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
 * Timers requires to be revisited (timers seems to be different in different expansions or patches)
 * Many parts of this encounter requires sniff verification
 * Spell SPELL_STUN_SELF is guessed, based on effects received in packets
 * For some reason Leotheras is transparent until evade is triggered
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "serpent_shrine.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum LeotherasTexts
{
    // Leotheras the Blind
    SAY_DEMON_MORPH               = 0,
    SAY_DEMON_INNER_DEMONS        = 1,
    SAY_DEMON_SLAY                = 2,
    SAY_NIGHT_ELF_AGGRO           = 3,
    SAY_NIGHT_ELF_FINAL_FORM      = 4,
    SAY_NIGHT_ELF_SLAY            = 5,
    SAY_NIGHT_ELF_DEATH           = 6,

    // Shadow of Leotheras
    SAY_DEMON_FREE                = 0
};

enum LeotherasSpells
{
    // Leotheras the Blind - Initial
    SPELL_BANISH                  = 37546,

    // Leotheras the Blind - Combat
    SPELL_WHIRLWIND               = 37640,
    SPELL_METAMORPHOSIS           = 37673,
    SPELL_CHAOS_BLAST             = 37674,
    SPELL_INSIDIOUS_WHISPER       = 37676,
    SPELL_BERSERK                 = 27680,

    // Leotheras the Blind - Combat - Misc
    SPELL_STUN_SELF               = 25900,
    SPELL_SUMMON_SHADOW           = 37781,
    SPELL_CLEAR_CONSUMING_MADNESS = 37750,

    // Greyheart Spellbinder
    SPELL_GREEN_BEAM              = 37626,
    SPELL_MIND_BLAST              = 37531,
    SPELL_SPELL_SHOCK             = 39076,

    // Inner Demon
    SPELL_DEMONIC_ALIGNMENT       = 37713,
    SPELL_DETECTION               = 18950,
    SPELL_DEMON_LINK              = 37716,
    SPELL_SHADOW_BOLT             = 39309,

    // Shadow of Leotheras
    SPELL_SHRINK                  = 37780,

    // Scripts
    SPELL_CHAOS_BLAST_DAMAGE      = 37675,
    SPELL_TARGET_1                = 37725,
    SPELL_TARGET_2                = 37726,
    SPELL_TARGET_3                = 37731,
    SPELL_TARGET_4                = 37732,
    SPELL_TARGET_5                = 37733,
    SPELL_CONSUMING_MADNESS       = 37749,
    SPELL_SUMMON_INNER_DEMON      = 37735
};

enum LeotherasEvents
{
    // Out of Combat
    EVENT_FORCE_CHANNEL           = 1,

    // Combat
    EVENT_WHIRLWIND,
    EVENT_METAMORPHOSIS,
    EVENT_CHAOS_BLAST,
    EVENT_INSIDIOUS_WHISPER,
    EVENT_BERSERK,

    // Transition
    EVENT_TRANSITION_1,
    EVENT_TRANSITION_2,
    EVENT_TRANSITION_3,
    EVENT_TRANSITION_4,
    EVENT_TRANSITION_5
};

enum LeotherasActions
{
    ACTION_SPELLBINDER_DIES       = 0,
    ACTION_RESET_ENCOUNTER        = 1,
    ACTION_START_CHANNELING       = 2,
    ACTION_METAMORPHOSIS_APPLIED  = 3,
    ACTION_METAMORPHOSIS_REMOVED  = 4
};

enum LeotherasMisc
{
    FACTION_LEOTHERAS_DEMON_1     = 1829,
    FACTION_LEOTHERAS_DEMON_2     = 1830,
    FACTION_LEOTHERAS_DEMON_3     = 1831,
    FACTION_LEOTHERAS_DEMON_4     = 1832,
    FACTION_LEOTHERAS_DEMON_5     = 1833,
    MAX_SPELLBINDERS              = 3,
    NPC_GREYHEART_SPELLBINDER     = 21806
};

enum LeotherasSpawnGroups
{
    SPAWN_GROUP_SPELLBINDER_1     = 365,
    SPAWN_GROUP_SPELLBINDER_2     = 366,
    SPAWN_GROUP_SPELLBINDER_3     = 367
};

static constexpr std::array<uint32, 3> SpellbindersSpawnGroupsData =
{
    SPAWN_GROUP_SPELLBINDER_1,
    SPAWN_GROUP_SPELLBINDER_2,
    SPAWN_GROUP_SPELLBINDER_3
};

static constexpr std::array<uint32, 5> ForceReactionSpells =
{
    SPELL_TARGET_1,
    SPELL_TARGET_2,
    SPELL_TARGET_3,
    SPELL_TARGET_4,
    SPELL_TARGET_5
};

static constexpr std::pair<uint32, uint32> DemonFaction[5] =
{
    { SPELL_TARGET_1, FACTION_LEOTHERAS_DEMON_1 },
    { SPELL_TARGET_2, FACTION_LEOTHERAS_DEMON_2 },
    { SPELL_TARGET_3, FACTION_LEOTHERAS_DEMON_3 },
    { SPELL_TARGET_4, FACTION_LEOTHERAS_DEMON_4 },
    { SPELL_TARGET_5, FACTION_LEOTHERAS_DEMON_5 }
};

// 21215 - Leotheras the Blind
struct boss_leotheras_the_blind : public BossAI
{
    boss_leotheras_the_blind(Creature* creature) : BossAI(creature, BOSS_LEOTHERAS_THE_BLIND),
        _deadSpellbindersCount(0), _isStartedTransition(false) { }

    void Reset() override
    {
        _Reset();

        _isStartedTransition = false;

        me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
        me->SetReactState(REACT_AGGRESSIVE);
        me->SetIsCombatDisallowed(true);
        me->SetCanDualWield(true);
        SetEquipmentSlots(true);
    }

    void JustAppeared() override
    {
        events.ScheduleEvent(EVENT_FORCE_CHANNEL, 15s, 25s);

        me->ApplySpellImmune(-1, IMMUNITY_MECHANIC, MECHANIC_BANISH, false);
        DoCastSelf(SPELL_BANISH);
        me->ApplySpellImmune(-1, IMMUNITY_MECHANIC, MECHANIC_BANISH, true);

        for (uint32 group : SpellbindersSpawnGroupsData)
            me->GetMap()->SpawnGroupSpawn(group, true);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_NIGHT_ELF_AGGRO);

        events.ScheduleEvent(EVENT_WHIRLWIND, 15s, 25s);
        events.ScheduleEvent(EVENT_METAMORPHOSIS, 60s);
        events.ScheduleEvent(EVENT_BERSERK, 10min);
    }

    void AttackStart(Unit* who) override
    {
        if (me->HasAura(SPELL_METAMORPHOSIS))
            BossAI::AttackStartCaster(who, 40.0f);
        else
            BossAI::AttackStart(who);
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_INSIDIOUS_WHISPER)
            Talk(SAY_DEMON_INNER_DEMONS);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_isStartedTransition && me->HealthBelowPctDamaged(15, damage))
        {
            _isStartedTransition = true;
            events.ScheduleEvent(EVENT_TRANSITION_1, 0s);
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_SPELLBINDER_DIES:
            {
                _deadSpellbindersCount++;

                if (_deadSpellbindersCount == MAX_SPELLBINDERS)
                {
                    me->RemoveAurasDueToSpell(SPELL_BANISH);
                    me->SetIsCombatDisallowed(false);
                    DoZoneInCombat();
                    _deadSpellbindersCount = 0;
                }
                break;
            }
            case ACTION_RESET_ENCOUNTER:
                _deadSpellbindersCount = 0;
                for (uint32 group : SpellbindersSpawnGroupsData)
                    me->GetMap()->SpawnGroupSpawn(group, true);
                break;
            case ACTION_METAMORPHOSIS_APPLIED:
                me->RemoveAurasDueToSpell(SPELL_WHIRLWIND);
                Talk(SAY_DEMON_MORPH);
                SetEquipmentSlots(false, EQUIP_UNEQUIP, EQUIP_UNEQUIP, EQUIP_NO_CHANGE);
                ResetThreatList();

                events.CancelEvent(EVENT_WHIRLWIND);
                events.ScheduleEvent(EVENT_CHAOS_BLAST, 0s);
                events.ScheduleEvent(EVENT_INSIDIOUS_WHISPER, 20s);
                break;
            case ACTION_METAMORPHOSIS_REMOVED:
                SetEquipmentSlots(true);
                ResetThreatList();

                me->InterruptNonMeleeSpells(false);

                // Without this AttackStartCaster gets stuck if Leotheras uses Consuming Madness. Investigate this
                if (Unit* victim = me->GetVictim())
                    me->GetMotionMaster()->MoveChase(victim);

                events.CancelEvent(EVENT_CHAOS_BLAST);
                events.CancelEvent(EVENT_INSIDIOUS_WHISPER);
                events.ScheduleEvent(EVENT_WHIRLWIND, 15s, 25s);
                break;
            default:
                break;
        }
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        BossAI::EnterEvadeMode(why);

        DoCastSelf(SPELL_CLEAR_CONSUMING_MADNESS, true);
    }

    void JustReachedHome() override
    {
        _JustReachedHome();

        me->ApplySpellImmune(-1, IMMUNITY_MECHANIC, MECHANIC_BANISH, false);
        DoCastSelf(SPELL_BANISH);
        me->ApplySpellImmune(-1, IMMUNITY_MECHANIC, MECHANIC_BANISH, true);

        events.ScheduleEvent(EVENT_FORCE_CHANNEL, 15s, 25s);

        DoAction(ACTION_RESET_ENCOUNTER);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() != TYPEID_PLAYER)
            return;

        Talk(me->HasAura(SPELL_METAMORPHOSIS) ? SAY_DEMON_SLAY : SAY_NIGHT_ELF_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_NIGHT_ELF_DEATH);

        DoCastSelf(SPELL_CLEAR_CONSUMING_MADNESS, true);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                if (eventId == EVENT_FORCE_CHANNEL)
                {
                    std::vector<Creature*> spellbinders;
                    GetCreatureListWithEntryInGrid(spellbinders, me, NPC_GREYHEART_SPELLBINDER, 20.0f);
                    for (Creature* spellbinder : spellbinders)
                        spellbinder->AI()->DoAction(ACTION_START_CHANNELING);

                    events.Repeat(15s, 25s);
                }
            }

            return;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                // Combat
                case EVENT_WHIRLWIND:
                    DoCastSelf(SPELL_WHIRLWIND);
                    events.Repeat(25s, 35s);
                    break;
                case EVENT_METAMORPHOSIS:
                    DoCastSelf(SPELL_METAMORPHOSIS);
                    events.Repeat(120s);
                    break;
                case EVENT_CHAOS_BLAST:
                    DoCastVictim(SPELL_CHAOS_BLAST);
                    events.Repeat(2400ms);
                    break;
                case EVENT_INSIDIOUS_WHISPER:
                    DoCastSelf(SPELL_INSIDIOUS_WHISPER);
                    break;
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK);
                    break;

                // Transition
                case EVENT_TRANSITION_1:
                    me->RemoveAurasDueToSpell(SPELL_WHIRLWIND);
                    me->RemoveAurasDueToSpell(SPELL_METAMORPHOSIS);
                    me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    me->SetReactState(REACT_PASSIVE);

                    DoCastSelf(SPELL_STUN_SELF);

                    Talk(SAY_NIGHT_ELF_FINAL_FORM);

                    SetEquipmentSlots(true);

                    events.CancelEvent(EVENT_CHAOS_BLAST);
                    events.CancelEvent(EVENT_INSIDIOUS_WHISPER);
                    events.CancelEvent(EVENT_METAMORPHOSIS);
                    events.CancelEvent(EVENT_WHIRLWIND);

                    events.ScheduleEvent(EVENT_TRANSITION_2, 1200ms);
                    break;
                case EVENT_TRANSITION_2:
                    ResetThreatList();
                    me->SetStandState(UNIT_STAND_STATE_KNEEL);
                    events.ScheduleEvent(EVENT_TRANSITION_3, 6s);
                    break;
                case EVENT_TRANSITION_3:
                    DoCastSelf(SPELL_SUMMON_SHADOW, true);
                    events.ScheduleEvent(EVENT_TRANSITION_4, 3600ms);
                    break;
                case EVENT_TRANSITION_4:
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    events.ScheduleEvent(EVENT_TRANSITION_5, 1200ms);
                    break;
                case EVENT_TRANSITION_5:
                    me->RemoveAurasDueToSpell(SPELL_STUN_SELF);
                    me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    me->SetReactState(REACT_AGGRESSIVE);
                    events.ScheduleEvent(EVENT_WHIRLWIND, 15s, 25s);
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
    uint8 _deadSpellbindersCount;
    bool _isStartedTransition;
};

// 21875 - Shadow of Leotheras
struct npc_shadow_of_leotheras : public ScriptedAI
{
    using ScriptedAI::ScriptedAI;

    void JustAppeared() override
    {
        _scheduler.Schedule(0s, [this](TaskContext task)
        {
            switch (task.GetRepeatCounter())
            {
                case 0:
                    me->SetReactState(REACT_PASSIVE);
                    DoCastSelf(SPELL_SHRINK);
                    task.Repeat(3s);
                    break;
                case 1:
                    me->RemoveAurasDueToSpell(SPELL_SHRINK);
                    task.Repeat(2s);
                    break;
                case 2:
                    Talk(SAY_DEMON_FREE);
                    DoZoneInCombat();
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    break;
                default:
                    break;
            }
        });
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(0s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_CHAOS_BLAST);
            task.Repeat(2400ms);
        });
    }

    void AttackStart(Unit* who) override
    {
        ScriptedAI::AttackStartCaster(who, 40.0f);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
};

// 21806 - Greyheart Spellbinder
struct npc_greyheart_spellbinder : public ScriptedAI
{
    npc_greyheart_spellbinder(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript()) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_GREEN_BEAM);
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        me->InterruptNonMeleeSpells(false);

        _scheduler
            .SetValidator([this]
            {
                return !me->HasUnitState(UNIT_STATE_CASTING);
            })
            .Schedule(10s, 20s, [this](TaskContext task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 20.0f))
                    DoCast(target, SPELL_MIND_BLAST);
                task.Repeat(15s, 25s);
            })
            .Schedule(5s, 10s, [this](TaskContext task)
            {
                std::vector<Player*> playerList;
                GetPlayerListInGrid(playerList, me, 45.0f);
                for (Player* player : playerList)
                {
                    if (player->IsNonMeleeSpellCast(false))
                    {
                        DoCast(player, SPELL_SPELL_SHOCK);
                        break;
                    }
                }
                task.Repeat(10s, 15s);
            });
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_START_CHANNELING && me->IsAlive() && !me->IsInCombat() && !me->IsInEvadeMode())
            DoCastSelf(SPELL_GREEN_BEAM);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode(why);

        if (Creature* leotheras = _instance->GetCreature(BOSS_LEOTHERAS_THE_BLIND))
            leotheras->AI()->DoAction(ACTION_RESET_ENCOUNTER);
    }

    void JustReachedHome() override
    {
        DoCastSelf(SPELL_GREEN_BEAM);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* leotheras = _instance->GetCreature(BOSS_LEOTHERAS_THE_BLIND))
            leotheras->AI()->DoAction(ACTION_SPELLBINDER_DIES);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

// 21857 - Inner Demon
struct npc_inner_demon : public ScriptedAI
{
    using ScriptedAI::ScriptedAI;

    void InitializeAI() override
    {
        ScriptedAI::InitializeAI();

        if (TempSummon* summon = me->ToTempSummon())
            if (Unit* summoner = summon->GetSummonerUnit())
                for (auto [spellId, factionTemplateId] : DemonFaction)
                    if (summoner->HasAura(spellId))
                        me->SetFaction(factionTemplateId);
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_DEMONIC_ALIGNMENT);
        DoCastSelf(SPELL_DETECTION);
        DoCastSelf(SPELL_DEMON_LINK);

        if (TempSummon* summon = me->ToTempSummon())
        {
            if (Unit* summoner = summon->GetSummonerUnit())
            {
                AddThreat(summoner, 50000.0f);
                AttackStart(summoner);
            }
        }
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(5s, 10s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_SHADOW_BOLT);
            task.Repeat(5s, 10s);
        });
    }

    void JustDied(Unit* killer) override
    {
        killer->RemoveAurasDueToSpell(SPELL_INSIDIOUS_WHISPER);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

private:
    TaskScheduler _scheduler;
};

// 37640 - Whirlwind
class spell_leotheras_the_blind_whirlwind_init : public SpellScript
{
    PrepareSpellScript(spell_leotheras_the_blind_whirlwind_init);

    void HandleAfterCast()
    {
        Creature* caster = GetCaster()->ToCreature();
        if (!caster)
            return;

        caster->GetThreatManager().ResetAllThreat();
        if (Unit* target = caster->AI()->SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
            caster->GetThreatManager().AddThreat(target, 100000.0f);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_leotheras_the_blind_whirlwind_init::HandleAfterCast);
    }
};

// 37641 - Whirlwind
class spell_leotheras_the_blind_whirlwind_effect : public SpellScript
{
    PrepareSpellScript(spell_leotheras_the_blind_whirlwind_effect);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Creature* caster = GetCaster()->ToCreature();
        if (!caster)
            return;

        SpellInfo const* spellInfo = GetTriggeringSpell();
        if (!spellInfo)
            return;

        if (AuraEffect const* eff = caster->GetAuraEffect(spellInfo->Id, EFFECT_0))
        {
            if (eff->GetTickNumber() != spellInfo->GetMaxTicks())
            {
                if (roll_chance_i(50))
                {
                    caster->GetThreatManager().ResetAllThreat();
                    if (Unit* target = caster->AI()->SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                        caster->GetThreatManager().AddThreat(target, 100000.0f);
                }
            }
            else
                caster->GetThreatManager().ResetAllThreat();
        }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_leotheras_the_blind_whirlwind_effect::HandleScript, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 37673 - Metamorphosis
class spell_leotheras_the_blind_metamorphosis : public AuraScript
{
    PrepareAuraScript(spell_leotheras_the_blind_metamorphosis);

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* target = GetTarget()->ToCreature())
            target->AI()->DoAction(ACTION_METAMORPHOSIS_APPLIED);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        if (Creature* target = GetTarget()->ToCreature())
            target->AI()->DoAction(ACTION_METAMORPHOSIS_REMOVED);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_leotheras_the_blind_metamorphosis::AfterApply, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_leotheras_the_blind_metamorphosis::AfterRemove, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
    }
};

// 37674 - Chaos Blast
class spell_leotheras_the_blind_chaos_blast : public SpellScript
{
    PrepareSpellScript(spell_leotheras_the_blind_chaos_blast);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CHAOS_BLAST_DAMAGE });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_CHAOS_BLAST_DAMAGE);

        GetCaster()->CastSpell(GetHitUnit(), SPELL_CHAOS_BLAST_DAMAGE, CastSpellExtraArgs()
            .SetTriggerFlags(TRIGGERED_FULL_MASK)
            .AddSpellMod(SPELLVALUE_BASE_POINT0, spellInfo->GetEffect(EFFECT_1).CalcValue()));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_leotheras_the_blind_chaos_blast::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 37676 - Insidious Whisper
class spell_leotheras_the_blind_insidious_whisper : public SpellScript
{
    PrepareSpellScript(spell_leotheras_the_blind_insidious_whisper);

public:
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(ForceReactionSpells);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove(GetCaster()->GetVictim());
        Trinity::Containers::RandomResize(targets, 5);
    }

    void HandleEffect(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), ForceReactionSpells[std::min(_targetCount, ForceReactionSpells.size() - 1)], true);
        _targetCount++;
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_leotheras_the_blind_insidious_whisper::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_leotheras_the_blind_insidious_whisper::HandleEffect, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }

private:
    std::size_t _targetCount = 0;
};

class spell_leotheras_the_blind_insidious_whisper_aura : public AuraScript
{
    PrepareAuraScript(spell_leotheras_the_blind_insidious_whisper_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(ForceReactionSpells) && ValidateSpellInfo({ SPELL_CONSUMING_MADNESS });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        for (uint32 spell : ForceReactionSpells)
            target->RemoveAurasDueToSpell(spell);

        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        if (Unit* caster = GetCaster())
            caster->CastSpell(target, SPELL_CONSUMING_MADNESS, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_leotheras_the_blind_insidious_whisper_aura::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

/* 37725 - Target 1
   37726 - Target 2
   37731 - Target 3
   37732 - Target 4
   37733 - Target 5 */
class spell_leotheras_the_blind_summon_inner_demon : public SpellScript
{
    PrepareSpellScript(spell_leotheras_the_blind_summon_inner_demon);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_INNER_DEMON });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SUMMON_INNER_DEMON, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_leotheras_the_blind_summon_inner_demon::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 37750 - Clear Consuming Madness
class spell_leotheras_the_blind_clear_consuming_madness : public SpellScript
{
    PrepareSpellScript(spell_leotheras_the_blind_clear_consuming_madness);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_INSIDIOUS_WHISPER, SPELL_CONSUMING_MADNESS });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->RemoveAurasDueToSpell(SPELL_INSIDIOUS_WHISPER);
        GetHitUnit()->RemoveAurasDueToSpell(SPELL_CONSUMING_MADNESS);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_leotheras_the_blind_clear_consuming_madness::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 37716 - Demon Link
class spell_leotheras_the_blind_demon_link : public AuraScript
{
    PrepareAuraScript(spell_leotheras_the_blind_demon_link);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void OnPeriodic(AuraEffect const* aurEff)
    {
        PreventDefaultAction();

        Unit* target = GetTarget();
        Unit* victim = target->GetVictim();
        if (victim)
            target->CastSpell(victim, aurEff->GetSpellEffectInfo().TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_leotheras_the_blind_demon_link::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

void AddSC_boss_leotheras_the_blind()
{
    RegisterSerpentshrineCavernCreatureAI(boss_leotheras_the_blind);
    RegisterSerpentshrineCavernCreatureAI(npc_shadow_of_leotheras);
    RegisterSerpentshrineCavernCreatureAI(npc_greyheart_spellbinder);
    RegisterSerpentshrineCavernCreatureAI(npc_inner_demon);
    RegisterSpellScript(spell_leotheras_the_blind_whirlwind_init);
    RegisterSpellScript(spell_leotheras_the_blind_whirlwind_effect);
    RegisterSpellScript(spell_leotheras_the_blind_metamorphosis);
    RegisterSpellScript(spell_leotheras_the_blind_chaos_blast);
    RegisterSpellAndAuraScriptPair(spell_leotheras_the_blind_insidious_whisper, spell_leotheras_the_blind_insidious_whisper_aura);
    RegisterSpellScript(spell_leotheras_the_blind_summon_inner_demon);
    RegisterSpellScript(spell_leotheras_the_blind_clear_consuming_madness);
    RegisterSpellScript(spell_leotheras_the_blind_demon_link);
}
