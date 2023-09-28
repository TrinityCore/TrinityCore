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

#ifndef _MAILMGR_H
#define _MAILMGR_H

#include "Common.h"
#include "Mail.h"
#include "Item.h"
#include "ObjectGuid.h"
#include "Timer.h"

struct AuctionEntry;
struct CalendarEvent;
enum MailTimers
{
    MAIL_UPDATE_INTERVAL = 1000 // 1 sec
};

struct TC_GAME_API Mail
{
    //uint32 messageID;  // number is itr->first
    uint8 messageType;
    uint8 stationery;
    uint16 mailTemplateId;
    ObjectGuid::LowType sender;
    ObjectGuid::LowType receiver;
    std::string subject;
    std::string body;
    bool items_exist;
    time_t expire_time;
    time_t deliver_time;
    uint32 money;
    uint32 COD;
    uint8 checked;
    uint8 state;
};
typedef std::unordered_map<uint32 /*mailId*/, Mail> MailMap;

struct TC_GAME_API MailItem
{
    uint32 messageID;
    ObjectGuid::LowType item_guid;
    ObjectGuid::LowType receiver_guid;
};
typedef std::unordered_map<uint32 /*mailItemId*/, MailItem> MailItemMap;

class Item;
class Object;
class Player;

class TC_GAME_API MailMgr
{
private:
    MailMgr();
    ~MailMgr();

public:
    static MailMgr* instance();

    void Initialize();

    void Update(uint32 diff);

    void SendMailBy(Object* sender, ObjectGuid::LowType receiver, std::string const& subject, std::string const& body, uint32 money, MailCheckMask mask = MAIL_CHECK_MASK_NONE, uint32 deliver_delay = 0, uint32 COD = 0);
    void SendMailByGUID(ObjectGuid::LowType sender, ObjectGuid::LowType receiver, uint8 m_messageType, std::string const& subject, std::string const& body, uint32 money, MailCheckMask mask = MAIL_CHECK_MASK_NONE, uint32 deliver_delay = 0, uint32 COD = 0);

    void SendMailWithItemsBy(Object* sender, ObjectGuid::LowType receiver, std::string const& subject, std::string const& body, uint32 money, std::vector<Item*> const& itemlist, MailCheckMask mask = MAIL_CHECK_MASK_NONE, uint32 deliver_delay = 0, uint32 COD = 0);
    void SendMailWithItemsByGUID(ObjectGuid::LowType sender, ObjectGuid::LowType receiver, uint8 m_messageType, std::string const& subject, std::string const& body, uint32 money, std::vector<Item*> const& itemlist, MailCheckMask mask = MAIL_CHECK_MASK_NONE, uint32 deliver_delay = 0, uint32 COD = 0);

    void SendMailByAuctionHouse(AuctionEntry* sender, ObjectGuid::LowType receiver, std::string const& subject, std::string const& body, uint32 money, MailCheckMask mask = MAIL_CHECK_MASK_NONE, uint32 deliver_delay = 0, uint32 COD = 0);
    void SendMailByAuctionHouseWithItems(AuctionEntry* sender, ObjectGuid::LowType receiver, std::string const& subject, std::string const& body, uint32 money, std::vector<Item*> const& itemlist, MailCheckMask mask = MAIL_CHECK_MASK_NONE, uint32 deliver_delay = 0, uint32 COD = 0);

    void SendMailByCalendarEvent(CalendarEvent* sender, ObjectGuid::LowType receiver, std::string const& subject, std::string const& body, uint32 money, MailCheckMask mask = MAIL_CHECK_MASK_NONE, uint32 deliver_delay = 0, uint32 COD = 0);
    void SendMailByCalendarEventWithItems(CalendarEvent* sender, ObjectGuid::LowType receiver, std::string const& subject, std::string const& body, uint32 money, std::vector<Item*> const& itemlist, MailCheckMask mask = MAIL_CHECK_MASK_NONE, uint32 deliver_delay = 0, uint32 COD = 0);

    void SendMailWithTemplateBy(Object* sender, ObjectGuid::LowType receiver, uint16 mailTemplateId, MailCheckMask mask = MAIL_CHECK_MASK_HAS_BODY, uint32 deliver_delay = 0);
    void SendMailWithTemplateByGUID(ObjectGuid::LowType sender, ObjectGuid::LowType receiver, uint8 messageType, uint16 mailTemplateId, MailCheckMask mask = MAIL_CHECK_MASK_HAS_BODY, uint32 deliver_delay = 0);

    void RemoveAllMailsFor(ObjectGuid::LowType playerId);

    uint32 GetUnreadMessagesAndNextDelivertime(ObjectGuid::LowType playerId, time_t& delivertime);
    uint32 GetMailBoxSize(ObjectGuid::LowType playerId);

    bool HandleMailMarkAsRead(uint32 mailID);
    bool HandleMailDelete(uint32 mailID);
    MailResponseResult HandleMailReturnToSender(uint32 mailID);
    MailResponseResult HandleMailTakeItem(Player* player, uint32 mailID, ObjectGuid::LowType item_guid, uint32& count, uint32& msg_result);
    MailResponseResult HandleMailTakeMoney(Player* player, uint32 mailID, uint32& msg_result);
    void HandleGetMailList(Player* player, WorldPacket& data);
    MailResponseResult HandleMailCreateTextItem(Player* player, uint32 mailID, uint32& msg_result);
    bool HandleQueryNextMailTime(Player* player, WorldPacket& data);

    time_t GetMailMgrExpiryTimer() { return _ExpTimer.GetExpiry().count(); }

    MailMap const& GetMailMap() const { return m_mails; }

protected:

    // Mail section
    uint32 AddNewMail(
        uint8 messageType, uint8 stationery, uint16 mailTemplateId, ObjectGuid::LowType sender, ObjectGuid::LowType receiver,
        std::string const& subject, std::string const& body, bool items, uint32 money, time_t expire_time, time_t deliver_time,
        uint32 COD, uint8 checked = MAIL_CHECK_MASK_NONE, uint8 state = MAIL_STATE_UNCHANGED
    );

    // Mail Item section
    void AddNewMailItem(uint32 mailID, Item* itemPointer, ObjectGuid::LowType itemGuidLow, ObjectGuid::LowType receiver, CharacterDatabaseTransaction& trans);

    Item* GetMItem(uint32 id);
    void AddMItem(Item* it);
    bool RemoveMItem(uint32 id);

    void RemoveMail(uint32 mailID, CharacterDatabaseTransaction& trans);
    void RemoveMailItem(ObjectGuid::LowType itemGuidLow, CharacterDatabaseTransaction& trans);
    void RemoveMailItemsByMailId(uint32 mailID, CharacterDatabaseTransaction& trans);

    // helper
    bool PrepareMessageAttributeBy(Object* sender, ObjectGuid::LowType receiver, uint8& m_messageType, uint8& m_stationery, ObjectGuid::LowType& m_senderId, uint32 deliver_delay, uint32 COD, time_t& expire_time, time_t& deliver_time);
    bool PrepareMessageAttributeByGUID(ObjectGuid::LowType sender, uint8 m_messageType, uint8& m_stationery, uint32 deliver_delay, uint32 COD, time_t& expire_time, time_t& deliver_time);
    bool PrepareMessageAttributeForAuctionAndCalendar(uint32 deliver_delay, uint32 COD, time_t& expire_time, time_t& deliver_time);

    void prepareItems(uint32 mailId, uint16 mailTemplateId, Player* receiver);
    uint32 SendReturnMailByGUID(uint32 old_mailID, ObjectGuid::LowType sender, ObjectGuid::LowType receiver, std::string const& subject, std::string const& body, uint32 money, bool itemexist, uint32 deliver_delay = 0);

    void clearDependInstanceItem(ObjectGuid::LowType playerId, uint32 mailID, CharacterDatabaseTransaction& trans);
    void clearDependInstanceItemsBeforeDeletePlayer(ObjectGuid::LowType playerId);

    void _LoadMails();
    void _LoadMailItems();
    void _LoadMailedItemPointers();

    void _UpdateExpiryTime();
    time_t GetNextExpireMailUpd();
    void _DeleteExpiryMails(bool startServer = false);

    void _RemoveMoneyFromMail(uint32 mailId, CharacterDatabaseTransaction& trans) const;

private:
    typedef std::unordered_map<uint32, Item*> ItemMap;

    MailMap m_mails;
    MailItemMap m_mailitems;
    ItemMap mMitems;                                    //template defined in objectmgr.cpp
    // update interval
    uint32 m_updateTimer;
    TimeTracker _ExpTimer;
};

#define sMailMgr MailMgr::instance()

#endif // _MAILMGR_H
