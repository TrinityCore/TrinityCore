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

/*
 * Timers requires to be revisited, especially Void Bolt, not sure how exactly it is used
 * SAY_UNK_1 is used (sniffs), but the exact purpose is unknown. SAY_UNK_2 maybe is used, maybe not, exact purpose is unknown
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum KazzakTexts
{
    SAY_INTRO                       = 0,
    SAY_AGGRO                       = 1,
    SAY_SURPREME                    = 2,
    SAY_SLAY                        = 3,
    SAY_DEATH                       = 4,
    SAY_SOUL                        = 5,
    EMOTE_FRENZY                    = 6,
    SAY_UNK_1                       = 7,
    SAY_UNK_2                       = 8
};

enum KazzakSpells
{
    // Initial
    SPELL_CAPTURE_SOUL              = 48473,

    // Combat
    SPELL_CLEAVE                    = 16044,
    SPELL_TWISTED_REFLECTION        = 21063,
    SPELL_VOID_BOLT                 = 21066,
    SPELL_MARK_OF_KAZZAK            = 32960,
    SPELL_SHADOW_BOLT_VOLLEY        = 32963,
    SPELL_FRENZY                    = 32964,
    SPELL_THUNDERCLAP               = 36706,
    SPELL_BERSERK                   = 32965,

    // Scripts
    SPELL_MARK_OF_KAZZAK_DAMAGE     = 32961,
    SPELL_TWISTED_REFLECTION_HEAL   = 21064
};

enum KazzakEvents
{
    EVENT_CLEAVE                    = 1,
    EVENT_TWISTED_REFLECTION,
    EVENT_VOID_BOLT,
    EVENT_MARK_OF_KAZZAK,
    EVENT_SHADOW_BOLT_VOLLEY,
    EVENT_FRENZY,
    EVENT_THUNDERCLAP,
    EVENT_BERSERK
};

// 18728 - Doom Lord Kazzak
struct boss_doom_lord_kazzak : public WorldBossAI
{
    using WorldBossAI::WorldBossAI;

    void JustAppeared() override
    {
        Talk(SAY_INTRO);
    }

    void JustEngagedWith(Unit* who) override
    {
        WorldBossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        DoCastSelf(SPELL_CAPTURE_SOUL);

        events.ScheduleEvent(EVENT_CLEAVE, 10s, 15s);
        events.ScheduleEvent(EVENT_TWISTED_REFLECTION, 15s, 25s);
        events.ScheduleEvent(EVENT_VOID_BOLT, 10s);
        events.ScheduleEvent(EVENT_MARK_OF_KAZZAK, 10s, 20s);
        events.ScheduleEvent(EVENT_SHADOW_BOLT_VOLLEY, 5s, 15s);
        events.ScheduleEvent(EVENT_FRENZY, 1min);
        events.ScheduleEvent(EVENT_THUNDERCLAP, 10s, 25s);
        events.ScheduleEvent(EVENT_BERSERK, 3min);
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_FRENZY:
                Talk(EMOTE_FRENZY);
                Talk(SAY_SURPREME);
                break;
            case SPELL_BERSERK:
                Talk(SAY_SURPREME);
                break;
            default:
                break;
        }
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() != TYPEID_PLAYER)
            return;

        Talk(SAY_SLAY);
    }

    void JustDied(Unit* killer) override
    {
        WorldBossAI::JustDied(killer);

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
                case EVENT_CLEAVE:
                    DoCastVictim(SPELL_CLEAVE);
                    events.Repeat(10s, 15s);
                    break;
                case EVENT_TWISTED_REFLECTION:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                        DoCast(target, SPELL_TWISTED_REFLECTION);
                    events.Repeat(15s, 30s);
                    break;
                case EVENT_VOID_BOLT:
                    if (!me->IsWithinMeleeRange(me->GetVictim()))
                        DoCastVictim(SPELL_VOID_BOLT);
                    events.Repeat(2s);
                    break;
                case EVENT_MARK_OF_KAZZAK:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, [](Unit const* unit) { return unit && unit->IsPlayer() && unit->GetPowerType() == POWER_MANA && !unit->HasAura(SPELL_MARK_OF_KAZZAK); }))
                        DoCast(target, SPELL_MARK_OF_KAZZAK);
                    events.Repeat(10s, 25s);
                    break;
                case EVENT_SHADOW_BOLT_VOLLEY:
                    DoCastSelf(SPELL_SHADOW_BOLT_VOLLEY);
                    events.Repeat(10s, 25s);
                    break;
                case EVENT_FRENZY:
                    DoCastSelf(SPELL_FRENZY);
                    events.Repeat(60s);
                    break;
                case EVENT_THUNDERCLAP:
                    DoCastSelf(SPELL_THUNDERCLAP);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

// 32960 - Mark of Kazzak
class spell_doom_lord_kazzak_mark_of_kazzak : public AuraScript
{
    PrepareAuraScript(spell_doom_lord_kazzak_mark_of_kazzak);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MARK_OF_KAZZAK_DAMAGE });
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        if (Unit* owner = GetUnitOwner())
            amount = CalculatePct(owner->GetMaxPower(POWER_MANA), 5);
    }

    void OnPeriodic(AuraEffect const* aurEff)
    {
        Unit* target = GetTarget();

        if (target->GetPowerPct(POWER_MANA) < 5.0f)
        {
            target->CastSpell(target, SPELL_MARK_OF_KAZZAK_DAMAGE, aurEff);
            Remove();
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_doom_lord_kazzak_mark_of_kazzak::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_MANA_LEECH);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_doom_lord_kazzak_mark_of_kazzak::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_MANA_LEECH);
    }
};

// 21063 - Twisted Reflection
class spell_doom_lord_kazzak_twisted_reflection : public AuraScript
{
    PrepareAuraScript(spell_doom_lord_kazzak_twisted_reflection);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TWISTED_REFLECTION_HEAL });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        DamageInfo* damageInfo = eventInfo.GetDamageInfo();
        if (!damageInfo || !damageInfo->GetDamage())
            return;

        eventInfo.GetActionTarget()->CastSpell(eventInfo.GetActor(), SPELL_TWISTED_REFLECTION_HEAL, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_doom_lord_kazzak_twisted_reflection::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 48473 - Capture Soul
class spell_doom_lord_kazzak_capture_soul : public AuraScript
{
    PrepareAuraScript(spell_doom_lord_kazzak_capture_soul);

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        if (Creature* actor = eventInfo.GetActor()->ToCreature())
            actor->AI()->Talk(SAY_SOUL, eventInfo.GetActionTarget());
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_doom_lord_kazzak_capture_soul::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

void AddSC_boss_doomlordkazzak()
{
    RegisterCreatureAI(boss_doom_lord_kazzak);
    RegisterSpellScript(spell_doom_lord_kazzak_mark_of_kazzak);
    RegisterSpellScript(spell_doom_lord_kazzak_twisted_reflection);
    RegisterSpellScript(spell_doom_lord_kazzak_capture_soul);
}
