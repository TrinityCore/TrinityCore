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
#include "World.h"

enum RamBlaBla
{
    SPELL_GIDDYUP                           = 42924,
    SPELL_RENTAL_RACING_RAM                 = 43883,
    SPELL_SWIFT_WORK_RAM                    = 43880,
    SPELL_RENTAL_RACING_RAM_AURA            = 42146,
    SPELL_RAM_LEVEL_NEUTRAL                 = 43310,
    SPELL_RAM_TROT                          = 42992,
    SPELL_RAM_CANTER                        = 42993,
    SPELL_RAM_GALLOP                        = 42994,
    SPELL_RAM_FATIGUE                       = 43052,
    SPELL_EXHAUSTED_RAM                     = 43332,
    SPELL_RELAY_RACE_TURN_IN                = 44501,

    // Quest
    SPELL_BREWFEST_QUEST_SPEED_BUNNY_GREEN  = 43345,
    SPELL_BREWFEST_QUEST_SPEED_BUNNY_YELLOW = 43346,
    SPELL_BREWFEST_QUEST_SPEED_BUNNY_RED    = 43347
};

// 42924 - Giddyup!
class spell_brewfest_giddyup : public AuraScript
{
    PrepareAuraScript(spell_brewfest_giddyup);

    void OnChange(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (!target->HasAura(SPELL_RENTAL_RACING_RAM) && !target->HasAura(SPELL_SWIFT_WORK_RAM))
        {
            target->RemoveAura(GetId());
            return;
        }

        if (target->HasAura(SPELL_EXHAUSTED_RAM))
            return;

        switch (GetStackAmount())
        {
            case 1: // green
                target->RemoveAura(SPELL_RAM_LEVEL_NEUTRAL);
                target->RemoveAura(SPELL_RAM_CANTER);
                target->CastSpell(target, SPELL_RAM_TROT, true);
                break;
            case 6: // yellow
                target->RemoveAura(SPELL_RAM_TROT);
                target->RemoveAura(SPELL_RAM_GALLOP);
                target->CastSpell(target, SPELL_RAM_CANTER, true);
                break;
            case 11: // red
                target->RemoveAura(SPELL_RAM_CANTER);
                target->CastSpell(target, SPELL_RAM_GALLOP, true);
                break;
            default:
                break;
        }

        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_DEFAULT)
        {
            target->RemoveAura(SPELL_RAM_TROT);
            target->CastSpell(target, SPELL_RAM_LEVEL_NEUTRAL, true);
        }
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        GetTarget()->RemoveAuraFromStack(GetId());
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_brewfest_giddyup::OnChange, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
        OnEffectRemove += AuraEffectRemoveFn(spell_brewfest_giddyup::OnChange, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_brewfest_giddyup::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 43310 - Ram Level - Neutral
// 42992 - Ram - Trot
// 42993 - Ram - Canter
// 42994 - Ram - Gallop
class spell_brewfest_ram : public AuraScript
{
    PrepareAuraScript(spell_brewfest_ram);

    void OnPeriodic(AuraEffect const* aurEff)
    {
        Unit* target = GetTarget();
        if (target->HasAura(SPELL_EXHAUSTED_RAM))
            return;

        switch (GetId())
        {
            case SPELL_RAM_LEVEL_NEUTRAL:
                if (Aura* aura = target->GetAura(SPELL_RAM_FATIGUE))
                    aura->ModStackAmount(-4);
                break;
            case SPELL_RAM_TROT: // green
                if (Aura* aura = target->GetAura(SPELL_RAM_FATIGUE))
                    aura->ModStackAmount(-2);
                if (aurEff->GetTickNumber() == 4)
                    target->CastSpell(target, SPELL_BREWFEST_QUEST_SPEED_BUNNY_GREEN, true);
                break;
            case SPELL_RAM_CANTER:
            {
                CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                args.AddSpellMod(SPELLVALUE_AURA_STACK, 1);
                target->CastSpell(target, SPELL_RAM_FATIGUE, args);
                if (aurEff->GetTickNumber() == 8)
                    target->CastSpell(target, SPELL_BREWFEST_QUEST_SPEED_BUNNY_YELLOW, true);
                break;
            }
            case SPELL_RAM_GALLOP:
            {
                CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                args.AddSpellMod(SPELLVALUE_AURA_STACK, target->HasAura(SPELL_RAM_FATIGUE) ? 4 : 5 /*Hack*/);
                target->CastSpell(target, SPELL_RAM_FATIGUE, args);
                if (aurEff->GetTickNumber() == 8)
                    target->CastSpell(target, SPELL_BREWFEST_QUEST_SPEED_BUNNY_RED, true);
                break;
            }
            default:
                break;
        }

    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_brewfest_ram::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 43052 - Ram Fatigue
class spell_brewfest_ram_fatigue : public AuraScript
{
    PrepareAuraScript(spell_brewfest_ram_fatigue);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        if (GetStackAmount() == 101)
        {
            target->RemoveAura(SPELL_RAM_LEVEL_NEUTRAL);
            target->RemoveAura(SPELL_RAM_TROT);
            target->RemoveAura(SPELL_RAM_CANTER);
            target->RemoveAura(SPELL_RAM_GALLOP);
            target->RemoveAura(SPELL_GIDDYUP);

            target->CastSpell(target, SPELL_EXHAUSTED_RAM, true);
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_brewfest_ram_fatigue::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

// 43450 - Brewfest - apple trap - friendly DND
class spell_brewfest_apple_trap : public AuraScript
{
    PrepareAuraScript(spell_brewfest_apple_trap);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAura(SPELL_RAM_FATIGUE);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_brewfest_apple_trap::OnApply, EFFECT_0, SPELL_AURA_FORCE_REACTION, AURA_EFFECT_HANDLE_REAL);
    }
};

// 43332 - Exhausted Ram
class spell_brewfest_exhausted_ram : public AuraScript
{
    PrepareAuraScript(spell_brewfest_exhausted_ram);

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_RAM_LEVEL_NEUTRAL, true);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectApplyFn(spell_brewfest_exhausted_ram::OnRemove, EFFECT_0, SPELL_AURA_MOD_DECREASE_SPEED, AURA_EFFECT_HANDLE_REAL);
    }
};

// 43714 - Brewfest - Relay Race - Intro - Force - Player to throw- DND
class spell_brewfest_relay_race_intro_force_player_to_throw : public SpellScript
{
    PrepareSpellScript(spell_brewfest_relay_race_intro_force_player_to_throw);

    void HandleForceCast(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        // All this spells trigger a spell that requires reagents; if the
        // triggered spell is cast as "triggered", reagents are not consumed
        GetHitUnit()->CastSpell(nullptr, GetEffectInfo().TriggerSpell, TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_IGNORE_POWER_AND_REAGENT_COST));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_brewfest_relay_race_intro_force_player_to_throw::HandleForceCast, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
    }
};

// 43755 - Brewfest - Daily - Relay Race - Player - Increase Mount Duration - DND
class spell_brewfest_relay_race_turn_in : public SpellScript
{
    PrepareSpellScript(spell_brewfest_relay_race_turn_in);

    void HandleDummy(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);

        if (Aura* aura = GetHitUnit()->GetAura(SPELL_SWIFT_WORK_RAM))
        {
            aura->SetDuration(aura->GetDuration() + 30 * IN_MILLISECONDS);
            GetCaster()->CastSpell(GetHitUnit(), SPELL_RELAY_RACE_TURN_IN, TRIGGERED_FULL_MASK);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_brewfest_relay_race_turn_in::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 43876 - Dismount Ram
class spell_brewfest_dismount_ram : public SpellScript
{
    PrepareSpellScript(spell_brewfest_dismount_ram);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->RemoveAura(SPELL_RENTAL_RACING_RAM);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_brewfest_dismount_ram::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum RamBlub
{
    // Horde
    QUEST_BARK_FOR_DROHNS_DISTILLERY        = 11407,
    QUEST_BARK_FOR_TCHALIS_VOODOO_BREWERY   = 11408,

    // Alliance
    QUEST_BARK_BARLEYBREW                   = 11293,
    QUEST_BARK_FOR_THUNDERBREWS             = 11294,

    // Bark for Drohn's Distillery!
    SAY_DROHN_DISTILLERY_1                  = 23520,
    SAY_DROHN_DISTILLERY_2                  = 23521,
    SAY_DROHN_DISTILLERY_3                  = 23522,
    SAY_DROHN_DISTILLERY_4                  = 23523,

    // Bark for T'chali's Voodoo Brewery!
    SAY_TCHALIS_VOODOO_1                    = 23524,
    SAY_TCHALIS_VOODOO_2                    = 23525,
    SAY_TCHALIS_VOODOO_3                    = 23526,
    SAY_TCHALIS_VOODOO_4                    = 23527,

    // Bark for the Barleybrews!
    SAY_BARLEYBREW_1                        = 23464,
    SAY_BARLEYBREW_2                        = 23465,
    SAY_BARLEYBREW_3                        = 23466,
    SAY_BARLEYBREW_4                        = 22941,

    // Bark for the Thunderbrews!
    SAY_THUNDERBREWS_1                      = 23467,
    SAY_THUNDERBREWS_2                      = 23468,
    SAY_THUNDERBREWS_3                      = 23469,
    SAY_THUNDERBREWS_4                      = 22942
};

// 43259 Brewfest  - Barker Bunny 1
// 43260 Brewfest  - Barker Bunny 2
// 43261 Brewfest  - Barker Bunny 3
// 43262 Brewfest  - Barker Bunny 4
class spell_brewfest_barker_bunny : public AuraScript
{
    PrepareAuraScript(spell_brewfest_barker_bunny);

    bool Load() override
    {
        return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Player* target = GetTarget()->ToPlayer();

        uint32 BroadcastTextId = 0;

        if (target->GetQuestStatus(QUEST_BARK_FOR_DROHNS_DISTILLERY) == QUEST_STATUS_INCOMPLETE ||
            target->GetQuestStatus(QUEST_BARK_FOR_DROHNS_DISTILLERY) == QUEST_STATUS_COMPLETE)
            BroadcastTextId = RAND(SAY_DROHN_DISTILLERY_1, SAY_DROHN_DISTILLERY_2, SAY_DROHN_DISTILLERY_3, SAY_DROHN_DISTILLERY_4);

        if (target->GetQuestStatus(QUEST_BARK_FOR_TCHALIS_VOODOO_BREWERY) == QUEST_STATUS_INCOMPLETE ||
            target->GetQuestStatus(QUEST_BARK_FOR_TCHALIS_VOODOO_BREWERY) == QUEST_STATUS_COMPLETE)
            BroadcastTextId = RAND(SAY_TCHALIS_VOODOO_1, SAY_TCHALIS_VOODOO_2, SAY_TCHALIS_VOODOO_3, SAY_TCHALIS_VOODOO_4);

        if (target->GetQuestStatus(QUEST_BARK_BARLEYBREW) == QUEST_STATUS_INCOMPLETE ||
            target->GetQuestStatus(QUEST_BARK_BARLEYBREW) == QUEST_STATUS_COMPLETE)
            BroadcastTextId = RAND(SAY_BARLEYBREW_1, SAY_BARLEYBREW_2, SAY_BARLEYBREW_3, SAY_BARLEYBREW_4);

        if (target->GetQuestStatus(QUEST_BARK_FOR_THUNDERBREWS) == QUEST_STATUS_INCOMPLETE ||
            target->GetQuestStatus(QUEST_BARK_FOR_THUNDERBREWS) == QUEST_STATUS_COMPLETE)
            BroadcastTextId = RAND(SAY_THUNDERBREWS_1, SAY_THUNDERBREWS_2, SAY_THUNDERBREWS_3, SAY_THUNDERBREWS_4);

        if (BroadcastTextId)
            target->Talk(BroadcastTextId, CHAT_MSG_SAY, sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_SAY), target);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_brewfest_barker_bunny::OnApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

enum BrewfestMountTransformation
{
    SPELL_MOUNT_RAM_100                         = 43900,
    SPELL_MOUNT_RAM_60                          = 43899,
    SPELL_MOUNT_KODO_100                        = 49379,
    SPELL_MOUNT_KODO_60                         = 49378,
    SPELL_BREWFEST_MOUNT_TRANSFORM              = 49357,
    SPELL_BREWFEST_MOUNT_TRANSFORM_REVERSE      = 52845,
};

// 49357 - Brewfest Mount Transformation
// 52845 - Brewfest Mount Transformation (Faction Swap)
class spell_brewfest_mount_transformation : public SpellScript
{
    PrepareSpellScript(spell_brewfest_mount_transformation);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_MOUNT_RAM_100,
            SPELL_MOUNT_RAM_60,
            SPELL_MOUNT_KODO_100,
            SPELL_MOUNT_KODO_60
        });
    }

    void HandleDummy(SpellEffIndex /* effIndex */)
    {
        Player* caster = GetCaster()->ToPlayer();
        if (caster->HasAuraType(SPELL_AURA_MOUNTED))
        {
            caster->RemoveAurasByType(SPELL_AURA_MOUNTED);
            uint32 spell_id;

            switch (GetSpellInfo()->Id)
            {
                case SPELL_BREWFEST_MOUNT_TRANSFORM:
                    if (caster->GetSpeedRate(MOVE_RUN) >= 2.0f)
                        spell_id = caster->GetTeam() == ALLIANCE ? SPELL_MOUNT_RAM_100 : SPELL_MOUNT_KODO_100;
                    else
                        spell_id = caster->GetTeam() == ALLIANCE ? SPELL_MOUNT_RAM_60 : SPELL_MOUNT_KODO_60;
                    break;
                case SPELL_BREWFEST_MOUNT_TRANSFORM_REVERSE:
                    if (caster->GetSpeedRate(MOVE_RUN) >= 2.0f)
                        spell_id = caster->GetTeam() == HORDE ? SPELL_MOUNT_RAM_100 : SPELL_MOUNT_KODO_100;
                    else
                        spell_id = caster->GetTeam() == HORDE ? SPELL_MOUNT_RAM_60 : SPELL_MOUNT_KODO_60;
                    break;
                default:
                    return;
            }
            caster->CastSpell(caster, spell_id, true);
        }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_brewfest_mount_transformation::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

/*
    Brew of the Month
 January   [Wild Winter Pilsner]
    spell_brewfest_botm_the_beast_within
 February  [Izzard's Ever Flavor]
    spell_brewfest_botm_gassy
 March     [Aromatic Honey Brew]
    Nothing to script here
 April     [Metok's Bubble Bock]
    spell_brewfest_botm_bloated
    Incomplete (spells 49828, 49827, 49830, 49837)
 May       [Springtime Stout]
    Nothing to script here
 June      [Blackrock Lager]
    spell_brewfest_botm_internal_combustion
 July      [Stranglethorn Brew]
    spell_brewfest_botm_jungle_madness
 August    [Draenic Pale Ale]
    NYI
 September [Binary Brew]
    spell_brewfest_botm_teach_language
 October   [Autumnal Acorn Ale]
    NYI
 November  [Bartlett's Bitter Brew]
    NYI
 December  [Lord of Frost's Private Label]
    Nothing to script here
*/

enum WildWinterPilsner
{
    SPELL_BOTM_UNLEASH_THE_BEAST    = 50099
};

// 50098 - The Beast Within
class spell_brewfest_botm_the_beast_within : public AuraScript
{
    PrepareAuraScript(spell_brewfest_botm_the_beast_within);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BOTM_UNLEASH_THE_BEAST });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_BOTM_UNLEASH_THE_BEAST);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_brewfest_botm_the_beast_within::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

enum IzzardsEverFlavor
{
    SPELL_BOTM_BELCH_BREW_BELCH_VISUAL    = 49860
};

// 49864 - Gassy
class spell_brewfest_botm_gassy : public AuraScript
{
    PrepareAuraScript(spell_brewfest_botm_gassy);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BOTM_BELCH_BREW_BELCH_VISUAL });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_BOTM_BELCH_BREW_BELCH_VISUAL, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_brewfest_botm_gassy::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

enum MetoksBubbleBock
{
    SPELL_BOTM_BUBBLE_BREW_TRIGGER_MISSILE    = 50072
};

// 49822 - Bloated
class spell_brewfest_botm_bloated : public AuraScript
{
    PrepareAuraScript(spell_brewfest_botm_bloated);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BOTM_BUBBLE_BREW_TRIGGER_MISSILE });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_BOTM_BUBBLE_BREW_TRIGGER_MISSILE, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_brewfest_botm_bloated::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

enum BlackrockLager
{
    SPELL_BOTM_BELCH_FIRE_VISUAL    = 49737
};

// 49738 - Internal Combustion
class spell_brewfest_botm_internal_combustion : public AuraScript
{
    PrepareAuraScript(spell_brewfest_botm_internal_combustion);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BOTM_BELCH_FIRE_VISUAL });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_BOTM_BELCH_FIRE_VISUAL, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_brewfest_botm_internal_combustion::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

enum StranglethornBrew
{
    SPELL_BOTM_JUNGLE_BREW_VISION_EFFECT    = 50010
};

// 49962 - Jungle Madness!
class spell_brewfest_botm_jungle_madness : public SpellScript
{
    PrepareSpellScript(spell_brewfest_botm_jungle_madness);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BOTM_JUNGLE_BREW_VISION_EFFECT });
    }

    void HandleAfterCast()
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_BOTM_JUNGLE_BREW_VISION_EFFECT, true);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_brewfest_botm_jungle_madness::HandleAfterCast);
    }
};

enum BinaryBrew
{
    SPELL_LEARN_GNOMISH_BINARY      = 50242,
    SPELL_LEARN_GOBLIN_BINARY       = 50246
};

// 50243 - Teach Language
class spell_brewfest_botm_teach_language : public SpellScript
{
    PrepareSpellScript(spell_brewfest_botm_teach_language);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_LEARN_GNOMISH_BINARY, SPELL_LEARN_GOBLIN_BINARY });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Player* caster = GetCaster()->ToPlayer())
            caster->CastSpell(caster, caster->GetTeam() == ALLIANCE ? SPELL_LEARN_GNOMISH_BINARY : SPELL_LEARN_GOBLIN_BINARY, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_brewfest_botm_teach_language::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum CreateEmptyBrewBottle
{
    SPELL_BOTM_CREATE_EMPTY_BREW_BOTTLE    = 51655
};

// 42254, 42255, 42256, 42257, 42258, 42259, 42260, 42261, 42263, 42264, 43959, 43961 - Weak Alcohol
class spell_brewfest_botm_weak_alcohol : public SpellScript
{
    PrepareSpellScript(spell_brewfest_botm_weak_alcohol);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BOTM_CREATE_EMPTY_BREW_BOTTLE });
    }

    void HandleAfterCast()
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_BOTM_CREATE_EMPTY_BREW_BOTTLE, true);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_brewfest_botm_weak_alcohol::HandleAfterCast);
    }
};

enum EmptyBottleThrow
{
    SPELL_BOTM_EMPTY_BOTTLE_THROW_IMPACT_CREATURE    = 51695,   // Just unit, not creature
    SPELL_BOTM_EMPTY_BOTTLE_THROW_IMPACT_GROUND      = 51697
};

// 51694 - BOTM - Empty Bottle Throw - Resolve
class spell_brewfest_botm_empty_bottle_throw_resolve : public SpellScript
{
    PrepareSpellScript(spell_brewfest_botm_empty_bottle_throw_resolve);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_BOTM_EMPTY_BOTTLE_THROW_IMPACT_CREATURE,
            SPELL_BOTM_EMPTY_BOTTLE_THROW_IMPACT_GROUND
        });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();

        if (Unit* target = GetHitUnit())
            caster->CastSpell(target, SPELL_BOTM_EMPTY_BOTTLE_THROW_IMPACT_CREATURE, true);
        else
            caster->CastSpell(GetHitDest()->GetPosition(), SPELL_BOTM_EMPTY_BOTTLE_THROW_IMPACT_GROUND, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_brewfest_botm_empty_bottle_throw_resolve::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_event_brewfest()
{
    RegisterSpellScript(spell_brewfest_giddyup);
    RegisterSpellScript(spell_brewfest_ram);
    RegisterSpellScript(spell_brewfest_ram_fatigue);
    RegisterSpellScript(spell_brewfest_apple_trap);
    RegisterSpellScript(spell_brewfest_exhausted_ram);
    RegisterSpellScript(spell_brewfest_relay_race_intro_force_player_to_throw);
    RegisterSpellScript(spell_brewfest_relay_race_turn_in);
    RegisterSpellScript(spell_brewfest_dismount_ram);
    RegisterSpellScript(spell_brewfest_barker_bunny);
    RegisterSpellScript(spell_brewfest_mount_transformation);
    RegisterSpellScript(spell_brewfest_botm_the_beast_within);
    RegisterSpellScript(spell_brewfest_botm_gassy);
    RegisterSpellScript(spell_brewfest_botm_bloated);
    RegisterSpellScript(spell_brewfest_botm_internal_combustion);
    RegisterSpellScript(spell_brewfest_botm_jungle_madness);
    RegisterSpellScript(spell_brewfest_botm_teach_language);
    RegisterSpellScript(spell_brewfest_botm_weak_alcohol);
    RegisterSpellScript(spell_brewfest_botm_empty_bottle_throw_resolve);
}
