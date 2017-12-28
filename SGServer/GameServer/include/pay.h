#ifndef __PAY_H_
#define __PAY_H_
#include "define.h"

#define PAY_GOODSTYPE_BASE					0		// 基础商店类型
#define PAY_GOODSTYPE_PUSH					1		// 推送类型
#define PAY_GOODSTYPE_DEFAULT				2		// 轮播图礼包
#define PAY_GOODSTYPE_ACTIVITY				3		// 活动类型

#define PAY_GOODSTYPE_MONTHCARD             101     // 月卡礼包
#define PAY_GOODSTYPE_WEEKCARD              102     // 周卡礼包

#define PAY_ACTIVITY_MAXCOUNT			10
#define PAY_INT_MONTH_DAY				30         // 一个月30天
#define PAY_INT_WEEK_DAY				7          // 一周7天

#define PAY_MONTH_AWARDGROUP				160         // 月卡奖励
#define PAY_WEEK_AWARDGROUP					159          // 周卡奖励

// 货币数字定义
// 注意：修改这里同时，源文件还有一个字符串定义，需一并修改
enum PayCoin
{
	USD = 0,//	美元
	CAD,	//	加元
	MXN,	//	墨西哥元
	AUD,	//	澳元
	NZD,	//	新西兰元
	JPY,	//	日元
	Euro,	//	欧元
	DKK,	//	丹麦克朗
	SEK,	//	瑞典克朗
	CHF,	//	瑞士法郎
	NOK,	//	挪威克朗
	GBP,	//	英镑
	CNY,	//	人民币元
	SGD,	//	新加坡元
	HKD,	//	港元
	TWD,	//	新台币
	RUB,	//	俄罗斯卢布
	TRY,	//	土耳其里拉
	INR,	//	印度卢比
	IDR,	//	印尼卢比
	ILS,	//	以色列新锡克尔
	ZAR,	//	南非兰特
	SAR,	//	沙特沙亚币
	AED,	//	阿联酋迪拉姆
	PAYCOINMAX,
};

// 多国支付价格
typedef struct _payprice
{
	int price[PAYCOINMAX];
}PayPrice;

// 支付国家配置
typedef struct _paycountry
{
	short	country_code;	// 国家数字代码
	char	country_str[3];	// 国家英文代码
	char	offset;			// 偏移值
}PayCountry;

int payprice_init();
int paycountry_init();
int paycountry_reload();

int paystore_list( int actor_index );
int paystore_activity_list( int actor_index );

// 通过type获取ID列表
int paystore_goodslist_withtype( int type, int *goodsid, int count );

// 购买商品
int paystore_buy( int actor_index, int goodsid );

// 添加订单
int paystore_addorder( int actor_index, int goodsid, char *pOrderID );

// 添加离线订单
int paystore_payoffline( int actor_index, int goodsid, char *pOrderID );
int paystore_payoffline_get( int actor_index );

// 购买月卡
void paystore_monthcard_buy( int actorid );

// 领取月卡
void paystore_monthcard_buy_get( int actor_index );

// 礼包信息
int pay_goodsinfo( int actor_index, int type, int goodsid );

// 限购添加次数
int actor_limitybuy_addnum( int actor_index, int index );
int actor_limitybuy_getnum( int actor_index, int index );
int actor_limitybuy_addnum_db( int actorid, int index );
int actor_limitybuy_getnum_db( int actorid, int index );

// 每日限购添加次数
int actor_everyday_limitybuy_addnum( int actor_index, int index );
int actor_everyday_limitybuy_getnum( int actor_index, int index );
int actor_everyday_limitybuy_addnum_db( int actorid, int index );
int actor_everyday_limitybuy_getnum_db( int actorid, int index );

// 获取这个商品在商店里的ID
int paystore_getid( int goodsid );

// 支付成功
int actor_pay( int actorid, int goodsid, char *pOrderID, char *money, char *currency );

// 推送礼包信息
int actor_pushbaginfo( int actor_index );

// 礼包操作
int city_paybag_add( struct _city *pCity, short goodsid, int cd, int limitcount, char path );
int city_paybag_sub( struct _city *pCity, short goodsid, short goodstype );
int city_paybag_del( struct _city *pCity, short goodsid );
int city_paybag_del_withtype( struct _city *pCity, int type );
char city_paybag_has( struct _city *pCity, short goodsid );

// 活动礼包开启
int activity_paybag_open( int activityid );
int activity_paybag_close( int activityid );
int activity_paybag_citynew( struct _city *pCity );

// 获取这个玩家所在国家应得的礼包
int paygoods_getawardgroup( int actor_index, short goodsid );

// 月卡或周卡每天的发放
int paycard_give();
#endif


