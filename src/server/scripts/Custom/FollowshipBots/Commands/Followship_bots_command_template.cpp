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
#include "DatabaseEnv.h"
#include "Log.h"
#include "WorldSession.h"

#include "Followship_bots_mgr.h"
#include "Followship_bots_utils.h"
#include "FollowshipDatabase.h"
#include "WorldDatabase.h"

using namespace Trinity::ChatCommands;

class followship_bots_template_commandscript : public CommandScript
{
public:
    followship_bots_template_commandscript() : CommandScript("followship_bots_template_commandscript") { }

    std::span<ChatCommandBuilder const> GetCommands() const override
    {
        static ChatCommandTable templateCommandTable =
        {
            { "add",    HandleFSBTemplateAdd,    rbac::RBAC_PERM_COMMAND_GM, Console::No },
            { "remove", HandleFSBTemplateRemove, rbac::RBAC_PERM_COMMAND_GM, Console::No },
        };

        static ChatCommandTable fsbCommandTable =
        {
            { "template", templateCommandTable }
        };

        static ChatCommandTable commandTable =
        {
            { "fsb", fsbCommandTable }
        };

        return commandTable;
    }

    static bool HandleFSBTemplateAdd(ChatHandler* handler, int32 botClass, int32 botRace, int32 botGender, uint32 companionSpell, uint32 petSource)
    {
        Creature* target = handler->getSelectedCreature();

        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (target->IsBot())
        {
            handler->SendSysMessage("Target is already a Followship bot. Select a regular NPC.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 entry = target->GetEntry();

        if (FSBMgr::Get()->HasBotTemplate(entry))
        {
            handler->PSendSysMessage("Bot template for entry %u already exists.", entry);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (botClass < static_cast<int32>(FSB_Class::Warrior) || botClass > static_cast<int32>(FSB_Class::DeathKnight))
        {
            handler->SendSysMessage("Invalid bot class value.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (botRace < static_cast<int32>(FSB_Race::Human) || botRace > static_cast<int32>(FSB_Race::HaranirHorde))
        {
            handler->SendSysMessage("Invalid bot race value.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (botGender < 0 || botGender > 2)
        {
            handler->SendSysMessage("Invalid gender value (0 = Male, 1 = Female, 2 = Unknown).");
            handler->SetSentErrorMessage(true);
            return false;
        }

        FSB_ChatterType chatterType = static_cast<FSB_ChatterType>(urand(1, 20));

        FSBEntryRaceClassMap data;
        data.entry = entry;
        data.botClass = static_cast<FSB_Class>(botClass);
        data.botRace = static_cast<FSB_Race>(botRace);
        data.companionSpell = companionSpell;
        data.chatterType = chatterType;
        data.gender = static_cast<Gender>(botGender);
        data.petSource = petSource;

        FollowshipDatabasePreparedStatement* stmt = FollowshipDatabase.GetPreparedStatement(FSB_INS_BOT_TEMPLATE);
        stmt->setUInt32(0, entry);
        stmt->setInt8(1, static_cast<int8>(botClass));
        stmt->setInt8(2, static_cast<int8>(botRace));
        stmt->setUInt32(3, companionSpell);
        stmt->setUInt8(4, static_cast<uint8>(chatterType));
        stmt->setInt8(5, static_cast<int8>(botGender));
        stmt->setUInt32(6, petSource);
        FollowshipDatabase.Execute(stmt);

        WorldDatabasePreparedStatement* worldStmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_CREATURE_TEMPLATE_SCRIPTNAME);
        worldStmt->setString(0, std::string("npc_followship_bots"));
        worldStmt->setUInt32(1, entry);
        WorldDatabase.Execute(worldStmt);

        FSBMgr::Get()->AddBotTemplate(data);

        handler->PSendSysMessage("Bot template added for entry %u (Class: %s, Race: %s, Gender: %s, Chatter: %s).",
            entry,
            FSBUtils::BotClassToString(data.botClass),
            FSBUtils::BotRaceToString(data.botRace),
            botGender == 0 ? "Male" : (botGender == 1 ? "Female" : "Unknown"),
            FSBUtils::ChatterTypeToString(chatterType));

        TC_LOG_INFO("scripts.fsb.command", "FSB Command: Template added for entry %u by player %s",
            entry, handler->GetPlayer()->GetName().c_str());

        return true;
    }

    static bool HandleFSBTemplateRemove(ChatHandler* handler)
    {
        Creature* target = handler->getSelectedCreature();

        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!target->IsBot())
        {
            handler->SendSysMessage("Target is not a Followship bot. Select a bot to remove its template.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 entry = target->GetEntry();

        if (!FSBMgr::Get()->HasBotTemplate(entry))
        {
            handler->PSendSysMessage("No bot template found for entry %u.", entry);
            handler->SetSentErrorMessage(true);
            return false;
        }

        FollowshipDatabasePreparedStatement* stmt = FollowshipDatabase.GetPreparedStatement(FSB_DEL_BOT_TEMPLATE);
        stmt->setUInt32(0, entry);
        FollowshipDatabase.Execute(stmt);

        WorldDatabasePreparedStatement* worldStmt = WorldDatabase.GetPreparedStatement(WORLD_UPD_CREATURE_TEMPLATE_SCRIPTNAME);
        worldStmt->setString(0, std::string());
        worldStmt->setUInt32(1, entry);
        WorldDatabase.Execute(worldStmt);

        FSBMgr::Get()->RemoveBotTemplate(entry);

        handler->PSendSysMessage("Bot template removed for entry %u.", entry);

        TC_LOG_INFO("scripts.fsb.command", "FSB Command: Template removed for entry %u by player %s",
            entry, handler->GetPlayer()->GetName().c_str());

        return true;
    }
};

void AddSC_followship_bots_command_template()
{
    new followship_bots_template_commandscript();
}
