/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "DBCDatabaseLoader.h"
#include "Common.h"
#include "DatabaseEnv.h"
#include "Errors.h"
#include "Log.h"
#include <sstream>

DBCDatabaseLoader::DBCDatabaseLoader(std::string const& storageName, std::string const& dbFormatString, std::string const& primaryKey, char const* dbcFormatString)
    : _formatString(dbFormatString), _indexName(primaryKey), _sqlTableName(storageName), _dbcFormat(dbcFormatString), _sqlIndexPos(0), _recordSize(0)
{
    // Convert dbc file name to sql table name
    std::transform(_sqlTableName.begin(), _sqlTableName.end(), _sqlTableName.begin(), ::tolower);
    for (char& c : _sqlTableName)
        if (c == '.')
            c = '_';

    // Get sql index position
    int32 indexPos = -1;
    _recordSize = DBCFileLoader::GetFormatRecordSize(_dbcFormat, &indexPos);
    ASSERT(indexPos >= 0);
    ASSERT(_recordSize);

    uint32 uindexPos = uint32(indexPos);
    for (uint32 x = 0; x < _formatString.size(); ++x)
    {
        // Count only fields present in sql
        if (_formatString[x] == FT_SQL_PRESENT)
        {
            if (x == uindexPos)
                break;
            ++_sqlIndexPos;
        }
    }
}

static char const* nullStr = "";

char* DBCDatabaseLoader::Load(uint32& records, char**& indexTable)
{
    std::ostringstream queryBuilder;
    queryBuilder << "SELECT * FROM " << _sqlTableName
        << " ORDER BY " << _indexName << " DESC;";

    // no error if empty set
    QueryResult result = WorldDatabase.Query(queryBuilder.str().c_str());
    if (!result)
        return nullptr;

    // Check if sql index pos is valid
    if (int32(result->GetFieldCount() - 1) < _sqlIndexPos)
    {
        ASSERT(false, "Invalid index pos for dbc:'%s'", _sqlTableName.c_str());
        return nullptr;
    }

    // Resize index table
    // database query *MUST* contain ORDER BY `index_field` DESC clause
    uint32 indexTableSize = std::max(records, (*result)[_sqlIndexPos].GetUInt32() + 1);
    if (indexTableSize > records)
    {
        char** tmpIdxTable = new char*[indexTableSize];
        memset(tmpIdxTable, 0, indexTableSize * sizeof(char*));
        memcpy(tmpIdxTable, indexTable, records * sizeof(char*));
        delete[] indexTable;
        indexTable = tmpIdxTable;
    }

    std::unique_ptr<char[]> dataTable = Trinity::make_unique<char[]>(result->GetRowCount() * _recordSize);
    std::unique_ptr<uint32[]> newIndexes = Trinity::make_unique<uint32[]>(result->GetRowCount());
    uint32 newRecords = 0;

    // Insert sql data into the data array
    do
    {
        Field* fields = result->Fetch();
        uint32 offset = 0;

        uint32 indexValue = fields[_sqlIndexPos].GetUInt32();

        char* dataValue = indexTable[indexValue];
        if (!dataValue)
        {
            newIndexes[newRecords] = indexValue;
            dataValue = &dataTable[newRecords++ * _recordSize];
        }
        else
        {
            // Attempt to overwrite existing data
            ASSERT(false, "Index %d already exists in dbc:'%s'", indexValue, _sqlTableName.c_str());
            return nullptr;
        }

        uint32 columnNumber = 0;
        uint32 sqlColumnNumber = 0;

        for (; columnNumber < _formatString.size(); ++columnNumber)
        {
            if (_formatString[columnNumber] == FT_SQL_ABSENT)
            {
                switch (_dbcFormat[columnNumber])
                {
                    case FT_FLOAT:
                        *reinterpret_cast<float*>(&dataValue[offset]) = 0.0f;
                        offset += 4;
                        break;
                    case FT_IND:
                    case FT_INT:
                        *reinterpret_cast<uint32*>(&dataValue[offset]) = uint32(0);
                        offset += 4;
                        break;
                    case FT_BYTE:
                        *reinterpret_cast<uint8*>(&dataValue[offset]) = uint8(0);
                        offset += 1;
                        break;
                    case FT_STRING:
                        *reinterpret_cast<char**>(&dataValue[offset]) = const_cast<char*>(nullStr);
                        offset += sizeof(char*);
                        break;
                }
            }
            else if (_formatString[columnNumber] == FT_SQL_PRESENT)
            {
                bool validSqlColumn = true;
                switch (_dbcFormat[columnNumber])
                {
                    case FT_FLOAT:
                        *reinterpret_cast<float*>(&dataValue[offset]) = fields[sqlColumnNumber].GetFloat();
                        offset += 4;
                        break;
                    case FT_IND:
                    case FT_INT:
                        *reinterpret_cast<uint32*>(&dataValue[offset]) = fields[sqlColumnNumber].GetUInt32();
                        offset += 4;
                        break;
                    case FT_BYTE:
                        *reinterpret_cast<uint8*>(&dataValue[offset]) = fields[sqlColumnNumber].GetUInt8();
                        offset += 1;
                        break;
                    case FT_STRING:
                        ASSERT(false, "Unsupported data type in table '%s' at char %d", _sqlTableName.c_str(), columnNumber);
                        return nullptr;
                    case FT_SORT:
                        break;
                    default:
                        validSqlColumn = false;
                        break;
                }
                if (validSqlColumn && (columnNumber != (_formatString.size() - 1)))
                    sqlColumnNumber++;
            }
            else
            {
                ASSERT(false, "Incorrect sql format string '%s' at char %d", _sqlTableName.c_str(), columnNumber);
                break;
            }
        }

        if (sqlColumnNumber != (result->GetFieldCount() - 1))
        {
            ASSERT(false, "SQL and DBC format strings are not matching for table: '%s'", _sqlTableName.c_str());
            return nullptr;
        }

        ASSERT(offset == _recordSize);
    } while (result->NextRow());

    ASSERT(newRecords == result->GetRowCount());

    // insert new records to index table
    for (uint32 i = 0; i < newRecords; ++i)
        indexTable[newIndexes[i]] = &dataTable[i * _recordSize];

    records = indexTableSize;

    return dataTable.release();
}
