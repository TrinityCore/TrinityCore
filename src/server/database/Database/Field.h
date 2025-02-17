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

#ifndef TRINITY_DATABASE_FIELD_H
#define TRINITY_DATABASE_FIELD_H

#include "Define.h"
#include "Duration.h"
#include <array>
#include <string>
#include <string_view>
#include <vector>

class BaseDatabaseResultValueConverter;

enum class DatabaseFieldTypes : uint8
{
    Null,
    UInt8,
    Int8,
    UInt16,
    Int16,
    UInt32,
    Int32,
    UInt64,
    Int64,
    Float,
    Double,
    Decimal,
    Date,
    Time,
    Binary
};

struct QueryResultFieldMetadata
{
    char const* TableName = nullptr;
    char const* TableAlias = nullptr;
    char const* Name = nullptr;
    char const* Alias = nullptr;
    char const* TypeName = nullptr;
    uint32 Index = 0;
    DatabaseFieldTypes Type = DatabaseFieldTypes::Null;
    BaseDatabaseResultValueConverter const* Converter = nullptr;
};

/**
    @class Field

    @brief Class used to access individual fields of database query result

    Guideline on field type matching:

    |   MySQL type           |  method to use                         |
    |------------------------|----------------------------------------|
    | TINYINT                | GetBool, GetInt8, GetUInt8             |
    | SMALLINT               | GetInt16, GetUInt16                    |
    | MEDIUMINT, INT         | GetInt32, GetUInt32                    |
    | BIGINT                 | GetInt64, GetUInt64                    |
    | FLOAT                  | GetFloat                               |
    | DOUBLE, DECIMAL        | GetDouble                              |
    | CHAR, VARCHAR,         | GetCString, GetString                  |
    | TINYTEXT, MEDIUMTEXT,  | GetCString, GetString                  |
    | TEXT, LONGTEXT         | GetCString, GetString                  |
    | TINYBLOB, MEDIUMBLOB,  | GetBinary, GetString                   |
    | BLOB, LONGBLOB         | GetBinary, GetString                   |
    | BINARY, VARBINARY      | GetBinary                              |

    Return types of aggregate functions:

    | Function |       Type        |
    |----------|-------------------|
    | MIN, MAX | Same as the field |
    | SUM, AVG | DECIMAL           |
    | COUNT    | BIGINT            |
*/
class TC_DATABASE_API Field
{
    friend class ResultSet;
    friend class PreparedResultSet;

    public:
        Field();
        ~Field();

        bool GetBool() const // Wrapper, actually gets integer
        {
            return GetUInt8() == 1 ? true : false;
        }

        uint8 GetUInt8() const;
        int8 GetInt8() const;
        uint16 GetUInt16() const;
        int16 GetInt16() const;
        uint32 GetUInt32() const;
        int32 GetInt32() const;
        uint64 GetUInt64() const;
        int64 GetInt64() const;
        float GetFloat() const;
        double GetDouble() const;
        SystemTimePoint GetDate() const;
        char const* GetCString() const;
        std::string GetString() const;
        std::string_view GetStringView() const;
        std::vector<uint8> GetBinary() const;
        template <size_t S>
        std::array<uint8, S> GetBinary() const
        {
            std::array<uint8, S> buf;
            GetBinarySizeChecked(buf.data(), S);
            return buf;
        }

        bool IsNull() const
        {
            return _value == nullptr;
        }

    private:
        char const* _value;             // Actual data in memory
        uint32 _length;                 // Length

        void SetValue(char const* newValue, uint32 length);

        QueryResultFieldMetadata const* _meta;
        void SetMetadata(QueryResultFieldMetadata const* meta);

        void GetBinarySizeChecked(uint8* buf, size_t size) const;
};

#endif
