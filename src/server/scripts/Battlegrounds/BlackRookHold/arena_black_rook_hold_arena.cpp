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

namespace BlackRookHoldArena
{
    namespace MapIds
    {
        static constexpr uint32 BlackRookHoldArena = 1504;
    }

    namespace GameObjects
    {
        static constexpr uint32 BlackRookDoor02 = 245763;
        static constexpr uint32 BlackRookDoor05 = 245766;
        static constexpr uint32 BlackRookDoor06 = 245767;
        static constexpr uint32 BlackRookDoor09 = 245770;
        static constexpr uint32 BlackRookDoor07 = 245768;
        static constexpr uint32 BlackRookDoor10 = 245781;
    }
}

struct arena_black_rook_hold_arena : ArenaScript
{
    explicit arena_black_rook_hold_arena(BattlegroundMap* map) : ArenaScript(map) { }

    void OnStart() override
    {
        for (ObjectGuid const& guid : _doorGUIDs)
            if (GameObject* door = battlegroundMap->GetGameObject(guid))
                door->UseDoorOrButton();
    }

    void OnGameObjectCreate(GameObject* gameobject) override
    {
        switch (gameobject->GetEntry())
        {
            case BlackRookHoldArena::GameObjects::BlackRookDoor02:
            case BlackRookHoldArena::GameObjects::BlackRookDoor05:
            case BlackRookHoldArena::GameObjects::BlackRookDoor06:
            case BlackRookHoldArena::GameObjects::BlackRookDoor09:
            case BlackRookHoldArena::GameObjects::BlackRookDoor07:
            case BlackRookHoldArena::GameObjects::BlackRookDoor10:
                _doorGUIDs.emplace_back(gameobject->GetGUID());
                break;
            default:
                break;
        }
    }

private:
    GuidVector _doorGUIDs;
};

void AddSC_arena_black_rook_hold_arena()
{
    RegisterBattlegroundMapScript(arena_black_rook_hold_arena, BlackRookHoldArena::MapIds::BlackRookHoldArena);
}
