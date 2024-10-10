/******************************************************************************************************************************
**---------------------------------------------------------------------------------------------------------------------------**
** Copyright (C) 2024 by ***.  All rights reserved.
**
**---------------------------------------------------------------------------------------------------------------------------**
** Administrative Information
** Namespace    : ..\Gp_BootCtl
** Class        : C
** Name         : Gp_BootCtl_Types.h
** Archversion  : 1
** FcVersion    : 1.1
** Author       : yangnanyang
**---------------------------------------------------------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [YES/NO]: NO
**---------------------------------------------------------------------------------------------------------------------------**
** Descritption
** Gp_BootCtl driver source file.
******************************************************************************************************************************/
#ifndef __GP_BOOTCTL_TYPES_H
#define __GP_BOOTCTL_TYPES_H
/******************************************************************************************************************************
**                                              Other Header File Inclusion
******************************************************************************************************************************/
#include "Std_Types.h"

/******************************************************************************************************************************
**                                                  Macro Definition
******************************************************************************************************************************/
/* Define embedded assembly symbols */
#if defined __GHS__
    #define GP_BOOTCTL_ASM              __asm
#elif defined __ICCARM__
    #define GP_BOOTCTL_ASM              __asm
#else
    #define GP_BOOTCTL_ASM              /* None */
#endif

/* Define weak symbol */
#define GP_BOOTCTL_WEAK                 __weak

/* Define chip type */
#define GP_BOOTCTL_CYT2B6               (0U)
#define GP_BOOTCTL_CYT2B7               (1U)
#define GP_BOOTCTL_CYT2B9               (2U)
#define GP_BOOTCTL_CYT2BL               (3U)
#define GP_BOOTCTL_CYT3BB               (4U)
#define GP_BOOTCTL_CYT4BB               (5U)
#define GP_BOOTCTL_CYT4BF               (6U)

/* Define core identification */
#define GP_BOOTCTL_CORE_CM0P            (0U)
#define GP_BOOTCTL_CORE_CM4_CM70        (14U)
#define GP_BOOTCTL_CORE_CM71            (13U)

/*Define end flag*/
#define GP_BOOTCTL_ENDFLAG              (0xFFFFFFFFU)

/* Define address of the CM0P IRQ0,IRQ1 hander */
#define GP_BOOTCTL_ALLCHIP_CM0_CPUIRQ0_ADDR                        (0x00000049U)    /* Note: This value should be read from the 0x40 address of the chip */
#define GP_BOOTCTL_ENTRYCHIP_CM0_CPUIRQ1_ADDR                      (0x0000022DU)    /* Note: This value should be read from the 0x44 address of the chip */
#define GP_BOOTCTL_HIGHCHIP_CM0_CPUIRQ1_ADDR                       (0x000002A5U)    /* Note: This value should be read from the 0x44 address of the chip */

/* Define general register address */
#define GP_BOOTCTL_CYT234S_CM0_VTOR_BASE_ADDR                      (0x40201120U)    /* CM0P vector table base register address */
#define GP_BOOTCTL_CYT234S_CM4_VTOR_BASE_ADDR                      (0x40200200U)    /* CM4 vector table base register address */
#define GP_BOOTCTL_CYT234S_CM70_VTOR_BASE_ADDR                     (0x40200200U)    /* CM70 vector table base register address */
#define GP_BOOTCTL_CYT234S_CM71_VTOR_BASE_ADDR                     (0x40200600U)    /* CM71 vector table base register address */
#define GP_BOOTCTL_CYT234S_ARM_CORE_VTOR_ADDR                      (0xE000ED08U)    /* Arm core VTOR register address */
#define GP_BOOTCTL_CYT234S_CPUSS_CM0_CTL_ADDR                      (0x40201000U)    /* CPUSS CM0P CTL register address */
#define GP_BOOTCTL_CYT234S_CPUSS_CM4_CTL_ADDR                      (0x4020000CU)    /* CPUSS CM4 CTL register address */
#define GP_BOOTCTL_CYT234S_CPUSS_CM70_CTL_ADDR                     (0x4020000CU)    /* CPUSS CM70 CTL register address */
#define GP_BOOTCTL_CYT234S_CPUSS_CM71_CTL_ADDR                     (0x4020040CU)    /* CPUSS CM71 CTL register address */
#define GP_BOOTCTL_CYT234S_CPUSS_RAM0_CTL0                         (0x40201300U)    /* CPUSS RAM0 CTL0 register address */
#define GP_BOOTCTL_CYT234S_CPUSS_RAM1_CTL0                         (0x40201380U)    /* CPUSS RAM0 CTL0 register address */
#define GP_BOOTCTL_CYT234S_CPUSS_RAM2_CTL0                         (0x402013A0U)    /* CPUSS RAM0 CTL0 register address */
#define GP_BOOTCTL_CYT234S_ARM_CM7_ITCM_ADDR                       (0xE000EF90U)    /* Arm CM7 SCS ITCM CTL register address */
#define GP_BOOTCTL_CYT234S_ARM_CM7_DTCM_ADDR                       (0xE000EF94U)    /* Arm CM7 SCS DTCM CTL register address */
#define GP_BOOTCTL_CYT234S_CORE_IDENTITY_ADDR                      (0x40240000U)    /* The number of the core that is accessing the bus register address */


/******************************************************************************************************************************
**                                                  Type Definition
******************************************************************************************************************************/
/* Define vector table hander function type */
typedef void(*ExceptionHander_Type)(void);

/* Define all register address type that to be used */
typedef struct Gp_BootCtl_RegAddrCfg{
    uint32      Cm0pVtorBaseRegAddr_u32;        /* CM0P vector table base register address */
    uint32      Cm4_Cm70_VtorBaseRegAddr_u32;   /* CM4/CM70 vector table base register address */
    uint32      Cm71_VtorBaseRegAddr_u32;       /* CM71 vector table base register address */
    uint32      ArmVtorRegAddr_u32;             /* ARM core VTOR register address */
    uint32      CpussCM0CtlRegAddr_u32;         /* CPUSS CM0 CTL register address */
    uint32      CpussCM4_Cm70_CtlRegAddr_u32;   /* CPUSS CM4/70 CTL register address */
    uint32      CpussCM71CtlRegAddr_u32;        /* CPUSS CM71 CTL register address */
    uint32      CpussRAM0Ctl0RegAddr_u32;       /* CPUSS RAM0 CTL0 register address */
    uint32      CpussRAM1Ctl0RegAddr_u32;       /* CPUSS RAM1 CTL0 register address */
    uint32      CpussRAM2Ctl0RegAddr_u32;       /* CPUSS RAM2 CTL0 register address */
    uint32      CM7_ITCMCR_RegAddr_u32;         /* Arm CM7 SCS ITCM CTL register address */
    uint32      CM7_DTCMCR_RegAddr_u32;         /* Arm CM7 SCS DTCM CTL register address */
    uint32      CoreIdRegAddr_u32;              /* The number of the core that is accessing the bus register address */
}Gp_BootCtl_RegAddrCfg_Type;

typedef struct Gp_BootCtl_GenCfg{
    uint32      StackInitVal_u32;               /* Value of the stack initialization */
}Gp_BootCtl_GenCfg_Type;







#endif /*__GP_BOOTCTL_TYPES_H*/
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
