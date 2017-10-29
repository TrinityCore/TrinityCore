/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "GameEventMgr.h"
#include "GameTime.h"

enum GameEvent
{
    GAME_EVENT_CHILDEREN_OF_GOLDSHIRE = 74
};

enum Paths
{
    STORMWIND_PATH = 80500,
    GOLDSHIRE_PATH = 80501,
    WOODS_PATH = 80502,
    HOUSE_PATH = 80503,
    LISA_PATH = 80700
};

enum Waypoints
{
    STORMWIND_WAYPOINT = 52,
    GOLDSHIRE_WAYPOINT = 32,
    WOODS_WAYPOINT = 22,
    HOUSE_WAYPOINT = 26,
    LISA_WAYPOINT = 4
};

enum Sounds
{
    BANSHEE_DEATH = 1171,
    BANSHEEATTACK = 1167,
    CTHUN_YOU_WILL_DIE = 8585,
    CTHUN_DEATH_IS_CLOSE = 8580,
    HUMAN_FEMALE_EMOTE_CRY = 6916,
    GHOSTDEATH = 3416
};

enum Creatures
{
    NPC_DANA = 804,
    NPC_CAMERON = 805,
    NPC_JOHN = 806,
    NPC_LISA = 807,
    NPC_AARON = 810,
    NPC_JOSE = 811
};

enum Events
{
    EVENT_WP_START_GOLDSHIRE = 1,
    EVENT_WP_START_WOODS = 2,
    EVENT_WP_START_HOUSE = 3,
    EVENT_WP_START_LISA = 4,
    EVENT_PLAY_SOUNDS = 5
};

Position const MovePosCameron = { -9354.81f, -87.9358f, 65.4745f, 5.20108f };

class npc_cameron : public CreatureScript
{
public:
    npc_cameron() : CreatureScript("npc_cameron") { }

    struct npc_cameronAI : public ScriptedAI
    {
        npc_cameronAI(Creature* creature) : ScriptedAI(creature)
        {
            _started = false;
            creature->setActive(true);
        }

        static uint32 SoundPicker()
        {
            uint32 newid = RAND(
                BANSHEE_DEATH,
                BANSHEEATTACK,
                CTHUN_YOU_WILL_DIE,
                CTHUN_DEATH_IS_CLOSE,
                HUMAN_FEMALE_EMOTE_CRY,
                GHOSTDEATH
            );
            return newid;
        }

        void WaypointReached(uint32 waypointId, uint32 pathId) override
        {
            switch (pathId)
            {
                case STORMWIND_PATH:
                {
                    if (waypointId == STORMWIND_WAYPOINT)
                    {
                        me->SetHomePosition(me->GetPosition());
                        me->GetMotionMaster()->MovementExpired();
                        me->GetMotionMaster()->MoveRandom(5.f);
                        _events.ScheduleEvent(EVENT_WP_START_GOLDSHIRE, Seconds(2));
                    }

                    break;
                }
                case GOLDSHIRE_PATH:
                {
                    if (waypointId == GOLDSHIRE_WAYPOINT)
                    {
                        me->SetHomePosition(me->GetPosition());
                        me->GetMotionMaster()->MovementExpired();
                        me->GetMotionMaster()->MoveRandom(5.f);
                        _events.ScheduleEvent(EVENT_WP_START_WOODS, Seconds(2));
                    }
                    break;
                }
                case WOODS_PATH:
                {
                    if (waypointId == WOODS_WAYPOINT)
                    {
                        me->SetHomePosition(me->GetPosition());
                        me->GetMotionMaster()->MovementExpired();
                        _events.ScheduleEvent(EVENT_WP_START_HOUSE, Seconds(2));
                        _events.ScheduleEvent(EVENT_WP_START_LISA, Seconds(1));
                    }

                    break;
                }
                case HOUSE_PATH:
                {
                    if (waypointId == HOUSE_WAYPOINT)
                    {
                        me->SetHomePosition(me->GetPosition());
                        //me->GetMotionMaster()->MovementExpired();
                        me->GetMotionMaster()->MovePoint(1, MovePosCameron);

                        _events.ScheduleEvent(EVENT_PLAY_SOUNDS, Seconds(10));

                        if (Creature* dana = me->FindNearestCreature(NPC_DANA, 10.0f))
                            dana->AI()->SetData(1, 1);

                        if (Creature* john = me->FindNearestCreature(NPC_JOHN, 10.0f))
                            john->AI()->SetData(1, 1);

                        if (Creature* lisa = me->FindNearestCreature(NPC_LISA, 10.0f))
                            lisa->AI()->SetData(1, 1);

                        if (Creature* aaron = me->FindNearestCreature(NPC_AARON, 10.0f))
                            aaron->AI()->SetData(1, 1);

                        if (Creature* jose = me->FindNearestCreature(NPC_JOSE, 10.0f))
                            jose->AI()->SetData(1, 1);
                    }
                    break;
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            time_t time = GameTime::GetGameTime();
            tm localTm;
            localtime_r(&time, &localTm);

            // Start event at 7 am
            if ((localTm.tm_hour == 7 && localTm.tm_min == 0 && localTm.tm_sec == 0) && !_started )
            {
                me->GetMotionMaster()->MovePath(STORMWIND_PATH, false);
                _started = true;
            }

            // Reset event at 8 am
            if ((localTm.tm_hour == 8 && localTm.tm_min == 0 && localTm.tm_sec == 0) && _started == true)
            {
                _started = false;
            }

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_WP_START_GOLDSHIRE:
                    {
                        me->GetMotionMaster()->MovementExpired();
                        me->GetMotionMaster()->MovePath(GOLDSHIRE_PATH, false);
                        break;
                    }
                    case EVENT_WP_START_WOODS:
                    {
                        me->GetMotionMaster()->MovementExpired();
                        me->GetMotionMaster()->MovePath(WOODS_PATH, false);
                        break;
                    }
                    case EVENT_WP_START_HOUSE:
                    {
                        me->GetMotionMaster()->MovementExpired();
                        me->GetMotionMaster()->MovePath(HOUSE_PATH, false);
                        break;
                    }
                    case EVENT_WP_START_LISA:
                    {
                        if (Creature* lisa = me->FindNearestCreature(NPC_LISA, 10.0f))
                        {
                            lisa->GetMotionMaster()->MovementExpired();
                            lisa->GetMotionMaster()->MovePath(LISA_PATH, false);
                        }
                        break;
                    }
                    case EVENT_PLAY_SOUNDS:
                    {
                        me->PlayDistanceSound(SoundPicker());
                        me->PlayDistanceSound(SoundPicker());
                        me->PlayDistanceSound(SoundPicker());
                        me->PlayDistanceSound(SoundPicker());
                        break;
                    }
                    default:
                        break;
                }
            }
        }

    private:
        EventMap _events;
        bool _started;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_cameronAI(creature);
    }
};

void AddSC_goldshire()
{
    new npc_cameron();
}
