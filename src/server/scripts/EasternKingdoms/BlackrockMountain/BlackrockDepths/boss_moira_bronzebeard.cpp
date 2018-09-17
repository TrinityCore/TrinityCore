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
#include "blackrock_depths.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_HEAL                                             = 10917,
    SPELL_RENEW                                            = 10929,
    SPELL_SHIELD                                           = 10901,
    SPELL_MINDBLAST                                        = 10947,
    SPELL_SHADOWWORDPAIN                                   = 10894,
    SPELL_SMITE                                            = 10934
};

enum Events
{
    EVENT_MINDBLAST                                        = 1,
    EVENT_SHADOW_WORD_PAIN                                 = 2,
    EVENT_SMITE                                            = 3,
    EVENT_HEAL                                             = 4  // not used atm
};

class boss_moira_bronzebeard : public CreatureScript
{
    public:
        boss_moira_bronzebeard() : CreatureScript("boss_moira_bronzebeard") { }

        struct boss_moira_bronzebeardAI : public ScriptedAI
        {
            boss_moira_bronzebeardAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                _events.Reset();
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                //_events.ScheduleEvent(EVENT_HEAL, 12s); // not used atm // These times are probably wrong
                _events.ScheduleEvent(EVENT_MINDBLAST, 16s);
                _events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 2s);
                _events.ScheduleEvent(EVENT_SMITE, 8s);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MINDBLAST:
                            DoCastVictim(SPELL_MINDBLAST);
                            _events.ScheduleEvent(EVENT_MINDBLAST, 14s);
                            break;
                        case EVENT_SHADOW_WORD_PAIN:
                            DoCastVictim(SPELL_SHADOWWORDPAIN);
                            _events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 18s);
                            break;
                        case EVENT_SMITE:
                            DoCastVictim(SPELL_SMITE);
                            _events.ScheduleEvent(EVENT_SMITE, 10s);
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBlackrockDepthsAI<boss_moira_bronzebeardAI>(creature);
        }
};

void AddSC_boss_moira_bronzebeard()
{
    new boss_moira_bronzebeard();
}
