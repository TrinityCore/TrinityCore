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

/// \addtogroup world The World
/// @{
/// \file

#ifndef __WORLD_H
#define __WORLD_H

#include "Common.h"
#include "AsyncCallbackProcessor.h"
#include "DatabaseEnvFwd.h"
#include "LockedQueue.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "SharedDefines.h"
#include "Timer.h"

#include <atomic>
#include <list>
#include <map>
#include <memory>
#include <unordered_map>
#include <vector>

class Player;
class WorldPacket;
class WorldSession;
class WorldSocket;

// ServerMessages.dbc
enum ServerMessageType
{
    SERVER_MSG_SHUTDOWN_TIME          = 1,
    SERVER_MSG_RESTART_TIME           = 2,
    SERVER_MSG_STRING                 = 3,
    SERVER_MSG_SHUTDOWN_CANCELLED     = 4,
    SERVER_MSG_RESTART_CANCELLED      = 5,
    SERVER_MSG_BG_SHUTDOWN_TIME       = 6,
    SERVER_MSG_BG_RESTART_TIME        = 7,
    SERVER_MSG_INSTANCE_SHUTDOWN_TIME = 8,
    SERVER_MSG_INSTANCE_RESTART_TIME  = 9,
    SERVER_MSG_CONTENT_READY          = 10,
    SERVER_MSG_TICKET_SERVICED_SOON   = 11,
    SERVER_MSG_WAIT_TIME_UNAVAILABLE  = 12,
    SERVER_MSG_TICKET_WAIT_TIME       = 13,
};

enum ShutdownMask : uint32
{
    SHUTDOWN_MASK_RESTART = 1,
    SHUTDOWN_MASK_IDLE    = 2,
    SHUTDOWN_MASK_FORCE   = 4
};

enum ShutdownExitCode : uint32
{
    SHUTDOWN_EXIT_CODE = 0,
    ERROR_EXIT_CODE    = 1,
    RESTART_EXIT_CODE  = 2
};

/// Timers for different object refresh rates
enum WorldTimers
{
    WUPDATE_AUCTIONS,
    WUPDATE_AUCTIONS_PENDING,
    WUPDATE_UPTIME,
    WUPDATE_CORPSES,
    WUPDATE_EVENTS,
    WUPDATE_CLEANDB,
    WUPDATE_AUTOBROADCAST,
    WUPDATE_MAILBOXQUEUE,
    WUPDATE_DELETECHARS,
    WUPDATE_AHBOT,
    WUPDATE_PINGDB,
    WUPDATE_GUILDSAVE,
    WUPDATE_BLACKMARKET,
    WUPDATE_CHECK_FILECHANGES,
    WUPDATE_WHO_LIST,
    WUPDATE_CHANNEL_SAVE,
    WUPDATE_COUNT
};

/// Configuration elements
enum WorldBoolConfigs
{
    CONFIG_DURABILITY_LOSS_IN_PVP = 0,
    CONFIG_ADDON_CHANNEL,
    CONFIG_CLEAN_CHARACTER_DB,
    CONFIG_GRID_UNLOAD,
    CONFIG_STATS_SAVE_ONLY_ON_LOGOUT,
    CONFIG_ALLOW_TWO_SIDE_INTERACTION_CALENDAR,
    CONFIG_ALLOW_TWO_SIDE_INTERACTION_CHANNEL,
    CONFIG_ALLOW_TWO_SIDE_INTERACTION_GROUP,
    CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD,
    CONFIG_ALLOW_TWO_SIDE_INTERACTION_AUCTION,
    CONFIG_ALLOW_TWO_SIDE_TRADE,
    CONFIG_ALL_TAXI_PATHS,
    CONFIG_INSTANT_TAXI,
    CONFIG_INSTANCE_IGNORE_LEVEL,
    CONFIG_INSTANCE_IGNORE_RAID,
    CONFIG_CAST_UNSTUCK,
    CONFIG_ALLOW_GM_GROUP,
    CONFIG_GM_LOWER_SECURITY,
    CONFIG_SKILL_PROSPECTING,
    CONFIG_SKILL_MILLING,
    CONFIG_WEATHER,
    CONFIG_QUEST_IGNORE_RAID,
    CONFIG_CHAT_PARTY_RAID_WARNINGS,
    CONFIG_DETECT_POS_COLLISION,
    CONFIG_RESTRICTED_LFG_CHANNEL,
    CONFIG_CHAT_FAKE_MESSAGE_PREVENTING,
    CONFIG_DEATH_CORPSE_RECLAIM_DELAY_PVP,
    CONFIG_DEATH_CORPSE_RECLAIM_DELAY_PVE,
    CONFIG_DEATH_BONES_WORLD,
    CONFIG_DEATH_BONES_BG_OR_ARENA,
    CONFIG_DIE_COMMAND_MODE,
    CONFIG_DECLINED_NAMES_USED,
    CONFIG_BATTLEGROUND_CAST_DESERTER,
    CONFIG_BATTLEGROUND_QUEUE_ANNOUNCER_ENABLE,
    CONFIG_BATTLEGROUND_QUEUE_ANNOUNCER_PLAYERONLY,
    CONFIG_BATTLEGROUND_STORE_STATISTICS_ENABLE,
    CONFIG_BG_XP_FOR_KILL,
    CONFIG_ARENA_QUEUE_ANNOUNCER_ENABLE,
    CONFIG_ARENA_SEASON_IN_PROGRESS,
    CONFIG_ARENA_LOG_EXTENDED_INFO,
    CONFIG_OFFHAND_CHECK_AT_SPELL_UNLEARN,
    CONFIG_VMAP_INDOOR_CHECK,
    CONFIG_START_ALL_SPELLS,
    CONFIG_START_ALL_EXPLORED,
    CONFIG_START_ALL_REP,
    CONFIG_PVP_TOKEN_ENABLE,
    CONFIG_NO_RESET_TALENT_COST,
    CONFIG_SHOW_KICK_IN_WORLD,
    CONFIG_SHOW_MUTE_IN_WORLD,
    CONFIG_SHOW_BAN_IN_WORLD,
    CONFIG_AUTOBROADCAST,
    CONFIG_SUPPORT_ENABLED,
    CONFIG_SUPPORT_TICKETS_ENABLED,
    CONFIG_SUPPORT_BUGS_ENABLED,
    CONFIG_SUPPORT_COMPLAINTS_ENABLED,
    CONFIG_SUPPORT_SUGGESTIONS_ENABLED,
    CONFIG_DBC_ENFORCE_ITEM_ATTRIBUTES,
    CONFIG_PRESERVE_CUSTOM_CHANNELS,
    CONFIG_PDUMP_NO_PATHS,
    CONFIG_PDUMP_NO_OVERWRITE,
    CONFIG_QUEST_IGNORE_AUTO_ACCEPT,
    CONFIG_QUEST_IGNORE_AUTO_COMPLETE,
    CONFIG_QUEST_ENABLE_QUEST_TRACKER,
    CONFIG_WARDEN_ENABLED,
    CONFIG_ENABLE_MMAPS,
    CONFIG_WINTERGRASP_ENABLE,
    CONFIG_TOLBARAD_ENABLE,
    CONFIG_EVENT_ANNOUNCE,
    CONFIG_STATS_LIMITS_ENABLE,
    CONFIG_INSTANCES_RESET_ANNOUNCE,
    CONFIG_IP_BASED_ACTION_LOGGING,
    CONFIG_CALCULATE_CREATURE_ZONE_AREA_DATA,
    CONFIG_CALCULATE_GAMEOBJECT_ZONE_AREA_DATA,
    CONFIG_FEATURE_SYSTEM_BPAY_STORE_ENABLED,
    CONFIG_FEATURE_SYSTEM_CHARACTER_UNDELETE_ENABLED,
    CONFIG_RESET_DUEL_COOLDOWNS,
    CONFIG_RESET_DUEL_HEALTH_MANA,
    CONFIG_BASEMAP_LOAD_GRIDS,
    CONFIG_INSTANCEMAP_LOAD_GRIDS,
    CONFIG_BLACKMARKET_ENABLED,
    CONFIG_HOTSWAP_ENABLED,
    CONFIG_HOTSWAP_RECOMPILER_ENABLED,
    CONFIG_HOTSWAP_EARLY_TERMINATION_ENABLED,
    CONFIG_HOTSWAP_BUILD_FILE_RECREATION_ENABLED,
    CONFIG_HOTSWAP_INSTALL_ENABLED,
    CONFIG_HOTSWAP_PREFIX_CORRECTION_ENABLED,
    CONFIG_PREVENT_RENAME_CUSTOMIZATION,
    CONFIG_CACHE_DATA_QUERIES,
    CONFIG_CREATURE_CHECK_INVALID_POSITION,
    CONFIG_GAME_OBJECT_CHECK_INVALID_POSITION,
    CONFIG_CHECK_GOBJECT_LOS,
    CONFIG_RESPAWN_DYNAMIC_ESCORTNPC,
    CONFIG_REGEN_HP_CANNOT_REACH_TARGET_IN_RAID,
    CONFIG_ALLOW_LOGGING_IP_ADDRESSES_IN_DATABASE,
    CONFIG_CHARACTER_CREATING_DISABLE_ALLIED_RACE_ACHIEVEMENT_REQUIREMENT,
    CONFIG_BATTLEGROUNDMAP_LOAD_GRIDS,
    CONFIG_ENABLE_AE_LOOT,
    CONFIG_LOAD_LOCALES,
    BOOL_CONFIG_VALUE_COUNT
};

enum WorldFloatConfigs
{
    CONFIG_GROUP_XP_DISTANCE = 0,
    CONFIG_MAX_RECRUIT_A_FRIEND_DISTANCE,
    CONFIG_SIGHT_MONSTER,
    CONFIG_LISTEN_RANGE_SAY,
    CONFIG_LISTEN_RANGE_TEXTEMOTE,
    CONFIG_LISTEN_RANGE_YELL,
    CONFIG_CREATURE_FAMILY_FLEE_ASSISTANCE_RADIUS,
    CONFIG_CREATURE_FAMILY_ASSISTANCE_RADIUS,
    CONFIG_THREAT_RADIUS,
    CONFIG_STATS_LIMITS_DODGE,
    CONFIG_STATS_LIMITS_PARRY,
    CONFIG_STATS_LIMITS_BLOCK,
    CONFIG_STATS_LIMITS_CRIT,
    CONFIG_ARENA_WIN_RATING_MODIFIER_1,
    CONFIG_ARENA_WIN_RATING_MODIFIER_2,
    CONFIG_ARENA_LOSE_RATING_MODIFIER,
    CONFIG_ARENA_MATCHMAKER_RATING_MODIFIER,
    CONFIG_RESPAWN_DYNAMICRATE_CREATURE,
    CONFIG_RESPAWN_DYNAMICRATE_GAMEOBJECT,
    CONFIG_CALL_TO_ARMS_5_PCT,
    CONFIG_CALL_TO_ARMS_10_PCT,
    CONFIG_CALL_TO_ARMS_20_PCT,
    FLOAT_CONFIG_VALUE_COUNT
};

enum WorldIntConfigs
{
    CONFIG_COMPRESSION = 0,
    CONFIG_INTERVAL_SAVE,
    CONFIG_INTERVAL_GRIDCLEAN,
    CONFIG_INTERVAL_MAPUPDATE,
    CONFIG_INTERVAL_CHANGEWEATHER,
    CONFIG_INTERVAL_DISCONNECT_TOLERANCE,
    CONFIG_PORT_WORLD,
    CONFIG_PORT_INSTANCE,
    CONFIG_SOCKET_TIMEOUTTIME,
    CONFIG_SESSION_ADD_DELAY,
    CONFIG_GAME_TYPE,
    CONFIG_REALM_ZONE,
    CONFIG_STRICT_PLAYER_NAMES,
    CONFIG_STRICT_CHARTER_NAMES,
    CONFIG_STRICT_PET_NAMES,
    CONFIG_MIN_PLAYER_NAME,
    CONFIG_MIN_CHARTER_NAME,
    CONFIG_MIN_PET_NAME,
    CONFIG_CHARACTER_CREATING_DISABLED,
    CONFIG_CHARACTER_CREATING_DISABLED_CLASSMASK,
    CONFIG_CHARACTERS_PER_ACCOUNT,
    CONFIG_CHARACTERS_PER_REALM,
    CONFIG_CHARACTER_CREATING_EVOKERS_PER_REALM,
    CONFIG_CHARACTER_CREATING_MIN_LEVEL_FOR_DEMON_HUNTER,
    CONFIG_CHARACTER_CREATING_MIN_LEVEL_FOR_EVOKER,
    CONFIG_SKIP_CINEMATICS,
    CONFIG_MAX_PLAYER_LEVEL,
    CONFIG_MIN_DUALSPEC_LEVEL,
    CONFIG_START_PLAYER_LEVEL,
    CONFIG_START_DEATH_KNIGHT_PLAYER_LEVEL,
    CONFIG_START_DEMON_HUNTER_PLAYER_LEVEL,
    CONFIG_START_EVOKER_PLAYER_LEVEL,
    CONFIG_START_ALLIED_RACE_LEVEL,
    CONFIG_START_PLAYER_MONEY,
    CONFIG_CURRENCY_START_APEXIS_CRYSTALS,
    CONFIG_CURRENCY_MAX_APEXIS_CRYSTALS,
    CONFIG_CURRENCY_START_JUSTICE_POINTS,
    CONFIG_CURRENCY_MAX_JUSTICE_POINTS,
    CONFIG_CURRENCY_RESET_HOUR,
    CONFIG_CURRENCY_RESET_DAY,
    CONFIG_CURRENCY_RESET_INTERVAL,
    CONFIG_MAX_RECRUIT_A_FRIEND_BONUS_PLAYER_LEVEL,
    CONFIG_MAX_RECRUIT_A_FRIEND_BONUS_PLAYER_LEVEL_DIFFERENCE,
    CONFIG_RESET_SCHEDULE_WEEK_DAY,
    CONFIG_RESET_SCHEDULE_HOUR,
    CONFIG_INSTANCE_UNLOAD_DELAY,
    CONFIG_DAILY_QUEST_RESET_TIME_HOUR,
    CONFIG_WEEKLY_QUEST_RESET_TIME_WDAY,
    CONFIG_MAX_PRIMARY_TRADE_SKILL,
    CONFIG_MIN_PETITION_SIGNS,
    CONFIG_MIN_QUEST_SCALED_XP_RATIO,
    CONFIG_MIN_CREATURE_SCALED_XP_RATIO,
    CONFIG_MIN_DISCOVERED_SCALED_XP_RATIO,
    CONFIG_GM_LOGIN_STATE,
    CONFIG_GM_VISIBLE_STATE,
    CONFIG_GM_CHAT,
    CONFIG_GM_WHISPERING_TO,
    CONFIG_GM_FREEZE_DURATION,
    CONFIG_GM_LEVEL_IN_GM_LIST,
    CONFIG_GM_LEVEL_IN_WHO_LIST,
    CONFIG_START_GM_LEVEL,
    CONFIG_FORCE_SHUTDOWN_THRESHOLD,
    CONFIG_GROUP_VISIBILITY,
    CONFIG_MAIL_DELIVERY_DELAY,
    CONFIG_CLEAN_OLD_MAIL_TIME,
    CONFIG_UPTIME_UPDATE,
    CONFIG_SKILL_CHANCE_ORANGE,
    CONFIG_SKILL_CHANCE_YELLOW,
    CONFIG_SKILL_CHANCE_GREEN,
    CONFIG_SKILL_CHANCE_GREY,
    CONFIG_SKILL_CHANCE_MINING_STEPS,
    CONFIG_SKILL_CHANCE_SKINNING_STEPS,
    CONFIG_SKILL_GAIN_CRAFTING,
    CONFIG_SKILL_GAIN_GATHERING,
    CONFIG_MAX_OVERSPEED_PINGS,
    CONFIG_EXPANSION,
    CONFIG_CHATFLOOD_MESSAGE_COUNT,
    CONFIG_CHATFLOOD_MESSAGE_DELAY,
    CONFIG_CHATFLOOD_ADDON_MESSAGE_COUNT,
    CONFIG_CHATFLOOD_ADDON_MESSAGE_DELAY,
    CONFIG_CHATFLOOD_MUTE_TIME,
    CONFIG_CREATURE_FAMILY_ASSISTANCE_DELAY,
    CONFIG_CREATURE_FAMILY_FLEE_DELAY,
    CONFIG_WORLD_BOSS_LEVEL_DIFF,
    CONFIG_QUEST_LOW_LEVEL_HIDE_DIFF,
    CONFIG_QUEST_HIGH_LEVEL_HIDE_DIFF,
    CONFIG_CHAT_STRICT_LINK_CHECKING_SEVERITY,
    CONFIG_CHAT_STRICT_LINK_CHECKING_KICK,
    CONFIG_CHAT_CHANNEL_LEVEL_REQ,
    CONFIG_CHAT_WHISPER_LEVEL_REQ,
    CONFIG_CHAT_EMOTE_LEVEL_REQ,
    CONFIG_CHAT_SAY_LEVEL_REQ,
    CONFIG_CHAT_YELL_LEVEL_REQ,
    CONFIG_PARTY_LEVEL_REQ,
    CONFIG_TRADE_LEVEL_REQ,
    CONFIG_AUCTION_LEVEL_REQ,
    CONFIG_MAIL_LEVEL_REQ,
    CONFIG_CORPSE_DECAY_NORMAL,
    CONFIG_CORPSE_DECAY_ELITE,
    CONFIG_CORPSE_DECAY_RAREELITE,
    CONFIG_CORPSE_DECAY_OBSOLETE,
    CONFIG_CORPSE_DECAY_RARE,
    CONFIG_CORPSE_DECAY_TRIVIAL,
    CONFIG_CORPSE_DECAY_MINUSMOB,
    CONFIG_DEATH_SICKNESS_LEVEL,
    CONFIG_INSTANT_LOGOUT,
    CONFIG_DISABLE_BREATHING,
    CONFIG_BATTLEGROUND_INVITATION_TYPE,
    CONFIG_BATTLEGROUND_PREMATURE_FINISH_TIMER,
    CONFIG_BATTLEGROUND_PREMADE_GROUP_WAIT_FOR_MATCH,
    CONFIG_BATTLEGROUND_REPORT_AFK,
    CONFIG_ARENA_MAX_RATING_DIFFERENCE,
    CONFIG_ARENA_RATING_DISCARD_TIMER,
    CONFIG_ARENA_RATED_UPDATE_TIMER,
    CONFIG_ARENA_SEASON_ID,
    CONFIG_ARENA_START_RATING,
    CONFIG_ARENA_START_PERSONAL_RATING,
    CONFIG_ARENA_START_MATCHMAKER_RATING,
    CONFIG_MAX_WHO,
    CONFIG_HONOR_AFTER_DUEL,
    CONFIG_PVP_TOKEN_MAP_TYPE,
    CONFIG_PVP_TOKEN_ID,
    CONFIG_PVP_TOKEN_COUNT,
    CONFIG_ENABLE_SINFO_LOGIN,
    CONFIG_PLAYER_ALLOW_COMMANDS,
    CONFIG_NUMTHREADS,
    CONFIG_LOGDB_CLEARINTERVAL,
    CONFIG_LOGDB_CLEARTIME,
    CONFIG_CLIENTCACHE_VERSION,
    CONFIG_GUILD_NEWS_LOG_COUNT,
    CONFIG_GUILD_EVENT_LOG_COUNT,
    CONFIG_GUILD_BANK_EVENT_LOG_COUNT,
    CONFIG_MIN_LEVEL_STAT_SAVE,
    CONFIG_RANDOM_BG_RESET_HOUR,
    CONFIG_CALENDAR_DELETE_OLD_EVENTS_HOUR,
    CONFIG_GUILD_RESET_HOUR,
    CONFIG_CHARDELETE_KEEP_DAYS,
    CONFIG_CHARDELETE_METHOD,
    CONFIG_CHARDELETE_MIN_LEVEL,
    CONFIG_CHARDELETE_DEATH_KNIGHT_MIN_LEVEL,
    CONFIG_CHARDELETE_DEMON_HUNTER_MIN_LEVEL,
    CONFIG_AUTOBROADCAST_CENTER,
    CONFIG_AUTOBROADCAST_INTERVAL,
    CONFIG_MAX_RESULTS_LOOKUP_COMMANDS,
    CONFIG_DB_PING_INTERVAL,
    CONFIG_PRESERVE_CUSTOM_CHANNEL_DURATION,
    CONFIG_PRESERVE_CUSTOM_CHANNEL_INTERVAL,
    CONFIG_PERSISTENT_CHARACTER_CLEAN_FLAGS,
    CONFIG_LFG_OPTIONSMASK,
    CONFIG_MAX_INSTANCES_PER_HOUR,
    CONFIG_XP_BOOST_DAYMASK,
    CONFIG_WARDEN_CLIENT_RESPONSE_DELAY,
    CONFIG_WARDEN_CLIENT_CHECK_HOLDOFF,
    CONFIG_WARDEN_CLIENT_FAIL_ACTION,
    CONFIG_WARDEN_CLIENT_BAN_DURATION,
    CONFIG_WARDEN_NUM_INJECT_CHECKS,
    CONFIG_WARDEN_NUM_LUA_CHECKS,
    CONFIG_WARDEN_NUM_CLIENT_MOD_CHECKS,
    CONFIG_WINTERGRASP_PLR_MAX,
    CONFIG_WINTERGRASP_PLR_MIN,
    CONFIG_WINTERGRASP_PLR_MIN_LVL,
    CONFIG_WINTERGRASP_BATTLETIME,
    CONFIG_WINTERGRASP_NOBATTLETIME,
    CONFIG_WINTERGRASP_RESTART_AFTER_CRASH,
    CONFIG_TOLBARAD_PLR_MAX,
    CONFIG_TOLBARAD_PLR_MIN,
    CONFIG_TOLBARAD_PLR_MIN_LVL,
    CONFIG_TOLBARAD_BATTLETIME,
    CONFIG_TOLBARAD_BONUSTIME,
    CONFIG_TOLBARAD_NOBATTLETIME,
    CONFIG_TOLBARAD_RESTART_AFTER_CRASH,
    CONFIG_GUILD_SAVE_INTERVAL,
    CONFIG_PACKET_SPOOF_POLICY,
    CONFIG_PACKET_SPOOF_BANMODE,
    CONFIG_PACKET_SPOOF_BANDURATION,
    CONFIG_ACC_PASSCHANGESEC,
    CONFIG_BG_REWARD_WINNER_HONOR_FIRST,
    CONFIG_BG_REWARD_WINNER_HONOR_LAST,
    CONFIG_BG_REWARD_LOSER_HONOR_FIRST,
    CONFIG_BG_REWARD_LOSER_HONOR_LAST,
    CONFIG_BG_REWARD_WINNER_CONQUEST_FIRST,
    CONFIG_BG_REWARD_WINNER_CONQUEST_LAST,
    CONFIG_CREATURE_PICKPOCKET_REFILL,
    CONFIG_CREATURE_STOP_FOR_PLAYER,
    CONFIG_AHBOT_UPDATE_INTERVAL,
    CONFIG_FEATURE_SYSTEM_CHARACTER_UNDELETE_COOLDOWN,
    CONFIG_CHARTER_COST_GUILD,
    CONFIG_CHARTER_COST_ARENA_2v2,
    CONFIG_CHARTER_COST_ARENA_3v3,
    CONFIG_CHARTER_COST_ARENA_5v5,
    CONFIG_NO_GRAY_AGGRO_ABOVE,
    CONFIG_NO_GRAY_AGGRO_BELOW,
    CONFIG_AUCTION_REPLICATE_DELAY,
    CONFIG_AUCTION_SEARCH_DELAY,
    CONFIG_AUCTION_TAINTED_SEARCH_DELAY,
    CONFIG_TALENTS_INSPECTING,
    CONFIG_RESPAWN_MINCHECKINTERVALMS,
    CONFIG_RESPAWN_DYNAMICMODE,
    CONFIG_RESPAWN_GUIDWARNLEVEL,
    CONFIG_RESPAWN_GUIDALERTLEVEL,
    CONFIG_RESPAWN_RESTARTQUIETTIME,
    CONFIG_RESPAWN_DYNAMICMINIMUM_CREATURE,
    CONFIG_RESPAWN_DYNAMICMINIMUM_GAMEOBJECT,
    CONFIG_RESPAWN_GUIDWARNING_FREQUENCY,
    CONFIG_SOCKET_TIMEOUTTIME_ACTIVE,
    CONFIG_BLACKMARKET_MAXAUCTIONS,
    CONFIG_BLACKMARKET_UPDATE_PERIOD,
    CONFIG_FACTION_BALANCE_LEVEL_CHECK_DIFF,
    INT_CONFIG_VALUE_COUNT
};

enum WorldInt64Configs
{
    CONFIG_CHARACTER_CREATING_DISABLED_RACEMASK,
    INT64_CONFIT_VALUE_COUNT
};

/// Server rates
enum Rates
{
    RATE_HEALTH = 0,
    RATE_POWER_MANA,
    RATE_POWER_RAGE_INCOME,
    RATE_POWER_RAGE_LOSS,
    RATE_POWER_FOCUS,
    RATE_POWER_ENERGY,
    RATE_POWER_COMBO_POINTS_LOSS,
    RATE_POWER_RUNIC_POWER_INCOME,
    RATE_POWER_RUNIC_POWER_LOSS,
    RATE_POWER_SOUL_SHARDS,
    RATE_POWER_LUNAR_POWER,
    RATE_POWER_HOLY_POWER,
    RATE_POWER_MAELSTROM,
    RATE_POWER_CHI,
    RATE_POWER_INSANITY,
    RATE_POWER_ARCANE_CHARGES,
    RATE_POWER_FURY,
    RATE_POWER_PAIN,
    RATE_POWER_ESSENCE,
    RATE_SKILL_DISCOVERY,
    RATE_DROP_ITEM_POOR,
    RATE_DROP_ITEM_NORMAL,
    RATE_DROP_ITEM_UNCOMMON,
    RATE_DROP_ITEM_RARE,
    RATE_DROP_ITEM_EPIC,
    RATE_DROP_ITEM_LEGENDARY,
    RATE_DROP_ITEM_ARTIFACT,
    RATE_DROP_ITEM_REFERENCED,
    RATE_DROP_ITEM_REFERENCED_AMOUNT,
    RATE_DROP_MONEY,
    RATE_XP_KILL,
    RATE_XP_BG_KILL,
    RATE_XP_QUEST,
    RATE_XP_GUILD_MODIFIER,
    RATE_XP_EXPLORE,
    RATE_REPAIRCOST,
    RATE_REPUTATION_GAIN,
    RATE_REPUTATION_LOWLEVEL_KILL,
    RATE_REPUTATION_LOWLEVEL_QUEST,
    RATE_REPUTATION_RECRUIT_A_FRIEND_BONUS,
    RATE_CREATURE_HP_NORMAL,
    RATE_CREATURE_HP_ELITE,
    RATE_CREATURE_HP_RAREELITE,
    RATE_CREATURE_HP_OBSOLETE,
    RATE_CREATURE_HP_RARE,
    RATE_CREATURE_HP_TRIVIAL,
    RATE_CREATURE_HP_MINUSMOB,
    RATE_CREATURE_DAMAGE_NORMAL,
    RATE_CREATURE_DAMAGE_ELITE,
    RATE_CREATURE_DAMAGE_RAREELITE,
    RATE_CREATURE_DAMAGE_OBSOLETE,
    RATE_CREATURE_DAMAGE_RARE,
    RATE_CREATURE_DAMAGE_TRIVIAL,
    RATE_CREATURE_DAMAGE_MINUSMOB,
    RATE_CREATURE_SPELLDAMAGE_NORMAL,
    RATE_CREATURE_SPELLDAMAGE_ELITE,
    RATE_CREATURE_SPELLDAMAGE_RAREELITE,
    RATE_CREATURE_SPELLDAMAGE_OBSOLETE,
    RATE_CREATURE_SPELLDAMAGE_RARE,
    RATE_CREATURE_SPELLDAMAGE_TRIVIAL,
    RATE_CREATURE_SPELLDAMAGE_MINUSMOB,
    RATE_CREATURE_AGGRO,
    RATE_REST_INGAME,
    RATE_REST_OFFLINE_IN_TAVERN_OR_CITY,
    RATE_REST_OFFLINE_IN_WILDERNESS,
    RATE_DAMAGE_FALL,
    RATE_AUCTION_TIME,
    RATE_AUCTION_DEPOSIT,
    RATE_AUCTION_CUT,
    RATE_HONOR,
    RATE_TALENT,
    RATE_CORPSE_DECAY_LOOTED,
    RATE_INSTANCE_RESET_TIME,
    RATE_DURABILITY_LOSS_ON_DEATH,
    RATE_DURABILITY_LOSS_DAMAGE,
    RATE_DURABILITY_LOSS_PARRY,
    RATE_DURABILITY_LOSS_ABSORB,
    RATE_DURABILITY_LOSS_BLOCK,
    RATE_MOVESPEED,
    RATE_XP_BOOST,
    RATE_MONEY_QUEST,
    RATE_MONEY_MAX_LEVEL_QUEST,
    MAX_RATES
};

struct PersistentWorldVariable;

/// Storage class for commands issued for delayed execution
struct TC_GAME_API CliCommandHolder
{
    using Print = void(*)(void*, std::string_view);
    using CommandFinished = void(*)(void*, bool success);

    void* m_callbackArg;
    char* m_command;
    Print m_print;
    CommandFinished m_commandFinished;

    CliCommandHolder(void* callbackArg, char const* command, Print zprint, CommandFinished commandFinished);
    ~CliCommandHolder();

private:
    CliCommandHolder(CliCommandHolder const& right) = delete;
    CliCommandHolder& operator=(CliCommandHolder const& right) = delete;
};

typedef std::unordered_map<uint32, WorldSession*> SessionMap;

/// The World
class TC_GAME_API World
{
    public:
        static World* instance();

        static std::atomic<uint32> m_worldLoopCounter;

        WorldSession* FindSession(uint32 id) const;
        void AddSession(WorldSession* s);
        void AddInstanceSocket(std::weak_ptr<WorldSocket> sock, uint64 connectToKey);
        void SendAutoBroadcast();
        bool RemoveSession(uint32 id);
        /// Get the number of current active sessions
        void UpdateMaxSessionCounters();
        SessionMap const& GetAllSessions() const { return m_sessions; }
        uint32 GetActiveAndQueuedSessionCount() const { return uint32(m_sessions.size()); }
        uint32 GetActiveSessionCount() const { return uint32(m_sessions.size() - m_QueuedPlayer.size()); }
        uint32 GetQueuedSessionCount() const { return uint32(m_QueuedPlayer.size()); }
        /// Get the maximum number of parallel sessions on the server since last reboot
        uint32 GetMaxQueuedSessionCount() const { return m_maxQueuedSessionCount; }
        uint32 GetMaxActiveSessionCount() const { return m_maxActiveSessionCount; }
        /// Get number of players
        inline uint32 GetPlayerCount() const { return m_PlayerCount; }
        inline uint32 GetMaxPlayerCount() const { return m_MaxPlayerCount; }
        /// Increase/Decrease number of players
        inline void IncreasePlayerCount()
        {
            m_PlayerCount++;
            m_MaxPlayerCount = std::max(m_MaxPlayerCount, m_PlayerCount);
        }
        inline void DecreasePlayerCount() { m_PlayerCount--; }

        Player* FindPlayerInZone(uint32 zone);

        /// Deny clients?
        bool IsClosed() const;

        /// Close world
        void SetClosed(bool val);

        /// Security level limitations
        AccountTypes GetPlayerSecurityLimit() const { return m_allowedSecurityLevel; }
        void SetPlayerSecurityLimit(AccountTypes sec);
        void LoadDBAllowedSecurityLevel();

        /// Active session server limit
        void SetPlayerAmountLimit(uint32 limit) { m_playerLimit = limit; }
        uint32 GetPlayerAmountLimit() const { return m_playerLimit; }

        //player Queue
        typedef std::list<WorldSession*> Queue;
        void AddQueuedPlayer(WorldSession*);
        bool RemoveQueuedPlayer(WorldSession* session);
        int32 GetQueuePos(WorldSession*);
        bool HasRecentlyDisconnected(WorldSession*);

        /// @todo Actions on m_allowMovement still to be implemented
        /// Is movement allowed?
        bool getAllowMovement() const { return m_allowMovement; }
        /// Allow/Disallow object movements
        void SetAllowMovement(bool allow) { m_allowMovement = allow; }

        /// Set a new Message of the Day
        void SetMotd(std::string motd);
        /// Get the current Message of the Day
        std::vector<std::string> const& GetMotd() const;

        /// Set the string for new characters (first login)
        void SetNewCharString(std::string const& str) { m_newCharString = str; }
        /// Get the string for new characters (first login)
        std::string const& GetNewCharString() const { return m_newCharString; }

        LocaleConstant GetDefaultDbcLocale() const { return m_defaultDbcLocale; }

        /// Get the path where data (dbc, maps) are stored on disk
        std::string const& GetDataPath() const { return m_dataPath; }

        /// Next daily quests and random bg reset time
        time_t GetNextDailyQuestsResetTime() const { return m_NextDailyQuestReset; }
        time_t GetNextWeeklyQuestsResetTime() const { return m_NextWeeklyQuestReset; }
        time_t GetNextRandomBGResetTime() const { return m_NextRandomBGReset; }

        /// Get the maximum skill level a player can reach
        uint16 GetConfigMaxSkillValue() const
        {
            uint8 lvl = uint8(getIntConfig(CONFIG_MAX_PLAYER_LEVEL));
            return lvl > 60 ? 300 + ((lvl - 60) * 75) / 10 : lvl * 5;
        }

        bool SetInitialWorldSettings();
        void LoadConfigSettings(bool reload = false);

        void SendWorldText(uint32 string_id, ...);
        void SendGlobalText(char const* text, WorldSession* self);
        void SendGMText(uint32 string_id, ...);
        void SendServerMessage(ServerMessageType messageID, std::string_view stringParam = {}, Player const* player = nullptr);
        void SendGlobalMessage(WorldPacket const* packet, WorldSession* self = nullptr, Optional<Team> team = { });
        void SendGlobalGMMessage(WorldPacket const* packet, WorldSession* self = nullptr, Optional<Team> team = { });
        bool SendZoneMessage(uint32 zone, WorldPacket const* packet, WorldSession* self = nullptr, Optional<Team> team = { });
        void SendZoneText(uint32 zone, const char *text, WorldSession* self = nullptr, Optional<Team> team = { });

        /// Are we in the middle of a shutdown?
        bool IsShuttingDown() const { return m_ShutdownTimer > 0; }
        uint32 GetShutDownTimeLeft() const { return m_ShutdownTimer; }
        void ShutdownServ(uint32 time, uint32 options, uint8 exitcode, const std::string& reason = std::string());
        uint32 ShutdownCancel();
        void ShutdownMsg(bool show = false, Player* player = nullptr, const std::string& reason = std::string());
        static uint8 GetExitCode() { return m_ExitCode; }
        static void StopNow(uint8 exitcode) { m_stopEvent = true; m_ExitCode = exitcode; }
        static bool IsStopped() { return m_stopEvent; }

        void Update(uint32 diff);

        void UpdateSessions(uint32 diff);
        /// Set a server rate (see #Rates)
        void setRate(Rates rate, float value) { rate_values[rate]=value; }
        /// Get a server rate (see #Rates)
        float getRate(Rates rate) const { return rate_values[rate]; }

        /// Set a server configuration element (see #WorldConfigs)
        void setBoolConfig(WorldBoolConfigs index, bool value)
        {
            if (index < BOOL_CONFIG_VALUE_COUNT)
                m_bool_configs[index] = value;
        }

        /// Get a server configuration element (see #WorldConfigs)
        bool getBoolConfig(WorldBoolConfigs index) const
        {
            return index < BOOL_CONFIG_VALUE_COUNT ? m_bool_configs[index] : 0;
        }

        /// Set a server configuration element (see #WorldConfigs)
        void setFloatConfig(WorldFloatConfigs index, float value)
        {
            if (index < FLOAT_CONFIG_VALUE_COUNT)
                m_float_configs[index] = value;
        }

        /// Get a server configuration element (see #WorldConfigs)
        float getFloatConfig(WorldFloatConfigs index) const
        {
            return index < FLOAT_CONFIG_VALUE_COUNT ? m_float_configs[index] : 0;
        }

        /// Set a server configuration element (see #WorldConfigs)
        void setIntConfig(WorldIntConfigs index, uint32 value)
        {
            if (index < INT_CONFIG_VALUE_COUNT)
                m_int_configs[index] = value;
        }

        /// Get a server configuration element (see #WorldConfigs)
        uint32 getIntConfig(WorldIntConfigs index) const
        {
            return index < INT_CONFIG_VALUE_COUNT ? m_int_configs[index] : 0;
        }

        uint64 GetUInt64Config(WorldInt64Configs index) const
        {
            return index < INT64_CONFIT_VALUE_COUNT ? m_int64_configs[index] : 0;
        }

        static PersistentWorldVariable const NextCurrencyResetTimeVarId;                    // Next arena distribution time
        static PersistentWorldVariable const NextWeeklyQuestResetTimeVarId;                 // Next weekly quest reset time
        static PersistentWorldVariable const NextBGRandomDailyResetTimeVarId;               // Next daily BG reset time
        static PersistentWorldVariable const CharacterDatabaseCleaningFlagsVarId;           // Cleaning Flags
        static PersistentWorldVariable const NextGuildDailyResetTimeVarId;                  // Next guild cap reset time
        static PersistentWorldVariable const NextMonthlyQuestResetTimeVarId;                // Next monthly quest reset time
        static PersistentWorldVariable const NextDailyQuestResetTimeVarId;                  // Next daily quest reset time
        static PersistentWorldVariable const NextOldCalendarEventDeletionTimeVarId;         // Next daily calendar deletions of old events time
        static PersistentWorldVariable const NextGuildWeeklyResetTimeVarId;                 // Next guild week reset time

        int32 GetPersistentWorldVariable(PersistentWorldVariable const& var) const;
        void SetPersistentWorldVariable(PersistentWorldVariable const& var, int32 value);
        void LoadPersistentWorldVariables();

        /// Are we on a "Player versus Player" server?
        bool IsPvPRealm() const;
        bool IsFFAPvPRealm() const;

        void KickAll();
        void KickAllLess(AccountTypes sec);
        BanReturn BanAccount(BanMode mode, std::string const& nameOrIP, std::string const& duration, std::string const& reason, std::string const& author);
        BanReturn BanAccount(BanMode mode, std::string const& nameOrIP, uint32 duration_secs, std::string const& reason, std::string const& author);
        bool RemoveBanAccount(BanMode mode, std::string const& nameOrIP);
        BanReturn BanCharacter(std::string const& name, std::string const& duration, std::string const& reason, std::string const& author);
        bool RemoveBanCharacter(std::string const& name);

        // for max speed access
        static float GetMaxVisibleDistanceOnContinents()    { return m_MaxVisibleDistanceOnContinents; }
        static float GetMaxVisibleDistanceInInstances()     { return m_MaxVisibleDistanceInInstances;  }
        static float GetMaxVisibleDistanceInBG()            { return m_MaxVisibleDistanceInBG;         }
        static float GetMaxVisibleDistanceInArenas()        { return m_MaxVisibleDistanceInArenas;     }

        static int32 GetVisibilityNotifyPeriodOnContinents(){ return m_visibility_notify_periodOnContinents; }
        static int32 GetVisibilityNotifyPeriodInInstances() { return m_visibility_notify_periodInInstances;  }
        static int32 GetVisibilityNotifyPeriodInBG()        { return m_visibility_notify_periodInBG;         }
        static int32 GetVisibilityNotifyPeriodInArenas()    { return m_visibility_notify_periodInArenas;     }

        void ProcessCliCommands();
        void QueueCliCommand(CliCommandHolder* commandHolder) { cliCmdQueue.add(commandHolder); }

        void ForceGameEventUpdate();

        void UpdateRealmCharCount(uint32 accountId);

        LocaleConstant GetAvailableDbcLocale(LocaleConstant locale) const { if (m_availableDbcLocaleMask & (1 << locale)) return locale; else return m_defaultDbcLocale; }

        // used World DB version
        void LoadDBVersion();
        char const* GetDBVersion() const { return m_DBVersion.c_str(); }

        void LoadAutobroadcasts();

        void UpdateAreaDependentAuras();

        bool IsBattlePetJournalLockAcquired(ObjectGuid battlenetAccountGuid);

        uint32 GetCleaningFlags() const { return m_CleaningFlags; }
        void SetCleaningFlags(uint32 flags) { m_CleaningFlags = flags; }
        void ResetEventSeasonalQuests(uint16 event_id, time_t eventStartTime);

        void ReloadRBAC();

        void RemoveOldCorpses();
        void TriggerGuidWarning();
        void TriggerGuidAlert();
        bool IsGuidWarning() { return _guidWarn; }
        bool IsGuidAlert() { return _guidAlert; }

        // War mode balancing
        void SetForcedWarModeFactionBalanceState(TeamId team, int32 reward = 0);
        void DisableForcedWarModeFactionBalanceState();

    protected:
        void _UpdateGameTime();

        // callback for UpdateRealmCharacters
        void _UpdateRealmCharCount(PreparedQueryResult resultCharCount);

        void InitQuestResetTimes();
        void CheckScheduledResetTimes();
        void InitCurrencyResetTime();
        void DailyReset();
        void ResetWeeklyQuests();
        void ResetMonthlyQuests();

        void InitRandomBGResetTime();
        void InitCalendarOldEventsDeletionTime();
        void InitGuildResetTime();
        void ResetRandomBG();
        void CalendarDeleteOldEvents();
        void ResetGuildCap();
        void ResetCurrencyWeekCap();
    private:
        World();
        ~World();

        static std::atomic<bool> m_stopEvent;
        static uint8 m_ExitCode;
        uint32 m_ShutdownTimer;
        uint32 m_ShutdownMask;

        uint32 m_CleaningFlags;

        bool m_isClosed;

        IntervalTimer m_timers[WUPDATE_COUNT];
        time_t mail_timer;
        time_t mail_timer_expires;
        time_t blackmarket_timer;

        SessionMap m_sessions;
        std::unordered_multimap<ObjectGuid, WorldSession*> m_sessionsByBnetGuid;
        typedef std::unordered_map<uint32, time_t> DisconnectMap;
        DisconnectMap m_disconnects;
        uint32 m_maxActiveSessionCount;
        uint32 m_maxQueuedSessionCount;
        uint32 m_PlayerCount;
        uint32 m_MaxPlayerCount;

        std::string m_newCharString;

        float rate_values[MAX_RATES];
        uint32 m_int_configs[INT_CONFIG_VALUE_COUNT];
        uint64 m_int64_configs[INT64_CONFIT_VALUE_COUNT];
        bool m_bool_configs[BOOL_CONFIG_VALUE_COUNT];
        float m_float_configs[FLOAT_CONFIG_VALUE_COUNT];
        std::unordered_map<std::string, int32> m_worldVariables;
        uint32 m_playerLimit;
        AccountTypes m_allowedSecurityLevel;
        LocaleConstant m_defaultDbcLocale;                     // from config for one from loaded DBC locales
        uint32 m_availableDbcLocaleMask;                       // by loaded DBC
        bool m_allowMovement;
        std::vector<std::string> _motd;
        std::string m_dataPath;

        // for max speed access
        static float m_MaxVisibleDistanceOnContinents;
        static float m_MaxVisibleDistanceInInstances;
        static float m_MaxVisibleDistanceInBG;
        static float m_MaxVisibleDistanceInArenas;

        static int32 m_visibility_notify_periodOnContinents;
        static int32 m_visibility_notify_periodInInstances;
        static int32 m_visibility_notify_periodInBG;
        static int32 m_visibility_notify_periodInArenas;

        // CLI command holder to be thread safe
        LockedQueue<CliCommandHolder*> cliCmdQueue;

        // scheduled reset times
        time_t m_NextDailyQuestReset;
        time_t m_NextWeeklyQuestReset;
        time_t m_NextMonthlyQuestReset;
        time_t m_NextRandomBGReset;
        time_t m_NextCalendarOldEventsDeletionTime;
        time_t m_NextGuildReset;
        time_t m_NextCurrencyReset;

        //Player Queue
        Queue m_QueuedPlayer;

        // sessions that are added async
        void AddSession_(WorldSession* s);
        LockedQueue<WorldSession*> addSessQueue;

        void ProcessLinkInstanceSocket(std::pair<std::weak_ptr<WorldSocket>, uint64> linkInfo);
        LockedQueue<std::pair<std::weak_ptr<WorldSocket>, uint64>> _linkSocketQueue;

        // used versions
        std::string m_DBVersion;

        struct Autobroadcast
        {
            std::string Message;
            uint8 Weight;
        };
        typedef std::unordered_map<uint8, Autobroadcast> AutobroadcastContainer;
        AutobroadcastContainer m_Autobroadcasts;

        void ProcessQueryCallbacks();

        void SendGuidWarning();
        void DoGuidWarningRestart();
        void DoGuidAlertRestart();
        QueryCallbackProcessor _queryProcessor;

        std::string _guidWarningMsg;
        std::string _alertRestartReason;

        std::mutex _guidAlertLock;

        bool _guidWarn;
        bool _guidAlert;
        uint32 _warnDiff;
        time_t _warnShutdownTime;

        // War mode balancing
        void UpdateWarModeRewardValues();

    friend class debug_commandscript;
};

TC_GAME_API uint32 GetVirtualRealmAddress();

#define sWorld World::instance()

#endif
/// @}
