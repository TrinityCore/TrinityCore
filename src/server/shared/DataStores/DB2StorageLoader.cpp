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
    recordSize = 0;
    recordCount = 0;
    fieldCount = 0;
    stringSize = 0;
    fieldsOffset = nullptr;
    data = nullptr;
    stringTable = nullptr;

    tableHash = 0;
    build = 0;

    unk1 = 0;
    minIndex = 0;
    maxIndex = 0;
    localeMask = 0;
    unk5 = 0;
}

bool DB2FileLoader::Load(const char *filename, const char *fmt)
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
    uint32 header;
    if (fread(&header, 4, 1, f) != 1)                        // Signature
    {
        fclose(f);
        return false;
    }

    EndianConvert(header);

    if (header != 0x32424457)
    {
        fclose(f);
        return false;                                       //'WDB2'
    }

    if (fread(&recordCount, 4, 1, f) != 1)                 // Number of records
    {
        fclose(f);
        return false;
    }

    EndianConvert(recordCount);

    if (fread(&fieldCount, 4, 1, f) != 1)                 // Number of fields
    {
        fclose(f);
        return false;
    }

    EndianConvert(fieldCount);

    if (fread(&recordSize, 4, 1, f) != 1)                 // Size of a record
    {
        fclose(f);
        return false;
    }

    EndianConvert(recordSize);

    if (fread(&stringSize, 4, 1, f) != 1)                 // String size
    {
        fclose(f);
        return false;
    }

    EndianConvert(stringSize);

    /* NEW WDB2 FIELDS*/
    if (fread(&tableHash, 4, 1, f) != 1)                  // Table hash
    {
        fclose(f);
        return false;
    }

    EndianConvert(tableHash);

    if (fread(&build, 4, 1, f) != 1)                     // Build
    {
        fclose(f);
        return false;
    }

    EndianConvert(build);

    if (fread(&unk1, 4, 1, f) != 1)                     // Unknown WDB2
    {
        fclose(f);
        return false;
    }

    EndianConvert(unk1);

    if (fread(&minIndex, 4, 1, f) != 1)                           // MinIndex WDB2
    {
        fclose(f);
        return false;
    }

    EndianConvert(minIndex);

    if (fread(&maxIndex, 4, 1, f) != 1)                           // MaxIndex WDB2
    {
        fclose(f);
        return false;
    }

    EndianConvert(maxIndex);

    if (fread(&localeMask, 4, 1, f) != 1)                             // Locales
    {
        fclose(f);
        return false;
    }

    EndianConvert(localeMask);

    if (fread(&unk5, 4, 1, f) != 1)                               // Unknown WDB2
    {
        fclose(f);
        return false;
    }

    EndianConvert(unk5);

    if (maxIndex != 0)
    {
        int32 diff = maxIndex - minIndex + 1;
        fseek(f, diff * 4 + diff * 2, SEEK_CUR);    // diff * 4: an index for rows, diff * 2: a memory allocation bank
    }

    fieldsOffset = new uint32[fieldCount];
    fieldsOffset[0] = 0;
    for (uint32 i = 1; i < fieldCount; i++)
    {
        fieldsOffset[i] = fieldsOffset[i - 1];
        if (fmt[i - 1] == FT_BYTE)  // byte fields
            fieldsOffset[i] += 1;
        else if (fmt[i - 1] == FT_LONG)
            fieldsOffset[i] += 8;
        else                                                // 4 byte fields (int32/float/strings)
            fieldsOffset[i] += 4;
    }

    data = new unsigned char[recordSize * recordCount + stringSize];
    stringTable = data + recordSize * recordCount;

    if (fread(data, recordSize * recordCount + stringSize, 1, f) != 1)
    {
        fclose(f);
        return false;
    }

    fclose(f);
    return true;
}

DB2FileLoader::~DB2FileLoader()
{
    if (data)
        delete [] data;
    if (fieldsOffset)
        delete [] fieldsOffset;
}

DB2FileLoader::Record DB2FileLoader::getRecord(size_t id)
{
    assert(data);
    return Record(*this, data + id*recordSize);
}

uint32 DB2FileLoader::GetFormatRecordSize(const char * format, int32* index_pos)
{
    uint32 recordsize = 0;
    int32 i = -1;
    for (uint32 x=0; format[x]; ++x)
    {
        switch (format[x])
        {
            case FT_FLOAT:
            case FT_INT:
                recordsize += 4;
                break;
            case FT_STRING:
            case FT_STRING_NOT_LOCALIZED:
                recordsize += sizeof(char*);
                break;
            case FT_SORT:
                i = x;
                break;
            case FT_IND:
                i = x;
                recordsize += 4;
                break;
            case FT_BYTE:
                recordsize += 1;
                break;
            case FT_LONG:
                recordsize += 8;
                break;
        }
    }

    if (index_pos)
        *index_pos = i;

    return recordsize;
}

uint32 DB2FileLoader::GetFormatStringFieldCount(const char* format)
{
    uint32 stringfields = 0;
    for (uint32 x = 0; format[x]; ++x)
        if (format[x] == FT_STRING || format[x] == FT_STRING_NOT_LOCALIZED)
            ++stringfields;

    return stringfields;
}

uint32 DB2FileLoader::GetFormatLocalizedStringFieldCount(char const* format)
{
    uint32 stringfields = 0;
    for (uint32 x = 0; format[x]; ++x)
        if (format[x] == FT_STRING)
            ++stringfields;

    return stringfields;
}

char* DB2FileLoader::AutoProduceData(const char* format, uint32& records, char**& indexTable)
{
    typedef char * ptr;
    if (strlen(format) != fieldCount)
        return NULL;

    //get struct size and index pos
    int32 indexField;
    uint32 recordsize = GetFormatRecordSize(format, &indexField);

    if (indexField >= 0)
    {
        uint32 maxi = 0;
        //find max index
        for (uint32 y = 0; y < recordCount; y++)
        {
            uint32 ind = getRecord(y).getUInt(indexField);
            if (ind > maxi)
                maxi = ind;
        }

        ++maxi;
        records = maxi;
        indexTable = new ptr[maxi];
        memset(indexTable, 0, maxi * sizeof(ptr));
    }
    else
    {
        records = recordCount;
        indexTable = new ptr[recordCount];
    }

    char* dataTable = new char[recordCount * recordsize];

    uint32 offset = 0;

    for (uint32 y = 0; y < recordCount; y++)
    {
        if (indexField >= 0)
            indexTable[getRecord(y).getUInt(indexField)] = &dataTable[offset];
        else
            indexTable[y] = &dataTable[offset];

        for (uint32 x = 0; x < fieldCount; x++)
        {
            switch (format[x])
            {
                case FT_FLOAT:
                    *((float*)(&dataTable[offset])) = getRecord(y).getFloat(x);
                    offset += 4;
                    break;
                case FT_IND:
                case FT_INT:
                    *((uint32*)(&dataTable[offset])) = getRecord(y).getUInt(x);
                    offset += 4;
                    break;
                case FT_BYTE:
                    *((uint8*)(&dataTable[offset])) = getRecord(y).getUInt8(x);
                    offset += 1;
                    break;
                case FT_LONG:
                    *((uint64*)(&dataTable[offset])) = getRecord(y).getUInt64(x);
                    offset += 8;
                    break;
                case FT_STRING:
                case FT_STRING_NOT_LOCALIZED:
                    *((char**)(&dataTable[offset])) = nullptr;   // will be replaces non-empty or "" strings in AutoProduceStrings
                    offset += sizeof(char*);
                    break;
            }
        }
    }

    return dataTable;
}

static char const* const nullStr = "";

char* DB2FileLoader::AutoProduceStringsArrayHolders(const char* format, char* dataTable)
{
    if (strlen(format) != fieldCount)
        return nullptr;

    // we store flat holders pool as single memory block
    std::size_t stringFields = GetFormatStringFieldCount(format);
    if (!stringFields)
        return nullptr;

    std::size_t localizedStringFields = GetFormatLocalizedStringFieldCount(format);

    // each string field at load have array of string for each locale
    std::size_t stringHolderSize = sizeof(char*) * TOTAL_LOCALES;
    std::size_t stringHoldersRecordPoolSize = localizedStringFields * stringHolderSize + (stringFields - localizedStringFields) * sizeof(char*);
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

        for (uint32 x = 0; x < fieldCount; x++)
        {
            switch (format[x])
            {
                case FT_FLOAT:
                case FT_IND:
                case FT_INT:
                    offset += 4;
                    break;
                case FT_BYTE:
                    offset += 1;
                    break;
                case FT_LONG:
                    offset += 8;
                    break;
                case FT_STRING:
                case FT_STRING_NOT_LOCALIZED:
                {
                    // init db2 string field slots by pointers to string holders
                    char const*** slot = (char const***)(&dataTable[offset]);
                    *slot = (char const**)(&stringHoldersPool[stringHoldersRecordPoolSize * y + stringFieldOffset]);
                    if (format[x] == FT_STRING)
                        stringFieldOffset += stringHolderSize;
                    else
                        ++stringFieldOffset;

                    offset += sizeof(char*);
                    break;
                }
                default:
                    ASSERT(false, "unknown format character %c", format[x]);
            }
        }
    }

    //send as char* for store in char* pool list for free at unload
    return stringHoldersPool;
}

char* DB2FileLoader::AutoProduceStrings(const char* format, char* dataTable, uint32 locale)
{
    if (strlen(format) != fieldCount)
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
        for (uint32 x = 0; x < fieldCount; x++)
        {
            switch (format[x])
            {
                case FT_FLOAT:
                case FT_IND:
                case FT_INT:
                    offset += 4;
                    break;
                case FT_BYTE:
                    offset += 1;
                    break;
                case FT_LONG:
                    offset += 8;
                    break;
                case FT_STRING:
                {
                    // fill only not filled entries
                    LocalizedString* db2str = *(LocalizedString**)(&dataTable[offset]);
                    if (db2str->Str[locale] == nullStr)
                    {
                        char const* st = getRecord(y).getString(x);
                        db2str->Str[locale] = stringPool + (st - (char const*)stringTable);
                    }

                    offset += sizeof(char*);
                    break;
                }
                case FT_STRING_NOT_LOCALIZED:
                {
                    char** db2str = (char**)(&dataTable[offset]);
                    char const* st = getRecord(y).getString(x);
                    *db2str = stringPool + (st - (char const*)stringTable);
                    offset += sizeof(char*);
                    break;
                }
            }
        }
    }

    return stringPool;
}

char* DB2DatabaseLoader::Load(const char* format, HotfixDatabaseStatements preparedStatement, uint32& records, char**& indexTable, char*& stringHolders, std::list<char*>& stringPool)
{
    // Even though this query is executed only once, prepared statement is used to send data from mysql server in binary format
    PreparedQueryResult result = HotfixDatabase.Query(HotfixDatabase.GetPreparedStatement(preparedStatement));
    if (!result)
        return nullptr;

    uint32 const fieldCount = strlen(format);
    if (fieldCount != result->GetFieldCount())
        return nullptr;

    // get struct size and index pos
    int32 indexField;
    uint32 recordSize = DB2FileLoader::GetFormatRecordSize(format, &indexField);

    // we store flat holders pool as single memory block
    size_t stringFields = DB2FileLoader::GetFormatStringFieldCount(format);

    // each string field at load have array of string for each locale
    size_t stringHolderSize = sizeof(char*) * TOTAL_LOCALES;
    size_t stringHoldersRecordPoolSize = stringFields * stringHolderSize;

    if (stringFields)
    {
        size_t stringHoldersPoolSize = stringHoldersRecordPoolSize * result->GetRowCount();
        stringHolders = new char[stringHoldersPoolSize];

        // DB2 strings expected to have at least empty string
        for (size_t i = 0; i < stringHoldersPoolSize / sizeof(char*); ++i)
            ((char const**)stringHolders)[i] = nullStr;
    }
    else
        stringHolders = nullptr;

    // Resize index table
    // database query *MUST* contain ORDER BY `index_field` DESC clause
    uint32 indexTableSize;
    if (indexField >= 0)
    {
        indexTableSize = (*result)[indexField].GetUInt32() + 1;
        if (indexTableSize < records)
            indexTableSize = records;
    }
    else
        indexTableSize = records + result->GetRowCount();

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
        uint32 stringFieldNumInRecord = 0;

        uint32 indexValue;
        if (indexField >= 0)
            indexValue = fields[indexField].GetUInt32();
        else
            indexValue = records + rec;

        // Attempt to overwrite existing data
        char* dataValue = indexTable[indexValue];
        if (!dataValue)
        {
            newIndexes[newRecords] = indexValue;
            dataValue = &tempDataTable[newRecords++ * recordSize];
        }

        for (uint32 f = 0; f < fieldCount; f++)
        {
            switch (format[f])
            {
                case FT_FLOAT:
                    *((float*)(&dataValue[offset])) = fields[f].GetFloat();
                    offset += 4;
                    break;
                case FT_IND:
                case FT_INT:
                    *((int32*)(&dataValue[offset])) = fields[f].GetInt32();
                    offset += 4;
                    break;
                case FT_BYTE:
                    *((int8*)(&dataValue[offset])) = fields[f].GetInt8();
                    offset += 1;
                    break;
                case FT_LONG:
                    *((int64*)(&dataValue[offset])) = fields[f].GetInt64();
                    offset += 8;
                    break;
                case FT_STRING:
                {
                    LocalizedString** slot = (LocalizedString**)(&dataValue[offset]);
                    *slot = (LocalizedString*)(&stringHolders[stringHoldersRecordPoolSize * rec + stringHolderSize * stringFieldNumInRecord]);
                    ASSERT(*slot);

                    // Value in database in main table field must be for enUS locale
                    if (char* str = AddString(&(*slot)->Str[LOCALE_enUS], fields[f].GetString()))
                        stringPool.push_back(str);

                    ++stringFieldNumInRecord;
                    offset += sizeof(char*);
                    break;
                }
                case FT_STRING_NOT_LOCALIZED:
                {
                    char const** slot = (char const**)(&dataValue[offset]);
                    *slot = (char*)(&stringHolders[stringHoldersRecordPoolSize * rec + stringHolderSize * stringFieldNumInRecord]);
                    ASSERT(*slot);

                    // Value in database in main table field must be for enUS locale
                    if (char* str = AddString(slot, fields[f].GetString()))
                        stringPool.push_back(str);

                    ++stringFieldNumInRecord;
                    offset += sizeof(char*);
                    break;
                }
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

void DB2DatabaseLoader::LoadStrings(const char* format, HotfixDatabaseStatements preparedStatement, uint32 locale, char**& indexTable, std::list<char*>& stringPool)
{
    PreparedStatement* stmt = HotfixDatabase.GetPreparedStatement(preparedStatement);
    stmt->setString(0, localeNames[locale]);
    PreparedQueryResult result = HotfixDatabase.Query(stmt);
    if (!result)
        return;

    size_t stringFields = DB2FileLoader::GetFormatLocalizedStringFieldCount(format);
    if (result->GetFieldCount() != stringFields + 1 /*ID*/)
        return;

    uint32 const fieldCount = strlen(format);
    int32 indexField;
    uint32 recordSize = DB2FileLoader::GetFormatRecordSize(format, &indexField);
    ASSERT(indexField >= 0, "DB2Storage must be indexed to load localized strings");

    do
    {
        Field* fields = result->Fetch();
        uint32 offset = 0;
        uint32 stringFieldNumInRecord = 0;
        uint32 indexValue = fields[0].GetUInt32();

        // Attempt to overwrite existing data
        if (char* dataValue = indexTable[indexValue])
        {
            for (uint32 x = 0; x < fieldCount; x++)
            {
                switch (format[x])
                {
                    case FT_FLOAT:
                    case FT_IND:
                    case FT_INT:
                        offset += 4;
                        break;
                    case FT_BYTE:
                        offset += 1;
                        break;
                    case FT_LONG:
                        offset += 8;
                        break;
                    case FT_STRING:
                    {
                        // fill only not filled entries
                        LocalizedString* db2str = *(LocalizedString**)(&dataValue[offset]);
                        if (db2str->Str[locale] == nullStr)
                            if (char* str = AddString(&db2str->Str[locale], fields[1 + stringFieldNumInRecord].GetString()))
                                stringPool.push_back(str);

                        ++stringFieldNumInRecord;
                        offset += sizeof(char*);
                        break;
                    }
                }
            }

            ASSERT(offset == recordSize);
        }
        else
            TC_LOG_ERROR("sql.sql", "Hotfix locale table for storage %s references row that does not exist %u!", _storageName.c_str(), indexValue);

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
