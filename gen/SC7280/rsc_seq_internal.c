/*0000000000000000 b $d
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
                 U g_rsc_count
                 U g_rscs
0000000000000000 T rsc_copy_cmd_seqs
0000000000000000 T rsc_enable_ts_events
0000000000000000 T rsc_get_count
0000000000000000 T rsc_get_handles
                 U rsc_hal_copy_extended_cmd_seq
                 U rsc_hal_copy_simple_cmd_seq
                 U rsc_hal_enable_ts_unit
                 U rsc_hal_get_delay_cntr_bitwidth
                 U rsc_hal_get_major_ver
                 U rsc_hal_get_minor_ver
                 U rsc_hal_get_num_drvs
                 U rsc_hal_get_num_seq_cmd_words
                 U rsc_hal_get_num_ts_events
                 U rsc_hal_get_parentchild_cfg
                 U rsc_hal_get_solver_cfg
                 U rsc_hal_get_step_ver
                 U rsc_hal_get_ts_unit_h
0000000000000000 T rsc_mode_index
0000000000000040 C rsc_params
0000000000000000 b rsc_params_count
0000000000000000 T rsc_read_id_info
0000000000000000 T rsc_read_internal_config
*/
#include "rsc_seq_internal.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall rsc_copy_cmd_seqs(__int64 a1)
{
  __int64 v2; // x23
  __int64 (__fastcall *v3)(__int64, unsigned __int16, __int64, unsigned int); // x20
  unsigned int i; // w21
  __int64 v5; // x1
  __int64 v6; // x22
  __int16 v7; // w0
  __int16 v8; // w1
  unsigned int v9; // w13
  __int64 v10; // x9
  __int64 v11; // x12
  __int64 v12; // x11
  unsigned __int16 v13; // w0
  unsigned int v14; // w10
  __int64 v15; // x15
  __int16 v16; // w14
  __int64 v17; // x11

  v2 = *(_QWORD *)(a1 + 40);
  if ( *(_BYTE *)(a1 + 1) == 8 )
    v3 = rsc_hal_copy_simple_cmd_seq;
  else
    v3 = rsc_hal_copy_extended_cmd_seq;
  for ( i = 0; ; ++i )
  {
    if ( i >= *(_DWORD *)(a1 + 16) )
    {
      v9 = 0;
      goto LABEL_15;
    }
    v5 = *(_QWORD *)(a1 + 8);
    v6 = v5 + 240LL * i;
    if ( *(_WORD *)(v6 + 8) )
      break;
LABEL_12:
    ;
  }
  v7 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v3)(
         v2,
         *(unsigned __int16 *)(a1 + 56),
         *(_QWORD *)(v5 + 240LL * i));
  if ( v7 )
  {
    v8 = *(_WORD *)(a1 + 56);
    if ( *(_BYTE *)(a1 + 1) == 8 )
      *(_WORD *)(v6 + 18) = v8;
    else
      *(_WORD *)(v6 + 18) = 2 * (v8 & 0x7FFF);
    *(_WORD *)(a1 + 56) = v7 + v8;
    goto LABEL_12;
  }
  v9 = 3;
LABEL_15:
  v10 = 0LL;
  v11 = 240LL * *(unsigned int *)(a1 + 16);
  while ( v11 != v10 )
  {
    v12 = *(_QWORD *)(a1 + 8) + v10;
    if ( *(_BYTE *)(v12 + 20) || !*(_WORD *)(v12 + 8) )
    {
      v13 = rsc_mode_index(a1, *(_BYTE *)(v12 + 21));
      *(_WORD *)(v17 + 18) = v16 + *(_WORD *)(v15 + v13 * (unsigned __int64)v14 + 18);
    }
    v10 += 240LL;
  }
  return v9;
}



__int64 __fastcall rsc_enable_ts_events(__int64 a1, char a2)
{
  int i; // w19

  for ( i = 0; i != 4; ++i )
  {
    rsc_hal_enable_ts_unit(*(_QWORD *)(a1 + 40), i, a2);
    if ( !*(_BYTE *)(a1 + 88) )
      rsc_hal_get_ts_unit_h(*(_QWORD *)(a1 + 40), i);
  }
  return 0LL;
}



__int64 __fastcall rsc_get_count(unsigned __int8 a1)
{
  int v1; // w4
  unsigned int v2; // w1
  __int64 result; // x0
  __int64 v4; // x6

  v1 = a1;
  v2 = 0;
  result = 0LL;
  while ( g_rsc_count > (unsigned __int64)v2 )
  {
    v4 = 96LL * v2++;
    if ( *(unsigned __int8 *)(g_rscs + v4) == v1 )
      result = (unsigned int)(result + 1);
    else
      result = (unsigned int)result;
  }
  return result;
}



__int64 __fastcall rsc_get_handles(char a1, int a2, __int64 a3)
{
  bool v3; // zf
  unsigned int v5; // w1
  unsigned __int64 v6; // x5
  _BYTE *v7; // x8
  __int64 result; // x0

  if ( a2 )
    v3 = a3 == 0;
  else
    v3 = 1;
  if ( v3 || a1 != 0 )
    return 0LL;
  v5 = 0;
  v6 = g_rsc_count;
  result = 0LL;
  while ( v6 > v5 )
  {
    v7 = (_BYTE *)(g_rscs + 96LL * v5);
    if ( !*v7 )
    {
      *(_QWORD *)(a3 + 8LL * (unsigned int)result) = v7;
      result = (unsigned int)(result + 1);
    }
    ++v5;
  }
  return result;
}



__int64 __fastcall rsc_mode_index(__int64 a1, unsigned __int8 a2)
{
  int v2; // w5
  __int64 v3; // x3
  unsigned int v4; // w2
  __int64 v5; // x4
  __int64 result; // x0
  __int64 v7; // x2
  int v8; // w3

  v2 = *(_DWORD *)(a1 + 16);
  v3 = 0LL;
  while ( 1 )
  {
    v4 = v3;
    if ( v3 == v2 )
      break;
    v5 = *(_QWORD *)(a1 + 8) + 240 * v3++;
    if ( *(_WORD *)(v5 + 16) == a2 )
      return v4;
  }
  v7 = *(_QWORD *)(a1 + 64);
  if ( v7 || (v8 = *(_DWORD *)(a1 + 72), result = 4LL, v8) )
  {
    result = 0LL;
    while ( (_DWORD)result != v2 )
    {
      if ( v7 && *(_WORD *)(v7 + 16) == a2 )
        return result;
      result = (unsigned int)(result + 1);
      v7 += 240LL;
    }
    return 4LL;
  }
  return result;
}



__int64 __fastcall rsc_read_id_info(__int64 a1)
{
  _BYTE *v2; // x20
  __int64 result; // x0

  v2 = *(_BYTE **)(a1 + 80);
  *v2 = rsc_hal_get_step_ver(*(_DWORD **)(a1 + 40));
  v2[1] = rsc_hal_get_minor_ver(*(_DWORD **)(a1 + 40));
  result = rsc_hal_get_major_ver(*(_DWORD **)(a1 + 40));
  v2[2] = result;
  return result;
}



__int64 __fastcall rsc_read_internal_config(__int64 result)
{
  unsigned __int16 v1; // w1
  __int64 v2; // x20
  __int64 v3; // x19

  v1 = rsc_params_count;
  if ( (unsigned __int16)rsc_params_count > 3u )
  {
    *(_QWORD *)(result + 80) = 0LL;
  }
  else
  {
    ++rsc_params_count;
    *(_QWORD *)(result + 80) = &rsc_params[16 * v1];
  }
  v2 = *(_QWORD *)(result + 80);
  if ( v2 )
  {
    v3 = result;
    *(_DWORD *)(v2 + 4) = rsc_hal_get_solver_cfg(*(_QWORD *)(result + 40));
    *(_DWORD *)(v2 + 12) = rsc_hal_get_parentchild_cfg(*(_QWORD *)(v3 + 40));
    *(_BYTE *)(v2 + 8) = rsc_hal_get_num_drvs(*(_QWORD *)(v3 + 40));
    *(_BYTE *)(v2 + 9) = rsc_hal_get_num_seq_cmd_words(*(_QWORD *)(v3 + 40));
    *(_BYTE *)(v2 + 10) = rsc_hal_get_num_ts_events(*(_QWORD *)(v3 + 40));
    result = rsc_hal_get_delay_cntr_bitwidth(*(_QWORD *)(v3 + 40));
    *(_BYTE *)(v2 + 11) = result;
  }
  return result;
}



