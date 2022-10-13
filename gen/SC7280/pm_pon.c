/*0000000000000000 r $d
0000000000000000 r $d
0000000000000000 d $d
0000000000000000 d $d
0000000000000000 b $d
0000000000000000 b $d
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
                 U pm_comm_channel_init_internal
                 U pm_comm_read_byte
                 U pm_comm_read_byte_array
                 U pm_comm_write_byte
                 U pm_comm_write_byte_mask
                 U pm_get_slave_id
0000000000000000 T pm_pon_get_reset_config_val
0000000000000000 T pm_pon_gp_reset_cfg
0000000000000000 T pm_pon_init
0000000000000000 b pm_pon_initialized
0000000000000000 T pm_pon_ps_hold_cfg
0000000000000000 d pon_gp1_reg
0000000000000000 d pon_gp2_reg
0000000000000000 b pon_ps_hold_reg
                 U qtiseclib_cb_udelay
*/
#include "pm_pon.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall pm_pon_get_reset_config_val(int a1, char *a2)
{
  char v2; // w0
  __int64 result; // x0

  switch ( a1 )
  {
    case 0:
      v2 = 1;
      goto LABEL_11;
    case 1:
      v2 = 4;
      goto LABEL_11;
    case 2:
      v2 = 5;
      goto LABEL_11;
    case 3:
      v2 = 6;
      goto LABEL_11;
    case 4:
      v2 = 7;
      goto LABEL_11;
    case 5:
      v2 = 8;
      goto LABEL_11;
    case 7:
      v2 = 9;
      goto LABEL_11;
    case 8:
      v2 = 2;
      goto LABEL_11;
    case 14:
      v2 = 15;
LABEL_11:
      *a2 = v2;
      result = 0LL;
      break;
    default:
      result = 4LL;
      break;
  }
  return result;
}



__int64 __fastcall pm_pon_gp_reset_cfg(unsigned __int8 a1, int a2, unsigned int a3)
{
  int slave_id; // w0
  void *v7; // x20
  unsigned int reset_config_val; // w19
  char v9; // w2
  char v11; // [xsp+2Ah] [xbp+2Ah] BYREF
  char v12; // [xsp+2Bh] [xbp+2Bh] BYREF
  unsigned int v13; // [xsp+2Ch] [xbp+2Ch] BYREF

  v12 = 0;
  v13 = 0;
  slave_id = pm_get_slave_id(a1, 0, &v13);
  if ( a3 > 0xE || slave_id != 0 )
    return 2;
  if ( a2 == 4 )
  {
    v7 = &pon_gp1_reg;
  }
  else
  {
    if ( a2 != 5 )
      return 2;
    v7 = &pon_gp2_reg;
  }
  reset_config_val = pm_pon_get_reset_config_val(a3, &v12);
  if ( !reset_config_val )
  {
    reset_config_val = pm_comm_read_byte(v13, *((_WORD *)v7 + 5), &v11, 0);
    if ( !reset_config_val )
    {
      v9 = *((_BYTE *)v7 + 12);
      v11 &= v9;
      if ( v11 )
      {
        reset_config_val = pm_comm_write_byte_mask(v13, *((_WORD *)v7 + 5), v9, 0, 0);
        qtiseclib_cb_udelay(300LL);
      }
      reset_config_val |= pm_comm_write_byte_mask(v13, *((_WORD *)v7 + 4), *((_BYTE *)v7 + 14), v12, 0);
      if ( v11 )
        reset_config_val |= pm_comm_write_byte_mask(v13, *((_WORD *)v7 + 5), *((_BYTE *)v7 + 12), -1, 0);
    }
  }
  return reset_config_val;
}



__int64 pm_pon_init()
{
  int v0; // w19
  __int64 result; // x0
  __int16 v2; // w1
  char v3; // [xsp+25h] [xbp+25h] BYREF
  char v4; // [xsp+26h] [xbp+26h] BYREF
  char v5; // [xsp+27h] [xbp+27h] BYREF
  __int16 v6; // [xsp+28h] [xbp+28h] BYREF

  v3 = 0;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v0 = pm_comm_read_byte(0, 0x804u, &v3, 0);
  result = v0 | (unsigned int)pm_comm_read_byte(0, 0x805u, &v4, 0);
  if ( !(_DWORD)result )
  {
    result = 4LL;
    if ( v3 == 1 )
    {
      if ( v4 == 8 )
      {
        pon_ps_hold_reg = 2130;
        word_31152 = 2131;
        word_31154 = 255;
        v2 = 128;
      }
      else
      {
        pon_ps_hold_reg = 2138;
        word_31152 = 2139;
        word_31154 = 128;
        v2 = 15;
      }
      word_31156 = v2;
      result = pm_comm_read_byte(0, 0x801u, &v5, 0);
      if ( !(_DWORD)result )
      {
        if ( !v5 )
          word_31152 = pon_ps_hold_reg;
        if ( v4 == 8
          || (result = pm_comm_read_byte_array(0, 0x80Au, 2u, (char *)&v6, 0), !(_DWORD)result)
          && (!v6 || (result = pm_comm_write_byte_mask(0, 0x88Du, 1, 1, 0), !(_DWORD)result)) )
        {
          pm_pon_initialized = 1;
          return 0LL;
        }
      }
    }
  }
  return result;
}



__int64 __fastcall pm_pon_ps_hold_cfg(unsigned __int8 a1, unsigned int a2)
{
  unsigned int inited; // w1
  int slave_id; // w0
  char v6; // w19
  int v7; // w19
  unsigned int v9; // [xsp+3Ch] [xbp+3Ch] BYREF

  v9 = 0;
  inited = pm_comm_channel_init_internal();
  if ( !inited )
  {
    slave_id = pm_get_slave_id(a1, 0, &v9);
    inited = 2;
    if ( !slave_id )
    {
      inited = 4;
      if ( a2 <= 0xE && (pm_pon_initialized || (inited = pm_pon_init()) == 0) )
      {
        switch ( a2 )
        {
          case 0u:
            v6 = 1;
            goto LABEL_17;
          case 1u:
            v6 = 4;
            goto LABEL_17;
          case 2u:
            v6 = 5;
            goto LABEL_17;
          case 3u:
            v6 = 6;
            goto LABEL_17;
          case 4u:
            v6 = 7;
            goto LABEL_17;
          case 5u:
          case 6u:
            v6 = 8;
            goto LABEL_17;
          case 7u:
            v6 = 9;
            goto LABEL_17;
          case 8u:
            v6 = 2;
            goto LABEL_17;
          case 0xEu:
            v6 = 15;
LABEL_17:
            inited = pm_comm_write_byte(v9, word_31152, 0, 0);
            if ( !inited )
            {
              qtiseclib_cb_udelay(300LL);
              v7 = pm_comm_write_byte(v9, pon_ps_hold_reg, v6, 0);
              inited = v7 | pm_comm_write_byte(v9, word_31152, word_31154, 0);
            }
            break;
          default:
            inited = 4;
            break;
        }
      }
    }
  }
  return inited;
}



