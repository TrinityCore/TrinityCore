/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITY_OBJECTACCESSOR_H
#define TRINITY_OBJECTACCESSOR_H

#include <mutex>
#include <set>
#include <unordered_map>
#include <boost/thread/locks.hpp>
#include <boost/thread/shared_mutex.hpp>

#include "Define.h"
#include "GridDefines.h"
#include "UpdateData.h"
#include "Object.h"

class Creature;
class Corpse;
class Unit;
class GameObject;
class DynamicObject;
class WorldObject;
class Vehicle;
class Map;
class WorldRunnable;
class Transport;

template <class T>
class HashMapHolder
{
    public:
        static_assert(std::is_same<Player, T>::value
            || std::is_same<Transport, T>::value,
            "Only Player and Transport can be registered in global HashMapHolder");

        typedef std::unordered_map<ObjectGuid, T*> MapType;

        static void Insert(T* o)
        {
            boost::unique_lock<boost::shared_mutex> lock(_lock);

            _objectMap[o->GetGUID()] = o;
        }

        static void Remove(T* o)
        {
            boost::unique_lock<boost::shared_mutex> lock(_lock);

            _objectMap.erase(o->GetGUID());
        }

        static T* Find(ObjectGuid guid)
        {
            boost::shared_lock<boost::shared_mutex> lock(_lock);

            typename MapType::iterator itr = _objectMap.find(guid);
            return (itr != _objectMap.end()) ? itr->second : NULL;
        }

        static MapType& GetContainer() { return _objectMap; }

        static boost::shared_mutex* GetLock() { return &_lock; }

    private:
        //Non instanceable only static
        HashMapHolder() { }

        static boost::shared_mutex _lock;
        static MapType _objectMap;
};

namespace ObjectAccessor
{
    // these functions return objects only if in map of specified object
    WorldObject* GetWorldObject(WorldObject const&, ObjectGuid const&);
    Object* GetObjectByTypeMask(WorldObject const&, ObjectGuid const&, uint32 typemask);
    Corpse* GetCorpse(WorldObject const& u, ObjectGuid const& guid);
    GameObject* GetGameObject(WorldObject const& u, ObjectGuid const& guid);
    Transport* GetTransport(WorldObject const& u, ObjectGuid const& guid);
    DynamicObject* GetDynamicObject(WorldObject const& u, ObjectGuid const& guid);
    Unit* GetUnit(WorldObject const&, ObjectGuid const& guid);
    Creature* GetCreature(WorldObject const& u, ObjectGuid const& guid);
    Pet* GetPet(WorldObject const&, ObjectGuid const& guid);
    Player* GetPlayer(Map const*, ObjectGuid const& guid);
    Player* GetPlayer(WorldObject const&, ObjectGuid const& guid);
    Creature* GetCreatureOrPetOrVehicle(WorldObject const&, ObjectGuid const&);

    // these functions return objects if found in whole world
    // ACCESS LIKE THAT IS NOT THREAD SAFE
    Player* FindPlayer(ObjectGuid const&);
    Player* FindPlayerByName(std::string const& name);

    // this returns Player even if he is not in world, for example teleporting
    Player* FindConnectedPlayer(ObjectGuid const&);
    Player* FindConnectedPlayerByName(std::string const& name);

    // when using this, you must use the hashmapholder's lock
    HashMapHolder<Player>::MapType const& GetPlayers();

    template<class T>
    void AddObject(T* object)
    {
        HashMapHolder<T>::Insert(object);
    }

    template<class T>
    void RemoveObject(T* object)
    {
        HashMapHolder<T>::Remove(object);
    }

    void SaveAllPlayers();
};

#endif
