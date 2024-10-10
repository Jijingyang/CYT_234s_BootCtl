/******************************************************************************************************************************
**---------------------------------------------------------------------------------------------------------------------------**
** Copyright (C) 2024 by ***.  All rights reserved.
**
**---------------------------------------------------------------------------------------------------------------------------**
** Administrative Information
** Namespace    : ..\Gp_BootCtl
** Class        : C
** Name         : Gp_BootCtl_Cfg.c
** Archversion  : 1
** FcVersion    : 1.1
** Author       : yangnanyang
**---------------------------------------------------------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [YES/NO]: YES
**---------------------------------------------------------------------------------------------------------------------------**
** Descritption
** Gp_BootCtl driver source file.
******************************************************************************************************************************/

/******************************************************************************************************************************
**                                              Other Header File Inclusion
******************************************************************************************************************************/
#include "Gp_BootCtl_Cfg.h"

/******************************************************************************************************************************
**                                                  Macro Definition
******************************************************************************************************************************/

/******************************************************************************************************************************
**                                                  Type Definition
******************************************************************************************************************************/

/******************************************************************************************************************************
**                                               Static Local Declaration
******************************************************************************************************************************/

/******************************************************************************************************************************
**                                               Static Local Definition
******************************************************************************************************************************/
/* Clear table */
const uint32 Gp_BootCtl_ClearTableCfg_au32[] = 
{
    (uint32)&bss_start_addr,         /* Target address */
    (uint32)&bss_length,             /* Length */
    (uint32)GP_BOOTCTL_ENDFLAG       /* End flag */
};

/* Copye table */
const uint32 Gp_BootCtl_CopyTableCfg_au32[] = 
{
    (uint32)&data_ram_start_addr,    /* Target address */
    (uint32)&data_rom_start_addr,    /* Source address */
    (uint32)&data_ram_length,        /* Length */
    (uint32)GP_BOOTCTL_ENDFLAG       /* End flag */   
};

/* Configure all register address type that to be used */
const Gp_BootCtl_RegAddrCfg_Type Gp_BootCtl_RegAddrCfg_ctst =
{
#if(GP_BOOTCTL_CFG_CHIPTYPE == GP_BOOTCTL_CYT2B6)
    GP_BOOTCTL_CYT234S_CM0_VTOR_BASE_ADDR,          /* CM0P vector table base register address */
    GP_BOOTCTL_CYT234S_CM4_VTOR_BASE_ADDR,          /* CM4/CM70 vector table base register address */
    NULL_PTR,                                       /* CM71 vector table base register address */
    GP_BOOTCTL_CYT234S_ARM_CORE_VTOR_ADDR,          /* ARM core VTOR register address */
    GP_BOOTCTL_CYT234S_CPUSS_CM0_CTL_ADDR,          /* CPUSS CM0P CTL register address */
    GP_BOOTCTL_CYT234S_CPUSS_CM4_CTL_ADDR,          /* CPUSS CM4/70 CTL register address */
    NULL_PTR,                                       /* CPUSS CM71 CTL register address */
    GP_BOOTCTL_CYT234S_CPUSS_RAM0_CTL0,             /* CPUSS RAM0 CTL0 register address */
    NULL_PTR,                                       /* CPUSS RAM1 CTL0 register address */
    NULL_PTR,                                       /* CPUSS RAM2 CTL0 register address */
    NULL_PTR,                                       /* Arm CM7 SCS ITCM CTL register address */
    NULL_PTR,                                       /* Arm CM7 SCS DTCM CTL register address */
    GP_BOOTCTL_CYT234S_CORE_IDENTITY_ADDR           /* The number of the core that is accessing the bus register address */
#elif(GP_BOOTCTL_CFG_CHIPTYPE == GP_BOOTCTL_CYT2B7)
    GP_BOOTCTL_CYT234S_CM0_VTOR_BASE_ADDR,          /* CM0P vector table base register address */
    GP_BOOTCTL_CYT234S_CM4_VTOR_BASE_ADDR,          /* CM4/CM70 vector table base register address */
    NULL_PTR,                                       /* CM71 vector table base register address */
    GP_BOOTCTL_CYT234S_ARM_CORE_VTOR_ADDR,          /* ARM core VTOR register address */
    GP_BOOTCTL_CYT234S_CPUSS_CM0_CTL_ADDR,          /* CPUSS CM0P CTL register address */
    GP_BOOTCTL_CYT234S_CPUSS_CM4_CTL_ADDR,          /* CPUSS CM4/70 CTL register address */
    NULL_PTR,                                       /* CPUSS CM71 CTL register address */
    GP_BOOTCTL_CYT234S_CPUSS_RAM0_CTL0,             /* CPUSS RAM0 CTL0 register address */
    GP_BOOTCTL_CYT234S_CPUSS_RAM1_CTL0,             /* CPUSS RAM1 CTL0 register address */
    NULL_PTR,                                       /* CPUSS RAM2 CTL0 register address */
    NULL_PTR,                                       /* Arm CM7 SCS ITCM CTL register address */
    NULL_PTR,                                       /* Arm CM7 SCS DTCM CTL register address */
    GP_BOOTCTL_CYT234S_CORE_IDENTITY_ADDR           /* The number of the core that is accessing the bus register address */
#elif(GP_BOOTCTL_CFG_CHIPTYPE == GP_BOOTCTL_CYT2B9)
    GP_BOOTCTL_CYT234S_CM0_VTOR_BASE_ADDR,          /* CM0P vector table base register address */
    GP_BOOTCTL_CYT234S_CM4_VTOR_BASE_ADDR,          /* CM4/CM70 vector table base register address */
    NULL_PTR,                                       /* CM71 vector table base register address */
    GP_BOOTCTL_CYT234S_ARM_CORE_VTOR_ADDR,          /* ARM core VTOR register address */
    GP_BOOTCTL_CYT234S_CPUSS_CM0_CTL_ADDR,          /* CPUSS CM0P CTL register address */
    GP_BOOTCTL_CYT234S_CPUSS_CM4_CTL_ADDR,          /* CPUSS CM4/70 CTL register address */
    NULL_PTR,                                       /* CPUSS CM71 CTL register address */
    GP_BOOTCTL_CYT234S_CPUSS_RAM0_CTL0,             /* CPUSS RAM0 CTL0 register address */
    GP_BOOTCTL_CYT234S_CPUSS_RAM1_CTL0,             /* CPUSS RAM1 CTL0 register address */
    NULL_PTR,                                       /* CPUSS RAM2 CTL0 register address */
    NULL_PTR,                                       /* Arm CM7 SCS ITCM CTL register address */
    NULL_PTR,                                       /* Arm CM7 SCS DTCM CTL register address */
    GP_BOOTCTL_CYT234S_CORE_IDENTITY_ADDR           /* The number of the core that is accessing the bus register address */
#elif(GP_BOOTCTL_CFG_CHIPTYPE == GP_BOOTCTL_CYT2BL)
    GP_BOOTCTL_CYT234S_CM0_VTOR_BASE_ADDR,          /* CM0P vector table base register address */
    GP_BOOTCTL_CYT234S_CM4_VTOR_BASE_ADDR,          /* CM4/CM70 vector table base register address */
    NULL_PTR,                                       /* CM71 vector table base register address */
    GP_BOOTCTL_CYT234S_ARM_CORE_VTOR_ADDR,          /* ARM core VTOR register address */
    GP_BOOTCTL_CYT234S_CPUSS_CM0_CTL_ADDR,          /* CPUSS CM0P CTL register address */
    GP_BOOTCTL_CYT234S_CPUSS_CM4_CTL_ADDR,          /* CPUSS CM4/70 CTL register address */
    NULL_PTR,                                       /* CPUSS CM71 CTL register address */
    GP_BOOTCTL_CYT234S_CPUSS_RAM0_CTL0,             /* CPUSS RAM0 CTL0 register address */
    GP_BOOTCTL_CYT234S_CPUSS_RAM1_CTL0,             /* CPUSS RAM1 CTL0 register address */
    NULL_PTR,                                       /* CPUSS RAM2 CTL0 register address */
    NULL_PTR,                                       /* Arm CM7 SCS ITCM CTL register address */
    NULL_PTR,                                       /* Arm CM7 SCS DTCM CTL register address */
    GP_BOOTCTL_CYT234S_CORE_IDENTITY_ADDR           /* The number of the core that is accessing the bus register address */
#elif(GP_BOOTCTL_CFG_CHIPTYPE == GP_BOOTCTL_CYT3BB)
    GP_BOOTCTL_CYT234S_CM0_VTOR_BASE_ADDR,          /* CM0P vector table base register address */
    GP_BOOTCTL_CYT234S_CM70_VTOR_BASE_ADDR,         /* CM4/CM70 vector table base register address */
    NULL_PTR,                                       /* CM71 vector table base register address */
    GP_BOOTCTL_CYT234S_ARM_CORE_VTOR_ADDR,          /* ARM core VTOR register address */
    GP_BOOTCTL_CYT234S_CPUSS_CM0_CTL_ADDR,          /* CPUSS CM0P CTL register address */
    GP_BOOTCTL_CYT234S_CPUSS_CM70_CTL_ADDR,         /* CPUSS CM4/70 CTL register address */
    NULL_PTR,                                       /* CPUSS CM71 CTL register address */
    GP_BOOTCTL_CYT234S_CPUSS_RAM0_CTL0,             /* CPUSS RAM0 CTL0 register address */
    GP_BOOTCTL_CYT234S_CPUSS_RAM1_CTL0,             /* CPUSS RAM1 CTL0 register address */
    NULL_PTR,                                       /* CPUSS RAM2 CTL0 register address */
    GP_BOOTCTL_CYT234S_ARM_CM7_ITCM_ADDR,           /* Arm CM7 SCS ITCM CTL register address */
    GP_BOOTCTL_CYT234S_ARM_CM7_DTCM_ADDR,           /* Arm CM7 SCS DTCM CTL register address */
    GP_BOOTCTL_CYT234S_CORE_IDENTITY_ADDR           /* The number of the core that is accessing the bus register address */
#elif(GP_BOOTCTL_CFG_CHIPTYPE == GP_BOOTCTL_CYT4BB)
    GP_BOOTCTL_CYT234S_CM0_VTOR_BASE_ADDR,          /* CM0P vector table base register address */
    GP_BOOTCTL_CYT234S_CM70_VTOR_BASE_ADDR,         /* CM4/CM70 vector table base register address */
    GP_BOOTCTL_CYT234S_CM71_VTOR_BASE_ADDR,         /* CM71 vector table base register address */
    GP_BOOTCTL_CYT234S_ARM_CORE_VTOR_ADDR,          /* ARM core VTOR register address */
    GP_BOOTCTL_CYT234S_CPUSS_CM0_CTL_ADDR,          /* CPUSS CM0P CTL register address */
    GP_BOOTCTL_CYT234S_CPUSS_CM70_CTL_ADDR,         /* CPUSS CM4/70 CTL register address */
    GP_BOOTCTL_CYT234S_CPUSS_CM71_CTL_ADDR,         /* CPUSS CM71 CTL register address */
    GP_BOOTCTL_CYT234S_CPUSS_RAM0_CTL0,             /* CPUSS RAM0 CTL0 register address */
    GP_BOOTCTL_CYT234S_CPUSS_RAM1_CTL0,             /* CPUSS RAM1 CTL0 register address */
    NULL_PTR,                                       /* CPUSS RAM2 CTL0 register address */
    GP_BOOTCTL_CYT234S_ARM_CM7_ITCM_ADDR,           /* Arm CM7 SCS ITCM CTL register address */
    GP_BOOTCTL_CYT234S_ARM_CM7_DTCM_ADDR,           /* Arm CM7 SCS DTCM CTL register address */
    GP_BOOTCTL_CYT234S_CORE_IDENTITY_ADDR           /* The number of the core that is accessing the bus register address */
#elif(GP_BOOTCTL_CFG_CHIPTYPE == GP_BOOTCTL_CYT4BF)
    GP_BOOTCTL_CYT234S_CM0_VTOR_BASE_ADDR,          /* CM0P vector table base register address */
    GP_BOOTCTL_CYT234S_CM70_VTOR_BASE_ADDR,         /* CM4/CM70 vector table base register address */
    GP_BOOTCTL_CYT234S_CM71_VTOR_BASE_ADDR,         /* CM71 vector table base register address */
    GP_BOOTCTL_CYT234S_ARM_CORE_VTOR_ADDR,          /* ARM core VTOR register address */
    GP_BOOTCTL_CYT234S_CPUSS_CM0_CTL_ADDR,          /* CPUSS CM0P CTL register address */
    GP_BOOTCTL_CYT234S_CPUSS_CM70_CTL_ADDR,         /* CPUSS CM4/70 CTL register address */
    GP_BOOTCTL_CYT234S_CPUSS_CM71_CTL_ADDR,         /* CPUSS CM71 CTL register address */
    GP_BOOTCTL_CYT234S_CPUSS_RAM0_CTL0,             /* CPUSS RAM0 CTL0 register address */
    GP_BOOTCTL_CYT234S_CPUSS_RAM1_CTL0,             /* CPUSS RAM1 CTL0 register address */
    GP_BOOTCTL_CYT234S_CPUSS_RAM2_CTL0,             /* CPUSS RAM2 CTL0 register address */
    GP_BOOTCTL_CYT234S_ARM_CM7_ITCM_ADDR,           /* Arm CM7 SCS ITCM CTL register address */
    GP_BOOTCTL_CYT234S_ARM_CM7_DTCM_ADDR,           /* Arm CM7 SCS DTCM CTL register address */
    GP_BOOTCTL_CYT234S_CORE_IDENTITY_ADDR           /* The number of the core that is accessing the bus register address */
#endif
};

const Gp_BootCtl_GenCfg_Type Gp_BootCtl_GenCfg_ctst = {
    GP_BOOTCTL_CFG_STACK_INIT_VAL
};



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