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

#ifndef DB2STORE_H
#define DB2STORE_H

#include "Common.h"
#include "DB2Meta.h"
#include "DB2StorageLoader.h"
#include "DBStorageIterator.h"
#include "ByteBuffer.h"

/// Interface class for common access
class DB2StorageBase
{
public:
    DB2StorageBase(char const* fileName, DB2LoadInfo&& loadInfo)
        : _tableHash(0), _layoutHash(0), _fileName(fileName), _fieldCount(0), _loadInfo(std::move(loadInfo)), _dataTable(nullptr), _dataTableEx(nullptr) { }

    virtual ~DB2StorageBase()
    {
        delete[] reinterpret_cast<char*>(_dataTable);
        delete[] reinterpret_cast<char*>(_dataTableEx);
        for (char* strings : _stringPool)
            delete[] strings;
    }

    uint32 GetTableHash() const { return _tableHash; }

    uint32 GetLayoutHash() const { return _layoutHash; }

    virtual bool HasRecord(uint32 id) const = 0;

    virtual void WriteRecord(uint32 id, uint32 locale, ByteBuffer& buffer) const = 0;

    virtual void EraseRecord(uint32 id) = 0;

    std::string const& GetFileName() const { return _fileName; }

    uint32 GetFieldCount() const { return _fieldCount; }

    DB2LoadInfo const* GetLoadInfo() const { return &_loadInfo; }

    virtual bool Load(std::string const& path, uint32 locale) = 0;
    virtual bool LoadStringsFrom(std::string const& path, uint32 locale) = 0;
    virtual void LoadFromDB() = 0;
    virtual void LoadStringsFromDB(uint32 locale) = 0;

protected:
    void WriteRecordData(char const* entry, uint32 locale, ByteBuffer& buffer) const
    {
        if (!_loadInfo.Meta->HasIndexFieldInData())
            entry += 4;

        for (uint32 i = 0; i < _loadInfo.Meta->FieldCount; ++i)
        {
            for (uint32 a = 0; a < _loadInfo.Meta->ArraySizes[i]; ++a)
            {
                switch (_loadInfo.TypesString[i])
                {
                    case FT_INT:
                        buffer << *(uint32*)entry;
                        entry += 4;
                        break;
                    case FT_FLOAT:
                        buffer << *(float*)entry;
                        entry += 4;
                        break;
                    case FT_BYTE:
                        buffer << *(uint8*)entry;
                        entry += 1;
                        break;
                    case FT_SHORT:
                        buffer << *(uint16*)entry;
                        entry += 2;
                        break;
                    case FT_STRING:
                    {
                        LocalizedString* locStr = *(LocalizedString**)entry;
                        if (locStr->Str[locale][0] == '\0')
                            locale = 0;

                        buffer << locStr->Str[locale];
                        entry += sizeof(LocalizedString*);
                        break;
                    }
                    case FT_STRING_NOT_LOCALIZED:
                    {
                        buffer << *(char const**)entry;
                        entry += sizeof(char const*);
                        break;
                    }
                }
            }
        }
    }

    uint32 _tableHash;
    uint32 _layoutHash;
    std::string _fileName;
    uint32 _fieldCount;
    DB2LoadInfo _loadInfo;
    char* _dataTable;
    char* _dataTableEx;
    std::vector<char*> _stringPool;
};

template<class T>
class DB2Storage : public DB2StorageBase
{
    static_assert(std::is_standard_layout<T>::value, "T in DB2Storage must have standard layout.");

public:
    typedef DBStorageIterator<T> iterator;

    DB2Storage(char const* fileName, DB2LoadInfo&& loadInfo) : DB2StorageBase(fileName, std::move(loadInfo)),
        _indexTableSize(0)
    {
        _indexTable.AsT = NULL;
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

    uint32 GetNumRows() const { return _indexTableSize; }
    bool Load(std::string const& path, uint32 locale) override
    {
        DB2FileLoader db2;
        // Check if load was successful, only then continue
        if (!db2.Load((path + _fileName).c_str(), &_loadInfo))
            return false;

        _fieldCount = db2.GetCols();
        _tableHash = db2.GetTableHash();
        _layoutHash = db2.GetLayoutHash();

        // load raw non-string data
        _dataTable = db2.AutoProduceData(_indexTableSize, _indexTable.AsChar, _stringPool);

        // load strings from db2 data
        if (!_stringPool.empty())
            if (char* stringBlock = db2.AutoProduceStrings(_dataTable, locale))
                _stringPool.push_back(stringBlock);

        db2.AutoProduceRecordCopies(_indexTableSize, _indexTable.AsChar, _dataTable);

        // error in db2 file at loading if NULL
        return _indexTable.AsT != NULL;
    }

    bool LoadStringsFrom(std::string const& path, uint32 locale) override
    {
        // DB2 must be already loaded using Load
        if (!_indexTable.AsT)
            return false;

        DB2FileLoader db2;
        // Check if load was successful, only then continue
        if (!db2.Load((path + _fileName).c_str(), &_loadInfo))
            return false;

        // load strings from another locale db2 data
        if (_loadInfo.GetStringFieldCount(true))
            if (char* stringBlock = db2.AutoProduceStrings(_dataTable, locale))
                _stringPool.push_back(stringBlock);
        return true;
    }

    void LoadFromDB() override
    {
        char* extraStringHolders = nullptr;
        _dataTableEx = DB2DatabaseLoader(_fileName, &_loadInfo).Load(_indexTableSize, _indexTable.AsChar, extraStringHolders, _stringPool);
        if (extraStringHolders)
            _stringPool.push_back(extraStringHolders);
    }

    void LoadStringsFromDB(uint32 locale) override
    {
        if (!_loadInfo.GetStringFieldCount(true))
            return;

        DB2DatabaseLoader(_fileName, &_loadInfo).LoadStrings(locale, _indexTableSize, _indexTable.AsChar, _stringPool);
    }

    iterator begin() { return iterator(_indexTable.AsT, _indexTableSize); }
    iterator end() { return iterator(_indexTable.AsT, _indexTableSize, _indexTableSize); }

private:
    union
    {
        T** AsT;
        char** AsChar;
    } _indexTable;
    uint32 _indexTableSize;
};

#endif
