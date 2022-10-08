/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "InstanceScript.h"
#include "GameObject.h"
#include "maw_of_souls.h"

DoorData const doorData[] =
{
    { GO_WALL_OF_SOULS,     DATA_HARBARON, DOOR_TYPE_ROOM },
{ GO_WALL_OF_SOULS_2,   DATA_HARBARON, DOOR_TYPE_ROOM },
{ GO_WALL_OF_SOULS_3,   DATA_HARBARON, DOOR_TYPE_ROOM },
{ GO_MURKY_FOG,         DATA_HARBARON, DOOR_TYPE_ROOM },
{ GO_COLLISION_WALL,    DATA_HARBARON, DOOR_TYPE_ROOM },
{ 0, 0, DOOR_TYPE_ROOM }
};


class instance_maw_of_souls : public InstanceMapScript
{
public:
    instance_maw_of_souls() : InstanceMapScript(MOSScriptName, 1492) { }

    struct instance_maw_of_souls_InstanceScript : public InstanceScript
    {
        instance_maw_of_souls_InstanceScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadDoorData(doorData);
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            if (!go)
                return;

            switch (go->GetEntry())
            {
            case GO_WALL_OF_SOULS:
            case GO_WALL_OF_SOULS_2:
            case GO_WALL_OF_SOULS_3:
            case GO_MURKY_FOG:
            case GO_COLLISION_WALL:
                AddDoor(go, true);
                break;

            default: break;
            }
        }

        void OnGameObjectRemove(GameObject* go) override
        {
            if (!go)
                return;

            switch (go->GetEntry())
            {
            case GO_WALL_OF_SOULS:
            case GO_WALL_OF_SOULS_2:
            case GO_WALL_OF_SOULS_3:
            case GO_MURKY_FOG:
            case GO_COLLISION_WALL:
                AddDoor(go, false);
                break;

            default: break;
            }
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_maw_of_souls_InstanceScript(map);
    }
};

void AddSC_instance_maw_of_souls()
{
    new instance_maw_of_souls();
}

