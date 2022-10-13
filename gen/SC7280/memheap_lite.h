#pragma once
#include "defs.h"
__int64 __fastcall mem_free(__int64 a1, _QWORD *a2, __int64 a3);
__int64 __fastcall mem_get_buffer_size(__int64 a1);
__int64 __fastcall mem_init_heap(int *a1, __int64 *a2, __int64 a3, unsigned __int64 a4);
unsigned __int64 __fastcall mem_malloc(__int64 a1, _QWORD *a2, unsigned int a3);
unsigned __int64 __fastcall mem_realloc(__int64 a1, _QWORD *a2, __int64 a3, unsigned int a4);
