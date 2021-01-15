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

#include "Guild.h"
#include "AccountMgr.h"
#include "Bag.h"
#include "CalendarMgr.h"
#include "CalendarPackets.h"
#include "CharacterCache.h"
#include "Chat.h"
#include "ChatPackets.h"
#include "Config.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "GuildFinderMgr.h"
#include "GuildMgr.h"
#include "GuildPackets.h"
#include "Language.h"
#include "Log.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SocialMgr.h"
#include "World.h"
#include "WorldSession.h"

size_t const MAX_GUILD_BANK_TAB_TEXT_LEN = 500;

uint32 const EMBLEM_PRICE = 10 * GOLD;

inline uint64 GetGuildBankTabPrice(uint8 tabId)
{
    // these prices are in gold units, not copper
    static uint64 const tabPrices[GUILD_BANK_MAX_TABS] = { 100, 250, 500, 1000, 2500, 5000, 0, 0 };
    ASSERT(tabId < GUILD_BANK_MAX_TABS);

    return tabPrices[tabId];
}

void Guild::SendCommandResult(WorldSession* session, GuildCommandType type, GuildCommandError errCode, std::string const& param)
{
    WorldPackets::Guild::GuildCommandResult resultPacket;
    resultPacket.Command = type;
    resultPacket.Result = errCode;
    resultPacket.Name = param;
    session->SendPacket(resultPacket.Write());

    TC_LOG_DEBUG("guild", "SMSG_GUILD_COMMAND_RESULT [%s]: Type: %u, code: %u, param: %s"
         , session->GetPlayerInfo().c_str(), type, errCode, param.c_str());
}

void Guild::SendSaveEmblemResult(WorldSession* session, GuildEmblemError errCode)
{
    WorldPackets::Guild::PlayerSaveGuildEmblem saveResponse;
    saveResponse.Error = int32(errCode);
    session->SendPacket(saveResponse.Write());

    TC_LOG_DEBUG("guild", "Sent SMSG_SAVE_GUILD_EMBLEM [%s] Code: %u", session->GetPlayerInfo().c_str(), errCode);
}

// LogHolder
Guild::LogHolder::~LogHolder()
{
    // Cleanup
    for (auto itr = m_log.begin(); itr != m_log.end(); ++itr)
        delete (*itr);
}

// Adds event loaded from database to collection
inline void Guild::LogHolder::LoadEvent(LogEntry* entry)
{
    if (m_nextGUID == uint32(GUILD_EVENT_LOG_GUID_UNDEFINED))
        m_nextGUID = entry->GetGUID();
    m_log.push_front(entry);
}

// Adds new event happened in game.
// If maximum number of events is reached, oldest event is removed from collection.
inline void Guild::LogHolder::AddEvent(CharacterDatabaseTransaction& trans, LogEntry* entry)
{
    // Check max records limit
    if (m_log.size() >= m_maxRecords)
    {
        LogEntry* oldEntry = m_log.front();
        delete oldEntry;
        m_log.pop_front();
    }
    // Add event to list
    m_log.push_back(entry);
    // Save to DB
    entry->SaveToDB(trans);
}

inline uint32 Guild::LogHolder::GetNextGUID()
{
    // Next guid was not initialized. It means there are no records for this holder in DB yet.
    // Start from the beginning.
    if (m_nextGUID == uint32(GUILD_EVENT_LOG_GUID_UNDEFINED))
        m_nextGUID = 0;
    else
        m_nextGUID = (m_nextGUID + 1) % m_maxRecords;
    return m_nextGUID;
}

// EventLogEntry
void Guild::EventLogEntry::SaveToDB(CharacterDatabaseTransaction& trans) const
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_EVENTLOG);
    stmt->setUInt64(0, m_guildId);
    stmt->setUInt32(1, m_guid);
    trans->Append(stmt);

    uint8 index = 0;
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_EVENTLOG);
    stmt->setUInt64(  index, m_guildId);
    stmt->setUInt32(++index, m_guid);
    stmt->setUInt8 (++index, uint8(m_eventType));
    stmt->setUInt64(++index, m_playerGuid1);
    stmt->setUInt64(++index, m_playerGuid2);
    stmt->setUInt8 (++index, m_newRank);
    stmt->setUInt64(++index, m_timestamp);
    trans->Append(stmt);
}

void Guild::EventLogEntry::WritePacket(WorldPackets::Guild::GuildEventLogQueryResults& packet) const
{
    ObjectGuid playerGUID = ObjectGuid::Create<HighGuid::Player>(m_playerGuid1);
    ObjectGuid otherGUID = ObjectGuid::Create<HighGuid::Player>(m_playerGuid2);

    WorldPackets::Guild::GuildEventEntry eventEntry;
    eventEntry.PlayerGUID = playerGUID;
    eventEntry.OtherGUID = otherGUID;
    eventEntry.TransactionType = uint8(m_eventType);
    eventEntry.TransactionDate = uint32(::time(nullptr) - m_timestamp);
    eventEntry.RankID = uint8(m_newRank);
    packet.Entry.push_back(eventEntry);
}

// BankEventLogEntry
void Guild::BankEventLogEntry::SaveToDB(CharacterDatabaseTransaction& trans) const
{
    uint8 index = 0;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_BANK_EVENTLOG);
    stmt->setUInt64(  index, m_guildId);
    stmt->setUInt32(++index, m_guid);
    stmt->setUInt8 (++index, m_bankTabId);
    trans->Append(stmt);

    index = 0;
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_BANK_EVENTLOG);
    stmt->setUInt64(  index, m_guildId);
    stmt->setUInt32(++index, m_guid);
    stmt->setUInt8 (++index, m_bankTabId);
    stmt->setUInt8 (++index, uint8(m_eventType));
    stmt->setUInt64(++index, m_playerGuid);
    stmt->setUInt64(++index, m_itemOrMoney);
    stmt->setUInt16(++index, m_itemStackCount);
    stmt->setUInt8 (++index, m_destTabId);
    stmt->setUInt64(++index, m_timestamp);
    trans->Append(stmt);
}

void Guild::BankEventLogEntry::WritePacket(WorldPackets::Guild:: GuildBankLogQueryResults& packet) const
{
    ObjectGuid logGuid = ObjectGuid::Create<HighGuid::Player>(m_playerGuid);

    bool hasItem = m_eventType == GUILD_BANK_LOG_DEPOSIT_ITEM || m_eventType == GUILD_BANK_LOG_WITHDRAW_ITEM ||
                   m_eventType == GUILD_BANK_LOG_MOVE_ITEM || m_eventType == GUILD_BANK_LOG_MOVE_ITEM2;

    bool itemMoved = (m_eventType == GUILD_BANK_LOG_MOVE_ITEM || m_eventType == GUILD_BANK_LOG_MOVE_ITEM2);

    bool hasStack = (hasItem && m_itemStackCount > 1) || itemMoved;

    WorldPackets::Guild::GuildBankLogEntry bankLogEntry;
    bankLogEntry.PlayerGUID = logGuid;
    bankLogEntry.TimeOffset = int32(time(nullptr) - m_timestamp);
    bankLogEntry.EntryType = int8(m_eventType);

    if (hasStack)
        bankLogEntry.Count = int32(m_itemStackCount);

    if (IsMoneyEvent())
        bankLogEntry.Money = uint64(m_itemOrMoney);

    if (hasItem)
        bankLogEntry.ItemID = int32(m_itemOrMoney);

    if (itemMoved)
        bankLogEntry.OtherTab = int8(m_destTabId);

    packet.Entry.push_back(bankLogEntry);
}

void Guild::NewsLogEntry::SaveToDB(CharacterDatabaseTransaction& trans) const
{
    uint8 index = 0;
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_NEWS);
    stmt->setUInt64(  index, m_guildId);
    stmt->setUInt32(++index, GetGUID());
    stmt->setUInt8 (++index, GetType());
    stmt->setUInt64(++index, GetPlayerGuid().GetCounter());
    stmt->setUInt32(++index, GetFlags());
    stmt->setUInt32(++index, GetValue());
    stmt->setUInt64(++index, GetTimestamp());
    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void Guild::NewsLogEntry::WritePacket(WorldPackets::Guild::GuildNews& newsPacket) const
{
    WorldPackets::Guild::GuildNewsEvent newsEvent;
    newsEvent.Id = int32(GetGUID());
    newsEvent.MemberGuid = GetPlayerGuid();
    newsEvent.CompletedDate = uint32(GetTimestamp());
    newsEvent.Flags = int32(GetFlags());
    newsEvent.Type = int32(GetType());

    //for (uint8 i = 0; i < 2; i++)
    //    newsEvent.Data[i] =

    //newsEvent.MemberList.push_back(MemberGuid);

    if (GetType() == GUILD_NEWS_ITEM_LOOTED || GetType() == GUILD_NEWS_ITEM_CRAFTED || GetType() == GUILD_NEWS_ITEM_PURCHASED)
    {
        WorldPackets::Item::ItemInstance itemInstance;
        itemInstance.ItemID = GetValue();
        newsEvent.Item = itemInstance;
    }

    newsPacket.NewsEvents.push_back(newsEvent);
}

// RankInfo
void Guild::RankInfo::LoadFromDB(Field* fields)
{
    m_rankId            = fields[1].GetUInt8();
    m_name              = fields[2].GetString();
    m_rights            = fields[3].GetUInt32();
    m_bankMoneyPerDay   = fields[4].GetUInt32();
    if (m_rankId == GR_GUILDMASTER)                     // Prevent loss of leader rights
        m_rights |= GR_RIGHT_ALL;
}

void Guild::RankInfo::SaveToDB(CharacterDatabaseTransaction& trans) const
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_RANK);
    stmt->setUInt64(0, m_guildId);
    stmt->setUInt8 (1, m_rankId);
    stmt->setString(2, m_name);
    stmt->setUInt32(3, m_rights);
    stmt->setUInt32(4, m_bankMoneyPerDay);
    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void Guild::RankInfo::CreateMissingTabsIfNeeded(uint8 tabs, CharacterDatabaseTransaction& trans, bool logOnCreate /* = false */)
{
    for (uint8 i = 0; i < tabs; ++i)
    {
        GuildBankRightsAndSlots& rightsAndSlots = m_bankTabRightsAndSlots[i];
        if (rightsAndSlots.GetTabId() == i)
            continue;

        rightsAndSlots.SetTabId(i);
        if (m_rankId == GR_GUILDMASTER)
            rightsAndSlots.SetGuildMasterValues();

        if (logOnCreate)
            TC_LOG_ERROR("guild", "Guild " UI64FMTD " has broken Tab %u for rank %u. Created default tab.", m_guildId, i, m_rankId);

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_BANK_RIGHT);
        stmt->setUInt64(0, m_guildId);
        stmt->setUInt8(1, i);
        stmt->setUInt8(2, m_rankId);
        stmt->setInt8(3,  rightsAndSlots.GetRights());
        stmt->setInt32(4, rightsAndSlots.GetSlots());
        trans->Append(stmt);
    }
}

void Guild::RankInfo::SetName(std::string const& name)
{
    if (m_name == name)
        return;

    m_name = name;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_RANK_NAME);
    stmt->setString(0, m_name);
    stmt->setUInt8 (1, m_rankId);
    stmt->setUInt64(2, m_guildId);
    CharacterDatabase.Execute(stmt);
}

void Guild::RankInfo::SetRights(uint32 rights)
{
    if (m_rankId == GR_GUILDMASTER)                     // Prevent loss of leader rights
        rights = GR_RIGHT_ALL;

    if (m_rights == rights)
        return;

    m_rights = rights;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_RANK_RIGHTS);
    stmt->setUInt32(0, m_rights);
    stmt->setUInt8 (1, m_rankId);
    stmt->setUInt64(2, m_guildId);
    CharacterDatabase.Execute(stmt);
}

void Guild::RankInfo::SetBankMoneyPerDay(uint32 money)
{
    if (m_bankMoneyPerDay == money)
        return;

    m_bankMoneyPerDay = money;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_RANK_BANK_MONEY);
    stmt->setUInt32(0, money);
    stmt->setUInt8 (1, m_rankId);
    stmt->setUInt64(2, m_guildId);
    CharacterDatabase.Execute(stmt);
}

void Guild::RankInfo::SetBankTabSlotsAndRights(GuildBankRightsAndSlots rightsAndSlots, bool saveToDB)
{
    if (m_rankId == GR_GUILDMASTER)                     // Prevent loss of leader rights
        rightsAndSlots.SetGuildMasterValues();

    GuildBankRightsAndSlots& guildBR = m_bankTabRightsAndSlots[rightsAndSlots.GetTabId()];
    guildBR = rightsAndSlots;

    if (saveToDB)
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_BANK_RIGHT);
        stmt->setUInt64(0, m_guildId);
        stmt->setUInt8 (1, guildBR.GetTabId());
        stmt->setUInt8 (2, m_rankId);
        stmt->setInt8  (3, guildBR.GetRights());
        stmt->setInt32 (4, guildBR.GetSlots());
        CharacterDatabase.Execute(stmt);
    }
}

// BankTab
Guild::BankTab::BankTab(ObjectGuid::LowType guildId, uint8 tabId) : m_guildId(guildId), m_tabId(tabId)
{
    memset(m_items, 0, GUILD_BANK_MAX_SLOTS * sizeof(Item*));
}

void Guild::BankTab::LoadFromDB(Field* fields)
{
    m_name = fields[2].GetString();
    m_icon = fields[3].GetString();
    m_text = fields[4].GetString();
}

bool Guild::BankTab::LoadItemFromDB(Field* fields)
{
    uint8 slotId = fields[45].GetUInt8();
    ObjectGuid::LowType itemGuid = fields[0].GetUInt64();
    uint32 itemEntry = fields[1].GetUInt32();
    if (slotId >= GUILD_BANK_MAX_SLOTS)
    {
        TC_LOG_ERROR("guild", "Invalid slot for item (GUID: " UI64FMTD ", id: %u) in guild bank, skipped.", itemGuid, itemEntry);
        return false;
    }

    ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemEntry);
    if (!proto)
    {
        TC_LOG_ERROR("guild", "Unknown item (GUID: " UI64FMTD ", id: %u) in guild bank, skipped.", itemGuid, itemEntry);
        return false;
    }

    Item* pItem = NewItemOrBag(proto);
    if (!pItem->LoadFromDB(itemGuid, ObjectGuid::Empty, fields, itemEntry))
    {
        TC_LOG_ERROR("guild", "Item (GUID " UI64FMTD ", id: %u) not found in item_instance, deleting from guild bank!", itemGuid, itemEntry);

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_NONEXISTENT_GUILD_BANK_ITEM);
        stmt->setUInt64(0, m_guildId);
        stmt->setUInt8 (1, m_tabId);
        stmt->setUInt8 (2, slotId);
        CharacterDatabase.Execute(stmt);

        delete pItem;
        return false;
    }

    pItem->AddToWorld();
    m_items[slotId] = pItem;
    return true;
}

// Deletes contents of the tab from the world (and from DB if necessary)
void Guild::BankTab::Delete(CharacterDatabaseTransaction& trans, bool removeItemsFromDB)
{
    for (uint8 slotId = 0; slotId < GUILD_BANK_MAX_SLOTS; ++slotId)
    {
        if (Item* item = m_items[slotId])
        {
            item->RemoveFromWorld();
            if (removeItemsFromDB)
                item->DeleteFromDB(trans);
            delete item;
            item = nullptr;
        }
    }
}

void Guild::BankTab::SetInfo(std::string const& name, std::string const& icon)
{
    if (m_name == name && m_icon == icon)
        return;

    m_name = name;
    m_icon = icon;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_BANK_TAB_INFO);
    stmt->setString(0, m_name);
    stmt->setString(1, m_icon);
    stmt->setUInt64(2, m_guildId);
    stmt->setUInt8 (3, m_tabId);
    CharacterDatabase.Execute(stmt);
}

void Guild::BankTab::SetText(std::string const& text)
{
    if (m_text == text)
        return;

    m_text = text;
    utf8truncate(m_text, MAX_GUILD_BANK_TAB_TEXT_LEN);          // DB and client size limitation

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_BANK_TAB_TEXT);
    stmt->setString(0, m_text);
    stmt->setUInt64(1, m_guildId);
    stmt->setUInt8 (2, m_tabId);
    CharacterDatabase.Execute(stmt);
}

// Sets/removes contents of specified slot.
// If pItem == nullptr contents are removed.
bool Guild::BankTab::SetItem(CharacterDatabaseTransaction& trans, uint8 slotId, Item* item)
{
    if (slotId >= GUILD_BANK_MAX_SLOTS)
        return false;

    m_items[slotId] = item;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_BANK_ITEM);
    stmt->setUInt64(0, m_guildId);
    stmt->setUInt8 (1, m_tabId);
    stmt->setUInt8 (2, slotId);
    trans->Append(stmt);

    if (item)
    {
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_BANK_ITEM);
        stmt->setUInt64(0, m_guildId);
        stmt->setUInt8 (1, m_tabId);
        stmt->setUInt8 (2, slotId);
        stmt->setUInt64(3, item->GetGUID().GetCounter());
        trans->Append(stmt);

        item->SetContainedIn(ObjectGuid::Empty);
        item->SetOwnerGUID(ObjectGuid::Empty);
        item->FSetState(ITEM_NEW);
        item->SaveToDB(trans);                                 // Not in inventory and can be saved standalone
    }

    return true;
}

void Guild::BankTab::SendText(Guild const* guild, WorldSession* session) const
{
    WorldPackets::Guild::GuildBankTextQueryResult textQuery;
    textQuery.Tab = m_tabId;
    textQuery.Text = m_text;

    if (session)
    {
        TC_LOG_DEBUG("guild", "SMSG_GUILD_BANK_QUERY_TEXT_RESULT [%s]: Tabid: %u, Text: %s"
            , session->GetPlayerInfo().c_str(), m_tabId, m_text.c_str());
        session->SendPacket(textQuery.Write());
    }
    else
    {
        TC_LOG_DEBUG("guild", "SMSG_GUILD_BANK_QUERY_TEXT_RESULT [Broadcast]: Tabid: %u, Text: %s", m_tabId, m_text.c_str());
        guild->BroadcastPacket(textQuery.Write());
    }
}

// Member
Guild::Member::Member(ObjectGuid::LowType guildId, ObjectGuid guid, uint8 rankId) :
    m_guildId(guildId),
    m_guid(guid),
    m_zoneId(0),
    m_level(0),
    m_class(0),
    _gender(0),
    m_flags(GUILDMEMBER_STATUS_NONE),
    m_logoutTime(::time(nullptr)),
    m_accountId(0),
    m_rankId(rankId),
    m_bankWithdrawMoney(0),
    m_achievementPoints(0),
    m_totalActivity(0),
    m_weekActivity(0),
    m_totalReputation(0),
    m_weekReputation(0)
{
    memset(m_bankWithdraw, 0, (GUILD_BANK_MAX_TABS) * sizeof(uint32));
}

void Guild::Member::SetStats(Player* player)
{
    m_name      = player->GetName();
    m_level     = player->getLevel();
    m_class     = player->getClass();
    _gender     = player->GetNativeSex();
    m_zoneId    = player->GetZoneId();
    m_accountId = player->GetSession()->GetAccountId();
    m_achievementPoints = player->GetAchievementPoints();
}

void Guild::Member::SetStats(std::string const& name, uint8 level, uint8 _class, uint8 gender, uint32 zoneId, uint32 accountId, uint32 reputation)
{
    m_name      = name;
    m_level     = level;
    m_class     = _class;
    _gender     = gender;
    m_zoneId    = zoneId;
    m_accountId = accountId;
    m_totalReputation = reputation;
}

void Guild::Member::SetPublicNote(std::string const& publicNote)
{
    if (m_publicNote == publicNote)
        return;

    m_publicNote = publicNote;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_MEMBER_PNOTE);
    stmt->setString(0, publicNote);
    stmt->setUInt64(1, m_guid.GetCounter());
    CharacterDatabase.Execute(stmt);
}

void Guild::Member::SetOfficerNote(std::string const& officerNote)
{
    if (m_officerNote == officerNote)
        return;

    m_officerNote = officerNote;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_MEMBER_OFFNOTE);
    stmt->setString(0, officerNote);
    stmt->setUInt64(1, m_guid.GetCounter());
    CharacterDatabase.Execute(stmt);
}

void Guild::Member::ChangeRank(CharacterDatabaseTransaction& trans, uint8 newRank)
{
    m_rankId = newRank;

    // Update rank information in player's field, if he is online.
    if (Player* player = FindConnectedPlayer())
        player->SetGuildRank(newRank);

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_MEMBER_RANK);
    stmt->setUInt8 (0, newRank);
    stmt->setUInt64(1, m_guid.GetCounter());
    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void Guild::Member::SaveToDB(CharacterDatabaseTransaction& trans) const
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_MEMBER);
    stmt->setUInt64(0, m_guildId);
    stmt->setUInt64(1, m_guid.GetCounter());
    stmt->setUInt8 (2, m_rankId);
    stmt->setString(3, m_publicNote);
    stmt->setString(4, m_officerNote);
    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

// Loads member's data from database.
// If member has broken fields (level, class) returns false.
// In this case member has to be removed from guild.
bool Guild::Member::LoadFromDB(Field* fields)
{
    m_publicNote  = fields[3].GetString();
    m_officerNote = fields[4].GetString();

    for (uint8 i = 0; i < GUILD_BANK_MAX_TABS; ++i)
        m_bankWithdraw[i] = fields[5 + i].GetUInt32();

    m_bankWithdrawMoney = fields[13].GetUInt64();

    SetStats(fields[14].GetString(),
             fields[15].GetUInt8(),                         // characters.level
             fields[16].GetUInt8(),                         // characters.class
             fields[17].GetUInt8(),                         // characters.gender
             fields[18].GetUInt16(),                        // characters.zone
             fields[19].GetUInt32(),                        // characters.account
             0);
    m_logoutTime = fields[20].GetUInt32();                  // characters.logout_time
    m_totalActivity = 0;
    m_weekActivity = 0;
    m_weekReputation = 0;

    if (!CheckStats())
        return false;

    if (!m_zoneId)
    {
        TC_LOG_DEBUG("guild", "%s has broken zone-data", m_guid.ToString().c_str());
        m_zoneId = Player::GetZoneIdFromDB(m_guid);
    }

    ResetFlags();
    return true;
}

// Validate player fields. Returns false if corrupted fields are found.
bool Guild::Member::CheckStats() const
{
    if (m_level < 1)
    {
        TC_LOG_ERROR("guild", "%s has a broken data in field `characters`.`level`, deleting him from guild!", m_guid.ToString().c_str());
        return false;
    }

    if (m_class < CLASS_WARRIOR || m_class >= MAX_CLASSES)
    {
        TC_LOG_ERROR("guild", "%s has a broken data in field `characters`.`class`, deleting him from guild!", m_guid.ToString().c_str());
        return false;
    }
    return true;
}

float Guild::Member::GetInactiveDays() const
{
    if (IsOnline())
        return 0.0f;
    return float(::time(nullptr) - GetLogoutTime()) / float(DAY);
}

// Decreases amount of slots left for today.
void Guild::Member::UpdateBankTabWithdrawValue(CharacterDatabaseTransaction& trans, uint8 tabId, uint32 amount)
{
    m_bankWithdraw[tabId] += amount;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_MEMBER_WITHDRAW_TABS);
    stmt->setUInt64(0, m_guid.GetCounter());
    for (uint8 i = 0; i < GUILD_BANK_MAX_TABS;)
    {
        uint32 withdraw = m_bankWithdraw[i++];
        stmt->setUInt32(i, withdraw);
    }

    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

// Decreases amount of money left for today.
void Guild::Member::UpdateBankMoneyWithdrawValue(CharacterDatabaseTransaction& trans, uint64 amount)
{
    m_bankWithdrawMoney += amount;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_MEMBER_WITHDRAW_MONEY);
    stmt->setUInt64(0, m_guid.GetCounter());
    stmt->setUInt64(1, m_bankWithdrawMoney);
    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void Guild::Member::ResetValues(bool weekly /* = false*/)
{
    for (uint8 tabId = 0; tabId < GUILD_BANK_MAX_TABS; ++tabId)
        m_bankWithdraw[tabId] = 0;

    m_bankWithdrawMoney = 0;

    if (weekly)
    {
        m_weekActivity = 0;
        m_weekReputation = 0;
    }
}

Player* Guild::Member::FindPlayer() const
{
    return ObjectAccessor::FindPlayer(m_guid);
}

Player* Guild::Member::FindConnectedPlayer() const
{
    return ObjectAccessor::FindConnectedPlayer(m_guid);
}

// EmblemInfo
void EmblemInfo::ReadPacket(WorldPackets::Guild::SaveGuildEmblem& packet)
{
    m_style = packet.EStyle;
    m_color = packet.EColor;
    m_borderStyle = packet.BStyle;
    m_borderColor = packet.BColor;
    m_backgroundColor = packet.Bg;
}

bool EmblemInfo::ValidateEmblemColors() const
{
    return sGuildColorBackgroundStore.LookupEntry(m_backgroundColor) &&
           sGuildColorBorderStore.LookupEntry(m_borderColor) &&
           sGuildColorEmblemStore.LookupEntry(m_color);

}

bool EmblemInfo::LoadFromDB(Field* fields)
{
    m_style             = fields[3].GetUInt8();
    m_color             = fields[4].GetUInt8();
    m_borderStyle       = fields[5].GetUInt8();
    m_borderColor       = fields[6].GetUInt8();
    m_backgroundColor   = fields[7].GetUInt8();

    return ValidateEmblemColors();
}

void EmblemInfo::SaveToDB(ObjectGuid::LowType guildId) const
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_EMBLEM_INFO);
    stmt->setUInt32(0, m_style);
    stmt->setUInt32(1, m_color);
    stmt->setUInt32(2, m_borderStyle);
    stmt->setUInt32(3, m_borderColor);
    stmt->setUInt32(4, m_backgroundColor);
    stmt->setUInt64(5, guildId);
    CharacterDatabase.Execute(stmt);
}

// MoveItemData
Guild::MoveItemData::MoveItemData(Guild* guild, Player* player, uint8 container, uint8 slotId) : m_pGuild(guild), m_pPlayer(player),
m_container(container), m_slotId(slotId), m_pItem(nullptr), m_pClonedItem(nullptr)
{
}

Guild::MoveItemData::~MoveItemData()
{
}

bool Guild::MoveItemData::CheckItem(uint32& splitedAmount)
{
    ASSERT(m_pItem);
    if (splitedAmount > m_pItem->GetCount())
        return false;
    if (splitedAmount == m_pItem->GetCount())
        splitedAmount = 0;
    return true;
}

bool Guild::MoveItemData::CanStore(Item* pItem, bool swap, bool sendError)
{
    m_vec.clear();
    InventoryResult msg = CanStore(pItem, swap);
    if (sendError && msg != EQUIP_ERR_OK)
        m_pPlayer->SendEquipError(msg, pItem);
    return (msg == EQUIP_ERR_OK);
}

bool Guild::MoveItemData::CloneItem(uint32 count)
{
    ASSERT(m_pItem);
    m_pClonedItem = m_pItem->CloneItem(count);
    if (!m_pClonedItem)
    {
        m_pPlayer->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, m_pItem);
        return false;
    }
    return true;
}

void Guild::MoveItemData::LogAction(MoveItemData* pFrom) const
{
    ASSERT(pFrom->GetItem());

    sScriptMgr->OnGuildItemMove(m_pGuild, m_pPlayer, pFrom->GetItem(),
        pFrom->IsBank(), pFrom->GetContainer(), pFrom->GetSlotId(),
        IsBank(), GetContainer(), GetSlotId());
}

inline void Guild::MoveItemData::CopySlots(SlotIds& ids) const
{
    for (auto itr = m_vec.begin(); itr != m_vec.end(); ++itr)
        ids.insert(uint8(itr->pos));
}

// PlayerMoveItemData
bool Guild::PlayerMoveItemData::InitItem()
{
    m_pItem = m_pPlayer->GetItemByPos(m_container, m_slotId);
    if (m_pItem)
    {
        // Anti-WPE protection. Do not move non-empty bags to bank.
        if (m_pItem->IsNotEmptyBag())
        {
            m_pPlayer->SendEquipError(EQUIP_ERR_DESTROY_NONEMPTY_BAG, m_pItem);
            m_pItem = nullptr;
        }
        // Bound items cannot be put into bank.
        else if (!m_pItem->CanBeTraded())
        {
            m_pPlayer->SendEquipError(EQUIP_ERR_CANT_SWAP, m_pItem);
            m_pItem = nullptr;
        }
    }
    return (m_pItem != nullptr);
}

void Guild::PlayerMoveItemData::RemoveItem(CharacterDatabaseTransaction& trans, MoveItemData* /*pOther*/, uint32 splitedAmount)
{
    if (splitedAmount)
    {
        m_pItem->SetCount(m_pItem->GetCount() - splitedAmount);
        m_pItem->SetState(ITEM_CHANGED, m_pPlayer);
        m_pPlayer->SaveInventoryAndGoldToDB(trans);
    }
    else
    {
        m_pPlayer->MoveItemFromInventory(m_container, m_slotId, true);
        m_pItem->DeleteFromInventoryDB(trans);
        m_pItem = nullptr;
    }
}

Item* Guild::PlayerMoveItemData::StoreItem(CharacterDatabaseTransaction& trans, Item* pItem)
{
    ASSERT(pItem);
    m_pPlayer->MoveItemToInventory(m_vec, pItem, true);
    m_pPlayer->SaveInventoryAndGoldToDB(trans);
    return pItem;
}

void Guild::PlayerMoveItemData::LogBankEvent(CharacterDatabaseTransaction& trans, MoveItemData* pFrom, uint32 count) const
{
    ASSERT(pFrom);
    // Bank -> Char
    m_pGuild->_LogBankEvent(trans, GUILD_BANK_LOG_WITHDRAW_ITEM, pFrom->GetContainer(), m_pPlayer->GetGUID().GetCounter(),
        pFrom->GetItem()->GetEntry(), count);
}

inline InventoryResult Guild::PlayerMoveItemData::CanStore(Item* pItem, bool swap)
{
    return m_pPlayer->CanStoreItem(m_container, m_slotId, m_vec, pItem, swap);
}

// BankMoveItemData
bool Guild::BankMoveItemData::InitItem()
{
    m_pItem = m_pGuild->_GetItem(m_container, m_slotId);
    return (m_pItem != nullptr);
}

bool Guild::BankMoveItemData::HasStoreRights(MoveItemData* pOther) const
{
    ASSERT(pOther);
    // Do not check rights if item is being swapped within the same bank tab
    if (pOther->IsBank() && pOther->GetContainer() == m_container)
        return true;
    return m_pGuild->_MemberHasTabRights(m_pPlayer->GetGUID(), m_container, GUILD_BANK_RIGHT_DEPOSIT_ITEM);
}

bool Guild::BankMoveItemData::HasWithdrawRights(MoveItemData* pOther) const
{
    ASSERT(pOther);
    // Do not check rights if item is being swapped within the same bank tab
    if (pOther->IsBank() && pOther->GetContainer() == m_container)
        return true;

    int32 slots = 0;
    if (Member const* member = m_pGuild->GetMember(m_pPlayer->GetGUID()))
        slots = m_pGuild->_GetMemberRemainingSlots(member, m_container);

    return slots != 0;
}

void Guild::BankMoveItemData::RemoveItem(CharacterDatabaseTransaction& trans, MoveItemData* pOther, uint32 splitedAmount)
{
    ASSERT(m_pItem);
    if (splitedAmount)
    {
        m_pItem->SetCount(m_pItem->GetCount() - splitedAmount);
        m_pItem->FSetState(ITEM_CHANGED);
        m_pItem->SaveToDB(trans);
    }
    else
    {
        m_pGuild->_RemoveItem(trans, m_container, m_slotId);
        m_pItem = nullptr;
    }
    // Decrease amount of player's remaining items (if item is moved to different tab or to player)
    if (!pOther->IsBank() || pOther->GetContainer() != m_container)
        m_pGuild->_UpdateMemberWithdrawSlots(trans, m_pPlayer->GetGUID(), m_container);
}

Item* Guild::BankMoveItemData::StoreItem(CharacterDatabaseTransaction& trans, Item* pItem)
{
    if (!pItem)
        return nullptr;

    BankTab* pTab = m_pGuild->GetBankTab(m_container);
    if (!pTab)
        return nullptr;

    Item* pLastItem = pItem;
    for (auto itr = m_vec.begin(); itr != m_vec.end(); )
    {
        ItemPosCount pos(*itr);
        ++itr;

        TC_LOG_DEBUG("guild", "GUILD STORAGE: StoreItem tab = %u, slot = %u, item = %u, count = %u",
            m_container, m_slotId, pItem->GetEntry(), pItem->GetCount());
        pLastItem = _StoreItem(trans, pTab, pItem, pos, itr != m_vec.end());
    }
    return pLastItem;
}

void Guild::BankMoveItemData::LogBankEvent(CharacterDatabaseTransaction& trans, MoveItemData* pFrom, uint32 count) const
{
    ASSERT(pFrom->GetItem());
    if (pFrom->IsBank())
        // Bank -> Bank
        m_pGuild->_LogBankEvent(trans, GUILD_BANK_LOG_MOVE_ITEM, pFrom->GetContainer(), m_pPlayer->GetGUID().GetCounter(),
            pFrom->GetItem()->GetEntry(), count, m_container);
    else
        // Char -> Bank
        m_pGuild->_LogBankEvent(trans, GUILD_BANK_LOG_DEPOSIT_ITEM, m_container, m_pPlayer->GetGUID().GetCounter(),
            pFrom->GetItem()->GetEntry(), count);
}

void Guild::BankMoveItemData::LogAction(MoveItemData* pFrom) const
{
    MoveItemData::LogAction(pFrom);
    if (!pFrom->IsBank() && m_pPlayer->GetSession()->HasPermission(rbac::RBAC_PERM_LOG_GM_TRADE)) /// @todo Move this to scripts
    {
        sLog->outCommand(m_pPlayer->GetSession()->GetAccountId(),
            "GM %s (%s) (Account: %u) deposit item: %s (Entry: %d Count: %u) to guild bank named: %s (Guild ID: " UI64FMTD ")",
            m_pPlayer->GetName().c_str(), m_pPlayer->GetGUID().ToString().c_str(), m_pPlayer->GetSession()->GetAccountId(),
            pFrom->GetItem()->GetTemplate()->GetDefaultLocaleName(), pFrom->GetItem()->GetEntry(), pFrom->GetItem()->GetCount(),
            m_pGuild->GetName().c_str(), m_pGuild->GetId());
    }
}

Item* Guild::BankMoveItemData::_StoreItem(CharacterDatabaseTransaction& trans, BankTab* pTab, Item* pItem, ItemPosCount& pos, bool clone) const
{
    uint8 slotId = uint8(pos.pos);
    uint32 count = pos.count;
    if (Item* pItemDest = pTab->GetItem(slotId))
    {
        pItemDest->SetCount(pItemDest->GetCount() + count);
        pItemDest->FSetState(ITEM_CHANGED);
        pItemDest->SaveToDB(trans);
        if (!clone)
        {
            pItem->RemoveFromWorld();
            pItem->DeleteFromDB(trans);
            delete pItem;
        }
        return pItemDest;
    }

    if (clone)
        pItem = pItem->CloneItem(count);
    else
        pItem->SetCount(count);

    if (pItem && pTab->SetItem(trans, slotId, pItem))
        return pItem;

    return nullptr;
}

// Tries to reserve space for source item.
// If item in destination slot exists it must be the item of the same entry
// and stack must have enough space to take at least one item.
// Returns false if destination item specified and it cannot be used to reserve space.
bool Guild::BankMoveItemData::_ReserveSpace(uint8 slotId, Item* pItem, Item* pItemDest, uint32& count)
{
    uint32 requiredSpace = pItem->GetMaxStackCount();
    if (pItemDest)
    {
        // Make sure source and destination items match and destination item has space for more stacks.
        if (pItemDest->GetEntry() != pItem->GetEntry() || pItemDest->GetCount() >= pItem->GetMaxStackCount())
            return false;
        requiredSpace -= pItemDest->GetCount();
    }
    // Let's not be greedy, reserve only required space
    requiredSpace = std::min(requiredSpace, count);

    // Reserve space
    ItemPosCount pos(slotId, requiredSpace);
    if (!pos.isContainedIn(m_vec))
    {
        m_vec.push_back(pos);
        count -= requiredSpace;
    }
    return true;
}

void Guild::BankMoveItemData::CanStoreItemInTab(Item* pItem, uint8 skipSlotId, bool merge, uint32& count)
{
    for (uint8 slotId = 0; (slotId < GUILD_BANK_MAX_SLOTS) && (count > 0); ++slotId)
    {
        // Skip slot already processed in CanStore (when destination slot was specified)
        if (slotId == skipSlotId)
            continue;

        Item* pItemDest = m_pGuild->_GetItem(m_container, slotId);
        if (pItemDest == pItem)
            pItemDest = nullptr;

        // If merge skip empty, if not merge skip non-empty
        if ((pItemDest != nullptr) != merge)
            continue;

        _ReserveSpace(slotId, pItem, pItemDest, count);
    }
}

InventoryResult Guild::BankMoveItemData::CanStore(Item* pItem, bool swap)
{
    TC_LOG_DEBUG("guild", "GUILD STORAGE: CanStore() tab = %u, slot = %u, item = %u, count = %u",
        m_container, m_slotId, pItem->GetEntry(), pItem->GetCount());

    uint32 count = pItem->GetCount();
    // Soulbound items cannot be moved
    if (pItem->IsSoulBound())
        return EQUIP_ERR_DROP_BOUND_ITEM;

    // Make sure destination bank tab exists
    if (m_container >= m_pGuild->_GetPurchasedTabsSize())
        return EQUIP_ERR_WRONG_BAG_TYPE;

    // Slot explicitely specified. Check it.
    if (m_slotId != NULL_SLOT)
    {
        Item* pItemDest = m_pGuild->_GetItem(m_container, m_slotId);
        // Ignore swapped item (this slot will be empty after move)
        if ((pItemDest == pItem) || swap)
            pItemDest = nullptr;

        if (!_ReserveSpace(m_slotId, pItem, pItemDest, count))
            return EQUIP_ERR_CANT_STACK;

        if (count == 0)
            return EQUIP_ERR_OK;
    }

    // Slot was not specified or it has not enough space for all the items in stack
    // Search for stacks to merge with
    if (pItem->GetMaxStackCount() > 1)
    {
        CanStoreItemInTab(pItem, m_slotId, true, count);
        if (count == 0)
            return EQUIP_ERR_OK;
    }

    // Search free slot for item
    CanStoreItemInTab(pItem, m_slotId, false, count);
    if (count == 0)
        return EQUIP_ERR_OK;

    return EQUIP_ERR_BANK_FULL;
}

// Guild
Guild::Guild():
    m_id(UI64LIT(0)),
    m_leaderGuid(),
    m_createdDate(0),
    m_accountsNumber(0),
    m_bankMoney(0),
    m_eventLog(nullptr),
    m_newsLog(nullptr),
    m_achievementMgr(this)
{
    memset(&m_bankEventLog, 0, (GUILD_BANK_MAX_TABS + 1) * sizeof(LogHolder*));
}

Guild::~Guild()
{
    CharacterDatabaseTransaction temp(nullptr);
    _DeleteBankItems(temp);

    // Cleanup
    delete m_eventLog;
    m_eventLog = nullptr;
    delete m_newsLog;
    m_newsLog = nullptr;

    for (uint8 tabId = 0; tabId <= GUILD_BANK_MAX_TABS; ++tabId)
    {
        delete m_bankEventLog[tabId];
        m_bankEventLog[tabId] = nullptr;
    }

    for (auto itr = m_members.begin(); itr != m_members.end(); ++itr)
    {
        delete itr->second;
        itr->second = nullptr;
    }
}

// Creates new guild with default data and saves it to database.
bool Guild::Create(Player* pLeader, std::string const& name)
{
    // Check if guild with such name already exists
    if (sGuildMgr->GetGuildByName(name))
        return false;

    WorldSession* pLeaderSession = pLeader->GetSession();
    if (!pLeaderSession)
        return false;

    m_id = sGuildMgr->GenerateGuildId();
    m_leaderGuid = pLeader->GetGUID();
    m_name = name;
    m_info = "";
    m_motd = "No message set.";
    m_bankMoney = 0;
    m_createdDate = ::time(nullptr);
    _CreateLogHolders();

    TC_LOG_DEBUG("guild", "GUILD: creating guild [%s] for leader %s (%s)",
        name.c_str(), pLeader->GetName().c_str(), m_leaderGuid.ToString().c_str());

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_MEMBERS);
    stmt->setUInt64(0, m_id);
    trans->Append(stmt);

    uint8 index = 0;
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD);
    stmt->setUInt64(  index, m_id);
    stmt->setString(++index, name);
    stmt->setUInt64(++index, m_leaderGuid.GetCounter());
    stmt->setString(++index, m_info);
    stmt->setString(++index, m_motd);
    stmt->setUInt64(++index, uint32(m_createdDate));
    stmt->setUInt32(++index, m_emblemInfo.GetStyle());
    stmt->setUInt32(++index, m_emblemInfo.GetColor());
    stmt->setUInt32(++index, m_emblemInfo.GetBorderStyle());
    stmt->setUInt32(++index, m_emblemInfo.GetBorderColor());
    stmt->setUInt32(++index, m_emblemInfo.GetBackgroundColor());
    stmt->setUInt64(++index, m_bankMoney);
    trans->Append(stmt);

    _CreateDefaultGuildRanks(trans, pLeaderSession->GetSessionDbLocaleIndex()); // Create default ranks
    bool ret = AddMember(trans, m_leaderGuid, GR_GUILDMASTER);                  // Add guildmaster

    CharacterDatabase.CommitTransaction(trans);

    if (ret)
    {
        Member* leader = GetMember(m_leaderGuid);
        if (leader)
            SendEventNewLeader(leader, nullptr);

        sScriptMgr->OnGuildCreate(this, pLeader, name);
    }

    return ret;
}

// Disbands guild and deletes all related data from database
void Guild::Disband()
{
    // Call scripts before guild data removed from database
    sScriptMgr->OnGuildDisband(this);

    WorldPackets::Guild::GuildEventDisbanded packet;
    BroadcastPacket(packet.Write());

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    // Remove all members
    while (!m_members.empty())
    {
        auto itr = m_members.begin();
        DeleteMember(trans, itr->second->GetGUID(), true);
    }

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD);
    stmt->setUInt64(0, m_id);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_RANKS);
    stmt->setUInt64(0, m_id);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_BANK_TABS);
    stmt->setUInt64(0, m_id);
    trans->Append(stmt);

    // Free bank tab used memory and delete items stored in them
    _DeleteBankItems(trans, true);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_BANK_ITEMS);
    stmt->setUInt64(0, m_id);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_BANK_RIGHTS);
    stmt->setUInt64(0, m_id);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_BANK_EVENTLOGS);
    stmt->setUInt64(0, m_id);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_EVENTLOGS);
    stmt->setUInt64(0, m_id);
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);

    sGuildFinderMgr->DeleteGuild(GetGUID());

    sGuildMgr->RemoveGuild(m_id);
}

void Guild::SaveToDB()
{
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    m_achievementMgr.SaveToDB(trans);

    CharacterDatabase.CommitTransaction(trans);
}

void Guild::UpdateMemberData(Player* player, uint8 dataid, uint32 value)
{
    if (Member* member = GetMember(player->GetGUID()))
    {
        switch (dataid)
        {
            case GUILD_MEMBER_DATA_ZONEID:
                member->SetZoneId(value);
                break;
            case GUILD_MEMBER_DATA_ACHIEVEMENT_POINTS:
                member->SetAchievementPoints(value);
                break;
            case GUILD_MEMBER_DATA_LEVEL:
                member->SetLevel(value);
                break;
            default:
                TC_LOG_ERROR("guild", "Guild::UpdateMemberData: Called with incorrect DATAID %u (value %u)", dataid, value);
                return;
        }
        //HandleRoster();
    }
}

void Guild::OnPlayerStatusChange(Player* player, uint32 flag, bool state)
{
    if (Member* member = GetMember(player->GetGUID()))
    {
        if (state)
            member->AddFlag(flag);
        else member->RemFlag(flag);
    }
}

bool Guild::SetName(std::string const& name)
{
    if (m_name == name || name.empty() || name.length() > 24 || sObjectMgr->IsReservedName(name) || !ObjectMgr::IsValidCharterName(name))
        return false;

    m_name = name;
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_NAME);
    stmt->setString(0, m_name);
    stmt->setUInt64(1, GetId());
    CharacterDatabase.Execute(stmt);

    WorldPackets::Guild::GuildNameChanged guildNameChanged;
    guildNameChanged.GuildGUID = GetGUID();
    guildNameChanged.GuildName = m_name;
    BroadcastPacket(guildNameChanged.Write());

    return true;
}

void Guild::HandleRoster(WorldSession* session)
{
    WorldPackets::Guild::GuildRoster roster;

    roster.NumAccounts = int32(m_accountsNumber);
    roster.CreateDate = uint32(m_createdDate);
    roster.GuildFlags = 0;

    roster.MemberData.reserve(m_members.size());

    for (auto itr : m_members)
    {
        Member* member = itr.second;

        WorldPackets::Guild::GuildRosterMemberData memberData;

        memberData.Guid = member->GetGUID();
        memberData.RankID = int32(member->GetRankId());
        memberData.AreaID = int32(member->GetZoneId());
        memberData.PersonalAchievementPoints = int32(member->GetAchievementPoints());
        memberData.GuildReputation = int32(member->GetTotalReputation());
        memberData.LastSave = member->GetInactiveDays();

        //GuildRosterProfessionData

        memberData.VirtualRealmAddress = GetVirtualRealmAddress();
        memberData.Status = member->GetFlags();
        memberData.Level = member->GetLevel();
        memberData.ClassID = member->GetClass();
        memberData.Gender = member->GetGender();

        memberData.Authenticated = false;
        memberData.SorEligible = false;

        memberData.Name = member->GetName();
        memberData.Note = member->GetPublicNote();
        memberData.OfficerNote = member->GetOfficerNote();

        roster.MemberData.push_back(memberData);
    }

    roster.WelcomeText = m_motd;
    roster.InfoText = m_info;

    TC_LOG_DEBUG("guild", "SMSG_GUILD_ROSTER [%s]", session->GetPlayerInfo().c_str());
    session->SendPacket(roster.Write());
}

void Guild::SendQueryResponse(WorldSession* session, ObjectGuid const& playerGuid)
{
    WorldPackets::Guild::QueryGuildInfoResponse response;
    response.GuildGuid = GetGUID();
    response.PlayerGuid = playerGuid;
    response.Info = boost::in_place();

    response.Info->GuildGUID = GetGUID();
    response.Info->VirtualRealmAddress = GetVirtualRealmAddress();

    response.Info->EmblemStyle = m_emblemInfo.GetStyle();
    response.Info->EmblemColor = m_emblemInfo.GetColor();
    response.Info->BorderStyle = m_emblemInfo.GetBorderStyle();
    response.Info->BorderColor = m_emblemInfo.GetBorderColor();
    response.Info->BackgroundColor = m_emblemInfo.GetBackgroundColor();

    for (uint8 i = 0; i < _GetRanksSize(); ++i)
    {
        WorldPackets::Guild::QueryGuildInfoResponse::GuildInfo::GuildInfoRank info
            (m_ranks[i].GetId(), i, m_ranks[i].GetName());
        response.Info->Ranks.insert(info);
    }

    response.Info->GuildName = m_name;

    session->SendPacket(response.Write());
    TC_LOG_DEBUG("guild", "SMSG_GUILD_QUERY_RESPONSE [%s]", session->GetPlayerInfo().c_str());
}

void Guild::SendGuildRankInfo(WorldSession* session) const
{
    WorldPackets::Guild::GuildRanks ranks;

    ranks.Ranks.reserve(_GetRanksSize());

    for (uint8 i = 0; i < _GetRanksSize(); i++)
    {
        RankInfo const* rankInfo = GetRankInfo(i);
        if (!rankInfo)
            continue;

        WorldPackets::Guild::GuildRankData rankData;

        rankData.RankID = rankInfo->GetId();
        rankData.RankOrder = uint32(i);
        rankData.Flags = rankInfo->GetRights();
        rankData.WithdrawGoldLimit = (rankInfo->GetId() == GR_GUILDMASTER ? (-1) : int32(rankInfo->GetBankMoneyPerDay() / GOLD));
        rankData.RankName = rankInfo->GetName();

        for (uint8 j = 0; j < GUILD_BANK_MAX_TABS; ++j)
        {
            rankData.TabFlags[j] = uint32(rankInfo->GetBankTabRights(j));
            rankData.TabWithdrawItemLimit[j] = uint32(rankInfo->GetBankTabSlotsPerDay(j));
        }

        ranks.Ranks.push_back(rankData);
    }

    session->SendPacket(ranks.Write());
    TC_LOG_DEBUG("guild", "SMSG_GUILD_RANK [%s]", session->GetPlayerInfo().c_str());
}

void Guild::HandleSetAchievementTracking(WorldSession* session, uint32 const* achievementIdsBegin, uint32 const* achievementIdsEnd)
{
    Player* player = session->GetPlayer();

    if (Member* member = GetMember(player->GetGUID()))
    {
        std::set<uint32> criteriaIds;

        for (uint32 const* achievementIdItr = achievementIdsBegin; achievementIdItr != achievementIdsEnd; ++achievementIdItr)
        {
            uint32 achievementId = *achievementIdItr;
            if (AchievementEntry const* achievement = sAchievementStore.LookupEntry(achievementId))
            {
                if (!(achievement->Flags & ACHIEVEMENT_FLAG_GUILD) || m_achievementMgr.HasAchieved(achievementId))
                    continue;

                if (CriteriaTree const* tree = sCriteriaMgr->GetCriteriaTree(achievement->CriteriaTree))
                {
                    CriteriaMgr::WalkCriteriaTree(tree, [&criteriaIds](CriteriaTree const* node)
                    {
                        if (node->Criteria)
                            criteriaIds.insert(node->Criteria->ID);
                    });
                }
            }
        }

        member->SetTrackedCriteriaIds(std::move(criteriaIds));
        m_achievementMgr.SendAllTrackedCriterias(player, member->GetTrackedCriteriaIds());
    }
}

void Guild::HandleGetAchievementMembers(WorldSession* session, uint32 achievementId) const
{
    m_achievementMgr.SendAchievementMembers(session->GetPlayer(), achievementId);
}

void Guild::HandleSetMOTD(WorldSession* session, std::string const& motd)
{
    if (m_motd == motd)
        return;

    // Player must have rights to set MOTD
    if (!_HasRankRight(session->GetPlayer(), GR_RIGHT_SETMOTD))
        SendCommandResult(session, GUILD_COMMAND_EDIT_MOTD, ERR_GUILD_PERMISSIONS);
    else
    {
        m_motd = motd;

        sScriptMgr->OnGuildMOTDChanged(this, motd);

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_MOTD);
        stmt->setString(0, motd);
        stmt->setUInt64(1, m_id);
        CharacterDatabase.Execute(stmt);

        SendEventMOTD(session, true);
    }
}

void Guild::HandleSetInfo(WorldSession* session, std::string const& info)
{
    if (m_info == info)
        return;

    // Player must have rights to set guild's info
    if (_HasRankRight(session->GetPlayer(), GR_RIGHT_MODIFY_GUILD_INFO))
    {
        m_info = info;

        sScriptMgr->OnGuildInfoChanged(this, info);

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_INFO);
        stmt->setString(0, info);
        stmt->setUInt64(1, m_id);
        CharacterDatabase.Execute(stmt);
    }
}

void Guild::HandleSetEmblem(WorldSession* session, EmblemInfo const& emblemInfo)
{
    Player* player = session->GetPlayer();
    if (!_IsLeader(player))
        SendSaveEmblemResult(session, ERR_GUILDEMBLEM_NOTGUILDMASTER); // "Only guild leaders can create emblems."
    else if (!player->HasEnoughMoney(uint64(EMBLEM_PRICE)))
        SendSaveEmblemResult(session, ERR_GUILDEMBLEM_NOTENOUGHMONEY); // "You can't afford to do that."
    else
    {
        player->ModifyMoney(-int64(EMBLEM_PRICE));

        m_emblemInfo = emblemInfo;
        m_emblemInfo.SaveToDB(m_id);

        SendSaveEmblemResult(session, ERR_GUILDEMBLEM_SUCCESS); // "Guild Emblem saved."

        SendQueryResponse(session, ObjectGuid::Empty);
    }
}

void Guild::HandleSetNewGuildMaster(WorldSession* session, std::string const& name, bool isSelfPromote)
{
    Player* player = session->GetPlayer();

    Member* oldGuildMaster = GetMember(GetLeaderGUID());
    ASSERT(oldGuildMaster);

    Member* newGuildMaster;

    if (isSelfPromote)
    {
        newGuildMaster = GetMember(player->GetGUID());
        if (!newGuildMaster)
            return;

        if (!newGuildMaster->IsRankNotLower(GR_MEMBER) || uint32(oldGuildMaster->GetInactiveDays()) < GUILD_MASTER_DETHRONE_INACTIVE_DAYS)
        {
            SendCommandResult(session, GUILD_COMMAND_CHANGE_LEADER, ERR_GUILD_PERMISSIONS);
            return;
        }
    }
    else
    {
        if (!_IsLeader(player))
        {
            SendCommandResult(session, GUILD_COMMAND_CHANGE_LEADER, ERR_GUILD_PERMISSIONS);
            return;
        }

        newGuildMaster = GetMember(name);
        if (!newGuildMaster)
            return;
    }

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    _SetLeader(trans, newGuildMaster);
    oldGuildMaster->ChangeRank(trans, GR_INITIATE);

    SendEventNewLeader(newGuildMaster, oldGuildMaster, isSelfPromote);

    CharacterDatabase.CommitTransaction(trans);
}

void Guild::HandleSetBankTabInfo(WorldSession* session, uint8 tabId, std::string const& name, std::string const& icon)
{
    BankTab* tab = GetBankTab(tabId);
    if (!tab)
    {
        TC_LOG_ERROR("guild", "Guild::HandleSetBankTabInfo: Player %s trying to change bank tab info from unexisting tab %d.",
                       session->GetPlayerInfo().c_str(), tabId);
        return;
    }

    tab->SetInfo(name, icon);

    WorldPackets::Guild::GuildEventTabModified packet;
    packet.Tab = tabId;
    packet.Name = name;
    packet.Icon = icon;
    BroadcastPacket(packet.Write());
}

void Guild::HandleSetMemberNote(WorldSession* session, std::string const& note, ObjectGuid guid, bool isPublic)
{
    // Player must have rights to set public/officer note
    if (!_HasRankRight(session->GetPlayer(), isPublic ? GR_RIGHT_EDIT_PUBLIC_NOTE : GR_RIGHT_EOFFNOTE))
        SendCommandResult(session, GUILD_COMMAND_EDIT_PUBLIC_NOTE, ERR_GUILD_PERMISSIONS);
    else if (Member* member = GetMember(guid))
    {
        if (isPublic)
            member->SetPublicNote(note);
        else
            member->SetOfficerNote(note);

        WorldPackets::Guild::GuildMemberUpdateNote updateNote;
        updateNote.Member = guid;
        updateNote.IsPublic = isPublic;
        updateNote.Note = note;
        BroadcastPacket(updateNote.Write());
    }
}

void Guild::HandleSetRankInfo(WorldSession* session, uint8 rankId, std::string const& name, uint32 rights, uint32 moneyPerDay, GuildBankRightsAndSlotsVec const& rightsAndSlots)
{
    // Only leader can modify ranks
    if (!_IsLeader(session->GetPlayer()))
        SendCommandResult(session, GUILD_COMMAND_CHANGE_RANK, ERR_GUILD_PERMISSIONS);
    else if (RankInfo* rankInfo = GetRankInfo(rankId))
    {
        TC_LOG_DEBUG("guild", "Changed RankName to '%s', rights to 0x%08X", name.c_str(), rights);

        rankInfo->SetName(name);
        rankInfo->SetRights(rights);
        _SetRankBankMoneyPerDay(rankId, moneyPerDay * GOLD);

        for (auto itr = rightsAndSlots.begin(); itr != rightsAndSlots.end(); ++itr)
            _SetRankBankTabRightsAndSlots(rankId, *itr);

        WorldPackets::Guild::GuildEventRankChanged packet;
        packet.RankID = rankId;
        BroadcastPacket(packet.Write());
    }
}

void Guild::HandleBuyBankTab(WorldSession* session, uint8 tabId)
{
    Player* player = session->GetPlayer();
    if (!player)
        return;

    Member const* member = GetMember(player->GetGUID());
    if (!member)
        return;

    if (_GetPurchasedTabsSize() >= GUILD_BANK_MAX_TABS)
        return;

    if (tabId != _GetPurchasedTabsSize())
        return;

    if (tabId >= GUILD_BANK_MAX_TABS)
        return;

    // Do not get money for bank tabs that the GM bought, we had to buy them already.
    // This is just a speedup check, GetGuildBankTabPrice will return 0.
    if (tabId < GUILD_BANK_MAX_TABS - 2) // 7th tab is actually the 6th
    {
        int64 tabCost = GetGuildBankTabPrice(tabId) * GOLD;
        if (!player->HasEnoughMoney(tabCost))                   // Should not happen, this is checked by client
            return;

        player->ModifyMoney(-tabCost);
    }

    _CreateNewBankTab();

    WorldPackets::Guild::GuildEventTabAdded packet;
    BroadcastPacket(packet.Write());

    SendPermissions(session); /// Hack to force client to update permissions
}

void Guild::HandleInviteMember(WorldSession* session, std::string const& name)
{
    Player* pInvitee = ObjectAccessor::FindPlayerByName(name);
    if (!pInvitee)
    {
        SendCommandResult(session, GUILD_COMMAND_INVITE_PLAYER, ERR_GUILD_PLAYER_NOT_FOUND_S, name);
        return;
    }

    Player* player = session->GetPlayer();
    // Do not show invitations from ignored players
    if (pInvitee->GetSocial()->HasIgnore(player->GetGUID()))
        return;

    if (!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD) && pInvitee->GetTeam() != player->GetTeam())
    {
        SendCommandResult(session, GUILD_COMMAND_INVITE_PLAYER, ERR_GUILD_NOT_ALLIED, name);
        return;
    }

    // Invited player cannot be in another guild
    if (pInvitee->GetGuildId())
    {
        SendCommandResult(session, GUILD_COMMAND_INVITE_PLAYER, ERR_ALREADY_IN_GUILD_S, name);
        return;
    }

    // Invited player cannot be invited
    if (pInvitee->GetGuildIdInvited())
    {
        SendCommandResult(session, GUILD_COMMAND_INVITE_PLAYER, ERR_ALREADY_INVITED_TO_GUILD_S, name);
        return;
    }

    // Inviting player must have rights to invite
    if (!_HasRankRight(player, GR_RIGHT_INVITE))
    {
        SendCommandResult(session, GUILD_COMMAND_INVITE_PLAYER, ERR_GUILD_PERMISSIONS);
        return;
    }

    SendCommandResult(session, GUILD_COMMAND_INVITE_PLAYER, ERR_GUILD_COMMAND_SUCCESS, name);

    TC_LOG_DEBUG("guild", "Player %s invited %s to join his Guild", player->GetName().c_str(), name.c_str());

    pInvitee->SetGuildIdInvited(m_id);
    _LogEvent(GUILD_EVENT_LOG_INVITE_PLAYER, player->GetGUID().GetCounter(), pInvitee->GetGUID().GetCounter());

    WorldPackets::Guild::GuildInvite invite;

    invite.InviterVirtualRealmAddress = GetVirtualRealmAddress();
    invite.GuildVirtualRealmAddress = GetVirtualRealmAddress();
    invite.GuildGUID = GetGUID();

    invite.EmblemStyle = uint32(m_emblemInfo.GetStyle());
    invite.EmblemColor = uint32(m_emblemInfo.GetColor());
    invite.BorderStyle = uint32(m_emblemInfo.GetBorderStyle());
    invite.BorderColor = uint32(m_emblemInfo.GetBorderColor());
    invite.Background = uint32(m_emblemInfo.GetBackgroundColor());
    invite.AchievementPoints = GetAchievementMgr().GetAchievementPoints();

    invite.InviterName = player->GetName();
    invite.GuildName = GetName();

    if (Guild* oldGuild = pInvitee->GetGuild())
    {
        invite.OldGuildGUID = oldGuild->GetGUID();
        invite.OldGuildName = oldGuild->GetName();
        invite.OldGuildVirtualRealmAddress = GetVirtualRealmAddress();
    }

    pInvitee->SendDirectMessage(invite.Write());
    TC_LOG_DEBUG("guild", "SMSG_GUILD_INVITE [%s]", pInvitee->GetName().c_str());
}

void Guild::HandleAcceptMember(WorldSession* session)
{
    Player* player = session->GetPlayer();
    if (!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD) &&
        player->GetTeam() != sCharacterCache->GetCharacterTeamByGuid(GetLeaderGUID()))
        return;

    CharacterDatabaseTransaction trans(nullptr);
    AddMember(trans, player->GetGUID());
}

void Guild::HandleLeaveMember(WorldSession* session)
{
    Player* player = session->GetPlayer();
    bool disband = false;

    // If leader is leaving
    if (_IsLeader(player))
    {
        if (m_members.size() > 1)
            // Leader cannot leave if he is not the last member
            SendCommandResult(session, GUILD_COMMAND_LEAVE_GUILD, ERR_GUILD_LEADER_LEAVE);
        else
        {
            // Guild is disbanded if leader leaves.
            Disband();
            disband = true;
        }
    }
    else
    {
        _LogEvent(GUILD_EVENT_LOG_LEAVE_GUILD, player->GetGUID().GetCounter());
        SendEventPlayerLeft(GetMember(player->GetGUID()));

        CharacterDatabaseTransaction trans(nullptr);
        DeleteMember(trans, player->GetGUID(), false, false);

        SendCommandResult(session, GUILD_COMMAND_LEAVE_GUILD, ERR_GUILD_COMMAND_SUCCESS, m_name);
    }

    sCalendarMgr->RemovePlayerGuildEventsAndSignups(player->GetGUID(), GetId());

    if (disband)
        delete this;
}

void Guild::HandleRemoveMember(WorldSession* session, ObjectGuid guid)
{
    Player* player = session->GetPlayer();

    // Player must have rights to remove members
    if (!_HasRankRight(player, GR_RIGHT_REMOVE))
        SendCommandResult(session, GUILD_COMMAND_REMOVE_PLAYER, ERR_GUILD_PERMISSIONS);
    else if (Member* member = GetMember(guid))
    {
        std::string name = member->GetName();

        // Guild masters cannot be removed
        if (member->IsRank(GR_GUILDMASTER))
            SendCommandResult(session, GUILD_COMMAND_REMOVE_PLAYER, ERR_GUILD_LEADER_LEAVE);
        // Do not allow to remove player with the same rank or higher
        else
        {
            Member* memberMe = GetMember(player->GetGUID());
            if (!memberMe || member->IsRankNotLower(memberMe->GetRankId()))
                SendCommandResult(session, GUILD_COMMAND_REMOVE_PLAYER, ERR_GUILD_RANK_TOO_HIGH_S, name);
            else
            {
                _LogEvent(GUILD_EVENT_LOG_UNINVITE_PLAYER, player->GetGUID().GetCounter(), guid.GetCounter());
                SendEventPlayerLeft(member, memberMe, true);

                // After call to DeleteMember pointer to member becomes invalid
                CharacterDatabaseTransaction trans(nullptr);
                DeleteMember(trans, guid, false, true);

                SendCommandResult(session, GUILD_COMMAND_REMOVE_PLAYER, ERR_GUILD_COMMAND_SUCCESS, name);
            }
        }
    }
}

void Guild::HandleUpdateMemberRank(WorldSession* session, ObjectGuid guid, bool demote)
{
    Player* player = session->GetPlayer();
    GuildCommandType type = demote ? GUILD_COMMAND_DEMOTE_PLAYER : GUILD_COMMAND_PROMOTE_PLAYER;
    // Player must have rights to promote
    if (!_HasRankRight(player, demote ? GR_RIGHT_DEMOTE : GR_RIGHT_PROMOTE))
        SendCommandResult(session, type, ERR_GUILD_PERMISSIONS);
    // Promoted player must be a member of guild
    else if (Member* member = GetMember(guid))
    {
        std::string name = member->GetName();
        // Player cannot promote himself
        if (member->IsSamePlayer(player->GetGUID()))
        {
            SendCommandResult(session, type, ERR_GUILD_NAME_INVALID);
            return;
        }

        Member const* memberMe = GetMember(player->GetGUID());
        ASSERT(memberMe);
        uint8 rankId = memberMe->GetRankId();
        if (demote)
        {
            // Player can demote only lower rank members
            if (member->IsRankNotLower(rankId))
            {
                SendCommandResult(session, type, ERR_GUILD_RANK_TOO_HIGH_S, name);
                return;
            }
            // Lowest rank cannot be demoted
            if (member->GetRankId() >= _GetLowestRankId())
            {
                SendCommandResult(session, type, ERR_GUILD_RANK_TOO_LOW_S, name);
                return;
            }
        }
        else
        {
            // Allow to promote only to lower rank than member's rank
            // member->GetRankId() + 1 is the highest rank that current player can promote to
            if (member->IsRankNotLower(rankId + 1))
            {
                SendCommandResult(session, type, ERR_GUILD_RANK_TOO_HIGH_S, name);
                return;
            }
        }

        uint32 newRankId = member->GetRankId() + (demote ? 1 : -1);
        CharacterDatabaseTransaction trans(nullptr);
        member->ChangeRank(trans, newRankId);
        _LogEvent(demote ? GUILD_EVENT_LOG_DEMOTE_PLAYER : GUILD_EVENT_LOG_PROMOTE_PLAYER, player->GetGUID().GetCounter(), member->GetGUID().GetCounter(), newRankId);
        //_BroadcastEvent(demote ? GE_DEMOTION : GE_PROMOTION, ObjectGuid::Empty, player->GetName().c_str(), name.c_str(), _GetRankName(newRankId).c_str());
    }
}

void Guild::HandleSetMemberRank(WorldSession* session, ObjectGuid targetGuid, ObjectGuid setterGuid, uint32 rank)
{
    Player* player = session->GetPlayer();
    Member* member = GetMember(targetGuid);
    if (!member)
        return;
    GuildRankRights rights = GR_RIGHT_PROMOTE;
    GuildCommandType type = GUILD_COMMAND_PROMOTE_PLAYER;

    if (rank > member->GetRankId())
    {
        rights = GR_RIGHT_DEMOTE;
        type = GUILD_COMMAND_DEMOTE_PLAYER;
    }

    // Promoted player must be a member of guild
    if (!_HasRankRight(player, rights))
    {
        SendCommandResult(session, type, ERR_GUILD_PERMISSIONS);
        return;
    }

    // Player cannot promote himself
    if (member->IsSamePlayer(player->GetGUID()))
    {
        SendCommandResult(session, type, ERR_GUILD_NAME_INVALID);
        return;
    }

    SendGuildRanksUpdate(setterGuid, targetGuid, rank);
}

void Guild::HandleAddNewRank(WorldSession* session, std::string const& name)
{
    uint8 size = _GetRanksSize();
    if (size >= GUILD_RANKS_MAX_COUNT)
        return;

    // Only leader can add new rank
    if (_IsLeader(session->GetPlayer()))
    {
        CharacterDatabaseTransaction trans(nullptr);
        if (_CreateRank(trans, name, GR_RIGHT_GCHATLISTEN | GR_RIGHT_GCHATSPEAK))
        {
            WorldPackets::Guild::GuildEventRanksUpdated eventPacket;
            BroadcastPacket(eventPacket.Write());
        }
    }
}

void Guild::HandleRemoveRank(WorldSession* session, uint8 rankId)
{
    // Cannot remove rank if total count is minimum allowed by the client or is not leader
    if (_GetRanksSize() <= GUILD_RANKS_MIN_COUNT || rankId >= _GetRanksSize() || !_IsLeader(session->GetPlayer()))
        return;

    // Delete bank rights for rank
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_BANK_RIGHTS_FOR_RANK);
    stmt->setUInt64(0, m_id);
    stmt->setUInt8(1, rankId);
    CharacterDatabase.Execute(stmt);

    // Delete rank
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_RANK);
    stmt->setUInt64(0, m_id);
    stmt->setUInt8(1, rankId);
    CharacterDatabase.Execute(stmt);

    m_ranks.erase(m_ranks.begin() + rankId);

    WorldPackets::Guild::GuildEventRanksUpdated eventPacket;
    BroadcastPacket(eventPacket.Write());
}

void Guild::HandleMemberDepositMoney(WorldSession* session, uint64 amount, bool cashFlow /*=false*/)
{
    // guild bank cannot have more than MAX_MONEY_AMOUNT
    amount = std::min(amount, MAX_MONEY_AMOUNT - m_bankMoney);
    if (!amount)
        return;

    Player* player = session->GetPlayer();

    // Call script after validation and before money transfer.
    sScriptMgr->OnGuildMemberDepositMoney(this, player, amount);

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    _ModifyBankMoney(trans, amount, true);
    if (!cashFlow)
    {
        player->ModifyMoney(-int64(amount));
        player->SaveGoldToDB(trans);
    }

    _LogBankEvent(trans, cashFlow ? GUILD_BANK_LOG_CASH_FLOW_DEPOSIT : GUILD_BANK_LOG_DEPOSIT_MONEY, uint8(0), player->GetGUID().GetCounter(), amount);
    CharacterDatabase.CommitTransaction(trans);

    SendEventBankMoneyChanged();

    if (player->GetSession()->HasPermission(rbac::RBAC_PERM_LOG_GM_TRADE))
    {
        sLog->outCommand(player->GetSession()->GetAccountId(),
            "GM %s (Account: %u) deposit money (Amount: " UI64FMTD ") to guild bank (Guild ID " UI64FMTD ")",
            player->GetName().c_str(), player->GetSession()->GetAccountId(), amount, m_id);
    }
}

bool Guild::HandleMemberWithdrawMoney(WorldSession* session, uint64 amount, bool repair)
{
    // clamp amount to MAX_MONEY_AMOUNT, Players can't hold more than that anyway
    amount = std::min(amount, MAX_MONEY_AMOUNT);

    if (m_bankMoney < amount)                               // Not enough money in bank
        return false;

    Player* player = session->GetPlayer();

    Member* member = GetMember(player->GetGUID());
    if (!member)
        return false;

    if (!_HasRankRight(player, repair ? GR_RIGHT_WITHDRAW_REPAIR : GR_RIGHT_WITHDRAW_GOLD))
        return false;

   if (_GetMemberRemainingMoney(member) < int64(amount))   // Check if we have enough slot/money today
       return false;

    // Call script after validation and before money transfer.
    sScriptMgr->OnGuildMemberWitdrawMoney(this, player, amount, repair);

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    // Add money to player (if required)
    if (!repair)
    {
        if (!player->ModifyMoney(amount))
            return false;

        player->SaveGoldToDB(trans);
    }

    // Update remaining money amount
    member->UpdateBankMoneyWithdrawValue(trans, amount);
    // Remove money from bank
    _ModifyBankMoney(trans, amount, false);

    // Log guild bank event
    _LogBankEvent(trans, repair ? GUILD_BANK_LOG_REPAIR_MONEY : GUILD_BANK_LOG_WITHDRAW_MONEY, uint8(0), player->GetGUID().GetCounter(), amount);
    CharacterDatabase.CommitTransaction(trans);

    SendEventBankMoneyChanged();
    return true;
}

void Guild::HandleMemberLogout(WorldSession* session)
{
    Player* player = session->GetPlayer();
    if (Member* member = GetMember(player->GetGUID()))
    {
        member->SetStats(player);
        member->UpdateLogoutTime();
        member->ResetFlags();
    }

    SendEventPresenceChanged(session, false, true);
    SaveToDB();
}

void Guild::HandleDelete(WorldSession* session)
{
    // Only leader can disband guild
    if (_IsLeader(session->GetPlayer()))
    {
        Disband();
        TC_LOG_DEBUG("guild", "%s successfully deleted", GetGUID().ToString().c_str());
        delete this;
    }
}

void Guild::HandleGuildPartyRequest(WorldSession* session) const
{
    Player* player = session->GetPlayer();
    Group* group = player->GetGroup();

    // Make sure player is a member of the guild and that he is in a group.
    if (!IsMember(player->GetGUID()) || !group)
        return;

    WorldPackets::Guild::GuildPartyState partyStateResponse;
    partyStateResponse.InGuildParty = (player->GetMap()->GetOwnerGuildId(player->GetTeam()) == GetId());
    partyStateResponse.NumMembers = 0;
    partyStateResponse.NumRequired = 0;
    partyStateResponse.GuildXPEarnedMult = 0.0f;
    session->SendPacket(partyStateResponse.Write());

    TC_LOG_DEBUG("guild", "SMSG_GUILD_PARTY_STATE_RESPONSE [%s]", session->GetPlayerInfo().c_str());
}

void Guild::HandleGuildRequestChallengeUpdate(WorldSession* session) const
{
    WorldPackets::Guild::GuildChallengeUpdate updatePacket;

    for (int i = 0; i < GUILD_CHALLENGES_TYPES; ++i)
        updatePacket.CurrentCount[i] = int32(0); /// @todo current count

    for (int i = 0; i < GUILD_CHALLENGES_TYPES; ++i)
        updatePacket.MaxCount[i] = int32(GuildChallengesMaxCount[i]);

    for (int i = 0; i < GUILD_CHALLENGES_TYPES; ++i)
        updatePacket.MaxLevelGold[i] = int32(GuildChallengeMaxLevelGoldReward[i]);

    for (int i = 0; i < GUILD_CHALLENGES_TYPES; ++i)
        updatePacket.Gold[i] = int32(GuildChallengeGoldReward[i]);

    session->SendPacket(updatePacket.Write());
}

void Guild::SendEventLog(WorldSession* session) const
{
    GuildLog* logs = m_eventLog->GetGuildLog();

    if (!logs)
        return;

    WorldPackets::Guild::GuildEventLogQueryResults packet;
    packet.Entry.reserve(m_eventLog->GetSize());

    for (GuildLog::const_iterator itr = logs->begin(); itr != logs->end(); ++itr)
    {
        EventLogEntry* eventLog = static_cast<EventLogEntry*>(*itr);
        eventLog->WritePacket(packet);
    }

    session->SendPacket(packet.Write());

    TC_LOG_DEBUG("guild", "SMSG_GUILD_EVENT_LOG_QUERY_RESULTS [%s]", session->GetPlayerInfo().c_str());
}

void Guild::SendNewsUpdate(WorldSession* session) const
{
    GuildLog* logs = m_newsLog->GetGuildLog();

    if (!logs)
        return;

    WorldPackets::Guild::GuildNews packet;
    packet.NewsEvents.reserve(m_newsLog->GetSize());

    for (GuildLog::const_iterator itr = logs->begin(); itr != logs->end(); ++itr)
    {
        NewsLogEntry* eventLog = static_cast<NewsLogEntry*>(*itr);
        eventLog->WritePacket(packet);
    }

    session->SendPacket(packet.Write());

    TC_LOG_DEBUG("guild", "SMSG_GUILD_NEWS_UPDATE [%s]", session->GetPlayerInfo().c_str());
}

void Guild::SendBankLog(WorldSession* session, uint8 tabId) const
{
    // GUILD_BANK_MAX_TABS send by client for money log
    if (tabId < _GetPurchasedTabsSize() || tabId == GUILD_BANK_MAX_TABS)
    {
        GuildLog* logs = m_bankEventLog[tabId]->GetGuildLog();

        if (!logs)
            return;

        WorldPackets::Guild::GuildBankLogQueryResults packet;
        packet.Tab = int32(tabId);

        //if (tabId == GUILD_BANK_MAX_TABS && hasCashFlow)
        //    packet.WeeklyBonusMoney.Set(uint64(weeklyBonusMoney));

        packet.Entry.reserve(m_bankEventLog[tabId]->GetSize());
        for (GuildLog::const_iterator itr = logs->begin(); itr != logs->end(); ++itr)
        {
            BankEventLogEntry* bankEventLog = static_cast<BankEventLogEntry*>(*itr);
            bankEventLog->WritePacket(packet);
        }

        session->SendPacket(packet.Write());

        TC_LOG_DEBUG("guild", "SMSG_GUILD_BANK_LOG_QUERY_RESULT [%s] TabId: %u", session->GetPlayerInfo().c_str(), tabId);
    }
}

void Guild::SendBankTabText(WorldSession* session, uint8 tabId) const
{
    if (BankTab const* tab = GetBankTab(tabId))
        tab->SendText(this, session);
}

void Guild::SendPermissions(WorldSession* session) const
{
    Member const* member = GetMember(session->GetPlayer()->GetGUID());
    if (!member)
        return;

    uint8 rankId = member->GetRankId();

    WorldPackets::Guild::GuildPermissionsQueryResults queryResult;
    queryResult.RankID = rankId;
    queryResult.WithdrawGoldLimit = int32(_GetRankBankMoneyPerDay(rankId));
    queryResult.Flags = _GetRankRights(rankId);
    queryResult.NumTabs = _GetPurchasedTabsSize();
    queryResult.Tab.reserve(GUILD_BANK_MAX_TABS);

    for (uint8 tabId = 0; tabId < GUILD_BANK_MAX_TABS; ++tabId)
    {
        WorldPackets::Guild::GuildPermissionsQueryResults::GuildRankTabPermissions tabPerm;
        tabPerm.Flags = _GetRankBankTabRights(rankId, tabId);
        tabPerm.WithdrawItemLimit = _GetMemberRemainingSlots(member, tabId);
        queryResult.Tab.push_back(tabPerm);
    }

    session->SendPacket(queryResult.Write());
    TC_LOG_DEBUG("guild", "SMSG_GUILD_PERMISSIONS_QUERY_RESULTS [%s] Rank: %u", session->GetPlayerInfo().c_str(), rankId);
}

void Guild::SendMoneyInfo(WorldSession* session) const
{
    Member const* member = GetMember(session->GetPlayer()->GetGUID());
    if (!member)
        return;

    int64 amount = _GetMemberRemainingMoney(member);

    WorldPackets::Guild::GuildBankRemainingWithdrawMoney packet;
    packet.RemainingWithdrawMoney = amount;
    session->SendPacket(packet.Write());

    TC_LOG_DEBUG("guild", "SMSG_GUILD_BANK_MONEY_WITHDRAWN [%s] Money: " SI64FMTD, session->GetPlayerInfo().c_str(), amount);
}

void Guild::SendLoginInfo(WorldSession* session)
{
    Player* player = session->GetPlayer();
    Member* member = GetMember(player->GetGUID());
    if (!member)
        return;

    /*
        Login sequence:
          SMSG_GUILD_EVENT_MOTD
          SMSG_GUILD_RANK
          SMSG_GUILD_EVENT_PRESENCE_CHANGE - LoggedOn: True
          -- learn perks
          SMSG_ALL_GUILD_ACHIEVEMENTS
          SMSG_GUILD_MEMBER_DAILY_RESET // bank withdrawal reset
    */

    SendEventMOTD(session);
    SendGuildRankInfo(session);
    SendEventPresenceChanged(session, true, true);      // Broadcast

    // Send to self separately, player is not in world yet and is not found by _BroadcastEvent
    SendEventPresenceChanged(session, true);

    if (member->GetGUID() == GetLeaderGUID())
    {
        WorldPackets::Guild::GuildFlaggedForRename renameFlag;
        renameFlag.FlagSet = false;
        player->GetSession()->SendPacket(renameFlag.Write());
    }

    for (GuildPerkSpellsEntry const* entry : sGuildPerkSpellsStore)
        player->LearnSpell(entry->SpellID, true);

    m_achievementMgr.SendAllData(player);

    WorldPackets::Guild::GuildMemberDailyReset packet; // tells the client to request bank withdrawal limit
    player->GetSession()->SendPacket(packet.Write());

    member->SetStats(player);
    member->AddFlag(GUILDMEMBER_STATUS_ONLINE);
}

void Guild::SendEventAwayChanged(ObjectGuid const& memberGuid, bool afk, bool dnd)
{
    Member* member = GetMember(memberGuid);
    if (!member)
        return;

    if (afk)
        member->AddFlag(GUILDMEMBER_STATUS_AFK);
    else
        member->RemFlag(GUILDMEMBER_STATUS_AFK);

    if (dnd)
        member->AddFlag(GUILDMEMBER_STATUS_DND);
    else
        member->RemFlag(GUILDMEMBER_STATUS_DND);

    WorldPackets::Guild::GuildEventStatusChange statusChange;
    statusChange.Guid = memberGuid;
    statusChange.AFK = afk;
    statusChange.DND = dnd;
    BroadcastPacket(statusChange.Write());
}

void Guild::SendEventBankMoneyChanged() const
{
    WorldPackets::Guild::GuildEventBankMoneyChanged eventPacket;
    eventPacket.Money = GetBankMoney();
    BroadcastPacket(eventPacket.Write());
}

void Guild::SendEventMOTD(WorldSession* session, bool broadcast) const
{
    WorldPackets::Guild::GuildEventMotd eventPacket;
    eventPacket.MotdText = GetMOTD();

    if (broadcast)
        BroadcastPacket(eventPacket.Write());
    else
    {
        session->SendPacket(eventPacket.Write());
        TC_LOG_DEBUG("guild", "SMSG_GUILD_EVENT_MOTD [%s] ", session->GetPlayerInfo().c_str());
    }
}

void Guild::SendEventNewLeader(Member* newLeader, Member* oldLeader, bool isSelfPromoted) const
{
    WorldPackets::Guild::GuildEventNewLeader eventPacket;
    eventPacket.SelfPromoted = isSelfPromoted;
    if (newLeader)
    {
        eventPacket.NewLeaderGUID = newLeader->GetGUID();
        eventPacket.NewLeaderName = newLeader->GetName();
        eventPacket.NewLeaderVirtualRealmAddress = GetVirtualRealmAddress();
    }

    if (oldLeader)
    {
        eventPacket.OldLeaderGUID = oldLeader->GetGUID();
        eventPacket.OldLeaderName = oldLeader->GetName();
        eventPacket.OldLeaderVirtualRealmAddress = GetVirtualRealmAddress();
    }

    BroadcastPacket(eventPacket.Write());
}

void Guild::SendEventPlayerLeft(Member* leaver, Member* remover, bool isRemoved) const
{
    WorldPackets::Guild::GuildEventPlayerLeft eventPacket;
    eventPacket.Removed = isRemoved;
    eventPacket.LeaverGUID = leaver->GetGUID();
    eventPacket.LeaverName = leaver->GetName();
    eventPacket.LeaverVirtualRealmAddress = GetVirtualRealmAddress();

    if (isRemoved && remover != nullptr)
    {
        eventPacket.RemoverGUID = remover->GetGUID();
        eventPacket.RemoverName = remover->GetName();
        eventPacket.RemoverVirtualRealmAddress = GetVirtualRealmAddress();
    }

    BroadcastPacket(eventPacket.Write());
}

void Guild::SendEventPresenceChanged(WorldSession* session, bool loggedOn, bool broadcast) const
{
    Player* player = session->GetPlayer();

    WorldPackets::Guild::GuildEventPresenceChange eventPacket;
    eventPacket.Guid = player->GetGUID();
    eventPacket.Name = player->GetName();
    eventPacket.VirtualRealmAddress = GetVirtualRealmAddress();
    eventPacket.LoggedOn = loggedOn;
    eventPacket.Mobile = false;

    if (broadcast)
        BroadcastPacket(eventPacket.Write());
    else
        session->SendPacket(eventPacket.Write());
}

// Loading methods
bool Guild::LoadFromDB(Field* fields)
{
    m_id            = fields[0].GetUInt64();
    m_name          = fields[1].GetString();
    m_leaderGuid    = ObjectGuid::Create<HighGuid::Player>(fields[2].GetUInt64());

    if (!m_emblemInfo.LoadFromDB(fields))
    {
        TC_LOG_ERROR("guild", "Guild " UI64FMTD " has invalid emblem colors (Background: %u, Border: %u, Emblem: %u), skipped.",
            m_id, m_emblemInfo.GetBackgroundColor(), m_emblemInfo.GetBorderColor(), m_emblemInfo.GetColor());
        return false;
    }

    m_info          = fields[8].GetString();
    m_motd          = fields[9].GetString();
    m_createdDate   = time_t(fields[10].GetUInt32());
    m_bankMoney     = fields[11].GetUInt64();

    uint8 purchasedTabs = uint8(fields[12].GetUInt64());
    if (purchasedTabs > GUILD_BANK_MAX_TABS)
        purchasedTabs = GUILD_BANK_MAX_TABS;

    m_bankTabs.resize(purchasedTabs);
    for (uint8 i = 0; i < purchasedTabs; ++i)
        m_bankTabs[i] = new BankTab(m_id, i);

    _CreateLogHolders();
    return true;
}

void Guild::LoadRankFromDB(Field* fields)
{
    RankInfo rankInfo(m_id);

    rankInfo.LoadFromDB(fields);

    m_ranks.push_back(rankInfo);
}

bool Guild::LoadMemberFromDB(Field* fields)
{
    ObjectGuid::LowType lowguid = fields[1].GetUInt64();
    ObjectGuid playerGuid(ObjectGuid::Create<HighGuid::Player>(lowguid));
    Member* member = new Member(m_id, playerGuid, fields[2].GetUInt8());
    if (!member->LoadFromDB(fields))
    {
        CharacterDatabaseTransaction trans(nullptr);
        Guild::_DeleteMemberFromDB(trans, lowguid);
        delete member;
        return false;
    }

    sCharacterCache->UpdateCharacterGuildId(playerGuid, GetId());
    m_members[member->GetGUID()] = member;
    return true;
}

void Guild::LoadBankRightFromDB(Field* fields)
{
                                           // tabId              rights               slots
    GuildBankRightsAndSlots rightsAndSlots(fields[1].GetUInt8(), fields[3].GetInt8(), fields[4].GetInt32());
                                  // rankId
    _SetRankBankTabRightsAndSlots(fields[2].GetUInt8(), rightsAndSlots, false);
}

bool Guild::LoadEventLogFromDB(Field* fields) const
{
    if (m_eventLog->CanInsert())
    {
        m_eventLog->LoadEvent(new EventLogEntry(
            m_id,                                       // guild id
            fields[1].GetUInt32(),                      // guid
            time_t(fields[6].GetUInt32()),              // timestamp
            GuildEventLogTypes(fields[2].GetUInt8()),   // event type
            fields[3].GetUInt64(),                      // player guid 1
            fields[4].GetUInt64(),                      // player guid 2
            fields[5].GetUInt8()));                     // rank
        return true;
    }
    return false;
}

bool Guild::LoadBankEventLogFromDB(Field* fields)
{
    uint8 dbTabId = fields[1].GetUInt8();
    bool isMoneyTab = (dbTabId == GUILD_BANK_MONEY_LOGS_TAB);
    if (dbTabId < _GetPurchasedTabsSize() || isMoneyTab)
    {
        uint8 tabId = isMoneyTab ? uint8(GUILD_BANK_MAX_TABS) : dbTabId;
        LogHolder* pLog = m_bankEventLog[tabId];
        if (pLog->CanInsert())
        {
            uint32 guid = fields[2].GetUInt32();
            GuildBankEventLogTypes eventType = GuildBankEventLogTypes(fields[3].GetUInt8());
            if (BankEventLogEntry::IsMoneyEvent(eventType))
            {
                if (!isMoneyTab)
                {
                    TC_LOG_ERROR("guild", "GuildBankEventLog ERROR: MoneyEvent(LogGuid: %u, Guild: " UI64FMTD ") does not belong to money tab (%u), ignoring...", guid, m_id, dbTabId);
                    return false;
                }
            }
            else if (isMoneyTab)
            {
                TC_LOG_ERROR("guild", "GuildBankEventLog ERROR: non-money event (LogGuid: %u, Guild: " UI64FMTD ") belongs to money tab, ignoring...", guid, m_id);
                return false;
            }
            pLog->LoadEvent(new BankEventLogEntry(
                m_id,                                   // guild id
                guid,                                   // guid
                time_t(fields[8].GetUInt32()),          // timestamp
                dbTabId,                                // tab id
                eventType,                              // event type
                fields[4].GetUInt64(),                  // player guid
                fields[5].GetUInt64(),                  // item or money
                fields[6].GetUInt16(),                  // itam stack count
                fields[7].GetUInt8()));                 // dest tab id
        }
    }
    return true;
}

void Guild::LoadGuildNewsLogFromDB(Field* fields) const
{
    if (!m_newsLog->CanInsert())
        return;

    m_newsLog->LoadEvent(new NewsLogEntry(
    m_id,                                               // guild id
    fields[1].GetUInt32(),                              // guid
    fields[6].GetUInt32(),                              // timestamp //64 bits?
    GuildNews(fields[2].GetUInt8()),                    // type
    ObjectGuid::Create<HighGuid::Player>(fields[3].GetUInt64()), // player guid
    fields[4].GetUInt32(),                              // Flags
    fields[5].GetUInt32()));                            // value
}

void Guild::LoadBankTabFromDB(Field* fields)
{
    uint8 tabId = fields[1].GetUInt8();
    if (tabId >= _GetPurchasedTabsSize())
        TC_LOG_ERROR("guild", "Invalid tab (tabId: %u) in guild bank, skipped.", tabId);
    else
        m_bankTabs[tabId]->LoadFromDB(fields);
}

bool Guild::LoadBankItemFromDB(Field* fields)
{
    uint8 tabId = fields[44].GetUInt8();
    if (tabId >= _GetPurchasedTabsSize())
    {
        TC_LOG_ERROR("guild", "Invalid tab for item (GUID: %u, id: #%u) in guild bank, skipped.",
            fields[0].GetUInt32(), fields[1].GetUInt32());
        return false;
    }
    return m_bankTabs[tabId]->LoadItemFromDB(fields);
}

// Validates guild data loaded from database. Returns false if guild should be deleted.
bool Guild::Validate()
{
    // Validate ranks data
    // GUILD RANKS represent a sequence starting from 0 = GUILD_MASTER (ALL PRIVILEGES) to max 9 (lowest privileges).
    // The lower rank id is considered higher rank - so promotion does rank-- and demotion does rank++
    // Between ranks in sequence cannot be gaps - so 0, 1, 2, 4 is impossible
    // Min ranks count is 2 and max is 10.
    bool broken_ranks = false;
    uint8 ranks = _GetRanksSize();

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    if (ranks < GUILD_RANKS_MIN_COUNT || ranks > GUILD_RANKS_MAX_COUNT)
    {
        TC_LOG_ERROR("guild", "Guild " UI64FMTD " has invalid number of ranks, creating new...", m_id);
        broken_ranks = true;
    }
    else
    {
        for (uint8 rankId = 0; rankId < ranks; ++rankId)
        {
            RankInfo* rankInfo = GetRankInfo(rankId);
            if (rankInfo->GetId() != rankId)
            {
                TC_LOG_ERROR("guild", "Guild " UI64FMTD " has broken rank id %u, creating default set of ranks...", m_id, rankId);
                broken_ranks = true;
            }
            else
                rankInfo->CreateMissingTabsIfNeeded(_GetPurchasedTabsSize(), trans, true);
        }
    }

    if (broken_ranks)
    {
        m_ranks.clear();
        _CreateDefaultGuildRanks(trans, DEFAULT_LOCALE);
    }

    // Validate members' data
    for (auto itr = m_members.begin(); itr != m_members.end(); ++itr)
        if (itr->second->GetRankId() > _GetRanksSize())
            itr->second->ChangeRank(trans, _GetLowestRankId());

    // Repair the structure of the guild.
    // If the guildmaster doesn't exist or isn't member of the guild
    // attempt to promote another member.
    Member* leader = GetMember(m_leaderGuid);
    if (!leader)
    {
        CharacterDatabaseTransaction trans(nullptr);
        DeleteMember(trans, m_leaderGuid);
        // If no more members left, disband guild
        if (m_members.empty())
        {
            Disband();
            return false;
        }
    }
    else if (!leader->IsRank(GR_GUILDMASTER))
        _SetLeader(trans, leader);

    // Check config if multiple guildmasters are allowed
    if (!sConfigMgr->GetBoolDefault("Guild.AllowMultipleGuildMaster", false))
        for (auto itr = m_members.begin(); itr != m_members.end(); ++itr)
            if (itr->second->GetRankId() == GR_GUILDMASTER && !itr->second->IsSamePlayer(m_leaderGuid))
                itr->second->ChangeRank(trans, GR_OFFICER);

    if (trans->GetSize() > 0)
        CharacterDatabase.CommitTransaction(trans);
    _UpdateAccountsNumber();
    return true;
}

// Broadcasts
void Guild::BroadcastToGuild(WorldSession* session, bool officerOnly, std::string const& msg, uint32 language) const
{
    if (session && session->GetPlayer() && _HasRankRight(session->GetPlayer(), officerOnly ? GR_RIGHT_OFFCHATSPEAK : GR_RIGHT_GCHATSPEAK))
    {
        WorldPackets::Chat::Chat packet;
        packet.Initialize(officerOnly ? CHAT_MSG_OFFICER : CHAT_MSG_GUILD, Language(language), session->GetPlayer(), nullptr, msg);
        WorldPacket const* data = packet.Write();
        for (auto itr = m_members.begin(); itr != m_members.end(); ++itr)
            if (Player* player = itr->second->FindConnectedPlayer())
                if (player->GetSession() && _HasRankRight(player, officerOnly ? GR_RIGHT_OFFCHATLISTEN : GR_RIGHT_GCHATLISTEN) &&
                    !player->GetSocial()->HasIgnore(session->GetPlayer()->GetGUID()))
                    player->SendDirectMessage(data);
    }
}

void Guild::BroadcastAddonToGuild(WorldSession* session, bool officerOnly, std::string const& msg, std::string const& prefix, bool isLogged) const
{
    if (session && session->GetPlayer() && _HasRankRight(session->GetPlayer(), officerOnly ? GR_RIGHT_OFFCHATSPEAK : GR_RIGHT_GCHATSPEAK))
    {
        WorldPackets::Chat::Chat packet;
        packet.Initialize(officerOnly ? CHAT_MSG_OFFICER : CHAT_MSG_GUILD, isLogged ? LANG_ADDON_LOGGED : LANG_ADDON, session->GetPlayer(), nullptr, msg, 0, "", DEFAULT_LOCALE, prefix);
        WorldPacket const* data = packet.Write();
        for (Members::const_iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
            if (Player* player = itr->second->FindPlayer())
                if (player->GetSession() && _HasRankRight(player, officerOnly ? GR_RIGHT_OFFCHATLISTEN : GR_RIGHT_GCHATLISTEN) &&
                    !player->GetSocial()->HasIgnore(session->GetPlayer()->GetGUID()) &&
                    player->GetSession()->IsAddonRegistered(prefix))
                        player->SendDirectMessage(data);
    }
}

void Guild::BroadcastPacketToRank(WorldPacket const* packet, uint8 rankId) const
{
    for (auto itr = m_members.begin(); itr != m_members.end(); ++itr)
        if (itr->second->IsRank(rankId))
            if (Player* player = itr->second->FindConnectedPlayer())
                player->SendDirectMessage(packet);
}

void Guild::BroadcastPacket(WorldPacket const* packet) const
{
    for (auto itr = m_members.begin(); itr != m_members.end(); ++itr)
        if (Player* player = itr->second->FindPlayer())
            player->SendDirectMessage(packet);
}

void Guild::BroadcastPacketIfTrackingAchievement(WorldPacket const* packet, uint32 criteriaId) const
{
    for (Members::const_iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
        if (itr->second->IsTrackingCriteriaId(criteriaId))
            if (Player* player = itr->second->FindPlayer())
                player->GetSession()->SendPacket(packet);
}

void Guild::MassInviteToEvent(WorldSession* session, uint32 minLevel, uint32 maxLevel, uint32 minRank)
{
    WorldPackets::Calendar::CalendarCommunityInvite packet;

    for (auto itr = m_members.begin(); itr != m_members.end(); ++itr)
    {
        // not sure if needed, maybe client checks it as well
        if (packet.Invites.size() >= CALENDAR_MAX_INVITES)
        {
            if (Player* player = session->GetPlayer())
                sCalendarMgr->SendCalendarCommandResult(player->GetGUID(), CALENDAR_ERROR_INVITES_EXCEEDED);
            return;
        }

        Member* member = itr->second;
        uint32 level = sCharacterCache->GetCharacterLevelByGuid(member->GetGUID());

        if (member->GetGUID() != session->GetPlayer()->GetGUID() && level >= minLevel && level <= maxLevel && member->IsRankNotLower(minRank))
            packet.Invites.emplace_back(member->GetGUID(), level);
    }

    session->SendPacket(packet.Write());
}

// Members handling
bool Guild::AddMember(CharacterDatabaseTransaction& trans, ObjectGuid guid, uint8 rankId)
{
    Player* player = ObjectAccessor::FindConnectedPlayer(guid);
    // Player cannot be in guild
    if (player)
    {
        if (player->GetGuildId())
            return false;
    }
    else if (sCharacterCache->GetCharacterGuildIdByGuid(guid))
        return false;

    // Remove all player signs from another petitions
    // This will be prevent attempt to join many guilds and corrupt guild data integrity
    Player::RemovePetitionsAndSigns(guid);

    ObjectGuid::LowType lowguid = guid.GetCounter();

    // If rank was not passed, assign lowest possible rank
    if (rankId == GUILD_RANK_NONE)
        rankId = _GetLowestRankId();

    Member* member = new Member(m_id, guid, rankId);
    std::string name;
    if (player)
    {
        m_members[guid] = member;
        player->SetInGuild(m_id);
        player->SetGuildIdInvited(UI64LIT(0));
        player->SetGuildRank(rankId);
        player->SetGuildLevel(GetLevel());
        SendLoginInfo(player->GetSession());
        name = player->GetName();
    }
    else
    {
        member->ResetFlags();

        bool ok = false;
        // Player must exist
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_DATA_FOR_GUILD);
        stmt->setUInt64(0, lowguid);
        if (PreparedQueryResult result = CharacterDatabase.Query(stmt))
        {
            Field* fields = result->Fetch();
            name = fields[0].GetString();
            member->SetStats(
                name,
                fields[1].GetUInt8(),
                fields[2].GetUInt8(),
                fields[3].GetUInt8(),
                fields[4].GetUInt16(),
                fields[5].GetUInt32(),
                0);

            ok = member->CheckStats();
        }

        if (!ok)
        {
            delete member;
            return false;
        }
        m_members[guid] = member;
        sCharacterCache->UpdateCharacterGuildId(guid, GetId());
    }

    member->SaveToDB(trans);

    _UpdateAccountsNumber();
    _LogEvent(GUILD_EVENT_LOG_JOIN_GUILD, lowguid);

    WorldPackets::Guild::GuildEventPlayerJoined joinNotificationPacket;
    joinNotificationPacket.Guid = guid;
    joinNotificationPacket.Name = name;
    joinNotificationPacket.VirtualRealmAddress = GetVirtualRealmAddress();
    BroadcastPacket(joinNotificationPacket.Write());

    sGuildFinderMgr->RemoveAllMembershipRequestsFromPlayer(guid);

    // Call scripts if member was succesfully added (and stored to database)
    sScriptMgr->OnGuildAddMember(this, player, rankId);

    return true;
}

void Guild::DeleteMember(CharacterDatabaseTransaction& trans, ObjectGuid guid, bool isDisbanding, bool isKicked, bool canDeleteGuild)
{
    // Guild master can be deleted when loading guild and guid doesn't exist in characters table
    // or when he is removed from guild by gm command
    if (m_leaderGuid == guid && !isDisbanding)
    {
        Member* oldLeader = nullptr;
        Member* newLeader = nullptr;
        for (auto i = m_members.begin(); i != m_members.end(); ++i)
        {
            if (i->first == guid)
                oldLeader = i->second;
            else if (!newLeader || newLeader->GetRankId() > i->second->GetRankId())
                newLeader = i->second;
        }

        if (!newLeader)
        {
            Disband();
            if (canDeleteGuild)
                delete this;
            return;
        }

        _SetLeader(trans, newLeader);

        // If leader does not exist (at guild loading with deleted leader) do not send broadcasts
        if (oldLeader)
        {
            SendEventNewLeader(newLeader, oldLeader, true);
            SendEventPlayerLeft(oldLeader);
        }
    }
    // Call script on remove before member is actually removed from guild (and database)
    sScriptMgr->OnGuildRemoveMember(this, guid, isDisbanding, isKicked);

    if (Member* member = GetMember(guid))
        delete member;
    m_members.erase(guid);

    // If player not online data in data field will be loaded from guild tabs no need to update it !!
    Player* player = ObjectAccessor::FindConnectedPlayer(guid);
    if (player)
    {
        player->SetInGuild(UI64LIT(0));
        player->SetGuildRank(0);
        player->SetGuildLevel(0);

        for (GuildPerkSpellsEntry const* entry : sGuildPerkSpellsStore)
            player->RemoveSpell(entry->SpellID, false, false);
    }
    else
        sCharacterCache->UpdateCharacterGuildId(guid, 0);

    Guild::_DeleteMemberFromDB(trans, guid.GetCounter());
    if (!isDisbanding)
        _UpdateAccountsNumber();
}

bool Guild::ChangeMemberRank(CharacterDatabaseTransaction& trans, ObjectGuid guid, uint8 newRank)
{
    if (newRank <= _GetLowestRankId())                    // Validate rank (allow only existing ranks)
    {
        if (Member* member = GetMember(guid))
        {
            member->ChangeRank(trans, newRank);
            return true;
        }
    }

    return false;
}

bool Guild::IsMember(ObjectGuid guid) const
{
    Members::const_iterator itr = m_members.find(guid);
    return itr != m_members.end();
}

// Bank (items move)
void Guild::SwapItems(Player* player, uint8 tabId, uint8 slotId, uint8 destTabId, uint8 destSlotId, uint32 splitedAmount)
{
    if (tabId >= _GetPurchasedTabsSize() || slotId >= GUILD_BANK_MAX_SLOTS ||
        destTabId >= _GetPurchasedTabsSize() || destSlotId >= GUILD_BANK_MAX_SLOTS)
        return;

    if (tabId == destTabId && slotId == destSlotId)
        return;

    BankMoveItemData from(this, player, tabId, slotId);
    BankMoveItemData to(this, player, destTabId, destSlotId);
    _MoveItems(&from, &to, splitedAmount);
}

void Guild::SwapItemsWithInventory(Player* player, bool toChar, uint8 tabId, uint8 slotId, uint8 playerBag, uint8 playerSlotId, uint32 splitedAmount)
{
    if ((slotId >= GUILD_BANK_MAX_SLOTS && slotId != NULL_SLOT) || tabId >= _GetPurchasedTabsSize())
        return;

    BankMoveItemData bankData(this, player, tabId, slotId);
    PlayerMoveItemData charData(this, player, playerBag, playerSlotId);
    if (toChar)
        _MoveItems(&bankData, &charData, splitedAmount);
    else
        _MoveItems(&charData, &bankData, splitedAmount);
}

// Bank tabs
void Guild::SetBankTabText(uint8 tabId, std::string const& text)
{
    if (BankTab* pTab = GetBankTab(tabId))
    {
        pTab->SetText(text);
        pTab->SendText(this, nullptr);

        WorldPackets::Guild::GuildEventTabTextChanged eventPacket;
        eventPacket.Tab = tabId;
        BroadcastPacket(eventPacket.Write());
    }
}

bool Guild::_HasRankRight(Player const* player, uint32 right) const
{
    if (player)
        if (Member const* member = GetMember(player->GetGUID()))
            return (_GetRankRights(member->GetRankId()) & right) != GR_RIGHT_NONE;
    return false;
}

void Guild::_DeleteMemberFromDB(CharacterDatabaseTransaction& trans, ObjectGuid::LowType lowguid)
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_MEMBER);
    stmt->setUInt64(0, lowguid);
    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

// Private methods
void Guild::_CreateLogHolders()
{
    m_eventLog = new LogHolder(sWorld->getIntConfig(CONFIG_GUILD_EVENT_LOG_COUNT));
    m_newsLog = new LogHolder(sWorld->getIntConfig(CONFIG_GUILD_NEWS_LOG_COUNT));
    for (uint8 tabId = 0; tabId <= GUILD_BANK_MAX_TABS; ++tabId)
        m_bankEventLog[tabId] = new LogHolder(sWorld->getIntConfig(CONFIG_GUILD_BANK_EVENT_LOG_COUNT));
}

void Guild::_CreateNewBankTab()
{
    uint8 tabId = _GetPurchasedTabsSize();                      // Next free id
    m_bankTabs.push_back(new BankTab(m_id, tabId));

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_BANK_TAB);
    stmt->setUInt64(0, m_id);
    stmt->setUInt8 (1, tabId);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_BANK_TAB);
    stmt->setUInt64(0, m_id);
    stmt->setUInt8 (1, tabId);
    trans->Append(stmt);

    ++tabId;
    for (auto itr = m_ranks.begin(); itr != m_ranks.end(); ++itr)
        (*itr).CreateMissingTabsIfNeeded(tabId, trans, false);

    CharacterDatabase.CommitTransaction(trans);
}

void Guild::_CreateDefaultGuildRanks(CharacterDatabaseTransaction& trans, LocaleConstant loc)
{
    ASSERT(trans);

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_RANKS);
    stmt->setUInt64(0, m_id);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_BANK_RIGHTS);
    stmt->setUInt64(0, m_id);
    trans->Append(stmt);

    _CreateRank(trans, sObjectMgr->GetTrinityString(LANG_GUILD_MASTER,   loc), GR_RIGHT_ALL);
    _CreateRank(trans, sObjectMgr->GetTrinityString(LANG_GUILD_OFFICER,  loc), GR_RIGHT_ALL);
    _CreateRank(trans, sObjectMgr->GetTrinityString(LANG_GUILD_VETERAN,  loc), GR_RIGHT_GCHATLISTEN | GR_RIGHT_GCHATSPEAK);
    _CreateRank(trans, sObjectMgr->GetTrinityString(LANG_GUILD_MEMBER,   loc), GR_RIGHT_GCHATLISTEN | GR_RIGHT_GCHATSPEAK);
    _CreateRank(trans, sObjectMgr->GetTrinityString(LANG_GUILD_INITIATE, loc), GR_RIGHT_GCHATLISTEN | GR_RIGHT_GCHATSPEAK);
}

bool Guild::_CreateRank(CharacterDatabaseTransaction& trans, std::string const& name, uint32 rights)
{
    uint8 newRankId = _GetRanksSize();
    if (newRankId >= GUILD_RANKS_MAX_COUNT)
        return false;

    // Ranks represent sequence 0, 1, 2, ... where 0 means guildmaster
    RankInfo info(m_id, newRankId, name, rights, 0);
    m_ranks.push_back(info);

    bool const isInTransaction = bool(trans);
    if (!isInTransaction)
        trans = CharacterDatabase.BeginTransaction();

    info.CreateMissingTabsIfNeeded(_GetPurchasedTabsSize(), trans);
    info.SaveToDB(trans);

    if (!isInTransaction)
        CharacterDatabase.CommitTransaction(trans);

    return true;
}

// Updates the number of accounts that are in the guild
// Player may have many characters in the guild, but with the same account
void Guild::_UpdateAccountsNumber()
{
    // We use a set to be sure each element will be unique
    std::set<uint32> accountsIdSet;
    for (auto itr = m_members.begin(); itr != m_members.end(); ++itr)
        accountsIdSet.insert(itr->second->GetAccountId());

    m_accountsNumber = accountsIdSet.size();
}

// Detects if player is the guild master.
// Check both leader guid and player's rank (otherwise multiple feature with
// multiple guild masters won't work)
bool Guild::_IsLeader(Player* player) const
{
    if (player->GetGUID() == m_leaderGuid)
        return true;
    if (Member const* member = GetMember(player->GetGUID()))
        return member->IsRank(GR_GUILDMASTER);
    return false;
}

void Guild::_DeleteBankItems(CharacterDatabaseTransaction& trans, bool removeItemsFromDB)
{
    for (uint8 tabId = 0; tabId < _GetPurchasedTabsSize(); ++tabId)
    {
        m_bankTabs[tabId]->Delete(trans, removeItemsFromDB);
        delete m_bankTabs[tabId];
        m_bankTabs[tabId] = nullptr;
    }
    m_bankTabs.clear();
}

bool Guild::_ModifyBankMoney(CharacterDatabaseTransaction& trans, uint64 amount, bool add)
{
    if (add)
        m_bankMoney += amount;
    else
    {
        // Check if there is enough money in bank.
        if (m_bankMoney < amount)
            return false;
        m_bankMoney -= amount;
    }

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_BANK_MONEY);
    stmt->setUInt64(0, m_bankMoney);
    stmt->setUInt64(1, m_id);
    trans->Append(stmt);
    return true;
}

void Guild::_SetLeader(CharacterDatabaseTransaction& trans, Member* leader)
{
    if (!leader)
        return;

    bool isInTransaction = bool(trans);
    if (!isInTransaction)
        trans = CharacterDatabase.BeginTransaction();

    m_leaderGuid = leader->GetGUID();
    leader->ChangeRank(trans, GR_GUILDMASTER);

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_LEADER);
    stmt->setUInt64(0, m_leaderGuid.GetCounter());
    stmt->setUInt64(1, m_id);
    trans->Append(stmt);

    if (!isInTransaction)
        CharacterDatabase.CommitTransaction(trans);
}

void Guild::_SetRankBankMoneyPerDay(uint8 rankId, uint32 moneyPerDay)
{
    if (RankInfo* rankInfo = GetRankInfo(rankId))
        rankInfo->SetBankMoneyPerDay(moneyPerDay);
}

void Guild::_SetRankBankTabRightsAndSlots(uint8 rankId, GuildBankRightsAndSlots rightsAndSlots, bool saveToDB)
{
    if (rightsAndSlots.GetTabId() >= _GetPurchasedTabsSize())
        return;

    if (RankInfo* rankInfo = GetRankInfo(rankId))
        rankInfo->SetBankTabSlotsAndRights(rightsAndSlots, saveToDB);
}

inline std::string Guild::_GetRankName(uint8 rankId) const
{
    if (RankInfo const* rankInfo = GetRankInfo(rankId))
        return rankInfo->GetName();
    return "<unknown>";
}

inline uint32 Guild::_GetRankRights(uint8 rankId) const
{
    if (RankInfo const* rankInfo = GetRankInfo(rankId))
        return rankInfo->GetRights();
    return 0;
}

inline uint32 Guild::_GetRankBankMoneyPerDay(uint8 rankId) const
{
    if (RankInfo const* rankInfo = GetRankInfo(rankId))
        return rankInfo->GetBankMoneyPerDay();
    return 0;
}

inline int32 Guild::_GetRankBankTabSlotsPerDay(uint8 rankId, uint8 tabId) const
{
    if (tabId < _GetPurchasedTabsSize())
        if (RankInfo const* rankInfo = GetRankInfo(rankId))
            return rankInfo->GetBankTabSlotsPerDay(tabId);
    return 0;
}

inline int8 Guild::_GetRankBankTabRights(uint8 rankId, uint8 tabId) const
{
    if (RankInfo const* rankInfo = GetRankInfo(rankId))
        return rankInfo->GetBankTabRights(tabId);
    return 0;
}

inline int32 Guild::_GetMemberRemainingSlots(Member const* member, uint8 tabId) const
{
    if (member)
    {
        uint8 rankId = member->GetRankId();
        if (rankId == GR_GUILDMASTER)
            return static_cast<int32>(GUILD_WITHDRAW_SLOT_UNLIMITED);
        if ((_GetRankBankTabRights(rankId, tabId) & GUILD_BANK_RIGHT_VIEW_TAB) != 0)
        {
            int32 remaining = _GetRankBankTabSlotsPerDay(rankId, tabId) - member->GetBankTabWithdrawValue(tabId);
            if (remaining > 0)
                return remaining;
        }
    }
    return 0;
}

inline int64 Guild::_GetMemberRemainingMoney(Member const* member) const
{
    if (member)
    {
        uint8 rankId = member->GetRankId();
        if (rankId == GR_GUILDMASTER)
            return std::numeric_limits<int64>::max();

        if ((_GetRankRights(rankId) & (GR_RIGHT_WITHDRAW_REPAIR | GR_RIGHT_WITHDRAW_GOLD)) != 0)
        {
            int64 remaining = (int64(_GetRankBankMoneyPerDay(rankId)) * GOLD) - member->GetBankMoneyWithdrawValue();
            if (remaining > 0)
                return remaining;
        }
    }
    return 0;
}

inline void Guild::_UpdateMemberWithdrawSlots(CharacterDatabaseTransaction& trans, ObjectGuid guid, uint8 tabId)
{
    if (Member* member = GetMember(guid))
        member->UpdateBankTabWithdrawValue(trans, tabId, 1);
}

inline bool Guild::_MemberHasTabRights(ObjectGuid guid, uint8 tabId, int32 rights) const
{
    if (Member const* member = GetMember(guid))
    {
        // Leader always has full rights
        if (member->IsRank(GR_GUILDMASTER) || m_leaderGuid == guid)
            return true;
        return (_GetRankBankTabRights(member->GetRankId(), tabId) & rights) == rights;
    }
    return false;
}

// Add new event log record
inline void Guild::_LogEvent(GuildEventLogTypes eventType, ObjectGuid::LowType playerGuid1, ObjectGuid::LowType playerGuid2, uint8 newRank)
{
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    m_eventLog->AddEvent(trans, new EventLogEntry(m_id, m_eventLog->GetNextGUID(), eventType, playerGuid1, playerGuid2, newRank));
    CharacterDatabase.CommitTransaction(trans);

    sScriptMgr->OnGuildEvent(this, uint8(eventType), playerGuid1, playerGuid2, newRank);
}

// Add new bank event log record
void Guild::_LogBankEvent(CharacterDatabaseTransaction& trans, GuildBankEventLogTypes eventType, uint8 tabId, ObjectGuid::LowType lowguid, uint64 itemOrMoney, uint16 itemStackCount, uint8 destTabId)
{
    if (tabId > GUILD_BANK_MAX_TABS)
        return;

    // not logging moves within the same tab
    if (eventType == GUILD_BANK_LOG_MOVE_ITEM && tabId == destTabId)
        return;

    uint8 dbTabId = tabId;
    if (BankEventLogEntry::IsMoneyEvent(eventType))
    {
        tabId = GUILD_BANK_MAX_TABS;
        dbTabId = GUILD_BANK_MONEY_LOGS_TAB;
    }
    LogHolder* pLog = m_bankEventLog[tabId];
    pLog->AddEvent(trans, new BankEventLogEntry(m_id, pLog->GetNextGUID(), eventType, dbTabId, lowguid, itemOrMoney, itemStackCount, destTabId));

    sScriptMgr->OnGuildBankEvent(this, uint8(eventType), tabId, lowguid, itemOrMoney, itemStackCount, destTabId);
}

inline Item* Guild::_GetItem(uint8 tabId, uint8 slotId) const
{
    if (BankTab const* tab = GetBankTab(tabId))
        return tab->GetItem(slotId);
    return nullptr;
}

inline void Guild::_RemoveItem(CharacterDatabaseTransaction& trans, uint8 tabId, uint8 slotId)
{
    if (BankTab* pTab = GetBankTab(tabId))
        pTab->SetItem(trans, slotId, nullptr);
}

void Guild::_MoveItems(MoveItemData* pSrc, MoveItemData* pDest, uint32 splitedAmount) const
{
    // 1. Initialize source item
    if (!pSrc->InitItem())
        return; // No source item

    // 2. Check source item
    if (!pSrc->CheckItem(splitedAmount))
        return; // Source item or splited amount is invalid
    /*
    if (pItemSrc->GetCount() == 0)
    {
        TC_LOG_FATAL("guild", "Guild::SwapItems: Player %s(GUIDLow: %u) tried to move item %u from tab %u slot %u to tab %u slot %u, but item %u has a stack of zero!",
            player->GetName(), player->GetGUIDLow(), pItemSrc->GetEntry(), tabId, slotId, destTabId, destSlotId, pItemSrc->GetEntry());
        //return; // Commented out for now, uncomment when it's verified that this causes a crash!!
    }
    // */

    // 3. Check destination rights
    if (!pDest->HasStoreRights(pSrc))
        return; // Player has no rights to store item in destination

    // 4. Check source withdraw rights
    if (!pSrc->HasWithdrawRights(pDest))
        return; // Player has no rights to withdraw items from source

    // 5. Check split
    if (splitedAmount)
    {
        // 5.1. Clone source item
        if (!pSrc->CloneItem(splitedAmount))
            return; // Item could not be cloned

        // 5.2. Move splited item to destination
        Guild::_DoItemsMove(pSrc, pDest, true, splitedAmount);
    }
    else // 6. No split
    {
        // 6.1. Try to merge items in destination (pDest->GetItem() == nullptr)
        if (!Guild::_DoItemsMove(pSrc, pDest, false)) // Item could not be merged
        {
            // 6.2. Try to swap items
            // 6.2.1. Initialize destination item
            if (!pDest->InitItem())
                return;

            // 6.2.2. Check rights to store item in source (opposite direction)
            if (!pSrc->HasStoreRights(pDest))
                return; // Player has no rights to store item in source (opposite direction)

            if (!pDest->HasWithdrawRights(pSrc))
                return; // Player has no rights to withdraw item from destination (opposite direction)

            // 6.2.3. Swap items (pDest->GetItem() != nullptr)
            Guild::_DoItemsMove(pSrc, pDest, true);
        }
    }
    // 7. Send changes
    _SendBankContentUpdate(pSrc, pDest);
}

bool Guild::_DoItemsMove(MoveItemData* pSrc, MoveItemData* pDest, bool sendError, uint32 splitedAmount)
{
    Item* pDestItem = pDest->GetItem();
    bool swap = (pDestItem != nullptr);

    Item* pSrcItem = pSrc->GetItem(splitedAmount != 0);
    // 1. Can store source item in destination
    if (!pDest->CanStore(pSrcItem, swap, sendError))
        return false;

    // 2. Can store destination item in source
    if (swap)
        if (!pSrc->CanStore(pDestItem, true, true))
            return false;

    // GM LOG (@todo move to scripts)
    pDest->LogAction(pSrc);
    if (swap)
        pSrc->LogAction(pDest);

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    // 3. Log bank events
    pDest->LogBankEvent(trans, pSrc, pSrcItem->GetCount());
    if (swap)
        pSrc->LogBankEvent(trans, pDest, pDestItem->GetCount());

    // 4. Remove item from source
    pSrc->RemoveItem(trans, pDest, splitedAmount);

    // 5. Remove item from destination
    if (swap)
        pDest->RemoveItem(trans, pSrc);

    // 6. Store item in destination
    pDest->StoreItem(trans, pSrcItem);

    // 7. Store item in source
    if (swap)
        pSrc->StoreItem(trans, pDestItem);

    CharacterDatabase.CommitTransaction(trans);
    return true;
}

void Guild::_SendBankContentUpdate(MoveItemData* pSrc, MoveItemData* pDest) const
{
    ASSERT(pSrc->IsBank() || pDest->IsBank());

    uint8 tabId = 0;
    SlotIds slots;
    if (pSrc->IsBank()) // B ->
    {
        tabId = pSrc->GetContainer();
        slots.insert(pSrc->GetSlotId());
        if (pDest->IsBank()) // B -> B
        {
            // Same tab - add destination slots to collection
            if (pDest->GetContainer() == pSrc->GetContainer())
                pDest->CopySlots(slots);
            else // Different tabs - send second message
            {
                SlotIds destSlots;
                pDest->CopySlots(destSlots);
                _SendBankContentUpdate(pDest->GetContainer(), destSlots);
            }
        }
    }
    else if (pDest->IsBank()) // C -> B
    {
        tabId = pDest->GetContainer();
        pDest->CopySlots(slots);
    }

    _SendBankContentUpdate(tabId, slots);
}

void Guild::_SendBankContentUpdate(uint8 tabId, SlotIds slots) const
{
    if (BankTab const* tab = GetBankTab(tabId))
    {
        WorldPackets::Guild::GuildBankQueryResults packet;
        packet.FullUpdate = true;          // @todo
        packet.Tab = int32(tabId);
        packet.Money = m_bankMoney;

        for (SlotIds::const_iterator itr = slots.begin(); itr != slots.end(); ++itr)
        {
            Item const* tabItem = tab->GetItem(*itr);

            WorldPackets::Guild::GuildBankItemInfo itemInfo;

            itemInfo.Slot = int32(*itr);
            itemInfo.Item.ItemID = int32(tabItem ? tabItem->GetEntry() : 0);
            itemInfo.Count = int32(tabItem ? tabItem->GetCount() : 0);
            itemInfo.Charges = int32(tabItem ? abs(tabItem->GetSpellCharges()) : 0);
            itemInfo.OnUseEnchantmentID = 0/*int32(tabItem->GetItemSuffixFactor())*/;
            itemInfo.Flags = 0;
            itemInfo.Locked = false;

            if (tabItem)
            {
                uint8 i = 0;
                for (UF::SocketedGem const& gemData : tabItem->m_itemData->Gems)
                {
                    if (gemData.ItemID)
                    {
                        WorldPackets::Item::ItemGemData gem;
                        gem.Slot = i;
                        gem.Item.Initialize(&gemData);
                        itemInfo.SocketEnchant.push_back(gem);
                    }
                    ++i;
                }
            }

            packet.ItemInfo.push_back(itemInfo);
        }

        for (Members::const_iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
            if (_MemberHasTabRights(itr->second->GetGUID(), tabId, GUILD_BANK_RIGHT_VIEW_TAB))
                if (Player* player = itr->second->FindPlayer())
                {
                    packet.WithdrawalsRemaining = _GetMemberRemainingSlots(itr->second, tabId);
                    player->GetSession()->SendPacket(packet.Write());
                }
    }
}

void Guild::SendBankList(WorldSession* session, uint8 tabId, bool fullUpdate) const
{
    Member const* member = GetMember(session->GetPlayer()->GetGUID());
    if (!member) // Shouldn't happen, just in case
        return;

    WorldPackets::Guild::GuildBankQueryResults packet;

    packet.Money = m_bankMoney;
    packet.WithdrawalsRemaining = _GetMemberRemainingSlots(member, tabId);
    packet.Tab = int32(tabId);
    packet.FullUpdate = fullUpdate;

    // TabInfo
    if (fullUpdate)
    {
        packet.TabInfo.reserve(_GetPurchasedTabsSize());
        for (uint8 i = 0; i < _GetPurchasedTabsSize(); ++i)
        {
            WorldPackets::Guild::GuildBankTabInfo tabInfo;
            tabInfo.TabIndex = i;
            tabInfo.Name = m_bankTabs[i]->GetName();
            tabInfo.Icon = m_bankTabs[i]->GetIcon();
            packet.TabInfo.push_back(tabInfo);
        }
    }

    // ItemInfo
    uint32 itemCount = 0;
    if (fullUpdate && _MemberHasTabRights(session->GetPlayer()->GetGUID(), tabId, GUILD_BANK_RIGHT_VIEW_TAB))
        if (BankTab const* tab = GetBankTab(tabId))
            for (uint8 slotId = 0; slotId < GUILD_BANK_MAX_SLOTS; ++slotId)
                if (tab->GetItem(slotId))
                    ++itemCount;

    packet.ItemInfo.reserve(itemCount);

    if (fullUpdate && _MemberHasTabRights(session->GetPlayer()->GetGUID(), tabId, GUILD_BANK_RIGHT_VIEW_TAB))
    {
        if (BankTab const* tab = GetBankTab(tabId))
        {
            for (uint8 slotId = 0; slotId < GUILD_BANK_MAX_SLOTS; ++slotId)
            {
                if (Item* tabItem = tab->GetItem(slotId))
                {
                    WorldPackets::Guild::GuildBankItemInfo itemInfo;

                    itemInfo.Slot = int32(slotId);
                    itemInfo.Item.ItemID = tabItem->GetEntry();
                    itemInfo.Count = int32(tabItem->GetCount());
                    itemInfo.Charges = int32(abs(tabItem->GetSpellCharges()));
                    itemInfo.EnchantmentID = int32(tabItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT));
                    itemInfo.OnUseEnchantmentID = int32(tabItem->GetEnchantmentId(USE_ENCHANTMENT_SLOT));
                    itemInfo.Flags = tabItem->m_itemData->DynamicFlags;

                    uint8 i = 0;
                    for (UF::SocketedGem const& gemData : tabItem->m_itemData->Gems)
                    {
                        if (gemData.ItemID)
                        {
                            WorldPackets::Item::ItemGemData gem;
                            gem.Slot = i;
                            gem.Item.Initialize(&gemData);
                            itemInfo.SocketEnchant.push_back(gem);
                        }
                        ++i;
                    }

                    itemInfo.Locked = false;

                    packet.ItemInfo.push_back(itemInfo);
                }
            }
        }
    }

    session->SendPacket(packet.Write());
}

void Guild::SendGuildRanksUpdate(ObjectGuid setterGuid, ObjectGuid targetGuid, uint32 rank)
{
    Member* member = GetMember(targetGuid);
    ASSERT(member);

    WorldPackets::Guild::GuildSendRankChange rankChange;
    rankChange.Officer = setterGuid;
    rankChange.Other = targetGuid;
    rankChange.RankID = rank;
    rankChange.Promote = (rank < member->GetRankId());
    BroadcastPacket(rankChange.Write());

    CharacterDatabaseTransaction trans;
    member->ChangeRank(trans, rank);

    TC_LOG_DEBUG("network", "SMSG_GUILD_RANKS_UPDATE [Broadcast] Target: %s, Issuer: %s, RankId: %u",
        targetGuid.ToString().c_str(), setterGuid.ToString().c_str(), rank);
}

void Guild::ResetTimes(bool weekly)
{
    for (auto itr = m_members.begin(); itr != m_members.end(); ++itr)
    {
        itr->second->ResetValues(weekly);
        if (Player* player = itr->second->FindPlayer())
        {
            WorldPackets::Guild::GuildMemberDailyReset packet; // tells the client to request bank withdrawal limit
            player->GetSession()->SendPacket(packet.Write());
        }
    }
}

void Guild::AddGuildNews(uint8 type, ObjectGuid guid, uint32 flags, uint32 value) const
{
    NewsLogEntry* news = new NewsLogEntry(m_id, m_newsLog->GetNextGUID(), GuildNews(type), guid, flags, value);

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    m_newsLog->AddEvent(trans, news);
    CharacterDatabase.CommitTransaction(trans);

    WorldPackets::Guild::GuildNews newsPacket;
    newsPacket.NewsEvents.reserve(1);
    news->WritePacket(newsPacket);
    BroadcastPacket(newsPacket.Write());
}

bool Guild::HasAchieved(uint32 achievementId) const
{
    return m_achievementMgr.HasAchieved(achievementId);
}

void Guild::UpdateCriteria(CriteriaTypes type, uint64 miscValue1, uint64 miscValue2, uint64 miscValue3, Unit* unit, Player* player)
{
    m_achievementMgr.UpdateCriteria(type, miscValue1, miscValue2, miscValue3, unit, player);
}

void Guild::HandleNewsSetSticky(WorldSession* session, uint32 newsId, bool sticky) const
{
    GuildLog* logs = m_newsLog->GetGuildLog();
    GuildLog::iterator itr = logs->begin();
    while (itr != logs->end() && (*itr)->GetGUID() != newsId)
        ++itr;

    if (itr == logs->end())
    {
        TC_LOG_DEBUG("guild", "HandleNewsSetSticky: [%s] requested unknown newsId %u - Sticky: %u",
            session->GetPlayerInfo().c_str(), newsId, sticky);
        return;
    }

    NewsLogEntry* news = static_cast<NewsLogEntry*>(*itr);
    news->SetSticky(sticky);

    TC_LOG_DEBUG("guild", "HandleNewsSetSticky: [%s] changed newsId %u sticky to %u",
        session->GetPlayerInfo().c_str(), newsId, sticky);

    WorldPackets::Guild::GuildNews newsPacket;
    newsPacket.NewsEvents.reserve(1);
    news->WritePacket(newsPacket);
    session->SendPacket(newsPacket.Write());
}
