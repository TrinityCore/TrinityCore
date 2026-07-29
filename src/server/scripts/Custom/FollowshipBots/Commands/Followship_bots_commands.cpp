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
#include "Pet.h"
#include "SpellAuras.h"
#include "WorldSession.h"

#include "Followship_bots_mgr.h"
#include "Followship_bots_utils.h"

#include "Followship_bots_outofcombat_handler.h"
#include "Followship_bots_pet_handler.h"
#include "Followship_bots_utils_spells.h"

using namespace Trinity::ChatCommands;

class followship_bots_commandscript : public CommandScript
{
public:
    followship_bots_commandscript() : CommandScript("followship_bots_commandscript") { }

    std::span<ChatCommandBuilder const> GetCommands() const override
    {
        static ChatCommandTable fsbCommandTable =
        {
            { "info",      HandleFSBInfo,            rbac::RBAC_PERM_COMMAND_GM, Console::No },
            { "afkaction", HandleFSBAfkAction,       rbac::RBAC_PERM_COMMAND_GM, Console::No },
            { "playsound", HandleFSBPlaySound,       rbac::RBAC_PERM_COMMAND_GM, Console::No },
            { "summonpet", HandleFSBSummonPet,       rbac::RBAC_PERM_COMMAND_GM, Console::No },
            { "castSpell", HandleFSBCastSpellOnTarget, rbac::RBAC_PERM_COMMAND_GM, Console::No },
        };

        static ChatCommandTable commandTable =
        {
            { "fsb", fsbCommandTable }
        };



        return commandTable;
    }

    static bool HandleFSBInfo(ChatHandler* handler)
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

        // --- Fetch bot metadata ---
        FSB_Class botClass = FSBMgr::Get()->GetBotClassForEntry(bot->GetEntry());
        FSB_Race botRace = FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry());

        

        handler->PSendSysMessage("=== Followship Bot Info ===");
        handler->PSendSysMessage("Name: %s", bot->GetName().c_str());
        handler->PSendSysMessage("Level: %u", bot->GetLevel());
        handler->PSendSysMessage("Class: %s", FSBUtils::BotClassToString(botClass));
        handler->PSendSysMessage("Race: %s", FSBUtils::BotRaceToString(botRace));

        if (auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI()))
            handler->PSendSysMessage("Role: %s", FSBUtils::BotRoleToString(baseAI->botRole));

        handler->PSendSysMessage("Attack Power: %.1f and Ranged Attack Power: %.1f ", bot->GetTotalAttackPowerValue(BASE_ATTACK), bot->GetTotalAttackPowerValue(RANGED_ATTACK));

        handler->PSendSysMessage("Damage: Base: %.1f Min: %.1f Max: %.1f", bot->GetBaseDamageForLevel(bot->GetLevel()), bot->GetWeaponDamageRange(BASE_ATTACK, MINDAMAGE), bot->GetWeaponDamageRange(BASE_ATTACK, MAXDAMAGE));
        handler->PSendSysMessage("Ranged Damage: Base: %.1f Min: %.1f Max: %.1f", bot->GetBaseDamageForLevel(bot->GetLevel()), bot->GetWeaponDamageRange(RANGED_ATTACK, MINDAMAGE), bot->GetWeaponDamageRange(RANGED_ATTACK, MAXDAMAGE));
        handler->PSendSysMessage("Offhand Damage: Base: %.1f Min: %.1f Max: %.1f", bot->GetBaseDamageForLevel(bot->GetLevel()), bot->GetWeaponDamageRange(OFF_ATTACK, MINDAMAGE), bot->GetWeaponDamageRange(OFF_ATTACK, MAXDAMAGE));
        handler->PSendSysMessage("Mainhand DMG mod: Base: %.1f, Mod: %.1f, BasePct: %.1f, ModPct: %.1f",
            bot->GetFlatModifierValue(UNIT_MOD_DAMAGE_MAINHAND, BASE_VALUE),
            bot->GetFlatModifierValue(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_VALUE),
            bot->GetPctModifierValue(UNIT_MOD_DAMAGE_MAINHAND, BASE_PCT),
            bot->GetPctModifierValue(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_PCT));

        handler->PSendSysMessage("In Combat: %s", bot->IsInCombat() ? "Yes" : "No");

        return true;
    }

    static bool HandleFSBAfkAction(ChatHandler* handler)
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

        // --- Fetch bot metadata ---
        handler->PSendSysMessage("=== Followship Bot Random AFK Action ===");
        handler->PSendSysMessage("Returned: %s", FSBOOC::BotOOCActionPlayerAFK(bot, true) ? "true" : "false");

        return true;
    }

    static bool HandleFSBPlaySound(ChatHandler* handler, uint32 soundId)
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

        // --- Fetch bot metadata ---
        handler->PSendSysMessage("=== Followship Bot Play Sound ID ===");
        handler->PSendSysMessage("Playing Sound Id: %u", soundId);

        bot->PlayDistanceSound(soundId, handler->GetPlayer());

        return true;
    }

    static bool HandleFSBSummonPet(ChatHandler* handler)
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

        // --- Fetch bot metadata ---
        handler->PSendSysMessage("=== Followship Bot Summon Pet ===");

        FSBPet::BotSummonPet(bot);
        
        return true;
    }

    static bool HandleFSBCastSpellOnTarget(ChatHandler* handler, uint32 spellId, std::string name)
    {
        Creature* target = handler->getSelectedCreature();

        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Creature* bot = target->ToCreature();

        // --- Fetch bot metadata ---
        handler->PSendSysMessage("=== Followship Bot Cast Spell On Target ===");
        Unit* spellTarget = FSBUtils::FindCreatureByName(bot, name);
        if (!spellTarget)
        {
            handler->PSendSysMessage("Cast Failed: Target Not Found");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if(!spellId)
        {
            handler->PSendSysMessage("Cast Failed: No valid spell id");
            handler->SetSentErrorMessage(true);
            return false;
        }

        SpellCastResult result = FSBSpells::BotCastSpellWithResult(bot, spellId, spellTarget);
        if (result == SPELL_CAST_OK)
        {
            handler->PSendSysMessage("Cast Success");
            TC_LOG_DEBUG("scripts.fsb.command", "FSB Command: Bot {} cast spell {} on target {} successfully", bot->GetName(), spellId, spellTarget->GetName());
        }
        else
        {
            std::string resultString = FSBSpellsUtils::GetSpellCastResultString(result);
            handler->PSendSysMessage("Cast Failed: %u (%s)", result, resultString.c_str());
            TC_LOG_DEBUG("scripts.fsb.command", "FSB Command: Bot {} failed to cast spell {} on target {} with result {} ({})", bot->GetName(), spellId, spellTarget->GetName(), result, resultString);
            handler->SetSentErrorMessage(true);
            return false;
        }

        return true;
    }

};

void AddSC_followship_bots_commandscript()
{
    new followship_bots_commandscript();
}
