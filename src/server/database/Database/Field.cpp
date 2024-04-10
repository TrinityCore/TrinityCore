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

uint8 Field::GetUInt8() const
{
    if (!_value)
        return 0;

    return _meta->Converter->GetUInt8(_value, _length, _meta);
}

int8 Field::GetInt8() const
{
    if (!_value)
        return 0;

    return _meta->Converter->GetInt8(_value, _length, _meta);
}

uint16 Field::GetUInt16() const
{
    if (!_value)
        return 0;

    return _meta->Converter->GetUInt16(_value, _length, _meta);
}

int16 Field::GetInt16() const
{
    if (!_value)
        return 0;

    return _meta->Converter->GetInt16(_value, _length, _meta);
}

uint32 Field::GetUInt32() const
{
    if (!_value)
        return 0;

    return _meta->Converter->GetUInt32(_value, _length, _meta);
}

int32 Field::GetInt32() const
{
    if (!_value)
        return 0;

    return _meta->Converter->GetInt32(_value, _length, _meta);
}

uint64 Field::GetUInt64() const
{
    if (!_value)
        return 0;

    return _meta->Converter->GetUInt64(_value, _length, _meta);
}

int64 Field::GetInt64() const
{
    if (!_value)
        return 0;

    return _meta->Converter->GetInt64(_value, _length, _meta);
}

float Field::GetFloat() const
{
    if (!_value)
        return 0.0f;

    return _meta->Converter->GetFloat(_value, _length, _meta);
}

double Field::GetDouble() const
{
    if (!_value)
        return 0.0;

    return _meta->Converter->GetDouble(_value, _length, _meta);
}

SystemTimePoint Field::GetDate() const
{
    if (!_value)
        return SystemTimePoint::min();

    return _meta->Converter->GetDate(_value, _length, _meta);
}

char const* Field::GetCString() const
{
    if (!_value)
        return nullptr;

    return _meta->Converter->GetCString(_value, _length, _meta);
}

std::string Field::GetString() const
{
    if (!_value)
        return "";

    char const* string = GetCString();
    if (!string)
        return "";

    return std::string(string, _length);
}

std::string_view Field::GetStringView() const
{
    if (!_value)
        return {};

    char const* const string = GetCString();
    if (!string)
        return {};

    return { string, _length };
}

std::vector<uint8> Field::GetBinary() const
{
    std::vector<uint8> result;
    if (!_value || !_length)
        return result;

    result.resize(_length);
    memcpy(result.data(), _value, _length);
    return result;
}

void Field::GetBinarySizeChecked(uint8* buf, size_t length) const
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
