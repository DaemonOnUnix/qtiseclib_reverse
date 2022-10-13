/*0000000000000000 b $d
0000000000000000 d $d
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 b asAVSRegs
0000000000000000 d bIsInit.1181
0000000000000000 d gHALAVSContext
0000000000000000 T HAL_avs_BusyWait
0000000000000000 T HAL_avs_Enable
0000000000000000 T HAL_avs_EnableCtl
0000000000000000 T HAL_avs_GetVddSettleTimeUS
0000000000000000 T HAL_avs_Init
0000000000000000 T HAL_avs_Ramp_En
0000000000000000 T HAL_avs_RestoreBootVoltage
0000000000000000 T HAL_avs_SecondaryRailInit
0000000000000000 T HAL_avs_SetClockDivider
0000000000000000 T HAL_avs_SetDelay
0000000000000000 T HAL_avs_SetMaxVoltage
0000000000000000 T HAL_avs_SetMinVoltage
0000000000000000 T HAL_avs_SetPowerMode
0000000000000000 T HAL_avs_SetVoltage
0000000000000000 T HAL_avs_SetVoltageStepSize
0000000000000000 T HAL_avs_SetVoltageWidth
                 U qtiseclib_cb_udelay
*/
#include "saw_v4.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

unsigned int *__fastcall HAL_avs_Enable(unsigned int a1, int a2)
{
  unsigned int *result; // x0
  unsigned int v3; // w1

  result = (unsigned int *)asAVSRegs[7 * a1 + 4];
  if ( a2 )
  {
    *result |= 1u;
    v3 = *result | 0x10;
  }
  else
  {
    *result &= ~1u;
    v3 = *result & 0xFFFFFFEF;
  }
  *result = v3;
  return result;
}



__int64 __fastcall HAL_avs_EnableCtl(unsigned int a1, unsigned __int8 a2)
{
  int v2; // w22
  int v4; // w21
  __int64 *v5; // x19
  unsigned int v6; // w19
  int VddSettleTimeUS; // w0

  v2 = a2;
  v4 = 201;
  v5 = &asAVSRegs[7 * a1];
  *(_DWORD *)*v5 = ((a2 != 0) << 7) | 0x30000;
  while ( 1 )
  {
    if ( !--v4 )
    {
      v6 = 0;
      goto LABEL_7;
    }
    if ( (*(_DWORD *)v5[1] & 0x30000) == 0 )
      break;
    qtiseclib_cb_udelay(2LL);
  }
  v6 = 1;
LABEL_7:
  if ( v2 )
  {
    VddSettleTimeUS = HAL_avs_GetVddSettleTimeUS(a1, gHALAVSContext[4 * a1 + 2]);
    qtiseclib_cb_udelay((unsigned int)(VddSettleTimeUS + 36));
  }
  return v6;
}



__int64 __fastcall HAL_avs_GetVddSettleTimeUS(int a1, int a2)
{
  if ( a2 )
    return 120 * ((unsigned int)(1000 * a2) / gHALAVSContext[4 * a1 + 3]) / 0x64;
  else
    return 0LL;
}




__int64 __fastcall HAL_avs_Ramp_En(unsigned int a1, char a2)
{
  unsigned int *v2; // x2
  __int64 result; // x0

  v2 = (unsigned int *)asAVSRegs[7 * a1 + 4];
  *v2 = ((a2 & 1) << 15) | *v2 & 0xFFFF7FFF;
  result = *v2;
  *v2 = ((a2 & 1) << 14) | result & 0xFFFFBFFF;
  return result;
}



__int64 __fastcall HAL_avs_RestoreBootVoltage(unsigned int a1)
{
  return HAL_avs_SetVoltage(a1, gHALAVSContext[4 * a1 + 1]);
}



__int64 HAL_avs_SecondaryRailInit()
{
  HAL_avs_Enable(1u, 1);
  HAL_avs_EnableCtl(1u, 1u);
  return HAL_avs_RestoreBootVoltage(1u);
}



__int64 __fastcall HAL_avs_SetClockDivider(unsigned int a1, char a2)
{
  _DWORD *v2; // x2
  __int64 result; // x0

  v2 = (_DWORD *)asAVSRegs[7 * a1 + 4];
  result = ((a2 & 0x1F) << 8) | *v2 & 0xFFFFE0FF;
  *v2 = result;
  return result;
}



__int64 __fastcall HAL_avs_SetDelay(unsigned int a1, __int16 a2)
{
  _DWORD *v2; // x2
  __int64 result; // x0

  v2 = (_DWORD *)asAVSRegs[7 * a1 + 6];
  result = *v2 & 0xFFFFFC00;
  *v2 = result | a2 & 0x3FF;
  return result;
}



__int64 __fastcall HAL_avs_SetMaxVoltage(unsigned int a1, int a2)
{
  _DWORD *v2; // x2
  __int64 result; // x0

  v2 = (_DWORD *)asAVSRegs[7 * a1 + 5];
  result = (unsigned __int16)*v2;
  *v2 = result | (a2 << 16);
  return result;
}



__int64 __fastcall HAL_avs_SetMinVoltage(unsigned int a1, unsigned __int16 a2)
{
  _DWORD *v2; // x2
  __int64 result; // x0

  v2 = (_DWORD *)asAVSRegs[7 * a1 + 5];
  result = *v2 & 0xFFFF0000;
  *v2 = result | a2;
  return result;
}



__int64 __fastcall HAL_avs_SetPowerMode(unsigned int a1, int a2)
{
  int v2; // w2
  int v4; // w20
  __int64 *v5; // x19

  if ( a2 == 1 )
  {
    v2 = 7;
  }
  else
  {
    v2 = 6;
    if ( a2 )
      return 0LL;
  }
  v4 = 201;
  v5 = &asAVSRegs[7 * a1];
  *(_DWORD *)*v5 = v2 | 0x20000;
  while ( --v4 )
  {
    if ( (*(_DWORD *)v5[1] & 0x30000) == 0 )
      return 1LL;
    qtiseclib_cb_udelay(2LL);
  }
  return 0LL;
}



__int64 __fastcall HAL_avs_SetVoltage(unsigned int a1, unsigned int a2)
{
  int v4; // w24
  unsigned int v5; // w2
  int v6; // w1
  int v7; // w23
  __int64 *v8; // x22
  _DWORD *v9; // x0
  unsigned int v10; // w24
  __int64 VddSettleTimeUS; // x0
  __int64 result; // x0

  v4 = 201;
  v5 = gHALAVSContext[4 * a1 + 2];
  v6 = a2 - v5;
  v7 = v5 - a2;
  if ( v5 < a2 )
    v7 = v6;
  v8 = &asAVSRegs[7 * a1];
  *(_DWORD *)*v8 = (unsigned __int16)a2 | 0x100000;
  while ( 1 )
  {
    if ( !--v4 )
    {
      v10 = 0;
      goto LABEL_10;
    }
    v9 = (_DWORD *)v8[1];
    if ( (*v9 & 0x30000) == 0 && a2 == (unsigned __int16)*v9 )
      break;
    qtiseclib_cb_udelay(2LL);
  }
  v10 = 1;
LABEL_10:
  if ( !bIsInit_1181 && a2 > gHALAVSContext[4 * a1 + 2] )
  {
    VddSettleTimeUS = HAL_avs_GetVddSettleTimeUS(a1, v7);
    qtiseclib_cb_udelay(VddSettleTimeUS);
  }
  result = v10;
  bIsInit_1181 = 0;
  gHALAVSContext[4 * a1 + 2] = a2;
  return result;
}



__int64 __fastcall HAL_avs_SetVoltageStepSize(unsigned int a1, int a2, unsigned __int8 a3)
{
  int *v3; // x3
  __int64 result; // x0

  v3 = (int *)asAVSRegs[7 * a1 + 4];
  *v3 = *v3 & 0xFFFFFF | (a2 << 24);
  result = (a3 << 16) | *v3 & 0xFF00FFFF;
  *v3 = result;
  return result;
}



__int64 __fastcall HAL_avs_SetVoltageWidth(unsigned int a1, char a2)
{
  _DWORD *v2; // x2
  __int64 result; // x0

  v2 = (_DWORD *)asAVSRegs[7 * a1 + 4];
  result = (32 * (a2 & 1)) | *v2 & 0xFFFFFFDF;
  *v2 = result;
  return result;
}



