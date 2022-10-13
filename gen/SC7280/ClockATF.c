/*0000000000000000 b $d
0000000000000000 b $d
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 b bSSCGDSCPrevEnabled
                 U Clock_DisableClockGroup
                 U Clock_EnableClockGroup
                 U Clock_EnableSource
0000000000000000 T Clock_InitImage
0000000000000000 T Clock_PostInitImage
0000000000000000 B nMPSSQ6DbgVal
                 U qtiseclib_cb_udelay
*/
#include "ClockATF.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall Clock_InitImage(__int64 a1)
{
  __int64 v1; // x20
  unsigned int v2; // w21
  int v3; // w20

  v1 = *(_QWORD *)(*(_QWORD *)a1 + 24LL) + 40LL;
  MEMORY[0x171154] = MEMORY[0x171154] & 0x81F0000E | 1;
  while ( (MEMORY[0x171154] & 0x80000000) != 0 )
    qtiseclib_cb_udelay(1LL);
  Clock_EnableClockGroup(2u);
  Clock_EnableClockGroup(3u);
  if ( (MEMORY[0x339B024] & 1) != 0 )
  {
    bSSCGDSCPrevEnabled = 0;
    MEMORY[0x339B024] &= 0xF8FFFFFE;
    __dsb(0xFu);
    while ( (MEMORY[0x339B030] & 1) == 0 )
      ;
    while ( (MEMORY[0x380101C] & 0x80000000) != 0 )
      ;
  }
  else
  {
    bSSCGDSCPrevEnabled = 1;
  }
  Clock_EnableClockGroup(4u);
  MEMORY[0x3D91098] = MEMORY[0x3D91098] & 0x81E07FFC | 1;
  MEMORY[0x3D91204] = MEMORY[0x3D91204] & 0x81E0000C | 1;
  MEMORY[0x3D9E110] |= 1u;
  MEMORY[0x3D9E110] &= ~1u;
  MEMORY[0x3D9E110] &= ~1u;
  MEMORY[0x3D9E110] &= ~1u;
  MEMORY[0x3D9E110] &= ~1u;
  MEMORY[0x3D9E110] &= ~1u;
  MEMORY[0x3D91074] = MEMORY[0x3D91074] & 0x7FFF0 | 1;
  MEMORY[0x3D9106C] &= 0xF8FFFFFE;
  while ( (MEMORY[0x3D9106C] & 0x80000000) == 0 )
    ;
  MEMORY[0x3D91510] = 2;
  MEMORY[0x3D9E120] = MEMORY[0x3D9E120] & 0xFFFFFE00 | 0x1F4;
  MEMORY[0x3D91014] = MEMORY[0x3D91014] & 0x7FF0F | 0x70;
  MEMORY[0x3D91008] = 1;
  MEMORY[0x3D91160] = 1;
  MEMORY[0x3D98004] = 1;
  qtiseclib_cb_udelay(150LL);
  MEMORY[0x3D91008] = 0;
  MEMORY[0x3D91160] = 0;
  MEMORY[0x3D98004] = 0;
  MEMORY[0x3D9158C] = MEMORY[0x3D9158C] & 0x3C0001 | 0x10;
  qtiseclib_cb_udelay(1LL);
  MEMORY[0x3D9158C] &= 0x3C0001u;
  MEMORY[0x3D9158C] &= 0x3C0010u;
  MEMORY[0x3D9100C] &= 0xF8FFFFFE;
  while ( (MEMORY[0x3D9100C] & 0x80000000) == 0 )
    ;
  MEMORY[0x3D94004] &= 0x3000800u;
  MEMORY[0x3D94000] &= 0x3000800u;
  MEMORY[0x106100] &= ~4u;
  MEMORY[0x153000] = MEMORY[0x153000] & 2;
  MEMORY[0x15301C] = MEMORY[0x15301C] & 2;
  MEMORY[0x153018] = MEMORY[0x153018] & 2;
  MEMORY[0x153010] = MEMORY[0x153010] & 2;
  MEMORY[0x153014] = MEMORY[0x153014] & 2;
  MEMORY[0x153008] = MEMORY[0x153008] & 2;
  MEMORY[0x153004] = MEMORY[0x153004] & 2;
  MEMORY[0x106100] |= 0x800u;
  MEMORY[0x153000] = MEMORY[0x153000] & 1 | 2;
  MEMORY[0x15301C] = MEMORY[0x15301C] & 1 | 2;
  MEMORY[0x153010] = MEMORY[0x153010] & 1 | 2;
  MEMORY[0x153014] = MEMORY[0x153014] & 1 | 2;
  MEMORY[0x153008] = MEMORY[0x153008] & 1 | 2;
  MEMORY[0x153004] = MEMORY[0x153004] & 1 | 2;
  MEMORY[0x153018] = MEMORY[0x153018] & 1 | 2;
  MEMORY[0x3D94004] = MEMORY[0x3D94004] & 0x3000004 | 0x800;
  MEMORY[0x3D94000] = MEMORY[0x3D94000] & 0x3000004 | 0x800;
  MEMORY[0x190004] = MEMORY[0x190004] & 0x81F03FFF | 0x4000;
  MEMORY[0x190010] = MEMORY[0x190010] & 0x81F03FFE | 0x4000;
  MEMORY[0x190020] = MEMORY[0x190020] & 0x81F03FFF | 0x4000;
  MEMORY[0x190028] = MEMORY[0x190028] & 0x81F03FFF | 0x4000;
  MEMORY[0x183008] = MEMORY[0x183008] & 0x81F03FFF | 0x4000;
  MEMORY[0x17100C] = MEMORY[0x17100C] & 0x81F03FFF | 0x4000;
  v2 = Clock_EnableSource(v1);
  if ( v2 )
  {
    return (unsigned int)-1;
  }
  else
  {
    v3 = 500;
    MEMORY[0x1FD3300] = 1;
    MEMORY[0x18A2A4] = 0;
    MEMORY[0x18A00C] &= 0x81F0000E;
    MEMORY[0x18A000] = MEMORY[0x18A000] & 0x81F0000E | 1;
    if ( (MEMORY[0x18A000] & 2) == 0 )
    {
      while ( (MEMORY[0x18A000] & 0x80000000) != 0 )
      {
        qtiseclib_cb_udelay(1LL);
        if ( !--v3 )
          return v2;
      }
    }
    MEMORY[0x4180044] = 1;
    qtiseclib_cb_udelay(100LL);
    MEMORY[0xC2B0000] |= 1u;
    qtiseclib_cb_udelay(300LL);
    MEMORY[0xC2B0000] &= ~1u;
    qtiseclib_cb_udelay(100LL);
    MEMORY[0x4180044] = 0;
    MEMORY[0x18A000] &= 0x81F0000E;
    MEMORY[0x3D9152C] = 0;
  }
  return v2;
}



__int64 Clock_PostInitImage()
{
  MEMORY[0x3D9100C] = MEMORY[0x3D9100C] & 0xF8FFFFFE | 1;
  MEMORY[0x3D98004] = 1;
  qtiseclib_cb_udelay(150LL);
  MEMORY[0x3D9158C] = MEMORY[0x3D9158C] & 0x3C0010 | 1;
  while ( (MEMORY[0x3D9100C] & 0x80000000) != 0 )
    ;
  MEMORY[0x3D9106C] = MEMORY[0x3D9106C] & 0xF8FFFFFE | 1;
  while ( (MEMORY[0x3D9106C] & 0x80000000) != 0 )
    ;
  Clock_DisableClockGroup(4u);
  if ( !bSSCGDSCPrevEnabled )
  {
    MEMORY[0x339B024] = MEMORY[0x339B024] & 0xF8FFFFFE | 1;
    __dsb(0xFu);
    while ( (MEMORY[0x339B024] & 0x80000000) != 0 )
      ;
  }
  Clock_DisableClockGroup(3u);
  Clock_DisableClockGroup(2u);
  return 0LL;
}



