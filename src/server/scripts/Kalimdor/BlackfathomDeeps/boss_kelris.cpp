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
#include "blackfathom_deeps.h"

enum Spells
{
    SPELL_MIND_BLAST             = 15587,
    SPELL_SLEEP                  = 8399,
    SPELL_BLACKFATHOM_CHANNELING = 8734
};

enum Texts
{
    SAY_AGGRO    = 0,
    SAY_SLEEP    = 1,
    SAY_DEATH    = 2
};

enum Events
{
    EVENT_MIND_BLAST = 1,
    EVENT_SLEEP
};

struct boss_kelris : public BossAI
{
    boss_kelris(Creature* creature) : BossAI(creature, DATA_KELRIS) { }

    void Reset() override
    {
        _Reset();
        DoCastSelf(SPELL_BLACKFATHOM_CHANNELING);
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        DoCastSelf(SPELL_BLACKFATHOM_CHANNELING);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        me->RemoveAurasDueToSpell(SPELL_BLACKFATHOM_CHANNELING);
        events.ScheduleEvent(EVENT_MIND_BLAST, 2s, 5s);
        events.ScheduleEvent(EVENT_SLEEP, 9s, 12s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
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
                case EVENT_MIND_BLAST:
                    DoCastVictim(SPELL_MIND_BLAST);
                    events.ScheduleEvent(EVENT_MIND_BLAST, 7s, 9s);
                    break;
                case EVENT_SLEEP:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100, true))
                    {
                        Talk(SAY_SLEEP);
                        DoCast(target, SPELL_SLEEP);
                    }
                    events.ScheduleEvent(EVENT_SLEEP, 15s, 20s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

void AddSC_boss_kelris()
{
    RegisterBlackfathomDeepsCreatureAI(boss_kelris);
}
