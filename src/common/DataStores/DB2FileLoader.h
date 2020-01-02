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

#ifndef DB2_FILE_LOADER_H
#define DB2_FILE_LOADER_H

#include "Define.h"
#include <string>
#include <vector>

class DB2FileLoaderImpl;
struct DB2FieldMeta;
struct DB2Meta;

#pragma pack(push, 1)

struct DB2Header
{
    uint32 Signature;
    uint32 RecordCount;
    uint32 FieldCount;
    uint32 RecordSize;
    uint32 StringTableSize;
    uint32 TableHash;
    uint32 LayoutHash;
    uint32 MinId;
    uint32 MaxId;
    uint32 Locale;
    uint16 Flags;
    int16 IndexField;
    uint32 TotalFieldCount;
    uint32 PackedDataOffset;
    uint32 ParentLookupCount;
    uint32 ColumnMetaSize;
    uint32 CommonDataSize;
    uint32 PalletDataSize;
    uint32 SectionCount;
};

struct DB2SectionHeader
{
    uint64 TactId;
    uint32 FileOffset;
    uint32 RecordCount;
    uint32 StringTableSize;
    uint32 CatalogDataOffset;
    uint32 IdTableSize;
    uint32 ParentLookupDataSize;
    uint32 CatalogDataCount;
    uint32 CopyTableCount;
};

#pragma pack(pop)

struct TC_COMMON_API DB2FieldMeta
{
    DB2FieldMeta(bool isSigned, DBCFormer type, char const* name);

    bool IsSigned;
    DBCFormer Type;
    char const* Name;
};

struct TC_COMMON_API DB2FileLoadInfo
{
    DB2FileLoadInfo();
    DB2FileLoadInfo(DB2FieldMeta const* fields, std::size_t fieldCount, DB2Meta const* meta);

    uint32 GetStringFieldCount(bool localizedOnly) const;
    std::pair<int32/*fieldIndex*/, int32/*arrayIndex*/> GetFieldIndexByName(char const* fieldName) const;
    int32 GetFieldIndexByMetaIndex(uint32 metaIndex) const;

    DB2FieldMeta const* Fields;
    std::size_t FieldCount;
    DB2Meta const* Meta;
    std::string TypesString;
};

struct TC_COMMON_API DB2FileSource
{
    virtual ~DB2FileSource();

    // Returns true when the source is open for reading
    virtual bool IsOpen() const = 0;

    // Reads numBytes bytes from source and places them into buffer
    // Returns true if numBytes was read successfully
    virtual bool Read(void* buffer, std::size_t numBytes) = 0;

    // Returns current read position in file
    virtual int64 GetPosition() const = 0;

    virtual bool SetPosition(int64 position) = 0;

    virtual int64 GetFileSize() const = 0;

    virtual char const* GetFileName() const = 0;
};

class TC_COMMON_API DB2Record
{
public:
    DB2Record(DB2FileLoaderImpl const& db2, uint32 recordIndex, std::size_t* fieldOffsets);
    ~DB2Record();

    operator bool();

    uint32 GetId() const;

    uint8 GetUInt8(uint32 field, uint32 arrayIndex) const;
    uint8 GetUInt8(char const* fieldName) const;
    uint16 GetUInt16(uint32 field, uint32 arrayIndex) const;
    uint16 GetUInt16(char const* fieldName) const;
    uint32 GetUInt32(uint32 field, uint32 arrayIndex) const;
    uint32 GetUInt32(char const* fieldName) const;
    int32 GetInt32(uint32 field, uint32 arrayIndex) const;
    int32 GetInt32(char const* fieldName) const;
    uint64 GetUInt64(uint32 field, uint32 arrayIndex) const;
    uint64 GetUInt64(char const* fieldName) const;
    float GetFloat(uint32 field, uint32 arrayIndex) const;
    float GetFloat(char const* fieldName) const;
    char const* GetString(uint32 field, uint32 arrayIndex) const;
    char const* GetString(char const* fieldName) const;

    // Creates its own heap allocated copy of _fieldOffsets
    // by default _fieldOffets point to a shared array inside Loader to avoid heap allocations
    // meaning that only one instance of DB2Record has valid offsets if the file is sparse
    void MakePersistent();

private:
    DB2FileLoaderImpl const& _db2;
    uint32 _recordIndex;
    unsigned char const* _recordData;
    std::size_t* _fieldOffsets;
};

#pragma pack(push, 1)
struct DB2RecordCopy
{
    uint32 NewRowId = 0;
    uint32 SourceRowId = 0;
};
#pragma pack(pop)

class TC_COMMON_API DB2FileLoader
{
public:
    DB2FileLoader();
    ~DB2FileLoader();

    // loadInfo argument is required when trying to read data from the file
    bool LoadHeaders(DB2FileSource* source, DB2FileLoadInfo const* loadInfo);
    bool Load(DB2FileSource* source, DB2FileLoadInfo const* loadInfo);
    char* AutoProduceData(uint32& count, char**& indexTable, std::vector<char*>& stringPool);
    char* AutoProduceStrings(char** indexTable, uint32 indexTableSize, uint32 locale);
    void AutoProduceRecordCopies(uint32 records, char** indexTable, char* dataTable);

    uint32 GetCols() const { return _header.TotalFieldCount; }
    uint32 GetRecordCount() const;
    uint32 GetRecordCopyCount() const;
    uint32 GetTableHash() const { return _header.TableHash; }
    uint32 GetLayoutHash() const { return _header.LayoutHash; }
    uint32 GetMaxId() const;

    DB2Header const& GetHeader() const { return _header; }
    DB2SectionHeader const& GetSectionHeader(uint32 section) const;
    DB2Record GetRecord(uint32 recordNumber) const;
    DB2RecordCopy GetRecordCopy(uint32 copyNumber) const;

private:
    DB2FileLoaderImpl* _impl;
    DB2Header _header;
};

#endif
