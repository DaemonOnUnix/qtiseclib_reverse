/*0000000000000000 b $d
0000000000000000 t $x
0000000000000000 T cpucp_scmi_send
                 U get_input_payload_word_at_offset
                 U qtiseclib_cb_spin_lock
                 U qtiseclib_cb_spin_unlock
                 U scmi_construct_msg_hdr
0000000000000000 B scmi_host_spinlock
                 U scmi_packet_init_payload
                 U write_output_payload_word
*/
#include "scmi_host.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall cpucp_scmi_send(
        unsigned __int8 a1,
        unsigned __int8 a2,
        __int64 a3,
        unsigned int a4,
        _DWORD *a5,
        __int64 a6,
        unsigned int *a7)
{
  bool v7; // zf
  unsigned int v8; // w19
  unsigned __int64 v16; // x23
  unsigned __int64 StatusReg; // x0
  unsigned __int64 v18; // x2
  unsigned int v20; // w19
  unsigned int v21; // w24
  int v23; // w1
  unsigned __int64 v24; // x1
  unsigned __int64 v25; // x23
  unsigned int v27; // w0
  __int64 v28; // x3
  unsigned int v29; // w0
  __int64 v30; // x2
  __int64 i; // x1
  int v32; // t1
  __int64 v33; // x0
  __int64 v34; // x4
  __int64 v35; // x0
  __int64 v36; // x1
  __int64 v37; // x3

  if ( a3 )
    v7 = 1;
  else
    v7 = a4 == 0;
  v8 = -1;
  if ( v7 )
  {
    v8 = -2;
    if ( a4 <= 0x64 )
    {
      qtiseclib_cb_spin_lock(&scmi_host_spinlock);
      v16 = 500 * _ReadStatusReg(ARM64_SYSREG(3, 3, 14, 0, 0)) / 0x3E8;
      StatusReg = _ReadStatusReg(ARM64_SYSREG(3, 3, 14, 0, 1));
      v18 = v16 + StatusReg;
      while ( StatusReg < v18 && MEMORY[0x18509004] != 1 )
        StatusReg = _ReadStatusReg(ARM64_SYSREG(3, 3, 14, 0, 1));
      if ( MEMORY[0x18509004] != 1 )
        goto LABEL_14;
      __dsb(0xFu);
      MEMORY[0x18509018] = scmi_construct_msg_hdr(a2, 0, a1, 0);
      MEMORY[0x18509004] = 0;
      MEMORY[0x18509010] = 0;
      v20 = (a4 + 3) >> 2;
      v21 = 0;
      scmi_packet_init_payload(407932928LL);
      while ( v21 < v20 && a3 != 0 )
      {
        v23 = *(_DWORD *)(a3 + 4LL * v21++);
        write_output_payload_word(407932928LL, v23);
      }
      get_input_payload_word_at_offset(407932928LL, 1);
      MEMORY[0x17C00008] = 0x10000000;
      v24 = _ReadStatusReg(ARM64_SYSREG(3, 3, 14, 0, 1));
      v25 = v16 + v24;
      while ( MEMORY[0x18509004] != 1 && v24 < v25 )
        v24 = _ReadStatusReg(ARM64_SYSREG(3, 3, 14, 0, 1));
      if ( MEMORY[0x18509004] == 1 )
      {
        __dsb(0xFu);
        if ( MEMORY[0x18509014] <= 7u )
        {
LABEL_31:
          v8 = 0;
          if ( a7 )
          {
            if ( *a7 )
            {
              if ( MEMORY[0x18509014] > 8u )
              {
                v8 = -3;
                if ( a6 )
                {
                  v27 = MEMORY[0x18509014] - 8;
                  if ( *a7 >= MEMORY[0x18509014] - 8 )
                  {
                    v28 = v27 >> 2;
                    v29 = v27 >> 2;
                    v30 = 407932960LL;
                    for ( i = 0LL; i != v28; ++i )
                    {
                      v32 = *(_DWORD *)v30;
                      v30 += 4LL;
                      *(_DWORD *)(a6 + 4 * i) = v32;
                    }
                    v33 = 4LL * (v29 & 0x3FFFFFFF);
                    v34 = v33 + 407932960;
                    v35 = a6 + v33;
                    v36 = 0LL;
                    v37 = MEMORY[0x18509014] & 3;
                    while ( v37 != v36 )
                    {
                      *(_BYTE *)(v35 + v36) = *(_BYTE *)(v34 + v36);
                      ++v36;
                    }
                    v8 = 0;
                    *a7 = MEMORY[0x18509014] - 8;
                  }
                  else
                  {
                    v8 = -4;
                    *a7 = v27;
                  }
                }
              }
            }
          }
          goto LABEL_44;
        }
        v8 = -5;
        if ( a5 )
        {
          *a5 = MEMORY[0x1850901C];
          goto LABEL_31;
        }
      }
      else
      {
LABEL_14:
        v8 = -6;
      }
LABEL_44:
      qtiseclib_cb_spin_unlock(&scmi_host_spinlock);
    }
  }
  return v8;
}



