/*
GOMove By Rochet2
Original idea by Mordred

http://rochet2.github.io/
*/

#ifndef GOMOVE_H
#define GOMOVE_H

#include "Define.h"
#include "ObjectGuid.h"
#include <memory>
#include <mutex>
#include <unordered_map>

class Player;
class GameObject;

class TC_GAME_API GameObjectStore
{
public:
    typedef std::mutex LockType;
    typedef std::lock_guard<LockType> WriteGuard;

    void SpawnQueAdd(ObjectGuid const& guid, uint32 entry);
    void SpawnQueRem(ObjectGuid const& guid);
    uint32 SpawnQueGet(ObjectGuid const& guid);

private:
    LockType _objectsToSpawnLock;
    std::unordered_map<ObjectGuid, uint32> objectsToSpawn;
};

class TC_GAME_API GOMove
{
public:
    static GameObjectStore Store;

    static void SendAdd(Player* player, ObjectGuid::LowType lowguid);
    static void SendRemove(Player* player, ObjectGuid::LowType lowguid);
    static void SendAddonMessage(Player* player, const char* msg);

    static void DeleteGameObject(GameObject* object);
    static GameObject* GetGameObject(Player* player, ObjectGuid::LowType lowguid);
    static GameObject* SpawnGameObject(Player* player, float x, float y, float z, float o, std::set<uint32> p, uint32 entry);
    static GameObject* MoveGameObject(Player* player, float x, float y, float z, float o, std::set<uint32> p, ObjectGuid::LowType lowguid);
    static std::list<GameObject*> GetNearbyGameObjects(Player* player, float range);
};

#endif
