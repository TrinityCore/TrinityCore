/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "InstanceScript.h"
#include "CreatureTextMgr.h"
#include "culling_of_stratholme.h"
#include "Player.h"
#include "TemporarySummon.h"
#include "SpellInfo.h"

/* Culling of Stratholme encounters:
0 - Meathook
1 - Salramm the Fleshcrafter
2 - Chrono-Lord Epoch
3 - Mal'Ganis
4 - Infinite Corruptor (Heroic only)
*/

Position const ChromieSummonPos[] =
{
    { 1813.298f, 1283.578f, 142.3258f, 3.878161f },
    { 2273.725f, 1483.684f, 128.7205f, 6.057528f }
};

Position const InfiniteCorruptorPos = { 2335.47f, 1262.04f, 132.921f, 1.42079f };
Position const TimeRiftPos = { 2334.626f, 1280.45f, 133.0066f, 1.727876f };
Position const GuardianOfTimePos = { 2321.489f, 1268.383f, 132.8507f, 0.418879f };

DoorData const doorData[] =
{
    { GO_MALGANIS_GATE_2, DATA_MAL_GANIS, DOOR_TYPE_ROOM,    BOUNDARY_NONE },
    { GO_EXIT_GATE,       DATA_MAL_GANIS, DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    { 0,                  0,              DOOR_TYPE_ROOM,    BOUNDARY_NONE } // END
};

class instance_culling_of_stratholme : public InstanceMapScript
{
    public:
        instance_culling_of_stratholme() : InstanceMapScript(CoSScriptName, 595) { }

        struct instance_culling_of_stratholme_InstanceMapScript : public InstanceScript
        {
            instance_culling_of_stratholme_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);

                _crateCount        = 0;
                _eventTimer        = 0;
                _infiniteCouterState = NOT_STARTED;
            }

            void FillInitialWorldStates(WorldPacket& data) override
            {
                data << uint32(WORLDSTATE_SHOW_CRATES) << uint32(1);
                data << uint32(WORLDSTATE_CRATES_REVEALED) << uint32(_crateCount);
                data << uint32(WORLDSTATE_WAVE_COUNT) << uint32(0);
                data << uint32(WORLDSTATE_TIME_GUARDIAN) << uint32(25);
                data << uint32(WORLDSTATE_TIME_GUARDIAN_SHOW) << uint32(0);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_CHROMIE:
                        _chromieGUID = creature->GetGUID();
                        break;
                    case NPC_ARTHAS:
                        _arthasGUID = creature->GetGUID();
                        break;
                    case NPC_MEATHOOK:
                        _meathookGUID = creature->GetGUID();
                        break;
                    case NPC_SALRAMM:
                        _salrammGUID = creature->GetGUID();
                        break;
                    case NPC_EPOCH:
                        _epochGUID = creature->GetGUID();
                        break;
                    case NPC_MAL_GANIS:
                        _malGanisGUID = creature->GetGUID();
                        break;
                    case NPC_INFINITE:
                        _infiniteGUID = creature->GetGUID();
                        DoUpdateWorldState(WORLDSTATE_TIME_GUARDIAN_SHOW, 1);
                        break;
                    case NPC_GENERIC_BUNNY:
                        _genericBunnyGUID = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_SHKAF_GATE:
                        _shkafGateGUID = go->GetGUID();
                        break;
                    case GO_MALGANIS_GATE_1:
                        _malGanisGate1GUID = go->GetGUID();
                        break;
                    case GO_MALGANIS_GATE_2:
                        _malGanisGate2GUID = go->GetGUID();
                        AddDoor(go, true);
                        break;
                    case GO_EXIT_GATE:
                        _exitGateGUID = go->GetGUID();
                        AddDoor(go, true);
                        break;
                    case GO_MALGANIS_CHEST_N:
                    case GO_MALGANIS_CHEST_H:
                        _malGanisChestGUID = go->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_MALGANIS_GATE_2:
                    case GO_EXIT_GATE:
                        AddDoor(go, false);
                        break;
                    default:
                        break;
                }
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_CRATE_COUNT:
                        _crateCount = data;
                        if (_crateCount == 5)
                        {
                            if (Creature* bunny = instance->GetCreature(_genericBunnyGUID))
                                bunny->CastSpell(bunny, SPELL_CRATES_CREDIT, true);

                            // Summon Chromie and global whisper
                            if (Creature* chromie = instance->SummonCreature(NPC_CHROMIE_2, ChromieSummonPos[0]))
                                if (!instance->GetPlayers().isEmpty())
                                    chromie->AI()->Talk(SAY_CRATES_COMPLETED);
                        }
                        DoUpdateWorldState(WORLDSTATE_CRATES_REVEALED, _crateCount);
                        break;
                    case DATA_INFINITE_COUNTER:
                        _infiniteCouterState = data;
                        if (data == IN_PROGRESS)
                        {
                            if (!_infiniteGUID)
                            {
                                _eventTimer = 25;
                                instance->SummonCreature(NPC_INFINITE, InfiniteCorruptorPos);
                                instance->SummonCreature(NPC_TIME_RIFT, TimeRiftPos);
                                instance->SummonCreature(NPC_GUARDIAN_OF_TIME, GuardianOfTimePos);
                                events.ScheduleEvent(EVENT_INFINITE_TIMER, 1);
                            }
                        }
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
                    case DATA_INFINITE:
                        if (state == DONE)
                        {
                            DoUpdateWorldState(WORLDSTATE_TIME_GUARDIAN_SHOW, 0);
                            DoUpdateWorldState(WORLDSTATE_TIME_GUARDIAN, 0);
                        }
                        break;
                    case DATA_MAL_GANIS:
                        if (state == DONE)
                        {
                            if (GameObject* go = instance->GetGameObject(_malGanisChestGUID))
                                go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                            instance->SummonCreature(NPC_CHROMIE_3, ChromieSummonPos[1]);
                        }
                        break;
                    default:
                        break;
                }

                return true;
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_CRATE_COUNT:
                        return _crateCount;
                    case DATA_INFINITE_COUNTER:
                        return _infiniteCouterState;
                    default:
                        break;
                }
                return 0;
            }

            ObjectGuid GetGuidData(uint32 identifier) const override
            {
                switch (identifier)
                {
                    case DATA_ARTHAS:
                        return _arthasGUID;
                    case DATA_MEATHOOK:
                        return _meathookGUID;
                    case DATA_SALRAMM:
                        return _salrammGUID;
                    case DATA_EPOCH:
                        return _epochGUID;
                    case DATA_MAL_GANIS:
                        return _malGanisGUID;
                    case DATA_INFINITE:
                        return _infiniteGUID;
                    case DATA_SHKAF_GATE:
                        return _shkafGateGUID;
                    case DATA_MAL_GANIS_GATE_1:
                        return _malGanisGate1GUID;
                    case DATA_MAL_GANIS_GATE_2:
                        return _malGanisGate2GUID;
                    case DATA_EXIT_GATE:
                        return _exitGateGUID;
                    case DATA_MAL_GANIS_CHEST:
                        return _malGanisChestGUID;
                    default:
                        break;
                }
                return ObjectGuid::Empty;
            }

            void Update(uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_INFINITE_TIMER:
                            DoUpdateWorldState(WORLDSTATE_TIME_GUARDIAN, _eventTimer);

                            switch (_eventTimer)
                            {
                                case 25:
                                    if (instance->HavePlayers())
                                        if (Creature* chromie = instance->GetCreature(_chromieGUID))
                                            chromie->AI()->Talk(SAY_INFINITE_START);
                                    break;
                                case 5:
                                    if (instance->HavePlayers())
                                        if (Creature* chromie = instance->GetCreature(_chromieGUID))
                                            chromie->AI()->Talk(SAY_INFINITE);
                                    break;
                                case 0:
                                    if (instance->HavePlayers())
                                        if (Creature* chromie = instance->GetCreature(_chromieGUID))
                                            chromie->AI()->Talk(SAY_INFINITE_FAIL);

                                    if (Creature* infinite = instance->GetCreature(_infiniteGUID))
                                    {
                                        if (Creature* guardian = infinite->FindNearestCreature(NPC_GUARDIAN_OF_TIME, 100.0f))
                                            infinite->Kill(guardian);

                                        if (Creature* rift = infinite->FindNearestCreature(NPC_TIME_RIFT, 100.0f))
                                        {
                                            infinite->GetMotionMaster()->MovePoint(0, rift->GetPositionX(), rift->GetPositionY(), rift->GetPositionZ());
                                            rift->DespawnOrUnsummon(3000);
                                        }

                                        infinite->DespawnOrUnsummon(3000);
                                        infinite->AI()->Talk(SAY_FAIL_EVENT);
                                    }
                                    DoUpdateWorldState(WORLDSTATE_TIME_GUARDIAN_SHOW, 0);
                                    return;
                                default:
                                    break;
                            }
                            events.ScheduleEvent(EVENT_INFINITE_TIMER, 60000);
                            --_eventTimer;
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            ObjectGuid _chromieGUID;
            ObjectGuid _arthasGUID;
            ObjectGuid _meathookGUID;
            ObjectGuid _salrammGUID;
            ObjectGuid _epochGUID;
            ObjectGuid _malGanisGUID;
            ObjectGuid _infiniteGUID;
            ObjectGuid _shkafGateGUID;
            ObjectGuid _malGanisGate1GUID;
            ObjectGuid _malGanisGate2GUID;
            ObjectGuid _exitGateGUID;
            ObjectGuid _malGanisChestGUID;
            ObjectGuid _genericBunnyGUID;

            uint32 _crateCount;
            uint32 _eventTimer;
            uint32 _infiniteCouterState;

            EventMap events;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_culling_of_stratholme_InstanceMapScript(map);
        }
};

void AddSC_instance_culling_of_stratholme()
{
    new instance_culling_of_stratholme();
}
