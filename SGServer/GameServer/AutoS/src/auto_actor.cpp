#ifdef WIN32
#include <winsock2.h>
#include <windows.h>
#endif
#include <mysql.h>
#include "db.h"
#include "actor.h"
#include "auto_actor.h"
extern MYSQL *myGame;
int actor_load_auto( int actorid, Actor *pActor, const char *pTab )
{
	MYSQL_RES	*res;
	MYSQL_ROW	row;
	char	szSQL[8192] = {0};
	int offset = 0;
	if ( pActor == NULL )
		return -1;

	sprintf( szSQL, "select `actorid`,`admin`,`lastip`,`createtime`,`forbidtime`,`name`,`nation`,`shape`,`level`,`token`,`total_charge`,`charge_dollar`,`itemext`,`equipext`,`quest_complete`,`worldquest_complete`,`sflag`,`fdate`,`today_char`,`today_int0`,`today_int1`,`today_int2`,`today_int3`,`today_int4`,`today_int5`,`today_int6`,`today_int7`,`cd0`,`cd1`,`cd2`,`cd3`,`cd4`,`cd5`,`cd6`,`cd7`,`config`,`function`,`storyid`,`story_star`,`story_hero`,`story_restime`,`story_resnum`,`story_resreset`,`story_itemnum`,`story_drawing`,`lastpeople_c`,`lastpeople_n`,`cdkey1`,`cdkey2`,`cdkey3`,`cdkey4`,`hv_ln`,`hv_hn`,`hv_pro` from %s where actorid='%d'", pTab, actorid );
	if( mysql_query( myGame, szSQL ) )
	{
		printf( "Query failed (%s)\n", mysql_error(myGame) );
		write_gamelog( "%s", szSQL );
		if( mysql_ping(myGame) != 0 )
			db_reconnect_game();
		return -1;
	}
	res = mysql_store_result( myGame );

	if( ( row = mysql_fetch_row( res ) ) )
	{
		offset = 0;
		pActor->actorid = atoi(row[offset++]);
		pActor->admin = atoi(row[offset++]);
		memcpy( pActor->lastip, row[offset++], 16 ); pActor->lastip[15]=0;
		pActor->createtime = atoi(row[offset++]);
		pActor->forbidtime = atoi(row[offset++]);
		memcpy( pActor->name, row[offset++], 22 ); pActor->name[21]=0;
		pActor->nation = atoi(row[offset++]);
		pActor->shape = atoi(row[offset++]);
		pActor->level = atoi(row[offset++]);
		pActor->token = atoi(row[offset++]);
		pActor->total_charge = atoi(row[offset++]);
		pActor->charge_dollar = (float)atof(row[offset++]);
		pActor->itemext = atoi(row[offset++]);
		pActor->equipext = atoi(row[offset++]);
		memcpy( pActor->quest_complete, row[offset++], sizeof(char)*2048 );
		pActor->worldquest_complete = atoi(row[offset++]);
		pActor->sflag = atoi(row[offset++]);
		pActor->fdate = atoi(row[offset++]);
		memcpy( pActor->today_char, row[offset++], sizeof(char)*128 );
		pActor->today_int[0] = atoi(row[offset++]);
		pActor->today_int[1] = atoi(row[offset++]);
		pActor->today_int[2] = atoi(row[offset++]);
		pActor->today_int[3] = atoi(row[offset++]);
		pActor->today_int[4] = atoi(row[offset++]);
		pActor->today_int[5] = atoi(row[offset++]);
		pActor->today_int[6] = atoi(row[offset++]);
		pActor->today_int[7] = atoi(row[offset++]);
		pActor->cd[0] = atoi(row[offset++]);
		pActor->cd[1] = atoi(row[offset++]);
		pActor->cd[2] = atoi(row[offset++]);
		pActor->cd[3] = atoi(row[offset++]);
		pActor->cd[4] = atoi(row[offset++]);
		pActor->cd[5] = atoi(row[offset++]);
		pActor->cd[6] = atoi(row[offset++]);
		pActor->cd[7] = atoi(row[offset++]);
		memcpy( pActor->config, row[offset++], sizeof(char)*8 );
		pActor->function = atoi(row[offset++]);
		pActor->storyid = atoi(row[offset++]);
		memcpy( pActor->story_star, row[offset++], sizeof(char)*128 );
		memcpy( pActor->story_hero, row[offset++], sizeof(short)*32 );
		memcpy( pActor->story_restime, row[offset++], sizeof(int)*32 );
		memcpy( pActor->story_resnum, row[offset++], sizeof(char)*32 );
		memcpy( pActor->story_resreset, row[offset++], sizeof(char)*32 );
		memcpy( pActor->story_itemnum, row[offset++], sizeof(char)*64 );
		memcpy( pActor->story_drawing, row[offset++], sizeof(char)*16 );
		pActor->lastpeople_c = atoi(row[offset++]);
		pActor->lastpeople_n = atoi(row[offset++]);
		pActor->cdkey1 = atoi(row[offset++]);
		pActor->cdkey2 = atoi(row[offset++]);
		pActor->cdkey3 = atoi(row[offset++]);
		pActor->cdkey4 = atoi(row[offset++]);
		pActor->hv_ln = atoi(row[offset++]);
		pActor->hv_hn = atoi(row[offset++]);
		pActor->hv_pro = atoi(row[offset++]);
	}
	else
	{
		mysql_free_result( res );
		return -1;
	}
	mysql_free_result( res );
	return 0;
}
int actor_save_auto( Actor *pActor, const char *pTab, FILE *fp )
{
	char	szSQL[8192] = {0};
	char reconnect_flag = 0;
	if ( pActor == NULL )
		return -1;

	char szText_lastip[MAX_PATH]={0};
	char szText_name[MAX_PATH]={0};
	char szText_quest_complete[sizeof(char)*2048*2+1]={0};
	char szText_today_char[sizeof(char)*128*2+1]={0};
	char szText_config[sizeof(char)*8*2+1]={0};
	char szText_story_star[sizeof(char)*128*2+1]={0};
	char szText_story_hero[sizeof(short)*32*2+1]={0};
	char szText_story_restime[sizeof(int)*32*2+1]={0};
	char szText_story_resnum[sizeof(char)*32*2+1]={0};
	char szText_story_resreset[sizeof(char)*32*2+1]={0};
	char szText_story_itemnum[sizeof(char)*64*2+1]={0};
	char szText_story_drawing[sizeof(char)*16*2+1]={0};
RE_ACTOR_UPDATE:
	sprintf( szSQL, "REPLACE INTO %s (`actorid`,`lastip`,`createtime`,`forbidtime`,`name`,`nation`,`shape`,`level`,`token`,`total_charge`,`charge_dollar`,`itemext`,`equipext`,`quest_complete`,`worldquest_complete`,`sflag`,`fdate`,`today_char`,`today_int0`,`today_int1`,`today_int2`,`today_int3`,`today_int4`,`today_int5`,`today_int6`,`today_int7`,`cd0`,`cd1`,`cd2`,`cd3`,`cd4`,`cd5`,`cd6`,`cd7`,`config`,`function`,`storyid`,`story_star`,`story_hero`,`story_restime`,`story_resnum`,`story_resreset`,`story_itemnum`,`story_drawing`,`lastpeople_c`,`lastpeople_n`,`cdkey1`,`cdkey2`,`cdkey3`,`cdkey4`,`hv_ln`,`hv_hn`,`hv_pro`) Values('%d','%s','%d','%d','%s','%d','%d','%d','%d','%d','%f','%d','%d','%s','%d','%d','%d','%s','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%d','%s','%d','%d','%s','%s','%s','%s','%s','%s','%s','%d','%d','%d','%d','%d','%d','%d','%d','%d')",pTab,pActor->actorid,db_escape((const char *)pActor->lastip,szText_lastip,0),pActor->createtime,pActor->forbidtime,db_escape((const char *)pActor->name,szText_name,0),pActor->nation,pActor->shape,pActor->level,pActor->token,pActor->total_charge,pActor->charge_dollar,pActor->itemext,pActor->equipext,db_escape((const char *)pActor->quest_complete,szText_quest_complete,sizeof(char)*2048),pActor->worldquest_complete,pActor->sflag,pActor->fdate,db_escape((const char *)pActor->today_char,szText_today_char,sizeof(char)*128),pActor->today_int[0],pActor->today_int[1],pActor->today_int[2],pActor->today_int[3],pActor->today_int[4],pActor->today_int[5],pActor->today_int[6],pActor->today_int[7],pActor->cd[0],pActor->cd[1],pActor->cd[2],pActor->cd[3],pActor->cd[4],pActor->cd[5],pActor->cd[6],pActor->cd[7],db_escape((const char *)pActor->config,szText_config,sizeof(char)*8),pActor->function,pActor->storyid,db_escape((const char *)pActor->story_star,szText_story_star,sizeof(char)*128),db_escape((const char *)pActor->story_hero,szText_story_hero,sizeof(short)*32),db_escape((const char *)pActor->story_restime,szText_story_restime,sizeof(int)*32),db_escape((const char *)pActor->story_resnum,szText_story_resnum,sizeof(char)*32),db_escape((const char *)pActor->story_resreset,szText_story_resreset,sizeof(char)*32),db_escape((const char *)pActor->story_itemnum,szText_story_itemnum,sizeof(char)*64),db_escape((const char *)pActor->story_drawing,szText_story_drawing,sizeof(char)*16),pActor->lastpeople_c,pActor->lastpeople_n,pActor->cdkey1,pActor->cdkey2,pActor->cdkey3,pActor->cdkey4,pActor->hv_ln,pActor->hv_hn,pActor->hv_pro);
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
			goto RE_ACTOR_UPDATE;
		}
		return -1;
	}
	return 0;
}

