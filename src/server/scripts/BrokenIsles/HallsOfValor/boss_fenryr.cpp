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
#include "halls_of_valor.h"

enum fenryrSpells
{
    SPELL_CLAW_FRENZY           = 196512,
    SPELL_RAVENOUS_LEAP_DAMAGE  = 196496,
    SPELL_RAVENOUS_LEAP_DOT     = 196497,
    SPELL_RAVENOUS_LEAP_JUMP    = 196495,
    SPELL_RAVENOUS_LEAP_WARN    = 197556,
    SPELL_RAVENOUS_LEAP_CAST    = 197560,
    SPELL_SCENT_OF_BLOOD_2      = 196838,
    SPELL_SCENT_OF_BLOOD        = 196801,
    SPELL_UNNERVING_HOWL        = 196543,
};

enum fenryrEvents
{
    EVENT_CLAW_FRENZY = 1,
    EVENT_RAVENOUS_LEAP,
    EVENT_RAVENOUS_LEAP_2,
    EVENT_RAVENOUS_LEAP_3,
    EVENT_SCENT_OF_BLOOD,
    EVENT_UNNERVING_HOWL,
    EVENT_FLEE_TO_DEN,
    EVENT_AT_DEN,
};

const Position fenryrDen[] =
{
    { 2922.050f, 3235.689f, 581.794f, 6.0570f },
};

struct boss_fenryr : public BossAI
{
    boss_fenryr(Creature* creature) : BossAI(creature, DATA_FENRYR)
    {
        me->SetReactState(REACT_DEFENSIVE);
        me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
        me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
        me->SetCanFly(false);
    }

    bool phase2 = false;
    bool phaseStarted = false;
    bool secondCombatStart = false;

    void Reset() override
    {
        _Reset();

        me->SetReactState(REACT_DEFENSIVE);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();

        events.ScheduleEvent(EVENT_UNNERVING_HOWL, 8 * IN_MILLISECONDS);
        events.ScheduleEvent(EVENT_RAVENOUS_LEAP, 15 * IN_MILLISECONDS);
    }

    void InSecondPhaseStart()
    {
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
        me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
        me->AttackStop();

        me->GetMotionMaster()->MovePoint(0, fenryrDen[0]);
        me->SetWalk(false);
        me->SetSpeedRate(MOVE_RUN, 2.0f);

        events.ScheduleEvent(EVENT_FLEE_TO_DEN, 1 * IN_MILLISECONDS);
        phase2 = true;
        phaseStarted = true;
    }

    void InSecondPhaseCombatStart()
    {
        me->SetReactState(REACT_DEFENSIVE);
        me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
        me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
        me->SetInCombatWithZone();
    }

    void RegenerateHeal()
    {
        uint32 health = me->GetHealth();

        if (!health)
            return;

        health *= 1.0f;

        me->SetHealth(health);
    }

    void UpdateAI(uint32 diff) override
    {
        if (phaseStarted)
        {
            if (me->GetDistance2d(fenryrDen[0].GetPositionX(), fenryrDen[0].GetPositionY()) < 5.0f)
            {
                RegenerateHeal();
                me->SetOrientation(6.0570f);
                me->SetReactState(REACT_DEFENSIVE);
                me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                me->CastSpell(me, 31539, true);
                phaseStarted = false;
            }
            else
                return;
        }

        if (me->SelectNearestPlayer(5.0f) != nullptr)
        {
            if (!secondCombatStart && phase2)
            {
                secondCombatStart = true;
                me->RemoveAurasDueToSpell(31539);
            }
        }

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (!phase2 && me->GetHealthPct() <= 60)
            InSecondPhaseStart();

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CLAW_FRENZY:
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 50.0f, true, 0))
                        me->CastSpell(target, SPELL_CLAW_FRENZY, true);
                    break;
                }
                case EVENT_FLEE_TO_DEN:
                {
                    events.ScheduleEvent(EVENT_AT_DEN, 1 * IN_MILLISECONDS);
                    break;
                }
                case EVENT_AT_DEN:
                {
                    phaseStarted = true;
                    break;
                }
                case EVENT_RAVENOUS_LEAP:
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, 0))
                        me->CastSpell(target, SPELL_RAVENOUS_LEAP_CAST, true);

                    if (!phase2 || me->GetReactState() == REACT_PASSIVE)
                        events.ScheduleEvent(EVENT_RAVENOUS_LEAP_2, 1 * IN_MILLISECONDS);
                    break;
                }
                case EVENT_RAVENOUS_LEAP_2:
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, 0))
                        me->CastSpell(target, SPELL_RAVENOUS_LEAP_JUMP, true);

                    if (phase2)
                        events.ScheduleEvent(EVENT_RAVENOUS_LEAP_3, 1 * IN_MILLISECONDS);
                    else
                        events.ScheduleEvent(EVENT_RAVENOUS_LEAP, 22 * IN_MILLISECONDS);
                    break;
                }
                case EVENT_RAVENOUS_LEAP_3:
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, 0))
                        me->CastSpell(target, SPELL_RAVENOUS_LEAP_JUMP, true);

                    events.ScheduleEvent(EVENT_RAVENOUS_LEAP, 22 * IN_MILLISECONDS);
                    break;
                }
                case EVENT_SCENT_OF_BLOOD:
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100.0f, true, 0))
                    {
                        me->CastSpell(target, SPELL_SCENT_OF_BLOOD_2, true);
                        me->AddAura(SPELL_SCENT_OF_BLOOD, target);
                    }

                    break;
                }
                case EVENT_UNNERVING_HOWL:
                {
                    DoCast(SPELL_UNNERVING_HOWL);

                    events.ScheduleEvent(EVENT_UNNERVING_HOWL, 12 * IN_MILLISECONDS);
                    break;
                }
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

// 196495 - Ravenous Leap Jump
class spell_ravenous_leap_jump : public SpellScript
{
    PrepareSpellScript(spell_ravenous_leap_jump);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (!GetCaster() || !GetHitUnit())
            return;

        GetCaster()->CastSpell(GetCaster(), SPELL_RAVENOUS_LEAP_DAMAGE, true);
        GetCaster()->CastSpell(GetHitUnit(), SPELL_RAVENOUS_LEAP_DOT, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ravenous_leap_jump::HandleDummy, EFFECT_0, SPELL_EFFECT_JUMP);
    }
};

// 197560 - Ravenous Leap Cast
class spell_ravenous_leap : public SpellScript
{
    PrepareSpellScript(spell_ravenous_leap);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (!GetCaster() || GetHitUnit())
            return;

        GetCaster()->CastSpell(GetHitUnit(), SPELL_RAVENOUS_LEAP_JUMP, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ravenous_leap::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_fenryr()
{
    RegisterCreatureAI(boss_fenryr);
    RegisterSpellScript(spell_ravenous_leap_jump);
    RegisterSpellScript(spell_ravenous_leap);
}
