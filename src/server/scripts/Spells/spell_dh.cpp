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
 * Scripts for spells with SPELLFAMILY_DEMONHUNTER and SPELLFAMILY_GENERIC spells used by demon hunter players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_dh_".
 */

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "Unit.h"

enum DemonHunterSpells
{
    AREATRIGGER_DH_SHATTERED_SOULS_HAVOC           = 8352,
    AREATRIGGER_DH_SHATTERED_SOULS_HAVOC_DEMON     = 11231,
    AREATRIGGER_DH_SHATTERED_SOULS_VENGEANCE       = 11266,
    AREATRIGGER_DH_SHATTERED_SOULS_VENGEANCE_DEMON = 10693,
    AREATRIGGER_DH_SOUL_FRAGMENT_HAVOC             = 12929,
    AREATRIGGER_DH_SOUL_FRAGMENT_VENGEANCE         = 10665,

    SPELL_DH_ABYSSAL_STRIKE                        = 207550,
    SPELL_DH_ANNIHILATION                          = 201427,
    SPELL_DH_ANNIHILATION_MH                       = 227518,
    SPELL_DH_ANNIHILATION_OH                       = 201428,
    SPELL_DH_AWAKEN_THE_DEMON_WITHIN_CD            = 207128,
    SPELL_DH_BLUR                                  = 212800,
    SPELL_DH_BLUR_TRIGGER                          = 198589,
    SPELL_DH_BURNING_ALIVE                         = 207739,
    SPELL_DH_BURNING_ALIVE_TARGET_SELECTOR         = 207760,
    SPELL_DH_CHAOS_NOVA                            = 179057,
    SPELL_DH_CHAOS_STRIKE                          = 162794,
    SPELL_DH_CHAOS_STRIKE_ENERGIZE                 = 193840,
    SPELL_DH_CHAOS_STRIKE_MH                       = 222031,
    SPELL_DH_CHAOS_STRIKE_OH                       = 199547,
    SPELL_DH_CONSUME_SOUL_HAVOC                    = 228542,
    SPELL_DH_CONSUME_SOUL_HAVOC_DEMON              = 228556,
    SPELL_DH_CONSUME_SOUL_HAVOC_SHATTERED          = 228540,
    SPELL_DH_CONSUME_SOUL_HEAL                     = 203794,
    SPELL_DH_CONSUME_SOUL_VENGEANCE                = 208014,
    SPELL_DH_CONSUME_SOUL_VENGEANCE_DEMON          = 210050,
    SPELL_DH_CONSUME_SOUL_VENGEANCE_SHATTERED      = 210047,
    SPELL_DH_DARKNESS_ABSORB                       = 209426,
    SPELL_DH_DEMON_BLADES_DMG                      = 203796,
    SPELL_DH_DEMON_SPIKES                          = 203819,
    SPELL_DH_DEMON_SPIKES_TRIGGER                  = 203720,
    SPELL_DH_DEMONIC                               = 213410,
    SPELL_DH_DEMONIC_ORIGINS                       = 235893,
    SPELL_DH_DEMONIC_ORIGINS_BUFF                  = 235894,
    SPELL_DH_DEMONIC_TRAMPLE_DMG                   = 208645,
    SPELL_DH_DEMONIC_TRAMPLE_STUN                  = 213491,
    SPELL_DH_DEMONS_BITE                           = 162243,
    SPELL_DH_EYE_BEAM                              = 198013,
    SPELL_DH_EYE_BEAM_DMG                          = 198030,
    SPELL_DH_EYE_OF_LEOTHERAS_DMG                  = 206650,
    SPELL_DH_FEAST_OF_SOULS                        = 207697,
    SPELL_DH_FEAST_OF_SOULS_PERIODIC_HEAL          = 207693,
    SPELL_DH_FEED_THE_DEMON                        = 218612,
    SPELL_DH_FEL_BARRAGE                           = 211053,
    SPELL_DH_FEL_BARRAGE_DMG                       = 211052,
    SPELL_DH_FEL_BARRAGE_PROC                      = 222703,
    SPELL_DH_FEL_DEVASTATION                       = 212084,
    SPELL_DH_FEL_DEVASTATION_DMG                   = 212105,
    SPELL_DH_FEL_DEVASTATION_HEAL                  = 212106,
    SPELL_DH_FEL_RUSH                              = 195072,
    SPELL_DH_FEL_RUSH_DMG                          = 192611,
    SPELL_DH_FEL_RUSH_GROUND                       = 197922,
    SPELL_DH_FEL_RUSH_WATER_AIR                    = 197923,
    SPELL_DH_FELBLADE                              = 232893,
    SPELL_DH_FELBLADE_CHARGE                       = 213241,
    SPELL_DH_FELBLADE_DMG                          = 213243,
    SPELL_DH_FELBLADE_PROC                         = 203557,
    SPELL_DH_FELBLADE_PROC_VISUAL                  = 204497,
    SPELL_DH_FELBLADE_PROC1                        = 236167,
    SPELL_DH_FIERY_BRAND                           = 204021,
    SPELL_DH_FIERY_BRAND_DMG_REDUCTION_DEBUFF      = 207744,
    SPELL_DH_FIERY_BRAND_DOT                       = 207771,
    SPELL_DH_FIRST_BLOOD                           = 206416,
    SPELL_DH_FLAME_CRASH                           = 227322,
    SPELL_DH_FRAILTY                               = 224509,
    SPELL_DH_GLIDE                                 = 131347,
    SPELL_DH_GLIDE_DURATION                        = 197154,
    SPELL_DH_GLIDE_KNOCKBACK                       = 196353,
    SPELL_DH_HAVOC_MASTERY                         = 185164,
    SPELL_DH_ILLIDANS_GRASP                        = 205630,
    SPELL_DH_ILLIDANS_GRASP_DAMAGE                 = 208618,
    SPELL_DH_ILLIDANS_GRASP_JUMP_DEST              = 208175,
    SPELL_DH_INFERNAL_STRIKE_CAST                  = 189110,
    SPELL_DH_INFERNAL_STRIKE_IMPACT_DAMAGE         = 189112,
    SPELL_DH_INFERNAL_STRIKE_JUMP                  = 189111,
    SPELL_DH_JAGGED_SPIKES                         = 205627,
    SPELL_DH_JAGGED_SPIKES_DMG                     = 208790,
    SPELL_DH_JAGGED_SPIKES_PROC                    = 208796,
    SPELL_DH_MANA_RIFT_DMG_POWER_BURN              = 235904,
    SPELL_DH_METAMORPHOSIS                         = 191428,
    SPELL_DH_METAMORPHOSIS_DUMMY                   = 191427,
    SPELL_DH_METAMORPHOSIS_IMPACT_DAMAGE           = 200166,
    SPELL_DH_METAMORPHOSIS_RESET                   = 320645,
    SPELL_DH_METAMORPHOSIS_TRANSFORM               = 162264,
    SPELL_DH_METAMORPHOSIS_VENGEANCE_TRANSFORM     = 187827,
    SPELL_DH_MOMENTUM                              = 208628,
    SPELL_DH_NEMESIS_ABERRATIONS                   = 208607,
    SPELL_DH_NEMESIS_BEASTS                        = 208608,
    SPELL_DH_NEMESIS_CRITTERS                      = 208609,
    SPELL_DH_NEMESIS_DEMONS                        = 208608,
    SPELL_DH_NEMESIS_DRAGONKIN                     = 208610,
    SPELL_DH_NEMESIS_ELEMENTALS                    = 208611,
    SPELL_DH_NEMESIS_GIANTS                        = 208612,
    SPELL_DH_NEMESIS_HUMANOIDS                     = 208605,
    SPELL_DH_NEMESIS_MECHANICALS                   = 208613,
    SPELL_DH_NEMESIS_UNDEAD                        = 208614,
    SPELL_DH_RAIN_FROM_ABOVE                       = 206803,
    SPELL_DH_RAIN_OF_CHAOS                         = 205628,
    SPELL_DH_RAIN_OF_CHAOS_IMPACT                  = 232538,
    SPELL_DH_RAZOR_SPIKES                          = 210003,
    SPELL_DH_SEVER                                 = 235964,
    SPELL_DH_SHATTER_SOUL                          = 209980,
    SPELL_DH_SHATTER_SOUL_1                        = 209981,
    SPELL_DH_SHATTER_SOUL_2                        = 210038,
    SPELL_DH_SHATTERED_SOUL                        = 226258,
    SPELL_DH_SHATTERED_SOUL_LESSER_SOUL_FRAGMENT_1 = 228533,
    SPELL_DH_SHATTERED_SOUL_LESSER_SOUL_FRAGMENT_2 = 237867,
    SPELL_DH_SHEAR                                 = 203782,
    SPELL_DH_SIGIL_OF_CHAINS_AREA_SELECTOR         = 204834,
    SPELL_DH_SIGIL_OF_CHAINS_GRIP                  = 208674,
    SPELL_DH_SIGIL_OF_CHAINS_JUMP                  = 208674,
    SPELL_DH_SIGIL_OF_CHAINS_SLOW                  = 204843,
    SPELL_DH_SIGIL_OF_CHAINS_SNARE                 = 204843,
    SPELL_DH_SIGIL_OF_CHAINS_TARGET_SELECT         = 204834,
    SPELL_DH_SIGIL_OF_CHAINS_VISUAL                = 208673,
    SPELL_DH_SIGIL_OF_FLAME_AOE                    = 204598,
    SPELL_DH_SIGIL_OF_FLAME_DAMAGE                 = 204598,
    SPELL_DH_SIGIL_OF_FLAME_FLAME_CRASH            = 228973,
    SPELL_DH_SIGIL_OF_MISERY                       = 207685,
    SPELL_DH_SIGIL_OF_MISERY_AOE                   = 207685,
    SPELL_DH_SIGIL_OF_SILENCE                      = 204490,
    SPELL_DH_SIGIL_OF_SILENCE_AOE                  = 204490,
    SPELL_DH_SOUL_BARRIER                          = 227225,
    SPELL_DH_SOUL_CLEAVE                           = 228477,
    SPELL_DH_SOUL_CLEAVE_DMG                       = 228478,
    SPELL_DH_SOUL_FRAGMENT_COUNTER                 = 203981,
    SPELL_DH_SOUL_RENDING                          = 204909,
    SPELL_DH_SPIRIT_BOMB_DAMAGE                    = 218677,
    SPELL_DH_SPIRIT_BOMB_HEAL                      = 227255,
    SPELL_DH_SPIRIT_BOMB_VISUAL                    = 218678,
    SPELL_DH_THROW_GLAIVE                          = 185123,
    SPELL_DH_UNCONTAINED_FEL                       = 209261,
    SPELL_DH_VENGEFUL_RETREAT                      = 198813,
    SPELL_DH_VENGEFUL_RETREAT_TRIGGER              = 198793,
};

// 197125 - Chaos Strike
class spell_dh_chaos_strike : public AuraScript
{
    PrepareAuraScript(spell_dh_chaos_strike);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_CHAOS_STRIKE_ENERGIZE });
    }

    void HandleEffectProc(AuraEffect* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
        args.AddSpellMod(SPELLVALUE_BASE_POINT0, aurEff->GetAmount());
        args.SetTriggeringAura(aurEff);
        GetTarget()->CastSpell(GetTarget(), SPELL_DH_CHAOS_STRIKE_ENERGIZE, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dh_chaos_strike::HandleEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 206416 - First Blood
class spell_dh_first_blood : public AuraScript
{
    PrepareAuraScript(spell_dh_first_blood);

public:
    ObjectGuid const& GetFirstTarget() const { return _firstTargetGUID; }
    void SetFirstTarget(ObjectGuid const& targetGuid) { _firstTargetGUID = targetGuid; }

private:
    void Register() override
    {
    }

private:
    ObjectGuid _firstTargetGUID;
};

// 188499 - Blade Dance
// 210152 - Death Sweep
class spell_dh_blade_dance : public SpellScript
{
    PrepareSpellScript(spell_dh_blade_dance);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_FIRST_BLOOD });
    }

    void DecideFirstTarget(std::list<WorldObject*>& targetList)
    {
        if (targetList.empty())
            return;

        Aura* aura = GetCaster()->GetAura(SPELL_DH_FIRST_BLOOD);
        if (!aura)
            return;

        ObjectGuid firstTargetGUID = ObjectGuid::Empty;
        ObjectGuid selectedTarget = GetCaster()->GetTarget();

        // Prefer the selected target if he is one of the enemies
        if (targetList.size() > 1 && !selectedTarget.IsEmpty())
        {
            auto it = std::find_if(targetList.begin(), targetList.end(), [selectedTarget](WorldObject* object)
            {
                return object->GetGUID() == selectedTarget;
            });
            if (it != targetList.end())
                firstTargetGUID = (*it)->GetGUID();
        }

        if (firstTargetGUID.IsEmpty())
            firstTargetGUID = targetList.front()->GetGUID();

        if (spell_dh_first_blood* script = aura->GetScript<spell_dh_first_blood>())
            script->SetFirstTarget(firstTargetGUID);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dh_blade_dance::DecideFirstTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 199552 - Blade Dance
// 200685 - Blade Dance
// 210153 - Death Sweep
// 210155 - Death Sweep
class spell_dh_blade_dance_damage : public SpellScript
{
    PrepareSpellScript(spell_dh_blade_dance_damage);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_FIRST_BLOOD });
    }

    void HandleHitTarget()
    {
        int32 damage = GetHitDamage();

        if (AuraEffect* aurEff = GetCaster()->GetAuraEffect(SPELL_DH_FIRST_BLOOD, EFFECT_0))
            if (spell_dh_first_blood* script = aurEff->GetBase()->GetScript<spell_dh_first_blood>())
                if (GetHitUnit()->GetGUID() == script->GetFirstTarget())
                    AddPct(damage, aurEff->GetAmount());

        SetHitDamage(damage);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_dh_blade_dance_damage::HandleHitTarget);
    }
};

// 204596 - Sigil of Flame
// 207684 - Sigil of Misery
// 202137 - Sigil of Silence
template<uint32 TriggerSpellId>
class areatrigger_dh_generic_sigil : public AreaTriggerEntityScript
{
public:
    areatrigger_dh_generic_sigil(char const* script) : AreaTriggerEntityScript(script) { }

    template<uint32 Trigger>
    struct areatrigger_dh_generic_sigilAI : AreaTriggerAI
    {
        areatrigger_dh_generic_sigilAI(AreaTrigger* at) : AreaTriggerAI(at) { }

        void OnRemove() override
        {
            if (Unit* caster = at->GetCaster())
                caster->CastSpell(at->GetPosition(), Trigger);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new areatrigger_dh_generic_sigilAI<TriggerSpellId>(at);
    }
};

// 208673 - Sigil of Chains
class spell_dh_sigil_of_chains : public SpellScript
{
    PrepareSpellScript(spell_dh_sigil_of_chains);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_SIGIL_OF_CHAINS_SLOW, SPELL_DH_SIGIL_OF_CHAINS_GRIP });
    }

    void HandleEffectHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (WorldLocation const* loc = GetExplTargetDest())
        {
            GetCaster()->CastSpell(GetHitUnit(), SPELL_DH_SIGIL_OF_CHAINS_SLOW, true);
            GetHitUnit()->CastSpell(loc->GetPosition(), SPELL_DH_SIGIL_OF_CHAINS_GRIP, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dh_sigil_of_chains::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 202138 - Sigil of Chains
struct areatrigger_dh_sigil_of_chains : AreaTriggerAI
{
    areatrigger_dh_sigil_of_chains(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnRemove() override
    {
        if (Unit* caster = at->GetCaster())
        {
            caster->CastSpell(at->GetPosition(), SPELL_DH_SIGIL_OF_CHAINS_VISUAL);
            caster->CastSpell(at->GetPosition(), SPELL_DH_SIGIL_OF_CHAINS_TARGET_SELECT);
        }
    }
};

// 131347 - Glide
class spell_dh_glide : public SpellScript
{
    PrepareSpellScript(spell_dh_glide);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_GLIDE_KNOCKBACK, SPELL_DH_GLIDE_DURATION, SPELL_DH_VENGEFUL_RETREAT_TRIGGER, SPELL_DH_FEL_RUSH });
    }

    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();
        if (caster->IsMounted() || caster->GetVehicleBase())
            return SPELL_FAILED_DONT_REPORT;

        if (!caster->IsFalling())
            return SPELL_FAILED_NOT_ON_GROUND;

        return SPELL_CAST_OK;
    }

    void HandleCast()
    {
        Player* caster = GetCaster()->ToPlayer();
        if (!caster)
            return;

        caster->CastSpell(caster, SPELL_DH_GLIDE_KNOCKBACK, true);
        caster->CastSpell(caster, SPELL_DH_GLIDE_DURATION, true);

        caster->GetSpellHistory()->StartCooldown(sSpellMgr->AssertSpellInfo(SPELL_DH_VENGEFUL_RETREAT_TRIGGER, GetCastDifficulty()), 0, nullptr, false, 250ms);
        caster->GetSpellHistory()->StartCooldown(sSpellMgr->AssertSpellInfo(SPELL_DH_FEL_RUSH, GetCastDifficulty()), 0, nullptr, false, 250ms);
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_dh_glide::CheckCast);
        BeforeCast += SpellCastFn(spell_dh_glide::HandleCast);
    }
};

// 131347 - Glide
class spell_dh_glide_AuraScript : public AuraScript
{
    PrepareAuraScript(spell_dh_glide_AuraScript);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_GLIDE_DURATION });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAura(SPELL_DH_GLIDE_DURATION);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_dh_glide_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_FEATHER_FALL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 197154 - Glide
class spell_dh_glide_timer : public AuraScript
{
    PrepareAuraScript(spell_dh_glide_timer);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_GLIDE });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAura(SPELL_DH_GLIDE);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_dh_glide_timer::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_demon_hunter_spell_scripts()
{
    RegisterSpellScript(spell_dh_chaos_strike);

    new areatrigger_dh_generic_sigil<SPELL_DH_SIGIL_OF_SILENCE_AOE>("areatrigger_dh_sigil_of_silence");
    new areatrigger_dh_generic_sigil<SPELL_DH_SIGIL_OF_MISERY_AOE>("areatrigger_dh_sigil_of_misery");
    new areatrigger_dh_generic_sigil<SPELL_DH_SIGIL_OF_FLAME_AOE>("areatrigger_dh_sigil_of_flame");
    RegisterAreaTriggerAI(areatrigger_dh_sigil_of_chains);
    RegisterSpellScript(spell_dh_sigil_of_chains);

    // Havoc

    /* Spells & Auras */

    /* Auras */

    RegisterSpellScript(spell_dh_first_blood);

    /* AreaTrigger */

    /* Spells */

    RegisterSpellScript(spell_dh_blade_dance);
    RegisterSpellScript(spell_dh_blade_dance_damage);

    // Vengeance & Havoc

    RegisterSpellAndAuraScriptPair(spell_dh_glide, spell_dh_glide_AuraScript);
    RegisterSpellScript(spell_dh_glide_timer);

}
