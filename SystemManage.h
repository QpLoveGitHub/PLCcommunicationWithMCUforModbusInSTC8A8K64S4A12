//*****************************************************************************
// file     : SystemManage.h
// S32K144 linux-t operator
//
// Copyright (c) 2006-2020 HSAE co. Ltd. All rights reserved
//
// Change Logs:
// Date             Author        Note
// 2017/09/15       Linzhen       First draft version
//
//*****************************************************************************

#ifndef __SYSTEMMANAGE__H
#define __SYSTEMMANAGE__H

//*****************************************************************************
//
//! \addtogroup linux-t
//! @{
//
//*****************************************************************************


/*---------------------------------------------------------------------------*/
/* The api used externally                                                   */
/*---------------------------------------------------------------------------*/
extern void TimeSlice_Count(void);
extern void SystemState_CurrentState_Set(unsigned char systemState);
extern void SystemState_NextState_Set(unsigned char systemState);
extern unsigned char SystemState_Manage(void);
extern unsigned char SystemState_TimeSlice_Obtain(unsigned int TimeSlice_Item);
extern unsigned char SystemState_TimeSlice_Obtain(unsigned int TimeSlice_Item);
extern void SystemState_TimeSlice_Reset(unsigned int TimeSlice_Item);
extern void TimeSlice_Count(void);
extern int SystemState_Get_Stamp(void);
extern void SystemState_Set_Stamp(int stamp);

#endif
