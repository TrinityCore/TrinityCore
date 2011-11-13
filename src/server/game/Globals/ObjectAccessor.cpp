/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ObjectAccessor.h"
#include "ObjectMgr.h"

#include "Player.h"
#include "Creature.h"
#include "GameObject.h"
#include "DynamicObject.h"
#include "Vehicle.h"
#include "WorldPacket.h"
#include "Item.h"
#include "Corpse.h"
#include "GridNotifiers.h"
#include "MapManager.h"
#include "Map.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"
#include "Opcodes.h"
#include "ObjectDefines.h"
#include "MapInstanced.h"
#include "World.h"

#include <cmath>

ObjectAccessor::ObjectAccessor()
{
}

ObjectAccessor::~ObjectAccessor()
{
}

WorldObject* ObjectAccessor::GetWorldObject(WorldObject const& p, uint64 guid)
{
    switch (GUID_HIPART(guid))
    {
        case HIGHGUID_PLAYER:        return GetPlayer(p, guid);
        case HIGHGUID_TRANSPORT:
        case HIGHGUID_MO_TRANSPORT:
        case HIGHGUID_GAMEOBJECT:    return GetGameObject(p, guid);
        case HIGHGUID_VEHICLE:
        case HIGHGUID_UNIT:          return GetCreature(p, guid);
        case HIGHGUID_PET:           return GetPet(p, guid);
        case HIGHGUID_DYNAMICOBJECT: return GetDynamicObject(p, guid);
        case HIGHGUID_CORPSE:        return GetCorpse(p, guid);
        default:                     return NULL;
    }
}

Object* ObjectAccessor::GetObjectByTypeMask(WorldObject const& p, uint64 guid, uint32 typemask)
{
    switch (GUID_HIPART(guid))
    {
        case HIGHGUID_ITEM:
            if (typemask & TYPEMASK_ITEM && p.GetTypeId() == TYPEID_PLAYER)
                return ((Player const&)p).GetItemByGuid(guid);
            break;
        case HIGHGUID_PLAYER:
            if (typemask & TYPEMASK_PLAYER)
                return GetPlayer(p, guid);
            break;
        case HIGHGUID_TRANSPORT:
        case HIGHGUID_MO_TRANSPORT:
        case HIGHGUID_GAMEOBJECT:
            if (typemask & TYPEMASK_GAMEOBJECT)
                return GetGameObject(p, guid);
            break;
        case HIGHGUID_UNIT:
        case HIGHGUID_VEHICLE:
            if (typemask & TYPEMASK_UNIT)
                return GetCreature(p, guid);
            break;
        case HIGHGUID_PET:
            if (typemask & TYPEMASK_UNIT)
                return GetPet(p, guid);
            break;
        case HIGHGUID_DYNAMICOBJECT:
            if (typemask & TYPEMASK_DYNAMICOBJECT)
                return GetDynamicObject(p, guid);
            break;
        case HIGHGUID_CORPSE:
            break;
    }

    return NULL;
}

Corpse* ObjectAccessor::GetCorpse(WorldObject const& u, uint64 guid)
{
    return GetObjectInMap(guid, u.GetMap(), (Corpse*)NULL);
}

GameObject* ObjectAccessor::GetGameObject(WorldObject const& u, uint64 guid)
{
    return GetObjectInMap(guid, u.GetMap(), (GameObject*)NULL);
}

DynamicObject* ObjectAccessor::GetDynamicObject(WorldObject const& u, uint64 guid)
{
    return GetObjectInMap(guid, u.GetMap(), (DynamicObject*)NULL);
}

Unit* ObjectAccessor::GetUnit(WorldObject const& u, uint64 guid)
{
    return GetObjectInMap(guid, u.GetMap(), (Unit*)NULL);
}

Creature* ObjectAccessor::GetCreature(WorldObject const& u, uint64 guid)
{
    return GetObjectInMap(guid, u.GetMap(), (Creature*)NULL);
}

Pet* ObjectAccessor::GetPet(WorldObject const& u, uint64 guid)
{
    return GetObjectInMap(guid, u.GetMap(), (Pet*)NULL);
}

Player* ObjectAccessor::GetPlayer(WorldObject const& u, uint64 guid)
{
    return GetObjectInMap(guid, u.GetMap(), (Player*)NULL);
}

Creature* ObjectAccessor::GetCreatureOrPetOrVehicle(WorldObject const& u, uint64 guid)
{
    if (IS_PET_GUID(guid))
        return GetPet(u, guid);

    if (IS_CRE_OR_VEH_GUID(guid))
        return GetCreature(u, guid);

    return NULL;
}

Pet* ObjectAccessor::FindPet(uint64 guid)
{
    return GetObjectInWorld(guid, (Pet*)NULL);
}

Player* ObjectAccessor::FindPlayer(uint64 guid)
{
    return GetObjectInWorld(guid, (Player*)NULL);
}

Unit* ObjectAccessor::FindUnit(uint64 guid)
{
    return GetObjectInWorld(guid, (Unit*)NULL);
}

Player* ObjectAccessor::FindPlayerByName(const char* name)
{
    TRINITY_READ_GUARD(HashMapHolder<Player>::LockType, *HashMapHolder<Player>::GetLock());
    HashMapHolder<Player>::MapType const& m = GetPlayers();
    for (HashMapHolder<Player>::MapType::const_iterator iter = m.begin(); iter != m.end(); ++iter)
        if (iter->second->IsInWorld() && strcmp(name, iter->second->GetName()) == 0)
            return iter->second;

    return NULL;
}

void ObjectAccessor::SaveAllPlayers()
{
    TRINITY_READ_GUARD(HashMapHolder<Player>::LockType, *HashMapHolder<Player>::GetLock());
    HashMapHolder<Player>::MapType const& m = GetPlayers();
    for (HashMapHolder<Player>::MapType::const_iterator itr = m.begin(); itr != m.end(); ++itr)
        itr->second->SaveToDB();
}

Corpse* ObjectAccessor::GetCorpseForPlayerGUID(uint64 guid)
{
    TRINITY_READ_GUARD(ACE_RW_Thread_Mutex, i_corpseLock);

    Player2CorpsesMapType::iterator iter = i_player2corpse.find(guid);
    if (iter == i_player2corpse.end())
        return NULL;

    ASSERT(iter->second->GetType() != CORPSE_BONES);

    return iter->second;
}

void ObjectAccessor::RemoveCorpse(Corpse* corpse)
{
    ASSERT(corpse && corpse->GetType() != CORPSE_BONES);

    if (corpse->IsInGrid())
    {
        corpse->DestroyForNearbyPlayers();
        corpse->GetMap()->RemoveFromMap(corpse, false);
    }
    else
        corpse->RemoveFromWorld();

    // Critical section
    {
        TRINITY_WRITE_GUARD(ACE_RW_Thread_Mutex, i_corpseLock);

        Player2CorpsesMapType::iterator iter = i_player2corpse.find(corpse->GetOwnerGUID());
        if (iter == i_player2corpse.end()) // TODO: Fix this
            return;

        // build mapid*cellid -> guid_set map
        CellCoord cellCoord = Trinity::ComputeCellCoord(corpse->GetPositionX(), corpse->GetPositionY());
        uint32 cell_id = (cellCoord.y_coord * TOTAL_NUMBER_OF_CELLS_PER_MAP) + cellCoord.x_coord;

        sObjectMgr->DeleteCorpseCellData(corpse->GetMapId(), cell_id, GUID_LOPART(corpse->GetOwnerGUID()));

        i_player2corpse.erase(iter);
    }
}

void ObjectAccessor::AddCorpse(Corpse* corpse)
{
    ASSERT(corpse && corpse->GetType() != CORPSE_BONES);

    // Critical section
    {
        TRINITY_WRITE_GUARD(ACE_RW_Thread_Mutex, i_corpseLock);

        ASSERT(i_player2corpse.find(corpse->GetOwnerGUID()) == i_player2corpse.end());
        i_player2corpse[corpse->GetOwnerGUID()] = corpse;

        // build mapid*cellid -> guid_set map
        CellCoord cellCoord = Trinity::ComputeCellCoord(corpse->GetPositionX(), corpse->GetPositionY());
        uint32 cell_id = (cellCoord.y_coord * TOTAL_NUMBER_OF_CELLS_PER_MAP) + cellCoord.x_coord;

        sObjectMgr->AddCorpseCellData(corpse->GetMapId(), cell_id, GUID_LOPART(corpse->GetOwnerGUID()), corpse->GetInstanceId());
    }
}

void ObjectAccessor::AddCorpsesToGrid(GridCoord const& gridpair, GridType& grid, Map* map)
{
    TRINITY_READ_GUARD(ACE_RW_Thread_Mutex, i_corpseLock);

    for (Player2CorpsesMapType::iterator iter = i_player2corpse.begin(); iter != i_player2corpse.end(); ++iter)
    {
        // We need this check otherwise a corpose may be added to a grid twice
        if (iter->second->IsInGrid())
            continue;

        if (iter->second->GetGridCoord() == gridpair)
        {
            // verify, if the corpse in our instance (add only corpses which are)
            if (map->Instanceable())
            {
                if (iter->second->GetInstanceId() == map->GetInstanceId())
                    grid.AddWorldObject(iter->second);
            }
            else
                grid.AddWorldObject(iter->second);
        }
    }
}

Corpse* ObjectAccessor::ConvertCorpseForPlayer(uint64 player_guid, bool insignia /*=false*/)
{
    Corpse* corpse = GetCorpseForPlayerGUID(player_guid);
    if (!corpse)
    {
        //in fact this function is called from several places
        //even when player doesn't have a corpse, not an error
        return NULL;
    }

    sLog->outStaticDebug("Deleting Corpse and spawned bones.");

    // Map can be NULL
    Map* map = corpse->FindMap();

    // remove corpse from player_guid -> corpse map and from current map
    RemoveCorpse(corpse);
    // remove corpse from DB
    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    corpse->DeleteFromDB(trans);
    CharacterDatabase.CommitTransaction(trans);

    Corpse* bones = NULL;
    // create the bones only if the map and the grid is loaded at the corpse's location
    // ignore bones creating option in case insignia

    if (map && (insignia ||
        (map->IsBattlegroundOrArena() ? sWorld->getBoolConfig(CONFIG_DEATH_BONES_BG_OR_ARENA) : sWorld->getBoolConfig(CONFIG_DEATH_BONES_WORLD))) &&
        !map->IsRemovalGrid(corpse->GetPositionX(), corpse->GetPositionY()))
    {
        // Create bones, don't change Corpse
        bones = new Corpse;
        bones->Create(corpse->GetGUIDLow(), map);

        for (uint8 i = OBJECT_FIELD_TYPE + 1; i < CORPSE_END; ++i)                    // don't overwrite guid and object type
            bones->SetUInt32Value(i, corpse->GetUInt32Value(i));

        bones->SetGridCoord(corpse->GetGridCoord());
        // bones->m_time = m_time;                              // don't overwrite time
        // bones->m_type = m_type;                              // don't overwrite type
        bones->Relocate(corpse->GetPositionX(), corpse->GetPositionY(), corpse->GetPositionZ(), corpse->GetOrientation());
        bones->SetPhaseMask(corpse->GetPhaseMask(), false);

        bones->SetUInt32Value(CORPSE_FIELD_FLAGS, CORPSE_FLAG_UNK2 | CORPSE_FLAG_BONES);
        bones->SetUInt64Value(CORPSE_FIELD_OWNER, 0);

        for (uint8 i = 0; i < EQUIPMENT_SLOT_END; ++i)
        {
            if (corpse->GetUInt32Value(CORPSE_FIELD_ITEM + i))
                bones->SetUInt32Value(CORPSE_FIELD_ITEM + i, 0);
        }

        // add bones in grid store if grid loaded where corpse placed
        map->AddToMap(bones);
    }

    // all references to the corpse should be removed at this point
    delete corpse;

    return bones;
}

void ObjectAccessor::RemoveOldCorpses()
{
    time_t now = time(NULL);
    Player2CorpsesMapType::iterator next;
    for (Player2CorpsesMapType::iterator itr = i_player2corpse.begin(); itr != i_player2corpse.end(); itr = next)
    {
        next = itr;
        ++next;

        if (!itr->second->IsExpired(now))
            continue;

        ConvertCorpseForPlayer(itr->first);
    }
}

void ObjectAccessor::Update(uint32 /*diff*/)
{
    UpdateDataMapType update_players;

    while (!i_objects.empty())
    {
        Object* obj = *i_objects.begin();
        ASSERT(obj && obj->IsInWorld());
        i_objects.erase(i_objects.begin());
        obj->BuildUpdate(update_players);
    }

    WorldPacket packet;                                     // here we allocate a std::vector with a size of 0x10000
    for (UpdateDataMapType::iterator iter = update_players.begin(); iter != update_players.end(); ++iter)
    {
        iter->second.BuildPacket(&packet);
        iter->first->GetSession()->SendPacket(&packet);
        packet.clear();                                     // clean the string
    }
}

void ObjectAccessor::UnloadAll()
{
    for (Player2CorpsesMapType::const_iterator itr = i_player2corpse.begin(); itr != i_player2corpse.end(); ++itr)
    {
        itr->second->RemoveFromWorld();
        delete itr->second;
    }
}

/// Define the static members of HashMapHolder

template <class T> UNORDERED_MAP< uint64, T* > HashMapHolder<T>::m_objectMap;
template <class T> typename HashMapHolder<T>::LockType HashMapHolder<T>::i_lock;

/// Global definitions for the hashmap storage

template class HashMapHolder<Player>;
template class HashMapHolder<Pet>;
template class HashMapHolder<GameObject>;
template class HashMapHolder<DynamicObject>;
template class HashMapHolder<Creature>;
template class HashMapHolder<Corpse>;

template Player* ObjectAccessor::GetObjectInWorld<Player>(uint32 mapid, float x, float y, uint64 guid, Player* /*fake*/);
template Pet* ObjectAccessor::GetObjectInWorld<Pet>(uint32 mapid, float x, float y, uint64 guid, Pet* /*fake*/);
template Creature* ObjectAccessor::GetObjectInWorld<Creature>(uint32 mapid, float x, float y, uint64 guid, Creature* /*fake*/);
template Corpse* ObjectAccessor::GetObjectInWorld<Corpse>(uint32 mapid, float x, float y, uint64 guid, Corpse* /*fake*/);
template GameObject* ObjectAccessor::GetObjectInWorld<GameObject>(uint32 mapid, float x, float y, uint64 guid, GameObject* /*fake*/);
template DynamicObject* ObjectAccessor::GetObjectInWorld<DynamicObject>(uint32 mapid, float x, float y, uint64 guid, DynamicObject* /*fake*/);