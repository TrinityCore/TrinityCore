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

#include "Mail.h"
#include "AuctionHouseMgr.h"
#include "BlackMarketMgr.h"
#include "CalendarMgr.h"
#include "CharacterCache.h"
#include "DatabaseEnv.h"
#include "Item.h"
#include "Log.h"
#include "LootMgr.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "World.h"

MailSender::MailSender(Object* sender, MailStationery stationery) : m_stationery(stationery)
{
    switch (sender->GetTypeId())
    {
        case TYPEID_UNIT:
            m_messageType = MAIL_CREATURE;
            m_senderId = uint64(sender->GetEntry());
            break;
        case TYPEID_GAMEOBJECT:
            m_messageType = MAIL_GAMEOBJECT;
            m_senderId = uint64(sender->GetEntry());
            break;
        /*case TYPEID_ITEM:
            m_messageType = MAIL_ITEM;
            m_senderId = sender->GetEntry();
            break;*/
        case TYPEID_PLAYER:
            m_messageType = MAIL_NORMAL;
            m_senderId = sender->GetGUID().GetCounter();
            break;
        default:
            m_messageType = MAIL_NORMAL;
            m_senderId = UI64LIT(0);                        // will show mail from non-existing player
            TC_LOG_ERROR("misc", "MailSender::MailSender - Mail message contains unexpected sender typeid (%u).", sender->GetTypeId());
            break;
    }
}

MailSender::MailSender(CalendarEvent* sender)
    : m_messageType(MAIL_CALENDAR), m_senderId(sender->GetEventId()), m_stationery(MAIL_STATIONERY_DEFAULT) // what stationery we should use here?
{
}

MailSender::MailSender(AuctionHouseObject const* sender)
    : m_messageType(MAIL_AUCTION), m_senderId(uint64(sender->GetAuctionHouseId())), m_stationery(MAIL_STATIONERY_AUCTION) { }

MailSender::MailSender(BlackMarketEntry* sender)
    : m_messageType(MAIL_BLACKMARKET), m_senderId(sender->GetTemplate()->SellerNPC), m_stationery(MAIL_STATIONERY_AUCTION) { }

MailSender::MailSender(Player* sender)
{
    m_messageType = MAIL_NORMAL;
    m_stationery = sender->IsGameMaster() ? MAIL_STATIONERY_GM : MAIL_STATIONERY_DEFAULT;
    m_senderId = sender->GetGUID().GetCounter();
}

MailSender::MailSender(uint32 senderEntry)
{
    m_messageType = MAIL_CREATURE;
    m_senderId = senderEntry;
    m_stationery = MAIL_STATIONERY_DEFAULT;
}

MailReceiver::MailReceiver(Player* receiver) : m_receiver(receiver), m_receiver_lowguid(receiver->GetGUID().GetCounter()) { }

MailReceiver::MailReceiver(Player* receiver, ObjectGuid::LowType receiver_lowguid) : m_receiver(receiver), m_receiver_lowguid(receiver_lowguid)
{
    ASSERT(!receiver || receiver->GetGUID().GetCounter() == receiver_lowguid);
}

MailReceiver::MailReceiver(Player* receiver, ObjectGuid receiverGuid) : m_receiver(receiver), m_receiver_lowguid(receiverGuid.GetCounter())
{
    ASSERT(!receiver || receiver->GetGUID() == receiverGuid);
}

MailDraft& MailDraft::AddItem(Item* item)
{
    m_items[item->GetGUID().GetCounter()] = item;
    return *this;
}

void MailDraft::prepareItems(Player* receiver, CharacterDatabaseTransaction& trans)
{
    if (!m_mailTemplateId || !m_mailTemplateItemsNeed)
        return;

    m_mailTemplateItemsNeed = false;

    Loot mailLoot;

    // can be empty
    mailLoot.FillLoot(m_mailTemplateId, LootTemplates_Mail, receiver, true, true, LOOT_MODE_DEFAULT, ItemContext::NONE);

    uint32 max_slot = mailLoot.GetMaxSlotInLootFor(receiver);
    for (uint32 i = 0; m_items.size() < MAX_MAIL_ITEMS && i < max_slot; ++i)
    {
        if (LootItem* lootitem = mailLoot.LootItemInSlot(i, receiver))
        {
            if (Item* item = Item::CreateItem(lootitem->itemid, lootitem->count, lootitem->context, receiver))
            {
                item->SaveToDB(trans);                           // save for prevent lost at next mail load, if send fail then item will deleted
                AddItem(item);
            }
        }
    }
}

void MailDraft::deleteIncludedItems(CharacterDatabaseTransaction& trans, bool inDB /*= false*/ )
{
    for (MailItemMap::iterator mailItemIter = m_items.begin(); mailItemIter != m_items.end(); ++mailItemIter)
    {
        Item* item = mailItemIter->second;

        if (inDB)
            item->DeleteFromDB(trans);

        delete item;
    }

    m_items.clear();
}

void MailDraft::SendReturnToSender(uint32 sender_acc, ObjectGuid::LowType sender_guid, ObjectGuid::LowType receiver_guid, CharacterDatabaseTransaction& trans)
{
    ObjectGuid receiverGuid = ObjectGuid::Create<HighGuid::Player>(receiver_guid);
    Player* receiver = ObjectAccessor::FindConnectedPlayer(receiverGuid);

    uint32 rc_account = 0;
    if (!receiver)
        rc_account = sCharacterCache->GetCharacterAccountIdByGuid(receiverGuid);

    if (!receiver && !rc_account)                            // sender not exist
    {
        deleteIncludedItems(trans, true);
        return;
    }

    // prepare mail and send in other case
    bool needItemDelay = false;

    if (!m_items.empty())
    {
        // if item send to character at another account, then apply item delivery delay
        needItemDelay = sender_acc != rc_account;

        // set owner to new receiver (to prevent delete item with sender char deleting)
        for (MailItemMap::iterator mailItemIter = m_items.begin(); mailItemIter != m_items.end(); ++mailItemIter)
        {
            Item* item = mailItemIter->second;
            item->SaveToDB(trans);                      // item not in inventory and can be save standalone
            // owner in data will set at mail receive and item extracting
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ITEM_OWNER);
            stmt->setUInt64(0, receiver_guid);
            stmt->setUInt64(1, item->GetGUID().GetCounter());
            trans->Append(stmt);
        }
    }

    // If theres is an item, there is a one hour delivery delay.
    uint32 deliver_delay = needItemDelay ? sWorld->getIntConfig(CONFIG_MAIL_DELIVERY_DELAY) : 0;

    // will delete item or place to receiver mail list
    SendMailTo(trans, MailReceiver(receiver, receiver_guid), MailSender(MAIL_NORMAL, sender_guid), MAIL_CHECK_MASK_RETURNED, deliver_delay);
}

void MailDraft::SendMailTo(CharacterDatabaseTransaction& trans, MailReceiver const& receiver, MailSender const& sender, MailCheckMask checked, uint32 deliver_delay)
{
    Player* pReceiver = receiver.GetPlayer();               // can be NULL
    Player* pSender = sender.GetMailMessageType() == MAIL_NORMAL ? ObjectAccessor::FindPlayer(ObjectGuid::Create<HighGuid::Player>(sender.GetSenderId())) : nullptr;

    if (pReceiver)
        prepareItems(pReceiver, trans);                            // generate mail template items

    uint32 mailId = sObjectMgr->GenerateMailID();

    time_t deliver_time = time(NULL) + deliver_delay;

    //expire time if COD 3 days, if no COD 30 days, if auction sale pending 1 hour
    uint32 expire_delay;

    // auction mail without any items and money
    if (sender.GetMailMessageType() == MAIL_AUCTION && m_items.empty() && !m_money)
        expire_delay = sWorld->getIntConfig(CONFIG_MAIL_DELIVERY_DELAY);
     // default case: expire time if COD 3 days, if no COD 30 days (or 90 days if sender is a game master)
    else
    {
        if (m_COD)
            expire_delay = 3 * DAY;
        else
            expire_delay = pSender && pSender->IsGameMaster() ? 90 * DAY : 30 * DAY;
    }

    time_t expire_time = deliver_time + expire_delay;

    // Add to DB
    uint8 index = 0;
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_MAIL);
    stmt->setUInt32(  index, mailId);
    stmt->setUInt8 (++index, uint8(sender.GetMailMessageType()));
    stmt->setInt8  (++index, int8(sender.GetStationery()));
    stmt->setUInt16(++index, GetMailTemplateId());
    stmt->setUInt64(++index, sender.GetSenderId());
    stmt->setUInt64(++index, receiver.GetPlayerGUIDLow());
    stmt->setString(++index, GetSubject());
    stmt->setString(++index, GetBody());
    stmt->setBool  (++index, !m_items.empty());
    stmt->setUInt64(++index, uint64(expire_time));
    stmt->setUInt64(++index, uint64(deliver_time));
    stmt->setUInt64(++index, m_money);
    stmt->setUInt64(++index, m_COD);
    stmt->setUInt8 (++index, uint8(checked));
    trans->Append(stmt);

    for (MailItemMap::const_iterator mailItemIter = m_items.begin(); mailItemIter != m_items.end(); ++mailItemIter)
    {
        Item* pItem = mailItemIter->second;
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_MAIL_ITEM);
        stmt->setUInt32(0, mailId);
        stmt->setUInt64(1, pItem->GetGUID().GetCounter());
        stmt->setUInt64(2, receiver.GetPlayerGUIDLow());
        trans->Append(stmt);
    }

    // For online receiver update in game mail status and data
    if (pReceiver)
    {
        pReceiver->AddNewMailDeliverTime(deliver_time);

        if (pReceiver->IsMailsLoaded())
        {
            Mail* m = new Mail;
            m->messageID = mailId;
            m->mailTemplateId = GetMailTemplateId();
            m->subject = GetSubject();
            m->body = GetBody();
            m->money = GetMoney();
            m->COD = GetCOD();

            for (MailItemMap::const_iterator mailItemIter = m_items.begin(); mailItemIter != m_items.end(); ++mailItemIter)
            {
                Item* item = mailItemIter->second;
                m->AddItem(item->GetGUID().GetCounter(), item->GetEntry());
            }

            m->messageType = sender.GetMailMessageType();
            m->stationery = sender.GetStationery();
            m->sender = sender.GetSenderId();
            m->receiver = receiver.GetPlayerGUIDLow();
            m->expire_time = expire_time;
            m->deliver_time = deliver_time;
            m->checked = checked;
            m->state = MAIL_STATE_UNCHANGED;

            pReceiver->AddMail(m);                           // to insert new mail to beginning of maillist

            if (!m_items.empty())
            {
                for (MailItemMap::iterator mailItemIter = m_items.begin(); mailItemIter != m_items.end(); ++mailItemIter)
                    pReceiver->AddMItem(mailItemIter->second);
            }
        }
        else if (!m_items.empty())
        {
            CharacterDatabaseTransaction temp = CharacterDatabaseTransaction(NULL);
            deleteIncludedItems(temp);
        }
    }
    else if (!m_items.empty())
    {
        CharacterDatabaseTransaction temp = CharacterDatabaseTransaction(NULL);
        deleteIncludedItems(temp);
    }
}
