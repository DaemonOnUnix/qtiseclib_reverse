/*0000000000000000 b $d
0000000000000000 t $x
                 U clkdom_cpumasks
                 U clkdom_init_status
0000000000000000 T cpucp_clkdom_init
0000000000000000 B cpucp_clkdom_init_spinlock
                 U cpucp_scmi_send
                 U qtiseclib_cb_plat_my_core_pos
                 U qtiseclib_cb_spin_lock
                 U qtiseclib_cb_spin_unlock
*/
#include "clk_dom_enable.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall cpucp_clkdom_init(__int64 a1)
{
  char v1; // w0
  int *v2; // x2
  __int64 result; // x0
  __int64 v4; // x1
  __int64 v5; // x20
  int v6; // [xsp+34h] [xbp+34h] BYREF
  int v7[2]; // [xsp+38h] [xbp+38h] BYREF

  v1 = qtiseclib_cb_plat_my_core_pos(a1);
  v2 = &dword_1A61C;
  result = (unsigned int)(1 << v1);
  v4 = 0LL;
  while ( 1 )
  {
    v5 = (int)v4;
    if ( !clkdom_init_status[v4] && ((unsigned int)result & *v2) != 0 )
      break;
    ++v4;
    v2 += 2;
    if ( v4 == 4 )
      return result;
  }
  qtiseclib_cb_spin_lock(&cpucp_clkdom_init_spinlock);
  if ( !clkdom_init_status[v5] )
  {
    v7[0] = *((_DWORD *)&clkdom_cpumasks + 2 * v5);
    v7[1] = 1;
    if ( !(unsigned int)cpucp_scmi_send(0x14u, 7u, (__int64)v7, 8u, &v6, 0LL, 0LL) && !v6 )
      clkdom_init_status[v5] = 1;
  }
  return qtiseclib_cb_spin_unlock(&cpucp_clkdom_init_spinlock);
}



