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
#include "DatabaseEnv.h"
#include "Log.h"

DB2SparseFileLoader::DB2SparseFileLoader()
{
    fileName = nullptr;
    meta = nullptr;

    recordCount = 0;
    fieldCount = 0;
    recordSize = 0;
    offsetsPos = 0;
    tableHash = 0;
    layoutHash = 0;
    minIndex = 0;
    maxIndex = 0;
    localeMask = 0;
    copyIdSize = 0;

    dataStart = 0;
    data = nullptr;
    offsets = nullptr;
    fields = nullptr;
}

bool DB2SparseFileLoader::Load(const char *filename, DB2Meta const* meta)
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

    if (fread(&layoutHash, 4, 1, f) != 1)                   // Layout hash
    {
        fclose(f);
        return false;
    }

    EndianConvert(layoutHash);

    if (layoutHash != meta->LayoutHash)
    {
        fclose(f);
        return false;
    }

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

    ASSERT((metaFlags & 0x1) != 0, "%s is not a sparse storage, use DB2Storage!", filename);

    fields = new FieldEntry[fieldCount];
    if (fread(fields, fieldCount * sizeof(FieldEntry), 1, f) != 1)
    {
        fclose(f);
        return false;
    }

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
    delete[] fields;
}

static char const* const nullStr = "";

char* DB2SparseFileLoader::AutoProduceData(IndexTable const& indexTable, uint32 locale, std::vector<char*>& stringPool)
{
    if (meta->FieldCount != fieldCount)
        return NULL;

    //get struct size and index pos
    uint32 recordsize = meta->GetRecordSize();

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
    std::size_t stringFields = meta->GetStringFieldCount(false);
    std::size_t localizedStringFields = meta->GetStringFieldCount(true);

    // each string field at load have array of string for each locale
    std::size_t stringHoldersRecordPoolSize = localizedStringFields * sizeof(LocalizedString) + (stringFields - localizedStringFields) * sizeof(char*);
    std::size_t stringHoldersPoolSize = stringHoldersRecordPoolSize * records;

    char* stringHoldersPool = new char[stringHoldersPoolSize];
    stringPool.push_back(stringHoldersPool);

    // DB2 strings expected to have at least empty string
    for (std::size_t i = 0; i < stringHoldersPoolSize / sizeof(char*); ++i)
        ((char const**)stringHoldersPool)[i] = nullStr;

    char* stringTable = new char[expandedDataSize - records * ((recordsize - (!meta->HasIndexFieldInData() ? 4 : 0)) - stringFields * sizeof(char*))];
    memset(stringTable, 0, expandedDataSize - records * ((recordsize - (!meta->HasIndexFieldInData() ? 4 : 0)) - stringFields * sizeof(char*)));
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

        if (!meta->HasIndexFieldInData())
        {
            *((uint32*)(&dataTable[offset])) = y + minIndex;
            offset += 4;
        }

        for (uint32 x = 0; x < fieldCount; ++x)
        {
            uint16 fieldBytes = 4 - fields[x].UnusedBits / 8;
            for (uint32 z = 0; z < meta->ArraySizes[x]; ++z)
            {
                switch (meta->Types[x])
                {
                    case FT_FLOAT:
                    {
                        float val = *reinterpret_cast<float*>(&data[offsets[y].FileOffset - dataStart + fieldOffset]);
                        EndianConvert(val);
                        *((float*)(&dataTable[offset])) = val;
                        offset += 4;
                        fieldOffset += 4;
                        break;
                    }
                    case FT_INT:
                    {
                        ASSERT(fieldBytes && fieldBytes <= 4);
                        uint32 val = 0;
                        switch (fieldBytes)
                        {
                            case 1:
                                val = *reinterpret_cast<uint8*>(&data[offsets[y].FileOffset - dataStart + fieldOffset]);
                                break;
                            case 2:
                            {
                                uint16 val16 = *reinterpret_cast<uint16*>(&data[offsets[y].FileOffset - dataStart + fieldOffset]);
                                EndianConvert(val16);
                                val = val16;
                                break;
                            }
                            case 3:
                            {
#pragma pack(push, 1)
                                struct dbcint24 { uint8 v[3]; };
#pragma pack(pop)
                                dbcint24 i24v = *reinterpret_cast<dbcint24*>(&data[offsets[y].FileOffset - dataStart + fieldOffset]);
                                EndianConvert(i24v);
                                val = uint32(i24v.v[0]) | (uint32(i24v.v[1]) << 8) | (uint32(i24v.v[2]) << 16);
                                break;
                            }
                            case 4:
                                val = *reinterpret_cast<uint32*>(&data[offsets[y].FileOffset - dataStart + fieldOffset]);
                                EndianConvert(val);
                                break;
                            default:
                                break;
                        }
                        *((uint32*)(&dataTable[offset])) = val;
                        offset += 4;
                        fieldOffset += fieldBytes;
                        break;
                    }
                    case FT_BYTE:
                    {
                        ASSERT(fieldBytes == 1);
                        *((uint8*)(&dataTable[offset])) = *reinterpret_cast<uint8*>(&data[offsets[y].FileOffset - dataStart + fieldOffset]);
                        offset += 1;
                        fieldOffset += 1;
                        break;
                    }
                    case FT_SHORT:
                    {
                        ASSERT(fieldBytes == 2);
                        uint16 val = *reinterpret_cast<uint16*>(&data[offsets[y].FileOffset - dataStart + fieldOffset]);
                        EndianConvert(val);
                        *((uint16*)(&dataTable[offset])) = val;
                        offset += 2;
                        fieldOffset += 2;
                        break;
                    }
                    case FT_STRING:
                    {
                        LocalizedString** slot = (LocalizedString**)(&dataTable[offset]);
                        *slot = (LocalizedString*)(&stringHoldersPool[stringHoldersRecordPoolSize * recordNum + stringFieldOffset]);
                        (*slot)->Str[locale] = stringPtr;
                        strcpy(stringPtr, (char*)&data[offsets[y].FileOffset - dataStart + fieldOffset]);
                        fieldOffset += strlen(stringPtr) + 1;
                        stringPtr += strlen(stringPtr) + 1;
                        stringFieldOffset += sizeof(LocalizedString);
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

        ++recordNum;
    }

    return dataTable;
}

char* DB2SparseFileLoader::AutoProduceStrings(char* dataTable, uint32 locale)
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

    uint32 offsetCount = maxIndex - minIndex + 1;
    uint32 records = 0;
    for (uint32 i = 0; i < offsetCount; ++i)
        if (offsets[i].FileOffset && offsets[i].RecordSize)
            ++records;

    uint32 recordsize = meta->GetRecordSize();
    std::size_t stringFields = meta->GetStringFieldCount(true);
    char* stringTable = new char[offsetsPos - dataStart - records * ((recordsize - (!meta->HasIndexFieldInData() ? 4 : 0)) - stringFields * sizeof(char*))];
    memset(stringTable, 0, offsetsPos - dataStart - records * ((recordsize - (!meta->HasIndexFieldInData() ? 4 : 0)) - stringFields * sizeof(char*)));
    char* stringPtr = stringTable;

    uint32 offset = 0;

    for (uint32 y = 0; y < offsetCount; y++)
    {
        if (!offsets[y].FileOffset || !offsets[y].RecordSize)
            continue;

        if (!meta->HasIndexFieldInData())
            offset += 4;

        uint32 fieldOffset = 0;
        for (uint32 x = 0; x < fieldCount; ++x)
        {
            for (uint32 z = 0; z < meta->ArraySizes[x]; ++z)
            {
                switch (meta->Types[x])
                {
                    case FT_FLOAT:
                        offset += 4;
                        fieldOffset += 4;
                        break;
                    case FT_INT:
                        offset += 4;
                        fieldOffset += 4 - fields[x].UnusedBits / 8;
                        break;
                    case FT_BYTE:
                        offset += 1;
                        fieldOffset += 1;
                        break;
                    case FT_SHORT:
                        offset += 2;
                        fieldOffset += 2;
                        break;
                    case FT_STRING:
                    {
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
                        fieldOffset += strlen((char*)&data[offsets[y].FileOffset - dataStart + fieldOffset]) + 1;
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

    return stringTable;
}

char* DB2SparseDatabaseLoader::Load(HotfixDatabaseStatements preparedStatement, IndexTable const& indexTable, std::vector<char*>& stringPool)
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

        uint32 indexValue = fields[indexField].GetUInt32();

        // Attempt to overwrite existing data
        char* dataValue = indexTable.Get(indexValue);
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
        indexTable.Insert(newIndexes[i], &dataTable[i * recordSize]);

    delete[] tempDataTable;
    delete[] newIndexes;

    return dataTable;
}

void DB2SparseDatabaseLoader::LoadStrings(HotfixDatabaseStatements preparedStatement, uint32 locale, IndexTable const& indexTable, std::vector<char*>& stringPool)
{
    PreparedStatement* stmt = HotfixDatabase.GetPreparedStatement(preparedStatement);
    stmt->setString(0, localeNames[locale]);
    PreparedQueryResult result = HotfixDatabase.Query(stmt);
    if (!result)
        return;

    size_t stringFields = _meta->GetStringFieldCount(true);
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

        // Attempt to overwrite existing data
        if (char* dataValue = indexTable.Get(indexValue))
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
                            offset += sizeof(char*);
                            break;
                        }
                        default:
                            ASSERT(false, "Unknown format character '%c' found in %s meta", _meta->Types[x], _storageName.c_str());
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
