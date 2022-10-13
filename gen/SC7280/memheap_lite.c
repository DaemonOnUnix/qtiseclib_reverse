/*0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 T mem_free
0000000000000000 T mem_get_buffer_size
0000000000000000 t mem_get_next_block
0000000000000000 t mem_heap_enter_crit_sect
0000000000000000 t mem_heap_leave_crit_sect
0000000000000000 t mem_init_block_header.isra.0
0000000000000000 T mem_init_heap
0000000000000000 T mem_malloc
0000000000000000 T mem_realloc
                 U qtisec_assert
                 U qtiseclib_cb_log
                 U qtiseclib_cb_memcpy
                 U qtiseclib_cb_memset
                 U qtiseclib_cb_spin_lock
                 U qtiseclib_cb_spin_unlock
*/
#include "memheap_lite.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall mem_free(__int64 a1, _QWORD *a2, __int64 a3)
{
  void (__fastcall *v5)(__int64); // x1
  unsigned __int64 v6; // x21
  unsigned __int64 v7; // x1
  unsigned int v8; // w0
  unsigned int v9; // w1
  int v10; // w1
  __int64 v11; // x0
  _WORD *v12; // x1
  __int16 v13; // w2
  __int16 v14; // w3
  void (__fastcall *v15)(__int64); // x1

  if ( !a1 )
    qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x24Bu, "heap_ptr != ((void *) 0)");
  if ( !a2 )
    qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x24Cu, "mem_magic_number");
  if ( !*a2 )
    qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x24Du, "mem_magic_number->magic_num");
  if ( !a2[1] )
    qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x24Eu, "mem_magic_number->magic_num_index_array");
  if ( *(_DWORD *)a1 != *(_DWORD *)(*a2 + 4LL * *(unsigned __int16 *)(a1 + 76)) )
    qtisec_assert(
      "noship_src/services/heap/memheap_lite.c",
      0x251u,
      "heap_ptr->magic_num == mem_magic_number->magic_num[heap_ptr->magic_num_index]");
  if ( !a3 )
  {
    qtiseclib_cb_log(10LL, "NULL ptr occurenaces in mem_free()");
    qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x258u, "0");
  }
  if ( !*(_QWORD *)(a1 + 8) )
    qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x25Eu, "heap_ptr->first_block");
  v5 = *(void (__fastcall **)(__int64))(a1 + 48);
  if ( v5 )
    v5(a1);
  v6 = a3 - 8;
  if ( ((a3 - 8) & 0xF) != 0 )
    qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x26Du, "(((uintptr_t)theBlock)%kMinChunkSize) == 0");
  v7 = *(_QWORD *)(a1 + 8);
  if ( v6 < v7 || v6 >= v7 + *(unsigned int *)(a1 + 28) )
    qtisec_assert(
      "noship_src/services/heap/memheap_lite.c",
      0x270u,
      "((theBlock >= ((mem_heap_type*)heap_ptr)->first_block) && (((char*)(theBlock)) < ((char*)(((mem_heap_type*)heap_pt"
      "r)->first_block) + ((mem_heap_type*)(heap_ptr))->total_bytes)))");
  if ( (*(_BYTE *)(a3 - 5) & 0xF) != 0 )
    qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x274u, "!theBlock->free_flag");
  if ( *(_DWORD *)(a3 - 4) <= 7u )
    qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x277u, "theBlock->forw_offset >= sizeBlockHeader");
  if ( *(unsigned __int8 *)(a3 - 6) > 0xFu )
    qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x279u, "theBlock->extra < kMinChunkSize");
  if ( v6 + *(unsigned int *)(a3 - 4) > *(_QWORD *)(a1 + 8) + (unsigned __int64)*(unsigned int *)(a1 + 28) )
    qtisec_assert(
      "noship_src/services/heap/memheap_lite.c",
      0x27Cu,
      "((((mem_block_header_type *)theBlock)->forw_offset + (char *)theBlock) <= ((((char*)((mem_heap_type*)heap_ptr)->fi"
      "rst_block) + ((mem_heap_type*)heap_ptr)->total_bytes)))");
  if ( *(unsigned __int16 *)(a1 + 74) != (unsigned __int16)(*(_WORD *)(a3 - 8) ^ *(_WORD *)(a3 - 6) ^ *(_WORD *)(a3 - 4) ^ *(_WORD *)(a3 - 2)) )
    qtisec_assert(
      "noship_src/services/heap/memheap_lite.c",
      0x280u,
      "!(pblk[0]^pblk[1]^pblk[2]^pblk[3]^heap_ptr->magic_num_used)");
  if ( (*(_BYTE *)(a3 - 5) & 0xF) == 0 )
  {
    if ( *(_DWORD *)(a3 - 4) - 8 - (unsigned int)*(unsigned __int8 *)(a3 - 6) > *(_DWORD *)(a1 + 32) )
      qtisec_assert(
        "noship_src/services/heap/memheap_lite.c",
        0x287u,
        "(theBlock->forw_offset - sizeBlockHeader - theBlock->extra) <= heap_ptr->used_bytes");
    v8 = *(unsigned __int8 *)(a3 - 6) - *(_DWORD *)(a3 - 4) + *(_DWORD *)(a1 + 32) + 8;
    v9 = *(_DWORD *)(a1 + 28);
    *(_DWORD *)(a1 + 32) = v8;
    if ( v8 > v9 )
      qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x28Au, "heap_ptr->total_bytes >= heap_ptr->used_bytes");
    *(_BYTE *)(a3 - 5) = *(_BYTE *)(a3 - 5) & 0xF0 | 1;
    if ( v6 < *(_QWORD *)(a1 + 16) )
      *(_QWORD *)(a1 + 16) = v6;
    *(_WORD *)(a3 - 8) = *(_WORD *)(a3 - 6) ^ *(_WORD *)(a3 - 4) ^ *(_WORD *)(a3 - 2) ^ *(_WORD *)(a1 + 72);
    if ( !*(_DWORD *)(a1 + 32) )
    {
      v10 = *(_DWORD *)(a1 + 28);
      v11 = *(_QWORD *)(a1 + 8);
      *(_QWORD *)(a1 + 16) = v11;
      mem_init_block_header_isra_0(v11, v10);
      *(_BYTE *)(*(_QWORD *)(a1 + 8) + 3LL) = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 3LL) & 0xF | 0x10;
      v12 = *(_WORD **)(a1 + 8);
      v13 = v12[1];
      v14 = v12[3];
      *(_DWORD *)(a1 + 24) = 1;
      *v12 = v13 ^ v12[2] ^ v14 ^ *(_WORD *)(a1 + 72);
    }
  }
  v15 = *(void (__fastcall **)(__int64))(a1 + 56);
  if ( v15 )
    v15(a1);
  return 1LL;
}



__int64 __fastcall mem_get_buffer_size(__int64 a1)
{
  if ( a1 )
    return (unsigned int)(*(_DWORD *)(a1 - 4) - 8);
  else
    return 0LL;
}



__int64 __fastcall mem_init_heap(int *a1, __int64 *a2, __int64 a3, unsigned __int64 a4)
{
  int v8; // w0
  __int64 v9; // x21
  __int64 i; // x0
  __int64 v11; // x4
  unsigned __int16 v12; // w1
  __int16 v13; // w1
  int v14; // w21
  _WORD *v15; // x1
  __int16 v16; // w2
  __int16 v17; // w3
  __int16 v18; // w0
  __int16 v19; // w2
  __int16 v20; // w0

  if ( !a1 )
    qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x138u, "heap_ptr");
  if ( !a2 )
    qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x139u, "mem_magic_number");
  if ( !*a2 )
    qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x13Au, "mem_magic_number->magic_num");
  if ( !a2[1] )
    qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x13Bu, "mem_magic_number->magic_num_index_array");
  if ( *((_WORD *)a2 + 8) )
    qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x13Du, "mem_magic_number->magic_num_index < 1");
  v8 = *a1;
  if ( !*a1 || v8 != *(_DWORD *)(*a2 + 4LL * *((unsigned __int16 *)a1 + 38)) )
  {
    qtiseclib_cb_memset(a1, 0LL, 80LL);
    if ( !a3 )
      qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x147u, "heap_mem_ptr");
    if ( !a4 )
      qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x148u, "heap_mem_size");
    if ( a4 <= 0x1E )
      qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x149u, "heap_mem_size >= (2*kMinChunkSize-1)");
    v9 = a3 + a4;
    while ( (a3 & 0xF) != 0 )
      ++a3;
    *((_QWORD *)a1 + 8) = a3;
    qtiseclib_cb_memset(a3, 0LL, 4LL);
    *((_QWORD *)a1 + 6) = mem_heap_enter_crit_sect;
    *((_QWORD *)a1 + 7) = mem_heap_leave_crit_sect;
    for ( i = a3 + 4; (i & 0xF) != 0; ++i )
      ;
    v11 = *a2;
    v12 = *(_WORD *)(a2[1] + 2LL * *((unsigned __int16 *)a2 + 8));
    *((_QWORD *)a1 + 1) = i;
    *((_QWORD *)a1 + 2) = i;
    *(_DWORD *)(v11 + 4LL * v12) = -1412571974;
    *((_WORD *)a1 + 38) = v12;
    *((_WORD *)a1 + 36) = -21555;
    *((_WORD *)a1 + 37) = -21555;
    v13 = *((_WORD *)a2 + 8);
    *a1 = -1412571974;
    *((_WORD *)a2 + 8) = v13 + 1;
    v14 = 16 * ((v9 - i) / 16);
    mem_init_block_header_isra_0(i, v14);
    *(_BYTE *)(*((_QWORD *)a1 + 1) + 3LL) = *(_BYTE *)(*((_QWORD *)a1 + 1) + 3LL) & 0xF | 0x10;
    v15 = (_WORD *)*((_QWORD *)a1 + 1);
    v16 = v15[1];
    v17 = v15[3];
    a1[6] = 1;
    a1[7] = v14;
    v18 = v15[2];
    a1[8] = 0;
    a1[9] = 0;
    v19 = v16 ^ v18;
    v20 = *((_WORD *)a1 + 36);
    a1[10] = 0;
    *v15 = v19 ^ v17 ^ v20;
  }
  return 1LL;
}



unsigned __int64 __fastcall mem_malloc(__int64 a1, _QWORD *a2, unsigned int a3)
{
  unsigned __int64 result; // x0
  void (__fastcall *v8)(__int64); // x1
  unsigned __int64 v9; // x21
  char v10; // w24
  __int16 *v11; // x2
  __int16 v12; // w3
  __int16 v13; // w4
  __int16 v14; // w1
  __int16 v15; // w0
  unsigned int v16; // w1
  const char *v17; // x2
  __int64 v18; // x25
  unsigned __int64 i; // x22
  unsigned __int64 v20; // x20
  unsigned int v21; // w0
  char v23; // w1
  _WORD *v24; // x1
  unsigned __int64 v25; // x20
  unsigned __int64 v26; // x1
  __int16 v27; // w1
  __int16 v28; // w2
  int v29; // w0
  char v30; // w0
  unsigned int v31; // w1
  unsigned int v32; // w0
  unsigned int v33; // w0
  void (__fastcall *v34)(__int64); // x1

  if ( !a1 )
    qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x1D2u, "heap_ptr != ((void *) 0)");
  if ( !a2 )
    qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x1D4u, "mem_magic_number");
  if ( !*a2 )
    qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x1D5u, "mem_magic_number->magic_num");
  if ( !a2[1] )
    qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x1D6u, "mem_magic_number->magic_num_index_array");
  result = 0LL;
  if ( a3 )
  {
    result = 0LL;
    if ( a3 <= *(_DWORD *)(a1 + 28) && a3 <= 0xFFFFFFE7 )
    {
      v8 = *(void (__fastcall **)(__int64))(a1 + 48);
      v9 = (a3 + 23LL) & 0x1FFFFFFF0LL;
      v10 = v9 - a3 - 8;
      if ( v8 )
        v8(a1);
      if ( *(_DWORD *)a1 != *(_DWORD *)(*a2 + 4LL * *(unsigned __int16 *)(a1 + 76)) )
        qtisec_assert(
          "noship_src/services/heap/memheap_lite.c",
          0x1EFu,
          "heap_ptr->magic_num == mem_magic_number->magic_num[heap_ptr->magic_num_index]");
      if ( !*(_QWORD *)(a1 + 8) )
        qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x2CAu, "heap_ptr->first_block");
      v11 = *(__int16 **)(a1 + 16);
      v12 = v11[2];
      v13 = *v11;
      v14 = v11[1];
      v15 = v11[3];
      if ( (*((_BYTE *)v11 + 3) & 0xF) == 1 )
      {
        if ( *(unsigned __int16 *)(a1 + 72) != (unsigned __int16)(v12 ^ v15 ^ v13 ^ v14) )
        {
          v16 = 718;
          v17 = "!(pblk[0]^pblk[1]^pblk[2]^pblk[3]^heap_ptr->magic_num_free)";
          goto LABEL_25;
        }
      }
      else if ( *(unsigned __int16 *)(a1 + 74) != (unsigned __int16)(v13 ^ v14 ^ v12 ^ v15) )
      {
        v16 = 722;
        v17 = "!(pblk[0]^pblk[1]^pblk[2]^pblk[3]^heap_ptr->magic_num_used)";
LABEL_25:
        qtisec_assert("noship_src/services/heap/memheap_lite.c", v16, v17);
      }
      v18 = *(unsigned int *)(a1 + 24);
      for ( i = mem_get_next_block(a1, *(_QWORD *)(a1 + 16)); ; i = mem_get_next_block(a1, i) )
      {
        if ( v18 <= 0 )
        {
          v25 = 0LL;
          goto LABEL_53;
        }
        if ( !*(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL) )
          qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x2DCu, "heap_ptr->next_block->forw_offset > 0");
        if ( !*(_DWORD *)(i + 4) )
          qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x2DDu, "followingBlock->forw_offset > 0");
        if ( (*(_BYTE *)(*(_QWORD *)(a1 + 16) + 3LL) & 0xF) != 0 )
          break;
LABEL_40:
        *(_QWORD *)(a1 + 16) = i;
        --v18;
      }
      while ( 1 )
      {
        v20 = *(_QWORD *)(a1 + 16);
        v21 = *(_DWORD *)(v20 + 4);
        if ( v9 <= v21 )
          break;
        if ( (*(_BYTE *)(i + 3) & 0xF) == 0 || i <= v20 )
          goto LABEL_40;
        --v18;
        v23 = *(_BYTE *)(v20 + 3);
        *(_DWORD *)(v20 + 4) = *(_DWORD *)(i + 4) + v21;
        *(_BYTE *)(v20 + 3) = v23 & 0xF | (16 * ((*(_BYTE *)(i + 3) >> 4) & 0xF));
        v24 = *(_WORD **)(a1 + 16);
        *v24 = v24[3] ^ *(_WORD *)(a1 + 72) ^ v24[1] ^ v24[2];
        --*(_DWORD *)(a1 + 24);
        *(_DWORD *)i = 0;
        *(_DWORD *)(i + 4) = 0;
        i = mem_get_next_block(a1, (__int64)v24);
      }
      if ( !v21 )
        qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x1F6u, "freeBlock->forw_offset > 0");
      v26 = *(unsigned int *)(v20 + 4);
      if ( v9 < v26 )
      {
        mem_init_block_header_isra_0(v20 + v9, v26 - v9);
        *(_BYTE *)(v20 + v9 + 3) = *(_BYTE *)(v20 + v9 + 3) & 0xF | (16 * ((*(_BYTE *)(v20 + 3) >> 4) & 0xF));
        *(_BYTE *)(v20 + 3) &= 0xFu;
        v27 = *(_WORD *)(v20 + v9 + 2);
        v28 = *(_WORD *)(v20 + v9 + 6);
        v29 = *(_DWORD *)(a1 + 24) + 1;
        *(_DWORD *)(v20 + 4) = v9;
        *(_DWORD *)(a1 + 24) = v29;
        *(_WORD *)(v20 + v9) = v27 ^ *(_WORD *)(v20 + v9 + 4) ^ v28 ^ *(_WORD *)(a1 + 72);
      }
      v30 = *(_BYTE *)(v20 + 3);
      *(_BYTE *)(v20 + 2) = v10;
      *(_BYTE *)(v20 + 3) = v30 & 0xF0;
      *(_QWORD *)(a1 + 16) = mem_get_next_block(a1, v20);
      v31 = *(_DWORD *)(a1 + 28);
      v32 = a3 + *(_DWORD *)(a1 + 32);
      *(_DWORD *)(a1 + 32) = v32;
      if ( v32 > v31 )
        qtisec_assert(
          "noship_src/services/heap/memheap_lite.c",
          0x210u,
          "heap_ptr->total_bytes >= heap_ptr->used_bytes");
      v33 = *(_DWORD *)(a1 + 32);
      if ( v33 > *(_DWORD *)(a1 + 36) )
        *(_DWORD *)(a1 + 36) = v33;
      if ( a3 > *(_DWORD *)(a1 + 40) )
        *(_DWORD *)(a1 + 40) = a3;
      *(_WORD *)v20 = *(_WORD *)(v20 + 2) ^ *(_WORD *)(v20 + 4) ^ *(_WORD *)(v20 + 6) ^ *(_WORD *)(a1 + 74);
      v25 = v20 + 8;
LABEL_53:
      v34 = *(void (__fastcall **)(__int64))(a1 + 56);
      result = v25;
      if ( v34 )
      {
        v34(a1);
        return v25;
      }
    }
  }
  return result;
}



unsigned __int64 __fastcall mem_realloc(__int64 a1, _QWORD *a2, __int64 a3, unsigned int a4)
{
  __int64 v9; // x1
  unsigned __int64 v10; // x0
  unsigned __int64 v11; // x23
  __int64 v12; // x2

  if ( !a1 )
    qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x33Fu, "heap_ptr != ((void *) 0)");
  if ( !a2 )
    qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x340u, "mem_magic_number");
  if ( !*a2 )
    qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x341u, "mem_magic_number->magic_num");
  if ( !a2[1] )
    qtisec_assert("noship_src/services/heap/memheap_lite.c", 0x342u, "mem_magic_number->magic_num_index_array");
  if ( *(_DWORD *)a1 != *(_DWORD *)(*a2 + 4LL * *(unsigned __int16 *)(a1 + 76)) )
    qtisec_assert(
      "noship_src/services/heap/memheap_lite.c",
      0x343u,
      "heap_ptr->magic_num == mem_magic_number->magic_num[heap_ptr->magic_num_index]");
  if ( !a3 )
    return mem_malloc(a1, a2, a4);
  if ( a4 )
  {
    v10 = mem_malloc(a1, a2, a4);
    v11 = v10;
    v9 = 0LL;
    if ( v10 )
    {
      LODWORD(v12) = *(_DWORD *)(a3 - 4) - 8;
      if ( (unsigned int)v12 > a4 )
        v12 = a4;
      else
        v12 = (unsigned int)v12;
      qtiseclib_cb_memcpy(v10, a3, v12);
      mem_free(a1, a2, a3);
      return v11;
    }
  }
  else
  {
    mem_free(a1, a2, a3);
    return 0LL;
  }
  return v9;
}



