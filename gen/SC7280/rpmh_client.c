/*0000000000000000 b $d
0000000000000000 b $d
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
0000000000000000 t add_cmd_set_for_sleep.isra.0.constprop.3
0000000000000000 t add_explicit_cmd_set_for_sleep
0000000000000000 t add_rc_for_sleep
                 U cmdq_empty
                 U DRV_CONFIG_DATA
                 U drv_valid
00000000000000cc C g_cmd_set
                 U get_finished_drv
0000000000000000 t get_rc
                 U inq_it_begin
                 U inq_it_deref
                 U inq_it_next
                 U is_tcs_stuck
                 U lookup_drv_index
                 U qtiseclib_cb_memcpy
                 U qtiseclib_cb_memmove
                 U qtiseclib_cb_memset
                 U qtiseclib_cb_udelay
                 U resource_command_sets_dirty
0000000000000030 C rpmh
0000000000000000 T rpmh_barrier_all
0000000000000000 T rpmh_barrier_single
0000000000000000 T rpmh_check_tcs_idle_HLOS
0000000000000000 T rpmh_churn_all
0000000000000000 T rpmh_churn_single
                 U rpmh_client_command_add
                 U rpmh_client_command_finish
                 U rpmh_client_handle_add
0000000000000000 T rpmh_client_init
                 U rpmh_clientq_create
                 U rpmh_client_wait_on_cmd
                 U rpmh_clock_toggle
                 U rpmh_cmdq_create
                 U rpmh_cmdq_send_cmd_at_head
                 U rpmh_cmdq_send_cmd_set
                 U rpmh_core_verify
                 U rpmh_core_verify_ptr
0000000000000000 T rpmh_create_handle
0000000000000000 T rpmh_create_handle_explicit
0000000000000000 T rpmh_create_handle_internal
                 U rpmh_deregister_isr
0000000000000000 T rpmh_enter_sleep
0000000000000000 T rpmh_epcb_timeout
0000000000000000 T rpmh_exit_sleep
0000000000000000 T rpmh_find_resource_command
0000000000000000 T rpmh_finish_amc
0000000000000000 T rpmh_finish_amc_internal
0000000000000000 T rpmh_get_wake_latency
0000000000000000 T rpmh_invalidate_explicit_cmds
0000000000000000 T rpmh_is_drv_id_valid
0000000000000000 B rpmh_is_processing
0000000000000000 T rpmh_issue_command
0000000000000000 T rpmh_issue_command_set
0000000000000000 T rpmh_issue_command_set_internal
                 U rpmh_lock
                 U rpmh_malloc
                 U rpmh_os_init
                 U rpmh_realloc
                 U rpmh_register_isr
                 U rpmh_resource_command_exit_sleep
                 U rpmh_resource_command_get_priority
                 U rpmh_resource_command_init
                 U rpmh_resource_command_update
0000000000000000 B RPMH_STANDALONE
                 U rpmh_unlock
0000000000000000 t rpmh_wait_for_cmd.constprop.5
0000000000000000 t set_g_cmd_set_single
                 U tcs_check_idle_HLOS
                 U tcs_clean_sleep_wake
                 U tcs_finish_active_amc
                 U tcs_init
                 U tcs_prepare_sleep_add_cmd_set
                 U tcs_prepare_sleep_commit
                 U tcs_slots_available
*/
#include "rpmh_client.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>



__int64 __fastcall rpmh_churn_all(__int64 a1, unsigned int a2)
{
  return rpmh_wait_for_cmd_constprop_5(a1, a2, 1u, 1u);
}



__int64 __fastcall rpmh_churn_single(__int64 a1, unsigned int a2)
{
  return rpmh_wait_for_cmd_constprop_5(a1, a2, 0, 1u);
}



void rpmh_client_init()
{
  __int64 v0; // x21
  char *v1; // x28
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x24
  char *v5; // x27
  __int64 *v6; // x20
  __int64 v7; // x22

  if ( LODWORD(rpmh[0]) != 1 )
  {
    LODWORD(rpmh[0]) = 1;
    LOBYTE(qtiseclib_cb_memcpy) = RPMH_STANDALONE;
    rpmh_os_init();
    rpmh_core_verify(1LL);
    if ( !(_BYTE)qtiseclib_cb_memcpy )
      tcs_init();
    v0 = 0LL;
    qtiseclib_cb_memset = (__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))rpmh_malloc(8u);
    while ( !(_DWORD)v0 )
    {
      v1 = (char *)&_compound_literal_1_2 + 48 * v0;
      v2 = *((unsigned int *)v1 + 2);
      if ( (_DWORD)v2 )
        rpmh_register_isr(v2, (__int64)rpmh_finish_amc, *((unsigned int *)&_compound_literal_1_2 + 12 * v0), 0);
      v3 = *((unsigned int *)v1 + 3);
      if ( (_DWORD)v3 )
        rpmh_register_isr(v3, (__int64)rpmh_epcb_timeout, *((unsigned int *)&_compound_literal_1_2 + 12 * v0), 1);
      v4 = 8 * v0++;
      v5 = (char *)qtiseclib_cb_memset;
      *(_QWORD *)&v5[v4] = rpmh_cmdq_create(0);
    }
    rpmh[4] = rpmh_clientq_create();
    rpmh_core_verify(1LL);
    if ( !HIDWORD(rpmh[0]) && !LOBYTE(rpmh[5]) )
    {
      v6 = (__int64 *)(MEMORY[0xC3F0000] + 204472320LL);
      do
      {
        v7 = *v6;
        qtiseclib_cb_udelay(1LL);
        ++LODWORD(rpmh[1]);
      }
      while ( (_DWORD)v7 != -1598026722 );
      HIDWORD(rpmh[0]) = 1;
    }
    rpmh_core_verify(1LL);
    rpmh_core_verify(1LL);
  }
}



__int64 __fastcall rpmh_create_handle(int a1, __int64 a2)
{
  return rpmh_create_handle_internal(a1, a2, 0);
}



__int64 __fastcall rpmh_create_handle_explicit(int a1, __int64 a2)
{
  return rpmh_create_handle_internal(a1, a2, 1u);
}



__int64 __fastcall rpmh_create_handle_internal(int a1, __int64 a2, unsigned __int8 a3)
{
  int v5; // w21
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x19
  __int64 v9; // x0

  v5 = a3;
  rpmh_lock();
  v6 = drv_valid(a1);
  rpmh_core_verify(v6);
  rpmh_core_verify(1LL);
  v7 = rpmh_client_handle_add((unsigned int **)memcpy);
  *(_DWORD *)v7 = a1;
  *(_QWORD *)(v7 + 8) = a2;
  v8 = v7;
  *(_DWORD *)(v7 + 48) = 0;
  if ( v5 )
  {
    v9 = rpmh_malloc(0x10u);
    *(_QWORD *)(v8 + 64) = v9;
    rpmh_core_verify_ptr(v9);
    qtiseclib_cb_memset(*(_QWORD *)(v8 + 64), 0LL, 16LL);
  }
  rpmh_unlock();
  return v8;
}



__int64 __fastcall rpmh_enter_sleep(int a1)
{
  __int64 v3; // x0
  unsigned int v4; // w22
  __int64 v5; // x0
  __int64 v6; // x22
  __int64 v7; // x0
  int *v8; // x24
  __int64 v9; // x21
  int *v10; // x22

  rpmh_lock();
  if ( !(_BYTE)qtiseclib_cb_memcpy )
  {
    v3 = drv_valid(a1);
    rpmh_core_verify(v3);
    v4 = lookup_drv_index(a1);
    rpmh_core_verify(1LL);
    tcs_clean_sleep_wake(a1);
    if ( *((_DWORD *)&_compound_literal_1_2 + 12 * v4 + 2) )
      rpmh_deregister_isr();
    v5 = *((_QWORD *)qtiseclib_cb_memset + v4);
    v6 = 0LL;
    v7 = cmdq_empty(v5);
    rpmh_core_verify(v7);
    add_explicit_cmd_set_for_sleep(1, a1);
    while ( HIDWORD(qtiseclib_cb_ic_raise_sgi) > (unsigned int)v6 )
    {
      v8 = (int *)((char *)qtiseclib_cb_spin_lock + 24 * v6);
      if ( (unsigned int)rpmh_resource_command_get_priority((__int64)v8, a1) == 1 )
        add_rc_for_sleep(v8, a1);
      ++v6;
    }
    v9 = 0LL;
    add_explicit_cmd_set_for_sleep(0, a1);
    while ( HIDWORD(rpmh[1]) > (unsigned int)v9 )
    {
      v10 = (int *)(rpmh[2] + 24 * v9);
      if ( (unsigned int)rpmh_resource_command_get_priority((__int64)v10, a1) != 1 )
        add_rc_for_sleep(v10, a1);
      ++v9;
    }
    tcs_prepare_sleep_commit(a1);
  }
  rpmh_core_verify(1LL);
  return rpmh_unlock();
}



__int64 rpmh_epcb_timeout()
{
  rpmh_core_verify(1LL);
  return rpmh_core_verify(0LL);
}



__int64 __fastcall rpmh_exit_sleep(int a1)
{
  __int64 v2; // x0
  __int64 v4; // x0
  __int64 v5; // x19
  __int64 i; // x20
  __int64 v7; // x0

  rpmh_lock();
  if ( !(_BYTE)qtiseclib_cb_memcpy )
  {
    v4 = drv_valid(a1);
    rpmh_core_verify(v4);
    v5 = 48LL * (unsigned int)lookup_drv_index(a1);
    for ( i = 0LL; HIDWORD(rpmh[1]) > (unsigned int)i; ++i )
    {
      v7 = rpmh[2] + 24 * i;
      rpmh_resource_command_exit_sleep(v7, a1);
    }
    v2 = *(unsigned int *)((char *)&_compound_literal_1_2 + v5 + 8);
    if ( (_DWORD)v2 )
      rpmh_register_isr(v2, (__int64)rpmh_finish_amc, *(unsigned int *)((char *)&_compound_literal_1_2 + v5), 0);
  }
  rpmh_core_verify(1LL);
  return rpmh_unlock();
}



unsigned int *__fastcall rpmh_find_resource_command(unsigned int a1)
{
  unsigned int v2; // w3
  unsigned int v3; // w2
  unsigned int v4; // w4
  unsigned int v6; // w1
  unsigned int *result; // x0

  v2 = HIDWORD(rpmh[1]);
  v3 = v2 - 1;
  if ( v2 )
  {
    v4 = 0;
    while ( v4 <= v3 && v3 < v2 )
    {
      v6 = (v4 + v3) >> 1;
      result = (unsigned int *)(rpmh[2] + 24LL * v6);
      if ( *result >= a1 )
      {
        if ( *result <= a1 )
          return result;
        v3 = v6 - 1;
      }
      else
      {
        v4 = v6 + 1;
      }
    }
  }
  return 0LL;
}



__int64 __fastcall rpmh_finish_amc(int a1)
{
  return rpmh_finish_amc_internal(a1, 1u);
}



__int64 __fastcall rpmh_finish_amc_internal(int a1, unsigned __int8 a2)
{
  int v2; // w21
  int finished_drv; // w20
  __int64 v5; // x0
  __int64 v6; // x22
  int active; // w20
  __int64 result; // x0
  __int64 v9; // [xsp+38h] [xbp+38h] BYREF

  v2 = a2;
  v9 = 0LL;
  if ( a2 )
    rpmh_lock();
  finished_drv = get_finished_drv(a1);
  if ( finished_drv == 0x3FFFFFFF )
  {
    rpmh_core_verify(1LL);
  }
  else
  {
    rpmh_core_verify(1LL);
    v5 = drv_valid(finished_drv);
    rpmh_core_verify(v5);
    v6 = 8LL * (unsigned int)lookup_drv_index(finished_drv);
    active = tcs_finish_active_amc(&v9, *(_QWORD *)(rpmh[3] + v6), finished_drv);
    rpmh_core_verify(active != 0);
    rpmh_core_verify(1LL);
    rpmh_client_command_finish(v9, active);
    while ( (unsigned __int8)rpmh_cmdq_send_cmd_at_head(*(_QWORD *)(rpmh[3] + v6)) )
      ;
  }
  result = rpmh_core_verify(1LL);
  if ( v2 )
    return rpmh_unlock();
  return result;
}



__int64 __fastcall rpmh_get_wake_latency(int a1)
{
  return *((unsigned int *)&_compound_literal_1_2 + 12 * (int)lookup_drv_index(a1) + 4);
}



__int64 __fastcall rpmh_invalidate_explicit_cmds(__int64 a1)
{
  __int64 v2; // x0
  unsigned int v3; // w2

  rpmh_core_verify_ptr(*(_QWORD *)(a1 + 64));
  v2 = *(_QWORD *)(a1 + 64);
  v3 = *(_DWORD *)(v2 + 4);
  *(_DWORD *)v2 = 0;
  qtiseclib_cb_memset(*(_QWORD *)(v2 + 8), 0LL, 204LL * v3);
  return tcs_clean_sleep_wake(*(_DWORD *)a1);
}




__int64 __fastcall rpmh_issue_command(__int64 a1, int a2, char a3, int a4, int a5)
{
  rpmh_lock();
  set_g_cmd_set_single(a4, a5, a3, a2);
  LODWORD(a1) = rpmh_issue_command_set_internal(a1, (unsigned int *)g_cmd_set, 0);
  rpmh_unlock();
  return (unsigned int)a1;
}



__int64 __fastcall rpmh_issue_command_set(__int64 a1, unsigned int *a2)
{
  return rpmh_issue_command_set_internal(a1, a2, 1u);
}



__int64 __fastcall rpmh_issue_command_set_internal(__int64 a1, unsigned int *a2, unsigned __int8 a3)
{
  int v4; // w23
  unsigned int *v6; // x25
  unsigned int v7; // w24
  unsigned int v8; // w21
  unsigned int v9; // w1
  unsigned int v10; // w0
  int v11; // w21
  __int64 v12; // x26
  int v13; // w2
  unsigned int v14; // t1
  unsigned __int8 v15; // w0
  unsigned int **v16; // x21
  int v17; // w0
  unsigned int v18; // w21
  __int64 v19; // x21
  unsigned int v20; // w1
  unsigned int v21; // w0
  int v23; // [xsp+64h] [xbp+64h]
  unsigned int *rc; // [xsp+68h] [xbp+68h]

  v4 = a3;
  rpmh_is_processing = 1;
  if ( a3 )
    rpmh_lock();
  v6 = a2 + 3;
  v7 = 0;
  v8 = lookup_drv_index(*(_DWORD *)a1);
  rpmh_core_verify(1LL);
  v9 = a2[1];
  v10 = *((_DWORD *)&_compound_literal_1_2 + 12 * v8 + 7);
  v11 = 0;
  a2[2] = 0;
  rpmh_core_verify(v9 <= v10);
  v12 = *(_QWORD *)(a1 + 64);
  while ( a2[1] > v7 )
  {
    v13 = v6[1];
    ++v7;
    v14 = *v6;
    v6 += 3;
    v23 = v13;
    rc = get_rc(v14);
    rpmh_core_verify(1LL);
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



