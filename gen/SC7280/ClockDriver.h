#pragma once
#include "defs.h"
__int64 __fastcall Clock_DisableClock(__int64 a1);
__int64 __fastcall Clock_DisableClockDomain(__int64 a1);
__int64 __fastcall Clock_DisableClockGroup(unsigned int a1);
__int64 __fastcall Clock_EnableClock(__int64 a1);
__int64 __fastcall Clock_EnableClockDomain(__int64 a1);
__int64 __fastcall Clock_EnableClockGroup(unsigned int a1);
__int64 __fastcall Clock_EnableDFS(__int64 a1);
__int64 __fastcall Clock_EnableSource(__int64 a1);
__int64 __fastcall Clock_GetClockId(__int64 a1, _QWORD *a2);
__int64 __fastcall Clock_GetFrequencyPlan(__int64 a1, unsigned __int64 *a2, unsigned int *a3);
__int64 __fastcall Clock_GetRPMId(__int64 a1, _QWORD *a2);
__int64 Clock_Init();
__int64 Clock_InitRPMh();
__int64 Clock_IsBSPSupported();
__int64 __fastcall Clock_IsClockOn(__int64 a1, _BYTE *a2);
__int64 __fastcall Clock_IsClockPowerDomainOn(__int64 a1, _BYTE *a2);
__int64 Clock_RPMRequest();
__int64 __fastcall Clock_SetClockFrequency(__int64 a1, int a2, unsigned int *a3);
__int64 __fastcall Clock_SetCXVoltage(int a1);
__int64 Clock_SetRPMAvailable();
__int64 Clock_TZInitDone();
__int64 __fastcall Clock_WriteRegRegion(__int64 result);
