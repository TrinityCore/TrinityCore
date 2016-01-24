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

#ifndef DB2_SPARSE_FILE_LOADER_H
#define DB2_SPARSE_FILE_LOADER_H

#include "Define.h"
#include "Utilities/ByteConverter.h"
#include "Implementation/HotfixDatabase.h"
#include <unordered_map>
#include <vector>

class IndexTable
{
public:
    virtual void Insert(uint32 index, char* data) const = 0;
    virtual char* Get(uint32 index) const = 0;
};

template<typename T>
class IndexTableAdapter : public IndexTable
{
public:
    IndexTableAdapter(std::unordered_map<uint32, T const*>& indexTable) : _indexTable(indexTable) { }

    void Insert(uint32 index, char* data) const override
    {
        _indexTable[index] = (T const*)data;
    }

    char* Get(uint32 index) const override
    {
        auto itr = _indexTable.find(index);
        if (itr != _indexTable.end())
            return (char*)itr->second;
        return nullptr;
    }

private:
    std::unordered_map<uint32, T const*>& _indexTable;
};

class DB2SparseFileLoader
{
    public:
    DB2SparseFileLoader();
    ~DB2SparseFileLoader();

    bool Load(const char *filename);

    uint32 GetNumRows() const { return recordCount; }
    uint32 GetCols() const { return fieldCount; }
    uint32 GetHash() const { return tableHash; }
    bool IsLoaded() const { return (data != NULL); }
    char* AutoProduceData(const char* fmt, IndexTable const& indexTable, uint32 locale, std::vector<char*>& stringPool);
    char* AutoProduceStrings(const char* fmt, char* dataTable, uint32 locale);
    static uint32 GetFormatRecordSize(const char * format);
    static uint32 GetFormatStringFieldCount(const char * format);
    static uint32 GetFormatLocalizedStringFieldCount(const char * format);
private:
#pragma pack(push, 1)
    struct OffsetTableEntry
    {
        uint32 FileOffset;
        uint16 RecordSize;
    };
#pragma pack(pop)

    char const* fileName;

    // WDB2 / WCH2 fields
    uint32 recordSize;
    uint32 recordCount;
    uint32 fieldCount;
    uint32 offsetsPos;
    uint32 tableHash;
    uint32 build;
    uint32 unk1;
    uint32 minIndex;
    uint32 maxIndex;
    uint32 localeMask;
    uint32 copyIdSize;
    uint32 metaFlags;

    uint32 dataStart;
    unsigned char* data;
    OffsetTableEntry* offsets;
};

class DB2SparseDatabaseLoader
{
public:
    explicit DB2SparseDatabaseLoader(std::string const& storageName) : _storageName(storageName) { }

    char* Load(const char* format, HotfixDatabaseStatements preparedStatement, IndexTable const& indexTable, std::vector<char*>& stringPool);
    void LoadStrings(const char* format, HotfixDatabaseStatements preparedStatement, uint32 locale, IndexTable const& indexTable, std::vector<char*>& stringPool);
    static char* AddString(char const** holder, std::string const& value);

private:
    std::string _storageName;
};

#endif
