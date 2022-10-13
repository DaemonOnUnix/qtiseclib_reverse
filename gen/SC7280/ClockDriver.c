/*0000000000000000 d $d
0000000000000000 r $d
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
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 r aClockVRegMapping
0000000000000000 T Clock_DisableClock
0000000000000000 T Clock_DisableClockDomain
0000000000000000 T Clock_DisableClockGroup
0000000000000000 t Clock_DisableSource
0000000000000000 d ClockDrvCtxt
0000000000000000 T Clock_EnableClock
0000000000000000 T Clock_EnableClockDomain
0000000000000000 T Clock_EnableClockGroup
0000000000000000 T Clock_EnableDFS
0000000000000000 T Clock_EnableSource
0000000000000000 T Clock_GetClockId
0000000000000000 T Clock_GetFrequencyPlan
0000000000000000 T Clock_GetRPMId
0000000000000000 T Clock_Init
                 U Clock_InitImage
0000000000000000 T Clock_InitRPMh
0000000000000000 T Clock_IsBSPSupported
0000000000000000 T Clock_IsClockOn
0000000000000000 T Clock_IsClockPowerDomainOn
0000000000000004 C ClockMutex
                 U Clock_PostInitImage
0000000000000000 T Clock_RPMRequest
0000000000000000 T Clock_SetClockFrequency
0000000000000000 T Clock_SetCXVoltage
0000000000000000 T Clock_SetRPMAvailable
                 U ClockTZBSPConfig
0000000000000000 T Clock_TZInitDone
0000000000000000 t Clock_VoltageRequest
0000000000000000 T Clock_WriteRegRegion
                 U cmd_db_query_addr
                 U HAL_clk_ConfigClockMux
                 U HAL_clk_ConfigDFSMux
                 U HAL_clk_DisableClock
                 U HAL_clk_DisablePowerDomain
                 U HAL_clk_DisableSource
                 U HAL_clk_EnableClock
                 U HAL_clk_EnableDFS
                 U HAL_clk_EnablePowerDomain
                 U HAL_clk_EnableSource
                 U HAL_clk_IsClockOn
                 U HAL_clk_IsPowerDomainOn
                 U HAL_clk_WaitForClockOn
                 U HAL_clk_WaitForPowerDomainOn
                 U icbuarb_create_client
                 U icbuarb_issue_request
                 U pwr_utils_hlvl
                 U pwr_utils_hlvl_named_resource
                 U pwr_utils_lvl_resource_idx
                 U qtisec_assert
                 U qtiseclib_cb_spin_lock
                 U qtiseclib_cb_spin_unlock
                 U qtiseclib_cb_strcmp
                 U qtisec_malloc
                 U rpmh_barrier_single
                 U rpmh_create_handle
                 U rpmh_issue_command
                 U rpmh_issue_command_set
*/
#include "ClockDriver.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall Clock_DisableClock(__int64 a1)
{
  int v2; // w0
  __int64 v3; // x0
  int v4; // w1

  if ( !a1 )
    return 0xFFFFFFFFLL;
  qtiseclib_cb_spin_lock(&ClockMutex);
  v2 = *(_DWORD *)(a1 + 48);
  if ( v2 )
  {
    *(_DWORD *)(a1 + 48) = v2 - 1;
    if ( v2 == 1 )
    {
      HAL_clk_DisableClock(a1 + 8);
      Clock_DisableClockDomain(*(_QWORD *)(a1 + 32));
      v3 = *(_QWORD *)(a1 + 40);
      if ( v3 )
      {
        v4 = *(_DWORD *)(v3 + 16);
        if ( v4 )
        {
          *(_DWORD *)(v3 + 16) = v4 - 1;
          if ( v4 == 1 )
            HAL_clk_DisablePowerDomain((_DWORD **)v3);
        }
      }
    }
  }
  qtiseclib_cb_spin_unlock(&ClockMutex);
  return 0LL;
}



__int64 __fastcall Clock_DisableClockDomain(__int64 a1)
{
  int v1; // w1
  __int64 v3; // x0
  __int64 v4; // x0

  if ( !a1 )
    return 0xFFFFFFFFLL;
  v1 = *(_DWORD *)(a1 + 48);
  if ( !v1 )
    return 0LL;
  *(_DWORD *)(a1 + 48) = v1 - 1;
  if ( v1 != 1 )
    return 0LL;
  v3 = *(_QWORD *)(a1 + 40);
  if ( v3 )
    Clock_DisableSource(v3);
  v4 = *(_QWORD *)(a1 + 32);
  if ( v4 )
    Clock_VoltageRequest(*(_DWORD *)(v4 + 16), 0);
  return 0LL;
}



__int64 __fastcall Clock_DisableClockGroup(unsigned int a1)
{
  __int64 v1; // x29
  __int64 v3; // x24
  __int64 result; // x0
  unsigned __int64 v5; // x23
  __int64 v6; // x19
  __int64 v7; // x3
  __int64 v8; // x4
  __int64 v9; // x5
  __int64 v10; // x6
  __int64 v11; // x7
  int v12; // w0
  unsigned int v13; // w20
  unsigned __int64 i; // x20
  __int64 v15; // x0
  __int64 v16; // x0
  unsigned __int64 j; // x20
  unsigned __int64 k; // x20
  __int64 v19; // x0
  __int64 v20; // x2
  unsigned __int64 m; // x20
  __int64 v22; // x0
  unsigned __int64 n; // x20
  _QWORD *v24; // x0
  int v25; // w3
  __int64 v26; // [xsp+0h] [xbp-50h]
  __int64 v27[2]; // [xsp+40h] [xbp-10h] BYREF

  if ( a1 > 4 )
    return 0xFFFFFFFFLL;
  v26 = v1;
  v3 = *(_QWORD *)((char *)ClockDrvCtxt[0] + (unsigned __int64)&loc_8);
  result = 0xFFFFFFFFLL;
  if ( v3 )
  {
    v5 = (unsigned __int64)a1 << 6;
    v6 = v3 + v5;
    if ( *(_QWORD *)(v3 + v5) )
    {
      qtiseclib_cb_spin_lock(&ClockMutex);
      v12 = *(_DWORD *)(v6 + 40);
      if ( v12 )
      {
        *(_DWORD *)(v6 + 40) = v12 - 1;
        if ( v12 == 1 )
        {
          v13 = *(_DWORD *)(v6 + 44);
          v27[0] = 0LL;
          v27[1] = 0LL;
          for ( i = *(_QWORD *)(v3 + v5) + 24LL * v13 - 24; i >= *(_QWORD *)v6; i -= 24LL )
          {
            if ( !*(_DWORD *)(i + 16) )
              HAL_clk_DisableClock(i);
          }
          v15 = *(_QWORD *)(v6 + 8);
          if ( v15 )
          {
            for ( j = v15 + 16LL * *(unsigned int *)(v6 + 48) - 16; j >= *(_QWORD *)(v6 + 8); j -= 16LL )
            {
              if ( !*(_DWORD *)(j + 8) )
                HAL_clk_DisablePowerDomain((_DWORD **)j);
            }
          }
          v16 = *(_QWORD *)(v6 + 16);
          if ( v16 )
          {
            for ( k = v16 + 24LL * *(unsigned int *)(v6 + 52) - 24; k >= *(_QWORD *)(v6 + 16); k -= 24LL )
            {
              if ( !*(_DWORD *)(k + 16) )
                HAL_clk_DisableClock(k);
            }
          }
          v19 = *(_QWORD *)(v6 + 24);
          if ( v19 )
          {
            v20 = 24LL;
            for ( m = v19 + 24LL * *(unsigned int *)(v6 + 56) - 24; m >= *(_QWORD *)(v6 + 24); m -= 24LL )
            {
              v24 = *(_QWORD **)(m + 16);
              if ( v24 )
                icbuarb_issue_request(v24, v27, v20, v7, v8, v9, v10, v11, v26);
            }
          }
          v22 = *(_QWORD *)(v6 + 32);
          if ( v22 )
          {
            for ( n = v22 + 24LL * *(unsigned int *)(v6 + 60) - 24; n >= *(_QWORD *)(v6 + 32); n -= 24LL )
            {
              v25 = *(_DWORD *)(n + 12);
              if ( v25 )
                rpmh_issue_command(qword_1A528, 0, 1, v25, 0);
            }
          }
        }
      }
      qtiseclib_cb_spin_unlock(&ClockMutex);
      return 0LL;
    }
  }
  return result;
}



__int64 __fastcall Clock_EnableClock(__int64 a1)
{
  int v2; // w0
  int **v3; // x21
  __int64 v4; // x19
  int v5; // w0

  if ( !a1 )
    return 0xFFFFFFFFLL;
  qtiseclib_cb_spin_lock(&ClockMutex);
  v2 = *(_DWORD *)(a1 + 48);
  *(_DWORD *)(a1 + 48) = v2 + 1;
  if ( v2
    || ((v3 = (int **)(a1 + 8),
         Clock_EnableClockDomain(*(_QWORD *)(a1 + 32)),
         HAL_clk_EnableClock(a1 + 8),
         (v4 = *(_QWORD *)(a1 + 40)) == 0)
     || (v5 = *(_DWORD *)(v4 + 16), *(_DWORD *)(v4 + 16) = v5 + 1, v5)
     || (HAL_clk_EnablePowerDomain(v4), (unsigned int)HAL_clk_WaitForPowerDomainOn((_DWORD **)v4)))
    && (unsigned int)HAL_clk_WaitForClockOn(v3) )
  {
    qtiseclib_cb_spin_unlock(&ClockMutex);
    return 0LL;
  }
  else
  {
    qtiseclib_cb_spin_unlock(&ClockMutex);
    return 0xFFFFFFFFLL;
  }
}



__int64 __fastcall Clock_EnableClockDomain(__int64 a1)
{
  int v1; // w1
  __int64 v3; // x0
  __int64 v4; // x0

  if ( !a1 )
    return 0xFFFFFFFFLL;
  v1 = *(_DWORD *)(a1 + 48);
  *(_DWORD *)(a1 + 48) = v1 + 1;
  if ( v1 )
    return 0LL;
  v3 = *(_QWORD *)(a1 + 32);
  if ( v3 )
    Clock_VoltageRequest(0, *(_DWORD *)(v3 + 16));
  v4 = *(_QWORD *)(a1 + 40);
  if ( v4 )
    Clock_EnableSource(v4);
  return 0LL;
}



__int64 __fastcall Clock_EnableClockGroup(unsigned int a1)
{
  __int64 v1; // x29
  __int64 v2; // x23
  unsigned __int64 v3; // x21
  __int64 v4; // x19
  __int64 v5; // x2
  __int64 v6; // x3
  __int64 v7; // x4
  __int64 v8; // x5
  __int64 v9; // x6
  __int64 v10; // x7
  int v11; // w0
  __int64 v12; // x20
  __int64 v13; // x20
  __int64 v14; // x0
  int v15; // w0
  int v16; // w3
  int v17; // w4
  unsigned int v18; // w0
  int **v19; // x20
  __int64 client; // x0
  __int64 v21; // x0
  _QWORD *v22; // x20
  __int64 v23; // x0
  _QWORD *v24; // x24
  _DWORD **v25; // x0
  _QWORD *v26; // x24
  __int64 v27; // x0
  int **i; // x19
  int **v29; // x0
  __int64 v31; // [xsp+0h] [xbp-60h]
  __int64 v32; // [xsp+50h] [xbp-10h] BYREF
  __int64 v33; // [xsp+58h] [xbp-8h]

  if ( a1 > 4 )
    return 0xFFFFFFFFLL;
  v31 = v1;
  v2 = *(_QWORD *)((char *)ClockDrvCtxt[0] + (unsigned __int64)&loc_8);
  if ( v2 )
  {
    v3 = (unsigned __int64)a1 << 6;
    v4 = v2 + v3;
    if ( *(_QWORD *)(v2 + v3) )
    {
      qtiseclib_cb_spin_lock(&ClockMutex);
      v11 = *(_DWORD *)(v4 + 40);
      *(_DWORD *)(v4 + 40) = v11 + 1;
      if ( v11 )
        goto LABEL_43;
      v12 = *(_QWORD *)(v4 + 32);
      v32 = 0LL;
      v33 = 0LL;
      if ( v12 )
      {
        *(_DWORD *)(v4 + 60) = 0;
        while ( 1 )
        {
          v14 = *(_QWORD *)v12;
          if ( !*(_QWORD *)v12 )
            break;
          ++*(_DWORD *)(v4 + 60);
          if ( !*(_DWORD *)(v12 + 12) )
          {
            *(_DWORD *)(v12 + 12) = cmd_db_query_addr(v14);
            v15 = pwr_utils_hlvl_named_resource(*(_QWORD *)v12, *(_DWORD *)(v12 + 8), 0LL);
            *(_DWORD *)(v12 + 16) = v15;
            if ( !*(_DWORD *)(v12 + 12) )
            {
              v15 = 0;
              *(_DWORD *)cortex_a78_aarch64_sysini = 0;
              __break(0x3E8u);
            }
            if ( v15 == -1 )
            {
              *(_DWORD *)cortex_a78_aarch64_sysini = 0;
              __break(0x3E8u);
            }
          }
          v16 = *(_DWORD *)(v12 + 12);
          v17 = *(_DWORD *)(v12 + 16);
          v12 += 24LL;
          v18 = rpmh_issue_command(qword_1A528, 0, 1, v16, v17);
          rpmh_barrier_single(qword_1A528, v18);
        }
      }
      v13 = *(_QWORD *)(v4 + 24);
      if ( v13 )
      {
        *(_DWORD *)(v4 + 56) = 0;
        while ( *(_DWORD *)(v13 + 8) )
        {
          ++*(_DWORD *)(v4 + 56);
          if ( !*(_QWORD *)(v13 + 16) )
          {
            client = icbuarb_create_client(*(_DWORD *)v13, *(_DWORD *)(v13 + 4));
            *(_QWORD *)(v13 + 16) = client;
            if ( !client )
              qtisec_assert("noship_src/drivers/systemdrivers/clock/src/v1/ClockDriver.c", 0x255u, "pICB->hICB");
          }
          v21 = *(unsigned int *)(v13 + 8);
          v13 += 24LL;
          v32 = v21;
          v33 = v21;
          icbuarb_issue_request(*(_QWORD **)(v13 - 8), &v32, v5, v6, v7, v8, v9, v10, v31);
        }
      }
      v19 = *(int ***)(v4 + 16);
      if ( v19 )
      {
        *(_DWORD *)(v4 + 52) = 0;
        while ( *v19 )
        {
          ++*(_DWORD *)(v4 + 52);
          HAL_clk_EnableClock((__int64)v19);
          if ( !(unsigned int)HAL_clk_WaitForClockOn(v19) )
            goto LABEL_42;
          v19 += 3;
        }
      }
      v22 = *(_QWORD **)(v4 + 8);
      if ( v22 )
      {
        *(_DWORD *)(v4 + 48) = 0;
        while ( *v22 )
        {
          ++*(_DWORD *)(v4 + 48);
          v23 = (__int64)v22;
          v22 += 2;
          HAL_clk_EnablePowerDomain(v23);
        }
        v24 = *(_QWORD **)(v4 + 8);
        LODWORD(v22) = 0;
        while ( *v24 )
        {
          v25 = (_DWORD **)v24;
          v24 += 2;
          LODWORD(v22) = (unsigned int)v22 | ((unsigned int)HAL_clk_WaitForPowerDomainOn(v25) == 0);
        }
      }
      v26 = *(_QWORD **)(v2 + v3);
      *(_DWORD *)(v4 + 44) = 0;
      while ( *v26 )
      {
        ++*(_DWORD *)(v4 + 44);
        v27 = (__int64)v26;
        v26 += 3;
        HAL_clk_EnableClock(v27);
      }
      for ( i = *(int ***)(v2 + v3); *i; i += 3 )
      {
        v29 = i;
        LODWORD(v22) = (unsigned int)v22 | ((unsigned int)HAL_clk_WaitForClockOn(v29) == 0);
      }
      if ( !(_DWORD)v22 )
      {
LABEL_43:
        qtiseclib_cb_spin_unlock(&ClockMutex);
        return 0LL;
      }
LABEL_42:
      qtiseclib_cb_spin_unlock(&ClockMutex);
    }
  }
  return 0xFFFFFFFFLL;
}



__int64 __fastcall Clock_EnableDFS(__int64 a1)
{
  unsigned __int64 v1; // x19
  __int64 result; // x0
  __int64 i; // x20

  if ( !a1 )
    return 0xFFFFFFFFLL;
  v1 = *(_QWORD *)(a1 + 32);
  result = 0xFFFFFFFFLL;
  if ( v1 )
  {
    if ( *(_DWORD *)(v1 + 16) )
    {
      result = 0LL;
      if ( (*(_DWORD *)(v1 + 56) & 0x800000) == 0 )
      {
        for ( i = *(_QWORD *)(v1 + 24) + 4LL; *(_DWORD *)(i - 4); i += 24LL )
        {
          if ( *(unsigned __int8 *)(i + 10) != 255 )
            HAL_clk_ConfigDFSMux(v1, i);
        }
        HAL_clk_EnableDFS(v1);
        *(_DWORD *)(v1 + 56) |= 0x800000u;
        return 0LL;
      }
    }
  }
  return result;
}



__int64 __fastcall Clock_EnableSource(__int64 a1)
{
  unsigned int v1; // w20
  int v3; // w0

  if ( !a1 || *(_QWORD *)(a1 + 32) && (unsigned int)Clock_EnableSource() )
  {
    return (unsigned int)-1;
  }
  else
  {
    v3 = *(_DWORD *)(a1 + 16);
    v1 = 0;
    *(_DWORD *)(a1 + 16) = v3 + 1;
    if ( !v3 )
    {
      v1 = 0;
      if ( !*(_QWORD *)(a1 + 24) )
        HAL_clk_EnableSource((__int64 *)a1);
    }
  }
  return v1;
}



__int64 __fastcall Clock_GetClockId(__int64 a1, _QWORD *a2)
{
  bool v2; // zf
  _QWORD *v5; // x20
  __int64 result; // x0

  if ( a1 )
    v2 = a2 == 0LL;
  else
    v2 = 1;
  if ( v2 )
    return 0xFFFFFFFFLL;
  v5 = *(_QWORD **)((char *)ClockDrvCtxt[0] + (unsigned __int64)&loc_10);
  result = 0xFFFFFFFFLL;
  if ( v5 )
  {
    while ( *v5 )
    {
      result = qtiseclib_cb_strcmp(a1);
      if ( !(_DWORD)result )
      {
        *a2 = v5;
        return result;
      }
      v5 += 7;
    }
    result = 0xFFFFFFFFLL;
    *a2 = 0LL;
  }
  return result;
}



__int64 __fastcall Clock_GetFrequencyPlan(__int64 a1, unsigned __int64 *a2, unsigned int *a3)
{
  bool v3; // zf
  __int64 v5; // x22
  __int64 result; // x0
  __int64 v7; // x0
  unsigned int v8; // w20
  unsigned __int64 v11; // x0
  _DWORD *v12; // x2
  __int64 i; // x0

  if ( a2 )
    v3 = a3 == 0LL;
  else
    v3 = 1;
  if ( !v3 && a1 != 0 )
  {
    v5 = *(_QWORD *)(a1 + 32);
    result = 0xFFFFFFFFLL;
    if ( !v5 )
      return result;
    v7 = *(_QWORD *)(v5 + 24);
    v8 = 0;
    if ( !v7 )
    {
      *a3 = 0;
      return 0LL;
    }
    while ( *(_DWORD *)v7 )
    {
      if ( (*(_DWORD *)(v5 + 56) & 0x800000) == 0 || *(unsigned __int8 *)(v7 + 14) != 255 )
        ++v8;
      v7 += 24LL;
    }
    if ( *a2 || (*a3 = v8, v11 = qtisec_malloc(4LL * (v8 & 0x3FFFFFFF)), (*a2 = v11) != 0) )
    {
      if ( v8 <= *a3 )
      {
        v12 = (_DWORD *)*a2;
        for ( i = *(_QWORD *)(v5 + 24); *(_DWORD *)i; i += 24LL )
        {
          if ( (*(_DWORD *)(v5 + 56) & 0x800000) == 0 || *(unsigned __int8 *)(i + 14) != 255 )
            *v12++ = *(_DWORD *)i;
        }
        *a3 = v8;
        return 0LL;
      }
      *a3 = v8;
    }
    else
    {
      *a3 = 0;
    }
    return 0xFFFFFFFFLL;
  }
  return 0xFFFFFFFFLL;
}



__int64 __fastcall Clock_GetRPMId(__int64 a1, _QWORD *a2)
{
  bool v2; // zf
  _QWORD *v4; // x19
  __int64 result; // x0

  if ( a1 )
    v2 = a2 == 0LL;
  else
    v2 = 1;
  if ( v2 )
    return 0xFFFFFFFFLL;
  v4 = *(_QWORD **)ClockDrvCtxt[0];
  if ( *(_QWORD *)ClockDrvCtxt[0] )
  {
    while ( *v4 )
    {
      result = qtiseclib_cb_strcmp(a1);
      if ( !(_DWORD)result )
      {
        *a2 = v4;
        return result;
      }
      v4 += 3;
    }
  }
  return 0xFFFFFFFFLL;
}



__int64 Clock_Init()
{
  __int64 result; // x0

  result = (unsigned __int8)byte_1A500;
  if ( !byte_1A500 )
  {
    Clock_InitRPMh();
    if ( (unsigned int)Clock_InitImage((__int64)ClockDrvCtxt) )
      qtisec_assert(
        "noship_src/drivers/systemdrivers/clock/src/v1/ClockDriver.c",
        0x307u,
        "0 == Clock_InitImage(&ClockDrvCtxt)");
    result = 1LL;
    byte_1A500 = 1;
  }
  return result;
}



__int64 Clock_InitRPMh()
{
  int addr; // w23
  int v1; // w22
  int v2; // w21
  unsigned int v3; // w0

  qword_1A528 = rpmh_create_handle(0, (__int64)"clock");
  dword_1A530 = pwr_utils_lvl_resource_idx((__int64)"cx.lvl");
  dword_1A534 = pwr_utils_lvl_resource_idx((__int64)"mx.lvl");
  addr = cmd_db_query_addr((__int64)"cx.lvl");
  v1 = cmd_db_query_addr((__int64)"mx.lvl");
  v2 = cmd_db_query_addr((__int64)"xo.lvl");
  if ( !qword_1A528 )
    qtisec_assert("noship_src/drivers/systemdrivers/clock/src/v1/ClockDriver.c", 0xC5u, "pDrvCtxt->hRPMh != 0");
  if ( dword_1A530 == -1 )
    qtisec_assert("noship_src/drivers/systemdrivers/clock/src/v1/ClockDriver.c", 0xC6u, "pDrvCtxt->nCXLVLIdx != -1");
  if ( !addr )
    qtisec_assert("noship_src/drivers/systemdrivers/clock/src/v1/ClockDriver.c", 0xC7u, "nCXAddr");
  if ( !v1 )
    qtisec_assert("noship_src/drivers/systemdrivers/clock/src/v1/ClockDriver.c", 0xC8u, "nMXAddr");
  if ( !v2 )
    qtisec_assert("noship_src/drivers/systemdrivers/clock/src/v1/ClockDriver.c", 0xC9u, "nXOAddr");
  dword_1A544 = addr;
  dword_1A550 = v1;
  v3 = rpmh_issue_command(qword_1A528, 0, 1, v2, 3);
  return rpmh_barrier_single(qword_1A528, v3);
}



__int64 Clock_IsBSPSupported()
{
  return 1LL;
}



__int64 __fastcall Clock_IsClockOn(__int64 a1, _BYTE *a2)
{
  bool v2; // zf
  __int64 result; // x0

  if ( a1 )
    v2 = a2 == 0LL;
  else
    v2 = 1;
  if ( v2 )
    return 0xFFFFFFFFLL;
  result = HAL_clk_IsClockOn((int **)(a1 + 8));
  if ( (_DWORD)result )
  {
    *a2 = 1;
    return 0LL;
  }
  else
  {
    *a2 = 0;
  }
  return result;
}



__int64 __fastcall Clock_IsClockPowerDomainOn(__int64 a1, _BYTE *a2)
{
  bool v2; // zf
  _DWORD **v3; // x0
  __int64 result; // x0

  if ( a1 )
    v2 = a2 == 0LL;
  else
    v2 = 1;
  if ( v2 )
    return 0xFFFFFFFFLL;
  v3 = *(_DWORD ***)(a1 + 40);
  if ( !v3 || (result = HAL_clk_IsPowerDomainOn(v3), (_DWORD)result) )
  {
    *a2 = 1;
    return 0LL;
  }
  else
  {
    *a2 = 0;
  }
  return result;
}



__int64 Clock_RPMRequest()
{
  return 0LL;
}



__int64 __fastcall Clock_SetClockFrequency(__int64 a1, int a2, unsigned int *a3)
{
  unsigned int v3; // w1
  __int64 v4; // x19
  __int64 result; // x0
  __int64 v6; // x20
  unsigned int v7; // w3
  __int64 v8; // x21
  unsigned int v9; // w0
  unsigned int v10; // w1
  unsigned int v11; // w0
  unsigned int v12; // w1
  __int64 v13; // x0
  bool v14; // zf
  int v15; // w0

  v3 = 1000 * a2;
  if ( !a1 )
    return 0xFFFFFFFFLL;
  v4 = *(_QWORD *)(a1 + 32);
  result = 0xFFFFFFFFLL;
  if ( v4 )
  {
    v6 = *(_QWORD *)(v4 + 24);
    if ( v6 )
    {
      while ( 1 )
      {
        v7 = *(_DWORD *)v6;
        if ( !*(_DWORD *)v6 )
          return 0xFFFFFFFFLL;
        if ( v3 <= v7 && ((*(_DWORD *)(v4 + 56) & 0x800000) == 0 || *(unsigned __int8 *)(v6 + 14) != 255) )
          break;
        v6 += 24LL;
      }
      result = 0xFFFFFFFFLL;
      if ( *(_DWORD *)(v6 + 4) <= 2u )
      {
        if ( a3 )
          *a3 = v7 / 0x3E8;
        result = 0LL;
        if ( v6 != *(_QWORD *)(v4 + 32) )
        {
          qtiseclib_cb_spin_lock(&ClockMutex);
          v8 = *(_QWORD *)((char *)ClockDrvCtxt[0] + (unsigned __int64)&loc_18) + 40LL * *(unsigned int *)(v6 + 4);
          if ( *(_DWORD *)(v4 + 48) )
          {
            v9 = *(_DWORD *)(v4 + 52);
            v10 = *(_DWORD *)(v6 + 16);
            if ( v10 > v9 )
              Clock_VoltageRequest(v9, v10);
            if ( v8 != *(_QWORD *)(v4 + 40) )
              Clock_EnableSource(v8);
          }
          if ( (*(_DWORD *)(v4 + 56) & 0x800000) == 0 )
            HAL_clk_ConfigClockMux((_DWORD *)v4, (unsigned int *)(v6 + 4));
          if ( *(_DWORD *)(v4 + 48) )
          {
            v11 = *(_DWORD *)(v4 + 52);
            v12 = *(_DWORD *)(v6 + 16);
            if ( v12 < v11 )
              Clock_VoltageRequest(v11, v12);
            v13 = *(_QWORD *)(v4 + 40);
            if ( v13 )
              v14 = v8 == v13;
            else
              v14 = 1;
            if ( !v14 )
              Clock_DisableSource(v13);
          }
          v15 = *(_DWORD *)(v6 + 16);
          *(_QWORD *)(v4 + 32) = v6;
          *(_QWORD *)(v4 + 40) = v8;
          *(_DWORD *)(v4 + 52) = v15;
          qtiseclib_cb_spin_unlock(&ClockMutex);
          return 0LL;
        }
      }
    }
  }
  return result;
}



__int64 __fastcall Clock_SetCXVoltage(int a1)
{
  int v1; // w22
  int v2; // w21
  int v3; // w20
  unsigned int v4; // w0

  v1 = aClockVRegMapping[a1];
  v2 = pwr_utils_hlvl(dword_1A530, v1, 0LL);
  v3 = pwr_utils_hlvl(dword_1A534, v1, 0LL);
  if ( v2 == -1 )
    qtisec_assert("noship_src/drivers/systemdrivers/clock/src/v1/ClockDriver.c", 0xF5u, "nCXHLVL != -1");
  if ( v3 == -1 )
    qtisec_assert("noship_src/drivers/systemdrivers/clock/src/v1/ClockDriver.c", 0xF6u, "nMXHLVL != -1");
  dword_1A548 = v2;
  dword_1A554 = v3;
  v4 = rpmh_issue_command_set(qword_1A528, dword_1A538);
  rpmh_barrier_single(qword_1A528, v4);
  return 0LL;
}



__int64 Clock_SetRPMAvailable()
{
  return 0LL;
}



__int64 Clock_TZInitDone()
{
  __int64 result; // x0

  result = Clock_PostInitImage();
  if ( (_DWORD)result )
    qtisec_assert(
      "noship_src/drivers/systemdrivers/clock/src/v1/ClockDriver.c",
      0x317u,
      "0 == Clock_PostInitImage(&ClockDrvCtxt)");
  return result;
}



__int64 __fastcall Clock_WriteRegRegion(__int64 result)
{
  unsigned int i; // w1
  __int64 v2; // x3
  int v3; // w4

  for ( i = 0; i < *(_DWORD *)(result + 8); ++i )
  {
    v2 = 4LL * (i & 0x3FFFFFFF);
    v3 = *(_DWORD *)(*(_QWORD *)result + 4LL * i);
    *(_DWORD *)(v2 + *(_QWORD *)(result + 16)) = v3;
  }
  return result;
}



