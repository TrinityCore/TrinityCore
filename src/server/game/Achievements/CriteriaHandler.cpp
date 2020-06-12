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

#include "CriteriaHandler.h"
#include "AchievementMgr.h"
#include "ArenaTeamMgr.h"
#include "AzeriteItem.h"
#include "BattlefieldMgr.h"
#include "Battleground.h"
#include "BattlePetMgr.h"
#include "CollectionMgr.h"
#include "Containers.h"
#include "Creature.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "DisableMgr.h"
#include "GameEventMgr.h"
#include "Garrison.h"
#include "Group.h"
#include "InstanceScript.h"
#include "Item.h"
#include "Log.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "RealmList.h"
#include "ReputationMgr.h"
#include "Scenario.h"
#include "ScriptMgr.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "World.h"
#include "WorldSession.h"

bool CriteriaData::IsValid(Criteria const* criteria)
{
    if (DataType >= MAX_CRITERIA_DATA_TYPE)
    {
        TC_LOG_ERROR("sql.sql", "Table `criteria_data` for criteria (Entry: %u) contains a wrong data type (%u), ignored.", criteria->ID, DataType);
        return false;
    }

    switch (criteria->Entry->Type)
    {
        case CRITERIA_TYPE_KILL_CREATURE:
        case CRITERIA_TYPE_KILL_CREATURE_TYPE:
        case CRITERIA_TYPE_WIN_BG:
        case CRITERIA_TYPE_FALL_WITHOUT_DYING:
        case CRITERIA_TYPE_COMPLETE_QUEST:          // only hardcoded list
        case CRITERIA_TYPE_CAST_SPELL:
        case CRITERIA_TYPE_WIN_RATED_ARENA:
        case CRITERIA_TYPE_DO_EMOTE:
        case CRITERIA_TYPE_SPECIAL_PVP_KILL:
        case CRITERIA_TYPE_WIN_DUEL:
        case CRITERIA_TYPE_LOOT_TYPE:
        case CRITERIA_TYPE_CAST_SPELL2:
        case CRITERIA_TYPE_BE_SPELL_TARGET:
        case CRITERIA_TYPE_BE_SPELL_TARGET2:
        case CRITERIA_TYPE_EQUIP_EPIC_ITEM:
        case CRITERIA_TYPE_ROLL_NEED_ON_LOOT:
        case CRITERIA_TYPE_ROLL_GREED_ON_LOOT:
        case CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE:
        case CRITERIA_TYPE_HONORABLE_KILL:
        case CRITERIA_TYPE_COMPLETE_DAILY_QUEST:    // only Children's Week achievements
        case CRITERIA_TYPE_USE_ITEM:                // only Children's Week achievements
        case CRITERIA_TYPE_GET_KILLING_BLOWS:
        case CRITERIA_TYPE_REACH_LEVEL:
        case CRITERIA_TYPE_ON_LOGIN:
        case CRITERIA_TYPE_LOOT_EPIC_ITEM:
        case CRITERIA_TYPE_RECEIVE_EPIC_ITEM:
            break;
        default:
            if (DataType != CRITERIA_DATA_TYPE_SCRIPT)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` contains data for a non-supported criteria type (Entry: %u Type: %u), ignored.", criteria->ID, criteria->Entry->Type);
                return false;
            }
            break;
    }

    switch (DataType)
    {
        case CRITERIA_DATA_TYPE_NONE:
        case CRITERIA_DATA_TYPE_INSTANCE_SCRIPT:
            return true;
        case CRITERIA_DATA_TYPE_T_CREATURE:
            if (!Creature.Id || !sObjectMgr->GetCreatureTemplate(Creature.Id))
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: %u Type: %u) for data type CRITERIA_DATA_TYPE_CREATURE (%u) contains a non-existing creature id in value1 (%u), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, Creature.Id);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_T_PLAYER_CLASS_RACE:
            if (!ClassRace.Class && !ClassRace.Race)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: %u Type: %u) for data type CRITERIA_DATA_TYPE_T_PLAYER_CLASS_RACE (%u) must not have 0 in either value field, ignored.",
                    criteria->ID, criteria->Entry->Type, DataType);
                return false;
            }
            if (ClassRace.Class && ((1 << (ClassRace.Class-1)) & CLASSMASK_ALL_PLAYABLE) == 0)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: %u Type: %u) for data type CRITERIA_DATA_TYPE_T_PLAYER_CLASS_RACE (%u) contains a non-existing class in value1 (%u), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, ClassRace.Class);
                return false;
            }
            if (!Trinity::RaceMask<uint64>{ RACEMASK_ALL_PLAYABLE }.HasRace(ClassRace.Race))
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: %u Type: %u) for data type CRITERIA_DATA_TYPE_T_PLAYER_CLASS_RACE (%u) contains a non-existing race in value2 (%u), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, ClassRace.Race);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_T_PLAYER_LESS_HEALTH:
            if (Health.Percent < 1 || Health.Percent > 100)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: %u Type: %u) for data type CRITERIA_DATA_TYPE_PLAYER_LESS_HEALTH (%u) contains a wrong percent value in value1 (%u), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, Health.Percent);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_S_AURA:
        case CRITERIA_DATA_TYPE_T_AURA:
        {
            SpellInfo const* spellEntry = sSpellMgr->GetSpellInfo(Aura.SpellId, DIFFICULTY_NONE);
            if (!spellEntry)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: %u Type: %u) for data type %s (%u) contains a wrong spell id in value1 (%u), ignored.",
                    criteria->ID, criteria->Entry->Type, (DataType == CRITERIA_DATA_TYPE_S_AURA ? "CRITERIA_DATA_TYPE_S_AURA" : "CRITERIA_DATA_TYPE_T_AURA"), DataType, Aura.SpellId);
                return false;
            }
            SpellEffectInfo const* effect = spellEntry->GetEffect(Aura.EffectIndex);
            if (!effect)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: %u Type: %u) for data type %s (%u) contains a wrong spell effect index in value2 (%u), ignored.",
                    criteria->ID, criteria->Entry->Type, (DataType == CRITERIA_DATA_TYPE_S_AURA ? "CRITERIA_DATA_TYPE_S_AURA" : "CRITERIA_DATA_TYPE_T_AURA"), DataType, Aura.EffectIndex);
                return false;
            }
            if (!effect->ApplyAuraName)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: %u Type: %u) for data type %s (%u) contains a non-aura spell effect (ID: %u Effect: %u), ignored.",
                    criteria->ID, criteria->Entry->Type, (DataType == CRITERIA_DATA_TYPE_S_AURA ? "CRITERIA_DATA_TYPE_S_AURA" : "CRITERIA_DATA_TYPE_T_AURA"), DataType, Aura.SpellId, Aura.EffectIndex);
                return false;
            }
            return true;
        }
        case CRITERIA_DATA_TYPE_VALUE:
            if (Value.ComparisonType >= COMP_TYPE_MAX)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: %u Type: %u) for data type CRITERIA_DATA_TYPE_VALUE (%u) contains a wrong ComparisionType in value2 (%u), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, Value.ComparisonType);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_T_LEVEL:
            if (Level.Min > STRONG_MAX_LEVEL)
            {
                TC_LOG_ERROR("sql.sql", "Table `CRITERIA_DATA` (Entry: %u Type: %u) for data type CRITERIA_DATA_TYPE_T_LEVEL (%u) contains a wrong minlevel in value1 (%u), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, Level.Min);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_T_GENDER:
            if (Gender.Gender > GENDER_NONE)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: %u Type: %u) for data type CRITERIA_DATA_TYPE_T_GENDER (%u) contains a wrong gender value in value1 (%u), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, Gender.Gender);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_SCRIPT:
            if (!ScriptId)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: %u Type: %u) for data type CRITERIA_DATA_TYPE_SCRIPT (%u) does not have a ScriptName set, ignored.",
                    criteria->ID, criteria->Entry->Type, DataType);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_MAP_PLAYER_COUNT:
            if (MapPlayers.MaxCount <= 0)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: %u Type: %u) for data type CRITERIA_DATA_TYPE_MAP_PLAYER_COUNT (%u) contains a wrong max players count in value1 (%u), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, MapPlayers.MaxCount);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_T_TEAM:
            if (Team.Team != ALLIANCE && Team.Team != HORDE)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: %u Type: %u) for data type CRITERIA_DATA_TYPE_T_TEAM (%u) contains an unknown team value in value1 (%u), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, Team.Team);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_S_DRUNK:
            if (Drunk.State >= MAX_DRUNKEN)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: %u Type: %u) for data type CRITERIA_DATA_TYPE_S_DRUNK (%u) contains an unknown drunken state value in value1 (%u), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, Drunk.State);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_HOLIDAY:
            if (!sHolidaysStore.LookupEntry(Holiday.Id))
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: %u Type: %u) for data type CRITERIA_DATA_TYPE_HOLIDAY (%u) contains an unknown holiday entry in value1 (%u), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, Holiday.Id);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_GAME_EVENT:
        {
            GameEventMgr::GameEventDataMap const& events = sGameEventMgr->GetEventMap();
            if (GameEvent.Id < 1 || GameEvent.Id >= events.size())
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: %u Type: %u) for data type CRITERIA_DATA_TYPE_GAME_EVENT (%u) has unknown game_event in value1 (%u), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, GameEvent.Id);
                return false;
            }
            return true;
        }
        case CRITERIA_DATA_TYPE_BG_LOSS_TEAM_SCORE:
            return true;                                    // not check correctness node indexes
        case CRITERIA_DATA_TYPE_S_EQUIPPED_ITEM:
            if (EquippedItem.Quality >= MAX_ITEM_QUALITY)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: %u Type: %u) for data type CRITERIA_DATA_TYPE_S_EQUIPPED_ITEM (%u) contains an unknown quality state value in value2 (%u), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, EquippedItem.Quality);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_MAP_ID:
            if (!sMapStore.LookupEntry(Map.Id))
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: %u Type: %u) for data type CRITERIA_DATA_TYPE_MAP_ID (%u) contains an unknown map entry in value1 (%u), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, Map.Id);
            }
            return true;
        case CRITERIA_DATA_TYPE_S_PLAYER_CLASS_RACE:
            if (!ClassRace.Class && !ClassRace.Race)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: %u Type: %u) for data type CRITERIA_DATA_TYPE_S_PLAYER_CLASS_RACE (%u) should not have 0 in either value field. Ignored.",
                    criteria->ID, criteria->Entry->Type, DataType);
                return false;
            }
            if (ClassRace.Class && ((1 << (ClassRace.Class-1)) & CLASSMASK_ALL_PLAYABLE) == 0)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: %u Type: %u) for data type CRITERIA_DATA_TYPE_S_PLAYER_CLASS_RACE (%u) contains a non-existing class entry in value1 (%u), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, ClassRace.Class);
                return false;
            }
            if (ClassRace.Race && ((UI64LIT(1) << (ClassRace.Race-1)) & RACEMASK_ALL_PLAYABLE) == 0)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: %u Type: %u) for data type CRITERIA_DATA_TYPE_S_PLAYER_CLASS_RACE (%u) contains a non-existing race entry in value2 (%u), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, ClassRace.Race);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_S_KNOWN_TITLE:
            if (!sCharTitlesStore.LookupEntry(KnownTitle.Id))
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: %u Type: %u) for data type CRITERIA_DATA_TYPE_S_KNOWN_TITLE (%u) contains an unknown title_id in value1 (%u), ignore.",
                    criteria->ID, criteria->Entry->Type, DataType, KnownTitle.Id);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_S_ITEM_QUALITY:
            if (ItemQuality.Quality >= MAX_ITEM_QUALITY)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: %u Type: %u) for data type CRITERIA_DATA_TYPE_S_ITEM_QUALITY (%u) contains an unknown quality state value in value1 (%u), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, ItemQuality.Quality);
                return false;
            }
            return true;
        default:
            TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: %u Type: %u) contains data of a non-supported data type (%u), ignored.", criteria->ID, criteria->Entry->Type, DataType);
            return false;
    }
}

bool CriteriaData::Meets(uint32 criteriaId, Player const* source, Unit const* target, uint32 miscValue1 /*= 0*/, uint32 miscValue2 /*= 0*/) const
{
    switch (DataType)
    {
        case CRITERIA_DATA_TYPE_NONE:
            return true;
        case CRITERIA_DATA_TYPE_T_CREATURE:
            if (!target || target->GetTypeId() != TYPEID_UNIT)
                return false;
            return target->GetEntry() == Creature.Id;
        case CRITERIA_DATA_TYPE_T_PLAYER_CLASS_RACE:
            if (!target || target->GetTypeId() != TYPEID_PLAYER)
                return false;
            if (ClassRace.Class && ClassRace.Class != target->ToPlayer()->getClass())
                return false;
            if (ClassRace.Race && ClassRace.Race != target->ToPlayer()->getRace())
                return false;
            return true;
        case CRITERIA_DATA_TYPE_S_PLAYER_CLASS_RACE:
            if (source->GetTypeId() != TYPEID_PLAYER)
                return false;
            if (ClassRace.Class && ClassRace.Class != source->ToPlayer()->getClass())
                return false;
            if (ClassRace.Race && ClassRace.Race != source->ToPlayer()->getRace())
                return false;
            return true;
        case CRITERIA_DATA_TYPE_T_PLAYER_LESS_HEALTH:
            if (!target || target->GetTypeId() != TYPEID_PLAYER)
                return false;
            return !target->HealthAbovePct(Health.Percent);
        case CRITERIA_DATA_TYPE_S_AURA:
            return source->HasAuraEffect(Aura.SpellId, uint8(Aura.EffectIndex));
        case CRITERIA_DATA_TYPE_T_AURA:
            return target && target->HasAuraEffect(Aura.SpellId, uint8(Aura.EffectIndex));
        case CRITERIA_DATA_TYPE_VALUE:
            return CompareValues(ComparisionType(Value.ComparisonType), miscValue1, Value.Value);
        case CRITERIA_DATA_TYPE_T_LEVEL:
            if (!target)
                return false;
            return target->GetLevelForTarget(source) >= Level.Min;
        case CRITERIA_DATA_TYPE_T_GENDER:
            if (!target)
                return false;
            return target->getGender() == Gender.Gender;
        case CRITERIA_DATA_TYPE_SCRIPT:
            return sScriptMgr->OnCriteriaCheck(ScriptId, const_cast<Player*>(source), const_cast<Unit*>(target));
        case CRITERIA_DATA_TYPE_MAP_PLAYER_COUNT:
            return source->GetMap()->GetPlayersCountExceptGMs() <= MapPlayers.MaxCount;
        case CRITERIA_DATA_TYPE_T_TEAM:
            if (!target || target->GetTypeId() != TYPEID_PLAYER)
                return false;
            return target->ToPlayer()->GetTeam() == Team.Team;
        case CRITERIA_DATA_TYPE_S_DRUNK:
            return Player::GetDrunkenstateByValue(source->GetDrunkValue()) >= DrunkenState(Drunk.State);
        case CRITERIA_DATA_TYPE_HOLIDAY:
            return IsHolidayActive(HolidayIds(Holiday.Id));
        case CRITERIA_DATA_TYPE_GAME_EVENT:
            return IsEventActive(uint16(GameEvent.Id));
        case CRITERIA_DATA_TYPE_BG_LOSS_TEAM_SCORE:
        {
            Battleground* bg = source->GetBattleground();
            if (!bg)
                return false;

            uint32 score = bg->GetTeamScore(source->GetTeamId() == TEAM_ALLIANCE ? TEAM_HORDE : TEAM_ALLIANCE);
            return score >= BattlegroundScore.Min && score <= BattlegroundScore.Max;
        }
        case CRITERIA_DATA_TYPE_INSTANCE_SCRIPT:
        {
            if (!source->IsInWorld())
                return false;
            class Map* map = source->GetMap();
            if (!map->IsDungeon())
            {
                TC_LOG_ERROR("criteria", "Criteria system call CRITERIA_DATA_TYPE_INSTANCE_SCRIPT (%u) for criteria %u in a non-dungeon/non-raid map %u",
                    DataType, criteriaId, map->GetId());
                return false;
            }
            InstanceScript* instance = map->ToInstanceMap()->GetInstanceScript();
            if (!instance)
            {
                TC_LOG_ERROR("criteria", "Criteria system call CRITERIA_DATA_TYPE_INSTANCE_SCRIPT (%u) for criteria %u in map %u, but the map does not have an instance script.",
                    DataType, criteriaId, map->GetId());
                return false;
            }
            return instance->CheckAchievementCriteriaMeet(criteriaId, source, target, miscValue1);
        }
        case CRITERIA_DATA_TYPE_S_EQUIPPED_ITEM:
        {
            Criteria const* entry = ASSERT_NOTNULL(sCriteriaMgr->GetCriteria(criteriaId));

            uint32 itemId = (entry->Entry->Type == CRITERIA_TYPE_EQUIP_EPIC_ITEM ? miscValue2 : miscValue1);
            ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(itemId);
            if (!itemTemplate)
                return false;
            return itemTemplate->GetBaseItemLevel() >= EquippedItem.ItemLevel && itemTemplate->GetQuality() >= EquippedItem.Quality;
        }
        case CRITERIA_DATA_TYPE_MAP_ID:
            return source->GetMapId() == Map.Id;
        case CRITERIA_DATA_TYPE_S_KNOWN_TITLE:
        {
            if (CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(KnownTitle.Id))
                return source && source->HasTitle(titleInfo->MaskID);

            return false;
        }
        case CRITERIA_DATA_TYPE_S_ITEM_QUALITY:
        {
            ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(miscValue1);
            if (!pProto)
                return false;
            return pProto->GetQuality() == ItemQuality.Quality;
        }
        default:
            break;
    }
    return false;
}

bool CriteriaDataSet::Meets(Player const* source, Unit const* target, uint32 miscValue1 /*= 0*/, uint32 miscValue2 /*= 0*/) const
{
    for (CriteriaData const& data : _storage)
        if (!data.Meets(_criteriaId, source, target, miscValue1, miscValue2))
            return false;

    return true;
}

CriteriaHandler::CriteriaHandler() { }

CriteriaHandler::~CriteriaHandler() { }

void CriteriaHandler::Reset()
{
    for (auto iter = _criteriaProgress.begin(); iter != _criteriaProgress.end(); ++iter)
        SendCriteriaProgressRemoved(iter->first);

    _criteriaProgress.clear();
}

/**
 * this function will be called whenever the user might have done a criteria relevant action
 */
void CriteriaHandler::UpdateCriteria(CriteriaTypes type, uint64 miscValue1 /*= 0*/, uint64 miscValue2 /*= 0*/, uint64 miscValue3 /*= 0*/, Unit const* unit /*= nullptr*/, Player* referencePlayer /*= nullptr*/)
{
    if (type >= CRITERIA_TYPE_TOTAL)
    {
        TC_LOG_DEBUG("criteria", "CriteriaHandler::UpdateCriteria: Wrong criteria type %u", type);
        return;
    }

    if (!referencePlayer)
    {
        TC_LOG_DEBUG("criteria", "CriteriaHandler::UpdateCriteria: Player is NULL! Cant update criteria");
        return;
    }

    // disable for gamemasters with GM-mode enabled
    if (referencePlayer->IsGameMaster())
    {
        TC_LOG_DEBUG("criteria", "CriteriaHandler::UpdateCriteria: [Player %s GM mode on] %s, %s (%u), " UI64FMTD ", " UI64FMTD ", " UI64FMTD,
            referencePlayer->GetName().c_str(), GetOwnerInfo().c_str(), CriteriaMgr::GetCriteriaTypeString(type), type, miscValue1, miscValue2, miscValue3);
        return;
    }

    TC_LOG_DEBUG("criteria", "CriteriaHandler::UpdateCriteria(%s, %u, " UI64FMTD ", " UI64FMTD ", " UI64FMTD ") %s",
        CriteriaMgr::GetCriteriaTypeString(type), type, miscValue1, miscValue2, miscValue3, GetOwnerInfo().c_str());

    CriteriaList const& criteriaList = GetCriteriaByType(type, uint32(miscValue1));
    for (Criteria const* criteria : criteriaList)
    {
        CriteriaTreeList const* trees = sCriteriaMgr->GetCriteriaTreesByCriteria(criteria->ID);
        if (!CanUpdateCriteria(criteria, trees, miscValue1, miscValue2, miscValue3, unit, referencePlayer))
            continue;

        // requirements not found in the dbc
        if (CriteriaDataSet const* data = sCriteriaMgr->GetCriteriaDataSet(criteria))
            if (!data->Meets(referencePlayer, unit, uint32(miscValue1), uint32(miscValue2)))
                continue;

        switch (type)
        {
            // std. case: increment at 1
            case CRITERIA_TYPE_WIN_BG:
            case CRITERIA_TYPE_NUMBER_OF_TALENT_RESETS:
            case CRITERIA_TYPE_LOSE_DUEL:
            case CRITERIA_TYPE_CREATE_AUCTION:
            case CRITERIA_TYPE_WON_AUCTIONS:    /* FIXME: for online player only currently */
            case CRITERIA_TYPE_ROLL_NEED:
            case CRITERIA_TYPE_ROLL_GREED:
            case CRITERIA_TYPE_QUEST_ABANDONED:
            case CRITERIA_TYPE_FLIGHT_PATHS_TAKEN:
            case CRITERIA_TYPE_ACCEPTED_SUMMONINGS:
            case CRITERIA_TYPE_LOOT_EPIC_ITEM:
            case CRITERIA_TYPE_RECEIVE_EPIC_ITEM:
            case CRITERIA_TYPE_DEATH:
            case CRITERIA_TYPE_COMPLETE_DAILY_QUEST:
            case CRITERIA_TYPE_COMPLETE_BATTLEGROUND:
            case CRITERIA_TYPE_DEATH_AT_MAP:
            case CRITERIA_TYPE_DEATH_IN_DUNGEON:
            case CRITERIA_TYPE_KILLED_BY_CREATURE:
            case CRITERIA_TYPE_KILLED_BY_PLAYER:
            case CRITERIA_TYPE_DEATHS_FROM:
            case CRITERIA_TYPE_BE_SPELL_TARGET:
            case CRITERIA_TYPE_BE_SPELL_TARGET2:
            case CRITERIA_TYPE_CAST_SPELL:
            case CRITERIA_TYPE_CAST_SPELL2:
            case CRITERIA_TYPE_WIN_RATED_ARENA:
            case CRITERIA_TYPE_USE_ITEM:
            case CRITERIA_TYPE_ROLL_NEED_ON_LOOT:
            case CRITERIA_TYPE_ROLL_GREED_ON_LOOT:
            case CRITERIA_TYPE_DO_EMOTE:
            case CRITERIA_TYPE_USE_GAMEOBJECT:
            case CRITERIA_TYPE_FISH_IN_GAMEOBJECT:
            case CRITERIA_TYPE_WIN_DUEL:
            case CRITERIA_TYPE_HK_CLASS:
            case CRITERIA_TYPE_HK_RACE:
            case CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE:
            case CRITERIA_TYPE_HONORABLE_KILL:
            case CRITERIA_TYPE_SPECIAL_PVP_KILL:
            case CRITERIA_TYPE_GET_KILLING_BLOWS:
            case CRITERIA_TYPE_HONORABLE_KILL_AT_AREA:
            case CRITERIA_TYPE_WIN_ARENA: // This also behaves like CRITERIA_TYPE_WIN_RATED_ARENA
            case CRITERIA_TYPE_ON_LOGIN:
            case CRITERIA_TYPE_PLACE_GARRISON_BUILDING:
            case CRITERIA_TYPE_OWN_BATTLE_PET_COUNT:
            case CRITERIA_TYPE_HONOR_LEVEL_REACHED:
            case CRITERIA_TYPE_PRESTIGE_REACHED:
            case CRITERIA_TYPE_APPEARANCE_UNLOCKED_BY_SLOT:
            case CRITERIA_TYPE_TRANSMOG_SET_UNLOCKED:
                SetCriteriaProgress(criteria, 1, referencePlayer, PROGRESS_ACCUMULATE);
                break;
            // std case: increment at miscValue1
            case CRITERIA_TYPE_MONEY_FROM_VENDORS:
            case CRITERIA_TYPE_GOLD_SPENT_FOR_TALENTS:
            case CRITERIA_TYPE_MONEY_FROM_QUEST_REWARD:
            case CRITERIA_TYPE_GOLD_SPENT_FOR_TRAVELLING:
            case CRITERIA_TYPE_GOLD_SPENT_AT_BARBER:
            case CRITERIA_TYPE_GOLD_SPENT_FOR_MAIL:
            case CRITERIA_TYPE_LOOT_MONEY:
            case CRITERIA_TYPE_GOLD_EARNED_BY_AUCTIONS:/* FIXME: for online player only currently */
            case CRITERIA_TYPE_TOTAL_DAMAGE_RECEIVED:
            case CRITERIA_TYPE_TOTAL_HEALING_RECEIVED:
            case CRITERIA_TYPE_USE_LFD_TO_GROUP_WITH_PLAYERS:
            case CRITERIA_TYPE_DAMAGE_DONE:
            case CRITERIA_TYPE_HEALING_DONE:
            case CRITERIA_TYPE_HEART_OF_AZEROTH_ARTIFACT_POWER_EARNED:
                SetCriteriaProgress(criteria, miscValue1, referencePlayer, PROGRESS_ACCUMULATE);
                break;
            case CRITERIA_TYPE_KILL_CREATURE:
            case CRITERIA_TYPE_KILL_CREATURE_TYPE:
            case CRITERIA_TYPE_LOOT_TYPE:
            case CRITERIA_TYPE_OWN_ITEM:
            case CRITERIA_TYPE_LOOT_ITEM:
            case CRITERIA_TYPE_CURRENCY:
                SetCriteriaProgress(criteria, miscValue2, referencePlayer, PROGRESS_ACCUMULATE);
                break;
            // std case: high value at miscValue1
            case CRITERIA_TYPE_HIGHEST_AUCTION_BID:
            case CRITERIA_TYPE_HIGHEST_AUCTION_SOLD: /* FIXME: for online player only currently */
            case CRITERIA_TYPE_HIGHEST_HIT_DEALT:
            case CRITERIA_TYPE_HIGHEST_HIT_RECEIVED:
            case CRITERIA_TYPE_HIGHEST_HEAL_CAST:
            case CRITERIA_TYPE_HIGHEST_HEALING_RECEIVED:
            case CRITERIA_TYPE_HEART_OF_AZEROTH_LEVEL_REACHED:
                SetCriteriaProgress(criteria, miscValue1, referencePlayer, PROGRESS_HIGHEST);
                break;
            case CRITERIA_TYPE_REACH_LEVEL:
                SetCriteriaProgress(criteria, referencePlayer->getLevel(), referencePlayer);
                break;
            case CRITERIA_TYPE_REACH_SKILL_LEVEL:
                if (uint32 skillvalue = referencePlayer->GetBaseSkillValue(criteria->Entry->Asset.SkillID))
                    SetCriteriaProgress(criteria, skillvalue, referencePlayer);
                break;
            case CRITERIA_TYPE_LEARN_SKILL_LEVEL:
                if (uint32 maxSkillvalue = referencePlayer->GetPureMaxSkillValue(criteria->Entry->Asset.SkillID))
                    SetCriteriaProgress(criteria, maxSkillvalue, referencePlayer);
                break;
            case CRITERIA_TYPE_COMPLETE_QUEST_COUNT:
                SetCriteriaProgress(criteria, referencePlayer->GetRewardedQuestCount(), referencePlayer);
                break;
            case CRITERIA_TYPE_COMPLETE_DAILY_QUEST_DAILY:
            {
                time_t nextDailyResetTime = sWorld->GetNextDailyQuestsResetTime();
                CriteriaProgress *progress = GetCriteriaProgress(criteria);

                if (!miscValue1) // Login case.
                {
                    // reset if player missed one day.
                    if (progress && progress->Date < (nextDailyResetTime - 2 * DAY))
                        SetCriteriaProgress(criteria, 0, referencePlayer, PROGRESS_SET);
                    continue;
                }

                ProgressType progressType;
                if (!progress)
                    // 1st time. Start count.
                    progressType = PROGRESS_SET;
                else if (progress->Date < (nextDailyResetTime - 2 * DAY))
                    // last progress is older than 2 days. Player missed 1 day => Restart count.
                    progressType = PROGRESS_SET;
                else if (progress->Date < (nextDailyResetTime - DAY))
                    // last progress is between 1 and 2 days. => 1st time of the day.
                    progressType = PROGRESS_ACCUMULATE;
                else
                    // last progress is within the day before the reset => Already counted today.
                    continue;

                SetCriteriaProgress(criteria, 1, referencePlayer, progressType);
                break;
            }
            case CRITERIA_TYPE_COMPLETE_QUESTS_IN_ZONE:
            {
                if (miscValue1)
                {
                    SetCriteriaProgress(criteria, 1, referencePlayer, PROGRESS_ACCUMULATE);
                }
                else // login case
                {
                    uint32 counter = 0;

                    const RewardedQuestSet& rewQuests = referencePlayer->getRewardedQuests();
                    for (RewardedQuestSet::const_iterator itr = rewQuests.begin(); itr != rewQuests.end(); ++itr)
                    {
                        Quest const* quest = sObjectMgr->GetQuestTemplate(*itr);
                        if (quest && quest->GetZoneOrSort() >= 0 && quest->GetZoneOrSort() == criteria->Entry->Asset.ZoneID)
                            ++counter;
                    }
                    SetCriteriaProgress(criteria, counter, referencePlayer, PROGRESS_HIGHEST);
                }
                break;
            }
            case CRITERIA_TYPE_FALL_WITHOUT_DYING:
                // miscValue1 is the ingame fallheight*100 as stored in dbc
                SetCriteriaProgress(criteria, miscValue1, referencePlayer);
                break;
            case CRITERIA_TYPE_COMPLETE_QUEST:
            case CRITERIA_TYPE_LEARN_SPELL:
            case CRITERIA_TYPE_EXPLORE_AREA:
            case CRITERIA_TYPE_VISIT_BARBER_SHOP:
            case CRITERIA_TYPE_EQUIP_EPIC_ITEM:
            case CRITERIA_TYPE_EQUIP_ITEM:
            case CRITERIA_TYPE_COMPLETE_ACHIEVEMENT:
            case CRITERIA_TYPE_RECRUIT_GARRISON_FOLLOWER:
            case CRITERIA_TYPE_OWN_BATTLE_PET:
                SetCriteriaProgress(criteria, 1, referencePlayer);
                break;
            case CRITERIA_TYPE_BUY_BANK_SLOT:
                SetCriteriaProgress(criteria, referencePlayer->GetBankBagSlotCount(), referencePlayer);
                break;
            case CRITERIA_TYPE_GAIN_REPUTATION:
            {
                int32 reputation = referencePlayer->GetReputationMgr().GetReputation(criteria->Entry->Asset.FactionID);
                if (reputation > 0)
                    SetCriteriaProgress(criteria, reputation, referencePlayer);
                break;
            }
            case CRITERIA_TYPE_GAIN_EXALTED_REPUTATION:
                SetCriteriaProgress(criteria, referencePlayer->GetReputationMgr().GetExaltedFactionCount(), referencePlayer);
                break;
            case CRITERIA_TYPE_LEARN_SKILLLINE_SPELLS:
            case CRITERIA_TYPE_LEARN_SKILL_LINE:
            {
                uint32 spellCount = 0;
                for (PlayerSpellMap::const_iterator spellIter = referencePlayer->GetSpellMap().begin();
                    spellIter != referencePlayer->GetSpellMap().end();
                    ++spellIter)
                {
                    SkillLineAbilityMapBounds bounds = sSpellMgr->GetSkillLineAbilityMapBounds(spellIter->first);
                    for (SkillLineAbilityMap::const_iterator skillIter = bounds.first; skillIter != bounds.second; ++skillIter)
                    {
                        if (skillIter->second->SkillLine == int32(criteria->Entry->Asset.SkillID))
                        {
                            // do not add couter twice if by any chance skill is listed twice in dbc (eg. skill 777 and spell 22717)
                            ++spellCount;
                            break;
                        }
                    }
                }
                SetCriteriaProgress(criteria, spellCount, referencePlayer);
                break;
            }
            case CRITERIA_TYPE_GAIN_REVERED_REPUTATION:
                SetCriteriaProgress(criteria, referencePlayer->GetReputationMgr().GetReveredFactionCount(), referencePlayer);
                break;
            case CRITERIA_TYPE_GAIN_HONORED_REPUTATION:
                SetCriteriaProgress(criteria, referencePlayer->GetReputationMgr().GetHonoredFactionCount(), referencePlayer);
                break;
            case CRITERIA_TYPE_KNOWN_FACTIONS:
                SetCriteriaProgress(criteria, referencePlayer->GetReputationMgr().GetVisibleFactionCount(), referencePlayer);
                break;
            case CRITERIA_TYPE_EARN_HONORABLE_KILL:
                SetCriteriaProgress(criteria, referencePlayer->m_activePlayerData->LifetimeHonorableKills, referencePlayer);
                break;
            case CRITERIA_TYPE_HIGHEST_GOLD_VALUE_OWNED:
                SetCriteriaProgress(criteria, referencePlayer->GetMoney(), referencePlayer, PROGRESS_HIGHEST);
                break;
            case CRITERIA_TYPE_EARN_ACHIEVEMENT_POINTS:
                if (!miscValue1)
                    continue;
                SetCriteriaProgress(criteria, miscValue1, referencePlayer, PROGRESS_ACCUMULATE);
                break;
            case CRITERIA_TYPE_HIGHEST_PERSONAL_RATING:
            {
                uint32 reqTeamType = criteria->Entry->Asset.TeamType;

                if (miscValue1)
                {
                    if (miscValue2 != reqTeamType)
                        continue;

                    SetCriteriaProgress(criteria, miscValue1, referencePlayer, PROGRESS_HIGHEST);
                }
                else // login case
                {
                    for (uint8 arena_slot = 0; arena_slot < MAX_ARENA_SLOT; ++arena_slot)
                    {
                        uint32 teamId = referencePlayer->GetArenaTeamId(arena_slot);
                        if (!teamId)
                            continue;

                        ArenaTeam* team = sArenaTeamMgr->GetArenaTeamById(teamId);
                        if (!team || team->GetType() != reqTeamType)
                            continue;

                        if (ArenaTeamMember const* member = team->GetMember(referencePlayer->GetGUID()))
                        {
                            SetCriteriaProgress(criteria, member->PersonalRating, referencePlayer, PROGRESS_HIGHEST);
                            break;
                        }
                    }
                }
                break;
            }
            case CRITERIA_TYPE_REACH_GUILD_LEVEL:
                SetCriteriaProgress(criteria, miscValue1, referencePlayer);
                break;
            // FIXME: not triggered in code as result, need to implement
            case CRITERIA_TYPE_COMPLETE_RAID:
            case CRITERIA_TYPE_PLAY_ARENA:
            case CRITERIA_TYPE_HIGHEST_TEAM_RATING:
            case CRITERIA_TYPE_OWN_RANK:
            case CRITERIA_TYPE_SPENT_GOLD_GUILD_REPAIRS:
            case CRITERIA_TYPE_CRAFT_ITEMS_GUILD:
            case CRITERIA_TYPE_CATCH_FROM_POOL:
            case CRITERIA_TYPE_BUY_GUILD_BANK_SLOTS:
            case CRITERIA_TYPE_EARN_GUILD_ACHIEVEMENT_POINTS:
            case CRITERIA_TYPE_WIN_RATED_BATTLEGROUND:
            case CRITERIA_TYPE_REACH_BG_RATING:
            case CRITERIA_TYPE_BUY_GUILD_TABARD:
            case CRITERIA_TYPE_COMPLETE_QUESTS_GUILD:
            case CRITERIA_TYPE_HONORABLE_KILLS_GUILD:
            case CRITERIA_TYPE_KILL_CREATURE_TYPE_GUILD:
            case CRITERIA_TYPE_COMPLETE_ARCHAEOLOGY_PROJECTS:
            case CRITERIA_TYPE_COMPLETE_GUILD_CHALLENGE_TYPE:
            case CRITERIA_TYPE_COMPLETE_GUILD_CHALLENGE:
            case CRITERIA_TYPE_LFR_DUNGEONS_COMPLETED:
            case CRITERIA_TYPE_LFR_LEAVES:
            case CRITERIA_TYPE_LFR_VOTE_KICKS_INITIATED_BY_PLAYER:
            case CRITERIA_TYPE_LFR_VOTE_KICKS_NOT_INIT_BY_PLAYER:
            case CRITERIA_TYPE_BE_KICKED_FROM_LFR:
            case CRITERIA_TYPE_COUNT_OF_LFR_QUEUE_BOOSTS_BY_TANK:
            case CRITERIA_TYPE_COMPLETE_SCENARIO_COUNT:
            case CRITERIA_TYPE_COMPLETE_SCENARIO:
            case CRITERIA_TYPE_CAPTURE_BATTLE_PET:
            case CRITERIA_TYPE_WIN_PET_BATTLE:
            case CRITERIA_TYPE_LEVEL_BATTLE_PET:
            case CRITERIA_TYPE_CAPTURE_BATTLE_PET_CREDIT:
            case CRITERIA_TYPE_LEVEL_BATTLE_PET_CREDIT:
            case CRITERIA_TYPE_ENTER_AREA:
            case CRITERIA_TYPE_LEAVE_AREA:
            case CRITERIA_TYPE_COMPLETE_DUNGEON_ENCOUNTER:
            case CRITERIA_TYPE_UPGRADE_GARRISON_BUILDING:
            case CRITERIA_TYPE_CONSTRUCT_GARRISON_BUILDING:
            case CRITERIA_TYPE_UPGRADE_GARRISON:
            case CRITERIA_TYPE_START_GARRISON_MISSION:
            case CRITERIA_TYPE_COMPLETE_GARRISON_MISSION_COUNT:
            case CRITERIA_TYPE_COMPLETE_GARRISON_MISSION:
            case CRITERIA_TYPE_RECRUIT_GARRISON_FOLLOWER_COUNT:
            case CRITERIA_TYPE_LEARN_GARRISON_BLUEPRINT_COUNT:
            case CRITERIA_TYPE_COMPLETE_GARRISON_SHIPMENT:
            case CRITERIA_TYPE_RAISE_GARRISON_FOLLOWER_ITEM_LEVEL:
            case CRITERIA_TYPE_RAISE_GARRISON_FOLLOWER_LEVEL:
            case CRITERIA_TYPE_OWN_TOY:
            case CRITERIA_TYPE_OWN_TOY_COUNT:
            case CRITERIA_TYPE_OWN_HEIRLOOMS:
            case CRITERIA_TYPE_SURVEY_GAMEOBJECT:
            case CRITERIA_TYPE_CLEAR_DIGSITE:
            case CRITERIA_TYPE_MANUAL_COMPLETE_CRITERIA:
            case CRITERIA_TYPE_COMPLETE_CHALLENGE_MODE_GUILD:
            case CRITERIA_TYPE_DEFEAT_CREATURE_GROUP:
            case CRITERIA_TYPE_COMPLETE_CHALLENGE_MODE:
            case CRITERIA_TYPE_SEND_EVENT:
            case CRITERIA_TYPE_COOK_RECIPES_GUILD:
            case CRITERIA_TYPE_EARN_PET_BATTLE_ACHIEVEMENT_POINTS:
            case CRITERIA_TYPE_SEND_EVENT_SCENARIO:
            case CRITERIA_TYPE_RELEASE_SPIRIT:
            case CRITERIA_TYPE_OWN_PET:
            case CRITERIA_TYPE_GARRISON_COMPLETE_DUNGEON_ENCOUNTER:
            case CRITERIA_TYPE_COMPLETE_LFG_DUNGEON:
            case CRITERIA_TYPE_LFG_VOTE_KICKS_INITIATED_BY_PLAYER:
            case CRITERIA_TYPE_LFG_VOTE_KICKS_NOT_INIT_BY_PLAYER:
            case CRITERIA_TYPE_BE_KICKED_FROM_LFG:
            case CRITERIA_TYPE_LFG_LEAVES:
            case CRITERIA_TYPE_COUNT_OF_LFG_QUEUE_BOOSTS_BY_TANK:
            case CRITERIA_TYPE_REACH_AREATRIGGER_WITH_ACTIONSET:
            case CRITERIA_TYPE_START_ORDER_HALL_MISSION:
            case CRITERIA_TYPE_RECRUIT_GARRISON_FOLLOWER_WITH_QUALITY:
            case CRITERIA_TYPE_ARTIFACT_POWER_EARNED:
            case CRITERIA_TYPE_ARTIFACT_TRAITS_UNLOCKED:
            case CRITERIA_TYPE_ORDER_HALL_TALENT_LEARNED:
            case CRITERIA_TYPE_ORDER_HALL_RECRUIT_TROOP:
            case CRITERIA_TYPE_COMPLETE_WORLD_QUEST:
            case CRITERIA_TYPE_GAIN_PARAGON_REPUTATION:
            case CRITERIA_TYPE_EARN_HONOR_XP:
            case CRITERIA_TYPE_RELIC_TALENT_UNLOCKED:
            case CRITERIA_TYPE_REACH_ACCOUNT_HONOR_LEVEL:
                break;                                   // Not implemented yet :(
        }

        for (CriteriaTree const* tree : *trees)
        {
            if (IsCompletedCriteriaTree(tree))
                CompletedCriteriaTree(tree, referencePlayer);

            AfterCriteriaTreeUpdate(tree, referencePlayer);
        }
    }
}

void CriteriaHandler::UpdateTimedCriteria(uint32 timeDiff)
{
    if (!_timeCriteriaTrees.empty())
    {
        for (auto itr = _timeCriteriaTrees.begin(); itr != _timeCriteriaTrees.end();)
        {
            // Time is up, remove timer and reset progress
            if (itr->second <= timeDiff)
            {
                CriteriaTree const* criteriaTree = sCriteriaMgr->GetCriteriaTree(itr->first);
                if (criteriaTree->Criteria)
                    RemoveCriteriaProgress(criteriaTree->Criteria);

                itr = _timeCriteriaTrees.erase(itr);
            }
            else
            {
                itr->second -= timeDiff;
                ++itr;
            }
        }
    }
}

void CriteriaHandler::StartCriteriaTimer(CriteriaTimedTypes type, uint32 entry, uint32 timeLost /* = 0 */)
{
    CriteriaList const& criteriaList = sCriteriaMgr->GetTimedCriteriaByType(type);
    for (Criteria const* criteria : criteriaList)
    {
        if (criteria->Entry->StartAsset != int32(entry))
            continue;

        CriteriaTreeList const* trees = sCriteriaMgr->GetCriteriaTreesByCriteria(criteria->ID);
        bool canStart = false;
        for (CriteriaTree const* tree : *trees)
        {
            if (_timeCriteriaTrees.find(tree->ID) == _timeCriteriaTrees.end() && !IsCompletedCriteriaTree(tree))
            {
                // Start the timer
                if (criteria->Entry->StartTimer * uint32(IN_MILLISECONDS) > timeLost)
                {
                    _timeCriteriaTrees[tree->ID] = criteria->Entry->StartTimer * IN_MILLISECONDS - timeLost;
                    canStart = true;
                }
            }
        }

        if (!canStart)
            continue;

        // and at client too
        SetCriteriaProgress(criteria, 0, nullptr, PROGRESS_SET);
    }
}

void CriteriaHandler::RemoveCriteriaTimer(CriteriaTimedTypes type, uint32 entry)
{
    CriteriaList const& criteriaList = sCriteriaMgr->GetTimedCriteriaByType(type);
    for (Criteria const* criteria : criteriaList)
    {
        if (criteria->Entry->StartAsset != int32(entry))
            continue;

        CriteriaTreeList const* trees = sCriteriaMgr->GetCriteriaTreesByCriteria(criteria->ID);
        // Remove the timer from all trees
        for (CriteriaTree const* tree : *trees)
            _timeCriteriaTrees.erase(tree->ID);

        // remove progress
        RemoveCriteriaProgress(criteria);
    }
}

CriteriaProgress* CriteriaHandler::GetCriteriaProgress(Criteria const* entry)
{
    auto iter = _criteriaProgress.find(entry->ID);
    if (iter == _criteriaProgress.end())
        return nullptr;

    return &iter->second;
}

void CriteriaHandler::SetCriteriaProgress(Criteria const* criteria, uint64 changeValue, Player* referencePlayer, ProgressType progressType)
{
    // Don't allow to cheat - doing timed criteria without timer active
    CriteriaTreeList const* trees = nullptr;
    if (criteria->Entry->StartTimer)
    {
        trees = sCriteriaMgr->GetCriteriaTreesByCriteria(criteria->ID);
        if (!trees)
            return;

        bool hasTreeForTimed = false;
        for (CriteriaTree const* tree : *trees)
        {
            auto timedIter = _timeCriteriaTrees.find(tree->ID);
            if (timedIter != _timeCriteriaTrees.end())
            {
                hasTreeForTimed = true;
                break;
            }
        }

        if (!hasTreeForTimed)
            return;
    }

    TC_LOG_DEBUG("criteria", "CriteriaHandler::SetCriteriaProgress(%u, " UI64FMTD ") for %s", criteria->ID, changeValue, GetOwnerInfo().c_str());

    CriteriaProgress* progress = GetCriteriaProgress(criteria);
    if (!progress)
    {
        // not create record for 0 counter but allow it for timed criteria
        // we will need to send 0 progress to client to start the timer
        if (changeValue == 0 && !criteria->Entry->StartTimer)
            return;

        progress = &_criteriaProgress[criteria->ID];
        progress->Counter = changeValue;
    }
    else
    {
        uint64 newValue = 0;
        switch (progressType)
        {
            case PROGRESS_SET:
                newValue = changeValue;
                break;
            case PROGRESS_ACCUMULATE:
            {
                // avoid overflow
                uint64 max_value = std::numeric_limits<uint64>::max();
                newValue = max_value - progress->Counter > changeValue ? progress->Counter + changeValue : max_value;
                break;
            }
            case PROGRESS_HIGHEST:
                newValue = progress->Counter < changeValue ? changeValue : progress->Counter;
                break;
        }

        // not update (not mark as changed) if counter will have same value
        if (progress->Counter == newValue && !criteria->Entry->StartTimer)
            return;

        progress->Counter = newValue;
    }

    progress->Changed = true;
    progress->Date = time(NULL); // set the date to the latest update.
    progress->PlayerGUID = referencePlayer ? referencePlayer->GetGUID() : ObjectGuid::Empty;

    uint32 timeElapsed = 0;

    if (criteria->Entry->StartTimer)
    {
        ASSERT(trees);

        for (CriteriaTree const* tree : *trees)
        {
            auto timedIter = _timeCriteriaTrees.find(tree->ID);
            if (timedIter != _timeCriteriaTrees.end())
            {
                // Client expects this in packet
                timeElapsed = criteria->Entry->StartTimer - (timedIter->second / IN_MILLISECONDS);

                // Remove the timer, we wont need it anymore
                if (IsCompletedCriteriaTree(tree))
                    _timeCriteriaTrees.erase(timedIter);
            }
        }
    }

    SendCriteriaUpdate(criteria, progress, timeElapsed, true);
}

void CriteriaHandler::RemoveCriteriaProgress(Criteria const* criteria)
{
    if (!criteria)
        return;

    auto criteriaProgress = _criteriaProgress.find(criteria->ID);
    if (criteriaProgress == _criteriaProgress.end())
        return;

    SendCriteriaProgressRemoved(criteria->ID);

    _criteriaProgress.erase(criteriaProgress);
}

bool CriteriaHandler::IsCompletedCriteriaTree(CriteriaTree const* tree)
{
    if (!CanCompleteCriteriaTree(tree))
        return false;

    uint64 requiredCount = tree->Entry->Amount;
    switch (tree->Entry->Operator)
    {
        case CRITERIA_TREE_OPERATOR_SINGLE:
            return tree->Criteria && IsCompletedCriteria(tree->Criteria, requiredCount);
        case CRITERIA_TREE_OPERATOR_SINGLE_NOT_COMPLETED:
            return !tree->Criteria || !IsCompletedCriteria(tree->Criteria, requiredCount);
        case CRITERIA_TREE_OPERATOR_ALL:
            for (CriteriaTree const* node : tree->Children)
                if (!IsCompletedCriteriaTree(node))
                    return false;
            return true;
        case CRITERIA_TREE_OPERAROR_SUM_CHILDREN:
        {
            uint64 progress = 0;
            CriteriaMgr::WalkCriteriaTree(tree, [this, &progress](CriteriaTree const* criteriaTree)
            {
                if (criteriaTree->Criteria)
                    if (CriteriaProgress const* criteriaProgress = GetCriteriaProgress(criteriaTree->Criteria))
                        progress += criteriaProgress->Counter;
            });
            return progress >= requiredCount;
        }
        case CRITERIA_TREE_OPERATOR_MAX_CHILD:
        {
            uint64 progress = 0;
            CriteriaMgr::WalkCriteriaTree(tree, [this, &progress](CriteriaTree const* criteriaTree)
            {
                if (criteriaTree->Criteria)
                    if (CriteriaProgress const* criteriaProgress = GetCriteriaProgress(criteriaTree->Criteria))
                        if (criteriaProgress->Counter > progress)
                            progress = criteriaProgress->Counter;
            });
            return progress >= requiredCount;
        }
        case CRITERIA_TREE_OPERATOR_COUNT_DIRECT_CHILDREN:
        {
            uint64 progress = 0;
            for (CriteriaTree const* node : tree->Children)
                if (node->Criteria)
                    if (CriteriaProgress const* criteriaProgress = GetCriteriaProgress(node->Criteria))
                        if (criteriaProgress->Counter >= 1)
                            if (++progress >= requiredCount)
                                return true;

            return false;
        }
        case CRITERIA_TREE_OPERATOR_ANY:
        {
            uint64 progress = 0;
            for (CriteriaTree const* node : tree->Children)
                if (IsCompletedCriteriaTree(node))
                    if (++progress >= requiredCount)
                        return true;

            return false;
        }
        case CRITERIA_TREE_OPERATOR_SUM_CHILDREN_WEIGHT:
        {
            uint64 progress = 0;
            CriteriaMgr::WalkCriteriaTree(tree, [this, &progress](CriteriaTree const* criteriaTree)
            {
                if (criteriaTree->Criteria)
                    if (CriteriaProgress const* criteriaProgress = GetCriteriaProgress(criteriaTree->Criteria))
                        progress += criteriaProgress->Counter * criteriaTree->Entry->Amount;
            });
            return progress >= requiredCount;
        }
        default:
            break;
    }

    return false;
}

bool CriteriaHandler::CanUpdateCriteriaTree(Criteria const* criteria, CriteriaTree const* tree, Player* referencePlayer) const
{
    if ((tree->Entry->Flags & CRITERIA_TREE_FLAG_HORDE_ONLY && referencePlayer->GetTeam() != HORDE) ||
        (tree->Entry->Flags & CRITERIA_TREE_FLAG_ALLIANCE_ONLY && referencePlayer->GetTeam() != ALLIANCE))
    {
        TC_LOG_TRACE("criteria", "CriteriaHandler::CanUpdateCriteriaTree: (Id: %u Type %s CriteriaTree %u) Wrong faction",
            criteria->ID, CriteriaMgr::GetCriteriaTypeString(criteria->Entry->Type), tree->Entry->ID);
        return false;
    }

    return true;
}

bool CriteriaHandler::CanCompleteCriteriaTree(CriteriaTree const* /*tree*/)
{
    return true;
}

bool CriteriaHandler::IsCompletedCriteria(Criteria const* criteria, uint64 requiredAmount)
{
    CriteriaProgress const* progress = GetCriteriaProgress(criteria);
    if (!progress)
        return false;

    switch (CriteriaTypes(criteria->Entry->Type))
    {
        case CRITERIA_TYPE_WIN_BG:
        case CRITERIA_TYPE_KILL_CREATURE:
        case CRITERIA_TYPE_REACH_LEVEL:
        case CRITERIA_TYPE_REACH_GUILD_LEVEL:
        case CRITERIA_TYPE_REACH_SKILL_LEVEL:
        case CRITERIA_TYPE_COMPLETE_QUEST_COUNT:
        case CRITERIA_TYPE_COMPLETE_DAILY_QUEST_DAILY:
        case CRITERIA_TYPE_COMPLETE_QUESTS_IN_ZONE:
        case CRITERIA_TYPE_DAMAGE_DONE:
        case CRITERIA_TYPE_HEALING_DONE:
        case CRITERIA_TYPE_COMPLETE_DAILY_QUEST:
        case CRITERIA_TYPE_FALL_WITHOUT_DYING:
        case CRITERIA_TYPE_BE_SPELL_TARGET:
        case CRITERIA_TYPE_BE_SPELL_TARGET2:
        case CRITERIA_TYPE_CAST_SPELL:
        case CRITERIA_TYPE_CAST_SPELL2:
        case CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE:
        case CRITERIA_TYPE_HONORABLE_KILL_AT_AREA:
        case CRITERIA_TYPE_HONORABLE_KILL:
        case CRITERIA_TYPE_EARN_HONORABLE_KILL:
        case CRITERIA_TYPE_OWN_ITEM:
        case CRITERIA_TYPE_WIN_RATED_ARENA:
        case CRITERIA_TYPE_HIGHEST_PERSONAL_RATING:
        case CRITERIA_TYPE_USE_ITEM:
        case CRITERIA_TYPE_LOOT_ITEM:
        case CRITERIA_TYPE_BUY_BANK_SLOT:
        case CRITERIA_TYPE_GAIN_REPUTATION:
        case CRITERIA_TYPE_GAIN_EXALTED_REPUTATION:
        case CRITERIA_TYPE_VISIT_BARBER_SHOP:
        case CRITERIA_TYPE_EQUIP_EPIC_ITEM:
        case CRITERIA_TYPE_ROLL_NEED_ON_LOOT:
        case CRITERIA_TYPE_ROLL_GREED_ON_LOOT:
        case CRITERIA_TYPE_HK_CLASS:
        case CRITERIA_TYPE_HK_RACE:
        case CRITERIA_TYPE_DO_EMOTE:
        case CRITERIA_TYPE_EQUIP_ITEM:
        case CRITERIA_TYPE_MONEY_FROM_QUEST_REWARD:
        case CRITERIA_TYPE_LOOT_MONEY:
        case CRITERIA_TYPE_USE_GAMEOBJECT:
        case CRITERIA_TYPE_SPECIAL_PVP_KILL:
        case CRITERIA_TYPE_FISH_IN_GAMEOBJECT:
        case CRITERIA_TYPE_LEARN_SKILLLINE_SPELLS:
        case CRITERIA_TYPE_WIN_DUEL:
        case CRITERIA_TYPE_LOOT_TYPE:
        case CRITERIA_TYPE_LEARN_SKILL_LINE:
        case CRITERIA_TYPE_USE_LFD_TO_GROUP_WITH_PLAYERS:
        case CRITERIA_TYPE_GET_KILLING_BLOWS:
        case CRITERIA_TYPE_CURRENCY:
        case CRITERIA_TYPE_PLACE_GARRISON_BUILDING:
        case CRITERIA_TYPE_OWN_BATTLE_PET_COUNT:
        case CRITERIA_TYPE_APPEARANCE_UNLOCKED_BY_SLOT:
        case CRITERIA_TYPE_GAIN_PARAGON_REPUTATION:
        case CRITERIA_TYPE_EARN_HONOR_XP:
        case CRITERIA_TYPE_RELIC_TALENT_UNLOCKED:
        case CRITERIA_TYPE_REACH_ACCOUNT_HONOR_LEVEL:
        case CRITERIA_TYPE_HEART_OF_AZEROTH_ARTIFACT_POWER_EARNED:
        case CRITERIA_TYPE_HEART_OF_AZEROTH_LEVEL_REACHED:
            return progress->Counter >= requiredAmount;
        case CRITERIA_TYPE_COMPLETE_ACHIEVEMENT:
        case CRITERIA_TYPE_COMPLETE_QUEST:
        case CRITERIA_TYPE_LEARN_SPELL:
        case CRITERIA_TYPE_EXPLORE_AREA:
        case CRITERIA_TYPE_RECRUIT_GARRISON_FOLLOWER:
        case CRITERIA_TYPE_OWN_BATTLE_PET:
        case CRITERIA_TYPE_HONOR_LEVEL_REACHED:
        case CRITERIA_TYPE_PRESTIGE_REACHED:
        case CRITERIA_TYPE_TRANSMOG_SET_UNLOCKED:
            return progress->Counter >= 1;
        case CRITERIA_TYPE_LEARN_SKILL_LEVEL:
            return progress->Counter >= (requiredAmount * 75);
        case CRITERIA_TYPE_EARN_ACHIEVEMENT_POINTS:
            return progress->Counter >= 9000;
        case CRITERIA_TYPE_WIN_ARENA:
            return requiredAmount && progress->Counter >= requiredAmount;
        case CRITERIA_TYPE_ON_LOGIN:
            return true;
        // handle all statistic-only criteria here
        case CRITERIA_TYPE_COMPLETE_BATTLEGROUND:
        case CRITERIA_TYPE_DEATH_AT_MAP:
        case CRITERIA_TYPE_DEATH:
        case CRITERIA_TYPE_DEATH_IN_DUNGEON:
        case CRITERIA_TYPE_KILLED_BY_CREATURE:
        case CRITERIA_TYPE_KILLED_BY_PLAYER:
        case CRITERIA_TYPE_DEATHS_FROM:
        case CRITERIA_TYPE_HIGHEST_TEAM_RATING:
        case CRITERIA_TYPE_MONEY_FROM_VENDORS:
        case CRITERIA_TYPE_GOLD_SPENT_FOR_TALENTS:
        case CRITERIA_TYPE_NUMBER_OF_TALENT_RESETS:
        case CRITERIA_TYPE_GOLD_SPENT_AT_BARBER:
        case CRITERIA_TYPE_GOLD_SPENT_FOR_MAIL:
        case CRITERIA_TYPE_LOSE_DUEL:
        case CRITERIA_TYPE_KILL_CREATURE_TYPE:
        case CRITERIA_TYPE_GOLD_EARNED_BY_AUCTIONS:
        case CRITERIA_TYPE_CREATE_AUCTION:
        case CRITERIA_TYPE_HIGHEST_AUCTION_BID:
        case CRITERIA_TYPE_HIGHEST_AUCTION_SOLD:
        case CRITERIA_TYPE_HIGHEST_GOLD_VALUE_OWNED:
        case CRITERIA_TYPE_WON_AUCTIONS:
        case CRITERIA_TYPE_GAIN_REVERED_REPUTATION:
        case CRITERIA_TYPE_GAIN_HONORED_REPUTATION:
        case CRITERIA_TYPE_KNOWN_FACTIONS:
        case CRITERIA_TYPE_LOOT_EPIC_ITEM:
        case CRITERIA_TYPE_RECEIVE_EPIC_ITEM:
        case CRITERIA_TYPE_ROLL_NEED:
        case CRITERIA_TYPE_ROLL_GREED:
        case CRITERIA_TYPE_QUEST_ABANDONED:
        case CRITERIA_TYPE_FLIGHT_PATHS_TAKEN:
        case CRITERIA_TYPE_ACCEPTED_SUMMONINGS:
        default:
            break;
    }

    return false;
}

bool CriteriaHandler::CanUpdateCriteria(Criteria const* criteria, CriteriaTreeList const* trees, uint64 miscValue1, uint64 miscValue2, uint64 miscValue3, Unit const* unit, Player* referencePlayer)
{
    if (DisableMgr::IsDisabledFor(DISABLE_TYPE_CRITERIA, criteria->ID, nullptr))
    {
        TC_LOG_TRACE("criteria", "CriteriaHandler::CanUpdateCriteria: (Id: %u Type %s) Disabled", criteria->ID, CriteriaMgr::GetCriteriaTypeString(criteria->Entry->Type));
        return false;
    }

    bool treeRequirementPassed = false;
    for (CriteriaTree const* tree : *trees)
    {
        if (!CanUpdateCriteriaTree(criteria, tree, referencePlayer))
            continue;

        treeRequirementPassed = true;
        break;
    }

    if (!treeRequirementPassed)
        return false;

    if (!RequirementsSatisfied(criteria, miscValue1, miscValue2, miscValue3, unit, referencePlayer))
    {
        TC_LOG_TRACE("criteria", "CriteriaHandler::CanUpdateCriteria: (Id: %u Type %s) Requirements not satisfied", criteria->ID, CriteriaMgr::GetCriteriaTypeString(criteria->Entry->Type));
        return false;
    }

    if (criteria->Modifier && !ModifierTreeSatisfied(criteria->Modifier, miscValue1, miscValue2, unit, referencePlayer))
    {
        TC_LOG_TRACE("criteria", "CriteriaHandler::CanUpdateCriteria: (Id: %u Type %s) Requirements have not been satisfied", criteria->ID, CriteriaMgr::GetCriteriaTypeString(criteria->Entry->Type));
        return false;
    }

    if (!ConditionsSatisfied(criteria, referencePlayer))
    {
        TC_LOG_TRACE("criteria", "CriteriaHandler::CanUpdateCriteria: (Id: %u Type %s) Conditions have not been satisfied", criteria->ID, CriteriaMgr::GetCriteriaTypeString(criteria->Entry->Type));
        return false;
    }

    return true;
}

bool CriteriaHandler::ConditionsSatisfied(Criteria const* criteria, Player* referencePlayer) const
{
    if (!criteria->Entry->FailEvent)
        return true;

    switch (criteria->Entry->FailEvent)
    {
        case CRITERIA_CONDITION_BG_MAP:
            if (!referencePlayer->InBattleground())
                return false;
            break;
        case CRITERIA_CONDITION_NOT_IN_GROUP:
            if (referencePlayer->GetGroup())
                return false;
            break;
        default:
            break;
    }

    return true;
}

bool CriteriaHandler::RequirementsSatisfied(Criteria const* criteria, uint64 miscValue1, uint64 miscValue2, uint64 miscValue3, Unit const* unit, Player* referencePlayer) const
{
    switch (CriteriaTypes(criteria->Entry->Type))
    {
        case CRITERIA_TYPE_ACCEPTED_SUMMONINGS:
        case CRITERIA_TYPE_COMPLETE_DAILY_QUEST:
        case CRITERIA_TYPE_CREATE_AUCTION:
        case CRITERIA_TYPE_FALL_WITHOUT_DYING:
        case CRITERIA_TYPE_FLIGHT_PATHS_TAKEN:
        case CRITERIA_TYPE_GET_KILLING_BLOWS:
        case CRITERIA_TYPE_GOLD_EARNED_BY_AUCTIONS:
        case CRITERIA_TYPE_GOLD_SPENT_AT_BARBER:
        case CRITERIA_TYPE_GOLD_SPENT_FOR_MAIL:
        case CRITERIA_TYPE_GOLD_SPENT_FOR_TALENTS:
        case CRITERIA_TYPE_GOLD_SPENT_FOR_TRAVELLING:
        case CRITERIA_TYPE_HIGHEST_AUCTION_BID:
        case CRITERIA_TYPE_HIGHEST_AUCTION_SOLD:
        case CRITERIA_TYPE_HIGHEST_HEALING_RECEIVED:
        case CRITERIA_TYPE_HIGHEST_HEAL_CAST:
        case CRITERIA_TYPE_HIGHEST_HIT_DEALT:
        case CRITERIA_TYPE_HIGHEST_HIT_RECEIVED:
        case CRITERIA_TYPE_HONORABLE_KILL:
        case CRITERIA_TYPE_LOOT_MONEY:
        case CRITERIA_TYPE_LOSE_DUEL:
        case CRITERIA_TYPE_MONEY_FROM_QUEST_REWARD:
        case CRITERIA_TYPE_MONEY_FROM_VENDORS:
        case CRITERIA_TYPE_NUMBER_OF_TALENT_RESETS:
        case CRITERIA_TYPE_QUEST_ABANDONED:
        case CRITERIA_TYPE_REACH_GUILD_LEVEL:
        case CRITERIA_TYPE_ROLL_GREED:
        case CRITERIA_TYPE_ROLL_NEED:
        case CRITERIA_TYPE_SPECIAL_PVP_KILL:
        case CRITERIA_TYPE_TOTAL_DAMAGE_RECEIVED:
        case CRITERIA_TYPE_TOTAL_HEALING_RECEIVED:
        case CRITERIA_TYPE_USE_LFD_TO_GROUP_WITH_PLAYERS:
        case CRITERIA_TYPE_VISIT_BARBER_SHOP:
        case CRITERIA_TYPE_WIN_DUEL:
        case CRITERIA_TYPE_WIN_RATED_ARENA:
        case CRITERIA_TYPE_WON_AUCTIONS:
            if (!miscValue1)
                return false;
            break;
        case CRITERIA_TYPE_BUY_BANK_SLOT:
        case CRITERIA_TYPE_COMPLETE_DAILY_QUEST_DAILY:
        case CRITERIA_TYPE_COMPLETE_QUEST_COUNT:
        case CRITERIA_TYPE_EARN_ACHIEVEMENT_POINTS:
        case CRITERIA_TYPE_GAIN_EXALTED_REPUTATION:
        case CRITERIA_TYPE_GAIN_HONORED_REPUTATION:
        case CRITERIA_TYPE_GAIN_REVERED_REPUTATION:
        case CRITERIA_TYPE_HIGHEST_GOLD_VALUE_OWNED:
        case CRITERIA_TYPE_HIGHEST_PERSONAL_RATING:
        case CRITERIA_TYPE_KNOWN_FACTIONS:
        case CRITERIA_TYPE_REACH_LEVEL:
        case CRITERIA_TYPE_ON_LOGIN:
            break;
        case CRITERIA_TYPE_COMPLETE_ACHIEVEMENT:
            if (!RequiredAchievementSatisfied(criteria->Entry->Asset.AchievementID))
                return false;
            break;
        case CRITERIA_TYPE_WIN_BG:
        case CRITERIA_TYPE_COMPLETE_BATTLEGROUND:
        case CRITERIA_TYPE_DEATH_AT_MAP:
            if (!miscValue1 || uint32(criteria->Entry->Asset.MapID) != referencePlayer->GetMapId())
                return false;
            break;
        case CRITERIA_TYPE_KILL_CREATURE:
        case CRITERIA_TYPE_KILLED_BY_CREATURE:
            if (!miscValue1 || uint32(criteria->Entry->Asset.CreatureID) != miscValue1)
                return false;
            break;
        case CRITERIA_TYPE_REACH_SKILL_LEVEL:
        case CRITERIA_TYPE_LEARN_SKILL_LEVEL:
            // update at loading or specific skill update
            if (miscValue1 && miscValue1 != uint32(criteria->Entry->Asset.SkillID))
                return false;
            break;
        case CRITERIA_TYPE_COMPLETE_QUESTS_IN_ZONE:
            if (miscValue1)
            {
                Quest const* quest = sObjectMgr->GetQuestTemplate(miscValue1);
                if (!quest ||  quest->GetZoneOrSort() != criteria->Entry->Asset.ZoneID)
                    return false;
            }
            break;
        case CRITERIA_TYPE_DEATH:
        {
            if (!miscValue1)
                return false;
            break;
        }
        case CRITERIA_TYPE_DEATH_IN_DUNGEON:
        {
            if (!miscValue1)
                return false;

            Map const* map = referencePlayer->IsInWorld() ? referencePlayer->GetMap() : sMapMgr->FindMap(referencePlayer->GetMapId(), referencePlayer->GetInstanceId());
            if (!map || !map->IsDungeon())
                return false;

            //FIXME: work only for instances where max == min for players
            if (map->ToInstanceMap()->GetMaxPlayers() != uint32(criteria->Entry->Asset.GroupSize))
                return false;
            break;
        }
        case CRITERIA_TYPE_KILLED_BY_PLAYER:
            if (!miscValue1 || !unit || unit->GetTypeId() != TYPEID_PLAYER)
                return false;
            break;
        case CRITERIA_TYPE_DEATHS_FROM:
            if (!miscValue1 || miscValue2 != uint32(criteria->Entry->Asset.DamageType))
                return false;
            break;
        case CRITERIA_TYPE_COMPLETE_QUEST:
        {
            // if miscValues != 0, it contains the questID.
            if (miscValue1)
            {
                if (miscValue1 != uint32(criteria->Entry->Asset.QuestID))
                    return false;
            }
            else
            {
                // login case.
                if (!referencePlayer->GetQuestRewardStatus(criteria->Entry->Asset.QuestID))
                    return false;
            }

            if (CriteriaDataSet const* data = sCriteriaMgr->GetCriteriaDataSet(criteria))
                if (!data->Meets(referencePlayer, unit))
                    return false;
            break;
        }
        case CRITERIA_TYPE_BE_SPELL_TARGET:
        case CRITERIA_TYPE_BE_SPELL_TARGET2:
        case CRITERIA_TYPE_CAST_SPELL:
        case CRITERIA_TYPE_CAST_SPELL2:
            if (!miscValue1 || miscValue1 != uint32(criteria->Entry->Asset.SpellID))
                return false;
            break;
        case CRITERIA_TYPE_LEARN_SPELL:
            if (miscValue1 && miscValue1 != uint32(criteria->Entry->Asset.SpellID))
                return false;

            if (!referencePlayer->HasSpell(criteria->Entry->Asset.SpellID))
                return false;
            break;
        case CRITERIA_TYPE_LOOT_TYPE:
            // miscValue1 = itemId - miscValue2 = count of item loot
            // miscValue3 = loot_type (note: 0 = LOOT_CORPSE and then it ignored)
            if (!miscValue1 || !miscValue2 || !miscValue3 || miscValue3 != uint32(criteria->Entry->Asset.LootType))
                return false;
            break;
        case CRITERIA_TYPE_OWN_ITEM:
            if (miscValue1 && uint32(criteria->Entry->Asset.ItemID) != miscValue1)
                return false;
            break;
        case CRITERIA_TYPE_USE_ITEM:
        case CRITERIA_TYPE_LOOT_ITEM:
        case CRITERIA_TYPE_EQUIP_ITEM:
            if (!miscValue1 || uint32(criteria->Entry->Asset.ItemID )!= miscValue1)
                return false;
            break;
        case CRITERIA_TYPE_EXPLORE_AREA:
        {
            WorldMapOverlayEntry const* worldOverlayEntry = sWorldMapOverlayStore.LookupEntry(criteria->Entry->Asset.WorldMapOverlayID);
            if (!worldOverlayEntry)
                break;

            bool matchFound = false;
            for (int j = 0; j < MAX_WORLD_MAP_OVERLAY_AREA_IDX; ++j)
            {
                AreaTableEntry const* area = sAreaTableStore.LookupEntry(worldOverlayEntry->AreaID[j]);
                if (!area)
                    break;

                if (area->AreaBit < 0)
                    continue;

                uint16 playerIndexOffset = uint16(uint32(area->AreaBit) / 64);
                if (playerIndexOffset >= PLAYER_EXPLORED_ZONES_SIZE)
                    continue;

                uint64 mask = uint64(1) << (area->AreaBit % 64);
                if (referencePlayer->m_activePlayerData->ExploredZones[playerIndexOffset] & mask)
                {
                    matchFound = true;
                    break;
                }
            }

            if (!matchFound)
                return false;
            break;
        }
        case CRITERIA_TYPE_GAIN_REPUTATION:
            if (miscValue1 && miscValue1 != uint32(criteria->Entry->Asset.FactionID))
                return false;
            break;
        case CRITERIA_TYPE_EQUIP_EPIC_ITEM:
            // miscValue1 = itemSlot miscValue2 = itemid
            if (!miscValue2 || miscValue1 != uint32(criteria->Entry->Asset.ItemSlot))
                return false;
            break;
        case CRITERIA_TYPE_ROLL_NEED_ON_LOOT:
        case CRITERIA_TYPE_ROLL_GREED_ON_LOOT:
        {
            // miscValue1 = itemid miscValue2 = diced value
            if (!miscValue1 || miscValue2 != uint32(criteria->Entry->Asset.RollValue))
                return false;

            ItemTemplate const* proto = sObjectMgr->GetItemTemplate(uint32(miscValue1));
            if (!proto)
                return false;
            break;
        }
        case CRITERIA_TYPE_DO_EMOTE:
            if (!miscValue1 || miscValue1 != uint32(criteria->Entry->Asset.EmoteID))
                return false;
            break;
        case CRITERIA_TYPE_DAMAGE_DONE:
        case CRITERIA_TYPE_HEALING_DONE:
            if (!miscValue1)
                return false;

            if (criteria->Entry->FailEvent == CRITERIA_CONDITION_BG_MAP)
            {
                if (!referencePlayer->InBattleground())
                    return false;

                // map specific case (BG in fact) expected player targeted damage/heal
                if (!unit || unit->GetTypeId() != TYPEID_PLAYER)
                    return false;
            }
            break;
        case CRITERIA_TYPE_USE_GAMEOBJECT:
        case CRITERIA_TYPE_FISH_IN_GAMEOBJECT:
            if (!miscValue1 || miscValue1 != uint32(criteria->Entry->Asset.GameObjectID))
                return false;
            break;
        case CRITERIA_TYPE_LEARN_SKILLLINE_SPELLS:
        case CRITERIA_TYPE_LEARN_SKILL_LINE:
            if (miscValue1 && miscValue1 != uint32(criteria->Entry->Asset.SkillID))
                return false;
            break;
        case CRITERIA_TYPE_LOOT_EPIC_ITEM:
        case CRITERIA_TYPE_RECEIVE_EPIC_ITEM:
        {
            if (!miscValue1)
                return false;
            ItemTemplate const* proto = sObjectMgr->GetItemTemplate(uint32(miscValue1));
            if (!proto || proto->GetQuality() < ITEM_QUALITY_EPIC)
                return false;
            break;
        }
        case CRITERIA_TYPE_HK_CLASS:
            if (!miscValue1 || miscValue1 != uint32(criteria->Entry->Asset.ClassID))
                return false;
            break;
        case CRITERIA_TYPE_HK_RACE:
            if (!miscValue1 || miscValue1 != uint32(criteria->Entry->Asset.RaceID))
                return false;
            break;
        case CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE:
            if (!miscValue1 || miscValue1 != uint32(criteria->Entry->Asset.ObjectiveId))
                return false;
            break;
        case CRITERIA_TYPE_HONORABLE_KILL_AT_AREA:
            if (!miscValue1 || miscValue1 != uint32(criteria->Entry->Asset.AreaID))
                return false;
            break;
        case CRITERIA_TYPE_CURRENCY:
            if (!miscValue1 || !miscValue2 || int64(miscValue2) < 0
                || miscValue1 != uint32(criteria->Entry->Asset.CurrencyID))
                return false;
            break;
        case CRITERIA_TYPE_WIN_ARENA:
            if (miscValue1 != uint32(criteria->Entry->Asset.MapID))
                return false;
            break;
        case CRITERIA_TYPE_HIGHEST_TEAM_RATING:
            return false;
        case CRITERIA_TYPE_PLACE_GARRISON_BUILDING:
            if (miscValue1 != uint32(criteria->Entry->Asset.GarrBuildingID))
                return false;
            break;
        case CRITERIA_TYPE_TRANSMOG_SET_UNLOCKED:
            if (miscValue1 != uint32(criteria->Entry->Asset.TransmogSetGroupID))
                return false;
            break;
        case CRITERIA_TYPE_APPEARANCE_UNLOCKED_BY_SLOT:
            if (!miscValue2 /*login case*/ || miscValue1 != uint32(criteria->Entry->Asset.EquipmentSlot))
                return false;
            break;
        default:
            break;
    }
    return true;
}

bool CriteriaHandler::ModifierTreeSatisfied(ModifierTreeNode const* tree, uint64 miscValue1, uint64 miscValue2, Unit const* unit, Player* referencePlayer) const
{
    switch (ModifierTreeOperator(tree->Entry->Operator))
    {
        case ModifierTreeOperator::SingleTrue:
            return tree->Entry->Type && ModifierSatisfied(tree->Entry, miscValue1, miscValue2, unit, referencePlayer);
        case ModifierTreeOperator::SingleFalse:
            return tree->Entry->Type && !ModifierSatisfied(tree->Entry, miscValue1, miscValue2, unit, referencePlayer);
        case ModifierTreeOperator::All:
            for (ModifierTreeNode const* node : tree->Children)
                if (!ModifierTreeSatisfied(node, miscValue1, miscValue2, unit, referencePlayer))
                    return false;
            return true;
        case ModifierTreeOperator::Some:
        {
            int8 requiredAmount = std::max<int8>(tree->Entry->Amount, 1);
            for (ModifierTreeNode const* node : tree->Children)
                if (ModifierTreeSatisfied(node, miscValue1, miscValue2, unit, referencePlayer))
                    if (!--requiredAmount)
                        return true;

            return false;
        }
        default:
            break;
    }

    return false;
}

bool CriteriaHandler::ModifierSatisfied(ModifierTreeEntry const* modifier, uint64 miscValue1, uint64 miscValue2, Unit const* unit, Player* referencePlayer) const
{
    uint32 reqValue = modifier->Asset;
    uint32 secondaryAsset = modifier->SecondaryAsset;
    uint32 tertiaryAsset = modifier->TertiaryAsset;

    switch (CriteriaAdditionalCondition(modifier->Type))
    {
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_DRUNK_VALUE: // 1
        {
            uint32 inebriation = std::min(std::max<uint32>(referencePlayer->GetDrunkValue(), *referencePlayer->m_playerData->FakeInebriation), 100u);
            if (inebriation < reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_PLAYER_CONDITION: // 2
        {
            PlayerConditionEntry const* playerCondition = sPlayerConditionStore.LookupEntry(reqValue);
            if (!playerCondition || !ConditionMgr::IsPlayerMeetingCondition(referencePlayer, playerCondition))
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_ITEM_LEVEL: // 3
        {
            // miscValue1 is itemid
            ItemTemplate const* const item = sObjectMgr->GetItemTemplate(uint32(miscValue1));
            if (!item || item->GetBaseItemLevel() < reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_CREATURE_ENTRY: // 4
            if (!unit || unit->GetEntry() != reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_MUST_BE_PLAYER: // 5
            if (!unit || unit->GetTypeId() != TYPEID_PLAYER)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_MUST_BE_DEAD: // 6
            if (!unit || unit->IsAlive())
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_MUST_BE_ENEMY: // 7
            if (!unit || !referencePlayer->IsHostileTo(unit))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_HAS_AURA: // 8
            if (!referencePlayer->HasAura(reqValue))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_HAS_AURA_TYPE: // 9
            if (!referencePlayer->HasAuraType(AuraType(reqValue)))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_HAS_AURA: // 10
            if (!unit || !unit->HasAura(reqValue))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_HAS_AURA_TYPE: // 11
            if (!unit || !unit->HasAuraType(AuraType(reqValue)))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_AURA_STATE: // 12
            if (!referencePlayer->HasAuraState(AuraStateType(reqValue)))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_AURA_STATE: // 13
            if (!unit || !unit->HasAuraState(AuraStateType(reqValue)))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_ITEM_QUALITY_MIN: // 14
        {
            // miscValue1 is itemid
            ItemTemplate const* const item = sObjectMgr->GetItemTemplate(uint32(miscValue1));
            if (!item || item->GetQuality() < reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_ITEM_QUALITY_EQUALS: // 15
        {
            // miscValue1 is itemid
            ItemTemplate const* const item = sObjectMgr->GetItemTemplate(uint32(miscValue1));
            if (!item || item->GetQuality() != reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_IS_ALIVE: // 16
            if (referencePlayer->isDead())
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_AREA_OR_ZONE: // 17
        {
            uint32 zoneId, areaId;
            referencePlayer->GetZoneAndAreaId(zoneId, areaId);
            if (zoneId != reqValue && areaId != reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_AREA_OR_ZONE: // 18
        {
            if (!unit)
                return false;
            uint32 zoneId, areaId;
            unit->GetZoneAndAreaId(zoneId, areaId);
            if (zoneId != reqValue && areaId != reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_MAP_DIFFICULTY_OLD: // 20
        {
            DifficultyEntry const* difficulty = sDifficultyStore.LookupEntry(referencePlayer->GetMap()->GetDifficultyID());
            if (!difficulty || difficulty->OldEnumValue == -1 || uint32(difficulty->OldEnumValue) != reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_LEVEL_ABOVE_TARGET: // 22
            if (!unit || referencePlayer->getLevel() + reqValue < unit->getLevel())
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_LEVEL_EQUAL_TARGET: // 23
            if (!unit || referencePlayer->getLevel() != unit->getLevel())
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_ARENA_TYPE: // 24
        {
            Battleground* bg = referencePlayer->GetBattleground();
            if (!bg || !bg->isArena() || bg->GetArenaType() != reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_RACE: // 25
            if (referencePlayer->getRace() != reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_CLASS: // 26
            if (referencePlayer->getClass() != reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_RACE: // 27
            if (!unit || unit->GetTypeId() != TYPEID_PLAYER || unit->getRace() != reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_CLASS: // 28
            if (!unit || unit->GetTypeId() != TYPEID_PLAYER || unit->getClass() != reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_MAX_GROUP_MEMBERS: // 29
            if (referencePlayer->GetGroup() && referencePlayer->GetGroup()->GetMembersCount() >= reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_CREATURE_TYPE: // 30
        {
            if (!unit)
                return false;
            if (unit->GetTypeId() != TYPEID_UNIT || unit->GetCreatureType() != reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_CREATURE_FAMILY: // 31
        {
            if (!unit)
                return false;
            if (unit->GetTypeId() != TYPEID_UNIT || unit->ToCreature()->GetCreatureTemplate()->family != CreatureFamily(reqValue))
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_MAP: // 32
            if (referencePlayer->GetMapId() != reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_CLIENT_VERSION: // 33
            if (reqValue < sRealmList->GetMinorMajorBugfixVersionForBuild(realm.Build))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_BATTLE_PET_TEAM_LEVEL: // 34
            for (WorldPackets::BattlePet::BattlePetSlot const& slot : referencePlayer->GetSession()->GetBattlePetMgr()->GetSlots())
                if (slot.Pet.Level != reqValue)
                    return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_NOT_IN_GROUP: // 35
            if (referencePlayer->GetGroup())
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_IN_GROUP: // 36
            if (!referencePlayer->GetGroup())
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_TITLE_BIT_INDEX: // 38
            // miscValue1 is title's bit index
            if (miscValue1 != reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_LEVEL: // 39
            if (referencePlayer->getLevel() != reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_LEVEL: // 40
            if (!unit || unit->GetLevelForTarget(referencePlayer) != reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_ZONE: // 41
        {
            uint32 zoneId = referencePlayer->GetAreaId();
            if (AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(zoneId))
                if (areaEntry->Flags[0] & AREA_FLAG_UNK9)
                    zoneId = areaEntry->ParentAreaID;
            if (zoneId != reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_ZONE: // 42
        {
            if (!unit)
                return false;
            uint32 zoneId = unit->GetAreaId();
            if (AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(zoneId))
                if (areaEntry->Flags[0] & AREA_FLAG_UNK9)
                    zoneId = areaEntry->ParentAreaID;
            if (zoneId != reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_HEALTH_PCT_LOWER: // 43
            if (referencePlayer->GetHealthPct() > float(reqValue))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_HEALTH_PCT_GREATER: // 44
            if (referencePlayer->GetHealthPct() < float(reqValue))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_HEALTH_PCT_EQUAL: // 45
            if (referencePlayer->GetHealthPct() != float(reqValue))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_HEALTH_PCT_LOWER: // 46
            if (!unit || unit->GetHealthPct() > float(reqValue))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_HEALTH_PCT_GREATER: // 47
            if (!unit || unit->GetHealthPct() < float(reqValue))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_HEALTH_PCT_EQUAL: // 48
            if (!unit || unit->GetHealthPct() != float(reqValue))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_HEALTH_LOWER: // 49
            if (referencePlayer->GetHealth() > reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_HEALTH_GREATER: // 50
            if (referencePlayer->GetHealth() < reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_HEALTH_EQUAL: // 51
            if (referencePlayer->GetHealth() != reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_HEALTH_LOWER: // 52
            if (!unit || unit->GetHealth() > reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_HEALTH_GREATER: // 53
            if (!unit || unit->GetHealth() < reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_HEALTH_EQUAL: // 54
            if (!unit || unit->GetHealth() != reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_PLAYER_CONDITION: // 55
        {
            if (!unit || !unit->IsPlayer())
                return false;

            PlayerConditionEntry const* playerCondition = sPlayerConditionStore.LookupEntry(reqValue);
            if (!playerCondition || !ConditionMgr::IsPlayerMeetingCondition(unit->ToPlayer(), playerCondition))
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_MIN_ACHIEVEMENT_POINTS: // 56
            if (referencePlayer->GetAchievementPoints() <= reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_IN_LFG_DUNGEON: // 57
            if (!ConditionMgr::GetPlayerConditionLfgValue(referencePlayer, PlayerConditionLfgStatus::InLFGDungeon))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_IN_LFG_RANDOM_DUNGEON: // 58
            if (!ConditionMgr::GetPlayerConditionLfgValue(referencePlayer, PlayerConditionLfgStatus::InLFGRandomDungeon))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_IN_LFG_FIRST_RANDOM_DUNGEON: // 59
            if (!ConditionMgr::GetPlayerConditionLfgValue(referencePlayer, PlayerConditionLfgStatus::InLFGFirstRandomDungeon))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_GUILD_REPUTATION: // 62
            if (referencePlayer->GetReputationMgr().GetReputation(1168) < int32(reqValue))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_RATED_BATTLEGROUND_RATING: // 64
            if (referencePlayer->GetRBGPersonalRating() < reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_WORLD_STATE_EXPRESSION: // 67
            if (WorldStateExpressionEntry const* worldStateExpression = sWorldStateExpressionStore.LookupEntry(reqValue))
                return ConditionMgr::IsPlayerMeetingExpression(referencePlayer, worldStateExpression);
            return false;
        case CRITERIA_ADDITIONAL_CONDITION_MAP_DIFFICULTY: // 68
        {
            DifficultyEntry const* difficulty = sDifficultyStore.LookupEntry(referencePlayer->GetMap()->GetDifficultyID());
            if (!difficulty || difficulty->ID != reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_LEVEL_GREATER: // 69
            if (referencePlayer->getLevel() < reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_LEVEL_GREATER: // 70
            if (!unit || unit->getLevel() < reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_LEVEL_LOWER: // 71
            if (referencePlayer->getLevel() > reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_LEVEL_LOWER: // 72
            if (!unit || unit->getLevel() > reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_MODIFIER_TREE: // 73
            if (ModifierTreeNode const* nextModifierTree = sCriteriaMgr->GetModifierTree(reqValue))
                return ModifierTreeSatisfied(nextModifierTree, miscValue1, miscValue2, unit, referencePlayer);
            return false;
        case CRITERIA_ADDITIONAL_CONDITION_SCENARIO_ID: // 74
        {
            Scenario const* scenario = referencePlayer->GetScenario();
            if (!scenario)
                return false;
            if (scenario->GetEntry()->ID != reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_THE_TILLERS_REPUTATION: // 75
            if (referencePlayer->GetReputationMgr().GetReputation(1272) < int32(reqValue))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_SCENARIO_STEP_INDEX: // 82
        {
            Scenario const* scenario = referencePlayer->GetScenario();
            if (!scenario)
                return false;
            if (scenario->GetStep()->OrderIndex != (reqValue - 1))
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_IS_ON_QUEST: // 84
            if (referencePlayer->FindQuestSlot(reqValue) == MAX_QUEST_LOG_SIZE)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_EXALTED_WITH_FACTION: // 85
            if (referencePlayer->GetReputationMgr().GetReputation(reqValue) < 42000)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_HAS_ACHIEVEMENT: // 86
        case CRITERIA_ADDITIONAL_CONDITION_HAS_ACHIEVEMENT_ON_CHARACTER: // 87
            if (!referencePlayer->HasAchieved(reqValue))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_CLOUD_SERPENT_REPUTATION: // 88
            if (referencePlayer->GetReputationMgr().GetReputation(1271) < int32(reqValue))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_BATTLE_PET_SPECIES: // 91
            if (miscValue1 != reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_ACTIVE_EXPANSION: // 92
            if (referencePlayer->GetSession()->GetExpansion() < reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_FACTION_STANDING: // 95
            if (referencePlayer->GetReputationMgr().GetReputation(reqValue) < int32(secondaryAsset))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_SEX: // 97
            if (referencePlayer->getGender() != uint8(reqValue))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_NATIVE_SEX: // 98
            if (referencePlayer->m_playerData->NativeSex != uint8(reqValue))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_SKILL: // 99
            if (referencePlayer->GetPureSkillValue(reqValue) < uint16(secondaryAsset))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_NORMAL_PHASE_SHIFT: // 101
            if (!PhasingHandler::InDbPhaseShift(referencePlayer, 0, 0, 0))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_IN_PHASE: // 102
            if (!PhasingHandler::InDbPhaseShift(referencePlayer, 0, reqValue, 0))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_NOT_IN_PHASE: // 103
            if (PhasingHandler::InDbPhaseShift(referencePlayer, 0, reqValue, 0))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_HAS_SPELL: // 104
            if (!referencePlayer->HasSpell(reqValue))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_ITEM_COUNT: // 105
            if (referencePlayer->GetItemCount(reqValue, false) < secondaryAsset)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_ACCOUNT_EXPANSION: // 106
            if (referencePlayer->GetSession()->GetAccountExpansion() < reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_REWARDED_QUEST: // 110
            if (uint32 questBit = sDB2Manager.GetQuestUniqueBitFlag(reqValue))
                if (!(referencePlayer->m_activePlayerData->QuestCompleted[((questBit - 1) >> 6)] & (UI64LIT(1) << ((questBit - 1) & 63))))
                    return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_COMPLETED_QUEST: // 111
            if (referencePlayer->GetQuestStatus(reqValue) != QUEST_STATUS_COMPLETE)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_EXPLORED_AREA: // 113
        {
            AreaTableEntry const* areaTable = sAreaTableStore.LookupEntry(reqValue);
            if (!areaTable)
                return false;
            if (areaTable->AreaBit <= 0)
                break; // success
            uint32 playerIndexOffset = uint32(areaTable->AreaBit) / 64;
            if (playerIndexOffset >= PLAYER_EXPLORED_ZONES_SIZE)
                break;
            if (!(referencePlayer->m_activePlayerData->ExploredZones[playerIndexOffset] & (UI64LIT(1) << (areaTable->AreaBit % 64))))
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_ITEM_COUNT_INCLUDING_BANK: // 114
            if (referencePlayer->GetItemCount(reqValue, true) < secondaryAsset)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_PVP_FACTION_INDEX: // 116
        {
            ChrRacesEntry const* race = sChrRacesStore.LookupEntry(referencePlayer->getRace());
            if (!race)
                return false;
            FactionTemplateEntry const* faction = sFactionTemplateStore.LookupEntry(race->FactionID);
            if (!faction)
                return false;
            int32 factionIndex = -1;
            if (faction->FactionGroup & FACTION_MASK_HORDE)
                factionIndex = 0;
            else if (faction->FactionGroup & FACTION_MASK_ALLIANCE)
                factionIndex = 1;
            else if (faction->FactionGroup & FACTION_MASK_PLAYER)
                factionIndex = 0;
            if (factionIndex != int32(reqValue))
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_LFG_VALUE_EQUAL: // 117
            if (ConditionMgr::GetPlayerConditionLfgValue(referencePlayer, PlayerConditionLfgStatus(reqValue)) != secondaryAsset)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_LFG_VALUE_GREATER: // 118
            if (ConditionMgr::GetPlayerConditionLfgValue(referencePlayer, PlayerConditionLfgStatus(reqValue)) < secondaryAsset)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_CURRENCY_AMOUNT: // 119
            if (!referencePlayer->HasCurrency(reqValue, secondaryAsset))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_CURRENCY_TRACKED_AMOUNT: // 121
            if (referencePlayer->GetTrackedCurrencyCount(reqValue) < secondaryAsset)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_MAP_INSTANCE_TYPE: // 122
            if (referencePlayer->GetMap()->GetEntry()->InstanceType != int8(reqValue))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_MENTOR: // 123
            if (!referencePlayer->HasPlayerFlag(PLAYER_FLAGS_MENTOR))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_GARRISON_LEVEL_ABOVE: // 126
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(secondaryAsset) || garrison->GetSiteLevel()->GarrLevel < reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWERS_ABOVE_LEVEL: // 127
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(tertiaryAsset))
                return false;
            uint32 followerCount = garrison->CountFollowers([secondaryAsset](Garrison::Follower const& follower)
            {
                return follower.PacketInfo.FollowerLevel >= secondaryAsset;
            });
            if (followerCount < reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWERS_ABOVE_QUALITY: // 128
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(tertiaryAsset))
                return false;
            uint32 followerCount = garrison->CountFollowers([secondaryAsset](Garrison::Follower const& follower)
            {
                return follower.PacketInfo.Quality >= secondaryAsset;
            });
            if (followerCount < reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWER_ABOVE_LEVEL_WITH_ABILITY: // 129
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(tertiaryAsset))
                return false;
            uint32 followerCount = garrison->CountFollowers([reqValue, secondaryAsset](Garrison::Follower const& follower)
            {
                return follower.PacketInfo.FollowerLevel >= reqValue && follower.HasAbility(secondaryAsset);
            });
            if (followerCount < 1)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWER_ABOVE_LEVEL_WITH_TRAIT: // 130
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(tertiaryAsset))
                return false;
            GarrAbilityEntry const* traitEntry = sGarrAbilityStore.LookupEntry(secondaryAsset);
            if (!traitEntry || !(traitEntry->Flags & GARRISON_ABILITY_FLAG_TRAIT))
                return false;
            uint32 followerCount = garrison->CountFollowers([reqValue, secondaryAsset](Garrison::Follower const& follower)
            {
                return follower.PacketInfo.FollowerLevel >= reqValue && follower.HasAbility(secondaryAsset);
            });
            if (followerCount < 1)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWER_WITH_ABILITY_IN_BUILDING: // 131
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(tertiaryAsset))
                return false;
            uint32 followerCount = garrison->CountFollowers([reqValue, secondaryAsset](Garrison::Follower const& follower)
            {
                GarrBuildingEntry const* followerBuilding = sGarrBuildingStore.LookupEntry(follower.PacketInfo.CurrentBuildingID);
                if (!followerBuilding)
                    return false;
                return followerBuilding->BuildingType == secondaryAsset && follower.HasAbility(reqValue);;
            });
            if (followerCount < 1)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWER_WITH_TRAIT_IN_BUILDING: // 132
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(tertiaryAsset))
                return false;
            GarrAbilityEntry const* traitEntry = sGarrAbilityStore.LookupEntry(reqValue);
            if (!traitEntry || !(traitEntry->Flags & GARRISON_ABILITY_FLAG_TRAIT))
                return false;
            uint32 followerCount = garrison->CountFollowers([reqValue, secondaryAsset](Garrison::Follower const& follower)
            {
                GarrBuildingEntry const* followerBuilding = sGarrBuildingStore.LookupEntry(follower.PacketInfo.CurrentBuildingID);
                if (!followerBuilding)
                    return false;
                return followerBuilding->BuildingType == secondaryAsset && follower.HasAbility(reqValue);;
            });
            if (followerCount < 1)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWER_ABOVE_LEVEL_IN_BUILDING: // 133
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(tertiaryAsset))
                return false;
            uint32 followerCount = garrison->CountFollowers([reqValue, secondaryAsset](Garrison::Follower const& follower)
            {
                if (follower.PacketInfo.FollowerLevel < reqValue)
                    return false;
                GarrBuildingEntry const* followerBuilding = sGarrBuildingStore.LookupEntry(follower.PacketInfo.CurrentBuildingID);
                if (!followerBuilding)
                    return false;
                return followerBuilding->BuildingType == secondaryAsset;
            });
            if (followerCount < 1)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_GARRISON_BUILDING_ABOVE_LEVEL: // 134
        {
            Garrison* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(tertiaryAsset))
                return false;
            for (Garrison::Plot const* plot : garrison->GetPlots())
            {
                if (!plot->BuildingInfo.PacketInfo)
                    continue;

                GarrBuildingEntry const* building = sGarrBuildingStore.LookupEntry(plot->BuildingInfo.PacketInfo->GarrBuildingID);
                if (!building || building->UpgradeLevel < reqValue || building->BuildingType != secondaryAsset)
                    continue;

                return true;
            }
            return false;
        }
        case CRITERIA_ADDITIONAL_CONDITION_GARRISON_BLUEPRINT: // 135
        {
            GarrBuildingEntry const* blueprintBuilding = sGarrBuildingStore.LookupEntry(reqValue);
            if (!blueprintBuilding)
                return false;
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(blueprintBuilding->GarrTypeID))
                return false;
            if (!garrison->HasBlueprint(reqValue))
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_GARRISON_BUILDING_INACTIVE: // 140
        {
            GarrBuildingEntry const* building = sGarrBuildingStore.LookupEntry(reqValue);
            if (!building)
                return false;
            Garrison* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(tertiaryAsset))
                return false;
            for (Garrison::Plot const* plot : garrison->GetPlots())
            {
                if (!plot->BuildingInfo.PacketInfo || plot->BuildingInfo.PacketInfo->GarrBuildingID != reqValue)
                    continue;

                return !plot->BuildingInfo.PacketInfo->Active;
            }
            return false;
        }
        case CRITERIA_ADDITIONAL_CONDITION_GARRISON_BUILDING_EQUAL_LEVEL: // 142
        {
            Garrison* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(tertiaryAsset))
                return false;
            for (Garrison::Plot const* plot : garrison->GetPlots())
            {
                if (!plot->BuildingInfo.PacketInfo)
                    continue;

                GarrBuildingEntry const* building = sGarrBuildingStore.LookupEntry(plot->BuildingInfo.PacketInfo->GarrBuildingID);
                if (!building || building->UpgradeLevel != reqValue || building->BuildingType != secondaryAsset)
                    continue;

                return true;
            }
            return false;
        }
        case CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWER_WITH_ABILITY: // 143
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(secondaryAsset))
                return false;
            if (miscValue1)
            {
                Garrison::Follower const* follower = garrison->GetFollower(miscValue1);
                if (!follower)
                    return false;
                if (!follower->HasAbility(reqValue))
                    return false;
            }
            else
            {
                uint32 followerCount = garrison->CountFollowers([reqValue](Garrison::Follower const& follower)
                {
                    return follower.HasAbility(reqValue);
                });
                if (followerCount < 1)
                    return false;
            }
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWER_WITH_TRAIT: // 144
        {
            GarrAbilityEntry const* traitEntry = sGarrAbilityStore.LookupEntry(reqValue);
            if (!traitEntry || !(traitEntry->Flags & GARRISON_ABILITY_FLAG_TRAIT))
                return false;
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(secondaryAsset))
                return false;
            if (miscValue1)
            {
                Garrison::Follower const* follower = garrison->GetFollower(miscValue1);
                if (!follower || !follower->HasAbility(reqValue))
                    return false;
            }
            else
            {
                uint32 followerCount = garrison->CountFollowers([reqValue](Garrison::Follower const& follower)
                {
                    return follower.HasAbility(reqValue);
                });
                if (followerCount < 1)
                    return false;
            }
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWER_ABOVE_QUALITY_WOD: // 145
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GARRISON_TYPE_GARRISON)
                return false;
            if (miscValue1)
            {
                Garrison::Follower const* follower = garrison->GetFollower(miscValue1);
                if (!follower || follower->PacketInfo.Quality < reqValue)
                    return false;
            }
            else
            {
                uint32 followerCount = garrison->CountFollowers([reqValue](Garrison::Follower const& follower)
                {
                    return follower.PacketInfo.Quality >= reqValue;
                });
                if (followerCount < 1)
                    return false;
            }
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWER_EQUAL_LEVEL: // 146
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(secondaryAsset))
                return false;
            if (miscValue1)
            {
                Garrison::Follower const* follower = garrison->GetFollower(miscValue1);
                if (!follower || follower->PacketInfo.FollowerLevel < reqValue)
                    return false;
            }
            else
            {
                uint32 followerCount = garrison->CountFollowers([reqValue](Garrison::Follower const& follower)
                {
                    return follower.PacketInfo.FollowerLevel >= reqValue;
                });
                if (followerCount < 1)
                    return false;
            }
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_BATTLE_PET_SPECIES_IN_TEAM: // 151
        {
            uint32 count = 0;
            for (WorldPackets::BattlePet::BattlePetSlot const& slot : referencePlayer->GetSession()->GetBattlePetMgr()->GetSlots())
                if (slot.Pet.Species == secondaryAsset)
                    ++count;
            if (count < reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_BATTLE_PET_FAMILY_IN_TEAM: // 152
        {
            uint32 count = 0;
            for (WorldPackets::BattlePet::BattlePetSlot const& slot : referencePlayer->GetSession()->GetBattlePetMgr()->GetSlots())
                if (BattlePetSpeciesEntry const* species = sBattlePetSpeciesStore.LookupEntry(slot.Pet.Species))
                    if (species->PetTypeEnum == secondaryAsset)
                        ++count;
            if (count < reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWER_ID: // 157
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison)
                return false;
            if (miscValue1)
            {
                Garrison::Follower const* follower = garrison->GetFollower(miscValue1);
                if (!follower || follower->PacketInfo.GarrFollowerID != reqValue)
                    return false;
            }
            else
            {
                uint32 followerCount = garrison->CountFollowers([reqValue](Garrison::Follower const& follower)
                {
                    return follower.PacketInfo.GarrFollowerID == reqValue;
                });
                if (followerCount < 1)
                    return false;
            }
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWER_ABOVE_ITEM_LEVEL: // 168
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison)
                return false;
            if (miscValue1)
            {
                Garrison::Follower const* follower = garrison->GetFollower(miscValue1);
                if (!follower || follower->PacketInfo.GarrFollowerID != reqValue)
                    return false;
            }
            else
            {
                uint32 followerCount = garrison->CountFollowers([reqValue](Garrison::Follower const& follower)
                {
                    return follower.GetItemLevel() >= reqValue;
                });
                if (followerCount < 1)
                    return false;
            }
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWERS_ABOVE_ITEM_LEVEL: // 169
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(tertiaryAsset))
                return false;
            uint32 followerCount = garrison->CountFollowers([secondaryAsset](Garrison::Follower const& follower)
            {
                return follower.GetItemLevel() >= secondaryAsset;
            });
            if (followerCount < reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_GARRISON_LEVEL_EQUAL: // 170
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GARRISON_TYPE_GARRISON || garrison->GetSiteLevel()->GarrLevel != reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_TARGETING_CORPSE: // 173
            if (referencePlayer->GetTarget().GetHigh() != HighGuid::Corpse)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWERS_LEVEL_EQUAL: // 175
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(tertiaryAsset))
                return false;
            uint32 followerCount = garrison->CountFollowers([secondaryAsset](Garrison::Follower const& follower)
            {
                return follower.PacketInfo.FollowerLevel >= secondaryAsset;
            });
            if (followerCount < reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWER_ID_IN_BUILDING: // 176
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GARRISON_TYPE_GARRISON)
                return false;
            uint32 followerCount = garrison->CountFollowers([reqValue, secondaryAsset](Garrison::Follower const& follower)
            {
                if (follower.PacketInfo.GarrFollowerID != reqValue)
                    return false;
                GarrBuildingEntry const* followerBuilding = sGarrBuildingStore.LookupEntry(follower.PacketInfo.CurrentBuildingID);
                if (!followerBuilding)
                    return false;
                return followerBuilding->BuildingType == secondaryAsset;
            });
            if (followerCount < 1)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_WORLD_PVP_AREA: // 179
        {
            Battlefield const* bf = sBattlefieldMgr->GetBattlefieldToZoneId(referencePlayer->GetZoneId());
            if (!bf || bf->GetBattleId() != reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_GARRISON_FOLLOWERS_ITEM_LEVEL_ABOVE: // 184
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison)
                return false;
            uint32 followerCount = garrison->CountFollowers([secondaryAsset, tertiaryAsset](Garrison::Follower const& follower)
            {
                GarrFollowerEntry const* garrFollower = sGarrFollowerStore.LookupEntry(follower.PacketInfo.GarrFollowerID);
                if (!garrFollower)
                    return false;
                return follower.GetItemLevel() >= secondaryAsset && garrFollower->GarrFollowerTypeID == tertiaryAsset;
            });
            if (followerCount < reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_HONOR_LEVEL: // 193
            if (referencePlayer->GetHonorLevel() != reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_PRESTIGE_LEVEL: // 194
            return false;
        case CRITERIA_ADDITIONAL_CONDITION_ITEM_MODIFIED_APPEARANCE: // 200
        {
            std::pair<bool, bool> hasAppearance = referencePlayer->GetSession()->GetCollectionMgr()->HasItemAppearance(reqValue);
            if (!hasAppearance.first || hasAppearance.second)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_HAS_CHARACTER_RESTRICTIONS: // 203
        {
            if (referencePlayer->m_activePlayerData->CharacterRestrictions.empty())
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_QUEST_INFO_ID: // 206
        {
            Quest const* quest = sObjectMgr->GetQuestTemplate(miscValue1);
            if (!quest || quest->GetQuestInfoID() != reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_ARTIFACT_APPEARANCE_SET_USED: // 208
        {
            for (uint8 slot = EQUIPMENT_SLOT_MAINHAND; slot <= EQUIPMENT_SLOT_RANGED; ++slot)
                if (Item* artifact = referencePlayer->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
                    if (ArtifactAppearanceEntry const* artifactAppearance = sArtifactAppearanceStore.LookupEntry(artifact->GetModifier(ITEM_MODIFIER_ARTIFACT_APPEARANCE_ID)))
                        if (artifactAppearance->ArtifactAppearanceSetID == reqValue)
                            return true;
            return false;
        }
        case CRITERIA_ADDITIONAL_CONDITION_CURRENCY_AMOUNT_EQUAL: // 209
            if (referencePlayer->GetCurrency(reqValue) != secondaryAsset)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_SCENARIO_TYPE: // 211
        {
            Scenario const* scenario = referencePlayer->GetScenario();
            if (!scenario)
                return false;
            if (scenario->GetEntry()->Type != reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_ACCOUNT_EXPANSION_EQUAL: // 212
            if (referencePlayer->GetSession()->GetAccountExpansion() != reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_ACHIEVEMENT_GLOBALLY_INCOMPLETED: // 231
        {
            AchievementEntry const* achievement = sAchievementStore.LookupEntry(secondaryAsset);
            if (!achievement)
                return false;
            if (sAchievementMgr->IsRealmCompleted(achievement))
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_MAIN_HAND_VISIBLE_SUBCLASS: // 232
        {
            uint32 itemSubclass = ITEM_SUBCLASS_WEAPON_FIST_WEAPON;
            if (ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(referencePlayer->m_playerData->VisibleItems[EQUIPMENT_SLOT_MAINHAND].ItemID))
                itemSubclass = itemTemplate->GetSubClass();
            if (itemSubclass != reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_OFF_HAND_VISIBLE_SUBCLASS: // 233
        {
            uint32 itemSubclass = ITEM_SUBCLASS_WEAPON_FIST_WEAPON;
            if (ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(referencePlayer->m_playerData->VisibleItems[EQUIPMENT_SLOT_OFFHAND].ItemID))
                itemSubclass = itemTemplate->GetSubClass();
            if (itemSubclass != reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_AZERITE_ITEM_LEVEL: // 235
        {
            Item const* heartOfAzeroth = referencePlayer->GetItemByEntry(ITEM_ID_HEART_OF_AZEROTH, ITEM_SEARCH_EVERYWHERE);
            if (!heartOfAzeroth || heartOfAzeroth->ToAzeriteItem()->GetLevel() < reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_DISPLAY_RACE: // 252
        {
            CreatureDisplayInfoEntry const* creatureDisplayInfo = sCreatureDisplayInfoStore.LookupEntry(referencePlayer->GetDisplayId());
            if (!creatureDisplayInfo)
                return false;
            CreatureDisplayInfoExtraEntry const* creatureDisplayInfoExtra = sCreatureDisplayInfoExtraStore.LookupEntry(creatureDisplayInfo->ExtendedDisplayInfoID);
            if (!creatureDisplayInfoExtra)
                return false;
            if (uint32(creatureDisplayInfoExtra->DisplayRaceID) != reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_DISPLAY_RACE: // 253
        {
            if (!unit)
                return false;
            CreatureDisplayInfoEntry const* creatureDisplayInfo = sCreatureDisplayInfoStore.LookupEntry(unit->GetDisplayId());
            if (!creatureDisplayInfo)
                return false;
            CreatureDisplayInfoExtraEntry const* creatureDisplayInfoExtra = sCreatureDisplayInfoExtraStore.LookupEntry(creatureDisplayInfo->ExtendedDisplayInfoID);
            if (!creatureDisplayInfoExtra)
                return false;
            if (uint32(creatureDisplayInfoExtra->DisplayRaceID) != reqValue)
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_AURA_COUNT_EQUAL: // 255
            if (referencePlayer->GetAuraCount(secondaryAsset) != reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_AURA_COUNT_EQUAL: // 256
            if (!unit || unit->GetAuraCount(secondaryAsset) != reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_AURA_COUNT_GREATER: // 257
            if (referencePlayer->GetAuraCount(secondaryAsset) < reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_TARGET_AURA_COUNT_GREATER: // 258
            if (!unit || unit->GetAuraCount(secondaryAsset) < reqValue)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_UNLOCKED_AZERITE_ESSENCE_RANK_LOWER: // 259
        {
            if (Item const* heartOfAzeroth = referencePlayer->GetItemByEntry(ITEM_ID_HEART_OF_AZEROTH, ITEM_SEARCH_EVERYWHERE))
                if (AzeriteItem const* azeriteItem = heartOfAzeroth->ToAzeriteItem())
                    for (UF::UnlockedAzeriteEssence const& essence : azeriteItem->m_azeriteItemData->UnlockedEssences)
                        if (essence.AzeriteEssenceID == reqValue && essence.Rank < secondaryAsset)
                            return true;
            return false;
        }
        case CRITERIA_ADDITIONAL_CONDITION_UNLOCKED_AZERITE_ESSENCE_RANK_EQUAL: // 260
        {
            if (Item const* heartOfAzeroth = referencePlayer->GetItemByEntry(ITEM_ID_HEART_OF_AZEROTH, ITEM_SEARCH_EVERYWHERE))
                if (AzeriteItem const* azeriteItem = heartOfAzeroth->ToAzeriteItem())
                    for (UF::UnlockedAzeriteEssence const& essence : azeriteItem->m_azeriteItemData->UnlockedEssences)
                        if (essence.AzeriteEssenceID == reqValue && essence.Rank == secondaryAsset)
                            return true;
            return false;
        }
        case CRITERIA_ADDITIONAL_CONDITION_UNLOCKED_AZERITE_ESSENCE_RANK_GREATER: // 261
        {
            if (Item const* heartOfAzeroth = referencePlayer->GetItemByEntry(ITEM_ID_HEART_OF_AZEROTH, ITEM_SEARCH_EVERYWHERE))
                if (AzeriteItem const* azeriteItem = heartOfAzeroth->ToAzeriteItem())
                    for (UF::UnlockedAzeriteEssence const& essence : azeriteItem->m_azeriteItemData->UnlockedEssences)
                        if (essence.AzeriteEssenceID == reqValue && essence.Rank > secondaryAsset)
                            return true;
            return false;
        }
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_HAS_AURA_EFFECT_INDEX: // 262
            if (!referencePlayer->GetAuraEffect(reqValue, secondaryAsset))
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_SPECIALIZATION_ROLE: // 263
        {
            ChrSpecializationEntry const* spec = sChrSpecializationStore.LookupEntry(referencePlayer->GetPrimarySpecialization());
            if (!spec || spec->Role != int32(reqValue))
                return false;
            break;
        }
        case CRITERIA_ADDITIONAL_CONDITION_SOURCE_LEVEL_120: // 264
            if (referencePlayer->getLevel() != 120)
                return false;
            break;
        case CRITERIA_ADDITIONAL_CONDITION_SELECTED_AZERITE_ESSENCE_RANK_LOWER: // 266
            if (Item const* heartOfAzeroth = referencePlayer->GetItemByEntry(ITEM_ID_HEART_OF_AZEROTH, ITEM_SEARCH_EVERYWHERE))
                if (AzeriteItem const* azeriteItem = heartOfAzeroth->ToAzeriteItem())
                    if (UF::SelectedAzeriteEssences const* selectedEssences = azeriteItem->GetSelectedAzeriteEssences())
                        for (UF::UnlockedAzeriteEssence const& essence : azeriteItem->m_azeriteItemData->UnlockedEssences)
                            if (essence.AzeriteEssenceID == selectedEssences->AzeriteEssenceID[reqValue] && essence.Rank < secondaryAsset)
                                return true;
            return false;
        case CRITERIA_ADDITIONAL_CONDITION_SELECTED_AZERITE_ESSENCE_RANK_GREATER: // 267
            if (Item const* heartOfAzeroth = referencePlayer->GetItemByEntry(ITEM_ID_HEART_OF_AZEROTH, ITEM_SEARCH_EVERYWHERE))
                if (AzeriteItem const* azeriteItem = heartOfAzeroth->ToAzeriteItem())
                    if (UF::SelectedAzeriteEssences const* selectedEssences = azeriteItem->GetSelectedAzeriteEssences())
                        for (UF::UnlockedAzeriteEssence const& essence : azeriteItem->m_azeriteItemData->UnlockedEssences)
                            if (essence.AzeriteEssenceID == selectedEssences->AzeriteEssenceID[reqValue] && essence.Rank > secondaryAsset)
                                return true;
            return false;
        case CRITERIA_ADDITIONAL_CONDITION_MAP_OR_COSMETIC_MAP: // 280
        {
            MapEntry const* map = referencePlayer->GetMap()->GetEntry();
            if (map->ID != reqValue && map->CosmeticParentMapID != int32(reqValue))
                return false;
            break;
        }
        default:
            break;
    }
    return true;
}

char const* CriteriaMgr::GetCriteriaTypeString(uint32 type)
{
    return GetCriteriaTypeString(CriteriaTypes(type));
}

char const* CriteriaMgr::GetCriteriaTypeString(CriteriaTypes type)
{
    switch (type)
    {
        case CRITERIA_TYPE_KILL_CREATURE:
            return "KILL_CREATURE";
        case CRITERIA_TYPE_WIN_BG:
            return "TYPE_WIN_BG";
        case CRITERIA_TYPE_COMPLETE_ARCHAEOLOGY_PROJECTS:
            return "COMPLETE_RESEARCH";
        case CRITERIA_TYPE_SURVEY_GAMEOBJECT:
            return "SURVEY_GAMEOBJECT";
        case CRITERIA_TYPE_REACH_LEVEL:
            return "REACH_LEVEL";
        case CRITERIA_TYPE_CLEAR_DIGSITE:
            return "CLEAR_DIGSITE";
        case CRITERIA_TYPE_REACH_SKILL_LEVEL:
            return "REACH_SKILL_LEVEL";
        case CRITERIA_TYPE_COMPLETE_ACHIEVEMENT:
            return "COMPLETE_ACHIEVEMENT";
        case CRITERIA_TYPE_COMPLETE_QUEST_COUNT:
            return "COMPLETE_QUEST_COUNT";
        case CRITERIA_TYPE_COMPLETE_DAILY_QUEST_DAILY:
            return "COMPLETE_DAILY_QUEST_DAILY";
        case CRITERIA_TYPE_COMPLETE_QUESTS_IN_ZONE:
            return "COMPLETE_QUESTS_IN_ZONE";
        case CRITERIA_TYPE_CURRENCY:
            return "CURRENCY";
        case CRITERIA_TYPE_DAMAGE_DONE:
            return "DAMAGE_DONE";
        case CRITERIA_TYPE_COMPLETE_DAILY_QUEST:
            return "COMPLETE_DAILY_QUEST";
        case CRITERIA_TYPE_COMPLETE_BATTLEGROUND:
            return "COMPLETE_BATTLEGROUND";
        case CRITERIA_TYPE_DEATH_AT_MAP:
            return "DEATH_AT_MAP";
        case CRITERIA_TYPE_DEATH:
            return "DEATH";
        case CRITERIA_TYPE_DEATH_IN_DUNGEON:
            return "DEATH_IN_DUNGEON";
        case CRITERIA_TYPE_COMPLETE_RAID:
            return "COMPLETE_RAID";
        case CRITERIA_TYPE_KILLED_BY_CREATURE:
            return "KILLED_BY_CREATURE";
        case CRITERIA_TYPE_MANUAL_COMPLETE_CRITERIA:
            return "MANUAL_COMPLETE_CRITERIA";
        case CRITERIA_TYPE_COMPLETE_CHALLENGE_MODE_GUILD:
            return "COMPLETE_CHALLENGE_MODE_GUILD";
        case CRITERIA_TYPE_KILLED_BY_PLAYER:
            return "KILLED_BY_PLAYER";
        case CRITERIA_TYPE_FALL_WITHOUT_DYING:
            return "FALL_WITHOUT_DYING";
        case CRITERIA_TYPE_DEATHS_FROM:
            return "DEATHS_FROM";
        case CRITERIA_TYPE_COMPLETE_QUEST:
            return "COMPLETE_QUEST";
        case CRITERIA_TYPE_BE_SPELL_TARGET:
            return "BE_SPELL_TARGET";
        case CRITERIA_TYPE_CAST_SPELL:
            return "CAST_SPELL";
        case CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE:
            return "BG_OBJECTIVE_CAPTURE";
        case CRITERIA_TYPE_HONORABLE_KILL_AT_AREA:
            return "HONORABLE_KILL_AT_AREA";
        case CRITERIA_TYPE_WIN_ARENA:
            return "WIN_ARENA";
        case CRITERIA_TYPE_PLAY_ARENA:
            return "PLAY_ARENA";
        case CRITERIA_TYPE_LEARN_SPELL:
            return "LEARN_SPELL";
        case CRITERIA_TYPE_HONORABLE_KILL:
            return "HONORABLE_KILL";
        case CRITERIA_TYPE_OWN_ITEM:
            return "OWN_ITEM";
        case CRITERIA_TYPE_WIN_RATED_ARENA:
            return "WIN_RATED_ARENA";
        case CRITERIA_TYPE_HIGHEST_TEAM_RATING:
            return "HIGHEST_TEAM_RATING";
        case CRITERIA_TYPE_HIGHEST_PERSONAL_RATING:
            return "HIGHEST_PERSONAL_RATING";
        case CRITERIA_TYPE_LEARN_SKILL_LEVEL:
            return "LEARN_SKILL_LEVEL";
        case CRITERIA_TYPE_USE_ITEM:
            return "USE_ITEM";
        case CRITERIA_TYPE_LOOT_ITEM:
            return "LOOT_ITEM";
        case CRITERIA_TYPE_EXPLORE_AREA:
            return "EXPLORE_AREA";
        case CRITERIA_TYPE_OWN_RANK:
            return "OWN_RANK";
        case CRITERIA_TYPE_BUY_BANK_SLOT:
            return "BUY_BANK_SLOT";
        case CRITERIA_TYPE_GAIN_REPUTATION:
            return "GAIN_REPUTATION";
        case CRITERIA_TYPE_GAIN_EXALTED_REPUTATION:
            return "GAIN_EXALTED_REPUTATION";
        case CRITERIA_TYPE_VISIT_BARBER_SHOP:
            return "VISIT_BARBER_SHOP";
        case CRITERIA_TYPE_EQUIP_EPIC_ITEM:
            return "EQUIP_EPIC_ITEM";
        case CRITERIA_TYPE_ROLL_NEED_ON_LOOT:
            return "ROLL_NEED_ON_LOOT";
        case CRITERIA_TYPE_ROLL_GREED_ON_LOOT:
            return "GREED_ON_LOOT";
        case CRITERIA_TYPE_HK_CLASS:
            return "HK_CLASS";
        case CRITERIA_TYPE_HK_RACE:
            return "HK_RACE";
        case CRITERIA_TYPE_DO_EMOTE:
            return "DO_EMOTE";
        case CRITERIA_TYPE_HEALING_DONE:
            return "HEALING_DONE";
        case CRITERIA_TYPE_GET_KILLING_BLOWS:
            return "GET_KILLING_BLOWS";
        case CRITERIA_TYPE_EQUIP_ITEM:
            return "EQUIP_ITEM";
        case CRITERIA_TYPE_MONEY_FROM_VENDORS:
            return "MONEY_FROM_VENDORS";
        case CRITERIA_TYPE_GOLD_SPENT_FOR_TALENTS:
            return "GOLD_SPENT_FOR_TALENTS";
        case CRITERIA_TYPE_NUMBER_OF_TALENT_RESETS:
            return "NUMBER_OF_TALENT_RESETS";
        case CRITERIA_TYPE_MONEY_FROM_QUEST_REWARD:
            return "MONEY_FROM_QUEST_REWARD";
        case CRITERIA_TYPE_GOLD_SPENT_FOR_TRAVELLING:
            return "GOLD_SPENT_FOR_TRAVELLING";
        case CRITERIA_TYPE_DEFEAT_CREATURE_GROUP:
            return "DEFEAT_CREATURE_GROUP";
        case CRITERIA_TYPE_GOLD_SPENT_AT_BARBER:
            return "GOLD_SPENT_AT_BARBER";
        case CRITERIA_TYPE_GOLD_SPENT_FOR_MAIL:
            return "GOLD_SPENT_FOR_MAIL";
        case CRITERIA_TYPE_LOOT_MONEY:
            return "LOOT_MONEY";
        case CRITERIA_TYPE_USE_GAMEOBJECT:
            return "USE_GAMEOBJECT";
        case CRITERIA_TYPE_BE_SPELL_TARGET2:
            return "BE_SPELL_TARGET2";
        case CRITERIA_TYPE_SPECIAL_PVP_KILL:
            return "SPECIAL_PVP_KILL";
        case CRITERIA_TYPE_COMPLETE_CHALLENGE_MODE:
            return "COMPLETE_CHALLENGE_MODE";
        case CRITERIA_TYPE_FISH_IN_GAMEOBJECT:
            return "FISH_IN_GAMEOBJECT";
        case CRITERIA_TYPE_SEND_EVENT:
            return "SEND_EVENT";
        case CRITERIA_TYPE_ON_LOGIN:
            return "ON_LOGIN";
        case CRITERIA_TYPE_LEARN_SKILLLINE_SPELLS:
            return "LEARN_SKILLLINE_SPELLS";
        case CRITERIA_TYPE_WIN_DUEL:
            return "WIN_DUEL";
        case CRITERIA_TYPE_LOSE_DUEL:
            return "LOSE_DUEL";
        case CRITERIA_TYPE_KILL_CREATURE_TYPE:
            return "KILL_CREATURE_TYPE";
        case CRITERIA_TYPE_COOK_RECIPES_GUILD:
            return "COOK_RECIPE_GUILD";
        case CRITERIA_TYPE_GOLD_EARNED_BY_AUCTIONS:
            return "GOLD_EARNED_BY_AUCTIONS";
        case CRITERIA_TYPE_EARN_PET_BATTLE_ACHIEVEMENT_POINTS:
            return "EARN_PET_BATTLE_ACHIEVEMENT_POINTS";
        case CRITERIA_TYPE_CREATE_AUCTION:
            return "CREATE_AUCTION";
        case CRITERIA_TYPE_HIGHEST_AUCTION_BID:
            return "HIGHEST_AUCTION_BID";
        case CRITERIA_TYPE_WON_AUCTIONS:
            return "WON_AUCTIONS";
        case CRITERIA_TYPE_HIGHEST_AUCTION_SOLD:
            return "HIGHEST_AUCTION_SOLD";
        case CRITERIA_TYPE_HIGHEST_GOLD_VALUE_OWNED:
            return "HIGHEST_GOLD_VALUE_OWNED";
        case CRITERIA_TYPE_GAIN_REVERED_REPUTATION:
            return "GAIN_REVERED_REPUTATION";
        case CRITERIA_TYPE_GAIN_HONORED_REPUTATION:
            return "GAIN_HONORED_REPUTATION";
        case CRITERIA_TYPE_KNOWN_FACTIONS:
            return "KNOWN_FACTIONS";
        case CRITERIA_TYPE_LOOT_EPIC_ITEM:
            return "LOOT_EPIC_ITEM";
        case CRITERIA_TYPE_RECEIVE_EPIC_ITEM:
            return "RECEIVE_EPIC_ITEM";
        case CRITERIA_TYPE_SEND_EVENT_SCENARIO:
            return "SEND_EVENT_SCENARIO";
        case CRITERIA_TYPE_ROLL_NEED:
            return "ROLL_NEED";
        case CRITERIA_TYPE_ROLL_GREED:
            return "ROLL_GREED";
        case CRITERIA_TYPE_RELEASE_SPIRIT:
            return "RELEASE_SPIRIT";
        case CRITERIA_TYPE_OWN_PET:
            return "OWN_PET";
        case CRITERIA_TYPE_GARRISON_COMPLETE_DUNGEON_ENCOUNTER:
            return "GARRISON_COMPLETE_DUNGEON_ENCOUNTER";
        case CRITERIA_TYPE_HIGHEST_HIT_DEALT:
            return "HIT_DEALT";
        case CRITERIA_TYPE_HIGHEST_HIT_RECEIVED:
            return "HIT_RECEIVED";
        case CRITERIA_TYPE_TOTAL_DAMAGE_RECEIVED:
            return "TOTAL_DAMAGE_RECEIVED";
        case CRITERIA_TYPE_HIGHEST_HEAL_CAST:
            return "HIGHEST_HEAL_CAST";
        case CRITERIA_TYPE_TOTAL_HEALING_RECEIVED:
            return "TOTAL_HEALING_RECEIVED";
        case CRITERIA_TYPE_HIGHEST_HEALING_RECEIVED:
            return "HIGHEST_HEALING_RECEIVED";
        case CRITERIA_TYPE_QUEST_ABANDONED:
            return "QUEST_ABANDONED";
        case CRITERIA_TYPE_FLIGHT_PATHS_TAKEN:
            return "FLIGHT_PATHS_TAKEN";
        case CRITERIA_TYPE_LOOT_TYPE:
            return "LOOT_TYPE";
        case CRITERIA_TYPE_CAST_SPELL2:
            return "CAST_SPELL2";
        case CRITERIA_TYPE_LEARN_SKILL_LINE:
            return "LEARN_SKILL_LINE";
        case CRITERIA_TYPE_EARN_HONORABLE_KILL:
            return "EARN_HONORABLE_KILL";
        case CRITERIA_TYPE_ACCEPTED_SUMMONINGS:
            return "ACCEPTED_SUMMONINGS";
        case CRITERIA_TYPE_EARN_ACHIEVEMENT_POINTS:
            return "EARN_ACHIEVEMENT_POINTS";
        case CRITERIA_TYPE_COMPLETE_LFG_DUNGEON:
            return "COMPLETE_LFG_DUNGEON";
        case CRITERIA_TYPE_USE_LFD_TO_GROUP_WITH_PLAYERS:
            return "USE_LFD_TO_GROUP_WITH_PLAYERS";
        case CRITERIA_TYPE_LFG_VOTE_KICKS_INITIATED_BY_PLAYER:
            return "LFG_VOTE_KICKS_INITIATED_BY_PLAYER";
        case CRITERIA_TYPE_LFG_VOTE_KICKS_NOT_INIT_BY_PLAYER:
            return "LFG_VOTE_KICKS_NOT_INIT_BY_PLAYER";
        case CRITERIA_TYPE_BE_KICKED_FROM_LFG:
            return "BE_KICKED_FROM_LFG";
        case CRITERIA_TYPE_LFG_LEAVES:
            return "LFG_LEAVES";
        case CRITERIA_TYPE_SPENT_GOLD_GUILD_REPAIRS:
            return "SPENT_GOLD_GUILD_REPAIRS";
        case CRITERIA_TYPE_REACH_GUILD_LEVEL:
            return "REACH_GUILD_LEVEL";
        case CRITERIA_TYPE_CRAFT_ITEMS_GUILD:
            return "CRAFT_ITEMS_GUILD";
        case CRITERIA_TYPE_CATCH_FROM_POOL:
            return "CATCH_FROM_POOL";
        case CRITERIA_TYPE_BUY_GUILD_BANK_SLOTS:
            return "BUY_GUILD_BANK_SLOTS";
        case CRITERIA_TYPE_EARN_GUILD_ACHIEVEMENT_POINTS:
            return "EARN_GUILD_ACHIEVEMENT_POINTS";
        case CRITERIA_TYPE_WIN_RATED_BATTLEGROUND:
            return "WIN_RATED_BATTLEGROUND";
        case CRITERIA_TYPE_REACH_BG_RATING:
            return "REACH_BG_RATING";
        case CRITERIA_TYPE_BUY_GUILD_TABARD:
            return "BUY_GUILD_TABARD";
        case CRITERIA_TYPE_COMPLETE_QUESTS_GUILD:
            return "COMPLETE_QUESTS_GUILD";
        case CRITERIA_TYPE_HONORABLE_KILLS_GUILD:
            return "HONORABLE_KILLS_GUILD";
        case CRITERIA_TYPE_KILL_CREATURE_TYPE_GUILD:
            return "KILL_CREATURE_TYPE_GUILD";
        case CRITERIA_TYPE_COUNT_OF_LFG_QUEUE_BOOSTS_BY_TANK:
            return "COUNT_OF_LFG_QUEUE_BOOSTS_BY_TANK";
        case CRITERIA_TYPE_COMPLETE_GUILD_CHALLENGE_TYPE:
            return "GUILD_CHALLENGE_TYPE";
        case CRITERIA_TYPE_COMPLETE_GUILD_CHALLENGE:
            return "GUILD_CHALLENGE";
        case CRITERIA_TYPE_LFR_DUNGEONS_COMPLETED:
            return "LFR_DUNGEONS_COMPLETED";
        case CRITERIA_TYPE_LFR_LEAVES:
            return "LFR_LEAVES";
        case CRITERIA_TYPE_LFR_VOTE_KICKS_INITIATED_BY_PLAYER:
            return "LFR_VOTE_KICKS_INITIATED_BY_PLAYER";
        case CRITERIA_TYPE_LFR_VOTE_KICKS_NOT_INIT_BY_PLAYER:
            return "LFR_VOTE_KICKS_NOT_INIT_BY_PLAYER";
        case CRITERIA_TYPE_BE_KICKED_FROM_LFR:
            return "BE_KICKED_FROM_LFR";
        case CRITERIA_TYPE_COUNT_OF_LFR_QUEUE_BOOSTS_BY_TANK:
            return "COUNT_OF_LFR_QUEUE_BOOSTS_BY_TANK";
        case CRITERIA_TYPE_COMPLETE_SCENARIO_COUNT:
            return "COMPLETE_SCENARIO_COUNT";
        case CRITERIA_TYPE_COMPLETE_SCENARIO:
            return "COMPLETE_SCENARIO";
        case CRITERIA_TYPE_REACH_AREATRIGGER_WITH_ACTIONSET:
            return "REACH_AREATRIGGER_WITH_ACTIONSET";
        case CRITERIA_TYPE_OWN_BATTLE_PET:
            return "OWN_BATTLE_PET";
        case CRITERIA_TYPE_OWN_BATTLE_PET_COUNT:
            return "OWN_BATTLE_PET_COUNT";
        case CRITERIA_TYPE_CAPTURE_BATTLE_PET:
            return "CAPTURE_BATTLE_PET";
        case CRITERIA_TYPE_WIN_PET_BATTLE:
            return "WIN_PET_BATTLE";
        case CRITERIA_TYPE_LEVEL_BATTLE_PET:
            return "LEVEL_BATTLE_PET";
        case CRITERIA_TYPE_CAPTURE_BATTLE_PET_CREDIT:
            return "CAPTURE_BATTLE_PET_CREDIT";
        case CRITERIA_TYPE_LEVEL_BATTLE_PET_CREDIT:
            return "LEVEL_BATTLE_PET_CREDIT";
        case CRITERIA_TYPE_ENTER_AREA:
            return "ENTER_AREA";
        case CRITERIA_TYPE_LEAVE_AREA:
            return "LEAVE_AREA";
        case CRITERIA_TYPE_COMPLETE_DUNGEON_ENCOUNTER:
            return "COMPLETE_DUNGEON_ENCOUNTER";
        case CRITERIA_TYPE_PLACE_GARRISON_BUILDING:
            return "PLACE_GARRISON_BUILDING";
        case CRITERIA_TYPE_UPGRADE_GARRISON_BUILDING:
            return "UPGRADE_GARRISON_BUILDING";
        case CRITERIA_TYPE_CONSTRUCT_GARRISON_BUILDING:
            return "CONSTRUCT_GARRISON_BUILDING";
        case CRITERIA_TYPE_UPGRADE_GARRISON:
            return "UPGRADE_GARRISON";
        case CRITERIA_TYPE_START_GARRISON_MISSION:
            return "START_GARRISON_MISSION";
        case CRITERIA_TYPE_START_ORDER_HALL_MISSION:
            return "START_ORDER_HALL_MISSION";
        case CRITERIA_TYPE_COMPLETE_GARRISON_MISSION_COUNT:
            return "COMPLETE_GARRISON_MISSION_COUNT";
        case CRITERIA_TYPE_COMPLETE_GARRISON_MISSION:
            return "COMPLETE_GARRISON_MISSION";
        case CRITERIA_TYPE_RECRUIT_GARRISON_FOLLOWER_COUNT:
            return "RECRUIT_GARRISON_FOLLOWER_COUNT";
        case CRITERIA_TYPE_RECRUIT_GARRISON_FOLLOWER:
            return "RECRUIT_GARRISON_FOLLOWER";
        case CRITERIA_TYPE_LEARN_GARRISON_BLUEPRINT_COUNT:
            return "LEARN_GARRISON_BLUEPRINT_COUNT";
        case CRITERIA_TYPE_COMPLETE_GARRISON_SHIPMENT:
            return "COMPLETE_GARRISON_SHIPMENT";
        case CRITERIA_TYPE_RAISE_GARRISON_FOLLOWER_ITEM_LEVEL:
            return "RAISE_GARRISON_FOLLOWER_ITEM_LEVEL";
        case CRITERIA_TYPE_RAISE_GARRISON_FOLLOWER_LEVEL:
            return "RAISE_GARRISON_FOLLOWER_LEVEL";
        case CRITERIA_TYPE_OWN_TOY:
            return "OWN_TOY";
        case CRITERIA_TYPE_OWN_TOY_COUNT:
            return "OWN_TOY_COUNT";
        case CRITERIA_TYPE_RECRUIT_GARRISON_FOLLOWER_WITH_QUALITY:
            return "RECRUIT_GARRISON_FOLLOWER_WITH_QUALITY";
        case CRITERIA_TYPE_OWN_HEIRLOOMS:
            return "OWN_HEIRLOOMS";
        case CRITERIA_TYPE_ARTIFACT_POWER_EARNED:
            return "ARTIFACT_POWER_EARNED";
        case CRITERIA_TYPE_ARTIFACT_TRAITS_UNLOCKED:
            return "ARTIFACT_TRAITS_UNLOCKED";
        case CRITERIA_TYPE_HONOR_LEVEL_REACHED:
            return "HONOR_LEVEL_REACHED";
        case CRITERIA_TYPE_PRESTIGE_REACHED:
            return "PRESTIGE_REACHED";
        case CRITERIA_TYPE_ORDER_HALL_TALENT_LEARNED:
            return "ORDER_HALL_TALENT_LEARNED";
        case CRITERIA_TYPE_APPEARANCE_UNLOCKED_BY_SLOT:
            return "APPEARANCE_UNLOCKED_BY_SLOT";
        case CRITERIA_TYPE_ORDER_HALL_RECRUIT_TROOP:
            return "ORDER_HALL_RECRUIT_TROOP";
        case CRITERIA_TYPE_COMPLETE_WORLD_QUEST:
            return "COMPLETE_WORLD_QUEST";
        case CRITERIA_TYPE_TRANSMOG_SET_UNLOCKED:
            return "TRANSMOG_SET_UNLOCKED";
        case CRITERIA_TYPE_GAIN_PARAGON_REPUTATION:
            return "GAIN_PARAGON_REPUTATION";
        case CRITERIA_TYPE_EARN_HONOR_XP:
            return "EARN_HONOR_XP";
        case CRITERIA_TYPE_RELIC_TALENT_UNLOCKED:
            return "RELIC_TALENT_UNLOCKED";
        case CRITERIA_TYPE_REACH_ACCOUNT_HONOR_LEVEL:
            return "REACH_ACCOUNT_HONOR_LEVEL";
        case CRITERIA_TYPE_HEART_OF_AZEROTH_ARTIFACT_POWER_EARNED:
            return "HEART_OF_AZEROTH_ARTIFACT_POWER_EARNED";
        case CRITERIA_TYPE_HEART_OF_AZEROTH_LEVEL_REACHED:
            return "HEART_OF_AZEROTH_LEVEL_REACHED";
    }
    return "MISSING_TYPE";
}

CriteriaMgr* CriteriaMgr::Instance()
{
    static CriteriaMgr instance;
    return &instance;
}

namespace
{
inline bool IsCriteriaTypeStoredByAsset(CriteriaTypes type)
{
    switch (type)
    {
        case CRITERIA_TYPE_KILL_CREATURE:
        case CRITERIA_TYPE_WIN_BG:
        case CRITERIA_TYPE_REACH_SKILL_LEVEL:
        case CRITERIA_TYPE_COMPLETE_ACHIEVEMENT:
        case CRITERIA_TYPE_COMPLETE_QUESTS_IN_ZONE:
        case CRITERIA_TYPE_COMPLETE_BATTLEGROUND:
        case CRITERIA_TYPE_KILLED_BY_CREATURE:
        case CRITERIA_TYPE_COMPLETE_QUEST:
        case CRITERIA_TYPE_BE_SPELL_TARGET:
        case CRITERIA_TYPE_CAST_SPELL:
        case CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE:
        case CRITERIA_TYPE_HONORABLE_KILL_AT_AREA:
        case CRITERIA_TYPE_LEARN_SPELL:
        case CRITERIA_TYPE_OWN_ITEM:
        case CRITERIA_TYPE_LEARN_SKILL_LEVEL:
        case CRITERIA_TYPE_USE_ITEM:
        case CRITERIA_TYPE_LOOT_ITEM:
        case CRITERIA_TYPE_EXPLORE_AREA:
        case CRITERIA_TYPE_GAIN_REPUTATION:
        case CRITERIA_TYPE_EQUIP_EPIC_ITEM:
        case CRITERIA_TYPE_HK_CLASS:
        case CRITERIA_TYPE_HK_RACE:
        case CRITERIA_TYPE_DO_EMOTE:
        case CRITERIA_TYPE_EQUIP_ITEM:
        case CRITERIA_TYPE_USE_GAMEOBJECT:
        case CRITERIA_TYPE_BE_SPELL_TARGET2:
        case CRITERIA_TYPE_FISH_IN_GAMEOBJECT:
        case CRITERIA_TYPE_LEARN_SKILLLINE_SPELLS:
        case CRITERIA_TYPE_LOOT_TYPE:
        case CRITERIA_TYPE_CAST_SPELL2:
        case CRITERIA_TYPE_LEARN_SKILL_LINE:
            return true;
        default:
            break;
    }
    return false;
}
}

CriteriaList const& CriteriaMgr::GetPlayerCriteriaByType(CriteriaTypes type, uint32 asset) const
{
    if (asset && IsCriteriaTypeStoredByAsset(type))
    {
        auto itr = _criteriasByAsset[type].find(asset);
        if (itr != _criteriasByAsset[type].end())
            return itr->second;
    }

    return _criteriasByType[type];
}

//==========================================================
CriteriaMgr::~CriteriaMgr()
{
    for (auto itr = _criteriaTrees.begin(); itr != _criteriaTrees.end(); ++itr)
        delete itr->second;

    for (auto itr = _criteria.begin(); itr != _criteria.end(); ++itr)
        delete itr->second;

    for (auto itr = _criteriaModifiers.begin(); itr != _criteriaModifiers.end(); ++itr)
        delete itr->second;
}

void CriteriaMgr::LoadCriteriaModifiersTree()
{
    uint32 oldMSTime = getMSTime();

    if (sModifierTreeStore.GetNumRows() == 0)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 criteria modifiers.");
        return;
    }

    // Load modifier tree nodes
    for (uint32 i = 0; i < sModifierTreeStore.GetNumRows(); ++i)
    {
        ModifierTreeEntry const* tree = sModifierTreeStore.LookupEntry(i);
        if (!tree)
            continue;

        ModifierTreeNode* node = new ModifierTreeNode();
        node->Entry = tree;
        _criteriaModifiers[node->Entry->ID] = node;
    }

    // Build tree
    for (auto itr = _criteriaModifiers.begin(); itr != _criteriaModifiers.end(); ++itr)
        if (ModifierTreeNode* parentNode = Trinity::Containers::MapGetValuePtr(_criteriaModifiers, itr->second->Entry->Parent))
            parentNode->Children.push_back(itr->second);

    TC_LOG_INFO("server.loading", ">> Loaded %u criteria modifiers in %u ms", uint32(_criteriaModifiers.size()), GetMSTimeDiffToNow(oldMSTime));
}

template<typename T>
T GetEntry(std::unordered_map<uint32, T> const& map, CriteriaTreeEntry const* tree)
{
    CriteriaTreeEntry const* cur = tree;
    auto itr = map.find(tree->ID);
    while (itr == map.end())
    {
        if (!cur->Parent)
            break;

        cur = sCriteriaTreeStore.LookupEntry(cur->Parent);
        if (!cur)
            break;

        itr = map.find(cur->ID);
    }

    if (itr == map.end())
        return nullptr;

    return itr->second;
};

void CriteriaMgr::LoadCriteriaList()
{
    uint32 oldMSTime = getMSTime();

    std::unordered_map<uint32 /*criteriaTreeID*/, AchievementEntry const*> achievementCriteriaTreeIds;
    for (AchievementEntry const* achievement : sAchievementStore)
        if (achievement->CriteriaTree)
            achievementCriteriaTreeIds[achievement->CriteriaTree] = achievement;

    std::unordered_map<uint32 /*criteriaTreeID*/, ScenarioStepEntry const*> scenarioCriteriaTreeIds;
    for (ScenarioStepEntry const* scenarioStep : sScenarioStepStore)
        if (scenarioStep->Criteriatreeid)
            scenarioCriteriaTreeIds[scenarioStep->Criteriatreeid] = scenarioStep;

    std::unordered_map<uint32 /*criteriaTreeID*/, QuestObjective const*> questObjectiveCriteriaTreeIds;
    for (std::pair<uint32 /*questID*/, Quest const*> itr : sObjectMgr->GetQuestTemplates())
    {
        for (QuestObjective const& objective : itr.second->Objectives)
        {
            if (objective.Type != QUEST_OBJECTIVE_CRITERIA_TREE)
                continue;

            if (objective.ObjectID)
                questObjectiveCriteriaTreeIds[objective.ObjectID] = &objective;
        }
    }

    // Load criteria tree nodes
    for (CriteriaTreeEntry const* tree : sCriteriaTreeStore)
    {
        // Find linked achievement
        AchievementEntry const* achievement = GetEntry(achievementCriteriaTreeIds, tree);
        ScenarioStepEntry const* scenarioStep = GetEntry(scenarioCriteriaTreeIds, tree);
        QuestObjective const* questObjective = GetEntry(questObjectiveCriteriaTreeIds, tree);
        if (!achievement && !scenarioStep && !questObjective)
            continue;

        CriteriaTree* criteriaTree = new CriteriaTree();
        criteriaTree->ID = tree->ID;
        criteriaTree->Achievement = achievement;
        criteriaTree->ScenarioStep = scenarioStep;
        criteriaTree->QuestObjective = questObjective;
        criteriaTree->Entry = tree;

        _criteriaTrees[criteriaTree->Entry->ID] = criteriaTree;
    }

    // Build tree
    for (auto itr = _criteriaTrees.begin(); itr != _criteriaTrees.end(); ++itr)
    {
        if (CriteriaTree* parent = Trinity::Containers::MapGetValuePtr(_criteriaTrees, itr->second->Entry->Parent))
            parent->Children.push_back(itr->second);

        if (sCriteriaStore.HasRecord(itr->second->Entry->CriteriaID))
            _criteriaTreeByCriteria[itr->second->Entry->CriteriaID].push_back(itr->second);
    }

    // Load criteria
    uint32 criterias = 0;
    uint32 guildCriterias = 0;
    uint32 scenarioCriterias = 0;
    uint32 questObjectiveCriterias = 0;
    for (CriteriaEntry const* criteriaEntry : sCriteriaStore)
    {
        ASSERT(criteriaEntry->Type < CRITERIA_TYPE_TOTAL, "CRITERIA_TYPE_TOTAL must be greater than or equal to %u but is currently equal to %u",
            criteriaEntry->Type + 1, CRITERIA_TYPE_TOTAL);
        ASSERT(criteriaEntry->StartEvent < CRITERIA_TIMED_TYPE_MAX, "CRITERIA_TYPE_TOTAL must be greater than or equal to %u but is currently equal to %u",
            criteriaEntry->StartEvent + 1, CRITERIA_TIMED_TYPE_MAX);
        ASSERT(criteriaEntry->FailEvent < CRITERIA_CONDITION_MAX, "CRITERIA_CONDITION_MAX must be greater than or equal to %u but is currently equal to %u",
            criteriaEntry->FailEvent + 1, CRITERIA_CONDITION_MAX);

        auto treeItr = _criteriaTreeByCriteria.find(criteriaEntry->ID);
        if (treeItr == _criteriaTreeByCriteria.end())
            continue;

        Criteria* criteria = new Criteria();
        criteria->ID = criteriaEntry->ID;
        criteria->Entry = criteriaEntry;
        criteria->Modifier = Trinity::Containers::MapGetValuePtr(_criteriaModifiers, criteriaEntry->ModifierTreeId);

        _criteria[criteria->ID] = criteria;

        for (CriteriaTree const* tree : treeItr->second)
        {
            const_cast<CriteriaTree*>(tree)->Criteria = criteria;

            if (AchievementEntry const* achievement = tree->Achievement)
            {
                if (achievement->Flags & ACHIEVEMENT_FLAG_GUILD)
                    criteria->FlagsCu |= CRITERIA_FLAG_CU_GUILD;
                else if (achievement->Flags & ACHIEVEMENT_FLAG_ACCOUNT)
                    criteria->FlagsCu |= CRITERIA_FLAG_CU_ACCOUNT;
                else
                    criteria->FlagsCu |= CRITERIA_FLAG_CU_PLAYER;
            }
            else if (tree->ScenarioStep)
                criteria->FlagsCu |= CRITERIA_FLAG_CU_SCENARIO;
            else if (tree->QuestObjective)
                criteria->FlagsCu |= CRITERIA_FLAG_CU_QUEST_OBJECTIVE;
        }

        if (criteria->FlagsCu & (CRITERIA_FLAG_CU_PLAYER | CRITERIA_FLAG_CU_ACCOUNT))
        {
            ++criterias;
            _criteriasByType[criteriaEntry->Type].push_back(criteria);
            if (IsCriteriaTypeStoredByAsset(CriteriaTypes(criteriaEntry->Type)))
            {
                if (criteriaEntry->Type != CRITERIA_TYPE_EXPLORE_AREA)
                    _criteriasByAsset[criteriaEntry->Type][criteriaEntry->Asset.ID].push_back(criteria);
                else
                {
                    WorldMapOverlayEntry const* worldOverlayEntry = sWorldMapOverlayStore.LookupEntry(criteriaEntry->Asset.WorldMapOverlayID);
                    if (!worldOverlayEntry)
                        break;

                    for (uint8 j = 0; j < MAX_WORLD_MAP_OVERLAY_AREA_IDX; ++j)
                    {
                        if (worldOverlayEntry->AreaID[j])
                        {
                            bool valid = true;
                            for (uint8 i = 0; i < j; ++i)
                                if (worldOverlayEntry->AreaID[j] == worldOverlayEntry->AreaID[i])
                                    valid = false;
                            if (valid)
                                _criteriasByAsset[criteriaEntry->Type][worldOverlayEntry->AreaID[j]].push_back(criteria);
                        }
                    }
                }
            }
        }

        if (criteria->FlagsCu & CRITERIA_FLAG_CU_GUILD)
        {
            ++guildCriterias;
            _guildCriteriasByType[criteriaEntry->Type].push_back(criteria);
        }

        if (criteria->FlagsCu & CRITERIA_FLAG_CU_SCENARIO)
        {
            ++scenarioCriterias;
            _scenarioCriteriasByType[criteriaEntry->Type].push_back(criteria);
        }

        if (criteria->FlagsCu & CRITERIA_FLAG_CU_QUEST_OBJECTIVE)
        {
            ++questObjectiveCriterias;
            _questObjectiveCriteriasByType[criteriaEntry->Type].push_back(criteria);
        }

        if (criteriaEntry->StartTimer)
            _criteriasByTimedType[criteriaEntry->StartEvent].push_back(criteria);

        if (criteriaEntry->FailEvent)
            _criteriasByFailEvent[criteriaEntry->FailEvent][criteriaEntry->FailAsset].push_back(criteria);
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u criteria, %u guild criteria, %u scenario criteria and %u quest objective criteria in %u ms.", criterias, guildCriterias, scenarioCriterias, questObjectiveCriterias, GetMSTimeDiffToNow(oldMSTime));
}

void CriteriaMgr::LoadCriteriaData()
{
    uint32 oldMSTime = getMSTime();

    _criteriaDataMap.clear();                              // need for reload case

    QueryResult result = WorldDatabase.Query("SELECT criteria_id, type, value1, value2, ScriptName FROM criteria_data");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 additional criteria data. DB table `criteria_data` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();
        uint32 criteria_id = fields[0].GetUInt32();

        Criteria const* criteria = GetCriteria(criteria_id);

        if (!criteria)
        {
            TC_LOG_ERROR("sql.sql", "Table `criteria_data` contains data for non-existing criteria (Entry: %u). Ignored.", criteria_id);
            continue;
        }

        uint32 dataType = fields[1].GetUInt8();
        std::string scriptName = fields[4].GetString();
        uint32 scriptId = 0;
        if (!scriptName.empty())
        {
            if (dataType != CRITERIA_DATA_TYPE_SCRIPT)
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` contains a ScriptName for non-scripted data type (Entry: %u, type %u), useless data.", criteria_id, dataType);
            else
                scriptId = sObjectMgr->GetScriptId(scriptName);
        }

        CriteriaData data(dataType, fields[2].GetUInt32(), fields[3].GetUInt32(), scriptId);

        if (!data.IsValid(criteria))
            continue;

        // this will allocate empty data set storage
        CriteriaDataSet& dataSet = _criteriaDataMap[criteria_id];
        dataSet.SetCriteriaId(criteria_id);

        // add real data only for not NONE data types
        if (data.DataType != CRITERIA_DATA_TYPE_NONE)
            dataSet.Add(data);

        // counting data by and data types
        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u additional criteria data in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

CriteriaTree const* CriteriaMgr::GetCriteriaTree(uint32 criteriaTreeId) const
{
    auto itr = _criteriaTrees.find(criteriaTreeId);
    if (itr == _criteriaTrees.end())
        return nullptr;

    return itr->second;
}

Criteria const* CriteriaMgr::GetCriteria(uint32 criteriaId) const
{
    auto itr = _criteria.find(criteriaId);
    if (itr == _criteria.end())
        return nullptr;

    return itr->second;
}

ModifierTreeNode const* CriteriaMgr::GetModifierTree(uint32 modifierTreeId) const
{
    auto itr = _criteriaModifiers.find(modifierTreeId);
    if (itr != _criteriaModifiers.end())
        return itr->second;

    return nullptr;
}
