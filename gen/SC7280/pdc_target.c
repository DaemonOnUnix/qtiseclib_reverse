/*0000000000000000 b $d
0000000000000000 t $x
0000000000000000 t $x
                 U g_pdcGpioInputs
                 U g_pdcGPIOInputSize
                 U g_pdcGpioMapping
                 U g_pdcGPIOMappingSize
                 U g_pdcInterruptMapping
                 U g_pdcInterruptTableSize
                 U pdcHAL_setOwner
0000000000000000 B PDC_LOCK_NAME
0000000000000000 T pdcTarget_postInit
0000000000000000 T pdcTarget_preInit
*/
#include "pdc_target.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

__int64 pdcTarget_preInit()
{
  __int64 result; // x0

  for ( result = 0LL; result != 98; ++result )
  {
    g_pdcGpioMapping[3 * (int)result + 1] = &g_pdcGpioInputs[2 * result];
    g_pdcGpioInputs[2 * (int)result + 1] = result;
  }
  return result;
}



