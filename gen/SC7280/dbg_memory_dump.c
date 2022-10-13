/*0000000000000000 b $d
0000000000000000 b $d
0000000000000000 d $d
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 T dbg_err_fatal
0000000000000000 t dbg_err_fatal_handler
0000000000000000 D dbg_err_fatal_str
0000000000000000 t dbg_halt_online_cpus
0000000000000000 T dbg_init
0000000000000000 T dbg_is_sdi_enable
0000000000000000 d first_time.1190
0000000000000000 b g_dbg_svc_lock
0000000000000000 B g_fatal_err_code
                 U int_svc_core_pos_to_mpidr
                 U int_svc_is_cpu_on
                 U int_svc_register_isr
0000000000000000 t nsec_wdt_bite_isr_handler
                 U qtiseclib_cb_console_flush
                 U qtiseclib_cb_ic_raise_sgi
                 U qtiseclib_cb_log
                 U qtiseclib_cb_plat_my_core_pos
                 U qtiseclib_cb_spin_lock
                 U qtiseclib_cb_spin_unlock
                 U qtiseclib_cb_switch_console_to_crash_state
0000000000000000 T qtiseclib_is_debug_enabled_secure_io_access
0000000000000000 T qtiseclib_panic
0000000000000000 t sgi15_isr_handler
                 U timer_sec_wdog_pet
                 U timer_sec_wdog_start
*/
#include "dbg_memory_dump.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
void __fastcall __noreturn dbg_err_fatal(unsigned int a1)
{
  dbg_err_fatal_handler(a1);
}



__int64 dbg_init()
{
  int_svc_register_isr(33, (__int64)"NSEC_WDOG_BITE", 0xFuLL, (__int64)nsec_wdt_bite_isr_handler, 0LL);
  return int_svc_register_isr(15, (__int64)"SGI15", 6uLL, (__int64)sgi15_isr_handler, 0LL);
}



__int64 dbg_is_sdi_enable()
{
  return 0LL;
}



__int64 qtiseclib_is_debug_enabled_secure_io_access()
{
  return 0LL;
}



void __noreturn qtiseclib_panic()
{
  dbg_err_fatal_handler(1u);
}



