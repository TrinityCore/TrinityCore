/*****************************************************************************/
/* crypt_libc.c                           Copyright (c) Ladislav Zezula 2010 */
/*---------------------------------------------------------------------------*/
/* Description:                                                              */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 05.05.10  1.00  Lad  The first version of crypt_libc.c                    */
/*****************************************************************************/

// LibTomCrypt header
#include <stdlib.h>
#include "../headers/tomcrypt.h"

void * LibTomMalloc(size_t n)
{
    return malloc(n);
}

void * LibTomCalloc(size_t n, size_t s)
{
    return calloc(n, s);
}

void * LibTomRealloc(void *p, size_t n)
{
    return realloc(p, n);
}

void LibTomFree(void * p)
{
    free(p);
}

clock_t LibTomClock(void)
{
    return clock();
}

void LibTomQsort(void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *))
{
    qsort(base, nmemb, size, compar);
}
