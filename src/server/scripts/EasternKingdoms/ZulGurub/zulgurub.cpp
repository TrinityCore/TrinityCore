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
#include "zulgurub.h"
#include "Unit.h"

enum PoisonousBlood
{
    SPELL_POISONOUS_BLOOD     = 24321
};

// 24320 - Poisonous Blood
class spell_zulgurub_poisonous_blood : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_POISONOUS_BLOOD });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_POISONOUS_BLOOD);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_zulgurub_poisonous_blood::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_zulgurub()
{
    RegisterSpellScript(spell_zulgurub_poisonous_blood);
}
