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
#include "tol_dagor.h"

enum Spells {
    SPELL_CRIP_SHIV = 257777,
    SPELL_HOWLING_FEAR = 257791,
    SPELL_FLASHING_DAGGER = 257785,
};

enum Events {
    EVENT_CRIP_SHIV = 1,
    EVENT_HOWLING_FEAR = 2,
    EVENT_FLASHING_DAGGER = 3,
};

//jes howlis 127484
struct boss_jes_howlis : public BossAI
{
    boss_jes_howlis(Creature* creature) : BossAI(creature, DATA_JES_HOWLIS) { }

    void InitializeAI() override
    {
        BossAI::InitializeAI();
    }

    void Reset() override
    {
        BossAI::Reset();
    }

    void EnterCombat(Unit* who) override
    {
        events.ScheduleEvent(EVENT_CRIP_SHIV, 7200);
        events.ScheduleEvent(EVENT_HOWLING_FEAR, 8500);
        events.ScheduleEvent(EVENT_FLASHING_DAGGER, 12100);
        BossAI::EnterCombat(who);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
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
            case EVENT_CRIP_SHIV:
                DoCastVictim(SPELL_CRIP_SHIV);
                events.ScheduleEvent(EVENT_CRIP_SHIV, 16100);
                break;
            case EVENT_HOWLING_FEAR:
                DoCastVictim(SPELL_HOWLING_FEAR);
                events.ScheduleEvent(EVENT_HOWLING_FEAR, 13400);
                break;
            case EVENT_FLASHING_DAGGER:
                DoCastVictim(SPELL_FLASHING_DAGGER);
                events.ScheduleEvent(EVENT_FLASHING_DAGGER, 31600);
                break;
            default:
                break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:

};

void AddSC_boss_jes_howlis()
{
    RegisterCreatureAI(boss_jes_howlis);
}
