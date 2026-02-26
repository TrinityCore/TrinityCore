/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* This is a custom TC utility to detect things provided by orignal autoconf jemalloc build system */

#include <math.h>
#include <stdint.h>
#include <stdio.h>

#if defined(_M_IX86) || defined(_M_AMD64) || defined(__i386__) || defined(__x86_64__)

#ifdef _WIN32
#include <intrin.h>
#include <Windows.h>
#else
#include <cpuid.h>
#include <unistd.h>
#endif

static uint32_t GetNumSignificantVirtualAddressBits(void)
{
    uint32_t r[4];
    uint32_t eax_in = 0x80000008U;
    uint32_t eax_out;
    uint32_t vaddr;
#ifdef _WIN32
    __cpuid((int *)r, (int)eax_in);
#else
    __cpuid(eax_in, r[0], r[1], r[2], r[3]);
#endif
    eax_out = r[0];
    vaddr = ((eax_out & 0x0000ff00U) >> 8);
    if (vaddr > (sizeof(void*) << 3))
        vaddr = sizeof(void*) << 3;
    return vaddr;
}

#else

static uint32_t GetNumSignificantVirtualAddressBits(void)
{
    return sizeof(void*) == 8 ? 48 : 32;
}

#endif

static uint32_t GetPageSize(void)
{
#ifdef _WIN32
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    return si.dwPageSize;
#else
    int result;
    result = sysconf(_SC_PAGESIZE);
    if (result == -1) {
        return 0x1000;
    }
    return result;
#endif
}

static uint32_t log2i(uint32_t val)
{
#ifdef _WIN32
    unsigned long i;
    if (_BitScanForward(&i, val)) {
        return i;
    }
    return 0;
#else
    return __builtin_ffsl(val) - 1;
#endif
}

int main(void)
{
    printf("{ "
        "\"LG_SIZEOF_PTR\": %u, "
        "\"LG_SIZEOF_INT\": %u, "
        "\"LG_SIZEOF_LONG\": %u, "
        "\"LG_SIZEOF_LONG_LONG\": %u, "
        "\"LG_SIZEOF_INTMAX_T\": %u, "
        "\"LG_VADDR\": %u, "
        "\"LG_PAGE\": %u "
        " }",
        log2i(sizeof(void*)),
        log2i(sizeof(int)),
        log2i(sizeof(long)),
        log2i(sizeof(long long)),
        log2i(sizeof(intmax_t)),
        GetNumSignificantVirtualAddressBits(),
        log2i(GetPageSize())
        );
    return 0;
}
