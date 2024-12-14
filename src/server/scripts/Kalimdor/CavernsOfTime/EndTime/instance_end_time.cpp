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
#include "end_time.h"
#include "InstanceScript.h"

ObjectData const creatureData[] =
{
    { NPC_MUROZOND, BOSS_MUROZOND },
    { 0,            0             } // END
};

DungeonEncounterData const encounters[] =
{
    { BOSS_ECHO_OF_BAINE,       {{ 1881 }}  },
    { BOSS_ECHO_OF_SYLVANAS,    {{ 1882 }}  },
    { BOSS_ECHO_OF_JAINA,       {{ 1883 }}  },
    { BOSS_ECHO_OF_TYRANDE,     {{ 1884 }}  },
    { BOSS_MUROZOND,            {{ 1271 }}  }
};

class instance_end_time : public InstanceMapScript
{
public:
    instance_end_time() : InstanceMapScript(ETScriptName, 938) { }

    struct instance_end_time_InstanceMapScript : public InstanceScript
    {
        instance_end_time_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, nullptr);
            LoadDungeonEncounterData(encounters);
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_end_time_InstanceMapScript(map);
    }
};

void AddSC_instance_end_time()
{
    new instance_end_time();
}
