/*0000000000000000 b $d
0000000000000000 d $d
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 T ac_init
                 U ACTzTargetConfig
                 U cpuss_dsb
                 U dbg_err_fatal
                 U dbg_is_sdi_enable
                 U int_svc_register_isr
                 U msm_mpu_ranges
                 U msm_mpu_ranges_count
                 U msm_xpu_cfg
                 U msm_xpu_cfg_count
0000000000000000 T msm_xpu_isr
                 U msm_xpu_print_log
                 U qtisec_assert
                 U qtiseclib_cb_console_flush
                 U vmidmt_config
0000000000000000 D xpu_err_non_sec_ctx
0000000000000000 B xpu_err_sec_ctx
                 U XpuLockDownAssets
                 U XpuMasterMPuInit
                 U xpu_non_sec_intr_en_reg
0000000000000000 T xpu_register_interrupts
                 U xpu_sec_intr_en_reg
0000000000000000 T xpu_static_config
*/
#include "ac_init.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 ac_init()
{
  __int64 result; // x0

  vmidmt_config();
  if ( (unsigned int)xpu_static_config() )
    qtisec_assert("noship_src/drivers/accesscontrol/ac_init.c", 0x57u, "0 == xpu_static_config()");
  result = xpu_register_interrupts();
  if ( (_DWORD)result )
    qtisec_assert("noship_src/drivers/accesscontrol/ac_init.c", 0x59u, "0 == xpu_register_interrupts()");
  return result;
}



int *__fastcall msm_xpu_isr(__int64 a1, __int64 a2, int *a3)
{
  __int64 is_sdi_enable; // x0

  msm_xpu_print_log(a3);
  is_sdi_enable = dbg_is_sdi_enable();
  if ( (_BYTE)is_sdi_enable )
    dbg_err_fatal(4u);
  qtiseclib_cb_console_flush(is_sdi_enable);
  return a3;
}



__int64 xpu_register_interrupts()
{
  int v0; // w20

  v0 = int_svc_register_isr(227, (__int64)"SPI XPU Sec", 0xCuLL, (__int64)msm_xpu_isr, (__int64)&xpu_err_sec_ctx);
  return v0 | (unsigned int)int_svc_register_isr(
                              228,
                              (__int64)"SPI XPU NonSec",
                              0xCuLL,
                              (__int64)msm_xpu_isr,
                              (__int64)&xpu_err_non_sec_ctx);
}



__int64 xpu_static_config()
{
  unsigned int v0; // w19

  if ( (unsigned int)XpuMasterMPuInit((__int64)&msm_mpu_ranges, 2u) )
    return (unsigned int)-1;
  v0 = XpuLockDownAssets((__int64)&msm_xpu_cfg, msm_xpu_cfg_count);
  if ( v0 )
  {
    return (unsigned int)-1;
  }
  else
  {
    ACTzTargetConfig();
    cpuss_dsb();
    MEMORY[0x1FC2040] = -1;
    MEMORY[0x1FC4040] = -1;
    MEMORY[0x1FC2044] = -1;
    MEMORY[0x1FC4044] = -1;
  }
  return v0;
}



