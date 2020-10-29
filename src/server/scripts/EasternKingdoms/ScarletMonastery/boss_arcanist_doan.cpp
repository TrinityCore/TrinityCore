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
#include "scarlet_monastery.h"

enum Yells
{
    SAY_AGGRO       = 0,
    SAY_DETONATION  = 1
};

enum Spells
{
    SPELL_DETONATION        = 9435,
    SPELL_SILENCE           = 8988,
    SPELL_ARCANE_EXPLOSION  = 9433,
    SPELL_ARCANE_BUBBLE     = 9438,
    SPELL_POLYMORPH         = 13323
};

enum Events
{
    EVENT_DETONATION = 1,
    EVENT_SILENCE,
    EVENT_ARCANE_EXPLOSION,
    EVENT_ARCANE_BUBBLE,
    EVENT_POLYMORPH
};

struct boss_arcanist_doan : public BossAI
{
    boss_arcanist_doan(Creature* creature) : BossAI(creature, DATA_ARCANIST_DOAN), _detonationTriggered(false) { }

    void Reset() override
    {
        _Reset();
        _detonationTriggered = false;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_SILENCE, 6s);
        events.ScheduleEvent(EVENT_ARCANE_EXPLOSION, 11s);
        events.ScheduleEvent(EVENT_POLYMORPH, 45s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (!_detonationTriggered && me->HealthBelowPctDamaged(50, damage))
        {
            events.ScheduleEvent(EVENT_ARCANE_BUBBLE, 1ms);
            _detonationTriggered = true;
        }
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
                case EVENT_DETONATION:
                    Talk(SAY_DETONATION);
                    DoCastAOE(SPELL_DETONATION);
                    events.DelayEvents(3s);
                    break;
                case EVENT_SILENCE:
                    DoCastAOE(SPELL_SILENCE);
                    events.Repeat(21s, 24s);
                    break;
                case EVENT_ARCANE_EXPLOSION:
                    DoCastAOE(SPELL_ARCANE_EXPLOSION);
                    events.Repeat(4s, 14s);
                    break;
                case EVENT_ARCANE_BUBBLE:
                    DoCastSelf(SPELL_ARCANE_BUBBLE);
                    me->resetAttackTimer();
                    events.ScheduleEvent(EVENT_DETONATION, 1s);
                    break;
                case EVENT_POLYMORPH:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.f, true))
                        DoCast(target, SPELL_POLYMORPH);
                    events.Repeat(20s); // To-do: validate
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    bool _detonationTriggered;
};


void AddSC_boss_arcanist_doan()
{
    RegisterScarletMonasteryCreatureAI(boss_arcanist_doan);
}
