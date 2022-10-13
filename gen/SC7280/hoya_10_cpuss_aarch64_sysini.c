/*00000000000003b8 t $d
0000000000000000 t $x
00000000000003a8 t end_of_function
0000000000000000 T hoya_10_cpuss_aarch64_por_sysini
000000000000040c T HOYA_10_SYSINI_VERSION_CPUSS
00000000000002bc t l_763985_exit
0000000000000280 t l_763985_start
0000000000000250 t l_764609_exit
0000000000000230 t l_764609_start
000000000000030c t l_876346_exit
00000000000002ec t l_876346_start
000000000000032c t l_en_gnoc_ext_access
000000000000034c t l_en_gnoc_ext_access_exit
0000000000000210 t l_late_cancel_enable_exit
00000000000001f0 t l_late_cancel_enable_start
00000000000001d0 t l_mem_svs_enable_start
00000000000001f0 t l_mem_svs_exit
000000000000036c t l_SDM845_spi_cfg_start
00000000000003a0 t l_spi_cfg_exit
00000000000003a4 t power_down_sequence
000000000000001c t power_up_sequence
00000000000003b8 t SPI_CONFIGURATION_DATA_SDM845
*/
#include "hoya_10_cpuss_aarch64_sysini.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall hoya_10_cpuss_aarch64_por_sysini(__int64 result)
{
  int v1; // w2
  unsigned __int64 v2; // x4

  if ( (unsigned __int8)result == 1LL )
  {
    MEMORY[0x17E00058] = 9615380;
    MEMORY[0x17E00060] = MEMORY[0x17E00060] & 0xFFFFFFFD | 2;
    MEMORY[0x17E10058] = 9615380;
    MEMORY[0x17E10060] = MEMORY[0x17E10060] & 0xFFFFFFFD | 2;
    MEMORY[0x17E60058] = 9615380;
    MEMORY[0x17E60060] = MEMORY[0x17E60060] & 0xFFFFFFFD | 2;
    MEMORY[0x17E70058] = 9615380;
    MEMORY[0x17E70060] = MEMORY[0x17E70060] & 0xFFFFFFFD | 2;
    MEMORY[0x17E20058] = 9615380;
    MEMORY[0x17E20060] = MEMORY[0x17E20060] & 0xFFFFFFFD | 2;
    MEMORY[0x17E30058] = 9615380;
    MEMORY[0x17E30060] = MEMORY[0x17E30060] & 0xFFFFFFFD | 2;
    MEMORY[0x17E40058] = 9615380;
    MEMORY[0x17E40060] = MEMORY[0x17E40060] & 0xFFFFFFFD | 2;
    MEMORY[0x17E50058] = 9615380;
    MEMORY[0x17E50060] = MEMORY[0x17E50060] & 0xFFFFFFFD | 2;
    MEMORY[0x17810058] = MEMORY[0x17810058] & 0xFFFC0000 | 0x2004;
    MEMORY[0x17810068] = MEMORY[0x17810068] & 0xFFFC0000 | 0x2008;
    MEMORY[0x1781005C] = MEMORY[0x1781005C] & 0xFFFC0000 | 0x2008;
    MEMORY[0x17810060] = MEMORY[0x17810060] & 0xFFFC0000 | 0x2008;
    MEMORY[0x17810064] = MEMORY[0x17810064] & 0xFFFC0000 | 0x2008;
    MEMORY[0x17810054] = MEMORY[0x17810054] & 0xFFFFFC00 | 0x282;
    if ( (MEMORY[0x1FC8000] | 0xFFFF) == 1610678271LL )
    {
      MEMORY[0x17990174] = MEMORY[0x17990174] & 0xFFFFFFFE | 1;
      __dmb(0xFu);
    }
    MEMORY[0x1799001C] &= ~0x800u;
    __dmb(0xFu);
    if ( (MEMORY[0x1FC8000] | 0xFF) == 1610613247 )
    {
      MEMORY[0x17A00020] = MEMORY[0x17A00020] & 0xFFBFFFFF | 0x400000;
      __dmb(0xFu);
    }
    if ( (MEMORY[0x1FC8000] | 0xFF) == 1610613247 || (MEMORY[0x1FC8000] | 0xFF) == 1610613503 )
    {
      MEMORY[0x17A00020] = MEMORY[0x17A00020] & 0xFFEFFFFF | 0x100000;
      __dmb(0xFu);
      MEMORY[0x17A00020] = MEMORY[0x17A00020] & 0xFFF7FFFF | 0x80000;
      __dmb(0xFu);
    }
    if ( (MEMORY[0x1FC8000] | 0xFF) == 1610613247 || (MEMORY[0x1FC8000] | 0xFF) == 1610613503 )
    {
      MEMORY[0x17A00020] = MEMORY[0x17A00020] & 0xFF7FFFFF | 0x800000;
      __dmb(0xFu);
    }
    if ( (MEMORY[0x1FC8000] | 0xFFFF) == 1610678271 )
    {
      MEMORY[0x17990028] &= ~0x20u;
      __dmb(0xFu);
    }
    result = 33325056LL;
    if ( (MEMORY[0x1FC8000] | 0xFFFF) == 1610678271 )
    {
      result = 395903216LL;
      v1 = 20;
      v2 = (unsigned __int64)&SPI_CONFIGURATION_DATA_SDM845;
      do
      {
        *(_DWORD *)result &= ~*(_DWORD *)v2;
        result = (unsigned int)(result + 4);
        v2 = (unsigned int)(v2 + 4);
        --v1;
      }
      while ( v1 >= 0 );
    }
  }
  __dsb(0xFu);
  __isb(0xFu);
  return result;
}




