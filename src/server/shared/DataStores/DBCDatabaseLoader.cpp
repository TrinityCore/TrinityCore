/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
            case FT_SQL_ABSENT:
                break;
            default:
                ASSERT(false, "Invalid DB format string for '%s'", tableName);
                break;
        }
        --uIndexPos;
        ++fmt;
    }
    ASSERT(*fmt == FT_SQL_PRESENT, "Index column not present in format string for '%s'", tableName);
}

template <typename T>
void WriteField(void*& ptr, T val)
{
    T* coerced = static_cast<T*>(ptr);
    *coerced = val;
    ptr = static_cast<void*>(coerced + 1);
}
char* DBCDatabaseLoader::Load(uint32& records, char**& indexTable, Optional<uint32> onlyIndex)
{
    std::string query = onlyIndex ?
        Trinity::StringFormat("SELECT * FROM %s WHERE %s = %u;", _sqlTableName, _indexName, *onlyIndex) :
        Trinity::StringFormat("SELECT * FROM %s ORDER BY %s DESC;", _sqlTableName, _indexName);

    // no error if empty set
    QueryResult result = WorldDatabase.Query(query.c_str());
    if (!result)
        return nullptr;

    // Check if sql index pos is valid
    if (int32(result->GetFieldCount() - 1) < _sqlIndexPos)
    {
        ASSERT(false, "Invalid index pos for dbc: '%s'", _sqlTableName);
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

        uint32 indexValue = fields[_sqlIndexPos].GetUInt32();

        void* data = indexTable[indexValue];
        if (!data)
        {
            newIndexes[newRecords] = indexValue;
            data = &dataTable[newRecords * _recordSize];
            ++newRecords;
        }
        else
        {
            // Attempt to overwrite existing data
            ASSERT(false, "Index %d already exists in dbc:'%s'", indexValue, _sqlTableName);
            return nullptr;
        }

        uint32 sqlColumnNumber = 0;
        char const* dbcFormat = _dbcFormat;
        char const* sqlFormat = _formatString;
        for (; (*dbcFormat || *sqlFormat); ++dbcFormat, ++sqlFormat)
        {
            if (!*dbcFormat || !*sqlFormat)
            {
                ASSERT(false, "DB and DBC format strings do not have the same length for '%s'", _sqlTableName);
                return nullptr;
            }
            switch (*sqlFormat)
            {
                case FT_SQL_PRESENT:
                    switch (*dbcFormat)
                    {
                        case FT_FLOAT:
                            WriteField(data, fields[sqlColumnNumber].GetFloat());
                            break;
                        case FT_IND:
                        case FT_INT:
                            WriteField(data, fields[sqlColumnNumber].GetUInt32());
                            break;
                        case FT_BYTE:
                            WriteField(data, fields[sqlColumnNumber].GetUInt8());
                            break;
                        case FT_STRING:
                            WriteField(data, CloneStringToPool(fields[sqlColumnNumber].GetString()));
                            break;
                        case FT_SORT:
                            break;
                        default:
                            ASSERT(false, "Unsupported data type '%c' marked present in table '%s'", *dbcFormat, _sqlTableName);
                            return nullptr;
                    }
                    ++sqlColumnNumber;
                    break;
                case FT_SQL_ABSENT:
                    switch (*dbcFormat)
                    {
                        case FT_FLOAT:
                            WriteField(data, 0.0f);
                            break;
                        case FT_IND:
                        case FT_INT:
                            WriteField(data, uint32(0));
                            break;
                        case FT_BYTE:
                            WriteField(data, uint8(0));
                            break;
                        case FT_STRING:
                            WriteField(data, "");
                            break;
                    }
                    break;
                default:
                    ASSERT(false, "Invalid DB format string for '%s'", _sqlTableName);
                    break;
            }
        }
        ASSERT(sqlColumnNumber == result->GetFieldCount(), "SQL format string does not match database for table: '%s'", _sqlTableName);
    } while (result->NextRow());

    ASSERT(newRecords == result->GetRowCount());

    // insert new records to index table
    for (uint32 i = 0; i < newRecords; ++i)
        indexTable[newIndexes[i]] = &dataTable[i * _recordSize];

    records = indexTableSize;

    return dataTable.release();
}

template <typename T>
T ReadField(void*& ptr)
{
    T* coerced = reinterpret_cast<T*>(ptr);
    T value = *coerced;
    ptr = reinterpret_cast<void*>(coerced + 1);
    return value;
}
bool DBCDatabaseLoader::Save(uint32 indexValue, void* entry)
{
    SQLTransaction trans = WorldDatabase.BeginTransaction();
    trans->PAppend("DELETE FROM %s WHERE %s = %u", _sqlTableName, _indexName, indexValue);

    std::ostringstream insertQuery;
    insertQuery << Trinity::StringFormat("INSERT INTO %s VALUES (", _sqlTableName);
    char const* dbcFormat = _dbcFormat;
    char const* sqlFormat = _formatString;
    for (; (*dbcFormat || *sqlFormat); ++dbcFormat, ++sqlFormat)
    {
        if (!*dbcFormat || !*sqlFormat)
        {
            ASSERT(false, "DB and DBC format strings do not have the same length for '%s'", _sqlTableName);
            return nullptr;
        }
        bool doAppend = (*sqlFormat == FT_SQL_PRESENT);
        switch (*dbcFormat)
        {
            case FT_FLOAT:
                if (doAppend)
                    insertQuery << ReadField<float>(entry);
                else
                    ReadField<float>(entry);
                break;
            case FT_IND:
            case FT_INT:
                if (doAppend)
                    insertQuery << ReadField<uint32>(entry);
                else
                    ReadField<uint32>(entry);
                break;
            case FT_BYTE:
                if (doAppend)
                    insertQuery << ReadField<uint8>(entry);
                else
                    ReadField<uint8>(entry);
                break;
            case FT_STRING:
            {
                if (doAppend)
                {
                    std::string s(ReadField<char*>(entry));
                    WorldDatabase.EscapeString(s);
                    insertQuery << "\"" << s << "\"";
                }
                else
                    ReadField<char*>(entry);
                break;
            }
            case FT_SORT:
                break;
            default:
                ASSERT(!doAppend, "Unsupported data type '%c' marked present in table '%s'", *dbcFormat, _sqlTableName);
                break;
        }
        if (doAppend)
            insertQuery << ",";
    }

    insertQuery.seekp(-1, std::ios_base::end); // overwrite superfluous comma
    insertQuery << ")";

    printf("Write query:\n%s\n", insertQuery.str().c_str());

    trans->Append(insertQuery.str().c_str());

    WorldDatabase.DirectCommitTransaction(trans);
    return true;
}

char* DBCDatabaseLoader::CloneStringToPool(std::string const& str)
{
    char* buf = new char[str.size() + 1];
    memcpy(buf, str.c_str(), str.size() + 1);
    _stringPool.push_back(buf);
    return buf;
}
