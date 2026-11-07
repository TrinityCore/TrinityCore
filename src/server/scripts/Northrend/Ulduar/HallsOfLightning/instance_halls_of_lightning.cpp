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
#include "CreatureAI.h"
#include "GameObject.h"
#include "halls_of_lightning.h"
#include "InstanceScript.h"

static constexpr DoorData doorData[] =
{
    { GO_VOLKHAN_DOOR, BOSS_VOLKHAN, EncounterDoorBehavior::OpenWhenDone },
    { GO_IONAR_DOOR,   BOSS_IONAR,   EncounterDoorBehavior::OpenWhenDone },
    { GO_LOKEN_DOOR,   BOSS_LOKEN,   EncounterDoorBehavior::OpenWhenDone },
};

static constexpr ObjectData creatureData[] =
{
    { NPC_GENERAL_BJARNGRIM,    BOSS_GENERAL_BJARNGRIM  },
    { NPC_VOLKHAN,              BOSS_VOLKHAN            },
    { NPC_IONAR,                BOSS_IONAR              },
    { NPC_LOKEN,                BOSS_LOKEN              },
    { NPC_INVISIBLE_STALKER,    DATA_INVISIBLE_STALKER  },
    { NPC_VOLKHANS_ANVIL,       DATA_VOLKHANS_ANVIL     },
};

static constexpr ObjectData gameObjectData[] =
{
    { GO_VOLKHAN_TEMPER_VISUAL, DATA_VOLKHAN_TEMPER_VISUAL },
    { GO_LOKEN_THRONE,          DATA_LOKEN_GLOBE           },
};

static constexpr DungeonEncounterData encounters[] =
{
    { BOSS_GENERAL_BJARNGRIM, {{ 1987 }} },
    { BOSS_VOLKHAN, {{ 1985 }} },
    { BOSS_IONAR, {{ 1984 }} },
    { BOSS_LOKEN, {{ 1986 }} }
};

class instance_halls_of_lightning : public InstanceMapScript
{
    public:
        instance_halls_of_lightning() : InstanceMapScript(HoLScriptName, 602) { }

        struct instance_halls_of_lightning_InstanceMapScript : public InstanceScript
        {
            instance_halls_of_lightning_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, gameObjectData);
                LoadDoorData(doorData);
                LoadDungeonEncounterData(encounters);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case NPC_MOLTEN_GOLEM:
                        if (GetBossState(BOSS_VOLKHAN) == IN_PROGRESS)
                        {
                            if (Creature* volkhan = GetCreature(BOSS_VOLKHAN))
                                if (CreatureAI* ai = volkhan->AI())
                                    ai->JustSummoned(creature);
                        }
                        else // These golems are summoned via trigger missile so we have to clean them up if they spawned during a wipe/completion
                            creature->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case BOSS_LOKEN:
                        if (state == DONE)
                            if (GameObject* globe = GetGameObject(DATA_LOKEN_GLOBE))
                                globe->SendCustomAnim(0);
                        break;
                    default:
                        break;
                }

                return true;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_halls_of_lightning_InstanceMapScript(map);
        }
};

void AddSC_instance_halls_of_lightning()
{
    new instance_halls_of_lightning();
}
