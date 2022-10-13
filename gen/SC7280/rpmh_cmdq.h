#pragma once
#include "defs.h"
bool __fastcall cmdq_empty(__int64 a1);
unsigned int *__fastcall cmdq_finish_cmd(__int64 a1, __int64 a2, int a3, __int64 a4, int a5);
__int64 __fastcall cmdq_num_in_flight(__int64 a1);
__int64 __fastcall rpmh_clean_cmd(_QWORD *a1, unsigned int a2);
__int64 __fastcall rpmh_cmdq_create(unsigned int a1);
__int64 __fastcall rpmh_cmdq_send_cmd_at_head(__int64 a1);
__int64 __fastcall rpmh_cmdq_send_cmd_set(unsigned int *a1, int *a2, _DWORD *a3);
