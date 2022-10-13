/*0000000000000000 t $x
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
                 U qtiseclib_cb_memset
0000000000000000 T vmidmt_ClearError
0000000000000000 t _vmidmt_ConfigCtxt.isra.4
0000000000000000 T vmidmt_ConfigErrRep
0000000000000000 T vmidmt_ConfigSSDT
0000000000000000 T vmidmt_ConfigVmidCtxt
0000000000000000 T vmidmt_ConfigVmidCtxtWithSIDList
0000000000000000 T vmidmt_EnableClientP
0000000000000000 T vmidmt_GetError
0000000000000000 T vmidmt_Init
0000000000000000 T vmidmt_IsError
0000000000000000 T vmidmt_Reset
0000000000000000 T vmidmt_Restore
0000000000000000 T vmidmt_Save
0000000000000000 t _vmidmt_SetDefaultConfig.isra.0.part.1
0000000000000000 t _vmidmt_ShiftCtxt.isra.2
*/
#include "HALvmidmtGenImpl.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall vmidmt_ClearError(__int64 *a1, char a2)
{
  bool v2; // zf
  __int64 v3; // x1
  int v4; // w1

  v2 = a2 == 0;
  v3 = *a1;
  if ( v2 )
  {
    *(_DWORD *)(v3 + 1100) = 0;
    v4 = *(_DWORD *)(v3 + 1100);
  }
  else
  {
    *(_DWORD *)(v3 + 76) = 0;
    v4 = *(_DWORD *)(v3 + 76);
  }
  if ( (v4 & 0xC00000A6) != 0 )
    return 7LL;
  else
    return 0LL;
}



__int64 __fastcall vmidmt_ConfigErrRep(__int64 a1, char a2, int a3)
{
  int v3; // w3
  bool v4; // zf
  unsigned int *v5; // x2
  unsigned int v6; // w1

  if ( (a3 & 0xFFFFFFE0) != 0 )
    return 5LL;
  v3 = 0;
  if ( (a3 & 1) != 0 )
    v3 = (*(_BYTE *)(a1 + 15) == 1) << 21;
  if ( (a3 & 2) != 0 )
    v3 |= 0x400u;
  if ( (a3 & 4) != 0 )
    v3 |= 0x20u;
  if ( (a3 & 8) != 0 )
    v3 |= 0x10u;
  v4 = (a3 & 0x10) == 0LL;
  v5 = *(unsigned int **)a1;
  if ( !v4 )
    v3 |= 4u;
  if ( a2 )
  {
    *v5 = *v5 & 0xFFDFFBCB | v3 & 0x200434;
    v6 = *v5;
  }
  else
  {
    v5[256] = v5[256] & 0xFDFFBCB | v3 & 0x200434;
    v6 = v5[256];
  }
  if ( v3 == (v6 & 0x200434) )
    return 0LL;
  else
    return 7LL;
}



__int64 __fastcall vmidmt_ConfigSSDT(__int64 a1, __int64 a2, unsigned int a3)
{
  bool v4; // cc
  __int64 result; // x0
  unsigned int v6; // w3
  __int64 v7; // x2
  __int64 i; // x3
  __int64 v9; // x0
  int v10; // w5

  if ( a2 )
    v4 = a3 > 4;
  else
    v4 = 1;
  result = 5LL;
  if ( !v4 )
  {
    v6 = 1 << *(_BYTE *)(a1 + 12);
    result = 5LL;
    if ( v6 <= 0x1F )
    {
      if ( a3 > 1 )
        return result;
    }
    else if ( a3 > v6 >> 5 )
    {
      return result;
    }
    v7 = 4LL * a3;
    for ( i = 0LL; i != v7; i += 4LL )
    {
      v9 = (unsigned int)i;
      v10 = *(_DWORD *)(a2 + i);
      *(_DWORD *)(*(_QWORD *)a1 + 128LL + v9) &= v10;
    }
    return 0LL;
  }
  return result;
}



__int64 __fastcall vmidmt_ConfigVmidCtxt(__int64 a1, unsigned int a2, __int64 *a3)
{
  __int64 v3; // x8
  unsigned int v4; // w3
  __int64 result; // x0
  __int64 v6; // x3
  unsigned int v7; // w10
  __int64 v8; // x5
  __int64 v9; // x4
  __int64 v10; // x6
  int v11; // w3
  int v12; // w9
  __int64 *v13; // x11
  unsigned int v14; // w9
  int v15; // w7
  unsigned int v16; // w12
  int *v17; // x5
  unsigned int v18; // w7
  unsigned int i; // w6
  int v20; // t1
  unsigned int v21; // w13
  __int64 v23; // x1
  unsigned int v24; // w2
  _DWORD *v25; // x6
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x1
  int v29; // w1
  __int64 v30; // x2
  __int64 v31; // x1
  int v32; // w3
  __int64 v33; // x1
  __int64 v34; // x0
  __int64 v35; // x1
  unsigned int v36; // w7

  if ( !a3 )
    return 5LL;
  v3 = a1;
  if ( (1 << *(_BYTE *)(a1 + 13)) - 1 >= a2 || (v4 = *(unsigned __int16 *)(a1 + 8), result = 5LL, a2 < v4) )
  {
    v6 = *a3;
    if ( *a3 )
    {
      result = 5LL;
      if ( *(unsigned __int8 *)(v6 + 20) > 7u )
        return result;
      v7 = *(_DWORD *)v6 == 2;
    }
    else
    {
      v7 = 0;
    }
    v8 = *(_QWORD *)v3;
    v9 = 4LL * (a2 >> 5);
    v10 = *(_QWORD *)v3 + 128LL;
    v11 = 1 << a2;
    if ( v7 )
      v12 = ~v11;
    else
      v12 = 1 << a2;
    *(_DWORD *)(v9 + v10) ^= (v12 ^ *(_DWORD *)(v9 + v10)) & v11;
    if ( (v11 & *(_DWORD *)(v9 + v10)) != (v12 & v11) )
      return 7LL;
    v13 = a3;
    v14 = a2;
    if ( *(_BYTE *)(v3 + 15) == 1 )
    {
      v15 = *(_DWORD *)(v8 + 4);
      v16 = a2 | 0x80000000;
      v17 = (int *)(v8 + 2048);
      v18 = BYTE1(v15);
      for ( i = 0; (int)i < *(unsigned __int16 *)(v3 + 8); ++i )
      {
        v20 = *v17++;
        if ( v16 == v20 )
        {
          if ( v7 && v18 - 1 <= i || (v18 > i) > v7 )
            return vmidmt_ConfigCtxt_isra_4(*(_QWORD *)v3, i, v13);
          result = 0LL;
          if ( v18 <= i )
          {
            while ( v18 < i && (_DWORD)result == 0 )
              result = vmidmt_ShiftCtxt_isra_2(*(_QWORD *)v3, i - 1, i);
            if ( (_DWORD)result )
              return result;
            v23 = *(_QWORD *)v3;
            v24 = v18 + 1;
            *(_DWORD *)(v23 + 4) = ((unsigned __int8)(v18 + 1) << 8) | *(_DWORD *)(*(_QWORD *)v3 + 4LL) & 0x1000000;
            v18 = (unsigned __int8)BYTE1(*(_DWORD *)(v23 + 4));
            if ( v24 != v18 )
              return 7LL;
          }
          else
          {
            v21 = v18 - 1;
            while ( v21 > i )
            {
              if ( (_DWORD)result )
                return result;
              result = vmidmt_ShiftCtxt_isra_2(*(_QWORD *)v3, i + 1, i);
            }
            if ( (_DWORD)result )
              return result;
          }
          v25 = (_DWORD *)(4LL * (i & 0x3FFFFFFF) + *(_QWORD *)v3);
          v25[512] = 0;
          if ( v25[512] )
            return 7LL;
          v25[768] &= 0xCF030400;
          if ( (v25[768] & 0x30FCFBFF) != 0 )
            return 7LL;
          v25[896] = 0;
          if ( v25[896] )
            return 7LL;
          break;
        }
      }
      if ( v7 )
      {
        i = *(unsigned __int16 *)(v3 + 8) - 1;
        v27 = (int)(4 * i);
        while ( i != -1 )
        {
          v28 = *(_QWORD *)v3 + 2048LL;
          if ( (*(_DWORD *)(v28 + v27) & 0x80000000) == 0
            || (v29 = *(_DWORD *)(v28 + v27), v27 -= 4LL, v14 == (v29 & 0x7FFF)) )
          {
            if ( v18 - 1 > i )
              return 5LL;
            goto LABEL_51;
          }
          --i;
        }
        return 5LL;
      }
      v26 = 0LL;
      do
      {
        i = v26;
        v32 = v26;
        if ( v18 == v26 )
          break;
        v30 = 4 * v26;
        v31 = *(_QWORD *)v3 + 2048LL;
        if ( (*(_DWORD *)(v31 + 4 * v26) & 0x80000000) == 0 )
          break;
        ++v26;
      }
      while ( v14 != (*(_DWORD *)(v31 + v30) & 0x7FFF) );
      if ( v18 == v32 )
        return 5LL;
LABEL_51:
      v33 = *(_QWORD *)v3 + 2048LL;
      v34 = (int)(4 * i);
      *(_DWORD *)(v33 + v34) = v16;
      if ( v16 != *(_DWORD *)(v33 + v34) )
        return 7LL;
    }
    else
    {
      v18 = 0;
      i = 0;
    }
    if ( ((unsigned __int8)v7 & (v18 > i)) == 0 )
      return vmidmt_ConfigCtxt_isra_4(*(_QWORD *)v3, i, v13);
    v35 = *(_QWORD *)v3;
    v36 = v18 - 1;
    *(_DWORD *)(v35 + 4) = *(_DWORD *)(*(_QWORD *)v3 + 4LL) & 0x1000000 | (v36 << 8);
    if ( v36 == (unsigned __int8)BYTE1(*(_DWORD *)(v35 + 4)) )
      return vmidmt_ConfigCtxt_isra_4(*(_QWORD *)v3, i, v13);
    else
      return 7LL;
  }
  return result;
}



__int64 __fastcall vmidmt_ConfigVmidCtxtWithSIDList(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        unsigned int a4,
        __int64 *a5)
{
  __int64 result; // x0
  unsigned int v8; // w5
  __int64 v9; // x0
  unsigned int v10; // w6
  unsigned int v11; // w7
  int v12; // w10
  __int64 v15; // x2
  __int64 v16; // x0
  unsigned int v17; // w6

  if ( *(unsigned __int16 *)(a1 + 8) <= a2 || a5 == 0LL )
    return 5LL;
  if ( *a5 )
  {
    result = 5LL;
    if ( *(unsigned __int8 *)(*a5 + 20) > 7u )
      return result;
  }
  v8 = *(unsigned __int8 *)(a1 + 15);
  if ( v8 != 1 )
    return vmidmt_ConfigCtxt_isra_4(*(_QWORD *)a1, a2, a5);
  if ( !a3 )
    return 5LL;
  if ( *(_BYTE *)(a1 + 13) )
    v8 = (1 << *(_BYTE *)(a1 + 13)) - 1;
  v9 = 0LL;
  v10 = 0;
  v11 = 0;
  while ( v9 != a4 )
  {
    v12 = *(_DWORD *)(a3 + 4 * v9);
    v11 |= v12;
    if ( a4 > (int)v9 + 1 )
      v10 |= v12 ^ *(_DWORD *)(a3 + 4LL * (unsigned int)(v9 + 1));
    ++v9;
  }
  result = 5LL;
  if ( v8 >= v11 && v8 >= v10 )
  {
    v15 = 4LL * (a2 & 0x3FFFFFFF);
    v16 = *(_QWORD *)a1 + 2048LL;
    v17 = v11 | 0x80000000 | (v10 << 16);
    *(_DWORD *)(v16 + v15) = v17;
    if ( v17 == *(_DWORD *)(v16 + v15) )
      return vmidmt_ConfigCtxt_isra_4(*(_QWORD *)a1, a2, a5);
    return 7LL;
  }
  return result;
}



__int64 __fastcall vmidmt_EnableClientP(int **a1, char a2)
{
  int *v2; // x0
  int v3; // w0

  v2 = *a1;
  if ( a2 )
  {
    *v2 &= ~1u;
    v3 = *v2;
  }
  else
  {
    v2[256] &= 0xFFFFFFEu;
    v3 = v2[256];
  }
  if ( (v3 & 1) != 0 )
    return 7LL;
  else
    return 0LL;
}



__int64 __fastcall vmidmt_GetError(__int64 result, unsigned __int8 a2, _DWORD *a3)
{
  __int64 v4; // x20
  int v5; // w21
  _DWORD *v6; // x1
  unsigned int v7; // w2
  int v8; // w4
  int v9; // w3
  unsigned __int64 v10; // x0
  int v11; // w1

  if ( a3 )
  {
    v4 = result;
    v5 = a2;
    qtiseclib_cb_memset(a3, 0LL, 44LL);
    v6 = *(_DWORD **)v4;
    if ( v5 )
    {
      v7 = v6[18] & 0xC00000A6;
      a3[2] = v6[16];
      if ( *(_BYTE *)(v4 + 14) )
        a3[3] = v6[17];
      v8 = v6[21];
      v9 = v6[20] & 0x1FF;
      v10 = (unsigned int)v6[22];
    }
    else
    {
      v7 = v6[274] & 0xC00000A6;
      a3[2] = v6[272];
      if ( *(_BYTE *)(v4 + 14) )
        a3[3] = v6[273];
      v8 = v6[277];
      v10 = (unsigned int)v6[278];
      v9 = v6[276] & 0x1FF;
    }
    if ( (v7 & 0x80000000) != 0 )
      *a3 |= 1u;
    if ( (v7 & 0x40000000) != 0 )
      *a3 |= 2u;
    if ( (v7 & 0x80) != 0 )
      *a3 |= 4u;
    if ( (v7 & 0x20) != 0 )
      *a3 |= 8u;
    if ( (v7 & 4) != 0 )
      *a3 |= 0x10u;
    if ( (v7 & 2) != 0 )
      *a3 |= 0x20u;
    if ( (v9 & 0x20) != 0 )
      a3[1] |= 1u;
    if ( (v9 & 0x10) != 0 )
      a3[1] |= 2u;
    if ( (v9 & 2) != 0 )
      a3[1] |= 4u;
    a3[4] = BYTE2(v8);
    a3[5] = v8 & 0x7FFF;
    a3[6] = (unsigned __int8)v10;
    a3[7] = BYTE2(v10);
    a3[8] = BYTE3(v10);
    v11 = (unsigned __int16)v10 >> 13;
    result = (v10 >> 8) & 0x1F;
    a3[9] = v11;
    a3[10] = result;
  }
  return result;
}



__int64 __fastcall vmidmt_Init(__int64 *a1, __int64 a2, __int64 *a3)
{
  __int64 *v4; // x9
  __int64 *v5; // x12
  __int64 v6; // x1
  unsigned __int64 v7; // x0
  unsigned int v8; // w10
  __int64 result; // x0
  __int64 *v10; // x1
  int v11; // w10
  __int64 v12; // x11
  unsigned int *v13; // x0
  int v14; // w2
  unsigned int v15; // w2
  unsigned int i; // w1
  unsigned int j; // w1
  __int64 v18; // x4
  __int64 v19; // x5
  unsigned int k; // w1
  __int64 v21; // x4
  unsigned int *v22; // x0
  unsigned int *v23; // x2
  unsigned int v24; // w0
  unsigned int v25; // w1
  _DWORD *v26; // x0
  __int64 v27; // x1

  v4 = a1;
  v5 = a3;
  v6 = *a1;
  v7 = *(unsigned int *)(*a1 + 32);
  *((_BYTE *)v4 + 15) = (v7 & 0x8000000) != 0;
  *((_BYTE *)v4 + 13) = (v7 >> 9) & 0xF;
  *((_WORD *)v4 + 4) = (unsigned __int8)v7;
  *((_BYTE *)v4 + 12) = BYTE1(*(_DWORD *)(v6 + 36)) & 0xF;
  *((_BYTE *)v4 + 14) = *(_DWORD *)(v6 + 40) & 0xF;
  *((_WORD *)v4 + 5) = (unsigned __int8)*(_DWORD *)(v6 + 52);
  *(_DWORD *)(v6 + 156) = -1;
  if ( a2 )
  {
    v8 = *(unsigned __int8 *)(a2 + 9);
    if ( v8 != 255 && v8 > (unsigned __int8)v7 )
      goto LABEL_4;
    v10 = *(__int64 **)a2;
    if ( !*(_QWORD *)a2 || *v10 && *(unsigned __int8 *)(*v10 + 20) > 7u )
      goto LABEL_4;
    result = vmidmt_SetDefaultConfig_isra_0_part_1((unsigned int **)v4, v10, 1);
    if ( (_DWORD)result )
      goto LABEL_17;
    v13 = (unsigned int *)*v4;
    v14 = *(unsigned __int8 *)(v12 + 8);
    v13[1] = ((v14 & 1) << 24) | *(_DWORD *)(*v4 + 4) & 0xFF00;
    if ( (HIBYTE(v13[1]) & 1) != v14
      || (v13[1] = v13[1] & 0x1000000 | (v11 << 8), (unsigned __int8)BYTE1(v13[1]) != v11) )
    {
      result = 7LL;
      goto LABEL_17;
    }
  }
  else
  {
    *(_DWORD *)v6 = 273;
    *(_QWORD *)(v6 + 4) = (unsigned __int8)v7 << 8;
    *(_DWORD *)(v6 + 16) = 0;
  }
  if ( !v5 )
  {
    v22 = (unsigned int *)*v4;
    v22[256] = 273;
    v22[258] = 0;
    v22[260] = 0;
    goto LABEL_30;
  }
  if ( *v5 && *(unsigned __int8 *)(*v5 + 20) > 7u )
  {
LABEL_4:
    result = 5LL;
    goto LABEL_17;
  }
  result = vmidmt_SetDefaultConfig_isra_0_part_1((unsigned int **)v4, v5, 0);
  if ( (_DWORD)result )
    goto LABEL_17;
LABEL_30:
  v23 = (unsigned int *)*v4;
  v23[36] = 1;
  v23[292] = 1;
  v23[19] = 0;
  v23[275] = 0;
  v24 = 1 << *((_BYTE *)v4 + 12);
  if ( v24 <= 0x1F )
  {
    v23[32] = -1;
  }
  else
  {
    v25 = v24 >> 5;
    result = 6LL;
    if ( v25 > 4 )
      goto LABEL_17;
    v26 = v23 + 32;
    v27 = (__int64)&v23[v25 + 32];
    do
      *v26++ = -1;
    while ( (_DWORD *)v27 != v26 );
  }
  result = 0LL;
LABEL_17:
  v15 = *((unsigned __int16 *)v4 + 4);
  if ( *((_BYTE *)v4 + 15) == 1 )
  {
    for ( i = 0; i < v15; ++i )
    {
      v18 = 4LL * (i & 0x3FFFFFFF);
      *(_DWORD *)(*v4 + 2048 + v18) = 0;
    }
  }
  for ( j = 0; j < v15; ++j )
  {
    v19 = 4LL * (j & 0x3FFFFFFF);
    *(_DWORD *)(*v4 + 3072 + v19) = 0x10000;
  }
  for ( k = 0; k < v15; ++k )
  {
    v21 = 4LL * (k & 0x3FFFFFFF);
    *(_DWORD *)(*v4 + 3584 + v21) = 0;
  }
  return result;
}



              if ( vmidmt_IsError(v10, 1) )
              {
                vmidmt_GetError((__int64)v10, 1u, &v12);
                qtiseclib_cb_log(10LL, "Error Flags: 0x%X", (unsigned int)v12);
                qtiseclib_cb_log(10LL, "Bus Flags: 0x%X", HIDWORD(v12));
                qtiseclib_cb_log(10LL, "Phys Addr: 0x%X 0x%X", HIDWORD(v13), (unsigned int)v13);
                qtiseclib_cb_log(10LL, "SSD Idx: 0x%X SID: 0x%X", (unsigned int)v14, HIDWORD(v14));
                qtiseclib_cb_log(10LL, "MID: 0x%X AVMID: 0x%X", (unsigned int)v15, HIDWORD(v15));
                qtiseclib_cb_log(10LL, "ATID: 0x%X ABID: 0x%X APID: 0x%X", (unsigned int)v16, HIDWORD(v16), v17);
                vmidmt_ClearError(v10, 1);
              }
              else
              {
                qtiseclib_cb_log(10LL, "VMIDMT ERROR: VMIDMT %d reported no error!!", v9);
              }
            }
          }
          v8 += 2;
        }
        while ( v8 != (char *)&unk_16BF1 );
      }
    }
    while ( v6 <= 0x1F );
  }
  return a3;
}






