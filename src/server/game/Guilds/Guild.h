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

#ifndef TRINITYCORE_GUILD_H
#define TRINITYCORE_GUILD_H

#include "Common.h"
#include "DatabaseEnvFwd.h"
#include "DBCEnums.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "RaceMask.h"
#include "SharedDefines.h"
#include "UniqueTrackablePtr.h"
#include <set>
#include <unordered_map>

class GuildAchievementMgr;
class Item;
class Player;
class WorldObject;
class WorldPacket;
class WorldSession;
struct ItemPosCount;
enum InventoryResult : uint8;

namespace WorldPackets
{
    namespace Guild
    {
        class GuildBankLogQueryResults;
        class GuildEventLogQueryResults;
        class GuildNews;
        class SaveGuildEmblem;
    }
}

enum GuildMisc
{
    GUILD_BANK_MAX_TABS                 = 8,                    // send by client for money log also
    GUILD_BANK_MAX_SLOTS                = 98,
    GUILD_BANK_MONEY_LOGS_TAB           = 100,                  // used for money log in DB
    GUILD_MASTER_DETHRONE_INACTIVE_DAYS = 90,
    GUILD_RANKS_MIN_COUNT               = 2,
    GUILD_RANKS_MAX_COUNT               = 10,
    GUILD_RANK_NONE                     = 0xFF,
    GUILD_WITHDRAW_MONEY_UNLIMITED      = 0xFFFFFFFF,
    GUILD_WITHDRAW_SLOT_UNLIMITED       = 0xFFFFFFFF,
    GUILD_EVENT_LOG_GUID_UNDEFINED      = 0xFFFFFFFF,
    TAB_UNDEFINED                       = 0xFF,
    GUILD_OLD_MAX_LEVEL                 = 25
};

constexpr uint64 GUILD_BANK_MONEY_LIMIT = UI64LIT(100000000000);

enum GuildMemberData
{
    GUILD_MEMBER_DATA_ZONEID,
    GUILD_MEMBER_DATA_ACHIEVEMENT_POINTS,
    GUILD_MEMBER_DATA_LEVEL,
};

// Base Club/Community roles. Do not change.
enum class ClubRoleIdentifier : uint32
{
    Owner     = 1,
    Leader    = 2,
    Moderator = 3,
    Member    = 4
};

// Base Club/Community chat stream types. Do not change.
enum class ClubStreamType : uint32
{
    General = 0,
    Guild   = 1,
    Officer = 2,
    Other   = 3
};

enum class GuildRankId : uint8
{
    GuildMaster = 0
};

enum class GuildRankOrder : uint8 { };

enum GuildRankRights
{
    GR_RIGHT_NONE                       = 0x00000000,
    GR_RIGHT_GCHATLISTEN                = 0x00000001,
    GR_RIGHT_GCHATSPEAK                 = 0x00000002,
    GR_RIGHT_OFFCHATLISTEN              = 0x00000004,
    GR_RIGHT_OFFCHATSPEAK               = 0x00000008,
    GR_RIGHT_INVITE                     = 0x00000010,
    GR_RIGHT_REMOVE                     = 0x00000020,
    GR_RIGHT_ROSTER                     = 0x00000040,
    GR_RIGHT_PROMOTE                    = 0x00000080,
    GR_RIGHT_DEMOTE                     = 0x00000100,
    GR_RIGHT_UNK_200                    = 0x00000200,
    GR_RIGHT_UNK_400                    = 0x00000400,
    GR_RIGHT_UNK_800                    = 0x00000800,
    GR_RIGHT_SETMOTD                    = 0x00001000,
    GR_RIGHT_EDIT_PUBLIC_NOTE           = 0x00002000,
    GR_RIGHT_VIEWOFFNOTE                = 0x00004000,
    GR_RIGHT_EOFFNOTE                   = 0x00008000,
    GR_RIGHT_MODIFY_GUILD_INFO          = 0x00010000,
    GR_RIGHT_WITHDRAW_GOLD_LOCK         = 0x00020000,                   // remove money withdraw capacity
    GR_RIGHT_WITHDRAW_REPAIR            = 0x00040000,                   // withdraw for repair
    GR_RIGHT_WITHDRAW_GOLD              = 0x00080000,                   // withdraw gold
    GR_RIGHT_CREATE_GUILD_EVENT         = 0x00100000,                   // wotlk
    GR_RIGHT_ALL                        = 0x00DDFFBF
};

enum GuildCommandType
{
    GUILD_COMMAND_CREATE_GUILD          = 0,
    GUILD_COMMAND_INVITE_PLAYER         = 1,
    GUILD_COMMAND_LEAVE_GUILD           = 3,
    GUILD_COMMAND_GET_ROSTER            = 5,
    GUILD_COMMAND_PROMOTE_PLAYER        = 6,
    GUILD_COMMAND_DEMOTE_PLAYER         = 7,
    GUILD_COMMAND_REMOVE_PLAYER         = 8,
    GUILD_COMMAND_CHANGE_LEADER         = 10,
    GUILD_COMMAND_EDIT_MOTD             = 11,
    GUILD_COMMAND_GUILD_CHAT            = 13,
    GUILD_COMMAND_FOUNDER               = 14,
    GUILD_COMMAND_CHANGE_RANK           = 16,
    GUILD_COMMAND_EDIT_PUBLIC_NOTE      = 19,
    GUILD_COMMAND_VIEW_TAB              = 21,
    GUILD_COMMAND_MOVE_ITEM             = 22,
    GUILD_COMMAND_REPAIR                = 25,
};

enum GuildCommandError
{
    ERR_GUILD_COMMAND_SUCCESS           = 0,
    ERR_GUILD_INTERNAL                  = 1,
    ERR_ALREADY_IN_GUILD                = 2,
    ERR_ALREADY_IN_GUILD_S              = 3,
    ERR_INVITED_TO_GUILD                = 4,
    ERR_ALREADY_INVITED_TO_GUILD_S      = 5,
    ERR_GUILD_NAME_INVALID              = 6,
    ERR_GUILD_NAME_EXISTS_S             = 7,
    ERR_GUILD_LEADER_LEAVE              = 8,
    ERR_GUILD_PERMISSIONS               = 8,
    ERR_GUILD_PLAYER_NOT_IN_GUILD       = 9,
    ERR_GUILD_PLAYER_NOT_IN_GUILD_S     = 10,
    ERR_GUILD_PLAYER_NOT_FOUND_S        = 11,
    ERR_GUILD_NOT_ALLIED                = 12,
    ERR_GUILD_RANK_TOO_HIGH_S           = 13,
    ERR_GUILD_RANK_TOO_LOW_S            = 14,
    ERR_GUILD_RANKS_LOCKED              = 17,
    ERR_GUILD_RANK_IN_USE               = 18,
    ERR_GUILD_IGNORING_YOU_S            = 19,
    ERR_GUILD_UNK1                      = 20, // Forces roster update
    ERR_GUILD_WITHDRAW_LIMIT            = 25,
    ERR_GUILD_NOT_ENOUGH_MONEY          = 26,
    ERR_GUILD_BANK_FULL                 = 28,
    ERR_GUILD_ITEM_NOT_FOUND            = 29,
    ERR_GUILD_TOO_MUCH_MONEY            = 31,
    ERR_GUILD_BANK_WRONG_TAB            = 32,
    ERR_RANK_REQUIRES_AUTHENTICATOR     = 34,
    ERR_GUILD_BANK_VOUCHER_FAILED       = 35,
    ERR_GUILD_TRIAL_ACCOUNT             = 36,
    ERR_GUILD_UNDELETABLE_DUE_TO_LEVEL  = 37,
    ERR_GUILD_MOVE_STARTING             = 38,
    ERR_GUILD_REP_TOO_LOW               = 39
};

enum GuildBankRights
{
    GUILD_BANK_RIGHT_VIEW_TAB           = 0x01,
    GUILD_BANK_RIGHT_PUT_ITEM           = 0x02,
    GUILD_BANK_RIGHT_UPDATE_TEXT        = 0x04,

    GUILD_BANK_RIGHT_DEPOSIT_ITEM       = GUILD_BANK_RIGHT_VIEW_TAB | GUILD_BANK_RIGHT_PUT_ITEM,
    GUILD_BANK_RIGHT_FULL               = -1
};

enum GuildBankEventLogTypes
{
    GUILD_BANK_LOG_DEPOSIT_ITEM         = 1,
    GUILD_BANK_LOG_WITHDRAW_ITEM        = 2,
    GUILD_BANK_LOG_MOVE_ITEM            = 3,
    GUILD_BANK_LOG_DEPOSIT_MONEY        = 4,
    GUILD_BANK_LOG_WITHDRAW_MONEY       = 5,
    GUILD_BANK_LOG_REPAIR_MONEY         = 6,
    GUILD_BANK_LOG_MOVE_ITEM2           = 7,
    GUILD_BANK_LOG_UNK1                 = 8,
    GUILD_BANK_LOG_BUY_SLOT             = 9,
    GUILD_BANK_LOG_CASH_FLOW_DEPOSIT    = 10
};

enum GuildEventLogTypes
{
    GUILD_EVENT_LOG_INVITE_PLAYER       = 1,
    GUILD_EVENT_LOG_JOIN_GUILD          = 2,
    GUILD_EVENT_LOG_PROMOTE_PLAYER      = 3,
    GUILD_EVENT_LOG_DEMOTE_PLAYER       = 4,
    GUILD_EVENT_LOG_UNINVITE_PLAYER     = 5,
    GUILD_EVENT_LOG_LEAVE_GUILD         = 6
};

enum GuildEmblemError
{
    ERR_GUILDEMBLEM_SUCCESS               = 0,
    ERR_GUILDEMBLEM_INVALID_TABARD_COLORS = 1,
    ERR_GUILDEMBLEM_NOGUILD               = 2,
    ERR_GUILDEMBLEM_NOTGUILDMASTER        = 3,
    ERR_GUILDEMBLEM_NOTENOUGHMONEY        = 4,
    ERR_GUILDEMBLEM_INVALIDVENDOR         = 5
};

enum GuildMemberFlags
{
    GUILDMEMBER_STATUS_NONE             = 0x0000,
    GUILDMEMBER_STATUS_ONLINE           = 0x0001,
    GUILDMEMBER_STATUS_AFK              = 0x0002,
    GUILDMEMBER_STATUS_DND              = 0x0004,
    GUILDMEMBER_STATUS_MOBILE           = 0x0008, // remote chat from mobile app
};

enum GuildNews
{
    GUILD_NEWS_GUILD_ACHIEVEMENT        = 0,
    GUILD_NEWS_PLAYER_ACHIEVEMENT       = 1,
    GUILD_NEWS_DUNGEON_ENCOUNTER        = 2, // @todo Implement
    GUILD_NEWS_ITEM_LOOTED              = 3,
    GUILD_NEWS_ITEM_CRAFTED             = 4,
    GUILD_NEWS_ITEM_PURCHASED           = 5,
    GUILD_NEWS_LEVEL_UP                 = 6,
    GUILD_NEWS_CREATE                   = 7, // @todo Implement
    GUILD_NEWS_EVENT                    = 8  // @todo Implement
};

struct GuildReward
{
    uint32 ItemID;
    uint8 MinGuildRep;
    Trinity::RaceMask<uint64> RaceMask;
    uint64 Cost;
    std::vector<uint32> AchievementsRequired;
};

uint32 const MinNewsItemLevel = 353;

// Guild Challenge
#define GUILD_CHALLENGES_TYPES 6

const uint32 GuildChallengeGoldReward[GUILD_CHALLENGES_TYPES]         = { 0, 250,    1000,    500,   250,   500 };
const uint32 GuildChallengeMaxLevelGoldReward[GUILD_CHALLENGES_TYPES] = { 0, 125,    500,     250,   125,   250 };
const uint32 GuildChallengesMaxCount[GUILD_CHALLENGES_TYPES]          = { 0, 7,      1,       3,     0,     3 };

// Emblem info
class TC_GAME_API EmblemInfo
{
    public:
        EmblemInfo() : m_style(0), m_color(0), m_borderStyle(0), m_borderColor(0), m_backgroundColor(0) { }

        bool LoadFromDB(Field* fields);
        void SaveToDB(ObjectGuid::LowType guildId) const;
        void ReadPacket(WorldPackets::Guild::SaveGuildEmblem& packet);
        bool ValidateEmblemColors() const
        {
            return ValidateEmblemColors(m_style, m_color, m_borderStyle, m_borderColor, m_backgroundColor);
        }
        static bool ValidateEmblemColors(uint32 style, uint32 color, uint32 borderStyle, uint32 borderColor, uint32 backgroundColor);

        uint32 GetStyle() const { return m_style; }
        uint32 GetColor() const { return m_color; }
        uint32 GetBorderStyle() const { return m_borderStyle; }
        uint32 GetBorderColor() const { return m_borderColor; }
        uint32 GetBackgroundColor() const { return m_backgroundColor; }

    private:
        uint32 m_style;
        uint32 m_color;
        uint32 m_borderStyle;
        uint32 m_borderColor;
        uint32 m_backgroundColor;
};

// Structure for storing guild bank rights and remaining slots together.
class GuildBankRightsAndSlots
{
    public:
        GuildBankRightsAndSlots() : tabId(TAB_UNDEFINED), rights(0), slots(0) { }
        GuildBankRightsAndSlots(uint8 _tabId) : tabId(_tabId), rights(0), slots(0) { }
        GuildBankRightsAndSlots(uint8 _tabId, int8 _rights, int32 _slots) : tabId(_tabId), rights(_rights), slots(_slots) { }

        void SetGuildMasterValues()
        {
            rights = GUILD_BANK_RIGHT_FULL;
            slots = int32(GUILD_WITHDRAW_SLOT_UNLIMITED);
        }

        void SetTabId(uint8 _tabId) { tabId = _tabId; }
        void SetSlots(int32 _slots) { slots = _slots; }
        void SetRights(int8 _rights) { rights = _rights; }

        int8 GetTabId() const { return tabId; }
        int32 GetSlots() const { return slots; }
        int8 GetRights() const { return rights; }

    private:
        uint8 tabId;
        int8 rights;
        int32 slots;
};

using SlotIds = std::set<uint8>;

class TC_GAME_API Guild
{
    public:
        // Class representing guild member
        class Member
        {
            public:
                Member(ObjectGuid::LowType guildId, ObjectGuid guid, GuildRankId rankId);

                void SetStats(Player* player);
                void SetStats(std::string_view name, uint8 level, uint8 race, uint8 _class, uint8 gender, uint32 zoneId, uint32 accountId, uint32 reputation);
                bool CheckStats() const;

                void SetPublicNote(std::string_view publicNote);
                void SetOfficerNote(std::string_view officerNote);
                void SetZoneId(uint32 id) { m_zoneId = id; }
                void SetAchievementPoints(uint32 val) { m_achievementPoints = val; }
                void SetLevel(uint8 var) { m_level = var; }

                void AddFlag(uint8 var) { m_flags |= var; }
                void RemFlag(uint8 var) { m_flags &= ~var; }
                void ResetFlags() { m_flags = GUILDMEMBER_STATUS_NONE; }

                bool LoadFromDB(Field* fields);
                void SaveToDB(CharacterDatabaseTransaction trans) const;

                ObjectGuid const& GetGUID() const { return m_guid; }
                std::string const& GetName() const { return m_name; }
                uint32 GetAccountId() const { return m_accountId; }
                GuildRankId GetRankId() const { return m_rankId; }
                uint64 GetLogoutTime() const { return m_logoutTime; }
                float GetInactiveDays() const;
                std::string GetPublicNote() const { return m_publicNote; }
                std::string GetOfficerNote() const { return m_officerNote; }
                uint8 GetRace() const { return m_race; }
                uint8 GetClass() const { return m_class; }
                uint8 GetGender() const { return m_gender; }
                uint8 GetLevel() const { return m_level; }
                uint8 GetFlags() const { return m_flags; }
                uint32 GetZoneId() const { return m_zoneId; }
                uint32 GetAchievementPoints() const { return m_achievementPoints; }
                uint64 GetTotalActivity() const { return m_totalActivity; }
                uint64 GetWeekActivity() const { return m_weekActivity; }
                uint32 GetTotalReputation() const { return m_totalReputation; }
                uint32 GetWeekReputation() const { return m_weekReputation; }

                void SetTrackedCriteriaIds(std::set<uint32> criteriaIds) { m_trackedCriteriaIds = std::move(criteriaIds); }
                bool IsTrackingCriteriaId(uint32 criteriaId) const { return m_trackedCriteriaIds && m_trackedCriteriaIds->contains(criteriaId);  }

                bool IsOnline() const { return (m_flags & GUILDMEMBER_STATUS_ONLINE); }

                void ChangeRank(CharacterDatabaseTransaction trans, GuildRankId newRank);

                inline void UpdateLogoutTime();
                inline bool IsRank(GuildRankId rankId) const { return m_rankId == rankId; }
                inline bool IsSamePlayer(ObjectGuid guid) const { return m_guid == guid; }

                void UpdateBankTabWithdrawValue(CharacterDatabaseTransaction trans, uint8 tabId, uint32 amount);
                void UpdateBankMoneyWithdrawValue(CharacterDatabaseTransaction trans, uint64 amount);
                uint32 GetBankTabWithdrawValue(uint8 tabId) const { return m_bankWithdraw[tabId]; }
                uint64 GetBankMoneyWithdrawValue() const { return m_bankWithdrawMoney; }
                void ResetValues(bool weekly = false);

                Player* FindPlayer() const;
                Player* FindConnectedPlayer() const;

            private:
                ObjectGuid::LowType m_guildId;
                // Fields from characters table
                ObjectGuid m_guid;
                std::string m_name;
                uint32 m_zoneId;
                uint8 m_level;
                uint8 m_race;
                uint8 m_class;
                uint8 m_gender;
                uint8 m_flags;
                uint64 m_logoutTime;
                uint32 m_accountId;
                // Fields from guild_member table
                GuildRankId m_rankId;
                std::string m_publicNote;
                std::string m_officerNote;

                Optional<std::set<uint32>> m_trackedCriteriaIds;

                std::array<uint32, GUILD_BANK_MAX_TABS> m_bankWithdraw;
                uint64 m_bankWithdrawMoney;
                uint32 m_achievementPoints;
                uint64 m_totalActivity;
                uint64 m_weekActivity;
                uint32 m_totalReputation;
                uint32 m_weekReputation;
        };

    private:
        // Base class for event entries
        class LogEntry
        {
            public:
                LogEntry(ObjectGuid::LowType guildId, uint32 guid);
                LogEntry(ObjectGuid::LowType guildId, uint32 guid, time_t timestamp) : m_guildId(guildId), m_guid(guid), m_timestamp(timestamp) { }
                virtual ~LogEntry() { }

                uint32 GetGUID() const { return m_guid; }
                time_t GetTimestamp() const { return m_timestamp; }

                virtual void SaveToDB(CharacterDatabaseTransaction trans) const = 0;

            protected:
                ObjectGuid::LowType m_guildId;
                uint32 m_guid;
                time_t m_timestamp;
        };

        // Event log entry
        class EventLogEntry : public LogEntry
        {
            public:
                EventLogEntry(ObjectGuid::LowType guildId, uint32 guid, GuildEventLogTypes eventType, ObjectGuid::LowType playerGuid1, ObjectGuid::LowType playerGuid2, uint8 newRank) :
                    LogEntry(guildId, guid), m_eventType(eventType), m_playerGuid1(playerGuid1), m_playerGuid2(playerGuid2), m_newRank(newRank) { }

                EventLogEntry(ObjectGuid::LowType guildId, uint32 guid, time_t timestamp, GuildEventLogTypes eventType, ObjectGuid::LowType playerGuid1, ObjectGuid::LowType playerGuid2, uint8 newRank) :
                    LogEntry(guildId, guid, timestamp), m_eventType(eventType), m_playerGuid1(playerGuid1), m_playerGuid2(playerGuid2), m_newRank(newRank) { }

                ~EventLogEntry() { }

                void SaveToDB(CharacterDatabaseTransaction trans) const override;
                void WritePacket(WorldPackets::Guild::GuildEventLogQueryResults& packet) const;

            private:
                GuildEventLogTypes m_eventType;
                ObjectGuid::LowType m_playerGuid1;
                ObjectGuid::LowType m_playerGuid2;
                uint8 m_newRank;
        };

        // Bank event log entry
        class BankEventLogEntry : public LogEntry
        {
            public:
                static bool IsMoneyEvent(GuildBankEventLogTypes eventType)
                {
                    return
                        eventType == GUILD_BANK_LOG_DEPOSIT_MONEY ||
                        eventType == GUILD_BANK_LOG_WITHDRAW_MONEY ||
                        eventType == GUILD_BANK_LOG_REPAIR_MONEY ||
                        eventType == GUILD_BANK_LOG_CASH_FLOW_DEPOSIT;
                }

                bool IsMoneyEvent() const
                {
                    return IsMoneyEvent(m_eventType);
                }

                BankEventLogEntry(ObjectGuid::LowType guildId, uint32 guid, GuildBankEventLogTypes eventType, uint8 tabId, ObjectGuid::LowType playerGuid, uint64 itemOrMoney, uint16 itemStackCount, uint8 destTabId) :
                    LogEntry(guildId, guid), m_eventType(eventType), m_bankTabId(tabId), m_playerGuid(playerGuid),
                    m_itemOrMoney(itemOrMoney), m_itemStackCount(itemStackCount), m_destTabId(destTabId) { }

                BankEventLogEntry(ObjectGuid::LowType guildId, uint32 guid, time_t timestamp, uint8 tabId, GuildBankEventLogTypes eventType, ObjectGuid::LowType playerGuid, uint64 itemOrMoney, uint16 itemStackCount, uint8 destTabId) :
                    LogEntry(guildId, guid, timestamp), m_eventType(eventType), m_bankTabId(tabId), m_playerGuid(playerGuid),
                    m_itemOrMoney(itemOrMoney), m_itemStackCount(itemStackCount), m_destTabId(destTabId) { }

                ~BankEventLogEntry() { }

                void SaveToDB(CharacterDatabaseTransaction trans) const override;
                void WritePacket(WorldPackets::Guild::GuildBankLogQueryResults& packet) const;

            private:
                GuildBankEventLogTypes m_eventType;
                uint8  m_bankTabId;
                ObjectGuid::LowType m_playerGuid;
                uint64 m_itemOrMoney;
                uint16 m_itemStackCount;
                uint8  m_destTabId;
        };

        // News log entry
        class NewsLogEntry : public LogEntry
        {
            public:
                NewsLogEntry(ObjectGuid::LowType guildId, uint32 guid, GuildNews type, ObjectGuid playerGuid, uint32 flags, uint32 value) :
                    LogEntry(guildId, guid), m_type(type), m_playerGuid(playerGuid), m_flags(flags), m_value(value) { }

                NewsLogEntry(ObjectGuid::LowType guildId, uint32 guid, time_t timestamp, GuildNews type, ObjectGuid playerGuid, uint32 flags, uint32 value) :
                    LogEntry(guildId, guid, timestamp), m_type(type), m_playerGuid(playerGuid), m_flags(flags), m_value(value) { }

                ~NewsLogEntry() { }

                GuildNews GetType() const { return m_type; }
                ObjectGuid GetPlayerGuid() const { return m_playerGuid; }
                uint32 GetValue() const { return m_value; }
                uint32 GetFlags() const { return m_flags; }
                void SetSticky(bool sticky)
                {
                    if (sticky)
                       m_flags |= 1;
                   else
                       m_flags &= ~1;
                }

                void SaveToDB(CharacterDatabaseTransaction trans) const override;
                void WritePacket(WorldPackets::Guild::GuildNews& newsPacket) const;

            private:
                GuildNews m_type;
                ObjectGuid m_playerGuid;
                uint32 m_flags;
                uint32 m_value;
        };

        // Class encapsulating work with events collection
        template <typename Entry>
        class LogHolder
        {
            public:
                LogHolder();

                // Checks if new log entry can be added to holder
                bool CanInsert() const { return m_log.size() < m_maxRecords; }

                // Adds event from DB to collection
                template <typename... Ts>
                void LoadEvent(Ts&&... args);

                // Adds new event to collection and saves it to DB
                template <typename... Ts>
                Entry& AddEvent(CharacterDatabaseTransaction trans, Ts&&... args);

                uint32 GetNextGUID();
                std::list<Entry>& GetGuildLog() { return m_log; }
                std::list<Entry> const& GetGuildLog() const { return m_log; }

            private:
                std::list<Entry> m_log;
                uint32 const m_maxRecords;
                uint32 m_nextGUID;
        };

        // Class encapsulating guild rank data
        class RankInfo
        {
            public:
                RankInfo(): m_guildId(UI64LIT(0)), m_rankId(GuildRankId(0xFF)), m_rankOrder(GuildRankOrder(0)), m_rights(GR_RIGHT_NONE), m_bankMoneyPerDay(0) { }
                RankInfo(ObjectGuid::LowType guildId) : m_guildId(guildId), m_rankId(GuildRankId(0xFF)), m_rankOrder(GuildRankOrder(0)), m_rights(GR_RIGHT_NONE), m_bankMoneyPerDay(0) { }
                RankInfo(ObjectGuid::LowType guildId, GuildRankId rankId, GuildRankOrder rankOrder, std::string_view name, uint32 rights, uint32 money) :
                    m_guildId(guildId), m_rankId(rankId), m_rankOrder(rankOrder), m_name(name), m_rights(rights), m_bankMoneyPerDay(money) { }

                void LoadFromDB(Field* fields);
                void SaveToDB(CharacterDatabaseTransaction trans) const;

                GuildRankId GetId() const { return m_rankId; }

                GuildRankOrder GetOrder() const { return m_rankOrder; }
                void SetOrder(GuildRankOrder rankOrder) { m_rankOrder = rankOrder; }

                std::string const& GetName() const { return m_name; }
                void SetName(std::string_view name);

                uint32 GetRights() const { return m_rights; }
                void SetRights(uint32 rights);

                uint32 GetBankMoneyPerDay() const
                {
                    return m_rankId != GuildRankId::GuildMaster ? m_bankMoneyPerDay : GUILD_WITHDRAW_MONEY_UNLIMITED;
                }

                void SetBankMoneyPerDay(uint32 money);

                inline int8 GetBankTabRights(uint8 tabId) const
                {
                    return tabId < GUILD_BANK_MAX_TABS ? m_bankTabRightsAndSlots[tabId].GetRights() : 0;
                }

                inline int32 GetBankTabSlotsPerDay(uint8 tabId) const
                {
                    return tabId < GUILD_BANK_MAX_TABS ? m_bankTabRightsAndSlots[tabId].GetSlots() : 0;
                }

                void SetBankTabSlotsAndRights(GuildBankRightsAndSlots rightsAndSlots, bool saveToDB);
                void CreateMissingTabsIfNeeded(uint8 ranks, CharacterDatabaseTransaction trans, bool logOnCreate = false);

            private:
                ObjectGuid::LowType m_guildId;
                GuildRankId m_rankId;
                GuildRankOrder m_rankOrder;
                std::string m_name;
                uint32 m_rights;
                uint32 m_bankMoneyPerDay;
                std::array<GuildBankRightsAndSlots, GUILD_BANK_MAX_TABS> m_bankTabRightsAndSlots = {};
        };

        class BankTab
        {
            public:
                BankTab(ObjectGuid::LowType guildId, uint8 tabId);

                void LoadFromDB(Field* fields);
                bool LoadItemFromDB(Field* fields);
                void Delete(CharacterDatabaseTransaction trans, bool removeItemsFromDB = false);

                void SetInfo(std::string_view name, std::string_view icon);
                void SetText(std::string_view text);
                void SendText(Guild const* guild, WorldSession* session) const;

                std::string const& GetName() const { return m_name; }
                std::string const& GetIcon() const { return m_icon; }
                std::string const& GetText() const { return m_text; }

                inline Item* GetItem(uint8 slotId) const { return slotId < GUILD_BANK_MAX_SLOTS ?  m_items[slotId] : nullptr; }
                bool SetItem(CharacterDatabaseTransaction trans, uint8 slotId, Item* item);

            private:
                ObjectGuid::LowType m_guildId;
                uint8 m_tabId;

                std::array<Item*, GUILD_BANK_MAX_SLOTS> m_items = {};
                std::string m_name;
                std::string m_icon;
                std::string m_text;
        };

        // Movement data
        class MoveItemData
        {
            public:
                MoveItemData(Guild* guild, Player* player, uint8 container, uint8 slotId);
                virtual ~MoveItemData();

                virtual bool IsBank() const = 0;
                // Initializes item pointer. Returns true, if item exists, false otherwise.
                virtual bool InitItem() = 0;
                // Checks splited amount against item. Splited amount cannot be more that number of items in stack.
                virtual bool CheckItem(uint32& splitedAmount);
                // Defines if player has rights to save item in container
                virtual bool HasStoreRights(MoveItemData* /*pOther*/) const { return true; }
                // Defines if player has rights to withdraw item from container
                virtual bool HasWithdrawRights(MoveItemData* /*pOther*/) const { return true; }
                // Checks if container can store specified item
                InventoryResult CanStore(Item* pItem, bool swap, bool sendError);
                // Clones stored item
                bool CloneItem(uint32 count);
                // Remove item from container (if splited update items fields)
                virtual void RemoveItem(CharacterDatabaseTransaction trans, MoveItemData* pOther, uint32 splitedAmount = 0) = 0;
                // Saves item to container
                virtual Item* StoreItem(CharacterDatabaseTransaction trans, Item* pItem) = 0;
                // Log bank event
                virtual void LogBankEvent(CharacterDatabaseTransaction trans, MoveItemData* pFrom, uint32 count) const = 0;
                // Log GM action
                virtual void LogAction(MoveItemData* pFrom) const;
                // Copy slots id from position vector
                void CopySlots(SlotIds& ids) const;
                // Sends equip error to player
                void SendEquipError(InventoryResult result, Item const* item);

                Item* GetItem(bool isCloned = false) const { return isCloned ? m_pClonedItem : m_pItem; }
                uint8 GetContainer() const { return m_container; }
                uint8 GetSlotId() const { return m_slotId; }

            protected:
                virtual InventoryResult CanStore(Item* pItem, bool swap) = 0;

                Guild* m_pGuild;
                Player* m_pPlayer;
                uint8 m_container;
                uint8 m_slotId;
                Item* m_pItem;
                Item* m_pClonedItem;
                std::vector<ItemPosCount> m_vec;
        };

        class PlayerMoveItemData : public MoveItemData
        {
            public:
                PlayerMoveItemData(Guild* guild, Player* player, uint8 container, uint8 slotId) :
                    MoveItemData(guild, player, container, slotId) { }

                bool IsBank() const override { return false; }
                bool InitItem() override;
                void RemoveItem(CharacterDatabaseTransaction trans, MoveItemData* pOther, uint32 splitedAmount = 0) override;
                Item* StoreItem(CharacterDatabaseTransaction trans, Item* pItem) override;
                void LogBankEvent(CharacterDatabaseTransaction trans, MoveItemData* pFrom, uint32 count) const override;

            protected:
                InventoryResult CanStore(Item* pItem, bool swap) override;
        };

        class BankMoveItemData : public MoveItemData
        {
            public:
                BankMoveItemData(Guild* guild, Player* player, uint8 container, uint8 slotId) :
                    MoveItemData(guild, player, container, slotId) { }

                bool IsBank() const override { return true; }
                bool InitItem() override;
                bool HasStoreRights(MoveItemData* pOther) const override;
                bool HasWithdrawRights(MoveItemData* pOther) const override;
                void RemoveItem(CharacterDatabaseTransaction trans, MoveItemData* pOther, uint32 splitedAmount) override;
                Item* StoreItem(CharacterDatabaseTransaction trans, Item* pItem) override;
                void LogBankEvent(CharacterDatabaseTransaction trans, MoveItemData* pFrom, uint32 count) const override;
                void LogAction(MoveItemData* pFrom) const override;

            protected:
                InventoryResult CanStore(Item* pItem, bool swap) override;

            private:
                Item* _StoreItem(CharacterDatabaseTransaction trans, BankTab* pTab, Item* pItem, ItemPosCount& pos, bool clone) const;
                bool _ReserveSpace(uint8 slotId, Item* pItem, Item* pItemDest, uint32& count);
                void CanStoreItemInTab(Item* pItem, uint8 skipSlotId, bool merge, uint32& count);
        };

    public:
        static void SendCommandResult(WorldSession* session, GuildCommandType type, GuildCommandError errCode, std::string_view param = "");
        static void SendSaveEmblemResult(WorldSession* session, GuildEmblemError errCode);

        Guild();
        ~Guild();

        bool Create(Player* pLeader, std::string_view name);
        void Disband();

        void SaveToDB();

        // Getters
        ObjectGuid::LowType GetId() const { return m_id; }
        ObjectGuid GetGUID() const { return ObjectGuid::Create<HighGuid::Guild>(m_id); }
        ObjectGuid GetLeaderGUID() const { return m_leaderGuid; }
        std::string const& GetName() const { return m_name; }
        std::string const& GetMOTD() const { return m_motd; }
        std::string const& GetInfo() const { return m_info; }
        time_t GetCreatedDate() const { return m_createdDate; }
        uint64 GetBankMoney() const { return m_bankMoney; }

        bool SetName(std::string_view name);

        // Handle client commands
        void HandleRoster(WorldSession* session);
        void SendQueryResponse(WorldSession* session);
        void HandleSetAchievementTracking(WorldSession* session, uint32 const* achievementIdsBegin, uint32 const* achievementIdsEnd);
        void HandleGetAchievementMembers(WorldSession* session, uint32 achievementId) const;
        void HandleSetMOTD(WorldSession* session, std::string_view motd);
        void HandleSetInfo(WorldSession* session, std::string_view info);
        void HandleSetEmblem(WorldSession* session, EmblemInfo const& emblemInfo);
        void HandleSetNewGuildMaster(WorldSession* session, std::string_view name, bool isSelfPromote);
        void HandleSetBankTabInfo(WorldSession* session, uint8 tabId, std::string_view name, std::string_view icon);
        void HandleSetMemberNote(WorldSession* session, std::string_view note, ObjectGuid guid, bool isPublic);
        void HandleSetRankInfo(WorldSession* session, GuildRankId rankId, std::string_view name, uint32 rights, uint32 moneyPerDay, std::array<GuildBankRightsAndSlots, GUILD_BANK_MAX_TABS> const& rightsAndSlots);
        void HandleBuyBankTab(WorldSession* session, uint8 tabId);
        void HandleInviteMember(WorldSession* session, std::string_view name);
        void HandleAcceptMember(WorldSession* session);
        void HandleLeaveMember(WorldSession* session);
        void HandleRemoveMember(WorldSession* session, ObjectGuid guid);
        void HandleUpdateMemberRank(WorldSession* session, ObjectGuid guid, bool demote);
        void HandleSetMemberRank(WorldSession* session, ObjectGuid guid, ObjectGuid setterGuid, GuildRankOrder rank);
        void HandleAddNewRank(WorldSession* session, std::string_view name);
        void HandleRemoveRank(WorldSession* session, GuildRankOrder rankOrder);
        void HandleShiftRank(WorldSession* session, GuildRankOrder rankOrder, bool shiftUp);
        void HandleMemberDepositMoney(WorldSession* session, uint64 amount, bool cashFlow = false);
        bool HandleMemberWithdrawMoney(WorldSession* session, uint64 amount, bool repair = false);
        void HandleMemberLogout(WorldSession* session);
        void HandleDelete(WorldSession* session);
        void HandleGuildPartyRequest(WorldSession* session) const;
        void HandleNewsSetSticky(WorldSession* session, uint32 newsId, bool sticky);
        void HandleGuildRequestChallengeUpdate(WorldSession* session) const;

        void UpdateMemberData(Player* player, uint8 dataid, uint32 value);
        void OnPlayerStatusChange(Player* player, uint32 flag, bool state);

        // Send info to client
        void SendGuildRankInfo(WorldSession* session) const;
        void SendEventLog(WorldSession* session) const;
        void SendBankLog(WorldSession* session, uint8 tabId) const;
        void SendBankList(WorldSession* session, uint8 tabId, bool fullUpdate) const;
        void SendBankTabText(WorldSession* session, uint8 tabId) const;
        void SendPermissions(WorldSession* session) const;
        void SendMoneyInfo(WorldSession* session) const;
        void SendLoginInfo(WorldSession* session);
        void SendNewsUpdate(WorldSession* session) const;

        // Send events
        void SendEventAwayChanged(ObjectGuid const& memberGuid, bool afk, bool dnd);
        void SendEventBankMoneyChanged() const;
        void SendEventMOTD(WorldSession* session, bool broadcast = false) const;
        void SendEventNewLeader(Member* newLeader, Member* oldLeader, bool isSelfPromoted = false) const;
        void SendEventPlayerLeft(Member* leaver, Member* remover = nullptr, bool isRemoved = false) const;
        void SendEventPresenceChanged(WorldSession* session, bool loggedOn, bool broadcast = false) const;

        // Load from DB
        bool LoadFromDB(Field* fields);
        void LoadGuildNewsLogFromDB(Field* fields);
        void LoadRankFromDB(Field* fields);
        bool LoadMemberFromDB(Field* fields);
        bool LoadEventLogFromDB(Field* fields);
        void LoadBankRightFromDB(Field* fields);
        void LoadBankTabFromDB(Field* fields);
        bool LoadBankEventLogFromDB(Field* fields);
        bool LoadBankItemFromDB(Field* fields);
        bool Validate();

        // Broadcasts
        void BroadcastToGuild(WorldSession* session, bool officerOnly, std::string_view msg, uint32 language = LANG_UNIVERSAL) const;
        void BroadcastAddonToGuild(WorldSession* session, bool officerOnly, std::string_view msg, std::string_view prefix, bool isLogged) const;
        void BroadcastPacketToRank(WorldPacket const* packet, GuildRankId rankId) const;
        void BroadcastPacket(WorldPacket const* packet) const;

        void MassInviteToEvent(WorldSession* session, uint32 minLevel, uint32 maxLevel, GuildRankOrder minRank);

        template<class Do>
        void BroadcastWorker(Do&& _do, Player const* except = nullptr) const
        {
            for (auto const& [_, member] : m_members)
                if (Player* player = member.FindConnectedPlayer())
                    if (player != except)
                        _do(player);
        }

        // Members
        // Adds member to guild. If rankId == GUILD_RANK_NONE, lowest rank is assigned.
        bool AddMember(CharacterDatabaseTransaction trans, ObjectGuid guid, Optional<GuildRankId> rankId = {});
        bool DeleteMember(CharacterDatabaseTransaction trans, ObjectGuid guid, bool isDisbanding = false, bool isKicked = false);
        bool ChangeMemberRank(CharacterDatabaseTransaction trans, ObjectGuid guid, GuildRankId newRank);
        bool IsMember(ObjectGuid guid) const;
        uint32 GetMembersCount() const { return uint32(m_members.size()); }
        std::unordered_map<ObjectGuid, Member> const& GetMembers() const { return m_members; }
        uint64 GetMemberAvailableMoneyForRepairItems(ObjectGuid guid) const;
        std::vector<Player*> GetMembersTrackingCriteria(uint32 criteriaId) const;

        // Bank
        void SwapItems(Player* player, uint8 tabId, uint8 slotId, uint8 destTabId, uint8 destSlotId, uint32 splitedAmount);
        void SwapItemsWithInventory(Player* player, bool toChar, uint8 tabId, uint8 slotId, uint8 playerBag, uint8 playerSlotId, uint32 splitedAmount);

        // Bank tabs
        void SetBankTabText(uint8 tabId, std::string_view text);

        GuildAchievementMgr& GetAchievementMgr() { return *m_achievementMgr; }
        GuildAchievementMgr const& GetAchievementMgr() const { return *m_achievementMgr; }

        // Pre-6.x guild leveling
        uint8 GetLevel() const { return GUILD_OLD_MAX_LEVEL; }

        void AddGuildNews(uint8 type, ObjectGuid guid, uint32 flags, uint32 value);

        EmblemInfo const& GetEmblemInfo() const { return m_emblemInfo; }
        void ResetTimes(bool weekly);

        bool HasAchieved(uint32 achievementId) const;
        void UpdateCriteria(CriteriaType type, uint64 miscValue1, uint64 miscValue2, uint64 miscValue3, WorldObject const* ref, Player* player);

        Trinity::unique_weak_ptr<Guild> GetWeakPtr() const { return m_weakRef; }
        void SetWeakPtr(Trinity::unique_weak_ptr<Guild> weakRef) { m_weakRef = std::move(weakRef); }

    protected:
        ObjectGuid::LowType m_id;
        std::string m_name;
        ObjectGuid m_leaderGuid;
        std::string m_motd;
        std::string m_info;
        time_t m_createdDate;

        EmblemInfo m_emblemInfo;
        uint32 m_accountsNumber;
        uint64 m_bankMoney;

        std::vector<RankInfo> m_ranks;
        std::unordered_map<ObjectGuid, Member> m_members;
        std::vector<BankTab> m_bankTabs;

        // These are actually ordered lists. The first element is the oldest entry.
        LogHolder<EventLogEntry> m_eventLog;
        std::array<LogHolder<BankEventLogEntry>, GUILD_BANK_MAX_TABS + 1> m_bankEventLog = {};
        LogHolder<NewsLogEntry> m_newsLog;
        std::unique_ptr<GuildAchievementMgr> m_achievementMgr;

        Trinity::unique_weak_ptr<Guild> m_weakRef;

    private:
        inline uint8 _GetRanksSize() const { return uint8(m_ranks.size()); }
        RankInfo const* GetRankInfo(GuildRankId rankId) const;
        RankInfo* GetRankInfo(GuildRankId rankId);
        RankInfo const* GetRankInfo(GuildRankOrder rankOrder) const;
        RankInfo* GetRankInfo(GuildRankOrder rankOrder);
        bool _HasRankRight(Player const* player, uint32 right) const;
    public:
        bool HasAnyRankRight(GuildRankId rankId, GuildRankRights rights) const;

    private:
        inline GuildRankId _GetLowestRankId() const { return m_ranks.back().GetId(); }

        inline uint8 _GetPurchasedTabsSize() const { return uint8(m_bankTabs.size()); }
        inline BankTab* GetBankTab(uint8 tabId) { return tabId < m_bankTabs.size() ? &m_bankTabs[tabId] : nullptr; }
        inline BankTab const* GetBankTab(uint8 tabId) const { return tabId < m_bankTabs.size() ? &m_bankTabs[tabId] : nullptr; }

    public:
        inline Member const* GetMember(ObjectGuid const& guid) const
        {
            auto itr = m_members.find(guid);
            return (itr != m_members.end()) ? &itr->second : nullptr;
        }

    private:
        inline Member* GetMember(ObjectGuid const& guid)
        {
            auto itr = m_members.find(guid);
            return (itr != m_members.end()) ? &itr->second : nullptr;
        }

        inline Member* GetMember(std::string_view name)
        {
            for (auto itr = m_members.begin(); itr != m_members.end(); ++itr)
                if (itr->second.GetName() == name)
                    return &itr->second;

            return nullptr;
        }

        static void _DeleteMemberFromDB(CharacterDatabaseTransaction trans, ObjectGuid::LowType lowguid);

        // Tries to create new bank tab
        void _CreateNewBankTab();
        // Creates default guild ranks with names in given locale
        void _CreateDefaultGuildRanks(CharacterDatabaseTransaction trans, LocaleConstant loc);
        // Creates new rank
        bool _CreateRank(CharacterDatabaseTransaction trans, std::string_view name, uint32 rights);
        // Update account number when member added/removed from guild
        void _UpdateAccountsNumber();
        bool _IsLeader(Player* player) const;
        void _DeleteBankItems(CharacterDatabaseTransaction trans, bool removeItemsFromDB = false);
        bool _ModifyBankMoney(CharacterDatabaseTransaction trans, uint64 amount, bool add);
        void _SetLeader(CharacterDatabaseTransaction trans, Member& leader);

        void _SetRankBankMoneyPerDay(GuildRankId rankId, uint32 moneyPerDay);
        void _SetRankBankTabRightsAndSlots(GuildRankId rankId, GuildBankRightsAndSlots rightsAndSlots, bool saveToDB = true);
        int8 _GetRankBankTabRights(GuildRankId rankId, uint8 tabId) const;
        uint32 _GetRankRights(GuildRankId rankId) const;
        uint32 _GetRankBankMoneyPerDay(GuildRankId rankId) const;
        int32 _GetRankBankTabSlotsPerDay(GuildRankId rankId, uint8 tabId) const;
        std::string _GetRankName(GuildRankId rankId) const;

        int32 _GetMemberRemainingSlots(Member const& member, uint8 tabId) const;
        int64 _GetMemberRemainingMoney(Member const& member) const;
        void _UpdateMemberWithdrawSlots(CharacterDatabaseTransaction trans, ObjectGuid guid, uint8 tabId);
        bool _MemberHasTabRights(ObjectGuid guid, uint8 tabId, int32 rights) const;

        void _LogEvent(GuildEventLogTypes eventType, ObjectGuid::LowType playerGuid1, ObjectGuid::LowType playerGuid2 = UI64LIT(0), uint8 newRank = 0);
        void _LogBankEvent(CharacterDatabaseTransaction trans, GuildBankEventLogTypes eventType, uint8 tabId, ObjectGuid::LowType playerGuid, uint64 itemOrMoney, uint16 itemStackCount = 0, uint8 destTabId = 0);

        Item* _GetItem(uint8 tabId, uint8 slotId) const;
        void _RemoveItem(CharacterDatabaseTransaction trans, uint8 tabId, uint8 slotId);
        void _MoveItems(MoveItemData* pSrc, MoveItemData* pDest, uint32 splitedAmount) const;
        static InventoryResult _DoItemsMove(MoveItemData* pSrc, MoveItemData* pDest, bool sendError, uint32 splitedAmount = 0);

        void _SendBankContentUpdate(MoveItemData* pSrc, MoveItemData* pDest) const;
        void _SendBankContentUpdate(uint8 tabId, SlotIds slots) const;
        void SendGuildRanksUpdate(ObjectGuid setterGuid, ObjectGuid targetGuid, GuildRankId rank);
};
#endif
