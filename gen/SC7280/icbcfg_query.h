#pragma once
#include "defs.h"
__int64 __fastcall check_dupRegion(__int64 a1, __int64 a2, int a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, int a8);
bool __fastcall check_overlap(unsigned __int64 *a1, unsigned __int64 *a2);
__int64 __fastcall compare_ch_segments(__int64 a1, __int64 a2, int a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, int a8);
__int64 __fastcall get_system_memory_map(__int64 a1, _QWORD *a2);
__int64 __fastcall ICB_Get_AllowedMemRegion(__int64 a1, _QWORD *a2);
__int64 __fastcall ICB_Get_MCAddr(__int64 a1, __int64 a2, _QWORD *a3);
__int64 __fastcall ICB_Get_Memmap(__int64 a1, _QWORD *a2);
__int64 __fastcall translate_address(__int64 a1, __int64 a2, _QWORD *a3);
__int64 update_addr_translation();
