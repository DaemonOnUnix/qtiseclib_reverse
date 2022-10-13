/*0000000000000000 t $x
0000000000000000 T Tlmm_PlatformInit
*/
#include "tlmm_platform.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 Tlmm_PlatformInit()
{
  __int64 result; // x0

  result = 0xFFFFFFFFLL;
  MEMORY[0xF1AF00C] = -1;
  MEMORY[0xF1AF010] = -1;
  MEMORY[0xF1AF014] = -1;
  MEMORY[0xF1AF018] = -1;
  MEMORY[0xF1AF000] = -1;
  MEMORY[0xF1AF004] = -1;
  MEMORY[0xF1AF008] = -1;
  return result;
}



