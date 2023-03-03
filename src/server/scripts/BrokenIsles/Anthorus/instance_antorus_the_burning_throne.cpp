/*
 * This file is part of the AshamaneCore Project. See AUTHORS file for Copyright information
 * Copyright (C) 2018+ MagicStormProject <https://github.com/MagicStormTeam>
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

#include "Creature.h"
#include "GameObject.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "antorus_the_burning_throne.h"


ObjectData const creatureData[] =
{
    { BOSS_GAROTHI_WORLDBREAKER,    DATA_GAROTHI_WORLDBREAKER   },
    { NPC_DECIMATOR,                DATA_DECIMATOR              },
    { NPC_ANNIHILATOR,              DATA_ANNIHILATOR            },
    { 0,                            0                           }  // END
};

DoorData const doorData[] =
{
    { GO_COLLISION,     DATA_GAROTHI_WORLDBREAKER,    DOOR_TYPE_PASSAGE },
    { GO_ROCK,          DATA_GAROTHI_WORLDBREAKER,    DOOR_TYPE_PASSAGE },
    { GO_BOSS6_1,       DATA_IMONAR_THE_SOULHUNTER,   DOOR_TYPE_PASSAGE },
    { GO_BOSS6_2,       DATA_IMONAR_THE_SOULHUNTER,   DOOR_TYPE_PASSAGE },
    { GO_BOSS7_1,       DATA_KINGAROTH,               DOOR_TYPE_PASSAGE },
    { GO_BOSS9_1,       DATA_NOURA_MOTHER_OF_FLAMES,  DOOR_TYPE_ROOM },
    { GO_BOSS9_2,       DATA_NOURA_MOTHER_OF_FLAMES,  DOOR_TYPE_PASSAGE },
    { GO_BOSS_VARIMATHRAS,       DATA_VARIMATHRAS,  DOOR_TYPE_ROOM },
    { GO_DOOR_PORTAL_KEEPER_HASABEL,       DATA_PORTAL_KEEPER_HASABEL,  DOOR_TYPE_ROOM },
    { GO_BOSS10,        DATA_AGGRAMAR,                DOOR_TYPE_ROOM },
};

class instance_antorus_the_burning_throne: public InstanceMapScript
{
    public:
        instance_antorus_the_burning_throne() : InstanceMapScript(ABTScriptName, 757) { }

        struct instance_antorus_the_burning_throne_InstanceMapScript: public InstanceScript
        {
            instance_antorus_the_burning_throne_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, nullptr);
                LoadDoorData(doorData);
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

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_antorus_the_burning_throne_InstanceMapScript(map);
        }
};

void AddSC_instance_antorus_the_burning_throne()
{
    new instance_antorus_the_burning_throne();
}
