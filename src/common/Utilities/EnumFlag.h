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

#ifndef EnumFlag_h__
#define EnumFlag_h__

#include <type_traits>

namespace EnumFlag
{
    template<typename T>
    struct IsFlag : std::false_type { };
}

template<typename T, std::enable_if_t<EnumFlag::IsFlag<T>::value, std::nullptr_t> = nullptr>
inline constexpr T operator&(T left, T right)
{
    return static_cast<T>(static_cast<std::underlying_type_t<T>>(left) & static_cast<std::underlying_type_t<T>>(right));
}

template<typename T, std::enable_if_t<EnumFlag::IsFlag<T>::value, std::nullptr_t> = nullptr>
inline constexpr T& operator&=(T& left, T right)
{
    return left = left & right;
}

template<typename T, std::enable_if_t<EnumFlag::IsFlag<T>::value, std::nullptr_t> = nullptr>
inline constexpr T operator|(T left, T right)
{
    return static_cast<T>(static_cast<std::underlying_type_t<T>>(left) | static_cast<std::underlying_type_t<T>>(right));
}

template<typename T, std::enable_if_t<EnumFlag::IsFlag<T>::value, std::nullptr_t> = nullptr>
inline constexpr T& operator|=(T& left, T right)
{
    return left = left | right;
}

template<typename T, std::enable_if_t<EnumFlag::IsFlag<T>::value, std::nullptr_t> = nullptr>
inline constexpr T operator~(T value)
{
    return static_cast<T>(~static_cast<std::underlying_type_t<T>>(value));
}

template<typename T>
class EnumFlag_t
{
    static_assert(EnumFlag::IsFlag<T>::value, "EnumFlag_t must be used only with enums that are specify EnumFlag::IsFlag");

public:
    /*implicit*/ constexpr EnumFlag_t(T value) : _value(value)
    {
    }

    constexpr EnumFlag_t& operator&=(EnumFlag_t right)
    {
        _value &= right._value;
        return *this;
    }

    constexpr friend EnumFlag_t operator&(EnumFlag_t left, EnumFlag_t right)
    {
        return left &= right;
    }

    constexpr EnumFlag_t& operator|=(EnumFlag_t right)
    {
        _value |= right._value;
        return *this;
    }

    constexpr friend EnumFlag_t operator|(EnumFlag_t left, EnumFlag_t right)
    {
        return left |= right;
    }

    constexpr EnumFlag_t operator~() const
    {
        return static_cast<T>(~static_cast<std::underlying_type_t<T>>(_value));
    }

    constexpr void RemoveFlag(EnumFlag_t flag)
    {
        _value &= ~flag._value;
    }

    constexpr bool HasFlag(T flag) const
    {
        using i = std::underlying_type_t<T>;
        return static_cast<i>(_value & flag) != static_cast<i>(0);
    }

    constexpr bool HasAllFlags(T flags) const
    {
        return (_value & flags) == flags;
    }

    constexpr operator T() const
    {
        return _value;
    }

    constexpr std::underlying_type_t<T> AsUnderlyingType() const
    {
        return static_cast<std::underlying_type_t<T>>(_value);
    }

private:
    T _value;
};

#endif // EnumFlag_h__
