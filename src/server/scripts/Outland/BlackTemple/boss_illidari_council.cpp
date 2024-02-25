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
#include "black_temple.h"
#include "CellImpl.h"
#include "Containers.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum Says
{
    SAY_COUNCIL_AGRO     = 0,
    SAY_COUNCIL_ENRAGE   = 1,
    SAY_COUNCIL_SPECIAL  = 2,
    SAY_COUNCIL_SLAY     = 3,
    SAY_COUNCIL_COMNT    = 4,
    SAY_COUNCIL_DEATH    = 5
};

enum Spells
{
    // Illidari Council (Trigger)
    SPELL_EMPYREAL_BALANCE         = 41499,
    SPELL_EMPYREAL_EQUIVALENCY     = 41333,

    // Generic
    SPELL_SHARED_RULE              = 41342,
    SPELL_BERSERK                  = 45078,
    SPELL_BALANCE_OF_POWER         = 41341,
    SPELL_QUIET_SUICIDE            = 3617,

    // High Nethermancer Zerevor's
    SPELL_FLAMESTRIKE              = 41481,
    SPELL_BLIZZARD                 = 41482,
    SPELL_ARCANE_BOLT              = 41483,
    SPELL_ARCANE_EXPLOSION         = 41524,
    SPELL_DAMPEN_MAGIC             = 41478,

    // Lady Malande's
    SPELL_EMPOWERED_SMITE          = 41471,
    SPELL_CIRCLE_OF_HEALING        = 41455,
    SPELL_REFLECTIVE_SHIELD        = 41475,
    SPELL_REFLECTIVE_SHIELD_DAMAGE = 33619,
    SPELL_DIVINE_WRATH             = 41472,

    // Gathios the Shatterer's
    SPELL_BLESS_PROTECTION         = 41450,
    SPELL_BLESS_SPELL_WARDING      = 41451,
    SPELL_CONSECRATION             = 41541,
    SPELL_HAMMER_OF_JUSTICE        = 41468,
    SPELL_SEAL_OF_COMMAND          = 41469,
    SPELL_SEAL_OF_BLOOD            = 41459,
    SPELL_CHROMATIC_AURA           = 41453,
    SPELL_DEVOTION_AURA            = 41452,
    SPELL_JUDGEMENT_PRIMER         = 41473,
    SPELL_JUDGEMENT                = 41467,
    SPELL_JUDGEMENT_OF_COMMAND     = 41470,
    SPELL_JUDGEMENT_OF_BLOOD       = 41461,

    // Veras Darkshadow's
    SPELL_DEADLY_STRIKE             = 41480,
    SPELL_DEADLY_POISON             = 41485,
    SPELL_ENVENOM                   = 41487,
    SPELL_ENVENOM_VISUAL            = 41509,
    SPELL_VANISH                    = 41476,
    SPELL_VANISH_TELEPORT           = 41479,

    // Veras Vanish Effect
    SPELL_BIRTH                     = 40031,
    SPELL_ENVENOM_DUMMY             = 41510
};

enum IllidariEvents
{
    EVENT_EMPYREAL_EQUIVALENCY = 1,
    EVENT_VANISH,
    EVENT_FLAMESTRIKE,
    EVENT_BLIZZARD,
    EVENT_ARCANE_EXPLOSION,
    EVENT_ARCANE_EXPLOSION_CHECK,
    EVENT_DAMPEN_MAGIC,
    EVENT_BLESS,
    EVENT_CONSECRATION,
    EVENT_AURA,
    EVENT_JUDGEMENT,
    EVENT_HAMMER_OF_JUSTICE,
    EVENT_CIRCLE_OF_HEALING,
    EVENT_REFLECTIVE_SHIELD,
    EVENT_DIVINE_WRATH,
    EVENT_BERSERK
};

enum IllidariMisc
{
    SUMMON_COUNCIL_GROUP = 1,
    ACTION_REFRESH_DAMPEN
};

uint32 const CouncilData[4] =
{
    DATA_GATHIOS_THE_SHATTERER,
    DATA_HIGH_NETHERMANCER_ZEREVOR,
    DATA_LADY_MALANDE,
    DATA_VERAS_DARKSHADOW
};

static uint32 GetRandomBossExcept(uint32 exception)
{
    std::vector<uint32> bossData;
    for (uint32 data : CouncilData)
        if (data != exception)
            bossData.emplace_back(data);

    return Trinity::Containers::SelectRandomContainerElement(bossData);
}

struct boss_illidari_council : public BossAI
{
    boss_illidari_council(Creature* creature) : BossAI(creature, DATA_ILLIDARI_COUNCIL), _inCombat(false) { }

    void Reset() override
    {
        _Reset();
        _inCombat = false;
        me->SummonCreatureGroup(SUMMON_COUNCIL_GROUP);
    }

    void JustEngagedWith(Unit* who) override
    {
        if (!_inCombat)
        {
            _inCombat = true;
            BossAI::JustEngagedWith(who);
            DoCastSelf(SPELL_EMPYREAL_BALANCE, true);
            for (uint32 bossData : CouncilData)
            {
                if (Creature* council = instance->GetCreature(bossData))
                {
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, council);
                    DoZoneInCombat(council);
                }
            }
            events.ScheduleEvent(EVENT_EMPYREAL_EQUIVALENCY, 2s);
            events.ScheduleEvent(EVENT_BERSERK, 15min);
            if (Creature* council = instance->GetCreature(CouncilData[urand(0, 3)]))
                council->AI()->Talk(SAY_COUNCIL_AGRO);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        if (!me->IsInEvadeMode())
        {
            _inCombat = false;
            for (uint32 bossData : CouncilData)
                if (Creature* council = instance->GetCreature(bossData))
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, council);

            summons.DespawnAll();
            _DespawnAtEvade();
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _inCombat = false;
        events.Reset();
        instance->SetBossState(DATA_ILLIDARI_COUNCIL, DONE);

        for (uint32 bossData : CouncilData)
        {
            if (Creature* council = instance->GetCreature(bossData))
            {
                // Allow loot
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, council);
                council->LowerPlayerDamageReq(council->GetMaxHealth());
                council->CastSpell(council, SPELL_QUIET_SUICIDE, true);
            }
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
            switch (eventId)
            {
                case EVENT_EMPYREAL_EQUIVALENCY:
                    DoCastSelf(SPELL_EMPYREAL_EQUIVALENCY, true);
                    events.Repeat(Seconds(2));
                    break;
                case EVENT_BERSERK:
                    for (uint32 bossData : CouncilData)
                    {
                        if (Creature* council = instance->GetCreature(bossData))
                        {
                            council->CastSpell(council, SPELL_BERSERK, true);
                            council->AI()->Talk(SAY_COUNCIL_ENRAGE);
                        }
                    }
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    bool _inCombat;
};

struct IllidariCouncilBossAI : public BossAI
{
    IllidariCouncilBossAI(Creature* creature, uint32 bossId) : BossAI(creature, bossId), _bossId(bossId)
    {
        SetBoundary(instance->GetBossBoundary(DATA_ILLIDARI_COUNCIL));
    }

    void Reset() override
    {
        me->SetCombatPulseDelay(0);
        events.Reset();
        DoCastSelf(SPELL_BALANCE_OF_POWER, true);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        me->SetCombatPulseDelay(5);
        me->setActive(true);
        if (Creature* illidari = instance->GetCreature(DATA_ILLIDARI_COUNCIL))
            DoZoneInCombat(illidari);
        ScheduleEvents();
    }

    virtual void ScheduleEvents() = 0;

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_COUNCIL_DEATH);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        if (Creature* illidari = instance->GetCreature(DATA_ILLIDARI_COUNCIL))
            illidari->AI()->EnterEvadeMode(why);
    }

    void DamageTaken(Unit* who, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth() && (!who || who->GetGUID() != me->GetGUID()))
            damage = me->GetHealth() - 1;
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_COUNCIL_SLAY);

        if (roll_chance_i(30))
            if (Creature* boss = instance->GetCreature(GetRandomBossExcept(_bossId)))
                boss->AI()->Talk(SAY_COUNCIL_COMNT);
    }

private:
    uint32 _bossId;
};

class HammerTargetSelector
{
public:
    HammerTargetSelector(Unit const* unit) : _me(unit) { }

    bool operator()(Unit* unit) const
    {
        return _me->IsInRange(unit, 10.0f, 40.0f);
    }

private:
    Unit const* _me;
};

struct boss_gathios_the_shatterer : public IllidariCouncilBossAI
{
    boss_gathios_the_shatterer(Creature* creature) : IllidariCouncilBossAI(creature, DATA_GATHIOS_THE_SHATTERER) { }

    void ScheduleEvents() override
    {
        DoCastSelf(SPELL_SEAL_OF_BLOOD);
        events.ScheduleEvent(EVENT_BLESS, 20s);
        events.ScheduleEvent(EVENT_CONSECRATION, 10s);
        events.ScheduleEvent(EVENT_HAMMER_OF_JUSTICE, 10s);
        events.ScheduleEvent(EVENT_JUDGEMENT, 15s);
        events.ScheduleEvent(EVENT_AURA, 6s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_BLESS:
            {
                std::list<Unit*> TargetList;
                Trinity::AnyFriendlyUnitInObjectRangeCheck checker(me, me, 100.0f);
                Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(me, TargetList, checker);
                Cell::VisitAllObjects(me, searcher, 100.0f);

                if (!TargetList.empty())
                {
                    Unit* target = Trinity::Containers::SelectRandomContainerElement(TargetList);
                    DoCast(target, RAND(SPELL_BLESS_PROTECTION, SPELL_BLESS_SPELL_WARDING));
                }
                events.Repeat(Seconds(30), Seconds(45));
                break;
            }
            case EVENT_AURA:
                DoCastSelf(RAND(SPELL_CHROMATIC_AURA, SPELL_DEVOTION_AURA));
                events.Repeat(Seconds(30));
                break;
            case EVENT_HAMMER_OF_JUSTICE:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, HammerTargetSelector(me)))
                    DoCast(target, SPELL_HAMMER_OF_JUSTICE);
                events.Repeat(Seconds(20));
                break;
            case EVENT_JUDGEMENT:
                DoCastVictim(SPELL_JUDGEMENT);
                events.Repeat(Seconds(15));
                break;
            case EVENT_CONSECRATION:
                DoCastSelf(SPELL_CONSECRATION);
                events.Repeat(Seconds(30), Seconds(35));
                break;
            default:
                break;
        }
    }
};

struct boss_high_nethermancer_zerevor : public IllidariCouncilBossAI
{
    boss_high_nethermancer_zerevor(Creature* creature) : IllidariCouncilBossAI(creature, DATA_HIGH_NETHERMANCER_ZEREVOR), _canUseArcaneExplosion(true) { }

    void Reset() override
    {
        IllidariCouncilBossAI::Reset();
        _canUseArcaneExplosion = true;
        DoCastSelf(SPELL_DAMPEN_MAGIC);
    }

    void ScheduleEvents() override
    {
        events.ScheduleEvent(EVENT_FLAMESTRIKE, 8s);
        events.ScheduleEvent(EVENT_BLIZZARD, 25s);
        events.ScheduleEvent(EVENT_ARCANE_EXPLOSION, 5s);
        DoCastSelf(SPELL_DAMPEN_MAGIC);
    }

    void DoAction(int32 actionId) override
    {
        if (actionId == ACTION_REFRESH_DAMPEN)
            events.ScheduleEvent(EVENT_DAMPEN_MAGIC, 50s);
    }
    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_FLAMESTRIKE:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_FLAMESTRIKE);
                Talk(SAY_COUNCIL_SPECIAL);
                events.Repeat(Seconds(40));
                break;
            case EVENT_BLIZZARD:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_BLIZZARD);
                events.Repeat(Seconds(15), Seconds(40));
                break;
            case EVENT_ARCANE_EXPLOSION_CHECK:
                _canUseArcaneExplosion = true;
                break;
            case EVENT_ARCANE_EXPLOSION:
                if (_canUseArcaneExplosion && SelectTarget(SelectTargetMethod::Random, 0, 10.0f))
                {
                    DoCastSelf(SPELL_ARCANE_EXPLOSION);
                    _canUseArcaneExplosion = false;
                    events.ScheduleEvent(EVENT_ARCANE_EXPLOSION_CHECK, 5s);
                }
                events.Repeat(Seconds(1));
                break;
            case EVENT_DAMPEN_MAGIC:
                DoCastSelf(SPELL_DAMPEN_MAGIC);
                break;
            default:
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

        DoSpellAttackIfReady(SPELL_ARCANE_BOLT);
    }

private:
    bool _canUseArcaneExplosion;
};

struct boss_lady_malande : public IllidariCouncilBossAI
{
    boss_lady_malande(Creature* creature) : IllidariCouncilBossAI(creature, DATA_LADY_MALANDE)
    {
        me->SetCanMelee(false); // DoSpellAttackIfReady
    }

    void ScheduleEvents() override
    {
        events.ScheduleEvent(EVENT_CIRCLE_OF_HEALING, 20s);
        events.ScheduleEvent(EVENT_REFLECTIVE_SHIELD, 25s);
        events.ScheduleEvent(EVENT_DIVINE_WRATH, 32s);
    }

    void HealReceived(Unit* /*who*/, uint32& addhealth) override
    {
        // Need be negative to heal trigger
        me->CastSpell(nullptr, SPELL_SHARED_RULE, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellBP0(-int32(addhealth)));
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_CIRCLE_OF_HEALING:
                DoCastSelf(SPELL_CIRCLE_OF_HEALING);
                events.Repeat(Seconds(20), Seconds(35));
                break;
            case EVENT_REFLECTIVE_SHIELD:
                DoCastSelf(SPELL_REFLECTIVE_SHIELD);
                Talk(SAY_COUNCIL_SPECIAL);
                events.Repeat(Seconds(40));
                break;
            case EVENT_DIVINE_WRATH:
                DoCastVictim(SPELL_DIVINE_WRATH);
                events.Repeat(Seconds(20));
                break;
            default:
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

        DoSpellAttackIfReady(SPELL_EMPOWERED_SMITE);
    }
};

struct boss_veras_darkshadow : public IllidariCouncilBossAI
{
    boss_veras_darkshadow(Creature* creature) : IllidariCouncilBossAI(creature, DATA_VERAS_DARKSHADOW) { }

    void ScheduleEvents() override
    {
        events.ScheduleEvent(EVENT_VANISH, 18s);
    }

    bool CanSeeAlways(WorldObject const* who) override
    {
        return me->HasAura(SPELL_VANISH) ? true : ScriptedAI::CanSeeAlways(who);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_VANISH:
                Talk(SAY_COUNCIL_SPECIAL);
                DoCastSelf(SPELL_VANISH);
                DoCastSelf(SPELL_DEADLY_STRIKE);
                events.Repeat(Seconds(60));
                break;
            default:
                break;
        }
    }
};

struct npc_veras_vanish_effect : public PassiveAI
{
    npc_veras_vanish_effect(Creature* creature) : PassiveAI(creature) { }

    void Reset() override
    {
        DoCastSelf(SPELL_BIRTH, true);
        _scheduler.Schedule(Seconds(1), [this](TaskContext /*context*/)
        {
            DoCastSelf(SPELL_ENVENOM_DUMMY, true);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 41499 - Empyreal Balance
class spell_illidari_council_empyreal_balance : public SpellScript
{
    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        uint32 health = GetCaster()->CountPctFromCurHealth(25);
        target->SetMaxHealth(health);
        target->SetHealth(health);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_illidari_council_empyreal_balance::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 41333 - Empyreal Equivalency
class spell_illidari_council_empyreal_equivalency : public SpellScript
{
    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->SetHealth(GetCaster()->CountPctFromCurHealth(25));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_illidari_council_empyreal_equivalency::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 41341 - Balance of Power
class spell_illidari_council_balance_of_power : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHARED_RULE });
    }

    void Absorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& /*absorbAmount*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(nullptr, SPELL_SHARED_RULE, CastSpellExtraArgs(aurEff).AddSpellBP0(dmgInfo.GetDamage()));
    }

    void Register() override
    {
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_illidari_council_balance_of_power::Absorb, EFFECT_0);
    }
};

// 41480 - Deadly Strike
class spell_illidari_council_deadly_strike : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DEADLY_POISON });
    }

    void OnTrigger(AuraEffect const* aurEff)
    {
        PreventDefaultAction();

        if (Unit* victim = GetTarget()->GetAI()->SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true, true))
            GetTarget()->CastSpell(victim, SPELL_DEADLY_POISON, aurEff);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_illidari_council_deadly_strike::OnTrigger, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 41485 - Deadly Poison
class spell_illidari_council_deadly_poison : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ENVENOM, SPELL_ENVENOM_VISUAL });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
        {
            Unit* target = GetTarget();
            caster->CastSpell(target, SPELL_ENVENOM, true);
            target->CastSpell(nullptr, SPELL_ENVENOM_VISUAL, true);
        }
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_illidari_council_deadly_poison::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 41476 - Vanish
class spell_illidari_council_vanish : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_VANISH_TELEPORT });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_VANISH_TELEPORT, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_illidari_council_vanish::OnRemove, EFFECT_0, SPELL_AURA_MOD_ROOT, AURA_EFFECT_HANDLE_REAL);
    }
};

// 41475 - Reflective Shield
class spell_illidari_council_reflective_shield : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_REFLECTIVE_SHIELD_DAMAGE });
    }

    void OnAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
    {
        Unit* target = GetTarget();
        if (dmgInfo.GetAttacker() == target)
            return;

        target->CastSpell(dmgInfo.GetAttacker(), SPELL_REFLECTIVE_SHIELD_DAMAGE, CastSpellExtraArgs(aurEff).AddSpellBP0(absorbAmount/2));
    }

    void Register() override
    {
        AfterEffectAbsorb += AuraEffectAbsorbFn(spell_illidari_council_reflective_shield::OnAbsorb, EFFECT_0);
    }
};

// 41467 - Judgement
class spell_illidari_council_judgement : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_JUDGEMENT_OF_BLOOD,
            SPELL_JUDGEMENT_OF_COMMAND,
            SPELL_JUDGEMENT_PRIMER
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        uint32 judgementId = caster->HasAura(SPELL_SEAL_OF_BLOOD) ? SPELL_JUDGEMENT_OF_BLOOD : SPELL_JUDGEMENT_OF_COMMAND;
        caster->CastSpell(target, SPELL_JUDGEMENT_PRIMER, true);
        caster->CastSpell(target, judgementId, true);
    }

    void OnFinishCast()
    {
        if (Creature* caster = GetCaster()->ToCreature())
            caster->AI()->Talk(SAY_COUNCIL_SPECIAL);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_illidari_council_judgement::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        AfterCast += SpellCastFn(spell_illidari_council_judgement::OnFinishCast);
    }
};

/* 41469 - Seal of Command
   41459 - Seal of Blood */
class spell_illidari_council_seal : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SEAL_OF_COMMAND,
            SPELL_SEAL_OF_BLOOD
        });
    }

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (target->IsInWorld() && target->IsAlive())
        {
            uint32 spellId = aurEff->GetId() == SPELL_SEAL_OF_COMMAND ? SPELL_SEAL_OF_BLOOD : SPELL_SEAL_OF_COMMAND;
            target->CastSpell(target, spellId, true);
        }
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_illidari_council_seal::OnRemove, EFFECT_2, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 41478 - Dampen Magic
class spell_illidari_dampen_magic : public AuraScript
{
    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* target = GetTarget()->ToCreature())
        {
            AuraRemoveMode mode = GetTargetApplication()->GetRemoveMode();
            if (mode == AURA_REMOVE_BY_ENEMY_SPELL || mode == AURA_REMOVE_BY_EXPIRE)
                target->AI()->DoAction(ACTION_REFRESH_DAMPEN);
        }
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_illidari_dampen_magic::OnRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_illidari_council()
{
    RegisterBlackTempleCreatureAI(boss_illidari_council);
    RegisterBlackTempleCreatureAI(boss_gathios_the_shatterer);
    RegisterBlackTempleCreatureAI(boss_lady_malande);
    RegisterBlackTempleCreatureAI(boss_veras_darkshadow);
    RegisterBlackTempleCreatureAI(boss_high_nethermancer_zerevor);
    RegisterBlackTempleCreatureAI(npc_veras_vanish_effect);
    RegisterSpellScript(spell_illidari_council_empyreal_balance);
    RegisterSpellScript(spell_illidari_council_empyreal_equivalency);
    RegisterSpellScript(spell_illidari_council_balance_of_power);
    RegisterSpellScript(spell_illidari_council_deadly_strike);
    RegisterSpellScript(spell_illidari_council_deadly_poison);
    RegisterSpellScript(spell_illidari_council_vanish);
    RegisterSpellScript(spell_illidari_council_reflective_shield);
    RegisterSpellScript(spell_illidari_council_judgement);
    RegisterSpellScript(spell_illidari_council_seal);
    RegisterSpellScript(spell_illidari_dampen_magic);
}
