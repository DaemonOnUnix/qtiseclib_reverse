/*0000000000000000 t $x
                 U handle_scmi_base_protocol_msg
                 U handle_scmi_clk_mgmt_protocol_msg
                 U handle_scmi_perf_dom_mgmt_protocol_msg
                 U handle_scmi_unknown_protocol
                 U handle_scmi_vendor_protocol_msg
0000000000000000 T scmi_process_packet
*/
#include "scmi_process_packet.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall scmi_process_packet(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v4; // w1
  __int64 result; // x0
  __int64 v6; // x1

  v4 = (unsigned __int8)((unsigned __int64)*(unsigned int *)(a1 + 24) >> 10);
  if ( v4 == 20 )
  {
    result = handle_scmi_clk_mgmt_protocol_msg(a1);
    goto LABEL_11;
  }
  if ( v4 > 0x14 )
  {
    v6 = v4 - 128;
    if ( (unsigned int)v6 <= 2 )
    {
      result = handle_scmi_vendor_protocol_msg(a1, v6, a3);
      goto LABEL_11;
    }
LABEL_10:
    result = handle_scmi_unknown_protocol(a1);
    goto LABEL_11;
  }
  if ( v4 == 16 )
  {
    result = handle_scmi_base_protocol_msg(a1);
    goto LABEL_11;
  }
  if ( v4 != 19 )
    goto LABEL_10;
  result = handle_scmi_perf_dom_mgmt_protocol_msg();
LABEL_11:
  *(_DWORD *)(a1 + 4) = 1;
  return result;
}



