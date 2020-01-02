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

#ifndef TRINITY_TOTP_H
#define TRINITY_TOTP_H

#include "Define.h"
#include <ctime>
#include <vector>

namespace Trinity
{
namespace Crypto
{
struct TC_COMMON_API TOTP
{
    static constexpr std::size_t RECOMMENDED_SECRET_LENGTH = 20;
    using Secret = std::vector<uint8>;

    static uint32 GenerateToken(Secret const& key, time_t timestamp);
    static bool ValidateToken(Secret const& key, uint32 token);
};
}
}

#endif
