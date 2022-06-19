/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "Corpse.h"
#include "Creature.h"
#include "DynamicObject.h"
#include "GameObject.h"
#include "GridNotifiers.h"
#include "Item.h"
#include "Map.h"
#include "ObjectDefines.h"
#include "ObjectMgr.h"
#include "Pet.h"
#include "Player.h"
#include "Transport.h"
#include "World.h"

template<class T>
void HashMapHolder<T>::Insert(T* o)
{
    static_assert(std::is_same<Player, T>::value,
        "Only Player can be registered in global HashMapHolder");

    std::unique_lock<std::shared_mutex> lock(*GetLock());

    GetContainer()[o->GetGUID()] = o;
}

template<class T>
void HashMapHolder<T>::Remove(T* o)
{
    std::unique_lock<std::shared_mutex> lock(*GetLock());

    GetContainer().erase(o->GetGUID());
}

template<class T>
T* HashMapHolder<T>::Find(ObjectGuid guid)
{
    std::shared_lock<std::shared_mutex> lock(*GetLock());

    typename MapType::iterator itr = GetContainer().find(guid);
    return (itr != GetContainer().end()) ? itr->second : nullptr;
}

template<class T>
auto HashMapHolder<T>::GetContainer() -> MapType&
{
    static MapType _objectMap;
    return _objectMap;
}

template<class T>
std::shared_mutex* HashMapHolder<T>::GetLock()
{
    static std::shared_mutex _lock;
    return &_lock;
}

HashMapHolder<Player>::MapType const& ObjectAccessor::GetPlayers()
{
    return HashMapHolder<Player>::GetContainer();
}

template class TC_GAME_API HashMapHolder<Player>;

namespace PlayerNameMapHolder
{
typedef std::unordered_map<std::string, Player*> MapType;
static MapType PlayerNameMap;

void Insert(Player* p)
{
    PlayerNameMap[p->GetName()] = p;
}

void Remove(Player* p)
{
    PlayerNameMap.erase(p->GetName());
}

Player* Find(std::string const& name)
{
    std::string charName(name);
    if (!normalizePlayerName(charName))
        return nullptr;

    auto itr = PlayerNameMap.find(charName);
    return (itr != PlayerNameMap.end()) ? itr->second : nullptr;
}
} // namespace PlayerNameMapHolder

WorldObject* ObjectAccessor::GetWorldObject(WorldObject const& p, ObjectGuid const& guid)
{
    switch (guid.GetHigh())
    {
        case HighGuid::Player:        return GetPlayer(p, guid);
        case HighGuid::Transport:
        case HighGuid::Mo_Transport:
        case HighGuid::GameObject:    return GetGameObject(p, guid);
        case HighGuid::Vehicle:
        case HighGuid::Unit:          return GetCreature(p, guid);
        case HighGuid::Pet:           return GetPet(p, guid);
        case HighGuid::DynamicObject: return GetDynamicObject(p, guid);
        case HighGuid::AreaTrigger:   return GetAreaTrigger(p, guid);
        case HighGuid::Corpse:        return GetCorpse(p, guid);
        default:                      return nullptr;
    }
}

Object* ObjectAccessor::GetObjectByTypeMask(WorldObject const& p, ObjectGuid const& guid, uint32 typemask)
{
    switch (guid.GetHigh())
    {
        case HighGuid::Item:
            if (typemask & TYPEMASK_ITEM && p.GetTypeId() == TYPEID_PLAYER)
                return ((Player const&)p).GetItemByGuid(guid);
            break;
        case HighGuid::Player:
            if (typemask & TYPEMASK_PLAYER)
                return GetPlayer(p, guid);
            break;
        case HighGuid::Transport:
        case HighGuid::Mo_Transport:
        case HighGuid::GameObject:
            if (typemask & TYPEMASK_GAMEOBJECT)
                return GetGameObject(p, guid);
            break;
        case HighGuid::Unit:
        case HighGuid::Vehicle:
            if (typemask & TYPEMASK_UNIT)
                return GetCreature(p, guid);
            break;
        case HighGuid::Pet:
            if (typemask & TYPEMASK_UNIT)
                return GetPet(p, guid);
            break;
        case HighGuid::DynamicObject:
            if (typemask & TYPEMASK_DYNAMICOBJECT)
                return GetDynamicObject(p, guid);
            break;
        case HighGuid::AreaTrigger:
            if (typemask & TYPEMASK_AREATRIGGER)
                return GetAreaTrigger(p, guid);
            break;
        case HighGuid::Corpse:
            break;
        default:
            break;
    }

    return nullptr;
}

Corpse* ObjectAccessor::GetCorpse(WorldObject const& u, ObjectGuid const& guid)
{
    return u.GetMap()->GetCorpse(guid);
}

GameObject* ObjectAccessor::GetGameObject(WorldObject const& u, ObjectGuid const& guid)
{
    return u.GetMap()->GetGameObject(guid);
}

Transport* ObjectAccessor::GetTransport(WorldObject const& u, ObjectGuid const& guid)
{
    return u.GetMap()->GetTransport(guid);
}

DynamicObject* ObjectAccessor::GetDynamicObject(WorldObject const& u, ObjectGuid const& guid)
{
    return u.GetMap()->GetDynamicObject(guid);
}

AreaTrigger* ObjectAccessor::GetAreaTrigger(WorldObject const& u, ObjectGuid const& guid)
{
    return u.GetMap()->GetAreaTrigger(guid);
}

Unit* ObjectAccessor::GetUnit(WorldObject const& u, ObjectGuid const& guid)
{
    if (guid.IsPlayer())
        return GetPlayer(u, guid);

    if (guid.IsPet())
        return GetPet(u, guid);

    return GetCreature(u, guid);
}

Creature* ObjectAccessor::GetCreature(WorldObject const& u, ObjectGuid const& guid)
{
    return u.GetMap()->GetCreature(guid);
}

Pet* ObjectAccessor::GetPet(WorldObject const& u, ObjectGuid const& guid)
{
    return u.GetMap()->GetPet(guid);
}

Player* ObjectAccessor::GetPlayer(Map const* m, ObjectGuid const& guid)
{
    if (Player* player = HashMapHolder<Player>::Find(guid))
        if (player->IsInWorld() && player->GetMap() == m)
            return player;

    return nullptr;
}

Player* ObjectAccessor::GetPlayer(WorldObject const& u, ObjectGuid const& guid)
{
    return GetPlayer(u.GetMap(), guid);
}

Creature* ObjectAccessor::GetCreatureOrPetOrVehicle(WorldObject const& u, ObjectGuid const& guid)
{
    if (guid.IsPet())
        return GetPet(u, guid);

    if (guid.IsCreatureOrVehicle())
        return GetCreature(u, guid);

    return nullptr;
}

Player* ObjectAccessor::FindPlayer(ObjectGuid const& guid)
{
    Player* player = HashMapHolder<Player>::Find(guid);
    return player && player->IsInWorld() ? player : nullptr;
}

Player* ObjectAccessor::FindPlayerByName(std::string const& name)
{
    Player* player = PlayerNameMapHolder::Find(name);
    if (!player || !player->IsInWorld())
        return nullptr;

    return player;
}

Player* ObjectAccessor::FindPlayerByLowGUID(ObjectGuid::LowType lowguid)
{
    ObjectGuid guid(HighGuid::Player, lowguid);
    return ObjectAccessor::FindPlayer(guid);
}

Player* ObjectAccessor::FindConnectedPlayer(ObjectGuid const& guid)
{
    return HashMapHolder<Player>::Find(guid);
}

Player* ObjectAccessor::FindConnectedPlayerByName(std::string const& name)
{
    return PlayerNameMapHolder::Find(name);
}

void ObjectAccessor::SaveAllPlayers()
{
    std::shared_lock<std::shared_mutex> lock(*HashMapHolder<Player>::GetLock());

    HashMapHolder<Player>::MapType const& m = GetPlayers();
    for (HashMapHolder<Player>::MapType::const_iterator itr = m.begin(); itr != m.end(); ++itr)
        itr->second->SaveToDB();
}

template<>
void ObjectAccessor::AddObject(Player* player)
{
    HashMapHolder<Player>::Insert(player);
    PlayerNameMapHolder::Insert(player);
}

template<>
void ObjectAccessor::RemoveObject(Player* player)
{
    HashMapHolder<Player>::Remove(player);
    PlayerNameMapHolder::Remove(player);
}
