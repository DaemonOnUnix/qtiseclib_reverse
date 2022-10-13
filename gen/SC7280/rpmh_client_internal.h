#pragma once
#include "defs.h"
__int64 __fastcall check_for_events(__int64 a1, int a2);
__int64 __fastcall rpmh_client_command_add(__int64 a1);
__int64 __fastcall rpmh_client_command_finish(__int64 a1, int a2);
__int64 __fastcall rpmh_client_command_remove(__int64 a1, int a2);
__int64 __fastcall rpmh_client_handle_add(unsigned int **a1);
__int64 __fastcall rpmh_client_wait_on_cmd(__int64 a1, unsigned int a2, unsigned int a3, unsigned __int8 a4);
