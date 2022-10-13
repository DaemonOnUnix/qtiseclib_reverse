/*0000000000000000 r $d
0000000000000000 t $x
0000000000000000 r qtimer_frames
0000000000000000 T timer_qtimer_get_frames_list
*/
#include "timer_data.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
_QWORD *__fastcall timer_qtimer_get_frames_list(_QWORD *result, _DWORD *a2)
{
  bool v2; // zf

  if ( result )
    v2 = a2 == 0LL;
  else
    v2 = 1;
  if ( !v2 )
  {
    *result = &qtimer_frames;
    result = (_QWORD *)(&loc_8 + 1);
    *a2 = 9;
  }
  return result;
}



