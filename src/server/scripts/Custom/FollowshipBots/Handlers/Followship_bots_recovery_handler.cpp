/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
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
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Containers.h"
#include "Log.h"

#include "Followship_bots_mgr.h"
#include "Followship_bots_utils.h"

#include "Followship_bots_druid.h"

#include "Followship_bots_chatter_handler.h"
#include "GenAI_chatter_prompts.h"
#include "Followship_bots_dungeon_handler.h"
#include "Followship_bots_events_handler.h"
#include "Followship_bots_movement_handler.h"
#include "Followship_bots_recovery_handler.h"

namespace FSBRecovery
{
    BotRecoveryIntent DetermineRecoveryIntent(Creature* bot)
    {
        if (!bot)
            return BotRecoveryIntent::None;

        //TC_LOG_DEBUG("scripts.ai.fsb", "FSB: RecoveryHandler TryRecover intent check for: {}", bot->GetName());

        bool inDungeon = FSBDungeon::IsBotInDungeon(bot);
        float hpThreshold = inDungeon ? DungeonHpRecoveryThreshold : DefaultHpRecoveryThreshold;
        float manaThreshold = inDungeon ? DungeonManaRecoveryThreshold : DefaultManaRecoveryThreshold;

        bool lowHP = bot->GetHealthPct() < hpThreshold;

        // Determine if this bot uses mana at all
        bool usesMana = bot->GetMaxPower(POWER_MANA) > 0;

        // Druid shapeshifts (bear/cat) use rage/energy, not mana
        if (bot->HasAura(SPELL_DRUID_BEAR) || bot->HasAura(SPELL_DRUID_CAT))
            usesMana = false;

        bool lowMana = false;
        if (usesMana)
            lowMana = bot->GetPowerPct(POWER_MANA) < manaThreshold;

        if (lowHP && lowMana)
            return BotRecoveryIntent::RecoverHealthAndMana;

        if (lowHP)
            return BotRecoveryIntent::RecoverHealth;

        if (lowMana)
            return BotRecoveryIntent::RecoverMana;

        return BotRecoveryIntent::None;
    }

    BotRecoverAction GetRecoveryAction(Creature* bot, BotRecoveryIntent intent)
    {
        if (!bot || intent == BotRecoveryIntent::None)
            return BotRecoverAction::None;

        FSB_Class botClass = FSBMgr::Get()->GetBotClassForEntry(bot->GetEntry());
        FSB_Race botRace = FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry());

        std::vector<BotRecoverAction> recoveryActions;

        bool isBearOrCat = bot->HasAura(SPELL_DRUID_BEAR) || bot->HasAura(SPELL_DRUID_CAT);

        switch (intent)
        {
        case BotRecoveryIntent::RecoverHealth:
            recoveryActions.emplace_back(BotRecoverAction::Eat);

            if (!isBearOrCat)
            {
                recoveryActions.emplace_back(BotRecoverAction::Recuperate);

                if (FSBUtils::BotIsHealerClass(bot))
                    recoveryActions.emplace_back(BotRecoverAction::ClassHeal);
                if (botClass == FSB_Class::Mage)
                    recoveryActions.emplace_back(BotRecoverAction::ClassDrinkEat);

                if (botRace == FSB_Race::Draenei)
                    recoveryActions.emplace_back(BotRecoverAction::RaceHeal);
            }
            break;
        case BotRecoveryIntent::RecoverMana:
            if (!isBearOrCat)
            {
                recoveryActions.emplace_back(BotRecoverAction::Drink);
                if (botClass == FSB_Class::Mage)
                    recoveryActions.emplace_back(BotRecoverAction::ClassDrinkEat);
            }
            break;
        case BotRecoveryIntent::RecoverHealthAndMana:
            if (!isBearOrCat)
            {
                recoveryActions.emplace_back(BotRecoverAction::DrinkEat);
                if (botClass == FSB_Class::Mage)
                    recoveryActions.emplace_back(BotRecoverAction::ClassDrinkEat);
            }
            break;
        default:
            recoveryActions.emplace_back(BotRecoverAction::None);
        }

        if (recoveryActions.empty())
            return BotRecoverAction::None;

        return Trinity::Containers::SelectRandomContainerElement(recoveryActions);
    }

    void MarkRecoveryStarted(Creature* bot, uint32 duration)
    {
        if (!bot)
            return;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return;

        baseAI->botGenericData.isRecovering = true;
        FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_RECOVERY_END, std::chrono::milliseconds(duration));
    }

    bool BotActionDrinkEat(Creature* bot, uint32& globalCooldown, uint32& outSpell, uint8 drinkOrEat)
    {
        if (!bot)
            return false;

        if (bot->IsInCombat())
            return false;

        if (!bot->IsAlive())
            return false;

        uint32 now = getMSTime();

        uint32 spellId = 0;

        FSB_Class botClass = FSBMgr::Get()->GetBotClassForEntry(bot->GetEntry());
        FSB_Race botRace = FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry());

        if (drinkOrEat == DRINK_EAT)
        {
            if (bot->HasAura(SPELL_DRINK_CONJURED_CRYSTAL_WATER) || bot->HasAura(SPELL_FOOD_SCALED_WITH_LVL))
                return false;

            FSBMovement::StopFollow(bot);

            SpellCastResult result = bot->CastSpell(bot, SPELL_DRINK_CONJURED_CRYSTAL_WATER, false);
            SpellCastResult result2 = bot->CastSpell(bot, SPELL_FOOD_SCALED_WITH_LVL, false);

            if (result == SPELL_CAST_OK && result2 == SPELL_CAST_OK)
            {
                globalCooldown = now + 30000; // set cooldown to 30s to not interrup the drink spell which lasts 30 seconds max
                outSpell = RAND(SPELL_DRINK_CONJURED_CRYSTAL_WATER, SPELL_FOOD_SCALED_WITH_LVL);
                MarkRecoveryStarted(bot, globalCooldown - now);
                return true;
            }
        }

        if (drinkOrEat == DRINK)
        {
            spellId = SPELL_DRINK_CONJURED_CRYSTAL_WATER;

            if (bot->HasAura(spellId))
                return false;

            FSBMovement::StopFollow(bot);

            SpellCastResult result = bot->CastSpell(bot, spellId, false);

            if (result == SPELL_CAST_OK)
            {
                globalCooldown = now + 30000; // set cooldown to 30s to not interrup the drink spell which lasts 30 seconds max
                outSpell = spellId;
                MarkRecoveryStarted(bot, globalCooldown - now);
                return true;
            }
        }

        if (drinkOrEat == EAT)
        {
            spellId = SPELL_FOOD_SCALED_WITH_LVL;

            if (bot->HasAura(spellId))
                return false;

            FSBMovement::StopFollow(bot);

            SpellCastResult result = bot->CastSpell(bot, spellId, false);

            if (result == SPELL_CAST_OK)
            {
                globalCooldown = now + 30000; // set cooldown to 30s to not interrup the drink spell which lasts 30 seconds max
                outSpell = spellId;
                MarkRecoveryStarted(bot, globalCooldown - now);
                return true;
            }
        }

        if (drinkOrEat == CLASS_DRINK_EAT)
        {
            if (botClass == FSB_Class::Mage)
                spellId = SPELL_MAGE_CONJURED_MANA_PUDDING;
            else return false;

            if (bot->HasAura(spellId))
                return false;

            FSBMovement::StopFollow(bot);

            SpellCastResult result = bot->CastSpell(bot, spellId, false);

            if (result == SPELL_CAST_OK)
            {
                globalCooldown = now + 30000; // set cooldown to 30s to not interrup the drink spell which lasts 30 seconds max
                outSpell = spellId;
                MarkRecoveryStarted(bot, globalCooldown - now);
                return true;
            }
        }

        if (drinkOrEat == RECUPERATE)
        {
            spellId = SPELL_RECUPERATE;

            if (bot->HasAura(spellId))
                return false;

            FSBMovement::StopFollow(bot);

            SpellCastResult result = bot->CastSpell(bot, spellId, false);

            if (result == SPELL_CAST_OK)
            {
                globalCooldown = now + 10000; // set cooldown to 30s to not interrup the drink spell which lasts 30 seconds max
                outSpell = spellId;
                MarkRecoveryStarted(bot, globalCooldown - now);
                return true;
            }
        }

        if (drinkOrEat == CLASS_HEAL)
        {
            if (botClass == FSB_Class::Priest)
                spellId = RAND(SPELL_PRIEST_HEAL, SPELL_PRIEST_FLASH_HEAL);
            else if (botClass == FSB_Class::Paladin)
                spellId = RAND(SPELL_PALADIN_HOLY_LIGHT, SPELL_PALADIN_FLASH_OF_LIGHT);
            else if (botClass == FSB_Class::Druid)
                spellId = RAND(SPELL_DRUID_REGROWTH, SPELL_DRUID_REJUVENATION, SPELL_DRUID_LIFEBLOOM);
            else if (botClass == FSB_Class::Shaman)
                spellId = RAND(uint32(SPELL_SHAMAN_HEALING_SURGE), uint32(SPELL_SHAMAN_HEALING_STREAM_TOTEM), uint32(SPELL_SHAMAN_HEALING_TIDE_TOTEM));
            else if (botClass == FSB_Class::Monk)
                spellId = SPELL_MONK_VIVIFY;
            else return false;

            if (bot->HasAura(spellId))
                return false;

            FSBMovement::StopFollow(bot);

            SpellCastResult result = bot->CastSpell(bot, spellId, false);

            if (result == SPELL_CAST_OK)
            {
                globalCooldown = now + 1500; // set cooldown to 30s to not interrup the drink spell which lasts 30 seconds max
                outSpell = spellId;
                MarkRecoveryStarted(bot, globalCooldown - now);
                return true;
            }
        }

        if (drinkOrEat == RACE_HEAL)
        {
            if (botRace == FSB_Race::Draenei)
                spellId = SPELL_DRAENEI_GIFT_NAARU;
            else return false;

            if (bot->HasAura(spellId))
                return false;

            FSBMovement::StopFollow(bot);

            SpellCastResult result = bot->CastSpell(bot, spellId, false);

            if (result == SPELL_CAST_OK)
            {
                TC_LOG_DEBUG("scripts.fsb.ooc", "FSB: RecoveryAction Race Heal cast result: {}", result);
                globalCooldown = now + 1500; // set cooldown to 30s to not interrup the drink spell which lasts 30 seconds max
                outSpell = spellId;
                MarkRecoveryStarted(bot, globalCooldown - now);
                return true;
            }
            else TC_LOG_DEBUG("scripts.fsb.ooc", "FSB: RecoveryAction Race Heal cast result not ok: {}", result);
        }

        return false;
    }

    bool TryRecoverAction(Creature* bot, BotRecoverAction action, uint32& globalCooldown)
    {
        if (!bot)
            return false;

        if (bot->IsInCombat())
            return false;

        if (!bot->IsAlive())
            return false;

        if (bot->HasAura(SPELL_DRUID_TRAVEL) || bot->HasAuraType(SPELL_AURA_MOUNTED))
            return false;

        // Bears and Cats can only eat to recover health; drinking/ClassHeal/Recuperate breaks the shapeshift.
        if ((bot->HasAura(SPELL_DRUID_BEAR) || bot->HasAura(SPELL_DRUID_CAT)) && action != BotRecoverAction::Eat)
            return false;

        bool check = false;
        uint32 spellId = 0;
        uint8 drinkOrEat = 0;

        switch (action)
        {
        case BotRecoverAction::None:
            return false;
        case BotRecoverAction::DrinkEat:
            drinkOrEat = DRINK_EAT;
            if (BotActionDrinkEat(bot, globalCooldown, spellId, drinkOrEat))
                check = true;
            break;
        case BotRecoverAction::Drink:
            drinkOrEat = DRINK;
            if (BotActionDrinkEat(bot, globalCooldown, spellId, drinkOrEat))
                check = true;
            break;
        case BotRecoverAction::ClassDrinkEat:
            drinkOrEat = CLASS_DRINK_EAT;
            if (BotActionDrinkEat(bot, globalCooldown, spellId, drinkOrEat))
                check = true;
            break;
        case BotRecoverAction::Eat:
            drinkOrEat = EAT;
            if (BotActionDrinkEat(bot, globalCooldown, spellId, drinkOrEat))
                check = true;
            break;
        case BotRecoverAction::Recuperate:
            drinkOrEat = RECUPERATE;
            if (BotActionDrinkEat(bot, globalCooldown, spellId, drinkOrEat))
                check = true;
            break;
        case BotRecoverAction::ClassHeal:
            drinkOrEat = CLASS_HEAL;
            if (BotActionDrinkEat(bot, globalCooldown, spellId, drinkOrEat))
                check = true;
            break;
        case BotRecoverAction::RaceHeal:
            drinkOrEat = RACE_HEAL;
            if (BotActionDrinkEat(bot, globalCooldown, spellId, drinkOrEat))
                check = true;
            break;
        default:
            break;
        }

        if (check)
        {
            if (urand(0, 99) <= FollowshipBotsConfig::configFSBChatterRate)
                FSBGenAIPrompts::DispatchBotRecovery(bot, spellId);

            uint32 now = getMSTime();
            FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_HIRED_RESUME_FOLLOW, std::chrono::milliseconds(globalCooldown - now));

            return true;
        }

        return false;

    }

    bool TryOOCRecovery(Creature* bot, BotRecoveryIntent intent, uint32& globalCooldown)
    {
        if (!bot)
            return false;

        if (bot->IsInCombat())
            return false;

        if (!bot->IsAlive())
            return false;

        if (intent == BotRecoveryIntent::None)
            return false;


        BotRecoverAction action = GetRecoveryAction(bot, intent);
        
        if (TryRecoverAction(bot, action, globalCooldown))
            return true;

        return false;
    }

    int32 GetDrinkFoodPerLevel(uint8 level, DrinkFoodPerLevel const* table, size_t tableSize)
    {
        for (size_t i = 0; i < tableSize; ++i)
        {
            if (level >= table[i].minLevel && level <= table[i].maxLevel)
                return table[i].value;
        }

        return 0;
    }

    // Wrapper for GetDrinkFoodPerLevel
    int32 GetDrinkFood(uint16 level)
    {
        return GetDrinkFoodPerLevel(
            level,
            DrinkFoodTable,
            std::size(DrinkFoodTable)
        );
    }

    bool BotHasRecoveryActive(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI()))
            if (baseAI->botGenericData.isRecovering)
                return true;

        return bot->HasAura(SPELL_FOOD_SCALED_WITH_LVL)
            || bot->HasAura(SPELL_MAGE_CONJURED_MANA_PUDDING)
            || bot->HasAura(SPELL_DRINK_CONJURED_CRYSTAL_WATER)
            || bot->HasAura(SPELL_RECUPERATE);
    }

    void BotCancelRecoveryAtFull(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->ToCreature()->AI());
        if (!baseAI)
            return;

        if (!BotHasRecoveryActive(bot))
            return;

        bool fullMana = bot->GetPowerType() == POWER_MANA && bot->GetPowerPct(POWER_MANA) >= 100.0f;
        bool fullHealth = bot->GetHealthPct() >= 100.0f;

        if (fullMana)
            bot->RemoveAurasDueToSpell(SPELL_DRINK_CONJURED_CRYSTAL_WATER);

        if (fullHealth)
            bot->RemoveAurasDueToSpell(SPELL_FOOD_SCALED_WITH_LVL);

        // Mage pudding restores both; only cancel when both resources are full
        if (fullMana && fullHealth)
            bot->RemoveAurasDueToSpell(SPELL_MAGE_CONJURED_MANA_PUDDING);

        if (!BotHasRecoveryActive(bot))
        {
            baseAI->botGenericData.isRecovering = false;
            FSBMovement::ResumeFollow(bot, baseAI->botFollowDistance, baseAI->botFollowAngle);
        }
    }
}
