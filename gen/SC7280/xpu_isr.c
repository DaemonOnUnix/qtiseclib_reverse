/*0000000000000000 t $x
                 U dbg_is_sdi_enable
                 U g_xpu_base_addr_array
                 U g_xpu_base_addr_array_count
0000000000000000 T msm_xpu_print_log
                 U qtiseclib_cb_log
                 U qtiseclib_cb_switch_console_to_crash_state
                 U xpu_err_pos_to_hal_map
                 U xpu_non_sec_intr_status_reg
                 U xpu_sec_intr_status_reg
*/
#include "xpu_isr.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall msm_xpu_print_log(int *a1)
{
  void **v2; // x1
  __int64 v3; // x0
  __int64 v4; // x25
  __int64 result; // x0
  int v6; // w28
  char *v7; // x19
  int v8; // w4
  int v9; // w0
  unsigned int v10; // w21
  unsigned int v11; // w20
  __int64 v12; // x5
  char *v13; // x1
  unsigned int *v14; // x24
  unsigned int v15; // t1
  __int64 v16; // [xsp+60h] [xbp+60h]
  int v17; // [xsp+6Ch] [xbp+6Ch]
  __int16 v18; // [xsp+70h] [xbp+70h] BYREF
  __int64 v19; // [xsp+78h] [xbp+78h] BYREF

  v19 = 0LL;
  if ( (unsigned __int8)dbg_is_sdi_enable() )
    qtiseclib_cb_switch_console_to_crash_state();
  qtiseclib_cb_log(40LL, "xpu: ISR begin");
  if ( *a1 )
  {
    if ( *a1 != 1 )
    {
      qtiseclib_cb_log(10LL, "XPU ERROR: Invalid!!");
      goto LABEL_9;
    }
    qtiseclib_cb_log(10LL, "XPU ERROR: Non Sec!!");
    v2 = &xpu_non_sec_intr_status_reg;
    v3 = 33300480LL;
  }
  else
  {
    qtiseclib_cb_log(10LL, "XPU ERROR: Sec!!");
    v2 = &xpu_sec_intr_status_reg;
    v3 = 33308672LL;
  }
  LODWORD(v19) = *(_DWORD *)v3 & (unsigned int)v2[1];
  HIDWORD(v19) = *(_DWORD *)v2[2] & (unsigned int)v2[3];
LABEL_9:
  v4 = 0LL;
  result = qtiseclib_cb_log(10LL, "XPU INTR 0:1 >> %08x:%08x", (unsigned int)v19, HIDWORD(v19));
  do
  {
    v6 = *(_DWORD *)((char *)&v19 + v4);
    if ( v6 )
    {
      v7 = (char *)&xpu_err_pos_to_hal_map + 64 * v4;
      do
      {
        if ( (v6 & *(_DWORD *)v7) != 0 )
        {
          v8 = (unsigned __int8)v7[4];
          if ( (unsigned int)(v8 - 1) <= 0x16 )
          {
            v9 = *a1;
            v18 = 32;
            if ( v9 )
            {
              if ( v9 == 1 )
                v10 = 2176;
              else
                v10 = 0;
            }
            else
            {
              v10 = 2048;
              LOBYTE(v18) = 83;
            }
            v11 = 0;
            v12 = 24LL;
            while ( v11 < g_xpu_base_addr_array_count )
            {
              v13 = (char *)&g_xpu_base_addr_array + (int)v11 * v12;
              if ( v8 == *(_DWORD *)v13 )
              {
                v16 = v12;
                v14 = (unsigned int *)(v10 + *((_QWORD *)v13 + 1));
                v17 = v8;
                qtiseclib_cb_log(10LL, "%sEAR0 0x%x", (const char *)&v18, *v14);
                qtiseclib_cb_log(10LL, "%sEAR1 0x%x", (const char *)&v18, v14[1]);
                qtiseclib_cb_log(10LL, "%sESR 0x%x", (const char *)&v18, v14[2]);
                qtiseclib_cb_log(10LL, "%sESYNR0 0x%x", (const char *)&v18, v14[4]);
                qtiseclib_cb_log(10LL, "%sESYNR1 0x%x", (const char *)&v18, v14[5]);
                qtiseclib_cb_log(10LL, "%sESYNR2 0x%x", (const char *)&v18, v14[6]);
                qtiseclib_cb_log(10LL, "%sESYNR3 0x%x", (const char *)&v18, v14[7]);
                qtiseclib_cb_log(10LL, "%sESYNR4 0x%x", (const char *)&v18, v14[8]);
                v14[3] = 0;
                v8 = v17;
                v12 = v16;
              }
              ++v11;
            }
          }
        }
        v15 = *((_DWORD *)v7 + 2);
        v7 += 8;
        result = v15;
      }
      while ( v15 );
    }
    v4 += 4LL;
  }
  while ( v4 != 8 );
  return result;
}



