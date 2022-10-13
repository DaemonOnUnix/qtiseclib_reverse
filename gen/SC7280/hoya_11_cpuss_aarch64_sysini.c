/*00000000000002a8 t $d
0000000000000308 t $d
0000000000000000 t $x
0000000000000304 t $x
0000000000000298 t end_of_function
0000000000000000 T hoya_11_cpuss_aarch64_por_sysini
0000000000000308 T HOYA_11_SYSINI_VERSION_CPUSS
00000000000001b0 t l_aux_clk_on_enable_exit
0000000000000190 t l_aux_clk_on_enable_start
0000000000000050 t l_end_config_core0
0000000000000078 t l_end_config_core1
00000000000000a0 t l_end_config_core2
00000000000000c8 t l_end_config_core3
00000000000000f0 t l_end_config_core4
0000000000000118 t l_end_config_core5
0000000000000140 t l_end_config_core6
0000000000000168 t l_end_config_core7
000000000000025c t l_SC7180_spi_cfg_start
0000000000000290 t l_spi_cfg_exit
0000000000000294 t power_down_sequence
000000000000001c t power_up_sequence
00000000000002a8 t SPI_CONFIGURATION_DATA_SC7180
*/
#include "hoya_11_cpuss_aarch64_sysini.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall hoya_11_cpuss_aarch64_por_sysini(__int64 result)
{
  if ( (unsigned __int8)result == 1LL )
  {
    if ( (MEMORY[0x17E00024] & 1) != 0 )
    {
      MEMORY[0x18000058] = 9615380;
      MEMORY[0x18000060] = MEMORY[0x18000060] & 0xFFFFFFFD | 2;
    }
    if ( (MEMORY[0x17E00024] & 2) != 0 )
    {
      MEMORY[0x18010058] = 9615380;
      MEMORY[0x18010060] = MEMORY[0x18010060] & 0xFFFFFFFD | 2;
    }
    if ( (MEMORY[0x17E00024] & 4) != 0 )
    {
      MEMORY[0x18020058] = 9615380;
      MEMORY[0x18020060] = MEMORY[0x18020060] & 0xFFFFFFFD | 2;
    }
    if ( (MEMORY[0x17E00024] & 8) != 0 )
    {
      MEMORY[0x18030058] = 9615380;
      MEMORY[0x18030060] = MEMORY[0x18030060] & 0xFFFFFFFD | 2;
    }
    if ( (MEMORY[0x17E00024] & 0x10) != 0 )
    {
      MEMORY[0x18040058] = 9615380;
      MEMORY[0x18040060] = MEMORY[0x18040060] & 0xFFFFFFFD | 2;
    }
    if ( (MEMORY[0x17E00024] & 0x20) != 0 )
    {
      MEMORY[0x18050058] = 9615380;
      MEMORY[0x18050060] = MEMORY[0x18050060] & 0xFFFFFFFD | 2;
    }
    if ( (MEMORY[0x17E00024] & 0x40) != 0 )
    {
      MEMORY[0x18060058] = 9615380;
      MEMORY[0x18060060] = MEMORY[0x18060060] & 0xFFFFFFFD | 2;
    }
    if ( (MEMORY[0x17E00024] & 0x80) != 0 )
    {
      MEMORY[0x18070058] = 9615380;
      MEMORY[0x18070060] = MEMORY[0x18070060] & 0xFFFFFFFD | 2;
    }
    MEMORY[0x17E0041C] = 9615380;
    MEMORY[0x17E00434] = MEMORY[0x17E00434] & 0xFFFFFFFE | 1;
    MEMORY[0x18080058] = MEMORY[0x18080058] & 0xFFFC0000 | 0x2004;
    MEMORY[0x18080068] = MEMORY[0x18080068] & 0xFFFC0000 | 0x2008;
    MEMORY[0x1808005C] = MEMORY[0x1808005C] & 0xFFFC0000 | 0x2008;
    MEMORY[0x18080060] = MEMORY[0x18080060] & 0xFFFC0000 | 0x2008;
    MEMORY[0x18080064] = MEMORY[0x18080064] & 0xFFFC0000 | 0x2008;
    MEMORY[0x18080054] = MEMORY[0x18080054] & 0xFFFFFC00 | 0x282;
    result = 33325056LL;
  }
  __dsb(0xFu);
  __isb(0xFu);
  return result;
}




