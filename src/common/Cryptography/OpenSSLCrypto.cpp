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

#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER < 0x1010000fL
#include <vector>
#include <thread>
#include <mutex>

std::vector<std::mutex*> cryptoLocks;
void ValgrindRandomSetup();

static void lockingCallback(int mode, int type, char const* /*file*/, int /*line*/)
{
    if (mode & CRYPTO_LOCK)
        cryptoLocks[type]->lock();
    else
        cryptoLocks[type]->unlock();
}

static void threadIdCallback(CRYPTO_THREADID * id)
{
    (void)id;
    CRYPTO_THREADID_set_numeric(id, std::hash<std::thread::id>()(std::this_thread::get_id()));
}

void OpenSSLCrypto::threadsSetup()
{
#ifdef VALGRIND
    ValgrindRandomSetup();
#endif

    cryptoLocks.resize(CRYPTO_num_locks());
    for(int i = 0 ; i < CRYPTO_num_locks(); ++i)
    {
        cryptoLocks[i] = new std::mutex();
    }

    (void)&threadIdCallback;
    CRYPTO_THREADID_set_callback(threadIdCallback);

    (void)&lockingCallback;
    CRYPTO_set_locking_callback(lockingCallback);
}

void OpenSSLCrypto::threadsCleanup()
{
    CRYPTO_set_locking_callback(nullptr);
    CRYPTO_THREADID_set_callback(nullptr);
    for(int i = 0 ; i < CRYPTO_num_locks(); ++i)
    {
        delete cryptoLocks[i];
    }
    cryptoLocks.resize(0);
}
#endif

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
