#pragma once

#include <string>
#include <cstdint>
#include "TSString.h"
#include "TSBase.h"

#define INDENT_SIZE 4

inline TSString spaces(int spaces)
{
  std::string lol = "";
  for (int i = 0; i < spaces*INDENT_SIZE; ++i) lol += " ";
  return TSString(lol);
}

inline TSString ToStr(uint8 val, int indent = 0) { return TSString(std::to_string(val)); }
inline TSString ToStr(int8 val, int indent = 0) { return TSString(std::to_string(val)); }
inline TSString ToStr(uint16 val, int indent = 0) { return TSString(std::to_string(val)); }
inline TSString ToStr(int16 val, int indent = 0) { return TSString(std::to_string(val)); }
inline TSString ToStr(uint32 val, int indent = 0) { return TSString(std::to_string(val)); }
inline TSString ToStr(int32 val, int indent = 0) { return TSString(std::to_string(val)); }
inline TSString ToStr(uint64 val, int indent = 0) { return TSString(std::to_string(val)); }
inline TSString ToStr(int64 val, int indent = 0) { return TSString(std::to_string(val)); }
inline TSString ToStr(float val, int indent = 0) { return TSString(std::to_string(val)); }
inline TSString ToStr(double val, int indent = 0) { return TSString(std::to_string(val)); }
inline TSString ToStr(std::string val, int indent = 0) { return TSString(val); }
inline TSString ToStr(TSString val, int indent = 0) { return val; }
template <typename T>
TSString ToStr(T value, int indent = 0) { return value->stringify(indent); }

inline uint8 ToUInt8(TSString value)
{
  return uint8_t(std::stoi(value.std_str()));
}

inline int8 ToInt8(TSString value)
{
  return int8_t(std::stoi(value.std_str()));
}

inline uint16 ToUInt16(TSString value)
{
  return uint16_t(std::stoi(value.std_str()));
}

inline int16 ToInt16(TSString value)
{
  return int16_t(std::stoi(value.std_str()));
}

inline uint32 ToUInt32(TSString value)
{
  return uint32_t(std::stol(value.std_str()));
}

inline int32 ToInt32(TSString value)
{
  return int32_t(std::stoi(value.std_str()));
}

inline uint64 ToUInt64(TSString value)
{
  return uint64_t(std::stoul(value.std_str()));
}

inline int64 ToInt64(TSString value)
{
  return int64_t(std::stol(value.std_str()));
}

inline double ToDouble(TSString value)
{
  return std::stod(value.std_str());
}

inline float ToFloat(TSString value)
{
  return std::stof(value.std_str());
}
