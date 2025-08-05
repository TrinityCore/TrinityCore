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

enum AQ40TeleportSpells
{
    SPELL_TELEPORT_TO_TWIN_EMPS_EFFECT        = 29181,
    SPELL_TELEPORT_TO_FINAL_CHAMBER_EFFECT    = 29190
};

// 29182 - Teleport to Twin Emperors
class spell_temple_of_ahnqiraj_teleport_to_twin_emperors : public SpellScript
{
    PrepareSpellScript(spell_temple_of_ahnqiraj_teleport_to_twin_emperors);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TELEPORT_TO_TWIN_EMPS_EFFECT });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_TELEPORT_TO_TWIN_EMPS_EFFECT);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_temple_of_ahnqiraj_teleport_to_twin_emperors::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 29188 - Teleport to Final Chamber
class spell_temple_of_ahnqiraj_teleport_to_final_chamber : public SpellScript
{
    PrepareSpellScript(spell_temple_of_ahnqiraj_teleport_to_final_chamber);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TELEPORT_TO_FINAL_CHAMBER_EFFECT });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_TELEPORT_TO_FINAL_CHAMBER_EFFECT);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_temple_of_ahnqiraj_teleport_to_final_chamber::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum AQ40Itch
{
    SPELL_VEKNISS_CATALYST        = 26078
};

// 26077 - Itch
class spell_temple_of_ahnqiraj_itch : public AuraScript
{
    PrepareAuraScript(spell_temple_of_ahnqiraj_itch);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_VEKNISS_CATALYST });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), SPELL_VEKNISS_CATALYST, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_temple_of_ahnqiraj_itch::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_temple_of_ahnqiraj()
{
    RegisterSpellScript(spell_temple_of_ahnqiraj_teleport_to_twin_emperors);
    RegisterSpellScript(spell_temple_of_ahnqiraj_teleport_to_final_chamber);
    RegisterSpellScript(spell_temple_of_ahnqiraj_itch);
}
