/******************************************************************************************************************************
**---------------------------------------------------------------------------------------------------------------------------**
** Copyright (C) 2024 by ***.  All rights reserved.
**
**---------------------------------------------------------------------------------------------------------------------------**
** Administrative Information
** Namespace    : ..\Std_Types
** Class        : C
** Name         : Std_Types.h
** Archversion  : 1
** FcVersion    : 1.1
** Author       : yangnanyang
**---------------------------------------------------------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [YES/NO]: NO
**---------------------------------------------------------------------------------------------------------------------------**
** Descritption
** Std_Types driver source file.
******************************************************************************************************************************/
#ifndef __STD_TYPES_H
#define __STD_TYPES_H
/******************************************************************************************************************************
**                                              Other Header File Inclusion
******************************************************************************************************************************/
#include "Platform_Types.h"
#include "Compiler.h"
/******************************************************************************************************************************
**                                                  Macro Definition
******************************************************************************************************************************/
#define E_OK                            (0x00u)
#define E_NOT_OK                        (0x01u)

#define STD_ON                          (0x01u)
#define STD_OFF                         (0x00u)

#define STD_HIGH                        (0x01u)
#define STD_LOW                         (0x00u)

#define STD_ACTIVE                      (0x01u)
#define STD_IDLE                        (0x00u)

#define NULL_PTR                        ((void*)0)
/******************************************************************************************************************************
**                                                  Type Definition
******************************************************************************************************************************/
typedef uint8 Std_ReturnType;

#endif /*__STD_TYPES_H*/
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
