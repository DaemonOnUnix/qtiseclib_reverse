/*0000000000000000 r $d
0000000000000000 b $d
0000000000000000 d $d
0000000000000000 d $d
0000000000000000 d $d
0000000000000000 b $d
0000000000000000 b $d
0000000000000000 b $d
0000000000000000 r $d
0000000000000000 d $d
0000000000000000 d $d
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
                 U cpucp_clkdom_init
0000000000000000 t cpu_init
0000000000000000 t cpu_lpm_entry
0000000000000000 T cpu_lpm_exit
0000000000000000 D cpu_modes
0000000000000000 D cpu_node_ops
0000000000000000 t cpu_power_on
0000000000000000 t cpu_power_on_finish
0000000000000000 b g_apss_pdc
0000000000000000 b g_apss_rsc
0000000000000000 D g_psci_asic_nodes
0000000000000000 R g_psci_asic_nodes_count
0000000000000000 b g_psci_sys_cache_active
                 U HAL_avs_SecondaryRailInit
                 U int_svc_notify_cpu_state
0000000000000000 t l3_init
0000000000000000 t l3_lpm_entry
0000000000000000 t l3_lpm_exit
0000000000000000 D l3_modes
0000000000000000 D l3_node_ops
                 U lmh_c4_entry
                 U lmh_c4_exit
                 U pcu_config_low_power_mode
                 U pcu_node_init
                 U pdc_seq_handles
                 U pdc_seq_set_lpm
                 U pdc_seq_set_wakeup_time
                 U qtiseclib_cb_gic_pcpu_init
                 U qtiseclib_cb_ic_raise_sgi
                 U qtiseclib_cb_plat_core_pos_by_mpidr
                 U qtiseclib_cb_plat_my_core_pos
                 U qtiseclib_cb_udelay
0000000000000000 b rail_on.1712
                 U rsc_driver_init
                 U rsc_get_handles
                 U rsc_instance_init
                 U rsc_set_low_power_mode
                 U timer_qtimer_get_frames_list
*/
#include "psci_target.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall cpu_lpm_exit(__int64 a1, unsigned __int8 *a2, int a3)
{
  __int64 v5; // x0
  __int64 v6; // x0

  v5 = *a2;
  if ( (unsigned int)(v5 - 3) <= 1 )
  {
    if ( (_DWORD)v5 == 4 )
    {
      v6 = qtiseclib_cb_plat_my_core_pos(v5);
      lmh_c4_exit(v6);
    }
    int_svc_notify_cpu_state(1LL);
  }
  pcu_config_low_power_mode(*(__int64 **)(a1 + 64), 1);
  if ( !a3 )
    *(_DWORD *)(*(_QWORD *)(a1 + 32) + 68LL) &= 0xFFFC3FFu;
  return 0LL;
}



