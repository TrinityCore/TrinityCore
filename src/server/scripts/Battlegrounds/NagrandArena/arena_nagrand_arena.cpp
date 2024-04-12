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

struct arena_nagrand : ArenaScript
{
    enum GameObjects
    {
        BG_NA_OBJECT_TYPE_DOOR_1    = 183978,
        BG_NA_OBJECT_TYPE_DOOR_2    = 183980,
        BG_NA_OBJECT_TYPE_DOOR_3    = 183977,
        BG_NA_OBJECT_TYPE_DOOR_4    = 183979,
        BG_NA_OBJECT_TYPE_BUFF_1    = 184663,
        BG_NA_OBJECT_TYPE_BUFF_2    = 184664
    };

    explicit arena_nagrand(BattlegroundMap* map) : ArenaScript(map) { }

    void OnUpdate(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void OnInit() override
    {
        AddDoor(BG_NA_OBJECT_TYPE_DOOR_1, 4031.854f, 2966.833f, 12.6462f, -2.648788f, 0, 0, 0.9697962f, -0.2439165f);
        AddDoor(BG_NA_OBJECT_TYPE_DOOR_2, 4081.179f, 2874.97f, 12.39171f, 0.4928045f, 0, 0, 0.2439165f, 0.9697962f);
        AddDoor(BG_NA_OBJECT_TYPE_DOOR_3, 4023.709f, 2981.777f, 10.70117f, -2.648788f, 0, 0, 0.9697962f, -0.2439165f);
        AddDoor(BG_NA_OBJECT_TYPE_DOOR_4, 4090.064f, 2858.438f, 10.23631f, 0.4928045f, 0, 0, 0.2439165f, 0.9697962f);
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
            CreateObject(BG_NA_OBJECT_TYPE_BUFF_1, 4009.189941f, 2895.250000f, 13.052700f, -1.448624f, 0, 0, 0.6626201f, -0.7489557f);
            CreateObject(BG_NA_OBJECT_TYPE_BUFF_2, 4103.330078f, 2946.350098f, 13.051300f, -0.06981307f, 0, 0, 0.03489945f, -0.9993908f);
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

void AddSC_arena_nagrand()
{
    RegisterBattlegroundMapScript(arena_nagrand, 1505);
}
