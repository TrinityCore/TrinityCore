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
#include "antorus_the_burning_throne.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "InstanceScript.h"
#include "Map.h"

ObjectData const creatureData[] =
{
    { BOSS_GAROTHI_WORLDBREAKER,    DATA_GAROTHI_WORLDBREAKER   },
    { NPC_DECIMATOR,                DATA_DECIMATOR              },
    { NPC_ANNIHILATOR,              DATA_ANNIHILATOR            },
    { 0,                            0                           }  // END
};

DoorData const doorData[] =
{
    { GO_COLLISION,                 DATA_GAROTHI_WORLDBREAKER,  DOOR_TYPE_PASSAGE },
    { GO_ROCK,                      DATA_GAROTHI_WORLDBREAKER,  DOOR_TYPE_PASSAGE },
    { 0,                            0,                          DOOR_TYPE_ROOM }  // END
};

DungeonEncounterData const encounters[] =
{
    { DATA_GAROTHI_WORLDBREAKER, {{ 2076 }} },
    { DATA_FELHOUNDS_OF_SAGERAS, {{ 2074 }} },
    { DATA_ANTORAN_HIGH_COMMAND, {{ 2070 }} },
    { DATA_PORTAL_KEEPER_HASABEL, {{ 2064 }} },
    { DATA_EONAR_THE_LIFE_BINDER, {{ 2075 }} },
    { DATA_IMONAR_THE_SOULHUNTER, {{ 2082 }} },
    { DATA_KINGAROTH, {{ 2088 }} },
    { DATA_VARIMATHRAS, {{ 2069 }} },
    { DATA_THE_COVEN_OF_SHIVARRA, {{ 2073 }} },
    { DATA_AGGRAMAR, {{ 2063 }} },
    { DATA_ARGUS_THE_UNMAKER, {{ 2092 }} }
};

class instance_antorus_the_burning_throne : public InstanceMapScript
{
    public:
        instance_antorus_the_burning_throne() : InstanceMapScript(ABTScriptName, 1712) { }

        struct instance_antorus_the_burning_throne_InstanceMapScript: public InstanceScript
        {
            instance_antorus_the_burning_throne_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, nullptr);
                LoadDoorData(doorData);
                LoadDungeonEncounterData(encounters);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case NPC_ANNIHILATION:
                        if (Creature* garothi = GetCreature(DATA_GAROTHI_WORLDBREAKER))
                            garothi->AI()->JustSummoned(creature);
                        break;
                    default:
                        break;
                }
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_antorus_the_burning_throne_InstanceMapScript(map);
        }
};

void AddSC_instance_antorus_the_burning_throne()
{
    new instance_antorus_the_burning_throne();
}
