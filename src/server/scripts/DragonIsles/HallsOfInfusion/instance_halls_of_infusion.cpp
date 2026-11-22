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

#include "AreaBoundary.h"
#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "halls_of_infusion.h"

BossBoundaryData const boundaries =
{
    { DATA_WATCHER_IRIDEUS, new ZRangeBoundary(-40.0f, -32.0f) }
};

static constexpr ObjectData creatureData[] =
{
    { DATA_WATCHER_IRIDEUS,       BOSS_WATCHER_IRIDEUS       },
    { DATA_GULPING_GOLIATH,       BOSS_GULPING_GOLIATH       },
    { DATA_KHAJIN_THE_UNYIELDING, BOSS_KHAJIN_THE_UNYIELDING },
    { DATA_PRIMAL_TSUNAMI,        BOSS_PRIMAL_TSUNAMI        }
};

static constexpr DungeonEncounterData const encounters[] =
{
    { DATA_WATCHER_IRIDEUS,       {{ 2615 }} },
    { DATA_GULPING_GOLIATH,       {{ 2616 }} },
    { DATA_KHAJIN_THE_UNYIELDING, {{ 2617 }} },
    { DATA_PRIMAL_TSUNAMI,        {{ 2618 }} }
};

static constexpr DoorData doorData[] =
{
    { GO_WATCHER_IRIDEUS_DOOR1, DATA_WATCHER_IRIDEUS, EncounterDoorBehavior::OpenWhenDone },
    { GO_WATCHER_IRIDEUS_DOOR2, DATA_WATCHER_IRIDEUS, EncounterDoorBehavior::OpenWhenDone }
};

class instance_halls_of_infusion : public InstanceMapScript
{
public:
    instance_halls_of_infusion() : InstanceMapScript(HOFScriptName, 2527) { }

    struct instance_halls_of_infusion_InstanceMapScript: public InstanceScript
    {
        instance_halls_of_infusion_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, {});
            LoadDoorData(doorData);
            LoadBossBoundaries(boundaries);
            LoadDungeonEncounterData(encounters);
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_halls_of_infusion_InstanceMapScript(map);
    }
};

void AddSC_instance_halls_of_infusion()
{
    new instance_halls_of_infusion();
}
