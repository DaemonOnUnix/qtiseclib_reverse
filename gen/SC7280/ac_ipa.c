/*0000000000000000 b $d
0000000000000000 t $x
                 U dbg_err_fatal
0000000000000000 T mem_assign
                 U msm_mpu_ranges
                 U msm_mpu_ranges_count
0000000000000000 b perm_lock.1439
                 U qtiseclib_cb_log
                 U qtiseclib_cb_spin_lock
                 U qtiseclib_cb_spin_unlock
                 U XpuLockDownAssetDynamically
*/
#include "ac_ipa.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall mem_assign(__int64 *a1, unsigned int a2, __int64 a3, unsigned int a4, int *a5, unsigned int a6)
{
  __int64 v12; // x3
  __int64 v13; // x5
  int v14; // w19
  int v15; // w21
  int v16; // w0
  int v18; // w6
  unsigned int i; // w4
  __int64 v21; // x8
  int *v22; // x4
  unsigned int v23; // w25
  unsigned int v24; // w24
  int *v25; // x22
  int v26; // w0
  __int64 v28; // x5
  int v29; // w6
  int v30; // w9
  int v31; // w0
  __int64 *v32; // x28
  __int64 j; // x23
  int k; // w0
  __int64 v35; // x20
  __int64 v36; // x27
  __int64 v37; // x26
  int v38; // w0
  __int64 v39; // x22
  char *v40; // x20
  __int64 v41; // x9
  __int64 v42; // x3
  __int64 v43; // x5
  int v44; // w2
  __int64 v45; // x6
  unsigned __int64 v46; // x11
  int v47; // w8
  __int64 m; // x1
  int v49; // w4
  __int64 v50; // x0
  __int64 v51; // x13
  __int64 v52; // x0
  int v53; // w3
  __int64 v54; // x2
  bool v55; // zf
  __int64 v57; // x4
  int v58; // w3
  unsigned int v59; // w19
  __int64 result; // x0
  __int64 v61; // x3
  __int64 v62; // x4
  _QWORD *v63; // [xsp+68h] [xbp+68h]
  __int64 v64; // [xsp+78h] [xbp+78h]
  __int64 v65; // [xsp+90h] [xbp+90h]
  int v66; // [xsp+98h] [xbp+98h]
  unsigned int v67; // [xsp+9Ch] [xbp+9Ch]

  qtiseclib_cb_spin_lock(&perm_lock_1439);
  v12 = a4;
  v13 = 0LL;
  v14 = 0;
  v15 = 0;
  while ( v13 != v12 )
  {
    v16 = *(_DWORD *)(a3 + 4 * v13);
    if ( v16 == 15 || v16 == 43 )
    {
      v18 = 0;
      for ( i = 0; i < a6 && i <= 0x2B; ++i )
      {
        v21 = 6LL * i;
        if ( v16 == a5[v21] )
          v18 = 1;
      }
      if ( !v18 )
      {
        if ( v16 == 15 )
        {
          v14 = 1;
          v15 = 30;
        }
        else
        {
          if ( v16 != 43 )
          {
LABEL_77:
            v59 = 32;
            goto LABEL_78;
          }
          v14 = 1;
          v15 = 35;
        }
      }
    }
    ++v13;
  }
  v22 = a5;
  v23 = 0;
  v24 = 0;
  v25 = &a5[6 * a6];
  while ( v22 != v25 )
  {
    v26 = *v22;
    if ( *v22 == 15 || v26 == 43 )
    {
      v28 = 0LL;
      v29 = 0;
      while ( v12 != v28 )
      {
        v30 = *(_DWORD *)(a3 + 4 * v28++);
        if ( v26 == v30 )
          v29 = 1;
      }
      if ( !v29 )
      {
        if ( v26 == 15 )
        {
          v15 = 30;
        }
        else
        {
          if ( v26 != 43 )
            goto LABEL_77;
          v15 = 35;
        }
        v31 = v22[1];
        v14 = 257;
        if ( (v31 & 2) != 0 )
          v23 = 2;
        if ( (v31 & 4) != 0 )
          v24 = 2;
      }
    }
    v22 += 6;
  }
  v32 = a1;
  v65 = a2;
  for ( j = 0LL; ; ++j )
  {
    v67 = j;
    if ( j == v65 )
      break;
    for ( k = 0; k != 2; ++k )
    {
      v35 = 16LL * k;
      if ( v15 == *(_DWORD *)((char *)&msm_mpu_ranges + v35) )
      {
        v36 = *v32;
        v37 = 0LL;
        v38 = 0;
        v39 = *v32 + v32[1];
        v40 = (char *)&msm_mpu_ranges + v35;
        while ( (unsigned __int8)v40[4] > (int)v37 )
        {
          v41 = *((_QWORD *)v40 + 1);
          v42 = 0LL;
          v43 = 48 * v37;
          v44 = -1;
          v45 = v41 + 48 * v37;
          v46 = *(_QWORD *)(v45 + 24);
          v47 = v46 - *((unsigned __int16 *)v40 + 3);
          for ( m = 16 * (v47 + 1LL); ; m += 16LL )
          {
            v49 = v47 + v42;
            if ( v47 + v42 >= v46 )
            {
              v49 = v44;
              goto LABEL_68;
            }
            v50 = *(_QWORD *)(v45 + 32) + 24 * (v47 + v42);
            v51 = *(_QWORD *)(v50 + 8);
            if ( v36 == v51 && v39 == *(_QWORD *)(v50 + 16) )
              break;
            if ( *(_DWORD *)(*(_QWORD *)(v45 + 16) + m + 4) )
              v55 = 0;
            else
              v55 = v51 == 0xFFFFFFFFLL;
            if ( v55 && *(_QWORD *)(v50 + 16) == 0xFFFFFFFFLL && v44 == -1 )
              v44 = v47 + v42;
            ++v42;
          }
          if ( v14 == 1 )
          {
            v63 = (_QWORD *)(v41 + 48 * v37);
            v64 = *((_QWORD *)v40 + 1);
            v66 = v47 + v42;
            qtiseclib_cb_log(40LL, "freeing RG for xpu 0x%x z:%d", *v63, (unsigned int)v49);
            v52 = 0xFFFFFFFFLL;
            v53 = 0;
            v54 = 0xFFFFFFFFLL;
            v49 = v66;
            v45 = (__int64)v63;
            v43 = 48 * v37;
            v41 = v64;
            goto LABEL_69;
          }
LABEL_68:
          v52 = v39;
          v54 = v36;
          v53 = v14;
LABEL_69:
          if ( v49 == -1 )
          {
            qtiseclib_cb_log(40LL, "AC Fatal Error no free RG xpu addr : 0x%x ", *(_QWORD *)(v41 + v43));
            v38 = 1;
          }
          else
          {
            *(_DWORD *)(*(_QWORD *)(v45 + 16) + 16LL * v49 + 20) = v53;
            v57 = *(_QWORD *)(v45 + 32) + 24LL * v49;
            v58 = *(_DWORD *)v57;
            *(_QWORD *)(v57 + 8) = v54;
            *(_QWORD *)(v57 + 16) = v52;
            XpuLockDownAssetDynamically(v45, 1u, *(_DWORD *)(v45 + 40), v58, v24, v23);
            v38 = 0;
          }
          ++v37;
        }
        if ( v38 )
        {
          qtiseclib_cb_log(10LL, "AC Fatal Error  %x", 96LL);
          dbg_err_fatal(4u);
        }
        break;
      }
    }
    v61 = *v32;
    v62 = *v32 + v32[1];
    v32 += 2;
    qtiseclib_cb_log(10LL, "mpu_master_mpus_range: %d %x %x %x %x", v67, v61, v62, v24, v23);
  }
  v59 = 0;
LABEL_78:
  qtiseclib_cb_spin_unlock(&perm_lock_1439);
  result = 0LL;
  if ( v59 )
  {
    qtiseclib_cb_log(10LL, "mem_assign failed %x", v59);
    return -1LL;
  }
  return result;
}



