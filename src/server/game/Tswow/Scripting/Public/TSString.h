#pragma once

#include <string>
#include <algorithm>
#include "TSArray.h"
#include "TSDictionary.h"

#define JSTR(quote) TSString(quote)

#define STR_OP(cls,conv) friend TSString operator+(const TSString& lhs, cls) \
{                                                                     \
    return TSString(lhs._value + conv);                               \
}                                                                     \
                                                                      \
friend TSString operator+(cls, const TSString& rhs)                   \
{                                                                     \
    return TSString(conv + rhs._value);                               \
}                                                                     \
                                                                      \
friend TSString& operator+=(TSString& lhs, cls)                       \
{                                                                     \
    lhs._value += conv;                                               \
    return lhs;                                                       \
}                                                                     \

typedef wchar_t char_t;

struct TSString {
    std::string _value;
    TSString(std::string _value) {
        this->_value = _value;
    }

    TSString() {

    }

    constexpr TSString* operator->()
    {
        return this;
    }

    auto c_str() {
        return this->_value.c_str();
    }

    auto std_str() {
        return this->_value;
    }

    bool operator<(const TSString& str) const {
        return _value < str._value;
    }

    friend std::ostream& operator<<(std::ostream& os, TSString val)
    {
        return os << val._value;
    }

    int length() {
        return _value.size();
    }

    TSString substring(uint32_t begin, uint32_t end)
    {
        if (end == get_length())
        {
            return TSString(_value.substr(begin));
        }
        else
        {
            return TSString(_value.substr(begin, end - begin));
        }
    }

    TSString operator[](int n) {
        return TSString(std::string(10, _value[n]));
    }

    TSString substr(int start, int end = -1)
    {
        return substring(start, end);
    }

    TSString toUpperCase()
    {
        std::string cpy = std::string(_value);
        std::transform(cpy.begin(), cpy.end(), cpy.begin(), ::toupper);
        return TSString(cpy);
    }

    TSString toLowerCase()
    {
        std::string cpy = std::string(_value);
        std::transform(cpy.begin(), cpy.end(), cpy.begin(), ::tolower);
        return TSString(cpy);
    }

    bool startsWith(TSString str)
    {
        return startsWith(str._value);
    }

    bool startsWith(std::string str)
    {
        return _value.rfind(str, 0) == 0;
    }

    bool endsWith(std::string str)
    {
        if (str.size() > _value.size()) return false;
        return std::equal(str.rbegin(), str.rend(), _value.rbegin());
    }

    bool includes(TSString str)
    {
        return includes(str._value);
    }

    bool includes(std::string str)
    {
        return _value.find(str) != std::string::npos;
    }

    TSString replace(const TSString& from, const TSString& to) {
        size_t start_pos = _value.find(from._value);
        TSString str = TSString(_value);
        if (start_pos == std::string::npos)
            return str;
        str._value.replace(start_pos, from._value.length(), to._value);
        return str;
    }

    TSString replaceAll(const TSString& from, const TSString& to) {
        TSString str = TSString(_value);
        if (from._value.empty())
            return str;
        size_t start_pos = 0;
        while ((start_pos = str._value.find(from._value, start_pos)) != std::string::npos) {
            str._value.replace(start_pos, from._value.length(), to._value);
            start_pos += to._value.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
        }
        return str;
    }

    int32_t indexOf(TSString str)
    {
        return indexOf(str._value);
    }

    int32_t indexOf(std::string str)
    {
        size_t value = _value.find(str);
        if (value == std::string::npos)
        {
            return -1;
        }
        else
        {
            return (int32_t)value;
        }
    }

    int32_t lastIndexOf(std::string str)
    {
        size_t value = _value.rfind(str);
        if (value == std::string::npos)
        {
            return -1;
        }
        else
        {
            return (int32_t)value;
        }
    }

    TSArray<TSString> split(TSString delim)
    {
        TSArray<TSString> arr;
        auto start = 0U;
        auto end = _value.find(delim._value);
        while (end != std::string::npos)
        {
            if (end != start) {
                arr.push(_value.substr(start, end - start));
            }
            start = end + delim.get_length();
            end = _value.find(delim._value, start);
        }

        end = get_length();
        if (start != end) {
            arr.push(_value.substr(start, end - start));
        }

        return arr;
    }

    uint32_t get_length()
    {
        return _value.length();
    }

    TSString charAt(int index)
    {
        return substring(index, index + 1);
    }

    TSString operator+(TSString rhs)
    {
        return TSString(_value + rhs._value);
    }

    bool operator==(TSString rhs)
    {
        return _value == rhs._value;
    }


    TSString& operator+=(const TSString rhs)
    {
        _value += rhs._value;
        return *this;
    }


    operator const char* () { return _value.c_str(); }
    operator std::string() const { return _value; }

    STR_OP(const uint8_t v, std::to_string(v))
    STR_OP(const int8_t v, std::to_string(v))
    STR_OP(const uint16_t v, std::to_string(v))
    STR_OP(const int16_t v, std::to_string(v))
    STR_OP(const uint32_t v, std::to_string(v))
    STR_OP(const int32_t v, std::to_string(v))
    STR_OP(const uint64_t v, std::to_string(v))
    STR_OP(const int64_t v, std::to_string(v))
    STR_OP(const float v, std::to_string(v))
    STR_OP(const double v, std::to_string(v))
    STR_OP(const std::string v, v)
    STR_OP(const char* v, v)

    template <typename T>
    friend TSString& operator+=(TSString& lhs, TSArray<T>* arr)
    {
        lhs._value += str(*arr)._value;
        return lhs;
    }

    template <typename T>
    friend TSString operator+(const TSString& lhs, const TSArray<T>* arr)
    {
        return TSString(lhs._value + str(*arr)._value);
    }

    template <typename T>
    friend TSString operator+(const TSArray<T>* arr, const TSString& rhs)
    {
        return TSString(str(*arr)._value + rhs._value);
    }

    template <typename K, typename V>
    friend TSString& operator+=(TSString& lhs, TSDictionary<K, V>* map)
    {
        lhs._value += str(*map)._value;
        return lhs;
    }

    template <typename K, typename V>
    friend TSString operator+(const TSString& lhs, const TSDictionary<K, V>* map)
    {
        return TSString(lhs._value + str(*map)._value);
    }

    template <typename K, typename V>
    friend TSString operator+(const TSDictionary<K, V>* arr, const TSString& rhs)
    {
        return TSString(str(*arr)._value + rhs._value);
    }

    template <typename T>
    friend TSString& operator+=(TSString& lhs, TSArray<T> arr)
    {
        lhs._value += str(arr)._value;
        return lhs;
    }

    template <typename T>
    friend TSString operator+(const TSString& lhs, const TSArray<T> arr)
    {
        return TSString(lhs._value + str(arr)._value);
    }

    template <typename T>
    friend TSString operator+(const TSArray<T> arr, const TSString& rhs)
    {
        return TSString(str(arr)._value + rhs._value);
    }

    template <typename K, typename V>
    friend TSString& operator+=(TSString& lhs, TSDictionary<K, V> map)
    {
        lhs._value += str(map)._value;
        return lhs;
    }

    template <typename K, typename V>
    friend TSString operator+(const TSString& lhs, const TSDictionary<K, V> map)
    {
        return TSString(lhs._value + str(map)._value);
    }

    template <typename K, typename V>
    friend TSString operator+(const TSDictionary<K, V> arr, const TSString& rhs)
    {
        return TSString(str(arr)._value + rhs._value);
    }

    friend bool operator==(const TSString& lhs, const TSString& rhs)
    {
        return lhs._value == rhs._value;
    }

    friend bool operator!=(const TSString& lhs, const TSString& rhs)
    {
        return !(lhs._value == rhs._value);
    }

    template <typename T>
    friend TSString str(TSArray<T> arr)
    {
        TSString str = JSTR("[");
        for (int i = 0; i < arr.get_length(); ++i)
        {
            if (i < arr.get_length() - 1)
            {
                str += arr[i];
            }
            else
            {
                str += arr[i] + JSTR(",");
            }
        }
        return str + JSTR("]");
    }

    template <typename K, typename V>
    friend TSString str(TSDictionary<K, V> dict)
    {
        TSString str = JSTR("{");
        if (dict.get_length() > 0)
        {
            str = str + JSTR("\n");
        }

        int ctr = 0;
        for (auto& e : dict._map)
        {
            if (++ctr >= dict.get_length())
            {
                str += JSTR("    ") + e.first + JSTR(":") + e.second + JSTR("\n");
            }
            else
            {
                str += JSTR("    ") + e.first + JSTR(":") + e.second + JSTR(",\n");
            }
        }
        return str + JSTR("}");
    }
};