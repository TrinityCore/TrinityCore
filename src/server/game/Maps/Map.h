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
#include "GroupInstanceReference.h"
#include "MapDefines.h"
#include "MapReference.h"
#include "MapRefManager.h"
#include "MPSCQueue.h"
#include "ObjectGuid.h"
#include "PersonalPhaseTracker.h"
#include "SharedDefines.h"
#include "SpawnData.h"
#include "Timer.h"
#include "WorldStateDefines.h"
#include <bitset>
#include <list>
#include <map>
#include <memory>
#include <set>
#include <unordered_set>

class Battleground;
class BattlegroundMap;
class CreatureGroup;
class GameObjectModel;
class Group;
class InstanceLock;
class InstanceMap;
class InstanceScript;
class InstanceScenario;
class Object;
class PhaseShift;
class Player;
class SpawnedPoolData;
class TempSummon;
class TerrainInfo;
class Unit;
class Weather;
class WorldObject;
class WorldPacket;
struct DungeonEncounterEntry;
struct MapDifficultyEntry;
struct MapEntry;
struct Position;
struct ScriptAction;
struct ScriptInfo;
struct SmoothPhasingInfo;
struct SummonPropertiesEntry;
struct UpdateAdditionalSaveDataEvent;
struct UpdateBossStateSaveDataEvent;
class Transport;
enum Difficulty : uint8;
enum WeatherState : uint32;
enum class ItemContext : uint8;

namespace Trinity { struct ObjectUpdater; }
namespace VMAP { enum class ModelIgnoreFlags : uint32; }

enum TransferAbortReason : uint32
{
    TRANSFER_ABORT_NONE                          = 0,
    TRANSFER_ABORT_ERROR                         = 1,
    TRANSFER_ABORT_MAX_PLAYERS                   = 2,   // Transfer Aborted: instance is full
    TRANSFER_ABORT_NOT_FOUND                     = 3,   // Transfer Aborted: instance not found
    TRANSFER_ABORT_TOO_MANY_INSTANCES            = 4,   // You have entered too many instances recently.
    TRANSFER_ABORT_ZONE_IN_COMBAT                = 6,   // Unable to zone in while an encounter is in progress.
    TRANSFER_ABORT_INSUF_EXPAN_LVL               = 7,   // You must have <TBC, WotLK> expansion installed to access this area.
    TRANSFER_ABORT_DIFFICULTY                    = 8,   // <Normal, Heroic, Epic> difficulty mode is not available for %s.
    TRANSFER_ABORT_UNIQUE_MESSAGE                = 9,   // Until you've escaped TLK's grasp, you cannot leave this place!
    TRANSFER_ABORT_TOO_MANY_REALM_INSTANCES      = 10,  // Additional instances cannot be launched, please try again later.
    TRANSFER_ABORT_NEED_GROUP                    = 11,  // Transfer Aborted: you must be in a raid group to enter this instance
    TRANSFER_ABORT_NOT_FOUND_2                   = 12,  // Transfer Aborted: instance not found
    TRANSFER_ABORT_NOT_FOUND_3                   = 13,  // Transfer Aborted: instance not found
    TRANSFER_ABORT_NOT_FOUND_4                   = 14,  // Transfer Aborted: instance not found
    TRANSFER_ABORT_REALM_ONLY                    = 15,  // All players in the party must be from the same realm to enter %s.
    TRANSFER_ABORT_MAP_NOT_ALLOWED               = 16,  // Map cannot be entered at this time.
    TRANSFER_ABORT_LOCKED_TO_DIFFERENT_INSTANCE  = 18,  // You are already locked to %s
    TRANSFER_ABORT_ALREADY_COMPLETED_ENCOUNTER   = 19,  // You are ineligible to participate in at least one encounter in this instance because you are already locked to an instance in which it has been defeated.
    TRANSFER_ABORT_DIFFICULTY_NOT_FOUND          = 22,  // client writes to console "Unable to resolve requested difficultyID %u to actual difficulty for map %d"
    TRANSFER_ABORT_XREALM_ZONE_DOWN              = 24,  // Transfer Aborted: cross-realm zone is down
    TRANSFER_ABORT_SOLO_PLAYER_SWITCH_DIFFICULTY = 26,  // This instance is already in progress. You may only switch difficulties from inside the instance.
    TRANSFER_ABORT_NOT_CROSS_FACTION_COMPATIBLE  = 33,  // This instance isn't available for cross-faction groups
};

struct TransferAbortParams
{
    TransferAbortParams(TransferAbortReason reason, uint8 arg = 0, int32 mapDifficultyXConditionId = 0)
        : Reason(reason), Arg(arg), MapDifficultyXConditionId(mapDifficultyXConditionId)
    {
    }

    TransferAbortReason Reason;
    uint8 Arg;
    int32 MapDifficultyXConditionId;

    operator bool() const { return Reason != TRANSFER_ABORT_NONE; }
};

struct ScriptAction
{
    ObjectGuid sourceGUID;
    ObjectGuid targetGUID;
    ObjectGuid ownerGUID;                                   ///> owner of source if source is item
    ScriptInfo const* script;                               ///> pointer to static script data
};

struct ZoneDynamicInfo
{
    ZoneDynamicInfo();

    uint32 MusicId;

    std::unique_ptr<Weather> DefaultWeather;
    WeatherState WeatherId;
    float Intensity;

    struct LightOverride
    {
        uint32 AreaLightId;
        uint32 OverrideLightId;
        uint32 TransitionMilliseconds;
    };
    std::vector<LightOverride> LightOverrides;
};

#define MIN_UNLOAD_DELAY      1                             // immediate unload
#define MAP_INVALID_ZONE      0xFFFFFFFF

struct RespawnInfo; // forward declaration
struct CompareRespawnInfo
{
    bool operator()(RespawnInfo const* a, RespawnInfo const* b) const;
};
using ZoneDynamicInfoMap = std::unordered_map<uint32 /*zoneId*/, ZoneDynamicInfo>;
struct RespawnListContainer;
using RespawnInfoMap = std::unordered_map<ObjectGuid::LowType, RespawnInfo*>;
struct TC_GAME_API RespawnInfo
{
    virtual ~RespawnInfo();

    SpawnObjectType type;
    ObjectGuid::LowType spawnId;
    uint32 entry;
    time_t respawnTime;
    uint32 gridId;
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

extern template class TypeUnorderedMapContainer<AllMapStoredObjectTypes, ObjectGuid>;
typedef TypeUnorderedMapContainer<AllMapStoredObjectTypes, ObjectGuid> MapStoredObjectTypesContainer;

class TC_GAME_API Map : public GridRefManager<NGridType>
{
    friend class MapReference;
    public:
        Map(uint32 id, time_t, uint32 InstanceId, Difficulty SpawnMode);
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
        void LoadGridForActiveObject(float x, float y, WorldObject const* object);
        void LoadAllCells();
        bool UnloadGrid(NGridType& ngrid, bool pForce);
        void GridMarkNoUnload(uint32 x, uint32 y);
        void GridUnmarkNoUnload(uint32 x, uint32 y);
        void UnloadAll();

        void ResetGridExpiry(NGridType &grid, float factor = 1) const
        {
            grid.ResetTimeTracker(time_t(float(i_gridExpiry)*factor));
        }

        time_t GetGridExpiry() const { return i_gridExpiry; }

        static void InitStateMachine();
        static void DeleteStateMachine();

        TerrainInfo* GetTerrain() const { return m_terrain.get(); }

        // custom PathGenerator include and exclude filter flags
        // these modify what kind of terrain types are available in current instance
        // for example this can be used to mark offmesh connections as enabled/disabled
        uint16 GetForceEnabledNavMeshFilterFlags() const { return m_forceEnabledNavMeshFilterFlags; }
        void SetForceEnabledNavMeshFilterFlag(uint16 flag) { m_forceEnabledNavMeshFilterFlags |= flag; }
        void RemoveForceEnabledNavMeshFilterFlag(uint16 flag) { m_forceEnabledNavMeshFilterFlags &= ~flag; }

        uint16 GetForceDisabledNavMeshFilterFlags() const { return m_forceDisabledNavMeshFilterFlags; }
        void SetForceDisabledNavMeshFilterFlag(uint16 flag) { m_forceDisabledNavMeshFilterFlags |= flag; }
        void RemoveForceDisabledNavMeshFilterFlag(uint16 flag) { m_forceDisabledNavMeshFilterFlags &= ~flag; }

        void GetFullTerrainStatusForPosition(PhaseShift const& phaseShift, float x, float y, float z, PositionFullTerrainStatus& data, Optional<map_liquidHeaderTypeFlags> reqLiquidType = {}, float collisionHeight = 2.03128f); // DEFAULT_COLLISION_HEIGHT in Object.h
        ZLiquidStatus GetLiquidStatus(PhaseShift const& phaseShift, float x, float y, float z, Optional<map_liquidHeaderTypeFlags> ReqLiquidType = {}, LiquidData* data = nullptr, float collisionHeight = 2.03128f); // DEFAULT_COLLISION_HEIGHT in Object.h

        uint32 GetAreaId(PhaseShift const& phaseShift, float x, float y, float z);
        uint32 GetAreaId(PhaseShift const& phaseShift, Position const& pos) { return GetAreaId(phaseShift, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()); }
        uint32 GetZoneId(PhaseShift const& phaseShift, float x, float y, float z);
        uint32 GetZoneId(PhaseShift const& phaseShift, Position const& pos) { return GetZoneId(phaseShift, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()); }
        void GetZoneAndAreaId(PhaseShift const& phaseShift, uint32& zoneid, uint32& areaid, float x, float y, float z);
        void GetZoneAndAreaId(PhaseShift const& phaseShift, uint32& zoneid, uint32& areaid, Position const& pos) { GetZoneAndAreaId(phaseShift, zoneid, areaid, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()); }

        float GetMinHeight(PhaseShift const& phaseShift, float x, float y);
        float GetGridHeight(PhaseShift const& phaseShift, float x, float y);
        float GetStaticHeight(PhaseShift const& phaseShift, float x, float y, float z, bool checkVMap = true, float maxSearchDist = DEFAULT_HEIGHT_SEARCH);
        float GetStaticHeight(PhaseShift const& phaseShift, Position const& pos, bool checkVMap = true, float maxSearchDist = DEFAULT_HEIGHT_SEARCH) { return GetStaticHeight(phaseShift, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), checkVMap, maxSearchDist); }
        float GetHeight(PhaseShift const& phaseShift, float x, float y, float z, bool vmap = true, float maxSearchDist = DEFAULT_HEIGHT_SEARCH) { return std::max<float>(GetStaticHeight(phaseShift, x, y, z, vmap, maxSearchDist), GetGameObjectFloor(phaseShift, x, y, z, maxSearchDist)); }
        float GetHeight(PhaseShift const& phaseShift, Position const& pos, bool vmap = true, float maxSearchDist = DEFAULT_HEIGHT_SEARCH) { return GetHeight(phaseShift, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), vmap, maxSearchDist); }

        float GetWaterLevel(PhaseShift const& phaseShift, float x, float y);
        bool IsInWater(PhaseShift const& phaseShift, float x, float y, float z, LiquidData* data = nullptr);
        bool IsUnderWater(PhaseShift const& phaseShift, float x, float y, float z);

        float GetWaterOrGroundLevel(PhaseShift const& phaseShift, float x, float y, float z, float* ground = nullptr, bool swim = false, float collisionHeight = 2.03128f); // DEFAULT_COLLISION_HEIGHT in Object.h

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

        static TransferAbortParams PlayerCannotEnter(uint32 mapid, Player* player);
        virtual TransferAbortParams CannotEnter(Player* /*player*/) { return { TRANSFER_ABORT_NONE }; }
        char const* GetMapName() const;

        // have meaning only for instanced map (that have set real difficulty)
        Difficulty GetDifficultyID() const { return Difficulty(i_spawnMode); }
        MapDifficultyEntry const* GetMapDifficulty() const;

        uint32 GetId() const;
        bool Instanceable() const;
        bool IsDungeon() const;
        bool IsNonRaidDungeon() const;
        bool IsRaid() const;
        bool IsLFR() const;
        bool IsNormal() const;
        bool IsHeroic() const;
        bool IsMythic() const;
        bool IsMythicPlus() const;
        bool IsHeroicOrHigher() const;
        bool Is25ManRaid() const;
        bool IsTimewalking() const;
        bool IsBattleground() const;
        bool IsBattleArena() const;
        bool IsBattlegroundOrArena() const;
        bool IsScenario() const;
        bool IsGarrison() const;
        // Currently, this means that every entity added to this map will be marked as active
        bool IsAlwaysActive() const;
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

        template <typename T>
        void DoOnPlayers(T&& fn)
        {
            for (MapReference const& ref : GetPlayers())
                if (Player* player = ref.GetSource())
                    fn(player);
        }

        //per-map script storage
        void ScriptsStart(std::map<uint32, std::multimap<uint32, ScriptInfo>> const& scripts, uint32 id, Object* source, Object* target);
        void ScriptCommandStart(ScriptInfo const& script, uint32 delay, Object* source, Object* target);

        // must called with AddToWorld
        void AddToActive(WorldObject* obj);

        // must called with RemoveFromWorld
        void RemoveFromActive(WorldObject* obj);

        template<class T> void SwitchGridContainers(T* obj, bool on);
        std::unordered_map<ObjectGuid::LowType /*leaderSpawnId*/, CreatureGroup*> CreatureGroupHolder;

        void UpdateIteratorBack(Player* player);

        TempSummon* SummonCreature(uint32 entry, Position const& pos, SummonPropertiesEntry const* properties = nullptr, Milliseconds duration = 0ms, WorldObject* summoner = nullptr, uint32 spellId = 0, uint32 vehId = 0, ObjectGuid privateObjectOwner = ObjectGuid::Empty, SmoothPhasingInfo const* smoothPhasingInfo = nullptr);
        void SummonCreatureGroup(uint8 group, std::list<TempSummon*>* list = nullptr);
        AreaTrigger* GetAreaTrigger(ObjectGuid const& guid);
        SceneObject* GetSceneObject(ObjectGuid const& guid);
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
        AreaTrigger* GetAreaTriggerBySpawnId(ObjectGuid::LowType spawnId) const;
        WorldObject* GetWorldObjectBySpawnId(SpawnObjectType type, ObjectGuid::LowType spawnId) const
        {
            switch (type)
            {
                case SPAWN_TYPE_CREATURE:
                    return reinterpret_cast<WorldObject*>(GetCreatureBySpawnId(spawnId));
                case SPAWN_TYPE_GAMEOBJECT:
                    return reinterpret_cast<WorldObject*>(GetGameObjectBySpawnId(spawnId));
                case SPAWN_TYPE_AREATRIGGER:
                    return reinterpret_cast<WorldObject*>(GetAreaTriggerBySpawnId(spawnId));
                default:
                    return nullptr;
            }
        }

        MapStoredObjectTypesContainer& GetObjectsStore() { return _objectsStore; }

        typedef std::unordered_multimap<ObjectGuid::LowType, Creature*> CreatureBySpawnIdContainer;
        CreatureBySpawnIdContainer& GetCreatureBySpawnIdStore() { return _creatureBySpawnIdStore; }
        CreatureBySpawnIdContainer const& GetCreatureBySpawnIdStore() const { return _creatureBySpawnIdStore; }

        typedef std::unordered_multimap<ObjectGuid::LowType, GameObject*> GameObjectBySpawnIdContainer;
        GameObjectBySpawnIdContainer& GetGameObjectBySpawnIdStore() { return _gameobjectBySpawnIdStore; }
        GameObjectBySpawnIdContainer const& GetGameObjectBySpawnIdStore() const { return _gameobjectBySpawnIdStore; }

        typedef std::unordered_multimap<ObjectGuid::LowType, AreaTrigger*> AreaTriggerBySpawnIdContainer;
        AreaTriggerBySpawnIdContainer& GetAreaTriggerBySpawnIdStore() { return _areaTriggerBySpawnIdStore; }
        AreaTriggerBySpawnIdContainer const& GetAreaTriggerBySpawnIdStore() const { return _areaTriggerBySpawnIdStore; }

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

        InstanceMap* ToInstanceMap() { if (IsDungeon()) return reinterpret_cast<InstanceMap*>(this); else return nullptr;  }
        InstanceMap const* ToInstanceMap() const { if (IsDungeon()) return reinterpret_cast<InstanceMap const*>(this); return nullptr; }

        BattlegroundMap* ToBattlegroundMap() { if (IsBattlegroundOrArena()) return reinterpret_cast<BattlegroundMap*>(this); else return nullptr;  }
        BattlegroundMap const* ToBattlegroundMap() const { if (IsBattlegroundOrArena()) return reinterpret_cast<BattlegroundMap const*>(this); return nullptr; }

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
        time_t GetRespawnTime(SpawnObjectType type, ObjectGuid::LowType spawnId) const
        {
            if (auto map = GetRespawnMapForType(type))
            {
                auto it = map->find(spawnId);
                return (it == map->end()) ? 0 : it->second->respawnTime;
            }
            return 0;
        }
        time_t GetCreatureRespawnTime(ObjectGuid::LowType spawnId) const { return GetRespawnTime(SPAWN_TYPE_CREATURE, spawnId); }
        time_t GetGORespawnTime(ObjectGuid::LowType spawnId) const { return GetRespawnTime(SPAWN_TYPE_GAMEOBJECT, spawnId); }

        void UpdatePlayerZoneStats(uint32 oldZone, uint32 newZone);

        void SaveRespawnTime(SpawnObjectType type, ObjectGuid::LowType spawnId, uint32 entry, time_t respawnTime, uint32 gridId, CharacterDatabaseTransaction dbTrans = nullptr, bool startup = false);
        void SaveRespawnInfoDB(RespawnInfo const& info, CharacterDatabaseTransaction dbTrans = nullptr);
        void LoadRespawnTimes();
        void DeleteRespawnTimes() { UnloadAllRespawnInfos(); DeleteRespawnTimesInDB(); }
        void DeleteRespawnTimesInDB();

        void LoadCorpseData();
        void DeleteCorpseData();
        void AddCorpse(Corpse* corpse);
        void RemoveCorpse(Corpse* corpse);
        Corpse* ConvertCorpseToBones(ObjectGuid const& ownerGuid, bool insignia = false);
        void RemoveOldCorpses();

        void SendInitTransports(Player* player);
        void SendRemoveTransports(Player* player);
        void SendUpdateTransportVisibility(Player* player);
        void SendZoneDynamicInfo(uint32 zoneId, Player* player) const;
        void SendZoneWeather(uint32 zoneId, Player* player) const;
        void SendZoneWeather(ZoneDynamicInfo const& zoneDynamicInfo, Player* player) const;

        void SetZoneMusic(uint32 zoneId, uint32 musicId);
        Weather* GetOrGenerateZoneDefaultWeather(uint32 zoneId);
        WeatherState GetZoneWeather(uint32 zoneId) const;
        void SetZoneWeather(uint32 zoneId, WeatherState weatherId, float intensity);
        void SetZoneOverrideLight(uint32 zoneId, uint32 areaLightId, uint32 overrideLightId, Milliseconds transitionTime);

        void UpdateAreaDependentAuras();

        template<HighGuid high>
        inline ObjectGuid::LowType GenerateLowGuid()
        {
            static_assert(ObjectGuidTraits<high>::SequenceSource.HasFlag(ObjectGuidSequenceSource::Map), "Only map specific guid can be generated in Map context");
            return GetGuidSequenceGenerator(high).Generate();
        }

        template<HighGuid high>
        inline ObjectGuid::LowType GetMaxLowGuid()
        {
            static_assert(ObjectGuidTraits<high>::SequenceSource.HasFlag(ObjectGuidSequenceSource::Map), "Only map specific guid can be retrieved in Map context");
            return GetGuidSequenceGenerator(high).GetNextAfterMaxUsed();
        }

        void AddUpdateObject(Object* obj)
        {
            _updateObjects.insert(obj);
        }

        void RemoveUpdateObject(Object* obj)
        {
            _updateObjects.erase(obj);
        }

        size_t GetActiveNonPlayersCount() const
        {
            return m_activeNonPlayers.size();
        }

        virtual std::string GetDebugInfo() const;

    private:

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
        bool EnsureGridLoaded(Cell const&);
        void EnsureGridLoadedForActiveObject(Cell const&, WorldObject const* object);

        void buildNGridLinkage(NGridType* pNGridType) { pNGridType->link(this); }

        NGridType* getNGrid(uint32 x, uint32 y) const
        {
            ASSERT(x < MAX_NUMBER_OF_GRIDS && y < MAX_NUMBER_OF_GRIDS, "x = %u, y = %u", x, y);
            return i_grids[x][y];
        }

        bool isGridObjectDataLoaded(uint32 x, uint32 y) const { return getNGrid(x, y)->isGridObjectDataLoaded(); }
        void setGridObjectDataLoaded(bool pLoaded, uint32 x, uint32 y) { getNGrid(x, y)->setGridObjectDataLoaded(pLoaded); }

        void setNGrid(NGridType* grid, uint32 x, uint32 y);
        void ScriptsProcess();

        void SendObjectUpdates();

    protected:
        virtual void LoadGridObjects(NGridType* grid, Cell const& cell);

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
        GameObject* _GetScriptGameObjectSourceOrTarget(Object* source, Object* target, ScriptInfo const* scriptInfo, bool bReverse = false) const;
        Unit* _GetScriptUnit(Object* obj, bool isSource, ScriptInfo const* scriptInfo) const;
        Player* _GetScriptPlayer(Object* obj, bool isSource, ScriptInfo const* scriptInfo) const;
        Creature* _GetScriptCreature(Object* obj, bool isSource, ScriptInfo const* scriptInfo) const;
        WorldObject* _GetScriptWorldObject(Object* obj, bool isSource, ScriptInfo const* scriptInfo) const;
        void _ScriptProcessDoor(Object* source, Object* target, ScriptInfo const* scriptInfo) const;
        GameObject* _FindGameObject(WorldObject* pWorldObject, ObjectGuid::LowType guid) const;

        time_t i_gridExpiry;

        std::shared_ptr<TerrainInfo> m_terrain;
        uint16 m_forceEnabledNavMeshFilterFlags;
        uint16 m_forceDisabledNavMeshFilterFlags;

        NGridType* i_grids[MAX_NUMBER_OF_GRIDS][MAX_NUMBER_OF_GRIDS];
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
        bool AddRespawnInfo(RespawnInfo const& info);
        void UnloadAllRespawnInfos();
        RespawnInfo* GetRespawnInfo(SpawnObjectType type, ObjectGuid::LowType spawnId) const;
        void Respawn(RespawnInfo* info, CharacterDatabaseTransaction dbTrans = nullptr);
        void DeleteRespawnInfo(RespawnInfo* info, CharacterDatabaseTransaction dbTrans = nullptr);
        void DeleteRespawnInfoFromDB(SpawnObjectType type, ObjectGuid::LowType spawnId, CharacterDatabaseTransaction dbTrans = nullptr);

    public:
        void GetRespawnInfo(std::vector<RespawnInfo const*>& respawnData, SpawnObjectTypeMask types) const;
        void Respawn(SpawnObjectType type, ObjectGuid::LowType spawnId, CharacterDatabaseTransaction dbTrans = nullptr)
        {
            if (RespawnInfo* info = GetRespawnInfo(type, spawnId))
                Respawn(info, dbTrans);
        }
        void RemoveRespawnTime(SpawnObjectType type, ObjectGuid::LowType spawnId, CharacterDatabaseTransaction dbTrans = nullptr, bool alwaysDeleteFromDB = false)
        {
            if (RespawnInfo* info = GetRespawnInfo(type, spawnId))
                DeleteRespawnInfo(info, dbTrans);
            // Some callers might need to make sure the database doesn't contain any respawn time
            else if (alwaysDeleteFromDB)
                DeleteRespawnInfoFromDB(type, spawnId, dbTrans);
        }
        size_t DespawnAll(SpawnObjectType type, ObjectGuid::LowType spawnId);

        bool ShouldBeSpawnedOnGridLoad(SpawnObjectType type, ObjectGuid::LowType spawnId) const;
        template <typename T> bool ShouldBeSpawnedOnGridLoad(ObjectGuid::LowType spawnId) const { return ShouldBeSpawnedOnGridLoad(SpawnData::TypeFor<T>, spawnId); }

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

        SpawnedPoolData& GetPoolData() { return *_poolData; }
        SpawnedPoolData const& GetPoolData() const { return *_poolData; }

        typedef std::function<void(Map*)> FarSpellCallback;
        void AddFarSpellCallback(FarSpellCallback&& callback);

        void InitSpawnGroupState();
        void UpdateSpawnGroupConditions();

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

        std::unique_ptr<RespawnListContainer> _respawnTimes;
        RespawnInfoMap       _creatureRespawnTimesBySpawnId;
        RespawnInfoMap       _gameObjectRespawnTimesBySpawnId;
        RespawnInfoMap* GetRespawnMapForType(SpawnObjectType type)
        {
            switch (type)
            {
                default:
                    ABORT();
                case SPAWN_TYPE_CREATURE:
                    return &_creatureRespawnTimesBySpawnId;
                case SPAWN_TYPE_GAMEOBJECT:
                    return &_gameObjectRespawnTimesBySpawnId;
                case SPAWN_TYPE_AREATRIGGER:
                    return nullptr;
            }
        }
        RespawnInfoMap const* GetRespawnMapForType(SpawnObjectType type) const
        {
            switch (type)
            {
                default:
                    ABORT();
                case SPAWN_TYPE_CREATURE:
                    return &_creatureRespawnTimesBySpawnId;
                case SPAWN_TYPE_GAMEOBJECT:
                    return &_gameObjectRespawnTimesBySpawnId;
                case SPAWN_TYPE_AREATRIGGER:
                    return nullptr;
            }
        }

        void SetSpawnGroupActive(uint32 groupId, bool state);
        std::unordered_set<uint32> _toggledSpawnGroupIds;

        uint32 _respawnCheckTimer;
        std::unordered_map<uint32, uint32> _zonePlayerCountMap;

        ZoneDynamicInfoMap _zoneDynamicInfo;
        IntervalTimer _weatherUpdateTimer;

        ObjectGuidGenerator& GetGuidSequenceGenerator(HighGuid high);

        std::map<HighGuid, std::unique_ptr<ObjectGuidGenerator>> _guidGenerators;
        std::unique_ptr<SpawnedPoolData> _poolData;
        MapStoredObjectTypesContainer _objectsStore;
        CreatureBySpawnIdContainer _creatureBySpawnIdStore;
        GameObjectBySpawnIdContainer _gameobjectBySpawnIdStore;
        AreaTriggerBySpawnIdContainer _areaTriggerBySpawnIdStore;
        std::unordered_map<uint32/*cellId*/, std::unordered_set<Corpse*>> _corpsesByCell;
        std::unordered_map<ObjectGuid, Corpse*> _corpsesByPlayer;
        std::unordered_set<Corpse*> _corpseBones;

        std::unordered_set<Object*> _updateObjects;

        MPSCQueue<FarSpellCallback> _farSpellCallbacks;

        /*********************************************************/
        /***                   Phasing                         ***/
        /*********************************************************/
    public:
        MultiPersonalPhaseTracker& GetMultiPersonalPhaseTracker() { return _multiPersonalPhaseTracker; }
        void UpdatePersonalPhasesForPlayer(Player const* player);

    private:
        MultiPersonalPhaseTracker _multiPersonalPhaseTracker;

        /*********************************************************/
        /***                   WorldStates                     ***/
        /*********************************************************/
    public:
        int32 GetWorldStateValue(int32 worldStateId) const;
        void SetWorldStateValue(int32 worldStateId, int32 value, bool hidden);
        WorldStateValueContainer const& GetWorldStateValues() const { return _worldStateValues; }

    private:
        WorldStateValueContainer _worldStateValues;
};

enum class InstanceResetMethod : uint8
{
    Manual,
    OnChangeDifficulty,
    Expire
};

enum class InstanceResetResult : uint8
{
    Success,
    NotEmpty,
    CannotReset
};

class TC_GAME_API InstanceMap : public Map
{
    public:
        InstanceMap(uint32 id, time_t, uint32 InstanceId, Difficulty SpawnMode, TeamId InstanceTeam, InstanceLock* instanceLock);
        ~InstanceMap();
        bool AddPlayerToMap(Player* player, bool initPlayer = true) override;
        void RemovePlayerFromMap(Player*, bool) override;
        void Update(uint32) override;
        void CreateInstanceData();
        InstanceResetResult Reset(InstanceResetMethod method);
        uint32 GetScriptId() const { return i_script_id; }
        std::string const& GetScriptName() const;
        InstanceScript* GetInstanceScript() { return i_data; }
        InstanceScript const* GetInstanceScript() const { return i_data; }
        InstanceScenario* GetInstanceScenario() { return i_scenario; }
        InstanceScenario const* GetInstanceScenario() const { return i_scenario; }
        void SetInstanceScenario(InstanceScenario* scenario) { i_scenario = scenario; }
        InstanceLock const* GetInstanceLock() const { return i_instanceLock; }
        void UpdateInstanceLock(UpdateBossStateSaveDataEvent const& updateSaveDataEvent);
        void UpdateInstanceLock(UpdateAdditionalSaveDataEvent const& updateSaveDataEvent);
        void CreateInstanceLockForPlayer(Player* player);
        TransferAbortParams CannotEnter(Player* player) override;

        uint32 GetMaxPlayers() const;
        TeamId GetTeamIdInInstance() const;
        Team GetTeamInInstance() const { return GetTeamIdInInstance() == TEAM_ALLIANCE ? ALLIANCE : HORDE; }

        virtual void InitVisibilityDistance() override;

        Group* GetOwningGroup() const { return i_owningGroupRef.getTarget(); }
        void TrySetOwningGroup(Group* group);

        std::string GetDebugInfo() const override;
    private:
        Optional<SystemTimePoint> i_instanceExpireEvent;
        InstanceScript* i_data;
        uint32 i_script_id;
        InstanceScenario* i_scenario;
        InstanceLock* i_instanceLock;
        GroupInstanceReference i_owningGroupRef;
};

class TC_GAME_API BattlegroundMap : public Map
{
    public:
        BattlegroundMap(uint32 id, time_t, uint32 InstanceId, Difficulty spawnMode);
        ~BattlegroundMap();

        bool AddPlayerToMap(Player* player, bool initPlayer = true) override;
        void RemovePlayerFromMap(Player*, bool) override;
        TransferAbortParams CannotEnter(Player* player) override;
        void SetUnload();
        //void UnloadAll(bool pForce);
        void RemoveAllPlayers() override;

        virtual void InitVisibilityDistance() override;
        Battleground* GetBG() const { return m_bg; }
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
