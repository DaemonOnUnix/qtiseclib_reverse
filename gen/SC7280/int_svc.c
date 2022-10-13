/*0000000000000000 b $d
0000000000000000 b $d
0000000000000000 b $d
0000000000000000 b $d
0000000000000000 b $d
0000000000000000 b $d
0000000000000000 b $d
0000000000000000 b $d
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 b g_int_cpu_interruptible_state
0000000000000000 b g_int_cpu_on_state
0000000000000000 b g_int_svc_cpu_state_lock
0000000000000000 b g_int_svc_fiq_lock
0000000000000000 b g_int_swdog_target
0000000000000000 b g_isrs
0000000000000000 b g_mpidr_map
0000000000000000 b init_done.1195
0000000000000000 T int_svc_core_pos_to_mpidr
0000000000000000 T int_svc_init
0000000000000000 T int_svc_is_cpu_on
0000000000000000 T int_svc_notify_cpu_state
0000000000000000 T int_svc_register_isr
0000000000000000 T int_svc_unregister_isr
                 U qtisec_assert
                 U qtiseclib_cb_memcpy
                 U qtiseclib_cb_memset
                 U qtiseclib_cb_plat_my_core_pos
                 U qtiseclib_cb_set_spi_routing
                 U qtiseclib_cb_spin_lock
                 U qtiseclib_cb_spin_unlock
0000000000000000 T qtiseclib_invoke_isr
                 U timer_qtimer_read_time_raw
*/
#include "int_svc.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall int_svc_core_pos_to_mpidr(unsigned int a1)
{
  if ( a1 > 7 )
    qtisec_assert("noship_src/services/int_svc/int_svc.c", 0xCBu, "core_pos < QTISECLIB_PLAT_CORE_COUNT");
  if ( g_mpidr_map[a1] == 57005LL )
    qtisec_assert("noship_src/services/int_svc/int_svc.c", 0xCCu, "INVALID_MPIDR != g_mpidr_map[core_pos]");
  return g_mpidr_map[a1];
}



__int64 int_svc_init()
{
  __int64 i; // x0

  for ( i = 0LL; i != 8; ++i )
    g_mpidr_map[i] = 57005LL;
  return int_svc_notify_cpu_state(1LL);
}



bool __fastcall int_svc_is_cpu_on(char a1)
{
  int v2; // w19

  qtiseclib_cb_spin_lock(&g_int_svc_cpu_state_lock);
  v2 = (char)((1 << a1) & g_int_cpu_on_state);
  qtiseclib_cb_spin_unlock(&g_int_svc_cpu_state_lock);
  return v2 != 0;
}



__int64 __fastcall int_svc_notify_cpu_state(__int64 a1)
{
  int v1; // w23
  unsigned int v2; // w0
  unsigned int v3; // w24
  int v4; // w1
  unsigned int v5; // w19
  char v6; // w23
  int v7; // w0
  unsigned int v8; // w19
  int v9; // w19
  int v10; // w0
  int v11; // w1
  __int64 v12; // x0

  v1 = a1;
  v2 = qtiseclib_cb_plat_my_core_pos(a1);
  v3 = v2;
  if ( g_mpidr_map[v2] == 57005LL )
    g_mpidr_map[v2] = _ReadStatusReg(ARM64_SYSREG(3, 0, 0, 0, 5));
  qtiseclib_cb_spin_lock(&g_int_svc_cpu_state_lock);
  if ( v1 == 1 )
  {
    v4 = 1 << v3;
    if ( (((int)(unsigned __int8)g_int_cpu_on_state >> g_int_swdog_target) & 1LL) != 0 )
      v5 = 255;
    else
      v5 = v3;
    g_int_cpu_on_state |= v4;
    g_int_cpu_interruptible_state |= v4;
    if ( v5 == 255 )
      return qtiseclib_cb_spin_unlock(&g_int_svc_cpu_state_lock);
    if ( v5 > 7 )
      qtisec_assert("noship_src/services/int_svc/int_svc.c", 0x140u, "new_sec_wdog_target < QTISECLIB_PLAT_CORE_COUNT");
  }
  else if ( v1 )
  {
    if ( v3 != (unsigned __int8)g_int_swdog_target )
    {
      g_int_cpu_on_state &= ~(1 << v3);
      return qtiseclib_cb_spin_unlock(&g_int_svc_cpu_state_lock);
    }
    v9 = (unsigned __int8)g_int_cpu_on_state;
    v10 = (unsigned __int8)g_int_cpu_on_state - 1;
    v11 = (unsigned __int8)g_int_cpu_on_state & ~(1 << v3);
    g_int_cpu_on_state &= ~(1 << v3);
    if ( (v10 & v9) == 0 )
      return qtiseclib_cb_spin_unlock(&g_int_svc_cpu_state_lock);
    v5 = __clz(__rbit32(v11));
  }
  else
  {
    v6 = ~(1 << v3);
    v7 = (unsigned __int8)(v6 & g_int_cpu_interruptible_state);
    g_int_cpu_interruptible_state &= v6;
    if ( v3 != (unsigned __int8)g_int_swdog_target )
    {
      g_int_cpu_on_state &= v6;
      return qtiseclib_cb_spin_unlock(&g_int_svc_cpu_state_lock);
    }
    if ( ((unsigned __int8)(g_int_cpu_on_state - 1) & (unsigned __int8)g_int_cpu_on_state) != 0 )
    {
      v8 = (unsigned __int8)(v6 & g_int_cpu_on_state);
      g_int_cpu_on_state &= v6;
    }
    else
    {
      if ( !v7 )
        qtisec_assert("noship_src/services/int_svc/int_svc.c", 0x115u, "0 != g_int_cpu_interruptible_state");
      g_int_cpu_on_state &= v6;
      v8 = (unsigned __int8)g_int_cpu_interruptible_state;
    }
    v5 = __clz(__rbit32(v8));
  }
  if ( (((int)(unsigned __int8)g_int_cpu_interruptible_state >> v5) & 1) == 0 )
    qtisec_assert(
      "noship_src/services/int_svc/int_svc.c",
      0x141u,
      "g_int_cpu_interruptible_state & (1 << new_sec_wdog_target)");
  v12 = int_svc_core_pos_to_mpidr(v5);
  qtiseclib_cb_set_spi_routing(516LL, 0LL, v12);
  g_int_swdog_target = v5;
  return qtiseclib_cb_spin_unlock(&g_int_svc_cpu_state_lock);
}



  v0 = int_svc_register_isr(
         230,
         (__int64)"VMIDMT CTL Sec",
         0xFuLL,
         (__int64)vmidmt_error_handler,
         (__int64)&vmidmt_err_clt_sec_ctx);
  v1 = v0 | int_svc_register_isr(
              231,
              (__int64)"VMIDMT CTL NSec",
              0x10uLL,
              (__int64)vmidmt_error_handler,
              (__int64)&vmidmt_err_clt_nonsec_ctx);
  v2 = int_svc_register_isr(
         232,
         (__int64)"VMIDMT CFG Sec",
         0xFuLL,
         (__int64)vmidmt_error_handler,
         (__int64)&vmidmt_err_cfg_sec_ctx);
  result = v2 | (unsigned int)int_svc_register_isr(
                                233,
                                (__int64)"VMIDMT CFG NSec",
                                0x10uLL,
                                (__int64)vmidmt_error_handler,
                                (__int64)&vmidmt_err_cfg_nonsec_ctx) | v1;
  MEMORY[0x1FC5040] = -1;
  MEMORY[0x1FC3040] = -1;
  MEMORY[0x1FC4050] = -1;
  MEMORY[0x1FC2050] = -1;
  return result;
}



__int64 __fastcall int_svc_unregister_isr(int a1)
{
  __int64 v2; // x1
  unsigned int v3; // w20

  qtiseclib_cb_spin_lock(&g_int_svc_fiq_lock);
  v2 = 0LL;
  while ( g_isrs[34 * v2] != a1 )
  {
    if ( ++v2 == 32 )
    {
      v3 = -1;
      goto LABEL_6;
    }
  }
  v3 = 0;
  qtiseclib_cb_memset(&g_isrs[34 * (unsigned int)v2], 0LL, 136LL);
LABEL_6:
  qtiseclib_cb_spin_unlock(&g_int_svc_fiq_lock);
  return v3;
}



__int64 __fastcall qtiseclib_invoke_isr(__int64 a1, __int64 a2)
{
  unsigned int v3; // w23
  char v4; // w20
  __int64 v5; // x1
  __int64 v6; // x21
  __int64 v7; // x19
  __int64 (__fastcall *v8)(_QWORD, __int64, __int64); // x20
  __int64 result; // x0
  __int64 v10; // x20
  _DWORD *v11; // x0
  _DWORD *v12; // x19

  v3 = a1;
  v4 = qtiseclib_cb_plat_my_core_pos(a1);
  qtiseclib_cb_spin_lock(&g_int_svc_fiq_lock);
  v5 = 0LL;
  while ( 1 )
  {
    v6 = (unsigned int)v5;
    if ( g_isrs[34 * v5] == v3 )
      break;
    if ( ++v5 == 32 )
    {
      v6 = 32LL;
      v7 = 0LL;
      v8 = 0LL;
      goto LABEL_5;
    }
  }
  v10 = v4 & 7;
  v11 = &g_isrs[34 * (unsigned int)v5 + 8 + v10];
  ++v11[2];
  v12 = &g_isrs[34 * (unsigned int)v5];
  *(_QWORD *)&g_isrs[34 * (unsigned int)v5 + 18 + 2 * v10] = timer_qtimer_read_time_raw();
  v8 = (__int64 (__fastcall *)(_QWORD, __int64, __int64))*((_QWORD *)v12 + 3);
  v7 = *((_QWORD *)v12 + 4);
LABEL_5:
  result = qtiseclib_cb_spin_unlock(&g_int_svc_fiq_lock);
  if ( v8 )
  {
    result = v8(v3, a2, v7);
    *(_QWORD *)&g_isrs[34 * v6 + 8] = result;
  }
  return result;
}



