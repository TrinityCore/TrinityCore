/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITY_MAP_H
#define TRINITY_MAP_H

#include "Define.h"

#include "DBCStructure.h"
#include "GridDefines.h"
#include "Cell.h"
#include "Timer.h"
#include "SharedDefines.h"
#include "GridRefManager.h"
#include "MapRefManager.h"
#include "DynamicTree.h"
#include "GameObjectModel.h"
#include "ObjectGuid.h"

#include <bitset>
#include <list>
#include <memory>

class Unit;
class WorldPacket;
class InstanceScript;
class Group;
class InstanceSave;
class Object;
class WorldObject;
class TempSummon;
class Player;
class CreatureGroup;
struct ScriptInfo;
struct ScriptAction;
struct Position;
class Battleground;
class MapInstanced;
class BattlegroundMap;
class InstanceMap;
class Transport;
namespace Trinity { struct ObjectUpdater; }

struct ScriptAction
{
    ObjectGuid sourceGUID;
    ObjectGuid targetGUID;
    ObjectGuid ownerGUID;                                   ///> owner of source if source is item
    ScriptInfo const* script;                               ///> pointer to static script data
};

/// Represents a map magic value of 4 bytes (used in versions)
union u_map_magic
{
    char asChar[4]; ///> Non-null terminated string
    uint32 asUInt;  ///> uint32 representation
};

// ******************************************
// Map file format defines
// ******************************************
struct map_fileheader
{
    u_map_magic mapMagic;
    u_map_magic versionMagic;
    u_map_magic buildMagic;
    uint32 areaMapOffset;
    uint32 areaMapSize;
    uint32 heightMapOffset;
    uint32 heightMapSize;
    uint32 liquidMapOffset;
    uint32 liquidMapSize;
    uint32 holesOffset;
    uint32 holesSize;
};

#define MAP_AREA_NO_AREA      0x0001

struct map_areaHeader
{
    uint32 fourcc;
    uint16 flags;
    uint16 gridArea;
};

#define MAP_HEIGHT_NO_HEIGHT            0x0001
#define MAP_HEIGHT_AS_INT16             0x0002
#define MAP_HEIGHT_AS_INT8              0x0004

struct map_heightHeader
{
    uint32 fourcc;
    uint32 flags;
    float  gridHeight;
    float  gridMaxHeight;
};

#define MAP_LIQUID_NO_TYPE    0x0001
#define MAP_LIQUID_NO_HEIGHT  0x0002

struct map_liquidHeader
{
    uint32 fourcc;
    uint16 flags;
    uint16 liquidType;
    uint8  offsetX;
    uint8  offsetY;
    uint8  width;
    uint8  height;
    float  liquidLevel;
};

enum ZLiquidStatus
{
    LIQUID_MAP_NO_WATER     = 0x00000000,
    LIQUID_MAP_ABOVE_WATER  = 0x00000001,
    LIQUID_MAP_WATER_WALK   = 0x00000002,
    LIQUID_MAP_IN_WATER     = 0x00000004,
    LIQUID_MAP_UNDER_WATER  = 0x00000008
};

#define MAP_LIQUID_TYPE_NO_WATER    0x00
#define MAP_LIQUID_TYPE_WATER       0x01
#define MAP_LIQUID_TYPE_OCEAN       0x02
#define MAP_LIQUID_TYPE_MAGMA       0x04
#define MAP_LIQUID_TYPE_SLIME       0x08

#define MAP_ALL_LIQUIDS   (MAP_LIQUID_TYPE_WATER | MAP_LIQUID_TYPE_OCEAN | MAP_LIQUID_TYPE_MAGMA | MAP_LIQUID_TYPE_SLIME)

#define MAP_LIQUID_TYPE_DARK_WATER  0x10
#define MAP_LIQUID_TYPE_WMO_WATER   0x20

struct LiquidData
{
    uint32 type_flags;
    uint32 entry;
    float  level;
    float  depth_level;
};

class GridMap
{
    uint32  _flags;
    union{
        float* m_V9;
        uint16* m_uint16_V9;
        uint8* m_uint8_V9;
    };
    union{
        float* m_V8;
        uint16* m_uint16_V8;
        uint8* m_uint8_V8;
    };
    // Height level data
    float _gridHeight;
    float _gridIntHeightMultiplier;

    // Area data
    uint16* _areaMap;

    // Liquid data
    float _liquidLevel;
    uint16* _liquidEntry;
    uint8* _liquidFlags;
    float* _liquidMap;
    uint16 _gridArea;
    uint16 _liquidType;
    uint8 _liquidOffX;
    uint8 _liquidOffY;
    uint8 _liquidWidth;
    uint8 _liquidHeight;


    bool loadAreaData(FILE* in, uint32 offset, uint32 size);
    bool loadHeightData(FILE* in, uint32 offset, uint32 size);
    bool loadLiquidData(FILE* in, uint32 offset, uint32 size);

    // Get height functions and pointers
    typedef float (GridMap::*GetHeightPtr) (float x, float y) const;
    GetHeightPtr _gridGetHeight;
    float getHeightFromFloat(float x, float y) const;
    float getHeightFromUint16(float x, float y) const;
    float getHeightFromUint8(float x, float y) const;
    float getHeightFromFlat(float x, float y) const;

public:
    GridMap();
    ~GridMap();
    bool loadData(const char* filename);
    void unloadData();

    uint16 getArea(float x, float y) const;
    inline float getHeight(float x, float y) const {return (this->*_gridGetHeight)(x, y);}
    float getLiquidLevel(float x, float y) const;
    uint8 getTerrainType(float x, float y) const;
    ZLiquidStatus getLiquidStatus(float x, float y, float z, uint8 ReqLiquidType, LiquidData* data = 0);
};

#pragma pack(push, 1)

struct InstanceTemplate
{
    uint32 Parent;
    uint32 ScriptId;
    bool AllowMount;
};

enum LevelRequirementVsMode
{
    LEVELREQUIREMENT_HEROIC = 70
};

struct ZoneDynamicInfo
{
    ZoneDynamicInfo() : MusicId(0), WeatherId(0), WeatherGrade(0.0f),
        OverrideLightId(0), LightFadeInTime(0) { }

    uint32 MusicId;
    uint32 WeatherId;
    float WeatherGrade;
    uint32 OverrideLightId;
    uint32 LightFadeInTime;
};

#pragma pack(pop)

#define MAX_HEIGHT            100000.0f                     // can be use for find ground height at surface
#define INVALID_HEIGHT       -100000.0f                     // for check, must be equal to VMAP_INVALID_HEIGHT, real value for unknown height is VMAP_INVALID_HEIGHT_VALUE
#define MAX_FALL_DISTANCE     250000.0f                     // "unlimited fall" to find VMap ground if it is available, just larger than MAX_HEIGHT - INVALID_HEIGHT
#define DEFAULT_HEIGHT_SEARCH     50.0f                     // default search distance to find height at nearby locations
#define MIN_UNLOAD_DELAY      1                             // immediate unload

typedef std::map<uint32/*leaderDBGUID*/, CreatureGroup*>        CreatureGroupHolderType;

typedef std::unordered_map<uint32 /*zoneId*/, ZoneDynamicInfo> ZoneDynamicInfoMap;

class Map : public GridRefManager<NGridType>
{
    friend class MapReference;
    public:
        Map(uint32 id, time_t, uint32 InstanceId, uint8 SpawnMode, Map* _parent = NULL);
        virtual ~Map();

        MapEntry const* GetEntry() const { return i_mapEntry; }

        // currently unused for normal maps
        bool CanUnload(uint32 diff)
        {
            if (!m_unloadTimer)
                return false;

            if (m_unloadTimer <= diff)
                return true;

            m_unloadTimer -= diff;
            return false;
        }

        virtual bool AddPlayerToMap(Player*);
        virtual void RemovePlayerFromMap(Player*, bool);
        template<class T> bool AddToMap(T *);
        template<class T> void RemoveFromMap(T *, bool);

        void VisitNearbyCellsOf(WorldObject* obj, TypeContainerVisitor<Trinity::ObjectUpdater, GridTypeMapContainer> &gridVisitor, TypeContainerVisitor<Trinity::ObjectUpdater, WorldTypeMapContainer> &worldVisitor);
        virtual void Update(const uint32);

        float GetVisibilityRange() const { return m_VisibleDistance; }
        //function for setting up visibility distance for maps on per-type/per-Id basis
        virtual void InitVisibilityDistance();

        void PlayerRelocation(Player*, float x, float y, float z, float orientation);
        void CreatureRelocation(Creature* creature, float x, float y, float z, float ang, bool respawnRelocationOnFail = true);
        void GameObjectRelocation(GameObject* go, float x, float y, float z, float orientation, bool respawnRelocationOnFail = true);
        void DynamicObjectRelocation(DynamicObject* go, float x, float y, float z, float orientation);

        template<class T, class CONTAINER> void Visit(const Cell& cell, TypeContainerVisitor<T, CONTAINER> &visitor);

        bool IsRemovalGrid(float x, float y) const
        {
            GridCoord p = Trinity::ComputeGridCoord(x, y);
            return !getNGrid(p.x_coord, p.y_coord) || getNGrid(p.x_coord, p.y_coord)->GetGridState() == GRID_STATE_REMOVAL;
        }

        bool IsGridLoaded(float x, float y) const
        {
            return IsGridLoaded(Trinity::ComputeGridCoord(x, y));
        }

        bool GetUnloadLock(const GridCoord &p) const { return getNGrid(p.x_coord, p.y_coord)->getUnloadLock(); }
        void SetUnloadLock(const GridCoord &p, bool on) { getNGrid(p.x_coord, p.y_coord)->setUnloadExplicitLock(on); }
        void LoadGrid(float x, float y);
        bool UnloadGrid(NGridType& ngrid, bool pForce);
        virtual void UnloadAll();

        void ResetGridExpiry(NGridType &grid, float factor = 1) const
        {
            grid.ResetTimeTracker(time_t(float(i_gridExpiry)*factor));
        }

        time_t GetGridExpiry(void) const { return i_gridExpiry; }
        uint32 GetId(void) const { return i_mapEntry->MapID; }

        static bool ExistMap(uint32 mapid, int gx, int gy);
        static bool ExistVMap(uint32 mapid, int gx, int gy);

        static void InitStateMachine();
        static void DeleteStateMachine();

        Map const* GetParent() const { return m_parentMap; }

        // some calls like isInWater should not use vmaps due to processor power
        // can return INVALID_HEIGHT if under z+2 z coord not found height
        float GetHeight(float x, float y, float z, bool checkVMap = true, float maxSearchDist = DEFAULT_HEIGHT_SEARCH) const;

        ZLiquidStatus getLiquidStatus(float x, float y, float z, uint8 ReqLiquidType, LiquidData* data = nullptr) const;

        uint32 GetAreaId(float x, float y, float z, bool *isOutdoors) const;
        bool GetAreaInfo(float x, float y, float z, uint32& mogpflags, int32& adtId, int32& rootId, int32& groupId) const;
        uint32 GetAreaId(float x, float y, float z) const;
        uint32 GetZoneId(float x, float y, float z) const;
        void GetZoneAndAreaId(uint32& zoneid, uint32& areaid, float x, float y, float z) const;

        bool IsOutdoors(float x, float y, float z) const;

        uint8 GetTerrainType(float x, float y) const;
        float GetWaterLevel(float x, float y) const;
        bool IsInWater(float x, float y, float z, LiquidData* data = nullptr) const;
        bool IsUnderWater(float x, float y, float z) const;

        void MoveAllCreaturesInMoveList();
        void MoveAllGameObjectsInMoveList();
        void MoveAllDynamicObjectsInMoveList();
        void RemoveAllObjectsInRemoveList();
        virtual void RemoveAllPlayers();

        // used only in MoveAllCreaturesInMoveList and ObjectGridUnloader
        bool CreatureRespawnRelocation(Creature* c, bool diffGridOnly);
        bool GameObjectRespawnRelocation(GameObject* go, bool diffGridOnly);

        // assert print helper
        bool CheckGridIntegrity(Creature* c, bool moved) const;

        uint32 GetInstanceId() const { return i_InstanceId; }
        uint8 GetSpawnMode() const { return (i_spawnMode); }

        enum EnterState
        {
            CAN_ENTER = 0,
            CANNOT_ENTER_ALREADY_IN_MAP = 1, // Player is already in the map
            CANNOT_ENTER_NO_ENTRY, // No map entry was found for the target map ID
            CANNOT_ENTER_UNINSTANCED_DUNGEON, // No instance template was found for dungeon map
            CANNOT_ENTER_DIFFICULTY_UNAVAILABLE, // Requested instance difficulty is not available for target map
            CANNOT_ENTER_NOT_IN_RAID, // Target instance is a raid instance and the player is not in a raid group
            CANNOT_ENTER_CORPSE_IN_DIFFERENT_INSTANCE, // Player is dead and their corpse is not in target instance
            CANNOT_ENTER_INSTANCE_BIND_MISMATCH, // Player's permanent instance save is not compatible with their group's current instance bind
            CANNOT_ENTER_TOO_MANY_INSTANCES, // Player has entered too many instances recently
            CANNOT_ENTER_MAX_PLAYERS, // Target map already has the maximum number of players allowed
            CANNOT_ENTER_ZONE_IN_COMBAT, // A boss encounter is currently in progress on the target map
            CANNOT_ENTER_UNSPECIFIED_REASON
        };
        virtual EnterState CannotEnter(Player* /*player*/) { return CAN_ENTER; }
        const char* GetMapName() const;

        // have meaning only for instanced map (that have set real difficulty)
        Difficulty GetDifficulty() const { return Difficulty(GetSpawnMode()); }
        bool IsRegularDifficulty() const { return GetDifficulty() == REGULAR_DIFFICULTY; }
        MapDifficulty const* GetMapDifficulty() const;

        bool Instanceable() const { return i_mapEntry && i_mapEntry->Instanceable(); }
        bool IsDungeon() const { return i_mapEntry && i_mapEntry->IsDungeon(); }
        bool IsNonRaidDungeon() const { return i_mapEntry && i_mapEntry->IsNonRaidDungeon(); }
        bool IsRaid() const { return i_mapEntry && i_mapEntry->IsRaid(); }
        bool IsRaidOrHeroicDungeon() const { return IsRaid() || i_spawnMode > DUNGEON_DIFFICULTY_NORMAL; }
        bool IsHeroic() const { return IsRaid() ? i_spawnMode >= RAID_DIFFICULTY_10MAN_HEROIC : i_spawnMode >= DUNGEON_DIFFICULTY_HEROIC; }
        bool Is25ManRaid() const { return IsRaid() && i_spawnMode & RAID_DIFFICULTY_MASK_25MAN; }   // since 25man difficulties are 1 and 3, we can check them like that
        bool IsBattleground() const { return i_mapEntry && i_mapEntry->IsBattleground(); }
        bool IsBattleArena() const { return i_mapEntry && i_mapEntry->IsBattleArena(); }
        bool IsBattlegroundOrArena() const { return i_mapEntry && i_mapEntry->IsBattlegroundOrArena(); }
        bool GetEntrancePos(int32 &mapid, float &x, float &y)
        {
            if (!i_mapEntry)
                return false;
            return i_mapEntry->GetEntrancePos(mapid, x, y);
        }

        void AddObjectToRemoveList(WorldObject* obj);
        void AddObjectToSwitchList(WorldObject* obj, bool on);
        virtual void DelayedUpdate(const uint32 diff);

        void UpdateObjectVisibility(WorldObject* obj, Cell cell, CellCoord cellpair);
        void UpdateObjectsVisibilityFor(Player* player, Cell cell, CellCoord cellpair);

        void resetMarkedCells() { marked_cells.reset(); }
        bool isCellMarked(uint32 pCellId) { return marked_cells.test(pCellId); }
        void markCell(uint32 pCellId) { marked_cells.set(pCellId); }

        bool HavePlayers() const { return !m_mapRefManager.isEmpty(); }
        uint32 GetPlayersCountExceptGMs() const;
        bool ActiveObjectsNearGrid(NGridType const& ngrid) const;

        void AddWorldObject(WorldObject* obj) { i_worldObjects.insert(obj); }
        void RemoveWorldObject(WorldObject* obj) { i_worldObjects.erase(obj); }

        void SendToPlayers(WorldPacket* data) const;

        typedef MapRefManager PlayerList;
        PlayerList const& GetPlayers() const { return m_mapRefManager; }

        //per-map script storage
        void ScriptsStart(std::map<uint32, std::multimap<uint32, ScriptInfo> > const& scripts, uint32 id, Object* source, Object* target);
        void ScriptCommandStart(ScriptInfo const& script, uint32 delay, Object* source, Object* target);

        // must called with AddToWorld
        template<class T>
        void AddToActive(T* obj);

        // must called with RemoveFromWorld
        template<class T>
        void RemoveFromActive(T* obj);

        template<class T> void SwitchGridContainers(T* obj, bool on);
        template<class NOTIFIER> void VisitAll(const float &x, const float &y, float radius, NOTIFIER &notifier);
        template<class NOTIFIER> void VisitFirstFound(const float &x, const float &y, float radius, NOTIFIER &notifier);
        template<class NOTIFIER> void VisitWorld(const float &x, const float &y, float radius, NOTIFIER &notifier);
        template<class NOTIFIER> void VisitGrid(const float &x, const float &y, float radius, NOTIFIER &notifier);
        CreatureGroupHolderType CreatureGroupHolder;

        void UpdateIteratorBack(Player* player);

        TempSummon* SummonCreature(uint32 entry, Position const& pos, SummonPropertiesEntry const* properties = NULL, uint32 duration = 0, Unit* summoner = NULL, uint32 spellId = 0, uint32 vehId = 0);
        void SummonCreatureGroup(uint8 group, std::list<TempSummon*>* list = NULL);
        AreaTrigger* GetAreaTrigger(ObjectGuid const& guid);
        Corpse* GetCorpse(ObjectGuid const& guid);
        Creature* GetCreature(ObjectGuid const& guid);
        DynamicObject* GetDynamicObject(ObjectGuid const& guid);
        GameObject* GetGameObject(ObjectGuid const& guid);
        Pet* GetPet(ObjectGuid const& guid);
        Transport* GetTransport(ObjectGuid const& guid);

        MapStoredObjectTypesContainer& GetObjectsStore() { return _objectsStore; }

        typedef std::unordered_multimap<ObjectGuid::LowType, Creature*> CreatureBySpawnIdContainer;
        CreatureBySpawnIdContainer& GetCreatureBySpawnIdStore() { return _creatureBySpawnIdStore; }

        typedef std::unordered_multimap<ObjectGuid::LowType, GameObject*> GameObjectBySpawnIdContainer;
        GameObjectBySpawnIdContainer& GetGameObjectBySpawnIdStore() { return _gameObjectBySpawnIdStore; }

        std::unordered_set<Corpse*> const* GetCorpsesInCell(uint32 cellId) const
        {
            auto itr = _corpsesByCell.find(cellId);
            if (itr != _corpsesByCell.end())
                return &itr->second;

            return nullptr;
        }

        Corpse* GetCorpseByPlayer(ObjectGuid const& ownerGuid) const
        {
            auto itr = _corpsesByPlayer.find(ownerGuid);
            if (itr != _corpsesByPlayer.end())
                return itr->second;

            return nullptr;
        }

        MapInstanced* ToMapInstanced() { if (Instanceable()) return reinterpret_cast<MapInstanced*>(this); return NULL; }
        MapInstanced const* ToMapInstanced() const { if (Instanceable()) return reinterpret_cast<MapInstanced const*>(this); return NULL; }

        InstanceMap* ToInstanceMap() { if (IsDungeon()) return reinterpret_cast<InstanceMap*>(this); else return NULL;  }
        InstanceMap const* ToInstanceMap() const { if (IsDungeon()) return reinterpret_cast<InstanceMap const*>(this); return NULL; }

        BattlegroundMap* ToBattlegroundMap() { if (IsBattlegroundOrArena()) return reinterpret_cast<BattlegroundMap*>(this); else return NULL;  }
        BattlegroundMap const* ToBattlegroundMap() const { if (IsBattlegroundOrArena()) return reinterpret_cast<BattlegroundMap const*>(this); return NULL; }

        float GetWaterOrGroundLevel(float x, float y, float z, float* ground = NULL, bool swim = false) const;
        float GetHeight(uint32 phasemask, float x, float y, float z, bool vmap = true, float maxSearchDist = DEFAULT_HEIGHT_SEARCH) const;
        bool isInLineOfSight(float x1, float y1, float z1, float x2, float y2, float z2, uint32 phasemask) const;
        void Balance() { _dynamicTree.balance(); }
        void RemoveGameObjectModel(const GameObjectModel& model) { _dynamicTree.remove(model); }
        void InsertGameObjectModel(const GameObjectModel& model) { _dynamicTree.insert(model); }
        bool ContainsGameObjectModel(const GameObjectModel& model) const { return _dynamicTree.contains(model);}
        bool getObjectHitPos(uint32 phasemask, float x1, float y1, float z1, float x2, float y2, float z2, float& rx, float &ry, float& rz, float modifyDist);

        virtual uint32 GetOwnerGuildId(uint32 /*team*/ = TEAM_OTHER) const { return 0; }
        /*
            RESPAWN TIMES
        */
        time_t GetLinkedRespawnTime(ObjectGuid guid) const;
        time_t GetCreatureRespawnTime(ObjectGuid::LowType dbGuid) const
        {
            std::unordered_map<ObjectGuid::LowType /*dbGUID*/, time_t>::const_iterator itr = _creatureRespawnTimes.find(dbGuid);
            if (itr != _creatureRespawnTimes.end())
                return itr->second;

            return time_t(0);
        }

        time_t GetGORespawnTime(ObjectGuid::LowType dbGuid) const
        {
            std::unordered_map<ObjectGuid::LowType /*dbGUID*/, time_t>::const_iterator itr = _goRespawnTimes.find(dbGuid);
            if (itr != _goRespawnTimes.end())
                return itr->second;

            return time_t(0);
        }

        void SaveCreatureRespawnTime(ObjectGuid::LowType dbGuid, time_t respawnTime);
        void RemoveCreatureRespawnTime(ObjectGuid::LowType dbGuid);
        void SaveGORespawnTime(ObjectGuid::LowType dbGuid, time_t respawnTime);
        void RemoveGORespawnTime(ObjectGuid::LowType dbGuid);
        void LoadRespawnTimes();
        void DeleteRespawnTimes();

        void LoadCorpseData();
        void DeleteCorpseData();
        void AddCorpse(Corpse* corpse);
        void RemoveCorpse(Corpse* corpse);
        Corpse* ConvertCorpseToBones(ObjectGuid const& ownerGuid, bool insignia = false);
        void RemoveOldCorpses();

        static void DeleteRespawnTimesInDB(uint16 mapId, uint32 instanceId);

        void SendInitTransports(Player* player);
        void SendRemoveTransports(Player* player);
        void SendUpdateTransportVisibility(Player* player, std::set<uint32> const& previousPhases);
        void SendZoneDynamicInfo(Player* player);

        void SetZoneMusic(uint32 zoneId, uint32 musicId);
        void SetZoneWeather(uint32 zoneId, uint32 weatherId, float weatherGrade);
        void SetZoneOverrideLight(uint32 zoneId, uint32 lightId, uint32 fadeInTime);

        void UpdateAreaDependentAuras();

        template<HighGuid high>
        inline ObjectGuid::LowType GenerateLowGuid()
        {
            static_assert(ObjectGuidTraits<high>::MapSpecific, "Only map specific guid can be generated in Map context");
            return GetGuidSequenceGenerator<high>().Generate();
        }

        template<HighGuid high>
        inline ObjectGuid::LowType GetMaxLowGuid()
        {
            static_assert(ObjectGuidTraits<high>::MapSpecific, "Only map specific guid can be retrieved in Map context");
            return GetGuidSequenceGenerator<high>().GetNextAfterMaxUsed();
        }

        void AddUpdateObject(Object* obj)
        {
            _updateObjects.insert(obj);
        }

        void RemoveUpdateObject(Object* obj)
        {
            _updateObjects.erase(obj);
        }

    private:

        void LoadMapAndVMap(int gx, int gy);
        void LoadVMap(int gx, int gy);
        void LoadMap(int gx, int gy, bool reload = false);
        void LoadMMap(int gx, int gy);
        GridMap* GetGrid(float x, float y);

        void SetTimer(uint32 t) { i_gridExpiry = t < MIN_GRID_DELAY ? MIN_GRID_DELAY : t; }

        void SendInitSelf(Player* player);

        bool CreatureCellRelocation(Creature* creature, Cell new_cell);
        bool GameObjectCellRelocation(GameObject* go, Cell new_cell);
        bool DynamicObjectCellRelocation(DynamicObject* go, Cell new_cell);

        template<class T> void InitializeObject(T* obj);
        void AddCreatureToMoveList(Creature* c, float x, float y, float z, float ang);
        void RemoveCreatureFromMoveList(Creature* c);
        void AddGameObjectToMoveList(GameObject* go, float x, float y, float z, float ang);
        void RemoveGameObjectFromMoveList(GameObject* go);
        void AddDynamicObjectToMoveList(DynamicObject* go, float x, float y, float z, float ang);
        void RemoveDynamicObjectFromMoveList(DynamicObject* go);

        bool _creatureToMoveLock;
        std::vector<Creature*> _creaturesToMove;

        bool _gameObjectsToMoveLock;
        std::vector<GameObject*> _gameObjectsToMove;

        bool _dynamicObjectsToMoveLock;
        std::vector<DynamicObject*> _dynamicObjectsToMove;

        bool IsGridLoaded(const GridCoord &) const;
        void EnsureGridCreated(const GridCoord &);
        void EnsureGridCreated_i(const GridCoord &);
        bool EnsureGridLoaded(Cell const&);
        void EnsureGridLoadedForActiveObject(Cell const&, WorldObject* object);

        void buildNGridLinkage(NGridType* pNGridType) { pNGridType->link(this); }

        NGridType* getNGrid(uint32 x, uint32 y) const
        {
            ASSERT(x < MAX_NUMBER_OF_GRIDS && y < MAX_NUMBER_OF_GRIDS);
            return i_grids[x][y];
        }

        bool isGridObjectDataLoaded(uint32 x, uint32 y) const { return getNGrid(x, y)->isGridObjectDataLoaded(); }
        void setGridObjectDataLoaded(bool pLoaded, uint32 x, uint32 y) { getNGrid(x, y)->setGridObjectDataLoaded(pLoaded); }

        void setNGrid(NGridType* grid, uint32 x, uint32 y);
        void ScriptsProcess();

        void UpdateActiveCells(const float &x, const float &y, const uint32 t_diff);

        void SendObjectUpdates();

    protected:
        void SetUnloadReferenceLock(const GridCoord &p, bool on) { getNGrid(p.x_coord, p.y_coord)->setUnloadReferenceLock(on); }

        std::mutex _mapLock;
        std::mutex _gridLock;

        MapEntry const* i_mapEntry;
        uint8 i_spawnMode;
        uint32 i_InstanceId;
        uint32 m_unloadTimer;
        float m_VisibleDistance;
        DynamicMapTree _dynamicTree;

        MapRefManager m_mapRefManager;
        MapRefManager::iterator m_mapRefIter;

        int32 m_VisibilityNotifyPeriod;

        typedef std::set<WorldObject*> ActiveNonPlayers;
        ActiveNonPlayers m_activeNonPlayers;
        ActiveNonPlayers::iterator m_activeNonPlayersIter;

        // Objects that must update even in inactive grids without activating them
        typedef std::set<Transport*> TransportsContainer;
        TransportsContainer _transports;
        TransportsContainer::iterator _transportsUpdateIter;

    private:
        Player* _GetScriptPlayerSourceOrTarget(Object* source, Object* target, const ScriptInfo* scriptInfo) const;
        Creature* _GetScriptCreatureSourceOrTarget(Object* source, Object* target, const ScriptInfo* scriptInfo, bool bReverse = false) const;
        Unit* _GetScriptUnit(Object* obj, bool isSource, const ScriptInfo* scriptInfo) const;
        Player* _GetScriptPlayer(Object* obj, bool isSource, const ScriptInfo* scriptInfo) const;
        Creature* _GetScriptCreature(Object* obj, bool isSource, const ScriptInfo* scriptInfo) const;
        WorldObject* _GetScriptWorldObject(Object* obj, bool isSource, const ScriptInfo* scriptInfo) const;
        void _ScriptProcessDoor(Object* source, Object* target, const ScriptInfo* scriptInfo) const;
        GameObject* _FindGameObject(WorldObject* pWorldObject, ObjectGuid::LowType guid) const;

        time_t i_gridExpiry;

        //used for fast base_map (e.g. MapInstanced class object) search for
        //InstanceMaps and BattlegroundMaps...
        Map* m_parentMap;

        NGridType* i_grids[MAX_NUMBER_OF_GRIDS][MAX_NUMBER_OF_GRIDS];
        GridMap* GridMaps[MAX_NUMBER_OF_GRIDS][MAX_NUMBER_OF_GRIDS];
        std::bitset<TOTAL_NUMBER_OF_CELLS_PER_MAP*TOTAL_NUMBER_OF_CELLS_PER_MAP> marked_cells;

        //these functions used to process player/mob aggro reactions and
        //visibility calculations. Highly optimized for massive calculations
        void ProcessRelocationNotifies(const uint32 diff);

        bool i_scriptLock;
        std::set<WorldObject*> i_objectsToRemove;
        std::map<WorldObject*, bool> i_objectsToSwitch;
        std::set<WorldObject*> i_worldObjects;

        typedef std::multimap<time_t, ScriptAction> ScriptScheduleMap;
        ScriptScheduleMap m_scriptSchedule;

        // Type specific code for add/remove to/from grid
        template<class T>
        void AddToGrid(T* object, Cell const& cell);

        template<class T>
        void DeleteFromWorld(T*);

        void AddToActiveHelper(WorldObject* obj)
        {
            m_activeNonPlayers.insert(obj);
        }

        void RemoveFromActiveHelper(WorldObject* obj)
        {
            // Map::Update for active object in proccess
            if (m_activeNonPlayersIter != m_activeNonPlayers.end())
            {
                ActiveNonPlayers::iterator itr = m_activeNonPlayers.find(obj);
                if (itr == m_activeNonPlayers.end())
                    return;
                if (itr == m_activeNonPlayersIter)
                    ++m_activeNonPlayersIter;
                m_activeNonPlayers.erase(itr);
            }
            else
                m_activeNonPlayers.erase(obj);
        }

        std::unordered_map<ObjectGuid::LowType /*dbGUID*/, time_t> _creatureRespawnTimes;
        std::unordered_map<ObjectGuid::LowType /*dbGUID*/, time_t> _goRespawnTimes;

        ZoneDynamicInfoMap _zoneDynamicInfo;
        uint32 _defaultLight;

        template<HighGuid high>
        inline ObjectGuidGeneratorBase& GetGuidSequenceGenerator()
        {
            auto itr = _guidGenerators.find(high);
            if (itr == _guidGenerators.end())
                itr = _guidGenerators.insert(std::make_pair(high, std::unique_ptr<ObjectGuidGenerator<high>>(new ObjectGuidGenerator<high>()))).first;

            return *itr->second;
        }

        std::map<HighGuid, std::unique_ptr<ObjectGuidGeneratorBase>> _guidGenerators;
        MapStoredObjectTypesContainer _objectsStore;
        CreatureBySpawnIdContainer _creatureBySpawnIdStore;
        GameObjectBySpawnIdContainer _gameObjectBySpawnIdStore;
        std::unordered_map<uint32/*cellId*/, std::unordered_set<Corpse*>> _corpsesByCell;
        std::unordered_map<ObjectGuid, Corpse*> _corpsesByPlayer;
        std::unordered_set<Corpse*> _corpseBones;

        std::unordered_set<Object*> _updateObjects;
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

class InstanceMap : public Map
{
    public:
        InstanceMap(uint32 id, time_t, uint32 InstanceId, uint8 SpawnMode, Map* _parent);
        ~InstanceMap();
        bool AddPlayerToMap(Player*) override;
        void RemovePlayerFromMap(Player*, bool) override;
        void Update(const uint32) override;
        void CreateInstanceData(bool load);
        bool Reset(uint8 method);
        uint32 GetScriptId() const { return i_script_id; }
        InstanceScript* GetInstanceScript() { return i_data; }
        void PermBindAllPlayers(Player* source);
        void UnloadAll() override;
        EnterState CannotEnter(Player* player) override;
        void SendResetWarnings(uint32 timeLeft) const;
        void SetResetSchedule(bool on);

        /* this checks if any players have a permanent bind (included reactivatable expired binds) to the instance ID
        it needs a DB query, so use sparingly */
        bool HasPermBoundPlayers() const;
        uint32 GetMaxPlayers() const;
        uint32 GetMaxResetDelay() const;

        virtual void InitVisibilityDistance() override;
    private:
        bool m_resetAfterUnload;
        bool m_unloadWhenEmpty;
        InstanceScript* i_data;
        uint32 i_script_id;
};

class BattlegroundMap : public Map
{
    public:
        BattlegroundMap(uint32 id, time_t, uint32 InstanceId, Map* _parent, uint8 spawnMode);
        ~BattlegroundMap();

        bool AddPlayerToMap(Player*) override;
        void RemovePlayerFromMap(Player*, bool) override;
        EnterState CannotEnter(Player* player) override;
        void SetUnload();
        //void UnloadAll(bool pForce);
        void RemoveAllPlayers() override;

        virtual void InitVisibilityDistance() override;
        Battleground* GetBG() { return m_bg; }
        void SetBG(Battleground* bg) { m_bg = bg; }
    private:
        Battleground* m_bg;
};

template<class T, class CONTAINER>
inline void Map::Visit(Cell const& cell, TypeContainerVisitor<T, CONTAINER>& visitor)
{
    const uint32 x = cell.GridX();
    const uint32 y = cell.GridY();
    const uint32 cell_x = cell.CellX();
    const uint32 cell_y = cell.CellY();

    if (!cell.NoCreate() || IsGridLoaded(GridCoord(x, y)))
    {
        EnsureGridLoaded(cell);
        getNGrid(x, y)->VisitGrid(cell_x, cell_y, visitor);
    }
}

template<class NOTIFIER>
inline void Map::VisitAll(float const& x, float const& y, float radius, NOTIFIER& notifier)
{
    CellCoord p(Trinity::ComputeCellCoord(x, y));
    Cell cell(p);
    cell.SetNoCreate();

    TypeContainerVisitor<NOTIFIER, WorldTypeMapContainer> world_object_notifier(notifier);
    cell.Visit(p, world_object_notifier, *this, radius, x, y);
    TypeContainerVisitor<NOTIFIER, GridTypeMapContainer >  grid_object_notifier(notifier);
    cell.Visit(p, grid_object_notifier, *this, radius, x, y);
}

// should be used with Searcher notifiers, tries to search world if nothing found in grid
template<class NOTIFIER>
inline void Map::VisitFirstFound(const float &x, const float &y, float radius, NOTIFIER &notifier)
{
    CellCoord p(Trinity::ComputeCellCoord(x, y));
    Cell cell(p);
    cell.SetNoCreate();

    TypeContainerVisitor<NOTIFIER, WorldTypeMapContainer> world_object_notifier(notifier);
    cell.Visit(p, world_object_notifier, *this, radius, x, y);
    if (!notifier.i_object)
    {
        TypeContainerVisitor<NOTIFIER, GridTypeMapContainer >  grid_object_notifier(notifier);
        cell.Visit(p, grid_object_notifier, *this, radius, x, y);
    }
}

template<class NOTIFIER>
inline void Map::VisitWorld(const float &x, const float &y, float radius, NOTIFIER &notifier)
{
    CellCoord p(Trinity::ComputeCellCoord(x, y));
    Cell cell(p);
    cell.SetNoCreate();

    TypeContainerVisitor<NOTIFIER, WorldTypeMapContainer> world_object_notifier(notifier);
    cell.Visit(p, world_object_notifier, *this, radius, x, y);
}

template<class NOTIFIER>
inline void Map::VisitGrid(const float &x, const float &y, float radius, NOTIFIER &notifier)
{
    CellCoord p(Trinity::ComputeCellCoord(x, y));
    Cell cell(p);
    cell.SetNoCreate();

    TypeContainerVisitor<NOTIFIER, GridTypeMapContainer >  grid_object_notifier(notifier);
    cell.Visit(p, grid_object_notifier, *this, radius, x, y);
}
#endif
