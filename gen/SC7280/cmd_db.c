/*0000000000000000 b $d
0000000000000000 b $d
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
                 U cmd_db_access_done
0000000000000000 T cmd_db_conv_str_to_unit64
0000000000000000 T cmd_db_init
                 U cmd_db_prep_access
0000000000000000 T cmd_db_query
0000000000000000 T cmd_db_query_addr
0000000000000000 T cmd_db_query_aux_data
0000000000000000 T cmd_db_query_len
0000000000000000 T cmd_db_query_priority
0000000000000000 T cmd_db_query_priority_res_id
0000000000000000 T cmd_db_query_slv_id
0000000000000000 T cmd_db_query_version
                 U cmd_db_target_mem_init
0000000000000000 B cmd_db_test_addr
0000000000000000 B cmd_db_test_data
0000000000000000 B cmd_db_test_priority
                 U qtiseclib_cb_memcpy
0000000000000000 B smem_query_db
*/
#include "cmd_db.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall cmd_db_conv_str_to_unit64(__int64 a1)
{
  __int64 v2; // x2
  __int64 result; // x0
  unsigned __int8 v4; // w1
  char v5; // w3

  v2 = 0LL;
  result = 0LL;
  do
  {
    v4 = *(_BYTE *)(a1 + v2);
    if ( !v4 )
      break;
    v5 = 8 * v2++;
    result |= (unsigned __int64)v4 << v5;
  }
  while ( v2 != 8 );
  return result;
}



bool cmd_db_init()
{
  _BOOL4 v0; // w20
  char v2; // [xsp+4Bh] [xbp+4Bh] BYREF
  int v3; // [xsp+4Ch] [xbp+4Ch] BYREF

  v3 = 0;
  smem_query_db = cmd_db_target_mem_init(&v3);
  v0 = !smem_query_db
    || (cmd_db_prep_access(), *(_DWORD *)smem_query_db != 1)
    || *(_DWORD *)(smem_query_db + 4) != 201535707;
  cmd_db_access_done();
  if ( v0 )
    smem_query_db = 0LL;
  v2 = 32;
  cmd_db_test_addr = cmd_db_query_addr((__int64)"MC0");
  dword_1FCCC = cmd_db_query_addr((__int64)"mss.lvl");
  cmd_db_query_aux_data((__int64)"mss.lvl", &v2, (__int64)&cmd_db_test_data);
  cmd_db_test_priority = cmd_db_query_priority(cmd_db_test_addr, 0);
  dword_1FCBC = cmd_db_query_priority(dword_1FCCC, 1);
  dword_1FCC0 = cmd_db_query_priority_res_id((__int64)"cx.lvl", 0);
  dword_1FCC4 = cmd_db_query_priority_res_id((__int64)"cx.tmr", 1);
  return v0;
}



__int64 __fastcall cmd_db_query(__int64 a1, __int64 a2, __int64 a3)
{
  bool v5; // zf
  unsigned int v6; // w21
  int v7; // w0
  int v9; // w0
  __int64 v10; // x26
  int v11; // w0
  int v12; // w25
  int v13; // w21
  unsigned int v14; // w25
  __int64 v15; // x5
  unsigned __int16 *v16; // x4
  unsigned __int16 *v17; // x1
  unsigned int i; // w2
  int v19; // w0
  __int64 v20; // x3
  __int64 v21; // x22
  bool v22; // zf
  unsigned int v23; // w20
  unsigned int v24; // w2
  __int64 v25; // x1
  __int64 v26; // x21
  __int64 v27; // x2

  if ( !smem_query_db )
  {
LABEL_21:
    v6 = 1;
    goto LABEL_37;
  }
  if ( a1 )
    v5 = a2 == 0;
  else
    v5 = 1;
  v6 = 2;
  v7 = v5;
  if ( !v7 && (a3 || !*(_DWORD *)(a2 + 24)) )
  {
    v9 = *(_DWORD *)(a1 + 16);
    if ( !v9 )
    {
      v10 = cmd_db_conv_str_to_unit64(a1);
      goto LABEL_17;
    }
    if ( v9 == 1 )
    {
      v11 = *(_WORD *)(a1 + 14) & 0xF;
      if ( (unsigned int)(v11 - 3) <= 2 )
      {
        v10 = 0LL;
        *(_DWORD *)(a1 + 20) = v11;
LABEL_17:
        v12 = *(_DWORD *)(a1 + 20);
        cmd_db_prep_access();
        v13 = 0;
        v14 = v12 - 3;
        v15 = smem_query_db + 144;
        v16 = (unsigned __int16 *)(smem_query_db + 8);
        v17 = (unsigned __int16 *)(smem_query_db + 10);
        while ( v14 <= 2 && *v16 != *(_DWORD *)(a1 + 20) )
        {
LABEL_20:
          ++v13;
          v16 += 8;
          v17 += 8;
          if ( v13 == 8 )
            goto LABEL_21;
        }
        for ( i = 0; ; i = (unsigned __int16)(i + 1) )
        {
          if ( i >= v17[2] )
            goto LABEL_20;
          v19 = *(_DWORD *)(a1 + 16);
          v20 = *v17 + 24LL * i;
          v21 = v15 + v20;
          if ( v19 )
          {
            if ( v19 != 1 )
              continue;
            v22 = *(_DWORD *)(a1 + 12) == *(_DWORD *)(v21 + 16);
          }
          else
          {
            v22 = *(_QWORD *)(v15 + v20) == v10;
          }
          if ( v22 )
          {
            qtiseclib_cb_memcpy(a2, a1, 9LL);
            v23 = *(_DWORD *)(a2 + 24);
            v24 = *(unsigned __int16 *)(v21 + 20);
            v25 = smem_query_db;
            *(_DWORD *)(a2 + 12) = *(_DWORD *)(v21 + 16);
            v26 = v25 + 16LL * v13;
            *(_DWORD *)(a2 + 16) = *(_DWORD *)(v21 + 8);
            *(_DWORD *)(a2 + 20) = *(_DWORD *)(v21 + 12);
            *(_WORD *)(a2 + 28) = *(_WORD *)(v26 + 16);
            if ( v23 && v24 )
            {
              if ( v24 <= v23 )
                v23 = v24;
              v27 = *(unsigned __int16 *)(v26 + 12);
              v6 = 0;
              qtiseclib_cb_memcpy(a3, v25 + 144 + v27 + *(unsigned __int16 *)(v21 + 22), v23);
              *(_DWORD *)(a2 + 24) = v23;
            }
            else
            {
              v6 = 0;
              if ( v24 )
                *(_DWORD *)(a2 + 24) = v24;
            }
            goto LABEL_37;
          }
        }
      }
    }
    goto LABEL_21;
  }
LABEL_37:
  cmd_db_access_done();
  return v6;
}



__int64 __fastcall cmd_db_query_addr(__int64 a1)
{
  __int64 v2[3]; // [xsp+18h] [xbp+18h] BYREF
  __int64 v3; // [xsp+30h] [xbp+30h] BYREF
  __int64 v4; // [xsp+38h] [xbp+38h]
  __int64 v5; // [xsp+40h] [xbp+40h]
  __int64 v6; // [xsp+48h] [xbp+48h]

  v3 = 0LL;
  v4 = 0LL;
  v5 = 0LL;
  v6 = 0LL;
  memset(v2, 0, sizeof(v2));
  if ( !a1 )
    return 2LL;
  qtiseclib_cb_memcpy(v2, a1, 9LL);
  if ( (unsigned int)cmd_db_query((__int64)v2, (__int64)&v3, 0LL) )
    return 0LL;
  else
    return HIDWORD(v4);
}



__int64 __fastcall cmd_db_query_aux_data(__int64 a1, _BYTE *a2, __int64 a3)
{
  bool v3; // zf
  bool v4; // zf
  __int64 result; // x0
  __int64 v8[3]; // [xsp+28h] [xbp+28h] BYREF
  __int64 v9[3]; // [xsp+40h] [xbp+40h] BYREF
  __int64 v10; // [xsp+58h] [xbp+58h]

  if ( a3 )
    v3 = a2 == 0LL;
  else
    v3 = 1;
  v4 = v3 || a1 == 0;
  memset(v9, 0, sizeof(v9));
  v10 = 0LL;
  memset(v8, 0, sizeof(v8));
  if ( v4 )
    return 2LL;
  qtiseclib_cb_memcpy(v8, a1, 9LL);
  LODWORD(v10) = (unsigned __int8)*a2;
  result = cmd_db_query((__int64)v8, (__int64)v9, a3);
  if ( !(_DWORD)result )
    *a2 = v10;
  return result;
}



__int64 __fastcall cmd_db_query_len(__int64 a1)
{
  __int64 v2[3]; // [xsp+18h] [xbp+18h] BYREF
  __int64 v3[3]; // [xsp+30h] [xbp+30h] BYREF
  __int64 v4; // [xsp+48h] [xbp+48h]

  memset(v3, 0, sizeof(v3));
  v4 = 0LL;
  memset(v2, 0, sizeof(v2));
  if ( !a1 )
    return 2LL;
  qtiseclib_cb_memcpy(v2, a1, 9LL);
  if ( (unsigned int)cmd_db_query((__int64)v2, (__int64)v3, 0LL) )
    return 0LL;
  else
    return (unsigned int)v4;
}



__int64 __fastcall cmd_db_query_priority(int a1, char a2)
{
  __int64 v4; // [xsp+28h] [xbp+28h] BYREF
  int v5; // [xsp+30h] [xbp+30h]
  int v6; // [xsp+34h] [xbp+34h]
  __int64 v7; // [xsp+38h] [xbp+38h]
  __int64 v8[2]; // [xsp+40h] [xbp+40h] BYREF
  __int64 v9; // [xsp+50h] [xbp+50h]
  __int64 v10; // [xsp+58h] [xbp+58h]

  v4 = 0LL;
  v5 = 0;
  v7 = 1LL;
  v6 = a1;
  v8[0] = 0LL;
  v8[1] = 0LL;
  v9 = 0LL;
  v10 = 0LL;
  if ( (unsigned int)cmd_db_query((__int64)&v4, (__int64)v8, 0LL) )
    return 0LL;
  else
    return 2 * ((HIDWORD(v9) >> a2) & 1) + (((unsigned int)v9 >> a2) & 1);
}



__int64 __fastcall cmd_db_query_priority_res_id(__int64 a1, char a2)
{
  int v3; // w0
  unsigned int v4; // w1
  __int64 v6[3]; // [xsp+28h] [xbp+28h] BYREF
  __int64 v7[2]; // [xsp+40h] [xbp+40h] BYREF
  __int64 v8; // [xsp+50h] [xbp+50h]
  __int64 v9; // [xsp+58h] [xbp+58h]

  v7[0] = 0LL;
  v7[1] = 0LL;
  v8 = 0LL;
  v9 = 0LL;
  memset(v6, 0, sizeof(v6));
  if ( a1 )
  {
    qtiseclib_cb_memcpy(v6, a1, 9LL);
    v3 = cmd_db_query((__int64)v6, (__int64)v7, 0LL);
    v4 = 0;
    if ( !v3 )
      return 2 * ((HIDWORD(v8) >> a2) & 1) + (((unsigned int)v8 >> a2) & 1);
  }
  else
  {
    return 2;
  }
  return v4;
}



__int64 __fastcall cmd_db_query_slv_id(__int64 a1)
{
  __int64 v2[3]; // [xsp+18h] [xbp+18h] BYREF
  __int64 v3; // [xsp+30h] [xbp+30h] BYREF
  __int64 v4; // [xsp+38h] [xbp+38h]
  __int64 v5; // [xsp+40h] [xbp+40h]
  __int64 v6; // [xsp+48h] [xbp+48h]

  v3 = 0LL;
  v4 = 0LL;
  v5 = 0LL;
  v6 = 0LL;
  memset(v2, 0, sizeof(v2));
  if ( !a1 )
    return 0LL;
  qtiseclib_cb_memcpy(v2, a1, 9LL);
  if ( (unsigned int)cmd_db_query((__int64)v2, (__int64)&v3, 0LL) )
    return 0LL;
  else
    return BYTE6(v4) & 0xF;
}



__int64 __fastcall cmd_db_query_version(__int64 a1)
{
  __int64 v2[3]; // [xsp+18h] [xbp+18h] BYREF
  __int64 v3[3]; // [xsp+30h] [xbp+30h] BYREF
  __int64 v4; // [xsp+48h] [xbp+48h]

  memset(v3, 0, sizeof(v3));
  v4 = 0LL;
  memset(v2, 0, sizeof(v2));
  if ( !a1 )
    return 2LL;
  qtiseclib_cb_memcpy(v2, a1, 9LL);
  if ( (unsigned int)cmd_db_query((__int64)v2, (__int64)v3, 0LL) )
    return 0LL;
  else
    return WORD2(v4);
}



