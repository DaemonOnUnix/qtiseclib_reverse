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
                 U g_pdc_seq_count
                 U g_pdc_seqs
                 U pdc_seq_copy_cmd_seq
                 U pdc_seq_driver_init
0000000000000000 T pdc_seq_enable
0000000000000000 T pdc_seq_enable_arc_timer
0000000000000000 T pdc_seq_enable_profile_ts
                 U pdc_seq_hal_cfg_start_addr
                 U pdc_seq_hal_cfg_start_addr_ex
                 U pdc_seq_hal_cfg_wakeup_time
                 U pdc_seq_hal_cfg_wakeup_time_ex
                 U pdc_seq_hal_enable
                 U pdc_seq_hal_enable_arc_timer
                 U pdc_seq_hal_enable_profile_ts
                 U pdc_seq_hal_profile_ts
                 U pdc_seq_hal_profile_ts_count
                 U pdc_seq_handle_env_init
0000000000000000 T pdc_seq_handle_init
                 U pdc_seq_handle_internal_cfg
                 U pdc_seq_handles
                 U pdc_seq_handle_target_init
                 U pdc_seq_mode_index
0000000000000000 T pdc_seq_profile_ts
0000000000000000 T pdc_seq_profile_ts_count
0000000000000000 T pdc_seq_set_lpm
0000000000000000 T pdc_seq_set_wakeup_time
0000000000000000 T pdc_seq_sys_init
0000000000000000 T pdc_seq_test
*/
#include "pdc_seq.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall pdc_seq_enable(__int64 a1, char a2)
{
  __int64 v2; // x2
  __int64 result; // x0

  if ( !a1 )
    return 0xFFFFFFFFLL;
  v2 = *(_QWORD *)(a1 + 48);
  result = 0xFFFFFFFFLL;
  if ( v2 )
  {
    pdc_seq_hal_enable(v2, a2 != 0);
    return 0LL;
  }
  return result;
}



__int64 __fastcall pdc_seq_enable_arc_timer(__int64 a1, char a2)
{
  __int64 v2; // x2
  __int64 result; // x0

  if ( !a1 )
    return 0xFFFFFFFFLL;
  v2 = *(_QWORD *)(a1 + 48);
  result = 0xFFFFFFFFLL;
  if ( v2 )
  {
    pdc_seq_hal_enable_arc_timer(v2, a2 != 0);
    return 0LL;
  }
  return result;
}



__int64 __fastcall pdc_seq_enable_profile_ts(__int64 a1, unsigned __int8 a2)
{
  int v2; // w22
  unsigned int v3; // w1
  int v5; // w21
  int i; // w20
  unsigned __int8 v7; // w1

  if ( !a1 )
    return 0xFFFFFFFFLL;
  v2 = a2;
  v3 = -1;
  if ( *(_QWORD *)(a1 + 48) )
  {
    v5 = pdc_seq_profile_ts_count(a1);
    for ( i = 0; i != v5; ++i )
    {
      v7 = i;
      pdc_seq_hal_enable_profile_ts(*(_QWORD *)(a1 + 48), v7, v2 != 0);
    }
    return 0;
  }
  return v3;
}



__int64 __fastcall pdc_seq_handle_init(_QWORD *a1)
{
  __int64 result; // x0

  if ( !a1 || !a1[1] || !a1[2] || !a1[4] )
    return 0xFFFFFFFFLL;
  result = pdc_seq_handle_env_init(a1);
  if ( !(_DWORD)result )
  {
    result = pdc_seq_handle_target_init((__int64)a1);
    if ( !(_DWORD)result )
    {
      result = pdc_seq_handle_internal_cfg((__int64)a1);
      if ( !(_DWORD)result )
        return pdc_seq_copy_cmd_seq((__int64)a1);
    }
  }
  return result;
}



__int64 __fastcall pdc_seq_profile_ts(__int64 a1)
{
  unsigned __int64 *v1; // x22
  __int64 v3; // x20
  int v4; // w23
  int i; // w21
  unsigned __int8 v6; // w1

  if ( !a1 || !*(_QWORD *)(a1 + 48) )
    return 0LL;
  v1 = (unsigned __int64 *)(a1 + 64);
  v3 = a1 + 64;
  v4 = pdc_seq_profile_ts_count(a1);
  for ( i = 0; i != v4; ++i )
  {
    v6 = i;
    *v1++ = pdc_seq_hal_profile_ts(*(_QWORD *)(a1 + 48), v6);
  }
  return v3;
}



__int64 __fastcall pdc_seq_profile_ts_count(__int64 a1)
{
  __int64 v1; // x0

  if ( a1 && (v1 = *(_QWORD *)(a1 + 48)) != 0 )
    return pdc_seq_hal_profile_ts_count(v1);
  else
    return 0LL;
}



__int64 __fastcall pdc_seq_set_lpm(_QWORD *a1, unsigned __int16 a2)
{
  unsigned int v2; // w2
  signed int v4; // w0
  __int64 v5; // x1
  __int64 v6; // x0
  __int16 v7; // w1

  if ( !a1 )
    return 0xFFFFFFFFLL;
  v2 = -1;
  if ( a1[6] )
  {
    v4 = pdc_seq_mode_index((__int64)a1, a2);
    v2 = v4;
    if ( v4 != -3 )
    {
      v5 = a1[2] + 32LL * v4;
      v6 = a1[7];
      v7 = *(_WORD *)(v5 + 24);
      if ( v6 )
        pdc_seq_hal_cfg_start_addr(v6, v7);
      else
        pdc_seq_hal_cfg_start_addr_ex(a1[6], v7);
      return 0;
    }
  }
  return v2;
}



__int64 __fastcall pdc_seq_set_wakeup_time(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x0

  if ( !a1 )
    return 0xFFFFFFFFLL;
  result = 0xFFFFFFFFLL;
  if ( *(_QWORD *)(a1 + 48) )
  {
    v4 = *(_QWORD *)(a1 + 56);
    if ( v4 )
      pdc_seq_hal_cfg_wakeup_time(v4, a2);
    else
      pdc_seq_hal_cfg_wakeup_time_ex(*(_QWORD *)(a1 + 48), a2);
    return 0LL;
  }
  return result;
}



__int64 pdc_seq_sys_init()
{
  unsigned int v0; // w19
  __int64 result; // x0
  _QWORD *v2; // x20
  int v3; // w0
  int v4; // w0

  v0 = 0;
  pdc_seq_driver_init();
  while ( 1 )
  {
    result = (unsigned int)g_pdc_seq_count;
    if ( v0 >= g_pdc_seq_count )
      break;
    v2 = (_QWORD *)(g_pdc_seqs + 120LL * v0);
    v3 = pdc_seq_handle_init(v2);
    while ( v3 )
      ;
    v4 = pdc_seq_enable((__int64)v2, 1);
    while ( v4 )
      ;
    ++v0;
  }
  return result;
}



__int64 pdc_seq_test()
{
  int v0; // w19
  __int64 result; // x0
  _QWORD *v2; // [xsp+28h] [xbp+28h] BYREF

  pdc_seq_driver_init();
  pdc_seq_handles(0, 1u, (__int64)&v2);
  v0 = pdc_seq_handle_init(v2);
  pdc_seq_set_lpm(v2, 2u);
  result = pdc_seq_set_wakeup_time((__int64)v2, 0x123456789ABCDLL);
  if ( v0 )
  {
    while ( 1 )
      ;
  }
  return result;
}



