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
 * Scripts for spells with SPELLFAMILY_DEATHKNIGHT and SPELLFAMILY_GENERIC spells used by deathknight players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_dk_".
 */

#include "Player.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "Containers.h"

enum DemonHunterSpells
{
    SPELL_CHAOS_STRIKE_MAINHAND = 199547,
    SPELL_CHAOS_STRIKE_OFFHAND  = 222031,
};

// 197125 - Chaos Strike
class spell_dh_chaos_strike : public SpellScriptLoader
{
public:
    spell_dh_chaos_strike() : SpellScriptLoader("spell_dh_chaos_strike") { }

    class spell_dh_chaos_strike_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dh_chaos_strike_AuraScript);

        void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();

            if (Unit* caster = GetCaster())
                if (eventInfo.GetSpellInfo() && eventInfo.GetHitMask() & PROC_HIT_CRITICAL && (eventInfo.GetSpellInfo()->Id == SPELL_CHAOS_STRIKE_MAINHAND ||
                    eventInfo.GetSpellInfo()->Id == SPELL_CHAOS_STRIKE_OFFHAND))
                    caster->SetPower(POWER_FURY, caster->GetPower(POWER_FURY) + aurEff->GetBaseAmount());
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

void AddSC_demon_hunter_spell_scripts()
{
    new spell_dh_chaos_strike();
}
