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
#include "InstanceScript.h"
#include "Map.h"
#include "uldaman.h"

DoorData const doorData[] =
{
    { GO_TEMPLE_DOOR_TO_KEEPERS,    DATA_STONE_KEEPERS,  DOOR_TYPE_ROOM    },
    { GO_TEMPLE_DOOR_TO_ARCHAEDAS,  DATA_STONE_KEEPERS,  DOOR_TYPE_PASSAGE },
    { GO_TEMPLE_DOOR_ARCHAEDAS,     DATA_ARCHAEDAS,      DOOR_TYPE_ROOM    },
    { GO_ANCIENT_VAULT_DOOR,        DATA_ARCHAEDAS,      DOOR_TYPE_PASSAGE },
    { 0,                            0,                   DOOR_TYPE_ROOM    } // END
};

ObjectData const creatureData[] =
{
    { NPC_ARCHAEDAS,                DATA_ARCHAEDAS                },
    { 0,                            0                             } // END
};

ObjectData const gameObjectData[] =
{
    { GO_IRONAYA_SEAL_DOOR,         DATA_IRONAYA_SEAL_DOOR        },
    { 0,                            0                             } // END
};

class instance_uldaman : public InstanceMapScript
{
    public:
        instance_uldaman() : InstanceMapScript(UldamanScriptName, 70) { }

        struct instance_uldaman_InstanceMapScript : public InstanceScript
        {
            instance_uldaman_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, gameObjectData);
                LoadDoorData(doorData);

                IronayaIntroState = 0;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case NPC_STONE_KEEPER:
                    {
                        if (creature->HasStringId("StoneKeeper1"))
                            StoneKeeperGuid[0] = creature->GetGUID();

                        if (creature->HasStringId("StoneKeeper2"))
                            StoneKeeperGuid[1] = creature->GetGUID();

                        if (creature->HasStringId("StoneKeeper3"))
                            StoneKeeperGuid[2] = creature->GetGUID();

                        if (creature->HasStringId("StoneKeeper4"))
                            StoneKeeperGuid[3] = creature->GetGUID();
                        break;
                    }
                    case NPC_EARTHEN_GUARDIAN:
                    case NPC_EARTHEN_HALLSHAPER:
                    case NPC_EARTHEN_CUSTODIAN:
                    case NPC_VAULT_WARDER:
                        ArchaedasMinionsGuidSet.insert(creature->GetGUID());
                        break;
                    default:
                        break;
                }
            }

            void OnCreatureRemove(Creature* creature) override
            {
                InstanceScript::OnCreatureRemove(creature);

                switch (creature->GetEntry())
                {
                    case NPC_EARTHEN_GUARDIAN:
                    case NPC_EARTHEN_HALLSHAPER:
                    case NPC_EARTHEN_CUSTODIAN:
                    case NPC_VAULT_WARDER:
                        ArchaedasMinionsGuidSet.erase(creature->GetGUID());
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                switch (go->GetEntry())
                {
                    case GO_IRONAYA_SEAL_DOOR:
                        if (GetData(DATA_IRONAYA_INTRO) == DONE)
                            HandleGameObject(ObjectGuid::Empty, true, go);
                        break;
                    case GO_KEYSTONE:
                        if (GetData(DATA_IRONAYA_INTRO) == DONE)
                        {
                            HandleGameObject(ObjectGuid::Empty, true, go);
                            go->SetFlag(GO_FLAG_INTERACT_COND);
                        }
                        break;
                    default:
                        break;
                }
            }

            void OnUnitDeath(Unit* unit) override
            {
                InstanceScript::OnUnitDeath(unit);

                Creature* creature = unit->ToCreature();
                if (!creature)
                    return;

                switch (creature->GetEntry())
                {
                    case NPC_STONE_KEEPER:
                    {
                        if (creature->GetGUID() == StoneKeeperGuid[0])
                            if (Creature* keeper = instance->GetCreature(StoneKeeperGuid[1]))
                                keeper->AI()->DoAction(ACTION_KEEPER_ACTIVATED);

                        if (creature->GetGUID() == StoneKeeperGuid[1])
                            if (Creature* keeper = instance->GetCreature(StoneKeeperGuid[2]))
                                keeper->AI()->DoAction(ACTION_KEEPER_ACTIVATED);

                        if (creature->GetGUID() == StoneKeeperGuid[2])
                            if (Creature* keeper = instance->GetCreature(StoneKeeperGuid[3]))
                                keeper->AI()->DoAction(ACTION_KEEPER_ACTIVATED);

                        if (creature->GetGUID() == StoneKeeperGuid[3])
                            SetBossState(DATA_STONE_KEEPERS, DONE);
                        break;
                    }
                    default:
                        break;
                }
            }

            bool SetBossState(uint32 bossId, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(bossId, state))
                    return false;

                switch (bossId)
                {
                    case DATA_ARCHAEDAS:
                        if (state == FAIL)
                        {
                            for (ObjectGuid guid : ArchaedasMinionsGuidSet)
                                if (Creature* minion = instance->GetCreature(guid))
                                {
                                    if (minion->isDead())
                                        minion->Respawn();
                                }
                        }
                        break;
                    case DATA_STONE_KEEPERS:
                        if (state == FAIL)
                        {
                            if (Creature* keeper = instance->GetCreature(StoneKeeperGuid[0]))
                            {
                                if (!keeper->IsAlive())
                                {
                                    StoneKeeperGuid[0].Clear();
                                    keeper->Respawn();
                                }
                            }
                            if (Creature* keeper = instance->GetCreature(StoneKeeperGuid[1]))
                            {
                                if (!keeper->IsAlive())
                                {
                                    StoneKeeperGuid[1].Clear();
                                    keeper->Respawn();
                                }
                            }
                            if (Creature* keeper = instance->GetCreature(StoneKeeperGuid[2]))
                            {
                                if (!keeper->IsAlive())
                                {
                                    StoneKeeperGuid[2].Clear();
                                    keeper->Respawn();
                                }
                            }

                            SetBossState(DATA_STONE_KEEPERS, NOT_STARTED);
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
                    case DATA_IRONAYA_INTRO:
                        IronayaIntroState = data;
                        switch (data)
                        {
                            case IN_PROGRESS:
                                instance->SpawnGroupSpawn(SPAWN_GROUP_IRONAYA);
                                break;
                            case DONE:
                                HandleGameObject(ObjectGuid::Empty, true, GetGameObject(DATA_IRONAYA_SEAL_DOOR));
                                SaveToDB();
                                break;
                            default:
                                break;
                        }
                        break;
                }
            }

            void ProcessEvent(WorldObject* /*gameObject*/, uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_SUB_BOSS_AGGRO:
                        if (Creature* keeper = instance->GetCreature(StoneKeeperGuid[0]))
                            keeper->AI()->DoAction(ACTION_KEEPER_ACTIVATED);
                        break;
                    case EVENT_BOSS_AGGRO:
                        if (Creature* archaedas = GetCreature(DATA_ARCHAEDAS))
                            archaedas->AI()->DoAction(ACTION_ARCHAEDAS_AWAKEN);
                        break;
                    default:
                        break;
                }
            }

            void WriteSaveDataMore(std::ostringstream& stream) override
            {
                stream << IronayaIntroState;
            }

            void ReadSaveDataMore(std::istringstream& stream) override
            {
                stream >> IronayaIntroState;
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_IRONAYA_INTRO:
                        return IronayaIntroState;
                }
                return 0;
            }

        protected:
            ObjectGuid StoneKeeperGuid[4] = { };
            GuidSet ArchaedasMinionsGuidSet;
            uint32 IronayaIntroState;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_uldaman_InstanceMapScript(map);
        }
};

void AddSC_instance_uldaman()
{
    new instance_uldaman();
}
