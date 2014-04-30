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
#include <ace/Singleton.h>
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
}

class BattlenetMgr
{
    friend class ACE_Singleton<BattlenetMgr, ACE_Null_Mutex>;
    BattlenetMgr() { }
    ~BattlenetMgr() { }

public:
    void Load();
    bool HasComponent(Battlenet::Component const* component) const;
    bool HasProgram(std::string const& program) const { return _programs.count(program); }
    bool HasPlatform(std::string const& platform) const { return _platforms.count(platform); }
    bool HasBuild(uint32 build) const { return _builds.count(build); }

private:
    void LoadComponents();
    void LoadModules();

    std::set<Battlenet::Component*> _components;
    std::set<std::string> _programs;
    std::set<std::string> _platforms;
    std::set<uint32> _builds;
};

#define sBattlenetMgr ACE_Singleton<BattlenetMgr, ACE_Null_Mutex>::instance()

#endif // __BATTLENETMANAGER_H__
