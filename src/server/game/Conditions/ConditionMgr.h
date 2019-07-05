/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef TRINITY_CONDITIONMGR_H
#define TRINITY_CONDITIONMGR_H

#include "Define.h"
#include "Hash.h"
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Creature;
class Player;
class Unit;
class WorldObject;
class LootTemplate;
struct Condition;

enum ConditionTypes
{                                                              // value1           value2         value3
    CONDITION_NONE                     = 0,                    // 0                0              0                  always true
    CONDITION_AURA                     = 1,                    // spell_id         effindex       use target?        true if player (or target, if value3) has aura of spell_id with effect effindex
    CONDITION_ITEM                     = 2,                    // item_id          count          bank               true if has #count of item_ids (if 'bank' is set it searches in bank slots too)
    CONDITION_ITEM_EQUIPPED            = 3,                    // item_id          0              0                  true if has item_id equipped
    CONDITION_ZONEID                   = 4,                    // zone_id          0              0                  true if in zone_id
    CONDITION_REPUTATION_RANK          = 5,                    // faction_id       rankMask       0                  true if has min_rank for faction_id
    CONDITION_TEAM                     = 6,                    // player_team      0,             0                  469 - Alliance, 67 - Horde)
    CONDITION_SKILL                    = 7,                    // skill_id         skill_value    0                  true if has skill_value for skill_id
    CONDITION_QUESTREWARDED            = 8,                    // quest_id         0              0                  true if quest_id was rewarded before
    CONDITION_QUESTTAKEN               = 9,                    // quest_id         0,             0                  true while quest active
    CONDITION_DRUNKENSTATE             = 10,                   // DrunkenState     0,             0                  true if player is drunk enough
    CONDITION_WORLD_STATE              = 11,                   // index            value          0                  true if world has the value for the index
    CONDITION_ACTIVE_EVENT             = 12,                   // event_id         0              0                  true if event is active
    CONDITION_INSTANCE_INFO            = 13,                   // entry            data           type               true if the instance info defined by type (enum InstanceInfo) equals data.
    CONDITION_QUEST_NONE               = 14,                   // quest_id         0              0                  true if doesn't have quest saved
    CONDITION_CLASS                    = 15,                   // class            0              0                  true if player's class is equal to class
    CONDITION_RACE                     = 16,                   // race             0              0                  true if player's race is equal to race
    CONDITION_ACHIEVEMENT              = 17,                   // achievement_id   0              0                  true if achievement is complete
    CONDITION_TITLE                    = 18,                   // title id         0              0                  true if player has title
    CONDITION_SPAWNMASK                = 19,                   // spawnMask        0              0                  true if in spawnMask
    CONDITION_GENDER                   = 20,                   // gender           0              0                  true if player's gender is equal to gender
    CONDITION_UNIT_STATE               = 21,                   // unitState        0              0                  true if unit has unitState
    CONDITION_MAPID                    = 22,                   // map_id           0              0                  true if in map_id
    CONDITION_AREAID                   = 23,                   // area_id          0              0                  true if in area_id
    CONDITION_CREATURE_TYPE            = 24,                   // cinfo.type       0              0                  true if creature_template.type = value1
    CONDITION_SPELL                    = 25,                   // spell_id         0              0                  true if player has learned spell
    CONDITION_PHASEMASK                = 26,                   // phasemask        0              0                  true if object is in phasemask
    CONDITION_LEVEL                    = 27,                   // level            ComparisonType 0                  true if unit's level is equal to param1 (param2 can modify the statement)
    CONDITION_QUEST_COMPLETE           = 28,                   // quest_id         0              0                  true if player has quest_id with all objectives complete, but not yet rewarded
    CONDITION_NEAR_CREATURE            = 29,                   // creature entry   distance       dead (0/1)         true if there is a creature of entry in range
    CONDITION_NEAR_GAMEOBJECT          = 30,                   // gameobject entry distance       0                  true if there is a gameobject of entry in range
    CONDITION_OBJECT_ENTRY_GUID        = 31,                   // TypeID           entry          guid               true if object is type TypeID and the entry is 0 or matches entry of the object or matches guid of the object
    CONDITION_TYPE_MASK                = 32,                   // TypeMask         0              0                  true if object is type object's TypeMask matches provided TypeMask
    CONDITION_RELATION_TO              = 33,                   // ConditionTarget  RelationType   0                  true if object is in given relation with object specified by ConditionTarget
    CONDITION_REACTION_TO              = 34,                   // ConditionTarget  rankMask       0                  true if object's reaction matches rankMask object specified by ConditionTarget
    CONDITION_DISTANCE_TO              = 35,                   // ConditionTarget  distance       ComparisonType     true if object and ConditionTarget are within distance given by parameters
    CONDITION_ALIVE                    = 36,                   // 0                0              0                  true if unit is alive
    CONDITION_HP_VAL                   = 37,                   // hpVal            ComparisonType 0                  true if unit's hp matches given value
    CONDITION_HP_PCT                   = 38,                   // hpPct            ComparisonType 0                  true if unit's hp matches given pct
    CONDITION_REALM_ACHIEVEMENT        = 39,                   // achievement_id   0              0                  true if realm achievement is complete
    CONDITION_IN_WATER                 = 40,                   // 0                0              0                  true if unit in water
    CONDITION_TERRAIN_SWAP             = 41,                   //                                                    only for master branch
    CONDITION_STAND_STATE              = 42,                   // stateType        state          0                  true if unit matches specified sitstate (0,x: has exactly state x; 1,0: any standing state; 1,1: any sitting state;)
    CONDITION_DAILY_QUEST_DONE         = 43,                   // quest id         0              0                  true if daily quest has been completed for the day
    CONDITION_CHARMED                  = 44,                   // 0                0              0                  true if unit is currently charmed
    CONDITION_PET_TYPE                 = 45,                   // mask             0              0                  true if player has a pet of given type(s)
    CONDITION_TAXI                     = 46,                   // 0                0              0                  true if player is on taxi
    CONDITION_QUESTSTATE               = 47,                   // quest_id         state_mask     0                  true if player is in any of the provided quest states for the quest (1 = not taken, 2 = completed, 8 = in progress, 32 = failed, 64 = rewarded)
    CONDITION_QUEST_OBJECTIVE_PROGRESS = 48,                   // quest_id         objectiveIndex objectiveCount     true if player has reached the specified objectiveCount quest progress for the objectiveIndex for the specified quest
    CONDITION_GAMEMASTER               = 49,                   // canBeGM          0              0                  true if player is gamemaster (or can be gamemaster)
    CONDITION_MAX                      = 50                    // MAX
};

/*! Documentation on implementing a new ConditionSourceType:
    Step 1: Check for the lowest free ID. Look for CONDITION_SOURCE_TYPE_UNUSED_XX in the enum.
            Then define the new source type.

    Step 2: Determine and map the parameters for the new condition type.

    Step 3: Add a case block to ConditionMgr::isSourceTypeValid with the new condition type
            and validate the parameters.

    Step 4: If your condition can be grouped (determined in step 2), add a rule for it in
            ConditionMgr::CanHaveSourceGroupSet, following the example of the existing types.

    Step 5: Define the maximum available condition targets in ConditionMgr::GetMaxAvailableConditionTargets.

    The following steps only apply if your condition can be grouped:

    Step 6: Determine how you are going to store your conditions. You need to add a new storage container
            for it in ConditionMgr class, along with a function like:
            ConditionList GetConditionsForXXXYourNewSourceTypeXXX(parameters...)

            The above function should be placed in upper level (practical) code that actually
            checks the conditions.

    Step 7: Implement loading for your source type in ConditionMgr::LoadConditions.

    Step 8: Implement memory cleaning for your source type in ConditionMgr::Clean.
*/
enum ConditionSourceType
{
    CONDITION_SOURCE_TYPE_NONE                           = 0,
    CONDITION_SOURCE_TYPE_CREATURE_LOOT_TEMPLATE         = 1,
    CONDITION_SOURCE_TYPE_DISENCHANT_LOOT_TEMPLATE       = 2,
    CONDITION_SOURCE_TYPE_FISHING_LOOT_TEMPLATE          = 3,
    CONDITION_SOURCE_TYPE_GAMEOBJECT_LOOT_TEMPLATE       = 4,
    CONDITION_SOURCE_TYPE_ITEM_LOOT_TEMPLATE             = 5,
    CONDITION_SOURCE_TYPE_MAIL_LOOT_TEMPLATE             = 6,
    CONDITION_SOURCE_TYPE_MILLING_LOOT_TEMPLATE          = 7,
    CONDITION_SOURCE_TYPE_PICKPOCKETING_LOOT_TEMPLATE    = 8,
    CONDITION_SOURCE_TYPE_PROSPECTING_LOOT_TEMPLATE      = 9,
    CONDITION_SOURCE_TYPE_REFERENCE_LOOT_TEMPLATE        = 10,
    CONDITION_SOURCE_TYPE_SKINNING_LOOT_TEMPLATE         = 11,
    CONDITION_SOURCE_TYPE_SPELL_LOOT_TEMPLATE            = 12,
    CONDITION_SOURCE_TYPE_SPELL_IMPLICIT_TARGET          = 13,
    CONDITION_SOURCE_TYPE_GOSSIP_MENU                    = 14,
    CONDITION_SOURCE_TYPE_GOSSIP_MENU_OPTION             = 15,
    CONDITION_SOURCE_TYPE_CREATURE_TEMPLATE_VEHICLE      = 16,
    CONDITION_SOURCE_TYPE_SPELL                          = 17,
    CONDITION_SOURCE_TYPE_SPELL_CLICK_EVENT              = 18,
    CONDITION_SOURCE_TYPE_QUEST_AVAILABLE                = 19,
    // Condition source type 20 unused
    CONDITION_SOURCE_TYPE_VEHICLE_SPELL                  = 21,
    CONDITION_SOURCE_TYPE_SMART_EVENT                    = 22,
    CONDITION_SOURCE_TYPE_NPC_VENDOR                     = 23,
    CONDITION_SOURCE_TYPE_SPELL_PROC                     = 24,
    CONDITION_SOURCE_TYPE_TERRAIN_SWAP                   = 25, // only master
    CONDITION_SOURCE_TYPE_PHASE                          = 26, // only master
    CONDITION_SOURCE_TYPE_GRAVEYARD                      = 27, // only master
    CONDITION_SOURCE_TYPE_MAX                            = 28  // MAX
};

enum RelationType
{
    RELATION_SELF = 0,
    RELATION_IN_PARTY,
    RELATION_IN_RAID_OR_PARTY,
    RELATION_OWNED_BY,
    RELATION_PASSENGER_OF,
    RELATION_CREATED_BY,
    RELATION_MAX
};

enum InstanceInfo
{
    INSTANCE_INFO_DATA = 0,
    INSTANCE_INFO_GUID_DATA,
    INSTANCE_INFO_BOSS_STATE,
    INSTANCE_INFO_DATA64
};

enum MaxConditionTargets
{
    MAX_CONDITION_TARGETS = 3
};

struct TC_GAME_API ConditionSourceInfo
{
    WorldObject* mConditionTargets[MAX_CONDITION_TARGETS]; // an array of targets available for conditions
    Condition const* mLastFailedCondition;
    ConditionSourceInfo(WorldObject* target0, WorldObject* target1 = nullptr, WorldObject* target2 = nullptr)
    {
        mConditionTargets[0] = target0;
        mConditionTargets[1] = target1;
        mConditionTargets[2] = target2;
        mLastFailedCondition = nullptr;
    }
};

struct TC_GAME_API Condition
{
    ConditionSourceType     SourceType;        //SourceTypeOrReferenceId
    uint32                  SourceGroup;
    int32                   SourceEntry;
    uint32                  SourceId;          // So far, only used in CONDITION_SOURCE_TYPE_SMART_EVENT
    uint32                  ElseGroup;
    ConditionTypes          ConditionType;     //ConditionTypeOrReference
    uint32                  ConditionValue1;
    uint32                  ConditionValue2;
    uint32                  ConditionValue3;
    uint32                  ErrorType;
    uint32                  ErrorTextId;
    uint32                  ReferenceId;
    uint32                  ScriptId;
    uint8                   ConditionTarget;
    bool                    NegativeCondition;

    Condition()
    {
        SourceType         = CONDITION_SOURCE_TYPE_NONE;
        SourceGroup        = 0;
        SourceEntry        = 0;
        SourceId           = 0;
        ElseGroup          = 0;
        ConditionType      = CONDITION_NONE;
        ConditionTarget    = 0;
        ConditionValue1    = 0;
        ConditionValue2    = 0;
        ConditionValue3    = 0;
        ReferenceId        = 0;
        ErrorType          = 0;
        ErrorTextId        = 0;
        ScriptId           = 0;
        NegativeCondition  = false;
    }

    bool Meets(ConditionSourceInfo& sourceInfo) const;
    uint32 GetSearcherTypeMaskForCondition() const;
    bool isLoaded() const { return ConditionType > CONDITION_NONE || ReferenceId; }
    uint32 GetMaxAvailableConditionTargets() const;

    std::string ToString(bool ext = false) const; /// For logging purpose
};

typedef std::vector<Condition*> ConditionContainer;
typedef std::unordered_map<uint32 /*SourceEntry*/, ConditionContainer> ConditionsByEntryMap;
typedef std::array<ConditionsByEntryMap, CONDITION_SOURCE_TYPE_MAX> ConditionEntriesByTypeArray;
typedef std::unordered_map<uint32, ConditionsByEntryMap> ConditionEntriesByCreatureIdMap;
typedef std::unordered_map<std::pair<int32, uint32 /*SAI source_type*/>, ConditionsByEntryMap> SmartEventConditionContainer;
typedef std::unordered_map<uint32, ConditionContainer> ConditionReferenceContainer;//only used for references

class TC_GAME_API ConditionMgr
{
    private:
        ConditionMgr();
        ~ConditionMgr();

    public:
        static ConditionMgr* instance();

        void LoadConditions(bool isReload = false);
        bool isConditionTypeValid(Condition* cond) const;

        uint32 GetSearcherTypeMaskForConditionList(ConditionContainer const& conditions) const;
        bool IsObjectMeetToConditions(WorldObject* object, ConditionContainer const& conditions) const;
        bool IsObjectMeetToConditions(WorldObject* object1, WorldObject* object2, ConditionContainer const& conditions) const;
        bool IsObjectMeetToConditions(ConditionSourceInfo& sourceInfo, ConditionContainer const& conditions) const;
        static bool CanHaveSourceGroupSet(ConditionSourceType sourceType);
        static bool CanHaveSourceIdSet(ConditionSourceType sourceType);
        bool IsObjectMeetingNotGroupedConditions(ConditionSourceType sourceType, uint32 entry, ConditionSourceInfo& sourceInfo) const;
        bool IsObjectMeetingNotGroupedConditions(ConditionSourceType sourceType, uint32 entry, WorldObject* target0, WorldObject* target1 = nullptr, WorldObject* target2 = nullptr) const;
        bool HasConditionsForNotGroupedEntry(ConditionSourceType sourceType, uint32 entry) const;
        bool IsObjectMeetingSpellClickConditions(uint32 creatureId, uint32 spellId, WorldObject* clicker, WorldObject* target) const;
        ConditionContainer const* GetConditionsForSpellClickEvent(uint32 creatureId, uint32 spellId) const;
        bool IsObjectMeetingVehicleSpellConditions(uint32 creatureId, uint32 spellId, Player* player, Unit* vehicle) const;
        bool IsObjectMeetingSmartEventConditions(int32 entryOrGuid, uint32 eventId, uint32 sourceType, Unit* unit, WorldObject* baseObject) const;
        bool IsObjectMeetingVendorItemConditions(uint32 creatureId, uint32 itemId, Player* player, Creature* vendor) const;

        bool IsSpellUsedInSpellClickConditions(uint32 spellId) const;

        struct ConditionTypeInfo
        {
            char const* Name;
            bool HasConditionValue1;
            bool HasConditionValue2;
            bool HasConditionValue3;
        };
        static char const* const StaticSourceTypeData[CONDITION_SOURCE_TYPE_MAX];
        static ConditionTypeInfo const StaticConditionTypeData[CONDITION_MAX];

    private:
        bool isSourceTypeValid(Condition* cond) const;
        bool addToLootTemplate(Condition* cond, LootTemplate* loot) const;
        bool addToGossipMenus(Condition* cond) const;
        bool addToGossipMenuItems(Condition* cond) const;
        bool addToSpellImplicitTargetConditions(Condition* cond) const;
        bool IsObjectMeetToConditionList(ConditionSourceInfo& sourceInfo, ConditionContainer const& conditions) const;

        static void LogUselessConditionValue(Condition* cond, uint8 index, uint32 value);

        void Clean(); // free up resources
        std::vector<Condition*> AllocatedMemoryStore; // some garbage collection :)

        ConditionEntriesByTypeArray     ConditionStore;
        ConditionReferenceContainer     ConditionReferenceStore;
        ConditionEntriesByCreatureIdMap VehicleSpellConditionStore;
        ConditionEntriesByCreatureIdMap SpellClickEventConditionStore;
        ConditionEntriesByCreatureIdMap NpcVendorConditionContainerStore;
        SmartEventConditionContainer    SmartEventConditionStore;

        std::unordered_set<uint32> SpellsUsedInSpellClickConditions;
};

#define sConditionMgr ConditionMgr::instance()

#endif
