/*
0000000000000000 t $x
                 U mem_assign
0000000000000000 T qtiseclib_mem_assign             DONE
*/
#include <stdint.h>
int64_t qtiseclib_mem_assign(int64_t *a1, unsigned int a2, int64_t a3,
    unsigned int a4, int *a5, unsigned int a6)
{
    return mem_assign(a1, a2, a3, a4, a5, a6);
}