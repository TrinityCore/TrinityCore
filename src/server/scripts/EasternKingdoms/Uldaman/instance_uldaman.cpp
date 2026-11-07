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
#include <algorithm>

static constexpr DoorData doorData[] =
{
    { GO_TEMPLE_DOOR_TO_KEEPERS,    DATA_STONE_KEEPERS,  EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_TEMPLE_DOOR_TO_ARCHAEDAS,  DATA_STONE_KEEPERS,  EncounterDoorBehavior::OpenWhenDone          },
    { GO_TEMPLE_DOOR_ARCHAEDAS,     DATA_ARCHAEDAS,      EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_ANCIENT_VAULT_DOOR,        DATA_ARCHAEDAS,      EncounterDoorBehavior::OpenWhenDone          }
};

static constexpr ObjectData creatureData[] =
{
    { NPC_ARCHAEDAS,                DATA_ARCHAEDAS                }
};

static constexpr ObjectData gameObjectData[] =
{
    { GO_IRONAYA_SEAL_DOOR,         DATA_IRONAYA_SEAL_DOOR        }
};

static constexpr DungeonEncounterData Encounters[] =
{
    { DATA_REVELOSH, { { 547 } } },
    { DATA_THE_LOST_DWARVES, { { 548 } } },
    { DATA_IRONAYA, { { 549 } } },
    { DATA_ANCIENT_STONE_KEEPER, { { 551 } } },
    { DATA_GALGANN_FIREHAMMER, { { 552 } } },
    { DATA_GRIMLOK, { { 553 } } },
    { DATA_ARCHAEDAS, { { 554 } } },
    { DATA_OBSIDIAN_SENTINEL, { { 1887 } } },
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
                LoadDungeonEncounterData(Encounters);

                IronayaIntroState = 0;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case NPC_STONE_KEEPER:
                    {
                        static constexpr std::array<std::string_view, 4> KeeperStringId = {{ "StoneKeeper1", "StoneKeeper2", "StoneKeeper3", "StoneKeeper4" }};
                        auto stringId = std::ranges::find_if(KeeperStringId, [creature](std::string_view stringId) { return creature->HasStringId(stringId); });
                        if (stringId != KeeperStringId.end())
                            StoneKeeperGuid[std::ranges::distance(KeeperStringId.begin(), stringId)] = creature->GetGUID();
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
                    case NPC_REVELOSH: SetBossState(DATA_REVELOSH, DONE); break;
                    //case ?: SetBossState(BOSS_THE_LOST_DWARVES, DONE); break;
                    case NPC_ANCIENT_STONE_KEEPER: SetBossState(DATA_ANCIENT_STONE_KEEPER, DONE); break;
                    case NPC_GALGANN_FIREHAMMER: SetBossState(DATA_GALGANN_FIREHAMMER, DONE); break;
                    case NPC_GRIMLOK: SetBossState(DATA_GRIMLOK, DONE); break;
                    case NPC_OBSIDIAN_SENTINEL: SetBossState(DATA_OBSIDIAN_SENTINEL, DONE); break;
                    case NPC_STONE_KEEPER:
                    {
                        for (std::size_t i = 0; i < StoneKeeperGuid.size() - 1; ++i)
                        {
                            if (creature->GetGUID() == StoneKeeperGuid[i])
                            {
                                if (Creature* keeper = instance->GetCreature(StoneKeeperGuid[i + 1]))
                                {
                                    keeper->AI()->DoAction(ACTION_KEEPER_ACTIVATED);
                                    break;
                                }
                            }
                        }

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
                            for (std::size_t i = 0; i < StoneKeeperGuid.size() - 1; ++i)
                            {
                                if (Creature* keeper = instance->GetCreature(StoneKeeperGuid[i]))
                                {
                                    if (!keeper->IsAlive())
                                    {
                                        StoneKeeperGuid[i].Clear();
                                        keeper->Respawn();
                                    }
                                }
                            }

                            SetBossState(DATA_STONE_KEEPERS, NOT_STARTED);
                        }
                        break;
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
                                break;
                            default:
                                break;
                        }
                        break;
                }
            }

            void ProcessEvent(WorldObject* /*gameObject*/, uint32 eventId, WorldObject* /*invoker*/) override
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
            std::array<ObjectGuid, 4> StoneKeeperGuid;
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
