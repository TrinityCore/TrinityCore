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

/* Timers requires to be revisited */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "magisters_terrace.h"
#include "MotionMaster.h"

enum VexallusTexts
{
    SAY_AGGRO                       = 0,
    SAY_ENERGY                      = 1,
    SAY_OVERLOAD                    = 2,
    SAY_SLAY                        = 3,
    EMOTE_DISCHARGE_ENERGY          = 4,
    EMOTE_OVERLOAD                  = 5
};

enum VexallusSpells
{
    // Vexallus
    SPELL_CHAIN_LIGHTNING           = 44318,
    SPELL_ARCANE_SHOCK              = 44319,
    SPELL_OVERLOAD                  = 44353,

    SPELL_SUMMON_PURE_ENERGY        = 44322,
    SPELL_SUMMON_PURE_ENERGY_H_1    = 46154,
    SPELL_SUMMON_PURE_ENERGY_H_2    = 46159,

    SPELL_CLEAR_ENERGY_FEEDBACK     = 47108,

    // Pure Energy
    SPELL_ENERGY_BOLT_PERIODIC      = 46156,
    SPELL_PURE_ENERGY_PASSIVE       = 44326,
    SPELL_TRIGGER_000               = 36294,    // Triggers from 44326. NYI. Probably does what we did on creature death
    SPELL_ENERGY_FEEDBACK_PERIODIC  = 44328,
    SPELL_ENERGY_FEEDBACK           = 44335,
    SPELL_ENERGY_FEEDBACK_SCALE     = 44339
};

enum VexallusEvents
{
    EVENT_CHAIN_LIGHTNING           = 1,
    EVENT_ARCANE_SHOCK,
    EVENT_OVERLOAD
};

enum VexallusMisc
{
    INTERVAL_MODIFIER               = 15,
    INTERVAL_SWITCH                 = 6
};

// 24744 - Vexallus
struct boss_vexallus : public BossAI
{
    boss_vexallus(Creature* creature) : BossAI(creature, DATA_VEXALLUS), _intervalHealthAmount(1), _enraged(false) { }

    void Reset() override
    {
        _Reset();
        _intervalHealthAmount = 1;
        _enraged = false;
    }

    void JustEngagedWith(Unit* who) override
    {
        Talk(SAY_AGGRO);
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 8s);
        events.ScheduleEvent(EVENT_ARCANE_SHOCK, 5s);
    }

    void JustSummoned(Creature* summoned) override
    {
        if (Unit* temp = SelectTarget(SelectTargetMethod::Random, 0))
            summoned->GetMotionMaster()->MoveFollow(temp, 0, 0);

        summons.Summon(summoned);
    }

    void DamageTaken(Unit* /*who*/, uint32& /*damage*/, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (_enraged)
            return;

        // 85%, 70%, 55%, 40%, 25%
        if (!HealthAbovePct(100 - INTERVAL_MODIFIER * _intervalHealthAmount))
        {
            // increase amount, unless we're at 10%, then we switch and return
            if (_intervalHealthAmount == INTERVAL_SWITCH)
            {
                _enraged = true;
                events.Reset();
                events.ScheduleEvent(EVENT_OVERLOAD, 1200ms);
                Talk(SAY_OVERLOAD);
                Talk(EMOTE_OVERLOAD);
                return;
            }
            else
                ++_intervalHealthAmount;

            Talk(SAY_ENERGY);
            Talk(EMOTE_DISCHARGE_ENERGY);

            if (IsHeroic())
            {
                DoCastSelf(SPELL_SUMMON_PURE_ENERGY_H_1);
                DoCastSelf(SPELL_SUMMON_PURE_ENERGY_H_2);
            }
            else
                DoCastSelf(SPELL_SUMMON_PURE_ENERGY);
        }
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        DoCastSelf(SPELL_CLEAR_ENERGY_FEEDBACK, true);
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
                case EVENT_CHAIN_LIGHTNING:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                        DoCast(target, SPELL_CHAIN_LIGHTNING);
                    events.Repeat(8s);
                    break;
                case EVENT_ARCANE_SHOCK:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 20.0f, true))
                        DoCast(target, SPELL_ARCANE_SHOCK);
                    events.Repeat(8s);
                    break;
                case EVENT_OVERLOAD:
                    DoCastSelf(SPELL_OVERLOAD);
                    events.Repeat(2s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    uint32 _intervalHealthAmount;
    bool _enraged;
};

// 24745 - Pure Energy
struct npc_pure_energy : public ScriptedAI
{
    npc_pure_energy(Creature* creature) : ScriptedAI(creature)
    {
        me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
    }

    void JustDied(Unit* killer) override
    {
        // This is not correct as in sniff this spell was used not on killer
        if (killer)
            DoCast(killer, SPELL_ENERGY_FEEDBACK_PERIODIC, true);
        me->RemoveAurasDueToSpell(SPELL_ENERGY_BOLT_PERIODIC);
    }
};

// 44328 - Energy Feedback
class spell_vexallus_energy_feedback : public AuraScript
{
    PrepareAuraScript(spell_vexallus_energy_feedback);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ENERGY_FEEDBACK, SPELL_ENERGY_FEEDBACK_SCALE });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_ENERGY_FEEDBACK, true);
    }

    void OnPeriodic(AuraEffect const* aurEff)
    {
        Creature* caster = GetCaster()->ToCreature();
        if (!caster)
            return;

        switch (aurEff->GetTickNumber())
        {
            case 1:
            case 2:
            case 3:
            case 4:
                caster->CastSpell(caster, SPELL_ENERGY_FEEDBACK_SCALE, true);
                break;
            case 5:
                caster->CastSpell(caster, SPELL_ENERGY_FEEDBACK_SCALE, true);
                caster->DespawnOrUnsummon();
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_vexallus_energy_feedback::AfterApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_vexallus_energy_feedback::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 47108 - Clear Energy Feedback
class spell_vexallus_clear_energy_feedback : public SpellScript
{
    PrepareSpellScript(spell_vexallus_clear_energy_feedback);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ENERGY_FEEDBACK });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->RemoveAurasDueToSpell(SPELL_ENERGY_FEEDBACK);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_vexallus_clear_energy_feedback::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_vexallus()
{
    RegisterMagistersTerraceCreatureAI(boss_vexallus);
    RegisterMagistersTerraceCreatureAI(npc_pure_energy);
    RegisterSpellScript(spell_vexallus_energy_feedback);
    RegisterSpellScript(spell_vexallus_clear_energy_feedback);
}
