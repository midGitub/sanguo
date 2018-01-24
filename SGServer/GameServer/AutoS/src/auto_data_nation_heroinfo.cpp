extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}
#ifdef WIN32
#include <winsock2.h>
#include <windows.h>
#endif
#include <mysql.h>
#include "db.h"
#include "auto_data_nation_heroinfo.h"
extern MYSQL *myData;
extern lua_State* servL;
NationHeroInfo *g_nation_heroinfo = NULL;
int g_nation_heroinfo_maxnum = 0;

int nationheroinfo_init_auto()
{
	MYSQL_RES	*res;
	MYSQL_ROW	row;
	char	szSQL[2048] = {0};
	int offset = 0;

	sprintf( szSQL, "select max(`herokind`) from nation_heroinfo;" );
	if( mysql_query( myData, szSQL ) )
	{
		printf( "Query failed (%s)\n", mysql_error(myData) );
		write_gamelog( "%s", szSQL );
		return -1;
	}
	res = mysql_store_result( myData );
	if( ( row = mysql_fetch_row( res ) ) )
	{
		if ( row[0] )
			g_nation_heroinfo_maxnum = atoi( row[0] ) + 1;
		else
			g_nation_heroinfo_maxnum = 0;
	}
	else
	{
		mysql_free_result( res );
		return -1;
	}
	mysql_free_result( res );

	g_nation_heroinfo = (NationHeroInfo *)malloc( sizeof(NationHeroInfo)*g_nation_heroinfo_maxnum );
	memset( g_nation_heroinfo, 0, sizeof(NationHeroInfo)*g_nation_heroinfo_maxnum );

	sprintf( szSQL, "select `herokind`,`nation`,`nationlevel`,`visit_token`,`other_visit_token`,`catch_odds`,`catch_visit_odds`,`run_loyal00`,`run_loyal01`,`run_loyal02`,`run_loyal03`,`run_loyal04`,`run_loyal05`,`run_loyal06`,`run_loyal07`,`run_loyal08`,`run_loyal09`,`run_odds00`,`run_odds01`,`run_odds02`,`run_odds03`,`run_odds04`,`run_odds05`,`run_odds06`,`run_odds07`,`run_odds08`,`run_odds09`,`awardgroup`,`monsterid0`,`monsterid1`,`monsterid2`,`monsterid3` from nation_heroinfo;" );
	if( mysql_query( myData, szSQL ) )
	{
		printf( "Query failed (%s)\n", mysql_error(myData) );
		write_gamelog( "%s", szSQL );
		return -1;
	}
	res = mysql_store_result( myData );
	while( ( row = mysql_fetch_row( res ) ) )
	{
		offset = 0;
		int herokind = atoi( row[0] );
		if ( herokind < 0 || herokind >= g_nation_heroinfo_maxnum  )
			continue;
		g_nation_heroinfo[herokind].herokind = atoi(row[offset++]);
		g_nation_heroinfo[herokind].nation = atoi(row[offset++]);
		g_nation_heroinfo[herokind].nationlevel = atoi(row[offset++]);
		g_nation_heroinfo[herokind].visit_token = atoi(row[offset++]);
		g_nation_heroinfo[herokind].other_visit_token = atoi(row[offset++]);
		g_nation_heroinfo[herokind].catch_odds = atoi(row[offset++]);
		g_nation_heroinfo[herokind].catch_visit_odds = atoi(row[offset++]);
		g_nation_heroinfo[herokind].run_loyal[0] = atoi(row[offset++]);
		g_nation_heroinfo[herokind].run_loyal[1] = atoi(row[offset++]);
		g_nation_heroinfo[herokind].run_loyal[2] = atoi(row[offset++]);
		g_nation_heroinfo[herokind].run_loyal[3] = atoi(row[offset++]);
		g_nation_heroinfo[herokind].run_loyal[4] = atoi(row[offset++]);
		g_nation_heroinfo[herokind].run_loyal[5] = atoi(row[offset++]);
		g_nation_heroinfo[herokind].run_loyal[6] = atoi(row[offset++]);
		g_nation_heroinfo[herokind].run_loyal[7] = atoi(row[offset++]);
		g_nation_heroinfo[herokind].run_loyal[8] = atoi(row[offset++]);
		g_nation_heroinfo[herokind].run_loyal[9] = atoi(row[offset++]);
		g_nation_heroinfo[herokind].run_odds[0] = atoi(row[offset++]);
		g_nation_heroinfo[herokind].run_odds[1] = atoi(row[offset++]);
		g_nation_heroinfo[herokind].run_odds[2] = atoi(row[offset++]);
		g_nation_heroinfo[herokind].run_odds[3] = atoi(row[offset++]);
		g_nation_heroinfo[herokind].run_odds[4] = atoi(row[offset++]);
		g_nation_heroinfo[herokind].run_odds[5] = atoi(row[offset++]);
		g_nation_heroinfo[herokind].run_odds[6] = atoi(row[offset++]);
		g_nation_heroinfo[herokind].run_odds[7] = atoi(row[offset++]);
		g_nation_heroinfo[herokind].run_odds[8] = atoi(row[offset++]);
		g_nation_heroinfo[herokind].run_odds[9] = atoi(row[offset++]);
		g_nation_heroinfo[herokind].awardgroup = atoi(row[offset++]);
		g_nation_heroinfo[herokind].monsterid[0] = atoi(row[offset++]);
		g_nation_heroinfo[herokind].monsterid[1] = atoi(row[offset++]);
		g_nation_heroinfo[herokind].monsterid[2] = atoi(row[offset++]);
		g_nation_heroinfo[herokind].monsterid[3] = atoi(row[offset++]);
	}
	mysql_free_result( res );
	return 0;
}

int nationheroinfo_reload_auto()
{
	if ( g_nation_heroinfo )
	{
		free( g_nation_heroinfo );
		g_nation_heroinfo = NULL;
	}
	g_nation_heroinfo_maxnum = 0;
	nationheroinfo_init_auto();
	return 0;
}

