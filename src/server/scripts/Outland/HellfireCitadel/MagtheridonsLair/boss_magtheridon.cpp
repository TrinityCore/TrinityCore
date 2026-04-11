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
 * Combat timers requires to be revisited
 * Spell 30657 has tricky implementation, requires to be investigated and scripted
 * Spell 30410 deals no periodic damage
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "InstanceScript.h"
#include "magtheridons_lair.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum MagtheridonTexts
{
    SAY_TAUNT                         = 0,
    SAY_FREE                          = 1,
    SAY_SLAY                          = 2,
    SAY_BANISHED                      = 3,
    SAY_COLLAPSE                      = 4,
    SAY_DEATH                         = 5,
    EMOTE_WEAKEN                      = 6,
    EMOTE_NEARLY_FREE                 = 7,
    EMOTE_BREAKS_FREE                 = 8,
    EMOTE_BLAST_NOVA                  = 9
};

enum MagtheridonSpells
{
    // Magtheridon - Initial
    SPELL_SHADOW_CAGE_DUMMY           = 30205,

    // Magtheridon - Combat - Phase 2, 3
    SPELL_CLEAVE                      = 30619,
    SPELL_BLAZE                       = 30541,
    SPELL_QUAKE                       = 30576,
    SPELL_BLAST_NOVA                  = 30616,
    SPELL_BERSERK                     = 26662,

    // Magtheridon - Collapse
    SPELL_CAMERA_SHAKE                = 36455,

    // Magtheridon - Combat - Phase 3
    SPELL_DEBRIS                      = 30629,

    // Hellfire Channeler
    SPELL_SHADOW_GRASP_CHANNELER      = 30207,
    SPELL_SHADOW_BOLT_VOLLEY          = 30510,
    SPELL_BURNING_ABYSSAL             = 30511,
    SPELL_DARK_MENDING                = 30528,
    SPELL_FEAR                        = 30530,
    SPELL_SOUL_TRANSFER               = 30531,

    // World Trigger (Not Immune PC)
    SPELL_DEBRIS_KNOCKDOWN            = 36449,

    // Magtheridon's Room
    SPELL_DEBRIS_VISUAL               = 30632,
    SPELL_DEBRIS_DAMAGE               = 30631,

    // Scripts
    SPELL_BLAZE_SUMMON                = 30542,
    SPELL_QUAKE_TARGET_SELECTOR       = 30572,
    SPELL_QUAKE_KNOCK_BACK            = 30571,
    SPELL_QUAKE_PERIODIC              = 30657,
    SPELL_DEBRIS_SUMMON               = 30630,
    SPELL_SHADOW_GRASP                = 30410,
    SPELL_MIND_EXHAUSTION             = 44032,
    SPELL_SHADOW_GRASP_VISUAL         = 30166,
    SPELL_SHADOW_CAGE                 = 30168
};

enum MagtheridonEvents
{
    // Out of Combat
    EVENT_TAUNT                       = 1,

    // Phase 1
    EVENT_BREAK_FREE_1,
    EVENT_BREAK_FREE_2,
    EVENT_BREAK_FREE_3,
    EVENT_BREAK_FREE_4,

    // Phase 2, 3: Combat
    EVENT_CLEAVE,
    EVENT_BLAZE,
    EVENT_QUAKE,
    EVENT_BLAST_NOVA,
    EVENT_BERSERK,

    // Phase 3: Collapse
    EVENT_COLLAPSE_1,
    EVENT_COLLAPSE_2,
    EVENT_COLLAPSE_3,
    EVENT_COLLAPSE_4,
    EVENT_COLLAPSE_5,
    EVENT_COLLAPSE_6,

    // Phase 3: Combat
    EVENT_DEBRIS
};

enum MagtheridonEventGroups
{
    EVENT_GROUP_BREAK_FREE            = 1
};

enum MagtheridonPhases
{
    PHASE_0_BANISHED                  = 1,
    PHASE_1_CHANNELERS,
    PHASE_2_BREAKS_FREE,
    PHASE_3_COLLAPSE
};

enum MagtheridonMisc
{
    SUMMON_GROUP_CHANNELERS           = 1,
    ACTION_START_ENCOUNTER            = 0,
    ACTION_RESET_ENCOUNTER            = 1
};

// 17257 - Magtheridon
struct boss_magtheridon : public BossAI
{
    boss_magtheridon(Creature* creature) : BossAI(creature, DATA_MAGTHERIDON), _channelersCount(5) { }

    void JustAppeared() override
    {
        ///! HACK: Boss sometimes regens health since he can't reach target (happens when boss is stunned). For now we prevent health regeneration completely. Find a better solution
        me->SetRegenerateHealth(false);

        DoCastSelf(SPELL_SHADOW_CAGE_DUMMY);
        me->SummonCreatureGroup(SUMMON_GROUP_CHANNELERS);

        events.SetPhase(PHASE_0_BANISHED);
        events.ScheduleEvent(EVENT_TAUNT, 4min, 5min);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_CLEAVE, 8s, 10s);
        events.ScheduleEvent(EVENT_BLAZE, 20s);
        events.ScheduleEvent(EVENT_QUAKE, 35s);
        events.ScheduleEvent(EVENT_BLAST_NOVA, 1min);
        events.ScheduleEvent(EVENT_BERSERK, 20min);
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        if (summon->GetEntry() == NPC_HELLFIRE_CHANNELLER && events.IsInPhase(PHASE_1_CHANNELERS))
        {
            _channelersCount--;

            if (_channelersCount == 0)
            {
                events.CancelEventGroup(EVENT_GROUP_BREAK_FREE);
                events.ScheduleEvent(EVENT_BREAK_FREE_3, 0s);
            }
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_START_ENCOUNTER && events.IsInPhase(PHASE_0_BANISHED))
        {
            events.SetPhase(PHASE_1_CHANNELERS);
            events.ScheduleEvent(EVENT_BREAK_FREE_1, 0s, EVENT_GROUP_BREAK_FREE);
        }
        else if (action == ACTION_RESET_ENCOUNTER)
        {
            summons.DespawnAll();
            events.Reset();
            instance->SetData(DATA_MANTICRON_CUBE, ACTION_DISABLE);
            instance->SetData(DATA_COLLAPSE_1, ACTION_DISABLE);
            instance->SetData(DATA_COLLAPSE_2, ACTION_DISABLE);
            instance->SetBossState(DATA_MAGTHERIDON, FAIL);

            me->DespawnOrUnsummon(0s, 30s);
        }
    }

    void OnSpellStart(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_BLAST_NOVA)
            Talk(EMOTE_BLAST_NOVA);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_SHADOW_CAGE)
            Talk(SAY_BANISHED);
    }

    void DamageTaken(Unit* /*who*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->HealthBelowPctDamaged(30, damage) && !events.IsInPhase(PHASE_3_COLLAPSE))
        {
            events.SetPhase(PHASE_3_COLLAPSE);
            events.ScheduleEvent(EVENT_COLLAPSE_1, 0s);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        DoAction(ACTION_RESET_ENCOUNTER);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();
        instance->SetData(DATA_MANTICRON_CUBE, ACTION_DISABLE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!events.IsInPhase(PHASE_0_BANISHED) && !events.IsInPhase(PHASE_1_CHANNELERS) && !UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                // Out of Combat
                case EVENT_TAUNT:
                    Talk(SAY_TAUNT);
                    events.Repeat(4min, 5min);
                    break;

                // Phase 1
                case EVENT_BREAK_FREE_1:
                    Talk(EMOTE_WEAKEN);
                    summons.DoZoneInCombat(NPC_HELLFIRE_CHANNELLER);
                    instance->SetBossState(DATA_MAGTHERIDON, IN_PROGRESS);
                    instance->SetData(DATA_CALL_WARDERS, ACTION_ENABLE);
                    events.CancelEvent(EVENT_TAUNT);
                    events.ScheduleEvent(EVENT_BREAK_FREE_2, 1min, EVENT_GROUP_BREAK_FREE);
                    break;
                case EVENT_BREAK_FREE_2:
                    Talk(EMOTE_NEARLY_FREE);
                    events.ScheduleEvent(EVENT_BREAK_FREE_3, 1min, EVENT_GROUP_BREAK_FREE);
                    break;
                case EVENT_BREAK_FREE_3:
                    me->RemoveAurasDueToSpell(SPELL_SHADOW_CAGE_DUMMY);
                    me->SetReactState(REACT_PASSIVE);
                    me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    me->SetImmuneToPC(false);
                    DoZoneInCombat();
                    Talk(EMOTE_BREAKS_FREE);
                    Talk(SAY_FREE);
                    instance->SetData(DATA_MANTICRON_CUBE, ACTION_ENABLE);
                    events.SetPhase(PHASE_2_BREAKS_FREE);
                    events.ScheduleEvent(EVENT_BREAK_FREE_4, 2s, EVENT_GROUP_BREAK_FREE);
                    break;
                case EVENT_BREAK_FREE_4:
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;

                // Phase 2, 3: Combat
                case EVENT_CLEAVE:
                    DoCastVictim(SPELL_CLEAVE);
                    events.Repeat(8s, 10s);
                    break;
                case EVENT_BLAZE:
                    DoCastAOE(SPELL_BLAZE);
                    events.Repeat(20s);
                    break;
                case EVENT_QUAKE:
                    DoCastSelf(SPELL_QUAKE);
                    events.Repeat(60s);
                    break;
                case EVENT_BLAST_NOVA:
                    DoCastSelf(SPELL_BLAST_NOVA);
                    events.Repeat(55s);
                    break;
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK);
                    break;

                // Phase 3: Collapse
                case EVENT_COLLAPSE_1:
                    Talk(SAY_COLLAPSE);
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    me->SetEmoteState(EMOTE_STATE_TALK);
                    events.ScheduleEvent(EVENT_COLLAPSE_2, 6s);
                    break;
                case EVENT_COLLAPSE_2:
                    me->SetEmoteState(EMOTE_ONESHOT_NONE);
                    instance->SetData(DATA_COLLAPSE_1, ACTION_ENABLE);
                    events.ScheduleEvent(EVENT_COLLAPSE_3, 1s);
                    break;
                case EVENT_COLLAPSE_3:
                    DoCastAOE(SPELL_CAMERA_SHAKE);
                    events.ScheduleEvent(EVENT_COLLAPSE_4, 5s);
                    break;
                case EVENT_COLLAPSE_4:
                    instance->SetData(DATA_COLLAPSE_2, ACTION_ENABLE);
                    events.ScheduleEvent(EVENT_COLLAPSE_5, 3s);
                    break;
                case EVENT_COLLAPSE_5:
                    if (Creature* trigger = instance->GetCreature(DATA_WORLD_TRIGGER))
                        trigger->CastSpell(trigger, SPELL_DEBRIS_KNOCKDOWN, true);
                    events.ScheduleEvent(EVENT_COLLAPSE_6, 1s);
                    break;
                case EVENT_COLLAPSE_6:
                    me->SetReactState(REACT_AGGRESSIVE);
                    events.ScheduleEvent(EVENT_DEBRIS, 20s);
                    break;

                // Phase 3: Combat
                case EVENT_DEBRIS:
                    DoCastAOE(SPELL_DEBRIS);
                    events.Repeat(20s);
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
    uint8 _channelersCount;
};

// 17256 - Hellfire Channeler
struct npc_hellfire_channeler : public ScriptedAI
{
    npc_hellfire_channeler(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript())
    {
        SetBoundary(_instance->GetBossBoundary(DATA_MAGTHERIDON));
    }

    void InitializeAI() override
    {
        ScriptedAI::InitializeAI();
        me->SetCorpseDelay(4, true);
        me->SetReactState(REACT_DEFENSIVE);
    }

    void JustAppeared() override
    {
        _scheduler.Schedule(5s, [this](TaskContext /*task*/)
        {
            DoCastSelf(SPELL_SHADOW_GRASP_CHANNELER);
        });
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.CancelAll();

        me->InterruptNonMeleeSpells(false);

        if (Creature* magtheridon = _instance->GetCreature(DATA_MAGTHERIDON))
            magtheridon->AI()->DoAction(ACTION_START_ENCOUNTER);

        _scheduler
            .SetValidator([this]
            {
                return !me->HasUnitState(UNIT_STATE_CASTING);
            })
            .Schedule(20s, 30s, [this](TaskContext task)
            {
                DoCastAOE(SPELL_SHADOW_BOLT_VOLLEY);
                task.Repeat(10s, 20s);
            })
            .Schedule(15s, 55s, [this](TaskContext task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_BURNING_ABYSSAL);
                task.Repeat(60s, 80s);
            })
            .Schedule(1200ms, [this](TaskContext task)
            {
                if (Unit* target = DoSelectBelowHpPctFriendlyWithEntry(NPC_HELLFIRE_CHANNELLER, 30.0f, 51, false))
                {
                    DoCast(target, SPELL_DARK_MENDING);
                    task.Repeat(10s, 20s);
                }
                else
                    task.Repeat(1200ms);
            })
            .Schedule(15s, 20s, [this](TaskContext task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1))
                    DoCast(target, SPELL_FEAR);
                task.Repeat(25s, 40s);
            });
    }

    void JustSummoned(Creature* summon) override
    {
        if (Creature* magtheridon = _instance->GetCreature(DATA_MAGTHERIDON))
            magtheridon->AI()->JustSummoned(summon);

        DoZoneInCombat(summon);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        if (_instance->GetBossState(DATA_MAGTHERIDON) == IN_PROGRESS)
            if (Creature* magtheridon = _instance->GetCreature(DATA_MAGTHERIDON))
                magtheridon->AI()->DoAction(ACTION_RESET_ENCOUNTER);
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoCastAOE(SPELL_SOUL_TRANSFER);

        // One-shotted channelers need trigger combat event too. It's needed for Cata+
        if (Creature* magtheridon = _instance->GetCreature(DATA_MAGTHERIDON))
            magtheridon->AI()->DoAction(ACTION_START_ENCOUNTER);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (UpdateVictim())
            DoMeleeAttackIfReady();
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

// 17516 - Magtheridon's Room
struct npc_magtheridon_room : public ScriptedAI
{
    using ScriptedAI::ScriptedAI;

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        _scheduler.Schedule(0s, [this](TaskContext task)
        {
            switch (task.GetRepeatCounter())
            {
                case 0:
                    DoCastSelf(SPELL_DEBRIS_VISUAL);
                    task.Repeat(5s);
                    break;
                case 1:
                    DoCastSelf(SPELL_DEBRIS_DAMAGE);
                    task.Repeat(5s);
                    break;
                case 2:
                    me->DespawnOrUnsummon();
                    break;
                default:
                    break;
            }
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 30541 - Blaze
class spell_magtheridon_blaze_target : public SpellScript
{
    PrepareSpellScript(spell_magtheridon_blaze_target);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BLAZE_SUMMON });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_BLAZE_SUMMON, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_magtheridon_blaze_target::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_magtheridon_blaze_target::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 30576 - Quake
class spell_magtheridon_quake_initial : public AuraScript
{
    PrepareAuraScript(spell_magtheridon_quake_initial);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_QUAKE_TARGET_SELECTOR });
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_QUAKE_TARGET_SELECTOR, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_magtheridon_quake_initial::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 30572 - Quake
class spell_magtheridon_quake_target_selector : public SpellScript
{
    PrepareSpellScript(spell_magtheridon_quake_target_selector);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_QUAKE_KNOCK_BACK, SPELL_QUAKE_PERIODIC });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        target->CastSpell(target, SPELL_QUAKE_KNOCK_BACK, true);
        target->CastSpell(target, SPELL_QUAKE_PERIODIC, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_magtheridon_quake_target_selector::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_magtheridon_quake_target_selector::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 30629 - Debris
class spell_magtheridon_debris : public SpellScript
{
    PrepareSpellScript(spell_magtheridon_debris);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DEBRIS_SUMMON });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_DEBRIS_SUMMON, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_magtheridon_debris::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_magtheridon_debris::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 30420 - Shadow Grasp
class spell_magtheridon_shadow_grasp_cube : public SpellScript
{
    PrepareSpellScript(spell_magtheridon_shadow_grasp_cube);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MIND_EXHAUSTION, SPELL_SHADOW_GRASP });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();

        if (target->HasAura(SPELL_MIND_EXHAUSTION) || target->HasAura(SPELL_SHADOW_GRASP))
            return;

        target->CastSpell(nullptr, SPELL_SHADOW_GRASP, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_magtheridon_shadow_grasp_cube::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 30410 - Shadow Grasp
class spell_magtheridon_shadow_grasp : public AuraScript
{
    PrepareAuraScript(spell_magtheridon_shadow_grasp);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MIND_EXHAUSTION, SPELL_SHADOW_GRASP_VISUAL });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(nullptr, SPELL_SHADOW_GRASP_VISUAL);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->InterruptNonMeleeSpells(false);
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_MIND_EXHAUSTION, true);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_magtheridon_shadow_grasp::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_magtheridon_shadow_grasp::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 30166 - Shadow Grasp
class spell_magtheridon_shadow_grasp_visual : public AuraScript
{
    PrepareAuraScript(spell_magtheridon_shadow_grasp_visual);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHADOW_CAGE });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        if (target->GetAuraCount(GetId()) == 5)
            target->CastSpell(target, SPELL_SHADOW_CAGE, true);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_SHADOW_CAGE);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_magtheridon_shadow_grasp_visual::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_magtheridon_shadow_grasp_visual::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_magtheridon()
{
    RegisterMagtheridonsLairCreatureAI(boss_magtheridon);
    RegisterMagtheridonsLairCreatureAI(npc_hellfire_channeler);
    RegisterMagtheridonsLairCreatureAI(npc_magtheridon_room);
    RegisterSpellScript(spell_magtheridon_blaze_target);
    RegisterSpellScript(spell_magtheridon_quake_initial);
    RegisterSpellScript(spell_magtheridon_quake_target_selector);
    RegisterSpellScript(spell_magtheridon_debris);
    RegisterSpellScript(spell_magtheridon_shadow_grasp_cube);
    RegisterSpellScript(spell_magtheridon_shadow_grasp);
    RegisterSpellScript(spell_magtheridon_shadow_grasp_visual);
}
