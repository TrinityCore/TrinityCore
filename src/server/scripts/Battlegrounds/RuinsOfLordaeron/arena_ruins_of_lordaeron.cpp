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
#include "TaskScheduler.h"

struct arena_ruins_of_lordaeron : ArenaScript
{
    enum BattlegroundRLGameObjects
    {
        BG_RL_OBJECT_TYPE_DOOR_1    = 185918,
        BG_RL_OBJECT_TYPE_DOOR_2    = 185917,
        BG_RL_OBJECT_TYPE_BUFF_1    = 184663,
        BG_RL_OBJECT_TYPE_BUFF_2    = 184664
    };

    explicit arena_ruins_of_lordaeron(BattlegroundMap* map) : ArenaScript(map) { }

    void OnUpdate(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void OnInit() override
    {
        AddDoor(BG_RL_OBJECT_TYPE_DOOR_1, 1293.561f, 1601.938f, 31.60557f, -1.457349f, 0, 0, -0.6658813f, 0.7460576f);
        AddDoor(BG_RL_OBJECT_TYPE_DOOR_2, 1278.648f, 1730.557f, 31.60557f, 1.684245f, 0, 0, 0.7460582f, 0.6658807f);
    }

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

        _scheduler.Schedule(1min, [&](TaskContext)
        {
            CreateObject(BG_RL_OBJECT_TYPE_BUFF_1, 1328.719971f, 1632.719971f, 36.730400f, -1.448624f, 0, 0, 0.6626201f, -0.7489557f);
            CreateObject(BG_RL_OBJECT_TYPE_BUFF_2, 1243.300049f, 1699.170044f, 34.872601f, -0.06981307f, 0, 0, 0.03489945f, -0.9993908f);
        });
    }

    void AddDoor(uint32 entry, float x, float y, float z, float o, float rotation0, float rotation1, float rotation2, float rotation3, GOState goState = GO_STATE_READY)
    {
        if (GameObject const* go = CreateObject(entry, x, y, z, o, rotation0, rotation1, rotation2, rotation3, goState))
            _doorGUIDs.emplace_back(go->GetGUID());
    }

private:
    GuidVector _doorGUIDs;
    TaskScheduler _scheduler;
};

void AddSC_arena_ruins_of_lordaeron()
{
    RegisterBattlegroundMapScript(arena_ruins_of_lordaeron, 572);
}
