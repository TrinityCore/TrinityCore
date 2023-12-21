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
#include "MMapFactory.h"
#include "Map.h"
#include "MapManager.h"
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
#include "Realm.h"
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
#include "VMapManager2.h"
#include "WardenCheckMgr.h"
#include "WaypointManager.h"
#include "WeatherMgr.h"
#include "WhoListStorage.h"
#include "WorldSession.h"
#include "WorldSocket.h"
#include "WorldStateMgr.h"

#include <boost/algorithm/string.hpp>

TC_GAME_API std::atomic<bool> World::m_stopEvent(false);
TC_GAME_API uint8 World::m_ExitCode = SHUTDOWN_EXIT_CODE;

TC_GAME_API std::atomic<uint32> World::m_worldLoopCounter(0);

TC_GAME_API float World::m_MaxVisibleDistanceOnContinents = DEFAULT_VISIBILITY_DISTANCE;
TC_GAME_API float World::m_MaxVisibleDistanceInInstances  = DEFAULT_VISIBILITY_INSTANCE;
TC_GAME_API float World::m_MaxVisibleDistanceInBG         = DEFAULT_VISIBILITY_BGARENAS;
TC_GAME_API float World::m_MaxVisibleDistanceInArenas     = DEFAULT_VISIBILITY_BGARENAS;

TC_GAME_API int32 World::m_visibility_notify_periodOnContinents = DEFAULT_VISIBILITY_NOTIFY_PERIOD;
TC_GAME_API int32 World::m_visibility_notify_periodInInstances  = DEFAULT_VISIBILITY_NOTIFY_PERIOD;
TC_GAME_API int32 World::m_visibility_notify_periodInBG         = DEFAULT_VISIBILITY_NOTIFY_PERIOD;
TC_GAME_API int32 World::m_visibility_notify_periodInArenas     = DEFAULT_VISIBILITY_NOTIFY_PERIOD;

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
    MMAP::MMapFactory::clear();

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
    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_REALMLIST_SECURITY_LEVEL);
    stmt->setInt32(0, int32(realm.Id.Realm));
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    if (result)
        SetPlayerSecurityLimit(AccountTypes(result->Fetch()->GetUInt8()));
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
    boost::split(_motd, motd, boost::is_any_of("@"));
}

std::vector<std::string> const& World::GetMotd() const
{
    return _motd;
}

void World::TriggerGuidWarning()
{
    // Lock this only to prevent multiple maps triggering at the same time
    std::lock_guard<std::mutex> lock(_guidAlertLock);

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
    std::lock_guard<std::mutex> lock(_guidAlertLock);

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
        popu *= 2;
        TC_LOG_INFO("misc", "Server Population ({}).", popu);
    }
}

void World::ProcessLinkInstanceSocket(std::pair<std::weak_ptr<WorldSocket>, uint64> linkInfo)
{
    if (std::shared_ptr<WorldSocket> sock = linkInfo.first.lock())
    {
        if (!sock->IsOpen())
            return;

        WorldSession::ConnectToKey key;
        key.Raw = linkInfo.second;

        WorldSession* session = FindSession(uint32(key.Fields.AccountId));
        if (!session || session->GetConnectToInstanceKey() != linkInfo.second)
        {
            sock->SendAuthResponseError(ERROR_TIMED_OUT);
            sock->DelayedCloseSocket();
            return;
        }

        sock->SetWorldSession(session);
        session->AddInstanceConnection(sock);
        session->HandleContinuePlayerLogin();
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

    m_defaultDbcLocale = LocaleConstant(sConfigMgr->GetIntDefault("DBC.Locale", 0));

    if (m_defaultDbcLocale >= TOTAL_LOCALES || m_defaultDbcLocale == LOCALE_none)
    {
        TC_LOG_ERROR("server.loading", "Incorrect DBC.Locale! Must be >= 0 and < {} and not {} (set to 0)", TOTAL_LOCALES, LOCALE_none);
        m_defaultDbcLocale = LOCALE_enUS;
    }

    TC_LOG_INFO("server.loading", "Using {} DBC Locale", localeNames[m_defaultDbcLocale]);

    ///- Read the player limit and the Message of the day from the config file
    SetPlayerAmountLimit(sConfigMgr->GetIntDefault("PlayerLimit", 100));
    SetMotd(sConfigMgr->GetStringDefault("Motd", "Welcome to a Trinity Core Server."));

    ///- Read support system setting from the config file
    m_bool_configs[CONFIG_SUPPORT_ENABLED] = sConfigMgr->GetBoolDefault("Support.Enabled", true);
    m_bool_configs[CONFIG_SUPPORT_TICKETS_ENABLED] = sConfigMgr->GetBoolDefault("Support.TicketsEnabled", false);
    m_bool_configs[CONFIG_SUPPORT_BUGS_ENABLED] = sConfigMgr->GetBoolDefault("Support.BugsEnabled", false);
    m_bool_configs[CONFIG_SUPPORT_COMPLAINTS_ENABLED] = sConfigMgr->GetBoolDefault("Support.ComplaintsEnabled", false);
    m_bool_configs[CONFIG_SUPPORT_SUGGESTIONS_ENABLED] = sConfigMgr->GetBoolDefault("Support.SuggestionsEnabled", false);
    if (reload)
    {
        sSupportMgr->SetSupportSystemStatus(m_bool_configs[CONFIG_SUPPORT_ENABLED]);
        sSupportMgr->SetTicketSystemStatus(m_bool_configs[CONFIG_SUPPORT_TICKETS_ENABLED]);
        sSupportMgr->SetBugSystemStatus(m_bool_configs[CONFIG_SUPPORT_BUGS_ENABLED]);
        sSupportMgr->SetComplaintSystemStatus(m_bool_configs[CONFIG_SUPPORT_COMPLAINTS_ENABLED]);
        sSupportMgr->SetSuggestionSystemStatus(m_bool_configs[CONFIG_SUPPORT_SUGGESTIONS_ENABLED]);
    }

    ///- Get string for new logins (newly created characters)
    SetNewCharString(sConfigMgr->GetStringDefault("PlayerStart.String", ""));

    ///- Send server info on login?
    m_int_configs[CONFIG_ENABLE_SINFO_LOGIN] = sConfigMgr->GetIntDefault("Server.LoginInfo", 0);

    ///- Read all rates from the config file
    auto setRegenRate = [this](Rates rate, char const* configKey)
    {
        rate_values[rate] = sConfigMgr->GetFloatDefault(configKey, 1.0f);
        if (rate_values[rate] < 0.0f)
        {
            TC_LOG_ERROR("server.loading", "{} ({}) must be > 0. Using 1 instead.", configKey, rate_values[rate]);
            rate_values[rate] = 1.0f;
        }
    };

    setRegenRate(RATE_HEALTH, "Rate.Health");
    setRegenRate(RATE_POWER_MANA, "Rate.Mana");
    setRegenRate(RATE_POWER_RAGE_INCOME, "Rate.Rage.Gain");
    setRegenRate(RATE_POWER_RAGE_LOSS, "Rate.Rage.Loss");
    setRegenRate(RATE_POWER_FOCUS, "Rate.Focus");
    setRegenRate(RATE_POWER_ENERGY, "Rate.Energy");
    setRegenRate(RATE_POWER_COMBO_POINTS_LOSS, "Rate.ComboPoints.Loss");
    setRegenRate(RATE_POWER_RUNIC_POWER_INCOME, "Rate.RunicPower.Gain");
    setRegenRate(RATE_POWER_RUNIC_POWER_LOSS, "Rate.RunicPower.Loss");
    setRegenRate(RATE_POWER_SOUL_SHARDS, "Rate.SoulShards.Loss");
    setRegenRate(RATE_POWER_LUNAR_POWER, "Rate.LunarPower.Loss");
    setRegenRate(RATE_POWER_HOLY_POWER, "Rate.HolyPower.Loss");
    setRegenRate(RATE_POWER_MAELSTROM, "Rate.Maelstrom.Loss");
    setRegenRate(RATE_POWER_CHI, "Rate.Chi.Loss");
    setRegenRate(RATE_POWER_INSANITY, "Rate.Insanity.Loss");
    setRegenRate(RATE_POWER_ARCANE_CHARGES, "Rate.ArcaneCharges.Loss");
    setRegenRate(RATE_POWER_FURY, "Rate.Fury.Loss");
    setRegenRate(RATE_POWER_PAIN, "Rate.Pain.Loss");
    setRegenRate(RATE_POWER_ESSENCE, "Rate.Essence.Loss");

    rate_values[RATE_SKILL_DISCOVERY]      = sConfigMgr->GetFloatDefault("Rate.Skill.Discovery", 1.0f);
    rate_values[RATE_DROP_ITEM_POOR]       = sConfigMgr->GetFloatDefault("Rate.Drop.Item.Poor", 1.0f);
    rate_values[RATE_DROP_ITEM_NORMAL]     = sConfigMgr->GetFloatDefault("Rate.Drop.Item.Normal", 1.0f);
    rate_values[RATE_DROP_ITEM_UNCOMMON]   = sConfigMgr->GetFloatDefault("Rate.Drop.Item.Uncommon", 1.0f);
    rate_values[RATE_DROP_ITEM_RARE]       = sConfigMgr->GetFloatDefault("Rate.Drop.Item.Rare", 1.0f);
    rate_values[RATE_DROP_ITEM_EPIC]       = sConfigMgr->GetFloatDefault("Rate.Drop.Item.Epic", 1.0f);
    rate_values[RATE_DROP_ITEM_LEGENDARY]  = sConfigMgr->GetFloatDefault("Rate.Drop.Item.Legendary", 1.0f);
    rate_values[RATE_DROP_ITEM_ARTIFACT]   = sConfigMgr->GetFloatDefault("Rate.Drop.Item.Artifact", 1.0f);
    rate_values[RATE_DROP_ITEM_REFERENCED] = sConfigMgr->GetFloatDefault("Rate.Drop.Item.Referenced", 1.0f);
    rate_values[RATE_DROP_ITEM_REFERENCED_AMOUNT] = sConfigMgr->GetFloatDefault("Rate.Drop.Item.ReferencedAmount", 1.0f);
    rate_values[RATE_DROP_MONEY]  = sConfigMgr->GetFloatDefault("Rate.Drop.Money", 1.0f);
    rate_values[RATE_XP_KILL]     = sConfigMgr->GetFloatDefault("Rate.XP.Kill", 1.0f);
    rate_values[RATE_XP_BG_KILL]  = sConfigMgr->GetFloatDefault("Rate.XP.BattlegroundKill", 1.0f);
    rate_values[RATE_XP_QUEST]    = sConfigMgr->GetFloatDefault("Rate.XP.Quest", 1.0f);
    rate_values[RATE_XP_EXPLORE]  = sConfigMgr->GetFloatDefault("Rate.XP.Explore", 1.0f);

    m_int_configs[CONFIG_XP_BOOST_DAYMASK] = sConfigMgr->GetIntDefault("XP.Boost.Daymask", 0);
    rate_values[RATE_XP_BOOST] = sConfigMgr->GetFloatDefault("XP.Boost.Rate", 2.0f);

    rate_values[RATE_REPAIRCOST]  = sConfigMgr->GetFloatDefault("Rate.RepairCost", 1.0f);
    if (rate_values[RATE_REPAIRCOST] < 0.0f)
    {
        TC_LOG_ERROR("server.loading", "Rate.RepairCost ({}) must be >=0. Using 0.0 instead.", rate_values[RATE_REPAIRCOST]);
        rate_values[RATE_REPAIRCOST] = 0.0f;
    }
    rate_values[RATE_REPUTATION_GAIN]  = sConfigMgr->GetFloatDefault("Rate.Reputation.Gain", 1.0f);
    rate_values[RATE_REPUTATION_LOWLEVEL_KILL]  = sConfigMgr->GetFloatDefault("Rate.Reputation.LowLevel.Kill", 1.0f);
    rate_values[RATE_REPUTATION_LOWLEVEL_QUEST]  = sConfigMgr->GetFloatDefault("Rate.Reputation.LowLevel.Quest", 1.0f);
    rate_values[RATE_REPUTATION_RECRUIT_A_FRIEND_BONUS] = sConfigMgr->GetFloatDefault("Rate.Reputation.RecruitAFriendBonus", 0.1f);
    rate_values[RATE_CREATURE_NORMAL_DAMAGE]          = sConfigMgr->GetFloatDefault("Rate.Creature.Normal.Damage", 1.0f);
    rate_values[RATE_CREATURE_ELITE_ELITE_DAMAGE]     = sConfigMgr->GetFloatDefault("Rate.Creature.Elite.Elite.Damage", 1.0f);
    rate_values[RATE_CREATURE_ELITE_RAREELITE_DAMAGE] = sConfigMgr->GetFloatDefault("Rate.Creature.Elite.RAREELITE.Damage", 1.0f);
    rate_values[RATE_CREATURE_ELITE_WORLDBOSS_DAMAGE] = sConfigMgr->GetFloatDefault("Rate.Creature.Elite.WORLDBOSS.Damage", 1.0f);
    rate_values[RATE_CREATURE_ELITE_RARE_DAMAGE]      = sConfigMgr->GetFloatDefault("Rate.Creature.Elite.RARE.Damage", 1.0f);
    rate_values[RATE_CREATURE_NORMAL_HP]          = sConfigMgr->GetFloatDefault("Rate.Creature.Normal.HP", 1.0f);
    rate_values[RATE_CREATURE_ELITE_ELITE_HP]     = sConfigMgr->GetFloatDefault("Rate.Creature.Elite.Elite.HP", 1.0f);
    rate_values[RATE_CREATURE_ELITE_RAREELITE_HP] = sConfigMgr->GetFloatDefault("Rate.Creature.Elite.RAREELITE.HP", 1.0f);
    rate_values[RATE_CREATURE_ELITE_WORLDBOSS_HP] = sConfigMgr->GetFloatDefault("Rate.Creature.Elite.WORLDBOSS.HP", 1.0f);
    rate_values[RATE_CREATURE_ELITE_RARE_HP]      = sConfigMgr->GetFloatDefault("Rate.Creature.Elite.RARE.HP", 1.0f);
    rate_values[RATE_CREATURE_NORMAL_SPELLDAMAGE]          = sConfigMgr->GetFloatDefault("Rate.Creature.Normal.SpellDamage", 1.0f);
    rate_values[RATE_CREATURE_ELITE_ELITE_SPELLDAMAGE]     = sConfigMgr->GetFloatDefault("Rate.Creature.Elite.Elite.SpellDamage", 1.0f);
    rate_values[RATE_CREATURE_ELITE_RAREELITE_SPELLDAMAGE] = sConfigMgr->GetFloatDefault("Rate.Creature.Elite.RAREELITE.SpellDamage", 1.0f);
    rate_values[RATE_CREATURE_ELITE_WORLDBOSS_SPELLDAMAGE] = sConfigMgr->GetFloatDefault("Rate.Creature.Elite.WORLDBOSS.SpellDamage", 1.0f);
    rate_values[RATE_CREATURE_ELITE_RARE_SPELLDAMAGE]      = sConfigMgr->GetFloatDefault("Rate.Creature.Elite.RARE.SpellDamage", 1.0f);
    rate_values[RATE_CREATURE_AGGRO]  = sConfigMgr->GetFloatDefault("Rate.Creature.Aggro", 1.0f);
    rate_values[RATE_REST_INGAME]                    = sConfigMgr->GetFloatDefault("Rate.Rest.InGame", 1.0f);
    rate_values[RATE_REST_OFFLINE_IN_TAVERN_OR_CITY] = sConfigMgr->GetFloatDefault("Rate.Rest.Offline.InTavernOrCity", 1.0f);
    rate_values[RATE_REST_OFFLINE_IN_WILDERNESS]     = sConfigMgr->GetFloatDefault("Rate.Rest.Offline.InWilderness", 1.0f);
    rate_values[RATE_DAMAGE_FALL]  = sConfigMgr->GetFloatDefault("Rate.Damage.Fall", 1.0f);
    rate_values[RATE_AUCTION_TIME]  = sConfigMgr->GetFloatDefault("Rate.Auction.Time", 1.0f);
    rate_values[RATE_AUCTION_DEPOSIT] = sConfigMgr->GetFloatDefault("Rate.Auction.Deposit", 1.0f);
    rate_values[RATE_AUCTION_CUT] = sConfigMgr->GetFloatDefault("Rate.Auction.Cut", 1.0f);
    rate_values[RATE_HONOR] = sConfigMgr->GetFloatDefault("Rate.Honor", 1.0f);
    rate_values[RATE_INSTANCE_RESET_TIME] = sConfigMgr->GetFloatDefault("Rate.InstanceResetTime", 1.0f);
    rate_values[RATE_TALENT] = sConfigMgr->GetFloatDefault("Rate.Talent", 1.0f);
    if (rate_values[RATE_TALENT] < 0.0f)
    {
        TC_LOG_ERROR("server.loading", "Rate.Talent ({}) must be > 0. Using 1 instead.", rate_values[RATE_TALENT]);
        rate_values[RATE_TALENT] = 1.0f;
    }
    rate_values[RATE_MOVESPEED] = sConfigMgr->GetFloatDefault("Rate.MoveSpeed", 1.0f);
    if (rate_values[RATE_MOVESPEED] < 0)
    {
        TC_LOG_ERROR("server.loading", "Rate.MoveSpeed ({}) must be > 0. Using 1 instead.", rate_values[RATE_MOVESPEED]);
        rate_values[RATE_MOVESPEED] = 1.0f;
    }
    for (uint8 i = 0; i < MAX_MOVE_TYPE; ++i) playerBaseMoveSpeed[i] = baseMoveSpeed[i] * rate_values[RATE_MOVESPEED];
    rate_values[RATE_CORPSE_DECAY_LOOTED] = sConfigMgr->GetFloatDefault("Rate.Corpse.Decay.Looted", 0.5f);

    rate_values[RATE_DURABILITY_LOSS_ON_DEATH]  = sConfigMgr->GetFloatDefault("DurabilityLoss.OnDeath", 10.0f);
    if (rate_values[RATE_DURABILITY_LOSS_ON_DEATH] < 0.0f)
    {
        TC_LOG_ERROR("server.loading", "DurabilityLoss.OnDeath ({}) must be >=0. Using 0.0 instead.", rate_values[RATE_DURABILITY_LOSS_ON_DEATH]);
        rate_values[RATE_DURABILITY_LOSS_ON_DEATH] = 0.0f;
    }
    if (rate_values[RATE_DURABILITY_LOSS_ON_DEATH] > 100.0f)
    {
        TC_LOG_ERROR("server.loading", "DurabilityLoss.OnDeath ({}) must be <= 100. Using 100.0 instead.", rate_values[RATE_DURABILITY_LOSS_ON_DEATH]);
        rate_values[RATE_DURABILITY_LOSS_ON_DEATH] = 0.0f;
    }
    rate_values[RATE_DURABILITY_LOSS_ON_DEATH] = rate_values[RATE_DURABILITY_LOSS_ON_DEATH] / 100.0f;

    rate_values[RATE_DURABILITY_LOSS_DAMAGE] = sConfigMgr->GetFloatDefault("DurabilityLossChance.Damage", 0.5f);
    if (rate_values[RATE_DURABILITY_LOSS_DAMAGE] < 0.0f)
    {
        TC_LOG_ERROR("server.loading", "DurabilityLossChance.Damage ({}) must be >=0. Using 0.0 instead.", rate_values[RATE_DURABILITY_LOSS_DAMAGE]);
        rate_values[RATE_DURABILITY_LOSS_DAMAGE] = 0.0f;
    }
    rate_values[RATE_DURABILITY_LOSS_ABSORB] = sConfigMgr->GetFloatDefault("DurabilityLossChance.Absorb", 0.5f);
    if (rate_values[RATE_DURABILITY_LOSS_ABSORB] < 0.0f)
    {
        TC_LOG_ERROR("server.loading", "DurabilityLossChance.Absorb ({}) must be >=0. Using 0.0 instead.", rate_values[RATE_DURABILITY_LOSS_ABSORB]);
        rate_values[RATE_DURABILITY_LOSS_ABSORB] = 0.0f;
    }
    rate_values[RATE_DURABILITY_LOSS_PARRY] = sConfigMgr->GetFloatDefault("DurabilityLossChance.Parry", 0.05f);
    if (rate_values[RATE_DURABILITY_LOSS_PARRY] < 0.0f)
    {
        TC_LOG_ERROR("server.loading", "DurabilityLossChance.Parry ({}) must be >=0. Using 0.0 instead.", rate_values[RATE_DURABILITY_LOSS_PARRY]);
        rate_values[RATE_DURABILITY_LOSS_PARRY] = 0.0f;
    }
    rate_values[RATE_DURABILITY_LOSS_BLOCK] = sConfigMgr->GetFloatDefault("DurabilityLossChance.Block", 0.05f);
    if (rate_values[RATE_DURABILITY_LOSS_BLOCK] < 0.0f)
    {
        TC_LOG_ERROR("server.loading", "DurabilityLossChance.Block ({}) must be >=0. Using 0.0 instead.", rate_values[RATE_DURABILITY_LOSS_BLOCK]);
        rate_values[RATE_DURABILITY_LOSS_BLOCK] = 0.0f;
    }
    rate_values[RATE_MONEY_QUEST] = sConfigMgr->GetFloatDefault("Rate.Quest.Money.Reward", 1.0f);
    if (rate_values[RATE_MONEY_QUEST] < 0.0f)
    {
        TC_LOG_ERROR("server.loading", "Rate.Quest.Money.Reward ({}) must be >=0. Using 0 instead.", rate_values[RATE_MONEY_QUEST]);
        rate_values[RATE_MONEY_QUEST] = 0.0f;
    }
    rate_values[RATE_MONEY_MAX_LEVEL_QUEST] = sConfigMgr->GetFloatDefault("Rate.Quest.Money.Max.Level.Reward", 1.0f);
    if (rate_values[RATE_MONEY_MAX_LEVEL_QUEST] < 0.0f)
    {
        TC_LOG_ERROR("server.loading", "Rate.Quest.Money.Max.Level.Reward ({}) must be >=0. Using 0 instead.", rate_values[RATE_MONEY_MAX_LEVEL_QUEST]);
        rate_values[RATE_MONEY_MAX_LEVEL_QUEST] = 0.0f;
    }
    ///- Read other configuration items from the config file

    m_bool_configs[CONFIG_DURABILITY_LOSS_IN_PVP] = sConfigMgr->GetBoolDefault("DurabilityLoss.InPvP", false);

    m_int_configs[CONFIG_COMPRESSION] = sConfigMgr->GetIntDefault("Compression", 1);
    if (m_int_configs[CONFIG_COMPRESSION] < 1 || m_int_configs[CONFIG_COMPRESSION] > 9)
    {
        TC_LOG_ERROR("server.loading", "Compression level ({}) must be in range 1..9. Using default compression level (1).", m_int_configs[CONFIG_COMPRESSION]);
        m_int_configs[CONFIG_COMPRESSION] = 1;
    }
    m_bool_configs[CONFIG_ADDON_CHANNEL] = sConfigMgr->GetBoolDefault("AddonChannel", true);
    m_bool_configs[CONFIG_CLEAN_CHARACTER_DB] = sConfigMgr->GetBoolDefault("CleanCharacterDB", false);
    m_int_configs[CONFIG_PERSISTENT_CHARACTER_CLEAN_FLAGS] = sConfigMgr->GetIntDefault("PersistentCharacterCleanFlags", 0);
    m_int_configs[CONFIG_AUCTION_REPLICATE_DELAY] = sConfigMgr->GetIntDefault("Auction.ReplicateItemsCooldown", 900);
    m_int_configs[CONFIG_AUCTION_SEARCH_DELAY] = sConfigMgr->GetIntDefault("Auction.SearchDelay", 300);
    if (m_int_configs[CONFIG_AUCTION_SEARCH_DELAY] < 100 || m_int_configs[CONFIG_AUCTION_SEARCH_DELAY] > 10000)
    {
        TC_LOG_ERROR("server.loading", "Auction.SearchDelay ({}) must be between 100 and 10000. Using default of 300ms", m_int_configs[CONFIG_AUCTION_SEARCH_DELAY]);
        m_int_configs[CONFIG_AUCTION_SEARCH_DELAY] = 300;
    }
    m_int_configs[CONFIG_AUCTION_TAINTED_SEARCH_DELAY] = sConfigMgr->GetIntDefault("Auction.TaintedSearchDelay", 3000);
    if (m_int_configs[CONFIG_AUCTION_TAINTED_SEARCH_DELAY] < 100 || m_int_configs[CONFIG_AUCTION_TAINTED_SEARCH_DELAY] > 10000)
    {
        TC_LOG_ERROR("server.loading", "Auction.TaintedSearchDelay ({}) must be between 100 and 10000. Using default of 3s", m_int_configs[CONFIG_AUCTION_SEARCH_DELAY]);
        m_int_configs[CONFIG_AUCTION_TAINTED_SEARCH_DELAY] = 3000;
    }
    m_int_configs[CONFIG_CHAT_CHANNEL_LEVEL_REQ] = sConfigMgr->GetIntDefault("ChatLevelReq.Channel", 1);
    m_int_configs[CONFIG_CHAT_WHISPER_LEVEL_REQ] = sConfigMgr->GetIntDefault("ChatLevelReq.Whisper", 1);
    m_int_configs[CONFIG_CHAT_EMOTE_LEVEL_REQ] = sConfigMgr->GetIntDefault("ChatLevelReq.Emote", 1);
    m_int_configs[CONFIG_CHAT_SAY_LEVEL_REQ] = sConfigMgr->GetIntDefault("ChatLevelReq.Say", 1);
    m_int_configs[CONFIG_CHAT_YELL_LEVEL_REQ] = sConfigMgr->GetIntDefault("ChatLevelReq.Yell", 1);
    m_int_configs[CONFIG_PARTY_LEVEL_REQ] = sConfigMgr->GetIntDefault("PartyLevelReq", 1);
    m_int_configs[CONFIG_TRADE_LEVEL_REQ] = sConfigMgr->GetIntDefault("LevelReq.Trade", 1);
    m_int_configs[CONFIG_AUCTION_LEVEL_REQ] = sConfigMgr->GetIntDefault("LevelReq.Auction", 1);
    m_int_configs[CONFIG_MAIL_LEVEL_REQ] = sConfigMgr->GetIntDefault("LevelReq.Mail", 1);
    m_bool_configs[CONFIG_PRESERVE_CUSTOM_CHANNELS] = sConfigMgr->GetBoolDefault("PreserveCustomChannels", false);
    m_int_configs[CONFIG_PRESERVE_CUSTOM_CHANNEL_DURATION] = sConfigMgr->GetIntDefault("PreserveCustomChannelDuration", 14);
    m_int_configs[CONFIG_PRESERVE_CUSTOM_CHANNEL_INTERVAL] = sConfigMgr->GetIntDefault("PreserveCustomChannelInterval", 5);
    m_bool_configs[CONFIG_GRID_UNLOAD] = sConfigMgr->GetBoolDefault("GridUnload", true);
    m_bool_configs[CONFIG_BASEMAP_LOAD_GRIDS] = sConfigMgr->GetBoolDefault("BaseMapLoadAllGrids", false);
    if (m_bool_configs[CONFIG_BASEMAP_LOAD_GRIDS] && m_bool_configs[CONFIG_GRID_UNLOAD])
    {
        TC_LOG_ERROR("server.loading", "BaseMapLoadAllGrids enabled, but GridUnload also enabled. GridUnload must be disabled to enable base map pre-loading. Base map pre-loading disabled");
        m_bool_configs[CONFIG_BASEMAP_LOAD_GRIDS] = false;
    }
    m_bool_configs[CONFIG_INSTANCEMAP_LOAD_GRIDS] = sConfigMgr->GetBoolDefault("InstanceMapLoadAllGrids", false);
    if (m_bool_configs[CONFIG_INSTANCEMAP_LOAD_GRIDS] && m_bool_configs[CONFIG_GRID_UNLOAD])
    {
        TC_LOG_ERROR("server.loading", "InstanceMapLoadAllGrids enabled, but GridUnload also enabled. GridUnload must be disabled to enable instance map pre-loading. Instance map pre-loading disabled");
        m_bool_configs[CONFIG_INSTANCEMAP_LOAD_GRIDS] = false;
    }
    m_bool_configs[CONFIG_BATTLEGROUNDMAP_LOAD_GRIDS] = sConfigMgr->GetBoolDefault("BattlegroundMapLoadAllGrids", true);
    m_int_configs[CONFIG_INTERVAL_SAVE] = sConfigMgr->GetIntDefault("PlayerSaveInterval", 15 * MINUTE * IN_MILLISECONDS);
    m_int_configs[CONFIG_INTERVAL_DISCONNECT_TOLERANCE] = sConfigMgr->GetIntDefault("DisconnectToleranceInterval", 0);
    m_bool_configs[CONFIG_STATS_SAVE_ONLY_ON_LOGOUT] = sConfigMgr->GetBoolDefault("PlayerSave.Stats.SaveOnlyOnLogout", true);

    m_int_configs[CONFIG_MIN_LEVEL_STAT_SAVE] = sConfigMgr->GetIntDefault("PlayerSave.Stats.MinLevel", 0);
    if (m_int_configs[CONFIG_MIN_LEVEL_STAT_SAVE] > MAX_LEVEL)
    {
        TC_LOG_ERROR("server.loading", "PlayerSave.Stats.MinLevel ({}) must be in range 0..80. Using default, do not save character stats (0).", m_int_configs[CONFIG_MIN_LEVEL_STAT_SAVE]);
        m_int_configs[CONFIG_MIN_LEVEL_STAT_SAVE] = 0;
    }

    m_int_configs[CONFIG_INTERVAL_GRIDCLEAN] = sConfigMgr->GetIntDefault("GridCleanUpDelay", 5 * MINUTE * IN_MILLISECONDS);
    if (m_int_configs[CONFIG_INTERVAL_GRIDCLEAN] < MIN_GRID_DELAY)
    {
        TC_LOG_ERROR("server.loading", "GridCleanUpDelay ({}) must be greater {}. Use this minimal value.", m_int_configs[CONFIG_INTERVAL_GRIDCLEAN], MIN_GRID_DELAY);
        m_int_configs[CONFIG_INTERVAL_GRIDCLEAN] = MIN_GRID_DELAY;
    }
    if (reload)
        sMapMgr->SetGridCleanUpDelay(m_int_configs[CONFIG_INTERVAL_GRIDCLEAN]);

    m_int_configs[CONFIG_INTERVAL_MAPUPDATE] = sConfigMgr->GetIntDefault("MapUpdateInterval", 10);
    if (m_int_configs[CONFIG_INTERVAL_MAPUPDATE] < MIN_MAP_UPDATE_DELAY)
    {
        TC_LOG_ERROR("server.loading", "MapUpdateInterval ({}) must be greater {}. Use this minimal value.", m_int_configs[CONFIG_INTERVAL_MAPUPDATE], MIN_MAP_UPDATE_DELAY);
        m_int_configs[CONFIG_INTERVAL_MAPUPDATE] = MIN_MAP_UPDATE_DELAY;
    }
    if (reload)
        sMapMgr->SetMapUpdateInterval(m_int_configs[CONFIG_INTERVAL_MAPUPDATE]);

    m_int_configs[CONFIG_INTERVAL_CHANGEWEATHER] = sConfigMgr->GetIntDefault("ChangeWeatherInterval", 10 * MINUTE * IN_MILLISECONDS);

    if (reload)
    {
        uint32 val = sConfigMgr->GetIntDefault("WorldServerPort", 8085);
        if (val != m_int_configs[CONFIG_PORT_WORLD])
            TC_LOG_ERROR("server.loading", "WorldServerPort option can't be changed at worldserver.conf reload, using current value ({}).", m_int_configs[CONFIG_PORT_WORLD]);

        val = sConfigMgr->GetIntDefault("InstanceServerPort", 8086);
        if (val != m_int_configs[CONFIG_PORT_INSTANCE])
            TC_LOG_ERROR("server.loading", "InstanceServerPort option can't be changed at worldserver.conf reload, using current value ({}).", m_int_configs[CONFIG_PORT_INSTANCE]);
    }
    else
    {
        m_int_configs[CONFIG_PORT_WORLD] = sConfigMgr->GetIntDefault("WorldServerPort", 8085);
        m_int_configs[CONFIG_PORT_INSTANCE] = sConfigMgr->GetIntDefault("InstanceServerPort", 8086);
    }

    // Config values are in "milliseconds" but we handle SocketTimeOut only as "seconds" so divide by 1000
    m_int_configs[CONFIG_SOCKET_TIMEOUTTIME] = sConfigMgr->GetIntDefault("SocketTimeOutTime", 900000) / 1000;
    m_int_configs[CONFIG_SOCKET_TIMEOUTTIME_ACTIVE] = sConfigMgr->GetIntDefault("SocketTimeOutTimeActive", 60000) / 1000;

    m_int_configs[CONFIG_SESSION_ADD_DELAY] = sConfigMgr->GetIntDefault("SessionAddDelay", 10000);

    m_float_configs[CONFIG_GROUP_XP_DISTANCE] = sConfigMgr->GetFloatDefault("MaxGroupXPDistance", 74.0f);
    m_float_configs[CONFIG_MAX_RECRUIT_A_FRIEND_DISTANCE] = sConfigMgr->GetFloatDefault("MaxRecruitAFriendBonusDistance", 100.0f);

    m_int_configs[CONFIG_MIN_QUEST_SCALED_XP_RATIO] = sConfigMgr->GetIntDefault("MinQuestScaledXPRatio", 0);
    if (m_int_configs[CONFIG_MIN_QUEST_SCALED_XP_RATIO] > 100)
    {
        TC_LOG_ERROR("server.loading", "MinQuestScaledXPRatio ({}) must be in range 0..100. Set to 0.", m_int_configs[CONFIG_MIN_QUEST_SCALED_XP_RATIO]);
        m_int_configs[CONFIG_MIN_QUEST_SCALED_XP_RATIO] = 0;
    }

    m_int_configs[CONFIG_MIN_CREATURE_SCALED_XP_RATIO] = sConfigMgr->GetIntDefault("MinCreatureScaledXPRatio", 0);
    if (m_int_configs[CONFIG_MIN_CREATURE_SCALED_XP_RATIO] > 100)
    {
        TC_LOG_ERROR("server.loading", "MinCreatureScaledXPRatio ({}) must be in range 0..100. Set to 0.", m_int_configs[CONFIG_MIN_CREATURE_SCALED_XP_RATIO]);
        m_int_configs[CONFIG_MIN_CREATURE_SCALED_XP_RATIO] = 0;
    }

    m_int_configs[CONFIG_MIN_DISCOVERED_SCALED_XP_RATIO] = sConfigMgr->GetIntDefault("MinDiscoveredScaledXPRatio", 0);
    if (m_int_configs[CONFIG_MIN_DISCOVERED_SCALED_XP_RATIO] > 100)
    {
        TC_LOG_ERROR("server.loading", "MinDiscoveredScaledXPRatio ({}) must be in range 0..100. Set to 0.", m_int_configs[CONFIG_MIN_DISCOVERED_SCALED_XP_RATIO]);
        m_int_configs[CONFIG_MIN_DISCOVERED_SCALED_XP_RATIO] = 0;
    }

    /// @todo Add MonsterSight (with meaning) in worldserver.conf or put them as define
    m_float_configs[CONFIG_SIGHT_MONSTER] = sConfigMgr->GetFloatDefault("MonsterSight", 50.0f);

    m_bool_configs[CONFIG_REGEN_HP_CANNOT_REACH_TARGET_IN_RAID] = sConfigMgr->GetBoolDefault("Creature.RegenHPCannotReachTargetInRaid", true);

    if (reload)
    {
        uint32 val = sConfigMgr->GetIntDefault("GameType", 0);
        if (val != m_int_configs[CONFIG_GAME_TYPE])
            TC_LOG_ERROR("server.loading", "GameType option can't be changed at worldserver.conf reload, using current value ({}).", m_int_configs[CONFIG_GAME_TYPE]);
    }
    else
        m_int_configs[CONFIG_GAME_TYPE] = sConfigMgr->GetIntDefault("GameType", 0);

    if (reload)
    {
        uint32 val = sConfigMgr->GetIntDefault("RealmZone", HARDCODED_DEVELOPMENT_REALM_CATEGORY_ID);
        if (val != m_int_configs[CONFIG_REALM_ZONE])
            TC_LOG_ERROR("server.loading", "RealmZone option can't be changed at worldserver.conf reload, using current value ({}).", m_int_configs[CONFIG_REALM_ZONE]);
    }
    else
        m_int_configs[CONFIG_REALM_ZONE] = sConfigMgr->GetIntDefault("RealmZone", HARDCODED_DEVELOPMENT_REALM_CATEGORY_ID);

    m_bool_configs[CONFIG_ALLOW_TWO_SIDE_INTERACTION_CALENDAR]= sConfigMgr->GetBoolDefault("AllowTwoSide.Interaction.Calendar", false);
    m_bool_configs[CONFIG_ALLOW_TWO_SIDE_INTERACTION_CHANNEL] = sConfigMgr->GetBoolDefault("AllowTwoSide.Interaction.Channel", false);
    m_bool_configs[CONFIG_ALLOW_TWO_SIDE_INTERACTION_GROUP]   = sConfigMgr->GetBoolDefault("AllowTwoSide.Interaction.Group", false);
    m_bool_configs[CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD]   = sConfigMgr->GetBoolDefault("AllowTwoSide.Interaction.Guild", false);
    m_bool_configs[CONFIG_ALLOW_TWO_SIDE_INTERACTION_AUCTION] = sConfigMgr->GetBoolDefault("AllowTwoSide.Interaction.Auction", true);
    m_bool_configs[CONFIG_ALLOW_TWO_SIDE_TRADE]               = sConfigMgr->GetBoolDefault("AllowTwoSide.Trade", false);
    m_int_configs[CONFIG_STRICT_PLAYER_NAMES]                 = sConfigMgr->GetIntDefault ("StrictPlayerNames",  0);
    m_int_configs[CONFIG_STRICT_CHARTER_NAMES]                = sConfigMgr->GetIntDefault ("StrictCharterNames", 0);
    m_int_configs[CONFIG_STRICT_PET_NAMES]                    = sConfigMgr->GetIntDefault ("StrictPetNames",     0);

    m_int_configs[CONFIG_MIN_PLAYER_NAME]                     = sConfigMgr->GetIntDefault ("MinPlayerName",  2);
    if (m_int_configs[CONFIG_MIN_PLAYER_NAME] < 1 || m_int_configs[CONFIG_MIN_PLAYER_NAME] > MAX_PLAYER_NAME)
    {
        TC_LOG_ERROR("server.loading", "MinPlayerName ({}) must be in range 1..{}. Set to 2.", m_int_configs[CONFIG_MIN_PLAYER_NAME], MAX_PLAYER_NAME);
        m_int_configs[CONFIG_MIN_PLAYER_NAME] = 2;
    }

    m_int_configs[CONFIG_MIN_CHARTER_NAME]                    = sConfigMgr->GetIntDefault ("MinCharterName", 2);
    if (m_int_configs[CONFIG_MIN_CHARTER_NAME] < 1 || m_int_configs[CONFIG_MIN_CHARTER_NAME] > MAX_CHARTER_NAME)
    {
        TC_LOG_ERROR("server.loading", "MinCharterName ({}) must be in range 1..{}. Set to 2.", m_int_configs[CONFIG_MIN_CHARTER_NAME], MAX_CHARTER_NAME);
        m_int_configs[CONFIG_MIN_CHARTER_NAME] = 2;
    }

    m_int_configs[CONFIG_MIN_PET_NAME]                        = sConfigMgr->GetIntDefault ("MinPetName",     2);
    if (m_int_configs[CONFIG_MIN_PET_NAME] < 1 || m_int_configs[CONFIG_MIN_PET_NAME] > MAX_PET_NAME)
    {
        TC_LOG_ERROR("server.loading", "MinPetName ({}) must be in range 1..{}. Set to 2.", m_int_configs[CONFIG_MIN_PET_NAME], MAX_PET_NAME);
        m_int_configs[CONFIG_MIN_PET_NAME] = 2;
    }

    m_int_configs[CONFIG_CHARTER_COST_GUILD] = sConfigMgr->GetIntDefault("Guild.CharterCost", 1000);
    m_int_configs[CONFIG_CHARTER_COST_ARENA_2v2] = sConfigMgr->GetIntDefault("ArenaTeam.CharterCost.2v2", 800000);
    m_int_configs[CONFIG_CHARTER_COST_ARENA_3v3] = sConfigMgr->GetIntDefault("ArenaTeam.CharterCost.3v3", 1200000);
    m_int_configs[CONFIG_CHARTER_COST_ARENA_5v5] = sConfigMgr->GetIntDefault("ArenaTeam.CharterCost.5v5", 2000000);

    m_int_configs[CONFIG_CHARACTER_CREATING_DISABLED] = sConfigMgr->GetIntDefault("CharacterCreating.Disabled", 0);
    m_int64_configs[CONFIG_CHARACTER_CREATING_DISABLED_RACEMASK] = sConfigMgr->GetInt64Default("CharacterCreating.Disabled.RaceMask", 0);
    m_int_configs[CONFIG_CHARACTER_CREATING_DISABLED_CLASSMASK] = sConfigMgr->GetIntDefault("CharacterCreating.Disabled.ClassMask", 0);

    m_int_configs[CONFIG_CHARACTERS_PER_REALM] = sConfigMgr->GetIntDefault("CharactersPerRealm", 60);
    if (m_int_configs[CONFIG_CHARACTERS_PER_REALM] < 1 || m_int_configs[CONFIG_CHARACTERS_PER_REALM] > MAX_CHARACTERS_PER_REALM)
    {
        TC_LOG_ERROR("server.loading", "CharactersPerRealm ({}) must be in range 1..{}. Set to {}.", m_int_configs[CONFIG_CHARACTERS_PER_REALM], MAX_CHARACTERS_PER_REALM, MAX_CHARACTERS_PER_REALM);
        m_int_configs[CONFIG_CHARACTERS_PER_REALM] = MAX_CHARACTERS_PER_REALM;
    }

    // must be after CONFIG_CHARACTERS_PER_REALM
    m_int_configs[CONFIG_CHARACTERS_PER_ACCOUNT] = sConfigMgr->GetIntDefault("CharactersPerAccount", 60);
    if (m_int_configs[CONFIG_CHARACTERS_PER_ACCOUNT] < m_int_configs[CONFIG_CHARACTERS_PER_REALM])
    {
        TC_LOG_ERROR("server.loading", "CharactersPerAccount ({}) can't be less than CharactersPerRealm ({}).", m_int_configs[CONFIG_CHARACTERS_PER_ACCOUNT], m_int_configs[CONFIG_CHARACTERS_PER_REALM]);
        m_int_configs[CONFIG_CHARACTERS_PER_ACCOUNT] = m_int_configs[CONFIG_CHARACTERS_PER_REALM];
    }

    m_int_configs[CONFIG_CHARACTER_CREATING_EVOKERS_PER_REALM] = sConfigMgr->GetIntDefault("CharacterCreating.EvokersPerRealm", 1);
    if (int32(m_int_configs[CONFIG_CHARACTER_CREATING_EVOKERS_PER_REALM]) < 0 || m_int_configs[CONFIG_CHARACTER_CREATING_EVOKERS_PER_REALM] > 10)
    {
        TC_LOG_ERROR("server.loading", "CharacterCreating.EvokersPerRealm ({}) must be in range 0..10. Set to 1.", m_int_configs[CONFIG_CHARACTER_CREATING_EVOKERS_PER_REALM]);
        m_int_configs[CONFIG_CHARACTER_CREATING_EVOKERS_PER_REALM] = 1;
    }

    m_int_configs[CONFIG_CHARACTER_CREATING_MIN_LEVEL_FOR_DEMON_HUNTER] = sConfigMgr->GetIntDefault("CharacterCreating.MinLevelForDemonHunter", 0);
    m_int_configs[CONFIG_CHARACTER_CREATING_MIN_LEVEL_FOR_EVOKER] = sConfigMgr->GetIntDefault("CharacterCreating.MinLevelForEvoker", 50);
    m_bool_configs[CONFIG_CHARACTER_CREATING_DISABLE_ALLIED_RACE_ACHIEVEMENT_REQUIREMENT] = sConfigMgr->GetBoolDefault("CharacterCreating.DisableAlliedRaceAchievementRequirement", false);

    m_int_configs[CONFIG_SKIP_CINEMATICS] = sConfigMgr->GetIntDefault("SkipCinematics", 0);
    if (int32(m_int_configs[CONFIG_SKIP_CINEMATICS]) < 0 || m_int_configs[CONFIG_SKIP_CINEMATICS] > 2)
    {
        TC_LOG_ERROR("server.loading", "SkipCinematics ({}) must be in range 0..2. Set to 0.", m_int_configs[CONFIG_SKIP_CINEMATICS]);
        m_int_configs[CONFIG_SKIP_CINEMATICS] = 0;
    }

    if (reload)
    {
        uint32 val = sConfigMgr->GetIntDefault("MaxPlayerLevel", DEFAULT_MAX_LEVEL);
        if (val != m_int_configs[CONFIG_MAX_PLAYER_LEVEL])
            TC_LOG_ERROR("server.loading", "MaxPlayerLevel option can't be changed at config reload, using current value ({}).", m_int_configs[CONFIG_MAX_PLAYER_LEVEL]);
    }
    else
        m_int_configs[CONFIG_MAX_PLAYER_LEVEL] = sConfigMgr->GetIntDefault("MaxPlayerLevel", DEFAULT_MAX_LEVEL);

    if (m_int_configs[CONFIG_MAX_PLAYER_LEVEL] > MAX_LEVEL)
    {
        TC_LOG_ERROR("server.loading", "MaxPlayerLevel ({}) must be in range 1..{}. Set to {}.", m_int_configs[CONFIG_MAX_PLAYER_LEVEL], MAX_LEVEL, MAX_LEVEL);
        m_int_configs[CONFIG_MAX_PLAYER_LEVEL] = MAX_LEVEL;
    }

    m_int_configs[CONFIG_MIN_DUALSPEC_LEVEL] = sConfigMgr->GetIntDefault("MinDualSpecLevel", 40);

    m_int_configs[CONFIG_START_PLAYER_LEVEL] = sConfigMgr->GetIntDefault("StartPlayerLevel", 1);
    if (m_int_configs[CONFIG_START_PLAYER_LEVEL] < 1)
    {
        TC_LOG_ERROR("server.loading", "StartPlayerLevel ({}) must be in range 1..MaxPlayerLevel({}). Set to 1.", m_int_configs[CONFIG_START_PLAYER_LEVEL], m_int_configs[CONFIG_MAX_PLAYER_LEVEL]);
        m_int_configs[CONFIG_START_PLAYER_LEVEL] = 1;
    }
    else if (m_int_configs[CONFIG_START_PLAYER_LEVEL] > m_int_configs[CONFIG_MAX_PLAYER_LEVEL])
    {
        TC_LOG_ERROR("server.loading", "StartPlayerLevel ({}) must be in range 1..MaxPlayerLevel({}). Set to {}.", m_int_configs[CONFIG_START_PLAYER_LEVEL], m_int_configs[CONFIG_MAX_PLAYER_LEVEL], m_int_configs[CONFIG_MAX_PLAYER_LEVEL]);
        m_int_configs[CONFIG_START_PLAYER_LEVEL] = m_int_configs[CONFIG_MAX_PLAYER_LEVEL];
    }

    m_int_configs[CONFIG_START_DEATH_KNIGHT_PLAYER_LEVEL] = sConfigMgr->GetIntDefault("StartDeathKnightPlayerLevel", 8);
    if (m_int_configs[CONFIG_START_DEATH_KNIGHT_PLAYER_LEVEL] < 1)
    {
        TC_LOG_ERROR("server.loading", "StartDeathKnightPlayerLevel ({}) must be in range 1..MaxPlayerLevel({}). Set to 1.",
            m_int_configs[CONFIG_START_DEATH_KNIGHT_PLAYER_LEVEL], m_int_configs[CONFIG_MAX_PLAYER_LEVEL]);
        m_int_configs[CONFIG_START_DEATH_KNIGHT_PLAYER_LEVEL] = 1;
    }
    else if (m_int_configs[CONFIG_START_DEATH_KNIGHT_PLAYER_LEVEL] > m_int_configs[CONFIG_MAX_PLAYER_LEVEL])
    {
        TC_LOG_ERROR("server.loading", "StartDeathKnightPlayerLevel ({}) must be in range 1..MaxPlayerLevel({}). Set to {}.",
            m_int_configs[CONFIG_START_DEATH_KNIGHT_PLAYER_LEVEL], m_int_configs[CONFIG_MAX_PLAYER_LEVEL], m_int_configs[CONFIG_MAX_PLAYER_LEVEL]);
        m_int_configs[CONFIG_START_DEATH_KNIGHT_PLAYER_LEVEL] = m_int_configs[CONFIG_MAX_PLAYER_LEVEL];
    }

    m_int_configs[CONFIG_START_DEMON_HUNTER_PLAYER_LEVEL] = sConfigMgr->GetIntDefault("StartDemonHunterPlayerLevel", 8);
    if (m_int_configs[CONFIG_START_DEMON_HUNTER_PLAYER_LEVEL] < 1)
    {
        TC_LOG_ERROR("server.loading", "StartDemonHunterPlayerLevel ({}) must be in range 1..MaxPlayerLevel({}). Set to 1.",
            m_int_configs[CONFIG_START_DEMON_HUNTER_PLAYER_LEVEL], m_int_configs[CONFIG_MAX_PLAYER_LEVEL]);
        m_int_configs[CONFIG_START_DEMON_HUNTER_PLAYER_LEVEL] = 1;
    }
    else if (m_int_configs[CONFIG_START_DEMON_HUNTER_PLAYER_LEVEL] > m_int_configs[CONFIG_MAX_PLAYER_LEVEL])
    {
        TC_LOG_ERROR("server.loading", "StartDemonHunterPlayerLevel ({}) must be in range 1..MaxPlayerLevel({}). Set to {}.",
            m_int_configs[CONFIG_START_DEMON_HUNTER_PLAYER_LEVEL], m_int_configs[CONFIG_MAX_PLAYER_LEVEL], m_int_configs[CONFIG_MAX_PLAYER_LEVEL]);
        m_int_configs[CONFIG_START_DEMON_HUNTER_PLAYER_LEVEL] = m_int_configs[CONFIG_MAX_PLAYER_LEVEL];
    }

    m_int_configs[CONFIG_START_EVOKER_PLAYER_LEVEL] = sConfigMgr->GetIntDefault("StartEvokerPlayerLevel", 58);
    if (m_int_configs[CONFIG_START_EVOKER_PLAYER_LEVEL] < 1)
    {
        TC_LOG_ERROR("server.loading", "StartEvokerPlayerLevel ({}) must be in range 1..MaxPlayerLevel({}). Set to 1.",
            m_int_configs[CONFIG_START_EVOKER_PLAYER_LEVEL], m_int_configs[CONFIG_MAX_PLAYER_LEVEL]);
        m_int_configs[CONFIG_START_EVOKER_PLAYER_LEVEL] = 1;
    }
    else if (m_int_configs[CONFIG_START_EVOKER_PLAYER_LEVEL] > m_int_configs[CONFIG_MAX_PLAYER_LEVEL])
    {
        TC_LOG_ERROR("server.loading", "StartEvokerPlayerLevel ({}) must be in range 1..MaxPlayerLevel({}). Set to {}.",
            m_int_configs[CONFIG_START_EVOKER_PLAYER_LEVEL], m_int_configs[CONFIG_MAX_PLAYER_LEVEL], m_int_configs[CONFIG_MAX_PLAYER_LEVEL]);
        m_int_configs[CONFIG_START_EVOKER_PLAYER_LEVEL] = m_int_configs[CONFIG_MAX_PLAYER_LEVEL];
    }

    m_int_configs[CONFIG_START_ALLIED_RACE_LEVEL] = sConfigMgr->GetIntDefault("StartAlliedRacePlayerLevel", 10);
    if (m_int_configs[CONFIG_START_ALLIED_RACE_LEVEL] < 1)
    {
        TC_LOG_ERROR("server.loading", "StartDemonHunterPlayerLevel ({}) must be in range 1..MaxPlayerLevel({}). Set to 1.",
            m_int_configs[CONFIG_START_ALLIED_RACE_LEVEL], m_int_configs[CONFIG_MAX_PLAYER_LEVEL]);
        m_int_configs[CONFIG_START_ALLIED_RACE_LEVEL] = 1;
    }
    else if (m_int_configs[CONFIG_START_ALLIED_RACE_LEVEL] > m_int_configs[CONFIG_MAX_PLAYER_LEVEL])
    {
        TC_LOG_ERROR("server.loading", "StartDemonHunterPlayerLevel ({}) must be in range 1..MaxPlayerLevel({}). Set to {}.",
            m_int_configs[CONFIG_START_ALLIED_RACE_LEVEL], m_int_configs[CONFIG_MAX_PLAYER_LEVEL], m_int_configs[CONFIG_MAX_PLAYER_LEVEL]);
        m_int_configs[CONFIG_START_ALLIED_RACE_LEVEL] = m_int_configs[CONFIG_MAX_PLAYER_LEVEL];
    }

    m_int_configs[CONFIG_START_PLAYER_MONEY] = sConfigMgr->GetIntDefault("StartPlayerMoney", 0);
    if (int32(m_int_configs[CONFIG_START_PLAYER_MONEY]) < 0)
    {
        TC_LOG_ERROR("server.loading", "StartPlayerMoney ({}) must be in range 0..{}. Set to {}.", m_int_configs[CONFIG_START_PLAYER_MONEY], MAX_MONEY_AMOUNT, 0);
        m_int_configs[CONFIG_START_PLAYER_MONEY] = 0;
    }
    else if (m_int_configs[CONFIG_START_PLAYER_MONEY] > 0x7FFFFFFF-1) // TODO: (See MAX_MONEY_AMOUNT)
    {
        TC_LOG_ERROR("server.loading", "StartPlayerMoney ({}) must be in range 0..{}. Set to {}.",
            m_int_configs[CONFIG_START_PLAYER_MONEY], 0x7FFFFFFF-1, 0x7FFFFFFF-1);
        m_int_configs[CONFIG_START_PLAYER_MONEY] = 0x7FFFFFFF-1;
    }

    m_int_configs[CONFIG_CURRENCY_RESET_HOUR] = sConfigMgr->GetIntDefault("Currency.ResetHour", 3);
    if (m_int_configs[CONFIG_CURRENCY_RESET_HOUR] > 23)
    {
        TC_LOG_ERROR("server.loading", "Currency.ResetHour ({}) can't be load. Set to 6.", m_int_configs[CONFIG_CURRENCY_RESET_HOUR]);
        m_int_configs[CONFIG_CURRENCY_RESET_HOUR] = 3;
    }
    m_int_configs[CONFIG_CURRENCY_RESET_DAY] = sConfigMgr->GetIntDefault("Currency.ResetDay", 3);
    if (m_int_configs[CONFIG_CURRENCY_RESET_DAY] > 6)
    {
        TC_LOG_ERROR("server.loading", "Currency.ResetDay ({}) can't be load. Set to 3.", m_int_configs[CONFIG_CURRENCY_RESET_DAY]);
        m_int_configs[CONFIG_CURRENCY_RESET_DAY] = 3;
    }
    m_int_configs[CONFIG_CURRENCY_RESET_INTERVAL] = sConfigMgr->GetIntDefault("Currency.ResetInterval", 7);
    if (int32(m_int_configs[CONFIG_CURRENCY_RESET_INTERVAL]) <= 0)
    {
        TC_LOG_ERROR("server.loading", "Currency.ResetInterval ({}) must be > 0, set to default 7.", m_int_configs[CONFIG_CURRENCY_RESET_INTERVAL]);
        m_int_configs[CONFIG_CURRENCY_RESET_INTERVAL] = 7;
    }

    m_int_configs[CONFIG_MAX_RECRUIT_A_FRIEND_BONUS_PLAYER_LEVEL] = sConfigMgr->GetIntDefault("RecruitAFriend.MaxLevel", 85);
    if (m_int_configs[CONFIG_MAX_RECRUIT_A_FRIEND_BONUS_PLAYER_LEVEL] > m_int_configs[CONFIG_MAX_PLAYER_LEVEL])
    {
        TC_LOG_ERROR("server.loading", "RecruitAFriend.MaxLevel ({}) must be in the range 0..MaxLevel({}). Set to {}.",
            m_int_configs[CONFIG_MAX_RECRUIT_A_FRIEND_BONUS_PLAYER_LEVEL], m_int_configs[CONFIG_MAX_PLAYER_LEVEL], 85);
        m_int_configs[CONFIG_MAX_RECRUIT_A_FRIEND_BONUS_PLAYER_LEVEL] = 85;
    }

    m_int_configs[CONFIG_MAX_RECRUIT_A_FRIEND_BONUS_PLAYER_LEVEL_DIFFERENCE] = sConfigMgr->GetIntDefault("RecruitAFriend.MaxDifference", 4);
    m_bool_configs[CONFIG_ALL_TAXI_PATHS] = sConfigMgr->GetBoolDefault("AllFlightPaths", false);
    m_bool_configs[CONFIG_INSTANT_TAXI] = sConfigMgr->GetBoolDefault("InstantFlightPaths", false);

    m_bool_configs[CONFIG_INSTANCE_IGNORE_LEVEL] = sConfigMgr->GetBoolDefault("Instance.IgnoreLevel", false);
    m_bool_configs[CONFIG_INSTANCE_IGNORE_RAID]  = sConfigMgr->GetBoolDefault("Instance.IgnoreRaid", false);

    m_bool_configs[CONFIG_CAST_UNSTUCK] = sConfigMgr->GetBoolDefault("CastUnstuck", true);
    m_int_configs[CONFIG_RESET_SCHEDULE_WEEK_DAY]  = sConfigMgr->GetIntDefault("ResetSchedule.WeekDay", 2);
    m_int_configs[CONFIG_RESET_SCHEDULE_HOUR]  = sConfigMgr->GetIntDefault("ResetSchedule.Hour", 8);
    m_int_configs[CONFIG_INSTANCE_UNLOAD_DELAY] = sConfigMgr->GetIntDefault("Instance.UnloadDelay", 30 * MINUTE * IN_MILLISECONDS);

    m_int_configs[CONFIG_DAILY_QUEST_RESET_TIME_HOUR] = sConfigMgr->GetIntDefault("Quests.DailyResetTime", 3);
    if (m_int_configs[CONFIG_DAILY_QUEST_RESET_TIME_HOUR] > 23)
    {
        TC_LOG_ERROR("server.loading", "Quests.DailyResetTime ({}) must be in range 0..23. Set to 3.", m_int_configs[CONFIG_DAILY_QUEST_RESET_TIME_HOUR]);
        m_int_configs[CONFIG_DAILY_QUEST_RESET_TIME_HOUR] = 3;
    }

    m_int_configs[CONFIG_WEEKLY_QUEST_RESET_TIME_WDAY] = sConfigMgr->GetIntDefault("Quests.WeeklyResetWDay", 3);
    if (m_int_configs[CONFIG_WEEKLY_QUEST_RESET_TIME_WDAY] > 6)
    {
        TC_LOG_ERROR("server.loading", "Quests.WeeklyResetDay ({}) must be in range 0..6. Set to 3 (Wednesday).", m_int_configs[CONFIG_WEEKLY_QUEST_RESET_TIME_WDAY]);
        m_int_configs[CONFIG_WEEKLY_QUEST_RESET_TIME_WDAY] = 3;
    }

    m_int_configs[CONFIG_MAX_PRIMARY_TRADE_SKILL] = sConfigMgr->GetIntDefault("MaxPrimaryTradeSkill", 2);
    m_int_configs[CONFIG_MIN_PETITION_SIGNS] = sConfigMgr->GetIntDefault("MinPetitionSigns", 4);
    if (m_int_configs[CONFIG_MIN_PETITION_SIGNS] > 4)
    {
        TC_LOG_ERROR("server.loading", "MinPetitionSigns ({}) must be in range 0..4. Set to 4.", m_int_configs[CONFIG_MIN_PETITION_SIGNS]);
        m_int_configs[CONFIG_MIN_PETITION_SIGNS] = 4;
    }

    m_int_configs[CONFIG_GM_LOGIN_STATE]        = sConfigMgr->GetIntDefault("GM.LoginState", 2);
    m_int_configs[CONFIG_GM_VISIBLE_STATE]      = sConfigMgr->GetIntDefault("GM.Visible", 2);
    m_int_configs[CONFIG_GM_CHAT]               = sConfigMgr->GetIntDefault("GM.Chat", 2);
    m_int_configs[CONFIG_GM_WHISPERING_TO]      = sConfigMgr->GetIntDefault("GM.WhisperingTo", 2);
    m_int_configs[CONFIG_GM_FREEZE_DURATION]    = sConfigMgr->GetIntDefault("GM.FreezeAuraDuration", 0);

    m_int_configs[CONFIG_GM_LEVEL_IN_GM_LIST]   = sConfigMgr->GetIntDefault("GM.InGMList.Level", SEC_ADMINISTRATOR);
    m_int_configs[CONFIG_GM_LEVEL_IN_WHO_LIST]  = sConfigMgr->GetIntDefault("GM.InWhoList.Level", SEC_ADMINISTRATOR);
    m_int_configs[CONFIG_START_GM_LEVEL]        = sConfigMgr->GetIntDefault("GM.StartLevel", 1);
    if (m_int_configs[CONFIG_START_GM_LEVEL] < m_int_configs[CONFIG_START_PLAYER_LEVEL])
    {
        TC_LOG_ERROR("server.loading", "GM.StartLevel ({}) must be in range StartPlayerLevel({})..{}. Set to {}.",
            m_int_configs[CONFIG_START_GM_LEVEL], m_int_configs[CONFIG_START_PLAYER_LEVEL], MAX_LEVEL, m_int_configs[CONFIG_START_PLAYER_LEVEL]);
        m_int_configs[CONFIG_START_GM_LEVEL] = m_int_configs[CONFIG_START_PLAYER_LEVEL];
    }
    else if (m_int_configs[CONFIG_START_GM_LEVEL] > MAX_LEVEL)
    {
        TC_LOG_ERROR("server.loading", "GM.StartLevel ({}) must be in range 1..{}. Set to {}.", m_int_configs[CONFIG_START_GM_LEVEL], MAX_LEVEL, MAX_LEVEL);
        m_int_configs[CONFIG_START_GM_LEVEL] = MAX_LEVEL;
    }
    m_bool_configs[CONFIG_ALLOW_GM_GROUP]       = sConfigMgr->GetBoolDefault("GM.AllowInvite", false);
    m_bool_configs[CONFIG_GM_LOWER_SECURITY] = sConfigMgr->GetBoolDefault("GM.LowerSecurity", false);
    m_int_configs[CONFIG_FORCE_SHUTDOWN_THRESHOLD] = sConfigMgr->GetIntDefault("GM.ForceShutdownThreshold", 30);

    m_int_configs[CONFIG_GROUP_VISIBILITY] = sConfigMgr->GetIntDefault("Visibility.GroupMode", 1);

    m_int_configs[CONFIG_MAIL_DELIVERY_DELAY] = sConfigMgr->GetIntDefault("MailDeliveryDelay", HOUR);
    m_int_configs[CONFIG_CLEAN_OLD_MAIL_TIME] = sConfigMgr->GetIntDefault("CleanOldMailTime", 4);
    if (m_int_configs[CONFIG_CLEAN_OLD_MAIL_TIME] > 23)
    {
        TC_LOG_ERROR("server.loading", "CleanOldMailTime ({}) must be an hour, between 0 and 23. Set to 4.", m_int_configs[CONFIG_CLEAN_OLD_MAIL_TIME]);
        m_int_configs[CONFIG_CLEAN_OLD_MAIL_TIME] = 4;
    }

    m_int_configs[CONFIG_UPTIME_UPDATE] = sConfigMgr->GetIntDefault("UpdateUptimeInterval", 10);
    if (int32(m_int_configs[CONFIG_UPTIME_UPDATE]) <= 0)
    {
        TC_LOG_ERROR("server.loading", "UpdateUptimeInterval ({}) must be > 0, set to default 10.", m_int_configs[CONFIG_UPTIME_UPDATE]);
        m_int_configs[CONFIG_UPTIME_UPDATE] = 10;
    }
    if (reload)
    {
        m_timers[WUPDATE_UPTIME].SetInterval(m_int_configs[CONFIG_UPTIME_UPDATE]*MINUTE*IN_MILLISECONDS);
        m_timers[WUPDATE_UPTIME].Reset();
    }

    // log db cleanup interval
    m_int_configs[CONFIG_LOGDB_CLEARINTERVAL] = sConfigMgr->GetIntDefault("LogDB.Opt.ClearInterval", 10);
    if (int32(m_int_configs[CONFIG_LOGDB_CLEARINTERVAL]) <= 0)
    {
        TC_LOG_ERROR("server.loading", "LogDB.Opt.ClearInterval ({}) must be > 0, set to default 10.", m_int_configs[CONFIG_LOGDB_CLEARINTERVAL]);
        m_int_configs[CONFIG_LOGDB_CLEARINTERVAL] = 10;
    }
    if (reload)
    {
        m_timers[WUPDATE_CLEANDB].SetInterval(m_int_configs[CONFIG_LOGDB_CLEARINTERVAL] * MINUTE * IN_MILLISECONDS);
        m_timers[WUPDATE_CLEANDB].Reset();
    }
    m_int_configs[CONFIG_LOGDB_CLEARTIME] = sConfigMgr->GetIntDefault("LogDB.Opt.ClearTime", 1209600); // 14 days default
    TC_LOG_INFO("server.loading", "Will clear `logs` table of entries older than {} seconds every {} minutes.",
        m_int_configs[CONFIG_LOGDB_CLEARTIME], m_int_configs[CONFIG_LOGDB_CLEARINTERVAL]);

    m_int_configs[CONFIG_SKILL_CHANCE_ORANGE] = sConfigMgr->GetIntDefault("SkillChance.Orange", 100);
    m_int_configs[CONFIG_SKILL_CHANCE_YELLOW] = sConfigMgr->GetIntDefault("SkillChance.Yellow", 75);
    m_int_configs[CONFIG_SKILL_CHANCE_GREEN]  = sConfigMgr->GetIntDefault("SkillChance.Green", 25);
    m_int_configs[CONFIG_SKILL_CHANCE_GREY]   = sConfigMgr->GetIntDefault("SkillChance.Grey", 0);

    m_int_configs[CONFIG_SKILL_CHANCE_MINING_STEPS]  = sConfigMgr->GetIntDefault("SkillChance.MiningSteps", 75);
    m_int_configs[CONFIG_SKILL_CHANCE_SKINNING_STEPS]   = sConfigMgr->GetIntDefault("SkillChance.SkinningSteps", 75);

    m_bool_configs[CONFIG_SKILL_PROSPECTING] = sConfigMgr->GetBoolDefault("SkillChance.Prospecting", false);
    m_bool_configs[CONFIG_SKILL_MILLING] = sConfigMgr->GetBoolDefault("SkillChance.Milling", false);

    m_int_configs[CONFIG_SKILL_GAIN_CRAFTING]  = sConfigMgr->GetIntDefault("SkillGain.Crafting", 1);

    m_int_configs[CONFIG_SKILL_GAIN_GATHERING]  = sConfigMgr->GetIntDefault("SkillGain.Gathering", 1);

    m_int_configs[CONFIG_MAX_OVERSPEED_PINGS] = sConfigMgr->GetIntDefault("MaxOverspeedPings", 2);

    if (m_int_configs[CONFIG_MAX_OVERSPEED_PINGS] != 0 && m_int_configs[CONFIG_MAX_OVERSPEED_PINGS] < 2)
    {
        TC_LOG_ERROR("server.loading", "MaxOverspeedPings ({}) must be in range 2..infinity (or 0 to disable check). Set to 2.", m_int_configs[CONFIG_MAX_OVERSPEED_PINGS]);
        m_int_configs[CONFIG_MAX_OVERSPEED_PINGS] = 2;
    }

    m_bool_configs[CONFIG_WEATHER] = sConfigMgr->GetBoolDefault("ActivateWeather", true);

    m_int_configs[CONFIG_DISABLE_BREATHING] = sConfigMgr->GetIntDefault("DisableWaterBreath", SEC_CONSOLE);

    if (reload)
    {
        uint32 val = sConfigMgr->GetIntDefault("Expansion", CURRENT_EXPANSION);
        if (val != m_int_configs[CONFIG_EXPANSION])
            TC_LOG_ERROR("server.loading", "Expansion option can't be changed at worldserver.conf reload, using current value ({}).", m_int_configs[CONFIG_EXPANSION]);
    }
    else
        m_int_configs[CONFIG_EXPANSION] = sConfigMgr->GetIntDefault("Expansion", CURRENT_EXPANSION);

    m_int_configs[CONFIG_CHATFLOOD_MESSAGE_COUNT] = sConfigMgr->GetIntDefault("ChatFlood.MessageCount", 10);
    m_int_configs[CONFIG_CHATFLOOD_MESSAGE_DELAY] = sConfigMgr->GetIntDefault("ChatFlood.MessageDelay", 1);
    m_int_configs[CONFIG_CHATFLOOD_ADDON_MESSAGE_COUNT] = sConfigMgr->GetIntDefault("ChatFlood.AddonMessageCount", 100);
    m_int_configs[CONFIG_CHATFLOOD_ADDON_MESSAGE_DELAY] = sConfigMgr->GetIntDefault("ChatFlood.AddonMessageDelay", 1);
    m_int_configs[CONFIG_CHATFLOOD_MUTE_TIME]     = sConfigMgr->GetIntDefault("ChatFlood.MuteTime", 10);

    m_bool_configs[CONFIG_EVENT_ANNOUNCE] = sConfigMgr->GetBoolDefault("Event.Announce", false);

    m_float_configs[CONFIG_CREATURE_FAMILY_FLEE_ASSISTANCE_RADIUS] = sConfigMgr->GetFloatDefault("CreatureFamilyFleeAssistanceRadius", 30.0f);
    m_float_configs[CONFIG_CREATURE_FAMILY_ASSISTANCE_RADIUS] = sConfigMgr->GetFloatDefault("CreatureFamilyAssistanceRadius", 10.0f);
    m_int_configs[CONFIG_CREATURE_FAMILY_ASSISTANCE_DELAY]  = sConfigMgr->GetIntDefault("CreatureFamilyAssistanceDelay", 1500);
    m_int_configs[CONFIG_CREATURE_FAMILY_FLEE_DELAY]        = sConfigMgr->GetIntDefault("CreatureFamilyFleeDelay", 7000);

    m_int_configs[CONFIG_WORLD_BOSS_LEVEL_DIFF] = sConfigMgr->GetIntDefault("WorldBossLevelDiff", 3);

    m_bool_configs[CONFIG_QUEST_ENABLE_QUEST_TRACKER] = sConfigMgr->GetBoolDefault("Quests.EnableQuestTracker", false);

    // note: disable value (-1) will assigned as 0xFFFFFFF, to prevent overflow at calculations limit it to max possible player level MAX_LEVEL(100)
    m_int_configs[CONFIG_QUEST_LOW_LEVEL_HIDE_DIFF] = sConfigMgr->GetIntDefault("Quests.LowLevelHideDiff", 4);
    if (m_int_configs[CONFIG_QUEST_LOW_LEVEL_HIDE_DIFF] > MAX_LEVEL)
        m_int_configs[CONFIG_QUEST_LOW_LEVEL_HIDE_DIFF] = MAX_LEVEL;
    m_int_configs[CONFIG_QUEST_HIGH_LEVEL_HIDE_DIFF] = sConfigMgr->GetIntDefault("Quests.HighLevelHideDiff", 7);
    if (m_int_configs[CONFIG_QUEST_HIGH_LEVEL_HIDE_DIFF] > MAX_LEVEL)
        m_int_configs[CONFIG_QUEST_HIGH_LEVEL_HIDE_DIFF] = MAX_LEVEL;
    m_bool_configs[CONFIG_QUEST_IGNORE_RAID] = sConfigMgr->GetBoolDefault("Quests.IgnoreRaid", false);
    m_bool_configs[CONFIG_QUEST_IGNORE_AUTO_ACCEPT] = sConfigMgr->GetBoolDefault("Quests.IgnoreAutoAccept", false);
    m_bool_configs[CONFIG_QUEST_IGNORE_AUTO_COMPLETE] = sConfigMgr->GetBoolDefault("Quests.IgnoreAutoComplete", false);

    m_int_configs[CONFIG_RANDOM_BG_RESET_HOUR] = sConfigMgr->GetIntDefault("Battleground.Random.ResetHour", 6);
    if (m_int_configs[CONFIG_RANDOM_BG_RESET_HOUR] > 23)
    {
        TC_LOG_ERROR("server.loading", "Battleground.Random.ResetHour ({}) can't be load. Set to 6.", m_int_configs[CONFIG_RANDOM_BG_RESET_HOUR]);
        m_int_configs[CONFIG_RANDOM_BG_RESET_HOUR] = 6;
    }

    m_int_configs[CONFIG_CALENDAR_DELETE_OLD_EVENTS_HOUR] = sConfigMgr->GetIntDefault("Calendar.DeleteOldEventsHour", 6);
    if (m_int_configs[CONFIG_CALENDAR_DELETE_OLD_EVENTS_HOUR] > 23)
    {
        TC_LOG_ERROR("misc", "Calendar.DeleteOldEventsHour ({}) can't be load. Set to 6.", m_int_configs[CONFIG_CALENDAR_DELETE_OLD_EVENTS_HOUR]);
        m_int_configs[CONFIG_CALENDAR_DELETE_OLD_EVENTS_HOUR] = 6;
    }

    m_int_configs[CONFIG_GUILD_RESET_HOUR] = sConfigMgr->GetIntDefault("Guild.ResetHour", 6);
    if (m_int_configs[CONFIG_GUILD_RESET_HOUR] > 23)
    {
        TC_LOG_ERROR("misc", "Guild.ResetHour ({}) can't be load. Set to 6.", m_int_configs[CONFIG_GUILD_RESET_HOUR]);
        m_int_configs[CONFIG_GUILD_RESET_HOUR] = 6;
    }

    m_bool_configs[CONFIG_DETECT_POS_COLLISION] = sConfigMgr->GetBoolDefault("DetectPosCollision", true);

    m_bool_configs[CONFIG_RESTRICTED_LFG_CHANNEL]      = sConfigMgr->GetBoolDefault("Channel.RestrictedLfg", true);
    m_int_configs[CONFIG_TALENTS_INSPECTING]           = sConfigMgr->GetIntDefault("TalentsInspecting", 1);
    m_bool_configs[CONFIG_CHAT_FAKE_MESSAGE_PREVENTING] = sConfigMgr->GetBoolDefault("ChatFakeMessagePreventing", false);
    m_int_configs[CONFIG_CHAT_STRICT_LINK_CHECKING_SEVERITY] = sConfigMgr->GetIntDefault("ChatStrictLinkChecking.Severity", 0);
    m_int_configs[CONFIG_CHAT_STRICT_LINK_CHECKING_KICK] = sConfigMgr->GetIntDefault("ChatStrictLinkChecking.Kick", 0);

    m_int_configs[CONFIG_CORPSE_DECAY_NORMAL]    = sConfigMgr->GetIntDefault("Corpse.Decay.NORMAL", 60);
    m_int_configs[CONFIG_CORPSE_DECAY_RARE]      = sConfigMgr->GetIntDefault("Corpse.Decay.RARE", 300);
    m_int_configs[CONFIG_CORPSE_DECAY_ELITE]     = sConfigMgr->GetIntDefault("Corpse.Decay.ELITE", 300);
    m_int_configs[CONFIG_CORPSE_DECAY_RAREELITE] = sConfigMgr->GetIntDefault("Corpse.Decay.RAREELITE", 300);
    m_int_configs[CONFIG_CORPSE_DECAY_WORLDBOSS] = sConfigMgr->GetIntDefault("Corpse.Decay.WORLDBOSS", 3600);

    m_int_configs[CONFIG_DEATH_SICKNESS_LEVEL]           = sConfigMgr->GetIntDefault ("Death.SicknessLevel", 11);
    m_bool_configs[CONFIG_DEATH_CORPSE_RECLAIM_DELAY_PVP] = sConfigMgr->GetBoolDefault("Death.CorpseReclaimDelay.PvP", true);
    m_bool_configs[CONFIG_DEATH_CORPSE_RECLAIM_DELAY_PVE] = sConfigMgr->GetBoolDefault("Death.CorpseReclaimDelay.PvE", true);
    m_bool_configs[CONFIG_DEATH_BONES_WORLD]              = sConfigMgr->GetBoolDefault("Death.Bones.World", true);
    m_bool_configs[CONFIG_DEATH_BONES_BG_OR_ARENA]        = sConfigMgr->GetBoolDefault("Death.Bones.BattlegroundOrArena", true);

    m_bool_configs[CONFIG_DIE_COMMAND_MODE] = sConfigMgr->GetBoolDefault("Die.Command.Mode", true);

    m_float_configs[CONFIG_THREAT_RADIUS] = sConfigMgr->GetFloatDefault("ThreatRadius", 60.0f);

    m_bool_configs[CONFIG_DECLINED_NAMES_USED] = sConfigMgr->GetBoolDefault("DeclinedNames", false);

    // always use declined names in the russian client
    if (Cfg_CategoriesEntry const* category = sCfgCategoriesStore.LookupEntry(m_int_configs[CONFIG_REALM_ZONE]))
        if (category->GetCreateCharsetMask().HasFlag(CfgCategoriesCharsets::Russian))
            m_bool_configs[CONFIG_DECLINED_NAMES_USED] = true;

    m_float_configs[CONFIG_LISTEN_RANGE_SAY]       = sConfigMgr->GetFloatDefault("ListenRange.Say", 25.0f);
    m_float_configs[CONFIG_LISTEN_RANGE_TEXTEMOTE] = sConfigMgr->GetFloatDefault("ListenRange.TextEmote", 25.0f);
    m_float_configs[CONFIG_LISTEN_RANGE_YELL]      = sConfigMgr->GetFloatDefault("ListenRange.Yell", 300.0f);

    m_bool_configs[CONFIG_BATTLEGROUND_CAST_DESERTER]                = sConfigMgr->GetBoolDefault("Battleground.CastDeserter", true);
    m_bool_configs[CONFIG_BATTLEGROUND_QUEUE_ANNOUNCER_ENABLE]       = sConfigMgr->GetBoolDefault("Battleground.QueueAnnouncer.Enable", false);
    m_bool_configs[CONFIG_BATTLEGROUND_QUEUE_ANNOUNCER_PLAYERONLY]   = sConfigMgr->GetBoolDefault("Battleground.QueueAnnouncer.PlayerOnly", false);
    m_bool_configs[CONFIG_BATTLEGROUND_STORE_STATISTICS_ENABLE]      = sConfigMgr->GetBoolDefault("Battleground.StoreStatistics.Enable", false);
    m_int_configs[CONFIG_BATTLEGROUND_REPORT_AFK]                    = sConfigMgr->GetIntDefault("Battleground.ReportAFK", 3);
    if (m_int_configs[CONFIG_BATTLEGROUND_REPORT_AFK] < 1)
    {
        TC_LOG_ERROR("server.loading", "Battleground.ReportAFK ({}) must be >0. Using 3 instead.", m_int_configs[CONFIG_BATTLEGROUND_REPORT_AFK]);
        m_int_configs[CONFIG_BATTLEGROUND_REPORT_AFK] = 3;
    }
    if (m_int_configs[CONFIG_BATTLEGROUND_REPORT_AFK] > 9)
    {
        TC_LOG_ERROR("server.loading", "Battleground.ReportAFK ({}) must be <10. Using 3 instead.", m_int_configs[CONFIG_BATTLEGROUND_REPORT_AFK]);
        m_int_configs[CONFIG_BATTLEGROUND_REPORT_AFK] = 3;
    }
    m_int_configs[CONFIG_BATTLEGROUND_INVITATION_TYPE]               = sConfigMgr->GetIntDefault ("Battleground.InvitationType", 0);
    m_int_configs[CONFIG_BATTLEGROUND_PREMATURE_FINISH_TIMER]        = sConfigMgr->GetIntDefault ("Battleground.PrematureFinishTimer", 5 * MINUTE * IN_MILLISECONDS);
    m_int_configs[CONFIG_BATTLEGROUND_PREMADE_GROUP_WAIT_FOR_MATCH]  = sConfigMgr->GetIntDefault ("Battleground.PremadeGroupWaitForMatch", 30 * MINUTE * IN_MILLISECONDS);
    m_bool_configs[CONFIG_BG_XP_FOR_KILL]                            = sConfigMgr->GetBoolDefault("Battleground.GiveXPForKills", false);
    m_int_configs[CONFIG_ARENA_MAX_RATING_DIFFERENCE]                = sConfigMgr->GetIntDefault ("Arena.MaxRatingDifference", 150);
    m_int_configs[CONFIG_ARENA_RATING_DISCARD_TIMER]                 = sConfigMgr->GetIntDefault ("Arena.RatingDiscardTimer", 10 * MINUTE * IN_MILLISECONDS);
    m_int_configs[CONFIG_ARENA_RATED_UPDATE_TIMER]                   = sConfigMgr->GetIntDefault ("Arena.RatedUpdateTimer", 5 * IN_MILLISECONDS);
    m_bool_configs[CONFIG_ARENA_QUEUE_ANNOUNCER_ENABLE]              = sConfigMgr->GetBoolDefault("Arena.QueueAnnouncer.Enable", false);
    m_int_configs[CONFIG_ARENA_SEASON_ID]                            = sConfigMgr->GetIntDefault ("Arena.ArenaSeason.ID", 32);
    m_int_configs[CONFIG_ARENA_START_RATING]                         = sConfigMgr->GetIntDefault ("Arena.ArenaStartRating", 0);
    m_int_configs[CONFIG_ARENA_START_PERSONAL_RATING]                = sConfigMgr->GetIntDefault ("Arena.ArenaStartPersonalRating", 1000);
    m_int_configs[CONFIG_ARENA_START_MATCHMAKER_RATING]              = sConfigMgr->GetIntDefault ("Arena.ArenaStartMatchmakerRating", 1500);
    m_bool_configs[CONFIG_ARENA_SEASON_IN_PROGRESS]                  = sConfigMgr->GetBoolDefault("Arena.ArenaSeason.InProgress", false);
    m_bool_configs[CONFIG_ARENA_LOG_EXTENDED_INFO]                   = sConfigMgr->GetBoolDefault("ArenaLog.ExtendedInfo", false);
    m_float_configs[CONFIG_ARENA_WIN_RATING_MODIFIER_1]              = sConfigMgr->GetFloatDefault("Arena.ArenaWinRatingModifier1", 48.0f);
    m_float_configs[CONFIG_ARENA_WIN_RATING_MODIFIER_2]              = sConfigMgr->GetFloatDefault("Arena.ArenaWinRatingModifier2", 24.0f);
    m_float_configs[CONFIG_ARENA_LOSE_RATING_MODIFIER]               = sConfigMgr->GetFloatDefault("Arena.ArenaLoseRatingModifier", 24.0f);
    m_float_configs[CONFIG_ARENA_MATCHMAKER_RATING_MODIFIER]         = sConfigMgr->GetFloatDefault("Arena.ArenaMatchmakerRatingModifier", 24.0f);

    if (reload)
    {
        sWorldStateMgr->SetValue(WS_CURRENT_PVP_SEASON_ID, getBoolConfig(CONFIG_ARENA_SEASON_IN_PROGRESS) ? getIntConfig(CONFIG_ARENA_SEASON_ID) : 0, false, nullptr);
        sWorldStateMgr->SetValue(WS_PREVIOUS_PVP_SEASON_ID, getIntConfig(CONFIG_ARENA_SEASON_ID) - getBoolConfig(CONFIG_ARENA_SEASON_IN_PROGRESS), false, nullptr);
    }

    m_bool_configs[CONFIG_OFFHAND_CHECK_AT_SPELL_UNLEARN]            = sConfigMgr->GetBoolDefault("OffhandCheckAtSpellUnlearn", true);

    m_int_configs[CONFIG_CREATURE_PICKPOCKET_REFILL] = sConfigMgr->GetIntDefault("Creature.PickPocketRefillDelay", 10 * MINUTE);
    m_int_configs[CONFIG_CREATURE_STOP_FOR_PLAYER] = sConfigMgr->GetIntDefault("Creature.MovingStopTimeForPlayer", 3 * MINUTE * IN_MILLISECONDS);

    if (int32 clientCacheId = sConfigMgr->GetIntDefault("ClientCacheVersion", 0))
    {
        // overwrite DB/old value
        if (clientCacheId > 0)
            m_int_configs[CONFIG_CLIENTCACHE_VERSION] = clientCacheId;
        else
            TC_LOG_ERROR("server.loading", "ClientCacheVersion can't be negative {}, ignored.", clientCacheId);
    }
    TC_LOG_INFO("server.loading", "Client cache version set to: {}", m_int_configs[CONFIG_CLIENTCACHE_VERSION]);

    m_int_configs[CONFIG_GUILD_NEWS_LOG_COUNT] = sConfigMgr->GetIntDefault("Guild.NewsLogRecordsCount", GUILD_NEWSLOG_MAX_RECORDS);
    if (m_int_configs[CONFIG_GUILD_NEWS_LOG_COUNT] > GUILD_NEWSLOG_MAX_RECORDS)
        m_int_configs[CONFIG_GUILD_NEWS_LOG_COUNT] = GUILD_NEWSLOG_MAX_RECORDS;
    m_int_configs[CONFIG_GUILD_EVENT_LOG_COUNT] = sConfigMgr->GetIntDefault("Guild.EventLogRecordsCount", GUILD_EVENTLOG_MAX_RECORDS);
    if (m_int_configs[CONFIG_GUILD_EVENT_LOG_COUNT] > GUILD_EVENTLOG_MAX_RECORDS)
        m_int_configs[CONFIG_GUILD_EVENT_LOG_COUNT] = GUILD_EVENTLOG_MAX_RECORDS;
    m_int_configs[CONFIG_GUILD_BANK_EVENT_LOG_COUNT] = sConfigMgr->GetIntDefault("Guild.BankEventLogRecordsCount", GUILD_BANKLOG_MAX_RECORDS);
    if (m_int_configs[CONFIG_GUILD_BANK_EVENT_LOG_COUNT] > GUILD_BANKLOG_MAX_RECORDS)
        m_int_configs[CONFIG_GUILD_BANK_EVENT_LOG_COUNT] = GUILD_BANKLOG_MAX_RECORDS;

    // visibility on continents
    m_MaxVisibleDistanceOnContinents = sConfigMgr->GetFloatDefault("Visibility.Distance.Continents", DEFAULT_VISIBILITY_DISTANCE);
    if (m_MaxVisibleDistanceOnContinents < 45*getRate(RATE_CREATURE_AGGRO))
    {
        TC_LOG_ERROR("server.loading", "Visibility.Distance.Continents can't be less max aggro radius {}", 45*getRate(RATE_CREATURE_AGGRO));
        m_MaxVisibleDistanceOnContinents = 45*getRate(RATE_CREATURE_AGGRO);
    }
    else if (m_MaxVisibleDistanceOnContinents > MAX_VISIBILITY_DISTANCE)
    {
        TC_LOG_ERROR("server.loading", "Visibility.Distance.Continents can't be greater {}", MAX_VISIBILITY_DISTANCE);
        m_MaxVisibleDistanceOnContinents = MAX_VISIBILITY_DISTANCE;
    }

    // visibility in instances
    m_MaxVisibleDistanceInInstances = sConfigMgr->GetFloatDefault("Visibility.Distance.Instances", DEFAULT_VISIBILITY_INSTANCE);
    if (m_MaxVisibleDistanceInInstances < 45*getRate(RATE_CREATURE_AGGRO))
    {
        TC_LOG_ERROR("server.loading", "Visibility.Distance.Instances can't be less max aggro radius {}", 45*getRate(RATE_CREATURE_AGGRO));
        m_MaxVisibleDistanceInInstances = 45*getRate(RATE_CREATURE_AGGRO);
    }
    else if (m_MaxVisibleDistanceInInstances > MAX_VISIBILITY_DISTANCE)
    {
        TC_LOG_ERROR("server.loading", "Visibility.Distance.Instances can't be greater {}", MAX_VISIBILITY_DISTANCE);
        m_MaxVisibleDistanceInInstances = MAX_VISIBILITY_DISTANCE;
    }

    // visibility in BG
    m_MaxVisibleDistanceInBG = sConfigMgr->GetFloatDefault("Visibility.Distance.BG", DEFAULT_VISIBILITY_BGARENAS);
    if (m_MaxVisibleDistanceInBG < 45*getRate(RATE_CREATURE_AGGRO))
    {
        TC_LOG_ERROR("server.loading", "Visibility.Distance.BG can't be less max aggro radius {}", 45*getRate(RATE_CREATURE_AGGRO));
        m_MaxVisibleDistanceInBG = 45*getRate(RATE_CREATURE_AGGRO);
    }
    else if (m_MaxVisibleDistanceInBG > MAX_VISIBILITY_DISTANCE)
    {
        TC_LOG_ERROR("server.loading", "Visibility.Distance.BG can't be greater {}", MAX_VISIBILITY_DISTANCE);
        m_MaxVisibleDistanceInBG = MAX_VISIBILITY_DISTANCE;
    }

    // Visibility in Arenas
    m_MaxVisibleDistanceInArenas = sConfigMgr->GetFloatDefault("Visibility.Distance.Arenas", DEFAULT_VISIBILITY_BGARENAS);
    if (m_MaxVisibleDistanceInArenas < 45*getRate(RATE_CREATURE_AGGRO))
    {
        TC_LOG_ERROR("server.loading", "Visibility.Distance.Arenas can't be less max aggro radius {}", 45*getRate(RATE_CREATURE_AGGRO));
        m_MaxVisibleDistanceInArenas = 45*getRate(RATE_CREATURE_AGGRO);
    }
    else if (m_MaxVisibleDistanceInArenas > MAX_VISIBILITY_DISTANCE)
    {
        TC_LOG_ERROR("server.loading", "Visibility.Distance.Arenas can't be greater {}", MAX_VISIBILITY_DISTANCE);
        m_MaxVisibleDistanceInArenas = MAX_VISIBILITY_DISTANCE;
    }

    m_visibility_notify_periodOnContinents = sConfigMgr->GetIntDefault("Visibility.Notify.Period.OnContinents", DEFAULT_VISIBILITY_NOTIFY_PERIOD);
    m_visibility_notify_periodInInstances  = sConfigMgr->GetIntDefault("Visibility.Notify.Period.InInstances",  DEFAULT_VISIBILITY_NOTIFY_PERIOD);
    m_visibility_notify_periodInBG         = sConfigMgr->GetIntDefault("Visibility.Notify.Period.InBG",         DEFAULT_VISIBILITY_NOTIFY_PERIOD);
    m_visibility_notify_periodInArenas     = sConfigMgr->GetIntDefault("Visibility.Notify.Period.InArenas",     DEFAULT_VISIBILITY_NOTIFY_PERIOD);

    ///- Load the CharDelete related config options
    m_int_configs[CONFIG_CHARDELETE_METHOD] = sConfigMgr->GetIntDefault("CharDelete.Method", 0);
    m_int_configs[CONFIG_CHARDELETE_MIN_LEVEL] = sConfigMgr->GetIntDefault("CharDelete.MinLevel", 0);
    m_int_configs[CONFIG_CHARDELETE_DEATH_KNIGHT_MIN_LEVEL] = sConfigMgr->GetIntDefault("CharDelete.DeathKnight.MinLevel", 0);
    m_int_configs[CONFIG_CHARDELETE_DEMON_HUNTER_MIN_LEVEL] = sConfigMgr->GetIntDefault("CharDelete.DemonHunter.MinLevel", 0);
    m_int_configs[CONFIG_CHARDELETE_KEEP_DAYS] = sConfigMgr->GetIntDefault("CharDelete.KeepDays", 30);

    // No aggro from gray mobs
    m_int_configs[CONFIG_NO_GRAY_AGGRO_ABOVE] = sConfigMgr->GetIntDefault("NoGrayAggro.Above", 0);
    m_int_configs[CONFIG_NO_GRAY_AGGRO_BELOW] = sConfigMgr->GetIntDefault("NoGrayAggro.Below", 0);
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
    m_int_configs[CONFIG_RESPAWN_MINCHECKINTERVALMS] = sConfigMgr->GetIntDefault("Respawn.MinCheckIntervalMS", 5000);
    m_int_configs[CONFIG_RESPAWN_DYNAMICMODE] = sConfigMgr->GetIntDefault("Respawn.DynamicMode", 0);
    if (m_int_configs[CONFIG_RESPAWN_DYNAMICMODE] > 1)
    {
        TC_LOG_ERROR("server.loading", "Invalid value for Respawn.DynamicMode ({}). Set to 0.", m_int_configs[CONFIG_RESPAWN_DYNAMICMODE]);
        m_int_configs[CONFIG_RESPAWN_DYNAMICMODE] = 0;
    }
    m_bool_configs[CONFIG_RESPAWN_DYNAMIC_ESCORTNPC] = sConfigMgr->GetBoolDefault("Respawn.DynamicEscortNPC", false);
    m_int_configs[CONFIG_RESPAWN_GUIDWARNLEVEL] = sConfigMgr->GetIntDefault("Respawn.GuidWarnLevel", 12000000);
    if (m_int_configs[CONFIG_RESPAWN_GUIDWARNLEVEL] > 16777215)
    {
        TC_LOG_ERROR("server.loading", "Respawn.GuidWarnLevel ({}) cannot be greater than maximum GUID (16777215). Set to 12000000.", m_int_configs[CONFIG_RESPAWN_GUIDWARNLEVEL]);
        m_int_configs[CONFIG_RESPAWN_GUIDWARNLEVEL] = 12000000;
    }
    m_int_configs[CONFIG_RESPAWN_GUIDALERTLEVEL] = sConfigMgr->GetIntDefault("Respawn.GuidAlertLevel", 16000000);
    if (m_int_configs[CONFIG_RESPAWN_GUIDALERTLEVEL] > 16777215)
    {
        TC_LOG_ERROR("server.loading", "Respawn.GuidWarnLevel ({}) cannot be greater than maximum GUID (16777215). Set to 16000000.", m_int_configs[CONFIG_RESPAWN_GUIDALERTLEVEL]);
        m_int_configs[CONFIG_RESPAWN_GUIDALERTLEVEL] = 16000000;
    }
    m_int_configs[CONFIG_RESPAWN_RESTARTQUIETTIME] = sConfigMgr->GetIntDefault("Respawn.RestartQuietTime", 3);
    if (m_int_configs[CONFIG_RESPAWN_RESTARTQUIETTIME] > 23)
    {
        TC_LOG_ERROR("server.loading", "Respawn.RestartQuietTime ({}) must be an hour, between 0 and 23. Set to 3.", m_int_configs[CONFIG_RESPAWN_RESTARTQUIETTIME]);
        m_int_configs[CONFIG_RESPAWN_RESTARTQUIETTIME] = 3;
    }
    m_float_configs[CONFIG_RESPAWN_DYNAMICRATE_CREATURE] = sConfigMgr->GetFloatDefault("Respawn.DynamicRateCreature", 10.0f);
    if (m_float_configs[CONFIG_RESPAWN_DYNAMICRATE_CREATURE] < 0.0f)
    {
        TC_LOG_ERROR("server.loading", "Respawn.DynamicRateCreature ({}) must be positive. Set to 10.", m_float_configs[CONFIG_RESPAWN_DYNAMICRATE_CREATURE]);
        m_float_configs[CONFIG_RESPAWN_DYNAMICRATE_CREATURE] = 10.0f;
    }
    m_int_configs[CONFIG_RESPAWN_DYNAMICMINIMUM_CREATURE] = sConfigMgr->GetIntDefault("Respawn.DynamicMinimumCreature", 10);
    m_float_configs[CONFIG_RESPAWN_DYNAMICRATE_GAMEOBJECT] = sConfigMgr->GetFloatDefault("Respawn.DynamicRateGameObject", 10.0f);
    if (m_float_configs[CONFIG_RESPAWN_DYNAMICRATE_GAMEOBJECT] < 0.0f)
    {
        TC_LOG_ERROR("server.loading", "Respawn.DynamicRateGameObject ({}) must be positive. Set to 10.", m_float_configs[CONFIG_RESPAWN_DYNAMICRATE_GAMEOBJECT]);
        m_float_configs[CONFIG_RESPAWN_DYNAMICRATE_GAMEOBJECT] = 10.0f;
    }
    m_int_configs[CONFIG_RESPAWN_DYNAMICMINIMUM_GAMEOBJECT] = sConfigMgr->GetIntDefault("Respawn.DynamicMinimumGameObject", 10);
    _guidWarningMsg = sConfigMgr->GetStringDefault("Respawn.WarningMessage", "There will be an unscheduled server restart at 03:00. The server will be available again shortly after.");
    _alertRestartReason = sConfigMgr->GetStringDefault("Respawn.AlertRestartReason", "Urgent Maintenance");
    m_int_configs[CONFIG_RESPAWN_GUIDWARNING_FREQUENCY] = sConfigMgr->GetIntDefault("Respawn.WarningFrequency", 1800);
    ///- Read the "Data" directory from the config file
    std::string dataPath = sConfigMgr->GetStringDefault("DataDir", "./");
    if (dataPath.empty() || (dataPath.at(dataPath.length()-1) != '/' && dataPath.at(dataPath.length()-1) != '\\'))
        dataPath.push_back('/');

#if TRINITY_PLATFORM == TRINITY_PLATFORM_UNIX || TRINITY_PLATFORM == TRINITY_PLATFORM_APPLE
    if (dataPath[0] == '~')
    {
        char const* home = getenv("HOME");
        if (home)
            dataPath.replace(0, 1, home);
    }
#endif

    if (reload)
    {
        if (dataPath != m_dataPath)
            TC_LOG_ERROR("server.loading", "DataDir option can't be changed at worldserver.conf reload, using current value ({}).", m_dataPath);
    }
    else
    {
        m_dataPath = dataPath;
        TC_LOG_INFO("server.loading", "Using DataDir {}", m_dataPath);
    }

    m_bool_configs[CONFIG_ENABLE_MMAPS] = sConfigMgr->GetBoolDefault("mmap.enablePathFinding", true);
    TC_LOG_INFO("server.loading", "WORLD: MMap data directory is: {}mmaps", m_dataPath);

    m_bool_configs[CONFIG_VMAP_INDOOR_CHECK] = sConfigMgr->GetBoolDefault("vmap.enableIndoorCheck", false);
    bool enableIndoor = sConfigMgr->GetBoolDefault("vmap.enableIndoorCheck", true);
    bool enableLOS = sConfigMgr->GetBoolDefault("vmap.enableLOS", true);
    bool enableHeight = sConfigMgr->GetBoolDefault("vmap.enableHeight", true);

    if (!enableHeight)
        TC_LOG_ERROR("server.loading", "VMap height checking disabled! Creatures movements and other various things WILL be broken! Expect no support.");

    VMAP::VMapFactory::createOrGetVMapManager()->setEnableLineOfSightCalc(enableLOS);
    VMAP::VMapFactory::createOrGetVMapManager()->setEnableHeightCalc(enableHeight);
    TC_LOG_INFO("server.loading", "VMap support included. LineOfSight: {}, getHeight: {}, indoorCheck: {}", enableLOS, enableHeight, enableIndoor);
    TC_LOG_INFO("server.loading", "VMap data directory is: {}vmaps", m_dataPath);

    m_int_configs[CONFIG_MAX_WHO] = sConfigMgr->GetIntDefault("MaxWhoListReturns", 49);
    m_bool_configs[CONFIG_START_ALL_SPELLS] = sConfigMgr->GetBoolDefault("PlayerStart.AllSpells", false);
    if (m_bool_configs[CONFIG_START_ALL_SPELLS])
        TC_LOG_WARN("server.loading", "PlayerStart.AllSpells enabled - may not function as intended!");
    m_int_configs[CONFIG_HONOR_AFTER_DUEL] = sConfigMgr->GetIntDefault("HonorPointsAfterDuel", 0);
    m_bool_configs[CONFIG_RESET_DUEL_COOLDOWNS] = sConfigMgr->GetBoolDefault("ResetDuelCooldowns", false);
    m_bool_configs[CONFIG_RESET_DUEL_HEALTH_MANA] = sConfigMgr->GetBoolDefault("ResetDuelHealthMana", false);
    m_bool_configs[CONFIG_START_ALL_EXPLORED] = sConfigMgr->GetBoolDefault("PlayerStart.MapsExplored", false);
    m_bool_configs[CONFIG_START_ALL_REP] = sConfigMgr->GetBoolDefault("PlayerStart.AllReputation", false);
    m_bool_configs[CONFIG_PVP_TOKEN_ENABLE] = sConfigMgr->GetBoolDefault("PvPToken.Enable", false);
    m_int_configs[CONFIG_PVP_TOKEN_MAP_TYPE] = sConfigMgr->GetIntDefault("PvPToken.MapAllowType", 4);
    m_int_configs[CONFIG_PVP_TOKEN_ID] = sConfigMgr->GetIntDefault("PvPToken.ItemID", 29434);
    m_int_configs[CONFIG_PVP_TOKEN_COUNT] = sConfigMgr->GetIntDefault("PvPToken.ItemCount", 1);
    if (m_int_configs[CONFIG_PVP_TOKEN_COUNT] < 1)
        m_int_configs[CONFIG_PVP_TOKEN_COUNT] = 1;

    m_bool_configs[CONFIG_NO_RESET_TALENT_COST] = sConfigMgr->GetBoolDefault("NoResetTalentsCost", false);
    m_bool_configs[CONFIG_SHOW_KICK_IN_WORLD] = sConfigMgr->GetBoolDefault("ShowKickInWorld", false);
    m_bool_configs[CONFIG_SHOW_MUTE_IN_WORLD] = sConfigMgr->GetBoolDefault("ShowMuteInWorld", false);
    m_bool_configs[CONFIG_SHOW_BAN_IN_WORLD] = sConfigMgr->GetBoolDefault("ShowBanInWorld", false);
    m_int_configs[CONFIG_NUMTHREADS] = sConfigMgr->GetIntDefault("MapUpdate.Threads", 1);
    m_int_configs[CONFIG_MAX_RESULTS_LOOKUP_COMMANDS] = sConfigMgr->GetIntDefault("Command.LookupMaxResults", 0);

    // Warden
    m_bool_configs[CONFIG_WARDEN_ENABLED]              = sConfigMgr->GetBoolDefault("Warden.Enabled", false);
    m_int_configs[CONFIG_WARDEN_NUM_INJECT_CHECKS]     = sConfigMgr->GetIntDefault("Warden.NumInjectionChecks", 9);
    m_int_configs[CONFIG_WARDEN_NUM_LUA_CHECKS]        = sConfigMgr->GetIntDefault("Warden.NumLuaSandboxChecks", 1);
    m_int_configs[CONFIG_WARDEN_NUM_CLIENT_MOD_CHECKS] = sConfigMgr->GetIntDefault("Warden.NumClientModChecks", 1);
    m_int_configs[CONFIG_WARDEN_CLIENT_BAN_DURATION]   = sConfigMgr->GetIntDefault("Warden.BanDuration", 86400);
    m_int_configs[CONFIG_WARDEN_CLIENT_CHECK_HOLDOFF]  = sConfigMgr->GetIntDefault("Warden.ClientCheckHoldOff", 30);
    m_int_configs[CONFIG_WARDEN_CLIENT_FAIL_ACTION]    = sConfigMgr->GetIntDefault("Warden.ClientCheckFailAction", 0);
    m_int_configs[CONFIG_WARDEN_CLIENT_RESPONSE_DELAY] = sConfigMgr->GetIntDefault("Warden.ClientResponseDelay", 600);

    // Feature System
    m_bool_configs[CONFIG_FEATURE_SYSTEM_BPAY_STORE_ENABLED]         = sConfigMgr->GetBoolDefault("FeatureSystem.BpayStore.Enabled", false);
    m_bool_configs[CONFIG_FEATURE_SYSTEM_CHARACTER_UNDELETE_ENABLED] = sConfigMgr->GetBoolDefault("FeatureSystem.CharacterUndelete.Enabled", false);
    m_int_configs[CONFIG_FEATURE_SYSTEM_CHARACTER_UNDELETE_COOLDOWN] = sConfigMgr->GetIntDefault("FeatureSystem.CharacterUndelete.Cooldown", 2592000);

    // Dungeon finder
    m_int_configs[CONFIG_LFG_OPTIONSMASK] = sConfigMgr->GetIntDefault("DungeonFinder.OptionsMask", 1);

    // DBC_ItemAttributes
    m_bool_configs[CONFIG_DBC_ENFORCE_ITEM_ATTRIBUTES] = sConfigMgr->GetBoolDefault("DBC.EnforceItemAttributes", true);

    // Accountpassword Secruity
    m_int_configs[CONFIG_ACC_PASSCHANGESEC] = sConfigMgr->GetIntDefault("Account.PasswordChangeSecurity", 0);

    // Random Battleground Rewards
    m_int_configs[CONFIG_BG_REWARD_WINNER_HONOR_FIRST] = sConfigMgr->GetIntDefault("Battleground.RewardWinnerHonorFirst", 27000);
    m_int_configs[CONFIG_BG_REWARD_WINNER_CONQUEST_FIRST] = sConfigMgr->GetIntDefault("Battleground.RewardWinnerConquestFirst", 10000);
    m_int_configs[CONFIG_BG_REWARD_WINNER_HONOR_LAST]  = sConfigMgr->GetIntDefault("Battleground.RewardWinnerHonorLast", 13500);
    m_int_configs[CONFIG_BG_REWARD_WINNER_CONQUEST_LAST]  = sConfigMgr->GetIntDefault("Battleground.RewardWinnerConquestLast", 5000);
    m_int_configs[CONFIG_BG_REWARD_LOSER_HONOR_FIRST]  = sConfigMgr->GetIntDefault("Battleground.RewardLoserHonorFirst", 4500);
    m_int_configs[CONFIG_BG_REWARD_LOSER_HONOR_LAST]   = sConfigMgr->GetIntDefault("Battleground.RewardLoserHonorLast", 3500);

    // Max instances per hour
    m_int_configs[CONFIG_MAX_INSTANCES_PER_HOUR] = sConfigMgr->GetIntDefault("AccountInstancesPerHour", 5);

    // Anounce reset of instance to whole party
    m_bool_configs[CONFIG_INSTANCES_RESET_ANNOUNCE] = sConfigMgr->GetBoolDefault("InstancesResetAnnounce", false);

    // AutoBroadcast
    m_bool_configs[CONFIG_AUTOBROADCAST] = sConfigMgr->GetBoolDefault("AutoBroadcast.On", false);
    m_int_configs[CONFIG_AUTOBROADCAST_CENTER] = sConfigMgr->GetIntDefault("AutoBroadcast.Center", 0);
    m_int_configs[CONFIG_AUTOBROADCAST_INTERVAL] = sConfigMgr->GetIntDefault("AutoBroadcast.Timer", 60000);
    if (reload)
    {
        m_timers[WUPDATE_AUTOBROADCAST].SetInterval(m_int_configs[CONFIG_AUTOBROADCAST_INTERVAL]);
        m_timers[WUPDATE_AUTOBROADCAST].Reset();
    }

    // MySQL ping time interval
    m_int_configs[CONFIG_DB_PING_INTERVAL] = sConfigMgr->GetIntDefault("MaxPingTime", 30);

    // Guild save interval
    m_int_configs[CONFIG_GUILD_SAVE_INTERVAL] = sConfigMgr->GetIntDefault("Guild.SaveInterval", 15);

    // misc
    m_bool_configs[CONFIG_PDUMP_NO_PATHS] = sConfigMgr->GetBoolDefault("PlayerDump.DisallowPaths", true);
    m_bool_configs[CONFIG_PDUMP_NO_OVERWRITE] = sConfigMgr->GetBoolDefault("PlayerDump.DisallowOverwrite", true);

    // Wintergrasp battlefield
    m_bool_configs[CONFIG_WINTERGRASP_ENABLE] = sConfigMgr->GetBoolDefault("Wintergrasp.Enable", false);
    m_int_configs[CONFIG_WINTERGRASP_PLR_MAX] = sConfigMgr->GetIntDefault("Wintergrasp.PlayerMax", 100);
    m_int_configs[CONFIG_WINTERGRASP_PLR_MIN] = sConfigMgr->GetIntDefault("Wintergrasp.PlayerMin", 0);
    m_int_configs[CONFIG_WINTERGRASP_PLR_MIN_LVL] = sConfigMgr->GetIntDefault("Wintergrasp.PlayerMinLvl", 77);
    m_int_configs[CONFIG_WINTERGRASP_BATTLETIME] = sConfigMgr->GetIntDefault("Wintergrasp.BattleTimer", 30);
    m_int_configs[CONFIG_WINTERGRASP_NOBATTLETIME] = sConfigMgr->GetIntDefault("Wintergrasp.NoBattleTimer", 150);
    m_int_configs[CONFIG_WINTERGRASP_RESTART_AFTER_CRASH] = sConfigMgr->GetIntDefault("Wintergrasp.CrashRestartTimer", 10);

    // Tol Barad battlefield
    m_bool_configs[CONFIG_TOLBARAD_ENABLE] = sConfigMgr->GetBoolDefault("TolBarad.Enable", true);
    m_int_configs[CONFIG_TOLBARAD_PLR_MAX] = sConfigMgr->GetIntDefault("TolBarad.PlayerMax", 100);
    m_int_configs[CONFIG_TOLBARAD_PLR_MIN] = sConfigMgr->GetIntDefault("TolBarad.PlayerMin", 0);
    m_int_configs[CONFIG_TOLBARAD_PLR_MIN_LVL] = sConfigMgr->GetIntDefault("TolBarad.PlayerMinLvl", 85);
    m_int_configs[CONFIG_TOLBARAD_BATTLETIME] = sConfigMgr->GetIntDefault("TolBarad.BattleTimer", 15);
    m_int_configs[CONFIG_TOLBARAD_BONUSTIME] = sConfigMgr->GetIntDefault("TolBarad.BonusTime", 5);
    m_int_configs[CONFIG_TOLBARAD_NOBATTLETIME] = sConfigMgr->GetIntDefault("TolBarad.NoBattleTimer", 150);
    m_int_configs[CONFIG_TOLBARAD_RESTART_AFTER_CRASH] = sConfigMgr->GetIntDefault("TolBarad.CrashRestartTimer", 10);

    // Stats limits
    m_bool_configs[CONFIG_STATS_LIMITS_ENABLE] = sConfigMgr->GetBoolDefault("Stats.Limits.Enable", false);
    m_float_configs[CONFIG_STATS_LIMITS_DODGE] = sConfigMgr->GetFloatDefault("Stats.Limits.Dodge", 95.0f);
    m_float_configs[CONFIG_STATS_LIMITS_PARRY] = sConfigMgr->GetFloatDefault("Stats.Limits.Parry", 95.0f);
    m_float_configs[CONFIG_STATS_LIMITS_BLOCK] = sConfigMgr->GetFloatDefault("Stats.Limits.Block", 95.0f);
    m_float_configs[CONFIG_STATS_LIMITS_CRIT] = sConfigMgr->GetFloatDefault("Stats.Limits.Crit", 95.0f);

    //packet spoof punishment
    m_int_configs[CONFIG_PACKET_SPOOF_POLICY] = sConfigMgr->GetIntDefault("PacketSpoof.Policy", (uint32)WorldSession::DosProtection::POLICY_KICK);
    m_int_configs[CONFIG_PACKET_SPOOF_BANMODE] = sConfigMgr->GetIntDefault("PacketSpoof.BanMode", (uint32)BAN_ACCOUNT);
    if (m_int_configs[CONFIG_PACKET_SPOOF_BANMODE] == BAN_CHARACTER || m_int_configs[CONFIG_PACKET_SPOOF_BANMODE] > BAN_IP)
        m_int_configs[CONFIG_PACKET_SPOOF_BANMODE] = BAN_ACCOUNT;

    m_int_configs[CONFIG_PACKET_SPOOF_BANDURATION] = sConfigMgr->GetIntDefault("PacketSpoof.BanDuration", 86400);

    m_bool_configs[CONFIG_IP_BASED_ACTION_LOGGING] = sConfigMgr->GetBoolDefault("Allow.IP.Based.Action.Logging", false);

    // AHBot
    m_int_configs[CONFIG_AHBOT_UPDATE_INTERVAL] = sConfigMgr->GetIntDefault("AuctionHouseBot.Update.Interval", 20);

    m_bool_configs[CONFIG_CALCULATE_CREATURE_ZONE_AREA_DATA] = sConfigMgr->GetBoolDefault("Calculate.Creature.Zone.Area.Data", false);
    m_bool_configs[CONFIG_CALCULATE_GAMEOBJECT_ZONE_AREA_DATA] = sConfigMgr->GetBoolDefault("Calculate.Gameoject.Zone.Area.Data", false);

    // Black Market
    m_bool_configs[CONFIG_BLACKMARKET_ENABLED] = sConfigMgr->GetBoolDefault("BlackMarket.Enabled", true);

    m_int_configs[CONFIG_BLACKMARKET_MAXAUCTIONS] = sConfigMgr->GetIntDefault("BlackMarket.MaxAuctions", 12);
    m_int_configs[CONFIG_BLACKMARKET_UPDATE_PERIOD] = sConfigMgr->GetIntDefault("BlackMarket.UpdatePeriod", 24);

    // HotSwap
    m_bool_configs[CONFIG_HOTSWAP_ENABLED] = sConfigMgr->GetBoolDefault("HotSwap.Enabled", true);
    m_bool_configs[CONFIG_HOTSWAP_RECOMPILER_ENABLED] = sConfigMgr->GetBoolDefault("HotSwap.EnableReCompiler", true);
    m_bool_configs[CONFIG_HOTSWAP_EARLY_TERMINATION_ENABLED] = sConfigMgr->GetBoolDefault("HotSwap.EnableEarlyTermination", true);
    m_bool_configs[CONFIG_HOTSWAP_BUILD_FILE_RECREATION_ENABLED] = sConfigMgr->GetBoolDefault("HotSwap.EnableBuildFileRecreation", true);
    m_bool_configs[CONFIG_HOTSWAP_INSTALL_ENABLED] = sConfigMgr->GetBoolDefault("HotSwap.EnableInstall", true);
    m_bool_configs[CONFIG_HOTSWAP_PREFIX_CORRECTION_ENABLED] = sConfigMgr->GetBoolDefault("HotSwap.EnablePrefixCorrection", true);

    // prevent character rename on character customization
    m_bool_configs[CONFIG_PREVENT_RENAME_CUSTOMIZATION] = sConfigMgr->GetBoolDefault("PreventRenameCharacterOnCustomization", false);

    // Allow 5-man parties to use raid warnings
    m_bool_configs[CONFIG_CHAT_PARTY_RAID_WARNINGS] = sConfigMgr->GetBoolDefault("PartyRaidWarnings", false);

    // Allow to cache data queries
    m_bool_configs[CONFIG_CACHE_DATA_QUERIES] = sConfigMgr->GetBoolDefault("CacheDataQueries", true);

    // Check Invalid Position
    m_bool_configs[CONFIG_CREATURE_CHECK_INVALID_POSITION] = sConfigMgr->GetBoolDefault("Creature.CheckInvalidPosition", false);
    m_bool_configs[CONFIG_GAME_OBJECT_CHECK_INVALID_POSITION] = sConfigMgr->GetBoolDefault("GameObject.CheckInvalidPosition", false);

    // Whether to use LoS from game objects
    m_bool_configs[CONFIG_CHECK_GOBJECT_LOS] = sConfigMgr->GetBoolDefault("CheckGameObjectLoS", true);

    // FactionBalance
    m_int_configs[CONFIG_FACTION_BALANCE_LEVEL_CHECK_DIFF] = sConfigMgr->GetIntDefault("Pvp.FactionBalance.LevelCheckDiff", 0);
    m_float_configs[CONFIG_CALL_TO_ARMS_5_PCT] = sConfigMgr->GetFloatDefault("Pvp.FactionBalance.Pct5", 0.6f);
    m_float_configs[CONFIG_CALL_TO_ARMS_10_PCT] = sConfigMgr->GetFloatDefault("Pvp.FactionBalance.Pct10", 0.7f);
    m_float_configs[CONFIG_CALL_TO_ARMS_20_PCT] = sConfigMgr->GetFloatDefault("Pvp.FactionBalance.Pct20", 0.8f);

    // Specifies if IP addresses can be logged to the database
    m_bool_configs[CONFIG_ALLOW_LOGGING_IP_ADDRESSES_IN_DATABASE] = sConfigMgr->GetBoolDefault("AllowLoggingIPAddressesInDatabase", true, true);

    // call ScriptMgr if we're reloading the configuration
    if (reload)
        sScriptMgr->OnConfigLoad(reload);
}

/// Initialize the World
void World::SetInitialWorldSettings()
{
    sLog->SetRealmId(realm.Id.Realm);

    ///- Server startup begin
    uint32 startupBegin = getMSTime();

    ///- Initialize the random number generator
    srand((unsigned int)GameTime::GetGameTime());

    ///- Initialize detour memory management
    dtAllocSetCustom(dtCustomAlloc, dtCustomFree);

    ///- Initialize VMapManager function pointers (to untangle game/collision circular deps)
    VMAP::VMapManager2* vmmgr2 = VMAP::VMapFactory::createOrGetVMapManager();
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
        exit(1);
    }

    ///- Initialize pool manager
    sPoolMgr->Initialize();

    ///- Initialize game event manager
    sGameEventMgr->Initialize();

    ///- Loading strings. Getting no records means core load has to be canceled because no error message can be output.

    TC_LOG_INFO("server.loading", "Loading Trinity strings...");
    if (!sObjectMgr->LoadTrinityStrings())
        exit(1);                                            // Error message displayed in function already

    ///- Update the realm entry in the database with the realm type from the config file
    //No SQL injection as values are treated as integers

    // not send custom type REALM_FFA_PVP to realm list
    uint32 server_type = IsFFAPvPRealm() ? uint32(REALM_TYPE_PVP) : getIntConfig(CONFIG_GAME_TYPE);
    uint32 realm_zone = getIntConfig(CONFIG_REALM_ZONE);

    LoginDatabase.PExecute("UPDATE realmlist SET icon = {}, timezone = {} WHERE id = '{}'", server_type, realm_zone, realm.Id.Realm);      // One-time query

    TC_LOG_INFO("server.loading", "Initialize data stores...");
    ///- Load DB2s
    m_availableDbcLocaleMask = sDB2Manager.LoadStores(m_dataPath, m_defaultDbcLocale);
    if (!(m_availableDbcLocaleMask & (1 << m_defaultDbcLocale)))
    {
        TC_LOG_FATAL("server.loading", "Unable to load db2 files for {} locale specified in DBC.Locale config!", localeNames[m_defaultDbcLocale]);
        exit(1);
    }

    TC_LOG_INFO("server.loading", "Loading GameObject models...");
    if (!LoadGameObjectModelList(m_dataPath))
    {
        TC_LOG_FATAL("server.loading", "Unable to load gameobject models (part of vmaps), objects using WMO models will crash the client - server shutting down!");
        exit(1);
    }

    TC_LOG_INFO("misc", "Loading hotfix blobs...");
    sDB2Manager.LoadHotfixBlob(m_availableDbcLocaleMask);
    TC_LOG_INFO("misc", "Loading hotfix info...");
    sDB2Manager.LoadHotfixData(m_availableDbcLocaleMask);
    TC_LOG_INFO("misc", "Loading hotfix optional data...");
    sDB2Manager.LoadHotfixOptionalData(m_availableDbcLocaleMask);
    ///- Close hotfix database - it is only used during DB2 loading
    HotfixDatabase.Close();
    ///- Load M2 fly by cameras
    LoadM2Cameras(m_dataPath);
    ///- Load GameTables
    LoadGameTables(m_dataPath);

    //Load weighted graph on taxi nodes path
    TaxiPathGraph::Initialize();
    // Load IP Location Database
    sIPLocation->Load();

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

    MMAP::MMapManager* mmmgr = MMAP::MMapFactory::createOrGetMMapManager();
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
    sObjectMgr->LoadCreatureLocales();
    sObjectMgr->LoadGameObjectLocales();
    sObjectMgr->LoadQuestTemplateLocale();
    sObjectMgr->LoadQuestOfferRewardLocale();
    sObjectMgr->LoadQuestRequestItemsLocale();
    sObjectMgr->LoadQuestObjectivesLocale();
    sObjectMgr->LoadPageTextLocales();
    sObjectMgr->LoadGossipMenuItemsLocales();
    sObjectMgr->LoadPointOfInterestLocales();

    sObjectMgr->SetDBCLocaleIndex(GetDefaultDbcLocale());        // Get once for all the locale index of DBC language (console/broadcasts)
    TC_LOG_INFO("server.loading", ">> Localization strings loaded in {} ms", GetMSTimeDiffToNow(oldMSTime));

    TC_LOG_INFO("server.loading", "Loading Account Roles and Permissions...");
    sAccountMgr->LoadRBAC();

    TC_LOG_INFO("server.loading", "Loading Page Texts...");
    sObjectMgr->LoadPageTexts();

    TC_LOG_INFO("server.loading", "Loading Game Object Templates...");         // must be after LoadPageTexts
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
    sObjectMgr->LoadQuestGreetingLocales();

    TC_LOG_INFO("server.loading", "Loading Objects Pooling Data...");
    sPoolMgr->LoadFromDB();
    TC_LOG_INFO("server.loading", "Loading Quest Pooling Data...");
    sQuestPoolMgr->LoadFromDB();                                // must be after quest templates

    TC_LOG_INFO("server.loading", "Loading Game Event Data...");               // must be after loading pools fully
    sGameEventMgr->LoadFromDB();

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

    TC_LOG_INFO("server.loading", "Loading Player Choices Locales...");
    sObjectMgr->LoadPlayerChoicesLocale();

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
    TC_LOG_INFO("server.loading", "Loading Achievement Reward Locales...");
    sAchievementMgr->LoadRewardLocales();
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

    TC_LOG_INFO("server.loading", "Loading Waypoints...");
    sWaypointMgr->Load();

    TC_LOG_INFO("server.loading", "Loading Creature Formations...");
    sFormationMgr->LoadCreatureFormations();

    TC_LOG_INFO("server.loading", "Loading World State templates...");
    sWorldStateMgr->LoadFromDB();                               // must be loaded before battleground, outdoor PvP and conditions

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

    TC_LOG_INFO("server.loading", "Loading Creature Text Locales...");
    sCreatureTextMgr->LoadCreatureTextLocales();

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
                            realm.Id.Realm, uint32(GameTime::GetStartTime()), GitRevision::GetFullVersion());       // One-time query

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

    ///- Initialize outdoor pvp
    TC_LOG_INFO("server.loading", "Starting Outdoor PvP System");
    sOutdoorPvPMgr->InitOutdoorPvP();

    ///- Initialize Battlefield
    TC_LOG_INFO("server.loading", "Starting Battlefield System");
    sBattlefieldMgr->InitBattlefield();

    ///- Initialize Warden
    TC_LOG_INFO("server.loading", "Loading Warden Checks...");
    sWardenCheckMgr->LoadWardenChecks();

    TC_LOG_INFO("server.loading", "Loading Warden Action Overrides...");
    sWardenCheckMgr->LoadWardenOverrides();

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

    TC_LOG_INFO("server.worldserver", "World initialized in {} minutes {} seconds", (startupDuration / 60000), ((startupDuration % 60000) / 1000));

    TC_METRIC_EVENT("events", "World initialized", "World initialized in " + std::to_string(startupDuration / 60000) + " minutes " + std::to_string((startupDuration % 60000) / 1000) + " seconds");
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
    stmt->setInt32(0, realm.Id.Realm);
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

        m_Autobroadcasts[id] = { fields[2].GetString(), fields[1].GetUInt8() };

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
            ChannelMgr* mgr1 = ASSERT_NOTNULL(ChannelMgr::ForTeam(ALLIANCE));
            mgr1->SaveToDB();
            ChannelMgr* mgr2 = ASSERT_NOTNULL(ChannelMgr::ForTeam(HORDE));
            if (mgr1 != mgr2)
                mgr2->SaveToDB();
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
        stmt->setUInt32(2, realm.Id.Realm);
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
            stmt->setUInt32(2, realm.Id.Realm);

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
void World::SendGlobalMessage(WorldPacket const* packet, WorldSession* self, uint32 team)
{
    SessionMap::const_iterator itr;
    for (itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
    {
        if (itr->second &&
            itr->second->GetPlayer() &&
            itr->second->GetPlayer()->IsInWorld() &&
            itr->second != self &&
            (team == 0 || itr->second->GetPlayer()->GetTeam() == team))
        {
            itr->second->SendPacket(packet);
        }
    }
}

/// Send a packet to all GMs (except self if mentioned)
void World::SendGlobalGMMessage(WorldPacket const* packet, WorldSession* self, uint32 team)
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
bool World::SendZoneMessage(uint32 zone, WorldPacket const* packet, WorldSession* self, uint32 team)
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
            (team == 0 || itr->second->GetPlayer()->GetTeam() == team))
        {
            itr->second->SendPacket(packet);
            foundPlayerToSend = true;
        }
    }

    return foundPlayerToSend;
}

/// Send a System Message to all players in the zone (except self if mentioned)
void World::SendZoneText(uint32 zone, char const* text, WorldSession* self, uint32 team)
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
    if (strstr(serverMessage->Text[player->GetSession()->GetSessionDbcLocale()], "%s"))
        chatServerMessage.StringParam = stringParam;

    if (player)
        player->SendDirectMessage(chatServerMessage.Write());
    else
        SendGlobalMessage(chatServerMessage.Write());
}

void World::UpdateSessions(uint32 diff)
{
    std::pair<std::weak_ptr<WorldSocket>, uint64> linkInfo;
    while (_linkSocketQueue.next(linkInfo))
        ProcessLinkInstanceSocket(std::move(linkInfo));

    {
        TC_METRIC_DETAILED_NO_THRESHOLD_TIMER("world_update_time",
            TC_METRIC_TAG("type", "Add sessions"),
            TC_METRIC_TAG("parent_type", "Update sessions"));
        ///- Add new sessions
        WorldSession* sess = nullptr;
        while (addSessQueue.next(sess))
            AddSession_(sess);
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
        stmt->setUInt32(2, realm.Id.Realm);
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

    {
        std::ostringstream questIds;
        questIds << "DELETE cq, cqo FROM character_queststatus cq LEFT JOIN character_queststatus_objectives cqo ON cq.quest = cqo.quest WHERE cq.quest IN (";
        for (auto const& [questId, quest] : sObjectMgr->GetQuestTemplates())
        {
            if (quest.IsDaily() && quest.HasFlagEx(QUEST_FLAGS_EX_REMOVE_ON_PERIODIC_RESET))
                questIds << questId << ',';
        }
        questIds << "0)";

        CharacterDatabase.Execute(questIds.str().c_str());
    }

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

    {
        std::ostringstream questIds;
        questIds << "DELETE cq, cqo FROM character_queststatus cq LEFT JOIN character_queststatus_objectives cqo ON cq.quest = cqo.quest WHERE cq.quest IN (";
        for (auto const& [questId, quest] : sObjectMgr->GetQuestTemplates())
        {
            if (quest.IsWeekly() && quest.HasFlagEx(QUEST_FLAGS_EX_REMOVE_ON_PERIODIC_RESET))
                questIds << questId << ',';
        }
        questIds << "0)";

        CharacterDatabase.Execute(questIds.str().c_str());
    }

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
    stmt->setStringView(0, var.Id);
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

Realm realm;

uint32 GetVirtualRealmAddress()
{
    return realm.Id.GetAddress();
}

CliCommandHolder::CliCommandHolder(void* callbackArg, char const* command, Print zprint, CommandFinished commandFinished)
    : m_callbackArg(callbackArg), m_command(strdup(command)), m_print(zprint), m_commandFinished(commandFinished)
{
}

CliCommandHolder::~CliCommandHolder()
{
    free(m_command);
}
