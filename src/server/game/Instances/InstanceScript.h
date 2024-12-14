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

#ifndef TRINITY_INSTANCE_DATA_H
#define TRINITY_INSTANCE_DATA_H

#include "ZoneScript.h"
#include "Common.h"
#include "Duration.h"
#include "Optional.h"
#include <array>
#include <map>
#include <set>
#include <variant>

#ifdef TRINITY_API_USE_DYNAMIC_LINKING
#include <memory>
#endif

#define OUT_SAVE_INST_DATA             TC_LOG_DEBUG("scripts", "Saving Instance Data for Instance {} (Map {}, Instance Id {})", instance->GetMapName(), instance->GetId(), instance->GetInstanceId())
#define OUT_SAVE_INST_DATA_COMPLETE    TC_LOG_DEBUG("scripts", "Saving Instance Data for Instance {} (Map {}, Instance Id {}) completed.", instance->GetMapName(), instance->GetId(), instance->GetInstanceId())
#define OUT_LOAD_INST_DATA(a)          TC_LOG_DEBUG("scripts", "Loading Instance Data for Instance {} (Map {}, Instance Id {}). Input is '{}'", instance->GetMapName(), instance->GetId(), instance->GetInstanceId(), a)
#define OUT_LOAD_INST_DATA_COMPLETE    TC_LOG_DEBUG("scripts", "Instance Data Load for Instance {} (Map {}, Instance Id: {}) is complete.", instance->GetMapName(), instance->GetId(), instance->GetInstanceId())
#define OUT_LOAD_INST_DATA_FAIL        TC_LOG_ERROR("scripts", "Unable to load Instance Data for Instance {} (Map {}, Instance Id: {}).", instance->GetMapName(), instance->GetId(), instance->GetInstanceId())

class AreaBoundary;
class Creature;
class GameObject;
class InstanceMap;
class ModuleReference;
class PersistentInstanceScriptValueBase;
class Player;
class Unit;
struct DungeonEncounterEntry;
struct InstanceSpawnGroupInfo;
enum class CriteriaType : int16;
enum class CriteriaStartEvent : uint8;
enum Difficulty : uint8;

enum EncounterFrameType
{
    ENCOUNTER_FRAME_ENGAGE              = 0,
    ENCOUNTER_FRAME_DISENGAGE           = 1,
    ENCOUNTER_FRAME_UPDATE_PRIORITY     = 2,
    ENCOUNTER_FRAME_ADD_TIMER           = 3,
    ENCOUNTER_FRAME_ENABLE_OBJECTIVE    = 4,
    ENCOUNTER_FRAME_UPDATE_OBJECTIVE    = 5,
    ENCOUNTER_FRAME_DISABLE_OBJECTIVE   = 6,
    ENCOUNTER_FRAME_PHASE_SHIFT_CHANGED = 7
};

// EnumUtils: DESCRIBE THIS
enum EncounterState
{
    NOT_STARTED   = 0,
    IN_PROGRESS   = 1,
    FAIL          = 2,
    DONE          = 3,
    SPECIAL       = 4,
    TO_BE_DECIDED = 5
};

enum class EncounterDoorBehavior : uint8
{
    OpenWhenNotInProgress   = 0, // open if encounter is not in progress
    OpenWhenDone            = 1, // open if encounter is done
    OpenWhenInProgress      = 2, // open if encounter is in progress, typically used for spawning places
    OpenWhenNotDone         = 3, // open if encounter is not done
    Max
};

static constexpr uint32 MAX_DUNGEON_ENCOUNTERS_PER_BOSS = 4;

struct DungeonEncounterData
{
    uint32 BossId;
    std::array<uint32, MAX_DUNGEON_ENCOUNTERS_PER_BOSS> DungeonEncounterId;
};

struct DoorData
{
    uint32 entry, bossId;
    EncounterDoorBehavior Behavior;
};

struct BossBoundaryEntry
{
    uint32 BossId;
    AreaBoundary const* Boundary;
};

struct TC_GAME_API BossBoundaryData
{
    typedef std::vector<BossBoundaryEntry> StorageType;
    typedef StorageType::const_iterator const_iterator;

    BossBoundaryData(std::initializer_list<BossBoundaryEntry> data) : _data(data) { }
    ~BossBoundaryData();
    const_iterator begin() const { return _data.begin(); }
    const_iterator end() const { return _data.end(); }

    private:
        StorageType _data;
};

struct MinionData
{
    uint32 entry, bossId;
};

struct ObjectData
{
    uint32 entry;
    uint32 type;
};

typedef std::vector<AreaBoundary const*> CreatureBoundary;

struct BossInfo
{
    BossInfo() : state(TO_BE_DECIDED) { DungeonEncounters.fill(nullptr); }

    DungeonEncounterEntry const* GetDungeonEncounterForDifficulty(Difficulty difficulty) const;

    EncounterState state;
    std::array<GuidSet, static_cast<uint8>(EncounterDoorBehavior::Max)> door;
    GuidSet minion;
    CreatureBoundary boundary;
    std::array<DungeonEncounterEntry const*, MAX_DUNGEON_ENCOUNTERS_PER_BOSS> DungeonEncounters;
};

struct DoorInfo
{
    explicit DoorInfo(BossInfo* _bossInfo, EncounterDoorBehavior _behavior)
        : bossInfo(_bossInfo), Behavior(_behavior) { }
    BossInfo* bossInfo;
    EncounterDoorBehavior Behavior;
};

struct MinionInfo
{
    explicit MinionInfo(BossInfo* _bossInfo) : bossInfo(_bossInfo) { }
    BossInfo* bossInfo;
};

struct UpdateBossStateSaveDataEvent
{
    DungeonEncounterEntry const* DungeonEncounter;
    uint32 BossId;
    EncounterState NewState;
};

struct UpdateAdditionalSaveDataEvent
{
    explicit UpdateAdditionalSaveDataEvent(char const* key, std::variant<int64, double> value) : Key(key), Value(value) { }

    char const* Key;
    std::variant<int64, double> Value;
};

typedef std::multimap<uint32 /*entry*/, DoorInfo> DoorInfoMap;
typedef std::pair<DoorInfoMap::const_iterator, DoorInfoMap::const_iterator> DoorInfoMapBounds;

typedef std::map<uint32 /*entry*/, MinionInfo> MinionInfoMap;
typedef std::map<uint32 /*type*/, ObjectGuid /*guid*/> ObjectGuidMap;
typedef std::map<uint32 /*entry*/, uint32 /*type*/> ObjectInfoMap;

class TC_GAME_API InstanceScript : public ZoneScript
{
    public:
        explicit InstanceScript(InstanceMap* map);
        InstanceScript(InstanceScript const& right) = delete;
        InstanceScript(InstanceScript&& right) = delete;
        InstanceScript& operator=(InstanceScript const& right) = delete;
        InstanceScript& operator=(InstanceScript&& right) = delete;
        virtual ~InstanceScript();

        InstanceMap* instance;

        // On instance load, exactly ONE of these methods will ALWAYS be called:
        // if we're starting without any saved instance data
        virtual void Create();
        // if we're loading existing instance save data
        void Load(char const* data);

        // When save is needed, this function generates the data
        std::string GetSaveData();

        std::string UpdateBossStateSaveData(std::string const& oldData, UpdateBossStateSaveDataEvent const& event);
        std::string UpdateAdditionalSaveData(std::string const& oldData, UpdateAdditionalSaveDataEvent const& event);
        Optional<uint32> GetEntranceLocationForCompletedEncounters(uint32 completedEncountersMask) const;
        virtual Optional<uint32> ComputeEntranceLocationForCompletedEncounters(uint32 completedEncountersMask) const;

        virtual void Update(uint32 /*diff*/) { }
        void UpdateCombatResurrection(uint32 diff);

        // Used by the map's CannotEnter function.
        // This is to prevent players from entering during boss encounters.
        virtual bool IsEncounterInProgress() const;

        // Called when a creature/gameobject is added to map or removed from map.
        // Insert/Remove objectguid to dynamic guid store
        virtual void OnCreatureCreate(Creature* creature) override;
        virtual void OnCreatureRemove(Creature* creature) override;

        virtual void OnGameObjectCreate(GameObject* go) override;
        virtual void OnGameObjectRemove(GameObject* go) override;

        ObjectGuid GetObjectGuid(uint32 type) const;
        virtual ObjectGuid GetGuidData(uint32 type) const override;

        // Triggers a GameEvent
        // * If source is nullptr then event is triggered for each player in the instance as "source"
        void TriggerGameEvent(uint32 gameEventId, WorldObject* source = nullptr, WorldObject* target = nullptr) override;

        Creature* GetCreature(uint32 type);
        GameObject* GetGameObject(uint32 type);

        // Called when a player successfully enters the instance.
        virtual void OnPlayerEnter(Player* /*player*/) { }
        // Called when a player successfully leaves the instance.
        virtual void OnPlayerLeave(Player* /*player*/) { }

        // Handle open / close objects
        // * use HandleGameObject(0, boolen, GO); in OnObjectCreate in instance scripts
        // * use HandleGameObject(GUID, boolen, nullptr); in any other script
        void HandleGameObject(ObjectGuid guid, bool open, GameObject* go = nullptr);

        // Change active state of doors or buttons
        void DoUseDoorOrButton(ObjectGuid guid, uint32 withRestoreTime = 0, bool useAlternativeState = false);
        void DoCloseDoorOrButton(ObjectGuid guid);

        // Respawns a GO having negative spawntimesecs in gameobject-table
        void DoRespawnGameObject(ObjectGuid guid, Seconds timeToDespawn = 1min);

        // Sends world state update to all players in instance
        void DoUpdateWorldState(int32 worldStateId, int32 value);

        // Send Notify to all players in instance
        void DoSendNotifyToInstance(char const* format, ...);

        // Update Achievement Criteria for all players in instance
        void DoUpdateCriteria(CriteriaType type, uint32 miscValue1 = 0, uint32 miscValue2 = 0, Unit* unit = nullptr);

        // Remove Auras due to Spell on all players in instance
        void DoRemoveAurasDueToSpellOnPlayers(uint32 spell, bool includePets = false, bool includeControlled = false);
        void DoRemoveAurasDueToSpellOnPlayer(Player* player, uint32 spell, bool includePets = false, bool includeControlled = false);

        // Cast spell on all players in instance
        void DoCastSpellOnPlayers(uint32 spell, bool includePets = false, bool includeControlled = false);
        void DoCastSpellOnPlayer(Player* player, uint32 spell, bool includePets = false, bool includeControlled = false);

        // Return wether server allow two side groups or not
        static bool ServerAllowsTwoSideGroups();

        virtual bool SetBossState(uint32 id, EncounterState state);
        EncounterState GetBossState(uint32 id) const { return id < bosses.size() ? bosses[id].state : TO_BE_DECIDED; }
        static char const* GetBossStateName(uint8 state);
        CreatureBoundary const* GetBossBoundary(uint32 id) const { return id < bosses.size() ? &bosses[id].boundary : nullptr; }
        DungeonEncounterEntry const* GetBossDungeonEncounter(uint32 id) const;
        DungeonEncounterEntry const* GetBossDungeonEncounter(Creature const* creature) const;

        // Achievement criteria additional requirements check
        // NOTE: not use this if same can be checked existed requirement types from AchievementCriteriaRequirementType
        virtual bool CheckAchievementCriteriaMeet(uint32 /*criteria_id*/, Player const* /*source*/, Unit const* /*target*/ = nullptr, uint32 /*miscvalue1*/ = 0);

        // Checks boss requirements (one boss required to kill other)
        virtual bool CheckRequiredBosses(uint32 /*bossId*/, Player const* /*player*/ = nullptr) const { return true; }

        bool IsEncounterCompleted(uint32 dungeonEncounterId) const;
        bool IsEncounterCompletedInMaskByBossId(uint32 completedEncountersMask, uint32 bossId) const;

        uint32 GetEncounterCount() const { return uint32(bosses.size()); }

        // Sets the entrance location (WorldSafeLoc) id
        void SetEntranceLocation(uint32 worldSafeLocationId);

        // Sets a temporary entrance that does not get saved to db
        void SetTemporaryEntranceLocation(uint32 worldSafeLocationId) { _temporaryEntranceId = worldSafeLocationId; }

        // Get's the current entrance id
        uint32 GetEntranceLocation() const { return _temporaryEntranceId ? _temporaryEntranceId : _entranceId; }

        // Only used by areatriggers that inherit from OnlyOnceAreaTriggerScript
        void MarkAreaTriggerDone(uint32 id) { _activatedAreaTriggers.insert(id); }
        void ResetAreaTriggerDone(uint32 id) { _activatedAreaTriggers.erase(id); }
        bool IsAreaTriggerDone(uint32 id) const { return _activatedAreaTriggers.find(id) != _activatedAreaTriggers.end(); }

        void SendEncounterUnit(EncounterFrameType type, Unit const* unit, Optional<int32> param1 = {}, Optional<int32> param2 = {});
        void SendEncounterStart(uint32 inCombatResCount = 0, uint32 maxInCombatResCount = 0, uint32 inCombatResChargeRecovery = 0, uint32 nextCombatResChargeTime = 0);
        void SendEncounterEnd();

        void SendBossKillCredit(uint32 encounterId);

        // ReCheck PhaseTemplate related conditions
        void UpdatePhasing();

        void InitializeCombatResurrections(uint8 charges = 1, uint32 interval = 0);
        void AddCombatResurrectionCharge();
        void UseCombatResurrection();
        void ResetCombatResurrections();
        uint8 GetCombatResurrectionCharges() const { return _combatResurrectionCharges; }
        uint32 GetCombatResurrectionChargeInterval() const;

        void RegisterPersistentScriptValue(PersistentInstanceScriptValueBase* value) { _persistentScriptValues.push_back(value); }
        std::string const& GetHeader() const { return headers; }
        std::vector<PersistentInstanceScriptValueBase*>& GetPersistentScriptValues() { return _persistentScriptValues; }

    protected:
        void SetHeaders(std::string const& dataHeaders);
        void SetBossNumber(uint32 number) { bosses.resize(number); }
        void LoadBossBoundaries(BossBoundaryData const& data);
        void LoadDoorData(DoorData const* data);
        void LoadMinionData(MinionData const* data);
        void LoadObjectData(ObjectData const* creatureData, ObjectData const* gameObjectData);
        template<typename T>
        void LoadDungeonEncounterData(T const& encounters)
        {
            for (DungeonEncounterData const& encounter : encounters)
                LoadDungeonEncounterData(encounter.BossId, encounter.DungeonEncounterId);
        }

        void AddObject(Creature* obj, bool add);
        void AddObject(GameObject* obj, bool add);
        void AddObject(WorldObject* obj, uint32 type, bool add);

        virtual void AddDoor(GameObject* door, bool add);
        void AddMinion(Creature* minion, bool add);

        virtual void UpdateDoorState(GameObject* door);
        void UpdateMinionState(Creature* minion, EncounterState state);

        void UpdateSpawnGroups();

        // Exposes private data that should never be modified unless exceptional cases.
        // Pay very much attention at how the returned BossInfo data is modified to avoid issues.
        BossInfo* GetBossInfo(uint32 id);

        // Override this function to validate all additional data loads
        virtual void AfterDataLoad() { }

        bool _SkipCheckRequiredBosses(Player const* player = nullptr) const;

    private:
        static void LoadObjectData(ObjectData const* creatureData, ObjectInfoMap& objectInfo);
        void LoadDungeonEncounterData(uint32 bossId, std::array<uint32, MAX_DUNGEON_ENCOUNTERS_PER_BOSS> const& dungeonEncounterIds);
        void UpdateLfgEncounterState(BossInfo const* bossInfo);

        std::string headers;
        std::vector<BossInfo> bosses;
        std::vector<PersistentInstanceScriptValueBase*> _persistentScriptValues;
        DoorInfoMap doors;
        MinionInfoMap minions;
        ObjectInfoMap _creatureInfo;
        ObjectInfoMap _gameObjectInfo;
        ObjectGuidMap _objectGuids;
        std::vector<InstanceSpawnGroupInfo> const* const _instanceSpawnGroups;
        std::unordered_set<uint32> _activatedAreaTriggers;
        uint32 _entranceId;
        uint32 _temporaryEntranceId;
        uint32 _combatResurrectionTimer;
        uint8 _combatResurrectionCharges; // the counter for available battle resurrections
        bool _combatResurrectionTimerStarted;

    #ifdef TRINITY_API_USE_DYNAMIC_LINKING
        // Strong reference to the associated script module
        std::shared_ptr<ModuleReference> module_reference;
    #endif // #ifndef TRINITY_API_USE_DYNAMIC_LINKING

        friend class debug_commandscript;
};

class TC_GAME_API PersistentInstanceScriptValueBase
{
protected:
    PersistentInstanceScriptValueBase(InstanceScript& instance, char const* name, std::variant<int64, double> value);

public:
    virtual ~PersistentInstanceScriptValueBase();

    char const* GetName() const { return _name; }

    UpdateAdditionalSaveDataEvent CreateEvent() const
    {
        return UpdateAdditionalSaveDataEvent(_name, _value);
    }

    void LoadValue(int64 value)
    {
        _value.emplace<int64>(value);
    }

    void LoadValue(double value)
    {
        _value.emplace<double>(value);
    }

protected:
    void NotifyValueChanged();

    InstanceScript& _instance;
    char const* _name;
    std::variant<int64, double> _value;
};

template<typename T>
class PersistentInstanceScriptValue : public PersistentInstanceScriptValueBase
{
public:
    PersistentInstanceScriptValue(InstanceScript& instance, char const* name, T value = {})
        : PersistentInstanceScriptValueBase(instance, name, WrapValue(value))
    {
    }

    operator T() const
    {
        return std::visit([](auto v) { return static_cast<T>(v); }, _value);
    }

    PersistentInstanceScriptValue& operator=(T value)
    {
        _value = WrapValue(value);
        NotifyValueChanged();
        return *this;
    }

    void LoadValue(T value)
    {
        _value = WrapValue(value);
    }

private:
    static std::variant<int64, double> WrapValue(T value)
    {
        if constexpr (std::is_integral_v<T> || std::is_enum_v<T>)
            return int64(value);
        else if constexpr (std::is_floating_point_v<T>)
            return double(value);
        else
            return {};
    }
};

#endif // TRINITY_INSTANCE_DATA_H
