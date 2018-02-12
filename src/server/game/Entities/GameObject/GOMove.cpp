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
#include "DB2Stores.h"
#include "ObjectAccessor.h"


GameObjectStore GOMove::Store;

void GOMove::SendAddonMessage(Player * player, const char * msg)
{
    if (!player || !msg)
        return;

    player->WhisperAddon(msg, "GOMOVE", player);
}

GameObject * GOMove::GetGameObject(Player * player, ObjectGuid::LowType lowguid)
{
    return ChatHandler(player->GetSession()).GetObjectFromPlayerMapByDbGuid(lowguid);
}

void GOMove::SendAdd(Player * player, ObjectGuid::LowType lowguid)
{
    GameObjectData const* data = sObjectMgr->GetGOData(lowguid);
    if (!data)
        return;
    GameObjectTemplate const* temp = sObjectMgr->GetGameObjectTemplate(data->id);
    if (!temp)
        return;
    char msg[1024];
    snprintf(msg, 1024, "ADD|%s|%s|%u", std::to_string(lowguid).c_str(), temp->name.c_str(), data->id);
    SendAddonMessage(player, msg);
}

void GOMove::SendRemove(Player * player, ObjectGuid::LowType lowguid)
{
    char msg[1024];
    snprintf(msg, 1024, "REMOVE|%s||0", std::to_string(lowguid).c_str());

    SendAddonMessage(player, msg);
}

void GOMove::DeleteGameObject(GameObject * object)
{
    if (!object)
        return;

    // copy paste .gob del command
    ObjectGuid ownerGuid = object->GetOwnerGUID();
    if (!ownerGuid.IsEmpty())
    {
        Unit* owner = ObjectAccessor::GetUnit(*object, ownerGuid);
        if (!owner || !ownerGuid.IsPlayer())
            return;

        owner->RemoveGameObject(object, false);
    }

    object->SetRespawnTime(0);                                 // not save respawn time
    object->Delete();
    object->DeleteFromDB();
}

GameObject * GOMove::SpawnGameObject(Player* player, float x, float y, float z, float o, std::set<uint32> p, uint32 entry)
{
    if (!player || !entry)
        return nullptr;

    if (!MapManager::IsValidMapCoord(player->GetMapId(), x, y, z))
        return nullptr;

    // copy paste .gob add command

    const GameObjectTemplate* objectInfo = sObjectMgr->GetGameObjectTemplate(entry);

    if (!objectInfo)
        return nullptr;

    if (objectInfo->displayId && !sGameObjectDisplayInfoStore.LookupEntry(objectInfo->displayId))
        return nullptr;

    Map* map = player->GetMap();

    QuaternionData quat;
    quat.fromEulerAnglesZYX(z, y, x);
    Position pos;
    pos.m_positionX = x;
    pos.m_positionY = y;
    pos.m_positionZ = z;
    pos.SetOrientation(o);
    GameObject* object = GameObject::CreateGameObject(objectInfo->entry, map, pos, quat, 255, GO_STATE_READY);
    if (!object)
        return nullptr;

    // copy paste from WorldObject::CopyPhaseFrom(object, update)
    bool update = false;
    for (uint32 phase : p)
        object->SetInPhase(phase, false, true);
    if (update && object->IsInWorld())
        object->UpdateObjectVisibility();

    // fill the gameobject data and save to the db
    object->SaveToDB(map->GetId(), UI64LIT(1) << map->GetSpawnMode());
    ObjectGuid::LowType spawnId = object->GetSpawnId();

    // delete the old object and do a clean load from DB with a fresh new GameObject instance.
    // this is required to avoid weird behavior and memory leaks
    delete object;

    object = GameObject::CreateGameObjectFromDB(spawnId, map);
    if (!object)
        return nullptr;

    /// @todo is it really necessary to add both the real and DB table guid here ?
    sObjectMgr->AddGameobjectToGrid(spawnId, ASSERT_NOTNULL(sObjectMgr->GetGOData(spawnId)));

    if (object)
        SendAdd(player, spawnId);
    return object;
}

GameObject * GOMove::MoveGameObject(Player* player, float x, float y, float z, float o, std::set<uint32> p, ObjectGuid::LowType lowguid)
{
    if (!player)
        return nullptr;
    GameObject* object = ChatHandler(player->GetSession()).GetObjectFromPlayerMapByDbGuid(lowguid);
    if (!object)
    {
        SendRemove(player, lowguid);
        return nullptr;
    }

    if (!MapManager::IsValidMapCoord(object->GetMapId(), x, y, z))
        return nullptr;

    // copy paste .gob turn command
    object->Relocate(x, y, z, o);
    object->RelocateStationaryPosition(x, y, z, o);
    object->SetWorldRotationAngles(o, 0.0f, 0.0f);
    object->DestroyForNearbyPlayers();
    object->UpdateObjectVisibility();

    // copy paste .gob move command
    object->DestroyForNearbyPlayers();
    object->RelocateStationaryPosition(x, y, z, object->GetOrientation());
    object->GetMap()->GameObjectRelocation(object, x, y, z, object->GetOrientation());

    // copy paste .gob phase command
    // TODO multi phase support for 7.x
    object->ClearPhases();
    // copy paste from WorldObject::CopyPhaseFrom(object, update)
    bool update = true;
    for (uint32 phase : p)
        object->SetInPhase(phase, false, true);
    if (update && object->IsInWorld())
        object->UpdateObjectVisibility();

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
    Cell::VisitGridObjects(player, searcher, SIZE_OF_GRIDS, false);
    return objects;
}
