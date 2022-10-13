#pragma once
#include "defs.h"
__int64 is_rpmh_busy();
__int64 __fastcall rpmh_clock_toggle(_QWORD, _QWORD); // weak
__int64 __fastcall rpmh_clz(int a1);
__int64 __fastcall rpmh_core_verify(__int64 result);
__int64 __fastcall rpmh_core_verify_ptr(__int64 result);
__int64 rpmh_deregister_isr(void); // weak
void __fastcall __noreturn rpmh_err_fatal(_QWORD); // weak
__int64 rpmh_get_timestamp(void); // weak
__int64 rpmh_lock();
unsigned __int64 __fastcall rpmh_malloc(unsigned int a1);
__int64 rpmh_os_init(void); // weak
unsigned __int64 __fastcall rpmh_realloc(__int64 a1, unsigned int a2);
void *__fastcall rpmh_register_isr(__int64 a1, __int64 a2, __int64 a3, int a4);
__int64 rpmh_unlock();
