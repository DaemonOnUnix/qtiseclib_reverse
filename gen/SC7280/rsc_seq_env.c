/*0000000000000000 b $d
0000000000000000 t $x
0000000000000000 b g_rsc_ss_base
0000000000000000 T rsc_init_base_address
*/
#include "rsc_seq_env.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall rsc_init_base_address(__int64 a1)
{
  __int64 v2; // x2
  __int64 result; // x0

  if ( !a1 )
    return 1LL;
  if ( !g_rsc_ss_base )
    g_rsc_ss_base = 394264576LL;
  v2 = *(_QWORD *)(a1 + 24);
  result = 0xFFFFFFFFLL;
  if ( v2 )
  {
    result = 0LL;
    *(_QWORD *)(a1 + 40) = g_rsc_ss_base + v2;
  }
  return result;
}



