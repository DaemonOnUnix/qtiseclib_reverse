#pragma once
#include "defs.h"
_DWORD *__fastcall HAL_clk_ConfigClockMux(_DWORD *result, unsigned int *a2);
unsigned __int64 __fastcall HAL_clk_ConfigDFSMux(unsigned __int64 result, __int64 a2);
__int64 __fastcall HAL_clk_DisableClock(__int64 result);
_DWORD *__fastcall HAL_clk_DisablePowerDomain(_DWORD **a1);
__int64 __fastcall HAL_clk_DisableSource(__int64 a1);
__int64 __fastcall HAL_clk_EnableClock(__int64 result);
__int64 __fastcall HAL_clk_EnableDFS(__int64 result);
__int64 __fastcall HAL_clk_EnablePowerDomain(__int64 result);
__int64 *__fastcall HAL_clk_EnableSource(__int64 *result);
__int64 __fastcall HAL_clk_IsClockOn(int **a1);
__int64 __fastcall HAL_clk_IsPowerDomainOn(_DWORD **a1);
__int64 __fastcall HAL_clk_WaitForClockOn(int **a1);
__int64 __fastcall HAL_clk_WaitForPowerDomainOn(_DWORD **a1);
