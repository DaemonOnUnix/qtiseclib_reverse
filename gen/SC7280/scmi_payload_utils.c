/*0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 T get_input_payload_char_at_offset
0000000000000000 T get_input_payload_word_at_offset
0000000000000000 T scmi_packet_init_payload
0000000000000000 T write_output_payload_word
0000000000000000 T write_output_payload_word_at_offset
*/
#include "scmi_payload_utils.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall get_input_payload_char_at_offset(__int64 a1, int a2)
{
  return *(unsigned int *)(a1 + a2 + 28);
}



__int64 __fastcall get_input_payload_word_at_offset(__int64 a1, int a2)
{
  return *(unsigned int *)(a1 + 4LL * a2 + 28);
}



__int64 __fastcall scmi_packet_init_payload(__int64 result)
{
  *(_DWORD *)(result + 20) = 4;
  return result;
}



__int64 __fastcall write_output_payload_word(__int64 result, int a2)
{
  *(_DWORD *)(result + ((*(_DWORD *)(result + 20) - 1) & 0xFFFFFFFC) + 28) = a2;
  *(_DWORD *)(result + 20) += 4;
  return result;
}



__int64 __fastcall write_output_payload_word_at_offset(__int64 result, int a2, int a3)
{
  *(_DWORD *)(result + 4LL * a3 + 28) = a2;
  *(_DWORD *)(result + 20) += 4;
  return result;
}



