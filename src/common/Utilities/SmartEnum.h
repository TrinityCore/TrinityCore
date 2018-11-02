/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef TRINITY_SMARTENUM_H
#define TRINITY_SMARTENUM_H

#include "smart_enum.hpp"

struct EnumText
{
    constexpr EnumText(char const* t = nullptr, char const* d = nullptr) : Title(t), Description(d ? d : t) {}
    // Human-readable title of the value
    char const* const Title;
    // Human-readable description of the value
    char const* const Description;

    protected:
        constexpr EnumText(char const* n, EnumText e) : Title(e.Title ? e.Title : n), Description(e.Description ? e.Description : Title) {}
};

struct FullEnumText : public EnumText
{
    constexpr FullEnumText(char const* constant, EnumText e) : EnumText(constant, e), Constant(constant) {}
    // Enum constant of the value
    char const* const Constant;
};

template <typename E>
class EnumUtils
{
    public:
        static constexpr auto Begin() { return smart_enum::begin<E>(); }
        static constexpr auto End() { return smart_enum::end<E>(); }
        static constexpr auto Iterate() { return smart_enum::range<E>(); }
        static constexpr FullEnumText ToString(E value)
        {
            return { smart_enum::to_string<E>(value), smart_enum::data<E>(value) };
        }
        static constexpr char const* ToConstant(E value) { return ToString(value).Constant; }
        static constexpr char const* ToTitle(E value) { return ToString(value).Title; }
        static constexpr char const* ToDescription(E value) { return ToString(value).Description; }
};

#define SMART_ENUM_BOUND(type, name) static constexpr type name = type(smart_enum::value_of<type>(smart_enum::count<type>()-1)+1);
#define SMART_ENUM_BOUND_AFTER(type, name, entry) static constexpr type name = type(entry + 1);

#endif
