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

#include "DB2DatabaseLoader.h"
#include "Common.h"
#include "DatabaseEnv.h"
#include "DB2Meta.h"
#include "Errors.h"
#include "Log.h"

DB2LoadInfo::DB2LoadInfo(DB2FieldMeta const* fields, std::size_t fieldCount, DB2Meta const* meta, HotfixDatabaseStatements statement)
    : DB2FileLoadInfo(fields, fieldCount, meta), Statement(statement)
{
}

static char const* nullStr = "";

char* DB2DatabaseLoader::Load(bool custom, uint32& records, char**& indexTable, char*& stringHolders, std::vector<char*>& stringPool)
{
    // Even though this query is executed only once, prepared statement is used to send data from mysql server in binary format
    HotfixDatabasePreparedStatement* stmt = HotfixDatabase.GetPreparedStatement(_loadInfo->Statement);
    stmt->setBool(0, !custom);
    PreparedQueryResult result = HotfixDatabase.Query(stmt);
    if (!result)
        return nullptr;

    if (_loadInfo->Meta->GetDbFieldCount() != result->GetFieldCount())
        return nullptr;

    // get struct size and index pos
    uint32 indexField = _loadInfo->Meta->GetDbIndexField();
    uint32 recordSize = _loadInfo->Meta->GetRecordSize();

    // we store flat holders pool as single memory block
    std::size_t stringFields = _loadInfo->GetStringFieldCount(false);
    std::size_t localizedStringFields = _loadInfo->GetStringFieldCount(true);

    // each string field at load have array of string for each locale
    std::size_t stringHoldersRecordPoolSize = localizedStringFields * sizeof(LocalizedString) + (stringFields - localizedStringFields) * sizeof(char*);

    if (stringFields)
    {
        std::size_t stringHoldersPoolSize = stringHoldersRecordPoolSize * result->GetRowCount();
        stringHolders = new char[stringHoldersPoolSize];

        // DB2 strings expected to have at least empty string
        for (std::size_t i = 0; i < stringHoldersPoolSize / sizeof(char*); ++i)
            ((char const**)stringHolders)[i] = nullStr;
    }
    else
        stringHolders = nullptr;

    // Resize index table
    uint32 indexTableSize = records;
    if (PreparedQueryResult maxIdResult = HotfixDatabase.Query(HotfixDatabase.GetPreparedStatement(HotfixDatabaseStatements(_loadInfo->Statement + HOTFIX_MAX_ID_STMT_OFFSET))))
        if (uint32((*maxIdResult)[0].GetUInt64()) > records)
            indexTableSize = uint32((*maxIdResult)[0].GetUInt64());

    if (indexTableSize > records)
    {
        char** tmpIdxTable = new char*[indexTableSize];
        memset(tmpIdxTable, 0, indexTableSize * sizeof(char*));
        memcpy(tmpIdxTable, indexTable, records * sizeof(char*));
        delete[] indexTable;
        indexTable = tmpIdxTable;
    }

    char* tempDataTable = new char[result->GetRowCount() * recordSize];
    memset(tempDataTable, 0, result->GetRowCount() * recordSize);
    uint32* newIndexes = new uint32[result->GetRowCount()];
    if (stringFields)
        stringPool.reserve(std::max(stringPool.capacity(), stringPool.size() + stringFields * result->GetRowCount() + 1));

    uint32 rec = 0;
    uint32 newRecords = 0;

    do
    {
        Field* fields = result->Fetch();
        uint32 offset = 0;

        uint32 indexValue = fields[indexField].GetUInt32();
        bool isNew = false;

        // Attempt to overwrite existing data
        char* dataValue = indexTable[indexValue];
        if (!dataValue)
        {
            newIndexes[newRecords] = indexValue;
            dataValue = &tempDataTable[newRecords++ * recordSize];
            isNew = true;
        }

        uint32 f = 0;
        if (!_loadInfo->Meta->HasIndexFieldInData())
        {
            *((uint32*)(&dataValue[offset])) = indexValue;
            offset += 4;
            ++f;
        }

        for (uint32 x = 0; x < _loadInfo->Meta->FieldCount; ++x)
        {
            for (uint32 z = 0; z < _loadInfo->Meta->Fields[x].ArraySize; ++z)
            {
                switch (_loadInfo->TypesString[f])
                {
                    case FT_FLOAT:
                        *((float*)(&dataValue[offset])) = fields[f].GetFloat();
                        offset += 4;
                        break;
                    case FT_INT:
                        *((int32*)(&dataValue[offset])) = fields[f].GetInt32();
                        offset += 4;
                        break;
                    case FT_BYTE:
                        *((int8*)(&dataValue[offset])) = fields[f].GetInt8();
                        offset += 1;
                        break;
                    case FT_SHORT:
                        *((int16*)(&dataValue[offset])) = fields[f].GetInt16();
                        offset += 2;
                        break;
                    case FT_LONG:
                        *((int64*)(&dataValue[offset])) = fields[f].GetInt64();
                        offset += 8;
                        break;
                    case FT_STRING:
                    {
                        LocalizedString* slot = (LocalizedString*)(&dataValue[offset]);
                        if (isNew)
                            for (char const*& localeStr : slot->Str)
                                localeStr = nullStr;

                        // Value in database in main table field must be for enUS locale
                        if (char* str = AddString(&slot->Str[LOCALE_enUS], fields[f].GetString()))
                            stringPool.push_back(str);

                        offset += sizeof(LocalizedString);
                        break;
                    }
                    case FT_STRING_NOT_LOCALIZED:
                    {
                        char const** slot = (char const**)(&dataValue[offset]);

                        // Value in database in main table field must be for enUS locale
                        if (char* str = AddString(slot, fields[f].GetString()))
                            stringPool.push_back(str);
                        else
                            *slot = nullStr;

                        offset += sizeof(char*);
                        break;
                    }
                    default:
                        ASSERT(false, "Unknown format character '%c' found in %s meta for field %s",
                            _loadInfo->TypesString[f], _storageName.c_str(), _loadInfo->Fields[f].Name);
                        break;
                }
                ++f;
            }
        }

        ASSERT(offset == recordSize);
        ++rec;
    } while (result->NextRow());

    if (!newRecords)
    {
        delete[] tempDataTable;
        delete[] newIndexes;
        return nullptr;
    }

    // Compact new data table to only contain new records not previously loaded from file
    char* dataTable = new char[newRecords * recordSize];
    memcpy(dataTable, tempDataTable, newRecords * recordSize);

    // insert new records to index table
    for (uint32 i = 0; i < newRecords; ++i)
        indexTable[newIndexes[i]] = &dataTable[i * recordSize];

    delete[] tempDataTable;
    delete[] newIndexes;

    records = indexTableSize;

    return dataTable;
}

void DB2DatabaseLoader::LoadStrings(bool custom, LocaleConstant locale, uint32 records, char** indexTable, std::vector<char*>& stringPool)
{
    HotfixDatabasePreparedStatement* stmt = HotfixDatabase.GetPreparedStatement(HotfixDatabaseStatements(_loadInfo->Statement + HOTFIX_LOCALE_STMT_OFFSET));
    stmt->setBool(0, !custom);
    stmt->setString(1, localeNames[locale]);
    PreparedQueryResult result = HotfixDatabase.Query(stmt);
    if (!result)
        return;

    std::size_t stringFields = _loadInfo->GetStringFieldCount(true);
    if (result->GetFieldCount() != stringFields + 1 /*ID*/)
        return;

    uint32 fieldCount = _loadInfo->Meta->FieldCount;
    uint32 recordSize = _loadInfo->Meta->GetRecordSize();

    stringPool.reserve(std::max(stringPool.capacity(), stringPool.size() + stringFields * result->GetRowCount() + 1));

    do
    {
        Field* fields = result->Fetch();
        uint32 offset = 0;
        uint32 stringFieldNumInRecord = 0;
        uint32 indexValue = fields[0].GetUInt32();

        if (indexValue >= records)
            continue;

        // Attempt to overwrite existing data
        if (char* dataValue = indexTable[indexValue])
        {
            uint32 fieldIndex = 0;
            if (!_loadInfo->Meta->HasIndexFieldInData())
            {
                offset += 4;
                ++fieldIndex;
            }

            for (uint32 x = 0; x < fieldCount; ++x)
            {
                for (uint32 z = 0; z < _loadInfo->Meta->Fields[x].ArraySize; ++z)
                {
                    switch (_loadInfo->TypesString[fieldIndex])
                    {
                        case FT_FLOAT:
                        case FT_INT:
                            offset += 4;
                            break;
                        case FT_BYTE:
                            offset += 1;
                            break;
                        case FT_SHORT:
                            offset += 2;
                            break;
                        case FT_LONG:
                            offset += 8;
                            break;
                        case FT_STRING:
                        {
                            // fill only not filled entries
                            LocalizedString* db2str = (LocalizedString*)(&dataValue[offset]);
                            if (char* str = AddString(&db2str->Str[locale], fields[1 + stringFieldNumInRecord].GetString()))
                                stringPool.push_back(str);

                            ++stringFieldNumInRecord;
                            offset += sizeof(LocalizedString);
                            break;
                        }
                        case FT_STRING_NOT_LOCALIZED:
                            offset += sizeof(char*);
                            break;
                        default:
                            ASSERT(false, "Unknown format character '%c' found in %s meta for field %s",
                                _loadInfo->TypesString[fieldIndex], _storageName.c_str(), _loadInfo->Fields[fieldIndex].Name);
                            break;
                    }
                    ++fieldIndex;
                }
            }

            ASSERT(offset == recordSize);
        }
        else
            TC_LOG_ERROR("sql.sql", "Hotfix locale table for storage %s references row that does not exist %u locale %s!", _storageName.c_str(), indexValue, localeNames[locale]);

    } while (result->NextRow());
}

char* DB2DatabaseLoader::AddString(char const** holder, std::string const& value)
{
    if (!value.empty())
    {
        char* str = new char[value.length() + 1];
        memcpy(str, value.c_str(), value.length());
        str[value.length()] = '\0';
        *holder = str;
        return str;
    }

    return nullptr;
}
