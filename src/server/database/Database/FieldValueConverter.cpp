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

#include "FieldValueConverter.h"
#include "Errors.h"
#include "Field.h"

BaseDatabaseResultValueConverter::BaseDatabaseResultValueConverter() = default;
BaseDatabaseResultValueConverter::~BaseDatabaseResultValueConverter() = default;

void BaseDatabaseResultValueConverter::LogTruncation(char const* getter, QueryResultFieldMetadata const* meta)
{
    char const* expectedAccessor = "";
    switch (meta->Type)
    {
        case DatabaseFieldTypes::UInt8: expectedAccessor = "Field::GetUInt8"; break;
        case DatabaseFieldTypes::Int8: expectedAccessor = "Field::GetInt8"; break;
        case DatabaseFieldTypes::UInt16: expectedAccessor = "Field::GetUInt16"; break;
        case DatabaseFieldTypes::Int16: expectedAccessor = "Field::GetInt16"; break;
        case DatabaseFieldTypes::UInt32: expectedAccessor = "Field::GetUIn32"; break;
        case DatabaseFieldTypes::Int32: expectedAccessor = "Field::GetInt32"; break;
        case DatabaseFieldTypes::UInt64: expectedAccessor = "Field::GetUIn64"; break;
        case DatabaseFieldTypes::Int64:  expectedAccessor = "Field::GetInt64"; break;
        case DatabaseFieldTypes::Float: expectedAccessor = "Field::GetFloat"; break;
        case DatabaseFieldTypes::Double: expectedAccessor = "Field::GetDouble"; break;
        case DatabaseFieldTypes::Decimal: expectedAccessor = "Field::GetDouble or Field::GetString"; break;
        case DatabaseFieldTypes::Date: expectedAccessor = "Field::GetDate"; break;
        case DatabaseFieldTypes::Time: expectedAccessor = "Field::GetTime"; break;
        case DatabaseFieldTypes::Binary: expectedAccessor = "Field::GetString or Field::GetBinary"; break;
        default:
            break;
    }

    ASSERT(false, "%s on %s field %s.%s (%s.%s) at index %u caused value to be truncated. Use %s instead.",
        getter, meta->TypeName, meta->TableAlias, meta->Alias, meta->TableName, meta->Name, meta->Index, expectedAccessor);
}
