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

#include "ConditionMgr.h"
#include "AchievementMgr.h"
#include "AreaTrigger.h"
#include "AreaTriggerDataStore.h"
#include "BattlePetMgr.h"
#include "Battleground.h"
#include "Containers.h"
#include "ConversationDataStore.h"
#include "DB2Stores.h"
#include "DatabaseEnv.h"
#include "GameEventMgr.h"
#include "GameObject.h"
#include "GameTime.h"
#include "Group.h"
#include "InstanceScenario.h"
#include "InstanceScript.h"
#include "Item.h"
#include "LFGMgr.h"
#include "LanguageMgr.h"
#include "Log.h"
#include "LootMgr.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Pet.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "RaceMask.h"
#include "Realm.h"
#include "ReputationMgr.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "World.h"
#include "WorldSession.h"
#include "WorldStateMgr.h"
#include "WowTime.h"
#include <random>
#include <sstream>

char const* const ConditionMgr::StaticSourceTypeData[CONDITION_SOURCE_TYPE_MAX_DB_ALLOWED] =
{
    "None",
    "Creature Loot",
    "Disenchant Loot",
    "Fishing Loot",
    "GameObject Loot",
    "Item Loot",
    "Mail Loot",
    "Milling Loot",
    "Pickpocketing Loot",
    "Prospecting Loot",
    "Reference Loot",
    "Skinning Loot",
    "Spell Loot",
    "Spell Impl. Target",
    "Gossip Menu",
    "Gossip Menu Option",
    "Creature Vehicle",
    "Spell Expl. Target",
    "Spell Click Event",
    "Quest Available",
    "Unused",
    "Vehicle Spell",
    "SmartScript",
    "Npc Vendor",
    "Spell Proc",
    "Terrain Swap",
    "Phase",
    "Graveyard",
    "AreaTrigger",
    "ConversationLine",
    "AreaTrigger Client Triggered",
    "Trainer Spell",
    "Object Visibility (by ID)",
    "Spawn Group"
};

ConditionMgr::ConditionTypeInfo const ConditionMgr::StaticConditionTypeData[CONDITION_MAX] =
{
    { "None",                     false, false, false, false },
    { "Aura",                      true, true,  true,  false },
    { "Item Stored",               true, true,  true,  false },
    { "Item Equipped",             true, false, false, false },
    { "Zone",                      true, false, false, false },
    { "Reputation",                true, true,  false, false },
    { "Team",                      true, false, false, false },
    { "Skill",                     true, true,  false, false },
    { "Quest Rewarded",            true, false, false, false },
    { "Quest Taken",               true, false, false, false },
    { "Drunken",                   true, false, false, false },
    { "WorldState",                true, true,  false, false },
    { "Active Event",              true, false, false, false },
    { "Instance Info",             true, true,  true,  false },
    { "Quest None",                true, false, false, false },
    { "Class",                     true, false, false, false },
    { "Race",                      true, false, false, false },
    { "Achievement",               true, false, false, false },
    { "Title",                     true, false, false, false },
    { "SpawnMask",                 true, false, false, false },
    { "Gender",                    true, false, false, false },
    { "Unit State",                true, false, false, false },
    { "Map",                       true, false, false, false },
    { "Area",                      true, false, false, false },
    { "CreatureType",              true, false, false, false },
    { "Spell Known",               true, false, false, false },
    { "Phase",                     true, false, false, false },
    { "Level",                     true, true,  false, false },
    { "Quest Completed",           true, false, false, false },
    { "Near Creature",             true, true,  true,  false },
    { "Near GameObject",           true, true,  false, false },
    { "Object Entry or Guid",      true, true,  true,  false },
    { "Object TypeMask",           true, false, false, false },
    { "Relation",                  true, true,  false, false },
    { "Reaction",                  true, true,  false, false },
    { "Distance",                  true, true,  true,  false },
    { "Alive",                    false, false, false, false },
    { "Health Value",              true, true,  false, false },
    { "Health Pct",                true, true,  false, false },
    { "Realm Achievement",         true, false, false, false },
    { "In Water",                 false, false, false, false },
    { "Terrain Swap",              true, false, false, false },
    { "Sit/stand state",           true, true,  false, false },
    { "Daily Quest Completed",     true, false, false, false },
    { "Charmed",                  false, false, false, false },
    { "Pet type",                  true, false, false, false },
    { "On Taxi",                  false, false, false, false },
    { "Quest state mask",          true, true,  false, false },
    { "Quest objective progress",  true, false, true,  false },
    { "Map Difficulty",            true, false, false, false },
    { "Is Gamemaster",             true, false, false, false },
    { "Object Entry or Guid",      true, true,  true,  false },
    { "Object TypeMask",           true, false, false, false },
    { "BattlePet Species Learned", true, true,  true,  false },
    { "On Scenario Step",          true, false, false, false },
    { "Scene In Progress",         true, false, false, false },
    { "Player Condition",          true, false, false, false },
    { "String ID",                false, false, false, true }
};

ConditionSourceInfo::ConditionSourceInfo(WorldObject const* target0, WorldObject const* target1, WorldObject const* target2)
{
    mConditionTargets[0] = target0;
    mConditionTargets[1] = target1;
    mConditionTargets[2] = target2;
    if (target0)
        mConditionMap = target0->GetMap();
    else if (target1)
        mConditionMap = target1->GetMap();
    else if (target2)
        mConditionMap = target2->GetMap();
    else
        mConditionMap =  nullptr;
    mLastFailedCondition = nullptr;
}

ConditionSourceInfo::ConditionSourceInfo(Map const* map)
{
    std::fill(std::begin(mConditionTargets), std::end(mConditionTargets), nullptr);
    mConditionMap = map;
    mLastFailedCondition = nullptr;
}

std::size_t ConditionId::GetHash() const
{
    std::size_t hashVal = 0;
    Trinity::hash_combine(hashVal, SourceGroup);
    Trinity::hash_combine(hashVal, SourceEntry);
    Trinity::hash_combine(hashVal, SourceId);
    return hashVal;
}

// Checks if object meets the condition
// Can have CONDITION_SOURCE_TYPE_NONE && !mReferenceId if called from a special event (ie: SmartAI)
bool Condition::Meets(ConditionSourceInfo& sourceInfo) const
{
    ASSERT(ConditionTarget < MAX_CONDITION_TARGETS);

    Map const* map = sourceInfo.mConditionMap;
    bool condMeets = false;
    bool needsObject = false;
    switch (ConditionType)
    {
        case CONDITION_NONE:
            condMeets = true;                                    // empty condition, always met
            break;
        case CONDITION_ACTIVE_EVENT:
            condMeets = sGameEventMgr->IsActiveEvent(ConditionValue1);
            break;
        case CONDITION_INSTANCE_INFO:
        {
            if (InstanceMap const* instanceMap = map->ToInstanceMap())
            {
                if (InstanceScript const* instance = instanceMap->GetInstanceScript())
                {
                    switch (ConditionValue3)
                    {
                        case INSTANCE_INFO_DATA:
                            condMeets = instance->GetData(ConditionValue1) == ConditionValue2;
                            break;
                        case INSTANCE_INFO_BOSS_STATE:
                            condMeets = instance->GetBossState(ConditionValue1) == EncounterState(ConditionValue2);
                            break;
                        case INSTANCE_INFO_DATA64:
                            condMeets = instance->GetData64(ConditionValue1) == ConditionValue2;
                            break;
                        default:
                            condMeets = false;
                            break;
                    }
                }
            }
            else if (BattlegroundMap const* bgMap = map->ToBattlegroundMap())
            {
                ZoneScript const* zoneScript = bgMap->GetBG();
                switch (ConditionValue3)
                {
                    case INSTANCE_INFO_DATA:
                        condMeets = zoneScript->GetData(ConditionValue1) == ConditionValue2;
                        break;
                    case INSTANCE_INFO_DATA64:
                        condMeets = zoneScript->GetData64(ConditionValue1) == ConditionValue2;
                        break;
                    default:
                        condMeets = false;
                        break;
                }
            }
            break;
        }
        case CONDITION_MAPID:
            condMeets = map->GetId() == ConditionValue1;
            break;
        case CONDITION_WORLD_STATE:
        {
            condMeets = sWorldStateMgr->GetValue(ConditionValue1, map) == int32(ConditionValue2);
            break;
        }
        case CONDITION_REALM_ACHIEVEMENT:
        {
            AchievementEntry const* achievement = sAchievementStore.LookupEntry(ConditionValue1);
            if (achievement && sAchievementMgr->IsRealmCompleted(achievement))
                condMeets = true;
            break;
        }
        case CONDITION_DIFFICULTY_ID:
        {
            condMeets = map->GetDifficultyID() == ConditionValue1;
            break;
        }
        case CONDITION_SCENARIO_STEP:
        {
            if (InstanceMap const* instanceMap = map->ToInstanceMap())
                if (Scenario const* scenario = instanceMap->GetInstanceScenario())
                    if (ScenarioStepEntry const* step = scenario->GetStep())
                        condMeets = step->ID == ConditionValue1;
            break;
        }
        default:
            needsObject = true;
            break;
    }

    WorldObject const* object = sourceInfo.mConditionTargets[ConditionTarget];
    // object not present, return false
    if (needsObject && !object)
    {
        TC_LOG_DEBUG("condition", "Condition object not found for {}", ToString());
        return false;
    }
    switch (ConditionType)
    {
        case CONDITION_AURA:
        {
            if (Unit const* unit = object->ToUnit())
                condMeets = unit->HasAuraEffect(ConditionValue1, ConditionValue2);
            break;
        }
        case CONDITION_ITEM:
        {
            if (Player const* player = object->ToPlayer())
            {
                // don't allow 0 items (it's checked during table load)
                ASSERT(ConditionValue2);
                bool checkBank = ConditionValue3 ? true : false;
                condMeets = player->HasItemCount(ConditionValue1, ConditionValue2, checkBank);
            }
            break;
        }
        case CONDITION_ITEM_EQUIPPED:
        {
            if (Player const* player = object->ToPlayer())
                condMeets = player->HasItemOrGemWithIdEquipped(ConditionValue1, 1);
            break;
        }
        case CONDITION_ZONEID:
            condMeets = object->GetZoneId() == ConditionValue1;
            break;
        case CONDITION_REPUTATION_RANK:
        {
            if (Player const* player = object->ToPlayer())
            {
                if (FactionEntry const* faction = sFactionStore.LookupEntry(ConditionValue1))
                    condMeets = (ConditionValue2 & (1 << player->GetReputationMgr().GetRank(faction))) != 0;
            }
            break;
        }
        case CONDITION_ACHIEVEMENT:
        {
            if (Player const* player = object->ToPlayer())
                condMeets = player->HasAchieved(ConditionValue1);
            break;
        }
        case CONDITION_TEAM:
        {
            if (Player const* player = object->ToPlayer())
                condMeets = player->GetTeam() == Team(ConditionValue1);
            break;
        }
        case CONDITION_CLASS:
        {
            if (Unit const* unit = object->ToUnit())
                condMeets = (unit->GetClassMask() & ConditionValue1) != 0;
            break;
        }
        case CONDITION_RACE:
        {
            if (Unit const* unit = object->ToUnit())
                condMeets = Trinity::RaceMask<uint32>{ ConditionValue1 }.HasRace(unit->GetRace());
            break;
        }
        case CONDITION_GENDER:
        {
            if (Player const* player = object->ToPlayer())
                condMeets = player->GetNativeGender() == Gender(ConditionValue1);
            break;
        }
        case CONDITION_SKILL:
        {
            if (Player const* player = object->ToPlayer())
                condMeets = player->HasSkill(ConditionValue1) && player->GetBaseSkillValue(ConditionValue1) >= ConditionValue2;
            break;
        }
        case CONDITION_QUESTREWARDED:
        {
            if (Player const* player = object->ToPlayer())
                condMeets = player->GetQuestRewardStatus(ConditionValue1);
            break;
        }
        case CONDITION_QUESTTAKEN:
        {
            if (Player const* player = object->ToPlayer())
            {
                QuestStatus status = player->GetQuestStatus(ConditionValue1);
                condMeets = (status == QUEST_STATUS_INCOMPLETE);
            }
            break;
        }
        case CONDITION_QUEST_COMPLETE:
        {
            if (Player const* player = object->ToPlayer())
            {
                QuestStatus status = player->GetQuestStatus(ConditionValue1);
                condMeets = (status == QUEST_STATUS_COMPLETE && !player->GetQuestRewardStatus(ConditionValue1));
            }
            break;
        }
        case CONDITION_QUEST_NONE:
        {
            if (Player const* player = object->ToPlayer())
            {
                QuestStatus status = player->GetQuestStatus(ConditionValue1);
                condMeets = (status == QUEST_STATUS_NONE);
            }
            break;
        }
        case CONDITION_AREAID:
            condMeets = DB2Manager::IsInArea(object->GetAreaId(), ConditionValue1);
            break;
        case CONDITION_SPELL:
        {
            if (Player const* player = object->ToPlayer())
                condMeets = player->HasSpell(ConditionValue1);
            break;
        }
        case CONDITION_LEVEL:
        {
            if (Unit const* unit = object->ToUnit())
                condMeets = CompareValues(static_cast<ComparisionType>(ConditionValue2), static_cast<uint32>(unit->GetLevel()), ConditionValue1);
            break;
        }
        case CONDITION_DRUNKENSTATE:
        {
            if (Player const* player = object->ToPlayer())
                condMeets = (uint32)Player::GetDrunkenstateByValue(player->GetDrunkValue()) >= ConditionValue1;
            break;
        }
        case CONDITION_NEAR_CREATURE:
        {
            condMeets = object->FindNearestCreature(ConditionValue1, (float)ConditionValue2, bool(!ConditionValue3)) != nullptr;
            break;
        }
        case CONDITION_NEAR_GAMEOBJECT:
        {
            condMeets = object->FindNearestGameObject(ConditionValue1, (float)ConditionValue2) != nullptr;
            break;
        }
        case CONDITION_OBJECT_ENTRY_GUID:
        {
            if (uint32(object->GetTypeId()) == ConditionValue1)
            {
                condMeets = !ConditionValue2 || (object->GetEntry() == ConditionValue2);

                if (ConditionValue3)
                {
                    switch (object->GetTypeId())
                    {
                        case TYPEID_UNIT:
                            condMeets &= object->ToCreature()->GetSpawnId() == ConditionValue3;
                            break;
                        case TYPEID_GAMEOBJECT:
                            condMeets &= object->ToGameObject()->GetSpawnId() == ConditionValue3;
                            break;
                        default:
                            break;
                    }
                }
            }
            break;
        }
        case CONDITION_TYPE_MASK:
        {
            condMeets = object->isType(ConditionValue1);
            break;
        }
        case CONDITION_RELATION_TO:
        {
            if (WorldObject const* toObject = sourceInfo.mConditionTargets[ConditionValue1])
            {
                Unit const* toUnit = toObject->ToUnit();
                Unit const* unit = object->ToUnit();
                if (toUnit && unit)
                {
                    switch (static_cast<RelationType>(ConditionValue2))
                    {
                        case RELATION_SELF:
                            condMeets = unit == toUnit;
                            break;
                        case RELATION_IN_PARTY:
                            condMeets = unit->IsInPartyWith(toUnit);
                            break;
                        case RELATION_IN_RAID_OR_PARTY:
                            condMeets = unit->IsInRaidWith(toUnit);
                            break;
                        case RELATION_OWNED_BY:
                            condMeets = unit->GetOwnerGUID() == toUnit->GetGUID();
                            break;
                        case RELATION_PASSENGER_OF:
                            condMeets = unit->IsOnVehicle(toUnit);
                            break;
                        case RELATION_CREATED_BY:
                            condMeets = unit->GetCreatorGUID() == toUnit->GetGUID();
                            break;
                        default:
                            break;
                    }
                }
            }
            break;
        }
        case CONDITION_REACTION_TO:
        {
            if (WorldObject const* toObject = sourceInfo.mConditionTargets[ConditionValue1])
            {
                Unit const* toUnit = toObject->ToUnit();
                Unit const* unit = object->ToUnit();
                if (toUnit && unit)
                    condMeets = ((1 << unit->GetReactionTo(toUnit)) & ConditionValue2) != 0;
            }
            break;
        }
        case CONDITION_DISTANCE_TO:
        {
            if (WorldObject const* toObject = sourceInfo.mConditionTargets[ConditionValue1])
                condMeets = CompareValues(static_cast<ComparisionType>(ConditionValue3), object->GetDistance(toObject), static_cast<float>(ConditionValue2));
            break;
        }
        case CONDITION_ALIVE:
        {
            if (Unit const* unit = object->ToUnit())
                condMeets = unit->IsAlive();
            break;
        }
        case CONDITION_HP_VAL:
        {
            if (Unit const* unit = object->ToUnit())
                condMeets = CompareValues(static_cast<ComparisionType>(ConditionValue2), unit->GetHealth(), static_cast<uint64>(ConditionValue1));
            break;
        }
        case CONDITION_HP_PCT:
        {
            if (Unit const* unit = object->ToUnit())
                condMeets = CompareValues(static_cast<ComparisionType>(ConditionValue2), unit->GetHealthPct(), static_cast<float>(ConditionValue1));
            break;
        }
        case CONDITION_PHASEID:
        {
            condMeets = object->GetPhaseShift().HasPhase(ConditionValue1);
            break;
        }
        case CONDITION_TITLE:
        {
            if (Player const* player = object->ToPlayer())
                condMeets = player->HasTitle(ConditionValue1);
            break;
        }
        case CONDITION_UNIT_STATE:
        {
            if (Unit const* unit = object->ToUnit())
                condMeets = unit->HasUnitState(ConditionValue1);
            break;
        }
        case CONDITION_CREATURE_TYPE:
        {
            if (Creature const* creature = object->ToCreature())
                condMeets = creature->GetCreatureTemplate()->type == ConditionValue1;
            break;
        }
        case CONDITION_IN_WATER:
        {
            if (Unit const* unit = object->ToUnit())
                condMeets = unit->IsInWater();
            break;
        }
        case CONDITION_TERRAIN_SWAP:
        {
            condMeets = object->GetPhaseShift().HasVisibleMapId(ConditionValue1);
            break;
        }
        case CONDITION_STAND_STATE:
        {
            if (Unit const* unit = object->ToUnit())
            {
                if (ConditionValue1 == 0)
                    condMeets = (unit->GetStandState() == UnitStandStateType(ConditionValue2));
                else if (ConditionValue2 == 0)
                    condMeets = unit->IsStandState();
                else if (ConditionValue2 == 1)
                    condMeets = unit->IsSitState();
            }
            break;
        }
        case CONDITION_DAILY_QUEST_DONE:
        {
            if (Player const* player = object->ToPlayer())
                condMeets = player->IsDailyQuestDone(ConditionValue1);
            break;
        }
        case CONDITION_CHARMED:
        {
            if (Unit const* unit = object->ToUnit())
                condMeets = unit->IsCharmed();
            break;
        }
        case CONDITION_PET_TYPE:
        {
            if (Player const* player = object->ToPlayer())
                if (Pet const* pet = player->GetPet())
                    condMeets = (((1 << pet->getPetType()) & ConditionValue1) != 0);
            break;
        }
        case CONDITION_TAXI:
        {
            if (Player const* player = object->ToPlayer())
                condMeets = player->IsInFlight();
            break;
        }
        case CONDITION_QUESTSTATE:
        {
            if (Player const* player = object->ToPlayer())
            {
                if (
                    ((ConditionValue2 & (1 << QUEST_STATUS_NONE)) && (player->GetQuestStatus(ConditionValue1) == QUEST_STATUS_NONE)) ||
                    ((ConditionValue2 & (1 << QUEST_STATUS_COMPLETE)) && (player->GetQuestStatus(ConditionValue1) == QUEST_STATUS_COMPLETE)) ||
                    ((ConditionValue2 & (1 << QUEST_STATUS_INCOMPLETE)) && (player->GetQuestStatus(ConditionValue1) == QUEST_STATUS_INCOMPLETE)) ||
                    ((ConditionValue2 & (1 << QUEST_STATUS_FAILED)) && (player->GetQuestStatus(ConditionValue1) == QUEST_STATUS_FAILED)) ||
                    ((ConditionValue2 & (1 << QUEST_STATUS_REWARDED)) && player->GetQuestRewardStatus(ConditionValue1))
                )
                    condMeets = true;
            }
            break;
        }
        case CONDITION_QUEST_OBJECTIVE_PROGRESS:
        {
            if (Player const* player = object->ToPlayer())
            {
                QuestObjective const* obj = sObjectMgr->GetQuestObjective(ConditionValue1);
                if (!obj)
                    break;

                Quest const* quest = sObjectMgr->GetQuestTemplate(obj->QuestID);
                if (!quest)
                    break;

                uint16 slot = player->FindQuestSlot(obj->QuestID);
                if (slot >= MAX_QUEST_LOG_SIZE)
                    break;

                condMeets = player->GetQuestSlotObjectiveData(slot, *obj) == int32(ConditionValue3);
            }
            break;
        }
        case CONDITION_GAMEMASTER:
        {
            if (Player const* player = object->ToPlayer())
            {
                if (ConditionValue1 == 1)
                    condMeets = player->CanBeGameMaster();
                else
                    condMeets = player->IsGameMaster();
            }
            break;
        }
        case CONDITION_BATTLE_PET_COUNT:
        {
            if (Player const* player = object->ToPlayer())
                condMeets = CompareValues(static_cast<ComparisionType>(ConditionValue3),
                    player->GetSession()->GetBattlePetMgr()->GetPetCount(sBattlePetSpeciesStore.AssertEntry(ConditionValue1), player->GetGUID()),
                    static_cast<uint8>(ConditionValue2));
            break;
        }
        case CONDITION_SCENE_IN_PROGRESS:
        {
            if (Player const* player = object->ToPlayer())
                condMeets = player->GetSceneMgr().GetActiveSceneCount(ConditionValue1) > 0;
            break;
        }
        case CONDITION_PLAYER_CONDITION:
        {
            if (Player const* player = object->ToPlayer())
                if (PlayerConditionEntry const* playerCondition = sPlayerConditionStore.LookupEntry(ConditionValue1))
                    condMeets = ConditionMgr::IsPlayerMeetingCondition(player, playerCondition);
            break;
        }
        case CONDITION_PRIVATE_OBJECT:
        {
            condMeets = !object->GetPrivateObjectOwner().IsEmpty();
            break;
        }
        case CONDITION_STRING_ID:
        {
            if (Creature const* creature = object->ToCreature())
                condMeets = creature->HasStringId(ConditionStringValue1);
            else if (GameObject const* go = object->ToGameObject())
                condMeets = go->HasStringId(ConditionStringValue1);
            break;
        }
        default:
            break;
    }

    if (NegativeCondition)
        condMeets = !condMeets;

    if (!condMeets)
        sourceInfo.mLastFailedCondition = this;

    return condMeets && sScriptMgr->OnConditionCheck(this, sourceInfo); // Returns true by default.;
}

uint32 Condition::GetSearcherTypeMaskForCondition() const
{
    // build mask of types for which condition can return true
    // this is used for speeding up gridsearches
    if (NegativeCondition)
        return (GRID_MAP_TYPE_MASK_ALL);
    uint32 mask = 0;
    switch (ConditionType)
    {
        case CONDITION_NONE:
            mask |= GRID_MAP_TYPE_MASK_ALL;
            break;
        case CONDITION_AURA:
            mask |= GRID_MAP_TYPE_MASK_CREATURE | GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_ITEM:
            mask |= GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_ITEM_EQUIPPED:
            mask |= GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_ZONEID:
            mask |= GRID_MAP_TYPE_MASK_ALL;
            break;
        case CONDITION_REPUTATION_RANK:
            mask |= GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_ACHIEVEMENT:
            mask |= GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_TEAM:
            mask |= GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_CLASS:
            mask |= GRID_MAP_TYPE_MASK_CREATURE | GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_RACE:
            mask |= GRID_MAP_TYPE_MASK_CREATURE | GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_SKILL:
            mask |= GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_QUESTREWARDED:
            mask |= GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_QUESTTAKEN:
            mask |= GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_QUEST_COMPLETE:
            mask |= GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_QUEST_NONE:
            mask |= GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_ACTIVE_EVENT:
            mask |= GRID_MAP_TYPE_MASK_ALL;
            break;
        case CONDITION_INSTANCE_INFO:
            mask |= GRID_MAP_TYPE_MASK_ALL;
            break;
        case CONDITION_MAPID:
            mask |= GRID_MAP_TYPE_MASK_ALL;
            break;
        case CONDITION_AREAID:
            mask |= GRID_MAP_TYPE_MASK_ALL;
            break;
        case CONDITION_SPELL:
            mask |= GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_LEVEL:
            mask |= GRID_MAP_TYPE_MASK_CREATURE | GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_DRUNKENSTATE:
            mask |= GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_NEAR_CREATURE:
            mask |= GRID_MAP_TYPE_MASK_ALL;
            break;
        case CONDITION_NEAR_GAMEOBJECT:
            mask |= GRID_MAP_TYPE_MASK_ALL;
            break;
        case CONDITION_OBJECT_ENTRY_GUID:
            switch (ConditionValue1)
            {
                case TYPEID_UNIT:
                    mask |= GRID_MAP_TYPE_MASK_CREATURE;
                    break;
                case TYPEID_PLAYER:
                    mask |= GRID_MAP_TYPE_MASK_PLAYER;
                    break;
                case TYPEID_GAMEOBJECT:
                    mask |= GRID_MAP_TYPE_MASK_GAMEOBJECT;
                    break;
                case TYPEID_CORPSE:
                    mask |= GRID_MAP_TYPE_MASK_CORPSE;
                    break;
                case TYPEID_AREATRIGGER:
                    mask |= GRID_MAP_TYPE_MASK_AREATRIGGER;
                    break;
                default:
                    break;
            }
            break;
        case CONDITION_TYPE_MASK:
            if (ConditionValue1 & TYPEMASK_UNIT)
                mask |= GRID_MAP_TYPE_MASK_CREATURE | GRID_MAP_TYPE_MASK_PLAYER;
            if (ConditionValue1 & TYPEMASK_PLAYER)
                mask |= GRID_MAP_TYPE_MASK_PLAYER;
            if (ConditionValue1 & TYPEMASK_GAMEOBJECT)
                mask |= GRID_MAP_TYPE_MASK_GAMEOBJECT;
            if (ConditionValue1 & TYPEMASK_CORPSE)
                mask |= GRID_MAP_TYPE_MASK_CORPSE;
            if (ConditionValue1 & TYPEMASK_AREATRIGGER)
                mask |= GRID_MAP_TYPE_MASK_AREATRIGGER;
            break;
        case CONDITION_RELATION_TO:
            mask |= GRID_MAP_TYPE_MASK_CREATURE | GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_REACTION_TO:
            mask |= GRID_MAP_TYPE_MASK_CREATURE | GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_DISTANCE_TO:
            mask |= GRID_MAP_TYPE_MASK_ALL;
            break;
        case CONDITION_ALIVE:
            mask |= GRID_MAP_TYPE_MASK_CREATURE | GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_HP_VAL:
            mask |= GRID_MAP_TYPE_MASK_CREATURE | GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_HP_PCT:
            mask |= GRID_MAP_TYPE_MASK_CREATURE | GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_WORLD_STATE:
            mask |= GRID_MAP_TYPE_MASK_ALL;
            break;
        case CONDITION_PHASEID:
            mask |= GRID_MAP_TYPE_MASK_ALL;
            break;
        case CONDITION_TITLE:
            mask |= GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_GENDER:
            mask |= GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_UNIT_STATE:
            mask |= GRID_MAP_TYPE_MASK_CREATURE | GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_CREATURE_TYPE:
            mask |= GRID_MAP_TYPE_MASK_CREATURE;
            break;
        case CONDITION_REALM_ACHIEVEMENT:
            mask |= GRID_MAP_TYPE_MASK_ALL;
            break;
        case CONDITION_IN_WATER:
            mask |= GRID_MAP_TYPE_MASK_CREATURE | GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_TERRAIN_SWAP:
            mask |= GRID_MAP_TYPE_MASK_ALL;
            break;
        case CONDITION_STAND_STATE:
            mask |= GRID_MAP_TYPE_MASK_CREATURE | GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_DAILY_QUEST_DONE:
            mask |= GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_CHARMED:
            mask |= GRID_MAP_TYPE_MASK_CREATURE | GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_PET_TYPE:
            mask |= GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_TAXI:
            mask |= GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_QUESTSTATE:
            mask |= GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_QUEST_OBJECTIVE_PROGRESS:
            mask |= GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_DIFFICULTY_ID:
            mask |= GRID_MAP_TYPE_MASK_ALL;
            break;
        case CONDITION_GAMEMASTER:
            mask |= GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_BATTLE_PET_COUNT:
            mask |= GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_SCENARIO_STEP:
            mask |= GRID_MAP_TYPE_MASK_ALL;
            break;
        case CONDITION_SCENE_IN_PROGRESS:
            mask |= GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_PLAYER_CONDITION:
            mask |= GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_PRIVATE_OBJECT:
            mask |= GRID_MAP_TYPE_MASK_ALL & ~GRID_MAP_TYPE_MASK_PLAYER;
            break;
        default:
            ABORT_MSG("Condition::GetSearcherTypeMaskForCondition - missing condition handling!");
            break;
    }
    return mask;
}

uint32 Condition::GetMaxAvailableConditionTargets() const
{
    // returns number of targets which are available for given source type
    switch (SourceType)
    {
        case CONDITION_SOURCE_TYPE_SPELL:
        case CONDITION_SOURCE_TYPE_SPELL_IMPLICIT_TARGET:
        case CONDITION_SOURCE_TYPE_CREATURE_TEMPLATE_VEHICLE:
        case CONDITION_SOURCE_TYPE_VEHICLE_SPELL:
        case CONDITION_SOURCE_TYPE_SPELL_CLICK_EVENT:
        case CONDITION_SOURCE_TYPE_GOSSIP_MENU:
        case CONDITION_SOURCE_TYPE_GOSSIP_MENU_OPTION:
        case CONDITION_SOURCE_TYPE_SMART_EVENT:
        case CONDITION_SOURCE_TYPE_NPC_VENDOR:
        case CONDITION_SOURCE_TYPE_SPELL_PROC:
            return 2;
        default:
            return 1;
    }
}

std::string Condition::ToString(bool ext /*= false*/) const
{
    std::ostringstream ss;
    ss << "[Condition ";
    ss << "SourceType: " << SourceType;
    if (SourceType < CONDITION_SOURCE_TYPE_MAX_DB_ALLOWED)
        ss << " (" << ConditionMgr::StaticSourceTypeData[SourceType] << ")";
    else if (SourceType == CONDITION_SOURCE_TYPE_REFERENCE_CONDITION)
        ss << " (Reference)";
    else
        ss << " (Unknown)";
    if (ConditionMgr::CanHaveSourceGroupSet(SourceType))
        ss << ", SourceGroup: " << SourceGroup;
    ss << ", SourceEntry: " << SourceEntry;
    if (ConditionMgr::CanHaveSourceIdSet(SourceType))
        ss << ", SourceId: " << SourceId;

    if (ext)
    {
        ss << ", ConditionType: " << ConditionType;
        if (ConditionType < CONDITION_MAX)
            ss << " (" << ConditionMgr::StaticConditionTypeData[ConditionType].Name << ")";
        else
            ss << " (Unknown)";
    }

    ss << "]";
    return ss.str();
}

ConditionMgr::ConditionMgr() { }

ConditionMgr::~ConditionMgr()
{
    Clean();
}

uint32 ConditionMgr::GetSearcherTypeMaskForConditionList(ConditionContainer const& conditions) const
{
    if (conditions.empty())
        return GRID_MAP_TYPE_MASK_ALL;
    //     groupId, typeMask
    std::map<uint32, uint32> elseGroupSearcherTypeMasks;
    for (ConditionContainer::const_iterator i = conditions.begin(); i != conditions.end(); ++i)
    {
        // no point of having not loaded conditions in list
        ASSERT(i->isLoaded() && "ConditionMgr::GetSearcherTypeMaskForConditionList - not yet loaded condition found in list");
        std::map<uint32, uint32>::const_iterator itr = elseGroupSearcherTypeMasks.find(i->ElseGroup);
        // group not filled yet, fill with widest mask possible
        if (itr == elseGroupSearcherTypeMasks.end())
            elseGroupSearcherTypeMasks[i->ElseGroup] = GRID_MAP_TYPE_MASK_ALL;
        // no point of checking anymore, empty mask
        else if (!itr->second)
            continue;

        if (i->ReferenceId) // handle reference
        {
            auto ref = ConditionStore[CONDITION_SOURCE_TYPE_REFERENCE_CONDITION].find({ i->ReferenceId, 0, 0 });
            ASSERT(ref != ConditionStore[CONDITION_SOURCE_TYPE_REFERENCE_CONDITION].end() && "ConditionMgr::GetSearcherTypeMaskForConditionList - incorrect reference");
            elseGroupSearcherTypeMasks[i->ElseGroup] &= GetSearcherTypeMaskForConditionList(*(ref->second));
        }
        else // handle normal condition
        {
            // object will match conditions in one ElseGroupStore only when it matches all of them
            // so, let's find a smallest possible mask which satisfies all conditions
            elseGroupSearcherTypeMasks[i->ElseGroup] &= i->GetSearcherTypeMaskForCondition();
        }
    }
    // object will match condition when one of the checks in ElseGroupStore is matching
    // so, let's include all possible masks
    uint32 mask = 0;
    for (std::map<uint32, uint32>::const_iterator i = elseGroupSearcherTypeMasks.begin(); i != elseGroupSearcherTypeMasks.end(); ++i)
        mask |= i->second;

    return mask;
}

bool ConditionMgr::IsObjectMeetToConditionList(ConditionSourceInfo& sourceInfo, ConditionContainer const& conditions) const
{
    //     groupId, groupCheckPassed
    std::map<uint32, bool> elseGroupStore;
    for (Condition const& condition : conditions)
    {
        TC_LOG_DEBUG("condition", "ConditionMgr::IsPlayerMeetToConditionList {} val1: {}", condition.ToString(), condition.ConditionValue1);
        if (condition.isLoaded())
        {
            //! Find ElseGroup in ElseGroupStore
            std::map<uint32, bool>::iterator itr = elseGroupStore.try_emplace(condition.ElseGroup, true).first;
            if (!itr->second) //! If another condition in this group was unmatched before this, don't bother checking (the group is false anyway)
                continue;

            if (condition.ReferenceId)//handle reference
            {
                auto ref = ConditionStore[CONDITION_SOURCE_TYPE_REFERENCE_CONDITION].find({ condition.ReferenceId, 0, 0 });
                if (ref != ConditionStore[CONDITION_SOURCE_TYPE_REFERENCE_CONDITION].end())
                {
                    if (!IsObjectMeetToConditionList(sourceInfo, *ref->second))
                        itr->second = false;
                }
                else
                {
                    TC_LOG_DEBUG("condition", "ConditionMgr::IsPlayerMeetToConditionList {} Reference template -{} not found",
                        condition.ToString(), condition.ReferenceId); // checked at loading, should never happen
                }

            }
            else //handle normal condition
            {
                if (!condition.Meets(sourceInfo))
                    itr->second = false;
            }
        }
    }
    for (std::map<uint32, bool>::const_iterator i = elseGroupStore.begin(); i != elseGroupStore.end(); ++i)
        if (i->second)
            return true;

    return false;
}

bool ConditionMgr::IsObjectMeetToConditions(WorldObject const* object, ConditionContainer const& conditions) const
{
    ConditionSourceInfo srcInfo = ConditionSourceInfo(object);
    return IsObjectMeetToConditions(srcInfo, conditions);
}

bool ConditionMgr::IsObjectMeetToConditions(WorldObject const* object1, WorldObject const* object2, ConditionContainer const& conditions) const
{
    ConditionSourceInfo srcInfo = ConditionSourceInfo(object1, object2);
    return IsObjectMeetToConditions(srcInfo, conditions);
}

bool ConditionMgr::IsObjectMeetToConditions(ConditionSourceInfo& sourceInfo, ConditionContainer const& conditions) const
{
    if (conditions.empty())
        return true;

    TC_LOG_DEBUG("condition", "ConditionMgr::IsObjectMeetToConditions");
    return IsObjectMeetToConditionList(sourceInfo, conditions);
}

bool ConditionMgr::CanHaveSourceGroupSet(ConditionSourceType sourceType)
{
    return (sourceType == CONDITION_SOURCE_TYPE_CREATURE_LOOT_TEMPLATE ||
            sourceType == CONDITION_SOURCE_TYPE_DISENCHANT_LOOT_TEMPLATE ||
            sourceType == CONDITION_SOURCE_TYPE_FISHING_LOOT_TEMPLATE ||
            sourceType == CONDITION_SOURCE_TYPE_GAMEOBJECT_LOOT_TEMPLATE ||
            sourceType == CONDITION_SOURCE_TYPE_ITEM_LOOT_TEMPLATE ||
            sourceType == CONDITION_SOURCE_TYPE_MAIL_LOOT_TEMPLATE ||
            sourceType == CONDITION_SOURCE_TYPE_MILLING_LOOT_TEMPLATE ||
            sourceType == CONDITION_SOURCE_TYPE_PICKPOCKETING_LOOT_TEMPLATE ||
            sourceType == CONDITION_SOURCE_TYPE_PROSPECTING_LOOT_TEMPLATE ||
            sourceType == CONDITION_SOURCE_TYPE_REFERENCE_LOOT_TEMPLATE ||
            sourceType == CONDITION_SOURCE_TYPE_SKINNING_LOOT_TEMPLATE ||
            sourceType == CONDITION_SOURCE_TYPE_SPELL_LOOT_TEMPLATE ||
            sourceType == CONDITION_SOURCE_TYPE_GOSSIP_MENU ||
            sourceType == CONDITION_SOURCE_TYPE_GOSSIP_MENU_OPTION ||
            sourceType == CONDITION_SOURCE_TYPE_VEHICLE_SPELL ||
            sourceType == CONDITION_SOURCE_TYPE_SPELL_IMPLICIT_TARGET ||
            sourceType == CONDITION_SOURCE_TYPE_SPELL_CLICK_EVENT ||
            sourceType == CONDITION_SOURCE_TYPE_SMART_EVENT ||
            sourceType == CONDITION_SOURCE_TYPE_NPC_VENDOR ||
            sourceType == CONDITION_SOURCE_TYPE_PHASE ||
            sourceType == CONDITION_SOURCE_TYPE_GRAVEYARD ||
            sourceType == CONDITION_SOURCE_TYPE_AREATRIGGER ||
            sourceType == CONDITION_SOURCE_TYPE_TRAINER_SPELL ||
            sourceType == CONDITION_SOURCE_TYPE_OBJECT_ID_VISIBILITY ||
            sourceType == CONDITION_SOURCE_TYPE_REFERENCE_CONDITION);
}

bool ConditionMgr::CanHaveSourceIdSet(ConditionSourceType sourceType)
{
    return (sourceType == CONDITION_SOURCE_TYPE_SMART_EVENT);
}

bool ConditionMgr::CanHaveConditionType(ConditionSourceType sourceType, ConditionTypes conditionType)
{
    switch (sourceType)
    {
        case CONDITION_SOURCE_TYPE_SPAWN_GROUP:
            switch (conditionType)
            {
                case CONDITION_NONE:
                case CONDITION_ACTIVE_EVENT:
                case CONDITION_INSTANCE_INFO:
                case CONDITION_MAPID:
                case CONDITION_WORLD_STATE:
                case CONDITION_REALM_ACHIEVEMENT:
                case CONDITION_DIFFICULTY_ID:
                case CONDITION_SCENARIO_STEP:
                    return true;
                default:
                    return false;
            }
            break;
        default:
            break;
    }
    return true;
}

bool ConditionMgr::IsObjectMeetingNotGroupedConditions(ConditionSourceType sourceType, uint32 entry, ConditionSourceInfo& sourceInfo) const
{
    if (sourceType > CONDITION_SOURCE_TYPE_NONE && sourceType < CONDITION_SOURCE_TYPE_MAX)
    {
        auto i = ConditionStore[sourceType].find({ 0, int32(entry), 0 });
        if (i != ConditionStore[sourceType].end())
        {
            TC_LOG_DEBUG("condition", "GetConditionsForNotGroupedEntry: found conditions for type {} and entry {}", uint32(sourceType), entry);
            return IsObjectMeetToConditions(sourceInfo, *i->second);
        }
    }

    return true;
}

bool ConditionMgr::IsObjectMeetingNotGroupedConditions(ConditionSourceType sourceType, uint32 entry, WorldObject const* target0, WorldObject const* target1 /*= nullptr*/, WorldObject const* target2 /*= nullptr*/) const
{
    ConditionSourceInfo conditionSource(target0, target1, target2);
    return IsObjectMeetingNotGroupedConditions(sourceType, entry, conditionSource);
}

bool ConditionMgr::IsMapMeetingNotGroupedConditions(ConditionSourceType sourceType, uint32 entry, Map const* map) const
{
    ConditionSourceInfo conditionSource(map);
    return IsObjectMeetingNotGroupedConditions(sourceType, entry, conditionSource);
}

bool ConditionMgr::HasConditionsForNotGroupedEntry(ConditionSourceType sourceType, uint32 entry) const
{
    if (sourceType > CONDITION_SOURCE_TYPE_NONE && sourceType < CONDITION_SOURCE_TYPE_MAX)
        return ConditionStore[sourceType].contains({ 0, int32(entry), 0 });

    return false;
}

bool ConditionMgr::IsObjectMeetingSpellClickConditions(uint32 creatureId, uint32 spellId, WorldObject const* clicker, WorldObject const* target) const
{
    auto itr = ConditionStore[CONDITION_SOURCE_TYPE_SPELL_CLICK_EVENT].find({ creatureId, int32(spellId), 0 });
    if (itr != ConditionStore[CONDITION_SOURCE_TYPE_SPELL_CLICK_EVENT].end())
    {
        TC_LOG_DEBUG("condition", "IsObjectMeetingSpellClickConditions: found conditions for SpellClickEvent entry {} spell {}", creatureId, spellId);
        ConditionSourceInfo sourceInfo(clicker, target);
        return IsObjectMeetToConditions(sourceInfo, *itr->second);
    }
    return true;
}

bool ConditionMgr::HasConditionsForSpellClickEvent(uint32 creatureId, uint32 spellId) const
{
    auto itr = ConditionStore[CONDITION_SOURCE_TYPE_SPELL_CLICK_EVENT].find({ creatureId, int32(spellId), 0 });
    if (itr != ConditionStore[CONDITION_SOURCE_TYPE_SPELL_CLICK_EVENT].end())
    {
        TC_LOG_DEBUG("condition", "HasConditionsForSpellClickEvent: found conditions for SpellClickEvent entry {} spell {}", creatureId, spellId);
        return true;
    }
    return false;
}

bool ConditionMgr::IsObjectMeetingVehicleSpellConditions(uint32 creatureId, uint32 spellId, Player const* player, Unit const* vehicle) const
{
    auto itr = ConditionStore[CONDITION_SOURCE_TYPE_VEHICLE_SPELL].find({ creatureId, int32(spellId), 0 });
    if (itr != ConditionStore[CONDITION_SOURCE_TYPE_VEHICLE_SPELL].end())
    {
        TC_LOG_DEBUG("condition", "GetConditionsForVehicleSpell: found conditions for Vehicle entry {} spell {}", creatureId, spellId);
        ConditionSourceInfo sourceInfo(player, vehicle);
        return IsObjectMeetToConditions(sourceInfo, *itr->second);
    }
    return true;
}

bool ConditionMgr::IsObjectMeetingSmartEventConditions(int64 entryOrGuid, uint32 eventId, uint32 sourceType, Unit const* unit, WorldObject const* baseObject) const
{
    auto itr = ConditionStore[CONDITION_SOURCE_TYPE_SMART_EVENT].find({ eventId + 1, int32(entryOrGuid), sourceType });
    if (itr != ConditionStore[CONDITION_SOURCE_TYPE_SMART_EVENT].end())
    {
        TC_LOG_DEBUG("condition", "GetConditionsForSmartEvent: found conditions for Smart Event entry or guid {} eventId {}", entryOrGuid, eventId);
        ConditionSourceInfo sourceInfo(unit, baseObject);
        return IsObjectMeetToConditions(sourceInfo, *itr->second);
    }
    return true;
}

bool ConditionMgr::IsObjectMeetingVendorItemConditions(uint32 creatureId, uint32 itemId, Player const* player, Creature const* vendor) const
{
    auto itr = ConditionStore[CONDITION_SOURCE_TYPE_NPC_VENDOR].find({ creatureId, int32(itemId), 0 });
    if (itr != ConditionStore[CONDITION_SOURCE_TYPE_NPC_VENDOR].end())
    {
        TC_LOG_DEBUG("condition", "GetConditionsForNpcVendor: found conditions for creature entry {} item {}", creatureId, itemId);
        ConditionSourceInfo sourceInfo(player, vendor);
        return IsObjectMeetToConditions(sourceInfo, *itr->second);
    }
    return true;
}

bool ConditionMgr::IsSpellUsedInSpellClickConditions(uint32 spellId) const
{
    return SpellsUsedInSpellClickConditions.find(spellId) != SpellsUsedInSpellClickConditions.end();
}

ConditionContainer const* ConditionMgr::GetConditionsForAreaTrigger(uint32 areaTriggerId, bool isServerSide) const
{
    auto itr = ConditionStore[CONDITION_SOURCE_TYPE_AREATRIGGER].find({ areaTriggerId, isServerSide ? 1 : 0, 0 });
    if (itr != ConditionStore[CONDITION_SOURCE_TYPE_AREATRIGGER].end())
        return itr->second.get();
    return nullptr;
}

bool ConditionMgr::IsObjectMeetingTrainerSpellConditions(uint32 trainerId, uint32 spellId, Player* player) const
{
    auto itr = ConditionStore[CONDITION_SOURCE_TYPE_NPC_VENDOR].find({ trainerId, int32(spellId), 0 });
    if (itr != ConditionStore[CONDITION_SOURCE_TYPE_NPC_VENDOR].end())
    {
        TC_LOG_DEBUG("condition", "IsObjectMeetingTrainerSpellConditions: found conditions for trainer id {} spell {}", trainerId, spellId);
        return IsObjectMeetToConditions(player, *itr->second);
    }
    return true;
}

bool ConditionMgr::IsObjectMeetingVisibilityByObjectIdConditions(uint32 objectType, uint32 entry, WorldObject const* seer) const
{
    auto itr = ConditionStore[CONDITION_SOURCE_TYPE_OBJECT_ID_VISIBILITY].find({ objectType, int32(entry), 0 });
    if (itr != ConditionStore[CONDITION_SOURCE_TYPE_OBJECT_ID_VISIBILITY].end())
    {
        TC_LOG_DEBUG("condition", "IsObjectMeetingVisibilityByObjectIdConditions: found conditions for objectType {} entry {}", objectType, entry);
        return IsObjectMeetToConditions(seer, *itr->second);
    }
    return true;
}

ConditionMgr* ConditionMgr::instance()
{
    static ConditionMgr instance;
    return &instance;
}

void ConditionMgr::LoadConditions(bool isReload)
{
    uint32 oldMSTime = getMSTime();

    Clean();

    //must clear all custom handled cases (groupped types) before reload
    if (isReload)
    {
        sSpellMgr->UnloadSpellInfoImplicitTargetConditionLists();

        sObjectMgr->UnloadPhaseConditions();
    }

    QueryResult result = WorldDatabase.Query("SELECT SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, "
                                             "ConditionValue1, ConditionValue2, ConditionValue3, ConditionStringValue1, "
                                             "NegativeCondition, ErrorType, ErrorTextId, ScriptName FROM conditions");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 conditions. DB table `conditions` is empty!");
        return;
    }

    uint32 count = 0;

    auto getOrInitConditions = [this](ConditionSourceType sourceType, ConditionId const& id)
    {
        auto [itr, inserted] = ConditionStore[sourceType].try_emplace(id, nullptr);
        if (inserted)
            itr->second = std::make_shared<std::vector<Condition>>();
        return itr->second;
    };

    do
    {
        Field* fields = result->Fetch();

        Condition cond;
        int32 iSourceTypeOrReferenceId  = fields[0].GetInt32();
        cond.SourceGroup               = fields[1].GetUInt32();
        cond.SourceEntry               = fields[2].GetInt32();
        cond.SourceId                  = fields[3].GetInt32();
        cond.ElseGroup                 = fields[4].GetUInt32();
        int32 iConditionTypeOrReference = fields[5].GetInt32();
        cond.ConditionTarget           = fields[6].GetUInt8();
        cond.ConditionValue1           = fields[7].GetUInt32();
        cond.ConditionValue2           = fields[8].GetUInt32();
        cond.ConditionValue3           = fields[9].GetUInt32();
        cond.ConditionStringValue1     = fields[10].GetString();
        cond.NegativeCondition         = fields[11].GetBool();
        cond.ErrorType                 = fields[12].GetUInt32();
        cond.ErrorTextId               = fields[13].GetUInt32();
        cond.ScriptId                  = sObjectMgr->GetScriptId(fields[14].GetString());

        if (iConditionTypeOrReference >= 0)
            cond.ConditionType = ConditionTypes(iConditionTypeOrReference);

        if (iSourceTypeOrReferenceId >= 0)
            cond.SourceType = ConditionSourceType(iSourceTypeOrReferenceId);

        if (iConditionTypeOrReference < 0)//it has a reference
        {
            if (iConditionTypeOrReference == iSourceTypeOrReferenceId)//self referencing, skip
            {
                TC_LOG_ERROR("sql.sql", "Condition reference {} is referencing self, skipped", iSourceTypeOrReferenceId);
                continue;
            }

            cond.ReferenceId = uint32(-iConditionTypeOrReference);

            char const* rowType = "reference template";
            if (iSourceTypeOrReferenceId >= 0)
                rowType = "reference";
            //check for useless data
            if (cond.ConditionTarget)
                TC_LOG_ERROR("sql.sql", "Condition {} {} has useless data in ConditionTarget ({})!", rowType, iSourceTypeOrReferenceId, cond.ConditionTarget);
            if (cond.ConditionValue1)
                TC_LOG_ERROR("sql.sql", "Condition {} {} has useless data in value1 ({})!", rowType, iSourceTypeOrReferenceId, cond.ConditionValue1);
            if (cond.ConditionValue2)
                TC_LOG_ERROR("sql.sql", "Condition {} {} has useless data in value2 ({})!", rowType, iSourceTypeOrReferenceId, cond.ConditionValue2);
            if (cond.ConditionValue3)
                TC_LOG_ERROR("sql.sql", "Condition {} {} has useless data in value3 ({})!", rowType, iSourceTypeOrReferenceId, cond.ConditionValue3);
            if (cond.NegativeCondition)
                TC_LOG_ERROR("sql.sql", "Condition {} {} has useless data in NegativeCondition ({})!", rowType, iSourceTypeOrReferenceId, cond.NegativeCondition);
        }
        else if (!isConditionTypeValid(&cond))//doesn't have reference, validate ConditionType
            continue;

        if (iSourceTypeOrReferenceId < 0)//it is a reference template
        {
            if (cond.SourceGroup)
                TC_LOG_ERROR("sql.sql", "Condition reference template {} has useless data in SourceGroup ({})!", iSourceTypeOrReferenceId, cond.SourceGroup);
            if (cond.SourceEntry)
                TC_LOG_ERROR("sql.sql", "Condition reference template {} has useless data in SourceEntry ({})!", iSourceTypeOrReferenceId, cond.SourceEntry);
            if (cond.SourceId)
                TC_LOG_ERROR("sql.sql", "Condition reference template {} has useless data in SourceId ({})!", iSourceTypeOrReferenceId, cond.SourceId);

            cond.SourceType = CONDITION_SOURCE_TYPE_REFERENCE_CONDITION;
            cond.SourceGroup = -iSourceTypeOrReferenceId;
        }
        else if (!isSourceTypeValid(&cond)) //if not a reference and SourceType is invalid, skip
            continue;

        //Grouping is only allowed for some types (loot templates, gossip menus, gossip items)
        if (cond.SourceGroup && !CanHaveSourceGroupSet(cond.SourceType))
        {
            TC_LOG_ERROR("sql.sql", "{} has not allowed value of SourceGroup = {}!", cond.ToString(), cond.SourceGroup);
            continue;
        }
        if (cond.SourceId && !CanHaveSourceIdSet(cond.SourceType))
        {
            TC_LOG_ERROR("sql.sql", "{} has not allowed value of SourceId = {}!", cond.ToString(), cond.SourceId);
            continue;
        }

        if (cond.ErrorType && cond.SourceType != CONDITION_SOURCE_TYPE_SPELL)
        {
            TC_LOG_ERROR("sql.sql", "{} can't have ErrorType ({}), set to 0!", cond.ToString(), cond.ErrorType);
            cond.ErrorType = 0;
        }

        if (cond.ErrorTextId && !cond.ErrorType)
        {
            TC_LOG_ERROR("sql.sql", "{} has any ErrorType, ErrorTextId ({}) is set, set to 0!", cond.ToString(), cond.ErrorTextId);
            cond.ErrorTextId = 0;
        }

        getOrInitConditions(cond.SourceType, { cond.SourceGroup, cond.SourceEntry, cond.SourceId })->emplace_back(std::move(cond));
        ++count;
    }
    while (result->NextRow());

    for (auto&& [id, conditions] : ConditionStore[CONDITION_SOURCE_TYPE_CREATURE_LOOT_TEMPLATE])
        addToLootTemplate(id, conditions, LootTemplates_Creature.GetLootForConditionFill(id.SourceGroup));

    for (auto&& [id, conditions] : ConditionStore[CONDITION_SOURCE_TYPE_DISENCHANT_LOOT_TEMPLATE])
        addToLootTemplate(id, conditions, LootTemplates_Disenchant.GetLootForConditionFill(id.SourceGroup));

    for (auto&& [id, conditions] : ConditionStore[CONDITION_SOURCE_TYPE_FISHING_LOOT_TEMPLATE])
        addToLootTemplate(id, conditions, LootTemplates_Fishing.GetLootForConditionFill(id.SourceGroup));

    for (auto&& [id, conditions] : ConditionStore[CONDITION_SOURCE_TYPE_GAMEOBJECT_LOOT_TEMPLATE])
        addToLootTemplate(id, conditions, LootTemplates_Gameobject.GetLootForConditionFill(id.SourceGroup));

    for (auto&& [id, conditions] : ConditionStore[CONDITION_SOURCE_TYPE_ITEM_LOOT_TEMPLATE])
        addToLootTemplate(id, conditions, LootTemplates_Item.GetLootForConditionFill(id.SourceGroup));

    for (auto&& [id, conditions] : ConditionStore[CONDITION_SOURCE_TYPE_MAIL_LOOT_TEMPLATE])
        addToLootTemplate(id, conditions, LootTemplates_Mail.GetLootForConditionFill(id.SourceGroup));

    for (auto&& [id, conditions] : ConditionStore[CONDITION_SOURCE_TYPE_MILLING_LOOT_TEMPLATE])
        addToLootTemplate(id, conditions, LootTemplates_Milling.GetLootForConditionFill(id.SourceGroup));

    for (auto&& [id, conditions] : ConditionStore[CONDITION_SOURCE_TYPE_PICKPOCKETING_LOOT_TEMPLATE])
        addToLootTemplate(id, conditions, LootTemplates_Pickpocketing.GetLootForConditionFill(id.SourceGroup));

    for (auto&& [id, conditions] : ConditionStore[CONDITION_SOURCE_TYPE_PROSPECTING_LOOT_TEMPLATE])
        addToLootTemplate(id, conditions, LootTemplates_Prospecting.GetLootForConditionFill(id.SourceGroup));

    for (auto&& [id, conditions] : ConditionStore[CONDITION_SOURCE_TYPE_REFERENCE_LOOT_TEMPLATE])
        addToLootTemplate(id, conditions, LootTemplates_Reference.GetLootForConditionFill(id.SourceGroup));

    for (auto&& [id, conditions] : ConditionStore[CONDITION_SOURCE_TYPE_SKINNING_LOOT_TEMPLATE])
        addToLootTemplate(id, conditions, LootTemplates_Skinning.GetLootForConditionFill(id.SourceGroup));

    for (auto&& [id, conditions] : ConditionStore[CONDITION_SOURCE_TYPE_SPELL_LOOT_TEMPLATE])
        addToLootTemplate(id, conditions, LootTemplates_Spell.GetLootForConditionFill(id.SourceGroup));

    for (auto&& [id, conditions] : ConditionStore[CONDITION_SOURCE_TYPE_GOSSIP_MENU])
        addToGossipMenus(id, conditions);

    for (auto&& [id, conditions] : ConditionStore[CONDITION_SOURCE_TYPE_GOSSIP_MENU_OPTION])
        addToGossipMenuItems(id, conditions);

    SpellsUsedInSpellClickConditions.clear();
    for (auto&& [id, conditions] : ConditionStore[CONDITION_SOURCE_TYPE_SPELL_CLICK_EVENT])
        for (Condition const& condition : *conditions)
            if (condition.ConditionType == CONDITION_AURA)
                SpellsUsedInSpellClickConditions.insert(condition.ConditionValue1);

    for (auto&& [id, conditions] : ConditionStore[CONDITION_SOURCE_TYPE_SPELL_IMPLICIT_TARGET])
        for (Condition const& condition : *conditions)
            addToSpellImplicitTargetConditions(condition);

    for (auto&& [id, conditions] : ConditionStore[CONDITION_SOURCE_TYPE_PHASE])
        addToPhases(id, conditions);

    for (auto&& [id, conditions] : ConditionStore[CONDITION_SOURCE_TYPE_GRAVEYARD])
        addToGraveyardData(id, conditions);

    TC_LOG_INFO("server.loading", ">> Loaded {} conditions in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ConditionMgr::addToLootTemplate(ConditionId const& id, std::shared_ptr<std::vector<Condition>> conditions, LootTemplate* loot) const
{
    if (!loot)
    {
        for (Condition const& condition : *conditions)
            TC_LOG_ERROR("sql.sql", "{} LootTemplate {} not found.", condition.ToString(), id.SourceGroup);
        return;
    }

    if (loot->LinkConditions(id, ConditionsReference{ conditions }))
        return;

    for (Condition const& condition : *conditions)
        TC_LOG_ERROR("sql.sql", "{} Item {} not found in LootTemplate {}.", condition.ToString(), id.SourceEntry, id.SourceGroup);
}

void ConditionMgr::addToGossipMenus(ConditionId const& id, std::shared_ptr<std::vector<Condition>> conditions) const
{
    GossipMenusMapBoundsNonConst pMenuBounds = sObjectMgr->GetGossipMenusMapBoundsNonConst(id.SourceGroup);

    if (pMenuBounds.first != pMenuBounds.second)
    {
        for (GossipMenusContainer::iterator itr = pMenuBounds.first; itr != pMenuBounds.second; ++itr)
            if (itr->second.MenuID == id.SourceGroup && (itr->second.TextID == uint32(id.SourceEntry) || id.SourceEntry == 0))
                itr->second.Conditions = { conditions };

        return;
    }

    for (Condition const& condition : *conditions)
        TC_LOG_ERROR("sql.sql", "{} GossipMenu {} not found.", condition.ToString(), id.SourceGroup);
}

void ConditionMgr::addToGossipMenuItems(ConditionId const& id, std::shared_ptr<std::vector<Condition>> conditions) const
{
    Trinity::IteratorPair pMenuItemBounds = sObjectMgr->GetGossipMenuItemsMapBoundsNonConst(id.SourceGroup);
    for (auto& [_, gossipMenuItem] : pMenuItemBounds)
    {
        if (gossipMenuItem.MenuID == id.SourceGroup && gossipMenuItem.OrderIndex == uint32(id.SourceEntry))
        {
            gossipMenuItem.Conditions = { conditions };
            return;
        }
    }

    for (Condition const& condition : *conditions)
        TC_LOG_ERROR("sql.sql", "{} GossipMenuId {} Item {} not found.", condition.ToString(), id.SourceGroup, id.SourceEntry);
}

void ConditionMgr::addToSpellImplicitTargetConditions(Condition const& cond) const
{
    sSpellMgr->ForEachSpellInfoDifficulty(cond.SourceEntry, [&](SpellInfo const* spellInfo)
    {
        uint32 conditionEffMask = cond.SourceGroup;
        std::list<uint32> sharedMasks;
        for (SpellEffectInfo const& spellEffectInfo : spellInfo->GetEffects())
        {
            // additional checks by condition type
            if (conditionEffMask & (1 << spellEffectInfo.EffectIndex))
            {
                switch (cond.ConditionType)
                {
                    case CONDITION_OBJECT_ENTRY_GUID:
                    {
                        uint32 implicitTargetMask = GetTargetFlagMask(spellEffectInfo.TargetA.GetObjectType()) | GetTargetFlagMask(spellEffectInfo.TargetB.GetObjectType());
                        if ((implicitTargetMask & TARGET_FLAG_UNIT_MASK) && cond.ConditionValue1 != TYPEID_UNIT && cond.ConditionValue1 != TYPEID_PLAYER)
                        {
                            TC_LOG_ERROR("sql.sql", "{} in `condition` table - spell {} EFFECT_{} - "
                                "target requires ConditionValue1 to be either TYPEID_UNIT ({}) or TYPEID_PLAYER ({})", cond.ToString(), spellInfo->Id, uint32(spellEffectInfo.EffectIndex), uint32(TYPEID_UNIT), uint32(TYPEID_PLAYER));
                            return;
                        }

                        if ((implicitTargetMask & TARGET_FLAG_GAMEOBJECT_MASK) && cond.ConditionValue1 != TYPEID_GAMEOBJECT)
                        {
                            TC_LOG_ERROR("sql.sql", "{} in `condition` table - spell {} EFFECT_{} - "
                                "target requires ConditionValue1 to be TYPEID_GAMEOBJECT ({})", cond.ToString(), spellInfo->Id, uint32(spellEffectInfo.EffectIndex), uint32(TYPEID_GAMEOBJECT));
                            return;
                        }

                        if ((implicitTargetMask & TARGET_FLAG_CORPSE_MASK) && cond.ConditionValue1 != TYPEID_CORPSE)
                        {
                            TC_LOG_ERROR("sql.sql", "{} in `condition` table - spell {} EFFECT_{} - "
                                "target requires ConditionValue1 to be TYPEID_CORPSE ({})", cond.ToString(), spellInfo->Id, uint32(spellEffectInfo.EffectIndex), uint32(TYPEID_CORPSE));
                            return;
                        }
                        break;
                    }
                    default:
                        break;
                }
            }

            // check if effect is already a part of some shared mask
            auto itr = std::find_if(sharedMasks.begin(), sharedMasks.end(), [&](uint32 mask) { return !!(mask & (1 << spellEffectInfo.EffectIndex)); });
            if (itr != sharedMasks.end())
                continue;

            // build new shared mask with found effect
            uint32 sharedMask = 1 << spellEffectInfo.EffectIndex;
            for (size_t effIndex = spellEffectInfo.EffectIndex + 1; effIndex < spellInfo->GetEffects().size(); ++effIndex)
                if (spellInfo->GetEffect(SpellEffIndex(effIndex)).ImplicitTargetConditions == spellEffectInfo.ImplicitTargetConditions)
                    sharedMask |= 1 << effIndex;

            sharedMasks.push_back(sharedMask);
        }

        for (uint32 effectMask : sharedMasks)
        {
            // some effect indexes should have same data
            if (uint32 commonMask = effectMask & conditionEffMask)
            {
                size_t firstEffIndex = 0;
                for (; firstEffIndex < spellInfo->GetEffects().size(); ++firstEffIndex)
                    if ((1 << firstEffIndex) & effectMask)
                        break;

                if (firstEffIndex >= spellInfo->GetEffects().size())
                    return;

                // get shared data
                std::shared_ptr<ConditionContainer> sharedList = spellInfo->GetEffect(SpellEffIndex(firstEffIndex)).ImplicitTargetConditions;

                // there's already data entry for that sharedMask
                if (sharedList)
                {
                    // we have overlapping masks in db
                    if (conditionEffMask != effectMask)
                    {
                        TC_LOG_ERROR("sql.sql", "{} in `condition` table, has incorrect SourceGroup {} (spell effectMask) set - "
                            "effect masks are overlapping (all SourceGroup values having given bit set must be equal) - ignoring (Difficulty {}).",
                            cond.ToString(), cond.SourceGroup, uint32(spellInfo->Difficulty));
                        return;
                    }
                }
                // no data for shared mask, we can create new submask
                else
                {
                    // add new list, create new shared mask
                    sharedList = std::make_shared<ConditionContainer>();
                    bool assigned = false;
                    for (size_t i = firstEffIndex; i < spellInfo->GetEffects().size(); ++i)
                    {
                        if ((1 << i) & commonMask)
                        {
                            const_cast<SpellEffectInfo&>(spellInfo->GetEffect(SpellEffIndex(i))).ImplicitTargetConditions = sharedList;
                            assigned = true;
                        }
                    }

                    if (!assigned)
                        break;
                }
                sharedList->push_back(cond);
                break;
            }
        }
    });
}

void ConditionMgr::addToPhases(ConditionId const& id, std::shared_ptr<std::vector<Condition>> conditions) const
{
    if (!id.SourceEntry)
    {
        if (PhaseInfoStruct const* phaseInfo = sObjectMgr->GetPhaseInfo(id.SourceGroup))
        {
            bool found = false;
            for (uint32 areaId : phaseInfo->Areas)
            {
                if (std::vector<PhaseAreaInfo>* phases = const_cast<std::vector<PhaseAreaInfo>*>(sObjectMgr->GetPhasesForArea(areaId)))
                {
                    for (PhaseAreaInfo& phase : *phases)
                    {
                        if (phase.PhaseInfo->Id == id.SourceGroup)
                        {
                            phase.Conditions.insert(phase.Conditions.end(), conditions->begin(), conditions->end());
                            found = true;
                        }
                    }
                }
            }

            if (found)
                return;
        }
    }
    else if (std::vector<PhaseAreaInfo>* phases = const_cast<std::vector<PhaseAreaInfo>*>(sObjectMgr->GetPhasesForArea(id.SourceEntry)))
    {
        for (PhaseAreaInfo& phase : *phases)
        {
            if (phase.PhaseInfo->Id == id.SourceGroup)
            {
                phase.Conditions.insert(phase.Conditions.end(), conditions->begin(), conditions->end());
                return;
            }
        }
    }

    for (Condition const& condition : *conditions)
        TC_LOG_ERROR("sql.sql", "{} Area {} does not have phase {}.", condition.ToString(), id.SourceEntry, id.SourceGroup);
}

void ConditionMgr::addToGraveyardData(ConditionId const& id, std::shared_ptr<std::vector<Condition>> conditions) const
{
    if (GraveyardData* graveyard = const_cast<GraveyardData*>(sObjectMgr->FindGraveyardData(id.SourceEntry, id.SourceGroup)))
    {
        graveyard->Conditions = { conditions };
        return;
    }

    for (Condition const& condition : *conditions)
        TC_LOG_ERROR("sql.sql", "{}, Graveyard {} does not have ghostzone {}.", condition.ToString(), id.SourceEntry, id.SourceGroup);
}

bool ConditionMgr::isSourceTypeValid(Condition* cond) const
{
    switch (cond->SourceType)
    {
        case CONDITION_SOURCE_TYPE_CREATURE_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Creature.HaveLootFor(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceGroup in `condition` table, does not exist in `creature_loot_template`, ignoring.", cond->ToString());
                return false;
            }

            LootTemplate* loot = LootTemplates_Creature.GetLootForConditionFill(cond->SourceGroup);
            ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!pItemProto && !loot->isReference(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceType, SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_DISENCHANT_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Disenchant.HaveLootFor(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceGroup in `condition` table, does not exist in `disenchant_loot_template`, ignoring.", cond->ToString());
                return false;
            }

            LootTemplate* loot = LootTemplates_Disenchant.GetLootForConditionFill(cond->SourceGroup);
            ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!pItemProto && !loot->isReference(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceType, SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_FISHING_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Fishing.HaveLootFor(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceGroup in `condition` table, does not exist in `fishing_loot_template`, ignoring.", cond->ToString());
                return false;
            }

            LootTemplate* loot = LootTemplates_Fishing.GetLootForConditionFill(cond->SourceGroup);
            ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!pItemProto && !loot->isReference(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceType, SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_GAMEOBJECT_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Gameobject.HaveLootFor(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceGroup in `condition` table, does not exist in `gameobject_loot_template`, ignoring.", cond->ToString());
                return false;
            }

            LootTemplate* loot = LootTemplates_Gameobject.GetLootForConditionFill(cond->SourceGroup);
            ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!pItemProto && !loot->isReference(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceType, SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_ITEM_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Item.HaveLootFor(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceGroup in `condition` table, does not exist in `item_loot_template`, ignoring.", cond->ToString());
                return false;
            }

            LootTemplate* loot = LootTemplates_Item.GetLootForConditionFill(cond->SourceGroup);
            ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!pItemProto && !loot->isReference(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceType, SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_MAIL_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Mail.HaveLootFor(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceGroup in `condition` table, does not exist in `mail_loot_template`, ignoring.", cond->ToString());
                return false;
            }

            LootTemplate* loot = LootTemplates_Mail.GetLootForConditionFill(cond->SourceGroup);
            ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!pItemProto && !loot->isReference(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceType, SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_MILLING_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Milling.HaveLootFor(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceGroup in `condition` table, does not exist in `milling_loot_template`, ignoring.", cond->ToString());
                return false;
            }

            LootTemplate* loot = LootTemplates_Milling.GetLootForConditionFill(cond->SourceGroup);
            ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!pItemProto && !loot->isReference(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceType, SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_PICKPOCKETING_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Pickpocketing.HaveLootFor(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceGroup in `condition` table, does not exist in `pickpocketing_loot_template`, ignoring.", cond->ToString());
                return false;
            }

            LootTemplate* loot = LootTemplates_Pickpocketing.GetLootForConditionFill(cond->SourceGroup);
            ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!pItemProto && !loot->isReference(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceType, SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_PROSPECTING_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Prospecting.HaveLootFor(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceGroup in `condition` table, does not exist in `prospecting_loot_template`, ignoring.", cond->ToString());
                return false;
            }

            LootTemplate* loot = LootTemplates_Prospecting.GetLootForConditionFill(cond->SourceGroup);
            ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!pItemProto && !loot->isReference(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceType, SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_REFERENCE_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Reference.HaveLootFor(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceGroup in `condition` table, does not exist in `reference_loot_template`, ignoring.", cond->ToString());
                return false;
            }

            LootTemplate* loot = LootTemplates_Reference.GetLootForConditionFill(cond->SourceGroup);
            ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!pItemProto && !loot->isReference(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceType, SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_SKINNING_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Skinning.HaveLootFor(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceGroup in `condition` table, does not exist in `skinning_loot_template`, ignoring.", cond->ToString());
                return false;
            }

            LootTemplate* loot = LootTemplates_Skinning.GetLootForConditionFill(cond->SourceGroup);
            ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!pItemProto && !loot->isReference(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceType, SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_SPELL_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Spell.HaveLootFor(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceGroup in `condition` table, does not exist in `spell_loot_template`, ignoring.", cond->ToString());
                return false;
            }

            LootTemplate* loot = LootTemplates_Spell.GetLootForConditionFill(cond->SourceGroup);
            ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!pItemProto && !loot->isReference(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceType, SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_SPELL_IMPLICIT_TARGET:
        {
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(cond->SourceEntry, DIFFICULTY_NONE);
            if (!spellInfo)
            {
                TC_LOG_ERROR("sql.sql", "{} SourceEntry in `condition` table does not exist in `Spell.db2`, ignoring.", cond->ToString());
                return false;
            }

            if ((cond->SourceGroup > MAX_EFFECT_MASK) || !cond->SourceGroup)
            {
                TC_LOG_ERROR("sql.sql", "{} in `condition` table, has incorrect SourceGroup (spell effectMask) set, ignoring.", cond->ToString());
                return false;
            }

            uint32 origGroup = cond->SourceGroup;

            for (SpellEffectInfo const& spellEffectInfo : spellInfo->GetEffects())
            {
                if (!((1 << spellEffectInfo.EffectIndex) & cond->SourceGroup))
                    continue;

                if (spellEffectInfo.ChainTargets > 0)
                    continue;

                switch (spellEffectInfo.TargetA.GetSelectionCategory())
                {
                    case TARGET_SELECT_CATEGORY_NEARBY:
                    case TARGET_SELECT_CATEGORY_CONE:
                    case TARGET_SELECT_CATEGORY_AREA:
                    case TARGET_SELECT_CATEGORY_TRAJ:
                    case TARGET_SELECT_CATEGORY_LINE:
                        continue;
                    default:
                        break;
                }

                switch (spellEffectInfo.TargetB.GetSelectionCategory())
                {
                    case TARGET_SELECT_CATEGORY_NEARBY:
                    case TARGET_SELECT_CATEGORY_CONE:
                    case TARGET_SELECT_CATEGORY_AREA:
                    case TARGET_SELECT_CATEGORY_TRAJ:
                    case TARGET_SELECT_CATEGORY_LINE:
                        continue;
                    default:
                        break;
                }

                switch (spellEffectInfo.Effect)
                {
                    case SPELL_EFFECT_PERSISTENT_AREA_AURA:
                    case SPELL_EFFECT_APPLY_AREA_AURA_PARTY:
                    case SPELL_EFFECT_APPLY_AREA_AURA_RAID:
                    case SPELL_EFFECT_APPLY_AREA_AURA_FRIEND:
                    case SPELL_EFFECT_APPLY_AREA_AURA_ENEMY:
                    case SPELL_EFFECT_APPLY_AREA_AURA_PET:
                    case SPELL_EFFECT_APPLY_AREA_AURA_OWNER:
                    case SPELL_EFFECT_APPLY_AURA_ON_PET:
                    case SPELL_EFFECT_APPLY_AREA_AURA_SUMMONS:
                    case SPELL_EFFECT_APPLY_AREA_AURA_PARTY_NONRANDOM:
                        continue;
                    default:
                        break;
                }

                TC_LOG_ERROR("sql.sql", "SourceEntry {} SourceGroup {} in `condition` table - spell {} does not have implicit targets of types: _AREA_, _CONE_, _NEARBY_, __CHAIN__ or is not SPELL_EFFECT_PERSISTENT_AREA_AURA or SPELL_EFFECT_APPLY_AREA_AURA_* for effect {}, SourceGroup needs correction, ignoring.", cond->SourceEntry, origGroup, cond->SourceEntry, uint32(spellEffectInfo.EffectIndex));
                cond->SourceGroup &= ~(1 << spellEffectInfo.EffectIndex);
            }
            // all effects were removed, no need to add the condition at all
            if (!cond->SourceGroup)
                return false;
            break;
        }
        case CONDITION_SOURCE_TYPE_CREATURE_TEMPLATE_VEHICLE:
        {
            if (!sObjectMgr->GetCreatureTemplate(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceEntry in `condition` table, does not exist in `creature_template`, ignoring.", cond->ToString());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_SPELL:
        case CONDITION_SOURCE_TYPE_SPELL_PROC:
        {
            SpellInfo const* spellProto = sSpellMgr->GetSpellInfo(cond->SourceEntry, DIFFICULTY_NONE);
            if (!spellProto)
            {
                TC_LOG_ERROR("sql.sql", "{} SourceEntry in `condition` table does not exist in `Spell.db2`, ignoring.", cond->ToString());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_QUEST_AVAILABLE:
            if (!sObjectMgr->GetQuestTemplate(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceEntry specifies non-existing quest, skipped.", cond->ToString());
                return false;
            }
            break;
        case CONDITION_SOURCE_TYPE_VEHICLE_SPELL:
            if (!sObjectMgr->GetCreatureTemplate(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceGroup in `condition` table, does not exist in `creature_template`, ignoring.", cond->ToString());
                return false;
            }

            if (!sSpellMgr->GetSpellInfo(cond->SourceEntry, DIFFICULTY_NONE))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceEntry in `condition` table does not exist in `Spell.db2`, ignoring.", cond->ToString());
                return false;
            }
            break;
        case CONDITION_SOURCE_TYPE_SPELL_CLICK_EVENT:
            if (!sObjectMgr->GetCreatureTemplate(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceGroup in `condition` table, does not exist in `creature_template`, ignoring.", cond->ToString());
                return false;
            }

            if (!sSpellMgr->GetSpellInfo(cond->SourceEntry, DIFFICULTY_NONE))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceEntry in `condition` table does not exist in `Spell.db2`, ignoring.", cond->ToString());
                return false;
            }
            break;
        case CONDITION_SOURCE_TYPE_NPC_VENDOR:
        {
            if (!sObjectMgr->GetCreatureTemplate(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceGroup in `condition` table, does not exist in `creature_template`, ignoring.", cond->ToString());
                return false;
            }
            ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!itemTemplate)
            {
                TC_LOG_ERROR("sql.sql", "{} SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_TERRAIN_SWAP:
        {
            if (!sMapStore.LookupEntry(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceEntry in `condition` table, does not exist in Map.db2, ignoring.", cond->ToString());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_PHASE:
        {
            if (cond->SourceEntry && !sAreaTableStore.LookupEntry(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceEntry in `condition` table, does not exist in AreaTable.db2, ignoring.", cond->ToString());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_GOSSIP_MENU:
        case CONDITION_SOURCE_TYPE_GOSSIP_MENU_OPTION:
        case CONDITION_SOURCE_TYPE_SMART_EVENT:
            break;
        case CONDITION_SOURCE_TYPE_GRAVEYARD:
            if (!sObjectMgr->FindGraveyardData(cond->SourceEntry, cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceEntry in `condition` table, does not exist in `graveyard_zone`, ignoring.", cond->ToString());
                return false;
            }
            break;
        case CONDITION_SOURCE_TYPE_AREATRIGGER:
            if (cond->SourceEntry != 0 && cond->SourceEntry != 1)
            {
                TC_LOG_ERROR("sql.sql", "{} in `condition` table, unexpected SourceEntry value (expected 0 or 1), ignoring.", cond->ToString());
                return false;
            }
            if (!sAreaTriggerDataStore->GetAreaTriggerTemplate({ uint32(cond->SourceGroup), cond->SourceEntry == 1 }))
            {
                TC_LOG_ERROR("sql.sql", "{} in `condition` table, does not exist in `areatrigger_template`, ignoring.", cond->ToString());
                return false;
            }
            break;
        case CONDITION_SOURCE_TYPE_CONVERSATION_LINE:
            if (!sConversationDataStore->GetConversationLineTemplate(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "{} does not exist in `conversation_line_template`, ignoring.", cond->ToString());
                return false;
            }
            break;
        case CONDITION_SOURCE_TYPE_AREATRIGGER_CLIENT_TRIGGERED:
            if (!sAreaTriggerStore.LookupEntry(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceEntry in `condition` table, does not exists in AreaTrigger.db2, ignoring.", cond->ToString());
                return false;
            }
            break;
        case CONDITION_SOURCE_TYPE_TRAINER_SPELL:
        {
            if (!sObjectMgr->GetTrainer(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceGroup in `condition` table, does not exist in `trainer`, ignoring.", cond->ToString());
                return false;
            }
            if (!sSpellMgr->GetSpellInfo(cond->SourceEntry, DIFFICULTY_NONE))
            {
                TC_LOG_ERROR("sql.sql", "{} SourceEntry in `condition` table does not exist in `Spell.db2`, ignoring.", cond->ToString());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_OBJECT_ID_VISIBILITY:
        {
            if (cond->SourceGroup <= 0 || cond->SourceGroup >= NUM_CLIENT_OBJECT_TYPES)
            {
                TC_LOG_ERROR("sql.sql", "{} SourceGroup in `condition` table, is no valid object type, ignoring.", cond->ToString());
                return false;
            }

            if (cond->SourceGroup == TYPEID_UNIT)
            {
                if (!sObjectMgr->GetCreatureTemplate(cond->SourceEntry))
                {
                    TC_LOG_ERROR("sql.sql", "{} SourceEntry in `condition` table, does not exist in `creature_template`, ignoring.", cond->ToString());
                    return false;
                }
            }
            else if (cond->SourceGroup == TYPEID_GAMEOBJECT)
            {
                if (!sObjectMgr->GetGameObjectTemplate(cond->SourceEntry))
                {
                    TC_LOG_ERROR("sql.sql", "{} SourceEntry in `condition` table, does not exist in `gameobject_template`, ignoring.", cond->ToString());
                    return false;
                }
            }
            else
            {
                TC_LOG_ERROR("sql.sql", "{} SourceGroup in `condition` table, uses unchecked type id, ignoring.", cond->ToString());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_SPAWN_GROUP:
        {
            SpawnGroupTemplateData const* spawnGroup = sObjectMgr->GetSpawnGroupData(cond->SourceEntry);
            if (!spawnGroup)
            {
                TC_LOG_ERROR("sql.sql", "{} SourceEntry in `condition` table, does not exist in `spawn_group_template`, ignoring.", cond->ToString());
                return false;
            }
            if (spawnGroup->flags & (SPAWNGROUP_FLAG_SYSTEM))
            {
                TC_LOG_ERROR("sql.sql", "{} in `spawn_group_template` table cannot have SPAWNGROUP_FLAG_SYSTEM flags, ignoring.", cond->ToString());
                return false;
            }
            break;
        }
        default:
            TC_LOG_ERROR("sql.sql", "{} Invalid ConditionSourceType in `condition` table, ignoring.", cond->ToString());
            return false;
    }

    return true;
}

bool ConditionMgr::isConditionTypeValid(Condition* cond) const
{
    switch (cond->ConditionType)
    {
        case CONDITION_AURA:
        {
            if (!sSpellMgr->GetSpellInfo(cond->ConditionValue1, DIFFICULTY_NONE))
            {
                TC_LOG_ERROR("sql.sql", "{} has non existing spell (Id: {}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }

            if (cond->ConditionValue2 >= MAX_SPELL_EFFECTS)
            {
                TC_LOG_ERROR("sql.sql", "{} has non existing effect index ({}) (must be 0..{}), skipped.", cond->ToString(true), cond->ConditionValue2, MAX_SPELL_EFFECTS - 1);
                return false;
            }
            break;
        }
        case CONDITION_ITEM:
        {
            ItemTemplate const* proto = sObjectMgr->GetItemTemplate(cond->ConditionValue1);
            if (!proto)
            {
                TC_LOG_ERROR("sql.sql", "{} Item ({}) does not exist, skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }

            if (!cond->ConditionValue2)
            {
                TC_LOG_ERROR("sql.sql", "{} Zero item count in ConditionValue2, skipped.", cond->ToString(true));
                return false;
            }
            break;
        }
        case CONDITION_ITEM_EQUIPPED:
        {
            ItemTemplate const* proto = sObjectMgr->GetItemTemplate(cond->ConditionValue1);
            if (!proto)
            {
                TC_LOG_ERROR("sql.sql", "{} Item ({}) does not exist, skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_ZONEID:
        {
            AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(cond->ConditionValue1);
            if (!areaEntry)
            {
                TC_LOG_ERROR("sql.sql", "{} Area ({}) does not exist, skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }

            if (areaEntry->ParentAreaID != 0 && areaEntry->GetFlags().HasFlag(AreaFlags::IsSubzone))
            {
                TC_LOG_ERROR("sql.sql", "{} requires to be in area ({}) which is a subzone but zone expected, skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_REPUTATION_RANK:
        {
            FactionEntry const* factionEntry = sFactionStore.LookupEntry(cond->ConditionValue1);
            if (!factionEntry)
            {
                TC_LOG_ERROR("sql.sql", "{} has non existing faction ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_TEAM:
        {
            if (cond->ConditionValue1 != ALLIANCE && cond->ConditionValue1 != HORDE)
            {
                TC_LOG_ERROR("sql.sql", "{} specifies unknown team ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_SKILL:
        {
            SkillLineEntry const* pSkill = sSkillLineStore.LookupEntry(cond->ConditionValue1);
            if (!pSkill)
            {
                TC_LOG_ERROR("sql.sql", "{} specifies non-existing skill ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }

            if (cond->ConditionValue2 < 1 || cond->ConditionValue2 > sWorld->GetConfigMaxSkillValue())
            {
                TC_LOG_ERROR("sql.sql", "{} specifies skill ({}) with invalid value ({}), skipped.", cond->ToString(true), cond->ConditionValue1, cond->ConditionValue2);
                return false;
            }
            break;
        }
        case CONDITION_QUESTSTATE:
            if (cond->ConditionValue2 >= (1 << MAX_QUEST_STATUS))
            {
                TC_LOG_ERROR("sql.sql", "{} has invalid state mask ({}), skipped.", cond->ToString(true), cond->ConditionValue2);
                return false;
            }
            [[fallthrough]];
        case CONDITION_QUESTREWARDED:
        case CONDITION_QUESTTAKEN:
        case CONDITION_QUEST_NONE:
        case CONDITION_QUEST_COMPLETE:
        case CONDITION_DAILY_QUEST_DONE:
        {
            if (!sObjectMgr->GetQuestTemplate(cond->ConditionValue1))
            {
                TC_LOG_ERROR("sql.sql", "{} points to non-existing quest ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_ACTIVE_EVENT:
        {
            GameEventMgr::GameEventDataMap const& events = sGameEventMgr->GetEventMap();
            if (cond->ConditionValue1 >= events.size() || !events[cond->ConditionValue1].isValid())
            {
                TC_LOG_ERROR("sql.sql", "{} has non existing event id ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_ACHIEVEMENT:
        {
            AchievementEntry const* achievement = sAchievementStore.LookupEntry(cond->ConditionValue1);
            if (!achievement)
            {
                TC_LOG_ERROR("sql.sql", "{} has non existing achivement id ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_CLASS:
        {
            if (cond->ConditionValue1 & ~CLASSMASK_ALL_PLAYABLE)
            {
                TC_LOG_ERROR("sql.sql", "{} has non existing classmask ({}), skipped.", cond->ToString(true), cond->ConditionValue1 & ~CLASSMASK_ALL_PLAYABLE);
                return false;
            }
            break;
        }
        case CONDITION_RACE:
        {
            Trinity::RaceMask<uint64> invalidRaceMask = Trinity::RaceMask<uint64>{ cond->ConditionValue1 } & ~RACEMASK_ALL_PLAYABLE;
            if (!invalidRaceMask.IsEmpty()) // uint32 works thanks to weird index remapping in racemask
            {
                TC_LOG_ERROR("sql.sql", "{} has non existing racemask ({}), skipped.", cond->ToString(true), invalidRaceMask.RawValue);
                return false;
            }
            break;
        }
        case CONDITION_GENDER:
        {
            if (!Player::IsValidGender(uint8(cond->ConditionValue1)))
            {
                TC_LOG_ERROR("sql.sql", "{} has invalid gender ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_MAPID:
        {
            MapEntry const* me = sMapStore.LookupEntry(cond->ConditionValue1);
            if (!me)
            {
                TC_LOG_ERROR("sql.sql", "{} has non existing map ({}), skipped", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_SPELL:
        {
            if (!sSpellMgr->GetSpellInfo(cond->ConditionValue1, DIFFICULTY_NONE))
            {
                TC_LOG_ERROR("sql.sql", "{} has non existing spell (Id: {}), skipped", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_LEVEL:
        {
            if (cond->ConditionValue2 >= COMP_TYPE_MAX)
            {
                TC_LOG_ERROR("sql.sql", "{} has invalid ComparisionType ({}), skipped.", cond->ToString(true), cond->ConditionValue2);
                return false;
            }
            break;
        }
        case CONDITION_DRUNKENSTATE:
        {
            if (cond->ConditionValue1 > DRUNKEN_SMASHED)
            {
                TC_LOG_ERROR("sql.sql", "{} has invalid state ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_NEAR_CREATURE:
        {
            if (!sObjectMgr->GetCreatureTemplate(cond->ConditionValue1))
            {
                TC_LOG_ERROR("sql.sql", "{} has non existing creature template entry ({}), skipped", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_NEAR_GAMEOBJECT:
        {
            if (!sObjectMgr->GetGameObjectTemplate(cond->ConditionValue1))
            {
                TC_LOG_ERROR("sql.sql", "{} has non existing gameobject template entry ({}), skipped.", cond->ToString(), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_OBJECT_ENTRY_GUID_LEGACY:
            cond->ConditionType = CONDITION_OBJECT_ENTRY_GUID;
            cond->ConditionValue1 = Trinity::Legacy::ConvertLegacyTypeID(Trinity::Legacy::TypeID(cond->ConditionValue1));
            [[fallthrough]];
        case CONDITION_OBJECT_ENTRY_GUID:
        {
            switch (cond->ConditionValue1)
            {
                case TYPEID_UNIT:
                    if (cond->ConditionValue2 && !sObjectMgr->GetCreatureTemplate(cond->ConditionValue2))
                    {
                        TC_LOG_ERROR("sql.sql", "{} has non existing creature template entry ({}), skipped.", cond->ToString(true), cond->ConditionValue2);
                        return false;
                    }
                    if (cond->ConditionValue3)
                    {
                        if (CreatureData const* creatureData = sObjectMgr->GetCreatureData(cond->ConditionValue3))
                        {
                            if (cond->ConditionValue2 && creatureData->id != cond->ConditionValue2)
                            {
                                TC_LOG_ERROR("sql.sql", "{} has guid {} set but does not match creature entry ({}), skipped.", cond->ToString(true), cond->ConditionValue3, cond->ConditionValue2);
                                return false;
                            }
                        }
                        else
                        {
                            TC_LOG_ERROR("sql.sql", "{} has non existing creature guid ({}), skipped.", cond->ToString(true), cond->ConditionValue3);
                            return false;
                        }
                    }
                    break;
                case TYPEID_GAMEOBJECT:
                    if (cond->ConditionValue2 && !sObjectMgr->GetGameObjectTemplate(cond->ConditionValue2))
                    {
                        TC_LOG_ERROR("sql.sql", "{} has non existing gameobject template entry ({}), skipped.", cond->ToString(true), cond->ConditionValue2);
                        return false;
                    }
                    if (cond->ConditionValue3)
                    {
                        if (GameObjectData const* goData = sObjectMgr->GetGameObjectData(cond->ConditionValue3))
                        {
                            if (cond->ConditionValue2 && goData->id != cond->ConditionValue2)
                            {
                                TC_LOG_ERROR("sql.sql", "{} has guid {} set but does not match gameobject entry ({}), skipped.", cond->ToString(true), cond->ConditionValue3, cond->ConditionValue2);
                                return false;
                            }
                        }
                        else
                        {
                            TC_LOG_ERROR("sql.sql", "{} has non existing gameobject guid ({}), skipped.", cond->ToString(true), cond->ConditionValue3);
                            return false;
                        }
                    }
                    break;
                case TYPEID_PLAYER:
                case TYPEID_CORPSE:
                    if (cond->ConditionValue2)
                        LogUselessConditionValue(cond, 2, cond->ConditionValue2);
                    if (cond->ConditionValue3)
                        LogUselessConditionValue(cond, 3, cond->ConditionValue3);
                    break;
                default:
                    TC_LOG_ERROR("sql.sql", "{} has wrong typeid set ({}), skipped", cond->ToString(true), cond->ConditionValue1);
                    return false;
            }
            break;
        }
        case CONDITION_TYPE_MASK_LEGACY:
            cond->ConditionType = CONDITION_TYPE_MASK;
            cond->ConditionValue1 = Trinity::Legacy::ConvertLegacyTypeMask(cond->ConditionValue1);
            [[fallthrough]];
        case CONDITION_TYPE_MASK:
        {
            if (!cond->ConditionValue1 || (cond->ConditionValue1 & ~(TYPEMASK_UNIT | TYPEMASK_PLAYER | TYPEMASK_GAMEOBJECT | TYPEMASK_CORPSE)))
            {
                TC_LOG_ERROR("sql.sql", "{} has invalid typemask set ({}), skipped.", cond->ToString(true), cond->ConditionValue2);
                return false;
            }
            break;
        }
        case CONDITION_RELATION_TO:
        {
            if (cond->ConditionValue1 >= cond->GetMaxAvailableConditionTargets())
            {
                TC_LOG_ERROR("sql.sql", "{} has invalid ConditionValue1(ConditionTarget selection) ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            if (cond->ConditionValue1 == cond->ConditionTarget)
            {
                TC_LOG_ERROR("sql.sql", "{} has ConditionValue1(ConditionTarget selection) set to self ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            if (cond->ConditionValue2 >= RELATION_MAX)
            {
                TC_LOG_ERROR("sql.sql", "{} has invalid ConditionValue2(RelationType) ({}), skipped.", cond->ToString(true), cond->ConditionValue2);
                return false;
            }
            break;
        }
        case CONDITION_REACTION_TO:
        {
            if (cond->ConditionValue1 >= cond->GetMaxAvailableConditionTargets())
            {
                TC_LOG_ERROR("sql.sql", "{} has invalid ConditionValue1(ConditionTarget selection) ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            if (cond->ConditionValue1 == cond->ConditionTarget)
            {
                TC_LOG_ERROR("sql.sql", "{} has ConditionValue1(ConditionTarget selection) set to self ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            if (!cond->ConditionValue2)
            {
                TC_LOG_ERROR("sql.sql", "{} has invalid ConditionValue2(rankMask) ({}), skipped.", cond->ToString(true), cond->ConditionValue2);
                return false;
            }
            break;
        }
        case CONDITION_DISTANCE_TO:
        {
            if (cond->ConditionValue1 >= cond->GetMaxAvailableConditionTargets())
            {
                TC_LOG_ERROR("sql.sql", "{} has invalid ConditionValue1(ConditionTarget selection) ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            if (cond->ConditionValue1 == cond->ConditionTarget)
            {
                TC_LOG_ERROR("sql.sql", "{} has ConditionValue1(ConditionTarget selection) set to self ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            if (cond->ConditionValue3 >= COMP_TYPE_MAX)
            {
                TC_LOG_ERROR("sql.sql", "{} has invalid ComparisionType ({}), skipped.", cond->ToString(true), cond->ConditionValue3);
                return false;
            }
            break;
        }
        case CONDITION_HP_VAL:
        {
            if (cond->ConditionValue2 >= COMP_TYPE_MAX)
            {
                TC_LOG_ERROR("sql.sql", "{} has invalid ComparisionType ({}), skipped.", cond->ToString(true), cond->ConditionValue2);
                return false;
            }
            break;
        }
        case CONDITION_HP_PCT:
        {
            if (cond->ConditionValue1 > 100)
            {
                TC_LOG_ERROR("sql.sql", "{} has too big percent value ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            if (cond->ConditionValue2 >= COMP_TYPE_MAX)
            {
                TC_LOG_ERROR("sql.sql", "{} has invalid ComparisionType ({}), skipped.", cond->ToString(true), cond->ConditionValue2);
                return false;
            }
            break;
        }
        case CONDITION_WORLD_STATE:
        {
            if (!sWorldStateMgr->GetWorldStateTemplate(cond->ConditionValue1))
            {
                TC_LOG_ERROR("sql.sql", "{} has non existing world state in value1 ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_PHASEID:
        {
            if (!sPhaseStore.LookupEntry(cond->ConditionValue1))
            {
                TC_LOG_ERROR("sql.sql", "{} has nonexistent phaseid in value1 ({}), skipped", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_TITLE:
        {
            CharTitlesEntry const* titleEntry = sCharTitlesStore.LookupEntry(cond->ConditionValue1);
            if (!titleEntry)
            {
                TC_LOG_ERROR("sql.sql", "{} has non existing title in value1 ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_SPAWNMASK_DEPRECATED:
        {
            TC_LOG_ERROR("sql.sql", "{} using deprecated condition type CONDITION_SPAWNMASK.", cond->ToString(true));
            return false;
        }
        case CONDITION_UNIT_STATE:
        {
            if (!(cond->ConditionValue1 & UNIT_STATE_ALL_STATE_SUPPORTED))
            {
                TC_LOG_ERROR("sql.sql", "{} has non existing UnitState in value1 ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_CREATURE_TYPE:
        {
            if (!cond->ConditionValue1 || cond->ConditionValue1 > CREATURE_TYPE_GAS_CLOUD)
            {
                TC_LOG_ERROR("sql.sql", "{} has non existing CreatureType in value1 ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_REALM_ACHIEVEMENT:
        {
            AchievementEntry const* achievement = sAchievementStore.LookupEntry(cond->ConditionValue1);
            if (!achievement)
            {
                TC_LOG_ERROR("sql.sql", "{} has non existing realm first achivement id ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_STAND_STATE:
        {
            bool valid = false;
            switch (cond->ConditionValue1)
            {
                case 0:
                    valid = cond->ConditionValue2 <= UNIT_STAND_STATE_SUBMERGED;
                    break;
                case 1:
                    valid = cond->ConditionValue2 <= 1;
                    break;
                default:
                    valid = false;
                    break;
            }
            if (!valid)
            {
                TC_LOG_ERROR("sql.sql", "{} has non-existing stand state ({},{}), skipped.", cond->ToString(true), cond->ConditionValue1, cond->ConditionValue2);
                return false;
            }
            break;
        }
        case CONDITION_QUEST_OBJECTIVE_PROGRESS:
        {
            QuestObjective const* obj = sObjectMgr->GetQuestObjective(cond->ConditionValue1);
            if (!obj)
            {
                TC_LOG_ERROR("sql.sql", "{} points to non-existing quest objective ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            int32 limit = obj->IsStoringFlag() ? 1 : obj->Amount;
            if (int32(cond->ConditionValue3) > limit)
            {
                TC_LOG_ERROR("sql.sql", "{} has quest objective count {} in value3, but quest objective {} has a maximum objective count of {}, skipped.", cond->ToString(true), cond->ConditionValue3, cond->ConditionValue1, limit);
                return false;
            }
            break;
        }
        case CONDITION_PET_TYPE:
            if (cond->ConditionValue1 >= (1 << MAX_PET_TYPE))
            {
                TC_LOG_ERROR("sql.sql", "{} has non-existing pet type {}, skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            break;
        case CONDITION_INSTANCE_INFO:
            if (cond->ConditionValue3 == INSTANCE_INFO_GUID_DATA)
            {
                TC_LOG_ERROR("sql.sql", "{} has unsupported ConditionValue3 {} (INSTANCE_INFO_GUID_DATA), skipped.", cond->ToString(true), cond->ConditionValue3);
                return false;
            }
            break;
        case CONDITION_AREAID:
        case CONDITION_ALIVE:
        case CONDITION_IN_WATER:
        case CONDITION_TERRAIN_SWAP:
        case CONDITION_CHARMED:
        case CONDITION_TAXI:
        case CONDITION_GAMEMASTER:
        case CONDITION_PRIVATE_OBJECT:
            break;
        case CONDITION_DIFFICULTY_ID:
            if (!sDifficultyStore.LookupEntry(cond->ConditionValue1))
            {
                TC_LOG_ERROR("sql.sql", "{} has non existing difficulty in value1 ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            break;
        case CONDITION_BATTLE_PET_COUNT:
            if (!sBattlePetSpeciesStore.LookupEntry(cond->ConditionValue1))
            {
                TC_LOG_ERROR("sql.sql", "{} has non existing BattlePet SpeciesId in value1 ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            if (cond->ConditionValue2 > BattlePets::DEFAULT_MAX_BATTLE_PETS_PER_SPECIES)
            {
                TC_LOG_ERROR("sql.sql", "{} has invalid (greater than {}) value2 ({}), skipped.", cond->ToString(true),
                    uint32(BattlePets::DEFAULT_MAX_BATTLE_PETS_PER_SPECIES), cond->ConditionValue2);
                return false;
            }
            if (cond->ConditionValue3 >= COMP_TYPE_MAX)
            {
                TC_LOG_ERROR("sql.sql", "{} has invalid ComparisionType ({}), skipped.", cond->ToString(true), cond->ConditionValue3);
                return false;
            }
            break;
        case CONDITION_SCENARIO_STEP:
        {
            if (!sScenarioStepStore.LookupEntry(cond->ConditionValue1))
            {
                TC_LOG_ERROR("sql.sql", "{} has non existing ScenarioStep in value1 ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_SCENE_IN_PROGRESS:
        {
            if (!sSceneScriptPackageStore.LookupEntry(cond->ConditionValue1))
            {
                TC_LOG_ERROR("sql.sql", "{} has non existing SceneScriptPackageId in value1 ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_PLAYER_CONDITION:
        {
            if (!sPlayerConditionStore.LookupEntry(cond->ConditionValue1))
            {
                TC_LOG_ERROR("sql.sql", "{} has non existing PlayerConditionId in value1 ({}), skipped.", cond->ToString(true), cond->ConditionValue1);
                return false;
            }
            break;
        }
        default:
            TC_LOG_ERROR("sql.sql", "{} Invalid ConditionType in `condition` table, ignoring.", cond->ToString());
            return false;
    }

    if (cond->ConditionTarget >= cond->GetMaxAvailableConditionTargets())
    {
        TC_LOG_ERROR("sql.sql", "{} in `condition` table, has incorrect ConditionTarget set, ignoring.", cond->ToString(true));
        return false;
    }

    if (cond->ConditionValue1 && !StaticConditionTypeData[cond->ConditionType].HasConditionValue1)
        LogUselessConditionValue(cond, 1, cond->ConditionValue1);
    if (cond->ConditionValue2 && !StaticConditionTypeData[cond->ConditionType].HasConditionValue2)
        LogUselessConditionValue(cond, 2, cond->ConditionValue2);
    if (cond->ConditionValue3 && !StaticConditionTypeData[cond->ConditionType].HasConditionValue3)
        LogUselessConditionValue(cond, 3, cond->ConditionValue3);
    if (!cond->ConditionStringValue1.empty() && !StaticConditionTypeData[cond->ConditionType].HasConditionStringValue1)
        LogUselessConditionValue(cond, 1, cond->ConditionStringValue1);

    return true;
}

void ConditionMgr::LogUselessConditionValue(Condition const* cond, uint8 index, uint32 value)
{
    TC_LOG_ERROR("sql.sql", "{} has useless data in ConditionValue{} ({})!", cond->ToString(true), index, value);
}

void ConditionMgr::LogUselessConditionValue(Condition const* cond, uint8 index, std::string_view value)
{
    TC_LOG_ERROR("sql.sql", "{} has useless data in ConditionStringValue{} ({})!", cond->ToString(true), index, value);
}

void ConditionMgr::Clean()
{
    for (std::unordered_map<ConditionId, std::shared_ptr<std::vector<Condition>>>& conditionsMap : ConditionStore)
        conditionsMap.clear();

    SpellsUsedInSpellClickConditions.clear();
}

inline bool PlayerConditionCompare(int32 comparisonType, int32 value1, int32 value2)
{
    switch (comparisonType)
    {
        case 1:
            return value1 == value2;
        case 2:
            return value1 != value2;
        case 3:
            return value1 > value2;
        case 4:
            return value1 >= value2;
        case 5:
            return value1 < value2;
        case 6:
            return value1 <= value2;
        default:
            break;
    }
    return false;
}

template<std::size_t N>
inline bool PlayerConditionLogic(uint32 logic, std::array<bool, N>& results)
{
    static_assert(N < 16, "Logic array size must be equal to or less than 16");

    for (std::size_t i = 0; i < results.size(); ++i)
        if ((logic >> (16 + i)) & 1)
            results[i] ^= true;

    bool result = results[0];
    for (std::size_t i = 1; i < results.size(); ++i)
    {
        switch ((logic >> (2 * (i - 1))) & 3)
        {
            case 1:
                result = result && results[i];
                break;
            case 2:
                result = result || results[i];
                break;
            default:
                break;
        }
    }

    return result;
}

uint32 ConditionMgr::GetPlayerConditionLfgValue(Player const* player, PlayerConditionLfgStatus status)
{
    Group const* group = player->GetGroup();
    if (!group)
        return 0;

    switch (status)
    {
        case PlayerConditionLfgStatus::InLFGDungeon:
            return sLFGMgr->inLfgDungeonMap(player->GetGUID(), player->GetMapId(), player->GetMap()->GetDifficultyID()) ? 1 : 0;
        case PlayerConditionLfgStatus::InLFGRandomDungeon:
            return sLFGMgr->inLfgDungeonMap(player->GetGUID(), player->GetMapId(), player->GetMap()->GetDifficultyID()) &&
                sLFGMgr->selectedRandomLfgDungeon(player->GetGUID()) ? 1 : 0;
        case PlayerConditionLfgStatus::InLFGFirstRandomDungeon:
        {
            if (!sLFGMgr->inLfgDungeonMap(player->GetGUID(), player->GetMapId(), player->GetMap()->GetDifficultyID()))
                return 0;

            uint32 selectedRandomDungeon = sLFGMgr->GetSelectedRandomDungeon(player->GetGUID());
            if (!selectedRandomDungeon)
                return 0;

            if (lfg::LfgReward const* reward = sLFGMgr->GetRandomDungeonReward(selectedRandomDungeon, player->GetLevel()))
                if (Quest const* quest = sObjectMgr->GetQuestTemplate(reward->firstQuest))
                    if (player->CanRewardQuest(quest, false))
                        return 1;
            return 0;
        }
        case PlayerConditionLfgStatus::PartialClear:
            break;
        case PlayerConditionLfgStatus::StrangerCount:
            break;
        case PlayerConditionLfgStatus::VoteKickCount:
            break;
        case PlayerConditionLfgStatus::BootCount:
            break;
        case PlayerConditionLfgStatus::GearDiff:
            break;
        default:
            break;
    }

    return 0;
}

bool ConditionMgr::IsPlayerMeetingCondition(Player const* player, PlayerConditionEntry const* condition)
{
    if (Optional<ContentTuningLevels> levels = sDB2Manager.GetContentTuningData(condition->ContentTuningID, player->m_playerData->CtrOptions->ContentTuningConditionMask))
    {
        uint8 minLevel = condition->Flags & 0x800 ? levels->MinLevelWithDelta : levels->MinLevel;
        uint8 maxLevel = 0;
        if (!(condition->Flags & 0x20))
            maxLevel = condition->Flags & 0x800 ? levels->MaxLevelWithDelta : levels->MaxLevel;

        if (condition->Flags & 0x80)
        {
            if (minLevel && player->GetLevel() >= minLevel && (!maxLevel || player->GetLevel() <= maxLevel))
                return false;

            if (maxLevel && player->GetLevel() <= maxLevel && (!minLevel || player->GetLevel() >= minLevel))
                return false;
        }
        else
        {
            if (minLevel && player->GetLevel() < minLevel)
                return false;

            if (maxLevel && player->GetLevel() > maxLevel)
                return false;
        }
    }

    if (!condition->RaceMask.IsEmpty() && !condition->RaceMask.HasRace(player->GetRace()))
        return false;

    if (condition->ClassMask && !(player->GetClassMask() & condition->ClassMask))
        return false;

    if (condition->Gender >= 0 && player->GetGender() != condition->Gender)
        return false;

    if (condition->NativeGender >= 0 && player->GetNativeGender() != condition->NativeGender)
        return false;

    if (condition->PowerType != -1 && condition->PowerTypeComp)
    {
        int32 requiredPowerValue = condition->Flags & 4 ? player->GetMaxPower(Powers(condition->PowerType)) : condition->PowerTypeValue;
        if (!PlayerConditionCompare(condition->PowerTypeComp, player->GetPower(Powers(condition->PowerType)), requiredPowerValue))
            return false;
    }

    if (condition->ChrSpecializationIndex >= 0 || condition->ChrSpecializationRole >= 0)
    {
        if (ChrSpecializationEntry const* spec = sChrSpecializationStore.LookupEntry(AsUnderlyingType(player->GetPrimarySpecialization())))
        {
            if (condition->ChrSpecializationIndex >= 0 && spec->OrderIndex != condition->ChrSpecializationIndex)
                return false;

            if (condition->ChrSpecializationRole >= 0 && spec->Role != condition->ChrSpecializationRole)
                return false;
        }
    }

    if (condition->SkillID[0] || condition->SkillID[1] || condition->SkillID[2] || condition->SkillID[3])
    {
        std::array<bool, std::tuple_size_v<decltype(condition->SkillID)>> results;
        results.fill(true);
        for (std::size_t i = 0; i < condition->SkillID.size(); ++i)
        {
            if (condition->SkillID[i])
            {
                uint16 skillValue = player->GetSkillValue(condition->SkillID[i]);
                results[i] = skillValue != 0 && skillValue > condition->MinSkill[i] && skillValue < condition->MaxSkill[i];
            }
        }

        if (!PlayerConditionLogic(condition->SkillLogic, results))
            return false;
    }

    if (condition->LanguageID)
    {
        int32 languageSkill = 0;
        if (player->HasAuraTypeWithMiscvalue(SPELL_AURA_COMPREHEND_LANGUAGE, condition->LanguageID))
            languageSkill = 300;
        else
        {
            for (std::pair<uint32 const, LanguageDesc> const& languageDesc : sLanguageMgr->GetLanguageDescById(Language(condition->LanguageID)))
                languageSkill = std::max<int32>(languageSkill, player->GetSkillValue(languageDesc.second.SkillId));
        }

        if (condition->MinLanguage && languageSkill < condition->MinLanguage)
            return false;

        if (condition->MaxLanguage && languageSkill > condition->MaxLanguage)
            return false;
    }

    if (condition->MinFactionID[0] || condition->MinFactionID[1] || condition->MinFactionID[2] || condition->MaxFactionID)
    {
        if (!condition->MinFactionID[0] && !condition->MinFactionID[1] && !condition->MinFactionID[2])
        {
            if (ReputationRank const* forcedRank = player->GetReputationMgr().GetForcedRankIfAny(condition->MaxFactionID))
            {
                if (*forcedRank > ReputationRank(condition->MaxReputation))
                    return false;
            }
            else if (sFactionStore.HasRecord(condition->MaxReputation) && player->GetReputationRank(condition->MaxFactionID) > ReputationRank(condition->MaxReputation))
                return false;
        }
        else
        {
            std::array<bool, std::tuple_size_v<decltype(condition->MinFactionID)> + 1> results;
            results.fill(true);
            for (std::size_t i = 0; i < condition->MinFactionID.size(); ++i)
            {
                if (sFactionStore.HasRecord(condition->MinFactionID[i]))
                {
                    if (ReputationRank const* forcedRank = player->GetReputationMgr().GetForcedRankIfAny(condition->MinFactionID[i]))
                        results[i] = *forcedRank >= ReputationRank(condition->MinReputation[i]);
                    else
                        results[i] = player->GetReputationRank(condition->MinFactionID[i]) >= ReputationRank(condition->MinReputation[i]);
                }
            }

            if (ReputationRank const* forcedRank = player->GetReputationMgr().GetForcedRankIfAny(condition->MaxFactionID))
                results[3] = *forcedRank <= ReputationRank(condition->MaxReputation);
            else if (sFactionStore.HasRecord(condition->MaxReputation))
                results[3] = player->GetReputationRank(condition->MaxFactionID) <= ReputationRank(condition->MaxReputation);

            if (!PlayerConditionLogic(condition->ReputationLogic, results))
                return false;
        }
    }

    if (condition->CurrentPvpFaction)
    {
        int8 team;
        if (player->GetMap()->IsBattlegroundOrArena())
            team = player->m_playerData->ArenaFaction;
        else
            team = player->GetTeamId();

        if (condition->CurrentPvpFaction - 1 != team)
            return false;
    }

    if (condition->PvpMedal && !((1 << (condition->PvpMedal - 1)) & *player->m_activePlayerData->PvpMedals))
        return false;

    if (condition->LifetimeMaxPVPRank && player->m_activePlayerData->LifetimeMaxRank != condition->LifetimeMaxPVPRank)
        return false;

    if (condition->MovementFlags[0] && !(player->GetUnitMovementFlags() & condition->MovementFlags[0]))
        return false;

    if (condition->MovementFlags[1] && !(player->GetExtraUnitMovementFlags() & condition->MovementFlags[1]))
        return false;

    if (condition->WeaponSubclassMask)
    {
        Item* mainHand = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
        if (!mainHand || !((1 << mainHand->GetTemplate()->GetSubClass()) & condition->WeaponSubclassMask))
            return false;
    }

    if (condition->PartyStatus)
    {
        Group const* group = player->GetGroup();
        switch (condition->PartyStatus)
        {
            case 1:
                if (group)
                    return false;
                break;
            case 2:
                if (!group)
                    return false;
                break;
            case 3:
                if (!group || group->isRaidGroup())
                    return false;
                break;
            case 4:
                if (!group || !group->isRaidGroup())
                    return false;
                break;
            case 5:
                if (group && group->isRaidGroup())
                    return false;
                break;
            default:
                break;
        }
    }

    if (condition->PrevQuestID[0])
    {
        std::array<bool, std::tuple_size_v<decltype(condition->PrevQuestID)>> results;
        results.fill(true);
        for (std::size_t i = 0; i < condition->PrevQuestID.size(); ++i)
            if (uint32 questBit = sDB2Manager.GetQuestUniqueBitFlag(condition->PrevQuestID[i]))
                results[i] = (player->m_activePlayerData->QuestCompleted[((questBit - 1) >> 6)] & (UI64LIT(1) << ((questBit - 1) & 63))) != 0;

        if (!PlayerConditionLogic(condition->PrevQuestLogic, results))
            return false;
    }

    if (condition->CurrQuestID[0])
    {
        std::array<bool, std::tuple_size_v<decltype(condition->CurrQuestID)>> results;
        results.fill(true);
        for (std::size_t i = 0; i < condition->CurrQuestID.size(); ++i)
            if (condition->CurrQuestID[i])
                results[i] = player->FindQuestSlot(condition->CurrQuestID[i]) != MAX_QUEST_LOG_SIZE;

        if (!PlayerConditionLogic(condition->CurrQuestLogic, results))
            return false;
    }

    if (condition->CurrentCompletedQuestID[0])
    {
        std::array<bool, std::tuple_size_v<decltype(condition->CurrentCompletedQuestID)>> results;
        results.fill(true);
        for (std::size_t i = 0; i < condition->CurrentCompletedQuestID.size(); ++i)
            if (condition->CurrentCompletedQuestID[i])
                results[i] = player->GetQuestStatus(condition->CurrentCompletedQuestID[i]) == QUEST_STATUS_COMPLETE;

        if (!PlayerConditionLogic(condition->CurrentCompletedQuestLogic, results))
            return false;
    }

    if (condition->SpellID[0])
    {
        std::array<bool, std::tuple_size_v<decltype(condition->SpellID)>> results;
        results.fill(true);
        for (std::size_t i = 0; i < condition->SpellID.size(); ++i)
            if (condition->SpellID[i])
                results[i] = player->HasSpell(condition->SpellID[i]);

        if (!PlayerConditionLogic(condition->SpellLogic, results))
            return false;
    }

    if (condition->ItemID[0])
    {
        std::array<bool, std::tuple_size_v<decltype(condition->ItemID)>> results;
        results.fill(true);
        for (std::size_t i = 0; i < condition->ItemID.size(); ++i)
            if (condition->ItemID[i])
                results[i] = player->GetItemCount(condition->ItemID[i], condition->ItemFlags != 0) >= condition->ItemCount[i];

        if (!PlayerConditionLogic(condition->ItemLogic, results))
            return false;
    }

    if (condition->CurrencyID[0])
    {
        std::array<bool, std::tuple_size_v<decltype(condition->CurrencyID)>> results;
        results.fill(true);
        for (std::size_t i = 0; i < condition->CurrencyID.size(); ++i)
            if (condition->CurrencyID[i])
                results[i] = player->GetCurrencyQuantity(condition->CurrencyID[i]) >= condition->CurrencyCount[i];

        if (!PlayerConditionLogic(condition->CurrencyLogic, results))
            return false;
    }

    if (condition->Explored[0] || condition->Explored[1])
    {
        for (std::size_t i = 0; i < condition->Explored.size(); ++i)
            if (AreaTableEntry const* area = sAreaTableStore.LookupEntry(condition->Explored[i]))
                if (!player->HasExploredZone(area->ID))
                    return false;
    }

    if (condition->AuraSpellID[0])
    {
        std::array<bool, std::tuple_size_v<decltype(condition->AuraSpellID)>> results;
        results.fill(true);
        for (std::size_t i = 0; i < condition->AuraSpellID.size(); ++i)
        {
            if (condition->AuraSpellID[i])
            {
                if (condition->AuraStacks[i])
                    results[i] = player->GetAuraCount(condition->AuraSpellID[i]) >= condition->AuraStacks[i];
                else
                    results[i] = player->HasAura(condition->AuraSpellID[i]);
            }
        }

        if (!PlayerConditionLogic(condition->AuraSpellLogic, results))
            return false;
    }

    if (condition->Time[0])
    {
        WowTime time0;
        time0.SetPackedTime(condition->Time[0]);

        if (condition->Time[1])
        {
            WowTime time1;
            time1.SetPackedTime(condition->Time[1]);

            if (!GameTime::GetWowTime()->IsInRange(time0, time1))
                return false;
        }
        else if (*GameTime::GetWowTime() != time0)
            return false;
    }

    if (condition->WorldStateExpressionID)
    {
        WorldStateExpressionEntry const* worldStateExpression = sWorldStateExpressionStore.LookupEntry(condition->WorldStateExpressionID);
        if (!worldStateExpression)
            return false;

        if (!IsMeetingWorldStateExpression(player->GetMap(), worldStateExpression))
            return false;
    }

    if (condition->WeatherID)
        if (player->GetMap()->GetZoneWeather(player->GetZoneId()) != WeatherState(condition->WeatherID))
            return false;

    if (condition->Achievement[0])
    {
        std::array<bool, std::tuple_size_v<decltype(condition->Achievement)>> results;
        results.fill(true);
        for (std::size_t i = 0; i < condition->Achievement.size(); ++i)
        {
            if (condition->Achievement[i])
            {
                // if (condition->Flags & 2) { any character on account completed it } else { current character only }
                // TODO: part of accountwide achievements
                results[i] = player->HasAchieved(condition->Achievement[i]);
            }
        }

        if (!PlayerConditionLogic(condition->AchievementLogic, results))
            return false;
    }

    if (condition->LfgStatus[0])
    {
        std::array<bool, std::tuple_size_v<decltype(condition->LfgStatus)>> results;
        results.fill(true);
        for (std::size_t i = 0; i < condition->LfgStatus.size(); ++i)
            if (condition->LfgStatus[i])
                results[i] = PlayerConditionCompare(condition->LfgCompare[i],
                    GetPlayerConditionLfgValue(player, PlayerConditionLfgStatus(condition->LfgStatus[i])),
                    condition->LfgValue[i]);

        if (!PlayerConditionLogic(condition->LfgLogic, results))
            return false;
    }

    if (condition->AreaID[0])
    {
        std::array<bool, std::tuple_size_v<decltype(condition->AreaID)>> results;
        results.fill(true);
        for (std::size_t i = 0; i < condition->AreaID.size(); ++i)
            if (condition->AreaID[i])
                results[i] = DB2Manager::IsInArea(player->GetAreaId(), condition->AreaID[i]);

        if (!PlayerConditionLogic(condition->AreaLogic, results))
            return false;
    }

    if (condition->MinExpansionLevel != -1 && player->GetSession()->GetExpansion() < condition->MinExpansionLevel)
        return false;

    if (condition->MaxExpansionLevel != -1 && player->GetSession()->GetExpansion() > condition->MaxExpansionLevel)
        return false;

    if (condition->MinExpansionLevel != -1 && condition->MinExpansionTier != -1 && !player->IsGameMaster()
        && ((condition->MinExpansionLevel == int32(sWorld->getIntConfig(CONFIG_EXPANSION)) && condition->MinExpansionTier > 0) /*TODO: implement tier*/
        || condition->MinExpansionLevel > int32(sWorld->getIntConfig(CONFIG_EXPANSION))))
        return false;

    if (condition->PhaseID || condition->PhaseGroupID || condition->PhaseUseFlags)
        if (!PhasingHandler::InDbPhaseShift(player, condition->PhaseUseFlags, condition->PhaseID, condition->PhaseGroupID))
            return false;

    if (condition->QuestKillID)
    {
        Quest const* quest = sObjectMgr->GetQuestTemplate(condition->QuestKillID);
        uint16 questSlot = player->FindQuestSlot(condition->QuestKillID);
        if (quest && player->GetQuestStatus(condition->QuestKillID) != QUEST_STATUS_COMPLETE && questSlot < MAX_QUEST_LOG_SIZE)
        {
            std::array<bool, std::tuple_size_v<decltype(condition->QuestKillMonster)>> results;
            results.fill(true);
            for (std::size_t i = 0; i < condition->QuestKillMonster.size(); ++i)
            {
                if (condition->QuestKillMonster[i])
                {
                    auto objectiveItr = std::find_if(quest->GetObjectives().begin(), quest->GetObjectives().end(), [condition, i](QuestObjective const& objective) -> bool
                    {
                        return objective.Type == QUEST_OBJECTIVE_MONSTER && uint32(objective.ObjectID) == condition->QuestKillMonster[i];
                    });
                    if (objectiveItr != quest->GetObjectives().end())
                        results[i] = player->GetQuestSlotObjectiveData(questSlot, *objectiveItr) >= objectiveItr->Amount;
                }
            }

            if (!PlayerConditionLogic(condition->QuestKillLogic, results))
                return false;
        }
    }

    if (condition->MinAvgItemLevel && int32(std::floor(player->m_playerData->AvgItemLevel[0])) < condition->MinAvgItemLevel)
        return false;

    if (condition->MaxAvgItemLevel && int32(std::floor(player->m_playerData->AvgItemLevel[0])) > condition->MaxAvgItemLevel)
        return false;

    if (condition->MinAvgEquippedItemLevel && uint32(std::floor(player->m_playerData->AvgItemLevel[1])) < condition->MinAvgEquippedItemLevel)
        return false;

    if (condition->MaxAvgEquippedItemLevel && uint32(std::floor(player->m_playerData->AvgItemLevel[1])) > condition->MaxAvgEquippedItemLevel)
        return false;

    if (condition->ModifierTreeID && !player->ModifierTreeSatisfied(condition->ModifierTreeID))
        return false;

    if (condition->CovenantID && player->m_playerData->CovenantID != condition->CovenantID)
        return false;

    if (std::any_of(condition->TraitNodeEntryID.begin(), condition->TraitNodeEntryID.end(), [](int32 traitNodeEntryId) { return traitNodeEntryId != 0; }))
    {
        auto getTraitNodeEntryRank = [player](int32 traitNodeEntryId) -> Optional<uint16>
        {
            for (UF::TraitConfig const& traitConfig : player->m_activePlayerData->TraitConfigs)
            {
                if (TraitConfigType(*traitConfig.Type) == TraitConfigType::Combat)
                {
                    if (int32(*player->m_activePlayerData->ActiveCombatTraitConfigID) != traitConfig.ID
                        || !EnumFlag(TraitCombatConfigFlags(*traitConfig.CombatConfigFlags)).HasFlag(TraitCombatConfigFlags::ActiveForSpec))
                        continue;
                }

                for (UF::TraitEntry const& traitEntry : traitConfig.Entries)
                    if (traitEntry.TraitNodeEntryID == traitNodeEntryId)
                        return traitEntry.Rank;
            }
            return {};
        };

        std::array<bool, std::tuple_size_v<decltype(condition->TraitNodeEntryID)>> results;
        results.fill(true);
        for (std::size_t i = 0; i < condition->TraitNodeEntryID.size(); ++i)
        {
            if (!condition->TraitNodeEntryID[i])
                continue;

            Optional<int32> rank = getTraitNodeEntryRank(condition->TraitNodeEntryID[i]);
            if (!rank)
                results[i] = false;
            else if (condition->TraitNodeEntryMinRank[i] && rank < condition->TraitNodeEntryMinRank[i])
                results[i] = false;
            else if (condition->TraitNodeEntryMaxRank[i] && rank > condition->TraitNodeEntryMaxRank[i])
                results[i] = false;
        }

        if (!PlayerConditionLogic(condition->TraitNodeEntryLogic, results))
            return false;
    }

    return true;
}

ByteBuffer HexToBytes(const std::string& hex)
{
    ByteBuffer buffer(hex.length() / 2, ByteBuffer::Resize{});
    Trinity::Impl::HexStrToByteArray(hex, buffer.contents(), buffer.size());
    return buffer;
}

static int32(* const WorldStateExpressionFunctions[WSE_FUNCTION_MAX])(Map const*, uint32, uint32) =
{
    // WSE_FUNCTION_NONE
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_RANDOM
    [](Map const* /*map*/, uint32 arg1, uint32 arg2) -> int32
    {
        return irand(std::min(arg1, arg2), std::max(arg1, arg2));
    },

    // WSE_FUNCTION_MONTH
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return GameTime::GetDateAndTime()->tm_mon + 1;
    },

    // WSE_FUNCTION_DAY
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return GameTime::GetDateAndTime()->tm_mday + 1;
    },

    // WSE_FUNCTION_TIME_OF_DAY
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        tm const* localTime = GameTime::GetDateAndTime();
        return localTime->tm_hour * MINUTE + localTime->tm_min;
    },

    // WSE_FUNCTION_REGION
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return realm.Id.Region;
    },

    // WSE_FUNCTION_CLOCK_HOUR
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        uint32 currentHour = GameTime::GetDateAndTime()->tm_hour + 1;
        return currentHour <= 12 ? (currentHour ? currentHour : 12) : currentHour - 12;
    },

    // WSE_FUNCTION_OLD_DIFFICULTY_ID
    [](Map const* map, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        if (DifficultyEntry const* difficulty = sDifficultyStore.LookupEntry(map->GetDifficultyID()))
            return difficulty->OldEnumValue;

        return -1;
    },

    // WSE_FUNCTION_HOLIDAY_START
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_HOLIDAY_LEFT
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_HOLIDAY_ACTIVE
    [](Map const* /*map*/, uint32 arg1, uint32 /*arg2*/) -> int32
    {
        return int32(IsHolidayActive(HolidayIds(arg1)));
    },

    // WSE_FUNCTION_TIMER_CURRENT_TIME
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return GameTime::GetGameTime();
    },

    // WSE_FUNCTION_WEEK_NUMBER
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        time_t now = GameTime::GetGameTime();
        uint32 raidOrigin = 1135695600;
        if (Cfg_RegionsEntry const* region = sCfgRegionsStore.LookupEntry(realm.Id.Region))
            raidOrigin = region->Raidorigin;

        return (now - raidOrigin) / WEEK;
    },

    // WSE_FUNCTION_UNK13
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK14
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_DIFFICULTY_ID
    [](Map const* map, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return map->GetDifficultyID();
    },

    // WSE_FUNCTION_WAR_MODE_ACTIVE
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        // check if current zone/map is bound to war mode
        return 0;
    },

    // WSE_FUNCTION_UNK17
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK18
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK19
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK20
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK21
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_WORLD_STATE_EXPRESSION
    [](Map const* map, uint32 arg1, uint32 /*arg2*/) -> int32
    {
        if (WorldStateExpressionEntry const* worldStateExpression = sWorldStateExpressionStore.LookupEntry(arg1))
            return ConditionMgr::IsMeetingWorldStateExpression(map, worldStateExpression);

        return 0;
    },

    // WSE_FUNCTION_KEYSTONE_AFFIX
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK24
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK25
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK26
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK27
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_KEYSTONE_LEVEL
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK29
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK30
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK31
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK32
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_MERSENNE_RANDOM
    [](Map const* /*map*/, uint32 arg1, uint32 arg2) -> int32
    {
        if (arg1 == 1)
            return 1;

        // init with predetermined seed
        std::mt19937 mt(arg2 ? arg2 : 1);
        return mt() % arg1 + 1;
    },

    // WSE_FUNCTION_UNK34
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK35
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK36
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UI_WIDGET_DATA
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_TIME_EVENT_PASSED
    [](Map const* /*map*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },
};

int32 EvalSingleValue(ByteBuffer& buffer, Map const* map)
{
    WorldStateExpressionValueType valueType = buffer.read<WorldStateExpressionValueType>();
    int32 value = 0;

    switch (valueType)
    {
        case WorldStateExpressionValueType::Constant:
        {
            value = buffer.read<int32>();
            break;
        }
        case WorldStateExpressionValueType::WorldState:
        {
            uint32 worldStateId = buffer.read<uint32>();
            value = sWorldStateMgr->GetValue(worldStateId, map);
            break;
        }
        case WorldStateExpressionValueType::Function:
        {
            uint32 functionType = buffer.read<uint32>();
            int32 arg1 = EvalSingleValue(buffer, map);
            int32 arg2 = EvalSingleValue(buffer, map);

            if (functionType >= WSE_FUNCTION_MAX)
                return 0;

            value = WorldStateExpressionFunctions[functionType](map, arg1, arg2);
            break;
        }
        default:
            break;
    }

    return value;
}

int32 EvalValue(ByteBuffer& buffer, Map const* map)
{
    int32 leftValue = EvalSingleValue(buffer, map);

    WorldStateExpressionOperatorType operatorType = buffer.read<WorldStateExpressionOperatorType>();
    if (operatorType == WorldStateExpressionOperatorType::None)
        return leftValue;

    int32 rightValue = EvalSingleValue(buffer, map);

    switch (operatorType)
    {
        case WorldStateExpressionOperatorType::Sum:             return leftValue + rightValue;
        case WorldStateExpressionOperatorType::Substraction:    return leftValue - rightValue;
        case WorldStateExpressionOperatorType::Multiplication:  return leftValue * rightValue;
        case WorldStateExpressionOperatorType::Division:        return !rightValue ? 0 : leftValue / rightValue;
        case WorldStateExpressionOperatorType::Remainder:       return !rightValue ? 0 : leftValue % rightValue;
        default:
            break;
    }

    return leftValue;
}

bool EvalRelOp(ByteBuffer& buffer, Map const* map)
{
    int32 leftValue = EvalValue(buffer, map);

    WorldStateExpressionComparisonType compareLogic = buffer.read<WorldStateExpressionComparisonType>();
    if (compareLogic == WorldStateExpressionComparisonType::None)
        return leftValue != 0;

    int32 rightValue = EvalValue(buffer, map);

    switch (compareLogic)
    {
        case WorldStateExpressionComparisonType::Equal:             return leftValue == rightValue;
        case WorldStateExpressionComparisonType::NotEqual:          return leftValue != rightValue;
        case WorldStateExpressionComparisonType::Less:              return leftValue <  rightValue;
        case WorldStateExpressionComparisonType::LessOrEqual:       return leftValue <= rightValue;
        case WorldStateExpressionComparisonType::Greater:           return leftValue >  rightValue;
        case WorldStateExpressionComparisonType::GreaterOrEqual:    return leftValue >= rightValue;
        default:
            break;
    }

    return false;
}

bool ConditionMgr::IsMeetingWorldStateExpression(Map const* map, WorldStateExpressionEntry const* expression)
{
    ByteBuffer buffer = HexToBytes(expression->Expression);
    if (buffer.empty())
        return false;

    bool enabled = buffer.read<bool>();
    if (!enabled)
        return false;

    bool finalResult = EvalRelOp(buffer, map);
    WorldStateExpressionLogic resultLogic = buffer.read<WorldStateExpressionLogic>();

    while (resultLogic != WorldStateExpressionLogic::None)
    {
        bool secondResult = EvalRelOp(buffer, map);

        switch (resultLogic)
        {
            case WorldStateExpressionLogic::And: finalResult = finalResult && secondResult; break;
            case WorldStateExpressionLogic::Or:  finalResult = finalResult || secondResult; break;
            case WorldStateExpressionLogic::Xor: finalResult = finalResult != secondResult; break;
            default:
                break;
        }

        if (buffer.rpos() >= buffer.size())
            break;

        resultLogic = buffer.read<WorldStateExpressionLogic>();
    }

    return finalResult;
}

int32 GetUnitConditionVariable(Unit const* unit, Unit const* otherUnit, UnitConditionVariable variable, int32 value)
{
    switch (variable)
    {
        case UnitConditionVariable::Race:
            return unit->GetRace();
        case UnitConditionVariable::Class:
            return unit->GetClass();
        case UnitConditionVariable::Level:
            return unit->GetLevel();
        case UnitConditionVariable::IsSelf:
            return unit == otherUnit;
        case UnitConditionVariable::IsMyPet:
            return otherUnit && unit->GetCharmerOrOwnerGUID() == otherUnit->GetGUID();
        case UnitConditionVariable::IsMaster:
            return otherUnit && otherUnit->GetCharmerOrOwnerGUID() == unit->GetGUID();
        case UnitConditionVariable::IsTarget:
            return otherUnit && otherUnit->GetTarget() == unit->GetGUID();
        case UnitConditionVariable::CanAssist:
            return otherUnit && unit->IsValidAssistTarget(otherUnit);
        case UnitConditionVariable::CanAttack:
            return otherUnit && unit->IsValidAttackTarget(otherUnit);
        case UnitConditionVariable::HasPet:
            return !unit->GetCharmedGUID().IsEmpty() || !unit->GetMinionGUID().IsEmpty();
        case UnitConditionVariable::HasWeapon:
            if (Player const* player = unit->ToPlayer())
                return player->GetWeaponForAttack(BASE_ATTACK) || player->GetWeaponForAttack(OFF_ATTACK);
            return unit->GetVirtualItemId(0) || unit->GetVirtualItemId(1);
        case UnitConditionVariable::HealthPct:
            return unit->GetHealthPct();
        case UnitConditionVariable::ManaPct:
            return unit->GetPowerPct(POWER_MANA);
        case UnitConditionVariable::RagePct:
            return unit->GetPowerPct(POWER_RAGE);
        case UnitConditionVariable::EnergyPct:
            return unit->GetPowerPct(POWER_ENERGY);
        case UnitConditionVariable::ComboPoints:
            return unit->GetPower(POWER_COMBO_POINTS);
        case UnitConditionVariable::HasHelpfulAuraSpell:
            return unit->GetAuraApplication(value, [](AuraApplication const* aurApp)
            {
                return (aurApp->GetFlags() & AFLAG_NEGATIVE) == 0;
            }) != nullptr ? value : 0;
        case UnitConditionVariable::HasHelpfulAuraDispelType:
            return unit->GetAuraApplication([value](AuraApplication const* aurApp)
            {
                return (aurApp->GetFlags() & AFLAG_NEGATIVE) == 0 && int32(aurApp->GetBase()->GetSpellInfo()->Dispel) == value;
            }) != nullptr ? value : 0;
        case UnitConditionVariable::HasHelpfulAuraMechanic:
            return unit->GetAuraApplication([value](AuraApplication const* aurApp)
            {
                return (aurApp->GetFlags() & AFLAG_NEGATIVE) == 0 && (aurApp->GetBase()->GetSpellInfo()->GetSpellMechanicMaskByEffectMask(aurApp->GetEffectMask()) & (UI64LIT(1) << value)) != 0;
            }) != nullptr ? value : 0;
        case UnitConditionVariable::HasHarmfulAuraSpell:
            return unit->GetAuraApplication(value, [](AuraApplication const* aurApp)
            {
                return (aurApp->GetFlags() & AFLAG_NEGATIVE) != 0;
            }) != nullptr ? value : 0;
        case UnitConditionVariable::HasHarmfulAuraDispelType:
            return unit->GetAuraApplication([value](AuraApplication const* aurApp)
            {
                return (aurApp->GetFlags() & AFLAG_NEGATIVE) != 0 && int32(aurApp->GetBase()->GetSpellInfo()->Dispel) == value;
            }) != nullptr ? value : 0;
        case UnitConditionVariable::HasHarmfulAuraMechanic:
            return unit->GetAuraApplication([value](AuraApplication const* aurApp)
            {
                return (aurApp->GetFlags() & AFLAG_NEGATIVE) != 0 && (aurApp->GetBase()->GetSpellInfo()->GetSpellMechanicMaskByEffectMask(aurApp->GetEffectMask()) & (UI64LIT(1) << value)) != 0;
            }) != nullptr ? value : 0;
        case UnitConditionVariable::HasHarmfulAuraSchool:
            return unit->GetAuraApplication([value](AuraApplication const* aurApp)
            {
                return (aurApp->GetFlags() & AFLAG_NEGATIVE) != 0 && (aurApp->GetBase()->GetSpellInfo()->GetSchoolMask() & (1 << value)) != 0;
            }) != nullptr ? value : 0;
        case UnitConditionVariable::DamagePhysicalPct:
            break;
        case UnitConditionVariable::DamageHolyPct:
            break;
        case UnitConditionVariable::DamageFirePct:
            break;
        case UnitConditionVariable::DamageNaturePct:
            break;
        case UnitConditionVariable::DamageFrostPct:
            break;
        case UnitConditionVariable::DamageShadowPct:
            break;
        case UnitConditionVariable::DamageArcanePct:
            break;
        case UnitConditionVariable::InCombat:
            return unit->IsInCombat();
        case UnitConditionVariable::IsMoving:
            return unit->HasUnitMovementFlag(MOVEMENTFLAG_FORWARD | MOVEMENTFLAG_BACKWARD | MOVEMENTFLAG_STRAFE_LEFT | MOVEMENTFLAG_STRAFE_RIGHT);
        case UnitConditionVariable::IsCasting:
        case UnitConditionVariable::IsCastingSpell: // this is supposed to return spell id by client code but data always has 0 or 1
            return unit->GetCurrentSpell(CURRENT_GENERIC_SPELL) != nullptr;
        case UnitConditionVariable::IsChanneling:
        case UnitConditionVariable::IsChannelingSpell: // this is supposed to return spell id by client code but data always has 0 or 1
            return unit->GetChannelSpellId() != 0;
        case UnitConditionVariable::NumberOfMeleeAttackers:
            return std::count_if(unit->getAttackers().begin(), unit->getAttackers().end(), [unit](Unit* attacker)
            {
                float distance = std::max(unit->GetCombatReach() + attacker->GetCombatReach() + 1.3333334f, 5.0f);
                if (unit->HasUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED) || attacker->HasUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED))
                    distance += 1.0f;
                return unit->GetExactDistSq(attacker) < distance * distance;
            });
        case UnitConditionVariable::IsAttackingMe:
            return otherUnit && unit->GetTarget() == otherUnit->GetGUID();
        case UnitConditionVariable::Range:
            return otherUnit ? int32(unit->GetExactDist(otherUnit)) : 0;
        case UnitConditionVariable::InMeleeRange:
            if (otherUnit)
            {
                float distance = std::max(unit->GetCombatReach() + otherUnit->GetCombatReach() + 1.3333334f, 5.0f);
                if (unit->HasUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED) || otherUnit->HasUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED))
                    distance += 1.0f;
                return unit->GetExactDistSq(otherUnit) < distance * distance;
            }
            return 0;
        case UnitConditionVariable::PursuitTime:
            break;
        case UnitConditionVariable::HasHarmfulAuraCanceledByDamage:
            return unit->HasNegativeAuraWithInterruptFlag(SpellAuraInterruptFlags::Damage);
        case UnitConditionVariable::HasHarmfulAuraWithPeriodicDamage:
            return unit->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE);
        case UnitConditionVariable::NumberOfEnemies:
            return unit->GetThreatManager().GetThreatListSize();
        case UnitConditionVariable::NumberOfFriends:
            break;
        case UnitConditionVariable::ThreatPhysicalPct:
            break;
        case UnitConditionVariable::ThreatHolyPct:
            break;
        case UnitConditionVariable::ThreatFirePct:
            break;
        case UnitConditionVariable::ThreatNaturePct:
            break;
        case UnitConditionVariable::ThreatFrostPct:
            break;
        case UnitConditionVariable::ThreatShadowPct:
            break;
        case UnitConditionVariable::ThreatArcanePct:
            break;
        case UnitConditionVariable::IsInterruptible:
            break;
        case UnitConditionVariable::NumberOfAttackers:
            return unit->getAttackers().size();
        case UnitConditionVariable::NumberOfRangedAttackers:
            return std::count_if(unit->getAttackers().begin(), unit->getAttackers().end(), [unit](Unit* attacker)
            {
                float distance = std::max(unit->GetCombatReach() + attacker->GetCombatReach() + 1.3333334f, 5.0f);
                if (unit->HasUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED) || attacker->HasUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED))
                    distance += 1.0f;
                return unit->GetExactDistSq(attacker) >= distance * distance;
            });
        case UnitConditionVariable::CreatureType:
            return unit->GetCreatureType();
        case UnitConditionVariable::IsMeleeAttacking:
            if (Unit const* target = ObjectAccessor::GetUnit(*unit, unit->GetTarget()))
            {
                float distance = std::max(unit->GetCombatReach() + target->GetCombatReach() + 1.3333334f, 5.0f);
                if (unit->HasUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED) || target->HasUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED))
                    distance += 1.0f;
                return unit->GetExactDistSq(target) < distance * distance;
            }
            return 0;
        case UnitConditionVariable::IsRangedAttacking:
            if (Unit const* target = ObjectAccessor::GetUnit(*unit, unit->GetTarget()))
            {
                float distance = std::max(unit->GetCombatReach() + target->GetCombatReach() + 1.3333334f, 5.0f);
                if (unit->HasUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED) || target->HasUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED))
                    distance += 1.0f;
                return unit->GetExactDistSq(target) >= distance * distance;
            }
            return 0;
        case UnitConditionVariable::Health:
            return unit->GetHealth();
        case UnitConditionVariable::SpellKnown:
            return unit->HasSpell(value) ? value : 0;
        case UnitConditionVariable::HasHarmfulAuraEffect:
            return value >= 0 && value < int32(TOTAL_AURAS) && std::find_if(unit->GetAuraEffectsByType(AuraType(value)).begin(), unit->GetAuraEffectsByType(AuraType(value)).end(), [unit](AuraEffect const* aurEff)
            {
                return (aurEff->GetBase()->GetApplicationOfTarget(unit->GetGUID())->GetFlags() & AFLAG_NEGATIVE) != 0;
            }) != unit->GetAuraEffectsByType(AuraType(value)).end();
        case UnitConditionVariable::IsImmuneToAreaOfEffect:
            break;
        case UnitConditionVariable::IsPlayer:
            return unit->IsPlayer();
        case UnitConditionVariable::DamageMagicPct:
            break;
        case UnitConditionVariable::DamageTotalPct:
            break;
        case UnitConditionVariable::ThreatMagicPct:
            break;
        case UnitConditionVariable::ThreatTotalPct:
            break;
        case UnitConditionVariable::HasCritter:
            return !unit->GetCritterGUID().IsEmpty();
        case UnitConditionVariable::HasTotemInSlot1:
            return !unit->m_SummonSlot[SUMMON_SLOT_TOTEM].IsEmpty();
        case UnitConditionVariable::HasTotemInSlot2:
            return !unit->m_SummonSlot[SUMMON_SLOT_TOTEM_2].IsEmpty();
        case UnitConditionVariable::HasTotemInSlot3:
            return !unit->m_SummonSlot[SUMMON_SLOT_TOTEM_3].IsEmpty();
        case UnitConditionVariable::HasTotemInSlot4:
            return !unit->m_SummonSlot[SUMMON_SLOT_TOTEM_4].IsEmpty();
        case UnitConditionVariable::HasTotemInSlot5:
            break;
        case UnitConditionVariable::Creature:
            return unit->GetEntry();
        case UnitConditionVariable::StringID:
            break;
        case UnitConditionVariable::HasAura:
            return unit->HasAura(value) ? value : 0;
        case UnitConditionVariable::IsEnemy:
            return otherUnit && unit->GetReactionTo(otherUnit) <= REP_HOSTILE;
        case UnitConditionVariable::IsSpecMelee:
            return unit->IsPlayer() && unit->ToPlayer()->GetPrimarySpecializationEntry()
                && unit->ToPlayer()->GetPrimarySpecializationEntry()->GetFlags().HasFlag(ChrSpecializationFlag::Melee);
        case UnitConditionVariable::IsSpecTank:
            return unit->IsPlayer() && unit->ToPlayer()->GetPrimarySpecializationEntry()
                && unit->ToPlayer()->GetPrimarySpecializationEntry()->GetRole() == ChrSpecializationRole::Tank;
        case UnitConditionVariable::IsSpecRanged:
            return unit->IsPlayer() && unit->ToPlayer()->GetPrimarySpecializationEntry()
                && unit->ToPlayer()->GetPrimarySpecializationEntry()->GetFlags().HasFlag(ChrSpecializationFlag::Ranged);
        case UnitConditionVariable::IsSpecHealer:
            return unit->IsPlayer() && unit->ToPlayer()->GetPrimarySpecializationEntry()
                && unit->ToPlayer()->GetPrimarySpecializationEntry()->GetRole() == ChrSpecializationRole::Healer;
        case UnitConditionVariable::IsPlayerControlledNPC:
            return unit->IsCreature() && unit->HasUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED);
        case UnitConditionVariable::IsDying:
            return unit->GetHealth() == 0;
        case UnitConditionVariable::PathFailCount:
            break;
        case UnitConditionVariable::IsMounted:
            return unit->GetMountDisplayId() != 0;
        case UnitConditionVariable::Label:
            break;
        case UnitConditionVariable::IsMySummon:
            return otherUnit && (otherUnit->GetCharmerGUID() == unit->GetGUID() || otherUnit->GetCreatorGUID() == unit->GetGUID());
        case UnitConditionVariable::IsSummoner:
            return otherUnit && (unit->GetCharmerGUID() == otherUnit->GetGUID() || unit->GetCreatorGUID() == otherUnit->GetGUID());
        case UnitConditionVariable::IsMyTarget:
            return otherUnit && unit->GetTarget() == otherUnit->GetGUID();
        case UnitConditionVariable::Sex:
            return unit->GetGender();
        case UnitConditionVariable::LevelWithinContentTuning:
            if (Optional<ContentTuningLevels> levelRange = sDB2Manager.GetContentTuningData(value, 0))
                return unit->GetLevel() >= levelRange->MinLevel && unit->GetLevel() <= levelRange->MaxLevel ? value : 0;
            return 0;
        case UnitConditionVariable::IsFlying:
            return unit->IsFlying();
        case UnitConditionVariable::IsHovering:
            return unit->IsHovering();
        case UnitConditionVariable::HasHelpfulAuraEffect:
            return value >= 0 && value < int32(TOTAL_AURAS) && std::find_if(unit->GetAuraEffectsByType(AuraType(value)).begin(), unit->GetAuraEffectsByType(AuraType(value)).end(), [unit](AuraEffect const* aurEff)
            {
                return (aurEff->GetBase()->GetApplicationOfTarget(unit->GetGUID())->GetFlags() & AFLAG_NEGATIVE) == 0;
            }) != unit->GetAuraEffectsByType(AuraType(value)).end();
        case UnitConditionVariable::HasHelpfulAuraSchool:
            return unit->GetAuraApplication([value](AuraApplication const* aurApp)
            {
                return (aurApp->GetFlags() & AFLAG_NEGATIVE) == 0 && (aurApp->GetBase()->GetSpellInfo()->GetSchoolMask() & (1 << value)) != 0;
            }) != nullptr ? value : 0;
        default:
            break;
    }

    return 0;
}

bool ConditionMgr::IsUnitMeetingCondition(Unit const* unit, Unit const* otherUnit, UnitConditionEntry const* condition)
{
    for (size_t i = 0; i < MAX_UNIT_CONDITION_VALUES; ++i)
    {
        if (!condition->Variable[i])
            break;

        int32 unitValue = GetUnitConditionVariable(unit, otherUnit, UnitConditionVariable(condition->Variable[i]), condition->Value[i]);
        bool meets = false;
        switch (UnitConditionOp(condition->Op[i]))
        {
            case UnitConditionOp::EqualTo:
                meets = unitValue == condition->Value[i];
                break;
            case UnitConditionOp::NotEqualTo:
                meets = unitValue != condition->Value[i];
                break;
            case UnitConditionOp::LessThan:
                meets = unitValue < condition->Value[i];
                break;
            case UnitConditionOp::LessThanOrEqualTo:
                meets = unitValue <= condition->Value[i];
                break;
            case UnitConditionOp::GreaterThan:
                meets = unitValue > condition->Value[i];
                break;
            case UnitConditionOp::GreaterThanOrEqualTo:
                meets = unitValue >= condition->Value[i];
                break;
            default:
                break;
        }

        if (condition->GetFlags().HasFlag(UnitConditionFlags::LogicOr))
        {
            if (meets)
                return true;
        }
        else if (!meets)
            return false;
    }

    return !condition->GetFlags().HasFlag(UnitConditionFlags::LogicOr);
}
