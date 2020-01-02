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
#include "AreaBoundary.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ruby_sanctum.h"
#include "TemporarySummon.h"
#include "WorldStatePackets.h"

Position const HalionControllerSpawnPos = { 3156.037f, 533.2656f, 72.97205f, 0.0f };

BossBoundaryData const boundaries =
{
    { DATA_GENERAL_ZARITHRIAN, new EllipseBoundary(Position(3013.409f, 529.492f), 45.0, 100.0) },
    { DATA_HALION,             new CircleBoundary(Position(3156.037f, 533.2656f), 48.5)        }
};

DoorData const doorData[] =
{
    { GO_FIRE_FIELD,          DATA_BALTHARUS_THE_WARBORN, DOOR_TYPE_PASSAGE },
    { GO_FLAME_WALLS,         DATA_BALTHARUS_THE_WARBORN, DOOR_TYPE_PASSAGE },
    { GO_FLAME_WALLS,         DATA_SAVIANA_RAGEFIRE,      DOOR_TYPE_PASSAGE },
    { GO_FLAME_WALLS,         DATA_GENERAL_ZARITHRIAN,    DOOR_TYPE_ROOM    },
    { GO_FLAME_RING,          DATA_HALION,                DOOR_TYPE_ROOM    },
    { GO_TWILIGHT_FLAME_RING, DATA_HALION,                DOOR_TYPE_ROOM    },
    { 0,                      0,                          DOOR_TYPE_ROOM    } // END
};

ObjectData const creatureData[] =
{
    { NPC_BALTHARUS_THE_WARBORN,             DATA_BALTHARUS_THE_WARBORN  },
    { NPC_BALTHARUS_THE_WARBORN_CLONE,       DATA_BALTHARUS_CLONE        },
    { NPC_BALTHARUS_TARGET,                  DATA_CRYSTAL_CHANNEL_TARGET },
    { NPC_GENERAL_ZARITHRIAN,                DATA_GENERAL_ZARITHRIAN     },
    { NPC_SAVIANA_RAGEFIRE,                  DATA_SAVIANA_RAGEFIRE       },
    { NPC_HALION,                            DATA_HALION                 },
    { NPC_TWILIGHT_HALION,                   DATA_TWILIGHT_HALION        },
    { NPC_HALION_CONTROLLER,                 DATA_HALION_CONTROLLER      },
    { NPC_ORB_CARRIER,                       DATA_ORB_CARRIER            },
    { NPC_ORB_ROTATION_FOCUS,                DATA_ORB_ROTATION_FOCUS     },
    { NPC_XERESTRASZA,                       DATA_XERESTRASZA            },
    { 0,                                     0                           } // END
};

ObjectData const gameObjectData[] =
{
    { GO_FLAME_WALLS,           DATA_FLAME_WALLS            },
    { GO_BURNING_TREE_1,        DATA_BURNING_TREE_1         },
    { GO_BURNING_TREE_2,        DATA_BURNING_TREE_2         },
    { GO_BURNING_TREE_3,        DATA_BURNING_TREE_3         },
    { GO_BURNING_TREE_4,        DATA_BURNING_TREE_4         },
    { GO_FLAME_RING,            DATA_FLAME_RING             },
    { GO_TWILIGHT_FLAME_RING,   DATA_TWILIGHT_FLAME_RING    },
    { 0,                        0                           } //END
};


class instance_ruby_sanctum : public InstanceMapScript
{
    public:
        instance_ruby_sanctum() : InstanceMapScript(RSScriptName, 724) { }

        struct instance_ruby_sanctum_InstanceMapScript : public InstanceScript
        {
            instance_ruby_sanctum_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadBossBoundaries(boundaries);
                LoadDoorData(doorData);
                LoadObjectData(creatureData, gameObjectData);
                BaltharusSharedHealth = 0;
            }

            void OnPlayerEnter(Player* /*player*/) override
            {
                if (!GetGuidData(DATA_HALION) && GetBossState(DATA_HALION) != DONE && GetBossState(DATA_GENERAL_ZARITHRIAN) == DONE)
                {
                    instance->LoadGrid(HalionControllerSpawnPos.GetPositionX(), HalionControllerSpawnPos.GetPositionY());
                    if (Creature* halionController = instance->GetCreature(GetGuidData(DATA_HALION_CONTROLLER)))
                        halionController->AI()->DoAction(ACTION_INTRO_HALION_2);
                }
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                if (creature->GetEntry() == NPC_ZARITHRIAN_SPAWN_STALKER)
                {
                    if (!ZarithrianSpawnStalkerGUID[0])
                        ZarithrianSpawnStalkerGUID[0] = creature->GetGUID();
                    else
                        ZarithrianSpawnStalkerGUID[1] = creature->GetGUID();
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                switch (go->GetEntry())
                {
                    case GO_BURNING_TREE_1:
                    case GO_BURNING_TREE_2:
                    case GO_BURNING_TREE_3:
                    case GO_BURNING_TREE_4:
                        if (GetBossState(DATA_GENERAL_ZARITHRIAN) == DONE)
                            HandleGameObject(ObjectGuid::Empty, true, go);
                        break;
                    default:
                        break;
                }
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_ZARITHRIAN_SPAWN_STALKER_1:
                    case DATA_ZARITHRIAN_SPAWN_STALKER_2:
                        return ZarithrianSpawnStalkerGUID[type - DATA_ZARITHRIAN_SPAWN_STALKER_1];
                    default:
                        return InstanceScript::GetGuidData(type);
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_BALTHARUS_THE_WARBORN:
                    case DATA_SAVIANA_RAGEFIRE:
                        if (state == DONE)
                            CheckGeneral();
                        break;
                    case DATA_GENERAL_ZARITHRIAN:
                        if (state == DONE && GetBossState(DATA_HALION) != DONE)
                            if (Creature* halionController = GetCreature(DATA_HALION_CONTROLLER))
                                halionController->AI()->DoAction(ACTION_INTRO_HALION);
                        break;
                    case DATA_HALION:
                        DoUpdateWorldState(WORLDSTATE_CORPOREALITY_TOGGLE, 0);
                        DoUpdateWorldState(WORLDSTATE_CORPOREALITY_TWILIGHT, 0);
                        DoUpdateWorldState(WORLDSTATE_CORPOREALITY_MATERIAL, 0);
                        break;
                    default:
                        break;
                }

                return true;
            }

            void CheckGeneral()
            {
                if (GetBossState(DATA_SAVIANA_RAGEFIRE) == DONE && GetBossState(DATA_BALTHARUS_THE_WARBORN) == DONE)
                    if (Creature* zarithrian = GetCreature(DATA_GENERAL_ZARITHRIAN))
                        zarithrian->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE));
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type != DATA_BALTHARUS_SHARED_HEALTH)
                    return;

                BaltharusSharedHealth = data;
            }

            uint32 GetData(uint32 type) const override
            {
                if (type != DATA_BALTHARUS_SHARED_HEALTH)
                    return 0;

                return BaltharusSharedHealth;
            }

            void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override
            {
                packet.Worldstates.emplace_back(uint32(WORLDSTATE_CORPOREALITY_MATERIAL), 50);
                packet.Worldstates.emplace_back(uint32(WORLDSTATE_CORPOREALITY_TWILIGHT), 50);
                packet.Worldstates.emplace_back(uint32(WORLDSTATE_CORPOREALITY_TOGGLE), 0);
            }

        protected:
            ObjectGuid ZarithrianSpawnStalkerGUID[2];
            uint32 BaltharusSharedHealth;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_ruby_sanctum_InstanceMapScript(map);
        }
};

void AddSC_instance_ruby_sanctum()
{
    new instance_ruby_sanctum();
}
