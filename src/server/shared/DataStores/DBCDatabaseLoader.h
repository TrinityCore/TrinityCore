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

#ifndef DBCDatabaseLoader_h__
#define DBCDatabaseLoader_h__

#include "DBCFileLoader.h"
#include <string>
#include <vector>

struct TC_SHARED_API DBCDatabaseLoader
{
    DBCDatabaseLoader(std::string const& storageName, std::string const& dbFormatString, std::string const& primaryKey, char const* dbcFormatString);

    char* Load(uint32& records, char**& indexTable);

private:
    std::string const& _formatString;
    std::string const& _indexName;
    std::string _sqlTableName;
    char const* _dbcFormat;
    int32 _sqlIndexPos;
    uint32 _recordSize;

    DBCDatabaseLoader(DBCDatabaseLoader const& right) = delete;
    DBCDatabaseLoader& operator=(DBCDatabaseLoader const& right) = delete;
};

#endif // DBCDatabaseLoader_h__
