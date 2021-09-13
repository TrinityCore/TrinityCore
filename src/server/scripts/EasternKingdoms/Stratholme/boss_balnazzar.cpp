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
#include "stratholme.h"

enum Spells
{
    // Balnazzar
    SPELL_MINDBLAST                 = 80750,
    SPELL_PSYCHIC_SCREAM            = 13704,
    SPELL_SLEEP                     = 66290,
    SPELL_DOMINATION                = 17405,
    SPELL_SHADOW_SHOCK              = 17399
};

enum Events
{
    EVENT_MIND_BLAST = 1,
    EVENT_SLEEP,
    EVENT_PSYCHIC_SCREAM,
    EVENT_DOMINATION,
    EVENT_SHADOW_SHOCK,
};

enum Texts
{
    SAY_AGGRO = 0,
    SAY_DEATH = 1,
};

struct boss_balnazzar : public BossAI
{
    boss_balnazzar(Creature* creature) : BossAI(creature, DATA_BALNAZZAR) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO, who);
        events.ScheduleEvent(EVENT_MIND_BLAST, 7s);
        events.ScheduleEvent(EVENT_SLEEP, 11s);
        events.ScheduleEvent(EVENT_PSYCHIC_SCREAM, 21s);
        events.ScheduleEvent(EVENT_DOMINATION, 30s);
        events.ScheduleEvent(EVENT_SHADOW_SHOCK, 33s);
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);
        Talk(SAY_DEATH, killer);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        _DespawnAtEvade();
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
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.f, false, false))
                        DoCast(target, SPELL_MINDBLAST);
                    else
                        DoCastVictim(SPELL_MINDBLAST);
                    events.Repeat(7s);
                    break;
                case EVENT_SLEEP:
                    DoCastVictim(SPELL_SLEEP);
                    events.Repeat(11s);
                    break;
                case EVENT_PSYCHIC_SCREAM:
                    DoCastAOE(SPELL_PSYCHIC_SCREAM);
                    events.RescheduleEvent(EVENT_MIND_BLAST, 6s);
                    events.Repeat(27s);
                    break;
                case EVENT_DOMINATION:
                    if (SelectTarget(SELECT_TARGET_RANDOM, 0, 30.f, false, false))
                        DoCastVictim(SPELL_DOMINATION);
                    events.Repeat(12s);
                    break;
                case EVENT_SHADOW_SHOCK:
                    DoCastAOE(SPELL_SHADOW_SHOCK);
                    // @TODO: need repeat timer
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

void AddSC_boss_balnazzar()
{
    RegisterStratholmeCreatureAI(boss_balnazzar);
}
