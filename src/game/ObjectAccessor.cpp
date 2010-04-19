/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Policies/SingletonImp.h"
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

#define CLASS_LOCK Trinity::ClassLevelLockable<ObjectAccessor, ACE_Thread_Mutex>
INSTANTIATE_SINGLETON_2(ObjectAccessor, CLASS_LOCK);
INSTANTIATE_CLASS_MUTEX(ObjectAccessor, ACE_Thread_Mutex);

ObjectAccessor::ObjectAccessor()
{
}

ObjectAccessor::~ObjectAccessor()
{
    for (Player2CorpsesMapType::const_iterator itr = i_player2corpse.begin(); itr != i_player2corpse.end(); ++itr)
    {
        itr->second->RemoveFromWorld();
        delete itr->second;
    }
}

Creature* ObjectAccessor::GetCreatureOrPetOrVehicle(WorldObject const& u, uint64 guid)
{
    if (IS_PLAYER_GUID(guid))
        return NULL;

    if (IS_PET_GUID(guid))
        return GetPet(guid);

    return u.IsInWorld() ? u.GetMap()->GetCreature(guid) : NULL;
}

Corpse* ObjectAccessor::GetCorpse(WorldObject const& u, uint64 guid)
{
    Corpse* ret = GetObjectInWorld(guid, (Corpse*)NULL);

    if (!ret)
        return NULL;

    if (ret->GetMapId() != u.GetMapId())
        return NULL;

    if (ret->GetInstanceId() != u.GetInstanceId())
        return NULL;

    return ret;
}

WorldObject* ObjectAccessor::GetWorldObject(WorldObject const& p, uint64 guid)
{
    switch (GUID_HIPART(guid))
    {
        case HIGHGUID_PLAYER:        return FindPlayer(guid);
        case HIGHGUID_GAMEOBJECT:    return p.GetMap()->GetGameObject(guid);
        case HIGHGUID_VEHICLE:
        case HIGHGUID_UNIT:          return p.GetMap()->GetCreature(guid);
        case HIGHGUID_PET:           return GetPet(guid);
        case HIGHGUID_DYNAMICOBJECT: return p.GetMap()->GetDynamicObject(guid);
        case HIGHGUID_TRANSPORT:     return NULL;
        case HIGHGUID_CORPSE:        return GetCorpse(p,guid);
        case HIGHGUID_MO_TRANSPORT:  return NULL;
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
                return FindPlayer(guid);
            break;
        case HIGHGUID_GAMEOBJECT:
            if (typemask & TYPEMASK_GAMEOBJECT)
                return p.GetMap()->GetGameObject(guid);
            break;
        case HIGHGUID_UNIT:
        case HIGHGUID_VEHICLE:
            if (typemask & TYPEMASK_UNIT)
                return p.GetMap()->GetCreature(guid);
            break;
        case HIGHGUID_PET:
            if (typemask & TYPEMASK_UNIT)
                return GetPet(guid);
            break;
        case HIGHGUID_DYNAMICOBJECT:
            if (typemask & TYPEMASK_DYNAMICOBJECT)
                return p.GetMap()->GetDynamicObject(guid);
            break;
        case HIGHGUID_TRANSPORT:
        case HIGHGUID_CORPSE:
        case HIGHGUID_MO_TRANSPORT:
            break;
    }

    return NULL;
}

Player* ObjectAccessor::FindPlayer(uint64 guid)
{
    Player* plr = GetObjectInWorld(guid, (Player*)NULL);
    if (!plr || !plr->IsInWorld())
        return NULL;

    return plr;
}

Player* ObjectAccessor::FindPlayerByName(const char* name)
{
    Guard guard(*HashMapHolder<Player>::GetLock());
    HashMapHolder<Player>::MapType& m = HashMapHolder<Player>::GetContainer();
    for (HashMapHolder<Player>::MapType::iterator iter = m.begin(); iter != m.end(); ++iter)
        if (iter->second->IsInWorld() && strcmp(name, iter->second->GetName()) == 0)
            return iter->second;

    return NULL;
}

void ObjectAccessor::SaveAllPlayers()
{
    Guard guard(*HashMapHolder<Player>::GetLock());
    HashMapHolder<Player>::MapType& m = HashMapHolder<Player>::GetContainer();
    for (HashMapHolder<Player>::MapType::iterator itr = m.begin(); itr != m.end(); ++itr)
        itr->second->SaveToDB();
}

Pet* ObjectAccessor::GetPet(uint64 guid)
{
    return GetObjectInWorld(guid, (Pet*)NULL);
}

Corpse* ObjectAccessor::GetCorpseForPlayerGUID(uint64 guid)
{
    Guard guard(i_corpseGuard);

    Player2CorpsesMapType::iterator iter = i_player2corpse.find(guid);
    if (iter == i_player2corpse.end())
        return NULL;

    assert(iter->second->GetType() != CORPSE_BONES);

    return iter->second;
}

void ObjectAccessor::RemoveCorpse(Corpse* corpse)
{
    assert(corpse && corpse->GetType() != CORPSE_BONES);

    if (corpse->FindMap())
        corpse->FindMap()->Remove(corpse, false);
    else
        corpse->RemoveFromWorld();

    // Critical section
    {
        Guard guard(i_corpseGuard);

        Player2CorpsesMapType::iterator iter = i_player2corpse.find(corpse->GetOwnerGUID());
        if (iter == i_player2corpse.end()) // TODO: Fix this
            return;

        // build mapid*cellid -> guid_set map
        CellPair cell_pair = Trinity::ComputeCellPair(corpse->GetPositionX(), corpse->GetPositionY());
        uint32 cell_id = (cell_pair.y_coord * TOTAL_NUMBER_OF_CELLS_PER_MAP) + cell_pair.x_coord;

        objmgr.DeleteCorpseCellData(corpse->GetMapId(), cell_id, corpse->GetOwnerGUID());

        i_player2corpse.erase(iter);
    }
}

void ObjectAccessor::AddCorpse(Corpse* corpse)
{
    assert(corpse && corpse->GetType() != CORPSE_BONES);

    // Critical section
    {
        Guard guard(i_corpseGuard);

        assert(i_player2corpse.find(corpse->GetOwnerGUID()) == i_player2corpse.end());
        i_player2corpse[corpse->GetOwnerGUID()] = corpse;

        // build mapid*cellid -> guid_set map
        CellPair cell_pair = Trinity::ComputeCellPair(corpse->GetPositionX(), corpse->GetPositionY());
        uint32 cell_id = (cell_pair.y_coord * TOTAL_NUMBER_OF_CELLS_PER_MAP) + cell_pair.x_coord;

        objmgr.AddCorpseCellData(corpse->GetMapId(), cell_id, corpse->GetOwnerGUID(), corpse->GetInstanceId());
    }
}

void ObjectAccessor::AddCorpsesToGrid(GridPair const& gridpair, GridType& grid, Map* map)
{
    Guard guard(i_corpseGuard);

    for (Player2CorpsesMapType::iterator iter = i_player2corpse.begin(); iter != i_player2corpse.end(); ++iter)
    {
        if (iter->second->GetGrid() == gridpair)
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

Corpse* ObjectAccessor::ConvertCorpseForPlayer(uint64 player_guid, bool /*insignia*/)
{
    Corpse* corpse = GetCorpseForPlayerGUID(player_guid);
    if (!corpse)
    {
        //in fact this function is called from several places
        //even when player doesn't have a corpse, not an error
        // TODO: really, now...
        //sLog.outError("Try remove corpse that not in map for GUID %ul", player_guid);
        return NULL;
    }

    DEBUG_LOG("Deleting Corpse and spawning bones.");

    //Map* map = corpse->FindMap();

    // remove corpse from player_guid -> corpse map
    RemoveCorpse(corpse);

    // done in removecorpse
    // remove resurrectable corpse from grid object registry (loaded state checked into call)
    // do not load the map if it's not loaded
    //Map *map = MapManager::Instance().FindMap(corpse->GetMapId(), corpse->GetInstanceId());
    //if (map)
    //    map->Remove(corpse, false);

    // remove corpse from DB
    corpse->DeleteFromDB();

    // we don't want bones to save some cpu.. :)
    delete corpse;
    return NULL;

    /*
    Corpse* bones = NULL;
    // create the bones only if the map and the grid is loaded at the corpse's location
    // ignore bones creating option in case insignia
    if (map && (insignia ||
        (map->IsBattleGroundOrArena() ? sWorld.getConfig(CONFIG_DEATH_BONES_BG_OR_ARENA) : sWorld.getConfig(CONFIG_DEATH_BONES_WORLD))) &&
        !map->IsRemovalGrid(corpse->GetPositionX(), corpse->GetPositionY()))
    {
        // Create bones, don't change Corpse
        bones = new Corpse;
        bones->Create(corpse->GetGUIDLow(), map);

        for (int i = 3; i < CORPSE_END; ++i)                    // don't overwrite guid and object type
            bones->SetUInt32Value(i, corpse->GetUInt32Value(i));

        bones->SetGrid(corpse->GetGrid());
        // bones->m_time = m_time;                              // don't overwrite time
        // bones->m_inWorld = m_inWorld;                        // don't overwrite in-world state
        // bones->m_type = m_type;                              // don't overwrite type
        bones->Relocate(corpse->GetPositionX(), corpse->GetPositionY(), corpse->GetPositionZ(), corpse->GetOrientation());
        bones->SetPhaseMask(corpse->GetPhaseMask(), false);

        bones->SetUInt32Value(CORPSE_FIELD_FLAGS, CORPSE_FLAG_UNK2 | CORPSE_FLAG_BONES);
        bones->SetUInt64Value(CORPSE_FIELD_OWNER, 0);

        for (int i = 0; i < EQUIPMENT_SLOT_END; ++i)
        {
            if (corpse->GetUInt32Value(CORPSE_FIELD_ITEM + i))
                bones->SetUInt32Value(CORPSE_FIELD_ITEM + i, 0);
        }

        // add bones in grid store if grid loaded where corpse placed
        map->Add(bones);
    }

    // all references to the corpse should be removed at this point
    delete corpse;

    return bones;
    */
}

void ObjectAccessor::Update(uint32 /*diff*/)
{
    UpdateDataMapType update_players;

    // Critical section
    {
        Guard guard(i_updateGuard);

        while (!i_objects.empty())
        {
            Object* obj = *i_objects.begin();
            assert(obj && obj->IsInWorld());
            i_objects.erase(i_objects.begin());
            obj->BuildUpdate(update_players);
        }
    }

    WorldPacket packet;                                     // here we allocate a std::vector with a size of 0x10000
    for (UpdateDataMapType::iterator iter = update_players.begin(); iter != update_players.end(); ++iter)
    {
        iter->second.BuildPacket(&packet);
        iter->first->GetSession()->SendPacket(&packet);
        packet.clear();                                     // clean the string
    }
}

/// Define the static members of HashMapHolder

template <class T> UNORDERED_MAP< uint64, T* > HashMapHolder<T>::m_objectMap;
template <class T> ACE_Thread_Mutex HashMapHolder<T>::i_lock;

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
