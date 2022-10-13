/*0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 T cmdq_empty
0000000000000000 T cmdq_finish_cmd
0000000000000000 T cmdq_num_in_flight
                 U DRV_CONFIG_DATA
                 U inq_append
                 U inq_create
                 U inq_head
                 U inq_it_begin
                 U inq_it_delete
                 U inq_it_deref
                 U inq_it_next
                 U inq_pop
                 U inq_size
                 U is_amc_free
                 U qtiseclib_cb_memset
0000000000000000 T rpmh_clean_cmd
0000000000000000 T rpmh_cmdq_create
0000000000000000 T rpmh_cmdq_send_cmd_at_head
0000000000000000 T rpmh_cmdq_send_cmd_set
                 U rpmh_core_verify
                 U rpmh_core_verify_ptr
                 U rpmh_err_fatal
                 U rpmh_find_resource_command
                 U rpmh_malloc
                 U rpmh_resource_command_finish
                 U rpmh_resource_command_get_voter
                 U tcs_send
*/
#include "rpmh_cmdq.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
bool __fastcall cmdq_empty(__int64 a1)
{
  return !inq_head(*(_QWORD *)(a1 + 16)) && inq_head(*(_QWORD *)(a1 + 8)) == 0;
}



unsigned int *__fastcall cmdq_finish_cmd(__int64 a1, __int64 a2, int a3, __int64 a4, int a5)
{
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 i; // x20
  __int64 v11; // x0
  unsigned int *v13[3]; // [xsp+38h] [xbp+38h] BYREF

  if ( a5 )
  {
    rpmh_core_verify(0LL);
    v8 = 0LL;
  }
  else
  {
    v8 = *(_QWORD *)(a1 + 8);
  }
  inq_it_begin(v8, v13);
  while ( 1 )
  {
    v9 = inq_it_deref((__int64)v13);
    if ( !v9 )
      rpmh_err_fatal("Inconsistent cmdq state.");
    if ( a2 == v9 )
      break;
    inq_it_next(v13);
  }
  inq_it_delete(v13);
  for ( i = 0LL; *(_DWORD *)(a2 + 8) > (unsigned int)i; ++i )
  {
    v11 = 8 * i;
    rpmh_resource_command_finish(*(_DWORD *)(*(_QWORD *)a2 + v11), a3);
  }
  rpmh_clean_cmd((_QWORD *)a2, *(_DWORD *)a1);
  return inq_append(*(unsigned int **)(a1 + 24), a2);
}



__int64 __fastcall cmdq_num_in_flight(__int64 a1)
{
  return inq_size(*(_QWORD *)(a1 + 8));
}



__int64 __fastcall rpmh_clean_cmd(_QWORD *a1, unsigned int a2)
{
  _QWORD *v2; // x19

  v2 = a1 + 1;
  qtiseclib_cb_memset(*a1, 0LL, 8LL * a2);
  return qtiseclib_cb_memset(v2, 0LL, 40LL);
}



__int64 __fastcall rpmh_cmdq_create(unsigned int a1)
{
  char *v1; // x20
  __int64 v2; // x19

  v1 = (char *)&_compound_literal_1_2 + 48 * a1;
  v2 = rpmh_malloc(0x20u);
  rpmh_core_verify_ptr(v2);
  qtiseclib_cb_memset(v2, 0LL, 32LL);
  *(_DWORD *)v2 = *((_DWORD *)v1 + 7);
  *(_QWORD *)(v2 + 8) = inq_create(40);
  *(_QWORD *)(v2 + 16) = inq_create(40);
  *(_QWORD *)(v2 + 24) = inq_create(40);
  return v2;
}



__int64 __fastcall rpmh_cmdq_send_cmd_at_head(__int64 a1)
{
  __int64 v2; // x0
  unsigned int v3; // w21
  __int64 v4; // x19
  __int64 v5; // x21
  int v6; // w22
  unsigned int *resource_command; // x23
  __int64 voter; // x23
  unsigned __int8 v9; // w0
  unsigned int *v11[3]; // [xsp+48h] [xbp+48h] BYREF

  inq_it_begin(*(_QWORD *)(a1 + 16), v11);
  v2 = inq_it_deref((__int64)v11);
  if ( !v2 )
    return 0;
  v4 = v2;
  v5 = 0LL;
  v6 = 1;
  rpmh_core_verify(*(_DWORD *)(v2 + 8) <= *(_DWORD *)a1);
  while ( *(_DWORD *)(v4 + 8) > (unsigned int)v5 )
  {
    resource_command = rpmh_find_resource_command(*(_DWORD *)(*(_QWORD *)v4 + 8 * v5));
    rpmh_core_verify_ptr((__int64)resource_command);
    if ( !cmdq_empty(a1) )
    {
      voter = rpmh_resource_command_get_voter((__int64)resource_command, **(_DWORD **)(v4 + 16));
      rpmh_core_verify_ptr(voter);
      if ( *(_DWORD *)(voter + 4) || *(_DWORD *)(*(_QWORD *)v4 + 4LL) == 2 && (unsigned int)cmdq_num_in_flight(a1) )
        v6 = 0;
    }
    ++v5;
  }
  if ( v6 && (v9 = tcs_send(v4, **(_DWORD **)(v4 + 16)), (v3 = v9) != 0) )
  {
    inq_it_delete(v11);
    inq_append(*(unsigned int **)(a1 + 8), v4);
  }
  else
  {
    return 0;
  }
  return v3;
}



__int64 __fastcall rpmh_cmdq_send_cmd_set(unsigned int *a1, int *a2, _DWORD *a3)
{
  __int64 v6; // x19
  __int64 v7; // x0
  unsigned int v8; // w0
  int v9; // w1
  unsigned int *v10; // x24
  __int64 v11; // x23
  int v12; // w25
  unsigned int v13; // w0
  unsigned int v14; // w26
  unsigned int v15; // w28
  unsigned int *resource_command; // x27
  unsigned int *v17; // x2
  __int64 voter; // x26
  unsigned int v19; // w22

  v6 = inq_pop(*((unsigned int **)a1 + 3));
  if ( !v6 )
  {
    v6 = rpmh_malloc(0x30u);
    rpmh_core_verify_ptr(v6);
    qtiseclib_cb_memset(v6, 0LL, 48LL);
  }
  if ( !*(_QWORD *)v6 )
  {
    v7 = rpmh_malloc(8 * *a1);
    *(_QWORD *)v6 = v7;
    rpmh_core_verify_ptr(v7);
    qtiseclib_cb_memset(*(_QWORD *)v6, 0LL, 8LL * *a1);
  }
  v8 = a3[1];
  v9 = 0;
  *(_QWORD *)(v6 + 16) = a2;
  *(_DWORD *)(v6 + 8) = v8;
  if ( a2 )
    v9 = a2[12];
  *(_DWORD *)(v6 + 24) = v9;
  v10 = a3 + 3;
  v11 = 0LL;
  v12 = 1;
  *(_DWORD *)(v6 + 12) = a3[2];
  *(_DWORD *)(v6 + 28) = *a3;
  *(_BYTE *)(v6 + 32) = 1;
  rpmh_core_verify(v8 <= *a1);
  rpmh_core_verify(a3[1] <= *a1);
  while ( 1 )
  {
    v13 = *(_DWORD *)(v6 + 8);
    if ( v13 <= (unsigned int)v11 )
      break;
    v14 = *v10;
    v15 = *((unsigned __int8 *)v10 + 8);
    resource_command = rpmh_find_resource_command(*v10);
    rpmh_core_verify_ptr((__int64)resource_command);
    v17 = (unsigned int *)(*(_QWORD *)v6 + 8 * v11);
    v17[1] = v15;
    *v17 = v14;
    if ( a2 )
    {
      voter = rpmh_resource_command_get_voter((__int64)resource_command, *a2);
      rpmh_core_verify_ptr(voter);
      if ( *(_DWORD *)(voter + 4) )
        v12 = 0;
    }
    ++v11;
    v10 += 3;
  }
  rpmh_core_verify(*a1 >= v13);
  if ( *a3 )
  {
    v19 = 0;
    rpmh_core_verify(0LL);
  }
  else
  {
    rpmh_core_verify_ptr((__int64)a2);
    v19 = *(_DWORD *)(v6 + 24);
    if ( v12 && (unsigned __int8)is_amc_free(*a2) )
    {
      inq_append(*((unsigned int **)a1 + 1), v6);
      tcs_send(v6, *a2);
    }
    else
    {
      rpmh_core_verify(1LL);
      inq_append(*((unsigned int **)a1 + 2), v6);
    }
  }
  return v19;
}



