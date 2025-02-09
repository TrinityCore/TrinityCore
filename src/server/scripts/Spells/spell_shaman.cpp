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
 * Scripts for spells with SPELLFAMILY_SHAMAN and SPELLFAMILY_GENERIC spells used by shaman players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_sha_".
 */

#include "ScriptMgr.h"
#include "SpellScript.h"
#include "Unit.h"

namespace Scripts::Spells::Shaman
{
    // 51505 - Lava Burst
    class spell_sha_lava_burst : public SpellScript
    {
        void CalcCritChance(Unit const* victim, float& critChance)
        {
            // The crit chance against targets effected by the caster's Flame Shock spell is 100%
            if (victim->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_SHAMAN, flag128(0x10000000), GetCaster()->GetGUID()))
                critChance = 100.0f;
        }

        void Register() override
        {
            OnCalcCritChance += SpellOnCalcCritChanceFn(spell_sha_lava_burst::CalcCritChance);
        }
    };
}

void AddSC_shaman_spell_scripts()
{
    using namespace Scripts::Spells::Shaman;
    RegisterSpellScript(spell_sha_lava_burst);
}
