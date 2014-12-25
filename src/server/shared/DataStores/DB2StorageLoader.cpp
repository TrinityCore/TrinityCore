/*
 * Copyright (C) 2011 TrintiyCore <http://www.trinitycore.org/>
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

#include <cstdio>
#include <cstdlib>
#include <cstring>

DB2FileLoader::DB2FileLoader()
{
    data = NULL;
    fieldsOffset = NULL;
}

bool DB2FileLoader::Load(const char *filename, const char *fmt)
{
    if (data)
    {
        delete [] data;
        data = NULL;
    }

    FILE* f = fopen(filename, "rb");
    if (!f)
        return false;

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

    if (build > 12880)
    {
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

        if (fread(&locale, 4, 1, f) != 1)                             // Locales
        {
            fclose(f);
            return false;
        }
        EndianConvert(locale);

        if (fread(&unk5, 4, 1, f) != 1)                               // Unknown WDB2
        {
            fclose(f);
            return false;
        }
        EndianConvert(unk5);
    }

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
        if (fmt[i - 1] == 'b' || fmt[i - 1] == 'X')
            fieldsOffset[i] += 1;
        else
            fieldsOffset[i] += 4;
    }

    data = new unsigned char[recordSize*recordCount+stringSize];
    stringTable = data + recordSize*recordCount;

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
        }
    }

    if (index_pos)
        *index_pos = i;

    return recordsize;
}

uint32 DB2FileLoader::GetFormatStringFieldCount(char const* format)
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
                case FT_STRING:
                    *((char**)(&dataTable[offset])) = NULL;   // will be replaces non-empty or "" strings in AutoProduceStrings
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
    size_t stringFields = GetFormatStringFieldCount(format);
    if (!stringFields)
        return nullptr;

    // each string field at load have array of string for each locale
    size_t stringHolderSize = sizeof(char*) * TOTAL_LOCALES;
    size_t stringHoldersRecordPoolSize = stringFields * stringHolderSize;
    size_t stringHoldersPoolSize = stringHoldersRecordPoolSize * recordCount;

    char* stringHoldersPool = new char[stringHoldersPoolSize];

    // DB2 strings expected to have at least empty string
    for (size_t i = 0; i < stringHoldersPoolSize / sizeof(char*); ++i)
        ((char const**)stringHoldersPool)[i] = nullStr;

    uint32 offset = 0;

    // assign string holders to string field slots
    for (uint32 y = 0; y < recordCount; y++)
    {
        uint32 stringFieldNum = 0;

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
                case FT_STRING:
                {
                    // init db2 string field slots by pointers to string holders
                    char const*** slot = (char const***)(&dataTable[offset]);
                    *slot = (char const**)(&stringHoldersPool[stringHoldersRecordPoolSize * y + stringHolderSize*stringFieldNum]);
                    ++stringFieldNum;
                    offset += sizeof(char*);
                    break;
                }
                case FT_NA:
                case FT_NA_BYTE:
                case FT_SORT:
                    break;
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
        return NULL;

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
                case FT_STRING:
                {
                    // fill only not filled entries
                    LocalizedString* db2str = *(LocalizedString**)(&dataTable[offset]);
                    if (db2str->Str[locale] == nullStr)
                    {
                        const char * st = getRecord(y).getString(x);
                        db2str->Str[locale] = stringPool + (st - (const char*)stringTable);
                    }

                    offset += sizeof(char*);
                    break;
                }
            }
        }
    }

    return stringPool;
}

char* DB2DatabaseLoader::Load(const char* format, int32 preparedStatement, uint32& records, char**& indexTable, char*& stringHolders, std::list<char*>& stringPool)
{
    // Even though this query is executed only once, prepared statement is used to send data from mysql server in binary format
    PreparedQueryResult result = HotfixDatabase.Query(HotfixDatabase.GetPreparedStatement(preparedStatement));
    if (!result)
        return nullptr;

    // we store flat holders pool as single memory block
    size_t stringFields = DB2FileLoader::GetFormatStringFieldCount(format);

    size_t expectedFields = strlen(format) + 1 /*VerifiedBuild*/;
    if (stringFields)
        expectedFields += 1 /*ID*/ + stringFields * (TOTAL_LOCALES - 1) + 1 /*VerifiedBuild in locale table*/;

    if (expectedFields != result->GetFieldCount())
        return nullptr;

    //get struct size and index pos
    int32 indexField;
    uint32 recordSize = DB2FileLoader::GetFormatRecordSize(format, &indexField);

    // each string field at load have array of string for each locale
    size_t stringHolderSize = sizeof(char*) * TOTAL_LOCALES;
    size_t stringHoldersRecordPoolSize = stringFields * stringHolderSize;
    size_t stringHoldersPoolSize = stringHoldersRecordPoolSize * result->GetRowCount();

    if (stringFields)
        stringHolders = new char[stringHoldersPoolSize];
    else
        stringHolders = nullptr;

    std::unordered_map<uint32, char*> tempIndexTable;
    tempIndexTable.reserve(result->GetRowCount());
    char* dataTable = new char[result->GetRowCount() * recordSize];
    uint32 offset = 0;

    uint32 const fieldCount = strlen(format);
    uint32 const localeFieldsOffset = fieldCount + 2 /*VerifiedBuild in main table, ID in locale table*/;
    uint32 oldIndexSize = records;
    uint32 rec = 0;
    do
    {
        Field* fields = result->Fetch();
        uint32 stringFieldNumInRecord = 0;

        if (indexField >= 0)
        {
            uint32 indexValue = fields[indexField].GetUInt32();
            tempIndexTable[indexValue] = &dataTable[offset];
            if (records <= indexValue)
                records = indexValue + 1;
        }
        else
            tempIndexTable[records++] = &dataTable[offset];

        for (uint32 x = 0; x < fieldCount; x++)
        {
            switch (format[x])
            {
                case FT_FLOAT:
                    *((float*)(&dataTable[offset])) = fields[x].GetFloat();
                    offset += 4;
                    break;
                case FT_IND:
                case FT_INT:
                    *((int32*)(&dataTable[offset])) = fields[x].GetInt32();
                    offset += 4;
                    break;
                case FT_BYTE:
                    *((int8*)(&dataTable[offset])) = fields[x].GetInt8();
                    offset += 1;
                    break;
                case FT_STRING:
                {
                    LocalizedString** slot = (LocalizedString**)(&dataTable[offset]);
                    *slot = (LocalizedString*)(&stringHolders[stringHoldersRecordPoolSize * rec++ + stringHolderSize * stringFieldNumInRecord]);

                    // Value in database in main table field must be for enUS locale
                    if (char* str = AddLocaleString(*slot, LOCALE_enUS, fields[x].GetString()))
                        stringPool.push_back(str);

                    for (uint32 i = LOCALE_koKR; i < TOTAL_LOCALES; ++i)
                        if (char* str = AddLocaleString(*slot, i, fields[localeFieldsOffset + (i - 1) * stringFieldNumInRecord].GetString()))
                            stringPool.push_back(str);

                    ++stringFieldNumInRecord;
                    offset += sizeof(char*);
                    break;
                }
            }
        }
    } while (result->NextRow());

    // Reallocate index if needed
    if (records > oldIndexSize)
    {
        char** tmpIdxTable = new char*[records];
        memset(tmpIdxTable, 0, records * sizeof(char*));
        memcpy(tmpIdxTable, indexTable, oldIndexSize * sizeof(char*));
        delete[] indexTable;
        indexTable = tmpIdxTable;
    }

    // Merge new data into index
    for (auto itr = tempIndexTable.begin(); itr != tempIndexTable.end(); ++itr)
        indexTable[itr->first] = itr->second;

    return dataTable;
}

char* DB2DatabaseLoader::AddLocaleString(LocalizedString* holder, uint32 locale, std::string const& value)
{
    if (!value.empty())
    {
        char* str = new char[value.length() + 1];
        strcpy(str, value.c_str());
        holder->Str[locale] = str;
        return str;
    }

    return nullptr;
}
