/*0000000000000000 d $d
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
                 U cmd_db_query_addr
0000000000000000 D g_pdc_resource_data_instances
                 U g_pdcResourceList
                 U g_pdcTCSConfig
0000000000000000 T pdcTcs_getAllResourceList
0000000000000000 T pdcTcs_getResources
0000000000000000 T pdcTcs_initialize
                 U qtisec_assert
*/
#include "pdcTcs.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

char *__fastcall pdcTcs_getResources(unsigned int a1)
{
  if ( a1 > 3 )
    qtisec_assert("noship_src/drivers/pdc/tcs/src/pdcTcs.c", 0xC1u, "tcsNum < TCS_NUM_TOTAL");
  return (char *)&g_pdcTCSConfig + 96 * a1;
}



__int64 pdcTcs_initialize()
{
  int v0; // w19
  unsigned int v1; // w23
  char *v2; // x21
  char *v3; // x20
  char *v4; // x22
  int v5; // w24
  __int64 result; // x0
  unsigned __int64 v7; // x20
  __int64 i; // x5
  unsigned int v9; // w19
  char *v10; // x4
  int v11; // w1
  int v12; // w0
  int *v13; // x14
  unsigned int v14; // w0
  unsigned __int64 v15; // x2
  char **v16; // x2
  unsigned __int64 v17; // x2
  int v18; // w3
  __int64 v19[2]; // [xsp+40h] [xbp+40h]

  v0 = unk_1CC68;
  v1 = unk_1CC6C;
  v19[0] = 0LL;
  v19[1] = 0LL;
  v2 = (char *)off_1CC58;
  if ( unk_1CC6C > 4u )
    qtisec_assert("noship_src/drivers/pdc/tcs/src/pdcTcs.c", 0x81u, "(TCS_NUM_TOTAL >= TotalnTCS)");
  v3 = off_1CC60 + 8;
  v4 = off_1CC60 + 72;
  v5 = 0;
  do
  {
    result = cmd_db_query_addr(*((_QWORD *)v3 - 1));
    if ( (_DWORD)result )
    {
      result = (unsigned int)(*(_DWORD *)v3 + result);
      *(_DWORD *)v3 = result;
    }
    else
    {
      ++v5;
    }
    v3 += 16;
  }
  while ( v4 != v3 );
  if ( !v5 )
  {
    v7 = (unsigned int)(v0 + 4100);
    if ( (unsigned __int8)*(_DWORD *)v7 >> 5 != 4 )
      qtisec_assert(
        "noship_src/drivers/pdc/tcs/src/pdcTcs.c",
        0x9Bu,
        "4 == (((*((volatile uint32_t *) ((uintptr_t) ((pdc_res.subsytem_addr) + 0X1004 + (0x10000*(0)))))) & (0xe0)) >> 5)");
    if ( ((*(_DWORD *)v7 >> 8) & 0xFu) < v1 )
      qtisec_assert(
        "noship_src/drivers/pdc/tcs/src/pdcTcs.c",
        0x9Cu,
        "TotalnTCS <= (((*((volatile uint32_t *) ((uintptr_t) ((pdc_res.subsytem_addr) + 0X1004 + (0x10000*(0)))))) & (0xf00)) >> 8)");
    for ( i = 0LL; i != v1; ++i )
    {
      v10 = &v2[96 * i];
      v11 = 0;
      v12 = v0 + 200 * (unsigned __int16)i;
      v13 = (int *)(unsigned int)(v12 + 21768);
      v14 = v12 + 21776;
      do
      {
        v15 = *((unsigned int *)v10 + 3);
        if ( (v15 & 0x10) == 0 )
        {
          if ( (v15 & 8) == 0 )
            *((_DWORD *)v19 + i) |= 1 << v11;
          *(_DWORD *)(v14 - 4) = (((v15 >> 1) & 1) << 8) | ((((v15 ^ 4) >> 2) & 1) << 16);
          if ( (v15 & 1) != 0 )
            *v13 = (1 << v11) | *v13 & 0xF;
          v16 = &(&g_pdcResourceList)[2 * (unsigned __int8)*v10];
          *(_QWORD *)v10 = v16;
          *(_DWORD *)v14 = *((_DWORD *)v16 + 2) + *((_DWORD *)v10 + 4);
          *(_DWORD *)(v14 + 4) = *((_DWORD *)v10 + 2);
        }
        ++v11;
        v10 += 24;
        v14 += 16;
      }
      while ( v11 != 4 );
    }
    v9 = v0 + 21764;
    for ( result = 0LL; result != v1; ++result )
    {
      v17 = v9;
      v18 = *((_DWORD *)v19 + result);
      v9 += 200;
      *(_DWORD *)v17 = v18;
    }
  }
  return result;
}



