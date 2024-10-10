/******************************************************************************************************************************
**---------------------------------------------------------------------------------------------------------------------------**
** Copyright (C) 2024 by ***.  All rights reserved.
**
**---------------------------------------------------------------------------------------------------------------------------**
** Administrative Information
** Namespace    : ..\Gp_BootCtl
** Class        : C
** Name         : Gp_BootCtl.c
** Archversion  : 1
** FcVersion    : 1.1
** Author       : yangnanyang
**---------------------------------------------------------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [YES/NO]: NO
**---------------------------------------------------------------------------------------------------------------------------**
** Descritption
** Gp_BootCtl driver source file.
******************************************************************************************************************************/

/******************************************************************************************************************************
**                                              Other Header File Inclusion
******************************************************************************************************************************/
#include "Gp_BootCtl.h"

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


/******************************************************************************************************************************
**                                               Function Source Code
******************************************************************************************************************************/

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_DisableWdg
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Disable watch dog for each core.
******************************************************************************************************************************/
void Gp_BootCtl_DisableWdg(void)
{
    /* Code */
}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_InitITCMDTCM
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Clear ram data in ITCM and DTCM.
******************************************************************************************************************************/
void Gp_BootCtl_InitITCMDTCM(void)
{
    /* Code */
}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_ResetSrcProcess
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Startup phase two.
******************************************************************************************************************************/
void Gp_BootCtl_ResetSrcProcess(void)
{
    /* Code */

}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_StartUpPhase_One
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Startup phase one.
******************************************************************************************************************************/
void Gp_BootCtl_StartUpPhase_One(void)
{
    uint8 TableIdx_u8 = 0;
    uint32* TempTagAddr_pu32 = NULL_PTR;
    uint32* TempSrcAddr_pu32 = NULL_PTR;
    uint32* TempEndAddr_pu32 = NULL_PTR;
    uint32* ClearTableAddr_pu32 = Gp_BootCtl_ClearTableCfg_au32;
    uint32* CopyTableAddr_pu32 = Gp_BootCtl_CopyTableCfg_au32;  

    /* Initialize clear tabel data */
    TableIdx_u8 = 0;
    while(ClearTableAddr_pu32[TableIdx_u8 * 2] != GP_BOOTCTL_ENDFLAG)
    {
        TempTagAddr_pu32 = (uint32*)ClearTableAddr_pu32[TableIdx_u8 * 2];
        TempEndAddr_pu32 = (uint32*)(ClearTableAddr_pu32[TableIdx_u8 * 2] + ClearTableAddr_pu32[TableIdx_u8 * 2 + 1]);
        for(TempTagAddr_pu32; TempTagAddr_pu32<TempEndAddr_pu32; TempTagAddr_pu32++)
        {
            *TempTagAddr_pu32 = 0x0u;
        }
        TableIdx_u8 ++;
    }

    /* Initialize copy tabel data */
    TableIdx_u8 = 0;
    while(CopyTableAddr_pu32[TableIdx_u8 * 3] != GP_BOOTCTL_ENDFLAG)
    {
        TempTagAddr_pu32 = (uint32*)CopyTableAddr_pu32[TableIdx_u8 * 3];
        TempSrcAddr_pu32 = (uint32*)CopyTableAddr_pu32[TableIdx_u8 * 3 + 1];
        TempEndAddr_pu32 = (uint32*)(CopyTableAddr_pu32[TableIdx_u8 * 3] + CopyTableAddr_pu32[TableIdx_u8 * 3 + 2]);
        for(TempTagAddr_pu32; TempTagAddr_pu32<TempEndAddr_pu32; TempTagAddr_pu32++,TempSrcAddr_pu32++)
        {
            *TempTagAddr_pu32 = *TempSrcAddr_pu32;
        }
        TableIdx_u8 ++;
    }

    /* Initialize ITCM/DTCM on CYT3BB/CYT4BB/CYT4BF */
    Gp_BootCtl_InitITCMDTCM();
}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_StartUpPhase_Two
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Startup phase two.
******************************************************************************************************************************/
void Gp_BootCtl_StartUpPhase_Two(void)
{
    /* Reset source precess */
    Gp_BootCtl_ResetSrcProcess();

    /* Set CpuIRQ priority on CM0+ core */

    /* FPU setting */

    /* Icache setting */

    /* Dcache setting */
}

/******************************************************************************************************************************
** Function Name      : Gp_BootCtl_ResetHander
** Service ID         : None
** Sync/Async         : None
** Reentrancy         : No
** Paramter[in]       : None
** Paramter[in/out]   : None
** Paramter[out]      : None
** Return Value       : None
** Description        : Reset hander function when cpu reset or power on.
******************************************************************************************************************************/
void Gp_BootCtl_ResetHander(void)
{
    /* Disable global interrupt */
    GP_BOOTCTL_ASM("CPSID i");

#if defined(_CORE_cm0plus_)
    /* Enable Ram0 ECC and Disable Ram0 ECC check */
    GP_BOOTCTL_ASM("MOVS r3,#1");
    GP_BOOTCTL_ASM("LSLS r3,r3,#16");
    GP_BOOTCTL_ASM("MOVS r4,#1");
    GP_BOOTCTL_ASM("LSLS r4,r4,#19");
    GP_BOOTCTL_ASM("ORRS r3,r4");
    GP_BOOTCTL_ASM("MOVS r4,%0": : "r"(Gp_BootCtl_RegAddrCfg_ctst.CpussRAM0Ctl0RegAddr_u32));
    GP_BOOTCTL_ASM("LDR  r5,[r4]");
    GP_BOOTCTL_ASM("ORRS r5,r3");
    GP_BOOTCTL_ASM("STR  r5,[r4]");
#if(GP_BOOTCTL_CFG_CHIPTYPE >= GP_BOOTCTL_CYT2B7)
    /* Enable Ram1 ECC and Disable Ram1 ECC check */
    GP_BOOTCTL_ASM("MOVS r4,%0": : "r"(Gp_BootCtl_RegAddrCfg_ctst.CpussRAM1Ctl0RegAddr_u32));
    GP_BOOTCTL_ASM("LDR  r5,[r4]");
    GP_BOOTCTL_ASM("ORRS r5,r3");
    GP_BOOTCTL_ASM("STR  r5,[r4]");
#endif
#if(GP_BOOTCTL_CFG_CHIPTYPE >= GP_BOOTCTL_CYT3BB)
    /* Enable Ram2 ECC and Disable Ram2 ECC check */
    GP_BOOTCTL_ASM("MOVS r4,%0": : "r"(Gp_BootCtl_RegAddrCfg_ctst.CpussRAM2Ctl0RegAddr_u32));
    GP_BOOTCTL_ASM("LDR  r5,[r4]");
    GP_BOOTCTL_ASM("ORRS r5,r3");
    GP_BOOTCTL_ASM("STR  r5,[r4]");
#endif
    /* Set vector table */
    GP_BOOTCTL_ASM("MOVS r3,%0" : : "r"(&Gp_BootCtl_VecTable_Core0_at[0]));
    GP_BOOTCTL_ASM("MOVS r4,%0" : : "r"(Gp_BootCtl_RegAddrCfg_ctst.ArmVtorRegAddr_u32));
    GP_BOOTCTL_ASM("STR  r3,[r4]");
    GP_BOOTCTL_ASM("DSB");
    /* Set Stack pointer */
    GP_BOOTCTL_ASM("LDR r4,[r3]");
    GP_BOOTCTL_ASM("MSR MSP,r4");
    /* initialize stack */
    GP_BOOTCTL_ASM("MOVS r3,%0" : : "r"(Gp_BootCtl_GenCfg_ctst.StackInitVal_u32));
    GP_BOOTCTL_ASM("MOVS r4,%0" : : "r"(&Stack_Start_Cm0p));
    GP_BOOTCTL_ASM("Gp_BootClt_StackInit:\n"
                        "STM  r4!,{r3}\n"
                        "CMP  SP,r4\n"
                        "BHI  Gp_BootClt_StackInit");
#elif defined(_CORE_cm4_)
    /* Set vector table */
    GP_BOOTCTL_ASM("MOV  r3,%0" : : "r"(&Gp_BootCtl_VecTable_Core0_at[0]));
    GP_BOOTCTL_ASM("MOV  r4,%0" : : "r"(Gp_BootCtl_RegAddrCfg_ctst.ArmVtorRegAddr_u32));
    GP_BOOTCTL_ASM("STR  r3,[r4]");
    GP_BOOTCTL_ASM("DSB");
    /* Set Stack pointer */
    GP_BOOTCTL_ASM("LDR  r4,[r3]");
    GP_BOOTCTL_ASM("MSR  MSP,r4");
    /* initialize stack */
    GP_BOOTCTL_ASM("MOV  r3,%0" : : "r"(Gp_BootCtl_GenCfg_ctst.StackInitVal_u32));
    GP_BOOTCTL_ASM("MOV  r4,%0" : : "r"(&Stack_Start_Cm4));
    GP_BOOTCTL_ASM("Gp_BootClt_StackInit:\n"
                        "STM  r4!,{r3}\n"
                        "CMP  SP,r4\n"
                        "BHI  Gp_BootClt_StackInit");
#elif defined(_CORE_cm7_)
    /* Get core index */
    GP_BOOTCTL_ASM("MOV  r4,%0" : : "r"(Gp_BootCtl_RegAddrCfg_ctst.CoreIdRegAddr_u32));
    GP_BOOTCTL_ASM("LDR  r3,[r4]");
    GP_BOOTCTL_ASM("LSR  r3,r3,#8");
    GP_BOOTCTL_ASM("AND  r3,#0xf");
    GP_BOOTCTL_ASM("CMP  r3,#14");
    GP_BOOTCTL_ASM("BEQ  Cm70_Init");
    GP_BOOTCTL_ASM("BNE  Cm70_Init_Skip");

    /* CM7_0 initialize */
    GP_BOOTCTL_ASM("Cm70_Init:: ");
    /* Set CM7_0 vector table */
    GP_BOOTCTL_ASM("MOV  r4,%0" : : "r"(&Gp_BootCtl_VecTable_Core0_at[0]));
    GP_BOOTCTL_ASM("MOV  r5,%0" : : "r"(Gp_BootCtl_RegAddrCfg_ctst.ArmVtorRegAddr_u32));
    GP_BOOTCTL_ASM("STR  r4,[r5]");
    GP_BOOTCTL_ASM("DSB");
    /* Set CM7_0 Stack pointer */
    GP_BOOTCTL_ASM("LDR  r5,[r4]");
    GP_BOOTCTL_ASM("MSR  MSP,r5");
    /* initialize CM7_0 stack */
    GP_BOOTCTL_ASM("MOV  r4,%0" : : "r"(Gp_BootCtl_GenCfg_ctst.StackInitVal_u32));
    GP_BOOTCTL_ASM("MOV  r5,%0" : : "r"(&Stack_Start_Cm7_0));
    GP_BOOTCTL_ASM("Gp_BootClt_StackInit:\n"
                        "STM  r5!,{r4}\n"
                        "CMP  SP,r5\n"
                        "BHI  Gp_BootClt_StackInit");
    /* Enable CM7_0 VTOR register and CM7_0 ITCM/DTCM configuretion register */
    GP_BOOTCTL_ASM("MOV  r4,%0" : : "r"(Gp_BootCtl_RegAddrCfg_ctst.CpussCM4_Cm70_CtlRegAddr_u32));
    GP_BOOTCTL_ASM("LDR  r5,[r4]");
    GP_BOOTCTL_ASM("BIC  r5,#0xB");
    GP_BOOTCTL_ASM("STR  r5,[r4]");
    GP_BOOTCTL_ASM("DSB");
    /* Enable ITCM */
    GP_BOOTCTL_ASM("MOV  r4,%0" : : "r"(Gp_BootCtl_RegAddrCfg_ctst.CM7_ITCMCR_RegAddr_u32));
    GP_BOOTCTL_ASM("LDR  r5,[r4]");
    GP_BOOTCTL_ASM("ORR  r5,#0x7");
    GP_BOOTCTL_ASM("STR  r5,[r4]");
    /* Enable DTCM */
    GP_BOOTCTL_ASM("MOV  r4,%0" : : "r"(Gp_BootCtl_RegAddrCfg_ctst.CM7_DTCMCR_RegAddr_u32));
    GP_BOOTCTL_ASM("LDR  r5,[r4]");
    GP_BOOTCTL_ASM("ORR  r5,#0x7");
    GP_BOOTCTL_ASM("STR  r5,[r4]");
    GP_BOOTCTL_ASM("DSB");
    GP_BOOTCTL_ASM("ISB");
    GP_BOOTCTL_ASM("Cm70_Init_Skip:: ");

#if(GP_BOOTCTL_CFG_CORE_NUM >= 2)
    GP_BOOTCTL_ASM("CMP  r3,#13");
    GP_BOOTCTL_ASM("BEQ  Cm71_Init");
    GP_BOOTCTL_ASM("BNE  Cm71_Init_Skip");

    /* CM7_1 initialize */
    GP_BOOTCTL_ASM("Cm71_Init:: ");
    /* Set CM7_1 vector table */
    GP_BOOTCTL_ASM("MOV  r4,%0" : : "r"(&Gp_BootCtl_VecTable_Core1_at[0]));
    GP_BOOTCTL_ASM("MOV  r5,%0" : : "r"(Gp_BootCtl_RegAddrCfg_ctst.ArmVtorRegAddr_u32));
    GP_BOOTCTL_ASM("STR  r4,[r5]");
    GP_BOOTCTL_ASM("DSB");
    /* Set CM7_1 Stack pointer */
    GP_BOOTCTL_ASM("LDR  r5,[r4]");
    GP_BOOTCTL_ASM("MSR  MSP,r5");
    /* initialize CM7_1 stack */
    GP_BOOTCTL_ASM("MOV  r4,%0" : : "r"(Gp_BootCtl_GenCfg_ctst.StackInitVal_u32));
    GP_BOOTCTL_ASM("MOV  r5,%0" : : "r"(&Stack_Start_Cm7_1));
    GP_BOOTCTL_ASM("Gp_BootClt_StackInit:\n"
                        "STM  r5!,{r4}\n"
                        "CMP  SP,r5\n"
                        "BHI  Gp_BootClt_StackInit");
    /* Enable CM7_1 VTOR register and CM7_1 ITCM/DTCM configuretion register */
    GP_BOOTCTL_ASM("MOV  r4,%0" : : "r"(Gp_BootCtl_RegAddrCfg_ctst.CpussCM71CtlRegAddr_u32));
    GP_BOOTCTL_ASM("LDR  r5,[r4]");
    GP_BOOTCTL_ASM("BIC  r5,#0xB");
    GP_BOOTCTL_ASM("STR  r5,[r4]");
    GP_BOOTCTL_ASM("DSB");
    /* Enable ITCM */
    GP_BOOTCTL_ASM("MOV  r4,%0" : : "r"(Gp_BootCtl_RegAddrCfg_ctst.CM7_ITCMCR_RegAddr_u32));
    GP_BOOTCTL_ASM("LDR  r5,[r4]");
    GP_BOOTCTL_ASM("ORR  r5,#0x7");
    GP_BOOTCTL_ASM("STR  r5,[r4]");
    /* Enable DTCM */
    GP_BOOTCTL_ASM("MOV  r4,%0" : : "r"(Gp_BootCtl_RegAddrCfg_ctst.CM7_DTCMCR_RegAddr_u32));
    GP_BOOTCTL_ASM("LDR  r5,[r4]");
    GP_BOOTCTL_ASM("ORR  r5,#0x7");
    GP_BOOTCTL_ASM("STR  r5,[r4]");
    GP_BOOTCTL_ASM("DSB");
    GP_BOOTCTL_ASM("ISB");
    GP_BOOTCTL_ASM("Cm71_Init_Skip:: ");
#endif
#endif
    /* Disable WDG */
    Gp_BootCtl_DisableWdg();
    /* Start up phase one */
    Gp_BootCtl_StartUpPhase_One();
    /* Start up phase two */
    Gp_BootCtl_StartUpPhase_Two();
    /* Enable ECC check */
    Gp_BootCtl_EnableEccCheck();
    /* Go to main */
    Gp_BootCtl_GotoMain();
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
