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
 * Scripts for spells with SPELLFAMILY_PRIEST and SPELLFAMILY_GENERIC spells used by priest players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_pri_".
 */

#include "ScriptMgr.h"
#include "AreaTriggerAI.h"
#include "GridNotifiers.h"
#include "ObjectAccessor.h"
#include "Log.h"
#include "Player.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum PriestSpells
{
    SPELL_PRIEST_ANGELIC_FEATHER_AREATRIGGER        = 158624,
    SPELL_PRIEST_ANGELIC_FEATHER_AURA               = 121557,
    SPELL_PRIEST_ARMOR_OF_FAITH                     = 28810,
    SPELL_PRIEST_ATONEMENT                          = 81749,
    SPELL_PRIEST_ATONEMENT_HEAL                     = 81751,
    SPELL_PRIEST_ATONEMENT_TRIGGERED                = 194384,
    SPELL_PRIEST_ATONEMENT_TRIGGERED_TRINITY        = 214206,
    SPELL_PRIEST_BLESSED_HEALING                    = 70772,
    SPELL_PRIEST_BODY_AND_SOUL                      = 64129,
    SPELL_PRIEST_BODY_AND_SOUL_SPEED                = 65081,
    SPELL_PRIEST_DIVINE_BLESSING                    = 40440,
    SPELL_PRIEST_DIVINE_WRATH                       = 40441,
    SPELL_PRIEST_FLASH_HEAL                         = 2061,
    SPELL_PRIEST_GUARDIAN_SPIRIT_HEAL               = 48153,
    SPELL_PRIEST_HEAL                               = 2060,
    SPELL_PRIEST_HOLY_WORD_CHASTISE                 = 88625,
    SPELL_PRIEST_HOLY_WORD_SANCTIFY                 = 34861,
    SPELL_PRIEST_HOLY_WORD_SERENITY                 = 2050,
    SPELL_PRIEST_ITEM_EFFICIENCY                    = 37595,
    SPELL_PRIEST_LEAP_OF_FAITH_EFFECT               = 92832,
    SPELL_PRIEST_LEVITATE_EFFECT                    = 111759,
    SPELL_PRIEST_ORACULAR_HEAL                      = 26170,
    SPELL_PRIEST_PENANCE_R1                         = 47540,
    SPELL_PRIEST_PENANCE_R1_DAMAGE                  = 47758,
    SPELL_PRIEST_PENANCE_R1_HEAL                    = 47757,
    SPELL_PRIEST_PRAYER_OF_HEALING                  = 596,
    SPELL_PRIEST_RENEW                              = 139,
    SPELL_PRIEST_RENEWED_HOPE                       = 197469,
    SPELL_PRIEST_RENEWED_HOPE_EFFECT                = 197470,
    SPELL_PRIEST_SHIELD_DISCIPLINE_ENERGIZE         = 47755,
    SPELL_PRIEST_SHIELD_DISCIPLINE_PASSIVE          = 197045,
    SPELL_PRIEST_SMITE                              = 585,
    SPELL_PRIEST_SPIRIT_OF_REDEMPTION               = 27827,
    SPELL_PRIEST_STRENGTH_OF_SOUL                   = 197535,
    SPELL_PRIEST_STRENGTH_OF_SOUL_EFFECT            = 197548,
    SPELL_PRIEST_THE_PENITENT_AURA                  = 200347,
    SPELL_PRIEST_TRINITY                            = 214205,
    SPELL_PRIEST_VAMPIRIC_EMBRACE_HEAL              = 15290,
    SPELL_PRIEST_VAMPIRIC_TOUCH_DISPEL              = 64085,
    SPELL_PRIEST_VOID_SHIELD                        = 199144,
    SPELL_PRIEST_VOID_SHIELD_EFFECT                 = 199145,
    SPELL_PRIEST_PRAYER_OF_MENDING_AURA             = 41635,
    SPELL_PRIEST_PRAYER_OF_MENDING_HEAL             = 33110,
    SPELL_PRIEST_PRAYER_OF_MENDING_JUMP             = 155793,
};

enum MiscSpells
{
    SPELL_GEN_REPLENISHMENT                         = 57669
};

class PowerCheck
{
    public:
        explicit PowerCheck(Powers const power) : _power(power) { }

        bool operator()(WorldObject* obj) const
        {
            if (Unit* target = obj->ToUnit())
                return target->GetPowerType() != _power;

            return true;
        }

    private:
        Powers const _power;
};

class RaidCheck
{
    public:
        explicit RaidCheck(Unit const* caster) : _caster(caster) { }

        bool operator()(WorldObject* obj) const
        {
            if (Unit* target = obj->ToUnit())
                return !_caster->IsInRaidWith(target);

            return true;
        }

    private:
        Unit const* _caster;
};

// 26169 - Oracle Healing Bonus
class spell_pri_aq_3p_bonus : public SpellScriptLoader
{
    public:
        spell_pri_aq_3p_bonus() : SpellScriptLoader("spell_pri_aq_3p_bonus") { }

        class spell_pri_aq_3p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_aq_3p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PRIEST_ORACULAR_HEAL });
            }

            void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                Unit* caster = eventInfo.GetActor();
                if (caster == eventInfo.GetProcTarget())
                    return;

                HealInfo* healInfo = eventInfo.GetHealInfo();
                if (!healInfo || !healInfo->GetHeal())
                    return;

                CastSpellExtraArgs args(aurEff);
                args.AddSpellBP0(CalculatePct(static_cast<int32>(healInfo->GetHeal()), 10));
                caster->CastSpell(caster, SPELL_PRIEST_ORACULAR_HEAL, args);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pri_aq_3p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_aq_3p_bonus_AuraScript();
        }
};

// 81749 - Atonement
class spell_pri_atonement : public SpellScriptLoader
{
public:
    static char constexpr const ScriptName[] = "spell_pri_atonement";

    spell_pri_atonement() : SpellScriptLoader(ScriptName) { }

    class spell_pri_atonement_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pri_atonement_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_PRIEST_ATONEMENT_HEAL });
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            return eventInfo.GetDamageInfo() != nullptr;
        }

        void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
        {
            DamageInfo* damageInfo = eventInfo.GetDamageInfo();
            CastSpellExtraArgs args(aurEff);
            args.AddSpellMod(SPELLVALUE_BASE_POINT0, CalculatePct(damageInfo->GetDamage(), aurEff->GetAmount()));
            _appliedAtonements.erase(std::remove_if(_appliedAtonements.begin(), _appliedAtonements.end(), [this, &args](ObjectGuid const& targetGuid)
            {
                if (Unit* target = ObjectAccessor::GetUnit(*GetTarget(), targetGuid))
                {
                    if (target->GetExactDist(GetTarget()) < GetSpellInfo()->GetEffect(EFFECT_1)->CalcValue())
                        GetTarget()->CastSpell(target, SPELL_PRIEST_ATONEMENT_HEAL, args);

                    return false;
                }
                return true;
            }), _appliedAtonements.end());
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_pri_atonement_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_pri_atonement_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }

        std::vector<ObjectGuid> _appliedAtonements;

    public:
        void AddAtonementTarget(ObjectGuid const& target)
        {
            _appliedAtonements.push_back(target);
        }

        void RemoveAtonementTarget(ObjectGuid const& target)
        {
            _appliedAtonements.erase(std::remove(_appliedAtonements.begin(), _appliedAtonements.end(), target), _appliedAtonements.end());
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pri_atonement_AuraScript();
    }
};
char constexpr const spell_pri_atonement::ScriptName[];

// 194384, 214206 - Atonement
class spell_pri_atonement_triggered : public SpellScriptLoader
{
public:
    spell_pri_atonement_triggered() : SpellScriptLoader("spell_pri_atonement_triggered") { }

    class spell_pri_atonement_triggered_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pri_atonement_triggered_AuraScript);

        using AtonementScript = spell_pri_atonement::spell_pri_atonement_AuraScript;

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_PRIEST_ATONEMENT });
        }

        void HandleOnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            RegisterHelper<&AtonementScript::AddAtonementTarget>();
        }

        void HandleOnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            RegisterHelper<&AtonementScript::RemoveAtonementTarget>();
        }

        template<void(AtonementScript::*func)(ObjectGuid const&)>
        void RegisterHelper()
        {
            if (Unit* caster = GetCaster())
                if (Aura* atonement = caster->GetAura(SPELL_PRIEST_ATONEMENT))
                    if (AtonementScript* script = atonement->GetScript<AtonementScript>(spell_pri_atonement::ScriptName))
                        (script->*func)(GetTarget()->GetGUID());
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_pri_atonement_triggered_AuraScript::HandleOnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_pri_atonement_triggered_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pri_atonement_triggered_AuraScript();
    }
};

// 64844 - Divine Hymn
class spell_pri_divine_hymn : public SpellScriptLoader
{
    public:
        spell_pri_divine_hymn() : SpellScriptLoader("spell_pri_divine_hymn") { }

        class spell_pri_divine_hymn_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_divine_hymn_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(RaidCheck(GetCaster()));

                uint32 const maxTargets = 3;

                if (targets.size() > maxTargets)
                {
                    targets.sort(Trinity::HealthPctOrderPred());
                    targets.resize(maxTargets);
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pri_divine_hymn_SpellScript::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pri_divine_hymn_SpellScript();
        }
};

// 47788 - Guardian Spirit
class spell_pri_guardian_spirit : public SpellScriptLoader
{
    public:
        spell_pri_guardian_spirit() : SpellScriptLoader("spell_pri_guardian_spirit") { }

        class spell_pri_guardian_spirit_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_guardian_spirit_AuraScript);

            uint32 healPct = 0;

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PRIEST_GUARDIAN_SPIRIT_HEAL });
            }

            bool Load() override
            {
                healPct = GetSpellInfo()->GetEffect(EFFECT_1)->CalcValue();
                return true;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                // Set absorbtion amount to unlimited
                amount = -1;
            }

            void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
            {
                Unit* target = GetTarget();
                if (dmgInfo.GetDamage() < target->GetHealth())
                    return;

                int32 healAmount = int32(target->CountPctFromMaxHealth(healPct));
                // remove the aura now, we don't want 40% healing bonus
                Remove(AURA_REMOVE_BY_ENEMY_SPELL);
                CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                args.AddSpellBP0(healAmount);
                target->CastSpell(target, SPELL_PRIEST_GUARDIAN_SPIRIT_HEAL, args);
                absorbAmount = dmgInfo.GetDamage();
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pri_guardian_spirit_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB);
                OnEffectAbsorb += AuraEffectAbsorbFn(spell_pri_guardian_spirit_AuraScript::Absorb, EFFECT_1);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_guardian_spirit_AuraScript();
        }
};

// 63733 - Holy Words
class spell_pri_holy_words : public AuraScript
{
    PrepareAuraScript(spell_pri_holy_words);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_PRIEST_HEAL,
            SPELL_PRIEST_FLASH_HEAL,
            SPELL_PRIEST_PRAYER_OF_HEALING,
            SPELL_PRIEST_RENEW,
            SPELL_PRIEST_SMITE,
            SPELL_PRIEST_HOLY_WORD_CHASTISE,
            SPELL_PRIEST_HOLY_WORD_SANCTIFY,
            SPELL_PRIEST_HOLY_WORD_SERENITY
        })
            && sSpellMgr->AssertSpellInfo(SPELL_PRIEST_HOLY_WORD_SERENITY, DIFFICULTY_NONE)->GetEffect(EFFECT_1)
            && sSpellMgr->AssertSpellInfo(SPELL_PRIEST_HOLY_WORD_SANCTIFY, DIFFICULTY_NONE)->GetEffect(EFFECT_2)
            && sSpellMgr->AssertSpellInfo(SPELL_PRIEST_HOLY_WORD_SANCTIFY, DIFFICULTY_NONE)->GetEffect(EFFECT_3)
            && sSpellMgr->AssertSpellInfo(SPELL_PRIEST_HOLY_WORD_CHASTISE, DIFFICULTY_NONE)->GetEffect(EFFECT_1);
    }

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
        if (!spellInfo)
            return;

        uint32 targetSpellId;
        SpellEffIndex cdReductionEffIndex;
        switch (spellInfo->Id)
        {
            case SPELL_PRIEST_HEAL:
            case SPELL_PRIEST_FLASH_HEAL: // reduce Holy Word: Serenity cd by 6 seconds
                targetSpellId = SPELL_PRIEST_HOLY_WORD_SERENITY;
                cdReductionEffIndex = EFFECT_1;
                // cdReduction = sSpellMgr->GetSpellInfo(SPELL_PRIEST_HOLY_WORD_SERENITY, GetCastDifficulty())->GetEffect(EFFECT_1)->CalcValue(player);
                break;
            case SPELL_PRIEST_PRAYER_OF_HEALING: // reduce Holy Word: Sanctify cd by 6 seconds
                targetSpellId = SPELL_PRIEST_HOLY_WORD_SANCTIFY;
                cdReductionEffIndex = EFFECT_2;
                break;
            case SPELL_PRIEST_RENEW: // reuce Holy Word: Sanctify cd by 2 seconds
                targetSpellId = SPELL_PRIEST_HOLY_WORD_SANCTIFY;
                cdReductionEffIndex = EFFECT_3;
                break;
            case SPELL_PRIEST_SMITE: // reduce Holy Word: Chastise cd by 4 seconds
                targetSpellId = SPELL_PRIEST_HOLY_WORD_CHASTISE;
                cdReductionEffIndex = EFFECT_1;
                break;
            default:
                TC_LOG_WARN("spells.priest", "HolyWords aura has been proced by an unknown spell: %u", GetSpellInfo()->Id);
                return;
        }

        SpellInfo const* targetSpellInfo = sSpellMgr->AssertSpellInfo(targetSpellId, GetCastDifficulty());
        int32 cdReduction = targetSpellInfo->GetEffect(cdReductionEffIndex)->CalcValue(GetTarget());
        GetTarget()->GetSpellHistory()->ModifyCooldown(targetSpellInfo, Seconds(-cdReduction));
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pri_holy_words::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 40438 - Priest Tier 6 Trinket
class spell_pri_item_t6_trinket : public SpellScriptLoader
{
    public:
        spell_pri_item_t6_trinket() : SpellScriptLoader("spell_pri_item_t6_trinket") { }

        class spell_pri_item_t6_trinket_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_item_t6_trinket_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PRIEST_DIVINE_BLESSING, SPELL_PRIEST_DIVINE_WRATH });
            }

            void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                Unit* caster = eventInfo.GetActor();
                if (eventInfo.GetSpellTypeMask() & PROC_SPELL_TYPE_HEAL)
                    caster->CastSpell(nullptr, SPELL_PRIEST_DIVINE_BLESSING, true);

                if (eventInfo.GetSpellTypeMask() & PROC_SPELL_TYPE_DAMAGE)
                    caster->CastSpell(nullptr, SPELL_PRIEST_DIVINE_WRATH, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pri_item_t6_trinket_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_item_t6_trinket_AuraScript();
        }
};

// 92833 - Leap of Faith
class spell_pri_leap_of_faith_effect_trigger : public SpellScriptLoader
{
    public:
        spell_pri_leap_of_faith_effect_trigger() : SpellScriptLoader("spell_pri_leap_of_faith_effect_trigger") { }

        class spell_pri_leap_of_faith_effect_trigger_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_leap_of_faith_effect_trigger_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PRIEST_LEAP_OF_FAITH_EFFECT });
            }

            void HandleEffectDummy(SpellEffIndex /*effIndex*/)
            {
                Position destPos = GetHitDest()->GetPosition();

                SpellCastTargets targets;
                targets.SetDst(destPos);
                targets.SetUnitTarget(GetCaster());
                GetHitUnit()->CastSpell(targets, GetEffectValue(), GetCastDifficulty());
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_pri_leap_of_faith_effect_trigger_SpellScript::HandleEffectDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pri_leap_of_faith_effect_trigger_SpellScript();
        }
};

// 1706 - Levitate
class spell_pri_levitate : public SpellScriptLoader
{
public:
    spell_pri_levitate() : SpellScriptLoader("spell_pri_levitate") { }

    class spell_pri_levitate_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pri_levitate_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_PRIEST_LEVITATE_EFFECT });
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->CastSpell(GetHitUnit(), SPELL_PRIEST_LEVITATE_EFFECT, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_pri_levitate_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pri_levitate_SpellScript();
    }
};

// 47540 - Penance
class spell_pri_penance : public SpellScriptLoader
{
    public:
        spell_pri_penance() : SpellScriptLoader("spell_pri_penance") { }

        class spell_pri_penance_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_penance_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            bool Validate(SpellInfo const* spellInfo) override
            {
                SpellInfo const* firstRankSpellInfo = sSpellMgr->GetSpellInfo(SPELL_PRIEST_PENANCE_R1, DIFFICULTY_NONE);
                if (!firstRankSpellInfo)
                    return false;

                // can't use other spell than this penance due to spell_ranks dependency
                if (!spellInfo->IsRankOf(firstRankSpellInfo))
                    return false;

                uint8 rank = spellInfo->GetRank();
                if (!sSpellMgr->GetSpellWithRank(SPELL_PRIEST_PENANCE_R1_DAMAGE, rank, true))
                    return false;
                if (!sSpellMgr->GetSpellWithRank(SPELL_PRIEST_PENANCE_R1_HEAL, rank, true))
                    return false;

                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetHitUnit())
                {
                    if (!target->IsAlive())
                        return;

                    uint8 rank = GetSpellInfo()->GetRank();

                    if (caster->IsFriendlyTo(target))
                        caster->CastSpell(target, sSpellMgr->GetSpellWithRank(SPELL_PRIEST_PENANCE_R1_HEAL, rank), false);
                    else
                        caster->CastSpell(target, sSpellMgr->GetSpellWithRank(SPELL_PRIEST_PENANCE_R1_DAMAGE, rank), false);
                }
            }

            SpellCastResult CheckCast()
            {
                Player* caster = GetCaster()->ToPlayer();
                if (Unit* target = GetExplTargetUnit())
                {
                    if (!caster->IsFriendlyTo(target))
                    {
                        if (!caster->IsValidAttackTarget(target))
                            return SPELL_FAILED_BAD_TARGETS;

                        if (!caster->isInFront(target))
                            return SPELL_FAILED_UNIT_NOT_INFRONT;
                    }
                }

                return SPELL_CAST_OK;
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_pri_penance_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                OnCheckCast += SpellCheckCastFn(spell_pri_penance_SpellScript::CheckCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pri_penance_SpellScript;
        }
};

// 194509 - Power Word: Radiance
class spell_pri_power_word_radiance : public SpellScript
{
    PrepareSpellScript(spell_pri_power_word_radiance);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_ATONEMENT, SPELL_PRIEST_ATONEMENT_TRIGGERED, SPELL_PRIEST_TRINITY });
    }

    void OnTargetSelect(std::list<WorldObject*>& targets)
    {
        SpellEffectInfo const* eff2 = GetEffectInfo(EFFECT_2);
        if (!eff2)
            return;

        uint32 maxTargets = eff2->CalcValue(GetCaster()) + 1; // adding 1 for explicit target unit
        if (targets.size() > maxTargets)
        {
            Unit* explTarget = GetExplTargetUnit();

            // Sort targets so units with no atonement are first, then units who are injured, then oher units
            // Make sure explicit target unit is first
            targets.sort([this, explTarget](WorldObject* lhs, WorldObject* rhs)
            {
                if (lhs == explTarget) // explTarget > anything: always true
                    return true;
                if (rhs == explTarget) // anything > explTarget: always false
                    return false;
                return MakeSortTuple(lhs) > MakeSortTuple(rhs);
            });

            targets.resize(maxTargets);
        }
    }

    void HandleEffectHitTarget(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (caster->HasAura(SPELL_PRIEST_TRINITY))
            return;

        SpellEffectInfo const* effect3 = GetEffectInfo(EFFECT_3);
        if (!effect3)
            return;

        uint32 durationPct = effect3->CalcValue(caster);
        if (caster->HasAura(SPELL_PRIEST_ATONEMENT))
            caster->CastSpell(GetHitUnit(), SPELL_PRIEST_ATONEMENT_TRIGGERED, CastSpellExtraArgs(SPELLVALUE_DURATION_PCT, durationPct).SetTriggerFlags(TRIGGERED_FULL_MASK));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pri_power_word_radiance::OnTargetSelect, EFFECT_1, TARGET_UNIT_DEST_AREA_ALLY);
        OnEffectHitTarget += SpellEffectFn(spell_pri_power_word_radiance::HandleEffectHitTarget, EFFECT_1, SPELL_EFFECT_HEAL);
    }

private:
    std::tuple<bool, bool> MakeSortTuple(WorldObject* obj)
    {
        return std::make_tuple(IsUnitWithNoAtonement(obj), IsUnitInjured(obj));
    }

    // Returns true if obj is a unit but has no atonement
    bool IsUnitWithNoAtonement(WorldObject* obj)
    {
        Unit* unit = obj->ToUnit();
        return unit && !unit->HasAura(SPELL_PRIEST_ATONEMENT_TRIGGERED, GetCaster()->GetGUID());
    }

    // Returns true if obj is a unit and is injured
    static bool IsUnitInjured(WorldObject* obj)
    {
        Unit* unit = obj->ToUnit();
        return unit && !unit->IsFullHealth();
    }
};

// 17 - Power Word: Shield
class spell_pri_power_word_shield : public SpellScriptLoader
{
public:
    spell_pri_power_word_shield() : SpellScriptLoader("spell_pri_power_word_shield") { }

    class spell_pri_power_word_shield_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pri_power_word_shield_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo
            ({
                SPELL_PRIEST_BODY_AND_SOUL,
                SPELL_PRIEST_BODY_AND_SOUL_SPEED,
                SPELL_PRIEST_STRENGTH_OF_SOUL,
                SPELL_PRIEST_STRENGTH_OF_SOUL_EFFECT,
                SPELL_PRIEST_RENEWED_HOPE,
                SPELL_PRIEST_RENEWED_HOPE_EFFECT,
                SPELL_PRIEST_VOID_SHIELD,
                SPELL_PRIEST_VOID_SHIELD_EFFECT,
                SPELL_PRIEST_ATONEMENT,
                SPELL_PRIEST_TRINITY,
                SPELL_PRIEST_ATONEMENT_TRIGGERED,
                SPELL_PRIEST_ATONEMENT_TRIGGERED_TRINITY,
                SPELL_PRIEST_SHIELD_DISCIPLINE_PASSIVE,
                SPELL_PRIEST_SHIELD_DISCIPLINE_ENERGIZE
            });
        }

        void CalculateAmount(AuraEffect const* /*auraEffect*/, int32& amount, bool& canBeRecalculated)
        {
            canBeRecalculated = false;

            if (Player* player = GetCaster()->ToPlayer())
            {
                int32 playerMastery = player->GetRatingBonusValue(CR_MASTERY);
                int32 playerSpellPower = player->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_HOLY);
                int32 playerVersatileDamage = player->GetRatingBonusValue(CR_VERSATILITY_DAMAGE_DONE);

                //Formula taken from SpellWork
                amount = (int32)((playerSpellPower * 5.5f) + playerMastery) * (1 + playerVersatileDamage);
            }
        }

        void HandleOnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget();
            if (!caster)
                return;

            if (caster->HasAura(SPELL_PRIEST_BODY_AND_SOUL))
                caster->CastSpell(target, SPELL_PRIEST_BODY_AND_SOUL_SPEED, true);
            if (caster->HasAura(SPELL_PRIEST_STRENGTH_OF_SOUL))
                caster->CastSpell(target, SPELL_PRIEST_STRENGTH_OF_SOUL_EFFECT, true);
            if (caster->HasAura(SPELL_PRIEST_RENEWED_HOPE))
                caster->CastSpell(target, SPELL_PRIEST_RENEWED_HOPE_EFFECT, true);
            if (caster->HasAura(SPELL_PRIEST_VOID_SHIELD) && caster == target)
                caster->CastSpell(target, SPELL_PRIEST_VOID_SHIELD_EFFECT, true);
            if (caster->HasAura(SPELL_PRIEST_ATONEMENT))
                caster->CastSpell(target, caster->HasAura(SPELL_PRIEST_TRINITY) ? SPELL_PRIEST_ATONEMENT_TRIGGERED_TRINITY : SPELL_PRIEST_ATONEMENT_TRIGGERED, true);
        }

        void HandleOnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            GetTarget()->RemoveAura(SPELL_PRIEST_STRENGTH_OF_SOUL_EFFECT);
            if (Unit* caster = GetCaster())
                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL && caster->HasAura(SPELL_PRIEST_SHIELD_DISCIPLINE_PASSIVE))
                    caster->CastSpell(caster, SPELL_PRIEST_SHIELD_DISCIPLINE_ENERGIZE, true);
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pri_power_word_shield_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            AfterEffectApply += AuraEffectApplyFn(spell_pri_power_word_shield_AuraScript::HandleOnApply, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            AfterEffectRemove += AuraEffectRemoveFn(spell_pri_power_word_shield_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pri_power_word_shield_AuraScript();
    }
};

// Base class used by various prayer of mending spells
class spell_pri_prayer_of_mending_SpellScriptBase : public SpellScript
{
public:
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_PRAYER_OF_MENDING_HEAL, SPELL_PRIEST_PRAYER_OF_MENDING_AURA })
            && sSpellMgr->AssertSpellInfo(SPELL_PRIEST_PRAYER_OF_MENDING_HEAL, DIFFICULTY_NONE)->GetEffect(EFFECT_0);
    }

    bool Load() override
    {
        _spellInfoHeal = sSpellMgr->AssertSpellInfo(SPELL_PRIEST_PRAYER_OF_MENDING_HEAL, DIFFICULTY_NONE);
        _healEffectDummy = _spellInfoHeal->GetEffect(EFFECT_0);
        return true;
    }

    void CastPrayerOfMendingAura(Unit* caster, Unit* target, uint8 stack)
    {
        uint32 basePoints = caster->SpellHealingBonusDone(target, _spellInfoHeal, _healEffectDummy->CalcValue(caster), HEAL, _healEffectDummy);
        CastSpellExtraArgs args;
        args.TriggerFlags = TRIGGERED_FULL_MASK;
        args.AddSpellMod(SPELLVALUE_AURA_STACK, stack);
        args.AddSpellMod(SPELLVALUE_BASE_POINT0, basePoints);
        caster->CastSpell(target, SPELL_PRIEST_PRAYER_OF_MENDING_AURA, args);
    }

protected:
    SpellInfo const* _spellInfoHeal;
    SpellEffectInfo const* _healEffectDummy;
};

// 33076 - Prayer of Mending
class spell_pri_prayer_of_mending : public spell_pri_prayer_of_mending_SpellScriptBase
{
    PrepareSpellScript(spell_pri_prayer_of_mending);

    void HandleEffectDummy(SpellEffIndex /*effIndex*/)
    {
        CastPrayerOfMendingAura(GetCaster(), GetHitUnit(), GetEffectValue());
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_pri_prayer_of_mending::HandleEffectDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 41635 - Prayer of Mending (Aura) - SPELL_PRIEST_PRAYER_OF_MENDING_AURA
class spell_pri_prayer_of_mending_aura : public AuraScript
{
    PrepareAuraScript(spell_pri_prayer_of_mending_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_PRAYER_OF_MENDING_HEAL, SPELL_PRIEST_PRAYER_OF_MENDING_JUMP });
    }

    void HandleHeal(AuraEffect* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        // Caster: player (priest) that cast the Prayer of Mending
        // Target: player that currently has Prayer of Mending aura on him
        Unit* target = GetTarget();
        if (Unit* caster = GetCaster())
        {
            // Cast the spell to heal the owner
            caster->CastSpell(target, SPELL_PRIEST_PRAYER_OF_MENDING_HEAL, aurEff);

            // Only cast jump if stack is higher than 0
            int32 stackAmount = GetStackAmount();
            if (stackAmount > 1)
            {
                CastSpellExtraArgs args;
                args.TriggerFlags = TRIGGERED_FULL_MASK;
                args.TriggeringAura = aurEff;
                args.OriginalCaster = caster->GetGUID();
                args.AddSpellMod(SPELLVALUE_BASE_POINT0, stackAmount - 1);
                target->CastSpell(target, SPELL_PRIEST_PRAYER_OF_MENDING_JUMP, args);
            }

            Remove();
        }
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pri_prayer_of_mending_aura::HandleHeal, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 155793 - prayer of mending (Jump) - SPELL_PRIEST_PRAYER_OF_MENDING_JUMP
class spell_pri_prayer_of_mending_jump : public spell_pri_prayer_of_mending_SpellScriptBase
{
    PrepareSpellScript(spell_pri_prayer_of_mending_jump);

    void OnTargetSelect(std::list<WorldObject*>& targets)
    {
        // Find the best target - prefer players over pets
        bool foundPlayer = false;
        for (WorldObject* worldObject : targets)
        {
            if (worldObject->IsPlayer())
            {
                foundPlayer = true;
                break;
            }
        }

        if (foundPlayer)
            targets.remove_if(Trinity::ObjectTypeIdCheck(TYPEID_PLAYER, false));

        // choose one random target from targets
        if (targets.size() > 1)
        {
            WorldObject* selected = Trinity::Containers::SelectRandomContainerElement(targets);
            targets.clear();
            targets.push_back(selected);
        }
    }

    void HandleJump(SpellEffIndex /*effIndex*/)
    {
        Unit* origCaster = GetOriginalCaster(); // the one that started the prayer of mending chain
        Unit* target = GetHitUnit(); // the target we decided the aura should jump to

        if (origCaster)
            CastPrayerOfMendingAura(origCaster, target, GetEffectValue());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pri_prayer_of_mending_jump::OnTargetSelect, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
        OnEffectHitTarget += SpellEffectFn(spell_pri_prayer_of_mending_jump::HandleJump, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 20711 - Spirit of Redemption
class spell_pri_spirit_of_redemption : public AuraScript
{
    PrepareAuraScript(spell_pri_spirit_of_redemption);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_SPIRIT_OF_REDEMPTION });
    }

    void HandleAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
    {
        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_PRIEST_SPIRIT_OF_REDEMPTION, aurEff);
        target->SetFullHealth();

        absorbAmount = dmgInfo.GetDamage();
    }

    void Register() override
    {
        OnEffectAbsorb += AuraEffectAbsorbOverkillFn(spell_pri_spirit_of_redemption::HandleAbsorb, EFFECT_0);
    }
};

// 186263 - Shadow Mend
class spell_pri_shadow_mend : public SpellScript
{
    PrepareSpellScript(spell_pri_shadow_mend);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_ATONEMENT, SPELL_PRIEST_ATONEMENT_TRIGGERED, SPELL_PRIEST_TRINITY });
    }

    void HandleEffectHit(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
        {
            Unit* caster = GetCaster();
            if (caster->HasAura(SPELL_PRIEST_ATONEMENT) && !caster->HasAura(SPELL_PRIEST_TRINITY))
                caster->CastSpell(target, SPELL_PRIEST_ATONEMENT_TRIGGERED, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pri_shadow_mend::HandleEffectHit, EFFECT_0, SPELL_EFFECT_HEAL);
    }
};

// 28809 - Greater Heal
class spell_pri_t3_4p_bonus : public SpellScriptLoader
{
    public:
        spell_pri_t3_4p_bonus() : SpellScriptLoader("spell_pri_t3_4p_bonus") { }

        class spell_pri_t3_4p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_t3_4p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PRIEST_ARMOR_OF_FAITH });
            }

            void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), SPELL_PRIEST_ARMOR_OF_FAITH, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pri_t3_4p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_t3_4p_bonus_AuraScript();
        }
};

// 37594 - Greater Heal Refund
class spell_pri_t5_heal_2p_bonus : public SpellScriptLoader
{
    public:
        spell_pri_t5_heal_2p_bonus() : SpellScriptLoader("spell_pri_t5_heal_2p_bonus") { }

        class spell_pri_t5_heal_2p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_t5_heal_2p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PRIEST_ITEM_EFFICIENCY });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                if (HealInfo* healInfo = eventInfo.GetHealInfo())
                    if (Unit* healTarget = healInfo->GetTarget())
                        if (healInfo->GetEffectiveHeal())
                            if (healTarget->GetHealth() >= healTarget->GetMaxHealth())
                                return true;

                return false;
            }

            void HandleProc(AuraEffect* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_PRIEST_ITEM_EFFICIENCY, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_pri_t5_heal_2p_bonus_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pri_t5_heal_2p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_t5_heal_2p_bonus_AuraScript();
        }
};

// 70770 - Item - Priest T10 Healer 2P Bonus
class spell_pri_t10_heal_2p_bonus : public SpellScriptLoader
{
    public:
        spell_pri_t10_heal_2p_bonus() : SpellScriptLoader("spell_pri_t10_heal_2p_bonus") { }

        class spell_pri_t10_heal_2p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_t10_heal_2p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PRIEST_BLESSED_HEALING });
            }

            void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                HealInfo* healInfo = eventInfo.GetHealInfo();
                if (!healInfo || !healInfo->GetHeal())
                    return;

                SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_PRIEST_BLESSED_HEALING, GetCastDifficulty());
                int32 amount = CalculatePct(static_cast<int32>(healInfo->GetHeal()), aurEff->GetAmount());

                ASSERT(spellInfo->GetMaxTicks() > 0);
                amount /= spellInfo->GetMaxTicks();

                // Add remaining ticks to healing done
                Unit* caster = eventInfo.GetActor();
                Unit* target = eventInfo.GetProcTarget();
                amount += target->GetRemainingPeriodicAmount(caster->GetGUID(), SPELL_PRIEST_BLESSED_HEALING, SPELL_AURA_PERIODIC_HEAL);

                CastSpellExtraArgs args(aurEff);
                args.AddSpellBP0(amount);
                caster->CastSpell(target, SPELL_PRIEST_BLESSED_HEALING, args);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pri_t10_heal_2p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_t10_heal_2p_bonus_AuraScript();
        }
};

// 15286 - Vampiric Embrace
class spell_pri_vampiric_embrace : public SpellScriptLoader
{
    public:
        spell_pri_vampiric_embrace() : SpellScriptLoader("spell_pri_vampiric_embrace") { }

        class spell_pri_vampiric_embrace_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_vampiric_embrace_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PRIEST_VAMPIRIC_EMBRACE_HEAL });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                // Not proc from Mind Sear
                return !(eventInfo.GetDamageInfo()->GetSpellInfo()->SpellFamilyFlags[1] & 0x80000);
            }

            void HandleEffectProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo || !damageInfo->GetDamage())
                    return;

                int32 selfHeal = int32(CalculatePct(damageInfo->GetDamage(), aurEff->GetAmount()));
                int32 teamHeal = selfHeal / 2;

                CastSpellExtraArgs args(aurEff);
                args.AddSpellMod(SPELLVALUE_BASE_POINT0, teamHeal);
                args.AddSpellMod(SPELLVALUE_BASE_POINT1, selfHeal);
                GetTarget()->CastSpell(nullptr, SPELL_PRIEST_VAMPIRIC_EMBRACE_HEAL, args);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_pri_vampiric_embrace_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pri_vampiric_embrace_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_vampiric_embrace_AuraScript();
        }
};

// 15290 - Vampiric Embrace (heal)
class spell_pri_vampiric_embrace_target : public SpellScriptLoader
{
    public:
        spell_pri_vampiric_embrace_target() : SpellScriptLoader("spell_pri_vampiric_embrace_target") { }

        class spell_pri_vampiric_embrace_target_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_vampiric_embrace_target_SpellScript);

            void FilterTargets(std::list<WorldObject*>& unitList)
            {
                unitList.remove(GetCaster());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pri_vampiric_embrace_target_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_PARTY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pri_vampiric_embrace_target_SpellScript();
        }
};

// 34914 - Vampiric Touch
class spell_pri_vampiric_touch : public SpellScriptLoader
{
    public:
        spell_pri_vampiric_touch() : SpellScriptLoader("spell_pri_vampiric_touch") { }

        class spell_pri_vampiric_touch_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_vampiric_touch_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PRIEST_VAMPIRIC_TOUCH_DISPEL, SPELL_GEN_REPLENISHMENT });
            }

            void HandleDispel(DispelInfo* /*dispelInfo*/)
            {
                if (Unit* caster = GetCaster())
                {
                    if (Unit* target = GetUnitOwner())
                    {
                        if (AuraEffect const* aurEff = GetEffect(EFFECT_1))
                        {
                            // backfire damage
                            int32 bp = aurEff->GetAmount();
                            bp = target->SpellDamageBonusTaken(caster, aurEff->GetSpellInfo(), bp, DOT);
                            bp *= 8;

                            CastSpellExtraArgs args(aurEff);
                            args.AddSpellBP0(bp);
                            caster->CastSpell(target, SPELL_PRIEST_VAMPIRIC_TOUCH_DISPEL, args);
                        }
                    }
                }
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return eventInfo.GetProcTarget() == GetCaster();
            }

            void HandleEffectProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                eventInfo.GetProcTarget()->CastSpell(nullptr, SPELL_GEN_REPLENISHMENT, aurEff);
            }

            void Register() override
            {
                AfterDispel += AuraDispelFn(spell_pri_vampiric_touch_AuraScript::HandleDispel);
                DoCheckProc += AuraCheckProcFn(spell_pri_vampiric_touch_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pri_vampiric_touch_AuraScript::HandleEffectProc, EFFECT_2, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_vampiric_touch_AuraScript();
        }
};

// 121536 - Angelic Feather talent
class spell_pri_angelic_feather_trigger : public SpellScriptLoader
{
    public:
        spell_pri_angelic_feather_trigger() : SpellScriptLoader("spell_pri_angelic_feather_trigger") { }

        class spell_pri_angelic_feather_trigger_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_angelic_feather_trigger_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PRIEST_ANGELIC_FEATHER_AREATRIGGER });
            }

            void HandleEffectDummy(SpellEffIndex /*effIndex*/)
            {
                Position destPos = GetHitDest()->GetPosition();
                float radius = GetEffectInfo()->CalcRadius();

                // Caster is prioritary
                if (GetCaster()->IsWithinDist2d(&destPos, radius))
                {
                    GetCaster()->CastSpell(GetCaster(), SPELL_PRIEST_ANGELIC_FEATHER_AURA, true);
                }
                else
                {
                    SpellCastTargets targets;
                    targets.SetDst(destPos);
                    CastSpellExtraArgs args;
                    args.TriggerFlags = TRIGGERED_FULL_MASK;
                    args.CastDifficulty = GetCastDifficulty();
                    GetCaster()->CastSpell(targets, SPELL_PRIEST_ANGELIC_FEATHER_AREATRIGGER, args);
                }
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_pri_angelic_feather_trigger_SpellScript::HandleEffectDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pri_angelic_feather_trigger_SpellScript();
        }
};

// Angelic Feather areatrigger - created by SPELL_PRIEST_ANGELIC_FEATHER_AREATRIGGER
class areatrigger_pri_angelic_feather : public AreaTriggerEntityScript
{
public:
    areatrigger_pri_angelic_feather() : AreaTriggerEntityScript("areatrigger_pri_angelic_feather") { }

    struct areatrigger_pri_angelic_featherAI : AreaTriggerAI
    {
        areatrigger_pri_angelic_featherAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        // Called when the AreaTrigger has just been initialized, just before added to map
        void OnInitialize() override
        {
            if (Unit* caster = at->GetCaster())
            {
                std::vector<AreaTrigger*> areaTriggers = caster->GetAreaTriggers(SPELL_PRIEST_ANGELIC_FEATHER_AREATRIGGER);

                if (areaTriggers.size() >= 3)
                    areaTriggers.front()->SetDuration(0);
            }
        }

        void OnUnitEnter(Unit* unit) override
        {
            if (Unit* caster = at->GetCaster())
            {
                if (caster->IsFriendlyTo(unit))
                {
                    // If target already has aura, increase duration to max 130% of initial duration
                    caster->CastSpell(unit, SPELL_PRIEST_ANGELIC_FEATHER_AURA, true);
                    at->SetDuration(0);
                }
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new areatrigger_pri_angelic_featherAI(areatrigger);
    }
};

void AddSC_priest_spell_scripts()
{
    new spell_pri_aq_3p_bonus();
    new spell_pri_atonement();
    new spell_pri_atonement_triggered();
    new spell_pri_divine_hymn();
    new spell_pri_guardian_spirit();
    RegisterAuraScript(spell_pri_holy_words);
    new spell_pri_item_t6_trinket();
    new spell_pri_leap_of_faith_effect_trigger();
    new spell_pri_levitate();
    new spell_pri_penance();
    RegisterSpellScript(spell_pri_power_word_radiance);
    new spell_pri_power_word_shield();
    RegisterSpellScript(spell_pri_prayer_of_mending);
    RegisterAuraScript(spell_pri_prayer_of_mending_aura);
    RegisterSpellScript(spell_pri_prayer_of_mending_jump);
    RegisterAuraScript(spell_pri_spirit_of_redemption);
    RegisterSpellScript(spell_pri_shadow_mend);
    new spell_pri_t3_4p_bonus();
    new spell_pri_t5_heal_2p_bonus();
    new spell_pri_t10_heal_2p_bonus();
    new spell_pri_vampiric_embrace();
    new spell_pri_vampiric_embrace_target();
    new spell_pri_vampiric_touch();
    new spell_pri_angelic_feather_trigger();
    new areatrigger_pri_angelic_feather();
}
