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
#include "Containers.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "GameEventMgr.h"
#include "GameObject.h"
#include "GameTime.h"
#include "Group.h"
#include "InstanceScript.h"
#include "Item.h"
#include "LFGMgr.h"
#include "Log.h"
#include "LootMgr.h"
#include "Map.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "Pet.h"
#include "RaceMask.h"
#include "Realm.h"
#include "ReputationMgr.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "World.h"
#include "WorldSession.h"
#include <random>
#include <sstream>

char const* const ConditionMgr::StaticSourceTypeData[CONDITION_SOURCE_TYPE_MAX] =
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
    "Phase"
};

ConditionMgr::ConditionTypeInfo const ConditionMgr::StaticConditionTypeData[CONDITION_MAX] =
{
    { "None",                false, false, false },
    { "Aura",                 true, true,  true  },
    { "Item Stored",          true, true,  true  },
    { "Item Equipped",        true, false, false },
    { "Zone",                 true, false, false },
    { "Reputation",           true, true,  false },
    { "Team",                 true, false, false },
    { "Skill",                true, true,  false },
    { "Quest Rewarded",       true, false, false },
    { "Quest Taken",          true, false, false },
    { "Drunken",              true, false, false },
    { "WorldState",           true, true,  false },
    { "Active Event",         true, false, false },
    { "Instance Info",        true, true,  true  },
    { "Quest None",           true, false, false },
    { "Class",                true, false, false },
    { "Race",                 true, false, false },
    { "Achievement",          true, false, false },
    { "Title",                true, false, false },
    { "SpawnMask",            true, false, false },
    { "Gender",               true, false, false },
    { "Unit State",           true, false, false },
    { "Map",                  true, false, false },
    { "Area",                 true, false, false },
    { "CreatureType",         true, false, false },
    { "Spell Known",          true, false, false },
    { "Phase",                true, false, false },
    { "Level",                true, true,  false },
    { "Quest Completed",      true, false, false },
    { "Near Creature",        true, true,  true  },
    { "Near GameObject",      true, true,  false },
    { "Object Entry or Guid", true, true,  true  },
    { "Object TypeMask",      true, false, false },
    { "Relation",             true, true,  false },
    { "Reaction",             true, true,  false },
    { "Distance",             true, true,  true  },
    { "Alive",               false, false, false },
    { "Health Value",         true, true,  false },
    { "Health Pct",           true, true,  false },
    { "Realm Achievement",    true, false, false },
    { "In Water",            false, false, false },
    { "Terrain Swap",         true, false, false },
    { "Sit/stand state",      true,  true, false },
    { "Daily Quest Completed",true, false, false },
    { "Charmed",             false, false, false },
    { "Pet type",             true, false, false },
    { "On Taxi",             false, false, false },
    { "Quest state mask",     true,  true, false },
    { "Objective Complete",   true, false, false },
    { "Map Difficulty",       true, false, false },
    { nullptr,               false, false, false },
    { "Object Entry or Guid", true, true,  true  },
    { "Object TypeMask",      true, false, false },
};

// Checks if object meets the condition
// Can have CONDITION_SOURCE_TYPE_NONE && !mReferenceId if called from a special event (ie: SmartAI)
bool Condition::Meets(ConditionSourceInfo& sourceInfo) const
{
    ASSERT(ConditionTarget < MAX_CONDITION_TARGETS);
    WorldObject* object = sourceInfo.mConditionTargets[ConditionTarget];
    // object not present, return false
    if (!object)
    {
        TC_LOG_DEBUG("condition", "Condition object not found for %s", ToString().c_str());
        return false;
    }
    bool condMeets = false;
    switch (ConditionType)
    {
        case CONDITION_NONE:
            condMeets = true;                                    // empty condition, always met
            break;
        case CONDITION_AURA:
        {
            if (Unit* unit = object->ToUnit())
                condMeets = unit->HasAuraEffect(ConditionValue1, ConditionValue2);
            break;
        }
        case CONDITION_ITEM:
        {
            if (Player* player = object->ToPlayer())
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
            if (Player* player = object->ToPlayer())
                condMeets = player->HasItemOrGemWithIdEquipped(ConditionValue1, 1);
            break;
        }
        case CONDITION_ZONEID:
            condMeets = object->GetZoneId() == ConditionValue1;
            break;
        case CONDITION_REPUTATION_RANK:
        {
            if (Player* player = object->ToPlayer())
            {
                if (FactionEntry const* faction = sFactionStore.LookupEntry(ConditionValue1))
                    condMeets = (ConditionValue2 & (1 << player->GetReputationMgr().GetRank(faction))) != 0;
            }
            break;
        }
        case CONDITION_ACHIEVEMENT:
        {
            if (Player* player = object->ToPlayer())
                condMeets = player->HasAchieved(ConditionValue1);
            break;
        }
        case CONDITION_TEAM:
        {
            if (Player* player = object->ToPlayer())
                condMeets = player->GetTeam() == ConditionValue1;
            break;
        }
        case CONDITION_CLASS:
        {
            if (Unit* unit = object->ToUnit())
                condMeets = (unit->getClassMask() & ConditionValue1) != 0;
            break;
        }
        case CONDITION_RACE:
        {
            if (Unit* unit = object->ToUnit())
                condMeets = Trinity::RaceMask<uint32>{ ConditionValue1 }.HasRace(unit->getRace());
            break;
        }
        case CONDITION_GENDER:
        {
            if (Player* player = object->ToPlayer())
                condMeets = player->getGender() == ConditionValue1;
            break;
        }
        case CONDITION_SKILL:
        {
            if (Player* player = object->ToPlayer())
                condMeets = player->HasSkill(ConditionValue1) && player->GetBaseSkillValue(ConditionValue1) >= ConditionValue2;
            break;
        }
        case CONDITION_QUESTREWARDED:
        {
            if (Player* player = object->ToPlayer())
                condMeets = player->GetQuestRewardStatus(ConditionValue1);
            break;
        }
        case CONDITION_QUESTTAKEN:
        {
            if (Player* player = object->ToPlayer())
            {
                QuestStatus status = player->GetQuestStatus(ConditionValue1);
                condMeets = (status == QUEST_STATUS_INCOMPLETE);
            }
            break;
        }
        case CONDITION_QUEST_COMPLETE:
        {
            if (Player* player = object->ToPlayer())
            {
                QuestStatus status = player->GetQuestStatus(ConditionValue1);
                condMeets = (status == QUEST_STATUS_COMPLETE && !player->GetQuestRewardStatus(ConditionValue1));
            }
            break;
        }
        case CONDITION_QUEST_NONE:
        {
            if (Player* player = object->ToPlayer())
            {
                QuestStatus status = player->GetQuestStatus(ConditionValue1);
                condMeets = (status == QUEST_STATUS_NONE);
            }
            break;
        }
        case CONDITION_ACTIVE_EVENT:
            condMeets = sGameEventMgr->IsActiveEvent(ConditionValue1);
            break;
        case CONDITION_INSTANCE_INFO:
        {
            Map* map = object->GetMap();
            if (map->IsDungeon())
            {
                if (InstanceScript const* instance = ((InstanceMap*)map)->GetInstanceScript())
                {
                    switch (ConditionValue3)
                    {
                        case INSTANCE_INFO_DATA:
                            condMeets = instance->GetData(ConditionValue1) == ConditionValue2;
                            break;
                        //case INSTANCE_INFO_GUID_DATA:
                        //    condMeets = instance->GetGuidData(ConditionValue1) == ObjectGuid(uint64(ConditionValue2));
                        //    break;
                        case INSTANCE_INFO_BOSS_STATE:
                            condMeets = instance->GetBossState(ConditionValue1) == EncounterState(ConditionValue2);
                            break;
                        case INSTANCE_INFO_DATA64:
                            condMeets = instance->GetData64(ConditionValue1) == ConditionValue2;
                            break;
                    }
                }
            }
            break;
        }
        case CONDITION_MAPID:
            condMeets = object->GetMapId() == ConditionValue1;
            break;
        case CONDITION_AREAID:
            condMeets = object->GetAreaId() == ConditionValue1;
            break;
        case CONDITION_SPELL:
        {
            if (Player* player = object->ToPlayer())
                condMeets = player->HasSpell(ConditionValue1);
            break;
        }
        case CONDITION_LEVEL:
        {
            if (Unit* unit = object->ToUnit())
                condMeets = CompareValues(static_cast<ComparisionType>(ConditionValue2), static_cast<uint32>(unit->getLevel()), ConditionValue1);
            break;
        }
        case CONDITION_DRUNKENSTATE:
        {
            if (Player* player = object->ToPlayer())
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
            if (WorldObject* toObject = sourceInfo.mConditionTargets[ConditionValue1])
            {
                Unit* toUnit = toObject->ToUnit();
                Unit* unit = object->ToUnit();
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
            if (WorldObject* toObject = sourceInfo.mConditionTargets[ConditionValue1])
            {
                Unit* toUnit = toObject->ToUnit();
                Unit* unit = object->ToUnit();
                if (toUnit && unit)
                    condMeets = ((1 << unit->GetReactionTo(toUnit)) & ConditionValue2) != 0;
            }
            break;
        }
        case CONDITION_DISTANCE_TO:
        {
            if (WorldObject* toObject = sourceInfo.mConditionTargets[ConditionValue1])
                condMeets = CompareValues(static_cast<ComparisionType>(ConditionValue3), object->GetDistance(toObject), static_cast<float>(ConditionValue2));
            break;
        }
        case CONDITION_ALIVE:
        {
            if (Unit* unit = object->ToUnit())
                condMeets = unit->IsAlive();
            break;
        }
        case CONDITION_HP_VAL:
        {
            if (Unit* unit = object->ToUnit())
                condMeets = CompareValues(static_cast<ComparisionType>(ConditionValue2), unit->GetHealth(), static_cast<uint64>(ConditionValue1));
            break;
        }
        case CONDITION_HP_PCT:
        {
            if (Unit* unit = object->ToUnit())
                condMeets = CompareValues(static_cast<ComparisionType>(ConditionValue2), unit->GetHealthPct(), static_cast<float>(ConditionValue1));
            break;
        }
        case CONDITION_WORLD_STATE:
        {
            condMeets = ConditionValue2 == sWorld->getWorldState(ConditionValue1);
            break;
        }
        case CONDITION_PHASEID:
        {
            condMeets = object->GetPhaseShift().HasPhase(ConditionValue1);
            break;
        }
        case CONDITION_TITLE:
        {
            if (Player* player = object->ToPlayer())
                condMeets = player->HasTitle(ConditionValue1);
            break;
        }
        case CONDITION_UNIT_STATE:
        {
            if (Unit* unit = object->ToUnit())
                condMeets = unit->HasUnitState(ConditionValue1);
            break;
        }
        case CONDITION_CREATURE_TYPE:
        {
            if (Creature* creature = object->ToCreature())
                condMeets = creature->GetCreatureTemplate()->type == ConditionValue1;
            break;
        }
        case CONDITION_REALM_ACHIEVEMENT:
        {
            AchievementEntry const* achievement = sAchievementStore.LookupEntry(ConditionValue1);
            if (achievement && sAchievementMgr->IsRealmCompleted(achievement))
                condMeets = true;
            break;
        }
        case CONDITION_IN_WATER:
        {
            if (Unit* unit = object->ToUnit())
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
            if (Unit* unit = object->ToUnit())
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
            if (Player* player = object->ToPlayer())
                condMeets = player->IsDailyQuestDone(ConditionValue1);
            break;
        }
        case CONDITION_CHARMED:
        {
            if (Unit* unit = object->ToUnit())
                condMeets = unit->IsCharmed();
            break;
        }
        case CONDITION_PET_TYPE:
        {
            if (Player* player = object->ToPlayer())
                if (Pet* pet = player->GetPet())
                    condMeets = (((1 << pet->getPetType()) & ConditionValue1) != 0);
            break;
        }
        case CONDITION_TAXI:
        {
            if (Player* player = object->ToPlayer())
                condMeets = player->IsInFlight();
            break;
        }
        case CONDITION_QUESTSTATE:
        {
            if (Player* player = object->ToPlayer())
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
        case CONDITION_QUEST_OBJECTIVE_COMPLETE:
        {
            if (Player* player = object->ToPlayer())
            {
                QuestObjective const* obj = sObjectMgr->GetQuestObjective(ConditionValue1);
                if (!obj)
                    break;

                condMeets = (!player->GetQuestRewardStatus(obj->QuestID) && player->IsQuestObjectiveComplete(*obj));
            }
            break;
        }
        case CONDITION_DIFFICULTY_ID:
        {
            condMeets = object->GetMap()->GetDifficultyID() == ConditionValue1;
            break;
        }
        default:
            condMeets = false;
            break;
    }

    if (NegativeCondition)
        condMeets = !condMeets;

    if (!condMeets)
        sourceInfo.mLastFailedCondition = this;

    bool script = sScriptMgr->OnConditionCheck(this, sourceInfo); // Returns true by default.
    return condMeets && script;
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
        case CONDITION_QUEST_OBJECTIVE_COMPLETE:
            mask |= GRID_MAP_TYPE_MASK_PLAYER;
            break;
        case CONDITION_DIFFICULTY_ID:
            mask |= GRID_MAP_TYPE_MASK_ALL;
            break;
        default:
            ASSERT(false && "Condition::GetSearcherTypeMaskForCondition - missing condition handling!");
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
    if (SourceType < CONDITION_SOURCE_TYPE_MAX)
        ss << " (" << ConditionMgr::StaticSourceTypeData[SourceType] << ")";
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
        ASSERT((*i)->isLoaded() && "ConditionMgr::GetSearcherTypeMaskForConditionList - not yet loaded condition found in list");
        std::map<uint32, uint32>::const_iterator itr = elseGroupSearcherTypeMasks.find((*i)->ElseGroup);
        // group not filled yet, fill with widest mask possible
        if (itr == elseGroupSearcherTypeMasks.end())
            elseGroupSearcherTypeMasks[(*i)->ElseGroup] = GRID_MAP_TYPE_MASK_ALL;
        // no point of checking anymore, empty mask
        else if (!itr->second)
            continue;

        if ((*i)->ReferenceId) // handle reference
        {
            ConditionReferenceContainer::const_iterator ref = ConditionReferenceStore.find((*i)->ReferenceId);
            ASSERT(ref != ConditionReferenceStore.end() && "ConditionMgr::GetSearcherTypeMaskForConditionList - incorrect reference");
            elseGroupSearcherTypeMasks[(*i)->ElseGroup] &= GetSearcherTypeMaskForConditionList((*ref).second);
        }
        else // handle normal condition
        {
            // object will match conditions in one ElseGroupStore only when it matches all of them
            // so, let's find a smallest possible mask which satisfies all conditions
            elseGroupSearcherTypeMasks[(*i)->ElseGroup] &= (*i)->GetSearcherTypeMaskForCondition();
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
    for (Condition const* condition : conditions)
    {
        TC_LOG_DEBUG("condition", "ConditionMgr::IsPlayerMeetToConditionList %s val1: %u", condition->ToString().c_str(), condition->ConditionValue1);
        if (condition->isLoaded())
        {
            //! Find ElseGroup in ElseGroupStore
            std::map<uint32, bool>::const_iterator itr = elseGroupStore.find(condition->ElseGroup);
            //! If not found, add an entry in the store and set to true (placeholder)
            if (itr == elseGroupStore.end())
                elseGroupStore[condition->ElseGroup] = true;
            else if (!(*itr).second) //! If another condition in this group was unmatched before this, don't bother checking (the group is false anyway)
                continue;

            if (condition->ReferenceId)//handle reference
            {
                ConditionReferenceContainer::const_iterator ref = ConditionReferenceStore.find(condition->ReferenceId);
                if (ref != ConditionReferenceStore.end())
                {
                    if (!IsObjectMeetToConditionList(sourceInfo, ref->second))
                        elseGroupStore[condition->ElseGroup] = false;
                }
                else
                {
                    TC_LOG_DEBUG("condition", "ConditionMgr::IsPlayerMeetToConditionList %s Reference template -%u not found",
                        condition->ToString().c_str(), condition->ReferenceId); // checked at loading, should never happen
                }

            }
            else //handle normal condition
            {
                if (!condition->Meets(sourceInfo))
                    elseGroupStore[condition->ElseGroup] = false;
            }
        }
    }
    for (std::map<uint32, bool>::const_iterator i = elseGroupStore.begin(); i != elseGroupStore.end(); ++i)
        if (i->second)
            return true;

    return false;
}

bool ConditionMgr::IsObjectMeetToConditions(WorldObject* object, ConditionContainer const& conditions) const
{
    ConditionSourceInfo srcInfo = ConditionSourceInfo(object);
    return IsObjectMeetToConditions(srcInfo, conditions);
}

bool ConditionMgr::IsObjectMeetToConditions(WorldObject* object1, WorldObject* object2, ConditionContainer const& conditions) const
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
            sourceType == CONDITION_SOURCE_TYPE_PHASE);
}

bool ConditionMgr::CanHaveSourceIdSet(ConditionSourceType sourceType)
{
    return (sourceType == CONDITION_SOURCE_TYPE_SMART_EVENT);
}

bool ConditionMgr::IsObjectMeetingNotGroupedConditions(ConditionSourceType sourceType, uint32 entry, ConditionSourceInfo& sourceInfo) const
{
    if (sourceType > CONDITION_SOURCE_TYPE_NONE && sourceType < CONDITION_SOURCE_TYPE_MAX)
    {
        ConditionsByEntryMap::const_iterator i = ConditionStore[sourceType].find(entry);
        if (i != ConditionStore[sourceType].end())
        {
            TC_LOG_DEBUG("condition", "GetConditionsForNotGroupedEntry: found conditions for type %u and entry %u", uint32(sourceType), entry);
            return IsObjectMeetToConditions(sourceInfo, i->second);
        }
    }

    return true;
}

bool ConditionMgr::IsObjectMeetingNotGroupedConditions(ConditionSourceType sourceType, uint32 entry, WorldObject* target0, WorldObject* target1 /*= nullptr*/, WorldObject* target2 /*= nullptr*/) const
{
    ConditionSourceInfo conditionSource(target0, target1, target2);
    return IsObjectMeetingNotGroupedConditions(sourceType, entry, conditionSource);
}

bool ConditionMgr::HasConditionsForNotGroupedEntry(ConditionSourceType sourceType, uint32 entry) const
{
    if (sourceType > CONDITION_SOURCE_TYPE_NONE && sourceType < CONDITION_SOURCE_TYPE_MAX)
        if (ConditionStore[sourceType].find(entry) != ConditionStore[sourceType].end())
            return true;

    return false;
}

bool ConditionMgr::IsObjectMeetingSpellClickConditions(uint32 creatureId, uint32 spellId, WorldObject* clicker, WorldObject* target) const
{
    ConditionEntriesByCreatureIdMap::const_iterator itr = SpellClickEventConditionStore.find(creatureId);
    if (itr != SpellClickEventConditionStore.end())
    {
        ConditionsByEntryMap::const_iterator i = itr->second.find(spellId);
        if (i != itr->second.end())
        {
            TC_LOG_DEBUG("condition", "GetConditionsForSpellClickEvent: found conditions for SpellClickEvent entry %u spell %u", creatureId, spellId);
            ConditionSourceInfo sourceInfo(clicker, target);
            return IsObjectMeetToConditions(sourceInfo, i->second);
        }
    }
    return true;
}

ConditionContainer const* ConditionMgr::GetConditionsForSpellClickEvent(uint32 creatureId, uint32 spellId) const
{
    ConditionEntriesByCreatureIdMap::const_iterator itr = SpellClickEventConditionStore.find(creatureId);
    if (itr != SpellClickEventConditionStore.end())
    {
        ConditionsByEntryMap::const_iterator i = itr->second.find(spellId);
        if (i != itr->second.end())
        {
            TC_LOG_DEBUG("condition", "GetConditionsForSpellClickEvent: found conditions for SpellClickEvent entry %u spell %u", creatureId, spellId);
            return &i->second;
        }
    }
    return nullptr;
}

bool ConditionMgr::IsObjectMeetingVehicleSpellConditions(uint32 creatureId, uint32 spellId, Player* player, Unit* vehicle) const
{
    ConditionEntriesByCreatureIdMap::const_iterator itr = VehicleSpellConditionStore.find(creatureId);
    if (itr != VehicleSpellConditionStore.end())
    {
        ConditionsByEntryMap::const_iterator i = itr->second.find(spellId);
        if (i != itr->second.end())
        {
            TC_LOG_DEBUG("condition", "GetConditionsForVehicleSpell: found conditions for Vehicle entry %u spell %u", creatureId, spellId);
            ConditionSourceInfo sourceInfo(player, vehicle);
            return IsObjectMeetToConditions(sourceInfo, i->second);
        }
    }
    return true;
}

bool ConditionMgr::IsObjectMeetingSmartEventConditions(int64 entryOrGuid, uint32 eventId, uint32 sourceType, Unit* unit, WorldObject* baseObject) const
{
    SmartEventConditionContainer::const_iterator itr = SmartEventConditionStore.find(std::make_pair(entryOrGuid, sourceType));
    if (itr != SmartEventConditionStore.end())
    {
        ConditionsByEntryMap::const_iterator i = itr->second.find(eventId + 1);
        if (i != itr->second.end())
        {
            TC_LOG_DEBUG("condition", "GetConditionsForSmartEvent: found conditions for Smart Event entry or guid " SI64FMTD " eventId %u", entryOrGuid, eventId);
            ConditionSourceInfo sourceInfo(unit, baseObject);
            return IsObjectMeetToConditions(sourceInfo, i->second);
        }
    }
    return true;
}

bool ConditionMgr::IsObjectMeetingVendorItemConditions(uint32 creatureId, uint32 itemId, Player* player, Creature* vendor) const
{
    ConditionEntriesByCreatureIdMap::const_iterator itr = NpcVendorConditionContainerStore.find(creatureId);
    if (itr != NpcVendorConditionContainerStore.end())
    {
        ConditionsByEntryMap::const_iterator i = (*itr).second.find(itemId);
        if (i != (*itr).second.end())
        {
            TC_LOG_DEBUG("condition", "GetConditionsForNpcVendorEvent: found conditions for creature entry %u item %u", creatureId, itemId);
            ConditionSourceInfo sourceInfo(player, vendor);
            return IsObjectMeetToConditions(sourceInfo, i->second);
        }
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
        TC_LOG_INFO("misc", "Reseting Loot Conditions...");
        LootTemplates_Creature.ResetConditions();
        LootTemplates_Fishing.ResetConditions();
        LootTemplates_Gameobject.ResetConditions();
        LootTemplates_Item.ResetConditions();
        LootTemplates_Mail.ResetConditions();
        LootTemplates_Milling.ResetConditions();
        LootTemplates_Pickpocketing.ResetConditions();
        LootTemplates_Reference.ResetConditions();
        LootTemplates_Skinning.ResetConditions();
        LootTemplates_Disenchant.ResetConditions();
        LootTemplates_Prospecting.ResetConditions();
        LootTemplates_Spell.ResetConditions();

        TC_LOG_INFO("misc", "Re-Loading `gossip_menu` Table for Conditions!");
        sObjectMgr->LoadGossipMenu();

        TC_LOG_INFO("misc", "Re-Loading `gossip_menu_option` Table for Conditions!");
        sObjectMgr->LoadGossipMenuItems();

        sSpellMgr->UnloadSpellInfoImplicitTargetConditionLists();

        sObjectMgr->UnloadPhaseConditions();
    }

    QueryResult result = WorldDatabase.Query("SELECT SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, "
                                             " ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ErrorTextId, ScriptName FROM conditions");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 conditions. DB table `conditions` is empty!");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        Condition* cond = new Condition();
        int32 iSourceTypeOrReferenceId  = fields[0].GetInt32();
        cond->SourceGroup               = fields[1].GetUInt32();
        cond->SourceEntry               = fields[2].GetInt32();
        cond->SourceId                  = fields[3].GetInt32();
        cond->ElseGroup                 = fields[4].GetUInt32();
        int32 iConditionTypeOrReference = fields[5].GetInt32();
        cond->ConditionTarget           = fields[6].GetUInt8();
        cond->ConditionValue1           = fields[7].GetUInt32();
        cond->ConditionValue2           = fields[8].GetUInt32();
        cond->ConditionValue3           = fields[9].GetUInt32();
        cond->NegativeCondition         = fields[10].GetBool();
        cond->ErrorType                 = fields[11].GetUInt32();
        cond->ErrorTextId               = fields[12].GetUInt32();
        cond->ScriptId                  = sObjectMgr->GetScriptId(fields[13].GetString());

        if (iConditionTypeOrReference >= 0)
            cond->ConditionType = ConditionTypes(iConditionTypeOrReference);

        if (iSourceTypeOrReferenceId >= 0)
            cond->SourceType = ConditionSourceType(iSourceTypeOrReferenceId);

        if (iConditionTypeOrReference < 0)//it has a reference
        {
            if (iConditionTypeOrReference == iSourceTypeOrReferenceId)//self referencing, skip
            {
                TC_LOG_ERROR("sql.sql", "Condition reference %i is referencing self, skipped", iSourceTypeOrReferenceId);
                delete cond;
                continue;
            }
            cond->ReferenceId = uint32(abs(iConditionTypeOrReference));

            char const* rowType = "reference template";
            if (iSourceTypeOrReferenceId >= 0)
                rowType = "reference";
            //check for useless data
            if (cond->ConditionTarget)
                TC_LOG_ERROR("sql.sql", "Condition %s %i has useless data in ConditionTarget (%u)!", rowType, iSourceTypeOrReferenceId, cond->ConditionTarget);
            if (cond->ConditionValue1)
                TC_LOG_ERROR("sql.sql", "Condition %s %i has useless data in value1 (%u)!", rowType, iSourceTypeOrReferenceId, cond->ConditionValue1);
            if (cond->ConditionValue2)
                TC_LOG_ERROR("sql.sql", "Condition %s %i has useless data in value2 (%u)!", rowType, iSourceTypeOrReferenceId, cond->ConditionValue2);
            if (cond->ConditionValue3)
                TC_LOG_ERROR("sql.sql", "Condition %s %i has useless data in value3 (%u)!", rowType, iSourceTypeOrReferenceId, cond->ConditionValue3);
            if (cond->NegativeCondition)
                TC_LOG_ERROR("sql.sql", "Condition %s %i has useless data in NegativeCondition (%u)!", rowType, iSourceTypeOrReferenceId, cond->NegativeCondition);
            if (cond->SourceGroup && iSourceTypeOrReferenceId < 0)
                TC_LOG_ERROR("sql.sql", "Condition %s %i has useless data in SourceGroup (%u)!", rowType, iSourceTypeOrReferenceId, cond->SourceGroup);
            if (cond->SourceEntry && iSourceTypeOrReferenceId < 0)
                TC_LOG_ERROR("sql.sql", "Condition %s %i has useless data in SourceEntry (%u)!", rowType, iSourceTypeOrReferenceId, cond->SourceEntry);
        }
        else if (!isConditionTypeValid(cond))//doesn't have reference, validate ConditionType
        {
            delete cond;
            continue;
        }

        if (iSourceTypeOrReferenceId < 0)//it is a reference template
        {
            ConditionReferenceStore[std::abs(iSourceTypeOrReferenceId)].push_back(cond);//add to reference storage
            ++count;
            continue;
        }//end of reference templates

        //if not a reference and SourceType is invalid, skip
        if (iConditionTypeOrReference >= 0 && !isSourceTypeValid(cond))
        {
            delete cond;
            continue;
        }

        //Grouping is only allowed for some types (loot templates, gossip menus, gossip items)
        if (cond->SourceGroup && !CanHaveSourceGroupSet(cond->SourceType))
        {
            TC_LOG_ERROR("sql.sql", "%s has not allowed value of SourceGroup = %u!", cond->ToString().c_str(), cond->SourceGroup);
            delete cond;
            continue;
        }
        if (cond->SourceId && !CanHaveSourceIdSet(cond->SourceType))
        {
            TC_LOG_ERROR("sql.sql", "%s has not allowed value of SourceId = %u!", cond->ToString().c_str(), cond->SourceId);
            delete cond;
            continue;
        }

        if (cond->ErrorType && cond->SourceType != CONDITION_SOURCE_TYPE_SPELL)
        {
            TC_LOG_ERROR("sql.sql", "%s can't have ErrorType (%u), set to 0!", cond->ToString().c_str(), cond->ErrorType);
            cond->ErrorType = 0;
        }

        if (cond->ErrorTextId && !cond->ErrorType)
        {
            TC_LOG_ERROR("sql.sql", "%s has any ErrorType, ErrorTextId (%u) is set, set to 0!", cond->ToString().c_str(), cond->ErrorTextId);
            cond->ErrorTextId = 0;
        }

        if (cond->SourceGroup)
        {
            bool valid = false;
            // handle grouped conditions
            switch (cond->SourceType)
            {
                case CONDITION_SOURCE_TYPE_CREATURE_LOOT_TEMPLATE:
                    valid = addToLootTemplate(cond, LootTemplates_Creature.GetLootForConditionFill(cond->SourceGroup));
                    break;
                case CONDITION_SOURCE_TYPE_DISENCHANT_LOOT_TEMPLATE:
                    valid = addToLootTemplate(cond, LootTemplates_Disenchant.GetLootForConditionFill(cond->SourceGroup));
                    break;
                case CONDITION_SOURCE_TYPE_FISHING_LOOT_TEMPLATE:
                    valid = addToLootTemplate(cond, LootTemplates_Fishing.GetLootForConditionFill(cond->SourceGroup));
                    break;
                case CONDITION_SOURCE_TYPE_GAMEOBJECT_LOOT_TEMPLATE:
                    valid = addToLootTemplate(cond, LootTemplates_Gameobject.GetLootForConditionFill(cond->SourceGroup));
                    break;
                case CONDITION_SOURCE_TYPE_ITEM_LOOT_TEMPLATE:
                    valid = addToLootTemplate(cond, LootTemplates_Item.GetLootForConditionFill(cond->SourceGroup));
                    break;
                case CONDITION_SOURCE_TYPE_MAIL_LOOT_TEMPLATE:
                    valid = addToLootTemplate(cond, LootTemplates_Mail.GetLootForConditionFill(cond->SourceGroup));
                    break;
                case CONDITION_SOURCE_TYPE_MILLING_LOOT_TEMPLATE:
                    valid = addToLootTemplate(cond, LootTemplates_Milling.GetLootForConditionFill(cond->SourceGroup));
                    break;
                case CONDITION_SOURCE_TYPE_PICKPOCKETING_LOOT_TEMPLATE:
                    valid = addToLootTemplate(cond, LootTemplates_Pickpocketing.GetLootForConditionFill(cond->SourceGroup));
                    break;
                case CONDITION_SOURCE_TYPE_PROSPECTING_LOOT_TEMPLATE:
                    valid = addToLootTemplate(cond, LootTemplates_Prospecting.GetLootForConditionFill(cond->SourceGroup));
                    break;
                case CONDITION_SOURCE_TYPE_REFERENCE_LOOT_TEMPLATE:
                    valid = addToLootTemplate(cond, LootTemplates_Reference.GetLootForConditionFill(cond->SourceGroup));
                    break;
                case CONDITION_SOURCE_TYPE_SKINNING_LOOT_TEMPLATE:
                    valid = addToLootTemplate(cond, LootTemplates_Skinning.GetLootForConditionFill(cond->SourceGroup));
                    break;
                case CONDITION_SOURCE_TYPE_SPELL_LOOT_TEMPLATE:
                    valid = addToLootTemplate(cond, LootTemplates_Spell.GetLootForConditionFill(cond->SourceGroup));
                    break;
                case CONDITION_SOURCE_TYPE_GOSSIP_MENU:
                    valid = addToGossipMenus(cond);
                    break;
                case CONDITION_SOURCE_TYPE_GOSSIP_MENU_OPTION:
                    valid = addToGossipMenuItems(cond);
                    break;
                case CONDITION_SOURCE_TYPE_SPELL_CLICK_EVENT:
                {
                    SpellClickEventConditionStore[cond->SourceGroup][cond->SourceEntry].push_back(cond);
                    valid = true;
                    ++count;
                    continue;   // do not add to m_AllocatedMemory to avoid double deleting
                }
                case CONDITION_SOURCE_TYPE_SPELL_IMPLICIT_TARGET:
                    valid = addToSpellImplicitTargetConditions(cond);
                    break;
                case CONDITION_SOURCE_TYPE_VEHICLE_SPELL:
                {
                    VehicleSpellConditionStore[cond->SourceGroup][cond->SourceEntry].push_back(cond);
                    valid = true;
                    ++count;
                    continue;   // do not add to m_AllocatedMemory to avoid double deleting
                }
                case CONDITION_SOURCE_TYPE_SMART_EVENT:
                {
                    //! TODO: PAIR_32 ?
                    std::pair<int32, uint32> key = std::make_pair(cond->SourceEntry, cond->SourceId);
                    SmartEventConditionStore[key][cond->SourceGroup].push_back(cond);
                    valid = true;
                    ++count;
                    continue;
                }
                case CONDITION_SOURCE_TYPE_NPC_VENDOR:
                {
                    NpcVendorConditionContainerStore[cond->SourceGroup][cond->SourceEntry].push_back(cond);
                    valid = true;
                    ++count;
                    continue;
                }
                case CONDITION_SOURCE_TYPE_PHASE:
                    valid = addToPhases(cond);
                    break;
                default:
                    break;
            }

            if (!valid)
            {
                TC_LOG_ERROR("sql.sql", "%s Not handled grouped condition.", cond->ToString().c_str());
                delete cond;
            }
            else
            {
                AllocatedMemoryStore.push_back(cond);
                ++count;
            }
            continue;
        }

        //handle not grouped conditions
        //add new Condition to storage based on Type/Entry
        ConditionStore[cond->SourceType][cond->SourceEntry].push_back(cond);
        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u conditions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

bool ConditionMgr::addToLootTemplate(Condition* cond, LootTemplate* loot) const
{
    if (!loot)
    {
        TC_LOG_ERROR("sql.sql", "%s LootTemplate %u not found.", cond->ToString().c_str(), cond->SourceGroup);
        return false;
    }

    if (loot->addConditionItem(cond))
        return true;

    TC_LOG_ERROR("sql.sql", "%s Item %u not found in LootTemplate %u.", cond->ToString().c_str(), cond->SourceEntry, cond->SourceGroup);
    return false;
}

bool ConditionMgr::addToGossipMenus(Condition* cond) const
{
    GossipMenusMapBoundsNonConst pMenuBounds = sObjectMgr->GetGossipMenusMapBoundsNonConst(cond->SourceGroup);

    if (pMenuBounds.first != pMenuBounds.second)
    {
        for (GossipMenusContainer::iterator itr = pMenuBounds.first; itr != pMenuBounds.second; ++itr)
        {
            if ((*itr).second.MenuId == cond->SourceGroup && (*itr).second.TextId == uint32(cond->SourceEntry))
            {
                (*itr).second.Conditions.push_back(cond);
                return true;
            }
        }
    }

    TC_LOG_ERROR("sql.sql", "%s GossipMenu %u not found.", cond->ToString().c_str(), cond->SourceGroup);
    return false;
}

bool ConditionMgr::addToGossipMenuItems(Condition* cond) const
{
    GossipMenuItemsMapBoundsNonConst pMenuItemBounds = sObjectMgr->GetGossipMenuItemsMapBoundsNonConst(cond->SourceGroup);
    if (pMenuItemBounds.first != pMenuItemBounds.second)
    {
        for (GossipMenuItemsContainer::iterator itr = pMenuItemBounds.first; itr != pMenuItemBounds.second; ++itr)
        {
            if ((*itr).second.MenuId == cond->SourceGroup && (*itr).second.OptionIndex == uint32(cond->SourceEntry))
            {
                (*itr).second.Conditions.push_back(cond);
                return true;
            }
        }
    }

    TC_LOG_ERROR("sql.sql", "%s GossipMenuId %u Item %u not found.", cond->ToString().c_str(), cond->SourceGroup, cond->SourceEntry);
    return false;
}

bool ConditionMgr::addToSpellImplicitTargetConditions(Condition* cond) const
{
    bool valid = false;
    sSpellMgr->ForEachSpellInfoDifficulty(cond->SourceEntry, [&](SpellInfo const* spellInfo)
    {
        uint32 conditionEffMask = cond->SourceGroup;
        std::list<uint32> sharedMasks;
        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        {
            SpellEffectInfo const* effect = spellInfo->GetEffect(i);
            if (!effect)
                continue;

            // check if effect is already a part of some shared mask
            bool found = false;
            for (std::list<uint32>::iterator itr = sharedMasks.begin(); itr != sharedMasks.end(); ++itr)
            {
                if ((1 << i) & *itr)
                {
                    found = true;
                    break;
                }
            }

            if (found)
                continue;

            // build new shared mask with found effect
            uint32 sharedMask = 1 << i;
            ConditionContainer* cmp = effect->ImplicitTargetConditions;
            for (uint8 effIndex = i + 1; effIndex < MAX_SPELL_EFFECTS; ++effIndex)
            {
                SpellEffectInfo const* inner = spellInfo->GetEffect(effIndex);
                if (!inner)
                    continue;

                if (inner->ImplicitTargetConditions == cmp)
                    sharedMask |= 1 << effIndex;
            }

            sharedMasks.push_back(sharedMask);
        }

        for (std::list<uint32>::iterator itr = sharedMasks.begin(); itr != sharedMasks.end(); ++itr)
        {
            // some effect indexes should have same data
            if (uint32 commonMask = *itr & conditionEffMask)
            {
                uint8 firstEffIndex = 0;
                for (; firstEffIndex < MAX_SPELL_EFFECTS; ++firstEffIndex)
                    if ((1 << firstEffIndex) & *itr)
                        break;

                if (firstEffIndex >= MAX_SPELL_EFFECTS)
                    return;

                SpellEffectInfo const* effect = spellInfo->GetEffect(firstEffIndex);
                if (!effect)
                    continue;

                // get shared data
                ConditionContainer* sharedList = effect->ImplicitTargetConditions;

                // there's already data entry for that sharedMask
                if (sharedList)
                {
                    // we have overlapping masks in db
                    if (conditionEffMask != *itr)
                    {
                        TC_LOG_ERROR("sql.sql", "%s in `condition` table, has incorrect SourceGroup %u (spell effectMask) set - "
                            "effect masks are overlapping (all SourceGroup values having given bit set must be equal) - ignoring (Difficulty %u).",
                            cond->ToString().c_str(), cond->SourceGroup, uint32(spellInfo->Difficulty));
                        return;
                    }
                }
                // no data for shared mask, we can create new submask
                else
                {
                    // add new list, create new shared mask
                    sharedList = new ConditionContainer();
                    bool assigned = false;
                    for (uint8 i = firstEffIndex; i < MAX_SPELL_EFFECTS; ++i)
                    {
                        SpellEffectInfo const* eff = spellInfo->GetEffect(i);
                        if (!eff)
                            continue;

                        if ((1 << i) & commonMask)
                        {
                            const_cast<SpellEffectInfo*>(eff)->ImplicitTargetConditions = sharedList;
                            assigned = true;
                        }
                    }

                    if (!assigned)
                    {
                        delete sharedList;
                        break;
                    }
                }
                sharedList->push_back(cond);
                break;
            }
        }
        valid = true;
    });
    return true;
}

bool ConditionMgr::addToPhases(Condition* cond) const
{
    if (!cond->SourceEntry)
    {
        if (PhaseInfoStruct const* phaseInfo = sObjectMgr->GetPhaseInfo(cond->SourceGroup))
        {
            bool found = false;
            for (uint32 areaId : phaseInfo->Areas)
            {
                if (std::vector<PhaseAreaInfo>* phases = const_cast<std::vector<PhaseAreaInfo>*>(sObjectMgr->GetPhasesForArea(areaId)))
                {
                    for (PhaseAreaInfo& phase : *phases)
                    {
                        if (phase.PhaseInfo->Id == cond->SourceGroup)
                        {
                            phase.Conditions.push_back(cond);
                            found = true;
                        }
                    }
                }
            }

            if (found)
                return true;
        }
    }
    else if (std::vector<PhaseAreaInfo>* phases = const_cast<std::vector<PhaseAreaInfo>*>(sObjectMgr->GetPhasesForArea(cond->SourceEntry)))
    {
        for (PhaseAreaInfo& phase : *phases)
        {
            if (phase.PhaseInfo->Id == cond->SourceGroup)
            {
                phase.Conditions.push_back(cond);
                return true;
            }
        }
    }

    TC_LOG_ERROR("sql.sql", "%s Area %u does not have phase %u.", cond->ToString().c_str(), cond->SourceGroup, cond->SourceEntry);
    return false;
}

bool ConditionMgr::isSourceTypeValid(Condition* cond) const
{
    switch (cond->SourceType)
    {
        case CONDITION_SOURCE_TYPE_CREATURE_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Creature.HaveLootFor(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceGroup in `condition` table, does not exist in `creature_loot_template`, ignoring.", cond->ToString().c_str());
                return false;
            }

            LootTemplate* loot = LootTemplates_Creature.GetLootForConditionFill(cond->SourceGroup);
            ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!pItemProto && !loot->isReference(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceType, SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString().c_str());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_DISENCHANT_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Disenchant.HaveLootFor(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceGroup in `condition` table, does not exist in `disenchant_loot_template`, ignoring.", cond->ToString().c_str());
                return false;
            }

            LootTemplate* loot = LootTemplates_Disenchant.GetLootForConditionFill(cond->SourceGroup);
            ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!pItemProto && !loot->isReference(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceType, SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString().c_str());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_FISHING_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Fishing.HaveLootFor(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceGroup in `condition` table, does not exist in `fishing_loot_template`, ignoring.", cond->ToString().c_str());
                return false;
            }

            LootTemplate* loot = LootTemplates_Fishing.GetLootForConditionFill(cond->SourceGroup);
            ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!pItemProto && !loot->isReference(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceType, SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString().c_str());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_GAMEOBJECT_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Gameobject.HaveLootFor(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceGroup in `condition` table, does not exist in `gameobject_loot_template`, ignoring.", cond->ToString().c_str());
                return false;
            }

            LootTemplate* loot = LootTemplates_Gameobject.GetLootForConditionFill(cond->SourceGroup);
            ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!pItemProto && !loot->isReference(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceType, SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString().c_str());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_ITEM_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Item.HaveLootFor(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceGroup in `condition` table, does not exist in `item_loot_template`, ignoring.", cond->ToString().c_str());
                return false;
            }

            LootTemplate* loot = LootTemplates_Item.GetLootForConditionFill(cond->SourceGroup);
            ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!pItemProto && !loot->isReference(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceType, SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString().c_str());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_MAIL_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Mail.HaveLootFor(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceGroup in `condition` table, does not exist in `mail_loot_template`, ignoring.", cond->ToString().c_str());
                return false;
            }

            LootTemplate* loot = LootTemplates_Mail.GetLootForConditionFill(cond->SourceGroup);
            ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!pItemProto && !loot->isReference(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceType, SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString().c_str());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_MILLING_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Milling.HaveLootFor(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceGroup in `condition` table, does not exist in `milling_loot_template`, ignoring.", cond->ToString().c_str());
                return false;
            }

            LootTemplate* loot = LootTemplates_Milling.GetLootForConditionFill(cond->SourceGroup);
            ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!pItemProto && !loot->isReference(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceType, SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString().c_str());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_PICKPOCKETING_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Pickpocketing.HaveLootFor(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceGroup in `condition` table, does not exist in `pickpocketing_loot_template`, ignoring.", cond->ToString().c_str());
                return false;
            }

            LootTemplate* loot = LootTemplates_Pickpocketing.GetLootForConditionFill(cond->SourceGroup);
            ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!pItemProto && !loot->isReference(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceType, SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString().c_str());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_PROSPECTING_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Prospecting.HaveLootFor(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceGroup in `condition` table, does not exist in `prospecting_loot_template`, ignoring.", cond->ToString().c_str());
                return false;
            }

            LootTemplate* loot = LootTemplates_Prospecting.GetLootForConditionFill(cond->SourceGroup);
            ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!pItemProto && !loot->isReference(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceType, SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString().c_str());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_REFERENCE_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Reference.HaveLootFor(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceGroup in `condition` table, does not exist in `reference_loot_template`, ignoring.", cond->ToString().c_str());
                return false;
            }

            LootTemplate* loot = LootTemplates_Reference.GetLootForConditionFill(cond->SourceGroup);
            ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!pItemProto && !loot->isReference(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceType, SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString().c_str());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_SKINNING_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Skinning.HaveLootFor(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceGroup in `condition` table, does not exist in `skinning_loot_template`, ignoring.", cond->ToString().c_str());
                return false;
            }

            LootTemplate* loot = LootTemplates_Skinning.GetLootForConditionFill(cond->SourceGroup);
            ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!pItemProto && !loot->isReference(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceType, SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString().c_str());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_SPELL_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Spell.HaveLootFor(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceGroup in `condition` table, does not exist in `spell_loot_template`, ignoring.", cond->ToString().c_str());
                return false;
            }

            LootTemplate* loot = LootTemplates_Spell.GetLootForConditionFill(cond->SourceGroup);
            ItemTemplate const* pItemProto = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!pItemProto && !loot->isReference(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceType, SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString().c_str());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_SPELL_IMPLICIT_TARGET:
        {
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(cond->SourceEntry, DIFFICULTY_NONE);
            if (!spellInfo)
            {
                TC_LOG_ERROR("sql.sql", "%s SourceEntry in `condition` table does not exist in `spell.dbc`, ignoring.", cond->ToString().c_str());
                return false;
            }

            if ((cond->SourceGroup > MAX_EFFECT_MASK) || !cond->SourceGroup)
            {
                TC_LOG_ERROR("sql.sql", "%s in `condition` table, has incorrect SourceGroup (spell effectMask) set, ignoring.", cond->ToString().c_str());
                return false;
            }

            uint32 origGroup = cond->SourceGroup;

            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            {
                if (!((1 << i) & cond->SourceGroup))
                    continue;

                SpellEffectInfo const* effect = spellInfo->GetEffect(i);
                if (!effect)
                    continue;

                if (effect->ChainTargets > 0)
                    continue;

                switch (effect->TargetA.GetSelectionCategory())
                {
                    case TARGET_SELECT_CATEGORY_NEARBY:
                    case TARGET_SELECT_CATEGORY_CONE:
                    case TARGET_SELECT_CATEGORY_AREA:
                    case TARGET_SELECT_CATEGORY_TRAJ:
                        continue;
                    default:
                        break;
                }

                switch (effect->TargetB.GetSelectionCategory())
                {
                    case TARGET_SELECT_CATEGORY_NEARBY:
                    case TARGET_SELECT_CATEGORY_CONE:
                    case TARGET_SELECT_CATEGORY_AREA:
                    case TARGET_SELECT_CATEGORY_TRAJ:
                        continue;
                    default:
                        break;
                }

                TC_LOG_ERROR("sql.sql", "SourceEntry %u SourceGroup %u in `condition` table - spell %u does not have implicit targets of types: _AREA_, _CONE_, _NEARBY_, __CHAIN__ for effect %u, SourceGroup needs correction, ignoring.", cond->SourceEntry, origGroup, cond->SourceEntry, uint32(i));
                cond->SourceGroup &= ~(1 << i);
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
                TC_LOG_ERROR("sql.sql", "%s SourceEntry in `condition` table, does not exist in `creature_template`, ignoring.", cond->ToString().c_str());
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
                TC_LOG_ERROR("sql.sql", "%s SourceEntry in `condition` table does not exist in `spell.dbc`, ignoring.", cond->ToString().c_str());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_QUEST_AVAILABLE:
            if (!sObjectMgr->GetQuestTemplate(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceEntry specifies non-existing quest, skipped.", cond->ToString().c_str());
                return false;
            }
            break;
        case CONDITION_SOURCE_TYPE_VEHICLE_SPELL:
            if (!sObjectMgr->GetCreatureTemplate(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceEntry in `condition` table, does not exist in `creature_template`, ignoring.", cond->ToString().c_str());
                return false;
            }

            if (!sSpellMgr->GetSpellInfo(cond->SourceEntry, DIFFICULTY_NONE))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceEntry in `condition` table does not exist in `spell.dbc`, ignoring.", cond->ToString().c_str());
                return false;
            }
            break;
        case CONDITION_SOURCE_TYPE_SPELL_CLICK_EVENT:
            if (!sObjectMgr->GetCreatureTemplate(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceEntry in `condition` table, does not exist in `creature_template`, ignoring.", cond->ToString().c_str());
                return false;
            }

            if (!sSpellMgr->GetSpellInfo(cond->SourceEntry, DIFFICULTY_NONE))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceEntry in `condition` table does not exist in `spell.dbc`, ignoring.", cond->ToString().c_str());
                return false;
            }
            break;
        case CONDITION_SOURCE_TYPE_NPC_VENDOR:
        {
            if (!sObjectMgr->GetCreatureTemplate(cond->SourceGroup))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceEntry in `condition` table, does not exist in `creature_template`, ignoring.", cond->ToString().c_str());
                return false;
            }
            ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(cond->SourceEntry);
            if (!itemTemplate)
            {
                TC_LOG_ERROR("sql.sql", "%s SourceEntry in `condition` table, item does not exist, ignoring.", cond->ToString().c_str());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_TERRAIN_SWAP:
        {
            if (!sMapStore.LookupEntry(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceEntry in `condition` table, does not exist in Map.dbc, ignoring.", cond->ToString().c_str());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_PHASE:
        {
            if (cond->SourceEntry && !sAreaTableStore.LookupEntry(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceEntry in `condition` table, does not exist in AreaTable.dbc, ignoring.", cond->ToString().c_str());
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_GOSSIP_MENU:
        case CONDITION_SOURCE_TYPE_GOSSIP_MENU_OPTION:
        case CONDITION_SOURCE_TYPE_SMART_EVENT:
            break;
        case CONDITION_SOURCE_TYPE_GRAVEYARD:
            if (!sObjectMgr->GetWorldSafeLoc(cond->SourceEntry))
            {
                TC_LOG_ERROR("sql.sql", "%s SourceEntry in `condition` table, does not exist in WorldSafeLocs.db2, ignoring.", cond->ToString().c_str());
                return false;
            }
            break;
        default:
            TC_LOG_ERROR("sql.sql", "%s Invalid ConditionSourceType in `condition` table, ignoring.", cond->ToString().c_str());
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
                TC_LOG_ERROR("sql.sql", "%s has non existing spell (Id: %d), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }

            if (cond->ConditionValue2 > EFFECT_2)
            {
                TC_LOG_ERROR("sql.sql", "%s has non existing effect index (%u) (must be 0..2), skipped.", cond->ToString(true).c_str(), cond->ConditionValue2);
                return false;
            }
            break;
        }
        case CONDITION_ITEM:
        {
            ItemTemplate const* proto = sObjectMgr->GetItemTemplate(cond->ConditionValue1);
            if (!proto)
            {
                TC_LOG_ERROR("sql.sql", "%s Item (%u) does not exist, skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }

            if (!cond->ConditionValue2)
            {
                TC_LOG_ERROR("sql.sql", "%s Zero item count in ConditionValue2, skipped.", cond->ToString(true).c_str());
                return false;
            }
            break;
        }
        case CONDITION_ITEM_EQUIPPED:
        {
            ItemTemplate const* proto = sObjectMgr->GetItemTemplate(cond->ConditionValue1);
            if (!proto)
            {
                TC_LOG_ERROR("sql.sql", "%s Item (%u) does not exist, skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_ZONEID:
        {
            AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(cond->ConditionValue1);
            if (!areaEntry)
            {
                TC_LOG_ERROR("sql.sql", "%s Area (%u) does not exist, skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }

            if (areaEntry->ParentAreaID != 0)
            {
                TC_LOG_ERROR("sql.sql", "%s requires to be in area (%u) which is a subzone but zone expected, skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_REPUTATION_RANK:
        {
            FactionEntry const* factionEntry = sFactionStore.LookupEntry(cond->ConditionValue1);
            if (!factionEntry)
            {
                TC_LOG_ERROR("sql.sql", "%s has non existing faction (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_TEAM:
        {
            if (cond->ConditionValue1 != ALLIANCE && cond->ConditionValue1 != HORDE)
            {
                TC_LOG_ERROR("sql.sql", "%s specifies unknown team (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_SKILL:
        {
            SkillLineEntry const* pSkill = sSkillLineStore.LookupEntry(cond->ConditionValue1);
            if (!pSkill)
            {
                TC_LOG_ERROR("sql.sql", "%s specifies non-existing skill (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }

            if (cond->ConditionValue2 < 1 || cond->ConditionValue2 > sWorld->GetConfigMaxSkillValue())
            {
                TC_LOG_ERROR("sql.sql", "%s specifies skill (%u) with invalid value (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1, cond->ConditionValue2);
                return false;
            }
            break;
        }
        case CONDITION_QUESTSTATE:
            if (cond->ConditionValue2 >= (1 << MAX_QUEST_STATUS))
            {
                TC_LOG_ERROR("sql.sql", "%s has invalid state mask (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue2);
                return false;
            }
            /* fallthrough */
        case CONDITION_QUESTREWARDED:
        case CONDITION_QUESTTAKEN:
        case CONDITION_QUEST_NONE:
        case CONDITION_QUEST_COMPLETE:
        case CONDITION_DAILY_QUEST_DONE:
        {
            if (!sObjectMgr->GetQuestTemplate(cond->ConditionValue1))
            {
                TC_LOG_ERROR("sql.sql", "%s points to non-existing quest (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_ACTIVE_EVENT:
        {
            GameEventMgr::GameEventDataMap const& events = sGameEventMgr->GetEventMap();
            if (cond->ConditionValue1 >= events.size() || !events[cond->ConditionValue1].isValid())
            {
                TC_LOG_ERROR("sql.sql", "%s has non existing event id (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_ACHIEVEMENT:
        {
            AchievementEntry const* achievement = sAchievementStore.LookupEntry(cond->ConditionValue1);
            if (!achievement)
            {
                TC_LOG_ERROR("sql.sql", "%s has non existing achivement id (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_CLASS:
        {
            if (cond->ConditionValue1 & ~CLASSMASK_ALL_PLAYABLE)
            {
                TC_LOG_ERROR("sql.sql", "%s has non existing classmask (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1 & ~CLASSMASK_ALL_PLAYABLE);
                return false;
            }
            break;
        }
        case CONDITION_RACE:
        {
            if (uint32(cond->ConditionValue1 & ~RACEMASK_ALL_PLAYABLE)) // uint32 works thanks to weird index remapping in racemask
            {
                TC_LOG_ERROR("sql.sql", "%s has non existing racemask (" UI64FMTD "), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1 & ~RACEMASK_ALL_PLAYABLE);
                return false;
            }
            break;
        }
        case CONDITION_GENDER:
        {
            if (!Player::IsValidGender(uint8(cond->ConditionValue1)))
            {
                TC_LOG_ERROR("sql.sql", "%s has invalid gender (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_MAPID:
        {
            MapEntry const* me = sMapStore.LookupEntry(cond->ConditionValue1);
            if (!me)
            {
                TC_LOG_ERROR("sql.sql", "%s has non existing map (%u), skipped", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_SPELL:
        {
            if (!sSpellMgr->GetSpellInfo(cond->ConditionValue1, DIFFICULTY_NONE))
            {
                TC_LOG_ERROR("sql.sql", "%s has non existing spell (Id: %d), skipped", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_LEVEL:
        {
            if (cond->ConditionValue2 >= COMP_TYPE_MAX)
            {
                TC_LOG_ERROR("sql.sql", "%s has invalid ComparisionType (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue2);
                return false;
            }
            break;
        }
        case CONDITION_DRUNKENSTATE:
        {
            if (cond->ConditionValue1 > DRUNKEN_SMASHED)
            {
                TC_LOG_ERROR("sql.sql", "%s has invalid state (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_NEAR_CREATURE:
        {
            if (!sObjectMgr->GetCreatureTemplate(cond->ConditionValue1))
            {
                TC_LOG_ERROR("sql.sql", "%s has non existing creature template entry (%u), skipped", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_NEAR_GAMEOBJECT:
        {
            if (!sObjectMgr->GetGameObjectTemplate(cond->ConditionValue1))
            {
                TC_LOG_ERROR("sql.sql", "%s has non existing gameobject template entry (%u), skipped.", cond->ToString().c_str(), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_OBJECT_ENTRY_GUID_LEGACY:
            cond->ConditionType = CONDITION_OBJECT_ENTRY_GUID;
            cond->ConditionValue1 = Trinity::Legacy::ConvertLegacyTypeID(Trinity::Legacy::TypeID(cond->ConditionValue1));
            /* fallthrough */
        case CONDITION_OBJECT_ENTRY_GUID:
        {
            switch (cond->ConditionValue1)
            {
                case TYPEID_UNIT:
                    if (cond->ConditionValue2 && !sObjectMgr->GetCreatureTemplate(cond->ConditionValue2))
                    {
                        TC_LOG_ERROR("sql.sql", "%s has non existing creature template entry (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue2);
                        return false;
                    }
                    if (cond->ConditionValue3)
                    {
                        if (CreatureData const* creatureData = sObjectMgr->GetCreatureData(cond->ConditionValue3))
                        {
                            if (cond->ConditionValue2 && creatureData->id != cond->ConditionValue2)
                            {
                                TC_LOG_ERROR("sql.sql", "%s has guid %u set but does not match creature entry (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue3, cond->ConditionValue2);
                                return false;
                            }
                        }
                        else
                        {
                            TC_LOG_ERROR("sql.sql", "%s has non existing creature guid (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue3);
                            return false;
                        }
                    }
                    break;
                case TYPEID_GAMEOBJECT:
                    if (cond->ConditionValue2 && !sObjectMgr->GetGameObjectTemplate(cond->ConditionValue2))
                    {
                        TC_LOG_ERROR("sql.sql", "%s has non existing gameobject template entry (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue2);
                        return false;
                    }
                    if (cond->ConditionValue3)
                    {
                        if (GameObjectData const* goData = sObjectMgr->GetGameObjectData(cond->ConditionValue3))
                        {
                            if (cond->ConditionValue2 && goData->id != cond->ConditionValue2)
                            {
                                TC_LOG_ERROR("sql.sql", "%s has guid %u set but does not match gameobject entry (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue3, cond->ConditionValue2);
                                return false;
                            }
                        }
                        else
                        {
                            TC_LOG_ERROR("sql.sql", "%s has non existing gameobject guid (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue3);
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
                    TC_LOG_ERROR("sql.sql", "%s has wrong typeid set (%u), skipped", cond->ToString(true).c_str(), cond->ConditionValue1);
                    return false;
            }
            break;
        }
        case CONDITION_TYPE_MASK_LEGACY:
            cond->ConditionType = CONDITION_TYPE_MASK;
            cond->ConditionValue1 = Trinity::Legacy::ConvertLegacyTypeMask(cond->ConditionValue1);
            /* fallthrough */
        case CONDITION_TYPE_MASK:
        {
            if (!cond->ConditionValue1 || (cond->ConditionValue1 & ~(TYPEMASK_UNIT | TYPEMASK_PLAYER | TYPEMASK_GAMEOBJECT | TYPEMASK_CORPSE)))
            {
                TC_LOG_ERROR("sql.sql", "%s has invalid typemask set (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue2);
                return false;
            }
            break;
        }
        case CONDITION_RELATION_TO:
        {
            if (cond->ConditionValue1 >= cond->GetMaxAvailableConditionTargets())
            {
                TC_LOG_ERROR("sql.sql", "%s has invalid ConditionValue1(ConditionTarget selection) (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            if (cond->ConditionValue1 == cond->ConditionTarget)
            {
                TC_LOG_ERROR("sql.sql", "%s has ConditionValue1(ConditionTarget selection) set to self (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            if (cond->ConditionValue2 >= RELATION_MAX)
            {
                TC_LOG_ERROR("sql.sql", "%s has invalid ConditionValue2(RelationType) (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue2);
                return false;
            }
            break;
        }
        case CONDITION_REACTION_TO:
        {
            if (cond->ConditionValue1 >= cond->GetMaxAvailableConditionTargets())
            {
                TC_LOG_ERROR("sql.sql", "%s has invalid ConditionValue1(ConditionTarget selection) (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            if (cond->ConditionValue1 == cond->ConditionTarget)
            {
                TC_LOG_ERROR("sql.sql", "%s has ConditionValue1(ConditionTarget selection) set to self (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            if (!cond->ConditionValue2)
            {
                TC_LOG_ERROR("sql.sql", "%s has invalid ConditionValue2(rankMask) (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue2);
                return false;
            }
            break;
        }
        case CONDITION_DISTANCE_TO:
        {
            if (cond->ConditionValue1 >= cond->GetMaxAvailableConditionTargets())
            {
                TC_LOG_ERROR("sql.sql", "%s has invalid ConditionValue1(ConditionTarget selection) (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            if (cond->ConditionValue1 == cond->ConditionTarget)
            {
                TC_LOG_ERROR("sql.sql", "%s has ConditionValue1(ConditionTarget selection) set to self (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            if (cond->ConditionValue3 >= COMP_TYPE_MAX)
            {
                TC_LOG_ERROR("sql.sql", "%s has invalid ComparisionType (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue3);
                return false;
            }
            break;
        }
        case CONDITION_HP_VAL:
        {
            if (cond->ConditionValue2 >= COMP_TYPE_MAX)
            {
                TC_LOG_ERROR("sql.sql", "%s has invalid ComparisionType (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue2);
                return false;
            }
            break;
        }
        case CONDITION_HP_PCT:
        {
            if (cond->ConditionValue1 > 100)
            {
                TC_LOG_ERROR("sql.sql", "%s has too big percent value (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            if (cond->ConditionValue2 >= COMP_TYPE_MAX)
            {
                TC_LOG_ERROR("sql.sql", "%s has invalid ComparisionType (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue2);
                return false;
            }
            break;
        }
        case CONDITION_WORLD_STATE:
        {
            if (!sWorld->getWorldState(cond->ConditionValue1))
            {
                TC_LOG_ERROR("sql.sql", "%s has non existing world state in value1 (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_PHASEID:
        {
            if (!sPhaseStore.LookupEntry(cond->ConditionValue1))
            {
                TC_LOG_ERROR("sql.sql", "%s has nonexistent phaseid in value1 (%u), skipped", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_TITLE:
        {
            CharTitlesEntry const* titleEntry = sCharTitlesStore.LookupEntry(cond->ConditionValue1);
            if (!titleEntry)
            {
                TC_LOG_ERROR("sql.sql", "%s has non existing title in value1 (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_SPAWNMASK_DEPRECATED:
        {
            TC_LOG_ERROR("sql.sql", "%s using deprecated condition type CONDITION_SPAWNMASK.", cond->ToString(true).c_str());
            return false;
        }
        case CONDITION_UNIT_STATE:
        {
            if (!(cond->ConditionValue1 & UNIT_STATE_ALL_STATE_SUPPORTED))
            {
                TC_LOG_ERROR("sql.sql", "%s has non existing UnitState in value1 (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_CREATURE_TYPE:
        {
            if (!cond->ConditionValue1 || cond->ConditionValue1 > CREATURE_TYPE_GAS_CLOUD)
            {
                TC_LOG_ERROR("sql.sql", "%s has non existing CreatureType in value1 (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_REALM_ACHIEVEMENT:
        {
            AchievementEntry const* achievement = sAchievementStore.LookupEntry(cond->ConditionValue1);
            if (!achievement)
            {
                TC_LOG_ERROR("sql.sql", "%s has non existing realm first achivement id (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
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
                TC_LOG_ERROR("sql.sql", "%s has non-existing stand state (%u,%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1, cond->ConditionValue2);
                return false;
            }
            break;
        }
        case CONDITION_QUEST_OBJECTIVE_COMPLETE:
        {
            QuestObjective const* obj = sObjectMgr->GetQuestObjective(cond->ConditionValue1);
            if (!obj)
            {
                TC_LOG_ERROR("sql.sql", "%s points to non-existing quest objective (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_PET_TYPE:
            if (cond->ConditionValue1 >= (1 << MAX_PET_TYPE))
            {
                TC_LOG_ERROR("sql.sql", "%s has non-existing pet type %u, skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            break;
        case CONDITION_INSTANCE_INFO:
        case CONDITION_AREAID:
        case CONDITION_ALIVE:
        case CONDITION_IN_WATER:
        case CONDITION_TERRAIN_SWAP:
        case CONDITION_CHARMED:
        case CONDITION_TAXI:
            break;
        case CONDITION_DIFFICULTY_ID:
            if (!sDifficultyStore.LookupEntry(cond->ConditionValue1))
            {
                TC_LOG_ERROR("sql.sql", "%s has non existing difficulty in value1 (%u), skipped.", cond->ToString(true).c_str(), cond->ConditionValue1);
                return false;
            }
            break;
        default:
            TC_LOG_ERROR("sql.sql", "%s Invalid ConditionType in `condition` table, ignoring.", cond->ToString().c_str());
            return false;
    }

    if (cond->ConditionTarget >= cond->GetMaxAvailableConditionTargets())
    {
        TC_LOG_ERROR("sql.sql", "%s in `condition` table, has incorrect ConditionTarget set, ignoring.", cond->ToString(true).c_str());
        return false;
    }

    if (cond->ConditionValue1 && !StaticConditionTypeData[cond->ConditionType].HasConditionValue1)
        LogUselessConditionValue(cond, 1, cond->ConditionValue1);
    if (cond->ConditionValue2 && !StaticConditionTypeData[cond->ConditionType].HasConditionValue2)
        LogUselessConditionValue(cond, 2, cond->ConditionValue2);
    if (cond->ConditionValue3 && !StaticConditionTypeData[cond->ConditionType].HasConditionValue3)
        LogUselessConditionValue(cond, 3, cond->ConditionValue3);

    return true;
}

void ConditionMgr::LogUselessConditionValue(Condition* cond, uint8 index, uint32 value)
{
    TC_LOG_ERROR("sql.sql", "%s has useless data in ConditionValue%u (%u)!", cond->ToString(true).c_str(), index, value);
}

void ConditionMgr::Clean()
{
    for (ConditionReferenceContainer::iterator itr = ConditionReferenceStore.begin(); itr != ConditionReferenceStore.end(); ++itr)
        for (ConditionContainer::const_iterator it = itr->second.begin(); it != itr->second.end(); ++it)
            delete *it;

    ConditionReferenceStore.clear();

    for (uint32 i = 0; i < CONDITION_SOURCE_TYPE_MAX; ++i)
    {
        for (ConditionsByEntryMap::iterator it = ConditionStore[i].begin(); it != ConditionStore[i].end(); ++it)
            for (ConditionContainer::const_iterator itr = it->second.begin(); itr != it->second.end(); ++itr)
                delete *itr;

        ConditionStore[i].clear();
    }

    for (ConditionEntriesByCreatureIdMap::iterator itr = VehicleSpellConditionStore.begin(); itr != VehicleSpellConditionStore.end(); ++itr)
        for (ConditionsByEntryMap::iterator it = itr->second.begin(); it != itr->second.end(); ++it)
            for (ConditionContainer::const_iterator i = it->second.begin(); i != it->second.end(); ++i)
                delete *i;

    VehicleSpellConditionStore.clear();

    for (SmartEventConditionContainer::iterator itr = SmartEventConditionStore.begin(); itr != SmartEventConditionStore.end(); ++itr)
        for (ConditionsByEntryMap::iterator it = itr->second.begin(); it != itr->second.end(); ++it)
            for (ConditionContainer::const_iterator i = it->second.begin(); i != it->second.end(); ++i)
                delete *i;

    SmartEventConditionStore.clear();

    for (ConditionEntriesByCreatureIdMap::iterator itr = SpellClickEventConditionStore.begin(); itr != SpellClickEventConditionStore.end(); ++itr)
        for (ConditionsByEntryMap::iterator it = itr->second.begin(); it != itr->second.end(); ++it)
            for (ConditionContainer::const_iterator i = it->second.begin(); i != it->second.end(); ++i)
                delete *i;

    SpellClickEventConditionStore.clear();

    for (ConditionEntriesByCreatureIdMap::iterator itr = NpcVendorConditionContainerStore.begin(); itr != NpcVendorConditionContainerStore.end(); ++itr)
        for (ConditionsByEntryMap::iterator it = itr->second.begin(); it != itr->second.end(); ++it)
            for (ConditionContainer::const_iterator i = it->second.begin(); i != it->second.end(); ++i)
                delete *i;

    NpcVendorConditionContainerStore.clear();

    // this is a BIG hack, feel free to fix it if you can figure out the ConditionMgr ;)
    for (std::vector<Condition*>::const_iterator itr = AllocatedMemoryStore.begin(); itr != AllocatedMemoryStore.end(); ++itr)
        delete *itr;

    AllocatedMemoryStore.clear();
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

            if (lfg::LfgReward const* reward = sLFGMgr->GetRandomDungeonReward(selectedRandomDungeon, player->getLevel()))
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
            if (minLevel && player->getLevel() >= minLevel && (!maxLevel || player->getLevel() <= maxLevel))
                return false;

            if (maxLevel && player->getLevel() <= maxLevel && (!minLevel || player->getLevel() >= minLevel))
                return false;
        }
        else
        {
            if (minLevel && player->getLevel() < minLevel)
                return false;

            if (maxLevel && player->getLevel() > maxLevel)
                return false;
        }
    }

    if (condition->RaceMask && !condition->RaceMask.HasRace(player->getRace()))
        return false;

    if (condition->ClassMask && !(player->getClassMask() & condition->ClassMask))
        return false;

    if (condition->Gender >= 0 && player->getGender() != condition->Gender)
        return false;

    if (condition->NativeGender >= 0 && player->GetNativeSex() != condition->NativeGender)
        return false;

    if (condition->PowerType != -1 && condition->PowerTypeComp)
    {
        int32 requiredPowerValue = condition->Flags & 4 ? player->GetMaxPower(Powers(condition->PowerType)) : condition->PowerTypeValue;
        if (!PlayerConditionCompare(condition->PowerTypeComp, player->GetPower(Powers(condition->PowerType)), requiredPowerValue))
            return false;
    }

    if (condition->ChrSpecializationIndex >= 0 || condition->ChrSpecializationRole >= 0)
    {
        if (ChrSpecializationEntry const* spec = sChrSpecializationStore.LookupEntry(player->GetPrimarySpecialization()))
        {
            if (condition->ChrSpecializationIndex >= 0 && spec->OrderIndex != condition->ChrSpecializationIndex)
                return false;

            if (condition->ChrSpecializationRole >= 0 && spec->Role != condition->ChrSpecializationRole)
                return false;
        }
    }

    if (condition->SkillID[0] || condition->SkillID[1] || condition->SkillID[2] || condition->SkillID[3])
    {
        using SkillCount = std::extent<decltype(condition->SkillID)>;

        std::array<bool, SkillCount::value> results;
        results.fill(true);
        for (std::size_t i = 0; i < SkillCount::value; ++i)
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
        if (LanguageDesc const* lang = GetLanguageDescByID(condition->LanguageID))
        {
            int32 languageSkill = player->GetSkillValue(lang->skill_id);
            if (!languageSkill && player->HasAuraTypeWithMiscvalue(SPELL_AURA_COMPREHEND_LANGUAGE, condition->LanguageID))
                languageSkill = 300;

            if (condition->MinLanguage && languageSkill < condition->MinLanguage)
                return false;

            if (condition->MaxLanguage && languageSkill > condition->MaxLanguage)
                return false;
        }
    }

    if (condition->MinFactionID[0] && condition->MinFactionID[1] && condition->MinFactionID[2] && condition->MaxFactionID)
    {
        if (!condition->MinFactionID[0] && !condition->MinFactionID[1] && !condition->MinFactionID[2])
        {
            if (ReputationRank const* forcedRank = player->GetReputationMgr().GetForcedRankIfAny(condition->MaxFactionID))
            {
                if (*forcedRank > ReputationRank(condition->MaxReputation))
                    return false;
            }
            else if (player->GetReputationRank(condition->MaxFactionID) > ReputationRank(condition->MaxReputation))
                return false;
        }
        else
        {
            using FactionCount = std::extent<decltype(condition->MinFactionID)>;

            std::array<bool, FactionCount::value + 1> results;
            results.fill(true);
            for (std::size_t i = 0; i < FactionCount::value; ++i)
            {
                if (condition->MinFactionID[i])
                {
                    if (ReputationRank const* forcedRank = player->GetReputationMgr().GetForcedRankIfAny(condition->MinFactionID[i]))
                        results[i] = *forcedRank >= ReputationRank(condition->MinReputation[i]);
                    else
                        results[i] = player->GetReputationRank(condition->MinFactionID[i]) >= ReputationRank(condition->MinReputation[i]);
                }
            }

            if (ReputationRank const* forcedRank = player->GetReputationMgr().GetForcedRankIfAny(condition->MaxFactionID))
                results[3] = *forcedRank <= ReputationRank(condition->MaxReputation);
            else
                results[3] = player->GetReputationRank(condition->MaxFactionID) <= ReputationRank(condition->MaxReputation);

            if (!PlayerConditionLogic(condition->ReputationLogic, results))
                return false;
        }
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
        using PrevQuestCount = std::extent<decltype(condition->PrevQuestID)>;

        std::array<bool, PrevQuestCount::value> results;
        results.fill(true);
        for (std::size_t i = 0; i < PrevQuestCount::value; ++i)
            if (uint32 questBit = sDB2Manager.GetQuestUniqueBitFlag(condition->PrevQuestID[i]))
                results[i] = (player->m_activePlayerData->QuestCompleted[((questBit - 1) >> 6)] & (UI64LIT(1) << ((questBit - 1) & 63))) != 0;

        if (!PlayerConditionLogic(condition->PrevQuestLogic, results))
            return false;
    }

    if (condition->CurrQuestID[0])
    {
        using CurrQuestCount = std::extent<decltype(condition->CurrQuestID)>;

        std::array<bool, CurrQuestCount::value> results;
        results.fill(true);
        for (std::size_t i = 0; i < CurrQuestCount::value; ++i)
            if (condition->CurrQuestID[i])
                results[i] = player->FindQuestSlot(condition->CurrQuestID[i]) != MAX_QUEST_LOG_SIZE;

        if (!PlayerConditionLogic(condition->CurrQuestLogic, results))
            return false;
    }

    if (condition->CurrentCompletedQuestID[0])
    {
        using CurrentCompletedQuestCount = std::extent<decltype(condition->CurrentCompletedQuestID)>;

        std::array<bool, CurrentCompletedQuestCount::value> results;
        results.fill(true);
        for (std::size_t i = 0; i < CurrentCompletedQuestCount::value; ++i)
            if (condition->CurrentCompletedQuestID[i])
                results[i] = player->GetQuestStatus(condition->CurrentCompletedQuestID[i]) == QUEST_STATUS_COMPLETE;

        if (!PlayerConditionLogic(condition->CurrentCompletedQuestLogic, results))
            return false;
    }


    if (condition->SpellID[0])
    {
        using SpellCount = std::extent<decltype(condition->SpellID)>;

        std::array<bool, SpellCount::value> results;
        results.fill(true);
        for (std::size_t i = 0; i < SpellCount::value; ++i)
            if (condition->SpellID[i])
                results[i] = player->HasSpell(condition->SpellID[i]);

        if (!PlayerConditionLogic(condition->SpellLogic, results))
            return false;
    }

    if (condition->ItemID[0])
    {
        using ItemCount = std::extent<decltype(condition->ItemID)>;

        std::array<bool, ItemCount::value> results;
        results.fill(true);
        for (std::size_t i = 0; i < ItemCount::value; ++i)
            if (condition->ItemID[i])
                results[i] = player->GetItemCount(condition->ItemID[i], condition->ItemFlags != 0) >= condition->ItemCount[i];

        if (!PlayerConditionLogic(condition->ItemLogic, results))
            return false;
    }

    if (condition->CurrencyID[0])
    {
        using CurrencyCount = std::extent<decltype(condition->CurrencyID)>;

        std::array<bool, CurrencyCount::value> results;
        results.fill(true);
        for (std::size_t i = 0; i < CurrencyCount::value; ++i)
            if (condition->CurrencyID[i])
                results[i] = player->GetCurrency(condition->CurrencyID[i]) >= condition->CurrencyCount[i];

        if (!PlayerConditionLogic(condition->CurrencyLogic, results))
            return false;
    }

    if (condition->Explored[0] || condition->Explored[1])
    {
        using ExploredCount = std::extent<decltype(condition->Explored)>;

        for (std::size_t i = 0; i < ExploredCount::value; ++i)
        {
            if (AreaTableEntry const* area = sAreaTableStore.LookupEntry(condition->Explored[i]))
                if (area->AreaBit != -1 && !(player->m_activePlayerData->ExploredZones[area->AreaBit / 64] & (UI64LIT(1) << (uint32(area->AreaBit) % 64))))
                    return false;
        }
    }

    if (condition->AuraSpellID[0])
    {
        using AuraCount = std::extent<decltype(condition->AuraSpellID)>;

        std::array<bool, AuraCount::value> results;
        results.fill(true);
        for (std::size_t i = 0; i < AuraCount::value; ++i)
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

    // TODO: time condition

    if (condition->WorldStateExpressionID)
    {
        WorldStateExpressionEntry const* worldStateExpression = sWorldStateExpressionStore.LookupEntry(condition->WorldStateExpressionID);
        if (!worldStateExpression)
            return false;

        if (!IsPlayerMeetingExpression(player, worldStateExpression))
            return false;
    }

    // TODO: weather condition

    if (condition->Achievement[0])
    {
        using AchievementCount = std::extent<decltype(condition->Achievement)>;

        std::array<bool, AchievementCount::value> results;
        results.fill(true);
        for (std::size_t i = 0; i < AchievementCount::value; ++i)
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
        using LfgCount = std::extent<decltype(condition->LfgStatus)>;

        std::array<bool, LfgCount::value> results;
        results.fill(true);
        for (std::size_t i = 0; i < LfgCount::value; ++i)
            if (condition->LfgStatus[i])
                results[i] = PlayerConditionCompare(condition->LfgCompare[i],
                    GetPlayerConditionLfgValue(player, PlayerConditionLfgStatus(condition->LfgStatus[i])),
                    condition->LfgValue[i]);

        if (!PlayerConditionLogic(condition->LfgLogic, results))
            return false;
    }

    if (condition->AreaID[0])
    {
        using AreaCount = std::extent<decltype(condition->AreaID)>;

        std::array<bool, AreaCount::value> results;
        results.fill(true);
        for (std::size_t i = 0; i < AreaCount::value; ++i)
            if (condition->AreaID[i])
                results[i] = player->GetAreaId() == condition->AreaID[i] || player->GetZoneId() == condition->AreaID[i];

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
        if (quest && player->GetQuestStatus(condition->QuestKillID) != QUEST_STATUS_COMPLETE)
        {
            using QuestKillCount = std::extent<decltype(condition->QuestKillMonster)>;

            std::array<bool, QuestKillCount::value> results;
            results.fill(true);
            for (std::size_t i = 0; i < QuestKillCount::value; ++i)
            {
                if (condition->QuestKillMonster[i])
                {
                    auto objectiveItr = std::find_if(quest->GetObjectives().begin(), quest->GetObjectives().end(), [condition, i](QuestObjective const& objective) -> bool
                    {
                        return objective.Type == QUEST_OBJECTIVE_MONSTER && uint32(objective.ObjectID) == condition->QuestKillMonster[i];
                    });
                    if (objectiveItr != quest->GetObjectives().end())
                        results[i] = player->GetQuestObjectiveData(quest, objectiveItr->StorageIndex) >= objectiveItr->Amount;
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

    return true;
}

ByteBuffer HexToBytes(const std::string& hex)
{
    ByteBuffer buffer(hex.length() / 2, ByteBuffer::Resize{});
    HexStrToByteArray(hex, buffer.contents());
    return buffer;
}

static int32(* const WorldStateExpressionFunctions[WSE_FUNCTION_MAX])(Player const*, uint32, uint32) =
{
    // WSE_FUNCTION_NONE
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_RANDOM
    [](Player const* /*player*/, uint32 arg1, uint32 arg2) -> int32
    {
        return irand(std::min(arg1, arg2), std::max(arg1, arg2));
    },

    // WSE_FUNCTION_MONTH
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return GameTime::GetDateAndTime()->tm_mon + 1;
    },

    // WSE_FUNCTION_DAY
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return GameTime::GetDateAndTime()->tm_mday + 1;
    },

    // WSE_FUNCTION_TIME_OF_DAY
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        tm const* localTime = GameTime::GetDateAndTime();
        return localTime->tm_hour * MINUTE + localTime->tm_min;
    },

    // WSE_FUNCTION_REGION
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return realm.Id.Region;
    },

    // WSE_FUNCTION_CLOCK_HOUR
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        uint32 currentHour = GameTime::GetDateAndTime()->tm_hour + 1;
        return currentHour <= 12 ? (currentHour ? currentHour : 12) : currentHour - 12;
    },

    // WSE_FUNCTION_OLD_DIFFICULTY_ID
    [](Player const* player, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        if (DifficultyEntry const* difficulty = sDifficultyStore.LookupEntry(player->GetMap()->GetDifficultyID()))
            return difficulty->OldEnumValue;

        return -1;
    },

    // WSE_FUNCTION_HOLIDAY_START
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_HOLIDAY_LEFT
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_HOLIDAY_ACTIVE
    [](Player const* /*player*/, uint32 arg1, uint32 /*arg2*/) -> int32
    {
        return int32(IsHolidayActive(HolidayIds(arg1)));
    },

    // WSE_FUNCTION_TIMER_CURRENT_TIME
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return GameTime::GetGameTime();
    },

    // WSE_FUNCTION_WEEK_NUMBER
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        time_t now = GameTime::GetGameTime();
        uint32 raidOrigin = 1135695600;
        if (Cfg_RegionsEntry const* region = sCfgRegionsStore.LookupEntry(realm.Id.Region))
            raidOrigin = region->Raidorigin;

        return (now - raidOrigin) / WEEK;
    },

    // WSE_FUNCTION_UNK13
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK14
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_DIFFICULTY_ID
    [](Player const* player, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return player->GetMap()->GetDifficultyID();
    },

    // WSE_FUNCTION_WAR_MODE_ACTIVE
    [](Player const* player, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return player->HasPlayerFlag(PLAYER_FLAGS_WAR_MODE_ACTIVE);
    },

    // WSE_FUNCTION_UNK17
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK18
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK19
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK20
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK21
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_WORLD_STATE_EXPRESSION
    [](Player const* player, uint32 arg1, uint32 /*arg2*/) -> int32
    {
        if (WorldStateExpressionEntry const* worldStateExpression = sWorldStateExpressionStore.LookupEntry(arg1))
            return ConditionMgr::IsPlayerMeetingExpression(player, worldStateExpression);

        return 0;
    },

    // WSE_FUNCTION_KEYSTONE_AFFIX
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK24
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK25
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK26
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK27
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_KEYSTONE_LEVEL
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK29
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK30
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK31
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK32
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_MERSENNE_RANDOM
    [](Player const* /*player*/, uint32 arg1, uint32 arg2) -> int32
    {
        if (arg1 == 1)
            return 1;

        // init with predetermined seed
        std::mt19937 mt(arg2 ? arg2 : 1);
        return mt() % arg1 + 1;
    },

    // WSE_FUNCTION_UNK34
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK35
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UNK36
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

    // WSE_FUNCTION_UI_WIDGET_DATA
    [](Player const* /*player*/, uint32 /*arg1*/, uint32 /*arg2*/) -> int32
    {
        return 0;
    },

};

int32 EvalSingleValue(ByteBuffer& buffer, Player const* player)
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
            value = sWorld->getWorldState(worldStateId);
            break;
        }
        case WorldStateExpressionValueType::Function:
        {
            uint32 functionType = buffer.read<uint32>();
            int32 arg1 = EvalSingleValue(buffer, player);
            int32 arg2 = EvalSingleValue(buffer, player);

            if (functionType >= WSE_FUNCTION_MAX)
                return 0;

            value = WorldStateExpressionFunctions[functionType](player, arg1, arg2);
        }
        default:
            break;
    }

    return value;
}

int32 EvalValue(ByteBuffer& buffer, Player const* player)
{
    int32 leftValue = EvalSingleValue(buffer, player);

    WorldStateExpressionOperatorType operatorType = buffer.read<WorldStateExpressionOperatorType>();
    if (operatorType == WorldStateExpressionOperatorType::None)
        return leftValue;

    int32 rightValue = EvalSingleValue(buffer, player);

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

bool EvalRelOp(ByteBuffer& buffer, Player const* player)
{
    int32 leftValue = EvalValue(buffer, player);

    WorldStateExpressionComparisonType compareLogic = buffer.read<WorldStateExpressionComparisonType>();
    if (compareLogic == WorldStateExpressionComparisonType::None)
        return leftValue != 0;

    int32 rightValue = EvalValue(buffer, player);

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

bool ConditionMgr::IsPlayerMeetingExpression(Player const* player, WorldStateExpressionEntry const* expression)
{
    ByteBuffer buffer = HexToBytes(expression->Expression);
    if (buffer.empty())
        return false;

    bool enabled = buffer.read<bool>();
    if (!enabled)
        return false;

    bool finalResult = EvalRelOp(buffer, player);
    WorldStateExpressionLogic resultLogic = buffer.read<WorldStateExpressionLogic>();

    while (resultLogic != WorldStateExpressionLogic::None)
    {
        bool secondResult = EvalRelOp(buffer, player);

        switch (resultLogic)
        {
            case WorldStateExpressionLogic::And: finalResult = finalResult && secondResult; break;
            case WorldStateExpressionLogic::Or:  finalResult = finalResult || secondResult; break;
            case WorldStateExpressionLogic::Xor: finalResult = finalResult != secondResult; break;
            default:
                break;
        }

        if (buffer.rpos() < buffer.size())
            break;

        resultLogic = buffer.read<WorldStateExpressionLogic>();
    }

    return finalResult;
}
