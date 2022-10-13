#pragma once
#include "defs.h"
__int64 __fastcall isContextInitialized(_BYTE *a1, unsigned int a2);
__int64 __fastcall RscHalCheckAMCFinishedIRQ(unsigned int a1, int *a2);
__int64 __fastcall RscHalCheckTCSCmdCompletionStatus(unsigned int a1, unsigned __int8 a2, unsigned __int8 a3, _BYTE *a4);
__int64 __fastcall RscHalCheckTCSCmdIssueStatus(unsigned int a1, unsigned __int8 a2, unsigned __int8 a3, _BYTE *a4);
__int64 __fastcall RscHalCheckTCSCmdTriggerStatus(unsigned int a1, unsigned __int8 a2, unsigned __int8 a3, _BYTE *a4);
__int64 __fastcall RscHalCheckTCSIdle_HLOS(unsigned int a1);
__int64 __fastcall RscHalClearAMCFinishedIRQ(unsigned int a1, unsigned int a2);
__int64 __fastcall RscHalClearePCBTimedOut(unsigned int a1);
__int64 __fastcall RscHalConfigureCmdCompletion(unsigned int a1, unsigned __int8 a2, __int16 a3);
__int64 __fastcall RscHalConvertAMCtoTCS(unsigned int a1, unsigned __int8 a2);
__int64 __fastcall RscHalConvertTCStoAMC(unsigned int a1, unsigned __int8 a2);
__int64 __fastcall RscHalDisableAMCFinishedIRQ(unsigned int a1, unsigned int a2);
__int64 __fastcall RscHalEnableAMCFinishedIRQ(unsigned int a1, unsigned int a2);
__int64 __fastcall rscHalGetChipsetMappingTable(__int64 a1);
__int64 __fastcall rscHalGetDrvInfo(__int64 a1);
__int64 __fastcall rscHalGetNumCmdsPerTcs(__int64 a1, unsigned __int8 a2, _DWORD *a3);
__int64 __fastcall rscHalGetNumTcs(unsigned __int64 a1, char a2, _DWORD *a3);
__int64 __fastcall RscHalIsePCBTimedOut(unsigned int a1, _BYTE *a2);
__int64 __fastcall RscHalIsTCSIdle(unsigned int a1, unsigned __int8 a2, _BYTE *a3);
__int64 __fastcall RscHalReadConfig(unsigned int a1, _DWORD *a2, _DWORD *a3);
__int64 __fastcall RscHalReadResponseData(unsigned int a1, unsigned __int8 a2, unsigned __int8 a3, _DWORD *a4);
__int64 __fastcall RscHalRegisterDrv(unsigned int a1);
__int64 __fastcall rscHalSetupDrv0Tcs(__int64 a1, unsigned __int8 a2, unsigned __int8 *a3);
__int64 __fastcall rscHalSetupDrv2Tcs(__int64 a1, unsigned __int8 a2, unsigned __int8 *a3);
__int64 __fastcall RscHalSetupTCS(__int64 a1);
__int64 __fastcall RscHalToggleePCBTimeOut(unsigned int a1, char a2);
__int64 __fastcall RscHalToggleTCSCmd(unsigned int a1, unsigned __int8 a2, unsigned __int16 a3);
__int64 __fastcall RscHalTriggerTCS(unsigned int a1, unsigned __int8 a2);
__int64 __fastcall RscHalUpdateePCBTimeOutThreshold(unsigned int a1, unsigned __int16 a2);
__int64 __fastcall RscHalVersionID(unsigned int a1, int *a2);
