#ifdef WIN32
#include <winsock2.h>
#include <windows.h>
#endif
#include <mysql.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "db.h"
#include "define.h"
#include "dserver.h"
#include "building.h"
#include "actor.h"
#include "hero.h"
#include "area.h"
#include "actor_send.h"
#include "actor_times.h"
#include "server_netsend_auto.h"
#include "mapunit.h"
#include "fight.h"
#include "actor_notify.h"
#include "item.h"
#include "award.h"
#include "global.h"
#include "quest.h"
#include "activity.h"
#include "system.h"
#include "army.h"
#include "army_march.h"
#include "army_fight.h"
#include "city.h"
#include "map_town.h"
#include "map_enemy.h"
#include "map_res.h"
#include "map.h"
#include "mail.h"

extern SConfig g_Config;
extern MYSQL *myGame;
extern MYSQL *myData;
extern Global global;

extern Actor *g_actors;
extern int g_maxactornum;

extern HeroInfo *g_HeroInfo;
extern short g_HeroCount;

extern City * g_city;
extern int g_city_maxcount;
extern int g_city_maxindex;

extern MapUnit *g_mapunit;
extern int g_mapunit_maxcount;

extern ItemKind *g_itemkind;
extern int g_itemkindnum;

extern MapZoneInfo *g_zoneinfo;
extern int g_zoneinfo_maxnum;

extern MapEnemyInfo *g_enemyinfo;
extern int g_enemyinfo_maxnum;

extern MapEnemy *g_map_enemy;
extern int g_map_enemy_maxcount;

extern MapRes *g_map_res;
extern int g_map_res_maxcount;

extern MapTownInfo *g_towninfo;
extern int g_towninfo_maxnum;

extern Map g_map;

extern Army *g_army;
extern int g_army_maxcount;
extern int g_army_count;
extern int g_army_maxindex;

// 与流寇战斗结果
int army_vs_enemy( int army_index, Fight *pFight )
{
	if ( army_index < 0 || army_index >= g_army_maxcount )
		return -1;
	MapEnemy *enemy = map_enemy_getptr( g_army[army_index].to_index );
	if ( !enemy )
		return -1;
	MapEnemyInfo *config = map_enemy_getconfig( enemy->kind );
	if ( !config )
		return -1;
	City *pCity = army_getcityptr( army_index );
	if ( !pCity )
		return -1;
	i64 mailid = 0;

	// 玩家胜利
	if ( pFight->result == FIGHT_WIN )
	{
		// 获得的奖励
		AwardGetInfo awardinfo = { 0 };

		// 首杀
		char first = 0;
		if ( pCity->mokilllv < config->level )
		{
			pCity->mokilllv = (char)config->level;
			first = 1;

			// 获取正常奖励
			awardgroup_withid( pCity->actorid, config->awardgroup, PATH_ENEMY, &awardinfo );

			// 获取首杀奖励
			awardgroup_withid( pCity->actorid, config->first_awardgroup, PATH_ENEMY, &awardinfo );

			// 通知客户端更新击杀等级
			int value[2] = { 0 };
			value[0] = 2;
			value[1] = pCity->mokilllv;
			actor_notify_value( pCity->actor_index, NOTIFY_WORLDMAP, 2, value, NULL );
		}
		else
		{
			// 获取正常奖励
			awardgroup_withid( pCity->actorid, config->awardgroup, PATH_ENEMY, &awardinfo );
		}

		// 发送胜利邮件
		char title[MAIL_TITLE_MAXSIZE] = { 0 };
		sprintf( title, "%s%d", TAG_TEXTID, 5002 );

		// 奖励展示不是附件的
		char attach[MAIL_ATTACH_MAXSIZE] = { 0 };
		if ( awardinfo.count > 0 )
		{
			for ( int tmpi = 0; tmpi < awardinfo.count; tmpi++ )
			{
				if ( awardinfo.kind[tmpi] <= 0 )
					continue;
				char tempitem[32] = { 0 };
				sprintf( tempitem, "%d,%d@", awardinfo.kind[tmpi], awardinfo.num[tmpi] );
				strcat( attach, tempitem );
			}
		}

		// 内容
		char content[MAIL_CONTENT_MAXSIZE] = { 0 };
		sprintf( content, "{\"text\":\"%s%d\",\"win\":1,\"name\":\"%s\",\"lv\":%d,\"pos\":\"%d,%d\",\"tpos\":\"%d,%d\",\"award\":\"%s\"}",
			TAG_TEXTID, 5502, pCity->name, config->level, pCity->posx, pCity->posy, enemy->posx, enemy->posy, attach );

		mailid = mail( pCity->actor_index, pCity->actorid, MAIL_TYPE_FIGHT_ENEMY, title, content, "", 0 );

		//// 任务数值
		//quest_addvalue( pCity, QUEST_DATAINDEX_KILLMONSTER, 0, 1 );
		//quest_addvalue( pCity, QUEST_DATAINDEX_KILLMONSTER_LEVEL, config->level, 1 );

		// 删除流寇
		map_enemy_delete( g_army[army_index].to_index );
	}
	else
	{
		// 被选择次数减少
		map_enemy_subselected( g_army[army_index].to_index );

		// 发送失败邮件
		char title[MAIL_TITLE_MAXSIZE] = { 0 };
		sprintf( title, "%s%d", TAG_TEXTID, 5003 );

		// 内容
		char content[MAIL_CONTENT_MAXSIZE] = { 0 };
		sprintf( content, "{\"text\":\"%s%d\",\"win\":0,\"name\":\"%s\",\"lv\":%d,\"pos\":\"%d,%d\",\"tpos\":\"%d,%d\"}",
			TAG_TEXTID, 5503, pCity->name, config->level, pCity->posx, pCity->posy, enemy->posx, enemy->posy );

		mailid = mail( pCity->actor_index, pCity->actorid, MAIL_TYPE_FIGHT_ENEMY, title, content, "", 0 );
	}

	// 插入战斗详情邮件
	if ( mailid > 0 )
	{
		mail_fight( mailid, pCity->actorid, pFight->unit_json );
	}
	return 0;
}

// 与采集资源的部队战斗结果
int army_vs_res( int army_index, Fight *pFight )
{
	//if ( army_index < 0 || army_index >= g_army_maxcount )
	//	return -1;
	//int gather_army_index = map_res_getarmy( g_army[army_index].target_index );
	//if ( gather_army_index < 0 || gather_army_index >= g_army_maxcount )
	//	return -1;

	//// 防御方战场部队还原到防御方army里
	//army_fightresult_toarmy( gather_army_index, 0 );
	//army_mail_fightarmy( army_index, army_getcityptr( army_index ), army_getcityptr( gather_army_index ), &g_fight );

	//// 联盟事件
	//club_setevent_vsres( army_index, gather_army_index, g_fight.result );

	//if ( g_fight.result == FIGHT_WIN )
	//{
	//	City *pCity = army_getcityptr( gather_army_index );
	//	if ( pCity )
	//	{
	//		Hero *pHero = hero_getptr( pCity, g_fight.defense_hero );
	//		if ( pHero )
	//			pHero->state = HERO_STATE_DIE;
	//	}
	//	// 这里同时删除它自己的被攻击信息，之后删除就找不到索引了
	//	city_underfire_del_equal( army_getcityptr( gather_army_index ), gather_army_index );
	//	club_war_del_equal( army_getclubindex( gather_army_index ), gather_army_index );

	//	// 直接换成胜利者采集了
	//	map_res_setarmy( g_army[army_index].target_index, army_index );
	//	army_setstate( army_index, ARMY_STATE_GATHER );
	//	g_army[army_index].action = ARMY_ACTION_GATHER;

	//	// 检测是否全军覆没
	//	if ( army_fightresult_checkalldead( gather_army_index ) < 0 )
	//	{
	//		army_delete( gather_army_index );
	//	}
	//	else
	//	{
	//		army_setstate( gather_army_index, ARMY_STATE_REBACK );
	//	}
	//}
	//else
	//{
	//	City *pCity = army_getcityptr( army_index );
	//	if ( pCity )
	//	{
	//		Hero *pHero = hero_getptr( pCity, g_fight.attack_hero );
	//		if ( pHero )
	//			pHero->state = HERO_STATE_DIE;
	//	}

	//	// 因为士兵会有变化，所以要重新计算资源携带量
	//	army_setstate( gather_army_index, ARMY_STATE_GATHER );
	//}
	return 0;
}

