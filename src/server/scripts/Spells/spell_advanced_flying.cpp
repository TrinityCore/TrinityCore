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

/*
 * Scripts for spells used by dragonriding and advanced fly spells.
 * Scriptnames of files in this file should be prefixed with "spell_af_".
 */

#include "Containers.h"
#include "DB2Stores.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include <MovementPackets.h>
#include <G3D/g3dmath.h>

enum AdvancedFlyingSpells
{
    SPELL_DRAGONRIDER_ENERGIZE  = 372606,
    SPELL_VIGOR_CACHE           = 433547,
    SPELL_RIDING_ABROAD         = 432503, // TODO outside of dragon isles
    SPELL_ENERGY_WIDGET         = 423624,
};

// 373646 - Soar (Racial)
// 406095 - Skyriding
// 430833 - Soar (Racial)
class spell_af_skyriding : public AuraScript
{
    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_ENERGY_WIDGET, true);
        GetTarget()->SetPower(POWER_ALTERNATE_MOUNT, GetTarget()->GetPower(POWER_ALTERNATE_MOUNT), true);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_ENERGY_WIDGET);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_af_skyriding::OnApply, EFFECT_0, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_af_skyriding::OnRemove, EFFECT_0, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 372773 - Dragonrider Energy
class spell_af_energy : public AuraScript
{
    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (!target->HasAura(SPELL_VIGOR_CACHE))
        {
            CastSpellExtraArgs extraArgs(TRIGGERED_FULL_MASK);
            extraArgs.AddSpellMod(SPELLVALUE_BASE_POINT0, target->GetPower(POWER_ALTERNATE_MOUNT));
            target->CastSpell(target, SPELL_VIGOR_CACHE, extraArgs);
        }
    }

    void OnPeriodic(AuraEffect* /*aurEff*/)
    {
        if (Unit* caster = GetCaster())
        {
            if (ShouldRegenEnergy(caster))
            {
                if (AuraEffect* subAmountAurEff = caster->GetAuraEffect(SPELL_VIGOR_CACHE, EFFECT_1))
                {
                    int32 baseRegen = 20; // Todo : Calculate this based on talents & if we are thrilled/grounded

                    int32 newAmount = subAmountAurEff->GetAmount() + baseRegen;

                    if (newAmount >= 100)
                    {
                        newAmount -= 100;

                        caster->CastSpell(caster, SPELL_DRAGONRIDER_ENERGIZE, TRIGGERED_FULL_MASK);

                        if (AuraEffect* amountAurEff = caster->GetAuraEffect(SPELL_VIGOR_CACHE, EFFECT_0))
                            amountAurEff->SetAmount(caster->GetPower(POWER_ALTERNATE_MOUNT));
                    }

                    subAmountAurEff->SetAmount(newAmount);
                    subAmountAurEff->GetBase()->SetNeedClientUpdateForTargets();
                }
            }
        }
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_VIGOR_CACHE);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_af_energy::OnApply, EFFECT_0, SPELL_AURA_ENABLE_ALT_POWER, AURA_EFFECT_HANDLE_REAL);
        OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_af_energy::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        OnEffectRemove += AuraEffectRemoveFn(spell_af_energy::OnRemove, EFFECT_0, SPELL_AURA_ENABLE_ALT_POWER, AURA_EFFECT_HANDLE_REAL);
    }

private:
    bool ShouldRegenEnergy(Unit const* caster) const
    {
        if (caster->GetPower(POWER_ALTERNATE_MOUNT) == caster->GetMaxPower(POWER_ALTERNATE_MOUNT))
            return false;

        FlightCapabilityEntry const* flightCapabilityEntry = sFlightCapabilityStore.LookupEntry(caster->GetFlightCapabilityID());
        if (!flightCapabilityEntry)
            return false;

        float velocityRegenThreshold = flightCapabilityEntry->MaxVel * flightCapabilityEntry->VigorRegenMaxVelCoefficient;
        if (caster->GetAdvFlyingVelocity() >= velocityRegenThreshold)
            return true;

        return !caster->IsInAir() || caster->IsInWater();
    }
};

// 374763 - Lift off
// 372610 - Skyward Ascent (Dragonriding)
class spell_af_skyward_ascent : public SpellScript
{
    void HandleHitTarget(SpellEffIndex effIndex)
    {
        if (Player* caster = GetCaster()->ToPlayer())
        {
            uint32 ascentSpeed = uint32(GetSpellValue()->EffectBasePoints[effIndex]);
            caster->AddMoveImpulse(Position(0, 0, float(ascentSpeed) / 10));
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_af_skyward_ascent::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 372608 - Surge Forward
class spell_af_surge_forward : public SpellScript
{
    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Player* caster = GetCaster()->ToPlayer())
        {
            float SURGE_SPEED = 14.0f;

            float destX = caster->GetPositionX() + SURGE_SPEED * std::cos(caster->GetOrientation());
            float destY = caster->GetPositionY() + SURGE_SPEED * std::sin(caster->GetOrientation());
            float destZ = caster->GetPositionZ() + SURGE_SPEED * std::tan(caster->m_movementInfo.pitch);

            caster->AddMoveImpulse(Position(destX - caster->GetPositionX(), destY - caster->GetPositionY(), destZ - caster->GetPositionZ()));
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_af_surge_forward::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 361584 - Whirling Surge
class spell_af_whirling_surge : public SpellScript
{
    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Player* caster = GetCaster()->ToPlayer())
        {
            float SURGE_SPEED = 60.0f;

            float destX = caster->GetPositionX() + SURGE_SPEED * std::cos(caster->GetOrientation());
            float destY = caster->GetPositionY() + SURGE_SPEED * std::sin(caster->GetOrientation());
            float destZ = caster->GetPositionZ() + SURGE_SPEED * std::tan(caster->m_movementInfo.pitch);

            caster->AddMoveImpulse(Position(destX - caster->GetPositionX(), destY - caster->GetPositionY(), destZ - caster->GetPositionZ()));
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_af_whirling_surge::HandleHitTarget, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

void AddSC_advanced_flying_spell_scripts()
{
    RegisterSpellScript(spell_af_skyriding);
    RegisterSpellScript(spell_af_energy);
    RegisterSpellScript(spell_af_skyward_ascent);
    RegisterSpellScript(spell_af_surge_forward);
    RegisterSpellScript(spell_af_whirling_surge);
}
