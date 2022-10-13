/*0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
0000000000000000 t $x
                 U g_psci_asic_nodes
                 U g_psci_asic_nodes_count
                 U pcu_get_node
                 U pcu_init
                 U pm_app_ps_hold_cfg
                 U qtiseclib_cb_log
                 U qtiseclib_cb_plat_core_pos_by_mpidr
                 U qtiseclib_cb_plat_my_core_pos
0000000000000000 T qtiseclib_psci_init
0000000000000000 T qtiseclib_psci_node_on_finish
0000000000000000 T qtiseclib_psci_node_power_off
0000000000000000 T qtiseclib_psci_node_power_on
0000000000000000 T qtiseclib_psci_node_suspend
0000000000000000 T qtiseclib_psci_node_suspend_finish
0000000000000000 T qtiseclib_psci_system_off
0000000000000000 T qtiseclib_psci_system_reset
0000000000000000 T qtisec_psci_node_down
                 U set_boot_remap
*/
#include "psci_pm.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall qtiseclib_psci_init(unsigned __int64 a1)
{
  _QWORD *v1; // x19
  unsigned __int64 v2; // x20
  __int64 result; // x0
  _QWORD *v4; // x22
  __int64 (__fastcall **v5)(_QWORD *); // x0

  v1 = &unk_1CD38;
  set_boot_remap(a1);
  v2 = 0LL;
  pcu_init();
  result = (__int64)&unk_16000;
  while ( v2 < 9 )
  {
    v4 = v1 - 8;
    if ( (unsigned int)pcu_get_node(*((_DWORD *)v1 - 2), v1) )
    {
      qtiseclib_cb_log(10LL, "PSCI: Sequencer query failed (node: %s)", (&g_psci_asic_nodes)[10 * v2]);
      return 4294967290LL;
    }
    v5 = (__int64 (__fastcall **)(_QWORD *))*(v1 - 7);
    v1 += 10;
    result = (*v5)(v4);
    if ( (_DWORD)result )
      return result;
    ++v2;
  }
  result = (__int64)&(&g_psci_asic_nodes)[10 * (unsigned int)qtiseclib_cb_plat_my_core_pos(result)];
  do
  {
    *(_DWORD *)(result + 40) &= 0xFFFFFFEE;
    result = *(_QWORD *)(result + 48);
  }
  while ( result );
  return result;
}



char **__fastcall qtiseclib_psci_node_on_finish(__int64 a1)
{
  char **result; // x0
  __int64 i; // x1
  bool v4; // zf
  int j; // w19
  __int64 v6; // x20
  __int64 (__fastcall *v7)(__int64, __int64); // x2
  unsigned int v8; // w0
  __int64 v9[8]; // [xsp+30h] [xbp+30h] BYREF

  memset(v9, 0, sizeof(v9));
  result = &(&g_psci_asic_nodes)[10 * (int)qtiseclib_cb_plat_my_core_pos(a1)];
  for ( i = 0LL; ; ++i )
  {
    v4 = (int)i > 7 || result == 0LL;
    if ( v4 || !*(_BYTE *)(a1 + i) )
      break;
    v9[i] = (__int64)result;
    result = (char **)result[6];
  }
  for ( j = i - 1; j != -1; --j )
  {
    v6 = v9[j];
    v7 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v6 + 8) + 16LL);
    if ( v7 )
    {
      v8 = v7(v9[j], a1);
      if ( v8 )
        qtiseclib_cb_log(10LL, "PSCI_PLAT: Node on finish (%s, %d)", *(const char **)v6, v8);
    }
    result = (char **)(*(_DWORD *)(v6 + 40) & 0xFFFFFFFE);
    *(_DWORD *)(v6 + 40) = (_DWORD)result;
  }
  return result;
}



char **__fastcall qtiseclib_psci_node_power_off(__int64 a1)
{
  return qtisec_psci_node_down(a1, 2u);
}



__int64 __fastcall qtiseclib_psci_node_power_on(__int64 a1)
{
  char **v2; // x0
  __int64 i; // x1
  int v4; // w19
  bool v5; // cc
  __int64 v6; // x20
  __int64 (__fastcall *v7)(__int64, __int64); // x2
  unsigned int v8; // w0
  unsigned int v9; // w21
  __int64 v11[8]; // [xsp+30h] [xbp+30h] BYREF

  memset(v11, 0, sizeof(v11));
  v2 = &(&g_psci_asic_nodes)[10 * (int)qtiseclib_cb_plat_core_pos_by_mpidr(a1)];
  for ( i = 0LL; ; ++i )
  {
    v4 = i;
    v5 = v2 && (int)i <= 7;
    if ( !v5 || ((_DWORD)v2[5] & 0x10) == 0 )
      break;
    v11[i] = (__int64)v2;
    v2 = (char **)v2[6];
  }
  while ( 1 )
  {
    if ( --v4 == -1 )
      return 0;
    v6 = v11[v4];
    v7 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v6 + 8) + 8LL);
    if ( v7 )
    {
      v8 = v7(v11[v4], a1);
      v9 = v8;
      if ( v8 )
        break;
    }
    *(_DWORD *)(v6 + 40) &= ~0x10u;
  }
  qtiseclib_cb_log(10LL, "PSCI_PLAT: Node on (%s, %d)", *(const char **)v6, v8);
  return v9;
}



char **__fastcall qtiseclib_psci_node_suspend(__int64 a1)
{
  return qtisec_psci_node_down(a1, 1u);
}



char **__fastcall qtiseclib_psci_node_suspend_finish(__int64 a1)
{
  char **result; // x0
  __int64 i; // x1
  bool v4; // zf
  int j; // w19
  __int64 v6; // x21
  __int64 v7[8]; // [xsp+30h] [xbp+30h] BYREF

  memset(v7, 0, sizeof(v7));
  result = &(&g_psci_asic_nodes)[10 * (unsigned int)qtiseclib_cb_plat_my_core_pos(a1)];
  for ( i = 0LL; ; ++i )
  {
    v4 = (int)i > 7 || result == 0LL;
    if ( v4 || !*(_BYTE *)(a1 + i) )
      break;
    v7[i] = (__int64)result;
    result = (char **)result[6];
  }
  for ( j = i - 1; j != -1; --j )
  {
    v6 = v7[j];
    result = (char **)(*(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v6 + 8) + 32LL))(v6, a1, 1LL);
    if ( (_DWORD)result )
      result = (char **)qtiseclib_cb_log(
                          30LL,
                          "PSCI PLAT: Suspend finish (%s, %d)",
                          *(const char **)v6,
                          (unsigned int)result);
  }
  return result;
}



void __noreturn qtiseclib_psci_system_off()
{
  pm_app_ps_hold_cfg(2u);
  MEMORY[0xC264000] = 0;
  while ( 1 )
    ;
}



void __noreturn qtiseclib_psci_system_reset()
{
  pm_app_ps_hold_cfg(0);
  MEMORY[0xC264000] = 0;
  while ( 1 )
    ;
}



char **__fastcall qtisec_psci_node_down(__int64 a1, unsigned int a2)
{
  char **result; // x0
  __int64 i; // x1
  bool v6; // zf
  int j; // w19
  __int64 v8; // x22
  __int64 v9[8]; // [xsp+40h] [xbp+40h] BYREF

  memset(v9, 0, sizeof(v9));
  result = &(&g_psci_asic_nodes)[10 * (unsigned int)qtiseclib_cb_plat_my_core_pos(a1)];
  for ( i = 0LL; ; ++i )
  {
    v6 = (int)i > 7 || result == 0LL;
    if ( v6 || !*(_BYTE *)(a1 + i) )
      break;
    if ( a2 == 2 )
      *((_DWORD *)result + 10) |= 0x10u;
    v9[i] = (__int64)result;
    result = (char **)result[6];
  }
  for ( j = i - 1; j != -1; --j )
  {
    v8 = v9[j];
    result = (char **)(*(__int64 (__fastcall **)(__int64, __int64, _QWORD))(*(_QWORD *)(v8 + 8) + 24LL))(v8, a1, a2);
    if ( (_DWORD)result )
      result = (char **)qtiseclib_cb_log(
                          30LL,
                          "PSCI PLAT: Node down (%s, %d, %d)",
                          *(const char **)v8,
                          (unsigned int)result,
                          a2);
  }
  return result;
}



