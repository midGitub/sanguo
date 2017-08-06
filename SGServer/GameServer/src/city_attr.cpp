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
#include "global.h"
#include "actor.h"
#include "actor_notify.h"
#include "server_netsend_auto.h"
#include "city.h"
#include "city_tech.h"
#include "city_attr.h"
#include "building.h"
#include "item.h"
#include "army.h"
#include "vip.h"
#include "hero.h"

extern Global global;
extern SConfig g_Config;
extern MYSQL *myGame;
extern MYSQL *myData;

extern BuildingUpgrade *g_BuildingUpgrade;
extern int g_BuildingUpgradeCount;

extern City *g_city;
extern int g_city_maxcount;

extern VipInfo *g_vipinfo;
extern int g_vipinfo_maxnum;

extern ItemKind *g_itemkind;
extern int g_itemkindnum;

extern TechInfo *g_techinfo;
extern int g_techinfo_maxnum;

void city_attr_reset( City *pCity )
{
	if ( !pCity )
		return;

	// 先重置
	memset( &pCity->attr, 0, sizeof( CityAttr ) );

	// 科技影响
	for ( int kind = 1; kind < CITY_TECH_MAX; kind++ )
	{
		char tech_level = pCity->techlevel[kind];
		if ( tech_level > 0 && tech_level < g_techinfo[kind].maxnum )
		{
			city_attr_calc( &pCity->attr, g_techinfo[kind].config[tech_level].ability, g_techinfo[kind].config[tech_level].value, 100.0f );
		}
	}

	//// buff影响
	//for ( int tmpi = 0; tmpi < CITY_BUFF_MAX; tmpi++ )
	//{
	//	short buff_id = pCity->buff_id[tmpi];
	//	int duration = pCity->buff_duration[tmpi];
	//	if ( duration <= 0 )
	//		continue;
	//	if ( buff_id > 0 && buff_id < g_citybuff_maxcount )
	//	{
	//		city_attr_calc( &pCity->attr, g_citybuff[buff_id].ability, g_citybuff[buff_id].value, 100.0f );
	//	}
	//}

	// VIP影响
	if ( pCity->viplevel > 0 && pCity->viplevel < g_vipinfo_maxnum )
	{
		for ( char tmpi = 0; tmpi < VIP_ABILITY_MAXNUM; tmpi++ )
		{
			if ( g_vipinfo[pCity->viplevel].ability[tmpi] <= 0 )
				continue;
			city_attr_calc( &pCity->attr, g_vipinfo[pCity->viplevel].ability[tmpi], g_vipinfo[pCity->viplevel].value[tmpi], 100.0f );
		}
	}
	//city_attr_sendlist( pCity->actor_index, pCity );
}

void city_attr_calc( CityAttr *pAttr, short ability, int value, float digit )
{
	if ( !pAttr )
		return;
	switch ( ability )
	{
	case CITY_ATTR_ABILITY_1:// 提升银币每小时产量%
		pAttr->silver_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_2:// 提升木材每小时产量%
		pAttr->wood_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_3:// 提升粮食每小时产量%
		pAttr->food_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_4:// 提升镔铁每小时产量%
		pAttr->iron_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_5:// 提升步兵每分钟招募数量%
		pAttr->train_per[0] += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_6:// 提升骑兵每分钟招募数量%
		pAttr->train_per[1] += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_7:// 提升弓兵每分钟招募数量%
		pAttr->train_per[2] += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_8:// 提升武将行军速度%
		pAttr->movespeed_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_9:// 提升仓库保护资源量%
		pAttr->protectres_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_10:// 缩短建筑升级所需时间%
		pAttr->buildingsec_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_11:// 缩短作坊生产耗时%
		pAttr->materialsec_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_12://单位时间采集收获加成%
		pAttr->gather_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_13:// 增加武将幸运突破概率%
		pAttr->heroluck_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_14:// 增加武将杀敌获得威望数量%
		pAttr->prestige_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_15:// 对城防军伤害%
		pAttr->damageguard_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_16:// 武官加速募兵
		pAttr->trainspeed_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_100:// 提高所以武将攻击力（固定数值）
		pAttr->hero_attack[0] += value;
		pAttr->hero_attack[1] += value;
		pAttr->hero_attack[2] += value;
		break;
	case CITY_ATTR_ABILITY_101:// 提高步兵武将攻击力（固定数值）
		pAttr->hero_attack[0] += value;
		break;
	case CITY_ATTR_ABILITY_102:// 提高骑兵武将攻击力（固定数值）
		pAttr->hero_attack[1] += value;
		break;
	case CITY_ATTR_ABILITY_103:// 提高弓兵武将攻击力（固定数值）
		pAttr->hero_attack[2] += value;
		break;
	case CITY_ATTR_ABILITY_110:// 提高所以武将防御力（固定数值）
		pAttr->hero_defense[0] += value;
		pAttr->hero_defense[1] += value;
		pAttr->hero_defense[2] += value;
		break;
	case CITY_ATTR_ABILITY_111:// 提高步兵武将防御力（固定数值）
		pAttr->hero_defense[0] += value;
		break;
	case CITY_ATTR_ABILITY_112:// 提高骑兵武将防御力（固定数值）
		pAttr->hero_defense[1] += value;
		break;
	case CITY_ATTR_ABILITY_113:// 提高弓兵武将防御力（固定数值）
		pAttr->hero_defense[2] += value;
		break;
	case CITY_ATTR_ABILITY_120:// 提高所以武将兵力（固定数值）
		pAttr->hero_troops[0] += value;
		pAttr->hero_troops[1] += value;
		pAttr->hero_troops[2] += value;
		break;
	case CITY_ATTR_ABILITY_121:// 提高步兵武将兵力（固定数值）
		pAttr->hero_troops[0] += value;
		break;
	case CITY_ATTR_ABILITY_122:// 提高骑兵武将兵力（固定数值）
		pAttr->hero_troops[1] += value;
		break;
	case CITY_ATTR_ABILITY_123:// 提高弓兵武将兵力（固定数值）
		pAttr->hero_troops[2] += value;
		break;
	case CITY_ATTR_ABILITY_130:// 增加上阵武将数量（固定数值）
		pAttr->hero_up_num += value;
		break;
	case CITY_ATTR_ABILITY_131:// 增加武将带兵排数（固定数值）
		pAttr->hero_row_num += value;
		break;
	case CITY_ATTR_ABILITY_132:// 国器暴击：开启国N倍暴击（固定数值）
		pAttr->nequip_crit += value;
		break;
	case CITY_ATTR_ABILITY_133:// 侦查：可侦查敌国玩家城池信息（固定数值）
		pAttr->spy_city += value;
		break;
	case CITY_ATTR_ABILITY_134:// 立即建造加速秒（固定数值）
		pAttr->free_sec += value;
		break;
	case CITY_ATTR_ABILITY_135:// 体力购买次数上限（固定数值）
		pAttr->everyday_body_buymax += value;
		break;
	case CITY_ATTR_ABILITY_136:// 自动建造免费购买次数（固定数值）
		pAttr->everyday_autobuild_buynum += value;
		break;
	case CITY_ATTR_ABILITY_137:// 每日免费行军召回（固定数值）
		pAttr->everyday_army_recall += value;
		break;
	case CITY_ATTR_ABILITY_201:// 秘技：金色以上装备技能满级且相同，可开启秘技（开启功能）
		pAttr->ability_open_201 = 1;
		break;
	case CITY_ATTR_ABILITY_202:// 极品装备：打造装备有概率直接获得秘技装备（开启功能）
		pAttr->ability_open_202 = 1;
		break;
	case CITY_ATTR_ABILITY_203:// 改土辟地：可拆除建筑并选择指定类型建筑进行重建（开启功能）
		pAttr->ability_open_203 = 1;
		break;
	case CITY_ATTR_ABILITY_204:// 自动补兵：开启自动补兵（开启功能）
		pAttr->ability_open_204 = 1;
		break;
	case CITY_ATTR_ABILITY_205:// 扫荡副本（开启功能）
		pAttr->ability_open_205 = 1;
		break;
	case CITY_ATTR_ABILITY_206:// 跳过战斗（开启功能）
		pAttr->ability_open_206 = 1;
		break;
	case CITY_ATTR_ABILITY_207:// 开启皇宫内院（开启功能）
		pAttr->ability_open_207 = 1;
		break;
	}
}


// 重置总战力
void city_battlepower_reset( City *pCity )
{
	if ( !pCity )
		return;
	city_battlepower_hero_calc( pCity );
	city_battlepower_building_calc( pCity );
}

// 总战力计算
void city_battlepower_calc( City *pCity, char path )
{
	if ( !pCity )
		return;
	int old_battlepower = pCity->battlepower;
	pCity->battlepower = pCity->battlepower_hero + pCity->battlepower_building;

	// 有变化
	if ( old_battlepower != pCity->battlepower )
	{
		if ( pCity->actor_index >= 0 )
		{
			SLK_NetS_Battlepower pValue = { 0 };
			pValue.m_total = pCity->battlepower;
			pValue.m_path = path;
			netsend_battlepower_S( pCity->actor_index, SENDTYPE_ACTOR, &pValue );
		}
	}
}

// 英雄提供战力
void city_battlepower_hero_calc( City *pCity )
{
	if ( !pCity )
		return;
	int battlepower = 0;
	for ( int tmpi = 0; tmpi < 4; tmpi++ )
	{
		if ( pCity->hero[tmpi].kind <= 0 )
			continue;
		float attack = hero_attack( pCity, &pCity->hero[tmpi] ) * global.battlepower_attack;
		float defense = hero_defense( pCity, &pCity->hero[tmpi] ) * global.battlepower_defense;
		float troops = hero_troops( pCity, &pCity->hero[tmpi] ) * global.battlepower_troops;
		float attack_increase = hero_attack_increase( pCity, &pCity->hero[tmpi] ) * global.battlepower_attack_increase;
		float defense_increase = hero_defense_increase( pCity, &pCity->hero[tmpi] ) * global.battlepower_defense_increase;
		float assault = hero_assault( pCity, &pCity->hero[tmpi] ) * global.battlepower_assault;
		float defend = hero_defend( pCity, &pCity->hero[tmpi] ) * global.battlepower_defend;
		battlepower += (int)ceil( attack + defense + troops + attack_increase + defense_increase + assault + defend );
	}
	pCity->battlepower_hero = battlepower;
	city_battlepower_calc( pCity, BATTLEPOWER_PATH_HERO );
}

// 建筑提供战力
void city_battlepower_building_calc( struct _city *pCity )
{
	if ( !pCity )
		return;
	int battlepower = 0;
	// 普通建筑
	for ( int tmpi = 0; tmpi < BUILDING_MAXNUM; tmpi++ )
	{
		if ( pCity->building[tmpi].kind <= 0 )
			continue;
		BuildingUpgradeConfig *config = building_getconfig( pCity->building[tmpi].kind, pCity->building[tmpi].level );
		if ( config )
		{
			battlepower += config->battlepower;
		}
	}

	// 兵营建筑
	for ( int tmpi = 0; tmpi < BUILDING_BARRACKS_MAXNUM; tmpi++ )
	{
		if ( pCity->building_barracks[tmpi].kind <= 0 || pCity->building_barracks[tmpi].level <= 0 )
			continue;
		BuildingUpgradeConfig *config = building_getconfig( pCity->building_barracks[tmpi].kind, pCity->building_barracks[tmpi].level );
		if ( config )
		{
			battlepower += config->battlepower;
		}
	}

	// 资源建筑
	for ( int tmpi = 0; tmpi < BUILDING_RES_MAXNUM; tmpi++ )
	{
		if ( pCity->building_res[tmpi].kind <= 0 || pCity->building_res[tmpi].level <= 0 )
			continue;
		BuildingUpgradeConfig *config = building_getconfig( pCity->building_res[tmpi].kind, pCity->building_res[tmpi].level );
		if ( config )
		{
			battlepower += config->battlepower;
		}
	}
	int old_battlepower = pCity->battlepower_building;
	pCity->battlepower_building = battlepower;
	city_battlepower_calc( pCity, BATTLEPOWER_PATH_BUILDING );
}
