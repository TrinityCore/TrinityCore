/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "DB2Store.h"
#include "ByteBuffer.h"
#include "DB2DatabaseLoader.h"
#include "DB2FileSystemSource.h"
#include "DB2Meta.h"

DB2StorageBase::DB2StorageBase(char const* fileName, DB2LoadInfo const* loadInfo)
    : _tableHash(0), _layoutHash(0), _fileName(fileName), _fieldCount(0), _loadInfo(loadInfo), _dataTable(nullptr), _dataTableEx(nullptr), _indexTableSize(0)
{
}

DB2StorageBase::~DB2StorageBase()
{
    delete[] _dataTable;
    delete[] _dataTableEx;
    for (char* strings : _stringPool)
        delete[] strings;
}

void DB2StorageBase::WriteRecordData(char const* entry, uint32 locale, ByteBuffer& buffer) const
{
    std::size_t i = 0;
    if (!_loadInfo->Meta->HasIndexFieldInData())
    {
        entry += 4;
        ++i;
    }

    for (; i < _loadInfo->FieldCount; ++i)
    {
        switch (_loadInfo->TypesString[i])
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
            case FT_LONG:
                buffer << *(uint64*)entry;
                entry += 8;
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

bool DB2StorageBase::Load(std::string const& path, uint32 locale, char**& indexTable)
{
    indexTable = nullptr;
    DB2FileLoader db2;
    {
        DB2FileSystemSource source(path + _fileName);
        // Check if load was successful, only then continue
        if (!db2.Load(&source, _loadInfo))
            return false;
    }

    _fieldCount = db2.GetCols();
    _tableHash = db2.GetTableHash();
    _layoutHash = db2.GetLayoutHash();

    // load raw non-string data
    _dataTable = db2.AutoProduceData(_indexTableSize, indexTable, _stringPool);

    // load strings from db2 data
    if (!_stringPool.empty())
        if (char* stringBlock = db2.AutoProduceStrings(_dataTable, locale))
            _stringPool.push_back(stringBlock);

    db2.AutoProduceRecordCopies(_indexTableSize, indexTable, _dataTable);

    // error in db2 file at loading if NULL
    return indexTable != nullptr;
}

bool DB2StorageBase::LoadStringsFrom(std::string const& path, uint32 locale, char** indexTable)
{
    // DB2 must be already loaded using Load
    if (!indexTable)
        return false;

    DB2FileLoader db2;
    {
        DB2FileSystemSource source(path + _fileName);
        // Check if load was successful, only then continue
        if (!db2.Load(&source, _loadInfo))
            return false;
    }

    // load strings from another locale db2 data
    if (_loadInfo->GetStringFieldCount(true))
        if (char* stringBlock = db2.AutoProduceStrings(_dataTable, locale))
            _stringPool.push_back(stringBlock);

    return true;
}

void DB2StorageBase::LoadFromDB(char**& indexTable)
{
    char* extraStringHolders = nullptr;
    _dataTableEx = DB2DatabaseLoader(_fileName, _loadInfo).Load(_indexTableSize, indexTable, extraStringHolders, _stringPool);
    if (extraStringHolders)
        _stringPool.push_back(extraStringHolders);
}

void DB2StorageBase::LoadStringsFromDB(uint32 locale, char** indexTable)
{
    if (!_loadInfo->GetStringFieldCount(true))
        return;

    DB2DatabaseLoader(_fileName, _loadInfo).LoadStrings(locale, _indexTableSize, indexTable, _stringPool);
}
