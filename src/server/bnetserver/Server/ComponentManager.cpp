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

#include "ComponentManager.h"
#include "DatabaseEnv.h"

Battlenet::ComponentMgr::~ComponentMgr()
{
    for (Version::Record* component : _components)
        delete component;
}

void Battlenet::ComponentMgr::Load()
{
    QueryResult result = LoginDatabase.Query("SELECT Program, Platform, Build FROM battlenet_components");
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            Version::Record* component = new Version::Record();
            component->ProgramId = fields[0].GetString();
            component->Component = fields[1].GetString();
            component->Version = fields[2].GetUInt32();

            _components.insert(component);
            _programs.insert(component->ProgramId);
            _platforms.insert(component->Component);

        } while (result->NextRow());
    }
}

bool Battlenet::ComponentMgr::HasComponent(Battlenet::Version::Record const* component) const
{
    for (Version::Record const* c : _components)
        if (component->ProgramId == c->ProgramId && component->Component == c->Component && component->Version == c->Version)
            return true;

    return false;
}
