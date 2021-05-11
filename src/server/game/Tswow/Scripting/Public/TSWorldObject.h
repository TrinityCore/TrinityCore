/*
 * This file is part of tswow (https://github.com/tswow/).
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
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
#pragma once

#include "TSMain.h"
#include "TSString.h"
#include "TSClasses.h"
#include "TSObject.h"
#include "TSPosition.h"
#include "TSTask.h"
#include "TSStorage.h"
#include "TSEntity.h"
#include "TSDictionary.h"
#include <chrono>
#include <vector>

struct TSCollisions;
struct TSCollisionEntry;

#define CollisionCallback std::function<void(TSCollisionEntry*,TSWorldObject,TSWorldObject,TSMutable<uint32_t>)>

class TC_GAME_API TSWorldObject : public TSObject {
public:
    WorldObject* obj;
    TSWorldObject();
    TSWorldObject(WorldObject* obj);
    bool IsNull() { return obj == nullptr; };
    TSWorldObject* operator->() { return this;}
    TSArray<TSCreature> GetCreaturesInRange(float range, uint32 entry, uint32 hostile, uint32 dead);
    TSArray<TSPlayer> GetPlayersInRange(float range, uint32 hostile, uint32 dead);
    TSArray<TSUnit> GetUnitsInRange(float range, uint32 hostile, uint32 dead);
    TSArray<TSGameObject> GetGameObjectsInRange(float range, uint32 entry, uint32 hostile);

    TSPlayer GetNearestPlayer(float range, uint32 hostile, uint32 dead);
    TSGameObject GetNearestGameObject(float range, uint32 entry, uint32 hostile);
    TSCreature GetNearestCreature(float range, uint32 entry, uint32 hostile, uint32 dead);

    float GetDistance(TSWorldObject target, float X, float Y, float Z);
    float GetDistance2d(TSWorldObject target, float X, float Y);
    TSGameObject  SummonGameObject(uint32 entry, float x, float y, float z, float o, uint32 respawnDelay);
    TSCreature  SpawnCreature(uint32 entry, float x, float y, float z, float o, uint32 spawnType, uint32 despawnTimer);

    void SendPacket(TSWorldPacket data);
    void SendPacket(std::shared_ptr<TSWorldPacket> data);
    bool IsWithinLoS(TSWorldObject target, float x, float y, float z);
    bool IsInMap(TSWorldObject target);

    bool IsWithinDist(TSWorldObject target, float distance, bool is3D);
    bool IsWithinDistInMap(TSWorldObject target, float distance, bool is3D);
    bool IsInRange(TSWorldObject target, float minrange, float maxrange, bool is3D);

    bool IsInFront(TSWorldObject target, float arc);
    bool IsInBack(TSWorldObject target, float arc);
    void PlayMusic(uint32 musicid, TSPlayer player);
    void PlayDirectSound(uint32 soundId, TSPlayer player);
    void PlayDistanceSound(uint32 soundId, TSPlayer player);

    TSMap GetMap();
    TSString GetName();
    uint32 GetPhaseMask();
    void SetPhaseMask(uint32 phaseMask, bool update);
    uint32 GetInstanceId();
    uint32 GetAreaId();
    uint32 GetZoneId();
    uint32 GetMapId();
    float GetAngle(TSWorldObject target,float x,float y);
    float GetX();
    float GetY();
    float GetZ();
    float GetO();
    TSPosition GetPosition();
    // TODO: Fix
    //GetExactDistance(TSWorldObject _target, float x1, float y1, float z1);
    TSPosition GetRelativePoint(float dist, float rad);
    bool IsWithinDist3d(float x, float y, float z, float dist);
    bool IsWithinDist2d(float x, float y, float dist);
    bool IsInRange2d(float x, float y, float minrange, float maxrange);
    bool IsInRange3d(float x, float y, float z, float minrange, float maxrange);

    TSGameObject GetGameObject(uint64 guid);
    TSCorpse GetCorpse(uint64 guid);
    TSUnit GetUnit(uint64 guid);
    TSCreature GetCreature(uint64 guid);
    TSPlayer GetPlayer(uint64 guid);

    TSTasks<TSWorldObject> * GetTasks();
    TSStorage * GetData();

    TS_ENTITY_DATA_DECL(TSWorldObject)
    TS_ENTITY_TIMER_DECL(TSWorldObject)

    bool HasCollision(TSString id) ;
    void AddCollision(uint32_t modid, TSString id, float range, uint32_t minDelay, uint32_t maxHits, CollisionCallback callback);
    TSCollisionEntry * GetCollision(TSString id);

    TSCollisions* GetCollisions();
};

class TC_GAME_API TSCollisionEntry {
public:
    TSDictionary<uint64,uint32> hitmap;
    CollisionCallback callback;
    TSString name;
    uint32_t lastReload;
    uint32_t modid;
    uint32_t maxHits;
    float range;
    uint64_t minDelay;
    uint64_t lastHit = 0;

    TSCollisionEntry(uint32_t modid, TSString name, float range, uint32_t minDelay,uint32_t maxHits, CollisionCallback callback);
    bool Tick(TSWorldObject value, bool force = true);
};

class TC_GAME_API TSCollisions {
public:
    std::vector<TSCollisionEntry> callbacks;
    TSCollisionEntry* Add(uint32_t modid, TSString id, float range, uint32_t minDelay, uint32_t maxHits, CollisionCallback callback);
    bool Contains(TSString id);
    TSCollisionEntry* Get(TSString id);
    void Tick(TSWorldObject obj);
};
