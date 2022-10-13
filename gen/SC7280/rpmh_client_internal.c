/*0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 T check_for_events
0000000000000000 t get_cmd_in_progress.isra.1.constprop.3
                 U inq_append
                 U inq_create
                 U inq_head
                 U inq_it_begin
                 U inq_it_delete
                 U inq_it_deref
                 U inq_it_next
                 U inq_pop
                 U is_amc_finished
                 U qtiseclib_cb_memset
0000000000000000 T rpmh_client_command_add
0000000000000000 T rpmh_client_command_finish
0000000000000000 T rpmh_client_command_remove
0000000000000000 T rpmh_client_handle_add
0000000000000000 T rpmh_clientq_create
0000000000000000 T rpmh_client_wait_on_cmd
                 U rpmh_core_verify_ptr
                 U rpmh_err_fatal
                 U rpmh_event_create
                 U rpmh_event_destroy
                 U rpmh_event_set
                 U rpmh_event_wait
                 U rpmh_finish_amc_internal
                 U rpmh_lock
                 U rpmh_malloc
                 U rpmh_unlock
*/
#include "rpmh_client_internal.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall check_for_events(__int64 a1, int a2)
{
  __int64 result; // x0
  __int64 v5; // x19
  int v6; // w0
  unsigned int *v7[3]; // [xsp+38h] [xbp+38h] BYREF

  inq_it_begin(*(_QWORD *)(a1 + 32), v7);
  while ( 1 )
  {
    result = inq_it_deref((__int64)v7);
    v5 = result;
    if ( !result )
      return result;
    v6 = *(_DWORD *)(result + 16);
    if ( v6 == 1 )
    {
      if ( *(_DWORD *)v5 >= *(_DWORD *)(a1 + 52) )
        goto LABEL_9;
LABEL_8:
      rpmh_event_set(*(_QWORD *)(v5 + 8));
      inq_it_delete(v7);
      qtiseclib_cb_memset(v5, 0LL, 32LL);
      inq_append(*(unsigned int **)(a1 + 40), v5);
      inq_it_begin(*(_QWORD *)(a1 + 32), v7);
    }
    else
    {
      if ( !v6 && *(_DWORD *)v5 == a2 )
        goto LABEL_8;
LABEL_9:
      inq_it_next(v7);
    }
  }
}



__int64 __fastcall rpmh_client_command_add(__int64 a1)
{
  _DWORD *v2; // x20
  int v3; // w0
  unsigned int v4; // w1
  __int64 result; // x0

  v2 = (_DWORD *)inq_pop(*(unsigned int **)(a1 + 24));
  if ( !v2 )
  {
    v2 = (_DWORD *)rpmh_malloc(0x18u);
    rpmh_core_verify_ptr((__int64)v2);
    qtiseclib_cb_memset(v2, 0LL, 24LL);
  }
  v3 = *(_DWORD *)(a1 + 48) + 1;
  *(_DWORD *)(a1 + 48) = v3;
  *v2 = v3;
  inq_append(*(unsigned int **)(a1 + 16), (__int64)v2);
  v4 = *(_DWORD *)(a1 + 52);
  ++*(_DWORD *)(a1 + 56);
  LODWORD(result) = *(_DWORD *)(a1 + 48);
  if ( (unsigned int)result > v4 )
    result = v4;
  else
    result = (unsigned int)result;
  *(_DWORD *)(a1 + 52) = result;
  return result;
}



__int64 __fastcall rpmh_client_command_finish(__int64 a1, int a2)
{
  __int64 v4; // x0
  __int64 result; // x0
  __int64 v6; // [xsp+28h] [xbp+28h] BYREF

  v4 = *(_QWORD *)(a1 + 16);
  v6 = 0LL;
  result = (__int64)get_cmd_in_progress_isra_1_constprop_3(v4, &v6, a2);
  if ( (_BYTE)result )
  {
    result = *(unsigned __int8 *)(v6 + 8);
    if ( !*(_BYTE *)(v6 + 8) )
    {
      rpmh_client_command_remove(a1, a2);
      return check_for_events(a1, a2);
    }
  }
  return result;
}



__int64 __fastcall rpmh_client_command_remove(__int64 a1, int a2)
{
  _DWORD *v4; // x20
  int *v5; // x0
  int v6; // w0
  __int64 result; // x0
  unsigned int *v8[3]; // [xsp+38h] [xbp+38h] BYREF

  inq_it_begin(*(_QWORD *)(a1 + 16), v8);
  while ( 1 )
  {
    v4 = (_DWORD *)inq_it_deref((__int64)v8);
    if ( !v4 )
      rpmh_err_fatal("Inconsistent client cmds_in_progress state.");
    if ( a2 == *v4 )
      break;
    inq_it_next(v8);
  }
  inq_it_delete(v8);
  qtiseclib_cb_memset(v4, 0LL, 24LL);
  inq_append(*(unsigned int **)(a1 + 24), (__int64)v4);
  v5 = (int *)inq_head(*(_QWORD *)(a1 + 16));
  if ( v5 )
    v6 = *v5;
  else
    v6 = -1;
  *(_DWORD *)(a1 + 52) = v6;
  result = (unsigned int)(*(_DWORD *)(a1 + 56) - 1);
  *(_DWORD *)(a1 + 56) = result;
  return result;
}



__int64 __fastcall rpmh_client_handle_add(unsigned int **a1)
{
  __int64 v2; // x0
  __int64 v3; // x19

  v2 = inq_pop(a1[1]);
  if ( v2 )
  {
    v3 = v2;
    inq_append(*a1, v2);
  }
  else
  {
    v3 = rpmh_malloc(0x50u);
    rpmh_core_verify_ptr(v3);
    qtiseclib_cb_memset(v3, 0LL, 80LL);
    *(_DWORD *)(v3 + 52) = -1;
    inq_append(*a1, v3);
    *(_QWORD *)(v3 + 32) = inq_create(24);
    *(_QWORD *)(v3 + 40) = inq_create(24);
    *(_QWORD *)(v3 + 16) = inq_create(16);
    *(_QWORD *)(v3 + 24) = inq_create(16);
  }
  return v3;
}




__int64 __fastcall rpmh_client_wait_on_cmd(__int64 a1, unsigned int a2, unsigned int a3, unsigned __int8 a4)
{
  __int64 v6; // x0
  int v8; // w20
  __int64 result; // x0
  __int64 v10; // x20
  __int64 v11; // x22
  unsigned int *v12; // x0
  __int64 v13; // [xsp+48h] [xbp+48h] BYREF

  v6 = *(_QWORD *)(a1 + 16);
  v13 = 0LL;
  v8 = a4;
  result = (__int64)get_cmd_in_progress_isra_1_constprop_3(v6, &v13, a2);
  if ( (_BYTE)result || a3 == 1 && (result = *(unsigned int *)(a1 + 52), a2 > (unsigned int)result) )
  {
    if ( v8 )
    {
      while ( !is_amc_finished(*(_DWORD *)a1) )
        ;
      rpmh_finish_amc_internal(*(_DWORD *)a1, 0);
      return rpmh_client_wait_on_cmd(a1, a2, a3, 1LL);
    }
    else
    {
      v10 = inq_pop(*(unsigned int **)(a1 + 40));
      if ( !v10 )
      {
        v10 = rpmh_malloc(0x20u);
        rpmh_core_verify_ptr(v10);
        qtiseclib_cb_memset(v10, 0LL, 32LL);
      }
      v11 = rpmh_event_create();
      v12 = *(unsigned int **)(a1 + 32);
      *(_DWORD *)v10 = a2;
      *(_QWORD *)(v10 + 8) = v11;
      *(_DWORD *)(v10 + 16) = a3;
      inq_append(v12, v10);
      rpmh_unlock();
      rpmh_event_wait(v11);
      rpmh_lock();
      return rpmh_event_destroy(v11);
    }
  }
  return result;
}



