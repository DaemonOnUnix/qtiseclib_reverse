/*0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
                 U cmd_db_query_priority
                 U DRV_CONFIG_DATA
                 U lookup_drv_index
                 U qtiseclib_cb_memset
0000000000000000 t resource_command_dirty_update.isra.0
0000000000000000 T resource_command_sets_dirty
                 U rpmh_core_verify
                 U rpmh_core_verify_ptr
                 U rpmh_find_resource_command
                 U rpmh_malloc
0000000000000000 T rpmh_resource_command_exit_sleep
0000000000000000 T rpmh_resource_command_finish
0000000000000000 T rpmh_resource_command_get_priority
0000000000000000 T rpmh_resource_command_get_voter
0000000000000000 T rpmh_resource_command_init
0000000000000000 T rpmh_resource_command_update
0000000000000000 T rpmh_resource_command_val_at_rpmh
*/
#include "rpmh_resource_commands.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
unsigned __int64 __fastcall resource_command_sets_dirty(__int64 a1, int a2)
{
  unsigned __int64 result; // x0
  unsigned __int64 v3; // x2

  result = rpmh_resource_command_get_voter(a1, a2);
  if ( !result )
    return 0LL;
  v3 = result;
  LODWORD(result) = 2 * (*(_DWORD *)(result + 44) >= 2u);
  if ( *(_DWORD *)(v3 + 56) < 2u )
    return (unsigned int)result;
  else
    return (unsigned int)result | 4;
}



__int64 __fastcall rpmh_resource_command_exit_sleep(__int64 a1, int a2)
{
  __int64 voter; // x0
  int v3; // w4
  int v4; // w3

  voter = rpmh_resource_command_get_voter(a1, a2);
  if ( voter && *(_BYTE *)(voter + 52) )
  {
    v3 = *(_DWORD *)(voter + 56);
    v4 = *(_DWORD *)(voter + 48);
    *(_BYTE *)(voter + 28) = 1;
    *(_DWORD *)(voter + 24) = v4;
    if ( v3 != 1 )
    {
      *(_BYTE *)(voter + 52) = 0;
      *(_DWORD *)(voter + 48) = 0;
    }
    *(_BYTE *)(voter + 16) = 1;
    *(_DWORD *)(voter + 12) = v4;
  }
  return resource_command_dirty_update_isra_0(voter);
}



__int64 __fastcall rpmh_resource_command_finish(unsigned int a1, int a2)
{
  unsigned int *resource_command; // x19
  __int64 voter; // x19

  resource_command = rpmh_find_resource_command(a1);
  rpmh_core_verify_ptr((__int64)resource_command);
  voter = rpmh_resource_command_get_voter((__int64)resource_command, a2);
  rpmh_core_verify_ptr(voter);
  *(_DWORD *)(voter + 4) = 0;
  return resource_command_dirty_update_isra_0(voter);
}



__int64 __fastcall rpmh_resource_command_get_priority(__int64 a1, int a2)
{
  return *(unsigned int *)(rpmh_resource_command_get_voter(a1, a2) + 8);
}



unsigned __int64 __fastcall rpmh_resource_command_get_voter(__int64 a1, int a2)
{
  unsigned __int64 v2; // x19
  __int64 v3; // x22
  unsigned int v6; // w0

  v2 = *(_QWORD *)(a1 + 8);
  v3 = 0LL;
  while ( v2 )
  {
    if ( *(_DWORD *)v2 == a2 )
      return v2;
    v3 = v2;
    v2 = *(_QWORD *)(v2 + 64);
  }
  v2 = rpmh_malloc(0x48u);
  qtiseclib_cb_memset(v2, 0LL, 72LL);
  *(_DWORD *)v2 = a2;
  v6 = lookup_drv_index(a2);
  *(_DWORD *)(v2 + 8) = cmd_db_query_priority(*(_DWORD *)a1, *((_BYTE *)&_compound_literal_1_2 + 48 * v6 + 4));
  if ( *(_QWORD *)(a1 + 8) )
  {
    rpmh_core_verify_ptr(v3);
    *(_QWORD *)(v3 + 64) = v2;
  }
  else
  {
    *(_QWORD *)(a1 + 8) = v2;
  }
  return v2;
}



__int64 __fastcall rpmh_resource_command_init(_DWORD *a1, int a2)
{
  __int64 result; // x0

  result = qtiseclib_cb_memset(a1, 0LL, 24LL);
  *a1 = a2;
  return result;
}



    if ( rpmh_resource_command_update((__int64)rc, *a2, v23, *(_DWORD *)a1, v12 != 0) )
      v11 = 1;
  }
  if ( *a2 )
  {
    v18 = 0;
    if ( !v12 )
      goto LABEL_19;
    v19 = *(_QWORD *)(a1 + 64);
    v20 = *(_DWORD *)(v19 + 4);
    v21 = *(_DWORD *)v19 + 1;
    *(_DWORD *)v19 = v21;
    if ( v21 > v20 )
    {
      *(_QWORD *)(v19 + 8) = rpmh_realloc(*(_QWORD *)(v19 + 8), 204 * v21);
      *(_DWORD *)(v19 + 4) = *(_DWORD *)v19;
    }
    qtiseclib_cb_memcpy(*(_QWORD *)(v19 + 8) + 204LL * (unsigned int)(*(_DWORD *)v19 - 1), a2, 204LL);
    add_explicit_cmd_set_for_sleep(1, *(_DWORD *)a1);
    add_explicit_cmd_set_for_sleep(0, *(_DWORD *)a1);
    tcs_prepare_sleep_commit(*(_DWORD *)a1);
    goto LABEL_18;
  }
  if ( !v11 || LOBYTE(rpmh[5]) )
  {
    rpmh_core_verify(1LL);
LABEL_18:
    v18 = 0;
    goto LABEL_19;
  }
  v15 = is_tcs_stuck(*(_DWORD *)a1);
  rpmh_core_verify(v15 ^ 1u);
  rpmh_client_command_add(a1);
  while ( a2[1] > 0x10 )
    ;
  v16 = (unsigned int **)qtiseclib_cb_memset;
  v17 = lookup_drv_index(*(_DWORD *)a1);
  v18 = rpmh_cmdq_send_cmd_set(v16[v17], (int *)a1, a2);
  rpmh_core_verify(1LL);
LABEL_19:
  if ( v4 )
    rpmh_unlock();
  rpmh_wait_for_cmd_constprop_5(a1, v18, 1u, v4);
  rpmh_is_processing = 0;
  return v18;
}



__int64 __fastcall rpmh_resource_command_val_at_rpmh(unsigned int a1, int a2, unsigned int a3, unsigned __int8 a4)
{
  __int64 v4; // x19
  int v5; // w22
  unsigned int *resource_command; // x21
  __int64 voter; // x20
  unsigned __int64 v9; // x0
  unsigned __int64 v10; // x21
  unsigned __int64 v11; // x19
  unsigned int v12; // w0
  unsigned int v13; // w19
  __int64 v14; // x0

  v4 = a3;
  v5 = a4;
  resource_command = rpmh_find_resource_command(a1);
  rpmh_core_verify_ptr((__int64)resource_command);
  voter = rpmh_resource_command_get_voter((__int64)resource_command, a2);
  rpmh_core_verify_ptr(voter);
  rpmh_core_verify(*(_DWORD *)(voter + 4) == 0);
  v9 = rpmh_resource_command_get_voter((__int64)resource_command, a2);
  if ( v9 )
  {
    v10 = v9;
    v11 = v9 + 12 * v4;
    v12 = *(_DWORD *)(v11 + 32);
    if ( v12 <= 2 )
    {
      rpmh_core_verify(*(unsigned __int8 *)(v11 + 28));
      v13 = *(_DWORD *)(v11 + 24);
      goto LABEL_6;
    }
    if ( v12 == 4 )
    {
      rpmh_core_verify(*(unsigned __int8 *)(v10 + 28));
      v13 = *(_DWORD *)(v10 + 24);
LABEL_6:
      v14 = 1LL;
      goto LABEL_9;
    }
    rpmh_core_verify(0LL);
  }
  v13 = 0;
  v14 = 0LL;
LABEL_9:
  rpmh_core_verify(v14);
  *(_DWORD *)(voter + 12) = v13;
  *(_BYTE *)(voter + 16) = 1;
  if ( v5 )
    *(_DWORD *)(voter + 4) = 1;
  return v13;
}



