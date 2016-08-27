/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DB2_FILE_LOADER_H
#define DB2_FILE_LOADER_H

#include "Define.h"
#include "Implementation/HotfixDatabase.h"

class DB2FileLoaderImpl;
struct DB2Meta;

#pragma pack(push, 1)
struct DB2Header
{
    uint32 Signature;
    uint32 RecordCount;
    uint32 FieldCount;
    uint32 RecordSize;
    uint32 StringTableSize;
    uint32 TableHash;
    uint32 LayoutHash;
    uint32 MinId;
    uint32 MaxId;
    uint32 Locale;
    uint32 CopyTableSize;
    uint16 Flags;
    int16 IndexField;
};
#pragma pack(pop)

class TC_SHARED_API DB2FileLoader
{
public:
    DB2FileLoader();
    ~DB2FileLoader();

    bool Load(char const* filename, DB2Meta const* meta);
    char* AutoProduceData(uint32& count, char**& indexTable, std::vector<char*>& stringPool);
    char* AutoProduceStrings(char* dataTable, uint32 locale);
    void AutoProduceRecordCopies(uint32 records, char** indexTable, char* dataTable);

    uint32 GetCols() const { return _header.FieldCount; }
    uint32 GetTableHash() const { return _header.TableHash; }
    uint32 GetLayoutHash() const { return _header.LayoutHash; }

private:
    DB2FileLoaderImpl* _impl;
    DB2Header _header;
};

class TC_SHARED_API DB2DatabaseLoader
{
public:
    DB2DatabaseLoader(std::string const& storageName, DB2Meta const* meta) : _storageName(storageName), _meta(meta) { }

    char* Load(HotfixDatabaseStatements preparedStatement, uint32& records, char**& indexTable, char*& stringHolders, std::vector<char*>& stringPool);
    void LoadStrings(HotfixDatabaseStatements preparedStatement, uint32 locale, uint32 records, char** indexTable, std::vector<char*>& stringPool);
    static char* AddString(char const** holder, std::string const& value);

private:
    std::string _storageName;
    DB2Meta const* _meta;
};

#endif
