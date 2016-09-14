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
 * Scripts for spells with SPELLFAMILY_DEMONHUNTER and SPELLFAMILY_GENERIC spells used by demon hunter players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_dh_".
 */

#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "ScriptMgr.h"
#include "GridNotifiers.h"



enum DemonHunterSpells
{
    SPELL_FEL_RUSH_GROUND   = 197922,
    SPELL_FEL_RUSH_AIR      = 197923,
    SPELL_FEL_RUSH_DAMAGE   = 192611,

    SPELL_CHAOS_STRIKE_PROC = 193840,
    SPELL_DEMON_BLADES_PROC = 203796
};

// 197125 - Chaos Strike
class spell_dh_chaos_strike : public SpellScriptLoader
{
    public:
        spell_dh_chaos_strike() : SpellScriptLoader("spell_dh_chaos_strike") { }

        class spell_dh_chaos_strike_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dh_chaos_strike_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_CHAOS_STRIKE_PROC))
                    return false;
                return true;
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                if (Unit* caster = GetCaster())
                    caster->CastCustomSpell(SPELL_CHAOS_STRIKE_PROC, SPELLVALUE_BASE_POINT0, aurEff->GetBaseAmount(), caster);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dh_chaos_strike_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };
        AuraScript* GetAuraScript() const override
        {
            return new spell_dh_chaos_strike_AuraScript();
        }
};

// 195072 - Fel Rush
class spell_dh_fel_rush : public SpellScriptLoader
{
    public:
        spell_dh_fel_rush() : SpellScriptLoader("spell_dh_fel_rush") { }

        class spell_dh_fel_rush_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dh_fel_rush_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_FEL_RUSH_GROUND))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_FEL_RUSH_AIR))
                    return false;
                return true;
            }

            void HandleDashGround(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                    if (!caster->IsFalling() || caster->IsInWater())
                    {
                        caster->CastSpell(caster, SPELL_FEL_RUSH_GROUND, true);
                        caster->CastSpell(caster, SPELL_FEL_RUSH_DAMAGE, true);
                    }
            }

            void HandleDashAir(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                    if (caster->IsFalling())
                    {
                        caster->SetDisableGravity(true);
                        caster->CastSpell(caster, SPELL_FEL_RUSH_AIR, true);
                        caster->CastSpell(caster, SPELL_FEL_RUSH_DAMAGE, true);
                    }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dh_fel_rush_SpellScript::HandleDashGround, EFFECT_0, SPELL_EFFECT_DUMMY);
                OnEffectHitTarget += SpellEffectFn(spell_dh_fel_rush_SpellScript::HandleDashAir, EFFECT_1, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dh_fel_rush_SpellScript();
        }
};

// 197923 - Fel Rush (air cast)
class spell_dh_fel_rush_aura : public SpellScriptLoader
{
    public:
        spell_dh_fel_rush_aura() : SpellScriptLoader("spell_dh_fel_rush_aura") { }

        class spell_dh_fel_rush_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dh_fel_rush_aura_AuraScript);

            void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    caster->SetDisableGravity(false);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_dh_fel_rush_aura_AuraScript::AfterRemove, EFFECT_7, SPELL_AURA_MECHANIC_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
            }
        };
        AuraScript* GetAuraScript() const override
        {
            return new spell_dh_fel_rush_aura_AuraScript();
        }
};

// 203555 - Demon Blades
class spell_dh_demon_blades : public SpellScriptLoader
{
public:
    spell_dh_demon_blades() : SpellScriptLoader("spell_dh_demon_blades") { }

    class spell_dh_demon_blades_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_demon_blades_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_DEMON_BLADES_PROC))
                return false;
            return true;
        }

        void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            if (Unit* caster = GetCaster())
                caster->CastSpell(caster->GetVictim(), SPELL_DEMON_BLADES_PROC, true);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_dh_demon_blades_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };
    AuraScript* GetAuraScript() const override
    {
        return new spell_dh_demon_blades_AuraScript();
    }
};

void AddSC_demon_hunter_spell_scripts()
{
    new spell_dh_chaos_strike();
    new spell_dh_fel_rush();
    new spell_dh_fel_rush_aura();
    new spell_dh_demon_blades();
}
