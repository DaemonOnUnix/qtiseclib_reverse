/*0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 T timer_qtimer_read_time_raw
0000000000000000 T timer_qtimer_read_time_us
0000000000000000 T timer_qtimer_security_config
*/
#include "timer_qtimer.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 timer_qtimer_read_time_raw()
{
  return MEMORY[0x17C25000];
}



unsigned __int64 timer_qtimer_read_time_us()
{
  return 10LL * MEMORY[0x17C25000] / 0xC0uLL;
}



__int64 timer_qtimer_security_config()
{
  __int64 result; // x0

  MEMORY[0x17C20004] = 127;
  MEMORY[0x17C20040] = 63;
  MEMORY[0x17C20080] = 0;
  MEMORY[0x17C20084] = 0;
  MEMORY[0x17C20044] = 63;
  MEMORY[0x17C20088] = 0;
  MEMORY[0x17C2008C] = 0;
  MEMORY[0x17C20048] = 63;
  MEMORY[0x17C20090] = 0;
  MEMORY[0x17C20094] = 0;
  MEMORY[0x17C2004C] = 63;
  MEMORY[0x17C20098] = 0;
  MEMORY[0x17C2009C] = 0;
  MEMORY[0x17C20050] = 63;
  MEMORY[0x17C200A0] = 0;
  MEMORY[0x17C200A4] = 0;
  MEMORY[0x17C20054] = 63;
  MEMORY[0x17C200A8] = 0;
  MEMORY[0x17C200AC] = 0;
  MEMORY[0x17C20058] = 63;
  result = 398590128LL;
  MEMORY[0x17C200B0] = 0;
  MEMORY[0x17C200B4] = 0;
  return result;
}



