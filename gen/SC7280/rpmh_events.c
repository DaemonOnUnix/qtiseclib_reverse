/*0000000000000000 d $d
0000000000000000 d $d
0000000000000000 d $d
0000000000000000 d $d
0000000000000000 d $d
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
                 U inq_append
                 U rpmh_core_verify
0000000000000000 t rpmh_create_dal_event
0000000000000000 t rpmh_destroy_dal_event
0000000000000000 D rpmh_event_create
0000000000000000 D rpmh_event_destroy
0000000000000000 D rpmh_event_reset
0000000000000000 D rpmh_event_set
0000000000000000 D rpmh_event_wait
0000000000000000 t rpmh_reset_dal_event
0000000000000000 t rpmh_set_dal_event
0000000000000000 t rpmh_wait_dal_event
*/
#include "rpmh_events.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
