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
#include "Creature.h"
#include "InstanceScript.h"
#include "the_slave_pens.h"

static constexpr ObjectData creatureData[] =
{
    { NPC_AHUNE,                    DATA_AHUNE             },
    { NPC_FROZEN_CORE,              DATA_FROZEN_CORE       },
    { NPC_AHUNE_LOC_BUNNY,          DATA_AHUNE_BUNNY       },
    { NPC_SHAMAN_BONFIRE_BUNNY_000, DATA_BONFIRE_BUNNY_000 },
    { NPC_SHAMAN_BONFIRE_BUNNY_001, DATA_BONFIRE_BUNNY_001 },
    { NPC_SHAMAN_BONFIRE_BUNNY_002, DATA_BONFIRE_BUNNY_002 },
    { NPC_SHAMAN_BEAM_BUNNY_000,    DATA_BEAM_BUNNY_000    },
    { NPC_SHAMAN_BEAM_BUNNY_001,    DATA_BEAM_BUNNY_001    },
    { NPC_SHAMAN_BEAM_BUNNY_002,    DATA_BEAM_BUNNY_002    },
    { NPC_LUMA_SKYMOTHER,           DATA_LUMA_SKYMOTHER    },
};

static constexpr DungeonEncounterData encounters[] =
{
    { DATA_MENNU_THE_BETRAYER, {{ 1939 }} },
    { DATA_ROKMAR_THE_CRACKLER, {{ 1941 }} },
    { DATA_QUAGMIRRAN, {{ 1940 }} }
};

class instance_the_slave_pens : public InstanceMapScript
{
public:
    instance_the_slave_pens() : InstanceMapScript(SPScriptName, 547) { }

    struct instance_the_slave_pens_InstanceMapScript : public InstanceScript
    {
        instance_the_slave_pens_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, {});
            LoadDungeonEncounterData(encounters);
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_the_slave_pens_InstanceMapScript(map);
    }
};

void AddSC_instance_the_slave_pens()
{
    new instance_the_slave_pens();
}
