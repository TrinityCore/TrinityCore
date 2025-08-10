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

ObjectData const creatureData[] =
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
    { 0,                            0,                     }
};

DungeonEncounterData const encounters[] =
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
            counter = DATA_FLAMECALLER_000;
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, nullptr);
            LoadDungeonEncounterData(encounters);
        }

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            if (creature->GetEntry() == NPC_EARTHEN_RING_FLAMECALLER)
            {
                switch (counter)
                {
                    case DATA_FLAMECALLER_000:
                        FlameCallerGUIDs[0] = creature->GetGUID();
                        break;
                    case DATA_FLAMECALLER_001:
                        FlameCallerGUIDs[1] = creature->GetGUID();
                        break;
                    case DATA_FLAMECALLER_002:
                        FlameCallerGUIDs[2] = creature->GetGUID();
                        break;
                    default:
                        break;
                }
                ++counter;
            }
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_FLAMECALLER_000:
                    return FlameCallerGUIDs[0];
                case DATA_FLAMECALLER_001:
                    return FlameCallerGUIDs[1];
                case DATA_FLAMECALLER_002:
                    return FlameCallerGUIDs[2];
                default:
                    break;
            }
            return ObjectGuid::Empty;
        }

    protected:
        ObjectGuid FlameCallerGUIDs[3];
        uint8 counter;
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
