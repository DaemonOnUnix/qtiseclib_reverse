/*0000000000000464 t $d
0000000000000000 t $x
0000000000000090 t clear_mdcr_epmad_reg_exit
0000000000000000 T cortex_a78_aarch64_sysini
00000000000003bc T cortex_a78_amu_disable
00000000000003e4 t cortex_a78_amu_disable_exit
0000000000000390 T cortex_a78_amu_enable
00000000000003b8 t cortex_a78_amu_enable_exit
0000000000000214 t cortex_a78_amu_restore_exit
000000000000022c t cortex_a78_amu_save_exit
0000000000000128 t cortex_a78_mpmm_default
0000000000000120 t cortex_a78_SC7280_mpmm_start
00000000000001e0 t dummy1
000000000000030c t e_1467580_wa
0000000000000348 t e_1492189_wa
0000000000000268 t e_1503072_wa
0000000000000238 t e_1515634_wa
0000000000000330 t e_1688305_wa
0000000000000378 t e_1821534_wa
0000000000000360 t e_1827429_wa
0000000000000250 t e_1875698_wa
00000000000003e8 t e_1941498_wa
0000000000000400 t e_1951500_wa
00000000000000ec t en_cortex_a78_mpmm_pdp
0000000000000034 t en_dbg_feat
000000000000022c t end_of_function
0000000000000148 t en_error_records
0000000000000020 t en_vfp
00000000000000c8 t en_wr_clus_pm_reg
00000000000000a4 t en_wr_pwr_ctrl_reg
0000000000000090 t en_wr_pwr_ctrl_reg_s_el1
0000000000000218 t power_down_sequence
0000000000000020 t power_up_sequence
00000000000001fc t wa_end
00000000000001a8 t wa_r0p0_start
00000000000001cc t wa_r1p0_start
00000000000001f4 t wa_r1p1_start
0000000000000158 t wa_start
*/
#include "cortex_a78_aarch64_sysini.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall cortex_a78_aarch64_sysini(__int64 result)
{
  unsigned __int64 StatusReg; // x0
  unsigned __int64 v2; // x0

  if ( (unsigned __int8)result == 1LL )
  {
    _WriteStatusReg(
      ARM64_SYSREG(3, 0, 1, 0, 2),
      _ReadStatusReg(ARM64_SYSREG(3, 0, 1, 0, 2)) & 0xFFFFFFFFFFCFFFFFLL | 0x300000);
    __isb(0xFu);
    _WriteStatusReg(
      ARM64_SYSREG(3, 6, 1, 3, 1),
      _ReadStatusReg(ARM64_SYSREG(3, 6, 1, 3, 1)) & 0xFFFFFFFFFFCC39BFLL | 0x310000);
    __isb(0xFu);
    if ( MEMORY[0x1FC8000] == 1612185856LL )
    {
      _WriteStatusReg(ARM64_SYSREG(3, 6, 1, 3, 1), _ReadStatusReg(ARM64_SYSREG(3, 6, 1, 3, 1)) & 0xFFFFFFFFFFDFFFFFLL);
      __isb(0xFu);
    }
    _WriteStatusReg(
      ARM64_SYSREG(3, 6, 1, 0, 1),
      _ReadStatusReg(ARM64_SYSREG(3, 6, 1, 0, 1)) & 0xFFFFFFFFFFFFFF7FLL | 0x80);
    __isb(0xFu);
    _WriteStatusReg(
      ARM64_SYSREG(3, 6, 1, 0, 1),
      _ReadStatusReg(ARM64_SYSREG(3, 6, 1, 0, 1)) & 0xFFFFFFFFFFFFFF7FLL | 0x80);
    _WriteStatusReg(
      ARM64_SYSREG(3, 4, 1, 0, 1),
      _ReadStatusReg(ARM64_SYSREG(3, 4, 1, 0, 1)) & 0xFFFFFFFFFFFFFF7FLL | 0x80);
    __isb(0xFu);
    _WriteStatusReg(
      ARM64_SYSREG(3, 6, 1, 0, 1),
      _ReadStatusReg(ARM64_SYSREG(3, 6, 1, 0, 1)) & 0xFFFFFFFFFFFFEFFFLL | 0x1000);
    _WriteStatusReg(
      ARM64_SYSREG(3, 4, 1, 0, 1),
      _ReadStatusReg(ARM64_SYSREG(3, 4, 1, 0, 1)) & 0xFFFFFFFFFFFFEFFFLL | 0x1000);
    __isb(0xFu);
    StatusReg = _ReadStatusReg(ARM64_SYSREG(3, 6, 15, 2, 0));
    if ( MEMORY[0x1FC8000] == 1612185856LL )
      v2 = StatusReg & 0xFFFFFFFFFFFFFC0FLL | 0x30;
    else
      v2 = StatusReg & 0xFFFFFFFFFFC0000FLL | 0x928C0;
    _WriteStatusReg(ARM64_SYSREG(3, 6, 15, 2, 0), v2 & 0xFFFFFFF0FFFFFFF0LL | 0x10000000FLL);
    __isb(0xFu);
    _WriteStatusReg(ARM64_SYSREG(3, 0, 5, 3, 1), 0LL);
    _ReadStatusReg(ARM64_SYSREG(3, 0, 5, 4, 1));
    _WriteStatusReg(ARM64_SYSREG(3, 0, 5, 4, 1), 0x10DuLL);
    if ( (_ReadStatusReg(ARM64_SYSREG(3, 0, 0, 0, 0)) & 0xF0000F) != 0 )
    {
      if ( (_ReadStatusReg(ARM64_SYSREG(3, 0, 0, 0, 0)) & 0xF0000F) == 0x100000 )
      {
        if ( (_ReadStatusReg(ARM64_SYSREG(3, 0, 0, 0, 6)) & 1) != 1 )
          e_1688305_wa();
        e_1827429_wa();
        e_1821534_wa();
        e_1941498_wa();
        e_1951500_wa();
      }
      else if ( (_ReadStatusReg(ARM64_SYSREG(3, 0, 0, 0, 0)) & 0xF0000F) == 1048577 )
      {
        e_1941498_wa();
        e_1951500_wa();
      }
    }
    else
    {
      e_1688305_wa();
      e_1515634_wa();
      e_1503072_wa();
      e_1467580_wa();
      e_1492189_wa();
      e_1827429_wa();
      e_1821534_wa();
      e_1941498_wa();
    }
    result = 1612185856LL;
  }
  else if ( !(_BYTE)result )
  {
    result = 1612185856LL;
  }
  __dsb(0xFu);
  __isb(0xFu);
  return result;
}



__int64 cortex_a78_amu_disable()
{
  __int64 result; // x0

  result = 1612185856LL;
  if ( MEMORY[0x1FC8000] == 1612185856LL )
  {
    _WriteStatusReg(ARM64_SYSREG(3, 3, 15, 2, 4), 0xFuLL);
    result = 7LL;
    _WriteStatusReg(ARM64_SYSREG(3, 3, 15, 3, 0), 7uLL);
    __isb(0xFu);
  }
  return result;
}



__int64 cortex_a78_amu_enable()
{
  __int64 result; // x0

  result = 1612185856LL;
  if ( MEMORY[0x1FC8000] == 1612185856LL )
  {
    _WriteStatusReg(ARM64_SYSREG(3, 3, 15, 2, 5), 0xFuLL);
    result = 7LL;
    _WriteStatusReg(ARM64_SYSREG(3, 3, 15, 3, 1), 7uLL);
    __isb(0xFu);
  }
  return result;
}



