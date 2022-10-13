#pragma once
#include "defs.h"
unsigned int *__fastcall HAL_avs_Enable(unsigned int a1, int a2);
__int64 __fastcall HAL_avs_EnableCtl(unsigned int a1, unsigned __int8 a2);
__int64 __fastcall HAL_avs_GetVddSettleTimeUS(int a1, int a2);
__int64 __fastcall HAL_avs_Ramp_En(unsigned int a1, char a2);
__int64 __fastcall HAL_avs_RestoreBootVoltage(unsigned int a1);
__int64 HAL_avs_SecondaryRailInit();
__int64 __fastcall HAL_avs_SetClockDivider(unsigned int a1, char a2);
__int64 __fastcall HAL_avs_SetDelay(unsigned int a1, __int16 a2);
__int64 __fastcall HAL_avs_SetMaxVoltage(unsigned int a1, int a2);
__int64 __fastcall HAL_avs_SetMinVoltage(unsigned int a1, unsigned __int16 a2);
__int64 __fastcall HAL_avs_SetPowerMode(unsigned int a1, int a2);
__int64 __fastcall HAL_avs_SetVoltage(unsigned int a1, unsigned int a2);
__int64 __fastcall HAL_avs_SetVoltageStepSize(unsigned int a1, int a2, unsigned __int8 a3);
__int64 __fastcall HAL_avs_SetVoltageWidth(unsigned int a1, char a2);
