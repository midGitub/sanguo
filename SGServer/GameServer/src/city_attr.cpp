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

extern Actor *g_actors;
extern int g_maxactornum;

void city_attr_reset( City *pCity )
{
	if ( !pCity )
		return;

	// ������
	memset( &pCity->attr, 0, sizeof( CityAttr ) );

	// �Ƽ�Ӱ��
	for ( int kind = 1; kind < CITY_TECH_MAX; kind++ )
	{
		char tech_level = pCity->techlevel[kind];
		if ( tech_level > 0 && tech_level < g_techinfo[kind].maxnum )
		{
			city_attr_calc( &pCity->attr, g_techinfo[kind].config[tech_level].ability, g_techinfo[kind].config[tech_level].value, 100.0f );
		}
	}

	//// buffӰ��
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

	// VIPӰ��
	if ( pCity->viplevel > 0 && pCity->viplevel < g_vipinfo_maxnum )
	{
		for ( char tmpi = 0; tmpi < VIP_ABILITY_MAXNUM; tmpi++ )
		{
			if ( g_vipinfo[pCity->viplevel].ability[tmpi] <= 0 )
				continue;
			city_attr_calc( &pCity->attr, g_vipinfo[pCity->viplevel].ability[tmpi], g_vipinfo[pCity->viplevel].value[tmpi], 100.0f );
		}
	}
	city_attr_sendinfo( pCity->actor_index );
}

void city_attr_calc( CityAttr *pAttr, short ability, int value, float digit )
{
	if ( !pAttr )
		return;
	switch ( ability )
	{
	case CITY_ATTR_ABILITY_1:// ��������ÿСʱ����%
		pAttr->silver_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_2:// ����ľ��ÿСʱ����%
		pAttr->wood_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_3:// ������ʳÿСʱ����%
		pAttr->food_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_4:// ��������ÿСʱ����%
		pAttr->iron_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_5:// ��������ÿ������ļ����%
		pAttr->train_per[0] += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_6:// �������ÿ������ļ����%
		pAttr->train_per[1] += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_7:// ��������ÿ������ļ����%
		pAttr->train_per[2] += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_8:// �����佫�о��ٶ�%
		pAttr->movespeed_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_9:// �����ֿⱣ����Դ��%
		pAttr->protectres_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_10:// ���̽�����������ʱ��%
		pAttr->buildingsec_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_11:// ��������������ʱ%
		pAttr->materialsec_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_12://��λʱ��ɼ��ջ�ӳ�%
		pAttr->gather_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_13:// �����佫����ͻ�Ƹ���%
		pAttr->heroluck_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_14:// �����佫ɱ�л����������%
		pAttr->prestige_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_15:// �ԳǷ����˺�%
		pAttr->damageguard_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_16:// ��ټ���ļ��
		pAttr->trainspeed_per += (float)(value / digit);
		break;
	case CITY_ATTR_ABILITY_100:// ��������佫���������̶���ֵ��
		pAttr->hero_attack[0] += value;
		pAttr->hero_attack[1] += value;
		pAttr->hero_attack[2] += value;
		break;
	case CITY_ATTR_ABILITY_101:// ��߲����佫���������̶���ֵ��
		pAttr->hero_attack[0] += value;
		break;
	case CITY_ATTR_ABILITY_102:// �������佫���������̶���ֵ��
		pAttr->hero_attack[1] += value;
		break;
	case CITY_ATTR_ABILITY_103:// ��߹����佫���������̶���ֵ��
		pAttr->hero_attack[2] += value;
		break;
	case CITY_ATTR_ABILITY_110:// ��������佫���������̶���ֵ��
		pAttr->hero_defense[0] += value;
		pAttr->hero_defense[1] += value;
		pAttr->hero_defense[2] += value;
		break;
	case CITY_ATTR_ABILITY_111:// ��߲����佫���������̶���ֵ��
		pAttr->hero_defense[0] += value;
		break;
	case CITY_ATTR_ABILITY_112:// �������佫���������̶���ֵ��
		pAttr->hero_defense[1] += value;
		break;
	case CITY_ATTR_ABILITY_113:// ��߹����佫���������̶���ֵ��
		pAttr->hero_defense[2] += value;
		break;
	case CITY_ATTR_ABILITY_120:// ��������佫�������̶���ֵ��
		pAttr->hero_troops[0] += value;
		pAttr->hero_troops[1] += value;
		pAttr->hero_troops[2] += value;
		break;
	case CITY_ATTR_ABILITY_121:// ��߲����佫�������̶���ֵ��
		pAttr->hero_troops[0] += value;
		break;
	case CITY_ATTR_ABILITY_122:// �������佫�������̶���ֵ��
		pAttr->hero_troops[1] += value;
		break;
	case CITY_ATTR_ABILITY_123:// ��߹����佫�������̶���ֵ��
		pAttr->hero_troops[2] += value;
		break;
	case CITY_ATTR_ABILITY_130:// ���������佫�������̶���ֵ��
		pAttr->hero_up_num += value;
		break;
	case CITY_ATTR_ABILITY_131:// �����佫�����������̶���ֵ��
		pAttr->hero_row_num += value;
		break;
	case CITY_ATTR_ABILITY_132:// ����������������N���������̶���ֵ��
		pAttr->nequip_crit += value;
		break;
	case CITY_ATTR_ABILITY_133:// ��飺�����й���ҳǳ���Ϣ���̶���ֵ��
		pAttr->spy_city += value;
		break;
	case CITY_ATTR_ABILITY_134:// ������������루�̶���ֵ��
		pAttr->free_sec += value;
		break;
	case CITY_ATTR_ABILITY_135:// ��������������ޣ��̶���ֵ��
		pAttr->everyday_body_buymax += value;
		break;
	case CITY_ATTR_ABILITY_136:// �Զ�������ѹ���������̶���ֵ��
		pAttr->everyday_autobuild_buynum += value;
		break;
	case CITY_ATTR_ABILITY_137:// ÿ������о��ٻأ��̶���ֵ��
		pAttr->everyday_army_recall += value;
		break;
	case CITY_ATTR_ABILITY_201:// �ؼ�����ɫ����װ��������������ͬ���ɿ����ؼ����������ܣ�
		pAttr->ability_open_201 = 1;
		break;
	case CITY_ATTR_ABILITY_202:// ��Ʒװ��������װ���и���ֱ�ӻ���ؼ�װ�����������ܣ�
		pAttr->ability_open_202 = 1;
		break;
	case CITY_ATTR_ABILITY_203:// �����ٵأ��ɲ��������ѡ��ָ�����ͽ��������ؽ����������ܣ�
		pAttr->ability_open_203 = 1;
		break;
	case CITY_ATTR_ABILITY_204:// �Զ������������Զ��������������ܣ�
		pAttr->ability_open_204 = 1;
		break;
	case CITY_ATTR_ABILITY_205:// ɨ���������������ܣ�
		pAttr->ability_open_205 = 1;
		break;
	case CITY_ATTR_ABILITY_206:// ����ս�����������ܣ�
		pAttr->ability_open_206 = 1;
		break;
	case CITY_ATTR_ABILITY_207:// �����ʹ���Ժ���������ܣ�
		pAttr->ability_open_207 = 1;
		break;
	}
}

void city_attr_sendinfo( int actor_index )
{
	if ( actor_index < 0 || actor_index >= g_maxactornum )
		return;
	City *pCity = city_getptr( actor_index );
	if ( !pCity )
		return;
	SLK_NetS_CityAttr pValue = { 0 };
	pValue.m_protectres_per = (int)(pCity->attr.protectres_per * 100);
	pValue.m_buildingsec_per = (int)(pCity->attr.buildingsec_per * 100);
	pValue.m_materialsec_per = (int)(pCity->attr.materialsec_per * 100);
	pValue.m_hero_up_num = pCity->attr.hero_up_num;
	pValue.m_hero_row_num = pCity->attr.hero_up_num;
	pValue.m_everyday_body_buymax = pCity->attr.everyday_body_buymax;
	pValue.m_everyday_autobuild_buynum = pCity->attr.everyday_autobuild_buynum;
	pValue.m_everyday_army_recall = pCity->attr.everyday_army_recall;
	pValue.m_ability_open_201 = pCity->attr.ability_open_201;
	pValue.m_ability_open_203 = pCity->attr.ability_open_203;
	pValue.m_ability_open_204 = pCity->attr.ability_open_204;
	pValue.m_ability_open_205 = pCity->attr.ability_open_205;
	pValue.m_ability_open_206 = pCity->attr.ability_open_206;
	pValue.m_ability_open_207 = pCity->attr.ability_open_207;
	netsend_cityattr_S( actor_index, SENDTYPE_ACTOR, &pValue );
}

// ������ս��
void city_battlepower_reset( City *pCity )
{
	if ( !pCity )
		return;
	city_battlepower_hero_calc( pCity );
	city_battlepower_building_calc( pCity );
}

// ��ս������
void city_battlepower_calc( City *pCity, char path )
{
	if ( !pCity )
		return;
	int old_battlepower = pCity->battlepower;
	pCity->battlepower = pCity->battlepower_hero + pCity->battlepower_building;

	// �б仯
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

// Ӣ���ṩս��
void city_battlepower_hero_calc( City *pCity )
{
	if ( !pCity )
		return;
	int battlepower = 0;
	for ( int tmpi = 0; tmpi < 4; tmpi++ )
	{
		if ( pCity->hero[tmpi].kind <= 0 )
			continue;
		float attack =  pCity->hero[tmpi].attack * global.battlepower_attack;
		float defense = pCity->hero[tmpi].defense * global.battlepower_defense;
		float troops = pCity->hero[tmpi].troops * global.battlepower_troops;
		float attack_increase = pCity->hero[tmpi].attack_increase * global.battlepower_attack_increase;
		float defense_increase = pCity->hero[tmpi].defense_increase * global.battlepower_defense_increase;
		float assault = pCity->hero[tmpi].assault * global.battlepower_assault;
		float defend = pCity->hero[tmpi].defend * global.battlepower_defend;
		battlepower += (int)ceil( attack + defense + troops + attack_increase + defense_increase + assault + defend );
	}
	pCity->battlepower_hero = battlepower;
	city_battlepower_calc( pCity, BATTLEPOWER_PATH_HERO );
}

// �����ṩս��
void city_battlepower_building_calc( struct _city *pCity )
{
	if ( !pCity )
		return;
	int battlepower = 0;
	// ��ͨ����
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

	// ��Ӫ����
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

	// ��Դ����
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