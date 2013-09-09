/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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
#include "CalendarMgr.h"
#include "Chat.h"
#include "Config.h"
#include "DatabaseEnv.h"
#include "Guild.h"
#include "GuildFinderMgr.h"
#include "GuildMgr.h"
#include "Language.h"
#include "Log.h"
#include "ScriptMgr.h"
#include "SocialMgr.h"
#include "Opcodes.h"

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
        case GE_BANK_MONEY_CHANGED:
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
    WorldPacket data(SMSG_GUILD_COMMAND_RESULT, 8 + param.size() + 1);
    data << uint32(type);
    data << param;
    data << uint32(errCode);
    session->SendPacket(&data);

    TC_LOG_DEBUG(LOG_FILTER_GUILD, "SMSG_GUILD_COMMAND_RESULT [%s]: Type: %u, code: %u, param: %s"
         , session->GetPlayerInfo().c_str(), type, errCode, param.c_str());
}

void Guild::SendSaveEmblemResult(WorldSession* session, GuildEmblemError errCode)
{
    WorldPacket data(MSG_SAVE_GUILD_EMBLEM, 4);
    data << uint32(errCode);
    session->SendPacket(&data);

    TC_LOG_DEBUG(LOG_FILTER_GUILD, "MSG_SAVE_GUILD_EMBLEM [%s] Code: %u", session->GetPlayerInfo().c_str(), errCode);
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
inline void Guild::LogHolder::AddEvent(SQLTransaction& trans, LogEntry* entry)
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

// Writes information about all events into packet.
inline void Guild::LogHolder::WritePacket(WorldPacket& data) const
{
    ByteBuffer buffer;
    data.WriteBits(m_log.size(), 23);
    for (GuildLog::const_iterator itr = m_log.begin(); itr != m_log.end(); ++itr)
        (*itr)->WritePacket(data, buffer);

    data.FlushBits();
    data.append(buffer);
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
void Guild::EventLogEntry::SaveToDB(SQLTransaction& trans) const
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_EVENTLOG);
    stmt->setUInt32(0, m_guildId);
    stmt->setUInt32(1, m_guid);
    CharacterDatabase.ExecuteOrAppend(trans, stmt);

    uint8 index = 0;
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_EVENTLOG);
    stmt->setUInt32(  index, m_guildId);
    stmt->setUInt32(++index, m_guid);
    stmt->setUInt8 (++index, uint8(m_eventType));
    stmt->setUInt32(++index, m_playerGuid1);
    stmt->setUInt32(++index, m_playerGuid2);
    stmt->setUInt8 (++index, m_newRank);
    stmt->setUInt64(++index, m_timestamp);
    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void Guild::EventLogEntry::WritePacket(WorldPacket& data, ByteBuffer& content) const
{
    ObjectGuid guid1 = MAKE_NEW_GUID(m_playerGuid1, 0, HIGHGUID_PLAYER);
    ObjectGuid guid2 = MAKE_NEW_GUID(m_playerGuid2, 0, HIGHGUID_PLAYER);

    data.WriteBit(guid1[2]);
    data.WriteBit(guid1[4]);
    data.WriteBit(guid2[7]);
    data.WriteBit(guid2[6]);
    data.WriteBit(guid1[3]);
    data.WriteBit(guid2[3]);
    data.WriteBit(guid2[5]);
    data.WriteBit(guid1[7]);
    data.WriteBit(guid1[5]);
    data.WriteBit(guid1[0]);
    data.WriteBit(guid2[4]);
    data.WriteBit(guid2[2]);
    data.WriteBit(guid2[0]);
    data.WriteBit(guid2[1]);
    data.WriteBit(guid1[1]);
    data.WriteBit(guid1[6]);

    content.WriteByteSeq(guid2[3]);
    content.WriteByteSeq(guid2[2]);
    content.WriteByteSeq(guid2[5]);

    // New Rank
    content << uint8(m_newRank);

    content.WriteByteSeq(guid2[4]);
    content.WriteByteSeq(guid1[0]);
    content.WriteByteSeq(guid1[4]);

    // Event timestamp
    content << uint32(::time(NULL) - m_timestamp);

    content.WriteByteSeq(guid1[7]);
    content.WriteByteSeq(guid1[3]);
    content.WriteByteSeq(guid2[0]);
    content.WriteByteSeq(guid2[6]);
    content.WriteByteSeq(guid2[7]);
    content.WriteByteSeq(guid1[5]);

    // Event type
    content << uint8(m_eventType);

    content.WriteByteSeq(guid2[1]);
    content.WriteByteSeq(guid1[2]);
    content.WriteByteSeq(guid1[6]);
    content.WriteByteSeq(guid1[1]);
}

// BankEventLogEntry
void Guild::BankEventLogEntry::SaveToDB(SQLTransaction& trans) const
{
    uint8 index = 0;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_BANK_EVENTLOG);
    stmt->setUInt32(  index, m_guildId);
    stmt->setUInt32(++index, m_guid);
    stmt->setUInt8 (++index, m_bankTabId);
    CharacterDatabase.ExecuteOrAppend(trans, stmt);

    index = 0;
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_BANK_EVENTLOG);
    stmt->setUInt32(  index, m_guildId);
    stmt->setUInt32(++index, m_guid);
    stmt->setUInt8 (++index, m_bankTabId);
    stmt->setUInt8 (++index, uint8(m_eventType));
    stmt->setUInt32(++index, m_playerGuid);
    stmt->setUInt32(++index, m_itemOrMoney);
    stmt->setUInt16(++index, m_itemStackCount);
    stmt->setUInt8 (++index, m_destTabId);
    stmt->setUInt64(++index, m_timestamp);
    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void Guild::BankEventLogEntry::WritePacket(WorldPacket& data, ByteBuffer& content) const
{
    ObjectGuid logGuid = MAKE_NEW_GUID(m_playerGuid, 0, HIGHGUID_PLAYER);

    bool hasItem = m_eventType == GUILD_BANK_LOG_DEPOSIT_ITEM || m_eventType == GUILD_BANK_LOG_WITHDRAW_ITEM ||
                   m_eventType == GUILD_BANK_LOG_MOVE_ITEM || m_eventType == GUILD_BANK_LOG_MOVE_ITEM2;

    bool itemMoved = (m_eventType == GUILD_BANK_LOG_MOVE_ITEM || m_eventType == GUILD_BANK_LOG_MOVE_ITEM2);

    bool hasStack = (hasItem && m_itemStackCount > 1) || itemMoved;

    data.WriteBit(IsMoneyEvent());
    data.WriteBit(logGuid[4]);
    data.WriteBit(logGuid[1]);
    data.WriteBit(hasItem);
    data.WriteBit(hasStack);
    data.WriteBit(logGuid[2]);
    data.WriteBit(logGuid[5]);
    data.WriteBit(logGuid[3]);
    data.WriteBit(logGuid[6]);
    data.WriteBit(logGuid[0]);
    data.WriteBit(itemMoved);
    data.WriteBit(logGuid[7]);

    content.WriteByteSeq(logGuid[6]);
    content.WriteByteSeq(logGuid[1]);
    content.WriteByteSeq(logGuid[5]);
    if (hasStack)
        content << uint32(m_itemStackCount);

    content << uint8(m_eventType);
    content.WriteByteSeq(logGuid[2]);
    content.WriteByteSeq(logGuid[4]);
    content.WriteByteSeq(logGuid[0]);
    content.WriteByteSeq(logGuid[7]);
    content.WriteByteSeq(logGuid[3]);
    if (hasItem)
        content << uint32(m_itemOrMoney);

    content << uint32(time(NULL) - m_timestamp);

    if (IsMoneyEvent())
        content << uint64(m_itemOrMoney);

    if (itemMoved)
        content << uint8(m_destTabId);
}

void Guild::NewsLogEntry::SaveToDB(SQLTransaction& trans) const
{
    uint8 index = 0;
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_NEWS);
    stmt->setUInt32(  index, m_guildId);
    stmt->setUInt32(++index, GetGUID());
    stmt->setUInt8 (++index, GetType());
    stmt->setUInt32(++index, GetPlayerGuid());
    stmt->setUInt32(++index, GetFlags());
    stmt->setUInt32(++index, GetValue());
    stmt->setUInt64(++index, GetTimestamp());
    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void Guild::NewsLogEntry::WritePacket(WorldPacket& data, ByteBuffer& /*content*/) const
{
    data.WriteBits(0, 26); // Not yet implemented used for guild achievements
    ObjectGuid guid = GetPlayerGuid();

    data.WriteBit(guid[7]);
    data.WriteBit(guid[0]);
    data.WriteBit(guid[6]);
    data.WriteBit(guid[5]);
    data.WriteBit(guid[4]);
    data.WriteBit(guid[3]);
    data.WriteBit(guid[1]);
    data.WriteBit(guid[2]);

    data.FlushBits();

    data.WriteByteSeq(guid[5]);

    data << uint32(GetFlags());   // 1 sticky
    data << uint32(GetValue());
    data << uint32(0);            // always 0

    data.WriteByteSeq(guid[7]);
    data.WriteByteSeq(guid[6]);
    data.WriteByteSeq(guid[2]);
    data.WriteByteSeq(guid[3]);
    data.WriteByteSeq(guid[0]);
    data.WriteByteSeq(guid[4]);
    data.WriteByteSeq(guid[1]);

    data << uint32(GetGUID());
    data << uint32(GetType());
    data.AppendPackedTime(GetTimestamp());
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

void Guild::RankInfo::SaveToDB(SQLTransaction& trans) const
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_RANK);
    stmt->setUInt32(0, m_guildId);
    stmt->setUInt8 (1, m_rankId);
    stmt->setString(2, m_name);
    stmt->setUInt32(3, m_rights);
    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void Guild::RankInfo::CreateMissingTabsIfNeeded(uint8 tabs, SQLTransaction& trans, bool logOnCreate /* = false */)
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
            TC_LOG_ERROR(LOG_FILTER_GUILD, "Guild %u has broken Tab %u for rank %u. Created default tab.", m_guildId, i, m_rankId);

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_BANK_RIGHT);
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

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_RANK_NAME);
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

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_RANK_RIGHTS);
    stmt->setUInt32(0, m_rights);
    stmt->setUInt8 (1, m_rankId);
    stmt->setUInt32(2, m_guildId);
    CharacterDatabase.Execute(stmt);
}

void Guild::RankInfo::SetBankMoneyPerDay(uint32 money)
{
    if (m_rankId == GR_GUILDMASTER)                     // Prevent loss of leader rights
        money = uint32(GUILD_WITHDRAW_MONEY_UNLIMITED);

    if (m_bankMoneyPerDay == money)
        return;

    m_bankMoneyPerDay = money;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_RANK_BANK_MONEY);
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
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_BANK_RIGHT);
        stmt->setUInt32(0, m_guildId);
        stmt->setUInt8 (1, guildBR.GetTabId());
        stmt->setUInt8 (2, m_rankId);
        stmt->setUInt8 (3, guildBR.GetRights());
        stmt->setUInt32(4, guildBR.GetSlots());
        CharacterDatabase.Execute(stmt);
    }
}

// BankTab
void Guild::BankTab::LoadFromDB(Field* fields)
{
    m_name = fields[2].GetString();
    m_icon = fields[3].GetString();
    m_text = fields[4].GetString();
}

bool Guild::BankTab::LoadItemFromDB(Field* fields)
{
    uint8 slotId = fields[13].GetUInt8();
    uint32 itemGuid = fields[14].GetUInt32();
    uint32 itemEntry = fields[15].GetUInt32();
    if (slotId >= GUILD_BANK_MAX_SLOTS)
    {
        TC_LOG_ERROR(LOG_FILTER_GUILD, "Invalid slot for item (GUID: %u, id: %u) in guild bank, skipped.", itemGuid, itemEntry);
        return false;
    }

    ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemEntry);
    if (!proto)
    {
        TC_LOG_ERROR(LOG_FILTER_GUILD, "Unknown item (GUID: %u, id: %u) in guild bank, skipped.", itemGuid, itemEntry);
        return false;
    }

    Item* pItem = NewItemOrBag(proto);
    if (!pItem->LoadFromDB(itemGuid, 0, fields, itemEntry))
    {
        TC_LOG_ERROR(LOG_FILTER_GUILD, "Item (GUID %u, id: %u) not found in item_instance, deleting from guild bank!", itemGuid, itemEntry);

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_NONEXISTENT_GUILD_BANK_ITEM);
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
void Guild::BankTab::Delete(SQLTransaction& trans, bool removeItemsFromDB)
{
    for (uint8 slotId = 0; slotId < GUILD_BANK_MAX_SLOTS; ++slotId)
        if (Item* pItem = m_items[slotId])
        {
            pItem->RemoveFromWorld();
            if (removeItemsFromDB)
                pItem->DeleteFromDB(trans);
            delete pItem;
            pItem = NULL;
        }
}

void Guild::BankTab::SetInfo(std::string const& name, std::string const& icon)
{
    if (m_name == name && m_icon == icon)
        return;

    m_name = name;
    m_icon = icon;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_BANK_TAB_INFO);
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

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_BANK_TAB_TEXT);
    stmt->setString(0, m_text);
    stmt->setUInt32(1, m_guildId);
    stmt->setUInt8 (2, m_tabId);
    CharacterDatabase.Execute(stmt);
}

// Sets/removes contents of specified slot.
// If pItem == NULL contents are removed.
bool Guild::BankTab::SetItem(SQLTransaction& trans, uint8 slotId, Item* item)
{
    if (slotId >= GUILD_BANK_MAX_SLOTS)
        return false;

    m_items[slotId] = item;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_BANK_ITEM);
    stmt->setUInt32(0, m_guildId);
    stmt->setUInt8 (1, m_tabId);
    stmt->setUInt8 (2, slotId);
    CharacterDatabase.ExecuteOrAppend(trans, stmt);

    if (item)
    {
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_BANK_ITEM);
        stmt->setUInt32(0, m_guildId);
        stmt->setUInt8 (1, m_tabId);
        stmt->setUInt8 (2, slotId);
        stmt->setUInt32(3, item->GetGUIDLow());
        CharacterDatabase.ExecuteOrAppend(trans, stmt);

        item->SetUInt64Value(ITEM_FIELD_CONTAINED, 0);
        item->SetUInt64Value(ITEM_FIELD_OWNER, 0);
        item->FSetState(ITEM_NEW);
        item->SaveToDB(trans);                                 // Not in inventory and can be saved standalone
    }
    return true;
}

void Guild::BankTab::SendText(Guild const* guild, WorldSession* session) const
{
    WorldPacket data(SMSG_GUILD_BANK_QUERY_TEXT_RESULT, 1 + m_text.size() + 1);
    data.WriteBits(m_text.length(), 14);
    data << uint32(m_tabId);
    data.WriteString(m_text);

    if (session)
    {
        TC_LOG_DEBUG(LOG_FILTER_GUILD, "SMSG_GUILD_BANK_QUERY_TEXT_RESULT [%s]: Tabid: %u, Text: %s"
            , session->GetPlayerInfo().c_str(), m_tabId, m_text.c_str());
        session->SendPacket(&data);
    }
    else
    {
        TC_LOG_DEBUG(LOG_FILTER_GUILD, "SMSG_GUILD_BANK_QUERY_TEXT_RESULT [Broadcast]: Tabid: %u, Text: %s", m_tabId, m_text.c_str());
        guild->BroadcastPacket(&data);
    }
}

// Member
void Guild::Member::SetStats(Player* player)
{
    m_name      = player->GetName();
    m_level     = player->getLevel();
    m_class     = player->getClass();
    m_zoneId    = player->GetZoneId();
    m_accountId = player->GetSession()->GetAccountId();
    m_achievementPoints = player->GetAchievementPoints();
}

void Guild::Member::SetStats(std::string const& name, uint8 level, uint8 _class, uint32 zoneId, uint32 accountId, uint32 reputation)
{
    m_name      = name;
    m_level     = level;
    m_class     = _class;
    m_zoneId    = zoneId;
    m_accountId = accountId;
    m_totalReputation = reputation;
}

void Guild::Member::SetPublicNote(std::string const& publicNote)
{
    if (m_publicNote == publicNote)
        return;

    m_publicNote = publicNote;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_MEMBER_PNOTE);
    stmt->setString(0, publicNote);
    stmt->setUInt32(1, GUID_LOPART(m_guid));
    CharacterDatabase.Execute(stmt);
}

void Guild::Member::SetOfficerNote(std::string const& officerNote)
{
    if (m_officerNote == officerNote)
        return;

    m_officerNote = officerNote;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_MEMBER_OFFNOTE);
    stmt->setString(0, officerNote);
    stmt->setUInt32(1, GUID_LOPART(m_guid));
    CharacterDatabase.Execute(stmt);
}

void Guild::Member::ChangeRank(uint8 newRank)
{
    m_rankId = newRank;

    // Update rank information in player's field, if he is online.
    if (Player* player = FindPlayer())
        player->SetRank(newRank);

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_MEMBER_RANK);
    stmt->setUInt8 (0, newRank);
    stmt->setUInt32(1, GUID_LOPART(m_guid));
    CharacterDatabase.Execute(stmt);
}

void Guild::Member::SaveToDB(SQLTransaction& trans) const
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_MEMBER);
    stmt->setUInt32(0, m_guildId);
    stmt->setUInt32(1, GUID_LOPART(m_guid));
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

    for (uint8 i = 0; i <= GUILD_BANK_MAX_TABS; ++i)
        m_bankWithdraw[i] = fields[5 + i].GetUInt32();

    SetStats(fields[14].GetString(),
             fields[15].GetUInt8(),                         // characters.level
             fields[16].GetUInt8(),                         // characters.class
             fields[17].GetUInt16(),                        // characters.zone
             fields[18].GetUInt32(),                        // characters.account
             0);
    m_logoutTime = fields[19].GetUInt32();                  // characters.logout_time
    m_totalActivity = 0;
    m_weekActivity = 0;
    m_weekReputation = 0;

    if (!CheckStats())
        return false;

    if (!m_zoneId)
    {
        TC_LOG_ERROR(LOG_FILTER_GUILD, "Player (GUID: %u) has broken zone-data", GUID_LOPART(m_guid));
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
        TC_LOG_ERROR(LOG_FILTER_GUILD, "Player (GUID: %u) has a broken data in field `characters`.`level`, deleting him from guild!", GUID_LOPART(m_guid));
        return false;
    }

    if (m_class < CLASS_WARRIOR || m_class >= MAX_CLASSES)
    {
        TC_LOG_ERROR(LOG_FILTER_GUILD, "Player (GUID: %u) has a broken data in field `characters`.`class`, deleting him from guild!", GUID_LOPART(m_guid));
        return false;
    }
    return true;
}

// Decreases amount of money/slots left for today.
// If (tabId == GUILD_BANK_MAX_TABS) decrease money amount.
// Otherwise decrease remaining items amount for specified tab.
void Guild::Member::UpdateBankWithdrawValue(SQLTransaction& trans, uint8 tabId, uint32 amount)
{
    m_bankWithdraw[tabId] += amount;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_MEMBER_WITHDRAW);
    stmt->setUInt32(0, GUID_LOPART(m_guid));
    for (uint8 i = 0; i <= GUILD_BANK_MAX_TABS;)
    {
        uint32 withdraw = m_bankWithdraw[i++];
        stmt->setUInt32(i, withdraw);
    }

    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void Guild::Member::ResetValues(bool weekly /* = false*/)
{
    for (uint8 tabId = 0; tabId <= GUILD_BANK_MAX_TABS; ++tabId)
        m_bankWithdraw[tabId] = 0;

    if (weekly)
    {
        m_weekActivity = 0;
        m_weekReputation = 0;
    }
}

// Get amount of money/slots left for today.
// If (tabId == GUILD_BANK_MAX_TABS) return money amount.
// Otherwise return remaining items amount for specified tab.
int32 Guild::Member::GetBankWithdrawValue(uint8 tabId) const
{
    // Guild master has unlimited amount.
    if (IsRank(GR_GUILDMASTER))
        return tabId == GUILD_BANK_MAX_TABS ? GUILD_WITHDRAW_MONEY_UNLIMITED : GUILD_WITHDRAW_SLOT_UNLIMITED;

    return m_bankWithdraw[tabId];
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

void EmblemInfo::WritePacket(WorldPacket& data) const
{
    data << uint32(m_style);
    data << uint32(m_color);
    data << uint32(m_borderStyle);
    data << uint32(m_borderColor);
    data << uint32(m_backgroundColor);
}

void EmblemInfo::SaveToDB(uint32 guildId) const
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_EMBLEM_INFO);
    stmt->setUInt32(0, m_style);
    stmt->setUInt32(1, m_color);
    stmt->setUInt32(2, m_borderStyle);
    stmt->setUInt32(3, m_borderColor);
    stmt->setUInt32(4, m_backgroundColor);
    stmt->setUInt32(5, guildId);
    CharacterDatabase.Execute(stmt);
}

// MoveItemData
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
    for (ItemPosCountVec::const_iterator itr = m_vec.begin(); itr != m_vec.end(); ++itr)
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
            m_pItem = NULL;
        }
        // Bound items cannot be put into bank.
        else if (!m_pItem->CanBeTraded())
        {
            m_pPlayer->SendEquipError(EQUIP_ERR_CANT_SWAP, m_pItem);
            m_pItem = NULL;
        }
    }
    return (m_pItem != NULL);
}

void Guild::PlayerMoveItemData::RemoveItem(SQLTransaction& trans, MoveItemData* /*pOther*/, uint32 splitedAmount)
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
        m_pItem = NULL;
    }
}

Item* Guild::PlayerMoveItemData::StoreItem(SQLTransaction& trans, Item* pItem)
{
    ASSERT(pItem);
    m_pPlayer->MoveItemToInventory(m_vec, pItem, true);
    m_pPlayer->SaveInventoryAndGoldToDB(trans);
    return pItem;
}

void Guild::PlayerMoveItemData::LogBankEvent(SQLTransaction& trans, MoveItemData* pFrom, uint32 count) const
{
    ASSERT(pFrom);
    // Bank -> Char
    m_pGuild->_LogBankEvent(trans, GUILD_BANK_LOG_WITHDRAW_ITEM, pFrom->GetContainer(), m_pPlayer->GetGUIDLow(),
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
    return (m_pItem != NULL);
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

void Guild::BankMoveItemData::RemoveItem(SQLTransaction& trans, MoveItemData* pOther, uint32 splitedAmount)
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
        m_pItem = NULL;
    }
    // Decrease amount of player's remaining items (if item is moved to different tab or to player)
    if (!pOther->IsBank() || pOther->GetContainer() != m_container)
        m_pGuild->_UpdateMemberWithdrawSlots(trans, m_pPlayer->GetGUID(), m_container);
}

Item* Guild::BankMoveItemData::StoreItem(SQLTransaction& trans, Item* pItem)
{
    if (!pItem)
        return NULL;

    BankTab* pTab = m_pGuild->GetBankTab(m_container);
    if (!pTab)
        return NULL;

    Item* pLastItem = pItem;
    for (ItemPosCountVec::const_iterator itr = m_vec.begin(); itr != m_vec.end(); )
    {
        ItemPosCount pos(*itr);
        ++itr;

        TC_LOG_DEBUG(LOG_FILTER_GUILD, "GUILD STORAGE: StoreItem tab = %u, slot = %u, item = %u, count = %u",
            m_container, m_slotId, pItem->GetEntry(), pItem->GetCount());
        pLastItem = _StoreItem(trans, pTab, pItem, pos, itr != m_vec.end());
    }
    return pLastItem;
}

void Guild::BankMoveItemData::LogBankEvent(SQLTransaction& trans, MoveItemData* pFrom, uint32 count) const
{
    ASSERT(pFrom->GetItem());
    if (pFrom->IsBank())
        // Bank -> Bank
        m_pGuild->_LogBankEvent(trans, GUILD_BANK_LOG_MOVE_ITEM, pFrom->GetContainer(), m_pPlayer->GetGUIDLow(),
            pFrom->GetItem()->GetEntry(), count, m_container);
    else
        // Char -> Bank
        m_pGuild->_LogBankEvent(trans, GUILD_BANK_LOG_DEPOSIT_ITEM, m_container, m_pPlayer->GetGUIDLow(),
            pFrom->GetItem()->GetEntry(), count);
}

void Guild::BankMoveItemData::LogAction(MoveItemData* pFrom) const
{
    MoveItemData::LogAction(pFrom);
    if (!pFrom->IsBank() && m_pPlayer->GetSession()->HasPermission(RBAC_PERM_LOG_GM_TRADE)) /// @todo Move this to scripts
    {
        sLog->outCommand(m_pPlayer->GetSession()->GetAccountId(),
            "GM %s (Guid: %u) (Account: %u) deposit item: %s (Entry: %d Count: %u) to guild bank named: %s (Guild ID: %u)",
            m_pPlayer->GetName().c_str(), m_pPlayer->GetGUIDLow(), m_pPlayer->GetSession()->GetAccountId(),
            pFrom->GetItem()->GetTemplate()->Name1.c_str(), pFrom->GetItem()->GetEntry(), pFrom->GetItem()->GetCount(),
            m_pGuild->GetName().c_str(), m_pGuild->GetId());
    }
}

Item* Guild::BankMoveItemData::_StoreItem(SQLTransaction& trans, BankTab* pTab, Item* pItem, ItemPosCount& pos, bool clone) const
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

    return NULL;
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
            pItemDest = NULL;

        // If merge skip empty, if not merge skip non-empty
        if ((pItemDest != NULL) != merge)
            continue;

        _ReserveSpace(slotId, pItem, pItemDest, count);
    }
}

InventoryResult Guild::BankMoveItemData::CanStore(Item* pItem, bool swap)
{
    TC_LOG_DEBUG(LOG_FILTER_GUILD, "GUILD STORAGE: CanStore() tab = %u, slot = %u, item = %u, count = %u",
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
            pItemDest = NULL;

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
    m_leaderGuid(0),
    m_createdDate(0),
    m_accountsNumber(0),
    m_bankMoney(0),
    m_eventLog(NULL),
    m_newsLog(NULL),
    m_achievementMgr(this),
    _level(1),
    _experience(0),
    _todayExperience(0)
{
    memset(&m_bankEventLog, 0, (GUILD_BANK_MAX_TABS + 1) * sizeof(LogHolder*));
}

Guild::~Guild()
{
    SQLTransaction temp(NULL);
    _DeleteBankItems(temp);

    // Cleanup
    delete m_eventLog;
    m_eventLog = NULL;
    delete m_newsLog;
    m_newsLog = NULL;

    for (uint8 tabId = 0; tabId <= GUILD_BANK_MAX_TABS; ++tabId)
    {
        delete m_bankEventLog[tabId];
        m_bankEventLog[tabId] = NULL;
    }

    for (Members::iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
    {
        delete itr->second;
        itr->second = NULL;
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
    m_createdDate = ::time(NULL);
    _level = 1;
    _experience = 0;
    _todayExperience = 0;
    _CreateLogHolders();

    TC_LOG_DEBUG(LOG_FILTER_GUILD, "GUILD: creating guild [%s] for leader %s (%u)",
        name.c_str(), pLeader->GetName().c_str(), GUID_LOPART(m_leaderGuid));

    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_MEMBERS);
    stmt->setUInt32(0, m_id);
    trans->Append(stmt);

    uint8 index = 0;
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD);
    stmt->setUInt32(  index, m_id);
    stmt->setString(++index, name);
    stmt->setUInt32(++index, GUID_LOPART(m_leaderGuid));
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

    CharacterDatabase.CommitTransaction(trans);
    _CreateDefaultGuildRanks(pLeaderSession->GetSessionDbLocaleIndex()); // Create default ranks
    bool ret = AddMember(m_leaderGuid, GR_GUILDMASTER);                  // Add guildmaster

    if (ret)
    {
        _BroadcastEvent(GE_FOUNDER, 0);
        sScriptMgr->OnGuildCreate(this, pLeader, name);
    }

    return ret;
}

// Disbands guild and deletes all related data from database
void Guild::Disband()
{
    // Call scripts before guild data removed from database
    sScriptMgr->OnGuildDisband(this);

    _BroadcastEvent(GE_DISBANDED, 0);
    // Remove all members
    while (!m_members.empty())
    {
        Members::const_iterator itr = m_members.begin();
        DeleteMember(itr->second->GetGUID(), true);
    }

    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD);
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
    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_EXPERIENCE);
    stmt->setUInt32(0, GetLevel());
    stmt->setUInt64(1, GetExperience());
    stmt->setUInt64(2, GetTodayExperience());
    stmt->setUInt32(3, GetId());
    trans->Append(stmt);

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
                TC_LOG_ERROR(LOG_FILTER_GUILD, "Guild::UpdateMemberData: Called with incorrect DATAID %u (value %u)", dataid, value);
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
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_NAME);
    stmt->setString(0, m_name);
    stmt->setUInt32(1, GetId());
    CharacterDatabase.Execute(stmt);

    ObjectGuid guid = GetGUID();
    WorldPacket data(SMSG_GUILD_RENAMED, 24 + 8 + 1);
    data.WriteBit(guid[5]);
    data.WriteBits(name.length(), 8);
    data.WriteBit(guid[4]);
    data.WriteBit(guid[0]);
    data.WriteBit(guid[6]);
    data.WriteBit(guid[3]);
    data.WriteBit(guid[1]);
    data.WriteBit(guid[7]);
    data.WriteBit(guid[2]);

    data.WriteByteSeq(guid[3]);
    data.WriteByteSeq(guid[2]);
    data.WriteByteSeq(guid[7]);
    data.WriteByteSeq(guid[1]);
    data.WriteByteSeq(guid[0]);
    data.WriteByteSeq(guid[6]);
    data.WriteString(name);
    data.WriteByteSeq(guid[4]);
    data.WriteByteSeq(guid[5]);

    BroadcastPacket(&data);
    return true;
}

void Guild::HandleRoster(WorldSession* session /*= NULL*/)
{
    ByteBuffer memberData(100);
    // Guess size
    WorldPacket data(SMSG_GUILD_ROSTER, 100);
    data.WriteBits(m_motd.length(), 11);
    data.WriteBits(m_members.size(), 18);

    for (Members::const_iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
    {
        Member* member = itr->second;
        size_t pubNoteLength = member->GetPublicNote().length();
        size_t offNoteLength = member->GetOfficerNote().length();

        ObjectGuid guid = member->GetGUID();
        data.WriteBit(guid[3]);
        data.WriteBit(guid[4]);
        data.WriteBit(0); // Has Authenticator
        data.WriteBit(0); // Can Scroll of Ressurect
        data.WriteBits(pubNoteLength, 8);
        data.WriteBits(offNoteLength, 8);
        data.WriteBit(guid[0]);
        data.WriteBits(member->GetName().length(), 7);
        data.WriteBit(guid[1]);
        data.WriteBit(guid[2]);
        data.WriteBit(guid[6]);
        data.WriteBit(guid[5]);
        data.WriteBit(guid[7]);

        memberData << uint8(member->GetClass());
        memberData << uint32(member->GetTotalReputation());
        memberData.WriteByteSeq(guid[0]);
        memberData << uint64(member->GetWeekActivity());
        memberData << uint32(member->GetRankId());
        memberData << uint32(member->GetAchievementPoints());

        // for (2 professions)
        memberData << uint32(0) << uint32(0) << uint32(0);
        memberData << uint32(0) << uint32(0) << uint32(0);

        memberData.WriteByteSeq(guid[2]);
        memberData << uint8(member->GetFlags());
        memberData << uint32(member->GetZoneId());
        memberData << uint64(member->GetTotalActivity());
        memberData.WriteByteSeq(guid[7]);
        memberData << uint32(sWorld->getIntConfig(CONFIG_GUILD_WEEKLY_REP_CAP) - member->GetWeekReputation());

        if (pubNoteLength)
            memberData.WriteString(member->GetPublicNote());

        memberData.WriteByteSeq(guid[3]);
        memberData << uint8(member->GetLevel());
        memberData << int32(0);                                     // unk
        memberData.WriteByteSeq(guid[5]);
        memberData.WriteByteSeq(guid[4]);
        memberData << uint8(0);                                     // unk
        memberData.WriteByteSeq(guid[1]);
        memberData << float(member->IsOnline() ? 0.0f : float(::time(NULL) - member->GetLogoutTime()) / DAY);

        if (offNoteLength)
            memberData.WriteString(member->GetOfficerNote());

        memberData.WriteByteSeq(guid[6]);
        memberData.WriteString(member->GetName());
    }

    size_t infoLength = m_info.length();
    data.WriteBits(infoLength, 12);

    data.FlushBits();
    data.append(memberData);

    if (infoLength)
        data.WriteString(m_info);

    data.WriteString(m_motd);
    data << uint32(m_accountsNumber);
    data << uint32(sWorld->getIntConfig(CONFIG_GUILD_WEEKLY_REP_CAP));
    data.AppendPackedTime(m_createdDate);
    data << uint32(0);

    if (session)
    {
        TC_LOG_DEBUG(LOG_FILTER_GUILD, "SMSG_GUILD_ROSTER [%s]", session->GetPlayerInfo().c_str());
        session->SendPacket(&data);
    }
    else
    {
        TC_LOG_DEBUG(LOG_FILTER_GUILD, "SMSG_GUILD_ROSTER [Broadcast]");
        BroadcastPacket(&data);
    }
}

void Guild::HandleQuery(WorldSession* session)
{
    WorldPacket data(SMSG_GUILD_QUERY_RESPONSE, 8 * 32 + 200);      // Guess size

    data << uint64(GetGUID());
    data << m_name;

    // Rank name
    for (uint8 i = 0; i < GUILD_RANKS_MAX_COUNT; ++i)               // Always show 10 ranks
    {
        if (i < _GetRanksSize())
            data << m_ranks[i].GetName();
        else
            data << uint8(0);                                       // Empty string
    }

    // Rank order of creation
    for (uint8 i = 0; i < GUILD_RANKS_MAX_COUNT; ++i)
    {
        if (i < _GetRanksSize())
            data << uint32(i);
        else
            data << uint32(0);
    }

    // Rank order of "importance" (sorting by rights)
    for (uint8 i = 0; i < GUILD_RANKS_MAX_COUNT; ++i)
    {
        if (i < _GetRanksSize())
            data << uint32(m_ranks[i].GetId());
        else
            data << uint32(0);
    }

    m_emblemInfo.WritePacket(data);
    data << uint32(_GetRanksSize());                                // Number of ranks used

    session->SendPacket(&data);
    TC_LOG_DEBUG(LOG_FILTER_GUILD, "SMSG_GUILD_QUERY_RESPONSE [%s]", session->GetPlayerInfo().c_str());
}

void Guild::SendGuildRankInfo(WorldSession* session) const
{
    ByteBuffer rankData(100);
    WorldPacket data(SMSG_GUILD_RANK, 100);

    data.WriteBits(_GetRanksSize(), 18);

    for (uint8 i = 0; i < _GetRanksSize(); i++)
    {
        RankInfo const* rankInfo = GetRankInfo(i);
        if (!rankInfo)
            continue;

        data.WriteBits(rankInfo->GetName().length(), 7);

        rankData << uint32(rankInfo->GetId());

        for (uint8 j = 0; j < GUILD_BANK_MAX_TABS; ++j)
        {
            rankData << uint32(rankInfo->GetBankTabSlotsPerDay(j));
            rankData << uint32(rankInfo->GetBankTabRights(j));
        }

        rankData << uint32(rankInfo->GetBankMoneyPerDay());
        rankData << uint32(rankInfo->GetRights());

        if (rankInfo->GetName().length())
            rankData.WriteString(rankInfo->GetName());

        rankData << uint32(i);
    }

    data.FlushBits();
    data.append(rankData);
    session->SendPacket(&data);
    TC_LOG_DEBUG(LOG_FILTER_GUILD, "SMSG_GUILD_RANK [%s]", session->GetPlayerInfo().c_str());
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

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_MOTD);
        stmt->setString(0, motd);
        stmt->setUInt32(1, m_id);
        CharacterDatabase.Execute(stmt);

        _BroadcastEvent(GE_MOTD, 0, motd.c_str());
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

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_INFO);
        stmt->setString(0, info);
        stmt->setUInt32(1, m_id);
        CharacterDatabase.Execute(stmt);
    }
}

void Guild::HandleSetEmblem(WorldSession* session, const EmblemInfo& emblemInfo)
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

        HandleQuery(session);
    }
}

void Guild::HandleSetNewGuildMaster(WorldSession* session, std::string const& name)
{
    Player* player = session->GetPlayer();
    // Only the guild master can throne a new guild master
    if (!_IsLeader(player))
        SendCommandResult(session, GUILD_COMMAND_CHANGE_LEADER, ERR_GUILD_PERMISSIONS);
    // Old GM must be a guild member
    else if (Member* oldGuildMaster = GetMember(player->GetGUID()))
    {
        // Same for the new one
        if (Member* newGuildMaster = GetMember(name))
        {
            _SetLeaderGUID(newGuildMaster);
            oldGuildMaster->ChangeRank(GR_INITIATE);
            _BroadcastEvent(GE_LEADER_CHANGED, 0, player->GetName().c_str(), name.c_str());
        }
    }
}

void Guild::HandleSetBankTabInfo(WorldSession* session, uint8 tabId, std::string const& name, std::string const& icon)
{
    BankTab* tab = GetBankTab(tabId);
    if (!tab)
    {
        TC_LOG_ERROR(LOG_FILTER_GUILD, "Guild::HandleSetBankTabInfo: Player %s trying to change bank tab info from unexisting tab %d.",
                       session->GetPlayerInfo().c_str(), tabId);
        return;
    }

    char aux[2];
    sprintf(aux, "%u", tabId);

    tab->SetInfo(name, icon);
    _BroadcastEvent(GE_BANK_TAB_UPDATED, 0, aux, name.c_str(), icon.c_str());
}

void Guild::HandleSetMemberNote(WorldSession* session, std::string const& note, uint64 guid, bool isPublic)
{
    // Player must have rights to set public/officer note
    if (!_HasRankRight(session->GetPlayer(), isPublic ? GR_RIGHT_EPNOTE : GR_RIGHT_EOFFNOTE))
        SendCommandResult(session, GUILD_COMMAND_PUBLIC_NOTE, ERR_GUILD_PERMISSIONS);
    else if (Member* member = GetMember(guid))
    {
        if (isPublic)
            member->SetPublicNote(note);
        else
            member->SetOfficerNote(note);

        HandleRoster(session); // FIXME - We should send SMSG_GUILD_MEMBER_UPDATE_NOTE
    }
}

void Guild::HandleSetRankInfo(WorldSession* session, uint8 rankId, std::string const& name, uint32 rights, uint32 moneyPerDay, const GuildBankRightsAndSlotsVec& rightsAndSlots)
{
    // Only leader can modify ranks
    if (!_IsLeader(session->GetPlayer()))
        SendCommandResult(session, GUILD_COMMAND_CHANGE_RANK, ERR_GUILD_PERMISSIONS);
    else if (RankInfo* rankInfo = GetRankInfo(rankId))
    {
        TC_LOG_DEBUG(LOG_FILTER_GUILD, "Changed RankName to '%s', rights to 0x%08X", name.c_str(), rights);

        rankInfo->SetName(name);
        rankInfo->SetRights(rights);
        _SetRankBankMoneyPerDay(rankId, moneyPerDay);

        for (GuildBankRightsAndSlotsVec::const_iterator itr = rightsAndSlots.begin(); itr != rightsAndSlots.end(); ++itr)
            _SetRankBankTabRightsAndSlots(rankId, *itr);

        char aux[2];
        sprintf(aux, "%u", rankId);
        _BroadcastEvent(GE_RANK_UPDATED, 0, aux);
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
    _BroadcastEvent(GE_BANK_TAB_PURCHASED, 0);
    SendPermissions(session); /// Hack to force client to update permissions
}

void Guild::HandleInviteMember(WorldSession* session, std::string const& name)
{
    Player* pInvitee = sObjectAccessor->FindPlayerByName(name);
    if (!pInvitee)
    {
        SendCommandResult(session, GUILD_COMMAND_INVITE, ERR_GUILD_PLAYER_NOT_FOUND_S, name);
        return;
    }

    Player* player = session->GetPlayer();
    // Do not show invitations from ignored players
    if (pInvitee->GetSocial()->HasIgnore(player->GetGUIDLow()))
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

    TC_LOG_DEBUG(LOG_FILTER_GUILD, "Player %s invited %s to join his Guild", player->GetName().c_str(), name.c_str());

    pInvitee->SetGuildIdInvited(m_id);
    _LogEvent(GUILD_EVENT_LOG_INVITE_PLAYER, player->GetGUIDLow(), pInvitee->GetGUIDLow());

    WorldPacket data(SMSG_GUILD_INVITE, 100);
    data << uint32(GetLevel());
    data << uint32(m_emblemInfo.GetBorderStyle());
    data << uint32(m_emblemInfo.GetBorderColor());
    data << uint32(m_emblemInfo.GetStyle());
    data << uint32(m_emblemInfo.GetBackgroundColor());
    data << uint32(m_emblemInfo.GetColor());

    ObjectGuid oldGuildGuid = MAKE_NEW_GUID(pInvitee->GetGuildId(), 0, pInvitee->GetGuildId() ? uint32(HIGHGUID_GUILD) : 0);
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
    pInvitee->GetSession()->SendPacket(&data);
    TC_LOG_DEBUG(LOG_FILTER_GUILD, "SMSG_GUILD_INVITE [%s]", pInvitee->GetName().c_str());
}

void Guild::HandleAcceptMember(WorldSession* session)
{
    Player* player = session->GetPlayer();
    if (!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD) &&
        player->GetTeam() != sObjectMgr->GetPlayerTeamByGUID(GetLeaderGUID()))
        return;

    AddMember(player->GetGUID());
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
        DeleteMember(player->GetGUID(), false, false);

        _LogEvent(GUILD_EVENT_LOG_LEAVE_GUILD, player->GetGUIDLow());
        _BroadcastEvent(GE_LEFT, player->GetGUID(), player->GetName().c_str());

        SendCommandResult(session, GUILD_COMMAND_QUIT, ERR_GUILD_COMMAND_SUCCESS, m_name);
    }

    sCalendarMgr->RemovePlayerGuildEventsAndSignups(player->GetGUID(), GetId());

    if (disband)
        delete this;
}

void Guild::HandleRemoveMember(WorldSession* session, uint64 guid)
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
                DeleteMember(guid, false, true);
                _LogEvent(GUILD_EVENT_LOG_UNINVITE_PLAYER, player->GetGUIDLow(), GUID_LOPART(guid));
                _BroadcastEvent(GE_REMOVED, 0, name.c_str(), player->GetName().c_str());
                SendCommandResult(session, GUILD_COMMAND_REMOVE, ERR_GUILD_COMMAND_SUCCESS, name);
            }
        }
    }
}

void Guild::HandleUpdateMemberRank(WorldSession* session, uint64 guid, bool demote)
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
        member->ChangeRank(newRankId);
        _LogEvent(demote ? GUILD_EVENT_LOG_DEMOTE_PLAYER : GUILD_EVENT_LOG_PROMOTE_PLAYER, player->GetGUIDLow(), GUID_LOPART(member->GetGUID()), newRankId);
        _BroadcastEvent(demote ? GE_DEMOTION : GE_PROMOTION, 0, player->GetName().c_str(), name.c_str(), _GetRankName(newRankId).c_str());
    }
}

void Guild::HandleSetMemberRank(WorldSession* session, uint64 targetGuid, uint64 setterGuid, uint32 rank)
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
        if (_CreateRank(name, GR_RIGHT_GCHATLISTEN | GR_RIGHT_GCHATSPEAK))
            _BroadcastEvent(GE_RANK_CREATED, 0);
}

void Guild::HandleRemoveRank(WorldSession* session, uint8 rankId)
{
    // Cannot remove rank if total count is minimum allowed by the client or is not leader
    if (_GetRanksSize() <= GUILD_RANKS_MIN_COUNT || rankId >= _GetRanksSize() || !_IsLeader(session->GetPlayer()))
        return;

    // Delete bank rights for rank
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_BANK_RIGHTS_FOR_RANK);
    stmt->setUInt32(0, m_id);
    stmt->setUInt8(1, rankId);
    CharacterDatabase.Execute(stmt);
    // Delete rank
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_RANK);
    stmt->setUInt32(0, m_id);
    stmt->setUInt8(1, rankId);
    CharacterDatabase.Execute(stmt);

    m_ranks.erase(m_ranks.begin() + rankId);

    _BroadcastEvent(GE_RANK_DELETED, rankId);
}

void Guild::HandleMemberDepositMoney(WorldSession* session, uint64 amount, bool cashFlow /*=false*/)
{
    Player* player = session->GetPlayer();

    // Call script after validation and before money transfer.
    sScriptMgr->OnGuildMemberDepositMoney(this, player, amount);

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    _ModifyBankMoney(trans, amount, true);
    if (!cashFlow)
    {
        player->ModifyMoney(-int64(amount));
        player->SaveGoldToDB(trans);
    }

    _LogBankEvent(trans, cashFlow ? GUILD_BANK_LOG_CASH_FLOW_DEPOSIT : GUILD_BANK_LOG_DEPOSIT_MONEY, uint8(0), player->GetGUIDLow(), amount);
    CharacterDatabase.CommitTransaction(trans);

    std::string aux = ByteArrayToHexStr(reinterpret_cast<uint8*>(&amount), 8, true);
    _BroadcastEvent(GE_BANK_MONEY_CHANGED, 0, aux.c_str());

    if (player->GetSession()->HasPermission(RBAC_PERM_LOG_GM_TRADE))
    {
        sLog->outCommand(player->GetSession()->GetAccountId(),
            "GM %s (Account: %u) deposit money (Amount: " UI64FMTD ") to guild bank (Guild ID %u)",
            player->GetName().c_str(), player->GetSession()->GetAccountId(), amount, m_id);
    }
}

bool Guild::HandleMemberWithdrawMoney(WorldSession* session, uint64 amount, bool repair)
{
    if (m_bankMoney < amount)                               // Not enough money in bank
        return false;

    Player* player = session->GetPlayer();

    Member* member = GetMember(player->GetGUID());
    if (!member)
        return false;

   if (uint64(_GetMemberRemainingMoney(member)) < amount)   // Check if we have enough slot/money today
       return false;

    // Call script after validation and before money transfer.
    sScriptMgr->OnGuildMemberWitdrawMoney(this, player, amount, repair);

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    // Add money to player (if required)
    if (!repair)
    {
        if (!player->ModifyMoney(amount))
            return false;

        player->SaveGoldToDB(trans);
    }

    // Update remaining money amount
    member->UpdateBankWithdrawValue(trans, GUILD_BANK_MAX_TABS, amount);
    // Remove money from bank
    _ModifyBankMoney(trans, amount, false);

    // Log guild bank event
    _LogBankEvent(trans, repair ? GUILD_BANK_LOG_REPAIR_MONEY : GUILD_BANK_LOG_WITHDRAW_MONEY, uint8(0), player->GetGUIDLow(), amount);
    CharacterDatabase.CommitTransaction(trans);

    std::string aux = ByteArrayToHexStr(reinterpret_cast<uint8*>(&amount), 8, true);
    _BroadcastEvent(GE_BANK_MONEY_CHANGED, 0, aux.c_str());
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
        TC_LOG_DEBUG(LOG_FILTER_GUILD, "Guild Successfully Disbanded");
        delete this;
    }
}

void Guild::HandleGuildPartyRequest(WorldSession* session)
{
    Player* player = session->GetPlayer();
    Group* group = player->GetGroup();

    // Make sure player is a member of the guild and that he is in a group.
    if (!IsMember(player->GetGUID()) || !group)
        return;

    WorldPacket data(SMSG_GUILD_PARTY_STATE_RESPONSE, 13);
    data.WriteBit(player->GetMap()->GetOwnerGuildId(player->GetTeam()) == GetId()); // Is guild group
    data.FlushBits();
    data << float(0.f);                                                             // Guild XP multiplier
    data << uint32(0);                                                              // Current guild members
    data << uint32(0);                                                              // Needed guild members

    session->SendPacket(&data);
    TC_LOG_DEBUG(LOG_FILTER_GUILD, "SMSG_GUILD_PARTY_STATE_RESPONSE [%s]", session->GetPlayerInfo().c_str());
}

void Guild::SendEventLog(WorldSession* session) const
{
    WorldPacket data(SMSG_GUILD_EVENT_LOG_QUERY_RESULT, 1 + m_eventLog->GetSize() * (1 + 8 + 4));
    m_eventLog->WritePacket(data);
    session->SendPacket(&data);
    TC_LOG_DEBUG(LOG_FILTER_GUILD, "SMSG_GUILD_EVENT_LOG_QUERY_RESULT [%s]", session->GetPlayerInfo().c_str());
}

void Guild::SendNewsUpdate(WorldSession* session)
{
    uint32 size = m_newsLog->GetSize();
    GuildLog* logs = m_newsLog->GetGuildLog();

    if (!logs)
        return;

    WorldPacket data(SMSG_GUILD_NEWS_UPDATE, (21 + size * (26 + 8)) / 8 + (8 + 6 * 4) * size);
    data.WriteBits(size, 21);

    for (GuildLog::const_iterator itr = logs->begin(); itr != logs->end(); ++itr)
    {
        data.WriteBits(0, 26); // Not yet implemented used for guild achievements
        ObjectGuid guid = ((NewsLogEntry*)(*itr))->GetPlayerGuid();

        data.WriteBit(guid[7]);
        data.WriteBit(guid[0]);
        data.WriteBit(guid[6]);
        data.WriteBit(guid[5]);
        data.WriteBit(guid[4]);
        data.WriteBit(guid[3]);
        data.WriteBit(guid[1]);
        data.WriteBit(guid[2]);
    }

    data.FlushBits();

    for (GuildLog::const_iterator itr = logs->begin(); itr != logs->end(); ++itr)
    {
        NewsLogEntry* news = (NewsLogEntry*)(*itr);
        ObjectGuid guid = news->GetPlayerGuid();
        data.WriteByteSeq(guid[5]);

        data << uint32(news->GetFlags());   // 1 sticky
        data << uint32(news->GetValue());
        data << uint32(0);

        data.WriteByteSeq(guid[7]);
        data.WriteByteSeq(guid[6]);
        data.WriteByteSeq(guid[2]);
        data.WriteByteSeq(guid[3]);
        data.WriteByteSeq(guid[0]);
        data.WriteByteSeq(guid[4]);
        data.WriteByteSeq(guid[1]);

        data << uint32(news->GetGUID());
        data << uint32(news->GetType());
        data.AppendPackedTime(news->GetTimestamp());
    }

    session->SendPacket(&data);
    TC_LOG_DEBUG(LOG_FILTER_GUILD, "SMSG_GUILD_NEWS_UPDATE [%s]", session->GetPlayerInfo().c_str());
}

void Guild::SendBankLog(WorldSession* session, uint8 tabId) const
{
    // GUILD_BANK_MAX_TABS send by client for money log
    if (tabId < _GetPurchasedTabsSize() || tabId == GUILD_BANK_MAX_TABS)
    {
        LogHolder const* log = m_bankEventLog[tabId];
        WorldPacket data(SMSG_GUILD_BANK_LOG_QUERY_RESULT, log->GetSize() * (4 * 4 + 1) + 1 + 1);
        data.WriteBit(GetLevel() >= 5 && tabId == GUILD_BANK_MAX_TABS);     // has Cash Flow perk
        log->WritePacket(data);
        data << uint32(tabId);
        //if (tabId == GUILD_BANK_MAX_TABS && hasCashFlow)
        //    data << uint64(cashFlowContribution);
        session->SendPacket(&data);
        TC_LOG_DEBUG(LOG_FILTER_GUILD, "SMSG_GUILD_BANK_LOG_QUERY_RESULT [%s] TabId: %u", session->GetPlayerInfo().c_str(), tabId);
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
    data << uint32(_GetMemberRemainingMoney(member));
    data.WriteBits(GUILD_BANK_MAX_TABS, 23);
    for (uint8 tabId = 0; tabId < GUILD_BANK_MAX_TABS; ++tabId)
    {
        data << uint32(_GetRankBankTabRights(rankId, tabId));
        data << uint32(_GetMemberRemainingSlots(member, tabId));
    }

    session->SendPacket(&data);
    TC_LOG_DEBUG(LOG_FILTER_GUILD, "SMSG_GUILD_PERMISSIONS_QUERY_RESULTS [%s] Rank: %u", session->GetPlayerInfo().c_str(), rankId);
}

void Guild::SendMoneyInfo(WorldSession* session) const
{
    Member const* member = GetMember(session->GetPlayer()->GetGUID());
    if (!member)
        return;

    int32 amount = _GetMemberRemainingMoney(member);
    WorldPacket data(SMSG_GUILD_BANK_MONEY_WITHDRAWN, 8);
    data << int64(amount);
    session->SendPacket(&data);
    TC_LOG_DEBUG(LOG_FILTER_GUILD, "SMSG_GUILD_BANK_MONEY_WITHDRAWN [%s] Money: %u", session->GetPlayerInfo().c_str(), amount);
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

    WorldPacket data(SMSG_GUILD_EVENT, 1 + 1 + m_motd.size() + 1);
    data << uint8(GE_MOTD);
    data << uint8(1);
    data << m_motd;
    session->SendPacket(&data);

    TC_LOG_DEBUG(LOG_FILTER_GUILD, "SMSG_GUILD_EVENT [%s] MOTD", session->GetPlayerInfo().c_str());

    SendGuildRankInfo(session);
    _BroadcastEvent(GE_SIGNED_ON, player->GetGUID(), player->GetName().c_str());

    // Send to self separately, player is not in world yet and is not found by _BroadcastEvent
    data.Initialize(SMSG_GUILD_EVENT, 1 + 1 + player->GetName().size() + 8);
    data << uint8(GE_SIGNED_ON);
    data << uint8(1);
    data << player->GetName();
    data << uint64(player->GetGUID());
    session->SendPacket(&data);

    data.Initialize(SMSG_GUILD_MEMBER_DAILY_RESET, 0);  // tells the client to request bank withdrawal limit
    session->SendPacket(&data);

    if (!sWorld->getBoolConfig(CONFIG_GUILD_LEVELING_ENABLED))
        return;

    for (uint32 i = 0; i < sGuildPerkSpellsStore.GetNumRows(); ++i)
        if (GuildPerkSpellsEntry const* entry = sGuildPerkSpellsStore.LookupEntry(i))
            if (entry->Level <= GetLevel())
                player->learnSpell(entry->SpellId, true);

    SendGuildReputationWeeklyCap(session, member->GetWeekReputation());

    m_achievementMgr.SendAllAchievementData(player);

    member->SetStats(player);
    member->AddFlag(GUILDMEMBER_STATUS_ONLINE);
}

// Loading methods
bool Guild::LoadFromDB(Field* fields)
{
    m_id            = fields[0].GetUInt32();
    m_name          = fields[1].GetString();
    m_leaderGuid    = MAKE_NEW_GUID(fields[2].GetUInt32(), 0, HIGHGUID_PLAYER);
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
    uint32 lowguid = fields[1].GetUInt32();
    Member *member = new Member(m_id, MAKE_NEW_GUID(lowguid, 0, HIGHGUID_PLAYER), fields[2].GetUInt8());
    if (!member->LoadFromDB(fields))
    {
        _DeleteMemberFromDB(lowguid);
        delete member;
        return false;
    }
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
            uint32 guid = fields[2].GetUInt32();
            GuildBankEventLogTypes eventType = GuildBankEventLogTypes(fields[3].GetUInt8());
            if (BankEventLogEntry::IsMoneyEvent(eventType))
            {
                if (!isMoneyTab)
                {
                    TC_LOG_ERROR(LOG_FILTER_GUILD, "GuildBankEventLog ERROR: MoneyEvent(LogGuid: %u, Guild: %u) does not belong to money tab (%u), ignoring...", guid, m_id, dbTabId);
                    return false;
                }
            }
            else if (isMoneyTab)
            {
                TC_LOG_ERROR(LOG_FILTER_GUILD, "GuildBankEventLog ERROR: non-money event (LogGuid: %u, Guild: %u) belongs to money tab, ignoring...", guid, m_id);
                return false;
            }
            pLog->LoadEvent(new BankEventLogEntry(
                m_id,                                   // guild id
                guid,                                   // guid
                time_t(fields[8].GetUInt32()),          // timestamp
                dbTabId,                                // tab id
                eventType,                              // event type
                fields[4].GetUInt32(),                  // player guid
                fields[5].GetUInt32(),                  // item or money
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
    m_id,                                       // guild id
    fields[1].GetUInt32(),                      // guid
    fields[6].GetUInt32(),                      // timestamp //64 bits?
    GuildNews(fields[2].GetUInt8()),            // type
    fields[3].GetUInt32(),                      // player guid
    fields[4].GetUInt32(),                      // Flags
    fields[5].GetUInt32()));                    // value
}

void Guild::LoadBankTabFromDB(Field* fields)
{
    uint8 tabId = fields[1].GetUInt8();
    if (tabId >= _GetPurchasedTabsSize())
        TC_LOG_ERROR(LOG_FILTER_GUILD, "Invalid tab (tabId: %u) in guild bank, skipped.", tabId);
    else
        m_bankTabs[tabId]->LoadFromDB(fields);
}

bool Guild::LoadBankItemFromDB(Field* fields)
{
    uint8 tabId = fields[12].GetUInt8();
    if (tabId >= _GetPurchasedTabsSize())
    {
        TC_LOG_ERROR(LOG_FILTER_GUILD, "Invalid tab for item (GUID: %u, id: #%u) in guild bank, skipped.",
            fields[14].GetUInt32(), fields[15].GetUInt32());
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
    if (ranks < GUILD_RANKS_MIN_COUNT || ranks > GUILD_RANKS_MAX_COUNT)
    {
        TC_LOG_ERROR(LOG_FILTER_GUILD, "Guild %u has invalid number of ranks, creating new...", m_id);
        broken_ranks = true;
    }
    else
    {
        for (uint8 rankId = 0; rankId < ranks; ++rankId)
        {
            RankInfo* rankInfo = GetRankInfo(rankId);
            if (rankInfo->GetId() != rankId)
            {
                TC_LOG_ERROR(LOG_FILTER_GUILD, "Guild %u has broken rank id %u, creating default set of ranks...", m_id, rankId);
                broken_ranks = true;
            }
            else
            {
                SQLTransaction trans = CharacterDatabase.BeginTransaction();
                rankInfo->CreateMissingTabsIfNeeded(_GetPurchasedTabsSize(), trans, true);
                CharacterDatabase.CommitTransaction(trans);
            }
        }
    }

    if (broken_ranks)
    {
        m_ranks.clear();
        _CreateDefaultGuildRanks(DEFAULT_LOCALE);
    }

    // Validate members' data
    for (Members::iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
        if (itr->second->GetRankId() > _GetRanksSize())
            itr->second->ChangeRank(_GetLowestRankId());

    // Repair the structure of the guild.
    // If the guildmaster doesn't exist or isn't member of the guild
    // attempt to promote another member.
    Member* pLeader = GetMember(m_leaderGuid);
    if (!pLeader)
    {
        DeleteMember(m_leaderGuid);
        // If no more members left, disband guild
        if (m_members.empty())
        {
            Disband();
            return false;
        }
    }
    else if (!pLeader->IsRank(GR_GUILDMASTER))
        _SetLeaderGUID(pLeader);

    // Check config if multiple guildmasters are allowed
    if (!sConfigMgr->GetBoolDefault("Guild.AllowMultipleGuildMaster", 0))
        for (Members::iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
            if (itr->second->GetRankId() == GR_GUILDMASTER && !itr->second->IsSamePlayer(m_leaderGuid))
                itr->second->ChangeRank(GR_OFFICER);

    _UpdateAccountsNumber();
    return true;
}

// Broadcasts
void Guild::BroadcastToGuild(WorldSession* session, bool officerOnly, std::string const& msg, uint32 language) const
{
    if (session && session->GetPlayer() && _HasRankRight(session->GetPlayer(), officerOnly ? GR_RIGHT_OFFCHATSPEAK : GR_RIGHT_GCHATSPEAK))
    {
        WorldPacket data;
        ChatHandler::FillMessageData(&data, session, officerOnly ? CHAT_MSG_OFFICER : CHAT_MSG_GUILD, language, NULL, 0, msg.c_str(), NULL);
        for (Members::const_iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
            if (Player* player = itr->second->FindPlayer())
                if (player->GetSession() && _HasRankRight(player, officerOnly ? GR_RIGHT_OFFCHATLISTEN : GR_RIGHT_GCHATLISTEN) &&
                    !player->GetSocial()->HasIgnore(session->GetPlayer()->GetGUIDLow()))
                    player->GetSession()->SendPacket(&data);
    }
}

void Guild::BroadcastAddonToGuild(WorldSession* session, bool officerOnly, std::string const& msg, std::string const& prefix) const
{
    if (session && session->GetPlayer() && _HasRankRight(session->GetPlayer(), officerOnly ? GR_RIGHT_OFFCHATSPEAK : GR_RIGHT_GCHATSPEAK))
    {
        WorldPacket data;
        ChatHandler::FillMessageData(&data, session, officerOnly ? CHAT_MSG_OFFICER : CHAT_MSG_GUILD, uint32(CHAT_MSG_ADDON), NULL, 0, msg.c_str(), NULL, prefix.c_str());
        for (Members::const_iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
            if (Player* player = itr->second->FindPlayer())
                if (player->GetSession() && _HasRankRight(player, officerOnly ? GR_RIGHT_OFFCHATLISTEN : GR_RIGHT_GCHATLISTEN) &&
                    !player->GetSocial()->HasIgnore(session->GetPlayer()->GetGUIDLow()) &&
                    player->GetSession()->IsAddonRegistered(prefix))
                        player->GetSession()->SendPacket(&data);
    }
}

void Guild::BroadcastPacketToRank(WorldPacket* packet, uint8 rankId) const
{
    for (Members::const_iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
        if (itr->second->IsRank(rankId))
            if (Player* player = itr->second->FindPlayer())
                player->GetSession()->SendPacket(packet);
}

void Guild::BroadcastPacket(WorldPacket* packet) const
{
    for (Members::const_iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
        if (Player* player = itr->second->FindPlayer())
            player->GetSession()->SendPacket(packet);
}

void Guild::MassInviteToEvent(WorldSession* session, uint32 minLevel, uint32 maxLevel, uint32 minRank)
{
    uint32 count = 0;

    WorldPacket data(SMSG_CALENDAR_FILTER_GUILD);
    data << uint32(count); // count placeholder

    for (Members::const_iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
    {
        // not sure if needed, maybe client checks it as well
        if (count >= CALENDAR_MAX_INVITES)
        {
            if (Player* player = session->GetPlayer())
                sCalendarMgr->SendCalendarCommandResult(player->GetGUID(), CALENDAR_ERROR_INVITES_EXCEEDED);
            return;
        }

        Member* member = itr->second;
        uint32 level = Player::GetLevelFromDB(member->GetGUID());

        if (member->GetGUID() != session->GetPlayer()->GetGUID() && level >= minLevel && level <= maxLevel && member->IsRankNotLower(minRank))
        {
            data.appendPackGUID(member->GetGUID());
            data << uint8(0); // unk
            ++count;
        }
    }

    data.put<uint32>(0, count);

    session->SendPacket(&data);
}

// Members handling
bool Guild::AddMember(uint64 guid, uint8 rankId)
{
    Player* player = ObjectAccessor::FindPlayer(guid);
    // Player cannot be in guild
    if (player)
    {
        if (player->GetGuildId() != 0)
            return false;
    }
    else if (Player::GetGuildIdFromDB(guid) != 0)
        return false;

    // Remove all player signs from another petitions
    // This will be prevent attempt to join many guilds and corrupt guild data integrity
    Player::RemovePetitionsAndSigns(guid, GUILD_CHARTER_TYPE);

    uint32 lowguid = GUID_LOPART(guid);

    // If rank was not passed, assign lowest possible rank
    if (rankId == GUILD_RANK_NONE)
        rankId = _GetLowestRankId();

    Member* member = new Member(m_id, guid, rankId);
    std::string name;
    if (player)
    {
        m_members[lowguid] = member;
        player->SetInGuild(m_id);
        player->SetGuildIdInvited(0);
        player->SetRank(rankId);
        player->SetGuildLevel(GetLevel());
        SendLoginInfo(player->GetSession());
        name = player->GetName();
    }
    else
    {
        member->ResetFlags();

        bool ok = false;
        // Player must exist
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_DATA_FOR_GUILD);
        stmt->setUInt32(0, lowguid);
        if (PreparedQueryResult result = CharacterDatabase.Query(stmt))
        {
            Field* fields = result->Fetch();
            name = fields[0].GetString();
            member->SetStats(
                name,
                fields[1].GetUInt8(),
                fields[2].GetUInt8(),
                fields[3].GetUInt16(),
                fields[4].GetUInt32(),
                0);

            ok = member->CheckStats();
        }

        if (!ok)
        {
            delete member;
            return false;
        }
        m_members[lowguid] = member;
    }

    SQLTransaction trans(NULL);
    member->SaveToDB(trans);

    _UpdateAccountsNumber();
    _LogEvent(GUILD_EVENT_LOG_JOIN_GUILD, lowguid);
    _BroadcastEvent(GE_JOINED, guid, name.c_str());
    sGuildFinderMgr->RemoveAllMembershipRequestsFromPlayer(lowguid);

    // Call scripts if member was succesfully added (and stored to database)
    sScriptMgr->OnGuildAddMember(this, player, rankId);

    return true;
}

void Guild::DeleteMember(uint64 guid, bool isDisbanding, bool isKicked, bool canDeleteGuild)
{
    uint32 lowguid = GUID_LOPART(guid);
    Player* player = ObjectAccessor::FindPlayer(guid);

    // Guild master can be deleted when loading guild and guid doesn't exist in characters table
    // or when he is removed from guild by gm command
    if (m_leaderGuid == guid && !isDisbanding)
    {
        Member* oldLeader = NULL;
        Member* newLeader = NULL;
        for (Guild::Members::iterator i = m_members.begin(); i != m_members.end(); ++i)
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

        _SetLeaderGUID(newLeader);

        // If player not online data in data field will be loaded from guild tabs no need to update it !!
        if (Player* newLeaderPlayer = newLeader->FindPlayer())
            newLeaderPlayer->SetRank(GR_GUILDMASTER);

        // If leader does not exist (at guild loading with deleted leader) do not send broadcasts
        if (oldLeader)
        {
            _BroadcastEvent(GE_LEADER_CHANGED, 0, oldLeader->GetName().c_str(), newLeader->GetName().c_str());
            _BroadcastEvent(GE_LEFT, guid, oldLeader->GetName().c_str());
        }
    }
    // Call script on remove before member is actually removed from guild (and database)
    sScriptMgr->OnGuildRemoveMember(this, player, isDisbanding, isKicked);

    if (Member* member = GetMember(guid))
        delete member;
    m_members.erase(lowguid);

    // If player not online data in data field will be loaded from guild tabs no need to update it !!
    if (player)
    {
        player->SetInGuild(0);
        player->SetRank(0);
        player->SetGuildLevel(0);

        for (uint32 i = 0; i < sGuildPerkSpellsStore.GetNumRows(); ++i)
            if (GuildPerkSpellsEntry const* entry = sGuildPerkSpellsStore.LookupEntry(i))
                if (entry->Level <= GetLevel())
                    player->removeSpell(entry->SpellId, false, false);
    }

    _DeleteMemberFromDB(lowguid);
    if (!isDisbanding)
        _UpdateAccountsNumber();
}

bool Guild::ChangeMemberRank(uint64 guid, uint8 newRank)
{
    if (newRank <= _GetLowestRankId())                    // Validate rank (allow only existing ranks)
        if (Member* member = GetMember(guid))
        {
            member->ChangeRank(newRank);
            return true;
        }
    return false;
}

bool Guild::IsMember(uint64 guid) const
{
    Members::const_iterator itr = m_members.find(GUID_LOPART(guid));
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
        pTab->SendText(this, NULL);
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

    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_BANK_TAB);
    stmt->setUInt32(0, m_id);
    stmt->setUInt8 (1, tabId);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_BANK_TAB);
    stmt->setUInt32(0, m_id);
    stmt->setUInt8 (1, tabId);
    trans->Append(stmt);

    ++tabId;
    for (Ranks::iterator itr = m_ranks.begin(); itr != m_ranks.end(); ++itr)
        (*itr).CreateMissingTabsIfNeeded(tabId, trans, false);

    CharacterDatabase.CommitTransaction(trans);
}

void Guild::_CreateDefaultGuildRanks(LocaleConstant loc)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_RANKS);
    stmt->setUInt32(0, m_id);
    CharacterDatabase.Execute(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_BANK_RIGHTS);
    stmt->setUInt32(0, m_id);
    CharacterDatabase.Execute(stmt);

    _CreateRank(sObjectMgr->GetTrinityString(LANG_GUILD_MASTER,   loc), GR_RIGHT_ALL);
    _CreateRank(sObjectMgr->GetTrinityString(LANG_GUILD_OFFICER,  loc), GR_RIGHT_ALL);
    _CreateRank(sObjectMgr->GetTrinityString(LANG_GUILD_VETERAN,  loc), GR_RIGHT_GCHATLISTEN | GR_RIGHT_GCHATSPEAK);
    _CreateRank(sObjectMgr->GetTrinityString(LANG_GUILD_MEMBER,   loc), GR_RIGHT_GCHATLISTEN | GR_RIGHT_GCHATSPEAK);
    _CreateRank(sObjectMgr->GetTrinityString(LANG_GUILD_INITIATE, loc), GR_RIGHT_GCHATLISTEN | GR_RIGHT_GCHATSPEAK);
}

bool Guild::_CreateRank(std::string const& name, uint32 rights)
{
    uint8 newRankId = _GetRanksSize();
    if (newRankId >= GUILD_RANKS_MAX_COUNT)
        return false;

    // Ranks represent sequence 0, 1, 2, ... where 0 means guildmaster
    RankInfo info(m_id, newRankId, name, rights, 0);
    m_ranks.push_back(info);

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    info.CreateMissingTabsIfNeeded(_GetPurchasedTabsSize(), trans);
    info.SaveToDB(trans);
    CharacterDatabase.CommitTransaction(trans);

    return true;
}

// Updates the number of accounts that are in the guild
// Player may have many characters in the guild, but with the same account
void Guild::_UpdateAccountsNumber()
{
    // We use a set to be sure each element will be unique
    std::set<uint32> accountsIdSet;
    for (Members::const_iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
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
    if (const Member* member = GetMember(player->GetGUID()))
        return member->IsRank(GR_GUILDMASTER);
    return false;
}

void Guild::_DeleteBankItems(SQLTransaction& trans, bool removeItemsFromDB)
{
    for (uint8 tabId = 0; tabId < _GetPurchasedTabsSize(); ++tabId)
    {
        m_bankTabs[tabId]->Delete(trans, removeItemsFromDB);
        delete m_bankTabs[tabId];
        m_bankTabs[tabId] = NULL;
    }
    m_bankTabs.clear();
}

bool Guild::_ModifyBankMoney(SQLTransaction& trans, uint64 amount, bool add)
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

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_BANK_MONEY);
    stmt->setUInt64(0, m_bankMoney);
    stmt->setUInt32(1, m_id);
    trans->Append(stmt);
    return true;
}

void Guild::_SetLeaderGUID(Member* pLeader)
{
    if (!pLeader)
        return;

    m_leaderGuid = pLeader->GetGUID();
    pLeader->ChangeRank(GR_GUILDMASTER);

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_LEADER);
    stmt->setUInt32(0, GUID_LOPART(m_leaderGuid));
    stmt->setUInt32(1, m_id);
    CharacterDatabase.Execute(stmt);
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
    if (const RankInfo* rankInfo = GetRankInfo(rankId))
        return rankInfo->GetName();
    return "<unknown>";
}

inline uint32 Guild::_GetRankRights(uint8 rankId) const
{
    if (const RankInfo* rankInfo = GetRankInfo(rankId))
        return rankInfo->GetRights();
    return 0;
}

inline int32 Guild::_GetRankBankMoneyPerDay(uint8 rankId) const
{
    if (const RankInfo* rankInfo = GetRankInfo(rankId))
        return rankInfo->GetBankMoneyPerDay();
    return 0;
}

inline int32 Guild::_GetRankBankTabSlotsPerDay(uint8 rankId, uint8 tabId) const
{
    if (tabId < _GetPurchasedTabsSize())
        if (const RankInfo* rankInfo = GetRankInfo(rankId))
            return rankInfo->GetBankTabSlotsPerDay(tabId);
    return 0;
}

inline int8 Guild::_GetRankBankTabRights(uint8 rankId, uint8 tabId) const
{
    if (const RankInfo* rankInfo = GetRankInfo(rankId))
        return rankInfo->GetBankTabRights(tabId);
    return 0;
}

inline int32 Guild::_GetMemberRemainingSlots(Member const* member, uint8 tabId) const
{
    if (member)
    {
        uint8 rankId = member->GetRankId();
        if (rankId == GR_GUILDMASTER)
            return GUILD_WITHDRAW_SLOT_UNLIMITED;
        if ((_GetRankBankTabRights(rankId, tabId) & GUILD_BANK_RIGHT_VIEW_TAB) != 0)
        {
            int32 remaining = _GetRankBankTabSlotsPerDay(rankId, tabId) - member->GetBankWithdrawValue(tabId);
            if (remaining > 0)
                return remaining;
        }
    }
    return 0;
}

inline int32 Guild::_GetMemberRemainingMoney(Member const* member) const
{
    if (member)
    {
        uint8 rankId = member->GetRankId();
        if (rankId == GR_GUILDMASTER)
            return GUILD_WITHDRAW_MONEY_UNLIMITED;

        if ((_GetRankRights(rankId) & (GR_RIGHT_WITHDRAW_REPAIR | GR_RIGHT_WITHDRAW_GOLD)) != 0)
        {
            int32 remaining = _GetRankBankMoneyPerDay(rankId) - member->GetBankWithdrawValue(GUILD_BANK_MAX_TABS);
            if (remaining > 0)
                return remaining;
        }
    }
    return 0;
}

inline void Guild::_UpdateMemberWithdrawSlots(SQLTransaction& trans, uint64 guid, uint8 tabId)
{
    if (Member* member = GetMember(guid))
    {
        uint8 rankId = member->GetRankId();
        if (rankId != GR_GUILDMASTER
            && member->GetBankWithdrawValue(tabId) < _GetRankBankTabSlotsPerDay(rankId, tabId))
            member->UpdateBankWithdrawValue(trans, tabId, 1);
    }
}

inline bool Guild::_MemberHasTabRights(uint64 guid, uint8 tabId, uint32 rights) const
{
    if (const Member* member = GetMember(guid))
    {
        // Leader always has full rights
        if (member->IsRank(GR_GUILDMASTER) || m_leaderGuid == guid)
            return true;
        return (_GetRankBankTabRights(member->GetRankId(), tabId) & rights) == rights;
    }
    return false;
}

// Add new event log record
inline void Guild::_LogEvent(GuildEventLogTypes eventType, uint32 playerGuid1, uint32 playerGuid2, uint8 newRank)
{
    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    m_eventLog->AddEvent(trans, new EventLogEntry(m_id, m_eventLog->GetNextGUID(), eventType, playerGuid1, playerGuid2, newRank));
    CharacterDatabase.CommitTransaction(trans);

    sScriptMgr->OnGuildEvent(this, uint8(eventType), playerGuid1, playerGuid2, newRank);
}

// Add new bank event log record
void Guild::_LogBankEvent(SQLTransaction& trans, GuildBankEventLogTypes eventType, uint8 tabId, uint32 lowguid, uint32 itemOrMoney, uint16 itemStackCount, uint8 destTabId)
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
    return NULL;
}

inline void Guild::_RemoveItem(SQLTransaction& trans, uint8 tabId, uint8 slotId)
{
    if (BankTab* pTab = GetBankTab(tabId))
        pTab->SetItem(trans, slotId, NULL);
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
        TC_LOG_FATAL(LOG_FILTER_GUILD, "Guild::SwapItems: Player %s(GUIDLow: %u) tried to move item %u from tab %u slot %u to tab %u slot %u, but item %u has a stack of zero!",
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
        _DoItemsMove(pSrc, pDest, true, splitedAmount);
    }
    else // 6. No split
    {
        // 6.1. Try to merge items in destination (pDest->GetItem() == NULL)
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

            // 6.2.3. Swap items (pDest->GetItem() != NULL)
            _DoItemsMove(pSrc, pDest, true);
        }
    }
    // 7. Send changes
    _SendBankContentUpdate(pSrc, pDest);
}

bool Guild::_DoItemsMove(MoveItemData* pSrc, MoveItemData* pDest, bool sendError, uint32 splitedAmount)
{
    Item* pDestItem = pDest->GetItem();
    bool swap = (pDestItem != NULL);

    Item* pSrcItem = pSrc->GetItem(splitedAmount);
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

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
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
        ByteBuffer tabData;
        WorldPacket data(SMSG_GUILD_BANK_LIST, 1200);
        data.WriteBit(0);
        data.WriteBits(slots.size(), 20);                                           // Item count
        data.WriteBits(0, 22);                                                      // Tab count

        for (SlotIds::const_iterator itr = slots.begin(); itr != slots.end(); ++itr)
        {
            data.WriteBit(0);

            Item const* tabItem = tab->GetItem(*itr);
            uint32 enchantCount = 0;
            if (tabItem)
            {
                for (uint32 enchSlot = 0; enchSlot < MAX_ENCHANTMENT_SLOT; ++enchSlot)
                {
                    if (uint32 enchantId = tabItem->GetEnchantmentId(EnchantmentSlot(enchSlot)))
                    {
                        tabData << uint32(enchantId);
                        tabData << uint32(enchSlot);
                        ++enchantCount;
                    }
                }
            }

            data.WriteBits(enchantCount, 23);                                       // enchantment count

            tabData << uint32(0);
            tabData << uint32(0);
            tabData << uint32(0);
            tabData << uint32(tabItem ? tabItem->GetCount() : 0);                   // ITEM_FIELD_STACK_COUNT
            tabData << uint32(*itr);
            tabData << uint32(0);
            tabData << uint32(tabItem ? tabItem->GetEntry() : 0);
            tabData << uint32(tabItem ? tabItem->GetItemRandomPropertyId() : 0);
            tabData << uint32(tabItem ? abs(tabItem->GetSpellCharges()) : 0);       // Spell charges
            tabData << uint32(tabItem ? tabItem->GetItemSuffixFactor() : 0);        // SuffixFactor
        }

        data.FlushBits();

        data << uint64(m_bankMoney);
        if (!tabData.empty())
            data.append(tabData);

        data << uint32(tabId);

        size_t rempos = data.wpos();
        data << uint32(0);                                      // Item withdraw amount, will be filled later

        for (Members::const_iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
            if (_MemberHasTabRights(itr->second->GetGUID(), tabId, GUILD_BANK_RIGHT_VIEW_TAB))
                if (Player* player = itr->second->FindPlayer())
                {
                    data.put<uint32>(rempos, uint32(_GetMemberRemainingSlots(itr->second, tabId)));
                    player->GetSession()->SendPacket(&data);
                }

        TC_LOG_DEBUG(LOG_FILTER_GUILD, "WORLD: Sent (SMSG_GUILD_BANK_LIST)");
    }
}

void Guild::_BroadcastEvent(GuildEvents guildEvent, uint64 guid, const char* param1, const char* param2, const char* param3) const
{
    uint8 count = !param3 ? (!param2 ? (!param1 ? 0 : 1) : 2) : 3;

    WorldPacket data(SMSG_GUILD_EVENT, 1 + 1 + count + (guid ? 8 : 0));
    data << uint8(guildEvent);
    data << uint8(count);

    if (param3)
        data << param1 << param2 << param3;
    else if (param2)
        data << param1 << param2;
    else if (param1)
        data << param1;

    if (guid)
        data << uint64(guid);

    BroadcastPacket(&data);

    if (sLog->ShouldLog(LOG_FILTER_GUILD, LOG_LEVEL_DEBUG))
        TC_LOG_DEBUG(LOG_FILTER_GUILD, "SMSG_GUILD_EVENT [Broadcast] Event: %s (%u)", _GetGuildEventString(guildEvent).c_str(), guildEvent);
}

void Guild::SendBankList(WorldSession* session, uint8 tabId, bool withContent, bool withTabInfo) const
{
    Member const* member = GetMember(session->GetPlayer()->GetGUID());
    if (!member) // Shouldn't happen, just in case
        return;

    ByteBuffer tabData;
    WorldPacket data(SMSG_GUILD_BANK_LIST, 500);
    data.WriteBit(0);
    uint32 itemCount = 0;
    if (withContent && _MemberHasTabRights(session->GetPlayer()->GetGUID(), tabId, GUILD_BANK_RIGHT_VIEW_TAB))
        if (BankTab const* tab = GetBankTab(tabId))
            for (uint8 slotId = 0; slotId < GUILD_BANK_MAX_SLOTS; ++slotId)
                if (tab->GetItem(slotId))
                    ++itemCount;

    data.WriteBits(itemCount, 20);
    data.WriteBits(withTabInfo ? _GetPurchasedTabsSize() : 0, 22);
    if (withContent && _MemberHasTabRights(session->GetPlayer()->GetGUID(), tabId, GUILD_BANK_RIGHT_VIEW_TAB))
    {
        if (BankTab const* tab = GetBankTab(tabId))
        {
            for (uint8 slotId = 0; slotId < GUILD_BANK_MAX_SLOTS; ++slotId)
            {
                if (Item* tabItem = tab->GetItem(slotId))
                {
                    data.WriteBit(0);

                    uint32 enchants = 0;
                    for (uint32 ench = 0; ench < MAX_ENCHANTMENT_SLOT; ++ench)
                    {
                        if (uint32 enchantId = tabItem->GetEnchantmentId(EnchantmentSlot(ench)))
                        {
                            tabData << uint32(enchantId);
                            tabData << uint32(ench);
                            ++enchants;
                        }
                    }

                    data.WriteBits(enchants, 23);

                    tabData << uint32(0);
                    tabData << uint32(0);
                    tabData << uint32(0);
                    tabData << uint32(tabItem->GetCount());                 // ITEM_FIELD_STACK_COUNT
                    tabData << uint32(slotId);
                    tabData << uint32(0);
                    tabData << uint32(tabItem->GetEntry());
                    tabData << uint32(tabItem->GetItemRandomPropertyId());
                    tabData << uint32(abs(tabItem->GetSpellCharges()));     // Spell charges
                    tabData << uint32(tabItem->GetItemSuffixFactor());      // SuffixFactor
                }
            }
        }
    }

    if (withTabInfo)
    {
        for (uint8 i = 0; i < _GetPurchasedTabsSize(); ++i)
        {
            data.WriteBits(m_bankTabs[i]->GetIcon().length(), 9);
            data.WriteBits(m_bankTabs[i]->GetName().length(), 7);
        }
    }

    data.FlushBits();

    if (withTabInfo)
    {
        for (uint8 i = 0; i < _GetPurchasedTabsSize(); ++i)
        {
            data.WriteString(m_bankTabs[i]->GetIcon());
            data << uint32(i);
            data.WriteString(m_bankTabs[i]->GetName());
        }
    }

    data << uint64(m_bankMoney);
    if (!tabData.empty())
        data.append(tabData);

    data << uint32(tabId);
    data << uint32(_GetMemberRemainingSlots(member, tabId));

    session->SendPacket(&data);

    TC_LOG_DEBUG(LOG_FILTER_GUILD, "WORLD: Sent (SMSG_GUILD_BANK_LIST)");
}

void Guild::SendGuildRanksUpdate(uint64 setterGuid, uint64 targetGuid, uint32 rank)
{
    ObjectGuid tarGuid = targetGuid;
    ObjectGuid setGuid = setterGuid;

    Member* member = GetMember(targetGuid);
    ASSERT(member);

    WorldPacket data(SMSG_GUILD_RANKS_UPDATE, 100);
    data.WriteBit(setGuid[7]);
    data.WriteBit(setGuid[2]);
    data.WriteBit(tarGuid[2]);
    data.WriteBit(setGuid[1]);
    data.WriteBit(tarGuid[1]);
    data.WriteBit(tarGuid[7]);
    data.WriteBit(tarGuid[0]);
    data.WriteBit(tarGuid[5]);
    data.WriteBit(tarGuid[4]);
    data.WriteBit(rank < member->GetRankId()); // 1 == higher, 0 = lower?
    data.WriteBit(setGuid[5]);
    data.WriteBit(setGuid[0]);
    data.WriteBit(tarGuid[6]);
    data.WriteBit(setGuid[3]);
    data.WriteBit(setGuid[6]);
    data.WriteBit(tarGuid[3]);
    data.WriteBit(setGuid[4]);

    data.FlushBits();

    data << uint32(rank);
    data.WriteByteSeq(setGuid[3]);
    data.WriteByteSeq(tarGuid[7]);
    data.WriteByteSeq(setGuid[6]);
    data.WriteByteSeq(setGuid[2]);
    data.WriteByteSeq(tarGuid[5]);
    data.WriteByteSeq(tarGuid[0]);
    data.WriteByteSeq(setGuid[7]);
    data.WriteByteSeq(setGuid[5]);
    data.WriteByteSeq(tarGuid[2]);
    data.WriteByteSeq(tarGuid[1]);
    data.WriteByteSeq(setGuid[0]);
    data.WriteByteSeq(setGuid[4]);
    data.WriteByteSeq(setGuid[1]);
    data.WriteByteSeq(tarGuid[3]);
    data.WriteByteSeq(tarGuid[6]);
    data.WriteByteSeq(tarGuid[4]);
    BroadcastPacket(&data);

    member->ChangeRank(rank);

    TC_LOG_DEBUG(LOG_FILTER_NETWORKIO, "SMSG_GUILD_RANKS_UPDATE [Broadcast] Target: %u, Issuer: %u, RankId: %u",
        GUID_LOPART(targetGuid), GUID_LOPART(setterGuid), rank);
}

void Guild::GiveXP(uint32 xp, Player* source)
{
    if (!sWorld->getBoolConfig(CONFIG_GUILD_LEVELING_ENABLED))
        return;

    /// @todo: Award reputation and count activity for player

    if (GetLevel() >= sWorld->getIntConfig(CONFIG_GUILD_MAX_LEVEL))
        xp = 0; // SMSG_GUILD_XP_GAIN is always sent, even for no gains

    if (GetLevel() < GUILD_EXPERIENCE_UNCAPPED_LEVEL)
        xp = std::min(xp, sWorld->getIntConfig(CONFIG_GUILD_DAILY_XP_CAP) - uint32(_todayExperience));

    WorldPacket data(SMSG_GUILD_XP_GAIN, 8);
    data << uint64(xp);
    source->GetSession()->SendPacket(&data);

    _experience += xp;
    _todayExperience += xp;

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
                if (entry->Level > oldLevel && entry->Level <= GetLevel())
                    perksToLearn.push_back(entry->SpellId);

        // Notify all online players that guild level changed and learn perks
        for (Members::const_iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
        {
            if (Player* player = itr->second->FindPlayer())
            {
                player->SetGuildLevel(GetLevel());
                for (size_t i = 0; i < perksToLearn.size(); ++i)
                    player->learnSpell(perksToLearn[i], true);
            }
        }

        AddGuildNews(GUILD_NEWS_LEVEL_UP, 0, 0, _level);
        UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_REACH_GUILD_LEVEL, GetLevel(), 0, 0, NULL, source);

        ++oldLevel;
    }
}

void Guild::SendGuildXP(WorldSession* session /* = NULL */) const
{
    //Member const* member = GetMember(session->GetGuidLow());

    WorldPacket data(SMSG_GUILD_XP, 40);
    data << uint64(/*member ? member->GetTotalActivity() :*/ 0);
    data << uint64(sGuildMgr->GetXPForGuildLevel(GetLevel()) - GetExperience());    // XP missing for next level
    data << uint64(GetTodayExperience());
    data << uint64(/*member ? member->GetWeeklyActivity() :*/ 0);
    data << uint64(GetExperience());
    session->SendPacket(&data);
}

void Guild::SendGuildReputationWeeklyCap(WorldSession* session, uint32 reputation) const
{
    uint32 cap = sWorld->getIntConfig(CONFIG_GUILD_WEEKLY_REP_CAP) - reputation;
    WorldPacket data(SMSG_GUILD_REPUTATION_WEEKLY_CAP, 4);
    data << uint32(cap);
    session->SendPacket(&data);
    TC_LOG_DEBUG(LOG_FILTER_GUILD, "SMSG_GUILD_REPUTATION_WEEKLY_CAP [%s]: Left: %u",
                   session->GetPlayerInfo().c_str(), cap);
}

void Guild::ResetTimes(bool weekly)
{
    _todayExperience = 0;
    for (Members::const_iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
    {
        itr->second->ResetValues(weekly);
        if (Player* player = itr->second->FindPlayer())
        {
            //SendGuildXP(player->GetSession());
            WorldPacket data(SMSG_GUILD_MEMBER_DAILY_RESET, 0);  // tells the client to request bank withdrawal limit
            player->GetSession()->SendPacket(&data);
        }
    }
}

void Guild::AddGuildNews(uint8 type, uint64 guid, uint32 flags, uint32 value)
{
    uint32 lowGuid = GUID_LOPART(guid);
    NewsLogEntry* news = new NewsLogEntry(m_id, m_newsLog->GetNextGUID(), GuildNews(type), lowGuid, flags, value);

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    m_newsLog->AddEvent(trans, news);
    CharacterDatabase.CommitTransaction(trans);

    WorldPacket data(SMSG_GUILD_NEWS_UPDATE, 7 + 32);
    data.WriteBits(1, 21); // size, we are only sending 1 news here
    ByteBuffer buffer;
    news->WritePacket(data, buffer);

    BroadcastPacket(&data);
}

bool Guild::HasAchieved(uint32 achievementId) const
{
    return m_achievementMgr.HasAchieved(achievementId);
}

void Guild::UpdateAchievementCriteria(AchievementCriteriaTypes type, uint64 miscValue1, uint64 miscValue2, uint64 miscValue3, Unit* unit, Player* player)
{
    m_achievementMgr.UpdateAchievementCriteria(type, miscValue1, miscValue2, miscValue3, unit, player);
}

void Guild::HandleNewsSetSticky(WorldSession* session, uint32 newsId, bool sticky)
{
    GuildLog* logs = m_newsLog->GetGuildLog();
    GuildLog::iterator itr = logs->begin();
    while (itr != logs->end() && (*itr)->GetGUID() != newsId)
        ++itr;

    if (itr == logs->end())
    {
        TC_LOG_DEBUG(LOG_FILTER_GUILD, "HandleNewsSetSticky: [%s] requested unknown newsId %u - Sticky: %u",
            session->GetPlayerInfo().c_str(), newsId, sticky);
        return;
    }

    NewsLogEntry* news = (NewsLogEntry*)(*itr);
    news->SetSticky(sticky);

    TC_LOG_DEBUG(LOG_FILTER_GUILD, "HandleNewsSetSticky: [%s] chenged newsId %u sticky to %u",
        session->GetPlayerInfo().c_str(), newsId, sticky);

    WorldPacket data(SMSG_GUILD_NEWS_UPDATE, 7 + 32);
    data.WriteBits(1, 21);
    ByteBuffer buffer;
    news->WritePacket(data, buffer);
    session->SendPacket(&data);
}
