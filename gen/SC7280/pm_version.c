/*0000000000000000 b $d
0000000000000000 b $d
0000000000000000 b $d
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
                 U pm_comm_read_byte_array
0000000000000000 b pm_device_info_arr
0000000000000000 T pm_get_pmic_model
0000000000000000 T pm_get_slave_id
0000000000000000 b pm_primary_slave_id
0000000000000000 T pm_version_detect
0000000000000000 b pm_version_initialized
                 U qtiseclib_cb_memset
*/
#include "pm_version.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall pm_get_pmic_model(unsigned __int8 a1)
{
  if ( (unsigned __int8)pm_version_initialized <= (unsigned int)(a1 > 6u) )
    return 0x7FFFFFFFLL;
  else
    return (unsigned int)pm_device_info_arr[3 * a1];
}



__int64 __fastcall pm_get_slave_id(unsigned __int8 a1, unsigned __int8 a2, unsigned int *a3)
{
  unsigned int v4; // w1

  if ( !a3 || (unsigned __int8)pm_version_initialized <= (unsigned int)(a2 > 1u) )
    return 4LL;
  if ( a1 != 7 )
  {
    if ( a1 <= 6u )
    {
      v4 = a2 + pm_primary_slave_id[a1];
      *a3 = v4;
      if ( v4 <= 0xD )
        return 0LL;
    }
    return 4LL;
  }
  *a3 = a2 + 14;
  return 0LL;
}



__int64 pm_version_detect()
{
  __int64 result; // x0
  int *v1; // x19
  __int64 v2; // x20
  int v3; // w21
  char v4[8]; // [xsp+40h] [xbp+40h] BYREF
  char v5; // [xsp+48h] [xbp+48h] BYREF

  qtiseclib_cb_memset(&v5, 0LL, 6LL);
  qtiseclib_cb_memset(v4, 0LL, 4LL);
  result = 0LL;
  if ( !pm_version_initialized )
  {
    v1 = pm_device_info_arr;
    v2 = 0LL;
    qtiseclib_cb_memset(pm_primary_slave_id, 255LL, 28LL);
    while ( 1 )
    {
      v3 = 2 * v2;
      result = pm_comm_read_byte_array(2 * (unsigned __int8)v2, 0x102u, 4u, v4, 0);
      if ( (_DWORD)result )
      {
        result = 0LL;
      }
      else if ( v4[2] == 81 )
      {
        *v1 = (unsigned __int8)v4[3];
        v1[1] = (unsigned __int8)v4[1];
        v1[2] = (unsigned __int8)v4[0];
        result = pm_comm_read_byte_array(v3, 0x100u, 6u, &v5, 0);
        pm_primary_slave_id[v2] = v3;
      }
      if ( v2 == 6 )
        break;
      ++v2;
      v1 += 3;
    }
    pm_version_initialized = 1;
  }
  return result;
}



