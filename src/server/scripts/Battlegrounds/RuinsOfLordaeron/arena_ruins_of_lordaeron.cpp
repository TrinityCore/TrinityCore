/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "Battleground.h"
#include "BattlegroundScript.h"
#include "GameObject.h"
#include "Map.h"
#include "ScriptMgr.h"

namespace RuinsOfLordaeron
{
    namespace GameObjects
    {
        static constexpr uint32 Door01 = 185918;
        static constexpr uint32 Door02 = 185917;
    }
}

struct arena_ruins_of_lordaeron : ArenaScript
{
    explicit arena_ruins_of_lordaeron(BattlegroundMap* map) : ArenaScript(map) { }

    void OnStart() override
    {
        for (ObjectGuid const& guid : _doorGUIDs)
        {
            if (GameObject* door = battlegroundMap->GetGameObject(guid))
            {
                door->UseDoorOrButton();
                door->DespawnOrUnsummon(5s);
            }
        }
    }

    void OnGameObjectCreate(GameObject* gameobject) override
    {
        switch (gameobject->GetEntry())
        {
            case RuinsOfLordaeron::GameObjects::Door01:
            case RuinsOfLordaeron::GameObjects::Door02:
                _doorGUIDs.emplace_back(gameobject->GetGUID());
                break;
            default:
                break;
        }
    }

private:
    GuidVector _doorGUIDs;
};

void AddSC_arena_ruins_of_lordaeron()
{
    RegisterBattlegroundMapScript(arena_ruins_of_lordaeron, 572);
}
