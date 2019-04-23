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
#include "Creature.h"
#include "CreatureAI.h"
#include "EventMap.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "oculus.h"
#include "PhasingHandler.h"
#include "TemporarySummon.h"
#include "WorldStatePackets.h"

DoorData const doorData[] =
{
    { GO_DRAGON_CAGE_DOOR,  DATA_DRAKOS,    DOOR_TYPE_PASSAGE },
    { 0,                    0,              DOOR_TYPE_ROOM }
};

Position const VerdisaMove       = { 949.188f, 1032.91f, 359.967f, 1.093027f  };
Position const BelgaristraszMove = { 941.453f, 1044.1f,  359.967f, 0.1984709f };
Position const EternosMove       = { 943.202f, 1059.35f, 359.967f, 5.757278f  };

class instance_oculus : public InstanceMapScript
{
    public:
        instance_oculus() : InstanceMapScript(OculusScriptName, 578) { }

        struct instance_oculus_InstanceMapScript : public InstanceScript
        {
            instance_oculus_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);

                CentrifugueConstructCounter = 0;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_DRAKOS:
                        DrakosGUID = creature->GetGUID();
                        break;
                    case NPC_VAROS:
                        VarosGUID = creature->GetGUID();
                        if (GetBossState(DATA_DRAKOS) != DONE)
                            PhasingHandler::AddPhase(creature, 170, true);
                        else
                            PhasingHandler::RemovePhase(creature, 170, true);
                        break;
                    case NPC_UROM:
                        UromGUID = creature->GetGUID();
                        if (GetBossState(DATA_VAROS) != DONE)
                            PhasingHandler::AddPhase(creature, 170, true);
                        else
                            PhasingHandler::RemovePhase(creature, 170, true);
                        break;
                    case NPC_EREGOS:
                        EregosGUID = creature->GetGUID();
                        if (GetBossState(DATA_UROM) != DONE)
                            PhasingHandler::AddPhase(creature, 170, true);
                        else
                            PhasingHandler::RemovePhase(creature, 170, true);
                        break;
                    case NPC_CENTRIFUGE_CONSTRUCT:
                        if (creature->IsAlive())
                            DoUpdateWorldState(WORLD_STATE_CENTRIFUGE_CONSTRUCT_AMOUNT, ++CentrifugueConstructCounter);
                        break;
                    case NPC_BELGARISTRASZ:
                        BelgaristraszGUID = creature->GetGUID();
                        if (GetBossState(DATA_DRAKOS) == DONE)
                        {
                            creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                            creature->Relocate(BelgaristraszMove);
                        }
                        break;
                    case NPC_ETERNOS:
                        EternosGUID = creature->GetGUID();
                        if (GetBossState(DATA_DRAKOS) == DONE)
                        {
                            creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                            creature->Relocate(EternosMove);
                        }
                        break;
                    case NPC_VERDISA:
                        VerdisaGUID = creature->GetGUID();
                        if (GetBossState(DATA_DRAKOS) == DONE)
                        {
                            creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                            creature->Relocate(VerdisaMove);
                        }
                        break;
                    case NPC_GREATER_WHELP:
                        if (GetBossState(DATA_UROM) == DONE)
                            GreaterWhelpList.push_back(creature->GetGUID());
                        else
                            PhasingHandler::AddPhase(creature, 170, true);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_DRAGON_CAGE_DOOR:
                        AddDoor(go, true);
                        break;
                    case GO_EREGOS_CACHE_N:
                    case GO_EREGOS_CACHE_H:
                        EregosCacheGUID = go->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_DRAGON_CAGE_DOOR:
                        AddDoor(go, false);
                        break;
                    default:
                        break;
                }
            }

            void OnUnitDeath(Unit* unit) override
            {
                Creature* creature = unit->ToCreature();
                if (!creature)
                    return;

                if (creature->GetEntry() == NPC_CENTRIFUGE_CONSTRUCT)
                {
                     DoUpdateWorldState(WORLD_STATE_CENTRIFUGE_CONSTRUCT_AMOUNT, --CentrifugueConstructCounter);

                     if (!CentrifugueConstructCounter)
                        if (Creature* varos = instance->GetCreature(VarosGUID))
                            varos->RemoveAllAuras();
                }
            }

            void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override
            {
                if (GetBossState(DATA_DRAKOS) == DONE && GetBossState(DATA_VAROS) != DONE)
                {
                    packet.Worldstates.emplace_back(uint32(WORLD_STATE_CENTRIFUGE_CONSTRUCT_SHOW), 1);
                    packet.Worldstates.emplace_back(uint32(WORLD_STATE_CENTRIFUGE_CONSTRUCT_AMOUNT), int32(CentrifugueConstructCounter));
                }
                else
                {
                    packet.Worldstates.emplace_back(uint32(WORLD_STATE_CENTRIFUGE_CONSTRUCT_SHOW), 0);
                    packet.Worldstates.emplace_back(uint32(WORLD_STATE_CENTRIFUGE_CONSTRUCT_AMOUNT), 0);
                }
            }

            void ProcessEvent(WorldObject* /*unit*/, uint32 eventId) override
            {
                if (eventId != EVENT_CALL_DRAGON)
                    return;

                if (Creature* varos = instance->GetCreature(VarosGUID))
                    if (Creature* drake = varos->SummonCreature(NPC_AZURE_RING_GUARDIAN, varos->GetPositionX(), varos->GetPositionY(), varos->GetPositionZ() + 40))
                        drake->AI()->DoAction(ACTION_CALL_DRAGON_EVENT);
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_DRAKOS:
                        if (state == DONE)
                        {
                            DoUpdateWorldState(WORLD_STATE_CENTRIFUGE_CONSTRUCT_SHOW, 1);
                            DoUpdateWorldState(WORLD_STATE_CENTRIFUGE_CONSTRUCT_AMOUNT, CentrifugueConstructCounter);
                            FreeDragons();
                            if (Creature* varos = instance->GetCreature(VarosGUID))
                                PhasingHandler::RemovePhase(varos, 170, true);
                            events.ScheduleEvent(EVENT_VAROS_INTRO, 15000);
                        }
                        break;
                    case DATA_VAROS:
                        if (state == DONE)
                        {
                            DoUpdateWorldState(WORLD_STATE_CENTRIFUGE_CONSTRUCT_SHOW, 0);
                            if (Creature* urom = instance->GetCreature(UromGUID))
                                PhasingHandler::RemovePhase(urom, 170, true);
                        }
                        break;
                    case DATA_UROM:
                        if (state == DONE)
                        {
                            if (Creature* eregos = instance->GetCreature(EregosGUID))
                            {
                                PhasingHandler::RemovePhase(eregos, 170, true);
                                GreaterWhelps();
                                events.ScheduleEvent(EVENT_EREGOS_INTRO, 5000);
                            }
                        }
                        break;
                    case DATA_EREGOS:
                        if (state == DONE)
                        {
                            if (GameObject* cache = instance->GetGameObject(EregosCacheGUID))
                            {
                                cache->SetRespawnTime(cache->GetRespawnDelay());
                                cache->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                            }
                        }
                        break;
                }

                return true;
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_CONSTRUCTS)
                {
                    if (CentrifugueConstructCounter == 0)
                        return KILL_NO_CONSTRUCT;
                    else if (CentrifugueConstructCounter == 1)
                        return KILL_ONE_CONSTRUCT;
                    else if (CentrifugueConstructCounter > 1)
                        return KILL_MORE_CONSTRUCT;
                }

                return KILL_NO_CONSTRUCT;
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_DRAKOS:
                        return DrakosGUID;
                    case DATA_VAROS:
                        return VarosGUID;
                    case DATA_UROM:
                        return UromGUID;
                    case DATA_EREGOS:
                        return EregosGUID;
                    default:
                        break;
                }

                return ObjectGuid::Empty;
            }

            void FreeDragons()
            {
                if (Creature* belgaristrasz = instance->GetCreature(BelgaristraszGUID))
                {
                    belgaristrasz->SetWalk(true);
                    belgaristrasz->GetMotionMaster()->MovePoint(POINT_MOVE_OUT, BelgaristraszMove);
                }

                if (Creature* eternos = instance->GetCreature(EternosGUID))
                {
                    eternos->SetWalk(true);
                    eternos->GetMotionMaster()->MovePoint(POINT_MOVE_OUT, EternosMove);
                }

                if (Creature* verdisa = instance->GetCreature(VerdisaGUID))
                {
                    verdisa->SetWalk(true);
                    verdisa->GetMotionMaster()->MovePoint(POINT_MOVE_OUT, VerdisaMove);
                }
            }

            void Update(uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_VAROS_INTRO:
                            if (Creature* varos = instance->GetCreature(VarosGUID))
                                varos->AI()->Talk(SAY_VAROS_INTRO_TEXT);
                            break;
                        case EVENT_EREGOS_INTRO:
                            if (Creature* eregos = instance->GetCreature(EregosGUID))
                                eregos->AI()->Talk(SAY_EREGOS_INTRO_TEXT);
                            break;
                        default:
                            break;
                    }
                }
            }

            void GreaterWhelps()
            {
                for (ObjectGuid guid : GreaterWhelpList)
                    if (Creature* gwhelp = instance->GetCreature(guid))
                        PhasingHandler::RemovePhase(gwhelp, 170, true);
            }

        protected:
            ObjectGuid DrakosGUID;
            ObjectGuid VarosGUID;
            ObjectGuid UromGUID;
            ObjectGuid EregosGUID;

            ObjectGuid BelgaristraszGUID;
            ObjectGuid EternosGUID;
            ObjectGuid VerdisaGUID;

            uint8 CentrifugueConstructCounter;

            ObjectGuid EregosCacheGUID;

            GuidList GreaterWhelpList;

            EventMap events;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_oculus_InstanceMapScript(map);
        }
};

void AddSC_instance_oculus()
{
    new instance_oculus();
}
