/*0000000000000000 d $d
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 D isr_name
0000000000000000 T is_rpmh_busy
                 U qtisec_free
                 U qtiseclib_cb_spin_lock
                 U qtiseclib_cb_spin_unlock
                 U qtisec_malloc
                 U qtisec_realloc
0000000000000000 T rpmh_clock_toggle
0000000000000000 T rpmh_clz
0000000000000000 T rpmh_core_verify
0000000000000000 T rpmh_core_verify_ptr
0000000000000000 T rpmh_deregister_isr
0000000000000000 T rpmh_err_fatal
0000000000000000 T rpmh_free
0000000000000000 T rpmh_get_timestamp
                 U rpmh_is_processing
0000000000000000 T rpmh_lock
0000000000000000 T rpmh_malloc
0000000000000004 C rpmh_os
0000000000000000 T rpmh_os_init
0000000000000000 T rpmh_realloc
0000000000000000 T rpmh_register_isr
0000000000000000 T rpmh_unlock
                 U timer_qtimer_read_time_us
0000000000000008 C tz_completion_cb
0000000000000008 C tz_timeout_cb
*/
#include "rpmh_image_os.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 is_rpmh_busy()
{
  return (unsigned __int8)rpmh_is_processing;
}




__int64 __fastcall rpmh_clz(int a1)
{
  __int64 result; // x0

  result = 0LL;
  do
  {
    if ( (a1 & 0x80000000) != 0 )
      break;
    result = (unsigned int)(result + 1);
    a1 *= 2;
  }
  while ( (_DWORD)result != 32 );
  return result;
}



__int64 __fastcall rpmh_core_verify(__int64 result)
{
  if ( !(_BYTE)result )
  {
    while ( 1 )
      ;
  }
  return result;
}



__int64 __fastcall rpmh_core_verify_ptr(__int64 result)
{
  if ( !result )
  {
    while ( 1 )
      ;
  }
  return result;
}






      && rpmh_get_timestamp() > (unsigned __int64)(*(_QWORD *)(*(_QWORD *)(rpmh_tcs + v6) + 24 * v1 + 8) + 192000LL) )
    {
      v2 = 1;
      rpmh_core_verify(1LL);
    }
    ++v1;
  }
  return v2;
}



__int64 rpmh_lock()
{
  return qtiseclib_cb_spin_lock(&rpmh_os);
}



unsigned __int64 __fastcall rpmh_malloc(unsigned int a1)
{
  return qtisec_malloc(a1);
}




unsigned __int64 __fastcall rpmh_realloc(__int64 a1, unsigned int a2)
{
  return qtisec_realloc(a1, a2);
}



void *__fastcall rpmh_register_isr(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  void *result; // x0

  if ( a4 )
  {
    if ( a4 == 1 )
    {
      result = &unk_31000;
      tz_timeout_cb = a2;
    }
  }
  else
  {
    result = &unk_31000;
    tz_completion_cb = a2;
  }
  return result;
}



__int64 rpmh_unlock()
{
  return qtiseclib_cb_spin_unlock(&rpmh_os);
}



