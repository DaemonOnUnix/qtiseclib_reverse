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
0000000000000000 T pdc_seq_hal_cfg_br_addr
0000000000000000 T pdc_seq_hal_cfg_br_event_override
0000000000000000 T pdc_seq_hal_cfg_delay
0000000000000000 T pdc_seq_hal_cfg_pwr_ctl_override
0000000000000000 T pdc_seq_hal_cfg_start_addr
0000000000000000 T pdc_seq_hal_cfg_start_addr_ex
0000000000000000 T pdc_seq_hal_cfg_wait_event_override
0000000000000000 T pdc_seq_hal_cfg_wakeup_time
0000000000000000 T pdc_seq_hal_cfg_wakeup_time_ex
0000000000000000 T pdc_seq_hal_clk_gate_enable
0000000000000000 T pdc_seq_hal_copy_cmd_seq
0000000000000000 T pdc_seq_hal_enable
0000000000000000 T pdc_seq_hal_enable_arc_timer
0000000000000000 T pdc_seq_hal_enable_profile_ts
0000000000000000 T pdc_seq_hal_profile_ts
0000000000000000 T pdc_seq_hal_profile_ts_count
*/
#include "pdc_seq_hal.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall pdc_seq_hal_cfg_br_addr(__int64 a1, unsigned __int16 a2, unsigned __int8 a3)
{
  if ( a2 > 3u )
    return 0xFFFFFFFFLL;
  *(_DWORD *)(a1 + 4LL * a2 + 17760) = a3;
  return 0LL;
}



__int64 __fastcall pdc_seq_hal_cfg_br_event_override(__int64 a1, int a2, int a3)
{
  __int64 result; // x0

  result = a1 + 0x4000;
  *(_DWORD *)(result + 1360) = a2;
  *(_DWORD *)(result + 1364) = a3;
  return result;
}



__int64 __fastcall pdc_seq_hal_cfg_delay(__int64 a1, unsigned __int16 a2, int a3)
{
  if ( a2 > 0xFu )
    return 0xFFFFFFFFLL;
  *(_DWORD *)(a1 + 4LL * a2 + 17824) = a3;
  return 0LL;
}



__int64 __fastcall pdc_seq_hal_cfg_pwr_ctl_override(__int64 a1, int a2, int a3)
{
  __int64 result; // x0

  result = a1 + 0x4000;
  *(_DWORD *)(result + 1328) = a2;
  *(_DWORD *)(result + 1332) = a3;
  return result;
}



__int64 __fastcall pdc_seq_hal_cfg_start_addr(__int64 result, unsigned __int16 a2)
{
  *(_DWORD *)(result + 72) = a2 | 0x80000000;
  return result;
}



__int64 __fastcall pdc_seq_hal_cfg_start_addr_ex(__int64 a1, unsigned __int8 a2)
{
  __int64 result; // x0

  result = a1 + 0x4000;
  *(_DWORD *)(result + 1312) = a2;
  return result;
}



__int64 __fastcall pdc_seq_hal_cfg_wait_event_override(__int64 a1, int a2, int a3)
{
  __int64 result; // x0

  result = a1 + 0x4000;
  *(_DWORD *)(result + 1344) = a2;
  *(_DWORD *)(result + 1348) = a3;
  return result;
}



__int64 __fastcall pdc_seq_hal_cfg_wakeup_time(__int64 result, __int64 a2)
{
  *(_DWORD *)(result + 64) = a2;
  *(_DWORD *)(result + 56) = HIDWORD(a2) | 0x80000000;
  return result;
}



__int64 __fastcall pdc_seq_hal_cfg_wakeup_time_ex(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = a1 + 0x4000;
  *(_QWORD *)(result + 1296) = a2;
  return result;
}



__int64 __fastcall pdc_seq_hal_clk_gate_enable(__int64 a1, char a2)
{
  __int64 result; // x0

  result = a1 + 0x4000;
  *(_DWORD *)(result + 1280) = *(_DWORD *)(result + 1280) & 0x101 | ((a2 == 0) << 31);
  return result;
}



__int64 __fastcall pdc_seq_hal_copy_cmd_seq(__int64 a1, unsigned __int16 a2, __int64 a3, unsigned int a4)
{
  unsigned int v4; // w5
  unsigned int v5; // w4
  __int64 v6; // x8
  int v7; // w6
  int v8; // w10
  int v9; // w11
  char v10; // w7
  __int64 v11; // x5
  int v12; // w7
  int v13; // w9
  int v14; // w5
  __int64 v15; // x1

  a4 = (unsigned __int16)a4;
  v4 = 4 * (unsigned __int8)BYTE2(*(_DWORD *)(a1 + 4104));
  if ( v4 <= a2 )
    return 0;
  v5 = a2 + (unsigned __int16)a4;
  if ( v4 < v5 )
  {
    return 0;
  }
  else
  {
    v6 = 0LL;
    v7 = 0;
    v8 = 0;
    while ( (unsigned __int16)a4 > (unsigned int)(unsigned __int16)v6 )
    {
      v9 = ((_BYTE)a2 + (_BYTE)v6) & 3;
      v10 = 16;
      if ( v9 != 2 )
      {
        v10 = 24;
        if ( v9 != 3 )
        {
          v10 = 8;
          if ( v9 != 1 )
          {
            v10 = 0;
            if ( (_WORD)v6 )
            {
              v11 = 4 * (((unsigned __int16)(a2 + v6) - 1) / 4) + 0x200000LL;
              v12 = *(_DWORD *)(a1 + v11);
              v13 = v7 ^ v12;
              v7 = 0;
              *(_DWORD *)(a1 + v11) = v13 & v8 ^ v12;
              v10 = 0;
            }
          }
        }
      }
      v8 |= 255 << v10;
      v14 = *(unsigned __int8 *)(a3 + v6++);
      v7 |= v14 << v10;
    }
    v15 = 4 * (((unsigned __int16)v5 - 1) / 4) + 0x200000LL;
    *(_DWORD *)(a1 + v15) ^= (v7 ^ *(_DWORD *)(a1 + v15)) & v8;
  }
  return a4;
}



__int64 __fastcall pdc_seq_hal_enable(__int64 a1, char a2)
{
  __int64 result; // x0

  result = a1 + 0x4000;
  *(_DWORD *)(result + 1280) = *(_DWORD *)(result + 1280) & 0x80000100 | (a2 != 0);
  return result;
}



__int64 __fastcall pdc_seq_hal_enable_arc_timer(__int64 a1, char a2)
{
  __int64 result; // x0

  result = a1 + 0x4000;
  *(_DWORD *)(result + 1304) = a2 == 0;
  return result;
}



__int64 __fastcall pdc_seq_hal_enable_profile_ts(__int64 a1, unsigned __int8 a2, char a3)
{
  if ( a2 >= (unsigned int)((unsigned __int16)*(_DWORD *)(a1 + 4100) >> 12) )
    return 0xFFFFFFFFLL;
  *(_DWORD *)(a1 + 20LL * a2 + 20480) = a3 != 0;
  return 0LL;
}



unsigned __int64 __fastcall pdc_seq_hal_profile_ts(__int64 a1, unsigned __int8 a2)
{
  if ( a2 >= (unsigned int)((unsigned __int16)*(_DWORD *)(a1 + 4100) >> 12) )
    return 0LL;
  else
    return ((unsigned __int64)(*(_DWORD *)(a1 + 20LL * a2 + 4616) & 0xFFFFFF) << 32) | *(unsigned int *)(a1 + 20LL * a2 + 4612);
}



__int64 __fastcall pdc_seq_hal_profile_ts_count(__int64 a1)
{
  return (unsigned __int16)*(_DWORD *)(a1 + 4100) >> 12;
}



