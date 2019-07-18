/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef DB2STORE_H
#define DB2STORE_H

#include "Common.h"
#include "Errors.h"
#include "DBStorageIterator.h"
#include <vector>

class ByteBuffer;
struct DB2LoadInfo;

/// Interface class for common access
class TC_SHARED_API DB2StorageBase
{
public:
    DB2StorageBase(char const* fileName, DB2LoadInfo const* loadInfo);
    virtual ~DB2StorageBase();

    uint32 GetTableHash() const { return _tableHash; }
    uint32 GetLayoutHash() const { return _layoutHash; }

    virtual bool HasRecord(uint32 id) const = 0;
    virtual void WriteRecord(uint32 id, uint32 locale, ByteBuffer& buffer) const = 0;
    virtual void EraseRecord(uint32 id) = 0;

    std::string const& GetFileName() const { return _fileName; }
    uint32 GetFieldCount() const { return _fieldCount; }
    DB2LoadInfo const* GetLoadInfo() const { return _loadInfo; }

    virtual bool Load(std::string const& path, uint32 locale) = 0;
    virtual bool LoadStringsFrom(std::string const& path, uint32 locale) = 0;
    virtual void LoadFromDB() = 0;
    virtual void LoadStringsFromDB(uint32 locale) = 0;

protected:
    void WriteRecordData(char const* entry, uint32 locale, ByteBuffer& buffer) const;
    bool Load(std::string const& path, uint32 locale, char**& indexTable);
    bool LoadStringsFrom(std::string const& path, uint32 locale, char** indexTable);
    void LoadFromDB(char**& indexTable);
    void LoadStringsFromDB(uint32 locale, char** indexTable);

    uint32 _tableHash;
    uint32 _layoutHash;
    std::string _fileName;
    uint32 _fieldCount;
    DB2LoadInfo const* _loadInfo;
    char* _dataTable;
    char* _dataTableEx;
    std::vector<char*> _stringPool;
    uint32 _indexTableSize;
};

template<class T>
class DB2Storage : public DB2StorageBase
{
    static_assert(std::is_standard_layout<T>::value, "T in DB2Storage must have standard layout.");

public:
    typedef DBStorageIterator<T> iterator;

    DB2Storage(char const* fileName, DB2LoadInfo const* loadInfo) : DB2StorageBase(fileName, loadInfo)
    {
        _indexTable.AsT = nullptr;
    }

    ~DB2Storage()
    {
        delete[] reinterpret_cast<char*>(_indexTable.AsT);
    }

    bool HasRecord(uint32 id) const override { return id < _indexTableSize && _indexTable.AsT[id] != nullptr; }
    void WriteRecord(uint32 id, uint32 locale, ByteBuffer& buffer) const override
    {
        WriteRecordData(reinterpret_cast<char const*>(AssertEntry(id)), locale, buffer);
    }

    void EraseRecord(uint32 id) override { if (id < _indexTableSize) _indexTable.AsT[id] = nullptr; }

    T const* LookupEntry(uint32 id) const { return (id >= _indexTableSize) ? nullptr : _indexTable.AsT[id]; }
    T const* AssertEntry(uint32 id) const { return ASSERT_NOTNULL(LookupEntry(id)); }
    T const* operator[](uint32 id) const { return LookupEntry(id); }

    uint32 GetNumRows() const { return _indexTableSize; }
    bool Load(std::string const& path, uint32 locale) override
    {
        return DB2StorageBase::Load(path, locale, _indexTable.AsChar);
    }

    bool LoadStringsFrom(std::string const& path, uint32 locale) override
    {
        return DB2StorageBase::LoadStringsFrom(path, locale, _indexTable.AsChar);
    }

    void LoadFromDB() override
    {
        DB2StorageBase::LoadFromDB(_indexTable.AsChar);
    }

    void LoadStringsFromDB(uint32 locale) override
    {
        DB2StorageBase::LoadStringsFromDB(locale, _indexTable.AsChar);
    }

    iterator begin() { return iterator(_indexTable.AsT, _indexTableSize); }
    iterator end() { return iterator(_indexTable.AsT, _indexTableSize, _indexTableSize); }

private:
    union
    {
        T** AsT;
        char** AsChar;
    } _indexTable;
};

#endif
