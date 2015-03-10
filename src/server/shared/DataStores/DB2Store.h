/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include "DB2StorageLoader.h"
#include "DBStorageIterator.h"
#include "ByteBuffer.h"

/// Interface class for common access
class DB2StorageBase
{
public:
    virtual ~DB2StorageBase() { }

    uint32 GetHash() const { return _tableHash; }

    virtual bool HasRecord(uint32 id) const = 0;

    virtual void WriteRecord(uint32 id, uint32 locale, ByteBuffer& buffer) const = 0;

    virtual void EraseRecord(uint32 id) = 0;

protected:
    uint32 _tableHash;
};

template<class T>
class DB2Storage : public DB2StorageBase
{
    typedef std::list<char*> StringPoolList;
public:
    typedef DBStorageIterator<T> iterator;

    DB2Storage(char const* fileName, char const* format, uint32 preparedStmtIndex)
        : _fileName(fileName), _indexTableSize(0), _fieldCount(0), _format(format), _dataTable(nullptr), _dataTableEx(nullptr), _hotfixStatement(preparedStmtIndex)
    {
        _indexTable.AsT = NULL;
    }

    ~DB2Storage()
    {
        delete[] reinterpret_cast<char*>(_indexTable.AsT);
        delete[] reinterpret_cast<char*>(_dataTable);
        delete[] reinterpret_cast<char*>(_dataTableEx);
        for (char* stringPool : _stringPoolList)
            delete[] stringPool;
    }

    bool HasRecord(uint32 id) const override { return id < _indexTableSize && _indexTable.AsT[id] != nullptr; }
    void WriteRecord(uint32 id, uint32 locale, ByteBuffer& buffer) const override
    {
        ASSERT(id < _indexTableSize);
        char const* entry = _indexTable.AsChar[id];
        ASSERT(entry);

        std::size_t fields = strlen(_format);
        for (uint32 i = 0; i < fields; ++i)
        {
            switch (_format[i])
            {
                case FT_IND:
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
                case FT_STRING:
                {
                    LocalizedString* locStr = *(LocalizedString**)entry;
                    if (locStr->Str[locale][0] == '\0')
                        locale = 0;

                    char const* str = locStr->Str[locale];
                    std::size_t len = strlen(str);
                    buffer << uint16(len ? len + 1 : 0);
                    if (len)
                    {
                        buffer.append(str, len);
                        buffer << uint8(0);
                    }
                    entry += sizeof(LocalizedString*);
                    break;
                }
            }
        }
    }

    void EraseRecord(uint32 id) override { if (id < _indexTableSize) _indexTable.AsT[id] = nullptr; }

    T const* LookupEntry(uint32 id) const { return (id >= _indexTableSize) ? nullptr : _indexTable.AsT[id]; }
    std::string const& GetFileName() const { return _fileName; }
    uint32 GetNumRows() const { return _indexTableSize; }
    char const* GetFormat() const { return _format; }
    uint32 GetFieldCount() const { return _fieldCount; }
    bool Load(std::string const& path, uint32 locale)
    {
        DB2FileLoader db2;
        // Check if load was successful, only then continue
        if (!db2.Load((path + _fileName).c_str(), _format))
            return false;

        _fieldCount = db2.GetCols();
        _tableHash = db2.GetHash();

        // load raw non-string data
        _dataTable = reinterpret_cast<T*>(db2.AutoProduceData(_format, _indexTableSize, _indexTable.AsChar));

        // create string holders for loaded string fields
        if (char* stringHolders = db2.AutoProduceStringsArrayHolders(_format, (char*)_dataTable))
        {
            _stringPoolList.push_back(stringHolders);

            // load strings from db2 data
            if (char* stringBlock = db2.AutoProduceStrings(_format, (char*)_dataTable, locale))
                _stringPoolList.push_back(stringBlock);
        }

        // error in db2 file at loading if NULL
        return _indexTable.AsT != NULL;
    }

    bool LoadStringsFrom(std::string const& path, uint32 locale)
    {
        // DB2 must be already loaded using Load
        if (!_indexTable.AsT)
            return false;

        DB2FileLoader db2;
        // Check if load was successful, only then continue
        if (!db2.Load((path + _fileName).c_str(), _format))
            return false;

        // load strings from another locale db2 data
        if (DB2FileLoader::GetFormatStringFieldCount(_format))
            if (char* stringBlock = db2.AutoProduceStrings(_format, (char*)_dataTable, locale))
                _stringPoolList.push_back(stringBlock);
        return true;
    }

    void LoadFromDB()
    {
        char* extraStringHolders = nullptr;
        if (char* dataTable = DB2DatabaseLoader(_fileName).Load(_format, _hotfixStatement, _indexTableSize, _indexTable.AsChar, extraStringHolders, _stringPoolList))
            _dataTableEx = reinterpret_cast<T*>(dataTable);

        if (extraStringHolders)
            _stringPoolList.push_back(extraStringHolders);
    }

    void LoadStringsFromDB(uint32 locale)
    {
        if (!DB2FileLoader::GetFormatStringFieldCount(_format))
            return;

        DB2DatabaseLoader(_fileName).LoadStrings(_format, _hotfixStatement + 1, locale, _indexTable.AsChar, _stringPoolList);
    }

    iterator begin() { return iterator(_indexTable.AsT, _indexTableSize); }
    iterator end() { return iterator(_indexTable.AsT, _indexTableSize, _indexTableSize); }

private:
    std::string _fileName;
    uint32 _indexTableSize;
    uint32 _fieldCount;
    char const* _format;
    union
    {
        T** AsT;
        char** AsChar;
    } _indexTable;
    T* _dataTable;
    T* _dataTableEx;
    StringPoolList _stringPoolList;
    uint32 _hotfixStatement;
};

#endif
