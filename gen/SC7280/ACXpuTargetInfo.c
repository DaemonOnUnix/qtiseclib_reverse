/*0000000000000000 r $d
0000000000000000 d $d
0000000000000000 d $d
0000000000000000 d $d
0000000000000000 r $d
0000000000000000 r $d
0000000000000000 r $d
0000000000000000 t $x
0000000000000000 T ACTzTargetConfig
0000000000000000 D g_xpu_base_addr_array
0000000000000000 D g_xpu_base_addr_array_count
0000000000000000 D xpu_err_pos_to_hal_map
0000000000000000 R xpu_non_sec_intr_en_reg
0000000000000000 R xpu_non_sec_intr_status_reg
0000000000000000 R xpu_sec_intr_en_reg
0000000000000000 R xpu_sec_intr_status_reg
*/
#include "ACXpuTargetInfo.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 ACTzTargetConfig()
{
  __int64 result; // x0

  result = 31457288LL;
  MEMORY[0x1E00008] = 271;
  return result;
}



