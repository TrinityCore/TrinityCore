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

#include "DB2Stores.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "UnitAI.h"

// 56584 - Combined Toxins
class spell_ahnkahet_combined_toxins : public AuraScript
{
    PrepareAuraScript(spell_ahnkahet_combined_toxins);

    bool CheckProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        // only procs on poisons (damage class check to exclude stuff like Envenom)
        SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
        return (spellInfo && spellInfo->Dispel == DISPEL_POISON && spellInfo->DmgClass != SPELL_DAMAGE_CLASS_MELEE);
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_ahnkahet_combined_toxins::CheckProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_DAMAGE);
    }
};

// 56698, 59102 - Shadow Blast
class spell_ahnkahet_shadow_blast : public SpellScript
{
    PrepareSpellScript(spell_ahnkahet_shadow_blast);

    void HandleDamageCalc(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        if (!target)
            return;

        SetHitDamage(target->GetMaxHealth() * GetEffectInfo().BasePoints / 100);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ahnkahet_shadow_blast::HandleDamageCalc, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

enum ShadowSickle
{
    SPELL_SHADOW_SICKLE_TRIGGERED   = 56701,
    SPELL_SHADOW_SICKLE_TRIGGERED_H = 59104,
};

// 56702, 59103 - Shadow Sickle
class spell_ahnkahet_shadow_sickle : public AuraScript
{
    PrepareAuraScript(spell_ahnkahet_shadow_sickle);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHADOW_SICKLE_TRIGGERED });
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        Unit* owner = GetUnitOwner();

        uint32 spellId = 0;

        switch (GetId())
        {
            case 56702:
                spellId = SPELL_SHADOW_SICKLE_TRIGGERED;
                break;
            case 59103:
                spellId = SPELL_SHADOW_SICKLE_TRIGGERED_H;
                break;
            default:
                return;
        }

        if (owner->IsAIEnabled())
            if (Unit* target = owner->GetAI()->SelectTarget(SelectTargetMethod::Random, 0, 40.f))
                owner->CastSpell(target, spellId, CastSpellExtraArgs(aurEff).SetTriggerFlags(TriggerCastFlags::TRIGGERED_FULL_MASK));
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_ahnkahet_shadow_sickle::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 58906, 58908, 58909, 58910 - Creature - Yogg-Saron Whisper
class spell_ahnkahet_yogg_saron_whisper : public SpellScript
{
    PrepareSpellScript(spell_ahnkahet_yogg_saron_whisper);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return sBroadcastTextStore.HasRecord(uint32(spellInfo->GetEffect(EFFECT_0).CalcValue())) &&
            sSoundKitStore.HasRecord(uint32(spellInfo->GetEffect(EFFECT_1).CalcValue()));
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Player* player = GetHitPlayer())
            GetCaster()->Unit::Whisper(uint32(GetEffectValue()), player, false);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Player* player = GetHitPlayer())
            player->PlayDistanceSound(uint32(GetEffectValue()), player);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ahnkahet_yogg_saron_whisper::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        OnEffectHitTarget += SpellEffectFn(spell_ahnkahet_yogg_saron_whisper::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_ahnkahet()
{
    RegisterSpellScript(spell_ahnkahet_combined_toxins);
    RegisterSpellScript(spell_ahnkahet_shadow_blast);
    RegisterSpellScript(spell_ahnkahet_shadow_sickle);
    RegisterSpellScript(spell_ahnkahet_yogg_saron_whisper);
}
