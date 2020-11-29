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
#include "TSIncludes.h"
#include "TSMap.h"
#include "Map.h"
#include "Weather.h"
#include "Corpse.h"
#include "DynamicObject.h"
#include "Pet.h"

#include "TSMap.h"
#include "TSPlayer.h"
#include "TSWorldObject.h"

TSMap::TSMap(Map *map)
{
    this->map = map;
}

    
#ifndef CLASSIC
/**
 * Returns `true` if the [Map] is an arena [BattleGround], `false` otherwise.
 *
 * @return bool isArena
 */
bool TSMap::IsArena() 
{
    return map->IsBattleArena();
}
#endif
    
/**
 * Returns `true` if the [Map] is a non-arena [BattleGround], `false` otherwise.
 *
 * @return bool isBattleGround
 */
bool TSMap::IsBattleground() 
{
#if defined TRINITY || AZEROTHCORE
    return map->IsBattleground();
#else
    return map->IsBattleGround();
#endif
}
    
/**
 * Returns `true` if the [Map] is a dungeon, `false` otherwise.
 *
 * @return bool isDungeon
 */
bool TSMap::IsDungeon() 
{
    return map->IsDungeon();
}
    
/**
 * Returns `true` if the [Map] has no [Player]s, `false` otherwise.
 *
 * @return bool isEmpty
 */
bool TSMap::IsEmpty() 
{
    return map->isEmpty();
}
    
#ifndef CLASSIC
/**
 * Returns `true` if the [Map] is a heroic, `false` otherwise.
 *
 * @return bool isHeroic
 */
bool TSMap::IsHeroic() 
{
    return map->IsHeroic();
}
#endif
    
/**
 * Returns `true` if the [Map] is a raid, `false` otherwise.
 *
 * @return bool isRaid
 */
bool TSMap::IsRaid() 
{
    return map->IsRaid();
}
    
/**
 * Returns the name of the [Map].
 *
 * @return string mapName
 */
TSString TSMap::GetName()
{
     return TSString(map->GetMapName());
}
    
/**
 * Returns the height of the [Map] at the given X and Y coordinates.
 *
 * In case of no height found nil is returned
 *
 * @param float x
 * @param float y
 * @return float z
 */
float TSMap::GetHeight(float x,float y,uint32 phasemask) 
{
#if (defined(TBC) || defined(CLASSIC))
    float z = map->GetHeight(x, y, MAX_HEIGHT);
#else
    float z = map->GetHeight(phasemask, x, y, MAX_HEIGHT);
#endif
    if (z != INVALID_HEIGHT)
        return z;
}
    
/**
 * Returns the difficulty of the [Map].
 *
 * Always returns 0 if the expansion is pre-TBC.
 *
 * @return int32 difficulty
 */
int32 TSMap::GetDifficulty() 
{
#ifndef CLASSIC
    return map->GetDifficulty();
#else
    return (Difficulty)0;
#endif
}
    
/**
 * Returns the instance ID of the [Map].
 *
 * @return uint32 instanceId
 */
uint32 TSMap::GetInstanceId() 
{
    return map->GetInstanceId();
}
    
/**
 * Returns the player count currently on the [Map] (excluding GMs).
 *
 * @return uint32 playerCount
 */
uint32 TSMap::GetPlayerCount() 
{
    return map->GetPlayersCountExceptGMs();
}
    
/**
 * Returns the ID of the [Map].
 *
 * @return uint32 mapId
 */
uint32 TSMap::GetMapId() 
{
    return map->GetId();
}
    
/**
 * Returns the area ID of the [Map] at the specified X, Y, and Z coordinates.
 *
 * @param float x
 * @param float y
 * @param float z
 * @param uint32 phasemask = PHASEMASK_NORMAL
 * @return uint32 areaId
 */
uint32 TSMap::GetAreaId(float x,float y,float z,float phasemask) 
{
#if defined TRINITY
    return map->GetAreaId(phasemask, x, y, z);
#elif defined AZEROTHCORE
    return map->GetAreaId(x, y, z);
#else
    return map->GetTerrain()->GetAreaId(x, y, z);
#endif
}
    
/**
 * Returns a [WorldObject] by its GUID from the map if it is spawned.
 *
 * @param uint64 guid
 */
TSWorldObject  TSMap::GetWorldObject(uint64 guid) 
{
    
#if defined TRINITY || AZEROTHCORE
    switch (GUID_HIPART(guid))
    {
        case HIGHGUID_PLAYER:
#ifndef AZEROTHCORE
             return TSWorldObject(eObjectAccessor()GetPlayer(map, ObjectGuid(guid)));
#else
             return TSWorldObject(map->GetPlayer(ObjectGuid(guid)));
#endif // !AZEROTHCORE
            break;
        case HIGHGUID_TRANSPORT:
        case HIGHGUID_MO_TRANSPORT:
        case HIGHGUID_GAMEOBJECT:
             return TSWorldObject(map->GetGameObject(ObjectGuid(guid)));
            break;
        case HIGHGUID_VEHICLE:
        case HIGHGUID_UNIT:
             return TSWorldObject(map->GetCreature(ObjectGuid(guid)));
            break;
        case HIGHGUID_PET:
             return TSWorldObject(map->GetPet(ObjectGuid(guid)));
            break;
        case HIGHGUID_DYNAMICOBJECT:
             return TSWorldObject(map->GetDynamicObject(ObjectGuid(guid)));
            break;
        case HIGHGUID_CORPSE:
             return TSWorldObject(map->GetCorpse(ObjectGuid(guid)));
            break;
        default:
            break;
    }
#else
     return TSWorldObject(map->GetWorldObject(ObjectGuid(guid)));
#endif
}
    
/**
 * Sets the [Weather] type based on [WeatherType] and grade supplied.
 *
 *     enum WeatherType
 *     {
 *         WEATHER_TYPE_FINE       = 0,
 *         WEATHER_TYPE_RAIN       = 1,
 *         WEATHER_TYPE_SNOW       = 2,
 *         WEATHER_TYPE_STORM      = 3,
 *         WEATHER_TYPE_THUNDERS   = 86,
 *         WEATHER_TYPE_BLACKRAIN  = 90
 *
 * @param uint32 zone : id of the zone to set the weather for
 * @param [WeatherType] type : the [WeatherType], see above available weather types
 * @param float grade : the intensity/grade of the [Weather], ranges from 0 to 1
 */
void TSMap::SetWeather(uint32 zoneId,uint32 weatherType,float grade) 
{
    (void)map; // ensure that the variable is referenced in order to pass compiler checks
    
#if defined TRINITY
    if (Weather * weather = map->GetOrGenerateZoneDefaultWeather(zoneId))
        weather->SetWeather((WeatherType)weatherType, grade);
#elif defined AZEROTHCORE
    Weather* weather = WeatherMgr::FindWeather(zoneId);
    if (!weather)
        weather = WeatherMgr::AddWeather(zoneId);
    if (weather)
        weather->SetWeather((WeatherType)weatherType, grade);
#else
    if (Weather::IsValidWeatherType(weatherType))
        map->SetWeather(zoneId, (WeatherType)weatherType, grade, false);
#endif
}
    
/**
* Returns a table with all the current [Player]s in the map
*
*     enum TeamId
*     {
*         TEAM_ALLIANCE = 0,
*         TEAM_HORDE = 1,
*         TEAM_NEUTRAL = 2
*
* @param [TeamId] team : optional check team of the [Player], Alliance, Horde or Neutral (All)
* @return table mapPlayers
*/
TSArray<TSPlayer> TSMap::GetPlayers(uint32 team) 
{
    
    TSArray<TSPlayer> tbl;
    
    Map::PlayerList const& players = map->GetPlayers();
    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
    {
#if defined TRINITY || AZEROTHCORE
        Player* player = itr->GetSource();
#else
        Player* player = itr->getSource();
#endif
        if (!player)
            continue;
        if (player->GetSession() && (team >= TEAM_NEUTRAL || player->GetTeamId() == team))
        {
            tbl.push(TSPlayer(player));
        }
    }
    
    return tbl;
}
