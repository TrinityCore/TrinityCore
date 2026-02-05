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

/** \file
    \ingroup world
*/

#include "World.h"
#include "AccountMgr.h"
#include "AchievementMgr.h"
#include "AreaTriggerDataStore.h"
#include "ArenaTeamMgr.h"
#include "AuctionHouseBot.h"
#include "AuctionHouseMgr.h"
#include "AuthenticationPackets.h"
#include "BattlePetMgr.h"
#include "BattlefieldMgr.h"
#include "BattlegroundMgr.h"
#include "BattlenetRpcErrorCodes.h"
#include "BlackMarketMgr.h"
#include "CalendarMgr.h"
#include "ChannelMgr.h"
#include "CharacterCache.h"
#include "CharacterDatabaseCleaner.h"
#include "CharacterTemplateDataStore.h"
#include "Chat.h"
#include "ChatCommand.h"
#include "ChatPackets.h"
#include "Config.h"
#include "Containers.h"
#include "ConversationDataStore.h"
#include "CreatureAIRegistry.h"
#include "CreatureGroups.h"
#include "CreatureTextMgr.h"
#include "DB2Stores.h"
#include "DatabaseEnv.h"
#include "DetourMemoryFunctions.h"
#include "DisableMgr.h"
#include "GameEventMgr.h"
#include "GameObjectModel.h"
#include "GameTables.h"
#include "GameTime.h"
#include "GarrisonMgr.h"
#include "GitRevision.h"
#include "GridNotifiersImpl.h"
#include "GroupMgr.h"
#include "GuildMgr.h"
#include "IPLocation.h"
#include "InstanceLockMgr.h"
#include "ItemBonusMgr.h"
#include "LFGMgr.h"
#include "Language.h"
#include "LanguageMgr.h"
#include "Log.h"
#include "LootItemStorage.h"
#include "LootMgr.h"
#include "M2Stores.h"
#include "MMapManager.h"
#include "Map.h"
#include "MapManager.h"
#include "MapUtils.h"
#include "Metric.h"
#include "MiscPackets.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "OutdoorPvPMgr.h"
#include "PetitionMgr.h"
#include "Player.h"
#include "PlayerDump.h"
#include "PoolMgr.h"
#include "QuestPools.h"
#include "RealmList.h"
#include "ScenarioMgr.h"
#include "ScriptMgr.h"
#include "ScriptReloadMgr.h"
#include "SkillDiscovery.h"
#include "SkillExtraItems.h"
#include "SmartScriptMgr.h"
#include "SpellMgr.h"
#include "SupportMgr.h"
#include "TaxiPathGraph.h"
#include "TerrainMgr.h"
#include "TraitMgr.h"
#include "TransportMgr.h"
#include "Unit.h"
#include "UpdateTime.h"
#include "VMapFactory.h"
#include "VMapManager.h"
#include "WaypointManager.h"
#include "WeatherMgr.h"
#include "WhoListStorage.h"
#include "WorldSession.h"
#include "WorldStateMgr.h"
#include <zlib.h>

TC_GAME_API std::atomic<bool> World::m_stopEvent(false);
TC_GAME_API uint8 World::m_ExitCode = SHUTDOWN_EXIT_CODE;

TC_GAME_API std::atomic<uint32> World::m_worldLoopCounter(0);

struct PersistentWorldVariable
{
    std::string Id;
};

PersistentWorldVariable const World::NextCurrencyResetTimeVarId{ "NextCurrencyResetTime" };
PersistentWorldVariable const World::NextWeeklyQuestResetTimeVarId{ "NextWeeklyQuestResetTime" };
PersistentWorldVariable const World::NextBGRandomDailyResetTimeVarId{ "NextBGRandomDailyResetTime" };
PersistentWorldVariable const World::CharacterDatabaseCleaningFlagsVarId{ "PersistentCharacterCleanFlags" };
PersistentWorldVariable const World::NextGuildDailyResetTimeVarId{ "NextGuildDailyResetTime" };
PersistentWorldVariable const World::NextMonthlyQuestResetTimeVarId{ "NextMonthlyQuestResetTime" };
PersistentWorldVariable const World::NextDailyQuestResetTimeVarId{ "NextDailyQuestResetTime" };
PersistentWorldVariable const World::NextOldCalendarEventDeletionTimeVarId{ "NextOldCalendarEventDeletionTime" };
PersistentWorldVariable const World::NextGuildWeeklyResetTimeVarId{ "NextGuildWeeklyResetTime" };

/// World constructor
World::World()
{
    m_playerLimit = 0;
    m_allowedSecurityLevel = SEC_PLAYER;
    m_allowMovement = true;
    m_ShutdownMask = 0;
    m_ShutdownTimer = 0;

    m_maxActiveSessionCount = 0;
    m_maxQueuedSessionCount = 0;
    m_PlayerCount = 0;
    m_MaxPlayerCount = 0;
    m_NextDailyQuestReset = 0;
    m_NextWeeklyQuestReset = 0;
    m_NextMonthlyQuestReset = 0;
    m_NextRandomBGReset = 0;
    m_NextCalendarOldEventsDeletionTime = 0;
    m_NextGuildReset = 0;
    m_NextCurrencyReset = 0;

    m_defaultDbcLocale = LOCALE_enUS;
    m_availableDbcLocaleMask = 0;

    mail_timer = 0;
    mail_timer_expires = 0;
    blackmarket_timer = 0;

    m_isClosed = false;

    m_CleaningFlags = 0;

    memset(rate_values, 0, sizeof(rate_values));
    memset(m_int_configs, 0, sizeof(m_int_configs));
    memset(m_int64_configs, 0, sizeof(m_int64_configs));
    memset(m_bool_configs, 0, sizeof(m_bool_configs));
    memset(m_float_configs, 0, sizeof(m_float_configs));

    _guidWarn = false;
    _guidAlert = false;
    _warnDiff = 0;
    _warnShutdownTime = GameTime::GetGameTime();
}

/// World destructor
World::~World()
{
    ///- Empty the kicked session set
    while (!m_sessions.empty())
    {
        // not remove from queue, prevent loading new sessions
        delete m_sessions.begin()->second;
        m_sessions.erase(m_sessions.begin());
    }

    CliCommandHolder* command = nullptr;
    while (cliCmdQueue.next(command))
        delete command;

    VMAP::VMapFactory::clear();

    /// @todo free addSessQueue
}

World* World::instance()
{
    static World instance;
    return &instance;
}

/// Find a player in a specified zone
Player* World::FindPlayerInZone(uint32 zone)
{
    ///- circle through active sessions and return the first player found in the zone
    SessionMap::const_iterator itr;
    for (itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
    {
        if (!itr->second)
            continue;

        Player* player = itr->second->GetPlayer();
        if (!player)
            continue;

        if (player->IsInWorld() && player->GetZoneId() == zone)
            return player;
    }
    return nullptr;
}

bool World::IsClosed() const
{
    return m_isClosed;
}

void World::SetClosed(bool val)
{
    m_isClosed = val;

    // Invert the value, for simplicity for scripters.
    sScriptMgr->OnOpenStateChange(!val);
}

void World::LoadDBAllowedSecurityLevel()
{
    if (std::shared_ptr<Realm const> currentRealm = sRealmList->GetCurrentRealm())
        SetPlayerSecurityLimit(currentRealm->AllowedSecurityLevel);
}

void World::SetPlayerSecurityLimit(AccountTypes _sec)
{
    AccountTypes sec = _sec < SEC_CONSOLE ? _sec : SEC_PLAYER;
    bool update = sec > m_allowedSecurityLevel;
    m_allowedSecurityLevel = sec;
    if (update)
        KickAllLess(m_allowedSecurityLevel);
}

void World::SetMotd(std::string motd)
{
    /// we are using a string copy here to allow modifications in script hooks
    sScriptMgr->OnMotdChange(motd);

    _motd.clear();

    std::vector<std::string_view> tokens = Trinity::Tokenize(motd, '@', true);

    _motd.reserve(tokens.size());

    for (std::string_view const& token : tokens)
        _motd.emplace_back(token);
}

std::vector<std::string> const& World::GetMotd() const
{
    return _motd;
}

void World::TriggerGuidWarning()
{
    // Lock this only to prevent multiple maps triggering at the same time
    std::scoped_lock lock(_guidAlertLock);

    time_t gameTime = GameTime::GetGameTime();
    time_t today = (gameTime / DAY) * DAY;

    // Check if our window to restart today has passed. 5 mins until quiet time
    while (gameTime >= GetLocalHourTimestamp(today, getIntConfig(CONFIG_RESPAWN_RESTARTQUIETTIME)) - 1810)
        today += DAY;

    // Schedule restart for 30 minutes before quiet time, or as long as we have
    _warnShutdownTime = GetLocalHourTimestamp(today, getIntConfig(CONFIG_RESPAWN_RESTARTQUIETTIME)) - 1800;

    _guidWarn = true;
    SendGuidWarning();
}

void World::TriggerGuidAlert()
{
    // Lock this only to prevent multiple maps triggering at the same time
    std::scoped_lock lock(_guidAlertLock);

    DoGuidAlertRestart();
    _guidAlert = true;
    _guidWarn = false;
}

void World::DoGuidWarningRestart()
{
    if (m_ShutdownTimer)
        return;

    ShutdownServ(1800, SHUTDOWN_MASK_RESTART, RESTART_EXIT_CODE);
    _warnShutdownTime += HOUR;
}

void World::DoGuidAlertRestart()
{
    if (m_ShutdownTimer)
        return;

    ShutdownServ(300, SHUTDOWN_MASK_RESTART, RESTART_EXIT_CODE, _alertRestartReason);
}

void World::SendGuidWarning()
{
    if (!m_ShutdownTimer && _guidWarn && getIntConfig(CONFIG_RESPAWN_GUIDWARNING_FREQUENCY) > 0)
        SendServerMessage(SERVER_MSG_STRING, _guidWarningMsg.c_str());
    _warnDiff = 0;
}

/// Find a session by its id
WorldSession* World::FindSession(uint32 id) const
{
    SessionMap::const_iterator itr = m_sessions.find(id);

    if (itr != m_sessions.end())
        return itr->second;                                 // also can return nullptr for kicked session
    else
        return nullptr;
}

/// Remove a given session
bool World::RemoveSession(uint32 id)
{
    ///- Find the session, kick the user, but we can't delete session at this moment to prevent iterator invalidation
    SessionMap::const_iterator itr = m_sessions.find(id);

    if (itr != m_sessions.end() && itr->second)
    {
        if (itr->second->PlayerLoading())
            return false;

        itr->second->KickPlayer("World::RemoveSession");
    }

    return true;
}

void World::AddSession(WorldSession* s)
{
    addSessQueue.add(s);
}

void World::AddInstanceSocket(std::weak_ptr<WorldSocket> sock, uint64 connectToKey)
{
    _linkSocketQueue.add(std::make_pair(sock, connectToKey));
}

void World::AddSession_(WorldSession* s)
{
    ASSERT(s);

    //NOTE - Still there is race condition in WorldSession* being used in the Sockets

    ///- kick already loaded player with same account (if any) and remove session
    ///- if player is in loading and want to load again, return
    if (!RemoveSession(s->GetAccountId()))
    {
        s->KickPlayer("World::AddSession_ Couldn't remove the other session while on loading screen");
        delete s;                                           // session not added yet in session list, so not listed in queue
        return;
    }

    // decrease session counts only at not reconnection case
    bool decrease_session = true;

    // if session already exist, prepare to it deleting at next world update
    // NOTE - KickPlayer() should be called on "old" in RemoveSession()
    {
        SessionMap::const_iterator old = m_sessions.find(s->GetAccountId());

        if (old != m_sessions.end())
        {
            // prevent decrease sessions count if session queued
            if (RemoveQueuedPlayer(old->second))
                decrease_session = false;
            // not remove replaced session form queue if listed
            Trinity::Containers::MultimapErasePair(m_sessionsByBnetGuid, old->second->GetBattlenetAccountGUID(), old->second);
            delete old->second;
        }
    }

    m_sessions[s->GetAccountId()] = s;
    m_sessionsByBnetGuid.emplace(s->GetBattlenetAccountGUID(), s);

    uint32 Sessions = GetActiveAndQueuedSessionCount();
    uint32 pLimit = GetPlayerAmountLimit();
    uint32 QueueSize = GetQueuedSessionCount(); //number of players in the queue

    //so we don't count the user trying to
    //login as a session and queue the socket that we are using
    if (decrease_session)
        --Sessions;

    if (pLimit > 0 && Sessions >= pLimit && !s->HasPermission(rbac::RBAC_PERM_SKIP_QUEUE) && !HasRecentlyDisconnected(s))
    {
        AddQueuedPlayer(s);
        UpdateMaxSessionCounters();
        TC_LOG_INFO("misc", "PlayerQueue: Account id {} is in Queue Position ({}).", s->GetAccountId(), ++QueueSize);
        return;
    }

    s->InitializeSession();

    UpdateMaxSessionCounters();

    // Updates the population
    if (pLimit > 0)
    {
        float popu = (float)GetActiveSessionCount();              // updated number of users on the server
        popu /= pLimit;

        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_REALM_POPULATION);
        stmt->setFloat(0, popu);
        stmt->setUInt32(1, sRealmList->GetCurrentRealmId().Realm);
        LoginDatabase.Execute(stmt);

        TC_LOG_INFO("misc", "Server Population ({}).", popu);
    }
}

bool World::HasRecentlyDisconnected(WorldSession* session)
{
    if (!session)
        return false;

    if (uint32 tolerance = getIntConfig(CONFIG_INTERVAL_DISCONNECT_TOLERANCE))
    {
        for (DisconnectMap::iterator i = m_disconnects.begin(); i != m_disconnects.end();)
        {
            if (difftime(i->second, GameTime::GetGameTime()) < tolerance)
            {
                if (i->first == session->GetAccountId())
                    return true;
                ++i;
            }
            else
                m_disconnects.erase(i++);
        }
    }
    return false;
 }

int32 World::GetQueuePos(WorldSession* sess)
{
    uint32 position = 1;

    for (Queue::const_iterator iter = m_QueuedPlayer.begin(); iter != m_QueuedPlayer.end(); ++iter, ++position)
        if ((*iter) == sess)
            return position;

    return 0;
}

void World::AddQueuedPlayer(WorldSession* sess)
{
    sess->SetInQueue(true);
    m_QueuedPlayer.push_back(sess);

    // The 1st SMSG_AUTH_RESPONSE needs to contain other info too.
    sess->SendAuthResponse(ERROR_OK, true, GetQueuePos(sess));
}

bool World::RemoveQueuedPlayer(WorldSession* sess)
{
    // sessions count including queued to remove (if removed_session set)
    uint32 sessions = GetActiveSessionCount();

    uint32 position = 1;
    Queue::iterator iter = m_QueuedPlayer.begin();

    // search to remove and count skipped positions
    bool found = false;

    for (; iter != m_QueuedPlayer.end(); ++iter, ++position)
    {
        if (*iter == sess)
        {
            sess->SetInQueue(false);
            sess->ResetTimeOutTime(false);
            iter = m_QueuedPlayer.erase(iter);
            found = true;                                   // removing queued session
            break;
        }
    }

    // iter point to next socked after removed or end()
    // position store position of removed socket and then new position next socket after removed

    // if session not queued then we need decrease sessions count
    if (!found && sessions)
        --sessions;

    // accept first in queue
    if ((!m_playerLimit || sessions < m_playerLimit) && !m_QueuedPlayer.empty())
    {
        WorldSession* pop_sess = m_QueuedPlayer.front();
        pop_sess->InitializeSession();
        m_QueuedPlayer.pop_front();

        // update iter to point first queued socket or end() if queue is empty now
        iter = m_QueuedPlayer.begin();
        position = 1;
    }

    // update position from iter to end()
    // iter point to first not updated socket, position store new position
    for (; iter != m_QueuedPlayer.end(); ++iter, ++position)
        (*iter)->SendAuthWaitQueue(position);

    return found;
}

template <typename T, typename IndexType>
struct ConfigOptionLoadDefinition
{
    std::string_view Name;
    T DefaultValue = { };
    IndexType Index = { };
    Optional<T> Min, Max;
    bool Reloadable = true;
};

template <typename T, auto Max>
using ConfigOptionLoadDefinitionArray = std::array<ConfigOptionLoadDefinition<T, decltype(Max)>, Max>;

template <typename T, typename IndexType>
static void StoreConfigValue(T& oldValue, std::type_identity_t<T> value, ConfigOptionLoadDefinition<T, IndexType> const& definition, bool reload)
{
    if constexpr (!std::is_same_v<T, bool>)
    {
        if (definition.Min && value < *definition.Min)
        {
            TC_LOG_ERROR("server.loading", "{} {} must be >= {}. Using {} instead.", definition.Name, value, *definition.Min, *definition.Min);
            value = *definition.Min;
        }
        if (definition.Max && value > *definition.Max)
        {
            TC_LOG_ERROR("server.loading", "{} {} must be <= {}. Using {} instead.", definition.Name, value, *definition.Max, *definition.Max);
            value = *definition.Max;
        }
    }
    if (reload && !definition.Reloadable)
    {
        if (value != oldValue)
            TC_LOG_ERROR("server.loading", "{} option can't be changed at worldserver.conf reload, using current value ({}).", definition.Name, oldValue);
        return;
    }
    oldValue = value;
}

/// Initialize config values
void World::LoadConfigSettings(bool reload)
{
    if (reload)
    {
        std::vector<std::string> configErrors;
        if (!sConfigMgr->Reload(configErrors))
        {
            for (std::string const& configError : configErrors)
                TC_LOG_ERROR("misc", "World settings reload fail: {}.", configError);

            return;
        }
        sLog->LoadFromConfig();
        sMetric->LoadFromConfigs();
    }

    m_defaultDbcLocale = LocaleConstant(sConfigMgr->GetIntDefault("DBC.Locale"sv, 0));

    if (m_defaultDbcLocale >= TOTAL_LOCALES || m_defaultDbcLocale == LOCALE_none)
    {
        TC_LOG_ERROR("server.loading", "Incorrect DBC.Locale! Must be >= 0 and < {} and not {} (set to 0)", TOTAL_LOCALES, LOCALE_none);
        m_defaultDbcLocale = LOCALE_enUS;
    }

    TC_LOG_INFO("server.loading", "Using {} DBC Locale", localeNames[m_defaultDbcLocale]);

    ///- Read the player limit and the Message of the day from the config file
    SetPlayerAmountLimit(sConfigMgr->GetIntDefault("PlayerLimit"sv, 100));
    SetMotd(sConfigMgr->GetStringDefault("Motd"sv, "Welcome to a Trinity Core Server."sv));

    uint32 databaseCacheVersion = m_int_configs[CONFIG_CLIENTCACHE_VERSION];

    static constexpr ConfigOptionLoadDefinitionArray<bool, BOOL_CONFIG_VALUE_COUNT> bools =
    { {
        { .Name = "Support.Enabled"sv, .DefaultValue = true, .Index = CONFIG_SUPPORT_ENABLED },
        { .Name = "Support.TicketsEnabled"sv, .DefaultValue = false, .Index = CONFIG_SUPPORT_TICKETS_ENABLED },
        { .Name = "Support.BugsEnabled"sv, .DefaultValue = false, .Index = CONFIG_SUPPORT_BUGS_ENABLED },
        { .Name = "Support.ComplaintsEnabled"sv, .DefaultValue = false, .Index = CONFIG_SUPPORT_COMPLAINTS_ENABLED },
        { .Name = "Support.SuggestionsEnabled"sv, .DefaultValue = false, .Index = CONFIG_SUPPORT_SUGGESTIONS_ENABLED },
        { .Name = "DurabilityLoss.InPvP"sv, .DefaultValue = false, .Index = CONFIG_DURABILITY_LOSS_IN_PVP },
        { .Name = "AddonChannel"sv, .DefaultValue = true, .Index = CONFIG_ADDON_CHANNEL },
        { .Name = "CleanCharacterDB"sv, .DefaultValue = false, .Index = CONFIG_CLEAN_CHARACTER_DB },
        { .Name = "PreserveCustomChannels"sv, .DefaultValue = false, .Index = CONFIG_PRESERVE_CUSTOM_CHANNELS },
        { .Name = "GridUnload"sv, .DefaultValue = true, .Index = CONFIG_GRID_UNLOAD },
        { .Name = "BaseMapLoadAllGrids"sv, .DefaultValue = false, .Index = CONFIG_BASEMAP_LOAD_GRIDS },
        { .Name = "InstanceMapLoadAllGrids"sv, .DefaultValue = false, .Index = CONFIG_INSTANCEMAP_LOAD_GRIDS },
        { .Name = "BattlegroundMapLoadAllGrids"sv, .DefaultValue = true, .Index = CONFIG_BATTLEGROUNDMAP_LOAD_GRIDS },
        { .Name = "PlayerSave.Stats.SaveOnlyOnLogout"sv, .DefaultValue = true, .Index = CONFIG_STATS_SAVE_ONLY_ON_LOGOUT },
        { .Name = "Creature.RegenHPCannotReachTargetInRaid"sv, .DefaultValue = true, .Index = CONFIG_REGEN_HP_CANNOT_REACH_TARGET_IN_RAID },
        { .Name = "AllowTwoSide.Interaction.Calendar"sv, .DefaultValue = false, .Index = CONFIG_ALLOW_TWO_SIDE_INTERACTION_CALENDAR },
        { .Name = "AllowTwoSide.Interaction.Channel"sv, .DefaultValue = false, .Index = CONFIG_ALLOW_TWO_SIDE_INTERACTION_CHANNEL },
        { .Name = "AllowTwoSide.Interaction.Group"sv, .DefaultValue = false, .Index = CONFIG_ALLOW_TWO_SIDE_INTERACTION_GROUP },
        { .Name = "AllowTwoSide.Interaction.Guild"sv, .DefaultValue = false, .Index = CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD },
        { .Name = "AllowTwoSide.Interaction.Auction"sv, .DefaultValue = true, .Index = CONFIG_ALLOW_TWO_SIDE_INTERACTION_AUCTION },
        { .Name = "AllowTwoSide.Trade"sv, .DefaultValue = false, .Index = CONFIG_ALLOW_TWO_SIDE_TRADE },
        { .Name = "CharacterCreating.DisableAlliedRaceAchievementRequirement"sv, .DefaultValue = false, .Index = CONFIG_CHARACTER_CREATING_DISABLE_ALLIED_RACE_ACHIEVEMENT_REQUIREMENT },
        { .Name = "AllFlightPaths"sv, .DefaultValue = false, .Index = CONFIG_ALL_TAXI_PATHS },
        { .Name = "InstantFlightPaths"sv, .DefaultValue = false, .Index = CONFIG_INSTANT_TAXI },
        { .Name = "Instance.IgnoreLevel"sv, .DefaultValue = false, .Index = CONFIG_INSTANCE_IGNORE_LEVEL },
        { .Name = "Instance.IgnoreRaid"sv, .DefaultValue = false, .Index = CONFIG_INSTANCE_IGNORE_RAID },
        { .Name = "CastUnstuck"sv, .DefaultValue = true, .Index = CONFIG_CAST_UNSTUCK },
        { .Name = "GM.AllowInvite"sv, .DefaultValue = false, .Index = CONFIG_ALLOW_GM_GROUP },
        { .Name = "GM.LowerSecurity"sv, .DefaultValue = false, .Index = CONFIG_GM_LOWER_SECURITY },
        { .Name = "SkillChance.Prospecting"sv, .DefaultValue = false, .Index = CONFIG_SKILL_PROSPECTING },
        { .Name = "SkillChance.Milling"sv, .DefaultValue = false, .Index = CONFIG_SKILL_MILLING },
        { .Name = "ActivateWeather"sv, .DefaultValue = true, .Index = CONFIG_WEATHER },
        { .Name = "Event.Announce"sv, .DefaultValue = false, .Index = CONFIG_EVENT_ANNOUNCE },
        { .Name = "Quests.EnableQuestTracker"sv, .DefaultValue = false, .Index = CONFIG_QUEST_ENABLE_QUEST_TRACKER },
        { .Name = "Quests.IgnoreRaid"sv, .DefaultValue = false, .Index = CONFIG_QUEST_IGNORE_RAID },
        { .Name = "Quests.IgnoreAutoAccept"sv, .DefaultValue = false, .Index = CONFIG_QUEST_IGNORE_AUTO_ACCEPT },
        { .Name = "Quests.IgnoreAutoComplete"sv, .DefaultValue = false, .Index = CONFIG_QUEST_IGNORE_AUTO_COMPLETE },
        { .Name = "DetectPosCollision"sv, .DefaultValue = true, .Index = CONFIG_DETECT_POS_COLLISION },
        { .Name = "Channel.RestrictedLfg"sv, .DefaultValue = true, .Index = CONFIG_RESTRICTED_LFG_CHANNEL },
        { .Name = "ChatFakeMessagePreventing"sv, .DefaultValue = false, .Index = CONFIG_CHAT_FAKE_MESSAGE_PREVENTING },
        { .Name = "Death.CorpseReclaimDelay.PvP"sv, .DefaultValue = true, .Index = CONFIG_DEATH_CORPSE_RECLAIM_DELAY_PVP },
        { .Name = "Death.CorpseReclaimDelay.PvE"sv, .DefaultValue = true, .Index = CONFIG_DEATH_CORPSE_RECLAIM_DELAY_PVE },
        { .Name = "Death.Bones.World"sv, .DefaultValue = true, .Index = CONFIG_DEATH_BONES_WORLD },
        { .Name = "Death.Bones.BattlegroundOrArena"sv, .DefaultValue = true, .Index = CONFIG_DEATH_BONES_BG_OR_ARENA },
        { .Name = "Die.Command.Mode"sv, .DefaultValue = true, .Index = CONFIG_DIE_COMMAND_MODE },
        { .Name = "DeclinedNames"sv, .DefaultValue = false, .Index = CONFIG_DECLINED_NAMES_USED },
        { .Name = "Battleground.CastDeserter"sv, .DefaultValue = true, .Index = CONFIG_BATTLEGROUND_CAST_DESERTER },
        { .Name = "Battleground.QueueAnnouncer.Enable"sv, .DefaultValue = false, .Index = CONFIG_BATTLEGROUND_QUEUE_ANNOUNCER_ENABLE },
        { .Name = "Battleground.QueueAnnouncer.PlayerOnly"sv, .DefaultValue = false, .Index = CONFIG_BATTLEGROUND_QUEUE_ANNOUNCER_PLAYERONLY },
        { .Name = "Battleground.StoreStatistics.Enable"sv, .DefaultValue = false, .Index = CONFIG_BATTLEGROUND_STORE_STATISTICS_ENABLE },
        { .Name = "Battleground.GiveXPForKills"sv, .DefaultValue = false, .Index = CONFIG_BG_XP_FOR_KILL },
        { .Name = "Arena.QueueAnnouncer.Enable"sv, .DefaultValue = false, .Index = CONFIG_ARENA_QUEUE_ANNOUNCER_ENABLE },
        { .Name = "Arena.ArenaSeason.InProgress"sv, .DefaultValue = false, .Index = CONFIG_ARENA_SEASON_IN_PROGRESS },
        { .Name = "ArenaLog.ExtendedInfo"sv, .DefaultValue = false, .Index = CONFIG_ARENA_LOG_EXTENDED_INFO },
        { .Name = "OffhandCheckAtSpellUnlearn"sv, .DefaultValue = true, .Index = CONFIG_OFFHAND_CHECK_AT_SPELL_UNLEARN },
        { .Name = "Respawn.DynamicEscortNPC"sv, .DefaultValue = false, .Index = CONFIG_RESPAWN_DYNAMIC_ESCORTNPC },
        { .Name = "mmap.enablePathFinding"sv, .DefaultValue = true, .Index = CONFIG_ENABLE_MMAPS },
        { .Name = "vmap.enableIndoorCheck"sv, .DefaultValue = true, .Index = CONFIG_VMAP_INDOOR_CHECK },
        { .Name = "PlayerStart.AllSpells"sv, .DefaultValue = false, .Index = CONFIG_START_ALL_SPELLS },
        { .Name = "ResetDuelCooldowns"sv, .DefaultValue = false, .Index = CONFIG_RESET_DUEL_COOLDOWNS },
        { .Name = "ResetDuelHealthMana"sv, .DefaultValue = false, .Index = CONFIG_RESET_DUEL_HEALTH_MANA },
        { .Name = "PlayerStart.MapsExplored"sv, .DefaultValue = false, .Index = CONFIG_START_ALL_EXPLORED },
        { .Name = "PlayerStart.AllReputation"sv, .DefaultValue = false, .Index = CONFIG_START_ALL_REP },
        { .Name = "PvPToken.Enable"sv, .DefaultValue = false, .Index = CONFIG_PVP_TOKEN_ENABLE },
        { .Name = "NoResetTalentsCost"sv, .DefaultValue = false, .Index = CONFIG_NO_RESET_TALENT_COST },
        { .Name = "ShowKickInWorld"sv, .DefaultValue = false, .Index = CONFIG_SHOW_KICK_IN_WORLD },
        { .Name = "ShowMuteInWorld"sv, .DefaultValue = false, .Index = CONFIG_SHOW_MUTE_IN_WORLD },
        { .Name = "ShowBanInWorld"sv, .DefaultValue = false, .Index = CONFIG_SHOW_BAN_IN_WORLD },
        { .Name = "FeatureSystem.CharacterUndelete.Enabled"sv, .DefaultValue = false, .Index = CONFIG_FEATURE_SYSTEM_CHARACTER_UNDELETE_ENABLED },
        { .Name = "DBC.EnforceItemAttributes"sv, .DefaultValue = true, .Index = CONFIG_DBC_ENFORCE_ITEM_ATTRIBUTES },
        { .Name = "InstancesResetAnnounce"sv, .DefaultValue = false, .Index = CONFIG_INSTANCES_RESET_ANNOUNCE },
        { .Name = "AutoBroadcast.On"sv, .DefaultValue = false, .Index = CONFIG_AUTOBROADCAST },
        { .Name = "PlayerDump.DisallowPaths"sv, .DefaultValue = true, .Index = CONFIG_PDUMP_NO_PATHS },
        { .Name = "PlayerDump.DisallowOverwrite"sv, .DefaultValue = true, .Index = CONFIG_PDUMP_NO_OVERWRITE },
        { .Name = "Wintergrasp.Enable"sv, .DefaultValue = false, .Index = CONFIG_WINTERGRASP_ENABLE },
        { .Name = "TolBarad.Enable"sv, .DefaultValue = true, .Index = CONFIG_TOLBARAD_ENABLE },
        { .Name = "Stats.Limits.Enable"sv, .DefaultValue = false, .Index = CONFIG_STATS_LIMITS_ENABLE },
        { .Name = "Allow.IP.Based.Action.Logging"sv, .DefaultValue = false, .Index = CONFIG_IP_BASED_ACTION_LOGGING },
        { .Name = "Calculate.Creature.Zone.Area.Data"sv, .DefaultValue = false, .Index = CONFIG_CALCULATE_CREATURE_ZONE_AREA_DATA },
        { .Name = "Calculate.Gameoject.Zone.Area.Data"sv, .DefaultValue = false, .Index = CONFIG_CALCULATE_GAMEOBJECT_ZONE_AREA_DATA },
        { .Name = "BlackMarket.Enabled"sv, .DefaultValue = true, .Index = CONFIG_BLACKMARKET_ENABLED },
        { .Name = "HotSwap.Enabled"sv, .DefaultValue = true, .Index = CONFIG_HOTSWAP_ENABLED },
        { .Name = "HotSwap.EnableReCompiler"sv, .DefaultValue = true, .Index = CONFIG_HOTSWAP_RECOMPILER_ENABLED },
        { .Name = "HotSwap.EnableEarlyTermination"sv, .DefaultValue = true, .Index = CONFIG_HOTSWAP_EARLY_TERMINATION_ENABLED },
        { .Name = "HotSwap.EnableBuildFileRecreation"sv, .DefaultValue = true, .Index = CONFIG_HOTSWAP_BUILD_FILE_RECREATION_ENABLED },
        { .Name = "HotSwap.EnableInstall"sv, .DefaultValue = true, .Index = CONFIG_HOTSWAP_INSTALL_ENABLED },
        { .Name = "HotSwap.EnablePrefixCorrection"sv, .DefaultValue = true, .Index = CONFIG_HOTSWAP_PREFIX_CORRECTION_ENABLED },
        { .Name = "PreventRenameCharacterOnCustomization"sv, .DefaultValue = false, .Index = CONFIG_PREVENT_RENAME_CUSTOMIZATION },
        { .Name = "PartyRaidWarnings"sv, .DefaultValue = false, .Index = CONFIG_CHAT_PARTY_RAID_WARNINGS },
        { .Name = "CacheDataQueries"sv, .DefaultValue = true, .Index = CONFIG_CACHE_DATA_QUERIES },
        { .Name = "Creature.CheckInvalidPosition"sv, .DefaultValue = false, .Index = CONFIG_CREATURE_CHECK_INVALID_POSITION },
        { .Name = "GameObject.CheckInvalidPosition"sv, .DefaultValue = false, .Index = CONFIG_GAME_OBJECT_CHECK_INVALID_POSITION },
        { .Name = "CheckGameObjectLoS"sv, .DefaultValue = true, .Index = CONFIG_CHECK_GOBJECT_LOS },
        { .Name = "AllowLoggingIPAddressesInDatabase"sv, .DefaultValue = true, .Index = CONFIG_ALLOW_LOGGING_IP_ADDRESSES_IN_DATABASE },
        { .Name = "Loot.EnableAELoot"sv, .DefaultValue = true, .Index = CONFIG_ENABLE_AE_LOOT },
        { .Name = "Load.Locales"sv, .DefaultValue = true, .Index = CONFIG_LOAD_LOCALES },
    } };

    static constexpr ConfigOptionLoadDefinitionArray<uint32, INT_CONFIG_VALUE_COUNT> ints =
    { {
        { .Name = "Server.LoginInfo"sv, .DefaultValue = 0, .Index = CONFIG_ENABLE_SINFO_LOGIN },
        { .Name = "XP.Boost.Daymask"sv, .DefaultValue = 0, .Index = CONFIG_XP_BOOST_DAYMASK },
        { .Name = "Compression"sv, .DefaultValue = 1, .Index = CONFIG_COMPRESSION, .Min = Z_BEST_SPEED, .Max = Z_BEST_COMPRESSION },
        { .Name = "PersistentCharacterCleanFlags"sv, .DefaultValue = 0, .Index = CONFIG_PERSISTENT_CHARACTER_CLEAN_FLAGS },
        { .Name = "Auction.ReplicateItemsCooldown"sv, .DefaultValue = 900, .Index = CONFIG_AUCTION_REPLICATE_DELAY },
        { .Name = "Auction.SearchDelay"sv, .DefaultValue = 300, .Index = CONFIG_AUCTION_SEARCH_DELAY, .Min = 100, .Max = 10000 },
        { .Name = "Auction.TaintedSearchDelay"sv, .DefaultValue = 3000, .Index = CONFIG_AUCTION_TAINTED_SEARCH_DELAY, .Min = 100, .Max = 10000 },
        { .Name = "ChatLevelReq.Channel"sv, .DefaultValue = 1, .Index = CONFIG_CHAT_CHANNEL_LEVEL_REQ },
        { .Name = "ChatLevelReq.Whisper"sv, .DefaultValue = 1, .Index = CONFIG_CHAT_WHISPER_LEVEL_REQ },
        { .Name = "ChatLevelReq.Emote"sv, .DefaultValue = 1, .Index = CONFIG_CHAT_EMOTE_LEVEL_REQ },
        { .Name = "ChatLevelReq.Say"sv, .DefaultValue = 1, .Index = CONFIG_CHAT_SAY_LEVEL_REQ },
        { .Name = "ChatLevelReq.Yell"sv, .DefaultValue = 1, .Index = CONFIG_CHAT_YELL_LEVEL_REQ },
        { .Name = "PartyLevelReq"sv, .DefaultValue = 1, .Index = CONFIG_PARTY_LEVEL_REQ },
        { .Name = "LevelReq.Trade"sv, .DefaultValue = 1, .Index = CONFIG_TRADE_LEVEL_REQ },
        { .Name = "LevelReq.Auction"sv, .DefaultValue = 1, .Index = CONFIG_AUCTION_LEVEL_REQ },
        { .Name = "LevelReq.Mail"sv, .DefaultValue = 1, .Index = CONFIG_MAIL_LEVEL_REQ },
        { .Name = "PreserveCustomChannelDuration"sv, .DefaultValue = 14, .Index = CONFIG_PRESERVE_CUSTOM_CHANNEL_DURATION },
        { .Name = "PreserveCustomChannelInterval"sv, .DefaultValue = 5, .Index = CONFIG_PRESERVE_CUSTOM_CHANNEL_INTERVAL },
        { .Name = "PlayerSaveInterval"sv, .DefaultValue = 15 * MINUTE * IN_MILLISECONDS, .Index = CONFIG_INTERVAL_SAVE },
        { .Name = "DisconnectToleranceInterval"sv, .DefaultValue = 0, .Index = CONFIG_INTERVAL_DISCONNECT_TOLERANCE },
        { .Name = "PlayerSave.Stats.MinLevel"sv, .DefaultValue = 0, .Index = CONFIG_MIN_LEVEL_STAT_SAVE, .Max = STRONG_MAX_LEVEL },
        { .Name = "GridCleanUpDelay"sv, .DefaultValue = 5 * MINUTE * IN_MILLISECONDS, .Index = CONFIG_INTERVAL_GRIDCLEAN, .Min = MIN_GRID_DELAY },
        { .Name = "MapUpdateInterval"sv, .DefaultValue = 10, .Index = CONFIG_INTERVAL_MAPUPDATE, .Min = MIN_MAP_UPDATE_DELAY },
        { .Name = "ChangeWeatherInterval"sv, .DefaultValue = 10 * MINUTE * IN_MILLISECONDS, .Index = CONFIG_INTERVAL_CHANGEWEATHER },
        { .Name = "WorldServerPort"sv, .DefaultValue = 8085, .Index = CONFIG_PORT_WORLD, .Min = 1, .Max = std::numeric_limits<uint16>::max(), .Reloadable = false },
        { .Name = "SocketTimeOutTime"sv, .DefaultValue = 900000, .Index = CONFIG_SOCKET_TIMEOUTTIME },
        { .Name = "SocketTimeOutTimeActive"sv, .DefaultValue = 60000, .Index = CONFIG_SOCKET_TIMEOUTTIME_ACTIVE },
        { .Name = "SessionAddDelay"sv, .DefaultValue = 10000, .Index = CONFIG_SESSION_ADD_DELAY },
        { .Name = "MinQuestScaledXPRatio"sv, .DefaultValue = 0, .Index = CONFIG_MIN_QUEST_SCALED_XP_RATIO, .Max = 100 },
        { .Name = "MinCreatureScaledXPRatio"sv, .DefaultValue = 0, .Index = CONFIG_MIN_CREATURE_SCALED_XP_RATIO, .Max = 100 },
        { .Name = "MinDiscoveredScaledXPRatio"sv, .DefaultValue = 0, .Index = CONFIG_MIN_DISCOVERED_SCALED_XP_RATIO, .Max = 100 },
        { .Name = "GameType"sv, .DefaultValue = 0, .Index = CONFIG_GAME_TYPE, .Reloadable = false },
        { .Name = "RealmZone"sv, .DefaultValue = HARDCODED_DEVELOPMENT_REALM_CATEGORY_ID, .Index = CONFIG_REALM_ZONE, .Reloadable = false },
        { .Name = "StrictPlayerNames"sv, .DefaultValue = 0, .Index = CONFIG_STRICT_PLAYER_NAMES },
        { .Name = "StrictCharterNames"sv, .DefaultValue = 0, .Index = CONFIG_STRICT_CHARTER_NAMES },
        { .Name = "StrictPetNames"sv, .DefaultValue = 0, .Index = CONFIG_STRICT_PET_NAMES },
        { .Name = "MinPlayerName"sv, .DefaultValue = 2, .Index = CONFIG_MIN_PLAYER_NAME, .Min = 1, .Max = MAX_PLAYER_NAME },
        { .Name = "MinCharterName"sv, .DefaultValue = 2, .Index = CONFIG_MIN_CHARTER_NAME, .Min = 1, .Max = MAX_CHARTER_NAME },
        { .Name = "MinPetName"sv, .DefaultValue = 2, .Index = CONFIG_MIN_PET_NAME, .Min = 1, .Max = MAX_PET_NAME },
        { .Name = "Guild.CharterCost"sv, .DefaultValue = 1000, .Index = CONFIG_CHARTER_COST_GUILD },
        { .Name = "ArenaTeam.CharterCost.2v2"sv, .DefaultValue = 800000, .Index = CONFIG_CHARTER_COST_ARENA_2v2 },
        { .Name = "ArenaTeam.CharterCost.3v3"sv, .DefaultValue = 1200000, .Index = CONFIG_CHARTER_COST_ARENA_3v3 },
        { .Name = "ArenaTeam.CharterCost.5v5"sv, .DefaultValue = 2000000, .Index = CONFIG_CHARTER_COST_ARENA_5v5 },
        { .Name = "CharacterCreating.Disabled"sv, .DefaultValue = 0, .Index = CONFIG_CHARACTER_CREATING_DISABLED },
        { .Name = "CharacterCreating.Disabled.ClassMask"sv, .DefaultValue = 0, .Index = CONFIG_CHARACTER_CREATING_DISABLED_CLASSMASK },
        { .Name = "CharactersPerRealm"sv, .DefaultValue = 60, .Index = CONFIG_CHARACTERS_PER_REALM, .Min = 1, .Max = MAX_CHARACTERS_PER_REALM },
        { .Name = "CharactersPerAccount"sv, .DefaultValue = 60, .Index = CONFIG_CHARACTERS_PER_ACCOUNT, .Min = 1, .Max = MAX_CHARACTERS_PER_REALM },
        { .Name = "CharacterCreating.EvokersPerRealm"sv, .DefaultValue = 1, .Index = CONFIG_CHARACTER_CREATING_EVOKERS_PER_REALM, .Min = 1, .Max = MAX_CHARACTERS_PER_REALM },
        { .Name = "CharacterCreating.MinLevelForDemonHunter"sv, .DefaultValue = 0, .Index = CONFIG_CHARACTER_CREATING_MIN_LEVEL_FOR_DEMON_HUNTER },
        { .Name = "CharacterCreating.MinLevelForEvoker"sv, .DefaultValue = 50, .Index = CONFIG_CHARACTER_CREATING_MIN_LEVEL_FOR_EVOKER },
        { .Name = "SkipCinematics"sv, .DefaultValue = 0, .Index = CONFIG_SKIP_CINEMATICS, .Min = 0, .Max = 2 },
        { .Name = "MaxPlayerLevel"sv, .DefaultValue = DEFAULT_MAX_LEVEL, .Index = CONFIG_MAX_PLAYER_LEVEL, .Min = 1, .Max = MAX_LEVEL, .Reloadable = false },
        { .Name = "MinDualSpecLevel"sv, .DefaultValue = 40, .Index = CONFIG_MIN_DUALSPEC_LEVEL },
        { .Name = "StartPlayerLevel"sv, .DefaultValue = 1, .Index = CONFIG_START_PLAYER_LEVEL, .Min = 1 },
        { .Name = "StartDeathKnightPlayerLevel"sv, .DefaultValue = 8, .Index = CONFIG_START_DEATH_KNIGHT_PLAYER_LEVEL, .Min = 1 },
        { .Name = "StartDemonHunterPlayerLevel"sv, .DefaultValue = 8, .Index = CONFIG_START_DEMON_HUNTER_PLAYER_LEVEL, .Min = 1 },
        { .Name = "StartEvokerPlayerLevel"sv, .DefaultValue = 10, .Index = CONFIG_START_EVOKER_PLAYER_LEVEL, .Min = 1 },
        { .Name = "StartAlliedRacePlayerLevel"sv, .DefaultValue = 10, .Index = CONFIG_START_ALLIED_RACE_LEVEL, .Min = 1 },
        { .Name = "Currency.ResetHour"sv, .DefaultValue = 3, .Index = CONFIG_CURRENCY_RESET_HOUR, .Min = 0, .Max = 23 },
        { .Name = "Currency.ResetDay"sv, .DefaultValue = 3, .Index = CONFIG_CURRENCY_RESET_DAY, .Min = 0, .Max = 6 },
        { .Name = "Currency.ResetInterval"sv, .DefaultValue = 7, .Index = CONFIG_CURRENCY_RESET_INTERVAL, .Min = 1 },
        { .Name = "RecruitAFriend.MaxLevel"sv, .DefaultValue = DEFAULT_MAX_LEVEL, .Index = CONFIG_MAX_RECRUIT_A_FRIEND_BONUS_PLAYER_LEVEL, .Min = 1 },
        { .Name = "RecruitAFriend.MaxDifference"sv, .DefaultValue = 4, .Index = CONFIG_MAX_RECRUIT_A_FRIEND_BONUS_PLAYER_LEVEL_DIFFERENCE },
        { .Name = "ResetSchedule.WeekDay"sv, .DefaultValue = 2, .Index = CONFIG_RESET_SCHEDULE_WEEK_DAY, .Min = 0, .Max = 6 },
        { .Name = "ResetSchedule.Hour"sv, .DefaultValue = 8, .Index = CONFIG_RESET_SCHEDULE_HOUR, .Min = 0, .Max = 23 },
        { .Name = "Instance.UnloadDelay"sv, .DefaultValue = 30 * MINUTE * IN_MILLISECONDS, .Index = CONFIG_INSTANCE_UNLOAD_DELAY },
        { .Name = "Quests.DailyResetTime"sv, .DefaultValue = 3, .Index = CONFIG_DAILY_QUEST_RESET_TIME_HOUR, .Min = 0, .Max = 23 },
        { .Name = "Quests.WeeklyResetWDay"sv, .DefaultValue = 3, .Index = CONFIG_WEEKLY_QUEST_RESET_TIME_WDAY, .Min = 0, .Max = 6 },
        { .Name = "MaxPrimaryTradeSkill"sv, .DefaultValue = 2, .Index = CONFIG_MAX_PRIMARY_TRADE_SKILL },
        { .Name = "MinPetitionSigns"sv, .DefaultValue = 4, .Index = CONFIG_MIN_PETITION_SIGNS, .Max = 4 },
        { .Name = "GM.LoginState"sv, .DefaultValue = 2, .Index = CONFIG_GM_LOGIN_STATE },
        { .Name = "GM.Visible"sv, .DefaultValue = 2, .Index = CONFIG_GM_VISIBLE_STATE },
        { .Name = "GM.Chat"sv, .DefaultValue = 2, .Index = CONFIG_GM_CHAT },
        { .Name = "GM.WhisperingTo"sv, .DefaultValue = 2, .Index = CONFIG_GM_WHISPERING_TO },
        { .Name = "GM.FreezeAuraDuration"sv, .DefaultValue = 0, .Index = CONFIG_GM_FREEZE_DURATION },
        { .Name = "GM.InGMList.Level"sv, .DefaultValue = SEC_ADMINISTRATOR, .Index = CONFIG_GM_LEVEL_IN_GM_LIST },
        { .Name = "GM.InWhoList.Level"sv, .DefaultValue = SEC_ADMINISTRATOR, .Index = CONFIG_GM_LEVEL_IN_WHO_LIST },
        { .Name = "GM.StartLevel"sv, .DefaultValue = 1, .Index = CONFIG_START_GM_LEVEL, .Min = 1, .Max = MAX_LEVEL },
        { .Name = "GM.ForceShutdownThreshold"sv, .DefaultValue = 30, .Index = CONFIG_FORCE_SHUTDOWN_THRESHOLD },
        { .Name = "Visibility.GroupMode"sv, .DefaultValue = 1, .Index = CONFIG_GROUP_VISIBILITY, .Min = 0, .Max = 3 },
        { .Name = "MailDeliveryDelay"sv, .DefaultValue = HOUR, .Index = CONFIG_MAIL_DELIVERY_DELAY },
        { .Name = "CleanOldMailTime"sv, .DefaultValue = 4, .Index = CONFIG_CLEAN_OLD_MAIL_TIME, .Min = 0, .Max = 23 },
        { .Name = "UpdateUptimeInterval"sv, .DefaultValue = 10, .Index = CONFIG_UPTIME_UPDATE, .Min = 1 },
        { .Name = "LogDB.Opt.ClearInterval"sv, .DefaultValue = 10, .Index = CONFIG_LOGDB_CLEARINTERVAL, .Min = 1 },
        { .Name = "LogDB.Opt.ClearTime"sv, .DefaultValue = 1209600, .Index = CONFIG_LOGDB_CLEARTIME, .Min = 1 },
        { .Name = "SkillChance.Orange"sv, .DefaultValue = 100, .Index = CONFIG_SKILL_CHANCE_ORANGE },
        { .Name = "SkillChance.Yellow"sv, .DefaultValue = 75, .Index = CONFIG_SKILL_CHANCE_YELLOW },
        { .Name = "SkillChance.Green"sv, .DefaultValue = 25, .Index = CONFIG_SKILL_CHANCE_GREEN },
        { .Name = "SkillChance.Grey"sv, .DefaultValue = 0, .Index = CONFIG_SKILL_CHANCE_GREY },
        { .Name = "SkillChance.MiningSteps"sv, .DefaultValue = 75, .Index = CONFIG_SKILL_CHANCE_MINING_STEPS },
        { .Name = "SkillChance.SkinningSteps"sv, .DefaultValue = 75, .Index = CONFIG_SKILL_CHANCE_SKINNING_STEPS },
        { .Name = "SkillGain.Crafting"sv, .DefaultValue = 1, .Index = CONFIG_SKILL_GAIN_CRAFTING },
        { .Name = "SkillGain.Gathering"sv, .DefaultValue = 1, .Index = CONFIG_SKILL_GAIN_GATHERING },
        { .Name = "MaxOverspeedPings"sv, .DefaultValue = 2, .Index = CONFIG_MAX_OVERSPEED_PINGS },
        { .Name = "ClientCacheVersion"sv, .DefaultValue = 0, .Index = CONFIG_CLIENTCACHE_VERSION },
        { .Name = "DisableWaterBreath"sv, .DefaultValue = SEC_CONSOLE, .Index = CONFIG_DISABLE_BREATHING },
        { .Name = "Expansion"sv, .DefaultValue = CURRENT_EXPANSION, .Index = CONFIG_EXPANSION, .Min = 0, .Max = MAX_EXPANSIONS, .Reloadable = false },
        { .Name = "ChatFlood.MessageCount"sv, .DefaultValue = 10, .Index = CONFIG_CHATFLOOD_MESSAGE_COUNT },
        { .Name = "ChatFlood.MessageDelay"sv, .DefaultValue = 1, .Index = CONFIG_CHATFLOOD_MESSAGE_DELAY },
        { .Name = "ChatFlood.AddonMessageCount"sv, .DefaultValue = 100, .Index = CONFIG_CHATFLOOD_ADDON_MESSAGE_COUNT },
        { .Name = "ChatFlood.AddonMessageDelay"sv, .DefaultValue = 1, .Index = CONFIG_CHATFLOOD_ADDON_MESSAGE_DELAY },
        { .Name = "ChatFlood.MuteTime"sv, .DefaultValue = 10, .Index = CONFIG_CHATFLOOD_MUTE_TIME },
        { .Name = "CreatureFamilyAssistanceDelay"sv, .DefaultValue = 1500, .Index = CONFIG_CREATURE_FAMILY_ASSISTANCE_DELAY },
        { .Name = "CreatureFamilyFleeDelay"sv, .DefaultValue = 7000, .Index = CONFIG_CREATURE_FAMILY_FLEE_DELAY },
        { .Name = "WorldBossLevelDiff"sv, .DefaultValue = 3, .Index = CONFIG_WORLD_BOSS_LEVEL_DIFF },
        { .Name = "Quests.LowLevelHideDiff"sv, .DefaultValue = 4, .Index = CONFIG_QUEST_LOW_LEVEL_HIDE_DIFF, .Max = MAX_LEVEL },
        { .Name = "Quests.HighLevelHideDiff"sv, .DefaultValue = 7, .Index = CONFIG_QUEST_HIGH_LEVEL_HIDE_DIFF, .Max = MAX_LEVEL },
        { .Name = "Battleground.Random.ResetHour"sv, .DefaultValue = 6, .Index = CONFIG_RANDOM_BG_RESET_HOUR, .Min = 0, .Max = 23 },
        { .Name = "Calendar.DeleteOldEventsHour"sv, .DefaultValue = 6, .Index = CONFIG_CALENDAR_DELETE_OLD_EVENTS_HOUR, .Min = 0, .Max = 23 },
        { .Name = "Guild.ResetHour"sv, .DefaultValue = 6, .Index = CONFIG_GUILD_RESET_HOUR, .Min = 0, .Max = 23 },
        { .Name = "TalentsInspecting"sv, .DefaultValue = 1, .Index = CONFIG_TALENTS_INSPECTING },
        { .Name = "ChatStrictLinkChecking.Severity"sv, .DefaultValue = 0, .Index = CONFIG_CHAT_STRICT_LINK_CHECKING_SEVERITY },
        { .Name = "ChatStrictLinkChecking.Kick"sv, .DefaultValue = 0, .Index = CONFIG_CHAT_STRICT_LINK_CHECKING_KICK },
        { .Name = "Corpse.Decay.Normal"sv, .DefaultValue = 60, .Index = CONFIG_CORPSE_DECAY_NORMAL },
        { .Name = "Corpse.Decay.Elite"sv, .DefaultValue = 300, .Index = CONFIG_CORPSE_DECAY_ELITE },
        { .Name = "Corpse.Decay.RareElite"sv, .DefaultValue = 300, .Index = CONFIG_CORPSE_DECAY_RAREELITE },
        { .Name = "Corpse.Decay.Obsolete"sv, .DefaultValue = 3600, .Index = CONFIG_CORPSE_DECAY_OBSOLETE },
        { .Name = "Corpse.Decay.Rare"sv, .DefaultValue = 300, .Index = CONFIG_CORPSE_DECAY_RARE },
        { .Name = "Corpse.Decay.Trivial"sv, .DefaultValue = 300, .Index = CONFIG_CORPSE_DECAY_TRIVIAL },
        { .Name = "Corpse.Decay.MinusMob"sv, .DefaultValue = 150, .Index = CONFIG_CORPSE_DECAY_MINUSMOB },
        { .Name = "Death.SicknessLevel"sv, .DefaultValue = 11, .Index = CONFIG_DEATH_SICKNESS_LEVEL },
        { .Name = "Battleground.ReportAFK"sv, .DefaultValue = 3, .Index = CONFIG_BATTLEGROUND_REPORT_AFK, .Min = 1, .Max = 9 },
        { .Name = "Battleground.InvitationType"sv, .DefaultValue = 0, .Index = CONFIG_BATTLEGROUND_INVITATION_TYPE },
        { .Name = "Battleground.PrematureFinishTimer"sv, .DefaultValue = 5 * MINUTE * IN_MILLISECONDS, .Index = CONFIG_BATTLEGROUND_PREMATURE_FINISH_TIMER },
        { .Name = "Battleground.PremadeGroupWaitForMatch"sv, .DefaultValue = 30 * MINUTE * IN_MILLISECONDS, .Index = CONFIG_BATTLEGROUND_PREMADE_GROUP_WAIT_FOR_MATCH },
        { .Name = "Arena.MaxRatingDifference"sv, .DefaultValue = 150, .Index = CONFIG_ARENA_MAX_RATING_DIFFERENCE },
        { .Name = "Arena.RatingDiscardTimer"sv, .DefaultValue = 10 * MINUTE * IN_MILLISECONDS, .Index = CONFIG_ARENA_RATING_DISCARD_TIMER },
        { .Name = "Arena.RatedUpdateTimer"sv, .DefaultValue = 5 * IN_MILLISECONDS, .Index = CONFIG_ARENA_RATED_UPDATE_TIMER },
        { .Name = "Arena.ArenaSeason.ID"sv, .DefaultValue = 32, .Index = CONFIG_ARENA_SEASON_ID },
        { .Name = "Arena.ArenaStartRating"sv, .DefaultValue = 0, .Index = CONFIG_ARENA_START_RATING },
        { .Name = "Arena.ArenaStartPersonalRating"sv, .DefaultValue = 1000, .Index = CONFIG_ARENA_START_PERSONAL_RATING },
        { .Name = "Arena.ArenaStartMatchmakerRating"sv, .DefaultValue = 1500, .Index = CONFIG_ARENA_START_MATCHMAKER_RATING },
        { .Name = "Creature.PickPocketRefillDelay"sv, .DefaultValue = 10 * MINUTE, .Index = CONFIG_CREATURE_PICKPOCKET_REFILL },
        { .Name = "Creature.MovingStopTimeForPlayer"sv, .DefaultValue = 3 * MINUTE * IN_MILLISECONDS, .Index = CONFIG_CREATURE_STOP_FOR_PLAYER },
        { .Name = "Guild.NewsLogRecordsCount"sv, .DefaultValue = GUILD_NEWSLOG_MAX_RECORDS, .Index = CONFIG_GUILD_NEWS_LOG_COUNT, .Max = GUILD_NEWSLOG_MAX_RECORDS },
        { .Name = "Guild.EventLogRecordsCount"sv, .DefaultValue = GUILD_EVENTLOG_MAX_RECORDS, .Index = CONFIG_GUILD_EVENT_LOG_COUNT, .Max = GUILD_EVENTLOG_MAX_RECORDS },
        { .Name = "Guild.BankEventLogRecordsCount"sv, .DefaultValue = GUILD_BANKLOG_MAX_RECORDS, .Index = CONFIG_GUILD_BANK_EVENT_LOG_COUNT, .Max = GUILD_BANKLOG_MAX_RECORDS },
        { .Name = "Visibility.Notify.Period.OnContinents"sv, .DefaultValue = DEFAULT_VISIBILITY_NOTIFY_PERIOD, .Index = CONFIG_VISIBILITY_NOTIFY_PERIOD_CONTINENT },
        { .Name = "Visibility.Notify.Period.InInstances"sv, .DefaultValue = DEFAULT_VISIBILITY_NOTIFY_PERIOD, .Index = CONFIG_VISIBILITY_NOTIFY_PERIOD_INSTANCE },
        { .Name = "Visibility.Notify.Period.InBG"sv, .DefaultValue = DEFAULT_VISIBILITY_NOTIFY_PERIOD, .Index = CONFIG_VISIBILITY_NOTIFY_PERIOD_BATTLEGROUND },
        { .Name = "Visibility.Notify.Period.InArenas"sv, .DefaultValue = DEFAULT_VISIBILITY_NOTIFY_PERIOD, .Index = CONFIG_VISIBILITY_NOTIFY_PERIOD_ARENA },
        { .Name = "CharDelete.Method"sv, .DefaultValue = 0, .Index = CONFIG_CHARDELETE_METHOD },
        { .Name = "CharDelete.MinLevel"sv, .DefaultValue = 0, .Index = CONFIG_CHARDELETE_MIN_LEVEL },
        { .Name = "CharDelete.DeathKnight.MinLevel"sv, .DefaultValue = 0, .Index = CONFIG_CHARDELETE_DEATH_KNIGHT_MIN_LEVEL },
        { .Name = "CharDelete.DemonHunter.MinLevel"sv, .DefaultValue = 0, .Index = CONFIG_CHARDELETE_DEMON_HUNTER_MIN_LEVEL },
        { .Name = "CharDelete.KeepDays"sv, .DefaultValue = 30, .Index = CONFIG_CHARDELETE_KEEP_DAYS },
        { .Name = "NoGrayAggro.Above"sv, .DefaultValue = 0, .Index = CONFIG_NO_GRAY_AGGRO_ABOVE },
        { .Name = "NoGrayAggro.Below"sv, .DefaultValue = 0, .Index = CONFIG_NO_GRAY_AGGRO_BELOW },
        { .Name = "Respawn.MinCheckIntervalMS"sv, .DefaultValue = 5000, .Index = CONFIG_RESPAWN_MINCHECKINTERVALMS },
        { .Name = "Respawn.DynamicMode"sv, .DefaultValue = 0, .Index = CONFIG_RESPAWN_DYNAMICMODE, .Min = 0, .Max = 1 },
        { .Name = "Respawn.GuidWarnLevel"sv, .DefaultValue = 12000000, .Index = CONFIG_RESPAWN_GUIDWARNLEVEL, .Min = 0, .Max = 16777215 },
        { .Name = "Respawn.GuidAlertLevel"sv, .DefaultValue = 16000000, .Index = CONFIG_RESPAWN_GUIDALERTLEVEL, .Min = 0, .Max = 16777215 },
        { .Name = "Respawn.RestartQuietTime"sv, .DefaultValue = 3, .Index = CONFIG_RESPAWN_RESTARTQUIETTIME, .Min = 0, .Max = 23 },
        { .Name = "Respawn.DynamicMinimumCreature"sv, .DefaultValue = 10, .Index = CONFIG_RESPAWN_DYNAMICMINIMUM_CREATURE },
        { .Name = "Respawn.DynamicMinimumGameObject"sv, .DefaultValue = 10, .Index = CONFIG_RESPAWN_DYNAMICMINIMUM_GAMEOBJECT },
        { .Name = "Respawn.WarningFrequency"sv, .DefaultValue = 1800, .Index = CONFIG_RESPAWN_GUIDWARNING_FREQUENCY },
        { .Name = "MaxWhoListReturns"sv, .DefaultValue = 49, .Index = CONFIG_MAX_WHO },
        { .Name = "HonorPointsAfterDuel"sv, .DefaultValue = 0, .Index = CONFIG_HONOR_AFTER_DUEL },
        { .Name = "PvPToken.MapAllowType"sv, .DefaultValue = 4, .Index = CONFIG_PVP_TOKEN_MAP_TYPE, .Min = 1, .Max = 4 },
        { .Name = "PvPToken.ItemID"sv, .DefaultValue = 29434, .Index = CONFIG_PVP_TOKEN_ID },
        { .Name = "PvPToken.ItemCount"sv, .DefaultValue = 1, .Index = CONFIG_PVP_TOKEN_COUNT, .Min = 1 },
        { .Name = "MapUpdate.Threads"sv, .DefaultValue = 1, .Index = CONFIG_NUMTHREADS, .Min = 1 },
        { .Name = "Command.LookupMaxResults"sv, .DefaultValue = 0, .Index = CONFIG_MAX_RESULTS_LOOKUP_COMMANDS },
        { .Name = "FeatureSystem.CharacterUndelete.Cooldown"sv, .DefaultValue = 2592000, .Index = CONFIG_FEATURE_SYSTEM_CHARACTER_UNDELETE_COOLDOWN },
        { .Name = "DungeonFinder.OptionsMask"sv, .DefaultValue = 1, .Index = CONFIG_LFG_OPTIONSMASK },
        { .Name = "Account.PasswordChangeSecurity"sv, .DefaultValue = 0, .Index = CONFIG_ACC_PASSCHANGESEC },
        { .Name = "Battleground.RewardWinnerHonorFirst"sv, .DefaultValue = 27000, .Index = CONFIG_BG_REWARD_WINNER_HONOR_FIRST },
        { .Name = "Battleground.RewardWinnerConquestFirst"sv, .DefaultValue = 10000, .Index = CONFIG_BG_REWARD_WINNER_CONQUEST_FIRST },
        { .Name = "Battleground.RewardWinnerHonorLast"sv, .DefaultValue = 13500, .Index = CONFIG_BG_REWARD_WINNER_HONOR_LAST },
        { .Name = "Battleground.RewardWinnerConquestLast"sv, .DefaultValue = 5000, .Index = CONFIG_BG_REWARD_WINNER_CONQUEST_LAST },
        { .Name = "Battleground.RewardLoserHonorFirst"sv, .DefaultValue = 4500, .Index = CONFIG_BG_REWARD_LOSER_HONOR_FIRST },
        { .Name = "Battleground.RewardLoserHonorLast"sv, .DefaultValue = 3500, .Index = CONFIG_BG_REWARD_LOSER_HONOR_LAST },
        { .Name = "AccountInstancesPerHour"sv, .DefaultValue = 10, .Index = CONFIG_MAX_INSTANCES_PER_HOUR },
        { .Name = "AutoBroadcast.Center"sv, .DefaultValue = 0, .Index = CONFIG_AUTOBROADCAST_CENTER },
        { .Name = "AutoBroadcast.Timer"sv, .DefaultValue = 60000, .Index = CONFIG_AUTOBROADCAST_INTERVAL },
        { .Name = "MaxPingTime"sv, .DefaultValue = 30, .Index = CONFIG_DB_PING_INTERVAL },
        { .Name = "Guild.SaveInterval"sv, .DefaultValue = 15, .Index = CONFIG_GUILD_SAVE_INTERVAL },
        { .Name = "Wintergrasp.PlayerMax"sv, .DefaultValue = 100, .Index = CONFIG_WINTERGRASP_PLR_MAX },
        { .Name = "Wintergrasp.PlayerMin"sv, .DefaultValue = 0, .Index = CONFIG_WINTERGRASP_PLR_MIN },
        { .Name = "Wintergrasp.PlayerMinLvl"sv, .DefaultValue = 77, .Index = CONFIG_WINTERGRASP_PLR_MIN_LVL },
        { .Name = "Wintergrasp.BattleTimer"sv, .DefaultValue = 30, .Index = CONFIG_WINTERGRASP_BATTLETIME },
        { .Name = "Wintergrasp.NoBattleTimer"sv, .DefaultValue = 150, .Index = CONFIG_WINTERGRASP_NOBATTLETIME },
        { .Name = "Wintergrasp.CrashRestartTimer"sv, .DefaultValue = 10, .Index = CONFIG_WINTERGRASP_RESTART_AFTER_CRASH },
        { .Name = "TolBarad.PlayerMax"sv, .DefaultValue = 100, .Index = CONFIG_TOLBARAD_PLR_MAX },
        { .Name = "TolBarad.PlayerMin"sv, .DefaultValue = 0, .Index = CONFIG_TOLBARAD_PLR_MIN },
        { .Name = "TolBarad.PlayerMinLvl"sv, .DefaultValue = 85, .Index = CONFIG_TOLBARAD_PLR_MIN_LVL },
        { .Name = "TolBarad.BattleTimer"sv, .DefaultValue = 15, .Index = CONFIG_TOLBARAD_BATTLETIME },
        { .Name = "TolBarad.BonusTime"sv, .DefaultValue = 5, .Index = CONFIG_TOLBARAD_BONUSTIME },
        { .Name = "TolBarad.NoBattleTimer"sv, .DefaultValue = 150, .Index = CONFIG_TOLBARAD_NOBATTLETIME },
        { .Name = "TolBarad.CrashRestartTimer"sv, .DefaultValue = 10, .Index = CONFIG_TOLBARAD_RESTART_AFTER_CRASH },
        { .Name = "PacketSpoof.Policy"sv, .DefaultValue = WorldSession::DosProtection::POLICY_KICK, .Index = CONFIG_PACKET_SPOOF_POLICY },
        { .Name = "PacketSpoof.BanMode"sv, .DefaultValue = BAN_ACCOUNT, .Index = CONFIG_PACKET_SPOOF_BANMODE, .Min = BAN_ACCOUNT, .Max = BAN_IP },
        { .Name = "PacketSpoof.BanDuration"sv, .DefaultValue = 86400, .Index = CONFIG_PACKET_SPOOF_BANDURATION },
        { .Name = "AuctionHouseBot.Update.Interval"sv, .DefaultValue = 20, .Index = CONFIG_AHBOT_UPDATE_INTERVAL },
        { .Name = "BlackMarket.MaxAuctions"sv, .DefaultValue = 12, .Index = CONFIG_BLACKMARKET_MAXAUCTIONS },
        { .Name = "BlackMarket.UpdatePeriod"sv, .DefaultValue = 24, .Index = CONFIG_BLACKMARKET_UPDATE_PERIOD },
        { .Name = "Pvp.FactionBalance.LevelCheckDiff"sv, .DefaultValue = 0, .Index = CONFIG_FACTION_BALANCE_LEVEL_CHECK_DIFF },
    } };

    static constexpr ConfigOptionLoadDefinitionArray<uint64, INT64_CONFIG_VALUE_COUNT> int64s =
    { {
        { .Name = "CharacterCreating.Disabled.RaceMask"sv, .DefaultValue = 0, .Index = CONFIG_CHARACTER_CREATING_DISABLED_RACEMASK },
        { .Name = "StartPlayerMoney"sv, .DefaultValue = 0, .Index = CONFIG_START_PLAYER_MONEY, .Min = 0, .Max = MAX_MONEY_AMOUNT },
    } };

    static constexpr ConfigOptionLoadDefinitionArray<float, FLOAT_CONFIG_VALUE_COUNT> floats =
    { {
        { .Name = "MaxGroupXPDistance"sv, .DefaultValue = 74.0f, .Index = CONFIG_GROUP_XP_DISTANCE },
        { .Name = "MaxRecruitAFriendBonusDistance"sv, .DefaultValue = 100.0f, .Index = CONFIG_MAX_RECRUIT_A_FRIEND_DISTANCE },
        { .Name = "MonsterSight"sv, .DefaultValue = 50.0f, .Index = CONFIG_SIGHT_MONSTER },
        { .Name = "CreatureFamilyFleeAssistanceRadius"sv, .DefaultValue = 30.0f, .Index = CONFIG_CREATURE_FAMILY_FLEE_ASSISTANCE_RADIUS },
        { .Name = "CreatureFamilyAssistanceRadius"sv, .DefaultValue = 10.0f, .Index = CONFIG_CREATURE_FAMILY_ASSISTANCE_RADIUS },
        { .Name = "ThreatRadius"sv, .DefaultValue = 60.0f, .Index = CONFIG_THREAT_RADIUS },
        { .Name = "ListenRange.Say"sv, .DefaultValue = 25.0f, .Index = CONFIG_LISTEN_RANGE_SAY },
        { .Name = "ListenRange.TextEmote"sv, .DefaultValue = 25.0f, .Index = CONFIG_LISTEN_RANGE_TEXTEMOTE },
        { .Name = "ListenRange.Yell"sv, .DefaultValue = 300.0f, .Index = CONFIG_LISTEN_RANGE_YELL },
        { .Name = "Arena.ArenaWinRatingModifier1"sv, .DefaultValue = 48.0f, .Index = CONFIG_ARENA_WIN_RATING_MODIFIER_1 },
        { .Name = "Arena.ArenaWinRatingModifier2"sv, .DefaultValue = 24.0f, .Index = CONFIG_ARENA_WIN_RATING_MODIFIER_2 },
        { .Name = "Arena.ArenaLoseRatingModifier"sv, .DefaultValue = 24.0f, .Index = CONFIG_ARENA_LOSE_RATING_MODIFIER },
        { .Name = "Arena.ArenaMatchmakerRatingModifier"sv, .DefaultValue = 24.0f, .Index = CONFIG_ARENA_MATCHMAKER_RATING_MODIFIER },
        { .Name = "Visibility.Distance.Continents"sv, .DefaultValue = DEFAULT_VISIBILITY_DISTANCE, .Index = CONFIG_MAX_VISIBILITY_DISTANCE_CONTINENT, .Min = 0.0f, .Max = MAX_VISIBILITY_DISTANCE },
        { .Name = "Visibility.Distance.Instances"sv, .DefaultValue = DEFAULT_VISIBILITY_INSTANCE, .Index = CONFIG_MAX_VISIBILITY_DISTANCE_INSTANCE, .Min = 0.0f, .Max = MAX_VISIBILITY_DISTANCE },
        { .Name = "Visibility.Distance.BG"sv, .DefaultValue = DEFAULT_VISIBILITY_BGARENAS, .Index = CONFIG_MAX_VISIBILITY_DISTANCE_BATTLEGROUND, .Min = 0.0f, .Max = MAX_VISIBILITY_DISTANCE },
        { .Name = "Visibility.Distance.Arenas"sv, .DefaultValue = DEFAULT_VISIBILITY_BGARENAS, .Index = CONFIG_MAX_VISIBILITY_DISTANCE_ARENA, .Min = 0.0f, .Max = MAX_VISIBILITY_DISTANCE },
        { .Name = "Respawn.DynamicRateCreature"sv, .DefaultValue = 10.0f, .Index = CONFIG_RESPAWN_DYNAMICRATE_CREATURE, .Min = 0.0f },
        { .Name = "Respawn.DynamicRateGameObject"sv, .DefaultValue = 10.0f, .Index = CONFIG_RESPAWN_DYNAMICRATE_GAMEOBJECT, .Min = 0.0f },
        { .Name = "Stats.Limits.Dodge"sv, .DefaultValue = 95.0f, .Index = CONFIG_STATS_LIMITS_DODGE },
        { .Name = "Stats.Limits.Parry"sv, .DefaultValue = 95.0f, .Index = CONFIG_STATS_LIMITS_PARRY },
        { .Name = "Stats.Limits.Block"sv, .DefaultValue = 95.0f, .Index = CONFIG_STATS_LIMITS_BLOCK },
        { .Name = "Stats.Limits.Crit"sv, .DefaultValue = 95.0f, .Index = CONFIG_STATS_LIMITS_CRIT },
        { .Name = "Pvp.FactionBalance.Pct5"sv, .DefaultValue = 0.6f, .Index = CONFIG_CALL_TO_ARMS_5_PCT },
        { .Name = "Pvp.FactionBalance.Pct10"sv, .DefaultValue = 0.7f, .Index = CONFIG_CALL_TO_ARMS_10_PCT },
        { .Name = "Pvp.FactionBalance.Pct20"sv, .DefaultValue = 0.8f, .Index = CONFIG_CALL_TO_ARMS_20_PCT },
    } };

    static constexpr ConfigOptionLoadDefinitionArray<float, MAX_RATES> rates =
    { {
        { .Name = "Rate.Health"sv, .DefaultValue = 1.0f, .Index = RATE_HEALTH, .Min = 0.01f },
        { .Name = "Rate.Mana"sv, .DefaultValue = 1.0f, .Index = RATE_POWER_MANA, .Min = 0.01f },
        { .Name = "Rate.Rage.Gain"sv, .DefaultValue = 1.0f, .Index = RATE_POWER_RAGE_INCOME, .Min = 0.01f },
        { .Name = "Rate.Rage.Loss"sv, .DefaultValue = 1.0f, .Index = RATE_POWER_RAGE_LOSS, .Min = 0.01f },
        { .Name = "Rate.Focus"sv, .DefaultValue = 1.0f, .Index = RATE_POWER_FOCUS, .Min = 0.01f },
        { .Name = "Rate.Energy"sv, .DefaultValue = 1.0f, .Index = RATE_POWER_ENERGY, .Min = 0.01f },
        { .Name = "Rate.ComboPoints.Loss"sv, .DefaultValue = 1.0f, .Index = RATE_POWER_COMBO_POINTS_LOSS, .Min = 0.01f },
        { .Name = "Rate.RunicPower.Gain"sv, .DefaultValue = 1.0f, .Index = RATE_POWER_RUNIC_POWER_INCOME, .Min = 0.01f },
        { .Name = "Rate.RunicPower.Loss"sv, .DefaultValue = 1.0f, .Index = RATE_POWER_RUNIC_POWER_LOSS, .Min = 0.01f },
        { .Name = "Rate.SoulShards.Loss"sv, .DefaultValue = 1.0f, .Index = RATE_POWER_SOUL_SHARDS, .Min = 0.01f },
        { .Name = "Rate.LunarPower.Loss"sv, .DefaultValue = 1.0f, .Index = RATE_POWER_LUNAR_POWER, .Min = 0.01f },
        { .Name = "Rate.HolyPower.Loss"sv, .DefaultValue = 1.0f, .Index = RATE_POWER_HOLY_POWER, .Min = 0.01f },
        { .Name = "Rate.Maelstrom.Loss"sv, .DefaultValue = 1.0f, .Index = RATE_POWER_MAELSTROM, .Min = 0.01f },
        { .Name = "Rate.Chi.Loss"sv, .DefaultValue = 1.0f, .Index = RATE_POWER_CHI, .Min = 0.01f },
        { .Name = "Rate.Insanity.Loss"sv, .DefaultValue = 1.0f, .Index = RATE_POWER_INSANITY, .Min = 0.01f },
        { .Name = "Rate.ArcaneCharges.Loss"sv, .DefaultValue = 1.0f, .Index = RATE_POWER_ARCANE_CHARGES, .Min = 0.01f },
        { .Name = "Rate.Fury.Loss"sv, .DefaultValue = 1.0f, .Index = RATE_POWER_FURY, .Min = 0.01f },
        { .Name = "Rate.Pain.Loss"sv, .DefaultValue = 1.0f, .Index = RATE_POWER_PAIN, .Min = 0.01f },
        { .Name = "Rate.Essence.Loss"sv, .DefaultValue = 1.0f, .Index = RATE_POWER_ESSENCE, .Min = 0.01f },
        { .Name = "Rate.Skill.Discovery"sv, .DefaultValue = 1.0f, .Index = RATE_SKILL_DISCOVERY },
        { .Name = "Rate.Drop.Item.Poor"sv, .DefaultValue = 1.0f, .Index = RATE_DROP_ITEM_POOR },
        { .Name = "Rate.Drop.Item.Normal"sv, .DefaultValue = 1.0f, .Index = RATE_DROP_ITEM_NORMAL },
        { .Name = "Rate.Drop.Item.Uncommon"sv, .DefaultValue = 1.0f, .Index = RATE_DROP_ITEM_UNCOMMON },
        { .Name = "Rate.Drop.Item.Rare"sv, .DefaultValue = 1.0f, .Index = RATE_DROP_ITEM_RARE },
        { .Name = "Rate.Drop.Item.Epic"sv, .DefaultValue = 1.0f, .Index = RATE_DROP_ITEM_EPIC },
        { .Name = "Rate.Drop.Item.Legendary"sv, .DefaultValue = 1.0f, .Index = RATE_DROP_ITEM_LEGENDARY },
        { .Name = "Rate.Drop.Item.Artifact"sv, .DefaultValue = 1.0f, .Index = RATE_DROP_ITEM_ARTIFACT },
        { .Name = "Rate.Drop.Item.Referenced"sv, .DefaultValue = 1.0f, .Index = RATE_DROP_ITEM_REFERENCED },
        { .Name = "Rate.Drop.Item.ReferencedAmount"sv, .DefaultValue = 1.0f, .Index = RATE_DROP_ITEM_REFERENCED_AMOUNT },
        { .Name = "Rate.Drop.Money"sv, .DefaultValue = 1.0f, .Index = RATE_DROP_MONEY },
        { .Name = "Rate.XP.Kill"sv, .DefaultValue = 1.0f, .Index = RATE_XP_KILL },
        { .Name = "Rate.XP.BattlegroundKill"sv, .DefaultValue = 1.0f, .Index = RATE_XP_BG_KILL },
        { .Name = "Rate.XP.Quest"sv, .DefaultValue = 1.0f, .Index = RATE_XP_QUEST },
        { .Name = "Rate.XP.Explore"sv, .DefaultValue = 1.0f, .Index = RATE_XP_EXPLORE },
        { .Name = "XP.Boost.Rate"sv, .DefaultValue = 2.0f, .Index = RATE_XP_BOOST },
        { .Name = "Rate.RepairCost"sv, .DefaultValue = 1.0f, .Index = RATE_REPAIRCOST, .Min = 0.0f },
        { .Name = "Rate.Reputation.Gain"sv, .DefaultValue = 1.0f, .Index = RATE_REPUTATION_GAIN },
        { .Name = "Rate.Reputation.LowLevel.Kill"sv, .DefaultValue = 1.0f, .Index = RATE_REPUTATION_LOWLEVEL_KILL },
        { .Name = "Rate.Reputation.LowLevel.Quest"sv, .DefaultValue = 1.0f, .Index = RATE_REPUTATION_LOWLEVEL_QUEST },
        { .Name = "Rate.Reputation.RecruitAFriendBonus"sv, .DefaultValue = 0.1f, .Index = RATE_REPUTATION_RECRUIT_A_FRIEND_BONUS},
        { .Name = "Rate.Creature.HP.Normal"sv, .DefaultValue = 1.0f, .Index = RATE_CREATURE_HP_NORMAL },
        { .Name = "Rate.Creature.HP.Elite"sv, .DefaultValue = 1.0f, .Index = RATE_CREATURE_HP_ELITE },
        { .Name = "Rate.Creature.HP.RareElite"sv, .DefaultValue = 1.0f, .Index = RATE_CREATURE_HP_RAREELITE },
        { .Name = "Rate.Creature.HP.Obsolete"sv, .DefaultValue = 1.0f, .Index = RATE_CREATURE_HP_OBSOLETE },
        { .Name = "Rate.Creature.HP.Rare"sv, .DefaultValue = 1.0f, .Index = RATE_CREATURE_HP_RARE },
        { .Name = "Rate.Creature.HP.Trivial"sv, .DefaultValue = 1.0f, .Index = RATE_CREATURE_HP_TRIVIAL },
        { .Name = "Rate.Creature.HP.MinusMob"sv, .DefaultValue = 1.0f, .Index = RATE_CREATURE_HP_MINUSMOB },
        { .Name = "Rate.Creature.Damage.Normal"sv, .DefaultValue = 1.0f, .Index = RATE_CREATURE_DAMAGE_NORMAL },
        { .Name = "Rate.Creature.Damage.Elite"sv, .DefaultValue = 1.0f, .Index = RATE_CREATURE_DAMAGE_ELITE },
        { .Name = "Rate.Creature.Damage.RareElite"sv, .DefaultValue = 1.0f, .Index = RATE_CREATURE_DAMAGE_RAREELITE },
        { .Name = "Rate.Creature.Damage.Obsolete"sv, .DefaultValue = 1.0f, .Index = RATE_CREATURE_DAMAGE_OBSOLETE },
        { .Name = "Rate.Creature.Damage.Rare"sv, .DefaultValue = 1.0f, .Index = RATE_CREATURE_DAMAGE_RARE },
        { .Name = "Rate.Creature.Damage.Trivial"sv, .DefaultValue = 1.0f, .Index = RATE_CREATURE_DAMAGE_TRIVIAL },
        { .Name = "Rate.Creature.Damage.MinusMob"sv, .DefaultValue = 1.0f, .Index = RATE_CREATURE_DAMAGE_MINUSMOB },
        { .Name = "Rate.Creature.SpellDamage.Normal"sv, .DefaultValue = 1.0f, .Index = RATE_CREATURE_SPELLDAMAGE_NORMAL },
        { .Name = "Rate.Creature.SpellDamage.Elite"sv, .DefaultValue = 1.0f, .Index = RATE_CREATURE_SPELLDAMAGE_ELITE },
        { .Name = "Rate.Creature.SpellDamage.RareElite"sv, .DefaultValue = 1.0f, .Index = RATE_CREATURE_SPELLDAMAGE_RAREELITE },
        { .Name = "Rate.Creature.SpellDamage.Obsolete"sv, .DefaultValue = 1.0f, .Index = RATE_CREATURE_SPELLDAMAGE_OBSOLETE },
        { .Name = "Rate.Creature.SpellDamage.Rare"sv, .DefaultValue = 1.0f, .Index = RATE_CREATURE_SPELLDAMAGE_RARE },
        { .Name = "Rate.Creature.SpellDamage.Trivial"sv, .DefaultValue = 1.0f, .Index = RATE_CREATURE_SPELLDAMAGE_TRIVIAL },
        { .Name = "Rate.Creature.SpellDamage.MinusMob"sv, .DefaultValue = 1.0f, .Index = RATE_CREATURE_SPELLDAMAGE_MINUSMOB },
        { .Name = "Rate.Creature.Aggro"sv, .DefaultValue = 1.0f, .Index = RATE_CREATURE_AGGRO },
        { .Name = "Rate.Rest.InGame"sv, .DefaultValue = 1.0f, .Index = RATE_REST_INGAME },
        { .Name = "Rate.Rest.Offline.InTavernOrCity"sv, .DefaultValue = 1.0f, .Index = RATE_REST_OFFLINE_IN_TAVERN_OR_CITY },
        { .Name = "Rate.Rest.Offline.InWilderness"sv, .DefaultValue = 1.0f, .Index = RATE_REST_OFFLINE_IN_WILDERNESS },
        { .Name = "Rate.Damage.Fall"sv, .DefaultValue = 1.0f, .Index = RATE_DAMAGE_FALL },
        { .Name = "Rate.Auction.Time"sv, .DefaultValue = 1.0f, .Index = RATE_AUCTION_TIME },
        { .Name = "Rate.Auction.Deposit"sv, .DefaultValue = 1.0f, .Index = RATE_AUCTION_DEPOSIT },
        { .Name = "Rate.Auction.Cut"sv, .DefaultValue = 1.0f, .Index = RATE_AUCTION_CUT },
        { .Name = "Rate.Honor"sv, .DefaultValue = 1.0f, .Index = RATE_HONOR },
        { .Name = "Rate.InstanceResetTime"sv, .DefaultValue = 1.0f, .Index = RATE_INSTANCE_RESET_TIME },
        { .Name = "Rate.MoveSpeed"sv, .DefaultValue = 1.0f, .Index = RATE_MOVESPEED, .Min = 0.01f },
        { .Name = "Rate.Corpse.Decay.Looted"sv, .DefaultValue = 0.5f, .Index = RATE_CORPSE_DECAY_LOOTED },
        { .Name = "DurabilityLoss.OnDeath"sv, .DefaultValue = 10.0f, .Index = RATE_DURABILITY_LOSS_ON_DEATH, .Min = 0.0f, .Max = 100.0f },
        { .Name = "DurabilityLossChance.Damage"sv, .DefaultValue = 0.5f, .Index = RATE_DURABILITY_LOSS_DAMAGE, .Min = 0.0f },
        { .Name = "DurabilityLossChance.Absorb"sv, .DefaultValue = 0.5f, .Index = RATE_DURABILITY_LOSS_ABSORB, .Min = 0.0f },
        { .Name = "DurabilityLossChance.Parry"sv, .DefaultValue = 0.05f, .Index = RATE_DURABILITY_LOSS_PARRY, .Min = 0.0f },
        { .Name = "DurabilityLossChance.Block"sv, .DefaultValue = 0.05f, .Index = RATE_DURABILITY_LOSS_BLOCK, .Min = 0.0f },
        { .Name = "Rate.Quest.Money.Reward"sv, .DefaultValue = 1.0f, .Index = RATE_MONEY_QUEST, .Min = 0.0f },
        { .Name = "Rate.Quest.Money.Max.Level.Reward"sv, .DefaultValue = 1.0f, .Index = RATE_MONEY_MAX_LEVEL_QUEST, .Min = 0.0f },
    } };

    for (ConfigOptionLoadDefinition<bool, WorldBoolConfigs> const& definition : bools)
        StoreConfigValue(m_bool_configs[definition.Index], sConfigMgr->GetBoolDefault(definition.Name, definition.DefaultValue), definition, reload);

    for (ConfigOptionLoadDefinition<uint32, WorldIntConfigs> const& definition : ints)
        StoreConfigValue(m_int_configs[definition.Index], sConfigMgr->GetIntDefault(definition.Name, definition.DefaultValue), definition, reload);

    for (ConfigOptionLoadDefinition<uint64, WorldInt64Configs> const& definition : int64s)
        StoreConfigValue(m_int64_configs[definition.Index], sConfigMgr->GetInt64Default(definition.Name, definition.DefaultValue), definition, reload);

    for (ConfigOptionLoadDefinition<float, WorldFloatConfigs> const& definition : floats)
        StoreConfigValue(m_float_configs[definition.Index], sConfigMgr->GetFloatDefault(definition.Name, definition.DefaultValue), definition, reload);

    for (ConfigOptionLoadDefinition<float, Rates> const& definition : rates)
        StoreConfigValue(rate_values[definition.Index], sConfigMgr->GetFloatDefault(definition.Name, definition.DefaultValue), definition, reload);

    ///- Get string for new logins (newly created characters)
    SetNewCharString(sConfigMgr->GetStringDefault("PlayerStart.String"sv, ""sv));

    for (uint8 i = 0; i < MAX_MOVE_TYPE; ++i)
        playerBaseMoveSpeed[i] = baseMoveSpeed[i] * rate_values[RATE_MOVESPEED];

    rate_values[RATE_DURABILITY_LOSS_ON_DEATH] /= 100.0f;

    if (m_bool_configs[CONFIG_GRID_UNLOAD])
    {
        if (m_bool_configs[CONFIG_BASEMAP_LOAD_GRIDS])
        {
            TC_LOG_ERROR("server.loading", "BaseMapLoadAllGrids enabled, but GridUnload also enabled. GridUnload must be disabled to enable base map pre-loading. Base map pre-loading disabled");
            m_bool_configs[CONFIG_BASEMAP_LOAD_GRIDS] = false;
        }
        if (m_bool_configs[CONFIG_INSTANCEMAP_LOAD_GRIDS])
        {
            TC_LOG_ERROR("server.loading", "InstanceMapLoadAllGrids enabled, but GridUnload also enabled. GridUnload must be disabled to enable instance map pre-loading. Instance map pre-loading disabled");
            m_bool_configs[CONFIG_INSTANCEMAP_LOAD_GRIDS] = false;
        }
    }

    // Config values are in "milliseconds" but we handle SocketTimeOut only as "seconds" so divide by 1000
    m_int_configs[CONFIG_SOCKET_TIMEOUTTIME] /= 1000;
    m_int_configs[CONFIG_SOCKET_TIMEOUTTIME_ACTIVE] /= 1000;

    // must be after CONFIG_CHARACTERS_PER_REALM
    if (m_int_configs[CONFIG_CHARACTERS_PER_ACCOUNT] < m_int_configs[CONFIG_CHARACTERS_PER_REALM])
    {
        TC_LOG_ERROR("server.loading", "CharactersPerAccount ({}) can't be less than CharactersPerRealm ({}).", m_int_configs[CONFIG_CHARACTERS_PER_ACCOUNT], m_int_configs[CONFIG_CHARACTERS_PER_REALM]);
        m_int_configs[CONFIG_CHARACTERS_PER_ACCOUNT] = m_int_configs[CONFIG_CHARACTERS_PER_REALM];
    }

    auto validateStartLevel = [&](WorldIntConfigs config, char const* name)
    {
        uint32 maxLevel = m_int_configs[CONFIG_MAX_PLAYER_LEVEL];
        if (m_int_configs[config] > maxLevel)
        {
            TC_LOG_ERROR("server.loading", "{} ({}) must be in range 1..MaxPlayerLevel({}). Set to {}.", name, m_int_configs[config], maxLevel, maxLevel);
            m_int_configs[config] = maxLevel;
        }
    };

    validateStartLevel(CONFIG_START_PLAYER_LEVEL, "StartPlayerLevel");
    validateStartLevel(CONFIG_START_DEATH_KNIGHT_PLAYER_LEVEL, "StartDeathKnightPlayerLevel");
    validateStartLevel(CONFIG_START_DEMON_HUNTER_PLAYER_LEVEL, "StartDemonHunterPlayerLevel");
    validateStartLevel(CONFIG_START_EVOKER_PLAYER_LEVEL, "StartEvokerPlayerLevel");
    validateStartLevel(CONFIG_START_ALLIED_RACE_LEVEL, "StartDemonHunterPlayerLevel");
    validateStartLevel(CONFIG_MAX_RECRUIT_A_FRIEND_BONUS_PLAYER_LEVEL, "RecruitAFriend.MaxLevel");

    if (m_int_configs[CONFIG_START_GM_LEVEL] < m_int_configs[CONFIG_START_PLAYER_LEVEL])
    {
        TC_LOG_ERROR("server.loading", "GM.StartLevel ({}) must be in range StartPlayerLevel({})..{}. Set to {}.",
            m_int_configs[CONFIG_START_GM_LEVEL], m_int_configs[CONFIG_START_PLAYER_LEVEL], MAX_LEVEL, m_int_configs[CONFIG_START_PLAYER_LEVEL]);
        m_int_configs[CONFIG_START_GM_LEVEL] = m_int_configs[CONFIG_START_PLAYER_LEVEL];
    }

    TC_LOG_INFO("server.loading", "Will clear `logs` table of entries older than {} seconds every {} minutes.",
        m_int_configs[CONFIG_LOGDB_CLEARTIME], m_int_configs[CONFIG_LOGDB_CLEARINTERVAL]);

    if (m_int_configs[CONFIG_MAX_OVERSPEED_PINGS] != 0 && m_int_configs[CONFIG_MAX_OVERSPEED_PINGS] < 2)
    {
        TC_LOG_ERROR("server.loading", "MaxOverspeedPings ({}) must be in range 2..infinity (or 0 to disable check). Set to 2.", m_int_configs[CONFIG_MAX_OVERSPEED_PINGS]);
        m_int_configs[CONFIG_MAX_OVERSPEED_PINGS] = 2;
    }

    // always use declined names in the russian client
    if (Cfg_CategoriesEntry const* category = sCfgCategoriesStore.LookupEntry(m_int_configs[CONFIG_REALM_ZONE]))
        if (category->GetCreateCharsetMask().HasFlag(CfgCategoriesCharsets::Russian))
            m_bool_configs[CONFIG_DECLINED_NAMES_USED] = true;

    if (!m_int_configs[CONFIG_CLIENTCACHE_VERSION])
        m_int_configs[CONFIG_CLIENTCACHE_VERSION] = databaseCacheVersion;

    TC_LOG_INFO("server.loading", "Client cache version set to: {}", m_int_configs[CONFIG_CLIENTCACHE_VERSION]);

    auto validateVisibilityDistance = [&](WorldFloatConfigs config, char const* name)
    {
        float minVisibilityDistance = 45.0f * rate_values[RATE_CREATURE_AGGRO];
        if (m_float_configs[config] < minVisibilityDistance)
        {
            TC_LOG_ERROR("server.loading", "{} can't be less max aggro radius {}", name, minVisibilityDistance);
            m_float_configs[config] = minVisibilityDistance;
        }
    };

    // visibility on continents
    validateVisibilityDistance(CONFIG_MAX_VISIBILITY_DISTANCE_CONTINENT, "Visibility.Distance.Continents");

    // visibility in instances
    validateVisibilityDistance(CONFIG_MAX_VISIBILITY_DISTANCE_INSTANCE, "Visibility.Distance.Instances");

    // visibility in BG
    validateVisibilityDistance(CONFIG_MAX_VISIBILITY_DISTANCE_BATTLEGROUND, "Visibility.Distance.BG");

    // Visibility in Arenas
    validateVisibilityDistance(CONFIG_MAX_VISIBILITY_DISTANCE_ARENA, "Visibility.Distance.Arenas");

    // No aggro from gray mobs
    if (m_int_configs[CONFIG_NO_GRAY_AGGRO_ABOVE] > m_int_configs[CONFIG_MAX_PLAYER_LEVEL])
    {
       TC_LOG_ERROR("server.loading", "NoGrayAggro.Above ({}) must be in range 0..{}. Set to {}.", m_int_configs[CONFIG_NO_GRAY_AGGRO_ABOVE], m_int_configs[CONFIG_MAX_PLAYER_LEVEL], m_int_configs[CONFIG_MAX_PLAYER_LEVEL]);
       m_int_configs[CONFIG_NO_GRAY_AGGRO_ABOVE] = m_int_configs[CONFIG_MAX_PLAYER_LEVEL];
    }
    if (m_int_configs[CONFIG_NO_GRAY_AGGRO_BELOW] > m_int_configs[CONFIG_MAX_PLAYER_LEVEL])
    {
       TC_LOG_ERROR("server.loading", "NoGrayAggro.Below ({}) must be in range 0..{}. Set to {}.", m_int_configs[CONFIG_NO_GRAY_AGGRO_BELOW], m_int_configs[CONFIG_MAX_PLAYER_LEVEL], m_int_configs[CONFIG_MAX_PLAYER_LEVEL]);
       m_int_configs[CONFIG_NO_GRAY_AGGRO_BELOW] = m_int_configs[CONFIG_MAX_PLAYER_LEVEL];
    }
    if (m_int_configs[CONFIG_NO_GRAY_AGGRO_ABOVE] > 0 && m_int_configs[CONFIG_NO_GRAY_AGGRO_ABOVE] < m_int_configs[CONFIG_NO_GRAY_AGGRO_BELOW])
    {
       TC_LOG_ERROR("server.loading", "NoGrayAggro.Below ({}) cannot be greater than NoGrayAggro.Above ({}). Set to {}.", m_int_configs[CONFIG_NO_GRAY_AGGRO_BELOW], m_int_configs[CONFIG_NO_GRAY_AGGRO_ABOVE], m_int_configs[CONFIG_NO_GRAY_AGGRO_ABOVE]);
       m_int_configs[CONFIG_NO_GRAY_AGGRO_BELOW] = m_int_configs[CONFIG_NO_GRAY_AGGRO_ABOVE];
    }

    // Respawn Settings
    _guidWarningMsg = sConfigMgr->GetStringDefault("Respawn.WarningMessage"sv, "There will be an unscheduled server restart at 03:00. The server will be available again shortly after."sv);
    _alertRestartReason = sConfigMgr->GetStringDefault("Respawn.AlertRestartReason"sv, "Urgent Maintenance"sv);

    ///- Read the "Data" directory from the config file
    std::string dataPath = sConfigMgr->GetStringDefault("DataDir"sv, "./"sv);
    if (dataPath.empty() || (dataPath.back() != '/' && dataPath.back() != '\\'))
        dataPath.push_back('/');

    if (dataPath[0] == '~')
    {
#if TRINITY_PLATFORM != TRINITY_PLATFORM_WINDOWS
#define USER_HOME_DIRECTORY_VARIABLE "HOME"
#else
#define USER_HOME_DIRECTORY_VARIABLE "USERPROFILE"
#endif
        if (char const* home = std::getenv(USER_HOME_DIRECTORY_VARIABLE))
            dataPath.replace(0, 1, home);
#undef USER_HOME_DIRECTORY_VARIABLE
    }

    if (reload)
    {
        if (dataPath != m_dataPath)
            TC_LOG_ERROR("server.loading", "DataDir option can't be changed at worldserver.conf reload, using current value ({}).", m_dataPath);
    }
    else
    {
        m_dataPath = std::move(dataPath);
        TC_LOG_INFO("server.loading", "Using DataDir {}", m_dataPath);
    }

    TC_LOG_INFO("server.loading", "WORLD: MMap data directory is: {}mmaps", m_dataPath);

    bool enableLOS = sConfigMgr->GetBoolDefault("vmap.enableLOS"sv, true);
    bool enableHeight = sConfigMgr->GetBoolDefault("vmap.enableHeight"sv, true);

    if (!enableHeight)
        TC_LOG_ERROR("server.loading", "VMap height checking disabled! Creatures movements and other various things WILL be broken! Expect no support.");

    VMAP::VMapFactory::createOrGetVMapManager()->setEnableLineOfSightCalc(enableLOS);
    VMAP::VMapFactory::createOrGetVMapManager()->setEnableHeightCalc(enableHeight);
    TC_LOG_INFO("server.loading", "VMap support included. LineOfSight: {}, getHeight: {}, indoorCheck: {}", enableLOS, enableHeight, m_bool_configs[CONFIG_VMAP_INDOOR_CHECK]);
    TC_LOG_INFO("server.loading", "VMap data directory is: {}vmaps", m_dataPath);

    if (m_bool_configs[CONFIG_START_ALL_SPELLS])
        TC_LOG_WARN("server.loading", "PlayerStart.AllSpells enabled - may not function as intended!");

    //packet spoof punishment
    if (m_int_configs[CONFIG_PACKET_SPOOF_BANMODE] == BAN_CHARACTER)
        m_int_configs[CONFIG_PACKET_SPOOF_BANMODE] = BAN_ACCOUNT;

    _gameRules =
    {
        { .Rule = ::GameRule::TransmogEnabled, .Value = true },
        { .Rule = ::GameRule::HousingEnabled, .Value = true }
    };

    if (reload)
    {
        sSupportMgr->SetSupportSystemStatus(m_bool_configs[CONFIG_SUPPORT_ENABLED]);
        sSupportMgr->SetTicketSystemStatus(m_bool_configs[CONFIG_SUPPORT_TICKETS_ENABLED]);
        sSupportMgr->SetBugSystemStatus(m_bool_configs[CONFIG_SUPPORT_BUGS_ENABLED]);
        sSupportMgr->SetComplaintSystemStatus(m_bool_configs[CONFIG_SUPPORT_COMPLAINTS_ENABLED]);
        sSupportMgr->SetSuggestionSystemStatus(m_bool_configs[CONFIG_SUPPORT_SUGGESTIONS_ENABLED]);
        sMapMgr->SetGridCleanUpDelay(m_int_configs[CONFIG_INTERVAL_GRIDCLEAN]);
        sMapMgr->SetMapUpdateInterval(m_int_configs[CONFIG_INTERVAL_MAPUPDATE]);
        m_timers[WUPDATE_UPTIME].SetInterval(m_int_configs[CONFIG_UPTIME_UPDATE] * MINUTE * IN_MILLISECONDS);
        m_timers[WUPDATE_UPTIME].Reset();
        m_timers[WUPDATE_CLEANDB].SetInterval(m_int_configs[CONFIG_LOGDB_CLEARINTERVAL] * MINUTE * IN_MILLISECONDS);
        m_timers[WUPDATE_CLEANDB].Reset();
        m_timers[WUPDATE_AUTOBROADCAST].SetInterval(m_int_configs[CONFIG_AUTOBROADCAST_INTERVAL]);
        m_timers[WUPDATE_AUTOBROADCAST].Reset();
        sWorldStateMgr->SetValue(WS_CURRENT_PVP_SEASON_ID, getBoolConfig(CONFIG_ARENA_SEASON_IN_PROGRESS) ? getIntConfig(CONFIG_ARENA_SEASON_ID) : 0, false, nullptr);
        sWorldStateMgr->SetValue(WS_PREVIOUS_PVP_SEASON_ID, getIntConfig(CONFIG_ARENA_SEASON_ID) - getBoolConfig(CONFIG_ARENA_SEASON_IN_PROGRESS), false, nullptr);

        // call ScriptMgr if we're reloading the configuration
        sScriptMgr->OnConfigLoad(reload);
    }
}

/// Initialize the World
bool World::SetInitialWorldSettings()
{
    sLog->SetRealmId(sRealmList->GetCurrentRealmId().Realm);

    ///- Server startup begin
    uint32 startupBegin = getMSTime();

    ///- Initialize the random number generator
    srand((unsigned int)GameTime::GetGameTime());

    ///- Initialize detour memory management
    dtAllocSetCustom(dtCustomAlloc, dtCustomFree);

    ///- Initialize VMapManager function pointers (to untangle game/collision circular deps)
    VMAP::VMapManager* vmmgr2 = VMAP::VMapFactory::createOrGetVMapManager();
    vmmgr2->GetLiquidFlagsPtr = &DB2Manager::GetLiquidFlags;
    vmmgr2->IsVMAPDisabledForPtr = &DisableMgr::IsVMAPDisabledFor;

    ///- Initialize config settings
    LoadConfigSettings();

    ///- Initialize Allowed Security Level
    LoadDBAllowedSecurityLevel();

    ///- Init highest guids before any table loading to prevent using not initialized guids in some code.
    sObjectMgr->SetHighestGuids();

    ///- Check the existence of the map files for all races' startup areas.
    if (!TerrainMgr::ExistMapAndVMap(0, -6240.32f, 331.033f)
        || !TerrainMgr::ExistMapAndVMap(0, -8949.95f, -132.493f)
        || !TerrainMgr::ExistMapAndVMap(1, -618.518f, -4251.67f)
        || !TerrainMgr::ExistMapAndVMap(0, 1676.35f, 1677.45f)
        || !TerrainMgr::ExistMapAndVMap(1, 10311.3f, 832.463f)
        || !TerrainMgr::ExistMapAndVMap(1, -2917.58f, -257.98f)
        || (m_int_configs[CONFIG_EXPANSION] && (
            !TerrainMgr::ExistMapAndVMap(530, 10349.6f, -6357.29f) ||
            !TerrainMgr::ExistMapAndVMap(530, -3961.64f, -13931.2f))))
    {
        TC_LOG_FATAL("server.loading", "Unable to load map and vmap data for starting zones - server shutting down!");
        return false;
    }

    ///- Initialize pool manager
    sPoolMgr->Initialize();

    ///- Initialize game event manager
    sGameEventMgr->Initialize();

    ///- Loading strings. Getting no records means core load has to be canceled because no error message can be output.

    TC_LOG_INFO("server.loading", "Loading Trinity strings...");
    if (!sObjectMgr->LoadTrinityStrings())
        return false;                                       // Error message displayed in function already

    ///- Update the realm entry in the database with the realm type from the config file
    //No SQL injection as values are treated as integers

    // not send custom type REALM_FFA_PVP to realm list
    uint32 server_type = IsFFAPvPRealm() ? uint32(REALM_TYPE_PVP) : getIntConfig(CONFIG_GAME_TYPE);
    uint32 realm_zone = getIntConfig(CONFIG_REALM_ZONE);

    LoginDatabase.PExecute("UPDATE realmlist SET icon = {}, timezone = {} WHERE id = '{}'", server_type, realm_zone, sRealmList->GetCurrentRealmId().Realm);      // One-time query

    TC_LOG_INFO("server.loading", "Loading GameObject models...");
    if (!LoadGameObjectModelList(m_dataPath))
    {
        TC_LOG_FATAL("server.loading", "Unable to load gameobject models (part of vmaps), objects using WMO models will crash the client - server shutting down!");
        return false;
    }

    TC_LOG_INFO("server.loading", "Initialize data stores...");
    ///- Load DB2s
    m_availableDbcLocaleMask = sDB2Manager.LoadStores(m_dataPath, m_defaultDbcLocale);
    if (!(m_availableDbcLocaleMask & (1 << m_defaultDbcLocale)))
    {
        TC_LOG_FATAL("server.loading", "Unable to load db2 files for {} locale specified in DBC.Locale config!", localeNames[m_defaultDbcLocale]);
        return false;
    }

    TC_LOG_INFO("server.loading", "Loading hotfix blobs...");
    sDB2Manager.LoadHotfixBlob(m_availableDbcLocaleMask);
    TC_LOG_INFO("server.loading", "Loading hotfix info...");
    sDB2Manager.LoadHotfixData(m_availableDbcLocaleMask);
    TC_LOG_INFO("server.loading", "Loading hotfix optional data...");
    sDB2Manager.LoadHotfixOptionalData(m_availableDbcLocaleMask);
    TC_LOG_INFO("server.loading", "Indexing loaded data stores...");
    sDB2Manager.IndexLoadedStores();
    ///- Load M2 fly by cameras
    LoadM2Cameras(m_dataPath);
    ///- Load GameTables
    LoadGameTables(m_dataPath);

    //Load weighted graph on taxi nodes path
    TaxiPathGraph::Initialize();
    // Load IP Location Database
    sIPLocation->Load();

    // always use declined names in the russian client
    if (Cfg_CategoriesEntry const* category = sCfgCategoriesStore.LookupEntry(m_int_configs[CONFIG_REALM_ZONE]))
        if (category->GetCreateCharsetMask().HasFlag(CfgCategoriesCharsets::Russian))
            m_bool_configs[CONFIG_DECLINED_NAMES_USED] = true;

    std::unordered_map<uint32, std::vector<uint32>> mapData;
    for (MapEntry const* mapEntry : sMapStore)
    {
        mapData.emplace(std::piecewise_construct, std::forward_as_tuple(mapEntry->ID), std::forward_as_tuple());
        if (mapEntry->ParentMapID != -1)
        {
            ASSERT(mapEntry->CosmeticParentMapID == -1 || mapEntry->ParentMapID == mapEntry->CosmeticParentMapID,
                "Inconsistent parent map data for map %u (ParentMapID = %hd, CosmeticParentMapID = %hd)",
                mapEntry->ID, mapEntry->ParentMapID, mapEntry->CosmeticParentMapID);

            mapData[mapEntry->ParentMapID].push_back(mapEntry->ID);
        }
        else if (mapEntry->CosmeticParentMapID != -1)
            mapData[mapEntry->CosmeticParentMapID].push_back(mapEntry->ID);
    }

    sTerrainMgr.InitializeParentMapData(mapData);

    vmmgr2->InitializeThreadUnsafe(mapData);

    MMAP::MMapManager* mmmgr = MMAP::MMapManager::instance();
    mmmgr->InitializeThreadUnsafe(mapData);

    ///- Initialize static helper structures
    AIRegistry::Initialize();

    TC_LOG_INFO("server.loading", "Initializing PlayerDump tables...");
    PlayerDump::InitializeTables();

    TC_LOG_INFO("server.loading", "Loading SpellInfo store...");
    sSpellMgr->LoadSpellInfoStore();

    TC_LOG_INFO("server.loading", "Loading serverside spells...");
    sSpellMgr->LoadSpellInfoServerside();

    TC_LOG_INFO("server.loading", "Loading SpellInfo corrections...");
    sSpellMgr->LoadSpellInfoCorrections();

    TC_LOG_INFO("server.loading", "Loading SkillLineAbilityMultiMap Data...");
    sSpellMgr->LoadSkillLineAbilityMap();

    TC_LOG_INFO("server.loading", "Loading SpellInfo custom attributes...");
    sSpellMgr->LoadSpellInfoCustomAttributes();

    TC_LOG_INFO("server.loading", "Loading SpellInfo diminishing infos...");
    sSpellMgr->LoadSpellInfoDiminishing();

    TC_LOG_INFO("server.loading", "Loading SpellInfo immunity infos...");
    sSpellMgr->LoadSpellInfoImmunities();

    TC_LOG_INFO("server.loading", "Loading SpellInfo target caps...");
    sSpellMgr->LoadSpellInfoTargetCaps();

    TC_LOG_INFO("server.loading", "Loading PetFamilySpellsStore Data...");
    sSpellMgr->LoadPetFamilySpellsStore();

    TC_LOG_INFO("server.loading", "Loading Spell Totem models...");
    sSpellMgr->LoadSpellTotemModel();

    TC_LOG_INFO("server.loading", "Loading Traits...");
    TraitMgr::Load();

    TC_LOG_INFO("server.loading", "Loading languages...");  // must be after LoadSpellInfoStore and LoadSkillLineAbilityMap
    sLanguageMgr->LoadLanguages();

    TC_LOG_INFO("server.loading", "Loading languages words...");
    sLanguageMgr->LoadLanguagesWords();

    TC_LOG_INFO("server.loading", "Loading Instance Template...");
    sObjectMgr->LoadInstanceTemplate();

    // Must be called before `respawn` data
    TC_LOG_INFO("server.loading", "Loading instances...");
    sMapMgr->InitInstanceIds();
    sInstanceLockMgr.Load();

    TC_LOG_INFO("server.loading", "Loading Localization strings...");
    uint32 oldMSTime = getMSTime();
    if (m_bool_configs[CONFIG_LOAD_LOCALES])
    {
        sObjectMgr->LoadCreatureLocales();
        sObjectMgr->LoadGameObjectLocales();
        sObjectMgr->LoadQuestTemplateLocale();
        sObjectMgr->LoadQuestOfferRewardLocale();
        sObjectMgr->LoadQuestRequestItemsLocale();
        sObjectMgr->LoadQuestObjectivesLocale();
        sObjectMgr->LoadPageTextLocales();
        sObjectMgr->LoadGossipMenuItemsLocales();
        sObjectMgr->LoadPointOfInterestLocales();
    }

    sObjectMgr->SetDBCLocaleIndex(GetDefaultDbcLocale());        // Get once for all the locale index of DBC language (console/broadcasts)
    TC_LOG_INFO("server.loading", ">> Localization strings loaded in {} ms", GetMSTimeDiffToNow(oldMSTime));

    TC_LOG_INFO("server.loading", "Loading Account Roles and Permissions...");
    sAccountMgr->LoadRBAC();

    TC_LOG_INFO("server.loading", "Loading Page Texts...");
    sObjectMgr->LoadPageTexts();

    TC_LOG_INFO("server.loading", "Loading Game Object Templates...");         // must be after LoadPageTexts
    sObjectMgr->LoadDestructibleHitpoints();
    sObjectMgr->LoadGameObjectTemplate();

    TC_LOG_INFO("server.loading", "Loading Game Object template addons...");
    sObjectMgr->LoadGameObjectTemplateAddons();

    TC_LOG_INFO("server.loading", "Loading Transport templates...");
    sTransportMgr->LoadTransportTemplates();

    TC_LOG_INFO("server.loading", "Loading Transport animations and rotations...");
    sTransportMgr->LoadTransportAnimationAndRotation();

    TC_LOG_INFO("server.loading", "Loading Transport spawns...");
    sTransportMgr->LoadTransportSpawns();

    TC_LOG_INFO("server.loading", "Loading Spell Rank Data...");
    sSpellMgr->LoadSpellRanks();

    TC_LOG_INFO("server.loading", "Loading Spell Required Data...");
    sSpellMgr->LoadSpellRequired();

    TC_LOG_INFO("server.loading", "Loading Spell Group types...");
    sSpellMgr->LoadSpellGroups();

    TC_LOG_INFO("server.loading", "Loading Spell Learn Skills...");
    sSpellMgr->LoadSpellLearnSkills();                           // must be after LoadSpellRanks

    TC_LOG_INFO("server.loading", "Loading SpellInfo SpellSpecific and AuraState...");
    sSpellMgr->LoadSpellInfoSpellSpecificAndAuraState();         // must be after LoadSpellRanks

    TC_LOG_INFO("server.loading", "Loading Spell Learn Spells...");
    sSpellMgr->LoadSpellLearnSpells();

    TC_LOG_INFO("server.loading", "Loading Spell Proc conditions and data...");
    sSpellMgr->LoadSpellProcs();

    TC_LOG_INFO("server.loading", "Loading Aggro Spells Definitions...");
    sSpellMgr->LoadSpellThreats();

    TC_LOG_INFO("server.loading", "Loading Spell Group Stack Rules...");
    sSpellMgr->LoadSpellGroupStackRules();

    TC_LOG_INFO("server.loading", "Loading NPC Texts...");
    sObjectMgr->LoadNPCText();

    TC_LOG_INFO("server.loading", "Loading Enchant Spells Proc datas...");
    sSpellMgr->LoadSpellEnchantProcData();

    TC_LOG_INFO("server.loading", "Loading item bonus data...");
    ItemBonusMgr::Load();

    TC_LOG_INFO("server.loading", "Loading Random item bonus list definitions...");
    LoadItemRandomBonusListTemplates();

    TC_LOG_INFO("server.loading", "Loading Disables");                         // must be before loading quests and items
    DisableMgr::LoadDisables();

    TC_LOG_INFO("server.loading", "Loading Items...");                         // must be after LoadRandomEnchantmentsTable and LoadPageTexts
    sObjectMgr->LoadItemTemplates();

    TC_LOG_INFO("server.loading", "Loading Item set names...");                // must be after LoadItemPrototypes
    sObjectMgr->LoadItemTemplateAddon();

    TC_LOG_INFO("misc", "Loading Item Scripts...");                 // must be after LoadItemPrototypes
    sObjectMgr->LoadItemScriptNames();

    TC_LOG_INFO("server.loading", "Loading Creature Model Based Info Data...");
    sObjectMgr->LoadCreatureModelInfo();

    TC_LOG_INFO("server.loading", "Loading Creature templates...");
    sObjectMgr->LoadCreatureTemplates();

    TC_LOG_INFO("server.loading", "Loading Equipment templates...");           // must be after LoadCreatureTemplates
    sObjectMgr->LoadEquipmentTemplates();

    TC_LOG_INFO("server.loading", "Loading Creature template addons...");
    sObjectMgr->LoadCreatureTemplateAddons();

    TC_LOG_INFO("server.loading", "Loading Creature template difficulty...");
    sObjectMgr->LoadCreatureTemplateDifficulty();

    TC_LOG_INFO("server.loading", "Loading Creature template sparring...");
    sObjectMgr->LoadCreatureTemplateSparring();

    TC_LOG_INFO("server.loading", "Loading Reputation Reward Rates...");
    sObjectMgr->LoadReputationRewardRate();

    TC_LOG_INFO("server.loading", "Loading Creature Reputation OnKill Data...");
    sObjectMgr->LoadReputationOnKill();

    TC_LOG_INFO("server.loading", "Loading Reputation Spillover Data...");
    sObjectMgr->LoadReputationSpilloverTemplate();

    TC_LOG_INFO("server.loading", "Loading Points Of Interest Data...");
    sObjectMgr->LoadPointsOfInterest();

    TC_LOG_INFO("server.loading", "Loading Creature Base Stats...");
    sObjectMgr->LoadCreatureClassLevelStats();

    TC_LOG_INFO("server.loading", "Loading Spawn Group Templates...");
    sObjectMgr->LoadSpawnGroupTemplates();

    TC_LOG_INFO("server.loading", "Loading Creature Data...");
    sObjectMgr->LoadCreatures();

    TC_LOG_INFO("server.loading", "Loading Temporary Summon Data...");
    sObjectMgr->LoadTempSummons();                               // must be after LoadCreatureTemplates() and LoadGameObjectTemplates()

    TC_LOG_INFO("server.loading", "Loading pet levelup spells...");
    sSpellMgr->LoadPetLevelupSpellMap();

    TC_LOG_INFO("server.loading", "Loading pet default spells additional to levelup spells...");
    sSpellMgr->LoadPetDefaultSpells();

    TC_LOG_INFO("server.loading", "Loading Creature Addon Data...");
    sObjectMgr->LoadCreatureAddons();                            // must be after LoadCreatureTemplates() and LoadCreatures()

    TC_LOG_INFO("server.loading", "Loading Creature Movement Overrides...");
    sObjectMgr->LoadCreatureMovementOverrides();                 // must be after LoadCreatures()

    TC_LOG_INFO("server.loading", "Loading Gameobject Data...");
    sObjectMgr->LoadGameObjects();

    TC_LOG_INFO("server.loading", "Loading Spawn Group Data...");
    sObjectMgr->LoadSpawnGroups();

    TC_LOG_INFO("server.loading", "Loading instance spawn groups...");
    sObjectMgr->LoadInstanceSpawnGroups();

    TC_LOG_INFO("server.loading", "Loading GameObject Addon Data...");
    sObjectMgr->LoadGameObjectAddons();                          // must be after LoadGameObjects()

    TC_LOG_INFO("server.loading", "Loading GameObject faction and flags overrides...");
    sObjectMgr->LoadGameObjectOverrides();                       // must be after LoadGameObjects()

    TC_LOG_INFO("server.loading", "Loading GameObject Quest Items...");
    sObjectMgr->LoadGameObjectQuestItems();

    TC_LOG_INFO("server.loading", "Loading Creature Quest Items...");
    sObjectMgr->LoadCreatureQuestItems();

    TC_LOG_INFO("server.loading", "Loading Creature Quest Currencies...");
    sObjectMgr->LoadCreatureQuestCurrencies();

    TC_LOG_INFO("server.loading", "Loading Creature Linked Respawn...");
    sObjectMgr->LoadLinkedRespawn();                             // must be after LoadCreatures(), LoadGameObjects()

    TC_LOG_INFO("server.loading", "Loading Weather Data...");
    WeatherMgr::LoadWeatherData();

    TC_LOG_INFO("server.loading", "Loading Quests...");
    sObjectMgr->LoadQuests();                                    // must be loaded after DBCs, creature_template, items, gameobject tables

    TC_LOG_INFO("server.loading", "Checking Quest Disables");
    DisableMgr::CheckQuestDisables();                           // must be after loading quests

    TC_LOG_INFO("server.loading", "Loading Quest POI");
    sObjectMgr->LoadQuestPOI();

    TC_LOG_INFO("server.loading", "Loading Quests Starters and Enders...");
    sObjectMgr->LoadQuestStartersAndEnders();                    // must be after quest load

    TC_LOG_INFO("server.loading", "Loading Quest Greetings...");
    sObjectMgr->LoadQuestGreetings();

    if (m_bool_configs[CONFIG_LOAD_LOCALES])
        sObjectMgr->LoadQuestGreetingLocales();

    TC_LOG_INFO("server.loading", "Loading Objects Pooling Data...");
    sPoolMgr->LoadFromDB();
    TC_LOG_INFO("server.loading", "Loading Quest Pooling Data...");
    sQuestPoolMgr->LoadFromDB();                                // must be after quest templates

    TC_LOG_INFO("server.loading", "Loading World State templates...");
    sWorldStateMgr->LoadFromDB();                               // must be loaded before battleground, outdoor PvP, game events and conditions

    TC_LOG_INFO("server.loading", "Loading Game Event Data...");               // must be after loading pools fully
    sGameEventMgr->LoadFromDB();

    TC_LOG_INFO("server.loading", "Loading creature summoned data...");
    sObjectMgr->LoadCreatureSummonedData();                     // must be after LoadCreatureTemplates() and LoadQuests()

    TC_LOG_INFO("server.loading", "Loading UNIT_NPC_FLAG_SPELLCLICK Data..."); // must be after LoadQuests
    sObjectMgr->LoadNPCSpellClickSpells();

    TC_LOG_INFO("server.loading", "Loading Vehicle Templates...");
    sObjectMgr->LoadVehicleTemplate();                          // must be after LoadCreatureTemplates()

    TC_LOG_INFO("server.loading", "Loading Vehicle Template Accessories...");
    sObjectMgr->LoadVehicleTemplateAccessories();                // must be after LoadCreatureTemplates() and LoadNPCSpellClickSpells()

    TC_LOG_INFO("server.loading", "Loading Vehicle Accessories...");
    sObjectMgr->LoadVehicleAccessories();                       // must be after LoadCreatureTemplates() and LoadNPCSpellClickSpells()

    TC_LOG_INFO("server.loading", "Loading Vehicle Seat Addon Data...");
    sObjectMgr->LoadVehicleSeatAddon();                         // must be after loading DBC

    TC_LOG_INFO("server.loading", "Loading SpellArea Data...");                // must be after quest load
    sSpellMgr->LoadSpellAreas();

    TC_LOG_INFO("server.loading", "Loading World locations...");
    sObjectMgr->LoadWorldSafeLocs();                            // must be before LoadAreaTriggerTeleports and LoadGraveyardZones

    TC_LOG_INFO("server.loading", "Loading Area Trigger Teleports definitions...");
    sObjectMgr->LoadAreaTriggerTeleports();

    TC_LOG_INFO("server.loading", "Loading Area Trigger Polygon data...");
    sObjectMgr->LoadAreaTriggerPolygons();

    TC_LOG_INFO("server.loading", "Loading Access Requirements...");
    sObjectMgr->LoadAccessRequirements();                        // must be after item template load

    TC_LOG_INFO("server.loading", "Loading Quest Area Triggers...");
    sObjectMgr->LoadQuestAreaTriggers();                         // must be after LoadQuests

    TC_LOG_INFO("server.loading", "Loading Tavern Area Triggers...");
    sObjectMgr->LoadTavernAreaTriggers();

    TC_LOG_INFO("server.loading", "Loading AreaTrigger script names...");
    sObjectMgr->LoadAreaTriggerScripts();

    TC_LOG_INFO("server.loading", "Loading LFG entrance positions..."); // Must be after areatriggers
    sLFGMgr->LoadLFGDungeons();

    TC_LOG_INFO("server.loading", "Loading LFG rewards...");
    sLFGMgr->LoadRewards();

    TC_LOG_INFO("server.loading", "Loading Graveyard-zone links...");
    sObjectMgr->LoadGraveyardZones();

    TC_LOG_INFO("server.loading", "Loading spell pet auras...");
    sSpellMgr->LoadSpellPetAuras();

    TC_LOG_INFO("server.loading", "Loading Spell target coordinates...");
    sSpellMgr->LoadSpellTargetPositions();

    TC_LOG_INFO("server.loading", "Loading linked spells...");
    sSpellMgr->LoadSpellLinked();

    TC_LOG_INFO("server.loading", "Loading Scenes Templates..."); // must be before LoadPlayerInfo
    sObjectMgr->LoadSceneTemplates();

    TC_LOG_INFO("server.loading", "Loading Player Create Data...");
    sObjectMgr->LoadPlayerInfo();

    TC_LOG_INFO("server.loading", "Loading Exploration BaseXP Data...");
    sObjectMgr->LoadExplorationBaseXP();

    TC_LOG_INFO("server.loading", "Loading Pet Name Parts...");
    sObjectMgr->LoadPetNames();

    TC_LOG_INFO("server.loading", "Loading AreaTrigger Templates...");
    sAreaTriggerDataStore->LoadAreaTriggerTemplates();

    TC_LOG_INFO("server.loading", "Loading AreaTrigger Spawns...");
    sAreaTriggerDataStore->LoadAreaTriggerSpawns();

    TC_LOG_INFO("server.loading", "Loading Conversation Templates...");
    sConversationDataStore->LoadConversationTemplates();

    TC_LOG_INFO("server.loading", "Loading Player Choices...");
    sObjectMgr->LoadPlayerChoices();

    TC_LOG_INFO("server.loading", "Loading Spawn Tracking Templates...");
    sObjectMgr->LoadSpawnTrackingTemplates();

    TC_LOG_INFO("server.loading", "Loading Spawn Tracking Quest Objectives...");
    sObjectMgr->LoadSpawnTrackingQuestObjectives();

    TC_LOG_INFO("server.loading", "Loading Spawn Tracking Spawns...");
    sObjectMgr->LoadSpawnTrackings();

    TC_LOG_INFO("server.loading", "Loading Spawn Tracking Spawn States...");
    sObjectMgr->LoadSpawnTrackingStates();

    if (m_bool_configs[CONFIG_LOAD_LOCALES])
    {
        TC_LOG_INFO("server.loading", "Loading Player Choices Locales...");
        sObjectMgr->LoadPlayerChoicesLocale();
    }

    TC_LOG_INFO("server.loading", "Loading UIMap questlines...");
    sObjectMgr->LoadUiMapQuestLines();

    TC_LOG_INFO("server.loading", "Loading UIMap quests...");
    sObjectMgr->LoadUiMapQuests();

    TC_LOG_INFO("server.loading", "Loading Jump Charge Params...");
    sObjectMgr->LoadJumpChargeParams();

    CharacterDatabaseCleaner::CleanDatabase();

    TC_LOG_INFO("server.loading", "Loading the max pet number...");
    sObjectMgr->LoadPetNumber();

    TC_LOG_INFO("server.loading", "Loading pet level stats...");
    sObjectMgr->LoadPetLevelInfo();

    TC_LOG_INFO("server.loading", "Loading Player level dependent mail rewards...");
    sObjectMgr->LoadMailLevelRewards();

    // Loot tables
    LoadLootTables();

    TC_LOG_INFO("server.loading", "Loading Skill Discovery Table...");
    LoadSkillDiscoveryTable();

    TC_LOG_INFO("server.loading", "Loading Skill Extra Item Table...");
    LoadSkillExtraItemTable();

    TC_LOG_INFO("server.loading", "Loading Skill Perfection Data Table...");
    LoadSkillPerfectItemTable();

    TC_LOG_INFO("server.loading", "Loading Skill Fishing base level requirements...");
    sObjectMgr->LoadFishingBaseSkillLevel();

    TC_LOG_INFO("server.loading", "Loading skill tier info...");
    sObjectMgr->LoadSkillTiers();

    TC_LOG_INFO("server.loading", "Loading Criteria Modifier trees...");
    sCriteriaMgr->LoadCriteriaModifiersTree();
    TC_LOG_INFO("server.loading", "Loading Criteria Lists...");
    sCriteriaMgr->LoadCriteriaList();
    TC_LOG_INFO("server.loading", "Loading Criteria Data...");
    sCriteriaMgr->LoadCriteriaData();
    TC_LOG_INFO("server.loading", "Loading Achievements...");
    sAchievementMgr->LoadAchievementReferenceList();
    TC_LOG_INFO("server.loading", "Loading Achievements Scripts...");
    sAchievementMgr->LoadAchievementScripts();
    TC_LOG_INFO("server.loading", "Loading Achievement Rewards...");
    sAchievementMgr->LoadRewards();

    if (m_bool_configs[CONFIG_LOAD_LOCALES])
    {
        TC_LOG_INFO("server.loading", "Loading Achievement Reward Locales...");
        sAchievementMgr->LoadRewardLocales();
    }
    TC_LOG_INFO("server.loading", "Loading Completed Achievements...");
    sAchievementMgr->LoadCompletedAchievements();

    // Load before guilds and arena teams
    TC_LOG_INFO("server.loading", "Loading character cache store...");
    sCharacterCache->LoadCharacterCacheStorage();

    ///- Load dynamic data tables from the database
    TC_LOG_INFO("server.loading", "Loading Auctions...");
    sAuctionMgr->LoadAuctions();

    if (m_bool_configs[CONFIG_BLACKMARKET_ENABLED])
    {
        TC_LOG_INFO("server.loading", "Loading Black Market Templates...");
        sBlackMarketMgr->LoadTemplates();

        TC_LOG_INFO("server.loading", "Loading Black Market Auctions...");
        sBlackMarketMgr->LoadAuctions();
    }

    TC_LOG_INFO("server.loading", "Loading Guild rewards...");
    sGuildMgr->LoadGuildRewards();

    TC_LOG_INFO("server.loading", "Loading Guilds...");
    sGuildMgr->LoadGuilds();

    TC_LOG_INFO("server.loading", "Loading ArenaTeams...");
    sArenaTeamMgr->LoadArenaTeams();

    TC_LOG_INFO("server.loading", "Loading Groups...");
    sGroupMgr->LoadGroups();

    TC_LOG_INFO("server.loading", "Loading ReservedNames...");
    sObjectMgr->LoadReservedPlayersNames();

    TC_LOG_INFO("server.loading", "Loading GameObjects for quests...");
    sObjectMgr->LoadGameObjectForQuests();

    TC_LOG_INFO("server.loading", "Loading BattleMasters...");
    sBattlegroundMgr->LoadBattleMastersEntry();                 // must be after load CreatureTemplate

    TC_LOG_INFO("server.loading", "Loading GameTeleports...");
    sObjectMgr->LoadGameTele();

    TC_LOG_INFO("server.loading", "Loading Trainers...");
    sObjectMgr->LoadTrainers();                                 // must be after load CreatureTemplate

    TC_LOG_INFO("server.loading", "Loading Gossip menu...");
    sObjectMgr->LoadGossipMenu();

    TC_LOG_INFO("server.loading", "Loading Gossip menu options...");
    sObjectMgr->LoadGossipMenuItems();

    TC_LOG_INFO("server.loading", "Loading Gossip menu addon...");
    sObjectMgr->LoadGossipMenuAddon();

    TC_LOG_INFO("server.loading", "Loading Creature Template Gossip...");
    sObjectMgr->LoadCreatureTemplateGossip();

    TC_LOG_INFO("server.loading", "Loading Creature trainers...");
    sObjectMgr->LoadCreatureTrainers();                         // must be after LoadGossipMenuItems

    TC_LOG_INFO("server.loading", "Loading Vendors...");
    sObjectMgr->LoadVendors();                                  // must be after load CreatureTemplate and ItemTemplate

    TC_LOG_INFO("server.loading", "Loading Waypoint paths...");
    sWaypointMgr->LoadPaths();

    TC_LOG_INFO("server.loading", "Loading Creature Formations...");
    sFormationMgr->LoadCreatureFormations();

    TC_LOG_INFO("server.loading", "Loading Persistend World Variables...");
    LoadPersistentWorldVariables();

    sWorldStateMgr->SetValue(WS_CURRENT_PVP_SEASON_ID, getBoolConfig(CONFIG_ARENA_SEASON_IN_PROGRESS) ? getIntConfig(CONFIG_ARENA_SEASON_ID) : 0, false, nullptr);
    sWorldStateMgr->SetValue(WS_PREVIOUS_PVP_SEASON_ID, getIntConfig(CONFIG_ARENA_SEASON_ID) - getBoolConfig(CONFIG_ARENA_SEASON_IN_PROGRESS), false, nullptr);

    sObjectMgr->LoadPhases();

    TC_LOG_INFO("server.loading", "Loading Conditions...");
    sConditionMgr->LoadConditions();

    TC_LOG_INFO("server.loading", "Loading faction change achievement pairs...");
    sObjectMgr->LoadFactionChangeAchievements();

    TC_LOG_INFO("server.loading", "Loading faction change spell pairs...");
    sObjectMgr->LoadFactionChangeSpells();

    TC_LOG_INFO("server.loading", "Loading faction change quest pairs...");
    sObjectMgr->LoadFactionChangeQuests();

    TC_LOG_INFO("server.loading", "Loading faction change item pairs...");
    sObjectMgr->LoadFactionChangeItems();

    TC_LOG_INFO("server.loading", "Loading faction change reputation pairs...");
    sObjectMgr->LoadFactionChangeReputations();

    TC_LOG_INFO("server.loading", "Loading faction change title pairs...");
    sObjectMgr->LoadFactionChangeTitles();

    TC_LOG_INFO("server.loading", "Loading mount definitions...");
    CollectionMgr::LoadMountDefinitions();

    TC_LOG_INFO("server.loading", "Loading warband scene definitions...");
    CollectionMgr::LoadWarbandSceneDefinitions();

    TC_LOG_INFO("server.loading", "Loading GM bugs...");
    sSupportMgr->LoadBugTickets();

    TC_LOG_INFO("server.loading", "Loading GM complaints...");
    sSupportMgr->LoadComplaintTickets();

    TC_LOG_INFO("server.loading", "Loading GM suggestions...");
    sSupportMgr->LoadSuggestionTickets();

    /*TC_LOG_INFO("server.loading", "Loading GM surveys...");
    sSupportMgr->LoadSurveys();*/

    TC_LOG_INFO("server.loading", "Loading garrison info...");
    sGarrisonMgr.Initialize();

    ///- Handle outdated emails (delete/return)
    TC_LOG_INFO("server.loading", "Returning old mails...");
    sObjectMgr->ReturnOrDeleteOldMails(false);

    TC_LOG_INFO("server.loading", "Loading Autobroadcasts...");
    LoadAutobroadcasts();

    ///- Load and initialize scripts
    sObjectMgr->LoadSpellScripts();                              // must be after load Creature/Gameobject(Template/Data)
    sObjectMgr->LoadEventScripts();                              // must be after load Creature/Gameobject(Template/Data)

    TC_LOG_INFO("server.loading", "Loading spell script names...");
    sObjectMgr->LoadSpellScriptNames();

    TC_LOG_INFO("server.loading", "Loading Creature Texts...");
    sCreatureTextMgr->LoadCreatureTexts();

    if (m_bool_configs[CONFIG_LOAD_LOCALES])
    {
        TC_LOG_INFO("server.loading", "Loading Creature Text Locales...");
        sCreatureTextMgr->LoadCreatureTextLocales();
    }

    TC_LOG_INFO("server.loading", "Loading creature StaticFlags overrides...");
    sObjectMgr->LoadCreatureStaticFlagsOverride(); // must be after LoadCreatures

    TC_LOG_INFO("server.loading", "Initializing Scripts...");
    sScriptMgr->Initialize();
    sScriptMgr->OnConfigLoad(false);                                // must be done after the ScriptMgr has been properly initialized

    TC_LOG_INFO("server.loading", "Validating spell scripts...");
    sObjectMgr->ValidateSpellScripts();

    TC_LOG_INFO("server.loading", "Loading SmartAI scripts...");
    sSmartScriptMgr->LoadSmartAIFromDB();

    TC_LOG_INFO("server.loading", "Loading Calendar data...");
    sCalendarMgr->LoadFromDB();

    TC_LOG_INFO("server.loading", "Loading Petitions...");
    sPetitionMgr->LoadPetitions();

    TC_LOG_INFO("server.loading", "Loading Signatures...");
    sPetitionMgr->LoadSignatures();

    TC_LOG_INFO("server.loading", "Loading Item loot...");
    sLootItemStorage->LoadStorageFromDB();

    TC_LOG_INFO("server.loading", "Initialize query data...");
    sObjectMgr->InitializeQueriesData(QUERY_DATA_ALL);

    TC_LOG_INFO("server.loading", "Initialize commands...");
    Trinity::ChatCommands::LoadCommandMap();

    ///- Initialize game time and timers
    TC_LOG_INFO("server.loading", "Initialize game time and timers");
    GameTime::UpdateGameTimers();

    LoginDatabase.PExecute("INSERT INTO uptime (realmid, starttime, uptime, revision) VALUES({}, {}, 0, '{}')",
        sRealmList->GetCurrentRealmId().Realm, uint32(GameTime::GetStartTime()), GitRevision::GetFullVersion());    // One-time query

    m_timers[WUPDATE_AUCTIONS].SetInterval(MINUTE*IN_MILLISECONDS);
    m_timers[WUPDATE_AUCTIONS_PENDING].SetInterval(250);
    m_timers[WUPDATE_UPTIME].SetInterval(m_int_configs[CONFIG_UPTIME_UPDATE]*MINUTE*IN_MILLISECONDS);
                                                            //Update "uptime" table based on configuration entry in minutes.
    m_timers[WUPDATE_CORPSES].SetInterval(20 * MINUTE * IN_MILLISECONDS);
                                                            //erase corpses every 20 minutes
    m_timers[WUPDATE_CLEANDB].SetInterval(m_int_configs[CONFIG_LOGDB_CLEARINTERVAL]*MINUTE*IN_MILLISECONDS);
                                                            // clean logs table every 14 days by default
    m_timers[WUPDATE_AUTOBROADCAST].SetInterval(getIntConfig(CONFIG_AUTOBROADCAST_INTERVAL));
    m_timers[WUPDATE_DELETECHARS].SetInterval(DAY*IN_MILLISECONDS); // check for chars to delete every day

    // for AhBot
    m_timers[WUPDATE_AHBOT].SetInterval(getIntConfig(CONFIG_AHBOT_UPDATE_INTERVAL) * IN_MILLISECONDS); // every 20 sec

    m_timers[WUPDATE_PINGDB].SetInterval(getIntConfig(CONFIG_DB_PING_INTERVAL)*MINUTE*IN_MILLISECONDS);    // Mysql ping time in minutes

    m_timers[WUPDATE_GUILDSAVE].SetInterval(getIntConfig(CONFIG_GUILD_SAVE_INTERVAL) * MINUTE * IN_MILLISECONDS);

    m_timers[WUPDATE_BLACKMARKET].SetInterval(10 * IN_MILLISECONDS);

    m_timers[WUPDATE_CHECK_FILECHANGES].SetInterval(500);

    m_timers[WUPDATE_WHO_LIST].SetInterval(5 * IN_MILLISECONDS); // update who list cache every 5 seconds

    m_timers[WUPDATE_CHANNEL_SAVE].SetInterval(getIntConfig(CONFIG_PRESERVE_CUSTOM_CHANNEL_INTERVAL) * MINUTE * IN_MILLISECONDS);

    //to set mailtimer to return mails every day between 4 and 5 am
    //mailtimer is increased when updating auctions
    //one second is 1000 -(tested on win system)
    /// @todo Get rid of magic numbers
    tm localTm;
    time_t gameTime = GameTime::GetGameTime();
    localtime_r(&gameTime, &localTm);
    uint8 CleanOldMailsTime = getIntConfig(CONFIG_CLEAN_OLD_MAIL_TIME);
    mail_timer = ((((localTm.tm_hour + (24 - CleanOldMailsTime)) % 24)* HOUR * IN_MILLISECONDS) / m_timers[WUPDATE_AUCTIONS].GetInterval());
                                                            //1440
    mail_timer_expires = ((DAY * IN_MILLISECONDS) / (m_timers[WUPDATE_AUCTIONS].GetInterval()));
    TC_LOG_INFO("server.loading", "Mail timer set to: {}, mail return is called every {} minutes", uint64(mail_timer), uint64(mail_timer_expires));

    ///- Initialize MapManager
    TC_LOG_INFO("server.loading", "Starting Map System");
    sMapMgr->Initialize();

    TC_LOG_INFO("server.loading", "Starting Game Event system...");
    uint32 nextGameEvent = sGameEventMgr->StartSystem();
    m_timers[WUPDATE_EVENTS].SetInterval(nextGameEvent);    //depend on next event

    // Delete all characters which have been deleted X days before
    Player::DeleteOldCharacters();

    TC_LOG_INFO("server.loading", "Initialize AuctionHouseBot...");
    sAuctionBot->Initialize();

    TC_LOG_INFO("server.loading", "Initializing chat channels...");
    ChannelMgr::LoadFromDB();

    TC_LOG_INFO("server.loading", "Initializing Opcodes...");
    opcodeTable.Initialize();
    WorldPackets::Auth::ConnectTo::InitializeEncryption();
    WorldPackets::Auth::EnterEncryptedMode::InitializeEncryption();

    TC_LOG_INFO("server.loading", "Starting Arena Season...");
    sGameEventMgr->StartArenaSeason();

    sSupportMgr->Initialize();

    ///- Initialize Battlegrounds
    TC_LOG_INFO("server.loading", "Starting Battleground System");
    sBattlegroundMgr->LoadBattlegroundTemplates();
    sBattlegroundMgr->LoadBattlegroundScriptTemplate();

    ///- Initialize outdoor pvp
    TC_LOG_INFO("server.loading", "Starting Outdoor PvP System");
    sOutdoorPvPMgr->InitOutdoorPvP();

    ///- Initialize Battlefield
    TC_LOG_INFO("server.loading", "Starting Battlefield System");
    sBattlefieldMgr->InitBattlefield();

    TC_LOG_INFO("server.loading", "Deleting expired bans...");
    LoginDatabase.Execute("DELETE FROM ip_banned WHERE unbandate <= UNIX_TIMESTAMP() AND unbandate<>bandate");      // One-time query

    TC_LOG_INFO("server.loading", "Initializing quest reset times...");
    InitQuestResetTimes();
    CheckScheduledResetTimes();

    TC_LOG_INFO("server.loading", "Calculate random battleground reset time...");
    InitRandomBGResetTime();

    TC_LOG_INFO("server.loading", "Calculate deletion of old calendar events time...");
    InitCalendarOldEventsDeletionTime();

    TC_LOG_INFO("server.loading", "Calculate guild limitation(s) reset time...");
    InitGuildResetTime();

    TC_LOG_INFO("server.loading", "Calculate next currency reset time...");
    InitCurrencyResetTime();

    TC_LOG_INFO("server.loading", "Loading race and class expansion requirements...");
    sObjectMgr->LoadRaceAndClassExpansionRequirements();

    TC_LOG_INFO("server.loading", "Loading character templates...");
    sCharacterTemplateDataStore->LoadCharacterTemplates();

    TC_LOG_INFO("server.loading", "Loading battle pets info...");
    BattlePets::BattlePetMgr::Initialize();

    TC_LOG_INFO("server.loading", "Loading scenarios");
    sScenarioMgr->LoadDB2Data();
    sScenarioMgr->LoadDBData();

    TC_LOG_INFO("server.loading", "Loading scenario poi data");
    sScenarioMgr->LoadScenarioPOI();

    TC_LOG_INFO("server.loading", "Loading phase names...");
    sObjectMgr->LoadPhaseNames();

    uint32 startupDuration = GetMSTimeDiffToNow(startupBegin);

    TC_LOG_INFO("server.worldserver", "World initialized in {} minutes {} seconds", startupDuration / 60000, startupDuration % 60000 / 1000);

    TC_METRIC_EVENT("events", "World initialized", Trinity::StringFormat("World initialized in {}  minutes {} seconds", startupDuration / 60000, startupDuration % 60000 / 1000));
    return true;
}

void World::SetForcedWarModeFactionBalanceState(TeamId team, int32 reward)
{
    sWorldStateMgr->SetValueAndSaveInDb(WS_WAR_MODE_HORDE_BUFF_VALUE, 10 + (team == TEAM_ALLIANCE ? reward : 0), false, nullptr);
    sWorldStateMgr->SetValueAndSaveInDb(WS_WAR_MODE_ALLIANCE_BUFF_VALUE, 10 + (team == TEAM_HORDE ? reward : 0), false, nullptr);
}

void World::DisableForcedWarModeFactionBalanceState()
{
    UpdateWarModeRewardValues();
}

void World::LoadAutobroadcasts()
{
    uint32 oldMSTime = getMSTime();

    m_Autobroadcasts.clear();

    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_AUTOBROADCAST);
    stmt->setInt32(0, sRealmList->GetCurrentRealmId().Realm);
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 autobroadcasts definitions. DB table `autobroadcast` is empty for this realm!");
        return;
    }

    do
    {
        Field* fields = result->Fetch();
        uint8 id = fields[0].GetUInt8();

        m_Autobroadcasts[id] = { .Message = fields[2].GetString(), .Weight = fields[1].GetUInt8() };

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} autobroadcast definitions in {} ms", m_Autobroadcasts.size(), GetMSTimeDiffToNow(oldMSTime));
}

/// Update the World !
void World::Update(uint32 diff)
{
    TC_METRIC_TIMER("world_update_time_total");
    ///- Update the game time and check for shutdown time
    _UpdateGameTime();
    time_t currentGameTime = GameTime::GetGameTime();

    sWorldUpdateTime.UpdateWithDiff(diff);

    ///- Update the different timers
    for (int i = 0; i < WUPDATE_COUNT; ++i)
    {
        if (m_timers[i].GetCurrent() >= 0)
            m_timers[i].Update(diff);
        else
            m_timers[i].SetCurrent(0);
    }

    ///- Update Who List Storage
    if (m_timers[WUPDATE_WHO_LIST].Passed())
    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Update who list"));
        m_timers[WUPDATE_WHO_LIST].Reset();
        sWhoListStorageMgr->Update();
    }

    if (IsStopped() || m_timers[WUPDATE_CHANNEL_SAVE].Passed())
    {
        m_timers[WUPDATE_CHANNEL_SAVE].Reset();

        if (getBoolConfig(CONFIG_PRESERVE_CUSTOM_CHANNELS))
        {
            TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Save custom channels"));
            ChannelMgr* mgr1 = ASSERT_NOTNULL(ChannelMgr::ForTeam(PANDARIA_NEUTRAL));
            mgr1->SaveToDB();
            ChannelMgr* mgr2 = ASSERT_NOTNULL(ChannelMgr::ForTeam(ALLIANCE));
            if (mgr1 != mgr2)
                mgr2->SaveToDB();
            ChannelMgr* mgr3 = ASSERT_NOTNULL(ChannelMgr::ForTeam(HORDE));
            if (mgr1 != mgr3)
                mgr3->SaveToDB();
        }
    }

    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Check daily reset times"));
        CheckScheduledResetTimes();
    }

    if (currentGameTime > m_NextRandomBGReset)
    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Reset random BG"));
        ResetRandomBG();
    }

    if (currentGameTime > m_NextCalendarOldEventsDeletionTime)
    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Delete old calendar events"));
        CalendarDeleteOldEvents();
    }

    if (currentGameTime > m_NextGuildReset)
    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Reset guild cap"));
        ResetGuildCap();
    }

    if (currentGameTime > m_NextCurrencyReset)
    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Reset currency weekly cap"));
        ResetCurrencyWeekCap();
    }

    /// <ul><li> Handle auctions when the timer has passed
    if (m_timers[WUPDATE_AUCTIONS].Passed())
    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Update expired auctions"));
        m_timers[WUPDATE_AUCTIONS].Reset();

        ///- Update mails (return old mails with item, or delete them)
        //(tested... works on win)
        if (++mail_timer > mail_timer_expires)
        {
            mail_timer = 0;
            sObjectMgr->ReturnOrDeleteOldMails(true);
        }

        ///- Handle expired auctions
        sAuctionMgr->Update();
    }

    if (m_timers[WUPDATE_AUCTIONS_PENDING].Passed())
    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Update pending auctions"));
        m_timers[WUPDATE_AUCTIONS_PENDING].Reset();

        sAuctionMgr->UpdatePendingAuctions();
    }

    if (m_timers[WUPDATE_BLACKMARKET].Passed())
    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Update pending black market auctions"));
        m_timers[WUPDATE_BLACKMARKET].Reset();

        ///- Update blackmarket, refresh auctions if necessary
        if ((blackmarket_timer *  m_timers[WUPDATE_BLACKMARKET].GetInterval() >=
            getIntConfig(CONFIG_BLACKMARKET_UPDATE_PERIOD) * HOUR * IN_MILLISECONDS)
            || !blackmarket_timer)
        {
            sBlackMarketMgr->RefreshAuctions();
            blackmarket_timer = 1; // timer is 0 on startup
        }
        else
        {
            ++blackmarket_timer;
            sBlackMarketMgr->Update();
        }
    }

    /// <li> Handle AHBot operations
    if (m_timers[WUPDATE_AHBOT].Passed())
    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Update AHBot"));
        sAuctionBot->Update();
        m_timers[WUPDATE_AHBOT].Reset();
    }

    /// Synchronize all scripts with their ids before updating the sScriptReloadMgr
    sScriptMgr->SyncScripts();

    /// <li> Handle file changes
    if (m_timers[WUPDATE_CHECK_FILECHANGES].Passed())
    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Update HotSwap"));
        sScriptReloadMgr->Update();
        m_timers[WUPDATE_CHECK_FILECHANGES].Reset();
    }

    {
        /// <li> Handle session updates when the timer has passed
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Update sessions"));
        UpdateSessions(diff);
    }

    /// <li> Update uptime table
    if (m_timers[WUPDATE_UPTIME].Passed())
    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Update uptime"));
        uint32 tmpDiff = GameTime::GetUptime();
        uint32 maxOnlinePlayers = GetMaxPlayerCount();

        m_timers[WUPDATE_UPTIME].Reset();

        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_UPTIME_PLAYERS);

        stmt->setUInt32(0, tmpDiff);
        stmt->setUInt16(1, uint16(maxOnlinePlayers));
        stmt->setUInt32(2, sRealmList->GetCurrentRealmId().Realm);
        stmt->setUInt32(3, uint32(GameTime::GetStartTime()));

        LoginDatabase.Execute(stmt);
    }

    /// <li> Clean logs table
    if (getIntConfig(CONFIG_LOGDB_CLEARTIME) > 0) // if not enabled, ignore the timer
    {
        if (m_timers[WUPDATE_CLEANDB].Passed())
        {
            TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Clean logs table"));
            m_timers[WUPDATE_CLEANDB].Reset();

            LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_OLD_LOGS);

            stmt->setUInt32(0, getIntConfig(CONFIG_LOGDB_CLEARTIME));
            stmt->setUInt32(1, uint32(GameTime::GetGameTime()));
            stmt->setUInt32(2, sRealmList->GetCurrentRealmId().Realm);

            LoginDatabase.Execute(stmt);
        }
    }

    /// <li> Handle all other objects
    ///- Update objects when the timer has passed (maps, transport, creatures, ...)
    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Update maps"));
        sMapMgr->Update(diff);
    }

    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Terrain data cleanup"));
        sTerrainMgr.Update(diff);
    }

    if (getBoolConfig(CONFIG_AUTOBROADCAST))
    {
        if (m_timers[WUPDATE_AUTOBROADCAST].Passed())
        {
            TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Send autobroadcast"));
            m_timers[WUPDATE_AUTOBROADCAST].Reset();
            SendAutoBroadcast();
        }
    }

    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Update battlegrounds"));
        sBattlegroundMgr->Update(diff);
    }

    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Update outdoor pvp"));
        sOutdoorPvPMgr->Update(diff);
    }

    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Update battlefields"));
        sBattlefieldMgr->Update(diff);
    }

    ///- Delete all characters which have been deleted X days before
    if (m_timers[WUPDATE_DELETECHARS].Passed())
    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Delete old characters"));
        m_timers[WUPDATE_DELETECHARS].Reset();
        Player::DeleteOldCharacters();
    }

    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Update groups"));
        sGroupMgr->Update(diff);
    }

    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Update LFG"));
        sLFGMgr->Update(diff);
    }

    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Process query callbacks"));
        // execute callbacks from sql queries that were queued recently
        ProcessQueryCallbacks();
    }

    ///- Erase corpses once every 20 minutes
    if (m_timers[WUPDATE_CORPSES].Passed())
    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Remove old corpses"));
        m_timers[WUPDATE_CORPSES].Reset();
        sMapMgr->DoForAllMaps([](Map* map)
        {
            map->RemoveOldCorpses();
        });
    }

    ///- Process Game events when necessary
    if (m_timers[WUPDATE_EVENTS].Passed())
    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Update game events"));
        m_timers[WUPDATE_EVENTS].Reset();                   // to give time for Update() to be processed
        uint32 nextGameEvent = sGameEventMgr->Update();
        m_timers[WUPDATE_EVENTS].SetInterval(nextGameEvent);
        m_timers[WUPDATE_EVENTS].Reset();
    }

    ///- Ping to keep MySQL connections alive
    if (m_timers[WUPDATE_PINGDB].Passed())
    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Ping MySQL"));
        m_timers[WUPDATE_PINGDB].Reset();
        TC_LOG_DEBUG("misc", "Ping MySQL to keep connection alive");
        CharacterDatabase.KeepAlive();
        LoginDatabase.KeepAlive();
        WorldDatabase.KeepAlive();
        HotfixDatabase.KeepAlive();
    }

    if (m_timers[WUPDATE_GUILDSAVE].Passed())
    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Save guilds"));
        m_timers[WUPDATE_GUILDSAVE].Reset();
        sGuildMgr->SaveGuilds();
    }

    // Check for shutdown warning
    if (_guidWarn && !_guidAlert)
    {
        _warnDiff += diff;
        if (GameTime::GetGameTime() >= _warnShutdownTime)
            DoGuidWarningRestart();
        else if (_warnDiff > getIntConfig(CONFIG_RESPAWN_GUIDWARNING_FREQUENCY) * IN_MILLISECONDS)
            SendGuidWarning();
    }

    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Process cli commands"));
        // And last, but not least handle the issued cli commands
        ProcessCliCommands();
    }

    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Update world scripts"));
        sScriptMgr->OnWorldUpdate(diff);
    }

    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Update metrics"));
        // Stats logger update
        sMetric->Update();
        TC_METRIC_VALUE("update_time_diff", diff);
    }
}

void World::ForceGameEventUpdate()
{
    m_timers[WUPDATE_EVENTS].Reset();                   // to give time for Update() to be processed
    uint32 nextGameEvent = sGameEventMgr->Update();
    m_timers[WUPDATE_EVENTS].SetInterval(nextGameEvent);
    m_timers[WUPDATE_EVENTS].Reset();
}

/// Send a packet to all players (except self if mentioned)
void World::SendGlobalMessage(WorldPacket const* packet, WorldSession* self, Optional<Team> team)
{
    SessionMap::const_iterator itr;
    for (itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
    {
        if (itr->second &&
            itr->second->GetPlayer() &&
            itr->second->GetPlayer()->IsInWorld() &&
            itr->second != self &&
            (!team || itr->second->GetPlayer()->GetTeam() == team))
        {
            itr->second->SendPacket(packet);
        }
    }
}

/// Send a packet to all GMs (except self if mentioned)
void World::SendGlobalGMMessage(WorldPacket const* packet, WorldSession* self, Optional<Team> team)
{
    for (SessionMap::const_iterator itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
    {
        // check if session and can receive global GM Messages and its not self
        WorldSession* session = itr->second;
        if (!session || session == self || !session->HasPermission(rbac::RBAC_PERM_RECEIVE_GLOBAL_GM_TEXTMESSAGE))
            continue;

        // Player should be in world
        Player* player = session->GetPlayer();
        if (!player || !player->IsInWorld())
            continue;

        // Send only to same team, if team is given
        if (!team || player->GetTeam() == team)
            session->SendPacket(packet);
    }
}

namespace Trinity
{
    class WorldWorldTextBuilder
    {
        class MultiplePacketSender
        {
        public:
            void operator()(Player const* receiver) const
            {
                for (std::unique_ptr<WorldPackets::Packet> const& packet : Packets)
                    receiver->SendDirectMessage(packet->GetRawPacket());
            }

            std::vector<std::unique_ptr<WorldPackets::Packet>> Packets;
        };

        public:
            static size_t const BufferSize = 2048;

            explicit WorldWorldTextBuilder(uint32 textId, va_list* args = nullptr) : i_textId(textId), i_args(args) { }

            MultiplePacketSender* operator()(LocaleConstant locale)
            {
                char const* text = sObjectMgr->GetTrinityString(i_textId, locale);

                char strBuffer[BufferSize];
                if (i_args)
                {
                    // we need copy va_list before use or original va_list will corrupted
                    va_list ap;
                    va_copy(ap, *i_args);
                    vsnprintf(strBuffer, BufferSize, text, ap);
                    va_end(ap);
                }
                else
                {
                    std::strncpy(strBuffer, text, BufferSize);
                    strBuffer[BufferSize - 1] = '\0';
                }

                MultiplePacketSender* sender = new MultiplePacketSender();
                do_helper(sender->Packets, strBuffer);
                return sender;
            }

        private:
            void do_helper(std::vector<std::unique_ptr<WorldPackets::Packet>>& dataList, char* text)
            {
                while (char* line = ChatHandler::LineFromMessage(text))
                {
                    WorldPackets::Chat::Chat* packet = new WorldPackets::Chat::Chat();
                    packet->Initialize(CHAT_MSG_SYSTEM, LANG_UNIVERSAL, nullptr, nullptr, line);
                    packet->Write();
                    dataList.emplace_back(packet);
                }
            }

            uint32 i_textId;
            va_list* i_args;
    };
}                                                           // namespace Trinity

/// Send a System Message to all players (except self if mentioned)
void World::SendWorldText(uint32 string_id, ...)
{
    va_list ap;
    va_start(ap, string_id);

    Trinity::WorldWorldTextBuilder wt_builder(string_id, &ap);
    Trinity::LocalizedDo<Trinity::WorldWorldTextBuilder> wt_do(wt_builder);
    for (SessionMap::const_iterator itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
    {
        if (!itr->second || !itr->second->GetPlayer() || !itr->second->GetPlayer()->IsInWorld())
            continue;

        wt_do(itr->second->GetPlayer());
    }

    va_end(ap);
}

/// Send a System Message to all GMs (except self if mentioned)
void World::SendGMText(uint32 string_id, ...)
{
    va_list ap;
    va_start(ap, string_id);

    Trinity::WorldWorldTextBuilder wt_builder(string_id, &ap);
    Trinity::LocalizedDo<Trinity::WorldWorldTextBuilder> wt_do(wt_builder);
    for (SessionMap::const_iterator itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
    {
        // Session should have permissions to receive global gm messages
        WorldSession* session = itr->second;
        if (!session || !session->HasPermission(rbac::RBAC_PERM_RECEIVE_GLOBAL_GM_TEXTMESSAGE))
            continue;

        // Player should be in world
        Player* player = session->GetPlayer();
        if (!player || !player->IsInWorld())
            continue;

        wt_do(player);
    }

    va_end(ap);
}

/// DEPRECATED, only for debug purpose. Send a System Message to all players (except self if mentioned)
void World::SendGlobalText(char const* text, WorldSession* self)
{
    // need copy to prevent corruption by strtok call in LineFromMessage original string
    char* buf = strdup(text);
    char* pos = buf;

    while (char* line = ChatHandler::LineFromMessage(pos))
    {
        WorldPackets::Chat::Chat packet;
        packet.Initialize(CHAT_MSG_SYSTEM, LANG_UNIVERSAL, nullptr, nullptr, line);
        SendGlobalMessage(packet.Write(), self);
    }

    free(buf);
}

/// Send a packet to all players (or players selected team) in the zone (except self if mentioned)
bool World::SendZoneMessage(uint32 zone, WorldPacket const* packet, WorldSession* self, Optional<Team> team)
{
    bool foundPlayerToSend = false;
    SessionMap::const_iterator itr;

    for (itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
    {
        if (itr->second &&
            itr->second->GetPlayer() &&
            itr->second->GetPlayer()->IsInWorld() &&
            itr->second->GetPlayer()->GetZoneId() == zone &&
            itr->second != self &&
            (!team || itr->second->GetPlayer()->GetTeam() == team))
        {
            itr->second->SendPacket(packet);
            foundPlayerToSend = true;
        }
    }

    return foundPlayerToSend;
}

/// Send a System Message to all players in the zone (except self if mentioned)
void World::SendZoneText(uint32 zone, char const* text, WorldSession* self, Optional<Team> team)
{
    WorldPackets::Chat::Chat packet;
    packet.Initialize(CHAT_MSG_SYSTEM, LANG_UNIVERSAL, nullptr, nullptr, text);
    SendZoneMessage(zone, packet.Write(), self, team);
}

/// Kick (and save) all players
void World::KickAll()
{
    m_QueuedPlayer.clear();                                 // prevent send queue update packet and login queued sessions

    // session not removed at kick and will removed in next update tick
    for (SessionMap::const_iterator itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
        itr->second->KickPlayer("World::KickAll");
}

/// Kick (and save) all players with security level less `sec`
void World::KickAllLess(AccountTypes sec)
{
    // session not removed at kick and will removed in next update tick
    for (SessionMap::const_iterator itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
        if (itr->second->GetSecurity() < sec)
            itr->second->KickPlayer("World::KickAllLess");
}

/// Ban an account or ban an IP address, duration will be parsed using TimeStringToSecs if it is positive, otherwise permban
BanReturn World::BanAccount(BanMode mode, std::string const& nameOrIP, std::string const& duration, std::string const& reason, std::string const& author)
{
    uint32 duration_secs = TimeStringToSecs(duration);
    return BanAccount(mode, nameOrIP, duration_secs, reason, author);
}

/// Ban an account or ban an IP address, duration is in seconds if positive, otherwise permban
BanReturn World::BanAccount(BanMode mode, std::string const& nameOrIP, uint32 duration_secs, std::string const& reason, std::string const& author)
{
    PreparedQueryResult resultAccounts = PreparedQueryResult(nullptr); //used for kicking

    // Prevent banning an already banned account
    if (mode == BAN_ACCOUNT && AccountMgr::IsBannedAccount(nameOrIP))
        return BAN_EXISTS;

    ///- Update the database with ban information
    switch (mode)
    {
        case BAN_IP:
        {
            // No SQL injection with prepared statements
            LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_BY_IP);
            stmt->setString(0, nameOrIP);
            resultAccounts = LoginDatabase.Query(stmt);
            stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_IP_BANNED);
            stmt->setString(0, nameOrIP);
            stmt->setUInt32(1, duration_secs);
            stmt->setString(2, author);
            stmt->setString(3, reason);
            LoginDatabase.Execute(stmt);
            break;
        }
        case BAN_ACCOUNT:
        {
            // No SQL injection with prepared statements
            LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_ID_BY_NAME);
            stmt->setString(0, nameOrIP);
            resultAccounts = LoginDatabase.Query(stmt);
            break;
        }
        case BAN_CHARACTER:
        {
            // No SQL injection with prepared statements
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ACCOUNT_BY_NAME);
            stmt->setString(0, nameOrIP);
            resultAccounts = CharacterDatabase.Query(stmt);
            break;
        }
        default:
            return BAN_SYNTAX_ERROR;
    }

    if (!resultAccounts)
    {
        if (mode == BAN_IP)
            return BAN_SUCCESS;                             // ip correctly banned but nobody affected (yet)
        else
            return BAN_NOTFOUND;                            // Nobody to ban
    }

    ///- Disconnect all affected players (for IP it can be several)
    LoginDatabaseTransaction trans = LoginDatabase.BeginTransaction();
    do
    {
        Field* fieldsAccount = resultAccounts->Fetch();
        uint32 account = fieldsAccount[0].GetUInt32();

        if (mode != BAN_IP)
        {
            // make sure there is only one active ban
            LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_ACCOUNT_NOT_BANNED);
            stmt->setUInt32(0, account);
            trans->Append(stmt);
            // No SQL injection with prepared statements
            stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_ACCOUNT_BANNED);
            stmt->setUInt32(0, account);
            stmt->setUInt32(1, duration_secs);
            stmt->setString(2, author);
            stmt->setString(3, reason);
            trans->Append(stmt);
        }

        if (WorldSession* sess = FindSession(account))
            if (std::string(sess->GetPlayerName()) != author)
                sess->KickPlayer("World::BanAccount Banning account");
    } while (resultAccounts->NextRow());

    LoginDatabase.CommitTransaction(trans);

    return BAN_SUCCESS;
}

/// Remove a ban from an account or IP address
bool World::RemoveBanAccount(BanMode mode, std::string const& nameOrIP)
{
    LoginDatabasePreparedStatement* stmt = nullptr;
    if (mode == BAN_IP)
    {
        stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_IP_NOT_BANNED);
        stmt->setString(0, nameOrIP);
        LoginDatabase.Execute(stmt);
    }
    else
    {
        uint32 account = 0;
        if (mode == BAN_ACCOUNT)
            account = AccountMgr::GetId(nameOrIP);
        else if (mode == BAN_CHARACTER)
            account = sCharacterCache->GetCharacterAccountIdByName(nameOrIP);

        if (!account)
            return false;

        //NO SQL injection as account is uint32
        stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_ACCOUNT_NOT_BANNED);
        stmt->setUInt32(0, account);
        LoginDatabase.Execute(stmt);
    }
    return true;
}

/// Ban an account or ban an IP address, duration will be parsed using TimeStringToSecs if it is positive, otherwise permban
BanReturn World::BanCharacter(std::string const& name, std::string const& duration, std::string const& reason, std::string const& author)
{
    Player* banned = ObjectAccessor::FindConnectedPlayerByName(name);
    ObjectGuid guid;

    uint32 duration_secs = TimeStringToSecs(duration);

    /// Pick a player to ban if not online
    if (!banned)
    {
        guid = sCharacterCache->GetCharacterGuidByName(name);
        if (guid.IsEmpty())
            return BAN_NOTFOUND;                                    // Nobody to ban
    }
    else
        guid = banned->GetGUID();

    //Use transaction in order to ensure the order of the queries
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    // make sure there is only one active ban
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHARACTER_BAN);
    stmt->setUInt64(0, guid.GetCounter());
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_BAN);
    stmt->setUInt64(0, guid.GetCounter());
    stmt->setInt64(1, duration_secs);
    stmt->setString(2, author);
    stmt->setString(3, reason);
    trans->Append(stmt);
    CharacterDatabase.CommitTransaction(trans);

    if (banned)
        banned->GetSession()->KickPlayer("World::BanCharacter Banning character");

    return BAN_SUCCESS;
}

/// Remove a ban from a character
bool World::RemoveBanCharacter(std::string const& name)
{
    Player* banned = ObjectAccessor::FindConnectedPlayerByName(name);
    ObjectGuid guid;

    /// Pick a player to ban if not online
    if (!banned)
    {
        guid = sCharacterCache->GetCharacterGuidByName(name);
        if (guid.IsEmpty())
            return false;                                    // Nobody to ban
    }
    else
        guid = banned->GetGUID();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHARACTER_BAN);
    stmt->setUInt64(0, guid.GetCounter());
    CharacterDatabase.Execute(stmt);
    return true;
}

/// Update the game time
void World::_UpdateGameTime()
{
    ///- update the time
    time_t lastGameTime = GameTime::GetGameTime();
    GameTime::UpdateGameTimers();

    uint32 elapsed = uint32(GameTime::GetGameTime() - lastGameTime);

    ///- if there is a shutdown timer
    if (!IsStopped() && m_ShutdownTimer > 0 && elapsed > 0)
    {
        ///- ... and it is overdue, stop the world (set m_stopEvent)
        if (m_ShutdownTimer <= elapsed)
        {
            if (!(m_ShutdownMask & SHUTDOWN_MASK_IDLE) || GetActiveAndQueuedSessionCount() == 0)
                m_stopEvent = true;                         // exist code already set
            else
                m_ShutdownTimer = 1;                        // minimum timer value to wait idle state
        }
        ///- ... else decrease it and if necessary display a shutdown countdown to the users
        else
        {
            m_ShutdownTimer -= elapsed;

            ShutdownMsg();
        }
    }
}

/// Shutdown the server
void World::ShutdownServ(uint32 time, uint32 options, uint8 exitcode, const std::string& reason)
{
    // ignore if server shutdown at next tick
    if (IsStopped())
        return;

    m_ShutdownMask = options;
    m_ExitCode = exitcode;

    ///- If the shutdown time is 0, evaluate shutdown on next tick (no message)
    if (time == 0)
        m_ShutdownTimer = 1;
    ///- Else set the shutdown timer and warn users
    else
    {
        m_ShutdownTimer = time;
        ShutdownMsg(true, nullptr, reason);
    }

    sScriptMgr->OnShutdownInitiate(ShutdownExitCode(exitcode), ShutdownMask(options));
}

/// Display a shutdown message to the user(s)
void World::ShutdownMsg(bool show, Player* player, const std::string& reason)
{
    // not show messages for idle shutdown mode
    if (m_ShutdownMask & SHUTDOWN_MASK_IDLE)
        return;

    ///- Display a message every 12 hours, hours, 5 minutes, minute, 5 seconds and finally seconds
    if (show ||
        (m_ShutdownTimer < 5* MINUTE && (m_ShutdownTimer % 15) == 0) || // < 5 min; every 15 sec
        (m_ShutdownTimer < 15 * MINUTE && (m_ShutdownTimer % MINUTE) == 0) || // < 15 min ; every 1 min
        (m_ShutdownTimer < 30 * MINUTE && (m_ShutdownTimer % (5 * MINUTE)) == 0) || // < 30 min ; every 5 min
        (m_ShutdownTimer < 12 * HOUR && (m_ShutdownTimer % HOUR) == 0) || // < 12 h ; every 1 h
        (m_ShutdownTimer > 12 * HOUR && (m_ShutdownTimer % (12 * HOUR)) == 0)) // > 12 h ; every 12 h
    {
        std::string str = secsToTimeString(m_ShutdownTimer, TimeFormat::Numeric);
        if (!reason.empty())
            str += " - " + reason;

        ServerMessageType msgid = (m_ShutdownMask & SHUTDOWN_MASK_RESTART) ? SERVER_MSG_RESTART_TIME : SERVER_MSG_SHUTDOWN_TIME;

        SendServerMessage(msgid, str, player);
        TC_LOG_DEBUG("misc", "Server is {} in {}", (m_ShutdownMask & SHUTDOWN_MASK_RESTART ? "restart" : "shuttingdown"), str);
    }
}

/// Cancel a planned server shutdown
uint32 World::ShutdownCancel()
{
    // nothing cancel or too late
    if (!m_ShutdownTimer || m_stopEvent)
        return 0;

    ServerMessageType msgid = (m_ShutdownMask & SHUTDOWN_MASK_RESTART) ? SERVER_MSG_RESTART_CANCELLED : SERVER_MSG_SHUTDOWN_CANCELLED;

    uint32 oldTimer = m_ShutdownTimer;
    m_ShutdownMask = 0;
    m_ShutdownTimer = 0;
    m_ExitCode = SHUTDOWN_EXIT_CODE;                       // to default value
    SendServerMessage(msgid);

    TC_LOG_DEBUG("misc", "Server {} cancelled.", (m_ShutdownMask & SHUTDOWN_MASK_RESTART ? "restart" : "shutdown"));

    sScriptMgr->OnShutdownCancel();
    return oldTimer;
}

/// Send a server message to the user(s)
void World::SendServerMessage(ServerMessageType messageID, std::string_view stringParam /*= {}*/, Player const* player /*= nullptr*/)
{
    ServerMessagesEntry const* serverMessage = sServerMessagesStore.LookupEntry(messageID);
    if (!serverMessage)
        return;

    WorldPackets::Chat::ChatServerMessage chatServerMessage;
    chatServerMessage.MessageID = int32(messageID);
    if (strstr(serverMessage->Text[player ? player->GetSession()->GetSessionDbcLocale() : GetDefaultDbcLocale()], "%s"))
        chatServerMessage.StringParam = stringParam;

    if (player)
        player->SendDirectMessage(chatServerMessage.Write());
    else
        SendGlobalMessage(chatServerMessage.Write());
}

void World::UpdateSessions(uint32 diff)
{
    {
        TC_METRIC_DETAILED_NO_THRESHOLD_TIMER("world_update_time",
            TC_METRIC_TAG("type", "Add sessions"),
            TC_METRIC_TAG("parent_type", "Update sessions"));
        ///- Add new sessions
        WorldSession* sess = nullptr;
        while (addSessQueue.next(sess))
            AddSession_(sess);
    }

    {
        std::pair<std::weak_ptr<WorldSocket>, uint64> linkInfo;
        while (_linkSocketQueue.next(linkInfo))
        {
            WorldSession::ConnectToKey key = { .Raw = linkInfo.second };
            WorldSession::AddInstanceConnection(FindSession(key.Fields.AccountId), linkInfo.first, key);
        }
    }

    ///- Then send an update signal to remaining ones
    for (SessionMap::iterator itr = m_sessions.begin(), next; itr != m_sessions.end(); itr = next)
    {
        next = itr;
        ++next;

        ///- and remove not active sessions from the list
        WorldSession* pSession = itr->second;
        WorldSessionFilter updater(pSession);

        [[maybe_unused]] uint32 currentSessionId = itr->first;
        TC_METRIC_DETAILED_TIMER("world_update_sessions_time", TC_METRIC_TAG("account_id", std::to_string(currentSessionId)));

        if (!pSession->Update(diff, updater))    // As interval = 0
        {
            if (!RemoveQueuedPlayer(itr->second) && itr->second && getIntConfig(CONFIG_INTERVAL_DISCONNECT_TOLERANCE))
                m_disconnects[itr->second->GetAccountId()] = GameTime::GetGameTime();
            RemoveQueuedPlayer(pSession);
            m_sessions.erase(itr);
            Trinity::Containers::MultimapErasePair(m_sessionsByBnetGuid, pSession->GetBattlenetAccountGUID(), pSession);
            delete pSession;
        }
    }
}

// This handles the issued and queued CLI commands
void World::ProcessCliCommands()
{
    CliCommandHolder::Print zprint = nullptr;
    void* callbackArg = nullptr;
    CliCommandHolder* command = nullptr;
    while (cliCmdQueue.next(command))
    {
        TC_LOG_INFO("misc", "CLI command under processing...");
        zprint = command->m_print;
        callbackArg = command->m_callbackArg;
        CliHandler handler(callbackArg, zprint);
        handler.ParseCommands(command->m_command);
        if (command->m_commandFinished)
            command->m_commandFinished(callbackArg, !handler.HasSentErrorMessage());
        delete command;
    }
}

void World::SendAutoBroadcast()
{
    if (m_Autobroadcasts.empty())
        return;

    auto itr = Trinity::Containers::SelectRandomWeightedContainerElement(m_Autobroadcasts, [](AutobroadcastContainer::value_type const& pair)
    {
        return pair.second.Weight;
    });

    uint32 abcenter = getIntConfig(CONFIG_AUTOBROADCAST_CENTER);

    if (abcenter == 0)
        SendWorldText(LANG_AUTO_BROADCAST, itr->second.Message.c_str());
    else if (abcenter == 1)
        SendGlobalMessage(WorldPackets::Chat::PrintNotification(itr->second.Message).Write());
    else if (abcenter == 2)
    {
        SendWorldText(LANG_AUTO_BROADCAST, itr->second.Message.c_str());
        SendGlobalMessage(WorldPackets::Chat::PrintNotification(itr->second.Message).Write());
    }

    TC_LOG_DEBUG("misc", "AutoBroadcast: '{}'", itr->second.Message);
}

void World::UpdateRealmCharCount(uint32 accountId)
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_COUNT);
    stmt->setUInt32(0, accountId);
    _queryProcessor.AddCallback(CharacterDatabase.AsyncQuery(stmt).WithPreparedCallback([this](PreparedQueryResult result)
    {
        _UpdateRealmCharCount(std::move(result));
    }));
}

void World::_UpdateRealmCharCount(PreparedQueryResult resultCharCount)
{
    if (resultCharCount)
    {
        Field* fields = resultCharCount->Fetch();
        uint32 accountId = fields[0].GetUInt32();
        uint8 charCount = uint8(fields[1].GetUInt64());

        LoginDatabaseTransaction trans = LoginDatabase.BeginTransaction();

        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_REP_REALM_CHARACTERS);
        stmt->setUInt8(0, charCount);
        stmt->setUInt32(1, accountId);
        stmt->setUInt32(2, sRealmList->GetCurrentRealmId().Realm);
        trans->Append(stmt);

        LoginDatabase.CommitTransaction(trans);
    }
}

void World::InitQuestResetTimes()
{
    m_NextDailyQuestReset = GetPersistentWorldVariable(NextDailyQuestResetTimeVarId);
    m_NextWeeklyQuestReset = GetPersistentWorldVariable(NextWeeklyQuestResetTimeVarId);
    m_NextMonthlyQuestReset = GetPersistentWorldVariable(NextMonthlyQuestResetTimeVarId);
}

static time_t GetNextDailyResetTime(time_t t)
{
    return GetLocalHourTimestamp(t, sWorld->getIntConfig(CONFIG_DAILY_QUEST_RESET_TIME_HOUR), true);
}

void World::DailyReset()
{
    // reset all saved quest status
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_RESET_CHARACTER_QUESTSTATUS_DAILY);
    CharacterDatabase.Execute(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHARACTER_GARRISON_FOLLOWER_ACTIVATIONS);
    stmt->setUInt32(0, 1);
    CharacterDatabase.Execute(stmt);

    // reset all quest status in memory
    for (SessionMap::const_iterator itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
        if (Player* player = itr->second->GetPlayer())
            player->DailyReset();

    // reselect pools
    sQuestPoolMgr->ChangeDailyQuests();

    // store next reset time
    time_t now = GameTime::GetGameTime();
    time_t next = GetNextDailyResetTime(now);
    ASSERT(now < next);

    m_NextDailyQuestReset = next;
    SetPersistentWorldVariable(NextDailyQuestResetTimeVarId, uint64(next));

    TC_LOG_INFO("misc", "Daily quests for all characters have been reset.");
}

static time_t GetNextWeeklyResetTime(time_t t)
{
    t = GetNextDailyResetTime(t);
    tm time = TimeBreakdown(t);
    int wday = time.tm_wday;
    int target = sWorld->getIntConfig(CONFIG_WEEKLY_QUEST_RESET_TIME_WDAY);
    if (target < wday)
        wday -= 7;
    t += (DAY * (target - wday));
    return t;
}

void World::ResetWeeklyQuests()
{
    // reset all saved quest status
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_RESET_CHARACTER_QUESTSTATUS_WEEKLY);
    CharacterDatabase.Execute(stmt);
    // reset all quest status in memory
    for (SessionMap::const_iterator itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
        if (Player* player = itr->second->GetPlayer())
            player->ResetWeeklyQuestStatus();

    // reselect pools
    sQuestPoolMgr->ChangeWeeklyQuests();

    // Update faction balance
    UpdateWarModeRewardValues();

    // store next reset time
    time_t now = GameTime::GetGameTime();
    time_t next = GetNextWeeklyResetTime(now);
    ASSERT(now < next);

    m_NextWeeklyQuestReset = next;
    SetPersistentWorldVariable(NextWeeklyQuestResetTimeVarId, uint64(next));

    TC_LOG_INFO("misc", "Weekly quests for all characters have been reset.");
}

static time_t GetNextMonthlyResetTime(time_t t)
{
    t = GetNextDailyResetTime(t);
    tm time = TimeBreakdown(t);
    if (time.tm_mday == 1)
        return t;

    time.tm_mday = 1;
    time.tm_mon += 1;
    return mktime(&time);
}

void World::ResetMonthlyQuests()
{
    // reset all saved quest status
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_RESET_CHARACTER_QUESTSTATUS_MONTHLY);
    CharacterDatabase.Execute(stmt);
    // reset all quest status in memory
    for (SessionMap::const_iterator itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
        if (Player* player = itr->second->GetPlayer())
            player->ResetMonthlyQuestStatus();

    // reselect pools
    sQuestPoolMgr->ChangeMonthlyQuests();

    // store next reset time
    time_t now = GameTime::GetGameTime();
    time_t next = GetNextMonthlyResetTime(now);
    ASSERT(now < next);

    m_NextMonthlyQuestReset = next;
    SetPersistentWorldVariable(NextMonthlyQuestResetTimeVarId, uint64(next));

    TC_LOG_INFO("misc", "Monthly quests for all characters have been reset.");
}

void World::CheckScheduledResetTimes()
{
    time_t const now = GameTime::GetGameTime();
    if (m_NextDailyQuestReset <= now)
        DailyReset();
    if (m_NextWeeklyQuestReset <= now)
        ResetWeeklyQuests();
    if (m_NextMonthlyQuestReset <= now)
        ResetMonthlyQuests();
}

void World::InitRandomBGResetTime()
{
    time_t bgtime = GetPersistentWorldVariable(NextBGRandomDailyResetTimeVarId);
    if (!bgtime)
        m_NextRandomBGReset = GameTime::GetGameTime();         // game time not yet init

    // generate time by config
    time_t curTime = GameTime::GetGameTime();
    tm localTm;
    localtime_r(&curTime, &localTm);
    localTm.tm_hour = getIntConfig(CONFIG_RANDOM_BG_RESET_HOUR);
    localTm.tm_min = 0;
    localTm.tm_sec = 0;

    // current day reset time
    time_t nextDayResetTime = mktime(&localTm);

    // next reset time before current moment
    if (curTime >= nextDayResetTime)
        nextDayResetTime += DAY;

    // normalize reset time
    m_NextRandomBGReset = bgtime < curTime ? nextDayResetTime - DAY : nextDayResetTime;

    if (!bgtime)
        SetPersistentWorldVariable(NextBGRandomDailyResetTimeVarId, uint32(m_NextRandomBGReset));
}

void World::InitCalendarOldEventsDeletionTime()
{
    time_t now = GameTime::GetGameTime();
    time_t nextDeletionTime = GetLocalHourTimestamp(now, getIntConfig(CONFIG_CALENDAR_DELETE_OLD_EVENTS_HOUR));
    time_t currentDeletionTime = GetPersistentWorldVariable(NextOldCalendarEventDeletionTimeVarId);

    // If the reset time saved in the worldstate is before now it means the server was offline when the reset was supposed to occur.
    // In this case we set the reset time in the past and next world update will do the reset and schedule next one in the future.
    if (currentDeletionTime < now)
        m_NextCalendarOldEventsDeletionTime = nextDeletionTime - DAY;
    else
        m_NextCalendarOldEventsDeletionTime = nextDeletionTime;

    if (!currentDeletionTime)
        SetPersistentWorldVariable(NextOldCalendarEventDeletionTimeVarId, uint64(m_NextCalendarOldEventsDeletionTime));
}

void World::InitGuildResetTime()
{
    time_t gtime = GetPersistentWorldVariable(NextGuildDailyResetTimeVarId);
    if (!gtime)
        m_NextGuildReset = GameTime::GetGameTime();         // game time not yet init

    // generate time by config
    time_t curTime = GameTime::GetGameTime();
    tm localTm;
    localtime_r(&curTime, &localTm);
    localTm.tm_hour = getIntConfig(CONFIG_GUILD_RESET_HOUR);
    localTm.tm_min = 0;
    localTm.tm_sec = 0;

    // current day reset time
    time_t nextDayResetTime = mktime(&localTm);

    // next reset time before current moment
    if (curTime >= nextDayResetTime)
        nextDayResetTime += DAY;

    // normalize reset time
    m_NextGuildReset = gtime < curTime ? nextDayResetTime - DAY : nextDayResetTime;

    if (!gtime)
        SetPersistentWorldVariable(NextGuildDailyResetTimeVarId, uint32(m_NextGuildReset));
}

void World::InitCurrencyResetTime()
{
    time_t currencytime = GetPersistentWorldVariable(NextCurrencyResetTimeVarId);
    if (!currencytime)
        m_NextCurrencyReset = GameTime::GetGameTime();         // game time not yet init

    // generate time by config
    time_t curTime = GameTime::GetGameTime();
    tm localTm;
    localtime_r(&curTime, &localTm);

    localTm.tm_wday = getIntConfig(CONFIG_CURRENCY_RESET_DAY);
    localTm.tm_hour = getIntConfig(CONFIG_CURRENCY_RESET_HOUR);
    localTm.tm_min = 0;
    localTm.tm_sec = 0;

    // current week reset time
    time_t nextWeekResetTime = mktime(&localTm);

    // next reset time before current moment
    if (curTime >= nextWeekResetTime)
        nextWeekResetTime += getIntConfig(CONFIG_CURRENCY_RESET_INTERVAL) * DAY;

    // normalize reset time
    m_NextCurrencyReset = currencytime < curTime ? nextWeekResetTime - getIntConfig(CONFIG_CURRENCY_RESET_INTERVAL) * DAY : nextWeekResetTime;

    if (!currencytime)
        SetPersistentWorldVariable(NextCurrencyResetTimeVarId, uint32(m_NextCurrencyReset));
}

void World::ResetCurrencyWeekCap()
{
    CharacterDatabase.Execute("UPDATE `character_currency` SET `WeeklyQuantity` = 0");

    for (SessionMap::const_iterator itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
        if (itr->second->GetPlayer())
            itr->second->GetPlayer()->ResetCurrencyWeekCap();

    m_NextCurrencyReset = time_t(m_NextCurrencyReset + DAY * getIntConfig(CONFIG_CURRENCY_RESET_INTERVAL));
    SetPersistentWorldVariable(NextCurrencyResetTimeVarId, uint32(m_NextCurrencyReset));
}

void World::ResetEventSeasonalQuests(uint16 event_id, time_t eventStartTime)
{
    TC_LOG_INFO("misc", "Seasonal quests reset for all characters.");

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_RESET_CHARACTER_QUESTSTATUS_SEASONAL_BY_EVENT);
    stmt->setUInt16(0, event_id);
    stmt->setInt64(1, eventStartTime);
    CharacterDatabase.Execute(stmt);

    for (SessionMap::const_iterator itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
        if (itr->second->GetPlayer())
            itr->second->GetPlayer()->ResetSeasonalQuestStatus(event_id, eventStartTime);
}

void World::ResetRandomBG()
{
    TC_LOG_INFO("misc", "Random BG status reset for all characters.");

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_BATTLEGROUND_RANDOM_ALL);
    CharacterDatabase.Execute(stmt);

    for (SessionMap::const_iterator itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
        if (itr->second->GetPlayer())
            itr->second->GetPlayer()->SetRandomWinner(false);

    m_NextRandomBGReset = time_t(m_NextRandomBGReset + DAY);
    SetPersistentWorldVariable(NextBGRandomDailyResetTimeVarId, uint32(m_NextRandomBGReset));
}

void World::CalendarDeleteOldEvents()
{
    TC_LOG_INFO("misc", "Calendar deletion of old events.");

    m_NextCalendarOldEventsDeletionTime = time_t(m_NextCalendarOldEventsDeletionTime + DAY);
    SetPersistentWorldVariable(NextOldCalendarEventDeletionTimeVarId, uint64(m_NextCalendarOldEventsDeletionTime));
    sCalendarMgr->DeleteOldEvents();
}

void World::ResetGuildCap()
{
    m_NextGuildReset = time_t(m_NextGuildReset + DAY);
    SetPersistentWorldVariable(NextGuildDailyResetTimeVarId, uint32(m_NextGuildReset));
    uint32 week = GetPersistentWorldVariable(NextGuildWeeklyResetTimeVarId);
    week = week < 7 ? week + 1 : 1;

    TC_LOG_INFO("misc", "Guild Daily Cap reset. Week: {}", week == 1);
    SetPersistentWorldVariable(NextGuildWeeklyResetTimeVarId, week);
    sGuildMgr->ResetTimes(week == 1);
}

void World::UpdateMaxSessionCounters()
{
    m_maxActiveSessionCount = std::max(m_maxActiveSessionCount, uint32(m_sessions.size()-m_QueuedPlayer.size()));
    m_maxQueuedSessionCount = std::max(m_maxQueuedSessionCount, uint32(m_QueuedPlayer.size()));
}

void World::LoadDBVersion()
{
    if (QueryResult result = WorldDatabase.Query("SELECT db_version, cache_id FROM version LIMIT 1"))
    {
        Field* fields = result->Fetch();

        m_DBVersion = fields[0].GetString();
        // will be overwrite by config values if different and non-0
        m_int_configs[CONFIG_CLIENTCACHE_VERSION] = fields[1].GetUInt32();
    }

    if (m_DBVersion.empty())
        m_DBVersion = "Unknown world database.";
}

void World::UpdateAreaDependentAuras()
{
    SessionMap::const_iterator itr;
    for (itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
        if (itr->second && itr->second->GetPlayer() && itr->second->GetPlayer()->IsInWorld())
        {
            itr->second->GetPlayer()->UpdateAreaDependentAuras(itr->second->GetPlayer()->GetAreaId());
            itr->second->GetPlayer()->UpdateZoneDependentAuras(itr->second->GetPlayer()->GetZoneId());
        }
}

bool World::IsBattlePetJournalLockAcquired(ObjectGuid battlenetAccountGuid)
{
    for (auto&& sessionForBnet : Trinity::Containers::MapEqualRange(m_sessionsByBnetGuid, battlenetAccountGuid))
        if (sessionForBnet.second->GetBattlePetMgr()->HasJournalLock())
            return true;

    return false;
}

bool World::IsPvPRealm() const
{
    return (getIntConfig(CONFIG_GAME_TYPE) == REALM_TYPE_PVP || getIntConfig(CONFIG_GAME_TYPE) == REALM_TYPE_RPPVP || getIntConfig(CONFIG_GAME_TYPE) == REALM_TYPE_FFA_PVP);
}

bool World::IsFFAPvPRealm() const
{
    return getIntConfig(CONFIG_GAME_TYPE) == REALM_TYPE_FFA_PVP;
}

int32 World::GetPersistentWorldVariable(PersistentWorldVariable const& var) const
{
    if (int32 const* value = Trinity::Containers::MapGetValuePtr(m_worldVariables, var.Id))
        return *value;

    return 0;
}

void World::SetPersistentWorldVariable(PersistentWorldVariable const& var, int32 value)
{
    m_worldVariables[var.Id] = value;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_WORLD_VARIABLE);
    stmt->setString(0, var.Id);
    stmt->setInt32(1, value);
    CharacterDatabase.Execute(stmt);
}

void World::LoadPersistentWorldVariables()
{
    uint32 oldMSTime = getMSTime();

    if (QueryResult result = CharacterDatabase.Query("SELECT ID, Value FROM world_variable"))
    {
        do
        {
            Field* fields = result->Fetch();
            m_worldVariables[fields[0].GetString()] = fields[1].GetInt32();
        } while (result->NextRow());
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} world variables in {} ms", m_worldVariables.size(), GetMSTimeDiffToNow(oldMSTime));
}

void World::ProcessQueryCallbacks()
{
    _queryProcessor.ProcessReadyCallbacks();
}

void World::ReloadRBAC()
{
    // Passive reload, we mark the data as invalidated and next time a permission is checked it will be reloaded
    TC_LOG_INFO("rbac", "World::ReloadRBAC()");
    for (SessionMap::const_iterator itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
        if (WorldSession* session = itr->second)
            session->InvalidateRBACData();
}

void World::RemoveOldCorpses()
{
    m_timers[WUPDATE_CORPSES].SetCurrent(m_timers[WUPDATE_CORPSES].GetInterval());
}

void World::UpdateWarModeRewardValues()
{
    std::array<int64, 2> warModeEnabledFaction = { };

    // Search for characters that have war mode enabled and played during the last week
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_WAR_MODE_TUNING);
    stmt->setUInt32(0, PLAYER_FLAGS_WAR_MODE_DESIRED);
    stmt->setUInt32(1, PLAYER_FLAGS_WAR_MODE_DESIRED);
    if (PreparedQueryResult result = CharacterDatabase.Query(stmt))
    {
        do
        {
            Field* fields = result->Fetch();
            uint8 race = fields[0].GetUInt8();
            if (ChrRacesEntry const* raceEntry = sChrRacesStore.LookupEntry(race))
            {
                if (FactionTemplateEntry const* raceFaction = sFactionTemplateStore.AssertEntry(raceEntry->FactionID))
                {
                    if (raceFaction->FactionGroup & FACTION_MASK_ALLIANCE)
                        warModeEnabledFaction[TEAM_ALLIANCE] += fields[1].GetInt64();
                    else if (raceFaction->FactionGroup & FACTION_MASK_HORDE)
                        warModeEnabledFaction[TEAM_HORDE] += fields[1].GetInt64();
                }
            }

        } while (result->NextRow());
    }

    TeamId dominantFaction = TEAM_ALLIANCE;
    int32 outnumberedFactionReward = 0;

    if (std::any_of(warModeEnabledFaction.begin(), warModeEnabledFaction.end(), [](int64 val) { return val != 0; }))
    {
        int64 dominantFactionCount = warModeEnabledFaction[TEAM_ALLIANCE];
        if (warModeEnabledFaction[TEAM_ALLIANCE] < warModeEnabledFaction[TEAM_HORDE])
        {
            dominantFactionCount = warModeEnabledFaction[TEAM_HORDE];
            dominantFaction = TEAM_HORDE;
        }

        double total = warModeEnabledFaction[TEAM_ALLIANCE] + warModeEnabledFaction[TEAM_HORDE];
        double pct = dominantFactionCount / total;

        if (pct >= getFloatConfig(CONFIG_CALL_TO_ARMS_20_PCT))
            outnumberedFactionReward = 20;
        else if (pct >= getFloatConfig(CONFIG_CALL_TO_ARMS_10_PCT))
            outnumberedFactionReward = 10;
        else if (pct >= getFloatConfig(CONFIG_CALL_TO_ARMS_5_PCT))
            outnumberedFactionReward = 5;
    }

    sWorldStateMgr->SetValueAndSaveInDb(WS_WAR_MODE_HORDE_BUFF_VALUE, 10 + (dominantFaction == TEAM_ALLIANCE ? outnumberedFactionReward : 0), false, nullptr);
    sWorldStateMgr->SetValueAndSaveInDb(WS_WAR_MODE_ALLIANCE_BUFF_VALUE, 10 + (dominantFaction == TEAM_HORDE ? outnumberedFactionReward : 0), false, nullptr);
}

uint32 GetVirtualRealmAddress()
{
    return sRealmList->GetCurrentRealmId().GetAddress();
}

CliCommandHolder::CliCommandHolder(void* callbackArg, char const* command, Print zprint, CommandFinished commandFinished)
    : m_callbackArg(callbackArg), m_command(strdup(command)), m_print(zprint), m_commandFinished(commandFinished)
{
}

CliCommandHolder::~CliCommandHolder()
{
    free(m_command);
}
