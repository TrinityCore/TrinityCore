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
 * Scripts for spells with SPELLFAMILY_ROGUE and SPELLFAMILY_GENERIC spells used by rogue players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_rog_".
 */

#include "ScriptPCH.h"

enum RogueSpells
{
    ROGUE_SPELL_SHIV_TRIGGERED                   = 5940,
    ROGUE_SPELL_GLYPH_OF_PREPARATION             = 56819,
    ROGUE_SPELL_PREY_ON_THE_WEAK                 = 58670,
};

// Cheat Death
class spell_rog_cheat_death : public SpellScriptLoader
{
public:
    spell_rog_cheat_death() : SpellScriptLoader("spell_rog_cheat_death") { }

    class spell_rog_cheat_death_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rog_cheat_death_AuraScript);

        uint32 absorbChance;

        enum Spell
        {
            ROG_SPELL_CHEAT_DEATH_COOLDOWN = 31231,
        };

        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            return sSpellStore.LookupEntry(ROG_SPELL_CHEAT_DEATH_COOLDOWN);
        }

        bool Load()
        {
            absorbChance = SpellMgr::CalculateSpellEffectAmount(GetSpellProto(), EFFECT_0);
            return GetUnitOwner()->ToPlayer();
        }

        void CalculateAmount(AuraEffect const * /*aurEff*/, int32 & amount, bool & canBeRecalculated)
        {
            // Set absorbtion amount to unlimited
            amount = -1;
        }

        void Absorb(AuraEffect * aurEff, DamageInfo & dmgInfo, uint32 & absorbAmount)
        {
            Unit * target = GetTarget();
            if (dmgInfo.GetDamage() < target->GetHealth())
                return;
            if (target->ToPlayer()->HasSpellCooldown(ROG_SPELL_CHEAT_DEATH_COOLDOWN))
                return;
            if (!roll_chance_i(absorbChance))
                return;

            target->CastSpell(target, ROG_SPELL_CHEAT_DEATH_COOLDOWN, true);
            target->ToPlayer()->AddSpellCooldown(ROG_SPELL_CHEAT_DEATH_COOLDOWN, 0, time(NULL) + 60);

            uint32 health10 = target->CountPctFromMaxHealth(10);

            // hp > 10% - absorb hp till 10%
            if (target->GetHealth() > health10)
                absorbAmount = dmgInfo.GetDamage() - target->GetHealth() + health10;
            // hp lower than 10% - absorb everything
            else
                absorbAmount = dmgInfo.GetDamage();
        }

        void Register()
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_rog_cheat_death_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_rog_cheat_death_AuraScript::Absorb, EFFECT_0);
        }
    };

    AuraScript *GetAuraScript() const
    {
        return new spell_rog_cheat_death_AuraScript();
    }
};

// 31130 - Nerves of Steel
class spell_rog_nerves_of_steel : public SpellScriptLoader
{
public:
    spell_rog_nerves_of_steel() : SpellScriptLoader("spell_rog_nerves_of_steel") { }

    class spell_rog_nerves_of_steel_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rog_nerves_of_steel_AuraScript);

        uint32 absorbPct;

        bool Load()
        {
            absorbPct = SpellMgr::CalculateSpellEffectAmount(GetSpellProto(), EFFECT_0, GetCaster());
            return true;
        }

        void CalculateAmount(AuraEffect const * /*aurEff*/, int32 & amount, bool & canBeRecalculated)
        {
            // Set absorbtion amount to unlimited
            amount = -1;
        }

        void Absorb(AuraEffect * /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
        {
            // reduces all damage taken while stun or fear
            if (GetTarget()->GetUInt32Value(UNIT_FIELD_FLAGS) & (UNIT_FLAG_STUNNED | UNIT_FLAG_FLEEING))
                absorbAmount = CalculatePctN(dmgInfo.GetDamage(), absorbPct);
        }

        void Register()
        {
             DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_rog_nerves_of_steel_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
             OnEffectAbsorb += AuraEffectAbsorbFn(spell_rog_nerves_of_steel_AuraScript::Absorb, EFFECT_0);
        }
    };

    AuraScript *GetAuraScript() const
    {
        return new spell_rog_nerves_of_steel_AuraScript();
    }
};

class spell_rog_preparation : public SpellScriptLoader
{
    public:
        spell_rog_preparation() : SpellScriptLoader("spell_rog_preparation") { }

        class spell_rog_preparation_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_rog_preparation_SpellScript)
            bool Validate(SpellEntry const * /*spellEntry*/)
            {
                if (!sSpellStore.LookupEntry(ROGUE_SPELL_GLYPH_OF_PREPARATION))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit *caster = GetCaster();
                if (caster->GetTypeId() != TYPEID_PLAYER)
                    return;

                //immediately finishes the cooldown on certain Rogue abilities
                const SpellCooldowns& cm = caster->ToPlayer()->GetSpellCooldownMap();
                for (SpellCooldowns::const_iterator itr = cm.begin(); itr != cm.end();)
                {
                    SpellEntry const *spellInfo = sSpellStore.LookupEntry(itr->first);

                    if (spellInfo->SpellFamilyName == SPELLFAMILY_ROGUE)
                    {
                        if (spellInfo->SpellFamilyFlags[1] & SPELLFAMILYFLAG1_ROGUE_COLDB_SHADOWSTEP ||      // Cold Blood, Shadowstep
                            spellInfo->SpellFamilyFlags[0] & SPELLFAMILYFLAG_ROGUE_VAN_EVAS_SPRINT)           // Vanish, Evasion, Sprint
                            caster->ToPlayer()->RemoveSpellCooldown((itr++)->first, true);
                        else if (caster->HasAura(ROGUE_SPELL_GLYPH_OF_PREPARATION))
                        {
                            if (spellInfo->SpellFamilyFlags[1] & SPELLFAMILYFLAG1_ROGUE_DISMANTLE ||         // Dismantle
                                spellInfo->SpellFamilyFlags[0] & SPELLFAMILYFLAG_ROGUE_KICK ||               // Kick
                                (spellInfo->SpellFamilyFlags[0] & SPELLFAMILYFLAG_ROGUE_BLADE_FLURRY &&     // Blade Flurry
                                spellInfo->SpellFamilyFlags[1] & SPELLFAMILYFLAG1_ROGUE_BLADE_FLURRY))
                                caster->ToPlayer()->RemoveSpellCooldown((itr++)->first, true);
                            else
                                ++itr;
                        }
                        else
                            ++itr;
                    }
                    else
                        ++itr;
                }
            }

            void Register()
            {
                // add dummy effect spell handler to Preparation
                OnEffect += SpellEffectFn(spell_rog_preparation_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript *GetSpellScript() const
        {
            return new spell_rog_preparation_SpellScript();
        }
};

// 51685-51689 Prey on the Weak
class spell_rog_prey_on_the_weak : public SpellScriptLoader
{
public:
    spell_rog_prey_on_the_weak() : SpellScriptLoader("spell_rog_prey_on_the_weak") { }

    class spell_rog_prey_on_the_weak_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rog_prey_on_the_weak_AuraScript)
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(ROGUE_SPELL_PREY_ON_THE_WEAK))
                return false;
            return true;
        }

        void HandleEffectPeriodic(AuraEffect const * /*aurEff*/)
        {
            Unit* pTarget = GetTarget();
            Unit* pVictim = pTarget->getVictim();
            if (pVictim && (pTarget->GetHealthPct() > pVictim->GetHealthPct()))
            {
                if (!pTarget->HasAura(ROGUE_SPELL_PREY_ON_THE_WEAK))
                {
                    int32 bp = SpellMgr::CalculateSpellEffectAmount(GetSpellProto(), 0);
                    pTarget->CastCustomSpell(pTarget, ROGUE_SPELL_PREY_ON_THE_WEAK, &bp, 0, 0, true);
                }
            }
            else
                pTarget->RemoveAurasDueToSpell(ROGUE_SPELL_PREY_ON_THE_WEAK);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_rog_prey_on_the_weak_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript *GetAuraScript() const
    {
        return new spell_rog_prey_on_the_weak_AuraScript();
    }
};


class spell_rog_shiv : public SpellScriptLoader
{
    public:
        spell_rog_shiv() : SpellScriptLoader("spell_rog_shiv") { }

        class spell_rog_shiv_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_rog_shiv_SpellScript)
            bool Validate(SpellEntry const * /*spellEntry*/)
            {
                if (!sSpellStore.LookupEntry(ROGUE_SPELL_SHIV_TRIGGERED))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit *caster = GetCaster();
                if (caster->GetTypeId() != TYPEID_PLAYER)
                    return;

                if (Unit *unitTarget = GetHitUnit())
                    caster->CastSpell(unitTarget, ROGUE_SPELL_SHIV_TRIGGERED, true);
            }

            void Register()
            {
                // add dummy effect spell handler to Shiv
                OnEffect += SpellEffectFn(spell_rog_shiv_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript *GetSpellScript() const
        {
            return new spell_rog_shiv_SpellScript();
        }
};

void AddSC_rogue_spell_scripts()
{
    new spell_rog_cheat_death();
    new spell_rog_nerves_of_steel();
    new spell_rog_preparation();
    new spell_rog_prey_on_the_weak();
    new spell_rog_shiv();
}
