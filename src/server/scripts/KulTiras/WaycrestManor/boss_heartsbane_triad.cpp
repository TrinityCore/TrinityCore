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

#include "Creature.h"
#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "waycrest_manor.h"

enum HeartsbaneTriadSpells
{
    // Sister Briar
    SPELL_BRAMBLE_BOLT          = 260701,
    SPELL_BRAMBLE_BOLT_ENHANCED = 260697,
    SPELL_JAGGED_NETTLES        = 260741,
    SPELL_IRONBARK_SHIELD       = 261265,

    // Sister Malady
    SPELL_RUINOUS_BOLT          = 260700,
    SPELL_RUINOUS_BOLT_ENHANCED = 260696,
    SPELL_RUNIC_WARD            = 261266,
    SPELL_UNSTABLE_RUNIC_MARK   = 260703,
    SPELL_UNSTABLE_RUNIC_MARK_DAMAGE = 260702,

    // Sister Solena
    SPELL_SOUL_BOLT             = 260699,
    SPELL_SOUL_BOLT_ENHANCED    = 260698,
    SPELL_SOUL_ARMOR            = 261264,
    SPELL_SOUL_MANIPULATION_SELECTOR         = 260907,
    SPELL_SOUL_MANIPULATION_CHARM            = 260900,
    SPELL_SOUL_MANIPULATION_DAMAGE_REDUCTION = 260923,
    SPELL_SOUL_MANIPULATION_VISUAL           = 260926,

    SPELL_DIRE_RITUAL           = 260773,
    SPELL_CLAIM_THE_IRIS        = 260852,
    SPELL_DROP_THE_IRIS         = 260853,
    SPELL_FOCUSING_IRIS         = 260805
};

enum HeartsbaneTriadTexts
{
    // Shared
    SAY_AGGRO                 = 0,
    SAY_CLAIM_THE_IRIS        = 1,
    SAY_SLAY                  = 3,
    SAY_DEATH                 = 4,
    SAY_DIRE_RITUAL_ALERT     = 5,
    SAY_DIRE_RITUAL           = 6,

    // Sister Solena
    SAY_SOUL_MANIPULATION     = 2,

    // Sister Malady
    SAY_UNSTABLE_RUNIC_MARK   = 2,

    // Sister Briar
    SAY_JAGGED_NETTLES        = 2
};

enum HeartsbaneTriadEvents
{
    // Sister Briar
    EVENT_BRAMBLE_BOLT          = 1,
    EVENT_BRAMBLE_BOLT_ENHANCED = 2,
    EVENT_JAGGED_NETTLES        = 3,
    EVENT_BRIAR_TAKE_IRIS       = 4,

    // Sister Malady
    EVENT_RUINOUS_BOLT          = 5,
    EVENT_RUINOUS_BOLT_ENHANCED = 6,
    EVENT_UNSTABLE_RUNIC_MARK   = 7,
    EVENT_MALADY_TAKE_IRIS      = 8,

    // Sister Solena
    EVENT_SOUL_BOLT             = 9,
    EVENT_SOUL_BOLT_ENHANCED    = 10,
    EVENT_SOUL_MANIPULATION     = 11,
    EVENT_SOLENA_TAKE_IRIS      = 12,

    EVENT_CHECK_POWER           = 13
};

enum HeartsbaneTriadActions
{
    ACTION_CLAIM_THE_IRIS_INTRO  = 1,
    ACTION_MALADY_CLAIM_THE_IRIS = 2,
    ACTION_BRIAR_CLAIM_THE_IRIS  = 3,
    ACTION_SOLENA_CLAIM_THE_IRIS = 4
};

enum HeartsbaneTriadSummonGroups
{
    SUMMON_GROUP_TRIAD_FOCUSING_IRIS = 0
};

uint32 const TriadData[3] =
{
    DATA_SISTER_BRIAR,
    DATA_SISTER_MALADY,
    DATA_SISTER_SOLENA
};

namespace
{
void DespawnTriad(InstanceScript* instance, EvadeReason why)
{
    if (instance->GetBossState(DATA_HEARTSBANE_TRIAD) == FAIL)
        return;

    instance->SetBossState(DATA_HEARTSBANE_TRIAD, FAIL);

    for (uint32 bossesData : TriadData)
    {
        if (Creature* triad = instance->GetCreature(bossesData))
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, triad);
            triad->AI()->EnterEvadeMode(why);
        }
    }
}

void HeartsbaneTriadEncounterDone(InstanceScript* instance)
{
    if (instance->GetBossState(DATA_HEARTSBANE_TRIAD) == DONE)
        return;

    for (uint32 bossesData : TriadData)
    {
        if (Creature* triad = instance->GetCreature(bossesData))
        {
            if (triad->IsAlive())
                return;
        }
    }

    instance->SetBossState(DATA_HEARTSBANE_TRIAD, DONE);
}
}

struct TriadSharedAI : public BossAI
{
    TriadSharedAI(Creature* creature, uint32 bossId) : BossAI(creature, bossId), _healthTriggered(false)
    {
        SetBoundary(instance->GetBossBoundary(DATA_HEARTSBANE_TRIAD));
    }

    void Reset() override
    {
        events.Reset();
        _healthTriggered = false;
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        DespawnTriad(instance, why);

        events.Reset();
        _DespawnAtEvade();
    }

    void JustAppeared() override
    {
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 0);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        for (uint32 bossesData : TriadData)
        {
            if (Creature* triad = instance->GetCreature(bossesData))
                triad->AI()->DoZoneInCombat();
        }

        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        ScheduleEvents();
    }

    void HandleSharedEvents(uint32 eventId)
    {
        if (eventId == EVENT_CHECK_POWER)
        {
            if (me->GetPower(me->GetPowerType()) >= 100)
            {
                Talk(SAY_DIRE_RITUAL_ALERT);
                Talk(SAY_DIRE_RITUAL);
                DoCast(SPELL_DIRE_RITUAL);
            }
            events.Repeat(500ms);
        }
    }

    virtual void ScheduleEvents()
    {
        events.ScheduleEvent(EVENT_CHECK_POWER, 500ms);
    };

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

protected:
    bool _healthTriggered = false;
};

// 131825 - Sister Briar
struct boss_sister_briar : public TriadSharedAI
{
    boss_sister_briar(Creature* creature) : TriadSharedAI(creature, DATA_SISTER_BRIAR) { }

    void ScheduleEvents() override
    {
        events.ScheduleEvent(EVENT_BRAMBLE_BOLT, 2000ms);
    }

    void JustEngagedWith(Unit* who) override
    {
        TriadSharedAI::JustEngagedWith(who);
        TriadSharedAI::ScheduleEvents();
    }

    void JustDied(Unit* killer) override
    {
        TriadSharedAI::JustDied(killer);

        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_JAGGED_NETTLES);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        TriadSharedAI::EnterEvadeMode(why);

        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_JAGGED_NETTLES);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->HealthBelowPctDamaged(50, damage) && !_healthTriggered)
        {
            _healthTriggered = true;
            me->AttackStop();
            me->InterruptNonMeleeSpells(true);

            DoCastSelf(SPELL_DROP_THE_IRIS);
            DoCastSelf(SPELL_IRONBARK_SHIELD);

            if (Creature* sisterSolena = instance->GetCreature(DATA_SISTER_SOLENA))
                sisterSolena->AI()->DoAction(ACTION_SOLENA_CLAIM_THE_IRIS);

            events.CancelEvent(EVENT_BRAMBLE_BOLT_ENHANCED);
            events.CancelEvent(EVENT_JAGGED_NETTLES);
            events.ScheduleEvent(EVENT_BRAMBLE_BOLT, 3200ms);
        }
    }

    void DoAction(int32 actionId) override
    {
        if (actionId != ACTION_BRIAR_CLAIM_THE_IRIS)
            return;

        events.ScheduleEvent(EVENT_BRIAR_TAKE_IRIS, 1500ms);
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
            case EVENT_BRIAR_TAKE_IRIS:
            {
                Talk(SAY_CLAIM_THE_IRIS);

                me->AttackStop();
                me->InterruptNonMeleeSpells(true);

                if (Creature* focusingIris = me->FindNearestCreature(NPC_FOCUSING_IRIS, 100.0f))
                    DoCast(focusingIris, SPELL_CLAIM_THE_IRIS);

                me->RemoveAurasDueToSpell(SPELL_IRONBARK_SHIELD);
                events.CancelEvent(EVENT_BRAMBLE_BOLT);
                events.ScheduleEvent(EVENT_BRAMBLE_BOLT_ENHANCED, 4700ms);
                events.ScheduleEvent(EVENT_JAGGED_NETTLES, 14600ms);
                break;
            }
            default:
                HandleSharedEvents(EVENT_CHECK_POWER);
                break;
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
            ExecuteEvent(eventId);
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
};

// 131823 - Sister Malady
struct boss_sister_malady : public TriadSharedAI
{
    boss_sister_malady(Creature* creature) : TriadSharedAI(creature, DATA_SISTER_MALADY) { }

    void ScheduleEvents() override
    {
        events.ScheduleEvent(EVENT_RUINOUS_BOLT, 3200ms);
    }

    void JustEngagedWith(Unit* who) override
    {
        TriadSharedAI::JustEngagedWith(who);
        TriadSharedAI::ScheduleEvents();
    }

    void JustDied(Unit* killer) override
    {
        TriadSharedAI::JustDied(killer);

        DoCastSelf(SPELL_DROP_THE_IRIS);

        if (Creature* sisterBriar = instance->GetCreature(DATA_SISTER_BRIAR))
            sisterBriar->AI()->DoAction(ACTION_BRIAR_CLAIM_THE_IRIS);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->HealthBelowPctDamaged(50, damage) && !_healthTriggered)
        {
            _healthTriggered = true;
            me->AttackStop();
            me->InterruptNonMeleeSpells(true);

            DoCastSelf(SPELL_DROP_THE_IRIS);
            DoCastSelf(SPELL_RUNIC_WARD);

            if (Creature* sisterBriar = instance->GetCreature(DATA_SISTER_BRIAR))
                sisterBriar->AI()->DoAction(ACTION_BRIAR_CLAIM_THE_IRIS);  

            events.CancelEvent(EVENT_RUINOUS_BOLT_ENHANCED);
            events.CancelEvent(EVENT_UNSTABLE_RUNIC_MARK);
            events.ScheduleEvent(EVENT_RUINOUS_BOLT, 3200ms);
        }
    }

    void DoAction(int32 actionId) override
    {
        if (actionId != ACTION_MALADY_CLAIM_THE_IRIS)
            return;

        events.ScheduleEvent(EVENT_MALADY_TAKE_IRIS, 1500ms);
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
            case EVENT_MALADY_TAKE_IRIS:
            {
                Talk(SAY_CLAIM_THE_IRIS);

                me->AttackStop();
                me->InterruptNonMeleeSpells(true);

                if (Creature* focusingIris = me->FindNearestCreature(NPC_FOCUSING_IRIS, 100.0f))
                    DoCast(focusingIris, SPELL_CLAIM_THE_IRIS);

                me->RemoveAurasDueToSpell(SPELL_RUNIC_WARD);

                events.CancelEvent(EVENT_RUINOUS_BOLT);
                events.ScheduleEvent(EVENT_RUINOUS_BOLT_ENHANCED, 4700ms);
                events.ScheduleEvent(EVENT_UNSTABLE_RUNIC_MARK, 14600ms);
                break;
            }
            default:
                HandleSharedEvents(EVENT_CHECK_POWER);
                break;
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
            ExecuteEvent(eventId);
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
};

// 131824 - Sister Solena
struct boss_sister_solena : public TriadSharedAI
{
    boss_sister_solena(Creature* creature) : TriadSharedAI(creature, DATA_SISTER_SOLENA) { }

    void ScheduleEvents() override
    {
        events.ScheduleEvent(EVENT_SOUL_BOLT_ENHANCED, 4700ms);
        events.ScheduleEvent(EVENT_SOUL_MANIPULATION, 12000ms);
    }

    void JustEngagedWith(Unit* who) override
    {
        TriadSharedAI::JustEngagedWith(who);
        TriadSharedAI::ScheduleEvents();

        DoAction(ACTION_CLAIM_THE_IRIS_INTRO);

        Creature* sister = nullptr;

        switch (urand(0, 2))
        {
            case 0:
                sister = me->GetInstanceScript()->GetCreature(DATA_SISTER_BRIAR);
                break;
            case 1:
                sister = me->GetInstanceScript()->GetCreature(DATA_SISTER_MALADY);
                break;
            case 2:
                sister = me;
                break;
        }

        sister->AI()->Talk(SAY_AGGRO);
    }

    void JustDied(Unit* killer) override
    {
        TriadSharedAI::JustDied(killer);

        DoCastSelf(SPELL_DROP_THE_IRIS);

        if (Creature* sisterMalady = instance->GetCreature(DATA_SISTER_MALADY))
            sisterMalady->AI()->DoAction(ACTION_MALADY_CLAIM_THE_IRIS);
    }

    void DoAction(int32 actionId) override
    {
        switch (actionId)
        {
            case ACTION_CLAIM_THE_IRIS_INTRO:
            {
                if (Creature* focusingIris = me->FindNearestCreature(NPC_FOCUSING_IRIS, 100.0f))
                    DoCast(focusingIris, SPELL_CLAIM_THE_IRIS);
                break;
            }
            case ACTION_SOLENA_CLAIM_THE_IRIS:
            {
                events.ScheduleEvent(EVENT_SOLENA_TAKE_IRIS, 1500ms);
                break;
            }
            default:
                break;
        }
    }

    void JustAppeared() override
    {
        TriadSharedAI::JustAppeared();
        me->SummonCreatureGroup(SUMMON_GROUP_TRIAD_FOCUSING_IRIS);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->HealthBelowPctDamaged(50, damage) && !_healthTriggered)
        {
            _healthTriggered = true;
            me->AttackStop();
            me->InterruptNonMeleeSpells(true);

            DoCastSelf(SPELL_DROP_THE_IRIS);
            DoCastSelf(SPELL_SOUL_ARMOR);

            if (Creature* sisterMalady = instance->GetCreature(DATA_SISTER_MALADY))
                sisterMalady->AI()->DoAction(ACTION_MALADY_CLAIM_THE_IRIS);

            events.CancelEvent(EVENT_SOUL_BOLT_ENHANCED);
            events.CancelEvent(EVENT_SOUL_MANIPULATION);
            events.ScheduleEvent(EVENT_SOUL_BOLT, 3200ms);
        }
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
                Talk(SAY_SOUL_MANIPULATION);
                DoCast(SPELL_SOUL_MANIPULATION_SELECTOR);
                events.RescheduleEvent(EVENT_SOUL_BOLT_ENHANCED, 12s + 100ms);
                events.Repeat(23100ms, 24200ms);
                break;
            }
            case EVENT_SOLENA_TAKE_IRIS:
            {
                Talk(SAY_CLAIM_THE_IRIS);

                me->AttackStop();
                me->InterruptNonMeleeSpells(true);

                if (Creature* focusingIris = me->FindNearestCreature(NPC_FOCUSING_IRIS, 100.0f))
                    DoCast(focusingIris, SPELL_CLAIM_THE_IRIS);

                me->RemoveAurasDueToSpell(SPELL_SOUL_ARMOR);

                events.CancelEvent(EVENT_SOUL_BOLT);
                events.ScheduleEvent(EVENT_SOUL_BOLT_ENHANCED, 4700ms);
                events.ScheduleEvent(EVENT_SOUL_MANIPULATION, 14600ms);
                break;
            }
            default:
                HandleSharedEvents(EVENT_CHECK_POWER);
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            ExecuteEvent(eventId);
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
};

// 260741 - Jagged Nettles
class spell_jagged_nettles : public AuraScript
{
    void HandlePeriodic(AuraEffect const* aurEff)
    {
        if (aurEff->GetTickNumber() > 1)
        {
            Unit* target = GetTarget();
            if (target->GetHealthPct() >= float(GetEffectInfo(EFFECT_2).CalcValue(target)))
                GetAura()->Remove();
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_jagged_nettles::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 260852 - Claim the Iris
class spell_claim_the_iris : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FOCUSING_IRIS });
    }

    void HandleAfterCast()
    {
        Creature* casterCreature = GetCaster()->ToCreature();
        if (!casterCreature)
            return;

        if (Creature* focusingIris = casterCreature->FindNearestCreature(NPC_FOCUSING_IRIS, 100.0f))
            focusingIris->DespawnOrUnsummon();

        casterCreature->CastSpell(casterCreature, SPELL_FOCUSING_IRIS, TRIGGERED_IGNORE_CAST_IN_PROGRESS);
        casterCreature->SetSessile(false);
        casterCreature->SetFloating(false);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_claim_the_iris::HandleAfterCast);
    }
};

// 260854 - Drop the Iris
class spell_drop_the_iris : public SpellScript
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
        OnEffectHit += SpellEffectFn(spell_drop_the_iris::RemoveIris, EFFECT_0, SPELL_EFFECT_SUMMON);
    }
};

// 260923 - Soul Manipulation
class spell_soul_manipulation_periodic : public AuraScript
{
    void HandlePeriodic(AuraEffect const* aurEff)
    {
        if (aurEff->GetTickNumber() == 10)
        {
            GetAura()->Remove();
            GetCaster()->InterruptSpell(CURRENT_CHANNELED_SPELL);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_soul_manipulation_periodic::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 260907 Soul Manipulation (Selector)
class spell_soul_manipulation_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SOUL_MANIPULATION_CHARM, SPELL_SOUL_MANIPULATION_DAMAGE_REDUCTION, SPELL_SOUL_MANIPULATION_VISUAL });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([&](WorldObject const* target)
        {
            if (target = GetCaster()->GetThreatManager().GetCurrentVictim())
                return true;
            return false;
        });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_SOUL_MANIPULATION_CHARM, TRIGGERED_IGNORE_CAST_IN_PROGRESS);
        GetCaster()->CastSpell(GetCaster(), SPELL_SOUL_MANIPULATION_DAMAGE_REDUCTION, TRIGGERED_IGNORE_CAST_IN_PROGRESS);
        GetCaster()->CastSpell(GetHitUnit(), SPELL_SOUL_MANIPULATION_VISUAL, TRIGGERED_IGNORE_CAST_IN_PROGRESS);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_soul_manipulation_selector::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_soul_manipulation_selector::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 260703 - Unstable Runic Mark
class spell_unstable_runic_mark : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_UNSTABLE_RUNIC_MARK_DAMAGE });
    }

    void HandleDamage(AuraEffect const* /*aurEff*/ , AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE || GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_ENEMY_SPELL)
            return;

        GetTarget()->CastSpell(GetTarget(), SPELL_UNSTABLE_RUNIC_MARK_DAMAGE, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_unstable_runic_mark::HandleDamage, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 260773 - Dire Ritual
class spell_dire_ritual : public SpellScript
{
    void HandlePower()
    {
        GetCaster()->SetPower(POWER_ENERGY, 0);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_dire_ritual::HandlePower);
    }
};

void AddSC_boss_heartsbane_triad()
{
    RegisterWaycrestManorCreatureAI(boss_sister_briar);
    RegisterWaycrestManorCreatureAI(boss_sister_malady);
    RegisterWaycrestManorCreatureAI(boss_sister_solena);

    RegisterSpellScript(spell_jagged_nettles);
    RegisterSpellScript(spell_claim_the_iris);
    RegisterSpellScript(spell_drop_the_iris);
    RegisterSpellScript(spell_soul_manipulation_periodic);
    RegisterSpellScript(spell_soul_manipulation_selector);
    RegisterSpellScript(spell_unstable_runic_mark);
    RegisterSpellScript(spell_dire_ritual);
}
