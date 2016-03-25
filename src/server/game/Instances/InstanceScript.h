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

#ifndef TRINITY_INSTANCE_DATA_H
#define TRINITY_INSTANCE_DATA_H

#include <set>
#include "ZoneScript.h"
#include "World.h"
#include "ObjectMgr.h"
#include "CreatureAI.h"

#define OUT_SAVE_INST_DATA             TC_LOG_DEBUG("scripts", "Saving Instance Data for Instance %s (Map %d, Instance Id %d)", instance->GetMapName(), instance->GetId(), instance->GetInstanceId())
#define OUT_SAVE_INST_DATA_COMPLETE    TC_LOG_DEBUG("scripts", "Saving Instance Data for Instance %s (Map %d, Instance Id %d) completed.", instance->GetMapName(), instance->GetId(), instance->GetInstanceId())
#define OUT_LOAD_INST_DATA(a)          TC_LOG_DEBUG("scripts", "Loading Instance Data for Instance %s (Map %d, Instance Id %d). Input is '%s'", instance->GetMapName(), instance->GetId(), instance->GetInstanceId(), a)
#define OUT_LOAD_INST_DATA_COMPLETE    TC_LOG_DEBUG("scripts", "Instance Data Load for Instance %s (Map %d, Instance Id: %d) is complete.", instance->GetMapName(), instance->GetId(), instance->GetInstanceId())
#define OUT_LOAD_INST_DATA_FAIL        TC_LOG_ERROR("scripts", "Unable to load Instance Data for Instance %s (Map %d, Instance Id: %d).", instance->GetMapName(), instance->GetId(), instance->GetInstanceId())

class Map;
class Unit;
class Player;
class GameObject;
class Creature;

enum EncounterFrameType
{
    ENCOUNTER_FRAME_ENGAGE              = 0,
    ENCOUNTER_FRAME_DISENGAGE           = 1,
    ENCOUNTER_FRAME_UPDATE_PRIORITY     = 2,
    ENCOUNTER_FRAME_ADD_TIMER           = 3,
    ENCOUNTER_FRAME_ENABLE_OBJECTIVE    = 4,
    ENCOUNTER_FRAME_UPDATE_OBJECTIVE    = 5,
    ENCOUNTER_FRAME_DISABLE_OBJECTIVE   = 6,
    ENCOUNTER_FRAME_UNK7                = 7 // Seems to have something to do with sorting the encounter units
};

enum EncounterState
{
    NOT_STARTED   = 0,
    IN_PROGRESS   = 1,
    FAIL          = 2,
    DONE          = 3,
    SPECIAL       = 4,
    TO_BE_DECIDED = 5
};

enum DoorType
{
    DOOR_TYPE_ROOM          = 0,    // Door can open if encounter is not in progress
    DOOR_TYPE_PASSAGE       = 1,    // Door can open if encounter is done
    DOOR_TYPE_SPAWN_HOLE    = 2,    // Door can open if encounter is in progress, typically used for spawning places
    MAX_DOOR_TYPES
};

struct DoorData
{
    uint32 entry, bossId;
    DoorType type;
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

struct BossInfo
{
    BossInfo() : state(TO_BE_DECIDED) { }
    EncounterState state;
    GuidSet door[MAX_DOOR_TYPES];
    GuidSet minion;
    CreatureBoundary boundary;
};

struct DoorInfo
{
    explicit DoorInfo(BossInfo* _bossInfo, DoorType _type)
        : bossInfo(_bossInfo), type(_type) { }
    BossInfo* bossInfo;
    DoorType type;
};

struct MinionInfo
{
    explicit MinionInfo(BossInfo* _bossInfo) : bossInfo(_bossInfo) { }
    BossInfo* bossInfo;
};

typedef std::multimap<uint32 /*entry*/, DoorInfo> DoorInfoMap;
typedef std::pair<DoorInfoMap::const_iterator, DoorInfoMap::const_iterator> DoorInfoMapBounds;

typedef std::map<uint32 /*entry*/, MinionInfo> MinionInfoMap;
typedef std::map<uint32 /*type*/, ObjectGuid /*guid*/> ObjectGuidMap;
typedef std::map<uint32 /*entry*/, uint32 /*type*/> ObjectInfoMap;

class TC_GAME_API InstanceScript : public ZoneScript
{
    public:
        explicit InstanceScript(Map* map) : instance(map), completedEncounters(0) { }

        virtual ~InstanceScript() { }

        Map* instance;

        // On creation, NOT load.
        // PLEASE INITIALIZE FIELDS IN THE CONSTRUCTOR INSTEAD !!!
        // KEEPING THIS METHOD ONLY FOR BACKWARD COMPATIBILITY !!!
        virtual void Initialize() { }

        // On load
        virtual void Load(char const* data);

        // When save is needed, this function generates the data
        virtual std::string GetSaveData();

        void SaveToDB();

        virtual void Update(uint32 /*diff*/) { }

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

        inline Creature* GetCreature(uint32 type)
        {
            return instance->GetCreature(GetObjectGuid(type));
        }
        inline GameObject* GetGameObject(uint32 type)
        {
            return instance->GetGameObject(GetObjectGuid(type));
        }

        // Called when a player successfully enters the instance.
        virtual void OnPlayerEnter(Player* /*player*/) { }

        // Handle open / close objects
        // * use HandleGameObject(0, boolen, GO); in OnObjectCreate in instance scripts
        // * use HandleGameObject(GUID, boolen, NULL); in any other script
        void HandleGameObject(ObjectGuid guid, bool open, GameObject* go = nullptr);

        // Change active state of doors or buttons
        void DoUseDoorOrButton(ObjectGuid guid, uint32 withRestoreTime = 0, bool useAlternativeState = false);
        void DoCloseDoorOrButton(ObjectGuid guid);

        // Respawns a GO having negative spawntimesecs in gameobject-table
        void DoRespawnGameObject(ObjectGuid guid, uint32 timeToDespawn = MINUTE);

        // Sends world state update to all players in instance
        void DoUpdateWorldState(uint32 worldstateId, uint32 worldstateValue);

        // Send Notify to all players in instance
        void DoSendNotifyToInstance(char const* format, ...);

        // Update Achievement Criteria for all players in instance
        void DoUpdateAchievementCriteria(AchievementCriteriaTypes type, uint32 miscValue1 = 0, uint32 miscValue2 = 0, Unit* unit = NULL);

        // Start/Stop Timed Achievement Criteria for all players in instance
        void DoStartTimedAchievement(AchievementCriteriaTimedTypes type, uint32 entry);
        void DoStopTimedAchievement(AchievementCriteriaTimedTypes type, uint32 entry);

        // Remove Auras due to Spell on all players in instance
        void DoRemoveAurasDueToSpellOnPlayers(uint32 spell);

        // Cast spell on all players in instance
        void DoCastSpellOnPlayers(uint32 spell);

        // Return wether server allow two side groups or not
        bool ServerAllowsTwoSideGroups() { return sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GROUP); }

        virtual bool SetBossState(uint32 id, EncounterState state);
        EncounterState GetBossState(uint32 id) const { return id < bosses.size() ? bosses[id].state : TO_BE_DECIDED; }
        static std::string GetBossStateName(uint8 state);
        CreatureBoundary const* GetBossBoundary(uint32 id) const { return id < bosses.size() ? &bosses[id].boundary : NULL; }

        // Achievement criteria additional requirements check
        // NOTE: not use this if same can be checked existed requirement types from AchievementCriteriaRequirementType
        virtual bool CheckAchievementCriteriaMeet(uint32 /*criteria_id*/, Player const* /*source*/, Unit const* /*target*/ = NULL, uint32 /*miscvalue1*/ = 0);

        // Checks boss requirements (one boss required to kill other)
        virtual bool CheckRequiredBosses(uint32 /*bossId*/, Player const* /*player*/ = nullptr) const { return true; }

        // Checks encounter state at kill/spellcast
        void UpdateEncounterState(EncounterCreditType type, uint32 creditEntry, Unit* source);

        // Used only during loading
        void SetCompletedEncountersMask(uint32 newMask) { completedEncounters = newMask; }

        // Returns completed encounters mask for packets
        uint32 GetCompletedEncounterMask() const { return completedEncounters; }

        void SendEncounterUnit(uint32 type, Unit* unit = NULL, uint8 param1 = 0, uint8 param2 = 0);

        virtual void FillInitialWorldStates(WorldPacket& /*data*/) { }

        uint32 GetEncounterCount() const { return bosses.size(); }

    protected:
        void SetHeaders(std::string const& dataHeaders);
        void SetBossNumber(uint32 number) { bosses.resize(number); }
        void LoadBossBoundaries(BossBoundaryData const& data);
        void LoadDoorData(DoorData const* data);
        void LoadMinionData(MinionData const* data);
        void LoadObjectData(ObjectData const* creatureData, ObjectData const* gameObjectData);

        void AddObject(Creature* obj, bool add);
        void AddObject(GameObject* obj, bool add);
        void AddObject(WorldObject* obj, uint32 type, bool add);

        virtual void AddDoor(GameObject* door, bool add);
        void AddMinion(Creature* minion, bool add);

        virtual void UpdateDoorState(GameObject* door);
        void UpdateMinionState(Creature* minion, EncounterState state);

        // Exposes private data that should never be modified unless exceptional cases.
        // Pay very much attention at how the returned BossInfo data is modified to avoid issues.
        BossInfo* GetBossInfo(uint32 id);

        // Instance Load and Save
        bool ReadSaveDataHeaders(std::istringstream& data);
        void ReadSaveDataBossStates(std::istringstream& data);
        virtual void ReadSaveDataMore(std::istringstream& /*data*/) { }
        void WriteSaveDataHeaders(std::ostringstream& data);
        void WriteSaveDataBossStates(std::ostringstream& data);
        virtual void WriteSaveDataMore(std::ostringstream& /*data*/) { }

        bool _SkipCheckRequiredBosses(Player const* player = nullptr) const;

    private:
        static void LoadObjectData(ObjectData const* creatureData, ObjectInfoMap& objectInfo);

        std::vector<char> headers;
        std::vector<BossInfo> bosses;
        DoorInfoMap doors;
        MinionInfoMap minions;
        ObjectInfoMap _creatureInfo;
        ObjectInfoMap _gameObjectInfo;
        ObjectGuidMap _objectGuids;
        uint32 completedEncounters; // completed encounter mask, bit indexes are DungeonEncounter.dbc boss numbers, used for packets
};

template<class AI, class T>
AI* GetInstanceAI(T* obj, char const* scriptName)
{
    if (InstanceMap* instance = obj->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId(scriptName))
                return new AI(obj);

    return NULL;
}

template<class AI, class T>
AI* GetInstanceAI(T* obj)
{
    if (InstanceMap* instance = obj->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            return new AI(obj);

    return NULL;
}

#endif // TRINITY_INSTANCE_DATA_H
