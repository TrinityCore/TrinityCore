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

#ifndef TRINITY_CRYPTORANDOM_H
#define TRINITY_CRYPTORANDOM_H

#include "Define.h"
#include <array>
#include "advstd.h"

namespace Trinity
{
namespace Crypto
{
    void TC_COMMON_API GetRandomBytes(uint8* buf, size_t len);

    template <typename Container>
    void GetRandomBytes(Container& c)
    {
        GetRandomBytes(advstd::data(c), advstd::size(c));
    }

    template <size_t S>
    std::array<uint8, S> GetRandomBytes()
    {
        std::array<uint8, S> arr;
        GetRandomBytes(arr);
        return arr;
    }
}
}

#endif
