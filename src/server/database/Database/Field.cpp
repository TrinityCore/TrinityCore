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

#include "Field.h"
#include "Errors.h"
#include "FieldValueConverter.h"
#include <cstring>

Field::Field() : _value(nullptr), _length(0), _meta(nullptr)
{
}

Field::~Field() = default;

uint8 Field::GetUInt8() const noexcept
{
    if (_value)
        return _meta->Converter->GetUInt8(_value, _length, _meta);
    return 0;
}

int8 Field::GetInt8() const noexcept
{
    if (_value)
        return _meta->Converter->GetInt8(_value, _length, _meta);
    return 0;
}

uint16 Field::GetUInt16() const noexcept
{
    if (_value)
        return _meta->Converter->GetUInt16(_value, _length, _meta);
    return 0;
}

int16 Field::GetInt16() const noexcept
{
    if (_value)
        return _meta->Converter->GetInt16(_value, _length, _meta);
    return 0;
}

uint32 Field::GetUInt32() const noexcept
{
    if (_value)
        return _meta->Converter->GetUInt32(_value, _length, _meta);
    return 0;
}

int32 Field::GetInt32() const noexcept
{
    if (_value)
        return _meta->Converter->GetInt32(_value, _length, _meta);
    return 0;
}

uint64 Field::GetUInt64() const noexcept
{
    if (_value)
        return _meta->Converter->GetUInt64(_value, _length, _meta);
    return 0;
}

int64 Field::GetInt64() const noexcept
{
    if (_value)
        return _meta->Converter->GetInt64(_value, _length, _meta);
    return 0;
}

float Field::GetFloat() const noexcept
{
    if (_value)
        return _meta->Converter->GetFloat(_value, _length, _meta);
    return 0.0f;
}

double Field::GetDouble() const noexcept
{
    if (_value)
        return _meta->Converter->GetDouble(_value, _length, _meta);
    return 0.0;
}

SystemTimePoint Field::GetDate() const noexcept
{
    if (_value)
        return _meta->Converter->GetDate(_value, _length, _meta);
    return SystemTimePoint::min();
}

char const* Field::GetCString() const noexcept
{
    if (_value)
        return _meta->Converter->GetCString(_value, _length, _meta);
    return nullptr;
}

std::string Field::GetString() const noexcept
{
    return std::string(GetStringView());
}

std::string_view Field::GetStringView() const noexcept
{
    if (char const* string = GetCString())
        return { string, _length };
    return {};
}

std::vector<uint8> Field::GetBinary() const noexcept
{
    std::span<uint8 const> binary = GetBinaryView();
    return { binary.begin(), binary.end() };
}

std::span<uint8 const> Field::GetBinaryView() const noexcept
{
    return { reinterpret_cast<uint8 const*>(_value), _length };
}

Optional<uint8> Field::GetUInt8OrNull() const noexcept
{
    if (_value)
        return _meta->Converter->GetUInt8(_value, _length, _meta);
    return {};
}

Optional<int8> Field::GetInt8OrNull() const noexcept
{
    if (_value)
        return _meta->Converter->GetInt8(_value, _length, _meta);
    return {};
}

Optional<uint16> Field::GetUInt16OrNull() const noexcept
{
    if (_value)
        return _meta->Converter->GetUInt16(_value, _length, _meta);
    return {};
}

Optional<int16> Field::GetInt16OrNull() const noexcept
{
    if (_value)
        return _meta->Converter->GetInt16(_value, _length, _meta);
    return {};
}

Optional<uint32> Field::GetUInt32OrNull() const noexcept
{
    if (_value)
        return _meta->Converter->GetUInt32(_value, _length, _meta);
    return {};
}

Optional<int32> Field::GetInt32OrNull() const noexcept
{
    if (_value)
        return _meta->Converter->GetInt32(_value, _length, _meta);
    return {};
}

Optional<uint64> Field::GetUInt64OrNull() const noexcept
{
    if (_value)
        return _meta->Converter->GetUInt64(_value, _length, _meta);
    return {};
}

Optional<int64> Field::GetInt64OrNull() const noexcept
{
    if (_value)
        return _meta->Converter->GetInt64(_value, _length, _meta);
    return {};
}

Optional<float> Field::GetFloatOrNull() const noexcept
{
    if (_value)
        return _meta->Converter->GetFloat(_value, _length, _meta);
    return {};
}

Optional<double> Field::GetDoubleOrNull() const noexcept
{
    if (_value)
        return _meta->Converter->GetDouble(_value, _length, _meta);
    return {};
}

Optional<SystemTimePoint> Field::GetDateOrNull() const noexcept
{
    if (_value)
        return _meta->Converter->GetDate(_value, _length, _meta);
    return {};
}

Optional<std::string> Field::GetStringOrNull() const noexcept
{
    if (Optional<std::string_view> string = GetStringViewOrNull())
        return Optional<std::string>(std::in_place, *string);
    return {};
}

Optional<std::string_view> Field::GetStringViewOrNull() const noexcept
{
    if (char const* string = GetCString())
        return Optional<std::string_view>(std::in_place, string, _length);
    return {};
}

Optional<std::vector<uint8>> Field::GetBinaryOrNull() const noexcept
{
    if (Optional<std::span<uint8 const>> binary = GetBinaryViewOrNull())
        return Optional<std::vector<uint8>>(std::in_place, binary->begin(), binary->end());
    return {};
}

Optional<std::span<uint8 const>> Field::GetBinaryViewOrNull() const noexcept
{
    if (_value)
        return Optional<std::span<uint8 const>>(std::in_place, reinterpret_cast<uint8 const*>(_value), _length);
    return {};
}

void Field::GetBinarySizeChecked(uint8* buf, size_t length) const noexcept
{
    ASSERT(_value && (_length == length), "Expected %zu-byte binary blob, got %sdata (%u bytes) instead", length, _value ? "" : "no ", _length);
    memcpy(buf, _value, length);
}

void Field::SetValue(char const* newValue, uint32 length)
{
    // This value stores raw bytes that have to be explicitly cast later
    _value = newValue;
    _length = length;
}

void Field::SetMetadata(QueryResultFieldMetadata const* meta)
{
    _meta = meta;
}
