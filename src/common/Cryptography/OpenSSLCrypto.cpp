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

#include "OpenSSLCrypto.h"
#include <openssl/crypto.h>
#include <openssl/provider.h>

OSSL_PROVIDER* LegacyProvider;

void OpenSSLCrypto::threadsSetup([[maybe_unused]] boost::filesystem::path const& providerModulePath)
{
#ifdef VALGRIND
    ValgrindRandomSetup();
#endif

#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
    OSSL_PROVIDER_set_default_search_path(nullptr, providerModulePath.string().c_str());
#endif
    LegacyProvider = OSSL_PROVIDER_try_load(nullptr, "legacy", 1);
}

void OpenSSLCrypto::threadsCleanup()
{
    OSSL_PROVIDER_unload(LegacyProvider);
    OSSL_PROVIDER_set_default_search_path(nullptr, nullptr);
}

#ifdef VALGRIND
#include <openssl/rand.h>

RAND_METHOD const* default_rand;

static int Valgrind_RAND_seed(const void* buf, int num)
{
    VALGRIND_DISCARD(VALGRIND_MAKE_MEM_DEFINED(buf, num));
    return default_rand->seed(buf, num);
}

static int Valgrind_RAND_bytes(unsigned char* buf, int num)
{
    int ret = default_rand->bytes(buf, num);
    VALGRIND_DISCARD(VALGRIND_MAKE_MEM_DEFINED(buf, num));
    return ret;
}

static void Valgrind_RAND_cleanup(void)
{
    default_rand->cleanup();
}

static int Valgrind_RAND_add(const void* buf, int num, double randomness)
{
    VALGRIND_DISCARD(VALGRIND_MAKE_MEM_DEFINED(buf, num));
    return default_rand->add(buf, num, randomness);
}

static int Valgrind_RAND_pseudorand(unsigned char* buf, int num)
{
    int ret = default_rand->pseudorand(buf, num);
    VALGRIND_DISCARD(VALGRIND_MAKE_MEM_DEFINED(buf, num));
    return ret;
}

static int Valgrind_RAND_status(void)
{
    return default_rand->status();
}

static RAND_METHOD valgrind_rand;

void ValgrindRandomSetup()
{
    memset(&valgrind_rand, 0, sizeof(RAND_METHOD));
    default_rand = RAND_get_rand_method();
    if (default_rand->seed)
        valgrind_rand.seed = &Valgrind_RAND_seed;
    if (default_rand->bytes)
        valgrind_rand.bytes = &Valgrind_RAND_bytes;
    if (default_rand->cleanup)
        valgrind_rand.cleanup = &Valgrind_RAND_cleanup;
    if (default_rand->add)
        valgrind_rand.add = &Valgrind_RAND_add;
    if (default_rand->pseudorand)
        valgrind_rand.pseudorand = &Valgrind_RAND_pseudorand;
    if (default_rand->status)
        valgrind_rand.status = &Valgrind_RAND_status;
    RAND_set_rand_method(&valgrind_rand);
}
#endif
