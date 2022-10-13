/*0000000000000000 b $d
0000000000000000 b $d
0000000000000000 b $d
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
                 U cmd_db_query_addr
0000000000000000 T icbuarb_target_d4_entry
0000000000000000 T icbuarb_target_d4_exit
0000000000000000 T icbuarb_target_init
0000000000000000 T icbuarb_target_prio_override_disable
0000000000000000 T icbuarb_target_prio_override_enable
0000000000000000 T icbuarb_target_throttle_disable
0000000000000000 T icbuarb_target_throttle_enable
0000000000000000 b initialized
0000000000000000 b mm_node
                 U qtiseclib_cb_memset
                 U rpmh_barrier_single
                 U rpmh_create_handle_explicit
                 U rpmh_invalidate_explicit_cmds
                 U rpmh_issue_command_set
0000000000000000 b rpmh_wa_handle
*/
#include "icbuarb_target.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 icbuarb_target_d4_entry()
{
  __int64 result; // x0
  unsigned int v1; // w0
  unsigned int v2; // w22
  unsigned int v3[4]; // [xsp+30h] [xbp+30h] BYREF
  int v4; // [xsp+40h] [xbp+40h]
  char v5; // [xsp+44h] [xbp+44h]

  result = (unsigned __int8)initialized;
  if ( initialized )
  {
    result = *(unsigned int *)(mm_node + 40);
    if ( !(_DWORD)result )
    {
      qtiseclib_cb_memset(v3, 0LL, 204LL);
      v3[0] = 0;
      v3[1] = 1;
      v1 = *(_DWORD *)(mm_node + 20);
      v5 = 1;
      v3[3] = v1;
      v4 = 1610612737;
      v2 = rpmh_issue_command_set(rpmh_wa_handle, v3);
      v5 = 1;
      v3[0] = 2;
      v4 = 1610612737;
      rpmh_issue_command_set(rpmh_wa_handle, v3);
      v5 = 0;
      v3[0] = 1;
      v4 = 0x40000000;
      rpmh_issue_command_set(rpmh_wa_handle, v3);
      return rpmh_barrier_single(rpmh_wa_handle, v2);
    }
  }
  return result;
}



__int64 icbuarb_target_d4_exit()
{
  __int64 result; // x0
  unsigned int v1; // w0
  unsigned int v2[5]; // [xsp+20h] [xbp+20h] BYREF
  char v3; // [xsp+34h] [xbp+34h]

  result = (unsigned __int8)initialized;
  if ( initialized )
  {
    result = *(unsigned int *)(mm_node + 40);
    if ( !(_DWORD)result )
    {
      rpmh_invalidate_explicit_cmds(rpmh_wa_handle);
      qtiseclib_cb_memset(v2, 0LL, 204LL);
      v2[0] = 0;
      v2[1] = 1;
      v1 = *(_DWORD *)(mm_node + 20);
      v3 = 0;
      v2[3] = v1;
      v2[4] = 0x40000000;
      return rpmh_issue_command_set(rpmh_wa_handle, v2);
    }
  }
  return result;
}



__int64 __fastcall icbuarb_target_init(__int64 a1)
{
  int addr; // w0
  __int64 v3; // x2
  __int64 v4; // x1

  addr = cmd_db_query_addr((__int64)"MM1");
  v3 = 0LL;
  while ( v3 != 8LL * *(unsigned int *)(a1 + 48) )
  {
    v4 = *(_QWORD *)(*(_QWORD *)(a1 + 56) + v3);
    v3 += 8LL;
    if ( addr == *(_DWORD *)(v4 + 20) )
      goto LABEL_6;
  }
  v4 = 0LL;
LABEL_6:
  mm_node = v4;
  if ( v4 )
  {
    rpmh_wa_handle = rpmh_create_handle_explicit(0, (__int64)"ICB");
    if ( rpmh_wa_handle )
      initialized = 1;
  }
  return (unsigned __int8)initialized;
}







