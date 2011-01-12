/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
 * Scripts for spells with SPELLFAMILY_MAGE and SPELLFAMILY_GENERIC spells used by mage players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_mage_".
 */

#include "ScriptPCH.h"

enum MageSpells
{
    SPELL_MAGE_COLD_SNAP                         = 11958,
    SPELL_MAGE_SQUIRREL_FORM                     = 32813,
    SPELL_MAGE_GIRAFFE_FORM                      = 32816,
    SPELL_MAGE_SERPENT_FORM                      = 32817,
    SPELL_MAGE_DRAGONHAWK_FORM                   = 32818,
    SPELL_MAGE_WORGEN_FORM                       = 32819,
    SPELL_MAGE_SHEEP_FORM                        = 32820,
    SPELL_MAGE_GLYPH_OF_ETERNAL_WATER            = 70937,
    SPELL_MAGE_SUMMON_WATER_ELEMENTAL_PERMANENT  = 70908,
    SPELL_MAGE_SUMMON_WATER_ELEMENTAL_TEMPORARY  = 70907,
    SPELL_MAGE_GLYPH_OF_BLAST_WAVE               = 62126,
};

class spell_mage_blast_wave : public SpellScriptLoader
{
    public:
        spell_mage_blast_wave() : SpellScriptLoader("spell_mage_blast_wave") { }

        class spell_mage_blast_wave_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mage_blast_wave_SpellScript)
            bool Validate(SpellEntry const * /*spellEntry*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_MAGE_GLYPH_OF_BLAST_WAVE))
                    return false;
                return true;
            }

            void HandleKnockBack(SpellEffIndex effIndex)
            {
                if (GetCaster()->HasAura(SPELL_MAGE_GLYPH_OF_BLAST_WAVE))
                    PreventHitDefaultEffect(effIndex);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_mage_blast_wave_SpellScript::HandleKnockBack, EFFECT_2, SPELL_EFFECT_KNOCK_BACK);
            }
        };

        SpellScript * GetSpellScript() const
        {
            return new spell_mage_blast_wave_SpellScript();
        }
};

class spell_mage_cold_snap : public SpellScriptLoader
{
    public:
        spell_mage_cold_snap() : SpellScriptLoader("spell_mage_cold_snap") { }

        class spell_mage_cold_snap_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mage_cold_snap_SpellScript)
            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit *caster = GetCaster();

                if (caster->GetTypeId() != TYPEID_PLAYER)
                    return;

                // immediately finishes the cooldown on Frost spells
                const SpellCooldowns& cm = caster->ToPlayer()->GetSpellCooldownMap();
                for (SpellCooldowns::const_iterator itr = cm.begin(); itr != cm.end();)
                {
                    SpellEntry const *spellInfo = sSpellStore.LookupEntry(itr->first);

                    if (spellInfo->SpellFamilyName == SPELLFAMILY_MAGE &&
                        (GetSpellSchoolMask(spellInfo) & SPELL_SCHOOL_MASK_FROST) &&
                        spellInfo->Id != SPELL_MAGE_COLD_SNAP && GetSpellRecoveryTime(spellInfo) > 0)
                    {
                        caster->ToPlayer()->RemoveSpellCooldown((itr++)->first, true);
                    }
                    else
                        ++itr;
                }
            }

            void Register()
            {
                // add dummy effect spell handler to Cold Snap
                OnEffect += SpellEffectFn(spell_mage_cold_snap_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_mage_cold_snap_SpellScript();
        }
};

class spell_mage_polymorph_cast_visual : public SpellScriptLoader
{
    public:
        spell_mage_polymorph_cast_visual() : SpellScriptLoader("spell_mage_polymorph_visual") { }

        class spell_mage_polymorph_cast_visual_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mage_polymorph_cast_visual_SpellScript)
            static const uint32 spell_list[6];

            bool Validate(SpellEntry const * /*spellEntry*/)
            {
                // check if spell ids exist in dbc
                for (int i = 0; i < 6; i++)
                    if (!sSpellStore.LookupEntry(spell_list[i]))
                        return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Unit *unitTarget = GetHitUnit())
                    if (unitTarget->GetTypeId() == TYPEID_UNIT)
                        unitTarget->CastSpell(unitTarget, spell_list[urand(0, 5)], true);
            }

            void Register()
            {
                // add dummy effect spell handler to Polymorph visual
                OnEffect += SpellEffectFn(spell_mage_polymorph_cast_visual_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_mage_polymorph_cast_visual_SpellScript();
        }
};

const uint32 spell_mage_polymorph_cast_visual::spell_mage_polymorph_cast_visual_SpellScript::spell_list[6] =
{
    SPELL_MAGE_SQUIRREL_FORM,
    SPELL_MAGE_GIRAFFE_FORM,
    SPELL_MAGE_SERPENT_FORM,
    SPELL_MAGE_DRAGONHAWK_FORM,
    SPELL_MAGE_WORGEN_FORM,
    SPELL_MAGE_SHEEP_FORM
};

class spell_mage_summon_water_elemental : public SpellScriptLoader
{
    public:
        spell_mage_summon_water_elemental() : SpellScriptLoader("spell_mage_summon_water_elemental") { }

        class spell_mage_summon_water_elemental_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mage_summon_water_elemental_SpellScript)
            bool Validate(SpellEntry const * /*spellEntry*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_MAGE_GLYPH_OF_ETERNAL_WATER))
                    return false;
                if (!sSpellStore.LookupEntry(SPELL_MAGE_SUMMON_WATER_ELEMENTAL_TEMPORARY))
                    return false;
                if (!sSpellStore.LookupEntry(SPELL_MAGE_SUMMON_WATER_ELEMENTAL_PERMANENT))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Unit *unitTarget = GetHitUnit())
                {
                    // Glyph of Eternal Water
                    if (unitTarget->HasAura(SPELL_MAGE_GLYPH_OF_ETERNAL_WATER))
                        unitTarget->CastSpell(unitTarget, SPELL_MAGE_SUMMON_WATER_ELEMENTAL_PERMANENT, true);
                    else
                        unitTarget->CastSpell(unitTarget, SPELL_MAGE_SUMMON_WATER_ELEMENTAL_TEMPORARY, true);
                }
            }

            void Register()
            {
                // add dummy effect spell handler to Summon Water Elemental
                OnEffect += SpellEffectFn(spell_mage_summon_water_elemental_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript * GetSpellScript() const
        {
            return new spell_mage_summon_water_elemental_SpellScript();
        }
};

// Frost Warding
class spell_mage_frost_warding_trigger : public SpellScriptLoader
{
public:
    spell_mage_frost_warding_trigger() : SpellScriptLoader("spell_mage_frost_warding_trigger") { }

    class spell_mage_frost_warding_trigger_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_frost_warding_trigger_AuraScript);

        enum Spells
        {
            SPELL_MAGE_FROST_WARDING_TRIGGERED = 57776,
            SPELL_MAGE_FROST_WARDING_R1 = 28332,
        };

        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            return sSpellStore.LookupEntry(SPELL_MAGE_FROST_WARDING_TRIGGERED) 
                && sSpellStore.LookupEntry(SPELL_MAGE_FROST_WARDING_R1);
        }

        void Absorb(AuraEffect * aurEff, DamageInfo & dmgInfo, uint32 & absorbAmount)
        {
            Unit * target = GetTarget();
            if (AuraEffect * talentAurEff = target->GetAuraEffectOfRankedSpell(SPELL_MAGE_FROST_WARDING_R1, EFFECT_0))
            {
                int32 chance = SpellMgr::CalculateSpellEffectAmount(talentAurEff->GetSpellProto(), EFFECT_1);

                if (roll_chance_i(chance))
                {
                    absorbAmount = dmgInfo.GetDamage();
                    int32 bp = absorbAmount;
                    target->CastCustomSpell(target, SPELL_MAGE_FROST_WARDING_TRIGGERED, &bp, NULL, NULL, true, NULL, aurEff);
                }
            }
        }

        void Register()
        {
             OnEffectAbsorb += AuraEffectAbsorbFn(spell_mage_frost_warding_trigger_AuraScript::Absorb, EFFECT_0);
        }
    };

    AuraScript *GetAuraScript() const
    {
        return new spell_mage_frost_warding_trigger_AuraScript();
    }
};

// Incanter's Absorption
class spell_mage_incanters_absorbtion_absorb : public SpellScriptLoader
{
public:
    spell_mage_incanters_absorbtion_absorb() : SpellScriptLoader("spell_mage_incanters_absorbtion_absorb") { }

    class spell_mage_incanters_absorbtion_absorb_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_incanters_absorbtion_absorb_AuraScript);

        enum Spells
        {
            SPELL_MAGE_INCANTERS_ABSORBTION_TRIGGERED = 44413,
            SPELL_MAGE_INCANTERS_ABSORBTION_R1 = 44394,
        };

        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            return sSpellStore.LookupEntry(SPELL_MAGE_INCANTERS_ABSORBTION_TRIGGERED) 
                && sSpellStore.LookupEntry(SPELL_MAGE_INCANTERS_ABSORBTION_R1);
        }

        void Trigger(AuraEffect * aurEff, DamageInfo & /*dmgInfo*/, uint32 & absorbAmount)
        {
            Unit * target = GetTarget();

            if (AuraEffect * talentAurEff = target->GetAuraEffectOfRankedSpell(SPELL_MAGE_INCANTERS_ABSORBTION_R1, EFFECT_0))
            {
                int32 bp = CalculatePctN(absorbAmount, talentAurEff->GetAmount());
                target->CastCustomSpell(target, SPELL_MAGE_INCANTERS_ABSORBTION_TRIGGERED, &bp, NULL, NULL, true, NULL, aurEff);
            }
        }

        void Register()
        {
             AfterEffectAbsorb += AuraEffectAbsorbFn(spell_mage_incanters_absorbtion_absorb_AuraScript::Trigger, EFFECT_0);
        }
    };

    AuraScript *GetAuraScript() const
    {
        return new spell_mage_incanters_absorbtion_absorb_AuraScript();
    }
};

// Incanter's Absorption
class spell_mage_incanters_absorbtion_manashield : public SpellScriptLoader
{
public:
    spell_mage_incanters_absorbtion_manashield() : SpellScriptLoader("spell_mage_incanters_absorbtion_manashield") { }

    class spell_mage_incanters_absorbtion_manashield_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_incanters_absorbtion_manashield_AuraScript);

        enum Spells
        {
            SPELL_MAGE_INCANTERS_ABSORBTION_TRIGGERED = 44413,
            SPELL_MAGE_INCANTERS_ABSORBTION_R1 = 44394,
        };

        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            return sSpellStore.LookupEntry(SPELL_MAGE_INCANTERS_ABSORBTION_TRIGGERED) 
                && sSpellStore.LookupEntry(SPELL_MAGE_INCANTERS_ABSORBTION_R1);
        }

        void Trigger(AuraEffect * aurEff, DamageInfo & /*dmgInfo*/, uint32 & absorbAmount)
        {
            Unit * target = GetTarget();

            if (AuraEffect * talentAurEff = target->GetAuraEffectOfRankedSpell(SPELL_MAGE_INCANTERS_ABSORBTION_R1, EFFECT_0))
            {
                int32 bp = CalculatePctN(absorbAmount, talentAurEff->GetAmount());
                target->CastCustomSpell(target, SPELL_MAGE_INCANTERS_ABSORBTION_TRIGGERED, &bp, NULL, NULL, true, NULL, aurEff);
            }
        }

        void Register()
        {
             AfterEffectManaShield += AuraEffectManaShieldFn(spell_mage_incanters_absorbtion_manashield_AuraScript::Trigger, EFFECT_0);
        }
    };

    AuraScript *GetAuraScript() const
    {
        return new spell_mage_incanters_absorbtion_manashield_AuraScript();
    }
};

void AddSC_mage_spell_scripts()
{
    new spell_mage_blast_wave;
    new spell_mage_cold_snap;
    new spell_mage_frost_warding_trigger();
    new spell_mage_incanters_absorbtion_absorb();
    new spell_mage_incanters_absorbtion_manashield();
    new spell_mage_polymorph_cast_visual;
    new spell_mage_summon_water_elemental;
}
