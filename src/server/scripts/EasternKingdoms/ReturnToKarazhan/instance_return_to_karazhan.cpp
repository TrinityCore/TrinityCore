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
#include "return_to_karazhan.h"

BossBoundaryData const boundaries =
{
    { DATA_MAIDEN_OF_VIRTUE_RTK, new CircleBoundary(Position(-10945.900391f, -2103.530029f, 92.794197f), 55.0f) },
    { DATA_SHADE_OF_MEDIVH, new CircleBoundary(Position(-4599.149902f, -2517.947266f, 2876.506836f), 35.0f) },
};

ObjectData const creatureData[] =
{
    { BOSS_MAIDEN_OF_VIRTUE_RTK, DATA_MAIDEN_OF_VIRTUE_RTK },
    { BOSS_THE_CURATOR_RTK,      DATA_THE_CURATOR_RTK      },
    { BOSS_MANA_DEVOURER,        DATA_MANA_DEVOURER        },
    { 0,                         0                         }  // END
};

DoorData const doorData[] =
{
    { GO_STRANGE_WALL,        DATA_THE_CURATOR_RTK, EncounterDoorBehavior::OpenWhenDone          },
    { GO_SUSPICIOUS_BOOKCASE, DATA_SHADE_OF_MEDIVH, EncounterDoorBehavior::OpenWhenDone          },
    { GO_MEDIVH_DOOR,         DATA_SHADE_OF_MEDIVH, EncounterDoorBehavior::OpenWhenNotInProgress },
    { 0,                      0,                    EncounterDoorBehavior::OpenWhenNotInProgress }
};

DungeonEncounterData const encounters[] =
{
    { DATA_OPERA_HALL,           {{ 1957 }} },
    { DATA_MAIDEN_OF_VIRTUE_RTK, {{ 1954 }} },
    { DATA_MOROES,               {{ 1961 }} },
    { DATA_ATTUMEN_THE_HUNTSMAN, {{ 1960 }} },
    { DATA_THE_CURATOR_RTK,      {{ 1964 }} },
    { DATA_SHADE_OF_MEDIVH,      {{ 1965 }} },
    { DATA_MANA_DEVOURER,        {{ 1959 }} },
    { DATA_VIZADUUM_THE_WATCHER, {{ 2017 }} },
    { DATA_NIGHTBANE,            {{ 2031 }} }
};

class instance_return_to_karazhan : public InstanceMapScript
{
    public:
        instance_return_to_karazhan() : InstanceMapScript(RTKScriptName, 1651) { }

        struct instance_return_to_karazhan_InstanceMapScript: public InstanceScript
        {
            instance_return_to_karazhan_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, nullptr);
                LoadBossBoundaries(boundaries);
                LoadDoorData(doorData);
                LoadDungeonEncounterData(encounters);
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_return_to_karazhan_InstanceMapScript(map);
        }
};

void AddSC_instance_return_to_karazhan()
{
    new instance_return_to_karazhan();
}
