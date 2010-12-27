/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
 * Scripts for spells with SPELLFAMILY_DEATHKNIGHT and SPELLFAMILY_GENERIC spells used by deathknight players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_dk_".
 */

#include "ScriptPCH.h"
#include "Spell.h"

enum DeathKnightSpells
{
    DK_SPELL_SUMMON_GARGOYLE                = 50514,
    DK_SPELL_CORPSE_EXPLOSION_TRIGGERED     = 43999,
    DISPLAY_GHOUL_CORPSE                    = 25537,
    DK_SPELL_SCOURGE_STRIKE_TRIGGERED       = 70890,
};

// 49158 Corpse Explosion (51325, 51326, 51327, 51328)
class spell_dk_corpse_explosion : public SpellScriptLoader
{
public:
    spell_dk_corpse_explosion() : SpellScriptLoader("spell_dk_corpse_explosion") { }

    class spell_dk_corpse_explosion_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dk_corpse_explosion_SpellScript)
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(DK_SPELL_CORPSE_EXPLOSION_TRIGGERED))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* unitTarget = GetHitUnit())
            {
                int32 bp = 0;
                // Living ghoul as a target
                if (unitTarget->isAlive())
                    bp = int32(unitTarget->CountPctFromMaxHealth(25));
                // Some corpse
                else
                    bp = GetEffectValue();
                GetCaster()->CastCustomSpell(unitTarget, SpellMgr::CalculateSpellEffectAmount(GetSpellInfo(), 1), &bp, NULL, NULL, true);
                // Corpse Explosion (Suicide)
                unitTarget->CastCustomSpell(unitTarget, DK_SPELL_CORPSE_EXPLOSION_TRIGGERED, &bp, NULL, NULL, true);
                // Set corpse look
                unitTarget->SetDisplayId(DISPLAY_GHOUL_CORPSE + urand(0, 3));
            }
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_dk_corpse_explosion_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_dk_corpse_explosion_SpellScript();
    }
};

// 50524 Runic Power Feed (keeping Gargoyle alive)
class spell_dk_runic_power_feed : public SpellScriptLoader
{
public:
    spell_dk_runic_power_feed() : SpellScriptLoader("spell_dk_runic_power_feed") { }

    class spell_dk_runic_power_feed_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dk_runic_power_feed_SpellScript)
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(DK_SPELL_SUMMON_GARGOYLE))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                // No power, dismiss Gargoyle
                if (caster->GetPower(POWER_RUNIC_POWER) < 30)
                    caster->RemoveAurasDueToSpell(DK_SPELL_SUMMON_GARGOYLE, caster->GetGUID());
                else
                    caster->ModifyPower(POWER_RUNIC_POWER, -30);
            }
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_dk_runic_power_feed_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_dk_runic_power_feed_SpellScript();
    }
};

// 55090 Scourge Strike (55265, 55270, 55271)
class spell_dk_scourge_strike : public SpellScriptLoader
{
public:
    spell_dk_scourge_strike() : SpellScriptLoader("spell_dk_scourge_strike") { }

    class spell_dk_scourge_strike_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dk_scourge_strike_SpellScript)
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(DK_SPELL_SCOURGE_STRIKE_TRIGGERED))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (Unit* unitTarget = GetHitUnit())
            {
                int32 bp = CalculatePctN(GetHitDamage(), GetEffectValue() * unitTarget->GetDiseasesByCaster(caster->GetGUID()));
                caster->CastCustomSpell(unitTarget, DK_SPELL_SCOURGE_STRIKE_TRIGGERED, &bp, NULL, NULL, true);
            }
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_dk_scourge_strike_SpellScript::HandleDummy, EFFECT_2, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_dk_scourge_strike_SpellScript();
    }
};

// 49145 - Spell Deflection
class spell_dk_spell_deflection : public SpellScriptLoader
{
public:
    spell_dk_spell_deflection() : SpellScriptLoader("spell_dk_spell_deflection") { }

    class spell_dk_spell_deflection_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dk_spell_deflection_AuraScript);

        uint32 absorbPct;
        void CalculateAmount(AuraEffect const * /*aurEff*/, int32 & amount, bool & canBeRecalculated)
        {
            absorbPct = amount;
            // Set absorbtion amount to unlimited
            amount = -1;
        }

        void Absorb(AuraEffect * /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
        {
            // You have a chance equal to your Parry chance
            if ((dmgInfo.GetDamageType() == DIRECT_DAMAGE) && roll_chance_f(GetTarget()->GetUnitParryChance()))
                absorbAmount = CalculatePctN(dmgInfo.GetDamage(), absorbPct);
        }

        void Register()
        {
             DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_spell_deflection_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
             OnEffectAbsorb += AuraEffectAbsorbFn(spell_dk_spell_deflection_AuraScript::Absorb, EFFECT_0);
        }
    };

    AuraScript *GetAuraScript() const
    {
        return new spell_dk_spell_deflection_AuraScript();
    }
};


void AddSC_deathknight_spell_scripts()
{
    new spell_dk_corpse_explosion();
    new spell_dk_runic_power_feed();
    new spell_dk_scourge_strike();
    new spell_dk_spell_deflection();
}
