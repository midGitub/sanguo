#ifdef WIN32
#include <winsock2.h>
#include <windows.h>
#endif
#include <mysql.h>
#include "db.h"
#include "actor.h"
#include "auto_city_nation_hero.h"
extern MYSQL *myGame;
extern char g_batchsql[BATCHSQL_MAXSIZE];

int city_nation_hero_load_auto( int actorid, int city_index, LPCB_GETNATIONHERO pCB_GetNationHero, const char *pTab )
{
	MYSQL_RES	*res;
	MYSQL_ROW	row;
	char	szSQL[8192] = {0};
	int offset = 0;
	NationHero *pNationHero;

	sprintf( szSQL, "select `actorid`,`offset`,`herokind`,`state`,`forever`,`loyal` from %s where actorid='%d'", pTab, actorid );
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
		pNationHero = pCB_GetNationHero( city_index, atoi(row[1]) );
		if( pNationHero == NULL )
			continue;
		offset++;
		offset++;
		pNationHero->herokind = atoi(row[offset++]);
		pNationHero->state = atoi(row[offset++]);
		pNationHero->forever = atoi(row[offset++]);
		pNationHero->loyal = atoi(row[offset++]);
	}
	mysql_free_result( res );
	return 0;
}
int city_nation_hero_save_auto( int actorid, int offset, NationHero *pNationHero, const char *pTab, FILE *fp )
{
	char	szSQL[8192] = {0};
	char reconnect_flag = 0;
	if ( pNationHero == NULL )
		return -1;

RE_NATIONHERO_UPDATE:
	sprintf( szSQL, "REPLACE INTO %s (`actorid`,`offset`,`herokind`,`state`,`forever`,`loyal`) Values('%d','%d','%d','%d','%d','%d')",pTab,actorid,offset,pNationHero->herokind,pNationHero->state,pNationHero->forever,pNationHero->loyal);
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
			goto RE_NATIONHERO_UPDATE;
		}
		return -1;
	}
	return 0;
}

int city_nation_hero_batch_save_auto( int actorid, NationHero *pNationHero, int maxcount, const char *pTab, FILE *fp )
{
	char	szSQL[8192] = {0};
	if ( pNationHero == NULL )
		return -1;

	int count = 0;
	memset( g_batchsql, 0, sizeof(char)*BATCHSQL_MAXSIZE );
	for ( int index = 0; index < maxcount; index++ )
	{
		if ( pNationHero[index].herokind <= 0 )
			continue;
		if ( count == 0 )
		{
			sprintf( g_batchsql, "REPLACE INTO %s (`actorid`,`offset`,`herokind`,`state`,`forever`,`loyal`) Values('%d','%d','%d','%d','%d','%d')",pTab,actorid,index,pNationHero[index].herokind,pNationHero[index].state,pNationHero[index].forever,pNationHero[index].loyal);
		}
		else
		{
			sprintf( szSQL, ",('%d','%d','%d','%d','%d','%d')",actorid,index,pNationHero[index].herokind,pNationHero[index].state,pNationHero[index].forever,pNationHero[index].loyal);
			strcat( g_batchsql, szSQL );
		}
		count += 1;
		if ( count > 16 )
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
