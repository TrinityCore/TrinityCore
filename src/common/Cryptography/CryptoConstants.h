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

#ifndef TRINITY_CRYPTO_CONSTANTS_H
#define TRINITY_CRYPTO_CONSTANTS_H

#include "Define.h"

namespace Trinity
{
namespace Crypto
{
    struct Constants
    {
        static constexpr size_t MD5_DIGEST_LENGTH_BYTES = 16;
        static constexpr size_t SHA1_DIGEST_LENGTH_BYTES = 20;
        static constexpr size_t SHA256_DIGEST_LENGTH_BYTES = 32;
        static constexpr size_t SHA512_DIGEST_LENGTH_BYTES = 64;
    };
}
}

#endif
