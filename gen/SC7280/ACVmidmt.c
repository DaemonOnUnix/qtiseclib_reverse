/*0000000000000000 r $d
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
0000000000000000 T vmidmt_config
                 U vmidmt_ConfigErrRep
0000000000000000 T vmidmt_config_options
0000000000000000 T vmidmt_config_options_per_master
                 U vmidmt_ConfigSSDT
                 U vmidmt_ConfigVmidCtxt
                 U vmidmt_ConfigVmidCtxtWithSIDList
0000000000000000 T vmidmt_config_vmids
                 U vmidmt_EnableClientP
0000000000000000 d vmidmt_err_cfg_nonsec_ctx
0000000000000000 d vmidmt_err_cfg_sec_ctx
0000000000000000 d vmidmt_err_clt_nonsec_ctx
0000000000000000 b vmidmt_err_clt_sec_ctx
0000000000000000 t vmidmt_error_handler
                 U vmidmt_err_pos_to_hal_map
                 U vmidmt_GetError
0000000000000000 T vmidmt_getInfo_index
                 U vmidmt_Init
                 U vmidmt_IsError
0000000000000000 T vmidmt_map_multisid_vmid_internal
0000000000000000 T vmidmt_map_vmid_internal
0000000000000000 T vmidmt_register_interrupts
*/
#include "ACVmidmt.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 vmidmt_config()
{
  __int64 result; // x0

  if ( (unsigned int)vmidmt_config_options()
    || (unsigned int)vmidmt_config_vmids()
    || (result = vmidmt_register_interrupts(), (_DWORD)result) )
  {
    qtiseclib_cb_log(10LL, "VMIDMT ERROR :(%x)", 1LL);
    while ( 1 )
      ;
  }
  return result;
}



__int64 vmidmt_config_options()
{
  unsigned int i; // w19
  __int64 result; // x0

  for ( i = 0; i < 3; ++i )
  {
    if ( g_vmidmt_cfg[24 * i + 17] )
    {
      result = vmidmt_config_options_per_master(i);
      if ( (_DWORD)result )
        return result;
    }
  }
  return 0LL;
}



__int64 __fastcall vmidmt_config_options_per_master(int a1)
{
  __int64 v1; // x22
  int v2; // w23
  __int64 Info_index; // x19
  __int64 *v4; // x19
  int v5; // w0
  unsigned int v6; // w1
  unsigned __int8 *v7; // x20
  __int64 v8; // x1
  int v9; // w20
  __int64 v11[2]; // [xsp+40h] [xbp+40h] BYREF
  int v12[8]; // [xsp+50h] [xbp+50h] BYREF
  __int64 v13[3]; // [xsp+70h] [xbp+70h] BYREF
  char v14; // [xsp+88h] [xbp+88h]
  char v15; // [xsp+89h] [xbp+89h]

  v1 = a1;
  v2 = g_vmidmt_cfg[24 * a1];
  Info_index = (unsigned __int8)vmidmt_getInfo_index(g_vmidmt_cfg[24 * a1]);
  v13[2] = (__int64)&acc_ctl;
  v14 = 0;
  v15 = 0;
  v11[1] = 65280LL;
  v13[0] = 0LL;
  v13[1] = 0LL;
  qtiseclib_cb_memset(v12, 0LL, 28LL);
  v11[0] = (__int64)v13;
  if ( v2 == 4 )
  {
    v15 = 0;
    v13[0] = (__int64)v12;
    v12[0] = 2;
  }
  v4 = (__int64 *)&g_vmidmt_info_cfg[24 * Info_index + 8];
  v5 = vmidmt_Init(v4, (__int64)v11, 0LL);
  v6 = -1;
  if ( !v5 )
  {
    v7 = &g_vmidmt_cfg[24 * v1];
    v8 = *((_QWORD *)v7 + 1);
    if ( v8 )
      vmidmt_ConfigSSDT((__int64)v4, v8, v7[16]);
    v9 = g_vmidmt_cfg[24 * v1 + 1];
    vmidmt_ConfigErrRep((__int64)v4, 0, v9);
    vmidmt_ConfigErrRep((__int64)v4, 1, v9);
    return 0;
  }
  return v6;
}



__int64 vmidmt_config_vmids()
{
  char *v0; // x21
  unsigned int i; // w19
  char *v2; // x1
  unsigned __int8 v3; // w0
  unsigned int v4; // w0
  unsigned int v5; // w20

  v0 = (char *)&unk_15EBC;
  for ( i = 0; i < 0x55; ++i )
  {
    v2 = (char *)&g_vmid_map + 28 * (int)i;
    if ( v2[26] )
    {
      v3 = *((_BYTE *)&g_vmid_map + 28 * (int)i);
      v4 = v2[24] == 1 ? vmidmt_map_vmid_internal(v3) : vmidmt_map_multisid_vmid_internal(v3);
      v5 = v4;
      if ( v4 )
      {
        qtiseclib_cb_log(10LL, "VMIDMT Config ERROR for g_vmid_map[%d]", i);
        return v5;
      }
    }
    v0 += 28;
  }
  return 0;
}



__int64 __fastcall vmidmt_getInfo_index(unsigned __int8 a1)
{
  int v1; // w4
  __int64 v2; // x1
  __int64 result; // x0

  v1 = a1;
  v2 = 0LL;
  result = 0xFFFFFFFFLL;
  while ( (int)v2 < (unsigned __int8)g_vmidmt_info_cfg_count )
  {
    if ( g_vmidmt_info_cfg[24 * v2] == v1 )
      result = (unsigned int)v2;
    else
      result = (unsigned int)result;
    ++v2;
  }
  return result;
}



__int64 __fastcall vmidmt_map_multisid_vmid_internal(unsigned __int8 a1)
{
  int v1; // w7
  unsigned int v2; // w8
  __int64 v3; // x9
  unsigned int v4; // w10
  char v5; // w11
  int v6; // w12
  __int64 Info_index; // x19
  int **v8; // x19
  int v9; // w0
  unsigned int v10; // w1
  __int64 v12[2]; // [xsp+28h] [xbp+28h] BYREF
  __int64 v13; // [xsp+38h] [xbp+38h]
  __int64 v14[2]; // [xsp+40h] [xbp+40h] BYREF
  __int64 v15; // [xsp+50h] [xbp+50h]
  int v16; // [xsp+58h] [xbp+58h]

  v14[0] = 0LL;
  v14[1] = 0LL;
  v12[0] = 0LL;
  v12[1] = 0LL;
  v13 = 0LL;
  v15 = 0LL;
  v16 = 0;
  Info_index = (unsigned __int8)vmidmt_getInfo_index(a1);
  if ( v1 != 255 )
  {
    BYTE4(v15) = v1;
    LODWORD(v15) = 1;
  }
  if ( v6 )
    LODWORD(v14[0]) = 2;
  v12[0] = (__int64)v14;
  v8 = (int **)&g_vmidmt_info_cfg[24 * Info_index + 8];
  LOBYTE(v13) = v5;
  v9 = vmidmt_ConfigVmidCtxtWithSIDList((__int64)v8, v2, v3, v4, v12);
  v10 = -1;
  if ( !v9 )
  {
    vmidmt_EnableClientP(v8, 1);
    vmidmt_EnableClientP(v8, 0);
    return 0;
  }
  return v10;
}



__int64 __fastcall vmidmt_map_vmid_internal(unsigned __int8 a1)
{
  int v1; // w7
  unsigned int v2; // w8
  char v3; // w9
  int v4; // w10
  __int64 Info_index; // x19
  int **v6; // x19
  int v7; // w0
  unsigned int v8; // w1
  __int64 v10[2]; // [xsp+28h] [xbp+28h] BYREF
  __int64 v11; // [xsp+38h] [xbp+38h]
  __int64 v12[2]; // [xsp+40h] [xbp+40h] BYREF
  __int64 v13; // [xsp+50h] [xbp+50h]
  int v14; // [xsp+58h] [xbp+58h]

  v12[0] = 0LL;
  v12[1] = 0LL;
  v10[0] = 0LL;
  v10[1] = 0LL;
  v11 = 0LL;
  v13 = 0LL;
  v14 = 0;
  Info_index = (unsigned __int8)vmidmt_getInfo_index(a1);
  if ( v1 != 255 )
  {
    BYTE4(v13) = v1;
    LODWORD(v13) = 1;
  }
  if ( v4 )
    LODWORD(v12[0]) = 2;
  v10[0] = (__int64)v12;
  LOBYTE(v11) = v3;
  v6 = (int **)&g_vmidmt_info_cfg[24 * Info_index + 8];
  v7 = vmidmt_ConfigVmidCtxt((__int64)v6, v2, v10);
  v8 = -1;
  if ( !v7 )
  {
    vmidmt_EnableClientP(v6, 1);
    vmidmt_EnableClientP(v6, 0);
    return 0;
  }
  return v8;
}



__int64 vmidmt_register_interrupts()
{
  int v0; // w20
  int v1; // w20
  int v2; // w21
  __int64 result; // x0

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



