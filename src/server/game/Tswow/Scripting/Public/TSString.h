/*
 * This file is part of tswow (https://github.com/tswow/).
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 * 
 * This program is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once

#include <string>

#define JSTR(quote) TSString(quote)

typedef wchar_t char_t;

class TSString {
public:
    std::string _value;
    TSString(std::string _value) {
        this->_value = _value;
    }

    TSString() {

    }

    auto c_str() {
        return this->_value.c_str();
    }

    auto std_str() {
        return this->_value;
    }

    friend std::ostream& operator<<(std::ostream& os, TSString val)
    {
        return os << val._value;
    }

    inline operator const char* ()
    {
        return _value.c_str();
    }

    int length() {
        return _value.size();
    }

    template <typename N>
    TSString substring(N begin, N end)
    {
        return _value.substr(begin, end - begin);
    }

    TSString operator[](int n) {
        return TSString(std::string(10, _value[n]));
    }

    TSString operator+(TSString str) const {
        return TSString(_value + str._value);
    }

    bool operator<(const TSString& str) const {
        return _value < str._value;
    }
};