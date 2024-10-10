/******************************************************************************************************************************
**---------------------------------------------------------------------------------------------------------------------------**
** Copyright (C) 2024 by ***.  All rights reserved.
**
**---------------------------------------------------------------------------------------------------------------------------**
** Administrative Information
** Namespace    : ..\Gp_BootCtl
** Class        : C
** Name         : Gp_BootCtl_Vct.c
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
#include "Gp_BootCtl_Vct.h"

/******************************************************************************************************************************
**                                                  Macro Definition
******************************************************************************************************************************/

/******************************************************************************************************************************
**                                                  Type Definition
******************************************************************************************************************************/

/******************************************************************************************************************************
**                                               Static Local Declaration
******************************************************************************************************************************/
extern void Gp_BootCtl_ResetHander(void);
GP_BOOTCTL_WEAK void Gp_BootCtl_NMIHander(void);
GP_BOOTCTL_WEAK void Gp_BootCtl_HardFaultHander(void);
GP_BOOTCTL_WEAK void Gp_BootCtl_MemMFaultHander(void);
GP_BOOTCTL_WEAK void Gp_BootCtl_BusFaultHander(void);
GP_BOOTCTL_WEAK void Gp_BootCtl_UsageFaultHander(void);
GP_BOOTCTL_WEAK void Gp_BootCtl_SVCallHander(void);
GP_BOOTCTL_WEAK void Gp_BootCtl_PendSVHander(void);
GP_BOOTCTL_WEAK void Gp_BootCtl_SysTickHander(void);
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuIRQ0Hander(void);
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuIRQ1Hander(void);
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuIRQ2Hander(void);
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuIRQ3Hander(void);
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuIRQ4Hander(void);
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuIRQ5Hander(void);
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuIRQ6Hander(void);
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuIRQ7Hander(void);
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuInternalIRQ0Hander(void);
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuInternalIRQ1Hander(void);
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuInternalIRQ2Hander(void);
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuInternalIRQ3Hander(void);
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuInternalIRQ4Hander(void);
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuInternalIRQ5Hander(void);
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuInternalIRQ6Hander(void);
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuInternalIRQ7Hander(void);

/******************************************************************************************************************************
**                                               Static Local Definition
******************************************************************************************************************************/
const ExceptionHander_Type Gp_BootCtl_VecTable_Core0_at[] = 
{
    /* 0 Stack pointer */
#if defined(_CORE_cm0plus_)
    (ExceptionHander_Type)&Stack_Top_Cm0p,
#elif defined(_CORE_cm4_)
    (ExceptionHander_Type)&Stack_Top_Cm4,
#elif defined(_CORE_cm7_)
    (ExceptionHander_Type)&Stack_Top_Cm7_0,
#endif
    /* 1 Reset hander */
    Gp_BootCtl_ResetHander,
#if(GP_BOOTCTL_CFG_USE_OS_VECTOR == STD_OFF)
    /* 2 NMI */
    Gp_BootCtl_NMIHander,
    /* 3 HardFault */
    Gp_BootCtl_HardFaultHander,
    /* 4-6 Reserved(CM0+), Memory Management Fault,Bus Fault,Usage Fault(CM4/CM7) */
#if defined(_CORE_cm0plus_)
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
#elif (defined(_CORE_cm4_) || defined(_CORE_cm7_))
    Gp_BootCtl_MemMFaultHander,
    Gp_BootCtl_BusFaultHander,
    Gp_BootCtl_UsageFaultHander,
#endif
    /* 7-10 Reserved */
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    /* 11 SVCall */
    Gp_BootCtl_SVCallHander,
    /* 12-13 Reserved */
    NULL_PTR,
    NULL_PTR,
    /* 14 PendSV */
    Gp_BootCtl_PendSVHander,
    /* 15 System tick */
    Gp_BootCtl_SysTickHander,
    /* 16-17 CPU IRQ0-1 */
#if defined(_CORE_cm0plus_)
    (ExceptionHander_Type)GP_BOOTCTL_ALLCHIP_CM0P_CPUIRQ0_ADDR,
#if((GP_BOOTCTL_CFG_CHIPTYPE == GP_BOOTCTL_CYT2B6) || (GP_BOOTCTL_CFG_CHIPTYPE == GP_BOOTCTL_CYT2B7) || \
    (GP_BOOTCTL_CFG_CHIPTYPE == GP_BOOTCTL_CYT2B9) || (GP_BOOTCTL_CFG_CHIPTYPE == GP_BOOTCTL_CYT2BL))
    (ExceptionHander_Type)GP_BOOTCTL_ENTRYCHIP_CM0P_CPUIRQ1_ADDR,
#elif((GP_BOOTCTL_CFG_CHIPTYPE == GP_BOOTCTL_CYT3BB) || (GP_BOOTCTL_CFG_CHIPTYPE == GP_BOOTCTL_CYT4BB) || \
      (GP_BOOTCTL_CFG_CHIPTYPE == GP_BOOTCTL_CYT4BF))
    (ExceptionHander_Type)GP_BOOTCTL_HIGHCHIP_CM0P_CPUIRQ1_ADDR,
#endif
#else
    Gp_BootCtl_CpuIRQ0Hander,
    Gp_BootCtl_CpuIRQ1Hander,
#endif
    /* 18-23 CPU IRQ2-7 */
    Gp_BootCtl_CpuIRQ2Hander,
    Gp_BootCtl_CpuIRQ3Hander,
    Gp_BootCtl_CpuIRQ4Hander,
    Gp_BootCtl_CpuIRQ5Hander,
    Gp_BootCtl_CpuIRQ6Hander,
    Gp_BootCtl_CpuIRQ7Hander,
    /* 24-31 CPU internal(softwart) interrupt0-7*/
    Gp_BootCtl_CpuInternalIRQ0Hander,
    Gp_BootCtl_CpuInternalIRQ1Hander,
    Gp_BootCtl_CpuInternalIRQ2Hander,
    Gp_BootCtl_CpuInternalIRQ3Hander,
    Gp_BootCtl_CpuInternalIRQ4Hander,
    Gp_BootCtl_CpuInternalIRQ5Hander,
    Gp_BootCtl_CpuInternalIRQ6Hander,
    Gp_BootCtl_CpuInternalIRQ7Hander
#endif
};



#if (GP_BOOTCTL_CFG_CORE_NUM >= 2)  /* means this is CM7_1 */
const ExceptionHander_Type Gp_BootCtl_VecTable_Core1_at[] = 
{
    /* 0 Stack pointer */
    (ExceptionHander_Type)&Stack_Top_Cm7_1,
    /* 1 Reset hander */
    Gp_BootCtl_ResetHander,
#if(GP_BOOTCTL_CFG_USE_OS_VECTOR == STD_OFF)
    /* 2 NMI */
    Gp_BootCtl_NMIHander,
    /* 3 HardFault */
    Gp_BootCtl_HardFaultHander,
    /* 4-6 Reserved(CM0+), Memory Management Fault,Bus Fault,Usage Fault(CM4/CM7) */
    Gp_BootCtl_MemMFaultHander,
    Gp_BootCtl_BusFaultHander,
    Gp_BootCtl_UsageFaultHander,
    /* 7-10 Reserved */
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    /* 11 SVCall */
    Gp_BootCtl_SVCallHander,
    /* 12-13 Reserved */
    NULL_PTR,
    NULL_PTR,
    /* 14 PendSV */
    Gp_BootCtl_PendSVHander,
    /* 15 System tick */
    Gp_BootCtl_SysTickHander,
    /* 16-17 CPU IRQ0-1 */
    Gp_BootCtl_CpuIRQ0Hander,
    Gp_BootCtl_CpuIRQ1Hander,
    /* 18-23 CPU IRQ2-7 */
    Gp_BootCtl_CpuIRQ2Hander,
    Gp_BootCtl_CpuIRQ3Hander,
    Gp_BootCtl_CpuIRQ4Hander,
    Gp_BootCtl_CpuIRQ5Hander,
    Gp_BootCtl_CpuIRQ6Hander,
    Gp_BootCtl_CpuIRQ7Hander,
    /* 24-31 CPU internal(softwart) interrupt0-7*/
    Gp_BootCtl_CpuInternalIRQ0Hander,
    Gp_BootCtl_CpuInternalIRQ1Hander,
    Gp_BootCtl_CpuInternalIRQ2Hander,
    Gp_BootCtl_CpuInternalIRQ3Hander,
    Gp_BootCtl_CpuInternalIRQ4Hander,
    Gp_BootCtl_CpuInternalIRQ5Hander,
    Gp_BootCtl_CpuInternalIRQ6Hander,
    Gp_BootCtl_CpuInternalIRQ7Hander
#endif
};
#endif


/******************************************************************************************************************************
**                                                Function Source Code
******************************************************************************************************************************/


/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_NMIHander
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Non Maskable Interrupt hander.
******************************************************************************************************************************/
GP_BOOTCTL_WEAK void Gp_BootCtl_NMIHander(void)
{

}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_HardFaultHander
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Hard Fault hander.
******************************************************************************************************************************/
GP_BOOTCTL_WEAK void Gp_BootCtl_HardFaultHander(void)
{

}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_MemMFaultHander
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Memory Management Fault hander.
******************************************************************************************************************************/
GP_BOOTCTL_WEAK void Gp_BootCtl_MemMFaultHander(void)
{

}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_BusFaultHander
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Bus Fault hander.
******************************************************************************************************************************/
GP_BOOTCTL_WEAK void Gp_BootCtl_BusFaultHander(void)
{

}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_UsageFaultHander
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Usage Fault hander.
******************************************************************************************************************************/
GP_BOOTCTL_WEAK void Gp_BootCtl_UsageFaultHander(void)
{

}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_SVCallHander
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Supervisory Call hander.
******************************************************************************************************************************/
GP_BOOTCTL_WEAK void Gp_BootCtl_SVCallHander(void)
{

}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_PendSVHander
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Pend Supervisory hander.
******************************************************************************************************************************/
GP_BOOTCTL_WEAK void Gp_BootCtl_PendSVHander(void)
{

}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_SysTickHander
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : System Tick hander.
******************************************************************************************************************************/
GP_BOOTCTL_WEAK void Gp_BootCtl_SysTickHander(void)
{

}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_CpuIRQ0Hander
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Cpu Interrupt 0 hander.
******************************************************************************************************************************/
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuIRQ0Hander(void)
{

}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_CpuIRQ1Hander
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Cpu Interrupt 1 hander.
******************************************************************************************************************************/
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuIRQ1Hander(void)
{

}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_CpuIRQ2Hander
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Cpu Interrupt 2 hander.
******************************************************************************************************************************/
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuIRQ2Hander(void)
{

}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_CpuIRQ3Hander
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Cpu Interrupt 3 hander.
******************************************************************************************************************************/
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuIRQ3Hander(void)
{

}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_CpuIRQ4Hander
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Cpu Interrupt 4 hander.
******************************************************************************************************************************/
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuIRQ4Hander(void)
{

}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_CpuIRQ5Hander
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Cpu Interrupt 5 hander.
******************************************************************************************************************************/
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuIRQ5Hander(void)
{

}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_CpuIRQ6Hander
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Cpu Interrupt 6 hander.
******************************************************************************************************************************/
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuIRQ6Hander(void)
{

}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_CpuIRQ7Hander
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Cpu Interrupt 7 hander.
******************************************************************************************************************************/
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuIRQ7Hander(void)
{

}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_CpuInternalIRQ0Hander
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Cpu Software Interrupt 0 hander.
******************************************************************************************************************************/
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuInternalIRQ0Hander(void)
{

}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_CpuInternalIRQ1Hander
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Cpu Software Interrupt 1 hander.
******************************************************************************************************************************/
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuInternalIRQ1Hander(void)
{

}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_CpuInternalIRQ2Hander
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Cpu Software Interrupt 2 hander.
******************************************************************************************************************************/
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuInternalIRQ2Hander(void)
{

}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_CpuInternalIRQ3Hander
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Cpu Software Interrupt 3 hander.
******************************************************************************************************************************/
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuInternalIRQ3Hander(void)
{

}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_CpuInternalIRQ4Hander
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Cpu Software Interrupt 4 hander.
******************************************************************************************************************************/
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuInternalIRQ4Hander(void)
{

}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_CpuInternalIRQ5Hander
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Cpu Software Interrupt 5 hander.
******************************************************************************************************************************/
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuInternalIRQ5Hander(void)
{

}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_CpuInternalIRQ6Hander
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Cpu Software Interrupt 6 hander.
******************************************************************************************************************************/
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuInternalIRQ6Hander(void)
{

}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_CpuInternalIRQ7Hander
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Cpu Software Interrupt 7 hander.
******************************************************************************************************************************/
GP_BOOTCTL_WEAK void Gp_BootCtl_CpuInternalIRQ7Hander(void)
{

}




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