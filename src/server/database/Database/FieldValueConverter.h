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

#ifndef TRINITY_FIELD_VALUE_CONVERTER_H
#define TRINITY_FIELD_VALUE_CONVERTER_H

#include "Define.h"
#include "Duration.h"

struct QueryResultFieldMetadata;

class BaseDatabaseResultValueConverter
{
public:
    BaseDatabaseResultValueConverter();
    BaseDatabaseResultValueConverter(BaseDatabaseResultValueConverter const&) = delete;
    BaseDatabaseResultValueConverter(BaseDatabaseResultValueConverter&&) = delete;
    BaseDatabaseResultValueConverter& operator=(BaseDatabaseResultValueConverter const&) = delete;
    BaseDatabaseResultValueConverter& operator=(BaseDatabaseResultValueConverter&&) = delete;
    virtual ~BaseDatabaseResultValueConverter();

    virtual uint8 GetUInt8(char const* data, uint32 size, QueryResultFieldMetadata const* meta) const = 0;
    virtual int8 GetInt8(char const* data, uint32 size, QueryResultFieldMetadata const* meta) const = 0;
    virtual uint16 GetUInt16(char const* data, uint32 size, QueryResultFieldMetadata const* meta) const = 0;
    virtual int16 GetInt16(char const* data, uint32 size, QueryResultFieldMetadata const* meta) const = 0;
    virtual uint32 GetUInt32(char const* data, uint32 size, QueryResultFieldMetadata const* meta) const = 0;
    virtual int32 GetInt32(char const* data, uint32 size, QueryResultFieldMetadata const* meta) const = 0;
    virtual uint64 GetUInt64(char const* data, uint32 size, QueryResultFieldMetadata const* meta) const = 0;
    virtual int64 GetInt64(char const* data, uint32 size, QueryResultFieldMetadata const* meta) const = 0;
    virtual float GetFloat(char const* data, uint32 size, QueryResultFieldMetadata const* meta) const = 0;
    virtual double GetDouble(char const* data, uint32 size, QueryResultFieldMetadata const* meta) const = 0;
    virtual SystemTimePoint GetDate(char const* data, uint32 size, QueryResultFieldMetadata const* meta) const = 0;
    virtual char const* GetCString(char const* data, uint32 size, QueryResultFieldMetadata const* meta) const = 0;

    static void LogTruncation(char const* getter, QueryResultFieldMetadata const* meta);
};

#endif // TRINITY_FIELD_VALUE_CONVERTER_H
