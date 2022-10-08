/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "world_bosses_zuldazar.h"

enum Events{
    EVENT_SHAKE_LOSE   = 1,
    EVENT_PRIMAL_RAGE  = 2,
    EVENT_SONIC_BELLOW = 3,
};

enum Spells {
    SPELL_SHAKE_LOSE          = 276046,
    SPELL_PRIMAL_RAGE         = 275200,
    SPELL_SONIC_BELLOW        = 275175,
    SPELL_SHAKE_LOSE_DMG      = 276055,
    SPELL_SHAKE_LOSE_SUMMON   = 276053,
    SPELL_SONIC_BELLOW_VISUAL = 275177,
};

struct boss_dunegorger_kraulok : public BossAI
{
    boss_dunegorger_kraulok(Creature* creature) : BossAI(creature, DATA_DUNEGORGER_KRAULOK) { }

    void InitializeAI() override
    {
        BossAI::InitializeAI();
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_SHAKE_LOSE)
        {
            me->CastSpell(target, SPELL_SHAKE_LOSE_DMG);
            me->CastSpell(target, SPELL_SHAKE_LOSE_SUMMON);
        }
        if (spell->Id == SPELL_SONIC_BELLOW)
            me->CastSpell(target, SPELL_SONIC_BELLOW_VISUAL);
    }

    void Reset() override
    {
        events.Reset();
        summons.DespawnAll();
    }

    void EnterCombat(Unit* who) override
    {
        BossAI::EnterCombat(who);

        //EVENTS
        events.ScheduleEvent(EVENT_SHAKE_LOSE, 25000);
        events.ScheduleEvent(EVENT_PRIMAL_RAGE, 39000);
        events.ScheduleEvent(EVENT_SONIC_BELLOW, 9000);
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
            case EVENT_SHAKE_LOSE:
            {
                me->CastSpell(me, SPELL_SHAKE_LOSE);
                if (me->HasAura(SPELL_PRIMAL_RAGE))
                {
                    events.ScheduleEvent(EVENT_SHAKE_LOSE, 15000);
                }
                else
                {
                    events.ScheduleEvent(EVENT_SHAKE_LOSE, 28000);
                }
                break;
            }
            case EVENT_PRIMAL_RAGE:
            {
                me->CastSpell(me, SPELL_PRIMAL_RAGE);
                events.ScheduleEvent(EVENT_PRIMAL_RAGE, 33000);
                break;
            }
            case EVENT_SONIC_BELLOW:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                    me->CastSpell(target, 275175);
                if (me->HasAura(SPELL_PRIMAL_RAGE))
                    events.ScheduleEvent(EVENT_SONIC_BELLOW, urand(15000, 20000));
                else
                {
                    events.ScheduleEvent(EVENT_SONIC_BELLOW, urand(25000, 30000));
                }
                break;
            }
            default:
                break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
};

void AddSC_boss_dunegorger_kraulok()
{
    RegisterCreatureAI(boss_dunegorger_kraulok);
}
