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

#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "auchindoun.h"

constexpr ObjectData creatureData[] =
{
    { BOSS_VIGILANT_KAATHAR,  DATA_VIGILANT_KAATHAR   },
    { BOSS_SOULBINDER_NYAMI,  DATA_SOULBINDER_NYAMI   },
    { BOSS_AZZAKEL,           DATA_AZZAKEL            },
    { BOSS_TERONGOR,          DATA_TERONGOR           },
    { NPC_SOULBINDER_TUULANI, DATA_SOULBINDER_TUULANI },
    { 0,                      0                       }  // END
};

constexpr ObjectData objectData[] =
{
    { GO_HOLY_BARRIER, DATA_HOLY_BARRIER },
    { 0,               0                 }  // END
};

constexpr DungeonEncounterData encounters[] =
{
    { DATA_VIGILANT_KAATHAR, {{ 1678 }}  },
    { DATA_SOULBINDER_NYAMI, {{ 1685 }}  },
    { DATA_AZZAKEL,          {{ 1686 }}  },
    { DATA_TERONGOR,         {{ 1714 }}  }
};

class instance_auchindoun : public InstanceMapScript
{
public:
    instance_auchindoun() : InstanceMapScript("instance_auchindoun", 1182) { }

    struct instance_auchindoun_InstanceMapScript : public InstanceScript
    {
        instance_auchindoun_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, objectData);
            LoadDungeonEncounterData(encounters);
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_auchindoun_InstanceMapScript(map);
    }
};

void AddSC_instance_auchindoun()
{
    new instance_auchindoun();
}
