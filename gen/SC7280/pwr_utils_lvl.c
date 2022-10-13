/*0000000000000000 r $d
0000000000000000 b $d
0000000000000000 b $d
0000000000000000 b $d
0000000000000000 d $d
0000000000000000 b $d
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 b alloc_offset.1210
                 U cmd_db_query_aux_data
                 U cmd_db_query_len
0000000000000000 b g_res
0000000000000000 b g_res_count
0000000000000000 b lvl_buf
0000000000000000 T pwr_utils_hlvl
0000000000000000 T pwr_utils_hlvl_named_resource
0000000000000000 T pwr_utils_lvl_init
0000000000000000 T pwr_utils_lvl_resource_idx
0000000000000000 T pwr_utils_named_resource_lvls_count
0000000000000000 T pwr_utils_resource_lvls_count
0000000000000000 T pwr_utils_vlvl
0000000000000000 T pwr_utils_vlvl_named_resource
                 U qtisec_assert
                 U qtiseclib_cb_strcmp
0000000000000000 R resource_count
0000000000000000 d resource_list
*/
#include "pwr_utils_lvl.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall pwr_utils_hlvl(int a1, int a2, char *a3)
{
  int v3; // wzr
  __int64 v5; // x3
  __int64 result; // x0
  int v7; // w4
  char v8; // [xsp+Ch] [xbp-4h] BYREF

  if ( !a3 )
    a3 = &v8;
  if ( a1 >= (unsigned __int64)g_res_count || a2 < v3 )
  {
    result = 0xFFFFFFFFLL;
    *(_DWORD *)a3 = -1;
  }
  else
  {
    v5 = g_res + 24LL * a1;
    for ( result = 0LL; (unsigned __int64)(unsigned int)result < *(_QWORD *)(v5 + 16); result = (unsigned int)(result + 1) )
    {
      v7 = *(unsigned __int16 *)(*(_QWORD *)(v5 + 8) + 2LL * (unsigned int)result);
      if ( a2 <= v7 )
      {
        *(_DWORD *)a3 = v7;
        return result;
      }
    }
    *(_DWORD *)a3 = -2;
    return 0xFFFFFFFFLL;
  }
  return result;
}



__int64 __fastcall pwr_utils_hlvl_named_resource(__int64 a1, int a2, char *a3)
{
  int v5; // w0

  v5 = pwr_utils_lvl_resource_idx(a1);
  return pwr_utils_hlvl(v5, a2, a3);
}



__int64 pwr_utils_lvl_init()
{
  unsigned int v0; // w20
  __int64 result; // x0
  __int64 v2; // x0
  __int64 v3; // x27
  __int64 v4; // x24
  unsigned int len; // w0
  unsigned int v6; // w19
  char *v7; // x2
  __int64 v8; // x19
  __int64 i; // x1
  unsigned __int8 v11; // [xsp+6Fh] [xbp+6Fh] BYREF

  g_res = (__int64)&resource_list;
  v0 = 0;
  g_res_count = 9LL;
  while ( 1 )
  {
    result = g_res_count;
    if ( g_res_count <= (unsigned __int64)v0 )
      break;
    v2 = 24LL * v0;
    v3 = *(_QWORD *)(g_res + v2);
    v4 = g_res + v2;
    len = cmd_db_query_len(v3);
    v11 = len;
    v6 = len;
    if ( len )
    {
      if ( len > 0x20 )
        qtisec_assert("noship_src/services/pwr_utils/pwr_utils_lvl.c", 0x74u, "data_len <= MAX_AUX_DATA_LEN");
      if ( (unsigned __int64)len + alloc_offset_1210 > 0x1FF )
        qtisec_assert(
          "noship_src/services/pwr_utils/pwr_utils_lvl.c",
          0x77u,
          "(alloc_offset + data_len) < (sizeof (lvl_buf)/sizeof (lvl_buf[0]))");
      v7 = (char *)&lvl_buf + 2 * alloc_offset_1210;
      alloc_offset_1210 += len;
      *(_QWORD *)(v4 + 8) = v7;
      cmd_db_query_aux_data(v3, &v11, (__int64)v7);
      if ( v6 != v11 )
        qtisec_assert("noship_src/services/pwr_utils/pwr_utils_lvl.c", 0x7Cu, "data_len == (uint32_t)aux_len");
      v8 = v6 >> 1;
      for ( i = 0LL; i != v8; ++i )
      {
        if ( !*(_WORD *)(*(_QWORD *)(v4 + 8) + 2 * i) && (_DWORD)i != 0 )
          break;
      }
      *(_QWORD *)(v4 + 16) = (unsigned int)i;
    }
    ++v0;
  }
  return result;
}



__int64 __fastcall pwr_utils_lvl_resource_idx(__int64 a1)
{
  unsigned int i; // w19

  if ( !a1 )
    return 0xFFFFFFFFLL;
  if ( g_res && g_res_count )
  {
    for ( i = 0; g_res_count > (unsigned __int64)i; ++i )
    {
      if ( !(unsigned int)qtiseclib_cb_strcmp(*(_QWORD *)(g_res + 24LL * i)) )
        return i;
    }
  }
  return 0xFFFFFFFFLL;
}



__int64 __fastcall pwr_utils_named_resource_lvls_count(__int64 a1)
{
  int v1; // w0

  v1 = pwr_utils_lvl_resource_idx(a1);
  return pwr_utils_resource_lvls_count(v1);
}



__int64 __fastcall pwr_utils_resource_lvls_count(int a1)
{
  if ( g_res_count <= (unsigned __int64)a1 )
    return 0xFFFFFFFFLL;
  else
    return *(unsigned int *)(g_res + 24LL * a1 + 16);
}



__int64 __fastcall pwr_utils_vlvl(int a1, int a2)
{
  __int64 v2; // x2
  __int64 result; // x0

  if ( g_res_count <= (unsigned __int64)a1 )
    return 0xFFFFFFFFLL;
  v2 = g_res + 24LL * a1;
  result = 0xFFFFFFFFLL;
  if ( (unsigned __int64)a2 < *(_QWORD *)(v2 + 16) )
    return *(unsigned __int16 *)(*(_QWORD *)(v2 + 8) + 2LL * a2);
  return result;
}



__int64 __fastcall pwr_utils_vlvl_named_resource(__int64 a1, int a2)
{
  int v3; // w0

  v3 = pwr_utils_lvl_resource_idx(a1);
  return pwr_utils_vlvl(v3, a2);
}



