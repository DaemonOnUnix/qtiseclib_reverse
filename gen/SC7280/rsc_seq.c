/*0000000000000000 d $d
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 d initial_dynmode_id.1266
                 U qtisec_realloc
0000000000000000 T rsc_conf_hidden_tcs_ownership
                 U rsc_copy_cmd_seqs
0000000000000000 T rsc_driver_init
                 U rsc_enable_ts_events
0000000000000000 T rsc_get_time_stamp
                 U rsc_hal_conf_hidden_tcs_owner
                 U rsc_hal_config_br_addr
                 U rsc_hal_copy_extended_cmd_seq
                 U rsc_hal_copy_simple_cmd_seq
                 U rsc_hal_seq_busy
                 U rsc_hal_set_seq_override_start_addr
                 U rsc_hal_set_seq_override_start_addr_valid
                 U rsc_hal_set_trigger_seq
                 U rsc_hal_set_trigger_start_address
                 U rsc_init_base_address
0000000000000000 T rsc_instance_init
                 U rsc_mode_index
0000000000000000 T rsc_program_dyn_cmd_seq
                 U rsc_read_id_info
                 U rsc_read_internal_config
0000000000000000 T rsc_set_low_power_mode
                 U rsc_target_init
0000000000000000 T rsc_trigger_seq
0000000000000000 T rsc_ts_init
*/
#include "rsc_seq.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall rsc_conf_hidden_tcs_ownership(__int64 a1, char a2)
{
  __int64 v2; // x2
  __int64 result; // x0

  if ( !a1 )
    return 2LL;
  v2 = *(_QWORD *)(a1 + 40);
  result = 2LL;
  if ( v2 )
  {
    rsc_hal_conf_hidden_tcs_owner(v2, a2);
    return 0LL;
  }
  return result;
}




__int64 __fastcall rsc_get_time_stamp(__int64 a1, unsigned __int8 a2)
{
  unsigned int v3; // w0
  unsigned int v4; // w3
  __int64 v5; // x0

  if ( !a1 || !*(_QWORD *)(a1 + 40) || !*(_BYTE *)(a1 + 88) )
    return 2LL;
  v3 = rsc_mode_index(a1, a2);
  v4 = 4;
  if ( v3 != 4 )
  {
    v4 = -1;
    v5 = *(_QWORD *)(a1 + 8) + 240LL * v3;
    ++*(_WORD *)(v5 + 232);
  }
  return v4;
}



__int64 __fastcall rsc_instance_init(__int64 a1)
{
  unsigned int v2; // w20

  if ( (unsigned int)rsc_init_base_address(a1) )
    return 0xFFFFFFFFLL;
  rsc_read_internal_config(a1);
  rsc_read_id_info(a1);
  v2 = rsc_copy_cmd_seqs(a1);
  rsc_conf_hidden_tcs_ownership(a1, *(_BYTE *)(a1 + 32));
  return v2;
}



__int64 __fastcall rsc_program_dyn_cmd_seq(__int64 a1, __int64 a2, __int16 a3, _DWORD *a4)
{
  unsigned int v4; // w4
  __int64 (*v7)(void); // x4
  __int16 v10; // w24
  unsigned __int64 v11; // x0
  unsigned __int64 v12; // x2
  int v13; // w0
  __int16 v14; // w0

  if ( !a1 )
    return 1LL;
  v4 = 1;
  if ( *(_QWORD *)(a1 + 40) )
  {
    if ( *(_BYTE *)(a1 + 1) == 8 )
      v7 = (__int64 (*)(void))rsc_hal_copy_simple_cmd_seq;
    else
      v7 = (__int64 (*)(void))rsc_hal_copy_extended_cmd_seq;
    if ( (unsigned int)initial_dynmode_id_1266 <= 0xFF )
    {
      v10 = v7();
      v4 = 3;
      if ( v10 )
      {
        v11 = qtisec_realloc(*(_QWORD *)(a1 + 64), 240LL * (unsigned int)(*(_DWORD *)(a1 + 72) + 1));
        *(_QWORD *)(a1 + 64) = v11;
        v4 = -1;
        if ( v11 )
        {
          v12 = v11 + 240LL * *(unsigned int *)(a1 + 72);
          *(_QWORD *)v12 = a2;
          v13 = initial_dynmode_id_1266;
          *(_WORD *)(v12 + 8) = a3;
          *(_WORD *)(v12 + 16) = v13;
          initial_dynmode_id_1266 = v13 + 1;
          *a4 = (unsigned __int16)v13;
          *(_WORD *)(v12 + 232) = 0;
          v14 = *(_WORD *)(a1 + 56);
          if ( *(_BYTE *)(a1 + 1) == 8 )
            *(_WORD *)(v12 + 18) = v14;
          else
            *(_WORD *)(v12 + 18) = 2 * (v14 & 0x7FFF);
          v4 = 0;
          *(_WORD *)(a1 + 56) = v10 + v14;
          ++*(_DWORD *)(a1 + 72);
        }
      }
    }
    else
    {
      v4 = -1;
      *a4 = 255;
    }
  }
  return v4;
}



__int64 __fastcall rsc_set_low_power_mode(__int64 a1, unsigned __int8 a2)
{
  unsigned int v2; // w2
  unsigned int v4; // w0
  unsigned int v5; // w21
  __int64 v6; // x20
  unsigned __int16 v7; // w2

  if ( !a1 )
    return 1LL;
  v2 = 1;
  if ( *(_QWORD *)(a1 + 40) )
  {
    v4 = rsc_mode_index(a1, a2);
    v2 = 2;
    if ( v4 != 4 )
    {
      v5 = 0;
      v6 = *(_QWORD *)(a1 + 8) + 240LL * v4;
      if ( *(_QWORD *)(v6 + 24) )
      {
        while ( v5 < *(unsigned __int16 *)(v6 + 32) )
        {
          v7 = *(_WORD *)(*(_QWORD *)(v6 + 24) + 2LL * v5);
          if ( v7 )
            rsc_hal_config_br_addr(*(_QWORD *)(a1 + 40), v5, v7);
          ++v5;
        }
      }
      rsc_hal_set_seq_override_start_addr_valid(*(_QWORD *)(a1 + 40), 1);
      rsc_hal_set_seq_override_start_addr(*(_QWORD *)(a1 + 40), *(_BYTE *)(v6 + 18));
      return 0;
    }
  }
  return v2;
}



__int64 __fastcall rsc_trigger_seq(__int64 a1, unsigned __int8 a2)
{
  __int64 result; // x0
  __int64 v4; // x5
  __int64 v5; // x2
  unsigned int v6; // w4
  __int64 v7; // x4
  __int64 v8; // x19

  if ( !a1 )
    return 2LL;
  result = 2LL;
  v4 = *(_QWORD *)(a1 + 40);
  if ( v4 )
  {
    v5 = *(_QWORD *)(a1 + 64);
    v6 = *(_DWORD *)(a1 + 72);
    if ( v5 || v6 )
    {
      v7 = v5 + 240LL * v6;
      while ( v7 != v5 )
      {
        if ( v5 && *(_WORD *)(v5 + 16) == a2 )
        {
          v8 = a1;
          rsc_hal_set_trigger_start_address(v4, *(_WORD *)(v5 + 18));
          rsc_hal_set_trigger_seq(*(_QWORD *)(v8 + 40), 0);
          rsc_hal_set_trigger_seq(*(_QWORD *)(v8 + 40), 1u);
          do
            result = rsc_hal_seq_busy(*(_QWORD *)(v8 + 40));
          while ( (_DWORD)result );
          return result;
        }
        v5 += 240LL;
      }
      return 2LL;
    }
  }
  return result;
}



__int64 __fastcall rsc_ts_init(__int64 a1)
{
  unsigned int v2; // w2

  if ( !a1 || !*(_QWORD *)(a1 + 40) )
    return 1LL;
  v2 = rsc_enable_ts_events(a1, 1);
  if ( v2 )
  {
    *(_BYTE *)(a1 + 88) = 0;
    return (unsigned int)-1;
  }
  else
  {
    *(_BYTE *)(a1 + 88) = 1;
  }
  return v2;
}



