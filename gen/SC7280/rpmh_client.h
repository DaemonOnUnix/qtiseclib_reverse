#pragma once
#include "defs.h"
__int64 __fastcall rpmh_barrier_all(_QWORD, _QWORD); // weak
__int64 __fastcall rpmh_barrier_single(_QWORD, _QWORD); // weak
__int64 __fastcall rpmh_churn_all(__int64 a1, unsigned int a2);
__int64 __fastcall rpmh_churn_single(__int64 a1, unsigned int a2);
void rpmh_client_init();
__int64 __fastcall rpmh_create_handle(int a1, __int64 a2);
__int64 __fastcall rpmh_create_handle_explicit(int a1, __int64 a2);
__int64 __fastcall rpmh_create_handle_internal(int a1, __int64 a2, unsigned __int8 a3);
__int64 __fastcall rpmh_enter_sleep(int a1);
__int64 rpmh_epcb_timeout();
__int64 __fastcall rpmh_exit_sleep(int a1);
unsigned int *__fastcall rpmh_find_resource_command(unsigned int a1);
__int64 __fastcall rpmh_finish_amc(int a1);
__int64 __fastcall rpmh_finish_amc_internal(int a1, unsigned __int8 a2);
__int64 __fastcall rpmh_get_wake_latency(int a1);
__int64 __fastcall rpmh_invalidate_explicit_cmds(__int64 a1);
__int64 __fastcall rpmh_issue_command(__int64 a1, int a2, char a3, int a4, int a5);
__int64 __fastcall rpmh_issue_command_set(__int64 a1, unsigned int *a2);
__int64 __fastcall rpmh_issue_command_set_internal(__int64 a1, unsigned int *a2, unsigned __int8 a3);
