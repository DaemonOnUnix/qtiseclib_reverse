#pragma once
#include "defs.h"
__int64 __fastcall qtiseclib_psci_init(unsigned __int64 a1);
char **__fastcall qtiseclib_psci_node_on_finish(__int64 a1);
char **__fastcall qtiseclib_psci_node_power_off(__int64 a1);
__int64 __fastcall qtiseclib_psci_node_power_on(__int64 a1);
char **__fastcall qtiseclib_psci_node_suspend(__int64 a1);
char **__fastcall qtiseclib_psci_node_suspend_finish(__int64 a1);
void __noreturn qtiseclib_psci_system_off();
void __noreturn qtiseclib_psci_system_reset();
char **__fastcall qtisec_psci_node_down(__int64 a1, unsigned int a2);
