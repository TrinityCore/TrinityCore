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
#include "uldaman_legacy_of_tyr.h"

BossBoundaryData const boundaries =
{
    { DATA_SENTINEL_TALONDRAS,          new CircleBoundary(Position(59.4028f, -653.566f), 38.0f) }
};

static constexpr ObjectData creatureData[] =
{
    { BOSS_OLAF,               DATA_OLAF               },
    { BOSS_BAELOG,             DATA_BAELOG             },
    { BOSS_ERIK_THE_SWIFT,     DATA_ERIK_THE_SWIFT     },
    { BOSS_BROMACH,            DATA_BROMACH            },
    { BOSS_SENTINEL_TALONDRAS, DATA_SENTINEL_TALONDRAS },
    { BOSS_EMBERON,            DATA_EMBERON            },
    { BOSS_CHRONO_LORD_DEIOS,  DATA_CHRONO_LORD_DEIOS  }
};

static constexpr DoorData doorData[] =
{
    { GO_DOOR_START_TALONDRAS, DATA_SENTINEL_TALONDRAS, EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_DOOR_EXIT_TALONDRAS, DATA_SENTINEL_TALONDRAS, EncounterDoorBehavior::OpenWhenDone },
};

DungeonEncounterData const encounters[] =
{
    { DATA_THE_LOST_DWARVES,   {{ 2555 }} },
    { DATA_BROMACH,            {{ 2556 }} },
    { DATA_SENTINEL_TALONDRAS, {{ 2557 }} },
    { DATA_EMBERON,            {{ 2558 }} },
    { DATA_CHRONO_LORD_DEIOS,  {{ 2559 }} }
};

class instance_uldaman_legacy_of_tyr : public InstanceMapScript
{
public:
    instance_uldaman_legacy_of_tyr() : InstanceMapScript(ULOTScriptName, 2451) { }

    struct instance_uldaman_legacy_of_tyr_InstanceMapScript: public InstanceScript
    {
        instance_uldaman_legacy_of_tyr_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
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
        return new instance_uldaman_legacy_of_tyr_InstanceMapScript(map);
    }
};

void AddSC_instance_uldaman_legacy_of_tyr()
{
    new instance_uldaman_legacy_of_tyr();
}
