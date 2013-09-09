/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "zulaman.h"

class instance_zulaman : public InstanceMapScript
{
    public:
        instance_zulaman() : InstanceMapScript(ZulAmanScriptName, 568) { }

        struct instance_zulaman_InstanceScript : public InstanceScript
        {
            instance_zulaman_InstanceScript(InstanceMap* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);

                AkilzonGUID             = 0;
                NalorakkGUID            = 0;
                JanalaiGUID             = 0;
                HalazziGUID             = 0;
                HexLordMalacrassGUID    = 0;
                DaakaraGUID             = 0;
                VoljinGUID              = 0;
                HexLordTriggerGUID      = 0;
                SpeedRunTimer           = 16;
                ZulAmanState            = NOT_STARTED;
                ZulAmanBossCount        = 0;
            }

            void FillInitialWorldStates(WorldPacket& packet) OVERRIDE
            {
                packet << uint32(WORLD_STATE_ZULAMAN_TIMER_ENABLED) << uint32(ZulAmanState ? 1 : 0);
                packet << uint32(WORLD_STATE_ZULAMAN_TIMER) << uint32(SpeedRunTimer);
            }

            void OnCreatureCreate(Creature* creature) OVERRIDE
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

            void OnGameObjectCreate(GameObject* go) OVERRIDE
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

            void OnGameObjectRemove(GameObject* go) OVERRIDE
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

            uint64 GetData64(uint32 type) const OVERRIDE
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

                return 0;
            }

            void SetData(uint32 type, uint32 data) OVERRIDE
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

            uint32 GetData(uint32 type) const OVERRIDE
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

            bool SetBossState(uint32 type, EncounterState state) OVERRIDE
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

            void ProcessEvent(WorldObject* /*obj*/, uint32 eventId) OVERRIDE
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

            void Update(uint32 diff)
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

            std::string GetSaveData() OVERRIDE
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "Z A " << GetBossSaveData() << ZulAmanState
                    << ' ' << SpeedRunTimer << ' ' << ZulAmanBossCount;

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(char const* str) OVERRIDE
            {
                if (!str)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(str);

                char dataHead1, dataHead2;

                std::istringstream loadStream(str);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'Z' && dataHead2 == 'A')
                {
                    for (uint8 i = 0; i < EncounterCount; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;

                        SetBossState(i, EncounterState(tmpState));
                    }

                    loadStream >> ZulAmanState;
                    loadStream >> SpeedRunTimer;
                    loadStream >> ZulAmanBossCount;

                    if (ZulAmanState == IN_PROGRESS && SpeedRunTimer && SpeedRunTimer <= 15)
                    {
                        events.ScheduleEvent(EVENT_UPDATE_ZULAMAN_TIMER, 60000);
                        DoUpdateWorldState(WORLD_STATE_ZULAMAN_TIMER_ENABLED, 1);
                        DoUpdateWorldState(WORLD_STATE_ZULAMAN_TIMER, SpeedRunTimer);
                    }
                }
                else
                    OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

        protected:
            EventMap events;
            uint64 AkilzonGUID;
            uint64 NalorakkGUID;
            uint64 JanalaiGUID;
            uint64 HalazziGUID;
            uint64 HexLordMalacrassGUID;
            uint64 DaakaraGUID;
            uint64 VoljinGUID;
            uint64 HexLordTriggerGUID;
            uint64 StrangeGongGUID;
            uint64 MasiveGateGUID;
            uint32 SpeedRunTimer;
            uint32 ZulAmanState;
            uint32 ZulAmanBossCount;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const OVERRIDE
        {
            return new instance_zulaman_InstanceScript(map);
        }
};

void AddSC_instance_zulaman()
{
    new instance_zulaman();
}
