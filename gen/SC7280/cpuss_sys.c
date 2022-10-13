/*0000000000000000 t $x
0000000000000010 T cpuss_dmb
0000000000000008 T cpuss_dsb
0000000000000018 T cpuss_isb
0000000000000000 T cpuss_read_isr
*/
#include "cpuss_sys.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
void cpuss_dmb()
{
  __dmb(0xFu);
}



void cpuss_dsb()
{
  __dsb(0xFu);
}



void cpuss_isb()
{
  __isb(0xFu);
}



unsigned __int64 cpuss_read_isr()
{
  return _ReadStatusReg(ARM64_SYSREG(3, 0, 12, 1, 0));
}



