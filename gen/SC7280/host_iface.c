/*0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
                 U clkdom_cpumasks
                 U cpucp_clkdom_init
0000000000000000 T cpucp_host_clock_domain_disable
0000000000000000 T cpucp_host_clock_domain_enable
0000000000000000 T cpucp_host_clock_domain_init
                 U cpucp_host_configure_shared_data
0000000000000000 T cpucp_host_error_handler
0000000000000000 T cpucp_host_handle_irq
0000000000000000 T cpucp_host_init
0000000000000000 T cpucp_host_recv_message
0000000000000000 T cpucp_host_send_message
0000000000000000 T cpucp_iface_initialize
                 U cpucp_load_firmware
                 U cpucp_prepare
                 U cpucp_start
                 U cpucp_unprepare
*/
#include "host_iface.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 cpucp_host_clock_domain_disable()
{
  return 0LL;
}



__int64 __fastcall cpucp_host_clock_domain_enable(__int64 a1)
{
  cpucp_clkdom_init(a1);
  return 0LL;
}



__int64 cpucp_host_clock_domain_init()
{
  return 0LL;
}



__int64 cpucp_host_error_handler()
{
  return 0LL;
}



__int64 cpucp_host_handle_irq()
{
  return 0LL;
}



__int64 cpucp_host_init()
{
  return 0LL;
}



__int64 cpucp_host_recv_message()
{
  return 0LL;
}



__int64 cpucp_host_send_message()
{
  return 0LL;
}



__int64 __fastcall cpucp_iface_initialize(_QWORD *a1)
{
  int *v1; // x2
  _QWORD *v2; // x0
  int v3; // w1
  int v4; // t1

  a1[1] = cpucp_prepare;
  a1[2] = cpucp_unprepare;
  a1[3] = cpucp_load_firmware;
  a1[4] = cpucp_host_init;
  v1 = &dword_1A61C;
  a1[8] = cpucp_host_configure_shared_data;
  a1[9] = cpucp_host_error_handler;
  a1[10] = cpucp_host_send_message;
  a1[11] = cpucp_host_recv_message;
  a1[5] = cpucp_start;
  v2 = a1 + 12;
  v3 = 0;
  do
  {
    *(_DWORD *)v2 = v3++;
    v2[4] = cpucp_host_clock_domain_init;
    v2[5] = cpucp_host_clock_domain_enable;
    v2[6] = cpucp_host_clock_domain_disable;
    v2 += 10;
    *(v2 - 1) = cpucp_host_handle_irq;
    v4 = *v1;
    v1 += 2;
    *((_DWORD *)v2 - 18) = v4;
  }
  while ( v3 != 4 );
  return 0LL;
}



