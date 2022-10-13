/*0000000000000000 t $x
                 U scmi_plat_ops
0000000000000000 T scmi_write_packet
*/
#include "scmi_write_packet.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall scmi_write_packet(__int64 a1)
{
  if ( (*(_DWORD *)(a1 + 16) & 1) == 0 || !qtiseclib_cb_strcmp )
    return 0LL;
  qtiseclib_cb_strcmp(0LL);
  return 0LL;
}



