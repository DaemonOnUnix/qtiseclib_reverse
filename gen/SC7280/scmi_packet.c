/*0000000000000000 t $x
0000000000000000 T scmi_construct_msg_hdr
*/
#include "scmi_packet.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
unsigned __int64 __fastcall scmi_construct_msg_hdr(unsigned __int8 a1, char a2, unsigned __int8 a3, __int16 a4)
{
  int v5; // [xsp+8h] [xbp-8h]

  LOBYTE(v5) = a1;
  BYTE1(v5) = BYTE1(v5) & 0xFC | a2 & 3;
  return a1 | (unsigned __int64)(unsigned __int16)((unsigned __int8)((unsigned __int16)(v5 & 0x3FF | (a3 << 10)) >> 8) << 8) | ((((v5 & 0xFFFC03FF | (a3 << 10)) >> 16) & 3 | (unsigned __int8)(4 * a4)) << 16) & 0xFFFFFF | ((unsigned __int64)(unsigned __int8)((unsigned __int16)(((v5 & 0xFFFC03FF | (a3 << 10)) >> 16) & 0xF003 | (4 * (a4 & 0x3FF))) >> 8) << 24);
}



