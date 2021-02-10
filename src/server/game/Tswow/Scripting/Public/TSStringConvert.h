#pragma once

#include <string>
#include "TSString.h"
#include "TSBase.h"

template <typename T>
TSString ToStr(T val)
{
    return TSString(std::to_string(val));
}

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