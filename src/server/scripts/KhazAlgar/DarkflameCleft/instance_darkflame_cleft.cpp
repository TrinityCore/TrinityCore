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
#include "darkflame_cleft.h"

static constexpr ObjectData creatureData[] =
{
    { DATA_OL_WAXBEARD,     BOSS_OL_WAXBEARD     },
    { DATA_BLAZIKON,        BOSS_BLAZIKON        },
    { DATA_THE_CANDLE_KING, BOSS_THE_CANDLE_KING },
    { DATA_THE_DARKNESS,    BOSS_THE_DARKNESS    }
};

static constexpr DungeonEncounterData const encounters[] =
{
    { DATA_OL_WAXBEARD,     {{ 2829 }} },
    { DATA_BLAZIKON,        {{ 2826 }} },
    { DATA_THE_CANDLE_KING, {{ 2787 }} },
    { DATA_THE_DARKNESS,    {{ 2788 }} }
};

class instance_darkflame_cleft : public InstanceMapScript
{
public:
    instance_darkflame_cleft() : InstanceMapScript(DCScriptName, 2651) { }

    struct instance_darkflame_cleft_InstanceMapScript: public InstanceScript
    {
        instance_darkflame_cleft_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, {});
            LoadDungeonEncounterData(encounters);
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_darkflame_cleft_InstanceMapScript(map);
    }
};

void AddSC_instance_darkflame_cleft()
{
    new instance_darkflame_cleft();
}
