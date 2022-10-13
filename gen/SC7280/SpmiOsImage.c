/*0000000000000000 t $x
0000000000000000 t $x
                 U pSpmiBlockInfo
                 U qtiseclib_cb_udelay
0000000000000000 T SpmiOs_Init
0000000000000000 T SpmiOs_Wait
*/
#include "SpmiOsImage.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall SpmiOs_Init(_QWORD *a1)
{
  if ( !pSpmiBlockInfo )
    return 13LL;
  *a1 = pSpmiBlockInfo;
  return 0LL;
}




