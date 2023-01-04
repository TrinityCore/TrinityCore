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

#include "SpellAuras.h"
#include "SpellScript.h"
#include "ScriptMgr.h"
#include "Unit.h"
#include "ruby_life_pools.h"

enum RLPSpells
{
    // Flashfrost Chillweaver
    SPELL_ICE_SHIELD = 372749,

    // Primal Juggernaut
    SPELL_EXCAVATE   = 373497
};

// 371652 - Executed
class spell_ruby_life_pools_executed : public AuraScript
{
    PrepareAuraScript(spell_ruby_life_pools_executed);

    void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->SetUnitFlag3(UNIT_FLAG3_FAKE_DEAD);
        target->SetUnitFlag2(UNIT_FLAG2_FEIGN_DEATH);
        target->SetUnitFlag(UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_ruby_life_pools_executed::HandleEffectApply, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

// 384933 - Ice Shield
class spell_ruby_life_pools_ice_shield : public AuraScript
{
    PrepareAuraScript(spell_ruby_life_pools_ice_shield);

    void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();

        if (Aura* iceShield = target->GetAura(SPELL_ICE_SHIELD))
            iceShield->RefreshDuration();
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_ruby_life_pools_ice_shield::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 372793 - Excavate
class spell_ruby_life_pools_excavate : public AuraScript
{
    PrepareAuraScript(spell_ruby_life_pools_excavate);

    void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), SPELL_EXCAVATE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_ruby_life_pools_excavate::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 395029 - Storm Infusion
class spell_ruby_life_pools_storm_infusion : public SpellScript
{
    PrepareSpellScript(spell_ruby_life_pools_storm_infusion);

    void SetDest(SpellDestination& dest)
    {
        dest.RelocateOffset({ 9.0f, 0.0f, 4.0f, 0.0f });
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_ruby_life_pools_storm_infusion::SetDest, EFFECT_1, TARGET_DEST_DEST);
    }
};

void AddSC_ruby_life_pools()
{
    RegisterSpellScript(spell_ruby_life_pools_executed);
    RegisterSpellScript(spell_ruby_life_pools_ice_shield);
    RegisterSpellScript(spell_ruby_life_pools_excavate);
    RegisterSpellScript(spell_ruby_life_pools_storm_infusion);
}
