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
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 T rsc_hal_conf_hidden_tcs_owner
0000000000000000 T rsc_hal_config_br_addr
0000000000000000 T rsc_hal_copy_extended_cmd_seq
0000000000000000 T rsc_hal_copy_simple_cmd_seq
0000000000000000 T rsc_hal_enable_ts_unit
0000000000000000 T rsc_hal_get_delay_cntr_bitwidth
0000000000000000 T rsc_hal_get_major_ver
0000000000000000 T rsc_hal_get_minor_ver
0000000000000000 T rsc_hal_get_num_drvs
0000000000000000 T rsc_hal_get_num_seq_cmd_words
0000000000000000 T rsc_hal_get_num_ts_events
0000000000000000 T rsc_hal_get_parentchild_cfg
0000000000000000 T rsc_hal_get_seq_override_start_addr_valid
0000000000000000 T rsc_hal_get_seq_program_counter
0000000000000000 T rsc_hal_get_solver_cfg
0000000000000000 T rsc_hal_get_status0
0000000000000000 T rsc_hal_get_status1
0000000000000000 T rsc_hal_get_status2
0000000000000000 T rsc_hal_get_step_ver
0000000000000000 T rsc_hal_get_ts_overflow
0000000000000000 T rsc_hal_get_ts_unit_h
0000000000000000 T rsc_hal_get_ts_unit_l
0000000000000000 T rsc_hal_get_ts_valid
0000000000000004 C rsc_hal_read_back_val
0000000000000000 T rsc_hal_seq_busy
0000000000000000 T rsc_hal_set_seq_override_start_addr
0000000000000000 T rsc_hal_set_seq_override_start_addr_valid
0000000000000000 T rsc_hal_set_trigger_seq
0000000000000000 T rsc_hal_set_trigger_start_address
0000000000000000 T rsc_hal_set_ts_unit_owner
*/
#include "rsc_seq_hal.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall rsc_hal_conf_hidden_tcs_owner(__int64 result, char a2)
{
  *(_DWORD *)(result + 28) = *(_DWORD *)(result + 28) & 0x10000 | a2 & 3;
  return result;
}



__int64 __fastcall rsc_hal_config_br_addr(__int64 result, int a2, unsigned __int16 a3)
{
  *(_DWORD *)(result + 4LL * (a2 & 0x3FFFFFFF) + 1280) = a3;
  return result;
}



__int64 __fastcall rsc_hal_copy_extended_cmd_seq(__int64 a1, unsigned __int16 a2, __int64 a3, unsigned int a4)
{
  int v4; // w5
  int v5; // w4
  __int64 v6; // x8
  int v7; // w6
  int v8; // w7
  __int64 v9; // x5
  int v10; // w9
  int v11; // w6
  int v12; // w6
  char v13; // w9
  int v14; // w5
  int v15; // w5
  __int64 v16; // x1

  a4 = (unsigned __int16)a4;
  v4 = 2 * (unsigned __int8)BYTE2(*(_DWORD *)(a1 + 8));
  if ( a2 >= (unsigned int)v4 )
    return 0;
  v5 = a2 + (unsigned __int16)a4;
  if ( v5 > v4 )
  {
    return 0;
  }
  else
  {
    v6 = 0LL;
    v7 = 0;
    v8 = 0;
    while ( (unsigned __int16)a4 > (unsigned int)v6 )
    {
      if ( (((_BYTE)a2 + (_BYTE)v6) & 1) != 0 )
      {
        v13 = 16;
        v14 = -65536;
      }
      else if ( (_WORD)v6 )
      {
        v9 = 4 * (((unsigned __int16)(a2 + v6) - 1) / 2) + 1536LL;
        v10 = *(_DWORD *)(a1 + v9);
        v11 = (v7 ^ v10) & v8;
        v8 = 0;
        v12 = v11 ^ v10;
        v13 = 0;
        *(_DWORD *)(a1 + v9) = v12;
        v14 = 0xFFFF;
        v7 = 0;
      }
      else
      {
        v13 = 0;
        v14 = 0xFFFF;
      }
      v8 |= v14;
      v15 = *(unsigned __int16 *)(a3 + 2 * v6++);
      v7 |= v15 << v13;
    }
    v16 = 4 * (((unsigned __int16)v5 - 1) / 2) + 1536LL;
    *(_DWORD *)(a1 + v16) ^= (v7 ^ *(_DWORD *)(a1 + v16)) & v8;
  }
  return a4;
}



__int64 __fastcall rsc_hal_copy_simple_cmd_seq(__int64 a1, unsigned __int16 a2, __int64 a3, unsigned int a4)
{
  int v4; // w5
  int v5; // w4
  __int64 v6; // x7
  int v7; // w6
  int v8; // w10
  int v9; // w8
  __int64 v10; // x5
  int v11; // w8
  int v12; // w6
  int v13; // w8
  char v14; // w5
  int v15; // w8
  int v16; // w9
  __int64 v17; // x1

  a4 = (unsigned __int16)a4;
  v4 = 4 * (unsigned __int8)BYTE2(*(_DWORD *)(a1 + 8));
  if ( a2 >= (unsigned int)v4 )
    return 0;
  v5 = a2 + (unsigned __int16)a4;
  if ( v5 > v4 )
  {
    return 0;
  }
  else
  {
    v6 = 0LL;
    v7 = 0;
    v8 = 0;
    while ( (unsigned __int16)a4 > (unsigned int)v6 )
    {
      v9 = ((_BYTE)a2 + (_BYTE)v6) & 3;
      switch ( v9 )
      {
        case 2:
          v14 = 16;
          v15 = 16711680;
          break;
        case 3:
          v14 = 24;
          v15 = -16777216;
          break;
        case 1:
          v14 = 8;
          v15 = 65280;
          break;
        default:
          if ( (_WORD)v6 )
          {
            v10 = 4 * (((unsigned __int16)(a2 + v6) - 1) / 4) + 1536LL;
            v11 = *(_DWORD *)(a1 + v10);
            v12 = (v7 ^ v11) & v8;
            v8 = 0;
            v13 = v12 ^ v11;
            v7 = 0;
            *(_DWORD *)(a1 + v10) = v13;
          }
          v14 = 0;
          v15 = 255;
          break;
      }
      v16 = *(unsigned __int16 *)(a3 + 2 * v6);
      v8 |= v15;
      ++v6;
      v7 |= v16 << v14;
    }
    v17 = 4 * (((unsigned __int16)v5 - 1) / 4) + 1536LL;
    *(_DWORD *)(a1 + v17) ^= (v7 ^ *(_DWORD *)(a1 + v17)) & v8;
  }
  return a4;
}



__int64 __fastcall rsc_hal_enable_ts_unit(__int64 result, unsigned __int8 a2, char a3)
{
  *(_DWORD *)(result + 32LL * a2 + 516) = a3 & 1;
  return result;
}



__int64 __fastcall rsc_hal_get_delay_cntr_bitwidth(__int64 a1)
{
  return *(_DWORD *)(a1 + 8) & 0x1F;
}



__int64 __fastcall rsc_hal_get_major_ver(_DWORD *a1)
{
  return (unsigned __int8)BYTE2(*a1);
}



__int64 __fastcall rsc_hal_get_minor_ver(_DWORD *a1)
{
  return (unsigned __int8)BYTE1(*a1);
}



unsigned __int64 __fastcall rsc_hal_get_num_drvs(__int64 a1)
{
  return ((unsigned __int64)*(unsigned int *)(a1 + 8) >> 24) & 7;
}



__int64 __fastcall rsc_hal_get_num_seq_cmd_words(__int64 a1)
{
  return (unsigned __int8)BYTE2(*(_DWORD *)(a1 + 8));
}



unsigned __int64 __fastcall rsc_hal_get_num_ts_events(__int64 a1)
{
  return ((unsigned __int64)*(unsigned int *)(a1 + 8) >> 8) & 0xF;
}



__int64 __fastcall rsc_hal_get_parentchild_cfg(__int64 a1)
{
  return *(_DWORD *)(a1 + 12) & 0xF8FFFFFF;
}



__int64 __fastcall rsc_hal_get_seq_override_start_addr_valid(__int64 a1)
{
  return *(_DWORD *)(a1 + 1024) >> 31;
}



__int64 __fastcall rsc_hal_get_seq_program_counter(__int64 a1)
{
  return *(_DWORD *)(a1 + 1032) & 0x3FF;
}



__int64 __fastcall rsc_hal_get_solver_cfg(__int64 a1)
{
  return *(_DWORD *)(a1 + 4) & 0x71F1F1F;
}



__int64 __fastcall rsc_hal_get_status0(__int64 a1)
{
  return *(_DWORD *)(a1 + 16) & 0x101FFFF;
}



__int64 __fastcall rsc_hal_get_status1(__int64 a1)
{
  return *(unsigned int *)(a1 + 20);
}



__int64 __fastcall rsc_hal_get_status2(__int64 a1)
{
  return *(_DWORD *)(a1 + 24) & 0xFFFFFF;
}



__int64 __fastcall rsc_hal_get_step_ver(_DWORD *a1)
{
  return (unsigned __int8)*a1;
}



unsigned __int64 __fastcall rsc_hal_get_ts_overflow(__int64 a1, unsigned __int8 a2)
{
  return ((unsigned __int64)*(unsigned int *)(a1 + 32LL * a2 + 528) >> 8) & 1;
}



__int64 __fastcall rsc_hal_get_ts_unit_h(__int64 a1, unsigned __int8 a2)
{
  return *(_DWORD *)(a1 + 32LL * a2 + 524) & 0xFFFFFF;
}



__int64 __fastcall rsc_hal_get_ts_unit_l(__int64 a1, unsigned __int8 a2)
{
  return *(unsigned int *)(a1 + 32LL * a2 + 520);
}



__int64 __fastcall rsc_hal_get_ts_valid(__int64 a1, unsigned __int8 a2)
{
  return *(_DWORD *)(a1 + 32LL * a2 + 528) & 1;
}



__int64 __fastcall rsc_hal_seq_busy(__int64 a1)
{
  return *(_DWORD *)(a1 + 1028) & 1;
}



__int64 __fastcall rsc_hal_set_seq_override_start_addr(__int64 result, unsigned __int8 a2)
{
  *(_DWORD *)(result + 1024) = *(_DWORD *)(result + 1024) & 0x80000000 | a2;
  return result;
}



__int64 __fastcall rsc_hal_set_seq_override_start_addr_valid(__int64 result, int a2)
{
  *(_DWORD *)(result + 1024) = *(_DWORD *)(result + 1024) & 0x3FF | (a2 << 31);
  return result;
}



__int64 __fastcall rsc_hal_set_trigger_seq(__int64 result, unsigned __int8 a2)
{
  *(_DWORD *)(result + 1120) = a2;
  return result;
}



__int64 __fastcall rsc_hal_set_trigger_start_address(__int64 result, unsigned __int16 a2)
{
  *(_DWORD *)(result + 1124) = a2;
  return result;
}



__int64 __fastcall rsc_hal_set_ts_unit_owner(__int64 result, unsigned __int8 a2)
{
  *(_DWORD *)(result + 512) = a2;
  return result;
}



