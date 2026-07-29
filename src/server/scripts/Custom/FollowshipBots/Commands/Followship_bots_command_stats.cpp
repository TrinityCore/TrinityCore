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

#include "Chat.h"
#include "ChatCommand.h"
#include "Log.h"

#include "Followship_bots_mgr.h"
#include "Followship_bots_utils.h"
#include "Followship_bots_stats_handler.h"

using namespace Trinity::ChatCommands;

class followship_bots_stats_commandscript : public CommandScript
{
public:
    followship_bots_stats_commandscript() : CommandScript("followship_bots_stats_commandscript") { }

    std::span<ChatCommandBuilder const> GetCommands() const override
    {
        static ChatCommandTable statsCommandTable =
        {
            { "recalculate", HandleFSBStatsRecalculate, rbac::RBAC_PERM_COMMAND_GM, Console::No },
            { "damage",      HandleFSBDamage,           rbac::RBAC_PERM_COMMAND_GM, Console::No },
            { "",            HandleFSBStats,            rbac::RBAC_PERM_COMMAND_GM, Console::No },
        };

        static ChatCommandTable fsbCommandTable =
        {
            { "stats", statsCommandTable }
        };

        static ChatCommandTable commandTable =
        {
            { "fsb", fsbCommandTable }
        };

        return commandTable;
    }

    static bool HandleFSBStats(ChatHandler* handler)
    {
        Creature* target = handler->getSelectedCreature();

        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Creature* bot = target->ToCreature();
        if (!bot || !bot->IsBot())
        {
            handler->SendSysMessage("Target is not a Followship bot.");
            return false;
        }

        handler->PSendSysMessage("=== Followship Bot Stats ===");

        float baseHealth = bot->GetFlatModifierValue(UNIT_MOD_HEALTH, BASE_VALUE);
        float totalHealth = bot->GetTotalAuraModValue(UNIT_MOD_HEALTH);

        handler->PSendSysMessage("Health: Base: %.1f Max: %.1f (%.1f%%)", baseHealth, totalHealth, bot->GetHealthPct());

        Powers powerType = bot->GetPowerType();

        float currentPower = bot->GetPower(powerType);
        float maxPower = bot->GetMaxPower(powerType);
        float basePower = bot->GetFlatModifierValue(UnitMods(UNIT_MOD_POWER_START + AsUnderlyingType(powerType)), BASE_VALUE);
        float totalPower = bot->GetTotalAuraModValue(UnitMods(UNIT_MOD_POWER_START + AsUnderlyingType(powerType)));

        handler->PSendSysMessage("Power (%s): Base %u / %u", FSBUtils::PowerTypeToString(powerType), (int32)basePower, (int32)totalPower);
        handler->PSendSysMessage("Current Power (%s): Now %u / Max %u", FSBUtils::PowerTypeToString(powerType), (int32)currentPower, (int32)maxPower);


        float baseArmor = bot->GetFlatModifierValue(UNIT_MOD_ARMOR, BASE_VALUE);
        float totalArmor = bot->GetTotalAuraModValue(UNIT_MOD_ARMOR);

        handler->PSendSysMessage("Armor: Base: %.1f, Total: %.1f, Bonus: %.1f", baseArmor, totalArmor, totalArmor - baseArmor);

        return true;
    }

    static bool HandleFSBDamage(ChatHandler* handler)
    {
        Creature* target = handler->getSelectedCreature();

        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Creature* bot = target->ToCreature();
        if (!bot || !bot->IsBot())
        {
            handler->SendSysMessage("Target is not a Followship bot.");
            return false;
        }

        uint8 level = bot->GetLevel();
        uint8 eLevel = bot->GetLevelForTarget(handler->GetPlayer());

        handler->PSendSysMessage("=== Followship Bot Damage Stats ===");
        handler->PSendSysMessage("Bot %s with level: %u and effective level: %u", bot->GetName(), level, eLevel);

        float totalAttackPower = bot->GetTotalAttackPowerValue(BASE_ATTACK);
        float base_attPower = float(bot->GetTotalAttackPowerValue(BASE_ATTACK, false));

        handler->PSendSysMessage("Attack Power: Base %.1f / Total %.1f", base_attPower, totalAttackPower);

        float totalRAttackPower = bot->GetTotalAttackPowerValue(RANGED_ATTACK);
        float base_RattPower = float(bot->GetTotalAttackPowerValue(RANGED_ATTACK, false));

        handler->PSendSysMessage("Ranged Attack Power: Base %.1f / Total %.1f", base_RattPower, totalRAttackPower);

        float weaponDamageMin = bot->GetWeaponDamageRange(BASE_ATTACK, MINDAMAGE);
        float weaponDamageMax = bot->GetWeaponDamageRange(BASE_ATTACK, MAXDAMAGE);

        float basedamageL = bot->GetBaseDamageForLevel(level);
        float basedamageEL = bot->GetBaseDamageForLevel(eLevel);

        handler->PSendSysMessage("Weapon Damage: Min %.1f / Max %.1f", weaponDamageMin, weaponDamageMax);
        handler->PSendSysMessage("Base Damage: Level %.1f / E Level %.1f", basedamageL, basedamageEL);

        int32 spellPower = FSBStats::BotGetSpellPower(bot);
        handler->PSendSysMessage("Spell Power: %u", spellPower);

        return true;
    }

    static bool HandleFSBStatsRecalculate(ChatHandler* handler)
    {
        Creature* target = handler->getSelectedCreature();

        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Creature* bot = target->ToCreature();
        if (!bot || !bot->IsBot())
        {
            handler->SendSysMessage("Target is not a Followship bot.");
            return false;
        }

        FSBStats::RecalculateStats(bot, true, true);

        handler->PSendSysMessage("Stats recalculated for bot %s.", bot->GetName());

        return true;
    }
};

void AddSC_followship_bots_command_stats()
{
    new followship_bots_stats_commandscript();
}
