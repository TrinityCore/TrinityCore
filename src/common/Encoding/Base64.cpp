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

#include "Base64.h"
#include "BaseEncoding.h"
#include "Errors.h"

struct B64Impl
{
    static constexpr std::size_t BITS_PER_CHAR = 6;

    static constexpr char PADDING = '=';
    static constexpr char Encode(uint8 v)
    {
        ASSERT(v < 0x40);
        if (v < 26)  return 'A' + v;
        if (v < 52)  return 'a' + (v - 26);
        if (v < 62)  return '0' + (v - 52);
        if (v == 62) return '+';
        else         return '/';
    }

    static constexpr uint8 DECODE_ERROR = 0xff;
    static constexpr uint8 Decode(uint8 v)
    {
        if (('A' <= v) && (v <= 'Z')) return (v - 'A');
        if (('a' <= v) && (v <= 'z')) return (v - 'a') + 26;
        if (('0' <= v) && (v <= '9')) return (v - '0') + 52;
        if (v == '+') return 62;
        if (v == '/') return 63;
        return DECODE_ERROR;
    }
};

/*static*/ std::string Trinity::Encoding::Base64::Encode(std::vector<uint8> const& data)
{
    return Trinity::Impl::GenericBaseEncoding<B64Impl>::Encode(data);
}

/*static*/ Optional<std::vector<uint8>> Trinity::Encoding::Base64::Decode(std::string_view data)
{
    return Trinity::Impl::GenericBaseEncoding<B64Impl>::Decode(data);
}
