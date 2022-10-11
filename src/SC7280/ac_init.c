/*
0000000000000000 T ac_init                          DONE
                 U ACTzTargetConfig
                 U cpuss_dsb
                 U dbg_err_fatal
                 U dbg_is_sdi_enable
                 U int_svc_register_isr
                 U msm_mpu_ranges
                 U msm_mpu_ranges_count
                 U msm_xpu_cfg
                 U msm_xpu_cfg_count
0000000000000000 T msm_xpu_isr                      DONE
                 U msm_xpu_print_log
                 U qtisec_assert
                 U qtiseclib_cb_console_flush
                 U vmidmt_config
0000000000000000 D xpu_err_non_sec_ctx              TODO
0000000000000000 B xpu_err_sec_ctx                  TODO
                 U XpuLockDownAssets
                 U XpuMasterMPuInit
                 U xpu_non_sec_intr_en_reg
0000000000000000 T xpu_register_interrupts          DONE
                 U xpu_sec_intr_en_reg
0000000000000000 T xpu_static_config                DONE
*/

#include <stddef.h>
#include <stdint.h>

int64_t ac_init() {
    int64_t result;

    vmidmt_config();
    if ((uint32_t)xpu_static_config())
        qtisec_assert("noship_src/drivers/accesscontrol/ac_init.c", 0x57u,
                    "0 == xpu_static_config()");

    result = xpu_register_interrupts();

    if ((uint32_t)result)
        qtisec_assert("noship_src/drivers/accesscontrol/ac_init.c", 0x59u,
                    "0 == xpu_register_interrupts()");

    return result;
}

int *msm_xpu_isr(int64_t a1, int64_t a2, int *a3) {
    int64_t is_sdi_enable; // x0

    msm_xpu_print_log(a3);

    is_sdi_enable = dbg_is_sdi_enable();

    if ((char)is_sdi_enable)
        dbg_err_fatal(4u);

    qtiseclib_cb_console_flush(is_sdi_enable);

    return a3;
}

int64_t vmidmt_config() {
    int64_t result;

    if ((uint32_t)vmidmt_config_options() || (uint32_t)vmidmt_config_vmids() ||
        (result = vmidmt_register_interrupts(), (int32_t)result)) {
        qtiseclib_cb_log(10LL, "VMIDMT ERROR :(%x)", 1);
        while (1)
        ;
    }

    return result;
}

#define SPI_XPU_SEC 0xe3
#define SPI_XPU_NON_SEC 0xe4
int64_t xpu_register_interrupts() {
    uint32_t status =
        int_svc_register_isr(SPI_XPU_SEC, (int64_t) "SPI XPU Sec", 0xCuLL,
                            (int64_t)msm_xpu_isr, (int64_t)&xpu_err_sec_ctx);
    status |= (uint32_t)int_svc_register_isr(
        SPI_XPU_NON_SEC, (int64_t) "SPI XPU NonSec", 0xCuLL, (int64_t)msm_xpu_isr,
        (int64_t)&xpu_err_non_sec_ctx);
    return status;
}

uint32_t xpu_static_config() {
    uint32_t to_return;

    if ((uint32_t)XpuMasterMPuInit((int64_t)&msm_mpu_ranges, 2))
        return -1;

    if (XpuLockDownAssets((int64_t)&msm_xpu_cfg, msm_xpu_cfg_count))
        return -1;

    ACTzTargetConfig();
    cpuss_dsb();

    volatile int8_t *cmd_addr[4] = {0x1FC2040, 0x1FC4040, 0x1FC2044, 0x1FC4044};
    for (size_t i = 0; i < 4; i++) {
        volatile int8_t *addr = cmd_addr[i];
        *addr = -1;
    }

    return 0;
}
