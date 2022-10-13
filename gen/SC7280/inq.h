#pragma once
#include "defs.h"
unsigned int *__fastcall inq_append(unsigned int *result, __int64 a2);
_DWORD *__fastcall inq_create(int a1);
__int64 __fastcall inq_head(__int64 a1);
__int64 __fastcall inq_it_begin(__int64 a1, _QWORD *a2);
__int64 __fastcall inq_it_delete(unsigned int **a1);
__int64 __fastcall inq_it_deref(__int64 a1);
unsigned int *__fastcall inq_it_insert(unsigned int **a1, __int64 a2);
unsigned int **__fastcall inq_it_next(unsigned int **result);
__int64 __fastcall inq_pop(unsigned int *a1);
__int64 __fastcall inq_size(__int64 a1);
