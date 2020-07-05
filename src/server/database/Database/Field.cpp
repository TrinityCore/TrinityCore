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
#include "Log.h"
#include "MySQLHacks.h"

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

#ifdef TRINITY_DEBUG
    if (!IsType(DatabaseFieldTypes::Int8))
    {
        LogWrongType(__FUNCTION__);
        return 0;
    }
#endif

    if (data.raw)
        return *reinterpret_cast<uint8 const*>(data.value);
    return static_cast<uint8>(strtoul(data.value, nullptr, 10));
}

int8 Field::GetInt8() const
{
    if (!data.value)
        return 0;

#ifdef TRINITY_DEBUG
    if (!IsType(DatabaseFieldTypes::Int8))
    {
        LogWrongType(__FUNCTION__);
        return 0;
    }
#endif

    if (data.raw)
        return *reinterpret_cast<int8 const*>(data.value);
    return static_cast<int8>(strtol(data.value, nullptr, 10));
}

uint16 Field::GetUInt16() const
{
    if (!data.value)
        return 0;

#ifdef TRINITY_DEBUG
    if (!IsType(DatabaseFieldTypes::Int16))
    {
        LogWrongType(__FUNCTION__);
        return 0;
    }
#endif

    if (data.raw)
        return *reinterpret_cast<uint16 const*>(data.value);
    return static_cast<uint16>(strtoul(data.value, nullptr, 10));
}

int16 Field::GetInt16() const
{
    if (!data.value)
        return 0;

#ifdef TRINITY_DEBUG
    if (!IsType(DatabaseFieldTypes::Int16))
    {
        LogWrongType(__FUNCTION__);
        return 0;
    }
#endif

    if (data.raw)
        return *reinterpret_cast<int16 const*>(data.value);
    return static_cast<int16>(strtol(data.value, nullptr, 10));
}

uint32 Field::GetUInt32() const
{
    if (!data.value)
        return 0;

#ifdef TRINITY_DEBUG
    if (!IsType(DatabaseFieldTypes::Int32))
    {
        LogWrongType(__FUNCTION__);
        return 0;
    }
#endif

    if (data.raw)
        return *reinterpret_cast<uint32 const*>(data.value);
    return static_cast<uint32>(strtoul(data.value, nullptr, 10));
}

int32 Field::GetInt32() const
{
    if (!data.value)
        return 0;

#ifdef TRINITY_DEBUG
    if (!IsType(DatabaseFieldTypes::Int32))
    {
        LogWrongType(__FUNCTION__);
        return 0;
    }
#endif

    if (data.raw)
        return *reinterpret_cast<int32 const*>(data.value);
    return static_cast<int32>(strtol(data.value, nullptr, 10));
}

uint64 Field::GetUInt64() const
{
    if (!data.value)
        return 0;

#ifdef TRINITY_DEBUG
    if (!IsType(DatabaseFieldTypes::Int64))
    {
        LogWrongType(__FUNCTION__);
        return 0;
    }
#endif

    if (data.raw)
        return *reinterpret_cast<uint64 const*>(data.value);
    return static_cast<uint64>(strtoull(data.value, nullptr, 10));
}

int64 Field::GetInt64() const
{
    if (!data.value)
        return 0;

#ifdef TRINITY_DEBUG
    if (!IsType(DatabaseFieldTypes::Int64))
    {
        LogWrongType(__FUNCTION__);
        return 0;
    }
#endif

    if (data.raw)
        return *reinterpret_cast<int64 const*>(data.value);
    return static_cast<int64>(strtoll(data.value, nullptr, 10));
}

float Field::GetFloat() const
{
    if (!data.value)
        return 0.0f;

#ifdef TRINITY_DEBUG
    if (!IsType(DatabaseFieldTypes::Float))
    {
        LogWrongType(__FUNCTION__);
        return 0.0f;
    }
#endif

    if (data.raw)
        return *reinterpret_cast<float const*>(data.value);
    return static_cast<float>(atof(data.value));
}

double Field::GetDouble() const
{
    if (!data.value)
        return 0.0f;

#ifdef TRINITY_DEBUG
    if (!IsType(DatabaseFieldTypes::Double) && !IsType(DatabaseFieldTypes::Decimal))
    {
        LogWrongType(__FUNCTION__);
        return 0.0f;
    }
#endif

    if (data.raw && !IsType(DatabaseFieldTypes::Decimal))
        return *reinterpret_cast<double const*>(data.value);
    return static_cast<double>(atof(data.value));
}

char const* Field::GetCString() const
{
    if (!data.value)
        return nullptr;

#ifdef TRINITY_DEBUG
    if (IsNumeric() && data.raw)
    {
        LogWrongType(__FUNCTION__);
        return NULL;
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

std::vector<uint8> Field::GetBinary() const
{
    std::vector<uint8> result;
    if (!data.value || !data.length)
        return result;

    result.resize(data.length);
    memcpy(result.data(), data.value, data.length);
    return result;
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
    TC_LOG_WARN("sql.sql", "Warning: %s on %s field %s.%s (%s.%s) at index %u.",
        getter, meta->TypeName, meta->TableAlias, meta->Alias, meta->TableName, meta->Name, meta->Index);
}

void Field::SetMetadata(QueryResultFieldMetadata const* fieldMeta)
{
    meta = fieldMeta;
}
