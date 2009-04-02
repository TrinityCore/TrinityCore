/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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

#define CLASS_LOCK Trinity::ClassLevelLockable<ObjectAccessor, ZThread::FastMutex>
INSTANTIATE_SINGLETON_2(ObjectAccessor, CLASS_LOCK);
INSTANTIATE_CLASS_MUTEX(ObjectAccessor, ZThread::FastMutex);

ObjectAccessor::ObjectAccessor() {}
ObjectAccessor::~ObjectAccessor() {}

Creature*
ObjectAccessor::GetNPCIfCanInteractWith(Player const &player, uint64 guid, uint32 npcflagmask)
{
    // unit checks
    if (!guid)
        return NULL;

    // exist
    Creature *unit = GetCreature(player, guid);
    if (!unit)
        return NULL;

    // player check
    if(!player.CanInteractWithNPCs(!unit->isSpiritService()))
        return NULL;

    // appropriate npc type
    if(npcflagmask && !unit->HasFlag( UNIT_NPC_FLAGS, npcflagmask ))
        return NULL;

    // alive or spirit healer
    if(!unit->isAlive() && (!unit->isSpiritService() || player.isAlive() ))
        return NULL;

    // not allow interaction under control
    if(unit->GetCharmerOrOwnerGUID())
        return NULL;

    // not enemy
    if( unit->IsHostileTo(&player))
        return NULL;

    // not unfriendly
    if(FactionTemplateEntry const* factionTemplate = sFactionTemplateStore.LookupEntry(unit->getFaction()))
        if(factionTemplate->faction)
            if(FactionEntry const* faction = sFactionStore.LookupEntry(factionTemplate->faction))
                if(faction->reputationListID >= 0 && player.GetReputationMgr().GetRank(faction) <= REP_UNFRIENDLY)
                    return NULL;

    // not too far
    if(!unit->IsWithinDistInMap(&player,INTERACTION_DISTANCE))
        return NULL;

    return unit;
}

Creature*
ObjectAccessor::GetCreatureOrPetOrVehicle(WorldObject const &u, uint64 guid)
{
    if(Creature *unit = GetPet(guid))
        return unit;

    if(Creature *unit = GetVehicle(guid))
        return unit;

    return GetCreature(u, guid);
}

Creature*
ObjectAccessor::GetCreature(WorldObject const &u, uint64 guid)
{
    Creature * ret = GetObjectInWorld(guid, (Creature*)NULL);
    if(!ret)
        return NULL;

    if(ret->GetMapId() != u.GetMapId())
        return NULL;

    if(ret->GetInstanceId() != u.GetInstanceId())
        return NULL;

    return ret;
}

Unit*
ObjectAccessor::GetUnit(WorldObject const &u, uint64 guid)
{
    if(!guid)
        return NULL;

    if(IS_PLAYER_GUID(guid))
        return FindPlayer(guid);

    return GetCreatureOrPetOrVehicle(u, guid);
}

Corpse*
ObjectAccessor::GetCorpse(WorldObject const &u, uint64 guid)
{
    Corpse * ret = GetObjectInWorld(guid, (Corpse*)NULL);
    if(!ret)
        return NULL;
    if(ret->GetMapId() != u.GetMapId())
        return NULL;
    if(ret->GetInstanceId() != u.GetInstanceId())
        return NULL;
    return ret;
}

Object* ObjectAccessor::GetObjectByTypeMask(WorldObject const &p, uint64 guid, uint32 typemask)
{
    Object *obj = NULL;

    if(typemask & TYPEMASK_PLAYER)
    {
        obj = FindPlayer(guid);
        if(obj) return obj;
    }

    if(typemask & TYPEMASK_UNIT)
    {
        obj = GetCreatureOrPetOrVehicle(p,guid);
        if(obj) return obj;
    }

    if(typemask & TYPEMASK_GAMEOBJECT)
    {
        obj = GetGameObject(p,guid);
        if(obj) return obj;
    }

    if(typemask & TYPEMASK_DYNAMICOBJECT)
    {
        obj = GetDynamicObject(p,guid);
        if(obj) return obj;
    }

    if(typemask & TYPEMASK_ITEM && p.GetTypeId() == TYPEID_PLAYER)
    {
        obj = ((Player const &)p).GetItemByGuid( guid );
        if(obj) return obj;
    }

    return NULL;
}

GameObject*
ObjectAccessor::GetGameObject(WorldObject const &u, uint64 guid)
{
    GameObject * ret = GetObjectInWorld(guid, (GameObject*)NULL);
    if(!ret)
        return NULL;
    if(ret->GetMapId() != u.GetMapId())
        return NULL;
    if(ret->GetInstanceId() != u.GetInstanceId())
        return NULL;
    return ret;
}

DynamicObject*
ObjectAccessor::GetDynamicObject(WorldObject const &u, uint64 guid)
{
    DynamicObject * ret = GetObjectInWorld(guid, (DynamicObject*)NULL);
    if(!ret)
        return NULL;
    if(ret->GetMapId() != u.GetMapId())
        return NULL;
    if(ret->GetInstanceId() != u.GetInstanceId())
        return NULL;
    return ret;
}

Player*
ObjectAccessor::FindPlayer(uint64 guid)
{
    return GetObjectInWorld(guid, (Player*)NULL);
}

Player*
ObjectAccessor::FindPlayerByName(const char *name)
{
    //TODO: Player Guard
    HashMapHolder<Player>::MapType& m = HashMapHolder<Player>::GetContainer();
    HashMapHolder<Player>::MapType::iterator iter = m.begin();
    for(; iter != m.end(); ++iter)
        if( ::strcmp(name, iter->second->GetName()) == 0 )
            return iter->second;
    return NULL;
}

void
ObjectAccessor::SaveAllPlayers()
{
    Guard guard(*HashMapHolder<Player*>::GetLock());
    HashMapHolder<Player>::MapType& m = HashMapHolder<Player>::GetContainer();
    HashMapHolder<Player>::MapType::iterator itr = m.begin();
    for(; itr != m.end(); ++itr)
        itr->second->SaveToDB();
}

void
ObjectAccessor::UpdateObject(Object* obj, Player* exceptPlayer)
{
    UpdateDataMapType update_players;
    obj->BuildUpdate(update_players);

    WorldPacket packet;
    for(UpdateDataMapType::iterator iter = update_players.begin(); iter != update_players.end(); ++iter)
    {
        if(iter->first == exceptPlayer)
            continue;

        iter->second.BuildPacket(&packet);
        iter->first->GetSession()->SendPacket(&packet);
        packet.clear();
    }
}

void
ObjectAccessor::_buildUpdateObject(Object *obj, UpdateDataMapType &update_players)
{
    if(obj->isType(TYPEMASK_ITEM))
    {
        if(Player *owner = ((Item*)obj)->GetOwner())
           _buildPacket(owner, obj, update_players);
    }
    else
        _buildChangeObjectForPlayer((WorldObject*)obj, update_players);
}

void
ObjectAccessor::_buildPacket(Player *pl, Object *obj, UpdateDataMapType &update_players)
{
    UpdateDataMapType::iterator iter = update_players.find(pl);

    if( iter == update_players.end() )
    {
        std::pair<UpdateDataMapType::iterator, bool> p = update_players.insert( UpdateDataValueType(pl, UpdateData()) );
        assert(p.second);
        iter = p.first;
    }

    obj->BuildValuesUpdateBlockForPlayer(&iter->second, iter->first);
}

void
ObjectAccessor::_buildChangeObjectForPlayer(WorldObject *obj, UpdateDataMapType &update_players)
{
    CellPair p = Trinity::ComputeCellPair(obj->GetPositionX(), obj->GetPositionY());
    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();
    WorldObjectChangeAccumulator notifier(*obj, update_players);
    TypeContainerVisitor<WorldObjectChangeAccumulator, WorldTypeMapContainer > player_notifier(notifier);
    CellLock<GridReadGuard> cell_lock(cell, p);
    cell_lock->Visit(cell_lock, player_notifier, *obj->GetMap());
}

Pet*
ObjectAccessor::GetPet(uint64 guid)
{
    return GetObjectInWorld(guid, (Pet*)NULL);
}

Vehicle*
ObjectAccessor::GetVehicle(uint64 guid)
{
    return GetObjectInWorld(guid, (Vehicle*)NULL);
}

Corpse*
ObjectAccessor::GetCorpseForPlayerGUID(uint64 guid)
{
    Guard guard(i_corpseGuard);

    Player2CorpsesMapType::iterator iter = i_player2corpse.find(guid);
    if( iter == i_player2corpse.end() ) return NULL;

    assert(iter->second->GetType() != CORPSE_BONES);

    return iter->second;
}

void
ObjectAccessor::RemoveCorpse(Corpse *corpse)
{
    assert(corpse && corpse->GetType() != CORPSE_BONES);

    Guard guard(i_corpseGuard);
    Player2CorpsesMapType::iterator iter = i_player2corpse.find(corpse->GetOwnerGUID());
    if( iter == i_player2corpse.end() )
        return;

    // build mapid*cellid -> guid_set map
    CellPair cell_pair = Trinity::ComputeCellPair(corpse->GetPositionX(), corpse->GetPositionY());
    uint32 cell_id = (cell_pair.y_coord*TOTAL_NUMBER_OF_CELLS_PER_MAP) + cell_pair.x_coord;

    objmgr.DeleteCorpseCellData(corpse->GetMapId(),cell_id,corpse->GetOwnerGUID());
    corpse->RemoveFromWorld();

    i_player2corpse.erase(iter);
}

void
ObjectAccessor::AddCorpse(Corpse *corpse)
{
    assert(corpse && corpse->GetType() != CORPSE_BONES);

    Guard guard(i_corpseGuard);
    assert(i_player2corpse.find(corpse->GetOwnerGUID()) == i_player2corpse.end());
    i_player2corpse[corpse->GetOwnerGUID()] = corpse;

    // build mapid*cellid -> guid_set map
    CellPair cell_pair = Trinity::ComputeCellPair(corpse->GetPositionX(), corpse->GetPositionY());
    uint32 cell_id = (cell_pair.y_coord*TOTAL_NUMBER_OF_CELLS_PER_MAP) + cell_pair.x_coord;

    objmgr.AddCorpseCellData(corpse->GetMapId(),cell_id,corpse->GetOwnerGUID(),corpse->GetInstanceId());
}

void
ObjectAccessor::AddCorpsesToGrid(GridPair const& gridpair,GridType& grid,Map* map)
{
    Guard guard(i_corpseGuard);
    for(Player2CorpsesMapType::iterator iter = i_player2corpse.begin(); iter != i_player2corpse.end(); ++iter)
        if(iter->second->GetGrid()==gridpair)
    {
        // verify, if the corpse in our instance (add only corpses which are)
        if (map->Instanceable())
        {
            if (iter->second->GetInstanceId() == map->GetInstanceId())
            {
                grid.AddWorldObject(iter->second,iter->second->GetGUID());
            }
        }
        else
        {
            grid.AddWorldObject(iter->second,iter->second->GetGUID());
        }
    }
}

Corpse*
ObjectAccessor::ConvertCorpseForPlayer(uint64 player_guid, bool insignia)
{
    Corpse *corpse = GetCorpseForPlayerGUID(player_guid);
    if(!corpse)
    {
        //in fact this function is called from several places
        //even when player doesn't have a corpse, not an error
        //sLog.outError("Try remove corpse that not in map for GUID %ul", player_guid);
        return NULL;
    }

    DEBUG_LOG("Deleting Corpse and spawning bones.");

    // remove corpse from player_guid -> corpse map
    RemoveCorpse(corpse);

    // remove resurrectble corpse from grid object registry (loaded state checked into call)
    // do not load the map if it's not loaded
    Map *map = MapManager::Instance().FindMap(corpse->GetMapId(), corpse->GetInstanceId());
    if(map) map->Remove(corpse,false);

    // remove corpse from DB
    corpse->DeleteFromDB();

    Corpse *bones = NULL;
    // create the bones only if the map and the grid is loaded at the corpse's location
    // ignore bones creating option in case insignia
    if (map && (insignia ||
        (map->IsBattleGroundOrArena() ? sWorld.getConfig(CONFIG_DEATH_BONES_BG_OR_ARENA) : sWorld.getConfig(CONFIG_DEATH_BONES_WORLD))) &&
        !map->IsRemovalGrid(corpse->GetPositionX(), corpse->GetPositionY()))
    {
        // Create bones, don't change Corpse
        bones = new Corpse;
        bones->Create(corpse->GetGUIDLow());

        for (int i = 3; i < CORPSE_END; i++)                    // don't overwrite guid and object type
            bones->SetUInt32Value(i, corpse->GetUInt32Value(i));

        bones->SetGrid(corpse->GetGrid());
        // bones->m_time = m_time;                              // don't overwrite time
        // bones->m_inWorld = m_inWorld;                        // don't overwrite world state
        // bones->m_type = m_type;                              // don't overwrite type
        bones->Relocate(corpse->GetPositionX(), corpse->GetPositionY(), corpse->GetPositionZ(), corpse->GetOrientation());
        bones->SetMapId(corpse->GetMapId());
        bones->SetInstanceId(corpse->GetInstanceId());
        bones->SetPhaseMask(corpse->GetPhaseMask(),false);

        bones->SetUInt32Value(CORPSE_FIELD_FLAGS, CORPSE_FLAG_UNK2 | CORPSE_FLAG_BONES);
        bones->SetUInt64Value(CORPSE_FIELD_OWNER, 0);

        for (int i = 0; i < EQUIPMENT_SLOT_END; i++)
        {
            if(corpse->GetUInt32Value(CORPSE_FIELD_ITEM + i))
                bones->SetUInt32Value(CORPSE_FIELD_ITEM + i, 0);
        }

        // add bones in grid store if grid loaded where corpse placed
        map->Add(bones);
    }

    // all references to the corpse should be removed at this point
    delete corpse;

    return bones;
}

void
ObjectAccessor::Update(uint32 diff)
{
    UpdateDataMapType update_players;
    {
        Guard guard(i_updateGuard);
        while(!i_objects.empty())
        {
            Object* obj = *i_objects.begin();
            assert(obj && obj->IsInWorld());
            i_objects.erase(i_objects.begin());
            _buildUpdateObject(obj, update_players);
            obj->ClearUpdateMask(false);
        }
    }

    WorldPacket packet;                                     // here we allocate a std::vector with a size of 0x10000
    for(UpdateDataMapType::iterator iter = update_players.begin(); iter != update_players.end(); ++iter)
    {
        iter->second.BuildPacket(&packet);
        iter->first->GetSession()->SendPacket(&packet);
        packet.clear();                                     // clean the string
    }
}

void
ObjectAccessor::UpdatePlayers(uint32 diff)
{
    HashMapHolder<Player>::MapType& playerMap = HashMapHolder<Player>::GetContainer();
    for(HashMapHolder<Player>::MapType::iterator iter = playerMap.begin(); iter != playerMap.end(); ++iter)
        if(iter->second->IsInWorld())
            iter->second->Update(diff);
}

void
ObjectAccessor::WorldObjectChangeAccumulator::Visit(PlayerMapType &m)
{
    for(PlayerMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        BuildPacket(iter->getSource());
        if (!iter->getSource()->GetSharedVisionList().empty())
        {
            SharedVisionList::const_iterator it = iter->getSource()->GetSharedVisionList().begin();
            for ( ; it != iter->getSource()->GetSharedVisionList().end(); ++it)
                BuildPacket(*it);
        }
    }
}

void
ObjectAccessor::WorldObjectChangeAccumulator::Visit(CreatureMapType &m)
{
    for(CreatureMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        if (!iter->getSource()->GetSharedVisionList().empty())
        {
            SharedVisionList::const_iterator it = iter->getSource()->GetSharedVisionList().begin();
            for ( ; it != iter->getSource()->GetSharedVisionList().end(); ++it)
                BuildPacket(*it);
        }
    }
}

void
ObjectAccessor::WorldObjectChangeAccumulator::Visit(DynamicObjectMapType &m)
{
    for(DynamicObjectMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        if (IS_PLAYER_GUID(iter->getSource()->GetCasterGUID()))
        {
            Player* caster = (Player*)iter->getSource()->GetCaster();
            if (caster->GetUInt64Value(PLAYER_FARSIGHT) == iter->getSource()->GetGUID())
                BuildPacket(caster);
        }
    }
}

void
ObjectAccessor::WorldObjectChangeAccumulator::BuildPacket(Player* plr)
{
    // Only send update once to a player
    if (plr_list.find(plr->GetGUID()) == plr_list.end() && plr->HaveAtClient(&i_object))
    {
        ObjectAccessor::_buildPacket(plr, &i_object, i_updateDatas);
        plr_list.insert(plr->GetGUID());
    }
}

void
ObjectAccessor::UpdateObjectVisibility(WorldObject *obj)
{
    CellPair p = Trinity::ComputeCellPair(obj->GetPositionX(), obj->GetPositionY());
    Cell cell(p);

    obj->GetMap()->UpdateObjectVisibility(obj,cell,p);
}

/*void ObjectAccessor::UpdateVisibilityForPlayer( Player* player )
{
    CellPair p = Trinity::ComputeCellPair(player->GetPositionX(), player->GetPositionY());
    Cell cell(p);
    Map* m = player->GetMap();

    m->UpdatePlayerVisibility(player,cell,p);
    m->UpdateObjectsVisibilityFor(player,cell,p);
}*/

/// Define the static member of HashMapHolder

template <class T> UNORDERED_MAP< uint64, T* > HashMapHolder<T>::m_objectMap;
template <class T> ZThread::FastMutex HashMapHolder<T>::i_lock;

/// Global definitions for the hashmap storage

template class HashMapHolder<Player>;
template class HashMapHolder<Pet>;
template class HashMapHolder<Vehicle>;
template class HashMapHolder<GameObject>;
template class HashMapHolder<DynamicObject>;
template class HashMapHolder<Creature>;
template class HashMapHolder<Corpse>;

template Player* ObjectAccessor::GetObjectInWorld<Player>(uint32 mapid, float x, float y, uint64 guid, Player* /*fake*/);
template Pet* ObjectAccessor::GetObjectInWorld<Pet>(uint32 mapid, float x, float y, uint64 guid, Pet* /*fake*/);
template Vehicle* ObjectAccessor::GetObjectInWorld<Vehicle>(uint32 mapid, float x, float y, uint64 guid, Vehicle* /*fake*/);
template Creature* ObjectAccessor::GetObjectInWorld<Creature>(uint32 mapid, float x, float y, uint64 guid, Creature* /*fake*/);
template Corpse* ObjectAccessor::GetObjectInWorld<Corpse>(uint32 mapid, float x, float y, uint64 guid, Corpse* /*fake*/);
template GameObject* ObjectAccessor::GetObjectInWorld<GameObject>(uint32 mapid, float x, float y, uint64 guid, GameObject* /*fake*/);
template DynamicObject* ObjectAccessor::GetObjectInWorld<DynamicObject>(uint32 mapid, float x, float y, uint64 guid, DynamicObject* /*fake*/);

