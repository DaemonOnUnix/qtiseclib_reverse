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
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t add_sw_node_request
0000000000000000 t aggregate_sw_node
                 U cmd_db_query_addr
                 U cmd_db_query_aux_data
0000000000000000 b commit_queue
0000000000000000 T icbuarb_create_client
0000000000000000 T icbuarb_d4_entry
0000000000000000 T icbuarb_d4_exit
0000000000000000 T icbuarb_destroy_client
0000000000000000 T icbuarb_init
0000000000000000 T icbuarb_issue_request
0000000000000000 T icbuarb_prio_override_disable
0000000000000000 T icbuarb_prio_override_enable
                 U icbuarb_target_d4_entry
                 U icbuarb_target_d4_exit
                 U icbuarb_target_init
                 U icbuarb_target_prio_override_disable
                 U icbuarb_target_prio_override_enable
                 U icbuarb_target_throttle_disable
                 U icbuarb_target_throttle_enable
0000000000000000 T icbuarb_throttle_disable
0000000000000000 T icbuarb_throttle_enable
0000000000000000 b info
                 U qtisec_free
                 U qtiseclib_cb_memcpy
                 U qtiseclib_cb_memmove
                 U qtiseclib_cb_memset
                 U qtisec_malloc
0000000000000000 t remove_client_requests
0000000000000000 t remove_sw_node_request
                 U rpmh_barrier_all
                 U rpmh_create_handle
0000000000000000 b rpmh_handle
                 U rpmh_issue_command_set
                 U target_info
*/
#include "icbuarb.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall icbuarb_create_client(int a1, int a2)
{
  __int64 i; // x20
  _DWORD *v3; // x4
  __int64 v6; // x19
  __int64 v7; // x0
  unsigned int v8; // w20
  __int64 v9; // x0
  __int64 v10; // x21
  __int64 v11; // x0
  __int64 v12; // x0

  if ( info )
  {
    for ( i = 0LL; i != 8LL * *(unsigned int *)info; i += 8LL )
    {
      v3 = *(_DWORD **)(*(_QWORD *)(info + 8) + i);
      if ( v3 && *v3 == a1 && v3[1] == a2 )
      {
        v6 = qtisec_malloc(0x20uLL);
        if ( !v6 )
          return 0LL;
        v7 = *(_QWORD *)(*(_QWORD *)(info + 8) + i);
        v8 = 0;
        *(_DWORD *)v6 = a1;
        *(_DWORD *)(v6 + 4) = a2;
        *(_QWORD *)(v6 + 8) = v7;
        qtiseclib_cb_memset(v6 + 16, 0LL, 16LL);
        while ( 1 )
        {
          v9 = *(_QWORD *)(v6 + 8);
          if ( v8 >= *(_DWORD *)(v9 + 8) )
            break;
          v10 = 16LL * v8;
          v11 = *(_QWORD *)(*(_QWORD *)(v9 + 16) + v10);
          if ( v11 )
          {
            if ( !(unsigned __int8)add_sw_node_request((int *)(v11 + 32), v6 + 16) )
              break;
          }
          v12 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v6 + 8) + 16LL) + v10 + 8);
          if ( v12 )
          {
            if ( !(unsigned __int8)add_sw_node_request((int *)(v12 + 32), v6 + 16) )
              break;
          }
          ++v8;
        }
        if ( v8 < *(_DWORD *)(*(_QWORD *)(v6 + 8) + 8LL) )
        {
          remove_client_requests(v6);
          qtisec_free(v6);
          return 0LL;
        }
        return v6;
      }
    }
  }
  return 0LL;
}





__int64 __fastcall icbuarb_destroy_client(_QWORD *a1)
{
  __int64 v2; // x2
  __int64 v3; // x3
  __int64 v4; // x4
  __int64 v5; // x5
  __int64 v6; // x6
  __int64 v7; // x7
  __int64 v9; // [xsp+0h] [xbp+0h]
  _QWORD v10[2]; // [xsp+20h] [xbp+20h] BYREF

  if ( !a1 )
    return 0LL;
  qtiseclib_cb_memset(v10, 0LL, 16LL);
  if ( !(unsigned __int8)icbuarb_issue_request(a1, v10, v2, v3, v4, v5, v6, v7, v9) )
    return 0LL;
  remove_client_requests((__int64)a1);
  qtisec_free((__int64)a1);
  return 1LL;
}



__int64 icbuarb_init()
{
  __int64 result; // x0
  unsigned int v1; // w21
  __int64 v2; // x19
  int v3; // w0
  __int64 v4; // x0
  __int64 v5; // x3
  __int64 v6; // x5
  __int64 v7; // x4
  __int64 v8; // x1
  __int64 v9; // x6
  __int64 v10; // x7
  unsigned int v11; // w2
  int v12; // w12
  int v13; // w13
  __int64 v14; // x8
  __int64 v15; // x3
  __int64 v16; // x5
  __int64 v17; // x4
  __int64 v18; // x1
  __int64 v19; // x6
  __int64 v20; // x7
  unsigned int v21; // w2
  int v22; // w12
  int v23; // w13
  __int64 v24; // x8
  char v25; // w0
  char v26; // [xsp+37h] [xbp+37h] BYREF
  int v27; // [xsp+38h] [xbp+38h] BYREF
  unsigned __int16 v28; // [xsp+3Ch] [xbp+3Ch]
  unsigned __int8 v29; // [xsp+3Eh] [xbp+3Eh]

  result = 1LL;
  if ( !info )
  {
    v1 = 0;
    info = (__int64)&target_info;
    while ( v1 < *(_DWORD *)(info + 48) )
    {
      v2 = *(_QWORD *)(*(_QWORD *)(info + 56) + 8LL * v1);
      v26 = 8;
      if ( (unsigned int)cmd_db_query_aux_data(*(_QWORD *)(v2 + 8), &v26, (__int64)&v27) )
        goto LABEL_23;
      ++v1;
      *(_DWORD *)(v2 + 20) = cmd_db_query_addr(*(_QWORD *)(v2 + 8));
      v3 = v28;
      *(_BYTE *)(v2 + 36) = 0;
      *(_DWORD *)(v2 + 24) = v3;
      *(_DWORD *)(v2 + 28) = v27;
      *(_DWORD *)(v2 + 32) = v29;
    }
    rpmh_handle = rpmh_create_handle(0, (__int64)"ICB");
    if ( !rpmh_handle )
    {
LABEL_23:
      v25 = 0;
      return v25 & 1;
    }
    v4 = info;
    v5 = 0LL;
    v6 = 8LL * *(unsigned int *)(info + 16);
    while ( v6 != v5 )
    {
      v7 = 0LL;
      v8 = *(_QWORD *)(*(_QWORD *)(v4 + 24) + v5);
      v9 = 8LL * *(unsigned int *)(v8 + 48);
      while ( v7 != v9 )
      {
        v10 = *(_QWORD *)(*(_QWORD *)(v8 + 56) + v7);
        v11 = *(_DWORD *)(v10 + 64);
        if ( v11 < *(_DWORD *)(v10 + 68) )
        {
          v13 = *(_DWORD *)(v8 + 4);
          v12 = *(_DWORD *)(v8 + 8);
          v14 = *(_QWORD *)(v10 + 72) + 16LL * *(unsigned int *)(v10 + 64);
          *(_QWORD *)v14 = v8 + 16;
          *(_DWORD *)(v14 + 8) = v13;
          *(_DWORD *)(v14 + 12) = v12;
          *(_DWORD *)(v10 + 64) = v11 + 1;
        }
        v7 += 8LL;
      }
      v5 += 8LL;
    }
    v15 = 0LL;
    v16 = 8LL * *(unsigned int *)(v4 + 32);
    while ( v15 != v16 )
    {
      v17 = 0LL;
      v18 = *(_QWORD *)(*(_QWORD *)(v4 + 40) + v15);
      v19 = 8LL * *(unsigned int *)(v18 + 48);
      while ( v17 != v19 )
      {
        v20 = *(_QWORD *)(*(_QWORD *)(v18 + 56) + v17);
        v21 = *(_DWORD *)(v20 + 64);
        if ( v21 < *(_DWORD *)(v20 + 68) )
        {
          v23 = *(_DWORD *)(v18 + 4);
          v22 = *(_DWORD *)(v18 + 8);
          v24 = *(_QWORD *)(v20 + 72) + 16LL * *(unsigned int *)(v20 + 64);
          *(_QWORD *)v24 = v18 + 16;
          *(_DWORD *)(v24 + 8) = v23;
          *(_DWORD *)(v24 + 12) = v22;
          *(_DWORD *)(v20 + 64) = v21 + 1;
        }
        v17 += 8LL;
      }
      v15 += 8LL;
    }
    v25 = icbuarb_target_init(v4);
    return v25 & 1;
  }
  return result;
}



__int64 __fastcall icbuarb_issue_request(
        _QWORD *a1,
        _QWORD *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  __int64 v9; // x8
  __int64 result; // x0
  __int64 v12; // x11
  unsigned int i; // w10
  __int64 v14; // x12
  __int64 v15; // x9
  __int64 v16; // x9
  __int64 v17; // x9
  char v18; // w13
  __int64 v19; // x0
  __int64 v20; // x1
  __int64 v21; // x2
  __int64 v22; // x9
  char v23; // w13
  __int64 v24; // x0
  __int64 v25; // x1
  __int64 v26; // x2
  __int64 v27; // x9
  int v28; // w11
  __int64 v29; // x4
  __int64 v30; // x12
  __int64 v31; // x1
  __int64 v32; // x0
  int v33; // w13
  __int64 v34; // x5
  unsigned __int64 v35; // x1
  unsigned __int64 v36; // x3
  int v37; // w2
  __int64 v38; // x18
  unsigned __int64 *v39; // x14
  __int64 v40; // x7
  unsigned int v41; // w2
  unsigned __int64 v42; // x16
  unsigned __int64 v43; // x6
  unsigned __int64 v44; // x7
  unsigned __int64 v45; // x2
  unsigned __int64 v46; // x2
  unsigned __int64 v47; // x5
  unsigned __int64 v48; // x1
  unsigned __int64 v49; // x2
  int v50; // w1
  __int64 v51; // x1
  _QWORD *v52; // x2
  unsigned int v53; // w21
  __int64 j; // x0
  _DWORD *v55; // x1
  __int64 v56; // x5
  unsigned int v57; // w2
  char *v58; // x4
  int v59; // w3
  int v60; // w3
  char *v62; // x0
  int v63; // w0
  int v64; // w20
  unsigned int v65[52]; // [xsp+40h] [xbp-D0h] BYREF

  v9 = info;
  if ( !info )
    return 0LL;
  if ( !a1 || a2 == 0LL )
    return 0LL;
  v12 = a1[1];
  a1[2] = *a2;
  a1[3] = a2[1];
  if ( !v12 )
    return 0LL;
  for ( i = 0; i < *(_DWORD *)(v12 + 8); ++i )
  {
    v14 = 16LL * i;
    v15 = *(_QWORD *)(*(_QWORD *)(v12 + 16) + v14);
    if ( v15 )
    {
      aggregate_sw_node((unsigned int *)(v15 + 32), (_QWORD *)(v15 + 16));
      v19 = 0LL;
      v20 = 8LL * *(unsigned int *)(v17 + 48);
      while ( v19 != v20 )
      {
        v21 = *(_QWORD *)(*(_QWORD *)(v17 + 56) + v19);
        v19 += 8LL;
        *(_BYTE *)(v21 + 36) = v18;
      }
    }
    v16 = *(_QWORD *)(*(_QWORD *)(v12 + 16) + v14 + 8);
    if ( v16 )
    {
      aggregate_sw_node((unsigned int *)(v16 + 32), (_QWORD *)(v16 + 16));
      v24 = 0LL;
      v25 = 8LL * *(unsigned int *)(v22 + 48);
      while ( v24 != v25 )
      {
        v26 = *(_QWORD *)(*(_QWORD *)(v22 + 56) + v24);
        v24 += 8LL;
        *(_BYTE *)(v26 + 36) = v23;
      }
    }
  }
  v27 = 0LL;
  v28 = 0;
  v29 = commit_queue;
  v30 = 8LL * *(unsigned int *)(v9 + 48);
  while ( v27 != v30 )
  {
    v31 = v29;
    v32 = *(_QWORD *)(*(_QWORD *)(v9 + 56) + v27);
    v33 = *(unsigned __int8 *)(v32 + 36);
    if ( *(_BYTE *)(v32 + 36) )
    {
      v34 = 0LL;
      v35 = 0LL;
      v36 = 0LL;
      while ( 1 )
      {
        v37 = *(_DWORD *)(v32 + 16);
        if ( v34 == 16LL * *(unsigned int *)(v32 + 64) )
          break;
        v38 = *(_QWORD *)(v32 + 72) + v34;
        v39 = *(unsigned __int64 **)v38;
        if ( v37 )
        {
          if ( v36 < v39[1] )
            v36 = v39[1];
          v46 = *v39;
        }
        else
        {
          v40 = *(unsigned int *)(v32 + 24);
          v41 = *(_DWORD *)(v38 + 8);
          v42 = v40 * v39[1];
          v43 = v42 / v41;
          if ( v42 % v41 )
            ++v43;
          if ( v36 < v43 )
            v36 = v43;
          v44 = v40 * *v39;
          v45 = v41 * *(_DWORD *)(v38 + 12);
          if ( v44 % v45 )
            v46 = v44 / v45 + 1;
          else
            v46 = v44 / v45;
        }
        v34 += 16LL;
        if ( v35 < v46 )
          v35 = v46;
      }
      *(_QWORD *)(v32 + 48) = v35;
      *(_QWORD *)(v32 + 56) = v36;
      if ( v37 )
      {
        *(_DWORD *)(v32 + 40) = 0;
      }
      else
      {
        v47 = *(unsigned int *)(v32 + 28);
        if ( v35 % v47 )
          v48 = v35 / v47 + 1;
        else
          v48 = v35 / v47;
        v49 = v36 / v47;
        if ( v48 > 0x3FFF )
          LODWORD(v48) = 0x3FFF;
        if ( v36 % v47 )
          ++v49;
        if ( v49 > 0x3FFF )
          LODWORD(v49) = 0x3FFF;
        *(_DWORD *)(v32 + 40) = v49 | ((_DWORD)v48 << 14);
      }
      v50 = *(_DWORD *)(v32 + 40);
      if ( v50 )
        *(_DWORD *)(v32 + 40) = v50 | 0x20000000;
      v51 = v29;
      v52 = 0LL;
      while ( v51 && *(_DWORD *)(v32 + 32) >= *(_DWORD *)(v51 + 32) )
      {
        v52 = (_QWORD *)v51;
        v51 = *(_QWORD *)v51;
      }
      if ( v51 == v29 )
      {
        *(_QWORD *)v32 = v51;
        v31 = v32;
      }
      else
      {
        *v52 = v32;
        v33 = v28;
        *(_QWORD *)v32 = v51;
        v31 = v29;
      }
      v28 = v33;
      *(_BYTE *)(v32 + 36) = 0;
    }
    v27 += 8LL;
    v29 = v31;
  }
  if ( v28 )
    commit_queue = v29;
  result = 1LL;
  if ( commit_queue )
  {
    v53 = 0;
    qtiseclib_cb_memset(v65, 0LL, 204LL);
    for ( j = 0LL; ; j = v57 )
    {
      v55 = (_DWORD *)commit_queue;
      if ( !commit_queue )
        break;
      v56 = *(_QWORD *)commit_queue;
      v57 = j + 1;
      *(_QWORD *)commit_queue = 0LL;
      v58 = (char *)&a9 + 12 * (unsigned int)j;
      v59 = v55[5];
      commit_queue = v56;
      *((_DWORD *)v58 - 49) = v59;
      v60 = v55[10];
      *((_DWORD *)v58 - 48) = v60;
      if ( v56 )
      {
        if ( v55[8] == *(_DWORD *)(v56 + 32) && v57 != 16 )
          continue;
      }
      v62 = (char *)&a9 + 12 * j;
      v65[0] = 0;
      v65[1] = v57;
      *((_DWORD *)v62 - 48) = v60 | 0x40000000;
      *(v62 - 188) = 1;
      v63 = rpmh_issue_command_set(rpmh_handle, v65);
      if ( v63 )
        v64 = v63;
      else
        v64 = v53;
      v53 = v64;
      qtiseclib_cb_memset(v65, 0LL, 204LL);
      v57 = 0;
    }
    rpmh_barrier_all(rpmh_handle, v53);
    return 1LL;
  }
  return result;
}







