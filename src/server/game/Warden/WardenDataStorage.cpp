/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Common.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Log.h"
#include "Database/DatabaseEnv.h"
#include "Util.h"
#include "WardenDataStorage.h"
#include "WardenWin.h"

CWardenDataStorage::CWardenDataStorage()
{
    InternalDataID = 1;
}

CWardenDataStorage::~CWardenDataStorage()
{
    std::map<uint32, WardenData*>::iterator itr1 = _data_map.begin();
    for (; itr1 != _data_map.end(); ++itr1)
        delete itr1->second;

    std::map<uint32, WardenDataResult*>::iterator itr2 = _result_map.begin();
    for (; itr2 != _result_map.end(); ++itr2)
        delete itr2->second;
}

void CWardenDataStorage::Init()
{
    LoadWardenDataResult();
}

void CWardenDataStorage::LoadWardenDataResult()
{
    QueryResult result = WorldDatabase.Query("SELECT `check`, `data`, `result`, `address`, `length`, `str` FROM warden_data_result");

    uint32 count = 0;

    if (!result)
    {
        sLog->outString();
        sLog->outString(">> Loaded %u warden data and results", count);
        return;
    }

    do
    {
        ++count;

        Field *fields = result->Fetch();

        uint8 type = fields[0].GetUInt8();

        uint32 id = GenerateInternalDataID();
        WardenData *wd = new WardenData();
        wd->Type = type;

        if (type == PAGE_CHECK_A || type == PAGE_CHECK_B || type == DRIVER_CHECK)
        {
            std::string data = fields[1].GetString();
            wd->i.SetHexStr(data.c_str());
            int len = data.size() / 2;
            if (wd->i.GetNumBytes() < len)
            {
                uint8 temp[24];
                memset(temp, 0, len);
                memcpy(temp, wd->i.AsByteArray(), wd->i.GetNumBytes());
                std::reverse(temp, temp + len);
                wd->i.SetBinary((uint8*)temp, len);
            }
        }

        if (type == MEM_CHECK || type == MODULE_CHECK)
            MemCheckIds.push_back(id);

        if (type == MEM_CHECK || type == PAGE_CHECK_A || type == PAGE_CHECK_B || type == PROC_CHECK)
        {
            wd->Address = fields[3].GetUInt32();
            wd->Length = fields[4].GetUInt8();
        }

        // PROC_CHECK support missing
        if (type == MEM_CHECK || type == MPQ_CHECK || type == LUA_STR_CHECK || type == DRIVER_CHECK || type == MODULE_CHECK)
            wd->str = fields[5].GetString();

        _data_map[id] = wd;

        if (type == MPQ_CHECK || type == MEM_CHECK)
        {
            std::string result = fields[2].GetString();
            WardenDataResult *wr = new WardenDataResult();
            wr->res.SetHexStr(result.c_str());
            int len = result.size() / 2;
            if (wr->res.GetNumBytes() < len)
            {
                uint8 *temp = new uint8[len];
                memset(temp, 0, len);
                memcpy(temp, wr->res.AsByteArray(), wr->res.GetNumBytes());
                std::reverse(temp, temp + len);
                wr->res.SetBinary((uint8*)temp, len);
                delete [] temp;
            }
            _result_map[id] = wr;
        }
    } while (result->NextRow());

    sLog->outString();
    sLog->outString(">> Loaded %u warden data and results", count);
}

WardenData *CWardenDataStorage::GetWardenDataById(uint32 Id)
{
    std::map<uint32, WardenData*>::const_iterator itr = _data_map.find(Id);
    if (itr != _data_map.end())
        return itr->second;
    return NULL;
}

WardenDataResult *CWardenDataStorage::GetWardenResultById(uint32 Id)
{
    std::map<uint32, WardenDataResult*>::const_iterator itr = _result_map.find(Id);
    if (itr != _result_map.end())
        return itr->second;
    return NULL;
}
