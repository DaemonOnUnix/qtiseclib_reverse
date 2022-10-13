/*0000000000000000 t $x
0000000000000000 t $x
                 U g_pdcGpioInputs
                 U g_pdcGPIOInputSize
                 U g_pdcGpioMapping
                 U g_pdcGPIOMappingSize
                 U g_pdcInterruptMapping
                 U g_pdcInterruptTableSize
0000000000000000 T mapOS_getGpioTable
0000000000000000 T mapOS_getInterruptTable
*/
#include "mapping_os.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall mapOS_getGpioTable(__int64 a1)
{
  *(_QWORD *)a1 = g_pdcGpioInputs;
  *(_QWORD *)(a1 + 8) = g_pdcGpioMapping;
  *(_DWORD *)(a1 + 16) = 98;
  *(_DWORD *)(a1 + 20) = 98;
  return 0LL;
}



__int64 __fastcall mapOS_getInterruptTable(__int64 a1)
{
  *(_QWORD *)a1 = g_pdcInterruptMapping;
  *(_DWORD *)(a1 + 8) = 70;
  return 0LL;
}



