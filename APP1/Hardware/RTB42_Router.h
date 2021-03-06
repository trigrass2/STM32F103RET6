#ifndef _RTB42_ROUTER_H
#define _RTB42_ROUTER_H
#include "stm32f10x.h"
#include "includes.h"
#include "Initialize.h"
#include "struct.h"
#include "const.h"
////////////////////////////////////////////////////////////////////////////////////////////////
//SSC1642电力载波通信芯片通信协议
////////////////////////////////////////////////////////////////////////////////////////////////
//初始化RTB42
void Init_RTB42(void);

//发送PLC报文   周期调用   所有报文缓存到FIFO中，每个6秒周期调用
void Send_RTB42_Bdp(void);

//把发送报文打到环形缓存区去  返回是否添加成功
unsigned char Add_bpd_to_PLC_RingBuf(unsigned char send_counter, unsigned char * pbuf, unsigned char len);

////////////////////////////////////////////////////////////////////////////////////
#endif
