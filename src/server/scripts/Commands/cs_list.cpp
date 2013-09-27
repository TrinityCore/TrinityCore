/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

/* ScriptData
Name: list_commandscript
%Complete: 100
Comment: All list related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Chat.h"
#include "SpellAuraEffects.h"
#include "Language.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include <iostream>

class list_commandscript : public CommandScript
{
public:
    list_commandscript() : CommandScript("list_commandscript") { }

    ChatCommand* GetCommands() const OVERRIDE
    {
        static ChatCommand listCommandTable[] =
        {
            { "creature", rbac::RBAC_PERM_COMMAND_LIST_CREATURE, true, &HandleListCreatureCommand, "", NULL },
            { "item",     rbac::RBAC_PERM_COMMAND_LIST_ITEM,     true, &HandleListItemCommand,     "", NULL },
            { "object",   rbac::RBAC_PERM_COMMAND_LIST_OBJECT,   true, &HandleListObjectCommand,   "", NULL },
            { "auras",    rbac::RBAC_PERM_COMMAND_LIST_AURAS,   false, &HandleListAurasCommand,    "", NULL },
            { "mail",     rbac::RBAC_PERM_COMMAND_LIST_MAIL,     true, &HandleListMailCommand,     "", NULL },
            { NULL,       0,                              false, NULL,                       "", NULL }
        };
        static ChatCommand commandTable[] =
        {
            { "list", rbac::RBAC_PERM_COMMAND_LIST,true, NULL, "", listCommandTable },
            { NULL,   0,                    false, NULL, "", NULL }
        };
        return commandTable;
    }

    static bool HandleListCreatureCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        // number or [name] Shift-click form |color|Hcreature_entry:creature_id|h[name]|h|r
        char* id = handler->extractKeyFromLink((char*)args, "Hcreature_entry");
        if (!id)
            return false;

        uint32 creatureId = atol(id);
        if (!creatureId)
        {
            handler->PSendSysMessage(LANG_COMMAND_INVALIDCREATUREID, creatureId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        CreatureTemplate const* cInfo = sObjectMgr->GetCreatureTemplate(creatureId);
        if (!cInfo)
        {
            handler->PSendSysMessage(LANG_COMMAND_INVALIDCREATUREID, creatureId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        char* countStr = strtok(NULL, " ");
        uint32 count = countStr ? atol(countStr) : 10;

        if (count == 0)
            return false;

        QueryResult result;

        uint32 creatureCount = 0;
        result = WorldDatabase.PQuery("SELECT COUNT(guid) FROM creature WHERE id='%u'", creatureId);
        if (result)
            creatureCount = (*result)[0].GetUInt64();

        if (handler->GetSession())
        {
            Player* player = handler->GetSession()->GetPlayer();
            result = WorldDatabase.PQuery("SELECT guid, position_x, position_y, position_z, map, (POW(position_x - '%f', 2) + POW(position_y - '%f', 2) + POW(position_z - '%f', 2)) AS order_ FROM creature WHERE id = '%u' ORDER BY order_ ASC LIMIT %u",
                player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), creatureId, count);
        }
        else
            result = WorldDatabase.PQuery("SELECT guid, position_x, position_y, position_z, map FROM creature WHERE id = '%u' LIMIT %u",
                creatureId, count);

        if (result)
        {
            do
            {
                Field* fields   = result->Fetch();
                uint32 guid     = fields[0].GetUInt32();
                float x         = fields[1].GetFloat();
                float y         = fields[2].GetFloat();
                float z         = fields[3].GetFloat();
                uint16 mapId    = fields[4].GetUInt16();

                if (handler->GetSession())
                    handler->PSendSysMessage(LANG_CREATURE_LIST_CHAT, guid, guid, cInfo->Name.c_str(), x, y, z, mapId);
                else
                    handler->PSendSysMessage(LANG_CREATURE_LIST_CONSOLE, guid, cInfo->Name.c_str(), x, y, z, mapId);
            }
            while (result->NextRow());
        }

        handler->PSendSysMessage(LANG_COMMAND_LISTCREATUREMESSAGE, creatureId, creatureCount);

        return true;
    }

    static bool HandleListItemCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* id = handler->extractKeyFromLink((char*)args, "Hitem");
        if (!id)
            return false;

        uint32 itemId = atol(id);
        if (!itemId)
        {
            handler->PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, itemId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(itemId);
        if (!itemTemplate)
        {
            handler->PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, itemId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        char* countStr = strtok(NULL, " ");
        uint32 count = countStr ? atol(countStr) : 10;

        if (count == 0)
            return false;

        PreparedQueryResult result;

        // inventory case
        uint32 inventoryCount = 0;

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_INVENTORY_COUNT_ITEM);
        stmt->setUInt32(0, itemId);
        result = CharacterDatabase.Query(stmt);

        if (result)
            inventoryCount = (*result)[0].GetUInt64();

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_INVENTORY_ITEM_BY_ENTRY);
        stmt->setUInt32(0, itemId);
        stmt->setUInt32(1, count);
        result = CharacterDatabase.Query(stmt);

        if (result)
        {
            do
            {
                Field* fields           = result->Fetch();
                uint32 itemGuid         = fields[0].GetUInt32();
                uint32 itemBag          = fields[1].GetUInt32();
                uint8 itemSlot          = fields[2].GetUInt8();
                uint32 ownerGuid        = fields[3].GetUInt32();
                uint32 ownerAccountId   = fields[4].GetUInt32();
                std::string ownerName   = fields[5].GetString();

                char const* itemPos = 0;
                if (Player::IsEquipmentPos(itemBag, itemSlot))
                    itemPos = "[equipped]";
                else if (Player::IsInventoryPos(itemBag, itemSlot))
                    itemPos = "[in inventory]";
                else if (Player::IsBankPos(itemBag, itemSlot))
                    itemPos = "[in bank]";
                else
                    itemPos = "";

                handler->PSendSysMessage(LANG_ITEMLIST_SLOT, itemGuid, ownerName.c_str(), ownerGuid, ownerAccountId, itemPos);
            }
            while (result->NextRow());

            uint32 resultCount = uint32(result->GetRowCount());

            if (count > resultCount)
                count -= resultCount;
            else if (count)
                count = 0;
        }

        // mail case
        uint32 mailCount = 0;

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_MAIL_COUNT_ITEM);
        stmt->setUInt32(0, itemId);
        result = CharacterDatabase.Query(stmt);

        if (result)
            mailCount = (*result)[0].GetUInt64();

        if (count > 0)
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_MAIL_ITEMS_BY_ENTRY);
            stmt->setUInt32(0, itemId);
            stmt->setUInt32(1, count);
            result = CharacterDatabase.Query(stmt);
        }
        else
            result = PreparedQueryResult(NULL);

        if (result)
        {
            do
            {
                Field* fields                   = result->Fetch();
                uint32 itemGuid                 = fields[0].GetUInt32();
                uint32 itemSender               = fields[1].GetUInt32();
                uint32 itemReceiver             = fields[2].GetUInt32();
                uint32 itemSenderAccountId      = fields[3].GetUInt32();
                std::string itemSenderName      = fields[4].GetString();
                uint32 itemReceiverAccount      = fields[5].GetUInt32();
                std::string itemReceiverName    = fields[6].GetString();

                char const* itemPos = "[in mail]";

                handler->PSendSysMessage(LANG_ITEMLIST_MAIL, itemGuid, itemSenderName.c_str(), itemSender, itemSenderAccountId, itemReceiverName.c_str(), itemReceiver, itemReceiverAccount, itemPos);
            }
            while (result->NextRow());

            uint32 resultCount = uint32(result->GetRowCount());

            if (count > resultCount)
                count -= resultCount;
            else if (count)
                count = 0;
        }

        // auction case
        uint32 auctionCount = 0;

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_AUCTIONHOUSE_COUNT_ITEM);
        stmt->setUInt32(0, itemId);
        result = CharacterDatabase.Query(stmt);

        if (result)
            auctionCount = (*result)[0].GetUInt64();

        if (count > 0)
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_AUCTIONHOUSE_ITEM_BY_ENTRY);
            stmt->setUInt32(0, itemId);
            stmt->setUInt32(1, count);
            result = CharacterDatabase.Query(stmt);
        }
        else
            result = PreparedQueryResult(NULL);

        if (result)
        {
            do
            {
                Field* fields           = result->Fetch();
                uint32 itemGuid         = fields[0].GetUInt32();
                uint32 owner            = fields[1].GetUInt32();
                uint32 ownerAccountId   = fields[2].GetUInt32();
                std::string ownerName   = fields[3].GetString();

                char const* itemPos = "[in auction]";

                handler->PSendSysMessage(LANG_ITEMLIST_AUCTION, itemGuid, ownerName.c_str(), owner, ownerAccountId, itemPos);
            }
            while (result->NextRow());
        }

        // guild bank case
        uint32 guildCount = 0;

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GUILD_BANK_COUNT_ITEM);
        stmt->setUInt32(0, itemId);
        result = CharacterDatabase.Query(stmt);

        if (result)
            guildCount = (*result)[0].GetUInt64();

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GUILD_BANK_ITEM_BY_ENTRY);
        stmt->setUInt32(0, itemId);
        stmt->setUInt32(1, count);
        result = CharacterDatabase.Query(stmt);

        if (result)
        {
            do
            {
                Field* fields = result->Fetch();
                uint32 itemGuid = fields[0].GetUInt32();
                uint32 guildGuid = fields[1].GetUInt32();
                std::string guildName = fields[2].GetString();

                char const* itemPos = "[in guild bank]";

                handler->PSendSysMessage(LANG_ITEMLIST_GUILD, itemGuid, guildName.c_str(), guildGuid, itemPos);
            }
            while (result->NextRow());

            uint32 resultCount = uint32(result->GetRowCount());

            if (count > resultCount)
                count -= resultCount;
            else if (count)
                count = 0;
        }

        if (inventoryCount + mailCount + auctionCount + guildCount == 0)
        {
            handler->SendSysMessage(LANG_COMMAND_NOITEMFOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage(LANG_COMMAND_LISTITEMMESSAGE, itemId, inventoryCount + mailCount + auctionCount + guildCount, inventoryCount, mailCount, auctionCount, guildCount);

        return true;
    }

    static bool HandleListObjectCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        // number or [name] Shift-click form |color|Hgameobject_entry:go_id|h[name]|h|r
        char* id = handler->extractKeyFromLink((char*)args, "Hgameobject_entry");
        if (!id)
            return false;

        uint32 gameObjectId = atol(id);
        if (!gameObjectId)
        {
            handler->PSendSysMessage(LANG_COMMAND_LISTOBJINVALIDID, gameObjectId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        GameObjectTemplate const* gInfo = sObjectMgr->GetGameObjectTemplate(gameObjectId);
        if (!gInfo)
        {
            handler->PSendSysMessage(LANG_COMMAND_LISTOBJINVALIDID, gameObjectId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        char* countStr = strtok(NULL, " ");
        uint32 count = countStr ? atol(countStr) : 10;

        if (count == 0)
            return false;

        QueryResult result;

        uint32 objectCount = 0;
        result = WorldDatabase.PQuery("SELECT COUNT(guid) FROM gameobject WHERE id='%u'", gameObjectId);
        if (result)
            objectCount = (*result)[0].GetUInt64();

        if (handler->GetSession())
        {
            Player* player = handler->GetSession()->GetPlayer();
            result = WorldDatabase.PQuery("SELECT guid, position_x, position_y, position_z, map, id, (POW(position_x - '%f', 2) + POW(position_y - '%f', 2) + POW(position_z - '%f', 2)) AS order_ FROM gameobject WHERE id = '%u' ORDER BY order_ ASC LIMIT %u",
                player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), gameObjectId, count);
        }
        else
            result = WorldDatabase.PQuery("SELECT guid, position_x, position_y, position_z, map, id FROM gameobject WHERE id = '%u' LIMIT %u",
                gameObjectId, count);

        if (result)
        {
            do
            {
                Field* fields   = result->Fetch();
                uint32 guid     = fields[0].GetUInt32();
                float x         = fields[1].GetFloat();
                float y         = fields[2].GetFloat();
                float z         = fields[3].GetFloat();
                uint16 mapId    = fields[4].GetUInt16();
                uint32 entry    = fields[5].GetUInt32();

                if (handler->GetSession())
                    handler->PSendSysMessage(LANG_GO_LIST_CHAT, guid, entry, guid, gInfo->name.c_str(), x, y, z, mapId);
                else
                    handler->PSendSysMessage(LANG_GO_LIST_CONSOLE, guid, gInfo->name.c_str(), x, y, z, mapId);
            }
            while (result->NextRow());
        }

        handler->PSendSysMessage(LANG_COMMAND_LISTOBJMESSAGE, gameObjectId, objectCount);

        return true;
    }

    static bool HandleListAurasCommand(ChatHandler* handler, char const* /*args*/)
    {
        Unit* unit = handler->getSelectedUnit();
        if (!unit)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        char const* talentStr = handler->GetTrinityString(LANG_TALENT);
        char const* passiveStr = handler->GetTrinityString(LANG_PASSIVE);

        Unit::AuraApplicationMap const& auras = unit->GetAppliedAuras();
        handler->PSendSysMessage(LANG_COMMAND_TARGET_LISTAURAS, auras.size());
        for (Unit::AuraApplicationMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
        {
            bool talent = GetTalentSpellCost(itr->second->GetBase()->GetId()) > 0;

            AuraApplication const* aurApp = itr->second;
            Aura const* aura = aurApp->GetBase();
            char const* name = aura->GetSpellInfo()->SpellName[handler->GetSessionDbcLocale()];

            std::ostringstream ss_name;
            ss_name << "|cffffffff|Hspell:" << aura->GetId() << "|h[" << name << "]|h|r";

            handler->PSendSysMessage(LANG_COMMAND_TARGET_AURADETAIL, aura->GetId(), (handler->GetSession() ? ss_name.str().c_str() : name),
                aurApp->GetEffectMask(), aura->GetCharges(), aura->GetStackAmount(), aurApp->GetSlot(),
                aura->GetDuration(), aura->GetMaxDuration(), (aura->IsPassive() ? passiveStr : ""),
                (talent ? talentStr : ""), IS_PLAYER_GUID(aura->GetCasterGUID()) ? "player" : "creature",
                GUID_LOPART(aura->GetCasterGUID()));
        }

        for (uint16 i = 0; i < TOTAL_AURAS; ++i)
        {
            Unit::AuraEffectList const& auraList = unit->GetAuraEffectsByType(AuraType(i));
            if (auraList.empty())
                continue;

            handler->PSendSysMessage(LANG_COMMAND_TARGET_LISTAURATYPE, auraList.size(), i);

            for (Unit::AuraEffectList::const_iterator itr = auraList.begin(); itr != auraList.end(); ++itr)
                handler->PSendSysMessage(LANG_COMMAND_TARGET_AURASIMPLE, (*itr)->GetId(), (*itr)->GetEffIndex(), (*itr)->GetAmount());
        }

        return true;
    }
    // handle list mail command
    static bool HandleListMailCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        uint64 targetGuid;
        std::string targetName;

        if (!*args)
            return false;

        uint32 parseGUID = MAKE_NEW_GUID(atol((char*)args), 0, HIGHGUID_PLAYER);

        if (sObjectMgr->GetPlayerNameByGUID(parseGUID, targetName))
        {
            target = sObjectMgr->GetPlayerByLowGUID(parseGUID);
            targetGuid = parseGUID;
        }
        else if (!handler->extractPlayerTarget((char*)args, &target, &targetGuid, &targetName))
            return false;

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_MAIL_LIST_COUNT);
        stmt->setUInt32(0, targetGuid);
        PreparedQueryResult result = CharacterDatabase.Query(stmt);
        if (result)
        {
            Field* fields = result->Fetch();
            uint32 countMail = fields[0].GetUInt64();
            std::string nameLink = handler->playerLink(targetName);
            handler->PSendSysMessage(LANG_LIST_MAIL_HEADER, countMail, nameLink.c_str(), targetGuid);
            handler->PSendSysMessage(LANG_ACCOUNT_LIST_BAR);
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_MAIL_LIST_INFO);
            stmt->setUInt32(0, targetGuid);
            PreparedQueryResult result = CharacterDatabase.Query(stmt);
            if (result)
            {
                do
                {
                    Field* fields           = result->Fetch();
                    uint32 messageId        = fields[0].GetUInt32();
                    uint32 senderId         = fields[1].GetUInt32();
                    std::string sender      = fields[2].GetString();
                    uint32 receiverId       = fields[3].GetUInt32();
                    std::string receiver    = fields[4].GetString();
                    std::string subject     = fields[5].GetString();
                    uint64 deliverTime      = fields[6].GetUInt32();
                    uint64 expireTime       = fields[7].GetUInt32();
                    uint32 money            = fields[8].GetUInt32();
                    int hasItem             = fields[9].GetUInt8();
                    uint32 gold = money /GOLD;
                    uint32 silv = (money % GOLD) / SILVER;
                    uint32 copp = (money % GOLD) % SILVER;
                    std::string receiverStr = handler->playerLink(receiver);
                    std::string senderStr = handler->playerLink(sender);
                    handler->PSendSysMessage(LANG_LIST_MAIL_INFO_1, messageId, subject.c_str(), gold, silv, copp);
                    handler->PSendSysMessage(LANG_LIST_MAIL_INFO_2, senderStr.c_str(), senderId, receiverStr.c_str(), receiverId);
                    handler->PSendSysMessage(LANG_LIST_MAIL_INFO_3, TimeToTimestampStr(deliverTime).c_str(), TimeToTimestampStr(expireTime).c_str());
                    if (hasItem == 1)
                    {
                        QueryResult result2;
                        result2 = CharacterDatabase.PQuery("SELECT item_guid FROM mail_items WHERE mail_id = '%u'", messageId);
                        if (result2)
                        {
                            do
                            {
                                uint32 item_guid        = (*result2)[0].GetUInt32();
                                PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_MAIL_LIST_ITEMS);
                                stmt->setUInt32(0, item_guid);
                                PreparedQueryResult result3 = CharacterDatabase.Query(stmt);
                                if (result3)
                                {
                                    do
                                    {
                                        Field* fields           = result3->Fetch();
                                        uint32 item_entry       = fields[0].GetUInt32();
                                        uint32 item_count       = fields[1].GetUInt32();
                                        QueryResult result4;
                                        result4 = WorldDatabase.PQuery("SELECT name, quality FROM item_template WHERE entry = '%u'", item_entry);
                                        Field* fields1          = result4->Fetch();
                                        std::string item_name   = fields1[0].GetString();
                                        int item_quality        = fields1[1].GetUInt8();
                                        if (handler->GetSession())
                                        {
                                            uint32 color = ItemQualityColors[item_quality];
                                            std::ostringstream itemStr;
                                            itemStr << "|c" << std::hex << color << "|Hitem:" << item_entry << ":0:0:0:0:0:0:0:0:0|h[" << item_name << "]|h|r";
                                            handler->PSendSysMessage(LANG_LIST_MAIL_INFO_ITEM, itemStr.str().c_str(), item_entry, item_guid, item_count);
                                        }
                                        else
                                            handler->PSendSysMessage(LANG_LIST_MAIL_INFO_ITEM, item_name.c_str(), item_entry, item_guid, item_count);
                                    }
                                    while (result3->NextRow());
                                }
                            }
                            while (result2->NextRow());
                        }
                    }
                    handler->PSendSysMessage(LANG_ACCOUNT_LIST_BAR);
                }
                while (result->NextRow());
            }
            else
                handler->PSendSysMessage(LANG_LIST_MAIL_NOT_FOUND);
            return true;
        }
        else
            handler->PSendSysMessage(LANG_LIST_MAIL_NOT_FOUND);
        return true;
    }
};

void AddSC_list_commandscript()
{
    new list_commandscript();
}
