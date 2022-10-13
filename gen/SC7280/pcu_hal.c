/*0000000000000000 t $x
0000000000000000 t $x
0000000000000000 T pcu_config_seq_ctl
0000000000000000 T pcu_write_cmds
*/
#include "pcu_hal.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall pcu_config_seq_ctl(__int64 result, int a2, int a3, int a4)
{
  if ( (a2 & 0x80000000) != 0 )
    *(_DWORD *)(result + 36) = 0;
  else
    *(_DWORD *)(result + 36) = ((a2 & 0xF) << 8) | a4 | (a3 << 16);
  return result;
}



_DWORD *__fastcall pcu_write_cmds(unsigned __int8 a1, int a2)
{
  _DWORD *result; // x0

  result = (_DWORD *)(4LL * ((a1 + 100859904) & 0xFFFFFFF));
  *result = a2;
  return result;
}



