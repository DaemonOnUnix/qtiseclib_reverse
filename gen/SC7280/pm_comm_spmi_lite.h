#pragma once
#include "defs.h"
__int64 pm_comm_channel_init_internal();
__int64 __fastcall pm_comm_read_byte(char a1, unsigned __int16 a2, char *a3, unsigned __int8 a4);
__int64 __fastcall pm_comm_read_byte_array(char a1, unsigned __int16 a2, unsigned int a3, char *a4, unsigned __int8 a5);
__int64 __fastcall pm_comm_read_byte_mask(char a1, unsigned __int16 a2, char a3, char *a4, unsigned __int8 a5);
__int64 __fastcall pm_comm_write_byte(char a1, unsigned __int16 a2, char a3, unsigned __int8 a4);
__int64 __fastcall pm_comm_write_byte_array(char a1, unsigned __int16 a2, unsigned int a3, char *a4, unsigned __int8 a5);
__int64 __fastcall pm_comm_write_byte_mask(char a1, unsigned __int16 a2, char a3, char a4, unsigned __int8 a5);
