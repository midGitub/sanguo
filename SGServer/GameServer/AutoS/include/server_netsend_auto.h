#ifndef __NETSEND_AUTO_H0
#define __NETSEND_AUTO_H0

#include "server_structsend_auto.h"
int netsend_login_S( int actor_index, char send_type, SLK_NetS_Login *pValue );
int netsend_list_S( int actor_index, char send_type, SLK_NetS_List *pValue );
int netsend_create_S( int actor_index, char send_type, SLK_NetS_Create *pValue );
int netsend_enterinfo_S( int actor_index, char send_type, SLK_NetS_EnterInfo *pValue );
int netsend_delete_S( int actor_index, char send_type, SLK_NetS_Delete *pValue );
int netsend_heart_S( int actor_index, char send_type, SLK_NetS_Heart *pValue );
int netsend_notify_S( int actor_index, char send_type, SLK_NetS_Notify *pValue );
int netsend_actorinfo_S( int actor_index, char send_type, SLK_NetS_ActorInfo *pValue );
int netsend_itemuse_S( int actor_index, char send_type, SLK_NetS_ItemUse *pValue );
int netsend_itemput_S( int actor_index, char send_type, SLK_NetS_ItemPut *pValue );
int netsend_itemsettle_S( int actor_index, char send_type, SLK_NetS_ItemSettle *pValue );
int netsend_lostitem_S( int actor_index, char send_type, SLK_NetS_LostItem *pValue );
int netsend_getitem_S( int actor_index, char send_type, SLK_NetS_GetItem *pValue );
int netsend_itemlist_S( int actor_index, char send_type, SLK_NetS_ItemList *pValue );
int netsend_iteminfo_S( int actor_index, char send_type, SLK_NetS_ItemInfo *pValue );
int netsend_addmapunit_S( char *databuf, int size, SLK_NetS_AddMapUnit *pValue );
int netsend_delmapunit_S( char *databuf, int size, SLK_NetS_DelMapUnit *pValue );
int netsend_updatemapunit_S( char *databuf, int size, SLK_NetS_UpdateMapUnit *pValue );
int netsend_mapunitsingle_S( int actor_index, char send_type, SLK_NetS_AddMapUnit *pValue );
int netsend_worldmapinfo_S( int actor_index, char send_type, SLK_NetS_WorldMapInfo *pValue );
int netsend_mapunitcorrdinate_S( char *databuf, int size, SLK_NetS_MapUnitCorrdinate *pValue );
int netsend_addmarchroute_S( char *databuf, int size, SLK_NetS_AddMarchRoute *pValue );
int netsend_delmarchroute_S( char *databuf, int size, SLK_NetS_DelMarchRoute *pValue );
int netsend_awardinfolist_S( int actor_index, char send_type, SLK_NetS_AwardInfoList *pValue );
int netsend_experience_S( int actor_index, char send_type, SLK_NetS_Experience *pValue );
int netsend_body_S( int actor_index, char send_type, SLK_NetS_Body *pValue );
int netsend_buildinglist_S( int actor_index, char send_type, SLK_NetS_BuildingList *pValue );
int netsend_changelevy_S( int actor_index, char send_type, SLK_NetS_Levy *pValue );
int netsend_changesilver_S( int actor_index, char send_type, SLK_NetS_Silver *pValue );
int netsend_changewood_S( int actor_index, char send_type, SLK_NetS_Wood *pValue );
int netsend_changefood_S( int actor_index, char send_type, SLK_NetS_Food *pValue );
int netsend_changeiron_S( int actor_index, char send_type, SLK_NetS_Iron *pValue );
int netsend_changepeople_S( int actor_index, char send_type, SLK_NetS_People *pValue );
int netsend_changeprestige_S( int actor_index, char send_type, SLK_NetS_Prestige *pValue );
int netsend_changefriendship_S( int actor_index, char send_type, SLK_NetS_Friendship *pValue );
int netsend_changevip_S( int actor_index, char send_type, SLK_NetS_Vip *pValue );
int netsend_changtoken_S( int actor_index, char send_type, SLK_NetS_Token *pValue );
int netsend_equip_S( int actor_index, char send_type, SLK_NetS_Equip *pValue );
int netsend_equiplist_S( int actor_index, char send_type, SLK_NetS_EquipList *pValue );
int netsend_equipget_S( int actor_index, char send_type, SLK_NetS_EquipGet *pValue );
int netsend_equiplost_S( int actor_index, char send_type, SLK_NetS_EquipLost *pValue );
int netsend_hero_S( int actor_index, char send_type, SLK_NetS_Hero *pValue );
int netsend_herolist_S( int actor_index, char send_type, SLK_NetS_HeroList *pValue );
int netsend_heroexp_S( int actor_index, char send_type, SLK_NetS_HeroExp *pValue );
int netsend_herosoldiers_S( int actor_index, char send_type, SLK_NetS_HeroSoldiers *pValue );
int netsend_herostate_S( int actor_index, char send_type, SLK_NetS_HeroState *pValue );
int netsend_heroreplace_S( int actor_index, char send_type, SLK_NetS_HeroReplace *pValue );
int netsend_buildingupgradeinfo_S( int actor_index, char send_type, SLK_NetS_BuildingUpgradeInfo *pValue );
int netsend_building_S( int actor_index, char send_type, SLK_NetS_Building *pValue );
int netsend_buildingbarracks_S( int actor_index, char send_type, SLK_NetS_BuildingBarracks *pValue );
int netsend_buildingres_S( int actor_index, char send_type, SLK_NetS_BuildingRes *pValue );
int netsend_worker_S( int actor_index, char send_type, SLK_NetS_Worker *pValue );
int netsend_heroget_S( int actor_index, char send_type, SLK_NetS_HeroGet *pValue );
int netsend_buildingget_S( int actor_index, char send_type, SLK_NetS_BuildingGet *pValue );
int netsend_buildingbarracksget_S( int actor_index, char send_type, SLK_NetS_BuildingBarracksGet *pValue );
int netsend_buildingresget_S( int actor_index, char send_type, SLK_NetS_BuildingResGet *pValue );
int netsend_soldiers_S( int actor_index, char send_type, SLK_NetS_Soldiers *pValue );
int netsend_traininfo_S( int actor_index, char send_type, SLK_NetS_TrainInfo *pValue );
int netsend_quest_S( int actor_index, char send_type, SLK_NetS_Quest *pValue );
int netsend_questlist_S( int actor_index, char send_type, SLK_NetS_QuestList *pValue );
int netsend_questaward_S( int actor_index, char send_type, SLK_NetS_QuestAward *pValue );
int netsend_function_S( int actor_index, char send_type, SLK_NetS_Function *pValue );
int netsend_cityguard_S( int actor_index, char send_type, SLK_NetS_CityGuard *pValue );
int netsend_cityguardlist_S( int actor_index, char send_type, SLK_NetS_CityGuardList *pValue );
int netsend_cityguardsec_S( int actor_index, char send_type, SLK_NetS_CityGuardSec *pValue );
int netsend_buildingsmithy_S( int actor_index, char send_type, SLK_NetS_BuildingSmithy *pValue );
int netsend_changename_S( int actor_index, char send_type, SLK_NetS_ChangeName *pValue );
int netsend_buildingaction_S( int actor_index, char send_type, SLK_NetS_BuildingAction *pValue );
int netsend_levyinfo_S( int actor_index, char send_type, SLK_NetS_LevyInfo *pValue );
int netsend_chat_S( int actor_index, char send_type, SLK_NetS_Chat *pValue );
int netsend_chatlist_S( int actor_index, char send_type, SLK_NetS_ChatList *pValue );
int netsend_systalkid_S( int actor_index, char send_type, SLK_NetS_Systalkid *pValue );
int netsend_systalk_S( int actor_index, char send_type, SLK_NetS_Systalk *pValue );
int netsend_battlepower_S( int actor_index, char send_type, SLK_NetS_Battlepower *pValue );
int netsend_techchange_S( int actor_index, char send_type, SLK_NetS_TechChange *pValue );
int netsend_cityeventlist_S( int actor_index, char send_type, SLK_NetS_EventList *pValue );
int netsend_officialhirechange_S( int actor_index, char send_type, SLK_NetS_OfficialHireChange *pValue );
int netsend_cityprotect_S( int actor_index, char send_type, SLK_NetS_CityProtect *pValue );

int netsend_userawarded_S( int actor_index, char send_type, SLK_NetU_UserAwarded *pValue );
int netsend_gmlocalcmd_S( int actor_index, char send_type, SLK_NetU_Gmlocalcmd *pValue );
int netsend_logined_S( int actor_index, char send_type, SLK_NetU_Logined *pValue );
int netsend_timer_S( int actor_index, char send_type, char *pValue );

#endif
