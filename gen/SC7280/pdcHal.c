/*0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
                 U g_pdcInterrupts
0000000000000000 t HALInternal_setInterruptState
                 U pdc_getTriggerConfig
0000000000000000 T pdcHAL_disable
0000000000000000 T pdcHAL_enable
0000000000000000 T pdcHAL_setGPIOConfig
0000000000000000 T pdcHAL_setOwner
0000000000000000 T pdcHAL_setTriggerConfig
*/
#include "pdcHal.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall pdcHAL_disable(unsigned int a1, int a2)
{
  return HALInternal_setInterruptState(a1, a2, 0);
}



__int64 __fastcall pdcHAL_enable(unsigned int a1, int a2)
{
  return HALInternal_setInterruptState(a1, a2, 1u);
}



__int64 __fastcall pdcHAL_setGPIOConfig(int a1, __int64 a2, _DWORD *a3)
{
  return pdcHAL_setTriggerConfig(a1, 1, a3);
}



int *__fastcall pdcHAL_setOwner(int a1, int a2, char a3)
{
  int *result; // x0

  if ( a2 )
    a1 += hmss_pcu_memory_base[0];
  result = (int *)(4LL * ((a1 + 46666112) & 0x3FFFFFFF));
  *result = a3 & 7;
  return result;
}



__int64 __fastcall pdcHAL_setTriggerConfig(int a1, int a2, _DWORD *a3)
{
  int v3; // w4

  if ( a2 )
    a1 += hmss_pcu_memory_base[0];
  v3 = a3[1];
  *(_DWORD *)(unsigned int)((v3 << 16) + 186646800 + 4 * a1) = *a3 & 7;
  *(_DWORD *)(unsigned int)(4 * a1 + 186664448) = v3 & 7;
  return 0LL;
}



