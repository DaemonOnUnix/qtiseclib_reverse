#pragma once
#include "defs.h"
__int64 __fastcall cmd_db_conv_str_to_unit64(__int64 a1);
bool cmd_db_init();
__int64 __fastcall cmd_db_query(__int64 a1, __int64 a2, __int64 a3);
__int64 __fastcall cmd_db_query_addr(__int64 a1);
__int64 __fastcall cmd_db_query_aux_data(__int64 a1, _BYTE *a2, __int64 a3);
__int64 __fastcall cmd_db_query_len(__int64 a1);
__int64 __fastcall cmd_db_query_priority(int a1, char a2);
__int64 __fastcall cmd_db_query_priority_res_id(__int64 a1, char a2);
__int64 __fastcall cmd_db_query_slv_id(__int64 a1);
__int64 __fastcall cmd_db_query_version(__int64 a1);
