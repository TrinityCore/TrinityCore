/*
* Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
#include "Containers.h"
#include "ObjectAccessor.h"
#include "Pet.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellScript.h"
#include "SpellMgr.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "TemporarySummon.h"

enum SpellIds
{
    SPELL_DH_FURY_OF_THE_ILLIDARI_AT                = 202796,
    SPELL_DH_FURY_OF_THE_ILLIDARI_MH                = 201628,
    SPELL_DH_FURY_OF_THE_ILLIDARI_OH                = 201789,
    SPELL_DRUID_ASHAMANE_FRENZY                     = 210722,
    SPELL_DRUID_ASHAMANE_FRENZY_DAMAGE              = 210723,
    SPELL_DRUID_NEW_MOON                            = 202767,
    SPELL_DRUID_NEW_MOON_OVERRIDE                   = 202787,
    SPELL_DRUID_HALF_MOON                           = 202768,
    SPELL_DRUID_HALF_MOON_OVERRIDE                  = 202788,
    SPELL_DRUID_FULL_MOON                           = 202771,
    SPELL_DRUID_FULL_MOON_OVERRIDE                  = 202789,
    SPELL_MAGE_BRAIN_FREEZE_AURA                    = 190446,
    SPELL_MAGE_IMMOLATION                           = 211918,
    SPELL_MAGE_PHOENIX_FLAMES                       = 194466,
    SPELL_MAGE_PHOENIX_FLAMES_TRIGGER               = 224637,
    SPELL_PRIEST_CALL_OF_THE_VOID                   = 193371,
    SPELL_PRIEST_CALL_OF_THE_VOID_SUMMON            = 193470,
    SPELL_PRIEST_MIND_FLAY                          = 193473,
    SPELL_SHAMAN_CARESS_OF_THE_TIDEMOTHER           = 207354,
    SPELL_SHAMAN_HEALING_STREAM_TOTEM               = 5394,
    SPELL_SHAMAN_REINCARNATION                      = 20608,
    SPELL_SHAMAN_SERVANT_OF_THE_QUEEN               = 207357,
    SPELL_SHAMAN_FURY_OF_THE_STORMS                 = 191717,
    SPELL_SHAMAN_SUMMON_LIGHTHING_ELEMENTAL         = 191716,
    SPELL_WARLOCK_DEADWIND_HARVERST                 = 216708,
    SPELL_WARLOCK_TORMENTED_SOULS                   = 216695,
    SPELL_WARLOCK_THALKIELS_CONSUMPTION_DAMAGE      = 211715,
    SPELL_WARLOCK_TEAR_CHAOS_BARRAGE                = 187394,
    SPELL_WARLOCK_TEAR_CHAOS_BOLT                   = 215279,
    SPELL_WARLOCK_TEAR_SHADOW_BOLT                  = 196657,
    SPELL_PALADIN_TYR_DELIVERANCE_HEAL              = 200654,
};

// Ebonbolt - 214634
class spell_arti_mage_ebonbolt : public SpellScript
{
    PrepareSpellScript(spell_arti_mage_ebonbolt);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(caster, SPELL_MAGE_BRAIN_FREEZE_AURA, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_arti_mage_ebonbolt::HandleDummy, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
    }
};

// Reap Souls - 216698
class spell_arti_warl_reap_souls : public SpellScript
{
    PrepareSpellScript(spell_arti_warl_reap_souls);

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(caster, SPELL_WARLOCK_DEADWIND_HARVERST, true);
    }

    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return SPELL_FAILED_DONT_REPORT;

        if (!caster->HasAura(SPELL_WARLOCK_TORMENTED_SOULS))
            return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_arti_warl_reap_souls::CheckCast);
        OnEffectHitTarget += SpellEffectFn(spell_arti_warl_reap_souls::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Deadwind harvest - 216708
class spell_arti_warl_deadwind_harvest : public AuraScript
{
    PrepareAuraScript(spell_arti_warl_deadwind_harvest);

    void CalcAmount(AuraEffect const* /*aurEff*/, int32& /*amount*/, bool& /*canBeRecalculated*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        int32 stackAmount = 0;
        if (Aura* aur = caster->GetAura(SPELL_WARLOCK_TORMENTED_SOULS))
            stackAmount = aur->GetStackAmount();

        int32 duration = GetAura()->GetDuration() * stackAmount;
        GetAura()->SetMaxDuration(duration);
        GetAura()->SetDuration(duration);

        caster->RemoveAurasDueToSpell(SPELL_WARLOCK_TORMENTED_SOULS);
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_arti_warl_deadwind_harvest::CalcAmount, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
    }
};

// Phoenix Flames - 194466
class spell_arti_mage_phoenix_flames : public SpellScript
{
    PrepareSpellScript(spell_arti_mage_phoenix_flames);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_PHOENIX_FLAMES_TRIGGER, SPELL_MAGE_PHOENIX_FLAMES });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        caster->CastSpell(target, SPELL_MAGE_PHOENIX_FLAMES_TRIGGER, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_arti_mage_phoenix_flames::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Phoenix Flames Trigger - 224637
class spell_arti_mage_phoenix_flames_trigger : public SpellScript
{
    PrepareSpellScript(spell_arti_mage_phoenix_flames_trigger);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_PHOENIX_FLAMES_TRIGGER, SPELL_MAGE_PHOENIX_FLAMES });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        Unit* originalTarget = GetExplTargetUnit();
        if (!target || !originalTarget)
            return;

        if (originalTarget == target)
            SetHitDamage(0);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_arti_mage_phoenix_flames_trigger::HandleHit, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Immolation (artifact passive) - 211918
class spell_arti_mage_immolation : public AuraScript
{
    PrepareAuraScript(spell_arti_mage_immolation);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_IMMOLATION, SPELL_MAGE_PHOENIX_FLAMES });
    }

public:

    spell_arti_mage_immolation()
    {
        mod = new SpellModifier(GetAura());
        mod->op = SPELLMOD_CRITICAL_CHANCE;
        mod->type = SPELLMOD_FLAT;
        mod->spellId = SPELL_MAGE_IMMOLATION;
        mod->value = 200;
        mod->mask[3] = 0x20000000;
    }

private:

    SpellModifier* mod = nullptr;

    void HandleApply(AuraEffect const* /*aurEffect*/, AuraEffectHandleModes /*mode*/)
    {
        Player* player = GetCaster()->ToPlayer();
        if (!player)
            return;

        player->AddSpellMod(mod, true);
    }

    void HandleRemove(AuraEffect const* /*aurEffect*/, AuraEffectHandleModes /*mode*/)
    {
        Player* player = GetCaster()->ToPlayer();
        if (!player)
            return;

        player->AddSpellMod(mod, false);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_arti_mage_immolation::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_arti_mage_immolation::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// Fury of the Illidari - 201467
// AreaTriggerID - 5758
struct at_dh_fury_of_the_illidari : AreaTriggerAI
{
    int32 timeInterval;

    at_dh_fury_of_the_illidari(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)
    {
        // How often should the action be executed
        timeInterval = 420; // Blaze it (blizzard wtf, 7 times under 3 seconds)
    }

    void OnUpdate(uint32 p_Time) override
    {
        Unit* caster = at->GetCaster();
        if (!caster || !caster->IsPlayer())
            return;

        // Check if we can handle actions
        timeInterval += p_Time;
        if (timeInterval < 420)
            return;

        caster->CastSpell(at->GetPosition(), SPELL_DH_FURY_OF_THE_ILLIDARI_MH, true);
        caster->CastSpell(at->GetPosition(), SPELL_DH_FURY_OF_THE_ILLIDARI_OH, true);

        timeInterval -= 420;
    }
};

//207357 - Servant of the queen
class spell_arti_sha_servant_of_the_queen : public AuraScript
{
    PrepareAuraScript(spell_arti_sha_servant_of_the_queen);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (!eventInfo.GetSpellInfo())
            return false;

        if(eventInfo.GetSpellInfo()->Id == SPELL_SHAMAN_REINCARNATION)
            return true;
        else
            return false;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_arti_sha_servant_of_the_queen::CheckProc);
    }
};

//207354 - Caress of the tidemother
class spell_arti_sha_caress_of_the_tidemother : public AuraScript
{
    PrepareAuraScript(spell_arti_sha_caress_of_the_tidemother);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if(!eventInfo.GetSpellInfo())
            return false;

        if(eventInfo.GetSpellInfo()->Id == SPELL_SHAMAN_HEALING_STREAM_TOTEM)
            return true;
        else
            return false;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_arti_sha_caress_of_the_tidemother::CheckProc);
    }
};

// Dimensional Rift - 196586
class spell_arti_warl_dimensional_rift : public SpellScript
{
    PrepareSpellScript(spell_arti_warl_dimensional_rift);

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

                                                //green //green //purple
        std::vector<uint32> spellVisualIds = { 219117, 219117, 219107 };
                                        // Chaos Tear  //Chaos Portal  //Shadowy Tear
        std::vector<uint32> summonIds = { 108493,        108493,          99887 };
        // Durations must be longer, because if the npc gets destroyed before the last projectile hits
        // it won't deal any damage.
        std::vector<uint32> durations = { 7000, 4500, 16000 };
        uint32 id = std::rand() % 3;
        Position pos = caster->GetPosition();
        caster->MovePosition(pos, (float)(std::rand() % 5) + 4.f, (float)rand_norm() * static_cast<float>(2 * M_PI));
        if (TempSummon* rift = caster->SummonCreature(summonIds[id], pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, durations[id]))
        {
            rift->CastSpell(rift, spellVisualIds[id], true);
            rift->SetOwnerGUID(caster->GetGUID());
            rift->SetTarget(target->GetGUID());
            // We use same ID and script for Chaos Portal and Chaos Tear as there are no more NPCs for this spell
            rift->SetArmor(id, 0);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_arti_warl_dimensional_rift::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// Thal'kiel's Consumption - 211714
class spell_arti_warl_thalkiels_consumption : public SpellScript
{
    PrepareSpellScript(spell_arti_warl_thalkiels_consumption);

    int32 damage = 0;

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!target || !caster)
            return;

        caster->CastCustomSpell(SPELL_WARLOCK_THALKIELS_CONSUMPTION_DAMAGE, SPELLVALUE_BASE_POINT0, damage, target, TRIGGERED_FULL_MASK);
    }

    void SaveDamage(std::list<WorldObject*>& targets)
    {
        targets.remove_if([this](WorldObject* target)
        {
            if (!target->IsCreature())
                return true;
            if (!target->ToCreature()->IsPet() || target->ToCreature()->ToPet()->GetOwner() != GetCaster())
                return true;
            // Remove Gateways
            if (target->ToCreature()->GetCreatureType() != CREATURE_TYPE_DEMON)
                return true;

            return false;
        });

        int32 basePoints = GetSpellInfo()->GetEffect(EFFECT_1)->BasePoints;
        for (WorldObject* pet : targets)
            damage += pet->ToUnit()->CountPctFromMaxHealth(basePoints);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_arti_warl_thalkiels_consumption::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_arti_warl_thalkiels_consumption::SaveDamage, EFFECT_1, TARGET_UNIT_CASTER_PET);
    }
};

// Chaos Tear - 108493
struct npc_warl_chaos_tear : public ScriptedAI
{
    npc_warl_chaos_tear(Creature* p_Creature) : ScriptedAI(p_Creature) { }

    int32 timer = 0;
    int32 counter = 0;

    void UpdateAI(uint32 diff) override

    {
        timer += diff;
        switch (me->GetArmor())
        {
        case 0:
            if (counter >= 22)
                return;
            if (timer >= 250)
            {
                timer -= 250;
                ObjectGuid targetGuid = me->GetTarget();
                ObjectGuid casterGuid = me->GetOwnerGUID();
                if (targetGuid.IsEmpty() || casterGuid.IsEmpty())
                    return;
                Unit* caster = ObjectAccessor::GetUnit(*me, casterGuid);
                Unit* target = ObjectAccessor::GetUnit(*me, targetGuid);
                if (!caster || !target)
                    return;

                me->CastSpell(target, SPELL_WARLOCK_TEAR_CHAOS_BARRAGE, true, nullptr, nullptr, caster->GetGUID());
                counter++;
            }
            break;
        case 1:
            if (timer >= 1500)
            {
                timer -= 9000;
                ObjectGuid targetGuid = me->GetTarget();
                ObjectGuid casterGuid = me->GetOwnerGUID();
                if (targetGuid.IsEmpty() || casterGuid.IsEmpty())
                    return;
                Unit* caster = ObjectAccessor::GetUnit(*me, casterGuid);
                Unit* target = ObjectAccessor::GetUnit(*me, targetGuid);
                if (!caster || !target)
                    return;

                me->CastSpell(target, SPELL_WARLOCK_TEAR_CHAOS_BOLT, true, nullptr, nullptr, caster->GetGUID());
            }
            break;
        default:
            break;
        }
    }
};

// Shadowy Tear - 99887
struct npc_warl_shadowy_tear : public ScriptedAI
{
    npc_warl_shadowy_tear(Creature* p_Creature) : ScriptedAI(p_Creature) { }

    int32 timer = 0;
    int32 counter = 0;

    void UpdateAI(uint32 diff) override
    {
        if (counter >= 7)
            return;

        timer += diff;
        if (timer >= 2000)
        {
            timer -= 2000;
            ObjectGuid targetGuid = me->GetTarget();
            ObjectGuid casterGuid = me->GetOwnerGUID();
            if (targetGuid.IsEmpty() || casterGuid.IsEmpty())
                return;
            Unit* caster = ObjectAccessor::GetUnit(*me, casterGuid);
            Unit* target = ObjectAccessor::GetUnit(*me, targetGuid);
            if (!caster || !target)
                return;

            me->CastSpell(target, SPELL_WARLOCK_TEAR_SHADOW_BOLT, true, nullptr, nullptr, caster->GetGUID());
            counter++;
        }
    }
};

class spell_arti_dru_new_moon : public SpellScript
{
    PrepareSpellScript(spell_arti_dru_new_moon);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_NEW_MOON, SPELL_DRUID_NEW_MOON_OVERRIDE });
    }

    void RemoveOverride()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->RemoveAurasDueToSpell(SPELL_DRUID_FULL_MOON_OVERRIDE);
        caster->AddAura(SPELL_DRUID_NEW_MOON_OVERRIDE, caster);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_arti_dru_new_moon::RemoveOverride);
    }
};

// Half Moon - 202768
class spell_arti_dru_half_moon : public SpellScript
{
    PrepareSpellScript(spell_arti_dru_half_moon);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_HALF_MOON, SPELL_DRUID_HALF_MOON_OVERRIDE });
    }

    void RemoveOverride()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->RemoveAurasDueToSpell(SPELL_DRUID_NEW_MOON_OVERRIDE);
        caster->AddAura(SPELL_DRUID_HALF_MOON_OVERRIDE, caster);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_arti_dru_half_moon::RemoveOverride);
    }
};

//Full Moon - 202771
class spell_arti_dru_full_moon : public SpellScript
{
    PrepareSpellScript(spell_arti_dru_full_moon);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_FULL_MOON, SPELL_DRUID_FULL_MOON_OVERRIDE });
    }

    void RemoveOverride()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->RemoveAurasDueToSpell(SPELL_DRUID_HALF_MOON_OVERRIDE);
        //caster->AddAura(SPELL_DRUID_FULL_MOON_OVERRIDE, caster);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_arti_dru_full_moon::RemoveOverride);
    }
};

#define ASHAMANE_FRENZY_TARGET "ashamane_frenzy_target"

// 210722 - Ashamane's Frenzy
class spell_arti_dru_ashamane_frenzy : public SpellScript
{
    PrepareSpellScript(spell_arti_dru_ashamane_frenzy);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            GetCaster()->Variables.Set(ASHAMANE_FRENZY_TARGET, target->GetGUID());
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_arti_dru_ashamane_frenzy::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 210722 - Ashamane's Frenzy
class aura_arti_dru_ashamane_frenzy : public AuraScript
{
    PrepareAuraScript(aura_arti_dru_ashamane_frenzy);

    void HandleDummyTick(AuraEffect const* aurEff)
    {
        if (Unit* caster = GetCaster())
            if (Unit* target = ObjectAccessor::GetUnit(*caster, caster->Variables.GetValue<ObjectGuid>(ASHAMANE_FRENZY_TARGET)))
                caster->CastSpell(target, SPELL_DRUID_ASHAMANE_FRENZY_DAMAGE, true, NULL, aurEff);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            caster->Variables.Remove(ASHAMANE_FRENZY_TARGET);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(aura_arti_dru_ashamane_frenzy::HandleDummyTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        AfterEffectRemove += AuraEffectRemoveFn(aura_arti_dru_ashamane_frenzy::OnRemove, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 193371 - Call to the Void
class spell_arti_pri_call_of_the_void : public AuraScript
{
    PrepareAuraScript(spell_arti_pri_call_of_the_void);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_MIND_FLAY, SPELL_PRIEST_CALL_OF_THE_VOID, SPELL_PRIEST_CALL_OF_THE_VOID_SUMMON });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetSpellInfo() && eventInfo.GetSpellInfo()->Id == SPELL_PRIEST_MIND_FLAY;
    }

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(eventInfo.GetProcTarget(), SPELL_PRIEST_CALL_OF_THE_VOID_SUMMON, true, nullptr, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_arti_pri_call_of_the_void::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_arti_pri_call_of_the_void::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 98167 - Void Tendril
struct npc_arti_priest_void_tendril : public Scripted_NoMovementAI
{
    npc_arti_priest_void_tendril(Creature* p_Creature) : Scripted_NoMovementAI(p_Creature) { }

    void IsSummonedBy(Unit* summoner) override
    {
        auto channelTargets = summoner->GetChannelObjects();

        if (channelTargets.size() != 1)
        {
            me->DisappearAndDie();
            return;
        }

        ObjectGuid targetGuid = *(channelTargets.begin());
        if (Unit* target = ObjectAccessor::GetUnit(*me, targetGuid))
        {
            AttackStart(target);
            me->GetScheduler().Schedule(250ms, [this, targetGuid](TaskContext context)
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (Unit* owner = me->GetOwner())
                    if (Unit* target = ObjectAccessor::GetUnit(*me, targetGuid))
                        me->CastCustomSpell(SPELL_PRIEST_MIND_FLAY, SPELLVALUE_BASE_POINT0, owner->GetTotalSpellPowerValue(SPELL_SCHOOL_MASK_SHADOW, false), target);

                context.Repeat();
            });
        }
    }
};

// 200653  - Tyr's Deliverance
class spell_arti_pal_tyr_deliverance : public SpellScript
{
    PrepareSpellScript(spell_arti_pal_tyr_deliverance);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_TYR_DELIVERANCE_HEAL });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            GetCaster()->CastSpell(target, SPELL_PALADIN_TYR_DELIVERANCE_HEAL, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_arti_pal_tyr_deliverance::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 205495 - Stormkeeper
class aura_artifact_shaman_stormkeeper : public AuraScript
{
    PrepareAuraScript(aura_artifact_shaman_stormkeeper);

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetCaster()->HasAura(SPELL_SHAMAN_FURY_OF_THE_STORMS))
            GetCaster()->CastSpell(GetCaster(), SPELL_SHAMAN_SUMMON_LIGHTHING_ELEMENTAL, true);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(aura_artifact_shaman_stormkeeper::AfterApply, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_artifact_spell_scripts()
{
    RegisterSpellScript(spell_arti_dru_new_moon);
    RegisterSpellScript(spell_arti_dru_half_moon);
    RegisterSpellScript(spell_arti_dru_full_moon);
    RegisterSpellAndAuraScriptPair(spell_arti_dru_ashamane_frenzy, aura_arti_dru_ashamane_frenzy);

    RegisterAuraScript(spell_arti_mage_immolation);
    RegisterSpellScript(spell_arti_mage_phoenix_flames);
    RegisterSpellScript(spell_arti_mage_phoenix_flames_trigger);

    RegisterAuraScript(spell_arti_sha_servant_of_the_queen);
    RegisterAuraScript(spell_arti_sha_caress_of_the_tidemother);

    RegisterAuraScript(spell_arti_warl_deadwind_harvest);
    RegisterSpellScript(spell_arti_warl_reap_souls);
    RegisterSpellScript(spell_arti_warl_dimensional_rift);
    RegisterCreatureAI(npc_warl_chaos_tear);
    RegisterCreatureAI(npc_warl_shadowy_tear);
    RegisterSpellScript(spell_arti_warl_thalkiels_consumption);

    /// AreaTrigger scripts
    RegisterAreaTriggerAI(at_dh_fury_of_the_illidari);

    RegisterSpellScript(spell_arti_mage_ebonbolt);

    RegisterAuraScript(spell_arti_pri_call_of_the_void);
    RegisterCreatureAI(npc_arti_priest_void_tendril);

    RegisterSpellScript(spell_arti_pal_tyr_deliverance);
    
    RegisterAuraScript(aura_artifact_shaman_stormkeeper);
}
