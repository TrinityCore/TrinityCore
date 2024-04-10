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

#include "QueryResult.h"
#include "Errors.h"
#include "Field.h"
#include "FieldValueConverters.h"
#include "Log.h"
#include "MySQLHacks.h"
#include "MySQLWorkaround.h"
#include <chrono>
#include <cstring>

namespace
{
static uint32 SizeForType(MYSQL_FIELD* field)
{
    switch (field->type)
    {
        case MYSQL_TYPE_NULL:
            return 0;
        case MYSQL_TYPE_TINY:
            return 1;
        case MYSQL_TYPE_YEAR:
        case MYSQL_TYPE_SHORT:
            return 2;
        case MYSQL_TYPE_INT24:
        case MYSQL_TYPE_LONG:
        case MYSQL_TYPE_FLOAT:
            return 4;
        case MYSQL_TYPE_DOUBLE:
        case MYSQL_TYPE_LONGLONG:
        case MYSQL_TYPE_BIT:
            return 8;

        case MYSQL_TYPE_TIMESTAMP:
        case MYSQL_TYPE_DATE:
        case MYSQL_TYPE_TIME:
        case MYSQL_TYPE_DATETIME:
            return sizeof(MYSQL_TIME);

        case MYSQL_TYPE_TINY_BLOB:
        case MYSQL_TYPE_MEDIUM_BLOB:
        case MYSQL_TYPE_LONG_BLOB:
        case MYSQL_TYPE_BLOB:
        case MYSQL_TYPE_STRING:
        case MYSQL_TYPE_VAR_STRING:
            return field->max_length + 1;

        case MYSQL_TYPE_DECIMAL:
        case MYSQL_TYPE_NEWDECIMAL:
            return 64;

        case MYSQL_TYPE_GEOMETRY:
            /*
            Following types are not sent over the wire:
            MYSQL_TYPE_ENUM:
            MYSQL_TYPE_SET:
            */
        default:
            TC_LOG_WARN("sql.sql", "SQL::SizeForType(): invalid field type {}", uint32(field->type));
            return 0;
    }
}

DatabaseFieldTypes MysqlTypeToFieldType(enum_field_types type, uint32 flags)
{
    switch (type)
    {
        case MYSQL_TYPE_NULL:
            return DatabaseFieldTypes::Null;
        case MYSQL_TYPE_TINY:
            return (flags & UNSIGNED_FLAG) ? DatabaseFieldTypes::UInt8 : DatabaseFieldTypes::Int8;
        case MYSQL_TYPE_YEAR:
        case MYSQL_TYPE_SHORT:
            return (flags & UNSIGNED_FLAG) ? DatabaseFieldTypes::UInt16 : DatabaseFieldTypes::Int16;
        case MYSQL_TYPE_INT24:
        case MYSQL_TYPE_LONG:
            return (flags & UNSIGNED_FLAG) ? DatabaseFieldTypes::UInt32 : DatabaseFieldTypes::Int32;
        case MYSQL_TYPE_LONGLONG:
        case MYSQL_TYPE_BIT:
            return (flags & UNSIGNED_FLAG) ? DatabaseFieldTypes::UInt64 : DatabaseFieldTypes::Int64;
        case MYSQL_TYPE_FLOAT:
            return DatabaseFieldTypes::Float;
        case MYSQL_TYPE_DOUBLE:
            return DatabaseFieldTypes::Double;
        case MYSQL_TYPE_DECIMAL:
        case MYSQL_TYPE_NEWDECIMAL:
            return DatabaseFieldTypes::Decimal;
        case MYSQL_TYPE_TIMESTAMP:
        case MYSQL_TYPE_DATE:
        case MYSQL_TYPE_DATETIME:
            return DatabaseFieldTypes::Date;
        case MYSQL_TYPE_TIME:
            return DatabaseFieldTypes::Time;
        case MYSQL_TYPE_TINY_BLOB:
        case MYSQL_TYPE_MEDIUM_BLOB:
        case MYSQL_TYPE_LONG_BLOB:
        case MYSQL_TYPE_BLOB:
        case MYSQL_TYPE_STRING:
        case MYSQL_TYPE_VAR_STRING:
            return DatabaseFieldTypes::Binary;
        default:
            TC_LOG_WARN("sql.sql", "MysqlTypeToFieldType(): invalid field type {}", uint32(type));
            break;
    }

    return DatabaseFieldTypes::Null;
}

static char const* FieldTypeToString(enum_field_types type, uint32 flags)
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
        case MYSQL_TYPE_INT24:       return (flags & UNSIGNED_FLAG) ? "UNSIGNED INT24" : "INT24";
        case MYSQL_TYPE_LONG:        return (flags & UNSIGNED_FLAG) ? "UNSIGNED LONG" : "LONG";
        case MYSQL_TYPE_LONGLONG:    return (flags & UNSIGNED_FLAG) ? "UNSIGNED LONGLONG" : "LONGLONG";
        case MYSQL_TYPE_LONG_BLOB:   return "LONG_BLOB";
        case MYSQL_TYPE_MEDIUM_BLOB: return "MEDIUM_BLOB";
        case MYSQL_TYPE_NEWDATE:     return "NEWDATE";
        case MYSQL_TYPE_NULL:        return "NULL";
        case MYSQL_TYPE_SET:         return "SET";
        case MYSQL_TYPE_SHORT:       return (flags & UNSIGNED_FLAG) ? "UNSIGNED SHORT" : "SHORT";
        case MYSQL_TYPE_STRING:      return "STRING";
        case MYSQL_TYPE_TIME:        return "TIME";
        case MYSQL_TYPE_TIMESTAMP:   return "TIMESTAMP";
        case MYSQL_TYPE_TINY:        return (flags & UNSIGNED_FLAG) ? "UNSIGNED TINY" : "TINY";
        case MYSQL_TYPE_TINY_BLOB:   return "TINY_BLOB";
        case MYSQL_TYPE_VAR_STRING:  return "VAR_STRING";
        case MYSQL_TYPE_YEAR:        return "YEAR";
        default:                     return "-Unknown-";
    }
}

template <typename>
class FromStringToMYSQL_TIME
{
public:
    static MYSQL_TIME GetDatabaseValue(char const* data, uint32 size)
    {
        MYSQL_TIME result = {};
        if (!data || !size)
        {
            result.time_type = MYSQL_TIMESTAMP_NONE;
            return result;
        }

        std::string_view in(data, size);

        size_t firstSeparatorIndex = in.find_first_of(":-");
        if (firstSeparatorIndex == std::string_view::npos)
        {
            result.time_type = MYSQL_TIMESTAMP_NONE;
            return result;
        }

        char firstSeparator = in[firstSeparatorIndex];

        auto parseNextComponent = [&](uint32& value, char requiredSeparator = '\0') -> bool
        {
            std::from_chars_result parseResult = std::from_chars(in.data(), in.data() + in.size(), value);
            if (parseResult.ec != std::errc())
                return false;

            in.remove_prefix(parseResult.ptr - in.data());
            if (requiredSeparator)
            {
                if (in.empty() || in[0] != requiredSeparator)
                    return false;

                in.remove_prefix(1);
            }

            return true;
        };

        uint32 yearOrHours = 0;
        uint32 monthOrMinutes = 0;
        uint32 dayOrSeconds = 0;
        if (!parseNextComponent(yearOrHours, firstSeparator)
            || !parseNextComponent(monthOrMinutes, firstSeparator)
            || !parseNextComponent(dayOrSeconds))
        {
            result.time_type = MYSQL_TIMESTAMP_ERROR;
            return result;
        }

        if (firstSeparator == ':')
        {
            if (!in.empty())
            {
                result.time_type = MYSQL_TIMESTAMP_ERROR;
                return result;
            }

            // time
            result.hour = yearOrHours;
            result.minute = monthOrMinutes;
            result.second = dayOrSeconds;
            result.time_type = MYSQL_TIMESTAMP_TIME;
        }
        else
        {
            if (in.empty())
            {
                // date
                result.year = yearOrHours;
                result.month = monthOrMinutes;
                result.day = dayOrSeconds;
                result.time_type = MYSQL_TIMESTAMP_DATE;
                return result;
            }

            // date+time
            if (in[0] != ' ')
            {
                result.time_type = MYSQL_TIMESTAMP_ERROR;
                return result;
            }

            in.remove_prefix(1);

            uint32 hours = 0;
            uint32 minutes = 0;
            uint32 seconds = 0;
            if (!parseNextComponent(hours, ':')
                || !parseNextComponent(minutes, ':')
                || !parseNextComponent(seconds))
            {
                result.time_type = MYSQL_TIMESTAMP_ERROR;
                return result;
            }

            uint32 microseconds = 0;
            if (!in.empty())
            {
                if (in[0] != '.')
                {
                    result.time_type = MYSQL_TIMESTAMP_ERROR;
                    return result;
                }

                in.remove_prefix(1);
                if (!parseNextComponent(microseconds))
                {
                    result.time_type = MYSQL_TIMESTAMP_ERROR;
                    return result;
                }

                if (!in.empty())
                {
                    result.time_type = MYSQL_TIMESTAMP_ERROR;
                    return result;
                }
            }

            result.year = yearOrHours;
            result.month = monthOrMinutes;
            result.day = dayOrSeconds;
            result.hour = hours;
            result.minute = minutes;
            result.second = seconds;
            result.second_part = microseconds;
            result.time_type = MYSQL_TIMESTAMP_DATETIME;
        }

        return result;
    }

    static char const* GetStringValue(char const* data)
    {
        return data;
    }
};

template<template<typename> typename ToDatabaseTypeConverter>
class DateResultValueConverter : public BaseDatabaseResultValueConverter
{
    uint8 GetUInt8(char const* /*data*/, uint32 /*size*/, QueryResultFieldMetadata const* meta) const override { LogTruncation("Field::GetUInt8", meta); return 0; }
    int8 GetInt8(char const* /*data*/, uint32 /*size*/, QueryResultFieldMetadata const* meta) const override { LogTruncation("Field::GetInt8", meta); return 0; }
    uint16 GetUInt16(char const* /*data*/, uint32 /*size*/, QueryResultFieldMetadata const* meta) const override { LogTruncation("Field::GetUInt16", meta); return 0; }
    int16 GetInt16(char const* /*data*/, uint32 /*size*/, QueryResultFieldMetadata const* meta) const override { LogTruncation("Field::GetInt16", meta); return 0; }
    uint32 GetUInt32(char const* /*data*/, uint32 /*size*/, QueryResultFieldMetadata const* meta) const override { LogTruncation("Field::GetUInt32", meta); return 0; }
    int32 GetInt32(char const* /*data*/, uint32 /*size*/, QueryResultFieldMetadata const* meta) const override { LogTruncation("Field::GetInt32", meta); return 0; }
    uint64 GetUInt64(char const* /*data*/, uint32 /*size*/, QueryResultFieldMetadata const* meta) const override { LogTruncation("Field::GetUInt64", meta); return 0; }
    int64 GetInt64(char const* /*data*/, uint32 /*size*/, QueryResultFieldMetadata const* meta) const override { LogTruncation("Field::GetInt64", meta); return 0; }
    float GetFloat(char const* /*data*/, uint32 /*size*/, QueryResultFieldMetadata const* meta) const override { LogTruncation("Field::GetFloat", meta); return 0.0f; }
    double GetDouble(char const* /*data*/, uint32 /*size*/, QueryResultFieldMetadata const* meta) const override { LogTruncation("Field::GetDouble", meta); return 0.0; }

    SystemTimePoint GetDate(char const* data, uint32 size, QueryResultFieldMetadata const* meta) const override
    {
        using namespace std::chrono;
        MYSQL_TIME source = ToDatabaseTypeConverter<MYSQL_TIME>::GetDatabaseValue(data, size);
        switch (source.time_type)
        {
            case MYSQL_TIMESTAMP_DATE:
                return sys_days(year(source.year) / month(source.month) / day(source.day));
            case MYSQL_TIMESTAMP_DATETIME:
                return sys_days(year(source.year) / month(source.month) / day(source.day))
                    + hours(source.hour)
                    + minutes(source.minute)
                    + seconds(source.second)
                    + microseconds(source.second_part);
            default:
                break;
        }

        LogTruncation("Field::GetDate", meta);
        return SystemTimePoint();
    }

    char const* GetCString(char const* data, uint32 /*size*/, QueryResultFieldMetadata const* meta) const override
    {
        char const* result = ToDatabaseTypeConverter<MYSQL_TIME>::GetStringValue(data);
        if (data && !result)
            LogTruncation("Field::GetCString", meta);
        return result;
    }
};

std::unique_ptr<BaseDatabaseResultValueConverter> const FromStringValueConverters[15] =
{
    nullptr,
    std::make_unique<PrimitiveResultValueConverter<uint8, FromStringToDatabaseTypeConverter>>(),
    std::make_unique<PrimitiveResultValueConverter<int8, FromStringToDatabaseTypeConverter>>(),
    std::make_unique<PrimitiveResultValueConverter<uint16, FromStringToDatabaseTypeConverter>>(),
    std::make_unique<PrimitiveResultValueConverter<int16, FromStringToDatabaseTypeConverter>>(),
    std::make_unique<PrimitiveResultValueConverter<uint32, FromStringToDatabaseTypeConverter>>(),
    std::make_unique<PrimitiveResultValueConverter<int32, FromStringToDatabaseTypeConverter>>(),
    std::make_unique<PrimitiveResultValueConverter<uint64, FromStringToDatabaseTypeConverter>>(),
    std::make_unique<PrimitiveResultValueConverter<int64, FromStringToDatabaseTypeConverter>>(),
    std::make_unique<PrimitiveResultValueConverter<float, FromStringToDatabaseTypeConverter>>(),
    std::make_unique<PrimitiveResultValueConverter<double, FromStringToDatabaseTypeConverter>>(),
    std::make_unique<PrimitiveResultValueConverter<double, FromStringToDatabaseTypeConverter>>(),
    std::make_unique<DateResultValueConverter<FromStringToMYSQL_TIME>>(),
    std::make_unique<NotImplementedResultValueConverter>(),    // DatabaseFieldTypes::Time
    std::make_unique<StringResultValueConverter>()
};

std::unique_ptr<BaseDatabaseResultValueConverter> const BinaryValueConverters[15] =
{
    nullptr,
    std::make_unique<PrimitiveResultValueConverter<uint8, FromBinaryToDatabaseTypeConverter>>(),
    std::make_unique<PrimitiveResultValueConverter<int8, FromBinaryToDatabaseTypeConverter>>(),
    std::make_unique<PrimitiveResultValueConverter<uint16, FromBinaryToDatabaseTypeConverter>>(),
    std::make_unique<PrimitiveResultValueConverter<int16, FromBinaryToDatabaseTypeConverter>>(),
    std::make_unique<PrimitiveResultValueConverter<uint32, FromBinaryToDatabaseTypeConverter>>(),
    std::make_unique<PrimitiveResultValueConverter<int32, FromBinaryToDatabaseTypeConverter>>(),
    std::make_unique<PrimitiveResultValueConverter<uint64, FromBinaryToDatabaseTypeConverter>>(),
    std::make_unique<PrimitiveResultValueConverter<int64, FromBinaryToDatabaseTypeConverter>>(),
    std::make_unique<PrimitiveResultValueConverter<float, FromBinaryToDatabaseTypeConverter>>(),
    std::make_unique<PrimitiveResultValueConverter<double, FromBinaryToDatabaseTypeConverter>>(),
    std::make_unique<PrimitiveResultValueConverter<double, FromStringToDatabaseTypeConverter>>(), // always sent as string
    std::make_unique<DateResultValueConverter<FromBinaryToDatabaseTypeConverter>>(),
    std::make_unique<NotImplementedResultValueConverter>(),    // DatabaseFieldTypes::Time
    std::make_unique<StringResultValueConverter>()
};

void InitializeDatabaseFieldMetadata(QueryResultFieldMetadata* meta, MySQLField const* field, uint32 fieldIndex, bool binaryProtocol)
{
    meta->TableName = field->org_table;
    meta->TableAlias = field->table;
    meta->Name = field->org_name;
    meta->Alias = field->name;
    meta->TypeName = FieldTypeToString(field->type, field->flags);
    meta->Index = fieldIndex;
    meta->Type = MysqlTypeToFieldType(field->type, field->flags);
    meta->Converter = binaryProtocol ? BinaryValueConverters[AsUnderlyingType(meta->Type)].get() : FromStringValueConverters[AsUnderlyingType(meta->Type)].get();
}
}

ResultSet::ResultSet(MySQLResult* result, MySQLField* fields, uint64 rowCount, uint32 fieldCount) :
_rowCount(rowCount),
_fieldCount(fieldCount),
_result(result),
_fields(fields)
{
    _fieldMetadata.resize(_fieldCount);
    _currentRow = new Field[_fieldCount];
    for (uint32 i = 0; i < _fieldCount; i++)
    {
        InitializeDatabaseFieldMetadata(&_fieldMetadata[i], &_fields[i], i, false);
        _currentRow[i].SetMetadata(&_fieldMetadata[i]);
    }
}

PreparedResultSet::PreparedResultSet(MySQLStmt* stmt, MySQLResult* result, uint64 rowCount, uint32 fieldCount) :
m_rowCount(rowCount),
m_rowPosition(0),
m_fieldCount(fieldCount),
m_rBind(nullptr),
m_stmt(stmt),
m_metadataResult(result)
{
    if (!m_metadataResult)
        return;

    if (m_stmt->bind_result_done)
    {
        delete[] m_stmt->bind->length;
        delete[] m_stmt->bind->is_null;
    }

    m_rBind = new MySQLBind[m_fieldCount];

    //- for future readers wondering where the fuck this is freed - mysql_stmt_bind_result moves pointers to these
    // from m_rBind to m_stmt->bind and it is later freed by the `if (m_stmt->bind_result_done)` block just above here
    // MYSQL_STMT lifetime is equal to connection lifetime
    MySQLBool* m_isNull = new MySQLBool[m_fieldCount];
    unsigned long* m_length = new unsigned long[m_fieldCount];

    memset(m_isNull, 0, sizeof(MySQLBool) * m_fieldCount);
    memset(m_rBind, 0, sizeof(MySQLBind) * m_fieldCount);
    memset(m_length, 0, sizeof(unsigned long) * m_fieldCount);

    //- This is where we store the (entire) resultset
    if (mysql_stmt_store_result(m_stmt))
    {
        TC_LOG_WARN("sql.sql", "{}:mysql_stmt_store_result, cannot bind result from MySQL server. Error: {}", __FUNCTION__, mysql_stmt_error(m_stmt));
        delete[] m_rBind;
        delete[] m_isNull;
        delete[] m_length;
        return;
    }

    m_rowCount = mysql_stmt_num_rows(m_stmt);

    //- This is where we prepare the buffer based on metadata
    MySQLField* field = reinterpret_cast<MySQLField*>(mysql_fetch_fields(m_metadataResult));
    m_fieldMetadata.resize(m_fieldCount);
    std::size_t rowSize = 0;
    for (uint32 i = 0; i < m_fieldCount; ++i)
    {
        uint32 size = SizeForType(&field[i]);
        rowSize += size;

        InitializeDatabaseFieldMetadata(&m_fieldMetadata[i], &field[i], i, true);

        m_rBind[i].buffer_type = field[i].type;
        m_rBind[i].buffer_length = size;
        m_rBind[i].length = &m_length[i];
        m_rBind[i].is_null = &m_isNull[i];
        m_rBind[i].error = nullptr;
        m_rBind[i].is_unsigned = field[i].flags & UNSIGNED_FLAG;
    }

    char* dataBuffer = new char[rowSize * m_rowCount];
    for (uint32 i = 0, offset = 0; i < m_fieldCount; ++i)
    {
        m_rBind[i].buffer = dataBuffer + offset;
        offset += m_rBind[i].buffer_length;
    }

    //- This is where we bind the bind the buffer to the statement
    if (mysql_stmt_bind_result(m_stmt, m_rBind))
    {
        TC_LOG_WARN("sql.sql", "{}:mysql_stmt_bind_result, cannot bind result from MySQL server. Error: {}", __FUNCTION__, mysql_stmt_error(m_stmt));
        mysql_stmt_free_result(m_stmt);
        CleanUp();
        delete[] m_isNull;
        delete[] m_length;
        return;
    }

    m_rows.resize(uint32(m_rowCount) * m_fieldCount);
    while (_NextRow())
    {
        for (uint32 fIndex = 0; fIndex < m_fieldCount; ++fIndex)
        {
            m_rows[uint32(m_rowPosition) * m_fieldCount + fIndex].SetMetadata(&m_fieldMetadata[fIndex]);

            unsigned long buffer_length = m_rBind[fIndex].buffer_length;
            unsigned long fetched_length = *m_rBind[fIndex].length;
            if (!*m_rBind[fIndex].is_null)
            {
                void* buffer = m_stmt->bind[fIndex].buffer;
                switch (m_rBind[fIndex].buffer_type)
                {
                    case MYSQL_TYPE_TINY_BLOB:
                    case MYSQL_TYPE_MEDIUM_BLOB:
                    case MYSQL_TYPE_LONG_BLOB:
                    case MYSQL_TYPE_BLOB:
                    case MYSQL_TYPE_STRING:
                    case MYSQL_TYPE_VAR_STRING:
                        // warning - the string will not be null-terminated if there is no space for it in the buffer
                        // when mysql_stmt_fetch returned MYSQL_DATA_TRUNCATED
                        // we cannot blindly null-terminate the data either as it may be retrieved as binary blob and not specifically a string
                        // in this case using Field::GetCString will result in garbage
                        // TODO: remove Field::GetCString and use std::string_view in C++17
                        if (fetched_length < buffer_length)
                            *((char*)buffer + fetched_length) = '\0';
                        break;
                    default:
                        break;
                }

                m_rows[uint32(m_rowPosition) * m_fieldCount + fIndex].SetValue(
                    (char const*)buffer,
                    fetched_length);

                // move buffer pointer to next part
                m_stmt->bind[fIndex].buffer = (char*)buffer + rowSize;
            }
            else
            {
                m_rows[uint32(m_rowPosition) * m_fieldCount + fIndex].SetValue(
                    nullptr,
                    *m_rBind[fIndex].length);
            }
        }
        m_rowPosition++;
    }
    m_rowPosition = 0;

    /// All data is buffered, let go of mysql c api structures
    mysql_stmt_free_result(m_stmt);
}

ResultSet::~ResultSet()
{
    CleanUp();
}

PreparedResultSet::~PreparedResultSet()
{
    CleanUp();
}

bool ResultSet::NextRow()
{
    MYSQL_ROW row;

    if (!_result)
        return false;

    row = mysql_fetch_row(_result);
    if (!row)
    {
        CleanUp();
        return false;
    }

    unsigned long* lengths = mysql_fetch_lengths(_result);
    if (!lengths)
    {
        TC_LOG_WARN("sql.sql", "{}:mysql_fetch_lengths, cannot retrieve value lengths. Error {}.", __FUNCTION__, mysql_error(_result->handle));
        CleanUp();
        return false;
    }

    for (uint32 i = 0; i < _fieldCount; i++)
        _currentRow[i].SetValue(row[i], lengths[i]);

    return true;
}

bool PreparedResultSet::NextRow()
{
    /// Only updates the m_rowPosition so upper level code knows in which element
    /// of the rows vector to look
    if (++m_rowPosition >= m_rowCount)
        return false;

    return true;
}

bool PreparedResultSet::_NextRow()
{
    /// Only called in low-level code, namely the constructor
    /// Will iterate over every row of data and buffer it
    if (m_rowPosition >= m_rowCount)
        return false;

    int retval = mysql_stmt_fetch(m_stmt);
    return retval == 0 || retval == MYSQL_DATA_TRUNCATED;
}

void ResultSet::CleanUp()
{
    if (_currentRow)
    {
        delete [] _currentRow;
        _currentRow = nullptr;
    }

    if (_result)
    {
        mysql_free_result(_result);
        _result = nullptr;
    }
}

void PreparedResultSet::CleanUp()
{
    if (m_metadataResult)
        mysql_free_result(m_metadataResult);

    if (m_rBind)
    {
        delete[](char*)m_rBind->buffer;
        delete[] m_rBind;
        m_rBind = nullptr;
    }
}

Field const& ResultSet::operator[](std::size_t index) const
{
    ASSERT(index < _fieldCount);
    return _currentRow[index];
}

Field* PreparedResultSet::Fetch() const
{
    ASSERT(m_rowPosition < m_rowCount);
    return const_cast<Field*>(&m_rows[uint32(m_rowPosition) * m_fieldCount]);
}

Field const& PreparedResultSet::operator[](std::size_t index) const
{
    ASSERT(m_rowPosition < m_rowCount);
    ASSERT(index < m_fieldCount);
    return m_rows[uint32(m_rowPosition) * m_fieldCount + index];
}
