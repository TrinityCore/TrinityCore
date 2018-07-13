/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "Creature.h"
#include "firelands.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"

BossBoundaryData const bounderies =
{
    { DATA_RAGNAROS, new CircleBoundary(Position(1040.0f, -57.0f), 80) },
};

DoorData const doorData[] =
{
    { GO_RAGNAROS_DOOR,         DATA_RAGNAROS,              DOOR_TYPE_ROOM },
    { 0,                        0,                          DOOR_TYPE_ROOM } //END
};

ObjectData const creatureData[] =
{
    { NPC_RAGNAROS,             DATA_RAGNAROS },
    { NPC_SULFURAS,             DATA_SULFURAS },
    { NPC_CENARIUS,             DATA_CENARIUS },
    { NPC_HAMUUL_RUNETOTEM,     DATA_HAMUUL_RUNETOTEM },
    { NPC_MALFURION_STORMRAGE,  DATA_MALFURION_STORMRAGE },
    { NPC_DREADFLAME,           DATA_DREADFLAME },
    { 0, 0 } // END
};

ObjectData const gameObjectData[] =
{
    { GO_RAGNAROS_PLATFORM, DATA_RAGNAROS_PLATFORM },
    { 0, 0 } // END
};

class instance_firelands : public InstanceMapScript
{
    public:
        instance_firelands() : InstanceMapScript(FirelandsScriptName, 720) { }

        struct instance_firelands_InstanceScript : public InstanceScript
        {
            instance_firelands_InstanceScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadBossBoundaries(bounderies);
                LoadDoorData(doorData);
                LoadObjectData(creatureData, gameObjectData);

                _ragnarosFirstEmerge = true;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_SMOULDERING_HATCHLING:
                        // Cannot directly start attacking here as the creature is not yet on map
                        creature->m_Events.AddEvent(new DelayedAttackStartEvent(creature), creature->m_Events.CalculateTime(500));
                        break;
                    case NPC_BALEROC:
                        BalerocGUID = creature->GetGUID();
                        break;
                    case NPC_SULFURAS_SMASH_TRIGGER:
                    case NPC_SULFURAS:
                    case NPC_MOLTEN_ELEMENTAL:
                    case NPC_BLAZING_HEAT:
                        if (Creature* ragnaros = GetCreature(DATA_RAGNAROS))
                            if (ragnaros->IsAIEnabled)
                                ragnaros->AI()->JustSummoned(creature);
                        break;
                    // Ragnaros trash manual linked respawn
                    case NPC_LAVA_WIELDER:
                    case NPC_MOLTEN_SPEWER:
                    case NPC_MOLTEN_ERUPTER:
                        if (GetBossState(DATA_RAGNAROS) != DONE)
                            break;

                        creature->SetRespawnTime(WEEK);
                        creature->DisappearAndDie();
                    default:
                        break;
                }

                InstanceScript::OnCreatureCreate(creature);
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch(go->GetEntry())
                {
                    case GO_BALEROC_FIREWALL:
                        BalerocDoorGUID = go->GetGUID();
                        if (GetBossState(DATA_SHANNOX) == DONE || GetBossState(DATA_BALEROC) == DONE)
                            go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    case GO_RAGNAROS_DOOR:
                        AddDoor(go, true);
                        break;
                    default:
                        break;
                }

                InstanceScript::OnGameObjectCreate(go);
            }

            void OnGameObjectRemove(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                case GO_RAGNAROS_DOOR:
                    AddDoor(go, false);
                    break;
                default:
                    break;
                }

                InstanceScript::OnGameObjectRemove(go);
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_RAGNAROS_FIRST_EMERGE:
                        return _ragnarosFirstEmerge ? 1 : 0;
                    default:
                        break;
                }

                return 0;
            }

            void SetData(uint32 data, uint32 value) override
            {
                switch (data)
                {
                    case DATA_RAGNAROS_EMERGE:
                    {
                        if (GetCreature(DATA_RAGNAROS))
                            break;

                        EncounterState state = GetBossState(DATA_RAGNAROS);
                        if (state != NOT_STARTED && state != TO_BE_DECIDED)
                            break;

                        instance->SummonCreature(NPC_RAGNAROS, RagnarosPosition);
                        break;
                    }
                    case DATA_RAGNAROS_FIRST_EMERGE:
                        _ragnarosFirstEmerge = value == 1;
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
                    case DATA_RAGNAROS:
                        if (state == FAIL)
                            _scheduler.Schedule(Seconds(31), [this](TaskContext)
                            {
                                if (!GetCreature(DATA_RAGNAROS))
                                    instance->SummonCreature(NPC_RAGNAROS, RagnarosPosition);
                            });
                        else if (state == DONE)
                            SendBossKillCredit(1203);
                        break;
                    default:
                        break;
                }

                if ((type == DATA_SHANNOX && state == DONE) || (type == DATA_BALEROC && state != IN_PROGRESS))
                {
                    if (GameObject* door = instance->GetGameObject(BalerocDoorGUID))
                        door->SetGoState(GO_STATE_ACTIVE);
                }
                else if (type == DATA_BALEROC && state == IN_PROGRESS)
                    if (GameObject* door = instance->GetGameObject(BalerocDoorGUID))
                        door->SetGoState(GO_STATE_READY);

                return true;
            }

            void Update(uint32 diff) override
            {
                _scheduler.Update(diff);
                InstanceScript::Update(diff);
            }

        private:
            bool _ragnarosFirstEmerge;
            TaskScheduler _scheduler;

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_BALEROC:
                        return BalerocGUID;
                    default:
                        break;
                }
                return ObjectGuid::Empty;
            }

            protected:
                ObjectGuid BalerocDoorGUID;
                ObjectGuid BalerocGUID;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_firelands_InstanceScript(map);
        }
};

void AddSC_instance_firelands()
{
    new instance_firelands();
}
