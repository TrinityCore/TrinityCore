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

enum class DB2ColumnCompression : uint32
{
    None,
    Immediate,
    CommonData,
    Pallet,
    PalletArray
};

#pragma pack(push, 1)

struct DB2FieldEntry
{
    int16 UnusedBits;
    uint16 Offset;
};

struct DB2CatalogEntry
{
    uint32 FileOffset;
    uint16 RecordSize;
};

struct DB2ColumnMeta
{
    uint16 BitOffset;
    uint16 BitSize;
    uint32 AdditionalDataSize;
    DB2ColumnCompression CompressionType;
    union
    {
        struct
        {
            uint32 BitOffset;
            uint32 BitWidth;
            bool Signed;
        } immediate;

        struct
        {
            uint32 Value;
        } commonData;

        struct
        {
            uint32 BitOffset;
            uint32 BitWidth;
            uint32 ArraySize;
        } pallet;
    } CompressionData;
};

struct DB2CommonValue
{
    uint32 RecordId;
    uint32 Value;
};

struct DB2PalletValue
{
    uint32 Value;
};

struct DB2IndexDataInfo
{
    uint32 NumEntries;
    uint32 MinId;
    uint32 MaxId;
};

struct DB2IndexEntry
{
    uint32 ParentId;
    uint32 RecordIndex;
};

#pragma pack(pop)

struct DB2IndexData
{
    DB2IndexDataInfo Info;
    std::unique_ptr<DB2IndexEntry[]> Entries;
};

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
    virtual bool LoadTableData(DB2FileSource* source) = 0;
    virtual bool LoadCatalogData(DB2FileSource* source) = 0;
    virtual void SetAdditionalData(std::unique_ptr<DB2FieldEntry[]> fields, std::unique_ptr<uint32[]> idTable, std::unique_ptr<DB2RecordCopy[]> copyTable,
        std::unique_ptr<DB2ColumnMeta[]> columnMeta, std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> palletValues,
        std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> palletArrayValues, std::unique_ptr<std::unordered_map<uint32, uint32>[]> commonValues,
        std::unique_ptr<DB2IndexData[]> parentIndexes) = 0;
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
    virtual uint32 RecordGetId(uint8 const* record, uint32 recordIndex) const = 0;
    virtual uint8 RecordGetUInt8(uint8 const* record, uint32 field, uint32 arrayIndex) const = 0;
    virtual uint16 RecordGetUInt16(uint8 const* record, uint32 field, uint32 arrayIndex) const = 0;
    virtual uint32 RecordGetUInt32(uint8 const* record, uint32 field, uint32 arrayIndex) const = 0;
    virtual int32 RecordGetInt32(uint8 const* record, uint32 field, uint32 arrayIndex) const = 0;
    virtual uint64 RecordGetUInt64(uint8 const* record, uint32 field, uint32 arrayIndex) const = 0;
    virtual float RecordGetFloat(uint8 const* record, uint32 field, uint32 arrayIndex) const = 0;
    virtual char const* RecordGetString(uint8 const* record, uint32 field, uint32 arrayIndex) const = 0;
    virtual std::size_t* RecordCreateDetachedFieldOffsets(std::size_t* oldOffsets) const = 0;
    virtual void RecordDestroyFieldOffsets(std::size_t*& fieldOffsets) const = 0;
};

class DB2FileLoaderRegularImpl final : public DB2FileLoaderImpl
{
public:
    DB2FileLoaderRegularImpl(char const* fileName, DB2FileLoadInfo const* loadInfo, DB2Header const* header);
    ~DB2FileLoaderRegularImpl();

    bool LoadTableData(DB2FileSource* source) override;
    bool LoadCatalogData(DB2FileSource* /*source*/) override { return true; }
    void SetAdditionalData(std::unique_ptr<DB2FieldEntry[]> fields, std::unique_ptr<uint32[]> idTable, std::unique_ptr<DB2RecordCopy[]> copyTable,
        std::unique_ptr<DB2ColumnMeta[]> columnMeta, std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> palletValues,
        std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> palletArrayValues, std::unique_ptr<std::unordered_map<uint32, uint32>[]> commonValues,
        std::unique_ptr<DB2IndexData[]> parentIndexes) override;
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
    void FillParentLookup(char* dataTable);
    uint8 const* GetRawRecordData(uint32 recordNumber) const override;
    uint32 RecordGetId(uint8 const* record, uint32 recordIndex) const override;
    uint8 RecordGetUInt8(uint8 const* record, uint32 field, uint32 arrayIndex) const override;
    uint16 RecordGetUInt16(uint8 const* record, uint32 field, uint32 arrayIndex) const override;
    uint32 RecordGetUInt32(uint8 const* record, uint32 field, uint32 arrayIndex) const override;
    int32 RecordGetInt32(uint8 const* record, uint32 field, uint32 arrayIndex) const override;
    uint64 RecordGetUInt64(uint8 const* record, uint32 field, uint32 arrayIndex) const override;
    float RecordGetFloat(uint8 const* record, uint32 field, uint32 arrayIndex) const override;
    char const* RecordGetString(uint8 const* record, uint32 field, uint32 arrayIndex) const override;
    template<typename T>
    T RecordGetVarInt(uint8 const* record, uint32 field, uint32 arrayIndex) const;
    uint64 RecordGetPackedValue(uint8 const* packedRecordData, uint32 bitWidth, uint32 bitOffset) const;
    uint16 GetFieldOffset(uint32 field) const;
    std::size_t* RecordCreateDetachedFieldOffsets(std::size_t* oldOffsets) const override;
    void RecordDestroyFieldOffsets(std::size_t*& fieldOffsets) const override;

    char const* _fileName;
    DB2FileLoadInfo const* _loadInfo;
    DB2Header const* _header;
    std::unique_ptr<uint8[]> _data;
    uint8* _stringTable;
    std::unique_ptr<uint32[]> _idTable;
    std::unique_ptr<DB2RecordCopy[]> _copyTable;
    std::unique_ptr<DB2ColumnMeta[]> _columnMeta;
    std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> _palletValues;
    std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> _palletArrayValues;
    std::unique_ptr<std::unordered_map<uint32, uint32>[]> _commonValues;
    std::unique_ptr<DB2IndexData[]> _parentIndexes;
};

class DB2FileLoaderSparseImpl final : public DB2FileLoaderImpl
{
public:
    DB2FileLoaderSparseImpl(char const* fileName, DB2FileLoadInfo const* loadInfo, DB2Header const* header);
    ~DB2FileLoaderSparseImpl();

    bool LoadTableData(DB2FileSource* source) override;
    bool LoadCatalogData(DB2FileSource* source) override;
    void SetAdditionalData(std::unique_ptr<DB2FieldEntry[]> fields, std::unique_ptr<uint32[]> idTable, std::unique_ptr<DB2RecordCopy[]> copyTable,
        std::unique_ptr<DB2ColumnMeta[]> columnMeta, std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> palletValues,
        std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> palletArrayValues, std::unique_ptr<std::unordered_map<uint32, uint32>[]> commonValues,
        std::unique_ptr<DB2IndexData[]> parentIndexes) override;
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
    uint8 const* GetRawRecordData(uint32 recordNumber) const override;
    uint32 RecordGetId(uint8 const* record, uint32 recordIndex) const override;
    uint8 RecordGetUInt8(uint8 const* record, uint32 field, uint32 arrayIndex) const override;
    uint16 RecordGetUInt16(uint8 const* record, uint32 field, uint32 arrayIndex) const override;
    uint32 RecordGetUInt32(uint8 const* record, uint32 field, uint32 arrayIndex) const override;
    int32 RecordGetInt32(uint8 const* record, uint32 field, uint32 arrayIndex) const override;
    uint64 RecordGetUInt64(uint8 const* record, uint32 field, uint32 arrayIndex) const override;
    float RecordGetFloat(uint8 const* record, uint32 field, uint32 arrayIndex) const override;
    char const* RecordGetString(uint8 const* record, uint32 field, uint32 arrayIndex) const override;
    uint32 RecordGetVarInt(uint8 const* record, uint32 field, uint32 arrayIndex, bool isSigned) const;
    uint16 GetFieldOffset(uint32 field, uint32 arrayIndex) const;
    uint16 GetFieldSize(uint32 field) const;
    std::size_t* RecordCreateDetachedFieldOffsets(std::size_t* oldOffsets) const override;
    void RecordDestroyFieldOffsets(std::size_t*& fieldOffsets) const override;
    void CalculateAndStoreFieldOffsets(uint8 const* rawRecord) const;

#pragma pack(push, 1)
#pragma pack(pop)

    char const* _fileName;
    DB2FileLoadInfo const* _loadInfo;
    DB2Header const* _header;
    std::size_t _dataStart;
    std::unique_ptr<uint8[]> _data;
    std::unique_ptr<DB2FieldEntry[]> _fields;
    std::unique_ptr<std::size_t[]> _fieldAndArrayOffsets;
    std::unique_ptr<DB2CatalogEntry[]> _catalog;
};

DB2FileLoaderRegularImpl::DB2FileLoaderRegularImpl(char const* fileName, DB2FileLoadInfo const* loadInfo, DB2Header const* header) :
    _fileName(fileName),
    _loadInfo(loadInfo),
    _header(header),
    _stringTable(nullptr)
{
}

bool DB2FileLoaderRegularImpl::LoadTableData(DB2FileSource* source)
{
    _data = Trinity::make_unique<uint8[]>(_header->RecordSize * _header->RecordCount + _header->StringTableSize);
    _stringTable = &_data[_header->RecordSize * _header->RecordCount];
    return source->Read(_data.get(), _header->RecordSize * _header->RecordCount + _header->StringTableSize);
}

void DB2FileLoaderRegularImpl::SetAdditionalData(std::unique_ptr<DB2FieldEntry[]> /*fields*/, std::unique_ptr<uint32[]> idTable, std::unique_ptr<DB2RecordCopy[]> copyTable,
    std::unique_ptr<DB2ColumnMeta[]> columnMeta, std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> palletValues,
    std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> palletArrayValues, std::unique_ptr<std::unordered_map<uint32, uint32>[]> commonValues,
    std::unique_ptr<DB2IndexData[]> parentIndexes)
{
    _idTable = std::move(idTable);
    _copyTable = std::move(copyTable);
    _columnMeta = std::move(columnMeta);
    _palletValues = std::move(palletValues);
    _palletArrayValues = std::move(palletArrayValues);
    _commonValues = std::move(commonValues);
    _parentIndexes = std::move(parentIndexes);
}

DB2FileLoaderRegularImpl::~DB2FileLoaderRegularImpl()
{
}

static char const* const nullStr = "";

char* DB2FileLoaderRegularImpl::AutoProduceData(uint32& records, char**& indexTable, std::vector<char*>& stringPool)
{
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
                        *((uint32*)(&dataTable[offset])) = RecordGetVarInt<uint32>(rawRecord, x, z);
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
                    case FT_LONG:
                        *((uint64*)(&dataTable[offset])) = RecordGetUInt64(rawRecord, x, z);
                        offset += 8;
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
                        ASSERT(false, "Unknown format character '%c' found in %s meta", _loadInfo->TypesString[x], _fileName);
                        break;
                }
                ++fieldIndex;
            }
        }

        for (uint32 x = _header->FieldCount; x < _loadInfo->Meta->FieldCount; ++x)
        {
            for (uint32 z = 0; z < _loadInfo->Meta->ArraySizes[x]; ++z)
            {
                switch (_loadInfo->TypesString[fieldIndex])
                {
                    case FT_FLOAT:
                        *((float*)(&dataTable[offset])) = 0;
                        offset += 4;
                        break;
                    case FT_INT:
                        *((uint32*)(&dataTable[offset])) = 0;
                        offset += 4;
                        break;
                    case FT_BYTE:
                        *((uint8*)(&dataTable[offset])) = 0;
                        offset += 1;
                        break;
                    case FT_SHORT:
                        *((uint16*)(&dataTable[offset])) = 0;
                        offset += 2;
                        break;
                    case FT_LONG:
                        *((uint64*)(&dataTable[offset])) = 0;
                        offset += 8;
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
                        ASSERT(false, "Unknown format character '%c' found in %s meta", _loadInfo->TypesString[x], _fileName);
                        break;
                }
                ++fieldIndex;
            }
        }
    }

    if (_parentIndexes)
        FillParentLookup(dataTable);

    return dataTable;
}

char* DB2FileLoaderRegularImpl::AutoProduceStrings(char* dataTable, uint32 locale)
{
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

        TC_LOG_ERROR("", "Attempted to load %s which has locales %s as %s. Check if you placed your localized db2 files in correct directory.", _fileName, str.str().c_str(), localeNames[locale]);
        return nullptr;
    }

    char* stringPool = new char[_header->StringTableSize];
    memcpy(stringPool, _stringTable, _header->StringTableSize);

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

        for (uint32 x = 0; x < _loadInfo->Meta->FieldCount; ++x)
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
                    case FT_LONG:
                        offset += 8;
                        break;
                    case FT_STRING:
                    {
                        // fill only not filled entries
                        LocalizedString* db2str = *(LocalizedString**)(&dataTable[offset]);
                        if (db2str->Str[locale] == nullStr)
                        {
                            char const* st = RecordGetString(rawRecord, x, z);
                            db2str->Str[locale] = stringPool + (st - (char const*)_stringTable);
                        }

                        offset += sizeof(char*);
                        break;
                    }
                    case FT_STRING_NOT_LOCALIZED:
                    {
                        char** db2str = (char**)(&dataTable[offset]);
                        char const* st = RecordGetString(rawRecord, x, z);
                        *db2str = stringPool + (st - (char const*)_stringTable);
                        offset += sizeof(char*);
                        break;
                    }
                    default:
                        ASSERT(false, "Unknown format character '%c' found in %s meta", _loadInfo->TypesString[x], _fileName);
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
    uint32 idFieldOffset = _loadInfo->Meta->HasIndexFieldInData() ? GetFieldOffset(_loadInfo->Meta->GetIndexField()) : 0;
    for (uint32 c = 0; c < GetRecordCopyCount(); ++c)
    {
        DB2RecordCopy copy = GetRecordCopy(c);
        if (copy.SourceRowId && copy.SourceRowId < records && copy.NewRowId < records && indexTable[copy.SourceRowId])
        {
            indexTable[copy.NewRowId] = &dataTable[offset];
            memcpy(indexTable[copy.NewRowId], indexTable[copy.SourceRowId], recordsize);
            *((uint32*)(&dataTable[offset + idFieldOffset])) = copy.NewRowId;
            offset += recordsize;
        }
    }
}

void DB2FileLoaderRegularImpl::FillParentLookup(char* dataTable)
{
    int32 parentIdOffset = _loadInfo->Meta->GetParentIndexFieldOffset();
    uint32 recordSize = _loadInfo->Meta->GetRecordSize();
    for (uint32 i = 0; i < _parentIndexes[0].Info.NumEntries; ++i)
    {
        uint32 parentId = _parentIndexes[0].Entries[i].ParentId;
        char* recordData = &dataTable[_parentIndexes[0].Entries[i].RecordIndex * recordSize];

        switch (_loadInfo->Meta->Types[_loadInfo->Meta->ParentIndexField])
        {
            case FT_SHORT:
                *reinterpret_cast<uint16*>(&recordData[parentIdOffset]) = uint16(parentId);
                break;
            case FT_BYTE:
                *reinterpret_cast<uint8*>(&recordData[parentIdOffset]) = uint8(parentId);
                break;
            case FT_INT:
                *reinterpret_cast<uint32*>(&recordData[parentIdOffset]) = parentId;
                break;
            default:
                ASSERT(false, "Unhandled parent id type '%c' found in %s", _loadInfo->Meta->Types[_loadInfo->Meta->ParentIndexField], _fileName);
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

    return _copyTable[copyNumber];
}

uint32 DB2FileLoaderRegularImpl::GetRecordCount() const
{
    return _header->RecordCount;
}

uint32 DB2FileLoaderRegularImpl::GetRecordCopyCount() const
{
    return _header->CopyTableSize / sizeof(DB2RecordCopy);
}

uint8 const* DB2FileLoaderRegularImpl::GetRawRecordData(uint32 recordNumber) const
{
    if (recordNumber >= _header->RecordCount)
        return nullptr;

    return &_data[recordNumber * _header->RecordSize];
}

uint32 DB2FileLoaderRegularImpl::RecordGetId(uint8 const* record, uint32 recordIndex) const
{
    if (_loadInfo->Meta->HasIndexFieldInData())
        return RecordGetVarInt<uint32>(record, _loadInfo->Meta->GetIndexField(), 0);

    return _idTable[recordIndex];
}

uint8 DB2FileLoaderRegularImpl::RecordGetUInt8(uint8 const* record, uint32 field, uint32 arrayIndex) const
{
    return RecordGetVarInt<uint8>(record, field, arrayIndex);
}

uint16 DB2FileLoaderRegularImpl::RecordGetUInt16(uint8 const* record, uint32 field, uint32 arrayIndex) const
{
    return RecordGetVarInt<uint16>(record, field, arrayIndex);
}

uint32 DB2FileLoaderRegularImpl::RecordGetUInt32(uint8 const* record, uint32 field, uint32 arrayIndex) const
{
    return RecordGetVarInt<uint32>(record, field, arrayIndex);
}

int32 DB2FileLoaderRegularImpl::RecordGetInt32(uint8 const* record, uint32 field, uint32 arrayIndex) const
{
    return RecordGetVarInt<int32>(record, field, arrayIndex);
}

uint64 DB2FileLoaderRegularImpl::RecordGetUInt64(uint8 const* record, uint32 field, uint32 arrayIndex) const
{
    return RecordGetVarInt<uint64>(record, field, arrayIndex);
}

float DB2FileLoaderRegularImpl::RecordGetFloat(uint8 const* record, uint32 field, uint32 arrayIndex) const
{
    return RecordGetVarInt<float>(record, field, arrayIndex);
}

char const* DB2FileLoaderRegularImpl::RecordGetString(uint8 const* record, uint32 field, uint32 arrayIndex) const
{
    uint32 stringOffset = RecordGetVarInt<uint32>(record, field, arrayIndex);
    ASSERT(stringOffset < _header->StringTableSize);
    return reinterpret_cast<char*>(_stringTable + stringOffset);
}

template<typename T>
T DB2FileLoaderRegularImpl::RecordGetVarInt(uint8 const* record, uint32 field, uint32 arrayIndex) const
{
    ASSERT(field < _header->FieldCount);
    switch (_columnMeta[field].CompressionType)
    {
        case DB2ColumnCompression::None:
        {
            T val = *reinterpret_cast<T const*>(record + GetFieldOffset(field) + sizeof(T) * arrayIndex);
            EndianConvert(val);
            return val;
        }
        case DB2ColumnCompression::Immediate:
        {
            ASSERT(arrayIndex == 0);
            uint64 immediateValue = RecordGetPackedValue(record + GetFieldOffset(field),
                _columnMeta[field].CompressionData.immediate.BitWidth, _columnMeta[field].CompressionData.immediate.BitOffset);
            EndianConvert(immediateValue);
            if (_columnMeta[field].CompressionData.immediate.Signed)
            {
                uint64 mask = UI64LIT(1) << (_columnMeta[field].CompressionData.immediate.BitWidth - 1);
                immediateValue = (immediateValue ^ mask) - mask;
            }
            T value;
            memcpy(&value, &immediateValue, std::min(sizeof(T), sizeof(immediateValue)));
            return value;
        }
        case DB2ColumnCompression::CommonData:
        {
            uint32 id = RecordGetId(record, (_data.get() - record) / _header->RecordSize);
            T value;
            auto valueItr = _commonValues[field].find(id);
            if (valueItr != _commonValues[field].end())
                memcpy(&value, &valueItr->second, std::min(sizeof(T), sizeof(uint32)));
            else
                memcpy(&value, &_columnMeta[field].CompressionData.commonData.Value, std::min(sizeof(T), sizeof(uint32)));
            return value;
        }
        case DB2ColumnCompression::Pallet:
        {
            ASSERT(arrayIndex == 0);
            uint64 palletIndex = RecordGetPackedValue(record + GetFieldOffset(field),
                _columnMeta[field].CompressionData.pallet.BitWidth, _columnMeta[field].CompressionData.pallet.BitOffset);
            EndianConvert(palletIndex);
            uint32 palletValue = _palletValues[field][palletIndex].Value;
            EndianConvert(palletValue);
            T value;
            memcpy(&value, &palletValue, std::min(sizeof(T), sizeof(palletValue)));
            return value;
        }
        case DB2ColumnCompression::PalletArray:
        {
            uint64 palletIndex = RecordGetPackedValue(record + GetFieldOffset(field),
                _columnMeta[field].CompressionData.pallet.BitWidth, _columnMeta[field].CompressionData.pallet.BitOffset);
            EndianConvert(palletIndex);
            uint32 palletValue = _palletArrayValues[field][palletIndex * _columnMeta[field].CompressionData.pallet.ArraySize + arrayIndex].Value;
            EndianConvert(palletValue);
            T value;
            memcpy(&value, &palletValue, std::min(sizeof(T), sizeof(palletValue)));
            return value;
        }
        default:
            ASSERT(false, "Unhandled compression type %u in %s", uint32(_columnMeta[field].CompressionType), _fileName);
            break;
    }

    return 0;
}

uint64 DB2FileLoaderRegularImpl::RecordGetPackedValue(uint8 const* packedRecordData, uint32 bitWidth, uint32 bitOffset) const
{
    uint32 bitsToRead = bitOffset & 7;
    return *reinterpret_cast<uint64 const*>(packedRecordData) << (64 - bitsToRead - bitWidth) >> (64 - bitWidth);
}

uint16 DB2FileLoaderRegularImpl::GetFieldOffset(uint32 field) const
{
    ASSERT(field < _header->FieldCount);
    switch (_columnMeta[field].CompressionType)
    {
        case DB2ColumnCompression::None:
            return _columnMeta[field].BitOffset / 8;
        case DB2ColumnCompression::Immediate:
            return _columnMeta[field].CompressionData.immediate.BitOffset / 8 + _header->PackedDataOffset;
        case DB2ColumnCompression::CommonData:
            return 0xFFFF;
        case DB2ColumnCompression::Pallet:
        case DB2ColumnCompression::PalletArray:
            return _columnMeta[field].CompressionData.pallet.BitOffset / 8 + _header->PackedDataOffset;
        default:
            ASSERT(false, "Unhandled compression type %u in %s", uint32(_columnMeta[field].CompressionType), _fileName);
            break;
    }

    return 0;
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

DB2FileLoaderSparseImpl::DB2FileLoaderSparseImpl(char const* fileName, DB2FileLoadInfo const* loadInfo, DB2Header const* header) :
    _fileName(fileName),
    _loadInfo(loadInfo),
    _header(header),
    _dataStart(0),
    _fieldAndArrayOffsets(Trinity::make_unique<std::size_t[]>(loadInfo->Meta->FieldCount + loadInfo->FieldCount - (!loadInfo->Meta->HasIndexFieldInData() ? 1 : 0)))
{
}

DB2FileLoaderSparseImpl::~DB2FileLoaderSparseImpl()
{
}

bool DB2FileLoaderSparseImpl::LoadTableData(DB2FileSource* source)
{
    _dataStart = source->GetPosition();
    _data = Trinity::make_unique<uint8[]>(_header->CatalogDataOffset - _dataStart);
    return source->Read(_data.get(), _header->CatalogDataOffset - _dataStart);
}

bool DB2FileLoaderSparseImpl::LoadCatalogData(DB2FileSource* source)
{
    _catalog = Trinity::make_unique<DB2CatalogEntry[]>(_header->MaxId - _header->MinId + 1);
    return source->Read(_catalog.get(), sizeof(DB2CatalogEntry) * (_header->MaxId - _header->MinId + 1));
}

void DB2FileLoaderSparseImpl::SetAdditionalData(std::unique_ptr<DB2FieldEntry[]> fields, std::unique_ptr<uint32[]> /*idTable*/, std::unique_ptr<DB2RecordCopy[]> /*copyTable*/,
    std::unique_ptr<DB2ColumnMeta[]> /*columnMeta*/, std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> /*palletValues*/,
    std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> /*palletArrayValues*/, std::unique_ptr<std::unordered_map<uint32, uint32>[]> /*commonValues*/,
    std::unique_ptr<DB2IndexData[]> /*parentIndexes*/)
{
    _fields = std::move(fields);
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
        if (_catalog[i].FileOffset && _catalog[i].RecordSize)
        {
            ++records;
            expandedDataSize += _catalog[i].RecordSize;
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
                    case FT_LONG:
                        *((uint64*)(&dataTable[offset])) = RecordGetUInt64(rawRecord, x, z);
                        offset += 8;
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
                        ASSERT(false, "Unknown format character '%c' found in %s meta", _loadInfo->TypesString[x], _fileName);
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

        TC_LOG_ERROR("", "Attempted to load %s which has locales %s as %s. Check if you placed your localized db2 files in correct directory.", _fileName, str.str().c_str(), localeNames[locale]);
        return nullptr;
    }

    uint32 offsetCount = _header->MaxId - _header->MinId + 1;
    uint32 records = 0;
    for (uint32 i = 0; i < offsetCount; ++i)
        if (_catalog[i].FileOffset && _catalog[i].RecordSize)
            ++records;

    uint32 recordsize = _loadInfo->Meta->GetRecordSize();
    std::size_t stringFields = _loadInfo->GetStringFieldCount(true);
    char* stringTable = new char[_header->CatalogDataOffset - _dataStart - records * ((recordsize - (!_loadInfo->Meta->HasIndexFieldInData() ? 4 : 0)) - stringFields * sizeof(char*))];
    memset(stringTable, 0, _header->CatalogDataOffset - _dataStart - records * ((recordsize - (!_loadInfo->Meta->HasIndexFieldInData() ? 4 : 0)) - stringFields * sizeof(char*)));
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
                    case FT_LONG:
                        offset += 8;
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
                        ASSERT(false, "Unknown format character '%c' found in %s meta", _loadInfo->TypesString[x], _fileName);
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
    return DB2Record(*this, recordNumber, _fieldAndArrayOffsets.get());
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

uint8 const* DB2FileLoaderSparseImpl::GetRawRecordData(uint32 recordNumber) const
{
    if (recordNumber > (_header->MaxId - _header->MinId) || !_catalog[recordNumber].FileOffset || !_catalog[recordNumber].RecordSize)
        return nullptr;

    uint8 const* rawRecord = &_data[_catalog[recordNumber].FileOffset - _dataStart];
    CalculateAndStoreFieldOffsets(rawRecord);
    return rawRecord;
}

uint32 DB2FileLoaderSparseImpl::RecordGetId(uint8 const* record, uint32 recordIndex) const
{
    if (_loadInfo->Meta->HasIndexFieldInData())
        return RecordGetVarInt(record, _loadInfo->Meta->GetIndexField(), 0, false);

    return _header->MinId + recordIndex;
}

uint8 DB2FileLoaderSparseImpl::RecordGetUInt8(uint8 const* record, uint32 field, uint32 arrayIndex) const
{
    ASSERT(field < _header->FieldCount);
    return *reinterpret_cast<uint8 const*>(record + GetFieldOffset(field, arrayIndex));
}

uint16 DB2FileLoaderSparseImpl::RecordGetUInt16(uint8 const* record, uint32 field, uint32 arrayIndex) const
{
    ASSERT(field < _header->FieldCount);
    uint16 val = *reinterpret_cast<uint16 const*>(record + GetFieldOffset(field, arrayIndex));
    EndianConvert(val);
    return val;
}

uint32 DB2FileLoaderSparseImpl::RecordGetUInt32(uint8 const* record, uint32 field, uint32 arrayIndex) const
{
    return RecordGetVarInt(record, field, arrayIndex, false);
}

int32 DB2FileLoaderSparseImpl::RecordGetInt32(uint8 const* record, uint32 field, uint32 arrayIndex) const
{
    return int32(RecordGetVarInt(record, field, arrayIndex, true));
}

uint64 DB2FileLoaderSparseImpl::RecordGetUInt64(uint8 const* record, uint32 field, uint32 arrayIndex) const
{
    ASSERT(field < _header->FieldCount);
    uint64 val = *reinterpret_cast<uint64 const*>(record + GetFieldOffset(field, arrayIndex));
    EndianConvert(val);
    return val;
}

float DB2FileLoaderSparseImpl::RecordGetFloat(uint8 const* record, uint32 field, uint32 arrayIndex) const
{
    ASSERT(field < _header->FieldCount);
    float val = *reinterpret_cast<float const*>(record + GetFieldOffset(field, arrayIndex));
    EndianConvert(val);
    return val;
}

char const* DB2FileLoaderSparseImpl::RecordGetString(uint8 const* record, uint32 field, uint32 arrayIndex) const
{
    ASSERT(field < _header->FieldCount);
    return reinterpret_cast<char const*>(record + GetFieldOffset(field, arrayIndex));
}

uint32 DB2FileLoaderSparseImpl::RecordGetVarInt(uint8 const* record, uint32 field, uint32 arrayIndex, bool isSigned) const
{
    ASSERT(field < _header->FieldCount);
    uint32 val = 0;
    memcpy(&val, record + GetFieldOffset(field, arrayIndex), GetFieldSize(field));
    EndianConvert(val);
    if (isSigned)
        return int32(val) << _fields[field].UnusedBits >> _fields[field].UnusedBits;

    return val << _fields[field].UnusedBits >> _fields[field].UnusedBits;
}

uint16 DB2FileLoaderSparseImpl::GetFieldOffset(uint32 field, uint32 arrayIndex) const
{
    return uint16(_fieldAndArrayOffsets[_fieldAndArrayOffsets[field] + arrayIndex]);
}

uint16 DB2FileLoaderSparseImpl::GetFieldSize(uint32 field) const
{
    ASSERT(field < _header->FieldCount);
    return 4 - _fields[field].UnusedBits / 8;
}

std::size_t* DB2FileLoaderSparseImpl::RecordCreateDetachedFieldOffsets(std::size_t* oldOffsets) const
{
    if (oldOffsets != _fieldAndArrayOffsets.get())
        return oldOffsets;

    std::size_t size = _loadInfo->Meta->FieldCount + _loadInfo->FieldCount - (!_loadInfo->Meta->HasIndexFieldInData() ? 1 : 0);
    std::size_t* newOffsets = new std::size_t[size];
    memcpy(newOffsets, _fieldAndArrayOffsets.get(), size * sizeof(std::size_t));
    return newOffsets;
}

void DB2FileLoaderSparseImpl::RecordDestroyFieldOffsets(std::size_t*& fieldOffsets) const
{
    if (fieldOffsets == _fieldAndArrayOffsets.get())
        return;

    delete[] fieldOffsets;
    fieldOffsets = nullptr;
}

void DB2FileLoaderSparseImpl::CalculateAndStoreFieldOffsets(uint8 const* rawRecord) const
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
                case FT_LONG:
                    offset += GetFieldSize(field);
                    break;
                case FT_FLOAT:
                    offset += sizeof(float);
                    break;
                case FT_STRING:
                    offset += strlen(reinterpret_cast<char const*>(rawRecord) + offset) + 1;
                    break;
                default:
                    ASSERT(false, "Unknown format character '%c' found in %s meta", _loadInfo->Meta->Types[field], _fileName);
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

uint64 DB2Record::GetUInt64(uint32 field, uint32 arrayIndex) const
{
    return _db2.RecordGetUInt64(_recordData, field, arrayIndex);
}

uint64 DB2Record::GetUInt64(char const* fieldName) const
{
    std::pair<int32, int32> fieldIndex = _db2.GetLoadInfo()->GetFieldIndexByName(fieldName);
    ASSERT(fieldIndex.first != -1, "Field with name %s does not exist!", fieldName);
    return _db2.RecordGetUInt64(_recordData, uint32(fieldIndex.first), uint32(fieldIndex.second));
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
    EndianConvert(_header.PackedDataOffset);
    EndianConvert(_header.ParentLookupCount);
    EndianConvert(_header.CatalogDataOffset);
    EndianConvert(_header.IdTableSize);
    EndianConvert(_header.ColumnMetaSize);
    EndianConvert(_header.CommonDataSize);
    EndianConvert(_header.PalletDataSize);
    EndianConvert(_header.ParentLookupDataSize);

    if (_header.Signature != 0x31434457)                        //'WCH1'
        return false;

    if (_header.LayoutHash != loadInfo->Meta->LayoutHash)
        return false;

    if (!(_header.Flags & 0x1))
    {
        std::size_t expectedFileSize =
            sizeof(DB2Header) +
            sizeof(DB2FieldEntry) * _header.FieldCount +
            _header.RecordCount * _header.RecordSize +
            _header.StringTableSize +
            _header.IdTableSize +
            _header.CopyTableSize +
            _header.ColumnMetaSize +
            _header.PalletDataSize +
            _header.CommonDataSize +
            _header.ParentLookupDataSize;

        if (source->GetFileSize() != expectedFileSize)
            return false;
    }

    if (_header.ParentLookupCount > 1)
        return false;

    if (_header.TotalFieldCount + (loadInfo->Meta->ParentIndexField >= int32(_header.TotalFieldCount) ? 1 : 0) != loadInfo->Meta->FieldCount)
        return false;

    if (_header.ParentLookupCount && loadInfo->Meta->ParentIndexField == -1)
        return false;

    if (!(_header.Flags & 0x1))
        _impl = new DB2FileLoaderRegularImpl(source->GetFileName(), loadInfo, &_header);
    else
        _impl = new DB2FileLoaderSparseImpl(source->GetFileName(), loadInfo, &_header);

    std::unique_ptr<DB2FieldEntry[]> fieldData = Trinity::make_unique<DB2FieldEntry[]>(_header.FieldCount);
    if (!source->Read(fieldData.get(), sizeof(DB2FieldEntry) * _header.FieldCount))
        return false;

    if (!_impl->LoadTableData(source))
        return false;

    if (!_impl->LoadCatalogData(source))
        return false;

    ASSERT(!loadInfo->Meta->HasIndexFieldInData() || _header.IdTableSize == 0);
    ASSERT(loadInfo->Meta->HasIndexFieldInData() || _header.IdTableSize == 4 * _header.RecordCount);

    std::unique_ptr<uint32[]> idTable;
    if (!loadInfo->Meta->HasIndexFieldInData() && _header.IdTableSize)
    {
        idTable = Trinity::make_unique<uint32[]>(_header.RecordCount);
        if (!source->Read(idTable.get(), _header.IdTableSize))
            return false;
    }

    std::unique_ptr<DB2RecordCopy[]> copyTable;
    if (_header.CopyTableSize)
    {
        copyTable = Trinity::make_unique<DB2RecordCopy[]>(_header.CopyTableSize / sizeof(DB2RecordCopy));
        if (!source->Read(copyTable.get(), _header.CopyTableSize))
            return false;
    }

    std::unique_ptr<DB2ColumnMeta[]> columnMeta;
    std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> palletValues;
    std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> palletArrayValues;
    std::unique_ptr<std::unordered_map<uint32, uint32>[]> commonValues;
    if (_header.ColumnMetaSize)
    {
        columnMeta = Trinity::make_unique<DB2ColumnMeta[]>(_header.TotalFieldCount);
        if (!source->Read(columnMeta.get(), _header.ColumnMetaSize))
            return false;

        ASSERT(!loadInfo->Meta->HasIndexFieldInData() ||
            columnMeta[loadInfo->Meta->IndexField].CompressionType == DB2ColumnCompression::None ||
            columnMeta[loadInfo->Meta->IndexField].CompressionType == DB2ColumnCompression::Immediate);

        palletValues = Trinity::make_unique<std::unique_ptr<DB2PalletValue[]>[]>(_header.TotalFieldCount);
        for (uint32 i = 0; i < _header.TotalFieldCount; ++i)
        {
            if (columnMeta[i].CompressionType != DB2ColumnCompression::Pallet)
                continue;

            palletValues[i] = Trinity::make_unique<DB2PalletValue[]>(columnMeta[i].AdditionalDataSize / sizeof(DB2PalletValue));
            if (!source->Read(palletValues[i].get(), columnMeta[i].AdditionalDataSize))
                return false;
        }

        palletArrayValues = Trinity::make_unique<std::unique_ptr<DB2PalletValue[]>[]>(_header.TotalFieldCount);
        for (uint32 i = 0; i < _header.TotalFieldCount; ++i)
        {
            if (columnMeta[i].CompressionType != DB2ColumnCompression::PalletArray)
                continue;

            palletArrayValues[i] = Trinity::make_unique<DB2PalletValue[]>(columnMeta[i].AdditionalDataSize / sizeof(DB2PalletValue));
            if (!source->Read(palletArrayValues[i].get(), columnMeta[i].AdditionalDataSize))
                return false;
        }

        std::unique_ptr<std::unique_ptr<DB2CommonValue[]>[]> commonData = Trinity::make_unique<std::unique_ptr<DB2CommonValue[]>[]>(_header.TotalFieldCount);
        commonValues = Trinity::make_unique<std::unordered_map<uint32, uint32>[]>(_header.TotalFieldCount);
        for (uint32 i = 0; i < _header.TotalFieldCount; ++i)
        {
            if (columnMeta[i].CompressionType != DB2ColumnCompression::CommonData)
                continue;

            if (!columnMeta[i].AdditionalDataSize)
                continue;

            commonData[i] = Trinity::make_unique<DB2CommonValue[]>(columnMeta[i].AdditionalDataSize / sizeof(DB2CommonValue));
            if (!source->Read(commonData[i].get(), columnMeta[i].AdditionalDataSize))
                return false;

            uint32 numExtraValuesForField = columnMeta[i].AdditionalDataSize / sizeof(DB2CommonValue);
            for (uint32 record = 0; record < numExtraValuesForField; ++record)
            {
                uint32 recordId = commonData[i][record].RecordId;
                uint32 value = commonData[i][record].Value;
                EndianConvert(value);
                commonValues[i][recordId] = value;
            }
        }
    }

    std::unique_ptr<DB2IndexData[]> parentIndexes;
    if (_header.ParentLookupCount)
    {
        parentIndexes = Trinity::make_unique<DB2IndexData[]>(_header.ParentLookupCount);
        for (uint32 i = 0; i < _header.ParentLookupCount; ++i)
        {
            if (!source->Read(&parentIndexes[i].Info, sizeof(DB2IndexDataInfo)))
                return false;

            if (!parentIndexes[i].Info.NumEntries)
                continue;

            parentIndexes[i].Entries = Trinity::make_unique<DB2IndexEntry[]>(parentIndexes[i].Info.NumEntries);
            if (!source->Read(parentIndexes[i].Entries.get(), sizeof(DB2IndexEntry) * parentIndexes[i].Info.NumEntries))
                return false;
        }
    }

    _impl->SetAdditionalData(std::move(fieldData), std::move(idTable), std::move(copyTable), std::move(columnMeta),
        std::move(palletValues), std::move(palletArrayValues), std::move(commonValues), std::move(parentIndexes));

    return true;
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
