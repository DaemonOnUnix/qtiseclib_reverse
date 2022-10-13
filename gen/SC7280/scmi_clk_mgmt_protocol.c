/*0000000000000000 r $d
0000000000000000 t $x
                 U get_input_payload_word_at_offset
0000000000000000 T handle_scmi_clk_mgmt_protocol_msg
                 U scmi_num_clk_doms
                 U scmi_packet_init_payload
                 U scmi_plat_ops
                 U write_output_payload_word
*/
#include "scmi_clk_mgmt_protocol.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall handle_scmi_clk_mgmt_protocol_msg(__int64 a1)
{
  int v2; // w1
  unsigned int input_payload_word_at_offset; // w20

  scmi_packet_init_payload(a1);
  switch ( *(_BYTE *)(a1 + 24) )
  {
    case 0:
      write_output_payload_word(a1, 0);
      v2 = 0x10000;
      break;
    case 1:
      write_output_payload_word(a1, 0);
      v2 = scmi_num_clk_doms;
      break;
    case 2:
      write_output_payload_word(a1, 0);
      goto LABEL_9;
    case 3:
    case 4:
    case 5:
    case 6:
      v2 = -3;
      break;
    case 7:
      input_payload_word_at_offset = get_input_payload_word_at_offset(a1, 0);
      if ( (unsigned int)get_input_payload_word_at_offset(a1, 1) != 1 || !MEMORY[0x319B0] )
        goto LABEL_10;
      MEMORY[0x319B0](input_payload_word_at_offset);
LABEL_9:
      v2 = 0;
      break;
    default:
LABEL_10:
      v2 = -1;
      break;
  }
  write_output_payload_word(a1, v2);
  return 0LL;
}



