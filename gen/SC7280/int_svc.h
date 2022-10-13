#pragma once
#include "defs.h"
__int64 __fastcall int_svc_core_pos_to_mpidr(unsigned int a1);
__int64 int_svc_init();
bool __fastcall int_svc_is_cpu_on(char a1);
__int64 __fastcall int_svc_notify_cpu_state(__int64 a1);
__int64 __fastcall int_svc_register_isr(int a1, __int64 a2, unsigned __int64 a3, __int64 a4, __int64 a5);
__int64 __fastcall int_svc_unregister_isr(int a1);
__int64 __fastcall qtiseclib_invoke_isr(__int64 a1, __int64 a2);
