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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Creature.h"
#include "GridNotifiers.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "waycrest_manor.h"

enum HeartsbaneTriadSpells
{
    // Sister Briar
    SPELL_BRAMBLE_BOLT                       = 260701,
    SPELL_BRAMBLE_BOLT_ENHANCED              = 260697,
    SPELL_JAGGED_NETTLES                     = 260741,
    SPELL_IRONBARK_SHIELD                    = 261265,
    SPELL_AURA_OF_THORNS                     = 268122,
    SPELL_AURA_OF_THORNS_CHECK_PROC          = 268125,

    // Sister Malady
    SPELL_RUINOUS_BOLT                       = 260700,
    SPELL_RUINOUS_BOLT_ENHANCED              = 260696,
    SPELL_RUNIC_WARD                         = 261266,
    SPELL_UNSTABLE_RUNIC_MARK                = 260703,
    SPELL_UNSTABLE_RUNIC_MARK_DAMAGE         = 260702,
    SPELL_AURA_OF_DREAD                      = 268088,
    SPELL_AURA_OF_DREAD_DAMAGE               = 268086,
    SPELL_AURA_OF_DREAD_MOVE_CHECK           = 268085,

    // Sister Solena
    SPELL_SOUL_BOLT                          = 260699,
    SPELL_SOUL_BOLT_ENHANCED                 = 260698,
    SPELL_SOUL_ARMOR                         = 261264,
    SPELL_SOUL_MANIPULATION_SELECTOR         = 260907,
    SPELL_SOUL_MANIPULATION_CHARM            = 260900,
    SPELL_SOUL_MANIPULATION_DAMAGE_REDUCTION = 260923,
    SPELL_SOUL_MANIPULATION_VISUAL           = 260926,
    SPELL_AURA_OF_APATHY                     = 268077,
    SPELL_AURA_OF_APATHY_DEBUFF              = 268080,

    SPELL_DIRE_RITUAL                        = 260773,
    SPELL_CLAIM_THE_IRIS                     = 260852,
    SPELL_DROP_THE_IRIS                      = 260853,
    SPELL_FOCUSING_IRIS                      = 260805
};

enum HeartsbaneTriadTexts
{
    // Shared
    SAY_AGGRO               = 0,
    SAY_CLAIM_THE_IRIS      = 1,
    SAY_SLAY                = 3,
    SAY_DEATH               = 4,
    SAY_DIRE_RITUAL_ALERT   = 5,
    SAY_DIRE_RITUAL         = 6,

    // Sister Solena
    SAY_SOUL_MANIPULATION   = 2,

    // Sister Malady
    SAY_UNSTABLE_RUNIC_MARK = 2,

    // Sister Briar
    SAY_JAGGED_NETTLES      = 2
};

enum HeartsbaneTriadEvents
{
    // Sister Briar
    EVENT_BRAMBLE_BOLT          = 1,
    EVENT_BRAMBLE_BOLT_ENHANCED,
    EVENT_JAGGED_NETTLES,
    EVENT_AURA_OF_THORNS,

    // Sister Malady
    EVENT_RUINOUS_BOLT,
    EVENT_RUINOUS_BOLT_ENHANCED,
    EVENT_UNSTABLE_RUNIC_MARK,
    EVENT_AURA_OF_DREAD,

    // Sister Solena
    EVENT_SOUL_BOLT,
    EVENT_SOUL_BOLT_ENHANCED,
    EVENT_SOUL_MANIPULATION,
    EVENT_AURA_OF_APATHY,

    EVENT_CHECK_POWER,
    EVENT_CLAIM_IRIS,
};

enum HeartsbaneTriadActions
{
    ACTION_CLAIM_THE_IRIS_INTRO  = 1,
    ACTION_CLAIM_THE_IRIS,
};

enum HeartsbaneTriadSummonGroups
{
    SUMMON_GROUP_TRIAD_FOCUSING_IRIS = 0
};

uint32 const HeartsbaneTriadData[3] =
{
    DATA_SISTER_BRIAR,
    DATA_SISTER_MALADY,
    DATA_SISTER_SOLENA
};

namespace
{
void HeartsbaneTriadEncounterStart(InstanceScript* instance)
{
    if (instance->GetBossState(DATA_HEARTSBANE_TRIAD) == IN_PROGRESS)
        return;

    instance->SetBossState(DATA_HEARTSBANE_TRIAD, IN_PROGRESS);

    for (uint32 data : HeartsbaneTriadData)
    {
        if (Creature* sister = instance->GetCreature(data))
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, sister, 1);
            sister->AI()->DoZoneInCombat();
        }
    }
}

void HeartsbaneTriadEncounterFail(InstanceScript* instance, EvadeReason why, Creature* invoker)
{
    if (instance->GetBossState(DATA_HEARTSBANE_TRIAD) == FAIL)
        return;

    instance->SetBossState(DATA_HEARTSBANE_TRIAD, FAIL);

    for (uint32 data : HeartsbaneTriadData)
    {
        if (Creature* triad = instance->GetCreature(data))
        {
            if (triad == invoker)
                continue;

            triad->AI()->EnterEvadeMode(why);
        }
    }
}

void HeartsbaneTriadEncounterDone(InstanceScript* instance)
{
    if (instance->GetBossState(DATA_HEARTSBANE_TRIAD) == DONE)
        return;

    for (uint32 data : HeartsbaneTriadData)
    {
        if (Creature* sister = instance->GetCreature(data))
        {
            if (sister->IsAlive())
                return;
        }
    }

    for (uint32 data : HeartsbaneTriadData)
    {
        if (Creature* sister = instance->GetCreature(data))
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, sister);
    }

    instance->SetBossState(DATA_HEARTSBANE_TRIAD, DONE);
}
}

struct HeartsbaneTriadSharedAI : public BossAI
{
    HeartsbaneTriadSharedAI(Creature* creature, uint32 bossId) : BossAI(creature, bossId), _healthTriggered(false), _claimedIris(false)
    {
        SetBoundary(instance->GetBossBoundary(DATA_HEARTSBANE_TRIAD));
    }

    virtual void ScheduleEvents()
    {
        events.ScheduleEvent(EVENT_CHECK_POWER, 1000ms);
    };

    virtual void HandleDropIris(bool /*skipShieldPhase*/, bool /*skipIrisDrop*/)
    {
        _claimedIris = false;
    }

    virtual void HandleClaimIris()
    {
        _claimedIris = true;

        Talk(SAY_CLAIM_THE_IRIS);

        me->AttackStop();
        me->InterruptNonMeleeSpells(true);

        if (Creature* focusingIris = me->FindNearestCreature(NPC_FOCUSING_IRIS, 200.0f))
            me->CastSpell(focusingIris, SPELL_CLAIM_THE_IRIS);

        me->SetUnkillable(false);
    }

    void Reset() override
    {
        events.Reset();
        _healthTriggered = false;
        _claimedIris = false;
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        HeartsbaneTriadEncounterFail(instance, why, me);

        me->RemoveAurasDueToSpell(SPELL_FOCUSING_IRIS);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        summons.DespawnAll();
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->HealthBelowPctDamaged(50, damage) && !_healthTriggered)
        {
            _healthTriggered = true;
            me->AttackStop();
            me->InterruptNonMeleeSpells(true);

            me->SetUnkillable(true);

            HandleDropIris(false, !_claimedIris);
        }
    }

    void JustAppeared() override
    {
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 0);

        me->SetUnkillable(true);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        HeartsbaneTriadEncounterStart(instance);
        ScheduleEvents();
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_CHECK_POWER:
            {
                if (me->GetPower(POWER_ENERGY) >= 100)
                {
                    Talk(SAY_DIRE_RITUAL_ALERT);
                    Talk(SAY_DIRE_RITUAL);
                    DoCast(SPELL_DIRE_RITUAL);
                }
                events.Repeat(1000ms);
                break;
            }
            case EVENT_CLAIM_IRIS:
            {
                HandleClaimIris();
                break;
            }
            default:
                break;
        }
    }

    void DoAction(int32 actionId) override
    {
        switch (actionId)
        {
            case ACTION_CLAIM_THE_IRIS:
                events.Reset();
                events.ScheduleEvent(EVENT_CLAIM_IRIS, 1500ms);
                break;
            default:
                break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();

        Talk(SAY_DEATH);

        HeartsbaneTriadEncounterDone(instance);
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        Talk(SAY_SLAY);
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
            ExecuteEvent(eventId);
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    bool _healthTriggered;

protected:
    bool _claimedIris; // to prevent dropping multiple iris if a sister dies during claim process
};

// 131825 - Sister Briar
struct boss_sister_briar : public HeartsbaneTriadSharedAI
{
    boss_sister_briar(Creature* creature) : HeartsbaneTriadSharedAI(creature, DATA_SISTER_BRIAR) { }

    void ScheduleEvents() override
    {
        HeartsbaneTriadSharedAI::ScheduleEvents();

        events.ScheduleEvent(EVENT_BRAMBLE_BOLT, 2000ms);
    }

    void JustDied(Unit* killer) override
    {
        HeartsbaneTriadSharedAI::JustDied(killer);

        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_JAGGED_NETTLES);
    }

    void HandleDropIris(bool skipShieldPhase, bool skipIrisDrop) override
    {
        HeartsbaneTriadSharedAI::HandleDropIris(skipIrisDrop, skipIrisDrop);

        me->RemoveAurasDueToSpell(SPELL_AURA_OF_THORNS);

        events.CancelEvent(EVENT_BRAMBLE_BOLT_ENHANCED);
        events.CancelEvent(EVENT_JAGGED_NETTLES);

        if (skipShieldPhase)
            return;

        if (!skipIrisDrop)
            DoCastSelf(SPELL_DROP_THE_IRIS);
        DoCastSelf(SPELL_IRONBARK_SHIELD);

        if (Creature* solena = instance->GetCreature(DATA_SISTER_SOLENA))
            solena->AI()->DoAction(ACTION_CLAIM_THE_IRIS);

        events.ScheduleEvent(EVENT_BRAMBLE_BOLT, 3200ms);
    }

    void HandleClaimIris() override
    {
        HeartsbaneTriadSharedAI::HandleClaimIris();

        if (IsHeroic() || IsMythic())
            events.ScheduleEvent(EVENT_AURA_OF_THORNS, 1600ms);

        me->RemoveAurasDueToSpell(SPELL_IRONBARK_SHIELD);
        events.ScheduleEvent(EVENT_BRAMBLE_BOLT_ENHANCED, 4700ms);
        events.ScheduleEvent(EVENT_JAGGED_NETTLES, 14600ms);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        HeartsbaneTriadSharedAI::EnterEvadeMode(why);

        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_JAGGED_NETTLES);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_BRAMBLE_BOLT:
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_BRAMBLE_BOLT);
                events.Repeat(2400ms);
                break;
            }
            case EVENT_BRAMBLE_BOLT_ENHANCED:
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_BRAMBLE_BOLT_ENHANCED);
                events.Repeat(7300ms);
                break;
            }
            case EVENT_JAGGED_NETTLES:
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_JAGGED_NETTLES);
                Talk(SAY_JAGGED_NETTLES);
                events.Repeat(14600ms);
                break;
            }
            case EVENT_AURA_OF_THORNS:
            {
                DoCastSelf(SPELL_AURA_OF_THORNS);
                break;
            }
            default:
                HeartsbaneTriadSharedAI::ExecuteEvent(eventId);
                break;
        }
    }
};

// 131823 - Sister Malady
struct boss_sister_malady : public HeartsbaneTriadSharedAI
{
    boss_sister_malady(Creature* creature) : HeartsbaneTriadSharedAI(creature, DATA_SISTER_MALADY) { }

    void ScheduleEvents() override
    {
        HeartsbaneTriadSharedAI::ScheduleEvents();

        events.ScheduleEvent(EVENT_RUINOUS_BOLT, 3200ms);
    }

    void JustDied(Unit* killer) override
    {
        HeartsbaneTriadSharedAI::JustDied(killer);

        HandleDropIris(true, _claimedIris);
    }

    void HandleDropIris(bool skipShieldPhase, bool skipIrisDrop) override
    {
        me->RemoveAurasDueToSpell(SPELL_AURA_OF_DREAD);
        if (!skipIrisDrop)
            DoCastSelf(SPELL_DROP_THE_IRIS);

        if (Creature* briar = instance->GetCreature(DATA_SISTER_BRIAR))
            briar->AI()->DoAction(ACTION_CLAIM_THE_IRIS);

        events.CancelEvent(EVENT_RUINOUS_BOLT_ENHANCED);
        events.CancelEvent(EVENT_UNSTABLE_RUNIC_MARK);

        if (skipShieldPhase)
            return;

        DoCastSelf(SPELL_RUNIC_WARD);
        events.ScheduleEvent(EVENT_RUINOUS_BOLT, 3200ms);
    }

    void HandleClaimIris() override
    {
        HeartsbaneTriadSharedAI::HandleClaimIris();

        if (IsHeroic() || IsMythic())
            events.ScheduleEvent(EVENT_AURA_OF_DREAD, 1600ms);

        me->RemoveAurasDueToSpell(SPELL_RUNIC_WARD);

        events.ScheduleEvent(EVENT_RUINOUS_BOLT_ENHANCED, 4700ms);
        events.ScheduleEvent(EVENT_UNSTABLE_RUNIC_MARK, 14600ms);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_RUINOUS_BOLT:
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_RUINOUS_BOLT);
                events.Repeat(2400ms);
                break;
            }
            case EVENT_RUINOUS_BOLT_ENHANCED:
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_RUINOUS_BOLT_ENHANCED);
                events.Repeat(7300ms);
                break;
            }
            case EVENT_UNSTABLE_RUNIC_MARK:
            {
                Talk(SAY_UNSTABLE_RUNIC_MARK);
                DoCast(SPELL_UNSTABLE_RUNIC_MARK);
                events.Repeat(12100ms);
                break;
            }
            case EVENT_CLAIM_IRIS:
            {
                HandleClaimIris();
                break;
            }
            case EVENT_AURA_OF_DREAD:
            {
                DoCastSelf(SPELL_AURA_OF_DREAD);
                break;
            }
            default:
                HeartsbaneTriadSharedAI::ExecuteEvent(eventId);
                break;
        }
    }
};

// 131824 - Sister Solena
struct boss_sister_solena : public HeartsbaneTriadSharedAI
{
    boss_sister_solena(Creature* creature) : HeartsbaneTriadSharedAI(creature, DATA_SISTER_SOLENA) { }

    void ScheduleEvents() override
    {
        HeartsbaneTriadSharedAI::ScheduleEvents();

        events.ScheduleEvent(EVENT_SOUL_BOLT_ENHANCED, 4700ms);
        events.ScheduleEvent(EVENT_SOUL_MANIPULATION, 12000ms);
    }

    void JustEngagedWith(Unit* who) override
    {
        HeartsbaneTriadSharedAI::JustEngagedWith(who);

        DoAction(ACTION_CLAIM_THE_IRIS_INTRO);

        if (Creature* sister = me->GetInstanceScript()->GetCreature(RAND(DATA_SISTER_SOLENA, DATA_SISTER_BRIAR, DATA_SISTER_MALADY)))
            sister->AI()->Talk(SAY_AGGRO);
    }

    void JustDied(Unit* killer) override
    {
        HeartsbaneTriadSharedAI::JustDied(killer);

        HandleDropIris(true, _claimedIris);
    }

    void HandleDropIris(bool skipShieldPhase, bool skipIrisDrop) override
    {
        me->RemoveAurasDueToSpell(SPELL_AURA_OF_APATHY);
        if (!skipIrisDrop)
            DoCastSelf(SPELL_DROP_THE_IRIS);

        if (Creature* malady = instance->GetCreature(DATA_SISTER_MALADY))
            malady->AI()->DoAction(ACTION_CLAIM_THE_IRIS);

        events.CancelEvent(EVENT_SOUL_BOLT_ENHANCED);
        events.CancelEvent(EVENT_SOUL_MANIPULATION);

        if (skipShieldPhase)
            return;

        DoCastSelf(SPELL_SOUL_ARMOR);
        events.ScheduleEvent(EVENT_SOUL_BOLT, 3200ms);
    }

    void HandleClaimIris() override
    {
        HeartsbaneTriadSharedAI::HandleClaimIris();

        if (IsHeroic() || IsMythic())
            events.ScheduleEvent(EVENT_AURA_OF_APATHY, 1600ms);

        me->RemoveAurasDueToSpell(SPELL_SOUL_ARMOR);

        events.ScheduleEvent(EVENT_SOUL_BOLT_ENHANCED, 4700ms);
        events.ScheduleEvent(EVENT_SOUL_MANIPULATION, 14600ms);
    }

    void DoAction(int32 actionId) override
    {
        switch (actionId)
        {
            case ACTION_CLAIM_THE_IRIS_INTRO:
            {
                _claimedIris = true;

                if (Creature* focusingIris = me->FindNearestCreature(NPC_FOCUSING_IRIS, 100.0f))
                    DoCast(focusingIris, SPELL_CLAIM_THE_IRIS);

                if (IsHeroic() || IsMythic())
                    events.ScheduleEvent(EVENT_AURA_OF_APATHY, 1600ms);
                break;
            }
            default:
                HeartsbaneTriadSharedAI::DoAction(actionId);
                break;
        }
    }

    void JustAppeared() override
    {
        HeartsbaneTriadSharedAI::JustAppeared();
        me->SummonCreatureGroup(SUMMON_GROUP_TRIAD_FOCUSING_IRIS);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_SOUL_BOLT_ENHANCED:
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_SOUL_BOLT_ENHANCED);
                events.Repeat(4900ms);
                break;
            }
            case EVENT_SOUL_BOLT:
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_SOUL_BOLT);
                events.Repeat(2400ms);
                break;
            }
            case EVENT_SOUL_MANIPULATION:
            {
                if (me->GetMap()->GetPlayersCountExceptGMs() > 1) // This event doesn't happen if you go solo because it resets boss
                {
                    Talk(SAY_SOUL_MANIPULATION);
                    DoCast(SPELL_SOUL_MANIPULATION_SELECTOR);
                    events.RescheduleEvent(EVENT_SOUL_BOLT_ENHANCED, 12s + 100ms);
                    events.Repeat(23100ms, 24200ms);
                }
                break;
            }
            case EVENT_AURA_OF_APATHY:
            {
                DoCastSelf(SPELL_AURA_OF_APATHY);
                break;
            }
            default:
                HeartsbaneTriadSharedAI::ExecuteEvent(eventId);
                break;
        }
    }
};

// 260741 - Jagged Nettles
class spell_heartsbane_triad_jagged_nettles : public AuraScript
{
    void HandlePeriodic(AuraEffect const* aurEff)
    {
        if (aurEff->GetTickNumber() > 1)
        {
            if (GetTarget()->GetHealthPct() >= float(GetEffectInfo(EFFECT_2).CalcValue(GetCaster())))
                Remove();
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_heartsbane_triad_jagged_nettles::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 260852 - Claim the Iris
class spell_heartsbane_triad_claim_the_iris : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FOCUSING_IRIS });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        Creature* casterCreature = GetCaster()->ToCreature();
        if (!casterCreature)
            return;

        if (Creature* hitCreature = GetHitCreature())
            hitCreature->DespawnOrUnsummon();

        casterCreature->CastSpell(casterCreature, SPELL_FOCUSING_IRIS, TRIGGERED_IGNORE_CAST_IN_PROGRESS);
        casterCreature->SetSessile(false);
        casterCreature->SetFloating(false);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_heartsbane_triad_claim_the_iris::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 260854 - Drop the Iris
class spell_heartsbane_triad_drop_the_iris : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FOCUSING_IRIS });
    }

    void RemoveIris(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->RemoveAurasDueToSpell(SPELL_FOCUSING_IRIS);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_heartsbane_triad_drop_the_iris::RemoveIris, EFFECT_0, SPELL_EFFECT_SUMMON);
    }
};

// 260923 - Soul Manipulation
class spell_heartsbane_triad_soul_manipulation_periodic : public AuraScript
{
    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (GetTarget()->GetHealthPct() > 50.0f)
            return;

        Remove();

        if (Unit* caster = GetCaster())
            caster->InterruptSpell(CURRENT_CHANNELED_SPELL);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_heartsbane_triad_soul_manipulation_periodic::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 260907 Soul Manipulation (Selector)
class spell_heartsbane_triad_soul_manipulation_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SOUL_MANIPULATION_CHARM, SPELL_SOUL_MANIPULATION_DAMAGE_REDUCTION, SPELL_SOUL_MANIPULATION_VISUAL });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_SOUL_MANIPULATION_CHARM, TRIGGERED_IGNORE_CAST_IN_PROGRESS);
        GetCaster()->CastSpell(GetCaster(), SPELL_SOUL_MANIPULATION_DAMAGE_REDUCTION, TRIGGERED_IGNORE_CAST_IN_PROGRESS);
        GetCaster()->CastSpell(GetHitUnit(), SPELL_SOUL_MANIPULATION_VISUAL, TRIGGERED_IGNORE_CAST_IN_PROGRESS);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_heartsbane_triad_soul_manipulation_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 260703 - Unstable Runic Mark
class spell_heartsbane_triad_unstable_runic_mark : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_UNSTABLE_RUNIC_MARK_DAMAGE });
    }

    void HandleDamage(AuraEffect const* /*aurEff*/ , AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE && GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_ENEMY_SPELL)
            return;

        GetTarget()->CastSpell(GetTarget(), SPELL_UNSTABLE_RUNIC_MARK_DAMAGE, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_heartsbane_triad_unstable_runic_mark::HandleDamage, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 260773 - Dire Ritual
class spell_heartsbane_triad_dire_ritual : public SpellScript
{
    void HandleAfterCast()
    {
        GetCaster()->SetPower(POWER_ENERGY, 0);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_heartsbane_triad_dire_ritual::HandleAfterCast);
    }
};

// 17789 - Aura of Apathy
struct at_heartsbane_triad_aura_of_apathy : AreaTriggerAI
{
    at_heartsbane_triad_aura_of_apathy(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->CastSpell(unit, SPELL_AURA_OF_APATHY_DEBUFF, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_AURA_OF_APATHY_DEBUFF);
    }

    void OnRemove() override
    {
        for (ObjectGuid const& guid : at->GetInsideUnits())
        {
            Unit* unit = ObjectAccessor::GetUnit(*at, guid);
            if (!unit)
                continue;

            OnUnitExit(unit);
        }
    }
};

// 17791 - Aura of Dread
struct at_heartsbane_triad_aura_of_dread : AreaTriggerAI
{
    at_heartsbane_triad_aura_of_dread(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->CastSpell(unit, SPELL_AURA_OF_DREAD_MOVE_CHECK, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_AURA_OF_DREAD_MOVE_CHECK);
        unit->RemoveAurasDueToSpell(SPELL_AURA_OF_DREAD_DAMAGE);
    }

    void OnRemove() override
    {
        for (ObjectGuid const& guid : at->GetInsideUnits())
        {
            Unit* unit = ObjectAccessor::GetUnit(*at, guid);
            if (!unit)
                continue;

            OnUnitExit(unit);
        }
    }
};

// 268088 - Aura of Dread
class spell_heartsbane_triad_aura_of_dread : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_AURA_OF_DREAD_DAMAGE, SPELL_AURA_OF_DREAD_MOVE_CHECK });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        for (MapReference const& players : caster->GetMap()->GetPlayers())
        {
            if (Player* player = players.GetSource())
            {
                if (!player->HasAura(SPELL_AURA_OF_DREAD_MOVE_CHECK))
                    continue;

                player->CastSpell(player, SPELL_AURA_OF_DREAD_DAMAGE, true);
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_heartsbane_triad_aura_of_dread::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 268085 - Aura of Dread
class spell_heartsbane_triad_aura_of_dread_movement_check : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_AURA_OF_DREAD_DAMAGE });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (caster->isMoving())
        {
            if (Aura* stack = caster->GetAura(SPELL_AURA_OF_DREAD_DAMAGE, caster->GetGUID()))
            {
                if (stack->GetStackAmount() > 1)
                    caster->RemoveAuraFromStack(SPELL_AURA_OF_DREAD_DAMAGE);
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_heartsbane_triad_aura_of_dread_movement_check::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 17807 - Aura of Thorns
struct at_heartsbane_triad_aura_of_thorns : AreaTriggerAI
{
    at_heartsbane_triad_aura_of_thorns(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->CastSpell(unit, SPELL_AURA_OF_THORNS_CHECK_PROC, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_AURA_OF_THORNS_CHECK_PROC);
    }

    void OnRemove() override
    {
        for (ObjectGuid const& guid : at->GetInsideUnits())
        {
            Unit* unit = ObjectAccessor::GetUnit(*at, guid);
            if (!unit)
                continue;

            OnUnitExit(unit);
        }
    }
};

// 268122 - Aura of Thorns
class spell_heartsbane_triad_aura_of_thorns : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_AURA_OF_THORNS_CHECK_PROC });
    }

    bool HandleCheckProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetActor()->HasAura(SPELL_AURA_OF_THORNS_CHECK_PROC);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_heartsbane_triad_aura_of_thorns::HandleCheckProc);
    }
};

void AddSC_boss_heartsbane_triad()
{
    RegisterWaycrestManorCreatureAI(boss_sister_briar);
    RegisterWaycrestManorCreatureAI(boss_sister_malady);
    RegisterWaycrestManorCreatureAI(boss_sister_solena);

    RegisterSpellScript(spell_heartsbane_triad_jagged_nettles);
    RegisterSpellScript(spell_heartsbane_triad_claim_the_iris);
    RegisterSpellScript(spell_heartsbane_triad_drop_the_iris);
    RegisterSpellScript(spell_heartsbane_triad_soul_manipulation_periodic);
    RegisterSpellScript(spell_heartsbane_triad_soul_manipulation_selector);
    RegisterSpellScript(spell_heartsbane_triad_unstable_runic_mark);
    RegisterSpellScript(spell_heartsbane_triad_dire_ritual);

    RegisterAreaTriggerAI(at_heartsbane_triad_aura_of_apathy);
    RegisterAreaTriggerAI(at_heartsbane_triad_aura_of_dread);
    RegisterSpellScript(spell_heartsbane_triad_aura_of_dread);
    RegisterSpellScript(spell_heartsbane_triad_aura_of_dread_movement_check);
    RegisterAreaTriggerAI(at_heartsbane_triad_aura_of_thorns);
    RegisterSpellScript(spell_heartsbane_triad_aura_of_thorns);
}
