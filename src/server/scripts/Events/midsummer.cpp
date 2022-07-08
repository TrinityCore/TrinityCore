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
#include "CreatureAIImpl.h"
#include "Player.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum TorchSpells
{
    SPELL_TORCH_TOSSING_TRAINING                    = 45716,
    SPELL_TORCH_TOSSING_PRACTICE                    = 46630,
    SPELL_TORCH_TOSSING_TRAINING_SUCCESS_ALLIANCE   = 45719,
    SPELL_TORCH_TOSSING_TRAINING_SUCCESS_HORDE      = 46651,
    SPELL_TARGET_INDICATOR_COSMETIC                 = 46901,
    SPELL_TARGET_INDICATOR                          = 45723,
    SPELL_BRAZIERS_HIT                              = 45724
};

// 45724 - Braziers Hit!
class spell_midsummer_braziers_hit : public AuraScript
{
    PrepareAuraScript(spell_midsummer_braziers_hit);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_TORCH_TOSSING_TRAINING,
            SPELL_TORCH_TOSSING_PRACTICE,
            SPELL_TORCH_TOSSING_TRAINING_SUCCESS_ALLIANCE,
            SPELL_TORCH_TOSSING_TRAINING_SUCCESS_HORDE
        });
    }

    void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Player* player = GetTarget()->ToPlayer();
        if (!player)
            return;

        if ((player->HasAura(SPELL_TORCH_TOSSING_TRAINING) && GetStackAmount() == 8) || (player->HasAura(SPELL_TORCH_TOSSING_PRACTICE) && GetStackAmount() == 20))
        {
            if (player->GetTeam() == ALLIANCE)
                player->CastSpell(player, SPELL_TORCH_TOSSING_TRAINING_SUCCESS_ALLIANCE, true);
            else if (player->GetTeam() == HORDE)
                player->CastSpell(player, SPELL_TORCH_TOSSING_TRAINING_SUCCESS_HORDE, true);
            Remove();
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_midsummer_braziers_hit::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAPPLY);
    }
};

// 45907 - Torch Target Picker
class spell_midsummer_torch_target_picker : public SpellScript
{
    PrepareSpellScript(spell_midsummer_torch_target_picker);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TARGET_INDICATOR_COSMETIC, SPELL_TARGET_INDICATOR });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        target->CastSpell(target, SPELL_TARGET_INDICATOR_COSMETIC, true);
        target->CastSpell(target, SPELL_TARGET_INDICATOR, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_midsummer_torch_target_picker::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 46054 - Torch Toss (land)
class spell_midsummer_torch_toss_land : public SpellScript
{
    PrepareSpellScript(spell_midsummer_torch_toss_land);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BRAZIERS_HIT });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetCaster(), SPELL_BRAZIERS_HIT, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_midsummer_torch_toss_land::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum RibbonPoleData
{
    SPELL_HAS_FULL_MIDSUMMER_SET      = 58933,
    SPELL_BURNING_HOT_POLE_DANCE      = 58934,
    SPELL_RIBBON_POLE_PERIODIC_VISUAL = 45406,
    SPELL_RIBBON_DANCE                = 29175,
    SPELL_TEST_RIBBON_POLE_1          = 29705,
    SPELL_TEST_RIBBON_POLE_2          = 29726,
    SPELL_TEST_RIBBON_POLE_3          = 29727
};

// 29705, 29726, 29727 - Test Ribbon Pole Channel
class spell_midsummer_test_ribbon_pole_channel : public AuraScript
{
    PrepareAuraScript(spell_midsummer_test_ribbon_pole_channel);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_RIBBON_POLE_PERIODIC_VISUAL,
            SPELL_BURNING_HOT_POLE_DANCE,
            SPELL_HAS_FULL_MIDSUMMER_SET,
            SPELL_RIBBON_DANCE
        });
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_RIBBON_POLE_PERIODIC_VISUAL);
    }

    void PeriodicTick(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_RIBBON_POLE_PERIODIC_VISUAL, true);

        if (Aura* aur = target->GetAura(SPELL_RIBBON_DANCE))
        {
            aur->SetMaxDuration(std::min(3600000, aur->GetMaxDuration() + 180000));
            aur->RefreshDuration();

            if (aur->GetMaxDuration() == 3600000 && target->HasAura(SPELL_HAS_FULL_MIDSUMMER_SET))
                target->CastSpell(target, SPELL_BURNING_HOT_POLE_DANCE, true);
        }
        else
            target->CastSpell(target, SPELL_RIBBON_DANCE, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_midsummer_test_ribbon_pole_channel::HandleRemove, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_midsummer_test_ribbon_pole_channel::PeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 45406 - Holiday - Midsummer, Ribbon Pole Periodic Visual
class spell_midsummer_ribbon_pole_periodic_visual : public AuraScript
{
    PrepareAuraScript(spell_midsummer_ribbon_pole_periodic_visual);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_TEST_RIBBON_POLE_1,
            SPELL_TEST_RIBBON_POLE_2,
            SPELL_TEST_RIBBON_POLE_3
        });
    }

    void PeriodicTick(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        if (!target->HasAura(SPELL_TEST_RIBBON_POLE_1) && !target->HasAura(SPELL_TEST_RIBBON_POLE_2) && !target->HasAura(SPELL_TEST_RIBBON_POLE_3))
            Remove();
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_midsummer_ribbon_pole_periodic_visual::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

enum JugglingTorch
{
    SPELL_JUGGLE_TORCH_SLOW          = 45792,
    SPELL_JUGGLE_TORCH_MEDIUM        = 45806,
    SPELL_JUGGLE_TORCH_FAST          = 45816,
    SPELL_JUGGLE_TORCH_SELF          = 45638,

    SPELL_JUGGLE_TORCH_SHADOW_SLOW   = 46120,
    SPELL_JUGGLE_TORCH_SHADOW_MEDIUM = 46118,
    SPELL_JUGGLE_TORCH_SHADOW_FAST   = 46117,
    SPELL_JUGGLE_TORCH_SHADOW_SELF   = 46121,

    SPELL_GIVE_TORCH                 = 45280,
    QUEST_TORCH_CATCHING_A           = 11657,
    QUEST_TORCH_CATCHING_H           = 11923,
    QUEST_MORE_TORCH_CATCHING_A      = 11924,
    QUEST_MORE_TORCH_CATCHING_H      = 11925
};

// 45819 - Throw Torch
class spell_midsummer_juggle_torch : public SpellScript
{
    PrepareSpellScript(spell_midsummer_juggle_torch);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({
            SPELL_JUGGLE_TORCH_SLOW, SPELL_JUGGLE_TORCH_MEDIUM, SPELL_JUGGLE_TORCH_FAST,
            SPELL_JUGGLE_TORCH_SELF, SPELL_JUGGLE_TORCH_SHADOW_SLOW, SPELL_JUGGLE_TORCH_SHADOW_MEDIUM,
            SPELL_JUGGLE_TORCH_SHADOW_FAST, SPELL_JUGGLE_TORCH_SHADOW_SELF
        });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (!GetExplTargetDest())
            return;

        Position spellDest = *GetExplTargetDest();
        float distance = GetCaster()->GetExactDist2d(spellDest.GetPositionX(), spellDest.GetPositionY());

        uint32 torchSpellID = 0;
        uint32 torchShadowSpellID = 0;

        if (distance <= 1.5f)
        {
            torchSpellID = SPELL_JUGGLE_TORCH_SELF;
            torchShadowSpellID = SPELL_JUGGLE_TORCH_SHADOW_SELF;
            spellDest = GetCaster()->GetPosition();
        }
        else if (distance <= 10.0f)
        {
            torchSpellID = SPELL_JUGGLE_TORCH_SLOW;
            torchShadowSpellID = SPELL_JUGGLE_TORCH_SHADOW_SLOW;
        }
        else if (distance <= 20.0f)
        {
            torchSpellID = SPELL_JUGGLE_TORCH_MEDIUM;
            torchShadowSpellID = SPELL_JUGGLE_TORCH_SHADOW_MEDIUM;
        }
        else
        {
            torchSpellID = SPELL_JUGGLE_TORCH_FAST;
            torchShadowSpellID = SPELL_JUGGLE_TORCH_SHADOW_FAST;
        }

        GetCaster()->CastSpell(spellDest, torchSpellID);
        GetCaster()->CastSpell(spellDest, torchShadowSpellID);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_midsummer_juggle_torch::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 45644 - Juggle Torch (Catch)
class spell_midsummer_torch_catch : public SpellScript
{
    PrepareSpellScript(spell_midsummer_torch_catch);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_GIVE_TORCH });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Player* player = GetHitPlayer();
        if (!player)
            return;

        if (player->GetQuestStatus(QUEST_TORCH_CATCHING_A) == QUEST_STATUS_REWARDED || player->GetQuestStatus(QUEST_TORCH_CATCHING_H) == QUEST_STATUS_REWARDED)
            player->CastSpell(player, SPELL_GIVE_TORCH);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_midsummer_torch_catch::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum FlingTorch
{
    SPELL_FLING_TORCH_TRIGGERED           = 45669,
    SPELL_FLING_TORCH_SHADOW              = 46105,
    SPELL_JUGGLE_TORCH_MISSED             = 45676,
    SPELL_TORCHES_CAUGHT                  = 45693,
    SPELL_TORCH_CATCHING_SUCCESS_ALLIANCE = 46081,
    SPELL_TORCH_CATCHING_SUCCESS_HORDE    = 46654,
    SPELL_TORCH_CATCHING_REMOVE_TORCHES   = 46084
};

// 46747 - Fling torch
class spell_midsummer_fling_torch : public SpellScript
{
    PrepareSpellScript(spell_midsummer_fling_torch);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FLING_TORCH_TRIGGERED, SPELL_FLING_TORCH_SHADOW });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Position dest = GetCaster()->GetFirstCollisionPosition(30.0f, (float)rand_norm() * static_cast<float>(2 * M_PI));
        GetCaster()->CastSpell(dest, SPELL_FLING_TORCH_TRIGGERED, true);
        GetCaster()->CastSpell(dest, SPELL_FLING_TORCH_SHADOW);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_midsummer_fling_torch::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 45669 - Fling Torch
class spell_midsummer_fling_torch_triggered : public SpellScript
{
    PrepareSpellScript(spell_midsummer_fling_torch_triggered);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_JUGGLE_TORCH_MISSED });
    }

    void HandleTriggerMissile(SpellEffIndex effIndex)
    {
        if (Position const* pos = GetHitDest())
        {
            if (GetCaster()->GetExactDist2d(pos) > 3.0f)
            {
                PreventHitEffect(effIndex);
                GetCaster()->CastSpell(*GetExplTargetDest(), SPELL_JUGGLE_TORCH_MISSED);
                GetCaster()->RemoveAura(SPELL_TORCHES_CAUGHT);
            }
        }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_midsummer_fling_torch_triggered::HandleTriggerMissile, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
    }
};

// 45671 - Juggle Torch (Catch, Quest)
class spell_midsummer_fling_torch_catch : public SpellScript
{
    PrepareSpellScript(spell_midsummer_fling_torch_catch);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({
            SPELL_FLING_TORCH_TRIGGERED,
            SPELL_TORCH_CATCHING_SUCCESS_ALLIANCE,
            SPELL_TORCH_CATCHING_SUCCESS_HORDE,
            SPELL_TORCH_CATCHING_REMOVE_TORCHES,
            SPELL_FLING_TORCH_SHADOW
        });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Player* player = GetHitPlayer();
        if (!player)
            return;

        if (!GetExplTargetDest())
            return;

        // Only the caster can catch the torch
        if (player->GetGUID() != GetCaster()->GetGUID())
            return;

        uint8 requiredCatches = 0;
        // Number of required catches depends on quest - 4 for the normal quest, 10 for the daily version
        if (player->GetQuestStatus(QUEST_TORCH_CATCHING_A) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(QUEST_TORCH_CATCHING_H) == QUEST_STATUS_INCOMPLETE)
            requiredCatches = 3;
        else if (player->GetQuestStatus(QUEST_MORE_TORCH_CATCHING_A) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(QUEST_MORE_TORCH_CATCHING_H) == QUEST_STATUS_INCOMPLETE)
            requiredCatches = 9;

        // Used quest item without being on quest - do nothing
        if (requiredCatches == 0)
            return;

        if (player->GetAuraCount(SPELL_TORCHES_CAUGHT) >= requiredCatches)
        {
            player->CastSpell(player, (player->GetTeam() == ALLIANCE) ? SPELL_TORCH_CATCHING_SUCCESS_ALLIANCE : SPELL_TORCH_CATCHING_SUCCESS_HORDE);
            player->CastSpell(player, SPELL_TORCH_CATCHING_REMOVE_TORCHES);
            player->RemoveAura(SPELL_TORCHES_CAUGHT);
        }
        else
        {
            Position dest = player->GetFirstCollisionPosition(15.0f, (float)rand_norm() * static_cast<float>(2 * M_PI));
            player->CastSpell(player, SPELL_TORCHES_CAUGHT);
            player->CastSpell(dest, SPELL_FLING_TORCH_TRIGGERED, true);
            player->CastSpell(dest, SPELL_FLING_TORCH_SHADOW);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_midsummer_fling_torch_catch::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 45676 - Juggle Torch (Quest, Missed)
class spell_midsummer_fling_torch_missed : public SpellScript
{
    PrepareSpellScript(spell_midsummer_fling_torch_missed);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        // This spell only hits the caster
        targets.remove_if([this](WorldObject* obj)
            {
                return obj->GetGUID() != GetCaster()->GetGUID();
            });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_midsummer_fling_torch_missed::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_midsummer_fling_torch_missed::FilterTargets, EFFECT_2, TARGET_UNIT_DEST_AREA_ENTRY);
    }
};

void AddSC_event_midsummer()
{
    RegisterSpellScript(spell_midsummer_braziers_hit);
    RegisterSpellScript(spell_midsummer_torch_target_picker);
    RegisterSpellScript(spell_midsummer_torch_toss_land);
    RegisterSpellScript(spell_midsummer_test_ribbon_pole_channel);
    RegisterSpellScript(spell_midsummer_ribbon_pole_periodic_visual);
    RegisterSpellScript(spell_midsummer_juggle_torch);
    RegisterSpellScript(spell_midsummer_torch_catch);
    RegisterSpellScript(spell_midsummer_fling_torch);
    RegisterSpellScript(spell_midsummer_fling_torch_triggered);
    RegisterSpellScript(spell_midsummer_fling_torch_catch);
    RegisterSpellScript(spell_midsummer_fling_torch_missed);
}
