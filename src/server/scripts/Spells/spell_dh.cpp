/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
 * Scripts for spells with SPELLFAMILY_DEMONHUNTER and SPELLFAMILY_GENERIC spells used by demonhunter players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_dh_".
 */

#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "ScriptMgr.h"
#include "GridNotifiers.h"
#include "SpellScript.h"
#include "Unit.h"

enum DemonHunterSpells
{
    SPELL_DH_CHAOS_STRIKE_PROC     = 193840,
    SPELL_DH_DEMON_BLADES_PROC     = 203796
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
                return ValidateSpellInfo
                ({
                    SPELL_DH_CHAOS_STRIKE_PROC
                });
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                if (Unit* caster = GetCaster())
                    caster->CastCustomSpell(SPELL_DH_CHAOS_STRIKE_PROC, SPELLVALUE_BASE_POINT0, aurEff->GetBaseAmount(), caster);
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
            return ValidateSpellInfo
            ({
                SPELL_DH_DEMON_BLADES_PROC
            });
        }

        void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
        {
            if (Unit* caster = GetCaster())
                caster->CastCustomSpell(SPELL_DH_DEMON_BLADES_PROC, SPELLVALUE_BASE_POINT0, aurEff->GetBaseAmount(), caster);
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
    new spell_dh_demon_blades();
}