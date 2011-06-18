/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "ruby_sanctum.h"

enum Texts
{
    SAY_XERESTRASZA_EVENT       = 0,
    SAY_XERESTRASZA_EVENT_1     = 1,
    SAY_XERESTRASZA_EVENT_2     = 2,
    SAY_XERESTRASZA_EVENT_3     = 3,
    SAY_XERESTRASZA_EVENT_4     = 4,
    SAY_XERESTRASZA_EVENT_5     = 5,
    SAY_XERESTRASZA_EVENT_6     = 6,
    SAY_XERESTRASZA_EVENT_7     = 7,
    SAY_XERESTRASZA_INTRO       = 8,
};

enum Events
{
    EVENT_XERESTRASZA_EVENT_1   = 1,
    EVENT_XERESTRASZA_EVENT_2   = 2,
    EVENT_XERESTRASZA_EVENT_3   = 3,
    EVENT_XERESTRASZA_EVENT_4   = 4,
    EVENT_XERESTRASZA_EVENT_5   = 5,
    EVENT_XERESTRASZA_EVENT_6   = 6,
    EVENT_XERESTRASZA_EVENT_7   = 7,
};

Position const xerestraszaMovePos = {3151.236f, 379.8733f, 86.31996f, 0.0f};

class npc_xerestrasza : public CreatureScript
{
    public:
        npc_xerestrasza() : CreatureScript("npc_xerestrasza") { }

        struct npc_xerestraszaAI : public ScriptedAI
        {
            npc_xerestraszaAI(Creature* creature) : ScriptedAI(creature)
            {
                _isIntro = true;
                _introDone = false;
            }

            void Reset()
            {
                _events.Reset();
                me->RemoveFlag(UNIT_NPC_FLAGS, GOSSIP_OPTION_QUESTGIVER);
            }

            void DoAction(int32 const action)
            {
                if (action == ACTION_BALTHARUS_DEATH)
                {
                    me->setActive(true);
                    _isIntro = false;

                    Talk(SAY_XERESTRASZA_EVENT);
                    me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                    me->GetMotionMaster()->MovePoint(0, xerestraszaMovePos);

                    _events.ScheduleEvent(EVENT_XERESTRASZA_EVENT_1, 16000);
                    _events.ScheduleEvent(EVENT_XERESTRASZA_EVENT_2, 25000);
                    _events.ScheduleEvent(EVENT_XERESTRASZA_EVENT_3, 32000);
                    _events.ScheduleEvent(EVENT_XERESTRASZA_EVENT_4, 42000);
                    _events.ScheduleEvent(EVENT_XERESTRASZA_EVENT_5, 51000);
                    _events.ScheduleEvent(EVENT_XERESTRASZA_EVENT_6, 61000);
                    _events.ScheduleEvent(EVENT_XERESTRASZA_EVENT_7, 69000);
                }
                else if (action == ACTION_INTRO_BALTHARUS && !_introDone)
                {
                    _introDone = true;
                    Talk(SAY_XERESTRASZA_INTRO);
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (_isIntro)
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_XERESTRASZA_EVENT_1:
                            Talk(SAY_XERESTRASZA_EVENT_1);
                            break;
                        case EVENT_XERESTRASZA_EVENT_2:
                            Talk(SAY_XERESTRASZA_EVENT_2);
                            break;
                        case EVENT_XERESTRASZA_EVENT_3:
                            Talk(SAY_XERESTRASZA_EVENT_3);
                            break;
                        case EVENT_XERESTRASZA_EVENT_4:
                            Talk(SAY_XERESTRASZA_EVENT_4);
                            break;
                        case EVENT_XERESTRASZA_EVENT_5:
                            Talk(SAY_XERESTRASZA_EVENT_5);
                            break;
                        case EVENT_XERESTRASZA_EVENT_6:
                            Talk(SAY_XERESTRASZA_EVENT_6);
                            break;
                        case EVENT_XERESTRASZA_EVENT_7:
                            me->SetFlag(UNIT_NPC_FLAGS, GOSSIP_OPTION_QUESTGIVER);
                            Talk(SAY_XERESTRASZA_EVENT_7);
                            me->setActive(false);
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap _events;
            bool _isIntro;
            bool _introDone;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<npc_xerestraszaAI>(creature);
        }
};

class at_baltharus_plateau : public AreaTriggerScript
{
    public:
        at_baltharus_plateau() : AreaTriggerScript("at_baltharus_plateau") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            // Only trigger once
            if (InstanceScript* instance = player->GetInstanceScript())
            {
                if (Creature* xerestrasza = ObjectAccessor::GetCreature(*player, instance->GetData64(DATA_XERESTRASZA)))
                    xerestrasza->AI()->DoAction(ACTION_INTRO_BALTHARUS);

                if (Creature* baltharus = ObjectAccessor::GetCreature(*player, instance->GetData64(DATA_BALTHARUS_THE_WARBORN)))
                    baltharus->AI()->DoAction(ACTION_INTRO_BALTHARUS);
            }

            return true;
        }
};

void AddSC_ruby_sanctum()
{
    new npc_xerestrasza();
    new at_baltharus_plateau();
}
