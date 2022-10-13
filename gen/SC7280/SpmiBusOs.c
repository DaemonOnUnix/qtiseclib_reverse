/*0000000000000000 b $d
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t debugExecute.part.3
0000000000000000 T SpmiBus_DeInit
0000000000000000 T SpmiBus_Init
0000000000000000 T SpmiBus_ReadLong
0000000000000000 T SpmiBus_WriteLong
0000000000000000 B spmiDrv
                 U SpmiOs_Init
                 U SpmiOs_Wait
*/
#include "SpmiBusOs.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 SpmiBus_DeInit()
{
  spmiDrv[0] = 0;
  return 0LL;
}



__int64 SpmiBus_Init()
{
  __int64 result; // x0
  __int64 v1; // x0
  unsigned __int16 **v2; // x0
  unsigned __int16 *v3; // x1
  unsigned int v4; // w3
  unsigned int i; // w0
  unsigned __int64 v6; // x2
  __int64 v7; // x2

  result = 0LL;
  if ( !spmiDrv[0] )
  {
    result = SpmiOs_Init(&qword_316C8);
    if ( !(_DWORD)result )
    {
      v1 = qword_316C8;
      *(_BYTE *)(qword_316C8 + 1) = 0;
      v2 = *(unsigned __int16 ***)(v1 + 24);
      v3 = *v2;
      if ( (*((_DWORD *)*v2 + 5259264) & 0x400) == 0 )
      {
        v4 = *v2[5];
        for ( i = 0; i < v4; ++i )
        {
          v6 = (unsigned __int64)(unsigned __int16)i << 16;
          *(_DWORD *)((char *)v3 + v6 + 23068936) = 255;
          *(_DWORD *)((char *)v3 + v6 + 23068928) = 0;
          v7 = 2LL * (i & 0x3FFFFFFF);
          *(_DWORD *)&v3[v7 + 10507136] = 0;
          *(_DWORD *)&v3[v7 + 10617984] = 0;
        }
        *((_DWORD *)v3 + 5253120) &= ~1u;
        *((_DWORD *)v3 + 5253124) |= 1u;
        *((_DWORD *)v3 + 5253120) |= 1u;
        *((_DWORD *)v3 + 5254082) |= 1u;
        *((_DWORD *)v3 + 5253125) |= 3u;
        *((_DWORD *)v3 + 5254080) &= 0xFFFFFFFC;
        *((_DWORD *)v3 + 5254081) |= 0x800u;
        *((_DWORD *)v3 + 5254081) |= 0x200u;
        *((_DWORD *)v3 + 5254081) |= 0x100u;
        *((_DWORD *)v3 + 5254081) |= 0x80u;
        *((_DWORD *)v3 + 5254081) |= 0x20u;
        *((_DWORD *)v3 + 5254081) |= 8u;
        *((_DWORD *)v3 + 5254081) |= 1u;
        *((_DWORD *)v3 + 5308420) |= 1u;
        *((_DWORD *)v3 + 5254081) &= ~2u;
      }
      spmiDrv[0] = 1;
      return 0LL;
    }
  }
  return result;
}



__int64 __fastcall SpmiBus_ReadLong(char a1, int a2, int a3, char *a4, unsigned int a5, __int64 *a6)
{
  if ( spmiDrv[0] )
    return debugExecute_part_3(1, a2, a1, a3, a4, a5, a6);
  else
    return 14LL;
}



__int64 __fastcall SpmiBus_WriteLong(char a1, int a2, int a3, char *a4, unsigned int a5)
{
  if ( spmiDrv[0] )
    return debugExecute_part_3(0, a2, a1, a3, a4, a5, 0LL);
  else
    return 14LL;
}



