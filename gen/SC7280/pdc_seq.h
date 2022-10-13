#pragma once
#include "defs.h"
__int64 __fastcall pdc_seq_enable(__int64 a1, char a2);
__int64 __fastcall pdc_seq_enable_arc_timer(__int64 a1, char a2);
__int64 __fastcall pdc_seq_enable_profile_ts(__int64 a1, unsigned __int8 a2);
__int64 __fastcall pdc_seq_handle_init(_QWORD *a1);
__int64 __fastcall pdc_seq_profile_ts(__int64 a1);
__int64 __fastcall pdc_seq_profile_ts_count(__int64 a1);
__int64 __fastcall pdc_seq_set_lpm(_QWORD *a1, unsigned __int16 a2);
__int64 __fastcall pdc_seq_set_wakeup_time(__int64 a1, __int64 a2);
__int64 pdc_seq_sys_init();
__int64 pdc_seq_test();
