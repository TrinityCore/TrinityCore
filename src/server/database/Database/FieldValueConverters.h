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

#ifndef TRINITY_FIELD_VALUE_CONVERTERS_H
#define TRINITY_FIELD_VALUE_CONVERTERS_H

#include "FieldValueConverter.h"
#include "StringConvert.h"

// converts string value returned from query to type specified in column metadata
template<typename DatabaseType>
class FromStringToDatabaseTypeConverter
{
public:
    static DatabaseType GetDatabaseValue(char const* data, uint32 size)
    {
        return Trinity::StringTo<DatabaseType>({ data, size }).template value_or<DatabaseType>(0);
    }

    static char const* GetStringValue(char const* data)
    {
        return data;
    }
};

// converts binary value returned from query to type specified in column metadata
template<typename DatabaseType>
class FromBinaryToDatabaseTypeConverter
{
public:
    static DatabaseType GetDatabaseValue(char const* data, uint32 /*size*/)
    {
        return *reinterpret_cast<DatabaseType const*>(data);
    }

    static char const* GetStringValue(char const* /*data*/)
    {
        return nullptr;
    }
};

// converts column value from type specified in column metadata to type requested by Field::Get* function
template<typename DatabaseType, template<typename> typename ToDatabaseTypeConverter>
class PrimitiveResultValueConverter : public BaseDatabaseResultValueConverter
{
public:
    template<typename T>
    static T GetNumericValue(char const* data, uint32 size, QueryResultFieldMetadata const* meta, char const* func)
    {
        DatabaseType source = ToDatabaseTypeConverter<DatabaseType>::GetDatabaseValue(data, size);
        T result = static_cast<T>(source);
        if (static_cast<DatabaseType>(result) != source)
        {
            LogTruncation(func, meta);
            return T();
        }
        return result;
    }

    uint8 GetUInt8(char const* data, uint32 size, QueryResultFieldMetadata const* meta) const override { return GetNumericValue<uint8>(data, size, meta, "Field::GetUInt8"); }
    int8 GetInt8(char const* data, uint32 size, QueryResultFieldMetadata const* meta) const override { return GetNumericValue<int8>(data, size, meta, "Field::GetInt8"); }
    uint16 GetUInt16(char const* data, uint32 size, QueryResultFieldMetadata const* meta) const override { return GetNumericValue<uint16>(data, size, meta, "Field::GetUInt16"); }
    int16 GetInt16(char const* data, uint32 size, QueryResultFieldMetadata const* meta) const override { return GetNumericValue<int16>(data, size, meta, "Field::GetInt16"); }
    uint32 GetUInt32(char const* data, uint32 size, QueryResultFieldMetadata const* meta) const override { return GetNumericValue<uint32>(data, size, meta, "Field::GetUInt32"); }
    int32 GetInt32(char const* data, uint32 size, QueryResultFieldMetadata const* meta) const override { return GetNumericValue<int32>(data, size, meta, "Field::GetInt32"); }
    uint64 GetUInt64(char const* data, uint32 size, QueryResultFieldMetadata const* meta) const override { return GetNumericValue<uint64>(data, size, meta, "Field::GetUInt64"); }
    int64 GetInt64(char const* data, uint32 size, QueryResultFieldMetadata const* meta) const override { return GetNumericValue<int64>(data, size, meta, "Field::GetInt64"); }
    float GetFloat(char const* data, uint32 size, QueryResultFieldMetadata const* meta) const override { return GetNumericValue<float>(data, size, meta, "Field::GetFloat"); }
    double GetDouble(char const* data, uint32 size, QueryResultFieldMetadata const* meta) const override { return GetNumericValue<double>(data, size, meta, "Field::GetDouble"); }
    SystemTimePoint GetDate(char const* /*data*/, uint32 /*size*/, QueryResultFieldMetadata const* meta) const override { LogTruncation("Field::GetDate", meta); return SystemTimePoint::min(); }
    char const* GetCString(char const* data, uint32 /*size*/, QueryResultFieldMetadata const* meta) const override
    {
        char const* result = ToDatabaseTypeConverter<DatabaseType>::GetStringValue(data);
        if (data && !result)
            LogTruncation("Field::GetCString", meta);
        return result;
    }
};

template<>
class PrimitiveResultValueConverter<char const*, std::type_identity_t> : public BaseDatabaseResultValueConverter
{
public:
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
    SystemTimePoint GetDate(char const* /*data*/, uint32 /*size*/, QueryResultFieldMetadata const* meta) const override { LogTruncation("Field::GetDate", meta); return SystemTimePoint::min(); }
    char const* GetCString(char const* data, uint32 /*size*/, QueryResultFieldMetadata const* /*meta*/) const override { return data; }
};

using StringResultValueConverter = PrimitiveResultValueConverter<char const*, std::type_identity_t>;

class NotImplementedResultValueConverter : public BaseDatabaseResultValueConverter
{
public:
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
    SystemTimePoint GetDate(char const* /*data*/, uint32 /*size*/, QueryResultFieldMetadata const* meta) const override { LogTruncation("Field::GetDate", meta); return SystemTimePoint::min(); }
    char const* GetCString(char const* /*data*/, uint32 /*size*/, QueryResultFieldMetadata const* meta) const override { LogTruncation("Field::GetCString", meta); return nullptr; }
};

#endif // TRINITY_FIELD_VALUE_CONVERTERS_H
