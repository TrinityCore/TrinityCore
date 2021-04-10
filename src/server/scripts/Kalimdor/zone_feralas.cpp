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
#include "GameObject.h"
#include "SpellScript.h"

enum GordunniTrapSpells
{
    SPELL_GORDUNNI_DIRT_MOUND_CHEST = 11756,
    SPELL_GORDUNNI_DIRT_MOUND_JUNK  = 19394
};

// 19395 - Gordunni Trap
class spell_gordunni_trap : public SpellScript
{
    PrepareSpellScript(spell_gordunni_trap);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_GORDUNNI_DIRT_MOUND_CHEST, SPELL_GORDUNNI_DIRT_MOUND_JUNK });
    }

    void HandleDummy()
    {
        GameObject* caster = GetGObjCaster();
        caster->CastSpell(caster, urand(0, 1) ? SPELL_GORDUNNI_DIRT_MOUND_CHEST : SPELL_GORDUNNI_DIRT_MOUND_JUNK);
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_gordunni_trap::HandleDummy);
    }
};

void AddSC_feralas()
{
    RegisterSpellScript(spell_gordunni_trap);
}
