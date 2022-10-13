/*0000000000000000 t $x
0000000000000000 t $x
                 U g_pdcGpioInputs
                 U g_pdcGPIOInputSize
                 U g_pdcGpioMapping
                 U g_pdcGPIOMappingSize
                 U g_pdcInterruptMapping
                 U g_pdcInterruptTableSize
0000000000000000 T pdcMap_getGpioTable
0000000000000000 T pdcMap_getInterruptTable
                 U qtisec_assert
*/
#include "mapping.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall pdcMap_getGpioTable(__int64 a1)
{
  if ( !a1 )
    qtisec_assert("noship_src/drivers/pdc/interrupt/common/mapping.c", 0x48u, "((void *) 0) != (gpioMap)");
  *(_QWORD *)a1 = g_pdcGpioInputs;
  *(_QWORD *)(a1 + 8) = g_pdcGpioMapping;
  *(_DWORD *)(a1 + 16) = 98;
  *(_DWORD *)(a1 + 20) = 98;
  return 0LL;
}



__int64 __fastcall pdcMap_getInterruptTable(__int64 a1)
{
  if ( !a1 )
    qtisec_assert("noship_src/drivers/pdc/interrupt/common/mapping.c", 0x3Fu, "((void *) 0) != (intMap)");
  *(_QWORD *)a1 = g_pdcInterruptMapping;
  *(_DWORD *)(a1 + 8) = 70;
  return 0LL;
}



