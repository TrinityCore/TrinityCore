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
    PalletArray,
    SignedImmediate
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
    std::vector<DB2IndexEntry> Entries;
};

DB2FieldMeta::DB2FieldMeta(bool isSigned, DBCFormer type, char const* name)
    : IsSigned(isSigned), Type(type), Name(name)
{
}

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
        for (uint8 arr = 0; arr < Meta->Fields[i].ArraySize; ++arr)
        {
            if (!strcmp(Fields[ourIndex].Name, fieldName))
                return std::make_pair(int32(i), int32(arr));

            ++ourIndex;
        }
    }

    return std::make_pair(-1, -1);
}

int32 DB2FileLoadInfo::GetFieldIndexByMetaIndex(uint32 metaIndex) const
{
    ASSERT(metaIndex < Meta->FieldCount);
    int32 ourIndex = Meta->HasIndexFieldInData() ? 0 : 1;
    for (uint32 i = 0; i < metaIndex; ++i)
        ourIndex += Meta->Fields[i].ArraySize;

    return ourIndex;
}

DB2FileSource::~DB2FileSource()
{
}

class DB2FileLoaderImpl
{
public:
    virtual ~DB2FileLoaderImpl() { }
    virtual void LoadColumnData(std::unique_ptr<DB2SectionHeader[]> sections, std::unique_ptr<DB2FieldEntry[]> fields, std::unique_ptr<DB2ColumnMeta[]> columnMeta,
        std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> palletValues, std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> palletArrayValues,
        std::unique_ptr<std::unordered_map<uint32, uint32>[]> commonValues) = 0;
    virtual void SkipEncryptedSection(uint32 section) = 0;
    virtual bool LoadTableData(DB2FileSource* source, uint32 section) = 0;
    virtual bool LoadCatalogData(DB2FileSource* source, uint32 section) = 0;
    virtual void SetAdditionalData(std::vector<uint32> idTable, std::vector<DB2RecordCopy> copyTable, std::vector<std::vector<DB2IndexData>> parentIndexes) = 0;
    virtual char* AutoProduceData(uint32& count, char**& indexTable, std::vector<char*>& stringPool) = 0;
    virtual char* AutoProduceStrings(char** indexTable, uint32 indexTableSize, uint32 locale) = 0;
    virtual void AutoProduceRecordCopies(uint32 records, char** indexTable, char* dataTable) = 0;
    virtual DB2Record GetRecord(uint32 recordNumber) const = 0;
    virtual DB2RecordCopy GetRecordCopy(uint32 copyNumber) const = 0;
    virtual uint32 GetRecordCount() const = 0;
    virtual uint32 GetRecordCopyCount() const = 0;
    virtual uint32 GetMaxId() const = 0;
    virtual DB2FileLoadInfo const* GetLoadInfo() const = 0;
    virtual DB2SectionHeader const& GetSection(uint32 section) const = 0;
    virtual bool IsSignedField(uint32 field) const = 0;

private:
    friend class DB2Record;
    virtual unsigned char const* GetRawRecordData(uint32 recordNumber, uint32 const* section) const = 0;
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

    void LoadColumnData(std::unique_ptr<DB2SectionHeader[]> sections, std::unique_ptr<DB2FieldEntry[]> fields, std::unique_ptr<DB2ColumnMeta[]> columnMeta,
        std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> palletValues, std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> palletArrayValues,
        std::unique_ptr<std::unordered_map<uint32, uint32>[]> commonValues) override;
    void SkipEncryptedSection(uint32 /*section*/) override { }
    bool LoadTableData(DB2FileSource* source, uint32 section) override;
    bool LoadCatalogData(DB2FileSource* /*source*/, uint32 /*section*/) override { return true; }
    void SetAdditionalData(std::vector<uint32> idTable, std::vector<DB2RecordCopy> copyTable, std::vector<std::vector<DB2IndexData>> parentIndexes) override;
    char* AutoProduceData(uint32& count, char**& indexTable, std::vector<char*>& stringPool) override;
    char* AutoProduceStrings(char** indexTable, uint32 indexTableSize, uint32 locale) override;
    void AutoProduceRecordCopies(uint32 records, char** indexTable, char* dataTable) override;
    DB2Record GetRecord(uint32 recordNumber) const override;
    DB2RecordCopy GetRecordCopy(uint32 copyNumber) const override;
    uint32 GetRecordCount() const override;
    uint32 GetRecordCopyCount() const override;
    uint32 GetMaxId() const override;
    DB2FileLoadInfo const* GetLoadInfo() const override;
    DB2SectionHeader const& GetSection(uint32 section) const override;
    bool IsSignedField(uint32 field) const override;

private:
    void FillParentLookup(char* dataTable);
    uint32 GetRecordSection(uint32 recordNumber) const;
    unsigned char const* GetRawRecordData(uint32 recordNumber, uint32 const* section) const override;
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
    std::unique_ptr<DB2SectionHeader[]> _sections;
    std::unique_ptr<DB2ColumnMeta[]> _columnMeta;
    std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> _palletValues;
    std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> _palletArrayValues;
    std::unique_ptr<std::unordered_map<uint32, uint32>[]> _commonValues;
    std::vector<uint32> _idTable;
    std::vector<DB2RecordCopy> _copyTable;
    std::vector<std::vector<DB2IndexData>> _parentIndexes;
};

class DB2FileLoaderSparseImpl final : public DB2FileLoaderImpl
{
public:
    DB2FileLoaderSparseImpl(char const* fileName, DB2FileLoadInfo const* loadInfo, DB2Header const* header, DB2FileSource* source);
    ~DB2FileLoaderSparseImpl();

    void LoadColumnData(std::unique_ptr<DB2SectionHeader[]> sections, std::unique_ptr<DB2FieldEntry[]> fields, std::unique_ptr<DB2ColumnMeta[]> columnMeta,
        std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> palletValues, std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> palletArrayValues,
        std::unique_ptr<std::unordered_map<uint32, uint32>[]> commonValues) override;
    void SkipEncryptedSection(uint32 section) override;
    bool LoadTableData(DB2FileSource* /*source*/, uint32 /*section*/) override { return true; }
    bool LoadCatalogData(DB2FileSource* source, uint32 section) override;
    void SetAdditionalData(std::vector<uint32> idTable, std::vector<DB2RecordCopy> copyTable, std::vector<std::vector<DB2IndexData>> parentIndexes) override;
    char* AutoProduceData(uint32& records, char**& indexTable, std::vector<char*>& stringPool) override;
    char* AutoProduceStrings(char** indexTable, uint32 indexTableSize, uint32 locale) override;
    void AutoProduceRecordCopies(uint32 records, char** indexTable, char* dataTable) override;
    DB2Record GetRecord(uint32 recordNumber) const override;
    DB2RecordCopy GetRecordCopy(uint32 copyNumber) const override;
    uint32 GetRecordCount() const override;
    uint32 GetRecordCopyCount() const override;
    uint32 GetMaxId() const override;
    DB2FileLoadInfo const* GetLoadInfo() const override;
    DB2SectionHeader const& GetSection(uint32 section) const override;
    bool IsSignedField(uint32 field) const override;

private:
    void FillParentLookup(char* dataTable);
    uint32 GetRecordSection(uint32 recordNumber) const;
    unsigned char const* GetRawRecordData(uint32 recordNumber, uint32 const* section) const override;
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
    DB2FileSource* const _source;
    std::size_t _totalRecordSize;
    uint16 _maxRecordSize;
    std::unique_ptr<uint8[]> _recordBuffer;
    std::unique_ptr<DB2SectionHeader[]> _sections;
    std::unique_ptr<DB2FieldEntry[]> _fields;
    std::unique_ptr<std::size_t[]> _fieldAndArrayOffsets;
    std::vector<uint32> _catalogIds;
    std::vector<DB2CatalogEntry> _catalog;
    std::vector<DB2RecordCopy> _copyTable;
    std::vector<std::vector<DB2IndexData>> _parentIndexes;
};

DB2FileLoaderRegularImpl::DB2FileLoaderRegularImpl(char const* fileName, DB2FileLoadInfo const* loadInfo, DB2Header const* header) :
    _fileName(fileName),
    _loadInfo(loadInfo),
    _header(header),
    _stringTable(nullptr)
{
}

void DB2FileLoaderRegularImpl::LoadColumnData(std::unique_ptr<DB2SectionHeader[]> sections, std::unique_ptr<DB2FieldEntry[]> /*fields*/, std::unique_ptr<DB2ColumnMeta[]> columnMeta,
    std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> palletValues, std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> palletArrayValues,
    std::unique_ptr<std::unordered_map<uint32, uint32>[]> commonValues)
{
    _sections = std::move(sections);
    _columnMeta = std::move(columnMeta);
    _palletValues = std::move(palletValues);
    _palletArrayValues = std::move(palletArrayValues);
    _commonValues = std::move(commonValues);
}

bool DB2FileLoaderRegularImpl::LoadTableData(DB2FileSource* source, uint32 section)
{
    if (!_data)
    {
        _data = Trinity::make_unique<uint8[]>(_header->RecordSize * _header->RecordCount + _header->StringTableSize + 8);
        _stringTable = &_data[_header->RecordSize * _header->RecordCount];
    }

    uint32 sectionDataStart = 0;
    uint32 sectionStringTableStart = 0;
    for (uint32 i = 0; i < section; ++i)
    {
        sectionDataStart += _header->RecordSize * _sections[i].RecordCount;
        sectionStringTableStart += _sections[i].StringTableSize;
    }

    if (_sections[section].RecordCount && !source->Read(&_data[sectionDataStart], _header->RecordSize * _sections[section].RecordCount))
        return false;

    if (_sections[section].StringTableSize && !source->Read(&_stringTable[sectionStringTableStart], _sections[section].StringTableSize))
        return false;

    return true;
}

void DB2FileLoaderRegularImpl::SetAdditionalData(std::vector<uint32> idTable, std::vector<DB2RecordCopy> copyTable, std::vector<std::vector<DB2IndexData>> parentIndexes)
{
    _idTable = std::move(idTable);
    _copyTable = std::move(copyTable);
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

    char* dataTable = new char[(_header->RecordCount + _copyTable.size()) * recordsize];

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
    uint32 y = 0;

    for (uint32 section = 0; section < _header->SectionCount; ++section)
    {
        DB2SectionHeader const& sectionHeader = GetSection(section);
        if (sectionHeader.TactId)
        {
            offset += recordsize * sectionHeader.RecordCount;
            y += sectionHeader.RecordCount;
            continue;
        }

        for (uint32 sr = 0; sr < sectionHeader.RecordCount; ++sr, ++y)
        {
            unsigned char const* rawRecord = GetRawRecordData(y, &section);
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
                for (uint32 z = 0; z < _loadInfo->Meta->Fields[x].ArraySize; ++z)
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
                            ASSERT(false, "Unknown format character '%c' found in %s meta for field %s",
                                _loadInfo->TypesString[fieldIndex], _fileName, _loadInfo->Fields[fieldIndex].Name);
                            break;
                    }
                    ++fieldIndex;
                }
            }

            for (uint32 x = _header->FieldCount; x < _loadInfo->Meta->FieldCount; ++x)
            {
                for (uint32 z = 0; z < _loadInfo->Meta->Fields[x].ArraySize; ++z)
                {
                    switch (_loadInfo->TypesString[fieldIndex])
                    {
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
                        default:
                            ASSERT(false, "Unknown format character '%c' found in %s meta for parent field %s",
                                _loadInfo->TypesString[fieldIndex], _fileName, _loadInfo->Fields[fieldIndex].Name);
                            break;
                    }
                    ++fieldIndex;
                }
            }
        }
    }

    if (!_parentIndexes.empty())
        FillParentLookup(dataTable);

    return dataTable;
}

char* DB2FileLoaderRegularImpl::AutoProduceStrings(char** indexTable, uint32 indexTableSize, uint32 locale)
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

    uint32 y = 0;

    for (uint32 section = 0; section < _header->SectionCount; ++section)
    {
        DB2SectionHeader const& sectionHeader = GetSection(section);
        if (sectionHeader.TactId)
        {
            y += sectionHeader.RecordCount;
            continue;
        }

        for (uint32 sr = 0; sr < sectionHeader.RecordCount; ++sr, ++y)
        {
            unsigned char const* rawRecord = GetRawRecordData(y, &section);
            if (!rawRecord)
                continue;

            uint32 indexVal = RecordGetId(rawRecord, y);
            if (indexVal >= indexTableSize)
                continue;

            char* recordData = indexTable[indexVal];

            uint32 offset = 0;
            uint32 fieldIndex = 0;
            if (!_loadInfo->Meta->HasIndexFieldInData())
            {
                offset += 4;
                ++fieldIndex;
            }

            for (uint32 x = 0; x < _loadInfo->Meta->FieldCount; ++x)
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
                            LocalizedString* db2str = *(LocalizedString * *)(&recordData[offset]);
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
                            char** db2str = (char**)(&recordData[offset]);
                            char const* st = RecordGetString(rawRecord, x, z);
                            *db2str = stringPool + (st - (char const*)_stringTable);
                            offset += sizeof(char*);
                            break;
                        }
                        default:
                            ASSERT(false, "Unknown format character '%c' found in %s meta for field %s",
                                _loadInfo->TypesString[fieldIndex], _fileName, _loadInfo->Fields[fieldIndex].Name);
                            break;
                    }
                    ++fieldIndex;
                }
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
    uint32 recordIndexOffset = 0;
    for (uint32 i = 0; i < _header->SectionCount; ++i)
    {
        DB2SectionHeader const& section = GetSection(i);
        if (!section.TactId)
        {
            for (std::size_t j = 0; j < _parentIndexes[i][0].Entries.size(); ++j)
            {
                uint32 parentId = _parentIndexes[i][0].Entries[j].ParentId;
                char* recordData = &dataTable[(_parentIndexes[i][0].Entries[j].RecordIndex + recordIndexOffset) * recordSize];

                switch (_loadInfo->Meta->Fields[_loadInfo->Meta->ParentIndexField].Type)
                {
                    case FT_SHORT:
                    {
                        if (_loadInfo->Meta->ParentIndexField >= int32(_loadInfo->Meta->FileFieldCount))
                        {
                            // extra field at the end
                            *reinterpret_cast<uint32*>(&recordData[parentIdOffset]) = parentId;
                        }
                        else
                        {
                            // in data block, must fit
                            ASSERT(parentId <= 0xFFFF, "ParentId value %u does not fit into uint16 field (%s in %s)",
                                parentId, _loadInfo->Fields[_loadInfo->GetFieldIndexByMetaIndex(_loadInfo->Meta->ParentIndexField)].Name, _fileName);
                            *reinterpret_cast<uint16*>(&recordData[parentIdOffset]) = parentId;
                        }
                        break;
                    }
                    case FT_BYTE:
                    {
                        if (_loadInfo->Meta->ParentIndexField >= int32(_loadInfo->Meta->FileFieldCount))
                        {
                            // extra field at the end
                            *reinterpret_cast<uint32*>(&recordData[parentIdOffset]) = parentId;
                        }
                        else
                        {
                            // in data block, must fit
                            ASSERT(parentId <= 0xFF, "ParentId value %u does not fit into uint8 field (%s in %s)",
                                parentId, _loadInfo->Fields[_loadInfo->GetFieldIndexByMetaIndex(_loadInfo->Meta->ParentIndexField)].Name, _fileName);
                            *reinterpret_cast<uint8*>(&recordData[parentIdOffset]) = parentId;
                        }
                        break;
                    }
                    case FT_INT:
                        *reinterpret_cast<uint32*>(&recordData[parentIdOffset]) = parentId;
                        break;
                    default:
                        ASSERT(false, "Unhandled parent id type '%c' found in %s", _loadInfo->Meta->Fields[_loadInfo->Meta->ParentIndexField].Type, _fileName);
                        break;
                }
            }
        }
        recordIndexOffset += section.RecordCount;
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
    return _copyTable.size();
}

uint32 DB2FileLoaderRegularImpl::GetRecordSection(uint32 recordNumber) const
{
    uint32 section = 0;
    for (; section < _header->SectionCount; ++section)
    {
        DB2SectionHeader const& sectionHeader = GetSection(section);
        if (recordNumber < sectionHeader.RecordCount)
            break;

        recordNumber -= sectionHeader.RecordCount;
    }

    return section;
}

unsigned char const* DB2FileLoaderRegularImpl::GetRawRecordData(uint32 recordNumber, uint32 const* section) const
{
    if (recordNumber >= _header->RecordCount)
        return nullptr;

    if (GetSection(section ? *section : GetRecordSection(recordNumber)).TactId)
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
    uint32 fieldOffset = GetFieldOffset(field) + sizeof(uint32) * arrayIndex;
    uint32 stringOffset = RecordGetVarInt<uint32>(record, field, arrayIndex);
    ASSERT(stringOffset < _header->RecordSize * _header->RecordCount + _header->StringTableSize);
    return reinterpret_cast<char const*>(record + fieldOffset + stringOffset);
}

template<typename T>
T DB2FileLoaderRegularImpl::RecordGetVarInt(uint8 const* record, uint32 field, uint32 arrayIndex) const
{
    ASSERT(field < _header->FieldCount);
    DB2ColumnCompression compressionType = _columnMeta ? _columnMeta[field].CompressionType : DB2ColumnCompression::None;
    switch (compressionType)
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
        case DB2ColumnCompression::SignedImmediate:
        {
            ASSERT(arrayIndex == 0);
            uint64 immediateValue = RecordGetPackedValue(record + GetFieldOffset(field),
                _columnMeta[field].CompressionData.immediate.BitWidth, _columnMeta[field].CompressionData.immediate.BitOffset);
            EndianConvert(immediateValue);
            uint64 mask = UI64LIT(1) << (_columnMeta[field].CompressionData.immediate.BitWidth - 1);
            immediateValue = (immediateValue ^ mask) - mask;
            T value;
            memcpy(&value, &immediateValue, std::min(sizeof(T), sizeof(immediateValue)));
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
    DB2ColumnCompression compressionType = _columnMeta ? _columnMeta[field].CompressionType : DB2ColumnCompression::None;
    switch (compressionType)
    {
        case DB2ColumnCompression::None:
            return _columnMeta[field].BitOffset / 8;
        case DB2ColumnCompression::Immediate:
        case DB2ColumnCompression::SignedImmediate:
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
        unsigned char const* rawRecord = GetRawRecordData(row, nullptr);
        if (!rawRecord)
            continue;

        uint32 id = RecordGetId(rawRecord, row);
        if (id > maxId)
            maxId = id;
    }

    for (uint32 copy = 0; copy < GetRecordCopyCount(); ++copy)
    {
        uint32 id = GetRecordCopy(copy).NewRowId;
        if (id > maxId)
            maxId = id;
    }

    ASSERT(maxId <= _header->MaxId);
    return maxId;
}

DB2FileLoadInfo const* DB2FileLoaderRegularImpl::GetLoadInfo() const
{
    return _loadInfo;
}

DB2SectionHeader const& DB2FileLoaderRegularImpl::GetSection(uint32 section) const
{
    return _sections[section];
}

bool DB2FileLoaderRegularImpl::IsSignedField(uint32 field) const
{
    if (field >= _header->TotalFieldCount)
    {
        ASSERT(field == _header->TotalFieldCount);
        ASSERT(int32(field) == _loadInfo->Meta->ParentIndexField);
        return _loadInfo->Meta->IsSignedField(field);
    }

    DB2ColumnCompression compressionType = _columnMeta ? _columnMeta[field].CompressionType : DB2ColumnCompression::None;
    switch (compressionType)
    {
        case DB2ColumnCompression::None:
        case DB2ColumnCompression::CommonData:
        case DB2ColumnCompression::Pallet:
        case DB2ColumnCompression::PalletArray:
            return _loadInfo->Meta->IsSignedField(field);
        case DB2ColumnCompression::SignedImmediate:
            return field != uint32(_loadInfo->Meta->IndexField);
        case DB2ColumnCompression::Immediate:
            return false;
        default:
            ASSERT(false, "Unhandled compression type %u in %s", uint32(_columnMeta[field].CompressionType), _fileName);
            break;
    }

    return false;
}

DB2FileLoaderSparseImpl::DB2FileLoaderSparseImpl(char const* fileName, DB2FileLoadInfo const* loadInfo, DB2Header const* header, DB2FileSource* source) :
    _fileName(fileName),
    _loadInfo(loadInfo),
    _header(header),
    _source(source),
    _totalRecordSize(0),
    _maxRecordSize(0),
    _fieldAndArrayOffsets(loadInfo ? (Trinity::make_unique<std::size_t[]>(loadInfo->Meta->FieldCount + loadInfo->FieldCount - (!loadInfo->Meta->HasIndexFieldInData() ? 1 : 0))) : nullptr)
{
}

DB2FileLoaderSparseImpl::~DB2FileLoaderSparseImpl()
{
}

void DB2FileLoaderSparseImpl::LoadColumnData(std::unique_ptr<DB2SectionHeader[]> sections, std::unique_ptr<DB2FieldEntry[]> fields, std::unique_ptr<DB2ColumnMeta[]> /*columnMeta*/,
    std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> /*palletValues*/, std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> /*palletArrayValues*/,
    std::unique_ptr<std::unordered_map<uint32, uint32>[]> /*commonValues*/)
{
    _sections = std::move(sections);
    _fields = std::move(fields);
}

void DB2FileLoaderSparseImpl::SkipEncryptedSection(uint32 section)
{
    _catalogIds.resize(_catalogIds.size() + _sections[section].CatalogDataCount);
    _catalog.resize(_catalog.size() + _sections[section].CatalogDataCount);
}

bool DB2FileLoaderSparseImpl::LoadCatalogData(DB2FileSource* source, uint32 section)
{
    source->SetPosition(_sections[section].CatalogDataOffset);

    std::size_t oldSize = _catalog.size();
    _catalogIds.resize(oldSize + _sections[section].CatalogDataCount);
    if (!source->Read(&_catalogIds[oldSize], sizeof(uint32) * _sections[section].CatalogDataCount))
        return false;

    if (_sections[section].CopyTableCount)
    {
        std::size_t oldCopyTableSize = _copyTable.size();
        _copyTable.resize(oldCopyTableSize + _sections[section].CopyTableCount);
        if (!source->Read(&_copyTable[oldCopyTableSize], sizeof(DB2RecordCopy) * _sections[section].CopyTableCount))
            return false;
    }

    _catalog.resize(oldSize + _sections[section].CatalogDataCount);
    if (!source->Read(&_catalog[oldSize], sizeof(DB2CatalogEntry) * _sections[section].CatalogDataCount))
        return false;

    for (uint32 i = 0; i < _sections[section].CatalogDataCount; ++i)
    {
        _totalRecordSize += _catalog[oldSize + i].RecordSize;
        _maxRecordSize = std::max(_maxRecordSize, _catalog[oldSize + i].RecordSize);
    }

    return true;
}

void DB2FileLoaderSparseImpl::SetAdditionalData(std::vector<uint32> /*idTable*/, std::vector<DB2RecordCopy> /*copyTable*/, std::vector<std::vector<DB2IndexData>> parentIndexes)
{
    _parentIndexes = std::move(parentIndexes);
    _recordBuffer = Trinity::make_unique<uint8[]>(_maxRecordSize);
}

char* DB2FileLoaderSparseImpl::AutoProduceData(uint32& maxId, char**& indexTable, std::vector<char*>& stringPool)
{
    if (_loadInfo->Meta->FieldCount != _header->FieldCount)
        return nullptr;

    //get struct size and index pos
    uint32 recordsize = _loadInfo->Meta->GetRecordSize();
    uint32 records = _catalog.size();

    using index_entry_t = char*;

    maxId = _header->MaxId + 1;
    indexTable = new index_entry_t[maxId];
    memset(indexTable, 0, maxId * sizeof(index_entry_t));

    char* dataTable = new char[(records + _copyTable.size()) * recordsize];

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

    char* stringTable = new char[_totalRecordSize - records * ((recordsize - (!_loadInfo->Meta->HasIndexFieldInData() ? 4 : 0)) - stringFields * sizeof(char*))];
    memset(stringTable, 0, _totalRecordSize - records * ((recordsize - (!_loadInfo->Meta->HasIndexFieldInData() ? 4 : 0)) - stringFields * sizeof(char*)));
    stringPool.push_back(stringTable);
    char* stringPtr = stringTable;

    uint32 offset = 0;
    uint32 recordNum = 0;
    uint32 y = 0;

    for (uint32 section = 0; section < _header->SectionCount; ++section)
    {
        DB2SectionHeader const& sectionHeader = GetSection(section);
        if (sectionHeader.TactId)
        {
            offset += recordsize * sectionHeader.RecordCount;
            y += sectionHeader.RecordCount;
            continue;
        }

        for (uint32 sr = 0; sr < sectionHeader.CatalogDataCount; ++sr, ++y)
        {
            unsigned char const* rawRecord = GetRawRecordData(y, &section);
            if (!rawRecord)
                continue;

            uint32 indexVal = _catalogIds[y];
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
                for (uint32 z = 0; z < _loadInfo->Meta->Fields[x].ArraySize; ++z)
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
                            LocalizedString** slot = (LocalizedString * *)(&dataTable[offset]);
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
                            ASSERT(false, "Unknown format character '%c' found in %s meta for field %s",
                                _loadInfo->TypesString[fieldIndex], _fileName, _loadInfo->Fields[fieldIndex].Name);
                            break;
                    }
                    ++fieldIndex;
                }
            }

            for (uint32 x = _header->FieldCount; x < _loadInfo->Meta->FieldCount; ++x)
            {
                for (uint32 z = 0; z < _loadInfo->Meta->Fields[x].ArraySize; ++z)
                {
                    switch (_loadInfo->TypesString[fieldIndex])
                    {
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
                        default:
                            ASSERT(false, "Unknown format character '%c' found in %s meta for parent field %s",
                                _loadInfo->TypesString[fieldIndex], _fileName, _loadInfo->Fields[fieldIndex].Name);
                            break;
                    }
                    ++fieldIndex;
                }
            }

            ++recordNum;
        }
    }

    return dataTable;
}

char* DB2FileLoaderSparseImpl::AutoProduceStrings(char** indexTable, uint32 indexTableSize, uint32 locale)
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

    uint32 records = _catalog.size();
    uint32 recordsize = _loadInfo->Meta->GetRecordSize();
    std::size_t stringFields = _loadInfo->GetStringFieldCount(true);
    char* stringTable = new char[_totalRecordSize - records * ((recordsize - (!_loadInfo->Meta->HasIndexFieldInData() ? 4 : 0)) - stringFields * sizeof(char*))];
    memset(stringTable, 0, _totalRecordSize - records * ((recordsize - (!_loadInfo->Meta->HasIndexFieldInData() ? 4 : 0)) - stringFields * sizeof(char*)));
    char* stringPtr = stringTable;

    uint32 y = 0;

    for (uint32 section = 0; section < _header->SectionCount; ++section)
    {
        DB2SectionHeader const& sectionHeader = GetSection(section);
        if (sectionHeader.TactId)
        {
            y += sectionHeader.RecordCount;
            continue;
        }

        for (uint32 sr = 0; sr < sectionHeader.CatalogDataCount; ++sr, ++y)
        {
            unsigned char const* rawRecord = GetRawRecordData(y, &section);
            if (!rawRecord)
                continue;

            uint32 indexVal = _catalogIds[y];
            if (indexVal >= indexTableSize)
                continue;

            char* recordData = indexTable[indexVal];

            uint32 offset = 0;
            uint32 fieldIndex = 0;
            if (!_loadInfo->Meta->HasIndexFieldInData())
            {
                offset += 4;
                ++fieldIndex;
            }

            for (uint32 x = 0; x < _header->FieldCount; ++x)
            {
                for (uint32 z = 0; z < _loadInfo->Meta->Fields[x].ArraySize; ++z)
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
                            LocalizedString* db2str = *(LocalizedString * *)(&recordData[offset]);
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
                            ASSERT(false, "Unknown format character '%c' found in %s meta for field %s",
                                _loadInfo->TypesString[fieldIndex], _fileName, _loadInfo->Fields[fieldIndex].Name);
                            break;
                    }
                    ++fieldIndex;
                }
            }
        }
    }

    return stringTable;
}

void DB2FileLoaderSparseImpl::AutoProduceRecordCopies(uint32 records, char** indexTable, char* dataTable)
{
    uint32 recordsize = _loadInfo->Meta->GetRecordSize();
    uint32 offset = _header->RecordCount * recordsize;
    uint32 idFieldOffset = _loadInfo->Meta->HasIndexFieldInData() ? _loadInfo->Meta->GetIndexFieldOffset() : 0;
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

DB2Record DB2FileLoaderSparseImpl::GetRecord(uint32 recordNumber) const
{
    return DB2Record(*this, recordNumber, _fieldAndArrayOffsets.get());
}

DB2RecordCopy DB2FileLoaderSparseImpl::GetRecordCopy(uint32 copyNumber) const
{
    if (copyNumber >= GetRecordCopyCount())
        return DB2RecordCopy{};

    return _copyTable[copyNumber];
}

uint32 DB2FileLoaderSparseImpl::GetRecordCount() const
{
    return _catalog.size();
}

uint32 DB2FileLoaderSparseImpl::GetRecordCopyCount() const
{
    return _copyTable.size();
}

void DB2FileLoaderSparseImpl::FillParentLookup(char* dataTable)
{
    int32 parentIdOffset = _loadInfo->Meta->GetParentIndexFieldOffset();
    uint32 recordSize = _loadInfo->Meta->GetRecordSize();
    uint32 recordIndexOffset = 0;
    for (uint32 i = 0; i < _header->SectionCount; ++i)
    {
        DB2SectionHeader const& section = GetSection(i);
        if (!section.TactId)
        {
            for (std::size_t j = 0; j < _parentIndexes[i][0].Entries.size(); ++j)
            {
                uint32 parentId = _parentIndexes[i][0].Entries[j].ParentId;
                char* recordData = &dataTable[(_parentIndexes[i][0].Entries[j].RecordIndex + recordIndexOffset) * recordSize];

                switch (_loadInfo->Meta->Fields[_loadInfo->Meta->ParentIndexField].Type)
                {
                    case FT_SHORT:
                    {
                        if (_loadInfo->Meta->ParentIndexField >= int32(_loadInfo->Meta->FileFieldCount))
                        {
                            // extra field at the end
                            *reinterpret_cast<uint32*>(&recordData[parentIdOffset]) = parentId;
                        }
                        else
                        {
                            // in data block, must fit
                            ASSERT(parentId <= 0xFFFF, "ParentId value %u does not fit into uint16 field (%s in %s)",
                                parentId, _loadInfo->Fields[_loadInfo->GetFieldIndexByMetaIndex(_loadInfo->Meta->ParentIndexField)].Name, _fileName);
                            *reinterpret_cast<uint16*>(&recordData[parentIdOffset]) = parentId;
                        }
                        break;
                    }
                    case FT_BYTE:
                    {
                        if (_loadInfo->Meta->ParentIndexField >= int32(_loadInfo->Meta->FileFieldCount))
                        {
                            // extra field at the end
                            *reinterpret_cast<uint32*>(&recordData[parentIdOffset]) = parentId;
                        }
                        else
                        {
                            // in data block, must fit
                            ASSERT(parentId <= 0xFF, "ParentId value %u does not fit into uint8 field (%s in %s)",
                                parentId, _loadInfo->Fields[_loadInfo->GetFieldIndexByMetaIndex(_loadInfo->Meta->ParentIndexField)].Name, _fileName);
                            *reinterpret_cast<uint8*>(&recordData[parentIdOffset]) = parentId;
                        }
                        break;
                    }
                    case FT_INT:
                        *reinterpret_cast<uint32*>(&recordData[parentIdOffset]) = parentId;
                        break;
                    default:
                        ASSERT(false, "Unhandled parent id type '%c' found in %s", _loadInfo->Meta->Fields[_loadInfo->Meta->ParentIndexField].Type, _fileName);
                        break;
                }
            }
        }
        recordIndexOffset += section.RecordCount;
    }
}

uint32 DB2FileLoaderSparseImpl::GetRecordSection(uint32 recordNumber) const
{
    uint32 section = 0;
    for (; section < _header->SectionCount; ++section)
    {
        DB2SectionHeader const& sectionHeader = GetSection(section);
        if (recordNumber < sectionHeader.CatalogDataCount)
            break;

        recordNumber -= sectionHeader.CatalogDataCount;
    }

    return section;
}

unsigned char const* DB2FileLoaderSparseImpl::GetRawRecordData(uint32 recordNumber, uint32 const* section) const
{
    if (recordNumber >= _catalog.size())
        return nullptr;

    if (GetSection(section ? *section : GetRecordSection(recordNumber)).TactId)
        return nullptr;

    _source->SetPosition(_catalog[recordNumber].FileOffset);
    uint8* rawRecord = _recordBuffer.get();
    if (!_source->Read(rawRecord, _catalog[recordNumber].RecordSize))
        return nullptr;

    CalculateAndStoreFieldOffsets(rawRecord);
    return rawRecord;
}

uint32 DB2FileLoaderSparseImpl::RecordGetId(uint8 const* record, uint32 recordIndex) const
{
    if (_loadInfo->Meta->HasIndexFieldInData())
        return RecordGetVarInt(record, _loadInfo->Meta->GetIndexField(), 0, false);

    return _catalogIds[recordIndex];
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
        for (uint32 arr = 0; arr < _loadInfo->Meta->Fields[field].ArraySize; ++arr)
        {
            _fieldAndArrayOffsets[combinedField] = offset;
            switch (_loadInfo->Meta->Fields[field].Type)
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
                case FT_STRING_NOT_LOCALIZED:
                    offset += strlen(reinterpret_cast<char const*>(rawRecord) + offset) + 1;
                    break;
                default:
                    ASSERT(false, "Unknown format character '%c' found in %s meta", _loadInfo->Meta->Fields[field].Type, _fileName);
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

DB2SectionHeader const& DB2FileLoaderSparseImpl::GetSection(uint32 section) const
{
    return _sections[section];
}

bool DB2FileLoaderSparseImpl::IsSignedField(uint32 field) const
{
    ASSERT(field < _header->FieldCount);
    return _loadInfo->Meta->IsSignedField(field);
}

DB2Record::DB2Record(DB2FileLoaderImpl const& db2, uint32 recordIndex, std::size_t* fieldOffsets)
    : _db2(db2), _recordIndex(recordIndex), _recordData(db2.GetRawRecordData(recordIndex, nullptr)), _fieldOffsets(fieldOffsets)
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

bool DB2FileLoader::LoadHeaders(DB2FileSource* source, DB2FileLoadInfo const* loadInfo)
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
    EndianConvert(_header.Flags);
    EndianConvert(_header.IndexField);
    EndianConvert(_header.TotalFieldCount);
    EndianConvert(_header.PackedDataOffset);
    EndianConvert(_header.ParentLookupCount);
    EndianConvert(_header.ColumnMetaSize);
    EndianConvert(_header.CommonDataSize);
    EndianConvert(_header.PalletDataSize);
    EndianConvert(_header.SectionCount);

    if (_header.Signature != 0x33434457)                        //'WDC3'
        return false;

    if (loadInfo && _header.LayoutHash != loadInfo->Meta->LayoutHash)
        return false;

    if (_header.ParentLookupCount > 1)
        return false;

    if (loadInfo && (_header.TotalFieldCount + (loadInfo->Meta->ParentIndexField >= int32(_header.TotalFieldCount) ? 1 : 0) != loadInfo->Meta->FieldCount))
        return false;

    if (loadInfo && (_header.ParentLookupCount && loadInfo->Meta->ParentIndexField == -1))
        return false;

    std::unique_ptr<DB2SectionHeader[]> sections = Trinity::make_unique<DB2SectionHeader[]>(_header.SectionCount);
    if (_header.SectionCount && !source->Read(sections.get(), sizeof(DB2SectionHeader) * _header.SectionCount))
        return false;

    uint32 totalCopyTableSize = 0;
    uint32 totalParentLookupDataSize = 0;
    for (uint32 i = 0; i < _header.SectionCount; ++i)
    {
        totalCopyTableSize += sections[i].CopyTableCount * sizeof(DB2RecordCopy);
        totalParentLookupDataSize += sections[i].ParentLookupDataSize;
    }

    if (loadInfo && !(_header.Flags & 0x1))
    {
        int64 expectedFileSize =
            sizeof(DB2Header) +
            sizeof(DB2SectionHeader) * _header.SectionCount +
            sizeof(DB2FieldEntry) * _header.FieldCount +
            _header.RecordCount * _header.RecordSize +
            _header.StringTableSize +
            (loadInfo->Meta->IndexField == -1 ? _header.RecordCount * sizeof(uint32) : 0) +
            totalCopyTableSize +
            _header.ColumnMetaSize +
            _header.PalletDataSize +
            _header.CommonDataSize +
            totalParentLookupDataSize;

        if (source->GetFileSize() != expectedFileSize)
            return false;
    }

    std::unique_ptr<DB2FieldEntry[]> fieldData = Trinity::make_unique<DB2FieldEntry[]>(_header.FieldCount);
    if (!source->Read(fieldData.get(), sizeof(DB2FieldEntry) * _header.FieldCount))
        return false;

    std::unique_ptr<DB2ColumnMeta[]> columnMeta;
    std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> palletValues;
    std::unique_ptr<std::unique_ptr<DB2PalletValue[]>[]> palletArrayValues;
    std::unique_ptr<std::unordered_map<uint32, uint32>[]> commonValues;
    if (_header.ColumnMetaSize)
    {
        columnMeta = Trinity::make_unique<DB2ColumnMeta[]>(_header.TotalFieldCount);
        if (!source->Read(columnMeta.get(), _header.ColumnMetaSize))
            return false;

        if (loadInfo)
        {
            ASSERT(!loadInfo->Meta->HasIndexFieldInData() ||
                columnMeta[loadInfo->Meta->IndexField].CompressionType == DB2ColumnCompression::None ||
                columnMeta[loadInfo->Meta->IndexField].CompressionType == DB2ColumnCompression::Immediate ||
                columnMeta[loadInfo->Meta->IndexField].CompressionType == DB2ColumnCompression::SignedImmediate);
        }

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

    if (!(_header.Flags & 0x1))
        _impl = new DB2FileLoaderRegularImpl(source->GetFileName(), loadInfo, &_header);
    else
        _impl = new DB2FileLoaderSparseImpl(source->GetFileName(), loadInfo, &_header, source);

    _impl->LoadColumnData(std::move(sections), std::move(fieldData), std::move(columnMeta), std::move(palletValues), std::move(palletArrayValues), std::move(commonValues));
    return true;
}

bool DB2FileLoader::Load(DB2FileSource* source, DB2FileLoadInfo const* loadInfo)
{
    if (!LoadHeaders(source, loadInfo))
        return false;

    std::vector<uint32> idTable;
    std::vector<DB2RecordCopy> copyTable;
    std::vector<std::vector<DB2IndexData>> parentIndexes;
    if (loadInfo && !loadInfo->Meta->HasIndexFieldInData() && _header.RecordCount)
        idTable.reserve(_header.RecordCount);

    if (_header.ParentLookupCount)
    {
        parentIndexes.resize(_header.SectionCount);
        for (std::vector<DB2IndexData>& parentIndexesForSection : parentIndexes)
            parentIndexesForSection.resize(_header.ParentLookupCount);
    }

    for (uint32 i = 0; i < _header.SectionCount; ++i)
    {
        DB2SectionHeader const& section = _impl->GetSection(i);

        if (section.TactId)
        {
            _impl->SkipEncryptedSection(i);
            idTable.resize(idTable.size() + section.IdTableSize / sizeof(uint32));
            continue;
        }

        if (!source->SetPosition(section.FileOffset))
            return false;

        if (!_impl->LoadTableData(source, i))
            return false;

        if (!_impl->LoadCatalogData(source, i))
            return false;

        if (loadInfo)
        {
            ASSERT(!loadInfo->Meta->HasIndexFieldInData() || section.IdTableSize == 0);
            ASSERT(loadInfo->Meta->HasIndexFieldInData() || section.IdTableSize == 4 * section.RecordCount);
        }

        if (section.IdTableSize)
        {
            std::size_t idTableSize = idTable.size();
            idTable.resize(idTableSize + section.IdTableSize / sizeof(uint32));
            if (!source->Read(&idTable[idTableSize], section.IdTableSize))
                return false;
        }

        if (!(_header.Flags & 0x1) && section.CopyTableCount)
        {
            std::size_t copyTableSize = copyTable.size();
            copyTable.resize(copyTableSize + section.CopyTableCount);
            if (!source->Read(&copyTable[copyTableSize], section.CopyTableCount * sizeof(DB2RecordCopy)))
                return false;
        }

        if (_header.ParentLookupCount)
        {
            std::vector<DB2IndexData>& parentIndexesForSection = parentIndexes[i];
            for (uint32 j = 0; j < _header.ParentLookupCount; ++j)
            {
                DB2IndexDataInfo indexInfo;
                if (!source->Read(&indexInfo, sizeof(DB2IndexDataInfo)))
                    return false;

                if (!indexInfo.NumEntries)
                    continue;

                parentIndexesForSection[j].Entries.resize(indexInfo.NumEntries);
                if (!source->Read(parentIndexesForSection[j].Entries.data(), sizeof(DB2IndexEntry) * indexInfo.NumEntries))
                    return false;
            }
        }
    }

    _impl->SetAdditionalData(std::move(idTable), std::move(copyTable), std::move(parentIndexes));

    if (loadInfo)
    {
        uint32 fieldIndex = 0;
        if (!loadInfo->Meta->HasIndexFieldInData())
        {
            ASSERT(!loadInfo->Fields[0].IsSigned, "ID must be unsigned in %s", source->GetFileName());
            ++fieldIndex;
        }
        for (uint32 f = 0; f < loadInfo->Meta->FieldCount; ++f)
        {
            ASSERT(loadInfo->Fields[fieldIndex].IsSigned == _impl->IsSignedField(f), "Mismatched field signedness for field %u (%s) in %s", f, loadInfo->Fields[fieldIndex].Name, source->GetFileName());
            fieldIndex += loadInfo->Meta->Fields[f].ArraySize;
        }
    }

    return true;
}

char* DB2FileLoader::AutoProduceData(uint32& count, char**& indexTable, std::vector<char*>& stringPool)
{
    return _impl->AutoProduceData(count, indexTable, stringPool);
}

char* DB2FileLoader::AutoProduceStrings(char** indexTable, uint32 indexTableSize, uint32 locale)
{
    return _impl->AutoProduceStrings(indexTable, indexTableSize, locale);
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

DB2SectionHeader const& DB2FileLoader::GetSectionHeader(uint32 section) const
{
    return _impl->GetSection(section);
}

DB2Record DB2FileLoader::GetRecord(uint32 recordNumber) const
{
    return _impl->GetRecord(recordNumber);
}

DB2RecordCopy DB2FileLoader::GetRecordCopy(uint32 copyNumber) const
{
    return _impl->GetRecordCopy(copyNumber);
}
