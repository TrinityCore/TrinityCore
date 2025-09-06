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
    DB2StorageBase(DB2StorageBase const&) = delete;
    DB2StorageBase(DB2StorageBase&&) = delete;
    DB2StorageBase& operator=(DB2StorageBase const&) = delete;
    DB2StorageBase& operator=(DB2StorageBase&&) = delete;
    ~DB2StorageBase();

    uint32 GetTableHash() const { return _tableHash; }
    uint32 GetLayoutHash() const { return _layoutHash; }

    bool HasRecord(uint32 id) const { return id < _indexTableSize && _indexTable[id] != nullptr; }
    void WriteRecord(uint32 id, LocaleConstant locale, ByteBuffer& buffer) const;
    void EraseRecord(uint32 id) { if (id < _indexTableSize) _indexTable[id] = nullptr; }

    std::string const& GetFileName() const { return _fileName; }
    uint32 GetFieldCount() const { return _fieldCount; }
    DB2LoadInfo const* GetLoadInfo() const { return _loadInfo; }
    uint32 GetNumRows() const { return _indexTableSize; }

    void Load(std::string const& path, LocaleConstant locale);
    void LoadStringsFrom(std::string const& path, LocaleConstant locale);
    void LoadFromDB();
    void LoadStringsFromDB(LocaleConstant locale);

protected:
    uint32 _tableHash;
    uint32 _layoutHash;
    std::string _fileName;
    uint32 _fieldCount;
    DB2LoadInfo const* _loadInfo;
    char* _dataTable;
    char* _dataTableEx[2];
    std::vector<char*> _stringPool;
    char** _indexTable;
    uint32 _indexTableSize;
    uint32 _minId;

    friend class UnitTestDataLoader;
};

template<class T>
class DB2Storage : public DB2StorageBase
{
    static_assert(std::is_standard_layout_v<T>, "T in DB2Storage must have standard layout.");

public:
    using iterator = DBStorageIterator<T const*>;

    using DB2StorageBase::DB2StorageBase;

    T const* LookupEntry(uint32 id) const { return (id >= _indexTableSize) ? nullptr : reinterpret_cast<T const*>(_indexTable[id]); }
    T const* AssertEntry(uint32 id) const { return ASSERT_NOTNULL(LookupEntry(id)); }

    iterator begin() const { return iterator(reinterpret_cast<T const* const*>(_indexTable), _indexTableSize, _minId); }
    iterator end() const { return iterator(reinterpret_cast<T const* const*>(_indexTable), _indexTableSize, _indexTableSize); }
};

#endif
