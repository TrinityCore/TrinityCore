/*
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 * 
 * This program is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once

#include "TSDatabase.h"
#include "DatabaseEnv.h"
#include "TSString.h"
#include <memory>
#include "TSConsole.h"

class TC_GAME_API TSDatabaseImpl final : public TSDatabaseResult {
    Field* field = nullptr;
    QueryResult result;
public:
    TSDatabaseImpl(QueryResult result) : TSDatabaseResult()
    {
        this->result = result;
    }

    bool IsValid() final
    {
        return result!=nullptr;
    }

    bool GetRow() final
    {
        if(!result)
        {
            return false;
        }

        if(!field)
        {
            field = result->Fetch();
            return true;
        }

        bool v = result->NextRow();
        if(v)
        {
            field = result->Fetch();
        }
        return v;
    }

    uint8 GetUInt8(int index) final { return field[index].GetUInt8(); }
    uint16 GetUInt16(int index) final { return field[index].GetUInt16(); }
    uint32 GetUInt32(int index) final { return field[index].GetUInt32(); }
    uint64 GetUInt64(int index) final { return field[index].GetUInt64(); }

    int8 GetInt8(int index) final { return field[index].GetInt8(); }
    int16 GetInt16(int index) final { return field[index].GetInt16(); }
    int32 GetInt32(int index) final { return field[index].GetInt32(); }
    int64 GetInt64(int index) final { return field[index].GetInt64(); }

    float GetFloat(int index) final { return field[index].GetFloat(); }
    double GetDouble(int index) final { return field[index].GetDouble(); }

    TSString GetString(int index) final { return TSString(field[index].GetString()); }
};

std::shared_ptr<TSDatabaseResult> QueryWorld(TSString query)
{
    return std::make_shared<TSDatabaseImpl>(WorldDatabase.Query(query.std_str().c_str()));
}

std::shared_ptr<TSDatabaseResult> QueryCharacters(TSString query)
{
    return std::make_shared<TSDatabaseImpl>(CharacterDatabase.Query(query.std_str().c_str()));
}

std::shared_ptr<TSDatabaseResult> QueryAuth(TSString query)
{
    return std::make_shared<TSDatabaseImpl>(LoginDatabase.Query(query.std_str().c_str()));
}