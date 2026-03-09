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
#include <memory>
#include <atomic>

class ByteBuffer;
struct DB2LoadInfo;

/**
 * Immutable snapshot of DB2 index table data for thread-safe read access.
 * Uses shared_ptr for RCU (Read-Copy-Update) semantics.
 * Owns the index table array (but not the pointed-to data).
 */
struct DB2IndexTableSnapshot
{
    char** const IndexTable;
    uint32 const TableSize;
    uint32 const MinId;

    DB2IndexTableSnapshot(char** table, uint32 size, uint32 minId)
        : IndexTable(table), TableSize(size), MinId(minId) {
    }

    ~DB2IndexTableSnapshot()
    {
        // Only delete the array of pointers, not the pointed-to data
        // The data is owned by DB2StorageBase::_dataTable and _dataTableEx
        delete[] IndexTable;
    }

    // Non-copyable, non-movable (immutable after creation)
    DB2IndexTableSnapshot(DB2IndexTableSnapshot const&) = delete;
    DB2IndexTableSnapshot& operator=(DB2IndexTableSnapshot const&) = delete;
};

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

    bool HasRecord(uint32 id) const;
    void WriteRecord(uint32 id, LocaleConstant locale, ByteBuffer& buffer) const;
    void EraseRecord(uint32 id);

    std::string const& GetFileName() const { return _fileName; }
    uint32 GetFieldCount() const { return _fieldCount; }
    DB2LoadInfo const* GetLoadInfo() const { return _loadInfo; }
    uint32 GetNumRows() const;

    /**
     * Get current index table snapshot for thread-safe read access.
     * Returns a shared_ptr that keeps the snapshot alive during use.
     */
    std::shared_ptr<DB2IndexTableSnapshot> GetSnapshot() const
    {
        return std::atomic_load(&_snapshot);
    }

    void Load(std::string const& path, LocaleConstant locale);
    void LoadStringsFrom(std::string const& path, LocaleConstant locale);
    void LoadFromDB();
    void LoadStringsFromDB(LocaleConstant locale);

protected:
    /**
     * Commit current _indexTable state to atomic snapshot.
     * Must be called after any modification to make changes visible to readers.
     * Creates a new snapshot and atomically replaces the old one.
     */
    void CommitSnapshot();

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

    // Thread-safe snapshot for readers (RCU semantics)
    // Writers update _indexTable first, then call CommitSnapshot()
    // Readers get a shared_ptr to the snapshot
    std::shared_ptr<DB2IndexTableSnapshot> _snapshot;

    friend class UnitTestDataLoader;
};

template<class T>
class DB2Storage : public DB2StorageBase
{
    static_assert(std::is_standard_layout_v<T>, "T in DB2Storage must have standard layout.");

public:
    using iterator = DBStorageIterator<T const*>;

    using DB2StorageBase::DB2StorageBase;

    T const* LookupEntry(uint32 id) const
    {
        // Thread-safe: get atomic snapshot and use it for lookup
        auto snapshot = GetSnapshot();
        if (!snapshot || id >= snapshot->TableSize)
            return nullptr;
        return reinterpret_cast<T const*>(snapshot->IndexTable[id]);
    }
    T const* AssertEntry(uint32 id) const { return ASSERT_NOTNULL(LookupEntry(id)); }

// Need rework on new standart DB2
#ifdef ELUNA
    void SetEntry(uint32 id, T* t)
    {
        if (id >= _indexTableSize)
        {
            // Resize
            typedef char* ptr;
            size_t newSize = id + 1;
            ptr* newArr = new ptr[newSize];
            memset(newArr, 0, newSize * sizeof(ptr));
            memcpy(newArr, _indexTable, _indexTableSize * sizeof(ptr));
            delete[] _indexTable;
            _indexTable = newArr;
            _indexTableSize = newSize;
        }

        delete reinterpret_cast<T*>(_indexTable[id]);
        _indexTable[id] = reinterpret_cast<char*>(t);

        // Commit snapshot to make change visible to readers
        CommitSnapshot();
    }
#endif



    iterator begin() const
    {
        auto snapshot = GetSnapshot();
        if (!snapshot)
            return iterator(nullptr, 0, 0);
        return iterator(reinterpret_cast<T const* const*>(snapshot->IndexTable), snapshot->TableSize, snapshot->MinId);
    }
    iterator end() const
    {
        auto snapshot = GetSnapshot();
        if (!snapshot)
            return iterator(nullptr, 0, 0);
        return iterator(reinterpret_cast<T const* const*>(snapshot->IndexTable), snapshot->TableSize, snapshot->TableSize);
    }
};

#endif
