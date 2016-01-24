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
#include "DB2SparseStorageLoader.h"
#include "Database/DatabaseEnv.h"
#include "Log.h"

DB2SparseFileLoader::DB2SparseFileLoader()
{
    fileName = nullptr;

    recordCount = 0;
    fieldCount = 0;
    recordSize = 0;
    offsetsPos = 0;
    tableHash = 0;
    build = 0;
    unk1 = 0;
    minIndex = 0;
    maxIndex = 0;
    localeMask = 0;
    copyIdSize = 0;

    dataStart = 0;
    data = nullptr;
    offsets = nullptr;
}

bool DB2SparseFileLoader::Load(const char *filename)
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
    if (fread(&header, 4, 1, f) != 1)                       // Signature
    {
        fclose(f);
        return false;
    }

    EndianConvert(header);

    if (header != 0x34424457)
    {
        fclose(f);
        return false;                                       //'WDB4'
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

    if (fread(&offsetsPos, 4, 1, f) != 1)                   // String size
    {
        fclose(f);
        return false;
    }

    EndianConvert(offsetsPos);

    if (fread(&tableHash, 4, 1, f) != 1)                    // Table hash
    {
        fclose(f);
        return false;
    }

    EndianConvert(tableHash);

    if (fread(&build, 4, 1, f) != 1)                        // Build
    {
        fclose(f);
        return false;
    }

    EndianConvert(build);

    if (fread(&unk1, 4, 1, f) != 1)                         // Unknown WDB2
    {
        fclose(f);
        return false;
    }

    EndianConvert(unk1);

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

    dataStart = ftell(f);

    data = new unsigned char[offsetsPos - dataStart];

    if (fread(data, offsetsPos - dataStart, 1, f) != 1)
    {
        fclose(f);
        return false;
    }

    offsets = new OffsetTableEntry[maxIndex - minIndex + 1];
    if (fread(offsets, (maxIndex - minIndex + 1) * 6, 1, f) != 1)
    {
        fclose(f);
        return false;
    }

    fclose(f);
    return true;
}

DB2SparseFileLoader::~DB2SparseFileLoader()
{
    delete[] data;
    delete[] offsets;
}

uint32 DB2SparseFileLoader::GetFormatRecordSize(const char * format)
{
    uint32 recordsize = 0;
    for (uint32 x = 0; format[x]; ++x)
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
            case FT_BYTE:
                recordsize += 1;
                break;
            case FT_LONG:
                recordsize += 8;
                break;
            case FT_SHORT:
                recordsize += 2;
                break;
        }
    }

    return recordsize;
}

uint32 DB2SparseFileLoader::GetFormatStringFieldCount(const char* format)
{
    uint32 stringfields = 0;
    for (uint32 x = 0; format[x]; ++x)
        if (format[x] == FT_STRING || format[x] == FT_STRING_NOT_LOCALIZED)
            ++stringfields;

    return stringfields;
}

uint32 DB2SparseFileLoader::GetFormatLocalizedStringFieldCount(char const* format)
{
    uint32 stringfields = 0;
    for (uint32 x = 0; format[x]; ++x)
        if (format[x] == FT_STRING)
            ++stringfields;

    return stringfields;
}

static char const* const nullStr = "";

char* DB2SparseFileLoader::AutoProduceData(const char* format, IndexTable const& indexTable, uint32 locale, std::vector<char*>& stringPool)
{
    typedef char* ptr;
    if (strlen(format) != fieldCount)
        return NULL;

    //get struct size and index pos
    uint32 recordsize = GetFormatRecordSize(format);

    uint32 offsetCount = maxIndex - minIndex + 1;
    uint32 records = 0;
    uint32 expandedDataSize = 0;
    for (uint32 i = 0; i < offsetCount; ++i)
    {
        if (offsets[i].FileOffset && offsets[i].RecordSize)
        {
            ++records;
            expandedDataSize += offsets[i].RecordSize;
        }
    }

    char* dataTable = new char[records * recordsize];

    // we store flat holders pool as single memory block
    std::size_t stringFields = GetFormatStringFieldCount(format);
    std::size_t localizedStringFields = GetFormatLocalizedStringFieldCount(format);

    // each string field at load have array of string for each locale
    std::size_t stringHolderSize = sizeof(char*) * TOTAL_LOCALES;
    std::size_t stringHoldersRecordPoolSize = localizedStringFields * stringHolderSize + (stringFields - localizedStringFields) * sizeof(char*);
    std::size_t stringHoldersPoolSize = stringHoldersRecordPoolSize * records;

    char* stringHoldersPool = new char[stringHoldersPoolSize];
    stringPool.push_back(stringHoldersPool);

    // DB2 strings expected to have at least empty string
    for (std::size_t i = 0; i < stringHoldersPoolSize / sizeof(char*); ++i)
        ((char const**)stringHoldersPool)[i] = nullStr;

    char* stringTable = new char[expandedDataSize - records * (recordsize - stringFields * sizeof(char*))];
    memset(stringTable, 0, expandedDataSize - records * (recordsize - stringFields * sizeof(char*)));
    stringPool.push_back(stringTable);
    char* stringPtr = stringTable;

    uint32 offset = 0;
    uint32 recordNum = 0;
    for (uint32 y = 0; y < offsetCount; ++y)
    {
        if (!offsets[y].FileOffset || !offsets[y].RecordSize)
            continue;

        indexTable.Insert(y + minIndex, &dataTable[offset]);
        uint32 fieldOffset = 0;
        uint32 stringFieldOffset = 0;
        for (uint32 x = 0; x < fieldCount; x++)
        {
            switch (format[x])
            {
                case FT_FLOAT:
                    *((float*)(&dataTable[offset])) = *reinterpret_cast<float*>(&data[offsets[y].FileOffset - dataStart + fieldOffset]);
                    offset += 4;
                    fieldOffset += 4;
                    break;
                case FT_IND:
                case FT_INT:
                    *((uint32*)(&dataTable[offset])) = *reinterpret_cast<uint32*>(&data[offsets[y].FileOffset - dataStart + fieldOffset]);
                    offset += 4;
                    fieldOffset += 4;
                    break;
                case FT_BYTE:
                    *((uint8*)(&dataTable[offset])) = *reinterpret_cast<uint8*>(&data[offsets[y].FileOffset - dataStart + fieldOffset]);
                    offset += 1;
                    fieldOffset += 1;
                    break;
                case FT_LONG:
                    *((uint64*)(&dataTable[offset])) = *reinterpret_cast<uint64*>(&data[offsets[y].FileOffset - dataStart + fieldOffset]);
                    offset += 8;
                    fieldOffset += 8;
                    break;
                case FT_SHORT:
                    *((uint16*)(&dataTable[offset])) = *reinterpret_cast<uint16*>(&data[offsets[y].FileOffset - dataStart + fieldOffset]);
                    offset += 2;
                    fieldOffset += 2;
                    break;
                case FT_STRING:
                {
                    LocalizedString** slot = (LocalizedString**)(&dataTable[offset]);
                    *slot = (LocalizedString*)(&stringHoldersPool[stringHoldersRecordPoolSize * recordNum + stringFieldOffset]);
                    (*slot)->Str[locale] = stringPtr;
                    strcpy(stringPtr, (char*)&data[offsets[y].FileOffset - dataStart + fieldOffset]);
                    fieldOffset += strlen(stringPtr) + 1;
                    stringPtr += strlen(stringPtr) + 1;
                    stringFieldOffset += stringHolderSize;
                    offset += sizeof(LocalizedString*);
                    break;
                }
                case FT_STRING_NOT_LOCALIZED:
                {
                    char const*** slot = (char const***)(&dataTable[offset]);
                    *slot = (char const**)(&stringHoldersPool[stringHoldersRecordPoolSize * recordNum + stringFieldOffset]);
                    **slot = stringPtr;
                    strcpy(stringPtr, (char*)&data[offsets[y].FileOffset - dataStart + fieldOffset]);
                    fieldOffset += strlen(stringPtr) + 1;
                    stringPtr += strlen(stringPtr) + 1;
                    ++stringFieldOffset;
                    offset += sizeof(char*);
                    break;
                }
            }
        }

        ++recordNum;
    }

    return dataTable;
}

char* DB2SparseFileLoader::AutoProduceStrings(const char* format, char* dataTable, uint32 locale)
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

    uint32 offsetCount = maxIndex - minIndex + 1;
    uint32 records = 0;
    for (uint32 i = 0; i < offsetCount; ++i)
        if (offsets[i].FileOffset && offsets[i].RecordSize)
            ++records;

    uint32 recordsize = GetFormatRecordSize(format);
    std::size_t stringFields = GetFormatStringFieldCount(format);
    char* stringTable = new char[offsetsPos - dataStart - records * (recordsize - stringFields * sizeof(char*))];
    memset(stringTable, 0, offsetsPos - dataStart - records * (recordsize - stringFields * sizeof(char*)));
    char* stringPtr = stringTable;

    uint32 offset = 0;

    for (uint32 y = 0; y < offsetCount; y++)
    {
        if (!offsets[y].FileOffset || !offsets[y].RecordSize)
            continue;

        uint32 fieldOffset;
        for (uint32 x = 0; x < fieldCount; x++)
        {
            switch (format[x])
            {
                case FT_FLOAT:
                case FT_IND:
                case FT_INT:
                    offset += 4;
                    fieldOffset += 4;
                    break;
                case FT_BYTE:
                    offset += 1;
                    fieldOffset += 1;
                    break;
                case FT_LONG:
                    offset += 8;
                    fieldOffset += 8;
                    break;
                case FT_SHORT:
                    offset += 2;
                    fieldOffset += 2;
                    break;
                case FT_STRING:
                {
                    // fill only not filled entries
                    LocalizedString* db2str = *(LocalizedString**)(&dataTable[offset]);
                    db2str->Str[locale] = stringPtr;
                    strcpy(stringPtr, (char*)&data[offsets[y].FileOffset - dataStart + fieldOffset]);
                    fieldOffset += strlen(stringPtr) + 1;
                    stringPtr += strlen(stringPtr) + 1;
                    offset += sizeof(char*);
                    break;
                }
                case FT_STRING_NOT_LOCALIZED:
                {
                    char** db2str = (char**)(&dataTable[offset]);
                    *db2str = stringPtr;
                    strcpy(stringPtr, (char*)&data[offsets[y].FileOffset - dataStart + fieldOffset]);
                    fieldOffset += strlen(stringPtr) + 1;
                    stringPtr += strlen(stringPtr) + 1;
                    offset += sizeof(char*);
                    break;
                }
            }
        }
    }

    return stringTable;
}

char* DB2SparseDatabaseLoader::Load(const char* format, HotfixDatabaseStatements preparedStatement, IndexTable const& indexTable, std::vector<char*>& stringPool)
{
    // Even though this query is executed only once, prepared statement is used to send data from mysql server in binary format
    PreparedQueryResult result = HotfixDatabase.Query(HotfixDatabase.GetPreparedStatement(preparedStatement));
    if (!result)
        return nullptr;

    uint32 const fieldCount = strlen(format);
    if (fieldCount != result->GetFieldCount())
        return nullptr;

    // get struct size and index pos
    uint32 recordSize = DB2SparseFileLoader::GetFormatRecordSize(format);

    // we store flat holders pool as single memory block
    std::size_t stringFields = DB2SparseFileLoader::GetFormatStringFieldCount(format);
    std::size_t localizedStringFields = DB2SparseFileLoader::GetFormatLocalizedStringFieldCount(format);

    // each string field at load have array of string for each locale
    std::size_t stringHolderSize = sizeof(char*) * TOTAL_LOCALES;
    std::size_t stringHoldersRecordPoolSize = localizedStringFields * stringHolderSize + (stringFields - localizedStringFields) * sizeof(char*);

    char* stringHolders = nullptr;
    if (stringFields)
    {
        std::size_t stringHoldersPoolSize = stringHoldersRecordPoolSize * result->GetRowCount();
        stringHolders = new char[stringHoldersPoolSize];
        stringPool.push_back(stringHolders);

        // DB2 strings expected to have at least empty string
        for (std::size_t i = 0; i < stringHoldersPoolSize / sizeof(char*); ++i)
            ((char const**)stringHolders)[i] = nullStr;
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

        uint32 indexValue = fields[0].GetUInt32();

        // Attempt to overwrite existing data
        char* dataValue = indexTable.Get(indexValue);
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

                    stringFieldOffset += stringHolderSize;
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

                    ++stringFieldOffset;
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
        indexTable.Insert(newIndexes[i], &dataTable[i * recordSize]);

    delete[] tempDataTable;
    delete[] newIndexes;

    return dataTable;
}

void DB2SparseDatabaseLoader::LoadStrings(const char* format, HotfixDatabaseStatements preparedStatement, uint32 locale, IndexTable const& indexTable, std::vector<char*>& stringPool)
{
    PreparedStatement* stmt = HotfixDatabase.GetPreparedStatement(preparedStatement);
    stmt->setString(0, localeNames[locale]);
    PreparedQueryResult result = HotfixDatabase.Query(stmt);
    if (!result)
        return;

    size_t stringFields = DB2SparseFileLoader::GetFormatLocalizedStringFieldCount(format);
    if (result->GetFieldCount() != stringFields + 1 /*ID*/)
        return;

    uint32 const fieldCount = strlen(format);
    uint32 recordSize = DB2SparseFileLoader::GetFormatRecordSize(format);
    ASSERT(0 >= 0, "DB2Storage must be indexed to load localized strings");

    do
    {
        Field* fields = result->Fetch();
        uint32 offset = 0;
        uint32 stringFieldNumInRecord = 0;
        uint32 indexValue = fields[0].GetUInt32();

        // Attempt to overwrite existing data
        if (char* dataValue = indexTable.Get(indexValue))
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

char* DB2SparseDatabaseLoader::AddString(char const** holder, std::string const& value)
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
