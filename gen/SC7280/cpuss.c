/*0000000000000000 t $x
                 U cluster_aarch64_sysini
                 U cpu_aarch64_sysini
                 U cpuss_aarch64_por_sysini
                 U interconnect_aarch64_sysini
0000000000000000 T qtiseclib_cpuss_reset_asm
0000000000000020 t qtiseclib_cpuss_reset_asm_cmn
0000000000000034 T qtiseclib_kryo6_gold_reset_asm
0000000000000040 T qtiseclib_kryo6_silver_reset_asm
*/
#include "cpuss.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
unsigned __int64 __fastcall qtiseclib_cpuss_reset_asm(int a1)
{
  if ( !a1 )
  {
    cpuss_aarch64_por_sysini(1LL);
    interconnect_aarch64_sysini(1LL);
  }
  return cluster_aarch64_sysini(1uLL);
}



__int64 qtiseclib_kryo6_gold_reset_asm()
{
  return cpu_aarch64_sysini(1LL);
}



__int64 qtiseclib_kryo6_silver_reset_asm()
{
  return cpu_aarch64_sysini(1LL);
}



