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

#include "DBCDatabaseLoader.h"
#include "Common.h"
#include "DatabaseEnv.h"
#include "Errors.h"
#include "Log.h"
#include "StringFormat.h"
#include <sstream>

DBCDatabaseLoader::DBCDatabaseLoader(char const* tableName, char const* dbFormatString, char const* primaryKey, char const* dbcFormatString, std::vector<char*>& stringPool)
    : _sqlTableName(tableName), _formatString(dbFormatString), _indexName(primaryKey), _dbcFormat(dbcFormatString), _sqlIndexPos(0), _recordSize(0), _stringPool(stringPool)
{
    // Get sql index position
    int32 indexPos = -1;
    _recordSize = DBCFileLoader::GetFormatRecordSize(_dbcFormat, &indexPos);
    ASSERT(indexPos >= 0);
    ASSERT(_recordSize);

    uint32 uIndexPos = uint32(indexPos);
    char const* fmt = _formatString;
    while (uIndexPos)
    {
        switch (*fmt)
        {
            case FT_SQL_PRESENT:
                ++_sqlIndexPos;
                break;
            case FT_SQL_ABSENT:
                break;
            default:
                ABORT_MSG("Invalid DB format string for '%s'", tableName);
                break;
        }
        --uIndexPos;
        ++fmt;
    }
    ASSERT(*fmt == FT_SQL_PRESENT, "Index column not present in format string for '%s'", tableName);
}

static char const* nullStr = "";

char* DBCDatabaseLoader::Load(uint32& records, char**& indexTable)
{
    std::string query = Trinity::StringFormat("SELECT * FROM %s ORDER BY %s DESC;", _sqlTableName, _indexName);

    // no error if empty set
    QueryResult result = WorldDatabase.Query(query.c_str());
    if (!result)
        return nullptr;

    // Check if sql index pos is valid
    if (int32(result->GetFieldCount() - 1) < _sqlIndexPos)
    {
        ABORT_MSG("Invalid index pos for dbc: '%s'", _sqlTableName);
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

    std::unique_ptr<char[]> dataTable = std::make_unique<char[]>(result->GetRowCount() * _recordSize);
    std::unique_ptr<uint32[]> newIndexes = std::make_unique<uint32[]>(result->GetRowCount());
    uint32 newRecords = 0;

    // Insert sql data into the data array
    do
    {
        Field* fields = result->Fetch();

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
            ABORT_MSG("Index %d already exists in dbc:'%s'", indexValue, _sqlTableName);
            return nullptr;
        }

        uint32 dataOffset = 0;
        uint32 sqlColumnNumber = 0;
        char const* dbcFormat = _dbcFormat;
        char const* sqlFormat = _formatString;
        for (; (*dbcFormat || *sqlFormat); ++dbcFormat, ++sqlFormat)
        {
            if (!*dbcFormat || !*sqlFormat)
            {
                ABORT_MSG("DB and DBC format strings do not have the same length for '%s'", _sqlTableName);
                return nullptr;
            }
            if (!*dbcFormat)
                break;
            switch (*sqlFormat)
            {
                case FT_SQL_PRESENT:
                    switch (*dbcFormat)
                    {
                        case FT_FLOAT:
                            *reinterpret_cast<float*>(&dataValue[dataOffset]) = fields[sqlColumnNumber].GetFloat();
                            dataOffset += sizeof(float);
                            break;
                        case FT_IND:
                        case FT_INT:
                            *reinterpret_cast<uint32*>(&dataValue[dataOffset]) = fields[sqlColumnNumber].GetUInt32();
                            dataOffset += sizeof(uint32);
                            break;
                        case FT_BYTE:
                            *reinterpret_cast<uint8*>(&dataValue[dataOffset]) = fields[sqlColumnNumber].GetUInt8();
                            dataOffset += sizeof(uint8);
                            break;
                        case FT_STRING:
                            *reinterpret_cast<char**>(&dataValue[dataOffset]) = CloneStringToPool(fields[sqlColumnNumber].GetString());
                            dataOffset += sizeof(char*);
                            break;
                        case FT_SORT:
                            break;
                        default:
                            ABORT_MSG("Unsupported data type '%c' marked present in table '%s'", *dbcFormat, _sqlTableName);
                            return nullptr;
                    }
                    ++sqlColumnNumber;
                    break;
                case FT_SQL_ABSENT:
                    switch (*dbcFormat)
                    {
                        case FT_FLOAT:
                            *reinterpret_cast<float*>(&dataValue[dataOffset]) = 0.0f;
                            dataOffset += sizeof(float);
                            break;
                        case FT_IND:
                        case FT_INT:
                            *reinterpret_cast<uint32*>(&dataValue[dataOffset]) = uint32(0);
                            dataOffset += sizeof(uint32);
                            break;
                        case FT_BYTE:
                            *reinterpret_cast<uint8*>(&dataValue[dataOffset]) = uint8(0);
                            dataOffset += sizeof(uint8);
                            break;
                        case FT_STRING:
                            *reinterpret_cast<char**>(&dataValue[dataOffset]) = const_cast<char*>(nullStr);
                            dataOffset += sizeof(char*);
                            break;
                    }
                    break;
                default:
                    ABORT_MSG("Invalid DB format string for '%s'", _sqlTableName);
                    return nullptr;
            }
        }
        ASSERT(sqlColumnNumber == result->GetFieldCount(), "SQL format string does not match database for table: '%s'", _sqlTableName);
        ASSERT(dataOffset == _recordSize);
    } while (result->NextRow());

    ASSERT(newRecords == result->GetRowCount());

    // insert new records to index table
    for (uint32 i = 0; i < newRecords; ++i)
        indexTable[newIndexes[i]] = &dataTable[i * _recordSize];

    records = indexTableSize;

    return dataTable.release();
}

char* DBCDatabaseLoader::CloneStringToPool(std::string const& str)
{
    char* buf = new char[str.size() + 1];
    memcpy(buf, str.c_str(), str.size() + 1);
    _stringPool.push_back(buf);
    return buf;
}
