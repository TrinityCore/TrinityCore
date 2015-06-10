/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include "ObjectMgr.h"
#include "SpellAuras.h"
#include "SpellAuraDefines.h"
#include "SharedDefines.h"
#include "DBCStores.h"
#include "World.h"
#include "Chat.h"
#include "Spell.h"
#include "BattlegroundMgr.h"
#include "MapManager.h"
#include "BattlefieldWG.h"
#include "BattlefieldMgr.h"
#include "Player.h"

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
        if (itr->second->SkillLine == skillId)
            return true;

    return false;
}

DiminishingGroup GetDiminishingReturnsGroupForSpell(SpellInfo const* spellproto)
{
    if (spellproto->IsPositive())
        return DIMINISHING_NONE;

    for (SpellEffectInfo const* effect: spellproto->GetEffectsForDifficulty(DIFFICULTY_NONE))
    {
        if (effect && effect->ApplyAuraName == SPELL_AURA_MOD_TAUNT)
            return DIMINISHING_TAUNT;
    }

    // Explicit Diminishing Groups
    switch (spellproto->SpellFamilyName)
    {
        case SPELLFAMILY_GENERIC:
        {
            // Entrapment -- 135373
            if (spellproto->SpellIconID == 20 && spellproto->SpellVisual[0] == 39588)
                return DIMINISHING_ROOT;

            // Intimidation -- 24394
            if (spellproto->SpellIconID == 166 && spellproto->SpellVisual[0] == 2816)
                return DIMINISHING_STUN;
            // Pulverize (Primal Earth Elemental) -- 118345
            if (spellproto->SpellIconID == 4507 && spellproto->SpellVisual[0] == 39877)
                return DIMINISHING_STUN;
            // Static Charge (Capacitor Totem) -- 118905
            if (spellproto->SpellIconID == 54 && spellproto->SpellVisual[0] == 24442)
                return DIMINISHING_STUN;
            // Remorseless Winter -- 115001
            if (spellproto->SpellIconID == 5744 && spellproto->SpellVisual[0] == 23514)
                return DIMINISHING_STUN;

            // Gorefiend's Grasp -- 108199
            if (spellproto->SpellIconID == 5743 && spellproto->SpellVisual[0] == 28937)
                return DIMINISHING_AOE_KNOCKBACK;
            break;
        }
        case SPELLFAMILY_MAGE:
        {
            // Frostjaw -- 102051
            if (spellproto->SpellFamilyFlags[2] & 0x40000)
                return DIMINISHING_SILENCE;

            // Frost Nova -- 122
            if (spellproto->SpellFamilyFlags[0] & 0x40)
                return DIMINISHING_ROOT;
            // Ice Ward -- 111340
            if (spellproto->SpellFamilyFlags[0] & 0x80000 && spellproto->SpellFamilyFlags[2] & 0x2000)
                return DIMINISHING_ROOT;
            // Freeze (Water Elemental) -- 33395
            if (spellproto->SpellFamilyFlags[2] & 0x200)
                return DIMINISHING_ROOT;

            // Deep Freeze -- 44572
            if (spellproto->SpellFamilyFlags[1] & 0x100000)
                return DIMINISHING_STUN;

            // Dragon's Breath -- 31661
            if (spellproto->SpellFamilyFlags[0] & 0x800000)
                return DIMINISHING_INCAPACITATE;
            // Polymorph -- 118
            if (spellproto->SpellFamilyFlags[0] & 0x1000000)
                return DIMINISHING_INCAPACITATE;
            // Ring of Frost -- 82691
            if (spellproto->SpellFamilyFlags[2] & 0x40)
                return DIMINISHING_INCAPACITATE;
            // Ice Nova -- 157997
            if (spellproto->SpellFamilyFlags[2] & 0x800000)
                return DIMINISHING_INCAPACITATE;
            break;
        }
        case SPELLFAMILY_WARRIOR:
        {
            // Shockwave -- 132168
            if (spellproto->SpellFamilyFlags[1] & 0x8000)
                return DIMINISHING_STUN;
            // Storm Bolt -- 132169
            if (spellproto->SpellFamilyFlags[2] & 0x1000)
                return DIMINISHING_STUN;

            // Intimidating Shout -- 5246
            if (spellproto->SpellFamilyFlags[0] & 0x40000)
                return DIMINISHING_DISORIENT;

            // Hamstring -- 1715, 8 seconds in PvP (6.0)
            if (spellproto->SpellFamilyFlags[0] & 0x2)
                return DIMINISHING_LIMITONLY;
            break;
        }
        case SPELLFAMILY_WARLOCK:
        {
            // Mortal Coil -- 6789
            if (spellproto->SpellFamilyFlags[0] & 0x80000)
                return DIMINISHING_INCAPACITATE;
            // Banish -- 710
            if (spellproto->SpellFamilyFlags[1] & 0x8000000)
                return DIMINISHING_INCAPACITATE;
            // Blood Horror -- 137143, no flags (17986)
            if (spellproto->SpellIconID == 6447 && spellproto->SpellVisual[0] == 26758)
                return DIMINISHING_INCAPACITATE;

            // Fear -- 118699
            if (spellproto->SpellFamilyFlags[1] & 0x400)
                return DIMINISHING_DISORIENT;
            // Howl of Terror -- 5484
            if (spellproto->SpellFamilyFlags[1] & 0x8)
                return DIMINISHING_DISORIENT;

            // Shadowfury -- 30283
            if (spellproto->SpellFamilyFlags[1] & 0x1000)
                return DIMINISHING_STUN;
            // Summon Infernal -- 22703
            if (spellproto->SpellFamilyFlags[0] & 0x1000)
                return DIMINISHING_STUN;
            break;
        }
        case SPELLFAMILY_WARLOCK_PET:
        {
            // Fellash -- 115770
            // Whiplash -- 6360
            if (spellproto->SpellFamilyFlags[0] & 0x8000000)
                return DIMINISHING_AOE_KNOCKBACK;

            // Mesmerize (Shivarra pet) -- 115268
            // Seduction (Succubus pet) -- 6358
            if (spellproto->SpellFamilyFlags[0] & 0x2000000)
                return DIMINISHING_DISORIENT;

            // Axe Toss (Felguard pet) -- 89766
            if (spellproto->SpellFamilyFlags[1] & 0x4)
                return DIMINISHING_STUN;
            break;
        }
        case SPELLFAMILY_DRUID:
        {
            // Maim -- 22570
            if (spellproto->SpellFamilyFlags[1] & 0x80)
                return DIMINISHING_STUN;
            // Mighty Bash -- 5211
            if (spellproto->SpellFamilyFlags[0] & 0x2000)
                return DIMINISHING_STUN;
            // Rake -- 163505 -- no flags on the stun, 20490
            if (spellproto->SpellIconID == 494 && spellproto->SpellVisual[0] == 38283)
                return DIMINISHING_STUN;

            // Incapacitating Roar -- 99, no flags on the stun, 14
            if (spellproto->SpellIconID == 960 && spellproto->SpellVisual[0] == 38528)
                return DIMINISHING_INCAPACITATE;

            // Cyclone -- 33786
            if (spellproto->SpellFamilyFlags[1] & 0x20)
                return DIMINISHING_DISORIENT;

            // Glyph of Fae Silence -- 114238, no flags on the silence, 15035
            if (spellproto->SpellIconID == 957 && spellproto->SchoolMask == 8)
                return DIMINISHING_SILENCE;

            // Typhoon -- 61391
            if (spellproto->SpellFamilyFlags[1] & 0x1000000)
                return DIMINISHING_AOE_KNOCKBACK;
            // Ursol's Vortex -- 127797, no flags on the effect, 16921
            if (spellproto->SpellIconID == 5784 && spellproto->SchoolMask == 8)
                return DIMINISHING_AOE_KNOCKBACK;

            // Entangling Roots -- 339
            if (spellproto->SpellFamilyFlags[0] & 0x200)
                return DIMINISHING_ROOT;
            // Mass Entanglement -- 102359, no flags on the root, 13535
            if (spellproto->SpellIconID == 5782 && spellproto->SpellVisual[0] == 38269)
                return DIMINISHING_ROOT;

            // Faerie Fire -- 770, 20 seconds in PvP (6.0)
            if (spellproto->SpellFamilyFlags[0] & 0x400)
                return DIMINISHING_LIMITONLY;
            break;
        }
        case SPELLFAMILY_ROGUE:
        {
            // Cheap Shot -- 1833
            if (spellproto->SpellFamilyFlags[0] & 0x400)
                return DIMINISHING_STUN;
            // Kidney Shot -- 408
            if (spellproto->SpellFamilyFlags[0] & 0x200000)
                return DIMINISHING_STUN;

            // Gouge -- 1776
            if (spellproto->SpellFamilyFlags[0] & 0x8)
                return DIMINISHING_INCAPACITATE;
            // Sap -- 6770
            if (spellproto->SpellFamilyFlags[0] & 0x80)
                return DIMINISHING_INCAPACITATE;

            // Blind -- 2094
            if (spellproto->SpellFamilyFlags[0] & 0x1000000)
                return DIMINISHING_DISORIENT;

            // Garrote -- 1330
            if (spellproto->SpellFamilyFlags[1] & 0x20000000)
                return DIMINISHING_SILENCE;
            break;
        }
        case SPELLFAMILY_HUNTER:
        {
            // Glyph of Explosive Trap -- 149575 maybe? @todo
                // return DIMINISHING_AOE_KNOCKBACK;

            // Charge (Tenacity pet) -- 53148, no flags (5526)
            if (spellproto->SpellIconID == 1559 && spellproto->SpellVisual[0] == 39480)
                return DIMINISHING_ROOT;
            // Narrow Escape -- 136634, no flags (17964)
            if (spellproto->SpellIconID == 3342 && spellproto->SchoolMask == 8)
                return DIMINISHING_ROOT;

            // Binding Shot -- 117526, no flags (15581)
            if (spellproto->SpellIconID == 4612 && spellproto->SpellVisual[0] == 6859)
                return DIMINISHING_STUN;

            // Freezing Trap -- 3355
            if (spellproto->SpellFamilyFlags[0] & 0x8)
                return DIMINISHING_INCAPACITATE;
            // Wyvern Sting -- 19386
            if (spellproto->SpellFamilyFlags[1] & 0x1000)
                return DIMINISHING_INCAPACITATE;
            break;
        }
        case SPELLFAMILY_PALADIN:
        {
            // Repentance -- 20066
            if (spellproto->SpellFamilyFlags[0] & 0x4)
                return DIMINISHING_INCAPACITATE;

            // Turn Evil -- 10326
            if (spellproto->SpellFamilyFlags[1] & 0x800000)
                return DIMINISHING_DISORIENT;

            // Avenger's Shield -- 31935
            if (spellproto->SpellFamilyFlags[0] & 0x4000)
                return DIMINISHING_SILENCE;

            // Fist of Justice -- 105593
            // Hammer of Justice -- 853
            if (spellproto->SpellFamilyFlags[0] & 0x800)
                return DIMINISHING_STUN;
            // Holy Wrath -- 119072
            if (spellproto->SpellFamilyFlags[1] & 0x200000)
                return DIMINISHING_STUN;
            break;
        }
        case SPELLFAMILY_SHAMAN:
        {
            // Hex -- 51514
            if (spellproto->SpellFamilyFlags[1] & 0x8000)
                return DIMINISHING_INCAPACITATE;

            // Thunderstorm -- 51490
            if (spellproto->SpellFamilyFlags[1] & 0x2000)
                return DIMINISHING_AOE_KNOCKBACK;
            // Earthgrab Totem -- 64695
            if (spellproto->SpellFamilyFlags[2] & 0x4000)
                return DIMINISHING_ROOT;
            // Frost Shock (with Frozen Power) -- 63685, no flags (6918)
            if (spellproto->SpellIconID == 193 && spellproto->SpellVisual[0] == 39876)
                return DIMINISHING_ROOT;
            break;
        }
        case SPELLFAMILY_DEATHKNIGHT:
        {
            // Strangulate -- 47476
            if (spellproto->SpellFamilyFlags[0] & 0x200)
                return DIMINISHING_SILENCE;

            // Chains of Ice (with Chilblains) -- 96294, no flags (13020)
            if (spellproto->SpellIconID == 180 && spellproto->SpellVisual[0] == 20135)
                return DIMINISHING_ROOT;

            // Asphyxiate -- 108194
            if (spellproto->SpellFamilyFlags[2] & 0x100000)
                return DIMINISHING_STUN;
            // Gnaw (Ghoul) -- 91800, no flags (12511)
            if (spellproto->SpellIconID == 3010 && spellproto->SpellVisual[0] == 38760)
                return DIMINISHING_STUN;
            // Monstrous Blow (Ghoul w/ Dark Transformation active) -- 91797, no flags (12510)
            if (spellproto->SpellIconID == 15 && spellproto->SpellVisual[0] == 38761)
                return DIMINISHING_STUN;
            break;
        }
        case SPELLFAMILY_PRIEST:
        {
            // Glyph of Mind Blast -- 87194, no flags (10092)
            if (spellproto->SpellIconID == 2114 && spellproto->SpellVisual[0] == 38927)
                return DIMINISHING_ROOT;
            // Void Tendrils -- 114404, no flags (15067)
            if (spellproto->SpellIconID == 5816 && spellproto->SpellVisual[0] == 25199)
                return DIMINISHING_ROOT;

            // Dominate Mind -- 605
            if (spellproto->SpellFamilyFlags[0] & 0x20000 && spellproto->SpellVisual[0] == 39068)
                return DIMINISHING_INCAPACITATE;
            // Holy Word: Chastise -- 88625
            if (spellproto->SpellFamilyFlags[2] & 0x20)
                return DIMINISHING_INCAPACITATE;
            // Psychic Horror -- 64044
            if (spellproto->SpellFamilyFlags[2] & 0x2000)
                return DIMINISHING_INCAPACITATE;

            // Psychic Scream -- 8122
            if (spellproto->SpellFamilyFlags[0] & 0x10000)
                return DIMINISHING_DISORIENT;

            // Silence -- 15487
            if (spellproto->SpellFamilyFlags[1] & 0x200000 && spellproto->SchoolMask == 32)
                return DIMINISHING_SILENCE;
            break;
        }
        case SPELLFAMILY_MONK:
        {
            // Disable -- 116706, no flags (15483)
            if (spellproto->SpellIconID == 23 && spellproto->SpellVisual[0] == 39984)
                return DIMINISHING_ROOT;

            // Charging Ox Wave -- 119392
            if (spellproto->SpellFamilyFlags[1] & 0x10000)
                return DIMINISHING_STUN;
            // Fists of Fury -- 120086
            if (spellproto->SpellFamilyFlags[1] & 0x800000 && !(spellproto->SpellFamilyFlags[2] & 0x8))
                return DIMINISHING_STUN;
            // Leg Sweep -- 119381
            if (spellproto->SpellFamilyFlags[1] & 0x200)
                return DIMINISHING_STUN;

            // Glyph of Breath of Fire -- 123393, no flags (16504)
            if (spellproto->SpellIconID == 15 && spellproto->SpellVisual[0] == 25408)
                return DIMINISHING_INCAPACITATE;
            // Paralysis -- 115078
            if (spellproto->SpellFamilyFlags[2] & 0x800000)
                return DIMINISHING_INCAPACITATE;
            // Ring of Peace -- 137460, no flags (18006)
            if (spellproto->SpellIconID == 7195 && spellproto->SpellVisual[0] == 39999)
                return DIMINISHING_INCAPACITATE;
            break;
        }
        default:
            break;
    }

    return DIMINISHING_NONE;
}

DiminishingReturnsType GetDiminishingReturnsGroupType(DiminishingGroup group)
{
    switch (group)
    {
        case DIMINISHING_TAUNT:
        case DIMINISHING_STUN:
            return DRTYPE_ALL;
        case DIMINISHING_LIMITONLY:
        case DIMINISHING_NONE:
            return DRTYPE_NONE;
        default:
            return DRTYPE_PLAYER;
    }
}

DiminishingLevels GetDiminishingReturnsMaxLevel(DiminishingGroup group)
{
    switch (group)
    {
        case DIMINISHING_TAUNT:
            return DIMINISHING_LEVEL_TAUNT_IMMUNE;
        case DIMINISHING_AOE_KNOCKBACK:
            return DIMINISHING_LEVEL_2;
        default:
            return DIMINISHING_LEVEL_IMMUNE;
    }
}

int32 GetDiminishingReturnsLimitDuration(SpellInfo const* spellproto)
{
    // Explicit diminishing duration
    switch (spellproto->SpellFamilyName)
    {
        case SPELLFAMILY_DRUID:
        {
            // Faerie Fire - 20 seconds in PvP (6.0)
            if (spellproto->SpellFamilyFlags[0] & 0x400)
                return 20 * IN_MILLISECONDS;
            break;
        }
        case SPELLFAMILY_HUNTER:
        {
            // Binding Shot - 3 seconds in PvP (6.0)
            if (spellproto->SpellIconID == 4612 && spellproto->SpellVisual[0] == 6859)
                return 3 * IN_MILLISECONDS;
            // Wyvern Sting - 6 seconds in PvP (6.0)
            if (spellproto->SpellFamilyFlags[1] & 0x1000)
                return 6 * IN_MILLISECONDS;
            break;
        }
        case SPELLFAMILY_MONK:
        {
            // Paralysis - 4 seconds in PvP regardless of if they are facing you (6.0)
            if (spellproto->SpellFamilyFlags[2] & 0x800000)
                return 4 * IN_MILLISECONDS;
            break;
        }
        default:
            break;
    }

    return 8 * IN_MILLISECONDS;
}

SpellMgr::SpellMgr() { }

SpellMgr::~SpellMgr()
{
    UnloadSpellInfoStore();
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
            case SPELL_EFFECT_CREATE_ITEM_2:
            {
                                               if (effect->ItemType == 0)
                {
                    // skip auto-loot crafting spells, its not need explicit item info (but have special fake items sometime)
                    if (!spellInfo->IsLootCrafting())
                    {
                        if (msg)
                        {
                            if (player)
                                ChatHandler(player->GetSession()).PSendSysMessage("Craft spell %u not have create item entry.", spellInfo->Id);
                            else
                                TC_LOG_ERROR("sql.sql", "Craft spell %u not have create item entry.", spellInfo->Id);
                        }
                        return false;
                    }

                }
                // also possible IsLootCrafting case but fake item must exist anyway
                else if (!sObjectMgr->GetItemTemplate(effect->ItemType))
                {
                    if (msg)
                    {
                        if (player)
                            ChatHandler(player->GetSession()).PSendSysMessage("Craft spell %u create not-exist in DB item (Entry: %u) and then...", spellInfo->Id, effect->ItemType);
                        else
                            TC_LOG_ERROR("sql.sql", "Craft spell %u create not-exist in DB item (Entry: %u) and then...", spellInfo->Id, effect->ItemType);
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
                        ChatHandler(player->GetSession()).PSendSysMessage("Craft spell %u have not-exist reagent in DB item (Entry: %u) and then...", spellInfo->Id, spellInfo->Reagent[j]);
                    else
                        TC_LOG_ERROR("sql.sql", "Craft spell %u have not-exist reagent in DB item (Entry: %u) and then...", spellInfo->Id, spellInfo->Reagent[j]);
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

SpellProcEventEntry const* SpellMgr::GetSpellProcEvent(uint32 spellId) const
{
    SpellProcEventMap::const_iterator itr = mSpellProcEventMap.find(spellId);
    if (itr != mSpellProcEventMap.end())
        return &itr->second;
    return NULL;
}

bool SpellMgr::IsSpellProcEventCanTriggeredBy(SpellInfo const* spellProto, SpellProcEventEntry const* spellProcEvent, uint32 EventProcFlag, SpellInfo const* procSpell, uint32 procFlags, uint32 procExtra, bool active) const
{
    // No extra req need
    uint32 procEvent_procEx = PROC_EX_NONE;

    // check prockFlags for condition
    if ((procFlags & EventProcFlag) == 0)
        return false;

    bool hasFamilyMask = false;

    /**

    * @brief Check auras procced by periodics

    *Only damaging Dots can proc auras with PROC_FLAG_TAKEN_DAMAGE

    *Only Dots can proc if ONLY has PROC_FLAG_DONE_PERIODIC or PROC_FLAG_TAKEN_PERIODIC.

    *Hots can proc if ONLY has PROC_FLAG_DONE_PERIODIC and spellfamily != 0

    *Only Dots can proc auras with PROC_FLAG_DONE_SPELL_MAGIC_DMG_CLASS_NEG or PROC_FLAG_DONE_SPELL_NONE_DMG_CLASS_NEG

    *Only Hots can proc auras with PROC_FLAG_DONE_SPELL_MAGIC_DMG_CLASS_POS or PROC_FLAG_DONE_SPELL_NONE_DMG_CLASS_POS

    *Only Dots can proc auras with PROC_FLAG_TAKEN_SPELL_MAGIC_DMG_CLASS_NEG or PROC_FLAG_TAKEN_SPELL_NONE_DMG_CLASS_NEG

    *Only Hots can proc auras with PROC_FLAG_TAKEN_SPELL_MAGIC_DMG_CLASS_POS or PROC_FLAG_TAKEN_SPELL_NONE_DMG_CLASS_POS

    * @param procSpell the spell proccing the aura
    * @param procFlags proc_flags of spellProc
    * @param procExtra proc_EX of procSpell
    * @param EventProcFlag proc_flags of aura to be procced
    * @param spellProto SpellInfo of aura to be procced

    */

    /// Quick Check - If PROC_FLAG_TAKEN_DAMAGE is set for aura and procSpell dealt damage, proc no matter what kind of spell that deals the damage.
    if (procFlags & PROC_FLAG_TAKEN_DAMAGE && EventProcFlag & PROC_FLAG_TAKEN_DAMAGE)
        return true;

    if (procFlags & PROC_FLAG_DONE_PERIODIC && EventProcFlag & PROC_FLAG_DONE_PERIODIC)
    {
        if (procExtra & PROC_EX_INTERNAL_HOT)
        {
            if (EventProcFlag == PROC_FLAG_DONE_PERIODIC)
            {
                /// no aura with only PROC_FLAG_DONE_PERIODIC and spellFamilyName == 0 can proc from a HOT.
                if (!spellProto->SpellFamilyName)
                    return false;
            }
            /// Aura must have positive procflags for a HOT to proc
            else if (!(EventProcFlag & (PROC_FLAG_DONE_SPELL_MAGIC_DMG_CLASS_POS | PROC_FLAG_DONE_SPELL_NONE_DMG_CLASS_POS)))
                return false;
        }
        /// Aura must have negative or neutral(PROC_FLAG_DONE_PERIODIC only) procflags for a DOT to proc
        else if (EventProcFlag != PROC_FLAG_DONE_PERIODIC)
            if (!(EventProcFlag & (PROC_FLAG_DONE_SPELL_MAGIC_DMG_CLASS_NEG | PROC_FLAG_DONE_SPELL_NONE_DMG_CLASS_NEG)))
                return false;
    }

    if (procFlags & PROC_FLAG_TAKEN_PERIODIC && EventProcFlag & PROC_FLAG_TAKEN_PERIODIC)
    {
        if (procExtra & PROC_EX_INTERNAL_HOT)
        {
            /// No aura that only has PROC_FLAG_TAKEN_PERIODIC can proc from a HOT.
            if (EventProcFlag == PROC_FLAG_TAKEN_PERIODIC)
                return false;
            /// Aura must have positive procflags for a HOT to proc
            if (!(EventProcFlag & (PROC_FLAG_TAKEN_SPELL_MAGIC_DMG_CLASS_POS | PROC_FLAG_TAKEN_SPELL_NONE_DMG_CLASS_POS)))
                return false;
        }
        /// Aura must have negative or neutral(PROC_FLAG_TAKEN_PERIODIC only) procflags for a DOT to proc
        else if (EventProcFlag != PROC_FLAG_TAKEN_PERIODIC)
            if (!(EventProcFlag & (PROC_FLAG_TAKEN_SPELL_MAGIC_DMG_CLASS_NEG | PROC_FLAG_TAKEN_SPELL_NONE_DMG_CLASS_NEG)))
                return false;
    }
    // Trap casts are active by default
    if (procFlags & PROC_FLAG_DONE_TRAP_ACTIVATION)
        active = true;

    // Always trigger for this
    if (procFlags & (PROC_FLAG_KILLED | PROC_FLAG_KILL | PROC_FLAG_DEATH))
        return true;

    if (spellProcEvent)     // Exist event data
    {
        // Store extra req
        procEvent_procEx = spellProcEvent->procEx;

        // For melee triggers
        if (procSpell == NULL)
        {
            // Check (if set) for school (melee attack have Normal school)
            if (spellProcEvent->schoolMask && (spellProcEvent->schoolMask & SPELL_SCHOOL_MASK_NORMAL) == 0)
                return false;
        }
        else // For spells need check school/spell family/family mask
        {
            // Check (if set) for school
            if (spellProcEvent->schoolMask && (spellProcEvent->schoolMask & procSpell->SchoolMask) == 0)
                return false;

            // Check (if set) for spellFamilyName
            if (spellProcEvent->spellFamilyName && (spellProcEvent->spellFamilyName != procSpell->SpellFamilyName))
                return false;

            // spellFamilyName is Ok need check for spellFamilyMask if present
            if (spellProcEvent->spellFamilyMask)
            {
                if (!(spellProcEvent->spellFamilyMask & procSpell->SpellFamilyFlags))
                    return false;
                hasFamilyMask = true;
                // Some spells are not considered as active even with have spellfamilyflags
                if (!(procEvent_procEx & PROC_EX_ONLY_ACTIVE_SPELL))
                    active = true;
            }
        }
    }

    if (procExtra & (PROC_EX_INTERNAL_REQ_FAMILY))
    {
        if (!hasFamilyMask)
            return false;
    }

    // Check for extra req (if none) and hit/crit
    if (procEvent_procEx == PROC_EX_NONE)
    {
        // No extra req, so can trigger only for hit/crit - spell has to be active
        if ((procExtra & (PROC_EX_NORMAL_HIT|PROC_EX_CRITICAL_HIT)) && active)
            return true;
    }
    else // Passive spells hits here only if resist/reflect/immune/evade
    {
        if (procExtra & AURA_SPELL_PROC_EX_MASK)
        {
            // if spell marked as procing only from not active spells
            if (active && procEvent_procEx & PROC_EX_NOT_ACTIVE_SPELL)
                return false;
            // if spell marked as procing only from active spells
            if (!active && procEvent_procEx & PROC_EX_ONLY_ACTIVE_SPELL)
                return false;
            // Exist req for PROC_EX_EX_TRIGGER_ALWAYS
            if (procEvent_procEx & PROC_EX_EX_TRIGGER_ALWAYS)
                return true;
            // PROC_EX_NOT_ACTIVE_SPELL and PROC_EX_ONLY_ACTIVE_SPELL flags handle: if passed checks before
            if ((procExtra & (PROC_EX_NORMAL_HIT|PROC_EX_CRITICAL_HIT)) && ((procEvent_procEx & (AURA_SPELL_PROC_EX_MASK)) == 0))
                return true;
        }
        // Check Extra Requirement like (hit/crit/miss/resist/parry/dodge/block/immune/reflect/absorb and other)
        if (procEvent_procEx & procExtra)
            return true;
    }
    return false;
}

SpellProcEntry const* SpellMgr::GetSpellProcEntry(uint32 spellId) const
{
    SpellProcMap::const_iterator itr = mSpellProcMap.find(spellId);
    if (itr != mSpellProcMap.end())
        return &itr->second;
    return NULL;
}

bool SpellMgr::CanSpellTriggerProcOnEvent(SpellProcEntry const& procEntry, ProcEventInfo& eventInfo) const
{
    // proc type doesn't match
    if (!(eventInfo.GetTypeMask() & procEntry.typeMask))
        return false;

    // check XP or honor target requirement
    if (procEntry.attributesMask & PROC_ATTR_REQ_EXP_OR_HONOR)
        if (Player* actor = eventInfo.GetActor()->ToPlayer())
            if (eventInfo.GetActionTarget() && !actor->isHonorOrXPTarget(eventInfo.GetActionTarget()))
                return false;

    // always trigger for these types
    if (eventInfo.GetTypeMask() & (PROC_FLAG_KILLED | PROC_FLAG_KILL | PROC_FLAG_DEATH))
        return true;

    // check school mask (if set) for other trigger types
    if (procEntry.schoolMask && !(eventInfo.GetSchoolMask() & procEntry.schoolMask))
        return false;

    // check spell family name/flags (if set) for spells
    if (eventInfo.GetTypeMask() & (PERIODIC_PROC_FLAG_MASK | SPELL_PROC_FLAG_MASK | PROC_FLAG_DONE_TRAP_ACTIVATION))
    {
        if (procEntry.spellFamilyName && eventInfo.GetSpellInfo() && (procEntry.spellFamilyName != eventInfo.GetSpellInfo()->SpellFamilyName))
            return false;

        if (procEntry.spellFamilyMask && eventInfo.GetSpellInfo() && !(procEntry.spellFamilyMask & eventInfo.GetSpellInfo()->SpellFamilyFlags))
            return false;
    }

    // check spell type mask (if set)
    if (eventInfo.GetTypeMask() & (SPELL_PROC_FLAG_MASK | PERIODIC_PROC_FLAG_MASK))
    {
        if (procEntry.spellTypeMask && !(eventInfo.GetSpellTypeMask() & procEntry.spellTypeMask))
            return false;
    }

    // check spell phase mask
    if (eventInfo.GetTypeMask() & REQ_SPELL_PHASE_PROC_FLAG_MASK)
    {
        if (!(eventInfo.GetSpellPhaseMask() & procEntry.spellPhaseMask))
            return false;
    }

    // check hit mask (on taken hit or on done hit, but not on spell cast phase)
    if ((eventInfo.GetTypeMask() & TAKEN_HIT_PROC_FLAG_MASK) || ((eventInfo.GetTypeMask() & DONE_HIT_PROC_FLAG_MASK) && !(eventInfo.GetSpellPhaseMask() & PROC_SPELL_PHASE_CAST)))
    {
        uint32 hitMask = procEntry.hitMask;
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

bool SpellArea::IsFitToRequirements(Player const* player, uint32 newZone, uint32 newArea) const
{
    if (gender != GENDER_NONE)                   // not in expected gender
        if (!player || gender != player->getGender())
            return false;

    if (raceMask)                                // not in expected race
        if (!player || !(raceMask & player->getRaceMask()))
            return false;

    if (areaId)                                  // not in expected zone
        if (newZone != areaId && newArea != areaId)
            return false;

    if (questStart)                              // not in expected required quest state
        if (!player || (((1 << player->GetQuestStatus(questStart)) & questStartStatus) == 0))
            return false;

    if (questEnd)                                // not in expected forbidden quest state
        if (!player || (((1 << player->GetQuestStatus(questEnd)) & questEndStatus) == 0))
            return false;

    if (auraSpell)                               // not have expected aura
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
            TC_LOG_ERROR("sql.sql", "Spell rank identifier(first_spell_id) %u listed in `spell_ranks` does not exist!", lastSpell);
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
                TC_LOG_ERROR("sql.sql", "Spell %u (rank %u) listed in `spell_ranks` for chain %u does not exist!", itr->first, itr->second, lastSpell);
                valid = false;
                break;
            }
            ++curRank;
            if (itr->second != curRank)
            {
                TC_LOG_ERROR("sql.sql", "Spell %u (rank %u) listed in `spell_ranks` for chain %u does not have proper rank value(should be %u)!", itr->first, itr->second, lastSpell, curRank);
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
                TC_LOG_ERROR("sql.sql", "Spell %u (rank: %u, first: %u) listed in `spell_ranks` has already ChainEntry from dbc.", addedSpell, itr->second, lastSpell);

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
            TC_LOG_ERROR("sql.sql", "spell_id %u in `spell_required` table is not found in dbcs, skipped", spell_id);
            continue;
        }

        SpellInfo const* reqSpell = GetSpellInfo(spell_req);
        if (!reqSpell)
        {
            TC_LOG_ERROR("sql.sql", "req_spell %u in `spell_required` table is not found in dbcs, skipped", spell_req);
            continue;
        }

        if (spell->IsRankOf(reqSpell))
        {
            TC_LOG_ERROR("sql.sql", "req_spell %u and spell_id %u in `spell_required` table are ranks of the same spell, entry not needed, skipped", spell_req, spell_id);
            continue;
        }

        if (IsSpellRequiringSpell(spell_id, spell_req))
        {
            TC_LOG_ERROR("sql.sql", "duplicated entry of req_spell %u and spell_id %u in `spell_required`, skipped", spell_req, spell_id);
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
    for (uint32 spell = 0; spell < GetSpellInfoStoreSize(); ++spell)
    {
        SpellInfo const* entry = GetSpellInfo(spell);

        if (!entry)
            continue;

        for (SpellEffectInfo const* effect : entry->GetEffectsForDifficulty(DIFFICULTY_NONE))
        {
            if (effect && effect->Effect == SPELL_EFFECT_SKILL)
            {
                SpellLearnSkillNode dbc_node;
                dbc_node.skill = effect->MiscValue;
                dbc_node.step  = effect->CalcValue();
                if (dbc_node.skill != SKILL_RIDING)
                    dbc_node.value = 1;
                else
                    dbc_node.value = dbc_node.step * 75;
                dbc_node.maxvalue = dbc_node.step * 75;
                mSpellLearnSkills[spell] = dbc_node;
                ++dbc_count;
                break;
            }
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
            TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_learn_spell` does not exist", spell_id);
            continue;
        }

        if (!GetSpellInfo(node.Spell))
        {
            TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_learn_spell` learning not existed spell %u", spell_id, node.Spell);
            continue;
        }

        if (spellInfo->HasAttribute(SPELL_ATTR0_CU_IS_TALENT))
        {
            TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_learn_spell` attempt learning talent spell %u, skipped", spell_id, node.Spell);
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
                        TC_LOG_ERROR("sql.sql", "Spell %u auto-learn spell %u in spell.dbc then the record in `spell_learn_spell` is redundant, please fix DB.",
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
            if (itr->second.Spell == spellLearnSpell->SpellID)
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
            if (itr->second.Spell == spellLearnSpell->SpellID)
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

    uint32 mastery_count = 0;
    for (uint32 i = 0; i < sChrSpecializationStore.GetNumRows(); ++i)
    {
        ChrSpecializationEntry const* chrSpec = sChrSpecializationStore.LookupEntry(i);
        if (!chrSpec)
            continue;

        if (chrSpec->ClassID >= MAX_CLASSES)
            continue;

        uint32 masteryMainSpell = MasterySpells[chrSpec->ClassID];

        for (uint32 m = 0; m < MAX_MASTERY_SPELLS; ++m)
        {
            uint32 mastery = chrSpec->MasterySpellID[m];
            if (!mastery)
                continue;

            SpellLearnSpellMapBounds db_node_bounds = dbSpellLearnSpells.equal_range(masteryMainSpell);
            bool found = false;
            for (SpellLearnSpellMap::const_iterator itr = db_node_bounds.first; itr != db_node_bounds.second; ++itr)
            {
                if (itr->second.Spell == mastery)
                {
                    TC_LOG_ERROR("sql.sql", "Found redundant record (entry: %u, SpellID: %u) in `spell_learn_spell`, spell added automatically as mastery learned spell from ChrSpecialization.dbc", masteryMainSpell, mastery);
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
                if (itr->second.Spell == mastery)
                {
                    found = true;
                    break;
                }
            }

            if (found)
                continue;

            SpellLearnSpellNode masteryNode;
            masteryNode.Spell       = mastery;
            masteryNode.OverridesSpell = 0;
            masteryNode.Active      = true;
            masteryNode.AutoLearned = false;

            mSpellLearnSpells.insert(SpellLearnSpellMap::value_type(masteryMainSpell, masteryNode));
            ++mastery_count;
        }
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u spell learn spells, %u found in Spell.dbc and %u from TalentTab.dbc in %u ms", count, dbc_count, mastery_count, GetMSTimeDiffToNow(oldMSTime));
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
            st.target_Orientation = effect->PositionFacing * M_PI / 180;
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
            TC_LOG_ERROR("sql.sql", "Spell (Id: %u, EffectIndex: %u) listed in `spell_target_position` does not have target TARGET_DEST_DB (17).", spellId, effIndex);
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
                TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_group` does not exist", itr->second);
                mSpellGroupSpell.erase(itr++);
            }
            else if (spellInfo->GetRank() > 1)
            {
                TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_group` is not first rank of spell", itr->second);
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
            TC_LOG_ERROR("sql.sql", "SpellGroupStackRule %u listed in `spell_group_stack_rules` does not exist", stack_rule);
            continue;
        }

        SpellGroupSpellMapBounds spellGroup = GetSpellGroupSpellMapBounds((SpellGroup)group_id);

        if (spellGroup.first == spellGroup.second)
        {
            TC_LOG_ERROR("sql.sql", "SpellGroup id %u listed in `spell_group_stack_rules` does not exist", group_id);
            continue;
        }

        mSpellGroupStack[(SpellGroup)group_id] = (SpellGroupStackRule)stack_rule;

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u spell group stack rules in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellProcEvents()
{
    uint32 oldMSTime = getMSTime();

    mSpellProcEventMap.clear();                             // need for reload case

    //                                                0      1           2                3                 4                 5                 6                 7          8       9        10            11
    QueryResult result = WorldDatabase.Query("SELECT entry, SchoolMask, SpellFamilyName, SpellFamilyMask0, SpellFamilyMask1, SpellFamilyMask2, SpellFamilyMask3, procFlags, procEx, ppmRate, CustomChance, Cooldown FROM spell_proc_event");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 spell proc event conditions. DB table `spell_proc_event` is empty.");
        return;
    }

    uint32 count = 0;

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
            TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_proc_event` does not exist", spellId);
            continue;
        }

        if (allRanks)
        {
            if (!spellInfo->IsRanked())
                TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_proc_event` with all ranks, but spell has no ranks.", spellId);

            if (spellInfo->GetFirstRankSpell()->Id != uint32(spellId))
            {
                TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_proc_event` is not first rank of spell.", spellId);
                continue;
            }
        }

        SpellProcEventEntry spellProcEvent;

        spellProcEvent.schoolMask         = fields[1].GetInt8();
        spellProcEvent.spellFamilyName    = fields[2].GetUInt16();
        spellProcEvent.spellFamilyMask[0] = fields[3].GetUInt32();
        spellProcEvent.spellFamilyMask[1] = fields[4].GetUInt32();
        spellProcEvent.spellFamilyMask[2] = fields[5].GetUInt32();
        spellProcEvent.spellFamilyMask[3] = fields[6].GetUInt32();
        spellProcEvent.procFlags          = fields[7].GetUInt32();
        spellProcEvent.procEx             = fields[8].GetUInt32();
        spellProcEvent.ppmRate            = fields[9].GetFloat();
        spellProcEvent.customChance       = fields[10].GetFloat();
        spellProcEvent.cooldown           = fields[11].GetUInt32();

        while (spellInfo)
        {
            if (mSpellProcEventMap.find(spellInfo->Id) != mSpellProcEventMap.end())
            {
                TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_proc_event` already has its first rank in table.", spellInfo->Id);
                break;
            }

            if (!spellInfo->ProcFlags && !spellProcEvent.procFlags)
                TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_proc_event` probably not triggered spell", spellInfo->Id);

            mSpellProcEventMap[spellInfo->Id] = spellProcEvent;

            if (allRanks)
                spellInfo = spellInfo->GetNextRankSpell();
            else
                break;
        }

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u extra spell proc event conditions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadSpellProcs()
{
    uint32 oldMSTime = getMSTime();

    mSpellProcMap.clear();                             // need for reload case

    //                                                 0        1           2                3                 4                 5                 6                7         8              9               10        11             12             13     14         15
    QueryResult result = WorldDatabase.Query("SELECT spellId, schoolMask, spellFamilyName, spellFamilyMask0, spellFamilyMask1, spellFamilyMask2, spellFamilyMask3, typeMask, spellTypeMask, spellPhaseMask, hitMask, attributesMask, ratePerMinute, chance, cooldown, charges FROM spell_proc");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 spell proc conditions and data. DB table `spell_proc` is empty.");
        return;
    }

    uint32 count = 0;
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
            TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_proc` does not exist", spellId);
            continue;
        }

        if (allRanks)
        {
            if (!spellInfo->IsRanked())
                TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_proc` with all ranks, but spell has no ranks.", spellId);

            if (spellInfo->GetFirstRankSpell()->Id != uint32(spellId))
            {
                TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_proc` is not first rank of spell.", spellId);
                continue;
            }
        }

        SpellProcEntry baseProcEntry;

        baseProcEntry.schoolMask      = fields[1].GetInt8();
        baseProcEntry.spellFamilyName = fields[2].GetUInt16();
        baseProcEntry.spellFamilyMask[0] = fields[3].GetUInt32();
        baseProcEntry.spellFamilyMask[1] = fields[4].GetUInt32();
        baseProcEntry.spellFamilyMask[2] = fields[5].GetUInt32();
        baseProcEntry.spellFamilyMask[3] = fields[6].GetUInt32();
        baseProcEntry.typeMask        = fields[7].GetUInt32();
        baseProcEntry.spellTypeMask   = fields[8].GetUInt32();
        baseProcEntry.spellPhaseMask  = fields[9].GetUInt32();
        baseProcEntry.hitMask         = fields[10].GetUInt32();
        baseProcEntry.attributesMask  = fields[11].GetUInt32();
        baseProcEntry.ratePerMinute   = fields[12].GetFloat();
        baseProcEntry.chance          = fields[13].GetFloat();
        float cooldown                = fields[14].GetFloat();
        baseProcEntry.cooldown        = uint32(cooldown);
        baseProcEntry.charges         = fields[15].GetUInt32();

        while (spellInfo)
        {
            if (mSpellProcMap.find(spellInfo->Id) != mSpellProcMap.end())
            {
                TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_proc` already has its first rank in table.", spellInfo->Id);
                break;
            }

            SpellProcEntry procEntry = SpellProcEntry(baseProcEntry);

            // take defaults from dbcs
            if (!procEntry.typeMask)
                procEntry.typeMask = spellInfo->ProcFlags;
            if (!procEntry.charges)
                procEntry.charges = spellInfo->ProcCharges;
            if (!procEntry.chance && !procEntry.ratePerMinute)
                procEntry.chance = float(spellInfo->ProcChance);

            // validate data
            if (procEntry.schoolMask & ~SPELL_SCHOOL_MASK_ALL)
                TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId %u has wrong `schoolMask` set: %u", spellInfo->Id, procEntry.schoolMask);
            if (procEntry.spellFamilyName && (procEntry.spellFamilyName < 3 || procEntry.spellFamilyName > 17 || procEntry.spellFamilyName == 14 || procEntry.spellFamilyName == 16))
                TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId %u has wrong `spellFamilyName` set: %u", spellInfo->Id, procEntry.spellFamilyName);
            if (procEntry.chance < 0)
            {
                TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId %u has negative value in `chance` field", spellInfo->Id);
                procEntry.chance = 0;
            }
            if (procEntry.ratePerMinute < 0)
            {
                TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId %u has negative value in `ratePerMinute` field", spellInfo->Id);
                procEntry.ratePerMinute = 0;
            }
            if (cooldown < 0)
            {
                TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId %u has negative value in `cooldown` field", spellInfo->Id);
                procEntry.cooldown = 0;
            }
            if (procEntry.chance == 0 && procEntry.ratePerMinute == 0)
                TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId %u doesn't have `chance` and `ratePerMinute` values defined, proc will not be triggered", spellInfo->Id);
            if (procEntry.charges > 99)
            {
                TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId %u has too big value in `charges` field", spellInfo->Id);
                procEntry.charges = 99;
            }
            if (!procEntry.typeMask)
                TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId %u doesn't have `typeMask` value defined, proc will not be triggered", spellInfo->Id);
            if (procEntry.spellTypeMask & ~PROC_SPELL_TYPE_MASK_ALL)
                TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId %u has wrong `spellTypeMask` set: %u", spellInfo->Id, procEntry.spellTypeMask);
            if (procEntry.spellTypeMask && !(procEntry.typeMask & (SPELL_PROC_FLAG_MASK | PERIODIC_PROC_FLAG_MASK)))
                TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId %u has `spellTypeMask` value defined, but it won't be used for defined `typeMask` value", spellInfo->Id);
            if (!procEntry.spellPhaseMask && procEntry.typeMask & REQ_SPELL_PHASE_PROC_FLAG_MASK)
                TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId %u doesn't have `spellPhaseMask` value defined, but it's required for defined `typeMask` value, proc will not be triggered", spellInfo->Id);
            if (procEntry.spellPhaseMask & ~PROC_SPELL_PHASE_MASK_ALL)
                TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId %u has wrong `spellPhaseMask` set: %u", spellInfo->Id, procEntry.spellPhaseMask);
            if (procEntry.spellPhaseMask && !(procEntry.typeMask & REQ_SPELL_PHASE_PROC_FLAG_MASK))
                TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId %u has `spellPhaseMask` value defined, but it won't be used for defined `typeMask` value", spellInfo->Id);
            if (procEntry.hitMask & ~PROC_HIT_MASK_ALL)
                TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId %u has wrong `hitMask` set: %u", spellInfo->Id, procEntry.hitMask);
            if (procEntry.hitMask && !(procEntry.typeMask & TAKEN_HIT_PROC_FLAG_MASK || (procEntry.typeMask & DONE_HIT_PROC_FLAG_MASK && (!procEntry.spellPhaseMask || procEntry.spellPhaseMask & (PROC_SPELL_PHASE_HIT | PROC_SPELL_PHASE_FINISH)))))
                TC_LOG_ERROR("sql.sql", "`spell_proc` table entry for spellId %u has `hitMask` value defined, but it won't be used for defined `typeMask` and `spellPhaseMask` values", spellInfo->Id);

            mSpellProcMap[spellInfo->Id] = procEntry;

            if (allRanks)
                spellInfo = spellInfo->GetNextRankSpell();
            else
                break;
        }
        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u spell proc conditions and data in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
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
            TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_threat` does not exist", entry);
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

        mSkillLineAbilityMap.insert(SkillLineAbilityMap::value_type(SkillInfo->SpellID, SkillInfo));
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
                TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_pet_auras` does not exist", spell);
                continue;
            }
            SpellEffectInfo const* effect = spellInfo->GetEffect(eff);
            if (!effect)
            {
                TC_LOG_ERROR("spells", "Spell %u listed in `spell_pet_auras` does not have effect at index %u", spell, uint32(eff));
                continue;
            }

            if (effect->Effect != SPELL_EFFECT_DUMMY &&
               (effect->Effect != SPELL_EFFECT_APPLY_AURA ||
                effect->ApplyAuraName != SPELL_AURA_DUMMY))
            {
                TC_LOG_ERROR("spells", "Spell %u listed in `spell_pet_auras` does not have dummy aura or dummy effect", spell);
                continue;
            }

            SpellInfo const* spellInfo2 = GetSpellInfo(aura);
            if (!spellInfo2)
            {
                TC_LOG_ERROR("sql.sql", "Aura %u listed in `spell_pet_auras` does not exist", aura);
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
            TC_LOG_ERROR("sql.sql", "Enchancment %u listed in `spell_enchant_proc_data` does not exist", enchantId);
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
            TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_linked_spell` does not exist", abs(trigger));
            continue;
        }

        if (effect >= 0)
            for (SpellEffectInfo const* eff : spellInfo->GetEffectsForDifficulty(DIFFICULTY_NONE))
            {
                if (eff && eff->CalcValue() == abs(effect))
                    TC_LOG_ERROR("sql.sql", "Spell %u Effect: %u listed in `spell_linked_spell` has same bp%u like effect (possible hack)", abs(trigger), abs(effect), eff->EffectIndex);
            }

        spellInfo = GetSpellInfo(abs(effect));
        if (!spellInfo)
        {
            TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_linked_spell` does not exist", abs(effect));
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

                if (skillLine->AquireMethod != SKILL_LINE_ABILITY_LEARNED_ON_SKILL_LEARN)
                    continue;

                SpellInfo const* spell = GetSpellInfo(skillLine->SpellID);
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
            petDefSpells.spellid[j] = spellDataEntry->Spells[j];

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

        for (SpellEffectInfo const* effect : spellEntry->GetEffectsForDifficulty(DIFFICULTY_NONE))
        {
            if (effect && (effect->Effect == SPELL_EFFECT_SUMMON || effect->Effect == SPELL_EFFECT_SUMMON_PET))
            {
                uint32 creature_id = effect->MiscValue;
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
            TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_area` does not exist", spell);
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
                TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_area` already listed with similar requirements.", spell);
                continue;
            }
        }

        if (spellArea.areaId && !GetAreaEntryByAreaID(spellArea.areaId))
        {
            TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_area` have wrong area (%u) requirement", spell, spellArea.areaId);
            continue;
        }

        if (spellArea.questStart && !sObjectMgr->GetQuestTemplate(spellArea.questStart))
        {
            TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_area` have wrong start quest (%u) requirement", spell, spellArea.questStart);
            continue;
        }

        if (spellArea.questEnd)
        {
            if (!sObjectMgr->GetQuestTemplate(spellArea.questEnd))
            {
                TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_area` have wrong end quest (%u) requirement", spell, spellArea.questEnd);
                continue;
            }
        }

        if (spellArea.auraSpell)
        {
            SpellInfo const* spellInfo = GetSpellInfo(abs(spellArea.auraSpell));
            if (!spellInfo)
            {
                TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_area` have wrong aura spell (%u) requirement", spell, abs(spellArea.auraSpell));
                continue;
            }

            if (uint32(abs(spellArea.auraSpell)) == spellArea.spellId)
            {
                TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_area` have aura spell (%u) requirement for itself", spell, abs(spellArea.auraSpell));
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
                    TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_area` have aura spell (%u) requirement that itself autocast from aura", spell, spellArea.auraSpell);
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
                    TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_area` have aura spell (%u) requirement that itself autocast from aura", spell, spellArea.auraSpell);
                    continue;
                }
            }
        }

        if (spellArea.raceMask && (spellArea.raceMask & RACEMASK_ALL_PLAYABLE) == 0)
        {
            TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_area` have wrong race mask (%u) requirement", spell, spellArea.raceMask);
            continue;
        }

        if (spellArea.gender != GENDER_NONE && spellArea.gender != GENDER_FEMALE && spellArea.gender != GENDER_MALE)
        {
            TC_LOG_ERROR("sql.sql", "Spell %u listed in `spell_area` have wrong gender (%u) requirement", spell, spellArea.gender);
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

    std::unordered_map<uint32, SpellEffectEntryMap> effectsBySpell;

    for (uint32 i = 0; i < sSpellEffectStore.GetNumRows(); ++i)
    {
        SpellEffectEntry const* effect = sSpellEffectStore.LookupEntry(i);
        if (!effect)
            continue;

        if (effect->EffectIndex >= MAX_SPELL_EFFECTS)
        {
            TC_LOG_ERROR("server.loading", "Spell %u has invalid EffectIndex %u, max is %u, skipped", i, effect->EffectIndex, uint32(MAX_SPELL_EFFECTS));
            continue;
        }

        SpellEffectEntryVector& effectsForDifficulty = effectsBySpell[effect->SpellID][effect->DifficultyID];
        if (effectsForDifficulty.size() <= effect->EffectIndex)
            effectsForDifficulty.resize(effect->EffectIndex + 1);

        effectsForDifficulty[effect->EffectIndex] = effect;
    }

    for (uint32 i = 0; i < sSpellStore.GetNumRows(); ++i)
        if (SpellEntry const* spellEntry = sSpellStore.LookupEntry(i))
            mSpellInfoMap[i] = new SpellInfo(spellEntry, effectsBySpell[i]);

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
                case SPELL_AURA_MOD_POSSESS:
                case SPELL_AURA_MOD_CONFUSE:
                case SPELL_AURA_MOD_CHARM:
                case SPELL_AURA_AOE_CHARM:
                case SPELL_AURA_MOD_FEAR:
                case SPELL_AURA_MOD_STUN:
                    spellInfo->AttributesCu |= SPELL_ATTR0_CU_AURA_CC;
                    break;
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

                            SpellInfo* procInfo = _GetSpellInfo(enchant->EffectSpellID[s]);
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

        if (spellInfo->SpellVisual[0] == 3879)
            spellInfo->AttributesCu |= SPELL_ATTR0_CU_CONE_BACK;

        if (talentSpells.count(spellInfo->Id))
            spellInfo->AttributesCu |= SPELL_ATTR0_CU_IS_TALENT;

        switch (spellInfo->SpellFamilyName)
        {
            case SPELLFAMILY_WARRIOR:
                // Shout
                if (spellInfo->SpellFamilyFlags[0] & 0x20000 || spellInfo->SpellFamilyFlags[1] & 0x20)
                    spellInfo->AttributesCu |= SPELL_ATTR0_CU_AURA_CC;
                break;
            case SPELLFAMILY_DRUID:
                // Roar
                if (spellInfo->SpellFamilyFlags[0] & 0x8)
                    spellInfo->AttributesCu |= SPELL_ATTR0_CU_AURA_CC;
                break;
            default:
                break;
        }

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
        }

        if (spellInfo->ActiveIconID == 2158)  // flight
            spellInfo->Attributes |= SPELL_ATTR0_PASSIVE;

        switch (spellInfo->Id)
        {
            case 63026: // Force Cast (HACK: Target shouldn't be changed)
            case 63137: // Force Cast (HACK: Target shouldn't be changed; summon position should be untied from spell destination)
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetA = SpellImplicitTargetInfo(TARGET_DEST_DB);
                break;
            case 42436: // Drink! (Brewfest)
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ANY);
                break;
            case 52611: // Summon Skeletons
            case 52612: // Summon Skeletons
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->MiscValueB = 64;
                break;
            case 40244: // Simon Game Visual
            case 40245: // Simon Game Visual
            case 40246: // Simon Game Visual
            case 40247: // Simon Game Visual
            case 42835: // Spout, remove damage effect, only anim is needed
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->Effect = 0;
                break;
            case 30657: // Quake
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TriggerSpell = 30571;
                break;
            case 30541: // Blaze (needs conditions entry)
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetB = SpellImplicitTargetInfo();
                break;
            case 63665: // Charge (Argent Tournament emote on riders)
            case 31298: // Sleep (needs target selection script)
            case 51904: // Summon Ghouls On Scarlet Crusade (this should use conditions table, script for this spell needs to be fixed)
            case 68933: // Wrath of Air Totem rank 2 (Aura)
            case 29200: // Purify Helboar Meat
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetB = SpellImplicitTargetInfo();
                break;
            case 31344: // Howl of Azgalor
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_100_YARDS); // 100yards instead of 50000?!
                break;
            case 42818: // Headless Horseman - Wisp Flight Port
            case 42821: // Headless Horseman - Wisp Flight Missile
                spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(6); // 100 yards
                break;
            case 36350: // They Must Burn Bomb Aura (self)
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TriggerSpell = 36325; // They Must Burn Bomb Drop (DND)
                break;
            case 49838: // Stop Time
            case 69438: // Sample Satisfaction
            case 69445: // Perfume Spritz
            case 69489: // Chocolate Sample
            case 69563: // Cologne Spritz
                spellInfo->AttributesEx3 |= SPELL_ATTR3_NO_INITIAL_AGGRO;
                break;
            case 61407: // Energize Cores
            case 62136: // Energize Cores
            case 54069: // Energize Cores
            case 56251: // Energize Cores
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetA = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ENTRY);
                break;
            case 50785: // Energize Cores
            case 59372: // Energize Cores
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetA = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ENEMY);
                break;
            case 63320: // Glyph of Life Tap
                // Entries were not updated after spell effect change, we have to do that manually :/
                spellInfo->AttributesEx3 |= SPELL_ATTR3_CAN_PROC_WITH_TRIGGERED;
                break;
            case 5308: // Execute
                spellInfo->AttributesEx3 |= SPELL_ATTR3_CANT_TRIGGER_PROC;
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
            case 53096: // Quetz'lun's Judgment
            case 70743: // AoD Special
            case 70614: // AoD Special - Vegard
            case 52479: // Gift of the Harvester
            case 61588: // Blazing Harpoon
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
            case 40827: // Sinful Beam
            case 40859: // Sinister Beam
            case 40860: // Vile Beam
            case 40861: // Wicked Beam
            case 54835: // Curse of the Plaguebringer - Noth (H)
            case 54098: // Poison Bolt Volly - Faerlina (H)
                spellInfo->MaxAffectedTargets = 10;
                break;
            case 50312: // Unholy Frenzy
                spellInfo->MaxAffectedTargets = 15;
                break;
            case 33711: // Murmur's Touch
            case 38794: // Murmur's Touch
                spellInfo->MaxAffectedTargets = 1;
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TriggerSpell = 33760;
                break;
            case 17941: // Shadow Trance
            case 22008: // Netherwind Focus
            case 34477: // Misdirection
            case 48108: // Hot Streak
            case 51124: // Killing Machine
            case 57761: // Fireball!
            case 64823: // Item - Druid T8 Balance 4P Bonus
            case 88819: // Daybreak
                spellInfo->ProcCharges = 1;
                break;
            case 44544: // Fingers of Frost
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->SpellClassMask = flag128(685904631, 1151048, 0, 0);
                break;
            case 28200: // Ascendance (Talisman of Ascendance trinket)
                spellInfo->ProcCharges = 6;
                break;
            case 37408: // Oscillation Field
                spellInfo->AttributesEx3 |= SPELL_ATTR3_STACK_FOR_DIFF_CASTERS;
                break;
            case 51852: // The Eye of Acherus (no spawn in phase 2 in db)
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->MiscValue |= 1;
                break;
            case 51912: // Crafty's Ultra-Advanced Proto-Typical Shortening Blaster
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->ApplyAuraPeriod = 3000;
                break;
            case 30421: // Nether Portal - Perseverence
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_2))->BasePoints += 30000;
                break;
            case 41913: // Parasitic Shadowfiend Passive
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->ApplyAuraName = SPELL_AURA_DUMMY; // proc debuff, and summon infinite fiends
                break;
            case 27892: // To Anchor 1
            case 27928: // To Anchor 1
            case 27935: // To Anchor 1
            case 27915: // Anchor to Skulls
            case 27931: // Anchor to Skulls
            case 27937: // Anchor to Skulls
                spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(EFFECT_RADIUS_10_YARDS);
                break;
            // target allys instead of enemies, target A is src_caster, spells with effect like that have ally target
            // this is the only known exception, probably just wrong data
            case 29214: // Wrath of the Plaguebringer
            case 54836: // Wrath of the Plaguebringer
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetB = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ALLY);
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_1))->TargetB = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ALLY);
                break;
            case 8145: // Tremor Totem (instant pulse)
            case 6474: // Earthbind Totem (instant pulse)
                spellInfo->AttributesEx5 |= SPELL_ATTR5_START_PERIODIC_AT_APPLY;
                break;
            case 5176:  // Wrath
            case 2912:  // Starfire
            //case 78674: // Starsurge 6.x effect 1 is no more
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_1))->Effect = SPELL_EFFECT_DUMMY;
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_1))->TargetA = TARGET_UNIT_CASTER;
                break;
            case 70728: // Exploit Weakness (needs target selection script)
            case 70840: // Devious Minds (needs target selection script)
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetB = SpellImplicitTargetInfo(TARGET_UNIT_PET);
                break;
            case 45602: // Ride Carpet
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->BasePoints = 0; // force seat 0, vehicle doesn't have the required seat flags for "no seat specified (-1)"
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
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->BasePoints = 1;
                break;
            case 59630: // Black Magic
                spellInfo->Attributes |= SPELL_ATTR0_PASSIVE;
                break;
            case 17364: // Stormstrike
                spellInfo->AttributesEx3 |= SPELL_ATTR3_STACK_FOR_DIFF_CASTERS;
                break;
            case 51798: // Brewfest - Relay Race - Intro - Quest Complete
            case 47134: // Quest Complete
                //! HACK: This spell break quest complete for alliance and on retail not used °_O
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->Effect = 0;
                break;
            // ULDUAR SPELLS
            //
            case 62374: // Pursued (Flame Leviathan)
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_50000_YARDS);   // 50000yd
                break;
            case 63342: // Focused Eyebeam Summon Trigger (Kologarn)
                spellInfo->MaxAffectedTargets = 1;
                break;
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
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_1))->Effect = 0;
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
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetB = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
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
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetB = SpellImplicitTargetInfo(TARGET_DEST_CASTER);
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
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetA = SpellImplicitTargetInfo(TARGET_DEST_DB);
                break;
            // ENDOF ULDUAR SPELLS
            //
            // TRIAL OF THE CRUSADER SPELLS
            //
            case 66258: // Infernal Eruption
                // increase duration from 15 to 18 seconds because caster is already
                // unsummoned when spell missile hits the ground so nothing happen in result
                spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(85);
                break;
            // ENDOF TRIAL OF THE CRUSADER SPELLS
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
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetA = SpellImplicitTargetInfo(TARGET_DEST_DB);
                break;
            case 71169: // Shadow's Fate
                spellInfo->AttributesEx3 |= SPELL_ATTR3_STACK_FOR_DIFF_CASTERS;
                break;
            case 72347: // Lock Players and Tap Chest
                spellInfo->AttributesEx3 &= ~SPELL_ATTR3_NO_INITIAL_AGGRO;
                break;
            case 72723: // Resistant Skin (Deathbringer Saurfang adds)
                // this spell initially granted Shadow damage immunity, however it was removed but the data was left in client
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_2))->Effect = 0;
                break;
            case 70460: // Coldflame Jets (Traps after Saurfang)
                spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(1); // 10 seconds
                break;
            case 71412: // Green Ooze Summon (Professor Putricide)
            case 71415: // Orange Ooze Summon (Professor Putricide)
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ANY);
                break;
            case 71159: // Awaken Plagued Zombies
                spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(21);
                break;
            case 70530: // Volatile Ooze Beam Protection (Professor Putricide)
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->Effect = SPELL_EFFECT_APPLY_AURA; // for an unknown reason this was SPELL_EFFECT_APPLY_AREA_AURA_RAID
                break;
            // THIS IS HERE BECAUSE COOLDOWN ON CREATURE PROCS IS NOT IMPLEMENTED
            case 71604: // Mutated Strength (Professor Putricide)
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_1))->Effect = 0;
                break;
            case 70911: // Unbound Plague (Professor Putricide) (needs target selection script)
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetB = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
                break;
            case 71708: // Empowered Flare (Blood Prince Council)
                spellInfo->AttributesEx3 |= SPELL_ATTR3_NO_DONE_BONUS;
                break;
            case 71266: // Swarming Shadows
                spellInfo->RequiredAreasID = 0; // originally, these require area 4522, which is... outside of Icecrown Citadel
                break;
            case 70602: // Corruption
            case 48278: // Paralyze
                spellInfo->AttributesEx3 |= SPELL_ATTR3_STACK_FOR_DIFF_CASTERS;
                break;
            case 70715: // Column of Frost (visual marker)
                spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(32); // 6 seconds (missing)
                break;
            case 71085: // Mana Void (periodic aura)
                spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(9); // 30 seconds (missing)
                break;
            case 70936: // Summon Suppressor (needs target selection script)
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ANY);
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetB = SpellImplicitTargetInfo();
                break;
            case 70598: // Sindragosa's Fury
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetA = SpellImplicitTargetInfo(TARGET_DEST_DEST);
                break;
            case 69846: // Frost Bomb
                spellInfo->Speed = 0.0f;    // This spell's summon happens instantly
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
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS); // 200yd
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_1))->RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS); // 200yd
                break;
            case 69198: // Raging Spirit Visual
                spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(13); // 50000yd
                break;
            case 73655: // Harvest Soul
                spellInfo->AttributesEx3 |= SPELL_ATTR3_NO_DONE_BONUS;
                break;
            case 73540: // Summon Shadow Trap
                spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(23); // 90 seconds
                break;
            case 73530: // Shadow Trap (visual)
                spellInfo->DurationEntry = sSpellDurationStore.LookupEntry(28); // 5 seconds
                break;
            case 74302: // Summon Spirit Bomb
                spellInfo->MaxAffectedTargets = 2;
                break;
            case 73579: // Summon Spirit Bomb
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_25_YARDS); // 25yd
                break;
            case 72376: // Raise Dead
                spellInfo->MaxAffectedTargets = 3;
                break;
            case 71809: // Jump
                spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(3); // 20yd
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_25_YARDS); // 25yd
                break;
            case 72405: // Broken Frostmourne
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_1))->RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_200_YARDS); // 200yd
                break;
            // ENDOF ICECROWN CITADEL SPELLS
            //
            // RUBY SANCTUM SPELLS
            //
            case 74799: // Soul Consumption
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_1))->RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_12_YARDS);
                break;
            case 75509: // Twilight Mending
                spellInfo->AttributesEx6 |= SPELL_ATTR6_CAN_TARGET_INVISIBLE;
                spellInfo->AttributesEx2 |= SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS;
                break;
            case 75888: // Awaken Flames
                spellInfo->AttributesEx |= SPELL_ATTR1_CANT_TARGET_SELF;
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
            // Stonecore spells
            case 95284: // Teleport (from entrance to Slabhide)
            case 95285: // Teleport (from Slabhide to entrance)
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetB = SpellImplicitTargetInfo(TARGET_DEST_DB);
                break;
            // Halls Of Origination spells
            // Temple Guardian Anhuur
            case 76606: // Disable Beacon Beams L
            case 76608: // Disable Beacon Beams R
                // Little hack, Increase the radius so it can hit the Cave In Stalkers in the platform.
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->MaxRadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_45_YARDS);
                break;
            case 75323: // Reverberating Hymn
                // Aura is refreshed at 3 seconds, and the tick should happen at the fourth.
                spellInfo->AttributesEx8 |= SPELL_ATTR8_DONT_RESET_PERIODIC_TIMER;
                break;
            case 24314: // Threatening Gaze
                spellInfo->AuraInterruptFlags |= AURA_INTERRUPT_FLAG_CAST | AURA_INTERRUPT_FLAG_MOVE | AURA_INTERRUPT_FLAG_JUMP;
                break;
            case 5420: // Tree of Life (Passive)
                spellInfo->Stances = 1 << (FORM_TREE - 1);
                break;
            case 49376: // Feral Charge (Cat Form)
                spellInfo->AttributesEx3 &= ~SPELL_ATTR3_CANT_TRIGGER_PROC;
                break;
            case 45257: // Using Steam Tonk Controller
            case 45440: // Steam Tonk Controller
            case 60256: // Collect Sample
                // Crashes client on pressing ESC
                spellInfo->AttributesEx4 &= ~SPELL_ATTR4_CAN_CAST_WHILE_CASTING;
                break;
            case 96942:  // Gaze of Occu'thar
                spellInfo->AttributesEx &= ~SPELL_ATTR1_CHANNELED_1;
                break;
            case 75610: // Evolution
                spellInfo->MaxAffectedTargets = 1;
                break;
            case 75697: // Evolution
                const_cast<SpellEffectInfo*>(spellInfo->GetEffect(EFFECT_0))->TargetA = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ENTRY);
                break;
            // ISLE OF CONQUEST SPELLS
            //
            case 66551: // Teleport
                spellInfo->RangeEntry = sSpellRangeStore.LookupEntry(13); // 50000yd
                break;
            // ENDOF ISLE OF CONQUEST SPELLS
            //
            default:
                break;
        }
    }

    if (SummonPropertiesEntry* properties = const_cast<SummonPropertiesEntry*>(sSummonPropertiesStore.LookupEntry(121)))
        properties->Type = SUMMON_TYPE_TOTEM;
    if (SummonPropertiesEntry* properties = const_cast<SummonPropertiesEntry*>(sSummonPropertiesStore.LookupEntry(647))) // 52893
        properties->Type = SUMMON_TYPE_TOTEM;

    TC_LOG_INFO("server.loading", ">> Loaded SpellInfo corrections in %u ms", GetMSTimeDiffToNow(oldMSTime));
}

void SpellMgr::LoadPetFamilySpellsStore()
{
    for (uint32 j = 0; j < sSkillLineAbilityStore.GetNumRows(); ++j)
    {
        SkillLineAbilityEntry const* skillLine = sSkillLineAbilityStore.LookupEntry(j);
        if (!skillLine)
            continue;

        SpellEntry const* spellInfo = sSpellStore.LookupEntry(skillLine->SpellID);
        if (!spellInfo)
            continue;

        SpellLevelsEntry const* levels = sSpellLevelsStore.LookupEntry(spellInfo->LevelsID);
        if (spellInfo->LevelsID && (!levels || levels->SpellLevel))
            continue;

        if (SpellMiscEntry const* spellMisc = sSpellMiscStore.LookupEntry(spellInfo->MiscID))
        {
            if (spellMisc->Attributes & SPELL_ATTR0_PASSIVE)
            {
                for (uint32 i = 1; i < sCreatureFamilyStore.GetNumRows(); ++i)
                {
                    CreatureFamilyEntry const* cFamily = sCreatureFamilyStore.LookupEntry(i);
                    if (!cFamily)
                        continue;

                    if (skillLine->SkillLine != cFamily->SkillLine[0] && skillLine->SkillLine != cFamily->SkillLine[1])
                        continue;

                    if (skillLine->AquireMethod != SKILL_LINE_ABILITY_LEARNED_ON_SKILL_LEARN)
                        continue;

                    sPetFamilySpellsStore[i].insert(spellInfo->ID);
                }
            }
        }
    }
}
