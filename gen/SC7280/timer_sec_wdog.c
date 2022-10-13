/*0000000000000000 d $d
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
                 U cpuss_dsb
0000000000000000 D g_sec_wdog_last_pet_time
                 U int_svc_register_isr
                 U qtisec_assert
                 U timer_qtimer_read_time_raw
0000000000000000 T timer_sec_wdog_init
0000000000000000 T timer_sec_wdog_pet
0000000000000000 T timer_sec_wdog_start
0000000000000000 T timer_sec_wdog_stop
0000000000000000 t timer_sec_wdt_bark_handler
*/
#include "timer_sec_wdog.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
void timer_sec_wdog_init()
{
  MEMORY[0xC230004] = 6;
  int_svc_register_isr(516, (__int64)"SEC_WDOG_BARK", 0xEuLL, (__int64)timer_sec_wdt_bark_handler, 0LL);
  timer_sec_wdog_start(6000, 22000);
}



__int64 timer_sec_wdog_pet()
{
  __int64 result; // x0

  MEMORY[0xC230000] = 1;
  cpuss_dsb();
  result = timer_qtimer_read_time_raw();
  g_sec_wdog_last_pet_time = result;
  return result;
}



void __fastcall timer_sec_wdog_start(int a1, int a2)
{
  unsigned int v2; // w0
  unsigned int v3; // w1

  if ( !a1 )
    a1 = 1;
  if ( !a2 )
    a2 = 1;
  v2 = 32 * a1;
  v3 = 32 * a2;
  MEMORY[0xC230004] &= ~1u;
  if ( v3 > 0xFFFFF )
    v3 = 0xFFFFF;
  if ( v2 > 0xFFFFF )
    v2 = 0xFFFFF;
  MEMORY[0xC23000C] = v2 | MEMORY[0xC23000C] & 0xFFF00000;
  while ( (MEMORY[0xC23000C] & 0x80000000) == 0 )
    ;
  MEMORY[0xC230010] = MEMORY[0xC230010] & 0xFFF00000 | v3;
  while ( (MEMORY[0xC230010] & 0x80000000) == 0 )
    ;
  MEMORY[0xC230004] |= 1u;
  MEMORY[0xC230004] |= 0x80000000;
  MEMORY[0xC230000] = 1;
  cpuss_dsb();
}



void timer_sec_wdog_stop()
{
  MEMORY[0xC230000] = 1;
  MEMORY[0xC230004] &= ~1u;
  cpuss_dsb();
}



