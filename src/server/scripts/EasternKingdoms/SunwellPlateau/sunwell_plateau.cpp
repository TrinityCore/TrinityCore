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
#include "Containers.h"
#include "SpellScript.h"
#include "Unit.h"
#include "sunwell_plateau.h"

enum CataclysmBreath
{
    SPELL_CORROSIVE_POISON    = 46293,
    SPELL_FEVERED_FATIGUE     = 46294,
    SPELL_HEX                 = 46295,
    SPELL_NECROTIC_POISON     = 46296,
    SPELL_PIERCING_SHADOW     = 46297,
    SPELL_SHRINK              = 46298,
    SPELL_WAVERING_WILL       = 46299,
    SPELL_WITHERED_TOUCH      = 46300
};

// 46292 - Cataclysm Breath
class spell_sunwell_plateau_cataclysm_breath : public SpellScript
{
    PrepareSpellScript(spell_sunwell_plateau_cataclysm_breath);

    static constexpr std::array<uint32, 8> PossibleSpells = { SPELL_CORROSIVE_POISON, SPELL_FEVERED_FATIGUE, SPELL_HEX, SPELL_NECROTIC_POISON, SPELL_PIERCING_SHADOW, SPELL_SHRINK, SPELL_WAVERING_WILL, SPELL_WITHERED_TOUCH };

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(PossibleSpells);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        std::array<uint32, 8> spellsToCast = PossibleSpells;

        Trinity::Containers::RandomShuffle(spellsToCast);

        for (uint32 i = 0; i < 4; ++i)
            caster->CastSpell(caster, spellsToCast[i]);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sunwell_plateau_cataclysm_breath::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_sunwell_plateau()
{
    RegisterSpellScript(spell_sunwell_plateau_cataclysm_breath);
}
