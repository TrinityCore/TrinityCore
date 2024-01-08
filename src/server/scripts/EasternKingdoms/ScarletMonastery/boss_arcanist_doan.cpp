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

#include "scarlet_monastery.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"

enum ArcanistDoanYells
{
    SAY_AGGRO = 0,
    SAY_SPECIALAE = 1
};

enum ArcanistDoanSpells
{
    SPELL_SILENCE = 8988,
    SPELL_ARCANE_EXPLOSION = 9433,
    SPELL_DETONATION = 9435,
    SPELL_ARCANE_BUBBLE = 9438,
    SPELL_POLYMORPH = 13323
};

enum ArcanistDoanEvents
{
    EVENT_SILENCE = 1,
    EVENT_ARCANE_EXPLOSION,
    EVENT_ARCANE_BUBBLE,
    EVENT_POLYMORPH
};

struct boss_arcanist_doan : public BossAI
{
    boss_arcanist_doan(Creature* creature) : BossAI(creature, DATA_ARCANIST_DOAN)
    {
        _healthAbove50Pct = true;
    }

    void Reset() override
    {
        _Reset();
        _healthAbove50Pct = true;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_SILENCE, 15s);
        events.ScheduleEvent(EVENT_ARCANE_EXPLOSION, 3s);
        events.ScheduleEvent(EVENT_POLYMORPH, 30s);
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
                case EVENT_SILENCE:
                    DoCastVictim(SPELL_SILENCE);
                    events.Repeat(15s, 20s);
                    break;
                case EVENT_ARCANE_EXPLOSION:
                    DoCastVictim(SPELL_ARCANE_EXPLOSION);
                    events.Repeat(8s);
                    break;
                case EVENT_POLYMORPH:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 30.0f, true))
                        DoCast(target, SPELL_POLYMORPH);
                    events.Repeat(20s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        if (_healthAbove50Pct && HealthBelowPct(50))
        {
            _healthAbove50Pct = false;
            Talk(SAY_SPECIALAE);
            DoCastSelf(SPELL_ARCANE_BUBBLE);
            DoCastAOE(SPELL_DETONATION);
        }
    }

private:
    bool _healthAbove50Pct;
};

void AddSC_boss_arcanist_doan()
{
    RegisterScarletMonasteryCreatureAI(boss_arcanist_doan);
}
