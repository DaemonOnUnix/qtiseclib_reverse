#pragma once
#include "defs.h"
unsigned __int64 __fastcall pdc_getTriggerConfig(int a1, unsigned int a2);
__int64 __fastcall pdcGpio_config(int a1, _DWORD *a2, _DWORD *a3);
__int64 __fastcall pdcGpio_disable(int a1);
__int64 __fastcall pdcGpio_enable(int a1);
__int64 __fastcall pdcGpio_unconfig(int a1);
__int64 pdc_initialize();
__int64 __fastcall pdcInt_config(int a1, __int64 a2);
__int64 __fastcall pdcInt_disable(int a1);
__int64 __fastcall pdcInt_enable(int a1);
