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
#include "ScriptedCreature.h"
#include "razorfen_downs.h"

enum Spells
{
    SPELL_THRASH             = 8876,
    SPELL_WEB_SPRAY          = 12252,
    SPELL_VIRULENT_POISON    = 12254,
    SPELL_CURSE_OF_TUTENKASH = 12255
};

enum Events
{
    EVENT_WEB_SPRAY          = 1,
    EVENT_CURSE_OF_TUTENKASH = 2
};

class boss_tuten_kash : public CreatureScript
{
public:
    boss_tuten_kash() : CreatureScript("boss_tuten_kash") { }

    struct boss_tuten_kashAI : public BossAI
    {
        boss_tuten_kashAI(Creature* creature) : BossAI(creature, DATA_TUTEN_KASH) { }

        void Reset() override
        {
            _Reset();
            if (!me->HasAura(SPELL_THRASH))
                DoCast(me, SPELL_THRASH);
            if (!me->HasAura(SPELL_VIRULENT_POISON))
                DoCast(me, SPELL_VIRULENT_POISON);
        }

        void JustEngagedWith(Unit* who) override
        {
            BossAI::JustEngagedWith(who);
            events.ScheduleEvent(EVENT_WEB_SPRAY, 3s, 5s);
            events.ScheduleEvent(EVENT_CURSE_OF_TUTENKASH, 9s, 14s);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
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
                    case EVENT_WEB_SPRAY:
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100, false))
                        {
                            if (!target->HasAura(SPELL_WEB_SPRAY))
                                DoCast(target, SPELL_WEB_SPRAY);
                        }
                        events.ScheduleEvent(EVENT_WEB_SPRAY, 6s, 8s);
                        break;
                    case EVENT_CURSE_OF_TUTENKASH:
                        DoCast(me, SPELL_CURSE_OF_TUTENKASH);
                        events.ScheduleEvent(EVENT_CURSE_OF_TUTENKASH, 15s, 25s);
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetRazorfenDownsAI<boss_tuten_kashAI>(creature);
    }
};

void AddSC_boss_tuten_kash()
{
    new boss_tuten_kash();
}
