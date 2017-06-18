#ifdef WIN32
#include <winsock2.h>
#include <windows.h>
#endif
#include <mysql.h>
#include "db.h"
#include "actor.h"
#include "auto_city_building.h"
extern MYSQL *myGame;
extern char g_batchsql[BATCHSQL_MAXSIZE];

int city_building_load_auto( int cityid, int city_index, LPCB_GETBUILDING pCB_GetBuilding, char *pTab )
{
	MYSQL_RES	*res;
	MYSQL_ROW	row;
	char	szSQL[8192] = {0};
	int offset = 0;
	Building *pBuilding;

	sprintf( szSQL, "select `cityid`,`offset`,`kind`,`level`,`finish`,`official`,`value` from %s where cityid='%d'", pTab, cityid );
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
		pBuilding = pCB_GetBuilding( city_index, atoi(row[1]) );
		if( pBuilding == NULL )
			continue;
		offset++;
		offset++;
		pBuilding->kind = atoi(row[offset++]);
		pBuilding->level = atoi(row[offset++]);
		pBuilding->finish = atoi(row[offset++]);
		pBuilding->official = atoi(row[offset++]);
		pBuilding->value = atoi(row[offset++]);
	}
	mysql_free_result( res );
	return 0;
}
int city_building_save_auto( int cityid, int offset, Building *pBuilding, char *pTab, FILE *fp )
{
	char	szSQL[8192] = {0};
	char reconnect_flag = 0;
	if ( pBuilding == NULL )
		return -1;

RE_BUILDING_UPDATE:
	sprintf( szSQL, "REPLACE INTO %s (`cityid`,`offset`,`kind`,`level`,`finish`,`official`,`value`) Values('%d','%d','%d','%d','%d','%d','%d')",pTab,cityid,offset,pBuilding->kind,pBuilding->level,pBuilding->finish,pBuilding->official,pBuilding->value);
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
			goto RE_BUILDING_UPDATE;
		}
		return -1;
	}
	return 0;
}

int city_building_batch_save_auto( int cityid, Building *pBuilding, int maxcount, char *pTab, FILE *fp )
{
	char	szSQL[8192] = {0};
	if ( pBuilding == NULL )
		return -1;

	int count = 0;
	memset( g_batchsql, 0, sizeof(char)*BATCHSQL_MAXSIZE );
	for ( int index = 0; index < maxcount; index++ )
	{
		if ( pBuilding[index].kind <= 0 )
			continue;
		if ( count == 0 )
		{
			sprintf( g_batchsql, "REPLACE INTO %s (`cityid`,`offset`,`kind`,`level`,`finish`,`official`,`value`) Values('%d','%d','%d','%d','%d','%d','%d')",pTab,cityid,index,pBuilding[index].kind,pBuilding[index].level,pBuilding[index].finish,pBuilding[index].official,pBuilding[index].value);
		}
		else
		{
			sprintf( szSQL, ",('%d','%d','%d','%d','%d','%d','%d')",cityid,index,pBuilding[index].kind,pBuilding[index].level,pBuilding[index].finish,pBuilding[index].official,pBuilding[index].value);
			strcat( g_batchsql, szSQL );
		}
		count += 1;
		if ( count > 64 )
		{
			count = 0;
			db_query( fp, g_batchsql );
			memset( g_batchsql, 0, sizeof(char)*BATCHSQL_MAXSIZE );
		}
	}
	if ( count > 0 )
	{
		count = 0;
		db_query( fp, g_batchsql );
		memset( g_batchsql, 0, sizeof(char)*BATCHSQL_MAXSIZE );
	}
	return 0;
}