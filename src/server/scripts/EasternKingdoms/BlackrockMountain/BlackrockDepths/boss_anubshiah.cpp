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
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_SHADOWBOLT                    = 17228,
    SPELL_CURSEOFTONGUES                = 15470,
    SPELL_CURSEOFWEAKNESS               = 17227,
    SPELL_DEMONARMOR                    = 11735,
    SPELL_ENVELOPINGWEB                 = 15471
};

enum Events
{
    EVENT_SHADOWBOLT                    = 1,
    EVENT_CURSE_OF_TONGUES              = 2,
    EVENT_CURSE_OF_WEAKNESS             = 3,
    EVENT_DEMON_ARMOR                   = 4,
    EVENT_ENVELOPING_WEB                = 5
};

class boss_anubshiah : public CreatureScript
{
    public:
        boss_anubshiah() : CreatureScript("boss_anubshiah") { }

        struct boss_anubshiahAI : public ScriptedAI
        {
            boss_anubshiahAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                _events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _events.ScheduleEvent(EVENT_SHADOWBOLT, 7000);
                _events.ScheduleEvent(EVENT_CURSE_OF_TONGUES, 24000);
                _events.ScheduleEvent(EVENT_CURSE_OF_WEAKNESS, 12000);
                _events.ScheduleEvent(EVENT_DEMON_ARMOR, 3000);
                _events.ScheduleEvent(EVENT_ENVELOPING_WEB, 16000);
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
                        case EVENT_SHADOWBOLT:
                            DoCast(me, SPELL_SHADOWBOLT);
                            _events.ScheduleEvent(EVENT_SHADOWBOLT, 7000);
                            break;
                        case EVENT_CURSE_OF_TONGUES:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                DoCast(target, SPELL_CURSEOFTONGUES);
                            _events.ScheduleEvent(EVENT_CURSE_OF_TONGUES, 18000);
                            break;
                        case EVENT_CURSE_OF_WEAKNESS:
                            DoCastVictim(SPELL_CURSEOFWEAKNESS);
                            _events.ScheduleEvent(EVENT_CURSE_OF_WEAKNESS, 45000);
                            break;
                        case EVENT_DEMON_ARMOR:
                            DoCast(me, SPELL_DEMONARMOR);
                            _events.ScheduleEvent(EVENT_DEMON_ARMOR, 300000);
                            break;
                        case EVENT_ENVELOPING_WEB:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                DoCast(target, SPELL_ENVELOPINGWEB);
                            _events.ScheduleEvent(EVENT_ENVELOPING_WEB, 12000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_anubshiahAI(creature);
        }
};

void AddSC_boss_anubshiah()
{
    new boss_anubshiah();
}
