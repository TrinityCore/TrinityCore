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

#ifndef TRINITY_OBJECTACCESSOR_H
#define TRINITY_OBJECTACCESSOR_H

#include "ObjectGuid.h"
#include <shared_mutex>
#include <unordered_map>

class Corpse;
class Creature;
class DynamicObject;
class GameObject;
class Map;
class Object;
class Pet;
class Player;
class Transport;
class Unit;
class WorldObject;

template <class T>
class TC_GAME_API HashMapHolder
{
    //Non instanceable only static
    HashMapHolder() { }

public:

    typedef std::unordered_map<ObjectGuid, T*> MapType;

    static void Insert(T* o);

    static void Remove(T* o);

    static T* Find(ObjectGuid guid);

    static MapType& GetContainer();

    static std::shared_mutex* GetLock();
};

namespace ObjectAccessor
{
    // these functions return objects only if in map of specified object
    TC_GAME_API WorldObject* GetWorldObject(WorldObject const&, ObjectGuid const&);
    TC_GAME_API Object* GetObjectByTypeMask(WorldObject const&, ObjectGuid const&, uint32 typemask);
    TC_GAME_API Corpse* GetCorpse(WorldObject const& u, ObjectGuid const& guid);
    TC_GAME_API GameObject* GetGameObject(WorldObject const& u, ObjectGuid const& guid);
    TC_GAME_API Transport* GetTransport(WorldObject const& u, ObjectGuid const& guid);
    TC_GAME_API DynamicObject* GetDynamicObject(WorldObject const& u, ObjectGuid const& guid);
    TC_GAME_API Unit* GetUnit(WorldObject const&, ObjectGuid const& guid);
    TC_GAME_API Creature* GetCreature(WorldObject const& u, ObjectGuid const& guid);
    TC_GAME_API Pet* GetPet(WorldObject const&, ObjectGuid const& guid);
    TC_GAME_API Player* GetPlayer(Map const*, ObjectGuid const& guid);
    TC_GAME_API Player* GetPlayer(WorldObject const&, ObjectGuid const& guid);
    TC_GAME_API Creature* GetCreatureOrPetOrVehicle(WorldObject const&, ObjectGuid const&);

    // these functions return objects if found in whole world
    // ACCESS LIKE THAT IS NOT THREAD SAFE
    TC_GAME_API Player* FindPlayer(ObjectGuid const&);
    TC_GAME_API Player* FindPlayerByName(std::string_view name);
    TC_GAME_API Player* FindPlayerByLowGUID(ObjectGuid::LowType lowguid);

    // this returns Player even if he is not in world, for example teleporting
    TC_GAME_API Player* FindConnectedPlayer(ObjectGuid const&);
    TC_GAME_API Player* FindConnectedPlayerByName(std::string_view name);

    // when using this, you must use the hashmapholder's lock
    TC_GAME_API HashMapHolder<Player>::MapType const& GetPlayers();

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

    template<>
    void AddObject(Player* player);

    template<>
    void RemoveObject(Player* player);

    TC_GAME_API void SaveAllPlayers();
};

#endif
