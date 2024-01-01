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

#include "ScriptMgr.h"
#include "throne_of_the_four_winds.h"
#include "InstanceScript.h"

ObjectData const creatureData[] =
{
    { NPC_ALAKIR,   BOSS_ALAKIR   },
    { 0,            0             } // END
};

DungeonEncounterData const encounters[] =
{
    { BOSS_CONCLAVE_OF_WIND,    {{ 1035 }}  },
    { BOSS_ALAKIR,              {{ 1034 }}  }
};

class instance_throne_of_the_four_winds : public InstanceMapScript
{
public:
    instance_throne_of_the_four_winds() : InstanceMapScript(TotFWScriptName, 754) { }

    struct instance_throne_of_the_four_winds_InstanceMapScript : public InstanceScript
    {
        instance_throne_of_the_four_winds_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, nullptr);
            LoadDungeonEncounterData(encounters);
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_throne_of_the_four_winds_InstanceMapScript(map);
    }
};

void AddSC_instance_throne_of_the_four_winds()
{
    new instance_throne_of_the_four_winds();
}
