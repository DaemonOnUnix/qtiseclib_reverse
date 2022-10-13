#pragma once
#include "defs.h"
void cpuss_dmb();
void cpuss_dsb();
void cpuss_isb();
unsigned __int64 cpuss_read_isr();
