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

#ifndef OPENSSL_CRYPTO_H
#define OPENSSL_CRYPTO_H

#include "Define.h"

/**
* A group of functions which setup openssl crypto module to work properly in multithreaded enviroment
* If not setup properly - it will crash
*/
namespace OpenSSLCrypto
{
    /// Needs to be called before threads using openssl are spawned
    TC_COMMON_API void threadsSetup();
    /// Needs to be called after threads using openssl are despawned
    TC_COMMON_API void threadsCleanup();
}

#endif
