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
#include "GameObject.h"

#include "TSPlayer.h"
#include "TSGroup.h"
#include "TSWorldObject.h"
#include "TSIncludes.h"
#include "TSGameObject.h"


TSGameObject::TSGameObject(GameObject *go) : TSWorldObject(go)
{
    this->go = go;
}

TSGameObject::TSGameObject() : TSWorldObject()
{
    this->go = nullptr;
}

/**
 * Returns 'true' if the [GameObject] can give the specified [Quest]
 *
 * @param uint32 questId : quest entry Id to check
 * @return bool hasQuest
 */
bool TSGameObject::HasQuest(uint32 questId) 
{
    
#if defined TRINITY || AZEROTHCORE
    return go->hasQuest(questId);
#else
    return go->HasQuest(questId);
#endif
}
    
/**
 * Returns 'true' if the [GameObject] is spawned
 *
 * @return bool isSpawned
 */
bool TSGameObject::IsSpawned() 
{
    return go->isSpawned();
}
    
/**
 * Returns 'true' if the [GameObject] is a transport
 *
 * @return bool isTransport
 */
bool TSGameObject::IsTransport() 
{
    return go->IsTransport();
}
    
/**
 * Returns 'true' if the [GameObject] is active
 *
 * @return bool isActive
 */
bool TSGameObject::IsActive() 
{
    return go->isActiveObject();
}
    
/*int TSGameObject::IsDestructible(lua_State* L, GameObject* go) // TODO: Implementation core side
{
    return go->IsDestructibleBuilding();
}*/
    
/**
 * Returns display ID of the [GameObject]
 *
 * @return uint32 displayId
 */
uint32 TSGameObject::GetDisplayId() 
{
    return go->GetDisplayId();
}
    
/**
 * Returns the state of a [GameObject]
 * Below are client side [GOState]s off of 3.3.5a
 *
 * <pre>
 * enum GOState
 * {
 *     GO_STATE_ACTIVE             = 0,                        // show in world as used and not reset (closed door open)
 *     GO_STATE_READY              = 1,                        // show in world as ready (closed door close)
 *     GO_STATE_ACTIVE_ALTERNATIVE = 2                         // show in world as used in alt way and not reset (closed door open by cannon fire)
 * </pre>
 *
 * @return [GOState] goState
 */
uint32 TSGameObject::GetGoState() 
{
    return go->GetGoState();
}
    
/**
 * Returns the [LootState] of a [GameObject]
 * Below are [LootState]s off of 3.3.5a
 *
 * <pre>
 * enum LootState
 * {
 *     GO_NOT_READY = 0,
 *     GO_READY,                                               // can be ready but despawned, and then not possible activate until spawn
 *     GO_ACTIVATED,
 *     GO_JUST_DEACTIVATED
 * </pre>
 *
 * @return [LootState] lootState
 */
uint32 TSGameObject::GetLootState() 
{
    return go->getLootState();
}
    
/**
 * Returns the [Player] that can loot the [GameObject]
 *
 * Not the original looter and may be nil.
 *
 * @return [Player] player
 */
TSPlayer  TSGameObject::GetLootRecipient() 
{
     return TSPlayer(go->GetLootRecipient());
}
    
/**
 * Returns the [Group] that can loot the [GameObject]
 *
 * Not the original looter and may be nil.
 *
 * @return [Group] group
 */
TSGroup  TSGameObject::GetLootRecipientGroup() 
{
#if defined TRINITY || AZEROTHCORE
     return TSGroup(go->GetLootRecipientGroup());
#else
     return TSGroup(go->GetGroupLootRecipient());
#endif
}
    
/**
 * Returns the guid of the [GameObject] that is used as the ID in the database
 *
 * @return uint32 dbguid
 */
uint32 TSGameObject::GetDBTableGUIDLow() 
{
#ifdef TRINITY
    return go->GetSpawnId();
#elif AZEROTHCORE
    return go->GetDBTableGUIDLow();
#else
    // on mangos based this is same as lowguid
    return go->GetGUIDLow();
#endif
}
    
/**
 * Sets the state of a [GameObject]
 *
 * <pre>
 * enum GOState
 * {
 *     GO_STATE_ACTIVE             = 0,                        // show in world as used and not reset (closed door open)
 *     GO_STATE_READY              = 1,                        // show in world as ready (closed door close)
 *     GO_STATE_ACTIVE_ALTERNATIVE = 2                         // show in world as used in alt way and not reset (closed door open by cannon fire)
 * </pre>
 *
 * @param [GOState] state : all available go states can be seen above
 */
void TSGameObject::SetGoState(uint32 state) 
{
    
    if (state == 0)
        go->SetGoState(GO_STATE_ACTIVE);
    else if (state == 1)
        go->SetGoState(GO_STATE_READY);
    else if (state == 2)
    {
#ifdef TRINITY
        go->SetGoState(GO_STATE_DESTROYED);
#else
        go->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
#endif
    }
    
}
    
/**
 * Sets the [LootState] of a [GameObject]
 * Below are [LootState]s off of 3.3.5a
 *
 * <pre>
 * enum LootState
 * {
 *     GO_NOT_READY = 0,
 *     GO_READY,                                               // can be ready but despawned, and then not possible activate until spawn
 *     GO_ACTIVATED,
 *     GO_JUST_DEACTIVATED
 * </pre>
 *
 * @param [LootState] state : all available loot states can be seen above
 */
void TSGameObject::SetLootState(uint32 state) 
{
    
    if (state == 0)
        go->SetLootState(GO_NOT_READY);
    else if (state == 1)
        go->SetLootState(GO_READY);
    else if (state == 2)
        go->SetLootState(GO_ACTIVATED);
    else if (state == 3)
        go->SetLootState(GO_JUST_DEACTIVATED);
    
}
    
/**
 * Saves [GameObject] to the database
 *
 */
void TSGameObject::SaveToDB() 
{
    go->SaveToDB();
}
    
/**
 * Removes [GameObject] from the world
 *
 * The object is no longer reachable after this and it is not respawned.
 *
 * @param bool deleteFromDB : if true, it will delete the [GameObject] from the database
 */
void TSGameObject::RemoveFromWorld(bool deldb) 
{
    
    // cs_gobject.cpp copy paste
#if defined TRINITY || AZEROTHCORE
    ObjectGuid ownerGuid = go->GetOwnerGUID();
#else
    ObjectGuid ownerGuid = go->GetOwnerGuid();
#endif
    if (ownerGuid)
    {
        Unit* owner = eObjectAccessor()GetUnit(*go, ownerGuid);
    
        owner->RemoveGameObject(go, false);
    }
    
    if (deldb)
    {
#ifdef TRINITY
        GameObject::DeleteFromDB(go->GetSpawnId());
#else
        go->DeleteFromDB();
#endif
    }
    
    go->SetRespawnTime(0);
    go->Delete();
    
}
    
/**
 * Activates a door or a button/lever
 *
 * @param uint32 delay = 0 : cooldown time in seconds to restore the [GameObject] back to normal. 0 for infinite duration
 */
void TSGameObject::UseDoorOrButton(uint32 delay) 
{
    
    go->UseDoorOrButton(delay);
}
    
/**
 * Despawns a [GameObject]
 *
 * The gameobject may be automatically respawned by the core
 */
void TSGameObject::Despawn() 
{
    go->SetLootState(GO_JUST_DEACTIVATED);
}
    
/**
 * Respawns a [GameObject]
 */
void TSGameObject::Respawn() 
{
    go->Respawn();
}
    
/**
 * Sets the respawn or despawn time for the gameobject.
 *
 * Respawn time is also used as despawn time depending on gameobject settings
 *
 * @param int32 delay = 0 : cooldown time in seconds to respawn or despawn the object. 0 means never
 */
void TSGameObject::SetRespawnTime(int32 respawn) 
{
    
    go->SetRespawnTime(respawn);
}

TSLoot TSGameObject::GetLoot()
{
    return TSLoot(&go->loot);
}