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
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "WorldStatePackets.h"
#include "zulaman.h"

class instance_zulaman : public InstanceMapScript
{
    public:
        instance_zulaman() : InstanceMapScript(ZulAmanScriptName, 568) { }

        struct instance_zulaman_InstanceScript : public InstanceScript
        {
            instance_zulaman_InstanceScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);

                SpeedRunTimer           = 16;
                ZulAmanState            = NOT_STARTED;
                ZulAmanBossCount        = 0;
            }

            void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override
            {
                packet.Worldstates.emplace_back(uint32(WORLD_STATE_ZULAMAN_TIMER_ENABLED), int32(ZulAmanState ? 1 : 0));
                packet.Worldstates.emplace_back(uint32(WORLD_STATE_ZULAMAN_TIMER), int32(SpeedRunTimer));
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_AKILZON:
                        AkilzonGUID = creature->GetGUID();
                        break;
                    case NPC_NALORAKK:
                        NalorakkGUID = creature->GetGUID();
                        break;
                    case NPC_JANALAI:
                        JanalaiGUID = creature->GetGUID();
                        break;
                    case NPC_HALAZZI:
                        HalazziGUID = creature->GetGUID();
                        break;
                    case NPC_HEXLORD:
                        HexLordMalacrassGUID = creature->GetGUID();
                        break;
                    case NPC_DAAKARA:
                        DaakaraGUID = creature->GetGUID();
                        break;
                    case NPC_VOLJIN:
                        VoljinGUID = creature->GetGUID();
                        break;
                    case NPC_HEXLORD_TRIGGER:
                        HexLordTriggerGUID = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_STRANGE_GONG:
                        StrangeGongGUID = go->GetGUID();
                        break;
                    case GO_MASSIVE_GATE:
                        MasiveGateGUID = go->GetGUID();
                        AddDoor(go, true);
                        if (ZulAmanState != NOT_STARTED)
                            go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_MASSIVE_GATE:
                        AddDoor(go, false);
                        break;
                    default:
                        break;
                }
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_AKILZON:
                        return AkilzonGUID;
                    case DATA_NALORAKK:
                        return NalorakkGUID;
                    case DATA_JANALAI:
                        return JanalaiGUID;
                    case DATA_HALAZZI:
                        return HalazziGUID;
                    case DATA_HEXLORD:
                        return HexLordMalacrassGUID;
                    case DATA_DAAKARA:
                        return DaakaraGUID;
                    case DATA_HEXLORD_TRIGGER:
                        return HexLordTriggerGUID;
                    case DATA_STRANGE_GONG:
                        return StrangeGongGUID;
                    case DATA_MASSIVE_GATE:
                        return MasiveGateGUID;
                    default:
                        break;
                }

                return ObjectGuid::Empty;
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_ZULAMAN_STATE:
                    {
                        if (data == IN_PROGRESS)
                        {
                            DoUpdateWorldState(WORLD_STATE_ZULAMAN_TIMER_ENABLED, 1);
                            DoUpdateWorldState(WORLD_STATE_ZULAMAN_TIMER, 15);
                            events.ScheduleEvent(EVENT_UPDATE_ZULAMAN_TIMER, 60000);
                            SpeedRunTimer = 15;
                            ZulAmanState = data;
                            SaveToDB();
                        }
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
                    case DATA_ZULAMAN_STATE:
                        return ZulAmanState;
                    default:
                        break;
                }

                return 0;
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                if (state == DONE)
                {
                    if (ZulAmanState == IN_PROGRESS && SpeedRunTimer)
                    {
                        ++ZulAmanBossCount;

                        if (ZulAmanBossCount < 2)
                        {
                            SpeedRunTimer = SpeedRunTimer + 5;
                            DoUpdateWorldState(WORLD_STATE_ZULAMAN_TIMER, SpeedRunTimer);
                        }
                        else if (ZulAmanBossCount == 4)
                        {
                            DoUpdateWorldState(WORLD_STATE_ZULAMAN_TIMER_ENABLED, 0);
                            events.CancelEvent(EVENT_UPDATE_ZULAMAN_TIMER);
                            ZulAmanState = DONE;
                        }
                    }
                }

                switch (type)
                {
                    case DATA_AKILZON:
                        break;
                    case DATA_NALORAKK:
                        break;
                    case DATA_JANALAI:
                        break;
                    case DATA_HALAZZI:
                    case DATA_HEXLORD:
                    case DATA_DAAKARA:
                        break;
                    default:
                        break;
                }

                return true;
            }

            void ProcessEvent(WorldObject* /*obj*/, uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_START_ZULAMAN:
                        if (Creature* voljin = instance->GetCreature(VoljinGUID))
                        {
                            if (voljin->IsAIEnabled)
                                voljin->AI()->DoAction(ACTION_START_ZULAMAN);
                        }
                        break;
                    default:
                        break;
                }
            }

            void Update(uint32 diff) override
            {
                if (events.Empty())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_UPDATE_ZULAMAN_TIMER:
                            SaveToDB();
                            DoUpdateWorldState(WORLD_STATE_ZULAMAN_TIMER, --SpeedRunTimer);
                            if (SpeedRunTimer)
                                events.ScheduleEvent(EVENT_UPDATE_ZULAMAN_TIMER, 60000);
                            else
                            {
                                DoUpdateWorldState(WORLD_STATE_ZULAMAN_TIMER_ENABLED, 0);
                                events.CancelEvent(EVENT_UPDATE_ZULAMAN_TIMER);
                                ZulAmanState = FAIL;
                            }
                            break;
                        default:
                            break;
                    }
                }
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << ZulAmanState  << ' '
                     << SpeedRunTimer << ' '
                     << ZulAmanBossCount;
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                data >> ZulAmanState;
                data >> SpeedRunTimer;
                data >> ZulAmanBossCount;

                if (ZulAmanState == IN_PROGRESS && SpeedRunTimer && SpeedRunTimer <= 15)
                {
                    events.ScheduleEvent(EVENT_UPDATE_ZULAMAN_TIMER, 60000);
                    DoUpdateWorldState(WORLD_STATE_ZULAMAN_TIMER_ENABLED, 1);
                    DoUpdateWorldState(WORLD_STATE_ZULAMAN_TIMER, SpeedRunTimer);
                }
            }

        protected:
            EventMap events;
            ObjectGuid AkilzonGUID;
            ObjectGuid NalorakkGUID;
            ObjectGuid JanalaiGUID;
            ObjectGuid HalazziGUID;
            ObjectGuid HexLordMalacrassGUID;
            ObjectGuid DaakaraGUID;
            ObjectGuid VoljinGUID;
            ObjectGuid HexLordTriggerGUID;
            ObjectGuid StrangeGongGUID;
            ObjectGuid MasiveGateGUID;
            uint32 SpeedRunTimer;
            uint32 ZulAmanState;
            uint32 ZulAmanBossCount;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_zulaman_InstanceScript(map);
        }
};

void AddSC_instance_zulaman()
{
    new instance_zulaman();
}
