/*00000000000000b0 t $d
0000000000000000 t $x
0000000000000000 T cluster_aarch64_sysini
                 U cortex_a78_aarch64_sysini
0000000000000088 T cpu_aarch64_sysini
0000000000000034 T cpuss_aarch64_por_sysini
                 U hoya_10_cluster_aarch64_sysini
                 U hoya_10_cpuss_aarch64_por_sysini
                 U hoya_10_interconnect_aarch64_sysini
                 U hoya_11_cluster_aarch64_sysini
                 U hoya_11_cpuss_aarch64_por_sysini
                 U hoya_20_cluster_aarch64_sysini
                 U hoya_20_cpuss_aarch64_por_sysini
0000000000000068 T interconnect_aarch64_sysini
                 U kryo500_silver_aarch64_sysini
00000000000000b0 T SYSINI_VERSION
*/
#include "sysini_api.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
unsigned __int64 __fastcall cluster_aarch64_sysini(unsigned __int64 result)
{
  if ( (MEMORY[0x1FC8000] | 0xFFFF) == 1611595775 )
    return hoya_11_cluster_aarch64_sysini(result);
  if ( (MEMORY[0x1FC8000] | 0xFFFF) == 1612251135 )
    return hoya_20_cluster_aarch64_sysini(result);
  return hoya_10_cluster_aarch64_sysini(result);
}



__int64 __fastcall cpu_aarch64_sysini(__int64 result)
{
  unsigned __int64 v1; // x2

  v1 = _ReadStatusReg(ARM64_SYSREG(3, 0, 0, 0, 0)) & 0xFFFFFFFFFF0FFFF0LL;
  if ( v1 == 1091555408 )
    return kryo500_silver_aarch64_sysini(result);
  if ( v1 == 1091556368 )
    return cortex_a78_aarch64_sysini(result);
  return result;
}



__int64 __fastcall cpuss_aarch64_por_sysini(__int64 result)
{
  if ( (MEMORY[0x1FC8000] | 0xFFFF) == 1611595775 )
    return hoya_11_cpuss_aarch64_por_sysini(result);
  if ( (MEMORY[0x1FC8000] | 0xFFFF) == 1612251135 )
    return hoya_20_cpuss_aarch64_por_sysini(result);
  return hoya_10_cpuss_aarch64_por_sysini(result);
}



__int64 __fastcall interconnect_aarch64_sysini(__int64 result)
{
  if ( (MEMORY[0x1FC8000] | 0xFFFF) == 1610678271 )
    return hoya_10_interconnect_aarch64_sysini(result);
  return result;
}




