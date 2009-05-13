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

#ifndef TRINITY_OBJECTACCESSOR_H
#define TRINITY_OBJECTACCESSOR_H

#include "Platform/Define.h"
#include "Policies/Singleton.h"
#include <ace/Thread_Mutex.h>
#include "Utilities/UnorderedMap.h"
#include "Policies/ThreadingModel.h"

#include "ByteBuffer.h"
#include "UpdateData.h"

#include "GridDefines.h"
#include "Object.h"
#include "Player.h"

#include <set>

class Creature;
class Corpse;
class Unit;
class GameObject;
class DynamicObject;
class Vehicle;
class WorldObject;
class Map;

template <class T>
class HashMapHolder
{
    public:

        typedef UNORDERED_MAP< uint64, T* >   MapType;
        typedef ACE_Thread_Mutex LockType;
        typedef MaNGOS::GeneralLock<LockType > Guard;

        static void Insert(T* o) { m_objectMap[o->GetGUID()] = o; }

        static void Remove(T* o)
        {
            Guard guard(i_lock);
            m_objectMap.erase(o->GetGUID());
        }

        static T* Find(uint64 guid)
        {
            typename MapType::iterator itr = m_objectMap.find(guid);
            return (itr != m_objectMap.end()) ? itr->second : NULL;
        }

        static MapType& GetContainer() { return m_objectMap; }

        static LockType* GetLock() { return &i_lock; }
    private:

        //Non instanceable only static
        HashMapHolder() {}

        static LockType i_lock;
        static MapType  m_objectMap;
};

class MANGOS_DLL_DECL ObjectAccessor : public MaNGOS::Singleton<ObjectAccessor, MaNGOS::ClassLevelLockable<ObjectAccessor, ACE_Thread_Mutex> >
{

    friend class Trinity::OperatorNew<ObjectAccessor>;
    ObjectAccessor();
    ~ObjectAccessor();
    ObjectAccessor(const ObjectAccessor &);
    ObjectAccessor& operator=(const ObjectAccessor &);

    public:
        typedef UNORDERED_MAP<uint64, Corpse* >      Player2CorpsesMapType;
        typedef UNORDERED_MAP<Player*, UpdateData>::value_type UpdateDataValueType;

        template<class T> static T* GetObjectInWorld(uint64 guid, T* /*fake*/)
        {
            return HashMapHolder<T>::Find(guid);
        }

        static Unit* GetObjectInWorld(uint64 guid, Unit* /*fake*/)
        {
            if(!guid)
                return NULL;

            if (IS_PLAYER_GUID(guid))
                return (Unit*)HashMapHolder<Player>::Find(guid);

            if (Unit* u = (Unit*)HashMapHolder<Pet>::Find(guid))
                return u;

            return (Unit*)HashMapHolder<Creature>::Find(guid);
        }

        template<class T> static T* GetObjectInWorld(uint32 mapid, float x, float y, uint64 guid, T* /*fake*/)
        {
            T* obj = HashMapHolder<T>::Find(guid);
            if(!obj || obj->GetMapId() != mapid) return NULL;

            CellPair p = Trinity::ComputeCellPair(x,y);
            if(p.x_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP || p.y_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP )
            {
                sLog.outError("ObjectAccessor::GetObjectInWorld: invalid coordinates supplied X:%f Y:%f grid cell [%u:%u]", x, y, p.x_coord, p.y_coord);
                return NULL;
            }

            CellPair q = Trinity::ComputeCellPair(obj->GetPositionX(),obj->GetPositionY());
            if(q.x_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP || q.y_coord >= TOTAL_NUMBER_OF_CELLS_PER_MAP )
            {
                sLog.outError("ObjectAccessor::GetObjecInWorld: object "I64FMTD" has invalid coordinates X:%f Y:%f grid cell [%u:%u]", obj->GetGUID(), obj->GetPositionX(), obj->GetPositionY(), q.x_coord, q.y_coord);
                return NULL;
            }

            int32 dx = int32(p.x_coord) - int32(q.x_coord);
            int32 dy = int32(p.y_coord) - int32(q.y_coord);

            if (dx > -2 && dx < 2 && dy > -2 && dy < 2) return obj;
            else return NULL;
        }

        static Object*   GetObjectByTypeMask(WorldObject const &, uint64, uint32 typemask);
        static Creature* GetCreatureOrPetOrVehicle(WorldObject const &, uint64);
        static Unit* GetUnit(WorldObject const &, uint64);
        static Pet* GetPet(Unit const &, uint64 guid) { return GetPet(guid); }
        static Player* GetPlayer(Unit const &, uint64 guid) { return FindPlayer(guid); }
        static Corpse* GetCorpse(WorldObject const &u, uint64 guid);
        static Pet* GetPet(uint64 guid);
        static Vehicle* GetVehicle(uint64 guid);
        static Player* FindPlayer(uint64);

        Player* FindPlayerByName(const char *name) ;

        HashMapHolder<Player>::MapType& GetPlayers()
        {
            return HashMapHolder<Player>::GetContainer();
        }

        HashMapHolder<Creature>::MapType& GetCreatures()
        {
            return HashMapHolder<Creature>::GetContainer();
        }

        HashMapHolder<GameObject>::MapType& GetGameObjects()
        {
            return HashMapHolder<GameObject>::GetContainer();
        }

        template<class T> void AddObject(T *object)
        {
            HashMapHolder<T>::Insert(object);
        }

        template<class T> void RemoveObject(T *object)
        {
            HashMapHolder<T>::Remove(object);
        }

        void RemoveObject(Player *pl)
        {
            HashMapHolder<Player>::Remove(pl);

            Guard guard(i_updateGuard);
            i_objects.erase((Object *)pl);
        }

        void SaveAllPlayers();

        void AddUpdateObject(Object *obj)
        {
            Guard guard(i_updateGuard);
            i_objects.insert(obj);
        }

        void RemoveUpdateObject(Object *obj)
        {
            Guard guard(i_updateGuard);
            i_objects.erase( obj );
        }

        void Update(uint32 diff);
        void UpdatePlayers(uint32 diff);

        Corpse* GetCorpseForPlayerGUID(uint64 guid);
        void RemoveCorpse(Corpse *corpse);
        void AddCorpse(Corpse* corpse);
        void AddCorpsesToGrid(GridPair const& gridpair,GridType& grid,Map* map);
        Corpse* ConvertCorpseForPlayer(uint64 player_guid, bool insignia = false);

        static void UpdateObject(Object* obj, Player* exceptPlayer);
        static void _buildUpdateObject(Object* obj, UpdateDataMapType &);

        static void UpdateObjectVisibility(WorldObject* obj);
        //static void UpdateVisibilityForPlayer(Player* player);
    private:
        struct WorldObjectChangeAccumulator
        {
            UpdateDataMapType &i_updateDatas;
            WorldObject &i_object;
            std::set<uint64> plr_list;
            WorldObjectChangeAccumulator(WorldObject &obj, UpdateDataMapType &d) : i_updateDatas(d), i_object(obj) {}
            void Visit(PlayerMapType &);
            void Visit(CreatureMapType &);
            void Visit(DynamicObjectMapType &);
            void BuildPacket(Player* plr);
            template<class SKIP> void Visit(GridRefManager<SKIP> &) {}
        };

        friend struct WorldObjectChangeAccumulator;
        Player2CorpsesMapType   i_player2corpse;

        typedef ACE_Thread_Mutex LockType;
        typedef MaNGOS::GeneralLock<LockType > Guard;

        static void _buildChangeObjectForPlayer(WorldObject *, UpdateDataMapType &);
        static void _buildPacket(Player *, Object *, UpdateDataMapType &);
        void _update(void);
        std::set<Object *> i_objects;
        LockType i_playerGuard;
        LockType i_updateGuard;
        LockType i_corpseGuard;
        LockType i_petGuard;
};
#endif

