/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
 
#ifndef TRINITY_ARGON2_H
#define TRINITY_ARGON2_H

#include "BigNumber.h"
#include "Define.h"
#include "Optional.h"
#include <string>

namespace Trinity
{
namespace Crypto
{
struct TC_COMMON_API Argon2
{
    static constexpr uint32 HASH_LEN = 16;                    // 128 bits, in bytes
    static constexpr uint32 ENCODED_HASH_LEN = 100;           // in chars
    static constexpr uint32 DEFAULT_ITERATIONS = 10;          // determined by dice roll, guaranteed to be secure (not really)
    static constexpr uint32 DEFAULT_MEMORY_COST = (1u << 17); // 2^17 kibibytes is 2^7 mebibytes is ~100MB
    static constexpr uint32 PARALLELISM = 1;                  // we don't support threaded hashing

    static Optional<std::string> Hash(std::string const& password, BigNumber const& salt, uint32 nIterations = DEFAULT_ITERATIONS, uint32 kibMemoryCost = DEFAULT_MEMORY_COST);
    static bool Verify(std::string const& password, std::string const& hash);
};
}
}

#endif
