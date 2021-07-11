/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/**
 * @addtogroup mailing
 * @{
 *
 * @file MailHandler.cpp
 * This file contains handlers for mail opcodes.
 *
 */

#include "Mail.h"
#include "Language.h"
#include "Log.h"
#include "ObjectGuid.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "World.h"

void WorldSession::SendMailResult(uint32 mailId, MailResponseType mailAction, MailResponseResult mailError, uint32 equipError, uint32 item_guid, uint32 item_count)
{
    WorldPacket data(SMSG_SEND_MAIL_RESULT, (4 + 4 + 4 + (mailError == MAIL_ERR_EQUIP_ERROR ? 4 : (mailAction == MAIL_ITEM_TAKEN ? 4 + 4 : 0))));
    data << (uint32)mailId;
    data << (uint32)mailAction;
    data << (uint32)mailError;
    if (mailError == MAIL_ERR_EQUIP_ERROR)
        data << (uint32)equipError;
    else if (mailAction == MAIL_ITEM_TAKEN)
    {
        data << (uint32)item_guid;                         // item guid low?
        data << (uint32)item_count;                        // item count?
    }
    SendPacket(&data);
}

void WorldSession::SendNewMail()
{
    // deliver undelivered mail
    WorldPacket data(SMSG_RECEIVED_MAIL, 4);
    data << (uint32)0;
    SendPacket(&data);
}

bool WorldSession::CheckMailBox(ObjectGuid guid)
{
    if (!GetPlayer()->GetGameObjectIfCanInteractWith(guid, GAMEOBJECT_TYPE_MAILBOX))
    {
        DEBUG_LOG("Mailbox %s not found or you can't interact with it.", guid.GetString().c_str());
        return false;
        if (!HasPermission(rbac::RBAC_PERM_COMMAND_MAILBOX))
        {
            TC_LOG_WARN("cheat", "{} attempted to open mailbox by using a cheat.", _player->GetName());
            return false;
        }
    }
    else if (guid.IsGameObject())
    {
        if (!_player->GetGameObjectIfCanInteractWith(guid, GAMEOBJECT_TYPE_MAILBOX))
            return false;
    }
    else if (guid.IsAnyTypeCreature())
    {
        if (!_player->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_MAILBOX, UNIT_NPC_FLAG_2_NONE))
            return false;
    }

    return true;
}

class WorldSession::AsyncMailSendRequest
void WorldSession::HandleSendMail(WorldPackets::Mail::SendMail& sendMail)
{
public:
    AsyncMailSendRequest(): accountId(0), money(0), COD(0), receiverPtr(nullptr), rcTeam(TEAM_NONE), mailsCount(0xFF) {}
    uint32 accountId;
    ObjectGuid senderGuid;
    ObjectGuid receiver;
    ObjectGuid itemGuid;
    uint32      money;
    uint32      COD;
    std::string subject;
    std::string body;
    std::string receiverName;
    Player*     receiverPtr;
    Team        rcTeam;
    uint8       mailsCount;
    void Callback(QueryResult* result)
    if (sendMail.Info.Attachments.size() > MAX_CLIENT_MAIL_ITEMS)        // client limit
    {
        WorldSession* sess = sWorld.FindSession(accountId);
        if (!sess || !sess->GetPlayer() || sess->GetPlayer()->GetObjectGuid() != senderGuid || !sess->GetPlayer()->IsInWorld())
        {
            delete result;
            delete this;
            return;
        }

        if (result)
        {
            Field* fields = result->Fetch();
            mailsCount = fields[0].GetUInt32();
            delete result;
        }
        sess->HandleSendMailCallback(this);
        delete this;
    }
};
    if (!CanOpenMailBox(sendMail.Info.Mailbox))
        return;

/**
 * Handles the Packet sent by the client when sending a mail.
 *
 * This methods takes the packet sent by the client and performs the following actions:
 * - Checks whether the mail is valid: i.e. can he send the selected items,
 *   does he have enough money, etc.
 * - Creates a MailDraft and adds the needed items, money, cost data.
 * - Sends the mail.
 *
 * Depending on the outcome of the checks performed the player will recieve a different
 * MailResponseResult.
 *
 * @see MailResponseResult
 * @see SendMailResult()
 *
 * @param recv_data the WorldPacket containing the data sent by the client.
 */
void WorldSession::HandleSendMail(WorldPacket& recv_data)
{
    ObjectGuid mailboxGuid;
    uint32 unk1, unk2;
    
    recv_data >> mailboxGuid;
    if (!CheckMailBox(mailboxGuid))
    if (sendMail.Info.Target.empty())
        return;

    WorldSession::AsyncMailSendRequest* req = new WorldSession::AsyncMailSendRequest();
    req->accountId = GetAccountId();
    req->senderGuid = GetMasterPlayer()->GetObjectGuid();
    recv_data >> req->receiverName;
    if (!ValidateHyperlinksAndMaybeKick(sendMail.Info.Subject) || !ValidateHyperlinksAndMaybeKick(sendMail.Info.Body))
        return;

    Player* player = _player;

    recv_data >> req->subject;

    recv_data >> req->body;

    recv_data >> unk1;                                      // stationery?
    recv_data >> unk2;                                      // 0x00000000

    recv_data >> req->itemGuid;

    recv_data >> req->money >> req->COD;                    // money and cod

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
    uint64 unk3;
    uint8 unk4;
    recv_data >> unk3;                                      // const 0
    recv_data >> unk4;                                      // const 0
#endif

    // packet read complete, now do check
    if (req->subject.size() > 64)
    if (player->GetLevel() < sWorld->getIntConfig(CONFIG_MAIL_LEVEL_REQ))
    {
        delete req;
        return;
    }

    if (req->body.size() > 500)
    ObjectGuid receiverGuid;
    if (normalizePlayerName(sendMail.Info.Target))
        receiverGuid = sCharacterCache->GetCharacterGuidByName(sendMail.Info.Target);

    if (!receiverGuid)
    {
        delete req;
        TC_LOG_INFO("network", "Player {} is sending mail to {} (GUID: non-existing!) with subject {} "
            "and body {} includes {} items, {} copper and {} COD copper with StationeryID = {}",
            GetPlayerInfo(), sendMail.Info.Target, sendMail.Info.Subject, sendMail.Info.Body,
            sendMail.Info.Attachments.size(), sendMail.Info.SendMoney, sendMail.Info.Cod, sendMail.Info.StationeryID);
        player->SendMailResult(0, MAIL_SEND, MAIL_ERR_RECIPIENT_NOT_FOUND);
        return;
    }

    // client interface limit
    if (req->COD > 100000000)
    if (sendMail.Info.SendMoney < 0)
    {
        ProcessAnticheatAction("PassiveAnticheat", "Attempt to send more than 10000g COD mail", CHEAT_ACTION_LOG | CHEAT_ACTION_REPORT_GMS);
        delete req;
        GetPlayer()->SendMailResult(0, MAIL_SEND, MAIL_ERR_INTERNAL_ERROR);
        TC_LOG_WARN("cheat", "Player {} attempted to send mail to {} ({}) with negative money value (SendMoney: {})",
            GetPlayerInfo(), sendMail.Info.Target, receiverGuid.ToString(), sendMail.Info.SendMoney);
        return;
    }

    if (req->COD && sWorld.getConfig(CONFIG_UINT32_COD_FORCE_TAG_MAX_LEVEL) &&
        sWorld.getConfig(CONFIG_UINT32_COD_FORCE_TAG_MAX_LEVEL) > GetAccountMaxLevel())
        req->subject = "(COD) " + req->subject;

    // Do not allow GMs to send money / items
    if (!sWorld.getConfig(CONFIG_BOOL_GM_ALLOW_TRADES) && GetSecurity() > SEC_PLAYER)
    if (sendMail.Info.Cod < 0)
    {
        if (!req->itemGuid.IsEmpty() || req->money)
        {
            delete req;
            return;
        }
    }
        GetPlayer()->SendMailResult(0, MAIL_SEND, MAIL_ERR_INTERNAL_ERROR);
        TC_LOG_WARN("cheat", "Player {} attempted to send mail to {} ({}) with negative COD value (Cod: {})",
            GetPlayerInfo(), sendMail.Info.Target, receiverGuid.ToString(), sendMail.Info.Cod);
        return;
    }

    if (req->receiverName.empty())
    TC_LOG_INFO("network", "Player {} is sending mail to {} ({}) with subject {} and body {} "
        "includes {} items, {} copper and " SI64FMTD  " COD copper with StationeryID = {}",
        GetPlayerInfo(), sendMail.Info.Target, receiverGuid.ToString(), sendMail.Info.Subject,
        sendMail.Info.Body, sendMail.Info.Attachments.size(), sendMail.Info.SendMoney, sendMail.Info.Cod, sendMail.Info.StationeryID);

    if (player->GetGUID() == receiverGuid)
    {
        delete req;
        return;
    }

    MasterPlayer* pl = GetMasterPlayer();
    uint32 cost = !sendMail.Info.Attachments.empty() ? 30 * sendMail.Info.Attachments.size() : 30;  // price hardcoded in client

    if (normalizePlayerName(req->receiverName))
        req->receiver = sObjectMgr.GetPlayerGuidByName(req->receiverName);
    int64 reqmoney = cost + sendMail.Info.SendMoney;

    if (!req->receiver)
    // Check for overflow
    if (reqmoney < sendMail.Info.SendMoney)
    {
        DETAIL_LOG("%s is sending mail to %s (GUID: nonexistent!) with subject %s and body %s includes %u items, %u copper and %u COD copper with unk1 = %u, unk2 = %u",
                   pl->GetGuidStr().c_str(), req->receiverName.c_str(), req->subject.c_str(), req->body.c_str(), req->itemGuid ? 1 : 0, req->money, req->COD, unk1, unk2);
        SendMailResult(0, MAIL_SEND, MAIL_ERR_RECIPIENT_NOT_FOUND);
        delete req;
        return;
    }

    DETAIL_LOG("%s is sending mail to %s with subject %s and body %s includes %u items, %u copper and %u COD copper with unk1 = %u, unk2 = %u",
               pl->GetGuidStr().c_str(), req->receiverName.c_str(), req->subject.c_str(), req->body.c_str(), req->itemGuid ? 1 : 0, req->money, req->COD, unk1, unk2);

    if (pl->GetObjectGuid() == req->receiver)
    {
        SendMailResult(0, MAIL_SEND, MAIL_ERR_CANNOT_SEND_TO_SELF);
        delete req;
        return;
    }

    req->receiverPtr = sObjectMgr.GetPlayer(req->receiver);

    if (req->receiverPtr)
    auto mailCountCheckContinuation = [this, player = _player, receiverGuid, mailInfo = std::move(sendMail.Info), reqmoney, cost](uint32 receiverTeam, uint64 mailsCount, uint8 receiverLevel, uint32 receiverAccountId, uint32 receiverBnetAccountId) mutable
    {
        MasterPlayer* receiverMasterPlayer = req->receiverPtr->GetSession()->GetMasterPlayer();
        ASSERT(receiverMasterPlayer);
        req->rcTeam = receiverMasterPlayer->GetTeam();
        req->mailsCount = receiverMasterPlayer->GetMailSize();
        req->Callback(nullptr);
    }
    else
    {
        req->rcTeam = sObjectMgr.GetPlayerTeamByGUID(req->receiver);
        // Unsafe query: can modify items, accesses online players ...
        CharacterDatabase.AsyncPQueryUnsafe(req, &WorldSession::AsyncMailSendRequest::Callback, "SELECT COUNT(*) FROM `mail` WHERE `receiver_guid` = '%u'", req->receiver.GetCounter());
    }
}
        if (_player != player)
            return;

// $req will be deleted by the caller.
void WorldSession::HandleSendMailCallback(WorldSession::AsyncMailSendRequest* req)
{
    MasterPlayer* pl = GetMasterPlayer();
    Player* loadedPlayer = GetPlayer();
    ASSERT(pl);

    uint32 reqmoney = req->money + 30;

    // Check for overflow
    if (reqmoney < req->money)
    {
        ProcessAnticheatAction("MailCheck", "Attempt to send free mails with money overflow", CHEAT_ACTION_LOG);
        SendMailResult(0, MAIL_SEND, MAIL_ERR_NOT_ENOUGH_MONEY);
        return;
    }
    if (reqmoney && (!loadedPlayer || loadedPlayer->GetMoney() < reqmoney))
    {
        SendMailResult(0, MAIL_SEND, MAIL_ERR_NOT_ENOUGH_MONEY);
        return;
    }
        // do not allow to have more than 100 mails in mailbox.. mails count is in opcode uint8!!! - so max can be 255..
        if (mailsCount > 100)
        {
            player->SendMailResult(0, MAIL_SEND, MAIL_ERR_RECIPIENT_CAP_REACHED);
            return;
        }

        // test the receiver's Faction... or all items are account bound
        bool accountBound = !mailInfo.Attachments.empty();
        for (WorldPackets::Mail::SendMail::StructSendMail::MailAttachment const& att : mailInfo.Attachments)
        {
            if (Item* item = player->GetItemByGuid(att.ItemGUID))
            {
                ItemTemplate const* itemProto = item->GetTemplate();
                if (!itemProto || !itemProto->HasFlag(ITEM_FLAG_IS_BOUND_TO_ACCOUNT))
                {
                    accountBound = false;
                    break;
                }
            }
        }

    // do not allow to have more than 100 mails in mailbox.. mails count is in opcode uint8!!! - so max can be 255..
    if (req->mailsCount > 100)
    {
        SendMailResult(0, MAIL_SEND, MAIL_ERR_RECIPIENT_CAP_REACHED);
        return;
    }
        if (!accountBound && player->GetTeam() != receiverTeam && !HasPermission(rbac::RBAC_PERM_TWO_SIDE_INTERACTION_MAIL))
        {
            player->SendMailResult(0, MAIL_SEND, MAIL_ERR_NOT_YOUR_TEAM);
            return;
        }

    // check the receiver's Faction...
    if (!sWorld.getConfig(CONFIG_BOOL_ALLOW_TWO_SIDE_INTERACTION_MAIL) && pl->GetTeam() != req->rcTeam && GetSecurity() == SEC_PLAYER)
    {
        SendMailResult(0, MAIL_SEND, MAIL_ERR_NOT_YOUR_TEAM);
        return;
    }
        if (receiverLevel < sWorld->getIntConfig(CONFIG_MAIL_LEVEL_REQ))
        {
            SendNotification(GetTrinityString(LANG_MAIL_RECEIVER_REQ), sWorld->getIntConfig(CONFIG_MAIL_LEVEL_REQ));
            return;
        }

    uint32 rc_account = sObjectMgr.GetPlayerAccountIdByGUID(req->receiver);
        std::vector<Item*> items;

    Item* item = nullptr;

    if (req->itemGuid)
    {
        item = loadedPlayer->GetItemByGuid(req->itemGuid);
        for (WorldPackets::Mail::SendMail::StructSendMail::MailAttachment const& att : mailInfo.Attachments)
        {
            if (att.ItemGUID.IsEmpty())
            {
                player->SendMailResult(0, MAIL_SEND, MAIL_ERR_MAIL_ATTACHMENT_INVALID);
                return;
            }

        // prevent sending bag with items (cheat: can be placed in bag after adding equipped empty bag to mail)
        if (!item || !item->IsInWorld())
        {
            SendMailResult(0, MAIL_SEND, MAIL_ERR_INTERNAL_ERROR);
            return;
        }
            Item* item = player->GetItemByGuid(att.ItemGUID);

            // prevent sending bag with items (cheat: can be placed in bag after adding equipped empty bag to mail)
            if (!item)
            {
                player->SendMailResult(0, MAIL_SEND, MAIL_ERR_MAIL_ATTACHMENT_INVALID);
                return;
            }

        // prevent sending item from bank slot
        if (_player->IsBankPos(item->GetPos())) 
        {
            SendMailResult(0, MAIL_SEND, MAIL_ERR_INTERNAL_ERROR);
            return;
        }
            if (!item->CanBeTraded(true))
            {
                player->SendMailResult(0, MAIL_SEND, MAIL_ERR_EQUIP_ERROR, EQUIP_ERR_MAIL_BOUND_ITEM);
                return;
            }

        if (!item->CanBeTraded())
        {
            SendMailResult(0, MAIL_SEND, MAIL_ERR_INTERNAL_ERROR);
            return;
        }
            if (item->IsBoundAccountWide() && item->IsSoulBound() && player->GetSession()->GetAccountId() != receiverAccountId)
            {
                if (!item->IsBattlenetAccountBound() || !player->GetSession()->GetBattlenetAccountId() || player->GetSession()->GetBattlenetAccountId() != receiverBnetAccountId)
                {
                    player->SendMailResult(0, MAIL_SEND, MAIL_ERR_EQUIP_ERROR, EQUIP_ERR_NOT_SAME_ACCOUNT);
                    return;
                }
            }

        if ((item->GetProto()->Flags & ITEM_FLAG_CONJURED) || item->GetUInt32Value(ITEM_FIELD_DURATION))
        {
            SendMailResult(0, MAIL_SEND, MAIL_ERR_INTERNAL_ERROR);
            return;
        }
    }
            if (item->GetTemplate()->HasFlag(ITEM_FLAG_CONJURED) || *item->m_itemData->Expiration)
            {
                player->SendMailResult(0, MAIL_SEND, MAIL_ERR_EQUIP_ERROR, EQUIP_ERR_MAIL_BOUND_ITEM);
                return;
            }

    // Antispam checks
    if (loadedPlayer->GetLevel() < sWorld.getConfig(CONFIG_UINT32_MAILSPAM_LEVEL) &&
        req->money < sWorld.getConfig(CONFIG_UINT32_MAILSPAM_MONEY) &&
        (sWorld.getConfig(CONFIG_BOOL_MAILSPAM_ITEM) && !req->itemGuid))
    {
        SendMailResult(0, MAIL_SEND, MAIL_ERR_INTERNAL_ERROR);
        return;
    }
            if (mailInfo.Cod && item->IsWrapped())
            {
                player->SendMailResult(0, MAIL_SEND, MAIL_ERR_CANT_SEND_WRAPPED_COD);
                return;
            }

    AccountPersistentData& data = sAccountMgr.GetAccountPersistentData(GetAccountId());
    if (!data.CanMail(rc_account))
    {
        std::stringstream details;
        std::string from = ChatHandler(this).playerLink(GetMasterPlayer()->GetName());
        std::string to = ChatHandler(this).playerLink(req->receiverName);
        details << from << " -> " << to << "\n";
        details << req->subject << "\n";
        details << req->body << "\n";
        if (req->COD)
            details << "COD: " << req->COD << " coppers\n";
        uint32 logId = sWorld.InsertLog(details.str(), SEC_GAMEMASTER);

        std::stringstream oss;
        oss << "Mail limit reached (\"" << req->body.substr(0, 30) << "...\") [log #" << logId << "]";
        ProcessAnticheatAction("ChatSpam", oss.str().c_str(), CHEAT_ACTION_LOG | CHEAT_ACTION_REPORT_GMS);
        SendMailResult(0, MAIL_SEND, MAIL_OK);
        return;
    }
    data.JustMailed(rc_account);
            if (item->IsNotEmptyBag())
            {
                player->SendMailResult(0, MAIL_SEND, MAIL_ERR_EQUIP_ERROR, EQUIP_ERR_DESTROY_NONEMPTY_BAG);
                return;
            }

    SendMailResult(0, MAIL_SEND, MAIL_OK);
            items.push_back(item);
        }

    loadedPlayer->ModifyMoney(-int32(reqmoney));
        player->SendMailResult(0, MAIL_SEND, MAIL_OK);

    MailDraft draft(req->subject, req->body);
        player->ModifyMoney(-reqmoney);
        player->UpdateCriteria(CriteriaType::MoneySpentOnPostage, cost);

    if (!req->COD && (req->money || item))
    {
        PlayerTransactionData data;
        data.type = "Mail";
        data.parts[0].lowGuid = pl->GetGUIDLow();
        if (item)
        {
            data.parts[0].itemsEntries[0] = item->GetEntry();
            data.parts[0].itemsCount[0] = item->GetCount();
            data.parts[0].itemsGuid[0] = item->GetGUIDLow();
        }
        data.parts[0].money = req->money;
        data.parts[1].lowGuid = req->receiver.GetCounter();
        sWorld.LogTransaction(data);
    }

    if (req->itemGuid || req->money > 0)
    {
        if (item)
        {
            if (GetSecurity() > SEC_PLAYER && sWorld.getConfig(CONFIG_BOOL_GM_LOG_TRADE))
            {
                sLog.outCommand(GetAccountId(), "GM %s (Account: %u) mail item: %s (Entry: %u Count: %u) to player: %s (Account: %u)",
                                GetPlayerName(), GetAccountId(), item->GetProto()->Name1, item->GetEntry(), item->GetCount(), req->receiver.GetString().c_str(), rc_account);
            }
        bool needItemDelay = false;

        MailDraft draft(mailInfo.Subject, mailInfo.Body);

        CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

        if (!mailInfo.Attachments.empty() || mailInfo.SendMoney > 0)
        {
            bool log = HasPermission(rbac::RBAC_PERM_LOG_GM_TRADE);
            if (!mailInfo.Attachments.empty())
            {
                for (auto const& item : items)
                {
                    if (log)
                    {
                        sLog->OutCommand(GetAccountId(), "GM {} ({}) (Account: {}) mail item: {} (Entry: {} Count: {}) "
                            "to: {} ({}) (Account: {})", GetPlayerName(), _player->GetGUID().ToString(), GetAccountId(),
                            item->GetTemplate()->GetDefaultLocaleName(), item->GetEntry(), item->GetCount(),
                            mailInfo.Target, receiverGuid.ToString(), receiverAccountId);
                    }

            loadedPlayer->MoveItemFromInventory(item->GetBagSlot(), item->GetSlot(), true);
            CharacterDatabase.BeginTransaction(loadedPlayer->GetGUIDLow());
            item->DeleteFromInventoryDB();                  // deletes item from character's inventory
            item->SaveToDB();                               // recursive and not have transaction guard into self, item not in inventory and can be save standalone
            // owner in data will set at mail receive and item extracting
            CharacterDatabase.PExecute("UPDATE `item_instance` SET `owner_guid` = '%u' WHERE `guid`='%u'", req->receiver.GetCounter(), item->GetGUIDLow());
            CharacterDatabase.CommitTransaction();
                    item->SetNotRefundable(GetPlayer()); // makes the item no longer refundable
                    player->MoveItemFromInventory(item->GetBagSlot(), item->GetSlot(), true);

            draft.AddItem(item);
        }
                    item->DeleteFromInventoryDB(trans);     // deletes item from character's inventory
                    item->SetOwnerGUID(receiverGuid);
                    item->SetState(ITEM_CHANGED);
                    item->SaveToDB(trans);                  // recursive and not have transaction guard into self, item not in inventory and can be save standalone

                    draft.AddItem(item);
                }

        if (req->money > 0 &&  GetSecurity() > SEC_PLAYER && sWorld.getConfig(CONFIG_BOOL_GM_LOG_TRADE))
        {
            sLog.outCommand(GetAccountId(), "GM %s (Account: %u) mail money: %u to player: %s (Account: %u)",
                            GetPlayerName(), GetAccountId(), req->money, req->receiver.GetString().c_str(), rc_account);
        }
    }
                // if item send to character at another account, then apply item delivery delay
                needItemDelay = player->GetSession()->GetAccountId() != receiverAccountId;
            }

            if (log && mailInfo.SendMoney > 0)
            {
                sLog->OutCommand(GetAccountId(), "GM {} ({}) (Account: {}) mail money: {} to: {} ({}) (Account: {})",
                    GetPlayerName(), _player->GetGUID().ToString(), GetAccountId(), mailInfo.SendMoney, mailInfo.Target, receiverGuid.ToString(), receiverAccountId);
            }
        }

    // default delay for mails is one hour in WoW Classic https://eu.battle.net/support/de/article/98485
    // mails which only contain a text message will arrive instantly
    uint32 deliver_delay = (!req->itemGuid && req->money == 0) ? 0 : sWorld.getConfig(CONFIG_UINT32_MAIL_DELIVERY_DELAY);
        // If theres is an item, there is a one hour delivery delay if sent to another account's character.
        uint32 deliver_delay = needItemDelay ? sWorld->getIntConfig(CONFIG_MAIL_DELIVERY_DELAY) : 0;

    if (!item && req->COD)
    {
        req->COD = 0;
        ProcessAnticheatAction("MailCheck", "Attempt to send COD mail without any item", CHEAT_ACTION_LOG);
    }
    // will delete item or place to receiver mail list
    draft
    .SetMoney(req->money)
    .SetCOD(req->COD)
    .SendMailTo(MailReceiver(req->receiverPtr, req->receiver), loadedPlayer, req->body.empty() ? MAIL_CHECK_MASK_COPIED : MAIL_CHECK_MASK_HAS_BODY, deliver_delay);
        // Mail sent between guild members arrives instantly
        if (Guild* guild = sGuildMgr->GetGuildById(player->GetGuildId()))
            if (guild->IsMember(receiverGuid))
                deliver_delay = 0;

        // don't ask for COD if there are no items
        if (mailInfo.Attachments.empty())
            mailInfo.Cod = 0;

        // will delete item or place to receiver mail list
        draft
            .AddMoney(mailInfo.SendMoney)
            .AddCOD(mailInfo.Cod)
            .SendMailTo(trans, MailReceiver(ObjectAccessor::FindConnectedPlayer(receiverGuid), receiverGuid.GetCounter()), MailSender(player), mailInfo.Body.empty() ? MAIL_CHECK_MASK_COPIED : MAIL_CHECK_MASK_HAS_BODY, deliver_delay);

    CharacterDatabase.BeginTransaction(loadedPlayer->GetGUIDLow());
    loadedPlayer->SaveInventoryAndGoldToDB();
    CharacterDatabase.CommitTransaction();
        player->SaveInventoryAndGoldToDB(trans);
        CharacterDatabase.CommitTransaction(trans);
    };

    if (Player* receiver = ObjectAccessor::FindConnectedPlayer(receiverGuid))
    {
        mailCountCheckContinuation(receiver->GetTeam(), receiver->GetMailSize(), receiver->GetLevel(), receiver->GetSession()->GetAccountId(), receiver->GetSession()->GetBattlenetAccountId());
    }
    else
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_MAIL_COUNT);
        stmt->setUInt64(0, receiverGuid.GetCounter());

        GetQueryProcessor().AddCallback(CharacterDatabase.AsyncQuery(stmt)
            .WithChainingPreparedCallback([continuation = std::move(mailCountCheckContinuation), receiverGuid](QueryCallback& queryCallback, PreparedQueryResult mailCountResult) mutable
        {
            if (CharacterCacheEntry const* characterInfo = sCharacterCache->GetCharacterCacheByGuid(receiverGuid))
                queryCallback.WithPreparedCallback([continuation = std::move(continuation), characterInfo, mailCountResult](PreparedQueryResult bnetAccountResult) mutable
                {
                    continuation(Player::TeamForRace(characterInfo->Race), mailCountResult ? (*mailCountResult)[0].GetUInt64() : UI64LIT(0),
                        characterInfo->Level, characterInfo->AccountId, bnetAccountResult ? (*bnetAccountResult)[0].GetUInt32() : 0);
                }).SetNextQuery(Battlenet::AccountMgr::GetIdByGameAccountAsync(characterInfo->AccountId));
        }));
    }
}

/**
 * Handles the Packet sent by the client when reading a mail.
 *
 * This method is called when a client reads a mail that was previously unread.
 * It will add the MAIL_CHECK_MASK_READ flag to the mail being read.
 *
 * @see MailCheckMask
 *
 * @param recv_data the packet containing information about the mail the player read.
 *
 */
void WorldSession::HandleMailMarkAsRead(WorldPacket& recv_data)
//called when mail is read
void WorldSession::HandleMailMarkAsRead(WorldPackets::Mail::MailMarkAsRead& markAsRead)
{
    ObjectGuid mailboxGuid;
    uint32 mailId;
    recv_data >> mailboxGuid;
    recv_data >> mailId;

    if (!CheckMailBox(mailboxGuid))
    if (!CanOpenMailBox(markAsRead.Mailbox))
        return;

    MasterPlayer* pl = GetMasterPlayer();
    ASSERT(pl);

    if (Mail *m = pl->GetMail(mailId))
    Player* player = _player;
    Mail* m = player->GetMail(markAsRead.MailID);
    if (m && m->state != MAIL_STATE_DELETED)
    {
        if (m->state == MAIL_STATE_DELETED)
        {
            ProcessAnticheatAction("MailCheck", "Attempt to mark deleted mail as read", CHEAT_ACTION_LOG);
            return;
        }
        pl->DecreaseUnreadMailsCount();
        m->checked = m->checked | MAIL_CHECK_MASK_READ;
        pl->MarkMailsUpdated();
        m->state = MAIL_STATE_CHANGED;

        time_t time_now = time(nullptr);
        if ((m->expire_time - time_now) > (3 * DAY))
            m->expire_time = time_now + (3 * DAY);
    }
}

/**
 * Handles the Packet sent by the client when deleting a mail.
 *
 * This method is called when a client deletes a mail in his mailbox.
 *
 * @param recv_data The packet containing information about the mail being deleted.
 *
 */
void WorldSession::HandleMailDelete(WorldPacket& recv_data)
//called when client deletes mail
void WorldSession::HandleMailDelete(WorldPackets::Mail::MailDelete& mailDelete)
{
    ObjectGuid mailboxGuid;
    uint32 mailId;
    recv_data >> mailboxGuid;
    recv_data >> mailId;

    if (!CheckMailBox(mailboxGuid))
        return;

    MasterPlayer* pl = GetMasterPlayer();
    ASSERT(pl);
    pl->MarkMailsUpdated();

    if (Mail *m = pl->GetMail(mailId))
    Mail* m = _player->GetMail(mailDelete.MailID);
    Player* player = _player;
    player->m_mailsUpdated = true;
    if (m)
    {
        // delete shouldn't show up for COD mails
        if (m->COD)
        {
            SendMailResult(mailId, MAIL_DELETED, MAIL_ERR_INTERNAL_ERROR);
            player->SendMailResult(mailDelete.MailID, MAIL_DELETED, MAIL_ERR_INTERNAL_ERROR);
            return;
        }

        m->state = MAIL_STATE_DELETED;
    }
    SendMailResult(mailId, MAIL_DELETED, MAIL_OK);
    player->SendMailResult(mailDelete.MailID, MAIL_DELETED, MAIL_OK);
}
/**
 * Handles the Packet sent by the client when returning a mail to sender.
 * This method is called when a player chooses to return a mail to its sender.
 * It will create a new MailDraft and add the items, money, etc. associated with the mail
 * and then send the mail to the original sender.
 *
 * @param recv_data The packet containing information about the mail being returned.
 *
 */
void WorldSession::HandleMailReturnToSender(WorldPacket& recv_data)
{
    ObjectGuid mailboxGuid;
    uint32 mailId;
    recv_data >> mailboxGuid;
    recv_data >> mailId;

    if (!CheckMailBox(mailboxGuid))
void WorldSession::HandleMailReturnToSender(WorldPackets::Mail::MailReturnToSender& returnToSender)
{
    if (!CanOpenMailBox(_player->PlayerTalkClass->GetInteractionData().SourceGuid))
        return;

    MasterPlayer* pl = GetMasterPlayer();
    ASSERT(pl);
    Mail *m = pl->GetMail(mailId);
    if (!m || m->state == MAIL_STATE_DELETED || m->deliver_time > time(nullptr))
    Player* player = _player;
    Mail* m = player->GetMail(returnToSender.MailID);
    if (!m || m->state == MAIL_STATE_DELETED || m->deliver_time > GameTime::GetGameTime() || m->sender != returnToSender.SenderGUID.GetCounter())
    {
        SendMailResult(mailId, MAIL_RETURNED_TO_SENDER, MAIL_ERR_INTERNAL_ERROR);
        player->SendMailResult(returnToSender.MailID, MAIL_RETURNED_TO_SENDER, MAIL_ERR_INTERNAL_ERROR);
        return;
    }
    //we can return mail now, so firstly delete the old one
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL_BY_ID);
    stmt->setUInt64(0, returnToSender.MailID);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL_ITEM_BY_ID);
    stmt->setUInt64(0, returnToSender.MailID);
    trans->Append(stmt);

    //we can return mail now
    //so firstly delete the old one
    CharacterDatabase.BeginTransaction(pl->GetGUIDLow());
    CharacterDatabase.PExecute("DELETE FROM `mail` WHERE `id` = '%u'", mailId);
    // needed?
    CharacterDatabase.PExecute("DELETE FROM `mail_items` WHERE `mail_id` = '%u'", mailId);
    CharacterDatabase.CommitTransaction();
    pl->RemoveMail(mailId);
    player->RemoveMail(returnToSender.MailID);

    // send back only to existing players and simple drop for other cases
    if (m->messageType == MAIL_NORMAL && m->sender)
    {
        MailDraft draft;
        if (m->mailTemplateId)
            draft.SetMailTemplate(m->mailTemplateId, false);// items already included
        else
            draft.SetSubjectAndBodyId(m->subject, m->itemTextId);

        if (m->HasItems())
        {
            for (const auto& itr2 : m->items)
            {
                if (Item *item = pl->GetMItem(itr2.itemGuid))
                    draft.AddItem(item);

                pl->RemoveMItem(itr2.itemGuid);
            }
        }

        draft.SetMoney(m->money).SendReturnToSender(GetAccountId(), m->receiverGuid, ObjectGuid(HIGHGUID_PLAYER, m->sender));
    }

    delete m;                                               // we can deallocate old mail
    SendMailResult(mailId, MAIL_RETURNED_TO_SENDER, MAIL_OK);
    delete m;                                               //we can deallocate old mail
    player->SendMailResult(returnToSender.MailID, MAIL_RETURNED_TO_SENDER, MAIL_OK);
}

/**
 * Handles the packet sent by the client when taking an item from the mail.
 */
void WorldSession::HandleMailTakeItem(WorldPacket& recv_data)
//called when player takes item attached in mail
void WorldSession::HandleMailTakeItem(WorldPackets::Mail::MailTakeItem& takeItem)
{
    ObjectGuid mailboxGuid;
    uint32 mailId;
    recv_data >> mailboxGuid;
    recv_data >> mailId;
    uint64 AttachID = takeItem.AttachID;

    if (!CheckMailBox(mailboxGuid))
    if (!CanOpenMailBox(takeItem.Mailbox))
        return;

    MasterPlayer* pl = GetMasterPlayer();
    Player* loadedPlayer = GetPlayer();
    ASSERT(pl);

    Mail* m = pl->GetMail(mailId);
    if (!m || m->state == MAIL_STATE_DELETED || m->deliver_time > time(nullptr))
    Mail* m = player->GetMail(takeItem.MailID);
    if (!m || m->state == MAIL_STATE_DELETED || m->deliver_time > GameTime::GetGameTime())
    {
        SendMailResult(mailId, MAIL_ITEM_TAKEN, MAIL_ERR_INTERNAL_ERROR);
        player->SendMailResult(takeItem.MailID, MAIL_ITEM_TAKEN, MAIL_ERR_INTERNAL_ERROR);
        return;
    }

    // Prevent spoofed packet accessing mail that doesn't actually have items
    if (!m->HasItems() || m->items.empty())
    {
        SendMailResult(mailId, MAIL_ITEM_TAKEN, MAIL_ERR_INTERNAL_ERROR);
        player->SendMailResult(takeItem.MailID, MAIL_ITEM_TAKEN, MAIL_ERR_INTERNAL_ERROR);
        return;
    }

    // prevent cheating with skip client money check
    if (loadedPlayer->GetMoney() < m->COD)
    {
        SendMailResult(mailId, MAIL_ITEM_TAKEN, MAIL_ERR_NOT_ENOUGH_MONEY);
        return;
    }

    // Do not allow GMs to send COD
    if (!sWorld.getConfig(CONFIG_BOOL_GM_ALLOW_TRADES) && GetSecurity() > SEC_PLAYER && m->COD)
    {
        SendMailResult(mailId, MAIL_ITEM_TAKEN, MAIL_ERR_NOT_ENOUGH_MONEY);
        player->SendMailResult(takeItem.MailID, MAIL_ITEM_TAKEN, MAIL_ERR_NOT_ENOUGH_MONEY);
        return;
    }

    uint32 itemId = m->items[0].itemId;
    uint32 itemGuid = m->items[0].itemGuid;

    Item *it = pl->GetMItem(itemGuid);
    Item* it = player->GetMItem(takeItem.AttachID);

    ItemPosCountVec dest;
    uint8 msg = _player->CanStoreItem(NULL_BAG, NULL_SLOT, dest, it, false);
    if (msg == EQUIP_ERR_OK)
    {
        m->RemoveItem(itemGuid);
        m->removedItems.push_back(itemGuid);

        if (m->COD > 0)                                     // if there is COD, take COD money from player and send them to sender by mail
        {
            ObjectGuid sender_guid = ObjectGuid(HIGHGUID_PLAYER, m->sender);
            Player* sender = sObjectMgr.GetPlayer(sender_guid);
        CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
        m->RemoveItem(takeItem.AttachID);
        m->removedItems.push_back(takeItem.AttachID);

            // Transaction log
            PlayerTransactionData data;
            data.type = "MailCOD";
            data.parts[0].lowGuid = sender_guid.GetCounter();
            if (it)
            {
                data.parts[0].itemsEntries[0] = it->GetEntry();
                data.parts[0].itemsCount[0] = it->GetCount();
                data.parts[0].itemsGuid[0] = it->GetGUIDLow();
            }
            data.parts[1].lowGuid = _player->GetGUIDLow();
            data.parts[1].money = m->COD;
            sWorld.LogTransaction(data);

            uint32 sender_accId = 0;

            if (GetSecurity() > SEC_PLAYER && sWorld.getConfig(CONFIG_BOOL_GM_LOG_TRADE))
            {
                std::string sender_name;
                if (sender)
                {
                    sender_accId = sender->GetSession()->GetAccountId();
                    sender_name = sender->GetName();
                }
                else
                {
                    // can be calculated early
                    sender_accId = sObjectMgr.GetPlayerAccountIdByGUID(sender_guid);

                    if (!sObjectMgr.GetPlayerNameByGUID(sender_guid, sender_name))
                        sender_name = sObjectMgr.GetMangosStringForDBCLocale(LANG_UNKNOWN);
                }
                sLog.outCommand(GetAccountId(), "GM %s (Account: %u) receive mail item: %s (Entry: %u Count: %u) and send COD money: %u to player: %s (Account: %u)",
                                GetPlayerName(), GetAccountId(), it->GetProto()->Name1, it->GetEntry(), it->GetCount(), m->COD, sender_name.c_str(), sender_accId);
                sLog->OutCommand(GetAccountId(), "GM {} (Account: {}) receiver mail item: {} (Entry: {} Count: {}) and send COD money: {} to player: {} (Account: {})",
                    GetPlayerName(), GetAccountId(), it->GetTemplate()->GetDefaultLocaleName(), it->GetEntry(), it->GetCount(), m->COD, sender_name, sender_accId);
            }
            else if (!sender)
                sender_accId = sObjectMgr.GetPlayerAccountIdByGUID(sender_guid);

            // check player existence
            if (sender || sender_accId)
            {
                MailDraft(m->subject)
                .SetMoney(m->COD)
                .SendMailTo(MailReceiver(sender, sender_guid), _player, MAIL_CHECK_MASK_COD_PAYMENT);
            }

            loadedPlayer->ModifyMoney(-int32(m->COD));
        }
        m->COD = 0;
        m->state = MAIL_STATE_CHANGED;
        pl->MarkMailsUpdated();
        pl->RemoveMItem(it->GetGUIDLow());

        uint32 count = it->GetCount();                      // save counts before store and possible merge with deleting
        it->SetState(ITEM_UNCHANGED);                       // need to set this state, otherwise item cannot be removed later, if necessary
        loadedPlayer->MoveItemToInventory(dest, it, true);

        CharacterDatabase.BeginTransaction(loadedPlayer->GetGUIDLow());
        loadedPlayer->SaveInventoryAndGoldToDB();
        pl->SaveMails();
        CharacterDatabase.CommitTransaction();

        SendMailResult(mailId, MAIL_ITEM_TAKEN, MAIL_OK, 0, itemId, count);
        player->SendMailResult(takeItem.MailID, MAIL_ITEM_TAKEN, MAIL_OK, 0, takeItem.AttachID, count);
    }
    else
        SendMailResult(mailId, MAIL_ITEM_TAKEN, MAIL_ERR_EQUIP_ERROR, msg);
        player->SendMailResult(takeItem.MailID, MAIL_ITEM_TAKEN, MAIL_ERR_EQUIP_ERROR, msg);
}
/**
 * Handles the packet sent by the client when taking money from the mail.
 */
void WorldSession::HandleMailTakeMoney(WorldPacket& recv_data)
{
    ObjectGuid mailboxGuid;
    uint32 mailId;
    recv_data >> mailboxGuid;
    recv_data >> mailId;

    if (!CheckMailBox(mailboxGuid))
void WorldSession::HandleMailTakeMoney(WorldPackets::Mail::MailTakeMoney& takeMoney)
{
    if (!CanOpenMailBox(takeMoney.Mailbox))
        return;

    MasterPlayer* pl = GetMasterPlayer();
    Player* loadedPlayer = GetPlayer();
    ASSERT(pl);

    Mail* m = pl->GetMail(mailId);
    if (!m || m->state == MAIL_STATE_DELETED || m->deliver_time > time(nullptr))
    Mail* m = player->GetMail(takeMoney.MailID);
    if ((!m || m->state == MAIL_STATE_DELETED || m->deliver_time > GameTime::GetGameTime()) ||
        (takeMoney.Money > 0 && m->money != uint64(takeMoney.Money)))
    {
        SendMailResult(mailId, MAIL_MONEY_TAKEN, MAIL_ERR_INTERNAL_ERROR);
        player->SendMailResult(takeMoney.MailID, MAIL_MONEY_TAKEN, MAIL_ERR_INTERNAL_ERROR);
        return;
    }

    SendMailResult(mailId, MAIL_MONEY_TAKEN, MAIL_OK);
    if (!player->ModifyMoney(m->money, false))
    {
        player->SendMailResult(takeMoney.MailID, MAIL_MONEY_TAKEN, MAIL_ERR_EQUIP_ERROR, EQUIP_ERR_TOO_MUCH_GOLD);
        return;
    }

    loadedPlayer->LogModifyMoney(m->money, "Mail", ObjectGuid(HIGHGUID_PLAYER, m->sender));
    m->money = 0;
    m->state = MAIL_STATE_CHANGED;
    pl->MarkMailsUpdated();
    player->m_mailsUpdated = true;

    player->SendMailResult(takeMoney.MailID, MAIL_MONEY_TAKEN, MAIL_OK);

    // save money and mail to prevent cheating
    CharacterDatabase.BeginTransaction(loadedPlayer->GetGUIDLow());
    loadedPlayer->SaveGoldToDB();
    pl->SaveMails();
    CharacterDatabase.CommitTransaction();
}

/**
 * Handles the packet sent by the client when requesting the current mail list.
 * It will send a list of all available mails in the players mailbox to the client.
 */
void WorldSession::HandleGetMailList(WorldPacket& recv_data)
//called when player lists his received mails
void WorldSession::HandleGetMailList(WorldPackets::Mail::MailGetList& getList)
{
    ObjectGuid mailboxGuid;
    recv_data >> mailboxGuid;

    if (!CheckMailBox(mailboxGuid))
    if (!CanOpenMailBox(getList.Mailbox))
        return;

    MasterPlayer* pl = GetMasterPlayer();
    ASSERT(pl);

    // client can't work with packets > max int16 value
    // uint32 const maxPacketSize = 32767;

    uint32 mailsCount = 0;                                  // real send to client mails amount

    WorldPacket data(SMSG_MAIL_LIST_RESULT, (200));         // guess size
    data << uint8(0);                                       // mail's count
    time_t cur_time = time(nullptr);
    WorldPackets::Mail::MailListResult response;
    time_t curTime = GameTime::GetGameTime();

    for (PlayerMails::iterator itr = pl->GetMailBegin(); itr != pl->GetMailEnd(); ++itr)
    {
        // packet send mail count as uint8, prevent overflow
        if (mailsCount >= 254)
            break;

        // skip deleted or not delivered (deliver delay not expired) mails
        if ((*itr)->state == MAIL_STATE_DELETED || cur_time < (*itr)->deliver_time || cur_time > (*itr)->expire_time)
            continue;

        /*[-ZERO] TODO recheck this
        size_t next_mail_size = 4+1+8+((*itr)->subject.size()+1)+4*7+1+item_count*(1+4+4+6*3*4+4+4+1+4+4+4);

        if (data.wpos()+next_mail_size > maxPacketSize)
            break;
        */

        data << uint32((*itr)->messageID);                  // Message ID
        data << uint8((*itr)->messageType);                 // Message Type

        switch ((*itr)->messageType)
        {
            case MAIL_NORMAL:                               // sender guid
                data << ObjectGuid(HIGHGUID_PLAYER, (*itr)->sender);
                break;
            case MAIL_CREATURE:
            case MAIL_GAMEOBJECT:
            case MAIL_AUCTION:
                data << (uint32)(*itr)->sender;             // creature/gameobject entry, auction id
                break;
            case MAIL_ITEM:                                 // item entry (?) sender = "Unknown", NYI
                break;
        }

        data << (*itr)->subject;                            // Subject string - once 00, when mail type = 3
        data << uint32((*itr)->itemTextId);                 // sure about this
        data << uint32(0);                                  // unknown
        data << uint32((*itr)->stationery);                 // stationery (Stationery.dbc)

        // 1.12.1 can have only single item
        Item *item = !(*itr)->items.empty() ? pl->GetMItem((*itr)->items[0].itemGuid) : nullptr;

        if (item)
        {
            data << uint32(item->GetEntry());
            data << uint32(item->GetEnchantmentId((EnchantmentSlot)PERM_ENCHANTMENT_SLOT)); // permanent enchantment
            data << uint32(item->GetItemRandomPropertyId());                                // can be negative
            data << uint32(item->GetItemSuffixFactor());                                    // unk
            data << uint8(item->GetCount());                                                // stack count
            data << uint32(item->GetSpellCharges());                                        // charges
            data << uint32(item->GetUInt32Value(ITEM_FIELD_MAXDURABILITY));                 // durability max
            data << uint32(item->GetUInt32Value(ITEM_FIELD_DURABILITY));                    // durability current
        }
        else
        {
            data << uint32(0) << uint32(0) << uint32(0) << uint32(0) << uint8(0) << uint32(0) << uint32(0) << uint32(0);
        }

        data << uint32((*itr)->money);                      // copper
        data << uint32((*itr)->COD);                        // Cash on delivery
        data << uint32((*itr)->checked);                    // flags
        data << float(float((*itr)->expire_time - time(nullptr)) / float(DAY));// Time

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
        data << uint32((*itr)->mailTemplateId);             // mail template (MailTemplate.dbc)
#endif

        mailsCount += 1;
    }

    data.put<uint8>(0, mailsCount);                         // set real send mails to client
    SendPacket(&data);
    player->PlayerTalkClass->GetInteractionData().Reset();
    player->PlayerTalkClass->GetInteractionData().SourceGuid = getList.Mailbox;
    SendPacket(response.Write());

    // recalculate m_nextMailDelivereTime and unReadMails
    pl->UpdateNextMailTimeAndUnreads();
}

/**
 * Handles the packet sent by the client when requesting information about the body of a mail.
 *
 * This function is called when client needs mail message body,
 * or when player clicks on item which has some flag set
 */
void WorldSession::HandleItemTextQuery(WorldPacket& recv_data)
{
    uint32 itemTextId;
    uint32 mailId;                                          // this value can be item id in bag, but it is also mail id
    uint32 unk;                                             // maybe something like state - 0x70000000

    recv_data >> itemTextId >> mailId >> unk;

    ///TODO: some check needed, if player has item with guid mailId, or has mail with id mailId

    DEBUG_LOG("CMSG_ITEM_TEXT_QUERY itemguid: %u, mailId: %u, unk: %u", itemTextId, mailId, unk);

    WorldPacket data(SMSG_ITEM_TEXT_QUERY_RESPONSE, (4 + 10)); // guess size
    data << itemTextId;
    data << sObjectMgr.GetItemText(itemTextId);
    SendPacket(&data);
}

/**
 * Handles the packet sent by the client when he copies the body a mail to his inventory.
 *
 * When a player copies the body of a mail to his inventory this method is called. It will create
 * a new item with the text of the mail and store it in the players inventory (if possible).
 *
 */
void WorldSession::HandleMailCreateTextItem(WorldPacket& recv_data)
//used when player copies mail body to his inventory
void WorldSession::HandleMailCreateTextItem(WorldPackets::Mail::MailCreateTextItem& createTextItem)
{
    ObjectGuid mailboxGuid;
    uint32 mailId;

    recv_data >> mailboxGuid;
    recv_data >> mailId;

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
    recv_data.read_skip<uint32>();                          // mailTemplateId, non need, Mail store own 100% correct value anyway
#endif

    if (!CheckMailBox(mailboxGuid))
    if (!CanOpenMailBox(createTextItem.Mailbox))
        return;

    MasterPlayer* pl = GetMasterPlayer();
    ASSERT(pl);
    Player* loadedPlayer = _player;

    Mail* m = pl->GetMail(mailId);
    if (!m || (!m->itemTextId && !m->mailTemplateId) || m->state == MAIL_STATE_DELETED || m->deliver_time > time(nullptr) || m->checked & MAIL_CHECK_MASK_COPIED)
    Mail* m = player->GetMail(createTextItem.MailID);
    if (!m || (m->body.empty() && !m->mailTemplateId) || m->state == MAIL_STATE_DELETED || m->deliver_time > GameTime::GetGameTime() || (m->checked & MAIL_CHECK_MASK_COPIED))
    {
        SendMailResult(mailId, MAIL_MADE_PERMANENT, MAIL_ERR_INTERNAL_ERROR);
        player->SendMailResult(createTextItem.MailID, MAIL_MADE_PERMANENT, MAIL_ERR_INTERNAL_ERROR);
        return;
    }

    uint32 itemTextId = m->itemTextId;

    Item *bodyItem = new Item;                              // This is not bag and then can be used new Item.
    if (!bodyItem->Create(sObjectMgr.GenerateItemLowGuid(), MAIL_BODY_ITEM_TEMPLATE, pl->GetObjectGuid()))
    {
        delete bodyItem;
        return;
    }

    bodyItem->SetUInt32Value(ITEM_FIELD_ITEM_TEXT_ID, itemTextId);
    bodyItem->SetGuidValue(ITEM_FIELD_CREATOR, ObjectGuid(HIGHGUID_PLAYER, m->sender));

    DETAIL_LOG("HandleMailCreateTextItem mailid=%u", mailId);
    bodyItem->SetItemFlag(ITEM_FIELD_FLAG_READABLE);

    ItemPosCountVec dest;
    uint8 msg = _player->CanStoreItem(NULL_BAG, NULL_SLOT, dest, bodyItem, false);
    if (msg == EQUIP_ERR_OK)
    {
        m->checked = m->checked | MAIL_CHECK_MASK_COPIED;
        m->state = MAIL_STATE_CHANGED;
        pl->MarkMailsUpdated();

        loadedPlayer->StoreItem(dest, bodyItem, true);
        SendMailResult(mailId, MAIL_MADE_PERMANENT, MAIL_OK);
        player->StoreItem(dest, bodyItem, true);
        player->SendMailResult(createTextItem.MailID, MAIL_MADE_PERMANENT, MAIL_OK);
    }
    else
    {
        SendMailResult(mailId, MAIL_MADE_PERMANENT, MAIL_ERR_EQUIP_ERROR, msg);
        player->SendMailResult(createTextItem.MailID, MAIL_MADE_PERMANENT, MAIL_ERR_EQUIP_ERROR, msg);
        delete bodyItem;
    }
}

/**
 * No idea when this is called.
 */
void WorldSession::HandleQueryNextMailTime(WorldPacket& /**recv_data*/)
{
    MasterPlayer* player = GetMasterPlayer();
    ASSERT(player);
    WorldPacket data(MSG_QUERY_NEXT_MAIL_TIME, 8);
    if (player->HasUnreadMail())
        data << float(0);
    else
        data << float(-86400.0f);
    SendPacket(&data);
}
void WorldSession::HandleQueryNextMailTime(WorldPackets::Mail::MailQueryNextMailTime& /*queryNextMailTime*/)
{
    WorldPackets::Mail::MailQueryNextTimeResult result;

    if (_player->unReadMails > 0)
    {
        result.NextMailTime = 0.0f;

        time_t now = GameTime::GetGameTime();
        std::set<ObjectGuid::LowType> sentSenders;

        for (Mail* mail : _player->GetMails())
        {
            if (mail->checked & MAIL_CHECK_MASK_READ)
                continue;

            // already delivered
            if (now < mail->deliver_time)
                continue;

            // only send each mail sender once
            if (sentSenders.count(mail->sender))
                continue;

            result.Next.emplace_back(mail);

            sentSenders.insert(mail->sender);

            // do not send more than 2 mails
            if (sentSenders.size() > 2)
                break;
        }
    }
    else
        result.NextMailTime = -DAY;

/*! @} */
