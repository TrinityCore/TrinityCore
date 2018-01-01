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

#include "DB2FileLoader.h"
#include "ByteConverter.h"
#include "Common.h"
#include "DB2Meta.h"
#include "Errors.h"
#include "Log.h"
#include <sstream>

DB2FileLoadInfo::DB2FileLoadInfo() : Fields(nullptr), FieldCount(0), Meta(nullptr)
{
}

DB2FileLoadInfo::DB2FileLoadInfo(DB2FieldMeta const* fields, std::size_t fieldCount, DB2Meta const* meta)
    : Fields(fields), FieldCount(fieldCount), Meta(meta)
{
    TypesString.reserve(FieldCount);
    for (std::size_t i = 0; i < FieldCount; ++i)
        TypesString += char(Fields[i].Type);
}

uint32 DB2FileLoadInfo::GetStringFieldCount(bool localizedOnly) const
{
    uint32 stringFields = 0;
    for (char fieldType : TypesString)
        if (fieldType == FT_STRING || (fieldType == FT_STRING_NOT_LOCALIZED && !localizedOnly))
            ++stringFields;

    return stringFields;
}

std::pair<int32, int32> DB2FileLoadInfo::GetFieldIndexByName(char const* fieldName) const
{
    std::size_t ourIndex = Meta->HasIndexFieldInData() ? 0 : 1;
    for (uint32 i = 0; i < Meta->FieldCount; ++i)
    {
        for (uint8 arr = 0; arr < Meta->ArraySizes[i]; ++arr)
        {
            if (!strcmp(Fields[ourIndex].Name, fieldName))
                return std::make_pair(int32(i), int32(arr));

            ++ourIndex;
        }
    }

    return std::make_pair(-1, -1);
}

DB2FileSource::~DB2FileSource()
{
}

class DB2FileLoaderImpl
{
public:
    virtual ~DB2FileLoaderImpl() { }
    virtual bool Load(DB2FileSource* source, DB2FileLoadInfo const* loadInfo, DB2Header const* header) = 0;
    virtual char* AutoProduceData(uint32& count, char**& indexTable, std::vector<char*>& stringPool) = 0;
    virtual char* AutoProduceStrings(char* dataTable, uint32 locale) = 0;
    virtual void AutoProduceRecordCopies(uint32 records, char** indexTable, char* dataTable) = 0;
    virtual DB2Record GetRecord(uint32 recordNumber) const = 0;
    virtual DB2RecordCopy GetRecordCopy(uint32 copyNumber) const = 0;
    virtual uint32 GetRecordCount() const = 0;
    virtual uint32 GetRecordCopyCount() const = 0;
    virtual uint32 GetMaxId() const = 0;
    virtual DB2FileLoadInfo const* GetLoadInfo() const = 0;

private:
    friend class DB2Record;
    virtual unsigned char const* GetRawRecordData(uint32 recordNumber) const = 0;
    virtual uint32 RecordGetId(unsigned char const* record, uint32 recordIndex) const = 0;
    virtual uint8 RecordGetUInt8(unsigned char const* record, uint32 field, uint32 arrayIndex) const = 0;
    virtual uint16 RecordGetUInt16(unsigned char const* record, uint32 field, uint32 arrayIndex) const = 0;
    virtual uint32 RecordGetUInt32(unsigned char const* record, uint32 field, uint32 arrayIndex) const = 0;
    virtual int32 RecordGetInt32(unsigned char const* record, uint32 field, uint32 arrayIndex) const = 0;
    virtual float RecordGetFloat(unsigned char const* record, uint32 field, uint32 arrayIndex) const = 0;
    virtual char const* RecordGetString(unsigned char const* record, uint32 field, uint32 arrayIndex) const = 0;
    virtual std::size_t* RecordCreateDetachedFieldOffsets(std::size_t* oldOffsets) const = 0;
    virtual void RecordDestroyFieldOffsets(std::size_t*& fieldOffsets) const = 0;
};

class DB2FileLoaderRegularImpl final : public DB2FileLoaderImpl
{
public:
    DB2FileLoaderRegularImpl();
    ~DB2FileLoaderRegularImpl();

    bool Load(DB2FileSource* source, DB2FileLoadInfo const* loadInfo, DB2Header const* header) override;
    char* AutoProduceData(uint32& count, char**& indexTable, std::vector<char*>& stringPool) override;
    char* AutoProduceStrings(char* dataTable, uint32 locale) override;
    void AutoProduceRecordCopies(uint32 records, char** indexTable, char* dataTable) override;
    DB2Record GetRecord(uint32 recordNumber) const override;
    DB2RecordCopy GetRecordCopy(uint32 copyNumber) const override;
    uint32 GetRecordCount() const override;
    uint32 GetRecordCopyCount() const override;
    uint32 GetMaxId() const override;
    DB2FileLoadInfo const* GetLoadInfo() const override;

private:
    void FillCommonValues(char** indexTable);
    unsigned char const* GetRawRecordData(uint32 recordNumber) const override;
    uint32 RecordGetId(unsigned char const* record, uint32 recordIndex) const override;
    uint8 RecordGetUInt8(unsigned char const* record, uint32 field, uint32 arrayIndex) const override;
    uint16 RecordGetUInt16(unsigned char const* record, uint32 field, uint32 arrayIndex) const override;
    uint32 RecordGetUInt32(unsigned char const* record, uint32 field, uint32 arrayIndex) const override;
    int32 RecordGetInt32(unsigned char const* record, uint32 field, uint32 arrayIndex) const override;
    float RecordGetFloat(unsigned char const* record, uint32 field, uint32 arrayIndex) const override;
    char const* RecordGetString(unsigned char const* record, uint32 field, uint32 arrayIndex) const override;
    uint32 RecordGetVarInt(unsigned char const* record, uint32 field, uint32 arrayIndex, bool isSigned) const;
    uint16 GetFieldOffset(uint32 field) const;
    uint16 GetFieldSize(uint32 field) const;
    std::size_t* RecordCreateDetachedFieldOffsets(std::size_t* oldOffsets) const override;
    void RecordDestroyFieldOffsets(std::size_t*& fieldOffsets) const override;

#pragma pack(push, 1)
    struct FieldEntry
    {
        uint16 UnusedBits;
        uint16 Offset;
    };
#pragma pack(pop)

    char const* fileName;
    DB2FileLoadInfo const* _loadInfo;

    DB2Header const* _header;

    unsigned char* data;
    unsigned char* stringTable;
    unsigned char* idTable;
    uint32 idTableSize;
    DB2RecordCopy* copyTable;
    FieldEntry* fields;
    unsigned char* commonData;
};

class DB2FileLoaderSparseImpl final : public DB2FileLoaderImpl
{
public:
    DB2FileLoaderSparseImpl();
    ~DB2FileLoaderSparseImpl();

    bool Load(DB2FileSource* source, DB2FileLoadInfo const* loadInfo, DB2Header const* header) override;
    char* AutoProduceData(uint32& records, char**& indexTable, std::vector<char*>& stringPool) override;
    char* AutoProduceStrings(char* dataTable, uint32 locale) override;
    void AutoProduceRecordCopies(uint32 /*records*/, char** /*indexTable*/, char* /*dataTable*/) override { }
    DB2Record GetRecord(uint32 recordNumber) const override;
    DB2RecordCopy GetRecordCopy(uint32 copyNumber) const override;
    uint32 GetRecordCount() const override;
    uint32 GetRecordCopyCount() const override;
    uint32 GetMaxId() const override;
    DB2FileLoadInfo const* GetLoadInfo() const override;

private:
    unsigned char const* GetRawRecordData(uint32 recordNumber) const override;
    uint32 RecordGetId(unsigned char const* record, uint32 recordIndex) const override;
    uint8 RecordGetUInt8(unsigned char const* record, uint32 field, uint32 arrayIndex) const override;
    uint16 RecordGetUInt16(unsigned char const* record, uint32 field, uint32 arrayIndex) const override;
    uint32 RecordGetUInt32(unsigned char const* record, uint32 field, uint32 arrayIndex) const override;
    int32 RecordGetInt32(unsigned char const* record, uint32 field, uint32 arrayIndex) const override;
    float RecordGetFloat(unsigned char const* record, uint32 field, uint32 arrayIndex) const override;
    char const* RecordGetString(unsigned char const* record, uint32 field, uint32 arrayIndex) const override;
    uint32 RecordGetVarInt(unsigned char const* record, uint32 field, uint32 arrayIndex, bool isSigned) const;
    uint16 GetFieldOffset(uint32 field, uint32 arrayIndex) const;
    uint16 GetFieldSize(uint32 field) const;
    std::size_t* RecordCreateDetachedFieldOffsets(std::size_t* oldOffsets) const override;
    void RecordDestroyFieldOffsets(std::size_t*& fieldOffsets) const override;
    void CalculateAndStoreFieldOffsets(unsigned char const* rawRecord) const;

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
    DB2FileLoadInfo const* _loadInfo;
    std::size_t* _fieldAndArrayOffsets;

    DB2Header const* _header;
    FieldEntry* fields;

    std::size_t dataStart;
    unsigned char* data;
    OffsetTableEntry* offsets;
};

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
    commonData = nullptr;
}

bool DB2FileLoaderRegularImpl::Load(DB2FileSource* source, DB2FileLoadInfo const* loadInfo, DB2Header const* header)
{
    _loadInfo = loadInfo;
    _header = header;
    ASSERT(_loadInfo->Meta->IndexField == -1 || _loadInfo->Meta->IndexField == int32(header->IndexField));

    fileName = source->GetFileName();
    fields = new FieldEntry[header->FieldCount];
    if (!source->Read(fields, header->FieldCount * sizeof(FieldEntry)))
        return false;

    if (!_loadInfo->Meta->HasIndexFieldInData())
        idTableSize = header->RecordCount * sizeof(uint32);

    data = new unsigned char[header->RecordSize * header->RecordCount + header->StringTableSize];
    stringTable = data + header->RecordSize * header->RecordCount;

    if (!source->Read(data, header->RecordSize * header->RecordCount + header->StringTableSize))
        return false;

    if (idTableSize)
    {
        idTable = new unsigned char[idTableSize];
        if (!source->Read(idTable, idTableSize))
            return false;
    }

    if (header->CopyTableSize)
    {
        copyTable = new DB2RecordCopy[header->CopyTableSize / sizeof(DB2RecordCopy)];
        if (!source->Read(copyTable, header->CopyTableSize))
            return false;
    }

    if (header->CommonDataSize)
    {
        uint32 commonFieldCount;
        if (!source->Read(&commonFieldCount, sizeof(uint32)))
            return false;

        if (commonFieldCount != header->TotalFieldCount)
            return false;

        commonData = new unsigned char[header->CommonDataSize - sizeof(uint32)];
        if (!source->Read(commonData, header->CommonDataSize - sizeof(uint32)))
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
    delete[] commonData;
}

static char const* const nullStr = "";

char* DB2FileLoaderRegularImpl::AutoProduceData(uint32& records, char**& indexTable, std::vector<char*>& stringPool)
{
    if (_loadInfo->Meta->FieldCount != _header->TotalFieldCount)
        return nullptr;

    //get struct size and index pos
    uint32 recordsize = _loadInfo->Meta->GetRecordSize();

    uint32 maxi = GetMaxId() + 1;

    using index_entry_t = char*;

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
        unsigned char const* rawRecord = GetRawRecordData(y);
        if (!rawRecord)
            continue;

        uint32 indexVal = RecordGetId(rawRecord, y);

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
                        *((float*)(&dataTable[offset])) = RecordGetFloat(rawRecord, x, z);
                        offset += 4;
                        break;
                    case FT_INT:
                        *((uint32*)(&dataTable[offset])) = RecordGetVarInt(rawRecord, x, z, _loadInfo->Fields[fieldIndex].IsSigned);
                        offset += 4;
                        break;
                    case FT_BYTE:
                        *((uint8*)(&dataTable[offset])) = RecordGetUInt8(rawRecord, x, z);
                        offset += 1;
                        break;
                    case FT_SHORT:
                        *((uint16*)(&dataTable[offset])) = RecordGetUInt16(rawRecord, x, z);
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

        for (uint32 x = _header->FieldCount; x < _header->TotalFieldCount; ++x)
        {
            for (uint32 z = 0; z < _loadInfo->Meta->ArraySizes[x]; ++z)
            {
                switch (_loadInfo->TypesString[fieldIndex])
                {
                    case FT_FLOAT:
                        *((float*)(&dataTable[offset])) = _loadInfo->Meta->FieldDefaults[x].AsFloat;
                        offset += 4;
                        break;
                    case FT_INT:
                        *((uint32*)(&dataTable[offset])) = _loadInfo->Meta->FieldDefaults[x].AsUInt32;
                        offset += 4;
                        break;
                    case FT_BYTE:
                        *((uint8*)(&dataTable[offset])) = _loadInfo->Meta->FieldDefaults[x].AsUInt8;
                        offset += 1;
                        break;
                    case FT_SHORT:
                        *((uint16*)(&dataTable[offset])) = _loadInfo->Meta->FieldDefaults[x].AsUInt16;
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

    if (commonData)
        FillCommonValues(indexTable);

    return dataTable;
}

char* DB2FileLoaderRegularImpl::AutoProduceStrings(char* dataTable, uint32 locale)
{
    if (_loadInfo->Meta->FieldCount != _header->TotalFieldCount)
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
        unsigned char const* rawRecord = GetRawRecordData(y);
        uint32 fieldIndex = 0;
        if (!_loadInfo->Meta->HasIndexFieldInData())
        {
            offset += 4;
            ++fieldIndex;
        }

        for (uint32 x = 0; x < _header->TotalFieldCount; ++x)
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
                            char const* st = RecordGetString(rawRecord, x, z);
                            db2str->Str[locale] = stringPool + (st - (char const*)stringTable);
                        }

                        offset += sizeof(char*);
                        break;
                    }
                    case FT_STRING_NOT_LOCALIZED:
                    {
                        char** db2str = (char**)(&dataTable[offset]);
                        char const* st = RecordGetString(rawRecord, x, z);
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
    for (uint32 c = 0; c < GetRecordCopyCount(); ++c)
    {
        DB2RecordCopy copy = GetRecordCopy(c);
        if (copy.SourceRowId && copy.SourceRowId < records && copy.NewRowId < records && indexTable[copy.SourceRowId])
        {
            indexTable[copy.NewRowId] = &dataTable[offset];
            memcpy(indexTable[copy.NewRowId], indexTable[copy.SourceRowId], recordsize);

            if (_loadInfo->Meta->HasIndexFieldInData())
                *((uint32*)(&dataTable[offset + GetFieldOffset(_loadInfo->Meta->GetIndexField())])) = copy.NewRowId;
            else
                *((uint32*)(&dataTable[offset])) = copy.NewRowId;

            offset += recordsize;
        }
    }
}

void DB2FileLoaderRegularImpl::FillCommonValues(char** indexTable)
{
    uint32 fieldOffset = 0;
    if (!_loadInfo->Meta->HasIndexFieldInData())
        fieldOffset += 4;

    unsigned char* commonDataItr = commonData;
    for (uint32 field = 0; field < _header->TotalFieldCount; ++field)
    {
        uint32 numExtraValuesForField = *reinterpret_cast<uint32*>(commonDataItr);
        commonDataItr += sizeof(uint32);
        uint8 dataType = *reinterpret_cast<uint8*>(commonDataItr);
        commonDataItr += sizeof(uint8);
        for (uint32 record = 0; record < numExtraValuesForField; ++record)
        {
            uint32 recordId = *reinterpret_cast<uint32*>(commonDataItr);
            commonDataItr += sizeof(uint32);

            char* recordData = indexTable[recordId];

            switch (dataType)
            {
                case 1:
                {
                    ASSERT(_loadInfo->Meta->Types[field] == FT_SHORT);
                    uint16 value = *reinterpret_cast<uint16*>(commonDataItr);
                    EndianConvert(value);
                    for (uint32 arrayIndex = 0; arrayIndex < _loadInfo->Meta->ArraySizes[field]; ++arrayIndex)
                        *reinterpret_cast<uint16*>(&recordData[fieldOffset + sizeof(uint16) * arrayIndex]) = value;
                    break;
                }
                case 2:
                {
                    ASSERT(_loadInfo->Meta->Types[field] == FT_BYTE);
                    uint8 value = *reinterpret_cast<uint8*>(commonDataItr);
                    for (uint32 arrayIndex = 0; arrayIndex < _loadInfo->Meta->ArraySizes[field]; ++arrayIndex)
                        *reinterpret_cast<uint8*>(&recordData[fieldOffset + sizeof(uint8) * arrayIndex]) = value;
                    break;
                }
                case 3:
                {
                    ASSERT(_loadInfo->Meta->Types[field] == FT_FLOAT);
                    float value = *reinterpret_cast<float*>(commonDataItr);
                    EndianConvert(value);
                    for (uint32 arrayIndex = 0; arrayIndex < _loadInfo->Meta->ArraySizes[field]; ++arrayIndex)
                        *reinterpret_cast<float*>(&recordData[fieldOffset + sizeof(float) * arrayIndex]) = value;
                    break;
                }
                case 4:
                {
                    ASSERT(_loadInfo->Meta->Types[field] == FT_INT);
                    uint32 value = *reinterpret_cast<uint32*>(commonDataItr);
                    EndianConvert(value);
                    for (uint32 arrayIndex = 0; arrayIndex < _loadInfo->Meta->ArraySizes[field]; ++arrayIndex)
                        *reinterpret_cast<uint32*>(&recordData[fieldOffset + sizeof(uint32) * arrayIndex]) = value;
                    break;
                }
                default:
                    ASSERT(false, "Unhandled common value type %d found in %s", dataType, fileName);
                    break;
            }

            commonDataItr += sizeof(uint32);
        }

        switch (_loadInfo->Meta->Types[field])
        {
            case FT_FLOAT:
            case FT_INT:
                fieldOffset += 4 * _loadInfo->Meta->ArraySizes[field];
                break;
            case FT_BYTE:
                fieldOffset += 1 * _loadInfo->Meta->ArraySizes[field];
                break;
            case FT_SHORT:
                fieldOffset += 2 * _loadInfo->Meta->ArraySizes[field];
                break;
            case FT_STRING:
                fieldOffset += sizeof(char*) * _loadInfo->Meta->ArraySizes[field];
                break;
        }
    }
}

DB2Record DB2FileLoaderRegularImpl::GetRecord(uint32 recordNumber) const
{
    return DB2Record(*this, recordNumber, nullptr);
}

DB2RecordCopy DB2FileLoaderRegularImpl::GetRecordCopy(uint32 copyNumber) const
{
    if (copyNumber >= GetRecordCopyCount())
        return DB2RecordCopy{};

    return copyTable[copyNumber];
}

uint32 DB2FileLoaderRegularImpl::GetRecordCount() const
{
    return _header->RecordCount;
}

uint32 DB2FileLoaderRegularImpl::GetRecordCopyCount() const
{
    return _header->CopyTableSize / sizeof(DB2RecordCopy);
}

unsigned char const* DB2FileLoaderRegularImpl::GetRawRecordData(uint32 recordNumber) const
{
    if (recordNumber >= _header->RecordCount)
        return nullptr;

    return data + recordNumber * _header->RecordSize;
}

uint32 DB2FileLoaderRegularImpl::RecordGetId(unsigned char const* record, uint32 recordIndex) const
{
    if (_loadInfo->Meta->HasIndexFieldInData())
        return RecordGetVarInt(record, _loadInfo->Meta->GetIndexField(), 0, false);

    return (reinterpret_cast<uint32 const*>(idTable))[recordIndex];
}

uint8 DB2FileLoaderRegularImpl::RecordGetUInt8(unsigned char const* record, uint32 field, uint32 arrayIndex) const
{
    ASSERT(field < _header->FieldCount);
    ASSERT(GetFieldSize(field) == 1);
    return *reinterpret_cast<uint8 const*>(record + GetFieldOffset(field) + arrayIndex * sizeof(uint8));
}

uint16 DB2FileLoaderRegularImpl::RecordGetUInt16(unsigned char const* record, uint32 field, uint32 arrayIndex) const
{
    ASSERT(field < _header->FieldCount);
    ASSERT(GetFieldSize(field) == 2);
    uint16 val = *reinterpret_cast<uint16 const*>(record + GetFieldOffset(field) + arrayIndex * sizeof(uint16));
    EndianConvert(val);
    return val;
}

uint32 DB2FileLoaderRegularImpl::RecordGetUInt32(unsigned char const* record, uint32 field, uint32 arrayIndex) const
{
    return RecordGetVarInt(record, field, arrayIndex, false);
}

int32 DB2FileLoaderRegularImpl::RecordGetInt32(unsigned char const* record, uint32 field, uint32 arrayIndex) const
{
    return int32(RecordGetVarInt(record, field, arrayIndex, true));
}

float DB2FileLoaderRegularImpl::RecordGetFloat(unsigned char const* record, uint32 field, uint32 arrayIndex) const
{
    ASSERT(field < _header->FieldCount);
    float val = *reinterpret_cast<float const*>(record + GetFieldOffset(field) + arrayIndex * sizeof(float));
    EndianConvert(val);
    return val;
}

char const* DB2FileLoaderRegularImpl::RecordGetString(unsigned char const* record, uint32 field, uint32 arrayIndex) const
{
    ASSERT(field < _header->FieldCount);
    uint32 stringOffset = *reinterpret_cast<uint32 const*>(record + GetFieldOffset(field) + arrayIndex * sizeof(uint32));
    EndianConvert(stringOffset);
    ASSERT(stringOffset < _header->StringTableSize);
    return reinterpret_cast<char*>(stringTable + stringOffset);
}

uint32 DB2FileLoaderRegularImpl::RecordGetVarInt(unsigned char const* record, uint32 field, uint32 arrayIndex, bool isSigned) const
{
    ASSERT(field < _header->FieldCount);
    uint32 val = *reinterpret_cast<uint32 const*>(record + GetFieldOffset(field) + arrayIndex * (4 - fields[field].UnusedBits / 8));
    EndianConvert(val);
    if (isSigned)
        return int32(val) << fields[field].UnusedBits >> fields[field].UnusedBits;

    return val << fields[field].UnusedBits >> fields[field].UnusedBits;
}

uint16 DB2FileLoaderRegularImpl::GetFieldOffset(uint32 field) const
{
    ASSERT(field < _header->FieldCount);
    return fields[field].Offset;
}

uint16 DB2FileLoaderRegularImpl::GetFieldSize(uint32 field) const
{
    ASSERT(field < _header->FieldCount);
    return 4 - fields[field].UnusedBits / 8;
}

std::size_t* DB2FileLoaderRegularImpl::RecordCreateDetachedFieldOffsets(std::size_t* /*oldOffsets*/) const
{
    return nullptr;
}

void DB2FileLoaderRegularImpl::RecordDestroyFieldOffsets(std::size_t*& /*fieldOffsets*/) const
{
}

uint32 DB2FileLoaderRegularImpl::GetMaxId() const
{
    uint32 maxId = 0;
    for (uint32 row = 0; row < _header->RecordCount; ++row)
    {
        uint32 id = RecordGetId(GetRawRecordData(row), row);
        if (id > maxId)
            maxId = id;
    }

    for (uint32 copy = 0; copy < GetRecordCopyCount(); ++copy)
    {
        uint32 id = GetRecordCopy(copy).NewRowId;
        if (id > maxId)
            maxId = id;
    }

    return maxId;
}

DB2FileLoadInfo const* DB2FileLoaderRegularImpl::GetLoadInfo() const
{
    return _loadInfo;
}

DB2FileLoaderSparseImpl::DB2FileLoaderSparseImpl()
{
    fileName = nullptr;
    _loadInfo = nullptr;
    _fieldAndArrayOffsets = nullptr;
    _header = nullptr;
    fields = nullptr;
    dataStart = 0;
    data = nullptr;
    offsets = nullptr;
}

DB2FileLoaderSparseImpl::~DB2FileLoaderSparseImpl()
{
    delete[] _fieldAndArrayOffsets;
    delete[] data;
    delete[] offsets;
    delete[] fields;
}

bool DB2FileLoaderSparseImpl::Load(DB2FileSource* source, DB2FileLoadInfo const* loadInfo, DB2Header const* header)
{
    _loadInfo = loadInfo;
    _header = header;
    fileName = source->GetFileName();

    fields = new FieldEntry[header->FieldCount];
    if (!source->Read(fields, header->FieldCount * sizeof(FieldEntry)))
        return false;

    dataStart = source->GetPosition();

    data = new unsigned char[header->StringTableSize - dataStart];

    if (!source->Read(data, header->StringTableSize - dataStart))
        return false;

    offsets = new OffsetTableEntry[header->MaxId - header->MinId + 1];
    if (!source->Read(offsets, (header->MaxId - header->MinId + 1) * 6))
        return false;

    _fieldAndArrayOffsets = new std::size_t[_loadInfo->Meta->FieldCount + _loadInfo->FieldCount - (!_loadInfo->Meta->HasIndexFieldInData() ? 1 : 0)];
    return true;
}

char* DB2FileLoaderSparseImpl::AutoProduceData(uint32& maxId, char**& indexTable, std::vector<char*>& stringPool)
{
    if (_loadInfo->Meta->FieldCount != _header->FieldCount)
        return nullptr;

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
        unsigned char const* rawRecord = GetRawRecordData(y);
        if (!rawRecord)
            continue;

        uint32 indexVal = RecordGetId(rawRecord, y);
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
                        *((float*)(&dataTable[offset])) = RecordGetFloat(rawRecord, x, z);
                        offset += 4;
                        break;
                    case FT_INT:
                        *((uint32*)(&dataTable[offset])) = RecordGetVarInt(rawRecord, x, z, _loadInfo->Fields[fieldIndex].IsSigned);
                        offset += 4;
                        break;
                    case FT_BYTE:
                        *((uint8*)(&dataTable[offset])) = RecordGetUInt8(rawRecord, x, z);
                        offset += 1;
                        break;
                    case FT_SHORT:
                        *((uint16*)(&dataTable[offset])) = RecordGetUInt16(rawRecord, x, z);
                        offset += 2;
                        break;
                    case FT_STRING:
                    {
                        LocalizedString** slot = (LocalizedString**)(&dataTable[offset]);
                        *slot = (LocalizedString*)(&stringHoldersPool[stringHoldersRecordPoolSize * recordNum + stringFieldOffset]);
                        for (uint32 locale = 0; locale < TOTAL_LOCALES; ++locale)
                            if (_header->Locale & (1 << locale))
                                (*slot)->Str[locale] = stringPtr;
                        strcpy(stringPtr, RecordGetString(rawRecord, x, z));
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
                        strcpy(stringPtr, RecordGetString(rawRecord, x, z));
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
        unsigned char const* rawRecord = GetRawRecordData(y);
        if (!rawRecord)
            continue;

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
                        offset += 4;
                        break;
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
                        LocalizedString* db2str = *(LocalizedString**)(&dataTable[offset]);
                        db2str->Str[locale] = stringPtr;
                        strcpy(stringPtr, RecordGetString(rawRecord, x, z));
                        stringPtr += strlen(stringPtr) + 1;
                        offset += sizeof(char*);
                        break;
                    }
                    case FT_STRING_NOT_LOCALIZED:
                        offset += sizeof(char*);
                        break;
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

DB2Record DB2FileLoaderSparseImpl::GetRecord(uint32 recordNumber) const
{
    return DB2Record(*this, recordNumber, _fieldAndArrayOffsets);
}

DB2RecordCopy DB2FileLoaderSparseImpl::GetRecordCopy(uint32 /*recordId*/) const
{
    return DB2RecordCopy{};
}

uint32 DB2FileLoaderSparseImpl::GetRecordCount() const
{
    return _header->MaxId - _header->MinId + 1;
}

uint32 DB2FileLoaderSparseImpl::GetRecordCopyCount() const
{
    return 0;
}

unsigned char const* DB2FileLoaderSparseImpl::GetRawRecordData(uint32 recordNumber) const
{
    if (recordNumber > (_header->MaxId - _header->MinId) || !offsets[recordNumber].FileOffset || !offsets[recordNumber].RecordSize)
        return nullptr;

    unsigned char const* rawRecord = &data[offsets[recordNumber].FileOffset - dataStart];
    CalculateAndStoreFieldOffsets(rawRecord);
    return rawRecord;
}

uint32 DB2FileLoaderSparseImpl::RecordGetId(unsigned char const* record, uint32 recordIndex) const
{
    if (_loadInfo->Meta->HasIndexFieldInData())
        return RecordGetVarInt(record, _loadInfo->Meta->GetIndexField(), 0, false);

    return _header->MinId + recordIndex;
}

uint8 DB2FileLoaderSparseImpl::RecordGetUInt8(unsigned char const* record, uint32 field, uint32 arrayIndex) const
{
    ASSERT(field < _header->FieldCount);
    ASSERT(GetFieldSize(field) == 1);
    return *reinterpret_cast<uint8 const*>(record + GetFieldOffset(field, arrayIndex));
}

uint16 DB2FileLoaderSparseImpl::RecordGetUInt16(unsigned char const* record, uint32 field, uint32 arrayIndex) const
{
    ASSERT(field < _header->FieldCount);
    ASSERT(GetFieldSize(field) == 2);
    uint16 val = *reinterpret_cast<uint16 const*>(record + GetFieldOffset(field, arrayIndex));
    EndianConvert(val);
    return val;
}

uint32 DB2FileLoaderSparseImpl::RecordGetUInt32(unsigned char const* record, uint32 field, uint32 arrayIndex) const
{
    return RecordGetVarInt(record, field, arrayIndex, false);
}

int32 DB2FileLoaderSparseImpl::RecordGetInt32(unsigned char const* record, uint32 field, uint32 arrayIndex) const
{
    return int32(RecordGetVarInt(record, field, arrayIndex, true));
}

float DB2FileLoaderSparseImpl::RecordGetFloat(unsigned char const* record, uint32 field, uint32 arrayIndex) const
{
    ASSERT(field < _header->FieldCount);
    float val = *reinterpret_cast<float const*>(record + GetFieldOffset(field, arrayIndex));
    EndianConvert(val);
    return val;
}

char const* DB2FileLoaderSparseImpl::RecordGetString(unsigned char const* record, uint32 field, uint32 arrayIndex) const
{
    ASSERT(field < _header->FieldCount);
    return reinterpret_cast<char const*>(record + GetFieldOffset(field, arrayIndex));
}

uint32 DB2FileLoaderSparseImpl::RecordGetVarInt(unsigned char const* record, uint32 field, uint32 arrayIndex, bool isSigned) const
{
    ASSERT(field < _header->FieldCount);
    uint32 val = 0;
    memcpy(&val, record + GetFieldOffset(field, arrayIndex), GetFieldSize(field));
    EndianConvert(val);
    if (isSigned)
        return int32(val) << fields[field].UnusedBits >> fields[field].UnusedBits;

    return val << fields[field].UnusedBits >> fields[field].UnusedBits;
}

uint16 DB2FileLoaderSparseImpl::GetFieldOffset(uint32 field, uint32 arrayIndex) const
{
    return uint16(_fieldAndArrayOffsets[_fieldAndArrayOffsets[field] + arrayIndex]);
}

uint16 DB2FileLoaderSparseImpl::GetFieldSize(uint32 field) const
{
    ASSERT(field < _header->FieldCount);
    return 4 - fields[field].UnusedBits / 8;
}

std::size_t* DB2FileLoaderSparseImpl::RecordCreateDetachedFieldOffsets(std::size_t* oldOffsets) const
{
    if (oldOffsets != _fieldAndArrayOffsets)
        return oldOffsets;

    std::size_t size = _loadInfo->Meta->FieldCount + _loadInfo->FieldCount - (!_loadInfo->Meta->HasIndexFieldInData() ? 1 : 0);
    std::size_t* newOffsets = new std::size_t[size];
    memcpy(newOffsets, _fieldAndArrayOffsets, size * sizeof(std::size_t));
    return newOffsets;
}

void DB2FileLoaderSparseImpl::RecordDestroyFieldOffsets(std::size_t*& fieldOffsets) const
{
    if (fieldOffsets == _fieldAndArrayOffsets)
        return;

    delete[] fieldOffsets;
    fieldOffsets = nullptr;
}

void DB2FileLoaderSparseImpl::CalculateAndStoreFieldOffsets(unsigned char const* rawRecord) const
{
    std::size_t offset = 0;
    uint32 combinedField = _loadInfo->Meta->FieldCount;
    for (uint32 field = 0; field < _loadInfo->Meta->FieldCount; ++field)
    {
        _fieldAndArrayOffsets[field] = combinedField;
        for (uint32 arr = 0; arr < _loadInfo->Meta->ArraySizes[field]; ++arr)
        {
            _fieldAndArrayOffsets[combinedField] = offset;
            switch (_loadInfo->Meta->Types[field])
            {
                case FT_BYTE:
                case FT_SHORT:
                case FT_INT:
                    offset += GetFieldSize(field);
                    break;
                case FT_FLOAT:
                    offset += sizeof(float);
                    break;
                case FT_STRING:
                    offset += strlen(reinterpret_cast<char const*>(rawRecord) + offset) + 1;
                    break;
                default:
                    ASSERT(false, "Unknown format character '%c' found in %s meta", _loadInfo->Meta->Types[field], fileName);
                    break;
            }
            ++combinedField;
        }
    }
}

uint32 DB2FileLoaderSparseImpl::GetMaxId() const
{
    return _header->MaxId;
}

DB2FileLoadInfo const* DB2FileLoaderSparseImpl::GetLoadInfo() const
{
    return _loadInfo;
}

DB2Record::DB2Record(DB2FileLoaderImpl const& db2, uint32 recordIndex, std::size_t* fieldOffsets)
    : _db2(db2), _recordIndex(recordIndex), _recordData(db2.GetRawRecordData(recordIndex)), _fieldOffsets(fieldOffsets)
{
}

DB2Record::~DB2Record()
{
    _db2.RecordDestroyFieldOffsets(_fieldOffsets);
}

DB2Record::operator bool()
{
    return _recordData != nullptr;
}

uint32 DB2Record::GetId() const
{
    return _db2.RecordGetId(_recordData, _recordIndex);
}

uint8 DB2Record::GetUInt8(uint32 field, uint32 arrayIndex) const
{
    return _db2.RecordGetUInt8(_recordData, field, arrayIndex);
}

uint8 DB2Record::GetUInt8(char const* fieldName) const
{
    std::pair<int32, int32> fieldIndex = _db2.GetLoadInfo()->GetFieldIndexByName(fieldName);
    ASSERT(fieldIndex.first != -1, "Field with name %s does not exist!", fieldName);
    return _db2.RecordGetUInt8(_recordData, uint32(fieldIndex.first), uint32(fieldIndex.second));
}

uint16 DB2Record::GetUInt16(uint32 field, uint32 arrayIndex) const
{
    return _db2.RecordGetUInt16(_recordData, field, arrayIndex);
}

uint16 DB2Record::GetUInt16(char const* fieldName) const
{
    std::pair<int32, int32> fieldIndex = _db2.GetLoadInfo()->GetFieldIndexByName(fieldName);
    ASSERT(fieldIndex.first != -1, "Field with name %s does not exist!", fieldName);
    return _db2.RecordGetUInt16(_recordData, uint32(fieldIndex.first), uint32(fieldIndex.second));
}

uint32 DB2Record::GetUInt32(uint32 field, uint32 arrayIndex) const
{
    return _db2.RecordGetUInt32(_recordData, field, arrayIndex);
}

uint32 DB2Record::GetUInt32(char const* fieldName) const
{
    std::pair<int32, int32> fieldIndex = _db2.GetLoadInfo()->GetFieldIndexByName(fieldName);
    ASSERT(fieldIndex.first != -1, "Field with name %s does not exist!", fieldName);
    return _db2.RecordGetUInt32(_recordData, uint32(fieldIndex.first), uint32(fieldIndex.second));
}

int32 DB2Record::GetInt32(uint32 field, uint32 arrayIndex) const
{
    return _db2.RecordGetInt32(_recordData, field, arrayIndex);
}

int32 DB2Record::GetInt32(char const* fieldName) const
{
    std::pair<int32, int32> fieldIndex = _db2.GetLoadInfo()->GetFieldIndexByName(fieldName);
    ASSERT(fieldIndex.first != -1, "Field with name %s does not exist!", fieldName);
    return _db2.RecordGetInt32(_recordData, uint32(fieldIndex.first), uint32(fieldIndex.second));
}

float DB2Record::GetFloat(uint32 field, uint32 arrayIndex) const
{
    return _db2.RecordGetFloat(_recordData, field, arrayIndex);
}

float DB2Record::GetFloat(char const* fieldName) const
{
    std::pair<int32, int32> fieldIndex = _db2.GetLoadInfo()->GetFieldIndexByName(fieldName);
    ASSERT(fieldIndex.first != -1, "Field with name %s does not exist!", fieldName);
    return _db2.RecordGetFloat(_recordData, uint32(fieldIndex.first), uint32(fieldIndex.second));
}

char const* DB2Record::GetString(uint32 field, uint32 arrayIndex) const
{
    return _db2.RecordGetString(_recordData, field, arrayIndex);
}

char const* DB2Record::GetString(char const* fieldName) const
{
    std::pair<int32, int32> fieldIndex = _db2.GetLoadInfo()->GetFieldIndexByName(fieldName);
    ASSERT(fieldIndex.first != -1, "Field with name %s does not exist!", fieldName);
    return _db2.RecordGetString(_recordData, uint32(fieldIndex.first), uint32(fieldIndex.second));
}

void DB2Record::MakePersistent()
{
    _fieldOffsets = _db2.RecordCreateDetachedFieldOffsets(_fieldOffsets);
}

DB2FileLoader::DB2FileLoader() : _impl(nullptr)
{
}

DB2FileLoader::~DB2FileLoader()
{
    delete _impl;
}

bool DB2FileLoader::Load(DB2FileSource* source, DB2FileLoadInfo const* loadInfo)
{
    if (!source->IsOpen())
        return false;

    if (!source->Read(&_header, sizeof(DB2Header)))
        return false;

    EndianConvert(_header.Signature);
    EndianConvert(_header.RecordCount);
    EndianConvert(_header.FieldCount);
    EndianConvert(_header.RecordSize);
    EndianConvert(_header.StringTableSize);
    EndianConvert(_header.TableHash);
    EndianConvert(_header.LayoutHash);
    EndianConvert(_header.MinId);
    EndianConvert(_header.MaxId);
    EndianConvert(_header.Locale);
    EndianConvert(_header.CopyTableSize);
    EndianConvert(_header.Flags);
    EndianConvert(_header.IndexField);
    EndianConvert(_header.TotalFieldCount);
    EndianConvert(_header.CommonDataSize);

    if (_header.Signature != 0x36424457)                        //'WDB6'
        return false;

    if (_header.LayoutHash != loadInfo->Meta->LayoutHash)
        return false;

    if (!(_header.Flags & 0x1))
        _impl = new DB2FileLoaderRegularImpl();
    else
        _impl = new DB2FileLoaderSparseImpl();

    return _impl->Load(source, loadInfo, &_header);
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

uint32 DB2FileLoader::GetRecordCount() const
{
    return _impl->GetRecordCount();
}

uint32 DB2FileLoader::GetRecordCopyCount() const
{
    return _impl->GetRecordCopyCount();
}

uint32 DB2FileLoader::GetMaxId() const
{
    return _impl->GetMaxId();
}

DB2Record DB2FileLoader::GetRecord(uint32 recordNumber) const
{
    return _impl->GetRecord(recordNumber);
}

DB2RecordCopy DB2FileLoader::GetRecordCopy(uint32 copyNumber) const
{
    return _impl->GetRecordCopy(copyNumber);
}
