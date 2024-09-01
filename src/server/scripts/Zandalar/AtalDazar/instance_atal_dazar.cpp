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
#include "atal_dazar.h"

BossBoundaryData const boundaries =
{
    { DATA_REZAN, new ZRangeBoundary(639.0f, 650.0f) }, // 647.65f
};

ObjectData const creatureData[] =
{
    { BOSS_PRIESTESS_ALUNZA, DATA_PRIESTESS_ALUNZA  },
    { BOSS_VOLKAAL,          DATA_VOLKAAL           },
    { BOSS_REZAN,            DATA_REZAN             },
    { BOSS_YAZMA,            DATA_YAZMA             },
    { 0,                     0                      }  // END
};

DungeonEncounterData const encounters[] =
{
    { DATA_PRIESTESS_ALUNZA, {{ 2084 }} },
    { DATA_VOLKAAL,          {{ 2085 }} },
    { DATA_REZAN,            {{ 2086 }} },
    { DATA_YAZMA,            {{ 2087 }} }
};

class instance_atal_dazar : public InstanceMapScript
{
public:
    instance_atal_dazar() : InstanceMapScript(AtalDazarScriptName, 1763) { }

    struct instance_atal_dazar_InstanceMapScript : public InstanceScript
    {
        instance_atal_dazar_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, nullptr);
            LoadBossBoundaries(boundaries);
            LoadDungeonEncounterData(encounters);
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_atal_dazar_InstanceMapScript(map);
    }
};

void AddSC_instance_atal_dazar()
{
    new instance_atal_dazar();
}
