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

#ifndef DBCSTORE_H
#define DBCSTORE_H

#include "Common.h"
#include "DBStorageIterator.h"
#include <vector>

 /// Interface class for common access
class TC_SHARED_API DBCStorageBase
{
    public:
        DBCStorageBase(char const* fmt);
        virtual ~DBCStorageBase();

        char const* GetFormat() const { return _fileFormat; }
        uint32 GetFieldCount() const { return _fieldCount; }

        virtual bool Load(std::string const& path) = 0;
        virtual bool LoadStringsFrom(std::string const& path) = 0;
        virtual void LoadFromDB(std::string const& path, std::string const& dbFormat, std::string const& primaryKey) = 0;

    protected:
        bool Load(std::string const& path, char**& indexTable);
        bool LoadStringsFrom(std::string const& path, char**& indexTable);
        void LoadFromDB(std::string const& path, std::string const& dbFormat, std::string const& primaryKey, char**& indexTable);

        uint32 _fieldCount;
        char const* _fileFormat;
        char* _dataTable;
        char* _dataTableEx;
        std::vector<char*> _stringPool;
        uint32 _indexTableSize;
};

template <class T>
class DBCStorage : public DBCStorageBase
{
    public:
        typedef DBStorageIterator<T> iterator;

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

        bool Load(std::string const& path) override
        {
            return DBCStorageBase::Load(path, _indexTable.AsChar);
        }

        bool LoadStringsFrom(std::string const& path) override
        {
            return DBCStorageBase::LoadStringsFrom(path, _indexTable.AsChar);
        }

        void LoadFromDB(std::string const& path, std::string const& dbFormat, std::string const& primaryKey) override
        {
            DBCStorageBase::LoadFromDB(path, dbFormat, primaryKey, _indexTable.AsChar);
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
