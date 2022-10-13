/*0000000000000000 t $x
                 U scmi_plat_ops
0000000000000000 T scmi_read_packet
*/
#include "scmi_read_packet.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall scmi_read_packet(__int64 a1, __int64 a2, __int64 a3)
{
  if ( qtiseclib_cb_set_spi_routing )
    qtiseclib_cb_set_spi_routing(a1, qtiseclib_cb_set_spi_routing, a3);
  return 0LL;
}



