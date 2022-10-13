#pragma once
#include "defs.h"
void timer_sec_wdog_init();
__int64 timer_sec_wdog_pet();
void __fastcall timer_sec_wdog_start(int a1, int a2);
void timer_sec_wdog_stop();
