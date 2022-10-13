/*0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 T ACQCGetxPUType
                 U cpuss_dmb
                 U cpuss_dsb
                 U cpuss_isb
0000000000000000 T XpuEnableDomains
0000000000000000 T XpuLockDownAssetDynamically
0000000000000000 T XpuLockDownAssets
0000000000000000 T XpuMasterMPuInit
0000000000000000 T XpuProgramMPUPartitions
0000000000000000 T XpuProgramMPUPartitionsDynamicPerm
0000000000000000 T XpuProgramMPUPartitionsPerm
0000000000000000 T XpuSetRGOwnership
*/
#include "xpu3.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall ACQCGetxPUType(__int64 a1)
{
  return *(_DWORD *)(*(_QWORD *)a1 + 1016LL) & 3;
}



__int64 __fastcall XpuEnableDomains(int **a1)
{
  int *v1; // x0
  int v2; // w1

  v1 = *a1;
  if ( !*v1 )
  {
    v2 = 1;
    if ( HIWORD(v1[255]) > 0x3002u )
    {
      v1[256] = 1;
      v2 = 3;
    }
    *v1 = v2;
    v1[4] = 271;
    v1[36] = 271;
    v1[32] = v2;
    v1[68] = 271;
    v1[64] = v2;
  }
  return 0LL;
}



__int64 __fastcall XpuLockDownAssetDynamically(__int64 a1, unsigned __int8 a2, int a3, int a4, int a5, int a6)
{
  __int64 v9; // x1
  __int64 v10; // x19
  __int64 result; // x0
  char v12; // w0

  v9 = a1 + 48LL * a2;
  do
  {
    if ( a1 == v9 )
      return 0xFFFFFFFFLL;
    v10 = a1;
    a1 += 48LL;
  }
  while ( *(_DWORD *)(a1 - 8) != a3 );
  if ( (*(_DWORD *)(v10 + 44) & 2) == 0 )
  {
    result = XpuEnableDomains((int **)v10);
    if ( (_DWORD)result )
      return result;
    *(_DWORD *)(v10 + 44) |= 2u;
  }
  cpuss_dmb();
  cpuss_isb();
  if ( (unsigned __int8)ACQCGetxPUType(v10) != 2
    || (result = XpuProgramMPUPartitions((_QWORD *)v10, a4), !(_DWORD)result) )
  {
    cpuss_dmb();
    cpuss_isb();
    result = XpuSetRGOwnership((_QWORD *)v10, a4);
    if ( !(_DWORD)result )
    {
      v12 = ACQCGetxPUType(v10);
      if ( v12 != 2 || (result = XpuProgramMPUPartitionsDynamicPerm((_QWORD *)v10, a4, a5, a6), !(_DWORD)result) )
      {
        cpuss_dmb();
        cpuss_isb();
        return 0LL;
      }
    }
  }
  return result;
}



__int64 __fastcall XpuLockDownAssets(__int64 a1, unsigned __int8 a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 result; // x0

  v2 = a1;
  v3 = a1 + 48LL * a2;
  while ( v2 != v3 )
  {
    if ( (*(_DWORD *)(v2 + 44) & 1) != 0 )
    {
      result = XpuEnableDomains((int **)v2);
      if ( (_DWORD)result )
        return result;
      cpuss_dmb();
      cpuss_isb();
      *(_DWORD *)(v2 + 44) |= 2u;
      if ( (unsigned __int8)ACQCGetxPUType(v2) == 2 )
      {
        result = XpuProgramMPUPartitions((_QWORD *)v2, 0xFFFFFF);
        if ( (_DWORD)result )
          return result;
      }
      cpuss_dmb();
      cpuss_isb();
      result = XpuSetRGOwnership((_QWORD *)v2, 0xFFFFFF);
      if ( (_DWORD)result )
        return result;
      if ( (unsigned __int8)ACQCGetxPUType(v2) == 2 )
      {
        result = XpuProgramMPUPartitionsPerm((_QWORD *)v2, 0xFFFFFF);
        if ( (_DWORD)result )
          return result;
      }
    }
    v2 += 48LL;
  }
  cpuss_dsb();
  cpuss_isb();
  return 0LL;
}



__int64 __fastcall XpuMasterMPuInit(__int64 a1, unsigned int a2)
{
  unsigned __int8 *v2; // x4
  unsigned __int8 *v3; // x6
  unsigned int v4; // w12
  __int64 v5; // x10
  unsigned int v6; // w7
  unsigned int v7; // w11
  int v8; // w3
  int **v9; // x0
  unsigned __int64 v10; // x9
  unsigned int v11; // w8
  int v12; // w2
  unsigned int v13; // w13
  __int64 v14; // x1
  unsigned __int64 v15; // x8
  unsigned int v16; // w1
  int i; // w3
  unsigned int v18; // w9
  unsigned __int64 v19; // x13
  unsigned __int64 v20; // x15
  __int64 result; // x0
  __int64 v22; // x5

  v2 = (unsigned __int8 *)(a1 + 4);
  v3 = (unsigned __int8 *)(a1 + 16LL * a2 + 4);
  v4 = 24;
  v5 = 0xFFFFFFFFLL;
  while ( v2 != v3 )
  {
    v6 = 0;
    v7 = 48;
    while ( v6 < *v2 )
    {
      v8 = *((unsigned __int16 *)v2 + 1);
      v9 = (int **)(*(_QWORD *)(v2 + 4) + v6 * (unsigned __int64)v7);
      v10 = (unsigned __int64)v9[1];
      v11 = v10 - v8;
      v12 = (HIWORD((*v9)[254]) & 0x3FF) - v8 + 1;
      while ( 1 )
      {
        v13 = v11 + v12;
        if ( v10 <= v11 )
          break;
        v14 = 4LL * v11++;
        *(_QWORD *)&v9[2][v14] = v8 - (_DWORD)v10 + v13;
      }
      v15 = (unsigned __int64)v9[3];
      v16 = v15 - v8;
      for ( i = v8 - v15; ; *(_DWORD *)v20 = i + v18 )
      {
        v18 = v16 + v12;
        if ( v15 <= v16 )
          break;
        v19 = v16++ * (unsigned __int64)v4;
        v20 = (unsigned __int64)v9[4] + v19;
        *(_QWORD *)(v20 + 8) = v5;
        *(_QWORD *)(v20 + 16) = v5;
      }
      if ( (*((_DWORD *)v9 + 11) & 2) == 0 )
      {
        result = XpuEnableDomains(v9);
        if ( (_DWORD)result )
          return result;
        *(_DWORD *)(*(_QWORD *)(v2 + 4) + v22 + 44) |= 2u;
      }
      ++v6;
    }
    v2 += 16;
  }
  return 0LL;
}



__int64 __fastcall XpuProgramMPUPartitions(_QWORD *a1, int a2)
{
  __int64 v2; // x5
  __int64 i; // x2
  __int64 v4; // x3
  __int64 v5; // x6
  unsigned __int64 v6; // x3

  v2 = 24LL * a1[3];
  for ( i = 0LL; i != v2; i += 24LL )
  {
    v4 = a1[4];
    if ( a2 == 0xFFFFFF || a2 == *(_DWORD *)(v4 + i) )
    {
      v5 = v4 + i;
      v6 = ((unsigned __int64)(*(_DWORD *)(v4 + i) & 0x1FFFFFF) << 7) + *a1;
      *(_QWORD *)(v6 + 4144) = *(_QWORD *)(v5 + 8);
      *(_QWORD *)(v6 + 4152) = *(_QWORD *)(v5 + 16);
    }
  }
  return 0LL;
}



__int64 __fastcall XpuProgramMPUPartitionsDynamicPerm(_QWORD *a1, int a2, int a3, int a4)
{
  __int64 v4; // x6
  __int64 i; // x4
  __int64 v6; // x5
  unsigned __int64 v7; // x5

  v4 = 24LL * a1[3];
  for ( i = 0LL; i != v4; i += 24LL )
  {
    v6 = a1[4];
    if ( a2 == 0xFFFFFF || a2 == *(_DWORD *)(v6 + i) )
    {
      v7 = ((unsigned __int64)(*(_DWORD *)(v6 + i) & 0x1FFFFFF) << 7) + *a1;
      *(_DWORD *)(v7 + 4116) = a3;
      *(_DWORD *)(v7 + 4124) = a4;
    }
  }
  return 0LL;
}



__int64 __fastcall XpuProgramMPUPartitionsPerm(_QWORD *a1, int a2)
{
  __int64 v2; // x4
  __int64 i; // x2
  _DWORD *v4; // x5
  _DWORD *v5; // x3
  _DWORD *v6; // x1
  _DWORD *v7; // x0

  v2 = a1[3];
  for ( i = 0LL; v2 != i; ++i )
  {
    if ( a2 == 0xFFFFFF || a2 == *(_DWORD *)(a1[4] + 24 * i) )
    {
      v4 = (_DWORD *)(a1[2] + 16 * i);
      if ( *v4 != 16777214 )
      {
        if ( *((_QWORD *)v4 + 1) )
        {
          v5 = (_DWORD *)(((unsigned __int64)(*(_DWORD *)(a1[4] + 24 * i) & 0x1FFFFFF) << 7) + *a1);
          v5[1029] = v4[2];
          v5[1031] = v4[3];
          if ( (v4[2] & 0x101) != 0 )
            v5[1028] = 1;
          if ( (v4[3] & 0x101) != 0 )
            v5[1030] = 1;
        }
      }
    }
  }
  v6 = (_DWORD *)(a1[2] + 16 * v2);
  if ( *v6 == 16777214 && *((_QWORD *)v6 + 1) )
  {
    v7 = (_DWORD *)*a1;
    v7[197] = v6[2];
    v7[199] = v6[3];
    if ( (v6[2] & 0x101) != 0 )
      v7[196] = 1;
    if ( (v6[3] & 0x101) != 0 )
      v7[198] = 1;
  }
  return 0LL;
}



__int64 __fastcall XpuSetRGOwnership(_QWORD *a1, int a2)
{
  __int64 v2; // x6
  __int64 i; // x3
  int *v4; // x5
  int v5; // w2

  v2 = a1[1];
  for ( i = 0LL; v2 != i; ++i )
  {
    v4 = (int *)(a1[2] + 16 * i);
    v5 = *v4;
    if ( *v4 == 16777214 )
    {
      *(_DWORD *)(*a1 + 768LL) = v4[1];
    }
    else if ( v5 == a2 || a2 == 0xFFFFFF )
    {
      *(_DWORD *)(*a1 + 4096LL + ((unsigned __int64)(v5 & 0x1FFFFFF) << 7)) = v4[1];
    }
  }
  return 0LL;
}



