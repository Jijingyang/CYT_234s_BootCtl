/******************************************************************************************************************************
**---------------------------------------------------------------------------------------------------------------------------**
** Copyright (C) 2024 by ***.  All rights reserved.
**
**---------------------------------------------------------------------------------------------------------------------------**
** Administrative Information
** Namespace    : ..\Gp_BootCtl
** Class        : C
** Name         : Gp_BootCtl_Vct.h
** Archversion  : 1
** FcVersion    : 1.1
** Author       : yangnanyang
**---------------------------------------------------------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [YES/NO]: YES
**---------------------------------------------------------------------------------------------------------------------------**
** Descritption
** Gp_BootCtl driver source file.
******************************************************************************************************************************/
#ifndef __GP_BOOTCTL_VCT_H
#define __GP_BOOTCTL_VCT_H
/******************************************************************************************************************************
**                                              Other Header File Inclusion
******************************************************************************************************************************/
#include "Gp_BootCtl_Cfg.h"

/******************************************************************************************************************************
**                                                  Macro Definition
******************************************************************************************************************************/


/******************************************************************************************************************************
**                                           Global variables With Declaration
******************************************************************************************************************************/
/* Variable extern */
extern const ExceptionHander_Type Gp_BootCtl_VecTable_Core0_at[];
#if(GP_BOOTCTL_CFG_CORE_NUM >= 2)
extern const ExceptionHander_Type Gp_BootCtl_VecTable_Core1_at[];
#endif

/* Import linker file symbol */
#if defined(_CORE_cm0plus_)
extern void* Stack_Start_Cm0p;
extern void* Stack_Top_Cm0p;
#elif defined(_CORE_cm4_)
extern void* Stack_Start_Cm4;
extern void* Stack_Top_Cm4;
#elif defined(_CORE_cm7_)
extern void* Stack_Start_Cm7_0;
extern void* Stack_Top_Cm7_0;
#endif
#if (GP_BOOTCTL_CFG_CORE_NUM >= 2)
extern void* Stack_Start_Cm7_1;
extern void* Stack_Top_Cm7_1;
#endif

#endif/* __GP_BOOTCTL_VCT_H */
/******************************************************************************************************************************
**-----------------------------------------------------------------------------------------------------------------------------
** ArchVersion History:
** V1:
** Initial version.
**-----------------------------------------------------------------------------------------------------------------------------
** FcVersion History:
** 1.0: 2024.09.18 yangnanyang
** N: Initial version.
**-----------------------------------------------------------------------------------------------------------------------------
******************************************************************************************************************************/