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

#ifndef TRINITY_STRINGCONVERT_H
#define TRINITY_STRINGCONVERT_H

#include "Define.h"
#include "Errors.h"
#include "Optional.h"
#include "Types.h"
#include "Util.h"
#include <charconv>
#include <string>
#include <string_view>
#include <type_traits>

namespace Trinity::Impl::StringConvertImpl
{
    template <typename T, typename = void> struct For
    {
        static_assert(Trinity::dependant_false_v<T>, "Unsupported type used for ToString or StringTo");
        /*
        static Optional<T> FromString(std::string_view str, ...);
        static std::string ToString(T&& val, ...);
        */
    };

    // @todo relax this once proper std::from_chars support exists
    template <typename T>
    struct For<T, std::enable_if_t<std::is_integral_v<T> && !std::is_same_v<T, bool>>>
    {
        static Optional<T> FromString(std::string_view str, int base = 10)
        {
            if (base == 0)
            {
                if (StringEqualI(str.substr(0, 2), "0x"))
                {
                    base = 16;
                    str.remove_prefix(2);
                }
                else if (StringEqualI(str.substr(0, 2), "0b"))
                {
                    base = 2;
                    str.remove_prefix(2);
                }
                else
                    base = 10;

                if (str.empty())
                    return std::nullopt;
            }

            char const* const start = str.data();
            char const* const end = (start + str.length());

            T val;
            std::from_chars_result const res = std::from_chars(start, end, val, base);
            if ((res.ptr == end) && (res.ec == std::errc()))
                return val;
            else
                return std::nullopt;
        }

        static std::string ToString(T val)
        {
            std::string buf(20,'\0'); /* 2^64 is 20 decimal characters, -(2^63) is 20 including the sign */
            char* const start = buf.data();
            char* const end = (start + buf.length());
            std::to_chars_result const res = std::to_chars(start, end, val);
            ASSERT(res.ec == std::errc());
            buf.resize(res.ptr - start);
            return buf;
        }
    };

#ifdef TRINITY_NEED_CHARCONV_WORKAROUND
    /*
        If this is defined, std::from_chars will cause linkage errors for 64-bit types.
        (This is a bug in clang-7.)

        If the clang requirement is bumped to >= clang-8, remove this ifdef block and its
        associated check in cmake/compiler/clang/settings.cmake
    */
    template <>
    struct For<uint64, void>
    {
        static Optional<uint64> FromString(std::string_view str, int base = 10)
        {
            if (str.empty())
                return std::nullopt;
            try
            {
                size_t n;
                uint64 val = std::stoull(std::string(str), &n, base);
                if (n != str.length())
                    return std::nullopt;
                return val;
            }
            catch (...) { return std::nullopt; }
        }

        static std::string ToString(uint64 val)
        {
            return std::to_string(val);
        }
    };

    template <>
    struct For<int64, void>
    {
        static Optional<int64> FromString(std::string_view str, int base = 10)
        {
            try {
                if (str.empty())
                    return std::nullopt;
                size_t n;
                int64 val = std::stoll(std::string(str), &n, base);
                if (n != str.length())
                    return std::nullopt;
                return val;
            }
            catch (...) { return std::nullopt; }
        }

        static std::string ToString(int64 val)
        {
            return std::to_string(val);
        }
    };
#endif

    template <>
    struct For<bool, void>
    {
        static Optional<bool> FromString(std::string_view str)
        {
            if ((str == "1") || StringEqualI(str, "y") || StringEqualI(str, "on") || StringEqualI(str, "yes") || StringEqualI(str, "true"))
                return true;
            if ((str == "0") || StringEqualI(str, "n") || StringEqualI(str, "off") || StringEqualI(str, "no") || StringEqualI(str, "false"))
                return false;
            return std::nullopt;
        }

        static std::string ToString(bool val)
        {
            return (val ? "1" : "0");
        }
    };
}

namespace Trinity
{
    template <typename Result, typename... Params>
    Optional<Result> StringTo(std::string_view str, Params&&... params)
    {
        return Trinity::Impl::StringConvertImpl::For<Result>::FromString(str, std::forward<Params>(params)...);
    }

    template <typename Type, typename... Params>
    std::string ToString(Type&& val, Params&&... params)
    {
        return Trinity::Impl::StringConvertImpl::For<std::decay_t<Type>>::ToString(std::forward<Type>(val), std::forward<Params>(params)...);
    }
}

#endif
