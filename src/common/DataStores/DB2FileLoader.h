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
    uint32 CopyTableSize;
    uint16 Flags;
    int16 IndexField;
};
#pragma pack(pop)

struct TC_COMMON_API DB2FileLoadInfo
{
    DB2FileLoadInfo();
    DB2FileLoadInfo(DB2FieldMeta const* fields, std::size_t fieldCount, DB2Meta const* meta);

    uint32 GetStringFieldCount(bool localizedOnly) const;

    DB2FieldMeta const* Fields;
    std::size_t FieldCount;
    DB2Meta const* Meta;
    std::string TypesString;
};

struct TC_COMMON_API DB2FileSource
{
    virtual ~DB2FileSource();

    ///
    /**
     * Returns true when the source is open for reading
     */
    virtual bool IsOpen() const = 0;

    // Reads numBytes bytes from source and places them into buffer
    // Retu
    virtual bool Read(void* buffer, std::size_t numBytes) = 0;
    virtual std::size_t GetPosition() const = 0;
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
    uint16 GetUInt16(uint32 field, uint32 arrayIndex) const;
    uint32 GetUInt32(uint32 field, uint32 arrayIndex) const;
    int32 GetInt32(uint32 field, uint32 arrayIndex) const;
    float GetFloat(uint32 field, uint32 arrayIndex) const;
    char const* GetString(uint32 field, uint32 arrayIndex) const;

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

    bool Load(DB2FileSource* source, DB2FileLoadInfo const* loadInfo);
    char* AutoProduceData(uint32& count, char**& indexTable, std::vector<char*>& stringPool);
    char* AutoProduceStrings(char* dataTable, uint32 locale);
    void AutoProduceRecordCopies(uint32 records, char** indexTable, char* dataTable);

    uint32 GetCols() const { return _header.FieldCount; }
    uint32 GetRecordCount() const;
    uint32 GetRecordCopyCount() const;
    uint32 GetTableHash() const { return _header.TableHash; }
    uint32 GetLayoutHash() const { return _header.LayoutHash; }
    uint32 GetMaxId() const;

    DB2Record GetRecord(uint32 recordNumber) const;
    DB2RecordCopy GetRecordCopy(uint32 copyNumber) const;

private:
    DB2FileLoaderImpl* _impl;
    DB2Header _header;
};

#endif
