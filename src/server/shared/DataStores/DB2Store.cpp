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

#include "DB2Store.h"
#include "ByteBuffer.h"
#include "DB2DatabaseLoader.h"
#include "DB2FileSystemSource.h"
#include "DB2Meta.h"
#include "StringFormat.h"

DB2StorageBase::DB2StorageBase(char const* fileName, DB2LoadInfo const* loadInfo)
    : _tableHash(0), _layoutHash(0), _fileName(fileName), _fieldCount(0), _loadInfo(loadInfo), _dataTable(nullptr), _dataTableEx(), _indexTableSize(0)
{
}

DB2StorageBase::~DB2StorageBase()
{
    delete[] _dataTable;
    delete[] _dataTableEx[0];
    delete[] _dataTableEx[1];
    for (char* strings : _stringPool)
        delete[] strings;
}

void DB2StorageBase::WriteRecordData(char const* entry, LocaleConstant locale, ByteBuffer& buffer) const
{
    if (!_loadInfo->Meta->HasIndexFieldInData())
        entry += 4;

    for (uint32 i = 0; i < _loadInfo->Meta->FieldCount; ++i)
    {
        for (uint8 arr = 0; arr < _loadInfo->Meta->Fields[i].ArraySize; ++arr)
        {
            switch (_loadInfo->Meta->Fields[i].Type)
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
                    buffer << (*(LocalizedString*)entry)[locale];
                    entry += sizeof(LocalizedString);
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

void DB2StorageBase::Load(std::string const& path, LocaleConstant locale, char**& indexTable)
{
    indexTable = nullptr;
    DB2FileLoader db2;
    DB2FileSystemSource source(path + _fileName);
    // Check if load was successful, only then continue
    db2.Load(&source, _loadInfo);

    _fieldCount = db2.GetCols();
    _tableHash = db2.GetTableHash();
    _layoutHash = db2.GetLayoutHash();

    // load raw non-string data
    _dataTable = db2.AutoProduceData(_indexTableSize, indexTable);

    // load strings from db2 data
    if (char* stringBlock = db2.AutoProduceStrings(indexTable, _indexTableSize, locale))
        _stringPool.push_back(stringBlock);

    db2.AutoProduceRecordCopies(_indexTableSize, indexTable, _dataTable);
}

void DB2StorageBase::LoadStringsFrom(std::string const& path, LocaleConstant locale, char** indexTable)
{
    // DB2 must be already loaded using Load
    if (!indexTable)
        throw DB2FileLoadException(Trinity::StringFormat("%s was not loaded properly, cannot load strings", path.c_str()));

    DB2FileLoader db2;
    DB2FileSystemSource source(path + _fileName);
    // Check if load was successful, only then continue
    db2.Load(&source, _loadInfo);

    // load strings from another locale db2 data
    if (_loadInfo->GetStringFieldCount(true))
        if (char* stringBlock = db2.AutoProduceStrings(indexTable, _indexTableSize, locale))
            _stringPool.push_back(stringBlock);
}

void DB2StorageBase::LoadFromDB(char**& indexTable)
{
    DB2DatabaseLoader loader(_fileName, _loadInfo);

    auto loadTable = [&](bool custom)
    {
        char* extraStringHolders = nullptr;
        _dataTableEx[custom ? 1 : 0] = loader.Load(custom, _indexTableSize, indexTable, extraStringHolders, _stringPool);
        if (extraStringHolders)
            _stringPool.push_back(extraStringHolders);
    };

    loadTable(false);
    loadTable(true);
    _stringPool.shrink_to_fit();
}

void DB2StorageBase::LoadStringsFromDB(LocaleConstant locale, char** indexTable)
{
    if (!_loadInfo->GetStringFieldCount(true))
        return;

    DB2DatabaseLoader loader(_fileName, _loadInfo);
    loader.LoadStrings(false, locale, _indexTableSize, indexTable, _stringPool);
    loader.LoadStrings(true, locale, _indexTableSize, indexTable, _stringPool);
    _stringPool.shrink_to_fit();
}
