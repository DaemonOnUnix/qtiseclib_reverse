/*0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 T HAL_clk_ConfigClockMux
0000000000000000 T HAL_clk_ConfigDFSMux
0000000000000000 T HAL_clk_DisableClock
0000000000000000 T HAL_clk_DisablePowerDomain
0000000000000000 T HAL_clk_DisableSource
0000000000000000 T HAL_clk_EnableClock
0000000000000000 T HAL_clk_EnableDFS
0000000000000000 T HAL_clk_EnablePowerDomain
0000000000000000 T HAL_clk_EnableSource
0000000000000000 t HAL_clk_GenericConfigMuxOffs.part.0
0000000000000000 T HAL_clk_IsClockOn
0000000000000000 T HAL_clk_IsPowerDomainOn
0000000000000000 T HAL_clk_WaitForClockOn
0000000000000000 T HAL_clk_WaitForPowerDomainOn
                 U qtiseclib_cb_udelay
*/
#include "HALclk.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
_DWORD *__fastcall HAL_clk_ConfigClockMux(_DWORD *result, unsigned int *a2)
{
  bool v2; // zf
  _DWORD **v3; // x9

  if ( a2 )
    v2 = result == 0LL;
  else
    v2 = 1;
  if ( !v2 && *(_QWORD *)result )
  {
    HAL_clk_GenericConfigMuxOffs_part_0((unsigned __int64)result, a2, 4u, 8u, 0xCu, 0x10u);
    result = *v3;
    **v3 |= 1u;
    while ( (*result & 1) != 0 )
      ;
  }
  return result;
}



unsigned __int64 __fastcall HAL_clk_ConfigDFSMux(unsigned __int64 result, __int64 a2)
{
  unsigned int v2; // w2

  if ( result )
  {
    v2 = *(unsigned __int8 *)(a2 + 10);
    if ( *(_DWORD *)(result + 16) > v2 )
      return HAL_clk_GenericConfigMuxOffs_part_0(
               result,
               (unsigned int *)a2,
               4 * v2 + 28,
               4 * v2 + 92,
               4 * v2 + 156,
               4 * v2 + 220);
  }
  return result;
}



__int64 __fastcall HAL_clk_DisableClock(__int64 result)
{
  unsigned __int64 v1; // x1
  int v2; // w0

  LODWORD(v1) = *(_DWORD *)(result + 8);
  if ( (_DWORD)v1 )
  {
    v1 = (unsigned int)v1;
    v2 = *(_DWORD *)(result + 12);
  }
  else
  {
    v1 = *(_QWORD *)result;
    if ( !*(_QWORD *)result )
      return result;
    v2 = 1;
  }
  result = *(_DWORD *)v1 & (unsigned int)~v2;
  *(_DWORD *)v1 = result;
  return result;
}



_DWORD *__fastcall HAL_clk_DisablePowerDomain(_DWORD **a1)
{
  _DWORD *result; // x0

  result = *a1;
  if ( result )
    *result |= 1u;
  return result;
}



__int64 __fastcall HAL_clk_DisableSource(__int64 a1)
{
  __int64 result; // x0

  result = *(unsigned int *)(a1 + 8);
  if ( (_DWORD)result )
  {
    result = MEMORY[0x153030] & (unsigned int)~(_DWORD)result;
    MEMORY[0x153030] = result;
  }
  return result;
}



         HAL_clk_EnableClock(a1 + 8),
         (v4 = *(_QWORD *)(a1 + 40)) == 0)
     || (v5 = *(_DWORD *)(v4 + 16), *(_DWORD *)(v4 + 16) = v5 + 1, v5)
     || (HAL_clk_EnablePowerDomain(v4), (unsigned int)HAL_clk_WaitForPowerDomainOn((_DWORD **)v4)))
    && (unsigned int)HAL_clk_WaitForClockOn(v3) )
  {
    qtiseclib_cb_spin_unlock(&ClockMutex);
    return 0LL;
  }
  else
  {
    qtiseclib_cb_spin_unlock(&ClockMutex);
    return 0xFFFFFFFFLL;
  }
}



__int64 __fastcall HAL_clk_EnableDFS(__int64 result)
{
  __int64 v1; // x1

  v1 = *(_QWORD *)result;
  if ( *(_QWORD *)result )
  {
    result = *(unsigned int *)(result + 16);
    if ( (_DWORD)result )
    {
      result = 33LL;
      *(_DWORD *)(v1 + 20) = 33;
    }
  }
  return result;
}



__int64 __fastcall HAL_clk_EnablePowerDomain(__int64 result)
{
  unsigned int *v1; // x2
  unsigned int v2; // w1

  v1 = *(unsigned int **)result;
  if ( *(_QWORD *)result )
  {
    v2 = *v1 & 0xFFFFFFFE;
    *(_DWORD *)(result + 8) = !(*(_BYTE *)v1 & 1);
    *v1 = v2;
  }
  return result;
}



__int64 *__fastcall HAL_clk_EnableSource(__int64 *result)
{
  int v1; // w3

  v1 = *((_DWORD *)result + 2);
  if ( v1 )
  {
    result = (__int64 *)*result;
    MEMORY[0x153030] |= v1;
    if ( result )
    {
      while ( (*(_DWORD *)result & 0x40000000) == 0 )
        ;
    }
  }
  return result;
}



__int64 __fastcall HAL_clk_IsClockOn(int **a1)
{
  int *v1; // x0

  v1 = *a1;
  if ( v1 )
    return (unsigned int)(*v1 >> 31);
  else
    return 0LL;
}



  if ( !v3 || (result = HAL_clk_IsPowerDomainOn(v3), (_DWORD)result) )
  {
    *a2 = 1;
    return 0LL;
  }
  else
  {
    *a2 = 0;
  }
  return result;
}



__int64 __fastcall HAL_clk_WaitForClockOn(int **a1)
{
  int v2; // w20

  if ( !*a1 )
    return 0xFFFFFFFFLL;
  if ( (**a1 & 2) != 0 )
    return 0LL;
  v2 = 100;
  while ( 1 )
  {
    if ( (unsigned int)HAL_clk_IsClockOn(a1) )
      return 0LL;
    if ( !--v2 )
      break;
    qtiseclib_cb_udelay(1LL);
  }
  return 0xFFFFFFFFLL;
}



__int64 __fastcall HAL_clk_WaitForPowerDomainOn(_DWORD **a1)
{
  int v2; // w19
  __int64 result; // x0

  v2 = 10000;
  qtiseclib_cb_udelay(1LL);
  while ( 1 )
  {
    result = HAL_clk_IsPowerDomainOn(a1);
    if ( !(_DWORD)result )
      break;
    if ( !--v2 )
      return 0xFFFFFFFFLL;
    qtiseclib_cb_udelay(1LL);
  }
  return result;
}



