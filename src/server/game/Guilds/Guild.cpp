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
#include "AchievementMgr.h"
#include "Bag.h"
#include "CalendarMgr.h"
#include "CalendarPackets.h"
#include "CharacterCache.h"
#include "Chat.h"
#include "ChatPackets.h"
#include "ClubMembershipService.h"
#include "ClubService.h"
#include "ClubUtils.h"
#include "Config.h"
#include "DB2Stores.h"
#include "DatabaseEnv.h"
#include "GameTime.h"
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
#include "club_listener.pb.h"
#include "club_membership_listener.pb.h"

size_t const MAX_GUILD_BANK_TAB_TEXT_LEN = 500;

uint32 const EMBLEM_PRICE = 10 * GOLD;

inline uint64 GetGuildBankTabPrice(uint8 tabId)
{
    // these prices are in gold units, not copper
    static uint64 const tabPrices[GUILD_BANK_MAX_TABS] = { 100, 250, 500, 1000, 2500, 5000, 0, 0 };
    ASSERT(tabId < GUILD_BANK_MAX_TABS);

    return tabPrices[tabId];
}

void Guild::SendCommandResult(WorldSession* session, GuildCommandType type, GuildCommandError errCode, std::string_view param)
{
    WorldPackets::Guild::GuildCommandResult resultPacket;
    resultPacket.Command = type;
    resultPacket.Result = errCode;
    resultPacket.Name = param;
    session->SendPacket(resultPacket.Write());

    TC_LOG_DEBUG("guild", "SMSG_GUILD_COMMAND_RESULT [{}]: Type: {}, code: {}, param: {}"
         , session->GetPlayerInfo(), type, errCode, resultPacket.Name);
}

void Guild::SendSaveEmblemResult(WorldSession* session, GuildEmblemError errCode)
{
    WorldPackets::Guild::PlayerSaveGuildEmblem saveResponse;
    saveResponse.Error = int32(errCode);
    session->SendPacket(saveResponse.Write());

    TC_LOG_DEBUG("guild", "Sent SMSG_SAVE_GUILD_EMBLEM [{}] Code: {}", session->GetPlayerInfo(), errCode);
}

// LogHolder
template <typename Entry>
Guild::LogHolder<Entry>::LogHolder()
    : m_maxRecords(sWorld->getIntConfig(std::is_same_v<Entry, BankEventLogEntry> ? CONFIG_GUILD_BANK_EVENT_LOG_COUNT : CONFIG_GUILD_EVENT_LOG_COUNT)), m_nextGUID(uint32(GUILD_EVENT_LOG_GUID_UNDEFINED))
{ }

template <typename Entry> template <typename... Ts>
void Guild::LogHolder<Entry>::LoadEvent(Ts&&... args)
{
    Entry const& newEntry = m_log.emplace_front(std::forward<Ts>(args)...);
    if (m_nextGUID == uint32(GUILD_EVENT_LOG_GUID_UNDEFINED))
        m_nextGUID = newEntry.GetGUID();
}

template <typename Entry> template <typename... Ts>
Entry& Guild::LogHolder<Entry>::AddEvent(CharacterDatabaseTransaction trans, Ts&&... args)
{
    // Check max records limit
    if (!CanInsert())
        m_log.pop_front();

    // Add event to list
    Entry& entry = m_log.emplace_back(std::forward<Ts>(args)...);
    // Save to DB
    entry.SaveToDB(trans);
    return entry;
}

template <typename Entry>
inline uint32 Guild::LogHolder<Entry>::GetNextGUID()
{
    // Next guid was not initialized. It means there are no records for this holder in DB yet.
    // Start from the beginning.
    if (m_nextGUID == uint32(GUILD_EVENT_LOG_GUID_UNDEFINED))
        m_nextGUID = 0;
    else
        m_nextGUID = (m_nextGUID + 1) % m_maxRecords;
    return m_nextGUID;
}

Guild::LogEntry::LogEntry(ObjectGuid::LowType guildId, uint32 guid) : m_guildId(guildId), m_guid(guid), m_timestamp(GameTime::GetGameTime()) { }

// EventLogEntry
void Guild::EventLogEntry::SaveToDB(CharacterDatabaseTransaction trans) const
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
    stmt->setInt64 (++index, m_timestamp);
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
    eventEntry.TransactionDate = uint32(GameTime::GetGameTime() - m_timestamp);
    eventEntry.RankID = uint8(m_newRank);
    packet.Entry.push_back(eventEntry);
}

// BankEventLogEntry
void Guild::BankEventLogEntry::SaveToDB(CharacterDatabaseTransaction trans) const
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
    stmt->setInt64 (++index, m_timestamp);
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
    bankLogEntry.TimeOffset = int32(GameTime::GetGameTime() - m_timestamp);
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

void Guild::NewsLogEntry::SaveToDB(CharacterDatabaseTransaction trans) const
{
    uint8 index = 0;
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_NEWS);
    stmt->setUInt64(  index, m_guildId);
    stmt->setUInt32(++index, GetGUID());
    stmt->setUInt8 (++index, GetType());
    stmt->setUInt64(++index, GetPlayerGuid().GetCounter());
    stmt->setUInt32(++index, GetFlags());
    stmt->setUInt32(++index, GetValue());
    stmt->setInt64 (++index, GetTimestamp());
    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void Guild::NewsLogEntry::WritePacket(WorldPackets::Guild::GuildNews& newsPacket) const
{
    WorldPackets::Guild::GuildNewsEvent newsEvent;
    newsEvent.Id = int32(GetGUID());
    newsEvent.MemberGuid = GetPlayerGuid();
    newsEvent.CompletedDate.SetUtcTimeFromUnixTime(GetTimestamp());
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
    m_rankId            = GuildRankId(fields[1].GetUInt8());
    m_rankOrder         = GuildRankOrder(fields[2].GetUInt8());
    m_name              = fields[3].GetString();
    m_rights            = fields[4].GetUInt32();
    m_bankMoneyPerDay   = fields[5].GetUInt32();
    if (m_rankId == GuildRankId::GuildMaster)           // Prevent loss of leader rights
        m_rights |= GR_RIGHT_ALL;
}

void Guild::RankInfo::SaveToDB(CharacterDatabaseTransaction trans) const
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_RANK);
    stmt->setUInt64(0, m_guildId);
    stmt->setUInt8 (1, AsUnderlyingType(m_rankId));
    stmt->setUInt8 (2, AsUnderlyingType(m_rankOrder));
    stmt->setString(3, m_name);
    stmt->setUInt32(4, m_rights);
    stmt->setUInt32(5, m_bankMoneyPerDay);
    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void Guild::RankInfo::CreateMissingTabsIfNeeded(uint8 tabs, CharacterDatabaseTransaction trans, bool logOnCreate /* = false */)
{
    for (uint8 i = 0; i < tabs; ++i)
    {
        GuildBankRightsAndSlots& rightsAndSlots = m_bankTabRightsAndSlots[i];
        if (rightsAndSlots.GetTabId() == i)
            continue;

        rightsAndSlots.SetTabId(i);
        if (m_rankId == GuildRankId::GuildMaster)
            rightsAndSlots.SetGuildMasterValues();

        if (logOnCreate)
            TC_LOG_ERROR("guild", "Guild {} has broken Tab {} for rank {}. Created default tab.", m_guildId, i, uint32(m_rankId));

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_BANK_RIGHT);
        stmt->setUInt64(0, m_guildId);
        stmt->setUInt8(1, i);
        stmt->setUInt8(2, AsUnderlyingType(m_rankId));
        stmt->setInt8(3,  rightsAndSlots.GetRights());
        stmt->setInt32(4, rightsAndSlots.GetSlots());
        trans->Append(stmt);
    }
}

void Guild::RankInfo::SetName(std::string_view name)
{
    if (m_name == name)
        return;

    m_name = name;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_RANK_NAME);
    stmt->setString(0, m_name);
    stmt->setUInt8 (1, AsUnderlyingType(m_rankId));
    stmt->setUInt64(2, m_guildId);
    CharacterDatabase.Execute(stmt);
}

void Guild::RankInfo::SetRights(uint32 rights)
{
    if (m_rankId == GuildRankId::GuildMaster)           // Prevent loss of leader rights
        rights = GR_RIGHT_ALL;

    if (m_rights == rights)
        return;

    m_rights = rights;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_RANK_RIGHTS);
    stmt->setUInt32(0, m_rights);
    stmt->setUInt8 (1, AsUnderlyingType(m_rankId));
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
    stmt->setUInt8 (1, AsUnderlyingType(m_rankId));
    stmt->setUInt64(2, m_guildId);
    CharacterDatabase.Execute(stmt);
}

void Guild::RankInfo::SetBankTabSlotsAndRights(GuildBankRightsAndSlots rightsAndSlots, bool saveToDB)
{
    if (m_rankId == GuildRankId::GuildMaster)           // Prevent loss of leader rights
        rightsAndSlots.SetGuildMasterValues();

    GuildBankRightsAndSlots& guildBR = m_bankTabRightsAndSlots[rightsAndSlots.GetTabId()];
    guildBR = rightsAndSlots;

    if (saveToDB)
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_BANK_RIGHT);
        stmt->setUInt64(0, m_guildId);
        stmt->setUInt8 (1, guildBR.GetTabId());
        stmt->setUInt8 (2, AsUnderlyingType(m_rankId));
        stmt->setInt8  (3, guildBR.GetRights());
        stmt->setInt32 (4, guildBR.GetSlots());
        CharacterDatabase.Execute(stmt);
    }
}

// BankTab
Guild::BankTab::BankTab(ObjectGuid::LowType guildId, uint8 tabId) : m_guildId(guildId), m_tabId(tabId)
{ }

void Guild::BankTab::LoadFromDB(Field* fields)
{
    m_name = fields[2].GetString();
    m_icon = fields[3].GetString();
    m_text = fields[4].GetString();
}

bool Guild::BankTab::LoadItemFromDB(Field* fields)
{
    uint8 slotId = fields[55].GetUInt8();
    ObjectGuid::LowType itemGuid = fields[0].GetUInt64();
    uint32 itemEntry = fields[1].GetUInt32();
    if (slotId >= GUILD_BANK_MAX_SLOTS)
    {
        TC_LOG_ERROR("guild", "Invalid slot for item (GUID: {}, id: {}) in guild bank, skipped.", itemGuid, itemEntry);
        return false;
    }

    ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemEntry);
    if (!proto)
    {
        TC_LOG_ERROR("guild", "Unknown item (GUID: {}, id: {}) in guild bank, skipped.", itemGuid, itemEntry);
        return false;
    }

    Item* pItem = NewItemOrBag(proto);
    if (!pItem->LoadFromDB(itemGuid, ObjectGuid::Empty, fields, itemEntry))
    {
        TC_LOG_ERROR("guild", "Item (GUID {}, id: {}) not found in item_instance, deleting from guild bank!", itemGuid, itemEntry);

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
void Guild::BankTab::Delete(CharacterDatabaseTransaction trans, bool removeItemsFromDB)
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

void Guild::BankTab::SetInfo(std::string_view name, std::string_view icon)
{
    if ((m_name == name) && (m_icon == icon))
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

void Guild::BankTab::SetText(std::string_view text)
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
bool Guild::BankTab::SetItem(CharacterDatabaseTransaction trans, uint8 slotId, Item* item)
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
        TC_LOG_DEBUG("guild", "SMSG_GUILD_BANK_QUERY_TEXT_RESULT [{}]: Tabid: {}, Text: {}"
            , session->GetPlayerInfo(), m_tabId, m_text);
        session->SendPacket(textQuery.Write());
    }
    else
    {
        TC_LOG_DEBUG("guild", "SMSG_GUILD_BANK_QUERY_TEXT_RESULT [Broadcast]: Tabid: {}, Text: {}", m_tabId, m_text);
        guild->BroadcastPacket(textQuery.Write());
    }
}

// Member
Guild::Member::Member(ObjectGuid::LowType guildId, ObjectGuid guid, GuildRankId rankId) :
    m_guildId(guildId),
    m_guid(guid),
    m_zoneId(0),
    m_level(0),
    m_race(0),
    m_class(0),
    m_gender(0),
    m_flags(GUILDMEMBER_STATUS_NONE),
    m_logoutTime(GameTime::GetGameTime()),
    m_accountId(0),
    m_rankId(rankId),
    m_bankWithdraw(),
    m_bankWithdrawMoney(0),
    m_achievementPoints(0),
    m_totalActivity(0),
    m_weekActivity(0),
    m_totalReputation(0),
    m_weekReputation(0)
{}

void Guild::Member::SetStats(Player* player)
{
    m_name      = player->GetName();
    m_level     = player->GetLevel();
    m_race      = player->GetRace();
    m_class     = player->GetClass();
    m_gender    = player->GetNativeGender();
    m_zoneId    = player->GetZoneId();
    m_accountId = player->GetSession()->GetAccountId();
    m_achievementPoints = player->GetAchievementPoints();
}

void Guild::Member::SetStats(std::string_view name, uint8 level, uint8 race, uint8 _class, uint8 gender, uint32 zoneId, uint32 accountId, uint32 reputation)
{
    m_name      = name;
    m_level     = level;
    m_race      = race;
    m_class     = _class;
    m_gender    = gender;
    m_zoneId    = zoneId;
    m_accountId = accountId;
    m_totalReputation = reputation;
}

void Guild::Member::SetPublicNote(std::string_view publicNote)
{
    if (m_publicNote == publicNote)
        return;

    m_publicNote = publicNote;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_MEMBER_PNOTE);
    stmt->setString(0, m_publicNote);
    stmt->setUInt64(1, m_guid.GetCounter());
    CharacterDatabase.Execute(stmt);
}

void Guild::Member::SetOfficerNote(std::string_view officerNote)
{
    if (m_officerNote == officerNote)
        return;

    m_officerNote = officerNote;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_MEMBER_OFFNOTE);
    stmt->setString(0, m_officerNote);
    stmt->setUInt64(1, m_guid.GetCounter());
    CharacterDatabase.Execute(stmt);
}

void Guild::Member::ChangeRank(CharacterDatabaseTransaction trans, GuildRankId newRank)
{
    m_rankId = newRank;

    // Update rank information in player's field, if he is online.
    if (Player* player = FindConnectedPlayer())
        player->SetGuildRank(AsUnderlyingType(newRank));

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_MEMBER_RANK);
    stmt->setUInt8 (0, AsUnderlyingType(newRank));
    stmt->setUInt64(1, m_guid.GetCounter());
    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void Guild::Member::UpdateLogoutTime()
{
    m_logoutTime = GameTime::GetGameTime();
}

void Guild::Member::SaveToDB(CharacterDatabaseTransaction trans) const
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_MEMBER);
    stmt->setUInt64(0, m_guildId);
    stmt->setUInt64(1, m_guid.GetCounter());
    stmt->setUInt8 (2, AsUnderlyingType(m_rankId));
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
             fields[16].GetUInt8(),                         // characters.race
             fields[17].GetUInt8(),                         // characters.class
             fields[18].GetUInt8(),                         // characters.gender
             fields[19].GetUInt16(),                        // characters.zone
             fields[20].GetUInt32(),                        // characters.account
             0);
    m_logoutTime = fields[21].GetUInt64();                  // characters.logout_time
    m_totalActivity = 0;
    m_weekActivity = 0;
    m_weekReputation = 0;

    if (!CheckStats())
        return false;

    if (!m_zoneId)
    {
        TC_LOG_DEBUG("guild", "{} has broken zone-data", m_guid.ToString());
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
        TC_LOG_ERROR("guild", "{} has a broken data in field `characters`.`level`, deleting him from guild!", m_guid.ToString());
        return false;
    }

    if (!sChrRacesStore.LookupEntry(m_race))
    {
        TC_LOG_ERROR("guild", "{} has a broken data in field `characters`.`race`, deleting him from guild!", m_guid.ToString());
        return false;
    }

    if (!sChrClassesStore.LookupEntry(m_class))
    {
        TC_LOG_ERROR("guild", "{} has a broken data in field `characters`.`class`, deleting him from guild!", m_guid.ToString());
        return false;
    }
    return true;
}

float Guild::Member::GetInactiveDays() const
{
    if (IsOnline())
        return 0.0f;
    return float(GameTime::GetGameTime() - GetLogoutTime()) / float(DAY);
}

// Decreases amount of slots left for today.
void Guild::Member::UpdateBankTabWithdrawValue(CharacterDatabaseTransaction trans, uint8 tabId, uint32 amount)
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
void Guild::Member::UpdateBankMoneyWithdrawValue(CharacterDatabaseTransaction trans, uint64 amount)
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

bool EmblemInfo::ValidateEmblemColors(uint32 /*style*/, uint32 color, uint32 /*borderStyle*/, uint32 borderColor, uint32 backgroundColor)
{
    return sGuildColorBackgroundStore.LookupEntry(backgroundColor) &&
           sGuildColorBorderStore.LookupEntry(borderColor) &&
           sGuildColorEmblemStore.LookupEntry(color);
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

InventoryResult Guild::MoveItemData::CanStore(Item* pItem, bool swap, bool sendError)
{
    m_vec.clear();
    InventoryResult msg = CanStore(pItem, swap);
    if (sendError && msg != EQUIP_ERR_OK)
        SendEquipError(msg, pItem);
    return msg;
}

bool Guild::MoveItemData::CloneItem(uint32 count)
{
    ASSERT(m_pItem);
    m_pClonedItem = m_pItem->CloneItem(count);
    if (!m_pClonedItem)
    {
        SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, m_pItem);
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

void Guild::MoveItemData::SendEquipError(InventoryResult result, Item const* item)
{
    m_pPlayer->SendEquipError(result, item);
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
            SendEquipError(EQUIP_ERR_DESTROY_NONEMPTY_BAG, m_pItem);
            m_pItem = nullptr;
        }
        // Bound items cannot be put into bank.
        else if (!m_pItem->CanBeTraded())
        {
            SendEquipError(EQUIP_ERR_CANT_SWAP, m_pItem);
            m_pItem = nullptr;
        }
    }
    return (m_pItem != nullptr);
}

void Guild::PlayerMoveItemData::RemoveItem(CharacterDatabaseTransaction trans, MoveItemData* /*pOther*/, uint32 splitedAmount)
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

Item* Guild::PlayerMoveItemData::StoreItem(CharacterDatabaseTransaction trans, Item* pItem)
{
    ASSERT(pItem);
    m_pPlayer->MoveItemToInventory(m_vec, pItem, true);
    m_pPlayer->SaveInventoryAndGoldToDB(trans);
    return pItem;
}

void Guild::PlayerMoveItemData::LogBankEvent(CharacterDatabaseTransaction trans, MoveItemData* pFrom, uint32 count) const
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
        slots = m_pGuild->_GetMemberRemainingSlots(*member, m_container);

    return slots != 0;
}

void Guild::BankMoveItemData::RemoveItem(CharacterDatabaseTransaction trans, MoveItemData* pOther, uint32 splitedAmount)
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

Item* Guild::BankMoveItemData::StoreItem(CharacterDatabaseTransaction trans, Item* pItem)
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

        ASSERT(pItem);

        TC_LOG_DEBUG("guild", "GUILD STORAGE: StoreItem tab = {}, slot = {}, item = {}, count = {}",
            m_container, m_slotId, pItem->GetEntry(), pItem->GetCount());
        pLastItem = _StoreItem(trans, pTab, pItem, pos, itr != m_vec.end());
    }
    return pLastItem;
}

void Guild::BankMoveItemData::LogBankEvent(CharacterDatabaseTransaction trans, MoveItemData* pFrom, uint32 count) const
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
        sLog->OutCommand(m_pPlayer->GetSession()->GetAccountId(),
            "GM {} ({}) (Account: {}) deposit item: {} (Entry: {} Count: {}) to guild bank named: {} (Guild ID: {})",
            m_pPlayer->GetName(), m_pPlayer->GetGUID().ToString(), m_pPlayer->GetSession()->GetAccountId(),
            pFrom->GetItem()->GetTemplate()->GetDefaultLocaleName(), pFrom->GetItem()->GetEntry(), pFrom->GetItem()->GetCount(),
            m_pGuild->GetName(), m_pGuild->GetId());
    }
}

Item* Guild::BankMoveItemData::_StoreItem(CharacterDatabaseTransaction trans, BankTab* pTab, Item* pItem, ItemPosCount& pos, bool clone) const
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
    TC_LOG_DEBUG("guild", "GUILD STORAGE: CanStore() tab = {}, slot = {}, item = {}, count = {}",
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
    m_achievementMgr(std::make_unique<GuildAchievementMgr>(this))
{
}

Guild::~Guild()
{
    CharacterDatabaseTransaction temp(nullptr);
    _DeleteBankItems(temp);
}

// Creates new guild with default data and saves it to database.
bool Guild::Create(Player* pLeader, std::string_view name)
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
    m_createdDate = GameTime::GetGameTime();

    TC_LOG_DEBUG("guild", "GUILD: creating guild [{}] for leader {} {}",
        m_name, pLeader->GetName(), m_leaderGuid.ToString());

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_MEMBERS);
    stmt->setUInt64(0, m_id);
    trans->Append(stmt);

    uint8 index = 0;
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD);
    stmt->setUInt64(  index, m_id);
    stmt->setString(++index, m_name);
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
    bool ret = AddMember(trans, m_leaderGuid, GuildRankId::GuildMaster);        // Add guildmaster

    CharacterDatabase.CommitTransaction(trans);

    if (ret)
    {
        Member* leader = GetMember(m_leaderGuid);
        if (leader)
            SendEventNewLeader(leader, nullptr);

        sScriptMgr->OnGuildCreate(this, pLeader, m_name);
    }

    return ret;
}

// Disbands guild and deletes all related data from database
void Guild::Disband()
{
    // Call scripts before guild data removed from database
    sScriptMgr->OnGuildDisband(this);

    WorldPackets::Guild::GuildEventDisbanded guildEventDisbanded;
    guildEventDisbanded.Write();

    // Notify the members of club removal.
    club::v1::UnsubscribeNotification unsubscribeNotification;
    unsubscribeNotification.set_club_id(GetId());

    BroadcastWorker([&](Player const* member)
    {
        member->SendDirectMessage(guildEventDisbanded.GetRawPacket());

        // Unsubscribe the removed player from the club to ensure interface updates.
        Battlenet::WorldserverService<club::v1::ClubListener>(member->GetSession()).OnUnsubscribe(&unsubscribeNotification, true, true);

        // Finally notify the client about leaving the club.
        club::v1::membership::ClubRemovedNotification clubRemovedNotification;
        clubRemovedNotification.set_allocated_member_id(Battlenet::Services::ClubMembershipService::CreateClubMemberId(member->GetGUID()).release());
        clubRemovedNotification.set_club_id(GetId());
        clubRemovedNotification.set_reason(club::v1::ClubRemovedReason::CLUB_REMOVED_REASON_DESTROYED_BY_MEMBER);
        Battlenet::WorldserverService<club::v1::membership::ClubMembershipListener>(member->GetSession()).OnClubRemoved(&clubRemovedNotification, true, true);
    });

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    // Remove all members
    while (!m_members.empty())
    {
        auto itr = m_members.begin();
        DeleteMember(trans, itr->second.GetGUID(), true);
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

    sGuildMgr->RemoveGuild(m_id);
}

void Guild::SaveToDB()
{
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    GetAchievementMgr().SaveToDB(trans);

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
                TC_LOG_ERROR("guild", "Guild::UpdateMemberData: Called with incorrect DATAID {} (value {})", dataid, value);
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

bool Guild::SetName(std::string_view name)
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
    roster.CreateDate.SetUtcTimeFromUnixTime(m_createdDate);
    roster.CreateDate += session->GetTimezoneOffset();
    roster.GuildFlags = 0;

    roster.MemberData.reserve(m_members.size());

    bool sendOfficerNote = _HasRankRight(session->GetPlayer(), GR_RIGHT_VIEWOFFNOTE);
    for (auto const& [guid, member] : m_members)
    {
        WorldPackets::Guild::GuildRosterMemberData& memberData = roster.MemberData.emplace_back();

        memberData.Guid = member.GetGUID();
        memberData.RankID = int32(member.GetRankId());
        memberData.AreaID = int32(member.GetZoneId());
        memberData.PersonalAchievementPoints = int32(member.GetAchievementPoints());
        memberData.GuildReputation = int32(member.GetTotalReputation());
        memberData.LastSave = member.GetInactiveDays();

        //GuildRosterProfessionData

        memberData.VirtualRealmAddress = GetVirtualRealmAddress();
        memberData.Status = member.GetFlags();
        memberData.Level = member.GetLevel();
        memberData.ClassID = member.GetClass();
        memberData.Gender = member.GetGender();
        memberData.RaceID = member.GetRace();
        memberData.GuildClubMemberID = Battlenet::Services::Clubs::CreateClubMemberId(member.GetGUID());

        memberData.Authenticated = false;
        memberData.SorEligible = false;

        memberData.Name = member.GetName();
        memberData.Note = member.GetPublicNote();
        if (sendOfficerNote)
            memberData.OfficerNote = member.GetOfficerNote();

    }

    roster.WelcomeText = m_motd;
    roster.InfoText = m_info;

    TC_LOG_DEBUG("guild", "SMSG_GUILD_ROSTER [{}]", session->GetPlayerInfo());
    session->SendPacket(roster.Write());
}

void Guild::SendQueryResponse(WorldSession* session)
{
    WorldPackets::Guild::QueryGuildInfoResponse response;
    response.GuildGuid = GetGUID();
    response.Info.emplace();

    response.Info->GuildGUID = GetGUID();
    response.Info->VirtualRealmAddress = GetVirtualRealmAddress();

    response.Info->EmblemStyle = m_emblemInfo.GetStyle();
    response.Info->EmblemColor = m_emblemInfo.GetColor();
    response.Info->BorderStyle = m_emblemInfo.GetBorderStyle();
    response.Info->BorderColor = m_emblemInfo.GetBorderColor();
    response.Info->BackgroundColor = m_emblemInfo.GetBackgroundColor();

    for (RankInfo const& rankInfo : m_ranks)
        response.Info->Ranks.emplace_back(AsUnderlyingType(rankInfo.GetId()), AsUnderlyingType(rankInfo.GetOrder()), rankInfo.GetName());

    response.Info->GuildName = m_name;

    session->SendPacket(response.Write());
    TC_LOG_DEBUG("guild", "SMSG_GUILD_QUERY_RESPONSE [{}]", session->GetPlayerInfo());
}

void Guild::SendGuildRankInfo(WorldSession* session) const
{
    WorldPackets::Guild::GuildRanks ranks;

    ranks.Ranks.reserve(_GetRanksSize());

    for (RankInfo const& rankInfo : m_ranks)
    {
        WorldPackets::Guild::GuildRankData rankData;

        rankData.RankID = AsUnderlyingType(rankInfo.GetId());
        rankData.RankOrder = AsUnderlyingType(rankInfo.GetOrder());
        rankData.Flags = rankInfo.GetRights();
        rankData.WithdrawGoldLimit = (rankInfo.GetId() == GuildRankId::GuildMaster ? (-1) : int32(rankInfo.GetBankMoneyPerDay() / GOLD));
        rankData.RankName = rankInfo.GetName();

        for (uint8 j = 0; j < GUILD_BANK_MAX_TABS; ++j)
        {
            rankData.TabFlags[j] = uint32(rankInfo.GetBankTabRights(j));
            rankData.TabWithdrawItemLimit[j] = uint32(rankInfo.GetBankTabSlotsPerDay(j));
        }

        ranks.Ranks.push_back(rankData);
    }

    session->SendPacket(ranks.Write());
    TC_LOG_DEBUG("guild", "SMSG_GUILD_RANK [{}]", session->GetPlayerInfo());
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
                if (!(achievement->Flags & ACHIEVEMENT_FLAG_GUILD) || GetAchievementMgr().HasAchieved(achievementId))
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

        GetAchievementMgr().SendAllTrackedCriterias(player, criteriaIds);
        member->SetTrackedCriteriaIds(std::move(criteriaIds));
    }
}

void Guild::HandleGetAchievementMembers(WorldSession* session, uint32 achievementId) const
{
    GetAchievementMgr().SendAchievementMembers(session->GetPlayer(), achievementId);
}

void Guild::HandleSetMOTD(WorldSession* session, std::string_view motd)
{
    if (m_motd == motd)
        return;

    // Player must have rights to set MOTD
    if (!_HasRankRight(session->GetPlayer(), GR_RIGHT_SETMOTD))
        SendCommandResult(session, GUILD_COMMAND_EDIT_MOTD, ERR_GUILD_PERMISSIONS);
    else
    {
        m_motd = motd;

        sScriptMgr->OnGuildMOTDChanged(this, m_motd);

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_MOTD);
        stmt->setString(0, m_motd);
        stmt->setUInt64(1, m_id);
        CharacterDatabase.Execute(stmt);

        SendEventMOTD(session, true);
    }
}

void Guild::HandleSetInfo(WorldSession* session, std::string_view info)
{
    if (m_info == info)
        return;

    // Player must have rights to set guild's info
    if (_HasRankRight(session->GetPlayer(), GR_RIGHT_MODIFY_GUILD_INFO))
    {
        m_info = info;

        sScriptMgr->OnGuildInfoChanged(this, m_info);

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_INFO);
        stmt->setString(0, m_info);
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

        SendQueryResponse(session);
    }
}

void Guild::HandleSetNewGuildMaster(WorldSession* session, std::string_view name, bool isSelfPromote)
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

        RankInfo const* oldRank = GetRankInfo(newGuildMaster->GetRankId());

        if (oldRank->GetOrder() != GuildRankOrder(1) // only second highest rank can take over guild
            || uint32(oldGuildMaster->GetInactiveDays()) < GUILD_MASTER_DETHRONE_INACTIVE_DAYS)
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

    _SetLeader(trans, *newGuildMaster);
    oldGuildMaster->ChangeRank(trans, _GetLowestRankId());

    SendEventNewLeader(newGuildMaster, oldGuildMaster, isSelfPromote);

    CharacterDatabase.CommitTransaction(trans);
}

void Guild::HandleSetBankTabInfo(WorldSession* session, uint8 tabId, std::string_view name, std::string_view icon)
{
    BankTab* tab = GetBankTab(tabId);
    if (!tab)
    {
        TC_LOG_ERROR("guild", "Guild::HandleSetBankTabInfo: Player {} trying to change bank tab info from unexisting tab {}.",
                       session->GetPlayerInfo(), tabId);
        return;
    }

    tab->SetInfo(name, icon);

    WorldPackets::Guild::GuildEventTabModified packet;
    packet.Tab = tabId;
    packet.Name = name;
    packet.Icon = icon;
    BroadcastPacket(packet.Write());
}

void Guild::HandleSetMemberNote(WorldSession* session, std::string_view note, ObjectGuid guid, bool isPublic)
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

void Guild::HandleSetRankInfo(WorldSession* session, GuildRankId rankId, std::string_view name, uint32 rights, uint32 moneyPerDay, std::array<GuildBankRightsAndSlots, GUILD_BANK_MAX_TABS> const& rightsAndSlots)
{
    // Only leader can modify ranks
    if (!_IsLeader(session->GetPlayer()))
        SendCommandResult(session, GUILD_COMMAND_CHANGE_RANK, ERR_GUILD_PERMISSIONS);
    else if (RankInfo* rankInfo = GetRankInfo(rankId))
    {
        rankInfo->SetName(name);
        rankInfo->SetRights(rights);
        _SetRankBankMoneyPerDay(rankId, moneyPerDay * GOLD);

        for (auto itr = rightsAndSlots.begin(); itr != rightsAndSlots.end(); ++itr)
            _SetRankBankTabRightsAndSlots(rankId, *itr);

        WorldPackets::Guild::GuildEventRankChanged packet;
        packet.RankID = AsUnderlyingType(rankId);
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

void Guild::HandleInviteMember(WorldSession* session, std::string_view name)
{
    Player* pInvitee = ObjectAccessor::FindPlayerByName(name);
    if (!pInvitee)
    {
        SendCommandResult(session, GUILD_COMMAND_INVITE_PLAYER, ERR_GUILD_PLAYER_NOT_FOUND_S, name);
        return;
    }

    Player* player = session->GetPlayer();
    // Do not show invitations from ignored players
    if (pInvitee->GetSocial()->HasIgnore(player->GetGUID(), player->GetSession()->GetAccountGUID()))
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

    TC_LOG_DEBUG("guild", "Player {} invited {} to join his Guild", player->GetName(), pInvitee->GetName());

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
    TC_LOG_DEBUG("guild", "SMSG_GUILD_INVITE [{}]", pInvitee->GetName());
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

    sCalendarMgr->RemovePlayerGuildEventsAndSignups(player->GetGUID(), GetId());

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
        }
    }
    else
    {
        _LogEvent(GUILD_EVENT_LOG_LEAVE_GUILD, player->GetGUID().GetCounter());
        SendEventPlayerLeft(GetMember(player->GetGUID()));

        SendCommandResult(session, GUILD_COMMAND_LEAVE_GUILD, ERR_GUILD_COMMAND_SUCCESS, m_name);

        CharacterDatabaseTransaction trans(nullptr);
        DeleteMember(trans, player->GetGUID(), false, false);
    }
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
        if (member->IsRank(GuildRankId::GuildMaster))
            SendCommandResult(session, GUILD_COMMAND_REMOVE_PLAYER, ERR_GUILD_LEADER_LEAVE);
        // Do not allow to remove player with the same rank or higher
        else
        {
            Member* memberMe = GetMember(player->GetGUID());
            RankInfo const* myRank = GetRankInfo(memberMe->GetRankId());
            RankInfo const* targetRank = GetRankInfo(member->GetRankId());

            if (!memberMe || targetRank->GetOrder() <= myRank->GetOrder())
                SendCommandResult(session, GUILD_COMMAND_REMOVE_PLAYER, ERR_GUILD_RANK_TOO_HIGH_S, name);
            else
            {
                _LogEvent(GUILD_EVENT_LOG_UNINVITE_PLAYER, player->GetGUID().GetCounter(), guid.GetCounter());
                SendEventPlayerLeft(member, memberMe, true);

                SendCommandResult(session, GUILD_COMMAND_REMOVE_PLAYER, ERR_GUILD_COMMAND_SUCCESS, name);

                // After call to DeleteMember pointer to member becomes invalid
                CharacterDatabaseTransaction trans(nullptr);
                DeleteMember(trans, guid, false, true);
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
        RankInfo const* myRank = GetRankInfo(memberMe->GetRankId());
        RankInfo const* oldRank = GetRankInfo(member->GetRankId());
        GuildRankId newRankId;
        if (demote)
        {
            // Player can demote only lower rank members
            if (oldRank->GetOrder() <= myRank->GetOrder())
            {
                SendCommandResult(session, type, ERR_GUILD_RANK_TOO_HIGH_S, name);
                return;
            }
            // Lowest rank cannot be demoted
            RankInfo const* newRank = GetRankInfo(GuildRankOrder(AsUnderlyingType(oldRank->GetOrder()) + 1));
            if (!newRank)
            {
                SendCommandResult(session, type, ERR_GUILD_RANK_TOO_LOW_S, name);
                return;
            }

            newRankId = newRank->GetId();
        }
        else
        {
            // Allow to promote only to lower rank than member's rank
            // memberMe->GetRankId() + 1 is the highest rank that current player can promote to
            if (GuildRankOrder(AsUnderlyingType(oldRank->GetOrder()) - 1) <= myRank->GetOrder())
            {
                SendCommandResult(session, type, ERR_GUILD_RANK_TOO_HIGH_S, name);
                return;
            }

            newRankId = ASSERT_NOTNULL(GetRankInfo(GuildRankOrder(AsUnderlyingType(oldRank->GetOrder()) - 1)))->GetId();
        }

        CharacterDatabaseTransaction trans(nullptr);
        member->ChangeRank(trans, newRankId);
        _LogEvent(demote ? GUILD_EVENT_LOG_DEMOTE_PLAYER : GUILD_EVENT_LOG_PROMOTE_PLAYER, player->GetGUID().GetCounter(), member->GetGUID().GetCounter(), AsUnderlyingType(newRankId));
        //_BroadcastEvent(demote ? GE_DEMOTION : GE_PROMOTION, ObjectGuid::Empty, player->GetName().c_str(), name.c_str(), _GetRankName(newRankId).c_str());
    }
}

void Guild::HandleSetMemberRank(WorldSession* session, ObjectGuid targetGuid, ObjectGuid setterGuid, GuildRankOrder rank)
{
    Player* player = session->GetPlayer();
    Member* member = GetMember(targetGuid);
    if (!member)
        return;
    GuildRankRights rights = GR_RIGHT_PROMOTE;
    GuildCommandType type = GUILD_COMMAND_PROMOTE_PLAYER;

    RankInfo const* oldRank = GetRankInfo(member->GetRankId());
    RankInfo const* newRank = GetRankInfo(rank);
    if (!oldRank || !newRank)
        return;

    if (rank > oldRank->GetOrder())
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

    SendGuildRanksUpdate(setterGuid, targetGuid, newRank->GetId());
}

void Guild::HandleAddNewRank(WorldSession* session, std::string_view name)
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

void Guild::HandleRemoveRank(WorldSession* session, GuildRankOrder rankOrder)
{
    // Cannot remove rank if total count is minimum allowed by the client or is not leader
    if (_GetRanksSize() <= GUILD_RANKS_MIN_COUNT || !_IsLeader(session->GetPlayer()))
        return;

    auto rankItr = std::find_if(m_ranks.begin(), m_ranks.end(), [rankOrder](RankInfo const& rank)
    {
        return rank.GetOrder() == rankOrder;
    });

    if (rankItr == m_ranks.end())
        return;

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    // Delete bank rights for rank
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_BANK_RIGHTS_FOR_RANK);
    stmt->setUInt64(0, m_id);
    stmt->setUInt8(1, AsUnderlyingType(rankItr->GetId()));
    trans->Append(stmt);

    // Delete rank
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_RANK);
    stmt->setUInt64(0, m_id);
    stmt->setUInt8(1, AsUnderlyingType(rankItr->GetId()));
    trans->Append(stmt);

    m_ranks.erase(rankItr);

    // correct order of other ranks
    for (RankInfo& otherRank : m_ranks)
    {
        if (otherRank.GetOrder() < rankOrder)
            continue;

        otherRank.SetOrder(GuildRankOrder(AsUnderlyingType(otherRank.GetOrder()) - 1));

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_RANK_ORDER);
        stmt->setUInt8(0, AsUnderlyingType(otherRank.GetOrder()));
        stmt->setUInt8(1, AsUnderlyingType(otherRank.GetId()));
        stmt->setUInt64(2, m_id);
        trans->Append(stmt);
    }

    CharacterDatabase.CommitTransaction(trans);

    WorldPackets::Guild::GuildEventRanksUpdated eventPacket;
    BroadcastPacket(eventPacket.Write());
}

void Guild::HandleShiftRank(WorldSession* session, GuildRankOrder rankOrder, bool shiftUp)
{
    // Only leader can modify ranks
    if (!_IsLeader(session->GetPlayer()))
        return;

    GuildRankOrder otherRankOrder = GuildRankOrder(AsUnderlyingType(rankOrder) + (shiftUp ? -1 : 1));

    RankInfo* rankInfo = GetRankInfo(rankOrder);
    RankInfo* otherRankInfo = GetRankInfo(otherRankOrder);
    if (!rankInfo || !otherRankInfo)
        return;

    // can't shift guild master rank (rank id = 0) - there's already a client-side limitation for it so that's just a safe-guard
    if (rankInfo->GetId() == GuildRankId::GuildMaster || otherRankInfo->GetId() == GuildRankId::GuildMaster)
        return;

    rankInfo->SetOrder(otherRankOrder);
    otherRankInfo->SetOrder(rankOrder);

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_RANK_ORDER);
    stmt->setUInt8(0, AsUnderlyingType(rankInfo->GetOrder()));
    stmt->setUInt8(1, AsUnderlyingType(rankInfo->GetId()));
    stmt->setUInt64(2, m_id);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_RANK_ORDER);
    stmt->setUInt8(0, AsUnderlyingType(otherRankInfo->GetOrder()));
    stmt->setUInt8(1, AsUnderlyingType(otherRankInfo->GetId()));
    stmt->setUInt64(2, m_id);
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);

    // force client to re-request SMSG_GUILD_RANKS
    BroadcastPacket(WorldPackets::Guild::GuildEventRanksUpdated().Write());
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

    if (m_bankMoney > GUILD_BANK_MONEY_LIMIT - amount)
    {
        if (!cashFlow)
            SendCommandResult(session, GUILD_COMMAND_MOVE_ITEM, ERR_GUILD_TOO_MUCH_MONEY);
        return;
    }

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    _ModifyBankMoney(trans, amount, true);
    if (!cashFlow)
    {
        player->ModifyMoney(-int64(amount));
        player->SaveInventoryAndGoldToDB(trans);
    }

    _LogBankEvent(trans, cashFlow ? GUILD_BANK_LOG_CASH_FLOW_DEPOSIT : GUILD_BANK_LOG_DEPOSIT_MONEY, uint8(0), player->GetGUID().GetCounter(), amount);
    CharacterDatabase.CommitTransaction(trans);

    SendEventBankMoneyChanged();

    if (player->GetSession()->HasPermission(rbac::RBAC_PERM_LOG_GM_TRADE))
    {
        sLog->OutCommand(player->GetSession()->GetAccountId(),
            "GM {} (Account: {}) deposit money (Amount: {}) to guild bank (Guild ID {})",
            player->GetName(), player->GetSession()->GetAccountId(), amount, m_id);
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

   if (_GetMemberRemainingMoney(*member) < int64(amount))   // Check if we have enough slot/money today
       return false;

    // Call script after validation and before money transfer.
    sScriptMgr->OnGuildMemberWitdrawMoney(this, player, amount, repair);

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    // Add money to player (if required)
    if (!repair)
    {
        if (!player->ModifyMoney(amount))
            return false;

        player->SaveInventoryAndGoldToDB(trans);
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
        TC_LOG_DEBUG("guild", "{} successfully deleted", GetGUID().ToString());
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

    TC_LOG_DEBUG("guild", "SMSG_GUILD_PARTY_STATE_RESPONSE [{}]", session->GetPlayerInfo());
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
    std::list<EventLogEntry> const& eventLog = m_eventLog.GetGuildLog();

    WorldPackets::Guild::GuildEventLogQueryResults packet;
    packet.Entry.reserve(eventLog.size());

    for (EventLogEntry const& entry : eventLog)
        entry.WritePacket(packet);

    session->SendPacket(packet.Write());

    TC_LOG_DEBUG("guild", "SMSG_GUILD_EVENT_LOG_QUERY_RESULTS [{}]", session->GetPlayerInfo());
}

void Guild::SendNewsUpdate(WorldSession* session) const
{
    std::list<NewsLogEntry> const& newsLog = m_newsLog.GetGuildLog();

    WorldPackets::Guild::GuildNews packet;
    packet.NewsEvents.reserve(newsLog.size());

    for (NewsLogEntry const& newsLogEntry : newsLog)
    {
        newsLogEntry.WritePacket(packet);
        packet.NewsEvents.back().CompletedDate += session->GetTimezoneOffset();
    }

    session->SendPacket(packet.Write());

    TC_LOG_DEBUG("guild", "SMSG_GUILD_NEWS_UPDATE [{}]", session->GetPlayerInfo());
}

void Guild::SendBankLog(WorldSession* session, uint8 tabId) const
{
    // GUILD_BANK_MAX_TABS send by client for money log
    if (tabId < _GetPurchasedTabsSize() || tabId == GUILD_BANK_MAX_TABS)
    {
        std::list<BankEventLogEntry> const& bankEventLog = m_bankEventLog[tabId].GetGuildLog();

        WorldPackets::Guild::GuildBankLogQueryResults packet;
        packet.Tab = int32(tabId);

        //if (tabId == GUILD_BANK_MAX_TABS && hasCashFlow)
        //    packet.WeeklyBonusMoney.Set(uint64(weeklyBonusMoney));

        packet.Entry.reserve(bankEventLog.size());
        for (BankEventLogEntry const& entry : bankEventLog)
            entry.WritePacket(packet);

        session->SendPacket(packet.Write());

        TC_LOG_DEBUG("guild", "SMSG_GUILD_BANK_LOG_QUERY_RESULT [{}] TabId: {}", session->GetPlayerInfo(), tabId);
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

    GuildRankId rankId = member->GetRankId();

    WorldPackets::Guild::GuildPermissionsQueryResults queryResult;
    queryResult.RankID = AsUnderlyingType(rankId);
    queryResult.WithdrawGoldLimit = _GetRankBankMoneyPerDay(rankId);
    queryResult.Flags = _GetRankRights(rankId);
    queryResult.NumTabs = _GetPurchasedTabsSize();
    queryResult.Tab.reserve(GUILD_BANK_MAX_TABS);

    for (uint8 tabId = 0; tabId < GUILD_BANK_MAX_TABS; ++tabId)
    {
        WorldPackets::Guild::GuildPermissionsQueryResults::GuildRankTabPermissions& tabPerm = queryResult.Tab.emplace_back();
        tabPerm.Flags = _GetRankBankTabRights(rankId, tabId);
        tabPerm.WithdrawItemLimit = _GetMemberRemainingSlots(*member, tabId);
    }

    session->SendPacket(queryResult.Write());
    TC_LOG_DEBUG("guild", "SMSG_GUILD_PERMISSIONS_QUERY_RESULTS [{}] Rank: {}", session->GetPlayerInfo(), uint32(rankId));
}

void Guild::SendMoneyInfo(WorldSession* session) const
{
    Member const* member = GetMember(session->GetPlayer()->GetGUID());
    if (!member)
        return;

    int64 amount = _GetMemberRemainingMoney(*member);

    WorldPackets::Guild::GuildBankRemainingWithdrawMoney packet;
    packet.RemainingWithdrawMoney = amount;
    session->SendPacket(packet.Write());

    TC_LOG_DEBUG("guild", "SMSG_GUILD_BANK_MONEY_WITHDRAWN [{}] Money: " SI64FMTD, session->GetPlayerInfo(), amount);
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

    GetAchievementMgr().SendAllData(player);

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
        TC_LOG_DEBUG("guild", "SMSG_GUILD_EVENT_MOTD [{}] ", session->GetPlayerInfo());
    }
}

void Guild::SendEventNewLeader(Member* newLeader, Member* oldLeader, bool isSelfPromoted) const
{
    WorldPackets::Guild::GuildEventNewLeader eventPacket;
    eventPacket.SelfPromoted = isSelfPromoted;

    club::v1::MemberRoleChangedNotification memberRoleChangeNotification;
    memberRoleChangeNotification.set_club_id(GetId());

    if (newLeader)
    {
        eventPacket.NewLeaderGUID = newLeader->GetGUID();
        eventPacket.NewLeaderName = newLeader->GetName();
        eventPacket.NewLeaderVirtualRealmAddress = GetVirtualRealmAddress();

        // Owner/GuildMaster role is always 1.
        club::v1::RoleAssignment* newLeaderRoleAssignment = memberRoleChangeNotification.add_assignment();
        newLeaderRoleAssignment->set_allocated_member_id(Battlenet::Services::ClubMembershipService::CreateClubMemberId(newLeader->GetGUID()).release());
        newLeaderRoleAssignment->add_role(AsUnderlyingType(ClubRoleIdentifier::Owner));
    }

    if (oldLeader)
    {
        eventPacket.OldLeaderGUID = oldLeader->GetGUID();
        eventPacket.OldLeaderName = oldLeader->GetName();
        eventPacket.OldLeaderVirtualRealmAddress = GetVirtualRealmAddress();

        // Non owner members in guilds get the lowest club/community role after a guild master change.
        club::v1::RoleAssignment* oldLeaderRoleAssignment = memberRoleChangeNotification.add_assignment();
        oldLeaderRoleAssignment->set_allocated_member_id(Battlenet::Services::ClubMembershipService::CreateClubMemberId(oldLeader->GetGUID()).release());
        oldLeaderRoleAssignment->add_role(AsUnderlyingType(ClubRoleIdentifier::Member));
    }

    eventPacket.Write();

    // We have to send old guild and new club packets so we use a custom broadcast loop here.
    BroadcastWorker([&](Player const* member)
    {
        member->SendDirectMessage(eventPacket.GetRawPacket());
        Battlenet::WorldserverService<club::v1::ClubListener>(member->GetSession()).OnMemberRoleChanged(&memberRoleChangeNotification, true, true);
    });
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

    eventPacket.Write();

    Player* leaverPlayer = leaver->FindConnectedPlayer();

    // Notify the removed member of club removal.
    if (leaverPlayer)
    {
        leaverPlayer->SendDirectMessage(eventPacket.GetRawPacket());

        // Unsubscribe the removed player from the club to ensure interface updates.
        club::v1::UnsubscribeNotification unsubscribeNotification;
        unsubscribeNotification.set_club_id(GetId());
        Battlenet::WorldserverService<club::v1::ClubListener>(leaverPlayer->GetSession()).OnUnsubscribe(&unsubscribeNotification, true, true);

        // Finally notify the client about leaving the club.
        club::v1::membership::ClubRemovedNotification clubRemovedNotification;
        clubRemovedNotification.set_club_id(GetId());
        clubRemovedNotification.set_reason(isRemoved
            ? club::v1::ClubRemovedReason::CLUB_REMOVED_REASON_MEMBER_KICKED
            : club::v1::ClubRemovedReason::CLUB_REMOVED_REASON_MEMBER_LEFT);
        clubRemovedNotification.set_allocated_member_id(Battlenet::Services::ClubMembershipService::CreateClubMemberId(leaver->GetGUID()).release());
        Battlenet::WorldserverService<club::v1::membership::ClubMembershipListener>(leaverPlayer->GetSession()).OnClubRemoved(&clubRemovedNotification, true, true);
    }

    club::v1::MemberRemovedNotification memberRemovedNotification;
    memberRemovedNotification.set_club_id(GetId());

    club::v1::MemberRemovedAssignment* removedMemberAssignment = memberRemovedNotification.add_member();
    removedMemberAssignment->set_allocated_id(Battlenet::Services::ClubMembershipService::CreateClubMemberId(leaver->GetGUID()).release());
    removedMemberAssignment->set_reason(isRemoved
        ? club::v1::ClubRemovedReason::CLUB_REMOVED_REASON_MEMBER_KICKED
        : club::v1::ClubRemovedReason::CLUB_REMOVED_REASON_MEMBER_LEFT);

    // We have to send old guild and new club packets so we use a custom broadcast loop here.
    BroadcastWorker([&](Player const* member)
    {
        // Notify other guild members.
        member->SendDirectMessage(eventPacket.GetRawPacket());
        Battlenet::WorldserverService<::bgs::protocol::club::v1::ClubListener>(member->GetSession()).OnMemberRemoved(&memberRemovedNotification, true, true);
    }, leaverPlayer);
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
        TC_LOG_ERROR("guild", "Guild {} has invalid emblem colors (Background: {}, Border: {}, Emblem: {}), skipped.",
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

    m_bankTabs.clear();
    m_bankTabs.reserve(purchasedTabs);
    for (uint8 i = 0; i < purchasedTabs; ++i)
        m_bankTabs.emplace_back(m_id, i);
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

    auto [memberIt, isNew] = m_members.try_emplace(playerGuid, m_id, playerGuid, GuildRankId(fields[2].GetUInt8()));
    if (!isNew)
    {
        TC_LOG_ERROR("guild", "Tried to add {} to guild '{}'. Member already exists.", playerGuid.ToString(), m_name);
        return false;
    }

    Member& member = memberIt->second;
    if (!member.LoadFromDB(fields))
    {
        CharacterDatabaseTransaction trans(nullptr);
        Guild::_DeleteMemberFromDB(trans, lowguid);
        m_members.erase(memberIt);
        return false;
    }

    sCharacterCache->UpdateCharacterGuildId(playerGuid, GetId());
    return true;
}

void Guild::LoadBankRightFromDB(Field* fields)
{
                                           // tabId              rights               slots
    GuildBankRightsAndSlots rightsAndSlots(fields[1].GetUInt8(), fields[3].GetInt8(), fields[4].GetInt32());
                                  // rankId
    _SetRankBankTabRightsAndSlots(GuildRankId(fields[2].GetUInt8()), rightsAndSlots, false);
}

bool Guild::LoadEventLogFromDB(Field* fields)
{
    if (m_eventLog.CanInsert())
    {
        m_eventLog.LoadEvent(
            m_id,                                       // guild id
            fields[1].GetUInt32(),                      // guid
            fields[6].GetInt64(),                       // timestamp
            GuildEventLogTypes(fields[2].GetUInt8()),   // event type
            fields[3].GetUInt64(),                      // player guid 1
            fields[4].GetUInt64(),                      // player guid 2
            fields[5].GetUInt8());                      // rank
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
        LogHolder<BankEventLogEntry>& bankLog = m_bankEventLog[tabId];
        if (bankLog.CanInsert())
        {
            uint32 guid = fields[2].GetUInt32();
            GuildBankEventLogTypes eventType = GuildBankEventLogTypes(fields[3].GetUInt8());
            if (BankEventLogEntry::IsMoneyEvent(eventType))
            {
                if (!isMoneyTab)
                {
                    TC_LOG_ERROR("guild", "GuildBankEventLog ERROR: MoneyEvent(LogGuid: {}, Guild: {}) does not belong to money tab ({}), ignoring...", guid, m_id, dbTabId);
                    return false;
                }
            }
            else if (isMoneyTab)
            {
                TC_LOG_ERROR("guild", "GuildBankEventLog ERROR: non-money event (LogGuid: {}, Guild: {}) belongs to money tab, ignoring...", guid, m_id);
                return false;
            }
            bankLog.LoadEvent(
                m_id,                                   // guild id
                guid,                                   // guid
                fields[8].GetInt64(),                   // timestamp
                dbTabId,                                // tab id
                eventType,                              // event type
                fields[4].GetUInt64(),                  // player guid
                fields[5].GetUInt64(),                  // item or money
                fields[6].GetUInt16(),                  // itam stack count
                fields[7].GetUInt8());                  // dest tab id
        }
    }
    return true;
}

void Guild::LoadGuildNewsLogFromDB(Field* fields)
{
    if (!m_newsLog.CanInsert())
        return;

    m_newsLog.LoadEvent(
    m_id,                                               // guild id
    fields[1].GetUInt32(),                              // guid
    fields[6].GetInt64(),                               // timestamp //64 bits?
    GuildNews(fields[2].GetUInt8()),                    // type
    ObjectGuid::Create<HighGuid::Player>(fields[3].GetUInt64()), // player guid
    fields[4].GetUInt32(),                              // Flags
    fields[5].GetUInt32());                             // value
}

void Guild::LoadBankTabFromDB(Field* fields)
{
    uint8 tabId = fields[1].GetUInt8();
    if (tabId >= _GetPurchasedTabsSize())
        TC_LOG_ERROR("guild", "Invalid tab (tabId: {}) in guild bank, skipped.", tabId);
    else
        m_bankTabs[tabId].LoadFromDB(fields);
}

bool Guild::LoadBankItemFromDB(Field* fields)
{
    uint8 tabId = fields[54].GetUInt8();
    if (tabId >= _GetPurchasedTabsSize())
    {
        TC_LOG_ERROR("guild", "Invalid tab for item (GUID: {}, id: #{}) in guild bank, skipped.",
            fields[0].GetUInt32(), fields[1].GetUInt32());
        return false;
    }
    return m_bankTabs[tabId].LoadItemFromDB(fields);
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
        TC_LOG_ERROR("guild", "Guild {} has invalid number of ranks, creating new...", m_id);
        broken_ranks = true;
    }
    else
    {
        for (uint8 rankId = 0; rankId < ranks; ++rankId)
        {
            RankInfo* rankInfo = GetRankInfo(GuildRankId(rankId));
            if (rankInfo->GetId() != GuildRankId(rankId))
            {
                TC_LOG_ERROR("guild", "Guild {} has broken rank id {}, creating default set of ranks...", m_id, rankId);
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
    for (auto& [guid, member] : m_members)
        if (!GetRankInfo(member.GetRankId()))
            member.ChangeRank(trans, _GetLowestRankId());

    // Repair the structure of the guild.
    // If the guildmaster doesn't exist or isn't member of the guild
    // attempt to promote another member.
    Member* leader = GetMember(m_leaderGuid);
    if (!leader)
    {
        CharacterDatabaseTransaction dummy(nullptr);
        if (DeleteMember(dummy, m_leaderGuid))
            return false;
    }
    else if (!leader->IsRank(GuildRankId::GuildMaster))
        _SetLeader(trans, *leader);

    // Check config if multiple guildmasters are allowed
    if (!sConfigMgr->GetBoolDefault("Guild.AllowMultipleGuildMaster", false))
        for (auto& [guid, member] : m_members)
            if (member.GetRankId() == GuildRankId::GuildMaster && !member.IsSamePlayer(m_leaderGuid))
                member.ChangeRank(trans, GetRankInfo(GuildRankOrder(1))->GetId());

    if (trans->GetSize() > 0)
        CharacterDatabase.CommitTransaction(trans);
    _UpdateAccountsNumber();
    return true;
}

// Broadcasts
void Guild::BroadcastToGuild(WorldSession* session, bool officerOnly, std::string_view msg, uint32 language) const
{
    if (session && session->GetPlayer() && _HasRankRight(session->GetPlayer(), officerOnly ? GR_RIGHT_OFFCHATSPEAK : GR_RIGHT_GCHATSPEAK))
    {
        WorldPackets::Chat::Chat packet;
        packet.Initialize(officerOnly ? CHAT_MSG_OFFICER : CHAT_MSG_GUILD, Language(language), session->GetPlayer(), nullptr, msg);
        WorldPacket const* data = packet.Write();
        for (auto const& [guid, member] : m_members)
            if (Player* player = member.FindConnectedPlayer())
                if (player->GetSession() && _HasRankRight(player, officerOnly ? GR_RIGHT_OFFCHATLISTEN : GR_RIGHT_GCHATLISTEN) &&
                    !player->GetSocial()->HasIgnore(session->GetPlayer()->GetGUID(), session->GetAccountGUID()))
                    player->SendDirectMessage(data);
    }
}

void Guild::BroadcastAddonToGuild(WorldSession* session, bool officerOnly, std::string_view msg, std::string_view prefix, bool isLogged) const
{
    if (session && session->GetPlayer() && _HasRankRight(session->GetPlayer(), officerOnly ? GR_RIGHT_OFFCHATSPEAK : GR_RIGHT_GCHATSPEAK))
    {
        WorldPackets::Chat::Chat packet;
        packet.Initialize(officerOnly ? CHAT_MSG_OFFICER : CHAT_MSG_GUILD, isLogged ? LANG_ADDON_LOGGED : LANG_ADDON, session->GetPlayer(), nullptr, msg, 0, "", DEFAULT_LOCALE, prefix);
        WorldPacket const* data = packet.Write();
        for (auto const& [guid, member] : m_members)
            if (Player* player = member.FindPlayer())
                if (player->GetSession() && _HasRankRight(player, officerOnly ? GR_RIGHT_OFFCHATLISTEN : GR_RIGHT_GCHATLISTEN) &&
                    !player->GetSocial()->HasIgnore(session->GetPlayer()->GetGUID(), session->GetAccountGUID()) &&
                    player->GetSession()->IsAddonRegistered(prefix))
                        player->SendDirectMessage(data);
    }
}

void Guild::BroadcastPacketToRank(WorldPacket const* packet, GuildRankId rankId) const
{
    for (auto const& [guid, member] : m_members)
        if (member.IsRank(rankId))
            if (Player* player = member.FindConnectedPlayer())
                player->SendDirectMessage(packet);
}

void Guild::BroadcastPacket(WorldPacket const* packet) const
{
    for (auto const& [guid, member] : m_members)
        if (Player* player = member.FindConnectedPlayer())
            player->SendDirectMessage(packet);
}

std::vector<Player*> Guild::GetMembersTrackingCriteria(uint32 criteriaId) const
{
    std::vector<Player*> members;
    for (auto const& [guid, member] : m_members)
        if (member.IsTrackingCriteriaId(criteriaId))
            if (Player* player = member.FindPlayer())
                members.push_back(player);

    return members;
}

void Guild::MassInviteToEvent(WorldSession* session, uint32 minLevel, uint32 maxLevel, GuildRankOrder minRank)
{
    WorldPackets::Calendar::CalendarCommunityInvite packet;

    for (auto const& [guid, member] : m_members)
    {
        // not sure if needed, maybe client checks it as well
        if (packet.Invites.size() >= CALENDAR_MAX_INVITES)
        {
            if (Player* player = session->GetPlayer())
                sCalendarMgr->SendCalendarCommandResult(player->GetGUID(), CALENDAR_ERROR_INVITES_EXCEEDED);
            return;
        }

        if (guid == session->GetPlayer()->GetGUID())
            continue;

        uint32 level = sCharacterCache->GetCharacterLevelByGuid(guid);
        if (level < minLevel || level > maxLevel)
            continue;

        RankInfo const* rank = GetRankInfo(member.GetRankId());
        if (rank->GetOrder() > minRank)
            continue;

        packet.Invites.emplace_back(guid, level);
    }

    session->SendPacket(packet.Write());
}

// Members handling
bool Guild::AddMember(CharacterDatabaseTransaction trans, ObjectGuid guid, Optional<GuildRankId> rankId /*= {}*/)
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
    if (!rankId)
        rankId = _GetLowestRankId();

    auto [memberIt, isNew] = m_members.try_emplace(guid, m_id, guid, *rankId);
    if (!isNew)
    {
        TC_LOG_ERROR("guild", "Tried to add {} to guild '{}'. Member already exists.", guid.ToString(), m_name);
        return false;
    }

    Member& member = memberIt->second;
    std::string name;
    if (player)
    {
        player->SetInGuild(m_id);
        player->SetGuildIdInvited(UI64LIT(0));
        player->SetGuildRank(AsUnderlyingType(*rankId));
        player->SetGuildLevel(GetLevel());
        member.SetStats(player);
        SendLoginInfo(player->GetSession());
        name = player->GetName();
    }
    else
    {
        member.ResetFlags();

        bool ok = false;
        // Player must exist
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_DATA_FOR_GUILD);
        stmt->setUInt64(0, lowguid);
        if (PreparedQueryResult result = CharacterDatabase.Query(stmt))
        {
            Field* fields = result->Fetch();
            name = fields[0].GetString();
            member.SetStats(
                name,
                fields[1].GetUInt8(),
                fields[2].GetUInt8(),
                fields[3].GetUInt8(),
                fields[4].GetUInt8(),
                fields[5].GetUInt16(),
                fields[6].GetUInt32(),
                0);

            ok = member.CheckStats();
        }

        if (!ok)
        {
            m_members.erase(memberIt);
            return false;
        }
        sCharacterCache->UpdateCharacterGuildId(guid, GetId());
    }

    member.SaveToDB(trans);

    _UpdateAccountsNumber();
    _LogEvent(GUILD_EVENT_LOG_JOIN_GUILD, lowguid);

    WorldPackets::Guild::GuildEventPlayerJoined joinNotificationPacket;
    joinNotificationPacket.Guid = guid;
    joinNotificationPacket.Name = name;
    joinNotificationPacket.VirtualRealmAddress = GetVirtualRealmAddress();
    joinNotificationPacket.Write();

    // Notify the added member with new club data.
    if (player)
    {
        player->SendDirectMessage(joinNotificationPacket.GetRawPacket());

        club::v1::membership::ClubAddedNotification clubAddedNotification;
        clubAddedNotification.mutable_membership()->set_allocated_member_id(Battlenet::Services::ClubMembershipService::CreateClubMemberId(guid).release());

        club::v1::ClubDescription* guildClub = clubAddedNotification.mutable_membership()->mutable_club();
        guildClub->set_id(GetId());
        guildClub->set_allocated_type(Battlenet::Services::ClubService::CreateGuildClubType().release());
        guildClub->set_name(GetName());
        guildClub->set_privacy_level(club::v1::PrivacyLevel::PRIVACY_LEVEL_OPEN);
        guildClub->set_visibility_level(club::v1::VISIBILITY_LEVEL_PRIVATE);
        guildClub->set_member_count(GetMembersCount());

        // Set the club owner, guild master in this case.
        club::v1::MemberDescription* guildLeaderDescription = guildClub->add_leader();
        guildLeaderDescription->set_allocated_id(Battlenet::Services::ClubMembershipService::CreateClubMemberId(GetLeaderGUID()).release());

        // Date is in microseconds.
        guildClub->set_creation_time(
            std::chrono::duration_cast<std::chrono::microseconds>(SystemTimePoint::clock::from_time_t(GetCreatedDate()).time_since_epoch()).count());
        guildClub->set_timezone("");
        guildClub->set_locale("");

        Battlenet::WorldserverService<club::v1::membership::ClubMembershipListener>(player->GetSession()).OnClubAdded(&clubAddedNotification, true, true);
    }

    club::v1::MemberAddedNotification memberAddedNotification;
    memberAddedNotification.set_club_id(GetId());

    club::v1::Member* addedMember = memberAddedNotification.add_member();
    addedMember->set_allocated_id(Battlenet::Services::ClubMembershipService::CreateClubMemberId(guid).release());
    if (HasAnyRankRight(member.GetRankId(), GuildRankRights(GR_RIGHT_OFFCHATLISTEN | GR_RIGHT_OFFCHATSPEAK)))
        addedMember->add_role(AsUnderlyingType(ClubRoleIdentifier::Moderator));
    else
        addedMember->add_role(AsUnderlyingType(ClubRoleIdentifier::Member));
    addedMember->set_presence_level(club::v1::PresenceLevel::PRESENCE_LEVEL_RICH);
    addedMember->set_whisper_level(club::v1::WhisperLevel::WHISPER_LEVEL_OPEN);
    addedMember->set_note("");
    addedMember->set_active(member.IsOnline());

    // We have to send old guild and new club packets so we use a custom broadcast loop here.
    BroadcastWorker([&](Player const* otherMember)
    {
        // Notify other online guild members.
        otherMember->SendDirectMessage(joinNotificationPacket.GetRawPacket());
        Battlenet::WorldserverService<club::v1::ClubListener>(otherMember->GetSession()).OnMemberAdded(&memberAddedNotification, true, true);
    }, player);

    // Call scripts if member was succesfully added (and stored to database)
    sScriptMgr->OnGuildAddMember(this, player, AsUnderlyingType(*rankId));

    return true;
}

bool Guild::DeleteMember(CharacterDatabaseTransaction trans, ObjectGuid guid, bool isDisbanding, bool isKicked)
{
    // Guild master can be deleted when loading guild and guid doesn't exist in characters table
    // or when he is removed from guild by gm command
    if (m_leaderGuid == guid && !isDisbanding)
    {
        Member* oldLeader = nullptr;
        Member* newLeader = nullptr;
        for (auto& [memberGuid, member] : m_members)
        {
            if (memberGuid == guid)
                oldLeader = &member;
            else if (!newLeader || newLeader->GetRankId() > member.GetRankId())
                newLeader = &member;
        }

        if (!newLeader)
        {
            Disband();
            return true;
        }

        _SetLeader(trans, *newLeader);

        // If leader does not exist (at guild loading with deleted leader) do not send broadcasts
        if (oldLeader)
        {
            SendEventNewLeader(newLeader, oldLeader, true);
            SendEventPlayerLeft(oldLeader);
        }
    }
    // Call script on remove before member is actually removed from guild (and database)
    sScriptMgr->OnGuildRemoveMember(this, guid, isDisbanding, isKicked);

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

    if (m_members.empty())
    {
        Disband();
        return true;
    }

    return false;
}

bool Guild::ChangeMemberRank(CharacterDatabaseTransaction trans, ObjectGuid guid, GuildRankId newRank)
{
    if (GetRankInfo(newRank))                             // Validate rank (allow only existing ranks)
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
    return m_members.find(guid) != m_members.end();
}

uint64 Guild::GetMemberAvailableMoneyForRepairItems(ObjectGuid guid) const
{
    Member const* member = GetMember(guid);
    if (!member)
        return 0;

    return std::min(m_bankMoney, static_cast<uint64>(_GetMemberRemainingMoney(*member)));
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
void Guild::SetBankTabText(uint8 tabId, std::string_view text)
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

Guild::Guild::RankInfo const* Guild::GetRankInfo(GuildRankId rankId) const
{
    auto rankItr = std::find_if(m_ranks.begin(), m_ranks.end(), [rankId](RankInfo const& rank)
    {
        return rank.GetId() == rankId;
    });

    return rankItr != m_ranks.end() ? &*rankItr : nullptr;
}

Guild::RankInfo* Guild::GetRankInfo(GuildRankId rankId)
{
    auto rankItr = std::find_if(m_ranks.begin(), m_ranks.end(), [rankId](RankInfo const& rank)
    {
        return rank.GetId() == rankId;
    });

    return rankItr != m_ranks.end() ? &*rankItr : nullptr;
}

Guild::Guild::RankInfo const* Guild::GetRankInfo(GuildRankOrder rankOrder) const
{
    auto rankItr = std::find_if(m_ranks.begin(), m_ranks.end(), [rankOrder](RankInfo const& rank)
    {
        return rank.GetOrder() == rankOrder;
    });

    return rankItr != m_ranks.end() ? &*rankItr : nullptr;
}

Guild::Guild::RankInfo* Guild::GetRankInfo(GuildRankOrder rankOrder)
{
    auto rankItr = std::find_if(m_ranks.begin(), m_ranks.end(), [rankOrder](RankInfo const& rank)
    {
        return rank.GetOrder() == rankOrder;
    });

    return rankItr != m_ranks.end() ? &*rankItr : nullptr;
}

bool Guild::_HasRankRight(Player const* player, uint32 right) const
{
    if (player)
        if (Member const* member = GetMember(player->GetGUID()))
            return (_GetRankRights(member->GetRankId()) & right) != GR_RIGHT_NONE;
    return false;
}

bool Guild::HasAnyRankRight(GuildRankId rankId, GuildRankRights rights) const
{
    return (_GetRankRights(rankId) & rights) != GR_RIGHT_NONE;
}

void Guild::_DeleteMemberFromDB(CharacterDatabaseTransaction trans, ObjectGuid::LowType lowguid)
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_MEMBER);
    stmt->setUInt64(0, lowguid);
    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

// Private methods
void Guild::_CreateNewBankTab()
{
    uint8 tabId = _GetPurchasedTabsSize();                      // Next free id
    m_bankTabs.emplace_back(m_id, tabId);

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

void Guild::_CreateDefaultGuildRanks(CharacterDatabaseTransaction trans, LocaleConstant loc)
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

bool Guild::_CreateRank(CharacterDatabaseTransaction trans, std::string_view name, uint32 rights)
{
    if (m_ranks.size() >= GUILD_RANKS_MAX_COUNT)
        return false;

    uint8 newRankId = [&]()
    {
        uint8 freeRankId = 0;
        while (GetRankInfo(GuildRankId(freeRankId)))
            ++freeRankId;

        return freeRankId;
    }();

    // Ranks represent sequence 0, 1, 2, ... where 0 means guildmaster
    RankInfo info(m_id, GuildRankId(newRankId), GuildRankOrder(m_ranks.size()), name, rights, 0);
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
    std::unordered_set<uint32> accountsIdSet;
    for (auto const& [guid, member] : m_members)
        accountsIdSet.insert(member.GetAccountId());

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
        return member->IsRank(GuildRankId::GuildMaster);
    return false;
}

void Guild::_DeleteBankItems(CharacterDatabaseTransaction trans, bool removeItemsFromDB)
{
    for (uint8 tabId = 0; tabId < _GetPurchasedTabsSize(); ++tabId)
        m_bankTabs[tabId].Delete(trans, removeItemsFromDB);

    m_bankTabs.clear();
}

bool Guild::_ModifyBankMoney(CharacterDatabaseTransaction trans, uint64 amount, bool add)
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

void Guild::_SetLeader(CharacterDatabaseTransaction trans, Member& leader)
{
    bool isInTransaction = bool(trans);
    if (!isInTransaction)
        trans = CharacterDatabase.BeginTransaction();

    m_leaderGuid = leader.GetGUID();
    leader.ChangeRank(trans, GuildRankId::GuildMaster);

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_LEADER);
    stmt->setUInt64(0, m_leaderGuid.GetCounter());
    stmt->setUInt64(1, m_id);
    trans->Append(stmt);

    if (!isInTransaction)
        CharacterDatabase.CommitTransaction(trans);
}

void Guild::_SetRankBankMoneyPerDay(GuildRankId rankId, uint32 moneyPerDay)
{
    if (RankInfo* rankInfo = GetRankInfo(rankId))
        rankInfo->SetBankMoneyPerDay(moneyPerDay);
}

void Guild::_SetRankBankTabRightsAndSlots(GuildRankId rankId, GuildBankRightsAndSlots rightsAndSlots, bool saveToDB)
{
    if (rightsAndSlots.GetTabId() >= _GetPurchasedTabsSize())
        return;

    if (RankInfo* rankInfo = GetRankInfo(rankId))
        rankInfo->SetBankTabSlotsAndRights(rightsAndSlots, saveToDB);
}

inline std::string Guild::_GetRankName(GuildRankId rankId) const
{
    if (RankInfo const* rankInfo = GetRankInfo(rankId))
        return rankInfo->GetName();
    return "<unknown>";
}

inline uint32 Guild::_GetRankRights(GuildRankId rankId) const
{
    if (RankInfo const* rankInfo = GetRankInfo(rankId))
        return rankInfo->GetRights();
    return 0;
}

inline uint32 Guild::_GetRankBankMoneyPerDay(GuildRankId rankId) const
{
    if (RankInfo const* rankInfo = GetRankInfo(rankId))
        return rankInfo->GetBankMoneyPerDay();
    return 0;
}

inline int32 Guild::_GetRankBankTabSlotsPerDay(GuildRankId rankId, uint8 tabId) const
{
    if (tabId < _GetPurchasedTabsSize())
        if (RankInfo const* rankInfo = GetRankInfo(rankId))
            return rankInfo->GetBankTabSlotsPerDay(tabId);
    return 0;
}

inline int8 Guild::_GetRankBankTabRights(GuildRankId rankId, uint8 tabId) const
{
    if (RankInfo const* rankInfo = GetRankInfo(rankId))
        return rankInfo->GetBankTabRights(tabId);
    return 0;
}

inline int32 Guild::_GetMemberRemainingSlots(Member const& member, uint8 tabId) const
{
    GuildRankId rankId = member.GetRankId();
    if (rankId == GuildRankId::GuildMaster)
        return static_cast<int32>(GUILD_WITHDRAW_SLOT_UNLIMITED);
    if ((_GetRankBankTabRights(rankId, tabId) & GUILD_BANK_RIGHT_VIEW_TAB) != 0)
    {

        int32 remaining = _GetRankBankTabSlotsPerDay(rankId, tabId) - member.GetBankTabWithdrawValue(tabId);
        if (remaining > 0)
            return remaining;

    }
    return 0;
}

inline int64 Guild::_GetMemberRemainingMoney(Member const& member) const
{
    GuildRankId rankId = member.GetRankId();
    if (rankId == GuildRankId::GuildMaster)
        return std::numeric_limits<int64>::max();

    if ((_GetRankRights(rankId) & (GR_RIGHT_WITHDRAW_REPAIR | GR_RIGHT_WITHDRAW_GOLD)) != 0)
    {
        int64 remaining = _GetRankBankMoneyPerDay(rankId) - member.GetBankMoneyWithdrawValue();
        if (remaining > 0)
            return remaining;
    }
    return 0;
}

inline void Guild::_UpdateMemberWithdrawSlots(CharacterDatabaseTransaction trans, ObjectGuid guid, uint8 tabId)
{
    if (Member* member = GetMember(guid))
        member->UpdateBankTabWithdrawValue(trans, tabId, 1);
}

inline bool Guild::_MemberHasTabRights(ObjectGuid guid, uint8 tabId, int32 rights) const
{
    if (Member const* member = GetMember(guid))
    {
        // Leader always has full rights
        if (member->IsRank(GuildRankId::GuildMaster) || m_leaderGuid == guid)
            return true;
        return (_GetRankBankTabRights(member->GetRankId(), tabId) & rights) == rights;
    }
    return false;
}

// Add new event log record
inline void Guild::_LogEvent(GuildEventLogTypes eventType, ObjectGuid::LowType playerGuid1, ObjectGuid::LowType playerGuid2, uint8 newRank)
{
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    m_eventLog.AddEvent(trans, m_id, m_eventLog.GetNextGUID(), eventType, playerGuid1, playerGuid2, newRank);
    CharacterDatabase.CommitTransaction(trans);

    sScriptMgr->OnGuildEvent(this, uint8(eventType), playerGuid1, playerGuid2, newRank);
}

// Add new bank event log record
void Guild::_LogBankEvent(CharacterDatabaseTransaction trans, GuildBankEventLogTypes eventType, uint8 tabId, ObjectGuid::LowType lowguid, uint64 itemOrMoney, uint16 itemStackCount, uint8 destTabId)
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
    LogHolder<BankEventLogEntry>& pLog = m_bankEventLog[tabId];
    pLog.AddEvent(trans, m_id, pLog.GetNextGUID(), eventType, dbTabId, lowguid, itemOrMoney, itemStackCount, destTabId);

    sScriptMgr->OnGuildBankEvent(this, uint8(eventType), tabId, lowguid, itemOrMoney, itemStackCount, destTabId);
}

inline Item* Guild::_GetItem(uint8 tabId, uint8 slotId) const
{
    if (BankTab const* tab = GetBankTab(tabId))
        return tab->GetItem(slotId);
    return nullptr;
}

inline void Guild::_RemoveItem(CharacterDatabaseTransaction trans, uint8 tabId, uint8 slotId)
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
        InventoryResult mergeAttemptResult = Guild::_DoItemsMove(pSrc, pDest, false);
        if (mergeAttemptResult != EQUIP_ERR_OK) // Item could not be merged
        {
            // 6.2. Try to swap items
            // 6.2.1. Initialize destination item
            if (!pDest->InitItem())
            {
                pSrc->SendEquipError(mergeAttemptResult, pSrc->GetItem(false));
                return;
            }

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

InventoryResult Guild::_DoItemsMove(MoveItemData* pSrc, MoveItemData* pDest, bool sendError, uint32 splitedAmount)
{
    Item* pDestItem = pDest->GetItem();
    bool swap = (pDestItem != nullptr);

    Item* pSrcItem = pSrc->GetItem(splitedAmount != 0);
    // 1. Can store source item in destination
    InventoryResult destResult = pDest->CanStore(pSrcItem, swap, sendError);
    if (destResult != EQUIP_ERR_OK)
        return destResult;

    // 2. Can store destination item in source
    if (swap)
    {
        InventoryResult srcResult = pSrc->CanStore(pDestItem, true, true);
        if (srcResult != EQUIP_ERR_OK)
            return srcResult;
    }

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
    return EQUIP_ERR_OK;
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
            itemInfo.EnchantmentID = int32(tabItem ? tabItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT) : 0);
            itemInfo.Charges = int32(tabItem ? abs(tabItem->GetSpellCharges()) : 0);
            itemInfo.OnUseEnchantmentID = int32(tabItem ? tabItem->GetEnchantmentId(USE_ENCHANTMENT_SLOT) : 0);
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

        for (auto const& [guid, member] : m_members)
        {
            if (!_MemberHasTabRights(member.GetGUID(), tabId, GUILD_BANK_RIGHT_VIEW_TAB))
                continue;

            Player* player = member.FindPlayer();
            if (!player)
                continue;

            packet.WithdrawalsRemaining = _GetMemberRemainingSlots(member, tabId);
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
    packet.WithdrawalsRemaining = _GetMemberRemainingSlots(*member, tabId);
    packet.Tab = int32(tabId);
    packet.FullUpdate = fullUpdate;

    // TabInfo
    if (fullUpdate)
    {
        packet.TabInfo.reserve(_GetPurchasedTabsSize());
        for (uint8 i = 0; i < _GetPurchasedTabsSize(); ++i)
        {
            WorldPackets::Guild::GuildBankTabInfo& tabInfo = packet.TabInfo.emplace_back();
            tabInfo.TabIndex = i;
            tabInfo.Name = m_bankTabs[i].GetName();
            tabInfo.Icon = m_bankTabs[i].GetIcon();
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
                    WorldPackets::Guild::GuildBankItemInfo& itemInfo = packet.ItemInfo.emplace_back();

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
                }
            }
        }
    }

    session->SendPacket(packet.Write());
}

void Guild::SendGuildRanksUpdate(ObjectGuid setterGuid, ObjectGuid targetGuid, GuildRankId rank)
{
    Member* member = GetMember(targetGuid);
    ASSERT(member);

    WorldPackets::Guild::GuildSendRankChange rankChange;
    rankChange.Officer = setterGuid;
    rankChange.Other = targetGuid;
    rankChange.RankID = AsUnderlyingType(rank);
    rankChange.Promote = (rank < member->GetRankId());
    rankChange.Write();

    club::v1::MemberRoleChangedNotification memberRoleChangeNotification;
    memberRoleChangeNotification.set_club_id(GetId());

    club::v1::RoleAssignment* changedRoleAssignment = memberRoleChangeNotification.add_assignment();
    changedRoleAssignment->set_allocated_member_id(Battlenet::Services::ClubMembershipService::CreateClubMemberId(targetGuid).release());
    if (rank == GuildRankId::GuildMaster)
        changedRoleAssignment->add_role(AsUnderlyingType(ClubRoleIdentifier::Owner));
    else if (HasAnyRankRight(rank, GuildRankRights(GR_RIGHT_OFFCHATLISTEN | GR_RIGHT_OFFCHATSPEAK)))
        changedRoleAssignment->add_role(AsUnderlyingType(ClubRoleIdentifier::Moderator));
    else
        changedRoleAssignment->add_role(AsUnderlyingType(ClubRoleIdentifier::Member));

    BroadcastWorker([&](Player const* memberPlayer)
    {
        memberPlayer->SendDirectMessage(rankChange.GetRawPacket());
        Battlenet::WorldserverService<club::v1::ClubListener>(memberPlayer->GetSession()).OnMemberRoleChanged(&memberRoleChangeNotification, true, true);
    });

    CharacterDatabaseTransaction trans;
    member->ChangeRank(trans, rank);

    TC_LOG_DEBUG("network", "SMSG_GUILD_RANKS_UPDATE [Broadcast] Target: {}, Issuer: {}, RankId: {}",
        targetGuid.ToString(), setterGuid.ToString(), uint32(rank));
}

void Guild::ResetTimes(bool weekly)
{
    for (auto& [guid, member] : m_members)
    {
        member.ResetValues(weekly);
        if (Player* player = member.FindPlayer())
        {
            WorldPackets::Guild::GuildMemberDailyReset packet; // tells the client to request bank withdrawal limit
            player->GetSession()->SendPacket(packet.Write());
        }
    }
}

void Guild::AddGuildNews(uint8 type, ObjectGuid guid, uint32 flags, uint32 value)
{
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    NewsLogEntry& news = m_newsLog.AddEvent(trans, m_id, m_newsLog.GetNextGUID(), GuildNews(type), guid, flags, value);
    CharacterDatabase.CommitTransaction(trans);

    BroadcastWorker([&](Player const* receiver)
    {
        WorldPackets::Guild::GuildNews newsPacket;
        newsPacket.NewsEvents.reserve(1);
        news.WritePacket(newsPacket);
        newsPacket.NewsEvents.back().CompletedDate += receiver->GetSession()->GetTimezoneOffset();

        receiver->SendDirectMessage(newsPacket.Write());
    });
}

bool Guild::HasAchieved(uint32 achievementId) const
{
    return GetAchievementMgr().HasAchieved(achievementId);
}

void Guild::UpdateCriteria(CriteriaType type, uint64 miscValue1, uint64 miscValue2, uint64 miscValue3, WorldObject const* ref, Player* player)
{
    GetAchievementMgr().UpdateCriteria(type, miscValue1, miscValue2, miscValue3, ref, player);
}

void Guild::HandleNewsSetSticky(WorldSession* session, uint32 newsId, bool sticky)
{
    std::list<NewsLogEntry>& newsLog = m_newsLog.GetGuildLog();
    auto itr = newsLog.begin();
    while (itr != newsLog.end() && itr->GetGUID() != newsId)
        ++itr;

    if (itr == newsLog.end())
    {
        TC_LOG_DEBUG("guild", "HandleNewsSetSticky: [{}] requested unknown newsId {} - Sticky: {}",
            session->GetPlayerInfo(), newsId, sticky);
        return;
    }

    itr->SetSticky(sticky);

    TC_LOG_DEBUG("guild", "HandleNewsSetSticky: [{}] changed newsId {} sticky to {}",
        session->GetPlayerInfo(), newsId, sticky);

    WorldPackets::Guild::GuildNews newsPacket;
    newsPacket.NewsEvents.reserve(1);
    itr->WritePacket(newsPacket);
    newsPacket.NewsEvents.back().CompletedDate += session->GetTimezoneOffset();
    session->SendPacket(newsPacket.Write());
}
