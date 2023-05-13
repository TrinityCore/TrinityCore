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
#include "Log.h"
#include "StringConvert.h"
#include <cstring>

Field::Field()
{
    data.value = nullptr;
    data.length = 0;
    data.raw = false;
    meta = nullptr;
}

Field::~Field() = default;

uint8 Field::GetUInt8() const
{
    if (!data.value)
        return 0;

#ifdef TRINITY_STRICT_DATABASE_TYPE_CHECKS
    if (!IsType(DatabaseFieldTypes::Int8))
    {
        LogWrongType(__FUNCTION__);
        return 0;
    }
#endif

    if (data.raw)
        return *reinterpret_cast<uint8 const*>(data.value);
    return Trinity::StringTo<uint8>(data.value, 10).value_or(0);
}

int8 Field::GetInt8() const
{
    if (!data.value)
        return 0;

#ifdef TRINITY_STRICT_DATABASE_TYPE_CHECKS
    if (!IsType(DatabaseFieldTypes::Int8))
    {
        LogWrongType(__FUNCTION__);
        return 0;
    }
#endif

    if (data.raw)
        return *reinterpret_cast<int8 const*>(data.value);
    return Trinity::StringTo<int8>(data.value, 10).value_or(0);
}

uint16 Field::GetUInt16() const
{
    if (!data.value)
        return 0;

#ifdef TRINITY_STRICT_DATABASE_TYPE_CHECKS
    if (!IsType(DatabaseFieldTypes::Int16))
    {
        LogWrongType(__FUNCTION__);
        return 0;
    }
#endif

    if (data.raw)
        return *reinterpret_cast<uint16 const*>(data.value);
    return Trinity::StringTo<uint16>(data.value, 10).value_or(0);
}

int16 Field::GetInt16() const
{
    if (!data.value)
        return 0;

#ifdef TRINITY_STRICT_DATABASE_TYPE_CHECKS
    if (!IsType(DatabaseFieldTypes::Int16))
    {
        LogWrongType(__FUNCTION__);
        return 0;
    }
#endif

    if (data.raw)
        return *reinterpret_cast<int16 const*>(data.value);
    return Trinity::StringTo<int16>(data.value, 10).value_or(0);
}

uint32 Field::GetUInt32() const
{
    if (!data.value)
        return 0;

#ifdef TRINITY_STRICT_DATABASE_TYPE_CHECKS
    if (!IsType(DatabaseFieldTypes::Int32))
    {
        LogWrongType(__FUNCTION__);
        return 0;
    }
#endif

    if (data.raw)
        return *reinterpret_cast<uint32 const*>(data.value);
    return Trinity::StringTo<uint32>(data.value, 10).value_or(0);
}

int32 Field::GetInt32() const
{
    if (!data.value)
        return 0;

#ifdef TRINITY_STRICT_DATABASE_TYPE_CHECKS
    if (!IsType(DatabaseFieldTypes::Int32))
    {
        LogWrongType(__FUNCTION__);
        return 0;
    }
#endif

    if (data.raw)
        return *reinterpret_cast<int32 const*>(data.value);
    return Trinity::StringTo<int32>(data.value, 10).value_or(0);
}

uint64 Field::GetUInt64() const
{
    if (!data.value)
        return 0;

#ifdef TRINITY_STRICT_DATABASE_TYPE_CHECKS
    if (!IsType(DatabaseFieldTypes::Int64))
    {
        LogWrongType(__FUNCTION__);
        return 0;
    }
#endif

    if (data.raw)
        return *reinterpret_cast<uint64 const*>(data.value);
    return Trinity::StringTo<uint64>(data.value, 10).value_or(0);
}

int64 Field::GetInt64() const
{
    if (!data.value)
        return 0;

#ifdef TRINITY_STRICT_DATABASE_TYPE_CHECKS
    if (!IsType(DatabaseFieldTypes::Int64))
    {
        LogWrongType(__FUNCTION__);
        return 0;
    }
#endif

    if (data.raw)
        return *reinterpret_cast<int64 const*>(data.value);
    return Trinity::StringTo<int64>(data.value, 10).value_or(0);
}

float Field::GetFloat() const
{
    if (!data.value)
        return 0.0f;

#ifdef TRINITY_STRICT_DATABASE_TYPE_CHECKS
    if (!IsType(DatabaseFieldTypes::Float))
    {
        LogWrongType(__FUNCTION__);
        return 0.0f;
    }
#endif

    if (data.raw)
        return *reinterpret_cast<float const*>(data.value);
    return Trinity::StringTo<float>(data.value, 10).value_or(0);
}

double Field::GetDouble() const
{
    if (!data.value)
        return 0.0;

#ifdef TRINITY_STRICT_DATABASE_TYPE_CHECKS
    if (!IsType(DatabaseFieldTypes::Double) && !IsType(DatabaseFieldTypes::Decimal))
    {
        LogWrongType(__FUNCTION__);
        return 0.0;
    }
#endif

    if (data.raw && !IsType(DatabaseFieldTypes::Decimal))
        return *reinterpret_cast<double const*>(data.value);
    return Trinity::StringTo<double>(data.value, 10).value_or(0);
}

char const* Field::GetCString() const
{
    if (!data.value)
        return nullptr;

#ifdef TRINITY_STRICT_DATABASE_TYPE_CHECKS
    if (IsNumeric() && data.raw)
    {
        LogWrongType(__FUNCTION__);
        return nullptr;
    }
#endif
    return static_cast<char const*>(data.value);
}

std::string Field::GetString() const
{
    if (!data.value)
        return "";

    char const* string = GetCString();
    if (!string)
        return "";

    return std::string(string, data.length);
}

std::string_view Field::GetStringView() const
{
    if (!data.value)
        return {};

    char const* const string = GetCString();
    if (!string)
        return {};

    return { string, data.length };
}

std::vector<uint8> Field::GetBinary() const
{
    std::vector<uint8> result;
    if (!data.value || !data.length)
        return result;

    result.resize(data.length);
    memcpy(result.data(), data.value, data.length);
    return result;
}

void Field::GetBinarySizeChecked(uint8* buf, size_t length) const
{
    ASSERT(data.value && (data.length == length), "Expected %zu-byte binary blob, got %sdata (%u bytes) instead", length, data.value ? "" : "no ", data.length);
    memcpy(buf, data.value, length);
}

void Field::SetByteValue(char const* newValue, uint32 length)
{
    // This value stores raw bytes that have to be explicitly cast later
    data.value = newValue;
    data.length = length;
    data.raw = true;
}

void Field::SetStructuredValue(char const* newValue, uint32 length)
{
    // This value stores somewhat structured data that needs function style casting
    data.value = newValue;
    data.length = length;
    data.raw = false;
}

bool Field::IsType(DatabaseFieldTypes type) const
{
    return meta->Type == type;
}

bool Field::IsNumeric() const
{
    return (meta->Type == DatabaseFieldTypes::Int8 ||
        meta->Type == DatabaseFieldTypes::Int16 ||
        meta->Type == DatabaseFieldTypes::Int32 ||
        meta->Type == DatabaseFieldTypes::Int64 ||
        meta->Type == DatabaseFieldTypes::Float ||
        meta->Type == DatabaseFieldTypes::Double);
}

void Field::LogWrongType(char const* getter) const
{
    TC_LOG_WARN("sql.sql", "Warning: {} on {} field {}.{} ({}.{}) at index {}.",
        getter, meta->TypeName, meta->TableAlias, meta->Alias, meta->TableName, meta->Name, meta->Index);
}

void Field::SetMetadata(QueryResultFieldMetadata const* fieldMeta)
{
    meta = fieldMeta;
}
