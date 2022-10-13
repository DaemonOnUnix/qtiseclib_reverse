/*0000000000000000 b $d
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 T cmd_db_access_done
0000000000000000 B cmd_db_addr
                 U cmd_db_init
0000000000000000 T cmd_db_prep_access
0000000000000000 T cmd_db_target_mem_init
0000000000000000 T cmd_db_tzbsp_init
*/
#include "cmd_db_target.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>


__int64 __fastcall cmd_db_target_mem_init(_DWORD *a1)
{
  cmd_db_addr = 2156265472LL;
  *a1 = 0x20000;
  return 2156265472LL;
}




