/*0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 T interconnect_enable_ns_register_access
0000000000000000 T sec_core
0000000000000000 T set_boot_remap
*/
#include "sec_core.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

__int64 sec_core()
{
  __int64 result; // x0

  result = 1LL;
  MEMORY[0x17C10000] = 1;
  MEMORY[0x18000000] = 1;
  MEMORY[0x18010000] = 1;
  MEMORY[0x18020000] = 1;
  MEMORY[0x18030000] = 1;
  MEMORY[0x18040000] = 1;
  MEMORY[0x18050000] = 1;
  MEMORY[0x18060000] = 1;
  MEMORY[0x18070000] = 1;
  MEMORY[0x18080000] = 1;
  MEMORY[0x17800000] = 1;
  MEMORY[0x17E00004] = 0;
  MEMORY[0x18101C00] = 7;
  MEMORY[0x18100C00] = 7;
  MEMORY[0x18300024] = 3;
  MEMORY[0x18300028] = 15;
  MEMORY[0x18282040] = 3;
  MEMORY[0x18280040] = 3;
  MEMORY[0x18284040] = 3;
  MEMORY[0x182A0004] = 1;
  return result;
}



unsigned __int64 __fastcall set_boot_remap(unsigned __int64 a1)
{
  unsigned __int64 v1; // x2
  unsigned __int64 result; // x0

  v1 = a1 >> 2;
  result = a1 >> 34;
  MEMORY[0x17E0001C] = v1;
  MEMORY[0x17E00020] = result;
  return result;
}



