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

#include "WorldSession.h"
#include "AccountMgr.h"
#include "BattlenetAccountMgr.h"
#include "CharacterCache.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "GossipDef.h"
#include "GameTime.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "Item.h"
#include "Language.h"
#include "Log.h"
#include "Mail.h"
#include "MailPackets.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "World.h"

bool WorldSession::CanOpenMailBox(ObjectGuid guid)
{
    if (guid == _player->GetGUID())
    {
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
    else
        return false;

    return true;
}

void WorldSession::HandleSendMail(WorldPackets::Mail::SendMail& sendMail)
{
    if (sendMail.Info.Attachments.size() > MAX_CLIENT_MAIL_ITEMS)        // client limit
    {
        GetPlayer()->SendMailResult(0, MAIL_SEND, MAIL_ERR_TOO_MANY_ATTACHMENTS);
        return;
    }

    if (!CanOpenMailBox(sendMail.Info.Mailbox))
        return;

    if (sendMail.Info.Target.empty())
        return;

    if (!ValidateHyperlinksAndMaybeKick(sendMail.Info.Subject) || !ValidateHyperlinksAndMaybeKick(sendMail.Info.Body))
        return;

    Player* player = _player;

    if (player->GetLevel() < sWorld->getIntConfig(CONFIG_MAIL_LEVEL_REQ))
    {
        SendNotification(GetTrinityString(LANG_MAIL_SENDER_REQ), sWorld->getIntConfig(CONFIG_MAIL_LEVEL_REQ));
        return;
    }

    ObjectGuid receiverGuid;
    if (normalizePlayerName(sendMail.Info.Target))
        receiverGuid = sCharacterCache->GetCharacterGuidByName(sendMail.Info.Target);

    if (!receiverGuid)
    {
        TC_LOG_INFO("network", "Player {} is sending mail to {} (GUID: non-existing!) with subject {} "
            "and body {} includes {} items, {} copper and {} COD copper with StationeryID = {}",
            GetPlayerInfo(), sendMail.Info.Target, sendMail.Info.Subject, sendMail.Info.Body,
            sendMail.Info.Attachments.size(), sendMail.Info.SendMoney, sendMail.Info.Cod, sendMail.Info.StationeryID);
        player->SendMailResult(0, MAIL_SEND, MAIL_ERR_RECIPIENT_NOT_FOUND);
        return;
    }

    if (sendMail.Info.SendMoney < 0)
    {
        GetPlayer()->SendMailResult(0, MAIL_SEND, MAIL_ERR_INTERNAL_ERROR);
        TC_LOG_WARN("cheat", "Player {} attempted to send mail to {} ({}) with negative money value (SendMoney: {})",
            GetPlayerInfo(), sendMail.Info.Target, receiverGuid.ToString(), sendMail.Info.SendMoney);
        return;
    }

    if (sendMail.Info.Cod < 0)
    {
        GetPlayer()->SendMailResult(0, MAIL_SEND, MAIL_ERR_INTERNAL_ERROR);
        TC_LOG_WARN("cheat", "Player {} attempted to send mail to {} ({}) with negative COD value (Cod: {})",
            GetPlayerInfo(), sendMail.Info.Target, receiverGuid.ToString(), sendMail.Info.Cod);
        return;
    }

    TC_LOG_INFO("network", "Player {} is sending mail to {} ({}) with subject {} and body {} "
        "includes {} items, {} copper and " SI64FMTD  " COD copper with StationeryID = {}",
        GetPlayerInfo(), sendMail.Info.Target, receiverGuid.ToString(), sendMail.Info.Subject,
        sendMail.Info.Body, sendMail.Info.Attachments.size(), sendMail.Info.SendMoney, sendMail.Info.Cod, sendMail.Info.StationeryID);

    if (player->GetGUID() == receiverGuid)
    {
        player->SendMailResult(0, MAIL_SEND, MAIL_ERR_CANNOT_SEND_TO_SELF);
        return;
    }

    uint32 cost = !sendMail.Info.Attachments.empty() ? 30 * sendMail.Info.Attachments.size() : 30;  // price hardcoded in client

    int64 reqmoney = cost + sendMail.Info.SendMoney;

    // Check for overflow
    if (reqmoney < sendMail.Info.SendMoney)
    {
        player->SendMailResult(0, MAIL_SEND, MAIL_ERR_NOT_ENOUGH_MONEY);
        return;
    }

    auto mailCountCheckContinuation = [this, player = _player, receiverGuid, mailInfo = std::move(sendMail.Info), reqmoney, cost](Team receiverTeam, uint64 mailsCount, uint8 receiverLevel, uint32 receiverAccountId, uint32 receiverBnetAccountId) mutable
    {
        if (_player != player)
            return;

        if (!player->HasEnoughMoney(reqmoney) && !player->IsGameMaster())
        {
            player->SendMailResult(0, MAIL_SEND, MAIL_ERR_NOT_ENOUGH_MONEY);
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

        if (!accountBound && player->GetTeam() != receiverTeam && !HasPermission(rbac::RBAC_PERM_TWO_SIDE_INTERACTION_MAIL))
        {
            player->SendMailResult(0, MAIL_SEND, MAIL_ERR_NOT_YOUR_TEAM);
            return;
        }

        if (receiverLevel < sWorld->getIntConfig(CONFIG_MAIL_LEVEL_REQ))
        {
            SendNotification(GetTrinityString(LANG_MAIL_RECEIVER_REQ), sWorld->getIntConfig(CONFIG_MAIL_LEVEL_REQ));
            return;
        }

        std::vector<Item*> items;

        for (WorldPackets::Mail::SendMail::StructSendMail::MailAttachment const& att : mailInfo.Attachments)
        {
            if (att.ItemGUID.IsEmpty())
            {
                player->SendMailResult(0, MAIL_SEND, MAIL_ERR_MAIL_ATTACHMENT_INVALID);
                return;
            }

            Item* item = player->GetItemByGuid(att.ItemGUID);

            // prevent sending bag with items (cheat: can be placed in bag after adding equipped empty bag to mail)
            if (!item)
            {
                player->SendMailResult(0, MAIL_SEND, MAIL_ERR_MAIL_ATTACHMENT_INVALID);
                return;
            }

            // handle empty bag before CanBeTraded, since that func already has that check
            if (item->IsNotEmptyBag())
            {
                player->SendMailResult(0, MAIL_SEND, MAIL_ERR_EQUIP_ERROR, EQUIP_ERR_DESTROY_NONEMPTY_BAG);
                return;
            }

            if (!item->CanBeTraded(true))
            {
                player->SendMailResult(0, MAIL_SEND, MAIL_ERR_EQUIP_ERROR, EQUIP_ERR_MAIL_BOUND_ITEM);
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

            if (item->GetTemplate()->HasFlag(ITEM_FLAG_CONJURED) || *item->m_itemData->Expiration)
            {
                player->SendMailResult(0, MAIL_SEND, MAIL_ERR_EQUIP_ERROR, EQUIP_ERR_MAIL_BOUND_ITEM);
                return;
            }

            if (mailInfo.Cod && item->IsWrapped())
            {
                player->SendMailResult(0, MAIL_SEND, MAIL_ERR_CANT_SEND_WRAPPED_COD);
                return;
            }

            items.push_back(item);
        }

        player->SendMailResult(0, MAIL_SEND, MAIL_OK);

        player->ModifyMoney(-reqmoney);
        player->UpdateCriteria(CriteriaType::MoneySpentOnPostage, cost);

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

                    item->SetNotRefundable(GetPlayer()); // makes the item no longer refundable
                    player->MoveItemFromInventory(item->GetBagSlot(), item->GetSlot(), true);

                    item->DeleteFromInventoryDB(trans);     // deletes item from character's inventory
                    item->SetOwnerGUID(receiverGuid);
                    item->SetState(ITEM_CHANGED);
                    item->SaveToDB(trans);                  // recursive and not have transaction guard into self, item not in inventory and can be save standalone

                    draft.AddItem(item);
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

        // If theres is an item, there is a one hour delivery delay if sent to another account's character.
        uint32 deliver_delay = needItemDelay ? sWorld->getIntConfig(CONFIG_MAIL_DELIVERY_DELAY) : 0;

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

//called when mail is read
void WorldSession::HandleMailMarkAsRead(WorldPackets::Mail::MailMarkAsRead& markAsRead)
{
    if (!CanOpenMailBox(markAsRead.Mailbox))
        return;

    Player* player = _player;
    Mail* m = player->GetMail(markAsRead.MailID);
    if (m && m->state != MAIL_STATE_DELETED)
    {
        if (player->unReadMails)
            --player->unReadMails;
        m->checked = m->checked | MAIL_CHECK_MASK_READ;
        player->m_mailsUpdated = true;
        m->state = MAIL_STATE_CHANGED;
    }
}

//called when client deletes mail
void WorldSession::HandleMailDelete(WorldPackets::Mail::MailDelete& mailDelete)
{
    Mail* m = _player->GetMail(mailDelete.MailID);
    Player* player = _player;
    player->m_mailsUpdated = true;
    if (m)
    {
        // delete shouldn't show up for COD mails
        if (m->COD)
        {
            player->SendMailResult(mailDelete.MailID, MAIL_DELETED, MAIL_ERR_INTERNAL_ERROR);
            return;
        }

        m->state = MAIL_STATE_DELETED;
    }
    player->SendMailResult(mailDelete.MailID, MAIL_DELETED, MAIL_OK);
}

void WorldSession::HandleMailReturnToSender(WorldPackets::Mail::MailReturnToSender& returnToSender)
{
    if (!CanOpenMailBox(_player->PlayerTalkClass->GetInteractionData().SourceGuid))
        return;

    Player* player = _player;
    Mail* m = player->GetMail(returnToSender.MailID);
    if (!m || m->state == MAIL_STATE_DELETED || m->deliver_time > GameTime::GetGameTime() || m->sender != returnToSender.SenderGUID.GetCounter())
    {
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

    player->RemoveMail(returnToSender.MailID);

    // only return mail if the player exists (and delete if not existing)
    if (m->messageType == MAIL_NORMAL && m->sender)
    {
        MailDraft draft(m->subject, m->body);
        if (m->mailTemplateId)
            draft = MailDraft(m->mailTemplateId, false);     // items already included

        if (m->HasItems())
        {
            for (MailItemInfoVec::iterator itr2 = m->items.begin(); itr2 != m->items.end(); ++itr2)
            {
                if (Item* const item = player->GetMItem(itr2->item_guid))
                    draft.AddItem(item);
                player->RemoveMItem(itr2->item_guid);
            }
        }
        draft.AddMoney(m->money).SendReturnToSender(GetAccountId(), m->receiver, m->sender, trans);
    }

    CharacterDatabase.CommitTransaction(trans);

    delete m;                                               //we can deallocate old mail
    player->SendMailResult(returnToSender.MailID, MAIL_RETURNED_TO_SENDER, MAIL_OK);
}

//called when player takes item attached in mail
void WorldSession::HandleMailTakeItem(WorldPackets::Mail::MailTakeItem& takeItem)
{
    uint64 AttachID = takeItem.AttachID;

    if (!CanOpenMailBox(takeItem.Mailbox))
        return;

    Player* player = _player;

    Mail* m = player->GetMail(takeItem.MailID);
    if (!m || m->state == MAIL_STATE_DELETED || m->deliver_time > GameTime::GetGameTime())
    {
        player->SendMailResult(takeItem.MailID, MAIL_ITEM_TAKEN, MAIL_ERR_INTERNAL_ERROR);
        return;
    }

    // verify that the mail has the item to avoid cheaters taking COD items without paying
    if (std::find_if(m->items.begin(), m->items.end(), [AttachID](MailItemInfo info){ return info.item_guid == AttachID; }) == m->items.end())
    {
        player->SendMailResult(takeItem.MailID, MAIL_ITEM_TAKEN, MAIL_ERR_INTERNAL_ERROR);
        return;
    }

    // prevent cheating with skip client money check
    if (!player->HasEnoughMoney(m->COD))
    {
        player->SendMailResult(takeItem.MailID, MAIL_ITEM_TAKEN, MAIL_ERR_NOT_ENOUGH_MONEY);
        return;
    }

    Item* it = player->GetMItem(takeItem.AttachID);

    ItemPosCountVec dest;
    uint8 msg = _player->CanStoreItem(NULL_BAG, NULL_SLOT, dest, it, false);
    if (msg == EQUIP_ERR_OK)
    {
        CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
        m->RemoveItem(takeItem.AttachID);
        m->removedItems.push_back(takeItem.AttachID);

        if (m->COD > 0)                                     //if there is COD, take COD money from player and send them to sender by mail
        {
            ObjectGuid sender_guid = ObjectGuid::Create<HighGuid::Player>(m->sender);
            Player* receiver = ObjectAccessor::FindConnectedPlayer(sender_guid);

            uint32 sender_accId = 0;

            if (HasPermission(rbac::RBAC_PERM_LOG_GM_TRADE))
            {
                std::string sender_name;
                if (receiver)
                {
                    sender_accId = receiver->GetSession()->GetAccountId();
                    sender_name = receiver->GetName();
                }
                else
                {
                    // can be calculated early
                    sender_accId = sCharacterCache->GetCharacterAccountIdByGuid(sender_guid);

                    if (!sCharacterCache->GetCharacterNameByGuid(sender_guid, sender_name))
                        sender_name = sObjectMgr->GetTrinityStringForDBCLocale(LANG_UNKNOWN);
                }
                sLog->OutCommand(GetAccountId(), "GM {} (Account: {}) receiver mail item: {} (Entry: {} Count: {}) and send COD money: {} to player: {} (Account: {})",
                    GetPlayerName(), GetAccountId(), it->GetTemplate()->GetDefaultLocaleName(), it->GetEntry(), it->GetCount(), m->COD, sender_name, sender_accId);
            }
            else if (!receiver)
                sender_accId = sCharacterCache->GetCharacterAccountIdByGuid(sender_guid);

            // check player existence
            if (receiver || sender_accId)
            {
                MailDraft(m->subject, "")
                    .AddMoney(m->COD)
                    .SendMailTo(trans, MailReceiver(receiver, m->sender), MailSender(MAIL_NORMAL, m->receiver), MAIL_CHECK_MASK_COD_PAYMENT);
            }

            player->ModifyMoney(-int64(m->COD));
        }
        m->COD = 0;
        m->state = MAIL_STATE_CHANGED;
        player->m_mailsUpdated = true;
        player->RemoveMItem(it->GetGUID().GetCounter());

        uint32 count = it->GetCount();                      // save counts before store and possible merge with deleting
        it->SetState(ITEM_UNCHANGED);                       // need to set this state, otherwise item cannot be removed later, if neccessary
        player->MoveItemToInventory(dest, it, true);

        player->SaveInventoryAndGoldToDB(trans);
        player->_SaveMail(trans);
        CharacterDatabase.CommitTransaction(trans);

        player->SendMailResult(takeItem.MailID, MAIL_ITEM_TAKEN, MAIL_OK, 0, takeItem.AttachID, count);
    }
    else
        player->SendMailResult(takeItem.MailID, MAIL_ITEM_TAKEN, MAIL_ERR_EQUIP_ERROR, msg);
}

void WorldSession::HandleMailTakeMoney(WorldPackets::Mail::MailTakeMoney& takeMoney)
{
    if (!CanOpenMailBox(takeMoney.Mailbox))
        return;

    Player* player = _player;

    Mail* m = player->GetMail(takeMoney.MailID);
    if ((!m || m->state == MAIL_STATE_DELETED || m->deliver_time > GameTime::GetGameTime()) ||
        (takeMoney.Money > 0 && m->money != uint64(takeMoney.Money)))
    {
        player->SendMailResult(takeMoney.MailID, MAIL_MONEY_TAKEN, MAIL_ERR_INTERNAL_ERROR);
        return;
    }

    if (!player->ModifyMoney(m->money, false))
    {
        player->SendMailResult(takeMoney.MailID, MAIL_MONEY_TAKEN, MAIL_ERR_EQUIP_ERROR, EQUIP_ERR_TOO_MUCH_GOLD);
        return;
    }

    m->money = 0;
    m->state = MAIL_STATE_CHANGED;
    player->m_mailsUpdated = true;

    player->SendMailResult(takeMoney.MailID, MAIL_MONEY_TAKEN, MAIL_OK);

    // save money and mail to prevent cheating
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    player->SaveGoldToDB(trans);
    player->_SaveMail(trans);
    CharacterDatabase.CommitTransaction(trans);
}

//called when player lists his received mails
void WorldSession::HandleGetMailList(WorldPackets::Mail::MailGetList& getList)
{
    if (!CanOpenMailBox(getList.Mailbox))
        return;

    Player* player = _player;

    WorldPackets::Mail::MailListResult response;
    time_t curTime = GameTime::GetGameTime();

    for (Mail* m : player->GetMails())
    {
        // skip deleted or not delivered (deliver delay not expired) mails
        if (m->state == MAIL_STATE_DELETED || curTime < m->deliver_time)
            continue;

        // max. 100 mails can be sent
        if (response.Mails.size() < 100)
            response.Mails.emplace_back(m, player);

        ++response.TotalNumRecords;
    }

    player->PlayerTalkClass->GetInteractionData().Reset();
    player->PlayerTalkClass->GetInteractionData().SourceGuid = getList.Mailbox;
    SendPacket(response.Write());

    // recalculate m_nextMailDelivereTime and unReadMails
    _player->UpdateNextMailTimeAndUnreads();
}

//used when player copies mail body to his inventory
void WorldSession::HandleMailCreateTextItem(WorldPackets::Mail::MailCreateTextItem& createTextItem)
{
    if (!CanOpenMailBox(createTextItem.Mailbox))
        return;

    Player* player = _player;

    Mail* m = player->GetMail(createTextItem.MailID);
    if (!m || (m->body.empty() && !m->mailTemplateId) || m->state == MAIL_STATE_DELETED || m->deliver_time > GameTime::GetGameTime() || (m->checked & MAIL_CHECK_MASK_COPIED))
    {
        player->SendMailResult(createTextItem.MailID, MAIL_MADE_PERMANENT, MAIL_ERR_INTERNAL_ERROR);
        return;
    }

    Item* bodyItem = Item::CreateItem(MAIL_BODY_ITEM_TEMPLATE, 1, ItemContext::NONE, player);
    if (!bodyItem)
        return;

    // in mail template case we need create new item text
    if (m->mailTemplateId)
    {
        MailTemplateEntry const* mailTemplateEntry = sMailTemplateStore.LookupEntry(m->mailTemplateId);
        ASSERT(mailTemplateEntry);
        bodyItem->SetText(mailTemplateEntry->Body[GetSessionDbcLocale()]);
    }
    else
        bodyItem->SetText(m->body);

    if (m->messageType == MAIL_NORMAL)
        bodyItem->SetCreator(ObjectGuid::Create<HighGuid::Player>(m->sender));

    bodyItem->SetItemFlag(ITEM_FIELD_FLAG_READABLE);

    ItemPosCountVec dest;
    uint8 msg = _player->CanStoreItem(NULL_BAG, NULL_SLOT, dest, bodyItem, false);
    if (msg == EQUIP_ERR_OK)
    {
        m->checked = m->checked | MAIL_CHECK_MASK_COPIED;
        m->state = MAIL_STATE_CHANGED;
        player->m_mailsUpdated = true;

        player->StoreItem(dest, bodyItem, true);
        player->SendMailResult(createTextItem.MailID, MAIL_MADE_PERMANENT, MAIL_OK);
    }
    else
    {
        player->SendMailResult(createTextItem.MailID, MAIL_MADE_PERMANENT, MAIL_ERR_EQUIP_ERROR, msg);
        delete bodyItem;
    }
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

    SendPacket(result.Write());
}
