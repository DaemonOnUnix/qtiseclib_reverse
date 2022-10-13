/*0000000000000000 d $d
0000000000000000 d $d
0000000000000000 b $d
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
0000000000000000 t $x
0000000000000000 D DrvBaseAddressMapping_array_subsystem
0000000000000000 D DrvBaseAddressMappingTable_subsystem
0000000000000068 C GlobalRscHalCtxt
0000000000000000 T isContextInitialized
0000000000000000 b numTcsPerHLOSDrv
                 U rpmh_core_verify
0000000000000000 T RscHalCheckAMCFinishedIRQ
0000000000000000 T RscHalCheckTCSCmdCompletionStatus
0000000000000000 T RscHalCheckTCSCmdIssueStatus
0000000000000000 T RscHalCheckTCSCmdTriggerStatus
0000000000000000 T RscHalCheckTCSIdle_HLOS
0000000000000000 T RscHalClearAMCFinishedIRQ
0000000000000000 T RscHalClearePCBTimedOut
0000000000000000 T RscHalConfigureCmdCompletion
0000000000000000 T RscHalConvertAMCtoTCS
0000000000000000 T RscHalConvertTCStoAMC
0000000000000000 T RscHalDisableAMCFinishedIRQ
0000000000000000 T RscHalEnableAMCFinishedIRQ
0000000000000000 T rscHalGetChipsetMappingTable
0000000000000000 T rscHalGetContext
0000000000000000 T rscHalGetDrvInfo
0000000000000000 T rscHalGetNumCmdsPerTcs
0000000000000000 T rscHalGetNumTcs
0000000000000000 T RscHalIsePCBTimedOut
0000000000000000 T RscHalIsTCSIdle
0000000000000000 T RscHalReadConfig
0000000000000000 T RscHalReadResponseData
0000000000000000 T RscHalRegisterDrv
0000000000000000 T rscHalSetupDrv0Tcs
0000000000000000 T rscHalSetupDrv2Tcs
0000000000000000 T RscHalSetupTCS
0000000000000000 T RscHalToggleePCBTimeOut
0000000000000000 T RscHalToggleTCSCmd
0000000000000000 T RscHalTriggerTCS
0000000000000000 T RscHalUpdateePCBTimeOutThreshold
0000000000000000 T RscHalVersionID
*/
#include "rsc_hal.h"
#include "defs.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
__int64 __fastcall isContextInitialized(_BYTE *a1, unsigned int a2)
{
  __int64 result; // x0

  if ( a2 <= 2 )
  {
    if ( a1 )
    {
      result = 4294967290LL;
      if ( *a1 )
      {
        if ( a1[32 * a2 + 28] )
          return 0LL;
        else
          return 4294967290LL;
      }
    }
    else
    {
      return 4294967290LL;
    }
  }
  else
  {
    rpmh_core_verify(1LL);
    return 0xFFFFFFFFLL;
  }
  return result;
}



__int64 __fastcall RscHalCheckAMCFinishedIRQ(unsigned int a1, int *a2)
{
  unsigned int v4; // w20
  _BYTE *v5; // x19
  int v6; // w1
  __int64 v7; // x0
  int v8; // w0

  if ( !a2 )
    return 4294967291LL;
  v4 = isContextInitialized(GlobalRscHalCtxt, a1);
  if ( v4 )
  {
    rpmh_core_verify(1LL);
    return v4;
  }
  else
  {
    v5 = &GlobalRscHalCtxt[32 * a1];
    v6 = *((_DWORD *)v5 + 6);
    v7 = *((_QWORD *)v5 + 2);
    if ( !v6 )
    {
      v8 = *(_DWORD *)(v7 + 3332) & 0xF;
      goto LABEL_7;
    }
    if ( v6 == 2 )
    {
      v8 = (unsigned __int8)*(_DWORD *)(v7 + 134404);
LABEL_7:
      *a2 = v8;
      return 0LL;
    }
    rpmh_core_verify(1LL);
    return 4294967288LL;
  }
}



__int64 __fastcall RscHalCheckTCSCmdCompletionStatus(
        unsigned int a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        _BYTE *a4)
{
  unsigned int v4; // w20
  _DWORD *v5; // x22
  unsigned int v6; // w1
  unsigned int v7; // w1
  unsigned int v8; // w1
  unsigned int v10; // w21
  int v11; // w1

  v4 = a2;
  v5 = &GlobalRscHalCtxt[32 * a1];
  v6 = v5[8];
  if ( v6 && v6 > v4 )
  {
    v8 = v5[9];
    if ( v8 && v8 > a3 )
    {
      v7 = -5;
      if ( a4 )
      {
        v10 = isContextInitialized(GlobalRscHalCtxt, a1);
        if ( v10 )
        {
          rpmh_core_verify(1LL);
          return v10;
        }
        else
        {
          v11 = v5[6];
          if ( v11 && v11 != 2 )
          {
            rpmh_core_verify(1LL);
            return (unsigned int)-8;
          }
          else
          {
            *a4 = 0;
            return 0;
          }
        }
      }
    }
    else
    {
      rpmh_core_verify(1LL);
      return (unsigned int)-3;
    }
  }
  else
  {
    rpmh_core_verify(1LL);
    return (unsigned int)-2;
  }
  return v7;
}



__int64 __fastcall RscHalCheckTCSCmdIssueStatus(unsigned int a1, unsigned __int8 a2, unsigned __int8 a3, _BYTE *a4)
{
  unsigned int v4; // w20
  _DWORD *v5; // x22
  unsigned int v6; // w1
  unsigned int v7; // w1
  unsigned int v8; // w1
  unsigned int v10; // w21
  int v11; // w1

  v4 = a2;
  v5 = &GlobalRscHalCtxt[32 * a1];
  v6 = v5[8];
  if ( v6 && v6 > v4 )
  {
    v8 = v5[9];
    if ( v8 && v8 > a3 )
    {
      v7 = -5;
      if ( a4 )
      {
        v10 = isContextInitialized(GlobalRscHalCtxt, a1);
        if ( v10 )
        {
          rpmh_core_verify(1LL);
          return v10;
        }
        else
        {
          v11 = v5[6];
          if ( v11 && v11 != 2 )
          {
            rpmh_core_verify(1LL);
            return (unsigned int)-8;
          }
          else
          {
            *a4 = 0;
            return 0;
          }
        }
      }
    }
    else
    {
      rpmh_core_verify(1LL);
      return (unsigned int)-3;
    }
  }
  else
  {
    rpmh_core_verify(1LL);
    return (unsigned int)-2;
  }
  return v7;
}



__int64 __fastcall RscHalCheckTCSCmdTriggerStatus(unsigned int a1, unsigned __int8 a2, unsigned __int8 a3, _BYTE *a4)
{
  unsigned int v4; // w20
  _BYTE *v5; // x22
  unsigned int v6; // w1
  unsigned int v7; // w1
  unsigned int v8; // w1
  int v9; // w19
  unsigned int v11; // w21
  int v12; // w1
  __int64 v13; // x0
  __int64 v14; // x3
  __int64 v15; // x0
  int v16; // w0

  v4 = a2;
  v5 = &GlobalRscHalCtxt[32 * a1];
  v6 = *((_DWORD *)v5 + 8);
  if ( v6 && v6 > v4 )
  {
    v8 = *((_DWORD *)v5 + 9);
    if ( v8 && (v9 = a3, v8 > a3) )
    {
      v7 = -5;
      if ( a4 )
      {
        v11 = isContextInitialized(GlobalRscHalCtxt, a1);
        if ( v11 )
        {
          rpmh_core_verify(1LL);
          return v11;
        }
        v12 = *((_DWORD *)v5 + 6);
        v13 = *((_QWORD *)v5 + 2);
        v14 = v13 + 3388;
        v15 = v13 + 134460;
        if ( v12 )
        {
          if ( v12 != 2 )
          {
            rpmh_core_verify(1LL);
            return (unsigned int)-8;
          }
          v16 = *(_DWORD *)((int)(672 * v4) + (__int64)(20 * v9) + v15);
        }
        else
        {
          v16 = *(_DWORD *)((int)(672 * v4) + (__int64)(20 * v9) + v14);
        }
        v7 = 0;
        *a4 = v16 & 1;
      }
    }
    else
    {
      rpmh_core_verify(1LL);
      return (unsigned int)-3;
    }
  }
  else
  {
    rpmh_core_verify(1LL);
    return (unsigned int)-2;
  }
  return v7;
}



__int64 __fastcall RscHalCheckTCSIdle_HLOS(unsigned int a1)
{
  unsigned int v1; // w19
  unsigned int i; // w0
  unsigned int j; // w0
  unsigned int k; // w0

  v1 = a1;
  if ( !numTcsPerHLOSDrv )
  {
    if ( (unsigned int)rscHalGetNumTcs(0x18200000uLL, a1, &numTcsPerHLOSDrv) )
    {
      rpmh_core_verify(1LL);
      rpmh_core_verify(0LL);
    }
    rpmh_core_verify(1LL);
    rpmh_core_verify(numTcsPerHLOSDrv != 0);
  }
  if ( v1 == 1 )
    goto LABEL_13;
  if ( !v1 )
  {
    v1 = 1;
    for ( i = 0; i < numTcsPerHLOSDrv; i = (unsigned __int8)(i + 1) )
    {
      v1 = *(_BYTE *)(int)(672 * i + 404753688) & 1;
      if ( (*(_DWORD *)(int)(672 * i + 404753688) & 1) == 0 )
        break;
    }
LABEL_13:
    for ( j = 0; j < numTcsPerHLOSDrv; j = (unsigned __int8)(j + 1) )
    {
      v1 = *(_BYTE *)(int)(672 * j + 404819224) & 1;
      if ( (*(_DWORD *)(int)(672 * j + 404819224) & 1) == 0 )
        break;
    }
    goto LABEL_17;
  }
  if ( v1 != 2 )
  {
    v1 = 1;
    goto LABEL_22;
  }
  v1 = 1;
LABEL_17:
  for ( k = 0; k < numTcsPerHLOSDrv; k = (unsigned __int8)(k + 1) )
  {
    v1 = *(_BYTE *)(int)(672 * k + 404884760) & 1;
    if ( (*(_DWORD *)(int)(672 * k + 404884760) & 1) == 0 )
      break;
  }
LABEL_22:
  rpmh_core_verify(1LL);
  rpmh_core_verify(1LL);
  return v1;
}



__int64 __fastcall RscHalClearAMCFinishedIRQ(unsigned int a1, unsigned int a2)
{
  _BYTE *v3; // x20
  unsigned int v4; // w1
  bool v5; // cc
  unsigned int v7; // w19
  int v8; // w1
  __int64 v9; // x0

  v3 = &GlobalRscHalCtxt[32 * a1];
  v4 = *((_DWORD *)v3 + 8);
  if ( v4 )
    v5 = v4 > a2;
  else
    v5 = 0;
  if ( !v5 )
  {
    rpmh_core_verify(1LL);
    return 4294967294LL;
  }
  v7 = isContextInitialized(GlobalRscHalCtxt, a1);
  if ( v7 )
  {
    rpmh_core_verify(1LL);
    return v7;
  }
  else
  {
    v8 = *((_DWORD *)v3 + 6);
    v9 = *((_QWORD *)v3 + 2);
    if ( !v8 )
    {
      *(_DWORD *)(v9 + 3336) = 1 << a2;
      return 0LL;
    }
    if ( v8 == 2 )
    {
      *(_DWORD *)(v9 + 134408) = 1 << a2;
      return 0LL;
    }
    rpmh_core_verify(1LL);
    return 4294967288LL;
  }
}



__int64 __fastcall RscHalClearePCBTimedOut(unsigned int a1)
{
  unsigned int v2; // w21
  _BYTE *v3; // x19

  v2 = isContextInitialized(GlobalRscHalCtxt, a1);
  if ( v2 )
  {
    rpmh_core_verify(1LL);
  }
  else
  {
    v3 = &GlobalRscHalCtxt[32 * a1];
    if ( *((_DWORD *)v3 + 6) )
    {
      v2 = -7;
      rpmh_core_verify(1LL);
    }
    else
    {
      *(_DWORD *)(*((_QWORD *)v3 + 2) + 212LL) = 1;
    }
  }
  return v2;
}



__int64 __fastcall RscHalConfigureCmdCompletion(unsigned int a1, unsigned __int8 a2, __int16 a3)
{
  unsigned int v3; // w19
  _BYTE *v4; // x22
  unsigned int v5; // w1
  int v7; // w21
  unsigned int v8; // w20
  int v9; // w1
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x19

  v3 = a2;
  v4 = &GlobalRscHalCtxt[32 * a1];
  v5 = *((_DWORD *)v4 + 8);
  if ( !v5 || v5 <= v3 )
  {
    rpmh_core_verify(1LL);
    return 4294967294LL;
  }
  LOWORD(v7) = a3;
  v8 = isContextInitialized(GlobalRscHalCtxt, a1);
  if ( v8 )
  {
    rpmh_core_verify(1LL);
    return v8;
  }
  else
  {
    v9 = *((_DWORD *)v4 + 6);
    v10 = *((_QWORD *)v4 + 2);
    if ( !v9 )
    {
      v7 = (unsigned __int16)v7;
      v11 = v10 + 3344;
      v12 = (int)(672 * v3);
      goto LABEL_9;
    }
    if ( v9 == 2 )
    {
      v7 = (unsigned __int16)v7;
      v11 = v10 + 134416;
      v12 = (int)(672 * v3);
LABEL_9:
      *(_DWORD *)(v12 + v11) = v7;
      return 0LL;
    }
    rpmh_core_verify(1LL);
    return 4294967288LL;
  }
}



__int64 __fastcall RscHalConvertAMCtoTCS(unsigned int a1, unsigned __int8 a2)
{
  _BYTE *v3; // x21
  unsigned int v4; // w19
  unsigned int v5; // w1
  unsigned int IsTCSIdle; // w20
  int v8; // w1
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x19
  char v12; // [xsp+4Fh] [xbp+4Fh] BYREF

  v3 = &GlobalRscHalCtxt[32 * a1];
  v4 = a2;
  v12 = 0;
  v5 = *((_DWORD *)v3 + 8);
  if ( !v5 || v5 <= v4 )
  {
    rpmh_core_verify(1LL);
    return 4294967294LL;
  }
  IsTCSIdle = RscHalIsTCSIdle(a1, v4, &v12);
  if ( IsTCSIdle )
    goto LABEL_14;
  if ( !v12 )
  {
    rpmh_core_verify(1LL);
    return 4294967287LL;
  }
  IsTCSIdle = isContextInitialized(GlobalRscHalCtxt, a1);
  if ( IsTCSIdle )
  {
LABEL_14:
    rpmh_core_verify(1LL);
    return IsTCSIdle;
  }
  else
  {
    v8 = *((_DWORD *)v3 + 6);
    v9 = *((_QWORD *)v3 + 2);
    if ( !v8 )
    {
      v10 = v9 + 3348;
      v11 = (int)(672 * v4);
      goto LABEL_12;
    }
    if ( v8 == 2 )
    {
      v10 = v9 + 134420;
      v11 = (int)(672 * v4);
LABEL_12:
      *(_DWORD *)(v11 + v10) &= 0x1000000u;
      return 0LL;
    }
    rpmh_core_verify(1LL);
    return 4294967288LL;
  }
}



__int64 __fastcall RscHalConvertTCStoAMC(unsigned int a1, unsigned __int8 a2)
{
  _BYTE *v3; // x21
  unsigned int v4; // w19
  unsigned int v5; // w1
  unsigned int IsTCSIdle; // w20
  int v8; // w1
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x19
  char v12; // [xsp+4Fh] [xbp+4Fh] BYREF

  v3 = &GlobalRscHalCtxt[32 * a1];
  v4 = a2;
  v12 = 0;
  v5 = *((_DWORD *)v3 + 8);
  if ( !v5 || v5 <= v4 )
  {
    rpmh_core_verify(1LL);
    return 4294967294LL;
  }
  IsTCSIdle = RscHalIsTCSIdle(a1, v4, &v12);
  if ( IsTCSIdle )
    goto LABEL_14;
  if ( !v12 )
  {
    rpmh_core_verify(1LL);
    return 4294967287LL;
  }
  IsTCSIdle = isContextInitialized(GlobalRscHalCtxt, a1);
  if ( IsTCSIdle )
  {
LABEL_14:
    rpmh_core_verify(1LL);
    return IsTCSIdle;
  }
  else
  {
    v8 = *((_DWORD *)v3 + 6);
    v9 = *((_QWORD *)v3 + 2);
    if ( !v8 )
    {
      v10 = v9 + 3348;
      v11 = (int)(672 * v4);
      goto LABEL_12;
    }
    if ( v8 == 2 )
    {
      v10 = v9 + 134420;
      v11 = (int)(672 * v4);
LABEL_12:
      *(_DWORD *)(v11 + v10) = *(_DWORD *)(v11 + v10) & 0x1000000 | 0x10000;
      return 0LL;
    }
    rpmh_core_verify(1LL);
    return 4294967288LL;
  }
}



__int64 __fastcall RscHalDisableAMCFinishedIRQ(unsigned int a1, unsigned int a2)
{
  _BYTE *v2; // x21
  unsigned int v3; // w3
  char v5; // w20
  unsigned int v6; // w19
  int v7; // w1
  __int64 v8; // x0

  v2 = &GlobalRscHalCtxt[32 * a1];
  v3 = *((_DWORD *)v2 + 8);
  if ( v3 <= a2 || v3 == 0 )
    return 4294967294LL;
  v5 = a2;
  v6 = isContextInitialized(GlobalRscHalCtxt, a1);
  if ( v6 )
  {
    rpmh_core_verify(1LL);
    return v6;
  }
  else
  {
    v7 = *((_DWORD *)v2 + 6);
    v8 = *((_QWORD *)v2 + 2);
    if ( !v7 )
    {
      *(_DWORD *)(v8 + 3328) &= 0xF & ~(1 << v5);
      return 0LL;
    }
    if ( v7 == 2 )
    {
      *(_DWORD *)(v8 + 134400) = (unsigned __int8)*(_DWORD *)(v8 + 134400) & ~(1 << v5);
      return 0LL;
    }
    return 4294967288LL;
  }
}



__int64 __fastcall RscHalEnableAMCFinishedIRQ(unsigned int a1, unsigned int a2)
{
  _BYTE *v3; // x20
  unsigned int v4; // w1
  unsigned int v7; // w0
  unsigned int v8; // w19
  int v9; // w0
  __int64 v10; // x2

  v3 = &GlobalRscHalCtxt[32 * a1];
  v4 = *((_DWORD *)v3 + 8);
  if ( v4 <= a2 || v4 == 0 )
  {
    rpmh_core_verify(1LL);
    return 4294967294LL;
  }
  v7 = isContextInitialized(GlobalRscHalCtxt, a1);
  v8 = v7;
  if ( v7 )
  {
    rpmh_core_verify(1LL);
    return v8;
  }
  else
  {
    v9 = *((_DWORD *)v3 + 6);
    v10 = *((_QWORD *)v3 + 2);
    if ( !v9 )
    {
      *(_DWORD *)(v10 + 3328) = *(_DWORD *)(v10 + 3328) & 0xF & ~(1 << a2) | (1 << a2);
      return 0LL;
    }
    if ( v9 == 2 )
    {
      *(_DWORD *)(v10 + 134400) = (unsigned __int8)*(_DWORD *)(v10 + 134400) & ~(1 << a2) | (1 << a2);
      return 0LL;
    }
    rpmh_core_verify(1LL);
    return 4294967288LL;
  }
}



__int64 __fastcall rscHalGetChipsetMappingTable(__int64 a1)
{
  if ( a1 )
  {
    *(_DWORD *)(a1 + 4) = DrvBaseAddressMappingTable_subsystem;
    return 0LL;
  }
  else
  {
    rpmh_core_verify(1LL);
    return 4294967290LL;
  }
}




__int64 __fastcall rscHalGetDrvInfo(__int64 a1)
{
  unsigned int i; // w21
  unsigned int *v4; // x23
  __int64 v5; // x22
  char *v6; // x20
  __int64 v7; // x1
  unsigned __int64 v8; // x0
  int v9; // [xsp+58h] [xbp+58h] BYREF
  int v10; // [xsp+5Ch] [xbp+5Ch] BYREF

  v9 = 0;
  v10 = 0;
  if ( a1 && *(_DWORD *)(a1 + 4) )
  {
    for ( i = 0; ; ++i )
    {
      if ( i >= *(_DWORD *)(a1 + 4) )
        return 0LL;
      v4 = (unsigned int *)off_1D268;
      v5 = 12LL * i;
      v6 = (char *)off_1D268 + v5;
      v7 = a1 + 32LL * *(unsigned int *)((char *)off_1D268 + v5);
      *(_DWORD *)(v7 + 8) = *(_DWORD *)((char *)off_1D268 + v5);
      v8 = *((unsigned int *)v6 + 1);
      *(_QWORD *)(v7 + 16) = v8;
      *(_DWORD *)(v7 + 24) = (unsigned __int8)v6[8];
      if ( (unsigned int)rscHalGetNumTcs(v8, v6[8], &v9) )
        break;
      *(_DWORD *)(a1 + 32LL * v4[3 * i] + 32) = v9;
      if ( (unsigned int)rscHalGetNumCmdsPerTcs(*((unsigned int *)v6 + 1), v6[8], &v10) )
        break;
      *(_DWORD *)(a1 + 32LL * v4[(unsigned __int64)v5 / 4] + 36) = v10;
    }
    rpmh_core_verify(1LL);
    return 4294967288LL;
  }
  else
  {
    rpmh_core_verify(1LL);
    return 4294967291LL;
  }
}



__int64 __fastcall rscHalGetNumCmdsPerTcs(__int64 a1, unsigned __int8 a2, _DWORD *a3)
{
  bool v3; // zf

  if ( a1 )
    v3 = a3 == 0LL;
  else
    v3 = 1;
  if ( v3 )
  {
    rpmh_core_verify(1LL);
    return 4294967291LL;
  }
  else if ( a2 > 2u )
  {
    rpmh_core_verify(1LL);
    return 4294967288LL;
  }
  else
  {
    *a3 = *(_DWORD *)(((unsigned __int64)a2 << 16) + a1 + 12) >> 27;
    return 0LL;
  }
}



__int64 __fastcall rscHalGetNumTcs(unsigned __int64 a1, char a2, _DWORD *a3)
{
  bool v3; // zf

  if ( a1 )
    v3 = a3 == 0LL;
  else
    v3 = 1;
  if ( v3 )
  {
    rpmh_core_verify(1LL);
    return 4294967291LL;
  }
  if ( !a2 )
  {
    LODWORD(a1) = *(_DWORD *)(a1 + 12) & 0x3F;
    goto LABEL_11;
  }
  if ( a2 == 2 )
  {
    a1 = ((unsigned __int64)*(unsigned int *)(a1 + 131084) >> 12) & 0x3F;
LABEL_11:
    *a3 = a1;
    return 0LL;
  }
  rpmh_core_verify(1LL);
  return 4294967288LL;
}



__int64 __fastcall RscHalIsePCBTimedOut(unsigned int a1, _BYTE *a2)
{
  unsigned int v4; // w21
  _BYTE *v5; // x19
  __int64 v6; // x1
  int v7; // w0

  v4 = isContextInitialized(GlobalRscHalCtxt, a1);
  if ( v4 )
  {
    rpmh_core_verify(1LL);
  }
  else if ( a2 )
  {
    v5 = &GlobalRscHalCtxt[32 * a1];
    v6 = *((_QWORD *)v5 + 2);
    if ( *((_DWORD *)v5 + 6) )
      v7 = *(_DWORD *)(v6 + 208 + ((unsigned __int64)(unsigned __int16)*((_DWORD *)v5 + 6) << 16));
    else
      v7 = *(_DWORD *)(v6 + 208);
    *a2 = v7 & 1;
  }
  else
  {
    v4 = -5;
    rpmh_core_verify(1LL);
  }
  return v4;
}



__int64 __fastcall RscHalIsTCSIdle(unsigned int a1, unsigned __int8 a2, _BYTE *a3)
{
  unsigned int v3; // w19
  char *v4; // x21
  unsigned int v5; // w1
  unsigned int v6; // w1
  unsigned int v8; // w20
  int v9; // w1
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x19

  v3 = a2;
  v4 = &GlobalRscHalCtxt[32 * a1];
  v5 = *((_DWORD *)v4 + 8);
  if ( v5 && v5 > v3 )
  {
    v6 = -5;
    if ( a3 )
    {
      v8 = isContextInitialized(GlobalRscHalCtxt, a1);
      if ( v8 )
      {
        rpmh_core_verify(1LL);
        return v8;
      }
      v9 = *((_DWORD *)v4 + 6);
      v10 = *((_QWORD *)v4 + 2);
      if ( v9 )
      {
        if ( v9 != 2 )
        {
          rpmh_core_verify(1LL);
          return (unsigned int)-8;
        }
        v11 = v10 + 134424;
        v12 = (int)(672 * v3);
      }
      else
      {
        v11 = v10 + 3352;
        v12 = (int)(672 * v3);
      }
      v6 = 0;
      *a3 = *(_BYTE *)(v12 + v11) & 1;
    }
  }
  else
  {
    rpmh_core_verify(1LL);
    return (unsigned int)-2;
  }
  return v6;
}



__int64 __fastcall RscHalReadConfig(unsigned int a1, _DWORD *a2, _DWORD *a3)
{
  bool v3; // zf
  unsigned int v8; // w0
  unsigned int v9; // w20
  _BYTE *v10; // x19

  if ( a2 )
    v3 = a3 == 0LL;
  else
    v3 = 1;
  if ( v3 )
  {
    rpmh_core_verify(1LL);
    return 4294967291LL;
  }
  else
  {
    v8 = isContextInitialized(GlobalRscHalCtxt, a1);
    v9 = v8;
    if ( v8 )
    {
      rpmh_core_verify(1LL);
      return v9;
    }
    else
    {
      v10 = &GlobalRscHalCtxt[32 * a1];
      *a2 = *((_DWORD *)v10 + 8);
      *a3 = *((_DWORD *)v10 + 9);
      return 0LL;
    }
  }
}



__int64 __fastcall RscHalReadResponseData(unsigned int a1, unsigned __int8 a2, unsigned __int8 a3, _DWORD *a4)
{
  unsigned int v4; // w20
  _BYTE *v5; // x21
  unsigned int v6; // w1
  unsigned int v7; // w1
  unsigned int v8; // w1
  int v9; // w19
  int v11; // w1
  __int64 v12; // x0
  __int64 v13; // x3
  __int64 v14; // x0
  int v15; // w0

  v4 = a2;
  v5 = &GlobalRscHalCtxt[32 * a1];
  v6 = *((_DWORD *)v5 + 8);
  if ( v6 && v6 > v4 )
  {
    v8 = *((_DWORD *)v5 + 9);
    if ( v8 && (v9 = a3, v8 > a3) )
    {
      v7 = -5;
      if ( a4 )
      {
        if ( (unsigned int)isContextInitialized(GlobalRscHalCtxt, a1) )
        {
          rpmh_core_verify(1LL);
          return (unsigned int)-6;
        }
        v11 = *((_DWORD *)v5 + 6);
        v12 = *((_QWORD *)v5 + 2);
        v13 = v12 + 3392;
        v14 = v12 + 134464;
        if ( v11 )
        {
          if ( v11 != 2 )
          {
            rpmh_core_verify(1LL);
            return (unsigned int)-8;
          }
          v15 = *(_DWORD *)((int)(672 * v4) + (__int64)(20 * v9) + v14);
        }
        else
        {
          v15 = *(_DWORD *)((int)(672 * v4) + (__int64)(20 * v9) + v13);
        }
        v7 = 0;
        *a4 = v15;
      }
    }
    else
    {
      rpmh_core_verify(1LL);
      return (unsigned int)-3;
    }
  }
  else
  {
    rpmh_core_verify(1LL);
    return (unsigned int)-2;
  }
  return v7;
}



__int64 __fastcall RscHalRegisterDrv(unsigned int a1)
{
  __int64 result; // x0
  unsigned int v3; // w2
  _BYTE *v4; // x1

  if ( a1 > 2 )
    goto LABEL_2;
  v3 = 0;
  if ( !GlobalRscHalCtxt[0] )
  {
    *(_DWORD *)&GlobalRscHalCtxt[4] = DrvBaseAddressMappingTable_subsystem;
    result = rscHalGetDrvInfo((__int64)GlobalRscHalCtxt);
    v3 = result;
    if ( (result & 0x80000000) != 0 )
      return result;
    GlobalRscHalCtxt[0] = 1;
  }
  v4 = &GlobalRscHalCtxt[32 * a1];
  if ( !*((_QWORD *)v4 + 2) )
  {
LABEL_2:
    rpmh_core_verify(1LL);
    return 0xFFFFFFFFLL;
  }
  v4[28] = 1;
  return v3;
}



__int64 __fastcall rscHalSetupDrv0Tcs(__int64 a1, unsigned __int8 a2, unsigned __int8 *a3)
{
  unsigned int v4; // w7
  __int64 v5; // x0

  if ( a1 )
  {
    if ( a3 )
    {
      v4 = *((_DWORD *)a3 + 1);
      v5 = 672 * a2 + a1;
      *(_DWORD *)(20LL * *a3 + 3380 + v5) = ((a3[1] & 7) << 16) | (unsigned __int16)*(_DWORD *)(20LL * *a3 + 3380 + v5);
      *(_DWORD *)(20LL * *a3 + 3380 + v5) = *(_DWORD *)(20LL * *a3 + 3380 + v5) & 0x70000 | *((unsigned __int16 *)a3 + 1);
      *(_DWORD *)(20LL * *a3 + 3376 + v5) = *(_DWORD *)(20LL * *a3 + 3376 + v5) & 0x10F | ((v4 < 2) << 16);
      *(_DWORD *)(20LL * *a3 + 3376 + v5) = *(_DWORD *)(20LL * *a3 + 3376 + v5) & 0x1000F | ((v4 != 0) << 8);
      *(_DWORD *)(20LL * *a3 + 3376 + v5) = a3[8] & 0xF | *(_DWORD *)(20LL * *a3 + 3376 + v5) & 0x10100;
      *(_DWORD *)(20LL * *a3 + 3384 + v5) = *((_DWORD *)a3 + 3);
      return 0LL;
    }
    else
    {
      rpmh_core_verify(1LL);
      return 4294967291LL;
    }
  }
  else
  {
    rpmh_core_verify(1LL);
    return 4294967290LL;
  }
}



__int64 __fastcall rscHalSetupDrv2Tcs(__int64 a1, unsigned __int8 a2, unsigned __int8 *a3)
{
  unsigned int v4; // w7
  __int64 v5; // x0

  if ( a1 )
  {
    if ( a3 )
    {
      v4 = *((_DWORD *)a3 + 1);
      v5 = 672 * a2 + a1;
      *(_DWORD *)(20LL * *a3 + 134452 + v5) = ((a3[1] & 7) << 16) | (unsigned __int16)*(_DWORD *)(20LL * *a3
                                                                                                + 134452
                                                                                                + v5);
      *(_DWORD *)(20LL * *a3 + 134452 + v5) = *(_DWORD *)(20LL * *a3 + 134452 + v5) & 0x70000 | *((unsigned __int16 *)a3
                                                                                                + 1);
      *(_DWORD *)(20LL * *a3 + 134448 + v5) = *(_DWORD *)(20LL * *a3 + 134448 + v5) & 0x10F | ((v4 < 2) << 16);
      *(_DWORD *)(20LL * *a3 + 134448 + v5) = *(_DWORD *)(20LL * *a3 + 134448 + v5) & 0x1000F | ((v4 != 0) << 8);
      *(_DWORD *)(20LL * *a3 + 134448 + v5) = a3[8] & 0xF | *(_DWORD *)(20LL * *a3 + 134448 + v5) & 0x10100;
      *(_DWORD *)(20LL * *a3 + 134456 + v5) = *((_DWORD *)a3 + 3);
      return 0LL;
    }
    else
    {
      rpmh_core_verify(1LL);
      return 4294967291LL;
    }
  }
  else
  {
    rpmh_core_verify(1LL);
    return 4294967290LL;
  }
}



__int64 __fastcall RscHalSetupTCS(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w0
  _BYTE *v4; // x21
  unsigned int v5; // w2
  unsigned int v6; // w1
  unsigned int IsTCSIdle; // w19
  unsigned __int8 *v8; // x19
  __int64 v9; // x22
  int v10; // w0
  unsigned int v11; // w21
  unsigned int i; // w21
  char v13; // [xsp+3Fh] [xbp+3Fh] BYREF

  v13 = 0;
  if ( !a1 )
  {
    rpmh_core_verify(1LL);
    return 4294967291LL;
  }
  v3 = *(_DWORD *)a1;
  if ( v3 > 2 )
  {
    rpmh_core_verify(1LL);
    return 0xFFFFFFFFLL;
  }
  v4 = &GlobalRscHalCtxt[32 * v3];
  v5 = *((_DWORD *)v4 + 8);
  if ( !v5 || (v6 = *(unsigned __int8 *)(a1 + 4), v5 <= v6) )
  {
    rpmh_core_verify(1LL);
    return 4294967294LL;
  }
  IsTCSIdle = RscHalIsTCSIdle(v3, v6, &v13);
  if ( IsTCSIdle )
  {
    rpmh_core_verify(1LL);
    return IsTCSIdle;
  }
  if ( !v13 )
  {
    rpmh_core_verify(1LL);
    return 4294967287LL;
  }
  v8 = *(unsigned __int8 **)(a1 + 16);
  result = 4294967291LL;
  v9 = *((_QWORD *)v4 + 2);
  if ( v8 && *(_DWORD *)(a1 + 8) )
  {
    v10 = *((_DWORD *)v4 + 6);
    if ( v10 )
    {
      v11 = 0;
      if ( v10 != 2 )
      {
        rpmh_core_verify(1LL);
        return 4294967288LL;
      }
      while ( v11 < *(_DWORD *)(a1 + 8) )
      {
        result = rscHalSetupDrv2Tcs(v9, *(_BYTE *)(a1 + 4), v8);
        if ( (_DWORD)result )
          return result;
        v8 += 16;
        ++v11;
      }
    }
    else
    {
      for ( i = 0; i < *(_DWORD *)(a1 + 8); ++i )
      {
        result = rscHalSetupDrv0Tcs(v9, *(_BYTE *)(a1 + 4), v8);
        if ( (_DWORD)result )
          return result;
        v8 += 16;
      }
    }
    return 0LL;
  }
  return result;
}



__int64 __fastcall RscHalToggleePCBTimeOut(unsigned int a1, char a2)
{
  unsigned int v4; // w21
  _BYTE *v5; // x19

  v4 = isContextInitialized(GlobalRscHalCtxt, a1);
  if ( v4 )
  {
    rpmh_core_verify(1LL);
  }
  else
  {
    v5 = &GlobalRscHalCtxt[32 * a1];
    if ( *((_DWORD *)v5 + 6) )
    {
      v4 = -7;
      rpmh_core_verify(1LL);
    }
    else
    {
      *(_DWORD *)(*((_QWORD *)v5 + 2) + 216LL) = ((a2 & 1) << 20) | (unsigned __int16)*(_DWORD *)(*((_QWORD *)v5 + 2)
                                                                                                + 216LL);
    }
  }
  return v4;
}



__int64 __fastcall RscHalToggleTCSCmd(unsigned int a1, unsigned __int8 a2, unsigned __int16 a3)
{
  _BYTE *v4; // x22
  unsigned int v5; // w19
  unsigned int v6; // w1
  unsigned int IsTCSIdle; // w20
  int v10; // w1
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x19
  char v14; // [xsp+4Fh] [xbp+4Fh] BYREF

  v4 = &GlobalRscHalCtxt[32 * a1];
  v5 = a2;
  v14 = 0;
  v6 = *((_DWORD *)v4 + 8);
  if ( !v6 || v6 <= v5 )
  {
    rpmh_core_verify(1LL);
    return 4294967294LL;
  }
  IsTCSIdle = RscHalIsTCSIdle(a1, v5, &v14);
  if ( IsTCSIdle )
    goto LABEL_14;
  if ( !v14 )
  {
    rpmh_core_verify(1LL);
    return 4294967287LL;
  }
  IsTCSIdle = isContextInitialized(GlobalRscHalCtxt, a1);
  if ( IsTCSIdle )
  {
LABEL_14:
    rpmh_core_verify(1LL);
    return IsTCSIdle;
  }
  else
  {
    v10 = *((_DWORD *)v4 + 6);
    v11 = *((_QWORD *)v4 + 2);
    if ( !v10 )
    {
      v12 = v11 + 3356;
      v13 = (int)(672 * v5);
      goto LABEL_12;
    }
    if ( v10 == 2 )
    {
      v12 = v11 + 134428;
      v13 = (int)(672 * v5);
LABEL_12:
      *(_DWORD *)(v13 + v12) = a3;
      return 0LL;
    }
    rpmh_core_verify(1LL);
    return 4294967288LL;
  }
}



__int64 __fastcall RscHalTriggerTCS(unsigned int a1, unsigned __int8 a2)
{
  _BYTE *v3; // x21
  unsigned int v4; // w19
  unsigned int v5; // w1
  unsigned int IsTCSIdle; // w20
  int v8; // w1
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x19
  char v12; // [xsp+4Fh] [xbp+4Fh] BYREF

  v3 = &GlobalRscHalCtxt[32 * a1];
  v4 = a2;
  v12 = 0;
  v5 = *((_DWORD *)v3 + 8);
  if ( !v5 || v5 <= v4 )
  {
    rpmh_core_verify(1LL);
    return 4294967294LL;
  }
  IsTCSIdle = RscHalIsTCSIdle(a1, v4, &v12);
  if ( IsTCSIdle )
    goto LABEL_14;
  if ( !v12 )
  {
    rpmh_core_verify(1LL);
    return 4294967287LL;
  }
  IsTCSIdle = isContextInitialized(GlobalRscHalCtxt, a1);
  if ( IsTCSIdle )
  {
LABEL_14:
    rpmh_core_verify(1LL);
    return IsTCSIdle;
  }
  else
  {
    v8 = *((_DWORD *)v3 + 6);
    v9 = *((_QWORD *)v3 + 2);
    if ( !v8 )
    {
      v10 = v9 + 3348;
      v11 = (int)(672 * v4);
      goto LABEL_12;
    }
    if ( v8 == 2 )
    {
      v10 = v9 + 134420;
      v11 = (int)(672 * v4);
LABEL_12:
      *(_DWORD *)(v11 + v10) &= 0x10000u;
      *(_DWORD *)(v11 + v10) = *(_DWORD *)(v11 + v10) & 0x10000 | 0x1000000;
      return 0LL;
    }
    rpmh_core_verify(1LL);
    return 4294967288LL;
  }
}



__int64 __fastcall RscHalUpdateePCBTimeOutThreshold(unsigned int a1, unsigned __int16 a2)
{
  int v3; // w22
  unsigned int v4; // w21
  _BYTE *v5; // x19

  v3 = a2;
  v4 = isContextInitialized(GlobalRscHalCtxt, a1);
  if ( v4 )
  {
    rpmh_core_verify(1LL);
  }
  else
  {
    v5 = &GlobalRscHalCtxt[32 * a1];
    if ( *((_DWORD *)v5 + 6) )
    {
      v4 = -7;
      rpmh_core_verify(1LL);
    }
    else
    {
      *(_DWORD *)(*((_QWORD *)v5 + 2) + 216LL) = *(_DWORD *)(*((_QWORD *)v5 + 2) + 216LL) & 0x100000 | v3;
    }
  }
  return v4;
}



__int64 __fastcall RscHalVersionID(unsigned int a1, int *a2)
{
  unsigned int v5; // w20

  if ( a2 )
  {
    v5 = isContextInitialized(GlobalRscHalCtxt, a1);
    if ( v5 )
    {
      rpmh_core_verify(1LL);
      return v5;
    }
    else
    {
      *a2 = *(_DWORD *)(((unsigned __int64)(unsigned __int16)*(_DWORD *)&GlobalRscHalCtxt[32 * a1 + 24] << 16)
                      + *(_QWORD *)&GlobalRscHalCtxt[32 * a1 + 16]) & 0xFFFFFF;
      return 0LL;
    }
  }
  else
  {
    rpmh_core_verify(1LL);
    return 4294967291LL;
  }
}



