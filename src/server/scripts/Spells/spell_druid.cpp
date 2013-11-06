/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
    SPELL_DRUID_WRATH                       = 5176,
    SPELL_DRUID_STARFIRE                    = 2912,
    SPELL_DRUID_STARSURGE                   = 78674,
    SPELL_DRUID_ECLIPSE_GENERAL_ENERGIZE    = 89265,
    SPELL_DRUID_STARSURGE_ENERGIZE          = 86605,
    SPELL_DRUID_LUNAR_ECLIPSE_MARKER        = 67484, // Will make the yellow arrow on eclipse bar point to the blue side (lunar)
    SPELL_DRUID_SOLAR_ECLIPSE_MARKER        = 67483, // Will make the yellow arrow on eclipse bar point to the yellow side (solar)
    SPELL_DRUID_SOLAR_ECLIPSE               = 48517,
    SPELL_DRUID_LUNAR_ECLIPSE               = 48518,
    SPELL_DRUID_ENRAGE_MOD_DAMAGE           = 51185,
    SPELL_DRUID_FERAL_CHARGE_BEAR           = 16979,
    SPELL_DRUID_FERAL_CHARGE_CAT            = 49376,
    SPELL_DRUID_GLYPH_OF_INNERVATE          = 54833,
    SPELL_DRUID_GLYPH_OF_STARFIRE           = 54846,
    SPELL_DRUID_GLYPH_OF_TYPHOON            = 62135,
    SPELL_DRUID_IDOL_OF_FERAL_SHADOWS       = 34241,
    SPELL_DRUID_IDOL_OF_WORSHIP             = 60774,
    SPELL_DRUID_INCREASED_MOONFIRE_DURATION = 38414,
    SPELL_DRUID_ITEM_T8_BALANCE_RELIC       = 64950,
    SPELL_DRUID_KING_OF_THE_JUNGLE          = 48492,
    SPELL_DRUID_LIFEBLOOM_ENERGIZE          = 64372,
    SPELL_DRUID_LIFEBLOOM_FINAL_HEAL        = 33778,
    SPELL_DRUID_LIVING_SEED_HEAL            = 48503,
    SPELL_DRUID_LIVING_SEED_PROC            = 48504,
    SPELL_DRUID_NATURES_GRACE               = 16880,
    SPELL_DRUID_NATURES_GRACE_TRIGGER       = 16886,
    SPELL_DRUID_SURVIVAL_INSTINCTS          = 50322,
    SPELL_DRUID_SAVAGE_ROAR                 = 62071,
    SPELL_DRUID_STAMPEDE_BAER_RANK_1        = 81016,
    SPELL_DRUID_STAMPEDE_CAT_RANK_1         = 81021,
    SPELL_DRUID_STAMPEDE_CAT_STATE          = 109881,
    SPELL_DRUID_TIGER_S_FURY_ENERGIZE       = 51178,
    SPELL_DRUID_NPC_WILD_MUSHROOM           = 47649,
    SPELL_DRUID_NPC_FUNGAL_GROWTH_1         = 43497,
    SPELL_DRUID_NPC_FUNGAL_GROWTH_2         = 43484,
    SPELL_DRUID_TALENT_FUNGAL_GROWTH_1      = 78788,
    SPELL_DRUID_TALENT_FUNGAL_GROWTH_2      = 78789,
    SPELL_DRUID_SPELL_FUNGAL_GROWTH_1       = 81291,
    SPELL_DRUID_SPELL_FUNGAL_GROWTH_2       = 81283,
    SPELL_DRUID_SPELL_WILD_MUSHROOM_SUICIDE = 92853,
    SPELL_DRUID_SPELL_WILD_MUSHROOM_DAMAGE  = 78777
};

// 1850 - Dash
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

            void Register() OVERRIDE
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_dash_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_INCREASE_SPEED);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_dru_dash_AuraScript();
        }
};

// 48517 - Eclipse (Solar)
// 48518 - Eclipse (Lunar)
class spell_dru_eclipse : public SpellScriptLoader
{
    public:
        spell_dru_eclipse(char const* scriptName) : SpellScriptLoader(scriptName) { }

        class spell_dru_eclipse_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_eclipse_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_NATURES_GRACE) ||
                    !sSpellMgr->GetSpellInfo(SPELL_DRUID_NATURES_GRACE_TRIGGER))
                    return false;
                return true;
            }

            bool Load() OVERRIDE
            {
                return GetCaster() && GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void ApplyEffect(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* caster = GetCaster();
                if (!caster)
                    return;

                if (caster->ToPlayer()->GetAuraOfRankedSpell(SPELL_DRUID_NATURES_GRACE))
                    caster->ToPlayer()->RemoveSpellCooldown(SPELL_DRUID_NATURES_GRACE_TRIGGER, true);
            }

            void Register() OVERRIDE
            {
                OnEffectApply += AuraEffectApplyFn(spell_dru_eclipse_AuraScript::ApplyEffect, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_dru_eclipse_AuraScript();
        }
};

// 2912, 5176, 78674 - Starfire, Wrath, and Starsurge
class spell_dru_eclipse_energize : public SpellScriptLoader
{
    public:
        spell_dru_eclipse_energize() : SpellScriptLoader("spell_dru_eclipse_energize") { }

        class spell_dru_eclipse_energize_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_eclipse_energize_SpellScript);

            int32 energizeAmount;

            bool Load() OVERRIDE
            {
                if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
                    return false;

                if (GetCaster()->ToPlayer()->getClass() != CLASS_DRUID)
                    return false;

                energizeAmount = 0;

                return true;
            }

            void HandleEnergize(SpellEffIndex effIndex)
            {
                Player* caster = GetCaster()->ToPlayer();

                // No boomy, no deal.
                if (caster->GetPrimaryTalentTree(caster->GetActiveSpec()) != TALENT_TREE_DRUID_BALANCE)
                    return;

                switch (GetSpellInfo()->Id)
                {
                    case SPELL_DRUID_WRATH:
                    {
                        energizeAmount = -GetSpellInfo()->Effects[effIndex].BasePoints; // -13
                        // If we are set to fill the lunar side or we've just logged in with 0 power..
                        if ((!caster->HasAura(SPELL_DRUID_SOLAR_ECLIPSE_MARKER) && caster->HasAura(SPELL_DRUID_LUNAR_ECLIPSE_MARKER))
                            || caster->GetPower(POWER_ECLIPSE) == 0)
                        {
                            caster->CastCustomSpell(caster, SPELL_DRUID_ECLIPSE_GENERAL_ENERGIZE, &energizeAmount, 0, 0, true);
                            // If the energize was due to 0 power, cast the eclipse marker aura
                            if (!caster->HasAura(SPELL_DRUID_LUNAR_ECLIPSE_MARKER))
                                caster->CastSpell(caster, SPELL_DRUID_LUNAR_ECLIPSE_MARKER, true);
                        }
                        // The energizing effect brought us out of the solar eclipse, remove the aura
                        if (caster->HasAura(SPELL_DRUID_SOLAR_ECLIPSE) && caster->GetPower(POWER_ECLIPSE) <= 0)
                            caster->RemoveAurasDueToSpell(SPELL_DRUID_SOLAR_ECLIPSE);
                        break;
                    }
                    case SPELL_DRUID_STARFIRE:
                    {
                        energizeAmount = GetSpellInfo()->Effects[effIndex].BasePoints; // 20
                        // If we are set to fill the solar side or we've just logged in with 0 power..
                        if ((!caster->HasAura(SPELL_DRUID_LUNAR_ECLIPSE_MARKER) && caster->HasAura(SPELL_DRUID_SOLAR_ECLIPSE_MARKER))
                            || caster->GetPower(POWER_ECLIPSE) == 0)
                        {
                            caster->CastCustomSpell(caster, SPELL_DRUID_ECLIPSE_GENERAL_ENERGIZE, &energizeAmount, 0, 0, true);
                            // If the energize was due to 0 power, cast the eclipse marker aura
                            if (!caster->HasAura(SPELL_DRUID_SOLAR_ECLIPSE_MARKER))
                                caster->CastSpell(caster, SPELL_DRUID_SOLAR_ECLIPSE_MARKER, true);
                        }
                        // The energizing effect brought us out of the lunar eclipse, remove the aura
                        if (caster->HasAura(SPELL_DRUID_LUNAR_ECLIPSE) && caster->GetPower(POWER_ECLIPSE) >= 0)
                            caster->RemoveAura(SPELL_DRUID_LUNAR_ECLIPSE);
                        break;
                    }
                    case SPELL_DRUID_STARSURGE:
                    {
                        // If we are set to fill the solar side or we've just logged in with 0 power (confirmed with sniffs)
                        if ((!caster->HasAura(SPELL_DRUID_LUNAR_ECLIPSE_MARKER) && caster->HasAura(SPELL_DRUID_SOLAR_ECLIPSE_MARKER))
                            || caster->GetPower(POWER_ECLIPSE) == 0)
                        {
                            energizeAmount = GetSpellInfo()->Effects[effIndex].BasePoints; // 15
                            caster->CastCustomSpell(caster, SPELL_DRUID_STARSURGE_ENERGIZE, &energizeAmount, 0, 0, true);

                            // If the energize was due to 0 power, cast the eclipse marker aura
                            if (!caster->HasAura(SPELL_DRUID_SOLAR_ECLIPSE_MARKER))
                                caster->CastSpell(caster, SPELL_DRUID_SOLAR_ECLIPSE_MARKER, true);
                        }
                        else if (!caster->HasAura(SPELL_DRUID_SOLAR_ECLIPSE_MARKER) && caster->HasAura(SPELL_DRUID_LUNAR_ECLIPSE_MARKER))
                        {
                            energizeAmount = -GetSpellInfo()->Effects[effIndex].BasePoints; // -15
                            caster->CastCustomSpell(caster, SPELL_DRUID_STARSURGE_ENERGIZE, &energizeAmount, 0, 0, true);
                        }
                        // The energizing effect brought us out of the lunar eclipse, remove the aura
                        if (caster->HasAura(SPELL_DRUID_LUNAR_ECLIPSE) && caster->GetPower(POWER_ECLIPSE) >= 0)
                            caster->RemoveAura(SPELL_DRUID_LUNAR_ECLIPSE);
                        // The energizing effect brought us out of the solar eclipse, remove the aura
                        else if (caster->HasAura(SPELL_DRUID_SOLAR_ECLIPSE) && caster->GetPower(POWER_ECLIPSE) <= 0)
                            caster->RemoveAura(SPELL_DRUID_SOLAR_ECLIPSE);
                        break;
                    }
                }
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_dru_eclipse_energize_SpellScript::HandleEnergize, EFFECT_1, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_dru_eclipse_energize_SpellScript;
        }
};

// 5229 - Enrage
class spell_dru_enrage : public SpellScriptLoader
{
    public:
        spell_dru_enrage() : SpellScriptLoader("spell_dru_enrage") { }

        class spell_dru_enrage_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_enrage_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_KING_OF_THE_JUNGLE)
                    || !sSpellMgr->GetSpellInfo(SPELL_DRUID_ENRAGE_MOD_DAMAGE))
                    return false;
                return true;
            }

            void OnHit()
            {
                if (AuraEffect const* aurEff = GetHitUnit()->GetAuraEffectOfRankedSpell(SPELL_DRUID_KING_OF_THE_JUNGLE, EFFECT_0))
                    GetHitUnit()->CastCustomSpell(SPELL_DRUID_ENRAGE_MOD_DAMAGE, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), GetHitUnit(), true);
            }

            void Register() OVERRIDE
            {
                AfterHit += SpellHitFn(spell_dru_enrage_SpellScript::OnHit);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_dru_enrage_SpellScript();
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_GLYPH_OF_INNERVATE))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                // Not proc from self Innervate
                return GetTarget() != eventInfo.GetProcTarget();
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_DRUID_GLYPH_OF_INNERVATE, true, NULL, aurEff);
            }

            void Register() OVERRIDE
            {
                DoCheckProc += AuraCheckProcFn(spell_dru_glyph_of_innervate_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_dru_glyph_of_innervate_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_dru_glyph_of_innervate_AuraScript();
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_INCREASED_MOONFIRE_DURATION))
                    return false;
                return true;
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* unitTarget = GetHitUnit())
                    if (AuraEffect const* aurEff = unitTarget->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DRUID, 0x2, 0, 0, caster->GetGUID()))
                    {
                        Aura* aura = aurEff->GetBase();

                        uint32 countMin = aura->GetMaxDuration();
                        uint32 countMax = aura->GetSpellInfo()->GetMaxDuration() + 9000;
                        if (caster->HasAura(SPELL_DRUID_INCREASED_MOONFIRE_DURATION))
                            countMax += 3000;

                        if (countMin < countMax)
                        {
                            aura->SetDuration(uint32(aura->GetDuration() + 3000));
                            aura->SetMaxDuration(countMin + 3000);
                        }
                    }
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_dru_glyph_of_starfire_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_dru_glyph_of_starfire_SpellScript();
        }
};

// 54845 - Glyph of Starfire
class spell_dru_glyph_of_starfire_proc : public SpellScriptLoader
{
    public:
        spell_dru_glyph_of_starfire_proc() : SpellScriptLoader("spell_dru_glyph_of_starfire_proc") { }

        class spell_dru_glyph_of_starfire_proc_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_glyph_of_starfire_proc_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_GLYPH_OF_STARFIRE))
                    return false;
                return true;
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_DRUID_GLYPH_OF_STARFIRE, true, NULL, aurEff);
            }

            void Register() OVERRIDE
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_glyph_of_starfire_proc_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_dru_glyph_of_starfire_proc_AuraScript();
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

            void Register() OVERRIDE
            {
                DoEffectCalcSpellMod += AuraEffectCalcSpellModFn(spell_dru_idol_lifebloom_AuraScript::HandleEffectCalcSpellMod, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
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
                amount = CalculatePct(int32(GetUnitOwner()->GetCreatePowers(POWER_MANA) / aurEff->GetTotalTicks()), amount);
            }

            void Register() OVERRIDE
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_innervate_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_dru_innervate_AuraScript();
        }
};

// 5570 - Insect Swarm
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

            void Register() OVERRIDE
            {
                 DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_insect_swarm_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_dru_insect_swarm_AuraScript();
        }
};

// 33763 - Lifebloom
class spell_dru_lifebloom : public SpellScriptLoader
{
    public:
        spell_dru_lifebloom() : SpellScriptLoader("spell_dru_lifebloom") { }

        class spell_dru_lifebloom_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_lifebloom_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) OVERRIDE
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

            void Register() OVERRIDE
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_dru_lifebloom_AuraScript::AfterRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                AfterDispel += AuraDispelFn(spell_dru_lifebloom_AuraScript::HandleDispel);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_LIVING_SEED_PROC))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 amount = CalculatePct(eventInfo.GetHealInfo()->GetHeal(), aurEff->GetAmount());
                GetTarget()->CastCustomSpell(SPELL_DRUID_LIVING_SEED_PROC, SPELLVALUE_BASE_POINT0, amount, eventInfo.GetProcTarget(), true, NULL, aurEff);
            }

            void Register() OVERRIDE
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_living_seed_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
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

            void Register() OVERRIDE
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_living_seed_proc_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_dru_living_seed_proc_AuraScript();
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

            void Register() OVERRIDE
            {
                AfterEffectApply += AuraEffectApplyFn(spell_dru_predatory_strikes_AuraScript::UpdateAmount, EFFECT_ALL, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
                AfterEffectRemove += AuraEffectRemoveFn(spell_dru_predatory_strikes_AuraScript::UpdateAmount, EFFECT_ALL, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_dru_predatory_strikes_AuraScript();
        }
};

// 1079 - Rip
class spell_dru_rip : public SpellScriptLoader
{
    public:
        spell_dru_rip() : SpellScriptLoader("spell_dru_rip") { }

        class spell_dru_rip_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_rip_AuraScript);

            bool Load() OVERRIDE
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
                    if (AuraEffect const* idol = caster->GetAuraEffect(SPELL_DRUID_IDOL_OF_FERAL_SHADOWS, EFFECT_0))
                        amount += cp * idol->GetAmount();
                    // Idol of Worship. Can't be handled as SpellMod due its dependency from CPs
                    else if (AuraEffect const* idol = caster->GetAuraEffect(SPELL_DRUID_IDOL_OF_WORSHIP, EFFECT_0))
                        amount += cp * idol->GetAmount();

                    amount += int32(CalculatePct(caster->GetTotalAttackPowerValue(BASE_ATTACK), cp));
                }
            }

            void Register() OVERRIDE
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_rip_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_dru_rip_AuraScript();
        }
};

// 62606 - Savage Defense
class spell_dru_savage_defense : public SpellScriptLoader
{
    public:
        spell_dru_savage_defense() : SpellScriptLoader("spell_dru_savage_defense") { }

        class spell_dru_savage_defense_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_savage_defense_AuraScript);

            uint32 absorbPct;

            bool Load() OVERRIDE
            {
                absorbPct = GetSpellInfo()->Effects[EFFECT_0].CalcValue(GetCaster());
                return true;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                // Set absorbtion amount to unlimited
                amount = -1;
            }

            void Absorb(AuraEffect* aurEff, DamageInfo & /*dmgInfo*/, uint32 & absorbAmount)
            {
                absorbAmount = uint32(CalculatePct(GetTarget()->GetTotalAttackPowerValue(BASE_ATTACK), absorbPct));
                aurEff->SetAmount(0);
            }

            void Register() OVERRIDE
            {
                 DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_savage_defense_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
                 OnEffectAbsorb += AuraEffectAbsorbFn(spell_dru_savage_defense_AuraScript::Absorb, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
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

            void Register() OVERRIDE
            {
                OnCheckCast += SpellCheckCastFn(spell_dru_savage_roar_SpellScript::CheckCast);
            }
        };

        class spell_dru_savage_roar_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_savage_roar_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
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

            void Register() OVERRIDE
            {
                AfterEffectApply += AuraEffectApplyFn(spell_dru_savage_roar_AuraScript::AfterApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_dru_savage_roar_AuraScript::AfterRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_dru_savage_roar_SpellScript();
        }

        AuraScript* GetAuraScript() const OVERRIDE
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

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_starfall_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_dru_starfall_aoe_SpellScript();
        }
};

// 50286 - Starfall (Dummy)
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

            void Register() OVERRIDE
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_starfall_dummy_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_dru_starfall_dummy_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_dru_starfall_dummy_SpellScript();
        }
};

// -78892 - Stampede
class spell_dru_stampede : public SpellScriptLoader
{
    public:
        spell_dru_stampede() : SpellScriptLoader("spell_dru_stampede") { }

        class spell_dru_stampede_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_stampede_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_STAMPEDE_BAER_RANK_1) ||
                    !sSpellMgr->GetSpellInfo(SPELL_DRUID_STAMPEDE_CAT_RANK_1) ||
                    !sSpellMgr->GetSpellInfo(SPELL_DRUID_STAMPEDE_CAT_STATE) ||
                    !sSpellMgr->GetSpellInfo(SPELL_DRUID_FERAL_CHARGE_CAT) ||
                    !sSpellMgr->GetSpellInfo(SPELL_DRUID_FERAL_CHARGE_BEAR))
                    return false;
                return true;
            }

            void HandleEffectCatProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                if (GetTarget()->GetShapeshiftForm() != FORM_CAT || eventInfo.GetDamageInfo()->GetSpellInfo()->Id != SPELL_DRUID_FERAL_CHARGE_CAT)
                    return;

                GetTarget()->CastSpell(GetTarget(), sSpellMgr->GetSpellWithRank(SPELL_DRUID_STAMPEDE_CAT_RANK_1, GetSpellInfo()->GetRank()), true, NULL, aurEff);
                GetTarget()->CastSpell(GetTarget(), SPELL_DRUID_STAMPEDE_CAT_STATE, true, NULL, aurEff);
            }

            void HandleEffectBearProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                if (GetTarget()->GetShapeshiftForm() != FORM_BEAR || eventInfo.GetDamageInfo()->GetSpellInfo()->Id != SPELL_DRUID_FERAL_CHARGE_BEAR)
                    return;

                GetTarget()->CastSpell(GetTarget(), sSpellMgr->GetSpellWithRank(SPELL_DRUID_STAMPEDE_BAER_RANK_1, GetSpellInfo()->GetRank()), true, NULL, aurEff);
            }

            void Register() OVERRIDE
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_stampede_AuraScript::HandleEffectCatProc, EFFECT_0, SPELL_AURA_DUMMY);
                OnEffectProc += AuraEffectProcFn(spell_dru_stampede_AuraScript::HandleEffectBearProc, EFFECT_1, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_dru_stampede_AuraScript();
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

            void Register()
            {
                OnCheckCast += SpellCheckCastFn(spell_dru_survival_instincts_SpellScript::CheckCast);
            }
        };

        class spell_dru_survival_instincts_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_survival_instincts_AuraScript);

            bool Validate(SpellInfo const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DRUID_SURVIVAL_INSTINCTS))
                    return false;
                return true;
            }

            void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();	
                target->CastSpell(target, SPELL_DRUID_SURVIVAL_INSTINCTS, true);
            }

            void Register()
            {
                AfterEffectApply += AuraEffectApplyFn(spell_dru_survival_instincts_AuraScript::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_dru_survival_instincts_SpellScript();
        }

        AuraScript* GetAuraScript() const
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

            bool Load() OVERRIDE
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                if (Player* caster = GetCaster()->ToPlayer())
                    if (caster->GetSkillValue(SKILL_RIDING) >= 375)
                        amount = 310;
            }

            void Register() OVERRIDE
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_swift_flight_passive_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_dru_swift_flight_passive_AuraScript();
        }
};

// 5217 - Tiger's Fury
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

            void Register() OVERRIDE
            {
                AfterHit += SpellHitFn(spell_dru_tiger_s_fury_SpellScript::OnHit);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_dru_tiger_s_fury_SpellScript();
        }
};

// 61391 - Typhoon
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

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_dru_typhoon_SpellScript::HandleKnockBack, EFFECT_0, SPELL_EFFECT_KNOCK_BACK);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_dru_typhoon_SpellScript();
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

            bool Load() OVERRIDE
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

            void Register() OVERRIDE
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_t10_restoration_4p_bonus_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_dru_t10_restoration_4p_bonus_SpellScript();
        }
};

// WILD MUSHROOM PARA DREAM WOW 
// Wild mushroom, 88747
class spell_dru_wild_mushroom : public SpellScriptLoader
{
    public:
        spell_dru_wild_mushroom() : SpellScriptLoader("spell_dru_wild_mushroom") { }

        class spell_dru_wild_mushroom_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_wild_mushroom_SpellScript)

            void HandleSummon(SpellEffIndex effIndex)
            {
                if (Player* player = GetCaster()->ToPlayer())
                {
                    if (Unit* gtarget = GetExplTargetUnit())
		      {
                    PreventHitDefaultEffect(effIndex);
                    SpellInfo const* spell = GetSpellInfo();

                    std::list<Creature*> list;
                    player->GetCreatureListWithEntryInGrid(list, SPELL_DRUID_NPC_WILD_MUSHROOM, 40.0f);
                    for (std::list<Creature*>::iterator i = list.begin(); i != list.end(); ++i)
                    {
                        if ((*i)->IsSummon() && (*i)->GetCharmerOrOwner() == player)
                            if (!player)
                                return;
                        continue;

                        list.remove((*i));
                    }

                    // Max 3 Wild Mushroom
                    if ((int32)list.size() >= spell->Effects[0].BasePoints)
                        list.front()->ToTempSummon()->UnSummon();

                    Position pos;
                    gtarget->GetPosition(&pos);
		      const SummonPropertiesEntry* properties = sSummonPropertiesStore.LookupEntry(spell->Effects[effIndex].MiscValueB);
			TempSummon* summon = player->SummonCreature(spell->Effects[0].MiscValue, pos, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 75000);

                    if (!summon)
                        return;

                    summon->SetUInt64Value(UNIT_FIELD_SUMMONEDBY, player->GetGUID());
                    summon->setFaction(player->getFaction());
                    summon->SetUInt32Value(UNIT_CREATED_BY_SPELL, GetSpellInfo()->Id);
                    summon->SetMaxHealth(5);
                    summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                    summon->StopMoving();
		    }
                }
            }

            SpellCastResult CheckCast()
            {
                Player* player = GetCaster()->ToPlayer();
                std::list<Creature*> list;

                player->GetCreatureListWithEntryInGrid(list, SPELL_DRUID_NPC_WILD_MUSHROOM, 90.0f);
                    for (std::list<Creature*>::iterator i = list.begin(); i != list.end(); ++i)
                    {
                        if ((*i)->IsSummon() && (*i)->GetCharmerOrOwner() == player && (*i)->ToTempSummon()->IsAlive())
                            if (!player)
                                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;
                        continue;

                        list.remove((*i));
                    }


		  if ((int32)list.size() >= 3)
		       return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;  

		return SPELL_CAST_OK;
            }

            void Register()
            {
                OnEffectHit += SpellEffectFn(spell_dru_wild_mushroom_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
                OnCheckCast += SpellCheckCastFn(spell_dru_wild_mushroom_SpellScript::CheckCast);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_dru_wild_mushroom_SpellScript();
        }
};

// Wild mushroom : Detonate, 88751
class spell_dru_wild_mushroom_detonate : public SpellScriptLoader
{
    public:
        spell_dru_wild_mushroom_detonate() : SpellScriptLoader("spell_dru_wild_mushroom_detonate") { }

        class spell_dru_wild_mushroom_detonate_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_wild_mushroom_detonate_SpellScript)

            // Globals variables
            float spellRange;
            std::list<TempSummon*> mushroomList;
            std::list<TempSummon*> fungal_List;

            bool Load()
            {
				spellRange = GetSpellInfo()->GetMaxRange();

                Player* player = GetCaster()->ToPlayer();

                if (!player)
                    return false;

                std::list<Creature*> list;
                std::list<TempSummon*> summonList;
                player->GetCreatureListWithEntryInGrid(list, SPELL_DRUID_NPC_WILD_MUSHROOM, 90.0f);

                for (std::list<Creature*>::const_iterator i = list.begin(); i != list.end(); ++i)
                {
                    if ((*i)->IsSummon() && (*i)->GetCharmerOrOwner() == player)
                    {
                        summonList.push_back((*i)->ToTempSummon());
                        continue;
                    }
                }
                mushroomList = summonList;

                if (!spellRange)
                    return false;

                return true;
            }

            SpellCastResult CheckCast()
            {
                Player* player = GetCaster()->ToPlayer();
                if (!player)
                    return SPELL_FAILED_CASTER_DEAD;

                if (mushroomList.empty())
                    return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

                bool inRange = false;

                for (std::list<TempSummon*>::const_iterator i = mushroomList.begin(); i != mushroomList.end(); ++i)
                {
                    Position shroomPos;
                    (*i)->GetPosition(&shroomPos);

                    // Must have at least one mushroom within 40 yards
                    if (player->IsWithinDist3d(&shroomPos, spellRange))
                    {
                        inRange = true;
                        break;
                    }
                }

                if (!inRange)
                {
                    SetCustomCastResultMessage(SPELL_CUSTOM_ERROR_TARGET_TOO_FAR);
                    return SPELL_FAILED_CUSTOM_ERROR;
                }

                return SPELL_CAST_OK;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Player* player = GetCaster()->ToPlayer())
                {
                    uint32 fungal = NULL;
                    uint32 npcfungal = NULL;

                    // Fungal Growth Rank 1
                    if (player->HasAura(SPELL_DRUID_TALENT_FUNGAL_GROWTH_1))
                    {
                        fungal = SPELL_DRUID_SPELL_FUNGAL_GROWTH_1;
                        npcfungal = SPELL_DRUID_NPC_FUNGAL_GROWTH_1;
                    }
                    // Fungal Growth Rank 2
                    else if (player->HasAura(SPELL_DRUID_TALENT_FUNGAL_GROWTH_2))
                    {
                        fungal = SPELL_DRUID_SPELL_FUNGAL_GROWTH_2;
                        npcfungal = SPELL_DRUID_NPC_FUNGAL_GROWTH_2;
                    }
					else
                    {
						// Nothing do
                    }

                    for (std::list<TempSummon*>::const_iterator i = mushroomList.begin(); i != mushroomList.end(); ++i)
                    {
                        Position shroomPos;

                        (*i)->GetPosition(&shroomPos);

                        if (!player->IsWithinDist3d(&shroomPos, spellRange))
                            continue;

                        // Explosion visual and suicide
                        (*i)->CastSpell((*i), SPELL_DRUID_SPELL_WILD_MUSHROOM_SUICIDE, true);

                        // damage
                        player->CastSpell((*i)->GetPositionX(), (*i)->GetPositionY(), (*i)->GetPositionZ(), SPELL_DRUID_SPELL_WILD_MUSHROOM_DAMAGE, true);

                        // Summoning fungal growth
                        if (fungal)
                            player->CastSpell((*i)->GetPositionX(), (*i)->GetPositionY(), (*i)->GetPositionZ(), fungal, true);
                    }

                    // Stop Moving on Fungal Growth
                    std::list<Creature*> fungal_list;
                    std::list<TempSummon*> fungalsummonList;
                    player->GetCreatureListWithEntryInGrid(fungal_list, npcfungal, 90.0f);

                    for (std::list<Creature*>::const_iterator i = fungal_list.begin(); i != fungal_list.end(); ++i)
                    {
                        if ((*i)->IsSummon() && (*i)->GetCharmerOrOwner() == player)
                        {
                            fungalsummonList.push_back((*i)->ToTempSummon());
                            continue;
                        }
                    }
                    fungal_List = fungalsummonList;

                    if (!fungal_List.empty())
                    {
                        for (std::list<TempSummon*>::const_iterator iter = fungal_List.begin(); iter != fungal_List.end(); ++iter)
                        {
                            (*iter)->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                            (*iter)->StopMoving();
                        }
                    }

                    // Cleanup Wild Mushroom
                    std::list<Creature*> list;
                    player->GetCreatureListWithEntryInGrid(list, SPELL_DRUID_NPC_WILD_MUSHROOM, 90.0f);
                    for (std::list<Creature*>::iterator i = list.begin(); i != list.end(); ++i)
                    {
                        if ((*i)->IsSummon() && (*i)->GetCharmerOrOwner() == player)
                            if (!player)
                                return;
                        continue;

                        list.remove((*i));
                    }

                    if ((int32)list.size() > 0)
                   	 for (std::list<Creature*>::iterator i = list.begin(); i != list.end(); ++i)
			 {
                        (*i)->ToTempSummon()->UnSummon();
			   list.front()->ToTempSummon()->UnSummon();
			 }
                }
            }

            void Register() 
            {
                OnCheckCast += SpellCheckCastFn(spell_dru_wild_mushroom_detonate_SpellScript::CheckCast);
                OnEffectHitTarget += SpellEffectFn(spell_dru_wild_mushroom_detonate_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_dru_wild_mushroom_detonate_SpellScript();
        }
};

// Solar Beam DREAM WOW
class spell_dru_beam : public SpellScriptLoader
{
    public:
        spell_dru_beam() : SpellScriptLoader("spell_dru_beam") { }

        class spell_dru_beam_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_beam_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) { return true; }

            void HandleEffectPeriodic(AuraEffect const* aurEff)
            {
                if (DynamicObject* dyn = GetTarget()->GetDynObject(aurEff->GetId()))
                    GetTarget()->CastSpell(dyn->GetPositionX(), dyn->GetPositionY(), dyn->GetPositionZ(), 81261, true);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_dru_beam_AuraScript::HandleEffectPeriodic, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_dru_beam_AuraScript();
        }
};

// Feral aggression para DREAM WOW
class spell_dru_feral_aggression : public SpellScriptLoader
{
    public:
        spell_dru_feral_aggression() : SpellScriptLoader("spell_dru_feral_aggression") { }

        class spell_dru_feral_aggression_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_feral_aggression_SpellScript);

            void OnHitTarget(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                    if (AuraEffect const* feralSwiftness = caster->GetDummyAuraEffect(SPELLFAMILY_DRUID, 960, EFFECT_0))
                    {
                        PreventHitDefaultEffect(effIndex);
                        caster->CastCustomSpell(91565, SPELLVALUE_AURA_STACK, feralSwiftness->GetAmount(), GetHitUnit(), true);
                    }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_dru_feral_aggression_SpellScript::OnHitTarget, EFFECT_0, SPELL_EFFECT_TRIGGER_SPELL);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_dru_feral_aggression_SpellScript();
        }
};

// Rejuvenation DREAM WOW rejuvenacion + don de la madre tierra
class spell_dru_rejuv : public SpellScriptLoader
{
    public:
        spell_dru_rejuv() : SpellScriptLoader("spell_dru_rejuv") { }

        class spell_dru_rejuv_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_rejuv_AuraScript);

            void AfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                {
                    uint32 rejuvCount = 0;
                    Player::appliedAurasList const& auras = caster->ToPlayer()->appliedAuras;

                    if (auras.empty())
                        return;
                    
                    for (Player::appliedAurasList::const_iterator itr = auras.begin(); itr != auras.end(); itr++)
                    {
                        Aura* aura = (*itr);
                        if (aura->GetId() == GetSpellInfo()->Id)
                            rejuvCount++;
                    }
                    if (rejuvCount < 3)
                        caster->RemoveAurasDueToSpell(96206);
                }
            }

            void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                {
                    if (AuraEffect* naturesBounty = caster->GetAuraEffect(SPELL_AURA_ADD_FLAT_MODIFIER, SPELLFAMILY_DRUID, 197, EFFECT_0))
                    {
                        uint32 rejuvCount = 0;
                        Player::appliedAurasList const& auras = caster->ToPlayer()->appliedAuras;
                        for (Player::appliedAurasList::const_iterator itr = auras.begin(); itr != auras.end(); itr++)
                        {
                            Aura* aura = (*itr);
                            if (aura->GetId() == GetSpellInfo()->Id)
                                rejuvCount++;
                        }
                        if (rejuvCount >= 3)
                        {
                            int32 bp0 = -naturesBounty->GetSpellInfo()->Effects[EFFECT_1].BasePoints;
                            caster->CastCustomSpell(caster, 96206, &bp0, NULL, NULL, true);
                        }
                    }

                    // Gift of the earthmother
                    if (AuraEffect* earthMother = caster->GetDummyAuraEffect(SPELLFAMILY_DRUID, 3186, EFFECT_0))
                    {
                        int32 bp0 = caster->SpellHealingBonusDone(GetUnitOwner(), GetSpellInfo(), aurEff->GetAmount(), DOT);
                        bp0 = (bp0 * aurEff->GetTotalTicks()) * (earthMother->GetAmount() / 100.0f);
                        caster->CastCustomSpell(GetUnitOwner(), 64801, &bp0, NULL, NULL, true);
                    }
                }
            }

            void Register()
            {
                AfterEffectApply += AuraEffectApplyFn(spell_dru_rejuv_AuraScript::AfterApply, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_dru_rejuv_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_dru_rejuv_AuraScript();
        }
};

// Empowered touch DREAM WOW toque potenciado
class spell_dru_emp_touch : public SpellScriptLoader
{
    public:
        spell_dru_emp_touch() : SpellScriptLoader("spell_dru_emp_touch") { }

        class spell_dru_emp_touch_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_emp_touch_SpellScript);

            void OnHit()
            {
                if (AuraEffect const* aurEff = GetCaster()->GetDummyAuraEffect(SPELLFAMILY_DRUID, 2251, EFFECT_1))
                    if (roll_chance_i(aurEff->GetAmount()))
                        GetCaster()->CastSpell(GetHitUnit(), 88433, true);
            }

            void Register()
            {
                AfterHit += SpellHitFn(spell_dru_emp_touch_SpellScript::OnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_dru_emp_touch_SpellScript();
        }
};

// Empowered touch DREAM WOW toque potenciado
class spell_dru_emp_touch_triggered : public SpellScriptLoader
{
    public:
        spell_dru_emp_touch_triggered() : SpellScriptLoader("spell_dru_emp_touch_triggered") { }

        class spell_dru_emp_touch_triggered_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_emp_touch_triggered_SpellScript);

            void OnHit()
            {
                if (GetCaster())
                    if (Aura* aura = GetCaster()->GetAura(33763, GetCaster()->GetGUID()))
                        aura->RefreshDuration();
            }

            void Register()
            {
                AfterHit += SpellHitFn(spell_dru_emp_touch_triggered_SpellScript::OnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_dru_emp_touch_triggered_SpellScript();
        }
};

// Efflorescence DREAM WOW floracion 
class spell_dru_efflorescence : public SpellScriptLoader
{
    public:
        spell_dru_efflorescence() : SpellScriptLoader("spell_dru_efflorescence") { }

        class spell_dru_efflorescence_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_efflorescence_AuraScript);

            void HandleEffectPeriodic(AuraEffect const* aurEff)
            {
                if (DynamicObject* dyn = GetTarget()->GetDynObject(aurEff->GetId()))
                    GetTarget()->CastSpell(dyn->GetPositionX(), dyn->GetPositionY(), dyn->GetPositionZ(), 81269, true);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_dru_efflorescence_AuraScript::HandleEffectPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_dru_efflorescence_AuraScript();
        }
};

// Efflorescence heal DREAM WOW floracion
class spell_dru_efflorescence_heal : public SpellScriptLoader
{
    public:
        spell_dru_efflorescence_heal() : SpellScriptLoader("spell_dru_efflorescence_heal") { }

        class spell_dru_efflorescence_heal_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_efflorescence_heal_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                std::list<Unit*> temp;
                for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end(); itr++)
                    if (Unit* unit = (*itr)->ToUnit())
                        temp.push_back(unit);

                targets.clear();
                temp.sort(Trinity::HealthPctOrderPred());
                if (temp.size() > 3)
                    temp.resize(3);                
                for (std::list<Unit*>::iterator itr = temp.begin(); itr != temp.end(); itr++)
                    targets.push_back((WorldObject*)(*itr));
            }

            void HandleHeal(SpellEffIndex /*effIndex*/)
            {
                if (AuraEffect* aurEff = GetCaster()->GetAuraEffect(81262, EFFECT_1, GetCaster()->GetGUID()))
                    SetHitHeal(aurEff->GetAmount());
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_efflorescence_heal_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
                OnEffectHitTarget += SpellEffectFn(spell_dru_efflorescence_heal_SpellScript::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_dru_efflorescence_heal_SpellScript();
        }
};

void AddSC_druid_spell_scripts()
{
    new spell_dru_dash();
    new spell_dru_eclipse("spell_dru_eclipse_lunar");
    new spell_dru_eclipse("spell_dru_eclipse_solar");
    new spell_dru_eclipse_energize();
    new spell_dru_enrage();
    new spell_dru_glyph_of_innervate();
    new spell_dru_glyph_of_starfire();
    new spell_dru_glyph_of_starfire_proc();
    new spell_dru_idol_lifebloom();
    new spell_dru_innervate();
    new spell_dru_insect_swarm();
    new spell_dru_lifebloom();
    new spell_dru_living_seed();
    new spell_dru_living_seed_proc();
    new spell_dru_predatory_strikes();
    new spell_dru_rip();
    new spell_dru_savage_defense();
    new spell_dru_savage_roar();
    new spell_dru_starfall_aoe();
    new spell_dru_starfall_dummy();
    new spell_dru_stampede();
    new spell_dru_survival_instincts();
    new spell_dru_swift_flight_passive();
    new spell_dru_tiger_s_fury();
    new spell_dru_typhoon();
    new spell_dru_t10_restoration_4p_bonus();
    new spell_dru_wild_mushroom();
    new spell_dru_wild_mushroom_detonate();
    new spell_dru_beam();
    new spell_dru_feral_aggression();
    new spell_dru_rejuv();
    new spell_dru_emp_touch();
    new spell_dru_emp_touch_triggered();
    new spell_dru_efflorescence();
    new spell_dru_efflorescence_heal();
	

}
