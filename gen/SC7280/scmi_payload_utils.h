#pragma once
#include "defs.h"
__int64 __fastcall get_input_payload_char_at_offset(__int64 a1, int a2);
__int64 __fastcall get_input_payload_word_at_offset(__int64 a1, int a2);
__int64 __fastcall scmi_packet_init_payload(__int64 result);
__int64 __fastcall write_output_payload_word(__int64 result, int a2);
__int64 __fastcall write_output_payload_word_at_offset(__int64 result, int a2, int a3);
