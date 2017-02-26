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

#include "DB2StorageLoader.h"
#include "Database/DatabaseEnv.h"
#include "DB2Meta.h"
#include "Utilities/ByteConverter.h"

DB2LoadInfo::DB2LoadInfo() : Fields(nullptr), FieldCount(0), Meta(nullptr), Statement(MAX_HOTFIXDATABASE_STATEMENTS)
{
}

DB2LoadInfo::DB2LoadInfo(DB2FieldMeta const* fields, std::size_t fieldCount, DB2Meta const* meta, HotfixDatabaseStatements statement)
    : Fields(fields), FieldCount(fieldCount), Meta(meta), Statement(statement)
{
    TypesString.reserve(FieldCount);
    for (std::size_t i = 0; i < FieldCount; ++i)
        TypesString += char(Fields[i].Type);
}

uint32 DB2LoadInfo::GetStringFieldCount(bool localizedOnly) const
{
    uint32 stringFields = 0;
    for (std::size_t i = 0; i < TypesString.length(); ++i)
        if (TypesString[i] == FT_STRING || (TypesString[i] == FT_STRING_NOT_LOCALIZED && !localizedOnly))
            ++stringFields;

    return stringFields;
}

class DB2FileLoaderImpl
{
public:
    virtual ~DB2FileLoaderImpl() { }
    virtual bool Load(char const* filename, FILE* file, DB2LoadInfo const* loadInfo, DB2Header const* header) = 0;
    virtual char* AutoProduceData(uint32& count, char**& indexTable, std::vector<char*>& stringPool) = 0;
    virtual char* AutoProduceStrings(char* dataTable, uint32 locale) = 0;
    virtual void AutoProduceRecordCopies(uint32 records, char** indexTable, char* dataTable) = 0;
};

class DB2FileLoaderRegularImpl : public DB2FileLoaderImpl
{
public:
    DB2FileLoaderRegularImpl();
    ~DB2FileLoaderRegularImpl();

    bool Load(char const* filename, FILE* file, DB2LoadInfo const* loadInfo, DB2Header const* header) override;
    char* AutoProduceData(uint32& count, char**& indexTable, std::vector<char*>& stringPool) override;
    char* AutoProduceStrings(char* dataTable, uint32 locale) override;
    void AutoProduceRecordCopies(uint32 records, char** indexTable, char* dataTable) override;

private:
    class Record
    {
    public:
        float getFloat(uint32 field, uint32 arrayIndex) const;
        uint32 getUInt(uint32 field, uint32 arrayIndex, bool isSigned) const;
        uint8 getUInt8(uint32 field, uint32 arrayIndex) const;
        uint16 getUInt16(uint32 field, uint32 arrayIndex) const;
        char const* getString(uint32 field, uint32 arrayIndex) const;

    private:
        uint16 GetOffset(uint32 field) const;
        uint16 GetByteSize(uint32 field) const;
        uint32 GetVarInt(uint32 field, uint32 arrayIndex, bool isSigned) const;

        Record(DB2FileLoaderRegularImpl &file_, unsigned char *offset_);
        unsigned char *offset;
        DB2FileLoaderRegularImpl &file;

        friend class DB2FileLoaderRegularImpl;
    };

    // Get record by id
    Record getRecord(size_t id);

#pragma pack(push, 1)
    struct FieldEntry
    {
        uint16 UnusedBits;
        uint16 Offset;
    };
#pragma pack(pop)

    char const* fileName;
    DB2LoadInfo const* _loadInfo;
    DB2Header const* _header;

    unsigned char* data;
    unsigned char* stringTable;
    unsigned char* idTable;
    uint32 idTableSize;
    unsigned char* copyTable;
    FieldEntry* fields;
};

class DB2FileLoaderSparseImpl : public DB2FileLoaderImpl
{
public:
    DB2FileLoaderSparseImpl();
    ~DB2FileLoaderSparseImpl();

    bool Load(char const* filename, FILE* file, DB2LoadInfo const* loadInfo, DB2Header const* header) override;
    char* AutoProduceData(uint32& records, char**& indexTable, std::vector<char*>& stringPool) override;
    char* AutoProduceStrings(char* dataTable, uint32 locale) override;
    void AutoProduceRecordCopies(uint32 /*records*/, char** /*indexTable*/, char* /*dataTable*/) override { }

private:
#pragma pack(push, 1)
    struct OffsetTableEntry
    {
        uint32 FileOffset;
        uint16 RecordSize;
    };
    struct FieldEntry
    {
        uint16 UnusedBits;
        uint16 Offset;
    };
#pragma pack(pop)

    char const* fileName;
    DB2LoadInfo const* _loadInfo;
    DB2Header const* _header;
    FieldEntry* fields;

    uint32 dataStart;
    unsigned char* data;
    OffsetTableEntry* offsets;
};

float DB2FileLoaderRegularImpl::Record::getFloat(uint32 field, uint32 arrayIndex) const
{
    ASSERT(field < file._header->FieldCount);
    float val = *reinterpret_cast<float*>(offset + GetOffset(field) + arrayIndex * sizeof(float));
    EndianConvert(val);
    return val;
}

uint32 DB2FileLoaderRegularImpl::Record::getUInt(uint32 field, uint32 arrayIndex, bool isSigned) const
{
    ASSERT(field < file._header->FieldCount);
    return GetVarInt(field, arrayIndex, isSigned);
}

uint8 DB2FileLoaderRegularImpl::Record::getUInt8(uint32 field, uint32 arrayIndex) const
{
    ASSERT(field < file._header->FieldCount);
    ASSERT(GetByteSize(field) == 1);
    return *reinterpret_cast<uint8*>(offset + GetOffset(field) + arrayIndex * sizeof(uint8));
}

uint16 DB2FileLoaderRegularImpl::Record::getUInt16(uint32 field, uint32 arrayIndex) const
{
    ASSERT(field < file._header->FieldCount);
    ASSERT(GetByteSize(field) == 2);
    uint16 val = *reinterpret_cast<uint16*>(offset + GetOffset(field) + arrayIndex * sizeof(uint16));
    EndianConvert(val);
    return val;
}

char const* DB2FileLoaderRegularImpl::Record::getString(uint32 field, uint32 arrayIndex) const
{
    ASSERT(field < file._header->FieldCount);
    uint32 stringOffset = *reinterpret_cast<uint32*>(offset + GetOffset(field) + arrayIndex * sizeof(uint32));
    EndianConvert(stringOffset);
    ASSERT(stringOffset < file._header->StringTableSize);
    return reinterpret_cast<char*>(file.stringTable + stringOffset);
}

uint16 DB2FileLoaderRegularImpl::Record::GetOffset(uint32 field) const
{
    ASSERT(field < file._header->FieldCount);
    return file.fields[field].Offset;
}

uint16 DB2FileLoaderRegularImpl::Record::GetByteSize(uint32 field) const
{
    ASSERT(field < file._header->FieldCount);
    return 4 - file.fields[field].UnusedBits / 8;
}

uint32 DB2FileLoaderRegularImpl::Record::GetVarInt(uint32 field, uint32 arrayIndex, bool isSigned) const
{
    ASSERT(field < file._header->FieldCount);
    uint32 val = *reinterpret_cast<uint32*>(offset + GetOffset(field) + arrayIndex * (4 - file.fields[field].UnusedBits / 8));
    EndianConvert(val);
    if (isSigned)
        return int32(val) << file.fields[field].UnusedBits >> file.fields[field].UnusedBits;

    return val << file.fields[field].UnusedBits >> file.fields[field].UnusedBits;
}

DB2FileLoaderRegularImpl::Record::Record(DB2FileLoaderRegularImpl &file_, unsigned char *offset_) : offset(offset_), file(file_)
{
}

DB2FileLoaderRegularImpl::DB2FileLoaderRegularImpl()
{
    fileName = nullptr;
    _loadInfo = nullptr;
    _header = nullptr;
    data = nullptr;
    stringTable = nullptr;
    idTable = nullptr;
    idTableSize = 0;
    copyTable = nullptr;
    fields = nullptr;
}

bool DB2FileLoaderRegularImpl::Load(char const* filename, FILE* file, DB2LoadInfo const* loadInfo, DB2Header const* header)
{
    _loadInfo = loadInfo;
    _header = header;
    ASSERT(_loadInfo->Meta->IndexField == -1 || _loadInfo->Meta->IndexField == int32(header->IndexField));

    fileName = filename;
    fields = new FieldEntry[header->FieldCount];
    if (fread(fields, header->FieldCount * sizeof(FieldEntry), 1, file) != 1)
        return false;

    if (!_loadInfo->Meta->HasIndexFieldInData())
        idTableSize = header->RecordCount * sizeof(uint32);

    data = new unsigned char[header->RecordSize * header->RecordCount + header->StringTableSize];
    stringTable = data + header->RecordSize * header->RecordCount;

    if (fread(data, header->RecordSize * header->RecordCount + header->StringTableSize, 1, file) != 1)
        return false;

    if (idTableSize)
    {
        idTable = new unsigned char[idTableSize];
        if (fread(idTable, idTableSize, 1, file) != 1)
            return false;
    }

    if (header->CopyTableSize)
    {
        copyTable = new unsigned char[header->CopyTableSize];
        if (fread(copyTable, header->CopyTableSize, 1, file) != 1)
            return false;
    }

    return true;
}

DB2FileLoaderRegularImpl::~DB2FileLoaderRegularImpl()
{
    delete[] data;
    delete[] idTable;
    delete[] copyTable;
    delete[] fields;
}

DB2FileLoaderRegularImpl::Record DB2FileLoaderRegularImpl::getRecord(size_t id)
{
    assert(data);
    return Record(*this, data + id * _header->RecordSize);
}

static char const* const nullStr = "";

char* DB2FileLoaderRegularImpl::AutoProduceData(uint32& records, char**& indexTable, std::vector<char*>& stringPool)
{
    if (_loadInfo->Meta->FieldCount != _header->FieldCount)
        return nullptr;

    //get struct size and index pos
    uint32 indexField = _loadInfo->Meta->GetIndexField();
    uint32 recordsize = _loadInfo->Meta->GetRecordSize();

    uint32 maxi = 0;
    //find max index
    if (!idTableSize)
    {
        for (uint32 y = 0; y < _header->RecordCount; ++y)
        {
            uint32 ind = getRecord(y).getUInt(indexField, 0, false);
            if (ind > maxi)
                maxi = ind;
        }
    }
    else
    {
        for (uint32 y = 0; y < _header->RecordCount; ++y)
        {
            uint32 ind = ((uint32*)idTable)[y];
            if (ind > maxi)
                maxi = ind;
        }
    }

    for (uint32 y = 0; y < _header->CopyTableSize; y += 8)
    {
        uint32 ind = *((uint32*)(copyTable + y));
        if (ind > maxi)
            maxi = ind;
    }

    using index_entry_t = char*;

    ++maxi;
    records = maxi;
    indexTable = new index_entry_t[maxi];
    memset(indexTable, 0, maxi * sizeof(index_entry_t));

    char* dataTable = new char[(_header->RecordCount + (_header->CopyTableSize / 8)) * recordsize];

    // we store flat holders pool as single memory block
    std::size_t stringFields = _loadInfo->GetStringFieldCount(false);
    std::size_t localizedStringFields = _loadInfo->GetStringFieldCount(true);

    // each string field at load have array of string for each locale
    std::size_t stringHoldersRecordPoolSize = localizedStringFields * sizeof(LocalizedString) + (stringFields - localizedStringFields) * sizeof(char*);
    char* stringHoldersPool = nullptr;
    if (stringFields)
    {
        std::size_t stringHoldersPoolSize = stringHoldersRecordPoolSize * _header->RecordCount;

        stringHoldersPool = new char[stringHoldersPoolSize];
        stringPool.push_back(stringHoldersPool);

        // DB2 strings expected to have at least empty string
        for (std::size_t i = 0; i < stringHoldersPoolSize / sizeof(char*); ++i)
            ((char const**)stringHoldersPool)[i] = nullStr;
    }

    uint32 offset = 0;

    for (uint32 y = 0; y < _header->RecordCount; y++)
    {
        Record rec = getRecord(y);
        uint32 indexVal = _loadInfo->Meta->HasIndexFieldInData() ? rec.getUInt(indexField, 0, false) : ((uint32*)idTable)[y];

        indexTable[indexVal] = &dataTable[offset];

        uint32 fieldIndex = 0;
        if (!_loadInfo->Meta->HasIndexFieldInData())
        {
            *((uint32*)(&dataTable[offset])) = indexVal;
            offset += 4;
            ++fieldIndex;
        }

        uint32 stringFieldOffset = 0;

        for (uint32 x = 0; x < _header->FieldCount; ++x)
        {
            for (uint32 z = 0; z < _loadInfo->Meta->ArraySizes[x]; ++z)
            {
                switch (_loadInfo->TypesString[fieldIndex])
                {
                    case FT_FLOAT:
                        *((float*)(&dataTable[offset])) = rec.getFloat(x, z);
                        offset += 4;
                        break;
                    case FT_INT:
                        *((uint32*)(&dataTable[offset])) = rec.getUInt(x, z, _loadInfo->Fields[fieldIndex].IsSigned);
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
                    {
                        // init db2 string field slots by pointers to string holders
                        char const*** slot = (char const***)(&dataTable[offset]);
                        *slot = (char const**)(&stringHoldersPool[stringHoldersRecordPoolSize * y + stringFieldOffset]);
                        if (_loadInfo->TypesString[fieldIndex] == FT_STRING)
                            stringFieldOffset += sizeof(LocalizedString);
                        else
                            stringFieldOffset += sizeof(char*);

                        offset += sizeof(char*);
                        break;
                    }
                    default:
                        ASSERT(false, "Unknown format character '%c' found in %s meta", _loadInfo->TypesString[x], fileName);
                        break;
                }
                ++fieldIndex;
            }
        }
    }

    return dataTable;
}

char* DB2FileLoaderRegularImpl::AutoProduceStrings(char* dataTable, uint32 locale)
{
    if (_loadInfo->Meta->FieldCount != _header->FieldCount)
        return nullptr;

    if (!(_header->Locale & (1 << locale)))
    {
        char const* sep = "";
        std::ostringstream str;
        for (uint32 i = 0; i < TOTAL_LOCALES; ++i)
        {
            if (_header->Locale & (1 << i))
            {
                str << sep << localeNames[i];
                sep = ", ";
            }
        }

        TC_LOG_ERROR("", "Attempted to load %s which has locales %s as %s. Check if you placed your localized db2 files in correct directory.", fileName, str.str().c_str(), localeNames[locale]);
        return nullptr;
    }

    char* stringPool = new char[_header->StringTableSize];
    memcpy(stringPool, stringTable, _header->StringTableSize);

    uint32 offset = 0;

    for (uint32 y = 0; y < _header->RecordCount; y++)
    {
        uint32 fieldIndex = 0;
        if (!_loadInfo->Meta->HasIndexFieldInData())
        {
            offset += 4;
            ++fieldIndex;
        }

        for (uint32 x = 0; x < _header->FieldCount; ++x)
        {
            for (uint32 z = 0; z < _loadInfo->Meta->ArraySizes[x]; ++z)
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
                        ASSERT(false, "Unknown format character '%c' found in %s meta", _loadInfo->TypesString[x], fileName);
                        break;
                }
                ++fieldIndex;
            }
        }
    }

    return stringPool;
}

void DB2FileLoaderRegularImpl::AutoProduceRecordCopies(uint32 records, char** indexTable, char* dataTable)
{
    uint32 recordsize = _loadInfo->Meta->GetRecordSize();
    uint32 offset = _header->RecordCount * recordsize;
    uint32* copyIds = (uint32*)copyTable;
    for (uint32 c = 0; c < _header->CopyTableSize / 4; c += 2)
    {
        uint32 to = copyIds[c];
        uint32 from = copyIds[c + 1];

        if (from && from < records && to < records && indexTable[from])
        {
            indexTable[to] = &dataTable[offset];
            memcpy(indexTable[to], indexTable[from], recordsize);

            if (_loadInfo->Meta->HasIndexFieldInData())
                *((uint32*)(&dataTable[offset + fields[_loadInfo->Meta->GetIndexField()].Offset])) = to;
            else
                *((uint32*)(&dataTable[offset])) = to;

            offset += recordsize;
        }
    }
}

DB2FileLoaderSparseImpl::DB2FileLoaderSparseImpl()
{
    fileName = nullptr;
    _loadInfo = nullptr;
    _header = nullptr;
    fields = nullptr;
    dataStart = 0;
    data = nullptr;
    offsets = nullptr;
}

bool DB2FileLoaderSparseImpl::Load(char const* filename, FILE* file, DB2LoadInfo const* loadInfo, DB2Header const* header)
{
    _loadInfo = loadInfo;
    _header = header;
    fileName = filename;

    fields = new FieldEntry[header->FieldCount];
    if (fread(fields, header->FieldCount * sizeof(FieldEntry), 1, file) != 1)
        return false;

    dataStart = ftell(file);

    data = new unsigned char[header->StringTableSize - dataStart];

    if (fread(data, header->StringTableSize - dataStart, 1, file) != 1)
        return false;

    offsets = new OffsetTableEntry[header->MaxId - header->MinId + 1];
    if (fread(offsets, (header->MaxId - header->MinId + 1) * 6, 1, file) != 1)
        return false;

    return true;
}

DB2FileLoaderSparseImpl::~DB2FileLoaderSparseImpl()
{
    delete[] data;
    delete[] offsets;
    delete[] fields;
}

char* DB2FileLoaderSparseImpl::AutoProduceData(uint32& maxId, char**& indexTable, std::vector<char*>& stringPool)
{
    if (_loadInfo->Meta->FieldCount != _header->FieldCount)
        return NULL;

    //get struct size and index pos
    uint32 recordsize = _loadInfo->Meta->GetRecordSize();

    uint32 offsetCount = _header->MaxId - _header->MinId + 1;
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

    using index_entry_t = char*;

    maxId = _header->MaxId + 1;
    indexTable = new index_entry_t[maxId];
    memset(indexTable, 0, maxId * sizeof(index_entry_t));

    char* dataTable = new char[records * recordsize];

    // we store flat holders pool as single memory block
    std::size_t stringFields = _loadInfo->GetStringFieldCount(false);
    std::size_t localizedStringFields = _loadInfo->GetStringFieldCount(true);

    // each string field at load have array of string for each locale
    std::size_t stringHoldersRecordPoolSize = localizedStringFields * sizeof(LocalizedString) + (stringFields - localizedStringFields) * sizeof(char*);
    std::size_t stringHoldersPoolSize = stringHoldersRecordPoolSize * records;

    char* stringHoldersPool = new char[stringHoldersPoolSize];
    stringPool.push_back(stringHoldersPool);

    // DB2 strings expected to have at least empty string
    for (std::size_t i = 0; i < stringHoldersPoolSize / sizeof(char*); ++i)
        ((char const**)stringHoldersPool)[i] = nullStr;

    char* stringTable = new char[expandedDataSize - records * ((recordsize - (!_loadInfo->Meta->HasIndexFieldInData() ? 4 : 0)) - stringFields * sizeof(char*))];
    memset(stringTable, 0, expandedDataSize - records * ((recordsize - (!_loadInfo->Meta->HasIndexFieldInData() ? 4 : 0)) - stringFields * sizeof(char*)));
    stringPool.push_back(stringTable);
    char* stringPtr = stringTable;

    uint32 offset = 0;
    uint32 recordNum = 0;
    for (uint32 y = 0; y < offsetCount; ++y)
    {
        if (!offsets[y].FileOffset || !offsets[y].RecordSize)
            continue;

        indexTable[y + _header->MinId] = &dataTable[offset];
        ASSERT(indexTable[y + _header->MinId]);
        std::size_t fieldOffset = 0;
        uint32 stringFieldOffset = 0;

        uint32 fieldIndex = 0;
        if (!_loadInfo->Meta->HasIndexFieldInData())
        {
            *((uint32*)(&dataTable[offset])) = y + _header->MinId;
            offset += 4;
            ++fieldIndex;
        }

        for (uint32 x = 0; x < _header->FieldCount; ++x)
        {
            uint16 fieldBytes = 4 - fields[x].UnusedBits / 8;
            for (uint32 z = 0; z < _loadInfo->Meta->ArraySizes[x]; ++z)
            {
                switch (_loadInfo->TypesString[fieldIndex])
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
                        for (uint32 locale = 0; locale < TOTAL_LOCALES; ++locale)
                            if (_header->Locale & (1 << locale))
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
                        ASSERT(false, "Unknown format character '%c' found in %s meta", _loadInfo->TypesString[x], fileName);
                        break;
                }
                ++fieldIndex;
            }
        }

        ++recordNum;
    }

    return dataTable;
}

char* DB2FileLoaderSparseImpl::AutoProduceStrings(char* dataTable, uint32 locale)
{
    if (_loadInfo->Meta->FieldCount != _header->FieldCount)
        return nullptr;

    if (!(_header->Locale & (1 << locale)))
    {
        char const* sep = "";
        std::ostringstream str;
        for (uint32 i = 0; i < TOTAL_LOCALES; ++i)
        {
            if (_header->Locale & (1 << i))
            {
                str << sep << localeNames[i];
                sep = ", ";
            }
        }

        TC_LOG_ERROR("", "Attempted to load %s which has locales %s as %s. Check if you placed your localized db2 files in correct directory.", fileName, str.str().c_str(), localeNames[locale]);
        return nullptr;
    }

    uint32 offsetCount = _header->MaxId - _header->MinId + 1;
    uint32 records = 0;
    for (uint32 i = 0; i < offsetCount; ++i)
        if (offsets[i].FileOffset && offsets[i].RecordSize)
            ++records;

    uint32 recordsize = _loadInfo->Meta->GetRecordSize();
    std::size_t stringFields = _loadInfo->GetStringFieldCount(true);
    char* stringTable = new char[_header->StringTableSize - dataStart - records * ((recordsize - (!_loadInfo->Meta->HasIndexFieldInData() ? 4 : 0)) - stringFields * sizeof(char*))];
    memset(stringTable, 0, _header->StringTableSize - dataStart - records * ((recordsize - (!_loadInfo->Meta->HasIndexFieldInData() ? 4 : 0)) - stringFields * sizeof(char*)));
    char* stringPtr = stringTable;

    uint32 offset = 0;

    for (uint32 y = 0; y < offsetCount; y++)
    {
        if (!offsets[y].FileOffset || !offsets[y].RecordSize)
            continue;

        uint32 fieldIndex = 0;
        if (!_loadInfo->Meta->HasIndexFieldInData())
        {
            offset += 4;
            ++fieldIndex;
        }

        std::size_t fieldOffset = 0;
        for (uint32 x = 0; x < _header->FieldCount; ++x)
        {
            for (uint32 z = 0; z < _loadInfo->Meta->ArraySizes[x]; ++z)
            {
                switch (_loadInfo->TypesString[fieldIndex])
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
                        ASSERT(false, "Unknown format character '%c' found in %s meta", _loadInfo->TypesString[x], fileName);
                        break;
                }
                ++fieldIndex;
            }
        }
    }

    return stringTable;
}

char* DB2DatabaseLoader::Load(uint32& records, char**& indexTable, char*& stringHolders, std::vector<char*>& stringPool)
{
    // Even though this query is executed only once, prepared statement is used to send data from mysql server in binary format
    PreparedQueryResult result = HotfixDatabase.Query(HotfixDatabase.GetPreparedStatement(_loadInfo->Statement));
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
        if (!_loadInfo->Meta->HasIndexFieldInData())
        {
            *((uint32*)(&dataValue[offset])) = indexValue;
            offset += 4;
            ++f;
        }

        for (uint32 x = 0; x < _loadInfo->Meta->FieldCount; ++x)
        {
            for (uint32 z = 0; z < _loadInfo->Meta->ArraySizes[x]; ++z)
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
                        ASSERT(false, "Unknown format character '%c' found in %s meta", _loadInfo->TypesString[x], _storageName.c_str());
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

void DB2DatabaseLoader::LoadStrings(uint32 locale, uint32 records, char** indexTable, std::vector<char*>& stringPool)
{
    PreparedStatement* stmt = HotfixDatabase.GetPreparedStatement(HotfixDatabaseStatements(_loadInfo->Statement + 1));
    stmt->setString(0, localeNames[locale]);
    PreparedQueryResult result = HotfixDatabase.Query(stmt);
    if (!result)
        return;

    std::size_t stringFields = _loadInfo->GetStringFieldCount(true);
    if (result->GetFieldCount() != stringFields + 1 /*ID*/)
        return;

    uint32 fieldCount = _loadInfo->Meta->FieldCount;
    uint32 recordSize = _loadInfo->Meta->GetRecordSize();

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
                for (uint32 z = 0; z < _loadInfo->Meta->ArraySizes[x]; ++z)
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
                            ASSERT(false, "Unknown format character '%c' found in %s meta", _loadInfo->TypesString[x], _storageName.c_str());
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

DB2FileLoader::DB2FileLoader() : _impl(nullptr)
{
}

DB2FileLoader::~DB2FileLoader()
{
    delete _impl;
}

bool DB2FileLoader::Load(char const* filename, DB2LoadInfo const* loadInfo)
{
    FILE* f = fopen(filename, "rb");
    if (!f)
        return false;

    if (fread(&_header.Signature, 4, 1, f) != 1)            // Signature
    {
        fclose(f);
        return false;
    }

    EndianConvert(_header.Signature);

    if (_header.Signature != 0x35424457)
    {
        fclose(f);
        return false;                                       //'WDB5'
    }

    if (fread(&_header.RecordCount, 4, 1, f) != 1)          // Number of records
    {
        fclose(f);
        return false;
    }

    EndianConvert(_header.RecordCount);

    if (fread(&_header.FieldCount, 4, 1, f) != 1)           // Number of fields
    {
        fclose(f);
        return false;
    }

    EndianConvert(_header.FieldCount);

    if (fread(&_header.RecordSize, 4, 1, f) != 1)           // Size of a record
    {
        fclose(f);
        return false;
    }

    EndianConvert(_header.RecordSize);

    if (fread(&_header.StringTableSize, 4, 1, f) != 1)      // String size
    {
        fclose(f);
        return false;
    }

    EndianConvert(_header.StringTableSize);

    if (fread(&_header.TableHash, 4, 1, f) != 1)            // Table hash
    {
        fclose(f);
        return false;
    }

    EndianConvert(_header.TableHash);

    if (fread(&_header.LayoutHash, 4, 1, f) != 1)           // Layout hash
    {
        fclose(f);
        return false;
    }

    EndianConvert(_header.LayoutHash);

    if (_header.LayoutHash != loadInfo->Meta->LayoutHash)
    {
        fclose(f);
        return false;
    }

    if (fread(&_header.MinId, 4, 1, f) != 1)                // MinIndex WDB2
    {
        fclose(f);
        return false;
    }

    EndianConvert(_header.MinId);

    if (fread(&_header.MaxId, 4, 1, f) != 1)                // MaxIndex WDB2
    {
        fclose(f);
        return false;
    }

    EndianConvert(_header.MaxId);

    if (fread(&_header.Locale, 4, 1, f) != 1)               // Locales
    {
        fclose(f);
        return false;
    }

    EndianConvert(_header.Locale);

    if (fread(&_header.CopyTableSize, 4, 1, f) != 1)
    {
        fclose(f);
        return false;
    }

    EndianConvert(_header.CopyTableSize);

    if (fread(&_header.Flags, 4, 1, f) != 1)
    {
        fclose(f);
        return false;
    }

    EndianConvert(_header.Flags);

    if (!(_header.Flags & 0x1))
        _impl = new DB2FileLoaderRegularImpl();
    else
        _impl = new DB2FileLoaderSparseImpl();

    bool result = _impl->Load(filename, f, loadInfo, &_header);
    fclose(f);
    return result;
}

char* DB2FileLoader::AutoProduceData(uint32& count, char**& indexTable, std::vector<char*>& stringPool)
{
    return _impl->AutoProduceData(count, indexTable, stringPool);
}

char* DB2FileLoader::AutoProduceStrings(char* dataTable, uint32 locale)
{
    return _impl->AutoProduceStrings(dataTable, locale);
}

void DB2FileLoader::AutoProduceRecordCopies(uint32 records, char** indexTable, char* dataTable)
{
    _impl->AutoProduceRecordCopies(records, indexTable, dataTable);
}
