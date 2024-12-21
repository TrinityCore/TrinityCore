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
 * Scripts for spells with SPELLFAMILY_WARRIOR and SPELLFAMILY_GENERIC spells used by warrior players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_warr_".
 */

#include "ScriptMgr.h"
#include "SpellScript.h"
#include "Unit.h"

namespace Scripts::Spells::Warrior
{
    // 78 - Heroic Strike
    class spell_warr_heroic_strike : public SpellScript
    {
        // Damage = {8+$ap*60/100}
        void CalculateDamage(SpellEffectInfo const& /*spellEffectInfo*/, Unit* /*victim*/, int32& damage, int32& /*flatMod*/, float& /*pctMod*/)
        {
            damage = static_cast<int32>(8 + GetCaster()->GetTotalAttackPowerValue(BASE_ATTACK) * 0.6f);
        }

        void Register() override
        {
            CalcDamage += SpellCalcDamageFn(spell_warr_heroic_strike::CalculateDamage);
        }
    };
}

void AddSC_warrior_spell_scripts()
{
    using namespace Scripts::Spells::Warrior;
    RegisterSpellScript(spell_warr_heroic_strike);
}
