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
0000000000000000 b addr_trans_segs
0000000000000000 T check_dupRegion
0000000000000000 T check_overlap
0000000000000000 T compare_ch_segments
0000000000000000 t get_addr_translation
0000000000000000 t get_device_configuration.isra.0
0000000000000000 T get_system_memory_map
0000000000000000 b icb_dev_config
0000000000000000 T ICB_Get_AllowedMemRegion
0000000000000000 T ICB_Get_MCAddr
0000000000000000 T ICB_Get_Memmap
                 U memcpy
                 U qtiseclib_cb_memset
0000000000000000 B query_dev_config_valid
                 U targetcfg_info
0000000000000000 T translate_address
0000000000000000 T update_addr_translation
*/
#include "icbcfg_query.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall check_dupRegion(
        __int64 a1,
        __int64 a2,
        int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  int v9; // w7
  __int64 *v10; // x5
  unsigned int v11; // w8
  char v12; // w11
  __int64 *v13; // x9
  __int64 v14; // x12
  unsigned int v15; // w10
  __int64 v16; // x1
  unsigned __int64 v17; // x0
  __int64 v18; // x2
  unsigned int i; // w0
  unsigned int v20; // w6
  __int64 v21; // x1
  char *v22; // x2
  unsigned __int64 v23; // x1
  unsigned __int64 v24; // x0
  __int64 v25; // x2
  unsigned __int64 v27[2]; // [xsp+10h] [xbp+10h] BYREF
  char v28; // [xsp+20h] [xbp+20h]
  unsigned __int64 v29[2]; // [xsp+28h] [xbp+28h] BYREF
  char v30; // [xsp+38h] [xbp+38h]

  if ( (unsigned int)compare_ch_segments(a1, a2, a3, a4, a5, a6, a7, a8) )
  {
    return (unsigned int)-1;
  }
  else
  {
    v9 = 1;
    v10 = addr_trans_segs;
    v11 = 0;
    v12 = 1;
    v13 = addr_trans_segs;
    v14 = 24LL;
    v15 = *(_DWORD *)(a1 + 24);
    while ( v9 != v15 )
    {
      if ( !*((_BYTE *)v10 + 16) )
      {
        v16 = *v10;
        v17 = v10[3];
        if ( *v10 >= v17 )
          return (unsigned int)-1;
        v18 = v10[1];
        v28 = v12;
        v27[0] = v18 + v16;
        v27[1] = v17 - v16;
        for ( i = v9; i < v15; i = v20 )
        {
          v20 = i + 1;
          v21 = i * v14;
          v22 = (char *)v13 + v21;
          if ( !*((_BYTE *)v13 + v21 + 16) )
          {
            v23 = *(__int64 *)((char *)v13 + v21);
            v24 = *(__int64 *)((char *)v13 + v20 * v14);
            if ( v23 >= v24 )
              return (unsigned int)-1;
            v25 = *((_QWORD *)v22 + 1);
            v30 = v12;
            v29[0] = v25 + v23;
            v29[1] = v24 - v23;
            if ( check_overlap(v27, v29) )
              return (unsigned int)-1;
          }
        }
      }
      v10 += 3;
      ++v9;
    }
  }
  return v11;
}



bool __fastcall check_overlap(unsigned __int64 *a1, unsigned __int64 *a2)
{
  unsigned __int64 v2; // x2
  unsigned __int64 v3; // x3
  unsigned __int64 v4; // x4
  _BOOL8 result; // x0

  v2 = *a1;
  v3 = *a2;
  if ( *a1 >= *a2 || (v4 = a1[1], result = 0LL, v3 < v2 + v4) )
  {
    result = 1LL;
    if ( v2 > v3 )
      return v2 < v3 + a2[1];
  }
  return result;
}



__int64 __fastcall compare_ch_segments(
        __int64 a1,
        __int64 a2,
        int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  int v8; // w1
  unsigned int v9; // w5
  int j; // w3
  unsigned int v11; // w5
  int i; // w3
  __int64 *v13; // x1
  __int64 *v14; // x1
  __int64 v15; // t1
  __int64 v16; // x4
  __int64 v17; // x11
  __int64 v18; // x4
  unsigned int v19; // w8
  int v20; // w14
  int v21; // w9
  __int64 v22; // x10
  __int64 *v23; // x1
  __int64 *v24; // x1
  __int64 v25; // t1
  __int64 v26; // x4
  __int64 v27; // x11
  __int64 v28; // x4
  unsigned int v29; // w8
  int v30; // w14
  int v31; // w9
  __int64 v32; // x10

  v8 = *(_DWORD *)(a1 + 36);
  if ( !v8 )
  {
    v11 = -16;
    for ( i = 0; i != *(_DWORD *)(a1 + 24); ++i )
    {
      v13 = *(__int64 **)(a1 + 40);
      if ( i )
      {
        a8 = *(_DWORD *)(*v13 + v11 + 32LL);
        a3 = *(_DWORD *)(*v13 + v11 + 36LL) & 0xF;
      }
      v15 = *v13;
      v14 = v13 + 1;
      v16 = 16LL * (i & 0xFFFFFFF);
      v17 = v16 + 24;
      v18 = v16 + 28;
      v19 = 1;
      v20 = *(_DWORD *)(v15 + v17);
      v21 = *(_DWORD *)(v15 + v18) & 0xF;
      while ( v19 < *(_DWORD *)(a1 + 28) )
      {
        if ( i && (a8 != *(_DWORD *)(*v14 + v11 + 32LL) || a3 != (*(_DWORD *)(*v14 + v11 + 36LL) & 0xF)) )
          return 0xFFFFFFFFLL;
        v22 = *v14;
        if ( v20 != *(_DWORD *)(*v14 + v17) )
          return 0xFFFFFFFFLL;
        ++v14;
        if ( v21 != (*(_DWORD *)(v22 + v18) & 0xF) )
          return 0xFFFFFFFFLL;
        ++v19;
      }
      v11 += 16;
    }
    return 0LL;
  }
  if ( v8 == 1 )
  {
    v9 = -16;
    for ( j = 0; j != *(_DWORD *)(a1 + 24); ++j )
    {
      v23 = *(__int64 **)(a1 + 40);
      if ( j )
      {
        a8 = *(_DWORD *)(*v23 + v9 + 12LL);
        a3 = *(_DWORD *)(*v23 + v9 + 16LL) & 0xF;
      }
      v25 = *v23;
      v24 = v23 + 1;
      v26 = 16LL * (j & 0xFFFFFFF);
      v27 = v26 + 4;
      v28 = v26 + 8;
      v29 = 1;
      v30 = *(_DWORD *)(v25 + v27);
      v31 = *(_DWORD *)(v25 + v28) & 0xF;
      while ( v29 < *(_DWORD *)(a1 + 28) )
      {
        if ( j && (a8 != *(_DWORD *)(*v24 + v9 + 12LL) || a3 != (*(_DWORD *)(*v24 + v9 + 16LL) & 0xF)) )
          return 0xFFFFFFFFLL;
        v32 = *v24;
        if ( v30 != *(_DWORD *)(*v24 + v27) )
          return 0xFFFFFFFFLL;
        ++v24;
        if ( v31 != (*(_DWORD *)(v32 + v28) & 0xF) )
          return 0xFFFFFFFFLL;
        ++v29;
      }
      v9 += 16;
    }
    return 0LL;
  }
  return 0xFFFFFFFFLL;
}



__int64 __fastcall get_system_memory_map(__int64 a1, _QWORD *a2)
{
  __int64 v4; // x2
  unsigned int v5; // w4
  __int64 *v6; // x1
  __int64 v7; // x5
  char *v8; // x6
  _QWORD *v9; // x6
  unsigned int i; // w21
  __int64 result; // x0
  __int64 v12; // x0

  qtiseclib_cb_memset(a2, 0LL, 576LL);
  v4 = 0LL;
  v5 = 0;
  v6 = (__int64 *)&byte_2FDA8;
  do
  {
    if ( *(_BYTE *)v6 )
    {
      v9 = &a2[3 * v5];
      if ( *v9 )
      {
        ++v5;
        v9[1] = v9[1] - v4 + *(v6 - 2);
      }
    }
    else
    {
      v7 = *(v6 - 2);
      v8 = (char *)&a2[3 * v5];
      if ( *(_QWORD *)v8 )
      {
        *((_QWORD *)v8 + 1) = *((_QWORD *)v8 + 1) - v4 + v7;
        v4 = v7;
      }
      else
      {
        a2[3 * v5] = v7;
        v4 = v7;
        v8[16] = 1;
      }
    }
    v6 += 3;
  }
  while ( v6 != &info );
  for ( i = 1; ; ++i )
  {
    result = *(unsigned int *)(a1 + 28);
    if ( i >= (unsigned int)result )
      break;
    v12 = i;
    memcpy(&a2[18 * v12], a2, 0x90uLL);
  }
  return result;
}



__int64 __fastcall ICB_Get_AllowedMemRegion(__int64 a1, _QWORD *a2)
{
  bool v2; // zf
  __int64 v4; // x1
  int v5; // w2
  __int64 v6; // x3
  __int64 v7; // x4
  __int64 v8; // x5
  __int64 v9; // x6
  int v10; // w7
  _QWORD *v12; // x0
  __int64 v13; // [xsp+28h] [xbp-8h] BYREF

  if ( a1 )
    v2 = a2 == 0LL;
  else
    v2 = 1;
  if ( v2 )
    return 1LL;
  if ( !(unsigned __int8)get_device_configuration_isra_0(&v13)
    || (unsigned int)check_dupRegion(v13, v4, v5, v6, v7, v8, v9, v10) )
  {
    return 0xFFFFFFFFLL;
  }
  v12 = *(_QWORD **)(v13 + 16);
  *a2 = *v12;
  a2[1] = v12[1];
  return 0LL;
}



__int64 __fastcall ICB_Get_MCAddr(__int64 a1, __int64 a2, _QWORD *a3)
{
  bool v3; // zf
  char device_configuration_isra_0; // w0
  unsigned int v8; // w1
  __int64 v10; // [xsp+28h] [xbp-8h] BYREF

  if ( a2 )
    v3 = a3 == 0LL;
  else
    v3 = 1;
  if ( v3 || a1 == 0 )
    return 1LL;
  device_configuration_isra_0 = get_device_configuration_isra_0(&v10);
  v8 = -1;
  if ( device_configuration_isra_0 )
  {
    v8 = 0;
    *a3 = a2;
  }
  return v8;
}



__int64 __fastcall ICB_Get_Memmap(__int64 a1, _QWORD *a2)
{
  bool v2; // zf
  char device_configuration_isra_0; // w0
  unsigned int v5; // w1
  __int64 v7; // [xsp+28h] [xbp-8h] BYREF

  if ( a1 )
    v2 = a2 == 0LL;
  else
    v2 = 1;
  if ( v2 )
    return 1LL;
  device_configuration_isra_0 = get_device_configuration_isra_0(&v7);
  v5 = -1;
  if ( device_configuration_isra_0 )
  {
    get_system_memory_map(v7, a2);
    return 0;
  }
  return v5;
}



__int64 __fastcall translate_address(__int64 a1, __int64 a2, _QWORD *a3)
{
  __int64 result; // x0

  result = 0LL;
  *a3 = a2;
  return result;
}



__int64 update_addr_translation()
{
  __int64 result; // x0

  result = (unsigned __int8)query_dev_config_valid;
  if ( query_dev_config_valid )
    return get_addr_translation(icb_dev_config_0);
  return result;
}



