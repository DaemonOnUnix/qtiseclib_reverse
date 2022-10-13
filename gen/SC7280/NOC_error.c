/*0000000000000000 b $d
0000000000000000 b $d
0000000000000000 b $d
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
                 U dbg_err_fatal
                 U dbg_is_sdi_enable
0000000000000000 T icb_error_init
                 U int_svc_register_isr
0000000000000000 T NOC_Error_Handle_Interrupt
0000000000000000 T NOC_Error_Init
                 U NOC_Error_Platform_Get_Propdata
                 U NOC_Error_Platform_Get_Propdata_OEM
0000000000000000 b NOCERR_propdata
0000000000000000 b NOCInfo
0000000000000000 b NOCInfoOEM
                 U qtisec_assert
                 U qtiseclib_cb_console_flush
                 U qtiseclib_cb_log
*/
#include "NOC_error.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

__int64 __fastcall NOC_Error_Handle_Interrupt(__int64 a1, __int64 a2, __int64 a3)
{
  int v4; // w7
  __int64 v5; // x20
  unsigned int v6; // w21
  const char *v7; // x0
  unsigned int i; // w22
  unsigned int v9; // w22
  int v10; // w6
  const char *v11; // x0
  unsigned int j; // w0
  unsigned int k; // w1
  __int64 v14; // x27
  const char **v15; // x19
  const char *v16; // x1
  const char *v17; // x2
  __int64 v18; // x3
  const char *v19; // x2
  __int64 v20; // x3
  const char *v21; // x2
  __int64 v22; // x3
  const char *v23; // x2
  __int64 v24; // x3
  const char *v25; // x2
  __int64 v26; // x3
  const char *v27; // x2
  __int64 v28; // x3
  const char *v29; // x2
  __int64 v30; // x3
  const char *v31; // x2
  __int64 v32; // x3
  int v33; // w1
  int v34; // w4
  const char *v35; // x2
  int v36; // w0
  __int64 v37; // x4
  const char *v38; // x2
  int v39; // w0
  __int64 v40; // x4
  const char *v41; // x2
  int v42; // w0
  __int64 v43; // x4
  const char *v44; // x2
  __int64 v45; // x24
  const char *v46; // x1
  __int64 v47; // x2
  int v48; // w0
  int v49; // w0
  int v50; // w0
  int v51; // w1
  unsigned __int16 *v52; // x0
  int v53; // w5
  __int64 v54; // x6
  int v55; // w3
  __int64 v56; // x5
  int v57; // w3
  __int64 v58; // x5
  int v59; // w3
  __int64 v60; // x2
  __int64 v61; // x0
  int v63; // [xsp+68h] [xbp+68h]
  int v64; // [xsp+6Ch] [xbp+6Ch]

  if ( !NOCInfo || !NOCInfoOEM )
  {
    qtiseclib_cb_log(10LL, "Invalid NOC info data structures!");
    return a3;
  }
  v4 = 0;
  v5 = 0LL;
  v6 = 0;
LABEL_17:
  if ( v6 < *(_DWORD *)(NOCERR_propdata + 12) )
  {
    v14 = NOCInfo;
    v15 = (const char **)(NOCInfo + 176LL * v6);
    if ( v15[3] != (const char *)(unsigned int)a3 )
      goto LABEL_16;
    v5 = NOCInfoOEM + 48LL * v6;
    if ( !v5 )
    {
      qtiseclib_cb_log(10LL, "Invalid Interrupt Vector!");
      return a3;
    }
    v7 = v15[2];
    if ( v7 )
    {
      v16 = v15[1];
      if ( *(_DWORD *)&v7[*((unsigned __int16 *)v16 + 3)] )
      {
        v17 = *(const char **)(NOCInfo + 176LL * v6);
        v18 = *(unsigned int *)&v7[*((unsigned __int16 *)v16 + 5)];
        *((_DWORD *)v15 + 18) = v18;
        qtiseclib_cb_log(10LL, "%s ERROR: ERRLOG0_LOW = 0x%08x", v17, v18);
        v19 = *(const char **)(v14 + 176LL * v6);
        v20 = *(unsigned int *)&v15[2][*((unsigned __int16 *)v15[1] + 6)];
        *((_DWORD *)v15 + 19) = v20;
        qtiseclib_cb_log(10LL, "%s ERROR: ERRLOG0_HIGH = 0x%08x", v19, v20);
        v21 = *(const char **)(v14 + 176LL * v6);
        v22 = *(unsigned int *)&v15[2][*((unsigned __int16 *)v15[1] + 7)];
        *((_DWORD *)v15 + 20) = v22;
        qtiseclib_cb_log(10LL, "%s ERROR: ERRLOG1_LOW = 0x%08x", v21, v22);
        v23 = *(const char **)(v14 + 176LL * v6);
        v24 = *(unsigned int *)&v15[2][*((unsigned __int16 *)v15[1] + 8)];
        *((_DWORD *)v15 + 21) = v24;
        qtiseclib_cb_log(10LL, "%s ERROR: ERRLOG1_HIGH = 0x%08x", v23, v24);
        v25 = *(const char **)(v14 + 176LL * v6);
        v26 = *(unsigned int *)&v15[2][*((unsigned __int16 *)v15[1] + 9)];
        *((_DWORD *)v15 + 22) = v26;
        qtiseclib_cb_log(10LL, "%s ERROR: ERRLOG2_LOW = 0x%08x", v25, v26);
        v27 = *(const char **)(v14 + 176LL * v6);
        v28 = *(unsigned int *)&v15[2][*((unsigned __int16 *)v15[1] + 10)];
        *((_DWORD *)v15 + 23) = v28;
        qtiseclib_cb_log(10LL, "%s ERROR: ERRLOG2_HIGH = 0x%08x", v27, v28);
        v29 = *(const char **)(v14 + 176LL * v6);
        v30 = *(unsigned int *)&v15[2][*((unsigned __int16 *)v15[1] + 11)];
        *((_DWORD *)v15 + 24) = v30;
        qtiseclib_cb_log(10LL, "%s ERROR: ERRLOG3_LOW = 0x%08x", v29, v30);
        v31 = *(const char **)(v14 + 176LL * v6);
        v32 = *(unsigned int *)&v15[2][*((unsigned __int16 *)v15[1] + 12)];
        *((_DWORD *)v15 + 25) = v32;
        qtiseclib_cb_log(10LL, "%s ERROR: ERRLOG3_HIGH = 0x%08x", v31, v32);
        v4 = 1;
      }
    }
    for ( i = 0; i < *((_DWORD *)v15 + 8); ++i )
    {
      v33 = *(unsigned __int16 *)(*(_QWORD *)&v15[5][8 * i] + 8LL);
      if ( v33 != 0xFFFF )
      {
        v34 = *(_DWORD *)(*(_QWORD *)&v15[6][8 * i] + (unsigned __int16)v33);
        if ( v34 )
        {
          v35 = *v15;
          *(_DWORD *)&v15[17][16 * i] = v34;
          qtiseclib_cb_log(10LL, "%s ERROR: SBM%d FAULTINSTATUS0_LOW = 0x%08x", v35, i);
          v4 = 1;
        }
      }
      v36 = *(unsigned __int16 *)(*(_QWORD *)&v15[5][8 * i] + 10LL);
      if ( v36 != 0xFFFF )
      {
        v37 = *(unsigned int *)(*(_QWORD *)&v15[6][8 * i] + (unsigned __int16)v36);
        if ( (_DWORD)v37 )
        {
          v38 = *v15;
          *(_DWORD *)&v15[17][16 * i + 4] = v37;
          qtiseclib_cb_log(10LL, "%s ERROR: SBM%d FAULTINSTATUS0_HIGH = 0x%08x", v38, i, v37);
          v4 = 1;
        }
      }
      v39 = *(unsigned __int16 *)(*(_QWORD *)&v15[5][8 * i] + 16LL);
      if ( v39 != 0xFFFF )
      {
        v40 = *(unsigned int *)(*(_QWORD *)&v15[6][8 * i] + (unsigned __int16)v39);
        if ( (_DWORD)v40 )
        {
          v41 = *v15;
          *(_DWORD *)&v15[17][16 * i + 8] = v40;
          qtiseclib_cb_log(10LL, "%s ERROR: SBM%d FAULTINSTATUS1_LOW = 0x%08x", v41, i, v40);
          v4 = 1;
        }
      }
      v42 = *(unsigned __int16 *)(*(_QWORD *)&v15[5][8 * i] + 18LL);
      if ( v42 != 0xFFFF )
      {
        v43 = *(unsigned int *)(*(_QWORD *)&v15[6][8 * i] + (unsigned __int16)v42);
        if ( (_DWORD)v43 )
        {
          v44 = *v15;
          *(_DWORD *)&v15[17][16 * i + 12] = v43;
          qtiseclib_cb_log(10LL, "%s ERROR: SBM%d FAULTINSTATUS1_HIGH = 0x%08x", v44, i, v43);
          v4 = 1;
        }
      }
    }
    v9 = 0;
    v10 = 0xFFFF;
    while ( 1 )
    {
      if ( v9 >= *((_DWORD *)v15 + 38) )
      {
        v11 = v15[2];
        if ( v11 )
          *(_DWORD *)&v11[*((unsigned __int16 *)v15[1] + 4)] = 1;
        for ( j = 0; j < *((_DWORD *)v15 + 38); ++j )
        {
          v51 = *(unsigned __int16 *)(*(_QWORD *)&v15[20][8 * j] + 8LL);
          if ( v51 != 0xFFFF )
            *(_DWORD *)(*(_QWORD *)&v15[21][8 * j] + (unsigned __int16)v51) = 1;
        }
        for ( k = 0; k < *((_DWORD *)v15 + 8); ++k )
        {
          v52 = *(unsigned __int16 **)&v15[5][8 * k];
          v53 = v52[4];
          if ( v53 != 0xFFFF )
          {
            v54 = *(_QWORD *)&v15[6][8 * k];
            *(_DWORD *)(v54 + v52[2]) &= *(_DWORD *)(*(_QWORD *)(v5 + 24) + 16LL * k) | ~*(_DWORD *)(v54 + (unsigned __int16)v53);
          }
          v55 = v52[5];
          if ( v55 != 0xFFFF )
          {
            v56 = *(_QWORD *)&v15[6][8 * k];
            *(_DWORD *)(v56 + v52[3]) &= *(_DWORD *)(*(_QWORD *)(v5 + 24) + 16LL * k + 4) | ~*(_DWORD *)(v56 + (unsigned __int16)v55);
          }
          v57 = v52[8];
          if ( v57 != 0xFFFF )
          {
            v58 = *(_QWORD *)&v15[6][8 * k];
            *(_DWORD *)(v58 + v52[6]) &= *(_DWORD *)(*(_QWORD *)(v5 + 24) + 16LL * k + 8) | ~*(_DWORD *)(v58 + (unsigned __int16)v57);
          }
          v59 = v52[9];
          if ( v59 != 0xFFFF )
          {
            v60 = *(_QWORD *)&v15[6][8 * k];
            *(_DWORD *)(v60 + v52[7]) &= *(_DWORD *)(*(_QWORD *)(v5 + 24) + 16LL * k + 12) | ~*(_DWORD *)(v60 + (unsigned __int16)v59);
          }
        }
LABEL_16:
        ++v6;
        goto LABEL_17;
      }
      v45 = 8LL * v9;
      v46 = v15[18];
      v47 = *(_QWORD *)&v15[20][v45];
      v48 = *(unsigned __int16 *)(v47 + 4);
      if ( v48 != v10 )
      {
        v49 = *(_DWORD *)(*(_QWORD *)&v15[21][8 * v9] + (unsigned __int16)v48);
        *(_DWORD *)&v46[8 * v9] = v49;
        if ( (v49 & 2) == 0 )
          goto LABEL_43;
        v4 = 1;
      }
      v50 = *(unsigned __int16 *)(v47 + 6);
      if ( v50 != v10 )
        *(_DWORD *)&v46[8 * v9 + 4] = *(_DWORD *)(*(_QWORD *)&v15[21][8 * v9] + (unsigned __int16)v50);
      v63 = v10;
      v64 = v4;
      qtiseclib_cb_log(10LL, "%s ERROR: NOC_POS%d ERRLOG_LOW = 0x%08x", *v15, v9, *(unsigned int *)&v46[8 * v9]);
      qtiseclib_cb_log(10LL, "%s ERROR: NOC_POS%d ERRLOG_HIGH = 0x%08x", *v15, v9, *(unsigned int *)&v15[18][v45 + 4]);
      v10 = v63;
      v4 = v64;
LABEL_43:
      ++v9;
    }
  }
  if ( v4 )
  {
    if ( (unsigned __int8)dbg_is_sdi_enable() )
    {
      if ( *(_BYTE *)(v5 + 9) )
      {
        qtiseclib_cb_log(10LL, "NOC error fatal");
        dbg_err_fatal(3u);
      }
    }
    else if ( *(_BYTE *)(v5 + 9) )
    {
      v61 = qtiseclib_cb_log(10LL, "NOC error fatal");
      qtiseclib_cb_console_flush(v61);
    }
  }
  return a3;
}



__int64 NOC_Error_Init()
{
  __int64 result; // x0
  __int64 v1; // x2
  unsigned int i; // w1
  __int64 v3; // x3
  unsigned int j; // w19
  __int64 v5; // x26
  __int64 v6; // x1
  unsigned int v7; // w2
  __int64 v8; // x0
  __int64 v9; // x7
  int v10; // w3
  int v11; // w3
  unsigned int k; // w2
  __int64 v13; // x3

  result = (__int64)NOC_Error_Platform_Get_Propdata();
  NOCERR_propdata = result;
  if ( result )
  {
    result = (__int64)NOC_Error_Platform_Get_Propdata_OEM();
    if ( result )
    {
      v1 = NOCERR_propdata;
      NOCInfo = *(_QWORD *)(NOCERR_propdata + 16);
      if ( NOCInfo )
      {
        NOCInfoOEM = *(_QWORD *)(result + 16);
        if ( NOCInfoOEM )
        {
          for ( i = 0; i < *(_DWORD *)(v1 + 24); ++i )
          {
            v3 = i;
            **(_DWORD **)(*(_QWORD *)(v1 + 32) + 8 * v3) = *(_DWORD *)(*(_QWORD *)(result + 24) + 4 * v3);
          }
          for ( j = 0; ; ++j )
          {
            result = *(unsigned int *)(NOCERR_propdata + 12);
            if ( j >= (unsigned int)result )
              break;
            v5 = 176LL * j;
            if ( (unsigned int)int_svc_register_isr(
                                 *(_QWORD *)(NOCInfo + v5 + 24),
                                 (__int64)"NOCERR",
                                 7uLL,
                                 (__int64)NOC_Error_Handle_Interrupt,
                                 *(_QWORD *)(NOCInfo + v5 + 24)) )
              qtisec_assert(
                "noship_src/drivers/systemdrivers/icb/src/common/NOC_error.c",
                0x1A8u,
                "0 == int_svc_register_isr(NOCInfo[i].intr_vector, \"NOCERR\",sizeof(\"NOCERR\"), NOC_Error_Handle_Interr"
                "upt, ((void*)((uint64_t)(NOCInfo[i].intr_vector))))");
            v6 = NOCInfoOEM + 48LL * j;
            if ( *(_BYTE *)(v6 + 8) )
            {
              v7 = 0;
              v8 = NOCInfo + v5;
              while ( v7 < *(_DWORD *)(v8 + 32) )
              {
                v9 = *(_QWORD *)(*(_QWORD *)(v8 + 40) + 8LL * v7);
                v10 = *(unsigned __int16 *)(v9 + 4);
                if ( v10 != 0xFFFF )
                  *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v8 + 48) + 8LL * v7) + (unsigned __int16)v10) = *(_DWORD *)(*(_QWORD *)(v6 + 16) + 16LL * v7);
                v11 = *(unsigned __int16 *)(v9 + 6);
                if ( v11 != 0xFFFF )
                  *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v8 + 48) + 8LL * v7) + (unsigned __int16)v11) = *(_DWORD *)(*(_QWORD *)(v6 + 16) + 16LL * v7 + 4);
                ++v7;
              }
              for ( k = 0; k < *(_DWORD *)(v8 + 56); ++k )
              {
                v13 = k;
                **(_DWORD **)(*(_QWORD *)(v8 + 64) + 8 * v13) = *(_DWORD *)(*(_QWORD *)(v6 + 32) + 4 * v13);
              }
              *(_DWORD *)(*(_QWORD *)(v8 + 16) + *(unsigned __int16 *)(*(_QWORD *)(v8 + 8) + 4LL)) = 1;
            }
          }
        }
      }
    }
  }
  return result;
}



