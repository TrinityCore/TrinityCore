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
#include "ScriptMgr.h"
#include "WorldPacket.h"
#include "GOMove.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"

GameObjectStore GOMove::Store;

void GOMove::SendAddonMessage(Player * player, const char * msg)
{
    if (!player || !msg)
        return;

    char buf[256];
    snprintf(buf, 256, "GOMOVE\t%s", msg);

    // copy paste addon message packet
    WorldPacket data; // Needs a custom built packet since TC doesnt send guid
    uint32 messageLength = static_cast<uint32>(std::strlen(buf) + 1);
    data.Initialize(SMSG_MESSAGECHAT, 100);
    data << uint8(CHAT_MSG_SYSTEM);
    data << int32(LANG_ADDON);
    data << uint64(player->GetGUID());
    data << uint32(0);
    data << uint64(player->GetGUID());
    data << uint32(messageLength);
    data << buf;
    data << uint8(0);
    player->GetSession()->SendPacket(&data);
}

GameObject * GOMove::GetGameObject(Player * player, ObjectGuid::LowType lowguid)
{
    if (GameObjectData const* data = sObjectMgr->GetGOData(lowguid))
        return ChatHandler(player->GetSession()).GetObjectGlobalyWithGuidOrNearWithDbGuid(lowguid, data->id);
    return nullptr;
}

void GOMove::SendAdd(Player * player, ObjectGuid::LowType lowguid)
{
    GameObjectData const* data = sObjectMgr->GetGOData(lowguid);
    if (!data)
        return;
    GameObjectTemplate const* temp = sObjectMgr->GetGameObjectTemplate(data->id);
    if (!temp)
        return;
    char msg[256];
    snprintf(msg, 256, "ADD|%u|%s|%u", lowguid, temp->name.c_str(), data->id);
    SendAddonMessage(player, msg);
}

void GOMove::SendRemove(Player * player, ObjectGuid::LowType lowguid)
{
    char msg[256];
    snprintf(msg, 256, "REMOVE|%u||0", lowguid);

    SendAddonMessage(player, msg);
}

void GOMove::DeleteGameObject(GameObject * object)
{
    if (!object)
        return;

    // copy paste .gob del command
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

    if (!MapManager::IsValidMapCoord(player->GetMapId(), x, y, z))
        return nullptr;

    Position pos(x, y, z, o);

    // copy paste .gob add command
    GameObjectTemplate const* objectInfo = sObjectMgr->GetGameObjectTemplate(entry);
    if (!objectInfo)
        return nullptr;

    if (objectInfo->displayId && !sGameObjectDisplayInfoStore.LookupEntry(objectInfo->displayId))
        return nullptr;

    Map* map = player->GetMap();

    GameObject* object = new GameObject();
    ObjectGuid::LowType guidLow = map->GenerateLowGuid<HighGuid::GameObject>();

    G3D::Quat rot = G3D::Matrix3::fromEulerAnglesZYX(pos.GetOrientation(), 0.f, 0.f);
    if (!object->Create(guidLow, objectInfo->entry, map, player->GetPhaseMaskForSpawn(), pos, rot, 255, GO_STATE_READY))
    {
        delete object;
        return nullptr;
    }

    // fill the gameobject data and save to the db
    object->SaveToDB(map->GetId(), (1 << map->GetSpawnMode()), p);
    guidLow = object->GetSpawnId();

    // delete the old object and do a clean load from DB with a fresh new GameObject instance.
    // this is required to avoid weird behavior and memory leaks
    delete object;

    object = new GameObject();
    // this will generate a new guid if the object is in an instance
    if (!object->LoadGameObjectFromDB(guidLow, map))
    {
        delete object;
        return nullptr;
    }

    /// @todo is it really necessary to add both the real and DB table guid here ?
    sObjectMgr->AddGameobjectToGrid(guidLow, sObjectMgr->GetGOData(guidLow));

    if (object)
        SendAdd(player, guidLow);
    return object;
}

GameObject * GOMove::MoveGameObject(Player* player, float x, float y, float z, float o, uint32 p, ObjectGuid::LowType lowguid)
{
    if (!player)
        return nullptr;
    GameObject* object = nullptr;
    if (GameObjectData const* data = sObjectMgr->GetGOData(lowguid))
        object = ChatHandler(player->GetSession()).GetObjectGlobalyWithGuidOrNearWithDbGuid(lowguid, data->id);
    if (!object)
    {
        SendRemove(player, lowguid);
        return nullptr;
    }

    Map* map = object->GetMap();
    if (!MapManager::IsValidMapCoord(object->GetMapId(), x, y, z))
        return nullptr;

    // copy paste .gob move command
    // copy paste .gob turn command
    object->Relocate(x, y, z, o);
    object->SetWorldRotationAngles(o, 0, 0);
    object->SaveToDB();

    // Generate a completely new spawn with new guid
    // 3.3.5a client caches recently deleted objects and brings them back to life
    // when CreateObject block for this guid is received again
    // however it entirely skips parsing that block and only uses already known location
    object->Delete();

    object = new GameObject();
    if (!object->LoadGameObjectFromDB(lowguid, map))
    {
        delete object;
        SendRemove(player, lowguid);
        return nullptr;
    }

    // copy paste from .gob phase command
    object->SetPhaseMask(p, true);
    object->SaveToDB();

    return object;
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

std::list<GameObject*> GOMove::GetNearbyGameObjects(Player* player, float range)
{
    float x, y, z;
    player->GetPosition(x, y, z);

    std::list<GameObject*> objects;
    Trinity::GameObjectInRangeCheck check(x, y, z, range);
    Trinity::GameObjectListSearcher<Trinity::GameObjectInRangeCheck> searcher(player, objects, check);
    player->VisitNearbyGridObject(SIZE_OF_GRIDS, searcher);
    return objects;
}
