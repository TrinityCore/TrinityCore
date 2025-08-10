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

#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "Unit.h"

// 323916 - Sulfuric Emission
class spell_soulbind_sulfuric_emission : public AuraScript
{
    static constexpr uint32 SPELL_SULFURIC_EMISSION_COOLDOWN_AURA = 347684;

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SULFURIC_EMISSION_COOLDOWN_AURA });
    }

    bool CheckProc(AuraEffect const* aurEff, ProcEventInfo& procInfo)
    {
        if (!procInfo.GetProcTarget()->HealthBelowPct(aurEff->GetAmount()))
            return false;

        if (procInfo.GetProcTarget()->HasAura(SPELL_SULFURIC_EMISSION_COOLDOWN_AURA))
            return false;

        return true;
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_soulbind_sulfuric_emission::CheckProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 332753 - Superior Tactics
class spell_soulbind_superior_tactics : public AuraScript
{
    static constexpr uint32 SPELL_SUPERIOR_TACTICS_COOLDOWN_AURA = 332926;

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUPERIOR_TACTICS_COOLDOWN_AURA });
    }

    bool CheckProc(AuraEffect const* /*aurEff*/, ProcEventInfo& procInfo)
    {
        if (GetTarget()->HasAura(SPELL_SUPERIOR_TACTICS_COOLDOWN_AURA))
            return false;

        // only dispels from friendly targets count
        if (procInfo.GetHitMask() & PROC_HIT_DISPEL && !(procInfo.GetTypeMask() & (PROC_FLAG_DEAL_HELPFUL_ABILITY | PROC_FLAG_DEAL_HELPFUL_SPELL | PROC_FLAG_DEAL_HELPFUL_PERIODIC)))
            return false;

        return true;
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_soulbind_superior_tactics::CheckProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

void AddSC_covenant_spell_scripts()
{
    RegisterSpellScript(spell_soulbind_sulfuric_emission);
    RegisterSpellScript(spell_soulbind_superior_tactics);
}
