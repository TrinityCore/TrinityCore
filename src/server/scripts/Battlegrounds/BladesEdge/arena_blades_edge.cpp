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

struct arena_blades_edge : ArenaScript
{
    enum GameObjects
    {
        BG_BE_OBJECT_TYPE_DOOR_1    = 183971,
        BG_BE_OBJECT_TYPE_DOOR_2    = 183973,
        BG_BE_OBJECT_TYPE_DOOR_3    = 183970,
        BG_BE_OBJECT_TYPE_DOOR_4    = 183972,
        BG_BE_OBJECT_TYPE_BUFF_1    = 184663,
        BG_BE_OBJECT_TYPE_BUFF_2    = 184664
    };

    explicit arena_blades_edge(BattlegroundMap* map) : ArenaScript(map) { }

    void OnUpdate(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void OnInit() override
    {
        AddDoor(BG_BE_OBJECT_TYPE_DOOR_1, 6287.277f, 282.1877f, 3.810925f, -2.260201f, 0, 0, 0.9044551f, -0.4265689f);
        AddDoor(BG_BE_OBJECT_TYPE_DOOR_2, 6189.546f, 241.7099f, 3.101481f, 0.8813917f, 0, 0, 0.4265689f, 0.9044551f);
        AddDoor(BG_BE_OBJECT_TYPE_DOOR_3, 6299.116f, 296.5494f, 3.308032f, 0.8813917f, 0, 0, 0.4265689f, 0.9044551f);
        AddDoor(BG_BE_OBJECT_TYPE_DOOR_4, 6177.708f, 227.3481f, 3.604374f, -2.260201f, 0, 0, 0.9044551f, -0.4265689f);
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
            CreateObject(BG_BE_OBJECT_TYPE_BUFF_1, 6249.042f, 275.3239f, 11.22033f, -1.448624f, 0, 0, 0.6626201f, -0.7489557f);
            CreateObject(BG_BE_OBJECT_TYPE_BUFF_2, 6228.26f, 249.566f, 11.21812f, -0.06981307f, 0, 0, 0.03489945f, -0.9993908f);
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

void AddSC_arena_blades_edge()
{
    RegisterBattlegroundMapScript(arena_blades_edge, 1672);
}
