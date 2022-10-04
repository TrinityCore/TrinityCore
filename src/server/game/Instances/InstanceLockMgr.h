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

#ifndef InstanceLockMgr_h__
#define InstanceLockMgr_h__

#include "Define.h"
#include "DatabaseEnvFwd.h"
#include "Duration.h"
#include "Hash.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include <shared_mutex>
#include <unordered_map>

/*
 * - Resetting instance difficulties with reset schedule from UI seems only possible either when its completed or in group (and only with LockID)
 * - All difficulties of all maps with ResetInterval share locks - KEY is (MapID, LockID)
 *
 * DATABASE
 * character_instance_lock
 *   `guid` bigint(20) unsigned NOT NULL,
 *   `mapId` int(10) unsigned NOT NULL,
 *   `lockId` int(10) unsigned NOT NULL,
 *   `instanceId` int(10) unsigned,                 REFERENCES instance for instanceId based locks
 *   `difficulty` tinyint(3) unsigned,
 *   `data` text,                                   ALWAYS FILLED (also might not match instance data for instanceId based locks)
 *   `completedEncountersMask` int(10) unsigned,    ALWAYS FILLED (also might not match instance data for instanceId based locks)
 *   `entranceWorldSafeLocId` int(10) unsigned,     ALWAYS FILLED (also might not match instance data for instanceId based locks)
 *   `expiryTime` bigint(20) unsigned,
 *   `extended` tinyint(1) unsigned,
 *   PRIMARY KEY (`guid`,`mapId`,`lockId`),
 *
 * instance
 *   `instanceId` int(10) unsigned NOT NULL,
 *   `data` text,                                   FILLED ONLY FOR ID BASED LOCKS
 *   `completedEncountersMask` int(10) unsigned,    FILLED ONLY FOR ID BASED LOCKS
 *   `entranceWorldSafeLocId` int(10) unsigned,     FILLED ONLY FOR ID BASED LOCKS
 *   PRIMARY KEY (`instanceId`)
 */

struct DungeonEncounterEntry;
struct MapEntry;
struct MapDifficultyEntry;
enum Difficulty : uint8;
enum TransferAbortReason : uint32;

#define INSTANCE_ID_HIGH_MASK   0x1F440000
#define INSTANCE_ID_LFG_MASK    0x00000001
#define INSTANCE_ID_NORMAL_MASK 0x00010000

using InstanceResetTimePoint = std::chrono::system_clock::time_point;

struct InstanceLockData
{
    InstanceLockData();
    virtual ~InstanceLockData();

    InstanceLockData(InstanceLockData const&) = delete;
    InstanceLockData(InstanceLockData&&) = delete;
    InstanceLockData& operator=(InstanceLockData const&) = delete;
    InstanceLockData& operator=(InstanceLockData&&) = delete;

    std::string Data;
    uint32 CompletedEncountersMask = 0;
    uint32 EntranceWorldSafeLocId = 0;
};

class TC_GAME_API InstanceLock
{
public:
    InstanceLock(uint32 mapId, Difficulty difficultyId, InstanceResetTimePoint expiryTime, uint32 instanceId);
    virtual ~InstanceLock();

    InstanceLock(InstanceLock const&) = delete;
    InstanceLock(InstanceLock&&) = delete;
    InstanceLock& operator=(InstanceLock const&) = delete;
    InstanceLock& operator=(InstanceLock&&) = delete;

    uint32 GetMapId() const { return _mapId; }

    Difficulty GetDifficultyId() const { return _difficultyId; }

    uint32 GetInstanceId() const { return _instanceId; }
    virtual void SetInstanceId(uint32 instanceId) { _instanceId = instanceId; }

    InstanceResetTimePoint GetExpiryTime() const { return _expiryTime; }
    void SetExpiryTime(InstanceResetTimePoint expiryTime) { _expiryTime = expiryTime; }
    bool IsExpired() const;

    bool IsExtended() const { return _extended; }
    void SetExtended(bool extended) { _extended = extended; }

    InstanceLockData* GetData() { return &_data; }
    InstanceLockData const* GetData() const { return &_data; }

    virtual InstanceLockData const* GetInstanceInitializationData() const { return &_data; }

    InstanceResetTimePoint GetEffectiveExpiryTime() const;

    bool IsInUse() const { return _isInUse; }
    void SetInUse(bool inUse) { _isInUse = inUse; }

private:
    uint32 _mapId;
    Difficulty _difficultyId;
    uint32 _instanceId;
    std::chrono::system_clock::time_point _expiryTime;
    bool _extended;
    InstanceLockData _data;
    bool _isInUse;
};

struct SharedInstanceLockData : InstanceLockData
{
    SharedInstanceLockData();
    ~SharedInstanceLockData();

    SharedInstanceLockData(SharedInstanceLockData const&) = delete;
    SharedInstanceLockData(SharedInstanceLockData&&) = delete;
    SharedInstanceLockData& operator=(SharedInstanceLockData const&) = delete;
    SharedInstanceLockData& operator=(SharedInstanceLockData&&) = delete;

    uint32 InstanceId = 0;
};

class TC_GAME_API SharedInstanceLock : public InstanceLock
{
public:
    SharedInstanceLock(uint32 mapId, Difficulty difficultyId, InstanceResetTimePoint expiryTime, uint32 instanceId, std::shared_ptr<SharedInstanceLockData> sharedData);

    void SetInstanceId(uint32 instanceId) override
    {
        InstanceLock::SetInstanceId(instanceId);
        _sharedData->InstanceId = instanceId;
    }

    InstanceLockData const* GetInstanceInitializationData() const override { return _sharedData.get(); }

    SharedInstanceLockData* GetSharedData() { return _sharedData.get(); }
    SharedInstanceLockData const* GetSharedData() const { return _sharedData.get(); }

private:
    /**
       Instance id based locks have two states
       One shared by everyone, which is the real state used by instance
       and one for each player that shows in UI that might have less encounters completed
    */
    std::shared_ptr<SharedInstanceLockData> _sharedData;
};

using InstanceLockKey = std::pair<uint32 /*MapDifficultyEntry::MapID*/, uint32 /*MapDifficultyEntry::LockID*/>;

struct TC_GAME_API MapDb2Entries
{
    MapDb2Entries(uint32 mapId, Difficulty difficulty);
    MapDb2Entries(MapEntry const* map, MapDifficultyEntry const* mapDifficulty);

    InstanceLockKey GetKey() const;
    bool IsInstanceIdBound() const;

    MapEntry const* Map;
    MapDifficultyEntry const* MapDifficulty;
};

struct InstanceLockUpdateEvent
{
    InstanceLockUpdateEvent(uint32 instanceId, std::string newData, uint32 instanceCompletedEncountersMask, DungeonEncounterEntry const* completedEncounter,
        Optional<uint32> entranceWorldSafeLocId) :
        InstanceId(instanceId), NewData(std::move(newData)), InstanceCompletedEncountersMask(instanceCompletedEncountersMask), CompletedEncounter(completedEncounter),
        EntranceWorldSafeLocId(entranceWorldSafeLocId) { }
    InstanceLockUpdateEvent(InstanceLockUpdateEvent const& other) = delete;
    InstanceLockUpdateEvent(InstanceLockUpdateEvent&& other) noexcept;

    InstanceLockUpdateEvent& operator=(InstanceLockUpdateEvent const&) = delete;
    InstanceLockUpdateEvent& operator=(InstanceLockUpdateEvent&&) noexcept;
    ~InstanceLockUpdateEvent();

    uint32 InstanceId;
    std::string NewData;
    uint32 InstanceCompletedEncountersMask;
    DungeonEncounterEntry const* CompletedEncounter;
    Optional<uint32> EntranceWorldSafeLocId;
};

struct InstanceLocksStatistics
{
    uint32 InstanceCount = 0;   // Number of existing ID-based locks
    uint32 PlayerCount = 0;     // Number of players that have any lock
};

class TC_GAME_API InstanceLockMgr
{
public:
    void Load();
    void Unload();

    /**
       @brief Checks if player is allowed to enter instance map
       @param playerGuid Guid of player who is trying to enter instance map
       @param entries Map.db2 + MapDifficulty.db2 data for instance
       @param instanceLock InstanceLock used during map creation
       @return Failure reason to show in client or TRANSFER_ABORT_NONE when player is allowed to enter
    */
    TransferAbortReason CanJoinInstanceLock(ObjectGuid const& playerGuid, MapDb2Entries const& entries, InstanceLock const* instanceLock) const;

    /**
       @brief Attempts to find InstanceLock for given instance owner. This will also find expired but extended locks
       @param playerGuid Guid of player owning instance. Player's own guid if not in group, otherwise group leader's
       @param entries Map.db2 + MapDifficulty.db2 data for instance
       @return InstanceLock previously loaded from database
    */
    InstanceLock* FindActiveInstanceLock(ObjectGuid const& playerGuid, MapDb2Entries const& entries) const;

    /**
       @brief Retrieves all existing instance locks for a player
       @param playerGuid Guid of player whose locks are requested
       @return All locks (current and expired) for player
    */
    std::vector<InstanceLock const*> GetInstanceLocksForPlayer(ObjectGuid const& playerGuid) const;

    /**
       @brief Creates new InstanceLock when instance map is created
       @param playerGuid Guid of player owning instance. Player's own guid if not in group, otherwise group leader's
       @param entries Map.db2 + MapDifficulty.db2 data for instance
       @param instanceId Persistent instance id
       @return New InstanceLock with clear state and _instanceId not set
    */
    InstanceLock* CreateInstanceLockForNewInstance(ObjectGuid const& playerGuid, MapDb2Entries const& entries, uint32 instanceId);

    /**
       @brief Updates existing instance lock for player with new completed encounter and instance state
       @param trans Database transaction
       @param playerGuid Guid of player who will become locked to instance
       @param entries Map.db2 + MapDifficulty.db2 data for instance
       @param updateEvent New instance lock data
       @return Updated InstanceLock for player
    */
    InstanceLock* UpdateInstanceLockForPlayer(CharacterDatabaseTransaction trans, ObjectGuid const& playerGuid, MapDb2Entries const& entries, InstanceLockUpdateEvent&& updateEvent);

    /**
       @brief Updates existing instance id based lock shared state with new completed encounter and instance state
       @param trans Database transaction
       @param updateEvent New instance lock data
    */
    void UpdateSharedInstanceLock(CharacterDatabaseTransaction trans, InstanceLockUpdateEvent&& updateEvent);

    /**
       @brief Handles last reference to shared instance state being removed to clean up leftover database data
       @param instanceId Id of the instance being deleted
    */
    void OnSharedInstanceLockDataDelete(uint32 instanceId);

    /**
       @brief Updates existing instance lock for player with requested extension state
       @param playerGuid Guid of player whose lock is extended
       @param entries Map.db2 + MapDifficulty.db2 data for instance
       @param extended New instance lock extension state
       @return pair<OldExpirationTime, NewExpirationTime>
    */
    std::pair<InstanceResetTimePoint, InstanceResetTimePoint> UpdateInstanceLockExtensionForPlayer(ObjectGuid const& playerGuid, MapDb2Entries const& entries, bool extended);

    /**
       @brief Resets instances that match given filter - for use in GM commands
       @param playerGuid Guid of player whose locks will be removed
       @param mapId (Optional) Map id of instance locks to reset
       @param difficulty (Optional) Difficulty of instance locks to reset
       @param locksReset All locks that were reset
       @param locksFailedToReset Locks that could not be reset because they are used by existing instance map
    */
    void ResetInstanceLocksForPlayer(ObjectGuid const& playerGuid, Optional<uint32> mapId, Optional<Difficulty> difficulty,
        std::vector<InstanceLock const*>* locksReset, std::vector<InstanceLock const*>* locksFailedToReset);

    /**
       @brief Retrieves instance lock statistics - for use in GM commands
       @return Statistics info
    */
    InstanceLocksStatistics GetStatistics() const;

    static InstanceLockMgr& Instance();

    static InstanceResetTimePoint GetNextResetTime(MapDb2Entries const& entries);

private:
    InstanceLockMgr();
    InstanceLockMgr(InstanceLockMgr const& right) = delete;
    InstanceLockMgr(InstanceLockMgr&& right) = delete;
    InstanceLockMgr& operator=(InstanceLockMgr const& right) = delete;
    InstanceLockMgr& operator=(InstanceLockMgr&& right) = delete;

    ~InstanceLockMgr();

    using PlayerLockMap = std::unordered_map<InstanceLockKey, std::unique_ptr<InstanceLock>>;
    using LockMap = std::unordered_map<ObjectGuid, PlayerLockMap>;

    static InstanceLock* FindInstanceLock(LockMap const& locks, ObjectGuid const& playerGuid, MapDb2Entries const& entries);
    InstanceLock* FindActiveInstanceLock(ObjectGuid const& playerGuid, MapDb2Entries const& entries, bool ignoreTemporary, bool ignoreExpired) const;

    mutable std::shared_mutex _locksMutex;
    LockMap _temporaryInstanceLocksByPlayer; // locks stored here before any boss gets killed
    LockMap _instanceLocksByPlayer;
    std::unordered_map<uint32, std::weak_ptr<SharedInstanceLockData>> _instanceLockDataById;
    bool _unloading = false;
};

#define sInstanceLockMgr InstanceLockMgr::Instance()

#endif // InstanceLockMgr_h__
