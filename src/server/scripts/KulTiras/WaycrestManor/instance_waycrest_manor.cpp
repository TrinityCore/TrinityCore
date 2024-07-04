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
#include "waycrest_manor.h"

static BossBoundaryData const boundaries =
{
    { DATA_HEARTSBANE_TRIAD, new BoundaryIntersectionBoundary(new ZRangeBoundary(235.0f, 243.0f), new RectangleBoundary(-618.580f, -524.305f, -188.971f, -137.363f)) },
};

ObjectData const creatureData[] =
{
    { BOSS_SISTER_BRIAR,  DATA_SISTER_BRIAR  },
    { BOSS_SISTER_MALADY, DATA_SISTER_MALADY },
    { BOSS_SISTER_SOLENA, DATA_SISTER_SOLENA },
    { 0,                  0                  }  // END
};

DoorData const doorData[] =
{
    { GO_HEARTSBANE_TRIAD_DOOR,                 DATA_HEARTSBANE_TRIAD,          EncounterDoorBehavior::OpenWhenNotInProgress },
    { 0,                                        0,                              EncounterDoorBehavior::OpenWhenNotInProgress }  // END
};

DungeonEncounterData const encounters[] =
{
    { DATA_HEARTSBANE_TRIAD,       {{ 2113 }} },
    { DATA_SOULBOUND_GOLIATH,      {{ 2114 }} },
    { DATA_RAAL_THE_GLUTTONOUS,    {{ 2115 }} },
    { DATA_LORD_AND_LADY_WAYCREST, {{ 2116 }} },
    { DATA_GORAK_TUL,              {{ 2117 }} }
};

class instance_waycrest_manor : public InstanceMapScript
{
public:
    instance_waycrest_manor() : InstanceMapScript("instance_waycrest_manor", 1862) { }

    struct instance_waycrest_manor_InstanceMapScript : public InstanceScript
    {
        instance_waycrest_manor_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, nullptr);
            LoadDoorData(doorData);
            LoadBossBoundaries(boundaries);
            LoadDungeonEncounterData(encounters);
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_waycrest_manor_InstanceMapScript(map);
    }
};

void AddSC_instance_waycrest_manor()
{
    new instance_waycrest_manor();
}
