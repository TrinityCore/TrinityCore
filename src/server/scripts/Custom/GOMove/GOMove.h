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

class GameObjectStore
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

namespace GOMove
{
    GameObjectStore Store;
    bool IsTemporary(ObjectGuid const& guid);

    void SendAdd(Player* player, uint32 GObjectID, bool isHex);
    void SendRemove(Player* player, uint32 GObjectID, bool isHex);
    void SendSwap(Player * player, uint32 GObjectID1, bool isHex1, uint32 GObjectID2, bool isHex2);
    void SendAddonMessage(Player* player, const char* msg);

    void DeleteGameObject(GameObject* object);
    void SaveGameObject(Player* player, uint32 GObjectID, bool isHex);
    GameObject* GetGameObject(Player* player, uint32 GObjectID, bool isHex);
    GameObject* SpawnGameObject(Player* player, float x, float y, float z, float o, uint32 p, uint32 entry);
    GameObject* MoveGameObject(Player* player, float x, float y, float z, float o, uint32 p, uint32 GObjectID, bool isHex);
    GameObject* CreateTemp(Player* obj, uint32 entry, float x, float y, float z, float o, uint32 p, uint32 respawnTime);
}

#endif