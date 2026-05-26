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
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum KrystallusTexts
{
    SAY_AGGRO                = 0,
    SAY_SLAY                 = 1,
    SAY_DEATH                = 2,
    SAY_SHATTER              = 3
};

enum KrystallusSpells
{
    SPELL_BOULDER_TOSS       = 50843,
    SPELL_GROUND_SPIKE       = 59750,
    SPELL_GROUND_SLAM        = 50827,
    SPELL_SHATTER            = 50810,
    SPELL_SHATTER_EFFECT     = 50811,
    SPELL_STONED             = 50812,
    SPELL_STOMP              = 48131
};

enum KrystallusEvents
{
    EVENT_BOULDER_TOSS       = 1,
    EVENT_GROUND_SPIKE,
    EVENT_GROUND_SLAM,
    EVENT_STOMP,
    EVENT_SHATTER
};

// 27977 - Krystallus
struct boss_krystallus : public BossAI
{
    boss_krystallus(Creature* creature) : BossAI(creature, DATA_KRYSTALLUS) { }

    void JustEngagedWith(Unit* who) override
    {
        Talk(SAY_AGGRO);
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_BOULDER_TOSS, 3s, 9s);
        events.ScheduleEvent(EVENT_GROUND_SLAM, 15s, 18s);
        events.ScheduleEvent(EVENT_STOMP, 20s, 29s);
        if (IsHeroic())
            events.ScheduleEvent(EVENT_GROUND_SPIKE, 9s, 14s);
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == sSpellMgr->GetSpellIdForDifficulty(SPELL_SHATTER, me))
            Talk(SAY_SHATTER);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
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
                case EVENT_BOULDER_TOSS:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 50.0f, true))
                        DoCast(target, SPELL_BOULDER_TOSS);
                    events.Repeat(9s, 15s);
                    break;
                case EVENT_GROUND_SPIKE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                        DoCast(target, SPELL_GROUND_SPIKE);
                    events.Repeat(12s, 17s);
                    break;
                case EVENT_GROUND_SLAM:
                    DoCastSelf(SPELL_GROUND_SLAM);
                    events.ScheduleEvent(EVENT_SHATTER, 10s);
                    events.Repeat(15s, 18s);
                    break;
                case EVENT_STOMP:
                    DoCastSelf(SPELL_STOMP);
                    events.Repeat(20s, 29s);
                    break;
                case EVENT_SHATTER:
                    DoCastSelf(SPELL_SHATTER);
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

// 50810, 61546 - Shatter
class spell_krystallus_shatter : public SpellScript
{
    PrepareSpellScript(spell_krystallus_shatter);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
        {
            target->RemoveAurasDueToSpell(SPELL_STONED);
            target->CastSpell(nullptr, SPELL_SHATTER_EFFECT, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_krystallus_shatter::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 50811, 61547 - Shatter
class spell_krystallus_shatter_effect : public SpellScript
{
    PrepareSpellScript(spell_krystallus_shatter_effect);

    void CalculateDamage()
    {
        if (!GetHitUnit())
            return;

        float radius = GetEffectInfo(EFFECT_0).CalcRadius(GetCaster());
        if (!radius)
            return;

        float distance = GetCaster()->GetDistance2d(GetHitUnit());
        if (distance > 1.0f)
            SetHitDamage(int32(GetHitDamage() * ((radius - distance) / radius)));
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_krystallus_shatter_effect::CalculateDamage);
    }
};

void AddSC_boss_krystallus()
{
    RegisterHallsOfStoneCreatureAI(boss_krystallus);
    RegisterSpellScript(spell_krystallus_shatter);
    RegisterSpellScript(spell_krystallus_shatter_effect);
}
