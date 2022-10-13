#pragma once
#include "defs.h"
__int64 vmidmt_config();
__int64 vmidmt_config_options();
__int64 __fastcall vmidmt_config_options_per_master(int a1);
__int64 vmidmt_config_vmids();
__int64 __fastcall vmidmt_getInfo_index(unsigned __int8 a1);
__int64 __fastcall vmidmt_map_multisid_vmid_internal(unsigned __int8 a1);
__int64 __fastcall vmidmt_map_vmid_internal(unsigned __int8 a1);
__int64 vmidmt_register_interrupts();
