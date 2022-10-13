#pragma once
#include "defs.h"
__int64 __fastcall ACQCGetxPUType(__int64 a1);
__int64 __fastcall XpuEnableDomains(int **a1);
__int64 __fastcall XpuLockDownAssetDynamically(__int64 a1, unsigned __int8 a2, int a3, int a4, int a5, int a6);
__int64 __fastcall XpuLockDownAssets(__int64 a1, unsigned __int8 a2);
__int64 __fastcall XpuMasterMPuInit(__int64 a1, unsigned int a2);
__int64 __fastcall XpuProgramMPUPartitions(_QWORD *a1, int a2);
__int64 __fastcall XpuProgramMPUPartitionsDynamicPerm(_QWORD *a1, int a2, int a3, int a4);
__int64 __fastcall XpuProgramMPUPartitionsPerm(_QWORD *a1, int a2);
__int64 __fastcall XpuSetRGOwnership(_QWORD *a1, int a2);
