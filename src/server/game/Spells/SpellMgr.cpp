/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "SpellInfo.h"
#include "Spell.h"
#include "ObjectMgr.h"
#include "SpellAuraDefines.h"
#include "SharedDefines.h"
#include "DBCStores.h"
#include "Chat.h"
#include "BattlegroundMgr.h"
#include "BattlefieldWG.h"
#include "BattlefieldMgr.h"
#include "Player.h"
#include <G3D/g3dmath.h>

bool IsPrimaryProfessionSkill(uint32 skill)
{
    SkillLineEntry const* pSkill = sSkillLineStore.LookupEntry(skill);
    return pSkill && pSkill->categoryId == SKILL_CATEGORY_PROFESSION;
}

bool IsWeaponSkill(uint32 skill)
{
    SkillLineEntry const* pSkill = sSkillLineStore.LookupEntry(skill);
    return pSkill && pSkill->categoryId == SKILL_CATEGORY_WEAPON;
}

bool IsPartOfSkillLine(uint32 skillId, uint32 spellId)
{
    SkillLineAbilityMapBounds skillBounds = sSpellMgr->GetSkillLineAbilityMapBounds(spellId);
    for (SkillLineAbilityMap::const_iterator itr = skillBounds.first; itr != skillBounds.second; ++itr)
        if (itr->second->skillId == skillId)
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
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        switch (spellInfo->Effects[i].Effect)
        {
            case 0:
                continue;

            // craft spell for crafting non-existed item (break client recipes list show)
            case SPELL_EFFECT_CREATE_ITEM:
            case SPELL_EFFECT_CREATE_ITEM_2:
            {
                if (spellInfo->Effects[i].ItemType == 0)
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
                else if (!sObjectMgr->GetItemTemplate(spellInfo->Effects[i].ItemType))
                {
                    if (msg)
                    {
                        if (player)
                            ChatHandler(player->GetSession()).PSendSysMessage("Craft spell %u has created a non-existing item in DB (Entry: %u) and then...", spellInfo->Id, spellInfo->Effects[i].ItemType);
                        else
                            TC_LOG_ERROR("sql.sql", "Craft spell %u has created a non-existing item in DB (Entry: %u) and then...", spellInfo->Id, spellInfo->Effects[i].ItemType);
                    }
                    return false;
                }

                needCheckReagents = true;
                break;
            }
            case SPELL_EFFECT_LEARN_SPELL:
            {
                SpellInfo const* spellInfo2 = sSpellMgr->GetSpellInfo(spellInfo->Effects[i].TriggerSpell);
                if (!IsSpellValid(spellInfo2, player, msg))
                {
                    if (msg)
                    {
                        if (player)
                            ChatHandler(player->GetSession()).PSendSysMessage("Spell %u learn to broken spell %u, and then...", spellInfo->Id, spellInfo->Effects[i].TriggerSpell);
                        else
                            TC_LOG_ERROR("sql.sql", "Spell %u learn to invalid spell %u, and then...", spellInfo->Id, spellInfo->Effects[i].TriggerSpell);
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

uint32 SpellMgr::GetSpellDifficultyId(uint32 spellId) const
{
    SpellDifficultySearcherMap::const_iterator i = mSpellDifficultySearcherMap.find(spellId);
    return i == mSpellDifficultySearcherMap.end() ? 0 : i->second;
}

void SpellMgr::SetSpellDifficultyId(uint32 spellId, uint32 id)
{
    if (uint32 i = GetSpellDifficultyId(spellId))
        TC_LOG_ERROR("spells", "SpellMgr::SetSpellDifficultyId: The spell %u already has spellDifficultyId %u. Will override with spellDifficultyId %u.", spellId, i, id);
    mSpellDifficultySearcherMap[spellId] = id;
}

uint32 SpellMgr::GetSpellIdForDifficulty(uint32 spellId, Unit const* caster) const
{
    if (!GetSpellInfo(spellId))
        return spellId;

    if (!caster || !caster->GetMap() || !caster->GetMap()->IsDungeon())
        return spellId;

    uint32 mode = uint32(caster->GetMap()->GetSpawnMode());
    if (mode >= MAX_DIFFICULTY)
    {
        TC_LOG_ERROR("spells", "SpellMgr::GetSpellIdForDifficulty: Incorrect difficulty for spell %u.", spellId);
        return spellId; //return source spell
    }

    uint32 difficultyId = GetSpellDifficultyId(spellId);
    if (!difficultyId)
        return spellId; //return source spell, it has only REGULAR_DIFFICULTY

    SpellDifficultyEntry const* difficultyEntry = sSpellDifficultyStore.LookupEntry(difficultyId);
    if (!difficultyEntry)
    {
        TC_LOG_ERROR("spells", "SpellMgr::GetSpellIdForDifficulty: SpellDifficultyEntry was not found for spell %u. This should never happen.", spellId);
        return spellId; //return source spell
    }

    if (difficultyEntry->SpellID[mode] <= 0 && mode > DUNGEON_DIFFICULTY_HEROIC)
    {
        TC_LOG_DEBUG("spells", "SpellMgr::GetSpellIdForDifficulty: spell %u mode %u spell is NULL, using mode %u", spellId, mode, mode - 2);
        mode -= 2;
    }

    if (difficultyEntry->SpellID[mode] <= 0)
    {
        TC_LOG_ERROR("sql.sql", "SpellMgr::GetSpellIdForDifficulty: spell %u mode %u spell is 0. Check spelldifficulty_dbc!", spellId, mode);
        return spellId;
    }

    TC_LOG_DEBUG("spells", "SpellMgr::GetSpellIdForDifficulty: spellid for spell %u in mode %u is %d", spellId, mode, difficultyEntry->SpellID[mode]);
    return uint32(difficultyEntry->SpellID[mode]);
}

SpellInfo const* SpellMgr::GetSpellForDifficultyFromSpell(SpellInfo const* spell, Unit const* caster) const
{
    if (!spell)
        return NULL;

    uint32 newSpellId = GetSpellIdForDifficulty(spell->Id, caster);
    SpellInfo const* newSpell = GetSpellInfo(newSpellId);
    if (!newSpell)
    {
        TC_LOG_DEBUG("spells", "SpellMgr::GetSpellForDifficultyFromSpell: spell %u not found. Check spelldifficulty_dbc!", newSpellId);
        return spell;
    }

    TC_LOG_DEBUG("spells", "SpellMgr::GetSpellForDifficultyFromSpell: Spell id for instance mode is %u (original %u)", newSpell->Id, spell->Id);
    return newSpell;
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

SpellRequiredMapBounds SpellMgr::GetSpellsRequiredForSpellBounds(uint32 spell_id) const
{
    return mSpellReq.equal_range(spell_id);
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
        if (i->second.spell == spell_id2)
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

bool SpellMgr::AddSameEffectStackRuleSpellGroups(SpellInfo const* spellInfo, uint32 auraType, int32 amount, std::map<SpellGroup, int32>& groups) const
{
    uint32 spellId = spellInfo->GetFirstRankSpell()->Id;
    auto spellGroupBounds = GetSpellSpellGroupMapBounds(spellId);
    // Find group with SPELL_GROUP_STACK_RULE_EXCLUSIVE_SAME_EFFECT if it belongs to one
    for (auto itr = spellGroupBounds.first; itr != spellGroupBounds.second; ++itr)
    {
        SpellGroup group = itr->second;
        auto found = mSpellSameEffectStack.find(group);
        if (found != mSpellSameEffectStack.end())
        {
            // check auraTypes
            if (!found->second.count(auraType))
                continue;

            // Put the highest amount in the map
            auto groupItr = groups.find(group);
            if (groupItr == groups.end())
                groups.emplace(group, amount);
            else
            {
                int32 curr_amount = groups[group];
                // Take absolute value because this also counts for the highest negative aura
                if (std::abs(curr_amount) < std::abs(amount))
                    groupItr->second = amount;
            }
            // return because a spell should be in only one SPELL_GROUP_STACK_RULE_EXCLUSIVE_SAME_EFFECT group per auraType
            return true;
        }
    }
    // Not in a SPELL_GROUP_STACK_RULE_EXCLUSIVE_SAME_EFFECT group, so return false
    return false;
}

SpellGroupStackRule SpellMgr::CheckSpellGroupStackRules(SpellInfo const* spellInfo1, SpellInfo const* spellInfo2) const
{
    ASSERT(spellInfo1);
    ASSERT(spellInfo2);

    uint32 spellid_1 = spellInfo1->GetFirstRankSpell()->Id;
    uint32 spellid_2 = spellInfo2->GetFirstRankSpell()->Id;

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

    // check mana requirement
    if (procEntry.AttributesMask & PROC_ATTR_REQ_MANA_COST)
        if (SpellInfo const* eventSpellInfo = eventInfo.GetSpellInfo())
            if (!eventSpellInfo->ManaCost && !eventSpellInfo->ManaCostPercentage)
                return false;

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

        // check spell type mask (if set)
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

SpellBonusEntry const* SpellMgr::GetSpellBonusData(uint32 spellId) const
{
    // Lookup data
    SpellBonusMap::const_iterator itr = mSpellBonusMap.find(spellId);
    if (itr != mSpellBonusMap.end())
        return &itr->second;
    // Not found, try lookup for 1 spell rank if exist
    if (uint32 rank_1 = GetFirstSpellInChain(spellId))
    {
        SpellBonusMap::const_iterator itr2 = mSpellBonusMap.find(rank_1);
        if (itr2 != mSpellBonusMap.end())
            return &itr2->second;
    }
    return NULL;
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

void SpellMgr::LoadSpellTalentRanks()
{
    // cleanup core data before reload - remove reference to ChainNode from SpellInfo
    UnloadSpellInfoChains();

    for (uint32 i = 0; i < sTalentStore.GetNumRows(); ++i)
    {
        TalentEntry const* talentInfo = sTalentStore.LookupEntry(i);
        if (!talentInfo)
            continue;

        SpellInfo const* lastSpell = NULL;
        for (uint8 rank = MAX_TALENT_RANK - 1; rank > 0; --rank)
        {
            if (talentInfo->RankID[rank])
            {
                lastSpell = GetSpellInfo(talentInfo->RankID[rank]);
                break;
            }
        }

        if (!lastSpell)
            continue;

        SpellInfo const* firstSpell = GetSpellInfo(talentInfo->RankID[0]);
        if (!firstSpell)
        {
            TC_LOG_ERROR("spells", "SpellMgr::LoadSpellTalentRanks: First Rank Spell %u for TalentEntry %u does not exist.", talentInfo->RankID[0], i);
            continue;
        }

        SpellInfo const* prevSpell = NULL;
        for (uint8 rank = 0; rank < MAX_TALENT_RANK; ++rank)
        {
            uint32 spellId = talentInfo->RankID[rank];
            if (!spellId)
                break;

            SpellInfo const* currentSpell = GetSpellInfo(spellId);
            if (!currentSpell)
            {
                TC_LOG_ERROR("spells", "SpellMgr::LoadSpellTalentRanks: Spell %u (Rank: %u) for TalentEntry %u does not exist.", spellId, rank + 1, i);
                break;
            }

            SpellChainNode node;
            node.first = firstSpell;
            node.last  = lastSpell;
            node.rank  = rank + 1;

            node.prev = prevSpell;
            node.next = node.rank < MAX_TALENT_RANK ? GetSpellInfo(talentInfo->RankID[node.rank]) : NULL;

            mSpellChains[spellId] = node;
            mSpellInfoMap[spellId]->ChainEntry = &mSpellChains[spellId];

            prevSpell = currentSpell;
        }
    }
}

void SpellMgr::LoadSpellRanks()
{
    // cleanup data and load spell ranks for talents from dbc
    LoadSpellTalentRanks();

    uint32 oldMSTime = getMSTime();

    //                                                     0             1      2
    QueryResult result = WorldDatabase.Query("SELECT first_spell_id, spell_id, rank from spell_ranks ORDER BY first_spell_id, rank");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 spell rank records. DB table `spell_ranks` is empty.");
        return;
    }

    uint32 count = 0;
    bool finished = false;

    do
    {
                        // spellid, rank
        std::list < std::pair < int32, int32 > > rankChain;
        int32 currentSpell = -1;
        int32 lastSpell = -1;

        // fill one chain
        while (currentSpell == lastSpell && !finished)
        {
            Field* fields = result->Fetch();

            currentSpell = fields[0].GetUInt32();
            if (lastSpell == -1)
                lastSpell = currentSpell;
            uint32 spell_id = fields[1].GetUInt32();
            uint32 rank = fields[2].GetUInt8();

            // don't drop the row if we're moving to the next rank
            if (currentSpell == lastSpell)
            {
                rankChain.push_back(std::make_pair(spell_id, rank));
                if (!result->NextRow())
                    finished = true;
            }
            else
                break;
        }
        // check if chain is made with valid first spell
        SpellInfo const* first = GetSpellInfo(lastSpell);
        if (!first)
        {
            TC_LOG_ERROR("sql.sql", "The spell rank identifier(first_spell_id) %u listed in `spell_ranks` does not exist!", lastSpell);
            continue;
        }
        // check if chain is long enough
        if (rankChain.size() < 2)
        {
            TC_LOG_ERROR("sql.sql", "There is only 1 spell rank for identifier(first_spell_id) %u in `spell_ranks`, entry is not needed!", lastSpell);
            continue;
        }
        int32 curRank = 0;
        bool valid = true;
        // check spells in chain
        for (std::list<std::pair<int32, int32> >::iterator itr = rankChain.begin(); itr!= rankChain.end(); ++itr)
        {
            SpellInfo const* spell = GetSpellInfo(itr->first);
            if (!spell)
            {
                TC_LOG_ERROR("sql.sql", "The spell %u (rank %u) listed in `spell_ranks` for chain %u does not exist!", itr->first, itr->second, lastSpell);
                valid = false;
                break;
            }
            ++curRank;
            if (itr->second != curRank)
            {
                TC_LOG_ERROR("sql.sql", "The spell %u (rank %u) listed in `spell_ranks` for chain %u does not have a proper rank value (should be %u)!", itr->first, itr->second, lastSpell, curRank);
                valid = false;
                break;
            }
        }
        if (!valid)
            continue;
        int32 prevRank = 0;
        // insert the chain
        std::list<std::pair<int32, int32> >::iterator itr = rankChain.begin();
        do
        {
            ++count;
            int32 addedSpell = itr->first;

            if (mSpellInfoMap[addedSpell]->ChainEntry)
                TC_LOG_ERROR("sql.sql", "The spell %u (rank: %u, first: %u) listed in `spell_ranks` already has ChainEntry from dbc.", addedSpell, itr->second, lastSpell);

            mSpellChains[addedSpell].first = GetSpellInfo(lastSpell);
            mSpellChains[addedSpell].last = GetSpellInfo(rankChain.back().first);
            mSpellChains[addedSpell].rank = itr->second;
            mSpellChains[addedSpell].prev = GetSpellInfo(prevRank);
            mSpellInfoMap[addedSpell]->ChainEntry = &mSpellChains[addedSpell];
            prevRank = addedSpell;
            ++itr;

            if (itr == rankChain.end())
            {
                mSpellChains[addedSpell].next = NULL;
                break;
            }
            else
                mSpellChains[addedSpell].next = GetSpellInfo(itr->first);
        }
        while (true);
    }
    while (!finished);

    TC_LOG_INFO("server.loading", ">> Loaded %u spell rank records in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
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

        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        {
            SpellLearnSkillNode dbc_node;
            switch (entry->Effects[i].Effect)
            {
                case SPELL_EFFECT_SKILL:
                    dbc_node.skill = entry->Effects[i].MiscValue;
                    dbc_node.step = entry->Effects[i].CalcValue();
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
        node.spell       = fields[1].GetUInt32();
        node.active      = fields[2].GetBool();
        node.autoLearned = false;

        if (!GetSpellInfo(spell_id))
        {
            TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_learn_spell` does not exist.", spell_id);
            continue;
        }

        if (!GetSpellInfo(node.spell))
        {
            TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_learn_spell` learning non-existing spell %u.", spell_id, node.spell);
            continue;
        }

        if (GetTalentSpellCost(node.spell))
        {
            TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_learn_spell` attempts learning talent spell %u, skipped.", spell_id, node.spell);
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

        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        {
            if (entry->Effects[i].Effect == SPELL_EFFECT_LEARN_SPELL)
            {
                SpellLearnSpellNode dbc_node;
                dbc_node.spell = entry->Effects[i].TriggerSpell;
                dbc_node.active = true;                     // all dbc based learned spells is active (show in spell book or hide by client itself)

                // ignore learning not existed spells (broken/outdated/or generic learnig spell 483
                if (!GetSpellInfo(dbc_node.spell))
                    continue;

                // talent or passive spells or skill-step spells auto-cast and not need dependent learning,
                // pet teaching spells must not be dependent learning (cast)
                // other required explicit dependent learning
                dbc_node.autoLearned = entry->Effects[i].TargetA.GetTarget() == TARGET_UNIT_PET || GetTalentSpellCost(spell) > 0 || entry->IsPassive() || entry->HasEffect(SPELL_EFFECT_SKILL_STEP);

                SpellLearnSpellMapBounds db_node_bounds = dbSpellLearnSpells.equal_range(spell);

                bool found = false;
                for (SpellLearnSpellMap::const_iterator itr = db_node_bounds.first; itr != db_node_bounds.second; ++itr)
                {
                    if (itr->second.spell == dbc_node.spell)
                    {
                        TC_LOG_ERROR("sql.sql", "The spell %u is an auto-learn spell %u in spell.dbc and the record in `spell_learn_spell` is redundant. Please update your DB.",
                            spell, dbc_node.spell);
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

    uint32 mastery_count = 0;
    for (uint32 i = 0; i < sTalentTabStore.GetNumRows(); ++i)
    {
        TalentTabEntry const* talentTab = sTalentTabStore.LookupEntry(i);
        if (!talentTab)
            continue;

        for (uint32 c = CLASS_WARRIOR; c < MAX_CLASSES; ++c)
        {
            if (!(talentTab->ClassMask & (1 << (c - 1))))
                continue;

            uint32 masteryMainSpell = MasterySpells[c];

            for (uint32 m = 0; m < MAX_MASTERY_SPELLS; ++m)
            {
                uint32 mastery = talentTab->MasterySpellId[m];
                if (!mastery)
                    continue;

                SpellLearnSpellMapBounds db_node_bounds = dbSpellLearnSpells.equal_range(masteryMainSpell);
                bool found = false;
                for (SpellLearnSpellMap::const_iterator itr = db_node_bounds.first; itr != db_node_bounds.second; ++itr)
                {
                    if (itr->second.spell == mastery)
                    {
                        TC_LOG_ERROR("sql.sql", "Found redundant record (entry: %u, SpellID: %u) in `spell_learn_spell`, spell added automatically as mastery learned spell from TalentTab.dbc", masteryMainSpell, mastery);
                        found = true;
                        break;
                    }
                }

                if (found)
                    continue;

                // Check if it is already found in Spell.dbc, ignore silently if yes
                SpellLearnSpellMapBounds dbc_node_bounds = GetSpellLearnSpellMapBounds(masteryMainSpell);
                found = false;
                for (SpellLearnSpellMap::const_iterator itr = dbc_node_bounds.first; itr != dbc_node_bounds.second; ++itr)
                {
                    if (itr->second.spell == mastery)
                    {
                        found = true;
                        break;
                    }
                }

                if (found)
                    continue;

                SpellLearnSpellNode masteryNode;
                masteryNode.spell       = mastery;
                masteryNode.active      = true;
                masteryNode.autoLearned = false;

                mSpellLearnSpells.insert(SpellLearnSpellMap::value_type(masteryMainSpell, masteryNode));
                ++mastery_count;
            }
        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u spell learn spells, %u found in Spell.dbc and %u from TalentTab.dbc in %u ms", count, dbc_count, mastery_count, GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellTargetPositions()
{
    uint32 oldMSTime = getMSTime();

    mSpellTargetPositions.clear();                                // need for reload case

    //                                                0      1          2        3         4           5            6
    QueryResult result = WorldDatabase.Query("SELECT ID, EffectIndex, MapID, PositionX, PositionY, PositionZ, Orientation FROM spell_target_position");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 spell target coordinates. DB table `spell_target_position` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 Spell_ID = fields[0].GetUInt32();
        SpellEffIndex effIndex = SpellEffIndex(fields[1].GetUInt8());

        SpellTargetPosition st;

        st.target_mapId       = fields[2].GetUInt16();
        st.target_X           = fields[3].GetFloat();
        st.target_Y           = fields[4].GetFloat();
        st.target_Z           = fields[5].GetFloat();
        st.target_Orientation = fields[6].GetFloat();

        MapEntry const* mapEntry = sMapStore.LookupEntry(st.target_mapId);
        if (!mapEntry)
        {
            TC_LOG_ERROR("sql.sql", "Spell (Id: %u, effIndex: %u) target map (ID: %u) does not exist in `Map.dbc`.", Spell_ID, effIndex, st.target_mapId);
            continue;
        }

        if (st.target_X==0 && st.target_Y==0 && st.target_Z==0)
        {
            TC_LOG_ERROR("sql.sql", "Spell (Id: %u, effIndex: %u) target coordinates not provided.", Spell_ID, effIndex);
            continue;
        }

        SpellInfo const* spellInfo = GetSpellInfo(Spell_ID);
        if (!spellInfo)
        {
            TC_LOG_ERROR("sql.sql", "Spell (Id: %u) listed in `spell_target_position` does not exist.", Spell_ID);
            continue;
        }

        if (spellInfo->Effects[effIndex].TargetA.GetTarget() == TARGET_DEST_DB || spellInfo->Effects[effIndex].TargetB.GetTarget() == TARGET_DEST_DB)
        {
            std::pair<uint32, SpellEffIndex> key = std::make_pair(Spell_ID, effIndex);
            mSpellTargetPositions[key] = st;
            ++count;
        }
        else
        {
            TC_LOG_ERROR("sql.sql", "Spell (Id: %u, effIndex: %u) listed in `spell_target_position` does not have a target TARGET_DEST_DB (17).", Spell_ID, effIndex);
            continue;
        }

    } while (result->NextRow());

    /*
    // Check all spells
    for (uint32 i = 1; i < GetSpellInfoStoreSize; ++i)
    {
        SpellInfo const* spellInfo = GetSpellInfo(i);
        if (!spellInfo)
            continue;

        bool found = false;
        for (int j = 0; j < MAX_SPELL_EFFECTS; ++j)
        {
            switch (spellInfo->Effects[j].TargetA)
            {
                case TARGET_DEST_DB:
                    found = true;
                    break;
            }
            if (found)
                break;
            switch (spellInfo->Effects[j].TargetB)
            {
                case TARGET_DEST_DB:
                    found = true;
                    break;
            }
            if (found)
                break;
        }
        if (found)
        {
            if (!sSpellMgr->GetSpellTargetPosition(i))
                TC_LOG_DEBUG("spells", "Spell (ID: %u) does not have a record in `spell_target_position`.", i);
        }
    }*/

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

        groups.insert(group_id);
        mSpellGroupSpell.emplace(SpellGroup(group_id), spell_id);

    } while (result->NextRow());

    for (auto itr = mSpellGroupSpell.begin(); itr!= mSpellGroupSpell.end();)
    {
        if (itr->second < 0)
        {
            if (groups.find(abs(itr->second)) == groups.end())
            {
                TC_LOG_ERROR("sql.sql", "SpellGroup id %u listed in `spell_group` does not exist", abs(itr->second));
                itr = mSpellGroupSpell.erase(itr);
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
                itr = mSpellGroupSpell.erase(itr);
            }
            else if (spellInfo->GetRank() > 1)
            {
                TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_group` is not the first rank of the spell.", itr->second);
                itr = mSpellGroupSpell.erase(itr);
            }
            else
                ++itr;
        }
    }

    for (auto groupItr = groups.begin(); groupItr != groups.end(); ++groupItr)
    {
        std::set<uint32> spells;
        GetSetOfSpellsInSpellGroup(SpellGroup(*groupItr), spells);

        for (auto spellItr = spells.begin(); spellItr != spells.end(); ++spellItr)
        {
            ++count;
            mSpellSpellGroup.emplace(*spellItr, SpellGroup(*groupItr));
        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u spell group definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellGroupStackRules()
{
    uint32 oldMSTime = getMSTime();

    mSpellGroupStack.clear();                                  // need for reload case
    mSpellSameEffectStack.clear();

    std::vector<uint32> sameEffectGroups;

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

        auto bounds = GetSpellGroupSpellMapBounds((SpellGroup)group_id);
        if (bounds.first == bounds.second)
        {
            TC_LOG_ERROR("sql.sql", "SpellGroup id %u listed in `spell_group_stack_rules` does not exist.", group_id);
            continue;
        }

        mSpellGroupStack.emplace(SpellGroup(group_id), SpellGroupStackRule(stack_rule));

        // different container for same effect stack rules, need to check effect types
        if (stack_rule == SPELL_GROUP_STACK_RULE_EXCLUSIVE_SAME_EFFECT)
            sameEffectGroups.push_back(group_id);

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u spell group stack rules in %u ms", count, GetMSTimeDiffToNow(oldMSTime));

    count = 0;
    oldMSTime = getMSTime();
    TC_LOG_INFO("server.loading", ">> Parsing SPELL_GROUP_STACK_RULE_EXCLUSIVE_SAME_EFFECT stack rules...");

    for (uint32 group_id : sameEffectGroups)
    {
        std::set<uint32> spellIds;
        GetSetOfSpellsInSpellGroup(SpellGroup(group_id), spellIds);

        std::unordered_set<uint32> auraTypes;

        // we have to 'guess' what effect this group corresponds to
        {
            std::unordered_multiset<uint32 /*auraName*/> frequencyContainer;

            // only waylay for the moment (shared group)
            std::vector<std::vector<uint32 /*auraName*/>> const SubGroups =
            {
                { SPELL_AURA_MOD_MELEE_HASTE, SPELL_AURA_MOD_MELEE_RANGED_HASTE, SPELL_AURA_MOD_RANGED_HASTE }
            };

            for (uint32 spellId : spellIds)
            {
                SpellInfo const* spellInfo = AssertSpellInfo(spellId);
                for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                {
                    if (!spellInfo->Effects[i].IsAura())
                        continue;

                    int32 auraName = static_cast<int32>(spellInfo->Effects[i].ApplyAuraName);
                    for (std::vector<uint32> const& subGroup : SubGroups)
                    {
                        if (std::find(subGroup.begin(), subGroup.end(), auraName) != subGroup.end())
                        {
                            // count as first aura
                            auraName = subGroup.front();
                            break;
                        }
                    }

                    frequencyContainer.insert(auraName);
                }
            }

            uint32 auraType = 0;
            size_t auraTypeCount = 0;
            for (uint32 auraName : frequencyContainer)
            {
                size_t currentCount = frequencyContainer.count(auraName);
                if (currentCount > auraTypeCount)
                {
                    auraType = auraName;
                    auraTypeCount = currentCount;
                }
            }

            for (std::vector<uint32> const& subGroup : SubGroups)
            {
                if (auraType == subGroup.front())
                {
                    auraTypes.insert(subGroup.begin(), subGroup.end());
                    break;
                }
            }

            if (auraTypes.empty())
                auraTypes.insert(auraType);
        }

        // re-check spells against guessed group
        for (uint32 spellId : spellIds)
        {
            SpellInfo const* spellInfo = AssertSpellInfo(spellId);

            bool found = false;
            while (spellInfo)
            {
                for (uint32 auraType : auraTypes)
                {
                    if (spellInfo->HasAura(AuraType(auraType)))
                    {
                        found = true;
                        break;
                    }
                }

                if (found)
                    break;

                spellInfo = spellInfo->GetNextRankSpell();
            }

            // not found either, log error
            if (!found)
                TC_LOG_ERROR("sql.sql", "SpellId %u listed in `spell_group` with stack rule 3 does not share aura assigned for group %u", spellId, group_id);
        }

        mSpellSameEffectStack[SpellGroup(group_id)] = auraTypes;
        ++count;
    }

    TC_LOG_INFO("server.loading", ">> Parsed %u SPELL_GROUP_STACK_RULE_EXCLUSIVE_SAME_EFFECT stack rules in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellProcs()
{
    uint32 oldMSTime = getMSTime();

    mSpellProcMap.clear();                             // need for reload case

    //                                                     0           1                2                 3                 4                 5
    QueryResult result = WorldDatabase.Query("SELECT SpellId, SchoolMask, SpellFamilyName, SpellFamilyMask0, SpellFamilyMask1, SpellFamilyMask2, "
    //           6              7               8        9              10              11      12        13      14
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

            baseProcEntry.SchoolMask = fields[1].GetInt8();
            baseProcEntry.SpellFamilyName = fields[2].GetUInt16();
            baseProcEntry.SpellFamilyMask[0] = fields[3].GetUInt32();
            baseProcEntry.SpellFamilyMask[1] = fields[4].GetUInt32();
            baseProcEntry.SpellFamilyMask[2] = fields[5].GetUInt32();
            baseProcEntry.ProcFlags = fields[6].GetUInt32();
            baseProcEntry.SpellTypeMask = fields[7].GetUInt32();
            baseProcEntry.SpellPhaseMask = fields[8].GetUInt32();
            baseProcEntry.HitMask = fields[9].GetUInt32();
            baseProcEntry.AttributesMask = fields[10].GetUInt32();
            baseProcEntry.ProcsPerMinute = fields[11].GetFloat();
            baseProcEntry.Chance = fields[12].GetFloat();
            baseProcEntry.Cooldown = Milliseconds(fields[13].GetUInt32());
            baseProcEntry.Charges = fields[14].GetUInt8();

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

                // validate data
                if (procEntry.SchoolMask & ~SPELL_SCHOOL_MASK_ALL)
                    TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId %u has wrong `SchoolMask` set: %u", spellInfo->Id, procEntry.SchoolMask);
                if (procEntry.SpellFamilyName && (procEntry.SpellFamilyName < SPELLFAMILY_MAGE || procEntry.SpellFamilyName > SPELLFAMILY_PET || procEntry.SpellFamilyName == 14 || procEntry.SpellFamilyName == 16))
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
                for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                    if ((procEntry.AttributesMask & (PROC_ATTR_DISABLE_EFF_0 << i)) && !spellInfo->Effects[i].IsAura())
                        TC_LOG_ERROR("sql.sql", "The `spell_proc` table entry for spellId %u has Attribute PROC_ATTR_DISABLE_EFF_%u, but effect %u is not an aura effect", spellInfo->Id, static_cast<uint32>(i), static_cast<uint32>(i));

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

    isTriggerAura[SPELL_AURA_DUMMY] = true;                                 // Most dummy auras should require scripting, but there are some exceptions (ie 12311)
    isTriggerAura[SPELL_AURA_MOD_CONFUSE] = true;                           // "Any direct damaging attack will revive targets"
    isTriggerAura[SPELL_AURA_MOD_THREAT] = true;                            // Only one spell: 28762 part of Mage T3 8p bonus
    isTriggerAura[SPELL_AURA_MOD_STUN] = true;                              // Aura does not have charges but needs to be removed on trigger
    isTriggerAura[SPELL_AURA_MOD_DAMAGE_DONE] = true;
    isTriggerAura[SPELL_AURA_MOD_DAMAGE_TAKEN] = true;
    isTriggerAura[SPELL_AURA_MOD_RESISTANCE] = true;
    isTriggerAura[SPELL_AURA_MOD_STEALTH] = true;
    isTriggerAura[SPELL_AURA_MOD_FEAR] = true;                              // Aura does not have charges but needs to be removed on trigger
    isTriggerAura[SPELL_AURA_MOD_ROOT] = true;
    isTriggerAura[SPELL_AURA_TRANSFORM] = true;
    isTriggerAura[SPELL_AURA_REFLECT_SPELLS] = true;
    isTriggerAura[SPELL_AURA_DAMAGE_IMMUNITY] = true;
    isTriggerAura[SPELL_AURA_PROC_TRIGGER_SPELL] = true;
    isTriggerAura[SPELL_AURA_PROC_TRIGGER_DAMAGE] = true;
    isTriggerAura[SPELL_AURA_MOD_CASTING_SPEED_NOT_STACK] = true;
    isTriggerAura[SPELL_AURA_MOD_POWER_COST_SCHOOL_PCT] = true;
    isTriggerAura[SPELL_AURA_MOD_POWER_COST_SCHOOL] = true;
    isTriggerAura[SPELL_AURA_REFLECT_SPELLS_SCHOOL] = true;
    isTriggerAura[SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN] = true;
    isTriggerAura[SPELL_AURA_MOD_ATTACK_POWER] = true;
    isTriggerAura[SPELL_AURA_ADD_CASTER_HIT_TRIGGER] = true;
    isTriggerAura[SPELL_AURA_OVERRIDE_CLASS_SCRIPTS] = true;
    isTriggerAura[SPELL_AURA_MOD_MELEE_HASTE] = true;
    isTriggerAura[SPELL_AURA_MOD_ATTACKER_MELEE_HIT_CHANCE] = true;
    isTriggerAura[SPELL_AURA_RAID_PROC_FROM_CHARGE] = true;
    isTriggerAura[SPELL_AURA_RAID_PROC_FROM_CHARGE_WITH_VALUE] = true;
    isTriggerAura[SPELL_AURA_PROC_TRIGGER_SPELL_WITH_VALUE] = true;
    isTriggerAura[SPELL_AURA_MOD_SPELL_CRIT_CHANCE] = true;
    isTriggerAura[SPELL_AURA_ADD_FLAT_MODIFIER] = true;
    isTriggerAura[SPELL_AURA_ADD_PCT_MODIFIER] = true;
    isTriggerAura[SPELL_AURA_ABILITY_IGNORE_AURASTATE] = true;
    isTriggerAura[SPELL_AURA_MOD_INVISIBILITY] = true;
    isTriggerAura[SPELL_AURA_FORCE_REACTION] = true;
    isTriggerAura[SPELL_AURA_MOD_TAUNT] = true;
    isTriggerAura[SPELL_AURA_MOD_DETAUNT] = true;
    isTriggerAura[SPELL_AURA_MOD_DAMAGE_PERCENT_DONE] = true;
    isTriggerAura[SPELL_AURA_MOD_ATTACK_POWER_PCT] = true;
    isTriggerAura[SPELL_AURA_MOD_HIT_CHANCE] = true;
    isTriggerAura[SPELL_AURA_MOD_WEAPON_CRIT_PERCENT] = true;
    isTriggerAura[SPELL_AURA_MOD_BLOCK_PERCENT] = true;
    isTriggerAura[SPELL_AURA_PROC_ON_POWER_AMOUNT] = true;

    isAlwaysTriggeredAura[SPELL_AURA_OVERRIDE_CLASS_SCRIPTS] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_STEALTH] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_CONFUSE] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_FEAR] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_ROOT] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_STUN] = true;
    isAlwaysTriggeredAura[SPELL_AURA_TRANSFORM] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_INVISIBILITY] = true;

    spellTypeMask[SPELL_AURA_MOD_STEALTH] = PROC_SPELL_TYPE_DAMAGE | PROC_SPELL_TYPE_NO_DMG_HEAL;
    spellTypeMask[SPELL_AURA_MOD_CONFUSE] = PROC_SPELL_TYPE_DAMAGE;
    spellTypeMask[SPELL_AURA_MOD_FEAR] = PROC_SPELL_TYPE_DAMAGE;
    spellTypeMask[SPELL_AURA_MOD_ROOT] = PROC_SPELL_TYPE_DAMAGE;
    spellTypeMask[SPELL_AURA_MOD_STUN] = PROC_SPELL_TYPE_DAMAGE;
    spellTypeMask[SPELL_AURA_TRANSFORM] = PROC_SPELL_TYPE_DAMAGE;
    spellTypeMask[SPELL_AURA_MOD_INVISIBILITY] = PROC_SPELL_TYPE_DAMAGE;

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
        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        {
            if (!spellInfo->Effects[i].IsEffect())
                continue;

            uint32 auraName = spellInfo->Effects[i].ApplyAuraName;
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
            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            {
                if (spellInfo->Effects[i].IsAura())
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
        for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            if (spellInfo->Effects[i].IsEffect() && isTriggerAura[spellInfo->Effects[i].ApplyAuraName])
                procEntry.SpellFamilyMask |= spellInfo->Effects[i].SpellClassMask;

        if (procEntry.SpellFamilyMask)
            procEntry.SpellFamilyName = spellInfo->SpellFamilyName;

        procEntry.SpellTypeMask   = procSpellTypeMask;
        procEntry.SpellPhaseMask  = PROC_SPELL_PHASE_HIT;
        procEntry.HitMask         = PROC_HIT_NONE; // uses default proc @see SpellMgr::CanSpellTriggerProcOnEvent

        for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        {
            if (!spellInfo->Effects[i].IsAura())
                continue;

            switch (spellInfo->Effects[i].ApplyAuraName)
            {
                // Reflect auras should only proc off reflects
                case SPELL_AURA_REFLECT_SPELLS:
                case SPELL_AURA_REFLECT_SPELLS_SCHOOL:
                    procEntry.HitMask = PROC_HIT_REFLECT;
                    break;
                // Only drop charge on crit
                case SPELL_AURA_MOD_WEAPON_CRIT_PERCENT:
                    procEntry.HitMask = PROC_HIT_CRITICAL;
                    break;
                // Only drop charge on block
                case SPELL_AURA_MOD_BLOCK_PERCENT:
                    procEntry.HitMask = PROC_HIT_BLOCK;
                    break;
                default:
                    continue;
            }
            break;
        }

        procEntry.AttributesMask  = 0;
        if (spellInfo->ProcFlags & PROC_FLAG_KILL)
            procEntry.AttributesMask |= PROC_ATTR_REQ_EXP_OR_HONOR;
        if (addTriggerFlag)
            procEntry.AttributesMask |= PROC_ATTR_TRIGGERED_CAN_PROC;

        procEntry.ProcsPerMinute  = 0;
        procEntry.Chance          = spellInfo->ProcChance;
        procEntry.Cooldown        = Milliseconds::zero();
        procEntry.Charges         = spellInfo->ProcCharges;

        mSpellProcMap[spellInfo->Id] = procEntry;
        ++count;
    }

    TC_LOG_INFO("server.loading", ">> Generated spell proc data for %u spells in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellBonusess()
{
    uint32 oldMSTime = getMSTime();

    mSpellBonusMap.clear();                             // need for reload case

    //                                                0      1             2          3         4
    QueryResult result = WorldDatabase.Query("SELECT entry, direct_bonus, dot_bonus, ap_bonus, ap_dot_bonus FROM spell_bonus_data");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 spell bonus data. DB table `spell_bonus_data` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();
        uint32 entry = fields[0].GetUInt32();

        SpellInfo const* spell = GetSpellInfo(entry);
        if (!spell)
        {
            TC_LOG_ERROR("sql.sql", "The spell %u listed in `spell_bonus_data` does not exist.", entry);
            continue;
        }

        SpellBonusEntry& sbe = mSpellBonusMap[entry];
        sbe.direct_damage = fields[1].GetFloat();
        sbe.dot_damage    = fields[2].GetFloat();
        sbe.ap_bonus      = fields[3].GetFloat();
        sbe.ap_dot_bonus   = fields[4].GetFloat();

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u extra spell bonus data in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
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

        mSkillLineAbilityMap.insert(SkillLineAbilityMap::value_type(SkillInfo->spellId, SkillInfo));
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
            if (spellInfo->Effects[eff].Effect != SPELL_EFFECT_DUMMY &&
               (spellInfo->Effects[eff].Effect != SPELL_EFFECT_APPLY_AURA ||
                spellInfo->Effects[eff].ApplyAuraName != SPELL_AURA_DUMMY))
            {
                TC_LOG_ERROR("spells", "The spell %u listed in `spell_pet_auras` does not have any dummy aura or dummy effect.", spell);
                continue;
            }

            SpellInfo const* spellInfo2 = GetSpellInfo(aura);
            if (!spellInfo2)
            {
                TC_LOG_ERROR("sql.sql", "The aura %u listed in `spell_pet_auras` does not exist.", aura);
                continue;
            }

            PetAura pa(pet, aura, spellInfo->Effects[eff].TargetA.GetTarget() == TARGET_UNIT_PET, spellInfo->Effects[eff].CalcValue());
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

        for (uint32 j = 0; j < MAX_SPELL_EFFECTS; ++j)
        {
            if (spellInfo->Effects[j].Effect == SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY)
            {
                uint32 enchId = spellInfo->Effects[j].MiscValue;
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
            for (uint8 j = 0; j < MAX_SPELL_EFFECTS; ++j)
            {
                if (spellInfo->Effects[j].CalcValue() == abs(effect))
                    TC_LOG_ERROR("sql.sql", "The spell %u Effect: %u listed in `spell_linked_spell` has same bp%u like effect (possible hack).", abs(trigger), abs(effect), j);
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
            if (!creatureFamily->skillLine[j])
                continue;

            for (uint32 k = 0; k < sSkillLineAbilityStore.GetNumRows(); ++k)
            {
                SkillLineAbilityEntry const* skillLine = sSkillLineAbilityStore.LookupEntry(k);
                if (!skillLine)
                    continue;

                //if (skillLine->skillId != creatureFamily->skillLine[0] &&
                //    (!creatureFamily->skillLine[1] || skillLine->skillId != creatureFamily->skillLine[1]))
                //    continue;

                if (skillLine->skillId != creatureFamily->skillLine[j])
                    continue;

                if (skillLine->AutolearnType != SKILL_LINE_ABILITY_LEARNED_ON_SKILL_LEARN)
                    continue;

                SpellInfo const* spell = GetSpellInfo(skillLine->spellId);
                if (!spell) // not exist or triggered or talent
                    continue;

                if (!spell->SpellLevel)
                    continue;

                PetLevelupSpellSet& spellSet = mPetLevelupSpellMap[creatureFamily->ID];
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
    uint32 countData = 0;

    CreatureTemplateContainer const* ctc = sObjectMgr->GetCreatureTemplates();
    for (CreatureTemplateContainer::const_iterator itr = ctc->begin(); itr != ctc->end(); ++itr)
    {

        if (!itr->second.PetSpellDataId)
            continue;

        // for creature with PetSpellDataId get default pet spells from dbc
        CreatureSpellDataEntry const* spellDataEntry = sCreatureSpellDataStore.LookupEntry(itr->second.PetSpellDataId);
        if (!spellDataEntry)
            continue;

        int32 petSpellsId = -int32(itr->second.PetSpellDataId);
        PetDefaultSpellsEntry petDefSpells;
        for (uint8 j = 0; j < MAX_CREATURE_SPELL_DATA_SLOT; ++j)
            petDefSpells.spellid[j] = spellDataEntry->spellId[j];

        if (LoadPetDefaultSpells_helper(&itr->second, petDefSpells))
        {
            mPetDefaultSpellsMap[petSpellsId] = petDefSpells;
            ++countData;
        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded addition spells for %u pet spell data entries in %u ms", countData, GetMSTimeDiffToNow(oldMSTime));

    TC_LOG_INFO("server.loading", "Loading summonable creature templates...");
    oldMSTime = getMSTime();

    // different summon spells
    for (uint32 i = 0; i < GetSpellInfoStoreSize(); ++i)
    {
        SpellInfo const* spellEntry = GetSpellInfo(i);
        if (!spellEntry)
            continue;

        for (uint8 k = 0; k < MAX_SPELL_EFFECTS; ++k)
        {
            if (spellEntry->Effects[k].Effect == SPELL_EFFECT_SUMMON || spellEntry->Effects[k].Effect == SPELL_EFFECT_SUMMON_PET)
            {
                uint32 creature_id = spellEntry->Effects[k].MiscValue;
                CreatureTemplate const* cInfo = sObjectMgr->GetCreatureTemplate(creature_id);
                if (!cInfo)
                    continue;

                // already loaded
                if (cInfo->PetSpellDataId)
                    continue;

                // for creature without PetSpellDataId get default pet spells from creature_template
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
    QueryResult result = WorldDatabase.Query("SELECT spell, area, quest_start, quest_start_status, quest_end_status, quest_end, aura_spell, racemask, gender, autocast FROM spell_area");
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
        spellArea.autocast            = fields[9].GetBool();

        if (SpellInfo const* spellInfo = GetSpellInfo(spell))
        {
            if (spellArea.autocast)
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
            if (spellArea.autocast && spellArea.auraSpell > 0)
            {
                bool chain = false;
                SpellAreaForAuraMapBounds saBound = GetSpellAreaForAuraMapBounds(spellArea.spellId);
                for (SpellAreaForAuraMap::const_iterator itr = saBound.first; itr != saBound.second; ++itr)
                {
                    if (itr->second->autocast && itr->second->auraSpell > 0)
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
                    if (itr2->second.autocast && itr2->second.auraSpell > 0)
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

// Temporary structure to hold spell effect entries for faster loading
struct SpellEffectArray
{
    SpellEffectArray()
    {
        effects[0] = NULL;
        effects[1] = NULL;
        effects[2] = NULL;
    }

    SpellEffectEntry const* effects[MAX_SPELL_EFFECTS];
};

void SpellMgr::LoadSpellInfoStore()
{
    uint32 oldMSTime = getMSTime();

    UnloadSpellInfoStore();
    mSpellInfoMap.resize(sSpellStore.GetNumRows(), NULL);

    std::map<uint32, SpellEffectArray> effectsBySpell;

    for (uint32 i = 0; i < sSpellEffectStore.GetNumRows(); ++i)
    {
        SpellEffectEntry const* effect = sSpellEffectStore.LookupEntry(i);
        if (!effect)
            continue;

        effectsBySpell[effect->EffectSpellId].effects[effect->EffectIndex] = effect;
    }

    for (uint32 i = 0; i < sSpellStore.GetNumRows(); ++i)
        if (SpellEntry const* spellEntry = sSpellStore.LookupEntry(i))
            mSpellInfoMap[i] = new SpellInfo(spellEntry, effectsBySpell[i].effects);

    for (uint32 spellIndex = 0; spellIndex < GetSpellInfoStoreSize(); ++spellIndex)
    {
        if (!mSpellInfoMap[spellIndex])
            continue;

        for (auto const& effect : mSpellInfoMap[spellIndex]->Effects)
        {
            //ASSERT(effect.EffectIndex < MAX_SPELL_EFFECTS, "MAX_SPELL_EFFECTS must be at least %u", effect.EffectIndex + 1);
            ASSERT(effect.Effect < TOTAL_SPELL_EFFECTS, "TOTAL_SPELL_EFFECTS must be at least %u", effect.Effect + 1);
            ASSERT(effect.ApplyAuraName < TOTAL_AURAS, "TOTAL_AURAS must be at least %u", effect.ApplyAuraName + 1);
            ASSERT(effect.TargetA.GetTarget() < TOTAL_SPELL_TARGETS, "TOTAL_SPELL_TARGETS must be at least %u", effect.TargetA.GetTarget() + 1);
            ASSERT(effect.TargetB.GetTarget() < TOTAL_SPELL_TARGETS, "TOTAL_SPELL_TARGETS must be at least %u", effect.TargetB.GetTarget() + 1);
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

            spellInfo->AttributesCu |= attributes;
            ++count;
        } while (result->NextRow());

        TC_LOG_INFO("server.loading", ">> Loaded %u spell custom attributes from DB in %u ms", count, GetMSTimeDiffToNow(oldMSTime2));
    }

    for (uint32 i = 0; i < GetSpellInfoStoreSize(); ++i)
    {
        spellInfo = mSpellInfoMap[i];
        if (!spellInfo)
            continue;

        for (uint8 j = 0; j < MAX_SPELL_EFFECTS; ++j)
        {
            switch (spellInfo->Effects[j].ApplyAuraName)
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

            switch (spellInfo->Effects[j].Effect)
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
                        uint32 enchantId = spellInfo->Effects[j].MiscValue;
                        SpellItemEnchantmentEntry const* enchant = sSpellItemEnchantmentStore.LookupEntry(enchantId);
                        if (!enchant)
                            break;

                        for (uint8 s = 0; s < MAX_ITEM_ENCHANTMENT_EFFECTS; ++s)
                        {
                            if (enchant->type[s] != ITEM_ENCHANTMENT_TYPE_COMBAT_SPELL)
                                continue;

                            SpellInfo* procInfo = _GetSpellInfo(enchant->spellid[s]);
                            if (!procInfo)
                                continue;

                            // if proced directly from enchantment, not via proc aura
                            // NOTE: Enchant Weapon - Blade Ward also has proc aura spell and is proced directly
                            // however its not expected to stack so this check is good
                            if (procInfo->HasAura(SPELL_AURA_PROC_TRIGGER_SPELL))
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

        spellInfo->_InitializeExplicitTargetMask();
    }

    TC_LOG_INFO("server.loading", ">> Loaded SpellInfo custom attributes in %u ms", GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellInfoCorrections()
{
    uint32 oldMSTime = getMSTime();

    SpellInfo* spellInfo = NULL;
    for (uint32 i = 0; i < GetSpellInfoStoreSize(); ++i)
    {
        spellInfo = (SpellInfo*)mSpellInfoMap[i];
        if (!spellInfo)
            continue;

        for (uint8 j = 0; j < MAX_SPELL_EFFECTS; ++j)
        {
            switch (spellInfo->Effects[j].Effect)
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

            // Passive talent auras cannot target pets
            if (spellInfo->IsPassive() && GetTalentSpellCost(i))
                if (spellInfo->Effects[j].TargetA.GetTarget() == TARGET_UNIT_PET)
                    spellInfo->Effects[j].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
        }

        // disable proc for magnet auras, they're handled differently
        if (spellInfo->HasAura(SPELL_AURA_SPELL_MAGNET))
            spellInfo->ProcFlags = 0;

        // due to the way spell system works, unit would change orientation in Spell::_cast
        if (spellInfo->HasAura(SPELL_AURA_CONTROL_VEHICLE))
            spellInfo->AttributesEx5 |= SPELL_ATTR5_DONT_TURN_DURING_CAST;

        if (spellInfo->ActiveIconID == 2158)  // flight
            spellInfo->Attributes |= SPELL_ATTR0_PASSIVE;

        switch (spellInfo->Id)
        {
            case 63026: // Force Cast (HACK: Target shouldn't be changed)
            case 63137: // Force Cast (HACK: Target shouldn't be changed; summon position should be untied from spell destination)
                spellInfo->Effects[0].TargetA = SpellImplicitTargetInfo(TARGET_DEST_DB);
                break;
            case 42436: // Drink! (Brewfest)
                spellInfo->Effects[EFFECT_0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ANY);
                break;
            case 52611: // Summon Skeletons
            case 52612: // Summon Skeletons
                spellInfo->Effects[EFFECT_0].MiscValueB = 64;
                break;
            case 40244: // Simon Game Visual
            case 40245: // Simon Game Visual
            case 40246: // Simon Game Visual
            case 40247: // Simon Game Visual
            case 42835: // Spout, remove damage effect, only anim is needed
                spellInfo->Effects[EFFECT_0].Effect = 0;
                break;
            case 63665: // Charge (Argent Tournament emote on riders)
            case 31298: // Sleep (needs target selection script)
            case 51904: // Summon Ghouls On Scarlet Crusade (this should use conditions table, script for this spell needs to be fixed)
            case 68933: // Wrath of Air Totem rank 2 (Aura)
            case 29200: // Purify Helboar Meat
            case 10872: // Abolish Disease Effect
            case 3137:  // Abolish Poison Effect
                spellInfo->Effects[EFFECT_0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
                spellInfo->Effects[EFFECT_0].TargetB = SpellImplicitTargetInfo();
                break;
            case 56690: // Thrust Spear
            case 60586: // Mighty Spear Thrust
            case 60776: // Claw Swipe
            case 60881: // Fatal Strike
            case 60864: // Jaws of Death
                spellInfo->AttributesEx4 |= SPELL_ATTR4_FIXED_DAMAGE;
                break;
            case 31344: // Howl of Azgalor
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_100_YARDS); // 100yards instead of 50000?!
                break;
            case 42818: // Headless Horseman - Wisp Flight Port
            case 42821: // Headless Horseman - Wisp Flight Missile
                spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(6); // 100 yards
                break;
            case 36350: // They Must Burn Bomb Aura (self)
                spellInfo->Effects[EFFECT_0].TriggerSpell = 36325; // They Must Burn Bomb Drop (DND)
                break;
            case 61407: // Energize Cores
            case 62136: // Energize Cores
            case 54069: // Energize Cores
            case 56251: // Energize Cores
                spellInfo->Effects[EFFECT_0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ENTRY);
                break;
            case 50785: // Energize Cores
            case 59372: // Energize Cores
                spellInfo->Effects[EFFECT_0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ENEMY);
                break;
            case 63320: // Glyph of Life Tap
            case 53228: // Rapid Killing (Rank 1)
            case 53232: // Rapid Killing (Rank 2)
                // Entries were not updated after spell effect change, we have to do that manually :/
                spellInfo->AttributesEx3 |= SPELL_ATTR3_CAN_PROC_WITH_TRIGGERED;
                break;
            case 5308: // Execute
                spellInfo->AttributesEx3 |= SPELL_ATTR3_CANT_TRIGGER_PROC;
                break;
            case 59725: // Improved Spell Reflection - aoe aura
                // Target entry seems to be wrong for this spell :/
                spellInfo->Effects[EFFECT_0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER_AREA_PARTY);
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_20_YARDS);
                break;
            case 43265: // Death and Decay
                // We need access to the targets of the dynaura to correctly apply the damage spell
                // Currently EFFECT_1 has PERIODIC_DUMMY aura but TARGET_UNIT_CASTER set
                // This will leave the spell in the same state as it was in 335 DBC
                spellInfo->Effects[EFFECT_0].ApplyAuraName = SPELL_AURA_PERIODIC_DUMMY;
                spellInfo->Effects[EFFECT_0].Amplitude = spellInfo->Effects[EFFECT_1].Amplitude;
                spellInfo->Effects[EFFECT_1].Effect = 0; // might as well save a few cpu cycles
                break;
            case 31347: // Doom
            case 36327: // Shoot Arcane Explosion Arrow
            case 39365: // Thundering Storm
            case 41071: // Raise Dead (HACK)
            case 42442: // Vengeance Landing Cannonfire
            case 42611: // Shoot
            case 44978: // Wild Magic
            case 45001: // Wild Magic
            case 45002: // Wild Magic
            case 45004: // Wild Magic
            case 45006: // Wild Magic
            case 45010: // Wild Magic
            case 45761: // Shoot Gun
            case 45863: // Cosmetic - Incinerate to Random Target
            case 48246: // Ball of Flame
            case 41635: // Prayer of Mending
            case 44869: // Spectral Blast
            case 45027: // Revitalize
            case 45976: // Muru Portal Channel
            case 52124: // Sky Darkener Assault
            case 52479: // Gift of the Harvester
            case 61588: // Blazing Harpoon
            case 55479: // Force Obedience
            case 28560: // Summon Blizzard (Sapphiron)
            case 53096: // Quetz'lun's Judgment
            case 70743: // AoD Special
            case 70614: // AoD Special - Vegard
            case 4020: // Safirdrang's Chill
            case 52438: // Summon Skittering Swarmer (Force Cast)
            case 52449: // Summon Skittering Infector (Force Cast)
            case 53609: // Summon Anub'ar Assassin (Force Cast)
            case 53457: // Summon Impale Trigger (AoE)
                spellInfo->MaxAffectedTargets = 1;
                break;
            case 36384: // Skartax Purple Beam
                spellInfo->MaxAffectedTargets = 2;
                break;
            case 28542: // Life Drain - Sapphiron
            case 29213: // Curse of the Plaguebringer - Noth
            case 29576: // Multi-Shot
            case 37790: // Spread Shot
            case 39992: // Needle Spine
            case 40816: // Saber Lash
            case 41303: // Soul Drain
            case 41376: // Spite
            case 45248: // Shadow Blades
            case 46771: // Flame Sear
            case 54171: // Divine Storm
            case 54172: // Divine Storm (heal)
            case 66588: // Flaming Spear
                spellInfo->MaxAffectedTargets = 3;
                break;
            case 38310: // Multi-Shot
            case 53385: // Divine Storm (Damage)
                spellInfo->MaxAffectedTargets = 4;
                break;
            case 42005: // Bloodboil
            case 38296: // Spitfire Totem
            case 37676: // Insidious Whisper
            case 46008: // Negative Energy
            case 45641: // Fire Bloom
            case 55665: // Life Drain - Sapphiron (H)
            case 28796: // Poison Bolt Volly - Faerlina
                spellInfo->MaxAffectedTargets = 5;
                break;
            case 54835: // Curse of the Plaguebringer - Noth (H)
                spellInfo->MaxAffectedTargets = 8;
                break;
            case 40827: // Sinful Beam
            case 40859: // Sinister Beam
            case 40860: // Vile Beam
            case 40861: // Wicked Beam
            case 54098: // Poison Bolt Volly - Faerlina (H)
                spellInfo->MaxAffectedTargets = 10;
                break;
            case 50312: // Unholy Frenzy
                spellInfo->MaxAffectedTargets = 15;
                break;
            case 33711: // Murmur's Touch
            case 38794: // Murmur's Touch
                spellInfo->MaxAffectedTargets = 1;
                spellInfo->Effects[EFFECT_0].TriggerSpell = 33760;
                break;
            case 44544: // Fingers of Frost
                spellInfo->Effects[EFFECT_0].SpellClassMask = flag96(685904631, 1151048, 0);
                break;
            case 53257: // Cobra Strikes
                spellInfo->ProcCharges = 2;
                spellInfo->StackAmount = 0;
                break;
            case 46867: // Wrecking Crew
            case 56611:
            case 56612:
                spellInfo->Effects[EFFECT_0].SpellClassMask = flag96(0x02000000, 0, 0);
                break;
            case 47201: // Everlasting Affliction (1)
            case 47202: // Everlasting Affliction (2)
            case 47203: // Everlasting Affliction (3)
            case 47204: // Everlasting Affliction (4)
            case 47205: // Everlasting Affliction (5)
                // add corruption to affected spells
                spellInfo->Effects[EFFECT_1].SpellClassMask[0] |= 2;
                break;
            case 49224: // Magic Suppression - DK
            case 49610: // Magic Suppression - DK
            case 49611: // Magic Suppression - DK
                spellInfo->ProcCharges = 0;
                break;
            case 52212: // Death and Decay
                spellInfo->AttributesEx6 |= SPELL_ATTR6_CAN_TARGET_INVISIBLE;
                break;
            case 37408: // Oscillation Field
                spellInfo->AttributesEx3 |= SPELL_ATTR3_STACK_FOR_DIFF_CASTERS;
                break;
            case 57470: // Renewed Hope (Rank 1)
            case 57472: // Renewed Hope (Rank 2)
                // should also affect Flash Heal
                spellInfo->Effects[EFFECT_0].SpellClassMask[0] |= 0x800;
                break;
            case 51912: // Crafty's Ultra-Advanced Proto-Typical Shortening Blaster
                spellInfo->Effects[EFFECT_0].Amplitude = 3000;
                break;
            // Master Shapeshifter: missing stance data for forms other than bear - bear version has correct data
            // To prevent aura staying on target after talent unlearned
            case 48420: // Master Shapeshifter
            case 24900: // Heart of the Wild - Cat Effect
                spellInfo->Stances = UI64LIT(1) << (FORM_CAT - 1);
                break;
            case 24899: // Heart of the Wild - Bear Effect
                spellInfo->Stances = UI64LIT(1) << (FORM_BEAR - 1);
                break;
            case 48421: // Master Shapeshifter
                spellInfo->Stances = UI64LIT(1) << (FORM_MOONKIN - 1);
                break;
            case 51466: // Elemental Oath (Rank 1)
            case 51470: // Elemental Oath (Rank 2)
                spellInfo->Effects[EFFECT_1].Effect = SPELL_EFFECT_APPLY_AURA;
                spellInfo->Effects[EFFECT_1].ApplyAuraName = SPELL_AURA_ADD_FLAT_MODIFIER;
                spellInfo->Effects[EFFECT_1].MiscValue = SPELLMOD_EFFECT2;
                spellInfo->Effects[EFFECT_1].SpellClassMask = flag96(0x00000000, 0x00004000, 0x00000000);
                break;
            case 47569: // Improved Shadowform (Rank 1)
                // with this spell atrribute aura can be stacked several times
                spellInfo->Attributes &= ~SPELL_ATTR0_NOT_SHAPESHIFT;
                break;
            case 64904: // Hymn of Hope
                spellInfo->Effects[EFFECT_1].ApplyAuraName = SPELL_AURA_MOD_INCREASE_ENERGY_PERCENT;
                break;
            case 30421: // Nether Portal - Perseverence
                spellInfo->Effects[EFFECT_2].BasePoints += 30000;
                break;
            case 41913: // Parasitic Shadowfiend Passive
                spellInfo->Effects[EFFECT_0].ApplyAuraName = SPELL_AURA_DUMMY; // proc debuff, and summon infinite fiends
                break;
            case 27892: // To Anchor 1
            case 27928: // To Anchor 1
            case 27935: // To Anchor 1
            case 27915: // Anchor to Skulls
            case 27931: // Anchor to Skulls
            case 27937: // Anchor to Skulls
            case 16177: // Ancestral Fortitude (Rank 1)
            case 16236: // Ancestral Fortitude (Rank 2)
            case 16237: // Ancestral Fortitude (Rank 3)
            case 47930: // Grace
                spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(EFFECT_RADIUS_10_YARDS);
                break;
            // target allys instead of enemies, target A is src_caster, spells with effect like that have ally target
            // this is the only known exception, probably just wrong data
            case 29214: // Wrath of the Plaguebringer
            case 54836: // Wrath of the Plaguebringer
                spellInfo->Effects[EFFECT_0].TargetB = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ALLY);
                spellInfo->Effects[EFFECT_1].TargetB = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ALLY);
                break;
            case 15290: // Vampiric Embrace
                spellInfo->AttributesEx3 |= SPELL_ATTR3_NO_INITIAL_AGGRO;
                break;
            case 63675: // Improved Devouring Plague
                spellInfo->AttributesEx3 |= SPELL_ATTR3_NO_DONE_BONUS;
                break;
            case 12721: // Deep Wounds shouldnt ignore resillience or damage taken auras because its damage is not based off a spell.
                spellInfo->AttributesEx4 = 0;
                break;
            case 8145: // Tremor Totem (instant pulse)
                spellInfo->AttributesEx2 |= SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS;
                /*no break*/
            case 6474: // Earthbind Totem (instant pulse)
                spellInfo->AttributesEx5 |= SPELL_ATTR5_START_PERIODIC_AT_APPLY;
                break;
            case 53241: // Marked for Death (Rank 1)
            case 53243: // Marked for Death (Rank 2)
                spellInfo->Effects[EFFECT_0].SpellClassMask = flag96(0x00067801, 0x10820001, 0x00000801);
                break;
            case 5176:  // Wrath
            case 2912:  // Starfire
            case 78674: // Starsurge
                spellInfo->Effects[EFFECT_1].Effect = SPELL_EFFECT_DUMMY;
                spellInfo->Effects[EFFECT_1].TargetA = TARGET_UNIT_CASTER;
                break;
            case 70728: // Exploit Weakness (needs target selection script)
            case 70840: // Devious Minds (needs target selection script)
                spellInfo->Effects[EFFECT_0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
                spellInfo->Effects[EFFECT_0].TargetB = SpellImplicitTargetInfo(TARGET_UNIT_PET);
                break;
            case 70893: // Culling The Herd (needs target selection script)
                spellInfo->Effects[EFFECT_0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
                spellInfo->Effects[EFFECT_0].TargetB = SpellImplicitTargetInfo(TARGET_UNIT_MASTER);
                break;
            case 54800: // Sigil of the Frozen Conscience - change class mask to custom extended flags of Icy Touch
                        // this is done because another spell also uses the same SpellFamilyFlags as Icy Touch
                        // SpellFamilyFlags[0] & 0x00000040 in SPELLFAMILY_DEATHKNIGHT is currently unused (3.3.5a)
                        // this needs research on modifier applying rules, does not seem to be in Attributes fields
                spellInfo->Effects[EFFECT_0].SpellClassMask = flag96(0x00000040, 0x00000000, 0x00000000);
                break;
            case 64949: // Idol of the Flourishing Life
                spellInfo->Effects[EFFECT_0].SpellClassMask = flag96(0x00000000, 0x02000000, 0x00000000);
                spellInfo->Effects[EFFECT_0].ApplyAuraName = SPELL_AURA_ADD_FLAT_MODIFIER;
                break;
            case 34231: // Libram of the Lightbringer
            case 60792: // Libram of Tolerance
            case 64956: // Libram of the Resolute
                spellInfo->Effects[EFFECT_0].SpellClassMask = flag96(0x80000000, 0x00000000, 0x00000000);
                spellInfo->Effects[EFFECT_0].ApplyAuraName = SPELL_AURA_ADD_FLAT_MODIFIER;
                break;
            case 28851: // Libram of Light
            case 28853: // Libram of Divinity
            case 32403: // Blessed Book of Nagrand
                spellInfo->Effects[EFFECT_0].SpellClassMask = flag96(0x40000000, 0x00000000, 0x00000000);
                spellInfo->Effects[EFFECT_0].ApplyAuraName = SPELL_AURA_ADD_FLAT_MODIFIER;
                break;
            case 45602: // Ride Carpet
                spellInfo->Effects[EFFECT_0].BasePoints = 0; // force seat 0, vehicle doesn't have the required seat flags for "no seat specified (-1)"
                break;
            case 61719: // Easter Lay Noblegarden Egg Aura - Interrupt flags copied from aura which this aura is linked with
                spellInfo->AuraInterruptFlags = AURA_INTERRUPT_FLAG_HITBYSPELL | AURA_INTERRUPT_FLAG_TAKE_DAMAGE;
                break;
            case 71838: // Drain Life - Bryntroll Normal
            case 71839: // Drain Life - Bryntroll Heroic
                spellInfo->AttributesEx2 |= SPELL_ATTR2_CANT_CRIT;
                break;
            case 56606: // Ride Jokkum
            case 61791: // Ride Vehicle (Yogg-Saron)
                /// @todo: remove this when basepoints of all Ride Vehicle auras are calculated correctly
                spellInfo->Effects[EFFECT_0].BasePoints = 1;
                break;
            case 59630: // Black Magic
                spellInfo->Attributes |= SPELL_ATTR0_PASSIVE;
                break;
            case 17364: // Stormstrike
            case 48278: // Paralyze
            case 53651: // Light's Beacon
                spellInfo->AttributesEx3 |= SPELL_ATTR3_STACK_FOR_DIFF_CASTERS;
                break;
            case 51798: // Brewfest - Relay Race - Intro - Quest Complete
            case 47134: // Quest Complete
                //! HACK: This spell break quest complete for alliance and on retail not used
                spellInfo->Effects[EFFECT_0].Effect = 0;
                break;
            case 15487: // Priest - Silence
            case 47476: // Deathknight - Strangulate
            case 69179: // Arcane Torrent (Rage)
                spellInfo->AttributesEx7 |= SPELL_ATTR7_INTERRUPT_ONLY_NONPLAYER;
                break;
            case 42490: // Energized!
            case 42492: // Cast Energized
                spellInfo->AttributesEx |= SPELL_ATTR1_NO_THREAT;
                break;
            case 85123: // Siege Cannon (Tol Barad)
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS);
                spellInfo->Effects[EFFECT_0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ENTRY);
                break;
            case 46842: // Flame Ring
            case 46836: // Flame Patch
                spellInfo->Effects[EFFECT_0].TargetA = SpellImplicitTargetInfo();
                break;
            case 29726: // Test Ribbon Pole Channel
                spellInfo->InterruptFlags &= ~AURA_INTERRUPT_FLAG_CAST;
                break;
            case 42767: // Sic'em
            case 43092: // Stop the Ascension!: Halfdan's Soul Destruction
                spellInfo->Effects[EFFECT_0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_NEARBY_ENTRY);
                break;
            case 46946: // Safeguard (Rank 1)
            case 46947: // Safeguard (Rank 2)
                spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(34); // Twenty-Five yards
                break;
            // VIOLET HOLD SPELLS
            //
            case 54258: // Water Globule (Ichoron)
            case 54264: // Water Globule (Ichoron)
            case 54265: // Water Globule (Ichoron)
            case 54266: // Water Globule (Ichoron)
            case 54267: // Water Globule (Ichoron)
                // in 3.3.5 there is only one radius in dbc which is 0 yards in this case
                // use max radius from 4.3.4
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_25_YARDS);
                break;
            // ENDOF VIOLET HOLD
            //
            // ULDUAR SPELLS
            //
            case 62374: // Pursued (Flame Leviathan)
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_50000_YARDS);   // 50000yd
                break;
            case 63342: // Focused Eyebeam Summon Trigger (Kologarn)
                spellInfo->MaxAffectedTargets = 1;
                break;
            case 62716: // Growth of Nature (Freya)
            case 65584: // Growth of Nature (Freya)
            case 64381: // Strength of the Pack (Auriaya)
                spellInfo->AttributesEx3 |= SPELL_ATTR3_STACK_FOR_DIFF_CASTERS;
                break;
            case 63018: // Searing Light (XT-002)
            case 65121: // Searing Light (25m) (XT-002)
            case 63024: // Gravity Bomb (XT-002)
            case 64234: // Gravity Bomb (25m) (XT-002)
                spellInfo->MaxAffectedTargets = 1;
                break;
            case 62834: // Boom (XT-002)
            // This hack is here because we suspect our implementation of spell effect execution on targets
            // is done in the wrong order. We suspect that EFFECT_0 needs to be applied on all targets,
            // then EFFECT_1, etc - instead of applying each effect on target1, then target2, etc.
            // The above situation causes the visual for this spell to be bugged, so we remove the instakill
            // effect and implement a script hack for that.
                spellInfo->Effects[EFFECT_1].Effect = 0;
                break;
            case 64386: // Terrifying Screech (Auriaya)
            case 64389: // Sentinel Blast (Auriaya)
            case 64678: // Sentinel Blast (Auriaya)
                spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(28); // 5 seconds, wrong DBC data?
                break;
            case 64321: // Potent Pheromones (Freya)
                // spell should dispel area aura, but doesn't have the attribute
                // may be db data bug, or blizz may keep reapplying area auras every update with checking immunity
                // that will be clear if we get more spells with problem like this
                spellInfo->AttributesEx |= SPELL_ATTR1_DISPEL_AURAS_ON_IMMUNITY;
                break;
            case 63414: // Spinning Up (Mimiron)
                spellInfo->Effects[EFFECT_0].TargetB = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
                spellInfo->ChannelInterruptFlags = 0;
                break;
            case 63036: // Rocket Strike (Mimiron)
                spellInfo->Speed = 0;
                break;
            case 64668: // Magnetic Field (Mimiron)
                spellInfo->Mechanic = MECHANIC_NONE;
                break;
            case 64468: // Empowering Shadows (Yogg-Saron)
            case 64486: // Empowering Shadows (Yogg-Saron)
                spellInfo->MaxAffectedTargets = 3;  // same for both modes?
                break;
            case 62301: // Cosmic Smash (Algalon the Observer)
                spellInfo->MaxAffectedTargets = 1;
                break;
            case 64598: // Cosmic Smash (Algalon the Observer)
                spellInfo->MaxAffectedTargets = 3;
                break;
            case 62293: // Cosmic Smash (Algalon the Observer)
                spellInfo->Effects[EFFECT_0].TargetB = SpellImplicitTargetInfo(TARGET_DEST_CASTER);
                break;
            case 62311: // Cosmic Smash (Algalon the Observer)
            case 64596: // Cosmic Smash (Algalon the Observer)
                spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(6);  // 100yd
                break;
            case 64014: // Expedition Base Camp Teleport
            case 64024: // Conservatory Teleport
            case 64025: // Halls of Invention Teleport
            case 64028: // Colossal Forge Teleport
            case 64029: // Shattered Walkway Teleport
            case 64030: // Antechamber Teleport
            case 64031: // Scrapyard Teleport
            case 64032: // Formation Grounds Teleport
            case 65042: // Prison of Yogg-Saron Teleport
                spellInfo->Effects[EFFECT_0].TargetA = SpellImplicitTargetInfo(TARGET_DEST_DB);
                break;
            // ENDOF ULDUAR SPELLS
            //
            // TRIAL OF THE CRUSADER SPELLS
            //
            case 66258: // Infernal Eruption (10N)
            case 67901: // Infernal Eruption (25N)
                // increase duration from 15 to 18 seconds because caster is already
                // unsummoned when spell missile hits the ground so nothing happen in result
                spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(85);
                break;
            // ENDOF TRIAL OF THE CRUSADER SPELLS
            //
            // HALLS OF REFLECTION SPELLS
            //
            case 72435: // Defiling Horror
            case 72452: // Defiling Horror
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_60_YARDS); // 60yd
                spellInfo->Effects[EFFECT_1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_60_YARDS); // 60yd
                break;
            case 72830: // Achievement Check
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_50000_YARDS); // 50000yd
                break;
            case 72900: // Start Halls of Reflection Quest AE
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS); // 200yd
                break;
            // ENDOF HALLS OF REFLECTION SPELLS
            //
            // ICECROWN CITADEL SPELLS
            //
            // THESE SPELLS ARE WORKING CORRECTLY EVEN WITHOUT THIS HACK
            // THE ONLY REASON ITS HERE IS THAT CURRENT GRID SYSTEM
            // DOES NOT ALLOW FAR OBJECT SELECTION (dist > 333)
            case 70781: // Light's Hammer Teleport
            case 70856: // Oratory of the Damned Teleport
            case 70857: // Rampart of Skulls Teleport
            case 70858: // Deathbringer's Rise Teleport
            case 70859: // Upper Spire Teleport
            case 70860: // Frozen Throne Teleport
            case 70861: // Sindragosa's Lair Teleport
                spellInfo->Effects[EFFECT_0].TargetA = SpellImplicitTargetInfo(TARGET_DEST_DB);
                break;
            case 69075: // Bone Storm (Lord Marrowgar)
            case 70834: // Bone Storm (Lord Marrowgar)
            case 70835: // Bone Storm (Lord Marrowgar)
            case 70836: // Bone Storm (Lord Marrowgar)
            case 72864: // Death Plague (Rotting Frost Giant)
            case 71160: // Plague Stench (Stinky)
            case 71161: // Plague Stench (Stinky)
            case 71123: // Decimate (Stinky & Precious)
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_100_YARDS); // 100yd
                break;
            case 71169: // Shadow's Fate
                spellInfo->AttributesEx3 |= SPELL_ATTR3_STACK_FOR_DIFF_CASTERS;
                break;
            case 72347: // Lock Players and Tap Chest
                spellInfo->AttributesEx3 &= ~SPELL_ATTR3_NO_INITIAL_AGGRO;
                break;
            case 73843: // Award Reputation - Boss Kill
            case 73844: // Award Reputation - Boss Kill
            case 73845: // Award Reputation - Boss Kill
            case 73846: // Award Reputation - Boss Kill
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_50000_YARDS); // 50000yd
                break;
            case 72378: // Blood Nova (Deathbringer Saurfang)
            case 73058: // Blood Nova (Deathbringer Saurfang)
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS);
                spellInfo->Effects[EFFECT_1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS);
                break;
            case 72769: // Scent of Blood (Deathbringer Saurfang)
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS);
                // no break
            case 72771: // Scent of Blood (Deathbringer Saurfang)
                spellInfo->Effects[EFFECT_1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS);
                break;
            case 72723: // Resistant Skin (Deathbringer Saurfang adds)
                // this spell initially granted Shadow damage immunity, however it was removed but the data was left in client
                spellInfo->Effects[EFFECT_2].Effect = 0;
                break;
            case 70460: // Coldflame Jets (Traps after Saurfang)
                spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(1); // 10 seconds
                break;
            case 71412: // Green Ooze Summon (Professor Putricide)
            case 71415: // Orange Ooze Summon (Professor Putricide)
                spellInfo->Effects[EFFECT_0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ANY);
                break;
            case 69783: // Ooze flood
            case 69797: // Ooze flood
            case 69799: // Ooze flood
            case 69802: // Ooze flood
                // Those spells are cast on creatures with same entry as caster while they have TARGET_UNIT_NEARBY_ENTRY.
                spellInfo->AttributesEx |= SPELL_ATTR1_CANT_TARGET_SELF;
                break;
            case 71159: // Awaken Plagued Zombies
                spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(21);
                break;
            case 70530: // Volatile Ooze Beam Protection (Professor Putricide)
                spellInfo->Effects[EFFECT_0].Effect = SPELL_EFFECT_APPLY_AURA; // for an unknown reason this was SPELL_EFFECT_APPLY_AREA_AURA_RAID
                break;
            // THIS IS HERE BECAUSE COOLDOWN ON CREATURE PROCS IS NOT IMPLEMENTED
            case 71604: // Mutated Strength (Professor Putricide)
            case 72673: // Mutated Strength (Professor Putricide)
            case 72674: // Mutated Strength (Professor Putricide)
            case 72675: // Mutated Strength (Professor Putricide)
                spellInfo->Effects[EFFECT_1].Effect = 0;
                break;
            case 72454: // Mutated Plague (Professor Putricide)
            case 72464: // Mutated Plague (Professor Putricide)
            case 72506: // Mutated Plague (Professor Putricide)
            case 72507: // Mutated Plague (Professor Putricide)
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_50000_YARDS); // 50000yd
                break;
            case 70911: // Unbound Plague (Professor Putricide) (needs target selection script)
            case 72854: // Unbound Plague (Professor Putricide) (needs target selection script)
            case 72855: // Unbound Plague (Professor Putricide) (needs target selection script)
            case 72856: // Unbound Plague (Professor Putricide) (needs target selection script)
                spellInfo->Effects[EFFECT_0].TargetB = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
                break;
            case 71518: // Unholy Infusion Quest Credit (Professor Putricide)
            case 72934: // Blood Infusion Quest Credit (Blood-Queen Lana'thel)
            case 72289: // Frost Infusion Quest Credit (Sindragosa)
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS); // another missing radius
                break;
            case 71708: // Empowered Flare (Blood Prince Council)
            case 72785: // Empowered Flare (Blood Prince Council)
            case 72786: // Empowered Flare (Blood Prince Council)
            case 72787: // Empowered Flare (Blood Prince Council)
                spellInfo->AttributesEx3 |= SPELL_ATTR3_NO_DONE_BONUS;
                break;
            case 71266: // Swarming Shadows
            case 72890: // Swarming Shadows
                spellInfo->AreaGroupId = 0; // originally, these require area 4522, which is... outside of Icecrown Citadel
                break;
            case 70602: // Corruption
                spellInfo->AttributesEx3 |= SPELL_ATTR3_STACK_FOR_DIFF_CASTERS;
                break;
            case 70715: // Column of Frost (visual marker)
                spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(32); // 6 seconds (missing)
                break;
            case 71085: // Mana Void (periodic aura)
                spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(9); // 30 seconds (missing)
                break;
            case 72015: // Frostbolt Volley (only heroic)
            case 72016: // Frostbolt Volley (only heroic)
                spellInfo->Effects[EFFECT_2].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_40_YARDS);
                break;
            case 70936: // Summon Suppressor (needs target selection script)
                spellInfo->Effects[EFFECT_0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ANY);
                spellInfo->Effects[EFFECT_0].TargetB = SpellImplicitTargetInfo();
                spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(157); // 90yd
                break;
            case 72706: // Achievement Check (Valithria Dreamwalker)
            case 71357: // Order Whelp
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS);   // 200yd
                break;
            case 70598: // Sindragosa's Fury
                spellInfo->Effects[EFFECT_0].TargetA = SpellImplicitTargetInfo(TARGET_DEST_DEST);
                break;
            case 69846: // Frost Bomb
                spellInfo->Speed = 0.0f;    // This spell's summon happens instantly
                break;
            case 70106: // Chilled to the Bone
                spellInfo->AttributesEx3 |= SPELL_ATTR3_NO_DONE_BONUS;
                spellInfo->AttributesEx6 |= SPELL_ATTR6_NO_DONE_PCT_DAMAGE_MODS;
                break;
            case 71614: // Ice Lock
                spellInfo->Mechanic = MECHANIC_STUN;
                break;
            case 72762: // Defile
                spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(559); // 53 seconds
                break;
            case 72743: // Defile
                spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(22); // 45 seconds
                break;
            case 72754: // Defile
            case 73708: // Defile
            case 73709: // Defile
            case 73710: // Defile
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS); // 200yd
                spellInfo->Effects[EFFECT_1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS); // 200yd
                break;
            case 69030: // Val'kyr Target Search
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS); // 200yd
                spellInfo->Effects[EFFECT_1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS); // 200yd
                spellInfo->Attributes |= SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY;
                break;
            case 69198: // Raging Spirit Visual
                spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(13); // 50000yd
                break;
            case 73654: // Harvest Souls
            case 74295: // Harvest Souls
            case 74296: // Harvest Souls
            case 74297: // Harvest Souls
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_50000_YARDS); // 50000yd
                spellInfo->Effects[EFFECT_1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_50000_YARDS); // 50000yd
                spellInfo->Effects[EFFECT_2].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_50000_YARDS); // 50000yd
                break;
            case 73655: // Harvest Soul
                spellInfo->AttributesEx3 |= SPELL_ATTR3_NO_DONE_BONUS;
                break;
            case 73540: // Summon Shadow Trap
                spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(3); // 60 seconds
                break;
            case 73530: // Shadow Trap (visual)
                spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(27); // 3 seconds
                break;
            case 73529: // Shadow Trap
                spellInfo->Effects[EFFECT_1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_10_YARDS); // 10yd
                break;
            case 74282: // Shadow Trap (searcher)
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_5_YARDS); // 5yd
                break;
            case 72595: // Restore Soul
            case 73650: // Restore Soul
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS); // 200yd
                break;
            case 74086: // Destroy Soul
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS); // 200yd
                break;
            case 74302: // Summon Spirit Bomb
            case 74342: // Summon Spirit Bomb
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS); // 200yd
                spellInfo->MaxAffectedTargets = 1;
                break;
            case 74341: // Summon Spirit Bomb
            case 74343: // Summon Spirit Bomb
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS); // 200yd
                spellInfo->MaxAffectedTargets = 3;
                break;
            case 73579: // Summon Spirit Bomb
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_25_YARDS); // 25yd
                break;
            case 72350: // Fury of Frostmourne
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_50000_YARDS); // 50000yd
                spellInfo->Effects[EFFECT_1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_50000_YARDS); // 50000yd
                break;
            case 75127: // Kill Frostmourne Players
            case 72351: // Fury of Frostmourne
            case 72431: // Jump (removes Fury of Frostmourne debuff)
            case 72429: // Mass Resurrection
            case 73159: // Play Movie
            case 73582: // Trigger Vile Spirit (Inside, Heroic)
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_50000_YARDS); // 50000yd
                break;
            case 72376: // Raise Dead
                spellInfo->MaxAffectedTargets = 3;
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_50000_YARDS); // 50000yd
                break;
            case 71809: // Jump
                spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(5); // 40yd
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_10_YARDS); // 10yd
                spellInfo->Effects[EFFECT_0].MiscValue = 190;
                break;
            case 72405: // Broken Frostmourne
                spellInfo->Effects[EFFECT_1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_20_YARDS); // 20yd
                spellInfo->AttributesEx |= SPELL_ATTR1_NO_THREAT;
                break;
            // ENDOF ICECROWN CITADEL SPELLS
            //
            // RUBY SANCTUM SPELLS
            //
            case 74799: // Soul Consumption
                spellInfo->Effects[EFFECT_1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_12_YARDS);
                break;
            case 74769: // Twilight Cutter
            case 77844: // Twilight Cutter
            case 77845: // Twilight Cutter
            case 77846: // Twilight Cutter
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_100_YARDS); // 100yd
                break;
            case 75509: // Twilight Mending
                spellInfo->AttributesEx6 |= SPELL_ATTR6_CAN_TARGET_INVISIBLE;
                spellInfo->AttributesEx2 |= SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS;
                break;
            case 75875: // Combustion and Consumption Heroic versions lacks radius data
                spellInfo->Effects[EFFECT_0].Mechanic = MECHANIC_NONE;
                spellInfo->Effects[EFFECT_1].Mechanic = MECHANIC_SNARE;
                spellInfo->Effects[EFFECT_1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_6_YARDS);
                break;
            case 75884:
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_6_YARDS);
                // No break
            case 75883:
            case 75876:
                spellInfo->Effects[EFFECT_1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_6_YARDS);
                break;
            // ENDOF RUBY SANCTUM SPELLS
            //
            // EYE OF ETERNITY SPELLS
            // All spells below work even without these changes. The LOS attribute is due to problem
            // from collision between maps & gos with active destroyed state.
            case 57473: // Arcane Storm bonus explicit visual spell
            case 57431: // Summon Static Field
            case 56091: // Flame Spike (Wyrmrest Skytalon)
            case 56092: // Engulf in Flames (Wyrmrest Skytalon)
            case 57090: // Revivify (Wyrmrest Skytalon)
            case 57143: // Life Burst (Wyrmrest Skytalon)
                spellInfo->AttributesEx2 |= SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS;
                break;
            // This would never crit on retail and it has attribute for SPELL_ATTR3_NO_DONE_BONUS because is handled from player,
            // until someone figures how to make scions not critting without hack and without making them main casters this should stay here.
            case 63934: // Arcane Barrage (cast by players and NONMELEEDAMAGELOG with caster Scion of Eternity (original caster)).
                spellInfo->AttributesEx2 |= SPELL_ATTR2_CANT_CRIT;
                break;
            // ENDOF EYE OF ETERNITY SPELLS
            //
            case 40055: // Introspection
            case 40165: // Introspection
            case 40166: // Introspection
            case 40167: // Introspection
                spellInfo->Attributes |= SPELL_ATTR0_NEGATIVE_1;
                break;
            case 2378: // Minor Fortitude
                spellInfo->ManaCost = 0;
                spellInfo->ManaPerSecond = 0;
                break;
            // Stonecore spells
            case 95284: // Teleport (from entrance to Slabhide)
            case 95285: // Teleport (from Slabhide to entrance)
                spellInfo->Effects[EFFECT_0].TargetB = SpellImplicitTargetInfo(TARGET_DEST_DB);
                break;
            // Vortex of Pinnacle spells
            case 85085: // Howling Gale
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_5_YARDS);
                break;
            case 85159: // Howling Gale
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(84); // To-do: Enum this radius entry - EFFECT_RADIUS_17_YARDS.
                break;
            // Altairus
            case 88282: // Upwind of Altairus
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_50000_YARDS);
                break;
            case 88314: // Twisting Winds
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_3_YARDS);
                spellInfo->Effects[EFFECT_1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_3_YARDS);
                break;
            // Grounding Field
            case 87721: // Beam A
            case 87722: // Beam B
            case 87723: // Beam C
                spellInfo->Effects[EFFECT_0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ANY);
                break;
                // The Lost City of the Tol'Vir Spells
                //  General Husam
            case 83131: // Summon Shockwave Target N
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_4_YARDS);
                break;
            case 83235: // Hurl
                spellInfo->Effects[EFFECT_0].Effect = SPELL_EFFECT_APPLY_AURA;
                spellInfo->Effects[EFFECT_0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ANY);
                break;
            // Halls Of Origination spells
            // Temple Guardian Anhuur
            case 76606: // Disable Beacon Beams L
            case 76608: // Disable Beacon Beams R
                // Little hack, Increase the radius so it can hit the Cave In Stalkers in the platform.
                spellInfo->Effects[EFFECT_0].MaxRadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_45_YARDS);
                break;
            case 75323: // Reverberating Hymn
                // Aura is refreshed at 3 seconds, and the tick should happen at the fourth.
                spellInfo->AttributesEx8 |= SPELL_ATTR8_DONT_RESET_PERIODIC_TIMER;
                break;
            // Rajh
            case 89133: // Solar Fire
            case 89878: // Solar Fire
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_4_YARDS);
                break;
            case 74108: // Solar Winds
            case 89130: // Solar Winds
                spellInfo->Effects[EFFECT_0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_4_YARDS);
                break;
            case 24314: // Threatening Gaze
                spellInfo->AuraInterruptFlags |= AURA_INTERRUPT_FLAG_CAST | AURA_INTERRUPT_FLAG_MOVE | AURA_INTERRUPT_FLAG_JUMP;
                break;
            case 5420: // Tree of Life (Passive)
                spellInfo->Stances = UI64LIT(1) << (FORM_TREE - 1);
                break;
            case 49376: // Feral Charge (Cat Form)
                spellInfo->AttributesEx3 &= ~SPELL_ATTR3_CANT_TRIGGER_PROC;
                break;
            case 96942:  // Gaze of Occu'thar
            case 101009: // Gaze of Occu'thar
                spellInfo->AttributesEx &= ~SPELL_ATTR1_CHANNELED_1;
                break;
            case 75610: // Evolution
                spellInfo->MaxAffectedTargets = 1;
                break;
            case 75697: // Evolution
                spellInfo->Effects[EFFECT_0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ENTRY);
                break;
            // ISLE OF CONQUEST SPELLS
            //
            case 66551: // Teleport
                spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(13); // 50000yd
                break;
            // ENDOF ISLE OF CONQUEST SPELLS
            //
            // Firelands Spells
            //
            case 99256: // Torment
            case 100230: //Torment
            case 100231: //Torment
            case 100232: //Torment
                spellInfo->Attributes |= SPELL_ATTR0_NEGATIVE_1;
                break;
            // End of Firelands Spells
            case 41485: // Deadly Poison - Black Temple
            case 41487: // Envenom - Black Temple
                spellInfo->AttributesEx6 |= SPELL_ATTR6_CAN_TARGET_INVISIBLE;
                break;
            default:
                break;
        }

        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
        {
            if (spellInfo->Effects[i].TargetA.GetSelectionCategory() == TARGET_SELECT_CATEGORY_CONE || spellInfo->Effects[i].TargetB.GetSelectionCategory() == TARGET_SELECT_CATEGORY_CONE)
                if (G3D::fuzzyEq(spellInfo->ConeAngle, 0.f))
                    spellInfo->ConeAngle = 90.f;
        }

        switch (spellInfo->SpellFamilyName)
        {
            case SPELLFAMILY_PALADIN:
                // Seals of the Pure should affect Seal of Righteousness
                if (spellInfo->SpellIconID == 25 && spellInfo->HasAttribute(SPELL_ATTR0_PASSIVE))
                    spellInfo->Effects[EFFECT_0].SpellClassMask[1] |= 0x20000000;
                break;
            case SPELLFAMILY_DEATHKNIGHT:
                // Icy Touch - extend FamilyFlags (unused value) for Sigil of the Frozen Conscience to use
                if (spellInfo->SpellIconID == 2721 && spellInfo->SpellFamilyFlags[0] & 0x2)
                    spellInfo->SpellFamilyFlags[0] |= 0x40;
                break;
        }
    }

    if (SummonPropertiesEntry* properties = const_cast<SummonPropertiesEntry*>(sSummonPropertiesStore.LookupEntry(121)))
        properties->Type = SUMMON_TYPE_TOTEM;
    if (SummonPropertiesEntry* properties = const_cast<SummonPropertiesEntry*>(sSummonPropertiesStore.LookupEntry(647))) // 52893
        properties->Type = SUMMON_TYPE_TOTEM;
    if (SummonPropertiesEntry* properties = const_cast<SummonPropertiesEntry*>(sSummonPropertiesStore.LookupEntry(628))) // Hungry Plaguehound
        properties->Category = SUMMON_CATEGORY_PET;

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
