/*00000000000001b4 t $d
0000000000000000 t $x
00000000000000a0 t clear_mdcr_epmad_reg_exit
000000000000008c t clear_mdcr_epmad_reg_start
0000000000000000 T cortex_a55_aarch64_sysini
00000000000001a8 t end_of_function
0000000000000000 T kryo500_silver_aarch64_sysini
00000000000001a4 t l_992657_exit
0000000000000190 t l_992657_start
00000000000001a8 t power_down_sequence
0000000000000020 t power_up_sequence
*/
#include "kryo500_silver_aarch64_sysini.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

__int64 __fastcall kryo500_silver_aarch64_sysini(__int64 result)
{
  if ( (unsigned __int8)result == 1LL )
  {
    _WriteStatusReg(
      ARM64_SYSREG(3, 0, 1, 0, 2),
      _ReadStatusReg(ARM64_SYSREG(3, 0, 1, 0, 2)) & 0xFFFFFFFFFFCFFFFFLL | 0x300000);
    __isb(0xFu);
    _WriteStatusReg(ARM64_SYSREG(3, 4, 5, 3, 0), 0x40000000uLL);
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
    _WriteStatusReg(ARM64_SYSREG(3, 6, 1, 0, 1), _ReadStatusReg(ARM64_SYSREG(3, 6, 1, 0, 1)) & 0xFFFFFFFFFFFFFFFDLL | 2);
    __isb(0xFu);
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
    _WriteStatusReg(ARM64_SYSREG(3, 0, 1, 0, 4), 0LL);
    __isb(0xFu);
    _WriteStatusReg(ARM64_SYSREG(3, 0, 5, 3, 1), 0LL);
    _ReadStatusReg(ARM64_SYSREG(3, 0, 5, 4, 1));
    _WriteStatusReg(ARM64_SYSREG(3, 0, 5, 4, 1), 0x10DuLL);
    _WriteStatusReg(ARM64_SYSREG(3, 6, 15, 8, 2), 0x8500020uLL);
    _WriteStatusReg(ARM64_SYSREG(3, 6, 15, 8, 3), 0x21FF00000uLL);
    _WriteStatusReg(ARM64_SYSREG(3, 6, 15, 8, 1), 0x11003FDuLL);
    _WriteStatusReg(ARM64_SYSREG(3, 6, 15, 8, 0), 1uLL);
    _WriteStatusReg(ARM64_SYSREG(3, 6, 15, 8, 2), 0x8D00040uLL);
    _WriteStatusReg(ARM64_SYSREG(3, 6, 15, 8, 3), 0x21FF00040uLL);
    _WriteStatusReg(ARM64_SYSREG(3, 6, 15, 8, 1), 0x11003FDuLL);
    result = 33325056LL;
  }
  __dsb(0xFu);
  __isb(0xFu);
  return result;
}



