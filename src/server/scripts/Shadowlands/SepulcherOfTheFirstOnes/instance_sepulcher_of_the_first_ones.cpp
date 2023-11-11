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
#include "Creature.h"
#include "CreatureAI.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptMgr.h"
#include "sepulcher_of_the_first_ones.h"

ObjectData const creatureData[] =
{
    // Anduin Wrynn
    { BOSS_ANDUIN_WRYNN,                        DATA_ANDUIN_WRYNN                   },
    { BOSS_REMNANT_OF_A_FALLEN_KING,            DATA_REMNANT_OF_A_FALLEN_KING       },
    { NPC_UTHER_THE_LIGHTBRINGER_ANDUIN,        DATA_UTHER_THE_LIGHTBRINGER_ANDUIN  },
    { NPC_LADY_JAINA_PROUDMOORE_ANDUIN,         DATA_JAINA_PROUDMOORE_ANDUIN        },
    { NPC_SYLVANAS_WINDRUNNER_ANDUIN,           DATA_SYLVANAS_WINDRUNNER_ANDUIN     },
    { NPC_THRALL_ANDUIN,                        DATA_THRALL_ANDUIN                  },
    { NPC_FIRIM_ANDUIN,                         DATA_FIRIM_ANDUIN                   },
    { NPC_ANDUIN_SOUL,                          DATA_ANDUIN_SOUL                    },
    { NPC_BEACON_OF_HOPE,                       DATA_BEACON_OF_HOPE                 },
    { NPC_QUARTERMASTER_RAHM_ANDUIN,            DATA_QUARTERMASTER_RAHM_ANDUIN      },
    { NPC_BOLVAR_FORDRAGON_ANDUIN,              DATA_BOLVAR_FORDRAGON_ANDUIN        },
    { 0,                                        0                                   }
};

BossBoundaryData const boundaries =
{
    { DATA_ANDUIN_WRYNN,                        new CircleBoundary({ -3825.0601f, -2715.4600f }, 45.0)},
};

DoorData const doorData[] =
{
    { GAMEOBJECT_BRIDGE_TO_ANDUIN,              DATA_ANDUIN_WRYNN,          EncounterDoorBehavior::OpenWhenInProgress },
    { GAMEOBJECT_BRIDGE_AFTER_ANDUIN,           DATA_ANDUIN_WRYNN,          EncounterDoorBehavior::OpenWhenNotDone },
    { 0,                                        0,                          EncounterDoorBehavior::OpenWhenInProgress }
};

DungeonEncounterData const encounters[] =
{
    { DATA_ANDUIN_WRYNN, {{ 2546 }} },
};

class instance_sepulcher_of_the_first_ones : public InstanceMapScript
{
public:
    instance_sepulcher_of_the_first_ones() : InstanceMapScript(SFOScriptName, 2481) { }

    struct instance_sepulcher_of_the_first_ones_InstanceMapScript : public InstanceScript
    {
        instance_sepulcher_of_the_first_ones_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadDungeonEncounterData(encounters);
            LoadBossBoundaries(boundaries);
            LoadObjectData(creatureData, nullptr);
            LoadDoorData(doorData);

            AnduinIntroductionState = NOT_STARTED;
        }

        bool SetBossState(uint32 id, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(id, state))
                return false;

            switch (id)
            {
                case DATA_ANDUIN_WRYNN:
                {
                    if (state == NOT_STARTED)
                        DoUpdateWorldState(WORLD_STATE_ANDUIN_ENCOUNTER_STARTED, 0);
                    else if (state == IN_PROGRESS)
                    {
                        Creature* anduin = GetCreature(DATA_ANDUIN_WRYNN);
                        if (!anduin)
                            return false;

                        DoUpdateWorldState(WORLD_STATE_ANDUIN_ENCOUNTER_STARTED, 1);

                        // @TODO: uther, sylvanas and jaina should attack anduin but keep faction 35; we lack core support
                        if (Creature* uther = GetCreature(DATA_UTHER_THE_LIGHTBRINGER_ANDUIN))
                            uther->AI()->AttackStart(anduin);

                        for (uint32 data : { DATA_SYLVANAS_WINDRUNNER_ANDUIN, DATA_JAINA_PROUDMOORE_ANDUIN })
                        {
                            if (Creature* creature = GetCreature(data))
                                creature->AI()->AttackStartCaster(anduin, 25.0f);
                        }
                    }
                    break;
                }
                default:
                    break;
            }
            return true;
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case DATA_ANDUIN_WRYNN_INTRODUCTION:
                {
                    AnduinIntroductionState = data;
                    break;
                }
                default:
                    break;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_ANDUIN_WRYNN_INTRODUCTION:
                    return AnduinIntroductionState;
                default:
                    break;
            }

            return 0;
        }

    protected:
        uint8 AnduinIntroductionState;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_sepulcher_of_the_first_ones_InstanceMapScript(map);
    }
};

void AddSC_instance_sepulcher_of_the_first_ones()
{
    new instance_sepulcher_of_the_first_ones();
}
