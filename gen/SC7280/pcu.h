#pragma once
#include "defs.h"
__int64 __fastcall pcu_config_low_power_mode(__int64 *a1, int a2);
__int64 __fastcall pcu_get_node(int a1, _QWORD *a2);
__int64 pcu_init();
__int64 __fastcall pcu_node_init(__int64 a1);
__int64 pcu_seq_memory_init();
__int64 __fastcall pcu_write_seq_memory(__int64 a1, int a2);
