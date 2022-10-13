#pragma once
#include "defs.h"
__int64 __fastcall pdc_seq_hal_cfg_br_addr(__int64 a1, unsigned __int16 a2, unsigned __int8 a3);
__int64 __fastcall pdc_seq_hal_cfg_br_event_override(__int64 a1, int a2, int a3);
__int64 __fastcall pdc_seq_hal_cfg_delay(__int64 a1, unsigned __int16 a2, int a3);
__int64 __fastcall pdc_seq_hal_cfg_pwr_ctl_override(__int64 a1, int a2, int a3);
__int64 __fastcall pdc_seq_hal_cfg_start_addr(__int64 result, unsigned __int16 a2);
__int64 __fastcall pdc_seq_hal_cfg_start_addr_ex(__int64 a1, unsigned __int8 a2);
__int64 __fastcall pdc_seq_hal_cfg_wait_event_override(__int64 a1, int a2, int a3);
__int64 __fastcall pdc_seq_hal_cfg_wakeup_time(__int64 result, __int64 a2);
__int64 __fastcall pdc_seq_hal_cfg_wakeup_time_ex(__int64 a1, __int64 a2);
__int64 __fastcall pdc_seq_hal_clk_gate_enable(__int64 a1, char a2);
__int64 __fastcall pdc_seq_hal_copy_cmd_seq(__int64 a1, unsigned __int16 a2, __int64 a3, unsigned int a4);
__int64 __fastcall pdc_seq_hal_enable(__int64 a1, char a2);
__int64 __fastcall pdc_seq_hal_enable_arc_timer(__int64 a1, char a2);
__int64 __fastcall pdc_seq_hal_enable_profile_ts(__int64 a1, unsigned __int8 a2, char a3);
unsigned __int64 __fastcall pdc_seq_hal_profile_ts(__int64 a1, unsigned __int8 a2);
__int64 __fastcall pdc_seq_hal_profile_ts_count(__int64 a1);
