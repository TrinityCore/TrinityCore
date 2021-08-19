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

#ifndef TRINITY_MAP_H
#define TRINITY_MAP_H

#include "Define.h"

#include "Cell.h"
#include "DatabaseEnvFwd.h"
#include "DynamicTree.h"
#include "GridDefines.h"
#include "GridRefManager.h"
#include "MapDefines.h"
#include "MapRefManager.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "SharedDefines.h"
#include "SpawnData.h"
#include "Timer.h"
#include <boost/heap/fibonacci_heap.hpp>
#include <bitset>
#include <list>
#include <memory>
#include <mutex>
#include <set>
#include <unordered_set>

class Battleground;
class BattlegroundMap;
class CreatureGroup;
class GameObjectModel;
class Group;
class InstanceMap;
class InstanceSave;
class InstanceScript;
class InstanceScenario;
class MapInstanced;
class Object;
class PhaseShift;
class Player;
class TempSummon;
class Unit;
class Weather;
class WorldObject;
class WorldPacket;
struct MapDifficultyEntry;
struct MapEntry;
struct Position;
struct ScriptAction;
struct ScriptInfo;
struct SummonPropertiesEntry;
class Transport;
enum Difficulty : uint8;
enum WeatherState : uint32;
enum class ItemContext : uint8;

namespace Trinity { struct ObjectUpdater; }
namespace G3D { class Plane; }
namespace VMAP { enum class ModelIgnoreFlags : uint32; }

struct ScriptAction
{
    ObjectGuid sourceGUID;
    ObjectGuid targetGUID;
    ObjectGuid ownerGUID;                                   ///> owner of source if source is item
    ScriptInfo const* script;                               ///> pointer to static script data
};

enum ZLiquidStatus : uint32
{
    LIQUID_MAP_NO_WATER     = 0x00000000,
    LIQUID_MAP_ABOVE_WATER  = 0x00000001,
    LIQUID_MAP_WATER_WALK   = 0x00000002,
    LIQUID_MAP_IN_WATER     = 0x00000004,
    LIQUID_MAP_UNDER_WATER  = 0x00000008
};

#define MAP_LIQUID_STATUS_SWIMMING (LIQUID_MAP_IN_WATER | LIQUID_MAP_UNDER_WATER)
#define MAP_LIQUID_STATUS_IN_CONTACT (MAP_LIQUID_STATUS_SWIMMING | LIQUID_MAP_WATER_WALK)

struct LiquidData
{
    EnumFlag<map_liquidHeaderTypeFlags> type_flags = map_liquidHeaderTypeFlags::NoWater;
    uint32 entry;
    float  level;
    float  depth_level;
};

struct PositionFullTerrainStatus
{
    struct AreaInfo
    {
        AreaInfo(int32 _adtId, int32 _rootId, int32 _groupId, uint32 _flags) : adtId(_adtId), rootId(_rootId), groupId(_groupId), mogpFlags(_flags) { }
        int32 const adtId;
        int32 const rootId;
        int32 const groupId;
        uint32 const mogpFlags;
    };

    uint32 areaId;
    float floorZ;
    bool outdoors;
    ZLiquidStatus liquidStatus;
    Optional<AreaInfo> areaInfo;
    Optional<LiquidData> liquidInfo;
};

class TC_GAME_API GridMap
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
    G3D::Plane* _minHeightPlanes;
    // Height level data
    float _gridHeight;
    float _gridIntHeightMultiplier;

    // Area data
    uint16* _areaMap;

    // Liquid data
    float _liquidLevel;
    uint16* _liquidEntry;
    map_liquidHeaderTypeFlags* _liquidFlags;
    float* _liquidMap;
    uint16 _gridArea;
    uint16 _liquidGlobalEntry;
    map_liquidHeaderTypeFlags _liquidGlobalFlags;
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

    enum class LoadResult
    {
        Ok,
        FileDoesNotExist,
        InvalidFile
    };

    LoadResult loadData(char const* filename);
    void unloadData();

    uint16 getArea(float x, float y) const;
    inline float getHeight(float x, float y) const {return (this->*_gridGetHeight)(x, y);}
    float getMinHeight(float x, float y) const;
    float getLiquidLevel(float x, float y) const;
    map_liquidHeaderTypeFlags getTerrainType(float x, float y) const;
    ZLiquidStatus GetLiquidStatus(float x, float y, float z, Optional<map_liquidHeaderTypeFlags> ReqLiquidType, LiquidData* data = nullptr, float collisionHeight = 2.03128f); // DEFAULT_COLLISION_HEIGHT in Object.h
};

#pragma pack(push, 1)

struct ZoneDynamicInfo
{
    ZoneDynamicInfo();

    uint32 MusicId;
    std::unique_ptr<Weather> DefaultWeather;
    WeatherState WeatherId;
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
#define MAP_INVALID_ZONE      0xFFFFFFFF

struct RespawnInfo; // forward declaration
struct CompareRespawnInfo
{
    bool operator()(RespawnInfo const* a, RespawnInfo const* b) const;
};
typedef std::unordered_map<uint32 /*zoneId*/, ZoneDynamicInfo> ZoneDynamicInfoMap;
typedef boost::heap::fibonacci_heap<RespawnInfo*, boost::heap::compare<CompareRespawnInfo>> RespawnListContainer;
typedef RespawnListContainer::handle_type RespawnListHandle;
typedef std::unordered_map<ObjectGuid::LowType, RespawnInfo*> RespawnInfoMap;
struct RespawnInfo
{
    SpawnObjectType type;
    ObjectGuid::LowType spawnId;
    uint32 entry;
    time_t respawnTime;
    uint32 gridId;
    uint32 zoneId;
    RespawnListHandle handle;
};
inline bool CompareRespawnInfo::operator()(RespawnInfo const* a, RespawnInfo const* b) const
{
    if (a == b)
        return false;
    if (a->respawnTime != b->respawnTime)
        return (a->respawnTime > b->respawnTime);
    if (a->spawnId != b->spawnId)
        return a->spawnId < b->spawnId;
    ASSERT(a->type != b->type, "Duplicate respawn entry for spawnId (%u," UI64FMTD ") found!", a->type, a->spawnId);
    return a->type < b->type;
}

typedef TypeUnorderedMapContainer<AllMapStoredObjectTypes, ObjectGuid> MapStoredObjectTypesContainer;

class TC_GAME_API Map : public GridRefManager<NGridType>
{
    friend class MapReference;
    public:
        Map(uint32 id, time_t, uint32 InstanceId, Difficulty SpawnMode, Map* _parent = nullptr);
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

        virtual bool AddPlayerToMap(Player* player, bool initPlayer = true);
        virtual void RemovePlayerFromMap(Player*, bool);

        template<class T> bool AddToMap(T *);
        template<class T> void RemoveFromMap(T *, bool);

        void VisitNearbyCellsOf(WorldObject* obj, TypeContainerVisitor<Trinity::ObjectUpdater, GridTypeMapContainer> &gridVisitor, TypeContainerVisitor<Trinity::ObjectUpdater, WorldTypeMapContainer> &worldVisitor);
        virtual void Update(uint32);

        float GetVisibilityRange() const { return m_VisibleDistance; }
        //function for setting up visibility distance for maps on per-type/per-Id basis
        virtual void InitVisibilityDistance();

        void PlayerRelocation(Player*, float x, float y, float z, float orientation);
        void CreatureRelocation(Creature* creature, float x, float y, float z, float ang, bool respawnRelocationOnFail = true);
        void GameObjectRelocation(GameObject* go, float x, float y, float z, float orientation, bool respawnRelocationOnFail = true);
        void DynamicObjectRelocation(DynamicObject* go, float x, float y, float z, float orientation);
        void AreaTriggerRelocation(AreaTrigger* at, float x, float y, float z, float orientation);

        template<class T, class CONTAINER>
        void Visit(Cell const& cell, TypeContainerVisitor<T, CONTAINER>& visitor);

        bool IsRemovalGrid(float x, float y) const
        {
            GridCoord p = Trinity::ComputeGridCoord(x, y);
            return !getNGrid(p.x_coord, p.y_coord) || getNGrid(p.x_coord, p.y_coord)->GetGridState() == GRID_STATE_REMOVAL;
        }
        bool IsRemovalGrid(Position const& pos) const { return IsRemovalGrid(pos.GetPositionX(), pos.GetPositionY()); }

        bool IsGridLoaded(uint32 gridId) const { return IsGridLoaded(GridCoord(gridId % MAX_NUMBER_OF_GRIDS, gridId / MAX_NUMBER_OF_GRIDS)); }
        bool IsGridLoaded(float x, float y) const { return IsGridLoaded(Trinity::ComputeGridCoord(x, y)); }
        bool IsGridLoaded(Position const& pos) const { return IsGridLoaded(pos.GetPositionX(), pos.GetPositionY()); }

        bool GetUnloadLock(GridCoord const& p) const { return getNGrid(p.x_coord, p.y_coord)->getUnloadLock(); }
        void SetUnloadLock(GridCoord const& p, bool on) { getNGrid(p.x_coord, p.y_coord)->setUnloadExplicitLock(on); }
        void LoadGrid(float x, float y);
        void LoadAllCells();
        bool UnloadGrid(NGridType& ngrid, bool pForce);
        void GridMarkNoUnload(uint32 x, uint32 y);
        void GridUnmarkNoUnload(uint32 x, uint32 y);
        virtual void UnloadAll();

        void ResetGridExpiry(NGridType &grid, float factor = 1) const
        {
            grid.ResetTimeTracker(time_t(float(i_gridExpiry)*factor));
        }

        time_t GetGridExpiry() const { return i_gridExpiry; }

        bool HasChildMapGridFile(uint32 mapId, int32 gx, int32 gy) const;
        static bool ExistMap(uint32 mapid, int gx, int gy, bool log = true);
        static bool ExistVMap(uint32 mapid, int gx, int gy);

        static void InitStateMachine();
        static void DeleteStateMachine();

        void DiscoverGridMapFiles();

        Map* GetRootParentTerrainMap();
        void AddChildTerrainMap(Map* map) { m_childTerrainMaps->push_back(map); map->m_parentTerrainMap = this; }
        void UnlinkAllChildTerrainMaps() { m_childTerrainMaps->clear(); }

        void GetFullTerrainStatusForPosition(float x, float y, float z, PositionFullTerrainStatus& data, map_liquidHeaderTypeFlags reqLiquidType = map_liquidHeaderTypeFlags::AllLiquids, float collisionHeight = 2.03128f) const; // DEFAULT_COLLISION_HEIGHT in Object.h
        void GetFullTerrainStatusForPosition(PhaseShift const& phaseShift, float x, float y, float z, PositionFullTerrainStatus& data, map_liquidHeaderTypeFlags reqLiquidType = map_liquidHeaderTypeFlags::AllLiquids, float collisionHeight = 2.03128f); // DEFAULT_COLLISION_HEIGHT in Object.h
        ZLiquidStatus GetLiquidStatus(PhaseShift const& phaseShift, float x, float y, float z, map_liquidHeaderTypeFlags ReqLiquidType, LiquidData* data = nullptr, float collisionHeight = 2.03128f); // DEFAULT_COLLISION_HEIGHT in Object.h

        bool GetAreaInfo(PhaseShift const& phaseShift, float x, float y, float z, uint32& mogpflags, int32& adtId, int32& rootId, int32& groupId);
        uint32 GetAreaId(PhaseShift const& phaseShift, float x, float y, float z, bool *isOutdoors = nullptr);
        uint32 GetAreaId(PhaseShift const& phaseShift, Position const& pos) { return GetAreaId(phaseShift, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()); }
        uint32 GetZoneId(PhaseShift const& phaseShift, float x, float y, float z);
        uint32 GetZoneId(PhaseShift const& phaseShift, Position const& pos) { return GetZoneId(phaseShift, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()); }
        void GetZoneAndAreaId(PhaseShift const& phaseShift, uint32& zoneid, uint32& areaid, float x, float y, float z);
        void GetZoneAndAreaId(PhaseShift const& phaseShift, uint32& zoneid, uint32& areaid, Position const& pos) { GetZoneAndAreaId(phaseShift, zoneid, areaid, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()); }

        bool IsOutdoors(PhaseShift const& phaseShift, float x, float y, float z);

        map_liquidHeaderTypeFlags GetTerrainType(PhaseShift const& phaseShift, float x, float y);
        float GetWaterLevel(PhaseShift const& phaseShift, float x, float y);
        bool IsInWater(PhaseShift const& phaseShift, float x, float y, float z, LiquidData* data = nullptr);
        bool IsUnderWater(PhaseShift const& phaseShift, float x, float y, float z);

        void MoveAllCreaturesInMoveList();
        void MoveAllGameObjectsInMoveList();
        void MoveAllDynamicObjectsInMoveList();
        void MoveAllAreaTriggersInMoveList();
        void RemoveAllObjectsInRemoveList();
        virtual void RemoveAllPlayers();

        // used only in MoveAllCreaturesInMoveList and ObjectGridUnloader
        bool CreatureRespawnRelocation(Creature* c, bool diffGridOnly);
        bool GameObjectRespawnRelocation(GameObject* go, bool diffGridOnly);

        // assert print helper
        template <typename T>
        static bool CheckGridIntegrity(T* object, bool moved, char const* objType);

        uint32 GetInstanceId() const { return i_InstanceId; }

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
        char const* GetMapName() const;

        // have meaning only for instanced map (that have set real difficulty)
        Difficulty GetDifficultyID() const { return Difficulty(i_spawnMode); }
        MapDifficultyEntry const* GetMapDifficulty() const;
        ItemContext GetDifficultyLootItemContext() const;

        uint32 GetId() const;
        bool Instanceable() const;
        bool IsDungeon() const;
        bool IsNonRaidDungeon() const;
        bool IsRaid() const;
        bool IsRaidOrHeroicDungeon() const;
        bool IsHeroic() const;
        bool Is25ManRaid() const;
        bool IsBattleground() const;
        bool IsBattleArena() const;
        bool IsBattlegroundOrArena() const;
        bool IsGarrison() const;
        bool GetEntrancePos(int32& mapid, float& x, float& y);

        void AddObjectToRemoveList(WorldObject* obj);
        void AddObjectToSwitchList(WorldObject* obj, bool on);
        virtual void DelayedUpdate(uint32 diff);

        void resetMarkedCells() { marked_cells.reset(); }
        bool isCellMarked(uint32 pCellId) { return marked_cells.test(pCellId); }
        void markCell(uint32 pCellId) { marked_cells.set(pCellId); }

        bool HavePlayers() const { return !m_mapRefManager.isEmpty(); }
        uint32 GetPlayersCountExceptGMs() const;
        bool ActiveObjectsNearGrid(NGridType const& ngrid) const;

        void AddWorldObject(WorldObject* obj) { i_worldObjects.insert(obj); }
        void RemoveWorldObject(WorldObject* obj) { i_worldObjects.erase(obj); }

        void SendToPlayers(WorldPacket const* data) const;

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
        std::unordered_map<ObjectGuid::LowType /*leaderSpawnId*/, CreatureGroup*> CreatureGroupHolder;

        void UpdateIteratorBack(Player* player);

        TempSummon* SummonCreature(uint32 entry, Position const& pos, SummonPropertiesEntry const* properties = nullptr, uint32 duration = 0, Unit* summoner = nullptr, uint32 spellId = 0, uint32 vehId = 0, ObjectGuid privateObjectOwner = ObjectGuid::Empty);
        void SummonCreatureGroup(uint8 group, std::list<TempSummon*>* list = nullptr);
        AreaTrigger* GetAreaTrigger(ObjectGuid const& guid);
        Conversation* GetConversation(ObjectGuid const& guid);
        Player* GetPlayer(ObjectGuid const& guid);
        Corpse* GetCorpse(ObjectGuid const& guid);
        Creature* GetCreature(ObjectGuid const& guid);
        DynamicObject* GetDynamicObject(ObjectGuid const& guid);
        GameObject* GetGameObject(ObjectGuid const& guid);
        Pet* GetPet(ObjectGuid const& guid);
        Transport* GetTransport(ObjectGuid const& guid);
        Creature* GetCreatureBySpawnId(ObjectGuid::LowType spawnId) const;
        GameObject* GetGameObjectBySpawnId(ObjectGuid::LowType spawnId) const;
        WorldObject* GetWorldObjectBySpawnId(SpawnObjectType type, ObjectGuid::LowType spawnId) const { return (type == SPAWN_TYPE_GAMEOBJECT) ? reinterpret_cast<WorldObject*>(GetGameObjectBySpawnId(spawnId)) : reinterpret_cast<WorldObject*>(GetCreatureBySpawnId(spawnId)); }

        MapStoredObjectTypesContainer& GetObjectsStore() { return _objectsStore; }

        typedef std::unordered_multimap<ObjectGuid::LowType, Creature*> CreatureBySpawnIdContainer;
        CreatureBySpawnIdContainer& GetCreatureBySpawnIdStore() { return _creatureBySpawnIdStore; }
        CreatureBySpawnIdContainer const& GetCreatureBySpawnIdStore() const { return _creatureBySpawnIdStore; }

        typedef std::unordered_multimap<ObjectGuid::LowType, GameObject*> GameObjectBySpawnIdContainer;
        GameObjectBySpawnIdContainer& GetGameObjectBySpawnIdStore() { return _gameobjectBySpawnIdStore; }
        GameObjectBySpawnIdContainer const& GetGameObjectBySpawnIdStore() const { return _gameobjectBySpawnIdStore; }

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

        MapInstanced* ToMapInstanced() { if (Instanceable()) return reinterpret_cast<MapInstanced*>(this); return nullptr; }
        MapInstanced const* ToMapInstanced() const { if (Instanceable()) return reinterpret_cast<MapInstanced const*>(this); return nullptr; }

        InstanceMap* ToInstanceMap() { if (IsDungeon()) return reinterpret_cast<InstanceMap*>(this); else return nullptr;  }
        InstanceMap const* ToInstanceMap() const { if (IsDungeon()) return reinterpret_cast<InstanceMap const*>(this); return nullptr; }

        BattlegroundMap* ToBattlegroundMap() { if (IsBattlegroundOrArena()) return reinterpret_cast<BattlegroundMap*>(this); else return nullptr;  }
        BattlegroundMap const* ToBattlegroundMap() const { if (IsBattlegroundOrArena()) return reinterpret_cast<BattlegroundMap const*>(this); return nullptr; }

        float GetWaterOrGroundLevel(PhaseShift const& phaseShift, float x, float y, float z, float* ground = nullptr, bool swim = false, float collisionHeight = 2.03128f); // DEFAULT_COLLISION_HEIGHT in Object.h
        float GetMinHeight(PhaseShift const& phaseShift, float x, float y);
        float GetStaticHeight(PhaseShift const& phaseShift, float x, float y, float z, bool checkVMap = true, float maxSearchDist = DEFAULT_HEIGHT_SEARCH);
        float GetStaticHeight(PhaseShift const& phaseShift, Position const& pos, bool checkVMap = true, float maxSearchDist = DEFAULT_HEIGHT_SEARCH) { return GetStaticHeight(phaseShift, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), checkVMap, maxSearchDist); }
        float GetHeight(PhaseShift const& phaseShift, float x, float y, float z, bool vmap = true, float maxSearchDist = DEFAULT_HEIGHT_SEARCH) { return std::max<float>(GetStaticHeight(phaseShift, x, y, z, vmap, maxSearchDist), GetGameObjectFloor(phaseShift, x, y, z, maxSearchDist)); }
        float GetHeight(PhaseShift const& phaseShift, Position const& pos, bool vmap = true, float maxSearchDist = DEFAULT_HEIGHT_SEARCH) { return GetHeight(phaseShift, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), vmap, maxSearchDist); }
        bool isInLineOfSight(PhaseShift const& phaseShift, float x1, float y1, float z1, float x2, float y2, float z2, LineOfSightChecks checks, VMAP::ModelIgnoreFlags ignoreFlags) const;
        void Balance() { _dynamicTree.balance(); }
        void RemoveGameObjectModel(GameObjectModel const& model) { _dynamicTree.remove(model); }
        void InsertGameObjectModel(GameObjectModel const& model) { _dynamicTree.insert(model); }
        bool ContainsGameObjectModel(GameObjectModel const& model) const { return _dynamicTree.contains(model);}
        float GetGameObjectFloor(PhaseShift const& phaseShift, float x, float y, float z, float maxSearchDist = DEFAULT_HEIGHT_SEARCH) const
        {
            return _dynamicTree.getHeight(x, y, z, maxSearchDist, phaseShift);
        }
        bool getObjectHitPos(PhaseShift const& phaseShift, float x1, float y1, float z1, float x2, float y2, float z2, float& rx, float &ry, float& rz, float modifyDist);

        virtual ObjectGuid::LowType GetOwnerGuildId(uint32 /*team*/ = TEAM_OTHER) const { return UI64LIT(0); }
        /*
            RESPAWN TIMES
        */
        time_t GetLinkedRespawnTime(ObjectGuid guid) const;
        time_t GetCreatureRespawnTime(ObjectGuid::LowType dbGuid) const
        {
            RespawnInfoMap::const_iterator itr = _creatureRespawnTimesBySpawnId.find(dbGuid);
            return itr != _creatureRespawnTimesBySpawnId.end() ? itr->second->respawnTime : 0;
        }

        time_t GetGORespawnTime(ObjectGuid::LowType dbGuid) const
        {
            RespawnInfoMap::const_iterator itr = _gameObjectRespawnTimesBySpawnId.find(dbGuid);
            return itr != _gameObjectRespawnTimesBySpawnId.end() ? itr->second->respawnTime : 0;
        }

        time_t GetRespawnTime(SpawnObjectType type, ObjectGuid::LowType spawnId) const { return (type == SPAWN_TYPE_GAMEOBJECT) ? GetGORespawnTime(spawnId) : GetCreatureRespawnTime(spawnId); }

        void UpdatePlayerZoneStats(uint32 oldZone, uint32 newZone);

        void SaveRespawnTime(SpawnObjectType type, ObjectGuid::LowType spawnId, uint32 entry, time_t respawnTime, uint32 zoneId, uint32 gridId = 0, bool writeDB = true, bool replace = false, CharacterDatabaseTransaction dbTrans = nullptr);
        void SaveRespawnTimeDB(SpawnObjectType type, ObjectGuid::LowType spawnId, time_t respawnTime, CharacterDatabaseTransaction dbTrans = nullptr);
        void LoadRespawnTimes();
        void DeleteRespawnTimes() { DeleteRespawnInfo(); DeleteRespawnTimesInDB(GetId(), GetInstanceId()); }

        void LoadCorpseData();
        void DeleteCorpseData();
        void AddCorpse(Corpse* corpse);
        void RemoveCorpse(Corpse* corpse);
        Corpse* ConvertCorpseToBones(ObjectGuid const& ownerGuid, bool insignia = false);
        void RemoveOldCorpses();

        static void DeleteRespawnTimesInDB(uint16 mapId, uint32 instanceId);

        void SendInitTransports(Player* player);
        void SendRemoveTransports(Player* player);
        void SendUpdateTransportVisibility(Player* player);
        void SendZoneDynamicInfo(uint32 zoneId, Player* player) const;
        void SendZoneWeather(uint32 zoneId, Player* player) const;
        void SendZoneWeather(ZoneDynamicInfo const& zoneDynamicInfo, Player* player) const;

        void SetZoneMusic(uint32 zoneId, uint32 musicId);
        Weather* GetOrGenerateZoneDefaultWeather(uint32 zoneId);
        WeatherState GetZoneWeather(uint32 zoneId) const;
        void SetZoneWeather(uint32 zoneId, WeatherState weatherId, float weatherGrade);
        void SetZoneOverrideLight(uint32 zoneId, uint32 lightId, uint32 fadeInTime);

        void UpdateAreaDependentAuras();

        template<HighGuid high>
        inline ObjectGuid::LowType GenerateLowGuid()
        {
            static_assert(ObjectGuidTraits<high>::SequenceSource.HasFlag(ObjectGuidSequenceSource::Map), "Only map specific guid can be generated in Map context");
            return GetGuidSequenceGenerator<high>().Generate();
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
        void LoadMap(int gx, int gy);
        static void LoadMapImpl(Map* map, int gx, int gy);
        void UnloadMap(int gx, int gy);
        static void UnloadMapImpl(Map* map, int gx, int gy);
        void LoadMMap(int gx, int gy);
        GridMap* GetGrid(uint32 mapId, float x, float y);

        void SetTimer(uint32 t) { i_gridExpiry = t < MIN_GRID_DELAY ? MIN_GRID_DELAY : t; }

        void SendInitSelf(Player* player);

        template <typename T>
        bool MapObjectCellRelocation(T* object, Cell new_cell, char const* objType);

        bool CreatureCellRelocation(Creature* creature, Cell new_cell);
        bool GameObjectCellRelocation(GameObject* go, Cell new_cell);
        bool DynamicObjectCellRelocation(DynamicObject* go, Cell new_cell);
        bool AreaTriggerCellRelocation(AreaTrigger* at, Cell new_cell);

        template<class T> void InitializeObject(T* obj);
        void AddCreatureToMoveList(Creature* c, float x, float y, float z, float ang);
        void RemoveCreatureFromMoveList(Creature* c);
        void AddGameObjectToMoveList(GameObject* go, float x, float y, float z, float ang);
        void RemoveGameObjectFromMoveList(GameObject* go);
        void AddDynamicObjectToMoveList(DynamicObject* go, float x, float y, float z, float ang);
        void RemoveDynamicObjectFromMoveList(DynamicObject* go);
        void AddAreaTriggerToMoveList(AreaTrigger* at, float x, float y, float z, float ang);
        void RemoveAreaTriggerFromMoveList(AreaTrigger* at);

        bool _creatureToMoveLock;
        std::vector<Creature*> _creaturesToMove;

        bool _gameObjectsToMoveLock;
        std::vector<GameObject*> _gameObjectsToMove;

        bool _dynamicObjectsToMoveLock;
        std::vector<DynamicObject*> _dynamicObjectsToMove;

        bool _areaTriggersToMoveLock;
        std::vector<AreaTrigger*> _areaTriggersToMove;

        bool IsGridLoaded(GridCoord const&) const;
        void EnsureGridCreated(GridCoord const&);
        void EnsureGridCreated_i(GridCoord const&);
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

        void SendObjectUpdates();

    protected:
        virtual void LoadGridObjects(NGridType* grid, Cell const& cell);

        std::mutex _mapLock;
        std::mutex _gridLock;

        MapEntry const* i_mapEntry;
        Difficulty i_spawnMode;
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
        Player* _GetScriptPlayerSourceOrTarget(Object* source, Object* target, ScriptInfo const* scriptInfo) const;
        Creature* _GetScriptCreatureSourceOrTarget(Object* source, Object* target, ScriptInfo const* scriptInfo, bool bReverse = false) const;
        Unit* _GetScriptUnit(Object* obj, bool isSource, ScriptInfo const* scriptInfo) const;
        Player* _GetScriptPlayer(Object* obj, bool isSource, ScriptInfo const* scriptInfo) const;
        Creature* _GetScriptCreature(Object* obj, bool isSource, ScriptInfo const* scriptInfo) const;
        WorldObject* _GetScriptWorldObject(Object* obj, bool isSource, ScriptInfo const* scriptInfo) const;
        void _ScriptProcessDoor(Object* source, Object* target, ScriptInfo const* scriptInfo) const;
        GameObject* _FindGameObject(WorldObject* pWorldObject, ObjectGuid::LowType guid) const;

        time_t i_gridExpiry;

        //used for fast base_map (e.g. MapInstanced class object) search for
        //InstanceMaps and BattlegroundMaps...
        Map* m_parentMap;                                           // points to MapInstanced* or self (always same map id)
        Map* m_parentTerrainMap;                                    // points to m_parentMap of MapEntry::ParentMapID
        std::vector<Map*>* m_childTerrainMaps;                      // contains m_parentMap of maps that have MapEntry::ParentMapID == GetId()

        NGridType* i_grids[MAX_NUMBER_OF_GRIDS][MAX_NUMBER_OF_GRIDS];
        std::shared_ptr<GridMap> GridMaps[MAX_NUMBER_OF_GRIDS][MAX_NUMBER_OF_GRIDS];
        uint16 GridMapReference[MAX_NUMBER_OF_GRIDS][MAX_NUMBER_OF_GRIDS];
        std::bitset<MAX_NUMBER_OF_GRIDS * MAX_NUMBER_OF_GRIDS> i_gridFileExists; // cache what grids are available for this map (not including parent/child maps)
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

    public:
        void ProcessRespawns();
        void ApplyDynamicModeRespawnScaling(WorldObject const* obj, ObjectGuid::LowType spawnId, uint32& respawnDelay, uint32 mode) const;

    private:
        // if return value is true, we can respawn
        // if return value is false, reschedule the respawn to new value of info->respawnTime iff nonzero, delete otherwise
        // if return value is false and info->respawnTime is nonzero, it is guaranteed to be greater than time(NULL)
        bool CheckRespawn(RespawnInfo* info);
        void DoRespawn(SpawnObjectType type, ObjectGuid::LowType spawnId, uint32 gridId);
        void Respawn(RespawnInfo* info, bool force = false, CharacterDatabaseTransaction dbTrans = nullptr);
        void Respawn(std::vector<RespawnInfo*>& respawnData, bool force = false, CharacterDatabaseTransaction dbTrans = nullptr);
        void AddRespawnInfo(RespawnInfo& info, bool replace = false);
        void DeleteRespawnInfo();
        void DeleteRespawnInfo(RespawnInfo* info);
        void DeleteRespawnInfo(std::vector<RespawnInfo*>& toDelete)
        {
            for (RespawnInfo* info : toDelete)
                DeleteRespawnInfo(info);
            toDelete.clear();
        }
        void DeleteRespawnInfo(SpawnObjectTypeMask types, uint32 zoneId = 0)
        {
            std::vector<RespawnInfo*> v;
            GetRespawnInfo(v, types, zoneId);
            if (!v.empty())
                DeleteRespawnInfo(v);
        }
        void DeleteRespawnInfo(SpawnObjectType type, ObjectGuid::LowType spawnId)
        {
            if (RespawnInfo* info = GetRespawnInfo(type, spawnId))
                DeleteRespawnInfo(info);
        }

    public:
        void GetRespawnInfo(std::vector<RespawnInfo*>& respawnData, SpawnObjectTypeMask types, uint32 zoneId = 0) const;
        RespawnInfo* GetRespawnInfo(SpawnObjectType type, ObjectGuid::LowType spawnId) const;
        void ForceRespawn(SpawnObjectType type, ObjectGuid::LowType spawnId)
        {
            if (RespawnInfo* info = GetRespawnInfo(type, spawnId))
                Respawn(info, true);
        }
        void RemoveRespawnTime(RespawnInfo* info, bool doRespawn = false, CharacterDatabaseTransaction dbTrans = nullptr);
        void RemoveRespawnTime(std::vector<RespawnInfo*>& respawnData, bool doRespawn = false, CharacterDatabaseTransaction dbTrans = nullptr);
        void RemoveRespawnTime(SpawnObjectTypeMask types = SPAWN_TYPEMASK_ALL, uint32 zoneId = 0, bool doRespawn = false, CharacterDatabaseTransaction dbTrans = nullptr)
        {
            std::vector<RespawnInfo*> v;
            GetRespawnInfo(v, types, zoneId);
            if (!v.empty())
                RemoveRespawnTime(v, doRespawn, dbTrans);
        }
        void RemoveRespawnTime(SpawnObjectType type, ObjectGuid::LowType spawnId, bool doRespawn = false, CharacterDatabaseTransaction dbTrans = nullptr)
        {
            if (RespawnInfo* info = GetRespawnInfo(type, spawnId))
                RemoveRespawnTime(info, doRespawn, dbTrans);
        }

        SpawnGroupTemplateData const* GetSpawnGroupData(uint32 groupId) const;

        bool IsSpawnGroupActive(uint32 groupId) const;

        // Enable the spawn group, which causes all creatures in it to respawn (unless they have a respawn timer)
        // The force flag can be used to force spawning additional copies even if old copies are still around from a previous spawn
        bool SpawnGroupSpawn(uint32 groupId, bool ignoreRespawn = false, bool force = false, std::vector<WorldObject*>* spawnedObjects = nullptr);

        // Despawn all creatures in the spawn group if spawned, optionally delete their respawn timer, and disable the group
        bool SpawnGroupDespawn(uint32 groupId, bool deleteRespawnTimes = false, size_t* count = nullptr);

        // Disable the spawn group, which prevents any creatures in the group from respawning until re-enabled
        // This will not affect any already-present creatures in the group
        void SetSpawnGroupInactive(uint32 groupId) { SetSpawnGroupActive(groupId, false); }

    private:
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

        RespawnListContainer _respawnTimes;
        RespawnInfoMap       _creatureRespawnTimesBySpawnId;
        RespawnInfoMap       _gameObjectRespawnTimesBySpawnId;
        RespawnInfoMap& GetRespawnMapForType(SpawnObjectType type) { return (type == SPAWN_TYPE_GAMEOBJECT) ? _gameObjectRespawnTimesBySpawnId : _creatureRespawnTimesBySpawnId; }
        RespawnInfoMap const& GetRespawnMapForType(SpawnObjectType type) const { return (type == SPAWN_TYPE_GAMEOBJECT) ? _gameObjectRespawnTimesBySpawnId : _creatureRespawnTimesBySpawnId; }

        void SetSpawnGroupActive(uint32 groupId, bool state);
        std::unordered_set<uint32> _toggledSpawnGroupIds;

        uint32 _respawnCheckTimer;
        std::unordered_map<uint32, uint32> _zonePlayerCountMap;

        ZoneDynamicInfoMap _zoneDynamicInfo;
        IntervalTimer _weatherUpdateTimer;
        uint32 _defaultLight;

        template<HighGuid high>
        inline ObjectGuidGeneratorBase& GetGuidSequenceGenerator()
        {
            auto itr = _guidGenerators.find(high);
            if (itr == _guidGenerators.end())
                itr = _guidGenerators.insert(std::make_pair(high, std::make_unique<ObjectGuidGenerator<high>>())).first;

            return *itr->second;
        }

        std::map<HighGuid, std::unique_ptr<ObjectGuidGeneratorBase>> _guidGenerators;
        MapStoredObjectTypesContainer _objectsStore;
        CreatureBySpawnIdContainer _creatureBySpawnIdStore;
        GameObjectBySpawnIdContainer _gameobjectBySpawnIdStore;
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

class TC_GAME_API InstanceMap : public Map
{
    public:
        InstanceMap(uint32 id, time_t, uint32 InstanceId, Difficulty SpawnMode, Map* _parent);
        ~InstanceMap();
        bool AddPlayerToMap(Player* player, bool initPlayer = true) override;
        void RemovePlayerFromMap(Player*, bool) override;
        void Update(uint32) override;
        void CreateInstanceData(bool load);
        bool Reset(uint8 method);
        uint32 GetScriptId() const { return i_script_id; }
        std::string const& GetScriptName() const;
        InstanceScript* GetInstanceScript() { return i_data; }
        InstanceScript const* GetInstanceScript() const { return i_data; }
        InstanceScenario* GetInstanceScenario() { return i_scenario; }
        InstanceScenario const* GetInstanceScenario() const { return i_scenario; }
        void SetInstanceScenario(InstanceScenario* scenario) { i_scenario = scenario; }
        void PermBindAllPlayers();
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
        InstanceScenario* i_scenario;
};

class TC_GAME_API BattlegroundMap : public Map
{
    public:
        BattlegroundMap(uint32 id, time_t, uint32 InstanceId, Map* _parent, Difficulty spawnMode);
        ~BattlegroundMap();

        bool AddPlayerToMap(Player* player, bool initPlayer = true) override;
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
#endif
