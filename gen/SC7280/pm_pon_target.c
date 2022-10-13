/*0000000000000000 r $d
0000000000000000 r $d
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
                 U pm_pon_gp_reset_cfg
0000000000000000 r pm_pon_pshold_gp1_reset_cfg_arr
0000000000000000 r pm_pon_pshold_reset_cfg_arr
0000000000000000 T pm_pon_tgt_specific_pshold_cfg
0000000000000000 T pm_tgt_get_pshold_gp1_reset_cfg
0000000000000000 T pm_tgt_get_pshold_reset_cfg
*/
#include "pm_pon_target.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall pm_pon_tgt_specific_pshold_cfg(unsigned int a1, unsigned int a2)
{
  bool v2; // cc
  unsigned int pshold_gp1_reset_cfg; // w19
  unsigned __int8 v4; // w4
  unsigned int v6; // [xsp+2Ch] [xbp+2Ch] BYREF

  v2 = a1 > 6 || a2 > 4;
  pshold_gp1_reset_cfg = 2;
  v6 = 15;
  if ( !v2 )
  {
    pshold_gp1_reset_cfg = pm_tgt_get_pshold_gp1_reset_cfg(a1, a2, &v6);
    if ( v6 != 15 )
      pshold_gp1_reset_cfg |= pm_pon_gp_reset_cfg(v4, 4, v6);
  }
  return pshold_gp1_reset_cfg;
}



__int64 __fastcall pm_tgt_get_pshold_gp1_reset_cfg(unsigned int a1, unsigned int a2, _DWORD *a3)
{
  if ( a2 > 4 || a3 == 0LL || a1 > 6 )
    return 2LL;
  *a3 = pm_pon_pshold_gp1_reset_cfg_arr[7 * a2 + a1];
  return 0LL;
}



__int64 __fastcall pm_tgt_get_pshold_reset_cfg(unsigned int a1, unsigned int a2, _DWORD *a3)
{
  if ( a2 > 4 || a3 == 0LL || a1 > 6 )
    return 2LL;
  *a3 = pm_pon_pshold_reset_cfg_arr[7 * a2 + a1];
  return 0LL;
}



