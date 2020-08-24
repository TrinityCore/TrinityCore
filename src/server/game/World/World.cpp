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
#include "AddonMgr.h"
#include "ArenaTeamMgr.h"
#include "AuctionHouseBot.h"
#include "AuctionHouseMgr.h"
#include "BattlefieldMgr.h"
#include "BattlegroundMgr.h"
#include "CalendarMgr.h"
#include "ChannelMgr.h"
#include "CharacterCache.h"
#include "CharacterDatabaseCleaner.h"
#include "Chat.h"
#include "Config.h"
#include "CreatureAIRegistry.h"
#include "CreatureGroups.h"
#include "CreatureTextMgr.h"
#include "DatabaseEnv.h"
#include "DisableMgr.h"
#include "GameEventMgr.h"
#include "GameObjectModel.h"
#include "GameTime.h"
#include "GitRevision.h"
#include "GridNotifiersImpl.h"
#include "GroupMgr.h"
#include "GuildMgr.h"
#include "InstanceSaveMgr.h"
#include "IPLocation.h"
#include "Language.h"
#include "LFGMgr.h"
#include "Log.h"
#include "LootItemStorage.h"
#include "LootMgr.h"
#include "M2Stores.h"
#include "MapManager.h"
#include "Memory.h"
#include "Metric.h"
#include "MMapFactory.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "OutdoorPvPMgr.h"
#include "PetitionMgr.h"
#include "Player.h"
#include "PlayerDump.h"
#include "PoolMgr.h"
#include "QueryCallback.h"
#include "QuestPools.h"
#include "Realm.h"
#include "ScriptMgr.h"
#include "ScriptReloadMgr.h"
#include "ServerMotd.h"
#include "SkillDiscovery.h"
#include "SkillExtraItems.h"
#include "SmartScriptMgr.h"
#include "SpellMgr.h"
#include "TicketMgr.h"
#include "TransportMgr.h"
#include "Unit.h"
#include "UpdateTime.h"
#include "VMapFactory.h"
#include "VMapManager2.h"
#include "WardenCheckMgr.h"
#include "WaypointManager.h"
#include "WeatherMgr.h"
#include "WhoListStorage.h"
#include "WorldConfigMgr.h"
#include "WorldSession.h"

#include <boost/asio/ip/address.hpp>

TC_GAME_API std::atomic<bool> World::m_stopEvent(false);
TC_GAME_API uint8 World::m_ExitCode = SHUTDOWN_EXIT_CODE;

TC_GAME_API std::atomic<uint32> World::m_worldLoopCounter(0);

TC_GAME_API float World::m_MaxVisibleDistanceOnContinents = DEFAULT_VISIBILITY_DISTANCE;
TC_GAME_API float World::m_MaxVisibleDistanceInInstances  = DEFAULT_VISIBILITY_INSTANCE;
TC_GAME_API float World::m_MaxVisibleDistanceInBGArenas   = DEFAULT_VISIBILITY_BGARENAS;

TC_GAME_API int32 World::m_visibility_notify_periodOnContinents = DEFAULT_VISIBILITY_NOTIFY_PERIOD;
TC_GAME_API int32 World::m_visibility_notify_periodInInstances  = DEFAULT_VISIBILITY_NOTIFY_PERIOD;
TC_GAME_API int32 World::m_visibility_notify_periodInBGArenas   = DEFAULT_VISIBILITY_NOTIFY_PERIOD;

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

    m_defaultDbcLocale = LOCALE_enUS;
    m_availableDbcLocaleMask = 0;

    mail_timer = 0;
    mail_timer_expires = 0;

    m_isClosed = false;

    m_CleaningFlags = 0;

    memset(rate_values, 0, sizeof(rate_values));
    memset(m_int_configs, 0, sizeof(m_int_configs));
    memset(m_bool_configs, 0, sizeof(m_bool_configs));
    memset(m_float_configs, 0, sizeof(m_float_configs));
    memset(m_string_configs, 0, sizeof(m_string_configs));

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
            delete old->second;
        }
    }

    m_sessions[s->GetAccountId()] = s;

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
        TC_LOG_INFO("misc", "PlayerQueue: Account id %u is in Queue Position (%u).", s->GetAccountId(), ++QueueSize);
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
        TC_LOG_INFO("misc", "Server Population (%f).", popu);
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
    sess->SendAuthResponse(AUTH_WAIT_QUEUE, false, GetQueuePos(sess));
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
        (*iter)->SendAuthWaitQue(position);

    return found;
}

/// Initialize config values
void World::LoadConfigSettings(bool reload)
{
    if (reload)
    {
        std::string configError;
        if (!sConfigMgr->Reload(configError))
        {
            TC_LOG_ERROR("misc", "World settings reload fail: %s.", configError.c_str());
            return;
        }
        sLog->LoadFromConfig();
        sMetric->LoadFromConfigs();
    }

    // STAGE 1 - Load Server configs (from config files)
    ///- Read the "Data" directory from the config file
    std::string dataPath = sConfigMgr->GetStringDefault("DataDir", "./");
    if (dataPath.empty() || (dataPath.at(dataPath.length() - 1) != '/' && dataPath.at(dataPath.length() - 1) != '\\'))
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
            TC_LOG_ERROR("server.loading", "DataDir option can't be changed at worldserver.conf reload, using current value (%s).", m_dataPath.c_str());
    }
    else
    {
        m_dataPath = dataPath;
        TC_LOG_INFO("server.loading", "Using DataDir %s", m_dataPath.c_str());
    }

    TC_LOG_INFO("server.loading", "WORLD: VMap data directory is: %svmaps", m_dataPath.c_str());
    TC_LOG_INFO("server.loading", "WORLD: MMap data directory is: %smmaps", m_dataPath.c_str());

    // STAGE 2 - Load all others from DB
    sWorldConfig->Load();
    sWorldConfig->RecheckAndFixDependancy();

    //###               FLOAT configs:
    ///-visibility on continents
    m_MaxVisibleDistanceOnContinents = m_float_configs[CONFIG_VISIBLITY_DISTANCE_CONTINENTS];
    ///-visibility in instances
    m_MaxVisibleDistanceInInstances = m_float_configs[CONFIG_VISIBILITY_DISTANCE_INSTANCES];
    ///-visibility in BG/Arenas
    m_MaxVisibleDistanceInBGArenas = m_float_configs[CONFIG_VISIBILITY_DISTANCE_BGARENAS];
    ///- Read all rates from the config file
    for (uint8 i = 0; i < MAX_MOVE_TYPE; ++i)
        playerBaseMoveSpeed[i] = baseMoveSpeed[i] * rate_values[RATE_MOVESPEED];
    //###      End

    //###               INT configs:
    ///- Read the player limit and the Message of the day from the config file
    SetPlayerAmountLimit(m_int_configs[CONFIG_MAX_PLAYERS_ON_REALM]);
    m_visibility_notify_periodOnContinents = m_int_configs[CONFIG_VISIBILITY_NOTIFY_PERIOD_ONCONTINENTS];
    m_visibility_notify_periodInInstances = m_int_configs[CONFIG_VISIBILITY_NOTIFY_PERIOD_ININSTANCES];
    m_visibility_notify_periodInBGArenas = m_int_configs[CONFIG_VISIBILITY_NOTIFY_PERIOD_INBGARENAS];
    TC_LOG_INFO("server.loading", "Will clear `logs` table of entries older than %i seconds every %u minutes.", m_int_configs[CONFIG_LOGDB_CLEARTIME], m_int_configs[CONFIG_LOGDB_CLEARINTERVAL]);
    TC_LOG_INFO("server.loading", "Client cache version set to: %u", m_int_configs[CONFIG_CLIENTCACHE_VERSION]);
    //###      End

    //###               STRING configs:
    _guidWarningMsg = m_string_configs[CONFIG_RESPAWN_WARNING_MESSAGE];
    _alertRestartReason = m_string_configs[CONFIG_RESPAWN_ALERT_RESTART_REASON];
    ///- Get string for new MOTD
    Motd::SetMotd(m_string_configs[CONFIG_MOTD]);
    ///- Get string for new logins (newly created characters)
    SetNewCharString(m_string_configs[CONFIG_PLAYER_START_STRING]);    
    //###      End

    //###               BOOL configs:
    bool enableIndoor = m_bool_configs[CONFIG_VMAP_INDOOR_CHECK];
    bool enableLOS = m_bool_configs[CONFIG_VMAP_ENABLE_LOS];
    bool enableHeight = m_bool_configs[CONFIG_VMAP_ENABLE_HEIGHT_CALCULATION];
    if (!enableHeight)
        TC_LOG_ERROR("server.loading", "VMap height checking disabled! Creatures movements and other various things WILL be broken! Expect no support.");

    VMAP::VMapFactory::createOrGetVMapManager()->setEnableLineOfSightCalc(enableLOS);
    VMAP::VMapFactory::createOrGetVMapManager()->setEnableHeightCalc(enableHeight);
    TC_LOG_INFO("server.loading", "VMap support included. LineOfSight: %i, getHeight: %i, indoorCheck: %i", enableLOS, enableHeight, enableIndoor);
    //###      End

    if (reload)
    {
        sMapMgr->SetGridCleanUpDelay(m_int_configs[CONFIG_INTERVAL_GRIDCLEAN]);
        sMapMgr->SetMapUpdateInterval(m_int_configs[CONFIG_INTERVAL_MAPUPDATE]);

        m_timers[WUPDATE_UPTIME].SetInterval(m_int_configs[CONFIG_UPTIME_UPDATE] * MINUTE * IN_MILLISECONDS);
        m_timers[WUPDATE_UPTIME].Reset();

        // log db cleanup interval
        m_timers[WUPDATE_CLEANDB].SetInterval(m_int_configs[CONFIG_LOGDB_CLEARINTERVAL] * MINUTE * IN_MILLISECONDS);
        m_timers[WUPDATE_CLEANDB].Reset();

        m_timers[WUPDATE_AUTOBROADCAST].SetInterval(m_int_configs[CONFIG_AUTOBROADCAST_INTERVAL]);
        m_timers[WUPDATE_AUTOBROADCAST].Reset();

        sScriptMgr->OnConfigLoad(reload);
    }
}

/// Initialize the World
void World::SetInitialWorldSettings()
{
    if (uint32 realmId = sConfigMgr->GetIntDefault("RealmID", 0)) // 0 reserved for auth
        sLog->SetRealmId(realmId);

    ///- Server startup begin
    uint32 startupBegin = getMSTime();

    ///- Initialize the random number generator
    srand((unsigned int)GameTime::GetGameTime());

    ///- Initialize detour memory management
    dtAllocSetCustom(dtCustomAlloc, dtCustomFree);

    ///- Initialize VMapManager function pointers (to untangle game/collision circular deps)
    if (VMAP::VMapManager2* vmmgr2 = dynamic_cast<VMAP::VMapManager2*>(VMAP::VMapFactory::createOrGetVMapManager()))
    {
        vmmgr2->GetLiquidFlagsPtr = &GetLiquidFlags;
        vmmgr2->IsVMAPDisabledForPtr = &DisableMgr::IsVMAPDisabledFor;
    }

    ///- Initialize config settings
    LoadConfigSettings();

    ///- Initialize Allowed Security Level
    LoadDBAllowedSecurityLevel();

    ///- Init highest guids before any table loading to prevent using not initialized guids in some code.
    sObjectMgr->SetHighestGuids();

    ///- Check the existence of the map files for all races' startup areas.
    if (!MapManager::ExistMapAndVMap(0, -6240.32f, 331.033f)
        || !MapManager::ExistMapAndVMap(0, -8949.95f, -132.493f)
        || !MapManager::ExistMapAndVMap(1, -618.518f, -4251.67f)
        || !MapManager::ExistMapAndVMap(0, 1676.35f, 1677.45f)
        || !MapManager::ExistMapAndVMap(1, 10311.3f, 832.463f)
        || !MapManager::ExistMapAndVMap(1, -2917.58f, -257.98f)
        || (m_int_configs[CONFIG_EXPANSION] && (
            !MapManager::ExistMapAndVMap(530, 10349.6f, -6357.29f) ||
            !MapManager::ExistMapAndVMap(530, -3961.64f, -13931.2f))))
    {
        TC_LOG_FATAL("server.loading", "Unable to load critical files - server shutting down !!!");
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

    LoginDatabase.PExecute("UPDATE realmlist SET icon = %u, timezone = %u WHERE id = '%d'", server_type, realm_zone, realm.Id.Realm);      // One-time query

    ///- Load the DBC files
    TC_LOG_INFO("server.loading", "Initialize data stores...");
    LoadDBCStores(m_dataPath);
    DetectDBCLang();

    // Load cinematic cameras
    LoadM2Cameras(m_dataPath);

    // Load IP Location Database
    sIPLocation->Load();

    std::vector<uint32> mapIds;
    for (uint32 mapId = 0; mapId < sMapStore.GetNumRows(); mapId++)
        if (sMapStore.LookupEntry(mapId))
            mapIds.push_back(mapId);

    if (VMAP::VMapManager2* vmmgr2 = dynamic_cast<VMAP::VMapManager2*>(VMAP::VMapFactory::createOrGetVMapManager()))
        vmmgr2->InitializeThreadUnsafe(mapIds);

    MMAP::MMapManager* mmmgr = MMAP::MMapFactory::createOrGetMMapManager();
    mmmgr->InitializeThreadUnsafe(mapIds);

    TC_LOG_INFO("server.loading", "Initializing PlayerDump tables...");
    PlayerDump::InitializeTables();

    ///- Initialize static helper structures
    AIRegistry::Initialize();

    TC_LOG_INFO("server.loading", "Loading SpellInfo store...");
    sSpellMgr->LoadSpellInfoStore();

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

    TC_LOG_INFO("server.loading", "Loading Player Totem models...");
    sObjectMgr->LoadPlayerTotemModels();

    TC_LOG_INFO("server.loading", "Loading GameObject models...");
    LoadGameObjectModelList(m_dataPath);

    TC_LOG_INFO("server.loading", "Loading Script Names...");
    sObjectMgr->LoadScriptNames();

    TC_LOG_INFO("server.loading", "Loading Instance Template...");
    sObjectMgr->LoadInstanceTemplate();

    // Must be called before `respawn` data
    TC_LOG_INFO("server.loading", "Loading instances...");
    sInstanceSaveMgr->LoadInstances();

    // Load before guilds and arena teams
    TC_LOG_INFO("server.loading", "Loading character cache store...");
    sCharacterCache->LoadCharacterCacheStorage();

    TC_LOG_INFO("server.loading", "Loading Broadcast texts...");
    sObjectMgr->LoadBroadcastTexts();
    sObjectMgr->LoadBroadcastTextLocales();

    TC_LOG_INFO("server.loading", "Loading Localization strings...");
    uint32 oldMSTime = getMSTime();
    sObjectMgr->LoadCreatureLocales();
    sObjectMgr->LoadGameObjectLocales();
    sObjectMgr->LoadItemLocales();
    sObjectMgr->LoadItemSetNameLocales();
    sObjectMgr->LoadQuestLocales();
    sObjectMgr->LoadQuestOfferRewardLocale();
    sObjectMgr->LoadQuestRequestItemsLocale();
    sObjectMgr->LoadNpcTextLocales();
    sObjectMgr->LoadPageTextLocales();
    sObjectMgr->LoadGossipMenuItemsLocales();
    sObjectMgr->LoadPointOfInterestLocales();
    sObjectMgr->LoadQuestGreetingLocales();

    sObjectMgr->SetDBCLocaleIndex(GetDefaultDbcLocale());        // Get once for all the locale index of DBC language (console/broadcasts)
    TC_LOG_INFO("server.loading", ">> Localization strings loaded in %u ms", GetMSTimeDiffToNow(oldMSTime));

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

    TC_LOG_INFO("server.loading", "Loading Spell Bonus Data...");
    sSpellMgr->LoadSpellBonuses();

    TC_LOG_INFO("server.loading", "Loading Aggro Spells Definitions...");
    sSpellMgr->LoadSpellThreats();

    TC_LOG_INFO("server.loading", "Loading Spell Group Stack Rules...");
    sSpellMgr->LoadSpellGroupStackRules();

    TC_LOG_INFO("server.loading", "Loading NPC Texts...");
    sObjectMgr->LoadGossipText();

    TC_LOG_INFO("server.loading", "Loading Enchant Spells Proc datas...");
    sSpellMgr->LoadSpellEnchantProcData();

    TC_LOG_INFO("server.loading", "Loading Item Random Enchantments Table...");
    LoadRandomEnchantmentsTable();

    TC_LOG_INFO("server.loading", "Loading Disables");                         // must be before loading quests and items
    DisableMgr::LoadDisables();

    TC_LOG_INFO("server.loading", "Loading Items...");                         // must be after LoadRandomEnchantmentsTable and LoadPageTexts
    sObjectMgr->LoadItemTemplates();

    TC_LOG_INFO("server.loading", "Loading Item set names...");                // must be after LoadItemPrototypes
    sObjectMgr->LoadItemSetNames();

    TC_LOG_INFO("server.loading", "Loading Creature Model Based Info Data...");
    sObjectMgr->LoadCreatureModelInfo();

    TC_LOG_INFO("server.loading", "Loading Creature templates...");
    sObjectMgr->LoadCreatureTemplates();

    TC_LOG_INFO("server.loading", "Loading Equipment templates...");           // must be after LoadCreatureTemplates
    sObjectMgr->LoadEquipmentTemplates();

    TC_LOG_INFO("server.loading", "Loading Creature template addons...");
    sObjectMgr->LoadCreatureTemplateAddons();

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

    TC_LOG_INFO("server.loading", "Loading instance spawn groups...");
    sObjectMgr->LoadInstanceSpawnGroups();

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
    sObjectMgr->LoadQuests();                                    // must be loaded after DBCs, creature_template, item_template, gameobject tables

    TC_LOG_INFO("server.loading", "Checking Quest Disables");
    DisableMgr::CheckQuestDisables();                           // must be after loading quests

    TC_LOG_INFO("server.loading", "Loading Quest POI");
    sObjectMgr->LoadQuestPOI();

    TC_LOG_INFO("server.loading", "Loading Quests Starters and Enders...");
    sObjectMgr->LoadQuestStartersAndEnders();                    // must be after quest load

    TC_LOG_INFO("server.loading", "Loading Quests Greetings...");
    sObjectMgr->LoadQuestGreetings();                           // must be loaded after creature_template, gameobject_template tables

    TC_LOG_INFO("server.loading", "Loading Objects Pooling Data...");
    sPoolMgr->LoadFromDB();
    TC_LOG_INFO("server.loading", "Loading Quest Pooling Data...");
    sQuestPoolMgr->LoadFromDB();                                // must be after quest templates

    TC_LOG_INFO("server.loading", "Loading Game Event Data...");               // must be after loading pools fully
    sGameEventMgr->LoadHolidayDates();                           // Must be after loading DBC
    sGameEventMgr->LoadFromDB();                                 // Must be after loading holiday dates

    TC_LOG_INFO("server.loading", "Loading UNIT_NPC_FLAG_SPELLCLICK Data..."); // must be after LoadQuests
    sObjectMgr->LoadNPCSpellClickSpells();

    TC_LOG_INFO("server.loading", "Loading Vehicle Template Accessories...");
    sObjectMgr->LoadVehicleTemplateAccessories();                // must be after LoadCreatureTemplates() and LoadNPCSpellClickSpells()

    TC_LOG_INFO("server.loading", "Loading Vehicle Accessories...");
    sObjectMgr->LoadVehicleAccessories();                       // must be after LoadCreatureTemplates() and LoadNPCSpellClickSpells()

    TC_LOG_INFO("server.loading", "Loading Vehicle Seat Addon Data...");
    sObjectMgr->LoadVehicleSeatAddon();                         // must be after loading DBC

    TC_LOG_INFO("server.loading", "Loading SpellArea Data...");                // must be after quest load
    sSpellMgr->LoadSpellAreas();

    TC_LOG_INFO("server.loading", "Loading AreaTrigger definitions...");
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

    TC_LOG_INFO("server.loading", "Loading Dungeon boss data...");
    sObjectMgr->LoadInstanceEncounters();

    TC_LOG_INFO("server.loading", "Loading LFG rewards...");
    sLFGMgr->LoadRewards();

    TC_LOG_INFO("server.loading", "Loading Graveyard-zone links...");
    sObjectMgr->LoadGraveyardZones();

    TC_LOG_INFO("server.loading", "Loading spell pet auras...");
    sSpellMgr->LoadSpellPetAuras();

    TC_LOG_INFO("server.loading", "Loading Spell target coordinates...");
    sSpellMgr->LoadSpellTargetPositions();

    TC_LOG_INFO("server.loading", "Loading enchant custom attributes...");
    sSpellMgr->LoadEnchantCustomAttr();

    TC_LOG_INFO("server.loading", "Loading linked spells...");
    sSpellMgr->LoadSpellLinked();

    TC_LOG_INFO("server.loading", "Loading Player Create Data...");
    sObjectMgr->LoadPlayerInfo();

    TC_LOG_INFO("server.loading", "Loading Exploration BaseXP Data...");
    sObjectMgr->LoadExplorationBaseXP();

    TC_LOG_INFO("server.loading", "Loading Pet Name Parts...");
    sObjectMgr->LoadPetNames();

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

    TC_LOG_INFO("server.loading", "Loading Achievements...");
    sAchievementMgr->LoadAchievementReferenceList();
    TC_LOG_INFO("server.loading", "Loading Achievement Criteria Lists...");
    sAchievementMgr->LoadAchievementCriteriaList();
    TC_LOG_INFO("server.loading", "Loading Achievement Criteria Data...");
    sAchievementMgr->LoadAchievementCriteriaData();
    TC_LOG_INFO("server.loading", "Loading Achievement Rewards...");
    sAchievementMgr->LoadRewards();
    TC_LOG_INFO("server.loading", "Loading Achievement Reward Locales...");
    sAchievementMgr->LoadRewardLocales();
    TC_LOG_INFO("server.loading", "Loading Completed Achievements...");
    sAchievementMgr->LoadCompletedAchievements();

    ///- Load dynamic data tables from the database
    TC_LOG_INFO("server.loading", "Loading Item Auctions...");
    sAuctionMgr->LoadAuctionItems();

    TC_LOG_INFO("server.loading", "Loading Auctions...");
    sAuctionMgr->LoadAuctions();

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

    TC_LOG_INFO("server.loading", "Loading Trainers...");       // must be after LoadCreatureTemplates
    sObjectMgr->LoadTrainers();

    TC_LOG_INFO("server.loading", "Loading Creature default trainers...");
    sObjectMgr->LoadCreatureDefaultTrainers();

    TC_LOG_INFO("server.loading", "Loading Gossip menu...");
    sObjectMgr->LoadGossipMenu();

    TC_LOG_INFO("server.loading", "Loading Gossip menu options...");
    sObjectMgr->LoadGossipMenuItems();                           // must be after LoadTrainers

    TC_LOG_INFO("server.loading", "Loading Vendors...");
    sObjectMgr->LoadVendors();                                   // must be after load CreatureTemplate and ItemTemplate

    TC_LOG_INFO("server.loading", "Loading Waypoints...");
    sWaypointMgr->Load();

    TC_LOG_INFO("server.loading", "Loading SmartAI Waypoints...");
    sSmartWaypointMgr->LoadFromDB();

    TC_LOG_INFO("server.loading", "Loading Creature Formations...");
    sFormationMgr->LoadCreatureFormations();

    TC_LOG_INFO("server.loading", "Loading World States...");              // must be loaded before battleground, outdoor PvP and conditions
    LoadWorldStates();

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

    TC_LOG_INFO("server.loading", "Loading GM tickets...");
    sTicketMgr->LoadTickets();

    TC_LOG_INFO("server.loading", "Loading GM surveys...");
    sTicketMgr->LoadSurveys();

    TC_LOG_INFO("server.loading", "Loading client addons...");
    AddonMgr::LoadFromDB();

    ///- Handle outdated emails (delete/return)
    TC_LOG_INFO("server.loading", "Returning old mails...");
    sObjectMgr->ReturnOrDeleteOldMails(false);

    TC_LOG_INFO("server.loading", "Loading Autobroadcasts...");
    LoadAutobroadcasts();

    ///- Load and initialize scripts
    sObjectMgr->LoadSpellScripts();                              // must be after load Creature/Gameobject(Template/Data)
    sObjectMgr->LoadEventScripts();                              // must be after load Creature/Gameobject(Template/Data)
    sObjectMgr->LoadWaypointScripts();

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
    ChatHandler::InitializeCommandTable();

    ///- Initialize game time and timers
    TC_LOG_INFO("server.loading", "Initialize game time and timers");
    GameTime::UpdateGameTimers();

    LoginDatabase.PExecute("INSERT INTO uptime (realmid, starttime, uptime, revision) VALUES(%u, %u, 0, '%s')",
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
    TC_LOG_INFO("server.loading", "Mail timer set to: " UI64FMTD ", mail return is called every " UI64FMTD " minutes", uint64(mail_timer), uint64(mail_timer_expires));

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

    TC_LOG_INFO("server.loading", "Starting Arena Season...");
    sGameEventMgr->StartArenaSeason();

    sTicketMgr->Initialize();

    ///- Initialize Battlegrounds
    TC_LOG_INFO("server.loading", "Starting Battleground System");
    sBattlegroundMgr->LoadBattlegroundTemplates();
    sBattlegroundMgr->InitAutomaticArenaPointDistribution();

    ///- Initialize outdoor pvp
    TC_LOG_INFO("server.loading", "Starting Outdoor PvP System");
    sOutdoorPvPMgr->InitOutdoorPvP();

    ///- Initialize Battlefield
    TC_LOG_INFO("server.loading", "Starting Battlefield System");
    sBattlefieldMgr->InitBattlefield();

    TC_LOG_INFO("server.loading", "Loading Transports...");
    sTransportMgr->SpawnContinentTransports();

    ///- Initialize Warden
    TC_LOG_INFO("server.loading", "Loading Warden Checks...");
    sWardenCheckMgr->LoadWardenChecks();

    TC_LOG_INFO("server.loading", "Loading Warden Action Overrides...");
    sWardenCheckMgr->LoadWardenOverrides();

    TC_LOG_INFO("server.loading", "Deleting expired bans...");
    LoginDatabase.Execute("DELETE FROM ip_banned WHERE unbandate <= UNIX_TIMESTAMP() AND unbandate<>bandate");      // One-time query

    TC_LOG_INFO("server.loading", "Initializing quest reset times...");
    InitQuestResetTimes();
    CheckQuestResetTimes();

    TC_LOG_INFO("server.loading", "Calculate random battleground reset time...");
    InitRandomBGResetTime();

    TC_LOG_INFO("server.loading", "Calculate deletion of old calendar events time...");
    InitCalendarOldEventsDeletionTime();

    TC_LOG_INFO("server.loading", "Calculate guild limitation(s) reset time...");
    InitGuildResetTime();

    // Preload all cells, if required for the base maps
    if (sWorld->getBoolConfig(CONFIG_BASEMAP_LOAD_GRIDS))
    {
        sMapMgr->DoForAllMaps([](Map* map)
        {
            if (!map->Instanceable())
            {
                TC_LOG_INFO("server.loading", "Pre-loading base map data for map %u", map->GetId());
                map->LoadAllCells();
            }
        });
    }

    uint32 startupDuration = GetMSTimeDiffToNow(startupBegin);

    TC_LOG_INFO("server.worldserver", "World initialized in %u minutes %u seconds", (startupDuration / 60000), ((startupDuration % 60000) / 1000));

    TC_METRIC_EVENT("events", "World initialized", "World initialized in " + std::to_string(startupDuration / 60000) + " minutes " + std::to_string((startupDuration % 60000) / 1000) + " seconds");
}

void World::DetectDBCLang()
{
    uint8 m_lang_confid = sConfigMgr->GetIntDefault("DBC.Locale", 255);

    if (m_lang_confid != 255 && m_lang_confid >= TOTAL_LOCALES)
    {
        TC_LOG_ERROR("server.loading", "Incorrect DBC.Locale! Must be >= 0 and < %d (set to 0)", TOTAL_LOCALES);
        m_lang_confid = LOCALE_enUS;
    }

    ChrRacesEntry const* race = sChrRacesStore.LookupEntry(1);

    std::string availableLocalsStr;

    uint8 default_locale = TOTAL_LOCALES;
    for (uint8 i = default_locale-1; i < TOTAL_LOCALES; --i)  // -1 will be 255 due to uint8
    {
        if (race->Name[i][0] != '\0')                     // check by race names
        {
            default_locale = i;
            m_availableDbcLocaleMask |= (1 << i);
            availableLocalsStr += localeNames[i];
            availableLocalsStr += " ";
        }
    }

    if (default_locale != m_lang_confid && m_lang_confid < TOTAL_LOCALES &&
        (m_availableDbcLocaleMask & (1 << m_lang_confid)))
    {
        default_locale = m_lang_confid;
    }

    if (default_locale >= TOTAL_LOCALES)
    {
        TC_LOG_ERROR("server.loading", "Unable to determine your DBC Locale! (corrupt DBC?)");
        exit(1);
    }

    m_defaultDbcLocale = LocaleConstant(default_locale);

    TC_LOG_INFO("server.loading", "Using %s DBC Locale as default. All available DBC locales: %s", localeNames[m_defaultDbcLocale], availableLocalsStr.empty() ? "<none>" : availableLocalsStr.c_str());
}

void World::LoadAutobroadcasts()
{
    uint32 oldMSTime = getMSTime();

    m_Autobroadcasts.clear();
    m_AutobroadcastsWeights.clear();

    uint32 realmId = sConfigMgr->GetIntDefault("RealmID", 0);
    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_AUTOBROADCAST);
    stmt->setInt32(0, realmId);
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 autobroadcasts definitions. DB table `autobroadcast` is empty for this realm!");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();
        uint8 id = fields[0].GetUInt8();

        m_Autobroadcasts[id] = fields[2].GetString();
        m_AutobroadcastsWeights[id] = fields[1].GetUInt8();

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u autobroadcast definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
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

        if (sWorld->getBoolConfig(CONFIG_PRESERVE_CUSTOM_CHANNELS))
        {
            TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Save custom channels"));
            ChannelMgr* mgr1 = ASSERT_NOTNULL(ChannelMgr::forTeam(ALLIANCE));
            mgr1->SaveToDB();
            ChannelMgr* mgr2 = ASSERT_NOTNULL(ChannelMgr::forTeam(HORDE));
            if (mgr1 != mgr2)
                mgr2->SaveToDB();
        }
    }

    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Check quest reset times"));
        CheckQuestResetTimes();
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

    /// <li> Handle AHBot operations
    if (m_timers[WUPDATE_AHBOT].Passed())
    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Update AHBot"));
        sAuctionBot->Update();
        m_timers[WUPDATE_AHBOT].Reset();
    }

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
    if (sWorld->getIntConfig(CONFIG_LOGDB_CLEARTIME) > 0) // if not enabled, ignore the timer
    {
        if (m_timers[WUPDATE_CLEANDB].Passed())
        {
            TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Clean logs table"));
            m_timers[WUPDATE_CLEANDB].Reset();

            LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_OLD_LOGS);

            stmt->setUInt32(0, sWorld->getIntConfig(CONFIG_LOGDB_CLEARTIME));
            stmt->setUInt32(1, uint32(time(0)));
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

    if (sWorld->getBoolConfig(CONFIG_AUTOBROADCAST))
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

    {
        TC_METRIC_TIMER("world_update_time", TC_METRIC_TAG("type", "Update instance reset times"));
        // update the instance reset times
        sInstanceSaveMgr->Update();
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
        public:
            typedef std::vector<WorldPacket*> WorldPacketList;
            explicit WorldWorldTextBuilder(uint32 textId, va_list* args = nullptr) : i_textId(textId), i_args(args) { }
            void operator()(WorldPacketList& data_list, LocaleConstant loc_idx)
            {
                char const* text = sObjectMgr->GetTrinityString(i_textId, loc_idx);

                if (i_args)
                {
                    // we need copy va_list before use or original va_list will corrupted
                    va_list ap;
                    va_copy(ap, *i_args);

                    char str[2048];
                    vsnprintf(str, 2048, text, ap);
                    va_end(ap);

                    do_helper(data_list, &str[0]);
                }
                else
                    do_helper(data_list, (char*)text);
            }
        private:
            char* lineFromMessage(char*& pos) { char* start = strtok(pos, "\n"); pos = nullptr; return start; }
            void do_helper(WorldPacketList& data_list, char* text)
            {
                char* pos = text;
                while (char* line = lineFromMessage(pos))
                {
                    WorldPacket* data = new WorldPacket();
                    ChatHandler::BuildChatPacket(*data, CHAT_MSG_SYSTEM, LANG_UNIVERSAL, nullptr, nullptr, line);
                    data_list.push_back(data);
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
    Trinity::LocalizedPacketListDo<Trinity::WorldWorldTextBuilder> wt_do(wt_builder);
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
    Trinity::LocalizedPacketListDo<Trinity::WorldWorldTextBuilder> wt_do(wt_builder);
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
    WorldPacket data;

    // need copy to prevent corruption by strtok call in LineFromMessage original string
    char* buf = strdup(text);
    char* pos = buf;

    while (char* line = ChatHandler::LineFromMessage(pos))
    {
        ChatHandler::BuildChatPacket(data, CHAT_MSG_SYSTEM, LANG_UNIVERSAL, nullptr, nullptr, line);
        SendGlobalMessage(&data, self);
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
    WorldPacket data;
    ChatHandler::BuildChatPacket(data, CHAT_MSG_SYSTEM, LANG_UNIVERSAL, nullptr, nullptr, text);
    SendZoneMessage(zone, &data, self, team);
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
    ObjectGuid::LowType guid = 0;

    uint32 duration_secs = TimeStringToSecs(duration);

    /// Pick a player to ban if not online
    if (!banned)
    {
        ObjectGuid fullGuid = sCharacterCache->GetCharacterGuidByName(name);
        if (fullGuid.IsEmpty())
            return BAN_NOTFOUND;                                    // Nobody to ban

        guid = fullGuid.GetCounter();
    }
    else
        guid = banned->GetGUID().GetCounter();
    //Use transaction in order to ensure the order of the queries
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    // make sure there is only one active ban
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHARACTER_BAN);
    stmt->setUInt32(0, guid);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_BAN);
    stmt->setUInt32(0, guid);
    stmt->setUInt32(1, duration_secs);
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
    ObjectGuid::LowType guid = 0;

    /// Pick a player to ban if not online
    if (!banned)
    {
        ObjectGuid fullGuid = sCharacterCache->GetCharacterGuidByName(name);
        if (fullGuid.IsEmpty())
            return false;

        guid = fullGuid.GetCounter();
    }
    else
        guid = banned->GetGUID().GetCounter();

    if (!guid)
        return false;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHARACTER_BAN);
    stmt->setUInt32(0, guid);
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

        SendServerMessage(msgid, str.c_str(), player);
        TC_LOG_DEBUG("misc", "Server is %s in %s", (m_ShutdownMask & SHUTDOWN_MASK_RESTART ? "restart" : "shuttingdown"), str.c_str());
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

    TC_LOG_DEBUG("misc", "Server %s cancelled.", (m_ShutdownMask & SHUTDOWN_MASK_RESTART ? "restart" : "shutdown"));

    sScriptMgr->OnShutdownCancel();
    return oldTimer;
}

/// Send a server message to the user(s)
void World::SendServerMessage(ServerMessageType type, const char *text, Player* player)
{
    WorldPacket data(SMSG_SERVER_MESSAGE, 50);              // guess size
    data << uint32(type);
    if (type <= SERVER_MSG_STRING)
        data << text;

    if (player)
        player->SendDirectMessage(&data);
    else
        SendGlobalMessage(&data);
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

    uint32 weight = 0;
    AutobroadcastsWeightMap selectionWeights;
    std::string msg;

    for (AutobroadcastsWeightMap::const_iterator it = m_AutobroadcastsWeights.begin(); it != m_AutobroadcastsWeights.end(); ++it)
    {
        if (it->second)
        {
            weight += it->second;
            selectionWeights[it->first] = it->second;
        }
    }

    if (weight)
    {
        uint32 selectedWeight = urand(0, weight - 1);
        weight = 0;
        for (AutobroadcastsWeightMap::const_iterator it = selectionWeights.begin(); it != selectionWeights.end(); ++it)
        {
            weight += it->second;
            if (selectedWeight < weight)
            {
                msg = m_Autobroadcasts[it->first];
                break;
            }
        }
    }
    else
        msg = m_Autobroadcasts[urand(0, m_Autobroadcasts.size())];

    uint32 abcenter = sWorld->getIntConfig(CONFIG_AUTOBROADCAST_CENTER);

    if (abcenter == 0)
        sWorld->SendWorldText(LANG_AUTO_BROADCAST, msg.c_str());
    else if (abcenter == 1)
    {
        WorldPacket data(SMSG_NOTIFICATION, (msg.size()+1));
        data << msg;
        sWorld->SendGlobalMessage(&data);
    }
    else if (abcenter == 2)
    {
        sWorld->SendWorldText(LANG_AUTO_BROADCAST, msg.c_str());

        WorldPacket data(SMSG_NOTIFICATION, (msg.size()+1));
        data << msg;
        sWorld->SendGlobalMessage(&data);
    }

    TC_LOG_DEBUG("misc", "AutoBroadcast: '%s'", msg.c_str());
}

void World::UpdateRealmCharCount(uint32 accountId)
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_COUNT);
    stmt->setUInt32(0, accountId);
    _queryProcessor.AddCallback(CharacterDatabase.AsyncQuery(stmt).WithPreparedCallback(std::bind(&World::_UpdateRealmCharCount, this, std::placeholders::_1)));
}

void World::_UpdateRealmCharCount(PreparedQueryResult resultCharCount)
{
    if (resultCharCount)
    {
        Field* fields = resultCharCount->Fetch();
        uint32 accountId = fields[0].GetUInt32();
        uint8 charCount = uint8(fields[1].GetUInt64());

        LoginDatabaseTransaction trans = LoginDatabase.BeginTransaction();

        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_REALM_CHARACTERS_BY_REALM);
        stmt->setUInt32(0, accountId);
        stmt->setUInt32(1, realm.Id.Realm);
        trans->Append(stmt);

        stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_REALM_CHARACTERS);
        stmt->setUInt8(0, charCount);
        stmt->setUInt32(1, accountId);
        stmt->setUInt32(2, realm.Id.Realm);
        trans->Append(stmt);

        LoginDatabase.CommitTransaction(trans);
    }
}

void World::InitQuestResetTimes()
{
    m_NextDailyQuestReset = sWorld->getWorldState(WS_DAILY_QUEST_RESET_TIME);
    m_NextWeeklyQuestReset = sWorld->getWorldState(WS_WEEKLY_QUEST_RESET_TIME);
    m_NextMonthlyQuestReset = sWorld->getWorldState(WS_MONTHLY_QUEST_RESET_TIME);
}

static time_t GetNextDailyResetTime(time_t t)
{
    return GetLocalHourTimestamp(t, sWorld->getIntConfig(CONFIG_DAILY_QUEST_RESET_TIME_HOUR), true);
}

void World::ResetDailyQuests()
{
    // reset all saved quest status
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_RESET_CHARACTER_QUESTSTATUS_DAILY);
    CharacterDatabase.Execute(stmt);
    // reset all quest status in memory
    for (SessionMap::const_iterator itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
        if (Player* player = itr->second->GetPlayer())
            player->ResetDailyQuestStatus();

    // reselect pools
    sQuestPoolMgr->ChangeDailyQuests();

    // store next reset time
    time_t now = GameTime::GetGameTime();
    time_t next = GetNextDailyResetTime(now);
    ASSERT(now < next);

    m_NextDailyQuestReset = next;
    sWorld->setWorldState(WS_DAILY_QUEST_RESET_TIME, uint64(next));

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

    // store next reset time
    time_t now = GameTime::GetGameTime();
    time_t next = GetNextWeeklyResetTime(now);
    ASSERT(now < next);

    m_NextWeeklyQuestReset = next;
    sWorld->setWorldState(WS_WEEKLY_QUEST_RESET_TIME, uint64(next));

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
    sWorld->setWorldState(WS_MONTHLY_QUEST_RESET_TIME, uint64(next));

    TC_LOG_INFO("misc", "Monthly quests for all characters have been reset.");
}

void World::CheckQuestResetTimes()
{
    time_t const now = GameTime::GetGameTime();
    if (m_NextDailyQuestReset <= now)
        ResetDailyQuests();
    if (m_NextWeeklyQuestReset <= now)
        ResetWeeklyQuests();
    if (m_NextMonthlyQuestReset <= now)
        ResetMonthlyQuests();
}

void World::InitRandomBGResetTime()
{
    time_t bgtime = uint64(sWorld->getWorldState(WS_BG_DAILY_RESET_TIME));
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
        sWorld->setWorldState(WS_BG_DAILY_RESET_TIME, uint64(m_NextRandomBGReset));
}

void World::InitCalendarOldEventsDeletionTime()
{
    time_t now = GameTime::GetGameTime();
    time_t nextDeletionTime = GetLocalHourTimestamp(now, getIntConfig(CONFIG_CALENDAR_DELETE_OLD_EVENTS_HOUR));
    time_t currentDeletionTime = getWorldState(WS_DAILY_CALENDAR_DELETION_OLD_EVENTS_TIME);

    // If the reset time saved in the worldstate is before now it means the server was offline when the reset was supposed to occur.
    // In this case we set the reset time in the past and next world update will do the reset and schedule next one in the future.
    if (currentDeletionTime < now)
        m_NextCalendarOldEventsDeletionTime = nextDeletionTime - DAY;
    else
        m_NextCalendarOldEventsDeletionTime = nextDeletionTime;

    if (!currentDeletionTime)
        sWorld->setWorldState(WS_DAILY_CALENDAR_DELETION_OLD_EVENTS_TIME, uint64(m_NextCalendarOldEventsDeletionTime));
}

void World::InitGuildResetTime()
{
    time_t gtime = uint64(getWorldState(WS_GUILD_DAILY_RESET_TIME));
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
        sWorld->setWorldState(WS_GUILD_DAILY_RESET_TIME, uint64(m_NextGuildReset));
}

void World::ResetEventSeasonalQuests(uint16 event_id)
{
    TC_LOG_INFO("misc", "Seasonal quests reset for all characters.");

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_RESET_CHARACTER_QUESTSTATUS_SEASONAL_BY_EVENT);
    stmt->setUInt16(0, event_id);
    CharacterDatabase.Execute(stmt);

    for (SessionMap::const_iterator itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
        if (itr->second->GetPlayer())
            itr->second->GetPlayer()->ResetSeasonalQuestStatus(event_id);
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
    sWorld->setWorldState(WS_BG_DAILY_RESET_TIME, uint64(m_NextRandomBGReset));
}

void World::CalendarDeleteOldEvents()
{
    TC_LOG_INFO("misc", "Calendar deletion of old events.");

    m_NextCalendarOldEventsDeletionTime = time_t(m_NextCalendarOldEventsDeletionTime + DAY);
    sWorld->setWorldState(WS_DAILY_CALENDAR_DELETION_OLD_EVENTS_TIME, uint64(m_NextCalendarOldEventsDeletionTime));
    sCalendarMgr->DeleteOldEvents();
}

void World::ResetGuildCap()
{
    TC_LOG_INFO("misc", "Guild Daily Cap reset.");

    m_NextGuildReset = time_t(m_NextGuildReset + DAY);
    sWorld->setWorldState(WS_GUILD_DAILY_RESET_TIME, uint64(m_NextGuildReset));
    sGuildMgr->ResetTimes();
}

void World::UpdateMaxSessionCounters()
{
    m_maxActiveSessionCount = std::max(m_maxActiveSessionCount, uint32(m_sessions.size()-m_QueuedPlayer.size()));
    m_maxQueuedSessionCount = std::max(m_maxQueuedSessionCount, uint32(m_QueuedPlayer.size()));
}

void World::LoadDBVersion()
{
    QueryResult result = WorldDatabase.Query("SELECT db_version, cache_id FROM version LIMIT 1");
    if (result)
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

void World::LoadWorldStates()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = CharacterDatabase.Query("SELECT entry, value FROM worldstates");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 world states. DB table `worldstates` is empty!");

        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();
        m_worldstates[fields[0].GetUInt32()] = fields[1].GetUInt32();
        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u world states in %u ms", count, GetMSTimeDiffToNow(oldMSTime));

}

bool World::IsPvPRealm() const
{
    return (getIntConfig(CONFIG_GAME_TYPE) == REALM_TYPE_PVP || getIntConfig(CONFIG_GAME_TYPE) == REALM_TYPE_RPPVP || getIntConfig(CONFIG_GAME_TYPE) == REALM_TYPE_FFA_PVP);
}

bool World::IsFFAPvPRealm() const
{
    return getIntConfig(CONFIG_GAME_TYPE) == REALM_TYPE_FFA_PVP;
}

// Setting a worldstate will save it to DB
void World::setWorldState(uint32 index, uint64 value)
{
    WorldStatesMap::const_iterator it = m_worldstates.find(index);
    if (it != m_worldstates.end())
    {
        if (it->second == value)
            return;

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_WORLDSTATE);

        stmt->setUInt32(0, uint32(value));
        stmt->setUInt32(1, index);

        CharacterDatabase.Execute(stmt);
    }
    else
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_WORLDSTATE);

        stmt->setUInt32(0, index);
        stmt->setUInt32(1, uint32(value));

        CharacterDatabase.Execute(stmt);
    }
    m_worldstates[index] = value;
}

uint64 World::getWorldState(uint32 index) const
{
    WorldStatesMap::const_iterator it = m_worldstates.find(index);
    return it != m_worldstates.end() ? it->second : 0;
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

Realm realm;

CliCommandHolder::CliCommandHolder(void* callbackArg, char const* command, Print zprint, CommandFinished commandFinished)
    : m_callbackArg(callbackArg), m_command(strdup(command)), m_print(zprint), m_commandFinished(commandFinished)
{
}

CliCommandHolder::~CliCommandHolder()
{
    free(m_command);
}
