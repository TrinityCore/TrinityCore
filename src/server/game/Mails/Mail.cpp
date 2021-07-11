/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
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
 * @file Mail.cpp
 * This file contains the the code needed for MaNGOS to handle mails.
 *
 */

#include "Mail.h"
#include "WorldSession.h"
#include "Opcodes.h"
#include "Log.h"
#include "Loot.h"
#include "LootMgr.h"
#include "ObjectAccessor.h"
#include "World.h"
#include "ObjectMgr.h"
#include "ObjectGuid.h"
#include "Player.h"
#include "Item.h"
#include "AuctionHouseMgr.h"
#include "MasterPlayer.h"

/**
 * Creates a new MailSender object.
 *
 * @param sender The object/player sending this mail.
 * @param stationery The stationary associated with this sender.
 */
MailSender::MailSender(Object* sender, MailStationery stationery) : m_stationery(stationery)
{
    switch (sender->GetTypeId())
    {
        case TYPEID_UNIT:
            m_messageType = MAIL_CREATURE;
            m_senderId = sender->GetEntry();
            break;
        case TYPEID_GAMEOBJECT:
            m_messageType = MAIL_GAMEOBJECT;
            m_senderId = sender->GetEntry();
            break;
        case TYPEID_ITEM:
        case TYPEID_CONTAINER:
            m_messageType = MAIL_ITEM;
            m_senderId = sender->GetEntry();
            break;
        case TYPEID_PLAYER:
            m_messageType = MAIL_NORMAL;
            m_senderId = sender->GetGUIDLow();
            break;
        default:
            m_messageType = MAIL_NORMAL;
            m_senderId = UI64LIT(0);                        // will show mail from non-existing player
            TC_LOG_ERROR("misc", "MailSender::MailSender - Mail message contains unexpected sender typeid ({}).", sender->GetTypeId());
            m_senderId = 0;                                 // will show mail from nonexistent player
            sLog.outError("MailSender::MailSender - Mail have unexpected sender typeid (%u)", sender->GetTypeId());
            break;
    }
}
/**
 * Creates a new MailSender object from an AuctionEntry.
 *
 * @param sender the AuctionEntry from which this mail is generated.
 */
MailSender::MailSender(AuctionEntry* sender)
    : m_messageType(MAIL_AUCTION), m_senderId(sender->GetHouseId()), m_stationery(MAIL_STATIONERY_AUCTION)
{
}

/**
 * Creates a new MailReceiver object.
 *
 * @param receiver The player receiving the mail.
 */
MailReceiver::MailReceiver(Player* receiver) : m_receiver(receiver), m_receiver_guid(receiver->GetObjectGuid())
{
}
/**
 * Creates a new MailReceiver object with a specified GUID.
 *
 * @param receiver The player receiving the mail.
 * @param receiver_lowguid The GUID to use instead of the receivers.
 */
MailReceiver::MailReceiver(Player* receiver, ObjectGuid receiver_guid) : m_receiver(receiver), m_receiver_guid(receiver_guid)
{
    MANGOS_ASSERT(!receiver || receiver->GetObjectGuid() == receiver_guid);
}

/**
* Creates a new MailDraft object using mail template id.
*
* @param mailTemplateId The ID of the Template to be used.
* @param a boolean specifying whether the mail needs items or not.
*
*/
MailDraft::MailDraft(uint16 mailTemplateId, bool need_items, LocaleConstant locale_idx) : m_mailTemplateId(mailTemplateId), m_mailTemplateItemsNeed(need_items), m_bodyId(0), m_money(0), m_COD(0)
{
#if SUPPORTED_CLIENT_BUILD <= CLIENT_BUILD_1_9_4
    m_bodyId = sObjectMgr.CreateItemText(sObjectMgr.GetMailTextTemplate(mailTemplateId, locale_idx));
#endif
}

/**
 * Creates a new MailDraft object using subject and contect texts.
 *
 * @param subject The subject of the mail.
 * @param itemText The text of the body of the mail.
 */
MailDraft::MailDraft(std::string subject, std::string text) : m_mailTemplateId(0), m_mailTemplateItemsNeed(false), m_subject(subject),
    m_bodyId(!text.empty() ? sObjectMgr.CreateItemText(text) : 0), m_money(0), m_COD(0)
{

}

MailDraft& MailDraft::SetSubjectAndBody(std::string subject, std::string text)
{
    m_subject = subject;

    MANGOS_ASSERT(!m_bodyId);
    m_bodyId = !text.empty() ? sObjectMgr.CreateItemText(text) : 0;

    return *this;
}

/**
 * Adds an item to the MailDraft.
 *
 * @param item The item to be added to the MailDraft.
 * @returns the MailDraft the item was added to.
 */
MailDraft& MailDraft::AddItem(Item* item)
{
    m_items[item->GetGUIDLow()] = item;
    return *this;
}

void MailDraft::prepareItems(Player* receiver, CharacterDatabaseTransaction trans)
/**
 * Prepares the items in a MailDraft.
 */
bool MailDraft::prepareItems(Player* receiver)
{
    if (!m_mailTemplateId || !m_mailTemplateItemsNeed)
        return false;

    m_mailTemplateItemsNeed = false;

    // The mail sent after turning in the quest The Good News and The Bad News contains 100g
    if (m_mailTemplateId == 123)
        m_money = 1000000;
    Loot mailLoot(nullptr);

    Loot mailLoot(nullptr, ObjectGuid::Empty, LOOT_NONE, nullptr);

    // can be empty
    mailLoot.FillLoot(m_mailTemplateId, LootTemplates_Mail, receiver, true, true);

    for (uint32 i = 0; m_items.size() < MAX_MAIL_ITEMS && i < mailLoot.items.size(); ++i)
    uint32 max_slot = mailLoot.GetMaxSlotInLootFor(receiver->GetGUIDLow());
    for (uint32 i = 0; m_items.empty() && i < max_slot; ++i)
    {
        if (LootItem* lootitem = mailLoot.LootItemInSlot(i, receiver->GetGUIDLow()))
        {
            if (Item* item = Item::CreateItem(lootitem->itemid, lootitem->count, receiver->GetObjectGuid()))
            {
                item->SaveToDB();                           // save for prevent lost at next mail load, if send fail then item will deleted
                AddItem(item);
            }
        }
    }

void MailDraft::deleteIncludedItems(CharacterDatabaseTransaction trans, bool inDB /*= false*/ )
    return true;
}
/**
 * Deletes the items included in a MailDraft.
 *
 * @param inDB A boolean specifying whether the change should be saved to the database or not.
 */
void MailDraft::deleteIncludedItems(bool inDB /**= false*/)
{
    for (const auto& itr : m_items)
    {
        Item* item = itr.second;

        if (inDB)
            CharacterDatabase.PExecute("DELETE FROM `item_instance` WHERE `guid`='%u'", item->GetGUIDLow());

        delete item;
    }

    m_items.clear();
}
/**
 * Clone MailDraft from another MailDraft.
 *
 * @param draft Point to source for draft cloning.
 */
void MailDraft::CloneFrom(MailDraft const& draft)
{
    m_mailTemplateId = draft.GetMailTemplateId();
    m_mailTemplateItemsNeed = draft.m_mailTemplateItemsNeed;

    m_subject = draft.GetSubject();

void MailDraft::SendReturnToSender(uint32 sender_acc, ObjectGuid::LowType sender_guid, ObjectGuid::LowType receiver_guid, CharacterDatabaseTransaction trans)
{
    ObjectGuid receiverGuid = ObjectGuid::Create<HighGuid::Player>(receiver_guid);
    Player* receiver = ObjectAccessor::FindConnectedPlayer(receiverGuid);
    MANGOS_ASSERT(!m_bodyId);
    if (uint32 bodyId = draft.GetBodyId())
    {
        std::string text = sObjectMgr.GetItemText(bodyId);
        m_bodyId = sObjectMgr.CreateItemText(text);
    }

    m_money = draft.GetMoney();
    m_COD = draft.GetCOD();

    for (const auto& itr : draft.m_items)
    {
        Item* item = itr.second;

        if (Item* newitem = item->CloneItem(item->GetCount()))
        {
            newitem->SaveToDB();
            AddItem(newitem);
        }
    }
}

/*
 * Returns a mail to its sender.
 * @param sender_acc           The id of the account of the sender.
 * @param sender_guid          The low part of the GUID of the sender.
 * @param receiver_guid        The low part of the GUID of the reciever.
 */
void MailDraft::SendReturnToSender(uint32 sender_acc, ObjectGuid sender_guid, ObjectGuid receiver_guid)
{
    Player* receiver = sObjectMgr.GetPlayer(receiver_guid);

    uint32 rc_account = 0;
    if (!receiver)
        rc_account = sObjectMgr.GetPlayerAccountIdByGUID(receiver_guid);

    if (!receiver && !rc_account)                           // sender not exist
    {
        deleteIncludedItems(true);
        return;
    }

    // prepare mail and send in other case
    bool needItemDelay = false;

    if (!m_items.empty())
    {
        // if item send to character at another account, then apply item delivery delay
        needItemDelay = sender_acc != rc_account;

        // set owner to new receiver (to prevent delete item with sender char deleting)
        CharacterDatabase.BeginTransaction();
        for (const auto& itr : m_items)
        {
            Item* item = itr.second;
            item->SaveToDB();                      // item not in inventory and can be save standalone
            // owner in data will set at mail receive and item extracting
            CharacterDatabase.PExecute("UPDATE `item_instance` SET `owner_guid` = '%u' WHERE `guid`='%u'", receiver_guid.GetCounter(), item->GetGUIDLow());
        }
        CharacterDatabase.CommitTransaction();
    }

    // If theres is an item, there is a one hour delivery delay.
    uint32 deliver_delay = needItemDelay ? sWorld.getConfig(CONFIG_UINT32_MAIL_DELIVERY_DELAY) : 0;

    // will delete item or place to receiver mail list
    SendMailTo(MailReceiver(receiver, receiver_guid), MailSender(MAIL_NORMAL, sender_guid.GetCounter()), MAIL_CHECK_MASK_RETURNED, deliver_delay);
}

void MailDraft::SendMailTo(CharacterDatabaseTransaction trans, MailReceiver const& receiver, MailSender const& sender, MailCheckMask checked, uint32 deliver_delay)
/**
 * Sends a mail.
 *
 * @param receiver             The MailReceiver to which this mail is sent.
 * @param sender               The MailSender from which this mail is originated.
 * @param checked              The mask used to specify the mail.
 * @param deliver_delay        The delay after which the mail is delivered in seconds
 */
void MailDraft::SendMailTo(MailReceiver const& receiver, MailSender const& sender, MailCheckMask checked, uint32 deliver_delay, uint32 expire_delay)
{
    Player* pReceiver = receiver.GetPlayer();               // can be nullptr
    MasterPlayer* masterReceiver = sObjectAccessor.FindMasterPlayer(receiver.GetPlayerGuid());

    bool has_items = !m_items.empty();

    // generate mail template items for online player, for offline player items will generated at open
    if (pReceiver)
    {
        if (prepareItems(pReceiver))
            has_items = true;
    }

    uint64 mailId = sObjectMgr->GenerateMailID();
    uint32 mailId = sObjectMgr.GenerateMailID();

    time_t deliver_time = time(nullptr) + deliver_delay;

    if (!expire_delay)
    {
        // expire time if COD 3 days, if no COD 30 days, if auction sale pending 1 hour
        // auction mail without any items and money (auction sale note) pending 1 hour
        if (sender.GetMailMessageType() == MAIL_AUCTION && m_items.empty() && !m_money)
            expire_delay = HOUR;
        // default case: expire time if COD 3 days, if no COD 30 days
        else
            expire_delay = (m_COD > 0) ? 3 * DAY : 30 * DAY;
    }

    time_t expire_time = deliver_time + expire_delay;

    // Add to DB
    uint8 index = 0;
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_MAIL);
    stmt->setUInt64(  index, mailId);
    stmt->setUInt8 (++index, uint8(sender.GetMailMessageType()));
    stmt->setInt8  (++index, int8(sender.GetStationery()));
    stmt->setUInt16(++index, GetMailTemplateId());
    stmt->setUInt64(++index, sender.GetSenderId());
    stmt->setUInt64(++index, receiver.GetPlayerGUIDLow());
    stmt->setString(++index, GetSubject());
    stmt->setString(++index, GetBody());
    stmt->setBool  (++index, !m_items.empty());
    stmt->setInt64 (++index, expire_time);
    stmt->setInt64 (++index, deliver_time);
    stmt->setUInt64(++index, m_money);
    stmt->setUInt64(++index, m_COD);
    stmt->setUInt8 (++index, uint8(checked));
    trans->Append(stmt);
    std::string safe_subject = GetSubject();

    CharacterDatabase.BeginTransaction();
    CharacterDatabase.escape_string(safe_subject);
    CharacterDatabase.PExecute("INSERT INTO `mail` (`id`, `message_type`, `stationery`, `mail_template_id`, `sender_guid`, `receiver_guid`, `subject`, `item_text_id`, `has_items`, `expire_time`, `deliver_time`, `money`, `cod`, `checked`) "
                               "VALUES ('%u', '%u', '%u', '%u', '%u', '%u', '%s', '%u', '%u', '" UI64FMTD "','" UI64FMTD "', '%u', '%u', '%u')",
                               mailId, sender.GetMailMessageType(), sender.GetStationery(), GetMailTemplateId(), sender.GetSenderId(), receiver.GetPlayerGuid().GetCounter(), safe_subject.c_str(), GetBodyId(), (has_items ? 1 : 0), (uint64)expire_time, (uint64)deliver_time, m_money, m_COD, checked);

    for (const auto& itr : m_items)
    {
        Item* pItem = mailItemIter->second;
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_MAIL_ITEM);
        stmt->setUInt64(0, mailId);
        stmt->setUInt64(1, pItem->GetGUID().GetCounter());
        stmt->setUInt64(2, receiver.GetPlayerGUIDLow());
        trans->Append(stmt);
        Item* item = itr.second;
        CharacterDatabase.PExecute("INSERT INTO `mail_items` (`mail_id`, `item_guid`, `item_id`, `receiver_guid`) VALUES ('%u', '%u', '%u','%u')",
                                   mailId, item->GetGUIDLow(), item->GetEntry(), receiver.GetPlayerGuid().GetCounter());
    }
    CharacterDatabase.CommitTransaction();

    // For online receiver update in game mail status and data
    if (masterReceiver)
    {
        masterReceiver->AddNewMailDeliverTime(deliver_time);

        Mail* m = new Mail;
        m->messageID = mailId;
        m->mailTemplateId = GetMailTemplateId();
        m->subject = GetSubject();
        m->body = GetBody();
        m->money = GetMoney();
        m->COD = GetCOD();
        Mail *m = new Mail;
        m->messageID = mailId;
        m->mailTemplateId = GetMailTemplateId();
        m->subject = GetSubject();
        m->itemTextId = GetBodyId();
        m->money = GetMoney();
        m->COD = GetCOD();

        for (MailItemMap::const_iterator mailItemIter = m_items.begin(); mailItemIter != m_items.end(); ++mailItemIter)
        {
            Item* item = mailItemIter->second;
            m->AddItem(item->GetGUID().GetCounter(), item->GetEntry());
        }
        for (const auto& itr : m_items)
        {
            Item* item = itr.second;
            m->AddItem(item->GetGUIDLow(), item->GetEntry());
        }

        m->messageType = sender.GetMailMessageType();
        m->stationery = sender.GetStationery();
        m->sender = sender.GetSenderId();
        m->receiver = receiver.GetPlayerGUIDLow();
        m->expire_time = expire_time;
        m->deliver_time = deliver_time;
        m->checked = checked;
        m->state = MAIL_STATE_UNCHANGED;
        m->messageType = sender.GetMailMessageType();
        m->stationery = sender.GetStationery();
        m->sender = sender.GetSenderId();
        m->receiverGuid = receiver.GetPlayerGuid();
        m->expire_time = expire_time;
        m->deliver_time = deliver_time;
        m->checked = checked;
        m->state = MAIL_STATE_UNCHANGED;

        pReceiver->AddMail(m);                           // to insert new mail to beginning of maillist
        masterReceiver->AddMail(m);                           // to insert new mail to beginning of maillist

        if (!m_items.empty())
        {
            for (MailItemMap::iterator mailItemIter = m_items.begin(); mailItemIter != m_items.end(); ++mailItemIter)
                pReceiver->AddMItem(mailItemIter->second);
        }
    }
    else if (!m_items.empty())
    {
        CharacterDatabaseTransaction temp = CharacterDatabaseTransaction(nullptr);
        deleteIncludedItems(temp);
    }
}
        if (!m_items.empty())
        {
            for (const auto& itr : m_items)
                masterReceiver->AddMItem(itr.second);
        }
    }
    else if (!m_items.empty())
        deleteIncludedItems();
}

/**
 * Generate items from template at mails loading (this happens when mail with mail template items send in time when receiver has been offline)
 *
 * @param receiver             reciver of mail
 */

void Mail::prepareTemplateItems(Player* receiver)
{
    MasterPlayer* masterReceiver = receiver->GetSession()->GetMasterPlayer();
    if (!mailTemplateId || !items.empty() || !masterReceiver)
        return;

    has_items = true;

    Loot mailLoot(nullptr);

    // can be empty
    mailLoot.FillLoot(mailTemplateId, LootTemplates_Mail, receiver, true, true);

    CharacterDatabase.BeginTransaction();
    CharacterDatabase.PExecute("UPDATE `mail` SET `has_items` = 1 WHERE `id` = %u", messageID);

    uint32 max_slot = mailLoot.GetMaxSlotInLootFor(receiver->GetGUIDLow());
    for (uint32 i = 0; items.empty() && i < max_slot; ++i)
    {
        if (LootItem* lootitem = mailLoot.LootItemInSlot(i, receiver->GetGUIDLow()))
        {
            if (Item* item = Item::CreateItem(lootitem->itemid, lootitem->count, receiver->GetObjectGuid()))
            {
                item->SaveToDB();

                AddItem(item->GetGUIDLow(), item->GetEntry());

                masterReceiver->AddMItem(item);

                CharacterDatabase.PExecute("INSERT INTO `mail_items` (`mail_id`, `item_guid`, `item_id`, `receiver_guid`) VALUES ('%u', '%u', '%u','%u')",
                                           messageID, item->GetGUIDLow(), item->GetEntry(), masterReceiver->GetGUIDLow());
            }
        }
    }

    CharacterDatabase.CommitTransaction();
}

/*! @} */
