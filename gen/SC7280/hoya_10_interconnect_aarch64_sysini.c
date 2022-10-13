/*0000000000000070 t $d
0000000000000000 t $x
0000000000000064 t end_of_function
0000000000000000 T hoya_10_interconnect_aarch64_sysini
0000000000000070 T HOYA_10_SYSINI_VERSION_INTERCONNECT
0000000000000060 t power_down_sequence
000000000000001c t power_up_sequence
*/
#include "hoya_10_interconnect_aarch64_sysini.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall hoya_10_interconnect_aarch64_sysini(__int64 result)
{
  if ( (unsigned __int8)result == 1LL )
  {
    MEMORY[0x1790008C] = MEMORY[0x1790008C] & 0xFFFFFFE0 | 1;
    __dsb(0xFu);
    __isb(0xFu);
    result = 395313284LL;
    MEMORY[0x17900084] &= 0xFFFF00FF;
    __dmb(0xFu);
  }
  __dsb(0xFu);
  __isb(0xFu);
  return result;
}




