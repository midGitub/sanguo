#ifndef _GIRL_H_
#define _GIRL_H_
#include "define.h"
#define ACTOR_GIRL_MAX	80

#define GIRL_SFLAG_MARRY	0	// �Ƿ���
#define GIRL_SFLAG_MAKELOVE	1	// �����Ƿ����ܻ�����

// ��offsetת���ɶ�Ӧ�����Խṹ
Girl *girl_getptr( int city_index, int kind );
GirlInfoConfig *girl_getconfig( int kind, int color );
void girl_makestruct( City *pCity, Girl *pGirl, SLK_NetS_Girl *pValue );
int girl_getgirl( City *pCity, int kind, char path ); // ��һ��Ů��
int girl_getsoul( City *pCity, int kind, int soul, char path ); // ��һ��Ů����Ƭ
int girl_info( City *pCity, Girl *pGirl ); // Ů����Ϣ
int girl_list( int actor_index ); // Ů���б�
void girl_update(); //  ÿ���������
int girl_allot( int actor_index, short herokind, short girlkind ); // ί���н�
int girl_unallot( int actor_index, short kind ); // ���ί��
int girl_colorup( int actor_index, short kind ); // ͻ��
int girl_loveitemuse( int actor_index, short kind, short itemkind );// ���ܶȵ���ʹ��
int girl_marry( int actor_index, short kind ); // ϲ������
int girl_makelove( int actor_index, short kind ); // ���ܻ���
int girl_addloveexp( City *pCity, short kind, int exp, short path ); // �������Ƕ�
void girl_gm_getall( City *pCity );
#endif