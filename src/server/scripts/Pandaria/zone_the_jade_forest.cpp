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
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "Unit.h"

namespace Scripts::Pandaria::TheJadeForest
{
namespace Spells
{
    // Into the Mists & The Mission
    static constexpr uint32 CancelBlackout            = 130812;
    static constexpr uint32 CutToBlack                = 122343;

    // Into the Mists
    static constexpr uint32 TeleportPrepHorde         = 130810;
    static constexpr uint32 TeleportPlayerToCrashSite = 102930;
    static constexpr uint32 WakeUpDead                = 122344;

    // The Mission
    static constexpr uint32 TeleportPrepAlliance      = 130832;
    static constexpr uint32 TheMissionTeleportPlayer  = 130321;
    static constexpr uint32 TheMissionSceneJF         = 131057;
}

// 121545 - Into the Mists Scene - JF
class spell_into_the_mists_scene_jf : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({
            Spells::CancelBlackout
        });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        Unit* hitUnit = GetHitUnit();

        hitUnit->CancelMountAura();
        hitUnit->CastSpell(nullptr, Spells::CancelBlackout, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .OriginalCastId = GetSpell()->m_castId
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_into_the_mists_scene_jf::HandleHitTarget, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 130723 - Into the Mists Scene End
class spell_into_the_mists_scene_end : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({
            Spells::TeleportPlayerToCrashSite,
            Spells::CutToBlack,
            Spells::WakeUpDead
        });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        Unit* hitUnit = GetHitUnit();

        CastSpellExtraArgs const& castSpellExtraArgs = CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .OriginalCastId = GetSpell()->m_castId
        };
        hitUnit->CastSpell(nullptr, Spells::TeleportPlayerToCrashSite, castSpellExtraArgs);
        hitUnit->CastSpell(nullptr, Spells::CutToBlack, castSpellExtraArgs);
        hitUnit->CastSpell(nullptr, Spells::WakeUpDead, castSpellExtraArgs);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_into_the_mists_scene_end::HandleHitTarget, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 131057 - The Mission Scene - JF
class spell_the_mission_scene_jf : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({
            Spells::CancelBlackout
        });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        Unit* hitUnit = GetHitUnit();

        hitUnit->CancelMountAura();
        hitUnit->CastSpell(nullptr, Spells::CancelBlackout, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .OriginalCastId = GetSpell()->m_castId
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_the_mission_scene_jf::HandleHitTarget, EFFECT_3, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 131059 - The Mission Scene End
class spell_the_mission_scene_end : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({
            Spells::TheMissionSceneJF,
            Spells::TheMissionTeleportPlayer,
            Spells::CutToBlack
        });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        Unit* hitUnit = GetHitUnit();

        // EFFECT_0 is incorrectly removing Horde aura
        hitUnit->RemoveAurasDueToSpell(Spells::TheMissionSceneJF);

        CastSpellExtraArgs const& castSpellExtraArgs = CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .OriginalCastId = GetSpell()->m_castId
        };
        hitUnit->CastSpell(nullptr, Spells::TheMissionTeleportPlayer, castSpellExtraArgs);
        hitUnit->CastSpell(nullptr, Spells::CutToBlack, castSpellExtraArgs);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_the_mission_scene_end::HandleHitTarget, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 130812 - Cancel Blackout
class spell_cancel_blackout : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({
            Spells::TeleportPrepHorde,
            Spells::TeleportPrepAlliance
        });
    }

    void HandleAfterEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        GetTarget()->RemoveAurasDueToSpell(Spells::TeleportPrepHorde);
        GetTarget()->RemoveAurasDueToSpell(Spells::TeleportPrepAlliance);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_cancel_blackout::HandleAfterEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};
}

void AddSC_zone_the_jade_forest()
{
    using namespace Scripts::Pandaria::TheJadeForest;

    // Spells
    RegisterSpellScript(spell_into_the_mists_scene_jf);
    RegisterSpellScript(spell_into_the_mists_scene_end);
    RegisterSpellScript(spell_the_mission_scene_jf);
    RegisterSpellScript(spell_the_mission_scene_end);
    RegisterSpellScript(spell_cancel_blackout);
}
