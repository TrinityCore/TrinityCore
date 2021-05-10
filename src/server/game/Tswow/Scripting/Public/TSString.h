#pragma once

#include <string>
#include <algorithm>

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

template <typename T>
struct TSArray;

template <typename K, typename V>
struct TSDictionary;

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

  TSArray<TSString> split(TSString delim);

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

  friend bool operator==(const TSString& lhs, const TSString& rhs)
  {
    return lhs._value == rhs._value;
  }

  friend bool operator!=(const TSString& lhs, const TSString& rhs)
  {
    return !(lhs._value == rhs._value);
  }
};