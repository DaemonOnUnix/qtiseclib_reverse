/*0000000000000000 r $d
0000000000000000 b $d
0000000000000000 b $d
0000000000000000 t $x
0000000000000000 T icbcfg_init
0000000000000000 b icb_dev_config
0000000000000000 B icb_dev_config_valid
                 U qtiseclib_cb_udelay
                 U targetcfg_info
*/
#include "icbcfg.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 icbcfg_init()
{
  __int64 result; // x0
  unsigned int *v1; // x24
  __int64 v2; // x26
  unsigned int v3; // w21
  unsigned int v4; // w20
  unsigned int v5; // w22
  unsigned int i; // w23
  int *v7; // x19
  int v8; // w1
  int v9; // w2
  int v10; // w4
  int v11; // w1
  int v12; // w1
  int v13; // w1
  int v14; // w2
  int v15; // w3
  int v16; // w1
  int v17; // w2
  int v18; // w3
  int v19; // w2
  int v20; // w3
  int v21; // w4
  int v22; // w1
  int v23; // w2
  int v24; // w3
  int v25; // w5
  int v26; // w1
  int v27; // w2
  int v28; // w3
  int v29; // w5
  int v30; // w1
  int v31; // w27
  int v32; // w27
  int v33; // w27

  if ( !icb_dev_config_valid )
  {
    icb_dev_config = (__int64)*off_1A820;
    icb_dev_config_valid = 1;
  }
  result = (unsigned __int8)icb_dev_config_valid;
  if ( icb_dev_config_valid )
  {
    result = icb_dev_config;
    v1 = *(unsigned int **)(icb_dev_config + 48);
    if ( v1 )
    {
      v2 = *((_QWORD *)v1 + 1);
      v3 = 0;
      v4 = 0;
      v5 = 0;
      for ( i = 0; ; ++i )
      {
        result = *v1;
        if ( i >= (unsigned int)result )
          break;
        v7 = (int *)(v2 + 32LL * i);
        v8 = *v7;
        result = *((_QWORD *)v7 + 1);
        if ( !result && v8 != 1 )
          break;
        switch ( v8 )
        {
          case 1:
            return result;
          case 2:
            v9 = v7[4];
            v10 = v7[5];
            v11 = v7[6];
            if ( v9 == v10 )
              v12 = v9 & v11;
            else
              v12 = (v10 & *(_DWORD *)result ^ v11) & v9 ^ v10 & *(_DWORD *)result;
            goto LABEL_25;
          case 3:
            v13 = v7[4];
            v14 = v7[5];
            v15 = v7[6];
            if ( v13 == v14 )
              LOWORD(v13) = v15 & v13;
            else
              LOWORD(v13) = *(_WORD *)result & v14 ^ (*(_WORD *)result & v14 ^ v15) & v13;
            goto LABEL_29;
          case 4:
            v16 = v7[4];
            v17 = v7[5];
            v18 = v7[6];
            if ( v16 == v17 )
              LOBYTE(v16) = v18 & v16;
            else
              LOBYTE(v16) = *(_BYTE *)result & v17 ^ (*(_BYTE *)result & v17 ^ v18) & v16;
            goto LABEL_33;
          case 5:
            v5 = (v7[5] & (unsigned int)v7[4] & *(_DWORD *)result) >> v7[6];
            continue;
          case 6:
            v4 = (v7[5] & v7[4] & (unsigned int)*(unsigned __int16 *)result) >> v7[6];
            continue;
          case 7:
            v3 = (v7[5] & v7[4] & (unsigned int)*(unsigned __int8 *)result) >> v7[6];
            continue;
          case 8:
            v19 = v7[4];
            v20 = v7[5];
            v21 = v7[6];
            v22 = v19 & v5;
            if ( v19 == v20 )
              v12 = v22 << v21;
            else
              v12 = *(_DWORD *)result & ~v19 & v20 | (v22 << v21);
LABEL_25:
            *(_DWORD *)result = v12;
            continue;
          case 9:
            v23 = v7[4];
            v24 = v7[5];
            v25 = v7[6];
            v26 = v4 & v23;
            if ( v23 == v24 )
              v13 = v26 << v25;
            else
              v13 = (unsigned __int16)(*(_WORD *)result & v24) & ~v23 | (v26 << v25);
LABEL_29:
            *(_WORD *)result = v13;
            break;
          case 10:
            v27 = v7[4];
            v28 = v7[5];
            v29 = v7[6];
            v30 = v3 & v27;
            if ( v27 == v28 )
              v16 = v30 << v29;
            else
              v16 = (unsigned __int8)(*(_BYTE *)result & v28) & ~v27 | (v30 << v29);
LABEL_33:
            *(_BYTE *)result = v16;
            break;
          case 11:
            v31 = 1000;
            v5 = v7[5] & v7[4] & *(_DWORD *)result;
            do
            {
              if ( v7[6] == v5 )
                break;
              qtiseclib_cb_udelay(1LL);
              --v31;
              v5 = v7[5] & v7[4] & **((_DWORD **)v7 + 1);
            }
            while ( v31 );
            break;
          case 12:
            v32 = 1000;
            v4 = *(unsigned __int16 *)result & v7[5] & v7[4];
            do
            {
              if ( v4 == v7[6] )
                break;
              qtiseclib_cb_udelay(1LL);
              --v32;
              v4 = **((unsigned __int16 **)v7 + 1) & v7[5] & v7[4];
            }
            while ( v32 );
            break;
          case 13:
            v33 = 1000;
            v3 = *(unsigned __int8 *)result & v7[5] & v7[4];
            do
            {
              if ( v3 == v7[6] )
                break;
              qtiseclib_cb_udelay(1LL);
              --v33;
              v3 = **((unsigned __int8 **)v7 + 1) & v7[5] & v7[4];
            }
            while ( v33 );
            break;
          default:
            continue;
        }
      }
    }
  }
  return result;
}



