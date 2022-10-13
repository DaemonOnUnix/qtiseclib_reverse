/*0000000000000000 d $d
0000000000000000 t $x
                 U ac_init
                 U Clock_Init
                 U Clock_TZInitDone
                 U cmd_db_tzbsp_init
                 U cpucp_clkdom_init
                 U cpucp_start
                 U dbg_init
                 U HAL_avs_Init
                 U HAL_avs_SecondaryRailInit
                 U icbcfg_init
                 U icb_error_init
                 U icbuarb_init
                 U int_svc_init
                 U lmh_config_init
                 U pdcOS_initialize
                 U pdc_seq_sys_init
                 U pdcTcs_initialize
0000000000000000 D platform_init_functions
                 U pwr_utils_lvl_init
                 U qtisec_build_string
0000000000000000 T qtiseclib_bl31_platform_setup
                 U qtiseclib_cb_log
                 U qtisec_oem_string
                 U qtisec_variant_string
                 U qtisec_version_string
                 U rpmh_client_init
                 U sec_core
                 U smmu_init
                 U timer_qtimer_security_config
                 U timer_sec_wdog_init
                 U Tlmm_Init
*/
#include "qtisec_bl31_platform_setup.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

