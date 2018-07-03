/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include <OpenSSLCrypto.h>
#include <openssl/crypto.h>
#include <vector>
#include <thread>
#include <mutex>

std::vector<std::mutex*> cryptoLocks;

static void lockingCallback(int mode, int type, const char* /*file*/, int /*line*/)
{
    if (mode & CRYPTO_LOCK)
        cryptoLocks[type]->lock();
    else
        cryptoLocks[type]->unlock();
}

static void threadIdCallback(CRYPTO_THREADID * id)
{
    CRYPTO_THREADID_set_numeric(id, std::hash<std::thread::id>()(std::this_thread::get_id()));
}

void OpenSSLCrypto::threadsSetup()
{
    cryptoLocks.resize(CRYPTO_num_locks());
    for(int i = 0 ; i < CRYPTO_num_locks(); ++i)
    {
        cryptoLocks[i] = new std::mutex;
    }
    CRYPTO_THREADID_set_callback(threadIdCallback);
    CRYPTO_set_locking_callback(lockingCallback);
}

void OpenSSLCrypto::threadsCleanup()
{
    CRYPTO_set_locking_callback(NULL);
    CRYPTO_THREADID_set_callback(NULL);
    for(int i = 0 ; i < CRYPTO_num_locks(); ++i)
    {
        delete cryptoLocks[i];
    }
    cryptoLocks.resize(0);
}
