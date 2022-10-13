/*0000000000000000 t $x
0000000000000000 T pm_app_ps_hold_cfg
                 U pm_comm_channel_init_internal
                 U pm_get_pmic_model
                 U pm_pon_ps_hold_cfg
                 U pm_pon_tgt_specific_pshold_cfg
                 U pm_tgt_get_pshold_reset_cfg
                 U pm_version_detect
*/
#include "pm_app_pon.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall pm_app_ps_hold_cfg(unsigned int a1)
{
  __int64 result; // x0
  unsigned int v3; // w21
  unsigned int v4; // w19
  unsigned int i; // w20
  int pmic_model; // w0
  unsigned int v8; // [xsp+3Ch] [xbp+3Ch] BYREF

  v8 = 15;
  if ( a1 > 4 )
    return 2LL;
  result = 4LL;
  if ( a1 - 3 > 1 )
  {
    v3 = a1;
    result = pm_comm_channel_init_internal();
    if ( !(_DWORD)result )
    {
      result = pm_version_detect();
      v4 = result;
      if ( !(_DWORD)result )
      {
        for ( i = 0; i != 7; ++i )
        {
          pmic_model = pm_get_pmic_model(i);
          if ( pmic_model != 0x7FFFFFFF && pmic_model != 0 )
          {
            v4 |= pm_tgt_get_pshold_reset_cfg(i, v3, &v8);
            if ( v4 )
              return v4;
            if ( v8 != 15 )
              v4 = pm_pon_ps_hold_cfg(i, v8);
            v4 |= pm_pon_tgt_specific_pshold_cfg(i, v3);
          }
        }
        return v4;
      }
    }
  }
  return result;
}



