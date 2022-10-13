/*0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
                 U calculate_cpumasks
                 U cmd_db_query_addr
                 U cmd_db_query_aux_data
                 U cmd_db_tzbsp_init
0000000000000000 t CPR11_SVSL1_QUOT_VMIN
0000000000000000 T cpucp_host_configure_shared_data
0000000000000000 T cpucp_load_firmware
0000000000000000 T cpucp_prepare
0000000000000000 T cpucp_start
0000000000000000 T cpucp_unprepare
*/
#include "load_firmware.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 cpucp_host_configure_shared_data()
{
  __int64 result; // x0
  char v1; // w20
  __int16 v2; // w0
  __int16 v3; // x5^2
  _DWORD *v4; // x6
  int *v5; // x3
  int v6; // w0
  char v7; // w2
  _DWORD *v8; // x4

  result = 0xFFFFFFFFLL;
  v1 = MEMORY[0x18508000];
  if ( MEMORY[0x18508000] == 3 )
  {
    calculate_cpumasks(407930404LL);
    MEMORY[0x18508634] |= MEMORY[0x1850862C] | MEMORY[0x18508628] | MEMORY[0x18508624] | MEMORY[0x18508630];
    MEMORY[0x18508220] = MEMORY[0x1FC8000] | (MEMORY[0x1FC8001] << 16);
    MEMORY[0x18508224] = (MEMORY[0x784210] >> 6) & 0xF;
    MEMORY[0x18508228] = MEMORY[0x784180] >> 29;
    MEMORY[0x18508234] = MEMORY[0x78070C] & 0xF;
    MEMORY[0x18508238] = MEMORY[0x7802DC] >> 29;
    MEMORY[0x1850822C] = (unsigned __int8)((unsigned __int64)MEMORY[0x784180] >> 20);
    MEMORY[0x185082A1] = 8;
    MEMORY[0x185082A2] = 8;
    MEMORY[0x185082A3] = 8;
    MEMORY[0x185085D3] = 0;
    MEMORY[0x185085DC] = 0;
    MEMORY[0x185085CA] = 0;
    MEMORY[0x18508230] = MEMORY[0x784180] & 0xFFFFF;
    MEMORY[0x1850837A] = 8
                       * ((MEMORY[0x784290] >> 13) & 0x1F)
                       * (((__int64)((unsigned __int64)MEMORY[0x784290] << 45) >> 63) | 1);
    MEMORY[0x1850837C] = 8
                       * ((4 * (MEMORY[0x7842AC] & 0xF) + (MEMORY[0x7842A8] >> 30)) & 0x1F)
                       * (((__int64)((unsigned __int64)(4 * (MEMORY[0x7842AC] & 0xFu) + (MEMORY[0x7842A8] >> 30)) << 58) >> 63) | 1);
    MEMORY[0x1850837E] = 8 * (MEMORY[0x7842AB] & 0x1F) * (((__int16)(MEMORY[0x7842A8] >> 14) >> 15) | 1);
    MEMORY[0x1850847C] = CPR11_SVSL1_QUOT_VMIN() - ((MEMORY[0x7842B0] >> 8) & 0xFFF);
    v2 = CPR11_SVSL1_QUOT_VMIN();
    MEMORY[0x1850847E] = (v3 & 0xFFF) - v2;
    MEMORY[0x1850857A] = (*v4 >> 8) & 0xFFF;
    MEMORY[0x1850857C] = CPR11_SVSL1_QUOT_VMIN();
    v6 = *v5;
    MEMORY[0x185082A4] = v7;
    MEMORY[0x1850857E] = HIWORD(v6) & 0xFFF;
    MEMORY[0x18508380] = 8 * ((*v8 >> 18) & 0x1F) * (((__int64)((unsigned __int64)(unsigned int)*v8 << 40) >> 63) | 1);
    MEMORY[0x18508480] = ((unsigned __int16)*v5 >> 4) - (HIWORD(*v5) & 0xFFF);
    MEMORY[0x18508580] = (unsigned __int16)*v5 >> 4;
    MEMORY[0x185082A9] = v7;
    MEMORY[0x185082AA] = v7;
    MEMORY[0x18508244] = (unsigned __int64)MEMORY[0x7842B4] >> 10;
    MEMORY[0x185082AB] = 9;
    MEMORY[0x1850838A] = 8
                       * ((MEMORY[0x7842B8] >> 4) & 0x1F)
                       * (((__int64)((unsigned __int64)MEMORY[0x7842B8] << 54) >> 63) | 1);
    MEMORY[0x1850838C] = 8
                       * ((4 * (MEMORY[0x7842B8] & 0xF) + (MEMORY[0x7842B4] >> 30)) & 0x1F)
                       * (((__int64)((unsigned __int64)(4 * (MEMORY[0x7842B8] & 0xFu) + (MEMORY[0x7842B4] >> 30)) << 58) >> 63) | 1);
    MEMORY[0x1850838E] = 8
                       * (MEMORY[0x7842B7] & 0x1F)
                       * (((__int64)((unsigned __int64)MEMORY[0x7842B4] << 34) >> 63) | 1);
    MEMORY[0x1850848C] = (((unsigned __int64)MEMORY[0x7842BC] >> 2) & 0xFFF)
                       - (((unsigned __int64)MEMORY[0x7842BC] >> 14) & 0xFFF);
    MEMORY[0x1850848E] = 5 * (((MEMORY[0x7842C0] & 3) << 6) + (MEMORY[0x7842BC] >> 26));
    MEMORY[0x1850858A] = ((unsigned __int64)MEMORY[0x7842BC] >> 14) & 0xFFF;
    MEMORY[0x1850858C] = ((unsigned __int64)MEMORY[0x7842BC] >> 2) & 0xFFF;
    MEMORY[0x185082AC] = 9;
    MEMORY[0x1850858E] = ((MEMORY[0x7842BC] & 3) << 10) + (MEMORY[0x7842B8] >> 22);
    MEMORY[0x18508390] = 8
                       * ((MEMORY[0x7842B4] >> 18) & 0x1F)
                       * (((__int64)((unsigned __int64)MEMORY[0x7842B4] << 40) >> 63) | 1);
    MEMORY[0x185082B9] = v7;
    MEMORY[0x185082BA] = v7;
    MEMORY[0x18508245] = (unsigned __int64)MEMORY[0x7842B4] >> 10;
    MEMORY[0x185082BB] = v7;
    MEMORY[0x18508590] = ((unsigned __int64)MEMORY[0x7842B8] >> 10) & 0xFFF;
    MEMORY[0x18508490] = MEMORY[0x18508590] - (MEMORY[0x7842B8] >> 22) - ((MEMORY[0x7842BC] & 3) << 10);
    MEMORY[0x185083AA] = 8
                       * (((unsigned __int64)MEMORY[0x7842D4] >> 22) & 0x1F)
                       * (((__int64)((unsigned __int64)MEMORY[0x7842D4] << 36) >> 63) | 1);
    MEMORY[0x185083AC] = 8
                       * (MEMORY[0x7842D6] & 0x1F)
                       * (((__int64)((unsigned __int64)MEMORY[0x7842D4] << 42) >> 63) | 1);
    MEMORY[0x185083AE] = 8
                       * ((MEMORY[0x7842D4] >> 10) & 0x1F)
                       * (((__int64)((unsigned __int64)MEMORY[0x7842D4] << 48) >> 63) | 1);
    MEMORY[0x185084AC] = (MEMORY[0x7842D8] >> 20) - (MEMORY[0x7842DC] & 0xFFF);
    MEMORY[0x185084AE] = ((MEMORY[0x7842D8] >> 8) & 0xFFF) - (MEMORY[0x7842D8] >> 20);
    MEMORY[0x185085AA] = MEMORY[0x7842DC] & 0xFFF;
    MEMORY[0x185085AC] = MEMORY[0x7842D8] >> 20;
    MEMORY[0x185082BD] = v7;
    MEMORY[0x185085AE] = (MEMORY[0x7842D8] >> 8) & 0xFFF;
    MEMORY[0x185083B2] = 8
                       * (((unsigned __int64)MEMORY[0x7842D4] >> 4) & 0x1F)
                       * (((__int64)((unsigned __int64)MEMORY[0x7842D4] << 54) >> 63) | 1);
    MEMORY[0x185084B2] = 16 * MEMORY[0x7842D8] + (MEMORY[0x7842D4] >> 28) - ((MEMORY[0x7842D8] >> 8) & 0xFFF);
    MEMORY[0x185085B2] = 16 * MEMORY[0x7842D8] + (MEMORY[0x7842D4] >> 28);
    MEMORY[0x185082B3] = 11;
    MEMORY[0x185082B1] = 13;
    MEMORY[0x18508247] = 16 * (MEMORY[0x7842D4] & 0xF) + (MEMORY[0x7842D0] >> 28);
    MEMORY[0x185082B2] = 13;
    MEMORY[0x1850839A] = 8
                       * ((16 * (MEMORY[0x7842C8] & 3) + (MEMORY[0x7842C4] >> 28)) & 0x1F)
                       * (((__int64)((unsigned __int64)(16 * (MEMORY[0x7842C8] & 3u) + (MEMORY[0x7842C4] >> 28)) << 58) >> 63) | 1);
    MEMORY[0x1850839C] = 8
                       * ((MEMORY[0x7842C4] >> 22) & 0x1F)
                       * (((__int64)((unsigned __int64)MEMORY[0x7842C4] << 36) >> 63) | 1);
    MEMORY[0x1850839E] = 8
                       * (MEMORY[0x7842C6] & 0x1F)
                       * (((__int64)((unsigned __int64)MEMORY[0x7842C4] << 42) >> 63) | 1);
    MEMORY[0x1850849C] = (((unsigned __int64)MEMORY[0x7842CC] >> 6) & 0xFFF)
                       - (((unsigned __int64)MEMORY[0x7842CC] >> 18) & 0xFFF);
    MEMORY[0x1850849E] = 5 * (unsigned __int8)((unsigned __int64)MEMORY[0x7842D0] >> 14);
    MEMORY[0x1850859A] = ((unsigned __int64)MEMORY[0x7842CC] >> 18) & 0xFFF;
    MEMORY[0x1850859C] = ((unsigned __int64)MEMORY[0x7842CC] >> 6) & 0xFFF;
    MEMORY[0x185082B5] = 11;
    MEMORY[0x1850859E] = ((MEMORY[0x7842CC] & 0x3F) << 6) + (MEMORY[0x7842C8] >> 26);
    MEMORY[0x185083A2] = 8
                       * ((MEMORY[0x7842C4] >> 4) & 0x1F)
                       * (((__int64)((unsigned __int64)MEMORY[0x7842C4] << 54) >> 63) | 1);
    MEMORY[0x185084A2] = (((unsigned __int64)MEMORY[0x7842C8] >> 2) & 0xFFF)
                       - (((unsigned __int64)MEMORY[0x7842C8] >> 14) & 0xFFF);
    MEMORY[0x185082B4] = 11;
    MEMORY[0x185085A2] = ((unsigned __int64)MEMORY[0x7842C8] >> 2) & 0xFFF;
    MEMORY[0x185083A0] = 8
                       * ((MEMORY[0x7842C4] >> 10) & 0x1F)
                       * (((__int64)((unsigned __int64)MEMORY[0x7842C4] << 48) >> 63) | 1);
    MEMORY[0x185084A0] = (((unsigned __int64)MEMORY[0x7842C8] >> 14) & 0xFFF)
                       - (MEMORY[0x7842C8] >> 26)
                       - ((MEMORY[0x7842CC] & 0x3F) << 6);
    MEMORY[0x185085A0] = ((unsigned __int64)MEMORY[0x7842C8] >> 14) & 0xFFF;
    MEMORY[0x18508246] = MEMORY[0x18508247];
    cmd_db_tzbsp_init();
    MEMORY[0x185085F0] = cmd_db_query_addr((__int64)"mx.lvl");
    MEMORY[0x185085F4] = 28;
    cmd_db_query_aux_data((__int64)"mx.lvl", (_BYTE *)0x185085F4, 407930358LL);
    MEMORY[0x18508614] = v1;
    MEMORY[0x18508615] = 13;
    MEMORY[0x18508618] = 0;
    MEMORY[0x18508616] = 1;
    MEMORY[0x18508617] = 1;
    MEMORY[0x18508619] = 1;
    MEMORY[0x1850861B] = 1;
    MEMORY[0x1850861D] = 1;
    MEMORY[0x1850861F] = 1;
    result = 0LL;
    MEMORY[0x1850861A] = 0;
    MEMORY[0x1850861C] = 0;
    MEMORY[0x1850861E] = 0;
    MEMORY[0x18508620] = 0;
  }
  return result;
}



__int64 cpucp_load_firmware()
{
  return 0LL;
}



__int64 cpucp_prepare()
{
  MEMORY[0x18598000] |= 1u;
  MEMORY[0x18580000] |= 1u;
  while ( (MEMORY[0x18580000] & 1) == 0 )
    ;
  return 0LL;
}



__int64 cpucp_start()
{
  __int64 result; // x0

  MEMORY[0x182A00B0] = MEMORY[0x182A00B0] & 3 | 0x200;
  MEMORY[0x182A00B0] = MEMORY[0x182A00B0] & 0xF00 | 1;
  MEMORY[0x182A000C] = MEMORY[0x182A000C] & 0xF0000000 | 1;
  MEMORY[0x182A0010] = 2;
  MEMORY[0x182A007C] = MEMORY[0x182A007C] & 0xF0000000 | 1;
  MEMORY[0x182A0080] = 0;
  MEMORY[0x182A005C] = MEMORY[0x182A005C] & 0xF0000000 | 1;
  MEMORY[0x182A0060] = 0;
  MEMORY[0x182A008C] = MEMORY[0x182A008C] & 0xF0000000 | 1;
  MEMORY[0x182A0090] = 1;
  MEMORY[0x18598018] = 19230;
  MEMORY[0x18598010] |= 1u;
  result = cpucp_host_configure_shared_data();
  if ( !(_DWORD)result )
  {
    MEMORY[0x18598000] &= ~1u;
    MEMORY[0x18598024] = 0;
    MEMORY[0x18598004] |= 1u;
    result = MEMORY[0x18580000] | 2u;
    MEMORY[0x18580000] |= 2u;
  }
  return result;
}



__int64 cpucp_unprepare()
{
  MEMORY[0x18598000] &= ~1u;
  MEMORY[0x18580000] &= ~1u;
  return 0LL;
}



