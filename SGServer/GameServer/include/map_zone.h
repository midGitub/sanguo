#ifndef _MAP_ZONE_H_
#define _MAP_ZONE_H_
#include "define.h"
#define MAPZONE_CENTERID	13

int map_zone_load();
int map_zone_save( FILE *fp );
MapZone *map_zone_getptr( int zoneid );

// �����Ƿ���ָ��������
char map_zone_inrange( int zoneid, short posx, short posy );

// ��ȡ����id
char map_zone_getid( short posx, short posy );

// ����ʾ��Ԫ���ӵ�����
int map_zone_addunit( int unit_index, int zoneid );

// ����ʾ��Ԫ�Ƴ�������
int map_zone_delunit( int unit_index );

// ����ǲ�����ͬһ������
char map_zone_checksame( short posx, short posy, short tposx, short tposy );

// ���õ�������
int map_zone_setnation( int zoneid, char nation );

// ָ���������һ��������
int map_zone_randpos( short zoneid, short *pPosx, short *pPosy );

// ָ�������͹����������һ��������
int map_zone_nation_randpos( char nation, short *pPosx, short *pPosy );

// �����л�
void map_zone_change( int actor_index, short posx, short posy );

// ��������б�
int map_zone_citylist( int actor_index, int zoneid );

// ���������б�
int map_zone_townlist( int actor_index, int zoneid );

// �����ʳ����򶼳Ǻ����������б�
int map_zone_center_townlist( int actor_index );

// �����ʳ����򶼳Ǻ����Ǹ���
int map_zone_center_townchange( int townid );
#endif 