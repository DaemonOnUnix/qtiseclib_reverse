/*0000000000000000 b $d
0000000000000000 b $d
0000000000000000 t $x
0000000000000000 b g_pdc_aoss_base
0000000000000000 b g_pdc_ss_base
0000000000000000 T pdc_seq_handle_env_init
*/
#include "pdc_seq_env.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall pdc_seq_handle_env_init(_QWORD *a1)
{
  unsigned int v1; // w3
  __int64 v2; // x2

  if ( !g_pdc_aoss_base )
    g_pdc_aoss_base = 184549376LL;
  if ( !g_pdc_ss_base )
    g_pdc_ss_base = 394264576LL;
  v1 = -2;
  if ( a1 )
  {
    v1 = 0;
    a1[6] = g_pdc_aoss_base + a1[4];
    v2 = a1[5];
    if ( v2 )
      a1[7] = g_pdc_ss_base + v2;
  }
  return v1;
}



