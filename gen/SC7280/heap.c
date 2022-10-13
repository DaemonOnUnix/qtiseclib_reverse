/*0000000000000000 b $d
0000000000000000 b $d
0000000000000000 b $d
0000000000000000 b $d
0000000000000000 d $d
0000000000000000 b $d
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 b atfHeap
0000000000000000 b atfHeapDesc
0000000000000000 b heapHasInit
0000000000000000 d magic_num
0000000000000000 b magic_num_index_array
                 U mem_free
                 U mem_init_heap
0000000000000000 b mem_magic_number
                 U mem_malloc
                 U mem_realloc
0000000000000000 T qtisec_free
                 U qtiseclib_cb_log
0000000000000000 T qtisec_malloc
0000000000000000 T qtisec_realloc
*/
#include "heap.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall qtisec_free(__int64 a1)
{
  return mem_free((__int64)atfHeapDesc, &mem_magic_number, a1);
}



    if ( *a2 || (*a3 = v8, v11 = qtisec_malloc(4LL * (v8 & 0x3FFFFFFF)), (*a2 = v11) != 0) )
    {
      if ( v8 <= *a3 )
      {
        v12 = (_DWORD *)*a2;
        for ( i = *(_QWORD *)(v5 + 24); *(_DWORD *)i; i += 24LL )
        {
          if ( (*(_DWORD *)(v5 + 56) & 0x800000) == 0 || *(unsigned __int8 *)(i + 14) != 255 )
            *v12++ = *(_DWORD *)i;
        }
        *a3 = v8;
        return 0LL;
      }
      *a3 = v8;
    }
    else
    {
      *a3 = 0;
    }
    return 0xFFFFFFFFLL;
  }
  return 0xFFFFFFFFLL;
}



unsigned __int64 __fastcall qtisec_realloc(__int64 a1, unsigned __int64 a2)
{
  unsigned __int64 v3; // x0
  unsigned __int64 v4; // x19
  bool v5; // zf

  if ( !heapHasInit )
  {
    qtiseclib_cb_log(10LL, "Heap un-initialized !");
    return 0LL;
  }
  if ( a2 > 0xFFFF )
  {
    qtiseclib_cb_log(10LL, "Heap length 0x%x not supported !", a2);
    return 0LL;
  }
  v3 = mem_realloc((__int64)atfHeapDesc, &mem_magic_number, a1, a2);
  v5 = a2 == 0;
  v4 = v3;
  v5 = !v5 && v3 == 0;
  if ( v5 )
    qtiseclib_cb_log(10LL, "Heap Exhausted !");
  return v4;
}



