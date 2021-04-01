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

#include "TSString.h"
#include <memory>
#include <string>

struct MySQLConnectionInfo;

class TC_GAME_API TSDatabaseResult : public std::enable_shared_from_this<TSDatabaseResult> {
public:
    using std::enable_shared_from_this<TSDatabaseResult>::shared_from_this;
    TSDatabaseResult* operator->(){return this;}
    virtual uint8 GetUInt8(int index) = 0;
    virtual uint16 GetUInt16(int index) = 0;
    virtual uint32 GetUInt32(int index) = 0;
    virtual uint64 GetUInt64(int index) = 0;

    virtual int8 GetInt8(int index) = 0;
    virtual int16 GetInt16(int index) = 0;
    virtual int32 GetInt32(int index) = 0;
    virtual int64 GetInt64(int index) = 0;

    virtual float GetFloat(int index) = 0;
    virtual double GetDouble(int index) = 0;

    virtual TSString GetString(int index) = 0;

    virtual bool GetRow() = 0;
    virtual bool IsValid() = 0;
};

class TC_GAME_API TSDatabaseConnectionInfo {
public:
    TSDatabaseConnectionInfo() = default;
    TSDatabaseConnectionInfo(
        MySQLConnectionInfo const* info
    );

    TSDatabaseConnectionInfo* operator->() { return this; }

    TSString User();
    TSString Password();
    TSString Database();
    TSString Host();
    TSString PortOrSocket();
    TSString SSL();

private:
    MySQLConnectionInfo const* _info;
};

TC_GAME_API std::shared_ptr<TSDatabaseResult> QueryWorld(TSString query);
TC_GAME_API std::shared_ptr<TSDatabaseResult> QueryCharacters(TSString query);
TC_GAME_API std::shared_ptr<TSDatabaseResult> QueryAuth(TSString query);

TC_GAME_API std::shared_ptr<TSDatabaseConnectionInfo> WorldDatabaseInfo();
TC_GAME_API std::shared_ptr<TSDatabaseConnectionInfo> CharactersDatabaseInfo();
TC_GAME_API std::shared_ptr<TSDatabaseConnectionInfo> AuthDatabaseInfo();

#define LoadRows(cls,query) cls::Load(query)
