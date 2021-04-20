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

/* ScriptData
Name: list_commandscript
%Complete: 100
Comment: All list related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "CharacterCache.h"
#include "Chat.h"
#include "Creature.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "GameObject.h"
#include "GameTime.h"
#include "Language.h"
#include "MapManager.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "Random.h"
#include "RBAC.h"
#include "SpellAuraEffects.h"
#include "WorldSession.h"

using namespace Trinity::ChatCommands;

class list_commandscript : public CommandScript
{
public:
    list_commandscript() : CommandScript("list_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable listAurasCommandTable =
        {
            { "",               HandleListAllAurasCommand,      rbac::RBAC_PERM_COMMAND_LIST_AURAS,         Console::No  },
            { "id",             HandleListAurasByIdCommand,     rbac::RBAC_PERM_COMMAND_LIST_AURAS,         Console::No  },
            { "name",           HandleListAurasByNameCommand,   rbac::RBAC_PERM_COMMAND_LIST_AURAS,         Console::No  },
        };

        static ChatCommandTable listCommandTable =
        {
            { "creature",       HandleListCreatureCommand,      rbac::RBAC_PERM_COMMAND_LIST_CREATURE,      Console::Yes },
            { "item",           HandleListItemCommand,          rbac::RBAC_PERM_COMMAND_LIST_ITEM,          Console::Yes },
            { "object",         HandleListObjectCommand,        rbac::RBAC_PERM_COMMAND_LIST_OBJECT,        Console::Yes },
            { "auras",          listAurasCommandTable                                                                    },
            { "mail",           HandleListMailCommand,          rbac::RBAC_PERM_COMMAND_LIST_MAIL,          Console::Yes },
            { "spawnpoints",    HandleListSpawnPointsCommand,   rbac::RBAC_PERM_COMMAND_LIST_SPAWNPOINTS,   Console::No  },
            { "respawns",       HandleListRespawnsCommand,      rbac::RBAC_PERM_COMMAND_LIST_RESPAWNS,      Console::No  },
        };
        static ChatCommandTable commandTable =
        {
            { "list", listCommandTable },
        };
        return commandTable;
    }

    static bool HandleListCreatureCommand(ChatHandler* handler, Variant<Hyperlink<creature_entry>, uint32> creatureId, Optional<uint32> countArg)
    {
        CreatureTemplate const* cInfo = sObjectMgr->GetCreatureTemplate(creatureId);
        if (!cInfo)
        {
            handler->PSendSysMessage(LANG_COMMAND_INVALIDCREATUREID, creatureId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 count = countArg.value_or(10);

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
                ObjectGuid::LowType guid = fields[0].GetUInt32();
                float x         = fields[1].GetFloat();
                float y         = fields[2].GetFloat();
                float z         = fields[3].GetFloat();
                uint16 mapId    = fields[4].GetUInt16();
                bool liveFound = false;

                // Get map (only support base map from console)
                Map* thisMap;
                if (handler->GetSession())
                    thisMap = handler->GetSession()->GetPlayer()->GetMap();
                else
                    thisMap = sMapMgr->FindBaseNonInstanceMap(mapId);

                // If map found, try to find active version of this creature
                if (thisMap)
                {
                    auto const creBounds = thisMap->GetCreatureBySpawnIdStore().equal_range(guid);
                    if (creBounds.first != creBounds.second)
                    {
                        for (std::unordered_multimap<uint32, Creature*>::const_iterator itr = creBounds.first; itr != creBounds.second;)
                        {
                            if (handler->GetSession())
                                handler->PSendSysMessage(LANG_CREATURE_LIST_CHAT, guid, guid, cInfo->Name.c_str(), x, y, z, mapId, itr->second->GetGUID().ToString().c_str(), itr->second->IsAlive() ? "*" : " ");
                            else
                                handler->PSendSysMessage(LANG_CREATURE_LIST_CONSOLE, guid, cInfo->Name.c_str(), x, y, z, mapId, itr->second->GetGUID().ToString().c_str(), itr->second->IsAlive() ? "*" : " ");
                            ++itr;
                        }
                        liveFound = true;
                    }
                }

                if (!liveFound)
                {
                    if (handler->GetSession())
                        handler->PSendSysMessage(LANG_CREATURE_LIST_CHAT, guid, guid, cInfo->Name.c_str(), x, y, z, mapId, "", "");
                    else
                        handler->PSendSysMessage(LANG_CREATURE_LIST_CONSOLE, guid, cInfo->Name.c_str(), x, y, z, mapId, "", "");
                }
            }
            while (result->NextRow());
        }

        handler->PSendSysMessage(LANG_COMMAND_LISTCREATUREMESSAGE, creatureId, creatureCount);

        return true;
    }

    static bool HandleListItemCommand(ChatHandler* handler, Hyperlink<item> item, Optional<uint32> countArg)
    {
        uint32 itemId = item->Item->ItemId;
        uint32 count = countArg.value_or(10);

        if (count == 0)
            return false;

        PreparedQueryResult result;

        // inventory case
        uint32 inventoryCount = 0;

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_INVENTORY_COUNT_ITEM);
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

                char const* itemPos = nullptr;
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
            else
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
            result = PreparedQueryResult(nullptr);

        if (result)
        {
            do
            {
                Field* fields                   = result->Fetch();
                ObjectGuid::LowType itemGuid                 = fields[0].GetUInt32();
                ObjectGuid::LowType itemSender               = fields[1].GetUInt32();
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
            else
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
            result = PreparedQueryResult(nullptr);

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
            else
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

    static bool HandleListObjectCommand(ChatHandler* handler, Variant<Hyperlink<gameobject_entry>, uint32> gameObjectId, Optional<uint32> countArg)
    {
        GameObjectTemplate const* gInfo = sObjectMgr->GetGameObjectTemplate(gameObjectId);
        if (!gInfo)
        {
            handler->PSendSysMessage(LANG_COMMAND_LISTOBJINVALIDID, gameObjectId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 count = countArg.value_or(10);

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
                ObjectGuid::LowType guid = fields[0].GetUInt32();
                float x         = fields[1].GetFloat();
                float y         = fields[2].GetFloat();
                float z         = fields[3].GetFloat();
                uint16 mapId    = fields[4].GetUInt16();
                uint32 entry    = fields[5].GetUInt32();
                bool liveFound = false;

                // Get map (only support base map from console)
                Map* thisMap;
                if (handler->GetSession())
                    thisMap = handler->GetSession()->GetPlayer()->GetMap();
                else
                    thisMap = sMapMgr->FindBaseNonInstanceMap(mapId);

                // If map found, try to find active version of this object
                if (thisMap)
                {
                    auto const goBounds = thisMap->GetGameObjectBySpawnIdStore().equal_range(guid);
                    if (goBounds.first != goBounds.second)
                    {
                        for (std::unordered_multimap<uint32, GameObject*>::const_iterator itr = goBounds.first; itr != goBounds.second;)
                        {
                            if (handler->GetSession())
                                handler->PSendSysMessage(LANG_GO_LIST_CHAT, guid, entry, guid, gInfo->name.c_str(), x, y, z, mapId, itr->second->GetGUID().ToString().c_str(), itr->second->isSpawned() ? "*" : " ");
                            else
                                handler->PSendSysMessage(LANG_GO_LIST_CONSOLE, guid, gInfo->name.c_str(), x, y, z, mapId, itr->second->GetGUID().ToString().c_str(), itr->second->isSpawned() ? "*" : " ");
                            ++itr;
                        }
                        liveFound = true;
                    }
                }

                if (!liveFound)
                {
                    if (handler->GetSession())
                        handler->PSendSysMessage(LANG_GO_LIST_CHAT, guid, entry, guid, gInfo->name.c_str(), x, y, z, mapId, "", "");
                    else
                        handler->PSendSysMessage(LANG_GO_LIST_CONSOLE, guid, gInfo->name.c_str(), x, y, z, mapId, "", "");
                }
            }
            while (result->NextRow());
        }

        handler->PSendSysMessage(LANG_COMMAND_LISTOBJMESSAGE, gameObjectId, objectCount);

        return true;
    }

    static bool HandleListAllAurasCommand(ChatHandler* handler)
    {
        return ListAurasCommand(handler, {}, {});
    }

    static bool HandleListAurasByIdCommand(ChatHandler* handler, uint32 spellId)
    {
        return ListAurasCommand(handler, spellId, {});
    }

    static bool HandleListAurasByNameCommand(ChatHandler* handler, WTail namePart)
    {
        return ListAurasCommand(handler, {}, namePart);
    }

    static bool ListAurasCommand(ChatHandler* handler, Optional<uint32> spellId, std::wstring namePart)
    {
        Unit* unit = handler->getSelectedUnit();
        if (!unit)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        wstrToLower(namePart);

        char const* talentStr = handler->GetTrinityString(LANG_TALENT);
        char const* passiveStr = handler->GetTrinityString(LANG_PASSIVE);

        Unit::AuraApplicationMap const& auras = unit->GetAppliedAuras();
        handler->PSendSysMessage(LANG_COMMAND_TARGET_LISTAURAS, auras.size());
        for (auto const& [aurId, aurApp] : auras)
        {
            bool talent = GetTalentSpellCost(aurApp->GetBase()->GetId()) > 0;

            Aura const* aura = aurApp->GetBase();
            char const* name = aura->GetSpellInfo()->SpellName[handler->GetSessionDbcLocale()];

            if (!ShouldListAura(aura->GetSpellInfo(), spellId, namePart, handler->GetSessionDbcLocale()))
                continue;

            std::ostringstream ss_name;
            ss_name << "|cffffffff|Hspell:" << aura->GetId() << "|h[" << name << "]|h|r";

            handler->PSendSysMessage(LANG_COMMAND_TARGET_AURADETAIL, aura->GetId(), (handler->GetSession() ? ss_name.str().c_str() : name),
                aurApp->GetEffectMask(), aura->GetCharges(), aura->GetStackAmount(), aurApp->GetSlot(),
                aura->GetDuration(), aura->GetMaxDuration(), (aura->IsPassive() ? passiveStr : ""),
                (talent ? talentStr : ""), aura->GetCasterGUID().IsPlayer() ? "player" : "creature",
                aura->GetCasterGUID().GetCounter());
        }

        for (uint16 i = 0; i < TOTAL_AURAS; ++i)
        {
            Unit::AuraEffectList const& auraList = unit->GetAuraEffectsByType(AuraType(i));
            if (auraList.empty())
                continue;

            bool sizeLogged = false;

            for (AuraEffect const* effect : auraList)
            {
                if (!ShouldListAura(effect->GetSpellInfo(), spellId, namePart, handler->GetSessionDbcLocale()))
                    continue;

                if (!sizeLogged)
                {
                    sizeLogged = true;
                    handler->PSendSysMessage(LANG_COMMAND_TARGET_LISTAURATYPE, auraList.size(), i);
                }

                handler->PSendSysMessage(LANG_COMMAND_TARGET_AURASIMPLE, effect->GetId(), effect->GetEffIndex(), effect->GetAmount());
            }
        }

        return true;
    }

    static bool ShouldListAura(SpellInfo const* spellInfo, Optional<uint32> spellId, std::wstring namePart, uint8 locale)
    {
        if (spellId)
            return spellInfo->Id == spellId;

        if (!namePart.empty())
        {
            std::string name = spellInfo->SpellName[locale];
            return Utf8FitTo(name, namePart);
        }

        return true;
    }

    // handle list mail command
    static bool HandleListMailCommand(ChatHandler* handler, Optional<PlayerIdentifier> player)
    {
        if (!player)
            player = PlayerIdentifier::FromTargetOrSelf(handler);
        if (!player)
            return false;

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_MAIL_LIST_COUNT);
        stmt->setUInt32(0, player->GetGUID().GetCounter());
        PreparedQueryResult queryResult = CharacterDatabase.Query(stmt);
        if (queryResult)
        {
            Field* fields       = queryResult->Fetch();
            uint32 countMail    = fields[0].GetUInt64();

            std::string nameLink = handler->playerLink(player->GetName());
            handler->PSendSysMessage(LANG_LIST_MAIL_HEADER, countMail, nameLink.c_str(), player->GetGUID().GetCounter());
            handler->PSendSysMessage(LANG_ACCOUNT_LIST_BAR);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_MAIL_LIST_INFO);
            stmt->setUInt32(0, player->GetGUID().GetCounter());
            queryResult = CharacterDatabase.Query(stmt);

            if (queryResult)
            {
                do
                {
                    Field* queryFields      = queryResult->Fetch();
                    uint32 messageId        = queryFields[0].GetUInt32();
                    uint32 senderId         = queryFields[1].GetUInt32();
                    std::string sender      = queryFields[2].GetString();
                    uint32 receiverId       = queryFields[3].GetUInt32();
                    std::string receiver    = queryFields[4].GetString();
                    std::string subject     = queryFields[5].GetString();
                    uint64 deliverTime      = queryFields[6].GetUInt32();
                    uint64 expireTime       = queryFields[7].GetUInt32();
                    uint32 money            = queryFields[8].GetUInt32();
                    uint8 hasItem           = queryFields[9].GetUInt8();
                    uint32 gold = money / GOLD;
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
                                ObjectGuid::LowType item_guid = (*result2)[0].GetUInt32();
                                stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_MAIL_LIST_ITEMS);
                                stmt->setUInt32(0, item_guid);
                                PreparedQueryResult result3 = CharacterDatabase.Query(stmt);
                                if (result3)
                                {
                                    do
                                    {
                                        Field* fields3          = result3->Fetch();
                                        uint32 item_entry       = fields3[0].GetUInt32();
                                        uint32 item_count       = fields3[1].GetUInt32();
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
                while (queryResult->NextRow());
            }
            else
                handler->PSendSysMessage(LANG_LIST_MAIL_NOT_FOUND);
            return true;
        }
        else
            handler->PSendSysMessage(LANG_LIST_MAIL_NOT_FOUND);
        return true;
    }

    static bool HandleListSpawnPointsCommand(ChatHandler* handler)
    {
        Player const* player = handler->GetSession()->GetPlayer();
        Map const* map = player->GetMap();
        uint32 const mapId = map->GetId();
        bool const showAll = map->IsBattlegroundOrArena() || map->IsDungeon();
        handler->PSendSysMessage("Listing all spawn points in map %u (%s)%s:", mapId, map->GetMapName(), showAll ? "" : " within 5000yd");
        for (auto const& pair : sObjectMgr->GetAllCreatureData())
        {
            SpawnData const& data = pair.second;
            if (data.mapId != mapId)
                continue;
            CreatureTemplate const* cTemp = sObjectMgr->GetCreatureTemplate(data.id);
            if (!cTemp)
                continue;
            if (showAll || data.spawnPoint.IsInDist2d(player, 5000.0))
                handler->PSendSysMessage("Type: %u | SpawnId: %u | Entry: %u (%s) | X: %.3f | Y: %.3f | Z: %.3f", uint32(data.type), data.spawnId, data.id, cTemp->Name.c_str(), data.spawnPoint.GetPositionX(), data.spawnPoint.GetPositionY(), data.spawnPoint.GetPositionZ());
        }
        for (auto const& pair : sObjectMgr->GetAllGameObjectData())
        {
            SpawnData const& data = pair.second;
            if (data.mapId != mapId)
                continue;
            GameObjectTemplate const* goTemp = sObjectMgr->GetGameObjectTemplate(data.id);
            if (!goTemp)
                continue;
            if (showAll || data.spawnPoint.IsInDist2d(player, 5000.0))
                handler->PSendSysMessage("Type: %u | SpawnId: %u | Entry: %u (%s) | X: %.3f | Y: %.3f | Z: %.3f", uint32(data.type), data.spawnId, data.id, goTemp->name.c_str(), data.spawnPoint.GetPositionX(), data.spawnPoint.GetPositionY(), data.spawnPoint.GetPositionZ());
        }
        return true;
    }

    static char const* GetZoneName(uint32 zoneId, LocaleConstant locale)
    {
        AreaTableEntry const* zoneEntry = sAreaTableStore.LookupEntry(zoneId);
        return zoneEntry ? zoneEntry->AreaName[locale] : "<unknown zone>";
    }

    static bool HandleListRespawnsCommand(ChatHandler* handler, Optional<uint32> range)
    {
        Player const* player = handler->GetSession()->GetPlayer();
        Map const* map = player->GetMap();

        LocaleConstant locale = handler->GetSession()->GetSessionDbcLocale();
        char const* stringOverdue = sObjectMgr->GetTrinityString(LANG_LIST_RESPAWNS_OVERDUE, locale);

        uint32 zoneId = player->GetZoneId();
        char const* zoneName = GetZoneName(zoneId, locale);
        for (SpawnObjectType type : EnumUtils::Iterate<SpawnObjectType>())
        {
            if (range)
                handler->PSendSysMessage(LANG_LIST_RESPAWNS_RANGE, EnumUtils::ToTitle(type), *range);
            else
                handler->PSendSysMessage(LANG_LIST_RESPAWNS_ZONE, EnumUtils::ToTitle(type), zoneName, zoneId);

            handler->PSendSysMessage(LANG_LIST_RESPAWNS_LISTHEADER);
            std::vector<RespawnInfo const*> respawns;
            map->GetRespawnInfo(respawns, SpawnObjectTypeMask(1 << type));
            for (RespawnInfo const* ri : respawns)
            {
                SpawnMetadata const* data = sObjectMgr->GetSpawnMetadata(ri->type, ri->spawnId);
                if (!data)
                    continue;

                uint32 respawnZoneId = 0;
                if (SpawnData const* edata = data->ToSpawnData())
                {
                    respawnZoneId = map->GetZoneId(edata->phaseMask, edata->spawnPoint);
                    if (range)
                    {
                        if (!player->IsInDist(edata->spawnPoint, *range))
                            continue;
                    }
                    else
                    {
                        if (zoneId != respawnZoneId)
                            continue;
                    }
                }
                uint32 gridY = ri->gridId / MAX_NUMBER_OF_GRIDS;
                uint32 gridX = ri->gridId % MAX_NUMBER_OF_GRIDS;
                std::string respawnTime = ri->respawnTime > GameTime::GetGameTime() ? secsToTimeString(uint64(ri->respawnTime - GameTime::GetGameTime()), TimeFormat::ShortText) : stringOverdue;
                handler->PSendSysMessage("%u | %u | [%02u,%02u] | %s (%u) | %s%s", ri->spawnId, ri->entry, gridX, gridY, GetZoneName(respawnZoneId, locale), respawnZoneId, respawnTime.c_str(), map->IsSpawnGroupActive(data->spawnGroupData->groupId) ? "" : " (inactive)");
            }
        }
        return true;
    }
};

void AddSC_list_commandscript()
{
    new list_commandscript();
}
