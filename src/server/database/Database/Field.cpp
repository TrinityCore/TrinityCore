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

Field::Field()
{
    data.value = NULL;
    data.type = DatabaseFieldTypes::Null;
    data.length = 0;
    data.raw = false;
}

Field::~Field()
{
    CleanUp();
}

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
        return *reinterpret_cast<uint8*>(data.value);
    return static_cast<uint8>(strtoul((char*)data.value, nullptr, 10));
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
        return *reinterpret_cast<int8*>(data.value);
    return static_cast<int8>(strtol((char*)data.value, NULL, 10));
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
        return *reinterpret_cast<uint16*>(data.value);
    return static_cast<uint16>(strtoul((char*)data.value, nullptr, 10));
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
        return *reinterpret_cast<int16*>(data.value);
    return static_cast<int16>(strtol((char*)data.value, NULL, 10));
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
        return *reinterpret_cast<uint32*>(data.value);
    return static_cast<uint32>(strtoul((char*)data.value, nullptr, 10));
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
        return *reinterpret_cast<int32*>(data.value);
    return static_cast<int32>(strtol((char*)data.value, NULL, 10));
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
        return *reinterpret_cast<uint64*>(data.value);
    return static_cast<uint64>(strtoull((char*)data.value, nullptr, 10));
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
        return *reinterpret_cast<int64*>(data.value);
    return static_cast<int64>(strtoll((char*)data.value, NULL, 10));
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
        return *reinterpret_cast<float*>(data.value);
    return static_cast<float>(atof((char*)data.value));
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
        return *reinterpret_cast<double*>(data.value);
    return static_cast<double>(atof((char*)data.value));
}

char const* Field::GetCString() const
{
    if (!data.value)
        return NULL;

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

void Field::SetByteValue(void* newValue, DatabaseFieldTypes newType, uint32 length)
{
    // This value stores raw bytes that have to be explicitly cast later
    data.value = newValue;
    data.length = length;
    data.type = newType;
    data.raw = true;
}

void Field::SetStructuredValue(char* newValue, DatabaseFieldTypes newType, uint32 length)
{
    if (data.value)
        CleanUp();

    // This value stores somewhat structured data that needs function style casting
    if (newValue)
    {
        data.value = new char[length + 1];
        memcpy(data.value, newValue, length);
        *(reinterpret_cast<char*>(data.value) + length) = '\0';
        data.length = length;
    }

    data.type = newType;
    data.raw = false;
}

bool Field::IsType(DatabaseFieldTypes type) const
{
    return data.type == type;
}

bool Field::IsNumeric() const
{
    return (data.type == DatabaseFieldTypes::Int8 ||
        data.type == DatabaseFieldTypes::Int16 ||
        data.type == DatabaseFieldTypes::Int32 ||
        data.type == DatabaseFieldTypes::Int64 ||
        data.type == DatabaseFieldTypes::Float ||
        data.type == DatabaseFieldTypes::Double);
}

#ifdef TRINITY_DEBUG

void Field::LogWrongType(char const* getter) const
{
    TC_LOG_WARN("sql.sql", "Warning: %s on %s field %s.%s (%s.%s) at index %u.",
        getter, meta.Type, meta.TableAlias, meta.Alias, meta.TableName, meta.Name, meta.Index);
}

#include "MySQLHacks.h"

static char const* FieldTypeToString(enum_field_types type)
{
    switch (type)
    {
        case MYSQL_TYPE_BIT:         return "BIT";
        case MYSQL_TYPE_BLOB:        return "BLOB";
        case MYSQL_TYPE_DATE:        return "DATE";
        case MYSQL_TYPE_DATETIME:    return "DATETIME";
        case MYSQL_TYPE_NEWDECIMAL:  return "NEWDECIMAL";
        case MYSQL_TYPE_DECIMAL:     return "DECIMAL";
        case MYSQL_TYPE_DOUBLE:      return "DOUBLE";
        case MYSQL_TYPE_ENUM:        return "ENUM";
        case MYSQL_TYPE_FLOAT:       return "FLOAT";
        case MYSQL_TYPE_GEOMETRY:    return "GEOMETRY";
        case MYSQL_TYPE_INT24:       return "INT24";
        case MYSQL_TYPE_LONG:        return "LONG";
        case MYSQL_TYPE_LONGLONG:    return "LONGLONG";
        case MYSQL_TYPE_LONG_BLOB:   return "LONG_BLOB";
        case MYSQL_TYPE_MEDIUM_BLOB: return "MEDIUM_BLOB";
        case MYSQL_TYPE_NEWDATE:     return "NEWDATE";
        case MYSQL_TYPE_NULL:        return "NULL";
        case MYSQL_TYPE_SET:         return "SET";
        case MYSQL_TYPE_SHORT:       return "SHORT";
        case MYSQL_TYPE_STRING:      return "STRING";
        case MYSQL_TYPE_TIME:        return "TIME";
        case MYSQL_TYPE_TIMESTAMP:   return "TIMESTAMP";
        case MYSQL_TYPE_TINY:        return "TINY";
        case MYSQL_TYPE_TINY_BLOB:   return "TINY_BLOB";
        case MYSQL_TYPE_VAR_STRING:  return "VAR_STRING";
        case MYSQL_TYPE_YEAR:        return "YEAR";
        default:                     return "-Unknown-";
    }
}

void Field::SetMetadata(MySQLField* field, uint32 fieldIndex)
{
    meta.TableName = field->org_table;
    meta.TableAlias = field->table;
    meta.Name = field->org_name;
    meta.Alias = field->name;
    meta.Type = FieldTypeToString(field->type);
    meta.Index = fieldIndex;
}
#endif
