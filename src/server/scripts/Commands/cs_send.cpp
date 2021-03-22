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
#include "Chat.h"
#include "DatabaseEnv.h"
#include "Item.h"
#include "Language.h"
#include "Mail.h"
#include "ObjectMgr.h"
#include "Pet.h"
#include "Player.h"
#include "RBAC.h"
#include "WorldSession.h"

class send_commandscript : public CommandScript
{
public:
    send_commandscript() : CommandScript("send_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> sendCommandTable =
        {
            { "items",   rbac::RBAC_PERM_COMMAND_SEND_ITEMS,   true, &HandleSendItemsCommand,   "" },
            { "mail",    rbac::RBAC_PERM_COMMAND_SEND_MAIL,    true, &HandleSendMailCommand,    "" },
            { "message", rbac::RBAC_PERM_COMMAND_SEND_MESSAGE, true, &HandleSendMessageCommand, "" },
            { "money",   rbac::RBAC_PERM_COMMAND_SEND_MONEY,   true, &HandleSendMoneyCommand,   "" },
        };

        static std::vector<ChatCommand> commandTable =
        {
            { "send", rbac::RBAC_PERM_COMMAND_SEND, false, nullptr, "", sendCommandTable },
        };
        return commandTable;
    }

    // Send mail by command
    static bool HandleSendMailCommand(ChatHandler* handler, char const* args)
    {
        // format: name "subject text" "mail text"
        Player* target;
        ObjectGuid targetGuid;
        std::string targetName;
        if (!handler->extractPlayerTarget((char*)args, &target, &targetGuid, &targetName))
            return false;

        char* tail1 = strtok(nullptr, "");
        if (!tail1)
            return false;

        char const* msgSubject = handler->extractQuotedArg(tail1);
        if (!msgSubject)
            return false;

        char* tail2 = strtok(nullptr, "");
        if (!tail2)
            return false;

        char const* msgText = handler->extractQuotedArg(tail2);
        if (!msgText)
            return false;

        // msgSubject, msgText isn't NUL after prev. check
        std::string subject = msgSubject;
        std::string text    = msgText;

        // from console, use non-existing sender
        MailSender sender(MAIL_NORMAL, handler->GetSession() ? handler->GetSession()->GetPlayer()->GetGUID().GetCounter() : UI64LIT(0), MAIL_STATIONERY_GM);

        /// @todo Fix poor design
        CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
        MailDraft(subject, text)
            .SendMailTo(trans, MailReceiver(target, targetGuid.GetCounter()), sender);

        CharacterDatabase.CommitTransaction(trans);

        std::string nameLink = handler->playerLink(targetName);
        handler->PSendSysMessage(LANG_MAIL_SENT, nameLink.c_str());
        return true;
    }

    // Send items by mail
    static bool HandleSendItemsCommand(ChatHandler* handler, char const* args)
    {
        // format: name "subject text" "mail text" item1[:count1] item2[:count2] ... item12[:count12]
        Player* receiver;
        ObjectGuid receiverGuid;
        std::string receiverName;
        if (!handler->extractPlayerTarget((char*)args, &receiver, &receiverGuid, &receiverName))
            return false;

        char* tail1 = strtok(nullptr, "");
        if (!tail1)
            return false;

        char const* msgSubject = handler->extractQuotedArg(tail1);
        if (!msgSubject)
            return false;

        char* tail2 = strtok(nullptr, "");
        if (!tail2)
            return false;

        char const* msgText = handler->extractQuotedArg(tail2);
        if (!msgText)
            return false;

        // msgSubject, msgText isn't NUL after prev. check
        std::string subject = msgSubject;
        std::string text    = msgText;

        // extract items
        typedef std::pair<uint32, uint32> ItemPair;
        typedef std::list< ItemPair > ItemPairs;
        ItemPairs items;

        // get all tail string
        char* tail = strtok(nullptr, "");

        // get from tail next item str
        while (char* itemStr = strtok(tail, " "))
        {
            // and get new tail
            tail = strtok(nullptr, "");

            // parse item str
            char const* itemIdStr = strtok(itemStr, ":");
            char const* itemCountStr = strtok(nullptr, " ");

            uint32 itemId = atoul(itemIdStr);
            if (!itemId)
                return false;

            ItemTemplate const* item_proto = sObjectMgr->GetItemTemplate(itemId);
            if (!item_proto)
            {
                handler->PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, itemId);
                handler->SetSentErrorMessage(true);
                return false;
            }

            uint32 itemCount = itemCountStr ? atoi(itemCountStr) : 1;
            if (itemCount < 1 || (item_proto->GetMaxCount() > 0 && itemCount > uint32(item_proto->GetMaxCount())))
            {
                handler->PSendSysMessage(LANG_COMMAND_INVALID_ITEM_COUNT, itemCount, itemId);
                handler->SetSentErrorMessage(true);
                return false;
            }

            while (itemCount > item_proto->GetMaxStackSize())
            {
                items.push_back(ItemPair(itemId, item_proto->GetMaxStackSize()));
                itemCount -= item_proto->GetMaxStackSize();
            }

            items.push_back(ItemPair(itemId, itemCount));

            if (items.size() > MAX_MAIL_ITEMS)
            {
                handler->PSendSysMessage(LANG_COMMAND_MAIL_ITEMS_LIMIT, MAX_MAIL_ITEMS);
                handler->SetSentErrorMessage(true);
                return false;
            }
        }

        // from console show nonexisting sender
        MailSender sender(MAIL_NORMAL, handler->GetSession() ? handler->GetSession()->GetPlayer()->GetGUID().GetCounter() : UI64LIT(0), MAIL_STATIONERY_GM);

        // fill mail
        MailDraft draft(subject, text);

        CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

        for (ItemPairs::const_iterator itr = items.begin(); itr != items.end(); ++itr)
        {
            if (Item* item = Item::CreateItem(itr->first, itr->second, ItemContext::NONE, handler->GetSession() ? handler->GetSession()->GetPlayer() : nullptr))
            {
                item->SaveToDB(trans);              // Save to prevent being lost at next mail load. If send fails, the item will be deleted.
                draft.AddItem(item);
            }
        }

        draft.SendMailTo(trans, MailReceiver(receiver, receiverGuid.GetCounter()), sender);
        CharacterDatabase.CommitTransaction(trans);

        std::string nameLink = handler->playerLink(receiverName);
        handler->PSendSysMessage(LANG_MAIL_SENT, nameLink.c_str());
        return true;
    }
    /// Send money by mail
    static bool HandleSendMoneyCommand(ChatHandler* handler, char const* args)
    {
        /// format: name "subject text" "mail text" money

        Player* receiver;
        ObjectGuid receiverGuid;
        std::string receiverName;
        if (!handler->extractPlayerTarget((char*)args, &receiver, &receiverGuid, &receiverName))
            return false;

        char* tail1 = strtok(nullptr, "");
        if (!tail1)
            return false;

        char* msgSubject = handler->extractQuotedArg(tail1);
        if (!msgSubject)
            return false;

        char* tail2 = strtok(nullptr, "");
        if (!tail2)
            return false;

        char* msgText = handler->extractQuotedArg(tail2);
        if (!msgText)
            return false;

        char* moneyStr = strtok(nullptr, "");
        int64 money = moneyStr ? atoll(moneyStr) : 0;
        if (money <= 0)
            return false;

        // msgSubject, msgText isn't NUL after prev. check
        std::string subject = msgSubject;
        std::string text    = msgText;

        // from console show nonexisting sender
        MailSender sender(MAIL_NORMAL, handler->GetSession() ? handler->GetSession()->GetPlayer()->GetGUID().GetCounter() : UI64LIT(0), MAIL_STATIONERY_GM);

        CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

        MailDraft(subject, text)
            .AddMoney(money)
            .SendMailTo(trans, MailReceiver(receiver, receiverGuid.GetCounter()), sender);

        CharacterDatabase.CommitTransaction(trans);

        std::string nameLink = handler->playerLink(receiverName);
        handler->PSendSysMessage(LANG_MAIL_SENT, nameLink.c_str());
        return true;
    }
    /// Send a message to a player in game
    static bool HandleSendMessageCommand(ChatHandler* handler, char const* args)
    {
        /// - Find the player
        Player* player;
        if (!handler->extractPlayerTarget((char*)args, &player))
            return false;

        char* msgStr = strtok(nullptr, "");
        if (!msgStr)
            return false;

        /// - Check if player is logging out.
        if (player->GetSession()->isLogingOut())
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        /// - Send the message
        player->GetSession()->SendNotification("%s", msgStr);
        player->GetSession()->SendNotification("|cffff0000[Message from administrator]:|r");

        // Confirmation message
        std::string nameLink = handler->GetNameLink(player);
        handler->PSendSysMessage(LANG_SENDMESSAGE, nameLink.c_str(), msgStr);

        return true;
    }
};

void AddSC_send_commandscript()
{
    new send_commandscript();
}
