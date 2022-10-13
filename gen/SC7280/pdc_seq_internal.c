/*0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
                 U g_pdc_seq_count
                 U g_pdc_seqs
0000000000000000 T pdc_seq_copy_cmd_seq
0000000000000000 T pdc_seq_count
                 U pdc_seq_hal_cfg_br_addr
                 U pdc_seq_hal_cfg_delay
                 U pdc_seq_hal_copy_cmd_seq
                 U pdc_seq_hal_profile_ts_count
0000000000000000 T pdc_seq_handle_internal_cfg
0000000000000000 T pdc_seq_handles
0000000000000000 T pdc_seq_mode_index
*/
#include "pdc_seq_internal.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall pdc_seq_copy_cmd_seq(__int64 a1)
{
  unsigned int v2; // w20
  __int64 v3; // x1
  __int64 v4; // x21
  __int64 v5; // x4
  int i; // w2
  __int64 v7; // x5
  __int16 v8; // w0
  __int16 v9; // w1

  v2 = 0;
LABEL_2:
  if ( (unsigned __int64)v2 >= *(_QWORD *)(a1 + 24) )
    return 0LL;
  v3 = *(_QWORD *)(a1 + 16);
  v4 = v3 + 32LL * v2;
  if ( !*(_WORD *)(v4 + 8) )
    return 4294967294LL;
  v5 = *(_QWORD *)(a1 + 16);
  for ( i = 0; v2 != i; ++i )
  {
    v7 = v5;
    v5 += 32LL;
    if ( *(_QWORD *)v7 == *(_QWORD *)v4 )
    {
      *(_WORD *)(v4 + 24) = *(_WORD *)(v7 + 24);
LABEL_11:
      ++v2;
      goto LABEL_2;
    }
  }
  v8 = pdc_seq_hal_copy_cmd_seq(
         *(_QWORD *)(a1 + 48),
         *(_WORD *)(a1 + 112),
         *(_QWORD *)(v3 + 32LL * v2),
         *(unsigned __int16 *)(v3 + 32LL * v2 + 8));
  if ( v8 )
  {
    v9 = *(_WORD *)(a1 + 112);
    *(_WORD *)(v4 + 24) = v9;
    *(_WORD *)(a1 + 112) = v8 + v9;
    goto LABEL_11;
  }
  return 4294967292LL;
}



__int64 __fastcall pdc_seq_count(unsigned __int8 a1)
{
  int v1; // w3
  unsigned __int8 *v2; // x1
  __int64 result; // x0
  int v4; // t1

  v1 = a1;
  v2 = (unsigned __int8 *)g_pdc_seqs;
  result = 0LL;
  while ( v2 != (unsigned __int8 *)(g_pdc_seqs + 120LL * (unsigned int)g_pdc_seq_count) )
  {
    v4 = *v2;
    v2 += 120;
    if ( v4 == v1 )
      result = (unsigned int)(result + 1);
    else
      result = (unsigned int)result;
  }
  return result;
}



__int64 __fastcall pdc_seq_handle_internal_cfg(__int64 a1)
{
  __int64 v1; // x21
  unsigned int i; // w19
  unsigned int j; // w19

  v1 = *(_QWORD *)(a1 + 8);
  for ( i = 0; i < *(_DWORD *)(v1 + 8); ++i )
  {
    if ( (unsigned int)pdc_seq_hal_cfg_br_addr(*(_QWORD *)(a1 + 48), i, *(_BYTE *)(*(_QWORD *)v1 + i)) )
      return 4294967294LL;
  }
  for ( j = 0; j < *(_DWORD *)(v1 + 24); ++j )
  {
    if ( (unsigned int)pdc_seq_hal_cfg_delay(*(_QWORD *)(a1 + 48), j, *(_DWORD *)(*(_QWORD *)(v1 + 16) + 4LL * j)) )
      return 4294967294LL;
  }
  if ( (unsigned int)pdc_seq_hal_profile_ts_count(*(_QWORD *)(a1 + 48)) != 5 )
    return 4294967294LL;
  return 0LL;
}



__int64 __fastcall pdc_seq_handles(unsigned __int8 a1, unsigned int a2, __int64 a3)
{
  int v3; // w5
  bool v4; // zf
  __int64 v6; // x3
  __int64 v7; // x4
  __int64 result; // x0

  v3 = a1;
  if ( a2 )
    v4 = a3 == 0;
  else
    v4 = 1;
  if ( v4 || a1 > 1u )
    return 0LL;
  v6 = 0LL;
  v7 = 120LL * (unsigned int)g_pdc_seq_count;
  result = 0LL;
  while ( v6 != v7 )
  {
    if ( *(unsigned __int8 *)(g_pdc_seqs + v6) == v3 )
    {
      if ( (unsigned int)result >= a2 )
        return result;
      *(_QWORD *)(a3 + 8LL * (unsigned int)result) = g_pdc_seqs + v6;
      result = (unsigned int)(result + 1);
    }
    v6 += 120LL;
  }
  return result;
}



__int64 __fastcall pdc_seq_mode_index(__int64 a1, unsigned __int16 a2)
{
  unsigned int i; // w2

  for ( i = 0; (unsigned __int64)i < *(_QWORD *)(a1 + 24); ++i )
  {
    if ( *(unsigned __int16 *)(*(_QWORD *)(a1 + 16) + 32LL * i + 10) == a2 )
      return i;
  }
  return 4294967293LL;
}



