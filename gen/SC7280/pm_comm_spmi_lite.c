/*0000000000000000 b $d
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 T pm_comm_channel_init_internal
0000000000000000 T pm_comm_read_byte
0000000000000000 T pm_comm_read_byte_array
0000000000000000 T pm_comm_read_byte_mask
0000000000000000 T pm_comm_write_byte
0000000000000000 T pm_comm_write_byte_array
0000000000000000 T pm_comm_write_byte_mask
                 U SpmiBus_Init
                 U SpmiBus_ReadLong
                 U SpmiBus_WriteLong
0000000000000000 b spmi_initialized
*/
#include "pm_comm_spmi_lite.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 pm_comm_channel_init_internal()
{
  int v0; // w0
  unsigned int v1; // w1

  v0 = SpmiBus_Init();
  v1 = 128;
  if ( !v0 )
  {
    spmi_initialized = 1;
    return 0;
  }
  return v1;
}



__int64 __fastcall pm_comm_read_byte(char a1, unsigned __int16 a2, char *a3, unsigned __int8 a4)
{
  int Long; // w0
  unsigned int v5; // w1
  int v7; // [xsp+1Ch] [xbp+1Ch] BYREF

  v7 = 0;
  if ( (unsigned __int8)spmi_initialized <= (unsigned int)(a2 == 0xFFFF) )
    return 128;
  Long = SpmiBus_ReadLong(a1, a4, a2, a3, 1u, (__int64 *)&v7);
  v5 = 0;
  if ( Long )
    return 128;
  return v5;
}



__int64 __fastcall pm_comm_read_byte_array(char a1, unsigned __int16 a2, unsigned int a3, char *a4, unsigned __int8 a5)
{
  int Long; // w0
  unsigned int v6; // w1
  int v8; // [xsp+1Ch] [xbp+1Ch] BYREF

  v8 = 0;
  if ( (unsigned __int8)spmi_initialized <= (unsigned int)(a2 == 0xFFFF) )
    return 128;
  Long = SpmiBus_ReadLong(a1, a5, a2, a4, a3, (__int64 *)&v8);
  v6 = 0;
  if ( Long )
    return 128;
  return v6;
}



__int64 __fastcall pm_comm_read_byte_mask(char a1, unsigned __int16 a2, char a3, char *a4, unsigned __int8 a5)
{
  __int64 result; // x0

  result = pm_comm_read_byte(a1, a2, a4, a5);
  if ( (_DWORD)result )
    return 128LL;
  *a4 &= a3;
  return result;
}



__int64 __fastcall pm_comm_write_byte(char a1, unsigned __int16 a2, char a3, unsigned __int8 a4)
{
  int v4; // w0
  unsigned int v5; // w1
  char v7; // [xsp+1Fh] [xbp+1Fh] BYREF

  v7 = a3;
  if ( (unsigned __int8)spmi_initialized <= (unsigned int)(a2 == 0xFFFF) )
    return 128;
  v4 = SpmiBus_WriteLong(a1, a4, a2, &v7, 1u);
  v5 = 0;
  if ( v4 )
    return 128;
  return v5;
}



__int64 __fastcall pm_comm_write_byte_array(
        char a1,
        unsigned __int16 a2,
        unsigned int a3,
        char *a4,
        unsigned __int8 a5)
{
  int v5; // w0
  unsigned int v6; // w1

  if ( (unsigned __int8)spmi_initialized <= (unsigned int)(a2 == 0xFFFF) )
    return 128LL;
  v5 = SpmiBus_WriteLong(a1, a5, a2, a4, a3);
  v6 = 0;
  if ( v5 )
    return 128;
  return v6;
}



__int64 __fastcall pm_comm_write_byte_mask(char a1, unsigned __int16 a2, char a3, char a4, unsigned __int8 a5)
{
  int v5; // w21
  int v7; // w23
  char v11; // [xsp+4Bh] [xbp+4Bh] BYREF
  int v12; // [xsp+4Ch] [xbp+4Ch] BYREF

  v5 = a2;
  v11 = 0;
  v12 = 1;
  if ( (unsigned __int8)spmi_initialized > (unsigned int)(a2 == 0xFFFF)
    && ((v7 = a5, (unsigned int)SpmiBus_ReadLong(a1, a5, a2, &v11, 1u, (__int64 *)&v12))
     || (v11 = v11 & ~a3 | a3 & a4, !(unsigned int)SpmiBus_WriteLong(a1, v7, v5, &v11, 1u))) )
  {
    return 0LL;
  }
  else
  {
    return 128LL;
  }
}



