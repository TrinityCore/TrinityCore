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

#include "AchievementMgr.h"
#include "ArenaTeamMgr.h"
#include "Battleground.h"
#include "CellImpl.h"
#include "ChatTextBuilder.h"
#include "DatabaseEnv.h"
#include "DBCEnums.h"
#include "DisableMgr.h"
#include "GameEventMgr.h"
#include "GameTime.h"
#include "GridNotifiersImpl.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "InstanceScript.h"
#include "Item.h"
#include "Language.h"
#include "Log.h"
#include "Mail.h"
#include "Map.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "RBAC.h"
#include "ReputationMgr.h"
#include "ScriptMgr.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "World.h"
#include "WorldSession.h"

bool AchievementCriteriaData::IsValid(AchievementCriteriaEntry const* criteria)
{
    if (dataType >= MAX_ACHIEVEMENT_CRITERIA_DATA_TYPE)
    {
        TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` for criteria (Entry: %u) contains a wrong data type (%u), ignored.", criteria->ID, dataType);
        return false;
    }

    switch (criteria->Type)
    {
        case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE:
        case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE_TYPE:
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_BG:
        case ACHIEVEMENT_CRITERIA_TYPE_DEATH_IN_DUNGEON:
        case ACHIEVEMENT_CRITERIA_TYPE_FALL_WITHOUT_DYING:
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST:          // only hardcoded list
        case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL:
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_ARENA:
        case ACHIEVEMENT_CRITERIA_TYPE_DO_EMOTE:
        case ACHIEVEMENT_CRITERIA_TYPE_SPECIAL_PVP_KILL:
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_DUEL:
        case ACHIEVEMENT_CRITERIA_TYPE_LOOT_TYPE:
        case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL2:
        case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET:
        case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2:
        case ACHIEVEMENT_CRITERIA_TYPE_EQUIP_EPIC_ITEM:
        case ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED_ON_LOOT:
        case ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED_ON_LOOT:
        case ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE:
        case ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL:
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST:    // only Children's Week achievements
        case ACHIEVEMENT_CRITERIA_TYPE_USE_ITEM:                // only Children's Week achievements
        case ACHIEVEMENT_CRITERIA_TYPE_GET_KILLING_BLOWS:
        case ACHIEVEMENT_CRITERIA_TYPE_REACH_LEVEL:
        case ACHIEVEMENT_CRITERIA_TYPE_ON_LOGIN:
        case ACHIEVEMENT_CRITERIA_TYPE_LOOT_EPIC_ITEM:
        case ACHIEVEMENT_CRITERIA_TYPE_RECEIVE_EPIC_ITEM:
            break;
        default:
            if (dataType != ACHIEVEMENT_CRITERIA_DATA_TYPE_SCRIPT)
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` contains data for a non-supported criteria type (Entry: %u Type: %u), ignored.", criteria->ID, criteria->Type);
                return false;
            }
            break;
    }

    switch (dataType)
    {
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_NONE:
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_INSTANCE_SCRIPT:
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_NTH_BIRTHDAY:
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_CREATURE:
            if (!creature.id || !sObjectMgr->GetCreatureTemplate(creature.id))
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_CREATURE (%u) contains a non-existing creature id in value1 (%u), ignored.",
                    criteria->ID, criteria->Type, dataType, creature.id);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_CLASS_RACE:
            if (classRace.class_id && ((1 << (classRace.class_id-1)) & CLASSMASK_ALL_PLAYABLE) == 0)
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_CLASS_RACE (%u) contains a non-existing class in value1 (%u), ignored.",
                    criteria->ID, criteria->Type, dataType, classRace.class_id);
                return false;
            }
            if (classRace.race_id && ((1 << (classRace.race_id-1)) & RACEMASK_ALL_PLAYABLE) == 0)
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_CLASS_RACE (%u) contains a non-existing race in value2 (%u), ignored.",
                    criteria->ID, criteria->Type, dataType, classRace.race_id);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_LESS_HEALTH:
            if (health.percent < 1 || health.percent > 100)
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_PLAYER_LESS_HEALTH (%u) contains a wrong percent value in value1 (%u), ignored.",
                    criteria->ID, criteria->Type, dataType, health.percent);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_DEAD:
            if (player_dead.own_team_flag > 1)
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_DEAD (%u) contains a wrong boolean value1 (%u).",
                    criteria->ID, criteria->Type, dataType, player_dead.own_team_flag);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA:
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_AURA:
        {
            SpellInfo const* spellEntry = sSpellMgr->GetSpellInfo(aura.spell_id);
            if (!spellEntry)
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type %s (%u) contains a wrong spell id in value1 (%u), ignored.",
                    criteria->ID, criteria->Type, (dataType == ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA?"ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA":"ACHIEVEMENT_CRITERIA_DATA_TYPE_T_AURA"), dataType, aura.spell_id);
                return false;
            }
            if (aura.effect_idx >= 3)
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type %s (%u) contains a wrong spell effect index in value2 (%u), ignored.",
                    criteria->ID, criteria->Type, (dataType == ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA?"ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA":"ACHIEVEMENT_CRITERIA_DATA_TYPE_T_AURA"), dataType, aura.effect_idx);
                return false;
            }
            if (!spellEntry->Effects[aura.effect_idx].ApplyAuraName)
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type %s (%u) contains a non-aura spell effect (ID: %u Effect: %u), ignored.",
                    criteria->ID, criteria->Type, (dataType == ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA?"ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA":"ACHIEVEMENT_CRITERIA_DATA_TYPE_T_AURA"), dataType, aura.spell_id, aura.effect_idx);
                return false;
            }
            return true;
        }
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AREA:
            if (!sAreaTableStore.LookupEntry(area.id))
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AREA (%u) contains a wrong area id in value1 (%u), ignored.",
                    criteria->ID, criteria->Type, dataType, area.id);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_VALUE:
            if (value.compType >= COMP_TYPE_MAX)
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_VALUE (%u) contains a wrong ComparisionType in value2 (%u), ignored.",
                    criteria->ID, criteria->Type, dataType, value.compType);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_LEVEL:
            if (level.minlevel > STRONG_MAX_LEVEL)
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_T_LEVEL (%u) contains a wrong minlevel in value1 (%u), ignored.",
                    criteria->ID, criteria->Type, dataType, level.minlevel);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_GENDER:
            if (gender.gender > GENDER_NONE)
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_T_GENDER (%u) contains a wrong gender value in value1 (%u), ignored.",
                    criteria->ID, criteria->Type, dataType, gender.gender);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_SCRIPT:
            if (!ScriptId)
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_SCRIPT (%u) does not have a ScriptName set, ignored.",
                    criteria->ID, criteria->Type, dataType);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_MAP_DIFFICULTY:
            if (difficulty.difficulty >= MAX_DIFFICULTY)
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_MAP_DIFFICULTY (%u) contains a wrong difficulty value in value1 (%u), ignored.",
                    criteria->ID, criteria->Type, dataType, difficulty.difficulty);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_MAP_PLAYER_COUNT:
            if (map_players.maxcount <= 0)
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_MAP_PLAYER_COUNT (%u) contains a wrong max players count in value1 (%u), ignored.",
                    criteria->ID, criteria->Type, dataType, map_players.maxcount);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_TEAM:
            if (team.team != ALLIANCE && team.team != HORDE)
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_T_TEAM (%u) contains an unknown team value in value1 (%u), ignored.",
                    criteria->ID, criteria->Type, dataType, team.team);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_DRUNK:
            if (drunk.state >= MAX_DRUNKEN)
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_S_DRUNK (%u) contains an unknown drunken state value in value1 (%u), ignored.",
                    criteria->ID, criteria->Type, dataType, drunk.state);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_HOLIDAY:
            if (!sHolidaysStore.LookupEntry(holiday.id))
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_HOLIDAY (%u) contains an unknown holiday entry in value1 (%u), ignored.",
                    criteria->ID, criteria->Type, dataType, holiday.id);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_BG_LOSS_TEAM_SCORE:
            return true;                                    // not check correctness node indexes
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_EQUIPPED_ITEM:
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_ITEM_QUALITY:
            if (equipped_item.item_quality >= MAX_ITEM_QUALITY)
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type %s (%u) contains an unknown quality state value in value1 (%u), ignored.",
                    criteria->ID, criteria->Type, (dataType == ACHIEVEMENT_CRITERIA_DATA_TYPE_S_EQUIPPED_ITEM ? "ACHIEVEMENT_CRITERIA_DATA_TYPE_S_EQUIPPED_ITEM" : "ACHIEVEMENT_CRITERIA_DATA_TYPE_S_ITEM_QUALITY"), dataType, equipped_item.item_quality);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_MAP_ID:
            if (!sMapStore.LookupEntry(map_id.mapId))
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_MAP_ID (%u) contains an unknown map id in value1 (%u), ignored.",
                    criteria->ID, criteria->Type, dataType, map_id.mapId);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_PLAYER_CLASS_RACE:
            if (!classRace.class_id && !classRace.race_id)
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_S_PLAYER_CLASS_RACE (%u) should not have 0 in either value field. Ignored.",
                    criteria->ID, criteria->Type, dataType);
                return false;
            }
            if (classRace.class_id && ((1 << (classRace.class_id-1)) & CLASSMASK_ALL_PLAYABLE) == 0)
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_S_PLAYER_CLASS_RACE (%u) contains a non-existing class entry in value1 (%u), ignored.",
                    criteria->ID, criteria->Type, dataType, classRace.class_id);
                return false;
            }
            if (classRace.race_id && ((1 << (classRace.race_id-1)) & RACEMASK_ALL_PLAYABLE) == 0)
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_S_PLAYER_CLASS_RACE (%u) contains a non-existing race entry in value2 (%u), ignored.",
                    criteria->ID, criteria->Type, dataType, classRace.race_id);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_KNOWN_TITLE:
            if (!sCharTitlesStore.LookupEntry(known_title.title_id))
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_S_KNOWN_TITLE (%u) contains an unknown title_id in value1 (%u), ignore.",
                    criteria->ID, criteria->Type, dataType, known_title.title_id);
                return false;
            }
            return true;
        default:
            TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` (Entry: %u Type: %u) contains data of a non-supported data type (%u), ignored.", criteria->ID, criteria->Type, dataType);
            return false;
    }
}

bool AchievementCriteriaData::Meets(uint32 criteria_id, Player const* source, WorldObject const* target, uint32 miscvalue1 /*= 0*/, uint32 miscvalue2 /* = 0*/) const
{
    switch (dataType)
    {
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_NONE:
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_CREATURE:
            if (!target || target->GetTypeId() != TYPEID_UNIT)
                return false;
            return target->GetEntry() == creature.id;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_CLASS_RACE:
            if (!target || target->GetTypeId() != TYPEID_PLAYER)
                return false;
            if (classRace.class_id && classRace.class_id != target->ToPlayer()->GetClass())
                return false;
            if (classRace.race_id && classRace.race_id != target->ToPlayer()->GetRace())
                return false;
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_PLAYER_CLASS_RACE:
            if (source->GetTypeId() != TYPEID_PLAYER)
                return false;
            if (classRace.class_id && classRace.class_id != source->ToPlayer()->GetClass())
                return false;
            if (classRace.race_id && classRace.race_id != source->ToPlayer()->GetRace())
                return false;
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_LESS_HEALTH:
            if (!target || target->GetTypeId() != TYPEID_PLAYER)
                return false;
            return !target->ToPlayer()->HealthAbovePct(health.percent);
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_DEAD:
            if (!target || target->GetTypeId() != TYPEID_PLAYER)
                return false;
            if (Player const* player = target->ToPlayer())
                if (!player->IsAlive() && player->GetDeathTimer() != 0)
                    // flag set == must be same team, not set == different team
                    return (player->GetTeam() == source->GetTeam()) == (player_dead.own_team_flag != 0);
            return false;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA:
            return source->HasAuraEffect(aura.spell_id, aura.effect_idx);
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AREA:
        {
            uint32 zone_id, area_id;
            source->GetZoneAndAreaId(zone_id, area_id);
            return area.id == zone_id || area.id == area_id;
        }
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_AURA:
        {
            if (!target)
                return false;
            Unit const* unitTarget = target->ToUnit();
            if (!unitTarget)
                return false;
            return unitTarget->HasAuraEffect(aura.spell_id, aura.effect_idx);
        }
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_VALUE:
            return CompareValues(ComparisionType(value.compType), miscvalue1, value.value);
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_LEVEL:
        {
            if (!target)
                return false;
            Unit const* unitTarget = target->ToUnit();
            if (!unitTarget)
                return false;
            return unitTarget->GetLevel() >= level.minlevel;
        }
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_GENDER:
        {
            if (!target)
                return false;
            Unit const* unitTarget = target->ToUnit();
            if (!unitTarget)
                return false;
            return unitTarget->GetGender() == gender.gender;
        }
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_SCRIPT:
        {
            Unit const* unitTarget = nullptr;
            if (target)
                unitTarget = target->ToUnit();
            return sScriptMgr->OnCriteriaCheck(ScriptId, const_cast<Player*>(source), const_cast<Unit*>(unitTarget));
        }
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_MAP_DIFFICULTY:
            if (source->GetMap()->IsRaid())
                if (source->GetMap()->Is25ManRaid() != ((difficulty.difficulty & RAID_DIFFICULTY_MASK_25MAN) != 0))
                    return false;
            return source->GetMap()->GetSpawnMode() >= difficulty.difficulty;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_MAP_PLAYER_COUNT:
            return source->GetMap()->GetPlayersCountExceptGMs() <= map_players.maxcount;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_TEAM:
            if (!target || target->GetTypeId() != TYPEID_PLAYER)
                return false;
            return target->ToPlayer()->GetTeam() == team.team;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_DRUNK:
            return Player::GetDrunkenstateByValue(source->GetDrunkValue()) >= DrunkenState(drunk.state);
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_HOLIDAY:
            return IsHolidayActive(HolidayIds(holiday.id));
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_BG_LOSS_TEAM_SCORE:
        {
            Battleground* bg = source->GetBattleground();
            if (!bg)
                return false;

            uint32 score = bg->GetTeamScore(source->GetTeamId() == TEAM_ALLIANCE ? TEAM_HORDE : TEAM_ALLIANCE);
            return score >= bg_loss_team_score.min_score && score <= bg_loss_team_score.max_score;
        }
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_INSTANCE_SCRIPT:
        {
            if (!source->IsInWorld())
                return false;
            Map* map = source->GetMap();
            if (!map->IsDungeon())
            {
                TC_LOG_ERROR("achievement", "Achievement system call ACHIEVEMENT_CRITERIA_DATA_TYPE_INSTANCE_SCRIPT (%u) for achievement criteria %u in a non-dungeon/non-raid map %u",
                    dataType, criteria_id, map->GetId());
                return false;
            }
            InstanceScript* instance = map->ToInstanceMap()->GetInstanceScript();
            if (!instance)
            {
                TC_LOG_ERROR("achievement", "Achievement system call ACHIEVEMENT_CRITERIA_DATA_TYPE_INSTANCE_SCRIPT (%u) for achievement criteria %u in map %u, but the map does not have an instance script.",
                    dataType, criteria_id, map->GetId());
                return false;
            }

            Unit const* unitTarget = nullptr;
            if (target)
                unitTarget = target->ToUnit();
            return instance->CheckAchievementCriteriaMeet(criteria_id, source, unitTarget, miscvalue1);
        }
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_EQUIPPED_ITEM:
        {
            AchievementCriteriaEntry const* entry = ASSERT_NOTNULL(sAchievementMgr->GetAchievementCriteria(criteria_id));

            uint32 itemId = (entry->Type == ACHIEVEMENT_CRITERIA_TYPE_EQUIP_EPIC_ITEM ? miscvalue2 : miscvalue1);
            ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(itemId);
            if (!itemTemplate)
                return false;
            return itemTemplate->ItemLevel >= equipped_item.item_level && itemTemplate->Quality >= equipped_item.item_quality;
        }
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_MAP_ID:
            return source->GetMapId() == map_id.mapId;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_NTH_BIRTHDAY:
        {
            time_t birthday_start = time_t(sWorld->getIntConfig(CONFIG_BIRTHDAY_TIME));
            tm birthday_tm;
            localtime_r(&birthday_start, &birthday_tm);

            // exactly N birthday
            birthday_tm.tm_year += birthday_login.nth_birthday;

            time_t birthday = mktime(&birthday_tm);
            time_t now = GameTime::GetGameTime();
            return now <= birthday + DAY && now >= birthday;
        }
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_KNOWN_TITLE:
        {
            if (CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(known_title.title_id))
                return source->HasTitle(titleInfo->bit_index);
            return false;
        }
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_ITEM_QUALITY:
        {
            ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(miscvalue1);
            if (!pProto)
                return false;
            return pProto->Quality == item.item_quality;
        }
        default:
            break;
    }
    return false;
}

bool AchievementCriteriaDataSet::Meets(Player const* source, WorldObject const* target, uint32 miscvalue1 /*= 0*/, uint32 miscvalue2 /* = 0*/) const
{
    for (Storage::const_iterator itr = storage.begin(); itr != storage.end(); ++itr)
        if (!itr->Meets(criteria_id, source, target, miscvalue1, miscvalue2))
            return false;

    return true;
}

AchievementMgr::AchievementMgr(Player* player)
{
    m_player = player;
}

AchievementMgr::~AchievementMgr() { }

void AchievementMgr::Reset()
{
    for (CompletedAchievementMap::const_iterator iter = m_completedAchievements.begin(); iter != m_completedAchievements.end(); ++iter)
    {
        WorldPacket data(SMSG_ACHIEVEMENT_DELETED, 4);
        data << uint32(iter->first);
        m_player->SendDirectMessage(&data);
    }

    for (CriteriaProgressMap::const_iterator iter = m_criteriaProgress.begin(); iter != m_criteriaProgress.end(); ++iter)
    {
        WorldPacket data(SMSG_CRITERIA_DELETED, 4);
        data << uint32(iter->first);
        m_player->SendDirectMessage(&data);
    }

    m_completedAchievements.clear();
    m_criteriaProgress.clear();
    DeleteFromDB(m_player->GetGUID());

    // re-fill data
    CheckAllAchievementCriteria();
}

void AchievementMgr::ResetAchievementCriteria(AchievementCriteriaCondition condition, uint32 value, bool evenIfCriteriaComplete)
{
    TC_LOG_DEBUG("achievement", "AchievementMgr::ResetAchievementCriteria(%u, %u, %u)", condition, value, evenIfCriteriaComplete);

    // Disable for GameMasters with GM-mode enabled or for players that don't have the related RBAC permission
    if (m_player->IsGameMaster() || m_player->GetSession()->HasPermission(rbac::RBAC_PERM_CANNOT_EARN_ACHIEVEMENTS))
        return;

    AchievementCriteriaEntryList const* achievementCriteriaList = sAchievementMgr->GetAchievementCriteriaByCondition(condition, value);
    if (!achievementCriteriaList)
        return;

    for (auto itr = achievementCriteriaList->begin(); itr != achievementCriteriaList->end(); ++itr)
    {
        AchievementCriteriaEntry const* achievementCriteria = *itr;
        AchievementEntry const* achievement = sAchievementMgr->GetAchievement(achievementCriteria->ReferredAchievement);
        if (!achievement)
            continue;

        // don't update already completed criteria if not forced or achievement already complete
        if ((IsCompletedCriteria(achievementCriteria, achievement) && !evenIfCriteriaComplete) || HasAchieved(achievement->ID))
            continue;

        RemoveCriteriaProgress(achievementCriteria);
    }
}

void AchievementMgr::DeleteFromDB(ObjectGuid guid)
{
    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_ACHIEVEMENT);
    stmt->setUInt32(0, guid.GetCounter());
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_ACHIEVEMENT_PROGRESS);
    stmt->setUInt32(0, guid.GetCounter());
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);
}

void AchievementMgr::SaveToDB(SQLTransaction& trans)
{
    if (!m_completedAchievements.empty())
    {
        for (CompletedAchievementMap::iterator iter = m_completedAchievements.begin(); iter != m_completedAchievements.end(); ++iter)
        {
            if (!iter->second.changed)
                continue;

            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_ACHIEVEMENT_BY_ACHIEVEMENT);
            stmt->setUInt16(0, iter->first);
            stmt->setUInt32(1, GetPlayer()->GetGUID().GetCounter());
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_ACHIEVEMENT);
            stmt->setUInt32(0, GetPlayer()->GetGUID().GetCounter());
            stmt->setUInt16(1, iter->first);
            stmt->setUInt32(2, uint32(iter->second.date));
            trans->Append(stmt);

            iter->second.changed = false;
        }
    }

    if (!m_criteriaProgress.empty())
    {
        for (CriteriaProgressMap::iterator iter = m_criteriaProgress.begin(); iter != m_criteriaProgress.end(); ++iter)
        {
            if (!iter->second.changed)
                continue;

            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_ACHIEVEMENT_PROGRESS_BY_CRITERIA);
            stmt->setUInt32(0, GetPlayer()->GetGUID().GetCounter());
            stmt->setUInt16(1, iter->first);
            trans->Append(stmt);

            if (iter->second.counter)
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_ACHIEVEMENT_PROGRESS);
                stmt->setUInt32(0, GetPlayer()->GetGUID().GetCounter());
                stmt->setUInt16(1, iter->first);
                stmt->setUInt32(2, iter->second.counter);
                stmt->setUInt32(3, uint32(iter->second.date));
                trans->Append(stmt);
            }

            iter->second.changed = false;
        }
    }
}

void AchievementMgr::LoadFromDB(PreparedQueryResult achievementResult, PreparedQueryResult criteriaResult)
{
    if (achievementResult)
    {
        do
        {
            Field* fields = achievementResult->Fetch();
            uint32 achievementid = fields[0].GetUInt16();

            // must not happen: cleanup at server startup in sAchievementMgr->LoadCompletedAchievements()
            AchievementEntry const* achievement = sAchievementMgr->GetAchievement(achievementid);
            if (!achievement)
                continue;

            CompletedAchievementData& ca = m_completedAchievements[achievementid];
            ca.date = time_t(fields[1].GetUInt32());
            ca.changed = false;

            // title achievement rewards are retroactive
            if (AchievementReward const* reward = sAchievementMgr->GetAchievementReward(achievement))
                if (uint32 titleId = reward->TitleId[Player::TeamForRace(GetPlayer()->GetRace()) == ALLIANCE ? 0 : 1])
                    if (CharTitlesEntry const* titleEntry = sCharTitlesStore.LookupEntry(titleId))
                        GetPlayer()->SetTitle(titleEntry);

        } while (achievementResult->NextRow());
    }

    if (criteriaResult)
    {
        do
        {
            Field* fields  = criteriaResult->Fetch();
            uint32 id      = fields[0].GetUInt16();
            uint32 counter = fields[1].GetUInt32();
            time_t date    = time_t(fields[2].GetUInt32());

            AchievementCriteriaEntry const* criteria = sAchievementMgr->GetAchievementCriteria(id);
            if (!criteria)
            {
                // Removing non-existing criteria data for all characters
                TC_LOG_ERROR("achievement", "Non-existing achievement criteria %u data has been removed from the table `character_achievement_progress`.", id);

                PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_INVALID_ACHIEV_PROGRESS_CRITERIA);

                stmt->setUInt16(0, uint16(id));

                CharacterDatabase.Execute(stmt);

                continue;
            }

            if (criteria->StartTimer && time_t(date + criteria->StartTimer) < GameTime::GetGameTime())
                continue;

            CriteriaProgress& progress = m_criteriaProgress[id];
            progress.counter = counter;
            progress.date    = date;
            progress.changed = false;
        } while (criteriaResult->NextRow());
    }
}

void AchievementMgr::SendAchievementEarned(AchievementEntry const* achievement) const
{
    if (GetPlayer()->GetSession()->PlayerLoading())
        return;

    // Don't send for achievements with ACHIEVEMENT_FLAG_TRACKING
    if (achievement->Flags & ACHIEVEMENT_FLAG_HIDDEN)
        return;

    #ifdef TRINITY_DEBUG
        TC_LOG_DEBUG("achievement", "AchievementMgr::SendAchievementEarned(%u)", achievement->ID);
    #endif

    if (Guild* guild = sGuildMgr->GetGuildById(GetPlayer()->GetGuildId()))
    {
        Trinity::BroadcastTextBuilder _builder(GetPlayer(), CHAT_MSG_GUILD_ACHIEVEMENT, BROADCAST_TEXT_ACHIEVEMENT_EARNED, GetPlayer()->GetGender(), GetPlayer(), achievement->ID);
        Trinity::LocalizedPacketDo<Trinity::BroadcastTextBuilder> _localizer(_builder);
        guild->BroadcastWorker(_localizer, GetPlayer());
    }

    if (achievement->Flags & (ACHIEVEMENT_FLAG_REALM_FIRST_KILL | ACHIEVEMENT_FLAG_REALM_FIRST_REACH))
    {
        uint32 team = GetPlayer()->GetTeam();

        // broadcast realm first reached
        WorldPacket data(SMSG_SERVER_FIRST_ACHIEVEMENT, GetPlayer()->GetName().size() + 1 + 8 + 4 + 4);
        data << GetPlayer()->GetName();
        data << uint64(GetPlayer()->GetGUID());
        data << uint32(achievement->ID);

        std::size_t linkTypePos = data.wpos();
        data << uint32(1);                                  // display name as clickable link in chat
        sWorld->SendGlobalMessage(&data, nullptr, team);

        data.put<uint32>(linkTypePos, 0);                   // display name as plain string in chat
        sWorld->SendGlobalMessage(&data, nullptr, team == ALLIANCE ? HORDE : ALLIANCE);
    }
    // if player is in world he can tell his friends about new achievement
    else if (GetPlayer()->IsInWorld())
    {
        Trinity::BroadcastTextBuilder _builder(GetPlayer(), CHAT_MSG_ACHIEVEMENT, BROADCAST_TEXT_ACHIEVEMENT_EARNED, GetPlayer()->GetGender(), GetPlayer(), achievement->ID);
        Trinity::LocalizedPacketDo<Trinity::BroadcastTextBuilder> _localizer(_builder);
        Trinity::PlayerDistWorker<Trinity::LocalizedPacketDo<Trinity::BroadcastTextBuilder>> _worker(GetPlayer(), sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_SAY), _localizer);
        Cell::VisitWorldObjects(GetPlayer(), _worker, sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_SAY));
    }

    WorldPacket data(SMSG_ACHIEVEMENT_EARNED, 8+4+8);
    data << GetPlayer()->GetPackGUID();
    data << uint32(achievement->ID);
    data.AppendPackedTime(GameTime::GetGameTime());
    data << uint32(0);
    GetPlayer()->SendMessageToSetInRange(&data, sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_SAY), true);
}

void AchievementMgr::SendCriteriaUpdate(AchievementCriteriaEntry const* entry, CriteriaProgress const* progress, uint32 timeElapsed, bool timedCompleted) const
{
    WorldPacket data(SMSG_CRITERIA_UPDATE, 8+4+8);
    data << uint32(entry->ID);

    // the counter is packed like a packed Guid
    data.appendPackGUID(progress->counter);

    data << GetPlayer()->GetPackGUID();
    if (!entry->StartTimer)
        data << uint32(0);
    else
        data << uint32(timedCompleted ? 1 : 0); // this are some flags, 1 is for keeping the counter at 0 in client
    data.AppendPackedTime(progress->date);
    data << uint32(timeElapsed);    // time elapsed in seconds
    data << uint32(0);              // unk
    GetPlayer()->SendDirectMessage(&data);
}

/**
 * called at player login. The player might have fulfilled some achievements when the achievement system wasn't working yet
 */
void AchievementMgr::CheckAllAchievementCriteria()
{
    // suppress sending packets
    for (uint32 i = 0; i < ACHIEVEMENT_CRITERIA_TYPE_TOTAL; ++i)
        UpdateAchievementCriteria(AchievementCriteriaTypes(i));
}

static const uint32 achievIdByArenaSlot[MAX_ARENA_SLOT] = { 1057, 1107, 1108 };

/**
 * this function will be called whenever the user might have done a criteria relevant action
 */
void AchievementMgr::UpdateAchievementCriteria(AchievementCriteriaTypes type, uint32 miscValue1 /*= 0*/, uint32 miscValue2 /*= 0*/, WorldObject* ref /*= nullptr*/)
{
    if (type >= ACHIEVEMENT_CRITERIA_TYPE_TOTAL)
    {
        TC_LOG_DEBUG("achievement", "UpdateAchievementCriteria: Wrong criteria type %u", type);
        return;
    }

    // Disable for GameMasters with GM-mode enabled or for players that don't have the related RBAC permission
    if (m_player->IsGameMaster() || m_player->GetSession()->HasPermission(rbac::RBAC_PERM_CANNOT_EARN_ACHIEVEMENTS))
    {
        TC_LOG_DEBUG("achievement", "UpdateAchievementCriteria: [Player %s %s] %s, %s (%u), %u, %u"
            , m_player->GetName().c_str(), m_player->IsGameMaster() ? "GM mode on" : "disallowed by RBAC", m_player->GetGUID().ToString().c_str(), AchievementGlobalMgr::GetCriteriaTypeString(type), type, miscValue1, miscValue2);
        return;
    }

    TC_LOG_DEBUG("achievement", "UpdateAchievementCriteria: %s, %s (%u), %u, %u"
        , m_player->GetGUID().ToString().c_str(), AchievementGlobalMgr::GetCriteriaTypeString(type), type, miscValue1, miscValue2);

    AchievementCriteriaEntryList const& achievementCriteriaList = sAchievementMgr->GetAchievementCriteriaByType(type, miscValue1);
    for (AchievementCriteriaEntry const* achievementCriteria : achievementCriteriaList)
    {
        AchievementEntry const* achievement = sAchievementMgr->GetAchievement(achievementCriteria->ReferredAchievement);
        if (!achievement)
            continue;

        if (!CanUpdateCriteria(achievementCriteria, achievement, miscValue1, miscValue2, ref))
            continue;

        switch (type)
        {
            // special cases, db data is checked later
            case ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_ARENA:
            case ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED_ON_LOOT:
            case ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED_ON_LOOT:
                break;
            default:
                if (AchievementCriteriaDataSet const* data = sAchievementMgr->GetCriteriaDataSet(achievementCriteria))
                    if (!data->Meets(GetPlayer(), ref, miscValue1, miscValue2))
                        continue;
                break;
        }

        switch (type)
        {
            // std. case: increment at 1
            case ACHIEVEMENT_CRITERIA_TYPE_WIN_BG:
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST:
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_BATTLEGROUND:
            case ACHIEVEMENT_CRITERIA_TYPE_DEATH_AT_MAP:
            case ACHIEVEMENT_CRITERIA_TYPE_DEATH:
            case ACHIEVEMENT_CRITERIA_TYPE_DEATH_IN_DUNGEON:
            case ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_CREATURE:
            case ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_PLAYER:
            case ACHIEVEMENT_CRITERIA_TYPE_DEATHS_FROM:
            case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET:
            case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL:
            case ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE:
            case ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL_AT_AREA:
            case ACHIEVEMENT_CRITERIA_TYPE_WIN_ARENA: // This also behaves like ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_ARENA
            case ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL:
            case ACHIEVEMENT_CRITERIA_TYPE_USE_ITEM:
            case ACHIEVEMENT_CRITERIA_TYPE_HK_CLASS:
            case ACHIEVEMENT_CRITERIA_TYPE_HK_RACE:
            case ACHIEVEMENT_CRITERIA_TYPE_DO_EMOTE:
            case ACHIEVEMENT_CRITERIA_TYPE_GET_KILLING_BLOWS:
            case ACHIEVEMENT_CRITERIA_TYPE_NUMBER_OF_TALENT_RESETS:
            case ACHIEVEMENT_CRITERIA_TYPE_USE_GAMEOBJECT:
            case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2:
            case ACHIEVEMENT_CRITERIA_TYPE_SPECIAL_PVP_KILL:
            case ACHIEVEMENT_CRITERIA_TYPE_FISH_IN_GAMEOBJECT:
            case ACHIEVEMENT_CRITERIA_TYPE_ON_LOGIN:
            case ACHIEVEMENT_CRITERIA_TYPE_WIN_DUEL:
            case ACHIEVEMENT_CRITERIA_TYPE_LOSE_DUEL:
            case ACHIEVEMENT_CRITERIA_TYPE_CREATE_AUCTION:
            case ACHIEVEMENT_CRITERIA_TYPE_WON_AUCTIONS:            /* FIXME: for online player only currently */
            case ACHIEVEMENT_CRITERIA_TYPE_LOOT_EPIC_ITEM:
            case ACHIEVEMENT_CRITERIA_TYPE_RECEIVE_EPIC_ITEM:
            case ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED:
            case ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED:
            case ACHIEVEMENT_CRITERIA_TYPE_QUEST_ABANDONED:
            case ACHIEVEMENT_CRITERIA_TYPE_FLIGHT_PATHS_TAKEN:
            case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL2:
            case ACHIEVEMENT_CRITERIA_TYPE_ACCEPTED_SUMMONINGS:
                SetCriteriaProgress(achievementCriteria, 1, PROGRESS_ACCUMULATE);
                break;
            // std case: increment at miscvalue1
            case ACHIEVEMENT_CRITERIA_TYPE_DAMAGE_DONE:
            case ACHIEVEMENT_CRITERIA_TYPE_HEALING_DONE:
            case ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_VENDORS:
            case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_TALENTS:
            case ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_QUEST_REWARD:
            case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_TRAVELLING:
            case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_AT_BARBER:
            case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_MAIL:
            case ACHIEVEMENT_CRITERIA_TYPE_LOOT_MONEY:
            case ACHIEVEMENT_CRITERIA_TYPE_GOLD_EARNED_BY_AUCTIONS: /* FIXME: for online player only currently */
            case ACHIEVEMENT_CRITERIA_TYPE_TOTAL_DAMAGE_RECEIVED:
            case ACHIEVEMENT_CRITERIA_TYPE_TOTAL_HEALING_RECEIVED:
            case ACHIEVEMENT_CRITERIA_TYPE_USE_LFD_TO_GROUP_WITH_PLAYERS:
                SetCriteriaProgress(achievementCriteria, miscValue1, PROGRESS_ACCUMULATE);
                break;
            // std case: increment at miscvalue2
            case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE:
            case ACHIEVEMENT_CRITERIA_TYPE_OWN_ITEM:
            case ACHIEVEMENT_CRITERIA_TYPE_LOOT_ITEM:
            case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE_TYPE:
            case ACHIEVEMENT_CRITERIA_TYPE_LOOT_TYPE:
                SetCriteriaProgress(achievementCriteria, miscValue2, PROGRESS_ACCUMULATE);
                break;
            // std case: high value at miscvalue1
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_AUCTION_BID:
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_AUCTION_SOLD: /* FIXME: for online player only currently */
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HIT_DEALT:
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HIT_RECEIVED:
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEAL_CAST:
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEALING_RECEIVED:
                SetCriteriaProgress(achievementCriteria, miscValue1, PROGRESS_HIGHEST);
                break;
            // std. case: set at 1
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST:
            case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SPELL:
            case ACHIEVEMENT_CRITERIA_TYPE_EXPLORE_AREA:
            case ACHIEVEMENT_CRITERIA_TYPE_VISIT_BARBER_SHOP:
            case ACHIEVEMENT_CRITERIA_TYPE_EQUIP_EPIC_ITEM:
            case ACHIEVEMENT_CRITERIA_TYPE_EQUIP_ITEM:
                SetCriteriaProgress(achievementCriteria, 1, PROGRESS_SET);
                break;

            // specialized cases
            case ACHIEVEMENT_CRITERIA_TYPE_REACH_LEVEL:
                SetCriteriaProgress(achievementCriteria, GetPlayer()->GetLevel());
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_REACH_SKILL_LEVEL:
                if (uint32 skillvalue = GetPlayer()->GetBaseSkillValue(achievementCriteria->Asset.SkillID))
                    SetCriteriaProgress(achievementCriteria, skillvalue);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LEVEL:
                if (uint32 maxSkillvalue = GetPlayer()->GetPureMaxSkillValue(achievementCriteria->Asset.SkillID))
                    SetCriteriaProgress(achievementCriteria, maxSkillvalue);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_ACHIEVEMENT:
                if ((miscValue1 && achievementCriteria->Asset.AchievementID == miscValue1) || (!miscValue1 && m_completedAchievements.find(achievementCriteria->Asset.AchievementID) != m_completedAchievements.end()))
                    SetCriteriaProgress(achievementCriteria, 1);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST_COUNT:
                SetCriteriaProgress(achievementCriteria, GetPlayer()->GetRewardedQuestCount());
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST_DAILY:
            {
                time_t nextDailyResetTime = sWorld->GetNextDailyQuestsResetTime();
                CriteriaProgress const* progress = GetCriteriaProgress(achievementCriteria);

                if (!miscValue1) // Login case.
                {
                    // reset if player missed one day.
                    if (progress && progress->date < (nextDailyResetTime - 2 * DAY))
                        SetCriteriaProgress(achievementCriteria, 0, PROGRESS_SET);
                    continue;
                }

                ProgressType progressType;
                if (!progress)
                    // 1st time. Start count.
                    progressType = PROGRESS_SET;
                else if (progress->date < (nextDailyResetTime - 2 * DAY))
                    // last progress is older than 2 days. Player missed 1 day => Retart count.
                    progressType = PROGRESS_SET;
                else if (progress->date < (nextDailyResetTime - DAY))
                    // last progress is between 1 and 2 days. => 1st time of the day.
                    progressType = PROGRESS_ACCUMULATE;
                else
                    // last progress is within the day before the reset => Already counted today.
                    continue;

                SetCriteriaProgress(achievementCriteria, 1, progressType);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUESTS_IN_ZONE:
            {
                uint32 counter = 0;

                RewardedQuestSet const& rewQuests = GetPlayer()->getRewardedQuests();
                for (RewardedQuestSet::const_iterator itr = rewQuests.begin(); itr != rewQuests.end(); ++itr)
                {
                    Quest const* quest = sObjectMgr->GetQuestTemplate(*itr);
                    if (quest && quest->GetZoneOrSort() >= 0 && uint32(quest->GetZoneOrSort()) == achievementCriteria->Asset.ZoneID)
                        ++counter;
                }
                SetCriteriaProgress(achievementCriteria, counter);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_FALL_WITHOUT_DYING:
                // miscvalue1 is the ingame fallheight*100 as stored in dbc
                SetCriteriaProgress(achievementCriteria, miscValue1);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_ARENA:
                // additional requirements
                if (achievementCriteria->AdditionalRequirements[0].Type == ACHIEVEMENT_CRITERIA_CONDITION_NO_LOSE)
                {
                    // those requirements couldn't be found in the dbc
                    AchievementCriteriaDataSet const* data = sAchievementMgr->GetCriteriaDataSet(achievementCriteria);
                    if (!data || !data->Meets(GetPlayer(), ref, miscValue1))
                    {
                        // reset the progress as we have a win without the requirement.
                        SetCriteriaProgress(achievementCriteria, 0);
                        continue;
                    }
                }

                SetCriteriaProgress(achievementCriteria, 1, PROGRESS_ACCUMULATE);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_BUY_BANK_SLOT:
                SetCriteriaProgress(achievementCriteria, GetPlayer()->GetBankBagSlotCount());
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_GAIN_REPUTATION:
            {
                int32 reputation = GetPlayer()->GetReputationMgr().GetReputation(achievementCriteria->Asset.FactionID);
                if (reputation > 0)
                    SetCriteriaProgress(achievementCriteria, reputation);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_GAIN_EXALTED_REPUTATION:
                SetCriteriaProgress(achievementCriteria, GetPlayer()->GetReputationMgr().GetExaltedFactionCount());
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED_ON_LOOT:
            case ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED_ON_LOOT:
            {
                ItemTemplate const* proto = sObjectMgr->GetItemTemplate(miscValue1);
                if (!proto)
                    continue;

                // check item level via achievement_criteria_data
                AchievementCriteriaDataSet const* data = sAchievementMgr->GetCriteriaDataSet(achievementCriteria);
                if (!data || !data->Meets(GetPlayer(), nullptr, proto->ItemLevel))
                    continue;

                SetCriteriaProgress(achievementCriteria, 1, PROGRESS_ACCUMULATE);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILLLINE_SPELLS:
            {
                uint32 spellCount = 0;
                for (PlayerSpellMap::const_iterator spellIter = GetPlayer()->GetSpellMap().begin();
                    spellIter != GetPlayer()->GetSpellMap().end();
                    ++spellIter)
                {
                    SkillLineAbilityMapBounds bounds = sSpellMgr->GetSkillLineAbilityMapBounds(spellIter->first);
                    for (SkillLineAbilityMap::const_iterator skillIter = bounds.first; skillIter != bounds.second; ++skillIter)
                    {
                        if (skillIter->second->skillId == achievementCriteria->Asset.SkillID)
                        {
                            // do not add couter twice if by any chance skill is listed twice in dbc (eg. skill 777 and spell 22717)
                            ++spellCount;
                            break;
                        }
                    }
                }
                SetCriteriaProgress(achievementCriteria, spellCount);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_GAIN_REVERED_REPUTATION:
                SetCriteriaProgress(achievementCriteria, GetPlayer()->GetReputationMgr().GetReveredFactionCount());
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_GAIN_HONORED_REPUTATION:
                SetCriteriaProgress(achievementCriteria, GetPlayer()->GetReputationMgr().GetHonoredFactionCount());
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_KNOWN_FACTIONS:
                SetCriteriaProgress(achievementCriteria, GetPlayer()->GetReputationMgr().GetVisibleFactionCount());
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LINE:
            {
                uint32 spellCount = 0;
                for (PlayerSpellMap::const_iterator spellIter = GetPlayer()->GetSpellMap().begin();
                    spellIter != GetPlayer()->GetSpellMap().end();
                    ++spellIter)
                {
                    SkillLineAbilityMapBounds bounds = sSpellMgr->GetSkillLineAbilityMapBounds(spellIter->first);
                    for (SkillLineAbilityMap::const_iterator skillIter = bounds.first; skillIter != bounds.second; ++skillIter)
                        if (skillIter->second->skillId == achievementCriteria->Asset.SkillID)
                        {
                            // do not add couter twice if by any chance skill is listed twice in dbc (eg. skill 777 and spell 22717)
                            ++spellCount;
                            break;
                        }
                }
                SetCriteriaProgress(achievementCriteria, spellCount);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_EARN_HONORABLE_KILL:
                SetCriteriaProgress(achievementCriteria, GetPlayer()->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS));
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_GOLD_VALUE_OWNED:
                SetCriteriaProgress(achievementCriteria, GetPlayer()->GetMoney(), PROGRESS_HIGHEST);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_EARN_ACHIEVEMENT_POINTS:
                if (!miscValue1)
                {
                    uint32 points = 0;
                    for (CompletedAchievementMap::const_iterator itr = m_completedAchievements.begin(); itr != m_completedAchievements.end(); ++itr)
                        if (AchievementEntry const* completedAchievements = sAchievementMgr->GetAchievement(itr->first))
                            points += completedAchievements->Points;
                    SetCriteriaProgress(achievementCriteria, points, PROGRESS_SET);
                }
                else
                    SetCriteriaProgress(achievementCriteria, miscValue1, PROGRESS_ACCUMULATE);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_TEAM_RATING:
            {
                uint32 reqTeamType = achievementCriteria->Asset.TeamType;

                if (miscValue1)
                {
                    if (miscValue2 != reqTeamType)
                        continue;

                    SetCriteriaProgress(achievementCriteria, miscValue1, PROGRESS_HIGHEST);
                }
                else // login case
                {
                    for (uint32 arena_slot = 0; arena_slot < MAX_ARENA_SLOT; ++arena_slot)
                    {
                        uint32 teamId = GetPlayer()->GetArenaTeamId(arena_slot);
                        if (!teamId)
                            continue;

                        ArenaTeam* team = sArenaTeamMgr->GetArenaTeamById(teamId);
                        if (!team || team->GetType() != reqTeamType)
                            continue;

                        SetCriteriaProgress(achievementCriteria, team->GetStats().Rating, PROGRESS_HIGHEST);
                        break;
                    }
                }
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_PERSONAL_RATING:
            {
                uint32 reqTeamType = achievementCriteria->Asset.TeamType;

                if (miscValue1)
                {
                    if (miscValue2 != reqTeamType)
                        continue;

                    SetCriteriaProgress(achievementCriteria, miscValue1, PROGRESS_HIGHEST);
                }
                else // login case
                {
                    for (uint32 arena_slot = 0; arena_slot < MAX_ARENA_SLOT; ++arena_slot)
                    {
                        uint32 teamId = GetPlayer()->GetArenaTeamId(arena_slot);
                        if (!teamId)
                            continue;

                        ArenaTeam* team = sArenaTeamMgr->GetArenaTeamById(teamId);
                        if (!team || team->GetType() != reqTeamType)
                            continue;

                        if (ArenaTeamMember const* member = team->GetMember(GetPlayer()->GetGUID()))
                        {
                            SetCriteriaProgress(achievementCriteria, member->PersonalRating, PROGRESS_HIGHEST);
                            break;
                        }
                    }
                }

                break;
            }
            // std case: does not exist in DBC, not triggered in code as result
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEALTH:
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_SPELLPOWER:
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_ARMOR:
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_POWER:
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_STAT:
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_RATING:
                break;
            // FIXME: not triggered in code as result, need to implement
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_RAID:
            case ACHIEVEMENT_CRITERIA_TYPE_PLAY_ARENA:
            case ACHIEVEMENT_CRITERIA_TYPE_OWN_RANK:
                break;                                   // Not implemented yet :(
        }

        if (IsCompletedCriteria(achievementCriteria, achievement))
            CompletedCriteriaFor(achievement);

        // check again the completeness for SUMM and REQ COUNT achievements,
        // as they don't depend on the completed criteria but on the sum of the progress of each individual criteria
        if (achievement->Flags & ACHIEVEMENT_FLAG_SUMM)
            if (IsCompletedAchievement(achievement))
                CompletedAchievement(achievement);

        if (AchievementEntryList const* achRefList = sAchievementMgr->GetAchievementByReferencedId(achievement->ID))
            for (AchievementEntryList::const_iterator itr = achRefList->begin(); itr != achRefList->end(); ++itr)
                if (IsCompletedAchievement(*itr))
                    CompletedAchievement(*itr);
    }
}

bool AchievementMgr::IsCompletedCriteria(AchievementCriteriaEntry const* achievementCriteria, AchievementEntry const* achievement)
{
    if (!achievement)
        return false;

    // counter can never complete
    if (achievement->Flags & ACHIEVEMENT_FLAG_COUNTER)
        return false;

    if (achievement->Flags & (ACHIEVEMENT_FLAG_REALM_FIRST_REACH | ACHIEVEMENT_FLAG_REALM_FIRST_KILL))
    {
        // someone on this realm has already completed that achievement
        if (sAchievementMgr->IsRealmCompleted(achievement))
            return false;
    }

    CriteriaProgress const* progress = GetCriteriaProgress(achievementCriteria);
    if (!progress)
        return false;

    switch (achievementCriteria->Type)
    {
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_BG:
        case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE:
        case ACHIEVEMENT_CRITERIA_TYPE_REACH_LEVEL:
        case ACHIEVEMENT_CRITERIA_TYPE_REACH_SKILL_LEVEL:
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST_COUNT:
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST_DAILY:
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUESTS_IN_ZONE:
        case ACHIEVEMENT_CRITERIA_TYPE_DAMAGE_DONE:
        case ACHIEVEMENT_CRITERIA_TYPE_HEALING_DONE:
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST:
        case ACHIEVEMENT_CRITERIA_TYPE_FALL_WITHOUT_DYING:
        case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET:
        case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2:
        case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL:
        case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL2:
        case ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE:
        case ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL_AT_AREA:
        case ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL:
        case ACHIEVEMENT_CRITERIA_TYPE_EARN_HONORABLE_KILL:
        case ACHIEVEMENT_CRITERIA_TYPE_OWN_ITEM:
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_ARENA:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_PERSONAL_RATING:
        case ACHIEVEMENT_CRITERIA_TYPE_USE_ITEM:
        case ACHIEVEMENT_CRITERIA_TYPE_LOOT_ITEM:
        case ACHIEVEMENT_CRITERIA_TYPE_BUY_BANK_SLOT:
        case ACHIEVEMENT_CRITERIA_TYPE_GAIN_REPUTATION:
        case ACHIEVEMENT_CRITERIA_TYPE_GAIN_EXALTED_REPUTATION:
        case ACHIEVEMENT_CRITERIA_TYPE_VISIT_BARBER_SHOP:
        case ACHIEVEMENT_CRITERIA_TYPE_EQUIP_EPIC_ITEM:
        case ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED_ON_LOOT:
        case ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED_ON_LOOT:
        case ACHIEVEMENT_CRITERIA_TYPE_HK_CLASS:
        case ACHIEVEMENT_CRITERIA_TYPE_HK_RACE:
        case ACHIEVEMENT_CRITERIA_TYPE_DO_EMOTE:
        case ACHIEVEMENT_CRITERIA_TYPE_EQUIP_ITEM:
        case ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_QUEST_REWARD:
        case ACHIEVEMENT_CRITERIA_TYPE_LOOT_MONEY:
        case ACHIEVEMENT_CRITERIA_TYPE_USE_GAMEOBJECT:
        case ACHIEVEMENT_CRITERIA_TYPE_SPECIAL_PVP_KILL:
        case ACHIEVEMENT_CRITERIA_TYPE_FISH_IN_GAMEOBJECT:
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILLLINE_SPELLS:
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_DUEL:
        case ACHIEVEMENT_CRITERIA_TYPE_LOOT_TYPE:
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LINE:
        case ACHIEVEMENT_CRITERIA_TYPE_USE_LFD_TO_GROUP_WITH_PLAYERS:
        case ACHIEVEMENT_CRITERIA_TYPE_GET_KILLING_BLOWS:
            return progress->counter >= achievementCriteria->Amount;
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_ACHIEVEMENT:
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST:
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SPELL:
        case ACHIEVEMENT_CRITERIA_TYPE_EXPLORE_AREA:
            return progress->counter >= 1;
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LEVEL:
            return progress->counter >= (achievementCriteria->Amount * 75);
        case ACHIEVEMENT_CRITERIA_TYPE_EARN_ACHIEVEMENT_POINTS:
            return progress->counter >= 9000;
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_ARENA:
            return achievementCriteria->Amount && progress->counter >= achievementCriteria->Amount;
        case ACHIEVEMENT_CRITERIA_TYPE_ON_LOGIN:
            return true;
        // handle all statistic-only criteria here
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_BATTLEGROUND:
        case ACHIEVEMENT_CRITERIA_TYPE_DEATH_AT_MAP:
        case ACHIEVEMENT_CRITERIA_TYPE_DEATH:
        case ACHIEVEMENT_CRITERIA_TYPE_DEATH_IN_DUNGEON:
        case ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_CREATURE:
        case ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_PLAYER:
        case ACHIEVEMENT_CRITERIA_TYPE_DEATHS_FROM:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_TEAM_RATING:
        case ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_VENDORS:
        case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_TALENTS:
        case ACHIEVEMENT_CRITERIA_TYPE_NUMBER_OF_TALENT_RESETS:
        case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_AT_BARBER:
        case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_MAIL:
        case ACHIEVEMENT_CRITERIA_TYPE_LOSE_DUEL:
        case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE_TYPE:
        case ACHIEVEMENT_CRITERIA_TYPE_GOLD_EARNED_BY_AUCTIONS:
        case ACHIEVEMENT_CRITERIA_TYPE_CREATE_AUCTION:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_AUCTION_BID:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_AUCTION_SOLD:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_GOLD_VALUE_OWNED:
        case ACHIEVEMENT_CRITERIA_TYPE_WON_AUCTIONS:
        case ACHIEVEMENT_CRITERIA_TYPE_GAIN_REVERED_REPUTATION:
        case ACHIEVEMENT_CRITERIA_TYPE_GAIN_HONORED_REPUTATION:
        case ACHIEVEMENT_CRITERIA_TYPE_KNOWN_FACTIONS:
        case ACHIEVEMENT_CRITERIA_TYPE_LOOT_EPIC_ITEM:
        case ACHIEVEMENT_CRITERIA_TYPE_RECEIVE_EPIC_ITEM:
        case ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED:
        case ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEALTH:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_SPELLPOWER:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_ARMOR:
        case ACHIEVEMENT_CRITERIA_TYPE_QUEST_ABANDONED:
        case ACHIEVEMENT_CRITERIA_TYPE_FLIGHT_PATHS_TAKEN:
        case ACHIEVEMENT_CRITERIA_TYPE_ACCEPTED_SUMMONINGS:
        default:
            break;
    }
    return false;
}

void AchievementMgr::CompletedCriteriaFor(AchievementEntry const* achievement)
{
    // counter can never complete
    if (achievement->Flags & ACHIEVEMENT_FLAG_COUNTER)
        return;

    // already completed and stored
    if (HasAchieved(achievement->ID))
        return;

    if (IsCompletedAchievement(achievement))
        CompletedAchievement(achievement);
}

bool AchievementMgr::IsCompletedAchievement(AchievementEntry const* entry)
{
    // counter can never complete
    if (entry->Flags & ACHIEVEMENT_FLAG_COUNTER)
        return false;

    // for achievement with referenced achievement criterias get from referenced and counter from self
    uint32 achievmentForTestId = entry->SharesCriteria ? entry->SharesCriteria : entry->ID;
    uint32 achievmentForTestCount = entry->MinimumCriteria;

    AchievementCriteriaEntryList const* cList = sAchievementMgr->GetAchievementCriteriaByAchievement(achievmentForTestId);
    if (!cList)
        return false;
    uint32 count = 0;

    // For SUMM achievements, we have to count the progress of each criteria of the achievement.
    // Oddly, the target count is NOT countained in the achievement, but in each individual criteria
    if (entry->Flags & ACHIEVEMENT_FLAG_SUMM)
    {
        for (AchievementCriteriaEntryList::const_iterator itr = cList->begin(); itr != cList->end(); ++itr)
        {
            AchievementCriteriaEntry const* criteria = *itr;

            CriteriaProgress const* progress = GetCriteriaProgress(criteria);
            if (!progress)
                continue;

            count += progress->counter;

            // for counters, field4 contains the main count requirement
            if (count >= criteria->Amount)
                return true;
        }
        return false;
    }

    // Default case - need complete all or
    bool completed_all = true;
    for (AchievementCriteriaEntryList::const_iterator itr = cList->begin(); itr != cList->end(); ++itr)
    {
        AchievementCriteriaEntry const* criteria = *itr;

        bool completed = IsCompletedCriteria(criteria, entry);

        // found an uncompleted criteria, but DONT return false yet - there might be a completed criteria with ACHIEVEMENT_CRITERIA_COMPLETE_FLAG_ALL
        if (completed)
            ++count;
        else
            completed_all = false;

        // completed as have req. count of completed criterias
        if (achievmentForTestCount > 0 && achievmentForTestCount <= count)
           return true;
    }

    // all criterias completed requirement
    if (completed_all && achievmentForTestCount == 0)
        return true;

    return false;
}

CriteriaProgress* AchievementMgr::GetCriteriaProgress(AchievementCriteriaEntry const* entry)
{
    CriteriaProgressMap::iterator iter = m_criteriaProgress.find(entry->ID);

    if (iter == m_criteriaProgress.end())
        return nullptr;

    return &(iter->second);
}

void AchievementMgr::SetCriteriaProgress(AchievementCriteriaEntry const* entry, uint32 changeValue, ProgressType ptype)
{
    // Don't allow to cheat - doing timed achievements without timer active
    TimedAchievementMap::iterator timedIter = m_timedAchievements.find(entry->ID);
    if (entry->StartTimer && timedIter == m_timedAchievements.end())
        return;

    TC_LOG_DEBUG("achievement", "AchievementMgr::SetCriteriaProgress(%u, %u) for (GUID:%u)", entry->ID, changeValue, m_player->GetGUID().GetCounter());

    CriteriaProgress* progress = GetCriteriaProgress(entry);
    if (!progress)
    {
        // not create record for 0 counter but allow it for timed achievements
        // we will need to send 0 progress to client to start the timer
        if (changeValue == 0 && !entry->StartTimer)
            return;

        progress = &m_criteriaProgress[entry->ID];
        progress->counter = changeValue;
    }
    else
    {
        uint32 newValue = 0;
        switch (ptype)
        {
            case PROGRESS_SET:
                newValue = changeValue;
                break;
            case PROGRESS_ACCUMULATE:
            {
                // avoid overflow
                uint32 max_value = std::numeric_limits<uint32>::max();
                newValue = max_value - progress->counter > changeValue ? progress->counter + changeValue : max_value;
                break;
            }
            case PROGRESS_HIGHEST:
                newValue = progress->counter < changeValue ? changeValue : progress->counter;
                break;
        }

        // not update (not mark as changed) if counter will have same value
        if (progress->counter == newValue && !entry->StartTimer)
            return;

        progress->counter = newValue;
    }

    progress->changed = true;
    progress->date = GameTime::GetGameTime(); // set the date to the latest update.

    uint32 timeElapsed = 0;
    bool timedCompleted = false;

    if (entry->StartTimer)
    {
        // has to exist, otherwise we wouldn't be here
        timedCompleted = IsCompletedCriteria(entry, sAchievementMgr->GetAchievement(entry->ReferredAchievement));
        // Client expects this in packet
        timeElapsed = entry->StartTimer - (timedIter->second/IN_MILLISECONDS);

        // Remove the timer, we wont need it anymore
        if (timedCompleted)
            m_timedAchievements.erase(timedIter);
    }

    SendCriteriaUpdate(entry, progress, timeElapsed, timedCompleted);
}

void AchievementMgr::RemoveCriteriaProgress(AchievementCriteriaEntry const* entry)
{
    if (!entry)
        return;

    CriteriaProgressMap::iterator criteriaProgress = m_criteriaProgress.find(entry->ID);
    if (criteriaProgress == m_criteriaProgress.end())
        return;

    WorldPacket data(SMSG_CRITERIA_DELETED, 4);
    data << uint32(entry->ID);
    m_player->SendDirectMessage(&data);

    m_criteriaProgress.erase(criteriaProgress);
}

void AchievementMgr::UpdateTimedAchievements(uint32 timeDiff)
{
    if (!m_timedAchievements.empty())
    {
        for (TimedAchievementMap::iterator itr = m_timedAchievements.begin(); itr != m_timedAchievements.end();)
        {
            // Time is up, remove timer and reset progress
            if (itr->second <= timeDiff)
            {
                AchievementCriteriaEntry const* entry = sAchievementMgr->GetAchievementCriteria(itr->first);
                RemoveCriteriaProgress(entry);
                m_timedAchievements.erase(itr++);
            }
            else
            {
                itr->second -= timeDiff;
                ++itr;
            }
        }
    }
}

void AchievementMgr::StartTimedAchievement(AchievementCriteriaTimedTypes type, uint32 entry, uint32 timeLost /*= 0*/)
{
    AchievementCriteriaEntryList const& achievementCriteriaList = sAchievementMgr->GetTimedAchievementCriteriaByType(type);
    for (AchievementCriteriaEntryList::const_iterator i = achievementCriteriaList.begin(); i != achievementCriteriaList.end(); ++i)
    {
        if ((*i)->StartAsset != entry)
            continue;

        AchievementEntry const* achievement = sAchievementMgr->GetAchievement((*i)->ReferredAchievement);
        if (m_timedAchievements.find((*i)->ID) == m_timedAchievements.end() && !IsCompletedCriteria(*i, achievement))
        {
            // Start the timer
            if ((*i)->StartTimer * IN_MILLISECONDS > timeLost)
            {
                m_timedAchievements[(*i)->ID] = (*i)->StartTimer * IN_MILLISECONDS - timeLost;

                // and at client too
                SetCriteriaProgress(*i, 0, PROGRESS_SET);
            }
        }
    }
}

void AchievementMgr::RemoveTimedAchievement(AchievementCriteriaTimedTypes type, uint32 entry)
{
    AchievementCriteriaEntryList const& achievementCriteriaList = sAchievementMgr->GetTimedAchievementCriteriaByType(type);
    for (AchievementCriteriaEntryList::const_iterator i = achievementCriteriaList.begin(); i!=achievementCriteriaList.end(); ++i)
    {
        if ((*i)->StartAsset != entry)
            continue;

        TimedAchievementMap::iterator timedIter = m_timedAchievements.find((*i)->ID);
        // We don't have timer for this achievement
        if (timedIter == m_timedAchievements.end())
            continue;

        // remove progress
        RemoveCriteriaProgress(*i);

        // Remove the timer
        m_timedAchievements.erase(timedIter);
    }
}

void AchievementMgr::CompletedAchievement(AchievementEntry const* achievement)
{
    // Disable for GameMasters with GM-mode enabled or for players that don't have the related RBAC permission
    if (m_player->IsGameMaster() || m_player->GetSession()->HasPermission(rbac::RBAC_PERM_CANNOT_EARN_ACHIEVEMENTS))
        return;

    if (achievement->Flags & ACHIEVEMENT_FLAG_COUNTER || HasAchieved(achievement->ID))
        return;

    TC_LOG_INFO("achievement", "AchievementMgr::CompletedAchievement(%u). Player: %s (%u)",
        achievement->ID, m_player->GetName().c_str(), m_player->GetGUID().GetCounter());

    SendAchievementEarned(achievement);
    CompletedAchievementData& ca = m_completedAchievements[achievement->ID];
    ca.date = GameTime::GetGameTime();
    ca.changed = true;

    if (achievement->Flags & (ACHIEVEMENT_FLAG_REALM_FIRST_REACH | ACHIEVEMENT_FLAG_REALM_FIRST_KILL))
        sAchievementMgr->SetRealmCompleted(achievement);

    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_ACHIEVEMENT, achievement->ID);
    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_EARN_ACHIEVEMENT_POINTS, achievement->Points);

    // reward items and titles if any
    AchievementReward const* reward = sAchievementMgr->GetAchievementReward(achievement);

    // no rewards
    if (!reward)
        return;

    // titles
    //! Currently there's only one achievement that deals with gender-specific titles.
    //! Since no common attributes were found, (not even in titleRewardFlags field)
    //! we explicitly check by ID. Maybe in the future we could move the achievement_reward
    //! condition fields to the condition system.
    if (uint32 titleId = reward->TitleId[achievement->ID == 1793 ? GetPlayer()->GetByteValue(PLAYER_BYTES_3, PLAYER_BYTES_3_OFFSET_GENDER) : (GetPlayer()->GetTeam() == ALLIANCE ? 0 : 1)])
        if (CharTitlesEntry const* titleEntry = sCharTitlesStore.LookupEntry(titleId))
            GetPlayer()->SetTitle(titleEntry);

    // mail
    if (reward->SenderCreatureId)
    {
        MailDraft draft(reward->MailTemplateId);

        if (!reward->MailTemplateId)
        {
            // subject and text
            std::string subject = reward->Subject;
            std::string text = reward->Body;

            LocaleConstant localeConstant = GetPlayer()->GetSession()->GetSessionDbLocaleIndex();
            if (localeConstant != LOCALE_enUS)
            {
                if (AchievementRewardLocale const* loc = sAchievementMgr->GetAchievementRewardLocale(achievement))
                {
                    ObjectMgr::GetLocaleString(loc->Subject, localeConstant, subject);
                    ObjectMgr::GetLocaleString(loc->Text,    localeConstant, text);
                }
            }

            draft = MailDraft(subject, text);
        }

        SQLTransaction trans = CharacterDatabase.BeginTransaction();

        Item* item = reward->ItemId ? Item::CreateItem(reward->ItemId, 1, GetPlayer()) : nullptr;
        if (item)
        {
            // save new item before send
            item->SaveToDB(trans);                               // save for prevent lost at next mail load, if send fail then item will deleted

            // item
            draft.AddItem(item);
        }

        draft.SendMailTo(trans, GetPlayer(), MailSender(MAIL_CREATURE, reward->SenderCreatureId));
        CharacterDatabase.CommitTransaction(trans);
    }
}

void AchievementMgr::SendAllAchievementData() const
{
    WorldPacket data(SMSG_ALL_ACHIEVEMENT_DATA, m_completedAchievements.size()*8+4+m_criteriaProgress.size()*38+4);
    BuildAllDataPacket(&data);
    GetPlayer()->SendDirectMessage(&data);
}

void AchievementMgr::SendRespondInspectAchievements(Player* player) const
{
    WorldPacket data(SMSG_RESPOND_INSPECT_ACHIEVEMENTS, 9+m_completedAchievements.size()*8+4+m_criteriaProgress.size()*38+4);
    data << GetPlayer()->GetPackGUID();
    BuildAllDataPacket(&data);
    player->SendDirectMessage(&data);
}

/**
 * used by SMSG_RESPOND_INSPECT_ACHIEVEMENT and SMSG_ALL_ACHIEVEMENT_DATA
 */
void AchievementMgr::BuildAllDataPacket(WorldPacket* data) const
{
    for (CompletedAchievementMap::const_iterator iter = m_completedAchievements.begin(); iter != m_completedAchievements.end(); ++iter)
    {
        // Skip hidden achievements
        AchievementEntry const* achievement = sAchievementMgr->GetAchievement(iter->first);
        if (!achievement || achievement->Flags & ACHIEVEMENT_FLAG_HIDDEN)
            continue;

        *data << uint32(iter->first);
        data->AppendPackedTime(iter->second.date);
    }
    *data << int32(-1);

    for (CriteriaProgressMap::const_iterator iter = m_criteriaProgress.begin(); iter != m_criteriaProgress.end(); ++iter)
    {
        *data << uint32(iter->first);
        data->appendPackGUID(iter->second.counter);
        *data << GetPlayer()->GetPackGUID();
        *data << uint32(0);
        data->AppendPackedTime(iter->second.date);
        *data << uint32(0);
        *data << uint32(0);
    }

    *data << int32(-1);
}

bool AchievementMgr::HasAchieved(uint32 achievementId) const
{
    return m_completedAchievements.find(achievementId) != m_completedAchievements.end();
}

bool AchievementMgr::CanUpdateCriteria(AchievementCriteriaEntry const* criteria, AchievementEntry const* achievement, uint32 miscValue1, uint32 miscValue2, WorldObject const* ref)
{
    if (DisableMgr::IsDisabledFor(DISABLE_TYPE_ACHIEVEMENT_CRITERIA, criteria->ID, nullptr))
    {
        TC_LOG_TRACE("achievement", "CanUpdateCriteria: (Id: %u Type %s) Disabled",
            criteria->ID, AchievementGlobalMgr::GetCriteriaTypeString(criteria->Type));
        return false;
    }

    if (achievement->MapID != -1 && GetPlayer()->GetMapId() != uint32(achievement->MapID))
    {
        TC_LOG_TRACE("achievement", "CanUpdateCriteria: (Id: %u Type %s Achievement %u) Wrong map",
            criteria->ID, AchievementGlobalMgr::GetCriteriaTypeString(criteria->Type), achievement->ID);
        return false;
    }

    if ((achievement->Faction == ACHIEVEMENT_FACTION_HORDE    && GetPlayer()->GetTeam() != HORDE) ||
        (achievement->Faction == ACHIEVEMENT_FACTION_ALLIANCE && GetPlayer()->GetTeam() != ALLIANCE))
    {
        TC_LOG_TRACE("achievement", "CanUpdateCriteria: (Id: %u Type %s Achievement %u) Wrong faction",
            criteria->ID, AchievementGlobalMgr::GetCriteriaTypeString(criteria->Type), achievement->ID);
        return false;
    }

    if (!RequirementsSatisfied(criteria, achievement, miscValue1, miscValue2, ref))
    {
        TC_LOG_TRACE("achievement", "CanUpdateCriteria: (Id: %u Type %s) Requirements have not been satisfied",
            criteria->ID, AchievementGlobalMgr::GetCriteriaTypeString(criteria->Type));
        return false;
    }

    if (!ConditionsSatisfied(criteria))
    {
        TC_LOG_TRACE("achievement", "CanUpdateCriteria: (Id: %u Type %s) Conditions have not been satisfied",
            criteria->ID, AchievementGlobalMgr::GetCriteriaTypeString(criteria->Type));
        return false;
    }

    // Don't update realm first achievements if the player's account isn't allowed to do so
    if (achievement->Flags & (ACHIEVEMENT_FLAG_REALM_FIRST_REACH | ACHIEVEMENT_FLAG_REALM_FIRST_KILL))
        if (GetPlayer()->GetSession()->HasPermission(rbac::RBAC_PERM_CANNOT_EARN_REALM_FIRST_ACHIEVEMENTS))
            return false;

    // don't update already completed criteria
    if (IsCompletedCriteria(criteria, achievement))
        return false;

    return true;
}

bool AchievementMgr::ConditionsSatisfied(AchievementCriteriaEntry const* criteria) const
{
    for (uint32 i = 0; i < MAX_CRITERIA_REQUIREMENTS; ++i)
    {
        if (!criteria->AdditionalRequirements[i].Type)
            continue;

        switch (criteria->AdditionalRequirements[i].Type)
        {
            case ACHIEVEMENT_CRITERIA_CONDITION_BG_MAP:
                if (GetPlayer()->GetMapId() != criteria->AdditionalRequirements[i].Asset)
                    return false;
                break;
            case ACHIEVEMENT_CRITERIA_CONDITION_NOT_IN_GROUP:
                if (GetPlayer()->GetGroup())
                    return false;
                break;
            default:
                break;
        }
    }

    return true;
}

bool AchievementMgr::RequirementsSatisfied(AchievementCriteriaEntry const* achievementCriteria, AchievementEntry const* achievement, uint32 miscValue1, uint32 miscValue2, WorldObject const* ref) const
{
    switch (AchievementCriteriaTypes(achievementCriteria->Type))
    {
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST:
        case ACHIEVEMENT_CRITERIA_TYPE_FALL_WITHOUT_DYING:
        case ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL:
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_ARENA:
        case ACHIEVEMENT_CRITERIA_TYPE_VISIT_BARBER_SHOP:
        case ACHIEVEMENT_CRITERIA_TYPE_GET_KILLING_BLOWS:
        case ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_VENDORS:
        case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_TALENTS:
        case ACHIEVEMENT_CRITERIA_TYPE_NUMBER_OF_TALENT_RESETS:
        case ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_QUEST_REWARD:
        case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_TRAVELLING:
        case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_AT_BARBER:
        case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_MAIL:
        case ACHIEVEMENT_CRITERIA_TYPE_LOOT_MONEY:
        case ACHIEVEMENT_CRITERIA_TYPE_SPECIAL_PVP_KILL:
        case ACHIEVEMENT_CRITERIA_TYPE_ON_LOGIN:
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_DUEL:
        case ACHIEVEMENT_CRITERIA_TYPE_LOSE_DUEL:
        case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE_TYPE:
        case ACHIEVEMENT_CRITERIA_TYPE_GOLD_EARNED_BY_AUCTIONS:
        case ACHIEVEMENT_CRITERIA_TYPE_CREATE_AUCTION:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_AUCTION_BID:
        case ACHIEVEMENT_CRITERIA_TYPE_WON_AUCTIONS:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_AUCTION_SOLD:
        case ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED:
        case ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HIT_DEALT:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HIT_RECEIVED:
        case ACHIEVEMENT_CRITERIA_TYPE_TOTAL_DAMAGE_RECEIVED:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEAL_CAST:
        case ACHIEVEMENT_CRITERIA_TYPE_TOTAL_HEALING_RECEIVED:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEALING_RECEIVED:
        case ACHIEVEMENT_CRITERIA_TYPE_QUEST_ABANDONED:
        case ACHIEVEMENT_CRITERIA_TYPE_FLIGHT_PATHS_TAKEN:
        case ACHIEVEMENT_CRITERIA_TYPE_ACCEPTED_SUMMONINGS:
        case ACHIEVEMENT_CRITERIA_TYPE_USE_LFD_TO_GROUP_WITH_PLAYERS:
            if (!miscValue1)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_REACH_LEVEL:
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_ACHIEVEMENT:
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST_COUNT:
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST_DAILY:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_TEAM_RATING:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_PERSONAL_RATING:
        case ACHIEVEMENT_CRITERIA_TYPE_BUY_BANK_SLOT:
        case ACHIEVEMENT_CRITERIA_TYPE_GAIN_EXALTED_REPUTATION:
        case ACHIEVEMENT_CRITERIA_TYPE_GAIN_REVERED_REPUTATION:
        case ACHIEVEMENT_CRITERIA_TYPE_GAIN_HONORED_REPUTATION:
        case ACHIEVEMENT_CRITERIA_TYPE_KNOWN_FACTIONS:
        case ACHIEVEMENT_CRITERIA_TYPE_EARN_HONORABLE_KILL:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_GOLD_VALUE_OWNED:
        case ACHIEVEMENT_CRITERIA_TYPE_EARN_ACHIEVEMENT_POINTS:
            break;

        // specialized cases
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_BG:
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_BATTLEGROUND:
        case ACHIEVEMENT_CRITERIA_TYPE_DEATH_AT_MAP:
            if (!miscValue1)
                return false;
            if (achievementCriteria->Asset.MapID != GetPlayer()->GetMapId())
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE:
        case ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_CREATURE:
            if (!miscValue1)
                return false;
            if (achievementCriteria->Asset.CreatureID != miscValue1)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_REACH_SKILL_LEVEL:
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LEVEL:
            if (miscValue1 && miscValue1 != achievementCriteria->Asset.SkillID)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUESTS_IN_ZONE:
            if (miscValue1 && miscValue1 != achievementCriteria->Asset.ZoneID)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_DEATH:
            if (!miscValue1)
                return false;
            for (uint8 j = 0; j < MAX_ARENA_SLOT; ++j)
            {
                if (achievIdByArenaSlot[j] == achievement->ID)
                {
                    Battleground* bg = GetPlayer()->GetBattleground();
                    if (!bg || !bg->isArena() || ArenaTeam::GetSlotByType(bg->GetArenaType()) != j)
                        return false;
                    break;
                }
            }
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_DEATH_IN_DUNGEON:
        {
            if (!miscValue1)
                return false;

            Map const* map = GetPlayer()->IsInWorld() ? GetPlayer()->GetMap() : sMapMgr->FindMap(GetPlayer()->GetMapId(), GetPlayer()->GetInstanceId());
            if (!map || !map->IsDungeon())
                return false;

            //FIXME: work only for instances where max == min for players
            if (map->ToInstanceMap()->GetMaxPlayers() != achievementCriteria->Asset.GroupSize)
                return false;
            break;
        }
        case ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_PLAYER:
            if (!miscValue1)
                return false;
            // if team check required: must kill by opposition faction
            if (achievement->ID == 318 && miscValue2 == GetPlayer()->GetTeam())
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_DEATHS_FROM:
            if (!miscValue1)
                return false;
            if (miscValue2 != achievementCriteria->Asset.DamageType)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST:
            // if miscvalues != 0, it contains the questID.
            if (miscValue1)
            {
                if (miscValue1 != achievementCriteria->Asset.QuestID)
                    return false;
            }
            else
            {
                // login case.
                if (!GetPlayer()->GetQuestRewardStatus(achievementCriteria->Asset.QuestID))
                    return false;
            }
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET:
        case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2:
        case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL:
        case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL2:
            if (!miscValue1 || miscValue1 != achievementCriteria->Asset.SpellID)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SPELL:
            if (miscValue1 && miscValue1 != achievementCriteria->Asset.SpellID)
                return false;
            if (!GetPlayer()->HasSpell(achievementCriteria->Asset.SpellID))
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_LOOT_TYPE:
            // miscvalue1=loot_type (note: 0 = LOOT_CORPSE and then it ignored)
            // miscvalue2=count of item loot
            if (!miscValue1 || !miscValue2)
                return false;
            if (miscValue1 != achievementCriteria->Asset.LootType)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_OWN_ITEM:
            if (miscValue1 && achievementCriteria->Asset.ItemID != miscValue1)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_USE_ITEM:
        case ACHIEVEMENT_CRITERIA_TYPE_LOOT_ITEM:
        case ACHIEVEMENT_CRITERIA_TYPE_EQUIP_ITEM:
            if (!miscValue1)
                return false;
            if (miscValue1 != achievementCriteria->Asset.ItemID)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_EXPLORE_AREA:
        {
            WorldMapOverlayEntry const* worldOverlayEntry = sWorldMapOverlayStore.LookupEntry(achievementCriteria->Asset.WorldMapOverlayID);
            if (!worldOverlayEntry)
                return false;

            bool matchFound = false;
            for (int j = 0; j < MAX_WORLD_MAP_OVERLAY_AREA_IDX; ++j)
            {
                AreaTableEntry const* area = sAreaTableStore.LookupEntry(worldOverlayEntry->areatableID[j]);
                if (!area)
                    break;

                uint32 playerIndexOffset = uint32(area->exploreFlag) / 32;
                if (playerIndexOffset >= PLAYER_EXPLORED_ZONES_SIZE)
                    continue;

                uint32 mask = 1 << (uint32(area->exploreFlag) % 32);
                if (GetPlayer()->GetUInt32Value(PLAYER_EXPLORED_ZONES_1 + playerIndexOffset) & mask)
                {
                    matchFound = true;
                    break;
                }
            }

            if (!matchFound)
                return false;
            break;
        }
        case ACHIEVEMENT_CRITERIA_TYPE_GAIN_REPUTATION:
            if (miscValue1 && miscValue1 != achievementCriteria->Asset.FactionID)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_EQUIP_EPIC_ITEM:
            // miscvalue1 = itemSlot
            // miscvalue2 = itemid
            if (!miscValue2)
                return false;
            if (miscValue1 != achievementCriteria->Asset.ItemSlot)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED_ON_LOOT:
        case ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED_ON_LOOT:
            // miscvalue1 = itemid
            // miscvalue2 = diced value
            if (!miscValue1)
                return false;
            if (miscValue2 != achievementCriteria->Asset.RollValue)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_DO_EMOTE:
            // miscvalue1 = emote
            if (!miscValue1)
                return false;
            if (miscValue1 != achievementCriteria->Asset.EmoteID)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_DAMAGE_DONE:
        case ACHIEVEMENT_CRITERIA_TYPE_HEALING_DONE:
            if (!miscValue1)
                return false;

            if (achievementCriteria->AdditionalRequirements[0].Type == ACHIEVEMENT_CRITERIA_CONDITION_BG_MAP)
            {
                if (GetPlayer()->GetMapId() != achievementCriteria->AdditionalRequirements[0].Asset)
                    return false;

                // map specific case (BG in fact) expected player targeted damage/heal
                if (!ref || ref->GetTypeId() != TYPEID_PLAYER)
                    return false;
            }
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_USE_GAMEOBJECT:
        case ACHIEVEMENT_CRITERIA_TYPE_FISH_IN_GAMEOBJECT:
            if (!miscValue1)
                return false;
            if (miscValue1 != achievementCriteria->Asset.GameObjectID)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILLLINE_SPELLS:
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LINE:
            if (miscValue1 && miscValue1 != achievementCriteria->Asset.SkillID)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_LOOT_EPIC_ITEM:
        case ACHIEVEMENT_CRITERIA_TYPE_RECEIVE_EPIC_ITEM:
        {
            if (!miscValue1)
                return false;
            ItemTemplate const* proto = sObjectMgr->GetItemTemplate(miscValue1);
            if (!proto || proto->Quality < ITEM_QUALITY_EPIC)
                return false;
            break;
        }
        case ACHIEVEMENT_CRITERIA_TYPE_HK_CLASS:
            if (!miscValue1 || miscValue1 != achievementCriteria->Asset.ClassID)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_HK_RACE:
            if (!miscValue1 || miscValue1 != achievementCriteria->Asset.RaceID)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE:
            if (!miscValue1 || miscValue1 != achievementCriteria->Asset.ObjectiveId)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL_AT_AREA:
            if (!miscValue1 || miscValue1 != achievementCriteria->Asset.AreaID)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_ARENA:
            if (miscValue1 != achievementCriteria->Asset.MapID)
                return false;
            break;
        default:
            break;
    }

    return true;
}

char const* AchievementGlobalMgr::GetCriteriaTypeString(uint32 type)
{
    return GetCriteriaTypeString(AchievementCriteriaTypes(type));
}

char const* AchievementGlobalMgr::GetCriteriaTypeString(AchievementCriteriaTypes type)
{
    switch (type)
    {
        case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE:
            return "KILL_CREATURE";
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_BG:
            return "TYPE_WIN_BG";
        case ACHIEVEMENT_CRITERIA_TYPE_REACH_LEVEL:
            return "REACH_LEVEL";
        case ACHIEVEMENT_CRITERIA_TYPE_REACH_SKILL_LEVEL:
            return "REACH_SKILL_LEVEL";
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_ACHIEVEMENT:
            return "COMPLETE_ACHIEVEMENT";
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST_COUNT:
            return "COMPLETE_QUEST_COUNT";
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST_DAILY:
            return "COMPLETE_DAILY_QUEST_DAILY";
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUESTS_IN_ZONE:
            return "COMPLETE_QUESTS_IN_ZONE";
        case ACHIEVEMENT_CRITERIA_TYPE_DAMAGE_DONE:
            return "DAMAGE_DONE";
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST:
            return "COMPLETE_DAILY_QUEST";
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_BATTLEGROUND:
            return "COMPLETE_BATTLEGROUND";
        case ACHIEVEMENT_CRITERIA_TYPE_DEATH_AT_MAP:
            return "DEATH_AT_MAP";
        case ACHIEVEMENT_CRITERIA_TYPE_DEATH:
            return "DEATH";
        case ACHIEVEMENT_CRITERIA_TYPE_DEATH_IN_DUNGEON:
            return "DEATH_IN_DUNGEON";
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_RAID:
            return "COMPLETE_RAID";
        case ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_CREATURE:
            return "KILLED_BY_CREATURE";
        case ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_PLAYER:
            return "KILLED_BY_PLAYER";
        case ACHIEVEMENT_CRITERIA_TYPE_FALL_WITHOUT_DYING:
            return "FALL_WITHOUT_DYING";
        case ACHIEVEMENT_CRITERIA_TYPE_DEATHS_FROM:
            return "DEATHS_FROM";
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST:
            return "COMPLETE_QUEST";
        case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET:
            return "BE_SPELL_TARGET";
        case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL:
            return "CAST_SPELL";
        case ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE:
            return "BG_OBJECTIVE_CAPTURE";
        case ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL_AT_AREA:
            return "HONORABLE_KILL_AT_AREA";
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_ARENA:
            return "WIN_ARENA";
        case ACHIEVEMENT_CRITERIA_TYPE_PLAY_ARENA:
            return "PLAY_ARENA";
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SPELL:
            return "LEARN_SPELL";
        case ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL:
            return "HONORABLE_KILL";
        case ACHIEVEMENT_CRITERIA_TYPE_OWN_ITEM:
            return "OWN_ITEM";
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_ARENA:
            return "WIN_RATED_ARENA";
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_TEAM_RATING:
            return "HIGHEST_TEAM_RATING";
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_PERSONAL_RATING:
            return "HIGHEST_PERSONAL_RATING";
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LEVEL:
            return "LEARN_SKILL_LEVEL";
        case ACHIEVEMENT_CRITERIA_TYPE_USE_ITEM:
            return "USE_ITEM";
        case ACHIEVEMENT_CRITERIA_TYPE_LOOT_ITEM:
            return "LOOT_ITEM";
        case ACHIEVEMENT_CRITERIA_TYPE_EXPLORE_AREA:
            return "EXPLORE_AREA";
        case ACHIEVEMENT_CRITERIA_TYPE_OWN_RANK:
            return "OWN_RANK";
        case ACHIEVEMENT_CRITERIA_TYPE_BUY_BANK_SLOT:
            return "BUY_BANK_SLOT";
        case ACHIEVEMENT_CRITERIA_TYPE_GAIN_REPUTATION:
            return "GAIN_REPUTATION";
        case ACHIEVEMENT_CRITERIA_TYPE_GAIN_EXALTED_REPUTATION:
            return "GAIN_EXALTED_REPUTATION";
        case ACHIEVEMENT_CRITERIA_TYPE_VISIT_BARBER_SHOP:
            return "VISIT_BARBER_SHOP";
        case ACHIEVEMENT_CRITERIA_TYPE_EQUIP_EPIC_ITEM:
            return "EQUIP_EPIC_ITEM";
        case ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED_ON_LOOT:
            return "ROLL_NEED_ON_LOOT";
        case ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED_ON_LOOT:
            return "GREED_ON_LOOT";
        case ACHIEVEMENT_CRITERIA_TYPE_HK_CLASS:
            return "HK_CLASS";
        case ACHIEVEMENT_CRITERIA_TYPE_HK_RACE:
            return "HK_RACE";
        case ACHIEVEMENT_CRITERIA_TYPE_DO_EMOTE:
            return "DO_EMOTE";
        case ACHIEVEMENT_CRITERIA_TYPE_HEALING_DONE:
            return "HEALING_DONE";
        case ACHIEVEMENT_CRITERIA_TYPE_GET_KILLING_BLOWS:
            return "GET_KILLING_BLOWS";
        case ACHIEVEMENT_CRITERIA_TYPE_EQUIP_ITEM:
            return "EQUIP_ITEM";
        case ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_VENDORS:
            return "MONEY_FROM_VENDORS";
        case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_TALENTS:
            return "GOLD_SPENT_FOR_TALENTS";
        case ACHIEVEMENT_CRITERIA_TYPE_NUMBER_OF_TALENT_RESETS:
            return "NUMBER_OF_TALENT_RESETS";
        case ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_QUEST_REWARD:
            return "MONEY_FROM_QUEST_REWARD";
        case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_TRAVELLING:
            return "GOLD_SPENT_FOR_TRAVELLING";
        case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_AT_BARBER:
            return "GOLD_SPENT_AT_BARBER";
        case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_MAIL:
            return "GOLD_SPENT_FOR_MAIL";
        case ACHIEVEMENT_CRITERIA_TYPE_LOOT_MONEY:
            return "LOOT_MONEY";
        case ACHIEVEMENT_CRITERIA_TYPE_USE_GAMEOBJECT:
            return "USE_GAMEOBJECT";
        case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2:
            return "BE_SPELL_TARGET2";
        case ACHIEVEMENT_CRITERIA_TYPE_SPECIAL_PVP_KILL:
            return "SPECIAL_PVP_KILL";
        case ACHIEVEMENT_CRITERIA_TYPE_FISH_IN_GAMEOBJECT:
            return "FISH_IN_GAMEOBJECT";
        case ACHIEVEMENT_CRITERIA_TYPE_ON_LOGIN:
            return "ON_LOGIN";
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILLLINE_SPELLS:
            return "LEARN_SKILLLINE_SPELLS";
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_DUEL:
            return "WIN_DUEL";
        case ACHIEVEMENT_CRITERIA_TYPE_LOSE_DUEL:
            return "LOSE_DUEL";
        case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE_TYPE:
            return "KILL_CREATURE_TYPE";
        case ACHIEVEMENT_CRITERIA_TYPE_GOLD_EARNED_BY_AUCTIONS:
            return "GOLD_EARNED_BY_AUCTIONS";
        case ACHIEVEMENT_CRITERIA_TYPE_CREATE_AUCTION:
            return "CREATE_AUCTION";
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_AUCTION_BID:
            return "HIGHEST_AUCTION_BID";
        case ACHIEVEMENT_CRITERIA_TYPE_WON_AUCTIONS:
            return "WON_AUCTIONS";
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_AUCTION_SOLD:
            return "HIGHEST_AUCTION_SOLD";
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_GOLD_VALUE_OWNED:
            return "HIGHEST_GOLD_VALUE_OWNED";
        case ACHIEVEMENT_CRITERIA_TYPE_GAIN_REVERED_REPUTATION:
            return "GAIN_REVERED_REPUTATION";
        case ACHIEVEMENT_CRITERIA_TYPE_GAIN_HONORED_REPUTATION:
            return "GAIN_HONORED_REPUTATION";
        case ACHIEVEMENT_CRITERIA_TYPE_KNOWN_FACTIONS:
            return "KNOWN_FACTIONS";
        case ACHIEVEMENT_CRITERIA_TYPE_LOOT_EPIC_ITEM:
            return "LOOT_EPIC_ITEM";
        case ACHIEVEMENT_CRITERIA_TYPE_RECEIVE_EPIC_ITEM:
            return "RECEIVE_EPIC_ITEM";
        case ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED:
            return "ROLL_NEED";
        case ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED:
            return "ROLL_GREED";
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEALTH:
            return "HIGHEST_HEALTH";
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_POWER:
            return "HIGHEST_POWER";
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_STAT:
            return "HIGHEST_STAT";
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_SPELLPOWER:
            return "HIGHEST_SPELLPOWER";
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_ARMOR:
            return "HIGHEST_ARMOR";
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_RATING:
            return "HIGHEST_RATING";
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HIT_DEALT:
            return "HIT_DEALT";
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HIT_RECEIVED:
            return "HIT_RECEIVED";
        case ACHIEVEMENT_CRITERIA_TYPE_TOTAL_DAMAGE_RECEIVED:
            return "TOTAL_DAMAGE_RECEIVED";
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEAL_CAST:
            return "HIGHEST_HEAL_CAST";
        case ACHIEVEMENT_CRITERIA_TYPE_TOTAL_HEALING_RECEIVED:
            return "TOTAL_HEALING_RECEIVED";
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEALING_RECEIVED:
            return "HIGHEST_HEALING_RECEIVED";
        case ACHIEVEMENT_CRITERIA_TYPE_QUEST_ABANDONED:
            return "QUEST_ABANDONED";
        case ACHIEVEMENT_CRITERIA_TYPE_FLIGHT_PATHS_TAKEN:
            return "FLIGHT_PATHS_TAKEN";
        case ACHIEVEMENT_CRITERIA_TYPE_LOOT_TYPE:
            return "LOOT_TYPE";
        case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL2:
            return "CAST_SPELL2";
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LINE:
            return "LEARN_SKILL_LINE";
        case ACHIEVEMENT_CRITERIA_TYPE_EARN_HONORABLE_KILL:
            return "EARN_HONORABLE_KILL";
        case ACHIEVEMENT_CRITERIA_TYPE_ACCEPTED_SUMMONINGS:
            return "ACCEPTED_SUMMONINGS";
        case ACHIEVEMENT_CRITERIA_TYPE_EARN_ACHIEVEMENT_POINTS:
            return "EARN_ACHIEVEMENT_POINTS";
        case ACHIEVEMENT_CRITERIA_TYPE_USE_LFD_TO_GROUP_WITH_PLAYERS:
            return "USE_LFD_TO_GROUP_WITH_PLAYERS";
    }
    return "MISSING_TYPE";
}

AchievementGlobalMgr* AchievementGlobalMgr::instance()
{
    static AchievementGlobalMgr instance;
    return &instance;
}

inline bool IsAchievementCriteriaTypeStoredByMiscValue(AchievementCriteriaTypes type)
{
    switch (type)
    {
        case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE:
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_BG:
        case ACHIEVEMENT_CRITERIA_TYPE_REACH_SKILL_LEVEL:
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_ACHIEVEMENT:
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUESTS_IN_ZONE:
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_BATTLEGROUND:
        case ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_CREATURE:
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST:
        case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET:
        case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL:
        case ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE:
        case ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL_AT_AREA:
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SPELL:
        case ACHIEVEMENT_CRITERIA_TYPE_OWN_ITEM:
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LEVEL:
        case ACHIEVEMENT_CRITERIA_TYPE_USE_ITEM:
        case ACHIEVEMENT_CRITERIA_TYPE_LOOT_ITEM:
        case ACHIEVEMENT_CRITERIA_TYPE_EXPLORE_AREA:
        case ACHIEVEMENT_CRITERIA_TYPE_GAIN_REPUTATION:
        case ACHIEVEMENT_CRITERIA_TYPE_EQUIP_EPIC_ITEM:
        case ACHIEVEMENT_CRITERIA_TYPE_HK_CLASS:
        case ACHIEVEMENT_CRITERIA_TYPE_HK_RACE:
        case ACHIEVEMENT_CRITERIA_TYPE_DO_EMOTE:
        case ACHIEVEMENT_CRITERIA_TYPE_EQUIP_ITEM:
        case ACHIEVEMENT_CRITERIA_TYPE_USE_GAMEOBJECT:
        case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2:
        case ACHIEVEMENT_CRITERIA_TYPE_FISH_IN_GAMEOBJECT:
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILLLINE_SPELLS:
        case ACHIEVEMENT_CRITERIA_TYPE_LOOT_TYPE:
        case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL2:
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LINE:
            return true;
        default:
            break;
    }
    return false;
}

AchievementCriteriaEntryList const& AchievementGlobalMgr::GetAchievementCriteriaByType(AchievementCriteriaTypes type, uint32 miscValue) const
{
    if (miscValue && IsAchievementCriteriaTypeStoredByMiscValue(type))
    {
        auto itr = m_AchievementCriteriasByMiscValue[type].find(miscValue);
        if (itr != m_AchievementCriteriasByMiscValue[type].end())
            return itr->second;
    }

    return m_AchievementCriteriasByType[type];
}

bool AchievementGlobalMgr::IsRealmCompleted(AchievementEntry const* achievement) const
{
    auto itr = _allCompletedAchievements.find(achievement->ID);
    if (itr == _allCompletedAchievements.end())
        return false;

    if (itr->second == std::chrono::system_clock::time_point::min())
        return false;

    if (itr->second == std::chrono::system_clock::time_point::max())
        return true;

    // Allow completing the realm first kill for entire minute after first person did it
    // it may allow more than one group to achieve it (highly unlikely)
    // but apparently this is how blizz handles it as well
    if (achievement->Flags & ACHIEVEMENT_FLAG_REALM_FIRST_KILL)
        return (GameTime::GetGameTimeSystemPoint() - itr->second) > Minutes(1);

    return true;
}

void AchievementGlobalMgr::SetRealmCompleted(AchievementEntry const* achievement)
{
    if (IsRealmCompleted(achievement))
        return;

    _allCompletedAchievements[achievement->ID] = GameTime::GetGameTimeSystemPoint();
}

//==========================================================
void AchievementGlobalMgr::LoadAchievementCriteriaList()
{
    uint32 oldMSTime = getMSTime();

    if (sAchievementCriteriaStore.GetNumRows() == 0)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 achievement criteria.");
        return;
    }

    uint32 loaded = 0;
    for (uint32 entryId = 0; entryId < sAchievementCriteriaStore.GetNumRows(); ++entryId)
    {
        AchievementCriteriaEntry const* criteria = sAchievementMgr->GetAchievementCriteria(entryId);
        if (!criteria)
            continue;

        ASSERT(criteria->Type < ACHIEVEMENT_CRITERIA_TYPE_TOTAL, "ACHIEVEMENT_CRITERIA_TYPE_TOTAL must be greater than or equal to %u but is currently equal to %u",
            criteria->Type + 1, ACHIEVEMENT_CRITERIA_TYPE_TOTAL);

        m_AchievementCriteriasByType[criteria->Type].push_back(criteria);
        m_AchievementCriteriaListByAchievement[criteria->ReferredAchievement].push_back(criteria);
        if (IsAchievementCriteriaTypeStoredByMiscValue(AchievementCriteriaTypes(criteria->Type)))
        {
            if (criteria->Type != ACHIEVEMENT_CRITERIA_TYPE_EXPLORE_AREA)
                m_AchievementCriteriasByMiscValue[criteria->Type][criteria->Asset.ID].push_back(criteria);
            else
            {
                WorldMapOverlayEntry const* worldOverlayEntry = sWorldMapOverlayStore.LookupEntry(criteria->Asset.WorldMapOverlayID);
                if (!worldOverlayEntry)
                    break;

                for (uint8 j = 0; j < MAX_WORLD_MAP_OVERLAY_AREA_IDX; ++j)
                {
                    if (worldOverlayEntry->areatableID[j])
                    {
                        bool valid = true;
                        for (uint8 i = 0; i < j; ++i)
                            if (worldOverlayEntry->areatableID[j] == worldOverlayEntry->areatableID[i])
                                valid = false;
                        if (valid)
                            m_AchievementCriteriasByMiscValue[criteria->Type][worldOverlayEntry->areatableID[j]].push_back(criteria);
                    }
                }
            }
        }

        for (uint32 i = 0; i < MAX_CRITERIA_REQUIREMENTS; ++i)
        {
            if (criteria->AdditionalRequirements[i].Type != ACHIEVEMENT_CRITERIA_CONDITION_NONE)
            {
                ASSERT(criteria->AdditionalRequirements[i].Type < ACHIEVEMENT_CRITERIA_CONDITION_MAX,
                    "ACHIEVEMENT_CRITERIA_CONDITION_MAX must be greater than or equal to %u but is currently equal to %u",
                    criteria->AdditionalRequirements[i].Type + 1, ACHIEVEMENT_CRITERIA_CONDITION_MAX);

                if (i == 0
                    || criteria->AdditionalRequirements[i].Type != criteria->AdditionalRequirements[i - 1].Type
                    || criteria->AdditionalRequirements[i].Asset != criteria->AdditionalRequirements[i - 1].Asset)
                    m_AchievementCriteriasByCondition[criteria->AdditionalRequirements[i].Type][criteria->AdditionalRequirements[i].Asset].push_back(criteria);
            }
        }

        if (criteria->StartTimer)
        {
            ASSERT(criteria->StartEvent < ACHIEVEMENT_TIMED_TYPE_MAX, "ACHIEVEMENT_TIMED_TYPE_MAX must be greater than or equal to %u but is currently equal to %u",
                criteria->StartEvent + 1, ACHIEVEMENT_TIMED_TYPE_MAX);
            m_AchievementCriteriasByTimedType[criteria->StartEvent].push_back(criteria);
        }

        ++loaded;
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u achievement criteria in %u ms.", loaded, GetMSTimeDiffToNow(oldMSTime));
}

void AchievementGlobalMgr::LoadAchievementReferenceList()
{
    uint32 oldMSTime = getMSTime();

    if (sAchievementStore.GetNumRows() == 0)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 achievement references.");
        return;
    }

    uint32 count = 0;

    for (uint32 entryId = 0; entryId < sAchievementStore.GetNumRows(); ++entryId)
    {
        AchievementEntry const* achievement = sAchievementMgr->GetAchievement(entryId);
        if (!achievement || !achievement->SharesCriteria)
            continue;

        m_AchievementListByReferencedId[achievement->SharesCriteria].push_back(achievement);
        ++count;
    }

    // Once Bitten, Twice Shy (10 player) - Icecrown Citadel
    if (AchievementEntry const* achievement = sAchievementMgr->GetAchievement(4539))
        const_cast<AchievementEntry*>(achievement)->MapID = 631;    // Correct map requirement (currently has Ulduar)

    TC_LOG_INFO("server.loading", ">> Loaded %u achievement references in %u ms.", count, GetMSTimeDiffToNow(oldMSTime));
}

void AchievementGlobalMgr::LoadAchievementCriteriaData()
{
    uint32 oldMSTime = getMSTime();

    m_criteriaDataMap.clear();                              // need for reload case

    QueryResult result = WorldDatabase.Query("SELECT criteria_id, type, value1, value2, ScriptName FROM achievement_criteria_data");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 additional achievement criteria data. DB table `achievement_criteria_data` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();
        uint32 criteria_id = fields[0].GetUInt32();

        AchievementCriteriaEntry const* criteria = sAchievementMgr->GetAchievementCriteria(criteria_id);

        if (!criteria)
        {
            TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` contains data for non-existing criteria (Entry: %u). Ignored.", criteria_id);
            continue;
        }

        uint32 dataType = fields[1].GetUInt8();
        std::string scriptName = fields[4].GetString();
        uint32 scriptId = 0;
        if (scriptName.length()) // not empty
        {
            if (dataType != ACHIEVEMENT_CRITERIA_DATA_TYPE_SCRIPT)
                TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` contains a ScriptName for non-scripted data type (Entry: %u, type %u), useless data.", criteria_id, dataType);
            else
                scriptId = sObjectMgr->GetScriptId(scriptName);
        }

        AchievementCriteriaData data(dataType, fields[2].GetUInt32(), fields[3].GetUInt32(), scriptId);

        if (!data.IsValid(criteria))
            continue;

        // this will allocate empty data set storage
        AchievementCriteriaDataSet& dataSet = m_criteriaDataMap[criteria_id];
        dataSet.SetCriteriaId(criteria_id);

        // add real data only for not NONE data types
        if (data.dataType != ACHIEVEMENT_CRITERIA_DATA_TYPE_NONE)
            dataSet.Add(data);

        // counting data by and data types
        ++count;
    }
    while (result->NextRow());

    // post loading checks
    for (uint32 entryId = 0; entryId < sAchievementCriteriaStore.GetNumRows(); ++entryId)
    {
        AchievementCriteriaEntry const* criteria = sAchievementMgr->GetAchievementCriteria(entryId);
        if (!criteria)
            continue;

        switch (criteria->Type)
        {
            case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE:
            case ACHIEVEMENT_CRITERIA_TYPE_WIN_BG:
            case ACHIEVEMENT_CRITERIA_TYPE_FALL_WITHOUT_DYING:
            case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET:
            case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL:
            case ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE:
            case ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL:
            case ACHIEVEMENT_CRITERIA_TYPE_EQUIP_EPIC_ITEM:
            case ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED_ON_LOOT:
            case ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED_ON_LOOT:
            case ACHIEVEMENT_CRITERIA_TYPE_GET_KILLING_BLOWS:
            case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2:
            case ACHIEVEMENT_CRITERIA_TYPE_SPECIAL_PVP_KILL:
            case ACHIEVEMENT_CRITERIA_TYPE_ON_LOGIN:
            case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE_TYPE:
            case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL2:
                // achievement requires db data
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST:
            {
                AchievementEntry const* achievement = sAchievementMgr->GetAchievement(criteria->ReferredAchievement);
                if (!achievement)
                    continue;

                // There are many achievements with these criteria, use hardcoded check at this moment to pick a simple case
                if (achievement->ID == 1282)
                    break;

                continue;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_ARENA: // need skip generic cases
                if (criteria->AdditionalRequirements[0].Type != ACHIEVEMENT_CRITERIA_CONDITION_NO_LOSE)
                    continue;
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_DO_EMOTE:        // need skip generic cases
                if (criteria->Amount == 0)
                    continue;
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_WIN_DUEL:        // skip statistics
                if (criteria->Amount == 0)
                    continue;
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_LOOT_TYPE:       // need skip generic cases
                if (criteria->Amount != 1)
                    continue;
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST:
            case ACHIEVEMENT_CRITERIA_TYPE_USE_ITEM:        // only Children's Week achievements
            {
                AchievementEntry const* achievement = sAchievementMgr->GetAchievement(criteria->ReferredAchievement);
                if (!achievement)
                    continue;
                if (achievement->Category != CATEGORY_CHILDRENS_WEEK && achievement->ID != 1785)
                    continue;
                break;
            }
            default:                                        // type not use DB data, ignore
                continue;
        }

        if (!GetCriteriaDataSet(criteria) && !DisableMgr::IsDisabledFor(DISABLE_TYPE_ACHIEVEMENT_CRITERIA, entryId, nullptr))
            TC_LOG_ERROR("sql.sql", "Table `achievement_criteria_data` does not contain expected data for criteria (Entry: %u Type: %u) for achievement %u.", criteria->ID, criteria->Type, criteria->ReferredAchievement);
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u additional achievement criteria data in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void AchievementGlobalMgr::LoadCompletedAchievements()
{
    uint32 oldMSTime = getMSTime();

    // Populate _allCompletedAchievements with all realm first achievement ids to make multithreaded access safer
    // while it will not prevent races, it will prevent crashes that happen because std::unordered_map key was added
    // instead the only potential race will happen on value associated with the key
    for (uint32 i = 0; i < sAchievementStore.GetNumRows(); ++i)
        if (AchievementEntry const* achievement = sAchievementStore.LookupEntry(i))
            if (achievement->Flags & (ACHIEVEMENT_FLAG_REALM_FIRST_REACH | ACHIEVEMENT_FLAG_REALM_FIRST_KILL))
                _allCompletedAchievements[achievement->ID] = std::chrono::system_clock::time_point::min();

    QueryResult result = CharacterDatabase.Query("SELECT achievement FROM character_achievement GROUP BY achievement");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 realm first completed achievements. DB table `character_achievement` is empty.");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        uint16 achievementId = fields[0].GetUInt16();
        AchievementEntry const* achievement = sAchievementMgr->GetAchievement(achievementId);
        if (!achievement)
        {
            // Remove non-existing achievements from all characters
            TC_LOG_ERROR("achievement", "Non-existing achievement %u data has been removed from the table `character_achievement`.", achievementId);

            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_INVALID_ACHIEVMENT);
            stmt->setUInt16(0, uint16(achievementId));
            CharacterDatabase.Execute(stmt);

            continue;
        }
        else if (achievement->Flags & (ACHIEVEMENT_FLAG_REALM_FIRST_REACH | ACHIEVEMENT_FLAG_REALM_FIRST_KILL))
            _allCompletedAchievements[achievementId] = std::chrono::system_clock::time_point::max();
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %lu realm first completed achievements in %u ms.", (unsigned long)_allCompletedAchievements.size(), GetMSTimeDiffToNow(oldMSTime));
}

void AchievementGlobalMgr::LoadRewards()
{
    uint32 oldMSTime = getMSTime();

    m_achievementRewards.clear();                           // need for reload case

    //                                               0   1       2       3       4       5        6     7
    QueryResult result = WorldDatabase.Query("SELECT ID, TitleA, TitleH, ItemID, Sender, Subject, Body, MailTemplateID FROM achievement_reward");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 achievement rewards. DB table `achievement_reward` is empty.");
        return;
    }

    do
    {
        Field* fields = result->Fetch();
        uint32 id = fields[0].GetUInt32();
        AchievementEntry const* achievement = GetAchievement(id);
        if (!achievement)
        {
            TC_LOG_ERROR("sql.sql", "Table `achievement_reward` contains a wrong achievement ID (%u), ignored.", id);
            continue;
        }

        AchievementReward reward;
        reward.TitleId[0]       = fields[1].GetUInt32();
        reward.TitleId[1]       = fields[2].GetUInt32();
        reward.ItemId           = fields[3].GetUInt32();
        reward.SenderCreatureId = fields[4].GetUInt32();
        reward.Subject          = fields[5].GetString();
        reward.Body             = fields[6].GetString();
        reward.MailTemplateId   = fields[7].GetUInt32();

        // must be title or mail at least
        if (!reward.TitleId[0] && !reward.TitleId[1] && !reward.SenderCreatureId)
        {
            TC_LOG_ERROR("sql.sql", "Table `achievement_reward` (ID: %u) does not contain title or item reward data. Ignored.", id);
            continue;
        }

        if (achievement->Faction == ACHIEVEMENT_FACTION_ANY && (!reward.TitleId[0] ^ !reward.TitleId[1]))
            TC_LOG_ERROR("sql.sql", "Table `achievement_reward` (ID: %u) contains the title (A: %u H: %u) for only one team.", id, reward.TitleId[0], reward.TitleId[1]);

        if (reward.TitleId[0])
        {
            CharTitlesEntry const* titleEntry = sCharTitlesStore.LookupEntry(reward.TitleId[0]);
            if (!titleEntry)
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_reward` (Entry: %u) contains an invalid title id (%u) in `title_A`, set to 0", id, reward.TitleId[0]);
                reward.TitleId[0] = 0;
            }
        }

        if (reward.TitleId[1])
        {
            CharTitlesEntry const* titleEntry = sCharTitlesStore.LookupEntry(reward.TitleId[1]);
            if (!titleEntry)
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_reward` (Entry: %u) contains an invalid title id (%u) in `title_H`, set to 0", id, reward.TitleId[1]);
                reward.TitleId[1] = 0;
            }
        }

        //check mail data before item for report including wrong item case
        if (reward.SenderCreatureId)
        {
            if (!sObjectMgr->GetCreatureTemplate(reward.SenderCreatureId))
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_reward` (ID: %u) contains an invalid creature ID %u as sender, mail reward skipped.", id, reward.SenderCreatureId);
                reward.SenderCreatureId = 0;
            }
        }
        else
        {
            if (reward.ItemId)
                TC_LOG_ERROR("sql.sql", "Table `achievement_reward` (ID: %u) does not have sender data, but contains an item reward. Item will not be rewarded.", id);

            if (!reward.Subject.empty())
                TC_LOG_ERROR("sql.sql", "Table `achievement_reward` (ID: %u) does not have sender data, but contains a mail subject.", id);

            if (!reward.Body.empty())
                TC_LOG_ERROR("sql.sql", "Table `achievement_reward` (ID: %u) does not have sender data, but contains mail text.", id);

            if (reward.MailTemplateId)
                TC_LOG_ERROR("sql.sql", "Table `achievement_reward` (ID: %u) does not have sender data, but has a MailTemplate.", id);
        }

        if (reward.MailTemplateId)
        {
            if (!sMailTemplateStore.LookupEntry(reward.MailTemplateId))
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_reward` (ID: %u) is using an invalid MailTemplate (%u).", id, reward.MailTemplateId);
                reward.MailTemplateId = 0;
            }
            else if (!reward.Subject.empty() || !reward.Body.empty())
                TC_LOG_ERROR("sql.sql", "Table `achievement_reward` (ID: %u) is using MailTemplate (%u) and mail subject/text.", id, reward.MailTemplateId);
        }

        if (reward.ItemId)
        {
            if (!sObjectMgr->GetItemTemplate(reward.ItemId))
            {
                TC_LOG_ERROR("sql.sql", "Table `achievement_reward` (ID: %u) contains an invalid item id %u, reward mail will not contain the rewarded item.", id, reward.ItemId);
                reward.ItemId = 0;
            }
        }

        m_achievementRewards[id] = reward;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u achievement rewards in %u ms.", uint32(m_achievementRewards.size()), GetMSTimeDiffToNow(oldMSTime));
}

void AchievementGlobalMgr::LoadRewardLocales()
{
    uint32 oldMSTime = getMSTime();

    m_achievementRewardLocales.clear();                       // need for reload case

    //                                               0   1       2        3
    QueryResult result = WorldDatabase.Query("SELECT ID, Locale, Subject, Body FROM achievement_reward_locale");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 achievement reward locale strings.  DB table `achievement_reward_locale` is empty.");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        uint32 id               = fields[0].GetUInt32();
        std::string localeName  = fields[1].GetString();
        std::string subject     = fields[2].GetString();
        std::string body        = fields[3].GetString();

        if (m_achievementRewards.find(id) == m_achievementRewards.end())
        {
            TC_LOG_ERROR("sql.sql", "Table `achievement_reward_locale` (ID: %u) contains locale strings for a non-existing achievement reward.", id);
            continue;
        }

        AchievementRewardLocale& data = m_achievementRewardLocales[id];
        LocaleConstant locale         = GetLocaleByName(localeName);
        if (locale == LOCALE_enUS)
            continue;

        ObjectMgr::AddLocaleString(subject, locale, data.Subject);
        ObjectMgr::AddLocaleString(body, locale, data.Text);
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u achievement reward locale strings in %u ms.", uint32(m_achievementRewardLocales.size()), GetMSTimeDiffToNow(oldMSTime));
}

AchievementEntry const* AchievementGlobalMgr::GetAchievement(uint32 achievementId) const
{
    return sAchievementStore.LookupEntry(achievementId);
}

AchievementCriteriaEntry const* AchievementGlobalMgr::GetAchievementCriteria(uint32 criteriaId) const
{
    return sAchievementCriteriaStore.LookupEntry(criteriaId);
}
