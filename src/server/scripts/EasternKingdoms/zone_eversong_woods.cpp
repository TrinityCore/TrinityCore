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
#include "GameObject.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"

enum Partygoer_Pather
{
    EVENT_PATH                    = 1,
    EVENT_RANDOM_ACTION_PATHER,
    EVENT_REMOVE_EQUIPMENT_PATHER,
    EVENT_STOP_DANCING_PATHER,

    PATH_FIRST_PATH               = 594440,
    PATH_LAST_PATH                = 594444,
};

struct npc_partygoer_pather : public ScriptedAI
{
    npc_partygoer_pather(Creature* creature) : ScriptedAI(creature), _path(PATH_FIRST_PATH) { }

    void JustAppeared() override
    {
        _path = PATH_FIRST_PATH;
        _events.ScheduleEvent(EVENT_RANDOM_ACTION_PATHER, 11s, 14s);
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 /*pathId*/) override
    {
        ++_path;
        if (_path > PATH_LAST_PATH)
            _path = PATH_FIRST_PATH;

        _events.ScheduleEvent(EVENT_RANDOM_ACTION_PATHER, 11s, 14s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_PATH:
                    me->GetMotionMaster()->MovePath(_path, false);
                    break;
                case EVENT_RANDOM_ACTION_PATHER:
                {
                    int8 action = urand(1, 5);

                    switch (action)
                    {
                        case 1:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                            _events.ScheduleEvent(EVENT_PATH, 11s);
                            break;
                        case 2:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                            _events.ScheduleEvent(EVENT_PATH, 11s);
                            break;
                        case 3:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_LAUGH);
                            _events.ScheduleEvent(EVENT_PATH, 11s);
                            break;
                        case 4:
                            me->LoadEquipment(urand(1, 2));
                            me->HandleEmoteCommand(EMOTE_ONESHOT_EAT_NO_SHEATHE);
                            _events.ScheduleEvent(EVENT_REMOVE_EQUIPMENT_PATHER, 4s);
                            break;
                        case 5:
                            me->SetEmoteState(EMOTE_STATE_DANCE);
                            _events.ScheduleEvent(EVENT_STOP_DANCING_PATHER, 6s);
                            break;
                    }
                    break;
                }
                case EVENT_REMOVE_EQUIPMENT_PATHER:
                    me->LoadEquipment(0, true);
                    _events.ScheduleEvent(EVENT_PATH, 8s);
                    break;
                case EVENT_STOP_DANCING_PATHER:
                    me->SetEmoteState(EMOTE_ONESHOT_NONE);
                    _events.ScheduleEvent(EVENT_PATH, 5s);
                    break;
            }
        }

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    uint32 _path;
};

enum Partygoer
{
    EVENT_RANDOM_ACTION     = 1,
    EVENT_REMOVE_EQUIPMENT,
    EVENT_STOP_DANCING,
    EVENT_THROW_FIREWORKS,
    EVENT_RESET_FACING,

    GO_FIREWORKS_LAUNCHER   = 180771,

    SPELL_SMALL_YELLOW_ROCKET = 26295
};

struct npc_partygoer : public ScriptedAI
{
    npc_partygoer(Creature* creature) : ScriptedAI(creature), _facing(0.0f) { }

    void JustAppeared() override
    {
        _facing = me->GetOrientation();
        _events.ScheduleEvent(EVENT_RANDOM_ACTION, 1s, 20s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_RANDOM_ACTION:
                {
                    int8 action = urand(1, 6);

                    switch (action)
                    {
                        case 1:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                            _events.ScheduleEvent(EVENT_RANDOM_ACTION, 13s, 20s);
                            break;
                        case 2:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
                            _events.ScheduleEvent(EVENT_RANDOM_ACTION, 13s, 20s);
                            break;
                        case 3:
                            me->HandleEmoteCommand(EMOTE_ONESHOT_LAUGH);
                            _events.ScheduleEvent(EVENT_RANDOM_ACTION, 13s, 20s);
                            break;
                        case 4:
                            me->LoadEquipment(urand(1, 2));
                            me->HandleEmoteCommand(EMOTE_ONESHOT_EAT_NO_SHEATHE);
                            _events.ScheduleEvent(EVENT_REMOVE_EQUIPMENT, 4s);
                            break;
                        case 5:
                            me->SetEmoteState(EMOTE_STATE_DANCE);
                            _events.ScheduleEvent(EVENT_STOP_DANCING, 8s, 16s);
                            break;
                        case 6:
                            if (GameObject* launcher = me->FindNearestGameObject(GO_FIREWORKS_LAUNCHER, 20.0f))
                                me->SetFacingToObject(launcher);
                            _events.ScheduleEvent(EVENT_THROW_FIREWORKS, 1s);
                            break;
                    }
                    break;
                }
                case EVENT_REMOVE_EQUIPMENT:
                    me->LoadEquipment(0, true);
                    _events.ScheduleEvent(EVENT_RANDOM_ACTION, 10s, 20s);
                    break;
                case EVENT_STOP_DANCING:
                    me->SetEmoteState(EMOTE_ONESHOT_NONE);
                    _events.ScheduleEvent(EVENT_RANDOM_ACTION, 10s, 20s);
                    break;
                case EVENT_THROW_FIREWORKS:
                    me->CastSpell(me, SPELL_SMALL_YELLOW_ROCKET);
                    _events.ScheduleEvent(EVENT_RESET_FACING, 3s);
                    break;
                case EVENT_RESET_FACING:
                    me->SetFacingTo(_facing);
                    _events.ScheduleEvent(EVENT_RANDOM_ACTION, 12s, 20s);
                    break;
            }
        }

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    float _facing;
};

void AddSC_eversong_woods()
{
    RegisterCreatureAI(npc_partygoer_pather);
    RegisterCreatureAI(npc_partygoer);
}
