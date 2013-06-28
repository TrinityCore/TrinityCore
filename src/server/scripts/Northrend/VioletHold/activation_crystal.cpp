/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "violet_hold.h"

class go_activation_crystal : public GameObjectScript
{
public:
    go_activation_crystal() : GameObjectScript("go_activation_crystal") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        go->EventInform(EVENT_ACTIVATE_CRYSTAL);
        return false;
    }
};

void AddSC_activation_crystal()
{
    new go_activation_crystal();
}
