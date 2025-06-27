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
#include "halls_of_stone.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellMgr.h"

enum Texts
{
    SAY_AGGRO                           = 0,
    SAY_SLAY                            = 1,
    SAY_DEATH                           = 2,
    SAY_STUN                            = 3
};

enum Spells
{
    SPELL_PARTING_SORROW                = 59723,
    SPELL_STORM_OF_GRIEF                = 50752,
    SPELL_SHOCK_OF_SORROW               = 50760,
    SPELL_PILLAR_OF_WOE                 = 50761
};

enum Events
{
    EVENT_PARTING_SORROW                = 1,
    EVENT_STORM_OF_GRIEF,
    EVENT_SHOCK_OF_SORROW,
    EVENT_PILLAR_OF_WOE
};

enum Achievements
{
    ACHIEV_GOOD_GRIEF_START_EVENT       = 20383,
};

struct boss_maiden_of_grief : public BossAI
{
    boss_maiden_of_grief(Creature* creature) : BossAI(creature, DATA_MAIDEN_OF_GRIEF) { }

    void Reset() override
    {
        _Reset();

        instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_GOOD_GRIEF_START_EVENT);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);

        if (IsHeroic())
            events.ScheduleEvent(EVENT_PARTING_SORROW, 25s, 30s);
        events.ScheduleEvent(EVENT_STORM_OF_GRIEF, 5s, 10s);
        events.ScheduleEvent(EVENT_SHOCK_OF_SORROW, 15s, 25s);
        events.ScheduleEvent(EVENT_PILLAR_OF_WOE, 5s, 15s);

        instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_GOOD_GRIEF_START_EVENT);
    }

    void KilledUnit(Unit* /*who*/) override
    {
        Talk(SAY_SLAY);
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == sSpellMgr->GetSpellIdForDifficulty(SPELL_SHOCK_OF_SORROW, me))
            Talk(SAY_STUN);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
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
                case EVENT_PARTING_SORROW:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                        DoCast(target, SPELL_PARTING_SORROW);
                    events.Repeat(30s, 40s);
                    break;
                case EVENT_STORM_OF_GRIEF:
                    DoCastVictim(SPELL_STORM_OF_GRIEF);
                    events.Repeat(15s, 20s);
                    break;
                case EVENT_SHOCK_OF_SORROW:
                    DoCastAOE(SPELL_SHOCK_OF_SORROW);
                    events.Repeat(20s, 35s);
                    break;
                case EVENT_PILLAR_OF_WOE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 0.0f, true))
                        DoCast(target, SPELL_PILLAR_OF_WOE);
                    else
                        DoCastVictim(SPELL_PILLAR_OF_WOE);
                    events.Repeat(5s, 25s);
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

void AddSC_boss_maiden_of_grief()
{
    RegisterHallsOfStoneCreatureAI(boss_maiden_of_grief);
}
