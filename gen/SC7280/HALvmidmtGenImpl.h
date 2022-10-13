#pragma once
#include "defs.h"
__int64 __fastcall vmidmt_ClearError(__int64 *a1, char a2);
__int64 __fastcall vmidmt_ConfigErrRep(__int64 a1, char a2, int a3);
__int64 __fastcall vmidmt_ConfigSSDT(__int64 a1, __int64 a2, unsigned int a3);
__int64 __fastcall vmidmt_ConfigVmidCtxt(__int64 a1, unsigned int a2, __int64 *a3);
__int64 __fastcall vmidmt_ConfigVmidCtxtWithSIDList(__int64 a1, unsigned int a2, __int64 a3, unsigned int a4, __int64 *a5);
__int64 __fastcall vmidmt_EnableClientP(int **a1, char a2);
__int64 __fastcall vmidmt_GetError(__int64 result, unsigned __int8 a2, _DWORD *a3);
__int64 __fastcall vmidmt_Init(__int64 *a1, __int64 a2, __int64 *a3);
bool __fastcall vmidmt_IsError(__int64 *a1, char a2);
