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
#include "InstanceScript.h"
#include "SpellScript.h"
#include "serpent_shrine.h"
#include "Unit.h"

enum SerpentshrineCavernMisc
{
    SPELL_FRENZY_WATER_PERIODIC      = 37280,
    SPELL_FRENZY_WATER_SUMMON        = 37026,
    SPELL_SCALDING_WATER             = 37284
};

// 37025 - Coilfang Water
class spell_serpent_shrine_coilfang_water : public AuraScript
{
    PrepareAuraScript(spell_serpent_shrine_coilfang_water);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FRENZY_WATER_PERIODIC, SPELL_SCALDING_WATER });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        if (InstanceScript* instance = target->GetInstanceScript())
        {
            if (instance->GetData(DATA_KILLED_ELITES) < MIN_KILLED_ELITES)
            {
                target->CastSpell(nullptr, SPELL_FRENZY_WATER_PERIODIC, true);
            }
            else
            {
                target->CastSpell(nullptr, SPELL_SCALDING_WATER, true);
            }
        }
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_FRENZY_WATER_PERIODIC);
        GetTarget()->RemoveAurasDueToSpell(SPELL_SCALDING_WATER);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_serpent_shrine_coilfang_water::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_serpent_shrine_coilfang_water::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 37280 - Frenzy Water
class spell_serpent_shrine_frenzy_water : public AuraScript
{
    PrepareAuraScript(spell_serpent_shrine_frenzy_water);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FRENZY_WATER_SUMMON });
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        if (target->HasUnitMovementFlag(MOVEMENTFLAG_SWIMMING))
            target->CastSpell(nullptr, SPELL_FRENZY_WATER_SUMMON, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_serpent_shrine_frenzy_water::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

void AddSC_serpentshrine_cavern()
{
    RegisterSpellScript(spell_serpent_shrine_coilfang_water);
    RegisterSpellScript(spell_serpent_shrine_frenzy_water);
}
