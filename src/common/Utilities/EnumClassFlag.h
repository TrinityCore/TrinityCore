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

#ifndef EnumClassFlag_h__
#define EnumClassFlag_h__

#include <type_traits>

template<typename T>
class EnumClassFlag
{
    static_assert(std::is_enum<T>::value, "EnumClassFlag must be used only with enums");

public:
    /*implicit*/ EnumClassFlag(T value) : _value(value) { }

    EnumClassFlag& operator&=(EnumClassFlag right)
    {
        _value = static_cast<T>(static_cast<std::underlying_type_t<T>>(_value) & static_cast<std::underlying_type_t<T>>(right._value));
        return *this;
    }

    friend EnumClassFlag operator&(EnumClassFlag left, EnumClassFlag right)
    {
        return left &= right;
    }

    EnumClassFlag& operator|=(EnumClassFlag right)
    {
        _value = static_cast<T>(static_cast<std::underlying_type_t<T>>(_value) | static_cast<std::underlying_type_t<T>>(right._value));
        return *this;
    }

    friend EnumClassFlag operator|(EnumClassFlag left, EnumClassFlag right)
    {
        return left |= right;
    }

    EnumClassFlag operator~() const
    {
        return static_cast<T>(~static_cast<std::underlying_type_t<T>>(_value));
    }

    void RemoveFlag(EnumClassFlag flag)
    {
        _value = static_cast<T>(static_cast<std::underlying_type_t<T>>(_value) & ~static_cast<std::underlying_type_t<T>>(flag._value));
    }

    bool HasFlag(T flag) const
    {
        return (static_cast<std::underlying_type_t<T>>(_value) & static_cast<std::underlying_type_t<T>>(flag)) != 0;
    }

    operator T() const
    {
        return _value;
    }

    std::underlying_type_t<T> AsUnderlyingType() const
    {
        return static_cast<std::underlying_type_t<T>>(_value);
    }

private:
    T _value;
};

#endif // EnumClassFlag_h__
