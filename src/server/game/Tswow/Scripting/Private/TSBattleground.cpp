/*
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 * Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
 * 
 * This program is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#include <memory.h>
#include "Object.h"
#include "Battleground.h"

#include "TSIncludes.h"
#include "TSBattleground.h"
#include "TSMap.h"
#include "Map.h"

TSBattleground::TSBattleground(Battleground *bg)
{
    this->bg = bg;
}

TSBattleground::TSBattleground()
{
    this->bg = nullptr;
}

/**
 * Returns the name of the [BattleGround].
 *
 * @return string name
 */
TSString TSBattleground::GetName()
{
     return TSString(bg->GetName());
}
    
/**
 * Returns the amount of alive players in the [BattleGround] by the team ID.
 *
 * @param [Team] team : team ID
 * @return uint32 count
 */
uint32 TSBattleground::GetAlivePlayersCountByTeam(uint32 team) 
{
    
#ifndef AZEROTHCORE
    return bg->GetAlivePlayersCountByTeam((Team)team);
#else
    return bg->GetAlivePlayersCountByTeam((TeamId)team);
#endif
}
    
/**
 * Returns the [Map] of the [BattleGround].
 *
 * @return [Map] map
 */
TSMap  TSBattleground::GetMap() 
{
     return TSMap(bg->GetBgMap());
}
    
/**
 * Returns the bonus honor given by amount of kills in the specific [BattleGround].
 *
 * @param uint32 kills : amount of kills
 * @return uint32 bonusHonor
 */
uint32 TSBattleground::GetBonusHonorFromKillCount(uint32 kills) 
{
    return bg->GetBonusHonorFromKill(kills);
}
    
#ifndef AZEROTHCORE
/**
 * Returns the bracket ID of the specific [BattleGround].
 *
 * @return [BattleGroundBracketId] bracketId
 */
uint32 TSBattleground::GetBracketId() 
{
    return bg->GetBracketId();
}
#endif
    
/**
 * Returns the end time of the [BattleGround].
 *
 * @return uint32 endTime
 */
uint32 TSBattleground::GetEndTime() 
{
#ifdef CATA
    return bg->GetRemainingTime();
#else
    return bg->GetEndTime();
#endif
}
    
/**
 * Returns the amount of free slots for the selected team in the specific [BattleGround].
 *
 * @param [Team] team : team ID
 * @return uint32 freeSlots
 */
uint32 TSBattleground::GetFreeSlotsForTeam(uint32 team) 
{
    
#ifndef AZEROTHCORE
    return bg->GetFreeSlotsForTeam((Team)team);
#else
    return bg->GetFreeSlotsForTeam((TeamId)team);
#endif
}
    
/**
 * Returns the instance ID of the [BattleGround].
 *
 * @return uint32 instanceId
 */
uint32 TSBattleground::GetInstanceId() 
{
    return bg->GetInstanceID();
}
    
/**
 * Returns the map ID of the [BattleGround].
 *
 * @return uint32 mapId
 */
uint32 TSBattleground::GetMapId() 
{
    return bg->GetMapId();
}
    
/**
 * Returns the type ID of the [BattleGround].
 *
 * @return [BattleGroundTypeId] typeId
 */
uint32 TSBattleground::GetTypeId() 
{
#ifndef AZEROTHCORE
    return bg->GetTypeID();
#else
    return bg->GetBgTypeID();
#endif
}
    
/**
 * Returns the max allowed [Player] level of the specific [BattleGround].
 *
 * @return uint32 maxLevel
 */
uint32 TSBattleground::GetMaxLevel() 
{
    return bg->GetMaxLevel();
}
    
/**
 * Returns the minimum allowed [Player] level of the specific [BattleGround].
 *
 * @return uint32 minLevel
 */
uint32 TSBattleground::GetMinLevel() 
{
    return bg->GetMinLevel();
}
    
/**
 * Returns the maximum allowed [Player] count of the specific [BattleGround].
 *
 * @return uint32 maxPlayerCount
 */
uint32 TSBattleground::GetMaxPlayers() 
{
#ifndef AZEROTHCORE
    return bg->GetMaxPlayers();
#else
    return bg->GetMaxPlayersPerTeam() * 2;
#endif
}
    
/**
 * Returns the minimum allowed [Player] count of the specific [BattleGround].
 *
 * @return uint32 minPlayerCount
 */
uint32 TSBattleground::GetMinPlayers() 
{
#ifndef AZEROTHCORE
    return bg->GetMinPlayers();
#else
    return bg->GetMaxPlayersPerTeam() * 2;
#endif
}
    
/**
 * Returns the maximum allowed [Player] count per team of the specific [BattleGround].
 *
 * @return uint32 maxTeamPlayerCount
 */
uint32 TSBattleground::GetMaxPlayersPerTeam() 
{
    return bg->GetMaxPlayersPerTeam();
}
    
/**
 * Returns the minimum allowed [Player] count per team of the specific [BattleGround].
 *
 * @return uint32 minTeamPlayerCount
 */
uint32 TSBattleground::GetMinPlayersPerTeam() 
{
    return bg->GetMinPlayersPerTeam();
}
    
/**
 * Returns the winning team of the specific [BattleGround].
 *
 * @return [Team] team
 */
uint32 TSBattleground::GetWinner() 
{
    return bg->GetWinner();
}
    
/**
 * Returns the status of the specific [BattleGround].
 *
 * @return [BattleGroundStatus] status
 */
uint32 TSBattleground::GetStatus() 
{
    return bg->GetStatus();
}
