#ifdef WIN32
#include <winsock2.h>
#include <windows.h>
#endif
#include <mysql.h>
#include "db.h"
#include "actor.h"
#include "auto_city.h"
extern MYSQL *myGame;
int g_city_maxindex = 0;

int city_load_auto( LPCB_GETCITY pCB_GetCity, LPCB_LOADCITY pCB_LoadCity, const char *pTab )
{
	MYSQL_RES	*res;
	MYSQL_ROW	row;
	char	szSQL[8192] = {0};
	int offset = 0;
	City *pCity;
	int index = 0;

	sprintf( szSQL, "select `actorid`,`index`,`name`,`type`,`shape`,`headid`,`country`,`ipcountry`,`language`,`os`,`platid`,`createtime`,`lastlogin`,`lastlogout`,`state`,`posx`,`posy`,`sflag`,`level`,`exp`,`vipexp`,`nation`,`official`,`place`,`zone`,`battlepower`,`mokilllv`,`body`,`bodysec`,`silver`,`wood`,`food`,`iron`,`levynum`,`levysec`,`people`,`prestige`,`friendship`,`function`,`equip_washnum`,`equip_washsec`,`forgingkind`,`forgingsec`,`hero_washnum`,`hero_washsec`,`autobuild`,`autobuildopen`,`ptsec`,`peoplesec`,`eventsec`,`questid`,`questvalue`,`techlevel`,`techprogress`,`data_record`,`matkind`,`matnum`,`matsec`,`matquenum`,`matkind_will`,`matnum_will`,`matkind_over`,`matnum_over`,`nequip`,`nequip_kind`,`nequip_sec`,`guardsec`,`worker_op`,`worker_sec`,`worker_kind`,`worker_offset`,`worker_free`,`worker_op_ex`,`worker_sec_ex`,`worker_kind_ex`,`worker_offset_ex`,`worker_free_ex`,`worker_expire_ex`,`wnsec`,`wnsec_ex`,`wnquick`,`wnquick_ex`,`ofkind0`,`ofkind1`,`ofkind2`,`ofsec0`,`ofsec1`,`ofsec2`,`offree0`,`offree1`,`offree2`,`ofquick0`,`ofquick1`,`ofquick2` from %s ", pTab );
	if( mysql_query( myGame, szSQL ) )
	{
		printf( "Query failed (%s)\n", mysql_error(myGame) );
		write_gamelog( "%s", szSQL );
		if( mysql_ping(myGame) != 0 )
			db_reconnect_game();
		return -1;
	}
	res = mysql_store_result( myGame );

	while( ( row = mysql_fetch_row( res ) ) )
	{
		offset = 0;
		pCity = pCB_GetCity( atoi(row[1]) );
		if( pCity == NULL )
			continue;
		pCity->actorid = atoi(row[offset++]);
		pCity->index = atoi(row[offset++]);
		memcpy( pCity->name, row[offset++], 22 ); pCity->name[21]=0;
		pCity->type = atoi(row[offset++]);
		pCity->shape = atoi(row[offset++]);
		pCity->headid = atoi(row[offset++]);
		pCity->country = atoi(row[offset++]);
		memcpy( pCity->ipcountry, row[offset++], 3 ); pCity->ipcountry[2]=0;
		pCity->language = atoi(row[offset++]);
		pCity->os = atoi(row[offset++]);
		pCity->platid = atoi(row[offset++]);
		pCity->createtime = atoi(row[offset++]);
		pCity->lastlogin = atoi(row[offset++]);
		pCity->lastlogout = atoi(row[offset++]);
		pCity->state = atoi(row[offset++]);
		pCity->posx = atoi(row[offset++]);
		pCity->posy = atoi(row[offset++]);
		pCity->sflag = atoi(row[offset++]);
		pCity->level = atoi(row[offset++]);
		pCity->exp = atoi(row[offset++]);
		pCity->vipexp = atoi(row[offset++]);
		pCity->nation = atoi(row[offset++]);
		pCity->official = atoi(row[offset++]);
		pCity->place = atoi(row[offset++]);
		pCity->zone = atoi(row[offset++]);
		pCity->battlepower = atoi(row[offset++]);
		pCity->mokilllv = atoi(row[offset++]);
		pCity->body = atoi(row[offset++]);
		pCity->bodysec = atoi(row[offset++]);
		pCity->silver = atoi(row[offset++]);
		pCity->wood = atoi(row[offset++]);
		pCity->food = atoi(row[offset++]);
		pCity->iron = atoi(row[offset++]);
		pCity->levynum = atoi(row[offset++]);
		pCity->levysec = atoi(row[offset++]);
		pCity->people = atoi(row[offset++]);
		pCity->prestige = atoi(row[offset++]);
		pCity->friendship = atoi(row[offset++]);
		pCity->function = atoi(row[offset++]);
		pCity->equip_washnum = atoi(row[offset++]);
		pCity->equip_washsec = atoi(row[offset++]);
		pCity->forgingkind = atoi(row[offset++]);
		pCity->forgingsec = atoi(row[offset++]);
		pCity->hero_washnum = atoi(row[offset++]);
		pCity->hero_washsec = atoi(row[offset++]);
		pCity->autobuild = atoi(row[offset++]);
		pCity->autobuildopen = atoi(row[offset++]);
		pCity->ptsec = atoi(row[offset++]);
		pCity->peoplesec = atoi(row[offset++]);
		pCity->eventsec = atoi(row[offset++]);
		memcpy( pCity->questid, row[offset++], sizeof(short)*6 );
		memcpy( pCity->questvalue, row[offset++], sizeof(int)*6 );
		memcpy( pCity->techlevel, row[offset++], sizeof(char)*40 );
		memcpy( pCity->techprogress, row[offset++], sizeof(char)*40 );
		memcpy( pCity->data_record, row[offset++], sizeof(int)*16 );
		memcpy( pCity->matkind, row[offset++], sizeof(char)*8 );
		memcpy( pCity->matnum, row[offset++], sizeof(char)*8 );
		memcpy( pCity->matsec, row[offset++], sizeof(int)*8 );
		pCity->matquenum = atoi(row[offset++]);
		memcpy( pCity->matkind_will, row[offset++], sizeof(char)*8 );
		memcpy( pCity->matnum_will, row[offset++], sizeof(char)*8 );
		memcpy( pCity->matkind_over, row[offset++], sizeof(char)*8 );
		memcpy( pCity->matnum_over, row[offset++], sizeof(char)*8 );
		memcpy( pCity->nequip, row[offset++], sizeof(short)*6 );
		pCity->nequip_kind = atoi(row[offset++]);
		pCity->nequip_sec = atoi(row[offset++]);
		pCity->guardsec = atoi(row[offset++]);
		pCity->worker_op = atoi(row[offset++]);
		pCity->worker_sec = atoi(row[offset++]);
		pCity->worker_kind = atoi(row[offset++]);
		pCity->worker_offset = atoi(row[offset++]);
		pCity->worker_free = atoi(row[offset++]);
		pCity->worker_op_ex = atoi(row[offset++]);
		pCity->worker_sec_ex = atoi(row[offset++]);
		pCity->worker_kind_ex = atoi(row[offset++]);
		pCity->worker_offset_ex = atoi(row[offset++]);
		pCity->worker_free_ex = atoi(row[offset++]);
		pCity->worker_expire_ex = atoi(row[offset++]);
		pCity->wnsec = atoi(row[offset++]);
		pCity->wnsec_ex = atoi(row[offset++]);
		pCity->wnquick = atoi(row[offset++]);
		pCity->wnquick_ex = atoi(row[offset++]);
		pCity->ofkind[0] = atoi(row[offset++]);
		pCity->ofkind[1] = atoi(row[offset++]);
		pCity->ofkind[2] = atoi(row[offset++]);
		pCity->ofsec[0] = atoi(row[offset++]);
		pCity->ofsec[1] = atoi(row[offset++]);
		pCity->ofsec[2] = atoi(row[offset++]);
		pCity->offree[0] = atoi(row[offset++]);
		pCity->offree[1] = atoi(row[offset++]);
		pCity->offree[2] = atoi(row[offset++]);
		pCity->ofquick[0] = atoi(row[offset++]);
		pCity->ofquick[1] = atoi(row[offset++]);
		pCity->ofquick[2] = atoi(row[offset++]);
		if( pCB_LoadCity )
			pCB_LoadCity( pCity->index );
		index = pCity->index;
		if ( index >= g_city_maxindex )
		{
			g_city_maxindex = index + 1;
		}
	}
	mysql_free_result( res );
	return 0;
}
int city_save_auto( City *pCity, const char *pTab, FILE *fp )
{
	char	szSQL[8192] = {0};
	char reconnect_flag = 0;
	if ( pCity == NULL )
		return -1;

	char szText_name[MAX_PATH]={0};
	char szText_ipcountry[MAX_PATH]={0};
	char szText_questid[sizeof(short)*6*2+1]={0};
	char szText_questvalue[sizeof(int)*6*2+1]={0};
	char szText_techlevel[sizeof(char)*40*2+1]={0};
	char szText_techprogress[sizeof(char)*40*2+1]={0};
	char szText_data_record[sizeof(int)*16*2+1]={0};
	char szText_matkind[sizeof(char)*8*2+1]={0};
	char szText_matnum[sizeof(char)*8*2+1]={0};
	char szText_matsec[sizeof(int)*8*2+1]={0};
	char szText_matkind_will[sizeof(char)*8*2+1]={0};
	char szText_matnum_will[sizeof(char)*8*2+1]={0};
	char szText_matkind_over[sizeof(char)*8*2+1]={0};
	char szText_matnum_over[sizeof(char)*8*2+1]={0};
	char szText_nequip[sizeof(short)*6*2+1]={0};
RE_CITY_UPDATE:
	sprintf( szSQL, "REPLACE INTO %s (`actorid`,`index`,`name`,`type`,`shape`,`headid`,`country`,`ipcountry`,`language`,`os`,`platid`,`createtime`,`lastlogin`,`lastlogout`,`state`,`posx`,`posy`,`sflag`,`level`,`exp`,`vipexp`,`nation`,`official`,`place`,`zone`,`battlepower`,`mokilllv`,`body`,`bodysec`,`silver`,`wood`,`food`,`iron`,`levynum`,`levysec`,`people`,`prestige`,`friendship`,`function`,`equip_washnum`,`equip_washsec`,`forgingkind`,`forgingsec`,`hero_washnum`,`hero_washsec`,`autobuild`,`autobuildopen`,`ptsec`,`peoplesec`,`eventsec`,`questid`,`questvalue`,`techlevel`,`techprogress`,`data_record`,`matkind`,`matnum`,`matsec`,`matquenum`,`matkind_will`,`matnum_will`,`matkind_over`,`matnum_over`,`nequip`,`nequip_kind`,`nequip_sec`,`guardsec`,`worker_op`,`worker_sec`,`worker_kind`,`worker_offset`,`worker_free`,`worker_op_ex`,`worker_sec_ex`,`worker_kind_ex`,`worker_offset_ex`,`worker_free_ex`,`worker_expire_ex`,`wnsec`,`wnsec_ex`,`wnquick`,`wnquick_ex`,`ofkind0`,`ofkind1`,`ofkind2`,`ofsec0`,`ofsec1`,`ofsec2`,`offree0`,`offree1`,`offree2`,`ofquick0`,`ofquick1`,`ofquick2`) Values('%d','%d','%s','%d','%d','%d','%d','%s','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%s','%s','%s','%s','%s','%s','%s','%s','%d','%s','%s','%s','%s','%s','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d')",pTab,pCity->actorid,pCity->index,db_escape((const char *)pCity->name,szText_name,0),pCity->type,pCity->shape,pCity->headid,pCity->country,db_escape((const char *)pCity->ipcountry,szText_ipcountry,0),pCity->language,pCity->os,pCity->platid,pCity->createtime,pCity->lastlogin,pCity->lastlogout,pCity->state,pCity->posx,pCity->posy,pCity->sflag,pCity->level,pCity->exp,pCity->vipexp,pCity->nation,pCity->official,pCity->place,pCity->zone,pCity->battlepower,pCity->mokilllv,pCity->body,pCity->bodysec,pCity->silver,pCity->wood,pCity->food,pCity->iron,pCity->levynum,pCity->levysec,pCity->people,pCity->prestige,pCity->friendship,pCity->function,pCity->equip_washnum,pCity->equip_washsec,pCity->forgingkind,pCity->forgingsec,pCity->hero_washnum,pCity->hero_washsec,pCity->autobuild,pCity->autobuildopen,pCity->ptsec,pCity->peoplesec,pCity->eventsec,db_escape((const char *)pCity->questid,szText_questid,sizeof(short)*6),db_escape((const char *)pCity->questvalue,szText_questvalue,sizeof(int)*6),db_escape((const char *)pCity->techlevel,szText_techlevel,sizeof(char)*40),db_escape((const char *)pCity->techprogress,szText_techprogress,sizeof(char)*40),db_escape((const char *)pCity->data_record,szText_data_record,sizeof(int)*16),db_escape((const char *)pCity->matkind,szText_matkind,sizeof(char)*8),db_escape((const char *)pCity->matnum,szText_matnum,sizeof(char)*8),db_escape((const char *)pCity->matsec,szText_matsec,sizeof(int)*8),pCity->matquenum,db_escape((const char *)pCity->matkind_will,szText_matkind_will,sizeof(char)*8),db_escape((const char *)pCity->matnum_will,szText_matnum_will,sizeof(char)*8),db_escape((const char *)pCity->matkind_over,szText_matkind_over,sizeof(char)*8),db_escape((const char *)pCity->matnum_over,szText_matnum_over,sizeof(char)*8),db_escape((const char *)pCity->nequip,szText_nequip,sizeof(short)*6),pCity->nequip_kind,pCity->nequip_sec,pCity->guardsec,pCity->worker_op,pCity->worker_sec,pCity->worker_kind,pCity->worker_offset,pCity->worker_free,pCity->worker_op_ex,pCity->worker_sec_ex,pCity->worker_kind_ex,pCity->worker_offset_ex,pCity->worker_free_ex,pCity->worker_expire_ex,pCity->wnsec,pCity->wnsec_ex,pCity->wnquick,pCity->wnquick_ex,pCity->ofkind[0],pCity->ofkind[1],pCity->ofkind[2],pCity->ofsec[0],pCity->ofsec[1],pCity->ofsec[2],pCity->offree[0],pCity->offree[1],pCity->offree[2],pCity->ofquick[0],pCity->ofquick[1],pCity->ofquick[2]);
	if( fp )
	{
		fprintf( fp, "%s;\n", szSQL );
	}
	else if( mysql_query( myGame, szSQL ) )
	{
		printf( "Query failed (%s)\n", mysql_error(myGame) );
		write_gamelog( "%s", szSQL );
		if( reconnect_flag )
			return -1;
		if( mysql_ping(myGame) != 0 )
		{
			db_reconnect_game();
			reconnect_flag = 1;
			goto RE_CITY_UPDATE;
		}
		return -1;
	}
	return 0;
}

