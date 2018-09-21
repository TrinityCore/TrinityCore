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
#include "CreatureTextMgr.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "ruins_of_ahnqiraj.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_MORTALWOUND       = 25646,
    SPELL_SANDTRAP          = 25648,
    SPELL_ENRAGE            = 26527,
    SPELL_SUMMON_PLAYER     = 26446,
    SPELL_TRASH             =  3391, // Should perhaps be triggered by an aura? Couldn't find any though
    SPELL_WIDE_SLASH        = 25814
};

enum Events
{
    EVENT_MORTAL_WOUND      = 1,
    EVENT_SANDTRAP          = 2,
    EVENT_TRASH             = 3,
    EVENT_WIDE_SLASH        = 4
};

enum Texts
{
    SAY_KURINAXX_DEATH      = 5, // Yelled by Ossirian the Unscarred
};

class boss_kurinnaxx : public CreatureScript
{
    public:
        boss_kurinnaxx() : CreatureScript("boss_kurinnaxx") { }

        struct boss_kurinnaxxAI : public BossAI
        {
            boss_kurinnaxxAI(Creature* creature) : BossAI(creature, DATA_KURINNAXX)
            {
                Initialize();
            }

            void Initialize()
            {
                _enraged = false;
            }

            void Reset() override
            {
                _Reset();
                Initialize();
                events.ScheduleEvent(EVENT_MORTAL_WOUND, 8000);
                events.ScheduleEvent(EVENT_SANDTRAP, urand(5000, 15000));
                events.ScheduleEvent(EVENT_TRASH, 1000);
                events.ScheduleEvent(EVENT_WIDE_SLASH, 11000);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
            {
                if (!_enraged && HealthBelowPct(30))
                {
                    DoCast(me, SPELL_ENRAGE);
                    _enraged = true;
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                if (Creature* Ossirian = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_OSSIRIAN)))
                    sCreatureTextMgr->SendChat(Ossirian, SAY_KURINAXX_DEATH, NULL, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_ZONE);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MORTAL_WOUND:
                            DoCastVictim(SPELL_MORTALWOUND);
                            events.ScheduleEvent(EVENT_MORTAL_WOUND, 8000);
                            break;
                        case EVENT_SANDTRAP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                target->CastSpell(target, SPELL_SANDTRAP, true);
                            else if (Unit* victim = me->GetVictim())
                                victim->CastSpell(victim, SPELL_SANDTRAP, true);
                            events.ScheduleEvent(EVENT_SANDTRAP, urand(5000, 15000));
                            break;
                        case EVENT_WIDE_SLASH:
                            DoCast(me, SPELL_WIDE_SLASH);
                            events.ScheduleEvent(EVENT_WIDE_SLASH, 11000);
                            break;
                        case EVENT_TRASH:
                            DoCast(me, SPELL_TRASH);
                            events.ScheduleEvent(EVENT_WIDE_SLASH, 16000);
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }
            private:
                bool _enraged;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAQ20AI<boss_kurinnaxxAI>(creature);
        }
};

void AddSC_boss_kurinnaxx()
{
    new boss_kurinnaxx();
}
