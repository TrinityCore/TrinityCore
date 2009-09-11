/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/** \file
    \ingroup world
*/

#include "Common.h"
#include "Database/DatabaseEnv.h"
#include "Config/ConfigEnv.h"
#include "SystemConfig.h"
#include "Log.h"
#include "Opcodes.h"
#include "WorldSession.h"
#include "WorldPacket.h"
#include "Weather.h"
#include "Player.h"
#include "Vehicle.h"
#include "SkillExtraItems.h"
#include "SkillDiscovery.h"
#include "World.h"
#include "AccountMgr.h"
#include "AchievementMgr.h"
#include "AuctionHouseMgr.h"
#include "ObjectMgr.h"
#include "CreatureEventAIMgr.h"
#include "SpellMgr.h"
#include "Chat.h"
#include "DBCStores.h"
#include "LootMgr.h"
#include "ItemEnchantmentMgr.h"
#include "MapManager.h"
#include "ScriptCalls.h"
#include "CreatureAIRegistry.h"
#include "Policies/SingletonImp.h"
#include "BattleGroundMgr.h"
#include "OutdoorPvPMgr.h"
#include "TemporarySummon.h"
#include "AuctionHouseBot.h"
#include "WaypointMovementGenerator.h"
#include "VMapFactory.h"
#include "GlobalEvents.h"
#include "GameEventMgr.h"
#include "PoolHandler.h"
#include "Database/DatabaseImpl.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"
#include "InstanceSaveMgr.h"
#include "Util.h"
#include "Language.h"
#include "CreatureGroups.h"
#include "Transports.h"
#include "ProgressBar.h"

INSTANTIATE_SINGLETON_1( World );

volatile bool World::m_stopEvent = false;
uint8 World::m_ExitCode = SHUTDOWN_EXIT_CODE;
volatile uint32 World::m_worldLoopCounter = 0;

float World::m_MaxVisibleDistance             = DEFAULT_VISIBILITY_DISTANCE;
float World::m_MaxVisibleDistanceForCreature  = DEFAULT_VISIBILITY_DISTANCE;
float World::m_MaxVisibleDistanceForPlayer    = DEFAULT_VISIBILITY_DISTANCE;
float World::m_MaxVisibleDistanceForObject    = DEFAULT_VISIBILITY_DISTANCE;
float World::m_MaxVisibleDistanceInFlight     = DEFAULT_VISIBILITY_DISTANCE;
float World::m_VisibleUnitGreyDistance        = 0;
float World::m_VisibleObjectGreyDistance      = 0;

/// World constructor
World::World()
{
    m_playerLimit = 0;
    m_allowedSecurityLevel = SEC_PLAYER;
    m_allowMovement = true;
    m_ShutdownMask = 0;
    m_ShutdownTimer = 0;
    m_gameTime=time(NULL);
    m_startTime=m_gameTime;
    m_maxActiveSessionCount = 0;
    m_maxQueuedSessionCount = 0;
    m_PlayerCount = 0;
    m_MaxPlayerCount = 0;
    m_resultQueue = NULL;
    m_NextDailyQuestReset = 0;
    m_scheduledScripts = 0;

    m_defaultDbcLocale = LOCALE_enUS;
    m_availableDbcLocaleMask = 0;

    m_updateTimeSum = 0;
    m_updateTimeCount = 0;

    m_isClosed = false;
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

    ///- Empty the WeatherMap
    for (WeatherMap::const_iterator itr = m_weathers.begin(); itr != m_weathers.end(); ++itr)
        delete itr->second;

    m_weathers.clear();

    while (!cliCmdQueue.empty())
        delete cliCmdQueue.next();

    VMAP::VMapFactory::clear();

    if(m_resultQueue) delete m_resultQueue;

    //TODO free addSessQueue
}

/// Find a player in a specified zone
Player* World::FindPlayerInZone(uint32 zone)
{
    ///- circle through active sessions and return the first player found in the zone
    SessionMap::const_iterator itr;
    for (itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
    {
        if(!itr->second)
            continue;
        Player *player = itr->second->GetPlayer();
        if(!player)
            continue;
        if( player->IsInWorld() && player->GetZoneId() == zone )
        {
            // Used by the weather system. We return the player to broadcast the change weather message to him and all players in the zone.
            return player;
        }
    }
    return NULL;
}

/// Find a session by its id
WorldSession* World::FindSession(uint32 id) const
{
    SessionMap::const_iterator itr = m_sessions.find(id);

    if(itr != m_sessions.end())
        return itr->second;                                 // also can return NULL for kicked session
    else
        return NULL;
}

/// Remove a given session
bool World::RemoveSession(uint32 id)
{
    ///- Find the session, kick the user, but we can't delete session at this moment to prevent iterator invalidation
    SessionMap::const_iterator itr = m_sessions.find(id);

    if(itr != m_sessions.end() && itr->second)
    {
        if (itr->second->PlayerLoading())
            return false;
        itr->second->KickPlayer();
    }

    return true;
}

void World::AddSession(WorldSession* s)
{
    addSessQueue.add(s);
}

void
World::AddSession_ (WorldSession* s)
{
    ASSERT (s);

    //NOTE - Still there is race condition in WorldSession* being used in the Sockets

    ///- kick already loaded player with same account (if any) and remove session
    ///- if player is in loading and want to load again, return
    if (!RemoveSession (s->GetAccountId ()))
    {
        s->KickPlayer ();
        delete s;                                           // session not added yet in session list, so not listed in queue
        return;
    }

    // decrease session counts only at not reconnection case
    bool decrease_session = true;

    // if session already exist, prepare to it deleting at next world update
    // NOTE - KickPlayer() should be called on "old" in RemoveSession()
    {
        SessionMap::const_iterator old = m_sessions.find(s->GetAccountId ());

        if(old != m_sessions.end())
        {
            // prevent decrease sessions count if session queued
            if(RemoveQueuedPlayer(old->second))
                decrease_session = false;
            // not remove replaced session form queue if listed
            delete old->second;
        }
    }

    m_sessions[s->GetAccountId ()] = s;

    uint32 Sessions = GetActiveAndQueuedSessionCount ();
    uint32 pLimit = GetPlayerAmountLimit ();
    uint32 QueueSize = GetQueueSize ();                     //number of players in the queue

    //so we don't count the user trying to
    //login as a session and queue the socket that we are using
    if(decrease_session)
        --Sessions;

    if (pLimit > 0 && Sessions >= pLimit && s->GetSecurity () == SEC_PLAYER && !HasRecentlyDisconnected(s) )
    {
        AddQueuedPlayer (s);
        UpdateMaxSessionCounters ();
        sLog.outDetail ("PlayerQueue: Account id %u is in Queue Position (%u).", s->GetAccountId (), ++QueueSize);
        return;
    }

    WorldPacket packet(SMSG_AUTH_RESPONSE, 1 + 4 + 1 + 4 + 1);
    packet << uint8 (AUTH_OK);
    packet << uint32 (0);                                   // BillingTimeRemaining
    packet << uint8 (0);                                    // BillingPlanFlags
    packet << uint32 (0);                                   // BillingTimeRested
    packet << uint8 (s->Expansion());                       // 0 - normal, 1 - TBC, must be set in database manually for each account
    s->SendPacket (&packet);

    s->SendAddonsInfo();

    WorldPacket pkt(SMSG_CLIENTCACHE_VERSION, 4);
    pkt << uint32(sWorld.getConfig(CONFIG_CLIENTCACHE_VERSION));
    s->SendPacket(&pkt);

    s->SendTutorialsData();

    UpdateMaxSessionCounters ();

    // Updates the population
    if (pLimit > 0)
    {
        float popu = GetActiveSessionCount ();              // updated number of users on the server
        popu /= pLimit;
        popu *= 2;
        loginDatabase.PExecute ("UPDATE realmlist SET population = '%f' WHERE id = '%d'", popu, realmID);
        sLog.outDetail ("Server Population (%f).", popu);
    }
}

bool World::HasRecentlyDisconnected(WorldSession* session)
{
    if(!session) return false;

    if(uint32 tolerance = getConfig(CONFIG_INTERVAL_DISCONNECT_TOLERANCE))
    {
        for(DisconnectMap::iterator i = m_disconnects.begin(); i != m_disconnects.end(); )
        {
            if(difftime(i->second, time(NULL)) < tolerance)
            {
                if(i->first == session->GetAccountId())
                    return true;
                ++i;
            }
            else
                m_disconnects.erase(i);
        }
    }
    return false;
 }

int32 World::GetQueuePos(WorldSession* sess)
{
    uint32 position = 1;

    for(Queue::const_iterator iter = m_QueuedPlayer.begin(); iter != m_QueuedPlayer.end(); ++iter, ++position)
        if((*iter) == sess)
            return position;

    return 0;
}

void World::AddQueuedPlayer(WorldSession* sess)
{
    sess->SetInQueue(true);
    m_QueuedPlayer.push_back (sess);

    // The 1st SMSG_AUTH_RESPONSE needs to contain other info too.
    WorldPacket packet (SMSG_AUTH_RESPONSE, 1 + 4 + 1 + 4 + 1);
    packet << uint8 (AUTH_WAIT_QUEUE);
    packet << uint32 (0);                                   // BillingTimeRemaining
    packet << uint8 (0);                                    // BillingPlanFlags
    packet << uint32 (0);                                   // BillingTimeRested
    packet << uint8 (sess->Expansion () ? 1 : 0);                    // 0 - normal, 1 - TBC, must be set in database manually for each account
    packet << uint32(GetQueuePos (sess));
    sess->SendPacket (&packet);

    //sess->SendAuthWaitQue (GetQueuePos (sess));
}

bool World::RemoveQueuedPlayer(WorldSession* sess)
{
    // sessions count including queued to remove (if removed_session set)
    uint32 sessions = GetActiveSessionCount();

    uint32 position = 1;
    Queue::iterator iter = m_QueuedPlayer.begin();

    // search to remove and count skipped positions
    bool found = false;

    for(;iter != m_QueuedPlayer.end(); ++iter, ++position)
    {
        if(*iter==sess)
        {
            sess->SetInQueue(false);
            iter = m_QueuedPlayer.erase(iter);
            found = true;                                   // removing queued session
            break;
        }
    }

    // iter point to next socked after removed or end()
    // position store position of removed socket and then new position next socket after removed

    // if session not queued then we need decrease sessions count
    if(!found && sessions)
        --sessions;

    // accept first in queue
    if( (!m_playerLimit || sessions < m_playerLimit) && !m_QueuedPlayer.empty() )
    {
        WorldSession* pop_sess = m_QueuedPlayer.front();
        pop_sess->SetInQueue(false);
        pop_sess->SendAuthWaitQue(0);
        m_QueuedPlayer.pop_front();

        // update iter to point first queued socket or end() if queue is empty now
        iter = m_QueuedPlayer.begin();
        position = 1;
    }

    // update position from iter to end()
    // iter point to first not updated socket, position store new position
    for(; iter != m_QueuedPlayer.end(); ++iter, ++position)
        (*iter)->SendAuthWaitQue(position);

    return found;
}

/// Find a Weather object by the given zoneid
Weather* World::FindWeather(uint32 id) const
{
    WeatherMap::const_iterator itr = m_weathers.find(id);

    if(itr != m_weathers.end())
        return itr->second;
    else
        return 0;
}

/// Remove a Weather object for the given zoneid
void World::RemoveWeather(uint32 id)
{
    // not called at the moment. Kept for completeness
    WeatherMap::iterator itr = m_weathers.find(id);

    if(itr != m_weathers.end())
    {
        delete itr->second;
        m_weathers.erase(itr);
    }
}

/// Add a Weather object to the list
Weather* World::AddWeather(uint32 zone_id)
{
    WeatherZoneChances const* weatherChances = objmgr.GetWeatherChances(zone_id);

    // zone not have weather, ignore
    if(!weatherChances)
        return NULL;

    Weather* w = new Weather(zone_id,weatherChances);
    m_weathers[w->GetZone()] = w;
    w->ReGenerate();
    w->UpdateWeather();
    return w;
}

/// Initialize config values
void World::LoadConfigSettings(bool reload)
{
    if(reload)
    {
        if(!sConfig.Reload())
        {
            sLog.outError("World settings reload fail: can't read settings from %s.",sConfig.GetFilename().c_str());
            return;
        }
        //TODO Check if config is outdated
    }

    ///- Read the player limit and the Message of the day from the config file
    SetPlayerLimit( sConfig.GetIntDefault("PlayerLimit", DEFAULT_PLAYER_LIMIT), true );
    SetMotd( sConfig.GetStringDefault("Motd", "Welcome to a Trinity Core Server." ) );

    ///- Get string for new logins (newly created characters)
    SetNewCharString(sConfig.GetStringDefault("PlayerStart.String", ""));

    ///- Send server info on login?
    m_configs[CONFIG_ENABLE_SINFO_LOGIN] = sConfig.GetIntDefault("Server.LoginInfo", 0);

    ///- Read all rates from the config file
    rate_values[RATE_HEALTH]      = sConfig.GetFloatDefault("Rate.Health", 1);
    if(rate_values[RATE_HEALTH] < 0)
    {
        sLog.outError("Rate.Health (%f) must be > 0. Using 1 instead.",rate_values[RATE_HEALTH]);
        rate_values[RATE_HEALTH] = 1;
    }
    rate_values[RATE_POWER_MANA]  = sConfig.GetFloatDefault("Rate.Mana", 1);
    if(rate_values[RATE_POWER_MANA] < 0)
    {
        sLog.outError("Rate.Mana (%f) must be > 0. Using 1 instead.",rate_values[RATE_POWER_MANA]);
        rate_values[RATE_POWER_MANA] = 1;
    }
    rate_values[RATE_POWER_RAGE_INCOME] = sConfig.GetFloatDefault("Rate.Rage.Income", 1);
    rate_values[RATE_POWER_RAGE_LOSS]   = sConfig.GetFloatDefault("Rate.Rage.Loss", 1);
    if(rate_values[RATE_POWER_RAGE_LOSS] < 0)
    {
        sLog.outError("Rate.Rage.Loss (%f) must be > 0. Using 1 instead.",rate_values[RATE_POWER_RAGE_LOSS]);
        rate_values[RATE_POWER_RAGE_LOSS] = 1;
    }
    rate_values[RATE_POWER_RUNICPOWER_INCOME] = sConfig.GetFloatDefault("Rate.RunicPower.Income", 1);
    rate_values[RATE_POWER_RUNICPOWER_LOSS]   = sConfig.GetFloatDefault("Rate.RunicPower.Loss", 1);
    if(rate_values[RATE_POWER_RUNICPOWER_LOSS] < 0)
    {
        sLog.outError("Rate.RunicPower.Loss (%f) must be > 0. Using 1 instead.",rate_values[RATE_POWER_RUNICPOWER_LOSS]);
        rate_values[RATE_POWER_RUNICPOWER_LOSS] = 1;
    }
    rate_values[RATE_POWER_FOCUS] = sConfig.GetFloatDefault("Rate.Focus", 1.0f);
    rate_values[RATE_SKILL_DISCOVERY] = sConfig.GetFloatDefault("Rate.Skill.Discovery", 1.0f);
    rate_values[RATE_DROP_ITEM_POOR]       = sConfig.GetFloatDefault("Rate.Drop.Item.Poor", 1.0f);
    rate_values[RATE_DROP_ITEM_NORMAL]     = sConfig.GetFloatDefault("Rate.Drop.Item.Normal", 1.0f);
    rate_values[RATE_DROP_ITEM_UNCOMMON]   = sConfig.GetFloatDefault("Rate.Drop.Item.Uncommon", 1.0f);
    rate_values[RATE_DROP_ITEM_RARE]       = sConfig.GetFloatDefault("Rate.Drop.Item.Rare", 1.0f);
    rate_values[RATE_DROP_ITEM_EPIC]       = sConfig.GetFloatDefault("Rate.Drop.Item.Epic", 1.0f);
    rate_values[RATE_DROP_ITEM_LEGENDARY]  = sConfig.GetFloatDefault("Rate.Drop.Item.Legendary", 1.0f);
    rate_values[RATE_DROP_ITEM_ARTIFACT]   = sConfig.GetFloatDefault("Rate.Drop.Item.Artifact", 1.0f);
    rate_values[RATE_DROP_ITEM_REFERENCED] = sConfig.GetFloatDefault("Rate.Drop.Item.Referenced", 1.0f);
    rate_values[RATE_DROP_MONEY]  = sConfig.GetFloatDefault("Rate.Drop.Money", 1.0f);
    rate_values[RATE_XP_KILL]     = sConfig.GetFloatDefault("Rate.XP.Kill", 1.0f);
    rate_values[RATE_XP_QUEST]    = sConfig.GetFloatDefault("Rate.XP.Quest", 1.0f);
    rate_values[RATE_XP_EXPLORE]  = sConfig.GetFloatDefault("Rate.XP.Explore", 1.0f);
    rate_values[RATE_REPAIRCOST]  = sConfig.GetFloatDefault("Rate.RepairCost", 1.0f);
    if(rate_values[RATE_REPAIRCOST] < 0.0f)
    {
        sLog.outError("Rate.RepairCost (%f) must be >=0. Using 0.0 instead.",rate_values[RATE_REPAIRCOST]);
        rate_values[RATE_REPAIRCOST] = 0.0f;
    }
    rate_values[RATE_REPUTATION_GAIN]  = sConfig.GetFloatDefault("Rate.Reputation.Gain", 1.0f);
    rate_values[RATE_REPUTATION_LOWLEVEL_KILL]  = sConfig.GetFloatDefault("Rate.Reputation.LowLevel.Kill", 1.0f);
    rate_values[RATE_REPUTATION_LOWLEVEL_QUEST]  = sConfig.GetFloatDefault("Rate.Reputation.LowLevel.Quest", 1.0f);
    rate_values[RATE_CREATURE_NORMAL_DAMAGE]          = sConfig.GetFloatDefault("Rate.Creature.Normal.Damage", 1.0f);
    rate_values[RATE_CREATURE_ELITE_ELITE_DAMAGE]     = sConfig.GetFloatDefault("Rate.Creature.Elite.Elite.Damage", 1.0f);
    rate_values[RATE_CREATURE_ELITE_RAREELITE_DAMAGE] = sConfig.GetFloatDefault("Rate.Creature.Elite.RAREELITE.Damage", 1.0f);
    rate_values[RATE_CREATURE_ELITE_WORLDBOSS_DAMAGE] = sConfig.GetFloatDefault("Rate.Creature.Elite.WORLDBOSS.Damage", 1.0f);
    rate_values[RATE_CREATURE_ELITE_RARE_DAMAGE]      = sConfig.GetFloatDefault("Rate.Creature.Elite.RARE.Damage", 1.0f);
    rate_values[RATE_CREATURE_NORMAL_HP]          = sConfig.GetFloatDefault("Rate.Creature.Normal.HP", 1.0f);
    rate_values[RATE_CREATURE_ELITE_ELITE_HP]     = sConfig.GetFloatDefault("Rate.Creature.Elite.Elite.HP", 1.0f);
    rate_values[RATE_CREATURE_ELITE_RAREELITE_HP] = sConfig.GetFloatDefault("Rate.Creature.Elite.RAREELITE.HP", 1.0f);
    rate_values[RATE_CREATURE_ELITE_WORLDBOSS_HP] = sConfig.GetFloatDefault("Rate.Creature.Elite.WORLDBOSS.HP", 1.0f);
    rate_values[RATE_CREATURE_ELITE_RARE_HP]      = sConfig.GetFloatDefault("Rate.Creature.Elite.RARE.HP", 1.0f);
    rate_values[RATE_CREATURE_NORMAL_SPELLDAMAGE]          = sConfig.GetFloatDefault("Rate.Creature.Normal.SpellDamage", 1.0f);
    rate_values[RATE_CREATURE_ELITE_ELITE_SPELLDAMAGE]     = sConfig.GetFloatDefault("Rate.Creature.Elite.Elite.SpellDamage", 1.0f);
    rate_values[RATE_CREATURE_ELITE_RAREELITE_SPELLDAMAGE] = sConfig.GetFloatDefault("Rate.Creature.Elite.RAREELITE.SpellDamage", 1.0f);
    rate_values[RATE_CREATURE_ELITE_WORLDBOSS_SPELLDAMAGE] = sConfig.GetFloatDefault("Rate.Creature.Elite.WORLDBOSS.SpellDamage", 1.0f);
    rate_values[RATE_CREATURE_ELITE_RARE_SPELLDAMAGE]      = sConfig.GetFloatDefault("Rate.Creature.Elite.RARE.SpellDamage", 1.0f);
    rate_values[RATE_CREATURE_AGGRO]  = sConfig.GetFloatDefault("Rate.Creature.Aggro", 1.0f);
    rate_values[RATE_REST_INGAME]                    = sConfig.GetFloatDefault("Rate.Rest.InGame", 1.0f);
    rate_values[RATE_REST_OFFLINE_IN_TAVERN_OR_CITY] = sConfig.GetFloatDefault("Rate.Rest.Offline.InTavernOrCity", 1.0f);
    rate_values[RATE_REST_OFFLINE_IN_WILDERNESS]     = sConfig.GetFloatDefault("Rate.Rest.Offline.InWilderness", 1.0f);
    rate_values[RATE_DAMAGE_FALL]  = sConfig.GetFloatDefault("Rate.Damage.Fall", 1.0f);
    rate_values[RATE_AUCTION_TIME]  = sConfig.GetFloatDefault("Rate.Auction.Time", 1.0f);
    rate_values[RATE_AUCTION_DEPOSIT] = sConfig.GetFloatDefault("Rate.Auction.Deposit", 1.0f);
    rate_values[RATE_AUCTION_CUT] = sConfig.GetFloatDefault("Rate.Auction.Cut", 1.0f);
    rate_values[RATE_HONOR] = sConfig.GetFloatDefault("Rate.Honor",1.0f);
    rate_values[RATE_MINING_AMOUNT] = sConfig.GetFloatDefault("Rate.Mining.Amount",1.0f);
    rate_values[RATE_MINING_NEXT]   = sConfig.GetFloatDefault("Rate.Mining.Next",1.0f);
    rate_values[RATE_INSTANCE_RESET_TIME] = sConfig.GetFloatDefault("Rate.InstanceResetTime",1.0f);
    rate_values[RATE_TALENT] = sConfig.GetFloatDefault("Rate.Talent",1.0f);
    if(rate_values[RATE_TALENT] < 0.0f)
    {
        sLog.outError("Rate.Talent (%f) must be > 0. Using 1 instead.",rate_values[RATE_TALENT]);
        rate_values[RATE_TALENT] = 1.0f;
    }
    rate_values[RATE_MOVESPEED] = sConfig.GetFloatDefault("Rate.MoveSpeed",1.0f);
    if(rate_values[RATE_MOVESPEED] < 0)
    {
        sLog.outError("Rate.MoveSpeed (%f) must be > 0. Using 1 instead.",rate_values[RATE_MOVESPEED]);
        rate_values[RATE_MOVESPEED] = 1.0f;
    }
    for(uint8 i = 0; i < MAX_MOVE_TYPE; ++i) playerBaseMoveSpeed[i] = baseMoveSpeed[i] * rate_values[RATE_MOVESPEED];
    rate_values[RATE_CORPSE_DECAY_LOOTED] = sConfig.GetFloatDefault("Rate.Corpse.Decay.Looted",0.5f);

    rate_values[RATE_TARGET_POS_RECALCULATION_RANGE] = sConfig.GetFloatDefault("TargetPosRecalculateRange",1.5f);
    if(rate_values[RATE_TARGET_POS_RECALCULATION_RANGE] < CONTACT_DISTANCE)
    {
        sLog.outError("TargetPosRecalculateRange (%f) must be >= %f. Using %f instead.",rate_values[RATE_TARGET_POS_RECALCULATION_RANGE],CONTACT_DISTANCE,CONTACT_DISTANCE);
        rate_values[RATE_TARGET_POS_RECALCULATION_RANGE] = CONTACT_DISTANCE;
    }
    else if(rate_values[RATE_TARGET_POS_RECALCULATION_RANGE] > NOMINAL_MELEE_RANGE)
    {
        sLog.outError("TargetPosRecalculateRange (%f) must be <= %f. Using %f instead.",
            rate_values[RATE_TARGET_POS_RECALCULATION_RANGE],NOMINAL_MELEE_RANGE,NOMINAL_MELEE_RANGE);
        rate_values[RATE_TARGET_POS_RECALCULATION_RANGE] = NOMINAL_MELEE_RANGE;
    }

    rate_values[RATE_DURABILITY_LOSS_ON_DEATH]  = sConfig.GetFloatDefault("DurabilityLoss.OnDeath", 10.0f);
    if(rate_values[RATE_DURABILITY_LOSS_ON_DEATH] < 0.0f)
    {
        sLog.outError("DurabilityLoss.OnDeath (%f) must be >=0. Using 0.0 instead.",rate_values[RATE_DURABILITY_LOSS_ON_DEATH]);
        rate_values[RATE_DURABILITY_LOSS_ON_DEATH] = 0.0f;
    }
    if(rate_values[RATE_DURABILITY_LOSS_ON_DEATH] > 100.0f)
    {
        sLog.outError("DurabilityLoss.OnDeath (%f) must be <=100. Using 100.0 instead.",rate_values[RATE_DURABILITY_LOSS_ON_DEATH]);
        rate_values[RATE_DURABILITY_LOSS_ON_DEATH] = 0.0f;
    }
    rate_values[RATE_DURABILITY_LOSS_ON_DEATH] = rate_values[RATE_DURABILITY_LOSS_ON_DEATH] / 100.0f;

    rate_values[RATE_DURABILITY_LOSS_DAMAGE] = sConfig.GetFloatDefault("DurabilityLossChance.Damage",0.5f);
    if(rate_values[RATE_DURABILITY_LOSS_DAMAGE] < 0.0f)
    {
        sLog.outError("DurabilityLossChance.Damage (%f) must be >=0. Using 0.0 instead.",rate_values[RATE_DURABILITY_LOSS_DAMAGE]);
        rate_values[RATE_DURABILITY_LOSS_DAMAGE] = 0.0f;
    }
    rate_values[RATE_DURABILITY_LOSS_ABSORB] = sConfig.GetFloatDefault("DurabilityLossChance.Absorb",0.5f);
    if(rate_values[RATE_DURABILITY_LOSS_ABSORB] < 0.0f)
    {
        sLog.outError("DurabilityLossChance.Absorb (%f) must be >=0. Using 0.0 instead.",rate_values[RATE_DURABILITY_LOSS_ABSORB]);
        rate_values[RATE_DURABILITY_LOSS_ABSORB] = 0.0f;
    }
    rate_values[RATE_DURABILITY_LOSS_PARRY] = sConfig.GetFloatDefault("DurabilityLossChance.Parry",0.05f);
    if(rate_values[RATE_DURABILITY_LOSS_PARRY] < 0.0f)
    {
        sLog.outError("DurabilityLossChance.Parry (%f) must be >=0. Using 0.0 instead.",rate_values[RATE_DURABILITY_LOSS_PARRY]);
        rate_values[RATE_DURABILITY_LOSS_PARRY] = 0.0f;
    }
    rate_values[RATE_DURABILITY_LOSS_BLOCK] = sConfig.GetFloatDefault("DurabilityLossChance.Block",0.05f);
    if(rate_values[RATE_DURABILITY_LOSS_BLOCK] < 0.0f)
    {
        sLog.outError("DurabilityLossChance.Block (%f) must be >=0. Using 0.0 instead.",rate_values[RATE_DURABILITY_LOSS_BLOCK]);
        rate_values[RATE_DURABILITY_LOSS_BLOCK] = 0.0f;
    }

    ///- Read other configuration items from the config file

    m_configs[CONFIG_DURABILITY_LOSS_IN_PVP] = sConfig.GetBoolDefault("DurabilityLoss.InPvP", false);

    m_configs[CONFIG_COMPRESSION] = sConfig.GetIntDefault("Compression", 1);
    if(m_configs[CONFIG_COMPRESSION] < 1 || m_configs[CONFIG_COMPRESSION] > 9)
    {
        sLog.outError("Compression level (%i) must be in range 1..9. Using default compression level (1).",m_configs[CONFIG_COMPRESSION]);
        m_configs[CONFIG_COMPRESSION] = 1;
    }
    m_configs[CONFIG_ADDON_CHANNEL] = sConfig.GetBoolDefault("AddonChannel", true);
    m_configs[CONFIG_GRID_UNLOAD] = sConfig.GetBoolDefault("GridUnload", true);
    m_configs[CONFIG_INTERVAL_SAVE] = sConfig.GetIntDefault("PlayerSaveInterval", 15 * MINUTE * IN_MILISECONDS);
    m_configs[CONFIG_INTERVAL_DISCONNECT_TOLERANCE] = sConfig.GetIntDefault("DisconnectToleranceInterval", 0);

    m_configs[CONFIG_INTERVAL_GRIDCLEAN] = sConfig.GetIntDefault("GridCleanUpDelay", 5 * MINUTE * IN_MILISECONDS);
    if(m_configs[CONFIG_INTERVAL_GRIDCLEAN] < MIN_GRID_DELAY)
    {
        sLog.outError("GridCleanUpDelay (%i) must be greater %u. Use this minimal value.",m_configs[CONFIG_INTERVAL_GRIDCLEAN],MIN_GRID_DELAY);
        m_configs[CONFIG_INTERVAL_GRIDCLEAN] = MIN_GRID_DELAY;
    }
    if(reload)
        MapManager::Instance().SetGridCleanUpDelay(m_configs[CONFIG_INTERVAL_GRIDCLEAN]);

    m_configs[CONFIG_INTERVAL_MAPUPDATE] = sConfig.GetIntDefault("MapUpdateInterval", 100);
    if(m_configs[CONFIG_INTERVAL_MAPUPDATE] < MIN_MAP_UPDATE_DELAY)
    {
        sLog.outError("MapUpdateInterval (%i) must be greater %u. Use this minimal value.",m_configs[CONFIG_INTERVAL_MAPUPDATE],MIN_MAP_UPDATE_DELAY);
        m_configs[CONFIG_INTERVAL_MAPUPDATE] = MIN_MAP_UPDATE_DELAY;
    }
    if(reload)
        MapManager::Instance().SetMapUpdateInterval(m_configs[CONFIG_INTERVAL_MAPUPDATE]);

    m_configs[CONFIG_INTERVAL_CHANGEWEATHER] = sConfig.GetIntDefault("ChangeWeatherInterval", 10 * MINUTE * IN_MILISECONDS);

    if(reload)
    {
        uint32 val = sConfig.GetIntDefault("WorldServerPort", DEFAULT_WORLDSERVER_PORT);
        if(val!=m_configs[CONFIG_PORT_WORLD])
            sLog.outError("WorldServerPort option can't be changed at Trinityd.conf reload, using current value (%u).",m_configs[CONFIG_PORT_WORLD]);
    }
    else
        m_configs[CONFIG_PORT_WORLD] = sConfig.GetIntDefault("WorldServerPort", DEFAULT_WORLDSERVER_PORT);

    if(reload)
    {
        uint32 val = sConfig.GetIntDefault("SocketSelectTime", DEFAULT_SOCKET_SELECT_TIME);
        if(val!=m_configs[CONFIG_SOCKET_SELECTTIME])
            sLog.outError("SocketSelectTime option can't be changed at Trinityd.conf reload, using current value (%u).",m_configs[CONFIG_SOCKET_SELECTTIME]);
    }
    else
        m_configs[CONFIG_SOCKET_SELECTTIME] = sConfig.GetIntDefault("SocketSelectTime", DEFAULT_SOCKET_SELECT_TIME);

    m_configs[CONFIG_GROUP_XP_DISTANCE] = sConfig.GetIntDefault("MaxGroupXPDistance", 74);
    /// \todo Add MonsterSight and GuarderSight (with meaning) in Trinityd.conf or put them as define
    m_configs[CONFIG_SIGHT_MONSTER] = sConfig.GetIntDefault("MonsterSight", 50);
    m_configs[CONFIG_SIGHT_GUARDER] = sConfig.GetIntDefault("GuarderSight", 50);

    if(reload)
    {
        uint32 val = sConfig.GetIntDefault("GameType", 0);
        if(val!=m_configs[CONFIG_GAME_TYPE])
            sLog.outError("GameType option can't be changed at Trinityd.conf reload, using current value (%u).",m_configs[CONFIG_GAME_TYPE]);
    }
    else
        m_configs[CONFIG_GAME_TYPE] = sConfig.GetIntDefault("GameType", 0);

    if(reload)
    {
        uint32 val = sConfig.GetIntDefault("RealmZone", REALM_ZONE_DEVELOPMENT);
        if(val!=m_configs[CONFIG_REALM_ZONE])
            sLog.outError("RealmZone option can't be changed at Trinityd.conf reload, using current value (%u).",m_configs[CONFIG_REALM_ZONE]);
    }
    else
        m_configs[CONFIG_REALM_ZONE] = sConfig.GetIntDefault("RealmZone", REALM_ZONE_DEVELOPMENT);

    m_configs[CONFIG_ALLOW_TWO_SIDE_ACCOUNTS]            = sConfig.GetBoolDefault("AllowTwoSide.Accounts", false);
    m_configs[CONFIG_ALLOW_TWO_SIDE_INTERACTION_CHAT]    = sConfig.GetBoolDefault("AllowTwoSide.Interaction.Chat",false);
    m_configs[CONFIG_ALLOW_TWO_SIDE_INTERACTION_CHANNEL] = sConfig.GetBoolDefault("AllowTwoSide.Interaction.Channel",false);
    m_configs[CONFIG_ALLOW_TWO_SIDE_INTERACTION_GROUP]   = sConfig.GetBoolDefault("AllowTwoSide.Interaction.Group",false);
    m_configs[CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD]   = sConfig.GetBoolDefault("AllowTwoSide.Interaction.Guild",false);
    m_configs[CONFIG_ALLOW_TWO_SIDE_INTERACTION_AUCTION] = sConfig.GetBoolDefault("AllowTwoSide.Interaction.Auction",false);
    m_configs[CONFIG_ALLOW_TWO_SIDE_INTERACTION_MAIL]    = sConfig.GetBoolDefault("AllowTwoSide.Interaction.Mail",false);
    m_configs[CONFIG_ALLOW_TWO_SIDE_WHO_LIST]            = sConfig.GetBoolDefault("AllowTwoSide.WhoList", false);
    m_configs[CONFIG_ALLOW_TWO_SIDE_ADD_FRIEND]          = sConfig.GetBoolDefault("AllowTwoSide.AddFriend", false);
    m_configs[CONFIG_ALLOW_TWO_SIDE_TRADE]               = sConfig.GetBoolDefault("AllowTwoSide.trade", false);
    m_configs[CONFIG_STRICT_PLAYER_NAMES]                = sConfig.GetIntDefault ("StrictPlayerNames",  0);
    m_configs[CONFIG_STRICT_CHARTER_NAMES]               = sConfig.GetIntDefault ("StrictCharterNames", 0);
    m_configs[CONFIG_STRICT_PET_NAMES]                   = sConfig.GetIntDefault ("StrictPetNames",     0);

    m_configs[CONFIG_MIN_PLAYER_NAME]                    = sConfig.GetIntDefault ("MinPlayerName",  2);
    if(m_configs[CONFIG_MIN_PLAYER_NAME] < 1 || m_configs[CONFIG_MIN_PLAYER_NAME] > MAX_PLAYER_NAME)
    {
        sLog.outError("MinPlayerName (%i) must be in range 1..%u. Set to 2.",m_configs[CONFIG_MIN_PLAYER_NAME],MAX_PLAYER_NAME);
        m_configs[CONFIG_MIN_PLAYER_NAME] = 2;
    }

    m_configs[CONFIG_MIN_CHARTER_NAME]                   = sConfig.GetIntDefault ("MinCharterName", 2);
    if(m_configs[CONFIG_MIN_CHARTER_NAME] < 1 || m_configs[CONFIG_MIN_CHARTER_NAME] > MAX_CHARTER_NAME)
    {
        sLog.outError("MinCharterName (%i) must be in range 1..%u. Set to 2.",m_configs[CONFIG_MIN_CHARTER_NAME],MAX_CHARTER_NAME);
        m_configs[CONFIG_MIN_CHARTER_NAME] = 2;
    }

    m_configs[CONFIG_MIN_PET_NAME]                       = sConfig.GetIntDefault ("MinPetName",     2);
    if(m_configs[CONFIG_MIN_PET_NAME] < 1 || m_configs[CONFIG_MIN_PET_NAME] > MAX_PET_NAME)
    {
        sLog.outError("MinPetName (%i) must be in range 1..%u. Set to 2.",m_configs[CONFIG_MIN_PET_NAME],MAX_PET_NAME);
        m_configs[CONFIG_MIN_PET_NAME] = 2;
    }

    m_configs[CONFIG_CHARACTERS_CREATING_DISABLED]       = sConfig.GetIntDefault ("CharactersCreatingDisabled", 0);

    m_configs[CONFIG_CHARACTERS_PER_REALM] = sConfig.GetIntDefault("CharactersPerRealm", 10);
    if(m_configs[CONFIG_CHARACTERS_PER_REALM] < 1 || m_configs[CONFIG_CHARACTERS_PER_REALM] > 10)
    {
        sLog.outError("CharactersPerRealm (%i) must be in range 1..10. Set to 10.",m_configs[CONFIG_CHARACTERS_PER_REALM]);
        m_configs[CONFIG_CHARACTERS_PER_REALM] = 10;
    }

    // must be after CONFIG_CHARACTERS_PER_REALM
    m_configs[CONFIG_CHARACTERS_PER_ACCOUNT] = sConfig.GetIntDefault("CharactersPerAccount", 50);
    if(m_configs[CONFIG_CHARACTERS_PER_ACCOUNT] < m_configs[CONFIG_CHARACTERS_PER_REALM])
    {
        sLog.outError("CharactersPerAccount (%i) can't be less than CharactersPerRealm (%i).",m_configs[CONFIG_CHARACTERS_PER_ACCOUNT],m_configs[CONFIG_CHARACTERS_PER_REALM]);
        m_configs[CONFIG_CHARACTERS_PER_ACCOUNT] = m_configs[CONFIG_CHARACTERS_PER_REALM];
    }

    m_configs[CONFIG_HEROIC_CHARACTERS_PER_REALM] = sConfig.GetIntDefault("HeroicCharactersPerRealm", 1);
    if(int32(m_configs[CONFIG_HEROIC_CHARACTERS_PER_REALM]) < 0 || m_configs[CONFIG_HEROIC_CHARACTERS_PER_REALM] > 10)
    {
        sLog.outError("HeroicCharactersPerRealm (%i) must be in range 0..10. Set to 1.",m_configs[CONFIG_HEROIC_CHARACTERS_PER_REALM]);
        m_configs[CONFIG_HEROIC_CHARACTERS_PER_REALM] = 1;
    }

    m_configs[CONFIG_MIN_LEVEL_FOR_HEROIC_CHARACTER_CREATING] = sConfig.GetIntDefault("MinLevelForHeroicCharacterCreating", 55);

    m_configs[CONFIG_SKIP_CINEMATICS] = sConfig.GetIntDefault("SkipCinematics", 0);
    if(int32(m_configs[CONFIG_SKIP_CINEMATICS]) < 0 || m_configs[CONFIG_SKIP_CINEMATICS] > 2)
    {
        sLog.outError("SkipCinematics (%i) must be in range 0..2. Set to 0.",m_configs[CONFIG_SKIP_CINEMATICS]);
        m_configs[CONFIG_SKIP_CINEMATICS] = 0;
    }

    if(reload)
    {
        uint32 val = sConfig.GetIntDefault("MaxPlayerLevel", DEFAULT_MAX_LEVEL);
        if(val!=m_configs[CONFIG_MAX_PLAYER_LEVEL])
            sLog.outError("MaxPlayerLevel option can't be changed at config reload, using current value (%u).",m_configs[CONFIG_MAX_PLAYER_LEVEL]);
    }
    else
        m_configs[CONFIG_MAX_PLAYER_LEVEL] = sConfig.GetIntDefault("MaxPlayerLevel", DEFAULT_MAX_LEVEL);

    if(m_configs[CONFIG_MAX_PLAYER_LEVEL] > MAX_LEVEL)
    {
        sLog.outError("MaxPlayerLevel (%i) must be in range 1..%u. Set to %u.",m_configs[CONFIG_MAX_PLAYER_LEVEL],MAX_LEVEL,MAX_LEVEL);
        m_configs[CONFIG_MAX_PLAYER_LEVEL] = MAX_LEVEL;
    }

    m_configs[CONFIG_MIN_DUALSPEC_LEVEL] = sConfig.GetIntDefault("MinDualSpecLevel", 40);

    m_configs[CONFIG_START_PLAYER_LEVEL] = sConfig.GetIntDefault("StartPlayerLevel", 1);
    if(m_configs[CONFIG_START_PLAYER_LEVEL] < 1)
    {
        sLog.outError("StartPlayerLevel (%i) must be in range 1..MaxPlayerLevel(%u). Set to 1.",m_configs[CONFIG_START_PLAYER_LEVEL],m_configs[CONFIG_MAX_PLAYER_LEVEL]);
        m_configs[CONFIG_START_PLAYER_LEVEL] = 1;
    }
    else if(m_configs[CONFIG_START_PLAYER_LEVEL] > m_configs[CONFIG_MAX_PLAYER_LEVEL])
    {
        sLog.outError("StartPlayerLevel (%i) must be in range 1..MaxPlayerLevel(%u). Set to %u.",m_configs[CONFIG_START_PLAYER_LEVEL],m_configs[CONFIG_MAX_PLAYER_LEVEL],m_configs[CONFIG_MAX_PLAYER_LEVEL]);
        m_configs[CONFIG_START_PLAYER_LEVEL] = m_configs[CONFIG_MAX_PLAYER_LEVEL];
    }

    m_configs[CONFIG_START_HEROIC_PLAYER_LEVEL] = sConfig.GetIntDefault("StartHeroicPlayerLevel", 55);
    if(m_configs[CONFIG_START_HEROIC_PLAYER_LEVEL] < 1)
    {
        sLog.outError("StartHeroicPlayerLevel (%i) must be in range 1..MaxPlayerLevel(%u). Set to 55.",
            m_configs[CONFIG_START_HEROIC_PLAYER_LEVEL],m_configs[CONFIG_MAX_PLAYER_LEVEL]);
        m_configs[CONFIG_START_HEROIC_PLAYER_LEVEL] = 55;
    }
    else if(m_configs[CONFIG_START_HEROIC_PLAYER_LEVEL] > m_configs[CONFIG_MAX_PLAYER_LEVEL])
    {
        sLog.outError("StartHeroicPlayerLevel (%i) must be in range 1..MaxPlayerLevel(%u). Set to %u.",
            m_configs[CONFIG_START_HEROIC_PLAYER_LEVEL],m_configs[CONFIG_MAX_PLAYER_LEVEL],m_configs[CONFIG_MAX_PLAYER_LEVEL]);
        m_configs[CONFIG_START_HEROIC_PLAYER_LEVEL] = m_configs[CONFIG_MAX_PLAYER_LEVEL];
    }

    m_configs[CONFIG_START_PLAYER_MONEY] = sConfig.GetIntDefault("StartPlayerMoney", 0);
    if(int32(m_configs[CONFIG_START_PLAYER_MONEY]) < 0)
    {
        sLog.outError("StartPlayerMoney (%i) must be in range 0..%u. Set to %u.",m_configs[CONFIG_START_PLAYER_MONEY],MAX_MONEY_AMOUNT,0);
        m_configs[CONFIG_START_PLAYER_MONEY] = 0;
    }
    else if(m_configs[CONFIG_START_PLAYER_MONEY] > MAX_MONEY_AMOUNT)
    {
        sLog.outError("StartPlayerMoney (%i) must be in range 0..%u. Set to %u.",
            m_configs[CONFIG_START_PLAYER_MONEY],MAX_MONEY_AMOUNT,MAX_MONEY_AMOUNT);
        m_configs[CONFIG_START_PLAYER_MONEY] = MAX_MONEY_AMOUNT;
    }

    m_configs[CONFIG_MAX_HONOR_POINTS] = sConfig.GetIntDefault("MaxHonorPoints", 75000);
    if(int32(m_configs[CONFIG_MAX_HONOR_POINTS]) < 0)
    {
        sLog.outError("MaxHonorPoints (%i) can't be negative. Set to 0.",m_configs[CONFIG_MAX_HONOR_POINTS]);
        m_configs[CONFIG_MAX_HONOR_POINTS] = 0;
    }

    m_configs[CONFIG_START_HONOR_POINTS] = sConfig.GetIntDefault("StartHonorPoints", 0);
    if(int32(m_configs[CONFIG_START_HONOR_POINTS]) < 0)
    {
        sLog.outError("StartHonorPoints (%i) must be in range 0..MaxHonorPoints(%u). Set to %u.",
            m_configs[CONFIG_START_HONOR_POINTS],m_configs[CONFIG_MAX_HONOR_POINTS],0);
        m_configs[CONFIG_START_HONOR_POINTS] = 0;
    }
    else if(m_configs[CONFIG_START_HONOR_POINTS] > m_configs[CONFIG_MAX_HONOR_POINTS])
    {
        sLog.outError("StartHonorPoints (%i) must be in range 0..MaxHonorPoints(%u). Set to %u.",
            m_configs[CONFIG_START_HONOR_POINTS],m_configs[CONFIG_MAX_HONOR_POINTS],m_configs[CONFIG_MAX_HONOR_POINTS]);
        m_configs[CONFIG_START_HONOR_POINTS] = m_configs[CONFIG_MAX_HONOR_POINTS];
    }

    m_configs[CONFIG_MAX_ARENA_POINTS] = sConfig.GetIntDefault("MaxArenaPoints", 5000);
    if(int32(m_configs[CONFIG_MAX_ARENA_POINTS]) < 0)
    {
        sLog.outError("MaxArenaPoints (%i) can't be negative. Set to 0.",m_configs[CONFIG_MAX_ARENA_POINTS]);
        m_configs[CONFIG_MAX_ARENA_POINTS] = 0;
    }

    m_configs[CONFIG_START_ARENA_POINTS] = sConfig.GetIntDefault("StartArenaPoints", 0);
    if(int32(m_configs[CONFIG_START_ARENA_POINTS]) < 0)
    {
        sLog.outError("StartArenaPoints (%i) must be in range 0..MaxArenaPoints(%u). Set to %u.",
            m_configs[CONFIG_START_ARENA_POINTS],m_configs[CONFIG_MAX_ARENA_POINTS],0);
        m_configs[CONFIG_START_ARENA_POINTS] = 0;
    }
    else if(m_configs[CONFIG_START_ARENA_POINTS] > m_configs[CONFIG_MAX_ARENA_POINTS])
    {
        sLog.outError("StartArenaPoints (%i) must be in range 0..MaxArenaPoints(%u). Set to %u.",
            m_configs[CONFIG_START_ARENA_POINTS],m_configs[CONFIG_MAX_ARENA_POINTS],m_configs[CONFIG_MAX_ARENA_POINTS]);
        m_configs[CONFIG_START_ARENA_POINTS] = m_configs[CONFIG_MAX_ARENA_POINTS];
    }

    m_configs[CONFIG_ALL_TAXI_PATHS] = sConfig.GetBoolDefault("AllFlightPaths", false);
    m_configs[CONFIG_INSTANT_TAXI] = sConfig.GetBoolDefault("InstantFlightPaths", false);

    m_configs[CONFIG_INSTANCE_IGNORE_LEVEL] = sConfig.GetBoolDefault("Instance.IgnoreLevel", false);
    m_configs[CONFIG_INSTANCE_IGNORE_RAID]  = sConfig.GetBoolDefault("Instance.IgnoreRaid", false);

    m_configs[CONFIG_CAST_UNSTUCK] = sConfig.GetBoolDefault("CastUnstuck", true);
    m_configs[CONFIG_INSTANCE_RESET_TIME_HOUR]  = sConfig.GetIntDefault("Instance.ResetTimeHour", 4);
    m_configs[CONFIG_INSTANCE_UNLOAD_DELAY] = sConfig.GetIntDefault("Instance.UnloadDelay", 30 * MINUTE * IN_MILISECONDS);

    m_configs[CONFIG_MAX_PRIMARY_TRADE_SKILL] = sConfig.GetIntDefault("MaxPrimaryTradeSkill", 2);
    m_configs[CONFIG_MIN_PETITION_SIGNS] = sConfig.GetIntDefault("MinPetitionSigns", 9);
    if(m_configs[CONFIG_MIN_PETITION_SIGNS] > 9)
    {
        sLog.outError("MinPetitionSigns (%i) must be in range 0..9. Set to 9.", m_configs[CONFIG_MIN_PETITION_SIGNS]);
        m_configs[CONFIG_MIN_PETITION_SIGNS] = 9;
    }

    m_configs[CONFIG_GM_LOGIN_STATE]       = sConfig.GetIntDefault("GM.LoginState", 2);
    m_configs[CONFIG_GM_VISIBLE_STATE]     = sConfig.GetIntDefault("GM.Visible", 2);
    //m_configs[CONFIG_GM_ACCEPT_TICKETS]    = sConfig.GetIntDefault("GM.AcceptTickets", 2);
    m_configs[CONFIG_GM_CHAT]              = sConfig.GetIntDefault("GM.Chat", 2);
    m_configs[CONFIG_GM_WISPERING_TO]      = sConfig.GetIntDefault("GM.WhisperingTo", 2);

    m_configs[CONFIG_GM_LEVEL_IN_GM_LIST]  = sConfig.GetIntDefault("GM.InGMList.Level", SEC_ADMINISTRATOR);
    m_configs[CONFIG_GM_LEVEL_IN_WHO_LIST] = sConfig.GetIntDefault("GM.InWhoList.Level", SEC_ADMINISTRATOR);
    m_configs[CONFIG_GM_LOG_TRADE]         = sConfig.GetBoolDefault("GM.LogTrade", false);
    m_configs[CONFIG_START_GM_LEVEL]       = sConfig.GetIntDefault("GM.StartLevel", 1);
    m_configs[CONFIG_ALLOW_GM_GROUP]       = sConfig.GetBoolDefault("GM.AllowInvite", false);
    m_configs[CONFIG_ALLOW_GM_FRIEND]      = sConfig.GetBoolDefault("GM.AllowFriend", false);
    if(m_configs[CONFIG_START_GM_LEVEL] < m_configs[CONFIG_START_PLAYER_LEVEL])
    {
        sLog.outError("GM.StartLevel (%i) must be in range StartPlayerLevel(%u)..%u. Set to %u.",
            m_configs[CONFIG_START_GM_LEVEL],m_configs[CONFIG_START_PLAYER_LEVEL], MAX_LEVEL, m_configs[CONFIG_START_PLAYER_LEVEL]);
        m_configs[CONFIG_START_GM_LEVEL] = m_configs[CONFIG_START_PLAYER_LEVEL];
    }
    else if(m_configs[CONFIG_START_GM_LEVEL] > MAX_LEVEL)
    {
        sLog.outError("GM.StartLevel (%i) must be in range 1..%u. Set to %u.", m_configs[CONFIG_START_GM_LEVEL], MAX_LEVEL, MAX_LEVEL);
        m_configs[CONFIG_START_GM_LEVEL] = MAX_LEVEL;
    }
    m_configs[CONFIG_GM_LOWER_SECURITY] = sConfig.GetBoolDefault("GM.LowerSecurity", false);
    m_configs[CONFIG_GM_ALLOW_ACHIEVEMENT_GAINS] = sConfig.GetBoolDefault("GM.AllowAchievementGain", true);

    m_configs[CONFIG_GROUP_VISIBILITY] = sConfig.GetIntDefault("Visibility.GroupMode",0);

    m_configs[CONFIG_MAIL_DELIVERY_DELAY] = sConfig.GetIntDefault("MailDeliveryDelay",HOUR);

    m_configs[CONFIG_UPTIME_UPDATE] = sConfig.GetIntDefault("UpdateUptimeInterval", 10);
    if(int32(m_configs[CONFIG_UPTIME_UPDATE])<=0)
    {
        sLog.outError("UpdateUptimeInterval (%i) must be > 0, set to default 10.",m_configs[CONFIG_UPTIME_UPDATE]);
        m_configs[CONFIG_UPTIME_UPDATE] = 10;
    }
    if(reload)
    {
        m_timers[WUPDATE_UPTIME].SetInterval(m_configs[CONFIG_UPTIME_UPDATE]*MINUTE*IN_MILISECONDS);
        m_timers[WUPDATE_UPTIME].Reset();
    }

    // log db cleanup interval
    m_configs[CONFIG_LOGDB_CLEARINTERVAL] = sConfig.GetIntDefault("LogDB.Opt.ClearInterval", 10);
    if(int32(m_configs[CONFIG_LOGDB_CLEARINTERVAL]) <= 0)
    {
        sLog.outError("LogDB.Opt.ClearInterval (%i) must be > 0, set to default 10.", m_configs[CONFIG_LOGDB_CLEARINTERVAL]);
        m_configs[CONFIG_LOGDB_CLEARINTERVAL] = 10;
    }
    if(reload)
    {
        m_timers[WUPDATE_CLEANDB].SetInterval(m_configs[CONFIG_LOGDB_CLEARINTERVAL] * MINUTE * IN_MILISECONDS);
        m_timers[WUPDATE_CLEANDB].Reset();
    }
    m_configs[CONFIG_LOGDB_CLEARTIME] = sConfig.GetIntDefault("LogDB.Opt.ClearTime", 1209600); // 14 days default
    sLog.outString("Will clear `logs` table of entries older than %i seconds every %u minutes.",
        m_configs[CONFIG_LOGDB_CLEARTIME], m_configs[CONFIG_LOGDB_CLEARINTERVAL]);

    m_configs[CONFIG_SKILL_CHANCE_ORANGE] = sConfig.GetIntDefault("SkillChance.Orange",100);
    m_configs[CONFIG_SKILL_CHANCE_YELLOW] = sConfig.GetIntDefault("SkillChance.Yellow",75);
    m_configs[CONFIG_SKILL_CHANCE_GREEN]  = sConfig.GetIntDefault("SkillChance.Green",25);
    m_configs[CONFIG_SKILL_CHANCE_GREY]   = sConfig.GetIntDefault("SkillChance.Grey",0);

    m_configs[CONFIG_SKILL_CHANCE_MINING_STEPS]  = sConfig.GetIntDefault("SkillChance.MiningSteps",75);
    m_configs[CONFIG_SKILL_CHANCE_SKINNING_STEPS]   = sConfig.GetIntDefault("SkillChance.SkinningSteps",75);

    m_configs[CONFIG_SKILL_PROSPECTING] = sConfig.GetBoolDefault("SkillChance.Prospecting",false);
    m_configs[CONFIG_SKILL_MILLING] = sConfig.GetBoolDefault("SkillChance.Milling",false);

    m_configs[CONFIG_SKILL_GAIN_CRAFTING]  = sConfig.GetIntDefault("SkillGain.Crafting", 1);
    if(m_configs[CONFIG_SKILL_GAIN_CRAFTING] < 0)
    {
        sLog.outError("SkillGain.Crafting (%i) can't be negative. Set to 1.",m_configs[CONFIG_SKILL_GAIN_CRAFTING]);
        m_configs[CONFIG_SKILL_GAIN_CRAFTING] = 1;
    }

    m_configs[CONFIG_SKILL_GAIN_DEFENSE]  = sConfig.GetIntDefault("SkillGain.Defense", 1);
    if(m_configs[CONFIG_SKILL_GAIN_DEFENSE] < 0)
    {
        sLog.outError("SkillGain.Defense (%i) can't be negative. Set to 1.",m_configs[CONFIG_SKILL_GAIN_DEFENSE]);
        m_configs[CONFIG_SKILL_GAIN_DEFENSE] = 1;
    }

    m_configs[CONFIG_SKILL_GAIN_GATHERING]  = sConfig.GetIntDefault("SkillGain.Gathering", 1);
    if(m_configs[CONFIG_SKILL_GAIN_GATHERING] < 0)
    {
        sLog.outError("SkillGain.Gathering (%i) can't be negative. Set to 1.",m_configs[CONFIG_SKILL_GAIN_GATHERING]);
        m_configs[CONFIG_SKILL_GAIN_GATHERING] = 1;
    }

    m_configs[CONFIG_SKILL_GAIN_WEAPON]  = sConfig.GetIntDefault("SkillGain.Weapon", 1);
    if(m_configs[CONFIG_SKILL_GAIN_WEAPON] < 0)
    {
        sLog.outError("SkillGain.Weapon (%i) can't be negative. Set to 1.",m_configs[CONFIG_SKILL_GAIN_WEAPON]);
        m_configs[CONFIG_SKILL_GAIN_WEAPON] = 1;
    }

    m_configs[CONFIG_MAX_OVERSPEED_PINGS] = sConfig.GetIntDefault("MaxOverspeedPings",2);
    if(m_configs[CONFIG_MAX_OVERSPEED_PINGS] != 0 && m_configs[CONFIG_MAX_OVERSPEED_PINGS] < 2)
    {
        sLog.outError("MaxOverspeedPings (%i) must be in range 2..infinity (or 0 to disable check). Set to 2.",m_configs[CONFIG_MAX_OVERSPEED_PINGS]);
        m_configs[CONFIG_MAX_OVERSPEED_PINGS] = 2;
    }

    m_configs[CONFIG_SAVE_RESPAWN_TIME_IMMEDIATELY] = sConfig.GetBoolDefault("SaveRespawnTimeImmediately",true);
    m_configs[CONFIG_WEATHER] = sConfig.GetBoolDefault("ActivateWeather",true);

    m_configs[CONFIG_DISABLE_BREATHING] = sConfig.GetIntDefault("DisableWaterBreath", SEC_CONSOLE);

    m_configs[CONFIG_ALWAYS_MAX_SKILL_FOR_LEVEL] = sConfig.GetBoolDefault("AlwaysMaxSkillForLevel", false);

    if(reload)
    {
        uint32 val = sConfig.GetIntDefault("Expansion",1);
        if(val!=m_configs[CONFIG_EXPANSION])
            sLog.outError("Expansion option can't be changed at Trinityd.conf reload, using current value (%u).",m_configs[CONFIG_EXPANSION]);
    }
    else
        m_configs[CONFIG_EXPANSION] = sConfig.GetIntDefault("Expansion",1);

    m_configs[CONFIG_CHATFLOOD_MESSAGE_COUNT] = sConfig.GetIntDefault("ChatFlood.MessageCount",10);
    m_configs[CONFIG_CHATFLOOD_MESSAGE_DELAY] = sConfig.GetIntDefault("ChatFlood.MessageDelay",1);
    m_configs[CONFIG_CHATFLOOD_MUTE_TIME]     = sConfig.GetIntDefault("ChatFlood.MuteTime",10);

    m_configs[CONFIG_EVENT_ANNOUNCE] = sConfig.GetIntDefault("Event.Announce",0);

    m_configs[CONFIG_CREATURE_FAMILY_FLEE_ASSISTANCE_RADIUS] = sConfig.GetIntDefault("CreatureFamilyFleeAssistanceRadius",30);
    m_configs[CONFIG_CREATURE_FAMILY_ASSISTANCE_RADIUS] = sConfig.GetIntDefault("CreatureFamilyAssistanceRadius",10);
    m_configs[CONFIG_CREATURE_FAMILY_ASSISTANCE_DELAY]  = sConfig.GetIntDefault("CreatureFamilyAssistanceDelay",1500);
    m_configs[CONFIG_CREATURE_FAMILY_FLEE_DELAY]        = sConfig.GetIntDefault("CreatureFamilyFleeDelay",7000);

    m_configs[CONFIG_WORLD_BOSS_LEVEL_DIFF] = sConfig.GetIntDefault("WorldBossLevelDiff",3);

    // note: disable value (-1) will assigned as 0xFFFFFFF, to prevent overflow at calculations limit it to max possible player level MAX_LEVEL(100)
    m_configs[CONFIG_QUEST_LOW_LEVEL_HIDE_DIFF] = sConfig.GetIntDefault("Quests.LowLevelHideDiff", 4);
    if(m_configs[CONFIG_QUEST_LOW_LEVEL_HIDE_DIFF] > MAX_LEVEL)
        m_configs[CONFIG_QUEST_LOW_LEVEL_HIDE_DIFF] = MAX_LEVEL;
    m_configs[CONFIG_QUEST_HIGH_LEVEL_HIDE_DIFF] = sConfig.GetIntDefault("Quests.HighLevelHideDiff", 7);
    if(m_configs[CONFIG_QUEST_HIGH_LEVEL_HIDE_DIFF] > MAX_LEVEL)
        m_configs[CONFIG_QUEST_HIGH_LEVEL_HIDE_DIFF] = MAX_LEVEL;

    m_configs[CONFIG_DETECT_POS_COLLISION] = sConfig.GetBoolDefault("DetectPosCollision", true);

    m_configs[CONFIG_RESTRICTED_LFG_CHANNEL]      = sConfig.GetBoolDefault("Channel.RestrictedLfg", true);
    m_configs[CONFIG_SILENTLY_GM_JOIN_TO_CHANNEL] = sConfig.GetBoolDefault("Channel.SilentlyGMJoin", false);

    m_configs[CONFIG_TALENTS_INSPECTING]           = sConfig.GetBoolDefault("TalentsInspecting", true);
    m_configs[CONFIG_CHAT_FAKE_MESSAGE_PREVENTING] = sConfig.GetBoolDefault("ChatFakeMessagePreventing", false);
    m_configs[CONFIG_CHAT_STRICT_LINK_CHECKING_SEVERITY] = sConfig.GetIntDefault("ChatStrictLinkChecking.Severity", 0);
    m_configs[CONFIG_CHAT_STRICT_LINK_CHECKING_KICK] = sConfig.GetIntDefault("ChatStrictLinkChecking.Kick", 0);

    m_configs[CONFIG_CORPSE_DECAY_NORMAL]    = sConfig.GetIntDefault("Corpse.Decay.NORMAL", 60);
    m_configs[CONFIG_CORPSE_DECAY_RARE]      = sConfig.GetIntDefault("Corpse.Decay.RARE", 300);
    m_configs[CONFIG_CORPSE_DECAY_ELITE]     = sConfig.GetIntDefault("Corpse.Decay.ELITE", 300);
    m_configs[CONFIG_CORPSE_DECAY_RAREELITE] = sConfig.GetIntDefault("Corpse.Decay.RAREELITE", 300);
    m_configs[CONFIG_CORPSE_DECAY_WORLDBOSS] = sConfig.GetIntDefault("Corpse.Decay.WORLDBOSS", 3600);

    m_configs[CONFIG_DEATH_SICKNESS_LEVEL]           = sConfig.GetIntDefault ("Death.SicknessLevel", 11);
    m_configs[CONFIG_DEATH_CORPSE_RECLAIM_DELAY_PVP] = sConfig.GetBoolDefault("Death.CorpseReclaimDelay.PvP", true);
    m_configs[CONFIG_DEATH_CORPSE_RECLAIM_DELAY_PVE] = sConfig.GetBoolDefault("Death.CorpseReclaimDelay.PvE", true);
    m_configs[CONFIG_DEATH_BONES_WORLD]              = sConfig.GetBoolDefault("Death.Bones.World", true);
    m_configs[CONFIG_DEATH_BONES_BG_OR_ARENA]        = sConfig.GetBoolDefault("Death.Bones.BattlegroundOrArena", true);

    m_configs[CONFIG_DIE_COMMAND_MODE] = sConfig.GetBoolDefault("Die.Command.Mode", true);

    m_configs[CONFIG_THREAT_RADIUS] = sConfig.GetIntDefault("ThreatRadius", 60);

    // always use declined names in the russian client
    m_configs[CONFIG_DECLINED_NAMES_USED] =
        (m_configs[CONFIG_REALM_ZONE] == REALM_ZONE_RUSSIAN) ? true : sConfig.GetBoolDefault("DeclinedNames", false);

    m_configs[CONFIG_LISTEN_RANGE_SAY]       = sConfig.GetIntDefault("ListenRange.Say", 25);
    m_configs[CONFIG_LISTEN_RANGE_TEXTEMOTE] = sConfig.GetIntDefault("ListenRange.TextEmote", 25);
    m_configs[CONFIG_LISTEN_RANGE_YELL]      = sConfig.GetIntDefault("ListenRange.Yell", 300);

    m_configs[CONFIG_BATTLEGROUND_CAST_DESERTER]                = sConfig.GetBoolDefault("Battleground.CastDeserter", true);
    m_configs[CONFIG_BATTLEGROUND_QUEUE_ANNOUNCER_ENABLE]       = sConfig.GetBoolDefault("Battleground.QueueAnnouncer.Enable", false);
    m_configs[CONFIG_BATTLEGROUND_QUEUE_ANNOUNCER_PLAYERONLY]   = sConfig.GetBoolDefault("Battleground.QueueAnnouncer.PlayerOnly", false);
    m_configs[CONFIG_BATTLEGROUND_INVITATION_TYPE]              = sConfig.GetIntDefault ("Battleground.InvitationType", 0);
    m_configs[CONFIG_BATTLEGROUND_PREMATURE_FINISH_TIMER]       = sConfig.GetIntDefault ("BattleGround.PrematureFinishTimer", 5 * MINUTE * IN_MILISECONDS);
    m_configs[CONFIG_BATTLEGROUND_PREMADE_GROUP_WAIT_FOR_MATCH] = sConfig.GetIntDefault ("BattleGround.PremadeGroupWaitForMatch", 30 * MINUTE * IN_MILISECONDS);
    m_configs[CONFIG_ARENA_MAX_RATING_DIFFERENCE]               = sConfig.GetIntDefault ("Arena.MaxRatingDifference", 150);
    m_configs[CONFIG_ARENA_RATING_DISCARD_TIMER]                = sConfig.GetIntDefault ("Arena.RatingDiscardTimer", 10 * MINUTE * IN_MILISECONDS);
    m_configs[CONFIG_ARENA_AUTO_DISTRIBUTE_POINTS]              = sConfig.GetBoolDefault("Arena.AutoDistributePoints", false);
    m_configs[CONFIG_ARENA_AUTO_DISTRIBUTE_INTERVAL_DAYS]       = sConfig.GetIntDefault ("Arena.AutoDistributeInterval", 7);
    m_configs[CONFIG_ARENA_QUEUE_ANNOUNCER_ENABLE]              = sConfig.GetBoolDefault("Arena.QueueAnnouncer.Enable", false);
    m_configs[CONFIG_ARENA_QUEUE_ANNOUNCER_PLAYERONLY]          = sConfig.GetBoolDefault("Arena.QueueAnnouncer.PlayerOnly", false);
    m_configs[CONFIG_ARENA_SEASON_ID]                           = sConfig.GetIntDefault ("Arena.ArenaSeason.ID", 1);
    m_configs[CONFIG_ARENA_SEASON_IN_PROGRESS]                  = sConfig.GetBoolDefault("Arena.ArenaSeason.InProgress", true);

    m_configs[CONFIG_OFFHAND_CHECK_AT_SPELL_UNLEARN] = sConfig.GetBoolDefault("OffhandCheckAtSpellUnlearn", false);

    if(int clientCacheId = sConfig.GetIntDefault("ClientCacheVersion", 0))
    {
        // overwrite DB/old value
        if(clientCacheId > 0)
        {
            m_configs[CONFIG_CLIENTCACHE_VERSION] = clientCacheId;
            sLog.outString("Client cache version set to: %u", clientCacheId);
        }
        else
            sLog.outError("ClientCacheVersion can't be negative %d, ignored.", clientCacheId);
    }

    m_configs[CONFIG_INSTANT_LOGOUT] = sConfig.GetIntDefault("InstantLogout", SEC_MODERATOR);

    m_configs[CONFIG_GUILD_EVENT_LOG_COUNT] = sConfig.GetIntDefault("Guild.EventLogRecordsCount", GUILD_EVENTLOG_MAX_RECORDS);
    if (m_configs[CONFIG_GUILD_EVENT_LOG_COUNT] < GUILD_EVENTLOG_MAX_RECORDS)
        m_configs[CONFIG_GUILD_EVENT_LOG_COUNT] = GUILD_EVENTLOG_MAX_RECORDS;
    m_configs[CONFIG_GUILD_BANK_EVENT_LOG_COUNT] = sConfig.GetIntDefault("Guild.BankEventLogRecordsCount", GUILD_BANK_MAX_LOGS);
    if (m_configs[CONFIG_GUILD_BANK_EVENT_LOG_COUNT] < GUILD_BANK_MAX_LOGS)
        m_configs[CONFIG_GUILD_BANK_EVENT_LOG_COUNT] = GUILD_BANK_MAX_LOGS;

    m_VisibleUnitGreyDistance = sConfig.GetFloatDefault("Visibility.Distance.Grey.Unit", 1);
    if(m_VisibleUnitGreyDistance >  MAX_VISIBILITY_DISTANCE)
    {
        sLog.outError("Visibility.Distance.Grey.Unit can't be greater %f",MAX_VISIBILITY_DISTANCE);
        m_VisibleUnitGreyDistance = MAX_VISIBILITY_DISTANCE;
    }
    m_VisibleObjectGreyDistance = sConfig.GetFloatDefault("Visibility.Distance.Grey.Object", 10);
    if(m_VisibleObjectGreyDistance >  MAX_VISIBILITY_DISTANCE)
    {
        sLog.outError("Visibility.Distance.Grey.Object can't be greater %f",MAX_VISIBILITY_DISTANCE);
        m_VisibleObjectGreyDistance = MAX_VISIBILITY_DISTANCE;
    }

    m_MaxVisibleDistanceForCreature      = sConfig.GetFloatDefault("Visibility.Distance.Creature",     DEFAULT_VISIBILITY_DISTANCE);
    if(m_MaxVisibleDistanceForCreature < 45*sWorld.getRate(RATE_CREATURE_AGGRO))
    {
        sLog.outError("Visibility.Distance.Creature can't be less max aggro radius %f",45*sWorld.getRate(RATE_CREATURE_AGGRO));
        m_MaxVisibleDistanceForCreature = 45*sWorld.getRate(RATE_CREATURE_AGGRO);
    }
    else if(m_MaxVisibleDistanceForCreature + m_VisibleUnitGreyDistance >  MAX_VISIBILITY_DISTANCE)
    {
        sLog.outString("Visibility. Distance .Creature can't be greater %f",MAX_VISIBILITY_DISTANCE - m_VisibleUnitGreyDistance);
        m_MaxVisibleDistanceForCreature = MAX_VISIBILITY_DISTANCE-m_VisibleUnitGreyDistance;
    }

    m_MaxVisibleDistanceForPlayer        = sConfig.GetFloatDefault("Visibility.Distance.Player",       DEFAULT_VISIBILITY_DISTANCE);
    if(m_MaxVisibleDistanceForPlayer < 45*sWorld.getRate(RATE_CREATURE_AGGRO))
    {
        sLog.outError("Visibility.Distance.Player can't be less max aggro radius %f",45*sWorld.getRate(RATE_CREATURE_AGGRO));
        m_MaxVisibleDistanceForPlayer = 45*sWorld.getRate(RATE_CREATURE_AGGRO);
    }
    else if(m_MaxVisibleDistanceForPlayer + m_VisibleUnitGreyDistance >  MAX_VISIBILITY_DISTANCE)
    {
        sLog.outString("Visibility.Distance.Player can't be greater %f",MAX_VISIBILITY_DISTANCE - m_VisibleUnitGreyDistance);
        m_MaxVisibleDistanceForPlayer = MAX_VISIBILITY_DISTANCE - m_VisibleUnitGreyDistance;
    }
    m_MaxVisibleDistance = std::max(m_MaxVisibleDistanceForPlayer, m_MaxVisibleDistanceForCreature);

    m_MaxVisibleDistanceForObject    = sConfig.GetFloatDefault("Visibility.Distance.Object",   DEFAULT_VISIBILITY_DISTANCE);
    if(m_MaxVisibleDistanceForObject < INTERACTION_DISTANCE)
    {
        sLog.outError("Visibility.Distance.Object can't be less max aggro radius %f",float(INTERACTION_DISTANCE));
        m_MaxVisibleDistanceForObject = INTERACTION_DISTANCE;
    }
    else if(m_MaxVisibleDistanceForObject + m_VisibleObjectGreyDistance >  MAX_VISIBILITY_DISTANCE)
    {
        sLog.outString("Visibility.Distance.Object can't be greater %f",MAX_VISIBILITY_DISTANCE-m_VisibleObjectGreyDistance);
        m_MaxVisibleDistanceForObject = MAX_VISIBILITY_DISTANCE - m_VisibleObjectGreyDistance;
    }
    if(m_MaxVisibleDistance < m_MaxVisibleDistanceForObject)
        m_MaxVisibleDistance = m_MaxVisibleDistanceForObject;

    m_MaxVisibleDistanceInFlight    = sConfig.GetFloatDefault("Visibility.Distance.InFlight",      DEFAULT_VISIBILITY_DISTANCE);
    if(m_MaxVisibleDistanceInFlight + m_VisibleObjectGreyDistance > MAX_VISIBILITY_DISTANCE)
    {
        sLog.outString("Visibility.Distance.InFlight can't be greater %f",MAX_VISIBILITY_DISTANCE-m_VisibleObjectGreyDistance);
        m_MaxVisibleDistanceInFlight = MAX_VISIBILITY_DISTANCE - m_VisibleObjectGreyDistance;
    }
    if(m_MaxVisibleDistance < m_MaxVisibleDistanceInFlight)
        m_MaxVisibleDistance = m_MaxVisibleDistanceInFlight;
    m_MaxVisibleDistance += 1.0f;

    ///- Read the "Data" directory from the config file
    std::string dataPath = sConfig.GetStringDefault("DataDir","./");
    if( dataPath.at(dataPath.length()-1)!='/' && dataPath.at(dataPath.length()-1)!='\\' )
        dataPath.append("/");

    if(reload)
    {
        if(dataPath!=m_dataPath)
            sLog.outError("DataDir option can't be changed at Trinityd.conf reload, using current value (%s).",m_dataPath.c_str());
    }
    else
    {
        m_dataPath = dataPath;
        sLog.outString("Using DataDir %s",m_dataPath.c_str());
    }

    bool enableLOS = sConfig.GetBoolDefault("vmap.enableLOS", false);
    bool enableHeight = sConfig.GetBoolDefault("vmap.enableHeight", false);
    std::string ignoreMapIds = sConfig.GetStringDefault("vmap.ignoreMapIds", "");
    std::string ignoreSpellIds = sConfig.GetStringDefault("vmap.ignoreSpellIds", "");
    VMAP::VMapFactory::createOrGetVMapManager()->setEnableLineOfSightCalc(enableLOS);
    VMAP::VMapFactory::createOrGetVMapManager()->setEnableHeightCalc(enableHeight);
    VMAP::VMapFactory::createOrGetVMapManager()->preventMapsFromBeingUsed(ignoreMapIds.c_str());
    VMAP::VMapFactory::preventSpellsFromBeingTestedForLoS(ignoreSpellIds.c_str());
    sLog.outString( "WORLD: VMap support included. LineOfSight:%i, getHeight:%i",enableLOS, enableHeight);
    sLog.outString( "WORLD: VMap data directory is: %svmaps",m_dataPath.c_str());
    sLog.outString( "WORLD: VMap config keys are: vmap.enableLOS, vmap.enableHeight, vmap.ignoreMapIds, vmap.ignoreSpellIds");


    m_configs[CONFIG_MAX_WHO] = sConfig.GetIntDefault("MaxWhoListReturns", 49);
    m_configs[CONFIG_PET_LOS] = sConfig.GetBoolDefault("vmap.petLOS", false);
    m_configs[CONFIG_BG_START_MUSIC] = sConfig.GetBoolDefault("MusicInBattleground", false);
    m_configs[CONFIG_START_ALL_SPELLS] = sConfig.GetBoolDefault("PlayerStart.AllSpells", false);
    m_configs[CONFIG_HONOR_AFTER_DUEL] = sConfig.GetIntDefault("HonorPointsAfterDuel", 0);
    if(m_configs[CONFIG_HONOR_AFTER_DUEL] < 0)
        m_configs[CONFIG_HONOR_AFTER_DUEL]= 0;
    m_configs[CONFIG_START_ALL_EXPLORED] = sConfig.GetBoolDefault("PlayerStart.MapsExplored", false);
    m_configs[CONFIG_START_ALL_REP] = sConfig.GetBoolDefault("PlayerStart.AllReputation", false);
    m_configs[CONFIG_ALWAYS_MAXSKILL] = sConfig.GetBoolDefault("AlwaysMaxWeaponSkill", false);
    m_configs[CONFIG_PVP_TOKEN_ENABLE] = sConfig.GetBoolDefault("PvPToken.Enable", false);
    m_configs[CONFIG_PVP_TOKEN_MAP_TYPE] = sConfig.GetIntDefault("PvPToken.MapAllowType", 4);
    m_configs[CONFIG_PVP_TOKEN_ID] = sConfig.GetIntDefault("PvPToken.ItemID", 29434);
    m_configs[CONFIG_PVP_TOKEN_COUNT] = sConfig.GetIntDefault("PvPToken.ItemCount", 1);
    if(m_configs[CONFIG_PVP_TOKEN_COUNT] < 1)
        m_configs[CONFIG_PVP_TOKEN_COUNT] = 1;
    m_configs[CONFIG_OUTDOORPVP_WINTERGRASP_START_TIME]     = sConfig.GetIntDefault("OutdoorPvP.Wintergrasp.StartTime", 30);
    m_configs[CONFIG_OUTDOORPVP_WINTERGRASP_BATTLE_TIME]    = sConfig.GetIntDefault("OutdoorPvP.Wintergrasp.BattleTime", 30); 
    m_configs[CONFIG_OUTDOORPVP_WINTERGRASP_INTERVAL]       = sConfig.GetIntDefault("OutdoorPvP.Wintergrasp.Interval", 150);
    m_configs[CONFIG_OUTDOORPVP_WINTERGRASP_CUSTOM_HONOR]   = sConfig.GetBoolDefault("OutdoorPvP.Wintergrasp.CustomHonorRewards", false);
    m_configs[CONFIG_OUTDOORPVP_WINTERGRASP_CUSTOM_HONOR_0] = sConfig.GetIntDefault("OutdoorPvP.Wintergrasp.CustomHonorBattleWin", 0);
    m_configs[CONFIG_OUTDOORPVP_WINTERGRASP_CUSTOM_HONOR_1] = sConfig.GetIntDefault("OutdoorPvP.Wintergrasp.CustomHonorBattleLose", 0);
    m_configs[CONFIG_OUTDOORPVP_WINTERGRASP_CUSTOM_HONOR_2] = sConfig.GetIntDefault("OutdoorPvP.Wintergrasp.CustomHonorDamageTower", 0);
    m_configs[CONFIG_OUTDOORPVP_WINTERGRASP_CUSTOM_HONOR_3] = sConfig.GetIntDefault("OutdoorPvP.Wintergrasp.CustomHonorDestroyedTower", 0);
    m_configs[CONFIG_OUTDOORPVP_WINTERGRASP_CUSTOM_HONOR_4] = sConfig.GetIntDefault("OutdoorPvP.Wintergrasp.CustomHonorDamagedBuilding", 0);
    m_configs[CONFIG_OUTDOORPVP_WINTERGRASP_CUSTOM_HONOR_5] = sConfig.GetIntDefault("OutdoorPvP.Wintergrasp.CustomHonorIntactBuilding", 0);
   
    m_configs[CONFIG_NO_RESET_TALENT_COST] = sConfig.GetBoolDefault("NoResetTalentsCost", false);
    m_configs[CONFIG_SHOW_KICK_IN_WORLD] = sConfig.GetBoolDefault("ShowKickInWorld", false);
    m_configs[CONFIG_INTERVAL_LOG_UPDATE] = sConfig.GetIntDefault("RecordUpdateTimeDiffInterval", 60000);
    m_configs[CONFIG_MIN_LOG_UPDATE] = sConfig.GetIntDefault("MinRecordUpdateTimeDiff", 10);
    m_configs[CONFIG_CHECK_DB] = sConfig.GetBoolDefault("CheckDB", true);
    m_configs[CONFIG_NUMTHREADS] = sConfig.GetIntDefault("MapUpdate.Threads",1);

    std::string forbiddenmaps = sConfig.GetStringDefault("ForbiddenMaps", "");
    char * forbiddenMaps = new char[forbiddenmaps.length() + 1];
    forbiddenMaps[forbiddenmaps.length()] = 0;
    strncpy(forbiddenMaps, forbiddenmaps.c_str(), forbiddenmaps.length());
    const char * delim = ",";
    char * token = strtok(forbiddenMaps, delim);
    while(token != NULL)
    {
        int32 mapid = strtol(token, NULL, 10);
        m_forbiddenMapIds.insert(mapid);
        token = strtok(NULL,delim);
    }
    delete[] forbiddenMaps;

    // chat logging
    m_configs[CONFIG_CHATLOG_CHANNEL] = sConfig.GetBoolDefault("ChatLogs.Channel", false);
    m_configs[CONFIG_CHATLOG_WHISPER] = sConfig.GetBoolDefault("ChatLogs.Whisper", false);
    m_configs[CONFIG_CHATLOG_SYSCHAN] = sConfig.GetBoolDefault("ChatLogs.SysChan", false);
    m_configs[CONFIG_CHATLOG_PARTY] = sConfig.GetBoolDefault("ChatLogs.Party", false);
    m_configs[CONFIG_CHATLOG_RAID] = sConfig.GetBoolDefault("ChatLogs.Raid", false);
    m_configs[CONFIG_CHATLOG_GUILD] = sConfig.GetBoolDefault("ChatLogs.Guild", false);
    m_configs[CONFIG_CHATLOG_PUBLIC] = sConfig.GetBoolDefault("ChatLogs.Public", false);
    m_configs[CONFIG_CHATLOG_ADDON] = sConfig.GetBoolDefault("ChatLogs.Addon", false);
    m_configs[CONFIG_CHATLOG_BGROUND] = sConfig.GetBoolDefault("ChatLogs.BattleGround", false);
}

/// Initialize the World
void World::SetInitialWorldSettings()
{
    ///- Initialize the random number generator
    srand((unsigned int)time(NULL));

    ///- Initialize config settings
    LoadConfigSettings();

    ///- Init highest guids before any table loading to prevent using not initialized guids in some code.
    objmgr.SetHighestGuids();

    ///- Check the existence of the map files for all races' startup areas.
    if(   !MapManager::ExistMapAndVMap(0,-6240.32f, 331.033f)
        ||!MapManager::ExistMapAndVMap(0,-8949.95f,-132.493f)
        ||!MapManager::ExistMapAndVMap(0,-8949.95f,-132.493f)
        ||!MapManager::ExistMapAndVMap(1,-618.518f,-4251.67f)
        ||!MapManager::ExistMapAndVMap(0, 1676.35f, 1677.45f)
        ||!MapManager::ExistMapAndVMap(1, 10311.3f, 832.463f)
        ||!MapManager::ExistMapAndVMap(1,-2917.58f,-257.98f)
        ||m_configs[CONFIG_EXPANSION] && (
        !MapManager::ExistMapAndVMap(530,10349.6f,-6357.29f) || !MapManager::ExistMapAndVMap(530,-3961.64f,-13931.2f) ) )
    {
        sLog.outError("Correct *.map files not found in path '%smaps' or *.vmap/*vmdir files in '%svmaps'. Please place *.map/*.vmap/*.vmdir files in appropriate directories or correct the DataDir value in the Trinityd.conf file.",m_dataPath.c_str(),m_dataPath.c_str());
        exit(1);
    }

    ///- Loading strings. Getting no records means core load has to be canceled because no error message can be output.
    sLog.outString();
    sLog.outString( "Loading Trinity strings..." );
    if (!objmgr.LoadTrinityStrings())
        exit(1);                                            // Error message displayed in function already

    ///- Update the realm entry in the database with the realm type from the config file
    //No SQL injection as values are treated as integers

    // not send custom type REALM_FFA_PVP to realm list
    uint32 server_type = IsFFAPvPRealm() ? REALM_TYPE_PVP : getConfig(CONFIG_GAME_TYPE);
    uint32 realm_zone = getConfig(CONFIG_REALM_ZONE);
    loginDatabase.PExecute("UPDATE realmlist SET icon = %u, timezone = %u WHERE id = '%d'", server_type, realm_zone, realmID);

    ///- Remove the bones after a restart
    CharacterDatabase.PExecute("DELETE FROM corpse WHERE corpse_type = '0'");

    ///- Load the DBC files
    sLog.outString("Initialize data stores...");
    LoadDBCStores(m_dataPath);
    DetectDBCLang();

    sLog.outString( "Loading Script Names...");
    objmgr.LoadScriptNames();

    sLog.outString( "Loading InstanceTemplate..." );
    objmgr.LoadInstanceTemplate();

    sLog.outString( "Loading SkillLineAbilityMultiMap Data..." );
    spellmgr.LoadSkillLineAbilityMap();

    ///- Clean up and pack instances
    sLog.outString( "Cleaning up instances..." );
    sInstanceSaveManager.CleanupInstances();                // must be called before `creature_respawn`/`gameobject_respawn` tables

    sLog.outString( "Packing instances..." );
    sInstanceSaveManager.PackInstances();

    sLog.outString();
    sLog.outString( "Loading Localization strings..." );
    objmgr.LoadCreatureLocales();
    objmgr.LoadGameObjectLocales();
    objmgr.LoadItemLocales();
    objmgr.LoadQuestLocales();
    objmgr.LoadNpcTextLocales();
    objmgr.LoadPageTextLocales();
    objmgr.LoadNpcOptionLocales();
    objmgr.LoadPointOfInterestLocales();
    objmgr.SetDBCLocaleIndex(GetDefaultDbcLocale());        // Get once for all the locale index of DBC language (console/broadcasts)
    sLog.outString( ">>> Localization strings loaded" );
    sLog.outString();

    sLog.outString( "Loading Page Texts..." );
    objmgr.LoadPageTexts();

    sLog.outString( "Loading Player info in cache..." );
    objmgr.LoadPlayerInfoInCache();

    sLog.outString( "Loading Game Object Templates..." );   // must be after LoadPageTexts
    objmgr.LoadGameobjectInfo();

    sLog.outString( "Loading Spell Chain Data..." );
    spellmgr.LoadSpellChains();

    sLog.outString( "Loading Spell Required Data..." );
    spellmgr.LoadSpellRequired();

    sLog.outString( "Loading Spell Elixir types..." );
    spellmgr.LoadSpellElixirs();

    sLog.outString( "Loading Spell Learn Skills..." );
    spellmgr.LoadSpellLearnSkills();                        // must be after LoadSpellChains

    sLog.outString( "Loading Spell Learn Spells..." );
    spellmgr.LoadSpellLearnSpells();

    sLog.outString( "Loading Spell Proc Event conditions..." );
    spellmgr.LoadSpellProcEvents();

    sLog.outString( "Loading Spell Bonus Data..." );
    spellmgr.LoadSpellBonusess();

    sLog.outString( "Loading Aggro Spells Definitions...");
    spellmgr.LoadSpellThreats();

    sLog.outString( "Loading NPC Texts..." );
    objmgr.LoadGossipText();

    sLog.outString( "Loading Enchant Spells Proc datas...");
    spellmgr.LoadSpellEnchantProcData();

    sLog.outString( "Loading Item Random Enchantments Table..." );
    LoadRandomEnchantmentsTable();

    sLog.outString( "Loading Items..." );                   // must be after LoadRandomEnchantmentsTable and LoadPageTexts
    objmgr.LoadItemPrototypes();

    sLog.outString( "Loading Item Texts..." );
    objmgr.LoadItemTexts();

    sLog.outString( "Loading Creature Model Based Info Data..." );
    objmgr.LoadCreatureModelInfo();

    sLog.outString( "Loading Equipment templates...");
    objmgr.LoadEquipmentTemplates();

    sLog.outString( "Loading Creature templates..." );
    objmgr.LoadCreatureTemplates();

    sLog.outString( "Loading SpellsScriptTarget...");
    spellmgr.LoadSpellScriptTarget();                       // must be after LoadCreatureTemplates and LoadGameobjectInfo

    sLog.outString( "Loading ItemRequiredTarget...");
    objmgr.LoadItemRequiredTarget();

    sLog.outString( "Loading Creature Reputation OnKill Data..." );
    objmgr.LoadReputationOnKill();

    sLog.outString( "Loading Points Of Interest Data..." );
    objmgr.LoadPointsOfInterest();

    sLog.outString( "Loading Creature Data..." );
    objmgr.LoadCreatures();

    sLog.outString( "Loading Creature Linked Respawn..." );
    objmgr.LoadCreatureLinkedRespawn();                     // must be after LoadCreatures()

    sLog.outString( "Loading pet levelup spells..." );
    spellmgr.LoadPetLevelupSpellMap();

    sLog.outString( "Loading pet default spell additional to levelup spells..." );
    spellmgr.LoadPetDefaultSpells();

    sLog.outString( "Loading Creature Addon Data..." );
    sLog.outString();
    objmgr.LoadCreatureAddons();                            // must be after LoadCreatureTemplates() and LoadCreatures()
    sLog.outString( ">>> Creature Addon Data loaded" );
    sLog.outString();

    sLog.outString( "Loading Creature Respawn Data..." );   // must be after PackInstances()
    objmgr.LoadCreatureRespawnTimes();

    sLog.outString( "Loading Gameobject Data..." );
    objmgr.LoadGameobjects();

    sLog.outString( "Loading Gameobject Respawn Data..." ); // must be after PackInstances()
    objmgr.LoadGameobjectRespawnTimes();

    sLog.outString( "Loading Objects Pooling Data...");
    poolhandler.LoadFromDB();

    sLog.outString( "Loading Game Event Data...");
    sLog.outString();
    gameeventmgr.LoadFromDB();
    sLog.outString( ">>> Game Event Data loaded" );
    sLog.outString();

    sLog.outString( "Loading Weather Data..." );
    objmgr.LoadWeatherZoneChances();

    sLog.outString( "Loading Quests..." );
    objmgr.LoadQuests();                                    // must be loaded after DBCs, creature_template, item_template, gameobject tables

    sLog.outString( "Loading Quests Relations..." );
    sLog.outString();
    objmgr.LoadQuestRelations();                            // must be after quest load
    sLog.outString( ">>> Quests Relations loaded" );
    sLog.outString();

    sLog.outString( "Loading UNIT_NPC_FLAG_SPELLCLICK Data..." );
    objmgr.LoadNPCSpellClickSpells();

    sLog.outString( "Loading SpellArea Data..." );          // must be after quest load
    spellmgr.LoadSpellAreas();

    sLog.outString( "Loading AreaTrigger definitions..." );
    objmgr.LoadAreaTriggerTeleports();

    sLog.outString( "Loading Access Requirements..." );
    objmgr.LoadAccessRequirements();                        // must be after item template load

    sLog.outString( "Loading Quest Area Triggers..." );
    objmgr.LoadQuestAreaTriggers();                         // must be after LoadQuests

    sLog.outString( "Loading Tavern Area Triggers..." );
    objmgr.LoadTavernAreaTriggers();

    sLog.outString( "Loading AreaTrigger script names..." );
    objmgr.LoadAreaTriggerScripts();

    sLog.outString( "Loading Graveyard-zone links...");
    objmgr.LoadGraveyardZones();

    sLog.outString( "Loading Spell target coordinates..." );
    spellmgr.LoadSpellTargetPositions();

    sLog.outString( "Loading spell pet auras..." );
    spellmgr.LoadSpellPetAuras();

    sLog.outString( "Loading spell extra attributes...(TODO)" );
    spellmgr.LoadSpellCustomAttr();

    sLog.outString( "Loading enchant custom attributes..." );
    spellmgr.LoadEnchantCustomAttr();

    sLog.outString( "Loading linked spells..." );
    spellmgr.LoadSpellLinked();

    sLog.outString( "Loading Player Create Info & Level Stats..." );
    sLog.outString();
    objmgr.LoadPlayerInfo();
    sLog.outString( ">>> Player Create Info & Level Stats loaded" );
    sLog.outString();

    sLog.outString( "Loading Exploration BaseXP Data..." );
    objmgr.LoadExplorationBaseXP();

    sLog.outString( "Loading Pet Name Parts..." );
    objmgr.LoadPetNames();

    sLog.outString( "Loading the max pet number..." );
    objmgr.LoadPetNumber();

    sLog.outString( "Loading pet level stats..." );
    objmgr.LoadPetLevelInfo();

    sLog.outString( "Loading Player Corpses..." );
    objmgr.LoadCorpses();

    sLog.outString( "Loading Disabled Spells..." );
    objmgr.LoadSpellDisabledEntrys();

    sLog.outString( "Loading Loot Tables..." );
    sLog.outString();
    LoadLootTables();
    sLog.outString( ">>> Loot Tables loaded" );
    sLog.outString();

    sLog.outString( "Loading Skill Discovery Table..." );
    LoadSkillDiscoveryTable();

    sLog.outString( "Loading Skill Extra Item Table..." );
    LoadSkillExtraItemTable();

    sLog.outString( "Loading Skill Fishing base level requirements..." );
    objmgr.LoadFishingBaseSkillLevel();

    sLog.outString( "Loading Achievements..." );
    sLog.outString();
    achievementmgr.LoadAchievementReferenceList();
    achievementmgr.LoadAchievementCriteriaList();
    achievementmgr.LoadAchievementCriteriaData();
    achievementmgr.LoadRewards();
    achievementmgr.LoadRewardLocales();
    achievementmgr.LoadCompletedAchievements();
    sLog.outString( ">>> Achievements loaded" );
    sLog.outString();

    ///- Load dynamic data tables from the database
    sLog.outString( "Loading Auctions..." );
    sLog.outString();
    auctionmgr.LoadAuctionItems();
    auctionmgr.LoadAuctions();
    sLog.outString( ">>> Auctions loaded" );
    sLog.outString();

    sLog.outString( "Loading Guilds..." );
    objmgr.LoadGuilds();

    sLog.outString( "Loading ArenaTeams..." );
    objmgr.LoadArenaTeams();

    sLog.outString( "Loading Groups..." );
    objmgr.LoadGroups();

    sLog.outString( "Loading ReservedNames..." );
    objmgr.LoadReservedPlayersNames();

    sLog.outString( "Loading GameObjects for quests..." );
    objmgr.LoadGameObjectForQuests();

    sLog.outString( "Loading BattleMasters..." );
    sBattleGroundMgr.LoadBattleMastersEntry();

    sLog.outString( "Loading GameTeleports..." );
    objmgr.LoadGameTele();

    sLog.outString( "Loading Npc Text Id..." );
    objmgr.LoadNpcTextId();                                 // must be after load Creature and NpcText

    sLog.outString( "Loading Npc Options..." );
    objmgr.LoadNpcOptions();

    sLog.outString( "Loading Vendors..." );
    objmgr.LoadVendors();                                   // must be after load CreatureTemplate and ItemTemplate

    sLog.outString( "Loading Trainers..." );
    objmgr.LoadTrainerSpell();                              // must be after load CreatureTemplate

    sLog.outString( "Loading Waypoints..." );
    sLog.outString();
    WaypointMgr.Load();

    sLog.outString( "Loading Creature Formations..." );
    formation_mgr.LoadCreatureFormations();

    sLog.outString( "Loading GM tickets...");
    objmgr.LoadGMTickets();

    ///- Handle outdated emails (delete/return)
    sLog.outString( "Returning old mails..." );
    objmgr.ReturnOrDeleteOldMails(false);

    sLog.outString("Loading Autobroadcasts...");
    LoadAutobroadcasts();

    ///- Load and initialize scripts
    sLog.outString( "Loading Scripts..." );
    sLog.outString();
    objmgr.LoadQuestStartScripts();                         // must be after load Creature/Gameobject(Template/Data) and QuestTemplate
    objmgr.LoadQuestEndScripts();                           // must be after load Creature/Gameobject(Template/Data) and QuestTemplate
    objmgr.LoadSpellScripts();                              // must be after load Creature/Gameobject(Template/Data)
    objmgr.LoadGameObjectScripts();                         // must be after load Creature/Gameobject(Template/Data)
    objmgr.LoadEventScripts();                              // must be after load Creature/Gameobject(Template/Data)
    objmgr.LoadWaypointScripts();
    sLog.outString( ">>> Scripts loaded" );
    sLog.outString();

    sLog.outString( "Loading Scripts text locales..." );    // must be after Load*Scripts calls
    objmgr.LoadDbScriptStrings();

    sLog.outString( "Loading CreatureEventAI Texts...");
    CreatureEAI_Mgr.LoadCreatureEventAI_Texts();

    sLog.outString( "Loading CreatureEventAI Summons...");
    CreatureEAI_Mgr.LoadCreatureEventAI_Summons();

    sLog.outString( "Loading CreatureEventAI Scripts...");
    CreatureEAI_Mgr.LoadCreatureEventAI_Scripts();

    sLog.outString( "Initializing Scripts..." );
    if(!LoadScriptingModule())
        exit(1);

    /// Check db
    if(m_configs[CONFIG_CHECK_DB])
    {
        sLog.outString( "Checking DB..." );
        if(!objmgr.CheckDB() || !spellmgr.CheckDB())
        {
            sLog.outError("Your world DB is outdated. Please reapply sqls in sql\\FULL folder, or disable CheckDB option in config file (not recommended).");
            exit(1);
        }
    }
    else
        sLog.outError("You have disabled DB check. We strongly recommend you to enable it to prevent unpredictable bugs and crashes.");

    ///- Initialize game time and timers
    sLog.outDebug( "DEBUG:: Initialize game time and timers" );
    m_gameTime = time(NULL);
    m_startTime=m_gameTime;

    tm local;
    time_t curr;
    time(&curr);
    local=*(localtime(&curr));                              // dereference and assign
    char isoDate[128];
    sprintf( isoDate, "%04d-%02d-%02d %02d:%02d:%02d",
        local.tm_year+1900, local.tm_mon+1, local.tm_mday, local.tm_hour, local.tm_min, local.tm_sec);

    loginDatabase.PExecute("INSERT INTO uptime (realmid, starttime, startstring, uptime) VALUES('%u', " UI64FMTD ", '%s', 0)",
        realmID, uint64(m_startTime), isoDate);

    static uint32 abtimer = 0;
    abtimer = sConfig.GetIntDefault("AutoBroadcast.Timer", 60000);
    m_timers[WUPDATE_OBJECTS].SetInterval(IN_MILISECONDS/2);
    m_timers[WUPDATE_SESSIONS].SetInterval(0);
    m_timers[WUPDATE_WEATHERS].SetInterval(1*IN_MILISECONDS);
    m_timers[WUPDATE_AUCTIONS].SetInterval(MINUTE*IN_MILISECONDS);
    m_timers[WUPDATE_UPTIME].SetInterval(m_configs[CONFIG_UPTIME_UPDATE]*MINUTE*IN_MILISECONDS);
                                                            //Update "uptime" table based on configuration entry in minutes.
    m_timers[WUPDATE_CORPSES].SetInterval(20*MINUTE*IN_MILISECONDS);
                                                            //erase corpses every 20 minutes
    m_timers[WUPDATE_CLEANDB].SetInterval(m_configs[CONFIG_LOGDB_CLEARINTERVAL]*MINUTE*IN_MILISECONDS);
                                                            // clean logs table every 14 days by default
    m_timers[WUPDATE_AUTOBROADCAST].SetInterval(abtimer);

    //to set mailtimer to return mails every day between 4 and 5 am
    //mailtimer is increased when updating auctions
    //one second is 1000 -(tested on win system)
    mail_timer = ((((localtime( &m_gameTime )->tm_hour + 20) % 24)* HOUR * IN_MILISECONDS) / m_timers[WUPDATE_AUCTIONS].GetInterval() );
                                                            //1440
    mail_timer_expires = ( (DAY * IN_MILISECONDS) / (m_timers[WUPDATE_AUCTIONS].GetInterval()));
    sLog.outDebug("Mail timer set to: %u, mail return is called every %u minutes", mail_timer, mail_timer_expires);

    ///- Initilize static helper structures
    AIRegistry::Initialize();
    Player::InitVisibleBits();

    ///- Initialize MapManager
    sLog.outString( "Starting Map System" );
    MapManager::Instance().Initialize();

    sLog.outString("Starting Game Event system..." );
    uint32 nextGameEvent = gameeventmgr.Initialize();
    m_timers[WUPDATE_EVENTS].SetInterval(nextGameEvent);    //depend on next event

    ///- Initialize Battlegrounds
    sLog.outString( "Starting BattleGround System" );
    sBattleGroundMgr.CreateInitialBattleGrounds();
    sBattleGroundMgr.InitAutomaticArenaPointDistribution();

    ///- Initialize outdoor pvp
    sLog.outString( "Starting Outdoor PvP System" );
    sOutdoorPvPMgr.InitOutdoorPvP();

    //Not sure if this can be moved up in the sequence (with static data loading) as it uses MapManager
    sLog.outString( "Loading Transports..." );
    MapManager::Instance().LoadTransports();

    sLog.outString( "Loading Transports Events..." );
    objmgr.LoadTransportEvents();

    sLog.outString("Deleting expired bans..." );
    loginDatabase.Execute("DELETE FROM ip_banned WHERE unbandate<=UNIX_TIMESTAMP() AND unbandate<>bandate");

    sLog.outString("Calculate next daily quest reset time..." );
    InitDailyQuestResetTime();

    sLog.outString("Starting objects Pooling system..." );
    poolhandler.Initialize();

    sLog.outString("Initialize AuctionHouseBot...");
    auctionbot.Initialize();

    // possibly enable db logging; avoid massive startup spam by doing it here.
    if (sLog.GetLogDBLater())
    {
        sLog.outString("Enabling database logging...");
        sLog.SetLogDBLater(false);
        sLog.SetLogDB(true);
    }
    else
    {
        sLog.SetLogDB(false);
        sLog.SetLogDBLater(false);
    }

    sLog.outString( "WORLD: World initialized" );
}

void World::DetectDBCLang()
{
    uint32 m_lang_confid = sConfig.GetIntDefault("DBC.Locale", 255);

    if(m_lang_confid != 255 && m_lang_confid >= MAX_LOCALE)
    {
        sLog.outError("Incorrect DBC.Locale! Must be >= 0 and < %d (set to 0)",MAX_LOCALE);
        m_lang_confid = LOCALE_enUS;
    }

    ChrRacesEntry const* race = sChrRacesStore.LookupEntry(1);

    std::string availableLocalsStr;

    int default_locale = MAX_LOCALE;
    for (int i = MAX_LOCALE-1; i >= 0; --i)
    {
        if ( strlen(race->name[i]) > 0)                     // check by race names
        {
            default_locale = i;
            m_availableDbcLocaleMask |= (1 << i);
            availableLocalsStr += localeNames[i];
            availableLocalsStr += " ";
        }
    }

    if( default_locale != m_lang_confid && m_lang_confid < MAX_LOCALE &&
        (m_availableDbcLocaleMask & (1 << m_lang_confid)) )
    {
        default_locale = m_lang_confid;
    }

    if(default_locale >= MAX_LOCALE)
    {
        sLog.outError("Unable to determine your DBC Locale! (corrupt DBC?)");
        exit(1);
    }

    m_defaultDbcLocale = LocaleConstant(default_locale);

    sLog.outString("Using %s DBC Locale as default. All available DBC locales: %s",localeNames[m_defaultDbcLocale],availableLocalsStr.empty() ? "<none>" : availableLocalsStr.c_str());
    sLog.outString();
}

void World::RecordTimeDiff(const char *text, ...)
{
    if(m_updateTimeCount != 1)
        return;
    if(!text)
    {
        m_currentTime = getMSTime();
        return;
    }

    uint32 thisTime = getMSTime();
    uint32 diff = getMSTimeDiff(m_currentTime, thisTime);

    if(diff > m_configs[CONFIG_MIN_LOG_UPDATE])
    {
        va_list ap;
        char str [256];
        va_start(ap, text);
        vsnprintf(str,256,text, ap );
        va_end(ap);
        sLog.outDetail("Difftime %s: %u.", str, diff);
    }

    m_currentTime = thisTime;
}

void World::LoadAutobroadcasts()
{
    m_Autobroadcasts.clear();

    QueryResult *result = WorldDatabase.Query("SELECT text FROM autobroadcast");

    if(!result)
    {
        barGoLink bar(1);
        bar.step();

        sLog.outString();
        sLog.outString( ">> Loaded 0 autobroadcasts definitions");
        return;
    }

    barGoLink bar(result->GetRowCount());

    uint32 count = 0;

    do
    {
        bar.step();

        Field *fields = result->Fetch();

        std::string message = fields[0].GetCppString();

        m_Autobroadcasts.push_back(message);

        count++;
    } while(result->NextRow());

    delete result;

    sLog.outString();
    sLog.outString( ">> Loaded %u autobroadcasts definitions", count);
}

/// Update the World !
void World::Update(uint32 diff)
{
    m_updateTime = uint32(diff);
    if(m_configs[CONFIG_INTERVAL_LOG_UPDATE])
    {
        if(m_updateTimeSum > m_configs[CONFIG_INTERVAL_LOG_UPDATE])
        {
            sLog.outBasic("Update time diff: %u. Players online: %u.", m_updateTimeSum / m_updateTimeCount, GetActiveSessionCount());
            m_updateTimeSum = m_updateTime;
            m_updateTimeCount = 1;
        }
        else
        {
            m_updateTimeSum += m_updateTime;
            ++m_updateTimeCount;
        }
    }

    ///- Update the different timers
    for(int i = 0; i < WUPDATE_COUNT; ++i)
        if(m_timers[i].GetCurrent()>=0)
            m_timers[i].Update(diff);
    else m_timers[i].SetCurrent(0);

    ///- Update the game time and check for shutdown time
    _UpdateGameTime();

    /// Handle daily quests reset time
    if(m_gameTime > m_NextDailyQuestReset)
    {
        ResetDailyQuests();
        m_NextDailyQuestReset += DAY;
    }

    /// <ul><li> Handle auctions when the timer has passed
    if (m_timers[WUPDATE_AUCTIONS].Passed())
    {
        auctionbot.Update();
        m_timers[WUPDATE_AUCTIONS].Reset();

        ///- Update mails (return old mails with item, or delete them)
        //(tested... works on win)
        if (++mail_timer > mail_timer_expires)
        {
            mail_timer = 0;
            objmgr.ReturnOrDeleteOldMails(true);
        }

        ///- Handle expired auctions
        auctionmgr.Update();
    }

    /// <li> Handle session updates when the timer has passed
    RecordTimeDiff(NULL);
    UpdateSessions(diff);
    RecordTimeDiff("UpdateSessions");

    /// <li> Handle weather updates when the timer has passed
    if (m_timers[WUPDATE_WEATHERS].Passed())
    {
        m_timers[WUPDATE_WEATHERS].Reset();

        ///- Send an update signal to Weather objects
        WeatherMap::iterator itr, next;
        for (itr = m_weathers.begin(); itr != m_weathers.end(); itr = next)
        {
            next = itr;
            ++next;

            ///- and remove Weather objects for zones with no player
                                                            //As interval > WorldTick
            if(!itr->second->Update(m_timers[WUPDATE_WEATHERS].GetInterval()))
            {
                delete itr->second;
                m_weathers.erase(itr);
            }
        }
    }
    /// <li> Update uptime table
    if (m_timers[WUPDATE_UPTIME].Passed())
    {
        uint32 tmpDiff = (m_gameTime - m_startTime);
        uint32 maxClientsNum = GetMaxActiveSessionCount();

        m_timers[WUPDATE_UPTIME].Reset();
        loginDatabase.PExecute("UPDATE uptime SET uptime = %u, maxplayers = %u WHERE realmid = %u AND starttime = " UI64FMTD, tmpDiff, maxClientsNum, realmID, uint64(m_startTime));
    }

    /// <li> Clean logs table
    if(sWorld.getConfig(CONFIG_LOGDB_CLEARTIME) > 0) // if not enabled, ignore the timer
    {
        if (m_timers[WUPDATE_CLEANDB].Passed())
        {
            uint32 tmpDiff = (m_gameTime - m_startTime);
            uint32 maxClientsNum = sWorld.GetMaxActiveSessionCount();

            m_timers[WUPDATE_CLEANDB].Reset();
            loginDatabase.PExecute("DELETE FROM logs WHERE (time + %u) < "UI64FMTD";",
                sWorld.getConfig(CONFIG_LOGDB_CLEARTIME), uint64(time(0)));
        }
    }

    /// <li> Handle all other objects
    ///- Update objects when the timer has passed (maps, transport, creatures,...)
    MapManager::Instance().Update(diff);                // As interval = 0

    /*if(m_timers[WUPDATE_OBJECTS].Passed())
    {
        m_timers[WUPDATE_OBJECTS].Reset();
        MapManager::Instance().DoDelayedMovesAndRemoves();
    }*/

    static uint32 autobroadcaston = 0;
    autobroadcaston = sConfig.GetIntDefault("AutoBroadcast.On", 0);
    if(autobroadcaston == 1)
    {
       if (m_timers[WUPDATE_AUTOBROADCAST].Passed())
       {
          m_timers[WUPDATE_AUTOBROADCAST].Reset();
          SendRNDBroadcast();
       }
    }

    sBattleGroundMgr.Update(diff);
    RecordTimeDiff("UpdateBattleGroundMgr");


    sOutdoorPvPMgr.Update(diff);
    RecordTimeDiff("UpdateOutdoorPvPMgr");


    // execute callbacks from sql queries that were queued recently
    UpdateResultQueue();
    RecordTimeDiff("UpdateResultQueue");

    ///- Erase corpses once every 20 minutes
    if (m_timers[WUPDATE_CORPSES].Passed())
    {
        m_timers[WUPDATE_CORPSES].Reset();

        CorpsesErase();
    }

    ///- Process Game events when necessary
    if (m_timers[WUPDATE_EVENTS].Passed())
    {
        m_timers[WUPDATE_EVENTS].Reset();                   // to give time for Update() to be processed
        uint32 nextGameEvent = gameeventmgr.Update();
        m_timers[WUPDATE_EVENTS].SetInterval(nextGameEvent);
        m_timers[WUPDATE_EVENTS].Reset();
    }

    // update the instance reset times
    sInstanceSaveManager.Update();

    // And last, but not least handle the issued cli commands
    ProcessCliCommands();
}

void World::ForceGameEventUpdate()
{
    m_timers[WUPDATE_EVENTS].Reset();                   // to give time for Update() to be processed
    uint32 nextGameEvent = gameeventmgr.Update();
    m_timers[WUPDATE_EVENTS].SetInterval(nextGameEvent);
    m_timers[WUPDATE_EVENTS].Reset();
}

/// Send a packet to all players (except self if mentioned)
void World::SendGlobalMessage(WorldPacket *packet, WorldSession *self, uint32 team)
{
    SessionMap::const_iterator itr;
    for (itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
    {
        if (itr->second &&
            itr->second->GetPlayer() &&
            itr->second->GetPlayer()->IsInWorld() &&
            itr->second != self &&
            (team == 0 || itr->second->GetPlayer()->GetTeam() == team) )
        {
            itr->second->SendPacket(packet);
        }
    }
}

/// Send a packet to all GMs (except self if mentioned)
void World::SendGlobalGMMessage(WorldPacket *packet, WorldSession *self, uint32 team)
{
    SessionMap::iterator itr;
    for (itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
    {
        if (itr->second &&
            itr->second->GetPlayer() &&
            itr->second->GetPlayer()->IsInWorld() &&
            itr->second != self &&
            itr->second->GetSecurity() > SEC_PLAYER &&
            (team == 0 || itr->second->GetPlayer()->GetTeam() == team) )
        {
            itr->second->SendPacket(packet);
        }
    }
}

namespace MaNGOS
{
    class WorldWorldTextBuilder
    {
        public:
            typedef std::vector<WorldPacket*> WorldPacketList;
            explicit WorldWorldTextBuilder(int32 textId, va_list* args = NULL) : i_textId(textId), i_args(args) {}
            void operator()(WorldPacketList& data_list, int32 loc_idx)
            {
                char const* text = objmgr.GetMangosString(i_textId,loc_idx);

                if(i_args)
                {
                    // we need copy va_list before use or original va_list will corrupted
                    va_list ap;
                    va_copy(ap,*i_args);

                    char str [2048];
                    vsnprintf(str,2048,text, ap );
                    va_end(ap);

                    do_helper(data_list,&str[0]);
                }
                else
                    do_helper(data_list,(char*)text);
            }
        private:
            char* lineFromMessage(char*& pos) { char* start = strtok(pos,"\n"); pos = NULL; return start; }
            void do_helper(WorldPacketList& data_list, char* text)
            {
                char* pos = text;

                while(char* line = lineFromMessage(pos))
                {
                    WorldPacket* data = new WorldPacket();

                    uint32 lineLength = (line ? strlen(line) : 0) + 1;

                    data->Initialize(SMSG_MESSAGECHAT, 100);                // guess size
                    *data << uint8(CHAT_MSG_SYSTEM);
                    *data << uint32(LANG_UNIVERSAL);
                    *data << uint64(0);
                    *data << uint32(0);                                     // can be chat msg group or something
                    *data << uint64(0);
                    *data << uint32(lineLength);
                    *data << line;
                    *data << uint8(0);

                    data_list.push_back(data);
                }
            }

            int32 i_textId;
            va_list* i_args;
    };
}                                                           // namespace MaNGOS

/// Send a System Message to all players (except self if mentioned)
void World::SendWorldText(int32 string_id, ...)
{
    va_list ap;
    va_start(ap, string_id);

    MaNGOS::WorldWorldTextBuilder wt_builder(string_id, &ap);
    MaNGOS::LocalizedPacketListDo<MaNGOS::WorldWorldTextBuilder> wt_do(wt_builder);
    for(SessionMap::const_iterator itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
    {
        if(!itr->second || !itr->second->GetPlayer() || !itr->second->GetPlayer()->IsInWorld() )
            continue;

        wt_do(itr->second->GetPlayer());
    }

    va_end(ap);
}

/// Send a System Message to all GMs (except self if mentioned)
void World::SendGMText(int32 string_id, ...)
{
    va_list ap;
    va_start(ap, string_id);

    MaNGOS::WorldWorldTextBuilder wt_builder(string_id, &ap);
    MaNGOS::LocalizedPacketListDo<MaNGOS::WorldWorldTextBuilder> wt_do(wt_builder);
    for(SessionMap::iterator itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
    {
        if(!itr->second || !itr->second->GetPlayer() || !itr->second->GetPlayer()->IsInWorld() )
            continue;

        if(itr->second->GetSecurity() < SEC_MODERATOR )
            continue;

        wt_do(itr->second->GetPlayer());
    }

    va_end(ap);
}

/// DEPRICATED, only for debug purpose. Send a System Message to all players (except self if mentioned)
void World::SendGlobalText(const char* text, WorldSession *self)
{
    WorldPacket data;

    // need copy to prevent corruption by strtok call in LineFromMessage original string
    char* buf = strdup(text);
    char* pos = buf;

    while(char* line = ChatHandler::LineFromMessage(pos))
    {
        ChatHandler::FillMessageData(&data, NULL, CHAT_MSG_SYSTEM, LANG_UNIVERSAL, NULL, 0, line, NULL);
        SendGlobalMessage(&data, self);
    }

    free(buf);
}

/// Send a packet to all players (or players selected team) in the zone (except self if mentioned)
void World::SendZoneMessage(uint32 zone, WorldPacket *packet, WorldSession *self, uint32 team)
{
    SessionMap::const_iterator itr;
    for (itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
    {
        if (itr->second &&
            itr->second->GetPlayer() &&
            itr->second->GetPlayer()->IsInWorld() &&
            itr->second->GetPlayer()->GetZoneId() == zone &&
            itr->second != self &&
            (team == 0 || itr->second->GetPlayer()->GetTeam() == team) )
        {
            itr->second->SendPacket(packet);
        }
    }
}

/// Send a System Message to all players in the zone (except self if mentioned)
void World::SendZoneText(uint32 zone, const char* text, WorldSession *self, uint32 team)
{
    WorldPacket data;
    ChatHandler::FillMessageData(&data, NULL, CHAT_MSG_SYSTEM, LANG_UNIVERSAL, NULL, 0, text, NULL);
    SendZoneMessage(zone, &data, self,team);
}

/// Kick (and save) all players
void World::KickAll()
{
    m_QueuedPlayer.clear();                                 // prevent send queue update packet and login queued sessions

    // session not removed at kick and will removed in next update tick
    for (SessionMap::const_iterator itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
        itr->second->KickPlayer();
}

/// Kick (and save) all players with security level less `sec`
void World::KickAllLess(AccountTypes sec)
{
    // session not removed at kick and will removed in next update tick
    for (SessionMap::const_iterator itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
        if(itr->second->GetSecurity() < sec)
            itr->second->KickPlayer();
}

/// Ban an account or ban an IP address, duration will be parsed using TimeStringToSecs if it is positive, otherwise permban
BanReturn World::BanAccount(BanMode mode, std::string nameOrIP, std::string duration, std::string reason, std::string author)
{
    loginDatabase.escape_string(nameOrIP);
    loginDatabase.escape_string(reason);
    std::string safe_author=author;
    loginDatabase.escape_string(safe_author);

    uint32 duration_secs = TimeStringToSecs(duration);
    QueryResult *resultAccounts = NULL;                     //used for kicking

    ///- Update the database with ban information
    switch(mode)
    {
        case BAN_IP:
            //No SQL injection as strings are escaped
            resultAccounts = loginDatabase.PQuery("SELECT id FROM account WHERE last_ip = '%s'",nameOrIP.c_str());
            loginDatabase.PExecute("INSERT INTO ip_banned VALUES ('%s',UNIX_TIMESTAMP(),UNIX_TIMESTAMP()+%u,'%s','%s')",nameOrIP.c_str(),duration_secs,safe_author.c_str(),reason.c_str());
            break;
        case BAN_ACCOUNT:
            //No SQL injection as string is escaped
            resultAccounts = loginDatabase.PQuery("SELECT id FROM account WHERE username = '%s'",nameOrIP.c_str());
            break;
        case BAN_CHARACTER:
            //No SQL injection as string is escaped
            resultAccounts = CharacterDatabase.PQuery("SELECT account FROM characters WHERE name = '%s'",nameOrIP.c_str());
            break;
        default:
            return BAN_SYNTAX_ERROR;
    }

    if(!resultAccounts)
    {
        if(mode==BAN_IP)
            return BAN_SUCCESS;                             // ip correctly banned but nobody affected (yet)
        else
            return BAN_NOTFOUND;                                // Nobody to ban
    }

    ///- Disconnect all affected players (for IP it can be several)
    do
    {
        Field* fieldsAccount = resultAccounts->Fetch();
        uint32 account = fieldsAccount->GetUInt32();

        if(mode!=BAN_IP)
        {
            //No SQL injection as strings are escaped
            loginDatabase.PExecute("INSERT INTO account_banned VALUES ('%u', UNIX_TIMESTAMP(), UNIX_TIMESTAMP()+%u, '%s', '%s', '1')",
                account,duration_secs,safe_author.c_str(),reason.c_str());
        }

        if (WorldSession* sess = FindSession(account))
            if(std::string(sess->GetPlayerName()) != author)
                sess->KickPlayer();
    }
    while( resultAccounts->NextRow() );

    delete resultAccounts;
    return BAN_SUCCESS;
}

/// Remove a ban from an account or IP address
bool World::RemoveBanAccount(BanMode mode, std::string nameOrIP)
{
    if (mode == BAN_IP)
    {
        loginDatabase.escape_string(nameOrIP);
        loginDatabase.PExecute("DELETE FROM ip_banned WHERE ip = '%s'",nameOrIP.c_str());
    }
    else
    {
        uint32 account = 0;
        if (mode == BAN_ACCOUNT)
            account = accmgr.GetId (nameOrIP);
        else if (mode == BAN_CHARACTER)
            account = objmgr.GetPlayerAccountIdByPlayerName (nameOrIP);

        if (!account)
            return false;

        //NO SQL injection as account is uint32
        loginDatabase.PExecute("UPDATE account_banned SET active = '0' WHERE id = '%u'",account);
    }
    return true;
}

/// Update the game time
void World::_UpdateGameTime()
{
    ///- update the time
    time_t thisTime = time(NULL);
    uint32 elapsed = uint32(thisTime - m_gameTime);
    m_gameTime = thisTime;

    ///- if there is a shutdown timer
    if(!m_stopEvent && m_ShutdownTimer > 0 && elapsed > 0)
    {
        ///- ... and it is overdue, stop the world (set m_stopEvent)
        if( m_ShutdownTimer <= elapsed )
        {
            if(!(m_ShutdownMask & SHUTDOWN_MASK_IDLE) || GetActiveAndQueuedSessionCount()==0)
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
void World::ShutdownServ(uint32 time, uint32 options, uint8 exitcode)
{
    // ignore if server shutdown at next tick
    if(m_stopEvent)
        return;

    m_ShutdownMask = options;
    m_ExitCode = exitcode;

    ///- If the shutdown time is 0, set m_stopEvent (except if shutdown is 'idle' with remaining sessions)
    if(time==0)
    {
        if(!(options & SHUTDOWN_MASK_IDLE) || GetActiveAndQueuedSessionCount()==0)
            m_stopEvent = true;                             // exist code already set
        else
            m_ShutdownTimer = 1;                            //So that the session count is re-evaluated at next world tick
    }
    ///- Else set the shutdown timer and warn users
    else
    {
        m_ShutdownTimer = time;
        ShutdownMsg(true);
    }
}

/// Display a shutdown message to the user(s)
void World::ShutdownMsg(bool show, Player* player)
{
    // not show messages for idle shutdown mode
    if(m_ShutdownMask & SHUTDOWN_MASK_IDLE)
        return;

    ///- Display a message every 12 hours, hours, 5 minutes, minute, 5 seconds and finally seconds
    if ( show ||
        (m_ShutdownTimer < 10) ||
                                                            // < 30 sec; every 5 sec
        (m_ShutdownTimer<30        && (m_ShutdownTimer % 5         )==0) ||
                                                            // < 5 min ; every 1 min
        (m_ShutdownTimer<5*MINUTE  && (m_ShutdownTimer % MINUTE    )==0) ||
                                                            // < 30 min ; every 5 min
        (m_ShutdownTimer<30*MINUTE && (m_ShutdownTimer % (5*MINUTE))==0) ||
                                                            // < 12 h ; every 1 h
        (m_ShutdownTimer<12*HOUR   && (m_ShutdownTimer % HOUR      )==0) ||
                                                            // > 12 h ; every 12 h
        (m_ShutdownTimer>12*HOUR   && (m_ShutdownTimer % (12*HOUR) )==0))
    {
        std::string str = secsToTimeString(m_ShutdownTimer);

        ServerMessageType msgid = (m_ShutdownMask & SHUTDOWN_MASK_RESTART) ? SERVER_MSG_RESTART_TIME : SERVER_MSG_SHUTDOWN_TIME;

        SendServerMessage(msgid,str.c_str(),player);
        DEBUG_LOG("Server is %s in %s",(m_ShutdownMask & SHUTDOWN_MASK_RESTART ? "restart" : "shuttingdown"),str.c_str());
    }
}

/// Cancel a planned server shutdown
void World::ShutdownCancel()
{
    // nothing cancel or too later
    if(!m_ShutdownTimer || m_stopEvent)
        return;

    ServerMessageType msgid = (m_ShutdownMask & SHUTDOWN_MASK_RESTART) ? SERVER_MSG_RESTART_CANCELLED : SERVER_MSG_SHUTDOWN_CANCELLED;

    m_ShutdownMask = 0;
    m_ShutdownTimer = 0;
    m_ExitCode = SHUTDOWN_EXIT_CODE;                       // to default value
    SendServerMessage(msgid);

    DEBUG_LOG("Server %s cancelled.",(m_ShutdownMask & SHUTDOWN_MASK_RESTART ? "restart" : "shuttingdown"));
}

/// Send a server message to the user(s)
void World::SendServerMessage(ServerMessageType type, const char *text, Player* player)
{
    WorldPacket data(SMSG_SERVER_MESSAGE, 50);              // guess size
    data << uint32(type);
    if(type <= SERVER_MSG_STRING)
        data << text;

    if(player)
        player->GetSession()->SendPacket(&data);
    else
        SendGlobalMessage( &data );
}

void World::UpdateSessions( uint32 diff )
{
    ///- Add new sessions
    while(!addSessQueue.empty())
    {
        WorldSession* sess = addSessQueue.next ();
        AddSession_ (sess);
    }

    ///- Then send an update signal to remaining ones
    for (SessionMap::iterator itr = m_sessions.begin(), next; itr != m_sessions.end(); itr = next)
    {
        next = itr;
        ++next;

        if(!itr->second)
            continue;

        ///- and remove not active sessions from the list
        if(!itr->second->Update(diff))                      // As interval = 0
        {
            if(!RemoveQueuedPlayer(itr->second) && itr->second && getConfig(CONFIG_INTERVAL_DISCONNECT_TOLERANCE))
                m_disconnects[itr->second->GetAccountId()] = time(NULL);
            delete itr->second;
            m_sessions.erase(itr);
        }
    }
}

// This handles the issued and queued CLI commands
void World::ProcessCliCommands()
{
    if (cliCmdQueue.empty())
        return;

    CliCommandHolder::Print* zprint;

    while (!cliCmdQueue.empty())
    {
        sLog.outDebug("CLI command under processing...");
        CliCommandHolder *command = cliCmdQueue.next();

        zprint = command->m_print;

        CliHandler(zprint).ParseCommands(command->m_command);

        delete command;
    }

    // print the console message here so it looks right
    zprint("TC> ");
}

void World::SendRNDBroadcast()
{
    if(m_Autobroadcasts.empty())
        return;

    std::string msg;

    std::list<std::string>::const_iterator itr = m_Autobroadcasts.begin();
    std::advance(itr, rand() % m_Autobroadcasts.size());
    msg = *itr;

    static uint32 abcenter = 0;
    abcenter = sConfig.GetIntDefault("AutoBroadcast.Center", 0);
    if(abcenter == 0)
    {
        sWorld.SendWorldText(LANG_AUTO_BROADCAST, msg.c_str());

        sLog.outString("AutoBroadcast: '%s'",msg.c_str());
    }
    if(abcenter == 1)
    {
        WorldPacket data(SMSG_NOTIFICATION, (msg.size()+1));
        data << msg;
        sWorld.SendGlobalMessage(&data);

        sLog.outString("AutoBroadcast: '%s'",msg.c_str());
    }
    if(abcenter == 2)
    {
        sWorld.SendWorldText(LANG_AUTO_BROADCAST, msg.c_str());

        WorldPacket data(SMSG_NOTIFICATION, (msg.size()+1));
        data << msg;
        sWorld.SendGlobalMessage(&data);

        sLog.outString("AutoBroadcast: '%s'",msg.c_str());
    }
}

void World::InitResultQueue()
{
    m_resultQueue = new SqlResultQueue;
    CharacterDatabase.SetResultQueue(m_resultQueue);
}

void World::UpdateResultQueue()
{
    m_resultQueue->Update();
}

void World::UpdateRealmCharCount(uint32 accountId)
{
    CharacterDatabase.AsyncPQuery(this, &World::_UpdateRealmCharCount, accountId,
        "SELECT COUNT(guid) FROM characters WHERE account = '%u'", accountId);
}

void World::_UpdateRealmCharCount(QueryResult *resultCharCount, uint32 accountId)
{
    if (resultCharCount)
    {
        Field *fields = resultCharCount->Fetch();
        uint32 charCount = fields[0].GetUInt32();
        delete resultCharCount;
        loginDatabase.PExecute("DELETE FROM realmcharacters WHERE acctid= '%d' AND realmid = '%d'", accountId, realmID);
        loginDatabase.PExecute("INSERT INTO realmcharacters (numchars, acctid, realmid) VALUES (%u, %u, %u)", charCount, accountId, realmID);
    }
}

void World::InitDailyQuestResetTime()
{
    time_t mostRecentQuestTime;

    QueryResult* result = CharacterDatabase.Query("SELECT MAX(time) FROM character_queststatus_daily");
    if(result)
    {
        Field *fields = result->Fetch();

        mostRecentQuestTime = (time_t)fields[0].GetUInt64();
        delete result;
    }
    else
        mostRecentQuestTime = 0;

    // client built-in time for reset is 6:00 AM
    // FIX ME: client not show day start time
    time_t curTime = time(NULL);
    tm localTm = *localtime(&curTime);
    localTm.tm_hour = 6;
    localTm.tm_min  = 0;
    localTm.tm_sec  = 0;

    // current day reset time
    time_t curDayResetTime = mktime(&localTm);

    // last reset time before current moment
    time_t resetTime = (curTime < curDayResetTime) ? curDayResetTime - DAY : curDayResetTime;

    // need reset (if we have quest time before last reset time (not processed by some reason)
    if(mostRecentQuestTime && mostRecentQuestTime <= resetTime)
        m_NextDailyQuestReset = mostRecentQuestTime;
    else
    {
        // plan next reset time
        m_NextDailyQuestReset = (curTime >= curDayResetTime) ? curDayResetTime + DAY : curDayResetTime;
    }
}

void World::ResetDailyQuests()
{
    sLog.outDetail("Daily quests reset for all characters.");
    CharacterDatabase.Execute("DELETE FROM character_queststatus_daily");
    for(SessionMap::const_iterator itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
        if(itr->second->GetPlayer())
            itr->second->GetPlayer()->ResetDailyQuestStatus();
}

void World::UpdateAllowedSecurity()
{
    QueryResult *result = loginDatabase.PQuery("SELECT allowedSecurityLevel from realmlist WHERE id = '%d'", realmID);
    if (result)
    {
        m_allowedSecurityLevel = AccountTypes(result->Fetch()->GetUInt16());
        sLog.outDebug("Allowed Level: %u Result %u", m_allowedSecurityLevel, result->Fetch()->GetUInt16());
        delete result;
    }
}

void World::SetPlayerLimit( int32 limit, bool needUpdate )
{
    m_playerLimit = limit;
}

void World::UpdateMaxSessionCounters()
{
    m_maxActiveSessionCount = std::max(m_maxActiveSessionCount,uint32(m_sessions.size()-m_QueuedPlayer.size()));
    m_maxQueuedSessionCount = std::max(m_maxQueuedSessionCount,uint32(m_QueuedPlayer.size()));
}

void World::LoadDBVersion()
{
    QueryResult* result = WorldDatabase.Query("SELECT db_version, script_version, cache_id FROM version LIMIT 1");
    //QueryResult* result = WorldDatabase.Query("SELECT version, creature_ai_version, cache_id FROM db_version LIMIT 1");
    if(result)
    {
        Field* fields = result->Fetch();

        m_DBVersion              = fields[0].GetCppString();
        m_CreatureEventAIVersion = fields[1].GetCppString();

        // will be overwrite by config values if different and non-0
        m_configs[CONFIG_CLIENTCACHE_VERSION] = fields[2].GetUInt32();
        delete result;
    }

    if(m_DBVersion.empty())
        m_DBVersion = "Unknown world database.";

    if(m_CreatureEventAIVersion.empty())
        m_CreatureEventAIVersion = "Unknown creature EventAI.";
}
