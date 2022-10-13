/*00000000000003a0 t $d
0000000000000000 t $x
0000000000000220 t apply_mibu_scid_qos_config
0000000000000390 t end_of_function
0000000000000000 T hoya_20_cpuss_aarch64_por_sysini
0000000000000350 t l_disable_MIBU_snoop_counter_begin
0000000000000388 t l_disable_MIBU_snoop_counter_end
0000000000000370 t l_disable_MIBU_snoop_counter_start
00000000000002f8 t l_Enable_Formal_fix_for_MIBU_begin
0000000000000328 t l_Enable_Formal_fix_for_MIBU_end
00000000000002fc t l_Enable_Formal_fix_for_MIBU_start
0000000000000200 t l_en_gic_fault_err_intr_exit
00000000000001a4 t l_en_gic_fault_err_intr_start
00000000000000cc t l_fal10_feature_enable_exit
00000000000000b4 t l_fal10_feature_enable_start
00000000000002c4 t l_SC7280_spi_cfg_start
0000000000000184 t l_set_mibu_qos_ctl_end
000000000000016c t l_set_mibu_qos_ctl_start
00000000000002f8 t l_spi_cfg_exit
0000000000000328 t l_TESTBUS_MUX_EN_begin
0000000000000350 t l_TESTBUS_MUX_EN_end
0000000000000338 t l_TESTBUS_MUX_EN_start
000000000000038c t power_down_sequence
000000000000001c t power_up_sequence
00000000000002a4 t skip_mibu_scid_qos_config
00000000000003a0 t SPI_CONFIGURATION_DATA_SC7280
*/
#include "hoya_20_cpuss_aarch64_sysini.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall hoya_20_cpuss_aarch64_por_sysini(__int64 result)
{
  __int64 v1; // x2
  __int64 v2; // x5
  __int64 v3; // x6
  __int64 i; // x7
  __int64 v5; // x0
  int v6; // w2
  unsigned __int64 v7; // x4

  if ( (unsigned __int8)result == 1LL )
  {
    v1 = MEMORY[0x17E0002C];
    v2 = 402653272LL;
    v3 = 402653280LL;
    for ( i = 1LL; (i & v1) != 0; i *= 2LL )
    {
      *(_QWORD *)v2 = 11538461LL;
      *(_DWORD *)v3 = *(_DWORD *)v3 & 0xFFFFFFFD | 2;
      v2 += 0x10000LL;
      v3 += 0x10000LL;
    }
    MEMORY[0x17E0041C] = 9615380;
    MEMORY[0x17E00434] = MEMORY[0x17E00434] & 0xFFFFFFFE | 1;
    __dmb(0xFu);
    if ( (MEMORY[0x1FC8000] | 0xFFFF) == 1612251135LL )
      MEMORY[0x180801C4] = MEMORY[0x180801C4] & 0xFFFFFFF8 | 3;
    MEMORY[0x18080058] = MEMORY[0x18080058] & 0xFFFC0000 | 0x2004;
    MEMORY[0x18080068] = MEMORY[0x18080068] & 0xFFFC0000 | 0x2008;
    MEMORY[0x1808005C] = MEMORY[0x1808005C] & 0xFFFC0000 | 0x2008;
    MEMORY[0x18080060] = MEMORY[0x18080060] & 0xFFFC0000 | 0x2008;
    MEMORY[0x18080064] = MEMORY[0x18080064] & 0xFFFC0000 | 0x2008;
    MEMORY[0x18080054] = MEMORY[0x18080054] & 0xFFFFFC00 | 0x282;
    if ( (MEMORY[0x1FC8000] | 0xFFFF) == 1612251135 )
    {
      MEMORY[0x17A20048] = MEMORY[0x17A20048] & 0xFFFFFEFF | 0x100;
      __dmb(0xFu);
      MEMORY[0x17A20088] = MEMORY[0x17A20088] & 0xFFFFFFF7 | 8;
      __dmb(0xFu);
      MEMORY[0x17A20088] = MEMORY[0x17A20088] & 0xFFFFFFFB | 4;
      __dmb(0xFu);
    }
    if ( (MEMORY[0x1FC8000] | 0xFFFF) == 1612251135 )
    {
      MEMORY[0x17E00458] &= ~0x2000000u;
      MEMORY[0x17E00458] = MEMORY[0x17E00458] & 0x83FFFFFF | 0x14000000;
      MEMORY[0x17E00458] = MEMORY[0x17E00458] & 0xFFFFFFE0 | 1;
      MEMORY[0x17E0045C] &= 0xFFFFFFF0;
      MEMORY[0x17E00230] = MEMORY[0x17E00230] & 0xFFFEFFFF | 0x10000;
      MEMORY[0x17E00230] = MEMORY[0x17E00230] & 0xF0FFFFFF | 0x1000000;
      v5 = 398459120LL;
      v6 = 24;
      v7 = (unsigned __int64)&SPI_CONFIGURATION_DATA_SC7280;
      do
      {
        *(_DWORD *)v5 &= ~*(_DWORD *)v7;
        v5 = (unsigned int)(v5 + 4);
        v7 = (unsigned int)(v7 + 4);
        --v6;
      }
      while ( v6 >= 0 );
    }
    result = 33325056LL;
    if ( (MEMORY[0x1FC8000] | 0xFFFF) == 1612251135 )
    {
      result = 400556600LL;
      MEMORY[0x17E00238] = MEMORY[0x17E00238] & 0xFFFFFFFB | 4;
    }
  }
  __dsb(0xFu);
  __isb(0xFu);
  return result;
}



