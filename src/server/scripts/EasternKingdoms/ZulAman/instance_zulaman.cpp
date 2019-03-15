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
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "zulaman.h"

ObjectData const creatureData[] =
{
    { BOSS_AKILZON,                     DATA_ALKILZON                   },
    { BOSS_NALORAKK,                    DATA_NALORAKK                   },
    { BOSS_JANALAI,                     DATA_JANALAI                    },
    { BOSS_HALAZZI,                     DATA_HALAZZI                    },
    { BOSS_HEXLORD_MALACRASS,           DATA_HEXLORD_MALACRASS          },
    { BOSS_DAAKARA,                     DATA_DAAKARA                    },
    { NPC_VOLJIN,                       DATA_VOLJIN                     },
    { NPC_HEXLORD_MALACRASS_TRIGGER,    DATA_HEXLORD_MALACRASS_TRIGGER  },
    { 0,                                0                               } // END
};

ObjectData const cameobjectData[] =
{
    { GO_STRANGE_GONG,                  DATA_STRANGE_GONG               },
    { GO_MASSIVE_GATE,                  DATA_MASSIVE_GATE               },
    { 0,                                0                               } // END
};

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
            LoadObjectData(creatureData, cameobjectData);
            _remainingSpeedRunTime = 0;
            _speedRunState = NOT_STARTED;
        }

        void FillInitialWorldStates(WorldPacket& packet) override
        {
            packet << uint32(WORLD_STATE_ZULAMAN_TIMER_ENABLED) << uint32(_speedRunState ? 1 : 0);
            packet << uint32(WORLD_STATE_ZULAMAN_TIMER) << uint32(_remainingSpeedRunTime);
        }

        void OnCreatureCreate(Creature* creature) override
        {
            /*
            switch (creature->GetEntry())
            {
            }
            */
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_MASSIVE_GATE:
                    if (_speedRunState != NOT_STARTED)
                        go->SetGoState(GO_STATE_ACTIVE);
                    break;
                default:
                    break;
            }
        }

        void OnGameObjectRemove(GameObject* go) override
        {
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            return ObjectGuid::Empty;
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case DATA_ZULAMAN_SPEEDRUN_STATE:
                {
                    if (data == IN_PROGRESS)
                    {
                        _remainingSpeedRunTime = 15;
                        _speedRunState = IN_PROGRESS;
                        DoUpdateWorldState(WORLD_STATE_ZULAMAN_TIMER_ENABLED, 1);
                        DoUpdateWorldState(WORLD_STATE_ZULAMAN_TIMER, _remainingSpeedRunTime);
                        events.ScheduleEvent(EVENT_UPDATE_SPEED_RUN_TIMER, 1min);
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
                case DATA_ZULAMAN_SPEEDRUN_STATE:
                    return _speedRunState;
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
            }

            return true;
        }

        void ProcessEvent(WorldObject* /*obj*/, uint32 eventId) override
        {
            switch (eventId)
            {
                case EVENT_START_ZULAMAN:
                    if (Creature* voljin = GetCreature(DATA_VOLJIN))
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
                    case EVENT_UPDATE_SPEED_RUN_TIMER:
                        _remainingSpeedRunTime--;
                        DoUpdateWorldState(WORLD_STATE_ZULAMAN_TIMER, _remainingSpeedRunTime);
                        if (_remainingSpeedRunTime)
                            events.Repeat(1min);
                        else
                        {
                            DoUpdateWorldState(WORLD_STATE_ZULAMAN_TIMER_ENABLED, 0);
                            _remainingSpeedRunTime = FAIL;
                        }
                        SaveToDB();
                        break;
                    default:
                        break;
                }
            }
        }

        void WriteSaveDataMore(std::ostringstream& data) override
        {
            data << _speedRunState << ' '
                << _remainingSpeedRunTime;
        }

        void ReadSaveDataMore(std::istringstream& data) override
        {
            data >> _speedRunState;
            data >> _remainingSpeedRunTime;

            if (_speedRunState == IN_PROGRESS && _remainingSpeedRunTime)
            {
                events.ScheduleEvent(EVENT_UPDATE_SPEED_RUN_TIMER, 1min);
                DoUpdateWorldState(WORLD_STATE_ZULAMAN_TIMER_ENABLED, 1);
                DoUpdateWorldState(WORLD_STATE_ZULAMAN_TIMER, _remainingSpeedRunTime);
            }
        }

    protected:
        EventMap events;
        uint32 _remainingSpeedRunTime;
        uint32 _speedRunState;
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
