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
#include "DatabaseEnv.h"
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
#include "ObjectAccessor.h"
#include "DBCStores.h"

// Tolerance for floating-point comparison of radians. This value is small enough
// to detect intentional orientation changes (minimum step is 0.01 radians from UI)
// but large enough to handle typical float precision errors (~1e-6 to 1e-7).
static const float ORIENTATION_EPSILON = 0.0001f;

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
    data << uint64(player->GetGUID().GetRawValue());
    data << uint32(0);
    data << uint64(player->GetGUID().GetRawValue());
    data << uint32(messageLength);
    data << buf;
    data << uint8(0);
    player->GetSession()->SendPacket(&data);
}

GameObject * GOMove::GetGameObject(Player * player, ObjectGuid::LowType lowguid)
{
    return ChatHandler(player->GetSession()).GetObjectFromPlayerMapByDbGuid(lowguid);
}

void GOMove::SendAdd(Player * player, ObjectGuid::LowType lowguid)
{
    GameObjectData const* data = sObjectMgr->GetGameObjectData(lowguid);
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
    auto spawnid = object->GetSpawnId();
    ObjectGuid ownerGuid = object->GetOwnerGUID();
    if (!ownerGuid.IsEmpty())
    {
        Unit* owner = ObjectAccessor::GetUnit(*object, ownerGuid);
        if (owner && ownerGuid.IsPlayer())
            owner->RemoveGameObject(object, false);
    }
    GameObject::DeleteFromDB(spawnid);
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

    QuaternionData rot = QuaternionData::fromEulerAnglesZYX(pos.GetOrientation(), 0.f, 0.f);
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
    if (!object->LoadFromDB(guidLow, map, true))
    {
        delete object;
        return nullptr;
    }

    /// @todo is it really necessary to add both the real and DB table guid here ?
    sObjectMgr->AddGameobjectToGrid(guidLow, sObjectMgr->GetGameObjectData(guidLow));

    if (object)
        SendAdd(player, guidLow);
    return object;
}

GameObject * GOMove::MoveGameObject(Player* player, float x, float y, float z, float o, uint32 p, ObjectGuid::LowType lowguid)
{
    if (!player)
        return nullptr;
    GameObject* object = ChatHandler(player->GetSession()).GetObjectFromPlayerMapByDbGuid(lowguid);
    if (!object)
    {
        SendRemove(player, lowguid);
        return nullptr;
    }

    Map* map = object->GetMap();
    if (!MapManager::IsValidMapCoord(object->GetMapId(), x, y, z))
        return nullptr;

    // Get current rotation to preserve pitch and roll
    QuaternionData rot = object->GetLocalRotation();
    float currentO, currentPitch, currentRoll;
    rot.toEulerAnglesZYX(currentO, currentPitch, currentRoll);

    // Determine the orientation to use: if the passed orientation is close to the
    // quaternion's orientation (position-only move), use the quaternion's value to
    // avoid floating point discrepancies that can invert pitch/roll.
    // If orientation is intentionally changing, calculate the delta and apply it.
    float orientationToUse;
    float orientationDelta = o - object->GetOrientation();
    if (fabs(orientationDelta) < ORIENTATION_EPSILON)
    {
        // Position-only move: preserve exact quaternion orientation
        orientationToUse = currentO;
    }
    else
    {
        // Orientation change: apply the delta to the quaternion's orientation
        orientationToUse = currentO + orientationDelta;
    }

    // copy paste .gob move command
    // copy paste .gob turn command
    object->Relocate(x, y, z, orientationToUse);
    object->SetLocalRotationAngles(orientationToUse, currentPitch, currentRoll);
    object->SaveToDB();

    // Generate a completely new spawn with new guid
    // 3.3.5a client caches recently deleted objects and brings them back to life
    // when CreateObject block for this guid is received again
    // however it entirely skips parsing that block and only uses already known location
    object->Delete();

    object = new GameObject();
    if (!object->LoadFromDB(lowguid, map, true))
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
    Cell::VisitGridObjects(player, searcher, SIZE_OF_GRIDS);
    return objects;
}

void GOMove::SendInfo(Player* player, ObjectGuid::LowType lowguid)
{
    if (!player)
        return;

    GameObjectData const* data = sObjectMgr->GetGameObjectData(lowguid);
    if (!data)
        return;

    GameObjectTemplate const* temp = sObjectMgr->GetGameObjectTemplate(data->id);
    if (!temp)
        return;

    char msg[512];
    snprintf(msg, 512, "INFO|%u|%s|%u|%.2f|%.2f|%.2f|%.2f",
        lowguid,
        temp->name.c_str(),
        data->id,
        data->spawnPoint.GetPositionX(),
        data->spawnPoint.GetPositionY(),
        data->spawnPoint.GetPositionZ(),
        data->spawnPoint.GetOrientation());
    SendAddonMessage(player, msg);
}

GameObject* GOMove::RotateGameObject(Player* player, float o, float pitch, float roll, ObjectGuid::LowType lowguid)
{
    if (!player)
        return nullptr;

    GameObject* object = ChatHandler(player->GetSession()).GetObjectFromPlayerMapByDbGuid(lowguid);
    if (!object)
    {
        SendRemove(player, lowguid);
        return nullptr;
    }

    Map* map = object->GetMap();

    // Set the rotation angles (ZYX order: orientation, pitch, roll)
    object->SetLocalRotationAngles(o, pitch, roll);
    object->SaveToDB();

    // Respawn to apply visual changes
    object->Delete();

    object = new GameObject();
    if (!object->LoadFromDB(lowguid, map, true))
    {
        delete object;
        SendRemove(player, lowguid);
        return nullptr;
    }

    return object;
}
