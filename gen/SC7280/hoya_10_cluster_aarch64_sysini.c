/*00000000000000dc t $d
0000000000000000 t $x
00000000000000d0 t end_of_function
0000000000000000 T hoya_10_cluster_aarch64_sysini
00000000000000dc T HOYA_10_SYSINI_VERSION_CLUSTER
00000000000000ac t l_798953_exit
0000000000000098 t l_798953_start
00000000000000b4 t power_down_sequence
00000000000000c8 t power_down_sequence_primary_cluster
00000000000000cc t power_down_sequence_secondary_cluster
0000000000000028 t power_up_sequence
000000000000003c t power_up_sequence_primary_cluster
00000000000000b0 t power_up_sequence_secondary_cluster
*/
#include "hoya_10_cluster_aarch64_sysini.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
unsigned __int64 __fastcall hoya_10_cluster_aarch64_sysini(unsigned __int64 result)
{
  if ( (unsigned __int8)result == 1LL && !((unsigned __int64)((unsigned __int16)result & 0xFF00) >> 8) )
  {
    _WriteStatusReg(
      ARM64_SYSREG(3, 0, 15, 3, 4),
      _ReadStatusReg(ARM64_SYSREG(3, 0, 15, 3, 4)) & 0xFFFFFFFFFFFFBFFFLL | 0x4000);
    __isb(0xFu);
    _WriteStatusReg(
      ARM64_SYSREG(3, 0, 15, 3, 4),
      _ReadStatusReg(ARM64_SYSREG(3, 0, 15, 3, 4)) & 0xFFFFFFFFFFFFFFFELL | 1);
    __isb(0xFu);
    _WriteStatusReg(
      ARM64_SYSREG(3, 0, 15, 3, 4),
      _ReadStatusReg(ARM64_SYSREG(3, 0, 15, 3, 4)) & 0xFFFFFFFFFFFFFFF7LL | 8);
    __isb(0xFu);
    result = 33325056LL;
    if ( (MEMORY[0x1FC8000] | 0xFF) == 1610613247 )
    {
      result = _ReadStatusReg(ARM64_SYSREG(3, 0, 15, 3, 3)) & 0xFFFFFFFFFFFF7FFFLL | 0x8000;
      _WriteStatusReg(ARM64_SYSREG(3, 0, 15, 3, 3), result);
      __isb(0xFu);
    }
  }
  __dsb(0xFu);
  __isb(0xFu);
  return result;
}




