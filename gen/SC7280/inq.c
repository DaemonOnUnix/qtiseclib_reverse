/*0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 T inq_append
0000000000000000 T inq_create
0000000000000000 T inq_destroy
0000000000000000 T inq_head
0000000000000000 T inq_it_begin
0000000000000000 T inq_it_delete
0000000000000000 T inq_it_deref
0000000000000000 T inq_it_insert
0000000000000000 T inq_it_next
0000000000000000 T inq_pop
0000000000000000 T inq_size
                 U qtiseclib_cb_memset
                 U rpmh_core_verify
                 U rpmh_core_verify_ptr
                 U rpmh_free
                 U rpmh_malloc
*/
#include "inq.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
unsigned int *__fastcall inq_append(unsigned int *result, __int64 a2)
{
  __int64 v2; // x3
  __int64 v3; // x2

  v2 = *((_QWORD *)result + 2);
  v3 = *result;
  if ( v2 )
  {
    *(_QWORD *)(v2 + v3) = a2;
    *(_QWORD *)(a2 + v3) = 0LL;
    *((_QWORD *)result + 2) = a2;
  }
  else
  {
    *((_QWORD *)result + 1) = a2;
    *((_QWORD *)result + 2) = a2;
    *(_QWORD *)(a2 + v3) = 0LL;
  }
  ++result[1];
  return result;
}



_DWORD *__fastcall inq_create(int a1)
{
  _DWORD *v2; // x19

  v2 = (_DWORD *)rpmh_malloc(0x18u);
  rpmh_core_verify_ptr((__int64)v2);
  qtiseclib_cb_memset(v2, 0LL, 24LL);
  *v2 = a1;
  return v2;
}




__int64 __fastcall inq_head(__int64 a1)
{
  return *(_QWORD *)(a1 + 8);
}



__int64 __fastcall inq_it_begin(__int64 a1, _QWORD *a2)
{
  __int64 result; // x0

  *a2 = a1;
  a2[1] = 0LL;
  result = *(_QWORD *)(a1 + 8);
  a2[2] = result;
  return result;
}



__int64 __fastcall inq_it_delete(unsigned int **a1)
{
  __int64 result; // x0
  unsigned int *v3; // x2
  unsigned int *v4; // x3
  unsigned int **v5; // x19
  __int64 v6; // x4

  result = (__int64)a1[2];
  if ( result )
  {
    v3 = *a1;
    v4 = a1[1];
    if ( v4 )
    {
      v6 = *v3;
      *(_QWORD *)((char *)v4 + v6) = *(_QWORD *)(result + v6);
      a1[2] = *(unsigned int **)(result + v6);
      if ( result == *((_QWORD *)v3 + 2) )
        *((_QWORD *)v3 + 2) = v4;
      --v3[1];
    }
    else
    {
      v5 = a1;
      rpmh_core_verify(*((_QWORD *)v3 + 1) == result);
      result = inq_pop(*v5);
      v5[2] = (unsigned int *)*((_QWORD *)*v5 + 1);
    }
  }
  return result;
}



__int64 __fastcall inq_it_deref(__int64 a1)
{
  return *(_QWORD *)(a1 + 16);
}



unsigned int *__fastcall inq_it_insert(unsigned int **a1, __int64 a2)
{
  unsigned int *v2; // x2
  unsigned int *v5; // x0
  unsigned int *result; // x0
  unsigned int *v7; // x1
  unsigned int *v8; // x0
  __int64 v9; // x0
  unsigned int *v10; // x1
  unsigned int v11; // w0

  v2 = a1[2];
  v5 = *a1;
  if ( v2 )
  {
    v7 = a1[1];
    if ( v7 )
    {
      v9 = *v5;
      *(_QWORD *)(a2 + v9) = v2;
      *(_QWORD *)((char *)v7 + v9) = a2;
    }
    else
    {
      rpmh_core_verify(*((_QWORD *)v5 + 1) == (_QWORD)v2);
      v8 = *a1;
      *(_QWORD *)(a2 + **a1) = *((_QWORD *)*a1 + 1);
      *((_QWORD *)v8 + 1) = a2;
    }
    v10 = *a1;
    v11 = (*a1)[1];
    a1[2] = (unsigned int *)a2;
    result = (unsigned int *)(v11 + 1);
    v10[1] = (unsigned int)result;
  }
  else
  {
    a1[1] = (unsigned int *)*((_QWORD *)v5 + 2);
    result = inq_append(v5, a2);
    a1[2] = (unsigned int *)a2;
  }
  return result;
}



unsigned int **__fastcall inq_it_next(unsigned int **result)
{
  unsigned int *v1; // x1

  v1 = result[2];
  result[1] = v1;
  if ( v1 )
    result[2] = *(unsigned int **)((char *)v1 + **result);
  return result;
}



__int64 __fastcall inq_pop(unsigned int *a1)
{
  unsigned int v1; // w2
  __int64 v2; // x1
  __int64 v3; // x3
  __int64 v4; // x4

  v1 = a1[1];
  if ( !v1 )
    return 0LL;
  v2 = *((_QWORD *)a1 + 1);
  v3 = *a1;
  v4 = *(_QWORD *)(v2 + v3);
  *((_QWORD *)a1 + 1) = v4;
  if ( !v4 )
    *((_QWORD *)a1 + 2) = 0LL;
  *(_QWORD *)(v2 + v3) = 0LL;
  a1[1] = v1 - 1;
  return v2;
}



__int64 __fastcall inq_size(__int64 a1)
{
  return *(unsigned int *)(a1 + 4);
}



