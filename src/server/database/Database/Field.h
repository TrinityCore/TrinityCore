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
#include "Optional.h"
#include <array>
#include <span>
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

        bool GetBool() const noexcept // Wrapper, actually gets integer
        {
            return GetUInt8() != 0;
        }

        uint8 GetUInt8() const noexcept;
        int8 GetInt8() const noexcept;
        uint16 GetUInt16() const noexcept;
        int16 GetInt16() const noexcept;
        uint32 GetUInt32() const noexcept;
        int32 GetInt32() const noexcept;
        uint64 GetUInt64() const noexcept;
        int64 GetInt64() const noexcept;
        float GetFloat() const noexcept;
        double GetDouble() const noexcept;
        SystemTimePoint GetDate() const noexcept;
        char const* GetCString() const noexcept;
        std::string GetString() const noexcept;
        std::string_view GetStringView() const noexcept;
        std::vector<uint8> GetBinary() const noexcept;
        std::span<uint8 const> GetBinaryView() const noexcept;
        template <size_t S>
        std::array<uint8, S> GetBinary() const noexcept
        {
            std::array<uint8, S> buf;
            GetBinarySizeChecked(buf.data(), S);
            return buf;
        }

        bool IsNull() const noexcept
        {
            return _value == nullptr;
        }

        Optional<uint8> GetUInt8OrNull() const noexcept;
        Optional<int8> GetInt8OrNull() const noexcept;
        Optional<uint16> GetUInt16OrNull() const noexcept;
        Optional<int16> GetInt16OrNull() const noexcept;
        Optional<uint32> GetUInt32OrNull() const noexcept;
        Optional<int32> GetInt32OrNull() const noexcept;
        Optional<uint64> GetUInt64OrNull() const noexcept;
        Optional<int64> GetInt64OrNull() const noexcept;
        Optional<float> GetFloatOrNull() const noexcept;
        Optional<double> GetDoubleOrNull() const noexcept;
        Optional<SystemTimePoint> GetDateOrNull() const noexcept;
        Optional<std::string> GetStringOrNull() const noexcept;
        Optional<std::string_view> GetStringViewOrNull() const noexcept;
        Optional<std::vector<uint8>> GetBinaryOrNull() const noexcept;
        Optional<std::span<uint8 const>> GetBinaryViewOrNull() const noexcept;
        template <size_t S>
        Optional<std::array<uint8, S>> GetBinaryOrNull() const noexcept
        {
            Optional<std::array<uint8, S>> buf;
            if (!IsNull())
                GetBinarySizeChecked(buf.emplace().data(), S);
            return buf;
        }

    private:
        char const* _value;             // Actual data in memory
        uint32 _length;                 // Length

        void SetValue(char const* newValue, uint32 length);

        QueryResultFieldMetadata const* _meta;
        void SetMetadata(QueryResultFieldMetadata const* meta);

        void GetBinarySizeChecked(uint8* buf, size_t size) const noexcept;
};

#endif
