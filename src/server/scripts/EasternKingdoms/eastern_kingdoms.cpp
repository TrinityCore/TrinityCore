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

#include "DBCStores.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "Unit.h"

enum Translocation
{
    SPELL_TRANSLOCATION_DUSKWITHER_SPIRE_UP       = 26566,
    SPELL_TRANSLOCATION_DUSKWITHER_SPIRE_DOWN     = 26572,
    SPELL_TRANSLOCATION_SILVERMOON_TO_UNDERCITY   = 25649,
    SPELL_TRANSLOCATION_UNDERCITY_TO_SILVERMOON   = 35730
};

// 34448 - Translocate
class spell_eastern_kingdoms_duskwither_spire_up : public SpellScript
{
    PrepareSpellScript(spell_eastern_kingdoms_duskwither_spire_up);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TRANSLOCATION_DUSKWITHER_SPIRE_UP });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_TRANSLOCATION_DUSKWITHER_SPIRE_UP);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_eastern_kingdoms_duskwither_spire_up::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 34452 - Translocate
class spell_eastern_kingdoms_duskwither_spire_down : public SpellScript
{
    PrepareSpellScript(spell_eastern_kingdoms_duskwither_spire_down);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TRANSLOCATION_DUSKWITHER_SPIRE_DOWN });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_TRANSLOCATION_DUSKWITHER_SPIRE_DOWN);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_eastern_kingdoms_duskwither_spire_down::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 35376 - Translocate
class spell_eastern_kingdoms_silvermoon_to_undercity : public SpellScript
{
    PrepareSpellScript(spell_eastern_kingdoms_silvermoon_to_undercity);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TRANSLOCATION_SILVERMOON_TO_UNDERCITY });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_TRANSLOCATION_SILVERMOON_TO_UNDERCITY);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_eastern_kingdoms_silvermoon_to_undercity::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 35727 - Translocate
class spell_eastern_kingdoms_undercity_to_silvermoon : public SpellScript
{
    PrepareSpellScript(spell_eastern_kingdoms_undercity_to_silvermoon);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TRANSLOCATION_UNDERCITY_TO_SILVERMOON });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_TRANSLOCATION_UNDERCITY_TO_SILVERMOON);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_eastern_kingdoms_undercity_to_silvermoon::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum DeadScarBombingRun
{
    SOUND_ID_BOMBING_RUN       = 12318
};

// 45071 - Quest - Sunwell Daily - Dead Scar Bombing Run
class spell_eastern_kingdoms_dead_scar_bombing_run : public SpellScript
{
    PrepareSpellScript(spell_eastern_kingdoms_dead_scar_bombing_run);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return sSoundEntriesStore.LookupEntry(SOUND_ID_BOMBING_RUN);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->PlayDirectSound(SOUND_ID_BOMBING_RUN);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_eastern_kingdoms_dead_scar_bombing_run::HandleScript, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum DawnbladeAttack
{
    SPELL_DAWNBLADE_ATTACK     = 45189
};

// 45188 - Dawnblade Attack
class spell_eastern_kingdoms_dawnblade_attack : public SpellScript
{
    PrepareSpellScript(spell_eastern_kingdoms_dawnblade_attack);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DAWNBLADE_ATTACK });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_DAWNBLADE_ATTACK);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_eastern_kingdoms_dawnblade_attack::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_eastern_kingdoms()
{
    RegisterSpellScript(spell_eastern_kingdoms_duskwither_spire_up);
    RegisterSpellScript(spell_eastern_kingdoms_duskwither_spire_down);
    RegisterSpellScript(spell_eastern_kingdoms_silvermoon_to_undercity);
    RegisterSpellScript(spell_eastern_kingdoms_undercity_to_silvermoon);
    RegisterSpellScript(spell_eastern_kingdoms_dead_scar_bombing_run);
    RegisterSpellScript(spell_eastern_kingdoms_dawnblade_attack);
}
