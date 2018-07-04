/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "SpellMgr.h"
#include "BattlefieldMgr.h"
#include "BattlefieldWG.h"
#include "BattlegroundMgr.h"
#include "Chat.h"
#include "DB2Stores.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "SharedDefines.h"
#include "Spell.h"
#include "SpellAuraDefines.h"
#include "SpellInfo.h"
#include <G3D/g3dmath.h>

PetFamilySpellsStore sPetFamilySpellsStore;

bool IsPrimaryProfessionSkill(uint32 skill)
{
    SkillLineEntry const* pSkill = sSkillLineStore.LookupEntry(skill);
    return pSkill && pSkill->CategoryID == SKILL_CATEGORY_PROFESSION;
}

bool IsWeaponSkill(uint32 skill)
{
    SkillLineEntry const* pSkill = sSkillLineStore.LookupEntry(skill);
    return pSkill && pSkill->CategoryID == SKILL_CATEGORY_WEAPON;
}

bool IsPartOfSkillLine(uint32 skillId, uint32 spellId)
{
    SkillLineAbilityMapBounds skillBounds = sSpellMgr->GetSkillLineAbilityMapBounds(spellId);
    for (SkillLineAbilityMap::const_iterator itr = skillBounds.first; itr != skillBounds.second; ++itr)
        if (itr->second->SkillLine == int32(skillId))
            return true;

    return false;
}

SpellMgr::SpellMgr() { }

SpellMgr::~SpellMgr()
{
    UnloadSpellInfoStore();
}

SpellMgr* SpellMgr::instance()
{
    static SpellMgr instance;
    return &instance;
}

/// Some checks for spells, to prevent adding deprecated/broken spells for trainers, spell book, etc
bool SpellMgr::IsSpellValid(SpellInfo const* spellInfo, Player* player, bool msg)
{
    // not exist
    if (!spellInfo)
        return false;

    bool needCheckReagents = false;

    // check effects
    for (SpellEffectInfo const* effect : spellInfo->GetEffectsForDifficulty(DIFFICULTY_NONE))
    {
        if (!effect)
            continue;

        switch (effect->Effect)
        {
            case 0:
                continue;

            // craft spell for crafting non-existed item (break client recipes list show)
            case SPELL_EFFECT_CREATE_ITEM:
            case SPELL_EFFECT_CREATE_LOOT:
            {
                if (effect->ItemType == 0)
                {
                    // skip auto-loot crafting spells, it does not need explicit item info (but has special fake items sometimes).
                    if (!spellInfo->IsLootCrafting())
                    {
                        if (msg)
                        {
                            if (player)
                                ChatHandler(player->GetSession()).PSendSysMessage("The craft spell %u does not have a create item entry.", spellInfo->Id);
                            else
                                TC_LOG_ERROR("sql.sql", "The craft spell %u does not have a create item entry.", spellInfo->Id);
                        }
                        return false;
                    }

                }
                // also possible IsLootCrafting case but fake items must exist anyway
                else if (!sObjectMgr->GetItemTemplate(effect->ItemType))
                {
                    if (msg)
                    {
                        if (player)
                            ChatHandler(player->GetSession()).PSendSysMessage("Craft spell %u has created a non-existing in DB item (Entry: %u) and then...", spellInfo->Id, effect->ItemType);
                        else
                            TC_LOG_ERROR("sql.sql", "Craft spell %u has created a non-existing item in DB item (Entry: %u) and then...", spellInfo->Id, effect->ItemType);
                    }
                    return false;
                }

                needCheckReagents = true;
                break;
            }
            case SPELL_EFFECT_LEARN_SPELL:
            {
                SpellInfo const* spellInfo2 = sSpellMgr->GetSpellInfo(effect->TriggerSpell);
                if (!IsSpellValid(spellInfo2, player, msg))
                {
                    if (msg)
                    {
                        if (player)
                            ChatHandler(player->GetSession()).PSendSysMessage("Spell %u learn to broken spell %u, and then...", spellInfo->Id, effect->TriggerSpell);
                        else
                            TC_LOG_ERROR("sql.sql", "Spell %u learn to invalid spell %u, and then...", spellInfo->Id, effect->TriggerSpell);
                    }
                    return false;
                }
                break;
            }
        }
    }

    if (needCheckReagents)
    {
        for (uint8 j = 0; j < MAX_SPELL_REAGENTS; ++j)
        {
            if (spellInfo->Reagent[j] > 0 && !sObjectMgr->GetItemTemplate(spellInfo->Reagent[j]))
            {
                if (msg)
                {
                    if (player)
                        ChatHandler(player->GetSession()).PSendSysMessage("Craft spell %u refers a non-existing reagent in DB item (Entry: %u) and then...", spellInfo->Id, spellInfo->Reagent[j]);
                    else
                        TC_LOG_ERROR("sql.sql", "Craft spell %u refers to a non-existing reagent in DB, item (Entry: %u) and then...", spellInfo->Id, spellInfo->Reagent[j]);
                }
                return false;
            }
        }
    }

    return true;
}

SpellChainNode const* SpellMgr::GetSpellChainNode(uint32 spell_id) const
{
    SpellChainMap::const_iterator itr = mSpellChains.find(spell_id);
    if (itr == mSpellChains.end())
        return NULL;

    return &itr->second;
}

uint32 SpellMgr::GetFirstSpellInChain(uint32 spell_id) const
{
    if (SpellChainNode const* node = GetSpellChainNode(spell_id))
        return node->first->Id;

    return spell_id;
}

uint32 SpellMgr::GetLastSpellInChain(uint32 spell_id) const
{
    if (SpellChainNode const* node = GetSpellChainNode(spell_id))
        return node->last->Id;

    return spell_id;
}

uint32 SpellMgr::GetNextSpellInChain(uint32 spell_id) const
{
    if (SpellChainNode const* node = GetSpellChainNode(spell_id))
        if (node->next)
            return node->next->Id;

    return 0;
}

uint32 SpellMgr::GetPrevSpellInChain(uint32 spell_id) const
{
    if (SpellChainNode const* node = GetSpellChainNode(spell_id))
        if (node->prev)
            return node->prev->Id;

    return 0;
}

uint8 SpellMgr::GetSpellRank(uint32 spell_id) const
{
    if (SpellChainNode const* node = GetSpellChainNode(spell_id))
        return node->rank;

    return 0;
}

uint32 SpellMgr::GetSpellWithRank(uint32 spell_id, uint32 rank, bool strict) const
{
    if (SpellChainNode const* node = GetSpellChainNode(spell_id))
    {
        if (rank != node->rank)
            return GetSpellWithRank(node->rank < rank ? node->next->Id : node->prev->Id, rank, strict);
    }
    else if (strict && rank > 1)
        return 0;
    return spell_id;
}

Trinity::IteratorPair<SpellRequiredMap::const_iterator> SpellMgr::GetSpellsRequiredForSpellBounds(uint32 spell_id) const
{
    return Trinity::Containers::MapEqualRange(mSpellReq, spell_id);
}

SpellsRequiringSpellMapBounds SpellMgr::GetSpellsRequiringSpellBounds(uint32 spell_id) const
{
    return mSpellsReqSpell.equal_range(spell_id);
}

bool SpellMgr::IsSpellRequiringSpell(uint32 spellid, uint32 req_spellid) const
{
    SpellsRequiringSpellMapBounds spellsRequiringSpell = GetSpellsRequiringSpellBounds(req_spellid);
    for (SpellsRequiringSpellMap::const_iterator itr = spellsRequiringSpell.first; itr != spellsRequiringSpell.second; ++itr)
    {
        if (itr->second == spellid)
            return true;
    }
    return false;
}

SpellLearnSkillNode const* SpellMgr::GetSpellLearnSkill(uint32 spell_id) const
{
    SpellLearnSkillMap::const_iterator itr = mSpellLearnSkills.find(spell_id);
    if (itr != mSpellLearnSkills.end())
        return &itr->second;
    else
        return NULL;
}

SpellLearnSpellMapBounds SpellMgr::GetSpellLearnSpellMapBounds(uint32 spell_id) const
{
    return mSpellLearnSpells.equal_range(spell_id);
}

bool SpellMgr::IsSpellLearnSpell(uint32 spell_id) const
{
    return mSpellLearnSpells.find(spell_id) != mSpellLearnSpells.end();
}

bool SpellMgr::IsSpellLearnToSpell(uint32 spell_id1, uint32 spell_id2) const
{
    SpellLearnSpellMapBounds bounds = GetSpellLearnSpellMapBounds(spell_id1);
    for (SpellLearnSpellMap::const_iterator i = bounds.first; i != bounds.second; ++i)
        if (i->second.Spell == spell_id2)
            return true;
    return false;
}

SpellTargetPosition const* SpellMgr::GetSpellTargetPosition(uint32 spell_id, SpellEffIndex effIndex) const
{
    SpellTargetPositionMap::const_iterator itr = mSpellTargetPositions.find(std::make_pair(spell_id, effIndex));
    if (itr != mSpellTargetPositions.end())
        return &itr->second;
    return NULL;
}

SpellSpellGroupMapBounds SpellMgr::GetSpellSpellGroupMapBounds(uint32 spell_id) const
{
    spell_id = GetFirstSpellInChain(spell_id);
    return mSpellSpellGroup.equal_range(spell_id);
}

bool SpellMgr::IsSpellMemberOfSpellGroup(uint32 spellid, SpellGroup groupid) const
{
    SpellSpellGroupMapBounds spellGroup = GetSpellSpellGroupMapBounds(spellid);
    for (SpellSpellGroupMap::const_iterator itr = spellGroup.first; itr != spellGroup.second; ++itr)
    {
        if (itr->second == groupid)
            return true;
    }
    return false;
}

SpellGroupSpellMapBounds SpellMgr::GetSpellGroupSpellMapBounds(SpellGroup group_id) const
{
    return mSpellGroupSpell.equal_range(group_id);
}

void SpellMgr::GetSetOfSpellsInSpellGroup(SpellGroup group_id, std::set<uint32>& foundSpells) const
{
    std::set<SpellGroup> usedGroups;
    GetSetOfSpellsInSpellGroup(group_id, foundSpells, usedGroups);
}

void SpellMgr::GetSetOfSpellsInSpellGroup(SpellGroup group_id, std::set<uint32>& foundSpells, std::set<SpellGroup>& usedGroups) const
{
    if (usedGroups.find(group_id) != usedGroups.end())
        return;
    usedGroups.insert(group_id);

    SpellGroupSpellMapBounds groupSpell = GetSpellGroupSpellMapBounds(group_id);
    for (SpellGroupSpellMap::const_iterator itr = groupSpell.first; itr != groupSpell.second; ++itr)
    {
        if (itr->second < 0)
        {
            SpellGroup currGroup = (SpellGroup)abs(itr->second);
            GetSetOfSpellsInSpellGroup(currGroup, foundSpells, usedGroups);
        }
        else
        {
            foundSpells.insert(itr->second);
        }
    }
}

bool SpellMgr::AddSameEffectStackRuleSpellGroups(SpellInfo const* spellInfo, int32 amount, std::map<SpellGroup, int32>& groups) const
{
    uint32 spellId = spellInfo->GetFirstRankSpell()->Id;
    SpellSpellGroupMapBounds spellGroup = GetSpellSpellGroupMapBounds(spellId);
    // Find group with SPELL_GROUP_STACK_RULE_EXCLUSIVE_SAME_EFFECT if it belongs to one
    for (SpellSpellGroupMap::const_iterator itr = spellGroup.first; itr != spellGroup.second; ++itr)
    {
        SpellGroup group = itr->second;
        SpellGroupStackMap::const_iterator found = mSpellGroupStack.find(group);
        if (found != mSpellGroupStack.end())
        {
            if (found->second == SPELL_GROUP_STACK_RULE_EXCLUSIVE_SAME_EFFECT)
            {
                // Put the highest amount in the map
                if (groups.find(group) == groups.end())
                    groups[group] = amount;
                else
                {
                    int32 curr_amount = groups[group];
                    // Take absolute value because this also counts for the highest negative aura
                    if (abs(curr_amount) < abs(amount))
                        groups[group] = amount;
                }
                // return because a spell should be in only one SPELL_GROUP_STACK_RULE_EXCLUSIVE_SAME_EFFECT group
                return true;
            }
        }
    }
    // Not in a SPELL_GROUP_STACK_RULE_EXCLUSIVE_SAME_EFFECT group, so return false
    return false;
}

SpellGroupStackRule SpellMgr::CheckSpellGroupStackRules(SpellInfo const* spellInfo1, SpellInfo const* spellInfo2) const
{
    uint32 spellid_1 = spellInfo1->GetFirstRankSpell()->Id;
    uint32 spellid_2 = spellInfo2->GetFirstRankSpell()->Id;
    if (spellid_1 == spellid_2)
        return SPELL_GROUP_STACK_RULE_DEFAULT;
    // find SpellGroups which are common for both spells
    SpellSpellGroupMapBounds spellGroup1 = GetSpellSpellGroupMapBounds(spellid_1);
    std::set<SpellGroup> groups;
    for (SpellSpellGroupMap::const_iterator itr = spellGroup1.first; itr != spellGroup1.second; ++itr)
    {
        if (IsSpellMemberOfSpellGroup(spellid_2, itr->second))
        {
            bool add = true;
            SpellGroupSpellMapBounds groupSpell = GetSpellGroupSpellMapBounds(itr->second);
            for (SpellGroupSpellMap::const_iterator itr2 = groupSpell.first; itr2 != groupSpell.second; ++itr2)
            {
                if (itr2->second < 0)
                {
                    SpellGroup currGroup = (SpellGroup)abs(itr2->second);
                    if (IsSpellMemberOfSpellGroup(spellid_1, currGroup) && IsSpellMemberOfSpellGroup(spellid_2, currGroup))
                    {
                        add = false;
                        break;
                    }
                }
            }
            if (add)
                groups.insert(itr->second);
        }
    }

    SpellGroupStackRule rule = SPELL_GROUP_STACK_RULE_DEFAULT;

    for (std::set<SpellGroup>::iterator itr = groups.begin(); itr!= groups.end(); ++itr)
    {
        SpellGroupStackMap::const_iterator found = mSpellGroupStack.find(*itr);
        if (found != mSpellGroupStack.end())
            rule = found->second;
        if (rule)
            break;
    }
    return rule;
}

SpellGroupStackRule SpellMgr::GetSpellGroupStackRule(SpellGroup group) const
{
    SpellGroupStackMap::const_iterator itr = mSpellGroupStack.find(group);
    if (itr != mSpellGroupStack.end())
        return itr->second;

    return SPELL_GROUP_STACK_RULE_DEFAULT;
}

SpellProcEntry const* SpellMgr::GetSpellProcEntry(uint32 spellId) const
{
    SpellProcMap::const_iterator itr = mSpellProcMap.find(spellId);
    if (itr != mSpellProcMap.end())
        return &itr->second;
    return NULL;
}

bool SpellMgr::CanSpellTriggerProcOnEvent(SpellProcEntry const& procEntry, ProcEventInfo& eventInfo)
{
    // proc type doesn't match
    if (!(eventInfo.GetTypeMask() & procEntry.ProcFlags))
        return false;

    // check XP or honor target requirement
    if (procEntry.AttributesMask & PROC_ATTR_REQ_EXP_OR_HONOR)
        if (Player* actor = eventInfo.GetActor()->ToPlayer())
            if (eventInfo.GetActionTarget() && !actor->isHonorOrXPTarget(eventInfo.GetActionTarget()))
                return false;

    // check power requirement
    if (procEntry.AttributesMask & PROC_ATTR_REQ_POWER_COST)
    {
        if (!eventInfo.GetProcSpell())
            return false;

        std::vector<SpellPowerCost> const& costs = eventInfo.GetProcSpell()->GetPowerCost();
        auto m = std::find_if(costs.begin(), costs.end(), [](SpellPowerCost const& cost) { return cost.Amount > 0; });
        if (m == costs.end())
            return false;
    }

    // always trigger for these types
    if (eventInfo.GetTypeMask() & (PROC_FLAG_KILLED | PROC_FLAG_KILL | PROC_FLAG_DEATH))
        return true;

    // do triggered cast checks
    // Do not consider autoattacks as triggered spells
    if (!(procEntry.AttributesMask & PROC_ATTR_TRIGGERED_CAN_PROC) && !(eventInfo.GetTypeMask() & AUTO_ATTACK_PROC_FLAG_MASK))
    {
        if (Spell const* spell = eventInfo.GetProcSpell())
        {
            if (spell->IsTriggered())
            {
                SpellInfo const* spellInfo = spell->GetSpellInfo();
                if (!spellInfo->HasAttribute(SPELL_ATTR3_TRIGGERED_CAN_TRIGGER_PROC_2) &&
                    !spellInfo->HasAttribute(SPELL_ATTR2_TRIGGERED_CAN_TRIGGER_PROC))
                    return false;
            }
        }
    }

    // check school mask (if set) for other trigger types
    if (procEntry.SchoolMask && !(eventInfo.GetSchoolMask() & procEntry.SchoolMask))
        return false;

    // check spell family name/flags (if set) for spells
    if (eventInfo.GetTypeMask() & (PERIODIC_PROC_FLAG_MASK | SPELL_PROC_FLAG_MASK))
    {
        if (SpellInfo const* eventSpellInfo = eventInfo.GetSpellInfo())
            if (!eventSpellInfo->IsAffected(procEntry.SpellFamilyName, procEntry.SpellFamilyMask))
                return false;
    }

    // check spell type mask (if set)
    if (eventInfo.GetTypeMask() & (SPELL_PROC_FLAG_MASK | PERIODIC_PROC_FLAG_MASK))
    {
        if (procEntry.SpellTypeMask && !(eventInfo.GetSpellTypeMask() & procEntry.SpellTypeMask))
            return false;
    }

    // check spell phase mask
    if (eventInfo.GetTypeMask() & REQ_SPELL_PHASE_PROC_FLAG_MASK)
    {
        if (!(eventInfo.GetSpellPhaseMask() & procEntry.SpellPhaseMask))
            return false;
    }

    // check hit mask (on taken hit or on done hit, but not on spell cast phase)
    if ((eventInfo.GetTypeMask() & TAKEN_HIT_PROC_FLAG_MASK) || ((eventInfo.GetTypeMask() & DONE_HIT_PROC_FLAG_MASK) && !(eventInfo.GetSpellPhaseMask() & PROC_SPELL_PHASE_CAST)))
    {
        uint32 hitMask = procEntry.HitMask;
        // get default values if hit mask not set
        if (!hitMask)
        {
            // for taken procs allow normal + critical hits by default
            if (eventInfo.GetTypeMask() & TAKEN_HIT_PROC_FLAG_MASK)
                hitMask |= PROC_HIT_NORMAL | PROC_HIT_CRITICAL;
            // for done procs allow normal + critical + absorbs by default
            else
                hitMask |= PROC_HIT_NORMAL | PROC_HIT_CRITICAL | PROC_HIT_ABSORB;
        }
        if (!(eventInfo.GetHitMask() & hitMask))
            return false;
    }

    return true;
}

SpellThreatEntry const* SpellMgr::GetSpellThreatEntry(uint32 spellID) const
{
    SpellThreatMap::const_iterator itr = mSpellThreatMap.find(spellID);
    if (itr != mSpellThreatMap.end())
        return &itr->second;
    else
    {
        uint32 firstSpell = GetFirstSpellInChain(spellID);
        itr = mSpellThreatMap.find(firstSpell);
        if (itr != mSpellThreatMap.end())
            return &itr->second;
    }
    return NULL;
}

SkillLineAbilityMapBounds SpellMgr::GetSkillLineAbilityMapBounds(uint32 spell_id) const
{
    return mSkillLineAbilityMap.equal_range(spell_id);
}

PetAura const* SpellMgr::GetPetAura(uint32 spell_id, uint8 eff) const
{
    SpellPetAuraMap::const_iterator itr = mSpellPetAuraMap.find((spell_id<<8) + eff);
    if (itr != mSpellPetAuraMap.end())
        return &itr->second;
    else
        return NULL;
}

SpellEnchantProcEntry const* SpellMgr::GetSpellEnchantProcEvent(uint32 enchId) const
{
    SpellEnchantProcEventMap::const_iterator itr = mSpellEnchantProcEventMap.find(enchId);
    if (itr != mSpellEnchantProcEventMap.end())
        return &itr->second;
    return NULL;
}

bool SpellMgr::IsArenaAllowedEnchancment(uint32 ench_id) const
{
    return mEnchantCustomAttr[ench_id];
}

const std::vector<int32>* SpellMgr::GetSpellLinked(int32 spell_id) const
{
    SpellLinkedMap::const_iterator itr = mSpellLinkedMap.find(spell_id);
    return itr != mSpellLinkedMap.end() ? &(itr->second) : NULL;
}

PetLevelupSpellSet const* SpellMgr::GetPetLevelupSpellList(uint32 petFamily) const
{
    PetLevelupSpellMap::const_iterator itr = mPetLevelupSpellMap.find(petFamily);
    if (itr != mPetLevelupSpellMap.end())
        return &itr->second;
    else
        return NULL;
}

PetDefaultSpellsEntry const* SpellMgr::GetPetDefaultSpellsEntry(int32 id) const
{
    PetDefaultSpellsMap::const_iterator itr = mPetDefaultSpellsMap.find(id);
    if (itr != mPetDefaultSpellsMap.end())
        return &itr->second;
    return NULL;
}

SpellAreaMapBounds SpellMgr::GetSpellAreaMapBounds(uint32 spell_id) const
{
    return mSpellAreaMap.equal_range(spell_id);
}

SpellAreaForQuestMapBounds SpellMgr::GetSpellAreaForQuestMapBounds(uint32 quest_id) const
{
    return mSpellAreaForQuestMap.equal_range(quest_id);
}

SpellAreaForQuestMapBounds SpellMgr::GetSpellAreaForQuestEndMapBounds(uint32 quest_id) const
{
    return mSpellAreaForQuestEndMap.equal_range(quest_id);
}

SpellAreaForAuraMapBounds SpellMgr::GetSpellAreaForAuraMapBounds(uint32 spell_id) const
{
    return mSpellAreaForAuraMap.equal_range(spell_id);
}

SpellAreaForAreaMapBounds SpellMgr::GetSpellAreaForAreaMapBounds(uint32 area_id) const
{
    return mSpellAreaForAreaMap.equal_range(area_id);
}

SpellAreaForQuestAreaMapBounds SpellMgr::GetSpellAreaForQuestAreaMapBounds(uint32 area_id, uint32 quest_id) const
{
    return mSpellAreaForQuestAreaMap.equal_range(std::pair<uint32, uint32>(area_id, quest_id));
}

bool SpellArea::IsFitToRequirements(Player const* player, uint32 newZone, uint32 newArea) const
{
    if (gender != GENDER_NONE)                   // is not expected gender
        if (!player || gender != player->getGender())
            return false;

    if (raceMask)                                // is not expected race
        if (!player || !(raceMask & player->getRaceMask()))
            return false;

    if (areaId)                                  // is not in expected zone
        if (newZone != areaId && newArea != areaId)
            return false;

    if (questStart)                              // is not in expected required quest state
        if (!player || (((1 << player->GetQuestStatus(questStart)) & questStartStatus) == 0))
            return false;

    if (questEnd)                                // is not in expected forbidden quest state
        if (!player || (((1 << player->GetQuestStatus(questEnd)) & questEndStatus) == 0))
            return false;

    if (auraSpell)                               // does not have expected aura
        if (!player || (auraSpell > 0 && !player->HasAura(auraSpell)) || (auraSpell < 0 && player->HasAura(-auraSpell)))
            return false;

    if (player)
    {
        if (Battleground* bg = player->GetBattleground())
            return bg->IsSpellAllowed(spellId, player);
    }

    // Extra conditions
    switch (spellId)
    {
        case 91604: // No fly Zone - Wintergrasp
        {
            if (!player)
                return false;

            Battlefield* Bf = sBattlefieldMgr->GetBattlefieldToZoneId(player->GetZoneId());
            if (!Bf || Bf->CanFlyIn() || (!player->HasAuraType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED) && !player->HasAuraType(SPELL_AURA_FLY)))
                return false;
            break;
        }
        case 56618: // Horde Controls Factory Phase Shift
        case 56617: // Alliance Controls Factory Phase Shift
        {
            if (!player)
                return false;

            Battlefield* bf = sBattlefieldMgr->GetBattlefieldToZoneId(player->GetZoneId());

            if (!bf || bf->GetTypeId() != BATTLEFIELD_WG)
                return false;

            // team that controls the workshop in the specified area
            uint32 team = bf->GetData(newArea);

            if (team == TEAM_HORDE)
                return spellId == 56618;
            else if (team == TEAM_ALLIANCE)
                return spellId == 56617;
            break;
        }
        case 57940: // Essence of Wintergrasp - Northrend
        case 58045: // Essence of Wintergrasp - Wintergrasp
        {
            if (!player)
                return false;

            if (Battlefield* battlefieldWG = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG))
                return battlefieldWG->IsEnabled() && (player->GetTeamId() == battlefieldWG->GetDefenderTeam()) && !battlefieldWG->IsWarTime();
            break;
        }
        case 74411: // Battleground - Dampening
        {
            if (!player)
                return false;

            if (Battlefield* bf = sBattlefieldMgr->GetBattlefieldToZoneId(player->GetZoneId()))
                return bf->IsWarTime();
            break;
        }

    }

    return true;
}

void SpellMgr::UnloadSpellInfoChains()
{
    for (SpellChainMap::iterator itr = mSpellChains.begin(); itr != mSpellChains.end(); ++itr)
        mSpellInfoMap[itr->first]->ChainEntry = NULL;

    mSpellChains.clear();
}

void SpellMgr::LoadSpellRanks()
{
    uint32 oldMSTime = getMSTime();

    std::map<uint32 /*spell*/, uint32 /*next*/> chains;
    std::set<uint32> hasPrev;
    for (SkillLineAbilityEntry const* skillAbility : sSkillLineAbilityStore)
    {
        if (!skillAbility->SupercedesSpell)
            continue;

        if (!GetSpellInfo(skillAbility->SupercedesSpell) || !GetSpellInfo(skillAbility->Spell))
            continue;

        chains[skillAbility->SupercedesSpell] = skillAbility->Spell;
        hasPrev.insert(skillAbility->Spell);
    }

    // each key in chains that isn't present in hasPrev is a first rank
    for (auto itr = chains.begin(); itr != chains.end(); ++itr)
    {
        if (hasPrev.count(itr->first))
            continue;

        SpellInfo const* first = AssertSpellInfo(itr->first);
        SpellInfo const* next = AssertSpellInfo(itr->second);

        mSpellChains[itr->first].first = first;
        mSpellChains[itr->first].prev = nullptr;
        mSpellChains[itr->first].next = next;
        mSpellChains[itr->first].last = next;
        mSpellChains[itr->first].rank = 1;
        mSpellInfoMap[itr->first]->ChainEntry = &mSpellChains[itr->first];

        mSpellChains[itr->second].first = first;
        mSpellChains[itr->second].prev = first;
        mSpellChains[itr->second].next = nullptr;
        mSpellChains[itr->second].last = next;
        mSpellChains[itr->second].rank = 2;
        mSpellInfoMap[itr->second]->ChainEntry = &mSpellChains[itr->second];

        uint8 rank = 3;
        auto nextItr = chains.find(itr->second);
        while (nextItr != chains.end())
        {
            SpellInfo const* prev = AssertSpellInfo(nextItr->first); // already checked in previous iteration (or above, in case this is the first one)
            SpellInfo const* last = AssertSpellInfo(nextItr->second);

            mSpellChains[nextItr->first].next = last;

            mSpellChains[nextItr->second].first = first;
            mSpellChains[nextItr->second].prev = prev;
            mSpellChains[nextItr->second].next = nullptr;
            mSpellChains[nextItr->second].last = last;
            mSpellChains[nextItr->second].rank = rank++;
            mSpellInfoMap[nextItr->second]->ChainEntry = &mSpellChains[nextItr->second];

            // fill 'last'
            do
            {
                mSpellChains[prev->Id].last = last;
                prev = mSpellChains[prev->Id].prev;
            } while (prev);

            nextItr = chains.find(nextItr->second);
        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u spell rank records in %u ms", uint32(mSpellChains.size()), GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellRequired()
{
    uint32 oldMSTime = getMSTime();

    mSpellsReqSpell.clear();                                   // need for reload case
    mSpellReq.clear();                                         // need for reload case

    //                                                   0        1
    QueryResult result = WorldDatabase.Query("SELECT spell_id, req_spell from spell_required");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 spell required records. DB table `spell_required` is empty.");

        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 spell_id = fields[0].GetUInt32();
        uint32 spell_req = fields[1].GetUInt32();

        // check if chain is made with valid first spell
        SpellInfo const* spell = GetSpellInfo(spell_id);
        if (!spell)
        {
            TC_LOG_ERROR("sql.sql", "spell_id %u in `spell_required` table could not be found in dbc, skipped.", spell_id);
            continue;
        }

        SpellInfo const* reqSpell = GetSpellInfo(spell_req);
        if (!reqSpell)
        {
            TC_LOG_ERROR("sql.sql", "req_spell %u in `spell_required` table could not be found in dbc, skipped.", spell_req);
            continue;
        }

        if (spell->IsRankOf(reqSpell))
        {
            TC_LOG_ERROR("sql.sql", "req_spell %u and spell_id %u in `spell_required` table are ranks of the same spell, entry not needed, skipped.", spell_req, spell_id);
            continue;
        }

        if (IsSpellRequiringSpell(spell_id, spell_req))
        {
            TC_LOG_ERROR("sql.sql", "Duplicate entry of req_spell %u and spell_id %u in `spell_required`, skipped.", spell_req, spell_id);
            continue;
        }

        mSpellReq.insert (std::pair<uint32, uint32>(spell_id, spell_req));
        mSpellsReqSpell.insert (std::pair<uint32, uint32>(spell_req, spell_id));
        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u spell required records in %u ms", count, GetMSTimeDiffToNow(oldMSTime));

}

void SpellMgr::LoadSpellLearnSkills()
{
    uint32 oldMSTime = getMSTime();

    mSpellLearnSkills.clear();                              // need for reload case

    // search auto-learned skills and add its to map also for use in unlearn spells/talents
    uint32 dbc_count = 0;
    for (SpellInfo const* entry : mSpellInfoMap)
    {
        if (!entry)
            continue;

        for (SpellEffectInfo const* effect : entry->GetEffectsForDifficulty(DIFFICULTY_NONE))
        {
            if (!effect)
                continue;

            SpellLearnSkillNode dbc_node;
            switch (effect->Effect)
            {
                case SPELL_EFFECT_SKILL:
                    dbc_node.skill = uint16(effect->MiscValue);
                    dbc_node.step  = uint16(effect->CalcValue());
                    if (dbc_node.skill != SKILL_RIDING)
                        dbc_node.value = 1;
                    else
                        dbc_node.value = dbc_node.step * 75;
                    dbc_node.maxvalue = dbc_node.step * 75;
                    break;
                case SPELL_EFFECT_DUAL_WIELD:
                    dbc_node.skill = SKILL_DUAL_WIELD;
                    dbc_node.step = 1;
                    dbc_node.value = 1;
                    dbc_node.maxvalue = 1;
                    break;
                default:
                    continue;
            }

            mSpellLearnSkills[entry->Id] = dbc_node;
            ++dbc_count;
            break;
        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u Spell Learn Skills from DBC in %u ms", dbc_count, GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellLearnSpells()
{
    uint32 oldMSTime = getMSTime();

    mSpellLearnSpells.clear();                              // need for reload case

    //                                                  0      1        2
    QueryResult result = WorldDatabase.Query("SELECT entry, SpellID, Active FROM spell_learn_spell");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 spell learn spells. DB table `spell_learn_spell` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 spell_id = fields[0].GetUInt32();

        SpellLearnSpellNode node;
        node.Spell       = fields[1].GetUInt32();
        node.OverridesSpell = 0;
        node.Active      = fields[2].GetBool();
        node.AutoLearned = false;

        SpellInfo const* spellInfo = GetSpellInfo(spell_id);
        if (!spellInfo)
        {
            TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_learn_spell` does not exist.", spell_id);
            continue;
        }

        if (!GetSpellInfo(node.Spell))
        {
            TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_learn_spell` learning non-existing spell %u.", spell_id, node.Spell);
            continue;
        }

        if (spellInfo->HasAttribute(SPELL_ATTR0_CU_IS_TALENT))
        {
            TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_learn_spell` attempts learning talent spell %u, skipped.", spell_id, node.Spell);
            continue;
        }

        mSpellLearnSpells.insert(SpellLearnSpellMap::value_type(spell_id, node));

        ++count;
    } while (result->NextRow());

    // copy state loaded from db
    SpellLearnSpellMap dbSpellLearnSpells = mSpellLearnSpells;

    // search auto-learned spells and add its to map also for use in unlearn spells/talents
    uint32 dbc_count = 0;
    for (uint32 spell = 0; spell < GetSpellInfoStoreSize(); ++spell)
    {
        SpellInfo const* entry = GetSpellInfo(spell);

        if (!entry)
            continue;

        for (SpellEffectInfo const* effect : entry->GetEffectsForDifficulty(DIFFICULTY_NONE))
        {
            if (effect && effect->Effect == SPELL_EFFECT_LEARN_SPELL)
            {
                SpellLearnSpellNode dbc_node;
                dbc_node.Spell = effect->TriggerSpell;
                dbc_node.Active = true;                     // all dbc based learned spells is active (show in spell book or hide by client itself)
                dbc_node.OverridesSpell = 0;

                // ignore learning not existed spells (broken/outdated/or generic learnig spell 483
                if (!GetSpellInfo(dbc_node.Spell))
                    continue;

                // talent or passive spells or skill-step spells auto-cast and not need dependent learning,
                // pet teaching spells must not be dependent learning (cast)
                // other required explicit dependent learning
                dbc_node.AutoLearned = effect->TargetA.GetTarget() == TARGET_UNIT_PET || entry->HasAttribute(SPELL_ATTR0_CU_IS_TALENT) || entry->IsPassive() || entry->HasEffect(SPELL_EFFECT_SKILL_STEP);

                SpellLearnSpellMapBounds db_node_bounds = dbSpellLearnSpells.equal_range(spell);

                bool found = false;
                for (SpellLearnSpellMap::const_iterator itr = db_node_bounds.first; itr != db_node_bounds.second; ++itr)
                {
                    if (itr->second.Spell == dbc_node.Spell)
                    {
                        TC_LOG_ERROR("sql.sql", "The spell %u is an auto-learn spell %u in spell.dbc and the record in `spell_learn_spell` is redundant. Please update your DB.",
                            spell, dbc_node.Spell);
                        found = true;
                        break;
                    }
                }

                if (!found)                                  // add new spell-spell pair if not found
                {
                    mSpellLearnSpells.insert(SpellLearnSpellMap::value_type(spell, dbc_node));
                    ++dbc_count;
                }
            }
        }
    }

    for (SpellLearnSpellEntry const* spellLearnSpell : sSpellLearnSpellStore)
    {
        if (!GetSpellInfo(spellLearnSpell->SpellID))
            continue;

        SpellLearnSpellMapBounds db_node_bounds = dbSpellLearnSpells.equal_range(spellLearnSpell->LearnSpellID);
        bool found = false;
        for (SpellLearnSpellMap::const_iterator itr = db_node_bounds.first; itr != db_node_bounds.second; ++itr)
        {
            if (int32(itr->second.Spell) == spellLearnSpell->SpellID)
            {
                TC_LOG_ERROR("sql.sql", "Found redundant record (entry: %u, SpellID: %u) in `spell_learn_spell`, spell added automatically from SpellLearnSpell.db2", spellLearnSpell->LearnSpellID, spellLearnSpell->SpellID);
                found = true;
                break;
            }
        }

        if (found)
            continue;

        // Check if it is already found in Spell.dbc, ignore silently if yes
        SpellLearnSpellMapBounds dbc_node_bounds = GetSpellLearnSpellMapBounds(spellLearnSpell->LearnSpellID);
        found = false;
        for (SpellLearnSpellMap::const_iterator itr = dbc_node_bounds.first; itr != dbc_node_bounds.second; ++itr)
        {
            if (int32(itr->second.Spell) == spellLearnSpell->SpellID)
            {
                found = true;
                break;
            }
        }

        if (found)
            continue;

        SpellLearnSpellNode dbcLearnNode;
        dbcLearnNode.Spell = spellLearnSpell->SpellID;
        dbcLearnNode.OverridesSpell = spellLearnSpell->OverridesSpellID;
        dbcLearnNode.Active = true;
        dbcLearnNode.AutoLearned = false;

        mSpellLearnSpells.insert(SpellLearnSpellMap::value_type(spellLearnSpell->LearnSpellID, dbcLearnNode));
        ++dbc_count;
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u spell learn spells, %u found in Spell.dbc in %u ms", count, dbc_count, GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellTargetPositions()
{
    uint32 oldMSTime = getMSTime();

    mSpellTargetPositions.clear();                                // need for reload case

    //                                               0   1            2      3          4          5
    QueryResult result = WorldDatabase.Query("SELECT ID, EffectIndex, MapID, PositionX, PositionY, PositionZ FROM spell_target_position");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 spell target coordinates. DB table `spell_target_position` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 spellId = fields[0].GetUInt32();
        SpellEffIndex effIndex = SpellEffIndex(fields[1].GetUInt8());

        SpellTargetPosition st;

        st.target_mapId       = fields[2].GetUInt16();
        st.target_X           = fields[3].GetFloat();
        st.target_Y           = fields[4].GetFloat();
        st.target_Z           = fields[5].GetFloat();

        MapEntry const* mapEntry = sMapStore.LookupEntry(st.target_mapId);
        if (!mapEntry)
        {
            TC_LOG_ERROR("sql.sql", "Spell (Id: %u, EffectIndex: %u) is using a non-existant MapID (ID: %u).", spellId, effIndex, st.target_mapId);
            continue;
        }

        if (st.target_X == 0 && st.target_Y == 0 && st.target_Z == 0)
        {
            TC_LOG_ERROR("sql.sql", "Spell (Id: %u, EffectIndex: %u): target coordinates not provided.", spellId, effIndex);
            continue;
        }

        SpellInfo const* spellInfo = GetSpellInfo(spellId);
        if (!spellInfo)
        {
            TC_LOG_ERROR("sql.sql", "Spell (Id: %u) listed in `spell_target_position` does not exist.", spellId);
            continue;
        }

        SpellEffectInfo const* effect = spellInfo->GetEffect(effIndex);
        if (!effect)
        {
            TC_LOG_ERROR("sql.sql", "Spell (Id: %u, EffectIndex: %u) listed in `spell_target_position` does not have an effect at index %u.", spellId, effIndex, effIndex);
            continue;
        }

        // target facing is in degrees for 6484 & 9268... (blizz sucks)
        if (effect->PositionFacing > 2 * M_PI)
            st.target_Orientation = effect->PositionFacing * float(M_PI) / 180;
        else
            st.target_Orientation = effect->PositionFacing;

        if (effect->TargetA.GetTarget() == TARGET_DEST_DB || effect->TargetB.GetTarget() == TARGET_DEST_DB)
        {
            std::pair<uint32, SpellEffIndex> key = std::make_pair(spellId, effIndex);
            mSpellTargetPositions[key] = st;
            ++count;
        }
        else
        {
            TC_LOG_ERROR("sql.sql", "Spell (Id: %u, effIndex: %u) listed in `spell_target_position` does not have a target TARGET_DEST_DB (17).", spellId, effIndex);
            continue;
        }

    } while (result->NextRow());

    /*
    // Check all spells
    for (uint32 i = 1; i < GetSpellInfoStoreSize(); ++i)
    {
        SpellInfo const* spellInfo = GetSpellInfo(i);
        if (!spellInfo)
            continue;

        for (uint8 j = 0; j < MAX_SPELL_EFFECTS; ++j)
        {
            SpellEffectInfo const* effect = spellInfo->GetEffect(j);
            if (!effect)
                continue;

            if (effect->TargetA.GetTarget() != TARGET_DEST_DB && effect->TargetB.GetTarget() != TARGET_DEST_DB)
                continue;

            if (!GetSpellTargetPosition(i, SpellEffIndex(j)))
                TC_LOG_DEBUG("spells", "Spell (Id: %u, EffectIndex: %u) does not have record in `spell_target_position`.", i, j);
        }
    }
    */

    TC_LOG_INFO("server.loading", ">> Loaded %u spell teleport coordinates in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellGroups()
{
    uint32 oldMSTime = getMSTime();

    mSpellSpellGroup.clear();                                  // need for reload case
    mSpellGroupSpell.clear();

    //                                                0     1
    QueryResult result = WorldDatabase.Query("SELECT id, spell_id FROM spell_group");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 spell group definitions. DB table `spell_group` is empty.");
        return;
    }

    std::set<uint32> groups;
    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 group_id = fields[0].GetUInt32();
        if (group_id <= SPELL_GROUP_DB_RANGE_MIN && group_id >= SPELL_GROUP_CORE_RANGE_MAX)
        {
            TC_LOG_ERROR("sql.sql", "SpellGroup id %u listed in `spell_group` is in core range, but is not defined in core!", group_id);
            continue;
        }
        int32 spell_id = fields[1].GetInt32();

        groups.insert(std::set<uint32>::value_type(group_id));
        mSpellGroupSpell.insert(SpellGroupSpellMap::value_type((SpellGroup)group_id, spell_id));

    } while (result->NextRow());

    for (SpellGroupSpellMap::iterator itr = mSpellGroupSpell.begin(); itr!= mSpellGroupSpell.end();)
    {
        if (itr->second < 0)
        {
            if (groups.find(abs(itr->second)) == groups.end())
            {
                TC_LOG_ERROR("sql.sql", "SpellGroup id %u listed in `spell_group` does not exist", abs(itr->second));
                mSpellGroupSpell.erase(itr++);
            }
            else
                ++itr;
        }
        else
        {
            SpellInfo const* spellInfo = GetSpellInfo(itr->second);

            if (!spellInfo)
            {
                TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_group` does not exist", itr->second);
                mSpellGroupSpell.erase(itr++);
            }
            else if (spellInfo->GetRank() > 1)
            {
                TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_group` is not the first rank of the spell.", itr->second);
                mSpellGroupSpell.erase(itr++);
            }
            else
                ++itr;
        }
    }

    for (std::set<uint32>::iterator groupItr = groups.begin(); groupItr != groups.end(); ++groupItr)
    {
        std::set<uint32> spells;
        GetSetOfSpellsInSpellGroup(SpellGroup(*groupItr), spells);

        for (std::set<uint32>::iterator spellItr = spells.begin(); spellItr != spells.end(); ++spellItr)
        {
            ++count;
            mSpellSpellGroup.insert(SpellSpellGroupMap::value_type(*spellItr, SpellGroup(*groupItr)));
        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u spell group definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellGroupStackRules()
{
    uint32 oldMSTime = getMSTime();

    mSpellGroupStack.clear();                                  // need for reload case

    //                                                       0         1
    QueryResult result = WorldDatabase.Query("SELECT group_id, stack_rule FROM spell_group_stack_rules");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 spell group stack rules. DB table `spell_group_stack_rules` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 group_id = fields[0].GetUInt32();
        uint8 stack_rule = fields[1].GetInt8();
        if (stack_rule >= SPELL_GROUP_STACK_RULE_MAX)
        {
            TC_LOG_ERROR("sql.sql", "SpellGroupStackRule %u listed in `spell_group_stack_rules` does not exist.", stack_rule);
            continue;
        }

        SpellGroupSpellMapBounds spellGroup = GetSpellGroupSpellMapBounds((SpellGroup)group_id);

        if (spellGroup.first == spellGroup.second)
        {
            TC_LOG_ERROR("sql.sql", "SpellGroup id %u listed in `spell_group_stack_rules` does not exist.", group_id);
            continue;
        }

        mSpellGroupStack[(SpellGroup)group_id] = (SpellGroupStackRule)stack_rule;

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u spell group stack rules in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellProcs()
{
    uint32 oldMSTime = getMSTime();

    mSpellProcMap.clear();                             // need for reload case

    //                                                     0           1                2                 3                 4                 5                 6
    QueryResult result = WorldDatabase.Query("SELECT SpellId, SchoolMask, SpellFamilyName, SpellFamilyMask0, SpellFamilyMask1, SpellFamilyMask2, SpellFamilyMask3, "
    //           7              8               9       10              11              12      13        14      15
        "ProcFlags, SpellTypeMask, SpellPhaseMask, HitMask, AttributesMask, ProcsPerMinute, Chance, Cooldown, Charges FROM spell_proc");

    uint32 count = 0;
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();

            int32 spellId = fields[0].GetInt32();

            bool allRanks = false;
            if (spellId < 0)
            {
                allRanks = true;
                spellId = -spellId;
            }

            SpellInfo const* spellInfo = GetSpellInfo(spellId);
            if (!spellInfo)
            {
                TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_proc` does not exist", spellId);
                continue;
            }

            if (allRanks)
            {
                if (!spellInfo->IsRanked())
                    TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_proc` with all ranks, but spell has no ranks.", spellId);

                if (spellInfo->GetFirstRankSpell()->Id != uint32(spellId))
                {
                    TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_proc` is not the first rank of the spell.", spellId);
                    continue;
                }
            }

            SpellProcEntry baseProcEntry;

            baseProcEntry.SchoolMask         = fields[1].GetInt8();
            baseProcEntry.SpellFamilyName    = fields[2].GetUInt16();
            baseProcEntry.SpellFamilyMask[0] = fields[3].GetUInt32();
            baseProcEntry.SpellFamilyMask[1] = fields[4].GetUInt32();
            baseProcEntry.SpellFamilyMask[2] = fields[5].GetUInt32();
            baseProcEntry.SpellFamilyMask[3] = fields[6].GetUInt32();
            baseProcEntry.ProcFlags          = fields[7].GetUInt32();
            baseProcEntry.SpellTypeMask      = fields[8].GetUInt32();
            baseProcEntry.SpellPhaseMask     = fields[9].GetUInt32();
            baseProcEntry.HitMask            = fields[10].GetUInt32();
            baseProcEntry.AttributesMask     = fields[11].GetUInt32();
            baseProcEntry.ProcsPerMinute     = fields[12].GetFloat();
            baseProcEntry.Chance             = fields[13].GetFloat();
            baseProcEntry.Cooldown           = Milliseconds(fields[14].GetUInt32());
            baseProcEntry.Charges            = fields[15].GetUInt8();

            while (spellInfo)
            {
                if (mSpellProcMap.find(spellInfo->Id) != mSpellProcMap.end())
                {
                    TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_proc` already has its first rank in the table.", spellInfo->Id);
                    break;
                }

                SpellProcEntry procEntry = SpellProcEntry(baseProcEntry);

                // take defaults from dbcs
                if (!procEntry.ProcFlags)
                    procEntry.ProcFlags = spellInfo->ProcFlags;
                if (!procEntry.Charges)
                    procEntry.Charges = spellInfo->ProcCharges;
                if (!procEntry.Chance && !procEntry.ProcsPerMinute)
                    procEntry.Chance = float(spellInfo->ProcChance);
                if (procEntry.Cooldown == Milliseconds::zero())
                    procEntry.Cooldown = Milliseconds(spellInfo->ProcCooldown);

                // validate data
                if (procEntry.SchoolMask & ~SPELL_SCHOOL_MASK_ALL)
                    TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId %u has wrong `SchoolMask` set: %u", spellInfo->Id, procEntry.SchoolMask);
                if (procEntry.SpellFamilyName && !DB2Manager::IsValidSpellFamiliyName(SpellFamilyNames(procEntry.SpellFamilyName)))
                    TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId %u has wrong `SpellFamilyName` set: %u", spellInfo->Id, procEntry.SpellFamilyName);
                if (procEntry.Chance < 0)
                {
                    TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId %u has negative value in the `Chance` field", spellInfo->Id);
                    procEntry.Chance = 0;
                }
                if (procEntry.ProcsPerMinute < 0)
                {
                    TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId %u has negative value in the `ProcsPerMinute` field", spellInfo->Id);
                    procEntry.ProcsPerMinute = 0;
                }
                if (!procEntry.ProcFlags)
                    TC_LOG_ERROR("sql.sql", "The `spell_proc` table entry for spellId %u doesn't have any `ProcFlags` value defined, proc will not be triggered.", spellInfo->Id);
                if (procEntry.SpellTypeMask & ~PROC_SPELL_TYPE_MASK_ALL)
                    TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId %u has wrong `SpellTypeMask` set: %u", spellInfo->Id, procEntry.SpellTypeMask);
                if (procEntry.SpellTypeMask && !(procEntry.ProcFlags & (SPELL_PROC_FLAG_MASK | PERIODIC_PROC_FLAG_MASK)))
                    TC_LOG_ERROR("sql.sql", "The `spell_proc` table entry for spellId %u has `SpellTypeMask` value defined, but it will not be used for the defined `ProcFlags` value.", spellInfo->Id);
                if (!procEntry.SpellPhaseMask && procEntry.ProcFlags & REQ_SPELL_PHASE_PROC_FLAG_MASK)
                    TC_LOG_ERROR("sql.sql", "The `spell_proc` table entry for spellId %u doesn't have any `SpellPhaseMask` value defined, but it is required for the defined `ProcFlags` value. Proc will not be triggered.", spellInfo->Id);
                if (procEntry.SpellPhaseMask & ~PROC_SPELL_PHASE_MASK_ALL)
                    TC_LOG_ERROR("sql.sql", "The `spell_proc` table entry for spellId %u has wrong `SpellPhaseMask` set: %u", spellInfo->Id, procEntry.SpellPhaseMask);
                if (procEntry.SpellPhaseMask && !(procEntry.ProcFlags & REQ_SPELL_PHASE_PROC_FLAG_MASK))
                    TC_LOG_ERROR("sql.sql", "The `spell_proc` table entry for spellId %u has a `SpellPhaseMask` value defined, but it will not be used for the defined `ProcFlags` value.", spellInfo->Id);
                if (procEntry.HitMask & ~PROC_HIT_MASK_ALL)
                    TC_LOG_ERROR("sql.sql", "The `spell_proc` table entry for spellId %u has wrong `HitMask` set: %u", spellInfo->Id, procEntry.HitMask);
                if (procEntry.HitMask && !(procEntry.ProcFlags & TAKEN_HIT_PROC_FLAG_MASK || (procEntry.ProcFlags & DONE_HIT_PROC_FLAG_MASK && (!procEntry.SpellPhaseMask || procEntry.SpellPhaseMask & (PROC_SPELL_PHASE_HIT | PROC_SPELL_PHASE_FINISH)))))
                    TC_LOG_ERROR("sql.sql", "The `spell_proc` table entry for spellId %u has `HitMask` value defined, but it will not be used for defined `ProcFlags` and `SpellPhaseMask` values.", spellInfo->Id);

                mSpellProcMap[spellInfo->Id] = procEntry;

                if (allRanks)
                    spellInfo = spellInfo->GetNextRankSpell();
                else
                    break;
            }
            ++count;
        } while (result->NextRow());
    }
    else
        TC_LOG_INFO("server.loading", ">> Loaded 0 spell proc conditions and data. DB table `spell_proc` is empty.");

    TC_LOG_INFO("server.loading", ">> Loaded %u spell proc conditions and data in %u ms", count, GetMSTimeDiffToNow(oldMSTime));

    // Define can trigger auras
    bool isTriggerAura[TOTAL_AURAS];
    // Triggered always, even from triggered spells
    bool isAlwaysTriggeredAura[TOTAL_AURAS];
    // SpellTypeMask to add to the proc
    uint32 spellTypeMask[TOTAL_AURAS];

    // List of auras that CAN trigger but may not exist in spell_proc
    // in most cases needed to drop charges

    // some aura types need additional checks (eg SPELL_AURA_MECHANIC_IMMUNITY needs mechanic check)
    // see AuraEffect::CheckEffectProc
    for (uint16 i = 0; i < TOTAL_AURAS; ++i)
    {
        isTriggerAura[i] = false;
        isAlwaysTriggeredAura[i] = false;
        spellTypeMask[i] = PROC_SPELL_TYPE_MASK_ALL;
    }

    isTriggerAura[SPELL_AURA_DUMMY] = true;
    isTriggerAura[SPELL_AURA_MOD_CONFUSE] = true;
    isTriggerAura[SPELL_AURA_MOD_THREAT] = true;
    isTriggerAura[SPELL_AURA_MOD_STUN] = true; // Aura does not have charges but needs to be removed on trigger
    isTriggerAura[SPELL_AURA_MOD_DAMAGE_DONE] = true;
    isTriggerAura[SPELL_AURA_MOD_DAMAGE_TAKEN] = true;
    isTriggerAura[SPELL_AURA_MOD_RESISTANCE] = true;
    isTriggerAura[SPELL_AURA_MOD_STEALTH] = true;
    isTriggerAura[SPELL_AURA_MOD_FEAR] = true; // Aura does not have charges but needs to be removed on trigger
    isTriggerAura[SPELL_AURA_MOD_ROOT] = true;
    isTriggerAura[SPELL_AURA_TRANSFORM] = true;
    isTriggerAura[SPELL_AURA_REFLECT_SPELLS] = true;
    isTriggerAura[SPELL_AURA_DAMAGE_IMMUNITY] = true;
    isTriggerAura[SPELL_AURA_PROC_TRIGGER_SPELL] = true;
    isTriggerAura[SPELL_AURA_PROC_TRIGGER_DAMAGE] = true;
    isTriggerAura[SPELL_AURA_MOD_CASTING_SPEED_NOT_STACK] = true;
    isTriggerAura[SPELL_AURA_SCHOOL_ABSORB] = true; // Savage Defense untested
    isTriggerAura[SPELL_AURA_MOD_POWER_COST_SCHOOL_PCT] = true;
    isTriggerAura[SPELL_AURA_MOD_POWER_COST_SCHOOL] = true;
    isTriggerAura[SPELL_AURA_REFLECT_SPELLS_SCHOOL] = true;
    isTriggerAura[SPELL_AURA_MECHANIC_IMMUNITY] = true;
    isTriggerAura[SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN] = true;
    isTriggerAura[SPELL_AURA_SPELL_MAGNET] = true;
    isTriggerAura[SPELL_AURA_MOD_ATTACK_POWER] = true;
    isTriggerAura[SPELL_AURA_MOD_POWER_REGEN_PERCENT] = true;
    isTriggerAura[SPELL_AURA_INTERCEPT_MELEE_RANGED_ATTACKS] = true;
    isTriggerAura[SPELL_AURA_OVERRIDE_CLASS_SCRIPTS] = true;
    isTriggerAura[SPELL_AURA_MOD_MECHANIC_RESISTANCE] = true;
    isTriggerAura[SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS] = true;
    isTriggerAura[SPELL_AURA_MOD_MELEE_HASTE] = true;
    isTriggerAura[SPELL_AURA_MOD_MELEE_HASTE_3] = true;
    isTriggerAura[SPELL_AURA_MOD_ATTACKER_MELEE_HIT_CHANCE] = true;
    isTriggerAura[SPELL_AURA_PROC_TRIGGER_SPELL_WITH_VALUE] = true;
    isTriggerAura[SPELL_AURA_MOD_SPELL_DAMAGE_FROM_CASTER] = true;
    isTriggerAura[SPELL_AURA_MOD_SPELL_CRIT_CHANCE] = true;
    isTriggerAura[SPELL_AURA_ABILITY_IGNORE_AURASTATE] = true;
    isTriggerAura[SPELL_AURA_MOD_ROOT_2] = true;

    isAlwaysTriggeredAura[SPELL_AURA_OVERRIDE_CLASS_SCRIPTS] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_STEALTH] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_CONFUSE] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_FEAR] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_ROOT] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_STUN] = true;
    isAlwaysTriggeredAura[SPELL_AURA_TRANSFORM] = true;
    isAlwaysTriggeredAura[SPELL_AURA_SPELL_MAGNET] = true;
    isAlwaysTriggeredAura[SPELL_AURA_SCHOOL_ABSORB] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_STEALTH] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_ROOT_2] = true;

    spellTypeMask[SPELL_AURA_MOD_STEALTH] = PROC_SPELL_TYPE_DAMAGE | PROC_SPELL_TYPE_NO_DMG_HEAL;
    spellTypeMask[SPELL_AURA_MOD_CONFUSE] = PROC_SPELL_TYPE_DAMAGE;
    spellTypeMask[SPELL_AURA_MOD_FEAR] = PROC_SPELL_TYPE_DAMAGE;
    spellTypeMask[SPELL_AURA_MOD_ROOT] = PROC_SPELL_TYPE_DAMAGE;
    spellTypeMask[SPELL_AURA_MOD_ROOT_2] = PROC_SPELL_TYPE_DAMAGE;
    spellTypeMask[SPELL_AURA_MOD_STUN] = PROC_SPELL_TYPE_DAMAGE;
    spellTypeMask[SPELL_AURA_TRANSFORM] = PROC_SPELL_TYPE_DAMAGE;

    // This generates default procs to retain compatibility with previous proc system
    TC_LOG_INFO("server.loading", "Generating spell proc data from SpellMap...");
    count = 0;
    oldMSTime = getMSTime();

    for (SpellInfo const* spellInfo : mSpellInfoMap)
    {
        if (!spellInfo)
            continue;

        // Data already present in DB, overwrites default proc
        if (mSpellProcMap.find(spellInfo->Id) != mSpellProcMap.end())
            continue;

        // Nothing to do if no flags set
        if (!spellInfo->ProcFlags)
            continue;

        bool addTriggerFlag = false;
        uint32 procSpellTypeMask = PROC_SPELL_TYPE_NONE;
        for (SpellEffectInfo const* effect : spellInfo->GetEffectsForDifficulty(DIFFICULTY_NONE))
        {
            if (!effect || !effect->IsEffect())
                continue;

            uint32 auraName = effect->ApplyAuraName;
            if (!auraName)
                continue;

            if (!isTriggerAura[auraName])
                continue;

            procSpellTypeMask |= spellTypeMask[auraName];
            if (isAlwaysTriggeredAura[auraName])
                addTriggerFlag = true;

            // many proc auras with taken procFlag mask don't have attribute "can proc with triggered"
            // they should proc nevertheless (example mage armor spells with judgement)
            if (!addTriggerFlag && (spellInfo->ProcFlags & TAKEN_HIT_PROC_FLAG_MASK) != 0)
            {
                switch (auraName)
                {
                    case SPELL_AURA_PROC_TRIGGER_SPELL:
                    case SPELL_AURA_PROC_TRIGGER_DAMAGE:
                        addTriggerFlag = true;
                        break;
                    default:
                        break;
                }
            }
            break;
        }

        if (!procSpellTypeMask)
        {
            for (SpellEffectInfo const* effectInfo : spellInfo->GetEffectsForDifficulty(DIFFICULTY_NONE))
            {
                if (effectInfo && effectInfo->IsAura())
                {
                    TC_LOG_ERROR("sql.sql", "Spell Id %u has DBC ProcFlags %u, but it's of non-proc aura type, it probably needs an entry in `spell_proc` table to be handled correctly.", spellInfo->Id, spellInfo->ProcFlags);
                    break;
                }
            }

            continue;
        }

        SpellProcEntry procEntry;
        procEntry.SchoolMask      = 0;
        procEntry.ProcFlags = spellInfo->ProcFlags;
        procEntry.SpellFamilyName = 0;
        for (SpellEffectInfo const* effect : spellInfo->GetEffectsForDifficulty(DIFFICULTY_NONE))
            if (effect && effect->IsEffect() && isTriggerAura[effect->ApplyAuraName])
                procEntry.SpellFamilyMask |= effect->SpellClassMask;

        if (procEntry.SpellFamilyMask)
            procEntry.SpellFamilyName = spellInfo->SpellFamilyName;

        procEntry.SpellTypeMask   = procSpellTypeMask;
        procEntry.SpellPhaseMask  = PROC_SPELL_PHASE_HIT;
        procEntry.HitMask         = PROC_HIT_NONE; // uses default proc @see SpellMgr::CanSpellTriggerProcOnEvent

        // Reflect auras should only proc off reflects
        for (SpellEffectInfo const* effect : spellInfo->GetEffectsForDifficulty(DIFFICULTY_NONE))
        {
            if (effect && (effect->IsAura(SPELL_AURA_REFLECT_SPELLS) || effect->IsAura(SPELL_AURA_REFLECT_SPELLS_SCHOOL)))
            {
                procEntry.HitMask = PROC_HIT_REFLECT;
                break;
            }
        }

        procEntry.AttributesMask  = 0;
        if (spellInfo->ProcFlags & PROC_FLAG_KILL)
            procEntry.AttributesMask |= PROC_ATTR_REQ_EXP_OR_HONOR;
        if (addTriggerFlag)
            procEntry.AttributesMask |= PROC_ATTR_TRIGGERED_CAN_PROC;

        procEntry.ProcsPerMinute  = 0;
        procEntry.Chance          = spellInfo->ProcChance;
        procEntry.Cooldown        = Milliseconds(spellInfo->ProcCooldown);
        procEntry.Charges         = spellInfo->ProcCharges;

        mSpellProcMap[spellInfo->Id] = procEntry;
        ++count;
    }

    TC_LOG_INFO("server.loading", ">> Generated spell proc data for %u spells in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellThreats()
{
    uint32 oldMSTime = getMSTime();

    mSpellThreatMap.clear();                                // need for reload case

    //                                                0      1        2       3
    QueryResult result = WorldDatabase.Query("SELECT entry, flatMod, pctMod, apPctMod FROM spell_threat");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 aggro generating spells. DB table `spell_threat` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 entry = fields[0].GetUInt32();

        if (!GetSpellInfo(entry))
        {
            TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_threat` does not exist.", entry);
            continue;
        }

        SpellThreatEntry ste;
        ste.flatMod  = fields[1].GetInt32();
        ste.pctMod   = fields[2].GetFloat();
        ste.apPctMod = fields[3].GetFloat();

        mSpellThreatMap[entry] = ste;
        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u SpellThreatEntries in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSkillLineAbilityMap()
{
    uint32 oldMSTime = getMSTime();

    mSkillLineAbilityMap.clear();

    uint32 count = 0;

    for (uint32 i = 0; i < sSkillLineAbilityStore.GetNumRows(); ++i)
    {
        SkillLineAbilityEntry const* SkillInfo = sSkillLineAbilityStore.LookupEntry(i);
        if (!SkillInfo)
            continue;

        mSkillLineAbilityMap.insert(SkillLineAbilityMap::value_type(SkillInfo->Spell, SkillInfo));
        ++count;
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u SkillLineAbility MultiMap Data in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellPetAuras()
{
    uint32 oldMSTime = getMSTime();

    mSpellPetAuraMap.clear();                                  // need for reload case

    //                                                  0       1       2    3
    QueryResult result = WorldDatabase.Query("SELECT spell, effectId, pet, aura FROM spell_pet_auras");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 spell pet auras. DB table `spell_pet_auras` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 spell = fields[0].GetUInt32();
        uint8 eff = fields[1].GetUInt8();
        uint32 pet = fields[2].GetUInt32();
        uint32 aura = fields[3].GetUInt32();

        SpellPetAuraMap::iterator itr = mSpellPetAuraMap.find((spell<<8) + eff);
        if (itr != mSpellPetAuraMap.end())
            itr->second.AddAura(pet, aura);
        else
        {
            SpellInfo const* spellInfo = GetSpellInfo(spell);
            if (!spellInfo)
            {
                TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_pet_auras` does not exist.", spell);
                continue;
            }
            SpellEffectInfo const* effect = spellInfo->GetEffect(eff);
            if (!effect)
            {
                TC_LOG_ERROR("spells", "The spell %u listed in `spell_pet_auras` does not have any effect at index %u", spell, uint32(eff));
                continue;
            }

            if (effect->Effect != SPELL_EFFECT_DUMMY &&
               (effect->Effect != SPELL_EFFECT_APPLY_AURA ||
                effect->ApplyAuraName != SPELL_AURA_DUMMY))
            {
                TC_LOG_ERROR("spells", "Spell %u listed in `spell_pet_auras` does not have any dummy aura or dummy effect", spell);
                continue;
            }

            SpellInfo const* spellInfo2 = GetSpellInfo(aura);
            if (!spellInfo2)
            {
                TC_LOG_ERROR("sql.sql", "The aura %u listed in `spell_pet_auras` does not exist.", aura);
                continue;
            }

            PetAura pa(pet, aura, effect->TargetA.GetTarget() == TARGET_UNIT_PET, effect->CalcValue());
            mSpellPetAuraMap[(spell<<8) + eff] = pa;
        }

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u spell pet auras in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

// Fill custom data about enchancments
void SpellMgr::LoadEnchantCustomAttr()
{
    uint32 oldMSTime = getMSTime();

    uint32 size = sSpellItemEnchantmentStore.GetNumRows();
    mEnchantCustomAttr.resize(size);

    for (uint32 i = 0; i < size; ++i)
       mEnchantCustomAttr[i] = 0;

    uint32 count = 0;
    for (uint32 i = 0; i < GetSpellInfoStoreSize(); ++i)
    {
        SpellInfo const* spellInfo = GetSpellInfo(i);
        if (!spellInfo)
            continue;

        /// @todo find a better check
        if (!spellInfo->HasAttribute(SPELL_ATTR2_PRESERVE_ENCHANT_IN_ARENA) || !spellInfo->HasAttribute(SPELL_ATTR0_NOT_SHAPESHIFT))
            continue;

        for (SpellEffectInfo const* effect : spellInfo->GetEffectsForDifficulty(DIFFICULTY_NONE))
        {
            if (effect && effect->Effect == SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY)
            {
                uint32 enchId = effect->MiscValue;
                SpellItemEnchantmentEntry const* ench = sSpellItemEnchantmentStore.LookupEntry(enchId);
                if (!ench)
                    continue;
                mEnchantCustomAttr[enchId] = true;
                ++count;
                break;
            }
        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u custom enchant attributes in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellEnchantProcData()
{
    uint32 oldMSTime = getMSTime();

    mSpellEnchantProcEventMap.clear();                             // need for reload case

    //                                                  0         1           2         3
    QueryResult result = WorldDatabase.Query("SELECT entry, customChance, PPMChance, procEx FROM spell_enchant_proc_data");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 spell enchant proc event conditions. DB table `spell_enchant_proc_data` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 enchantId = fields[0].GetUInt32();

        SpellItemEnchantmentEntry const* ench = sSpellItemEnchantmentStore.LookupEntry(enchantId);
        if (!ench)
        {
            TC_LOG_ERROR("sql.sql", "The enchancment %u listed in `spell_enchant_proc_data` does not exist.", enchantId);
            continue;
        }

        SpellEnchantProcEntry spe;

        spe.customChance = fields[1].GetUInt32();
        spe.PPMChance = fields[2].GetFloat();
        spe.procEx = fields[3].GetUInt32();

        mSpellEnchantProcEventMap[enchantId] = spe;

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u enchant proc data definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellLinked()
{
    uint32 oldMSTime = getMSTime();

    mSpellLinkedMap.clear();    // need for reload case

    //                                                0              1             2
    QueryResult result = WorldDatabase.Query("SELECT spell_trigger, spell_effect, type FROM spell_linked_spell");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 linked spells. DB table `spell_linked_spell` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        int32 trigger = fields[0].GetInt32();
        int32 effect = fields[1].GetInt32();
        int32 type = fields[2].GetUInt8();

        SpellInfo const* spellInfo = GetSpellInfo(abs(trigger));
        if (!spellInfo)
        {
            TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_linked_spell` does not exist.", abs(trigger));
            continue;
        }

        if (effect >= 0)
            for (SpellEffectInfo const* eff : spellInfo->GetEffectsForDifficulty(DIFFICULTY_NONE))
            {
                if (eff && eff->CalcValue() == abs(effect))
                    TC_LOG_ERROR("sql.sql", "The spell %u Effect: %u listed in `spell_linked_spell` has same bp%u like effect (possible hack)", abs(trigger), abs(effect), eff->EffectIndex);
            }

        spellInfo = GetSpellInfo(abs(effect));
        if (!spellInfo)
        {
            TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_linked_spell` does not exist.", abs(effect));
            continue;
        }

        if (type) //we will find a better way when more types are needed
        {
            if (trigger > 0)
                trigger += SPELL_LINKED_MAX_SPELLS * type;
            else
                trigger -= SPELL_LINKED_MAX_SPELLS * type;
        }
        mSpellLinkedMap[trigger].push_back(effect);

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u linked spells in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadPetLevelupSpellMap()
{
    uint32 oldMSTime = getMSTime();

    mPetLevelupSpellMap.clear();                                   // need for reload case

    uint32 count = 0;
    uint32 family_count = 0;

    for (uint32 i = 0; i < sCreatureFamilyStore.GetNumRows(); ++i)
    {
        CreatureFamilyEntry const* creatureFamily = sCreatureFamilyStore.LookupEntry(i);
        if (!creatureFamily)                                     // not exist
            continue;

        for (uint8 j = 0; j < 2; ++j)
        {
            if (!creatureFamily->SkillLine[j])
                continue;

            for (uint32 k = 0; k < sSkillLineAbilityStore.GetNumRows(); ++k)
            {
                SkillLineAbilityEntry const* skillLine = sSkillLineAbilityStore.LookupEntry(k);
                if (!skillLine)
                    continue;

                //if (skillLine->skillId != creatureFamily->SkillLine[0] &&
                //    (!creatureFamily->SkillLine[1] || skillLine->skillId != creatureFamily->SkillLine[1]))
                //    continue;

                if (skillLine->SkillLine != creatureFamily->SkillLine[j])
                    continue;

                if (skillLine->AcquireMethod != SKILL_LINE_ABILITY_LEARNED_ON_SKILL_LEARN)
                    continue;

                SpellInfo const* spell = GetSpellInfo(skillLine->Spell);
                if (!spell) // not exist or triggered or talent
                    continue;

                if (!spell->SpellLevel)
                    continue;

                PetLevelupSpellSet& spellSet = mPetLevelupSpellMap[i];
                if (spellSet.empty())
                    ++family_count;

                spellSet.insert(PetLevelupSpellSet::value_type(spell->SpellLevel, spell->Id));
                ++count;
            }
        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u pet levelup and default spells for %u families in %u ms", count, family_count, GetMSTimeDiffToNow(oldMSTime));
}

bool LoadPetDefaultSpells_helper(CreatureTemplate const* cInfo, PetDefaultSpellsEntry& petDefSpells)
{
    // skip empty list;
    bool have_spell = false;
    for (uint8 j = 0; j < MAX_CREATURE_SPELL_DATA_SLOT; ++j)
    {
        if (petDefSpells.spellid[j])
        {
            have_spell = true;
            break;
        }
    }
    if (!have_spell)
        return false;

    // remove duplicates with levelupSpells if any
    if (PetLevelupSpellSet const* levelupSpells = cInfo->family ? sSpellMgr->GetPetLevelupSpellList(cInfo->family) : NULL)
    {
        for (uint8 j = 0; j < MAX_CREATURE_SPELL_DATA_SLOT; ++j)
        {
            if (!petDefSpells.spellid[j])
                continue;

            for (PetLevelupSpellSet::const_iterator itr = levelupSpells->begin(); itr != levelupSpells->end(); ++itr)
            {
                if (itr->second == petDefSpells.spellid[j])
                {
                    petDefSpells.spellid[j] = 0;
                    break;
                }
            }
        }
    }

    // skip empty list;
    have_spell = false;
    for (uint8 j = 0; j < MAX_CREATURE_SPELL_DATA_SLOT; ++j)
    {
        if (petDefSpells.spellid[j])
        {
            have_spell = true;
            break;
        }
    }

    return have_spell;
}

void SpellMgr::LoadPetDefaultSpells()
{
    uint32 oldMSTime = getMSTime();

    mPetDefaultSpellsMap.clear();

    uint32 countCreature = 0;

    TC_LOG_INFO("server.loading", "Loading summonable creature templates...");
    oldMSTime = getMSTime();

    // different summon spells
    for (uint32 i = 0; i < GetSpellInfoStoreSize(); ++i)
    {
        SpellInfo const* spellEntry = GetSpellInfo(i);
        if (!spellEntry)
            continue;

        for (SpellEffectInfo const* effect : spellEntry->GetEffectsForDifficulty(DIFFICULTY_NONE))
        {
            if (effect && (effect->Effect == SPELL_EFFECT_SUMMON || effect->Effect == SPELL_EFFECT_SUMMON_PET))
            {
                uint32 creature_id = effect->MiscValue;
                CreatureTemplate const* cInfo = sObjectMgr->GetCreatureTemplate(creature_id);
                if (!cInfo)
                    continue;

                // get default pet spells from creature_template
                int32 petSpellsId = cInfo->Entry;
                if (mPetDefaultSpellsMap.find(cInfo->Entry) != mPetDefaultSpellsMap.end())
                    continue;

                PetDefaultSpellsEntry petDefSpells;
                for (uint8 j = 0; j < MAX_CREATURE_SPELL_DATA_SLOT; ++j)
                    petDefSpells.spellid[j] = cInfo->spells[j];

                if (LoadPetDefaultSpells_helper(cInfo, petDefSpells))
                {
                    mPetDefaultSpellsMap[petSpellsId] = petDefSpells;
                    ++countCreature;
                }
            }
        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u summonable creature templates in %u ms", countCreature, GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellAreas()
{
    uint32 oldMSTime = getMSTime();

    mSpellAreaMap.clear();                                  // need for reload case
    mSpellAreaForQuestMap.clear();
    mSpellAreaForQuestEndMap.clear();
    mSpellAreaForAuraMap.clear();

    //                                                  0     1         2              3               4                 5          6          7       8         9
    QueryResult result = WorldDatabase.Query("SELECT spell, area, quest_start, quest_start_status, quest_end_status, quest_end, aura_spell, racemask, gender, flags FROM spell_area");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 spell area requirements. DB table `spell_area` is empty.");

        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 spell = fields[0].GetUInt32();
        SpellArea spellArea;
        spellArea.spellId             = spell;
        spellArea.areaId              = fields[1].GetUInt32();
        spellArea.questStart          = fields[2].GetUInt32();
        spellArea.questStartStatus    = fields[3].GetUInt32();
        spellArea.questEndStatus      = fields[4].GetUInt32();
        spellArea.questEnd            = fields[5].GetUInt32();
        spellArea.auraSpell           = fields[6].GetInt32();
        spellArea.raceMask            = fields[7].GetUInt32();
        spellArea.gender              = Gender(fields[8].GetUInt8());
        spellArea.flags               = fields[9].GetUInt8();

        if (SpellInfo const* spellInfo = GetSpellInfo(spell))
        {
            if (spellArea.flags & SPELL_AREA_FLAG_AUTOCAST)
                const_cast<SpellInfo*>(spellInfo)->Attributes |= SPELL_ATTR0_CANT_CANCEL;
        }
        else
        {
            TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_area` does not exist", spell);
            continue;
        }

        {
            bool ok = true;
            SpellAreaMapBounds sa_bounds = GetSpellAreaMapBounds(spellArea.spellId);
            for (SpellAreaMap::const_iterator itr = sa_bounds.first; itr != sa_bounds.second; ++itr)
            {
                if (spellArea.spellId != itr->second.spellId)
                    continue;
                if (spellArea.areaId != itr->second.areaId)
                    continue;
                if (spellArea.questStart != itr->second.questStart)
                    continue;
                if (spellArea.auraSpell != itr->second.auraSpell)
                    continue;
                if ((spellArea.raceMask & itr->second.raceMask) == 0)
                    continue;
                if (spellArea.gender != itr->second.gender)
                    continue;

                // duplicate by requirements
                ok = false;
                break;
            }

            if (!ok)
            {
                TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_area` is already listed with similar requirements.", spell);
                continue;
            }
        }

        if (spellArea.areaId && !sAreaTableStore.LookupEntry(spellArea.areaId))
        {
            TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_area` has a wrong area (%u) requirement.", spell, spellArea.areaId);
            continue;
        }

        if (spellArea.questStart && !sObjectMgr->GetQuestTemplate(spellArea.questStart))
        {
            TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_area` has a wrong start quest (%u) requirement.", spell, spellArea.questStart);
            continue;
        }

        if (spellArea.questEnd)
        {
            if (!sObjectMgr->GetQuestTemplate(spellArea.questEnd))
            {
                TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_area` has a wrong ending quest (%u) requirement.", spell, spellArea.questEnd);
                continue;
            }
        }

        if (spellArea.auraSpell)
        {
            SpellInfo const* spellInfo = GetSpellInfo(abs(spellArea.auraSpell));
            if (!spellInfo)
            {
                TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_area` has wrong aura spell (%u) requirement", spell, abs(spellArea.auraSpell));
                continue;
            }

            if (uint32(abs(spellArea.auraSpell)) == spellArea.spellId)
            {
                TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_area` has aura spell (%u) requirement for itself", spell, abs(spellArea.auraSpell));
                continue;
            }

            // not allow autocast chains by auraSpell field (but allow use as alternative if not present)
            if (spellArea.flags & SPELL_AREA_FLAG_AUTOCAST && spellArea.auraSpell > 0)
            {
                bool chain = false;
                SpellAreaForAuraMapBounds saBound = GetSpellAreaForAuraMapBounds(spellArea.spellId);
                for (SpellAreaForAuraMap::const_iterator itr = saBound.first; itr != saBound.second; ++itr)
                {
                    if (itr->second->flags & SPELL_AREA_FLAG_AUTOCAST && itr->second->auraSpell > 0)
                    {
                        chain = true;
                        break;
                    }
                }

                if (chain)
                {
                    TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_area` has the aura spell (%u) requirement that it autocasts itself from the aura.", spell, spellArea.auraSpell);
                    continue;
                }

                SpellAreaMapBounds saBound2 = GetSpellAreaMapBounds(spellArea.auraSpell);
                for (SpellAreaMap::const_iterator itr2 = saBound2.first; itr2 != saBound2.second; ++itr2)
                {
                    if (itr2->second.flags & SPELL_AREA_FLAG_AUTOCAST && itr2->second.auraSpell > 0)
                    {
                        chain = true;
                        break;
                    }
                }

                if (chain)
                {
                    TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_area` has the aura spell (%u) requirement that the spell itself autocasts from the aura.", spell, spellArea.auraSpell);
                    continue;
                }
            }
        }

        if (spellArea.raceMask && (spellArea.raceMask & RACEMASK_ALL_PLAYABLE) == 0)
        {
            TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_area` has wrong race mask (%u) requirement.", spell, spellArea.raceMask);
            continue;
        }

        if (spellArea.gender != GENDER_NONE && spellArea.gender != GENDER_FEMALE && spellArea.gender != GENDER_MALE)
        {
            TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_area` has wrong gender (%u) requirement.", spell, spellArea.gender);
            continue;
        }

        SpellArea const* sa = &mSpellAreaMap.insert(SpellAreaMap::value_type(spell, spellArea))->second;

        // for search by current zone/subzone at zone/subzone change
        if (spellArea.areaId)
            mSpellAreaForAreaMap.insert(SpellAreaForAreaMap::value_type(spellArea.areaId, sa));

        // for search at quest start/reward
        if (spellArea.questStart)
            mSpellAreaForQuestMap.insert(SpellAreaForQuestMap::value_type(spellArea.questStart, sa));

        // for search at quest start/reward
        if (spellArea.questEnd)
            mSpellAreaForQuestEndMap.insert(SpellAreaForQuestMap::value_type(spellArea.questEnd, sa));

        // for search at aura apply
        if (spellArea.auraSpell)
            mSpellAreaForAuraMap.insert(SpellAreaForAuraMap::value_type(abs(spellArea.auraSpell), sa));

        if (spellArea.areaId && spellArea.questStart)
            mSpellAreaForQuestAreaMap.insert(SpellAreaForQuestAreaMap::value_type(std::pair<uint32, uint32>(spellArea.areaId, spellArea.questStart), sa));

        if (spellArea.areaId && spellArea.questEnd)
            mSpellAreaForQuestAreaMap.insert(SpellAreaForQuestAreaMap::value_type(std::pair<uint32, uint32>(spellArea.areaId, spellArea.questEnd), sa));

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u spell area requirements in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

typedef std::vector<SpellEffectEntry const*> SpellEffectVector;

void SpellMgr::LoadSpellInfoStore()
{
    uint32 oldMSTime = getMSTime();

    UnloadSpellInfoStore();
    mSpellInfoMap.resize(sSpellStore.GetNumRows(), NULL);
    std::unordered_map<uint32, SpellInfoLoadHelper> loadData;

    std::unordered_map<int32, SpellEffectEntryMap> effectsBySpell;
    std::unordered_map<uint32, SpellVisualMap> visualsBySpell;

    for (SpellEffectEntry const* effect : sSpellEffectStore)
    {
        ASSERT(effect->EffectIndex < MAX_SPELL_EFFECTS, "MAX_SPELL_EFFECTS must be at least %d", effect->EffectIndex + 1);
        ASSERT(effect->Effect < TOTAL_SPELL_EFFECTS, "TOTAL_SPELL_EFFECTS must be at least %u", effect->Effect + 1);
        ASSERT(effect->EffectAura < int32(TOTAL_AURAS), "TOTAL_AURAS must be at least %d", effect->EffectAura + 1);
        ASSERT(effect->ImplicitTarget[0] < TOTAL_SPELL_TARGETS, "TOTAL_SPELL_TARGETS must be at least %u", effect->ImplicitTarget[0] + 1);
        ASSERT(effect->ImplicitTarget[1] < TOTAL_SPELL_TARGETS, "TOTAL_SPELL_TARGETS must be at least %u", effect->ImplicitTarget[1] + 1);

        SpellEffectEntryVector& effectsForDifficulty = effectsBySpell[effect->SpellID][effect->DifficultyID];
        if (effectsForDifficulty.size() <= std::size_t(effect->EffectIndex))
            effectsForDifficulty.resize(std::size_t(effect->EffectIndex + 1));

        effectsForDifficulty[effect->EffectIndex] = effect;
    }

    for (SpellAuraOptionsEntry const* auraOptions : sSpellAuraOptionsStore)
        if (!auraOptions->DifficultyID)    // TODO: implement
            loadData[auraOptions->SpellID].AuraOptions = auraOptions;

    for (SpellAuraRestrictionsEntry const* auraRestrictions : sSpellAuraRestrictionsStore)
        if (!auraRestrictions->DifficultyID)    // TODO: implement
            loadData[auraRestrictions->SpellID].AuraRestrictions = auraRestrictions;

    for (SpellCastingRequirementsEntry const* castingRequirements : sSpellCastingRequirementsStore)
        loadData[castingRequirements->SpellID].CastingRequirements = castingRequirements;

    for (SpellCategoriesEntry const* categories : sSpellCategoriesStore)
        if (!categories->DifficultyID)  // TODO: implement
            loadData[categories->SpellID].Categories = categories;

    for (SpellClassOptionsEntry const* classOptions : sSpellClassOptionsStore)
        loadData[classOptions->SpellID].ClassOptions = classOptions;

    for (SpellCooldownsEntry const* cooldowns : sSpellCooldownsStore)
        if (!cooldowns->DifficultyID)   // TODO: implement
            loadData[cooldowns->SpellID].Cooldowns = cooldowns;

    for (SpellEquippedItemsEntry const* equippedItems : sSpellEquippedItemsStore)
        loadData[equippedItems->SpellID].EquippedItems = equippedItems;

    for (SpellInterruptsEntry const* interrupts : sSpellInterruptsStore)
        if (!interrupts->DifficultyID)  // TODO: implement
            loadData[interrupts->SpellID].Interrupts = interrupts;

    for (SpellLevelsEntry const* levels : sSpellLevelsStore)
        if (!levels->DifficultyID)  // TODO: implement
            loadData[levels->SpellID].Levels = levels;

    for (SpellMiscEntry const* misc : sSpellMiscStore)
        if (!misc->DifficultyID)
            loadData[misc->SpellID].Misc = misc;

    for (SpellReagentsEntry const* reagents : sSpellReagentsStore)
        loadData[reagents->SpellID].Reagents = reagents;

    for (SpellScalingEntry const* scaling : sSpellScalingStore)
        loadData[scaling->SpellID].Scaling = scaling;

    for (SpellShapeshiftEntry const* shapeshift : sSpellShapeshiftStore)
        loadData[shapeshift->SpellID].Shapeshift = shapeshift;

    for (SpellTargetRestrictionsEntry const* targetRestrictions : sSpellTargetRestrictionsStore)
        if (!targetRestrictions->DifficultyID)  // TODO: implement
            loadData[targetRestrictions->SpellID].TargetRestrictions = targetRestrictions;

    for (SpellTotemsEntry const* totems : sSpellTotemsStore)
        loadData[totems->SpellID].Totems = totems;

    for (SpellXSpellVisualEntry const* visual : sSpellXSpellVisualStore)
        visualsBySpell[visual->SpellID][visual->DifficultyID].push_back(visual);

    for (uint32 i = 0; i < sSpellStore.GetNumRows(); ++i)
    {
        if (SpellEntry const* spellEntry = sSpellStore.LookupEntry(i))
        {
            loadData[i].Entry = spellEntry;
            mSpellInfoMap[i] = new SpellInfo(loadData[i], effectsBySpell[i], std::move(visualsBySpell[i]));
        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded SpellInfo store in %u ms", GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::UnloadSpellInfoStore()
{
    for (uint32 i = 0; i < GetSpellInfoStoreSize(); ++i)
        delete mSpellInfoMap[i];

    mSpellInfoMap.clear();
}

void SpellMgr::UnloadSpellInfoImplicitTargetConditionLists()
{
    for (uint32 i = 0; i < GetSpellInfoStoreSize(); ++i)
        if (mSpellInfoMap[i])
            mSpellInfoMap[i]->_UnloadImplicitTargetConditionLists();
}

void SpellMgr::LoadSpellInfoCustomAttributes()
{
    uint32 oldMSTime = getMSTime();
    uint32 oldMSTime2 = oldMSTime;
    SpellInfo* spellInfo = NULL;

    QueryResult result = WorldDatabase.Query("SELECT entry, attributes FROM spell_custom_attr");

    if (!result)
        TC_LOG_INFO("server.loading", ">> Loaded 0 spell custom attributes from DB. DB table `spell_custom_attr` is empty.");
    else
    {
        uint32 count = 0;
        do
        {
            Field* fields = result->Fetch();

            uint32 spellId = fields[0].GetUInt32();
            uint32 attributes = fields[1].GetUInt32();

            spellInfo = _GetSpellInfo(spellId);
            if (!spellInfo)
            {
                TC_LOG_ERROR("sql.sql", "Table `spell_custom_attr` has wrong spell (entry: %u), ignored.", spellId);
                continue;
            }

            // TODO: validate attributes
            if (attributes & SPELL_ATTR0_CU_SHARE_DAMAGE)
            {
                if (!spellInfo->HasEffect(SPELL_EFFECT_SCHOOL_DAMAGE))
                {
                    TC_LOG_ERROR("sql.sql", "Spell %u listed in table `spell_custom_attr` with SPELL_ATTR0_CU_SHARE_DAMAGE has no SPELL_EFFECT_SCHOOL_DAMAGE, ignored.", spellId);
                    continue;
                }
            }

            spellInfo->AttributesCu |= attributes;
            ++count;
        } while (result->NextRow());

        TC_LOG_INFO("server.loading", ">> Loaded %u spell custom attributes from DB in %u ms", count, GetMSTimeDiffToNow(oldMSTime2));
    }

    std::set<uint32> talentSpells;
    for (uint32 i = 0; i < sTalentStore.GetNumRows(); ++i)
        if (TalentEntry const* talentInfo = sTalentStore.LookupEntry(i))
            talentSpells.insert(talentInfo->SpellID);

    for (uint32 i = 0; i < GetSpellInfoStoreSize(); ++i)
    {
        spellInfo = mSpellInfoMap[i];
        if (!spellInfo)
            continue;

        for (SpellEffectInfo const* effect : spellInfo->GetEffectsForDifficulty(DIFFICULTY_NONE))
        {
            if (!effect)
                continue;

            switch (effect->ApplyAuraName)
            {
                case SPELL_AURA_PERIODIC_HEAL:
                case SPELL_AURA_PERIODIC_DAMAGE:
                case SPELL_AURA_PERIODIC_DAMAGE_PERCENT:
                case SPELL_AURA_PERIODIC_LEECH:
                case SPELL_AURA_PERIODIC_MANA_LEECH:
                case SPELL_AURA_PERIODIC_HEALTH_FUNNEL:
                case SPELL_AURA_PERIODIC_ENERGIZE:
                case SPELL_AURA_OBS_MOD_HEALTH:
                case SPELL_AURA_OBS_MOD_POWER:
                case SPELL_AURA_POWER_BURN:
                    spellInfo->AttributesCu |= SPELL_ATTR0_CU_NO_INITIAL_THREAT;
                    break;
            }

            switch (effect->Effect)
            {
                case SPELL_EFFECT_SCHOOL_DAMAGE:
                case SPELL_EFFECT_WEAPON_DAMAGE:
                case SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL:
                case SPELL_EFFECT_NORMALIZED_WEAPON_DMG:
                case SPELL_EFFECT_WEAPON_PERCENT_DAMAGE:
                case SPELL_EFFECT_HEAL:
                    spellInfo->AttributesCu |= SPELL_ATTR0_CU_DIRECT_DAMAGE;
                    break;
                case SPELL_EFFECT_POWER_DRAIN:
                case SPELL_EFFECT_POWER_BURN:
                case SPELL_EFFECT_HEAL_MAX_HEALTH:
                case SPELL_EFFECT_HEALTH_LEECH:
                case SPELL_EFFECT_HEAL_PCT:
                case SPELL_EFFECT_ENERGIZE_PCT:
                case SPELL_EFFECT_ENERGIZE:
                case SPELL_EFFECT_HEAL_MECHANICAL:
                    spellInfo->AttributesCu |= SPELL_ATTR0_CU_NO_INITIAL_THREAT;
                    break;
                case SPELL_EFFECT_CHARGE:
                case SPELL_EFFECT_CHARGE_DEST:
                case SPELL_EFFECT_JUMP:
                case SPELL_EFFECT_JUMP_DEST:
                case SPELL_EFFECT_LEAP_BACK:
                    spellInfo->AttributesCu |= SPELL_ATTR0_CU_CHARGE;
                    break;
                case SPELL_EFFECT_PICKPOCKET:
                    spellInfo->AttributesCu |= SPELL_ATTR0_CU_PICKPOCKET;
                    break;
                case SPELL_EFFECT_ENCHANT_ITEM:
                case SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY:
                case SPELL_EFFECT_ENCHANT_ITEM_PRISMATIC:
                case SPELL_EFFECT_ENCHANT_HELD_ITEM:
                {
                    // only enchanting profession enchantments procs can stack
                    if (IsPartOfSkillLine(SKILL_ENCHANTING, i))
                    {
                        uint32 enchantId = effect->MiscValue;
                        SpellItemEnchantmentEntry const* enchant = sSpellItemEnchantmentStore.LookupEntry(enchantId);
                        if (!enchant)
                            break;

                        for (uint8 s = 0; s < MAX_ITEM_ENCHANTMENT_EFFECTS; ++s)
                        {
                            if (enchant->Effect[s] != ITEM_ENCHANTMENT_TYPE_COMBAT_SPELL)
                                continue;

                            SpellInfo* procInfo = _GetSpellInfo(enchant->EffectArg[s]);
                            if (!procInfo)
                                continue;

                            // if proced directly from enchantment, not via proc aura
                            // NOTE: Enchant Weapon - Blade Ward also has proc aura spell and is proced directly
                            // however its not expected to stack so this check is good
                            if (procInfo->HasAura(DIFFICULTY_NONE, SPELL_AURA_PROC_TRIGGER_SPELL))
                                continue;

                            procInfo->AttributesCu |= SPELL_ATTR0_CU_ENCHANT_PROC;
                        }
                    }
                    break;
                }
            }
        }

        if (!spellInfo->_IsPositiveEffect(EFFECT_0, false))
            spellInfo->AttributesCu |= SPELL_ATTR0_CU_NEGATIVE_EFF0;

        if (!spellInfo->_IsPositiveEffect(EFFECT_1, false))
            spellInfo->AttributesCu |= SPELL_ATTR0_CU_NEGATIVE_EFF1;

        if (!spellInfo->_IsPositiveEffect(EFFECT_2, false))
            spellInfo->AttributesCu |= SPELL_ATTR0_CU_NEGATIVE_EFF2;

        if (talentSpells.count(spellInfo->Id))
            spellInfo->AttributesCu |= SPELL_ATTR0_CU_IS_TALENT;


        spellInfo->_InitializeExplicitTargetMask();
    }

    TC_LOG_INFO("server.loading", ">> Loaded SpellInfo custom attributes in %u ms", GetMSTimeDiffToNow(oldMSTime));
}

inline void ApplySpellFix(std::initializer_list<uint32> spellIds, void(*fix)(SpellInfo*))
{
    for (uint32 spellId : spellIds)
    {
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
        if (!spellInfo)
        {
            TC_LOG_ERROR("server.loading", "Spell info correction specified for non-existing spell %u", spellId);
            continue;
        }

        fix(const_cast<SpellInfo*>(spellInfo));
    }
}

void SpellMgr::LoadSpellInfoCorrections()
{
    uint32 oldMSTime = getMSTime();

    ApplySpellFix({
        63026, // Summon Aspirant Test NPC (HACK: Target shouldn't be changed)
        63137  // Summon Valiant Test (HACK: Target shouldn't be changed; summon position should be untied from spell destination)
    }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetA = SpellImplicitTargetInfo(TARGET_DEST_DB);
    });

    // Summon Skeletons
    ApplySpellFix({ 52611, 52612 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->MiscValueB = 64;
    });

    ApplySpellFix({
        40244, // Simon Game Visual
        40245, // Simon Game Visual
        40246, // Simon Game Visual
        40247, // Simon Game Visual
        42835  // Spout, remove damage effect, only anim is needed
    }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->Effect = 0;
    });

    ApplySpellFix({
        63665, // Charge (Argent Tournament emote on riders)
        31298, // Sleep (needs target selection script)
        51904, // Summon Ghouls On Scarlet Crusade (this should use conditions table, script for this spell needs to be fixed)
        68933, // Wrath of Air Totem rank 2 (Aura)
        29200  // Purify Helboar Meat
    }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetB = SpellImplicitTargetInfo();
    });

    // Howl of Azgalor
    ApplySpellFix({ 31344 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_100_YARDS); // 100yards instead of 50000?!
    });

    ApplySpellFix({
        42818, // Headless Horseman - Wisp Flight Port
        42821  // Headless Horseman - Wisp Flight Missile
    }, [](SpellInfo* spellInfo)
    {
        spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(6); // 100 yards
    });

    // They Must Burn Bomb Aura (self)
    ApplySpellFix({ 36350 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TriggerSpell = 36325; // They Must Burn Bomb Drop (DND)
    });

    // Execute
    ApplySpellFix({ 5308 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx3 |= SPELL_ATTR3_CANT_TRIGGER_PROC;
    });

    ApplySpellFix({
        31347, // Doom
        36327, // Shoot Arcane Explosion Arrow
        39365, // Thundering Storm
        41071, // Raise Dead (HACK)
        42442, // Vengeance Landing Cannonfire
        42611, // Shoot
        44978, // Wild Magic
        45001, // Wild Magic
        45002, // Wild Magic
        45004, // Wild Magic
        45006, // Wild Magic
        45010, // Wild Magic
        45761, // Shoot Gun
        45863, // Cosmetic - Incinerate to Random Target
        48246, // Ball of Flame
        41635, // Prayer of Mending
        44869, // Spectral Blast
        45027, // Revitalize
        45976, // Muru Portal Channel
        52124, // Sky Darkener Assault
        52479, // Gift of the Harvester
        61588, // Blazing Harpoon
        55479, // Force Obedience
        28560, // Summon Blizzard (Sapphiron)
        53096, // Quetz'lun's Judgment
        70743, // AoD Special
        70614, // AoD Special - Vegard
        4020,  // Safirdrang's Chill
        52438, // Summon Skittering Swarmer (Force Cast)
        52449, // Summon Skittering Infector (Force Cast)
        53609, // Summon Anub'ar Assassin (Force Cast)
        53457  // Summon Impale Trigger (AoE)
    }, [](SpellInfo* spellInfo)
    {
        spellInfo->MaxAffectedTargets = 1;
    });

    // Skartax Purple Beam
    ApplySpellFix({ 36384 }, [](SpellInfo* spellInfo)
    {
        spellInfo->MaxAffectedTargets = 2;
    });

    ApplySpellFix({
        28542, // Life Drain - Sapphiron
        29213, // Curse of the Plaguebringer - Noth
        29576, // Multi-Shot
        37790, // Spread Shot
        39992, // Needle Spine
        40816, // Saber Lash
        41303, // Soul Drain
        41376, // Spite
        45248, // Shadow Blades
        46771, // Flame Sear
        66588  // Flaming Spear
    }, [](SpellInfo* spellInfo)
    {
        spellInfo->MaxAffectedTargets = 3;
    });

    ApplySpellFix({
        38310, // Multi-Shot
        53385  // Divine Storm (Damage)
    }, [](SpellInfo* spellInfo)
    {
        spellInfo->MaxAffectedTargets = 4;
    });

    ApplySpellFix({
        42005, // Bloodboil
        38296, // Spitfire Totem
        37676, // Insidious Whisper
        46008, // Negative Energy
        45641, // Fire Bloom
        55665, // Life Drain - Sapphiron (H)
        28796  // Poison Bolt Volly - Faerlina
    }, [](SpellInfo* spellInfo)
    {
        spellInfo->MaxAffectedTargets = 5;
    });

    // Curse of the Plaguebringer - Noth (H)
    ApplySpellFix({ 54835 }, [](SpellInfo* spellInfo)
    {
        spellInfo->MaxAffectedTargets = 8;
    });

    ApplySpellFix({
        40827, // Sinful Beam
        40859, // Sinister Beam
        40860, // Vile Beam
        40861, // Wicked Beam
        54098  // Poison Bolt Volly - Faerlina (H)
    }, [](SpellInfo* spellInfo)
    {
        spellInfo->MaxAffectedTargets = 10;
    });

    // Unholy Frenzy
    ApplySpellFix({ 50312 }, [](SpellInfo* spellInfo)
    {
        spellInfo->MaxAffectedTargets = 15;
    });

    // Murmur's Touch
    ApplySpellFix({ 33711, 38794 }, [](SpellInfo* spellInfo)
    {
        spellInfo->MaxAffectedTargets = 1;
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TriggerSpell = 33760;
    });

    // Fingers of Frost
    ApplySpellFix({ 44544 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->SpellClassMask = flag128(685904631, 1151048, 0, 0);
    });

    ApplySpellFix({
        52212, // Death and Decay
        41485, // Deadly Poison - Black Temple
        41487  // Envenom - Black Temple
    }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx6 |= SPELL_ATTR6_CAN_TARGET_INVISIBLE;
    });

    // Oscillation Field
    ApplySpellFix({ 37408 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx3 |= SPELL_ATTR3_STACK_FOR_DIFF_CASTERS;
    });

    // The Eye of Acherus (no spawn in phase 2 in db)
    ApplySpellFix({ 51852 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->MiscValue |= 1;
    });

    // Crafty's Ultra-Advanced Proto-Typical Shortening Blaster
    ApplySpellFix({ 51912 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->ApplyAuraPeriod = 3000;
    });

    // Nether Portal - Perseverence
    ApplySpellFix({ 30421 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_2))->BasePoints += 30000;
    });

    // Parasitic Shadowfiend Passive
    ApplySpellFix({ 41913 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->ApplyAuraName = SPELL_AURA_DUMMY; // proc debuff, and summon infinite fiends
    });

    ApplySpellFix({
        27892, // To Anchor 1
        27928, // To Anchor 1
        27935, // To Anchor 1
    }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_10_YARDS);
    });

    // Wrath of the Plaguebringer
    ApplySpellFix({ 29214, 54836 }, [](SpellInfo* spellInfo)
    {
        // target allys instead of enemies, target A is src_caster, spells with effect like that have ally target
        // this is the only known exception, probably just wrong data
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetB = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ALLY);
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_1))->TargetB = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ALLY);
    });

    // Vampiric Embrace
    ApplySpellFix({ 15290 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx3 |= SPELL_ATTR3_NO_INITIAL_AGGRO;
    });

    // Earthbind Totem (instant pulse)
    ApplySpellFix({ 6474 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx5 |= SPELL_ATTR5_START_PERIODIC_AT_APPLY;
    });

    ApplySpellFix({
        70728, // Exploit Weakness (needs target selection script)
        70840  // Devious Minds (needs target selection script)
    }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetB = SpellImplicitTargetInfo(TARGET_UNIT_PET);
    });

    // Ride Carpet
    ApplySpellFix({ 45602 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->BasePoints = 0; // force seat 0, vehicle doesn't have the required seat flags for "no seat specified (-1)"
    });

    // Easter Lay Noblegarden Egg Aura - Interrupt flags copied from aura which this aura is linked with
    ApplySpellFix({ 61719 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AuraInterruptFlags[0] = AURA_INTERRUPT_FLAG_HITBYSPELL | AURA_INTERRUPT_FLAG_TAKE_DAMAGE;
    });

    ApplySpellFix({
        71838, // Drain Life - Bryntroll Normal
        71839  // Drain Life - Bryntroll Heroic
    }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx2 |= SPELL_ATTR2_CANT_CRIT;
    });

    ApplySpellFix({
        56606, // Ride Jokkum
        61791  // Ride Vehicle (Yogg-Saron)
    }, [](SpellInfo* spellInfo)
    {
        /// @todo: remove this when basepoints of all Ride Vehicle auras are calculated correctly
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->BasePoints = 1;
    });

    // Black Magic
    ApplySpellFix({ 59630 }, [](SpellInfo* spellInfo)
    {
        spellInfo->Attributes |= SPELL_ATTR0_PASSIVE;
    });

    // Paralyze
    ApplySpellFix({ 48278 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx3 |= SPELL_ATTR3_STACK_FOR_DIFF_CASTERS;
    });

    ApplySpellFix({
        51798, // Brewfest - Relay Race - Intro - Quest Complete
        47134  // Quest Complete
    }, [](SpellInfo* spellInfo)
    {
        //! HACK: This spell break quest complete for alliance and on retail not used
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->Effect = 0;
    });

    // Siege Cannon (Tol Barad)
    ApplySpellFix({ 85123 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS);
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetA = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ENTRY);
    });

    // Gathering Storms
    ApplySpellFix({ 198300 }, [](SpellInfo* spellInfo)
    {
        spellInfo->ProcCharges = 1; // override proc charges, has 0 (unlimited) in db2
    });

    ApplySpellFix({
        42490, // Energized!
        42492, // Cast Energized
        43115  // Plague Vial
    }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx |= SPELL_ATTR1_NO_THREAT;
    });

    // Test Ribbon Pole Channel
    ApplySpellFix({ 29726 }, [](SpellInfo* spellInfo)
    {
        spellInfo->InterruptFlags &= ~AURA_INTERRUPT_FLAG_CAST;
    });

    // Sic'em
    ApplySpellFix({ 42767 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetA = SpellImplicitTargetInfo(TARGET_UNIT_NEARBY_ENTRY);
    });

    // Burn Body
    ApplySpellFix({ 42793 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_2))->MiscValue = 24008; // Fallen Combatant
    });

    // Gift of the Naaru (priest and monk variants)
    ApplySpellFix({ 59544, 121093 }, [](SpellInfo* spellInfo)
    {
        spellInfo->SpellFamilyFlags[2] = 0x80000000;
    });

    ApplySpellFix({
        50661, // Weakened Resolve
        68979  // Unleashed Souls
    }, [](SpellInfo* spellInfo)
    {
        spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(13); // 50000yd
    });

    //
    // VIOLET HOLD SPELLS
    //
    // Water Globule (Ichoron)
    ApplySpellFix({ 54258, 54264, 54265, 54266, 54267 }, [](SpellInfo* spellInfo)
    {
        // in 3.3.5 there is only one radius in dbc which is 0 yards in this case
        // use max radius from 4.3.4
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_25_YARDS);
    });
    // ENDOF VIOLET HOLD

    //
    // ULDUAR SPELLS
    //
    // Pursued (Flame Leviathan)
    ApplySpellFix({ 62374 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_50000_YARDS);   // 50000yd
    });

    // Focused Eyebeam Summon Trigger (Kologarn)
    ApplySpellFix({ 63342 }, [](SpellInfo* spellInfo)
    {
        spellInfo->MaxAffectedTargets = 1;
    });

    ApplySpellFix({
        65584, // Growth of Nature (Freya)
        64381  // Strength of the Pack (Auriaya)
    }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx3 |= SPELL_ATTR3_STACK_FOR_DIFF_CASTERS;
    });

    ApplySpellFix({
        63018, // Searing Light (XT-002)
        65121, // Searing Light (25m) (XT-002)
        63024, // Gravity Bomb (XT-002)
        64234  // Gravity Bomb (25m) (XT-002)
    }, [](SpellInfo* spellInfo)
    {
        spellInfo->MaxAffectedTargets = 1;
    });

    // Boom (XT-002)
    ApplySpellFix({ 62834 }, [](SpellInfo* spellInfo)
    {
        // This hack is here because we suspect our implementation of spell effect execution on targets
        // is done in the wrong order. We suspect that EFFECT_0 needs to be applied on all targets,
        // then EFFECT_1, etc - instead of applying each effect on target1, then target2, etc.
        // The above situation causes the visual for this spell to be bugged, so we remove the instakill
        // effect and implement a script hack for that.
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_1))->Effect = 0;
    });

    ApplySpellFix({
        64386, // Terrifying Screech (Auriaya)
        64389, // Sentinel Blast (Auriaya)
        64678  // Sentinel Blast (Auriaya)
    }, [](SpellInfo* spellInfo)
    {
        spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(28); // 5 seconds, wrong DBC data?
    });

    // Potent Pheromones (Freya)
    ApplySpellFix({ 64321 }, [](SpellInfo* spellInfo)
    {
        // spell should dispel area aura, but doesn't have the attribute
        // may be db data bug, or blizz may keep reapplying area auras every update with checking immunity
        // that will be clear if we get more spells with problem like this
        spellInfo->AttributesEx |= SPELL_ATTR1_DISPEL_AURAS_ON_IMMUNITY;
    });

    // Spinning Up (Mimiron)
    ApplySpellFix({ 63414 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetB = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
        spellInfo->ChannelInterruptFlags.fill(0);
    });

    // Rocket Strike (Mimiron)
    ApplySpellFix({ 63036 }, [](SpellInfo* spellInfo)
    {
        spellInfo->Speed = 0;
    });

    // Magnetic Field (Mimiron)
    ApplySpellFix({ 64668 }, [](SpellInfo* spellInfo)
    {
        spellInfo->Mechanic = MECHANIC_NONE;
    });

    // Empowering Shadows (Yogg-Saron)
    ApplySpellFix({ 64468, 64486 }, [](SpellInfo* spellInfo)
    {
        spellInfo->MaxAffectedTargets = 3;  // same for both modes?
    });

    // Cosmic Smash (Algalon the Observer)
    ApplySpellFix({ 62301 }, [](SpellInfo* spellInfo)
    {
        spellInfo->MaxAffectedTargets = 1;
    });

    // Cosmic Smash (Algalon the Observer)
    ApplySpellFix({ 64598 }, [](SpellInfo* spellInfo)
    {
        spellInfo->MaxAffectedTargets = 3;
    });

    // Cosmic Smash (Algalon the Observer)
    ApplySpellFix({ 62293 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetB = SpellImplicitTargetInfo(TARGET_DEST_CASTER);
    });

    // Cosmic Smash (Algalon the Observer)
    ApplySpellFix({ 62311, 64596 }, [](SpellInfo* spellInfo)
    {
        spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(6);  // 100yd
    });

    ApplySpellFix({
        64014, // Expedition Base Camp Teleport
        64024, // Conservatory Teleport
        64025, // Halls of Invention Teleport
        64028, // Colossal Forge Teleport
        64029, // Shattered Walkway Teleport
        64030, // Antechamber Teleport
        64031, // Scrapyard Teleport
        64032, // Formation Grounds Teleport
        65042  // Prison of Yogg-Saron Teleport
    }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetA = SpellImplicitTargetInfo(TARGET_DEST_DB);
    });
    // ENDOF ULDUAR SPELLS

    //
    // TRIAL OF THE CRUSADER SPELLS
    //
    // Infernal Eruption
    ApplySpellFix({ 66258 }, [](SpellInfo* spellInfo)
    {
        // increase duration from 15 to 18 seconds because caster is already
        // unsummoned when spell missile hits the ground so nothing happen in result
        spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(85);
    });
    // ENDOF TRIAL OF THE CRUSADER SPELLS

    //
    // ICECROWN CITADEL SPELLS
    //
    ApplySpellFix({
        70781, // Light's Hammer Teleport
        70856, // Oratory of the Damned Teleport
        70857, // Rampart of Skulls Teleport
        70858, // Deathbringer's Rise Teleport
        70859, // Upper Spire Teleport
        70860, // Frozen Throne Teleport
        70861  // Sindragosa's Lair Teleport
    }, [](SpellInfo* spellInfo)
    {
        // THESE SPELLS ARE WORKING CORRECTLY EVEN WITHOUT THIS HACK
        // THE ONLY REASON ITS HERE IS THAT CURRENT GRID SYSTEM
        // DOES NOT ALLOW FAR OBJECT SELECTION (dist > 333)
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetA = SpellImplicitTargetInfo(TARGET_DEST_DB);
    });

    // Shadow's Fate
    ApplySpellFix({ 71169 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx3 |= SPELL_ATTR3_STACK_FOR_DIFF_CASTERS;
    });

    // Lock Players and Tap Chest
    ApplySpellFix({ 72347 }, [](SpellInfo* spellInfo)
    {
                spellInfo->AttributesEx3 &= ~SPELL_ATTR3_NO_INITIAL_AGGRO;
    });

    // Resistant Skin (Deathbringer Saurfang adds)
    ApplySpellFix({ 72723 }, [](SpellInfo* spellInfo)
    {
        // this spell initially granted Shadow damage immunity, however it was removed but the data was left in client
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_2))->Effect = 0;
    });

    // Coldflame Jets (Traps after Saurfang)
    ApplySpellFix({ 70460 }, [](SpellInfo* spellInfo)
    {
        spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(1); // 10 seconds
    });

    ApplySpellFix({
        71412, // Green Ooze Summon (Professor Putricide)
        71415  // Orange Ooze Summon (Professor Putricide)
    }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ANY);
    });

    // Awaken Plagued Zombies
    ApplySpellFix({ 71159 }, [](SpellInfo* spellInfo)
    {
        spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(21);
    });

    // Volatile Ooze Beam Protection (Professor Putricide)
    ApplySpellFix({ 70530 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->Effect = SPELL_EFFECT_APPLY_AURA; // for an unknown reason this was SPELL_EFFECT_APPLY_AREA_AURA_RAID
    });

    // Mutated Strength (Professor Putricide)
    ApplySpellFix({ 71604 }, [](SpellInfo* spellInfo)
    {
        // THIS IS HERE BECAUSE COOLDOWN ON CREATURE PROCS WERE NOT IMPLEMENTED WHEN THE SCRIPT WAS WRITTEN
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_1))->Effect = 0;
    });

    // Unbound Plague (Professor Putricide) (needs target selection script)
    ApplySpellFix({ 70911 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetB = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    });

    // Empowered Flare (Blood Prince Council)
    ApplySpellFix({ 71708 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx3 |= SPELL_ATTR3_NO_DONE_BONUS;
    });

    // Swarming Shadows
    ApplySpellFix({ 71266 }, [](SpellInfo* spellInfo)
    {
        spellInfo->RequiredAreasID = 0; // originally, these require area 4522, which is... outside of Icecrown Citadel
    });

    // Corruption
    ApplySpellFix({ 70602 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx3 |= SPELL_ATTR3_STACK_FOR_DIFF_CASTERS;
    });

    // Column of Frost (visual marker)
    ApplySpellFix({ 70715 }, [](SpellInfo* spellInfo)
    {
        spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(32); // 6 seconds (missing)
    });

    // Mana Void (periodic aura)
    ApplySpellFix({ 71085 }, [](SpellInfo* spellInfo)
    {
        spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(9); // 30 seconds (missing)
    });

    // Summon Suppressor (needs target selection script)
    ApplySpellFix({ 70936 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ANY);
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetB = SpellImplicitTargetInfo();
        spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(157); // 90yd
    });

    // Sindragosa's Fury
    ApplySpellFix({ 70598 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetA = SpellImplicitTargetInfo(TARGET_DEST_DEST);
    });

    // Frost Bomb
    ApplySpellFix({ 69846 }, [](SpellInfo* spellInfo)
    {
        spellInfo->Speed = 0.0f;    // This spell's summon happens instantly
    });

    // Ice Lock
    ApplySpellFix({ 71614 }, [](SpellInfo* spellInfo)
    {
        spellInfo->Mechanic = MECHANIC_STUN;
    });

    // Defile
    ApplySpellFix({ 72762 }, [](SpellInfo* spellInfo)
    {
        spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(559); // 53 seconds
    });

    // Defile
    ApplySpellFix({ 72743 }, [](SpellInfo* spellInfo)
    {
        spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(22); // 45 seconds
    });

    // Defile
    ApplySpellFix({ 72754 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS); // 200yd
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_1))->RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS); // 200yd
    });

    // Raging Spirit Visual
    ApplySpellFix({ 69198 }, [](SpellInfo* spellInfo)
    {
        spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(13); // 50000yd
    });

    // Harvest Soul
    ApplySpellFix({ 73655 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx3 |= SPELL_ATTR3_NO_DONE_BONUS;
    });

    // Summon Shadow Trap
    ApplySpellFix({ 73540 }, [](SpellInfo* spellInfo)
    {
        spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(23); // 90 seconds
    });

    // Shadow Trap (visual)
    ApplySpellFix({ 73530 }, [](SpellInfo* spellInfo)
    {
        spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(28); // 5 seconds
    });

    // Summon Spirit Bomb
    ApplySpellFix({ 74302 }, [](SpellInfo* spellInfo)
    {
        spellInfo->MaxAffectedTargets = 2;
    });

    // Summon Spirit Bomb
    ApplySpellFix({ 73579 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_25_YARDS); // 25yd
    });

    // Raise Dead
    ApplySpellFix({ 72376 }, [](SpellInfo* spellInfo)
    {
        spellInfo->MaxAffectedTargets = 3;
    });

    // Jump
    ApplySpellFix({ 71809 }, [](SpellInfo* spellInfo)
    {
        spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(3); // 20yd
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_25_YARDS); // 25yd
    });

    // Broken Frostmourne
    ApplySpellFix({ 72405 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_1))->RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS); // 200yd
    });
    // ENDOF ICECROWN CITADEL SPELLS

    //
    // RUBY SANCTUM SPELLS
    //
    // Soul Consumption
    ApplySpellFix({ 74799 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_1))->RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_12_YARDS);
    });

    // Twilight Mending
    ApplySpellFix({ 75509 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx6 |= SPELL_ATTR6_CAN_TARGET_INVISIBLE;
        spellInfo->AttributesEx2 |= SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS;
    });

    // Awaken Flames
    ApplySpellFix({ 75888 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx |= SPELL_ATTR1_CANT_TARGET_SELF;
    });
    // ENDOF RUBY SANCTUM SPELLS

    //
    // EYE OF ETERNITY SPELLS
    //
    ApplySpellFix({
        57473, // Arcane Storm bonus explicit visual spell
        57431, // Summon Static Field
        56091, // Flame Spike (Wyrmrest Skytalon)
        56092, // Engulf in Flames (Wyrmrest Skytalon)
        57090, // Revivify (Wyrmrest Skytalon)
        57143  // Life Burst (Wyrmrest Skytalon)
    }, [](SpellInfo* spellInfo)
    {
        // All spells work even without these changes. The LOS attribute is due to problem
        // from collision between maps & gos with active destroyed state.
        spellInfo->AttributesEx2 |= SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS;
    });

    // Arcane Barrage (cast by players and NONMELEEDAMAGELOG with caster Scion of Eternity (original caster)).
    ApplySpellFix({ 63934 }, [](SpellInfo* spellInfo)
    {
        // This would never crit on retail and it has attribute for SPELL_ATTR3_NO_DONE_BONUS because is handled from player,
        // until someone figures how to make scions not critting without hack and without making them main casters this should stay here.
        spellInfo->AttributesEx2 |= SPELL_ATTR2_CANT_CRIT;
    });
    // ENDOF EYE OF ETERNITY SPELLS

    ApplySpellFix({
        40055, // Introspection
        40165, // Introspection
        40166, // Introspection
        40167, // Introspection
    }, [](SpellInfo* spellInfo)
    {
        spellInfo->Attributes |= SPELL_ATTR0_NEGATIVE_1;
    });

    //
    // STONECORE SPELLS
    //
    ApplySpellFix({
        95284, // Teleport (from entrance to Slabhide)
        95285  // Teleport (from Slabhide to entrance)
    }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetB = SpellImplicitTargetInfo(TARGET_DEST_DB);
    });
    // ENDOF STONECORE SPELLS

    //
    // HALLS OF ORIGINATION SPELLS
    //
    ApplySpellFix({
        76606, // Disable Beacon Beams L
        76608  // Disable Beacon Beams R
    }, [](SpellInfo* spellInfo)
    {
        // Little hack, Increase the radius so it can hit the Cave In Stalkers in the platform.
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->MaxRadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_45_YARDS);
    });

    // ENDOF HALLS OF ORIGINATION SPELLS

    // Threatening Gaze
    ApplySpellFix({ 24314 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AuraInterruptFlags[0] |= AURA_INTERRUPT_FLAG_CAST | AURA_INTERRUPT_FLAG_MOVE | AURA_INTERRUPT_FLAG_JUMP;
    });

    // Tree of Life (Passive)
    ApplySpellFix({ 5420 }, [](SpellInfo* spellInfo)
    {
        spellInfo->Stances = UI64LIT(1) << (FORM_TREE_OF_LIFE - 1);
    });

    // Feral Charge (Cat Form)
    ApplySpellFix({ 49376 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx3 &= ~SPELL_ATTR3_CANT_TRIGGER_PROC;
    });

    // Gaze of Occu'thar
    ApplySpellFix({ 96942 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx &= ~SPELL_ATTR1_CHANNELED_1;
    });

    // Evolution
    ApplySpellFix({ 75610 }, [](SpellInfo* spellInfo)
    {
        spellInfo->MaxAffectedTargets = 1;
    });

    // Evolution
    ApplySpellFix({ 75697 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetA = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ENTRY);
    });

    //
    // ISLE OF CONQUEST SPELLS
    //
    // Teleport
    ApplySpellFix({ 66551 }, [](SpellInfo* spellInfo)
    {
        spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(13); // 50000yd
    });
    // ENDOF ISLE OF CONQUEST SPELLS

    //
    // FIRELANDS SPELLS
    //
    // Torment Searcher
    ApplySpellFix({ 99253 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->MaxRadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_15_YARDS);
    });

    // Torment Damage
    ApplySpellFix({ 99256 }, [](SpellInfo* spellInfo)
    {
        spellInfo->Attributes |= SPELL_ATTR0_NEGATIVE_1;
    });

    // Blaze of Glory
    ApplySpellFix({ 99252 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AuraInterruptFlags[0] |= AURA_INTERRUPT_FLAG_CHANGE_MAP;
    });
    // ENDOF FIRELANDS SPELLS

    // Summon Master Li Fei
    ApplySpellFix({ 102445 }, [](SpellInfo* spellInfo)
    {
        const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetA = SpellImplicitTargetInfo(TARGET_DEST_DB);
    });

    SpellInfo* spellInfo = NULL;
    for (uint32 i = 0; i < GetSpellInfoStoreSize(); ++i)
    {
        spellInfo = (SpellInfo*)mSpellInfoMap[i];
        if (!spellInfo)
            continue;

        for (SpellEffectInfo const* effect : spellInfo->GetEffectsForDifficulty(DIFFICULTY_NONE))
        {
            if (!effect)
                continue;
            switch (effect->Effect)
            {
                case SPELL_EFFECT_CHARGE:
                case SPELL_EFFECT_CHARGE_DEST:
                case SPELL_EFFECT_JUMP:
                case SPELL_EFFECT_JUMP_DEST:
                case SPELL_EFFECT_LEAP_BACK:
                    if (!spellInfo->Speed && !spellInfo->SpellFamilyName)
                        spellInfo->Speed = SPEED_CHARGE;
                    break;
            }

            if (effect->TargetA.GetSelectionCategory() == TARGET_SELECT_CATEGORY_CONE || effect->TargetB.GetSelectionCategory() == TARGET_SELECT_CATEGORY_CONE)
                if (G3D::fuzzyEq(spellInfo->ConeAngle, 0.f))
                    spellInfo->ConeAngle = 90.f;
        }

        if (spellInfo->ActiveIconFileDataId == 135754)  // flight
            spellInfo->Attributes |= SPELL_ATTR0_PASSIVE;
    }

    if (SummonPropertiesEntry* properties = const_cast<SummonPropertiesEntry*>(sSummonPropertiesStore.LookupEntry(121)))
        properties->Title = SUMMON_TYPE_TOTEM;
    if (SummonPropertiesEntry* properties = const_cast<SummonPropertiesEntry*>(sSummonPropertiesStore.LookupEntry(647))) // 52893
        properties->Title = SUMMON_TYPE_TOTEM;
    if (SummonPropertiesEntry* properties = const_cast<SummonPropertiesEntry*>(sSummonPropertiesStore.LookupEntry(628))) // Hungry Plaguehound
        properties->Control = SUMMON_CATEGORY_PET;

    TC_LOG_INFO("server.loading", ">> Loaded SpellInfo corrections in %u ms", GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellInfoSpellSpecificAndAuraState()
{
    uint32 oldMSTime = getMSTime();

    for (SpellInfo* spellInfo : mSpellInfoMap)
    {
        if (!spellInfo)
            continue;

        // AuraState depends on SpellSpecific
        spellInfo->_LoadSpellSpecific();
        spellInfo->_LoadAuraState();
    }

    TC_LOG_INFO("server.loading", ">> Loaded SpellInfo SpellSpecific and AuraState in %u ms", GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellInfoDiminishing()
{
    uint32 oldMSTime = getMSTime();

    for (SpellInfo* spellInfo : mSpellInfoMap)
    {
        if (!spellInfo)
            continue;

        spellInfo->_LoadSpellDiminishInfo();
    }

    TC_LOG_INFO("server.loading", ">> Loaded SpellInfo diminishing infos in %u ms", GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellInfoImmunities()
{
    uint32 oldMSTime = getMSTime();

    for (SpellInfo* spellInfo : mSpellInfoMap)
    {
        if (!spellInfo)
            continue;

        spellInfo->_LoadImmunityInfo();
    }

    TC_LOG_INFO("server.loading", ">> Loaded SpellInfo immunity infos in %u ms", GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadPetFamilySpellsStore()
{
    std::unordered_map<uint32, SpellLevelsEntry const*> levelsBySpell;
    for (SpellLevelsEntry const* levels : sSpellLevelsStore)
        if (!levels->DifficultyID)
            levelsBySpell[levels->SpellID] = levels;

    for (SkillLineAbilityEntry const* skillLine : sSkillLineAbilityStore)
    {
        SpellInfo const* spellInfo = GetSpellInfo(skillLine->Spell);
        if (!spellInfo)
            continue;

        auto levels = levelsBySpell.find(skillLine->Spell);
        if (levels != levelsBySpell.end() && levels->second->SpellLevel)
            continue;

        if (spellInfo->IsPassive())
        {
            for (CreatureFamilyEntry const* cFamily : sCreatureFamilyStore)
            {
                if (skillLine->SkillLine != cFamily->SkillLine[0] && skillLine->SkillLine != cFamily->SkillLine[1])
                    continue;

                if (skillLine->AcquireMethod != SKILL_LINE_ABILITY_LEARNED_ON_SKILL_LEARN)
                    continue;

                sPetFamilySpellsStore[cFamily->ID].insert(spellInfo->Id);
            }
        }
    }
}

void SpellMgr::LoadSpellTotemModel()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.Query("SELECT SpellID, RaceID, DisplayID from spell_totem_model");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 spell totem model records. DB table `spell_totem_model` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 spellId = fields[0].GetUInt32();
        uint8 race = fields[1].GetUInt8();
        uint32 displayId = fields[2].GetUInt32();

        SpellInfo const* spellEntry = GetSpellInfo(spellId);
        if (!spellEntry)
        {
            TC_LOG_ERROR("sql.sql", "SpellID: %u in `spell_totem_model` table could not be found in dbc, skipped.", spellId);
            continue;
        }

        ChrRacesEntry const* raceEntry = sChrRacesStore.LookupEntry(race);
        if (!raceEntry)
        {
            TC_LOG_ERROR("sql.sql", "Race %u defined in `spell_totem_model` does not exists, skipped.", uint32(race));
            continue;
        }

        CreatureDisplayInfoEntry const* displayEntry = sCreatureDisplayInfoStore.LookupEntry(displayId);
        if (!displayEntry)
        {
            TC_LOG_ERROR("sql.sql", "SpellID: %u defined in `spell_totem_model` has non-existing model (%u).", spellId, displayId);
            continue;
        }

        mSpellTotemModel[std::make_pair(spellId, race)] = displayId;
        ++count;

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u spell totem model records in %u ms", count, GetMSTimeDiffToNow(oldMSTime));

}

uint32 SpellMgr::GetModelForTotem(uint32 spellId, uint8 race) const
{
    auto itr = mSpellTotemModel.find(std::make_pair(spellId, race));
    if (itr != mSpellTotemModel.end())
        return itr->second;

    TC_LOG_ERROR("spells", "Spell %u with RaceID (%u) have no totem model data defined, set to default model.", spellId, race);
    return 0;
}
