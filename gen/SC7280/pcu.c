/*0000000000000000 b $d
0000000000000000 d $d
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 b cmd_word_count.1139
                 U get_max_cmd_size
                 U g_pcu_count
0000000000000008 C hmss_pcu_seq_memory
0000000000000004 C max_cmd_size
0000000000000000 T pcu_config_low_power_mode
                 U pcu_config_seq_ctl
0000000000000000 T pcu_get_node
0000000000000000 T pcu_init
0000000000000000 T pcu_node_init
0000000000000000 T pcu_seq_memory_init
0000000000000000 D pcu_sequencer
                 U pcu_sequencer_target_init
                 U pcu_write_cmds
0000000000000000 T pcu_write_seq_memory
                 U target_pcu_node
*/
#include "pcu.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall pcu_config_low_power_mode(__int64 *a1, int a2)
{
  __int64 v2; // x3
  __int64 i; // x2

  v2 = a1[4];
  for ( i = 0LL; v2 != i && *(_DWORD *)(a1[3] + 48 * i) != a2; ++i )
    ;
  if ( a2 >= 0 && v2 == i )
    return 5LL;
  pcu_config_seq_ctl(
    a1[1],
    *(unsigned __int8 *)(a1[3] + 48 * i + 28),
    *(_DWORD *)(a1[3] + 48 * i + 40),
    *(unsigned __int8 *)(a1[3] + 48 * i + 29));
  return 0LL;
}



__int64 __fastcall pcu_get_node(int a1, _QWORD *a2)
{
  if ( (unsigned __int64)a1 >= 0xD )
    return 1LL;
  *a2 = &(&target_pcu_node)[5 * a1];
  return 0LL;
}



__int64 pcu_init()
{
  pcu_sequencer_target_init();
  return pcu_seq_memory_init();
}



__int64 __fastcall pcu_node_init(__int64 a1)
{
  void (*v1)(void); // x0

  v1 = *(void (**)(void))(a1 + 16);
  if ( v1 )
    v1();
  return 0LL;
}



__int64 pcu_seq_memory_init()
{
  unsigned __int64 v0; // x19
  char **v1; // x0
  __int64 result; // x0

  v0 = 0LL;
  while ( v0 < 0xD )
  {
    v1 = &(&target_pcu_node)[5 * v0++];
    result = pcu_write_seq_memory((__int64)v1, 1);
    if ( (_DWORD)result )
      return result;
  }
  return 0LL;
}



__int64 __fastcall pcu_write_seq_memory(__int64 a1, int a2)
{
  __int64 v4; // x23
  int max_cmd_size; // w0
  __int64 v6; // x20
  __int64 v7; // x5
  __int64 v8; // x19
  unsigned __int64 v9; // x22
  unsigned __int64 v10; // x21
  __int64 v11; // x4
  unsigned __int64 v12; // x2
  int v13; // w0
  int v14; // w1
  __int64 v16; // [xsp+68h] [xbp+68h]

  v4 = *(_QWORD *)(a1 + 32);
  max_cmd_size = get_max_cmd_size();
  v6 = 0LL;
  v7 = 48LL;
  ::max_cmd_size = max_cmd_size;
  while ( 1 )
  {
    if ( v6 == v4 )
      return 0LL;
    v8 = *(_QWORD *)(a1 + 24) + v6 * v7;
    if ( !*(_BYTE *)(v8 + 44) )
      break;
LABEL_18:
    ++v6;
  }
  if ( *(_DWORD *)(v8 + 24) )
  {
    if ( !(_DWORD)v6 )
      return 1LL;
    *(_DWORD *)(v8 + 40) = *(_DWORD *)(v8 - 8);
    goto LABEL_16;
  }
  if ( !*(_QWORD *)(v8 + 8) )
    goto LABEL_18;
  v9 = *(_QWORD *)(v8 + 16);
  if ( v9 + (unsigned int)cmd_word_count_1139 < ::max_cmd_size )
  {
    v10 = 0LL;
    *(_DWORD *)(v8 + 40) = cmd_word_count_1139;
    while ( v9 > v10 )
    {
      v11 = *(_QWORD *)(v8 + 8);
      v12 = v10 + 1;
      v13 = 8;
      v14 = *(unsigned __int8 *)(v11 + v10);
      do
      {
        if ( v12 < v9 )
          v14 |= *(unsigned __int8 *)(v11 + v12) << v13;
        v13 += 8;
        ++v12;
      }
      while ( v13 != 32 );
      v10 += 4LL;
      v16 = v7;
      pcu_write_cmds((unsigned int)cmd_word_count_1139 >> 2, v14);
      v7 = v16;
      cmd_word_count_1139 += 4;
    }
LABEL_16:
    if ( a2 )
      *(_BYTE *)(v8 + 44) = 1;
    goto LABEL_18;
  }
  return 3LL;
}



