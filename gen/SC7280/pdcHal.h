#pragma once
#include "defs.h"
__int64 __fastcall pdcHAL_disable(unsigned int a1, int a2);
__int64 __fastcall pdcHAL_enable(unsigned int a1, int a2);
__int64 __fastcall pdcHAL_setGPIOConfig(int a1, __int64 a2, _DWORD *a3);
int *__fastcall pdcHAL_setOwner(int a1, int a2, char a3);
__int64 __fastcall pdcHAL_setTriggerConfig(int a1, int a2, _DWORD *a3);
