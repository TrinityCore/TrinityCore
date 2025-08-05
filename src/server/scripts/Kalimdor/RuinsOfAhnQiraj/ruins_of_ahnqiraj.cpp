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
#include "SpellAuras.h"
#include "SpellScript.h"
#include "Unit.h"

enum AQ20Itch
{
    SPELL_HIVEZARA_CATALYST        = 25187
};

// 25185 - Itch
class spell_ruins_of_ahnqiraj_itch : public AuraScript
{
    PrepareAuraScript(spell_ruins_of_ahnqiraj_itch);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HIVEZARA_CATALYST });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), SPELL_HIVEZARA_CATALYST, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_ruins_of_ahnqiraj_itch::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_ruins_of_ahnqiraj()
{
    RegisterSpellScript(spell_ruins_of_ahnqiraj_itch);
}
