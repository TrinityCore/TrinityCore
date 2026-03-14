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
#include "murder_row.h"

BossBoundaryData const boundaries =
{
    { DATA_KYSTIA_MANAHEART, new ZRangeBoundary(-7.0729f, -5.2693f) }
};

static constexpr ObjectData creatureData[] =
{
    { BOSS_KYSTIA_MANAHEART,        DATA_KYSTIA_MANAHEART        },
    { BOSS_ZAEN_BLADESORROW,        DATA_ZAEN_BLADESORROW        },
    { BOSS_XATHUUX_THE_ANNIHILATOR, DATA_XATHUUX_THE_ANNIHILATOR },
    { BOSS_LITHIEL_CINDERFURY,      DATA_LITHIEL_CINDERFURY      },
    { NPC_NIBBLES,                  DATA_NIBBLES                 }
};

static constexpr DungeonEncounterData const encounters[] =
{
    { DATA_KYSTIA_MANAHEART,        {{ 3101 }} },
    { DATA_ZAEN_BLADESORROW,        {{ 3102 }} },
    { DATA_XATHUUX_THE_ANNIHILATOR, {{ 3103 }} },
    { DATA_LITHIEL_CINDERFURY,      {{ 3105 }} }
};

static constexpr DoorData doorData[] =
{
    { GO_FEL_DOOR, DATA_KYSTIA_MANAHEART, EncounterDoorBehavior::OpenWhenNotInProgress }
};

class instance_murder_row : public InstanceMapScript
{
public:
    instance_murder_row() : InstanceMapScript(MRScriptName, 2813) { }

    struct instance_murder_row_InstanceMapScript: public InstanceScript
    {
        instance_murder_row_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
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
        return new instance_murder_row_InstanceMapScript(map);
    }
};

void AddSC_instance_murder_row()
{
    new instance_murder_row();
}
