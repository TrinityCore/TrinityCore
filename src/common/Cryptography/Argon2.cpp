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

#include "Argon2.h"
#include <argon2/argon2.h>

/*static*/ Optional<std::string> Trinity::Crypto::Argon2::Hash(std::string const& password, BigNumber const& salt, uint32 nIterations, uint32 kibMemoryCost)
{
    char buf[ENCODED_HASH_LEN];
    int status = argon2id_hash_encoded(
        nIterations,
        kibMemoryCost,
        PARALLELISM,
        password.c_str(), password.length(),
        salt.AsByteArray().get(), salt.GetNumBytes(),
        HASH_LEN, buf, ENCODED_HASH_LEN
    );

    if (status == ARGON2_OK)
        return std::string(buf);

    return {};
}

/*static*/ bool Trinity::Crypto::Argon2::Verify(std::string const& password, std::string const& hash)
{
    int status = argon2id_verify(hash.c_str(), password.c_str(), password.length());
    return (status == ARGON2_OK);
}
