/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "Common.h"
#include "DB2StorageLoader.h"
#include "Database/DatabaseEnv.h"
#include "Log.h"

DB2FileLoader::DB2FileLoader()
{
    fileName = nullptr;
    meta = nullptr;

    recordSize = 0;
    recordCount = 0;
    fieldCount = 0;
    stringSize = 0;
    tableHash = 0;
    layoutHash = 0;
    minIndex = 0;
    maxIndex = 0;
    localeMask = 0;
    copyIdSize = 0;

    data = nullptr;
    stringTable = nullptr;
    idTable = nullptr;
    idTableSize = 0;
    copyTable = nullptr;
    fields = nullptr;
}

bool DB2FileLoader::Load(char const* filename, DB2Meta const* meta)
{
    if (data)
    {
        delete[] data;
        data = nullptr;
    }

    FILE* f = fopen(filename, "rb");
    if (!f)
        return false;

    fileName = filename;
    this->meta = meta;
    uint32 header;
    if (fread(&header, 4, 1, f) != 1)                       // Signature
    {
        fclose(f);
        return false;
    }

    EndianConvert(header);

    if (header != 0x35424457)
    {
        fclose(f);
        return false;                                       //'WDB5'
    }

    if (fread(&recordCount, 4, 1, f) != 1)                  // Number of records
    {
        fclose(f);
        return false;
    }

    EndianConvert(recordCount);

    if (fread(&fieldCount, 4, 1, f) != 1)                   // Number of fields
    {
        fclose(f);
        return false;
    }

    EndianConvert(fieldCount);

    if (fread(&recordSize, 4, 1, f) != 1)                   // Size of a record
    {
        fclose(f);
        return false;
    }

    EndianConvert(recordSize);

    if (fread(&stringSize, 4, 1, f) != 1)                   // String size
    {
        fclose(f);
        return false;
    }

    EndianConvert(stringSize);

    if (fread(&tableHash, 4, 1, f) != 1)                    // Table hash
    {
        fclose(f);
        return false;
    }

    EndianConvert(tableHash);

    if (fread(&layoutHash, 4, 1, f) != 1)                   // Build
    {
        fclose(f);
        return false;
    }

    if (layoutHash != meta->LayoutHash)
    {
        fclose(f);
        return false;
    }

    EndianConvert(layoutHash);

    if (fread(&minIndex, 4, 1, f) != 1)                     // MinIndex WDB2
    {
        fclose(f);
        return false;
    }

    EndianConvert(minIndex);

    if (fread(&maxIndex, 4, 1, f) != 1)                     // MaxIndex WDB2
    {
        fclose(f);
        return false;
    }

    EndianConvert(maxIndex);

    if (fread(&localeMask, 4, 1, f) != 1)                   // Locales
    {
        fclose(f);
        return false;
    }

    EndianConvert(localeMask);

    if (fread(&copyIdSize, 4, 1, f) != 1)
    {
        fclose(f);
        return false;
    }

    EndianConvert(copyIdSize);

    if (fread(&metaFlags, 4, 1, f) != 1)
    {
        fclose(f);
        return false;
    }

    EndianConvert(metaFlags);

    ASSERT((metaFlags & 0x1) == 0, "%s is a sparse storage, use DB2SparseStorage!", filename);
    ASSERT((meta->IndexField == -1) || (meta->IndexField == int32(metaFlags >> 16)));

    fields = new FieldEntry[fieldCount];
    if (fread(fields, fieldCount * sizeof(FieldEntry), 1, f) != 1)
    {
        fclose(f);
        return false;
    }

    if (!meta->HasIndexFieldInData())
        idTableSize = recordCount * sizeof(uint32);

    data = new unsigned char[recordSize * recordCount + stringSize];
    stringTable = data + recordSize * recordCount;

    if (fread(data, recordSize * recordCount + stringSize, 1, f) != 1)
    {
        fclose(f);
        return false;
    }

    if (idTableSize)
    {
        idTable = new unsigned char[idTableSize];
        if (fread(idTable, idTableSize, 1, f) != 1)
        {
            fclose(f);
            return false;
        }
    }

    if (copyIdSize)
    {
        copyTable = new unsigned char[copyIdSize];
        if (fread(copyTable, copyIdSize, 1, f) != 1)
        {
            fclose(f);
            return false;
        }
    }

    fclose(f);
    return true;
}

DB2FileLoader::~DB2FileLoader()
{
    delete[] data;
    delete[] idTable;
    delete[] copyTable;
    delete[] fields;
}

DB2FileLoader::Record DB2FileLoader::getRecord(size_t id)
{
    assert(data);
    return Record(*this, data + id * recordSize);
}

char* DB2FileLoader::AutoProduceData(uint32& records, char**& indexTable)
{
    typedef char* ptr;
    if (meta->FieldCount != fieldCount)
        return NULL;

    //get struct size and index pos
    uint32 indexField = meta->GetIndexField();
    uint32 recordsize = meta->GetRecordSize();

    uint32 maxi = 0;
    //find max index
    if (!idTableSize)
    {
        for (uint32 y = 0; y < recordCount; ++y)
        {
            uint32 ind = getRecord(y).getUInt(indexField, 0);
            if (ind > maxi)
                maxi = ind;
        }
    }
    else
    {
        for (uint32 y = 0; y < recordCount; ++y)
        {
            uint32 ind = ((uint32*)idTable)[y];
            if (ind > maxi)
                maxi = ind;
        }
    }

    for (uint32 y = 0; y < copyIdSize; y += 8)
    {
        uint32 ind = *((uint32*)(copyTable + y));
        if (ind > maxi)
            maxi = ind;
    }

    ++maxi;
    records = maxi;
    indexTable = new ptr[maxi];
    memset(indexTable, 0, maxi * sizeof(ptr));

    char* dataTable = new char[(recordCount + (copyIdSize / 8)) * recordsize];

    uint32 offset = 0;

    for (uint32 y = 0; y < recordCount; y++)
    {
        Record rec = getRecord(y);
        uint32 indexVal = meta->HasIndexFieldInData() ? rec.getUInt(indexField, 0) : ((uint32*)idTable)[y];

        indexTable[indexVal] = &dataTable[offset];

        if (!meta->HasIndexFieldInData())
        {
            *((uint32*)(&dataTable[offset])) = indexVal;
            offset += 4;
        }

        for (uint32 x = 0; x < fieldCount; ++x)
        {
            for (uint32 z = 0; z < meta->ArraySizes[x]; ++z)
            {
                switch (meta->Types[x])
                {
                    case FT_FLOAT:
                        *((float*)(&dataTable[offset])) = rec.getFloat(x, z);
                        offset += 4;
                        break;
                    case FT_INT:
                        *((uint32*)(&dataTable[offset])) = rec.getUInt(x, z);
                        offset += 4;
                        break;
                    case FT_BYTE:
                        *((uint8*)(&dataTable[offset])) = rec.getUInt8(x, z);
                        offset += 1;
                        break;
                    case FT_SHORT:
                        *((uint16*)(&dataTable[offset])) = rec.getUInt16(x, z);
                        offset += 2;
                        break;
                    case FT_STRING:
                    case FT_STRING_NOT_LOCALIZED:
                        *((char**)(&dataTable[offset])) = nullptr;   // will be replaced by non-empty or "" strings in AutoProduceStrings
                        offset += sizeof(char*);
                        break;
                    default:
                        ASSERT(false, "Unknown format character '%c' found in %s meta", meta->Types[x], fileName);
                        break;
                }
            }
        }
    }

    return dataTable;
}

static char const* const nullStr = "";

char* DB2FileLoader::AutoProduceStringsArrayHolders(char* dataTable)
{
    if (meta->FieldCount != fieldCount)
        return nullptr;

    // we store flat holders pool as single memory block
    std::size_t stringFields = meta->GetStringFieldCount(false);
    if (!stringFields)
        return nullptr;

    std::size_t localizedStringFields = meta->GetStringFieldCount(true);

    // each string field at load have array of string for each locale
    std::size_t stringHoldersRecordPoolSize = localizedStringFields * sizeof(LocalizedString) + (stringFields - localizedStringFields) * sizeof(char*);
    std::size_t stringHoldersPoolSize = stringHoldersRecordPoolSize * recordCount;

    char* stringHoldersPool = new char[stringHoldersPoolSize];

    // DB2 strings expected to have at least empty string
    for (std::size_t i = 0; i < stringHoldersPoolSize / sizeof(char*); ++i)
        ((char const**)stringHoldersPool)[i] = nullStr;

    uint32 offset = 0;

    // assign string holders to string field slots
    for (uint32 y = 0; y < recordCount; y++)
    {
        uint32 stringFieldOffset = 0;

        if (!meta->HasIndexFieldInData())
            offset += 4;

        for (uint32 x = 0; x < fieldCount; ++x)
        {
            for (uint32 z = 0; z < meta->ArraySizes[x]; ++z)
            {
                switch (meta->Types[x])
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
                    case FT_STRING:
                    case FT_STRING_NOT_LOCALIZED:
                    {
                        // init db2 string field slots by pointers to string holders
                        char const*** slot = (char const***)(&dataTable[offset]);
                        *slot = (char const**)(&stringHoldersPool[stringHoldersRecordPoolSize * y + stringFieldOffset]);
                        if (meta->Types[x] == FT_STRING)
                            stringFieldOffset += sizeof(LocalizedString);
                        else
                            stringFieldOffset += sizeof(char*);

                        offset += sizeof(char*);
                        break;
                    }
                    default:
                        ASSERT(false, "Unknown format character '%c' found in %s meta", meta->Types[x], fileName);
                        break;
                }
            }
        }
    }

    //send as char* for store in char* pool list for free at unload
    return stringHoldersPool;
}

char* DB2FileLoader::AutoProduceStrings(char* dataTable, uint32 locale)
{
    if (meta->FieldCount != fieldCount)
        return nullptr;

    if (!(localeMask & (1 << locale)))
    {
        char const* sep = "";
        std::ostringstream str;
        for (uint32 i = 0; i < TOTAL_LOCALES; ++i)
        {
            if (localeMask & (1 << i))
            {
                str << sep << localeNames[i];
                sep = ", ";
            }
        }

        TC_LOG_ERROR("", "Attempted to load %s which has locales %s as %s. Check if you placed your localized db2 files in correct directory.", fileName, str.str().c_str(), localeNames[locale]);
        return nullptr;
    }

    char* stringPool = new char[stringSize];
    memcpy(stringPool, stringTable, stringSize);

    uint32 offset = 0;

    for (uint32 y = 0; y < recordCount; y++)
    {
        if (!meta->HasIndexFieldInData())
            offset += 4;

        for (uint32 x = 0; x < fieldCount; ++x)
        {
            for (uint32 z = 0; z < meta->ArraySizes[x]; ++z)
            {
                switch (meta->Types[x])
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
                    case FT_STRING:
                    {
                        // fill only not filled entries
                        LocalizedString* db2str = *(LocalizedString**)(&dataTable[offset]);
                        if (db2str->Str[locale] == nullStr)
                        {
                            char const* st = getRecord(y).getString(x, z);
                            db2str->Str[locale] = stringPool + (st - (char const*)stringTable);
                        }

                        offset += sizeof(char*);
                        break;
                    }
                    case FT_STRING_NOT_LOCALIZED:
                    {
                        char** db2str = (char**)(&dataTable[offset]);
                        char const* st = getRecord(y).getString(x, z);
                        *db2str = stringPool + (st - (char const*)stringTable);
                        offset += sizeof(char*);
                        break;
                    }
                    default:
                        ASSERT(false, "Unknown format character '%c' found in %s meta", meta->Types[x], fileName);
                        break;
                }
            }
        }
    }

    return stringPool;
}

void DB2FileLoader::AutoProduceRecordCopies(uint32 records, char** indexTable, char* dataTable)
{
    uint32 recordsize = meta->GetRecordSize();
    uint32 offset = recordCount * recordsize;
    uint32* copyIds = (uint32*)copyTable;
    for (uint32 c = 0; c < copyIdSize / 4; c += 2)
    {
        uint32 to = copyIds[c];
        uint32 from = copyIds[c + 1];

        if (from && from < records && indexTable[from])
        {
            indexTable[to] = &dataTable[offset];
            memcpy(indexTable[to], indexTable[from], recordsize);

            if (meta->HasIndexFieldInData())
                *((uint32*)(&dataTable[offset + fields[meta->GetIndexField()].Offset])) = to;
            else
                *((uint32*)(&dataTable[offset])) = to;

            offset += recordsize;
        }
    }
}

char* DB2DatabaseLoader::Load(HotfixDatabaseStatements preparedStatement, uint32& records, char**& indexTable, char*& stringHolders, std::vector<char*>& stringPool)
{
    // Even though this query is executed only once, prepared statement is used to send data from mysql server in binary format
    PreparedQueryResult result = HotfixDatabase.Query(HotfixDatabase.GetPreparedStatement(preparedStatement));
    if (!result)
        return nullptr;

    if (_meta->GetDbFieldCount() != result->GetFieldCount())
        return nullptr;

    // get struct size and index pos
    uint32 indexField = _meta->GetDbIndexField();
    uint32 recordSize = _meta->GetRecordSize();

    // we store flat holders pool as single memory block
    std::size_t stringFields = _meta->GetStringFieldCount(false);
    std::size_t localizedStringFields = _meta->GetStringFieldCount(true);

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
    // database query *MUST* contain ORDER BY `index_field` DESC clause
    uint32 indexTableSize = (*result)[indexField].GetUInt32() + 1;
    if (indexTableSize < records)
        indexTableSize = records;

    if (indexTableSize > records)
    {
        char** tmpIdxTable = new char*[indexTableSize];
        memset(tmpIdxTable, 0, indexTableSize * sizeof(char*));
        memcpy(tmpIdxTable, indexTable, records * sizeof(char*));
        delete[] indexTable;
        indexTable = tmpIdxTable;
    }

    char* tempDataTable = new char[result->GetRowCount() * recordSize];
    uint32* newIndexes = new uint32[result->GetRowCount()];
    uint32 rec = 0;
    uint32 newRecords = 0;

    do
    {
        Field* fields = result->Fetch();
        uint32 offset = 0;
        uint32 stringFieldOffset = 0;

        uint32 indexValue = fields[indexField].GetUInt32();

        // Attempt to overwrite existing data
        char* dataValue = indexTable[indexValue];
        if (!dataValue)
        {
            newIndexes[newRecords] = indexValue;
            dataValue = &tempDataTable[newRecords++ * recordSize];
        }

        uint32 f = 0;
        if (!_meta->HasIndexFieldInData())
        {
            *((uint32*)(&dataValue[offset])) = indexValue;
            offset += 4;
            ++f;
        }

        for (uint32 x = 0; x < _meta->FieldCount; ++x)
        {
            for (uint32 z = 0; z < _meta->ArraySizes[x]; ++z)
            {
                switch (_meta->Types[x])
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
                    case FT_STRING:
                    {
                        LocalizedString** slot = (LocalizedString**)(&dataValue[offset]);
                        *slot = (LocalizedString*)(&stringHolders[stringHoldersRecordPoolSize * rec + stringFieldOffset]);
                        ASSERT(*slot);

                        // Value in database in main table field must be for enUS locale
                        if (char* str = AddString(&(*slot)->Str[LOCALE_enUS], fields[f].GetString()))
                            stringPool.push_back(str);

                        stringFieldOffset += sizeof(LocalizedString);
                        offset += sizeof(char*);
                        break;
                    }
                    case FT_STRING_NOT_LOCALIZED:
                    {
                        char const** slot = (char const**)(&dataValue[offset]);
                        *slot = (char*)(&stringHolders[stringHoldersRecordPoolSize * rec + stringFieldOffset]);
                        ASSERT(*slot);

                        // Value in database in main table field must be for enUS locale
                        if (char* str = AddString(slot, fields[f].GetString()))
                            stringPool.push_back(str);

                        stringFieldOffset += sizeof(char*);
                        offset += sizeof(char*);
                        break;
                    }
                    default:
                        ASSERT(false, "Unknown format character '%c' found in %s meta", _meta->Types[x], _storageName.c_str());
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

void DB2DatabaseLoader::LoadStrings(HotfixDatabaseStatements preparedStatement, uint32 locale, uint32 records, char** indexTable, std::vector<char*>& stringPool)
{
    PreparedStatement* stmt = HotfixDatabase.GetPreparedStatement(preparedStatement);
    stmt->setString(0, localeNames[locale]);
    PreparedQueryResult result = HotfixDatabase.Query(stmt);
    if (!result)
        return;

    std::size_t stringFields = _meta->GetStringFieldCount(true);
    if (result->GetFieldCount() != stringFields + 1 /*ID*/)
        return;

    uint32 fieldCount = _meta->FieldCount;
    uint32 recordSize = _meta->GetRecordSize();

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
            if (!_meta->HasIndexFieldInData())
                offset += 4;

            for (uint32 x = 0; x < fieldCount; ++x)
            {
                for (uint32 z = 0; z < _meta->ArraySizes[x]; ++z)
                {
                    switch (_meta->Types[x])
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
                        case FT_STRING:
                        {
                            // fill only not filled entries
                            LocalizedString* db2str = *(LocalizedString**)(&dataValue[offset]);
                            if (db2str->Str[locale] == nullStr)
                                if (char* str = AddString(&db2str->Str[locale], fields[1 + stringFieldNumInRecord].GetString()))
                                    stringPool.push_back(str);

                            ++stringFieldNumInRecord;
                            offset += sizeof(LocalizedString*);
                            break;
                        }
                        case FT_STRING_NOT_LOCALIZED:
                            offset += sizeof(char*);
                            break;
                        default:
                            ASSERT(false, "Unknown format character '%c' found in %s meta", _meta->Types[x], _storageName.c_str());
                            break;
                    }
                }
            }

            ASSERT(offset == recordSize);
        }
        else
            TC_LOG_ERROR("sql.sql", "Hotfix locale table for storage %s references row that does not exist %u locale %s!", _storageName.c_str(), indexValue, localeNames[locale]);

    } while (result->NextRow());

    return;
}

char* DB2DatabaseLoader::AddString(char const** holder, std::string const& value)
{
    if (!value.empty())
    {
        std::size_t existingLength = strlen(*holder);
        if (existingLength >= value.length())
        {
            // Reuse existing storage if there is enough space
            char* str = const_cast<char*>(*holder);
            memcpy(str, value.c_str(), value.length());
            str[value.length()] = '\0';
            return nullptr;
        }

        char* str = new char[value.length() + 1];
        memcpy(str, value.c_str(), value.length());
        str[value.length()] = '\0';
        *holder = str;
        return str;
    }

    return nullptr;
}
