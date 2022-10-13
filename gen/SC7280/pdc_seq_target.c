/*0000000000000000 b $d
0000000000000000 b $d
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 B g_pdc_seq_count
                 U g_pdc_seq_instance_count
                 U g_pdc_seq_instances
0000000000000000 B g_pdc_seqs
0000000000000000 T pdc_seq_driver_init
0000000000000000 T pdc_seq_handle_target_init
*/
#include "pdc_seq_target.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

__int64 __fastcall pdc_seq_handle_target_init(__int64 a1)
{
  if ( !a1 )
    return 0xFFFFFFFFLL;
  if ( *(_QWORD *)(a1 + 48) )
    return 0LL;
  return 0xFFFFFFFFLL;
}



