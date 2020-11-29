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
#include "TSWorldObject.h"
#include "TSArray.h"
#include "TSCreature.h"
#include "TSPlayer.h"
#include "TSWorldObject.h"
#include "TSGameObject.h"
#include "TSWorldPacket.h"
#include "TSWorldObject.h"
#include "TSMap.h"

TSWorldObject::TSWorldObject(WorldObject *obj) : TSObject(obj)
{
    this->obj = obj;
}

TSWorldObject::TSWorldObject() : TSObject()
{
    this->obj = nullptr;
}

/**
 * Returns the name of the [WorldObject]
 *
 * @return string name
 */
TSString TSWorldObject::GetName()
{
     return TSString(obj->GetName());
}
    
/**
 * Returns the current [Map] object of the [WorldObject]
 *
 * @return [Map] mapObject
 */
TSMap  TSWorldObject::GetMap() 
{
     return TSMap(obj->GetMap());
}
    
#if (!defined(TBC) && !defined(CLASSIC))
/**
 * Returns the current phase of the [WorldObject]
 *
 * @return uint32 phase
 */
uint32 TSWorldObject::GetPhaseMask() 
{
    return obj->GetPhaseMask();
}
    
/**
* Sets the [WorldObject]'s phase mask.
*
* @param uint32 phaseMask
* @param bool update = true : update visibility to nearby objects
*/
void TSWorldObject::SetPhaseMask(uint32 phaseMask,bool update) 
{
    obj->SetPhaseMask(phaseMask, update);
}
#endif
    
/**
 * Returns the current instance ID of the [WorldObject]
 *
 * @return uint32 instanceId
 */
uint32 TSWorldObject::GetInstanceId() 
{
    return obj->GetInstanceId();
}
    
/**
 * Returns the current area ID of the [WorldObject]
 *
 * @return uint32 areaId
 */
uint32 TSWorldObject::GetAreaId() 
{
    return obj->GetAreaId();
}
    
/**
 * Returns the current zone ID of the [WorldObject]
 *
 * @return uint32 zoneId
 */
uint32 TSWorldObject::GetZoneId() 
{
    return obj->GetZoneId();
}
    
/**
 * Returns the current map ID of the [WorldObject]
 *
 * @return uint32 mapId
 */
uint32 TSWorldObject::GetMapId() 
{
    return obj->GetMapId();
}
    
/**
 * Returns the current X coordinate of the [WorldObject]
 *
 * @return float x
 */
float TSWorldObject::GetX() 
{
    return obj->GetPositionX();
}
    
/**
 * Returns the current Y coordinate of the [WorldObject]
 *
 * @return float y
 */
float TSWorldObject::GetY() 
{
    return obj->GetPositionY();
}
    
/**
 * Returns the current Z coordinate of the [WorldObject]
 *
 * @return float z
 */
float TSWorldObject::GetZ() 
{
    return obj->GetPositionZ();
}
    
/**
 * Returns the current orientation of the [WorldObject]
 *
 * @return float orientation / facing
 */
float TSWorldObject::GetO() 
{
    return obj->GetOrientation();
}
    
/**
 * Returns the coordinates and orientation of the [WorldObject]
 *
 * @return float x : x coordinate of the [WorldObject]
#endif
    
    TSArray<TSWorldObject> tbl;
    uint32 i = 0;
    
    for (std::list<WorldObject*>::const_iterator it = list.begin(); it != list.end(); ++it)
    {
        tbl.push(TSWorldObject(*it));
    }

    return tbl;
}
    
/**
 * Returns the distance from this [WorldObject] to another [WorldObject], or from this [WorldObject] to a point in 3d space.
 *
 * The function takes into account the given object sizes. See also [WorldObject:GetExactDistance], [WorldObject:GetDistance2d]
 *
 * @proto dist = (obj)
 * @proto dist = (x, y, z)
 *
 * @param [WorldObject] obj
 * @param float x : the X-coordinate of the point
 * @param float y : the Y-coordinate of the point
 * @param float z : the Z-coordinate of the point
 *
 * @return float dist : the distance in yards
 */
float TSWorldObject::GetDistance(TSWorldObject _target,float X,float Y,float Z)
{
    auto target = _target.obj;
    if (target)
        return obj->GetDistance(target);
    else
    {
        return obj->GetDistance(X, Y, Z);
    }
}
    
/**
 * Returns the distance from this [WorldObject] to another [WorldObject], or from this [WorldObject] to a point in 3d space.
 *
 * The function does not take into account the given object sizes, which means only the object coordinates are compared. See also [WorldObject:GetDistance], [WorldObject:GetDistance2d]
 *
 * @proto dist = (obj)
 * @proto dist = (x, y, z)
 *
 * @param [WorldObject] obj
 * @param float x : the X-coordinate of the point
 * @param float y : the Y-coordinate of the point
 * @param float z : the Z-coordinate of the point
 *
 * @return float dist : the distance in yards
 */

/*
float TSWorldObject::GetExactDistance(TSWorldObject _target, float x1, float y1, float z1)
{
    auto target = _target.obj;
    float x, y, z;
    obj->GetPosition(x, y, z);
    if (target)
    {
        float x2, y2, z2;
        target->GetPosition(x2, y2, z2);
        x -= x2;
        y -= y2;
        z -= z2;
    }
    else
    {
        x -= x1;
        y -= y1;
        z -= z1;
    }
    return std::sqrt(x*x + y*y + z*z);
}
*/
    
/**
 * Returns the distance from this [WorldObject] to another [WorldObject], or from this [WorldObject] to a point in 2d space.
 *
 * The function takes into account the given object sizes. See also [WorldObject:GetDistance], [WorldObject:GetExactDistance2d]
 *
 * @proto dist = (obj)
 * @proto dist = (x, y)
 *
 * @param [WorldObject] obj
 * @param float x : the X-coordinate of the point
 * @param float y : the Y-coordinate of the point
 *
 * @return float dist : the distance in yards
 */
float TSWorldObject::GetDistance2d(TSWorldObject _target,float X,float Y)
{
    auto target = _target.obj;
    if (target)
        return obj->GetDistance2d(target);
    else
    {
        return obj->GetDistance2d(X, Y);
    }
}
    
/**
 * Returns the distance from this [WorldObject] to another [WorldObject], or from this [WorldObject] to a point in 2d space.
 *
 * The function does not take into account the given object sizes, which means only the object coordinates are compared. See also [WorldObject:GetDistance], [WorldObject:GetDistance2d]
 *
 * @proto dist = (obj)
 * @proto dist = (x, y)
 *
 * @param [WorldObject] obj
 * @param float x : the X-coordinate of the point
 * @param float y : the Y-coordinate of the point
 *
 * @return float dist : the distance in yards
 */
    
/**
 * Returns the x, y and z of a point dist away from the [WorldObject].
 *
 * @param float distance : specifies the distance of the point from the [WorldObject] in yards
 * @param float angle : specifies the angle of the point relative to the orientation / facing of the [WorldObject] in radians
 *
 * @return float x
 * @return float y
 * @return float z
 */
float TSWorldObject::GetRelativePoint(float dist,float rad) 
{
    
    float x, y, z;
    obj->GetClosePoint(x, y, z, 0.0f, dist, rad);
    return x;
    return y;
    return z;
}
    
/**
 * Returns the angle between this [WorldObject] and another [WorldObject] or a point.
 *
 * The angle is the angle between two points and orientation will be ignored.
 *
 * @proto dist = (obj)
 * @proto dist = (x, y)
 *
 * @param [WorldObject] object
 * @param float x
 * @param float y
 *
 * @return float angle : angle in radians in range 0..2*pi
 */
float TSWorldObject::GetAngle(TSWorldObject _target,float x,float y)
{
    auto target = _target.obj;
#if defined TRINITY && !AZEROTHCORE
    if (target)
        return obj->GetAbsoluteAngle(target);
    else
    {
        return obj->GetAbsoluteAngle(x, y);
    }
#else
    if (target)
        return obj->GetAngle(target);
    else
    {
        return obj->GetAngle(x, y);
    }
#endif
}
    
/**
 * Sends a [WorldPacket] to [Player]s in sight of the [WorldObject].
 *
 * @param [WorldPacket] packet
 */
void TSWorldObject::SendPacket(TSWorldPacket _data)
{
    auto data = _data.packet;
#ifdef CMANGOS
    obj->SendMessageToSet(*data, true);
#else
    obj->SendMessageToSet(data, true);
#endif
}
    
/**
 * Spawns a [GameObject] at specified location.
 *
 * @param uint32 entry : [GameObject] entry ID
 * @param float x
 * @param float y
 * @param float z
 * @param float o
 * @param uint32 respawnDelay = 30 : respawn time in seconds
 * @return [GameObject] gameObject
 */
TSGameObject  TSWorldObject::SummonGameObject(uint32 entry,float x,float y,float z,float o,uint32 respawnDelay) 
{
#ifdef TRINITY
    QuaternionData rot = QuaternionData::fromEulerAnglesZYX(o, 0.f, 0.f);
     // TODO Fix
    return TSGameObject(nullptr);
     //return TSGameObject(obj->SummonGameObject(entry, Position(x, y, z, o), rot, respawnDelay));
#elif AZEROTHCORE
     return TSGameObject(obj->SummonGameObject(entry, x, y, z, o, 0, 0, 0, 0, respawnDelay));
#else
     return TSGameObject(obj->SummonGameObject(entry, x, y, z, o, respawnDelay));
#endif
}
    
/**
 * Spawns the creature at specified location.
 *
 *     enum TempSummonType
 *     {
 *         TEMPSUMMON_TIMED_OR_DEAD_DESPAWN       = 1, // despawns after a specified time OR when the creature disappears
 *         TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN     = 2, // despawns after a specified time OR when the creature dies
 *         TEMPSUMMON_TIMED_DESPAWN               = 3, // despawns after a specified time
 *         TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT = 4, // despawns after a specified time after the creature is out of combat
 *         TEMPSUMMON_CORPSE_DESPAWN              = 5, // despawns instantly after death
 *         TEMPSUMMON_CORPSE_TIMED_DESPAWN        = 6, // despawns after a specified time after death
 *         TEMPSUMMON_DEAD_DESPAWN                = 7, // despawns when the creature disappears
 *         TEMPSUMMON_MANUAL_DESPAWN              = 8, // despawnswhen TSWorldObject::UnSummon() is called
 *         TEMPSUMMON_TIMED_OOC_OR_CORPSE_DESPAWN = 9, // despawns after a specified time (OOC) OR when the creature dies
 *         TEMPSUMMON_TIMED_OOC_OR_DEAD_DESPAWN   = 10 // despawns after a specified time (OOC) OR when the creature disappears
 *
 * @param uint32 entry : [Creature]'s entry ID
 * @param float x
 * @param float y
 * @param float z
 * @param float o
 * @param [TempSummonType] spawnType = MANUAL_DESPAWN : defines how and when the creature despawns
 * @param uint32 despawnTimer = 0 : despawn time in milliseconds
 * @return [Creature] spawnedCreature
 */
TSCreature  TSWorldObject::SpawnCreature(uint32 entry,float x,float y,float z,float o,uint32 spawnType,uint32 despawnTimer) 
{
    
    TempSummonType type;
    switch (spawnType)
    {
        case 1:
            type = TEMPSUMMON_TIMED_OR_DEAD_DESPAWN;
            break;
        case 2:
            type = TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN;
            break;
        case 3:
            type = TEMPSUMMON_TIMED_DESPAWN;
            break;
        case 4:
#if defined TRINITY || AZEROTHCORE
            type = TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT;
#else
            type = TEMPSUMMON_TIMED_OOC_DESPAWN;
#endif
            break;
        case 5:
            type = TEMPSUMMON_CORPSE_DESPAWN;
            break;
        case 6:
            type = TEMPSUMMON_CORPSE_TIMED_DESPAWN;
            break;
        case 7:
            type = TEMPSUMMON_DEAD_DESPAWN;
            break;
        case 8:
            type = TEMPSUMMON_MANUAL_DESPAWN;
            break;
#if !defined TRINITY && !AZEROTHCORE
        case 9:
            type = TEMPSUMMON_TIMED_OOC_OR_CORPSE_DESPAWN;
            break;
        case 10:
            type = TEMPSUMMON_TIMED_OOC_OR_DEAD_DESPAWN;
            break;
#endif
    }
    // TODO Fix
    //return TSCreature(obj->SummonCreature(entry, x, y, z, o, type, despawnTimer));
    return TSCreature(nullptr);
}
    
/**
 * Returns true if the given [WorldObject] or coordinates are in the [WorldObject]'s line of sight
 *
 * @proto isInLoS = (worldobject)
 * @proto isInLoS = (x, y, z)
 *
 * @param [WorldObject] worldobject
 * @param float x
 * @param float y
 * @param float z
 * @return bool isInLoS
 */
bool TSWorldObject::IsWithinLoS(TSWorldObject _target,float x,float y,float z)
{
    auto target = _target.obj;
    
    if (target)
        return obj->IsWithinLOSInMap(target);
    else
    {
        return obj->IsWithinLOS(x, y, z);
    }
    
}
    
/**
 * Returns true if the [WorldObject]s are on the same map
 *
 * @param [WorldObject] worldobject
 * @return bool isInMap
 */
bool TSWorldObject::IsInMap(TSWorldObject _target)
{
    auto target = _target.obj;
    return obj->IsInMap(target);
}
    
/**
 * Returns true if the point is in the given distance of the [WorldObject]
 *
 * Notice that the distance is measured from the edge of the [WorldObject].
 *
 * @param float x
 * @param float y
 * @param float z
 * @param float distance
 * @return bool isInDistance
 */
bool TSWorldObject::IsWithinDist3d(float x,float y,float z,float dist) 
{
    return obj->IsWithinDist3d(x, y, z, dist);
}
    
/**
 * Returns true if the point is in the given distance of the [WorldObject]
 *
 * The distance is measured only in x,y coordinates.
 * Notice that the distance is measured from the edge of the [WorldObject].
 *
 * @param float x
 * @param float y
 * @param float distance
 * @return bool isInDistance
 */
bool TSWorldObject::IsWithinDist2d(float x,float y,float dist) 
{
    return obj->IsWithinDist2d(x, y, dist);
}
    
/**
 * Returns true if the target is in the given distance of the [WorldObject]
 *
 * Notice that the distance is measured from the edge of the [WorldObject]s.
 *
 * @param [WorldObject] target
 * @param float distance
 * @param bool is3D = true : if false, only x,y coordinates used for checking
 * @return bool isInDistance
 */
bool TSWorldObject::IsWithinDist(TSWorldObject _target,float distance,bool is3D)
{
    auto target = _target.obj;
    return obj->IsWithinDist(target, distance, is3D);
}
    
/**
 * Returns true if the [WorldObject] is on the same map and within given distance
 *
 * Notice that the distance is measured from the edge of the [WorldObject]s.
 *
 * @param [WorldObject] target
 * @param float distance
 * @param bool is3D = true : if false, only x,y coordinates used for checking
 * @return bool isInDistance
 */
bool TSWorldObject::IsWithinDistInMap(TSWorldObject _target,float distance,bool is3D)
{
    auto target = _target.obj;
    return obj->IsWithinDistInMap(target, distance, is3D);
}
    
/**
 * Returns true if the target is within given range
 *
 * Notice that the distance is measured from the edge of the [WorldObject]s.
 *
 * @param [WorldObject] target
 * @param float minrange
 * @param float maxrange
 * @param bool is3D = true : if false, only x,y coordinates used for checking
 * @return bool isInDistance
 */
bool TSWorldObject::IsInRange(TSWorldObject _target,float minrange,float maxrange,bool is3D)
{
    auto target = _target.obj;
    return obj->IsInRange(target, minrange, maxrange, is3D);
}
    
/**
 * Returns true if the point is within given range
 *
 * Notice that the distance is measured from the edge of the [WorldObject].
 *
 * @param float x
 * @param float y
 * @param float minrange
 * @param float maxrange
 * @return bool isInDistance
 */
bool TSWorldObject::IsInRange2d(float x,float y,float minrange,float maxrange) 
{
    return obj->IsInRange2d(x, y, minrange, maxrange);
}
    
/**
 * Returns true if the point is within given range
 *
 * Notice that the distance is measured from the edge of the [WorldObject].
 *
 * @param float x
 * @param float y
 * @param float z
 * @param float minrange
 * @param float maxrange
 * @return bool isInDistance
 */
bool TSWorldObject::IsInRange3d(float x,float y,float z,float minrange,float maxrange) 
{
    return obj->IsInRange3d(x, y, z, minrange, maxrange);
}
    
/**
 * Returns true if the target is in the given arc in front of the [WorldObject]
 *
 * @param [WorldObject] target
 * @param float arc = pi
 * @return bool isInFront
 */
bool TSWorldObject::IsInFront(TSWorldObject _target,float arc)
{
    auto target = _target.obj;
    
#ifdef MANGOS
    return obj->IsInFront(target, arc);
#else
    return obj->isInFront(target, arc);
#endif
}
    
/**
 * Returns true if the target is in the given arc behind the [WorldObject]
 *
 * @param [WorldObject] target
 * @param float arc = pi
 * @return bool isInBack
 */
bool TSWorldObject::IsInBack(TSWorldObject _target,float arc)
{
    auto target = _target.obj;
    
#ifdef MANGOS
    return obj->IsInBack(target, arc);
#else
    return obj->isInBack(target, arc);
#endif
}
    
/**
 * The [WorldObject] plays music to a [Player]
 *
 * If no [Player] provided it will play the music to everyone near.
 * This method does not interrupt previously played music.
 *
 * See also [WorldObject:PlayDistanceSound], [WorldObject:PlayDirectSound]
 *
 * @param uint32 music : entry of a music
 * @param [Player] player = nil : [Player] to play the music to
 */
void TSWorldObject::PlayMusic(uint32 musicid,TSPlayer _player)
{
    auto player = _player.player;
    
WorldPacket data(SMSG_PLAY_MUSIC, 4);
    data << uint32(musicid);
#ifdef CMANGOS
    if (player)
        player->SendDirectMessage(data);
    else
        obj->SendMessageToSet(data, true);
#else
    if (player)
        player->SendDirectMessage(&data);
    else
        obj->SendMessageToSet(&data, true);
#endif
}
    
/**
 * The [WorldObject] plays a sound to a [Player]
 *
 * If no [Player] provided it will play the sound to everyone near.
 * This method will play sound and does not interrupt prvious sound.
 *
 * See also [WorldObject:PlayDistanceSound], [WorldObject:PlayMusic]
 *
 * @param uint32 sound : entry of a sound
 * @param [Player] player = nil : [Player] to play the sound to
 */
void TSWorldObject::PlayDirectSound(uint32 soundId,TSPlayer _player)
{
    auto player = _player.player;
    
    if (player)
        obj->PlayDirectSound(soundId, player);
    else
        obj->PlayDirectSound(soundId);
}
    
/**
 * The [WorldObject] plays a sound to a [Player]
 *
 * If no [Player] it will play the sound to everyone near.
 * Sound will fade the further you are from the [WorldObject].
 * This method interrupts previously playing sound.
 *
 * See also [WorldObject:PlayDirectSound], [WorldObject:PlayMusic]
 *
 * @param uint32 sound : entry of a sound
 * @param [Player] player = nil : [Player] to play the sound to
 */
void TSWorldObject::PlayDistanceSound(uint32 soundId,TSPlayer _player)
{
    auto player = _player.player;
    
    if (player)
        obj->PlayDistanceSound(soundId, player);
    else
        obj->PlayDistanceSound(soundId);
}
