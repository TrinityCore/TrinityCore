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
#include "SpellScript.h"
#include "Unit.h"

/*######
## Quest 5206: Marauders of Darrowshire
######*/

enum MaraudersOfDarrowshire
{
    SPELL_CREATE_RESONATING_SKULL   = 17269,
    SPELL_CREATE_BONE_DUST          = 17270
};

// 17271 - Test Fetid Skull
class spell_eastern_plaguelands_test_fetid_skull : public SpellScript
{
    PrepareSpellScript(spell_eastern_plaguelands_test_fetid_skull);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CREATE_RESONATING_SKULL, SPELL_CREATE_BONE_DUST });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), roll_chance_i(50) ? SPELL_CREATE_RESONATING_SKULL : SPELL_CREATE_BONE_DUST, TRIGGERED_IGNORE_POWER_AND_REAGENT_COST);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_eastern_plaguelands_test_fetid_skull::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_eastern_plaguelands()
{
    RegisterSpellScript(spell_eastern_plaguelands_test_fetid_skull);
}
