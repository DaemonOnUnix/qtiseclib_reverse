#pragma once
#include "defs.h"
unsigned __int64 __fastcall resource_command_sets_dirty(__int64 a1, int a2);
__int64 __fastcall rpmh_resource_command_exit_sleep(__int64 a1, int a2);
__int64 __fastcall rpmh_resource_command_finish(unsigned int a1, int a2);
__int64 __fastcall rpmh_resource_command_get_priority(__int64 a1, int a2);
unsigned __int64 __fastcall rpmh_resource_command_get_voter(__int64 a1, int a2);
__int64 __fastcall rpmh_resource_command_init(_DWORD *a1, int a2);
bool __fastcall rpmh_resource_command_update(__int64 a1, unsigned int a2, int a3, int a4, unsigned __int8 a5);
__int64 __fastcall rpmh_resource_command_val_at_rpmh(unsigned int a1, int a2, unsigned int a3, unsigned __int8 a4);
