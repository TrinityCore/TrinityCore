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
#include "CharacterCache.h"
#include "Chat.h"
#include "Config.h"
#include "DatabaseEnv.h"
#include "GuildFinderMgr.h"
#include "GuildMgr.h"
#include "GuildPackets.h"
#include "Language.h"
#include "Log.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SocialMgr.h"
#include "SpellAuraEffects.h"
#include "World.h"
#include "WorldSession.h"
#include "Group.h"
#include "Battleground.h"
#include "ReputationMgr.h"

#define MAX_GUILD_BANK_TAB_TEXT_LEN 500
#define EMBLEM_PRICE 10 * GOLD

std::string _GetGuildEventString(GuildEvents event)
{
    switch (event)
    {
        case GE_PROMOTION:
            return "Member promotion";
        case GE_DEMOTION:
            return "Member demotion";
        case GE_MOTD:
            return "Guild MOTD";
        case GE_JOINED:
            return "Member joined";
        case GE_LEFT:
            return "Member left";
        case GE_REMOVED:
            return "Member removed";
        case GE_LEADER_IS:
            return "Leader is";
        case GE_LEADER_CHANGED:
            return "Leader changed";
        case GE_DISBANDED:
            return "Guild disbanded";
        case GE_TABARDCHANGE:
            return "Tabard change";
        case GE_RANK_UPDATED:
            return "Rank updated";
        case GE_RANK_DELETED:
            return "Rank deleted";
        case GE_SIGNED_ON:
            return "Member signed on";
        case GE_SIGNED_OFF:
            return "Member signed off";
        case GE_GUILDBANKBAGSLOTS_CHANGED:
            return "Bank bag slots changed";
        case GE_BANK_TAB_PURCHASED:
            return "Bank tab purchased";
        case GE_BANK_TAB_UPDATED:
            return "Bank tab updated";
        case GE_BANK_MONEY_SET:
            return "Bank money set";
        case GE_BANK_TAB_AND_MONEY_UPDATED:
            return "Bank money changed";
        case GE_BANK_TEXT_CHANGED:
            return "Bank tab text changed";
        default:
            break;
    }
    return "<None>";
}

inline uint32 _GetGuildBankTabPrice(uint8 tabId)
{
    switch (tabId)
    {
        case 0: return 100;
        case 1: return 250;
        case 2: return 500;
        case 3: return 1000;
        case 4: return 2500;
        case 5: return 5000;
        default: return 0;
    }
}

void Guild::SendCommandResult(WorldSession* session, GuildCommandType type, GuildCommandError errCode, std::string const& param)
{
    // Note: SMSG_GUILD_COMMAND_RESULT and SMSG_GUILD_COMMAND_RESULT_2 do exactly the same in the client, they just have different structures.
    // There's no particular reason why we use SMSG_GUILD_COMMAND_RESULT_2, this one is processed inmediately as it is read from the client.
    // SMSG_GUILD_COMMAND_RESULT is a JAM opcode
    WorldPackets::Guild::GuildCommandResult result;

    result.Command = type;
    result.Name = param;
    result.Result = errCode;
    session->SendPacket(result.Write());

    TC_LOG_DEBUG("guild", "SMSG_GUILD_COMMAND_RESULT [%s]: Type: %u, code: %u, param: %s", session->GetPlayerInfo().c_str(), type, errCode, param.c_str());
}

void Guild::SendSaveEmblemResult(WorldSession* session, GuildEmblemError errCode)
{
    WorldPacket data(MSG_SAVE_GUILD_EMBLEM, 4);
    data << uint32(errCode);
    session->SendPacket(&data);

    TC_LOG_DEBUG("guild", "MSG_SAVE_GUILD_EMBLEM [%s] Code: %u", session->GetPlayerInfo().c_str(), errCode);
}

// LogHolder
Guild::LogHolder::~LogHolder()
{
    // Cleanup
    for (GuildLog::iterator itr = m_log.begin(); itr != m_log.end(); ++itr)
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
    stmt->setUInt32(0, m_guildId);
    stmt->setUInt32(1, m_guid);
    trans->Append(stmt);

    uint8 index = 0;
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_EVENTLOG);
    stmt->setUInt32(  index, m_guildId);
    stmt->setUInt32(++index, m_guid);
    stmt->setUInt8 (++index, uint8(m_eventType));
    stmt->setUInt32(++index, m_playerGuid1);
    stmt->setUInt32(++index, m_playerGuid2);
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
    eventEntry.TransactionDate = uint32(GameTime::GetGameTime() - m_timestamp);
    eventEntry.RankID = uint8(m_newRank);
    packet.Entry.push_back(eventEntry);
}

// BankEventLogEntry
void Guild::BankEventLogEntry::SaveToDB(CharacterDatabaseTransaction& trans) const
{
    uint8 index = 0;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_BANK_EVENTLOG);
    stmt->setUInt32(  index, m_guildId);
    stmt->setUInt32(++index, m_guid);
    stmt->setUInt8 (++index, m_bankTabId);
    trans->Append(stmt);

    index = 0;
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_BANK_EVENTLOG);
    stmt->setUInt32(  index, m_guildId);
    stmt->setUInt32(++index, m_guid);
    stmt->setUInt8 (++index, m_bankTabId);
    stmt->setUInt8 (++index, uint8(m_eventType));
    stmt->setUInt32(++index, m_playerGuid);
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

void Guild::NewsLogEntry::SaveToDB(CharacterDatabaseTransaction& trans) const
{
    uint8 index = 0;
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_NEWS);
    stmt->setUInt32(  index, m_guildId);
    stmt->setUInt32(++index, GetGUID());
    stmt->setUInt8 (++index, GetType());
    stmt->setUInt32(++index, GetPlayerGuid().GetCounter());
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
    newsEvent.Data[0] = int32(GetValue());

    //for (uint8 i = 0; i < 2; i++)
    //    newsEvent.Data[i] =

    //newsEvent.MemberList.push_back(MemberGuid);

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
    stmt->setUInt32(0, m_guildId);
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
            TC_LOG_ERROR("guild", "Guild %u has broken Tab %u for rank %u. Created default tab.", m_guildId, i, m_rankId);

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_BANK_RIGHT);
        stmt->setUInt32(0, m_guildId);
        stmt->setUInt8(1, i);
        stmt->setUInt8(2, m_rankId);
        stmt->setUInt8(3, rightsAndSlots.GetRights());
        stmt->setUInt32(4, rightsAndSlots.GetSlots());
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
    stmt->setUInt32(2, m_guildId);
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
    stmt->setUInt32(2, m_guildId);
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
    stmt->setUInt32(2, m_guildId);
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
        stmt->setUInt32(0, m_guildId);
        stmt->setUInt8 (1, guildBR.GetTabId());
        stmt->setUInt8 (2, m_rankId);
        stmt->setUInt8 (3, guildBR.GetRights());
        stmt->setUInt32(4, guildBR.GetSlots());
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
    uint8 slotId = fields[14].GetUInt8();
    ObjectGuid::LowType itemGuid = fields[15].GetUInt32();
    uint32 itemEntry = fields[16].GetUInt32();
    if (slotId >= GUILD_BANK_MAX_SLOTS)
    {
        TC_LOG_ERROR("guild", "Invalid slot for item (GUID: %u, id: %u) in guild bank, skipped.", itemGuid, itemEntry);
        return false;
    }

    ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemEntry);
    if (!proto)
    {
        TC_LOG_ERROR("guild", "Unknown item (GUID: %u, id: %u) in guild bank, skipped.", itemGuid, itemEntry);
        return false;
    }

    Item* pItem = NewItemOrBag(proto);
    if (!pItem->LoadFromDB(itemGuid, ObjectGuid::Empty, fields, itemEntry))
    {
        TC_LOG_ERROR("guild", "Item (GUID %u, id: %u) not found in item_instance, deleting from guild bank!", itemGuid, itemEntry);

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_NONEXISTENT_GUILD_BANK_ITEM);
        stmt->setUInt32(0, m_guildId);
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
        if (Item* pItem = m_items[slotId])
        {
            pItem->RemoveFromWorld();
            if (removeItemsFromDB)
                pItem->DeleteFromDB(trans);
            delete pItem;
            pItem = nullptr;
        }
    }
}

void Guild::BankTab::WriteInfoPacket(WorldPacket& data) const
{
    data << m_name;
    data << m_icon;
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
    stmt->setUInt32(2, m_guildId);
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
    stmt->setUInt32(1, m_guildId);
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
    stmt->setUInt32(0, m_guildId);
    stmt->setUInt8 (1, m_tabId);
    stmt->setUInt8 (2, slotId);
    trans->Append(stmt);

    if (item)
    {
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_BANK_ITEM);
        stmt->setUInt32(0, m_guildId);
        stmt->setUInt8 (1, m_tabId);
        stmt->setUInt8 (2, slotId);
        stmt->setUInt32(3, item->GetGUID().GetCounter());
        trans->Append(stmt);

        item->SetGuidValue(ITEM_FIELD_CONTAINED, ObjectGuid::Empty);
        item->SetGuidValue(ITEM_FIELD_OWNER, ObjectGuid::Empty);
        item->FSetState(ITEM_NEW);
        item->SaveToDB(trans);                                 // Not in inventory and can be saved standalone
    }

    return true;
}

void Guild::BankTab::SendText(Guild const* guild, WorldSession* session) const
{
    WorldPackets::Guild::GuildBankTextQueryResult textQuery;
    textQuery.Text = m_text;
    textQuery.Tab = m_tabId;

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
    m_logoutTime(::GameTime::GetGameTime()),
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
    m_zoneId    = player->GetZoneId();
    _gender     = player->GetByteValue(PLAYER_BYTES_3, PLAYER_BYTES_3_OFFSET_GENDER);
    m_accountId = player->GetSession()->GetAccountId();
    m_achievementPoints = player->GetAchievementPoints();
    m_totalReputation = player->GetReputation(FACTION_GUILD);
}

void Guild::Member::SetStats(std::string const& name, uint8 level, uint8 _class, uint32 zoneId, uint32 accountId, uint32 achievementPoints, uint32 reputation)
{
    m_name      = name;
    m_level     = level;
    m_class     = _class;
    m_zoneId    = zoneId;
    m_accountId = accountId;
    m_achievementPoints = achievementPoints;
    m_totalReputation = reputation;
}

void Guild::Member::SetPublicNote(std::string const& publicNote)
{
    if (m_publicNote == publicNote)
        return;

    m_publicNote = publicNote;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_MEMBER_PNOTE);
    stmt->setString(0, publicNote);
    stmt->setUInt32(1, m_guid.GetCounter());
    CharacterDatabase.Execute(stmt);
}

void Guild::Member::SetOfficerNote(std::string const& officerNote)
{
    if (m_officerNote == officerNote)
        return;

    m_officerNote = officerNote;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_MEMBER_OFFNOTE);
    stmt->setString(0, officerNote);
    stmt->setUInt32(1, m_guid.GetCounter());
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
    stmt->setUInt32(1, m_guid.GetCounter());
    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void Guild::Member::AddActivity(uint64 activity)
{
    m_totalActivity += activity;
    m_weekActivity += activity;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_MEMBER_ACTIVITY);
    stmt->setUInt64(0, m_totalActivity);
    stmt->setUInt64(1, m_weekActivity);
    stmt->setUInt32(2, m_guid.GetCounter());
    CharacterDatabase.Execute(stmt);
}

void Guild::Member::SaveToDB(CharacterDatabaseTransaction& trans) const
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_MEMBER);
    stmt->setUInt32(0, m_guildId);
    stmt->setUInt32(1, m_guid.GetCounter());
    stmt->setUInt8 (2, m_rankId);
    stmt->setString(3, m_publicNote);
    stmt->setString(4, m_officerNote);
    stmt->setUInt64(5, m_totalActivity);
    stmt->setUInt64(6, m_weekActivity);
    stmt->setUInt32(7, m_weekReputation);
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
             fields[17].GetUInt16(),                        // characters.zone
             fields[18].GetUInt32(),                        // characters.account
             fields[22].GetUInt32(),                        // characters.achievementPoint
             fields[23].GetUInt32());
    m_logoutTime = fields[19].GetUInt32();                  // characters.logout_time
    m_totalActivity = fields[20].GetUInt64();
    m_weekActivity = fields[21].GetUInt64();
    m_weekReputation = fields[24].GetUInt32();

    if (!CheckStats())
        return false;

    if (!m_zoneId)
    {
        TC_LOG_DEBUG("guild", "%s has broken zone-data", m_guid.ToString().c_str());
        m_zoneId = Player::GetZoneIdFromDB(m_guid);
    }

    LoadProfessionDataFromDB(m_guid);

    ResetFlags();
    return true;
}

void Guild::Member::LoadProfessionDataFromDB(ObjectGuid guid)
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_SKILLS);
    stmt->setUInt32(0, guid.GetCounter());
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    uint8 professionIndex = 0;
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint16 skill = fields[0].GetUInt16();
            uint16 value = fields[1].GetUInt16();
            uint16 max = fields[2].GetUInt16();

            SkillLineEntry const* skillLine = sSkillLineStore.LookupEntry(skill);
            if (!skillLine || skillLine->CategoryID != SKILL_CATEGORY_PROFESSION)
                continue;

            GuildMemberProfessionData profession(skill, max / 75, value);

            CharacterDatabasePreparedStatement* stmt2 = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_SPELL);
            stmt2->setUInt32(0, guid.GetCounter());
            PreparedQueryResult result2 = CharacterDatabase.Query(stmt2);

            if (result2)
            {
                do
                {
                    Field* fields2 = result2->Fetch();
                    uint32 spellId = fields2[0].GetUInt32();
                    bool disabled = fields2[2].GetBool();
                    if (disabled)
                        continue;

                    for (GuildProfession prof : sGuildMgr->GetGuildProfessionData(skill))
                    {
                        if (prof.SpellId == spellId || prof.AutoLearn)
                        {
                            uint16 index = prof.UniqueBits / 8;
                            uint8 offset = prof.UniqueBits % 8;
                            uint8 bit = 1 << offset;
                            profession.RecipeUniqueBits[index] |= bit;
                        }
                    }

                } while (result2->NextRow());

                m_professions[professionIndex] = profession;
                professionIndex++;
            }

        } while (result->NextRow());
    }
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
    return float(::GameTime::GetGameTime() - GetLogoutTime()) / float(DAY);
}

Player* Guild::Member::FindPlayer() const
{
    return ObjectAccessor::FindPlayer(m_guid);
}

Player* Guild::Member::FindConnectedPlayer() const
{
    return ObjectAccessor::FindConnectedPlayer(m_guid);
}

void Guild::Member::UpdateLogoutTime()
{
    m_logoutTime = ::GameTime::GetGameTime();
}

// Decreases amount of slots left for today.
void Guild::Member::UpdateBankTabWithdrawValue(CharacterDatabaseTransaction& trans, uint8 tabId, uint32 amount)
{
    m_bankWithdraw[tabId] += amount;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_MEMBER_WITHDRAW_TABS);
    stmt->setUInt32(0, m_guid.GetCounter());
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
        ResetWeekActivityAndReputation();
}

void Guild::Member::AddReputation(uint32 rep, Player *player)
{
    rep = std::min(rep, sWorld->getIntConfig(CONFIG_GUILD_WEEKLY_REP_CAP) - m_weekReputation);

    player->GetReputationMgr().ModifyReputation(sFactionStore.LookupEntry(FACTION_GUILD), rep);

    m_weekReputation += rep;
    m_totalReputation = player->GetReputation(FACTION_GUILD);

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_MEMBER_WEEK_REPUTATION);
    stmt->setUInt32(0, m_weekReputation);
    stmt->setUInt32(1, m_guid.GetCounter());
    CharacterDatabase.Execute(stmt);
}

void Guild::Member::ResetWeekActivityAndReputation()
{
    m_weekActivity = 0;
    m_weekReputation = 0;

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_RESET_GUILD_MEMBER_WEEK_ACTIVITY);
    stmt->setUInt32(0, m_guid.GetCounter());
    trans->Append(stmt);

    CharacterDatabasePreparedStatement* stmt2 = CharacterDatabase.GetPreparedStatement(CHAR_RESET_GUILD_MEMBER_WEEK_REPUTATION);
    stmt2->setUInt32(0, m_guid.GetCounter());
    trans->Append(stmt2);

    CharacterDatabase.CommitTransaction(trans);
}

void Guild::Member::UpdateProfessionData()
{
    Player* player = FindConnectedPlayer();
    if (!player)
        return;

    for (uint8 i = 0; i < GUILD_PROFESSION_COUNT; i++)
    {
        uint32 skillId = player->GetUInt32Value(PLAYER_PROFESSION_SKILL_LINE_1 + i);
        if (player->HasSkill(skillId))
        {
            m_professions[i].SkillId = skillId;
            m_professions[i].Rank = player->GetSkillValue(skillId);
            m_professions[i].Step = player->GetSkillStep(skillId);
            m_professions[i].RecipeUniqueBits.fill(0);

            for (GuildProfession prof : sGuildMgr->GetGuildProfessionData(skillId))
            {
                if (player->HasSpell(prof.SpellId))
                {
                    uint16 index = prof.UniqueBits / 8;
                    uint8 offset = prof.UniqueBits % 8;
                    uint8 bit = 1 << offset;
                    m_professions[i].RecipeUniqueBits[index] |= bit;
                }
            }
        }
        else
        {
            m_professions[i].SkillId = 0;
            m_professions[i].Step = 0;
            m_professions[i].Rank = 0;
            m_professions[i].RecipeUniqueBits.fill(0);
        }
    }
}

// EmblemInfo
void EmblemInfo::ReadPacket(WorldPacket& recv)
{
    recv >> m_style >> m_color >> m_borderStyle >> m_borderColor >> m_backgroundColor;
}

void EmblemInfo::LoadFromDB(Field* fields)
{
    m_style             = fields[3].GetUInt8();
    m_color             = fields[4].GetUInt8();
    m_borderStyle       = fields[5].GetUInt8();
    m_borderColor       = fields[6].GetUInt8();
    m_backgroundColor   = fields[7].GetUInt8();
}

void EmblemInfo::SaveToDB(ObjectGuid::LowType guildId) const
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_EMBLEM_INFO);
    stmt->setUInt32(0, m_style);
    stmt->setUInt32(1, m_color);
    stmt->setUInt32(2, m_borderStyle);
    stmt->setUInt32(3, m_borderColor);
    stmt->setUInt32(4, m_backgroundColor);
    stmt->setUInt32(5, guildId);
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
            "GM %s (Guid: %u) (Account: %u) deposit item: %s (Entry: %d Count: %u) to guild bank named: %s (Guild ID: %u)",
            m_pPlayer->GetName().c_str(), m_pPlayer->GetGUID().GetCounter(), m_pPlayer->GetSession()->GetAccountId(),
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
    m_id(0),
    m_leaderGuid(),
    m_createdDate(0),
    m_accountsNumber(0),
    m_bankMoney(0),
    _weeklyBonusMoney(0),
    m_eventLog(nullptr),
    m_newsLog(nullptr),
    _level(1),
    _experience(0),
    _todayExperience(0)
{
    memset(&m_bankEventLog, 0, (GUILD_BANK_MAX_TABS + 1) * sizeof(LogHolder*));

    m_achievementMgr = new AchievementMgr<Guild>(this);
    InitializeGuildChallengeRewards();
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

    delete m_achievementMgr;
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
    m_createdDate = ::GameTime::GetGameTime();
    _level = 1;
    _experience = 0;
    _todayExperience = 0;
    _CreateLogHolders();

    InitializeGuildChallengeRewards();

    TC_LOG_DEBUG("guild", "GUILD: creating guild [%s] for leader %s (%u)",
        name.c_str(), pLeader->GetName().c_str(), m_leaderGuid.GetCounter());

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_MEMBERS);
    stmt->setUInt32(0, m_id);
    trans->Append(stmt);

    uint8 index = 0;
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD);
    stmt->setUInt32(  index, m_id);
    stmt->setString(++index, name);
    stmt->setUInt32(++index, m_leaderGuid.GetCounter());
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
        _BroadcastEvent(GE_FOUNDER, ObjectGuid::Empty);
        sScriptMgr->OnGuildCreate(this, pLeader, name);
    }

    return ret;
}

// Disbands guild and deletes all related data from database
void Guild::Disband()
{
    // Call scripts before guild data removed from database
    sScriptMgr->OnGuildDisband(this);

    _BroadcastEvent(GE_DISBANDED, ObjectGuid::Empty);

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    // Remove all members
    while (!m_members.empty())
    {
        auto itr = m_members.begin();
        DeleteMember(trans, itr->second->GetGUID(), true);
    }

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD);
    stmt->setUInt32(0, m_id);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_RANKS);
    stmt->setUInt32(0, m_id);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_BANK_TABS);
    stmt->setUInt32(0, m_id);
    trans->Append(stmt);

    // Free bank tab used memory and delete items stored in them
    _DeleteBankItems(trans, true);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_BANK_ITEMS);
    stmt->setUInt32(0, m_id);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_BANK_RIGHTS);
    stmt->setUInt32(0, m_id);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_BANK_EVENTLOGS);
    stmt->setUInt32(0, m_id);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_EVENTLOGS);
    stmt->setUInt32(0, m_id);
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);

    sGuildFinderMgr->DeleteGuild(m_id);

    sGuildMgr->RemoveGuild(m_id);
}

void Guild::SaveToDB()
{
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_EXPERIENCE);
    stmt->setUInt32(0, GetLevel());
    stmt->setUInt64(1, GetExperience());
    stmt->setUInt64(2, GetTodayExperience());
    stmt->setUInt32(3, GetId());
    trans->Append(stmt);

    m_achievementMgr->SaveToDB(trans);

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
            case GUILD_MEMBER_DATA_PROFESSIONS:
                member->UpdateProfessionData();
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
    stmt->setUInt32(1, GetId());
    CharacterDatabase.Execute(stmt);

    WorldPackets::Guild::GuildNameChanged guildNameChanged;
    guildNameChanged.GuildGUID = GetGUID();
    guildNameChanged.GuildName = name;
    BroadcastPacket(guildNameChanged.Write());
    return true;
}

void Guild::HandleRoster(WorldSession* session)
{
     WorldPackets::Guild::GuildRoster roster;

    roster.NumAccounts = int32(m_accountsNumber);
    roster.CreateDate = uint32(m_createdDate);
    roster.GuildFlags = 0;
    roster.WeeklyRepCap = sWorld->getIntConfig(CONFIG_GUILD_WEEKLY_REP_CAP);
    roster.MemberData.reserve(m_members.size());

    for (std::pair<uint32 const, Guild::Member*> const& memberPair : m_members)
    {
        Member* member = memberPair.second;

        WorldPackets::Guild::GuildRosterMemberData memberData;

        memberData.Guid = member->GetGUID();
        memberData.RankID = int32(member->GetRankId());
        memberData.AreaID = int32(member->GetZoneId());
        memberData.PersonalAchievementPoints = int32(member->GetAchievementPoints());
        memberData.GuildReputation = int32(member->GetTotalReputation());
        memberData.LastSave = member->GetInactiveDays();
        memberData.GuildRepToCap = sWorld->getIntConfig(CONFIG_GUILD_WEEKLY_REP_CAP) - member->GetWeekReputation();

        for (uint8 i = 0; i < GUILD_PROFESSION_COUNT; i++)
        {
            GuildMemberProfessionData const& profData = member->GetProfessionData(i);
            memberData.Profession[i].DbID = profData.SkillId;
            memberData.Profession[i].Step = profData.Step;
            memberData.Profession[i].Rank = profData.Rank;
        }

        memberData.VirtualRealmAddress = 0;
        memberData.Status = member->GetFlags();
        memberData.Level = member->GetLevel();
        memberData.ClassID = member->GetClass();
        memberData.Gender = member->GetGender();

        memberData.Authenticated = false;
        memberData.SorEligible = false;

        memberData.Name = member->GetName();
        memberData.Note = member->GetPublicNote();
        memberData.OfficerNote = member->GetOfficerNote();

        memberData.TotalXP = member->GetTotalActivity();
        memberData.WeeklyXP = member->GetWeekActivity();

        roster.MemberData.push_back(memberData);
    }

    roster.WelcomeText = m_motd;
    roster.InfoText = m_info;

    TC_LOG_DEBUG("guild", "SMSG_GUILD_ROSTER [%s]", session->GetPlayerInfo().c_str());
    session->SendPacket(roster.Write());
}

void Guild::SendQueryResponse(WorldSession* session)
{
    WorldPackets::Guild::QueryGuildInfoResponse response;
    response.GuildGUID = GetGUID();
    response.GuildName = m_name;

    response.EmblemStyle = m_emblemInfo.GetStyle();
    response.EmblemColor = m_emblemInfo.GetColor();
    response.BorderStyle = m_emblemInfo.GetBorderStyle();
    response.BorderColor = m_emblemInfo.GetBorderColor();
    response.BackgroundColor = m_emblemInfo.GetBackgroundColor();

    response.RanksSize = _GetRanksSize();

    for (uint8 i = 0; i < GUILD_RANKS_MAX_COUNT; ++i)
    {
        WorldPackets::Guild::GuildInfoRank info;
        if (i < _GetRanksSize())
        {
            info.RankID = m_ranks[i].GetId();
            info.RankOrder = i;
            info.RankName = m_ranks[i].GetName();
        }
        response.Ranks[i] = info;
    }

    session->SendPacket(response.Write());
    TC_LOG_DEBUG("guild", "SMSG_QUERY_GUILD_INFO_RESPONSE [%s]", session->GetPlayerInfo().c_str());
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
        rankData.WithdrawGoldLimit = rankInfo->GetBankMoneyPerDay();
        rankData.RankName = rankInfo->GetName();

        for (uint8 j = 0; j < GUILD_BANK_MAX_TABS; ++j)
        {
            rankData.TabFlags[j] = uint32(rankInfo->GetBankTabRights(j));
            rankData.TabWithdrawItemLimit[j] = uint32(rankInfo->GetBankTabSlotsPerDay(j));
        }

        ranks.Ranks.push_back(rankData);
    }

    session->SendPacket(ranks.Write());
    TC_LOG_DEBUG("guild", "SMSG_GUILD_RANKS [%s]", session->GetPlayerInfo().c_str());
}

void Guild::HandleSetAchievementTracking(WorldSession* session, std::set<uint32> const& achievementIds)
{
    Player* player = session->GetPlayer();

    if (Member* member = GetMember(player->GetGUID()))
    {
        std::set<uint32> criteriaIds;

        for (std::set<uint32>::iterator achievementId = achievementIds.begin(); achievementId != achievementIds.end(); ++achievementId)
        {
            if (AchievementCriteriaEntryList const* cList = sAchievementMgr->GetAchievementCriteriaByAchievement(*achievementId))
            {
                for (AchievementCriteriaEntryList::const_iterator itr = cList->begin(); itr != cList->end(); ++itr)
                {
                    AchievementCriteriaEntry const* criteria = *itr;
                    criteriaIds.insert(criteria->ID);
                }
            }
        }

        member->SetTrackedCriteriaIds(criteriaIds);
        m_achievementMgr->SendAllTrackedCriterias(player, member->GetTrackedCriteriaIds());
    }
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
        stmt->setUInt32(1, m_id);
        CharacterDatabase.Execute(stmt);

        _BroadcastEvent(GE_MOTD, ObjectGuid::Empty, motd.c_str());
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
        stmt->setUInt32(1, m_id);
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
    _BroadcastEvent(GE_LEADER_CHANGED, ObjectGuid::Empty, player->GetName().c_str(), newGuildMaster->GetName().c_str());
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
    _BroadcastEvent(GE_BANK_TAB_UPDATED, ObjectGuid::Empty, std::to_string(tabId).c_str(), name.c_str(), icon.c_str());
}

void Guild::HandleSetMemberNote(WorldSession* session, std::string const& note, ObjectGuid guid, bool officer)
{
    // Player must have rights to set public/officer note
    if (!_HasRankRight(session->GetPlayer(), officer ? GR_RIGHT_EOFFNOTE : GR_RIGHT_EPNOTE))
        SendCommandResult(session, GUILD_COMMAND_PUBLIC_NOTE, ERR_GUILD_PERMISSIONS);
    else if (Member* member = GetMember(guid))
    {
        if (officer)
            member->SetOfficerNote(note);
        else
            member->SetPublicNote(note);

        SendMemberUpdateNote(note, guid, officer);
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
        _SetRankBankMoneyPerDay(rankId, moneyPerDay);

        for (auto itr = rightsAndSlots.begin(); itr != rightsAndSlots.end(); ++itr)
            _SetRankBankTabRightsAndSlots(rankId, *itr);

        _BroadcastEvent(GE_RANK_UPDATED, ObjectGuid::Empty, std::to_string(rankId).c_str(), name.c_str());
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

    // Do not get money for bank tabs that the GM bought, we had to buy them already.
    // This is just a speedup check, GetGuildBankTabPrice will return 0.
    if (tabId < GUILD_BANK_MAX_TABS - 2) // 7th tab is actually the 6th
    {
        uint32 tabCost = _GetGuildBankTabPrice(tabId) * GOLD;
        if (!tabCost)
            return;

        if (!player->HasEnoughMoney(uint64(tabCost)))                   // Should not happen, this is checked by client
            return;

        player->ModifyMoney(-int64(tabCost));
    }

    _CreateNewBankTab();
    _BroadcastEvent(GE_BANK_TAB_PURCHASED, ObjectGuid::Empty);
    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BUY_GUILD_BANK_SLOTS, _GetPurchasedTabsSize(), 0, 0, nullptr, player);
    SendPermissions(session); /// Hack to force client to update permissions
}

void Guild::HandleInviteMember(WorldSession* session, std::string const& name)
{
    Player* pInvitee = ObjectAccessor::FindPlayerByName(name);
    if (!pInvitee)
    {
        SendCommandResult(session, GUILD_COMMAND_INVITE, ERR_GUILD_PLAYER_NOT_FOUND_S, name);
        return;
    }

    Player* player = session->GetPlayer();
    // Do not show invitations from ignored players
    if (pInvitee->GetSocial()->HasIgnore(player->GetGUID()))
        return;

    if (!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD) && pInvitee->GetTeam() != player->GetTeam())
    {
        SendCommandResult(session, GUILD_COMMAND_INVITE, ERR_GUILD_NOT_ALLIED, name);
        return;
    }

    // Invited player cannot be in another guild
    /*if (pInvitee->GetGuildId())
    {
        SendCommandResult(session, GUILD_COMMAND_INVITE, ERR_ALREADY_IN_GUILD_S, name);
        return;
    }*/

    // Invited player cannot be invited
    if (pInvitee->GetGuildIdInvited())
    {
        SendCommandResult(session, GUILD_COMMAND_INVITE, ERR_ALREADY_INVITED_TO_GUILD_S, name);
        return;
    }
    // Inviting player must have rights to invite
    if (!_HasRankRight(player, GR_RIGHT_INVITE))
    {
        SendCommandResult(session, GUILD_COMMAND_INVITE, ERR_GUILD_PERMISSIONS);
        return;
    }

    SendCommandResult(session, GUILD_COMMAND_INVITE, ERR_GUILD_COMMAND_SUCCESS, name);

    TC_LOG_DEBUG("guild", "Player %s invited %s to join his Guild", player->GetName().c_str(), name.c_str());

    pInvitee->SetGuildIdInvited(m_id);
    _LogEvent(GUILD_EVENT_LOG_INVITE_PLAYER, player->GetGUID().GetCounter(), pInvitee->GetGUID().GetCounter());

    WorldPacket data(SMSG_GUILD_INVITE, 100);
    data << uint32(GetLevel());
    data << uint32(m_emblemInfo.GetBorderStyle());
    data << uint32(m_emblemInfo.GetBorderColor());
    data << uint32(m_emblemInfo.GetStyle());
    data << uint32(m_emblemInfo.GetBackgroundColor());
    data << uint32(m_emblemInfo.GetColor());

    ObjectGuid oldGuildGuid;
    if (uint32 oldId = pInvitee->GetGuildId())
        oldGuildGuid = ObjectGuid(HighGuid::Guild, oldId);

    ObjectGuid newGuildGuid = GetGUID();

    data.WriteBit(newGuildGuid[3]);
    data.WriteBit(newGuildGuid[2]);
    data.WriteBits(pInvitee->GetGuildName().length(), 8);
    data.WriteBit(newGuildGuid[1]);
    data.WriteBit(oldGuildGuid[6]);
    data.WriteBit(oldGuildGuid[4]);
    data.WriteBit(oldGuildGuid[1]);
    data.WriteBit(oldGuildGuid[5]);
    data.WriteBit(oldGuildGuid[7]);
    data.WriteBit(oldGuildGuid[2]);
    data.WriteBit(newGuildGuid[7]);
    data.WriteBit(newGuildGuid[0]);
    data.WriteBit(newGuildGuid[6]);
    data.WriteBits(m_name.length(), 8);
    data.WriteBit(oldGuildGuid[3]);
    data.WriteBit(oldGuildGuid[0]);
    data.WriteBit(newGuildGuid[5]);
    data.WriteBits(player->GetName().size(), 7);
    data.WriteBit(newGuildGuid[4]);

    data.FlushBits();

    data.WriteByteSeq(newGuildGuid[1]);
    data.WriteByteSeq(oldGuildGuid[3]);
    data.WriteByteSeq(newGuildGuid[6]);
    data.WriteByteSeq(oldGuildGuid[2]);
    data.WriteByteSeq(oldGuildGuid[1]);
    data.WriteByteSeq(newGuildGuid[0]);

    if (!pInvitee->GetGuildName().empty())
        data.WriteString(pInvitee->GetGuildName());

    data.WriteByteSeq(newGuildGuid[7]);
    data.WriteByteSeq(newGuildGuid[2]);

    data.WriteString(player->GetName());

    data.WriteByteSeq(oldGuildGuid[7]);
    data.WriteByteSeq(oldGuildGuid[6]);
    data.WriteByteSeq(oldGuildGuid[5]);
    data.WriteByteSeq(oldGuildGuid[0]);
    data.WriteByteSeq(newGuildGuid[4]);

    data.WriteString(m_name);

    data.WriteByteSeq(newGuildGuid[5]);
    data.WriteByteSeq(newGuildGuid[3]);
    data.WriteByteSeq(oldGuildGuid[4]);
    pInvitee->SendDirectMessage(&data);
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
            SendCommandResult(session, GUILD_COMMAND_QUIT, ERR_GUILD_LEADER_LEAVE);
        else if (GetLevel() >= sWorld->getIntConfig(CONFIG_GUILD_UNDELETABLE_LEVEL))
            SendCommandResult(session, GUILD_COMMAND_QUIT, ERR_GUILD_UNDELETABLE_DUE_TO_LEVEL);
        else
        {
            // Guild is disbanded if leader leaves.
            Disband();
            disband = true;
        }
    }
    else
    {
        CharacterDatabaseTransaction trans(nullptr);
        DeleteMember(trans, player->GetGUID(), false, false);

        _LogEvent(GUILD_EVENT_LOG_LEAVE_GUILD, player->GetGUID().GetCounter());
        _BroadcastEvent(GE_LEFT, player->GetGUID(), player->GetName().c_str());

        SendCommandResult(session, GUILD_COMMAND_QUIT, ERR_GUILD_COMMAND_SUCCESS, m_name);
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
        SendCommandResult(session, GUILD_COMMAND_REMOVE, ERR_GUILD_PERMISSIONS);
    else if (Member* member = GetMember(guid))
    {
        std::string name = member->GetName();

        // Guild masters cannot be removed
        if (member->IsRank(GR_GUILDMASTER))
            SendCommandResult(session, GUILD_COMMAND_REMOVE, ERR_GUILD_LEADER_LEAVE);
        // Do not allow to remove player with the same rank or higher
        else
        {
            Member const* memberMe = GetMember(player->GetGUID());
            if (!memberMe || member->IsRankNotLower(memberMe->GetRankId()))
                SendCommandResult(session, GUILD_COMMAND_REMOVE, ERR_GUILD_RANK_TOO_HIGH_S, name);
            else
            {
                // After call to DeleteMember pointer to member becomes invalid

                CharacterDatabaseTransaction trans(nullptr);
                DeleteMember(trans, guid, false, true);
                _LogEvent(GUILD_EVENT_LOG_UNINVITE_PLAYER, player->GetGUID().GetCounter(), guid.GetCounter());
                _BroadcastEvent(GE_REMOVED, ObjectGuid::Empty, name.c_str(), player->GetName().c_str());
                SendCommandResult(session, GUILD_COMMAND_REMOVE, ERR_GUILD_COMMAND_SUCCESS, name);
            }
        }
    }
}

void Guild::HandleUpdateMemberRank(WorldSession* session, ObjectGuid guid, bool demote)
{
    Player* player = session->GetPlayer();
    GuildCommandType type = demote ? GUILD_COMMAND_DEMOTE : GUILD_COMMAND_PROMOTE;
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
        _BroadcastEvent(demote ? GE_DEMOTION : GE_PROMOTION, ObjectGuid::Empty, player->GetName().c_str(), name.c_str(), _GetRankName(newRankId).c_str());
    }
}

void Guild::HandleSetMemberRank(WorldSession* session, ObjectGuid targetGuid, ObjectGuid setterGuid, uint32 rank)
{
    Player* player = session->GetPlayer();
    Member* member = GetMember(targetGuid);
    GuildRankRights rights = GR_RIGHT_PROMOTE;
    GuildCommandType type = GUILD_COMMAND_PROMOTE;

    if (rank > member->GetRankId())
    {
        rights = GR_RIGHT_DEMOTE;
        type = GUILD_COMMAND_DEMOTE;
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
            _BroadcastEvent(GE_RANK_UPDATED, ObjectGuid::Empty, std::to_string(size).c_str(), name.c_str());
    }
}

void Guild::HandleRemoveRank(WorldSession* session, uint8 rankId)
{
    // Cannot remove rank if total count is minimum allowed by the client or is not leader
    if (_GetRanksSize() <= GUILD_RANKS_MIN_COUNT || rankId >= _GetRanksSize() || !_IsLeader(session->GetPlayer()))
        return;

    // Delete bank rights for rank
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_BANK_RIGHTS_FOR_RANK);
    stmt->setUInt32(0, m_id);
    stmt->setUInt8(1, rankId);
    CharacterDatabase.Execute(stmt);
    // Delete rank
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_RANK);
    stmt->setUInt32(0, m_id);
    stmt->setUInt8(1, rankId);
    CharacterDatabase.Execute(stmt);

    m_ranks.erase(m_ranks.begin() + rankId);

    _BroadcastEvent(GE_RANK_DELETED, ObjectGuid::Empty, std::to_string(rankId).c_str());
}

void Guild::HandleMemberDepositMoney(WorldSession* session, uint64 amount, bool cashFlow /*=false*/)
{
    // guild bank cannot have more than GUILD_BANK_MONEY_LIMIT
    if (m_bankMoney > GUILD_BANK_MONEY_LIMIT - amount)
    {
        SendCommandResult(session, GUILD_COMMAND_MOVE_ITEM, ERR_GUILD_BANK_FULL);
        return;
    }

    Player* player = session->GetPlayer();

    // Call script after validation and before money transfer.
    sScriptMgr->OnGuildMemberDepositMoney(this, player, amount);

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    _ModifyBankMoney(trans, amount, true, cashFlow);
    if (!cashFlow)
    {
        player->ModifyMoney(-int64(amount));
        player->SaveGoldToDB(trans);
    }

    _LogBankEvent(trans, cashFlow ? GUILD_BANK_LOG_CASH_FLOW_DEPOSIT : GUILD_BANK_LOG_DEPOSIT_MONEY, uint8(0), player->GetGUID().GetCounter(), amount);
    CharacterDatabase.CommitTransaction(trans);

    std::string aux = ByteArrayToHexStr(reinterpret_cast<uint8*>(&m_bankMoney), 8, true);
    _BroadcastEvent(GE_BANK_MONEY_SET, player->GetGUID(), aux.c_str());

    if (player->GetSession()->HasPermission(rbac::RBAC_PERM_LOG_GM_TRADE))
    {
        sLog->outCommand(player->GetSession()->GetAccountId(),
            "GM %s (Account: %u) deposit money (Amount: " UI64FMTD ") to guild bank (Guild ID %u)",
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

    std::string aux = ByteArrayToHexStr(reinterpret_cast<uint8*>(&m_bankMoney), 8, true);
    _BroadcastEvent(GE_BANK_MONEY_SET, player->GetGUID(), aux.c_str());

    if (repair)
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_SPENT_GOLD_GUILD_REPAIRS, amount, 0, 0, nullptr, player);
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
    _BroadcastEvent(GE_SIGNED_OFF, player->GetGUID(), player->GetName().c_str());

    SaveToDB();
}

void Guild::HandleDisband(WorldSession* session)
{
    // Only leader can disband guild
    if (_IsLeader(session->GetPlayer()))
    {
        Disband();
        TC_LOG_DEBUG("guild", "Guild Successfully Disbanded");
        delete this;
    }
}

void Guild::HandleGuildPartyRequest(WorldSession* session)
{
    Player* player = session->GetPlayer();

    // Make sure player is a member of the guild and that he is in a group.
    if (!IsMember(player->GetGUID()))
        return;

    bool guildParty = false;
    float xpMultiplier = 0.0f;
    uint32 CurrGuildPartyMembers = 0, NeededGuildPartyMembers = 0;

    if (Group* group = player->GetGroup())
    {
        guildParty = group->IsGuildGroupFor(player);
        xpMultiplier = group->GetGuildXpRateForPlayer(player);
        CurrGuildPartyMembers = group->GetMembersCountOfGuild(player->GetGuildId());
        NeededGuildPartyMembers = group->GetNeededMembersOfSameGuild((player->InArena() && player->GetBattleground()->isRated()) ?
            player->GetBattleground()->GetArenaType() : 0, player->GetMap());
    }

    WorldPacket data(SMSG_GUILD_PARTY_STATE_RESPONSE, 13);
    data.WriteBit(guildParty);                          // Is guild group
    data.FlushBits();
    data << float(xpMultiplier);                        // Guild XP multiplier
    data << uint32(CurrGuildPartyMembers);              // Current guild members
    data << uint32(NeededGuildPartyMembers);            // Needed guild members

    session->SendPacket(&data);
    TC_LOG_DEBUG("guild", "SMSG_GUILD_PARTY_STATE_RESPONSE [%s]", session->GetPlayerInfo().c_str());
}

void Guild::HandleGuildRequestChallengeUpdate(WorldSession* session)
{
    WorldPackets::Guild::GuildChallengeUpdate update;

    for (uint8 i = 0; i < MAX_GUILD_CHALLENGE_TYPES; i++)
    {
        update.CurrentCount[i] = _currChallengeCount[i];
        update.MaxCount[i] = _maxChallengeCount[i];
        update.Gold[i] = _challengeGold[i];
        update.MaxLevelGold[i] = _challengeGoldMaxLevel[i];
        update.Xp[i] = _challengeXp[i];
    }

    session->SendPacket(update.Write());
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
    TC_LOG_DEBUG("guild", "SMSG_GUILD_EVENT_LOG_QUERY_RESULT [%s]", session->GetPlayerInfo().c_str());
}

void Guild::SendNewsUpdate(WorldSession* session)
{
    GuildLog* logs = m_newsLog->GetGuildLog();

    if (!logs)
        return;

    WorldPackets::Guild::GuildNews packet;
    packet.NewsEvents.reserve(m_newsLog->GetSize());

    uint64 weeklyMinTime = uint64(GameTime::GetGameTime() - time_t(7 * DAY));

    for (GuildLog::const_iterator itr = logs->begin(); itr != logs->end(); ++itr)
    {
        // Skip news log entries that are older than a week. A cleanup of db and log data will be executed on daily guild reset time.
        if ((*itr)->GetTimestamp() < weeklyMinTime)
            continue;

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

        // If we have a weekly bonus money value, we can safely assume that Cash Flow has been unlocked.
        if (tabId == GUILD_BANK_MAX_TABS && GetWeeklyBonusMoney())
            packet.WeeklyBonusMoney.emplace(GetWeeklyBonusMoney());

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

    WorldPacket data(SMSG_GUILD_PERMISSIONS_QUERY_RESULTS, 4 * 15 + 1);
    data << uint32(rankId);
    data << uint32(_GetPurchasedTabsSize());
    data << uint32(_GetRankRights(rankId));
    data << uint32(_GetRankBankMoneyPerDay(rankId));
    data.WriteBits(GUILD_BANK_MAX_TABS, 23);
    for (uint8 tabId = 0; tabId < GUILD_BANK_MAX_TABS; ++tabId)
    {
        data << uint32(_GetRankBankTabRights(rankId, tabId));
        data << uint32(_GetMemberRemainingSlots(member, tabId));
    }

    session->SendPacket(&data);
    TC_LOG_DEBUG("guild", "SMSG_GUILD_PERMISSIONS_QUERY_RESULTS [%s] Rank: %u", session->GetPlayerInfo().c_str(), rankId);
}

void Guild::SendMoneyInfo(WorldSession* session) const
{
    Member const* member = GetMember(session->GetPlayer()->GetGUID());
    if (!member)
        return;

    int64 amount = _GetMemberRemainingMoney(member);
    WorldPacket data(SMSG_GUILD_BANK_MONEY_WITHDRAWN, 8);
    data << int64(amount);
    session->SendPacket(&data);
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
          SMSG_GUILD_EVENT - GE_MOTD
          SMSG_GUILD_RANK
          SMSG_GUILD_EVENT - GE_SIGNED_ON
          -- learn perks
          SMSG_GUILD_REPUTATION_WEEKLY_CAP
          SMSG_GUILD_ACHIEVEMENT_DATA
          SMSG_GUILD_MEMBER_DAILY_RESET // bank withdrawal reset
    */

    WorldPackets::Guild::GuildEvent motd;
    motd.EventType = GE_MOTD;
    motd.Param.push_back(m_motd);
    session->SendPacket(motd.Write());

    TC_LOG_DEBUG("guild", "SMSG_GUILD_EVENT [%s] MOTD", session->GetPlayerInfo().c_str());

    SendGuildRankInfo(session);
    _BroadcastEvent(GE_SIGNED_ON, player->GetGUID(), player->GetName().c_str());

    // Send to self separately, player is not in world yet and is not found by _BroadcastEvent
    WorldPackets::Guild::GuildEvent signedOn;
    signedOn.EventType = GE_SIGNED_ON;
    signedOn.Param.push_back(player->GetName());
    signedOn.GUID = player->GetGUID();
    session->SendPacket(signedOn.Write());

    WorldPackets::Guild::GuildMemberDailyReset packet; // tells the client to request bank withdrawal limit
    session->SendPacket(packet.Write());

    if (!sWorld->getBoolConfig(CONFIG_GUILD_LEVELING_ENABLED))
        return;

    for (uint32 i = 0; i < sGuildPerkSpellsStore.GetNumRows(); ++i)
        if (GuildPerkSpellsEntry const* entry = sGuildPerkSpellsStore.LookupEntry(i))
            if (entry->GuildLevel <= GetLevel())
                player->LearnSpell(entry->SpellID, true);

    SendGuildReputationWeeklyCap(session, member->GetWeekReputation());

    m_achievementMgr->SendAllAchievementData(player);

    member->SetStats(player);
    member->AddFlag(GUILDMEMBER_STATUS_ONLINE);
}

void Guild::SendMemberUpdateNote(std::string const& note, ObjectGuid guid, bool isPublic) const
{
    uint8 length = note.length();
    WorldPacket data(SMSG_GUILD_MEMBER_UPDATE_NOTE, 1 + 1 + 1 + 8 + length);
    data.WriteBit(guid[7]);
    data.WriteBit(guid[2]);
    data.WriteBit(guid[3]);
    data.WriteBits(length, 8); // note length
    data.WriteBit(guid[5]);
    data.WriteBit(guid[0]);
    data.WriteBit(guid[6]);
    data.WriteBit(guid[4]);
    data.WriteBit(isPublic); // public
    data.WriteBit(guid[1]);
    data.WriteByteSeq(guid[3]);
    data.WriteByteSeq(guid[0]);
    data.WriteByteSeq(guid[2]);
    data.WriteByteSeq(guid[5]);
    data.WriteString(note); // note
    data.WriteByteSeq(guid[7]);
    data.WriteByteSeq(guid[6]);
    data.WriteByteSeq(guid[1]);
    data.WriteByteSeq(guid[4]);

    BroadcastPacket(&data);
}

// Loading methods
bool Guild::LoadFromDB(Field* fields)
{
    m_id            = fields[0].GetUInt32();
    m_name          = fields[1].GetString();
    m_leaderGuid    = ObjectGuid(HighGuid::Player, fields[2].GetUInt32());
    m_emblemInfo.LoadFromDB(fields);
    m_info          = fields[8].GetString();
    m_motd          = fields[9].GetString();
    m_createdDate   = time_t(fields[10].GetUInt32());
    m_bankMoney     = fields[11].GetUInt64();
    _level          = fields[12].GetUInt32();
    _experience     = fields[13].GetUInt64();
    _todayExperience = fields[14].GetUInt64();

    uint8 purchasedTabs = uint8(fields[15].GetUInt64());
    if (purchasedTabs > GUILD_BANK_MAX_TABS)
        purchasedTabs = GUILD_BANK_MAX_TABS;

    m_bankTabs.resize(purchasedTabs);
    for (uint8 i = 0; i < purchasedTabs; ++i)
        m_bankTabs[i] = new BankTab(m_id, i);

    _currChallengeCount[GUILD_CHALLENGE_TYPE_DUNGEON] = uint8(fields[16].GetUInt32());
    _currChallengeCount[GUILD_CHALLENGE_TYPE_RAID] = uint8(fields[17].GetUInt32());
    _currChallengeCount[GUILD_CHALLENGE_TYPE_RATED_BG] = uint8(fields[18].GetUInt32());
    _weeklyBonusMoney = fields[19].GetUInt64();

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
    ObjectGuid::LowType lowguid = fields[1].GetUInt32();
    ObjectGuid playerGuid(HighGuid::Player, lowguid);
    Member* member = new Member(m_id, playerGuid, fields[2].GetUInt8());
    if (!member->LoadFromDB(fields))
    {
        CharacterDatabaseTransaction trans(nullptr);
        _DeleteMemberFromDB(trans, lowguid);
        delete member;
        return false;
    }

    sCharacterCache->UpdateCharacterGuildId(playerGuid, GetId());
    m_members[lowguid] = member;
    return true;
}

void Guild::LoadBankRightFromDB(Field* fields)
{
                                           // tabId              rights                slots
    GuildBankRightsAndSlots rightsAndSlots(fields[1].GetUInt8(), fields[3].GetUInt8(), fields[4].GetUInt32());
                                  // rankId
    _SetRankBankTabRightsAndSlots(fields[2].GetUInt8(), rightsAndSlots, false);
}

bool Guild::LoadEventLogFromDB(Field* fields)
{
    if (m_eventLog->CanInsert())
    {
        m_eventLog->LoadEvent(new EventLogEntry(
            m_id,                                       // guild id
            fields[1].GetUInt32(),                      // guid
            time_t(fields[6].GetUInt32()),              // timestamp
            GuildEventLogTypes(fields[2].GetUInt8()),   // event type
            fields[3].GetUInt32(),                      // player guid 1
            fields[4].GetUInt32(),                      // player guid 2
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
            ObjectGuid::LowType guid = fields[2].GetUInt32();
            GuildBankEventLogTypes eventType = GuildBankEventLogTypes(fields[3].GetUInt8());
            if (BankEventLogEntry::IsMoneyEvent(eventType))
            {
                if (!isMoneyTab)
                {
                    TC_LOG_ERROR("guild", "GuildBankEventLog ERROR: MoneyEvent(LogGuid: %u, Guild: %u) does not belong to money tab (%u), ignoring...", guid, m_id, dbTabId);
                    return false;
                }
            }
            else if (isMoneyTab)
            {
                TC_LOG_ERROR("guild", "GuildBankEventLog ERROR: non-money event (LogGuid: %u, Guild: %u) belongs to money tab, ignoring...", guid, m_id);
                return false;
            }
            pLog->LoadEvent(new BankEventLogEntry(
                m_id,                                   // guild id
                guid,                                   // guid
                time_t(fields[8].GetUInt32()),          // timestamp
                dbTabId,                                // tab id
                eventType,                              // event type
                fields[4].GetUInt32(),                  // player guid
                fields[5].GetUInt64(),                  // item or money
                fields[6].GetUInt16(),                  // itam stack count
                fields[7].GetUInt8()));                 // dest tab id
        }
    }
    return true;
}

void Guild::LoadGuildNewsLogFromDB(Field* fields)
{
    if (!m_newsLog->CanInsert())
        return;

    m_newsLog->LoadEvent(new NewsLogEntry(
    m_id,                                               // guild id
    fields[1].GetUInt32(),                              // guid
    fields[6].GetUInt32(),                              // timestamp //64 bits?
    GuildNews(fields[2].GetUInt8()),                    // type
    ObjectGuid(HighGuid::Player, fields[3].GetUInt32()), // player guid
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
    uint8 tabId = fields[13].GetUInt8();
    if (tabId >= _GetPurchasedTabsSize())
    {
        TC_LOG_ERROR("guild", "Invalid tab for item (GUID: %u, id: #%u) in guild bank, skipped.",
            fields[15].GetUInt32(), fields[16].GetUInt32());
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
        TC_LOG_ERROR("guild", "Guild %u has invalid number of ranks, creating new...", m_id);
        broken_ranks = true;
    }
    else
    {
        for (uint8 rankId = 0; rankId < ranks; ++rankId)
        {
            RankInfo* rankInfo = GetRankInfo(rankId);
            if (rankInfo->GetId() != rankId)
            {
                TC_LOG_ERROR("guild", "Guild %u has broken rank id %u, creating default set of ranks...", m_id, rankId);
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
    Member* pLeader = GetMember(m_leaderGuid);
    if (!pLeader)
    {
        DeleteMember(trans, m_leaderGuid);
        // If no more members left, disband guild
        if (m_members.empty())
        {
            Disband();
            return false;
        }
    }
    else if (!pLeader->IsRank(GR_GUILDMASTER))
        _SetLeader(trans, pLeader);

    // Check config if multiple guildmasters are allowed
    if (!sConfigMgr->GetBoolDefault("Guild.AllowMultipleGuildMaster", 0))
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
        WorldPacket data;
        ChatHandler::BuildChatPacket(data, officerOnly ? CHAT_MSG_OFFICER : CHAT_MSG_GUILD, Language(language), session->GetPlayer(), nullptr, msg);
        for (auto itr = m_members.begin(); itr != m_members.end(); ++itr)
            if (Player* player = itr->second->FindConnectedPlayer())
                if (player->GetSession() && _HasRankRight(player, officerOnly ? GR_RIGHT_OFFCHATLISTEN : GR_RIGHT_GCHATLISTEN) &&
                    !player->GetSocial()->HasIgnore(session->GetPlayer()->GetGUID()))
                    player->SendDirectMessage(&data);
    }
}

void Guild::BroadcastAddonToGuild(WorldSession* session, bool officerOnly, std::string const& msg, std::string const& prefix) const
{
    if (session && session->GetPlayer() && _HasRankRight(session->GetPlayer(), officerOnly ? GR_RIGHT_OFFCHATSPEAK : GR_RIGHT_GCHATSPEAK))
    {
        WorldPacket data;
        ChatHandler::BuildChatPacket(data, officerOnly ? CHAT_MSG_OFFICER : CHAT_MSG_GUILD, LANG_ADDON, session->GetPlayer(), nullptr, msg, 0, "", DEFAULT_LOCALE, prefix);
        for (Members::const_iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
            if (Player* player = itr->second->FindPlayer())
                if (player->GetSession() && _HasRankRight(player, officerOnly ? GR_RIGHT_OFFCHATLISTEN : GR_RIGHT_GCHATLISTEN) &&
                    !player->GetSocial()->HasIgnore(session->GetPlayer()->GetGUID()) &&
                    player->GetSession()->IsAddonRegistered(prefix))
                        player->SendDirectMessage(&data);
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
                player->SendDirectMessage(packet);
}

void Guild::MassInviteToEvent(WorldSession* session, uint32 minLevel, uint32 maxLevel, uint32 minRank)
{
    uint32 count = 0;

    WorldPacket data(SMSG_CALENDAR_FILTER_GUILD);
    data << uint32(count); // count placeholder

    for (auto itr = m_members.begin(); itr != m_members.end(); ++itr)
    {
        // not sure if needed, maybe client checks it as well
        if (count >= CALENDAR_MAX_INVITES)
        {
            if (Player* player = session->GetPlayer())
                sCalendarMgr->SendCalendarCommandResult(player->GetGUID(), CALENDAR_ERROR_INVITES_EXCEEDED);
            return;
        }

        Member* member = itr->second;
        uint32 level = sCharacterCache->GetCharacterLevelByGuid(member->GetGUID());

        if (member->GetGUID() != session->GetPlayer()->GetGUID() && level >= minLevel && level <= maxLevel && member->IsRankNotLower(minRank))
        {
            data.appendPackGUID(member->GetGUID().GetRawValue());
            data << uint8(0); // unk
            ++count;
        }
    }

    data.put<uint32>(0, count);

    session->SendPacket(&data);
}

bool Guild::_HasRankRight(Player const* player, uint32 right) const
{
    if (player)
        if (Member const* member = GetMember(player->GetGUID()))
            return (_GetRankRights(member->GetRankId()) & right) != GR_RIGHT_EMPTY;
    return false;
}

void Guild::_DeleteMemberFromDB(CharacterDatabaseTransaction& trans, ObjectGuid::LowType lowguid) const
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_MEMBER);
    stmt->setUInt32(0, lowguid);
    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

// Members handling
bool Guild::AddMember(CharacterDatabaseTransaction& trans, ObjectGuid guid, uint8 rankId)
{
    Player* player = ObjectAccessor::FindConnectedPlayer(guid);
    // Player cannot be in guild
    if (player)
    {
        if (player->GetGuildId() != 0)
            return false;
    }
    else if (sCharacterCache->GetCharacterGuildIdByGuid(guid) != 0)
        return false;

    // Remove all player signs from another petitions
    // This will be prevent attempt to join many guilds and corrupt guild data integrity
    Player::RemovePetitionsAndSigns(guid, GUILD_CHARTER_TYPE);

    ObjectGuid::LowType lowguid = guid.GetCounter();

    // If rank was not passed, assign lowest possible rank
    if (rankId == GUILD_RANK_NONE)
        rankId = _GetLowestRankId();

    Member* member = new Member(m_id, guid, rankId);
    std::string name;

    /* Check if player can keep his guild reputation */
    bool keepGuildReputation = false;
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_OLD_GUILD_DATA);
    stmt->setUInt32(0, lowguid);
    if (PreparedQueryResult result = CharacterDatabase.Query(stmt))
    {
        Field* fields = result->Fetch();
        if (fields[0].GetUInt32() == m_id) // old player guild was this guild
        {
            // Set the Week cap
            member->SetWeekReputation(fields[1].GetUInt32());
            keepGuildReputation = true;
        }
    }

    if (player)
    {
        if (!keepGuildReputation || !player->GetReputation(FACTION_GUILD))
            player->SetReputation(FACTION_GUILD, 0);

        m_members[lowguid] = member;
        player->SetInGuild(m_id);
        player->SetGuildIdInvited(0);
        player->SetGuildRank(rankId);
        player->SetGuildLevel(GetLevel());
        member->UpdateProfessionData();
        SendLoginInfo(player->GetSession());
        name = player->GetName();
    }
    else
    {
        member->ResetFlags();

        bool ok = false;
        // Player must exist
        CharacterDatabasePreparedStatement* stmt2 = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_DATA_FOR_GUILD);
        stmt2->setUInt32(0, lowguid);
        if (PreparedQueryResult result = CharacterDatabase.Query(stmt2))
        {
            Field* fields = result->Fetch();
            name = fields[0].GetString();
            member->SetStats(
                name,
                fields[1].GetUInt8(),
                fields[2].GetUInt8(),
                fields[3].GetUInt16(),
                fields[4].GetUInt32(),
                fields[5].GetUInt32(),
                keepGuildReputation ? fields[6].GetUInt32() : 0);

            ok = member->CheckStats();
        }

        if (!ok)
        {
            delete member;
            return false;
        }

        // Remove guild reputation
        if (!keepGuildReputation)
        {
            stmt2 = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHAR_REP_FACTION_CHANGE);
            stmt2->setUInt16(0, uint16(FACTION_GUILD));
            stmt2->setInt32(1, 0);
            stmt2->setUInt16(2, uint16(FACTION_GUILD));
            stmt2->setUInt32(3, lowguid);
            CharacterDatabase.Execute(stmt2);
        }

        m_members[lowguid] = member;
        sCharacterCache->UpdateCharacterGuildId(guid, GetId());
    }

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_OLD_GUILD_DATA);
    stmt->setUInt32(0, lowguid);
    CharacterDatabase.Execute(stmt);

    member->SaveToDB(trans);

    _UpdateAccountsNumber();
    _LogEvent(GUILD_EVENT_LOG_JOIN_GUILD, lowguid);
    _BroadcastEvent(GE_JOINED, guid, name.c_str());
    sGuildFinderMgr->RemoveAllMembershipRequestsFromPlayer(lowguid);

    // Update GuildId in group
    if (player)
        if (Group* group = player->GetGroup())
            group->UpdateGuildFor(guid, m_id);

    // Call scripts if member was succesfully added (and stored to database)
    sScriptMgr->OnGuildAddMember(this, player, rankId);

    return true;
}

void Guild::DeleteMember(CharacterDatabaseTransaction& trans, ObjectGuid guid, bool isDisbanding, bool isKicked, bool canDeleteGuild)
{
    ObjectGuid::LowType lowguid = guid.GetCounter();
    Player* player = ObjectAccessor::FindConnectedPlayer(guid);

    // Guild master can be deleted when loading guild and guid doesn't exist in characters table
    // or when he is removed from guild by gm command
    if (m_leaderGuid == guid && !isDisbanding)
    {
        Member* oldLeader = nullptr;
        Member* newLeader = nullptr;
        for (auto i = m_members.begin(); i != m_members.end(); ++i)
        {
            if (i->first == lowguid)
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
            _BroadcastEvent(GE_LEADER_CHANGED, ObjectGuid::Empty, oldLeader->GetName().c_str(), newLeader->GetName().c_str());
            _BroadcastEvent(GE_LEFT, guid, oldLeader->GetName().c_str());
        }
    }
    // Call script on remove before member is actually removed from guild (and database)
    sScriptMgr->OnGuildRemoveMember(this, player, isDisbanding, isKicked);

    if (Member* member = GetMember(guid))
    {
        if (!isDisbanding)
        {
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_LEAVE_GUILD_DATA);
            stmt->setUInt32(0, lowguid);
            stmt->setUInt32(1, m_id);
            stmt->setUInt32(2, member->GetWeekReputation());
            stmt->setUInt64(3, uint32(::GameTime::GetGameTime()));
            CharacterDatabase.Execute(stmt);
        }
        delete member;
    }
    m_members.erase(lowguid);

    // If player not online data in data field will be loaded from guild tabs no need to update it !!
    if (player)
    {
        player->SetInGuild(0);
        player->SetGuildRank(0);
        player->SetGuildLevel(0);

        for (GuildPerkSpellsEntry const* entry : sGuildPerkSpellsStore)
            player->RemoveSpell(entry->SpellID, false, false);

        // Update GuildId in group
        if (Group* group = player->GetGroup())
            group->UpdateGuildFor(guid, 0);
    }
    else
        sCharacterCache->UpdateCharacterGuildId(guid, 0);

    _DeleteMemberFromDB(trans, lowguid);
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

uint64 Guild::GetMemberAvailableMoneyForRepairItems(ObjectGuid guid) const
{
    Member const* member = GetMember(guid);
    if (!member)
        return 0;

    return std::min(m_bankMoney, static_cast<uint64>(_GetMemberRemainingMoney(member)));
}

bool Guild::IsMember(ObjectGuid guid) const
{
    Members::const_iterator itr = m_members.find(guid.GetCounter());
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
    }
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
    stmt->setUInt32(0, m_id);
    stmt->setUInt8 (1, tabId);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_BANK_TAB);
    stmt->setUInt32(0, m_id);
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
    stmt->setUInt32(0, m_id);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_BANK_RIGHTS);
    stmt->setUInt32(0, m_id);
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

bool Guild::_ModifyBankMoney(CharacterDatabaseTransaction& trans, uint64 amount, bool add, bool fromCashFlow /*= false*/)
{
    if (add)
    {
        m_bankMoney += amount;
        if (fromCashFlow)
            _weeklyBonusMoney += amount;
    }
    else
    {
        // Check if there is enough money in bank.
        if (m_bankMoney < amount)
            return false;
        m_bankMoney -= amount;
    }

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_BANK_MONEY);
    stmt->setUInt64(0, m_bankMoney);
    stmt->setUInt64(1, _weeklyBonusMoney);
    stmt->setUInt32(2, m_id);
    trans->Append(stmt);
    return true;
}

void Guild::_SetLeader(CharacterDatabaseTransaction& trans, Member* pLeader)
{
    if (!pLeader)
        return;

    bool isInTransaction = bool(trans);
    if (!isInTransaction)
        trans = CharacterDatabase.BeginTransaction();

    m_leaderGuid = pLeader->GetGUID();
    pLeader->ChangeRank(trans, GR_GUILDMASTER);

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_LEADER);
    stmt->setUInt32(0, m_leaderGuid.GetCounter());
    stmt->setUInt32(1, m_id);
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

inline bool Guild::_MemberHasTabRights(ObjectGuid guid, uint8 tabId, uint32 rights) const
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
    if (const BankTab* tab = GetBankTab(tabId))
        return tab->GetItem(slotId);
    return nullptr;
}

inline void Guild::_RemoveItem(CharacterDatabaseTransaction& trans, uint8 tabId, uint8 slotId)
{
    if (BankTab* pTab = GetBankTab(tabId))
        pTab->SetItem(trans, slotId, nullptr);
}

void Guild::_MoveItems(MoveItemData* pSrc, MoveItemData* pDest, uint32 splitedAmount)
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
            player->GetName(), player->GetGUID().GetCounter(), pItemSrc->GetEntry(), tabId, slotId, destTabId, destSlotId, pItemSrc->GetEntry());
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
        _DoItemsMove(pSrc, pDest, true, splitedAmount);
    }
    else // 6. No split
    {
        // 6.1. Try to merge items in destination (pDest->GetItem() == nullptr)
        if (!_DoItemsMove(pSrc, pDest, false)) // Item could not be merged
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
            _DoItemsMove(pSrc, pDest, true);
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
            itemInfo.Item.RandomPropertiesID = int32(tabItem ? tabItem->GetItemRandomPropertyId() : 0);
            itemInfo.Item.RandomPropertiesSeed = int32(tabItem ? tabItem->GetItemSuffixFactor() : 0);
            itemInfo.EnchantmentID = int32(tabItem ? tabItem->GetEnchantmentId(EnchantmentSlot(PERM_ENCHANTMENT_SLOT)) : 0);
            itemInfo.OnUseEnchantmentID = int32(tabItem ? tabItem->GetEnchantmentId(EnchantmentSlot(BONUS_ENCHANTMENT_SLOT)) : 0);
            itemInfo.ReforgeEnchantmentID = int32(tabItem ? tabItem->GetEnchantmentId(EnchantmentSlot(REFORGE_ENCHANTMENT_SLOT)) : 0);
            itemInfo.Flags = int32(tabItem ? tabItem->GetInt32Value(ITEM_FIELD_FLAGS) : 0);
            itemInfo.Locked = false;

            if (tabItem)
            {
                uint8 slotIndex = 0;
                for (uint8 enchSlot = SOCK_ENCHANTMENT_SLOT; enchSlot <= SOCK_ENCHANTMENT_SLOT_3; enchSlot++)
                {
                    if (uint32 enchantId = tabItem->GetEnchantmentId(EnchantmentSlot(enchSlot)))
                    {
                        WorldPackets::Guild::GuildBankItemInfo::GuildBankSocketEnchant gem;
                        gem.SocketIndex = slotIndex;
                        gem.SocketEnchantID = enchantId;
                        itemInfo.SocketEnchant.push_back(gem);
                    }
                    slotIndex++;
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

void Guild::_BroadcastEvent(GuildEvents guildEvent, ObjectGuid guid, char const* param1, char const* param2, char const* param3) const
{
    WorldPackets::Guild::GuildEvent packet;
    packet.EventType = guildEvent;
    if (param1)
        packet.Param.push_back(param1);

    if (param2)
        packet.Param.push_back(param2);

    if (param3)
        packet.Param.push_back(param3);

    if (guid)
        packet.GUID = guid;

    BroadcastPacket(packet.Write());

    if (sLog->ShouldLog("guild", LOG_LEVEL_DEBUG))
        TC_LOG_DEBUG("guild", "SMSG_GUILD_EVENT [Broadcast] Event: %s (%u)", _GetGuildEventString(guildEvent).c_str(), guildEvent);
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
                    itemInfo.Item.RandomPropertiesID = int32(tabItem->GetItemRandomPropertyId());
                    itemInfo.Item.RandomPropertiesSeed = int32(tabItem->GetItemSuffixFactor());
                    itemInfo.Count = int32(tabItem->GetCount());
                    itemInfo.Charges = int32(abs(tabItem->GetSpellCharges()));
                    itemInfo.EnchantmentID = tabItem->GetEnchantmentId(EnchantmentSlot(PERM_ENCHANTMENT_SLOT));
                    itemInfo.OnUseEnchantmentID = tabItem->GetEnchantmentId(EnchantmentSlot(BONUS_ENCHANTMENT_SLOT));
                    itemInfo.ReforgeEnchantmentID = tabItem->GetEnchantmentId(EnchantmentSlot(REFORGE_ENCHANTMENT_SLOT));
                    itemInfo.Flags = tabItem->GetInt32Value(ITEM_FIELD_FLAGS);

                    uint8 slotIndex = 0;
                    for (uint8 enchSlot = SOCK_ENCHANTMENT_SLOT; enchSlot <= SOCK_ENCHANTMENT_SLOT_3; enchSlot++)
                    {
                        if (uint32 enchantId = tabItem->GetEnchantmentId(EnchantmentSlot(enchSlot)))
                        {
                            WorldPackets::Guild::GuildBankItemInfo::GuildBankSocketEnchant gem;
                            gem.SocketIndex = slotIndex;
                            gem.SocketEnchantID = enchantId;
                            itemInfo.SocketEnchant.push_back(gem);
                        }
                        slotIndex++;
                    }

                    itemInfo.Locked = false;

                    packet.ItemInfo.push_back(itemInfo);
                }
            }
        }
    }

    session->SendPacket(packet.Write());

    TC_LOG_DEBUG("guild", "WORLD: Sent (SMSG_GUILD_BANK_LIST)");
}

void Guild::SendGuildRanksUpdate(ObjectGuid setterGuid, ObjectGuid targetGuid, uint32 rank)
{
    Member* member = GetMember(targetGuid);
    ASSERT(member);

    WorldPacket data(SMSG_GUILD_RANKS_UPDATE, 100);
    data.WriteBit(setterGuid[7]);
    data.WriteBit(setterGuid[2]);
    data.WriteBit(targetGuid[2]);
    data.WriteBit(setterGuid[1]);
    data.WriteBit(targetGuid[1]);
    data.WriteBit(targetGuid[7]);
    data.WriteBit(targetGuid[0]);
    data.WriteBit(targetGuid[5]);
    data.WriteBit(targetGuid[4]);
    data.WriteBit(rank < member->GetRankId()); // 1 == higher, 0 = lower?
    data.WriteBit(setterGuid[5]);
    data.WriteBit(setterGuid[0]);
    data.WriteBit(targetGuid[6]);
    data.WriteBit(setterGuid[3]);
    data.WriteBit(setterGuid[6]);
    data.WriteBit(targetGuid[3]);
    data.WriteBit(setterGuid[4]);

    data.FlushBits();

    data << uint32(rank);
    data.WriteByteSeq(setterGuid[3]);
    data.WriteByteSeq(targetGuid[7]);
    data.WriteByteSeq(setterGuid[6]);
    data.WriteByteSeq(setterGuid[2]);
    data.WriteByteSeq(targetGuid[5]);
    data.WriteByteSeq(targetGuid[0]);
    data.WriteByteSeq(setterGuid[7]);
    data.WriteByteSeq(setterGuid[5]);
    data.WriteByteSeq(targetGuid[2]);
    data.WriteByteSeq(targetGuid[1]);
    data.WriteByteSeq(setterGuid[0]);
    data.WriteByteSeq(setterGuid[4]);
    data.WriteByteSeq(setterGuid[1]);
    data.WriteByteSeq(targetGuid[3]);
    data.WriteByteSeq(targetGuid[6]);
    data.WriteByteSeq(targetGuid[4]);
    BroadcastPacket(&data);

    CharacterDatabaseTransaction trans(nullptr);
    member->ChangeRank(trans, rank);

    TC_LOG_DEBUG("network", "SMSG_GUILD_RANKS_UPDATE [Broadcast] Target: %s, Issuer: %s, RankId: %u",
        targetGuid.ToString().c_str(), setterGuid.ToString().c_str(), rank);
}

void Guild::CompleteChallenge(uint8 challengeType, Player* source)
{
    if (_currChallengeCount[challengeType] >= _maxChallengeCount[challengeType])
        return;

    _currChallengeCount[challengeType]++;
    uint64 gold = GetLevel() >= sWorld->getIntConfig(CONFIG_GUILD_MAX_LEVEL) ? _challengeGoldMaxLevel[challengeType] : _challengeGold[challengeType];
    uint32 xp = GetLevel() >= sWorld->getIntConfig(CONFIG_GUILD_MAX_LEVEL) ? _challengeXp[challengeType] : 0;

    WorldPackets::Guild::GuildChallengeCompleted completed;

    completed.ChallengeType = challengeType;
    completed.GoldAwarded = gold;
    completed.CurrentCount = _currChallengeCount[challengeType];
    completed.XpAwarded = xp;
    completed.MaxCount = _maxChallengeCount[challengeType];

    BroadcastPacket(completed.Write());

    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_GUILD_CHALLENGE_TYPE, challengeType, 0, 0, nullptr, source);
    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_GUILD_CHALLENGE, 0, 0, 0, nullptr, source);

    // Give Reward now
    GiveXP(xp, source, true);
    SaveToDB(); // Save xp

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    uint64 money = gold * 10000;
    if (money / 10000 != gold)
        money = std::numeric_limits<uint64>::max();

    _ModifyBankMoney(trans, money, true, false);

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_CHALLENGE);
    stmt->setUInt32(0, _currChallengeCount[GUILD_CHALLENGE_TYPE_DUNGEON]);
    stmt->setUInt32(1, _currChallengeCount[GUILD_CHALLENGE_TYPE_RAID]);
    stmt->setUInt32(2, _currChallengeCount[GUILD_CHALLENGE_TYPE_RATED_BG]);
    stmt->setUInt32(3, m_id);
    trans->Append(stmt);
    CharacterDatabase.CommitTransaction(trans);
}

void Guild::GiveReputation(uint32 rep, Player* source)
{
    uint32 reputation = rep;

    // Apply reputation aura bonuses
    for (auto itr : source->GetAuraEffectsByType(SPELL_AURA_MOD_REPUTATION_GAIN))
        reputation += CalculatePct(rep, itr->GetAmount());

    // Guild Champion
    for (auto itr : source->GetAuraEffectsByType(SPELL_AURA_MOD_HONOR_GAIN_PCT))
        reputation += CalculatePct(rep, itr->GetAmount());

    if (Member* member = GetMember(source->GetGUID()))
    {
        member->AddReputation(reputation, source);
        SendGuildReputationWeeklyCap(source->GetSession(), member->GetWeekReputation());
    }
}

void Guild::GiveXP(uint32 xp, Player* source, bool rewardedByChallenge)
{
    if (!sWorld->getBoolConfig(CONFIG_GUILD_LEVELING_ENABLED))
        return;

    if (GetLevel() >= sWorld->getIntConfig(CONFIG_GUILD_MAX_LEVEL))
        xp = 0; // SMSG_GUILD_XP_GAIN is always sent, even for no gains

    if (GetLevel() < GUILD_EXPERIENCE_UNCAPPED_LEVEL)
        xp = std::min(xp, sWorld->getIntConfig(CONFIG_GUILD_DAILY_XP_CAP) - uint32(_todayExperience));

    _experience += xp;

    WorldPacket data(SMSG_GUILD_XP_GAIN, 8);
    data << uint64(xp);
    source->SendDirectMessage(&data);

    if (!rewardedByChallenge)
    {
        _todayExperience += xp;

        WorldPacket data(SMSG_GUILD_XP_GAIN, 8);
        data << uint64(xp);
        source->GetSession()->SendPacket(&data);
    }

    if (Member* member = GetMember(source->GetGUID()))
        member->AddActivity(xp);

    if (!xp)
        return;

    uint32 oldLevel = GetLevel();

    // Ding, mon!
    while (GetExperience() >= sGuildMgr->GetXPForGuildLevel(GetLevel()) && GetLevel() < sWorld->getIntConfig(CONFIG_GUILD_MAX_LEVEL))
    {
        _experience -= sGuildMgr->GetXPForGuildLevel(GetLevel());
        ++_level;

        // Find all guild perks to learn
        std::vector<uint32> perksToLearn;
        for (uint32 i = 0; i < sGuildPerkSpellsStore.GetNumRows(); ++i)
            if (GuildPerkSpellsEntry const* entry = sGuildPerkSpellsStore.LookupEntry(i))
                if (entry->GuildLevel > oldLevel && entry->GuildLevel <= GetLevel())
                    perksToLearn.push_back(entry->SpellID);

        // Notify all online players that guild level changed and learn perks
        for (Members::const_iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
        {
            if (Player* player = itr->second->FindPlayer())
            {
                player->SetGuildLevel(GetLevel());
                for (size_t i = 0; i < perksToLearn.size(); ++i)
                    player->LearnSpell(perksToLearn[i], true);
            }
        }

        AddGuildNews(GUILD_NEWS_LEVEL_UP, ObjectGuid::Empty, 0, _level);
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_REACH_GUILD_LEVEL, GetLevel(), 0, 0, nullptr, source);

        ++oldLevel;
    }

    for (Members::const_iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
        if (Player* player = itr->second->FindPlayer())
            SendGuildXP(player->GetSession());
}

void Guild::SendGuildXP(WorldSession* session /*= nullptr*/) const
{
    Member const* member = GetMember(session->GetPlayer()->GetGUID());

    WorldPackets::Guild::GuildXP packet;
    packet.TotalXP = uint64(member ? member->GetTotalActivity() : 0);
    packet.GuildRemainingXP = uint64(sGuildMgr->GetXPForGuildLevel(GetLevel()) - GetExperience());
    packet.GuildTodayXP = uint64(GetTodayExperience());
    packet.WeeklyXP = uint64(member ? member->GetWeekActivity() : 0);
    packet.GuildCurrentXP = uint64(GetExperience());
    session->SendPacket(packet.Write());
}

void Guild::SendGuildReputationWeeklyCap(WorldSession* session, uint32 reputation) const
{
    uint32 cap = std::max<uint32>(0, sWorld->getIntConfig(CONFIG_GUILD_WEEKLY_REP_CAP) - reputation);
    WorldPackets::Guild::GuildReputationWeeklyCap packet;
    packet.Cap = cap;
    session->SendPacket(packet.Write());
    TC_LOG_DEBUG("guild", "SMSG_GUILD_REPUTATION_WEEKLY_CAP [%s]: Left: %u",
                   session->GetPlayerInfo().c_str(), cap);
}

void Guild::ResetTimes(bool weekly)
{
    _todayExperience = 0;

    if (weekly)
    {
        InitializeGuildChallengeRewards();

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_RESET_CHALLENGE);
        stmt->setInt32(0, m_id);
        CharacterDatabase.Execute(stmt);

        // Reset weekly bonus money from Cash Flow perk
        _weeklyBonusMoney = 0;
    }

    for (Members::const_iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
    {
        itr->second->ResetValues(weekly);
        if (Player* player = itr->second->FindPlayer())
        {
            SendGuildXP(player->GetSession());
            WorldPacket data(SMSG_GUILD_MEMBER_DAILY_RESET, 0);  // tells the client to request bank withdrawal limit
            player->SendDirectMessage(&data);
        }
    }
}

void Guild::AddGuildNews(uint8 type, ObjectGuid guid, uint32 flags, uint32 value)
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
    return m_achievementMgr->HasAchieved(achievementId);
}

void Guild::UpdateAchievementCriteria(AchievementCriteriaTypes type, uint64 miscValue1, uint64 miscValue2, uint64 miscValue3, WorldObject* unit, Player* player, GameObject* go)
{
    m_achievementMgr->UpdateAchievementCriteria(type, miscValue1, miscValue2, miscValue3, unit, player, go);
}

void Guild::HandleNewsSetSticky(WorldSession* session, uint32 newsId, bool sticky)
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

    NewsLogEntry* news = (NewsLogEntry*)(*itr);
    news->SetSticky(sticky);

    TC_LOG_DEBUG("guild", "HandleNewsSetSticky: [%s] chenged newsId %u sticky to %u",
        session->GetPlayerInfo().c_str(), newsId, sticky);

    WorldPackets::Guild::GuildNews newsPacket;
    newsPacket.NewsEvents.reserve(1);
    news->WritePacket(newsPacket);
    session->SendPacket(newsPacket.Write());
}

void Guild::SendKnownRecipes(Player const* player)
{
    WorldPackets::Guild::GuildKnownRecipes packet;

    std::set<uint32> uniqueProfessions;
    std::unordered_map<uint32, std::array<uint8, GUILD_RECIPES_COUNT>> uniqueBitsMap;

    for (std::pair<uint32 const, Guild::Member*> const& memberPair : m_members)
    {
        Member* member = memberPair.second;

        for (uint8 i = 0; i < GUILD_PROFESSION_COUNT; i++)
        {
            GuildMemberProfessionData const& prof = member->GetProfessionData(i);
            if (uint32 skillId = prof.SkillId)
            {
                uniqueProfessions.insert(skillId);
                for (uint16 j = 0; j < GUILD_RECIPES_COUNT; j++)
                    uniqueBitsMap[skillId][j] |= prof.RecipeUniqueBits[j];
            }
        }
    }

    for (uint32 skill : uniqueProfessions)
    {
        WorldPackets::Guild::GuildRecipesData& data = packet.Recipes.emplace_back();
        data.SkillLineID = skill;
        for (uint16 i = 0; i < data.SkillLineBitArray.max_size(); i++)
            data.SkillLineBitArray[i] = uniqueBitsMap[skill][i];
    }

    player->SendDirectMessage(packet.Write());
}

void Guild::SendMembersForRecipe(Player const* player, uint32 skillLineId, uint32 spellId, uint32 uniqueBit)
{
    WorldPackets::Guild::GuildMembersWithRecipe packet;
    for (std::pair<uint32 const, Guild::Member*> const& memberPair : m_members)
    {
        Member* member = memberPair.second;
        for (uint8 i = 0; i < GUILD_PROFESSION_COUNT; i++)
        {
            GuildMemberProfessionData const& prof = member->GetProfessionData(i);
            if (prof.SkillId == skillLineId)
            {
                uint16 index = uniqueBit / 8;
                uint8 offset = uniqueBit % 8;
                uint8 bit = 1 << offset;
                if (prof.RecipeUniqueBits[index] & bit)
                    packet.Members.push_back(member->GetGUID());
            }
        }
    }

    packet.SkillLineID = skillLineId;
    packet.SpellID = spellId;
    player->SendDirectMessage(packet.Write());
}

void Guild::SendRecipesOfMember(Player const* player, uint32 skillLineId, ObjectGuid memberGuid)
{
    Member const* member = GetMember(memberGuid);
    WorldPackets::Guild::GuildMemberRecipes packet;
    packet.Member = memberGuid;
    packet.SkillLineBitArray.fill(0);

    for (uint8 i = 0; i < GUILD_PROFESSION_COUNT; i++)
    {
        GuildMemberProfessionData const& prof = member->GetProfessionData(i);
        if (prof.SkillId == skillLineId)
        {
            packet.SkillLineID = skillLineId;
            packet.SkillRank = prof.Rank;
            packet.SkillStep = prof.Step;
            for (uint16 j = 0; j < prof.RecipeUniqueBits.max_size(); j++)
                packet.SkillLineBitArray[j] |= prof.RecipeUniqueBits[j];
        }
    }
    player->SendDirectMessage(packet.Write());
}

void Guild::InitializeGuildChallengeRewards()
{
    // Initializing all possible fields so we wont end up with uninitialized fields in case of bad database data
    for (uint8 i = 0; i < MAX_GUILD_CHALLENGE_TYPES; i++)
    {
        _currChallengeCount[i] = 0;
        _maxChallengeCount[i] = 0;
        _challengeGold[i] = 0;
        _challengeGoldMaxLevel[i] = 0;
        _challengeXp[i] = 0;
    }

    // Assigning loaded guild challenge database data to guild data
    for (GuildChallenge challenge : sGuildMgr->GetGuildChallengeData())
    {
        _maxChallengeCount[challenge.ChallengeType] = challenge.ChallengeCount;
        _challengeGold[challenge.ChallengeType] = challenge.Gold;
        _challengeGoldMaxLevel[challenge.ChallengeType] = challenge.GoldMaxLevel;
        _challengeXp[challenge.ChallengeType] = challenge.Experience;
    }
}

void Guild::ClearExpiredNews()
{
    // Filter news that are older than a week
    uint64 minTime = uint64(GameTime::GetGameTime() - time_t(7 * DAY));

    if (GuildLog* logs = m_newsLog->GetGuildLog())
        for (GuildLog::const_iterator itr = logs->begin(); itr != logs->end(); ++itr)
            if ((*itr)->GetTimestamp() < minTime)
                itr = logs->erase(itr);
}

Guild::LogEntry::LogEntry(ObjectGuid::LowType guildId, uint32 guid) : m_guildId(guildId), m_guid(guid), m_timestamp(::GameTime::GetGameTime()) { }
