/*0000000000000168 t $d
0000000000000000 t $x
000000000000015c t end_of_function
0000000000000000 T kryo400_gold_aarch64_config_wa_sysini
0000000000000038 t kryo400_gold_aarch64_config_wa_sysini_end
0000000000000040 T kryo400_gold_aarch64_sysini
000000000000015c t power_down_sequence
0000000000000060 t power_up_sequence
0000000000000168 T SYSINI_VERSION_KRYO400GOLD
*/
#include "kryo400_gold_aarch64_sysini.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
unsigned __int64 __fastcall kryo400_gold_aarch64_config_wa_sysini(unsigned __int64 result, int a2)
{
  if ( (_DWORD)result == -2147450881 )
  {
    if ( a2 )
      result = _ReadStatusReg(ARM64_SYSREG(3, 0, 15, 1, 1)) & 0xFFFFFFFFFFFEFFFFLL | 0x10000;
    else
      result = _ReadStatusReg(ARM64_SYSREG(3, 0, 15, 1, 1)) & 0xFFFFFFFFFFFEFFFFLL;
    _WriteStatusReg(ARM64_SYSREG(3, 0, 15, 1, 1), result);
  }
  __isb(0xFu);
  return result;
}



__int64 __fastcall kryo400_gold_aarch64_sysini(__int64 result)
{
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
    _WriteStatusReg(ARM64_SYSREG(3, 6, 1, 0, 1), _ReadStatusReg(ARM64_SYSREG(3, 6, 1, 0, 1)) & 0xFFFFFFFFFFFFFFFELL | 1);
    _WriteStatusReg(ARM64_SYSREG(3, 4, 1, 0, 1), _ReadStatusReg(ARM64_SYSREG(3, 4, 1, 0, 1)) & 0xFFFFFFFFFFFFFFFELL | 1);
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
    result = 269LL;
    _WriteStatusReg(ARM64_SYSREG(3, 0, 5, 4, 1), 0x10DuLL);
  }
  __dsb(0xFu);
  __isb(0xFu);
  return result;
}




