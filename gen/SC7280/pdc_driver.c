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
0000000000000018 C g_pdcGpios
0000000000000010 C g_pdcInterrupts
0000000000000000 t gpio_findEntry
0000000000000000 t int_findEntry
0000000000000000 T pdc_getTriggerConfig
0000000000000000 T pdcGpio_config
0000000000000000 T pdcGpio_disable
0000000000000000 T pdcGpio_enable
0000000000000000 T pdcGpio_unconfig
                 U pdcHAL_disable
                 U pdcHAL_enable
                 U pdcHAL_setGPIOConfig
                 U pdcHAL_setTriggerConfig
0000000000000000 T pdc_initialize
0000000000000000 T pdcInt_config
0000000000000000 T pdcInt_disable
0000000000000000 T pdcInt_enable
                 U pdcMap_getGpioTable
                 U pdcMap_getInterruptTable
                 U qtisec_assert
*/
#include "pdc_driver.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
unsigned __int64 __fastcall pdc_getTriggerConfig(int a1, unsigned int a2)
{
  __int64 v3; // x0
  unsigned int v4; // w1

  if ( a1 )
  {
    if ( !g_pdcGpios[1] )
      qtisec_assert(
        "noship_src/drivers/pdc/interrupt/common/pdc_driver.c",
        0x185u,
        "((void *) 0) != (g_pdcGpios.map.mux_map)");
    if ( a2 >= g_cmd_set[1] )
      qtisec_assert("noship_src/drivers/pdc/interrupt/common/pdc_driver.c", 0x186u, "index < g_pdcGpios.numMux");
    v4 = 24;
    v3 = g_pdcGpios[1];
  }
  else
  {
    if ( !g_pdcInterrupts[0] )
      qtisec_assert(
        "noship_src/drivers/pdc/interrupt/common/pdc_driver.c",
        0x180u,
        "((void *) 0) != (g_pdcInterrupts.map)");
    if ( hmss_pcu_memory_base[0] <= a2 )
      qtisec_assert("noship_src/drivers/pdc/interrupt/common/pdc_driver.c", 0x181u, "index < g_pdcInterrupts.numInt");
    v3 = g_pdcInterrupts[0];
    v4 = 12;
  }
  return v3 + a2 * (unsigned __int64)v4;
}



__int64 __fastcall pdcGpio_config(int a1, _DWORD *a2, _DWORD *a3)
{
  unsigned __int16 *Entry; // x20
  __int64 result; // x0
  unsigned int v7; // w0
  __int64 v8; // x0
  int v9; // w1
  __int64 v10; // x2
  __int64 v11; // x1
  unsigned int v12; // [xsp+3Ch] [xbp+3Ch] BYREF

  if ( !a2 )
    return 19LL;
  if ( !a3 )
    qtisec_assert("noship_src/drivers/pdc/interrupt/common/pdc_driver.c", 0xECu, "((void *) 0) != (subsystemInterrupt)");
  Entry = gpio_findEntry(a1, &v12);
  result = 18LL;
  if ( Entry )
  {
    v7 = Entry[1];
    if ( v7 == 0xFFFF )
    {
      v9 = 0;
      v10 = g_pdcGpios[1];
      while ( v9 != HIDWORD(g_pdcGpios[2]) )
      {
        v8 = v10;
        v10 += 24LL;
        if ( !*(_QWORD *)(v10 - 16) )
        {
          Entry[1] = v9;
          *(_QWORD *)(v8 + 8) = Entry;
          goto LABEL_16;
        }
        ++v9;
      }
      return 20LL;
    }
    else
    {
      if ( v7 >= g_cmd_set[1] )
        qtisec_assert(
          "noship_src/drivers/pdc/interrupt/common/pdc_driver.c",
          0x116u,
          "gpioInput->mux_idx_num < g_pdcGpios.numMux");
      v8 = g_pdcGpios[1] + 24LL * Entry[1];
LABEL_16:
      *(_DWORD *)v8 = *a2;
      *(_DWORD *)(v8 + 4) = a2[1];
      v11 = v12;
      *a3 = *(_DWORD *)(v8 + 16);
      return pdcHAL_setGPIOConfig(Entry[1], v11, a2);
    }
  }
  return result;
}



__int64 __fastcall pdcGpio_disable(int a1)
{
  unsigned __int16 *Entry; // x0
  unsigned int v2; // w2
  __int64 result; // x0

  Entry = gpio_findEntry(a1, 0LL);
  if ( !Entry )
    return 18LL;
  v2 = Entry[1];
  result = 19LL;
  if ( v2 != 0xFFFF )
    return pdcHAL_disable(v2, 1);
  return result;
}



__int64 __fastcall pdcGpio_enable(int a1)
{
  unsigned __int16 *Entry; // x0
  unsigned int v2; // w2
  __int64 result; // x0

  Entry = gpio_findEntry(a1, 0LL);
  if ( !Entry )
    return 18LL;
  v2 = Entry[1];
  result = 19LL;
  if ( v2 != 0xFFFF )
    return pdcHAL_enable(v2, 1);
  return result;
}



__int64 __fastcall pdcGpio_unconfig(int a1)
{
  unsigned __int16 *Entry; // x0
  unsigned int v2; // w2
  unsigned __int16 *v3; // x19
  __int64 result; // x0
  __int64 v5; // x1

  Entry = gpio_findEntry(a1, 0LL);
  if ( !Entry )
    return 18LL;
  v2 = Entry[1];
  v3 = Entry;
  result = 19LL;
  if ( v2 != 0xFFFF )
  {
    result = pdcHAL_disable(v2, 1);
    if ( !(_DWORD)result )
    {
      v5 = lmh_hsr_version[0] + 24LL * v3[1];
      *(_QWORD *)(v5 + 8) = 0LL;
      *(_DWORD *)(v5 + 4) = -1;
      v3[1] = -1;
    }
  }
  return result;
}



__int64 pdc_initialize()
{
  __int64 result; // x0

  if ( (unsigned int)pdcMap_getInterruptTable((__int64)g_pdcInterrupts) )
    qtisec_assert(
      "noship_src/drivers/pdc/interrupt/common/pdc_driver.c",
      0x171u,
      "PDC_SUCCESS == pdcMap_getInterruptTable(&g_pdcInterrupts)");
  result = pdcMap_getGpioTable((__int64)g_pdcGpios);
  if ( (_DWORD)result )
    qtisec_assert(
      "noship_src/drivers/pdc/interrupt/common/pdc_driver.c",
      0x173u,
      "PDC_SUCCESS == pdcMap_getGpioTable(&g_pdcGpios)");
  return result;
}



__int64 __fastcall pdcInt_config(int a1, __int64 a2)
{
  unsigned int Entry; // w0
  _DWORD *v3; // x5
  _DWORD *v4; // x3

  if ( !a2 )
    return 19LL;
  Entry = int_findEntry(a1);
  if ( Entry >= LODWORD(g_pdcInterrupts[1]) )
    return 18LL;
  v4 = (_DWORD *)(g_pdcInterrupts[0] + 12LL * Entry);
  *v4 = *v3;
  v4[1] = v3[1];
  return pdcHAL_setTriggerConfig(Entry, 0, v3);
}



__int64 __fastcall pdcInt_disable(int a1)
{
  unsigned int Entry; // w0

  Entry = int_findEntry(a1);
  if ( Entry >= hmss_pcu_memory_base[0] )
    return 18LL;
  else
    return pdcHAL_disable(Entry, 0);
}



__int64 __fastcall pdcInt_enable(int a1)
{
  unsigned int Entry; // w0

  Entry = int_findEntry(a1);
  if ( Entry >= hmss_pcu_memory_base[0] )
    return 18LL;
  else
    return pdcHAL_enable(Entry, 0);
}



