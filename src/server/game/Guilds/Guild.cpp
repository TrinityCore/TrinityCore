/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
        case GE_BANK_TAB_AND_MONEY_UPDATED:
            return "Bank and money updated";
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

    TC_LOG_DEBUG("guild", "SMSG_GUILD_COMMAND_RESULT [%s]: Type: %u, code: %u, param: %s"
         , session->GetPlayerInfo().c_str(), type, errCode, param.c_str());
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
    data << uint8(m_log.size());
    for (GuildLog::const_iterator itr = m_log.begin(); itr != m_log.end(); ++itr)
        (*itr)->WritePacket(data);
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

void Guild::EventLogEntry::WritePacket(WorldPacket& data) const
{
    // Event type
    data << uint8(m_eventType);
    // Player 1
    data << ObjectGuid(HIGHGUID_PLAYER, m_playerGuid1);
    // Player 2 not for left/join guild events
    if (m_eventType != GUILD_EVENT_LOG_JOIN_GUILD && m_eventType != GUILD_EVENT_LOG_LEAVE_GUILD)
        data << ObjectGuid(HIGHGUID_PLAYER, m_playerGuid2);
    // New Rank - only for promote/demote guild events
    if (m_eventType == GUILD_EVENT_LOG_PROMOTE_PLAYER || m_eventType == GUILD_EVENT_LOG_DEMOTE_PLAYER)
        data << uint8(m_newRank);
    // Event timestamp
    data << uint32(::time(NULL) - m_timestamp);
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

void Guild::BankEventLogEntry::WritePacket(WorldPacket& data) const
{
    data << uint8(m_eventType);
    data << ObjectGuid(HIGHGUID_PLAYER, m_playerGuid);

    switch (m_eventType)
    {
        case GUILD_BANK_LOG_DEPOSIT_ITEM:
        case GUILD_BANK_LOG_WITHDRAW_ITEM:
            data << uint32(m_itemOrMoney);
            data << uint32(m_itemStackCount);
            break;
        case GUILD_BANK_LOG_MOVE_ITEM:
        case GUILD_BANK_LOG_MOVE_ITEM2:
            data << uint32(m_itemOrMoney);
            data << uint32(m_itemStackCount);
            data << uint8(m_destTabId);
            break;
        default:
            data << uint32(m_itemOrMoney);
    }

    data << uint32(time(NULL) - m_timestamp);
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
    stmt->setUInt32(4, m_bankMoneyPerDay);
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
            TC_LOG_ERROR("guild", "Guild %u has broken Tab %u for rank %u. Created default tab.", m_guildId, i, m_rankId);

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_BANK_RIGHT);
        stmt->setUInt32(0, m_guildId);
        stmt->setUInt8(1, i);
        stmt->setUInt8(2, m_rankId);
        stmt->setUInt8(3, rightsAndSlots.GetRights());
        stmt->setUInt32(4, rightsAndSlots.GetSlots());
        trans->Append(stmt);
    }
}

void Guild::RankInfo::WritePacket(WorldPacket& data) const
{
    data << uint32(m_rights);
    if (m_bankMoneyPerDay == GUILD_WITHDRAW_MONEY_UNLIMITED)
        data << uint32(GUILD_WITHDRAW_MONEY_UNLIMITED);
    else
        data << uint32(m_bankMoneyPerDay);
    for (uint8 i = 0; i < GUILD_BANK_MAX_TABS; ++i)
    {
        data << uint32(m_bankTabRightsAndSlots[i].GetRights());
        data << uint32(m_bankTabRightsAndSlots[i].GetSlots());
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

inline void Guild::BankTab::WritePacket(WorldPacket& data) const
{
    uint8 count = 0;

    size_t pos = data.wpos();
    data << uint8(0);

    for (uint8 slotId = 0; slotId < GUILD_BANK_MAX_SLOTS; ++slotId)
        if (WriteSlotPacket(data, slotId))
            ++count;

    data.put<uint8>(pos, count);
}

// Writes information about contents of specified slot into packet.
bool Guild::BankTab::WriteSlotPacket(WorldPacket& data, uint8 slotId, bool ignoreEmpty /* = true */) const
{
    Item* pItem = GetItem(slotId);
    uint32 itemEntry = pItem ? pItem->GetEntry() : 0;

    if (!itemEntry && ignoreEmpty)
        return false;

    data << uint8(slotId);
    data << uint32(itemEntry);
    if (itemEntry)
    {
        data << uint32(0);                                  // 3.3.0 (0x00018020, 0x00018000)


        if (uint32 random = pItem->GetItemRandomPropertyId())
        {
            data << uint32(random);                         // Random item property id
            data << uint32(pItem->GetItemSuffixFactor());   // SuffixFactor
        }
        else
            data << uint32(0);

        data << uint32(pItem->GetCount());                  // ITEM_FIELD_STACK_COUNT
        data << uint32(0);
        data << uint8(abs(pItem->GetSpellCharges()));       // Spell charges

        uint8 enchCount = 0;
        size_t enchCountPos = data.wpos();

        data << uint8(enchCount);                           // Number of enchantments
        for (uint32 i = PERM_ENCHANTMENT_SLOT; i < MAX_ENCHANTMENT_SLOT; ++i)
            if (uint32 enchId = pItem->GetEnchantmentId(EnchantmentSlot(i)))
            {
                data << uint8(i);
                data << uint32(enchId);
                ++enchCount;
            }
        data.put<uint8>(enchCountPos, enchCount);
    }
    return true;
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

        item->SetGuidValue(ITEM_FIELD_CONTAINED, ObjectGuid::Empty);
        item->SetGuidValue(ITEM_FIELD_OWNER, ObjectGuid::Empty);
        item->FSetState(ITEM_NEW);
        item->SaveToDB(trans);                                 // Not in inventory and can be saved standalone
    }
    return true;
}

void Guild::BankTab::SendText(Guild const* guild, WorldSession* session) const
{
    WorldPacket data(MSG_QUERY_GUILD_BANK_TEXT, 1 + m_text.size() + 1);
    data << uint8(m_tabId);
    data << m_text;

    if (session)
    {
        TC_LOG_DEBUG("guild", "MSG_QUERY_GUILD_BANK_TEXT [%s]: Tabid: %u, Text: %s"
            , session->GetPlayerInfo().c_str(), m_tabId, m_text.c_str());
        session->SendPacket(&data);
    }
    else
    {
        TC_LOG_DEBUG("guild", "MSG_QUERY_GUILD_BANK_TEXT [Broadcast]: Tabid: %u, Text: %s", m_tabId, m_text.c_str());
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
}

void Guild::Member::SetStats(std::string const& name, uint8 level, uint8 _class, uint32 zoneId, uint32 accountId)
{
    m_name      = name;
    m_level     = level;
    m_class     = _class;
    m_zoneId    = zoneId;
    m_accountId = accountId;
}

void Guild::Member::SetPublicNote(std::string const& publicNote)
{
    if (m_publicNote == publicNote)
        return;

    m_publicNote = publicNote;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_MEMBER_PNOTE);
    stmt->setString(0, publicNote);
    stmt->setUInt32(1, m_guid.GetCounter());
    CharacterDatabase.Execute(stmt);
}

void Guild::Member::SetOfficerNote(std::string const& officerNote)
{
    if (m_officerNote == officerNote)
        return;

    m_officerNote = officerNote;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_MEMBER_OFFNOTE);
    stmt->setString(0, officerNote);
    stmt->setUInt32(1, m_guid.GetCounter());
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
    stmt->setUInt32(1, m_guid.GetCounter());
    CharacterDatabase.Execute(stmt);
}

void Guild::Member::SaveToDB(SQLTransaction& trans) const
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_MEMBER);
    stmt->setUInt32(0, m_guildId);
    stmt->setUInt32(1, m_guid.GetCounter());
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

    SetStats(fields[12].GetString(),
             fields[13].GetUInt8(),                         // characters.level
             fields[14].GetUInt8(),                         // characters.class
             fields[15].GetUInt16(),                        // characters.zone
             fields[16].GetUInt32());                       // characters.account
    m_logoutTime = fields[17].GetUInt32();                  // characters.logout_time

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

void Guild::Member::WritePacket(WorldPacket& data, bool sendOfficerNote) const
{
    data << uint64(m_guid)
         << uint8(m_flags)
         << m_name
         << uint32(m_rankId)
         << uint8(m_level)
         << uint8(m_class)
         << uint8(0)
         << uint32(m_zoneId);

    if (!m_flags)
        data << float(float(::time(NULL) - m_logoutTime) / DAY);

    data << m_publicNote;

    if (sendOfficerNote)
        data << m_officerNote;
    else
        data << "";
}

// Decreases amount of money/slots left for today.
// If (tabId == GUILD_BANK_MAX_TABS) decrease money amount.
// Otherwise decrease remaining items amount for specified tab.
void Guild::Member::UpdateBankWithdrawValue(SQLTransaction& trans, uint8 tabId, uint32 amount)
{
    m_bankWithdraw[tabId] += amount;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_MEMBER_WITHDRAW);
    stmt->setUInt32(0, m_guid.GetCounter());
    for (uint8 i = 0; i <= GUILD_BANK_MAX_TABS;)
    {
        uint32 withdraw = m_bankWithdraw[i++];
        stmt->setUInt32(i, withdraw);
    }

    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void Guild::Member::ResetValues()
{
    for (uint8 tabId = 0; tabId <= GUILD_BANK_MAX_TABS; ++tabId)
        m_bankWithdraw[tabId] = 0;
}

// Get amount of money/slots left for today.
// If (tabId == GUILD_BANK_MAX_TABS) return money amount.
// Otherwise return remaining items amount for specified tab.
int32 Guild::Member::GetBankWithdrawValue(uint8 tabId) const
{
    // Guild master has unlimited amount.
    if (IsRank(GR_GUILDMASTER))
        return static_cast<int32>(tabId == GUILD_BANK_MAX_TABS ? GUILD_WITHDRAW_MONEY_UNLIMITED : GUILD_WITHDRAW_SLOT_UNLIMITED);

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
            m_pPlayer->SendEquipError(EQUIP_ERR_CAN_ONLY_DO_WITH_EMPTY_BAGS, m_pItem);
            m_pItem = NULL;
        }
        // Bound items cannot be put into bank.
        else if (!m_pItem->CanBeTraded())
        {
            m_pPlayer->SendEquipError(EQUIP_ERR_ITEMS_CANT_BE_SWAPPED, m_pItem);
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

        TC_LOG_DEBUG("guild", "GUILD STORAGE: StoreItem tab = %u, slot = %u, item = %u, count = %u",
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
    if (!pFrom->IsBank() && m_pPlayer->GetSession()->HasPermission(rbac::RBAC_PERM_LOG_GM_TRADE)) /// @todo Move this to scripts
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
    TC_LOG_DEBUG("guild", "GUILD STORAGE: CanStore() tab = %u, slot = %u, item = %u, count = %u",
        m_container, m_slotId, pItem->GetEntry(), pItem->GetCount());

    uint32 count = pItem->GetCount();
    // Soulbound items cannot be moved
    if (pItem->IsSoulBound())
        return EQUIP_ERR_CANT_DROP_SOULBOUND;

    // Make sure destination bank tab exists
    if (m_container >= m_pGuild->_GetPurchasedTabsSize())
        return EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG;

    // Slot explicitely specified. Check it.
    if (m_slotId != NULL_SLOT)
    {
        Item* pItemDest = m_pGuild->_GetItem(m_container, m_slotId);
        // Ignore swapped item (this slot will be empty after move)
        if ((pItemDest == pItem) || swap)
            pItemDest = NULL;

        if (!_ReserveSpace(m_slotId, pItem, pItemDest, count))
            return EQUIP_ERR_ITEM_CANT_STACK;

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
    m_eventLog(NULL)
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
    _CreateLogHolders();

    TC_LOG_DEBUG("guild", "GUILD: creating guild [%s] for leader %s (%u)",
        name.c_str(), pLeader->GetName().c_str(), m_leaderGuid.GetCounter());

    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_MEMBERS);
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

    CharacterDatabase.CommitTransaction(trans);
    _CreateDefaultGuildRanks(pLeaderSession->GetSessionDbLocaleIndex()); // Create default ranks
    bool ret = AddMember(m_leaderGuid, GR_GUILDMASTER);                  // Add guildmaster

    if (ret)
        sScriptMgr->OnGuildCreate(this, pLeader, name);

    return ret;
}

// Disbands guild and deletes all related data from database
void Guild::Disband()
{
    // Call scripts before guild data removed from database
    sScriptMgr->OnGuildDisband(this);

    _BroadcastEvent(GE_DISBANDED, ObjectGuid::Empty);
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
    sGuildMgr->RemoveGuild(m_id);
}

void Guild::UpdateMemberData(Player* player, uint8 dataid, uint32 value)
{
    if (Member* member = GetMember(player->GetGUID()))
    {
        switch (dataid)
        {
            case GUILD_MEMBER_DATA_ZONEID:
                member->SetZoneID(value);
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
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_NAME);
    stmt->setString(0, m_name);
    stmt->setUInt32(1, GetId());
    CharacterDatabase.Execute(stmt);
    return true;
}

void Guild::HandleRoster(WorldSession* session)
{
    // Guess size
    WorldPacket data(SMSG_GUILD_ROSTER, (4 + m_motd.length() + 1 + m_info.length() + 1 + 4 + _GetRanksSize() * (4 + 4 + GUILD_BANK_MAX_TABS * (4 + 4)) + m_members.size() * 50));
    data << uint32(m_members.size());
    data << m_motd;
    data << m_info;

    data << uint32(_GetRanksSize());
    for (Ranks::const_iterator ritr = m_ranks.begin(); ritr != m_ranks.end(); ++ritr)
        ritr->WritePacket(data);

    for (Members::const_iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
        itr->second->WritePacket(data, _HasRankRight(session->GetPlayer(), GR_RIGHT_VIEWOFFNOTE));

    TC_LOG_DEBUG("guild", "SMSG_GUILD_ROSTER [%s]", session->GetPlayerInfo().c_str());
    session->SendPacket(&data);
}

void Guild::HandleQuery(WorldSession* session)
{
    WorldPacket data(SMSG_GUILD_QUERY_RESPONSE, 8 * 32 + 200);      // Guess size
    data << uint32(m_id);
    data << m_name;

    // Rank name
    for (uint8 i = 0; i < GUILD_RANKS_MAX_COUNT; ++i)               // Always show 10 ranks
    {
        if (i < _GetRanksSize())
            data << m_ranks[i].GetName();
        else
            data << uint8(0);                                       // Empty string
    }

    m_emblemInfo.WritePacket(data);
    data << uint32(_GetRanksSize());                                // Number of ranks used

    session->SendPacket(&data);
    TC_LOG_DEBUG("guild", "SMSG_GUILD_QUERY_RESPONSE [%s]", session->GetPlayerInfo().c_str());
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
    else if (!player->HasEnoughMoney(EMBLEM_PRICE))
        SendSaveEmblemResult(session, ERR_GUILDEMBLEM_NOTENOUGHMONEY); // "You can't afford to do that."
    else
    {
        player->ModifyMoney(-int32(EMBLEM_PRICE));

        m_emblemInfo = emblemInfo;
        m_emblemInfo.SaveToDB(m_id);

        SendSaveEmblemResult(session, ERR_GUILDEMBLEM_SUCCESS); // "Guild Emblem saved."

        HandleQuery(session);
    }
}

void Guild::HandleSetLeader(WorldSession* session, std::string const& name)
{
    Player* player = session->GetPlayer();
    // Only leader can assign new leader
    if (!_IsLeader(player))
        SendCommandResult(session, GUILD_COMMAND_CHANGE_LEADER, ERR_GUILD_PERMISSIONS);
    // Old leader must be a member of guild
    else if (Member* pOldLeader = GetMember(player->GetGUID()))
    {
        // New leader must be a member of guild
        if (Member* pNewLeader = GetMember(name))
        {
            _SetLeaderGUID(pNewLeader);
            pOldLeader->ChangeRank(GR_OFFICER);
            _BroadcastEvent(GE_LEADER_CHANGED, ObjectGuid::Empty, player->GetName().c_str(), name.c_str());
        }
    }
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

    char aux[2];
    sprintf(aux, "%u", tabId);

    tab->SetInfo(name, icon);
    _BroadcastEvent(GE_BANK_TAB_UPDATED, ObjectGuid::Empty, aux, name.c_str(), icon.c_str());
}

void Guild::HandleSetMemberNote(WorldSession* session, std::string const& name, std::string const& note, bool isPublic)
{
    // Player must have rights to set public/officer note
    if (!_HasRankRight(session->GetPlayer(), isPublic ? GR_RIGHT_EPNOTE : GR_RIGHT_EOFFNOTE))
        SendCommandResult(session, GUILD_COMMAND_PUBLIC_NOTE, ERR_GUILD_PERMISSIONS);
    else if (Member* member = GetMember(name))
    {
        if (isPublic)
            member->SetPublicNote(note);
        else
            member->SetOfficerNote(note);

        HandleRoster(session);
    }
}

void Guild::HandleSetRankInfo(WorldSession* session, uint8 rankId, std::string const& name, uint32 rights, uint32 moneyPerDay, const GuildBankRightsAndSlotsVec& rightsAndSlots)
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

        for (GuildBankRightsAndSlotsVec::const_iterator itr = rightsAndSlots.begin(); itr != rightsAndSlots.end(); ++itr)
            _SetRankBankTabRightsAndSlots(rankId, *itr);

        char aux[2];
        sprintf(aux, "%u", rankId);
        _BroadcastEvent(GE_RANK_UPDATED, ObjectGuid::Empty, aux, name.c_str());
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

    uint32 tabCost = _GetGuildBankTabPrice(tabId) * GOLD;
    if (!tabCost)
        return;

    if (!player->HasEnoughMoney(tabCost))                   // Should not happen, this is checked by client
        return;

    player->ModifyMoney(-int32(tabCost));

    _CreateNewBankTab();
    _BroadcastEvent(GE_BANK_TAB_PURCHASED, ObjectGuid::Empty);
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
    if (pInvitee->GetGuildId())
    {
        SendCommandResult(session, GUILD_COMMAND_INVITE, ERR_ALREADY_IN_GUILD_S, name);
        return;
    }
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
    _LogEvent(GUILD_EVENT_LOG_INVITE_PLAYER, player->GetGUIDLow(), pInvitee->GetGUIDLow());

    WorldPacket data(SMSG_GUILD_INVITE, 8 + 10);              // Guess size
    data << player->GetName();
    data << m_name;
    pInvitee->GetSession()->SendPacket(&data);
    TC_LOG_DEBUG("guild", "SMSG_GUILD_INVITE [%s]", pInvitee->GetName().c_str());
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

void Guild::HandleRemoveMember(WorldSession* session, std::string const& name)
{
    Player* player = session->GetPlayer();
    // Player must have rights to remove members
    if (!_HasRankRight(player, GR_RIGHT_REMOVE))
        SendCommandResult(session, GUILD_COMMAND_REMOVE, ERR_GUILD_PERMISSIONS);
    else if (Member* member = GetMember(name))
    {
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
                ObjectGuid guid = member->GetGUID();
                // After call to DeleteMember pointer to member becomes invalid
                DeleteMember(guid, false, true);
                _LogEvent(GUILD_EVENT_LOG_UNINVITE_PLAYER, player->GetGUIDLow(), guid.GetCounter());
                _BroadcastEvent(GE_REMOVED, ObjectGuid::Empty, name.c_str(), player->GetName().c_str());
            }
        }
    }
}

void Guild::HandleUpdateMemberRank(WorldSession* session, std::string const& name, bool demote)
{
    Player* player = session->GetPlayer();
    GuildCommandType type = demote ? GUILD_COMMAND_DEMOTE : GUILD_COMMAND_PROMOTE;
    // Player must have rights to promote
    if (!_HasRankRight(player, demote ? GR_RIGHT_DEMOTE : GR_RIGHT_PROMOTE))
        SendCommandResult(session, type, ERR_GUILD_PERMISSIONS);
    // Promoted player must be a member of guild
    else if (Member* member = GetMember(name))
    {
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
        _LogEvent(demote ? GUILD_EVENT_LOG_DEMOTE_PLAYER : GUILD_EVENT_LOG_PROMOTE_PLAYER, player->GetGUIDLow(), member->GetGUID().GetCounter(), newRankId);
        _BroadcastEvent(demote ? GE_DEMOTION : GE_PROMOTION, ObjectGuid::Empty, player->GetName().c_str(), name.c_str(), _GetRankName(newRankId).c_str());
    }
}

void Guild::HandleAddNewRank(WorldSession* session, std::string const& name)
{
    uint8 size = _GetRanksSize();
    if (size >= GUILD_RANKS_MAX_COUNT)
        return;

    // Only leader can add new rank
    if (_IsLeader(session->GetPlayer()))
        if (_CreateRank(name, GR_RIGHT_GCHATLISTEN | GR_RIGHT_GCHATSPEAK))
        {
            char aux[2];
            sprintf(aux, "%u", size);
            _BroadcastEvent(GE_RANK_UPDATED, ObjectGuid::Empty, aux, name.c_str());
        }
}

void Guild::HandleRemoveLowestRank(WorldSession* session)
{
    HandleRemoveRank(session, _GetLowestRankId());
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
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_LOWEST_RANK);
    stmt->setUInt32(0, m_id);
    stmt->setUInt8(1, rankId);
    CharacterDatabase.Execute(stmt);

    m_ranks.pop_back();

    _BroadcastEvent(GE_RANK_DELETED, ObjectGuid::Empty, std::to_string(rankId).c_str());
}

void Guild::HandleMemberDepositMoney(WorldSession* session, uint32 amount)
{
    Player* player = session->GetPlayer();

    // Call script after validation and before money transfer.
    sScriptMgr->OnGuildMemberDepositMoney(this, player, amount);

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    _ModifyBankMoney(trans, amount, true);

    player->ModifyMoney(-int32(amount));
    player->SaveGoldToDB(trans);
    _LogBankEvent(trans, GUILD_BANK_LOG_DEPOSIT_MONEY, uint8(0), player->GetGUIDLow(), amount);

    CharacterDatabase.CommitTransaction(trans);

    std::string aux = ByteArrayToHexStr(reinterpret_cast<uint8*>(&m_bankMoney), 8, true);
    _BroadcastEvent(GE_BANK_MONEY_SET, ObjectGuid::Empty, aux.c_str());

    if (player->GetSession()->HasPermission(rbac::RBAC_PERM_LOG_GM_TRADE))
    {
        sLog->outCommand(player->GetSession()->GetAccountId(),
            "GM %s (Account: %u) deposit money (Amount: %u) to guild bank (Guild ID %u)",
            player->GetName().c_str(), player->GetSession()->GetAccountId(), amount, m_id);
    }
}

bool Guild::HandleMemberWithdrawMoney(WorldSession* session, uint32 amount, bool repair)
{
    //clamp amount to MAX_MONEY_AMOUNT, Players can't hold more than that anyway
    amount = std::min(amount, MAX_MONEY_AMOUNT);

    if (m_bankMoney < amount)                               // Not enough money in bank
        return false;

    Player* player = session->GetPlayer();

    Member* member = GetMember(player->GetGUID());
    if (!member)
        return false;

   if (uint32(_GetMemberRemainingMoney(member)) < amount)   // Check if we have enough slot/money today
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

    std::string aux = ByteArrayToHexStr(reinterpret_cast<uint8*>(&m_bankMoney), 8, true);
    _BroadcastEvent(GE_BANK_MONEY_SET, ObjectGuid::Empty, aux.c_str());
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

// Send data to client
void Guild::SendInfo(WorldSession* session) const
{
    WorldPacket data(SMSG_GUILD_INFO, m_name.size() + 4 + 4 + 4);
    data << m_name;
    data.AppendPackedTime(m_createdDate);           // 3.x (prev. year + month + day)
    data << uint32(m_members.size());               // Number of members
    data << m_accountsNumber;                       // Number of accounts

    session->SendPacket(&data);
    TC_LOG_DEBUG("guild", "SMSG_GUILD_INFO [%s]", session->GetPlayerInfo().c_str());
}

void Guild::SendEventLog(WorldSession* session) const
{
    WorldPacket data(MSG_GUILD_EVENT_LOG_QUERY, 1 + m_eventLog->GetSize() * (1 + 8 + 4));
    m_eventLog->WritePacket(data);
    session->SendPacket(&data);
    TC_LOG_DEBUG("guild", "MSG_GUILD_EVENT_LOG_QUERY [%s]", session->GetPlayerInfo().c_str());
}

void Guild::SendBankLog(WorldSession* session, uint8 tabId) const
{
    // GUILD_BANK_MAX_TABS send by client for money log
    if (tabId < _GetPurchasedTabsSize() || tabId == GUILD_BANK_MAX_TABS)
    {
        const LogHolder* pLog = m_bankEventLog[tabId];
        WorldPacket data(MSG_GUILD_BANK_LOG_QUERY, pLog->GetSize() * (4 * 4 + 1) + 1 + 1);
        data << uint8(tabId);
        pLog->WritePacket(data);
        session->SendPacket(&data);
        TC_LOG_DEBUG("guild", "MSG_GUILD_BANK_LOG_QUERY [%s]", session->GetPlayerInfo().c_str());
    }
}

void Guild::SendBankTabData(WorldSession* session, uint8 tabId) const
{
    if (tabId < _GetPurchasedTabsSize())
        _SendBankContent(session, tabId);
}

void Guild::SendBankTabsInfo(WorldSession* session, bool sendAllSlots /*= false*/) const
{
    _SendBankList(session, 0, sendAllSlots);
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

    WorldPacket data(MSG_GUILD_PERMISSIONS, 4 * 15 + 1);
    data << uint32(rankId);
    data << uint32(_GetRankRights(rankId));
    data << uint32(_GetMemberRemainingMoney(member));
    data << uint8(_GetPurchasedTabsSize());
    for (uint8 tabId = 0; tabId < GUILD_BANK_MAX_TABS; ++tabId)
    {
        data << uint32(_GetRankBankTabRights(rankId, tabId));
        data << uint32(_GetMemberRemainingSlots(member, tabId));
    }

    session->SendPacket(&data);
    TC_LOG_DEBUG("guild", "MSG_GUILD_PERMISSIONS [%s] Rank: %u", session->GetPlayerInfo().c_str(), rankId);
}

void Guild::SendMoneyInfo(WorldSession* session) const
{
    Member const* member = GetMember(session->GetPlayer()->GetGUID());
    if (!member)
        return;

    int32 amount = _GetMemberRemainingMoney(member);
    WorldPacket data(MSG_GUILD_BANK_MONEY_WITHDRAWN, 4);
    data << int32(amount);
    session->SendPacket(&data);
    TC_LOG_DEBUG("guild", "MSG_GUILD_BANK_MONEY_WITHDRAWN [%s] Money: %u", session->GetPlayerInfo().c_str(), amount);
}

void Guild::SendLoginInfo(WorldSession* session)
{
    WorldPacket data(SMSG_GUILD_EVENT, 1 + 1 + m_motd.size() + 1);
    data << uint8(GE_MOTD);
    data << uint8(1);
    data << m_motd;
    session->SendPacket(&data);

    TC_LOG_DEBUG("guild", "SMSG_GUILD_EVENT [%s] MOTD", session->GetPlayerInfo().c_str());

    SendBankTabsInfo(session);

    Player* player = session->GetPlayer();

    HandleRoster(session);
    _BroadcastEvent(GE_SIGNED_ON, player->GetGUID(), player->GetName().c_str());

    if (Member* member = GetMember(player->GetGUID()))
    {
        member->SetStats(player);
        member->AddFlag(GUILDMEMBER_STATUS_ONLINE);
    }
}

// Loading methods
bool Guild::LoadFromDB(Field* fields)
{
    m_id            = fields[0].GetUInt32();
    m_name          = fields[1].GetString();
    m_leaderGuid    = ObjectGuid(HIGHGUID_PLAYER, fields[2].GetUInt32());
    m_emblemInfo.LoadFromDB(fields);
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
    uint32 lowguid = fields[1].GetUInt32();
    Member *member = new Member(m_id, ObjectGuid(HIGHGUID_PLAYER, lowguid), fields[2].GetUInt8());
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
                fields[5].GetUInt32(),                  // item or money
                fields[6].GetUInt16(),                  // itam stack count
                fields[7].GetUInt8()));                 // dest tab id
        }
    }
    return true;
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
    uint8 tabId = fields[12].GetUInt8();
    if (tabId >= _GetPurchasedTabsSize())
    {
        TC_LOG_ERROR("guild", "Invalid tab for item (GUID: %u, id: #%u) in guild bank, skipped.",
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
    // Min ranks count is 5 and max is 10.
    bool broken_ranks = false;
    uint8 ranks = _GetRanksSize();
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
        ChatHandler::BuildChatPacket(data, officerOnly ? CHAT_MSG_OFFICER : CHAT_MSG_GUILD, Language(language), session->GetPlayer(), NULL, msg);
        for (Members::const_iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
            if (Player* player = itr->second->FindPlayer())
                if (player->GetSession() && _HasRankRight(player, officerOnly ? GR_RIGHT_OFFCHATLISTEN : GR_RIGHT_GCHATLISTEN) &&
                    !player->GetSocial()->HasIgnore(session->GetPlayer()->GetGUIDLow()))
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
            data.appendPackGUID(member->GetGUID().GetRawValue());
            data << uint8(0); // unk
            ++count;
        }
    }

    data.put<uint32>(0, count);

    session->SendPacket(&data);
}

// Members handling
bool Guild::AddMember(ObjectGuid guid, uint8 rankId)
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

    uint32 lowguid = guid.GetCounter();

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
        member->SetStats(player);
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
                fields[4].GetUInt32());

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

    // Call scripts if member was succesfully added (and stored to database)
    sScriptMgr->OnGuildAddMember(this, player, rankId);

    return true;
}

void Guild::DeleteMember(ObjectGuid guid, bool isDisbanding, bool isKicked, bool canDeleteGuild)
{
    uint32 lowguid = guid.GetCounter();
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
            _BroadcastEvent(GE_LEADER_CHANGED, ObjectGuid::Empty, oldLeader->GetName().c_str(), newLeader->GetName().c_str());
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
    }

    _DeleteMemberFromDB(lowguid);
    if (!isDisbanding)
        _UpdateAccountsNumber();
}

bool Guild::ChangeMemberRank(ObjectGuid guid, uint8 newRank)
{
    if (newRank <= _GetLowestRankId())                    // Validate rank (allow only existing ranks)
        if (Member* member = GetMember(guid))
        {
            member->ChangeRank(newRank);
            return true;
        }
    return false;
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
    stmt->setUInt32(0, m_leaderGuid.GetCounter());
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
            return static_cast<int32>(GUILD_WITHDRAW_SLOT_UNLIMITED);
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
            return static_cast<int32>(GUILD_WITHDRAW_MONEY_UNLIMITED);

        if ((_GetRankRights(rankId) & (GR_RIGHT_WITHDRAW_REPAIR | GR_RIGHT_WITHDRAW_GOLD)) != 0)
        {
            int32 remaining = _GetRankBankMoneyPerDay(rankId) - member->GetBankWithdrawValue(GUILD_BANK_MAX_TABS);
            if (remaining > 0)
                return remaining;
        }
    }
    return 0;
}

inline void Guild::_UpdateMemberWithdrawSlots(SQLTransaction& trans, ObjectGuid guid, uint8 tabId)
{
    if (Member* member = GetMember(guid))
    {
        uint8 rankId = member->GetRankId();
        if (rankId != GR_GUILDMASTER
            && member->GetBankWithdrawValue(tabId) < _GetRankBankTabSlotsPerDay(rankId, tabId))
            member->UpdateBankWithdrawValue(trans, tabId, 1);
    }
}

inline bool Guild::_MemberHasTabRights(ObjectGuid guid, uint8 tabId, uint32 rights) const
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

void Guild::_SendBankContent(WorldSession* session, uint8 tabId) const
{
    ObjectGuid guid = session->GetPlayer()->GetGUID();
    if (!_MemberHasTabRights(guid, tabId, GUILD_BANK_RIGHT_VIEW_TAB))
        return;

    _SendBankList(session, tabId, true);
}

void Guild::_SendBankMoneyUpdate(WorldSession* session) const
{
    _SendBankList(session);
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
    _SendBankList(NULL, tabId, false, &slots);
}

void Guild::_BroadcastEvent(GuildEvents guildEvent, ObjectGuid guid, const char* param1, const char* param2, const char* param3) const
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

    if (sLog->ShouldLog("guild", LOG_LEVEL_DEBUG))
        TC_LOG_DEBUG("guild", "SMSG_GUILD_EVENT [Broadcast] Event: %s (%u)", _GetGuildEventString(guildEvent).c_str(), guildEvent);
}

void Guild::_SendBankList(WorldSession* session /* = NULL*/, uint8 tabId /*= 0*/, bool sendAllSlots /*= false*/, SlotIds *slots /*= NULL*/) const
{
    WorldPacket data(SMSG_GUILD_BANK_LIST, 500);
    data << uint64(m_bankMoney);
    data << uint8(tabId);
    size_t rempos = data.wpos();
    data << uint32(0);
    data << uint8(sendAllSlots);

    if (sendAllSlots && !tabId)
    {
        data << uint8(_GetPurchasedTabsSize());                  // Number of tabs
        for (uint8 i = 0; i < _GetPurchasedTabsSize(); ++i)
            m_bankTabs[i]->WriteInfoPacket(data);
    }

    BankTab const* tab = GetBankTab(tabId);
    if (!tab)
        data << uint8(0);
    else if (sendAllSlots)
        tab->WritePacket(data);
    else if (slots && !slots->empty())
    {
        data << uint8(slots->size());
        for (SlotIds::const_iterator itr = slots->begin(); itr != slots->end(); ++itr)
            tab->WriteSlotPacket(data, *itr, false);
    }
    else
        data << uint8(0);

    if (session)
    {
        int32 numSlots = 0;
        if (Member const* member = GetMember(session->GetPlayer()->GetGUID()))
            numSlots = _GetMemberRemainingSlots(member, tabId);
        data.put<uint32>(rempos, numSlots);
        session->SendPacket(&data);
        TC_LOG_DEBUG("guild", "SMSG_GUILD_BANK_LIST [%s]: TabId: %u, FullSlots: %u, slots: %d",
                       session->GetPlayerInfo().c_str(), tabId, sendAllSlots, numSlots);
    }
    else /// @todo - Probably this is just sent to session + those that have sent CMSG_GUILD_BANKER_ACTIVATE
    {
        for (Members::const_iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
        {
            if (!_MemberHasTabRights(itr->second->GetGUID(), tabId, GUILD_BANK_RIGHT_VIEW_TAB))
                continue;
            Player* player = itr->second->FindPlayer();
            if (!player)
                continue;

            uint32 numSlots = _GetMemberRemainingSlots(itr->second, tabId);
            data.put<uint32>(rempos, numSlots);
            player->GetSession()->SendPacket(&data);
            TC_LOG_DEBUG("guild", "SMSG_GUILD_BANK_LIST [%s]: TabId: %u, FullSlots: %u, slots: %u"
                , player->GetName().c_str(), tabId, sendAllSlots, numSlots);
        }
    }
}

void Guild::ResetTimes()
{
    for (Members::const_iterator itr = m_members.begin(); itr != m_members.end(); ++itr)
        itr->second->ResetValues();

    _BroadcastEvent(GE_BANK_TAB_AND_MONEY_UPDATED, ObjectGuid::Empty);
}
