/*
0000000000000000 r $d
0000000000000000 d $d
0000000000000000 d $d
0000000000000000 d $d
0000000000000000 d $d
0000000000000000 b $d
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 D acc_ctl
                 U g_vmid_map
                 U g_vmid_map_count
                 U g_vmidmt_cfg
                 U g_vmidmt_cfg_count
                 U g_vmidmt_info_cfg
                 U g_vmidmt_info_cfg_count
                 U int_svc_register_isr
                 U qtiseclib_cb_log
                 U qtiseclib_cb_memset
                 U vmidmt_ClearError
0000000000000000 T vmidmt_config                        DONE
                 U vmidmt_ConfigErrRep
0000000000000000 T vmidmt_config_options                DONE
0000000000000000 T vmidmt_config_options_per_master     TODO
                 U vmidmt_ConfigSSDT
                 U vmidmt_ConfigVmidCtxt
                 U vmidmt_ConfigVmidCtxtWithSIDList
0000000000000000 T vmidmt_config_vmids                  TODO
                 U vmidmt_EnableClientP
0000000000000000 d vmidmt_err_cfg_nonsec_ctx
0000000000000000 d vmidmt_err_cfg_sec_ctx
0000000000000000 d vmidmt_err_clt_nonsec_ctx
0000000000000000 b vmidmt_err_clt_sec_ctx
0000000000000000 t vmidmt_error_handler
                 U vmidmt_err_pos_to_hal_map
                 U vmidmt_GetError
0000000000000000 T vmidmt_getInfo_index                 TODO
                 U vmidmt_Init
                 U vmidmt_IsError
0000000000000000 T vmidmt_map_multisid_vmid_internal    TODO
0000000000000000 T vmidmt_map_vmid_internal             TODO
0000000000000000 T vmidmt_register_interrupts           TODO
*/
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

int64_t vmidmt_config_options_per_master(int a1)
{
    int64_t v1 = a1; // x22
    int v2 = g_vmidmt_cfg[24 * a1]; // w23
    int64_t Info_index = (uint8_t)vmidmt_getInfo_index(g_vmidmt_cfg[24 * a1]);; // x19
    int64_t *v4; // x19
    int v5; // w0
    unsigned int v6 = -1; // w1
    uint8_t *v7; // x20
    int64_t v8; // x1
    int v9; // w20
    int v12[8];
    int64_t v13[3] = {0, 0, (int64_t)&acc_ctl};
    int64_t v11[2] = {(int64_t)v13, 65280};
    char v14 = 0;
    char v15 = 0;

    // should I leave it ?
    qtiseclib_cb_memset(v12, 0, 28);

    if ( v2 == 4 )
    {
        v13[0] = (int64_t)v12;
        v12[0] = 2;
    }

    v4 = (int64_t *)&g_vmidmt_info_cfg[24 * Info_index + 8];

    if (!vmidmt_Init(v4, (int64_t)v11, 0))
    {
        v7 = &g_vmidmt_cfg[24 * v1];
        v8 = *((uint64_t *)v7 + 1);
        if (v8)
            vmidmt_ConfigSSDT((int64_t)v4, v8, v7[16]);
        v9 = g_vmidmt_cfg[24 * v1 + 1];
        vmidmt_ConfigErrRep((int64_t)v4, 0, v9);
        vmidmt_ConfigErrRep((int64_t)v4, 1, v9);
        return 0;
    }

    return v6;
}

uint32_t vmidmt_config_options()
{
    uint32_t result;

    for (size_t i = 0; i < 3; ++i)
    {
        // TODO: unmagic value-ify
        if (g_vmidmt_cfg[24 * i + 17])
        {
            result = vmidmt_config_options_per_master(i);
            if (result)
                return result;
        }
    }
    return 0;
}

int32_t vmidmt_config()
{
    int32_t result;

    if(vmidmt_config_options())
        goto ERROR;

    if(vmidmt_config_vmids())
        goto ERROR;

    result = vmidmt_register_interrupts();
    if(result)
        goto ERROR;

    return result;
ERROR:
    qtiseclib_cb_log(10, "VMIDMT ERROR :(%x)", 1);
        while (1)
        ;
}