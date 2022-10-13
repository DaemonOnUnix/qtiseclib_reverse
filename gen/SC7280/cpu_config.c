/*0000000000000000 d $d
0000000000000000 d $d
0000000000000000 t $x
0000000000000000 T calculate_cpumasks
0000000000000000 D clkdom_cpumasks
0000000000000000 D clkdom_init_status
*/
#include "cpu_config.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall calculate_cpumasks(__int64 result)
{
  int *v1; // x1
  char v2; // w2
  __int64 i; // x2
  int v4; // t1

  v1 = &dword_1A61C;
  v2 = ~(unsigned __int8)((unsigned __int64)MEMORY[0x78018C] >> 7);
  dword_1A624 = v2 & 0xF;
  dword_1A62C = v2 & 0x70;
  dword_1A634 = v2 & 0x80;
  for ( i = 0LL; i != 16; i += 4LL )
  {
    v4 = *v1;
    v1 += 2;
    *(_DWORD *)(result + i) = v4;
  }
  return result;
}



