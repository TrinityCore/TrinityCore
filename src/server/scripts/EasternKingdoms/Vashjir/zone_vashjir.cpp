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
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "Unit.h"

namespace Scripts::EasternKingdoms::Vashjir
{
namespace Spells
{
    static constexpr uint32 SeaLegsAura = 73701;
}

// 76377 - Sea Legs
class spell_vashjir_sea_legs_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::SeaLegsAura });
    }

    static void CalcPeriodic(AuraScript const&, AuraEffect const* /*aurEff*/, bool& isPeriodic, int32& amplitude)
    {
        isPeriodic = true;
        amplitude = 500;
    }

    void OnUpdate(AuraEffect const* /*aurEff*/) const
    {
        Unit* target = GetTarget();
        if (target->IsInWater())
            target->CastSpell(target, Spells::SeaLegsAura, TRIGGERED_IGNORE_CAST_IN_PROGRESS);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        GetTarget()->RemoveAura(Spells::SeaLegsAura);
    }

    void Register() override
    {
        DoEffectCalcPeriodic += AuraEffectCalcPeriodicFn(spell_vashjir_sea_legs_aura::CalcPeriodic, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_vashjir_sea_legs_aura::OnUpdate, EFFECT_0, SPELL_AURA_DUMMY);
        AfterEffectRemove += AuraEffectRemoveFn(spell_vashjir_sea_legs_aura::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 76143 - Low Health
class spell_vashjir_low_health : public AuraScript
{
    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->SetHealth(GetTarget()->CountPctFromMaxHealth(10));
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_vashjir_low_health::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};
}

void AddSC_vashjir()
{
    using namespace Scripts::EasternKingdoms::Vashjir;

    // Spells
    RegisterSpellScript(spell_vashjir_sea_legs_aura);
    RegisterSpellScript(spell_vashjir_low_health);
}
