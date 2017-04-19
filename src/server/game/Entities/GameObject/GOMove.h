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

    void AddTemp(uint32 GObjectID, GameObject* go);
    void RemoveTemp(uint32 GObjectID);
    GameObject* GetTemp(Player* player, uint32 GObjectID);

    void SendSelectTempInRange(Player* player, float range);
    GameObject* GetClosestTemp(Player* player, GameObject* obj);

private:
    LockType _tempObjectsLock;
    LockType _objectsToSpawnLock;
    std::unordered_map<uint32, GameObject*> tempObjects;
    std::unordered_map<ObjectGuid, uint32> objectsToSpawn;
};

class TC_GAME_API GOMove
{
public:
    static GameObjectStore Store;
    static void GOMoveRemoveGO(ObjectGuid const & guid);
    static bool IsTemporary(ObjectGuid const& guid);

    static void SendAdd(Player* player, uint32 GObjectID, bool isHex);
    static void SendRemove(Player* player, uint32 GObjectID, bool isHex);
    static void SendSwap(Player * player, uint32 GObjectID1, bool isHex1, uint32 GObjectID2, bool isHex2);
    static void SendAddonMessage(Player* player, const char* msg);

    static void DeleteGameObject(GameObject* object);
    static void SaveGameObject(Player* player, uint32 GObjectID, bool isHex);
    static GameObject* GetGameObject(Player* player, uint32 GObjectID, bool isHex);
    static GameObject* SpawnGameObject(Player* player, float x, float y, float z, float o, uint32 p, uint32 entry);
    static GameObject* MoveGameObject(Player* player, float x, float y, float z, float o, uint32 p, uint32 GObjectID, bool isHex);
    static GameObject* CreateTemp(Player* obj, uint32 entry, float x, float y, float z, float o, uint32 p, uint32 respawnTime);
};

#endif
