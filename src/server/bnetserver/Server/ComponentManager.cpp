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

#include "ComponentManager.h"
#include "DatabaseEnv.h"

Battlenet::ComponentMgr::~ComponentMgr()
{
    for (Component* component : _components)
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
            Component* component = new Component();
            component->Program = fields[0].GetString();
            component->Platform = fields[1].GetString();
            component->Build = fields[2].GetUInt32();

            _components.insert(component);
            _programs.insert(component->Program);
            _platforms.insert(component->Platform);

        } while (result->NextRow());
    }
}

bool Battlenet::ComponentMgr::HasComponent(Battlenet::Component const* component) const
{
    for (Component const* c : _components)
        if (component->Program == c->Program && component->Platform == c->Platform && component->Build == c->Build)
            return true;

    return false;
}
