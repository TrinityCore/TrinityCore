/*
 * Copyright (C) 2019+ ATieshCore <https://at-wow.org/>
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

#include "AccountMgr.h"
#include "AuctionHouseMgr.h"
#include "Bag.h"
#include "BattlegroundMgr.h"
#include "CalendarMgr.h"
#include "CharacterCache.h"
#include "DatabaseEnv.h"
#include "DBCStoresMgr.h"
#include "GameTime.h"
#include "Guild.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "RBAC.h"
#include "Mail.h"
#include "MailMgr.h"
#include "Item.h"
#include "Language.h"
#include "Log.h"
#include "LootMgr.h"
#include "World.h"
#include "WorldSession.h"
#include "WorldPacket.h"

constexpr uint32 MAX_NETCLIENT_PACKET_SIZE = 32767 - 1; // Client hardcap: int16 with trailing zero space otherwise crash on memory free

MailMgr* MailMgr::instance()
{
    static MailMgr instance;
    return &instance;
}

MailMgr::MailMgr() : _ExpTimer(MONTH)
{
    m_updateTimer = 0;
}

MailMgr::~MailMgr()
{
    m_mails.clear();
    m_mailitems.clear();

    for (ItemMap::iterator iter = mMitems.begin(); iter != mMitems.end(); ++iter)
        iter->second->RemoveFromWorld();
    mMitems.clear();
}

void MailMgr::Initialize()
{
    _LoadMails();
    _LoadMailItems();
    _LoadMailedItemPointers();

    // delete old
    _DeleteExpiryMails(true);
}

void MailMgr::Update(uint32 diff)
{
    m_updateTimer += diff;
    if (m_updateTimer >= MAIL_UPDATE_INTERVAL) // upd only each 1 sec
    {
        _ExpTimer.Update(m_updateTimer/1000);
        if (_ExpTimer.Passed())
            _DeleteExpiryMails();

        m_updateTimer = 0;
    }
}

void MailMgr::SendMailBy(Object* sender, ObjectGuid::LowType receiver, std::string const& subject, std::string const& body, uint32 money, MailCheckMask mask, uint32 deliver_delay, uint32 COD)
{
    if (!sender || !receiver)
        return;

    uint8 m_messageType;
    uint8 m_stationery;
    ObjectGuid::LowType m_senderId;
    time_t expire_time, deliver_time;

    if (!PrepareMessageAttributeBy(sender, receiver, m_messageType, m_stationery, m_senderId, deliver_delay, COD, expire_time, deliver_time))
        return;

    uint32 mail_id = AddNewMail(m_messageType, m_stationery, 0, m_senderId, receiver, subject, body, false, money, expire_time, deliver_time, COD, mask);

    if (mail_id)
    {
        // For online receiver update in game mail status and data
        if (Player* pReceiver = ObjectAccessor::FindPlayerByLowGUID(receiver))
            pReceiver->AddNewMailDeliverTime(deliver_time);
    }
}

void MailMgr::SendMailByGUID(ObjectGuid::LowType sender, ObjectGuid::LowType receiver, uint8 m_messageType, std::string const& subject, std::string const& body, uint32 money, MailCheckMask mask, uint32 deliver_delay, uint32 COD)
{
    if (!receiver)
        return;

    uint8 m_stationery;
    time_t expire_time, deliver_time;

    if (!PrepareMessageAttributeByGUID(sender, m_messageType, m_stationery, deliver_delay, COD, expire_time, deliver_time))
        return;

    uint32 mail_id = AddNewMail(m_messageType, m_stationery, 0, sender, receiver, subject, body, false, money, expire_time, deliver_time, COD, mask);

    if (mail_id)
    {
        // For online receiver update in game mail status and data
        if (Player* pReceiver = ObjectAccessor::FindPlayerByLowGUID(receiver))
            pReceiver->AddNewMailDeliverTime(deliver_time);
    }
}

void MailMgr::SendMailWithItemsBy(Object* sender, ObjectGuid::LowType receiver, std::string const& subject, std::string const& body, uint32 money, std::vector<Item*> const& itemlist, MailCheckMask mask, uint32 deliver_delay, uint32 COD)
{
    if (!sender || !receiver)
        return;

    uint8 m_messageType;
    uint8 m_stationery;
    ObjectGuid::LowType m_senderId;
    time_t expire_time, deliver_time;

    if (!PrepareMessageAttributeBy(sender, receiver, m_messageType, m_stationery, m_senderId, deliver_delay, COD, expire_time, deliver_time))
        return;

    uint32 mail_id = AddNewMail(m_messageType, m_stationery, 0, m_senderId, receiver, subject, body, true, money, expire_time, deliver_time, COD, mask);

    if (mail_id)
    {
        if (!itemlist.empty()) // it's unreal, but possible to sent message with empty list
        {
            CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
            for (auto const& pointer : itemlist)
                AddNewMailItem(mail_id, pointer, pointer->GetGUID(), receiver, trans);
            CharacterDatabase.CommitTransaction(trans);
        }

        // For online receiver update in game mail status and data
        if (Player* pReceiver = ObjectAccessor::FindPlayerByLowGUID(receiver))
            pReceiver->AddNewMailDeliverTime(deliver_time);
    }
}

void MailMgr::SendMailWithItemsByGUID(ObjectGuid::LowType sender, ObjectGuid::LowType receiver, uint8 m_messageType, std::string const& subject, std::string const& body, uint32 money, std::vector<Item*> const& itemlist, MailCheckMask mask, uint32 deliver_delay, uint32 COD)
{
    if (!receiver)
        return;

    uint8 m_stationery;
    time_t expire_time, deliver_time;

    if (!PrepareMessageAttributeByGUID(sender, m_messageType, m_stationery, deliver_delay, 0, expire_time, deliver_time))
        return;

    uint32 mail_id = AddNewMail(m_messageType, m_stationery, 0, sender, receiver, subject, body, true, money, expire_time, deliver_time, COD, mask);

    if (mail_id)
    {
        if (!itemlist.empty()) // it's unreal, but possible to sent message with empty list
        {
            CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
            for (auto const& pointer : itemlist)
                AddNewMailItem(mail_id, pointer, pointer->GetGUID(), receiver, trans);
            CharacterDatabase.CommitTransaction(trans);
        }

        // For online receiver update in game mail status and data
        if (Player* pReceiver = ObjectAccessor::FindPlayerByLowGUID(receiver))
            pReceiver->AddNewMailDeliverTime(deliver_time);
    }
}

void MailMgr::SendMailByAuctionHouse(AuctionEntry* sender, ObjectGuid::LowType receiver, std::string const& subject, std::string const& body, uint32 money, MailCheckMask mask, uint32 deliver_delay, uint32 COD)
{
    if (!sender || !receiver)
        return;

    uint8 m_messageType = MAIL_AUCTION;
    uint8 m_stationery = MAIL_STATIONERY_AUCTION;
    ObjectGuid::LowType m_senderId = sender->GetHouseId();
    time_t expire_time, deliver_time;

    if (!PrepareMessageAttributeForAuctionAndCalendar(deliver_delay, COD, expire_time, deliver_time))
        return;

    uint32 mail_id = AddNewMail(m_messageType, m_stationery, 0, m_senderId, receiver, subject, body, false, money, expire_time, deliver_time, COD, mask);

    if (!mail_id)
        return;

    if (mail_id)
    {
        // For online receiver update in game mail status and data
        if (Player* pReceiver = ObjectAccessor::FindPlayerByLowGUID(receiver))
            pReceiver->AddNewMailDeliverTime(deliver_time);
    }
}

void MailMgr::SendMailByAuctionHouseWithItems(AuctionEntry* sender, ObjectGuid::LowType receiver, std::string const& subject, std::string const& body, uint32 money, std::vector<Item*> const& itemlist, MailCheckMask mask, uint32 deliver_delay, uint32 COD)
{
    if (!sender || !receiver)
        return;

    uint8 m_messageType = MAIL_AUCTION;
    uint8 m_stationery = MAIL_STATIONERY_AUCTION;
    ObjectGuid::LowType m_senderId = sender->GetHouseId();
    time_t expire_time, deliver_time;

    if (!PrepareMessageAttributeForAuctionAndCalendar(deliver_delay, COD, expire_time, deliver_time))
        return;

    uint32 mail_id = AddNewMail(m_messageType, m_stationery, 0, m_senderId, receiver, subject, body, true, money, expire_time, deliver_time, COD, mask);

    if (!mail_id)
        return;

    if (mail_id)
    {
        if (!itemlist.empty()) // it's unreal, but possible to sent message with empty list
        {
            CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
            for (auto const& pointer : itemlist)
                AddNewMailItem(mail_id, pointer, pointer->GetGUID(), receiver, trans);
            CharacterDatabase.CommitTransaction(trans);
        }
        // For online receiver update in game mail status and data
        if (Player* pReceiver = ObjectAccessor::FindPlayerByLowGUID(receiver))
            pReceiver->AddNewMailDeliverTime(deliver_time);
    }
}

void MailMgr::SendMailByCalendarEvent(CalendarEvent* sender, ObjectGuid::LowType receiver, std::string const& subject, std::string const& body, uint32 money, MailCheckMask mask, uint32 deliver_delay, uint32 COD)
{
    if (!sender || !receiver)
        return;

    uint8 m_messageType = MAIL_CALENDAR;
    uint8 m_stationery = MAIL_STATIONERY_DEFAULT;
    ObjectGuid::LowType m_senderId = sender->GetEventId();
    time_t expire_time, deliver_time;

    if (!PrepareMessageAttributeForAuctionAndCalendar(deliver_delay, COD, expire_time, deliver_time))
        return;

    uint32 mail_id = AddNewMail(m_messageType, m_stationery, 0, m_senderId, receiver, subject, body, false, money, expire_time, deliver_time, COD, mask);

    if (!mail_id)
        return;

    if (mail_id)
    {
        // For online receiver update in game mail status and data
        if (Player* pReceiver = ObjectAccessor::FindPlayerByLowGUID(receiver))
            pReceiver->AddNewMailDeliverTime(deliver_time);
    }
}

void MailMgr::SendMailByCalendarEventWithItems(CalendarEvent* sender, ObjectGuid::LowType receiver, std::string const& subject, std::string const& body, uint32 money, std::vector<Item*> const& itemlist, MailCheckMask mask, uint32 deliver_delay, uint32 COD)
{
    if (!sender || !receiver)
        return;

    uint8 m_messageType = MAIL_CALENDAR;
    uint8 m_stationery = MAIL_STATIONERY_DEFAULT;
    ObjectGuid::LowType m_senderId = sender->GetEventId();
    time_t expire_time, deliver_time;

    if (!PrepareMessageAttributeForAuctionAndCalendar(deliver_delay, COD, expire_time, deliver_time))
        return;

    uint32 mail_id = AddNewMail(m_messageType, m_stationery, 0, m_senderId, receiver, subject, body, true, money, expire_time, deliver_time, COD, mask);

    if (!mail_id)
        return;

    if (mail_id)
    {
        if (!itemlist.empty()) // it's unreal, but possible to sent message with empty list
        {
            CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
            for (auto const& pointer : itemlist)
                AddNewMailItem(mail_id, pointer, pointer->GetGUID(), receiver, trans);
            CharacterDatabase.CommitTransaction(trans);
        }
        // For online receiver update in game mail status and data
        if (Player* pReceiver = ObjectAccessor::FindPlayerByLowGUID(receiver))
            pReceiver->AddNewMailDeliverTime(deliver_time);
    }
}

void MailMgr::SendMailWithTemplateBy(Object* sender, ObjectGuid::LowType receiver, uint16 mailTemplateId, MailCheckMask mask, uint32 deliver_delay)
{
    if (!sender || !receiver)
        return;

    if (!mailTemplateId)
        return;

    uint8 m_messageType;
    uint8 m_stationery;
    uint32 m_money = 0;
    ObjectGuid::LowType m_senderId;
    time_t expire_time, deliver_time;

    if (!PrepareMessageAttributeBy(sender, receiver, m_messageType, m_stationery, m_senderId, deliver_delay, 0, expire_time, deliver_time))
        return;

    // The mail sent after turning in the quest The Good News and The Bad News contains 100g
    if (mailTemplateId == 123)
        m_money = 1000000;

    uint32 mail_id = AddNewMail(m_messageType, m_stationery, mailTemplateId, m_senderId, receiver, "", "", false, m_money, expire_time, deliver_time, 0, mask);

    if (!mail_id)
        return;

    if (Player* pReceiver = ObjectAccessor::FindPlayerByLowGUID(receiver))
        prepareItems(mail_id, mailTemplateId, pReceiver);
}

void MailMgr::SendMailWithTemplateByGUID(ObjectGuid::LowType sender, ObjectGuid::LowType receiver, uint8 messageType, uint16 mailTemplateId, MailCheckMask mask, uint32 deliver_delay)
{
    if (!sender || !receiver)
        return;

    if (!mailTemplateId)
        return;

    uint8 m_stationery;
    uint32 m_money = 0;
    time_t expire_time, deliver_time;

    if (!PrepareMessageAttributeByGUID(sender, messageType, m_stationery, deliver_delay, 0, expire_time, deliver_time))
        return;

    // The mail sent after turning in the quest The Good News and The Bad News contains 100g
    if (mailTemplateId == 123)
        m_money = 1000000;

    uint32 mail_id = AddNewMail(messageType, m_stationery, mailTemplateId, sender, receiver, "", "", false, m_money, expire_time, deliver_time, 0, mask);

    if (!mail_id)
        return;

    if (Player* pReceiver = ObjectAccessor::FindPlayerByLowGUID(receiver))
        prepareItems(mail_id, mailTemplateId, pReceiver);
}

void MailMgr::prepareItems(uint32 mailId, uint16 mailTemplateId, Player* receiver)
{
    if (!receiver)
        return;

    Loot mailLoot;
    // can be empty
    mailLoot.FillLoot(mailTemplateId, LootTemplates_Mail, receiver, true, true);

    uint32 max_slot = mailLoot.GetMaxSlotInLootFor(receiver);
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    for (uint32 i = 0; /*m_items.size() < MAX_MAIL_ITEMS &&*/ i < max_slot; ++i)
    {
        if (LootItem* lootitem = mailLoot.LootItemInSlot(i, receiver))
        {
            if (Item* item = Item::CreateItem(lootitem->itemid, lootitem->count, receiver))
            {
                item->SaveToDB(trans);                           // save for prevent lost at next mail load, if send fail then item will deleted
                AddNewMailItem(mailId, item, item->GetGUID(), receiver->GetGUID().GetCounter(), trans);
            }
        }
    }
    CharacterDatabase.CommitTransaction(trans);
}

uint32 MailMgr::SendReturnMailByGUID(uint32 old_mailID, ObjectGuid::LowType sender, ObjectGuid::LowType receiver, std::string const& subject, std::string const& body, uint32 money, bool itemexist, uint32 deliver_delay)
{
    if (!old_mailID || !receiver)
        return 0;

    uint8 m_messageType = MAIL_NORMAL;
    uint8 m_stationery = MAIL_STATIONERY_DEFAULT;
    MailCheckMask mask = MAIL_CHECK_MASK_RETURNED;
    time_t expire_time, deliver_time;

    if (!PrepareMessageAttributeByGUID(sender, m_messageType, m_stationery, deliver_delay, 0, expire_time, deliver_time))
        return 0;

    uint32 mail_id = AddNewMail(m_messageType, m_stationery, 0, sender, receiver, subject, body, itemexist, money, expire_time, deliver_time, 0, mask);

    if (!mail_id)
        return 0;

    if (itemexist)
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_MAIL_ITEM_OLDMAILID_BY_MAILID);
        stmt->setUInt32(0, mail_id);
        stmt->setUInt32(1, old_mailID);
        CharacterDatabase.Execute(stmt);
    }

    // For online receiver update in game mail status and data
    if (Player* pReceiver = ObjectAccessor::FindPlayerByLowGUID(receiver))
        pReceiver->AddNewMailDeliverTime(deliver_time);

    return mail_id;
}

void MailMgr::clearDependInstanceItem(ObjectGuid::LowType playerId, uint32 mailID, CharacterDatabaseTransaction& trans)
{
    ObjectGuid receiverGuid(HighGuid::Player, playerId);
    // Data needs to be at first place for Item::LoadFromDB
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_MAILITEM);
    stmt->setUInt32(0, mailID);
    PreparedQueryResult resultItems = CharacterDatabase.Query(stmt);
    if (resultItems)
    {
        do
        {
            Field* itemFields = resultItems->Fetch();
            ObjectGuid::LowType item_guidlow = itemFields[11].GetUInt32();
            uint32 item_template = itemFields[12].GetUInt32();

            ItemTemplate const* itemProto = sObjectMgr->GetItemTemplate(item_template);
            if (!itemProto)
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE);
                stmt->setUInt32(0, item_guidlow);
                trans->Append(stmt);
                continue;
            }

            Item* pItem = NewItemOrBag(itemProto);
            if (!pItem->LoadFromDB(item_guidlow, receiverGuid, itemFields, item_template))
            {
                pItem->FSetState(ITEM_REMOVED);
                pItem->SaveToDB(trans);              // it also deletes item object!
                continue;
            }

        } while (resultItems->NextRow());
    }
}

void MailMgr::clearDependInstanceItemsBeforeDeletePlayer(ObjectGuid::LowType playerId)
{
    ObjectGuid receiverGuid(HighGuid::Player, playerId);
    // Data from ITEM_INSTANCE should be cleared also
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_MAILITEMS_FOR_DELETE);
    stmt->setUInt32(0, playerId);

    PreparedQueryResult resultItems = CharacterDatabase.Query(stmt);
    if (resultItems)
    {
        CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
        do
        {
            Field* itemFields = resultItems->Fetch();
            ObjectGuid::LowType item_guidlow = itemFields[11].GetUInt32();
            uint32 item_template = itemFields[12].GetUInt32();

            ItemTemplate const* itemProto = sObjectMgr->GetItemTemplate(item_template);
            if (!itemProto)
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE);
                stmt->setUInt32(0, item_guidlow);
                trans->Append(stmt);
                continue;
            }

            Item* pItem = NewItemOrBag(itemProto);
            if (!pItem->LoadFromDB(item_guidlow, receiverGuid, itemFields, item_template))
            {
                pItem->FSetState(ITEM_REMOVED);
                pItem->SaveToDB(trans);              // it also deletes item object!
                continue;
            }

        } while (resultItems->NextRow());

        CharacterDatabase.CommitTransaction(trans);
    }
}

bool MailMgr::PrepareMessageAttributeBy(Object* sender, ObjectGuid::LowType receiver, uint8& m_messageType, uint8& m_stationery, ObjectGuid::LowType& m_senderId, uint32 deliver_delay, uint32 COD, time_t& expire_time, time_t& deliver_time)
{
    m_stationery = MAIL_STATIONERY_DEFAULT;

    bool typeIsOk = true;
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
            /*case TYPEID_ITEM:
                m_messageType = MAIL_ITEM;
                m_senderId = sender->GetEntry();
                break;*/
        case TYPEID_PLAYER:
            m_messageType = MAIL_NORMAL;
            m_senderId = sender->GetGUID().GetCounter();
            if (sender->ToPlayer()->IsGameMaster())
                m_stationery = MAIL_STATIONERY_GM;
            break;
        default:
            m_messageType = MAIL_NORMAL;
            m_senderId = 0;                                 // will show mail from non-existing player
            TC_LOG_ERROR("misc", "MailMgr::SendMailTo - Mail message contains unexpected sender typeid ({}).", sender->GetTypeId());
            typeIsOk = false;
            break;
    }

    if (!typeIsOk)
        return false;

    Player* pSender = sender->ToPlayer();
    Player* pReceiver = ObjectAccessor::FindPlayerByLowGUID(receiver);

    if (pReceiver)
    {
        // GuildLevel system
        /*
        if (pSender)
        {
            if (pSender->GetGuild() && pReceiver->GetGuild())
            {
                if (pSender->GetGuildId() == pReceiver->GetGuildId())
                {
                    if (pSender->GetGuild()->GetGuildLevel() >= 4)
                        deliver_delay = 0;
                }
            }
        }*/
    }

    deliver_time = GameTime::GetGameTime() + deliver_delay;

    //expire time if COD 3 days, if no COD 30 days, if auction sale pending 1 hour
    uint32 expire_delay;
    // mail from battlemaster (rewardmarks) should last only one day
    if (m_messageType == MAIL_CREATURE && sBattlegroundMgr->GetBattleMasterBG(m_senderId) != BATTLEGROUND_TYPE_NONE)
        expire_delay = DAY;
    // default case: expire time if COD 3 days, if no COD 30 days (or 90 days if sender is a game master)
    else
    {
        if (COD)
            expire_delay = 3 * DAY;
        else
            expire_delay = pSender && pSender->IsGameMaster() ? 90 * DAY : 30 * DAY;
    }

    expire_time = deliver_time + expire_delay;

    return true;
}

bool MailMgr::PrepareMessageAttributeByGUID(ObjectGuid::LowType senderEntry, uint8 m_messageType, uint8& m_stationery, uint32 deliver_delay, uint32 COD, time_t& expire_time, time_t& deliver_time)
{
    m_stationery = MAIL_STATIONERY_DEFAULT;
    if (!senderEntry)
        m_stationery = MAIL_STATIONERY_GM;

    deliver_time = GameTime::GetGameTime() + deliver_delay;

    //expire time if COD 3 days, if no COD 30 days, if auction sale pending 1 hour
    uint32 expire_delay;
    // mail from battlemaster (rewardmarks) should last only one day
    if (m_messageType == MAIL_CREATURE && sBattlegroundMgr->GetBattleMasterBG(senderEntry) != BATTLEGROUND_TYPE_NONE)
        expire_delay = DAY;
    // default case: expire time if COD 3 days, if no COD 30 days (or 90 days if sender is a game master)
    else
    {
        if (COD)
            expire_delay = 3 * DAY;
        else
            expire_delay = 30 * DAY;
    }

    expire_time = deliver_time + expire_delay;

    return true;
}

bool MailMgr::PrepareMessageAttributeForAuctionAndCalendar(uint32 deliver_delay, uint32 COD, time_t& expire_time, time_t& deliver_time)
{
    deliver_time = GameTime::GetGameTime() + deliver_delay;
    //expire time if COD 3 days, if no COD 30 days, if auction sale pending 1 hour
    uint32 expire_delay;
    if (COD)
        expire_delay = 3 * DAY;
    else
        expire_delay = 30 * DAY;

    expire_time = deliver_time + expire_delay;

    return true;
}

uint32 MailMgr::AddNewMail(uint8 messageType, uint8 stationery, uint16 mailTemplateId, ObjectGuid::LowType sender, ObjectGuid::LowType receiver,
    std::string const& subject, std::string const& body, bool item_exists, uint32 money, time_t expire_time, time_t deliver_time,
    uint32 COD, uint8 checked, uint8 state)
{
    // find max id
    uint32 new_id = 0;
    for (MailMap::const_iterator itr = m_mails.begin(); itr != m_mails.end(); ++itr)
        if (itr->first > new_id)
            new_id = itr->first;

    // use next
    ++new_id;

    Mail nm;

    nm.messageType = messageType;
    nm.stationery = stationery;
    nm.mailTemplateId = mailTemplateId;
    nm.sender = sender;
    nm.receiver = receiver;
    nm.subject = subject;
    nm.body = body;
    nm.items_exist = item_exists;
    nm.expire_time = expire_time;
    nm.deliver_time = deliver_time;
    nm.money = money;
    nm.COD = COD;
    nm.checked = checked;
    nm.state = state;

    m_mails[new_id] = nm;

    // Add to DB
    uint8 index = 0;
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_MAIL);
    stmt->setUInt32(index, new_id);
    stmt->setUInt8(++index, messageType);
    stmt->setInt8(++index, stationery);
    stmt->setUInt16(++index, mailTemplateId);
    stmt->setUInt32(++index, sender);
    stmt->setUInt32(++index, receiver);
    stmt->setString(++index, subject);
    stmt->setString(++index, body);
    stmt->setInt8(++index, item_exists ? 1 : 0);
    stmt->setUInt64(++index, uint64(expire_time));
    stmt->setUInt64(++index, uint64(deliver_time));
    stmt->setUInt32(++index, money);
    stmt->setUInt32(++index, COD);
    stmt->setUInt8(++index, checked);
    stmt->setUInt8(++index, state);
    CharacterDatabase.Execute(stmt);

    time_t currentExpTime = GetMailMgrExpiryTimer();
    time_t now = GameTime::GetGameTime();
    if (expire_time - now < currentExpTime)
        _ExpTimer.Reset(expire_time - now);

    return new_id;
}

void MailMgr::RemoveAllMailsFor(ObjectGuid::LowType playerId)
{
    std::vector<uint32> mID;
    for (MailMap::const_iterator itr = m_mails.begin(); itr != m_mails.end(); ++itr)
    {
        if (itr->second.receiver == playerId)
            mID.push_back(itr->first);
    }

    if (mID.empty())
        return;

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    for (std::vector<uint32>::const_iterator itr = mID.begin(); itr != mID.end(); ++itr)
    {
        if (*itr)
            RemoveMail(*itr, trans);
    }
    CharacterDatabase.CommitTransaction(trans);

    mID.clear();
    clearDependInstanceItemsBeforeDeletePlayer(playerId);
}

void MailMgr::RemoveMail(uint32 mailID, CharacterDatabaseTransaction& trans)
{
    // before need to remove all mail items and instance items
    RemoveMailItemsByMailId(mailID, trans);
    // now clear from container
    m_mails.erase(mailID);

    // now clear from DB
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL_BY_ID);
    stmt->setUInt32(0, mailID);
    trans->Append(stmt);
}

void MailMgr::AddNewMailItem(uint32 mailID, Item* itemPointer, ObjectGuid::LowType itemGuidLow, ObjectGuid::LowType receiver, CharacterDatabaseTransaction& trans)
{
    bool itemexist = false;
    for (MailItemMap::const_iterator itr = m_mailitems.begin(); itr != m_mailitems.end(); ++itr)
        if (itr->second.item_guid == itemGuidLow)
            itemexist = true;

    if (itemexist)
    {
        TC_LOG_ERROR("mailMgr", "New Mail ({}) :: AddNewMailItem (GUID: {}), but item with this item_guid already exist, skip", mailID, itemGuidLow);
        return;
    }

    // find max id
    uint32 new_id = 0;
    for (MailItemMap::const_iterator itr = m_mailitems.begin(); itr != m_mailitems.end(); ++itr)
        if (itr->first > new_id)
            new_id = itr->first;

    // use next
    ++new_id;

    MailItem mii;
    mii.messageID = mailID;
    mii.item_guid = itemGuidLow;
    mii.receiver_guid = receiver;
    m_mailitems[new_id] = mii;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_MAIL_ITEM);
    stmt->setUInt32(0, new_id);
    stmt->setUInt32(1, mailID);
    stmt->setUInt32(2, itemGuidLow);
    stmt->setUInt32(3, receiver);
    trans->Append(stmt);

    AddMItem(itemPointer);
}

void MailMgr::RemoveMailItem(ObjectGuid::LowType itemGuidLow, CharacterDatabaseTransaction& trans)
{
    uint32 id = 0;
    for (MailItemMap::const_iterator itr = m_mailitems.begin(); itr != m_mailitems.end(); ++itr)
    {
        if (itr->second.item_guid == itemGuidLow)
        {
            id = itr->first;
            break;
        }
    }

    if (!id)
        return;

    RemoveMItem(itemGuidLow);
    m_mailitems.erase(id);

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL_ITEM);
    stmt->setUInt32(0, itemGuidLow);
    trans->Append(stmt);
}

void MailMgr::RemoveMailItemsByMailId(uint32 mailID, CharacterDatabaseTransaction& trans)
{
    std::vector<uint32> miID;
    for (MailItemMap::const_iterator itr = m_mailitems.begin(); itr != m_mailitems.end(); ++itr)
    {
        if (itr->second.messageID == mailID)
        {
            clearDependInstanceItem(itr->second.receiver_guid, mailID, trans);
            miID.push_back(itr->first);
        }
    }

    if (miID.empty())
        return;

    for (std::vector<uint32>::const_iterator itr = miID.begin(); itr != miID.end(); ++itr)
    {
        if (*itr)
            m_mailitems.erase(*itr);
    }

    miID.clear();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL_ITEMS_BY_MAILID);
    stmt->setUInt32(0, mailID);
    trans->Append(stmt);
}

uint32 MailMgr::GetUnreadMessagesAndNextDelivertime(ObjectGuid::LowType playerId, time_t& delivertime)
{
    uint32 unread = 0;
    time_t cTime = GameTime::GetGameTime();

    for (MailMap::const_iterator itr = m_mails.begin(); itr != m_mails.end(); ++itr)
    {
        if (itr->second.receiver == playerId)
        {
            if (itr->second.deliver_time > cTime)
            {
                if (!delivertime || delivertime > itr->second.deliver_time)
                    delivertime = itr->second.deliver_time;
            }
            else if (itr->second.checked == MAIL_CHECK_MASK_READ)
                ++unread;
        }
    }

    return unread;
}

uint32 MailMgr::GetMailBoxSize(ObjectGuid::LowType playerId)
{
    uint32 mails = 0;

    for (MailMap::const_iterator itr = m_mails.begin(); itr != m_mails.end(); ++itr)
    {
        if (itr->second.receiver == playerId)
                ++mails;
    }

    return mails;
}

bool MailMgr::HandleMailMarkAsRead(uint32 mailID)
{
    MailMap::iterator itr = m_mails.find(mailID);
    if (itr != m_mails.end())
    {
        itr->second.checked = itr->second.checked | MAIL_CHECK_MASK_READ;
        itr->second.state = MAIL_STATE_CHANGED;

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_MAIL_MARK_AS_READ);
        stmt->setUInt8(0, itr->second.checked);
        stmt->setUInt8(1, itr->second.state);
        stmt->setUInt32(2, itr->first);
        CharacterDatabase.Execute(stmt);
        return true;
    }

    return false;
}

bool MailMgr::HandleMailDelete(uint32 mailID)
{
    bool result = false;
    MailMap::const_iterator itr = m_mails.find(mailID);
    if (itr != m_mails.end())
    {
        result = true;
        // if mail with item and COD we should reward sender (he should not lost the money)
        if (itr->second.COD && itr->second.sender && itr->second.messageType == MAIL_NORMAL)
            SendMailByGUID(0, itr->second.sender, MAIL_NORMAL, "Money received", "From old mail with COD", itr->second.COD, MAIL_CHECK_MASK_COD_PAYMENT);
    }

    if (result)
    {
        CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
        RemoveMail(mailID, trans);
        CharacterDatabase.CommitTransaction(trans);
    }    

    return result;
}

MailResponseResult MailMgr::HandleMailReturnToSender(uint32 mailID)
{
    uint32 new_sender    = 0;
    uint32 new_receiver  = 0;
    uint32 money         = 0;
    uint32 deliver_delay = 0;
    std::string subject, body;
    bool itemsExist = false;

    // Handle old-exist mailID (check it)
    MailMap::const_iterator itr = m_mails.find(mailID);
    if (itr != m_mails.end())
    {
        if (itr->second.deliver_time > GameTime::GetGameTime())
            return MAIL_ERR_INTERNAL_ERROR;

        ObjectGuid oldsenderGuid(HighGuid::Player, itr->second.sender);
        ObjectGuid oldreceiverGuid(HighGuid::Player, itr->second.receiver);

        uint32 sr_account = 0;
        uint32 rc_account = 0;

        sr_account = sCharacterCache->GetCharacterAccountIdByGuid(oldsenderGuid);
        rc_account = sCharacterCache->GetCharacterAccountIdByGuid(oldreceiverGuid);

        Player* oldsender = ObjectAccessor::FindConnectedPlayer(oldsenderGuid);

        if (!oldsender && !sr_account) // sender (new receiver) not exist
            return MAIL_ERR_RECIPIENT_NOT_FOUND;

        if (itr->second.sender) // new receiver
        {
            // AditionalData
            /*
            if (Player* receiver = ObjectAccessor::FindPlayerByLowGUID(itr->second.sender))
            {
                if (GetMailBoxSize(itr->second.sender) + receiver->GetAuctionLotsCount() > sWorld->customGetIntConfig(CONFIG_ANTISPAM_MAIL_COUNT_CONTROLLER))
                    return MAIL_ERR_RECIPIENT_CAP_REACHED;
            }*/
        }

        // MAIL_OK, now just gather info from mail for new mail
        new_receiver = itr->second.sender;
        new_sender = itr->second.receiver;
        subject = itr->second.subject;
        body = itr->second.body;
        money = itr->second.money;
        if (itr->second.items_exist)
            itemsExist = true;

        bool needItemDelay = sr_account != rc_account;
        // If theres is an item, there is a one hour delivery delay.
        deliver_delay = needItemDelay ? sWorld->getIntConfig(CONFIG_MAIL_DELIVERY_DELAY) : 0;
    }

    // 1 step - send new mail
    uint32 new_mailID = SendReturnMailByGUID(mailID, new_sender, new_receiver, subject, body, money, itemsExist, deliver_delay);

    // 2 step - update mail_items for new mailid
    if (itemsExist)
    {
        CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
        for (MailItemMap::iterator itr = m_mailitems.begin(); itr != m_mailitems.end(); ++itr)
        {
            if (itr->second.messageID == mailID)
            {
                itr->second.receiver_guid = new_receiver;
                // update mailId in memory container (in DB it already done in SendReturnMailByGUID func)
                itr->second.messageID = new_mailID;

                // owner in data will set at mail receive and item extracting
                CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ITEM_OWNER);
                stmt->setUInt32(0, itr->second.receiver_guid);
                stmt->setUInt32(1, itr->second.item_guid);
                trans->Append(stmt);
            }
        }
        CharacterDatabase.CommitTransaction(trans);
    }

    // 3 step - delete old mail
    CharacterDatabaseTransaction trans2 = CharacterDatabase.BeginTransaction();
    RemoveMail(mailID, trans2);
    CharacterDatabase.CommitTransaction(trans2);
    return MAIL_OK;
}

MailResponseResult MailMgr::HandleMailTakeItem(Player* player, uint32 mailID, ObjectGuid::LowType item_guid, uint32& count, uint32& msg_result)
{
    if (!player || !player->GetSession())
        return MAIL_ERR_RECIPIENT_NOT_FOUND;

    MailMap::iterator itr = m_mails.find(mailID);
    if (itr != m_mails.end())
    {
        if (itr->second.deliver_time > GameTime::GetGameTime())
            return MAIL_ERR_INTERNAL_ERROR;

        // check on item id
        bool itemexist = false;
        for (MailItemMap::iterator itr = m_mailitems.begin(); itr != m_mailitems.end(); ++itr)
        {
            if (itr->second.messageID == mailID && itr->second.item_guid == item_guid)
                itemexist = true;
        }

        Item* it = sMailMgr->GetMItem(item_guid);
        if (!it || !itemexist)
        {
            if (!it && itemexist)
                TC_LOG_ERROR("mailMgr", "Mail ({}) has item (GUID: {}), but doesn not exist in ItemMap of pointers", mailID, item_guid);
            if (it && !itemexist)
                TC_LOG_ERROR("mailMgr", "Mail ({}) has item (GUID: {}), but doesn not exist in MailItemMap", mailID, item_guid);
            return MAIL_ERR_MAIL_ATTACHMENT_INVALID;
        }

        if (!player->HasEnoughMoney(itr->second.COD))
            return MAIL_ERR_CANT_SEND_WRAPPED_COD;

        ItemPosCountVec dest;
        msg_result = player->CanStoreItem(NULL_BAG, NULL_SLOT, dest, it, false);
        if (msg_result == EQUIP_ERR_OK)
        {
            CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

            //if there is COD, take COD money from player and send them to sender by mail
            if (itr->second.COD > 0)
            {
                ObjectGuid sender_guid(HighGuid::Player, itr->second.sender);
                Player* receiver = ObjectAccessor::FindConnectedPlayer(sender_guid);

                uint32 sender_accId = 0;

                if (player->GetSession()->HasPermission(rbac::RBAC_PERM_LOG_GM_TRADE))
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
                    sLog->OutCommand(player->GetSession()->GetAccountId(), "GM {} (Account: {}) receiver mail item: {} (Entry: {} Count: {}) and send COD money: {} to player: {} (Account: {})",
                        player->GetName(), player->GetSession()->GetAccountId(), it->GetTemplate()->Name1, it->GetEntry(), it->GetCount(), itr->second.COD, sender_name, sender_accId);
                }
                else if (!receiver)
                    sender_accId = sCharacterCache->GetCharacterAccountIdByGuid(sender_guid);

                // check player existence
                if (receiver || sender_accId)
                    SendMailBy(player, itr->second.sender, itr->second.subject, "", itr->second.COD, MAIL_CHECK_MASK_COD_PAYMENT);

                player->ModifyMoney(-int32(itr->second.COD));

                itr->second.COD = 0;
            }

            //upd state
            itr->second.state = MAIL_STATE_CHANGED;
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_MAIL_STATE);
            stmt->setUInt8(0, MAIL_STATE_CHANGED);
            stmt->setUInt32(1, mailID);
            trans->Append(stmt);

            count = it->GetCount();                      // save counts before store and possible merge with deleting
            it->SetState(ITEM_UNCHANGED);                       // need to set this state, otherwise item cannot be removed later, if neccessary
            player->MoveItemToInventory(dest, it, true);
            player->SaveInventoryAndGoldToDB(trans);

            // upd owner of item
            CharacterDatabasePreparedStatement* stmt2 = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ITEM_OWNER);
            stmt2->setUInt32(0, player->GetGUID().GetCounter());
            stmt2->setUInt32(1, item_guid);
            trans->Append(stmt2);

            RemoveMailItem(item_guid, trans);

            // check on others items in this mail, and set "has_items" = 0 if no
            bool has_items = false;
            for (MailItemMap::iterator itr = m_mailitems.begin(); itr != m_mailitems.end(); ++itr)
            {
                if (itr->second.messageID == mailID)
                    has_items = true;
            }

            CharacterDatabasePreparedStatement* stmt3 = CharacterDatabase.GetPreparedStatement(CHAR_UPD_MAIL_ITEM_HAS_ITEM);
            stmt3->setUInt8(0, has_items ? 1 : 0);
            stmt3->setUInt32(1, mailID);
            trans->Append(stmt3);

            CharacterDatabase.CommitTransaction(trans);
            return MAIL_OK;
        }
        else
            return MAIL_ERR_EQUIP_ERROR;
    }

    return MAIL_ERR_INTERNAL_ERROR;
}

MailResponseResult MailMgr::HandleMailTakeMoney(Player* player, uint32 mailID, uint32& msg_result)
{
    if (!player)
        return MAIL_ERR_RECIPIENT_NOT_FOUND;

    MailMap::iterator itr = m_mails.find(mailID);
    if (itr != m_mails.end())
    {
        if (itr->second.deliver_time > GameTime::GetGameTime())
            return MAIL_ERR_INTERNAL_ERROR;

        if (!player->ModifyMoney(itr->second.money, false))
        {
            msg_result = EQUIP_ERR_TOO_MUCH_GOLD;
            return MAIL_ERR_EQUIP_ERROR;
        }

        itr->second.money = 0;
        itr->second.state = MAIL_STATE_CHANGED;

        player->SendMailResult(mailID, MAIL_MONEY_TAKEN, MAIL_OK);

        // save money and mail to prevent cheating
        CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
        player->SaveGoldToDB(trans);
        _RemoveMoneyFromMail(mailID, trans);
        CharacterDatabase.CommitTransaction(trans);
        return MAIL_OK;
    }

    return MAIL_ERR_INTERNAL_ERROR;
}

void MailMgr::HandleGetMailList(Player* player, WorldPacket& data)
{
    uint32 mailsCount = 0;                                // real send to client mails amount
    uint32 realCount = 0;                                 // real mails amount

    data << uint32(0);                                      // real mail's count
    data << uint8(0);                                       // mail's count
    time_t cur_time = GameTime::GetGameTime();

    for (MailMap::iterator itr = m_mails.begin(); itr != m_mails.end(); ++itr)
    {
        if (itr->second.receiver == player->GetGUID().GetCounter())
        {
            // Only first 50 mails are displayed
            if (mailsCount >= 50)
            {
                realCount += 1;
                continue;
            }

            // skip not delivered (deliver delay not expired) mails
            if (cur_time < itr->second.deliver_time)
                continue;

            uint32 mailID = itr->first;
            uint8 item_count = 0;
            for (MailItemMap::const_iterator itr = m_mailitems.begin(); itr != m_mailitems.end(); ++itr)
            {
                if (itr->second.messageID == mailID)
                    ++item_count;
            }

            size_t next_mail_size = 2 + 4 + 1 + (itr->second.messageType == MAIL_NORMAL ? 8 : 4) + 4 * 8 + (itr->second.subject.size() + 1) + (itr->second.body.size() + 1) + 1 + item_count * (1 + 4 + 4 + MAX_INSPECTED_ENCHANTMENT_SLOT * 3 * 4 + 4 + 4 + 4 + 4 + 4 + 4 + 1);

            if (data.wpos() + next_mail_size > MAX_NETCLIENT_PACKET_SIZE)
            {
                realCount += 1;
                continue;
            }

            data << uint16(next_mail_size);                    // Message size
            data << uint32(itr->first);                        // Message ID
            data << uint8(itr->second.messageType);            // Message Type

            switch (itr->second.messageType)
            {
                case MAIL_NORMAL:                              // sender guid
                    data << ObjectGuid(HighGuid::Player, itr->second.sender);
                    break;
                case MAIL_CREATURE:
                case MAIL_GAMEOBJECT:
                case MAIL_AUCTION:
                case MAIL_CALENDAR:
                    data << uint32(itr->second.sender);              // creature/gameobject entry, auction id, calendar event id?
                    break;
            }

            data << uint32(itr->second.COD);                         // COD
            data << uint32(0);                                       // package (Package.dbc)
            data << uint32(itr->second.stationery);                  // stationery (Stationery.dbc)
            data << uint32(itr->second.money);                       // Gold
            data << uint32(itr->second.checked);                     // flags
            data << float(float(itr->second.expire_time - GameTime::GetGameTime()) / DAY); // Time
            data << uint32(itr->second.mailTemplateId);              // mail template (MailTemplate.dbc)
            data << itr->second.subject;                             // Subject string - once 00, when mail type = 3, max 256
            data << itr->second.body;                                // message? max 8000
            data << uint8(item_count);                               // client limit is 0x10

            uint8 ItemIntex = 0;
            for (MailItemMap::const_iterator itr = m_mailitems.begin(); itr != m_mailitems.end(); ++itr)
            {
                if (itr->second.messageID == mailID)
                {
                    ++ItemIntex;
                    Item* item = GetMItem(itr->second.item_guid);
                    // item index (0-6?)
                    data << uint8(ItemIntex);
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
            }

            ++realCount;
            ++mailsCount;
        }
    }

    data.put<uint32>(0, realCount);                        // this will display warning about undelivered mail to player if realCount > mailsCount
    data.put<uint8>(4, mailsCount);                        // set real send mails to client
}

MailResponseResult MailMgr::HandleMailCreateTextItem(Player* player, uint32 mailID, uint32& msg_result)
{
    if (!player || !player->GetSession())
        return MAIL_ERR_RECIPIENT_NOT_FOUND;

    MailMap::iterator itr = m_mails.find(mailID);
    if (itr != m_mails.end())
    {
        if ((itr->second.body.empty() && !itr->second.mailTemplateId) || itr->second.deliver_time > GameTime::GetGameTime() || (itr->second.checked & MAIL_CHECK_MASK_COPIED))
            return MAIL_ERR_INTERNAL_ERROR;

        Item* bodyItem = new Item;                              // This is not bag and then can be used new Item.
        if (!bodyItem->Create(sObjectMgr->GetGenerator<HighGuid::Item>().Generate(), MAIL_BODY_ITEM_TEMPLATE, player))
        {
            delete bodyItem;
            return MAIL_ERR_MAIL_ATTACHMENT_INVALID;
        }

        // in mail template case we need create new item text
        if (itr->second.mailTemplateId)
        {
            MailTemplateDBC const* mailTemplateEntry = sDBCStoresMgr->GetMailTemplateDBC(itr->second.mailTemplateId);
            ASSERT(mailTemplateEntry);
            bodyItem->SetText(mailTemplateEntry->Body[player->GetSession()->GetSessionDbcLocale()]);
        }
        else
            bodyItem->SetText(itr->second.body);

        if (itr->second.messageType == MAIL_NORMAL)
            bodyItem->SetGuidValue(ITEM_FIELD_CREATOR, ObjectGuid(HighGuid::Player, itr->second.sender));

        bodyItem->SetFlag(ITEM_FIELD_FLAGS, ITEM_FLAG_MAIL_TEXT_MASK);

        TC_LOG_DEBUG("network", "HandleMailCreateTextItem mailid={}", mailID);

        ItemPosCountVec dest;
        msg_result = player->CanStoreItem(NULL_BAG, NULL_SLOT, dest, bodyItem, false);
        if (msg_result == EQUIP_ERR_OK)
        {
            itr->second.checked = itr->second.checked | MAIL_CHECK_MASK_COPIED;
            itr->second.state = MAIL_STATE_CHANGED;
            player->StoreItem(dest, bodyItem, true);
            return MAIL_OK;
        }
        else
        {
            delete bodyItem;
            return MAIL_ERR_EQUIP_ERROR;
        }
    }

    return MAIL_ERR_INTERNAL_ERROR;
}

bool MailMgr::HandleQueryNextMailTime(Player* player, WorldPacket& data)
{
    if (!player)
        return false;

    data << float(0);                                  // float
    data << uint32(0);                                 // count

    uint32 count = 0;
    time_t now = GameTime::GetGameTime();
    std::set<uint32> sentSenders;

    for (MailMap::iterator itr = m_mails.begin(); itr != m_mails.end(); ++itr)
    {
        if (itr->second.receiver == player->GetGUID().GetCounter())
        {
            // must be not checked yet
            if (itr->second.checked & MAIL_CHECK_MASK_READ)
                continue;

            // and already delivered
            if (now < itr->second.deliver_time)
                continue;

            // only send each mail sender once
            if (sentSenders.count(itr->second.sender))
                continue;

            data << uint64(itr->second.messageType == MAIL_NORMAL ? ObjectGuid(HighGuid::Player, itr->second.sender) : ObjectGuid::Empty);  // player guid
            data << uint32(itr->second.messageType != MAIL_NORMAL ? itr->second.sender : 0);  // non-player entries
            data << uint32(itr->second.messageType);
            data << uint32(itr->second.stationery);
            data << float(itr->second.deliver_time - now);

            sentSenders.insert(itr->second.sender);
            ++count;
            if (count == 2)                                  // do not display more than 2 mails
                break;
        }
    }

    sentSenders.clear();

    data.put<uint32>(4, count);

    return true;
}

Item* MailMgr::GetMItem(uint32 id)
{
    ItemMap::const_iterator itr = mMitems.find(id);
    return itr != mMitems.end() ? itr->second : nullptr;
}

void MailMgr::AddMItem(Item* it)
{
    ASSERT(it);
    //ASSERT deleted, because items can be added before loading
    mMitems[it->GetGUID().GetCounter()] = it;
}

bool MailMgr::RemoveMItem(uint32 id)
{
    return mMitems.erase(id) ? true : false;
}

// sql helper in func
// set zero money in Mail in db when received money
void MailMgr::_RemoveMoneyFromMail(uint32 mailId, CharacterDatabaseTransaction& trans) const
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_MAIL_MONEY_RECEIVED);
    stmt->setUInt32(0, 0);
    stmt->setUInt32(1, mailId);
    trans->Append(stmt);
}

// load mails
void MailMgr::_LoadMails()
{
    uint32 oldMSTime = getMSTime();

    m_mails.clear();
    //                                                    0       1            2               3         4       5         6       7       8         9             10         11    12     13      14
    QueryResult result = CharacterDatabase.Query("SELECT id, messageType, stationery, mailTemplateId, sender, receiver, subject, body, has_items, expire_time, deliver_time, money, cod, checked, state FROM mail");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 Mails. DB table `mail` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        Mail nm;
        nm.messageType = fields[1].GetUInt8();
        nm.stationery = fields[2].GetUInt8();
        nm.mailTemplateId = fields[3].GetUInt16();
        nm.sender = fields[4].GetUInt32();
        nm.receiver = fields[5].GetUInt32();
        nm.subject = fields[6].GetString();
        nm.body = fields[7].GetString();
        nm.items_exist = fields[8].GetUInt8() == 1 ? true : false;
        nm.expire_time = time_t(fields[9].GetUInt64());
        nm.deliver_time = time_t(fields[10].GetUInt64());
        nm.money = fields[11].GetUInt32();
        nm.COD = fields[12].GetUInt32();
        nm.checked = fields[13].GetUInt8();
        nm.state = fields[14].GetUInt8();

        m_mails[id] = nm;

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} mails in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void MailMgr::_LoadMailItems()
{
    uint32 oldMSTime = getMSTime();

    m_mailitems.clear();
    //                                                    0     1        2          3
    QueryResult result = CharacterDatabase.Query("SELECT id, mail_id, item_guid, receiver FROM mail_items");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 Mail items. DB table `mail_items` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        MailItem mii;
        uint32 id = fields[0].GetUInt32();
        mii.messageID = fields[1].GetUInt32();
        mii.item_guid = fields[2].GetUInt32();
        mii.receiver_guid = fields[3].GetUInt32();
        m_mailitems[id] = mii;

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} mail items in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// load mailed item which should receive current player
void MailMgr::_LoadMailedItemPointers()
{
    mMitems.clear();
    // data needs to be at first place for Item::LoadFromDB
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_MAILITEMS);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();

        ObjectGuid::LowType itemGuid = fields[11].GetUInt32();
        uint32 itemTemplate = fields[12].GetUInt32();

        ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemTemplate);

        if (!proto)
        {
            TC_LOG_ERROR("mailMgr", "Mail has unknown item_template in mailed items (GUID: {}, Entry: {}), deleted.", itemGuid, itemTemplate);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL_ITEM);
            stmt->setUInt32(0, itemGuid);
            CharacterDatabase.Execute(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE);
            stmt->setUInt32(0, itemGuid);
            CharacterDatabase.Execute(stmt);
            continue;
        }

        Item* item = NewItemOrBag(proto);

        if (!item->LoadFromDB(itemGuid, ObjectGuid(HighGuid::Player, fields[13].GetUInt32()), fields, itemTemplate))
        {
            TC_LOG_ERROR("entities.player", "Player::_LoadMailedItems: Item (GUID: {}) in mail doesn't exist, deleted from mail.", itemGuid);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL_ITEM);
            stmt->setUInt32(0, itemGuid);
            CharacterDatabase.Execute(stmt);

            item->FSetState(ITEM_REMOVED);

            CharacterDatabaseTransaction temp = CharacterDatabaseTransaction(nullptr);
            item->SaveToDB(temp);                               // it also deletes item object !
            continue;
        }

        AddMItem(item);
    } while (result->NextRow());
}

void MailMgr::_DeleteExpiryMails(bool startServer)
{
    std::vector<uint32>mailIds;
    time_t now = GameTime::GetGameTime();

    for (MailMap::iterator itr = m_mails.begin(); itr != m_mails.end(); ++itr)
    {
        if (itr->second.expire_time <= now)
        {
            mailIds.push_back(itr->first);

            // if mail with item and COD we should reward sender (he should not lost the money)
            if (itr->second.COD && itr->second.sender && itr->second.messageType == MAIL_NORMAL)
                SendMailByGUID(0, itr->second.sender, MAIL_NORMAL, "Money received", "From old mail with COD", itr->second.COD, MAIL_CHECK_MASK_COD_PAYMENT);
        }
    }

    if (!mailIds.empty())
    {
        CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
        for (std::vector<uint32>::iterator itr = mailIds.begin(); itr != mailIds.end(); ++itr)
            RemoveMail((*itr), trans);

        CharacterDatabase.CommitTransaction(trans);
    }

    mailIds.clear();

    // set new exp time
    if (!startServer)
        _UpdateExpiryTime();
}

time_t MailMgr::GetNextExpireMailUpd()
{
    time_t nextExpiry = GameTime::GetGameTime() + (12 * HOUR);

    for (MailMap::iterator itr = m_mails.begin(); itr != m_mails.end(); ++itr)
    {
        if (itr->second.expire_time < nextExpiry)
            nextExpiry = itr->second.expire_time;
    }

    return nextExpiry;
}

void MailMgr::_UpdateExpiryTime()
{
    time_t now = GameTime::GetGameTime();
    time_t newExpiry = GetNextExpireMailUpd();

    _ExpTimer.Reset(newExpiry - now);
}
