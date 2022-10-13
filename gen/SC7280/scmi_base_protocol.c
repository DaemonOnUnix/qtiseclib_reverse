/*0000000000000000 r $d
0000000000000000 t $x
                 U get_input_payload_char_at_offset
0000000000000000 T handle_scmi_base_protocol_msg
                 U scmi_packet_init_payload
                 U scmi_plat_ops
                 U write_output_payload_word
                 U write_output_payload_word_at_offset
*/
#include "scmi_base_protocol.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall handle_scmi_base_protocol_msg(__int64 a1)
{
  int v2; // w1
  __int64 v3; // x20
  int v4; // w0
  int v5; // w1
  __int64 v6; // x20
  int v7; // w0
  int v8; // w1
  __int64 input_payload_char_at_offset; // x0
  int v10; // w20
  unsigned int v12; // [xsp+3Ch] [xbp+3Ch] BYREF
  int v13[4]; // [xsp+40h] [xbp+40h] BYREF

  scmi_packet_init_payload(a1);
  switch ( *(_BYTE *)(a1 + 24) )
  {
    case 0:
      write_output_payload_word(a1, 0);
      v2 = 0x20000;
      goto LABEL_4;
    case 1:
      write_output_payload_word(a1, 0);
      v2 = 257;
      goto LABEL_4;
    case 2:
      write_output_payload_word(a1, 0);
      v2 = 0;
      goto LABEL_4;
    case 3:
      v3 = 0LL;
      write_output_payload_word(a1, 0);
      scmi_plat_ops(v13, &v12, 16LL);
      v4 = v12;
      if ( v12 > 0x10 )
        v4 = 16;
      v12 = v4;
      while ( (unsigned int)v3 < (v12 + 3) >> 2 )
      {
        v5 = v13[v3++];
        write_output_payload_word(a1, v5);
      }
      return 0LL;
    case 4:
      v6 = 0LL;
      write_output_payload_word(a1, 0);
      handle_scmi_vendor_protocol_msg(v13, &v12, 16LL);
      v7 = v12;
      if ( v12 > 0x10 )
        v7 = 16;
      v12 = v7;
      while ( (unsigned int)v6 < (v12 + 3) >> 2 )
      {
        v8 = v13[v6++];
        write_output_payload_word(a1, v8);
      }
      return 0LL;
    case 5:
      write_output_payload_word(a1, 0);
      v2 = 0x10000;
      goto LABEL_4;
    case 6:
      input_payload_char_at_offset = get_input_payload_char_at_offset(a1, 0);
      v10 = MEMORY[0x319B8](input_payload_char_at_offset, v13);
      write_output_payload_word(a1, 0);
      write_output_payload_word(a1, v10);
      v2 = v13[0];
      if ( v10 )
LABEL_4:
        write_output_payload_word(a1, v2);
      break;
    default:
      write_output_payload_word_at_offset(a1, -1, 0);
      break;
  }
  return 0LL;
}



