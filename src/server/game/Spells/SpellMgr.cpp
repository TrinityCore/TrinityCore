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

#include "SpellMgr.h"
#include "BattlefieldMgr.h"
#include "BattlegroundMgr.h"
#include "BattlePetMgr.h"
#include "Chat.h"
#include "Containers.h"
#include "DB2Stores.h"
#include "DatabaseEnv.h"
#include "LanguageMgr.h"
#include "Log.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "SharedDefines.h"
#include "Spell.h"
#include "SpellAuraDefines.h"
#include "SpellInfo.h"
#include "StringConvert.h"
#include <G3D/g3dmath.h>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/composite_key.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>

namespace
{
    struct SpellIdDifficultyIndex;
    struct SpellIdIndex;

    boost::multi_index::multi_index_container<
        SpellInfo,
        boost::multi_index::indexed_by<
            boost::multi_index::hashed_unique<
                boost::multi_index::tag<SpellIdDifficultyIndex>,
                boost::multi_index::composite_key<
                    SpellInfo,
                    boost::multi_index::member<SpellInfo, uint32 const, &SpellInfo::Id>,
                    boost::multi_index::member<SpellInfo, Difficulty const, &SpellInfo::Difficulty>
                >
            >,
            boost::multi_index::hashed_non_unique<
                boost::multi_index::tag<SpellIdIndex>,
                boost::multi_index::member<SpellInfo, uint32 const, &SpellInfo::Id>
            >
        >
    > mSpellInfoMap;

    class ServersideSpellName
    {
    public:
        explicit ServersideSpellName(uint32 id, std::string name) : _nameStorage(std::move(name))
        {
            Name.ID = id;
            InitPointers();
        }

        ServersideSpellName(ServersideSpellName const& right) : _nameStorage(right._nameStorage)
        {
            Name.ID = right.Name.ID;
            InitPointers();
        }

        ServersideSpellName(ServersideSpellName&& right) noexcept : _nameStorage(std::move(right._nameStorage))
        {
            Name.ID = right.Name.ID;
            InitPointers();
            right.InitPointers();
        }

        SpellNameEntry Name;

    private:
        void InitPointers()
        {
            std::fill(std::begin(Name.Name.Str), std::end(Name.Name.Str), _nameStorage.c_str());
        }

        std::string _nameStorage;
    };

    std::vector<ServersideSpellName> mServersideSpellNames;

    std::unordered_map<std::pair<uint32, Difficulty>, SpellProcEntry> mSpellProcMap;
    std::unordered_map<int32, CreatureImmunities> mCreatureImmunities;
}

PetFamilySpellsStore sPetFamilySpellsStore;

bool IsPrimaryProfessionSkill(uint32 skill)
{
    SkillLineEntry const* pSkill = sSkillLineStore.LookupEntry(skill);
    return pSkill && pSkill->CategoryID == SKILL_CATEGORY_PROFESSION && !pSkill->ParentSkillLineID;
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
    for (SpellEffectInfo const& spellEffectInfo : spellInfo->GetEffects())
    {
        switch (spellEffectInfo.Effect)
        {
            // craft spell for crafting non-existed item (break client recipes list show)
            case SPELL_EFFECT_CREATE_ITEM:
            case SPELL_EFFECT_CREATE_LOOT:
            {
                if (spellEffectInfo.ItemType == 0)
                {
                    // skip auto-loot crafting spells, it does not need explicit item info (but has special fake items sometimes).
                    if (!spellInfo->IsLootCrafting())
                    {
                        if (msg)
                        {
                            if (player)
                                ChatHandler(player->GetSession()).PSendSysMessage("The craft spell %u does not have a create item entry.", spellInfo->Id);
                            else
                                TC_LOG_ERROR("sql.sql", "The craft spell {} does not have a create item entry.", spellInfo->Id);
                        }
                        return false;
                    }

                }
                // also possible IsLootCrafting case but fake items must exist anyway
                else if (!sObjectMgr->GetItemTemplate(spellEffectInfo.ItemType))
                {
                    if (msg)
                    {
                        if (player)
                            ChatHandler(player->GetSession()).PSendSysMessage("Craft spell %u has created a non-existing in DB item (Entry: %u) and then...", spellInfo->Id, spellEffectInfo.ItemType);
                        else
                            TC_LOG_ERROR("sql.sql", "Craft spell {} has created a non-existing item in DB item (Entry: {}) and then...", spellInfo->Id, spellEffectInfo.ItemType);
                    }
                    return false;
                }

                needCheckReagents = true;
                break;
            }
            case SPELL_EFFECT_LEARN_SPELL:
            {
                SpellInfo const* spellInfo2 = sSpellMgr->GetSpellInfo(spellEffectInfo.TriggerSpell, DIFFICULTY_NONE);
                if (!IsSpellValid(spellInfo2, player, msg))
                {
                    if (msg)
                    {
                        if (player)
                            ChatHandler(player->GetSession()).PSendSysMessage("Spell %u learn to broken spell %u, and then...", spellInfo->Id, spellEffectInfo.TriggerSpell);
                        else
                            TC_LOG_ERROR("sql.sql", "Spell {} learn to invalid spell {}, and then...", spellInfo->Id, spellEffectInfo.TriggerSpell);
                    }
                    return false;
                }
                break;
            }
            default:
                break;
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
                        TC_LOG_ERROR("sql.sql", "Craft spell {} refers to a non-existing reagent in DB, item (Entry: {}) and then...", spellInfo->Id, spellInfo->Reagent[j]);
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
        return nullptr;

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
        return nullptr;
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
    return nullptr;
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

SpellProcEntry const* SpellMgr::GetSpellProcEntry(SpellInfo const* spellInfo) const
{
    SpellProcEntry const* procEntry = Trinity::Containers::MapGetValuePtr(mSpellProcMap, { spellInfo->Id, spellInfo->Difficulty });
    if (procEntry)
        return procEntry;

    if (DifficultyEntry const* difficulty = sDifficultyStore.LookupEntry(spellInfo->Difficulty))
    {
        do
        {
            procEntry = Trinity::Containers::MapGetValuePtr(mSpellProcMap, { spellInfo->Id, Difficulty(difficulty->FallbackDifficultyID) });
            if (procEntry)
                return procEntry;

            difficulty = sDifficultyStore.LookupEntry(difficulty->FallbackDifficultyID);
        } while (difficulty);
    }

    return nullptr;
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
    if (eventInfo.GetTypeMask() & (PROC_FLAG_HEARTBEAT | PROC_FLAG_KILL | PROC_FLAG_DEATH))
        return true;

    // check school mask (if set) for other trigger types
    if (procEntry.SchoolMask && !(eventInfo.GetSchoolMask() & procEntry.SchoolMask))
        return false;

    // check spell family name/flags (if set) for spells
    if (eventInfo.GetTypeMask() & SPELL_PROC_FLAG_MASK)
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
    return nullptr;
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
        return nullptr;
}

SpellEnchantProcEntry const* SpellMgr::GetSpellEnchantProcEvent(uint32 enchId) const
{
    SpellEnchantProcEventMap::const_iterator itr = mSpellEnchantProcEventMap.find(enchId);
    if (itr != mSpellEnchantProcEventMap.end())
        return &itr->second;
    return nullptr;
}

bool SpellMgr::IsArenaAllowedEnchancment(uint32 ench_id) const
{
    if (SpellItemEnchantmentEntry const* enchantment = sSpellItemEnchantmentStore.LookupEntry(ench_id))
        return enchantment->GetFlags().HasFlag(SpellItemEnchantmentFlags::AllowEnteringArena);

    return false;
}

std::vector<int32> const* SpellMgr::GetSpellLinked(SpellLinkedType type, uint32 spell_id) const
{
    return Trinity::Containers::MapGetValuePtr(mSpellLinkedMap, { type, spell_id });
}

PetLevelupSpellSet const* SpellMgr::GetPetLevelupSpellList(uint32 petFamily) const
{
    PetLevelupSpellMap::const_iterator itr = mPetLevelupSpellMap.find(petFamily);
    if (itr != mPetLevelupSpellMap.end())
        return &itr->second;
    else
        return nullptr;
}

PetDefaultSpellsEntry const* SpellMgr::GetPetDefaultSpellsEntry(int32 id) const
{
    PetDefaultSpellsMap::const_iterator itr = mPetDefaultSpellsMap.find(id);
    if (itr != mPetDefaultSpellsMap.end())
        return &itr->second;
    return nullptr;
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

CreatureImmunities const* SpellMgr::GetCreatureImmunities(int32 creatureImmunitiesId)
{
    return Trinity::Containers::MapGetValuePtr(mCreatureImmunities, creatureImmunitiesId);
}

SpellInfo const* SpellMgr::GetSpellInfo(uint32 spellId, Difficulty difficulty) const
{
    auto itr = mSpellInfoMap.find(boost::make_tuple(spellId, difficulty));
    if (itr != mSpellInfoMap.end())
        return &*itr;

    if (DifficultyEntry const* difficultyEntry = sDifficultyStore.LookupEntry(difficulty))
    {
        do
        {
            itr = mSpellInfoMap.find(boost::make_tuple(spellId, Difficulty(difficultyEntry->FallbackDifficultyID)));
            if (itr != mSpellInfoMap.end())
                return &*itr;

            difficultyEntry = sDifficultyStore.LookupEntry(difficultyEntry->FallbackDifficultyID);
        } while (difficultyEntry);
    }

    return nullptr;
}

auto _GetSpellInfo(uint32 spellId)
{
    return Trinity::Containers::MakeIteratorPair(mSpellInfoMap.get<SpellIdIndex>().equal_range(spellId));
}

void SpellMgr::ForEachSpellInfo(std::function<void(SpellInfo const*)> callback)
{
    for (SpellInfo const& spellInfo : mSpellInfoMap)
        callback(&spellInfo);
}

void SpellMgr::ForEachSpellInfoDifficulty(uint32 spellId, std::function<void(SpellInfo const*)> callback)
{
    for (SpellInfo const& spellInfo : _GetSpellInfo(spellId))
        callback(&spellInfo);
}

bool SpellArea::IsFitToRequirements(Player const* player, uint32 newZone, uint32 newArea) const
{
    if (gender != GENDER_NONE)                   // is not expected gender
        if (!player || gender != player->GetNativeGender())
            return false;

    if (!raceMask.IsEmpty())                     // is not expected race
        if (!player || !raceMask.HasRace(player->GetRace()))
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

    // Extra conditions
    switch (spellId)
    {
        case 91604: // No fly Zone - Wintergrasp
        {
            if (!player)
                return false;

            Battlefield* Bf = sBattlefieldMgr->GetBattlefieldToZoneId(player->GetMap(), player->GetZoneId());
            if (!Bf || Bf->CanFlyIn() || (!player->HasAuraType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED) && !player->HasAuraType(SPELL_AURA_FLY)))
                return false;
            break;
        }
        case 56618: // Horde Controls Factory Phase Shift
        case 56617: // Alliance Controls Factory Phase Shift
        {
            if (!player)
                return false;

            Battlefield* bf = sBattlefieldMgr->GetBattlefieldToZoneId(player->GetMap(), player->GetZoneId());

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

            if (Battlefield* battlefieldWG = sBattlefieldMgr->GetBattlefieldByBattleId(player->GetMap(), BATTLEFIELD_BATTLEID_WG))
                return battlefieldWG->IsEnabled() && (player->GetTeamId() == battlefieldWG->GetDefenderTeam()) && !battlefieldWG->IsWarTime();
            break;
        }
        case 74411: // Battleground - Dampening
        {
            if (!player)
                return false;

            if (Battlefield* bf = sBattlefieldMgr->GetBattlefieldToZoneId(player->GetMap(), player->GetZoneId()))
                return bf->IsWarTime();
            break;
        }

    }

    return true;
}

void SpellMgr::UnloadSpellInfoChains()
{
    for (SpellChainMap::iterator itr = mSpellChains.begin(); itr != mSpellChains.end(); ++itr)
        for (SpellInfo const& spellInfo : _GetSpellInfo(itr->first))
            const_cast<SpellInfo&>(spellInfo).ChainEntry = nullptr;

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

        if (!GetSpellInfo(skillAbility->SupercedesSpell, DIFFICULTY_NONE) || !GetSpellInfo(skillAbility->Spell, DIFFICULTY_NONE))
            continue;

        chains[skillAbility->SupercedesSpell] = skillAbility->Spell;
        hasPrev.insert(skillAbility->Spell);
    }

    // each key in chains that isn't present in hasPrev is a first rank
    for (auto itr = chains.begin(); itr != chains.end(); ++itr)
    {
        if (hasPrev.count(itr->first))
            continue;

        SpellInfo const* first = AssertSpellInfo(itr->first, DIFFICULTY_NONE);
        SpellInfo const* next = AssertSpellInfo(itr->second, DIFFICULTY_NONE);

        mSpellChains[itr->first].first = first;
        mSpellChains[itr->first].prev = nullptr;
        mSpellChains[itr->first].next = next;
        mSpellChains[itr->first].last = next;
        mSpellChains[itr->first].rank = 1;
        for (SpellInfo const& difficultyInfo : _GetSpellInfo(itr->first))
            const_cast<SpellInfo&>(difficultyInfo).ChainEntry = &mSpellChains[itr->first];

        mSpellChains[itr->second].first = first;
        mSpellChains[itr->second].prev = first;
        mSpellChains[itr->second].next = nullptr;
        mSpellChains[itr->second].last = next;
        mSpellChains[itr->second].rank = 2;
        for (SpellInfo const& difficultyInfo : _GetSpellInfo(itr->second))
            const_cast<SpellInfo&>(difficultyInfo).ChainEntry = &mSpellChains[itr->second];

        uint8 rank = 3;
        auto nextItr = chains.find(itr->second);
        while (nextItr != chains.end())
        {
            SpellInfo const* prev = AssertSpellInfo(nextItr->first, DIFFICULTY_NONE); // already checked in previous iteration (or above, in case this is the first one)
            SpellInfo const* last = AssertSpellInfo(nextItr->second, DIFFICULTY_NONE);

            mSpellChains[nextItr->first].next = last;

            mSpellChains[nextItr->second].first = first;
            mSpellChains[nextItr->second].prev = prev;
            mSpellChains[nextItr->second].next = nullptr;
            mSpellChains[nextItr->second].last = last;
            mSpellChains[nextItr->second].rank = rank++;
            for (SpellInfo const& difficultyInfo : _GetSpellInfo(nextItr->second))
                const_cast<SpellInfo&>(difficultyInfo).ChainEntry = &mSpellChains[nextItr->second];

            // fill 'last'
            do
            {
                mSpellChains[prev->Id].last = last;
                prev = mSpellChains[prev->Id].prev;
            } while (prev);

            nextItr = chains.find(nextItr->second);
        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} spell rank records in {} ms", uint32(mSpellChains.size()), GetMSTimeDiffToNow(oldMSTime));
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
        SpellInfo const* spell = GetSpellInfo(spell_id, DIFFICULTY_NONE);
        if (!spell)
        {
            TC_LOG_ERROR("sql.sql", "spell_id {} in `spell_required` table could not be found in dbc, skipped.", spell_id);
            continue;
        }

        SpellInfo const* reqSpell = GetSpellInfo(spell_req, DIFFICULTY_NONE);
        if (!reqSpell)
        {
            TC_LOG_ERROR("sql.sql", "req_spell {} in `spell_required` table could not be found in dbc, skipped.", spell_req);
            continue;
        }

        if (spell->IsRankOf(reqSpell))
        {
            TC_LOG_ERROR("sql.sql", "req_spell {} and spell_id {} in `spell_required` table are ranks of the same spell, entry not needed, skipped.", spell_req, spell_id);
            continue;
        }

        if (IsSpellRequiringSpell(spell_id, spell_req))
        {
            TC_LOG_ERROR("sql.sql", "Duplicate entry of req_spell {} and spell_id {} in `spell_required`, skipped.", spell_req, spell_id);
            continue;
        }

        mSpellReq.insert (std::pair<uint32, uint32>(spell_id, spell_req));
        mSpellsReqSpell.insert (std::pair<uint32, uint32>(spell_req, spell_id));
        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} spell required records in {} ms", count, GetMSTimeDiffToNow(oldMSTime));

}

void SpellMgr::LoadSpellLearnSkills()
{
    uint32 oldMSTime = getMSTime();

    mSpellLearnSkills.clear();                              // need for reload case

    // search auto-learned skills and add its to map also for use in unlearn spells/talents
    uint32 dbc_count = 0;
    for (SpellInfo const& entry : mSpellInfoMap)
    {
        if (entry.Difficulty != DIFFICULTY_NONE)
            continue;

        for (SpellEffectInfo const& spellEffectInfo : entry.GetEffects())
        {
            SpellLearnSkillNode dbc_node;
            switch (spellEffectInfo.Effect)
            {
                case SPELL_EFFECT_SKILL:
                    dbc_node.skill = uint16(spellEffectInfo.MiscValue);
                    dbc_node.step  = uint16(spellEffectInfo.CalcValue());
                    dbc_node.value = 0;
                    dbc_node.maxvalue = 0;
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

            mSpellLearnSkills[entry.Id] = dbc_node;
            ++dbc_count;
            break;
        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} Spell Learn Skills from DBC in {} ms", dbc_count, GetMSTimeDiffToNow(oldMSTime));
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

        SpellInfo const* spellInfo = GetSpellInfo(spell_id, DIFFICULTY_NONE);
        if (!spellInfo)
        {
            TC_LOG_ERROR("sql.sql", "The spell {} listed in `spell_learn_spell` does not exist.", spell_id);
            continue;
        }

        if (!GetSpellInfo(node.Spell, DIFFICULTY_NONE))
        {
            TC_LOG_ERROR("sql.sql", "The spell {} listed in `spell_learn_spell` learning non-existing spell {}.", spell_id, node.Spell);
            continue;
        }

        if (spellInfo->HasAttribute(SPELL_ATTR0_CU_IS_TALENT))
        {
            TC_LOG_ERROR("sql.sql", "The spell {} listed in `spell_learn_spell` attempts learning talent spell {}, skipped.", spell_id, node.Spell);
            continue;
        }

        mSpellLearnSpells.insert(SpellLearnSpellMap::value_type(spell_id, node));

        ++count;
    } while (result->NextRow());

    // copy state loaded from db
    SpellLearnSpellMap dbSpellLearnSpells = mSpellLearnSpells;

    // search auto-learned spells and add its to map also for use in unlearn spells/talents
    uint32 dbc_count = 0;
    for (SpellInfo const& entry : mSpellInfoMap)
    {
        if (entry.Difficulty != DIFFICULTY_NONE)
            continue;

        for (SpellEffectInfo const& spellEffectInfo : entry.GetEffects())
        {
            if (spellEffectInfo.IsEffect(SPELL_EFFECT_LEARN_SPELL))
            {
                SpellLearnSpellNode dbc_node;
                dbc_node.Spell = spellEffectInfo.TriggerSpell;
                dbc_node.Active = true;                     // all dbc based learned spells is active (show in spell book or hide by client itself)
                dbc_node.OverridesSpell = 0;

                // ignore learning not existed spells (broken/outdated/or generic learnig spell 483
                if (!GetSpellInfo(dbc_node.Spell, DIFFICULTY_NONE))
                    continue;

                // talent or passive spells or skill-step spells auto-cast and not need dependent learning,
                // pet teaching spells must not be dependent learning (cast)
                // other required explicit dependent learning
                dbc_node.AutoLearned = spellEffectInfo.TargetA.GetTarget() == TARGET_UNIT_PET || entry.HasAttribute(SPELL_ATTR0_CU_IS_TALENT) || entry.IsPassive() || entry.HasEffect(SPELL_EFFECT_SKILL_STEP);

                SpellLearnSpellMapBounds db_node_bounds = dbSpellLearnSpells.equal_range(entry.Id);

                bool found = false;
                for (SpellLearnSpellMap::const_iterator itr = db_node_bounds.first; itr != db_node_bounds.second; ++itr)
                {
                    if (itr->second.Spell == dbc_node.Spell)
                    {
                        TC_LOG_ERROR("sql.sql", "The spell {} is an auto-learn spell {} in spell.dbc and the record in `spell_learn_spell` is redundant. Please update your DB.",
                            entry.Id, dbc_node.Spell);
                        found = true;
                        break;
                    }
                }

                if (!found)                                  // add new spell-spell pair if not found
                {
                    mSpellLearnSpells.insert(SpellLearnSpellMap::value_type(entry.Id, dbc_node));
                    ++dbc_count;
                }
            }
        }
    }

    for (SpellLearnSpellEntry const* spellLearnSpell : sSpellLearnSpellStore)
    {
        if (!GetSpellInfo(spellLearnSpell->SpellID, DIFFICULTY_NONE) ||
            !GetSpellInfo(spellLearnSpell->LearnSpellID, DIFFICULTY_NONE))
            continue;

        SpellLearnSpellMapBounds db_node_bounds = dbSpellLearnSpells.equal_range(spellLearnSpell->SpellID);
        bool found = false;
        for (SpellLearnSpellMap::const_iterator itr = db_node_bounds.first; itr != db_node_bounds.second; ++itr)
        {
            if (int32(itr->second.Spell) == spellLearnSpell->LearnSpellID)
            {
                TC_LOG_ERROR("sql.sql", "Found redundant record (entry: {}, SpellID: {}) in `spell_learn_spell`, spell added automatically from SpellLearnSpell.db2", spellLearnSpell->SpellID, spellLearnSpell->LearnSpellID);
                found = true;
                break;
            }
        }

        if (found)
            continue;

        // Check if it is already found in Spell.dbc, ignore silently if yes
        SpellLearnSpellMapBounds dbc_node_bounds = GetSpellLearnSpellMapBounds(spellLearnSpell->SpellID);
        found = false;
        for (SpellLearnSpellMap::const_iterator itr = dbc_node_bounds.first; itr != dbc_node_bounds.second; ++itr)
        {
            if (int32(itr->second.Spell) == spellLearnSpell->LearnSpellID)
            {
                found = true;
                break;
            }
        }

        if (found)
            continue;

        SpellLearnSpellNode dbcLearnNode;
        dbcLearnNode.Spell = spellLearnSpell->LearnSpellID;
        dbcLearnNode.OverridesSpell = spellLearnSpell->OverridesSpellID;
        dbcLearnNode.Active = true;
        dbcLearnNode.AutoLearned = false;

        mSpellLearnSpells.insert(SpellLearnSpellMap::value_type(spellLearnSpell->SpellID, dbcLearnNode));
        ++dbc_count;
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} spell learn spells, {} found in Spell.dbc in {} ms", count, dbc_count, GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellTargetPositions()
{
    uint32 oldMSTime = getMSTime();

    mSpellTargetPositions.clear();                                // need for reload case

    //                                               0   1            2      3          4          5          6
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
            TC_LOG_ERROR("sql.sql", "Spell (Id: {}, EffectIndex: {}) is using a non-existant MapID (ID: {}).", spellId, uint32(effIndex), st.target_mapId);
            continue;
        }

        if (st.target_X == 0 && st.target_Y == 0 && st.target_Z == 0)
        {
            TC_LOG_ERROR("sql.sql", "Spell (Id: {}, EffectIndex: {}): target coordinates not provided.", spellId, uint32(effIndex));
            continue;
        }

        SpellInfo const* spellInfo = GetSpellInfo(spellId, DIFFICULTY_NONE);
        if (!spellInfo)
        {
            TC_LOG_ERROR("sql.sql", "Spell (Id: {}) listed in `spell_target_position` does not exist.", spellId);
            continue;
        }

        if (effIndex >= spellInfo->GetEffects().size())
        {
            TC_LOG_ERROR("sql.sql", "Spell (Id: {}, EffectIndex: {}) listed in `spell_target_position` does not have an effect at index {}.", spellId, uint32(effIndex), uint32(effIndex));
            continue;
        }

        if (!fields[6].IsNull())
            st.target_Orientation = fields[6].GetFloat();
        else
        {
            // target facing is in degrees for 6484 & 9268... (blizz sucks)
            if (spellInfo->GetEffect(effIndex).PositionFacing > 2 * float(M_PI))
                st.target_Orientation = spellInfo->GetEffect(effIndex).PositionFacing * float(M_PI) / 180;
            else
                st.target_Orientation = spellInfo->GetEffect(effIndex).PositionFacing;
        }

        auto hasTarget = [&](Targets target)
        {
            SpellEffectInfo const& spellEffectInfo = spellInfo->GetEffect(effIndex);
            return spellEffectInfo.TargetA.GetTarget() == target || spellEffectInfo.TargetB.GetTarget() == target;
        };

        if (hasTarget(TARGET_DEST_DB) || hasTarget(TARGET_DEST_NEARBY_ENTRY_OR_DB))
        {
            std::pair<uint32, SpellEffIndex> key = std::make_pair(spellId, effIndex);
            mSpellTargetPositions[key] = st;
            ++count;
        }
        else
        {
            TC_LOG_ERROR("sql.sql", "Spell (Id: {}, effIndex: {}) listed in `spell_target_position` does not have a target TARGET_DEST_DB (17).", spellId, uint32(effIndex));
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
                TC_LOG_DEBUG("spells", "Spell (Id: {}, EffectIndex: {}) does not have record in `spell_target_position`.", i, j);
        }
    }
    */

    TC_LOG_INFO("server.loading", ">> Loaded {} spell teleport coordinates in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
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
            TC_LOG_ERROR("sql.sql", "SpellGroup id {} listed in `spell_group` is in core range, but is not defined in core!", group_id);
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
                TC_LOG_ERROR("sql.sql", "SpellGroup id {} listed in `spell_group` does not exist", abs(itr->second));
                itr = mSpellGroupSpell.erase(itr);
            }
            else
                ++itr;
        }
        else
        {
            SpellInfo const* spellInfo = GetSpellInfo(itr->second, DIFFICULTY_NONE);
            if (!spellInfo)
            {
                TC_LOG_ERROR("sql.sql", "The spell {} listed in `spell_group` does not exist", itr->second);
                itr = mSpellGroupSpell.erase(itr);
            }
            else if (spellInfo->GetRank() > 1)
            {
                TC_LOG_ERROR("sql.sql", "The spell {} listed in `spell_group` is not the first rank of the spell.", itr->second);
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

    TC_LOG_INFO("server.loading", ">> Loaded {} spell group definitions in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
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
            TC_LOG_ERROR("sql.sql", "SpellGroupStackRule {} listed in `spell_group_stack_rules` does not exist.", stack_rule);
            continue;
        }

        auto bounds = GetSpellGroupSpellMapBounds((SpellGroup)group_id);
        if (bounds.first == bounds.second)
        {
            TC_LOG_ERROR("sql.sql", "SpellGroup id {} listed in `spell_group_stack_rules` does not exist.", group_id);
            continue;
        }

        mSpellGroupStack.emplace(SpellGroup(group_id), SpellGroupStackRule(stack_rule));

        // different container for same effect stack rules, need to check effect types
        if (stack_rule == SPELL_GROUP_STACK_RULE_EXCLUSIVE_SAME_EFFECT)
            sameEffectGroups.push_back(group_id);

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} spell group stack rules in {} ms", count, GetMSTimeDiffToNow(oldMSTime));

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
                SpellInfo const* spellInfo = AssertSpellInfo(spellId, DIFFICULTY_NONE);
                for (SpellEffectInfo const& spellEffectInfo : spellInfo->GetEffects())
                {
                    if (!spellEffectInfo.IsAura())
                        continue;

                    uint32 auraName = spellEffectInfo.ApplyAuraName;
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
            SpellInfo const* spellInfo = AssertSpellInfo(spellId, DIFFICULTY_NONE);

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
                TC_LOG_ERROR("sql.sql", "SpellId {} listed in `spell_group` with stack rule 3 does not share aura assigned for group {}", spellId, group_id);
        }

        mSpellSameEffectStack[SpellGroup(group_id)] = auraTypes;
        ++count;
    }

    TC_LOG_INFO("server.loading", ">> Parsed {} SPELL_GROUP_STACK_RULE_EXCLUSIVE_SAME_EFFECT stack rules in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellProcs()
{
    uint32 oldMSTime = getMSTime();

    mSpellProcMap.clear();                             // need for reload case

    //                                                     0           1                2                 3                 4                 5                 6
    QueryResult result = WorldDatabase.Query("SELECT SpellId, SchoolMask, SpellFamilyName, SpellFamilyMask0, SpellFamilyMask1, SpellFamilyMask2, SpellFamilyMask3, "
    //           7           8              9              10       11              12                  13              14      15        16       17
        "ProcFlags, ProcFlags2, SpellTypeMask, SpellPhaseMask, HitMask, AttributesMask, DisableEffectsMask, ProcsPerMinute, Chance, Cooldown, Charges FROM spell_proc");

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

            SpellInfo const* spellInfo = GetSpellInfo(spellId, DIFFICULTY_NONE);
            if (!spellInfo)
            {
                TC_LOG_ERROR("sql.sql", "The spell {} listed in `spell_proc` does not exist", spellId);
                continue;
            }

            if (allRanks)
            {
                if (!spellInfo->IsRanked())
                    TC_LOG_ERROR("sql.sql", "The spell {} listed in `spell_proc` with all ranks, but spell has no ranks.", spellId);

                if (spellInfo->GetFirstRankSpell()->Id != uint32(spellId))
                {
                    TC_LOG_ERROR("sql.sql", "The spell {} listed in `spell_proc` is not the first rank of the spell.", spellId);
                    continue;
                }
            }

            SpellProcEntry baseProcEntry;

            baseProcEntry.SchoolMask         = fields[1].GetUInt8();
            baseProcEntry.SpellFamilyName    = fields[2].GetUInt16();
            baseProcEntry.SpellFamilyMask[0] = fields[3].GetUInt32();
            baseProcEntry.SpellFamilyMask[1] = fields[4].GetUInt32();
            baseProcEntry.SpellFamilyMask[2] = fields[5].GetUInt32();
            baseProcEntry.SpellFamilyMask[3] = fields[6].GetUInt32();
            baseProcEntry.ProcFlags[0]       = fields[7].GetUInt32();
            baseProcEntry.ProcFlags[1]       = fields[8].GetUInt32();
            baseProcEntry.SpellTypeMask      = ProcFlagsSpellType(fields[9].GetUInt32());
            baseProcEntry.SpellPhaseMask     = ProcFlagsSpellPhase(fields[10].GetUInt32());
            baseProcEntry.HitMask            = ProcFlagsHit(fields[11].GetUInt32());
            baseProcEntry.AttributesMask     = ProcAttributes(fields[12].GetUInt32());
            baseProcEntry.DisableEffectsMask = fields[13].GetUInt32();
            baseProcEntry.ProcsPerMinute     = fields[14].GetFloat();
            baseProcEntry.Chance             = fields[15].GetFloat();
            baseProcEntry.Cooldown           = Milliseconds(fields[16].GetUInt32());
            baseProcEntry.Charges            = fields[17].GetUInt8();

            while (spellInfo)
            {
                if (mSpellProcMap.find({ spellInfo->Id, spellInfo->Difficulty }) != mSpellProcMap.end())
                {
                    TC_LOG_ERROR("sql.sql", "The spell {} listed in `spell_proc` already has its first rank in the table.", spellInfo->Id);
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
                    TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId {} has wrong `SchoolMask` set: {}", spellInfo->Id, procEntry.SchoolMask);
                if (procEntry.SpellFamilyName && !DB2Manager::IsValidSpellFamiliyName(SpellFamilyNames(procEntry.SpellFamilyName)))
                    TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId {} has wrong `SpellFamilyName` set: {}", spellInfo->Id, procEntry.SpellFamilyName);
                if (procEntry.Chance < 0)
                {
                    TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId {} has negative value in the `Chance` field", spellInfo->Id);
                    procEntry.Chance = 0;
                }
                if (procEntry.ProcsPerMinute < 0)
                {
                    TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId {} has negative value in the `ProcsPerMinute` field", spellInfo->Id);
                    procEntry.ProcsPerMinute = 0;
                }
                if (!procEntry.ProcFlags)
                    TC_LOG_ERROR("sql.sql", "The `spell_proc` table entry for spellId {} doesn't have any `ProcFlags` value defined, proc will not be triggered.", spellInfo->Id);
                if (procEntry.SpellTypeMask & ~PROC_SPELL_TYPE_MASK_ALL)
                    TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId {} has wrong `SpellTypeMask` set: {}", spellInfo->Id, procEntry.SpellTypeMask);
                if (procEntry.SpellTypeMask && !(procEntry.ProcFlags & SPELL_PROC_FLAG_MASK))
                    TC_LOG_ERROR("sql.sql", "The `spell_proc` table entry for spellId {} has `SpellTypeMask` value defined, but it will not be used for the defined `ProcFlags` value.", spellInfo->Id);
                if (!procEntry.SpellPhaseMask && procEntry.ProcFlags & REQ_SPELL_PHASE_PROC_FLAG_MASK)
                    TC_LOG_ERROR("sql.sql", "The `spell_proc` table entry for spellId {} doesn't have any `SpellPhaseMask` value defined, but it is required for the defined `ProcFlags` value. Proc will not be triggered.", spellInfo->Id);
                if (procEntry.SpellPhaseMask & ~PROC_SPELL_PHASE_MASK_ALL)
                    TC_LOG_ERROR("sql.sql", "The `spell_proc` table entry for spellId {} has wrong `SpellPhaseMask` set: {}", spellInfo->Id, procEntry.SpellPhaseMask);
                if (procEntry.SpellPhaseMask && !(procEntry.ProcFlags & REQ_SPELL_PHASE_PROC_FLAG_MASK))
                    TC_LOG_ERROR("sql.sql", "The `spell_proc` table entry for spellId {} has a `SpellPhaseMask` value defined, but it will not be used for the defined `ProcFlags` value.", spellInfo->Id);
                if (!procEntry.SpellPhaseMask && !(procEntry.ProcFlags & REQ_SPELL_PHASE_PROC_FLAG_MASK) && procEntry.ProcFlags & PROC_FLAG_2_CAST_SUCCESSFUL)
                    procEntry.SpellPhaseMask = PROC_SPELL_PHASE_CAST; // set default phase for PROC_FLAG_2_CAST_SUCCESSFUL
                if (procEntry.HitMask & ~PROC_HIT_MASK_ALL)
                    TC_LOG_ERROR("sql.sql", "The `spell_proc` table entry for spellId {} has wrong `HitMask` set: {}", spellInfo->Id, procEntry.HitMask);
                if (procEntry.HitMask && !(procEntry.ProcFlags & TAKEN_HIT_PROC_FLAG_MASK || (procEntry.ProcFlags & DONE_HIT_PROC_FLAG_MASK && (!procEntry.SpellPhaseMask || procEntry.SpellPhaseMask & (PROC_SPELL_PHASE_HIT | PROC_SPELL_PHASE_FINISH)))))
                    TC_LOG_ERROR("sql.sql", "The `spell_proc` table entry for spellId {} has `HitMask` value defined, but it will not be used for defined `ProcFlags` and `SpellPhaseMask` values.", spellInfo->Id);
                for (SpellEffectInfo const& spellEffectInfo : spellInfo->GetEffects())
                    if ((procEntry.DisableEffectsMask & (1u << spellEffectInfo.EffectIndex)) && !spellEffectInfo.IsAura())
                        TC_LOG_ERROR("sql.sql", "The `spell_proc` table entry for spellId {} has DisableEffectsMask with effect {}, but effect {} is not an aura effect", spellInfo->Id, static_cast<uint32>(spellEffectInfo.EffectIndex), static_cast<uint32>(spellEffectInfo.EffectIndex));
                if (procEntry.AttributesMask & PROC_ATTR_REQ_SPELLMOD)
                {
                    bool found = false;
                    for (SpellEffectInfo const& spellEffectInfo : spellInfo->GetEffects())
                    {
                        if (!spellEffectInfo.IsAura())
                            continue;

                        if (spellEffectInfo.ApplyAuraName == SPELL_AURA_ADD_PCT_MODIFIER || spellEffectInfo.ApplyAuraName == SPELL_AURA_ADD_FLAT_MODIFIER
                            || spellEffectInfo.ApplyAuraName == SPELL_AURA_ADD_PCT_MODIFIER_BY_SPELL_LABEL || spellEffectInfo.ApplyAuraName == SPELL_AURA_ADD_FLAT_MODIFIER_BY_SPELL_LABEL
                            || spellEffectInfo.ApplyAuraName == SPELL_AURA_IGNORE_SPELL_COOLDOWN)
                        {
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                        TC_LOG_ERROR("sql.sql", "The `spell_proc` table entry for spellId {} has Attribute PROC_ATTR_REQ_SPELLMOD, but spell has no spell mods. Proc will not be triggered", spellInfo->Id);
                }
                if (procEntry.AttributesMask & ~PROC_ATTR_ALL_ALLOWED)
                {
                    TC_LOG_ERROR("sql.sql", "The `spell_proc` table entry for spellId {} has `AttributesMask` value specifying invalid attributes 0x{:02X}.", spellInfo->Id, procEntry.AttributesMask & ~PROC_ATTR_ALL_ALLOWED);
                    procEntry.AttributesMask &= PROC_ATTR_ALL_ALLOWED;
                }

                mSpellProcMap[{ spellInfo->Id, spellInfo->Difficulty }] = procEntry;

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

    TC_LOG_INFO("server.loading", ">> Loaded {} spell proc conditions and data in {} ms", count, GetMSTimeDiffToNow(oldMSTime));

    // Define can trigger auras
    bool isTriggerAura[TOTAL_AURAS];
    // Triggered always, even from triggered spells
    bool isAlwaysTriggeredAura[TOTAL_AURAS];
    // SpellTypeMask to add to the proc
    ProcFlagsSpellType spellTypeMask[TOTAL_AURAS];

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
    isTriggerAura[SPELL_AURA_PERIODIC_DUMMY] = true;
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
    isTriggerAura[SPELL_AURA_MOD_SCHOOL_MASK_DAMAGE_FROM_CASTER] = true;
    isTriggerAura[SPELL_AURA_MOD_SPELL_DAMAGE_FROM_CASTER] = true;
    isTriggerAura[SPELL_AURA_MOD_SPELL_CRIT_CHANCE] = true;
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
    isTriggerAura[SPELL_AURA_MOD_ROOT_2] = true;
    isTriggerAura[SPELL_AURA_IGNORE_SPELL_COOLDOWN] = true;

    isAlwaysTriggeredAura[SPELL_AURA_OVERRIDE_CLASS_SCRIPTS] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_STEALTH] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_CONFUSE] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_FEAR] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_ROOT] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_STUN] = true;
    isAlwaysTriggeredAura[SPELL_AURA_TRANSFORM] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_INVISIBILITY] = true;
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
    spellTypeMask[SPELL_AURA_MOD_INVISIBILITY] = PROC_SPELL_TYPE_DAMAGE;

    // This generates default procs to retain compatibility with previous proc system
    TC_LOG_INFO("server.loading", "Generating spell proc data from SpellMap...");
    count = 0;
    oldMSTime = getMSTime();

    for (SpellInfo const& spellInfo : mSpellInfoMap)
    {
        // Data already present in DB, overwrites default proc
        if (mSpellProcMap.find({ spellInfo.Id, spellInfo.Difficulty }) != mSpellProcMap.end())
            continue;

        // Nothing to do if no flags set
        if (!spellInfo.ProcFlags)
            continue;

        bool addTriggerFlag = false;
        ProcFlagsSpellType procSpellTypeMask = PROC_SPELL_TYPE_NONE;
        uint32 nonProcMask = 0;
        for (SpellEffectInfo const& spellEffectInfo : spellInfo.GetEffects())
        {
            if (!spellEffectInfo.IsEffect())
                continue;

            uint32 auraName = spellEffectInfo.ApplyAuraName;
            if (!auraName)
                continue;

            if (!isTriggerAura[auraName])
            {
                // explicitly disable non proccing auras to avoid losing charges on self proc
                nonProcMask |= 1 << spellEffectInfo.EffectIndex;
                continue;
            }

            procSpellTypeMask |= spellTypeMask[auraName];
            if (isAlwaysTriggeredAura[auraName])
                addTriggerFlag = true;

            // many proc auras with taken procFlag mask don't have attribute "can proc with triggered"
            // they should proc nevertheless (example mage armor spells with judgement)
            if (!addTriggerFlag && (spellInfo.ProcFlags & TAKEN_HIT_PROC_FLAG_MASK) != 0)
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
        }

        if (!procSpellTypeMask)
        {
            for (SpellEffectInfo const& spellEffectInfo : spellInfo.GetEffects())
            {
                if (spellEffectInfo.IsAura())
                {
                    TC_LOG_ERROR("sql.sql", "Spell Id {} has DBC ProcFlags 0x{:X} 0x{:X}, but it's of non-proc aura type, it probably needs an entry in `spell_proc` table to be handled correctly.",
                        spellInfo.Id, uint32(spellInfo.ProcFlags[0]), uint32(spellInfo.ProcFlags[1]));
                    break;
                }
            }

            continue;
        }

        SpellProcEntry procEntry;
        procEntry.SchoolMask      = 0;
        procEntry.ProcFlags = spellInfo.ProcFlags;
        procEntry.SpellFamilyName = 0;
        for (SpellEffectInfo const& spellEffectInfo : spellInfo.GetEffects())
            if (spellEffectInfo.IsEffect() && isTriggerAura[spellEffectInfo.ApplyAuraName])
                procEntry.SpellFamilyMask |= spellEffectInfo.SpellClassMask;

        if (procEntry.SpellFamilyMask)
            procEntry.SpellFamilyName = spellInfo.SpellFamilyName;

        procEntry.SpellTypeMask   = procSpellTypeMask;
        procEntry.SpellPhaseMask  = PROC_SPELL_PHASE_HIT;
        procEntry.HitMask         = PROC_HIT_NONE; // uses default proc @see SpellMgr::CanSpellTriggerProcOnEvent

        if (!(procEntry.ProcFlags & REQ_SPELL_PHASE_PROC_FLAG_MASK) && procEntry.ProcFlags & PROC_FLAG_2_CAST_SUCCESSFUL)
            procEntry.SpellPhaseMask = PROC_SPELL_PHASE_CAST; // set default phase for PROC_FLAG_2_CAST_SUCCESSFUL

        bool triggersSpell = false;
        for (SpellEffectInfo const& spellEffectInfo : spellInfo.GetEffects())
        {
            if (!spellEffectInfo.IsAura())
                continue;

            switch (spellEffectInfo.ApplyAuraName)
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
                // proc auras with another aura reducing hit chance (eg 63767) only proc on missed attack
                case SPELL_AURA_MOD_HIT_CHANCE:
                    if (spellEffectInfo.CalcValue() <= -100)
                        procEntry.HitMask = PROC_HIT_MISS;
                    break;
                case SPELL_AURA_PROC_TRIGGER_SPELL:
                case SPELL_AURA_PROC_TRIGGER_SPELL_WITH_VALUE:
                    triggersSpell = spellEffectInfo.TriggerSpell != 0;
                    break;
                default:
                    continue;
            }
            break;
        }

        procEntry.AttributesMask  = PROC_ATTR_NONE;
        procEntry.DisableEffectsMask = nonProcMask;
        if (spellInfo.ProcFlags & PROC_FLAG_KILL)
            procEntry.AttributesMask |= PROC_ATTR_REQ_EXP_OR_HONOR;
        if (addTriggerFlag)
            procEntry.AttributesMask |= PROC_ATTR_TRIGGERED_CAN_PROC;

        procEntry.ProcsPerMinute  = 0;
        procEntry.Chance          = spellInfo.ProcChance;
        procEntry.Cooldown        = Milliseconds(spellInfo.ProcCooldown);
        procEntry.Charges         = spellInfo.ProcCharges;

        if (spellInfo.HasAttribute(SPELL_ATTR3_CAN_PROC_FROM_PROCS) && !procEntry.SpellFamilyMask
            && procEntry.Chance >= 100
            && spellInfo.ProcBasePPM <= 0.0f
            && procEntry.Cooldown <= 0ms
            && procEntry.Charges <= 0
            && procEntry.ProcFlags & (PROC_FLAG_DEAL_MELEE_ABILITY | PROC_FLAG_DEAL_RANGED_ATTACK | PROC_FLAG_DEAL_RANGED_ABILITY | PROC_FLAG_DEAL_HELPFUL_ABILITY
                | PROC_FLAG_DEAL_HARMFUL_ABILITY | PROC_FLAG_DEAL_HELPFUL_SPELL | PROC_FLAG_DEAL_HARMFUL_SPELL | PROC_FLAG_DEAL_HARMFUL_PERIODIC
                | PROC_FLAG_DEAL_HELPFUL_PERIODIC)
            && triggersSpell)
        {
            TC_LOG_ERROR("sql.sql", "Spell Id {} has SPELL_ATTR3_CAN_PROC_FROM_PROCS attribute and no restriction on what spells can cause it to proc and no cooldown. "
                "This spell can cause infinite proc loops. Proc data for this spell was not generated, data in `spell_proc` table is required for it to function!",
                spellInfo.Id);
            continue;
        }

        mSpellProcMap[{ spellInfo.Id, spellInfo.Difficulty }] = procEntry;
        ++count;
    }

    TC_LOG_INFO("server.loading", ">> Generated spell proc data for {} spells in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
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

        if (!GetSpellInfo(entry, DIFFICULTY_NONE))
        {
            TC_LOG_ERROR("sql.sql", "The spell {} listed in `spell_threat` does not exist.", entry);
            continue;
        }

        SpellThreatEntry ste;
        ste.flatMod  = fields[1].GetInt32();
        ste.pctMod   = fields[2].GetFloat();
        ste.apPctMod = fields[3].GetFloat();

        mSpellThreatMap[entry] = ste;
        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} SpellThreatEntries in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
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

    TC_LOG_INFO("server.loading", ">> Loaded {} SkillLineAbility MultiMap Data in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
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
        SpellEffIndex eff = SpellEffIndex(fields[1].GetUInt8());
        uint32 pet = fields[2].GetUInt32();
        uint32 aura = fields[3].GetUInt32();

        SpellPetAuraMap::iterator itr = mSpellPetAuraMap.find((spell<<8) + eff);
        if (itr != mSpellPetAuraMap.end())
            itr->second.AddAura(pet, aura);
        else
        {
            SpellInfo const* spellInfo = GetSpellInfo(spell, DIFFICULTY_NONE);
            if (!spellInfo)
            {
                TC_LOG_ERROR("sql.sql", "The spell {} listed in `spell_pet_auras` does not exist.", spell);
                continue;
            }
            if (eff >= spellInfo->GetEffects().size())
            {
                TC_LOG_ERROR("spells", "The spell {} listed in `spell_pet_auras` does not have any effect at index {}", spell, uint32(eff));
                continue;
            }

            if (spellInfo->GetEffect(eff).Effect != SPELL_EFFECT_DUMMY &&
               (spellInfo->GetEffect(eff).Effect != SPELL_EFFECT_APPLY_AURA ||
                spellInfo->GetEffect(eff).ApplyAuraName != SPELL_AURA_DUMMY))
            {
                TC_LOG_ERROR("spells", "The spell {} listed in `spell_pet_auras` does not have any dummy aura or dummy effect.", spell);
                continue;
            }

            SpellInfo const* spellInfo2 = GetSpellInfo(aura, DIFFICULTY_NONE);
            if (!spellInfo2)
            {
                TC_LOG_ERROR("sql.sql", "The aura {} listed in `spell_pet_auras` does not exist.", aura);
                continue;
            }

            PetAura pa(pet, aura, spellInfo->GetEffect(eff).TargetA.GetTarget() == TARGET_UNIT_PET, spellInfo->GetEffect(eff).CalcValue());
            mSpellPetAuraMap[(spell<<8) + eff] = pa;
        }

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} spell pet auras in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellEnchantProcData()
{
    uint32 oldMSTime = getMSTime();

    mSpellEnchantProcEventMap.clear();                             // need for reload case

    //                                                       0       1               2        3               4
    QueryResult result = WorldDatabase.Query("SELECT EnchantID, Chance, ProcsPerMinute, HitMask, AttributesMask FROM spell_enchant_proc_data");
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
            TC_LOG_ERROR("sql.sql", "The enchancment {} listed in `spell_enchant_proc_data` does not exist.", enchantId);
            continue;
        }

        SpellEnchantProcEntry spe;

        spe.Chance = fields[1].GetFloat();
        spe.ProcsPerMinute = fields[2].GetFloat();
        spe.HitMask = fields[3].GetUInt32();
        spe.AttributesMask = fields[4].GetUInt32();

        mSpellEnchantProcEventMap[enchantId] = spe;

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} enchant proc data definitions in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
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
        SpellLinkedType type = SpellLinkedType(fields[2].GetUInt8());

        SpellInfo const* spellInfo = GetSpellInfo(abs(trigger), DIFFICULTY_NONE);
        if (!spellInfo)
        {
            TC_LOG_ERROR("sql.sql", "The spell {} listed in `spell_linked_spell` does not exist.", abs(trigger));
            continue;
        }

        if (effect >= 0)
        {
            for (SpellEffectInfo const& spellEffectInfo : spellInfo->GetEffects())
            {
                if (spellEffectInfo.CalcValue() == abs(effect))
                    TC_LOG_ERROR("sql.sql", "The spell {} Effect: {} listed in `spell_linked_spell` has same bp{} like effect (possible hack).", abs(trigger), abs(effect), uint32(spellEffectInfo.EffectIndex));
            }
        }

        spellInfo = GetSpellInfo(abs(effect), DIFFICULTY_NONE);
        if (!spellInfo)
        {
            TC_LOG_ERROR("sql.sql", "The spell {} listed in `spell_linked_spell` does not exist.", abs(effect));
            continue;
        }

        if (type < SPELL_LINK_CAST || type > SPELL_LINK_REMOVE)
        {
            TC_LOG_ERROR("sql.sql", "The spell trigger {}, effect {} listed in `spell_linked_spell` has invalid link type {}, skipped.", trigger, effect, type);
            continue;
        }

        if (trigger < 0)
        {
            if (type != SPELL_LINK_CAST)
                TC_LOG_ERROR("sql.sql", "The spell trigger {} listed in `spell_linked_spell` has invalid link type {}, changed to 0.", trigger, type);

            trigger = -trigger;
            type = SPELL_LINK_REMOVE;
        }

        if (type != SPELL_LINK_AURA)
        {
            if (trigger == effect)
            {
                TC_LOG_ERROR("sql.sql", "The spell trigger {}, effect {} listed in `spell_linked_spell` triggers itself (infinite loop), skipped.", trigger, effect);
                continue;
            }
        }

        mSpellLinkedMap[{ type, trigger }].push_back(effect);

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} linked spells in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
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

            std::vector<SkillLineAbilityEntry const*> const* skillLineAbilities = sDB2Manager.GetSkillLineAbilitiesBySkill(creatureFamily->SkillLine[j]);
            if (!skillLineAbilities)
                continue;

            for (SkillLineAbilityEntry const* skillLine : *skillLineAbilities)
            {
                if (skillLine->AcquireMethod != SKILL_LINE_ABILITY_LEARNED_ON_SKILL_LEARN)
                    continue;

                SpellInfo const* spell = GetSpellInfo(skillLine->Spell, DIFFICULTY_NONE);
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

    TC_LOG_INFO("server.loading", ">> Loaded {} pet levelup and default spells for {} families in {} ms", count, family_count, GetMSTimeDiffToNow(oldMSTime));
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
    if (PetLevelupSpellSet const* levelupSpells = cInfo->family ? sSpellMgr->GetPetLevelupSpellList(cInfo->family) : nullptr)
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
    for (SpellInfo const& spellEntry : mSpellInfoMap)
    {
        if (spellEntry.Difficulty != DIFFICULTY_NONE)
            continue;

        for (SpellEffectInfo const& spellEffectInfo : spellEntry.GetEffects())
        {
            if (spellEffectInfo.IsEffect(SPELL_EFFECT_SUMMON) || spellEffectInfo.IsEffect(SPELL_EFFECT_SUMMON_PET))
            {
                uint32 creature_id = spellEffectInfo.MiscValue;
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

    TC_LOG_INFO("server.loading", ">> Loaded {} summonable creature templates in {} ms", countCreature, GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellAreas()
{
    uint32 oldMSTime = getMSTime();

    mSpellAreaMap.clear();                                  // need for reload case
    mSpellAreaForAreaMap.clear();
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
        spellArea.raceMask.RawValue   = fields[7].GetUInt64();
        spellArea.gender              = Gender(fields[8].GetUInt8());
        spellArea.flags               = fields[9].GetUInt8();

        if (SpellInfo const* spellInfo = GetSpellInfo(spell, DIFFICULTY_NONE))
        {
            if (spellArea.flags & SPELL_AREA_FLAG_AUTOCAST)
                const_cast<SpellInfo*>(spellInfo)->Attributes |= SPELL_ATTR0_NO_AURA_CANCEL;
        }
        else
        {
            TC_LOG_ERROR("sql.sql", "The spell {} listed in `spell_area` does not exist", spell);
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
                if ((spellArea.raceMask & itr->second.raceMask).IsEmpty())
                    continue;
                if (spellArea.gender != itr->second.gender)
                    continue;

                // duplicate by requirements
                ok = false;
                break;
            }

            if (!ok)
            {
                TC_LOG_ERROR("sql.sql", "The spell {} listed in `spell_area` is already listed with similar requirements.", spell);
                continue;
            }
        }

        if (spellArea.areaId && !sAreaTableStore.LookupEntry(spellArea.areaId))
        {
            TC_LOG_ERROR("sql.sql", "The spell {} listed in `spell_area` has a wrong area ({}) requirement.", spell, spellArea.areaId);
            continue;
        }

        if (spellArea.questStart && !sObjectMgr->GetQuestTemplate(spellArea.questStart))
        {
            TC_LOG_ERROR("sql.sql", "The spell {} listed in `spell_area` has a wrong start quest ({}) requirement.", spell, spellArea.questStart);
            continue;
        }

        if (spellArea.questEnd)
        {
            if (!sObjectMgr->GetQuestTemplate(spellArea.questEnd))
            {
                TC_LOG_ERROR("sql.sql", "The spell {} listed in `spell_area` has a wrong ending quest ({}) requirement.", spell, spellArea.questEnd);
                continue;
            }
        }

        if (spellArea.auraSpell)
        {
            SpellInfo const* spellInfo = GetSpellInfo(abs(spellArea.auraSpell), DIFFICULTY_NONE);
            if (!spellInfo)
            {
                TC_LOG_ERROR("sql.sql", "The spell {} listed in `spell_area` has wrong aura spell ({}) requirement", spell, abs(spellArea.auraSpell));
                continue;
            }

            if (uint32(abs(spellArea.auraSpell)) == spellArea.spellId)
            {
                TC_LOG_ERROR("sql.sql", "The spell {} listed in `spell_area` has aura spell ({}) requirement for itself", spell, abs(spellArea.auraSpell));
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
                    TC_LOG_ERROR("sql.sql", "The spell {} listed in `spell_area` has the aura spell ({}) requirement that it autocasts itself from the aura.", spell, spellArea.auraSpell);
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
                    TC_LOG_ERROR("sql.sql", "The spell {} listed in `spell_area` has the aura spell ({}) requirement that the spell itself autocasts from the aura.", spell, spellArea.auraSpell);
                    continue;
                }
            }
        }

        if (!spellArea.raceMask.IsEmpty() && (spellArea.raceMask & RACEMASK_ALL_PLAYABLE).IsEmpty())
        {
            TC_LOG_ERROR("sql.sql", "The spell {} listed in `spell_area` has wrong race mask ({}) requirement.", spell, spellArea.raceMask.RawValue);
            continue;
        }

        if (spellArea.gender != GENDER_NONE && spellArea.gender != GENDER_FEMALE && spellArea.gender != GENDER_MALE)
        {
            TC_LOG_ERROR("sql.sql", "The spell {} listed in `spell_area` has wrong gender ({}) requirement.", spell, spellArea.gender);
            continue;
        }

        SpellArea const* sa = &mSpellAreaMap.insert(SpellAreaMap::value_type(spell, spellArea))->second;

        // for search by current zone/subzone at zone/subzone change
        if (spellArea.areaId)
            mSpellAreaForAreaMap.insert(SpellAreaForAreaMap::value_type(spellArea.areaId, sa));

        // for search at quest update checks
        if (spellArea.questStart || spellArea.questEnd)
        {
            if (spellArea.questStart == spellArea.questEnd)
                mSpellAreaForQuestMap.insert(SpellAreaForQuestMap::value_type(spellArea.questStart, sa));
            else
            {
                if (spellArea.questStart)
                    mSpellAreaForQuestMap.insert(SpellAreaForQuestMap::value_type(spellArea.questStart, sa));
                if (spellArea.questEnd)
                    mSpellAreaForQuestMap.insert(SpellAreaForQuestMap::value_type(spellArea.questEnd, sa));
            }
        }

        // for search at quest start/reward
        if (spellArea.questEnd)
            mSpellAreaForQuestEndMap.insert(SpellAreaForQuestMap::value_type(spellArea.questEnd, sa));

        // for search at aura apply
        if (spellArea.auraSpell)
            mSpellAreaForAuraMap.insert(SpellAreaForAuraMap::value_type(abs(spellArea.auraSpell), sa));

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} spell area requirements in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

typedef std::vector<SpellEffectEntry const*> SpellEffectVector;

void SpellMgr::LoadSpellInfoStore()
{
    uint32 oldMSTime = getMSTime();

    UnloadSpellInfoStore();

    std::unordered_map<std::pair<uint32, Difficulty>, SpellInfoLoadHelper> loadData;

    std::unordered_map<int32, BattlePetSpeciesEntry const*> battlePetSpeciesByCreature;
    for (BattlePetSpeciesEntry const* battlePetSpecies : sBattlePetSpeciesStore)
        if (battlePetSpecies->CreatureID)
            battlePetSpeciesByCreature[battlePetSpecies->CreatureID] = battlePetSpecies;

    for (SpellEffectEntry const* effect : sSpellEffectStore)
    {
        ASSERT(effect->EffectIndex < MAX_SPELL_EFFECTS, "MAX_SPELL_EFFECTS must be at least %d", effect->EffectIndex + 1);
        ASSERT(effect->Effect < TOTAL_SPELL_EFFECTS, "TOTAL_SPELL_EFFECTS must be at least %u", effect->Effect + 1);
        ASSERT(effect->EffectAura < int32(TOTAL_AURAS), "TOTAL_AURAS must be at least %d", effect->EffectAura + 1);
        ASSERT(effect->ImplicitTarget[0] < TOTAL_SPELL_TARGETS, "TOTAL_SPELL_TARGETS must be at least %u", effect->ImplicitTarget[0] + 1);
        ASSERT(effect->ImplicitTarget[1] < TOTAL_SPELL_TARGETS, "TOTAL_SPELL_TARGETS must be at least %u", effect->ImplicitTarget[1] + 1);

        loadData[{ effect->SpellID, Difficulty(effect->DifficultyID) }].Effects[effect->EffectIndex] = effect;

        if (effect->Effect == SPELL_EFFECT_SUMMON)
            if (SummonPropertiesEntry const* summonProperties = sSummonPropertiesStore.LookupEntry(effect->EffectMiscValue[1]))
                if (summonProperties->Slot == SUMMON_SLOT_MINIPET && summonProperties->GetFlags().HasFlag(SummonPropertiesFlags::SummonFromBattlePetJournal))
                    if (BattlePetSpeciesEntry const* battlePetSpecies = Trinity::Containers::MapGetValuePtr(battlePetSpeciesByCreature, effect->EffectMiscValue[0]))
                        BattlePets::BattlePetMgr::AddBattlePetSpeciesBySpell(effect->SpellID, battlePetSpecies);

        if (effect->Effect == SPELL_EFFECT_LANGUAGE)
            sLanguageMgr->LoadSpellEffectLanguage(effect);

        switch (effect->EffectAura)
        {
            case SPELL_AURA_ADD_FLAT_MODIFIER:
            case SPELL_AURA_ADD_PCT_MODIFIER:
            case SPELL_AURA_ADD_PCT_MODIFIER_BY_SPELL_LABEL:
            case SPELL_AURA_ADD_FLAT_MODIFIER_BY_SPELL_LABEL:
                if (effect->EffectMiscValue[0] >= MAX_SPELLMOD)
                {
                    TC_LOG_ERROR("server.loading", "Invalid spell modifier type {} found on spell {} effect index {}, consider increasing MAX_SPELLMOD",
                        effect->EffectMiscValue[0], effect->SpellID, effect->EffectIndex);
                }
                break;
            default:
                break;
        }
    }

    for (SpellAuraOptionsEntry const* auraOptions : sSpellAuraOptionsStore)
        loadData[{ auraOptions->SpellID, Difficulty(auraOptions->DifficultyID) }].AuraOptions = auraOptions;

    for (SpellAuraRestrictionsEntry const* auraRestrictions : sSpellAuraRestrictionsStore)
        loadData[{ auraRestrictions->SpellID, Difficulty(auraRestrictions->DifficultyID) }].AuraRestrictions = auraRestrictions;

    for (SpellCastingRequirementsEntry const* castingRequirements : sSpellCastingRequirementsStore)
        loadData[{ castingRequirements->SpellID, DIFFICULTY_NONE }].CastingRequirements = castingRequirements;

    for (SpellCategoriesEntry const* categories : sSpellCategoriesStore)
        loadData[{ categories->SpellID, Difficulty(categories->DifficultyID) }].Categories = categories;

    for (SpellClassOptionsEntry const* classOptions : sSpellClassOptionsStore)
        loadData[{ classOptions->SpellID, DIFFICULTY_NONE }].ClassOptions = classOptions;

    for (SpellCooldownsEntry const* cooldowns : sSpellCooldownsStore)
        loadData[{ cooldowns->SpellID, Difficulty(cooldowns->DifficultyID) }].Cooldowns = cooldowns;

    for (SpellEmpowerStageEntry const* empowerStage : sSpellEmpowerStageStore)
    {
        if (SpellEmpowerEntry const* empower = sSpellEmpowerStore.LookupEntry(empowerStage->SpellEmpowerID))
        {
            std::vector<SpellEmpowerStageEntry const*>& empowerStages = loadData[{empower->SpellID, DIFFICULTY_NONE}].EmpowerStages;

            auto where = std::ranges::lower_bound(empowerStages, empowerStage->Stage, std::ranges::less(), &SpellEmpowerStageEntry::Stage);

            empowerStages.insert(where, empowerStage);
        }
    }

    for (SpellEquippedItemsEntry const* equippedItems : sSpellEquippedItemsStore)
        loadData[{ equippedItems->SpellID, DIFFICULTY_NONE }].EquippedItems = equippedItems;

    for (SpellInterruptsEntry const* interrupts : sSpellInterruptsStore)
        loadData[{ interrupts->SpellID, Difficulty(interrupts->DifficultyID) }].Interrupts = interrupts;

    for (SpellLabelEntry const* label : sSpellLabelStore)
        loadData[{ label->SpellID, DIFFICULTY_NONE }].Labels.push_back(label);

    for (SpellLevelsEntry const* levels : sSpellLevelsStore)
        loadData[{ levels->SpellID, Difficulty(levels->DifficultyID) }].Levels = levels;

    for (SpellMiscEntry const* misc : sSpellMiscStore)
        loadData[{ misc->SpellID, Difficulty(misc->DifficultyID) }].Misc = misc;

    for (SpellPowerEntry const* power : sSpellPowerStore)
    {
        Difficulty difficulty = DIFFICULTY_NONE;
        uint8 index = power->OrderIndex;
        if (SpellPowerDifficultyEntry const* powerDifficulty = sSpellPowerDifficultyStore.LookupEntry(power->ID))
        {
            difficulty = Difficulty(powerDifficulty->DifficultyID);
            index = powerDifficulty->OrderIndex;
        }

        loadData[{ power->SpellID, difficulty }].Powers[index] = power;
    }

    for (SpellReagentsEntry const* reagents : sSpellReagentsStore)
        loadData[{ reagents->SpellID, DIFFICULTY_NONE }].Reagents = reagents;

    for (SpellReagentsCurrencyEntry const* reagentsCurrency : sSpellReagentsCurrencyStore)
        loadData[{ reagentsCurrency->SpellID, DIFFICULTY_NONE }].ReagentsCurrency.push_back(reagentsCurrency);

    for (SpellScalingEntry const* scaling : sSpellScalingStore)
        loadData[{ scaling->SpellID, DIFFICULTY_NONE }].Scaling = scaling;

    for (SpellShapeshiftEntry const* shapeshift : sSpellShapeshiftStore)
        loadData[{ shapeshift->SpellID, DIFFICULTY_NONE }].Shapeshift = shapeshift;

    for (SpellTargetRestrictionsEntry const* targetRestrictions : sSpellTargetRestrictionsStore)
        loadData[{ targetRestrictions->SpellID, Difficulty(targetRestrictions->DifficultyID) }].TargetRestrictions = targetRestrictions;

    for (SpellTotemsEntry const* totems : sSpellTotemsStore)
        loadData[{ totems->SpellID, DIFFICULTY_NONE }].Totems = totems;

    for (SpellXSpellVisualEntry const* visual : sSpellXSpellVisualStore)
    {
        SpellVisualVector& visuals = loadData[{ visual->SpellID, Difficulty(visual->DifficultyID) }].Visuals;

        auto where = std::ranges::lower_bound(visuals, visual->CasterPlayerConditionID, std::ranges::greater(), &SpellXSpellVisualEntry::CasterPlayerConditionID);

        // sorted with unconditional visuals being last
        visuals.insert(where, visual);
    }

    for (auto& [key, data] : loadData)
    {
        SpellNameEntry const* spellNameEntry = sSpellNameStore.LookupEntry(key.first);
        if (!spellNameEntry)
            continue;

        // fill blanks
        if (DifficultyEntry const* difficultyEntry = sDifficultyStore.LookupEntry(key.second))
        {
            do
            {
                if (SpellInfoLoadHelper const* fallbackData = Trinity::Containers::MapGetValuePtr(loadData, { key.first, Difficulty(difficultyEntry->FallbackDifficultyID) }))
                {
                    if (!data.AuraOptions)
                        data.AuraOptions = fallbackData->AuraOptions;

                    if (!data.AuraRestrictions)
                        data.AuraRestrictions = fallbackData->AuraRestrictions;

                    if (!data.CastingRequirements)
                        data.CastingRequirements = fallbackData->CastingRequirements;

                    if (!data.Categories)
                        data.Categories = fallbackData->Categories;

                    if (!data.ClassOptions)
                        data.ClassOptions = fallbackData->ClassOptions;

                    if (!data.Cooldowns)
                        data.Cooldowns = fallbackData->Cooldowns;

                    for (std::size_t i = 0; i < data.Effects.size(); ++i)
                        if (!data.Effects[i])
                            data.Effects[i] = fallbackData->Effects[i];

                    if (data.EmpowerStages.empty())
                        data.EmpowerStages = fallbackData->EmpowerStages;

                    if (!data.EquippedItems)
                        data.EquippedItems = fallbackData->EquippedItems;

                    if (!data.Interrupts)
                        data.Interrupts = fallbackData->Interrupts;

                    if (data.Labels.empty())
                        data.Labels = fallbackData->Labels;

                    if (!data.Levels)
                        data.Levels = fallbackData->Levels;

                    if (!data.Misc)
                        data.Misc = fallbackData->Misc;

                    for (std::size_t i = 0; i < fallbackData->Powers.size(); ++i)
                        if (!data.Powers[i])
                            data.Powers[i] = fallbackData->Powers[i];

                    if (!data.Reagents)
                        data.Reagents = fallbackData->Reagents;

                    if (data.ReagentsCurrency.empty())
                        data.ReagentsCurrency = fallbackData->ReagentsCurrency;

                    if (!data.Scaling)
                        data.Scaling = fallbackData->Scaling;

                    if (!data.Shapeshift)
                        data.Shapeshift = fallbackData->Shapeshift;

                    if (!data.TargetRestrictions)
                        data.TargetRestrictions = fallbackData->TargetRestrictions;

                    if (!data.Totems)
                        data.Totems = fallbackData->Totems;

                    // visuals fall back only to first difficulty that defines any visual
                    // they do not stack all difficulties in fallback chain
                    if (data.Visuals.empty())
                        data.Visuals = fallbackData->Visuals;
                }

                difficultyEntry = sDifficultyStore.LookupEntry(difficultyEntry->FallbackDifficultyID);
            } while (difficultyEntry);
        }

        mSpellInfoMap.emplace(spellNameEntry, key.second, data);
    }

    TC_LOG_INFO("server.loading", ">> Loaded SpellInfo store in {} ms", GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::UnloadSpellInfoStore()
{
    mSpellInfoMap.clear();
    mServersideSpellNames.clear();
}

void SpellMgr::UnloadSpellInfoImplicitTargetConditionLists()
{
    for (SpellInfo const& spellInfo : mSpellInfoMap)
        const_cast<SpellInfo&>(spellInfo)._UnloadImplicitTargetConditionLists();
}

void SpellMgr::LoadSpellInfoServerside()
{
    uint32 oldMSTime = getMSTime();

    std::unordered_map<std::pair<uint32, Difficulty>, std::vector<SpellEffectEntry>> spellEffects;

    //                                                      0        1            2             3       4           5                6
    QueryResult effectsResult = WorldDatabase.Query("SELECT SpellID, EffectIndex, DifficultyID, Effect, EffectAura, EffectAmplitude, EffectAttributes, "
    //   7                 8                       9                     10                  11              12              13
        "EffectAuraPeriod, EffectBonusCoefficient, EffectChainAmplitude, EffectChainTargets, EffectItemType, EffectMechanic, EffectPointsPerResource, "
    //   14               15                        16                  17                      18             19           20
        "EffectPosFacing, EffectRealPointsPerLevel, EffectTriggerSpell, BonusCoefficientFromAP, PvpMultiplier, Coefficient, Variance, "
    //   21                   22                              23                24                25                26
        "ResourceCoefficient, GroupSizeBasePointsCoefficient, EffectBasePoints, EffectMiscValue1, EffectMiscValue2, EffectRadiusIndex1, "
    //   27                  28                     29                     30                     31                     32
        "EffectRadiusIndex2, EffectSpellClassMask1, EffectSpellClassMask2, EffectSpellClassMask3, EffectSpellClassMask4, ImplicitTarget1, "
    //   33
        "ImplicitTarget2 FROM serverside_spell_effect");
    if (effectsResult)
    {
        do
        {
            Field* fields = effectsResult->Fetch();
            uint32 spellId = fields[0].GetUInt32();
            Difficulty difficulty = Difficulty(fields[2].GetUInt32());
            SpellEffectEntry effect{ };
            effect.EffectIndex = fields[1].GetInt32();
            effect.Effect = fields[3].GetInt32();
            effect.EffectAura = fields[4].GetInt16();
            effect.EffectAmplitude = fields[5].GetFloat();
            effect.EffectAttributes = fields[6].GetInt32();
            effect.EffectAuraPeriod = fields[7].GetInt32();
            effect.EffectBonusCoefficient = fields[8].GetFloat();
            effect.EffectChainAmplitude = fields[9].GetFloat();
            effect.EffectChainTargets = fields[10].GetInt32();
            effect.EffectItemType = fields[11].GetInt32();
            effect.EffectMechanic = Mechanics(fields[12].GetInt32());
            effect.EffectPointsPerResource = fields[13].GetFloat();
            effect.EffectPosFacing = fields[14].GetFloat();
            effect.EffectRealPointsPerLevel = fields[15].GetFloat();
            effect.EffectTriggerSpell = fields[16].GetInt32();
            effect.BonusCoefficientFromAP = fields[17].GetFloat();
            effect.PvpMultiplier = fields[18].GetFloat();
            effect.Coefficient = fields[19].GetFloat();
            effect.Variance = fields[20].GetFloat();
            effect.ResourceCoefficient = fields[21].GetFloat();
            effect.GroupSizeBasePointsCoefficient = fields[22].GetFloat();
            effect.EffectBasePoints = fields[23].GetFloat();
            effect.EffectMiscValue[0] = fields[24].GetInt32();
            effect.EffectMiscValue[1] = fields[25].GetInt32();
            effect.EffectRadiusIndex[0] = fields[26].GetUInt32();
            effect.EffectRadiusIndex[1] = fields[27].GetUInt32();
            effect.EffectSpellClassMask = flag128(fields[28].GetInt32(), fields[29].GetInt32(), fields[30].GetInt32(), fields[31].GetInt32());
            effect.ImplicitTarget[0] = fields[32].GetInt16();
            effect.ImplicitTarget[1] = fields[33].GetInt16();

            auto existingSpellBounds = _GetSpellInfo(spellId);
            if (existingSpellBounds.begin() != existingSpellBounds.end())
            {
                TC_LOG_ERROR("sql.sql", "Serverside spell {} difficulty {} effext index {} references a regular spell loaded from file. Adding serverside effects to existing spells is not allowed.",
                    spellId, uint32(difficulty), effect.EffectIndex);
                continue;
            }

            if (difficulty != DIFFICULTY_NONE && !sDifficultyStore.HasRecord(difficulty))
            {
                TC_LOG_ERROR("sql.sql", "Serverside spell {} effect index {} references non-existing difficulty {}, skipped",
                    spellId, effect.EffectIndex, uint32(difficulty));
                continue;
            }

            if (effect.EffectIndex >= MAX_SPELL_EFFECTS)
            {
                TC_LOG_ERROR("sql.sql", "Serverside spell {} difficulty {} has more than {} effects, effect at index {} skipped",
                    spellId, uint32(difficulty), MAX_SPELL_EFFECTS, effect.EffectIndex);
                continue;
            }

            if (effect.Effect >= TOTAL_SPELL_EFFECTS)
            {
                TC_LOG_ERROR("sql.sql", "Serverside spell {} difficulty {} has invalid effect type {} at index {}, skipped",
                    spellId, uint32(difficulty), effect.Effect, effect.EffectIndex);
                continue;
            }

            if (effect.EffectAura >= int32(TOTAL_AURAS))
            {
                TC_LOG_ERROR("sql.sql", "Serverside spell {} difficulty {} has invalid aura type {} at index {}, skipped",
                    spellId, uint32(difficulty), effect.EffectAura, effect.EffectIndex);
                continue;
            }

            if (effect.ImplicitTarget[0] >= TOTAL_SPELL_TARGETS)
            {
                TC_LOG_ERROR("sql.sql", "Serverside spell {} difficulty {} has invalid targetA type {} at index {}, skipped",
                    spellId, uint32(difficulty), effect.ImplicitTarget[0], effect.EffectIndex);
                continue;
            }

            if (effect.ImplicitTarget[1] >= TOTAL_SPELL_TARGETS)
            {
                TC_LOG_ERROR("sql.sql", "Serverside spell {} difficulty {} has invalid targetB type {} at index {}, skipped",
                    spellId, uint32(difficulty), effect.ImplicitTarget[1], effect.EffectIndex);
                continue;
            }

            if (effect.EffectRadiusIndex[0] && !sSpellRadiusStore.HasRecord(effect.EffectRadiusIndex[0]))
            {
                TC_LOG_ERROR("sql.sql", "Serverside spell {} difficulty {} has invalid radius id {} at index {}, set to 0",
                    spellId, uint32(difficulty), effect.EffectRadiusIndex[0], effect.EffectIndex);
            }

            if (effect.EffectRadiusIndex[1] && !sSpellRadiusStore.HasRecord(effect.EffectRadiusIndex[1]))
            {
                TC_LOG_ERROR("sql.sql", "Serverside spell {} difficulty {} has invalid max radius id {} at index {}, set to 0",
                    spellId, uint32(difficulty), effect.EffectRadiusIndex[1], effect.EffectIndex);
            }

            spellEffects[{ spellId, difficulty }].push_back(std::move(effect));

        } while (effectsResult->NextRow());
    }

    //                                                     0   1             2           3       4         5           6             7              8
    QueryResult spellsResult = WorldDatabase.Query("SELECT Id, DifficultyID, CategoryId, Dispel, Mechanic, Attributes, AttributesEx, AttributesEx2, AttributesEx3, "
    //   9              10             11             12             13             14             15              16              17              18
        "AttributesEx4, AttributesEx5, AttributesEx6, AttributesEx7, AttributesEx8, AttributesEx9, AttributesEx10, AttributesEx11, AttributesEx12, AttributesEx13, "
    //   19              20       21          22       23                  24                  25                 26               27
        "AttributesEx14, Stances, StancesNot, Targets, TargetCreatureType, RequiresSpellFocus, FacingCasterFlags, CasterAuraState, TargetAuraState, "
    //   28                      29                      30               31               32                      33
        "ExcludeCasterAuraState, ExcludeTargetAuraState, CasterAuraSpell, TargetAuraSpell, ExcludeCasterAuraSpell, ExcludeTargetAuraSpell, "
    //   34              35              36                     37                     38
        "CasterAuraType, TargetAuraType, ExcludeCasterAuraType, ExcludeTargetAuraType, CastingTimeIndex, "
    //   39            40                    41                     42                 43              44                   45
        "RecoveryTime, CategoryRecoveryTime, StartRecoveryCategory, StartRecoveryTime, InterruptFlags, AuraInterruptFlags1, AuraInterruptFlags2, "
    //   46                      47                      48         49          50          51           52            53           54        55         56
        "ChannelInterruptFlags1, ChannelInterruptFlags2, ProcFlags, ProcFlags2, ProcChance, ProcCharges, ProcCooldown, ProcBasePPM, MaxLevel, BaseLevel, SpellLevel, "
    //   57             58          59     60           61           62                 63                        64                             65
        "DurationIndex, RangeIndex, Speed, LaunchDelay, StackAmount, EquippedItemClass, EquippedItemSubClassMask, EquippedItemInventoryTypeMask, ContentTuningId, "
    //   66         67         68         69              70                  71               72                 73                 74                 75
        "SpellName, ConeAngle, ConeWidth, MaxTargetLevel, MaxAffectedTargets, SpellFamilyName, SpellFamilyFlags1, SpellFamilyFlags2, SpellFamilyFlags3, SpellFamilyFlags4, "
    //   76        77              78           79          80
        "DmgClass, PreventionType, AreaGroupId, SchoolMask, ChargeCategoryId FROM serverside_spell");
    if (spellsResult)
    {
        mServersideSpellNames.reserve(spellsResult->GetRowCount());

        do
        {
            Field* fields = spellsResult->Fetch();
            uint32 spellId = fields[0].GetUInt32();
            Difficulty difficulty = Difficulty(fields[1].GetUInt32());
            if (sSpellNameStore.HasRecord(spellId))
            {
                TC_LOG_ERROR("sql.sql", "Serverside spell {} difficulty {} is already loaded from file. Overriding existing spells is not allowed.",
                    spellId, uint32(difficulty));
                continue;
            }

            mServersideSpellNames.emplace_back(spellId, fields[66].GetString());

            SpellInfo& spellInfo = const_cast<SpellInfo&>(*mSpellInfoMap.emplace(&mServersideSpellNames.back().Name, difficulty, spellEffects[{ spellId, difficulty }]).first);
            spellInfo.CategoryId = fields[2].GetUInt32();
            spellInfo.Dispel = fields[3].GetUInt32();
            spellInfo.Mechanic = fields[4].GetUInt32();
            spellInfo.Attributes = fields[5].GetUInt32();
            spellInfo.AttributesEx = fields[6].GetUInt32();
            spellInfo.AttributesEx2 = fields[7].GetUInt32();
            spellInfo.AttributesEx3 = fields[8].GetUInt32();
            spellInfo.AttributesEx4 = fields[9].GetUInt32();
            spellInfo.AttributesEx5 = fields[10].GetUInt32();
            spellInfo.AttributesEx6 = fields[11].GetUInt32();
            spellInfo.AttributesEx7 = fields[12].GetUInt32();
            spellInfo.AttributesEx8 = fields[13].GetUInt32();
            spellInfo.AttributesEx9 = fields[14].GetUInt32();
            spellInfo.AttributesEx10 = fields[15].GetUInt32();
            spellInfo.AttributesEx11 = fields[16].GetUInt32();
            spellInfo.AttributesEx12 = fields[17].GetUInt32();
            spellInfo.AttributesEx13 = fields[18].GetUInt32();
            spellInfo.AttributesEx14 = fields[19].GetUInt32();
            spellInfo.Stances = fields[20].GetUInt64();
            spellInfo.StancesNot = fields[21].GetUInt64();
            spellInfo.Targets = fields[22].GetUInt32();
            spellInfo.TargetCreatureType = fields[23].GetUInt32();
            spellInfo.RequiresSpellFocus = fields[24].GetUInt32();
            spellInfo.FacingCasterFlags = fields[25].GetUInt32();
            spellInfo.CasterAuraState = fields[26].GetUInt32();
            spellInfo.TargetAuraState = fields[27].GetUInt32();
            spellInfo.ExcludeCasterAuraState = fields[28].GetUInt32();
            spellInfo.ExcludeTargetAuraState = fields[29].GetUInt32();
            spellInfo.CasterAuraSpell = fields[30].GetUInt32();
            spellInfo.TargetAuraSpell = fields[31].GetUInt32();
            spellInfo.ExcludeCasterAuraSpell = fields[32].GetUInt32();
            spellInfo.ExcludeTargetAuraSpell = fields[33].GetUInt32();
            spellInfo.CasterAuraType = AuraType(fields[34].GetInt32());
            spellInfo.TargetAuraType = AuraType(fields[35].GetInt32());
            spellInfo.ExcludeCasterAuraType = AuraType(fields[36].GetInt32());
            spellInfo.ExcludeTargetAuraType = AuraType(fields[37].GetInt32());
            spellInfo.CastTimeEntry = sSpellCastTimesStore.LookupEntry(fields[38].GetUInt32());
            spellInfo.RecoveryTime = fields[39].GetUInt32();
            spellInfo.CategoryRecoveryTime = fields[40].GetUInt32();
            spellInfo.StartRecoveryCategory = fields[41].GetUInt32();
            spellInfo.StartRecoveryTime = fields[42].GetUInt32();
            spellInfo.InterruptFlags = SpellInterruptFlags(fields[43].GetUInt32());
            spellInfo.AuraInterruptFlags = SpellAuraInterruptFlags(fields[44].GetUInt32());
            spellInfo.AuraInterruptFlags2 = SpellAuraInterruptFlags2(fields[45].GetUInt32());
            spellInfo.ChannelInterruptFlags = SpellAuraInterruptFlags(fields[46].GetUInt32());
            spellInfo.ChannelInterruptFlags2 = SpellAuraInterruptFlags2(fields[47].GetUInt32());
            spellInfo.ProcFlags[0] = fields[48].GetUInt32();
            spellInfo.ProcFlags[1] = fields[49].GetUInt32();
            spellInfo.ProcChance = fields[50].GetUInt32();
            spellInfo.ProcCharges = fields[51].GetUInt32();
            spellInfo.ProcCooldown = fields[52].GetUInt32();
            spellInfo.ProcBasePPM = fields[53].GetFloat();
            spellInfo.MaxLevel = fields[54].GetUInt32();
            spellInfo.BaseLevel = fields[55].GetUInt32();
            spellInfo.SpellLevel = fields[56].GetUInt32();
            spellInfo.DurationEntry = sSpellDurationStore.LookupEntry(fields[57].GetUInt32());
            spellInfo.RangeEntry = sSpellRangeStore.LookupEntry(fields[58].GetUInt32());
            spellInfo.Speed = fields[59].GetFloat();
            spellInfo.LaunchDelay = fields[60].GetFloat();
            spellInfo.StackAmount = fields[61].GetUInt32();
            spellInfo.EquippedItemClass = fields[62].GetInt32();
            spellInfo.EquippedItemSubClassMask = fields[63].GetInt32();
            spellInfo.EquippedItemInventoryTypeMask = fields[64].GetInt32();
            spellInfo.ContentTuningId = fields[65].GetUInt32();
            spellInfo.ConeAngle = fields[67].GetFloat();
            spellInfo.Width = fields[68].GetFloat();
            spellInfo.MaxTargetLevel = fields[69].GetUInt32();
            spellInfo.MaxAffectedTargets = fields[70].GetUInt32();
            spellInfo.SpellFamilyName = fields[71].GetUInt32();
            spellInfo.SpellFamilyFlags = flag128(fields[72].GetUInt32(), fields[73].GetUInt32(), fields[74].GetUInt32(), fields[75].GetUInt32());
            spellInfo.DmgClass = fields[76].GetUInt32();
            spellInfo.PreventionType = fields[77].GetUInt32();
            spellInfo.RequiredAreasID = fields[78].GetInt32();
            spellInfo.SchoolMask = fields[79].GetUInt32();
            spellInfo.ChargeCategoryId = fields[80].GetUInt32();

        } while (spellsResult->NextRow());
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} serverside spells {} ms", mServersideSpellNames.size(), GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellInfoCustomAttributes()
{
    uint32 oldMSTime = getMSTime();
    uint32 oldMSTime2 = oldMSTime;

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

            auto spells = _GetSpellInfo(spellId);
            if (spells.begin() == spells.end())
            {
                TC_LOG_ERROR("sql.sql", "Table `spell_custom_attr` has wrong spell (entry: {}), ignored.", spellId);
                continue;
            }

            for (SpellInfo const& spellInfo : spells)
            {
                if (attributes & SPELL_ATTR0_CU_SHARE_DAMAGE)
                {
                    if (!spellInfo.HasEffect(SPELL_EFFECT_SCHOOL_DAMAGE))
                    {
                        TC_LOG_ERROR("sql.sql", "Spell {} listed in table `spell_custom_attr` with SPELL_ATTR0_CU_SHARE_DAMAGE has no SPELL_EFFECT_SCHOOL_DAMAGE, ignored.", spellId);
                        continue;
                    }
                }

                const_cast<SpellInfo&>(spellInfo).AttributesCu |= attributes;
            }
            ++count;
        } while (result->NextRow());

        TC_LOG_INFO("server.loading", ">> Loaded {} spell custom attributes from DB in {} ms", count, GetMSTimeDiffToNow(oldMSTime2));
    }

    std::set<uint32> talentSpells;
    for (uint32 i = 0; i < sTalentStore.GetNumRows(); ++i)
        if (TalentEntry const* talentInfo = sTalentStore.LookupEntry(i))
            talentSpells.insert(talentInfo->SpellID);

    for (SpellInfo const& spellInfo : mSpellInfoMap)
    {
        SpellInfo* spellInfoMutable = const_cast<SpellInfo*>(&spellInfo);
        for (SpellEffectInfo const& spellEffectInfo : spellInfoMutable->GetEffects())
        {
            // all bleed effects and spells ignore armor
            if (spellInfo.GetEffectMechanicMask(spellEffectInfo.EffectIndex) & (UI64LIT(1) << MECHANIC_BLEED))
                spellInfoMutable->AttributesCu |= SPELL_ATTR0_CU_IGNORE_ARMOR;

            switch (spellEffectInfo.ApplyAuraName)
            {
                case SPELL_AURA_MOD_POSSESS:
                case SPELL_AURA_MOD_CONFUSE:
                case SPELL_AURA_MOD_CHARM:
                case SPELL_AURA_AOE_CHARM:
                case SPELL_AURA_MOD_FEAR:
                case SPELL_AURA_MOD_STUN:
                    spellInfoMutable->AttributesCu |= SPELL_ATTR0_CU_AURA_CC;
                    break;
                default:
                    break;
            }

            switch (spellEffectInfo.ApplyAuraName)
            {
                case SPELL_AURA_OPEN_STABLE:    // No point in saving this, since the stable dialog can't be open on aura load anyway.
                // Auras that require both caster & target to be in world cannot be saved
                case SPELL_AURA_CONTROL_VEHICLE:
                case SPELL_AURA_BIND_SIGHT:
                case SPELL_AURA_MOD_POSSESS:
                case SPELL_AURA_MOD_POSSESS_PET:
                case SPELL_AURA_MOD_CHARM:
                case SPELL_AURA_AOE_CHARM:
                // Controlled by Battleground
                case SPELL_AURA_BATTLEGROUND_PLAYER_POSITION:
                case SPELL_AURA_BATTLEGROUND_PLAYER_POSITION_FACTIONAL:
                    spellInfoMutable->AttributesCu |= SPELL_ATTR0_CU_AURA_CANNOT_BE_SAVED;
                    break;
                default:
                    break;
            }

            switch (spellEffectInfo.Effect)
            {
                case SPELL_EFFECT_SCHOOL_DAMAGE:
                case SPELL_EFFECT_HEALTH_LEECH:
                case SPELL_EFFECT_HEAL:
                case SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL:
                case SPELL_EFFECT_WEAPON_PERCENT_DAMAGE:
                case SPELL_EFFECT_WEAPON_DAMAGE:
                case SPELL_EFFECT_POWER_BURN:
                case SPELL_EFFECT_HEAL_MECHANICAL:
                case SPELL_EFFECT_NORMALIZED_WEAPON_DMG:
                case SPELL_EFFECT_HEAL_PCT:
                case SPELL_EFFECT_DAMAGE_FROM_MAX_HEALTH_PCT:
                    spellInfoMutable->AttributesCu |= SPELL_ATTR0_CU_CAN_CRIT;
                    break;
                default:
                    break;
            }

            switch (spellEffectInfo.Effect)
            {
                case SPELL_EFFECT_SCHOOL_DAMAGE:
                case SPELL_EFFECT_WEAPON_DAMAGE:
                case SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL:
                case SPELL_EFFECT_NORMALIZED_WEAPON_DMG:
                case SPELL_EFFECT_WEAPON_PERCENT_DAMAGE:
                case SPELL_EFFECT_HEAL:
                    spellInfoMutable->AttributesCu |= SPELL_ATTR0_CU_DIRECT_DAMAGE;
                    break;
                case SPELL_EFFECT_POWER_DRAIN:
                case SPELL_EFFECT_POWER_BURN:
                case SPELL_EFFECT_HEAL_MAX_HEALTH:
                case SPELL_EFFECT_HEALTH_LEECH:
                case SPELL_EFFECT_HEAL_PCT:
                case SPELL_EFFECT_ENERGIZE_PCT:
                case SPELL_EFFECT_ENERGIZE:
                case SPELL_EFFECT_HEAL_MECHANICAL:
                    spellInfoMutable->AttributesCu |= SPELL_ATTR0_CU_NO_INITIAL_THREAT;
                    break;
                case SPELL_EFFECT_CHARGE:
                case SPELL_EFFECT_CHARGE_DEST:
                case SPELL_EFFECT_JUMP:
                case SPELL_EFFECT_JUMP_DEST:
                case SPELL_EFFECT_LEAP_BACK:
                    spellInfoMutable->AttributesCu |= SPELL_ATTR0_CU_CHARGE;
                    break;
                case SPELL_EFFECT_PICKPOCKET:
                    spellInfoMutable->AttributesCu |= SPELL_ATTR0_CU_PICKPOCKET;
                    break;
                case SPELL_EFFECT_ENCHANT_ITEM:
                case SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY:
                case SPELL_EFFECT_ENCHANT_ITEM_PRISMATIC:
                case SPELL_EFFECT_ENCHANT_HELD_ITEM:
                {
                    // only enchanting profession enchantments procs can stack
                    if (IsPartOfSkillLine(SKILL_ENCHANTING, spellInfo.Id))
                    {
                        uint32 enchantId = spellEffectInfo.MiscValue;
                        SpellItemEnchantmentEntry const* enchant = sSpellItemEnchantmentStore.LookupEntry(enchantId);
                        if (!enchant)
                            break;

                        for (uint8 s = 0; s < MAX_ITEM_ENCHANTMENT_EFFECTS; ++s)
                        {
                            if (enchant->Effect[s] != ITEM_ENCHANTMENT_TYPE_COMBAT_SPELL)
                                continue;

                            for (SpellInfo const& procInfo : _GetSpellInfo(enchant->EffectArg[s]))
                            {
                                // if proced directly from enchantment, not via proc aura
                                // NOTE: Enchant Weapon - Blade Ward also has proc aura spell and is proced directly
                                // however its not expected to stack so this check is good
                                if (procInfo.HasAura(SPELL_AURA_PROC_TRIGGER_SPELL))
                                    continue;

                                const_cast<SpellInfo&>(procInfo).AttributesCu |= SPELL_ATTR0_CU_ENCHANT_PROC;
                            }
                        }
                    }
                    break;
                }
                default:
                    break;
            }
        }

        // spells ignoring hit result should not be binary
        if (!spellInfoMutable->HasAttribute(SPELL_ATTR3_ALWAYS_HIT))
        {
            bool setFlag = false;
            for (SpellEffectInfo const& spellEffectInfo : spellInfoMutable->GetEffects())
            {
                if (spellEffectInfo.IsEffect())
                {
                    switch (spellEffectInfo.Effect)
                    {
                        case SPELL_EFFECT_SCHOOL_DAMAGE:
                        case SPELL_EFFECT_WEAPON_DAMAGE:
                        case SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL:
                        case SPELL_EFFECT_NORMALIZED_WEAPON_DMG:
                        case SPELL_EFFECT_WEAPON_PERCENT_DAMAGE:
                        case SPELL_EFFECT_TRIGGER_SPELL:
                        case SPELL_EFFECT_TRIGGER_SPELL_WITH_VALUE:
                            break;
                        case SPELL_EFFECT_PERSISTENT_AREA_AURA:
                        case SPELL_EFFECT_APPLY_AURA:
                        case SPELL_EFFECT_APPLY_AREA_AURA_PARTY:
                        case SPELL_EFFECT_APPLY_AREA_AURA_RAID:
                        case SPELL_EFFECT_APPLY_AREA_AURA_FRIEND:
                        case SPELL_EFFECT_APPLY_AREA_AURA_ENEMY:
                        case SPELL_EFFECT_APPLY_AREA_AURA_PET:
                        case SPELL_EFFECT_APPLY_AREA_AURA_OWNER:
                        case SPELL_EFFECT_APPLY_AURA_ON_PET:
                        case SPELL_EFFECT_APPLY_AREA_AURA_SUMMONS:
                        case SPELL_EFFECT_APPLY_AREA_AURA_PARTY_NONRANDOM:
                            if (spellEffectInfo.ApplyAuraName == SPELL_AURA_PERIODIC_DAMAGE ||
                                spellEffectInfo.ApplyAuraName == SPELL_AURA_PERIODIC_DAMAGE_PERCENT ||
                                spellEffectInfo.ApplyAuraName == SPELL_AURA_DUMMY ||
                                spellEffectInfo.ApplyAuraName == SPELL_AURA_PERIODIC_LEECH ||
                                spellEffectInfo.ApplyAuraName == SPELL_AURA_PERIODIC_HEALTH_FUNNEL ||
                                spellEffectInfo.ApplyAuraName == SPELL_AURA_PERIODIC_DUMMY)
                                break;
                            [[fallthrough]];
                        default:
                        {
                            // No value and not interrupt cast or crowd control without SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY flag
                            if (!spellEffectInfo.CalcValue() && !((spellEffectInfo.Effect == SPELL_EFFECT_INTERRUPT_CAST || spellInfoMutable->HasAttribute(SPELL_ATTR0_CU_AURA_CC)) && !spellInfoMutable->HasAttribute(SPELL_ATTR0_NO_IMMUNITIES)))
                                break;

                            // Sindragosa Frost Breath
                            if (spellInfoMutable->Id == 69649 || spellInfoMutable->Id == 71056 || spellInfoMutable->Id == 71057 || spellInfoMutable->Id == 71058 || spellInfoMutable->Id == 73061 || spellInfoMutable->Id == 73062 || spellInfoMutable->Id == 73063 || spellInfoMutable->Id == 73064)
                                break;

                            // Frostbolt
                            if (spellInfoMutable->SpellFamilyName == SPELLFAMILY_MAGE && (spellInfoMutable->SpellFamilyFlags[0] & 0x20))
                                break;

                            // Frost Fever
                            if (spellInfoMutable->Id == 55095)
                                break;

                            // Haunt
                            if (spellInfoMutable->SpellFamilyName == SPELLFAMILY_WARLOCK && (spellInfoMutable->SpellFamilyFlags[1] & 0x40000))
                                break;

                            setFlag = true;
                            break;
                        }
                    }

                    if (setFlag)
                    {
                        spellInfoMutable->AttributesCu |= SPELL_ATTR0_CU_BINARY_SPELL;
                        break;
                    }
                }
            }
        }

        // Remove normal school mask to properly calculate damage
        if ((spellInfoMutable->SchoolMask & SPELL_SCHOOL_MASK_NORMAL) && (spellInfoMutable->SchoolMask & SPELL_SCHOOL_MASK_MAGIC))
        {
            spellInfoMutable->SchoolMask &= ~SPELL_SCHOOL_MASK_NORMAL;
            spellInfoMutable->AttributesCu |= SPELL_ATTR0_CU_SCHOOLMASK_NORMAL_WITH_MAGIC;
        }

        spellInfoMutable->_InitializeSpellPositivity();

        if (talentSpells.count(spellInfoMutable->Id))
            spellInfoMutable->AttributesCu |= SPELL_ATTR0_CU_IS_TALENT;

        if (G3D::fuzzyNe(spellInfoMutable->Width, 0.0f))
            spellInfoMutable->AttributesCu |= SPELL_ATTR0_CU_CONE_LINE;

        switch (spellInfoMutable->SpellFamilyName)
        {
        case SPELLFAMILY_WARRIOR:
            // Shout / Piercing Howl
            if (spellInfoMutable->SpellFamilyFlags[0] & 0x20000/* || spellInfo->SpellFamilyFlags[1] & 0x20*/)
                spellInfoMutable->AttributesCu |= SPELL_ATTR0_CU_AURA_CC;
            break;
        case SPELLFAMILY_DRUID:
            // Roar
            if (spellInfoMutable->SpellFamilyFlags[0] & 0x8)
                spellInfoMutable->AttributesCu |= SPELL_ATTR0_CU_AURA_CC;
            break;
        case SPELLFAMILY_GENERIC:
            // Stoneclaw Totem effect
            if (spellInfoMutable->Id == 5729)
                spellInfoMutable->AttributesCu |= SPELL_ATTR0_CU_AURA_CC;
            break;
        default:
            break;
        }

        spellInfoMutable->_InitializeExplicitTargetMask();

        if (spellInfoMutable->Speed > 0.0f)
        {
            auto visualNeedsAmmo = [](SpellXSpellVisualEntry const* spellXspellVisual)
            {
                SpellVisualEntry const* spellVisual = sSpellVisualStore.LookupEntry(spellXspellVisual->SpellVisualID);
                if (!spellVisual)
                    return false;

                std::vector<SpellVisualMissileEntry const*> const* spellVisualMissiles = sDB2Manager.GetSpellVisualMissiles(spellVisual->SpellVisualMissileSetID);
                if (!spellVisualMissiles)
                    return false;

                for (SpellVisualMissileEntry const* spellVisualMissile : *spellVisualMissiles)
                {
                    SpellVisualEffectNameEntry const* spellVisualEffectName = sSpellVisualEffectNameStore.LookupEntry(spellVisualMissile->SpellVisualEffectNameID);
                    if (!spellVisualEffectName)
                        continue;

                    SpellVisualEffectNameType type = SpellVisualEffectNameType(spellVisualEffectName->Type);
                    if (type == SpellVisualEffectNameType::UnitAmmoBasic || type == SpellVisualEffectNameType::UnitAmmoPreferred)
                        return true;
                }

                return false;
            };

            for (SpellXSpellVisualEntry const* spellXspellVisual : spellInfoMutable->_visuals)
            {
                if (visualNeedsAmmo(spellXspellVisual))
                {
                    spellInfoMutable->AttributesCu |= SPELL_ATTR0_CU_NEEDS_AMMO_DATA;
                    break;
                }
            }
        }

        // Saving to DB happens before removing from world - skip saving these auras
        if (spellInfoMutable->HasAuraInterruptFlag(SpellAuraInterruptFlags::LeaveWorld))
            spellInfoMutable->AttributesCu |= SPELL_ATTR0_CU_AURA_CANNOT_BE_SAVED;
    }

    // addition for binary spells, omit spells triggering other spells
    for (SpellInfo const& spellInfo : mSpellInfoMap)
    {
        SpellInfo* spellInfoMutable = const_cast<SpellInfo*>(&spellInfo);
        if (!spellInfoMutable->HasAttribute(SPELL_ATTR0_CU_BINARY_SPELL))
        {
            bool allNonBinary = true;
            bool overrideAttr = false;
            for (SpellEffectInfo const& spellEffectInfo : spellInfoMutable->GetEffects())
            {
                if (spellEffectInfo.IsAura() && spellEffectInfo.TriggerSpell)
                {
                    switch (spellEffectInfo.ApplyAuraName)
                    {
                        case SPELL_AURA_PERIODIC_TRIGGER_SPELL:
                        case SPELL_AURA_PERIODIC_TRIGGER_SPELL_FROM_CLIENT:
                        case SPELL_AURA_PERIODIC_TRIGGER_SPELL_WITH_VALUE:
                            if (SpellInfo const* triggerSpell = sSpellMgr->GetSpellInfo(spellEffectInfo.TriggerSpell, DIFFICULTY_NONE))
                            {
                                overrideAttr = true;
                                if (triggerSpell->HasAttribute(SPELL_ATTR0_CU_BINARY_SPELL))
                                    allNonBinary = false;
                            }
                            break;
                        default:
                            break;
                    }
                }
            }

            if (overrideAttr && allNonBinary)
                spellInfoMutable->AttributesCu &= ~SPELL_ATTR0_CU_BINARY_SPELL;
        }

        // remove attribute from spells that can't crit
        if (spellInfo.HasAttribute(SPELL_ATTR0_CU_CAN_CRIT))
            if (spellInfo.HasAttribute(SPELL_ATTR2_CANT_CRIT))
                spellInfoMutable->AttributesCu &= ~SPELL_ATTR0_CU_CAN_CRIT;

    }

    // add custom attribute to liquid auras
    for (LiquidTypeEntry const* liquid : sLiquidTypeStore)
    {
        if (liquid->SpellID)
            for (SpellInfo const& spellInfo : _GetSpellInfo(liquid->SpellID))
                const_cast<SpellInfo&>(spellInfo).AttributesCu |= SPELL_ATTR0_CU_AURA_CANNOT_BE_SAVED;
    }

    TC_LOG_INFO("server.loading", ">> Loaded SpellInfo custom attributes in {} ms", GetMSTimeDiffToNow(oldMSTime));
}

inline void ApplySpellFix(std::initializer_list<uint32> spellIds, void(*fix)(SpellInfo*))
{
    for (uint32 spellId : spellIds)
    {
        auto range = _GetSpellInfo(spellId);
        if (range.begin() == range.end())
        {
            TC_LOG_ERROR("server.loading", "Spell info correction specified for non-existing spell {}", spellId);
            continue;
        }

        for (SpellInfo const& spellInfo : range)
            fix(&const_cast<SpellInfo&>(spellInfo));
    }
}

inline void ApplySpellEffectFix(SpellInfo* spellInfo, SpellEffIndex effectIndex, void(*fix)(SpellEffectInfo*))
{
    if (spellInfo->GetEffects().size() <= effectIndex)
    {
        TC_LOG_ERROR("server.loading", "Spell effect info correction specified for non-existing effect {} of spell {}", uint32(effectIndex), spellInfo->Id);
        return;
    }

    fix(const_cast<SpellEffectInfo*>(&spellInfo->GetEffect(effectIndex)));
}

void SpellMgr::LoadSpellInfoCorrections()
{
    uint32 oldMSTime = getMSTime();

    // Some spells have no amplitude set
    {
        ApplySpellFix({
            6727,  // Poison Mushroom
            7331,  // Healing Aura (TEST) (Rank 1)
            /*
            30400, // Nether Beam - Perseverance
                Blizzlike to have it disabled? DBC says:
                "This is currently turned off to increase performance. Enable this to make it fire more frequently."
            */
            34589, // Dangerous Water
            52562, // Arthas Zombie Catcher
            57550, // Tirion Aggro
            65755
        }, [](SpellInfo* spellInfo)
        {
            ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
            {
                spellEffectInfo->ApplyAuraPeriod = 1 * IN_MILLISECONDS;
            });
        });

        ApplySpellFix({
            24707, // Food
            26263, // Dim Sum
            29055  // Refreshing Red Apple
        }, [](SpellInfo* spellInfo)
        {
            ApplySpellEffectFix(spellInfo, EFFECT_1, [](SpellEffectInfo* spellEffectInfo)
            {
                spellEffectInfo->ApplyAuraPeriod = 1 * IN_MILLISECONDS;
            });
        });

        // Karazhan - Chess NPC AI, action timer
        ApplySpellFix({ 37504 }, [](SpellInfo* spellInfo)
        {
            ApplySpellEffectFix(spellInfo, EFFECT_1, [](SpellEffectInfo* spellEffectInfo)
            {
                spellEffectInfo->ApplyAuraPeriod = 5 * IN_MILLISECONDS;
            });
        });

        // Vomit
        ApplySpellFix({ 43327 }, [](SpellInfo* spellInfo)
        {
            ApplySpellEffectFix(spellInfo, EFFECT_1, [](SpellEffectInfo* spellEffectInfo)
            {
                spellEffectInfo->ApplyAuraPeriod = 1 * IN_MILLISECONDS;
            });
        });
    }

    // specific code for cases with no trigger spell provided in field
    {
        // Brood Affliction: Bronze
        ApplySpellFix({ 23170 }, [](SpellInfo* spellInfo)
        {
            ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
            {
                spellEffectInfo->TriggerSpell = 23171;
            });
        });

        // Feed Captured Animal
        ApplySpellFix({ 29917 }, [](SpellInfo* spellInfo)
        {
            ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
            {
                spellEffectInfo->TriggerSpell = 29916;
            });
        });

        // Remote Toy
        ApplySpellFix({ 37027 }, [](SpellInfo* spellInfo)
        {
            ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
            {
                spellEffectInfo->TriggerSpell = 37029;
            });
        });

        // Eye of Grillok
        ApplySpellFix({ 38495 }, [](SpellInfo* spellInfo)
        {
            ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
            {
                spellEffectInfo->TriggerSpell = 38530;
            });
        });

        // Tear of Azzinoth Summon Channel - it's not really supposed to do anything, and this only prevents the console spam
        ApplySpellFix({ 39857 }, [](SpellInfo* spellInfo)
        {
            ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
            {
                spellEffectInfo->TriggerSpell = 39856;
            });
        });

        // Personalized Weather
        ApplySpellFix({ 46736 }, [](SpellInfo* spellInfo)
        {
            ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
            {
                spellEffectInfo->TriggerSpell = 46737;
                spellEffectInfo->ApplyAuraName = SPELL_AURA_PERIODIC_TRIGGER_SPELL;
            });
        });
    }

    ApplySpellFix({
        63026, // Summon Aspirant Test NPC (HACK: Target shouldn't be changed)
        63137  // Summon Valiant Test (HACK: Target shouldn't be changed; summon position should be untied from spell destination)
    }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetA = SpellImplicitTargetInfo(TARGET_DEST_DB);
        });
    });

    // Summon Skeletons
    ApplySpellFix({ 52611, 52612 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->MiscValueB = 64;
        });
    });

    ApplySpellFix({
        40244, // Simon Game Visual
        40245, // Simon Game Visual
        40246, // Simon Game Visual
        40247, // Simon Game Visual
        42835  // Spout, remove damage effect, only anim is needed
    }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->Effect = SPELL_EFFECT_NONE;
        });
    });

    ApplySpellFix({
        63665, // Charge (Argent Tournament emote on riders)
        31298, // Sleep (needs target selection script)
        51904, // Summon Ghouls On Scarlet Crusade (this should use conditions table, script for this spell needs to be fixed)
        68933, // Wrath of Air Totem rank 2 (Aura)
        29200  // Purify Helboar Meat
    }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
            spellEffectInfo->TargetB = SpellImplicitTargetInfo();
        });
    });

    ApplySpellFix({
        56690, // Thrust Spear
        60586, // Mighty Spear Thrust
        60776, // Claw Swipe
        60881, // Fatal Strike
        60864  // Jaws of Death
        }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx4 |= SPELL_ATTR4_IGNORE_DAMAGE_TAKEN_MODIFIERS;
    });

    // Howl of Azgalor
    ApplySpellFix({ 31344 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetARadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_100_YARDS); // 100yards instead of 50000?!
        });
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
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TriggerSpell = 36325; // They Must Burn Bomb Drop (DND)
        });
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
        53457, // Summon Impale Trigger (AoE)
        45907, // Torch Target Picker
        52953, // Torch
        58121, // Torch
        43109, // Throw Torch
        58552, // Return to Orgrimmar
        58533, // Return to Stormwind
        21855, // Challenge Flag
        38762, // Force of Neltharaku
        51122, // Fierce Lightning Stike
        71848, // Toxic Wasteling Find Target
        36146, // Chains of Naberius
        33711, // Murmur's Touch
        38794  // Murmur's Touch
    }, [](SpellInfo* spellInfo)
    {
        spellInfo->MaxAffectedTargets = 1;
    });

    ApplySpellFix({
        36384, // Skartax Purple Beam
        47731  // Critter
    }, [](SpellInfo* spellInfo)
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
        28796, // Poison Bolt Volly - Faerlina
        37135  // Domination
    }, [](SpellInfo* spellInfo)
    {
        spellInfo->MaxAffectedTargets = 5;
    });

    ApplySpellFix({
        40827, // Sinful Beam
        40859, // Sinister Beam
        40860, // Vile Beam
        40861, // Wicked Beam
        54098, // Poison Bolt Volly - Faerlina (H)
        54835  // Curse of the Plaguebringer - Noth (H)
    }, [](SpellInfo* spellInfo)
    {
        spellInfo->MaxAffectedTargets = 10;
    });

    // Unholy Frenzy
    ApplySpellFix({ 50312 }, [](SpellInfo* spellInfo)
    {
        spellInfo->MaxAffectedTargets = 15;
    });

    // Fingers of Frost
    ApplySpellFix({ 44544 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->SpellClassMask[0] |= 0x20000;
        });
    });

    ApplySpellFix({
        52212, // Death and Decay
        41485, // Deadly Poison - Black Temple
        41487  // Envenom - Black Temple
    }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx6 |= SPELL_ATTR6_IGNORE_PHASE_SHIFT;
    });

    // Oscillation Field
    ApplySpellFix({ 37408 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx3 |= SPELL_ATTR3_DOT_STACKING_RULE;
    });

    // Crafty's Ultra-Advanced Proto-Typical Shortening Blaster
    ApplySpellFix({ 51912 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->ApplyAuraPeriod = 3000;
        });
    });

    // Nether Portal - Perseverence
    ApplySpellFix({ 30421 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_2, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->BasePoints += 30000;
        });
    });

    // Parasitic Shadowfiend Passive
    ApplySpellFix({ 41913 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->ApplyAuraName = SPELL_AURA_DUMMY; // proc debuff, and summon infinite fiends
        });
    });

    ApplySpellFix({
        27892, // To Anchor 1
        27928, // To Anchor 1
        27935, // To Anchor 1
    }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetARadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_10_YARDS);
        });
    });

    // Wrath of the Plaguebringer
    ApplySpellFix({ 29214, 54836 }, [](SpellInfo* spellInfo)
    {
        // target allys instead of enemies, target A is src_caster, spells with effect like that have ally target
        // this is the only known exception, probably just wrong data
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetB = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ALLY);
        });
        ApplySpellEffectFix(spellInfo, EFFECT_1, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetB = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ALLY);
        });
    });

    // Earthbind Totem (instant pulse)
    ApplySpellFix({ 6474 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx5 |= SPELL_ATTR5_EXTRA_INITIAL_PERIOD;
    });

    ApplySpellFix({
        70728, // Exploit Weakness (needs target selection script)
        70840  // Devious Minds (needs target selection script)
    }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
            spellEffectInfo->TargetB = SpellImplicitTargetInfo(TARGET_UNIT_PET);
        });
    });

    // Ride Carpet
    ApplySpellFix({ 45602 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->BasePoints = 0; // force seat 0, vehicle doesn't have the required seat flags for "no seat specified (-1)"
        });
    });

    // Easter Lay Noblegarden Egg Aura - Interrupt flags copied from aura which this aura is linked with
    ApplySpellFix({ 61719 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AuraInterruptFlags = SpellAuraInterruptFlags::HostileActionReceived | SpellAuraInterruptFlags::Damage;
    });

    ApplySpellFix({
        71838, // Drain Life - Bryntroll Normal
        71839  // Drain Life - Bryntroll Heroic
    }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx2 |= SPELL_ATTR2_CANT_CRIT;
    });

    ApplySpellFix({
        51597, // Summon Scourged Captive
        56606, // Ride Jokkum
        61791  // Ride Vehicle (Yogg-Saron)
    }, [](SpellInfo* spellInfo)
    {
        /// @todo: remove this when basepoints of all Ride Vehicle auras are calculated correctly
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->BasePoints = 1;
        });
    });

    // Summon Scourged Captive
    ApplySpellFix({ 51597 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->Scaling.Variance = 0.0f;
        });
    });

    // Black Magic
    ApplySpellFix({ 59630 }, [](SpellInfo* spellInfo)
    {
        spellInfo->Attributes |= SPELL_ATTR0_PASSIVE;
    });

    // Paralyze
    ApplySpellFix({ 48278 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx3 |= SPELL_ATTR3_DOT_STACKING_RULE;
    });

    ApplySpellFix({
        51798, // Brewfest - Relay Race - Intro - Quest Complete
        47134  // Quest Complete
    }, [](SpellInfo* spellInfo)
    {
        //! HACK: This spell break quest complete for alliance and on retail not used
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->Effect = SPELL_EFFECT_NONE;
        });
    });

    // Siege Cannon (Tol Barad)
    ApplySpellFix({ 85123 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetARadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS);
            spellEffectInfo->TargetA = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ENTRY);
        });
    });

    // Gathering Storms
    ApplySpellFix({ 198300 }, [](SpellInfo* spellInfo)
    {
        spellInfo->ProcCharges = 1; // override proc charges, has 0 (unlimited) in db2
    });

    ApplySpellFix({
        15538, // Gout of Flame
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
        spellInfo->ChannelInterruptFlags &= ~SpellAuraInterruptFlags::Action;
    });

    // Sic'em
    ApplySpellFix({ 42767 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetA = SpellImplicitTargetInfo(TARGET_UNIT_NEARBY_ENTRY);
        });
    });

    // Burn Body
    ApplySpellFix({ 42793 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_2, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->MiscValue = 24008; // Fallen Combatant
        });
    });

    // Gift of the Naaru (priest and monk variants)
    ApplySpellFix({ 59544, 121093 }, [](SpellInfo* spellInfo)
    {
        spellInfo->SpellFamilyFlags[2] = 0x80000000;
    });

    ApplySpellFix({
        50661, // Weakened Resolve
        68979, // Unleashed Souls
        48714, // Compelled
        7853,  // The Art of Being a Water Terror: Force Cast on Player
    }, [](SpellInfo* spellInfo)
    {
        spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(13); // 50000yd
    });

    ApplySpellFix({
        44327, // Trained Rock Falcon/Hawk Hunting
        44408  // Trained Rock Falcon/Hawk Hunting
        }, [](SpellInfo* spellInfo)
    {
        spellInfo->Speed = 0.f;
    });

    // Summon Corpse Scarabs
    ApplySpellFix({ 28864, 29105 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetARadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_10_YARDS);
        });
    });

    ApplySpellFix({
        37851, // Tag Greater Felfire Diemetradon
        37918  // Arcano-pince
    }, [](SpellInfo* spellInfo)
    {
        spellInfo->RecoveryTime = 3000;
    });

    // Jormungar Strike
    ApplySpellFix({ 56513 }, [](SpellInfo* spellInfo)
    {
        spellInfo->RecoveryTime = 2000;
    });

    ApplySpellFix({
        54997, // Cast Net (tooltip says 10s but sniffs say 6s)
        56524  // Acid Breath
    }, [](SpellInfo* spellInfo)
    {
        spellInfo->RecoveryTime = 6000;
    });

    ApplySpellFix({
        47911, // EMP
        48620, // Wing Buffet
        51752  // Stampy's Stompy-Stomp
    }, [](SpellInfo* spellInfo)
    {
        spellInfo->RecoveryTime = 10000;
    });

    ApplySpellFix({
        37727, // Touch of Darkness
        54996  // Ice Slick (tooltip says 20s but sniffs say 12s)
    }, [](SpellInfo* spellInfo)
    {
        spellInfo->RecoveryTime = 12000;
    });

    // Signal Helmet to Attack
    ApplySpellFix({ 51748 }, [](SpellInfo* spellInfo)
    {
        spellInfo->RecoveryTime = 15000;
    });

    ApplySpellFix({
        51756, // Charge
        37919, //Arcano-dismantle
        37917  //Arcano-Cloak
    }, [](SpellInfo* spellInfo)
    {
        spellInfo->RecoveryTime = 20000;
    });

    // Summon Frigid Bones
    ApplySpellFix({ 53525 }, [](SpellInfo* spellInfo)
    {
        spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(4); // 2 minutes
    });

    // Dark Conclave Ritualist Channel
    ApplySpellFix({ 38469 }, [](SpellInfo* spellInfo)
    {
        spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(6);  // 100yd
    });

    // Chrono Shift (enemy slow part)
    ApplySpellFix({ 236299 }, [](SpellInfo* spellInfo)
    {
        spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(6);  // 100yd
    });

    // Inescapable Torment
    ApplySpellFix({ 373427 }, [](SpellInfo* spellInfo)
    {
        // Remove self-damage from passive aura on learn
        ApplySpellEffectFix(spellInfo, EFFECT_3, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->Effect = SPELL_EFFECT_DUMMY;
        });
    });

    //
    // VIOLET HOLD SPELLS
    //
    // Water Globule (Ichoron)
    ApplySpellFix({ 54258, 54264, 54265, 54266, 54267 }, [](SpellInfo* spellInfo)
    {
        // in 3.3.5 there is only one radius in dbc which is 0 yards in this case
        // use max radius from 4.3.4
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetARadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_25_YARDS);
        });
    });
    // ENDOF VIOLET HOLD

    //
    // ULDUAR SPELLS
    //
    // Pursued (Flame Leviathan)
    ApplySpellFix({ 62374 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetARadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_50000_YARDS);   // 50000yd
        });
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
        spellInfo->AttributesEx3 |= SPELL_ATTR3_DOT_STACKING_RULE;
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
        spellInfo->AttributesEx |= SPELL_ATTR1_IMMUNITY_PURGES_EFFECT;
    });

    // Blizzard (Thorim)
    ApplySpellFix({ 62576, 62602 }, [](SpellInfo* spellInfo)
    {
        // DBC data is wrong for EFFECT_0, it's a different dynobject target than EFFECT_1
        // Both effects should be shared by the same DynObject
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetA = SpellImplicitTargetInfo(TARGET_DEST_CASTER_LEFT);
        });
    });

    // Spinning Up (Mimiron)
    ApplySpellFix({ 63414 }, [](SpellInfo* spellInfo)
    {
        spellInfo->ChannelInterruptFlags = SpellAuraInterruptFlags::None;
        spellInfo->ChannelInterruptFlags2 = SpellAuraInterruptFlags2::None;
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetB = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
        });
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
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetB = SpellImplicitTargetInfo(TARGET_DEST_CASTER);
        });
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
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetA = SpellImplicitTargetInfo(TARGET_DEST_DB);
        });
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
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetA = SpellImplicitTargetInfo(TARGET_DEST_DB);
        });
    });

    // Shadow's Fate
    ApplySpellFix({ 71169 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx3 |= SPELL_ATTR3_DOT_STACKING_RULE;
    });

    // Resistant Skin (Deathbringer Saurfang adds)
    ApplySpellFix({ 72723 }, [](SpellInfo* spellInfo)
    {
        // this spell initially granted Shadow damage immunity, however it was removed but the data was left in client
        ApplySpellEffectFix(spellInfo, EFFECT_2, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->Effect = SPELL_EFFECT_NONE;
        });
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
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ANY);
        });
    });

    // Awaken Plagued Zombies
    ApplySpellFix({ 71159 }, [](SpellInfo* spellInfo)
    {
        spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(21);
    });

    // Volatile Ooze Beam Protection (Professor Putricide)
    ApplySpellFix({ 70530 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->Effect = SPELL_EFFECT_APPLY_AURA; // for an unknown reason this was SPELL_EFFECT_APPLY_AREA_AURA_RAID
        });
    });

    // Mutated Strength (Professor Putricide)
    ApplySpellFix({ 71604 }, [](SpellInfo* spellInfo)
    {
        // THIS IS HERE BECAUSE COOLDOWN ON CREATURE PROCS WERE NOT IMPLEMENTED WHEN THE SCRIPT WAS WRITTEN
        ApplySpellEffectFix(spellInfo, EFFECT_1, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->Effect = SPELL_EFFECT_NONE;
        });
    });

    // Unbound Plague (Professor Putricide) (needs target selection script)
    ApplySpellFix({ 70911 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetB = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
        });
    });

    // Empowered Flare (Blood Prince Council)
    ApplySpellFix({ 71708 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_CASTER_MODIFIERS;
    });

    // Swarming Shadows
    ApplySpellFix({ 71266 }, [](SpellInfo* spellInfo)
    {
        spellInfo->RequiredAreasID = 0; // originally, these require area 4522, which is... outside of Icecrown Citadel
    });

    // Corruption
    ApplySpellFix({ 70602 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx3 |= SPELL_ATTR3_DOT_STACKING_RULE;
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
        spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(157); // 90yd
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ANY);
            spellEffectInfo->TargetB = SpellImplicitTargetInfo();
        });
    });

    // Sindragosa's Fury
    ApplySpellFix({ 70598 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetA = SpellImplicitTargetInfo(TARGET_DEST_DEST);
        });
    });

    // Frost Bomb
    ApplySpellFix({ 69846 }, [](SpellInfo* spellInfo)
    {
        spellInfo->Speed = 0.0f;    // This spell's summon happens instantly
    });

    // Chilled to the Bone
    ApplySpellFix({ 70106 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_CASTER_MODIFIERS;
        spellInfo->AttributesEx6 |= SPELL_ATTR6_IGNORE_CASTER_DAMAGE_MODIFIERS;
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
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetARadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS); // 200yd
        });
        ApplySpellEffectFix(spellInfo, EFFECT_1, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetARadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS); // 200yd
        });
    });

    // Val'kyr Target Search
    ApplySpellFix({ 69030 }, [](SpellInfo* spellInfo)
    {
        spellInfo->Attributes |= SPELL_ATTR0_NO_IMMUNITIES;
    });

    // Raging Spirit Visual
    ApplySpellFix({ 69198 }, [](SpellInfo* spellInfo)
    {
        spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(13); // 50000yd
    });

    // Harvest Soul
    ApplySpellFix({ 73655 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_CASTER_MODIFIERS;
    });

    // Summon Shadow Trap
    ApplySpellFix({ 73540 }, [](SpellInfo* spellInfo)
    {
        spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(3); // 60 seconds
    });

    // Shadow Trap (visual)
    ApplySpellFix({ 73530 }, [](SpellInfo* spellInfo)
    {
        spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(27); // 3 seconds
    });

    // Summon Spirit Bomb
    ApplySpellFix({ 74302 }, [](SpellInfo* spellInfo)
    {
        spellInfo->MaxAffectedTargets = 2;
    });

    // Summon Spirit Bomb
    ApplySpellFix({ 73579 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetARadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_25_YARDS); // 25yd
        });
    });

    // Raise Dead
    ApplySpellFix({ 72376 }, [](SpellInfo* spellInfo)
    {
        spellInfo->MaxAffectedTargets = 3;
    });

    // Jump
    ApplySpellFix({ 71809 }, [](SpellInfo* spellInfo)
    {
        spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(5); // 40yd
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetARadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_10_YARDS); // 10yd
            spellEffectInfo->MiscValue = 190;
        });
    });
    // ENDOF ICECROWN CITADEL SPELLS

    //
    // RUBY SANCTUM SPELLS
    //
    // Soul Consumption
    ApplySpellFix({ 74799 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_1, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetARadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_12_YARDS);
        });
    });

    // Twilight Mending
    ApplySpellFix({ 75509 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx6 |= SPELL_ATTR6_IGNORE_PHASE_SHIFT;
        spellInfo->AttributesEx2 |= SPELL_ATTR2_IGNORE_LINE_OF_SIGHT;
    });

    // Awaken Flames
    ApplySpellFix({ 75888 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx |= SPELL_ATTR1_EXCLUDE_CASTER;
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
        spellInfo->AttributesEx2 |= SPELL_ATTR2_IGNORE_LINE_OF_SIGHT;
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
        spellInfo->Attributes |= SPELL_ATTR0_AURA_IS_DEBUFF;
    });

    //
    // STONECORE SPELLS
    //
    ApplySpellFix({
        95284, // Teleport (from entrance to Slabhide)
        95285  // Teleport (from Slabhide to entrance)
    }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetB = SpellImplicitTargetInfo(TARGET_DEST_DB);
        });
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
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetBRadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_45_YARDS);
        });
    });

    // ENDOF HALLS OF ORIGINATION SPELLS

    // Threatening Gaze
    ApplySpellFix({ 24314 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AuraInterruptFlags |= SpellAuraInterruptFlags::Action | SpellAuraInterruptFlags::Moving | SpellAuraInterruptFlags::Anim;
    });

    // Travel Form (dummy) - cannot be cast indoors.
    ApplySpellFix({ 783 }, [](SpellInfo* spellInfo)
    {
        spellInfo->Attributes |= SPELL_ATTR0_ONLY_OUTDOORS;
    });

    // Tree of Life (Passive)
    ApplySpellFix({ 5420 }, [](SpellInfo* spellInfo)
    {
        spellInfo->Stances = UI64LIT(1) << (FORM_TREE_OF_LIFE - 1);
    });

    // Gaze of Occu'thar
    ApplySpellFix({ 96942 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx &= ~SPELL_ATTR1_IS_CHANNELLED;
    });

    // Evolution
    ApplySpellFix({ 75610 }, [](SpellInfo* spellInfo)
    {
        spellInfo->MaxAffectedTargets = 1;
    });

    // Evolution
    ApplySpellFix({ 75697 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetA = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ENTRY);
        });
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

    // Aura of Fear
    ApplySpellFix({ 40453 }, [](SpellInfo* spellInfo)
    {
        // Bad DBC data? Copying 25820 here due to spell description
        // either is a periodic with chance on tick, or a proc

        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
                spellEffectInfo->ApplyAuraName = SPELL_AURA_PROC_TRIGGER_SPELL;
                spellEffectInfo->ApplyAuraPeriod = 0;
        });
        spellInfo->ProcChance = 10;
    });

    // Survey Sinkholes
    ApplySpellFix({ 45853 }, [](SpellInfo* spellInfo)
    {
        spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(5); // 40 yards
    });

    // Baron Rivendare (Stratholme) - Unholy Aura
    ApplySpellFix({ 17466, 17467 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx2 |= SPELL_ATTR2_NO_INITIAL_THREAT;
    });

    // Spore - Spore Visual
    ApplySpellFix({ 42525 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx3 |= SPELL_ATTR3_ALLOW_AURA_WHILE_DEAD;
        spellInfo->AttributesEx2 |= SPELL_ATTR2_ALLOW_DEAD_TARGET;
    });

    // Soul Sickness (Forge of Souls)
    ApplySpellFix({ 69131 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_1, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->ApplyAuraName = SPELL_AURA_MOD_DECREASE_SPEED;
        });
    });

    //
    // FIRELANDS SPELLS
    //
    // Torment Searcher
    ApplySpellFix({ 99253 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetBRadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_15_YARDS);
        });
    });

    // Torment Damage
    ApplySpellFix({ 99256 }, [](SpellInfo* spellInfo)
    {
        spellInfo->Attributes |= SPELL_ATTR0_AURA_IS_DEBUFF;
    });

    // Blaze of Glory
    ApplySpellFix({ 99252 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AuraInterruptFlags |= SpellAuraInterruptFlags::LeaveWorld;
    });
    // ENDOF FIRELANDS

    //
    // SCARLET HALLS SPELLS
    //

    // 111755 - Call Reinforcement
    ApplySpellFix({ 111755 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx2 |= SPELL_ATTR2_IGNORE_LINE_OF_SIGHT;

        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetA = SpellImplicitTargetInfo(TARGET_DEST_DB);
        });
    });

    // 111756 - Call Reinforcement
    ApplySpellFix({ 111756 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx2 |= SPELL_ATTR2_IGNORE_LINE_OF_SIGHT;

        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetA = SpellImplicitTargetInfo(TARGET_DEST_DB);
        });
    });

    // ENDOF SCARLET HALLS SPELLS

    //
    // MARDUM SPELLS
    //

    // 187382 - The Invasion Begins: Summon Wrath Warrior
    ApplySpellFix({ 187382 }, [](SpellInfo* spellInfo)
    {
        spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(13); // 50000 yards

        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetA = SpellImplicitTargetInfo(TARGET_DEST_DEST);
        });
    });

    // 195061 - Beaming Gaze
    ApplySpellFix({ 195061 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetA = SpellImplicitTargetInfo(TARGET_DEST_DEST);
        });
    });

    // ENDOF MARDUM SPELLS

    //
    // MAW OF SOULS SPELLS
    //

    // 193465 - Bane
    ApplySpellFix({ 193465 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            // Normal difficulty should also be using the regular heroic+ AreaTriggerCreateProperties
            spellEffectInfo->MiscValue = 5838;
        });
    });

    // ENDOF MAW OF SOULS SPELLS

    //
    // ANTORUS THE BURNING THRONE SPELLS
    //

    // Decimation
    ApplySpellFix({ 244449 }, [](SpellInfo* spellInfo)
    {
        // For some reason there is a instakill effect that serves absolutely no purpose.
        // Until we figure out what it's actually used for we disable it.
        ApplySpellEffectFix(spellInfo, EFFECT_2, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->Effect = SPELL_EFFECT_NONE;
        });
    });

    // ENDOF ANTORUS THE BURNING THRONE SPELLS

    //
    // STORMSONG VALLEY SPELLS
    //

    // Void Orb
    ApplySpellFix({ 273467 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetARadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_0_5_YARDS);
        });
    });

    // ENDOF STORMSONG VALLEY SPELLS

    //
    // SEPULCHER OF THE FIRST ONES
    //

    // Wicked Star (Marker)
    ApplySpellFix({ 365021 }, [](SpellInfo* spellInfo)
    {
        spellInfo->Attributes |= SPELL_ATTR0_AURA_IS_DEBUFF;
    });

    // Empowered Wicked Star (Marker)
    ApplySpellFix({ 367632 }, [](SpellInfo* spellInfo)
    {
        spellInfo->Attributes |= SPELL_ATTR0_AURA_IS_DEBUFF;
    });

    // Wicked Star Areatrigger
    ApplySpellFix({ 365017 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetA = SpellImplicitTargetInfo(TARGET_DEST_DEST);
        });
    });

    // Willpower Energize Large
    ApplySpellFix({ 365228 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx6 |= SPELL_ATTR6_IGNORE_PHASE_SHIFT;
    });

    // Willpower Energize Small
    ApplySpellFix({ 365217 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx6 |= SPELL_ATTR6_IGNORE_PHASE_SHIFT;
    });

    // Force of Will
    ApplySpellFix({ 368913 }, [](SpellInfo* spellInfo)
    {
        spellInfo->Attributes |= SPELL_ATTR0_AURA_IS_DEBUFF;
    });

    // Fragment of Hope Areatrigger
    ApplySpellFix({ 365816 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetA = SpellImplicitTargetInfo(TARGET_DEST_DEST);
        });
        ApplySpellEffectFix(spellInfo, EFFECT_1, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetA = SpellImplicitTargetInfo(TARGET_DEST_DEST);
        });
    });

    // Shadestep
    ApplySpellFix({ 363976 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetB = SpellImplicitTargetInfo(TARGET_DEST_DEST);
        });
    });
    // END OF SEPULCHER OF THE FIRST ONES

    //
    // THE AZURE VAULT SPELLS
    //

    // Stinging Sap
    ApplySpellFix({ 374523 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx8 |= SPELL_ATTR8_CAN_ATTACK_IMMUNE_PC;
    });

    // Jump to Center (DNT)
    ApplySpellFix({ 387981 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetA = SpellImplicitTargetInfo(TARGET_DEST_DEST);
        });
    });

    // Jump to Platform (DNT)
    ApplySpellFix({ 388082 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetA = SpellImplicitTargetInfo(TARGET_DEST_DEST);
        });
    });

    // ENDOF THE AZURE VAULT SPELLS
    //
    // Summon Master Li Fei
    ApplySpellFix({ 102445 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->TargetA = SpellImplicitTargetInfo(TARGET_DEST_DB);
        });
    });

    // Earthquake
    ApplySpellFix({ 61882 }, [](SpellInfo* spellInfo)
    {
        spellInfo->NegativeEffects[EFFECT_2] = true;
    });

    // Headless Horseman Climax - Return Head (Hallow End)
    // Headless Horseman Climax - Body Regen (confuse only - removed on death)
    // Headless Horseman Climax - Head Is Dead
    ApplySpellFix({ 42401, 43105, 42428 }, [](SpellInfo* spellInfo)
    {
        spellInfo->Attributes |= SPELL_ATTR0_NO_IMMUNITIES;
    });

    // Horde / Alliance switch (BG mercenary system)
    ApplySpellFix({ 195838, 195843 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->Effect = SPELL_EFFECT_APPLY_AURA;
        });
        ApplySpellEffectFix(spellInfo, EFFECT_1, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->Effect = SPELL_EFFECT_APPLY_AURA;
        });
        ApplySpellEffectFix(spellInfo, EFFECT_2, [](SpellEffectInfo* spellEffectInfo)
        {
            spellEffectInfo->Effect = SPELL_EFFECT_APPLY_AURA;
        });
    });

    // Fire Cannon
    ApplySpellFix({ 181593 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            // This spell never triggers, theory is that it was supposed to be only triggered until target reaches some health percentage
            // but was broken and always caused visuals to break, then target was changed to immediately spawn with desired health
            // leaving old data in db2
            spellEffectInfo->TriggerSpell = 0;
        });
    });

    ApplySpellFix({ 265057 }, [](SpellInfo* spellInfo)
    {
        ApplySpellEffectFix(spellInfo, EFFECT_0, [](SpellEffectInfo* spellEffectInfo)
        {
            // Fix incorrect spell id (it has self in TriggerSpell)
            spellEffectInfo->TriggerSpell = 16403;
        });
    });

    // Ray of Frost (Fingers of Frost charges)
    ApplySpellFix({ 269748 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx &= ~SPELL_ATTR1_IS_CHANNELLED;
    });

    // Burning Rush
    ApplySpellFix({ 111400 }, [](SpellInfo* spellInfo)
    {
        spellInfo->AttributesEx4 |= SPELL_ATTR4_AURA_IS_BUFF;
    });

    for (SpellInfo const& s : mSpellInfoMap)
    {
        SpellInfo* spellInfo = &const_cast<SpellInfo&>(s);
        if (!spellInfo)
            continue;

        // Fix range for trajectory triggered spell
        for (SpellEffectInfo const& spellEffectInfo : spellInfo->GetEffects())
        {
            if (spellEffectInfo.IsEffect() && (spellEffectInfo.TargetA.GetTarget() == TARGET_DEST_TRAJ || spellEffectInfo.TargetB.GetTarget() == TARGET_DEST_TRAJ))
            {
                // Get triggered spell if any
                for (SpellInfo const& spellInfoTrigger : _GetSpellInfo(spellEffectInfo.TriggerSpell))
                {
                    float maxRangeMain = spellInfo->GetMaxRange();
                    float maxRangeTrigger = spellInfoTrigger.GetMaxRange();

                    // check if triggered spell has enough max range to cover trajectory
                    if (maxRangeTrigger < maxRangeMain)
                        const_cast<SpellInfo&>(spellInfoTrigger).RangeEntry = spellInfo->RangeEntry;
                }
            }

            switch (spellEffectInfo.Effect)
            {
                case SPELL_EFFECT_CHARGE:
                case SPELL_EFFECT_CHARGE_DEST:
                case SPELL_EFFECT_JUMP:
                case SPELL_EFFECT_JUMP_DEST:
                case SPELL_EFFECT_LEAP_BACK:
                    if (!spellInfo->Speed && !spellInfo->SpellFamilyName && !spellInfo->HasAttribute(SPELL_ATTR9_MISSILE_SPEED_IS_DELAY_IN_SEC))
                        spellInfo->Speed = SPEED_CHARGE;
                    break;
                default:
                    break;
            }

            if (spellEffectInfo.TargetA.GetSelectionCategory() == TARGET_SELECT_CATEGORY_CONE || spellEffectInfo.TargetB.GetSelectionCategory() == TARGET_SELECT_CATEGORY_CONE)
                if (G3D::fuzzyEq(spellInfo->ConeAngle, 0.f))
                    spellInfo->ConeAngle = 90.f;

            // Area auras may not target area (they're self cast)
            if (spellEffectInfo.IsAreaAuraEffect() && spellEffectInfo.IsTargetingArea())
            {
                const_cast<SpellEffectInfo&>(spellEffectInfo).TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
                const_cast<SpellEffectInfo&>(spellEffectInfo).TargetB = SpellImplicitTargetInfo(0);
            }
        }

        // disable proc for magnet auras, they're handled differently
        if (spellInfo->HasAura(SPELL_AURA_SPELL_MAGNET))
            spellInfo->ProcFlags = std::array<int32, 2>{};

        // due to the way spell system works, unit would change orientation in Spell::_cast
        if (spellInfo->HasAura(SPELL_AURA_CONTROL_VEHICLE))
            spellInfo->AttributesEx5 |= SPELL_ATTR5_AI_DOESNT_FACE_TARGET;

        if (spellInfo->ActiveIconFileDataId == 135754)  // flight
            spellInfo->Attributes |= SPELL_ATTR0_PASSIVE;

        if (spellInfo->IsSingleTarget() && !spellInfo->MaxAffectedTargets)
            spellInfo->MaxAffectedTargets = 1;
    }

    if (SummonPropertiesEntry* properties = const_cast<SummonPropertiesEntry*>(sSummonPropertiesStore.LookupEntry(121)))
        properties->Title = AsUnderlyingType(SummonTitle::Totem);
    if (SummonPropertiesEntry* properties = const_cast<SummonPropertiesEntry*>(sSummonPropertiesStore.LookupEntry(647))) // 52893
        properties->Title = AsUnderlyingType(SummonTitle::Totem);
    if (SummonPropertiesEntry* properties = const_cast<SummonPropertiesEntry*>(sSummonPropertiesStore.LookupEntry(628))) // Hungry Plaguehound
        properties->Control = SUMMON_CATEGORY_PET;

    TC_LOG_INFO("server.loading", ">> Loaded SpellInfo corrections in {} ms", GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellInfoSpellSpecificAndAuraState()
{
    uint32 oldMSTime = getMSTime();

    for (SpellInfo const& spellInfo : mSpellInfoMap)
    {
        // AuraState depends on SpellSpecific
        const_cast<SpellInfo&>(spellInfo)._LoadSpellSpecific();
        const_cast<SpellInfo&>(spellInfo)._LoadAuraState();
    }

    TC_LOG_INFO("server.loading", ">> Loaded SpellInfo SpellSpecific and AuraState in {} ms", GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellInfoDiminishing()
{
    uint32 oldMSTime = getMSTime();

    for (SpellInfo const& spellInfo : mSpellInfoMap)
        const_cast<SpellInfo&>(spellInfo)._LoadSpellDiminishInfo();

    TC_LOG_INFO("server.loading", ">> Loaded SpellInfo diminishing infos in {} ms", GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellInfoImmunities()
{
    uint32 oldMSTime = getMSTime();

    mCreatureImmunities.clear();

    //                                                   0   1           2               3              4        5      6          7
    if (QueryResult result = WorldDatabase.Query("SELECT ID, SchoolMask, DispelTypeMask, MechanicsMask, Effects, Auras, ImmuneAoE, ImmuneChain FROM creature_immunities"))
    {
        do
        {
            Field* fields = result->Fetch();
            int32 id = fields[0].GetInt32();
            uint8 school = fields[1].GetInt8();
            uint16 dispelType = fields[2].GetInt16();
            uint64 mechanics = fields[3].GetInt64();

            CreatureImmunities& immunities = mCreatureImmunities[id];
            immunities.School = school;
            immunities.DispelType = dispelType;
            immunities.Mechanic = mechanics;
            if (fields[6].GetBool())
                immunities.Other |= SpellOtherImmunity::AoETarget;
            if (fields[7].GetBool())
                immunities.Other |= SpellOtherImmunity::ChainTarget;

            if (immunities.School.to_ullong() != school)
                TC_LOG_ERROR("sql.sql", "Invalid value in `SchoolMask` {} for creature immunities {}, truncated", school, id);
            if (immunities.DispelType.to_ullong() != dispelType)
                TC_LOG_ERROR("sql.sql", "Invalid value in `DispelTypeMask` {} for creature immunities {}, truncated", dispelType, id);
            if (immunities.Mechanic.to_ullong() != mechanics)
                TC_LOG_ERROR("sql.sql", "Invalid value in `MechanicsMask` {} for creature immunities {}, truncated", mechanics, id);

            for (std::string_view token : Trinity::Tokenize(fields[4].GetStringView(), ',', false))
            {
                if (Optional<uint32> effect = Trinity::StringTo<uint32>(token); effect && effect < uint32(TOTAL_SPELL_EFFECTS))
                    immunities.Effect.push_back(SpellEffectName(*effect));
                else
                    TC_LOG_ERROR("sql.sql", "Invalid effect type in `Effects` {} for creature immunities {}, skipped", token, id);
            }

            for (std::string_view token : Trinity::Tokenize(fields[5].GetStringView(), ',', false))
            {
                if (Optional<uint32> aura = Trinity::StringTo<uint32>(token); aura && aura < TOTAL_AURAS)
                    immunities.Aura.push_back(AuraType(*aura));
                else
                    TC_LOG_ERROR("sql.sql", "Invalid aura type in `Auras` {} for creature immunities {}, skipped", token, id);
            }
        }
        while (result->NextRow());
    }

    for (SpellInfo const& spellInfo : mSpellInfoMap)
        const_cast<SpellInfo&>(spellInfo)._LoadImmunityInfo();

    TC_LOG_INFO("server.loading", ">> Loaded SpellInfo immunity infos in {} ms", GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadPetFamilySpellsStore()
{
    std::unordered_map<uint32, SpellLevelsEntry const*> levelsBySpell;
    for (SpellLevelsEntry const* levels : sSpellLevelsStore)
        if (!levels->DifficultyID)
            levelsBySpell[levels->SpellID] = levels;

    for (SkillLineAbilityEntry const* skillLine : sSkillLineAbilityStore)
    {
        SpellInfo const* spellInfo = GetSpellInfo(skillLine->Spell, DIFFICULTY_NONE);
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

        SpellInfo const* spellEntry = GetSpellInfo(spellId, DIFFICULTY_NONE);
        if (!spellEntry)
        {
            TC_LOG_ERROR("sql.sql", "SpellID: {} in `spell_totem_model` table could not be found in dbc, skipped.", spellId);
            continue;
        }

        ChrRacesEntry const* raceEntry = sChrRacesStore.LookupEntry(race);
        if (!raceEntry)
        {
            TC_LOG_ERROR("sql.sql", "Race {} defined in `spell_totem_model` does not exists, skipped.", uint32(race));
            continue;
        }

        CreatureDisplayInfoEntry const* displayEntry = sCreatureDisplayInfoStore.LookupEntry(displayId);
        if (!displayEntry)
        {
            TC_LOG_ERROR("sql.sql", "SpellID: {} defined in `spell_totem_model` has non-existing model ({}).", spellId, displayId);
            continue;
        }

        mSpellTotemModel[std::make_pair(spellId, race)] = displayId;
        ++count;

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} spell totem model records in {} ms", count, GetMSTimeDiffToNow(oldMSTime));

}

uint32 SpellMgr::GetModelForTotem(uint32 spellId, uint8 race) const
{
    auto itr = mSpellTotemModel.find(std::make_pair(spellId, race));
    if (itr != mSpellTotemModel.end())
        return itr->second;

    return 0;
}
