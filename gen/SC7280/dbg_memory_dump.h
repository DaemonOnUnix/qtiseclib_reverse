#pragma once
#include "defs.h"
void __fastcall __noreturn dbg_err_fatal(unsigned int a1);
__int64 dbg_init();
__int64 dbg_is_sdi_enable();
__int64 qtiseclib_is_debug_enabled_secure_io_access();
void __noreturn qtiseclib_panic();
