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

#ifndef TRINITY_MAP_H
#define TRINITY_MAP_H

#include "Platform/Define.h"
#include "Policies/ThreadingModel.h"
#include "zthread/Lockable.h"
#include "zthread/Mutex.h"
#include "zthread/FairReadWriteLock.h"
#include "Database/DBCStructure.h"
#include "GridDefines.h"
#include "Cell.h"
#include "Timer.h"
#include "SharedDefines.h"
#include "GameSystem/GridRefManager.h"
#include "MapRefManager.h"
#include "mersennetwister/MersenneTwister.h"

#include <bitset>
#include <list>

class Unit;
class WorldPacket;
class InstanceData;
class Group;
class InstanceSave;
class WorldObject;
class CreatureGroup;

namespace ZThread
{
    class Lockable;
    class ReadWriteLock;
}

typedef ZThread::FairReadWriteLock GridRWLock;

template<class MUTEX, class LOCK_TYPE>
struct RGuard
{
    RGuard(MUTEX &l) : i_lock(l.getReadLock()) {}
    Trinity::GeneralLock<LOCK_TYPE> i_lock;
};

template<class MUTEX, class LOCK_TYPE>
struct WGuard
{
    WGuard(MUTEX &l) : i_lock(l.getWriteLock()) {}
    Trinity::GeneralLock<LOCK_TYPE> i_lock;
};

typedef RGuard<GridRWLock, ZThread::Lockable> GridReadGuard;
typedef WGuard<GridRWLock, ZThread::Lockable> GridWriteGuard;
typedef Trinity::SingleThreaded<GridRWLock>::Lock NullGuard;

typedef struct
{
    uint16 area_flag[16][16];
    uint8 terrain_type[16][16];
    float liquid_level[128][128];
    float v9[16 * 8 + 1][16 * 8 + 1];
    float v8[16 * 8][16 * 8];
    //float Z[MAP_RESOLUTION][MAP_RESOLUTION];
}GridMap;

struct CreatureMover
{
    CreatureMover() : x(0), y(0), z(0), ang(0) {}
    CreatureMover(float _x, float _y, float _z, float _ang) : x(_x), y(_y), z(_z), ang(_ang) {}

    float x, y, z, ang;
};

// GCC have alternative #pragma pack(N) syntax and old gcc version not support pack(push,N), also any gcc version not support it at some platform
#if defined( __GNUC__ )
#pragma pack(1)
#else
#pragma pack(push,1)
#endif

struct InstanceTemplate
{
    uint32 map;
    uint32 parent;    
    uint32 maxPlayers;
    uint32 reset_delay;
    uint32 access_id;
    float startLocX;
    float startLocY;
    float startLocZ;
    float startLocO;
    uint32 script_id;
};

enum LevelRequirementVsMode
{
    LEVELREQUIREMENT_HEROIC = 70
};

#if defined( __GNUC__ )
#pragma pack()
#else
#pragma pack(pop)
#endif

typedef UNORDERED_MAP<Creature*, CreatureMover> CreatureMoveList;

#define MAX_HEIGHT            100000.0f                     // can be use for find ground height at surface
#define INVALID_HEIGHT       -100000.0f                     // for check, must be equal to VMAP_INVALID_HEIGHT, real value for unknown height is VMAP_INVALID_HEIGHT_VALUE
#define MIN_UNLOAD_DELAY      1                             // immediate unload

typedef std::map<uint32/*leaderDBGUID*/, CreatureGroup*>        CreatureGroupHolderType;

class TRINITY_DLL_SPEC Map : public GridRefManager<NGridType>, public Trinity::ObjectLevelLockable<Map, ZThread::Mutex>
{
    friend class MapReference;
    public:
        Map(uint32 id, time_t, uint32 InstanceId, uint8 SpawnMode);
        virtual ~Map();

        // currently unused for normal maps
        bool CanUnload(uint32 diff)
        {
            if(!m_unloadTimer) return false;
            if(m_unloadTimer <= diff) return true;
            m_unloadTimer -= diff;
            return false;
        }

        virtual bool Add(Player *);
        virtual void Remove(Player *, bool);
        template<class T> void Add(T *);
        template<class T> void Remove(T *, bool);

        virtual void Update(const uint32&);

        void MessageBroadcast(Player *, WorldPacket *, bool to_self, bool to_possessor);
        void MessageBroadcast(WorldObject *, WorldPacket *, bool to_possessor);
        void MessageDistBroadcast(Player *, WorldPacket *, float dist, bool to_self, bool to_possessor, bool own_team_only = false);
        void MessageDistBroadcast(WorldObject *, WorldPacket *, float dist, bool to_possessor);

        void PlayerRelocation(Player *, float x, float y, float z, float angl);
        void CreatureRelocation(Creature *creature, float x, float y, float, float);

        template<class LOCK_TYPE, class T, class CONTAINER> void Visit(const CellLock<LOCK_TYPE> &cell, TypeContainerVisitor<T, CONTAINER> &visitor);

        bool IsRemovalGrid(float x, float y) const
        {
            GridPair p = Trinity::ComputeGridPair(x, y);
            return( !getNGrid(p.x_coord, p.y_coord) || getNGrid(p.x_coord, p.y_coord)->GetGridState() == GRID_STATE_REMOVAL );
        }

        bool GetUnloadLock(const GridPair &p) const { return getNGrid(p.x_coord, p.y_coord)->getUnloadLock(); }
        void SetUnloadLock(const GridPair &p, bool on) { getNGrid(p.x_coord, p.y_coord)->setUnloadExplicitLock(on); }
        void LoadGrid(float x, float y);
        bool UnloadGrid(const uint32 &x, const uint32 &y, bool pForce);
        virtual void UnloadAll();

        void ResetGridExpiry(NGridType &grid, float factor = 1) const
        {
            grid.ResetTimeTracker((time_t)((float)i_gridExpiry*factor));
        }

        time_t GetGridExpiry(void) const { return i_gridExpiry; }
        uint32 GetId(void) const { return i_id; }

        static bool ExistMap(uint32 mapid, int x, int y);
        static bool ExistVMap(uint32 mapid, int x, int y);
        void LoadMapAndVMap(uint32 mapid, uint32 instanceid, int x, int y);

        static void InitStateMachine();
        static void DeleteStateMachine();

        // some calls like isInWater should not use vmaps due to processor power
        // can return INVALID_HEIGHT if under z+2 z coord not found height
        float GetHeight(float x, float y, float z, bool pCheckVMap=true) const;
        float GetVmapHeight(float x, float y, float z, bool useMaps) const;
        bool IsInWater(float x, float y, float z) const;    // does not use z pos. This is for future use

        uint16 GetAreaFlag(float x, float y ) const;
        uint8 GetTerrainType(float x, float y ) const;
        float GetWaterLevel(float x, float y ) const;
        bool IsUnderWater(float x, float y, float z) const;

        static uint32 GetAreaId(uint16 areaflag,uint32 map_id);
        static uint32 GetZoneId(uint16 areaflag,uint32 map_id);

        uint32 GetAreaId(float x, float y) const
        {
            return GetAreaId(GetAreaFlag(x,y),i_id);
        }

        uint32 GetZoneId(float x, float y) const
        {
            return GetZoneId(GetAreaFlag(x,y),i_id);
        }

        virtual void MoveAllCreaturesInMoveList();
        virtual void RemoveAllObjectsInRemoveList();

        bool CreatureRespawnRelocation(Creature *c);        // used only in MoveAllCreaturesInMoveList and ObjectGridUnloader

        // assert print helper
        bool CheckGridIntegrity(Creature* c, bool moved) const;

        uint32 GetInstanceId() { return i_InstanceId; }
        uint8 GetSpawnMode() { return (i_spawnMode); }
        virtual bool CanEnter(Player* /*player*/) { return true; }
        const char* GetMapName() const;

        bool Instanceable() const { return i_mapEntry && i_mapEntry->Instanceable(); }
        // NOTE: this duplicate of Instanceable(), but Instanceable() can be changed when BG also will be instanceable
        bool IsDungeon() const { return i_mapEntry && i_mapEntry->IsDungeon(); }
        bool IsRaid() const { return i_mapEntry && i_mapEntry->IsRaid(); }
        bool IsHeroic() const { return i_spawnMode == DIFFICULTY_HEROIC; }
        bool IsBattleGround() const { return i_mapEntry && i_mapEntry->IsBattleGround(); }
        bool IsBattleArena() const { return i_mapEntry && i_mapEntry->IsBattleArena(); }
        bool IsBattleGroundOrArena() const { return i_mapEntry && i_mapEntry->IsBattleGroundOrArena(); }

        void AddObjectToRemoveList(WorldObject *obj);
        void AddObjectToSwitchList(WorldObject *obj, bool on);
        void DoDelayedMovesAndRemoves();

        virtual bool RemoveBones(uint64 guid, float x, float y);

        void UpdateObjectVisibility(WorldObject* obj, Cell cell, CellPair cellpair);

        void resetMarkedCells() { marked_cells.reset(); }
        bool isCellMarked(uint32 pCellId) { return marked_cells.test(pCellId); }
        void markCell(uint32 pCellId) { marked_cells.set(pCellId); }
        Creature* GetCreatureInMap(uint64 guid);
        GameObject* GetGameObjectInMap(uint64 guid);

        bool HavePlayers() const { return !m_mapRefManager.isEmpty(); }
        uint32 GetPlayersCountExceptGMs() const;
        bool ActiveObjectsNearGrid(uint32 x, uint32 y) const;

        void AddUnitToNotify(Unit* unit);
        void RelocationNotify();

        void SendToPlayers(WorldPacket const* data) const;

        typedef MapRefManager PlayerList;
        PlayerList const& GetPlayers() const { return m_mapRefManager; }

        // must called with AddToWorld
        template<class T>
        void AddToActive(T* obj) { AddToActiveHelper(obj); }

        void AddToActive(Creature* obj);

        // must called with RemoveFromWorld
        template<class T>
        void RemoveFromActive(T* obj) { RemoveFromActiveHelper(obj); }

        void RemoveFromActive(Creature* obj);

        template<class T> void SwitchGridContainers(T* obj, bool active);
        template<class NOTIFIER> void VisitAll(const float &x, const float &y, float radius, NOTIFIER &notifier);
        template<class NOTIFIER> void VisitWorld(const float &x, const float &y, float radius, NOTIFIER &notifier);
        template<class NOTIFIER> void VisitGrid(const float &x, const float &y, float radius, NOTIFIER &notifier);
        CreatureGroupHolderType CreatureGroupHolder;
        MTRand mtRand;

        int32 irand(int32 min, int32 max)
        {
          return int32 (mtRand.randInt(max - min)) + min;
        }

        uint32 urand(uint32 min, uint32 max)
        {
          return mtRand.randInt(max - min) + min;
        }

        int32 rand32()
        {
          return mtRand.randInt();
        }

        double rand_norm(void)
        {
          return mtRand.randExc();
        }

        double rand_chance(void)
        {
          return mtRand.randExc(100.0);
        }

    private:
        void LoadVMap(int pX, int pY);
        void LoadMap(uint32 mapid, uint32 instanceid, int x,int y);

        void SetTimer(uint32 t) { i_gridExpiry = t < MIN_GRID_DELAY ? MIN_GRID_DELAY : t; }
        //uint64 CalculateGridMask(const uint32 &y) const;

        void SendInitSelf( Player * player );

        void SendInitTransports( Player * player );
        void SendRemoveTransports( Player * player );

        bool CreatureCellRelocation(Creature *creature, Cell new_cell);

        void AddCreatureToMoveList(Creature *c, float x, float y, float z, float ang);
        CreatureMoveList i_creaturesToMove;

        bool loaded(const GridPair &) const;
        void EnsureGridLoaded(const Cell&, Player* player = NULL);
        void  EnsureGridCreated(const GridPair &);

        void buildNGridLinkage(NGridType* pNGridType) { pNGridType->link(this); }

        template<class T> void AddType(T *obj);
        template<class T> void RemoveType(T *obj, bool);

        NGridType* getNGrid(uint32 x, uint32 y) const
        {
            return i_grids[x][y];
        }

        bool isGridObjectDataLoaded(uint32 x, uint32 y) const { return getNGrid(x,y)->isGridObjectDataLoaded(); }
        void setGridObjectDataLoaded(bool pLoaded, uint32 x, uint32 y) { getNGrid(x,y)->setGridObjectDataLoaded(pLoaded); }

        void setNGrid(NGridType* grid, uint32 x, uint32 y);

        void UpdateActiveCells(const float &x, const float &y, const uint32 &t_diff);
    protected:
        void SetUnloadReferenceLock(const GridPair &p, bool on) { getNGrid(p.x_coord, p.y_coord)->setUnloadReferenceLock(on); }

        typedef Trinity::ObjectLevelLockable<Map, ZThread::Mutex>::Lock Guard;

        MapEntry const* i_mapEntry;
        uint8 i_spawnMode;
        uint32 i_id;
        uint32 i_InstanceId;
        uint32 m_unloadTimer;

        MapRefManager m_mapRefManager;
        MapRefManager::iterator m_mapRefIter;

        typedef std::set<WorldObject*> ActiveNonPlayers;
        ActiveNonPlayers m_activeNonPlayers;
        ActiveNonPlayers::iterator m_activeNonPlayersIter;


    private:
        typedef GridReadGuard ReadGuard;
        typedef GridWriteGuard WriteGuard;

        NGridType* i_grids[MAX_NUMBER_OF_GRIDS][MAX_NUMBER_OF_GRIDS];
        GridMap *GridMaps[MAX_NUMBER_OF_GRIDS][MAX_NUMBER_OF_GRIDS];
        std::bitset<TOTAL_NUMBER_OF_CELLS_PER_MAP*TOTAL_NUMBER_OF_CELLS_PER_MAP> marked_cells;

        time_t i_gridExpiry;

        bool i_lock;
        std::vector<uint64> i_unitsToNotifyBacklog;
        std::vector<Unit*> i_unitsToNotify;
        std::set<WorldObject *> i_objectsToRemove;
        std::map<WorldObject*, bool> i_objectsToSwitch;

        // Type specific code for add/remove to/from grid
        template<class T>
            void AddToGrid(T*, NGridType *, Cell const&);

        template<class T>
            void AddNotifier(T*);

        template<class T>
            void RemoveFromGrid(T*, NGridType *, Cell const&);

        template<class T>
            void DeleteFromWorld(T*);

        template<class T>
        void AddToActiveHelper(T* obj)
        {
            m_activeNonPlayers.insert(obj);
        }

        template<class T>
        void RemoveFromActiveHelper(T* obj)
        {
            // Map::Update for active object in proccess
            if(m_activeNonPlayersIter != m_activeNonPlayers.end())
            {
                ActiveNonPlayers::iterator itr = m_activeNonPlayers.find(obj);
                if(itr == m_activeNonPlayers.end())
                    return;
                if(itr==m_activeNonPlayersIter)
                    ++m_activeNonPlayersIter;
                m_activeNonPlayers.erase(itr);
            }
            else
                m_activeNonPlayers.erase(obj);
        }
};

enum InstanceResetMethod
{
    INSTANCE_RESET_ALL,
    INSTANCE_RESET_CHANGE_DIFFICULTY,
    INSTANCE_RESET_GLOBAL,
    INSTANCE_RESET_GROUP_DISBAND,
    INSTANCE_RESET_GROUP_JOIN,
    INSTANCE_RESET_RESPAWN_DELAY
};

class TRINITY_DLL_SPEC InstanceMap : public Map
{
    public:
        InstanceMap(uint32 id, time_t, uint32 InstanceId, uint8 SpawnMode);
        ~InstanceMap();
        bool Add(Player *);
        void Remove(Player *, bool);
        void Update(const uint32&);
        void CreateInstanceData(bool load);
        bool Reset(uint8 method);
        uint32 GetScriptId() { return i_script_id; }
        InstanceData* GetInstanceData() { return i_data; }
        void PermBindAllPlayers(Player *player);
        time_t GetResetTime();
        void UnloadAll();
        bool CanEnter(Player* player);
        void SendResetWarnings(uint32 timeLeft) const;
        void SetResetSchedule(bool on);
    private:
        bool m_resetAfterUnload;
        bool m_unloadWhenEmpty;
        InstanceData* i_data;
        uint32 i_script_id;
};

class TRINITY_DLL_SPEC BattleGroundMap : public Map
{
    public:
        BattleGroundMap(uint32 id, time_t, uint32 InstanceId);
        ~BattleGroundMap();

        bool Add(Player *);
        void Remove(Player *, bool);
        bool CanEnter(Player* player);
        void SetUnload();
        void UnloadAll();
};

/*inline
uint64
Map::CalculateGridMask(const uint32 &y) const
{
    uint64 mask = 1;
    mask <<= y;
    return mask;
}
*/

template<class LOCK_TYPE, class T, class CONTAINER>
inline void
Map::Visit(const CellLock<LOCK_TYPE> &cell, TypeContainerVisitor<T, CONTAINER> &visitor)
{
    const uint32 x = cell->GridX();
    const uint32 y = cell->GridY();
    const uint32 cell_x = cell->CellX();
    const uint32 cell_y = cell->CellY();

    if( !cell->NoCreate() || loaded(GridPair(x,y)) )
    {
        EnsureGridLoaded(cell);
        //LOCK_TYPE guard(i_info[x][y]->i_lock);
        getNGrid(x, y)->Visit(cell_x, cell_y, visitor);
    }
}

template<class NOTIFIER>
inline void
Map::VisitAll(const float &x, const float &y, float radius, NOTIFIER &notifier)
{
    float x_off, y_off;
    CellPair p(Trinity::ComputeCellPair(x, y, x_off, y_off));
    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();
    CellLock<GridReadGuard> cell_lock(cell, p);

    TypeContainerVisitor<NOTIFIER, WorldTypeMapContainer> world_object_notifier(notifier);
    cell_lock->Visit(cell_lock, world_object_notifier, *this, radius, x_off, y_off);
    TypeContainerVisitor<NOTIFIER, GridTypeMapContainer >  grid_object_notifier(notifier);
    cell_lock->Visit(cell_lock, grid_object_notifier, *this, radius, x_off, y_off);
}

template<class NOTIFIER>
inline void
Map::VisitWorld(const float &x, const float &y, float radius, NOTIFIER &notifier)
{
    float x_off, y_off;
    CellPair p(Trinity::ComputeCellPair(x, y, x_off, y_off));
    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();
    CellLock<GridReadGuard> cell_lock(cell, p);

    TypeContainerVisitor<NOTIFIER, WorldTypeMapContainer> world_object_notifier(notifier);
    cell_lock->Visit(cell_lock, world_object_notifier, *this, radius, x_off, y_off);
}

template<class NOTIFIER>
inline void
Map::VisitGrid(const float &x, const float &y, float radius, NOTIFIER &notifier)
{
    float x_off, y_off;
    CellPair p(Trinity::ComputeCellPair(x, y, x_off, y_off));
    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();
    CellLock<GridReadGuard> cell_lock(cell, p);

    TypeContainerVisitor<NOTIFIER, GridTypeMapContainer >  grid_object_notifier(notifier);
    cell_lock->Visit(cell_lock, grid_object_notifier, *this, radius, x_off, y_off);
}
#endif

