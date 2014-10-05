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

#include "BattlenetManager.h"
#include "DatabaseEnv.h"

BattlenetMgr::~BattlenetMgr()
{
    for (Battlenet::Component* component : _components)
        delete component;

    for (auto const& m : _modules)
        delete m.second;
}

void BattlenetMgr::Load()
{
    LoadComponents();
    LoadModules();
}

void BattlenetMgr::LoadComponents()
{
    QueryResult result = LoginDatabase.Query("SELECT Program, Platform, Build FROM battlenet_components");
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            Battlenet::Component* component = new Battlenet::Component();
            component->Program = fields[0].GetString();
            component->Platform = fields[1].GetString();
            component->Build = fields[2].GetUInt32();

            _components.insert(component);
            _programs.insert(component->Program);
            _platforms.insert(component->Platform);

        } while (result->NextRow());
    }
}

void BattlenetMgr::LoadModules()
{
    QueryResult result = LoginDatabase.Query("SELECT `Hash`, `Name`, `Type`, `System`, `Data` FROM battlenet_modules");
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            Battlenet::ModuleInfo* module = new Battlenet::ModuleInfo();
            module->Type = fields[2].GetString();
            HexStrToByteArray(fields[0].GetString(), module->ModuleId);
            std::string data = fields[4].GetString();
            module->DataSize = data.length() / 2;
            if (module->DataSize)
            {
                module->Data = new uint8[data.length() / 2];
                HexStrToByteArray(data, module->Data);
            }

            _modules[{ fields[3].GetString(), fields[1].GetString() }] = module;
        } while (result->NextRow());
    }
}

bool BattlenetMgr::HasComponent(Battlenet::Component const* component) const
{
    for (Battlenet::Component const* c : _components)
        if (component->Program == c->Program && component->Platform == c->Platform && component->Build == c->Build)
            return true;

    return false;
}

Battlenet::ModuleInfo* BattlenetMgr::CreateModule(std::string const& os, std::string const& name) const
{
    Battlenet::ModuleKey key { os, name };
    ASSERT(_modules.count(key));

    return new Battlenet::ModuleInfo(*_modules.at(key));
}
