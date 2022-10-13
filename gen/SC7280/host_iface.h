#pragma once
#include "defs.h"
__int64 cpucp_host_clock_domain_disable();
__int64 __fastcall cpucp_host_clock_domain_enable(__int64 a1);
__int64 cpucp_host_clock_domain_init();
__int64 cpucp_host_error_handler();
__int64 cpucp_host_handle_irq();
__int64 cpucp_host_init();
__int64 cpucp_host_recv_message();
__int64 cpucp_host_send_message();
__int64 __fastcall cpucp_iface_initialize(_QWORD *a1);
