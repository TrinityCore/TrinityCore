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

#include "DBCStore.h"
#include "DBCDatabaseLoader.h"

DBCStorageBase::DBCStorageBase(char const* fmt) : _fieldCount(0), _fileFormat(fmt), _dataTable(nullptr), _indexTableSize(0)
{
}

DBCStorageBase::~DBCStorageBase()
{
    delete[] _dataTable;
    for (char* strings : _stringPool)
        delete[] strings;
}

bool DBCStorageBase::Load(char const* path, char**& indexTable)
{
    indexTable = nullptr;

    DBCFileLoader dbc;
    // Check if load was sucessful, only then continue
    if (!dbc.Load(path, _fileFormat))
        return false;

    _fieldCount = dbc.GetCols();

    // load raw non-string data
    _dataTable = dbc.AutoProduceData(_fileFormat, _indexTableSize, indexTable);

    // load strings from dbc data
    if (char* stringBlock = dbc.AutoProduceStrings(_fileFormat, _dataTable))
        _stringPool.push_back(stringBlock);

    // error in dbc file at loading if NULL
    return indexTable != nullptr;
}

bool DBCStorageBase::LoadStringsFrom(char const* path, char** indexTable)
{
    // DBC must be already loaded using Load
    if (!indexTable)
        return false;

    DBCFileLoader dbc;
    // Check if load was successful, only then continue
    if (!dbc.Load(path, _fileFormat))
        return false;

    // load strings from another locale dbc data
    if (char* stringBlock = dbc.AutoProduceStrings(_fileFormat, _dataTable))
        _stringPool.push_back(stringBlock);

    return true;
}

void DBCStorageBase::LoadFromDB(char const* table, char const* format, char const* index, char**& indexTable)
{
    _stringPool.push_back(DBCDatabaseLoader(table, format, index, _fileFormat, _stringPool).Load(_indexTableSize, indexTable));
}
