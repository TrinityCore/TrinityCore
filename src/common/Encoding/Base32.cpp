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

#include "Base32.h"
#include "BaseEncoding.h"
#include "Errors.h"

struct B32Impl
{
    static constexpr std::size_t BITS_PER_CHAR = 5;

    static constexpr char PADDING = '=';
    static constexpr char Encode(uint8 v)
    {
        ASSERT(v < 0x20);
        if (v < 26) return 'A'+v;
        else        return '2' + (v-26);
    }

    static constexpr uint8 DECODE_ERROR = 0xff;
    static constexpr uint8 Decode(uint8 v)
    {
        if (v == '0') return Decode('O');
        if (v == '1') return Decode('l');
        if (v == '8') return Decode('B');
        if (('A' <= v) && (v <= 'Z')) return (v-'A');
        if (('a' <= v) && (v <= 'z')) return (v-'a');
        if (('2' <= v) && (v <= '7')) return (v-'2')+26;
        return DECODE_ERROR;
    }
};

/*static*/ std::string Trinity::Encoding::Base32::Encode(std::vector<uint8> const& data)
{
    return Trinity::Impl::GenericBaseEncoding<B32Impl>::Encode(data);
}

/*static*/ Optional<std::vector<uint8>> Trinity::Encoding::Base32::Decode(std::string const& data)
{
    return Trinity::Impl::GenericBaseEncoding<B32Impl>::Decode(data);
}
