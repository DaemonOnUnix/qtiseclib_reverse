/*0000000000000000 t $x
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
                 U cmdq_finish_cmd
                 U DRV_CONFIG_DATA
0000000000000000 T drv_valid
0000000000000000 t get_finished_amc
0000000000000000 T get_finished_drv
0000000000000018 C g_msg
0000000000000100 C g_msg_body
0000000000000000 T is_amc_finished
0000000000000000 T is_amc_free
0000000000000000 T is_tcs_stuck
0000000000000000 T lookup_drv_index
                 U qtiseclib_cb_memset
                 U rpmh_clean_cmd
                 U rpmh_clz
                 U rpmh_core_verify
                 U rpmh_core_verify_ptr
                 U rpmh_get_timestamp
                 U rpmh_malloc
                 U rpmh_resource_command_val_at_rpmh
0000000000000008 C rpmh_tcs
                 U RscHalCheckAMCFinishedIRQ
                 U RscHalCheckTCSIdle_HLOS
                 U RscHalClearAMCFinishedIRQ
                 U RscHalConfigureCmdCompletion
                 U RscHalConvertAMCtoTCS
                 U RscHalConvertTCStoAMC
                 U RscHalEnableAMCFinishedIRQ
                 U RscHalIsTCSIdle
                 U RscHalReadConfig
                 U RscHalRegisterDrv
                 U RscHalSetupTCS
                 U RscHalToggleePCBTimeOut
                 U RscHalToggleTCSCmd
                 U RscHalTriggerTCS
                 U RscHalUpdateePCBTimeOutThreshold
0000000000000000 T tcs_check_idle_HLOS
0000000000000000 T tcs_clean_sleep_wake
0000000000000000 t tcs_clean_up
0000000000000000 T tcs_finish_active_amc
0000000000000000 T tcs_finish_amc
0000000000000000 T tcs_init
0000000000000008 C tcs_mode
0000000000000000 T tcs_prepare_sleep_add_cmd_set
0000000000000000 T tcs_prepare_sleep_commit
0000000000000000 T tcs_send
0000000000000000 t tcs_send_internal
0000000000000000 T tcs_size
0000000000000000 T tcs_slots_available
0000000000000000 T tcs_update_mode
*/
#include "rpmh_tcs.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall drv_valid(int a1)
{
  __int64 i; // x1
  int v2; // w4

  for ( i = 0LL; i != 48; i += 48LL )
  {
    v2 = *(_DWORD *)((char *)&_compound_literal_1_2 + i);
    if ( v2 == a1 )
      return 1LL;
  }
  return 0LL;
}



__int64 __fastcall get_finished_drv(int a1)
{
  unsigned int v2; // w19
  __int64 v3; // x0
  int v5; // w0
  __int64 v6; // x2
  unsigned int *v7; // x19
  _QWORD *v8; // x1
  int v9; // w3
  bool v10; // cc
  int v11; // [xsp+3Ch] [xbp+3Ch] BYREF

  v2 = lookup_drv_index(a1);
  v3 = (unsigned int)RscHalCheckAMCFinishedIRQ(*((_DWORD *)&_compound_literal_1_2 + 12 * v2 + 1), &v11) == 0;
  rpmh_core_verify(v3);
  if ( v11 )
  {
    v5 = 31 - rpmh_clz(v11);
    v6 = 0LL;
    v7 = (unsigned int *)(tcs_mode + 4LL * v2);
    while ( v6 != 48 )
    {
      v8 = (_QWORD *)((char *)&_compound_literal_1_2 + v6);
      v9 = v5 - *(_DWORD *)((char *)&_compound_literal_1_2 + v6 + 20);
      v10 = *(_DWORD *)((char *)&_compound_literal_1_2 + v6 + 4) != a1 || v9 < 0;
      if ( !v10 && (unsigned int)v9 < **(_DWORD **)(v8[5] + 8LL * *v7) )
        return *(unsigned int *)v8;
      v6 += 48LL;
    }
  }
  return 0x3FFFFFFFLL;
}



bool __fastcall is_amc_finished(int a1)
{
  unsigned int v1; // w0
  __int64 v2; // x0
  int v4; // [xsp+1Ch] [xbp+1Ch] BYREF

  v1 = lookup_drv_index(a1);
  v2 = (unsigned int)RscHalCheckAMCFinishedIRQ(*((_DWORD *)&_compound_literal_1_2 + 12 * v1 + 1), &v4) == 0;
  rpmh_core_verify(v2);
  return v4 != 0;
}



__int64 __fastcall is_amc_free(int a1)
{
  __int64 v1; // x19
  __int64 v2; // x21
  char *v3; // x20
  _QWORD *v4; // x19
  __int64 i; // x0
  __int64 v6; // x2

  v1 = (unsigned int)lookup_drv_index(a1);
  v2 = 4 * v1;
  v3 = (char *)&_compound_literal_1_2 + 48 * v1;
  rpmh_core_verify(**(_DWORD **)(*((_QWORD *)v3 + 5) + 8LL * *(unsigned int *)(tcs_mode + 4 * v1)) != 0);
  v4 = (_QWORD *)(rpmh_tcs + 8 * v1);
  for ( i = 0LL; i != 24LL * **(unsigned int **)(*((_QWORD *)v3 + 5) + 8LL * *(unsigned int *)(tcs_mode + v2)); i += 24LL )
  {
    v6 = *v4 + i;
    if ( !*(_DWORD *)(v6 + 4) )
      return 1LL;
  }
  return 0LL;
}



__int64 __fastcall is_tcs_stuck(int a1)
{
  __int64 v1; // x19
  unsigned int v2; // w22
  unsigned int v3; // w0
  char *v4; // x20
  __int64 v5; // x23
  __int64 v6; // x21
  __int64 v7; // x0
  char v9; // [xsp+6Fh] [xbp+6Fh] BYREF

  v1 = 0LL;
  v2 = 0;
  v3 = lookup_drv_index(a1);
  v4 = (char *)&_compound_literal_1_2 + 48 * v3;
  v5 = 4LL * v3;
  v6 = 8LL * v3;
  while ( **(_DWORD **)(*((_QWORD *)v4 + 5) + 8LL * *(unsigned int *)(tcs_mode + v5)) > (unsigned int)v1 )
  {
    v7 = (unsigned int)RscHalIsTCSIdle(*((_DWORD *)v4 + 1), v4[20] + (unsigned __int8)v1, &v9) == 0;
    rpmh_core_verify(v7);
    if ( !v9
      && rpmh_get_timestamp() > (unsigned __int64)(*(_QWORD *)(*(_QWORD *)(rpmh_tcs + v6) + 24 * v1 + 8) + 192000LL) )
    {
      v2 = 1;
      rpmh_core_verify(1LL);
    }
    ++v1;
  }
  return v2;
}



__int64 __fastcall lookup_drv_index(int a1)
{
  __int64 v1; // x1
  unsigned int v2; // w2
  __int64 v3; // x6

  v1 = 0LL;
  while ( 1 )
  {
    v2 = v1;
    if ( v1 == 1 )
      break;
    v3 = 48 * v1++;
    if ( *(_DWORD *)((char *)&_compound_literal_1_2 + v3) == a1 )
      return v2;
  }
  rpmh_core_verify(0LL);
  return 0xFFFFFFFFLL;
}




__int64 __fastcall tcs_clean_sleep_wake(int a1)
{
  unsigned int v1; // w0
  char *v2; // x19
  __int64 v3; // x22
  unsigned int v4; // w20
  __int64 i; // x21
  __int64 result; // x0
  __int64 v7; // x23
  __int64 v8; // x0
  unsigned __int8 v9; // w1
  __int64 v10; // x0

  v1 = lookup_drv_index(a1);
  v2 = (char *)&_compound_literal_1_2 + 48 * v1;
  v3 = 8LL * v1;
  v4 = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v2 + 5) + 8LL * *(unsigned int *)(tcs_mode + 4LL * v1)) + 8LL);
  for ( i = 24LL * (int)v4; ; i += 24LL )
  {
    result = *((unsigned int *)v2 + 6);
    if ( (unsigned int)result <= v4 )
      break;
    v7 = *(_QWORD *)(rpmh_tcs + v3) + i;
    v8 = *(_QWORD *)(v7 + 16);
    if ( v8 )
    {
      if ( *(_DWORD *)(v8 + 8) )
      {
        rpmh_core_verify((unsigned int)(*(_DWORD *)(v8 + 28) - 1) <= 1);
        rpmh_clean_cmd(*(_QWORD **)(v7 + 16), *((_DWORD *)v2 + 7));
      }
    }
    v9 = v4++;
    v10 = (unsigned int)RscHalToggleTCSCmd(*((_DWORD *)v2 + 1), v9, 0) == 0;
    rpmh_core_verify(v10);
  }
  return result;
}



__int64 __fastcall tcs_finish_active_amc(_QWORD *a1, __int64 a2, int a3)
{
  __int64 finished_amc; // x0
  __int64 v7; // x19
  unsigned __int8 *v8; // x20
  __int64 v9; // x0

  finished_amc = get_finished_amc(a3);
  if ( !finished_amc )
    return 0LL;
  v7 = *(_QWORD *)(finished_amc + 16);
  v8 = (unsigned __int8 *)finished_amc;
  rpmh_core_verify_ptr(v7);
  v9 = *(_QWORD *)(v7 + 16);
  LODWORD(v7) = *(_DWORD *)(v7 + 24);
  *a1 = v9;
  tcs_clean_up(a2, v8, a3, 0);
  return (unsigned int)v7;
}



__int64 __fastcall tcs_finish_amc(__int64 a1, int a2, int a3)
{
  __int64 result; // x0
  unsigned __int8 *v7; // x19

  result = get_finished_amc(a2);
  if ( result )
  {
    v7 = (unsigned __int8 *)result;
    rpmh_core_verify_ptr(*(_QWORD *)(result + 16));
    return tcs_clean_up(a1, v7, a2, a3);
  }
  return result;
}



__int64 tcs_init()
{
  __int64 v0; // x20
  __int64 result; // x0
  char *v2; // x22
  unsigned int v3; // w23
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // [xsp+70h] [xbp+70h]
  unsigned int v7; // [xsp+88h] [xbp+88h] BYREF
  unsigned int v8; // [xsp+8Ch] [xbp+8Ch] BYREF

  v0 = 0LL;
  v8 = 0;
  v7 = 0;
  rpmh_tcs = rpmh_malloc(8u);
  rpmh_core_verify_ptr(rpmh_tcs);
  qtiseclib_cb_memset(rpmh_tcs, 0LL, 8LL);
  tcs_mode = rpmh_malloc(4u);
  rpmh_core_verify_ptr(tcs_mode);
  qtiseclib_cb_memset(rpmh_tcs, 0LL, 4LL);
  while ( 1 )
  {
    result = 1LL;
    if ( (_DWORD)v0 )
      break;
    v2 = (char *)&_compound_literal_1_2 + 48 * v0;
    *(_DWORD *)(tcs_mode + 4 * v0) = 0;
    v3 = ***((_DWORD ***)v2 + 5);
    if ( *(_DWORD *)v2 <= 0x3FFFFEFFu )
    {
      v4 = (unsigned int)RscHalRegisterDrv(*(_DWORD *)v2) == 0;
      rpmh_core_verify(v4);
      v5 = (unsigned int)RscHalReadConfig(*((_DWORD *)&_compound_literal_1_2 + 12 * v0), &v7, &v8) == 0;
      rpmh_core_verify(v5);
      rpmh_core_verify(*((_DWORD *)v2 + 6) <= v7);
      rpmh_core_verify(*((_DWORD *)v2 + 7) <= v8);
      rpmh_core_verify(v3 <= v7);
      RscHalUpdateePCBTimeOutThreshold(*((_DWORD *)&_compound_literal_1_2 + 12 * v0), 0xFFFFu);
      RscHalToggleePCBTimeOut(*((_DWORD *)&_compound_literal_1_2 + 12 * v0), 1);
    }
    v6 = rpmh_tcs;
    *(_QWORD *)(v6 + 8 * v0) = rpmh_malloc(24 * *((_DWORD *)v2 + 6));
    rpmh_core_verify_ptr(*(_QWORD *)(rpmh_tcs + 8 * v0));
    qtiseclib_cb_memset(*(_QWORD *)(rpmh_tcs + 8 * v0), 0LL, 24LL * *((unsigned int *)v2 + 6));
    rpmh_core_verify(*((_DWORD *)v2 + 7) == 16);
    if ( v3 < v7 )
      rpmh_core_verify(v7 >= v3 + 2);
    ++v0;
    tcs_update_mode(0, 0);
  }
  return result;
}



__int64 __fastcall tcs_prepare_sleep_add_cmd_set(int *a1, int a2)
{
  unsigned int v4; // w19
  int v5; // w0
  char *v6; // x21
  __int64 v7; // x19
  __int64 v8; // x0
  unsigned __int64 *v9; // x22
  unsigned __int64 v10; // x0
  __int64 v11; // x2
  int v12; // w5
  int v13; // w2
  __int64 v14; // x1
  int v15; // w0
  __int64 v16; // x0
  int *v17; // x3
  _DWORD *v18; // x7
  unsigned int v19; // w0
  int v20; // w3
  int v21; // w2

  v4 = lookup_drv_index(a2);
  v5 = tcs_slots_available(a2, *a1, a1[1]);
  if ( v5 == -1 )
    return 0LL;
  v6 = (char *)&_compound_literal_1_2 + 48 * v4;
  v7 = *(_QWORD *)(rpmh_tcs + 8LL * v4) + 24LL * v5;
  rpmh_core_verify_ptr(v7);
  rpmh_core_verify(*(_DWORD *)(v7 + 4) == 3);
  if ( !*(_QWORD *)(v7 + 16) )
  {
    v8 = rpmh_malloc(0x30u);
    *(_QWORD *)(v7 + 16) = v8;
    rpmh_core_verify_ptr(v8);
    qtiseclib_cb_memset(*(_QWORD *)(v7 + 16), 0LL, 48LL);
    v9 = *(unsigned __int64 **)(v7 + 16);
    v10 = rpmh_malloc(8 * *((_DWORD *)v6 + 7));
    v11 = *((unsigned int *)v6 + 7);
    *v9 = v10;
    qtiseclib_cb_memset(**(_QWORD **)(v7 + 16), 0LL, 8 * v11);
  }
  v12 = a1[1];
  v13 = 0;
  v14 = *(_QWORD *)(v7 + 16);
  while ( 1 )
  {
    v15 = *(_DWORD *)(v14 + 8);
    if ( v13 == v12 )
      break;
    v16 = (unsigned int)(v13 + v15);
    v17 = &a1[3 * v13++];
    v18 = (_DWORD *)(*(_QWORD *)v14 + 8 * v16);
    *v18 = v17[3];
    v18[1] = *((unsigned __int8 *)v17 + 20);
  }
  v19 = v13 + v15;
  v20 = *a1;
  v21 = a1[2];
  *(_BYTE *)(v14 + 32) = 0;
  *(_DWORD *)(v14 + 8) = v19;
  *(_DWORD *)(v14 + 12) = v21;
  *(_DWORD *)(v14 + 28) = v20;
  rpmh_core_verify(v19 <= *((_DWORD *)v6 + 7));
  return 1LL;
}



__int64 __fastcall tcs_prepare_sleep_commit(int a1)
{
  unsigned int v2; // w0
  char *v3; // x22
  __int64 v4; // x19
  unsigned int v5; // w20
  __int64 i; // x21
  __int64 result; // x0
  __int64 v8; // x0

  v2 = lookup_drv_index(a1);
  v3 = (char *)&_compound_literal_1_2 + 48 * v2;
  v4 = 8LL * v2;
  v5 = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v3 + 5) + 8LL * *(unsigned int *)(tcs_mode + 4LL * v2)) + 8LL);
  for ( i = 24LL * (int)v5; ; i += 24LL )
  {
    result = *((unsigned int *)v3 + 6);
    if ( (unsigned int)result <= v5 )
      break;
    v8 = *(_QWORD *)(*(_QWORD *)(rpmh_tcs + v4) + i + 16);
    if ( v8 )
    {
      if ( *(_DWORD *)(v8 + 8) )
        tcs_send_internal(v8, a1, v5);
    }
    ++v5;
  }
  return result;
}



  if ( v6 && (v9 = tcs_send(v4, **(_DWORD **)(v4 + 16)), (v3 = v9) != 0) )
  {
    inq_it_delete(v11);
    inq_append(*(unsigned int **)(a1 + 8), v4);
  }
  else
  {
    return 0;
  }
  return v3;
}



__int64 __fastcall tcs_size(int a1)
{
  return *((unsigned int *)&_compound_literal_1_2 + 12 * (unsigned int)lookup_drv_index(a1) + 7);
}



__int64 __fastcall tcs_slots_available(int a1, int a2, unsigned int a3)
{
  unsigned int v5; // w20
  char *v6; // x19
  unsigned int v7; // w2
  __int64 result; // x0
  __int64 v9; // x1
  _QWORD *v10; // x20
  __int64 v11; // x1
  __int64 v12; // x4

  v5 = lookup_drv_index(a1);
  v6 = (char *)&_compound_literal_1_2 + 48 * v5;
  rpmh_core_verify(*((_DWORD *)v6 + 7) >= a3);
  if ( a2 == 1 )
  {
    v9 = *(_QWORD *)(*((_QWORD *)v6 + 5) + 8LL * *(unsigned int *)(tcs_mode + 4LL * v5));
    v7 = *(_DWORD *)(v9 + 4);
    result = *(unsigned int *)(v9 + 8);
  }
  else if ( a2 == 2 )
  {
    v7 = *((_DWORD *)v6 + 6);
    result = *(unsigned int *)(*(_QWORD *)(*((_QWORD *)v6 + 5) + 8LL * *(unsigned int *)(tcs_mode + 4LL * v5)) + 4LL);
  }
  else
  {
    rpmh_core_verify(0LL);
    v7 = 0;
    result = 0LL;
  }
  v10 = (_QWORD *)(rpmh_tcs + 8LL * v5);
  v11 = 24LL * (int)result;
  while ( v7 > (unsigned int)result )
  {
    v12 = *(_QWORD *)(*v10 + v11 + 16);
    if ( !v12 )
      return result;
    v11 += 24LL;
    if ( a3 <= *((_DWORD *)v6 + 7) - *(_DWORD *)(v12 + 8) )
      return result;
    result = (unsigned int)(result + 1);
  }
  return 0xFFFFFFFFLL;
}



__int64 __fastcall tcs_update_mode(unsigned int a1, unsigned int a2)
{
  __int64 v2; // x20
  __int64 v4; // x22
  char *v5; // x19
  __int64 v6; // x21
  __int64 i; // x20
  __int64 result; // x0
  __int64 v9; // x27
  unsigned int v10; // w1
  __int64 v11; // x28
  __int64 v12; // x0
  unsigned int v13; // w0
  unsigned int v14; // w0
  int v15; // w0
  unsigned int v16; // w0

  v2 = a1;
  v4 = 8LL * a1;
  v5 = (char *)&_compound_literal_1_2 + 48 * a1;
  rpmh_core_verify(*((_DWORD *)v5 + 8) > a2);
  *(_DWORD *)(tcs_mode + 4 * v2) = a2;
  v6 = 8LL * a2;
  for ( i = 0LL; ; ++i )
  {
    result = *((unsigned int *)v5 + 6);
    if ( (unsigned int)result <= (unsigned int)i )
      break;
    v9 = *(_QWORD *)(rpmh_tcs + v4);
    v10 = (unsigned __int8)(*((_DWORD *)v5 + 5) + i);
    v11 = v9 + 24 * i;
    *(_BYTE *)v11 = v10;
    v12 = (unsigned int)RscHalClearAMCFinishedIRQ(*((_DWORD *)v5 + 1), v10) == 0;
    rpmh_core_verify(v12);
    v13 = **(_DWORD **)(*((_QWORD *)v5 + 5) + v6);
    *(_QWORD *)(v11 + 8) = 0LL;
    if ( (unsigned int)i >= v13 )
    {
      v16 = *((_DWORD *)v5 + 1);
      *(_DWORD *)(v11 + 4) = 3;
      v15 = RscHalConvertAMCtoTCS(v16, *(_BYTE *)(v9 + 24 * i));
    }
    else
    {
      v14 = *((_DWORD *)v5 + 1);
      *(_DWORD *)(v11 + 4) = 0;
      v15 = RscHalConvertTCStoAMC(v14, *(_BYTE *)(v9 + 24 * i));
    }
    rpmh_core_verify(v15 == 0);
  }
  return result;
}



