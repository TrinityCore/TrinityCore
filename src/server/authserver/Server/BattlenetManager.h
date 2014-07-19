/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef __BATTLENETMANAGER_H__
#define __BATTLENETMANAGER_H__

#include "Define.h"
#include <string>
#include <set>
#include <map>

namespace Battlenet
{
    struct Component
    {
        std::string Program;
        std::string Platform;
        uint32 Build;
    };

    struct ModuleKey
    {
        std::string Platform;
        std::string Name;

        bool operator<(ModuleKey const& right) const
        {
            int32 res = Platform.compare(right.Platform);
            if (res < 0)
                return true;
            else if (res > 0)
                return false;

            return Name < right.Name;
        }
    };

    struct ModuleInfo
    {
        ModuleInfo() : Region("EU"), DataSize(0), Data(nullptr) { }
        ModuleInfo(ModuleInfo const& right) : Type(right.Type), Region(right.Region), DataSize(right.DataSize), Data(nullptr)
        {
            memcpy(ModuleId, right.ModuleId, 32);
            if (DataSize)
            {
                Data = new uint8[DataSize];
                memcpy(Data, right.Data, DataSize);
            }
        }
        ~ModuleInfo()
        {
            delete Data;
        }

        std::string Type;
        std::string Region;
        uint8 ModuleId[32];
        uint32 DataSize;
        uint8* Data;
    };

    struct RealmId
    {
        uint8 Region;
        uint8 Battlegroup;
        uint32 Index;
        uint32 Build;
    };
}

class BattlenetMgr
{
    BattlenetMgr() { }
    ~BattlenetMgr();

public:
    void Load();
    bool HasComponent(Battlenet::Component const* component) const;
    bool HasProgram(std::string const& program) const { return _programs.count(program) != 0; }
    bool HasPlatform(std::string const& platform) const { return _platforms.count(platform) != 0; }
    Battlenet::ModuleInfo* CreateModule(std::string const& os, std::string const& name) const;

    static BattlenetMgr* instance()
    {
        static BattlenetMgr instance;
        return &instance;
    }

private:
    void LoadComponents();
    void LoadModules();

    std::set<Battlenet::Component*> _components;
    std::set<std::string> _programs;
    std::set<std::string> _platforms;
    std::map<Battlenet::ModuleKey, Battlenet::ModuleInfo*> _modules;
};

#define sBattlenetMgr BattlenetMgr::instance()

#endif // __BATTLENETMANAGER_H__
