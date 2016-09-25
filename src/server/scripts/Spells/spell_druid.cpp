/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
 * Scripts for spells with SPELLFAMILY_DRUID and SPELLFAMILY_GENERIC spells used by druid players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_dru_".
 */

#include "Player.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Containers.h"

enum DruidSpells
{
    SPELL_DRUID_BEAR_FORM_PASSIVE           = 1178,
    SPELL_DRUID_DIRE_BEAR_FORM_PASSIVE      = 9635,
    SPELL_DRUID_ECLIPSE_LUNAR_PROC          = 48518,
    SPELL_DRUID_ECLIPSE_SOLAR_PROC          = 48517,
    SPELL_DRUID_FORMS_TRINKET_BEAR          = 37340,
    SPELL_DRUID_FORMS_TRINKET_CAT           = 37341,
    SPELL_DRUID_FORMS_TRINKET_MOONKIN       = 37343,
    SPELL_DRUID_FORMS_TRINKET_NONE          = 37344,
    SPELL_DRUID_FORMS_TRINKET_TREE          = 37342,
    SPELL_DRUID_ENRAGE                      = 5229,
    SPELL_DRUID_ENRAGE_MOD_DAMAGE           = 51185,
    SPELL_DRUID_ENRAGED_DEFENSE             = 70725,
    SPELL_DRUID_GLYPH_OF_TYPHOON            = 62135,
    SPELL_DRUID_IDOL_OF_FERAL_SHADOWS       = 34241,
    SPELL_DRUID_IDOL_OF_WORSHIP             = 60774,
    SPELL_DRUID_INCREASED_MOONFIRE_DURATION = 38414,
    SPELL_DRUID_ITEM_T8_BALANCE_RELIC       = 64950,
    SPELL_DRUID_ITEM_T10_FERAL_4P_BONUS     = 70726,
    SPELL_DRUID_KING_OF_THE_JUNGLE          = 48492,
    SPELL_DRUID_LIFEBLOOM_ENERGIZE          = 64372,
    SPELL_DRUID_LIFEBLOOM_FINAL_HEAL        = 33778,
    SPELL_DRUID_LIVING_SEED_HEAL            = 48503,
    SPELL_DRUID_LIVING_SEED_PROC            = 48504,
    SPELL_DRUID_NATURES_SPLENDOR            = 57865,
    SPELL_DRUID_SURVIVAL_INSTINCTS          = 50322,
    SPELL_DRUID_SAVAGE_ROAR                 = 62071,
    SPELL_DRUID_T9_FERAL_RELIC_BEAR         = 67354,
    SPELL_DRUID_T9_FERAL_RELIC_CAT          = 67355,
    SPELL_DRUID_TIGER_S_FURY_ENERGIZE       = 51178,
    SPELL_DRUID_T3_PROC_ENERGIZE_MANA       = 28722,
    SPELL_DRUID_T3_PROC_ENERGIZE_RAGE       = 28723,
    SPELL_DRUID_T3_PROC_ENERGIZE_ENERGY     = 28724,
    SPELL_DRUID_BLESSING_OF_THE_CLAW        = 28750,
    SPELL_DRUID_REVITALIZE_ENERGIZE_MANA    = 48542,
    SPELL_DRUID_REVITALIZE_ENERGIZE_RAGE    = 48541,
    SPELL_DRUID_REVITALIZE_ENERGIZE_ENERGY  = 48540,
    SPELL_DRUID_REVITALIZE_ENERGIZE_RP      = 48543,
    SPELL_DRUID_GLYPH_OF_INNERVATE_REGEN    = 54833,
    SPELL_DRUID_GLYPH_OF_STARFIRE_SCRIPT    = 54846,
    SPELL_DRUID_GLYPH_OF_RIP                = 54818,
    SPELL_DRUID_RIP_DURATION_LACERATE_DMG   = 60141,
    SPELL_DRUID_GLYPH_OF_RAKE_TRIGGERED     = 54820,
    SPELL_DRUID_IMP_LEADER_OF_THE_PACK_R1   = 34297,
    SPELL_DRUID_IMP_LEADER_OF_THE_PACK_HEAL = 34299,
    SPELL_DRUID_IMP_LEADER_OF_THE_PACK_MANA = 68285,
    SPELL_DRUID_EXHILARATE                  = 28742,
    SPELL_DRUID_GLYPH_OF_REJUVENATION_HEAL  = 54755,
    SPELL_DRUID_INFUSION                    = 37238,
    SPELL_DRUID_BLESSING_OF_REMULOS         = 40445,
    SPELL_DRUID_BLESSING_OF_ELUNE           = 40446,
    SPELL_DRUID_BLESSING_OF_CENARIUS        = 40452,
    SPELL_DRUID_LANGUISH                    = 71023,
    SPELL_DRUID_REJUVENATION_T10_PROC       = 70691,
    SPELL_DRUID_BALANCE_T10_BONUS           = 70718,
    SPELL_DRUID_BALANCE_T10_BONUS_PROC      = 70721
};

// 1178 - Bear Form (Passive)
// 9635 - Dire Bear Form (Passive)
class spell_dru_bear_form_passive : public SpellScriptLoader
{
    public:
        spell_dru_bear_form_passive() : SpellScriptLoader("spell_dru_bear_form_passive") { }

        class spell_dru_bear_form_passive_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_bear_form_passive_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_ENRAGE)
                    || !sSpellMgr->GetSpellInfo(SPELL_DRUID_ITEM_T10_FERAL_4P_BONUS))
                    return false;
                return true;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                if (!GetUnitOwner()->HasAura(SPELL_DRUID_ENRAGE) || GetUnitOwner()->HasAura(SPELL_DRUID_ITEM_T10_FERAL_4P_BONUS))
                    return;

                int32 mod = 0;
                switch (GetId())
                {
                    case SPELL_DRUID_BEAR_FORM_PASSIVE:
                        mod = -27;
                        break;
                    case SPELL_DRUID_DIRE_BEAR_FORM_PASSIVE:
                        mod = -16;
                        break;
                    default:
                        return;
                }
                amount += mod;
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_bear_form_passive_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_BASE_RESISTANCE_PCT);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_bear_form_passive_AuraScript();
        }
};

// -1850 - Dash
class spell_dru_dash : public SpellScriptLoader
{
    public:
        spell_dru_dash() : SpellScriptLoader("spell_dru_dash") { }

        class spell_dru_dash_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_dash_AuraScript);

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                // do not set speed if not in cat form
                if (GetUnitOwner()->GetShapeshiftForm() != FORM_CAT)
                    amount = 0;
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_dash_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_INCREASE_SPEED);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_dash_AuraScript();
        }
};

class spell_dru_eclipse : public SpellScriptLoader
{
public:
    spell_dru_eclipse() : SpellScriptLoader("spell_dru_eclipse") { }

    class spell_dru_eclipse_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_eclipse_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_ECLIPSE_LUNAR_PROC))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_ECLIPSE_SOLAR_PROC))
                return false;
            return true;
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (!eventInfo.GetSpellInfo())
                return false;

            if (eventInfo.GetActor()->HasAura(SPELL_DRUID_ECLIPSE_LUNAR_PROC) || eventInfo.GetActor()->HasAura(SPELL_DRUID_ECLIPSE_SOLAR_PROC))
                return false;

            // Triggered by Wrath?
            if (eventInfo.GetSpellInfo()->SpellFamilyFlags[0] & 1)
                return roll_chance_f(GetSpellInfo()->ProcChance * 0.6f) && _lunarProcCooldownEnd <= std::chrono::steady_clock::now();

            return _solarProcCooldownEnd <= std::chrono::steady_clock::now();
        }

        void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            if (eventInfo.GetSpellInfo()->SpellFamilyFlags[0] & 1)
            {
                _lunarProcCooldownEnd = std::chrono::steady_clock::now() + Seconds(aurEff->GetAmount());
                eventInfo.GetActor()->CastSpell(eventInfo.GetActor(), SPELL_DRUID_ECLIPSE_LUNAR_PROC, TRIGGERED_FULL_MASK, nullptr, aurEff);
            }
            else
            {
                _solarProcCooldownEnd = std::chrono::steady_clock::now() + Seconds(aurEff->GetAmount());
                eventInfo.GetActor()->CastSpell(eventInfo.GetActor(), SPELL_DRUID_ECLIPSE_SOLAR_PROC, TRIGGERED_FULL_MASK, nullptr, aurEff);
            }
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_dru_eclipse_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_dru_eclipse_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }

        std::chrono::steady_clock::time_point _lunarProcCooldownEnd = std::chrono::steady_clock::time_point::min();
        std::chrono::steady_clock::time_point _solarProcCooldownEnd = std::chrono::steady_clock::time_point::min();
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_eclipse_AuraScript();
    }
};

// 5229 - Enrage
class spell_dru_enrage : public SpellScriptLoader
{
    public:
        spell_dru_enrage() : SpellScriptLoader("spell_dru_enrage") { }

        class spell_dru_enrage_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_enrage_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_KING_OF_THE_JUNGLE)
                    || !sSpellMgr->GetSpellInfo(SPELL_DRUID_ENRAGE_MOD_DAMAGE)
                    || !sSpellMgr->GetSpellInfo(SPELL_DRUID_ENRAGED_DEFENSE)
                    || !sSpellMgr->GetSpellInfo(SPELL_DRUID_ITEM_T10_FERAL_4P_BONUS))
                    return false;
                return true;
            }

            void RecalculateBaseArmor()
            {
                Unit::AuraEffectList const& auras = GetTarget()->GetAuraEffectsByType(SPELL_AURA_MOD_BASE_RESISTANCE_PCT);
                for (Unit::AuraEffectList::const_iterator i = auras.begin(); i != auras.end(); ++i)
                {
                    SpellInfo const* spellInfo = (*i)->GetSpellInfo();
                    // Dire- / Bear Form (Passive)
                    if (spellInfo->SpellFamilyName == SPELLFAMILY_DRUID && spellInfo->SpellFamilyFlags.HasFlag(0x0, 0x0, 0x2))
                        (*i)->RecalculateAmount();
                }
            }

            void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                if (AuraEffect const* aurEff = target->GetAuraEffectOfRankedSpell(SPELL_DRUID_KING_OF_THE_JUNGLE, EFFECT_0))
                    target->CastCustomSpell(SPELL_DRUID_ENRAGE_MOD_DAMAGE, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), target, true);

                // Item - Druid T10 Feral 4P Bonus
                if (target->HasAura(SPELL_DRUID_ITEM_T10_FERAL_4P_BONUS))
                    target->CastSpell(target, SPELL_DRUID_ENRAGED_DEFENSE, true);

                RecalculateBaseArmor();
            }

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_ENRAGE_MOD_DAMAGE);
                GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_ENRAGED_DEFENSE);

                RecalculateBaseArmor();
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_dru_enrage_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_dru_enrage_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_enrage_AuraScript();
        }
};

// 37336 - Druid Forms Trinket
class spell_dru_forms_trinket : public SpellScriptLoader
{
public:
    spell_dru_forms_trinket() : SpellScriptLoader("spell_dru_forms_trinket") { }

    class spell_dru_forms_trinket_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_forms_trinket_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_FORMS_TRINKET_BEAR) ||
                !sSpellMgr->GetSpellInfo(SPELL_DRUID_FORMS_TRINKET_CAT) ||
                !sSpellMgr->GetSpellInfo(SPELL_DRUID_FORMS_TRINKET_MOONKIN) ||
                !sSpellMgr->GetSpellInfo(SPELL_DRUID_FORMS_TRINKET_NONE) ||
                !sSpellMgr->GetSpellInfo(SPELL_DRUID_FORMS_TRINKET_TREE))
                return false;
            return true;
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            Unit* target = eventInfo.GetActor();

            switch (target->GetShapeshiftForm())
            {
                case FORM_BEAR:
                case FORM_DIREBEAR:
                case FORM_CAT:
                case FORM_MOONKIN:
                case FORM_NONE:
                case FORM_TREE:
                    return true;
                default:
                    break;
            }

            return false;
        }

        void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            Unit* target = eventInfo.GetActor();
            uint32 triggerspell = 0;

            switch (target->GetShapeshiftForm())
            {
                case FORM_BEAR:
                case FORM_DIREBEAR:
                    triggerspell = SPELL_DRUID_FORMS_TRINKET_BEAR;
                    break;
                case FORM_CAT:
                    triggerspell = SPELL_DRUID_FORMS_TRINKET_CAT;
                    break;
                case FORM_MOONKIN:
                    triggerspell = SPELL_DRUID_FORMS_TRINKET_MOONKIN;
                    break;
                case FORM_NONE:
                    triggerspell = SPELL_DRUID_FORMS_TRINKET_NONE;
                    break;
                case FORM_TREE:
                    triggerspell = SPELL_DRUID_FORMS_TRINKET_TREE;
                    break;
                default:
                    return;
            }

            target->CastSpell(target, triggerspell, true, nullptr, aurEff);
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_dru_forms_trinket_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_dru_forms_trinket_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_forms_trinket_AuraScript();
    }
};

// -33943 - Flight Form
class spell_dru_flight_form : public SpellScriptLoader
{
    public:
        spell_dru_flight_form() : SpellScriptLoader("spell_dru_flight_form") { }

        class spell_dru_flight_form_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_flight_form_SpellScript);

            SpellCastResult CheckCast()
            {
                Unit* caster = GetCaster();
                if (caster->IsInDisallowedMountForm())
                    return SPELL_FAILED_NOT_SHAPESHIFT;

                return SPELL_CAST_OK;
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_dru_flight_form_SpellScript::CheckCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dru_flight_form_SpellScript();
        }
};

// 54832 - Glyph of Innervate
class spell_dru_glyph_of_innervate : public SpellScriptLoader
{
    public:
        spell_dru_glyph_of_innervate() : SpellScriptLoader("spell_dru_glyph_of_innervate") { }

        class spell_dru_glyph_of_innervate_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_glyph_of_innervate_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_GLYPH_OF_INNERVATE_REGEN))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                Unit* caster = eventInfo.GetActor();
                SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_DRUID_GLYPH_OF_INNERVATE_REGEN);
                int32 amount = CalculatePct(static_cast<int32>(caster->GetCreatePowers(POWER_MANA)), aurEff->GetAmount());
                amount /= spellInfo->GetMaxTicks();

                caster->CastCustomSpell(SPELL_DRUID_GLYPH_OF_INNERVATE_REGEN, SPELLVALUE_BASE_POINT0, amount, (Unit*)nullptr, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_glyph_of_innervate_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_glyph_of_innervate_AuraScript();
        }
};

// 54821 - Glyph of Rake
class spell_dru_glyph_of_rake : public SpellScriptLoader
{
    public:
        spell_dru_glyph_of_rake() : SpellScriptLoader("spell_dru_glyph_of_rake") { }

        class spell_dru_glyph_of_rake_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_glyph_of_rake_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_GLYPH_OF_RAKE_TRIGGERED))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return eventInfo.GetProcTarget()->GetTypeId() == TYPEID_UNIT;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), SPELL_DRUID_GLYPH_OF_RAKE_TRIGGERED, true);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_dru_glyph_of_rake_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_dru_glyph_of_rake_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_glyph_of_rake_AuraScript();
        }
};

// 54754 - Glyph of Rejuvenation
class spell_dru_glyph_of_rejuvenation : public SpellScriptLoader
{
    public:
        spell_dru_glyph_of_rejuvenation() : SpellScriptLoader("spell_dru_glyph_of_rejuvenation") { }

        class spell_dru_glyph_of_rejuvenation_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_glyph_of_rejuvenation_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_GLYPH_OF_REJUVENATION_HEAL))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return eventInfo.GetProcTarget()->HealthBelowPct(50);
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                HealInfo* healInfo = eventInfo.GetHealInfo();
                if (!healInfo || !healInfo->GetHeal())
                    return;

                int32 amount = CalculatePct(static_cast<int32>(healInfo->GetHeal()), aurEff->GetAmount());
                eventInfo.GetActor()->CastCustomSpell(SPELL_DRUID_GLYPH_OF_REJUVENATION_HEAL, SPELLVALUE_BASE_POINT0, amount, eventInfo.GetProcTarget(), true);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_dru_glyph_of_rejuvenation_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_dru_glyph_of_rejuvenation_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_glyph_of_rejuvenation_AuraScript();
        }
};

// 54815 - Glyph of Shred
class spell_dru_glyph_of_shred : public SpellScriptLoader
{
    public:
        spell_dru_glyph_of_shred() : SpellScriptLoader("spell_dru_glyph_of_shred") { }

        class spell_dru_glyph_of_shred_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_glyph_of_shred_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_GLYPH_OF_RIP) ||
                    !sSpellMgr->GetSpellInfo(SPELL_DRUID_RIP_DURATION_LACERATE_DMG))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                Unit* caster = eventInfo.GetActor();
                // try to find spell Rip on the target
                if (AuraEffect const* rip = eventInfo.GetProcTarget()->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DRUID, 0x00800000, 0x0, 0x0, caster->GetGUID()))
                {
                    // Rip's max duration, note: spells which modifies Rip's duration also counted like Glyph of Rip
                    uint32 countMin = rip->GetBase()->GetMaxDuration();

                    // just Rip's max duration without other spells
                    uint32 countMax = rip->GetSpellInfo()->GetMaxDuration();

                    // add possible auras' and Glyph of Shred's max duration
                    countMax += 3 * aurEff->GetAmount() * IN_MILLISECONDS;                                          // Glyph of Shred               -> +6 seconds
                    countMax += caster->HasAura(SPELL_DRUID_GLYPH_OF_RIP) ? 4 * IN_MILLISECONDS : 0;                // Glyph of Rip                 -> +4 seconds
                    countMax += caster->HasAura(SPELL_DRUID_RIP_DURATION_LACERATE_DMG) ? 4 * IN_MILLISECONDS : 0;   // T7 set bonus                 -> +4 seconds

                    // if min < max -> that means caster didn't cast 3 shred yet
                    // so set Rip's duration and max duration
                    if (countMin < countMax)
                    {
                        rip->GetBase()->SetDuration(rip->GetBase()->GetDuration() + aurEff->GetAmount() * IN_MILLISECONDS);
                        rip->GetBase()->SetMaxDuration(countMin + aurEff->GetAmount() * IN_MILLISECONDS);
                    }
                }
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_glyph_of_shred_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_glyph_of_shred_AuraScript();
        }
};

// 54846 - Glyph of Starfire
class spell_dru_glyph_of_starfire : public SpellScriptLoader
{
    public:
        spell_dru_glyph_of_starfire() : SpellScriptLoader("spell_dru_glyph_of_starfire") { }

        class spell_dru_glyph_of_starfire_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_glyph_of_starfire_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_INCREASED_MOONFIRE_DURATION) || !sSpellMgr->GetSpellInfo(SPELL_DRUID_NATURES_SPLENDOR))
                    return false;
                return true;
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* unitTarget = GetHitUnit())
                {
                    if (AuraEffect const* aurEff = unitTarget->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DRUID, 0x00000002, 0, 0, caster->GetGUID()))
                    {
                        Aura* aura = aurEff->GetBase();

                        uint32 countMin = aura->GetMaxDuration();
                        uint32 countMax = aura->GetSpellInfo()->GetMaxDuration() + 9000;
                        if (caster->HasAura(SPELL_DRUID_INCREASED_MOONFIRE_DURATION))
                            countMax += 3000;
                        if (caster->HasAura(SPELL_DRUID_NATURES_SPLENDOR))
                            countMax += 3000;

                        if (countMin < countMax)
                        {
                            aura->SetDuration(uint32(aura->GetDuration() + 3000));
                            aura->SetMaxDuration(countMin + 3000);
                        }
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dru_glyph_of_starfire_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dru_glyph_of_starfire_SpellScript();
        }
};

// 54845 - Glyph of Starfire
class spell_dru_glyph_of_starfire_dummy : public SpellScriptLoader
{
    public:
        spell_dru_glyph_of_starfire_dummy() : SpellScriptLoader("spell_dru_glyph_of_starfire_dummy") { }

        class spell_dru_glyph_of_starfire_dummy_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_glyph_of_starfire_dummy_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_GLYPH_OF_STARFIRE_SCRIPT))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), SPELL_DRUID_GLYPH_OF_STARFIRE_SCRIPT, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_glyph_of_starfire_dummy_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_glyph_of_starfire_dummy_AuraScript();
        }
};

// 34246 - Idol of the Emerald Queen
// 60779 - Idol of Lush Moss
class spell_dru_idol_lifebloom : public SpellScriptLoader
{
    public:
        spell_dru_idol_lifebloom() : SpellScriptLoader("spell_dru_idol_lifebloom") { }

        class spell_dru_idol_lifebloom_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_idol_lifebloom_AuraScript);

            void HandleEffectCalcSpellMod(AuraEffect const* aurEff, SpellModifier*& spellMod)
            {
                if (!spellMod)
                {
                    spellMod = new SpellModifier(GetAura());
                    spellMod->op = SPELLMOD_DOT;
                    spellMod->type = SPELLMOD_FLAT;
                    spellMod->spellId = GetId();
                    spellMod->mask = GetSpellInfo()->Effects[aurEff->GetEffIndex()].SpellClassMask;
                }
                spellMod->value = aurEff->GetAmount() / 7;
            }

            void Register() override
            {
                DoEffectCalcSpellMod += AuraEffectCalcSpellModFn(spell_dru_idol_lifebloom_AuraScript::HandleEffectCalcSpellMod, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_idol_lifebloom_AuraScript();
        }
};

// 29166 - Innervate
class spell_dru_innervate : public SpellScriptLoader
{
    public:
        spell_dru_innervate() : SpellScriptLoader("spell_dru_innervate") { }

        class spell_dru_innervate_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_innervate_AuraScript);

            void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
            {
                if (Unit* caster = GetCaster())
                    amount = int32(CalculatePct(caster->GetCreatePowers(POWER_MANA), amount) / aurEff->GetTotalTicks());
                else
                    amount = 0;
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_innervate_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_innervate_AuraScript();
        }
};

// -5570 - Insect Swarm
class spell_dru_insect_swarm : public SpellScriptLoader
{
    public:
        spell_dru_insect_swarm() : SpellScriptLoader("spell_dru_insect_swarm") { }

        class spell_dru_insect_swarm_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_insect_swarm_AuraScript);

            void CalculateAmount(AuraEffect const* aurEff, int32 & amount, bool & /*canBeRecalculated*/)
            {
                if (Unit* caster = GetCaster())
                    if (AuraEffect const* relicAurEff = caster->GetAuraEffect(SPELL_DRUID_ITEM_T8_BALANCE_RELIC, EFFECT_0))
                        amount += relicAurEff->GetAmount() / aurEff->GetTotalTicks();
            }

            void Register() override
            {
                 DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_insect_swarm_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_insect_swarm_AuraScript();
        }
};

// 24932 - Leader of the Pack
class spell_dru_leader_of_the_pack : public SpellScriptLoader
{
    public:
        spell_dru_leader_of_the_pack() : SpellScriptLoader("spell_dru_leader_of_the_pack") { }

        class spell_dru_leader_of_the_pack_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_leader_of_the_pack_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_IMP_LEADER_OF_THE_PACK_R1) ||
                    !sSpellMgr->GetSpellInfo(SPELL_DRUID_IMP_LEADER_OF_THE_PACK_HEAL) ||
                    !sSpellMgr->GetSpellInfo(SPELL_DRUID_IMP_LEADER_OF_THE_PACK_MANA))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                if (!aurEff->GetAmount())
                    return;

                Unit* caster = eventInfo.GetActor();
                if (caster->GetSpellHistory()->HasCooldown(SPELL_DRUID_IMP_LEADER_OF_THE_PACK_HEAL))
                    return;

                int32 amount = caster->CountPctFromMaxHealth(aurEff->GetAmount());
                caster->CastCustomSpell(SPELL_DRUID_IMP_LEADER_OF_THE_PACK_HEAL, SPELLVALUE_BASE_POINT0, amount, (Unit*)nullptr, true);

                // Because of how proc system works, we can't store proc cd on db, it would be applied to entire aura
                // so aura could only proc once per 6 seconds, independently of caster
                caster->GetSpellHistory()->AddCooldown(SPELL_DRUID_IMP_LEADER_OF_THE_PACK_HEAL, 0, Seconds(6));

                // only proc on self
                if (aurEff->GetCasterGUID() != caster->GetGUID())
                    return;

                AuraEffect const* impLotpMana = caster->GetAuraEffectOfRankedSpell(SPELL_DRUID_IMP_LEADER_OF_THE_PACK_R1, EFFECT_1, aurEff->GetCasterGUID());
                if (!impLotpMana)
                    return;

                int32 manaAmount = CalculatePct(static_cast<int32>(caster->GetMaxPower(POWER_MANA)), impLotpMana->GetAmount());
                caster->CastCustomSpell(SPELL_DRUID_IMP_LEADER_OF_THE_PACK_MANA, SPELLVALUE_BASE_POINT0, manaAmount, (Unit*)nullptr, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_leader_of_the_pack_AuraScript::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_leader_of_the_pack_AuraScript();
        }
};

// -33763 - Lifebloom
class spell_dru_lifebloom : public SpellScriptLoader
{
    public:
        spell_dru_lifebloom() : SpellScriptLoader("spell_dru_lifebloom") { }

        class spell_dru_lifebloom_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_lifebloom_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_LIFEBLOOM_FINAL_HEAL))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_LIFEBLOOM_ENERGIZE))
                    return false;
                return true;
            }

            void AfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                // Final heal only on duration end
                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
                    return;

                // final heal
                int32 stack = GetStackAmount();
                int32 healAmount = aurEff->GetAmount();
                if (Unit* caster = GetCaster())
                {
                    healAmount = caster->SpellHealingBonusDone(GetTarget(), GetSpellInfo(), healAmount, HEAL, stack);
                    healAmount = GetTarget()->SpellHealingBonusTaken(caster, GetSpellInfo(), healAmount, HEAL, stack);

                    GetTarget()->CastCustomSpell(GetTarget(), SPELL_DRUID_LIFEBLOOM_FINAL_HEAL, &healAmount, NULL, NULL, true, NULL, aurEff, GetCasterGUID());

                    // restore mana
                    int32 returnMana = CalculatePct(caster->GetCreateMana(), GetSpellInfo()->ManaCostPercentage) * stack / 2;
                    caster->CastCustomSpell(caster, SPELL_DRUID_LIFEBLOOM_ENERGIZE, &returnMana, NULL, NULL, true, NULL, aurEff, GetCasterGUID());
                    return;
                }

                GetTarget()->CastCustomSpell(GetTarget(), SPELL_DRUID_LIFEBLOOM_FINAL_HEAL, &healAmount, NULL, NULL, true, NULL, aurEff, GetCasterGUID());
            }

            void HandleDispel(DispelInfo* dispelInfo)
            {
                if (Unit* target = GetUnitOwner())
                {
                    if (AuraEffect const* aurEff = GetEffect(EFFECT_1))
                    {
                        // final heal
                        int32 healAmount = aurEff->GetAmount();
                        if (Unit* caster = GetCaster())
                        {
                            healAmount = caster->SpellHealingBonusDone(target, GetSpellInfo(), healAmount, HEAL, dispelInfo->GetRemovedCharges());
                            healAmount = target->SpellHealingBonusTaken(caster, GetSpellInfo(), healAmount, HEAL, dispelInfo->GetRemovedCharges());
                            target->CastCustomSpell(target, SPELL_DRUID_LIFEBLOOM_FINAL_HEAL, &healAmount, NULL, NULL, true, NULL, NULL, GetCasterGUID());

                            // restore mana
                            int32 returnMana = CalculatePct(caster->GetCreateMana(), GetSpellInfo()->ManaCostPercentage) * dispelInfo->GetRemovedCharges() / 2;
                            caster->CastCustomSpell(caster, SPELL_DRUID_LIFEBLOOM_ENERGIZE, &returnMana, NULL, NULL, true, NULL, NULL, GetCasterGUID());
                            return;
                        }

                        target->CastCustomSpell(target, SPELL_DRUID_LIFEBLOOM_FINAL_HEAL, &healAmount, NULL, NULL, true, NULL, NULL, GetCasterGUID());
                    }
                }
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_dru_lifebloom_AuraScript::AfterRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                AfterDispel += AuraDispelFn(spell_dru_lifebloom_AuraScript::HandleDispel);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_lifebloom_AuraScript();
        }
};

// -48496 - Living Seed
class spell_dru_living_seed : public SpellScriptLoader
{
    public:
        spell_dru_living_seed() : SpellScriptLoader("spell_dru_living_seed") { }

        class spell_dru_living_seed_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_living_seed_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_LIVING_SEED_PROC))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                HealInfo* healInfo = eventInfo.GetHealInfo();
                if (!healInfo || !healInfo->GetHeal())
                    return;

                int32 amount = CalculatePct(healInfo->GetHeal(), aurEff->GetAmount());
                GetTarget()->CastCustomSpell(SPELL_DRUID_LIVING_SEED_PROC, SPELLVALUE_BASE_POINT0, amount, eventInfo.GetProcTarget(), true, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_living_seed_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_living_seed_AuraScript();
        }
};

// 48504 - Living Seed (Proc)
class spell_dru_living_seed_proc : public SpellScriptLoader
{
    public:
        spell_dru_living_seed_proc() : SpellScriptLoader("spell_dru_living_seed_proc") { }

        class spell_dru_living_seed_proc_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_living_seed_proc_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_LIVING_SEED_HEAL))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastCustomSpell(SPELL_DRUID_LIVING_SEED_HEAL, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), GetTarget(), true, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_living_seed_proc_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_living_seed_proc_AuraScript();
        }
};

// 69366 - Moonkin Form passive
class spell_dru_moonkin_form_passive : public SpellScriptLoader
{
    public:
        spell_dru_moonkin_form_passive() : SpellScriptLoader("spell_dru_moonkin_form_passive") { }

        class spell_dru_moonkin_form_passive_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_moonkin_form_passive_AuraScript);

        public:
            spell_dru_moonkin_form_passive_AuraScript()
            {
                absorbPct = 0;
            }

        private:
            uint32 absorbPct;

            bool Load() override
            {
                absorbPct = GetSpellInfo()->Effects[EFFECT_0].CalcValue(GetCaster());
                return true;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                // Set absorbtion amount to unlimited
                amount = -1;
            }

            void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
            {
                // reduces all damage taken while Stunned in Moonkin Form
                if (GetTarget()->GetUInt32Value(UNIT_FIELD_FLAGS) & (UNIT_FLAG_STUNNED) && GetTarget()->HasAuraWithMechanic(1<<MECHANIC_STUN))
                    absorbAmount = CalculatePct(dmgInfo.GetDamage(), absorbPct);
            }

            void Register() override
            {
                 DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_moonkin_form_passive_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
                 OnEffectAbsorb += AuraEffectAbsorbFn(spell_dru_moonkin_form_passive_AuraScript::Absorb, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_moonkin_form_passive_AuraScript();
        }
};

// 16864 - Omen of Clarity
class spell_dru_omen_of_clarity : public SpellScriptLoader
{
    public:
        spell_dru_omen_of_clarity() : SpellScriptLoader("spell_dru_omen_of_clarity") { }

        class spell_dru_omen_of_clarity_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_omen_of_clarity_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_BALANCE_T10_BONUS) ||
                    !sSpellMgr->GetSpellInfo(SPELL_DRUID_BALANCE_T10_BONUS_PROC))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
            {
                Unit* target = GetTarget();
                if (target->HasAura(SPELL_DRUID_BALANCE_T10_BONUS))
                    target->CastSpell((Unit*)nullptr, SPELL_DRUID_BALANCE_T10_BONUS_PROC, true, nullptr);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_omen_of_clarity_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_omen_of_clarity_AuraScript();
        }
};

// 48391 - Owlkin Frenzy
class spell_dru_owlkin_frenzy : public SpellScriptLoader
{
    public:
        spell_dru_owlkin_frenzy() : SpellScriptLoader("spell_dru_owlkin_frenzy") { }

        class spell_dru_owlkin_frenzy_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_owlkin_frenzy_AuraScript);

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                amount = CalculatePct(GetUnitOwner()->GetCreatePowers(POWER_MANA), amount);
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_owlkin_frenzy_AuraScript::CalculateAmount, EFFECT_2, SPELL_AURA_PERIODIC_ENERGIZE);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_owlkin_frenzy_AuraScript();
        }
};

// -16972 - Predatory Strikes
class spell_dru_predatory_strikes : public SpellScriptLoader
{
    public:
        spell_dru_predatory_strikes() : SpellScriptLoader("spell_dru_predatory_strikes") { }

        class spell_dru_predatory_strikes_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_predatory_strikes_AuraScript);

            void UpdateAmount(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Player* target = GetTarget()->ToPlayer())
                    target->UpdateAttackPowerAndDamage();
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_dru_predatory_strikes_AuraScript::UpdateAmount, EFFECT_ALL, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
                AfterEffectRemove += AuraEffectRemoveFn(spell_dru_predatory_strikes_AuraScript::UpdateAmount, EFFECT_ALL, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_predatory_strikes_AuraScript();
        }
};

// 33851 - Primal Tenacity
class spell_dru_primal_tenacity : public SpellScriptLoader
{
    public:
        spell_dru_primal_tenacity() : SpellScriptLoader("spell_dru_primal_tenacity") { }

        class spell_dru_primal_tenacity_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_primal_tenacity_AuraScript);

        public:
            spell_dru_primal_tenacity_AuraScript()
            {
                absorbPct = 0;
            }

        private:
            uint32 absorbPct;

            bool Load() override
            {
                absorbPct = GetSpellInfo()->Effects[EFFECT_1].CalcValue(GetCaster());
                return true;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                // Set absorbtion amount to unlimited
                amount = -1;
            }

            void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
            {
                // reduces all damage taken while Stunned in Cat Form
                if (GetTarget()->GetShapeshiftForm() == FORM_CAT && GetTarget()->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED) && GetTarget()->HasAuraWithMechanic(1<<MECHANIC_STUN))
                    absorbAmount = CalculatePct(dmgInfo.GetDamage(), absorbPct);
            }

            void Register() override
            {
                 DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_primal_tenacity_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB);
                 OnEffectAbsorb += AuraEffectAbsorbFn(spell_dru_primal_tenacity_AuraScript::Absorb, EFFECT_1);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_primal_tenacity_AuraScript();
        }
};

// -48539 - Revitalize
class spell_dru_revitalize : public SpellScriptLoader
{
    public:
        spell_dru_revitalize() : SpellScriptLoader("spell_dru_revitalize") { }

        class spell_dru_revitalize_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_revitalize_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_REVITALIZE_ENERGIZE_MANA) ||
                    !sSpellMgr->GetSpellInfo(SPELL_DRUID_REVITALIZE_ENERGIZE_RAGE) ||
                    !sSpellMgr->GetSpellInfo(SPELL_DRUID_REVITALIZE_ENERGIZE_ENERGY) ||
                    !sSpellMgr->GetSpellInfo(SPELL_DRUID_REVITALIZE_ENERGIZE_RP))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                if (!roll_chance_i(aurEff->GetAmount()))
                    return;

                Unit* target = eventInfo.GetProcTarget();
                uint32 spellId;

                switch (target->getPowerType())
                {
                    case POWER_MANA:
                        spellId = SPELL_DRUID_REVITALIZE_ENERGIZE_MANA;
                        break;
                    case POWER_RAGE:
                        spellId = SPELL_DRUID_REVITALIZE_ENERGIZE_RAGE;
                        break;
                    case POWER_ENERGY:
                        spellId = SPELL_DRUID_REVITALIZE_ENERGIZE_ENERGY;
                        break;
                    case POWER_RUNIC_POWER:
                        spellId = SPELL_DRUID_REVITALIZE_ENERGIZE_RP;
                        break;
                    default:
                        return;
                }

                eventInfo.GetActor()->CastSpell(target, spellId, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_revitalize_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_revitalize_AuraScript();
        }
};

// -1079 - Rip
class spell_dru_rip : public SpellScriptLoader
{
    public:
        spell_dru_rip() : SpellScriptLoader("spell_dru_rip") { }

        class spell_dru_rip_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_rip_AuraScript);

            bool Load() override
            {
                Unit* caster = GetCaster();
                return caster && caster->GetTypeId() == TYPEID_PLAYER;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
            {
                canBeRecalculated = false;

                if (Unit* caster = GetCaster())
                {
                    // 0.01 * $AP * cp
                    uint8 cp = caster->ToPlayer()->GetComboPoints();

                    // Idol of Feral Shadows. Can't be handled as SpellMod due its dependency from CPs
                    if (AuraEffect const* auraEffIdolOfFeralShadows = caster->GetAuraEffect(SPELL_DRUID_IDOL_OF_FERAL_SHADOWS, EFFECT_0))
                        amount += cp * auraEffIdolOfFeralShadows->GetAmount();
                    // Idol of Worship. Can't be handled as SpellMod due its dependency from CPs
                    else if (AuraEffect const* auraEffIdolOfWorship = caster->GetAuraEffect(SPELL_DRUID_IDOL_OF_WORSHIP, EFFECT_0))
                        amount += cp * auraEffIdolOfWorship->GetAmount();

                    amount += int32(CalculatePct(caster->GetTotalAttackPowerValue(BASE_ATTACK), cp));
                }
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_rip_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_rip_AuraScript();
        }
};

// 62600 - Savage Defense
class spell_dru_savage_defense : public SpellScriptLoader
{
    public:
        spell_dru_savage_defense() : SpellScriptLoader("spell_dru_savage_defense") { }

        class spell_dru_savage_defense_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_savage_defense_AuraScript);

            bool Validate(SpellInfo const* spellInfo) override
            {
                if (!sSpellMgr->GetSpellInfo(spellInfo->Effects[EFFECT_0].TriggerSpell))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                Unit* caster = eventInfo.GetActor();
                int32 amount = static_cast<int32>(CalculatePct(caster->GetTotalAttackPowerValue(BASE_ATTACK), aurEff->GetAmount()));
                caster->CastCustomSpell(GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell, SPELLVALUE_BASE_POINT0, amount, (Unit*)nullptr, true);
            }

            void Register() override
            {
                 OnEffectProc += AuraEffectProcFn(spell_dru_savage_defense_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_savage_defense_AuraScript();
        }
};

// 52610 - Savage Roar
class spell_dru_savage_roar : public SpellScriptLoader
{
    public:
        spell_dru_savage_roar() : SpellScriptLoader("spell_dru_savage_roar") { }

        class spell_dru_savage_roar_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_savage_roar_SpellScript);

            SpellCastResult CheckCast()
            {
                Unit* caster = GetCaster();
                if (caster->GetShapeshiftForm() != FORM_CAT)
                    return SPELL_FAILED_ONLY_SHAPESHIFT;

                return SPELL_CAST_OK;
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_dru_savage_roar_SpellScript::CheckCast);
            }
        };

        class spell_dru_savage_roar_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_savage_roar_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_SAVAGE_ROAR))
                    return false;
                return true;
            }

            void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                target->CastSpell(target, SPELL_DRUID_SAVAGE_ROAR, true, NULL, aurEff, GetCasterGUID());
            }

            void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_SAVAGE_ROAR);
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_dru_savage_roar_AuraScript::AfterApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_dru_savage_roar_AuraScript::AfterRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dru_savage_roar_SpellScript();
        }

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_savage_roar_AuraScript();
        }
};

// -50294 - Starfall (AOE)
class spell_dru_starfall_aoe : public SpellScriptLoader
{
    public:
        spell_dru_starfall_aoe() : SpellScriptLoader("spell_dru_starfall_aoe") { }

        class spell_dru_starfall_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_starfall_aoe_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove(GetExplTargetUnit());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_starfall_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dru_starfall_aoe_SpellScript();
        }
};

// -50286 - Starfall (Dummy)
class spell_dru_starfall_dummy : public SpellScriptLoader
{
    public:
        spell_dru_starfall_dummy() : SpellScriptLoader("spell_dru_starfall_dummy") { }

        class spell_dru_starfall_dummy_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_starfall_dummy_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                Trinity::Containers::RandomResizeList(targets, 2);
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                // Shapeshifting into an animal form or mounting cancels the effect
                if (caster->GetCreatureType() == CREATURE_TYPE_BEAST || caster->IsMounted())
                {
                    if (SpellInfo const* spellInfo = GetTriggeringSpell())
                        caster->RemoveAurasDueToSpell(spellInfo->Id);
                    return;
                }

                // Any effect which causes you to lose control of your character will supress the starfall effect.
                if (caster->HasUnitState(UNIT_STATE_CONTROLLED))
                    return;

                caster->CastSpell(GetHitUnit(), uint32(GetEffectValue()), true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_starfall_dummy_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_dru_starfall_dummy_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dru_starfall_dummy_SpellScript();
        }
};

// 61336 - Survival Instincts
class spell_dru_survival_instincts : public SpellScriptLoader
{
    public:
        spell_dru_survival_instincts() : SpellScriptLoader("spell_dru_survival_instincts") { }

        class spell_dru_survival_instincts_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_survival_instincts_SpellScript);

            SpellCastResult CheckCast()
            {
                Unit* caster = GetCaster();
                if (!caster->IsInFeralForm())
                    return SPELL_FAILED_ONLY_SHAPESHIFT;

                return SPELL_CAST_OK;
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_dru_survival_instincts_SpellScript::CheckCast);
            }
        };

        class spell_dru_survival_instincts_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_survival_instincts_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_SURVIVAL_INSTINCTS))
                    return false;
                return true;
            }

            void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                int32 bp0 = target->CountPctFromMaxHealth(aurEff->GetAmount());
                target->CastCustomSpell(target, SPELL_DRUID_SURVIVAL_INSTINCTS, &bp0, NULL, NULL, true);
            }

            void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_SURVIVAL_INSTINCTS);
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_dru_survival_instincts_AuraScript::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
                AfterEffectRemove += AuraEffectRemoveFn(spell_dru_survival_instincts_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dru_survival_instincts_SpellScript();
        }

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_survival_instincts_AuraScript();
        }
};

// 40121 - Swift Flight Form (Passive)
class spell_dru_swift_flight_passive : public SpellScriptLoader
{
    public:
        spell_dru_swift_flight_passive() : SpellScriptLoader("spell_dru_swift_flight_passive") { }

        class spell_dru_swift_flight_passive_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_swift_flight_passive_AuraScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                if (Player* caster = GetCaster()->ToPlayer())
                    if (caster->Has310Flyer(false))
                        amount = 310;
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_swift_flight_passive_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_swift_flight_passive_AuraScript();
        }
};

// -5217 - Tiger's Fury
class spell_dru_tiger_s_fury : public SpellScriptLoader
{
    public:
        spell_dru_tiger_s_fury() : SpellScriptLoader("spell_dru_tiger_s_fury") { }

        class spell_dru_tiger_s_fury_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_tiger_s_fury_SpellScript);

            void OnHit()
            {
                if (AuraEffect const* aurEff = GetHitUnit()->GetAuraEffectOfRankedSpell(SPELL_DRUID_KING_OF_THE_JUNGLE, EFFECT_1))
                    GetHitUnit()->CastCustomSpell(SPELL_DRUID_TIGER_S_FURY_ENERGIZE, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), GetHitUnit(), true);
            }

            void Register() override
            {
                AfterHit += SpellHitFn(spell_dru_tiger_s_fury_SpellScript::OnHit);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dru_tiger_s_fury_SpellScript();
        }
};

// -61391 - Typhoon
class spell_dru_typhoon : public SpellScriptLoader
{
    public:
        spell_dru_typhoon() : SpellScriptLoader("spell_dru_typhoon") { }

        class spell_dru_typhoon_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_typhoon_SpellScript);

            void HandleKnockBack(SpellEffIndex effIndex)
            {
                // Glyph of Typhoon
                if (GetCaster()->HasAura(SPELL_DRUID_GLYPH_OF_TYPHOON))
                    PreventHitDefaultEffect(effIndex);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dru_typhoon_SpellScript::HandleKnockBack, EFFECT_0, SPELL_EFFECT_KNOCK_BACK);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dru_typhoon_SpellScript();
        }
};

// 28716 - Rejuvenation
class spell_dru_t3_2p_bonus : public SpellScriptLoader
{
    public:
        spell_dru_t3_2p_bonus() : SpellScriptLoader("spell_dru_t3_2p_bonus") { }

        class spell_dru_t3_2p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_t3_2p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_T3_PROC_ENERGIZE_MANA) ||
                    !sSpellMgr->GetSpellInfo(SPELL_DRUID_T3_PROC_ENERGIZE_RAGE) ||
                    !sSpellMgr->GetSpellInfo(SPELL_DRUID_T3_PROC_ENERGIZE_ENERGY))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                if (!roll_chance_i(50))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                Unit* target = eventInfo.GetProcTarget();
                uint32 spellId;

                switch (target->getPowerType())
                {
                    case POWER_MANA:
                        spellId = SPELL_DRUID_T3_PROC_ENERGIZE_MANA;
                        break;
                    case POWER_RAGE:
                        spellId = SPELL_DRUID_T3_PROC_ENERGIZE_RAGE;
                        break;
                    case POWER_ENERGY:
                        spellId = SPELL_DRUID_T3_PROC_ENERGIZE_ENERGY;
                        break;
                    default:
                        return;
                }

                eventInfo.GetActor()->CastSpell(target, spellId, true);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_dru_t3_2p_bonus_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_dru_t3_2p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_t3_2p_bonus_AuraScript();
        }
};

// 28744 - Regrowth
class spell_dru_t3_6p_bonus : public SpellScriptLoader
{
    public:
        spell_dru_t3_6p_bonus() : SpellScriptLoader("spell_dru_t3_6p_bonus") { }

        class spell_dru_t3_6p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_t3_6p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_BLESSING_OF_THE_CLAW))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), SPELL_DRUID_BLESSING_OF_THE_CLAW, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_t3_6p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_t3_6p_bonus_AuraScript();
        }
};

// 28719 - Healing Touch
class spell_dru_t3_8p_bonus : public SpellScriptLoader
{
        public:
            spell_dru_t3_8p_bonus() : SpellScriptLoader("spell_dru_t3_8p_bonus") { }

        class spell_dru_t3_8p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_t3_8p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_EXHILARATE))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo)
                    return;

                Unit* caster = eventInfo.GetActor();
                int32 amount = CalculatePct(spellInfo->CalcPowerCost(caster, spellInfo->GetSchoolMask()), aurEff->GetAmount());
                caster->CastCustomSpell(SPELL_DRUID_EXHILARATE, SPELLVALUE_BASE_POINT0, amount, (Unit*)nullptr, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_t3_8p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_t3_8p_bonus_AuraScript();
        }
};

// 37288 - Mana Restore
// 37295 - Mana Restore
class spell_dru_t4_2p_bonus : public SpellScriptLoader
{
    public:
        spell_dru_t4_2p_bonus() : SpellScriptLoader("spell_dru_t4_2p_bonus") { }

        class spell_dru_t4_2p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_t4_2p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_INFUSION))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                eventInfo.GetActor()->CastSpell((Unit*)nullptr, SPELL_DRUID_INFUSION, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_t4_2p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_t4_2p_bonus_AuraScript();
        }
};

// 40442 - Druid Tier 6 Trinket
class spell_dru_item_t6_trinket : public SpellScriptLoader
{
    public:
        spell_dru_item_t6_trinket() : SpellScriptLoader("spell_dru_item_t6_trinket") { }

        class spell_dru_item_t6_trinket_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_item_t6_trinket_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_BLESSING_OF_REMULOS) ||
                    !sSpellMgr->GetSpellInfo(SPELL_DRUID_BLESSING_OF_ELUNE) ||
                    !sSpellMgr->GetSpellInfo(SPELL_DRUID_BLESSING_OF_CENARIUS))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo)
                    return;

                uint32 spellId;
                int32 chance;

                // Starfire
                if (spellInfo->SpellFamilyFlags[0] & 0x00000004)
                {
                    spellId = SPELL_DRUID_BLESSING_OF_REMULOS;
                    chance = 25;
                }
                // Rejuvenation
                else if (spellInfo->SpellFamilyFlags[0] & 0x00000010)
                {
                    spellId = SPELL_DRUID_BLESSING_OF_ELUNE;
                    chance = 25;
                }
                // Mangle (Bear) and Mangle (Cat)
                else if (spellInfo->SpellFamilyFlags[1] & 0x00000440)
                {
                    spellId = SPELL_DRUID_BLESSING_OF_CENARIUS;
                    chance = 40;
                }
                else
                    return;

                if (roll_chance_i(chance))
                    eventInfo.GetActor()->CastSpell((Unit*)nullptr, spellId, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_item_t6_trinket_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_item_t6_trinket_AuraScript();
        }
};

// 67353 - T9 Feral Relic (Idol of Mutilation)
class spell_dru_t9_feral_relic : public SpellScriptLoader
{
public:
    spell_dru_t9_feral_relic() : SpellScriptLoader("spell_dru_t9_feral_relic") { }

    class spell_dru_t9_feral_relic_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_t9_feral_relic_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_T9_FERAL_RELIC_BEAR) ||
                !sSpellMgr->GetSpellInfo(SPELL_DRUID_T9_FERAL_RELIC_CAT))
                return false;
            return true;
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            Unit* target = eventInfo.GetActor();

            switch (target->GetShapeshiftForm())
            {
                case FORM_BEAR:
                case FORM_DIREBEAR:
                case FORM_CAT:
                    return true;
                default:
                    break;
            }

            return false;
        }

        void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            uint32 triggerspell = 0;

            Unit* target = eventInfo.GetActor();

            switch (target->GetShapeshiftForm())
            {
                case FORM_BEAR:
                case FORM_DIREBEAR:
                    triggerspell = SPELL_DRUID_T9_FERAL_RELIC_BEAR;
                    break;
                case FORM_CAT:
                    triggerspell = SPELL_DRUID_T9_FERAL_RELIC_CAT;
                    break;
                default:
                    return;
            }

            target->CastSpell(target, triggerspell, true, nullptr, aurEff);
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_dru_t9_feral_relic_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_dru_t9_feral_relic_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_t9_feral_relic_AuraScript();
    }
};

// 70723 - Item - Druid T10 Balance 4P Bonus
class spell_dru_t10_balance_4p_bonus : public SpellScriptLoader
{
    public:
        spell_dru_t10_balance_4p_bonus() : SpellScriptLoader("spell_dru_t10_balance_4p_bonus") { }

        class spell_dru_t10_balance_4p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_t10_balance_4p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_LANGUISH))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo || !damageInfo->GetDamage())
                    return;

                Unit* caster = eventInfo.GetActor();
                Unit* target = eventInfo.GetProcTarget();

                SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_DRUID_LANGUISH);
                int32 amount = CalculatePct(static_cast<int32>(damageInfo->GetDamage()), aurEff->GetAmount());
                amount /= spellInfo->GetMaxTicks();
                // Add remaining ticks to damage done
                amount += target->GetRemainingPeriodicAmount(caster->GetGUID(), SPELL_DRUID_LANGUISH, SPELL_AURA_PERIODIC_DAMAGE);

                caster->CastCustomSpell(SPELL_DRUID_LANGUISH, SPELLVALUE_BASE_POINT0, amount, target, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_t10_balance_4p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_t10_balance_4p_bonus_AuraScript();
        }
};

// 70691 - Item T10 Restoration 4P Bonus
class spell_dru_t10_restoration_4p_bonus : public SpellScriptLoader
{
    public:
        spell_dru_t10_restoration_4p_bonus() : SpellScriptLoader("spell_dru_t10_restoration_4p_bonus") { }

        class spell_dru_t10_restoration_4p_bonus_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_t10_restoration_4p_bonus_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster()->ToPlayer()->GetGroup())
                {
                    targets.clear();
                    targets.push_back(GetCaster());
                }
                else
                {
                    targets.remove(GetExplTargetUnit());
                    std::list<Unit*> tempTargets;
                    for (std::list<WorldObject*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                        if ((*itr)->GetTypeId() == TYPEID_PLAYER && GetCaster()->IsInRaidWith((*itr)->ToUnit()))
                            tempTargets.push_back((*itr)->ToUnit());

                    if (tempTargets.empty())
                    {
                        targets.clear();
                        FinishCast(SPELL_FAILED_DONT_REPORT);
                        return;
                    }

                    Unit* target = Trinity::Containers::SelectRandomContainerElement(tempTargets);
                    targets.clear();
                    targets.push_back(target);
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_t10_restoration_4p_bonus_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dru_t10_restoration_4p_bonus_SpellScript();
        }
};

// 70664 - Druid T10 Restoration 4P Bonus (Rejuvenation)
class spell_dru_t10_restoration_4p_bonus_dummy : public SpellScriptLoader
{
    public:
        spell_dru_t10_restoration_4p_bonus_dummy() : SpellScriptLoader("spell_dru_t10_restoration_4p_bonus_dummy") { }

        class spell_dru_t10_restoration_4p_bonus_dummy_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_t10_restoration_4p_bonus_dummy_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_REJUVENATION_T10_PROC))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo || spellInfo->Id == SPELL_DRUID_REJUVENATION_T10_PROC)
                    return false;

                HealInfo* healInfo = eventInfo.GetHealInfo();
                if (!healInfo || !healInfo->GetHeal())
                    return false;

                Player* caster = eventInfo.GetActor()->ToPlayer();
                if (!caster)
                    return false;

                return caster->GetGroup() || caster != eventInfo.GetProcTarget();
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                int32 amount = static_cast<int32>(eventInfo.GetHealInfo()->GetHeal());
                eventInfo.GetActor()->CastCustomSpell(SPELL_DRUID_REJUVENATION_T10_PROC, SPELLVALUE_BASE_POINT0, amount, (Unit*)nullptr, true);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_dru_t10_restoration_4p_bonus_dummy_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_dru_t10_restoration_4p_bonus_dummy_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_t10_restoration_4p_bonus_dummy_AuraScript();
        }
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

// -48438 - Wild Growth
class spell_dru_wild_growth : public SpellScriptLoader
{
    public:
        spell_dru_wild_growth() : SpellScriptLoader("spell_dru_wild_growth") { }

        class spell_dru_wild_growth_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_wild_growth_SpellScript);

            bool Validate(SpellInfo const* spellInfo) override
            {
                if (spellInfo->Effects[EFFECT_2].IsEffect() || spellInfo->Effects[EFFECT_2].CalcValue() <= 0)
                    return false;
                return true;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(RaidCheck(GetCaster()));

                uint32 const maxTargets = uint32(GetSpellInfo()->Effects[EFFECT_2].CalcValue(GetCaster()));

                if (targets.size() > maxTargets)
                {
                    targets.sort(Trinity::HealthPctOrderPred());
                    targets.resize(maxTargets);
                }

                _targets = targets;
            }

            void SetTargets(std::list<WorldObject*>& targets)
            {
                targets = _targets;
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_wild_growth_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_wild_growth_SpellScript::SetTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ALLY);
            }

        private:
            std::list<WorldObject*> _targets;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dru_wild_growth_SpellScript();
        }
};

void AddSC_druid_spell_scripts()
{
    new spell_dru_bear_form_passive();
    new spell_dru_dash();
    new spell_dru_eclipse();
    new spell_dru_enrage();
    new spell_dru_forms_trinket();
    new spell_dru_flight_form();
    new spell_dru_glyph_of_innervate();
    new spell_dru_glyph_of_rake();
    new spell_dru_glyph_of_rejuvenation();
    new spell_dru_glyph_of_shred();
    new spell_dru_glyph_of_starfire();
    new spell_dru_glyph_of_starfire_dummy();
    new spell_dru_idol_lifebloom();
    new spell_dru_innervate();
    new spell_dru_insect_swarm();
    new spell_dru_leader_of_the_pack();
    new spell_dru_lifebloom();
    new spell_dru_living_seed();
    new spell_dru_living_seed_proc();
    new spell_dru_moonkin_form_passive();
    new spell_dru_omen_of_clarity();
    new spell_dru_owlkin_frenzy();
    new spell_dru_predatory_strikes();
    new spell_dru_primal_tenacity();
    new spell_dru_revitalize();
    new spell_dru_rip();
    new spell_dru_savage_defense();
    new spell_dru_savage_roar();
    new spell_dru_starfall_aoe();
    new spell_dru_starfall_dummy();
    new spell_dru_survival_instincts();
    new spell_dru_swift_flight_passive();
    new spell_dru_tiger_s_fury();
    new spell_dru_typhoon();
    new spell_dru_t3_2p_bonus();
    new spell_dru_t3_6p_bonus();
    new spell_dru_t3_8p_bonus();
    new spell_dru_t4_2p_bonus();
    new spell_dru_item_t6_trinket();
    new spell_dru_t9_feral_relic();
    new spell_dru_t10_balance_4p_bonus();
    new spell_dru_t10_restoration_4p_bonus();
    new spell_dru_t10_restoration_4p_bonus_dummy();
    new spell_dru_wild_growth();
}
