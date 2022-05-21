//*****************************************************************************
// file     : SystemManageDef.h
// S32K144 linux-t operator
//
// Copyright (c) 2006-2020 HSAE co. Ltd. All rights reserved
//
// Change Logs:
// Date             Author        Note
// 2017/09/15       Linzhen       First draft version
//
//*****************************************************************************

#ifndef __SYSTEMMANAGEDEF__H
#define __SYSTEMMANAGEDEF__H

//*****************************************************************************
//
//! \addtogroup linux-t
//! @{
//
//*****************************************************************************

/*---------------------------------------------------------------------------*/
/* define macro                                                              */
/*---------------------------------------------------------------------------*/
#define System_TimeSlice_ObtainFailure  0
#define System_TimeSlice_ObtainSuccess  1

#define System_TimeSlice_1ms            1//25*4*10  =1000us=1ms

#define System_TimeSlice_2ms            2
#define System_TimeSlice_3ms            3
#define System_TimeSlice_4ms            4
#define System_TimeSlice_5ms            5
#define System_TimeSlice_6ms            6
#define System_TimeSlice_7ms            7
#define System_TimeSlice_8ms            8
#define System_TimeSlice_9ms            9

#define System_TimeSlice_10ms           10
#define System_TimeSlice_20ms           20
#define System_TimeSlice_50ms           50
#define System_TimeSlice_100ms          100
#define System_TimeSlice_200ms          200
#define System_TimeSlice_500ms          500


#define System_TimeSlice_1s             1000

#define System_TimeSlice_2s             2000
#define System_TimeSlice_5s             5000
#define System_TimeSlice_Max            0xffff


#define SystemState_Poweroff            0xff//机器复位

#define SystemState_Idle                0x00//上电重启
#define SystemState_Ready               0x01//系统准备打开，进行相关模块及变量的初始化
#define SystemState_WakeUp              0x02//系统从睡眠状态被唤醒
#define SystemState_Open                0x03//系统执行开机动作
#define SystemState_Normal              0x04//系统正常工作
#define SystemState_PowerOff            0x05//系统关掉
#define SystemState_StandBy             0x06//acc off+powerkey
#define SystemState_GoToSleep           0x07//系统准备进入睡眠状态
#define SystemState_Sleep               0x08
#define SystemState_DeepSleep           0x09
#define SystemState_Max                 0x0a//最大值
/*
#define System_TimeSlice_1ms            1//25*4*10  =1000us=1ms
#define System_TimeSlice_10ms           10
#define System_TimeSlice_20ms           20
#define System_TimeSlice_50ms           50
#define System_TimeSlice_100ms          100
#define System_TimeSlice_200ms          200
#define System_TimeSlice_500ms          500

#define System_TimeSlice_1s             1000

#define System_TimeSlice_2s             2000
#define System_TimeSlice_5s             5000


#define System_TimeSlice_30s            30000
#define System_TimeSlice_Max            0xffff
*/
/*---------------------------------------------------------------------------*/
/* define struct                                                             */
/*---------------------------------------------------------------------------*/
typedef struct
{
    unsigned char TimeCounter1ms;

    unsigned char TimeCounter2ms;
    unsigned char TimeCounter3ms;
    unsigned char TimeCounter4ms;
    unsigned char TimeCounter5ms;
    unsigned char TimeCounter6ms;
    unsigned char TimeCounter7ms;
    unsigned char TimeCounter8ms;
    unsigned char TimeCounter9ms;

    unsigned char TimeCounter10ms;
    unsigned char TimeCounter20ms;
    unsigned char TimeCounter50ms;
    unsigned char TimeCounter100ms;
    unsigned char TimeCounter200ms;
    unsigned int  TimeCounter500ms;
    unsigned int  TimeCounter1s;
    unsigned int  TimeCounter2s;
    unsigned int  TimeCounter5s;
} TimeCounter;

typedef struct
{
    unsigned char CurrentState;
    unsigned char NextState;//下次状态
    unsigned char LastState;
    unsigned char PowerState;//电源状态
    unsigned char WakeupEvent;//唤醒事件
    unsigned char Event;//唤醒事件
} Type_SystemState;

/*---------------------------------------------------------------------------*/
/* The struct used externally                                                */
/*---------------------------------------------------------------------------*/
extern TimeCounter      Counter;
extern Type_SystemState SystemState;

#endif

