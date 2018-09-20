/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "CharacterCache.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "GameTime.h"
#include "Item.h"
#include "Language.h"
#include "Log.h"
#include "Mail.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Player.h"
#include "World.h"
#include "WorldPacket.h"

bool WorldSession::CanOpenMailBox(ObjectGuid guid)
{
    if (guid == _player->GetGUID())
    {
        if (!HasPermission(rbac::RBAC_PERM_COMMAND_MAILBOX))
        {
            TC_LOG_WARN("cheat", "%s attempted to open mailbox by using a cheat.", _player->GetName().c_str());
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
        if (!_player->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_MAILBOX))
            return false;
    }
    else
        return false;

    return true;
}

void WorldSession::HandleSendMail(WorldPacket& recvData)
{
    ObjectGuid mailbox, unk3;
    std::string receiverName, subject, body;
    uint32 stationery, package, money, COD;
    uint8 unk4;
    uint8 items_count;
    recvData >> mailbox >> receiverName >> subject >> body
             >> stationery                                 // stationery?
             >> package                                    // 0x00000000
             >> items_count;                               // attached items count

    if (items_count > MAX_MAIL_ITEMS)                      // client limit
    {
        GetPlayer()->SendMailResult(0, MAIL_SEND, MAIL_ERR_TOO_MANY_ATTACHMENTS);
        recvData.rfinish();                   // set to end to avoid warnings spam
        return;
    }

    ObjectGuid itemGUIDs[MAX_MAIL_ITEMS];

    for (uint8 i = 0; i < items_count; ++i)
    {
        recvData.read_skip<uint8>();                       // item slot in mail, not used
        recvData >> itemGUIDs[i];
    }

    recvData >> money >> COD;                              // money and cod
    recvData >> unk3;                                      // const 0
    recvData >> unk4;                                      // const 0

    // packet read complete, now do check

    if (!CanOpenMailBox(mailbox))
        return;

    if (receiverName.empty())
        return;

    Player* player = _player;

    if (player->getLevel() < sWorld->getIntConfig(CONFIG_MAIL_LEVEL_REQ))
    {
        SendNotification(GetTrinityString(LANG_MAIL_SENDER_REQ), sWorld->getIntConfig(CONFIG_MAIL_LEVEL_REQ));
        return;
    }

    ObjectGuid receiverGuid;
    if (normalizePlayerName(receiverName))
        receiverGuid = sCharacterCache->GetCharacterGuidByName(receiverName);

    if (!receiverGuid)
    {
        TC_LOG_INFO("network", "Player %u is sending mail to %s (GUID: non-existing!) with subject %s "
            "and body %s includes %u items, %u copper and %u COD copper with unk1 = %u, unk2 = %u",
            player->GetGUID().GetCounter(), receiverName.c_str(), subject.c_str(), body.c_str(),
            items_count, money, COD, stationery, package);
        player->SendMailResult(0, MAIL_SEND, MAIL_ERR_RECIPIENT_NOT_FOUND);
        return;
    }

    TC_LOG_INFO("network", "Player %u is sending mail to %s (%s) with subject %s and body %s "
        "including %u items, %u copper and %u COD copper with unk1 = %u, unk2 = %u",
        player->GetGUID().GetCounter(), receiverName.c_str(), receiverGuid.ToString().c_str(), subject.c_str(),
        body.c_str(), items_count, money, COD, stationery, package);

    if (player->GetGUID() == receiverGuid)
    {
        player->SendMailResult(0, MAIL_SEND, MAIL_ERR_CANNOT_SEND_TO_SELF);
        return;
    }

    uint32 cost = items_count ? 30 * items_count : 30;  // price hardcoded in client

    uint32 reqmoney = cost + money;

    // Check for overflow
    if (reqmoney < money)
    {
        player->SendMailResult(0, MAIL_SEND, MAIL_ERR_NOT_ENOUGH_MONEY);
        return;
    }

    if (!player->HasEnoughMoney(reqmoney) && !player->IsGameMaster())
    {
        player->SendMailResult(0, MAIL_SEND, MAIL_ERR_NOT_ENOUGH_MONEY);
        return;
    }

    Player* receiver = ObjectAccessor::FindConnectedPlayer(receiverGuid);

    uint32 receiverTeam = 0;
    uint8 mailsCount = 0;                                  //do not allow to send to one player more than 100 mails
    uint8 receiverLevel = 0;
    uint32 receiverAccountId = 0;

    if (receiver)
    {
        receiverTeam = receiver->GetTeam();
        mailsCount = receiver->GetMailSize();
        receiverLevel = receiver->getLevel();
        receiverAccountId = receiver->GetSession()->GetAccountId();
    }
    else
    {
        if (CharacterCacheEntry const* characterInfo = sCharacterCache->GetCharacterCacheByGuid(receiverGuid))
        {
            receiverTeam = Player::TeamForRace(characterInfo->Race);
            receiverLevel = characterInfo->Level;
            receiverAccountId = characterInfo->AccountId;
        }

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_MAIL_COUNT);
        stmt->setUInt32(0, receiverGuid.GetCounter());

        PreparedQueryResult result = CharacterDatabase.Query(stmt);
        if (result)
        {
            Field* fields = result->Fetch();
            mailsCount = fields[0].GetUInt64();
        }
    }

    // do not allow to have more than 100 mails in mailbox.. mails count is in opcode uint8!!! - so max can be 255..
    if (mailsCount > 100)
    {
        player->SendMailResult(0, MAIL_SEND, MAIL_ERR_RECIPIENT_CAP_REACHED);
        return;
    }

    // test the receiver's Faction... or all items are account bound
    bool accountBound = items_count ? true : false;
    for (uint8 i = 0; i < items_count; ++i)
    {
        if (Item* item = player->GetItemByGuid(itemGUIDs[i]))
        {
            ItemTemplate const* itemProto = item->GetTemplate();
            if (!itemProto || !(itemProto->Flags & ITEM_FLAG_IS_BOUND_TO_ACCOUNT))
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

    Item* items[MAX_MAIL_ITEMS];

    for (uint8 i = 0; i < items_count; ++i)
    {
        if (!itemGUIDs[i])
        {
            player->SendMailResult(0, MAIL_SEND, MAIL_ERR_MAIL_ATTACHMENT_INVALID);
            return;
        }

        Item* item = player->GetItemByGuid(itemGUIDs[i]);

        // prevent sending bag with items (cheat: can be placed in bag after adding equipped empty bag to mail)
        if (!item)
        {
            player->SendMailResult(0, MAIL_SEND, MAIL_ERR_MAIL_ATTACHMENT_INVALID);
            return;
        }

        if (!item->CanBeTraded(true))
        {
            player->SendMailResult(0, MAIL_SEND, MAIL_ERR_EQUIP_ERROR, EQUIP_ERR_MAIL_BOUND_ITEM);
            return;
        }

        if (item->IsBoundAccountWide() && item->IsSoulBound() && player->GetSession()->GetAccountId() != receiverAccountId)
        {
            player->SendMailResult(0, MAIL_SEND, MAIL_ERR_EQUIP_ERROR, EQUIP_ERR_ARTEFACTS_ONLY_FOR_OWN_CHARACTERS);
            return;
        }

        if ((item->GetTemplate()->Flags & ITEM_FLAG_CONJURED) || item->GetUInt32Value(ITEM_FIELD_DURATION))
        {
            player->SendMailResult(0, MAIL_SEND, MAIL_ERR_EQUIP_ERROR, EQUIP_ERR_MAIL_BOUND_ITEM);
            return;
        }

        if (COD && item->HasFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_WRAPPED))
        {
            player->SendMailResult(0, MAIL_SEND, MAIL_ERR_CANT_SEND_WRAPPED_COD);
            return;
        }

        if (item->IsNotEmptyBag())
        {
            player->SendMailResult(0, MAIL_SEND, MAIL_ERR_EQUIP_ERROR, EQUIP_ERR_CAN_ONLY_DO_WITH_EMPTY_BAGS);
            return;
        }

        items[i] = item;
    }

    player->SendMailResult(0, MAIL_SEND, MAIL_OK);

    player->ModifyMoney(-int32(reqmoney));
    player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_MAIL, cost);

    bool needItemDelay = false;

    MailDraft draft(subject, body);

    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    if (items_count > 0 || money > 0)
    {
        bool log = HasPermission(rbac::RBAC_PERM_LOG_GM_TRADE);
        if (items_count > 0)
        {
            for (uint8 i = 0; i < items_count; ++i)
            {
                Item* item = items[i];
                if (log)
                {
                    sLog->outCommand(GetAccountId(), "GM %s (GUID: %u) (Account: %u) mail item: %s (Entry: %u Count: %u) "
                        "to: %s (%s) (Account: %u)", GetPlayerName().c_str(), GetGUIDLow(), GetAccountId(),
                        item->GetTemplate()->Name1.c_str(), item->GetEntry(), item->GetCount(),
                        receiverName.c_str(), receiverGuid.ToString().c_str(), receiverAccountId);
                }

                item->SetNotRefundable(GetPlayer()); // makes the item no longer refundable
                player->MoveItemFromInventory(items[i]->GetBagSlot(), item->GetSlot(), true);

                item->DeleteFromInventoryDB(trans);     // deletes item from character's inventory
                item->SetOwnerGUID(receiverGuid);
                item->SetState(ITEM_CHANGED);
                item->SaveToDB(trans);                  // recursive and not have transaction guard into self, item not in inventory and can be save standalone

                draft.AddItem(item);
            }

            // if item send to character at another account, then apply item delivery delay
            needItemDelay = player->GetSession()->GetAccountId() != receiverAccountId;
        }

        if (log && money > 0)
        {
            sLog->outCommand(GetAccountId(), "GM %s (GUID: %u) (Account: %u) mail money: %u to: %s (%s) (Account: %u)",
                GetPlayerName().c_str(), GetGUIDLow(), GetAccountId(), money, receiverName.c_str(), receiverGuid.ToString().c_str(), receiverAccountId);
        }
    }

    // If theres is an item, there is a one hour delivery delay if sent to another account's character.
    uint32 deliver_delay = needItemDelay ? sWorld->getIntConfig(CONFIG_MAIL_DELIVERY_DELAY) : 0;

    // don't ask for COD if there are no items
    if (items_count == 0)
        COD = 0;

    // will delete item or place to receiver mail list
    draft
        .AddMoney(money)
        .AddCOD(COD)
        .SendMailTo(trans, MailReceiver(receiver, receiverGuid.GetCounter()), MailSender(player), body.empty() ? MAIL_CHECK_MASK_COPIED : MAIL_CHECK_MASK_HAS_BODY, deliver_delay);

    player->SaveInventoryAndGoldToDB(trans);
    CharacterDatabase.CommitTransaction(trans);
}

//called when mail is read
void WorldSession::HandleMailMarkAsRead(WorldPacket& recvData)
{
    ObjectGuid mailbox;
    uint32 mailId;
    recvData >> mailbox;
    recvData >> mailId;

    if (!CanOpenMailBox(mailbox))
        return;

    Player* player = _player;
    Mail* m = player->GetMail(mailId);
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
void WorldSession::HandleMailDelete(WorldPacket& recvData)
{
    ObjectGuid mailbox;
    uint32 mailId;
    recvData >> mailbox;
    recvData >> mailId;
    recvData.read_skip<uint32>();                          // mailTemplateId

    if (!CanOpenMailBox(mailbox))
        return;

    Mail* m = _player->GetMail(mailId);
    Player* player = _player;
    player->m_mailsUpdated = true;
    if (m)
    {
        // delete shouldn't show up for COD mails
        if (m->COD)
        {
            player->SendMailResult(mailId, MAIL_DELETED, MAIL_ERR_INTERNAL_ERROR);
            return;
        }

        m->state = MAIL_STATE_DELETED;
    }
    player->SendMailResult(mailId, MAIL_DELETED, MAIL_OK);
}

void WorldSession::HandleMailReturnToSender(WorldPacket& recvData)
{
    ObjectGuid mailbox;
    uint32 mailId;
    recvData >> mailbox;
    recvData >> mailId;
    recvData.read_skip<uint64>();                          // original sender GUID for return to, not used

    if (!CanOpenMailBox(mailbox))
        return;

    Player* player = _player;
    Mail* m = player->GetMail(mailId);
    if (!m || m->state == MAIL_STATE_DELETED || m->deliver_time > GameTime::GetGameTime())
    {
        player->SendMailResult(mailId, MAIL_RETURNED_TO_SENDER, MAIL_ERR_INTERNAL_ERROR);
        return;
    }
    //we can return mail now
    //so firstly delete the old one
    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL_BY_ID);
    stmt->setUInt32(0, mailId);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL_ITEM_BY_ID);
    stmt->setUInt32(0, mailId);
    trans->Append(stmt);

    player->RemoveMail(mailId);

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
                Item* item = player->GetMItem(itr2->item_guid);
                if (item)
                    draft.AddItem(item);
                else
                {
                    //WTF?
                }

                player->RemoveMItem(itr2->item_guid);
            }
        }
        draft.AddMoney(m->money).SendReturnToSender(GetAccountId(), m->receiver, m->sender, trans);
    }

    CharacterDatabase.CommitTransaction(trans);

    delete m;                                               //we can deallocate old mail
    player->SendMailResult(mailId, MAIL_RETURNED_TO_SENDER, MAIL_OK);
}

//called when player takes item attached in mail
void WorldSession::HandleMailTakeItem(WorldPacket& recvData)
{
    ObjectGuid mailbox;
    uint32 mailId;
    uint32 itemId;
    recvData >> mailbox;
    recvData >> mailId;
    recvData >> itemId;                                    // item guid low

    if (!CanOpenMailBox(mailbox))
        return;

    Player* player = _player;

    Mail* m = player->GetMail(mailId);
    if (!m || m->state == MAIL_STATE_DELETED || m->deliver_time > GameTime::GetGameTime())
    {
        player->SendMailResult(mailId, MAIL_ITEM_TAKEN, MAIL_ERR_INTERNAL_ERROR);
        return;
    }

    // verify that the mail has the item to avoid cheaters taking COD items without paying
    if (std::find_if(m->items.begin(), m->items.end(), [itemId](MailItemInfo info){ return info.item_guid == itemId; }) == m->items.end())
    {
        player->SendMailResult(mailId, MAIL_ITEM_TAKEN, MAIL_ERR_INTERNAL_ERROR);
        return;
    }

    // prevent cheating with skip client money check
    if (!player->HasEnoughMoney(m->COD))
    {
        player->SendMailResult(mailId, MAIL_ITEM_TAKEN, MAIL_ERR_NOT_ENOUGH_MONEY);
        return;
    }

    Item* it = player->GetMItem(itemId);

    ItemPosCountVec dest;
    uint8 msg = _player->CanStoreItem(NULL_BAG, NULL_SLOT, dest, it, false);
    if (msg == EQUIP_ERR_OK)
    {
        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        m->RemoveItem(itemId);
        m->removedItems.push_back(itemId);

        if (m->COD > 0)                                     //if there is COD, take COD money from player and send them to sender by mail
        {
            ObjectGuid sender_guid(HighGuid::Player, m->sender);
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
                sLog->outCommand(GetAccountId(), "GM %s (Account: %u) receiver mail item: %s (Entry: %u Count: %u) and send COD money: %u to player: %s (Account: %u)",
                    GetPlayerName().c_str(), GetAccountId(), it->GetTemplate()->Name1.c_str(), it->GetEntry(), it->GetCount(), m->COD, sender_name.c_str(), sender_accId);
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

            player->ModifyMoney(-int32(m->COD));
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

        player->SendMailResult(mailId, MAIL_ITEM_TAKEN, MAIL_OK, 0, itemId, count);
    }
    else
        player->SendMailResult(mailId, MAIL_ITEM_TAKEN, MAIL_ERR_EQUIP_ERROR, msg);
}

void WorldSession::HandleMailTakeMoney(WorldPacket& recvData)
{
    ObjectGuid mailbox;
    uint32 mailId;
    recvData >> mailbox;
    recvData >> mailId;

    if (!CanOpenMailBox(mailbox))
        return;

    Player* player = _player;

    Mail* m = player->GetMail(mailId);
    if (!m || m->state == MAIL_STATE_DELETED || m->deliver_time > GameTime::GetGameTime())
    {
        player->SendMailResult(mailId, MAIL_MONEY_TAKEN, MAIL_ERR_INTERNAL_ERROR);
        return;
    }

    if (!player->ModifyMoney(m->money, false))
    {
        player->SendMailResult(mailId, MAIL_MONEY_TAKEN, MAIL_ERR_EQUIP_ERROR, EQUIP_ERR_TOO_MUCH_GOLD);
        return;
    }

    m->money = 0;
    m->state = MAIL_STATE_CHANGED;
    player->m_mailsUpdated = true;

    player->SendMailResult(mailId, MAIL_MONEY_TAKEN, MAIL_OK);

    // save money and mail to prevent cheating
    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    player->SaveGoldToDB(trans);
    player->_SaveMail(trans);
    CharacterDatabase.CommitTransaction(trans);
}

//called when player lists his received mails
void WorldSession::HandleGetMailList(WorldPacket& recvData)
{
    ObjectGuid mailbox;
    recvData >> mailbox;

    if (!CanOpenMailBox(mailbox))
        return;

    Player* player = _player;

    //load players mails, and mailed items
    if (!player->m_mailsLoaded)
        player->_LoadMail();

    // client can't work with packets > max int16 value
    const uint32 maxPacketSize = 32767;

    uint32 mailsCount = 0;                                 // real send to client mails amount
    uint32 realCount  = 0;                                 // real mails amount

    WorldPacket data(SMSG_MAIL_LIST_RESULT, (200));         // guess size
    data << uint32(0);                                      // real mail's count
    data << uint8(0);                                       // mail's count
    time_t cur_time = GameTime::GetGameTime();

    for (PlayerMails::iterator itr = player->GetMailBegin(); itr != player->GetMailEnd(); ++itr)
    {
        // Only first 50 mails are displayed
        if (mailsCount >= 50)
        {
            realCount += 1;
            continue;
        }

        // skip deleted or not delivered (deliver delay not expired) mails
        if ((*itr)->state == MAIL_STATE_DELETED || cur_time < (*itr)->deliver_time)
            continue;

        uint8 item_count = (*itr)->items.size();            // max count is MAX_MAIL_ITEMS (12)

        size_t next_mail_size = 2+4+1+((*itr)->messageType == MAIL_NORMAL ? 8 : 4)+4*8+((*itr)->subject.size()+1)+((*itr)->body.size()+1)+1+item_count*(1+4+4+MAX_INSPECTED_ENCHANTMENT_SLOT*3*4+4+4+4+4+4+4+1);

        if (data.wpos()+next_mail_size > maxPacketSize)
        {
            realCount += 1;
            continue;
        }

        data << uint16(next_mail_size);                    // Message size
        data << uint32((*itr)->messageID);                 // Message ID
        data << uint8((*itr)->messageType);                // Message Type

        switch ((*itr)->messageType)
        {
            case MAIL_NORMAL:                               // sender guid
                data << ObjectGuid(HighGuid::Player, (*itr)->sender);
                break;
            case MAIL_CREATURE:
            case MAIL_GAMEOBJECT:
            case MAIL_AUCTION:
            case MAIL_CALENDAR:
                data << uint32((*itr)->sender);            // creature/gameobject entry, auction id, calendar event id?
                break;
        }

        data << uint32((*itr)->COD);                         // COD
        data << uint32(0);                                   // package (Package.dbc)
        data << uint32((*itr)->stationery);                  // stationery (Stationery.dbc)
        data << uint32((*itr)->money);                       // Gold
        data << uint32((*itr)->checked);                     // flags
        data << float(float((*itr)->expire_time - GameTime::GetGameTime())/DAY); // Time
        data << uint32((*itr)->mailTemplateId);              // mail template (MailTemplate.dbc)
        data << (*itr)->subject;                             // Subject string - once 00, when mail type = 3, max 256
        data << (*itr)->body;                                // message? max 8000
        data << uint8(item_count);                           // client limit is 0x10

        for (uint8 i = 0; i < item_count; ++i)
        {
            Item* item = player->GetMItem((*itr)->items[i].item_guid);
            // item index (0-6?)
            data << uint8(i);
            // item guid low?
            data << uint32((item ? item->GetGUID().GetCounter() : 0));
            // entry
            data << uint32((item ? item->GetEntry() : 0));
            for (uint8 j = 0; j < MAX_INSPECTED_ENCHANTMENT_SLOT; ++j)
            {
                data << uint32((item ? item->GetEnchantmentId((EnchantmentSlot)j) : 0));
                data << uint32((item ? item->GetEnchantmentDuration((EnchantmentSlot)j) : 0));
                data << uint32((item ? item->GetEnchantmentCharges((EnchantmentSlot)j) : 0));
            }
            // can be negative
            data << int32((item ? item->GetItemRandomPropertyId() : 0));
            // unk
            data << uint32((item ? item->GetItemSuffixFactor() : 0));
            // stack count
            data << uint32((item ? item->GetCount() : 0));
            // charges
            data << uint32((item ? item->GetSpellCharges() : 0));
            // durability
            data << uint32((item ? item->GetUInt32Value(ITEM_FIELD_MAXDURABILITY) : 0));
            // durability
            data << uint32((item ? item->GetUInt32Value(ITEM_FIELD_DURABILITY) : 0));
            // unknown wotlk
            data << uint8((item && !item->IsLocked() ? 1 : 0));
        }

        ++realCount;
        ++mailsCount;
    }

    data.put<uint32>(0, realCount);                         // this will display warning about undelivered mail to player if realCount > mailsCount
    data.put<uint8>(4, mailsCount);                        // set real send mails to client
    SendPacket(&data);

    // recalculate m_nextMailDelivereTime and unReadMails
    _player->UpdateNextMailTimeAndUnreads();
}

//used when player copies mail body to his inventory
void WorldSession::HandleMailCreateTextItem(WorldPacket& recvData)
{
    ObjectGuid mailbox;
    uint32 mailId;

    recvData >> mailbox;
    recvData >> mailId;

    if (!CanOpenMailBox(mailbox))
        return;

    Player* player = _player;

    Mail* m = player->GetMail(mailId);
    if (!m || (m->body.empty() && !m->mailTemplateId) || m->state == MAIL_STATE_DELETED || m->deliver_time > GameTime::GetGameTime() || (m->checked & MAIL_CHECK_MASK_COPIED))
    {
        player->SendMailResult(mailId, MAIL_MADE_PERMANENT, MAIL_ERR_INTERNAL_ERROR);
        return;
    }

    Item* bodyItem = new Item;                              // This is not bag and then can be used new Item.
    if (!bodyItem->Create(sObjectMgr->GetGenerator<HighGuid::Item>().Generate(), MAIL_BODY_ITEM_TEMPLATE, player))
    {
        delete bodyItem;
        return;
    }

    // in mail template case we need create new item text
    if (m->mailTemplateId)
    {
        MailTemplateEntry const* mailTemplateEntry = sMailTemplateStore.LookupEntry(m->mailTemplateId);
        ASSERT(mailTemplateEntry);
        bodyItem->SetText(mailTemplateEntry->content[GetSessionDbcLocale()]);
    }
    else
        bodyItem->SetText(m->body);

    if (m->messageType == MAIL_NORMAL)
        bodyItem->SetGuidValue(ITEM_FIELD_CREATOR, ObjectGuid(HighGuid::Player, m->sender));

    bodyItem->SetFlag(ITEM_FIELD_FLAGS, ITEM_FLAG_MAIL_TEXT_MASK);

    TC_LOG_INFO("network", "HandleMailCreateTextItem mailid=%u", mailId);

    ItemPosCountVec dest;
    uint8 msg = _player->CanStoreItem(NULL_BAG, NULL_SLOT, dest, bodyItem, false);
    if (msg == EQUIP_ERR_OK)
    {
        m->checked = m->checked | MAIL_CHECK_MASK_COPIED;
        m->state = MAIL_STATE_CHANGED;
        player->m_mailsUpdated = true;

        player->StoreItem(dest, bodyItem, true);
        player->SendMailResult(mailId, MAIL_MADE_PERMANENT, MAIL_OK);
    }
    else
    {
        player->SendMailResult(mailId, MAIL_MADE_PERMANENT, MAIL_ERR_EQUIP_ERROR, msg);
        delete bodyItem;
    }
}

/// @todo Fix me! ... this void has probably bad condition, but good data are sent
void WorldSession::HandleQueryNextMailTime(WorldPacket & /*recvData*/)
{
    WorldPacket data(MSG_QUERY_NEXT_MAIL_TIME, 8);

    if (!_player->m_mailsLoaded)
        _player->_LoadMail();

    if (_player->unReadMails > 0)
    {
        data << float(0);                                  // float
        data << uint32(0);                                 // count

        uint32 count = 0;
        time_t now = GameTime::GetGameTime();
        std::set<uint32> sentSenders;
        for (PlayerMails::iterator itr = _player->GetMailBegin(); itr != _player->GetMailEnd(); ++itr)
        {
            Mail* m = (*itr);
            // must be not checked yet
            if (m->checked & MAIL_CHECK_MASK_READ)
                continue;

            // and already delivered
            if (now < m->deliver_time)
                continue;

            // only send each mail sender once
            if (sentSenders.count(m->sender))
                continue;

            data << uint64(m->messageType == MAIL_NORMAL ? ObjectGuid(HighGuid::Player, m->sender) : ObjectGuid::Empty);  // player guid
            data << uint32(m->messageType != MAIL_NORMAL ? m->sender : 0);  // non-player entries
            data << uint32(m->messageType);
            data << uint32(m->stationery);
            data << float(m->deliver_time - now);

            sentSenders.insert(m->sender);
            ++count;
            if (count == 2)                                  // do not display more than 2 mails
                break;
        }

        data.put<uint32>(4, count);
    }
    else
    {
        data << float(-DAY);
        data << uint32(0);
    }

    SendPacket(&data);
}
