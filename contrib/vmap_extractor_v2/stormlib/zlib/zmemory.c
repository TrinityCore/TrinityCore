/* zmemory.c
   Internal memory alloc and memory free functions
 */

#include <malloc.h>

#include "zlib.h"

const char *z_errmsg[10];               // Needed by zlib

voidpf zcalloc(voidpf opaque, uInt items, uInt size)
{
    return (voidpf)calloc(items, size);
}

void zcfree(voidpf opaque, voidpf address)
{
    free(address);
}
