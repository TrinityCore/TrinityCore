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
#include "throne_of_the_tides.h"
#include "InstanceScript.h"

ObjectData const creatureData[] =
{
    { NPC_LADY_NAZJAR,          BOSS_LADY_NAZJAR        },
    { NPC_COMMANDER_ULTHOK,     BOSS_COMMANDER_ULTHOK   },
    { NPC_MINDBENDER_GURSHA,    BOSS_MINDBENDER_GURSHA  },
    { NPC_OZUMAT,               DATA_OZUMAT             },
    { 0,                        0                       } // END
};

DungeonEncounterData const encounters[] =
{
    { BOSS_LADY_NAZJAR,         {{ 1045 }}  },
    { BOSS_COMMANDER_ULTHOK,    {{ 1044 }}  },
    { BOSS_MINDBENDER_GURSHA,   {{ 1046 }}  },
    { BOSS_OZUMAT,              {{ 1047 }}  }
};

class instance_throne_of_the_tides : public InstanceMapScript
{
public:
    instance_throne_of_the_tides() : InstanceMapScript(TotTScriptName, 643) { }

    struct instance_throne_of_the_tides_InstanceMapScript : public InstanceScript
    {
        instance_throne_of_the_tides_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, nullptr);
            LoadDungeonEncounterData(encounters);
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_throne_of_the_tides_InstanceMapScript(map);
    }
};

void AddSC_instance_throne_of_the_tides()
{
    new instance_throne_of_the_tides();
}
