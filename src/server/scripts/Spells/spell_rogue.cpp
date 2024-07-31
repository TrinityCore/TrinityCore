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
 * Scripts for spells with SPELLFAMILY_ROGUE and SPELLFAMILY_GENERIC spells used by rogue players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_rog_".
 */

#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "Unit.h"

// 2098 - Eviscerate
class spell_rog_eviscerate : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_0 } });
    }

    // Damage: effectValue + (basePoints * Combo) + (AP * 0.091 * Combo)
    void CalculateDamage(Unit* /*victim*/, int32& /*damage*/, int32& flatMod, float& /*pctMod*/) const
    {
        uint32 combo = GetSpell()->m_spentComboPoints;
        flatMod += (GetSpellInfo()->GetEffect(EFFECT_0).BasePoints * combo) + (GetCaster()->GetTotalAttackPowerValue(BASE_ATTACK) * 0.091f * combo);
    }

    void Register() override
    {
        CalcDamage += SpellCalcDamageFn(spell_rog_eviscerate::CalculateDamage);
    }
};

void AddSC_rogue_spell_scripts()
{
    RegisterSpellScript(spell_rog_eviscerate);
}
