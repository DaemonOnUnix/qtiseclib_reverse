/*0000000000000000 t $x
                 U mem_assign
0000000000000000 T qtiseclib_mem_assign
*/
#include "ac_syscall_def.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall qtiseclib_mem_assign(
        __int64 *a1,
        unsigned int a2,
        __int64 a3,
        unsigned int a4,
        int *a5,
        unsigned int a6)
{
  return mem_assign(a1, a2, a3, a4, a5, a6);
}



