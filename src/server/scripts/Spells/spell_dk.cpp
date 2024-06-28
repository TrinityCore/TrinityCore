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
 * Scripts for spells with SPELLFAMILY_DEATHKNIGHT and SPELLFAMILY_GENERIC spells used by deathknight players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_dk_".
 */

#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "Unit.h"

enum DeathKnightSpells
{
    SPELL_DK_DARK_SIMULACRUM_BUFF               = 77616,
    SPELL_DK_DARK_SIMULACRUM_SPELLPOWER_BUFF    = 94984
};

// 77606 - Dark Simulacrum
class spell_dk_dark_simulacrum : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_DARK_SIMULACRUM_BUFF, SPELL_DK_DARK_SIMULACRUM_SPELLPOWER_BUFF });
    }

    bool CheckProc(AuraEffect const* /*aurEff*/, ProcEventInfo const& eventInfo) const
    {
        Spell const* procSpell = eventInfo.GetProcSpell();
        if (!procSpell)
            return false;

        if (!GetTarget()->IsPlayer())
            return procSpell->GetSpellInfo()->HasAttribute(SPELL_ATTR9_ALLOW_DARK_SIMULACRUM);

        if (!procSpell->HasPowerTypeCost(POWER_MANA))
            return false;

        // filter out spells not castable by mind controlled players (teleports, summons, item creations (healthstones))
        if (procSpell->GetSpellInfo()->HasAttribute(SPELL_ATTR1_NO_AUTOCAST_AI))
            return false;

        return true;
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo const& eventInfo) const
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(caster, SPELL_DK_DARK_SIMULACRUM_BUFF, CastSpellExtraArgs()
            .SetTriggerFlags(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR)
            .SetTriggeringSpell(eventInfo.GetProcSpell())
            .AddSpellMod(SPELLVALUE_BASE_POINT0, eventInfo.GetSpellInfo()->Id));

        caster->CastSpell(caster, SPELL_DK_DARK_SIMULACRUM_SPELLPOWER_BUFF, CastSpellExtraArgs()
            .SetTriggerFlags(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR)
            .SetTriggeringSpell(eventInfo.GetProcSpell())
            .AddSpellMod(SPELLVALUE_BASE_POINT0, GetTarget()->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC))
            .AddSpellMod(SPELLVALUE_BASE_POINT1, GetTarget()->SpellBaseHealingBonusDone(SPELL_SCHOOL_MASK_MAGIC)));
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_dk_dark_simulacrum::CheckProc, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_dk_dark_simulacrum::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 77616 - Dark Simulacrum
class spell_dk_dark_simulacrum_buff : public AuraScript
{
    bool CheckProc(AuraEffect const* aurEff, ProcEventInfo const& eventInfo) const
    {
        return uint32(aurEff->GetAmount()) == eventInfo.GetSpellInfo()->Id;
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_dk_dark_simulacrum_buff::CheckProc, EFFECT_0, SPELL_AURA_OVERRIDE_ACTIONBAR_SPELLS_TRIGGERED);
    }
};

void AddSC_deathknight_spell_scripts()
{
    RegisterSpellScript(spell_dk_dark_simulacrum);
    RegisterSpellScript(spell_dk_dark_simulacrum_buff);
}
