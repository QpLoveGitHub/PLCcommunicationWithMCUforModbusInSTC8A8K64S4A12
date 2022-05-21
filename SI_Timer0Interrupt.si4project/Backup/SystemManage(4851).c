//*****************************************************************************
// file     : SystemManage.c
//
// Copyright (c) 2011-2020  HUAWEI co. Ltd. All rights reserved
//
// Change Logs:
// Date             Author      Note
// 2017/11/15       Linzhen     First draft version
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup linux-t
//! @{
//
//*****************************************************************************

/*---------------------------------------------------------------------------*/
/* include files                                                             */
/*---------------------------------------------------------------------------*/
//#include "public_def.h"
#include "SystemManageDef.h"
//#include "SystemState_Idle.h"
//#include "SystemState_WakeUp.h"
//#include "SystemState_Ready.h"
//#include "SystemState_Normal.h"
//#include "SystemState_StandBy.h"
//#include "SystemState_GoToSleep.h"
//#include "SystemState_Sleep.h"
//#include "SystemState_DeepSleep.h"
//#include "SystemState_Open.h"
//#include "SystemManage.h"
//#include "sleep.h"
//
//#include "timer.h"
//#include "utils.h"
//#include "../McuLogManage/McuLogManage.h"

#include "SystemState_Idle.h"
#include "SystemState_Ready.h"
#include "SystemState_Normal.h"
#include "system.h"


#define Event_poweroff_to_idle      		0
#define Event_idle_to_wakeup      			1
#define Event_wakeup_to_ready     			2
#define Event_ready_to_open       			3
#define Event_open_to_normal  	  			4
#define Event_normal_to_standby	  			5
#define Event_standby_to_gotosleep 			6
#define Event_gotosleep_to_sleep  			7
#define Event_gotosleep_to_deepsleep  		8
#define Event_sleep_to_open		  			9
#define Event_deepsleep_to_wakeup 			10
/** add timestamp */
static volatile int g_timer_stamp = 0;

/*
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
*/

char const * g_sys_state_str[] = 
{
	"SystemState_Idle"
	,"SystemState_Ready"
	,"SystemState_WakeUp"
	,"SystemState_Open"
	,"SystemState_Normal"
	,"SystemState_PowerOff"
	,"SystemState_StandBy"
	,"SystemState_GoToSleep"
	,"SystemState_Sleep"
	,"SystemState_DeepSleep"
};

/*---------------------------------------------------------------------------*/
/* define APIs                                                               */
/*---------------------------------------------------------------------------*/
/**
  * \brief
  * TimeSlice_Count
  * \param NONE
  *
  * \return NONE
  */
void TimeSlice_Count(void)//Time Slice Counter
{
    if (Counter.TimeCounter1ms < 2) //in 500us
    {
        Counter.TimeCounter1ms++;
    }

    g_timer_stamp++;
    if (g_timer_stamp == 0x7FFFFFFF)
    {
        g_timer_stamp = 0;
    }
}

/**
  * \brief
  * SystemState_Get_Stamp
  * \param NONE
  *
  * \return NONE
  */
int SystemState_Get_Stamp(void)
{
    return g_timer_stamp;
}

/**
  * \brief
  * SystemState_Set_Stamp
  * \param stamp
  *
  * \return NONE
  */
void SystemState_Set_Stamp(int stamp)
{
    g_timer_stamp = stamp;
}

/**
  * \brief
  * SystemState_TimeSlice_Reset
  * \param TimeSlice_Item
  *
  * \return NONE
  */
void SystemState_TimeSlice_Reset(unsigned int TimeSlice_Item)
{
    switch (TimeSlice_Item)
    {
    case System_TimeSlice_1ms:
        Counter.TimeCounter1ms = 0;
        break;
////
    case System_TimeSlice_2ms:
        Counter.TimeCounter1ms = 0;
        break;
    case System_TimeSlice_3ms:
        Counter.TimeCounter1ms = 0;
        break;
    case System_TimeSlice_4ms:
        Counter.TimeCounter1ms = 0;
        break;
    case System_TimeSlice_5ms:
        Counter.TimeCounter1ms = 0;
        break;
    case System_TimeSlice_6ms:
        Counter.TimeCounter1ms = 0;
        break;
    case System_TimeSlice_7ms:
        Counter.TimeCounter1ms = 0;
        break;
    case System_TimeSlice_8ms:
        Counter.TimeCounter1ms = 0;
        break;
    case System_TimeSlice_9ms:
        Counter.TimeCounter1ms = 0;
        break;
////
    case System_TimeSlice_10ms:
        Counter.TimeCounter10ms = 0;
        break;
    case System_TimeSlice_20ms:
        Counter.TimeCounter20ms = 0;
        break;
    case System_TimeSlice_50ms:
        Counter.TimeCounter50ms = 0;
        break;
    case System_TimeSlice_100ms:
        Counter.TimeCounter100ms = 0;
        break;
    case System_TimeSlice_200ms:
        Counter.TimeCounter200ms = 0;
        break;
    case System_TimeSlice_500ms:
        Counter.TimeCounter500ms = 0;
        break;

    case System_TimeSlice_1s:
        Counter.TimeCounter1s = 0;
        break;

    case System_TimeSlice_2s:
        Counter.TimeCounter2s = 0;
        break;
    case System_TimeSlice_5s:
        Counter.TimeCounter5s = 0;
        break;
    default: //reset all
        Counter.TimeCounter1ms = 0; //testadd

        Counter.TimeCounter2ms = 0;
        Counter.TimeCounter3ms = 0;
        Counter.TimeCounter4ms = 0;
        Counter.TimeCounter5ms = 0;
        Counter.TimeCounter6ms = 0;
        Counter.TimeCounter7ms = 0;
        Counter.TimeCounter8ms = 0;
        Counter.TimeCounter9ms = 0;

        Counter.TimeCounter10ms = 0;
        Counter.TimeCounter20ms = 0;
        Counter.TimeCounter50ms = 0;
        Counter.TimeCounter100ms = 0;
        Counter.TimeCounter200ms = 0;
        Counter.TimeCounter500ms = 0;
        Counter.TimeCounter1s = 0;
        Counter.TimeCounter2s = 0;
        Counter.TimeCounter5s = 0;
        break;
    }
}

/**
  * \brief
  * SystemState_TimeSlice_Obtain
  * \param TimeSlice_Item
  *
  * \return unsigned char
  */
unsigned char SystemState_TimeSlice_Obtain(unsigned int TimeSlice_Item)
{
    unsigned char TimeSlice_Obtain_result = 0;
    switch (TimeSlice_Item)
    {
    case System_TimeSlice_1ms:
        if (Counter.TimeCounter1ms == 2)
        {

				//DISABLE_INT();
				//Counter.TimeCounter1ms = 0;
				//ENABLE_INT();

            SystemState_TimeSlice_Reset(System_TimeSlice_1ms);

            TimeSlice_Obtain_result = System_TimeSlice_ObtainSuccess;
////
            if (Counter.TimeCounter2ms < System_TimeSlice_2ms) //2ms
            {
                Counter.TimeCounter2ms++;
            }
            if (Counter.TimeCounter3ms < System_TimeSlice_3ms) //3ms
            {
                Counter.TimeCounter3ms++;
            }
            if (Counter.TimeCounter4ms < System_TimeSlice_4ms) //4ms
            {
                Counter.TimeCounter4ms++;
            }
            if (Counter.TimeCounter5ms < System_TimeSlice_5ms) //5ms
            {
                Counter.TimeCounter5ms++;
            }
            if (Counter.TimeCounter6ms < System_TimeSlice_6ms) //6ms
            {
                Counter.TimeCounter6ms++;
            }
            if (Counter.TimeCounter7ms < System_TimeSlice_7ms) //7ms
            {
                Counter.TimeCounter7ms++;
            }
            if (Counter.TimeCounter8ms < System_TimeSlice_8ms) //8ms
            {
                Counter.TimeCounter8ms++;
            }
            if (Counter.TimeCounter9ms < System_TimeSlice_9ms) //9ms
            {
                Counter.TimeCounter9ms++;
            }

////
            if (Counter.TimeCounter10ms < System_TimeSlice_10ms) //10ms
            {
                Counter.TimeCounter10ms++;
            }
            if (Counter.TimeCounter20ms < System_TimeSlice_20ms) //20ms
            {
                Counter.TimeCounter20ms++;
            }
            if (Counter.TimeCounter50ms < System_TimeSlice_50ms) //50ms
            {
                Counter.TimeCounter50ms++;
            }
            if (Counter.TimeCounter100ms < System_TimeSlice_100ms) //100ms
            {
                Counter.TimeCounter100ms++;
            }
            if (Counter.TimeCounter200ms < System_TimeSlice_200ms) //200ms
            {
                Counter.TimeCounter200ms++;
            }
            if (Counter.TimeCounter500ms < System_TimeSlice_500ms) //500ms
            {
                Counter.TimeCounter500ms++;
            }

            if (Counter.TimeCounter1s < System_TimeSlice_1s) //1s
            {
                Counter.TimeCounter1s++;
            }

            if (Counter.TimeCounter2s < System_TimeSlice_2s) //2s
            {
                Counter.TimeCounter2s++;
            }
            if (Counter.TimeCounter5s < System_TimeSlice_5s) //5s
            {
                Counter.TimeCounter5s++;
            }
        }
        break;
////
    case System_TimeSlice_2ms:
        if (Counter.TimeCounter2ms == System_TimeSlice_2ms)
        {
            SystemState_TimeSlice_Reset(System_TimeSlice_2ms);
            TimeSlice_Obtain_result = System_TimeSlice_ObtainSuccess;
        }
        break;
////
    case System_TimeSlice_3ms:
        if (Counter.TimeCounter3ms == System_TimeSlice_3ms)
        {
            SystemState_TimeSlice_Reset(System_TimeSlice_3ms);
            TimeSlice_Obtain_result = System_TimeSlice_ObtainSuccess;
        }
        break;
////
    case System_TimeSlice_4ms:
        if (Counter.TimeCounter4ms == System_TimeSlice_4ms)
        {
            SystemState_TimeSlice_Reset(System_TimeSlice_3ms);
            TimeSlice_Obtain_result = System_TimeSlice_ObtainSuccess;
        }
        break;
////
    case System_TimeSlice_5ms:
        if (Counter.TimeCounter5ms == System_TimeSlice_5ms)
        {
            SystemState_TimeSlice_Reset(System_TimeSlice_5ms);
            TimeSlice_Obtain_result = System_TimeSlice_ObtainSuccess;
        }
        break;
////
    case System_TimeSlice_6ms:
        if (Counter.TimeCounter6ms == System_TimeSlice_6ms)
        {
            SystemState_TimeSlice_Reset(System_TimeSlice_6ms);
            TimeSlice_Obtain_result = System_TimeSlice_ObtainSuccess;
        }
        break;
////
    case System_TimeSlice_7ms:
        if (Counter.TimeCounter7ms == System_TimeSlice_7ms)
        {
            SystemState_TimeSlice_Reset(System_TimeSlice_7ms);
            TimeSlice_Obtain_result = System_TimeSlice_ObtainSuccess;
        }
        break;
////
    case System_TimeSlice_8ms:
        if (Counter.TimeCounter8ms == System_TimeSlice_8ms)
        {
            SystemState_TimeSlice_Reset(System_TimeSlice_8ms);
            TimeSlice_Obtain_result = System_TimeSlice_ObtainSuccess;
        }
        break;
////
    case System_TimeSlice_9ms:
        if (Counter.TimeCounter9ms == System_TimeSlice_9ms)
        {
            SystemState_TimeSlice_Reset(System_TimeSlice_9ms);
            TimeSlice_Obtain_result = System_TimeSlice_ObtainSuccess;
        }
        break;
////




    case System_TimeSlice_10ms:
        if (Counter.TimeCounter10ms == System_TimeSlice_10ms)
        {
            SystemState_TimeSlice_Reset(System_TimeSlice_10ms);
            TimeSlice_Obtain_result = System_TimeSlice_ObtainSuccess;
        }
        break;
    case System_TimeSlice_20ms:
        if (Counter.TimeCounter20ms == System_TimeSlice_20ms)
        {
            SystemState_TimeSlice_Reset(System_TimeSlice_20ms);
            TimeSlice_Obtain_result = System_TimeSlice_ObtainSuccess;
        }
        break;
    case System_TimeSlice_50ms:
        if (Counter.TimeCounter50ms == System_TimeSlice_50ms)
        {
            SystemState_TimeSlice_Reset(System_TimeSlice_50ms);
            TimeSlice_Obtain_result = System_TimeSlice_ObtainSuccess;
        }
        break;
    case System_TimeSlice_100ms:
        if (Counter.TimeCounter100ms == System_TimeSlice_100ms)
        {
            SystemState_TimeSlice_Reset(System_TimeSlice_100ms);
            TimeSlice_Obtain_result = System_TimeSlice_ObtainSuccess;
        }
        break;
    case System_TimeSlice_200ms:
        if (Counter.TimeCounter200ms == System_TimeSlice_200ms)
        {
            SystemState_TimeSlice_Reset(System_TimeSlice_200ms);
            TimeSlice_Obtain_result = System_TimeSlice_ObtainSuccess;
        }
        break;
    case System_TimeSlice_500ms:
        if (Counter.TimeCounter500ms == System_TimeSlice_500ms)
        {
            SystemState_TimeSlice_Reset(System_TimeSlice_500ms);
            TimeSlice_Obtain_result = System_TimeSlice_ObtainSuccess;
        }
        break;


    case System_TimeSlice_1s:
        if (Counter.TimeCounter1s == System_TimeSlice_1s)
        {
            SystemState_TimeSlice_Reset(System_TimeSlice_1s);
            TimeSlice_Obtain_result = System_TimeSlice_ObtainSuccess;
        }
        break;


    case System_TimeSlice_2s:
        if (Counter.TimeCounter2s == System_TimeSlice_2s)
        {
            SystemState_TimeSlice_Reset(System_TimeSlice_2s);
            TimeSlice_Obtain_result = System_TimeSlice_ObtainSuccess;
        }
        break;
    case System_TimeSlice_5s:
        if (Counter.TimeCounter5s == System_TimeSlice_5s)
        {
            SystemState_TimeSlice_Reset(System_TimeSlice_5s);
            TimeSlice_Obtain_result = System_TimeSlice_ObtainSuccess;
        }
        break;
    default:
        break;
    }
    return (TimeSlice_Obtain_result);
}

/**
  * \brief
  * SystemState_CurrentState_Set
  * \param systemState
  *
  * \return NONE
  */
void SystemState_CurrentState_Set(unsigned char systemState)
{
    SystemState.CurrentState = systemState;
}

/**
  * \brief
  * SystemState_NextState_Set
  * \param systemState
  *
  * \return NONE
  */
void SystemState_NextState_Set(unsigned char systemState)
{
    SystemState.NextState = systemState;
}

/**
  * \brief
  * SystemState_Manage
  * \param None
  *
  * \return unsigned char
  */
unsigned char SystemState_Manage(void)
{
	switch(SystemState.CurrentState)
	{
		case SystemState_Idle:
		{
			System_Idle_Task();
			SystemState_TimeSlice_Reset(System_TimeSlice_Max);
			SystemState_CurrentState_Set(SystemState_Ready);
		}
		break;

		case SystemState_Ready:
		{
			SystemState_Ready_Task();
			SystemState_TimeSlice_Reset(System_TimeSlice_Max);
			SystemState_CurrentState_Set(SystemState_Normal);
		}

		break;

		case SystemState_Normal:
		{
			System_Normal_Task();
		}
		break;

		default:
		break;
	}
	return(SystemState.CurrentState);
}


