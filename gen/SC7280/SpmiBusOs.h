#pragma once
#include "defs.h"
__int64 SpmiBus_DeInit();
__int64 SpmiBus_Init();
__int64 __fastcall SpmiBus_ReadLong(char a1, int a2, int a3, char *a4, unsigned int a5, __int64 *a6);
__int64 __fastcall SpmiBus_WriteLong(char a1, int a2, int a3, char *a4, unsigned int a5);
