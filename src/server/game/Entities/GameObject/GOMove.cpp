/*
GOMove By Rochet2
Original idea by Mordred

http://rochet2.github.io/
*/

#include <math.h>
#include <set>
#include <sstream>
#include <string>
#include "Chat.h"
#include "GameObject.h"
#include "Language.h"
#include "Map.h"
#include "MapManager.h"
#include "Object.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "Position.h"
#include "RBAC.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "WorldPacket.h"
#include "GOMove.h"

GameObjectStore GOMove::Store;

void GOMove::GOMoveRemoveGO(ObjectGuid const & guid)
{
    bool isHex = GOMove::IsTemporary(guid);
    if (isHex)
        GOMove::Store.RemoveTemp(guid.GetEntry());

    for (auto session : sWorld->GetAllSessions())
        if (Player* player = session.second->GetPlayer())
            GOMove::SendRemove(player, isHex ? guid.GetEntry() : guid.GetCounter(), isHex);
}

bool GOMove::IsTemporary(ObjectGuid const & guid)
{
    return (guid.GetHigh() == HighGuid::GOMoveObject);
}

void GOMove::SendAddonMessage(Player * player, const char * msg)
{
    if (!player || !msg)
        return;

    WorldPacket data; // Needs a custom built packet since TC doesnt send guid
    uint32 messageLength = (uint32)strlen(msg) + 1;
    data.Initialize(SMSG_MESSAGECHAT, 100);
    data << uint8(CHAT_MSG_SYSTEM);
    data << int32(LANG_ADDON);
    data << uint64(player->GetGUID());
    data << uint32(0);
    data << uint64(player->GetGUID());
    data << uint32(messageLength);
    data << msg;
    data << uint8(0);
    player->GetSession()->SendPacket(&data);
}

GameObject * GOMove::GetGameObject(Player * player, uint32 GObjectID, bool isHex)
{
    if (isHex)
        return Store.GetTemp(player, GObjectID);
    else if (GameObjectData const* gameObjectData = sObjectMgr->GetGOData(GObjectID))
        return ChatHandler(player->GetSession()).GetObjectGlobalyWithGuidOrNearWithDbGuid(GObjectID, gameObjectData->id);
    return nullptr;
}

void GOMove::SendAdd(Player * player, uint32 GObjectID, bool isHex)
{
    GameObject* object = GOMove::GetGameObject(player, GObjectID, isHex);
    if (!object)
        return;

    char msg[256];
    if (!isHex)
        snprintf(msg, 256, "GOMOVE|ADD|%u|%s|%u", GObjectID, object->GetName().c_str(), object->GetEntry());
    else
        snprintf(msg, 256, "GOMOVE|ADD|%#x|%s|%u", GObjectID, object->GetName().c_str(), object->GetEntry());

    SendAddonMessage(player, msg);
}

void GOMove::SendRemove(Player * player, uint32 GObjectID, bool isHex)
{
    char msg[256];
    if (!isHex)
        snprintf(msg, 256, "GOMOVE|REMOVE|%u||0", GObjectID);
    else
        snprintf(msg, 256, "GOMOVE|REMOVE|%#x||0", GObjectID);

    SendAddonMessage(player, msg);
}

void GOMove::SendSwap(Player * player, uint32 GObjectID1, bool isHex1, uint32 GObjectID2, bool isHex2)
{
    char msg[256];
    if (!isHex1 && !isHex2)
        snprintf(msg, 256, "GOMOVE|SWAP|%u||%u", GObjectID1, GObjectID2);
    else if (isHex1 && isHex2)
        snprintf(msg, 256, "GOMOVE|SWAP|%#x||%#x", GObjectID1, GObjectID2);
    else if (!isHex1 && isHex2)
        snprintf(msg, 256, "GOMOVE|SWAP|%u||%#x", GObjectID1, GObjectID2);
    else if (isHex1 && !isHex2)
        snprintf(msg, 256, "GOMOVE|SWAP|%#x||%u", GObjectID1, GObjectID2);
    SendAddonMessage(player, msg);
}

GameObject * GOMove::CreateTemp(Player * obj, uint32 entry, float x, float y, float z, float o, uint32 p, uint32 respawnTime)
{
    if (!obj->IsInWorld())
        return nullptr;

    GameObjectTemplate const* goinfo = sObjectMgr->GetGameObjectTemplate(entry);
    if (!goinfo)
        return nullptr;

    float rotation2 = std::sin(o / 2);
    float rotation3 = std::cos(o / 2);

    Map* map = obj->GetMap();
    GameObject* go = new GameObject();
    if (!go->Create(0, entry, map, p, x, y, z, o, 0, 0, rotation2, rotation3, 100, GO_STATE_READY))
    {
        delete go;
        return nullptr;
    }

    go->SetRespawnTime(respawnTime);
    obj->AddGameObject(go);
    map->AddToMap(go);

    Store.AddTemp(go->GetGUID().GetEntry(), go);
    return go;
}

void GOMove::DeleteGameObject(GameObject * object)
{
    if (!object)
        return;

    ObjectGuid ownerGuid = object->GetOwnerGUID();
    if (ownerGuid != ObjectGuid::Empty)
    {
        Unit* owner = ObjectAccessor::GetUnit(*object, ownerGuid);
        if (owner && ownerGuid.IsPlayer())
            owner->RemoveGameObject(object, false);
    }
    object->SetRespawnTime(0);
    object->Delete();
    object->DeleteFromDB();
}

GameObject * GOMove::SpawnGameObject(Player* player, float x, float y, float z, float o, uint32 p, uint32 entry)
{
    if (!player || !entry)
        return nullptr;

    GameObject* spawned = CreateTemp(player, entry, x, y, z, o, p, 0);
    if (spawned)
        SendAdd(player, spawned->GetGUID().GetEntry(), true);
    return spawned;
}

GameObject * GOMove::MoveGameObject(Player* player, float x, float y, float z, float o, uint32 p, uint32 GObjectID, bool isHex)
{
    if (!player)
        return nullptr;

    GameObject* object = GetGameObject(player, GObjectID, isHex);
    if (!object)
    {
        SendRemove(player, GObjectID, isHex);
        return nullptr;
    }

    GameObject* spawned = CreateTemp(player, object->GetEntry(), x, y, z, o, p, 0);

    if (!spawned)
        return nullptr;

    SendSwap(player, GObjectID, isHex, spawned->GetGUID().GetEntry(), true);
    DeleteGameObject(object);
    return spawned;
}

void GOMove::SaveGameObject(Player * player, uint32 GObjectID, bool isHex)
{
    GameObject* object = GetGameObject(player, GObjectID, isHex);
    if (!object)
        return;

    if (!isHex)
    {
        object->SaveToDB();
        return;
    }

    Map* map = player->GetMap();
    GameObject* saved = new GameObject();
    uint32 guidLow = map->GenerateLowGuid<HighGuid::GameObject>();
    float x, y, z, o;
    object->GetPosition(x, y, z, o);
    if (!saved->Create(guidLow, object->GetEntry(), map, object->GetPhaseMask(), x, y, z, o, 0.0f, 0.0f, 0.0f, 0.0f, 0, GO_STATE_READY))
    {
        delete saved;
        return;
    }
    saved->SaveToDB(map->GetId(), (1 << map->GetSpawnMode()), saved->GetPhaseMask());
    guidLow = saved->GetSpawnId();
    delete saved;
    saved = new GameObject();
    if (!saved->LoadGameObjectFromDB(guidLow, map))
    {
        delete saved;
        return;
    }
    sObjectMgr->AddGameobjectToGrid(guidLow, sObjectMgr->GetGOData(guidLow));

    SendSwap(player, GObjectID, isHex, guidLow, false);
    DeleteGameObject(object);
}

void GameObjectStore::SpawnQueAdd(ObjectGuid const & guid, uint32 entry)
{
    WriteGuard lock(_objectsToSpawnLock);
    objectsToSpawn[guid] = entry;
}

void GameObjectStore::SpawnQueRem(ObjectGuid const & guid)
{
    WriteGuard lock(_objectsToSpawnLock);
    objectsToSpawn.erase(guid);
}

uint32 GameObjectStore::SpawnQueGet(ObjectGuid const & guid)
{
    WriteGuard lock(_objectsToSpawnLock);
    auto it = objectsToSpawn.find(guid);
    if (it != objectsToSpawn.end())
        return it->second;
    return 0;
}

void GameObjectStore::AddTemp(uint32 GObjectID, GameObject * go)
{
    if (!go)
        return;
    WriteGuard lock(_tempObjectsLock);
    tempObjects[GObjectID] = go;
}

void GameObjectStore::RemoveTemp(uint32 GObjectID)
{
    {
        WriteGuard lock(_tempObjectsLock);
        tempObjects.erase(GObjectID);
    }
}

GameObject * GameObjectStore::GetTemp(Player* player, uint32 GObjectID)
{
    WriteGuard lock(_tempObjectsLock);
    auto it = tempObjects.find(GObjectID);
    if (it != tempObjects.end())
        return player->IsInMap(it->second) ? it->second : nullptr;
    return nullptr;
}

void GameObjectStore::SendSelectTempInRange(Player * player, float range)
{
    std::vector<uint32> toSend;
    {
        WriteGuard lock(_tempObjectsLock);
        for (auto& go : tempObjects)
        {
            if (go.second->IsWithinDistInMap(player, range))
                toSend.push_back(go.first);
        }
    }

    for (uint32 low : toSend)
        GOMove::SendAdd(player, low, true);
}

GameObject * GameObjectStore::GetClosestTemp(Player * player, GameObject * closestReal)
{
    GameObject* obj = closestReal;
    WriteGuard lock(_tempObjectsLock);
    for (auto& go : tempObjects)
    {
        if (obj && go.second->GetDistance(player) > obj->GetDistance(player))
            continue;
        obj = go.second;
    }
    return obj;
}
