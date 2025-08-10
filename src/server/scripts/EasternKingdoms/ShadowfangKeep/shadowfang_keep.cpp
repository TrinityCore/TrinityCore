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

// 7057 - Haunting Spirits
class spell_shadowfang_keep_haunting_spirits : public AuraScript
{
    void CalcPeriodic(AuraEffect const* /*aurEff*/, bool& isPeriodic, int32& amplitude)
    {
        isPeriodic = true;
        amplitude = (irand(0, 60) + 30) * IN_MILLISECONDS;
    }

    void HandleDummyTick(AuraEffect const* aurEff)
    {
        GetTarget()->CastSpell(nullptr, aurEff->GetAmount(), true);
    }

    void HandleUpdatePeriodic(AuraEffect* aurEff)
    {
        aurEff->CalculatePeriodic(GetCaster());
    }

    void Register() override
    {
        DoEffectCalcPeriodic += AuraEffectCalcPeriodicFn(spell_shadowfang_keep_haunting_spirits::CalcPeriodic, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_shadowfang_keep_haunting_spirits::HandleDummyTick, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_shadowfang_keep_haunting_spirits::HandleUpdatePeriodic, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

void AddSC_shadowfang_keep()
{
    RegisterSpellScript(spell_shadowfang_keep_haunting_spirits);
}
