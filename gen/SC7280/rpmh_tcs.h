#pragma once
#include "defs.h"
__int64 __fastcall drv_valid(int a1);
__int64 __fastcall get_finished_drv(int a1);
bool __fastcall is_amc_finished(int a1);
__int64 __fastcall is_amc_free(int a1);
__int64 __fastcall is_tcs_stuck(int a1);
__int64 __fastcall lookup_drv_index(int a1);
__int64 __fastcall tcs_clean_sleep_wake(int a1);
__int64 __fastcall tcs_finish_active_amc(_QWORD *a1, __int64 a2, int a3);
__int64 __fastcall tcs_finish_amc(__int64 a1, int a2, int a3);
__int64 tcs_init();
__int64 __fastcall tcs_prepare_sleep_add_cmd_set(int *a1, int a2);
__int64 __fastcall tcs_prepare_sleep_commit(int a1);
__int64 __fastcall tcs_send(__int64 a1, int a2);
__int64 __fastcall tcs_size(int a1);
__int64 __fastcall tcs_slots_available(int a1, int a2, unsigned int a3);
__int64 __fastcall tcs_update_mode(unsigned int a1, unsigned int a2);
