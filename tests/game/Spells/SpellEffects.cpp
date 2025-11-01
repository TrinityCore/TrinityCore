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

#include "tc_catch2.h"
#include "Spell.h"
#include "Unit.h"

// Mock Unit class for testing
class MockUnit : public Unit
{
public:
    MockUnit() : Unit() { }
    bool IsInWorld() const override { return true; }
    void GetPosition(float&, float&, float&, float&) const override { }
};

TEST_CASE("SpellEffect_PowerBurn", "[game][spells]")
{
    // 1. Setup
    MockUnit caster;
    MockUnit target;

    // Set initial power for the target
    target.SetMaxPower(POWER_MANA, 1000);
    target.SetPower(POWER_MANA, 500);

    // Create a mock spell info
    SpellInfo spellInfo;
    spellInfo.Effects[0].Effect = SPELL_EFFECT_POWER_BURN;
    spellInfo.Effects[0].BasePoints = 100; // Power burn amount
    spellInfo.Effects[0].DamageMultiplier = 2.0f; // Damage multiplier
    spellInfo.Effects[0].ValueMultiplier = 0.5f; // Value multiplier (should not be used)

    // Create a mock spell
    Spell spell(&caster, &spellInfo, TRIGGERED_NONE);
    spell.unitTarget = &target;
    spell.damage = spellInfo.Effects[0].BasePoints;
    spell.effectInfo = &spellInfo.Effects[0];
    spell.effectHandleMode = SPELL_EFFECT_HANDLE_HIT_TARGET;

    // 2. Execution
    spell.EffectPowerBurn();

    // 3. Assertion
    // The bug is that EffectPowerBurn uses ValueMultiplier instead of DamageMultiplier.
    // Correct behavior: 500 - (100 * 2.0) = 300
    // Buggy behavior: 500 - (100 * 0.5) = 450
    REQUIRE(target.GetPower(POWER_MANA) == 300);
}