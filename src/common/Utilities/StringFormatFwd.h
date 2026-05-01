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

#ifndef TRINITYCORE_STRING_FORMAT_FWD_H
#define TRINITYCORE_STRING_FORMAT_FWD_H

#include <stdexcept>

namespace fmt
{
inline namespace v12
{
template <typename T, typename Char, typename Enable>
struct formatter;
}
}

namespace Trinity
{
struct NoArgFormatterBase
{
    template <typename ParseContext>
    constexpr typename ParseContext::iterator parse(ParseContext& ctx)
    {
        auto begin = ctx.begin(), end = ctx.end();
        if (begin == end)
            return begin;

        if (*begin != '}')
            throw std::invalid_argument("invalid type specifier");

        return begin;
    }
};
}

#endif // TRINITYCORE_STRING_FORMAT_FWD_H
