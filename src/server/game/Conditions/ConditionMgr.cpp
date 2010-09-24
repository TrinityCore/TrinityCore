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



#include "Player.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "GameEventMgr.h"
#include "ObjectMgr.h"
#include "ProgressBar.h"
#include "InstanceScript.h"
#include "ConditionMgr.h"
#include "ScriptMgr.h"

// Checks if player meets the condition
// Can have CONDITION_SOURCE_TYPE_NONE && !mReferenceId if called from a special event (ie: eventAI)
bool Condition::Meets(Player * player, Unit* invoker)
{
    if (!player)
    {
        sLog.outDebug("Condition player not found");
        return false;                                       // player not present, return false
    }
    uint32 refId = mConditionValue3;//value 3 can be a 'quick' reference
    bool condMeets = false;
    bool sendErrorMsg = false;
    switch (mConditionType)
    {
        case CONDITION_NONE:
            condMeets = true;                                    // empty condition, always met
            break;
        case CONDITION_AURA:
            condMeets = player->HasAuraEffect(mConditionValue1, mConditionValue2);
            break;
        case CONDITION_ITEM:
            condMeets = player->HasItemCount(mConditionValue1, mConditionValue2);
            break;
        case CONDITION_ITEM_EQUIPPED:
            condMeets = player->HasItemOrGemWithIdEquipped(mConditionValue1,1);
            break;
        case CONDITION_ZONEID:
            condMeets = player->GetZoneId() == mConditionValue1;
            break;
        case CONDITION_REPUTATION_RANK:
        {
            FactionEntry const* faction = sFactionStore.LookupEntry(mConditionValue1);
            condMeets = faction && uint32(player->GetReputationMgr().GetRank(faction)) >= mConditionValue2;
            break;
        }
        case CONDITION_ACHIEVEMENT:
        {
            AchievementEntry const* achievement = GetAchievementStore()->LookupEntry(mConditionValue1);
            condMeets = player->GetAchievementMgr().HasAchieved(achievement);
            break;
        }
        case CONDITION_TEAM:
            condMeets = player->GetTeam() == mConditionValue1;
            break;
        case CONDITION_CLASS:
            condMeets = player->getClass() == mConditionValue1;
            break;
        case CONDITION_RACE:
            condMeets = player->getRace() == mConditionValue1;
            break;
        case CONDITION_SKILL:
            condMeets = player->HasSkill(mConditionValue1) && player->GetBaseSkillValue(mConditionValue1) >= mConditionValue2;
            break;
        case CONDITION_QUESTREWARDED:
            condMeets = player->GetQuestRewardStatus(mConditionValue1);
            break;
        case CONDITION_QUESTTAKEN:
        {
            QuestStatus status = player->GetQuestStatus(mConditionValue1);
            condMeets = (status == QUEST_STATUS_INCOMPLETE);
            break;
        }
        case CONDITION_QUEST_NONE:
        {
            QuestStatus status = player->GetQuestStatus(mConditionValue1);
            condMeets = (status == QUEST_STATUS_NONE);
            break;
        }
        case CONDITION_AD_COMMISSION_AURA:
        {
            Unit::AuraApplicationMap const& auras = player->GetAppliedAuras();
            for (Unit::AuraApplicationMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
                if ((itr->second->GetBase()->GetSpellProto()->Attributes & 0x1000010) && itr->second->GetBase()->GetSpellProto()->SpellVisual[0] == 3580)
                {
                    condMeets = true;
                    break;
                }
            condMeets = false;
            break;
        }
        case CONDITION_NO_AURA:
            condMeets = !player->HasAuraEffect(mConditionValue1, mConditionValue2);
            break;
        case CONDITION_ACTIVE_EVENT:
            condMeets = sGameEventMgr.IsActiveEvent(mConditionValue1);
            break;
        case CONDITION_INSTANCE_DATA:
        {
            Map *map = player->GetMap();
            if (map && map->IsDungeon() && ((InstanceMap*)map)->GetInstanceScript())
                condMeets = ((InstanceMap*)map)->GetInstanceScript()->GetData(mConditionValue1) == mConditionValue2;
            break;
        }
        case CONDITION_SPELL_SCRIPT_TARGET:
            condMeets = true;//spell target condition is handled in spellsystem, here it is always true
            refId = 0;//cant have references! use CONDITION_SOURCE_TYPE_SPELL for it
            break;
        case CONDITION_CREATURE_TARGET:
        {
            Unit* target = player->GetSelectedUnit();
            if (target)
                if (Creature* cTarget = target->ToCreature())
                    if (cTarget->GetEntry() == mConditionValue1)
                        condMeets = true;
            break;
        }
        case CONDITION_TARGET_HEALTH_BELOW_PCT:
        {
            Unit* target = player->GetSelectedUnit();
            if (target)
                condMeets = !target->HealthAbovePct(mConditionValue1);
            break;
        }
        case CONDITION_TARGET_RANGE:
        {
            if (Unit* target = player->GetSelectedUnit())
                if (player->GetDistance(target) >= mConditionValue1 && (!mConditionValue2 || player->GetDistance(target) <= mConditionValue2))
                    condMeets = true;
            break;
        }
        case CONDITION_MAPID:
            condMeets = player->GetMapId() == mConditionValue1;
            break;
        case CONDITION_AREAID:
            condMeets = player->GetAreaId() == mConditionValue1;
            break;
        case CONDITION_ITEM_TARGET:
        {
            condMeets = true;//handled in Item::IsTargetValidForItemUse
            refId = 0;//cant have references for now
            break;
        }
        case CONDITION_SPELL:
            condMeets = player->HasSpell(mConditionValue1);
            break;
        default:
            condMeets = false;
            refId = 0;
            break;
    }
    switch (mSourceType)
    {
        case CONDITION_SOURCE_TYPE_SPELL_SCRIPT_TARGET:
        case CONDITION_SOURCE_TYPE_SPELL:
            sendErrorMsg = true;
            break;
        default:
            break;
    }

    bool refMeets = false;
    if (condMeets && refId)//only have to check references if 'this' is met
    {
        ConditionList ref = sConditionMgr.GetConditionReferences(refId);
        refMeets = sConditionMgr.IsPlayerMeetToConditions(player, ref);
    }
    else
        refMeets = true;

    if (sendErrorMsg && ErrorTextd && (!condMeets || !refMeets))//send special error from DB
        player->m_ConditionErrorMsgId = ErrorTextd;

    bool script = sScriptMgr.OnConditionCheck(this, player, invoker); // Returns true by default.
    return condMeets && refMeets && script;
}

ConditionMgr::ConditionMgr()
{
}

ConditionMgr::~ConditionMgr()
{
    Clean();
}

ConditionList ConditionMgr::GetConditionReferences(uint32 refId)
{
    ConditionList conditions;
    ConditionReferenceMap::const_iterator ref = m_ConditionReferenceMap.find(refId);
    if (ref != m_ConditionReferenceMap.end())
        conditions = (*ref).second;
    return conditions;
}

bool ConditionMgr::IsPlayerMeetToConditionList(Player* player,const ConditionList& conditions, Unit* invoker)
{
    std::map<uint32, bool>ElseGroupMap;
    for (ConditionList::const_iterator i = conditions.begin(); i != conditions.end(); ++i)
    {
        sLog.outDebug("ConditionMgr::IsPlayerMeetToConditionList condType: %u val1: %u",(*i)->mConditionType,(*i)->mConditionValue1);
        if ((*i)->isLoaded())
        {
            std::map<uint32, bool>::const_iterator itr = ElseGroupMap.find((*i)->mElseGroup);
            if (itr == ElseGroupMap.end())
                ElseGroupMap[(*i)->mElseGroup] = true;
            else if (!(*itr).second)
                continue;

            if ((*i)->mReferenceId)//handle reference
            {
                ConditionReferenceMap::const_iterator ref = m_ConditionReferenceMap.find((*i)->mReferenceId);
                if (ref != m_ConditionReferenceMap.end())
                {
                    if(!IsPlayerMeetToConditionList(player, (*ref).second, invoker))
                        ElseGroupMap[(*i)->mElseGroup] = false;
                }
                else
                {
                    sLog.outDebug("IsPlayerMeetToConditionList: Reference template -%u not found",
                        (*i)->mReferenceId);//checked at loading, should never happen
                }

            }
            else //handle normal condition
            {
                if (!(*i)->Meets(player, invoker))
                    ElseGroupMap[(*i)->mElseGroup] = false;
            }
        }
    }
    for (std::map<uint32, bool>::const_iterator i = ElseGroupMap.begin(); i != ElseGroupMap.end(); ++i)
        if (i->second)
            return true;

    return false;
}

bool ConditionMgr::IsPlayerMeetToConditions(Player* player, ConditionList conditions, Unit* invoker)
{
    if (conditions.empty())
        return true;

    if(player)
        player->m_ConditionErrorMsgId = 0;

    sLog.outDebug("ConditionMgr::IsPlayerMeetToConditions");
    bool result = IsPlayerMeetToConditionList(player, conditions, invoker);

    if (player && player->m_ConditionErrorMsgId && player->GetSession() && !result)
            player->GetSession()->SendNotification(player->m_ConditionErrorMsgId);//m_ConditionErrorMsgId is set only if a condition was not met

    return result;
}

ConditionList ConditionMgr::GetConditionsForNotGroupedEntry(ConditionSourceType sType, uint32 uEntry)
{
    ConditionList spellCond;
    if (sType > CONDITION_SOURCE_TYPE_NONE && sType < CONDITION_SOURCE_TYPE_MAX)
    {
        ConditionMap::const_iterator itr = m_ConditionMap.find(sType);
        if (itr != m_ConditionMap.end())
        {
            ConditionTypeMap::const_iterator i = (*itr).second.find(uEntry);
            if (i != (*itr).second.end())
            {
                spellCond = (*i).second;
                sLog.outDebug("GetConditionsForNotGroupedEntry: found conditions for type %u and entry %u", uint32(sType), uEntry);
            }
        }
    }
    return spellCond;
}

void ConditionMgr::LoadConditions(bool isReload)
{
    Clean();

    //must clear all custom handled cases (groupped types) before reload
    if (isReload)
    {
        sLog.outString("Reseting Loot Conditions...");
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

        sLog.outString("Re-Loading `gossip_menu` Table for Conditions!");
        sObjectMgr.LoadGossipMenu();

        sLog.outString("Re-Loading `gossip_menu_option` Table for Conditions!");
        sObjectMgr.LoadGossipMenuItems();
    }

    uint32 count = 0;
    QueryResult result = WorldDatabase.Query("SELECT SourceTypeOrReferenceId, SourceGroup, SourceEntry, ElseGroup, ConditionTypeOrReference, ConditionValue1, ConditionValue2, ConditionValue3, ErrorTextId, ScriptName FROM conditions");

    if (!result)
    {
        barGoLink bar(1);

        bar.step();

        sLog.outString();
        sLog.outErrorDb(">> Loaded `conditions`, table is empty!");
        return;
    }

    barGoLink bar(result->GetRowCount());

    do
    {
        bar.step();

        Field *fields = result->Fetch();

        Condition* cond = new Condition();
        int32 iSourceTypeOrReferenceId   = fields[0].GetInt32();
        cond->mSourceGroup               = fields[1].GetUInt32();
        cond->mSourceEntry               = fields[2].GetUInt32();
        cond->mElseGroup                 = fields[3].GetUInt32();
        int32 iConditionTypeOrReference  = fields[4].GetInt32();
        cond->mConditionValue1           = fields[5].GetUInt32();
        cond->mConditionValue2           = fields[6].GetUInt32();
        cond->mConditionValue3           = fields[7].GetUInt32();
        cond->ErrorTextd                 = fields[8].GetUInt32();
        cond->mScriptId                  = sObjectMgr.GetScriptId(fields[9].GetCString());

        if (iConditionTypeOrReference >= 0)
            cond->mConditionType = ConditionType(iConditionTypeOrReference);

        if (iConditionTypeOrReference < 0)//it has a reference
        {
            if (iConditionTypeOrReference == iSourceTypeOrReferenceId)//self referencing, skip
            {
                sLog.outErrorDb("Condition reference %i is referencing self, skipped", iSourceTypeOrReferenceId);
                delete cond;
                continue;
            }
            cond->mReferenceId = uint32(abs(iConditionTypeOrReference));

            const char* rowType = "reference template";
            if (iSourceTypeOrReferenceId >= 0)
                rowType = "reference";
            //check for useless data
            if (cond->mConditionValue1)
                sLog.outErrorDb("Condition %s %i has useless data in value1 (%u)!", rowType, iSourceTypeOrReferenceId, cond->mConditionValue1);
            if (cond->mConditionValue2)
                sLog.outErrorDb("Condition %s %i has useless data in value2 (%u)!", rowType, iSourceTypeOrReferenceId, cond->mConditionValue2);
            if (cond->mConditionValue3)
                sLog.outErrorDb("Condition %s %i has useless data in value3 (%u)!", rowType, iSourceTypeOrReferenceId, cond->mConditionValue3);
            if (cond->mSourceGroup && iSourceTypeOrReferenceId < 0)
                sLog.outErrorDb("Condition %s %i has useless data in SourceGroup (%u)!", rowType, iSourceTypeOrReferenceId, cond->mSourceGroup);
            if (cond->mSourceEntry && iSourceTypeOrReferenceId < 0)
                sLog.outErrorDb("Condition %s %i has useless data in SourceEntry (%u)!", rowType, iSourceTypeOrReferenceId, cond->mSourceEntry);
        }
        else if (!isConditionTypeValid(cond))//doesn't have reference, validate ConditionType
        {
            delete cond;
            continue;
        }

        if (iSourceTypeOrReferenceId < 0)//it is a reference template
        {
            uint32 uRefId = abs(iSourceTypeOrReferenceId);
            if (m_ConditionReferenceMap.find(uRefId) == m_ConditionReferenceMap.end())//make sure we have a list for our conditions, based on reference id
            {
                ConditionList mCondList;
                m_ConditionReferenceMap[uRefId] = mCondList;
            }
            m_ConditionReferenceMap[uRefId].push_back(cond);//add to reference storage
            count++;
            continue;
        }//end of reference templates

        cond->mSourceType = ConditionSourceType(iSourceTypeOrReferenceId);

        //if not a reference and SourceType is invalid, skip
        if (iConditionTypeOrReference >= 0 && !isSourceTypeValid(cond))
        {
            delete cond;
            continue;
        }

        //Grouping is only allowed for some types (loot templates, gossip menus, gossip items)
        if (cond->mSourceGroup && !isGroupable(cond->mSourceType))
        {
            sLog.outErrorDb("Condition type %u has not allowed grouping %u!", uint32(cond->mSourceType), cond->mSourceGroup);
            delete cond;
            continue;
        }
        else if (cond->mSourceGroup)
        {
            bool bIsDone = false;
            //handle grouped conditions
            switch (cond->mSourceType)
            {
                case CONDITION_SOURCE_TYPE_CREATURE_LOOT_TEMPLATE:
                    bIsDone = addToLootTemplate(cond, LootTemplates_Creature.GetLootForConditionFill(cond->mSourceGroup));
                    break;
                case CONDITION_SOURCE_TYPE_DISENCHANT_LOOT_TEMPLATE:
                    bIsDone = addToLootTemplate(cond, LootTemplates_Disenchant.GetLootForConditionFill(cond->mSourceGroup));
                    break;
                case CONDITION_SOURCE_TYPE_FISHING_LOOT_TEMPLATE:
                    bIsDone = addToLootTemplate(cond, LootTemplates_Fishing.GetLootForConditionFill(cond->mSourceGroup));
                    break;
                case CONDITION_SOURCE_TYPE_GAMEOBJECT_LOOT_TEMPLATE:
                    bIsDone = addToLootTemplate(cond, LootTemplates_Gameobject.GetLootForConditionFill(cond->mSourceGroup));
                    break;
                case CONDITION_SOURCE_TYPE_ITEM_LOOT_TEMPLATE:
                    bIsDone = addToLootTemplate(cond, LootTemplates_Item.GetLootForConditionFill(cond->mSourceGroup));
                    break;
                case CONDITION_SOURCE_TYPE_MAIL_LOOT_TEMPLATE:
                    bIsDone = addToLootTemplate(cond, LootTemplates_Mail.GetLootForConditionFill(cond->mSourceGroup));
                    break;
                case CONDITION_SOURCE_TYPE_MILLING_LOOT_TEMPLATE:
                    bIsDone = addToLootTemplate(cond, LootTemplates_Milling.GetLootForConditionFill(cond->mSourceGroup));
                    break;
                case CONDITION_SOURCE_TYPE_PICKPOCKETING_LOOT_TEMPLATE:
                    bIsDone = addToLootTemplate(cond, LootTemplates_Pickpocketing.GetLootForConditionFill(cond->mSourceGroup));
                    break;
                case CONDITION_SOURCE_TYPE_PROSPECTING_LOOT_TEMPLATE:
                    bIsDone = addToLootTemplate(cond, LootTemplates_Prospecting.GetLootForConditionFill(cond->mSourceGroup));
                    break;
                case CONDITION_SOURCE_TYPE_REFERENCE_LOOT_TEMPLATE:
                    bIsDone = addToLootTemplate(cond, LootTemplates_Reference.GetLootForConditionFill(cond->mSourceGroup));
                    break;
                case CONDITION_SOURCE_TYPE_SKINNING_LOOT_TEMPLATE:
                    bIsDone = addToLootTemplate(cond, LootTemplates_Skinning.GetLootForConditionFill(cond->mSourceGroup));
                    break;
                case CONDITION_SOURCE_TYPE_SPELL_LOOT_TEMPLATE:
                    bIsDone = addToLootTemplate(cond, LootTemplates_Spell.GetLootForConditionFill(cond->mSourceGroup));
                    break;
                case CONDITION_SOURCE_TYPE_GOSSIP_MENU:
                    bIsDone = addToGossipMenus(cond);
                    break;
                case CONDITION_SOURCE_TYPE_GOSSIP_MENU_OPTION:
                    bIsDone = addToGossipMenuItems(cond);
                    break;
                default:
                    break;
            }

            if (!bIsDone)
            {
                sLog.outErrorDb("Not handled grouped condition, SourceGroup %u", cond->mSourceGroup);
                delete cond;
            }
            else
            {
                m_AllocatedMemory.push_back(cond);
                ++count;
            }
            continue;
        }

        //handle not grouped conditions
        //make sure we have a storage list for our SourceType
        if (m_ConditionMap.find(cond->mSourceType) == m_ConditionMap.end())
        {
            ConditionTypeMap mTypeMap;
            m_ConditionMap[cond->mSourceType] = mTypeMap;//add new empty list for SourceType
        }

        //make sure we have a condition list for our SourceType's entry
        if (m_ConditionMap[cond->mSourceType].find(cond->mSourceEntry) == m_ConditionMap[cond->mSourceType].end())
        {
            ConditionList mCondList;
            m_ConditionMap[cond->mSourceType][cond->mSourceEntry] = mCondList;
        }

        //add new Condition to storage based on Type/Entry
        m_ConditionMap[cond->mSourceType][cond->mSourceEntry].push_back(cond);
        ++count;
    }
    while (result->NextRow());

    sLog.outString();
    sLog.outString(">> Loaded %u conditions", count);
}

bool ConditionMgr::addToLootTemplate(Condition* cond, LootTemplate* loot)
{
    if (!loot)
    {
        sLog.outErrorDb("ConditionMgr: LootTemplate %u not found", cond->mSourceGroup);
        return false;
    }

    if (loot->addConditionItem(cond))
        return true;

    sLog.outErrorDb("ConditionMgr: Item %u not found in LootTemplate %u", cond->mSourceEntry, cond->mSourceGroup);
    return false;
}

bool ConditionMgr::addToGossipMenus(Condition* cond)
{
    GossipMenusMapBoundsNonConst pMenuBounds = sObjectMgr.GetGossipMenusMapBoundsNonConst(cond->mSourceGroup);

    if (pMenuBounds.first != pMenuBounds.second)
    {
        for (GossipMenusMap::iterator itr = pMenuBounds.first; itr != pMenuBounds.second; ++itr)
        {
            if ((*itr).second.entry == cond->mSourceGroup && (*itr).second.text_id == cond->mSourceEntry)
            {
                (*itr).second.conditions.push_back(cond);
                return true;
            }
        }
    }

    sLog.outErrorDb("addToGossipMenus: GossipMenu %u not found", cond->mSourceGroup);
    return false;
}

bool ConditionMgr::addToGossipMenuItems(Condition* cond)
{
    GossipMenuItemsMapBoundsNonConst pMenuItemBounds = sObjectMgr.GetGossipMenuItemsMapBoundsNonConst(cond->mSourceGroup);
    if (pMenuItemBounds.first != pMenuItemBounds.second)
    {
        for (GossipMenuItemsMap::iterator itr = pMenuItemBounds.first; itr != pMenuItemBounds.second; ++itr)
        {
            if ((*itr).second.menu_id == cond->mSourceGroup && (*itr).second.id == cond->mSourceEntry)
            {
                (*itr).second.conditions.push_back(cond);
                return true;
            }
        }
    }

    sLog.outErrorDb("addToGossipMenuItems: GossipMenuId %u Item %u not found", cond->mSourceGroup, cond->mSourceEntry);
    return false;
}

bool ConditionMgr::isSourceTypeValid(Condition* cond)
{
    if (cond->mSourceType == CONDITION_SOURCE_TYPE_NONE || cond->mSourceType >= CONDITION_SOURCE_TYPE_MAX)
    {
        sLog.outErrorDb("Invalid ConditionSourceType %u in `condition` table, ignoring.", uint32(cond->mSourceType));
        return false;
    }

    switch (cond->mSourceType)
    {
        case CONDITION_SOURCE_TYPE_CREATURE_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Creature.HaveLootFor(cond->mSourceGroup))
            {
                sLog.outErrorDb("SourceGroup %u in `condition` table, does not exist in `creature_loot_template`, ignoring.", cond->mSourceGroup);
                return false;
            }

            LootTemplate* loot = LootTemplates_Creature.GetLootForConditionFill(cond->mSourceGroup);
            ItemPrototype const* pItemProto = sItemStorage.LookupEntry<ItemPrototype>(cond->mSourceEntry);
            if (!pItemProto && !loot->isReference(cond->mSourceEntry))
            {
                sLog.outErrorDb("SourceType %u, SourceEntry %u in `condition` table, does not exist in `item_template`, ignoring.", cond->mSourceType, cond->mSourceEntry);
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_DISENCHANT_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Disenchant.HaveLootFor(cond->mSourceGroup))
            {
                sLog.outErrorDb("SourceGroup %u in `condition` table, does not exist in `disenchant_loot_template`, ignoring.", cond->mSourceGroup);
                return false;
            }

            LootTemplate* loot = LootTemplates_Disenchant.GetLootForConditionFill(cond->mSourceGroup);
            ItemPrototype const* pItemProto = sItemStorage.LookupEntry<ItemPrototype>(cond->mSourceEntry);
            if (!pItemProto && !loot->isReference(cond->mSourceEntry))
            {
                sLog.outErrorDb("SourceType %u, SourceEntry %u in `condition` table, does not exist in `item_template`, ignoring.", cond->mSourceType, cond->mSourceEntry);
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_FISHING_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Fishing.HaveLootFor(cond->mSourceGroup))
            {
                sLog.outErrorDb("SourceGroup %u in `condition` table, does not exist in `fishing_loot_template`, ignoring.", cond->mSourceGroup);
                return false;
            }

            LootTemplate* loot = LootTemplates_Fishing.GetLootForConditionFill(cond->mSourceGroup);
            ItemPrototype const* pItemProto = sItemStorage.LookupEntry<ItemPrototype>(cond->mSourceEntry);
            if (!pItemProto && !loot->isReference(cond->mSourceEntry))
            {
                sLog.outErrorDb("SourceType %u, SourceEntry %u in `condition` table, does not exist in `item_template`, ignoring.", cond->mSourceType, cond->mSourceEntry);
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_GAMEOBJECT_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Gameobject.HaveLootFor(cond->mSourceGroup))
            {
                sLog.outErrorDb("SourceGroup %u in `condition` table, does not exist in `gameobject_loot_template`, ignoring.", cond->mSourceGroup);
                return false;
            }

            LootTemplate* loot = LootTemplates_Gameobject.GetLootForConditionFill(cond->mSourceGroup);
            ItemPrototype const* pItemProto = sItemStorage.LookupEntry<ItemPrototype>(cond->mSourceEntry);
            if (!pItemProto && !loot->isReference(cond->mSourceEntry))
            {
                sLog.outErrorDb("SourceType %u, SourceEntry %u in `condition` table, does not exist in `item_template`, ignoring.", cond->mSourceType, cond->mSourceEntry);
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_ITEM_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Item.HaveLootFor(cond->mSourceGroup))
            {
                sLog.outErrorDb("SourceGroup %u in `condition` table, does not exist in `item_loot_template`, ignoring.", cond->mSourceGroup);
                return false;
            }

            LootTemplate* loot = LootTemplates_Item.GetLootForConditionFill(cond->mSourceGroup);
            ItemPrototype const* pItemProto = sItemStorage.LookupEntry<ItemPrototype>(cond->mSourceEntry);
            if (!pItemProto && !loot->isReference(cond->mSourceEntry))
            {
                sLog.outErrorDb("SourceType %u, SourceEntry %u in `condition` table, does not exist in `item_template`, ignoring.", cond->mSourceType, cond->mSourceEntry);
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_MAIL_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Mail.HaveLootFor(cond->mSourceGroup))
            {
                sLog.outErrorDb("SourceGroup %u in `condition` table, does not exist in `mail_loot_template`, ignoring.", cond->mSourceGroup);
                return false;
            }

            LootTemplate* loot = LootTemplates_Mail.GetLootForConditionFill(cond->mSourceGroup);
            ItemPrototype const* pItemProto = sItemStorage.LookupEntry<ItemPrototype>(cond->mSourceEntry);
            if (!pItemProto && !loot->isReference(cond->mSourceEntry))
            {
                sLog.outErrorDb("SourceType %u, SourceEntry %u in `condition` table, does not exist in `item_template`, ignoring.", cond->mSourceType, cond->mSourceEntry);
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_MILLING_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Milling.HaveLootFor(cond->mSourceGroup))
            {
                sLog.outErrorDb("SourceGroup %u in `condition` table, does not exist in `milling_loot_template`, ignoring.", cond->mSourceGroup);
                return false;
            }

            LootTemplate* loot = LootTemplates_Milling.GetLootForConditionFill(cond->mSourceGroup);
            ItemPrototype const* pItemProto = sItemStorage.LookupEntry<ItemPrototype>(cond->mSourceEntry);
            if (!pItemProto && !loot->isReference(cond->mSourceEntry))
            {
                sLog.outErrorDb("SourceType %u, SourceEntry %u in `condition` table, does not exist in `item_template`, ignoring.", cond->mSourceType, cond->mSourceEntry);
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_PICKPOCKETING_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Pickpocketing.HaveLootFor(cond->mSourceGroup))
            {
                sLog.outErrorDb("SourceGroup %u in `condition` table, does not exist in `pickpocketing_loot_template`, ignoring.", cond->mSourceGroup);
                return false;
            }

            LootTemplate* loot = LootTemplates_Pickpocketing.GetLootForConditionFill(cond->mSourceGroup);
            ItemPrototype const* pItemProto = sItemStorage.LookupEntry<ItemPrototype>(cond->mSourceEntry);
            if (!pItemProto && !loot->isReference(cond->mSourceEntry))
            {
                sLog.outErrorDb("SourceType %u, SourceEntry %u in `condition` table, does not exist in `item_template`, ignoring.", cond->mSourceType, cond->mSourceEntry);
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_PROSPECTING_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Prospecting.HaveLootFor(cond->mSourceGroup))
            {
                sLog.outErrorDb("SourceGroup %u in `condition` table, does not exist in `prospecting_loot_template`, ignoring.", cond->mSourceGroup);
                return false;
            }

            LootTemplate* loot = LootTemplates_Prospecting.GetLootForConditionFill(cond->mSourceGroup);
            ItemPrototype const* pItemProto = sItemStorage.LookupEntry<ItemPrototype>(cond->mSourceEntry);
            if (!pItemProto && !loot->isReference(cond->mSourceEntry))
            {
                sLog.outErrorDb("SourceType %u, SourceEntry %u in `condition` table, does not exist in `item_template`, ignoring.", cond->mSourceType, cond->mSourceEntry);
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_REFERENCE_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Reference.HaveLootFor(cond->mSourceGroup))
            {
                sLog.outErrorDb("SourceGroup %u in `condition` table, does not exist in `reference_loot_template`, ignoring.", cond->mSourceGroup);
                return false;
            }

            LootTemplate* loot = LootTemplates_Reference.GetLootForConditionFill(cond->mSourceGroup);
            ItemPrototype const* pItemProto = sItemStorage.LookupEntry<ItemPrototype>(cond->mSourceEntry);
            if (!pItemProto && !loot->isReference(cond->mSourceEntry))
            {
                sLog.outErrorDb("SourceType %u, SourceEntry %u in `condition` table, does not exist in `item_template`, ignoring.", cond->mSourceType, cond->mSourceEntry);
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_SKINNING_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Skinning.HaveLootFor(cond->mSourceGroup))
            {
                sLog.outErrorDb("SourceGroup %u in `condition` table, does not exist in `skinning_loot_template`, ignoring.", cond->mSourceGroup);
                return false;
            }

            LootTemplate* loot = LootTemplates_Skinning.GetLootForConditionFill(cond->mSourceGroup);
            ItemPrototype const* pItemProto = sItemStorage.LookupEntry<ItemPrototype>(cond->mSourceEntry);
            if (!pItemProto && !loot->isReference(cond->mSourceEntry))
            {
                sLog.outErrorDb("SourceType %u, SourceEntry %u in `condition` table, does not exist in `item_template`, ignoring.", cond->mSourceType, cond->mSourceEntry);
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_SPELL_LOOT_TEMPLATE:
        {
            if (!LootTemplates_Spell.HaveLootFor(cond->mSourceGroup))
            {
                sLog.outErrorDb("SourceGroup %u in `condition` table, does not exist in `spell_loot_template`, ignoring.", cond->mSourceGroup);
                return false;
            }

            LootTemplate* loot = LootTemplates_Spell.GetLootForConditionFill(cond->mSourceGroup);
            ItemPrototype const* pItemProto = sItemStorage.LookupEntry<ItemPrototype>(cond->mSourceEntry);
            if (!pItemProto && !loot->isReference(cond->mSourceEntry))
            {
                sLog.outErrorDb("SourceType %u, SourceEntry %u in `condition` table, does not exist in `item_template`, ignoring.", cond->mSourceType, cond->mSourceEntry);
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_SPELL_SCRIPT_TARGET:
        {
            if (cond->mConditionType != CONDITION_SPELL_SCRIPT_TARGET)
            {
                sLog.outErrorDb("SourceEntry %u in `condition` table, has ConditionType %u. Only CONDITION_SPELL_SCRIPT_TARGET(18) is valid for CONDITION_SOURCE_TYPE_SPELL_SCRIPT_TARGET(14), ignoring.", cond->mSourceEntry, uint32(cond->mConditionType));
                return false;
            }

            SpellEntry const* spellProto = sSpellStore.LookupEntry(cond->mSourceEntry);
            if (!spellProto)
            {
                sLog.outErrorDb("SourceEntry %u in `condition` table, does not exist in `spell.dbc`, ignoring.", cond->mSourceEntry);
                return false;
            }

            bool targetfound = false;
            for (uint8 i = 0; i < 3; ++i)
            {
                if (spellProto->EffectImplicitTargetA[i] == TARGET_UNIT_AREA_ENTRY_SRC ||
                    spellProto->EffectImplicitTargetB[i] == TARGET_UNIT_AREA_ENTRY_SRC ||
                    spellProto->EffectImplicitTargetA[i] == TARGET_UNIT_AREA_ENTRY_DST ||
                    spellProto->EffectImplicitTargetB[i] == TARGET_UNIT_AREA_ENTRY_DST ||
                    spellProto->EffectImplicitTargetA[i] == TARGET_UNIT_NEARBY_ENTRY ||
                    spellProto->EffectImplicitTargetB[i] == TARGET_UNIT_NEARBY_ENTRY ||
                    spellProto->EffectImplicitTargetA[i] == TARGET_GAMEOBJECT_NEARBY_ENTRY ||
                    spellProto->EffectImplicitTargetB[i] == TARGET_GAMEOBJECT_NEARBY_ENTRY ||
                    spellProto->EffectImplicitTargetA[i] == TARGET_GAMEOBJECT_AREA_SRC ||
                    spellProto->EffectImplicitTargetB[i] == TARGET_GAMEOBJECT_AREA_SRC ||
                    spellProto->EffectImplicitTargetA[i] == TARGET_GAMEOBJECT_AREA_DST ||
                    spellProto->EffectImplicitTargetB[i] == TARGET_GAMEOBJECT_AREA_DST ||
                    spellProto->EffectImplicitTargetA[i] == TARGET_DST_NEARBY_ENTRY ||
                    spellProto->EffectImplicitTargetB[i] == TARGET_DST_NEARBY_ENTRY ||
                    spellProto->EffectImplicitTargetA[i] == TARGET_UNIT_CONE_ENTRY ||
                    spellProto->EffectImplicitTargetB[i] == TARGET_UNIT_CONE_ENTRY)
                {
                    targetfound = true;
                    break;
                }
            }
            if (!targetfound)
            {
                sLog.outErrorDb("SourceEntry %u in `condition` table does not have any implicit target TARGET_UNIT_NEARBY_ENTRY(38) or TARGET_DST_NEARBY_ENTRY (46)"
                                ",TARGET_UNIT_AREA_ENTRY_SRC(7), TARGET_UNIT_AREA_ENTRY_DST(8), TARGET_UNIT_CONE_ENTRY(60), TARGET_GAMEOBJECT_NEARBY_ENTRY(40)"
                                "TARGET_GAMEOBJECT_AREA_SRC(51), TARGET_GAMEOBJECT_AREA_DST(52)", cond->mSourceEntry);
                return false;
            }
            if ((cond->mConditionValue1 == SPELL_TARGET_TYPE_DEAD) && !IsAllowingDeadTargetSpell(spellProto))
            {
                sLog.outErrorDb("SourceEntry %u in `condition` table does have SPELL_TARGET_TYPE_DEAD specified but spell does not have SPELL_ATTR_EX2_ALLOW_DEAD_TARGET", cond->mSourceEntry);
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_CREATURE_TEMPLATE_VEHICLE:
        {
            if (!sCreatureStorage.LookupEntry<CreatureInfo>(cond->mSourceEntry))
            {
                sLog.outErrorDb("SourceEntry %u in `condition` table, does not exist in `creature_template`, ignoring.", cond->mSourceEntry);
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_SPELL:
        {
            SpellEntry const* spellProto = sSpellStore.LookupEntry(cond->mSourceEntry);
            if (!spellProto)
            {
                sLog.outErrorDb("SourceEntry %u in `condition` table, does not exist in `spell.dbc`, ignoring.", cond->mSourceEntry);
                return false;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_ITEM_REQUIRED_TARGET:
        {
            if (cond->mConditionType != CONDITION_ITEM_TARGET)
            {
                sLog.outErrorDb("SourceEntry %u in `condition` table, has ConditionType %u. Only CONDITION_ITEM_TARGET(24) is valid for CONDITION_SOURCE_TYPE_ITEM_REQUIRED_TARGET(18), ignoring.", cond->mSourceEntry, uint32(cond->mConditionType));
                return false;
            }

            ItemPrototype const *pItemProto = sObjectMgr.GetItemPrototype(cond->mSourceEntry);
            if (!pItemProto)
            {
                sLog.outErrorDb("SourceEntry %u in `condition` table, does not exist in `item_tamplate`, ignoring.", cond->mSourceEntry);
                return false;
            }

            bool bIsItemSpellValid = false;
            for (uint8 i = 0; i < MAX_ITEM_PROTO_SPELLS; ++i)
            {
                if (SpellEntry const* pSpellInfo = sSpellStore.LookupEntry(pItemProto->Spells[i].SpellId))
                {
                    if (pItemProto->Spells[i].SpellTrigger == ITEM_SPELLTRIGGER_ON_USE ||
                        pItemProto->Spells[i].SpellTrigger == ITEM_SPELLTRIGGER_ON_NO_DELAY_USE)
                    {
                        ConditionList conditions = sConditionMgr.GetConditionsForNotGroupedEntry(CONDITION_SOURCE_TYPE_SPELL_SCRIPT_TARGET, pSpellInfo->Id);//script loading is done before item target loading
                        if (!conditions.empty())
                            break;

                        for (int j = 0; j < 3; ++j)
                        {
                            if (pSpellInfo->EffectImplicitTargetA[j] == TARGET_UNIT_TARGET_ENEMY ||
                                pSpellInfo->EffectImplicitTargetB[j] == TARGET_UNIT_TARGET_ENEMY ||
                                pSpellInfo->EffectImplicitTargetA[j] == TARGET_UNIT_TARGET_ANY ||
                                pSpellInfo->EffectImplicitTargetB[j] == TARGET_UNIT_TARGET_ANY)
                            {
                                bIsItemSpellValid = true;
                                break;
                            }
                        }

                        if (bIsItemSpellValid)
                            break;
                    }
                }
            }

            if (!bIsItemSpellValid)
            {
                sLog.outErrorDb("Conditions: CONDITION_SOURCE_TYPE_ITEM_REQUIRED_TARGET for item %u, which either doesn't have item spelltrigger or its spells don't have implicit target "
                                "TARGET_UNIT_TARGET_ENEMY(6), TARGET_UNIT_TARGET_ANY(25), or the spells are already listed in CONDITION_SOURCE_TYPE_SPELL_SCRIPT_TARGET conditions.", cond->mSourceEntry);
                break;
            }
            break;
        }
        case CONDITION_SOURCE_TYPE_QUEST_ACCEPT:
            {
                Quest const *Quest = sObjectMgr.GetQuestTemplate(cond->mSourceEntry);
                if (!Quest)
                {
                    sLog.outErrorDb("CONDITION_SOURCE_TYPE_QUEST_ACCEPT specifies non-existing quest (%u), skipped", cond->mSourceEntry);
                    return false;
                }
            }
            break;
        case CONDITION_SOURCE_TYPE_QUEST_SHOW_MARK:
            {
                Quest const *Quest = sObjectMgr.GetQuestTemplate(cond->mSourceEntry);
                if (!Quest)
                {
                    sLog.outErrorDb("CONDITION_SOURCE_TYPE_QUEST_SHOW_MARK specifies non-existing quest (%u), skipped", cond->mSourceEntry);
                    return false;
                }
            }
            break;
        case CONDITION_SOURCE_TYPE_GOSSIP_MENU:
        case CONDITION_SOURCE_TYPE_GOSSIP_MENU_OPTION:
        case CONDITION_SOURCE_TYPE_NONE:
        default:
            break;
    }

    return true;
}
bool ConditionMgr::isConditionTypeValid(Condition* cond)
{
    if (cond->mConditionType == CONDITION_NONE || cond->mConditionType >= CONDITION_MAX)
    {
        sLog.outErrorDb("Invalid ConditionType %u at SourceEntry %u in `condition` table, ignoring.", uint32(cond->mConditionType),cond->mSourceEntry);
        return false;
    }

    switch (cond->mConditionType)
    {
        case CONDITION_AURA:
        {
            if (!sSpellStore.LookupEntry(cond->mConditionValue1))
            {
                sLog.outErrorDb("Aura condition has non existing spell (Id: %d), skipped", cond->mConditionValue1);
                return false;
            }

            if (cond->mConditionValue2 > 2)
            {
                sLog.outErrorDb("Aura condition has non existing effect index (%u) (must be 0..2), skipped", cond->mConditionValue2);
                return false;
            }
            break;
        }
        case CONDITION_ITEM:
        {
            ItemPrototype const *proto = sObjectMgr.GetItemPrototype(cond->mConditionValue1);
            if (!proto)
            {
                sLog.outErrorDb("Item condition has non existing item (%u), skipped", cond->mConditionValue1);
                return false;
            }

            if (!cond->mConditionValue2)
            {
                sLog.outErrorDb("Item condition has 0 set for item count in value2 (%u), skipped", cond->mConditionValue2);
                return false;
            }
            break;
        }
        case CONDITION_ITEM_EQUIPPED:
        {
            ItemPrototype const *proto = sObjectMgr.GetItemPrototype(cond->mConditionValue1);
            if (!proto)
            {
                sLog.outErrorDb("ItemEquipped condition has non existing item (%u), skipped", cond->mConditionValue1);
                return false;
            }

            if (cond->mConditionValue2)
                sLog.outErrorDb("ItemEquipped condition has useless data in value2 (%u)!", cond->mConditionValue2);
            break;
        }
        case CONDITION_ZONEID:
        {
            AreaTableEntry const* areaEntry = GetAreaEntryByAreaID(cond->mConditionValue1);
            if (!areaEntry)
            {
                sLog.outErrorDb("Zone condition has non existing area (%u), skipped", cond->mConditionValue1);
                return false;
            }

            if (areaEntry->zone != 0)
            {
                sLog.outErrorDb("Zone condition requires to be in area (%u) which is a subzone but zone expected, skipped", cond->mConditionValue1);
                return false;
            }

            if (cond->mConditionValue2)
                sLog.outErrorDb("Zone condition has useless data in value2 (%u)!", cond->mConditionValue2);
            break;
        }
        case CONDITION_REPUTATION_RANK:
        {
            FactionEntry const* factionEntry = sFactionStore.LookupEntry(cond->mConditionValue1);
            if (!factionEntry)
            {
                sLog.outErrorDb("Reputation condition has non existing faction (%u), skipped", cond->mConditionValue1);
                return false;
            }
            break;
        }
        case CONDITION_TEAM:
        {
            if (cond->mConditionValue1 != ALLIANCE && cond->mConditionValue1 != HORDE)
            {
                sLog.outErrorDb("Team condition specifies unknown team (%u), skipped", cond->mConditionValue1);
                return false;
            }

            if (cond->mConditionValue2)
                sLog.outErrorDb("Team condition has useless data in value2 (%u)!", cond->mConditionValue2);
            break;
        }
        case CONDITION_SKILL:
        {
            SkillLineEntry const *pSkill = sSkillLineStore.LookupEntry(cond->mConditionValue1);
            if (!pSkill)
            {
                sLog.outErrorDb("Skill condition specifies non-existing skill (%u), skipped", cond->mConditionValue1);
                return false;
            }

            if (cond->mConditionValue2 < 1 || cond->mConditionValue2 > sWorld.GetConfigMaxSkillValue())
            {
                sLog.outErrorDb("Skill condition specifies invalid skill value (%u), skipped", cond->mConditionValue2);
                return false;
            }
            break;
        }
        case CONDITION_QUESTREWARDED:
        case CONDITION_QUESTTAKEN:
        case CONDITION_QUEST_NONE:
        {
            Quest const *Quest = sObjectMgr.GetQuestTemplate(cond->mConditionValue1);
            if (!Quest)
            {
                sLog.outErrorDb("Quest condition specifies non-existing quest (%u), skipped", cond->mConditionValue1);
                return false;
            }

            if (cond->mConditionValue2)
                sLog.outErrorDb("Quest condition has useless data in value2 (%u)!", cond->mConditionValue2);
            break;
        }
        case CONDITION_AD_COMMISSION_AURA:
        {
            if (cond->mConditionValue1)
                sLog.outErrorDb("Quest condition has useless data in value1 (%u)!", cond->mConditionValue1);

            if (cond->mConditionValue2)
                sLog.outErrorDb("Quest condition has useless data in value2 (%u)!", cond->mConditionValue2);
            break;
        }
        case CONDITION_NO_AURA:
        {
            if (!sSpellStore.LookupEntry(cond->mConditionValue1))
            {
                sLog.outErrorDb("Aura condition has non existing spell (Id: %d), skipped", cond->mConditionValue1);
                return false;
            }

            if (cond->mConditionValue2 > 2)
            {
                sLog.outErrorDb("Aura condition has non existing effect index (%u) in value2 (must be 0..2), skipped", cond->mConditionValue2);
                return false;
            }
            break;
        }
        case CONDITION_ACTIVE_EVENT:
        {
            GameEventMgr::GameEventDataMap const& events = sGameEventMgr.GetEventMap();
            if (cond->mConditionValue1 >=events.size() || !events[cond->mConditionValue1].isValid())
            {
                sLog.outErrorDb("Active event condition has non existing event id (%u), skipped", cond->mConditionValue1);
                return false;
            }

            if (cond->mConditionValue2)
                sLog.outErrorDb("Active event condition has useless data in value2 (%u)!", cond->mConditionValue2);
            break;
        }
        case CONDITION_ACHIEVEMENT:
        {
            AchievementEntry const* achievement = GetAchievementStore()->LookupEntry(cond->mConditionValue1);
            if (!achievement)
            {
                sLog.outErrorDb("Achivemen condition has non existing achivement id (%u), skipped", cond->mConditionValue1);
                return false;
            }

            if (cond->mConditionValue2)
                sLog.outErrorDb("Achivemen condition has useless data in value2 (%u)!", cond->mConditionValue2);
            break;
        }
        case CONDITION_CLASS:
        {
            if (cond->mConditionValue1 >= MAX_CLASSES)
            {
                sLog.outErrorDb("Class condition has non existing class (%u), skipped", cond->mConditionValue1);
                return false;
            }

            if (cond->mConditionValue2)
                sLog.outErrorDb("Class condition has useless data in value2 (%u)!", cond->mConditionValue2);
            break;
        }
        case CONDITION_RACE:
        {
            if (cond->mConditionValue1 >= MAX_RACES)
            {
                sLog.outErrorDb("Race condition has non existing race (%u), skipped", cond->mConditionValue1);
                return false;
            }

            if (cond->mConditionValue2)
                sLog.outErrorDb("Race condition has useless data in value2 (%u)!", cond->mConditionValue2);
            break;
        }
        case CONDITION_SPELL_SCRIPT_TARGET:
        {
            if (cond->mConditionValue1 >= MAX_SPELL_TARGET_TYPE)
            {
                sLog.outErrorDb("SpellTarget condition has non existing spell target type (%u), skipped", cond->mConditionValue1);
                return false;
            }

            switch(cond->mConditionValue1)
            {
                case SPELL_TARGET_TYPE_GAMEOBJECT:
                {
                    if (cond->mConditionValue2 && !sGOStorage.LookupEntry<GameObjectInfo>(cond->mConditionValue2))
                    {
                        sLog.outErrorDb("SpellTarget condition has non existing gameobject (%u) as target, skipped", cond->mConditionValue2);
                        return false;
                    }
                    break;
                }
                case SPELL_TARGET_TYPE_CONTROLLED:
                case SPELL_TARGET_TYPE_CREATURE:
                case SPELL_TARGET_TYPE_DEAD:
                {
                    if (cond->mConditionValue2 && !sCreatureStorage.LookupEntry<CreatureInfo>(cond->mConditionValue2))
                    {
                        sLog.outErrorDb("SpellTarget condition has non existing creature template entry (%u) as target, skipped", cond->mConditionValue2);
                        return false;
                    }

                    const CreatureInfo* cInfo = sCreatureStorage.LookupEntry<CreatureInfo>(cond->mConditionValue2);
                    if (cond->mSourceEntry == 30427 && !cInfo->SkinLootId)
                    {
                        sLog.outErrorDb("SpellTarget condition has creature entry %u as a target of spellid 30427, but this creature has no skinlootid. Gas extraction will not work!, skipped", cond->mConditionValue2);
                        return false;
                    }
                    break;
                }
            }

            if (cond->mConditionValue3)
                sLog.outErrorDb("SpellTarget condition has useless data in value3 (%u)!", cond->mConditionValue3);
            break;
        }
        case CONDITION_CREATURE_TARGET:
        {
            if (!cond->mConditionValue1 && !sCreatureStorage.LookupEntry<CreatureInfo>(cond->mConditionValue1))
            {
                sLog.outErrorDb("CreatureTarget condition has non existing creature template entry (%u) as target, skipped", cond->mConditionValue1);
                return false;
            }

            if (cond->mConditionValue2)
                sLog.outErrorDb("CreatureTarget condition has useless data in value2 (%u)!", cond->mConditionValue2);
            break;
        }
        case CONDITION_TARGET_HEALTH_BELOW_PCT:
        {
            if (cond->mConditionValue1 > 100)
            {
                sLog.outErrorDb("TargetHealthBelowPct condition has invalid data in value1 (%u), skipped", cond->mConditionValue1);
                return false;
            }

            if (cond->mConditionValue2)
                sLog.outErrorDb("TargetHealthBelowPct condition has useless data in value2 (%u)!", cond->mConditionValue2);
            break;
        }
        case CONDITION_TARGET_RANGE:
        {
            if (cond->mConditionValue2 && cond->mConditionValue2 < cond->mConditionValue1)//maxDist can be 0 for infinit max range
            {
                sLog.outErrorDb("TargetRange condition has max distance closer then min distance, skipped");
                return false;
            }
            break;
        }
        case CONDITION_MAPID:
        {
            MapEntry const * me = sMapStore.LookupEntry(cond->mConditionValue1);
            if (!me)
            {
                sLog.outErrorDb("Map condition has non existing map (%u), skipped", cond->mConditionValue1);
                return false;
            }

            if (cond->mConditionValue2)
                sLog.outErrorDb("Map condition has useless data in value2 (%u)!", cond->mConditionValue2);
            break;
        }
        case CONDITION_ITEM_TARGET:
        {
            if (!cond->mConditionValue1 || cond->mConditionValue1 > MAX_ITEM_REQ_TARGET_TYPE)
            {
                sLog.outErrorDb("ItemTarget condition has incorrect target type (%u), skipped", cond->mConditionValue1);
                return false;
            }

            if (!cond->mConditionValue2 && !sCreatureStorage.LookupEntry<CreatureInfo>(cond->mConditionValue2))
            {
                sLog.outErrorDb("ItemTarget condition has non existing creature template entry (%u) as target, skipped", cond->mConditionValue2);
                return false;
            }

            if (cond->mConditionValue3)
                sLog.outErrorDb("ItemTarget condition has useless data in value3 (%u)!", cond->mConditionValue3);
            break;
        }
        case CONDITION_SPELL:
        {
            if (!sSpellStore.LookupEntry(cond->mConditionValue1))
            {
                sLog.outErrorDb("Spell condition has non existing spell (Id: %d), skipped", cond->mConditionValue1);
                return false;
            }

            if (cond->mConditionValue2)
                sLog.outErrorDb("Spell condition has useless data in value2 (%u)!", cond->mConditionValue2);
            break;
        }
        case CONDITION_AREAID:
        case CONDITION_INSTANCE_DATA:
            break;
        default:
            break;
    }
    return true;
}

void ConditionMgr::Clean()
{
    for (ConditionReferenceMap::iterator itr = m_ConditionReferenceMap.begin(); itr != m_ConditionReferenceMap.end(); ++itr)
    {
        for (ConditionList::const_iterator it = itr->second.begin(); it != itr->second.end(); ++it)
            delete *it;
        itr->second.clear();
    }

    m_ConditionReferenceMap.clear();

    for (ConditionMap::iterator itr = m_ConditionMap.begin(); itr != m_ConditionMap.end(); ++itr)
    {
        for (ConditionTypeMap::iterator it = itr->second.begin(); it != itr->second.end(); ++it)
        {
            for (ConditionList::const_iterator i = it->second.begin(); i != it->second.end(); ++i)
                delete *i;
            it->second.clear();
        }
        itr->second.clear();
    }

    m_ConditionMap.clear();

    // this is a BIG hack, feel free to fix it if you can figure out the ConditionMgr ;)
    for (std::list<Condition*>::const_iterator itr = m_AllocatedMemory.begin(); itr != m_AllocatedMemory.end(); ++itr)
        delete *itr;

    m_AllocatedMemory.clear();
}
