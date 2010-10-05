/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef TRINITY_CONDITIONMGR_H
#define TRINITY_CONDITIONMGR_H

#include "LootMgr.h"

class Player;
class Unit;
class LootTemplate;

enum ConditionType
{                                                           // value1           value2      value3
    CONDITION_NONE                  = 0,                    // 0                0           0                  always true
    CONDITION_AURA                  = 1,                    // spell_id         effindex    +referenceID       true if has aura of spell_id with effect effindex
    CONDITION_ITEM                  = 2,                    // item_id          count       +referenceID       true if has #count of item_ids
    CONDITION_ITEM_EQUIPPED         = 3,                    // item_id          0           +referenceID       true if has item_id equipped
    CONDITION_ZONEID                = 4,                    // zone_id          0           +referenceID       true if in zone_id
    CONDITION_REPUTATION_RANK       = 5,                    // faction_id       min_rank    +referenceID       true if has min_rank for faction_id
    CONDITION_TEAM                  = 6,                    // player_team      0,          +referenceID       469 - Alliance, 67 - Horde)
    CONDITION_SKILL                 = 7,                    // skill_id         skill_value +referenceID       true if has skill_value for skill_id
    CONDITION_QUESTREWARDED         = 8,                    // quest_id         0           +referenceID       true if quest_id was rewarded before
    CONDITION_QUESTTAKEN            = 9,                    // quest_id         0,          +referenceID       true while quest active
    CONDITION_UNUSED_1              = 10,                   // currently unused
    CONDITION_NO_AURA               = 11,                   // spell_id         effindex    +referenceID       true if does not have aura of spell_id with effect effindex
    CONDITION_ACTIVE_EVENT          = 12,                   // event_id         0           +referenceID       true if event is active
    CONDITION_INSTANCE_DATA         = 13,                   // entry            data        +referenceID       true if data is set in current instance
    CONDITION_QUEST_NONE            = 14,                   // quest_id         0           +referenceID       true if doesn't have quest saved
    CONDITION_CLASS                 = 15,                   // class            0           +referenceID       true if player's class is equal to class
    CONDITION_RACE                  = 16,                   // race             0           +referenceID       true if player's race is equal to race
    CONDITION_ACHIEVEMENT           = 17,                   // achievement_id   0           +referenceID       true if achievement is complete
    CONDITION_SPELL_SCRIPT_TARGET   = 18,                   // SpellScriptTargetType, TargetEntry, 0
    CONDITION_CREATURE_TARGET       = 19,                   // creature entry   0           +referenceID       true if current target is creature with value1 entry
    CONDITION_TARGET_HEALTH_BELOW_PCT = 20,                 // 0-100            0           +referenceID       true if target's health is below value1 percent, false if over or no target
    CONDITION_TARGET_RANGE          = 21,                   // minDistance      maxDist     +referenceID       true if target is closer then minDist and further then maxDist or if max is 0 then max dist is infinit
    CONDITION_MAPID                 = 22,                   // map_id           0           +referenceID       true if in map_id
    CONDITION_AREAID                = 23,                   // area_id          0           +referenceID       true if in area_id
    CONDITION_ITEM_TARGET           = 24,                   // ItemRequiredTargetType,  TargetEntry,    0
    CONDITION_SPELL                 = 25,                   // spell_id         0           +referenceID       true if knows spell
    CONDITION_NOITEM                = 26,                   // item_id          bank        +referenceID       true if player does not have any of the item (if 'bank' is set it searches in bank slots too)
    CONDITION_LEVEL                 = 27,                   // level            opt         +referenceID       true if player's level is equal to param1 (param2 can modify the statement)
    CONDITION_MAX                   = 28                    // MAX
};

enum LevelConditionType
{
    LVL_COND_EQ = 0,
    LVL_COND_HIGH = 1,
    LVL_COND_LOW = 2,
    LVL_COND_HIGH_EQ = 3,
    LVL_COND_LOW_EQ = 4,
    LVL_COND_MAX = 5,
};

enum ConditionSourceType
{
    CONDITION_SOURCE_TYPE_NONE                           = 0,//DONE
    CONDITION_SOURCE_TYPE_CREATURE_LOOT_TEMPLATE         = 1,//DONE
    CONDITION_SOURCE_TYPE_DISENCHANT_LOOT_TEMPLATE       = 2,//DONE
    CONDITION_SOURCE_TYPE_FISHING_LOOT_TEMPLATE          = 3,//DONE
    CONDITION_SOURCE_TYPE_GAMEOBJECT_LOOT_TEMPLATE       = 4,//DONE
    CONDITION_SOURCE_TYPE_ITEM_LOOT_TEMPLATE             = 5,//DONE
    CONDITION_SOURCE_TYPE_MAIL_LOOT_TEMPLATE             = 6,//DONE
    CONDITION_SOURCE_TYPE_MILLING_LOOT_TEMPLATE          = 7,//DONE
    CONDITION_SOURCE_TYPE_PICKPOCKETING_LOOT_TEMPLATE    = 8,//DONE
    CONDITION_SOURCE_TYPE_PROSPECTING_LOOT_TEMPLATE      = 9,//DONE
    CONDITION_SOURCE_TYPE_REFERENCE_LOOT_TEMPLATE        = 10,//DONE
    CONDITION_SOURCE_TYPE_SKINNING_LOOT_TEMPLATE         = 11,//DONE
    CONDITION_SOURCE_TYPE_SPELL_LOOT_TEMPLATE            = 12,//DONE
    CONDITION_SOURCE_TYPE_SPELL_SCRIPT_TARGET            = 13,//DONE
    CONDITION_SOURCE_TYPE_GOSSIP_MENU                    = 14,//DONE
    CONDITION_SOURCE_TYPE_GOSSIP_MENU_OPTION             = 15,//DONE
    CONDITION_SOURCE_TYPE_CREATURE_TEMPLATE_VEHICLE      = 16,//DONE
    CONDITION_SOURCE_TYPE_SPELL                          = 17,//DONE
    CONDITION_SOURCE_TYPE_ITEM_REQUIRED_TARGET           = 18,//DONE
    CONDITION_SOURCE_TYPE_QUEST_ACCEPT                   = 19,//DONE
    CONDITION_SOURCE_TYPE_QUEST_SHOW_MARK                = 20,//DONE
    CONDITION_SOURCE_TYPE_MAX                            = 21//MAX
};

struct Condition
{
    ConditionSourceType     mSourceType;        //SourceTypeOrReferenceId
    uint32                  mSourceGroup;
    uint32                  mSourceEntry;
    uint32                  mElseGroup;
    ConditionType           mConditionType;     //ConditionTypeOrReference
    uint32                  mConditionValue1;
    uint32                  mConditionValue2;
    uint32                  mConditionValue3;
    uint32                  ErrorTextd;
    uint32                  mReferenceId;
    uint32                  mScriptId;

    Condition()
    {
        mSourceType         = CONDITION_SOURCE_TYPE_NONE;
        mSourceGroup        = 0;
        mSourceEntry        = 0;
        mElseGroup          = 0;
        mConditionType      = CONDITION_NONE;
        mConditionValue1    = 0;
        mConditionValue2    = 0;
        mConditionValue3    = 0;
        mReferenceId        = 0;
        ErrorTextd          = 0;
        mScriptId           = 0;
    }

    bool Meets(Player * player, Unit* invoker = NULL);
    bool isLoaded() { return mConditionType > CONDITION_NONE || mReferenceId; }
};

typedef std::list<Condition*> ConditionList;
typedef std::map<uint32, ConditionList > ConditionTypeMap;
typedef std::map<ConditionSourceType, ConditionTypeMap > ConditionMap;//used for all conditions, except references

typedef std::map<uint32, ConditionList > ConditionReferenceMap;//only used for references

class ConditionMgr
{
    friend class ACE_Singleton<ConditionMgr, ACE_Null_Mutex>;
    ConditionMgr();
    ~ConditionMgr();

    public:

        void LoadConditions(bool isReload = false);
        bool isConditionTypeValid(Condition* cond);
        ConditionList GetConditionReferences(uint32 refId);

        bool IsPlayerMeetToConditions(Player* player, ConditionList conditions, Unit* invoker = NULL);
        ConditionList GetConditionsForNotGroupedEntry(ConditionSourceType sType, uint32 uEntry);

    protected:

        ConditionMap            m_ConditionMap;
        ConditionReferenceMap   m_ConditionReferenceMap;

    private:

        bool isSourceTypeValid(Condition* cond);
        bool addToLootTemplate(Condition* cond, LootTemplate* loot);
        bool addToGossipMenus(Condition* cond);
        bool addToGossipMenuItems(Condition* cond);
        bool IsPlayerMeetToConditionList(Player* player,const ConditionList& conditions, Unit* invoker = NULL);

        bool isGroupable(ConditionSourceType sourceType)
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
                    sourceType == CONDITION_SOURCE_TYPE_GOSSIP_MENU_OPTION);
        }

        void Clean(); // free up resources
        std::list<Condition*> m_AllocatedMemory; // some garbage collection :)
};

#define sConditionMgr (*ACE_Singleton<ConditionMgr, ACE_Null_Mutex>::instance())

#endif
