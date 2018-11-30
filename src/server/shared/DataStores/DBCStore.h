/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef DBCSTORE_H
#define DBCSTORE_H

#include "Common.h"
#include "DBCStorageIterator.h"
#include <vector>

 /// Interface class for common access
class TC_SHARED_API DBCStorageBase
{
    public:
        DBCStorageBase(char const* fmt);
        virtual ~DBCStorageBase();

        char const* GetFormat() const { return _fileFormat; }
        uint32 GetFieldCount() const { return _fieldCount; }

        virtual bool Load(char const* path) = 0;
        virtual bool LoadStringsFrom(char const* path) = 0;
        virtual void LoadFromDB(char const* table, char const* format, char const* index) = 0;

    protected:
        bool Load(char const* path, char**& indexTable);
        bool LoadStringsFrom(char const* path, char** indexTable);
        void LoadFromDB(char const* table, char const* format, char const* index, char**& indexTable);

        uint32 _fieldCount;
        char const* _fileFormat;
        char* _dataTable;
        std::vector<char*> _stringPool;
        uint32 _indexTableSize;
};

template <class T>
class DBCStorage : public DBCStorageBase
{
    public:
        typedef DBCStorageIterator<T> iterator;

        explicit DBCStorage(char const* fmt) : DBCStorageBase(fmt)
        {
            _indexTable.AsT = nullptr;
        }

        ~DBCStorage()
        {
            delete[] reinterpret_cast<char*>(_indexTable.AsT);
        }

        T const* LookupEntry(uint32 id) const { return (id >= _indexTableSize) ? nullptr : _indexTable.AsT[id]; }
        T const* AssertEntry(uint32 id) const { return ASSERT_NOTNULL(LookupEntry(id)); }

        uint32 GetNumRows() const { return _indexTableSize; }

        bool Load(char const* path) override
        {
            return DBCStorageBase::Load(path, _indexTable.AsChar);
        }

        bool LoadStringsFrom(char const* path) override
        {
            return DBCStorageBase::LoadStringsFrom(path, _indexTable.AsChar);
        }

        void LoadFromDB(char const* table, char const* format, char const* index) override
        {
            DBCStorageBase::LoadFromDB(table, format, index, _indexTable.AsChar);
        }

        iterator begin() { return iterator(_indexTable.AsT, _indexTableSize); }
        iterator end() { return iterator(_indexTable.AsT, _indexTableSize, _indexTableSize); }

    private:
        union
        {
            T** AsT;
            char** AsChar;
        }
        _indexTable;

        DBCStorage(DBCStorage const& right) = delete;
        DBCStorage& operator=(DBCStorage const& right) = delete;
};

#endif
