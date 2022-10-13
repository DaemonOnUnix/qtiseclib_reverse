#pragma once
#include "defs.h"
__int64 ac_init();
int *__fastcall msm_xpu_isr(__int64 a1, __int64 a2, int *a3);
__int64 xpu_register_interrupts();
__int64 xpu_static_config();
