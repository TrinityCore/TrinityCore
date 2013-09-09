/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "ArenaTeam.h"
#include "ArenaTeamMgr.h"
#include "Battleground.h"
#include "CellImpl.h"
#include "Common.h"
#include "DatabaseEnv.h"
#include "DBCEnums.h"
#include "DisableMgr.h"
#include "GameEventMgr.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "InstanceScript.h"
#include "Language.h"
#include "Map.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ReputationMgr.h"
#include "ScriptMgr.h"
#include "SpellMgr.h"
#include "World.h"
#include "WorldPacket.h"

namespace Trinity
{
    class AchievementChatBuilder
    {
        public:
            AchievementChatBuilder(Player const& player, ChatMsg msgtype, int32 textId, uint32 ach_id)
                : i_player(player), i_msgtype(msgtype), i_textId(textId), i_achievementId(ach_id) {}
            void operator()(WorldPacket& data, LocaleConstant loc_idx)
            {
                char const* text = sObjectMgr->GetTrinityString(i_textId, loc_idx);

                data << uint8(i_msgtype);
                data << uint32(LANG_UNIVERSAL);
                data << uint64(i_player.GetGUID());
                data << uint32(5);
                data << uint64(i_player.GetGUID());
                data << uint32(strlen(text)+1);
                data << text;
                data << uint8(0);
                data << uint32(i_achievementId);
            }

        private:
            Player const& i_player;
            ChatMsg i_msgtype;
            int32 i_textId;
            uint32 i_achievementId;
    };
}                                                           // namespace Trinity

bool AchievementCriteriaData::IsValid(AchievementCriteriaEntry const* criteria)
{
    if (dataType >= MAX_ACHIEVEMENT_CRITERIA_DATA_TYPE)
    {
        TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_criteria_data` for criteria (Entry: %u) has wrong data type (%u), ignored.", criteria->ID, dataType);
        return false;
    }

    switch (criteria->type)
    {
        case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE:
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_BG:
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
            break;
        default:
            if (dataType != ACHIEVEMENT_CRITERIA_DATA_TYPE_SCRIPT)
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_criteria_data` has data for non-supported criteria type (Entry: %u Type: %u), ignored.", criteria->ID, criteria->type);
                return false;
            }
            break;
    }

    switch (dataType)
    {
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_NONE:
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_VALUE:
        case ACHIEVEMENT_CRITERIA_DATA_INSTANCE_SCRIPT:
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_CREATURE:
            if (!creature.id || !sObjectMgr->GetCreatureTemplate(creature.id))
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_CREATURE (%u) has non-existing creature id in value1 (%u), ignored.",
                    criteria->ID, criteria->type, dataType, creature.id);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_CLASS_RACE:
            if (!classRace.class_id && !classRace.race_id)
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_CLASS_RACE (%u) must not have 0 in either value field, ignored.",
                    criteria->ID, criteria->type, dataType);
                return false;
            }
            if (classRace.class_id && ((1 << (classRace.class_id-1)) & CLASSMASK_ALL_PLAYABLE) == 0)
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_CLASS_RACE (%u) has non-existing class in value1 (%u), ignored.",
                    criteria->ID, criteria->type, dataType, classRace.class_id);
                return false;
            }
            if (classRace.race_id && ((1 << (classRace.race_id-1)) & RACEMASK_ALL_PLAYABLE) == 0)
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_CLASS_RACE (%u) has non-existing race in value2 (%u), ignored.",
                    criteria->ID, criteria->type, dataType, classRace.race_id);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_LESS_HEALTH:
            if (health.percent < 1 || health.percent > 100)
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_PLAYER_LESS_HEALTH (%u) has wrong percent value in value1 (%u), ignored.",
                    criteria->ID, criteria->type, dataType, health.percent);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA:
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_AURA:
        {
            SpellInfo const* spellEntry = sSpellMgr->GetSpellInfo(aura.spell_id);
            if (!spellEntry)
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type %s (%u) has wrong spell id in value1 (%u), ignored.",
                    criteria->ID, criteria->type, (dataType == ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA?"ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA":"ACHIEVEMENT_CRITERIA_DATA_TYPE_T_AURA"), dataType, aura.spell_id);
                return false;
            }
            if (aura.effect_idx >= 3)
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type %s (%u) has wrong spell effect index in value2 (%u), ignored.",
                    criteria->ID, criteria->type, (dataType == ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA?"ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA":"ACHIEVEMENT_CRITERIA_DATA_TYPE_T_AURA"), dataType, aura.effect_idx);
                return false;
            }
            if (!spellEntry->Effects[aura.effect_idx].ApplyAuraName)
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type %s (%u) has non-aura spell effect (ID: %u Effect: %u), ignores.",
                    criteria->ID, criteria->type, (dataType == ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA?"ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA":"ACHIEVEMENT_CRITERIA_DATA_TYPE_T_AURA"), dataType, aura.spell_id, aura.effect_idx);
                return false;
            }
            return true;
        }
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_LEVEL:
            if (level.minlevel > STRONG_MAX_LEVEL)
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_T_LEVEL (%u) has wrong minlevel in value1 (%u), ignored.",
                    criteria->ID, criteria->type, dataType, level.minlevel);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_GENDER:
            if (gender.gender > GENDER_NONE)
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_T_GENDER (%u) has wrong gender in value1 (%u), ignored.",
                    criteria->ID, criteria->type, dataType, gender.gender);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_SCRIPT:
            if (!ScriptId)
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_SCRIPT (%u) does not have ScriptName set, ignored.",
                    criteria->ID, criteria->type, dataType);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_MAP_PLAYER_COUNT:
            if (map_players.maxcount <= 0)
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_MAP_PLAYER_COUNT (%u) has wrong max players count in value1 (%u), ignored.",
                    criteria->ID, criteria->type, dataType, map_players.maxcount);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_TEAM:
            if (team.team != ALLIANCE && team.team != HORDE)
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_T_TEAM (%u) has unknown team in value1 (%u), ignored.",
                    criteria->ID, criteria->type, dataType, team.team);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_DRUNK:
            if (drunk.state >= MAX_DRUNKEN)
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_S_DRUNK (%u) has unknown drunken state in value1 (%u), ignored.",
                    criteria->ID, criteria->type, dataType, drunk.state);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_HOLIDAY:
            if (!sHolidaysStore.LookupEntry(holiday.id))
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_HOLIDAY (%u) has unknown holiday in value1 (%u), ignored.",
                    criteria->ID, criteria->type, dataType, holiday.id);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_BG_LOSS_TEAM_SCORE:
            return true;                                    // not check correctness node indexes
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_EQUIPED_ITEM:
            if (equipped_item.item_quality >= MAX_ITEM_QUALITY)
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_criteria_requirement` (Entry: %u Type: %u) for requirement ACHIEVEMENT_CRITERIA_REQUIRE_S_EQUIPED_ITEM (%u) has unknown quality state in value1 (%u), ignored.",
                    criteria->ID, criteria->type, dataType, equipped_item.item_quality);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_PLAYER_CLASS_RACE:
            if (!classRace.class_id && !classRace.race_id)
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_S_PLAYER_CLASS_RACE (%u) must not have 0 in either value field, ignored.",
                    criteria->ID, criteria->type, dataType);
                return false;
            }
            if (classRace.class_id && ((1 << (classRace.class_id-1)) & CLASSMASK_ALL_PLAYABLE) == 0)
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_S_PLAYER_CLASS_RACE (%u) has non-existing class in value1 (%u), ignored.",
                    criteria->ID, criteria->type, dataType, classRace.class_id);
                return false;
            }
            if (classRace.race_id && ((1 << (classRace.race_id-1)) & RACEMASK_ALL_PLAYABLE) == 0)
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_S_PLAYER_CLASS_RACE (%u) has non-existing race in value2 (%u), ignored.",
                    criteria->ID, criteria->type, dataType, classRace.race_id);
                return false;
            }
            return true;
        default:
            TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_criteria_data` (Entry: %u Type: %u) has data for non-supported data type (%u), ignored.", criteria->ID, criteria->type, dataType);
            return false;
    }
}

bool AchievementCriteriaData::Meets(uint32 criteria_id, Player const* source, Unit const* target, uint32 miscValue1 /*= 0*/) const
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
            if (classRace.class_id && classRace.class_id != target->ToPlayer()->getClass())
                return false;
            if (classRace.race_id && classRace.race_id != target->ToPlayer()->getRace())
                return false;
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_PLAYER_CLASS_RACE:
            if (!source || source->GetTypeId() != TYPEID_PLAYER)
                return false;
            if (classRace.class_id && classRace.class_id != source->ToPlayer()->getClass())
                return false;
            if (classRace.race_id && classRace.race_id != source->ToPlayer()->getRace())
                return false;
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_LESS_HEALTH:
            if (!target || target->GetTypeId() != TYPEID_PLAYER)
                return false;
            return !target->HealthAbovePct(health.percent);
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA:
            return source->HasAuraEffect(aura.spell_id, aura.effect_idx);
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_AURA:
            return target && target->HasAuraEffect(aura.spell_id, aura.effect_idx);
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_VALUE:
            return miscValue1 >= value.minvalue;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_LEVEL:
            if (!target)
                return false;
            return target->getLevel() >= level.minlevel;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_GENDER:
            if (!target)
                return false;
            return target->getGender() == gender.gender;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_SCRIPT:
            return sScriptMgr->OnCriteriaCheck(ScriptId, const_cast<Player*>(source), const_cast<Unit*>(target));
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
        case ACHIEVEMENT_CRITERIA_DATA_INSTANCE_SCRIPT:
        {
            if (!source->IsInWorld())
                return false;
            Map* map = source->GetMap();
            if (!map->IsDungeon())
            {
                TC_LOG_ERROR(LOG_FILTER_ACHIEVEMENTSYS, "Achievement system call ACHIEVEMENT_CRITERIA_DATA_INSTANCE_SCRIPT (%u) for achievement criteria %u for non-dungeon/non-raid map %u",
                    ACHIEVEMENT_CRITERIA_DATA_INSTANCE_SCRIPT, criteria_id, map->GetId());
                    return false;
            }
            InstanceScript* instance = ((InstanceMap*)map)->GetInstanceScript();
            if (!instance)
            {
                TC_LOG_ERROR(LOG_FILTER_ACHIEVEMENTSYS, "Achievement system call ACHIEVEMENT_CRITERIA_DATA_INSTANCE_SCRIPT (%u) for achievement criteria %u for map %u but map does not have a instance script",
                    ACHIEVEMENT_CRITERIA_DATA_INSTANCE_SCRIPT, criteria_id, map->GetId());
                return false;
            }
            return instance->CheckAchievementCriteriaMeet(criteria_id, source, target, miscValue1);
        }
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_EQUIPED_ITEM:
        {
            ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(miscValue1);
            if (!pProto)
                return false;
            return pProto->ItemLevel >= equipped_item.item_level && pProto->Quality >= equipped_item.item_quality;
        }
        default:
            break;
    }
    return false;
}

bool AchievementCriteriaDataSet::Meets(Player const* source, Unit const* target, uint32 miscValue /*= 0*/) const
{
    for (Storage::const_iterator itr = storage.begin(); itr != storage.end(); ++itr)
        if (!itr->Meets(criteria_id, source, target, miscValue))
            return false;

    return true;
}

template<class T>
AchievementMgr<T>::AchievementMgr(T* owner): _owner(owner), _achievementPoints(0) {}

template<class T>
AchievementMgr<T>::~AchievementMgr()
{
}

template<class T>
void AchievementMgr<T>::SendPacket(WorldPacket* data) const
{
}

template<>
void AchievementMgr<Guild>::SendPacket(WorldPacket* data) const
{
    GetOwner()->BroadcastPacket(data);
}

template<>
void AchievementMgr<Player>::SendPacket(WorldPacket* data) const
{
    GetOwner()->GetSession()->SendPacket(data);
}

template<class T>
void AchievementMgr<T>::RemoveCriteriaProgress(AchievementCriteriaEntry const* entry)
{
    if (!entry)
        return;

    CriteriaProgressMap::iterator criteriaProgress = m_criteriaProgress.find(entry->ID);
    if (criteriaProgress == m_criteriaProgress.end())
        return;

    WorldPacket data(SMSG_CRITERIA_DELETED, 4);
    data << uint32(entry->ID);
    SendPacket(&data);

    m_criteriaProgress.erase(criteriaProgress);
}

template<>
void AchievementMgr<Guild>::RemoveCriteriaProgress(AchievementCriteriaEntry const* entry)
{
    if (!entry)
        return;

    CriteriaProgressMap::iterator criteriaProgress = m_criteriaProgress.find(entry->ID);
    if (criteriaProgress == m_criteriaProgress.end())
        return;

    ObjectGuid guid = GetOwner()->GetGUID();

    WorldPacket data(SMSG_GUILD_CRITERIA_DELETED, 4 + 8);
    data.WriteBit(guid[6]);
    data.WriteBit(guid[5]);
    data.WriteBit(guid[7]);
    data.WriteBit(guid[0]);
    data.WriteBit(guid[1]);
    data.WriteBit(guid[3]);
    data.WriteBit(guid[2]);
    data.WriteBit(guid[4]);

    data.WriteByteSeq(guid[2]);
    data.WriteByteSeq(guid[3]);
    data.WriteByteSeq(guid[4]);
    data.WriteByteSeq(guid[1]);
    data.WriteByteSeq(guid[7]);
    data << uint32(entry->ID);
    data.WriteByteSeq(guid[5]);
    data.WriteByteSeq(guid[0]);
    data.WriteByteSeq(guid[6]);

    SendPacket(&data);

    m_criteriaProgress.erase(criteriaProgress);
}

template<class T>
void AchievementMgr<T>::ResetAchievementCriteria(AchievementCriteriaTypes type, uint64 miscValue1, uint64 miscValue2, bool evenIfCriteriaComplete)
{
    TC_LOG_DEBUG(LOG_FILTER_ACHIEVEMENTSYS, "ResetAchievementCriteria(%u, " UI64FMTD ", " UI64FMTD ")", type, miscValue1, miscValue2);

    // disable for gamemasters with GM-mode enabled
    if (GetOwner()->IsGameMaster())
        return;

    AchievementCriteriaEntryList const& achievementCriteriaList = sAchievementMgr->GetAchievementCriteriaByType(type);
    for (AchievementCriteriaEntryList::const_iterator i = achievementCriteriaList.begin(); i != achievementCriteriaList.end(); ++i)
    {
        AchievementCriteriaEntry const* achievementCriteria = (*i);

        AchievementEntry const* achievement = sAchievementMgr->GetAchievement(achievementCriteria->achievement);
        if (!achievement)
            continue;

        // don't update already completed criteria if not forced or achievement already complete
        if ((IsCompletedCriteria(achievementCriteria, achievement) && !evenIfCriteriaComplete) || HasAchieved(achievement->ID))
            continue;

        for (uint8 j = 0; j < MAX_CRITERIA_REQUIREMENTS; ++j)
            if (achievementCriteria->additionalRequirements[j].additionalRequirement_type == miscValue1 &&
                (!achievementCriteria->additionalRequirements[j].additionalRequirement_value ||
                achievementCriteria->additionalRequirements[j].additionalRequirement_value == miscValue2))
            {
                RemoveCriteriaProgress(achievementCriteria);
                break;
            }
    }
}

template<>
void AchievementMgr<Guild>::ResetAchievementCriteria(AchievementCriteriaTypes /*type*/, uint64 /*miscValue1*/, uint64 /*miscValue2*/, bool /*evenIfCriteriaComplete*/)
{
    // Not needed
}

template<class T>
void AchievementMgr<T>::DeleteFromDB(uint32 /*lowguid*/)
{
}

template<>
void AchievementMgr<Player>::DeleteFromDB(uint32 lowguid)
{
    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_ACHIEVEMENT);
    stmt->setUInt32(0, lowguid);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_ACHIEVEMENT_PROGRESS);
    stmt->setUInt32(0, lowguid);
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);
}

template<>
void AchievementMgr<Guild>::DeleteFromDB(uint32 lowguid)
{
    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ALL_GUILD_ACHIEVEMENTS);
    stmt->setUInt32(0, lowguid);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ALL_GUILD_ACHIEVEMENT_CRITERIA);
    stmt->setUInt32(0, lowguid);
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);
}

template<class T>
void AchievementMgr<T>::SaveToDB(SQLTransaction& /*trans*/)
{
}

template<>
void AchievementMgr<Player>::SaveToDB(SQLTransaction& trans)
{
    if (!m_completedAchievements.empty())
    {
        for (CompletedAchievementMap::iterator iter = m_completedAchievements.begin(); iter != m_completedAchievements.end(); ++iter)
        {
            if (!iter->second.changed)
                continue;

            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_ACHIEVEMENT_BY_ACHIEVEMENT);
            stmt->setUInt16(0, iter->first);
            stmt->setUInt32(1, GetOwner()->GetGUID());
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_ACHIEVEMENT);
            stmt->setUInt32(0, GetOwner()->GetGUID());
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
            stmt->setUInt32(0, GetOwner()->GetGUID());
            stmt->setUInt16(1, iter->first);
            trans->Append(stmt);

            if (iter->second.counter)
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_ACHIEVEMENT_PROGRESS);
                stmt->setUInt32(0, GetOwner()->GetGUID());
                stmt->setUInt16(1, iter->first);
                stmt->setUInt32(2, iter->second.counter);
                stmt->setUInt32(3, uint32(iter->second.date));
                trans->Append(stmt);
            }

            iter->second.changed = false;
        }
    }
}

template<>
void AchievementMgr<Guild>::SaveToDB(SQLTransaction& trans)
{
    PreparedStatement* stmt;
    std::ostringstream guidstr;
    for (CompletedAchievementMap::const_iterator itr = m_completedAchievements.begin(); itr != m_completedAchievements.end(); ++itr)
    {
        if (!itr->second.changed)
            continue;

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_ACHIEVEMENT);
        stmt->setUInt32(0, GetOwner()->GetId());
        stmt->setUInt16(1, itr->first);
        trans->Append(stmt);

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_ACHIEVEMENT);
        stmt->setUInt32(0, GetOwner()->GetId());
        stmt->setUInt16(1, itr->first);
        stmt->setUInt32(2, itr->second.date);
        for (std::set<uint64>::const_iterator gItr = itr->second.guids.begin(); gItr != itr->second.guids.end(); ++gItr)
            guidstr << GUID_LOPART(*gItr) << ',';

        stmt->setString(3, guidstr.str());
        trans->Append(stmt);

        guidstr.str("");
    }

    for (CriteriaProgressMap::const_iterator itr = m_criteriaProgress.begin(); itr != m_criteriaProgress.end(); ++itr)
    {
        if (!itr->second.changed)
            continue;

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GUILD_ACHIEVEMENT_CRITERIA);
        stmt->setUInt32(0, GetOwner()->GetId());
        stmt->setUInt16(1, itr->first);
        trans->Append(stmt);

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_GUILD_ACHIEVEMENT_CRITERIA);
        stmt->setUInt32(0, GetOwner()->GetId());
        stmt->setUInt16(1, itr->first);
        stmt->setUInt64(2, itr->second.counter);
        stmt->setUInt32(3, itr->second.date);
        stmt->setUInt32(4, GUID_LOPART(itr->second.CompletedGUID));
        trans->Append(stmt);
    }
}

template<class T>
void AchievementMgr<T>::LoadFromDB(PreparedQueryResult achievementResult, PreparedQueryResult criteriaResult)
{
}

template<>
void AchievementMgr<Player>::LoadFromDB(PreparedQueryResult achievementResult, PreparedQueryResult criteriaResult)
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

            _achievementPoints += achievement->points;

            // title achievement rewards are retroactive
            if (AchievementReward const* reward = sAchievementMgr->GetAchievementReward(achievement))
                if (uint32 titleId = reward->titleId[Player::TeamForRace(GetOwner()->getRace()) == ALLIANCE ? 0 : 1])
                    if (CharTitlesEntry const* titleEntry = sCharTitlesStore.LookupEntry(titleId))
                        GetOwner()->SetTitle(titleEntry);

        }
        while (achievementResult->NextRow());
    }

    if (criteriaResult)
    {
        time_t now = time(NULL);
        do
        {
            Field* fields = criteriaResult->Fetch();
            uint32 id      = fields[0].GetUInt16();
            uint64 counter = fields[1].GetUInt64();
            time_t date    = time_t(fields[2].GetUInt32());

            AchievementCriteriaEntry const* criteria = sAchievementMgr->GetAchievementCriteria(id);
            if (!criteria)
            {
                // we will remove not existed criteria for all characters
                TC_LOG_ERROR(LOG_FILTER_ACHIEVEMENTSYS, "Non-existing achievement criteria %u data removed from table `character_achievement_progress`.", id);

                PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_INVALID_ACHIEV_PROGRESS_CRITERIA);
                stmt->setUInt16(0, uint16(id));
                CharacterDatabase.Execute(stmt);

                continue;
            }

            if (criteria->timeLimit && time_t(date + criteria->timeLimit) < now)
                continue;

            CriteriaProgress& progress = m_criteriaProgress[id];
            progress.counter = counter;
            progress.date    = date;
            progress.changed = false;
        }
        while (criteriaResult->NextRow());
    }
}

template<>
void AchievementMgr<Guild>::LoadFromDB(PreparedQueryResult achievementResult, PreparedQueryResult criteriaResult)
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
            Tokenizer guids(fields[2].GetString(), ' ');
            for (uint32 i = 0; i < guids.size(); ++i)
                ca.guids.insert(MAKE_NEW_GUID(atol(guids[i]), 0, HIGHGUID_PLAYER));

            ca.changed = false;

            _achievementPoints += achievement->points;
        }
        while (achievementResult->NextRow());
    }

    if (criteriaResult)
    {
        time_t now = time(NULL);
        do
        {
            Field* fields = criteriaResult->Fetch();
            uint32 id      = fields[0].GetUInt16();
            uint32 counter = fields[1].GetUInt32();
            time_t date    = time_t(fields[2].GetUInt32());
            uint64 guid    = fields[3].GetUInt32();

            AchievementCriteriaEntry const* criteria = sAchievementMgr->GetAchievementCriteria(id);
            if (!criteria)
            {
                // we will remove not existed criteria for all guilds
                TC_LOG_ERROR(LOG_FILTER_ACHIEVEMENTSYS, "Non-existing achievement criteria %u data removed from table `guild_achievement_progress`.", id);

                PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_INVALID_ACHIEV_PROGRESS_CRITERIA_GUILD);
                stmt->setUInt16(0, uint16(id));
                CharacterDatabase.Execute(stmt);
                continue;
            }

            if (criteria->timeLimit && time_t(date + criteria->timeLimit) < now)
                continue;

            CriteriaProgress& progress = m_criteriaProgress[id];
            progress.counter = counter;
            progress.date    = date;
            progress.CompletedGUID = MAKE_NEW_GUID(guid, 0, HIGHGUID_PLAYER);
            progress.changed = false;
        } while (criteriaResult->NextRow());
    }
}

template<class T>
void AchievementMgr<T>::Reset()
{
}

template<>
void AchievementMgr<Player>::Reset()
{
    for (CompletedAchievementMap::const_iterator iter = m_completedAchievements.begin(); iter != m_completedAchievements.end(); ++iter)
    {
        WorldPacket data(SMSG_ACHIEVEMENT_DELETED, 4);
        data << uint32(iter->first);
        SendPacket(&data);
    }

    for (CriteriaProgressMap::const_iterator iter = m_criteriaProgress.begin(); iter != m_criteriaProgress.end(); ++iter)
    {
        WorldPacket data(SMSG_CRITERIA_DELETED, 4);
        data << uint32(iter->first);
        SendPacket(&data);
    }

    m_completedAchievements.clear();
    _achievementPoints = 0;
    m_criteriaProgress.clear();
    DeleteFromDB(GetOwner()->GetGUIDLow());

    // re-fill data
    CheckAllAchievementCriteria(GetOwner());
}

template<>
void AchievementMgr<Guild>::Reset()
{
    ObjectGuid guid = GetOwner()->GetGUID();
    for (CompletedAchievementMap::const_iterator iter = m_completedAchievements.begin(); iter != m_completedAchievements.end(); ++iter)
    {
        WorldPacket data(SMSG_GUILD_ACHIEVEMENT_DELETED, 4);
        data.WriteBit(guid[4]);
        data.WriteBit(guid[1]);
        data.WriteBit(guid[2]);
        data.WriteBit(guid[3]);
        data.WriteBit(guid[0]);
        data.WriteBit(guid[7]);
        data.WriteBit(guid[5]);
        data.WriteBit(guid[6]);
        data << uint32(iter->first);
        data.WriteByteSeq(guid[5]);
        data.WriteByteSeq(guid[1]);
        data.WriteByteSeq(guid[3]);
        data.WriteByteSeq(guid[6]);
        data.WriteByteSeq(guid[0]);
        data.WriteByteSeq(guid[7]);
        data.AppendPackedTime(iter->second.date);
        data.WriteByteSeq(guid[4]);
        data.WriteByteSeq(guid[2]);
        SendPacket(&data);
    }

    while (!m_criteriaProgress.empty())
        if (AchievementCriteriaEntry const* criteria = sAchievementMgr->GetAchievementCriteria(m_criteriaProgress.begin()->first))
            RemoveCriteriaProgress(criteria);

    _achievementPoints = 0;
    m_completedAchievements.clear();
    DeleteFromDB(GetOwner()->GetId());
}

template<class T>
void AchievementMgr<T>::SendAchievementEarned(AchievementEntry const* achievement) const
{
    // Don't send for achievements with ACHIEVEMENT_FLAG_HIDDEN
    if (achievement->flags & ACHIEVEMENT_FLAG_HIDDEN)
        return;

    TC_LOG_DEBUG(LOG_FILTER_ACHIEVEMENTSYS, "AchievementMgr::SendAchievementEarned(%u)", achievement->ID);

    if (Guild* guild = sGuildMgr->GetGuildById(GetOwner()->GetGuildId()))
    {
        Trinity::AchievementChatBuilder say_builder(*GetOwner(), CHAT_MSG_GUILD_ACHIEVEMENT, LANG_ACHIEVEMENT_EARNED, achievement->ID);
        Trinity::LocalizedPacketDo<Trinity::AchievementChatBuilder> say_do(say_builder);
        guild->BroadcastWorker(say_do);
    }

    if (achievement->flags & (ACHIEVEMENT_FLAG_REALM_FIRST_KILL | ACHIEVEMENT_FLAG_REALM_FIRST_REACH))
    {
        // broadcast realm first reached
        WorldPacket data(SMSG_SERVER_FIRST_ACHIEVEMENT, GetOwner()->GetName().size() + 1 + 8 + 4 + 4);
        data << GetOwner()->GetName();
        data << uint64(GetOwner()->GetGUID());
        data << uint32(achievement->ID);
        data << uint32(0);                                  // 1=link supplied string as player name, 0=display plain string
        sWorld->SendGlobalMessage(&data);
    }
    // if player is in world he can tell his friends about new achievement
    else if (GetOwner()->IsInWorld())
    {
        Trinity::AchievementChatBuilder say_builder(*GetOwner(), CHAT_MSG_ACHIEVEMENT, LANG_ACHIEVEMENT_EARNED, achievement->ID);

        CellCoord p = Trinity::ComputeCellCoord(GetOwner()->GetPositionX(), GetOwner()->GetPositionY());

        Cell cell(p);
        cell.SetNoCreate();

        Trinity::LocalizedPacketDo<Trinity::AchievementChatBuilder> say_do(say_builder);
        Trinity::PlayerDistWorker<Trinity::LocalizedPacketDo<Trinity::AchievementChatBuilder> > say_worker(GetOwner(), sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_SAY), say_do);
        TypeContainerVisitor<Trinity::PlayerDistWorker<Trinity::LocalizedPacketDo<Trinity::AchievementChatBuilder> >, WorldTypeMapContainer > message(say_worker);
        cell.Visit(p, message, *GetOwner()->GetMap(), *GetOwner(), sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_SAY));
    }

    WorldPacket data(SMSG_ACHIEVEMENT_EARNED, 8+4+8);
    data.append(GetOwner()->GetPackGUID());
    data << uint32(achievement->ID);
    data.AppendPackedTime(time(NULL));
    data << uint32(0);  // does not notify player ingame
    GetOwner()->SendMessageToSetInRange(&data, sWorld->getFloatConfig(CONFIG_LISTEN_RANGE_SAY), true);
}

template<>
void AchievementMgr<Guild>::SendAchievementEarned(AchievementEntry const* achievement) const
{
    ObjectGuid guid = GetOwner()->GetGUID();

    WorldPacket data(SMSG_GUILD_ACHIEVEMENT_EARNED, 8+4+8);
    data.WriteBit(guid[3]);
    data.WriteBit(guid[1]);
    data.WriteBit(guid[0]);
    data.WriteBit(guid[7]);
    data.WriteBit(guid[4]);
    data.WriteBit(guid[6]);
    data.WriteBit(guid[2]);
    data.WriteBit(guid[5]);

    data.WriteByteSeq(guid[2]);
    data.AppendPackedTime(time(NULL));
    data.WriteByteSeq(guid[0]);
    data.WriteByteSeq(guid[4]);
    data.WriteByteSeq(guid[1]);
    data.WriteByteSeq(guid[3]);
    data << uint32(achievement->ID);
    data.WriteByteSeq(guid[7]);
    data.WriteByteSeq(guid[5]);
    data.WriteByteSeq(guid[6]);

    SendPacket(&data);
}

template<class T>
void AchievementMgr<T>::SendCriteriaUpdate(AchievementCriteriaEntry const* /*entry*/, CriteriaProgress const* /*progress*/, uint32 /*timeElapsed*/, bool /*timedCompleted*/) const
{
}

template<>
void AchievementMgr<Player>::SendCriteriaUpdate(AchievementCriteriaEntry const* entry, CriteriaProgress const* progress, uint32 timeElapsed, bool timedCompleted) const
{
    WorldPacket data(SMSG_CRITERIA_UPDATE, 8 + 4 + 8);
    data << uint32(entry->ID);

    // the counter is packed like a packed Guid
    data.appendPackGUID(progress->counter);

    data.appendPackGUID(GetOwner()->GetGUID());
    if (!entry->timeLimit)
        data << uint32(0);
    else
        data << uint32(timedCompleted ? 0 : 1); // this are some flags, 1 is for keeping the counter at 0 in client
    data.AppendPackedTime(progress->date);
    data << uint32(timeElapsed);    // time elapsed in seconds
    data << uint32(0);              // unk
    SendPacket(&data);
}

template<>
void AchievementMgr<Guild>::SendCriteriaUpdate(AchievementCriteriaEntry const* entry, CriteriaProgress const* progress, uint32 /*timeElapsed*/, bool /*timedCompleted*/) const
{
    //will send response to criteria progress request
    WorldPacket data(SMSG_GUILD_CRITERIA_DATA, 3 + 1 + 1 + 8 + 8 + 4 + 4 + 4 + 4 + 4);

    ObjectGuid counter = progress->counter; // for accessing every byte individually
    ObjectGuid guid = progress->CompletedGUID;

    data.WriteBits(1, 21);
    data.WriteBit(counter[4]);
    data.WriteBit(counter[1]);
    data.WriteBit(guid[2]);
    data.WriteBit(counter[3]);
    data.WriteBit(guid[1]);
    data.WriteBit(counter[5]);
    data.WriteBit(counter[0]);
    data.WriteBit(guid[3]);
    data.WriteBit(counter[2]);
    data.WriteBit(guid[7]);
    data.WriteBit(guid[5]);
    data.WriteBit(guid[0]);
    data.WriteBit(counter[6]);
    data.WriteBit(guid[6]);
    data.WriteBit(counter[7]);
    data.WriteBit(guid[4]);

    data.FlushBits();

    data.WriteByteSeq(guid[5]);
    data << uint32(progress->date);      // unknown date
    data.WriteByteSeq(counter[3]);
    data.WriteByteSeq(counter[7]);
    data << uint32(progress->date);      // unknown date
    data.WriteByteSeq(counter[6]);
    data.WriteByteSeq(guid[4]);
    data.WriteByteSeq(guid[1]);
    data.WriteByteSeq(counter[4]);
    data.WriteByteSeq(guid[3]);
    data.WriteByteSeq(counter[0]);
    data.WriteByteSeq(guid[2]);
    data.WriteByteSeq(counter[1]);
    data.WriteByteSeq(guid[6]);
    data << uint32(progress->date);      // last update time (not packed!)
    data << uint32(entry->ID);
    data.WriteByteSeq(counter[5]);
    data << uint32(0);
    data.WriteByteSeq(guid[7]);
    data.WriteByteSeq(counter[2]);
    data.WriteByteSeq(guid[0]);

    SendPacket(&data);
}

/**
 * called at player login. The player might have fulfilled some achievements when the achievement system wasn't working yet
 */
template<class T>
void AchievementMgr<T>::CheckAllAchievementCriteria(Player* referencePlayer)
{
    // suppress sending packets
    for (uint32 i=0; i<ACHIEVEMENT_CRITERIA_TYPE_TOTAL; ++i)
        UpdateAchievementCriteria(AchievementCriteriaTypes(i), 0, 0, 0, NULL, referencePlayer);
}

static const uint32 achievIdByArenaSlot[MAX_ARENA_SLOT] = {1057, 1107, 1108};
static const uint32 achievIdForDungeon[][4] =
{
    // ach_cr_id, is_dungeon, is_raid, is_heroic_dungeon
    { 321,       true,      true,   true  },
    { 916,       false,     true,   false },
    { 917,       false,     true,   false },
    { 918,       true,      false,  false },
    { 2219,      false,     false,  true  },
    { 0,         false,     false,  false }
};

// Helper function to avoid having to specialize template for a 800 line long function
template <typename T> static bool IsGuild() { return false; }
template<> bool IsGuild<Guild>() { return true; }

/**
 * this function will be called whenever the user might have done a criteria relevant action
 */
template<class T>
void AchievementMgr<T>::UpdateAchievementCriteria(AchievementCriteriaTypes type, uint64 miscValue1 /*= 0*/, uint64 miscValue2 /*= 0*/, uint64 miscValue3 /*= 0*/, Unit const* unit /*= NULL*/, Player* referencePlayer /*= NULL*/)
{
    if (type >= ACHIEVEMENT_CRITERIA_TYPE_TOTAL)
    {
        TC_LOG_DEBUG(LOG_FILTER_ACHIEVEMENTSYS, "UpdateAchievementCriteria: Wrong criteria type %u", type);
        return;
    }

    if (!referencePlayer)
    {
        TC_LOG_DEBUG(LOG_FILTER_ACHIEVEMENTSYS, "UpdateAchievementCriteria: Player is NULL! Cant update criteria");
        return;
    }

    // disable for gamemasters with GM-mode enabled
    if (referencePlayer->IsGameMaster())
    {
        TC_LOG_DEBUG(LOG_FILTER_ACHIEVEMENTSYS, "UpdateAchievementCriteria: [Player %s GM mode on] %s, %s (%u), " UI64FMTD ", " UI64FMTD ", " UI64FMTD
            , referencePlayer->GetName().c_str(), GetLogNameForGuid(GetOwner()->GetGUID()), AchievementGlobalMgr::GetCriteriaTypeString(type), type, miscValue1, miscValue2, miscValue3);
        return;
    }

    TC_LOG_DEBUG(LOG_FILTER_ACHIEVEMENTSYS, "UpdateAchievementCriteria: %s, %s (%u), " UI64FMTD ", " UI64FMTD ", " UI64FMTD
        , GetLogNameForGuid(GetOwner()->GetGUID()), AchievementGlobalMgr::GetCriteriaTypeString(type), type, miscValue1, miscValue2, miscValue3);

    // Lua_GetGuildLevelEnabled() is checked in achievement UI to display guild tab
    if (IsGuild<T>() && !sWorld->getBoolConfig(CONFIG_GUILD_LEVELING_ENABLED))
        return;

    AchievementCriteriaEntryList const& achievementCriteriaList = sAchievementMgr->GetAchievementCriteriaByType(type, IsGuild<T>());
    for (AchievementCriteriaEntryList::const_iterator i = achievementCriteriaList.begin(); i != achievementCriteriaList.end(); ++i)
    {
        AchievementCriteriaEntry const* achievementCriteria = (*i);
        AchievementEntry const* achievement = sAchievementMgr->GetAchievement(achievementCriteria->achievement);
        if (!achievement)
        {
            TC_LOG_ERROR(LOG_FILTER_ACHIEVEMENTSYS, "UpdateAchievementCriteria: Achievement %u not found!", achievementCriteria->achievement);
            continue;
        }

        if (!CanUpdateCriteria(achievementCriteria, achievement, miscValue1, miscValue2, miscValue3, unit, referencePlayer))
            continue;

        // requirements not found in the dbc
        if (AchievementCriteriaDataSet const* data = sAchievementMgr->GetCriteriaDataSet(achievementCriteria))
            if (!data->Meets(referencePlayer, unit, miscValue1))
                continue;

        switch (type)
        {
            // std. case: increment at 1
            case ACHIEVEMENT_CRITERIA_TYPE_NUMBER_OF_TALENT_RESETS:
            case ACHIEVEMENT_CRITERIA_TYPE_LOSE_DUEL:
            case ACHIEVEMENT_CRITERIA_TYPE_CREATE_AUCTION:
            case ACHIEVEMENT_CRITERIA_TYPE_WON_AUCTIONS:    /* FIXME: for online player only currently */
            case ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED:
            case ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED:
            case ACHIEVEMENT_CRITERIA_TYPE_QUEST_ABANDONED:
            case ACHIEVEMENT_CRITERIA_TYPE_FLIGHT_PATHS_TAKEN:
            case ACHIEVEMENT_CRITERIA_TYPE_ACCEPTED_SUMMONINGS:
            case ACHIEVEMENT_CRITERIA_TYPE_LOOT_EPIC_ITEM:
            case ACHIEVEMENT_CRITERIA_TYPE_RECEIVE_EPIC_ITEM:
            case ACHIEVEMENT_CRITERIA_TYPE_DEATH:
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST:
            case ACHIEVEMENT_CRITERIA_TYPE_DEATH_AT_MAP:
            case ACHIEVEMENT_CRITERIA_TYPE_DEATH_IN_DUNGEON:
            case ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_CREATURE:
            case ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_PLAYER:
            case ACHIEVEMENT_CRITERIA_TYPE_DEATHS_FROM:
            case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET:
            case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2:
            case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL:
            case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL2:
            case ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_ARENA:
            case ACHIEVEMENT_CRITERIA_TYPE_USE_ITEM:
            case ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED_ON_LOOT:
            case ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED_ON_LOOT:
            case ACHIEVEMENT_CRITERIA_TYPE_DO_EMOTE:
            case ACHIEVEMENT_CRITERIA_TYPE_USE_GAMEOBJECT:
            case ACHIEVEMENT_CRITERIA_TYPE_FISH_IN_GAMEOBJECT:
            case ACHIEVEMENT_CRITERIA_TYPE_WIN_DUEL:
            case ACHIEVEMENT_CRITERIA_TYPE_HK_CLASS:
            case ACHIEVEMENT_CRITERIA_TYPE_HK_RACE:
            case ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE:
            case ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL:
            case ACHIEVEMENT_CRITERIA_TYPE_SPECIAL_PVP_KILL:
            case ACHIEVEMENT_CRITERIA_TYPE_GET_KILLING_BLOWS:
            case ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL_AT_AREA:
            case ACHIEVEMENT_CRITERIA_TYPE_WIN_ARENA: // This also behaves like ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_ARENA
                SetCriteriaProgress(achievementCriteria, 1, referencePlayer, PROGRESS_ACCUMULATE);
                break;
            // std case: increment at miscValue1
            case ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_VENDORS:
            case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_TALENTS:
            case ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_QUEST_REWARD:
            case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_TRAVELLING:
            case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_AT_BARBER:
            case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_MAIL:
            case ACHIEVEMENT_CRITERIA_TYPE_LOOT_MONEY:
            case ACHIEVEMENT_CRITERIA_TYPE_GOLD_EARNED_BY_AUCTIONS:/* FIXME: for online player only currently */
            case ACHIEVEMENT_CRITERIA_TYPE_TOTAL_DAMAGE_RECEIVED:
            case ACHIEVEMENT_CRITERIA_TYPE_TOTAL_HEALING_RECEIVED:
            case ACHIEVEMENT_CRITERIA_TYPE_USE_LFD_TO_GROUP_WITH_PLAYERS:
            case ACHIEVEMENT_CRITERIA_TYPE_WIN_BG:
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_BATTLEGROUND:
            case ACHIEVEMENT_CRITERIA_TYPE_DAMAGE_DONE:
            case ACHIEVEMENT_CRITERIA_TYPE_HEALING_DONE:
                SetCriteriaProgress(achievementCriteria, miscValue1, referencePlayer, PROGRESS_ACCUMULATE);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE:
            case ACHIEVEMENT_CRITERIA_TYPE_LOOT_TYPE:
            case ACHIEVEMENT_CRITERIA_TYPE_OWN_ITEM:
            case ACHIEVEMENT_CRITERIA_TYPE_LOOT_ITEM:
            case ACHIEVEMENT_CRITERIA_TYPE_CURRENCY:
                SetCriteriaProgress(achievementCriteria, miscValue2, referencePlayer, PROGRESS_ACCUMULATE);
                break;
            // std case: high value at miscValue1
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_AUCTION_BID:
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_AUCTION_SOLD: /* FIXME: for online player only currently */
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HIT_DEALT:
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HIT_RECEIVED:
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEAL_CASTED:
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEALING_RECEIVED:
                SetCriteriaProgress(achievementCriteria, miscValue1, referencePlayer, PROGRESS_HIGHEST);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_REACH_LEVEL:
                SetCriteriaProgress(achievementCriteria, referencePlayer->getLevel(), referencePlayer);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_REACH_SKILL_LEVEL:
                if (uint32 skillvalue = referencePlayer->GetBaseSkillValue(achievementCriteria->reach_skill_level.skillID))
                    SetCriteriaProgress(achievementCriteria, skillvalue, referencePlayer);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LEVEL:
                if (uint32 maxSkillvalue = referencePlayer->GetPureMaxSkillValue(achievementCriteria->learn_skill_level.skillID))
                    SetCriteriaProgress(achievementCriteria, maxSkillvalue, referencePlayer);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST_COUNT:
                SetCriteriaProgress(achievementCriteria, referencePlayer->GetRewardedQuestCount(), referencePlayer);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST_DAILY:
            {
                time_t nextDailyResetTime = sWorld->GetNextDailyQuestsResetTime();
                CriteriaProgress *progress = GetCriteriaProgress(achievementCriteria);

                if (!miscValue1) // Login case.
                {
                    // reset if player missed one day.
                    if (progress && progress->date < (nextDailyResetTime - 2 * DAY))
                        SetCriteriaProgress(achievementCriteria, 0, referencePlayer, PROGRESS_SET);
                    continue;
                }

                ProgressType progressType;
                if (!progress)
                    // 1st time. Start count.
                    progressType = PROGRESS_SET;
                else if (progress->date < (nextDailyResetTime - 2 * DAY))
                    // last progress is older than 2 days. Player missed 1 day => Restart count.
                    progressType = PROGRESS_SET;
                else if (progress->date < (nextDailyResetTime - DAY))
                    // last progress is between 1 and 2 days. => 1st time of the day.
                    progressType = PROGRESS_ACCUMULATE;
                else
                    // last progress is within the day before the reset => Already counted today.
                    continue;

                SetCriteriaProgress(achievementCriteria, 1, referencePlayer, progressType);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUESTS_IN_ZONE:
            {
                uint32 counter = 0;

                const RewardedQuestSet &rewQuests = referencePlayer->getRewardedQuests();
                for (RewardedQuestSet::const_iterator itr = rewQuests.begin(); itr != rewQuests.end(); ++itr)
                {
                    Quest const* quest = sObjectMgr->GetQuestTemplate(*itr);
                    if (quest && quest->GetZoneOrSort() >= 0 && uint32(quest->GetZoneOrSort()) == achievementCriteria->complete_quests_in_zone.zoneID)
                        ++counter;
                }
                SetCriteriaProgress(achievementCriteria, counter, referencePlayer);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_FALL_WITHOUT_DYING:
                // miscValue1 is the ingame fallheight*100 as stored in dbc
                SetCriteriaProgress(achievementCriteria, miscValue1, referencePlayer);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST:
            case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SPELL:
            case ACHIEVEMENT_CRITERIA_TYPE_EXPLORE_AREA:
            case ACHIEVEMENT_CRITERIA_TYPE_VISIT_BARBER_SHOP:
            case ACHIEVEMENT_CRITERIA_TYPE_EQUIP_EPIC_ITEM:
            case ACHIEVEMENT_CRITERIA_TYPE_EQUIP_ITEM:
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_ACHIEVEMENT:
                SetCriteriaProgress(achievementCriteria, 1, referencePlayer);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_BUY_BANK_SLOT:
                SetCriteriaProgress(achievementCriteria, referencePlayer->GetBankBagSlotCount(), referencePlayer);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_GAIN_REPUTATION:
            {
                int32 reputation = referencePlayer->GetReputationMgr().GetReputation(achievementCriteria->gain_reputation.factionID);
                if (reputation > 0)
                    SetCriteriaProgress(achievementCriteria, reputation, referencePlayer);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_GAIN_EXALTED_REPUTATION:
                SetCriteriaProgress(achievementCriteria, referencePlayer->GetReputationMgr().GetExaltedFactionCount(), referencePlayer);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILLLINE_SPELLS:
            {
                uint32 spellCount = 0;
                for (PlayerSpellMap::const_iterator spellIter = referencePlayer->GetSpellMap().begin();
                    spellIter != referencePlayer->GetSpellMap().end();
                    ++spellIter)
                {
                    SkillLineAbilityMapBounds bounds = sSpellMgr->GetSkillLineAbilityMapBounds(spellIter->first);
                    for (SkillLineAbilityMap::const_iterator skillIter = bounds.first; skillIter != bounds.second; ++skillIter)
                    {
                        if (skillIter->second->skillId == achievementCriteria->learn_skillline_spell.skillLine)
                            spellCount++;
                    }
                }
                SetCriteriaProgress(achievementCriteria, spellCount, referencePlayer);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_GAIN_REVERED_REPUTATION:
                SetCriteriaProgress(achievementCriteria, referencePlayer->GetReputationMgr().GetReveredFactionCount(), referencePlayer);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_GAIN_HONORED_REPUTATION:
                SetCriteriaProgress(achievementCriteria, referencePlayer->GetReputationMgr().GetHonoredFactionCount(), referencePlayer);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_KNOWN_FACTIONS:
                SetCriteriaProgress(achievementCriteria, referencePlayer->GetReputationMgr().GetVisibleFactionCount(), referencePlayer);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LINE:
            {
                uint32 spellCount = 0;
                for (PlayerSpellMap::const_iterator spellIter = referencePlayer->GetSpellMap().begin();
                    spellIter != referencePlayer->GetSpellMap().end();
                    ++spellIter)
                {
                    SkillLineAbilityMapBounds bounds = sSpellMgr->GetSkillLineAbilityMapBounds(spellIter->first);
                    for (SkillLineAbilityMap::const_iterator skillIter = bounds.first; skillIter != bounds.second; ++skillIter)
                        if (skillIter->second->skillId == achievementCriteria->learn_skill_line.skillLine)
                            spellCount++;
                }
                SetCriteriaProgress(achievementCriteria, spellCount, referencePlayer);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_EARN_HONORABLE_KILL:
                SetCriteriaProgress(achievementCriteria, referencePlayer->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS), referencePlayer);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_GOLD_VALUE_OWNED:
                SetCriteriaProgress(achievementCriteria, referencePlayer->GetMoney(), referencePlayer, PROGRESS_HIGHEST);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_EARN_ACHIEVEMENT_POINTS:
                if (!miscValue1)
                    SetCriteriaProgress(achievementCriteria, _achievementPoints, referencePlayer, PROGRESS_SET);
                else
                    SetCriteriaProgress(achievementCriteria, miscValue1, referencePlayer, PROGRESS_ACCUMULATE);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_TEAM_RATING:
            {
                uint32 reqTeamType = achievementCriteria->highest_team_rating.teamtype;

                if (miscValue1)
                {
                    if (miscValue2 != reqTeamType)
                        continue;

                    SetCriteriaProgress(achievementCriteria, miscValue1, referencePlayer, PROGRESS_HIGHEST);
                }
                else // login case
                {
                    for (uint32 arena_slot = 0; arena_slot < MAX_ARENA_SLOT; ++arena_slot)
                    {
                        uint32 teamId = referencePlayer->GetArenaTeamId(arena_slot);
                        if (!teamId)
                            continue;

                        ArenaTeam* team = sArenaTeamMgr->GetArenaTeamById(teamId);
                        if (!team || team->GetType() != reqTeamType)
                            continue;

                        SetCriteriaProgress(achievementCriteria, team->GetStats().Rating, referencePlayer, PROGRESS_HIGHEST);
                        break;
                    }
                }

                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_PERSONAL_RATING:
            {
                uint32 reqTeamType = achievementCriteria->highest_personal_rating.teamtype;

                if (miscValue1)
                {
                    if (miscValue2 != reqTeamType)
                        continue;

                    SetCriteriaProgress(achievementCriteria, miscValue1, referencePlayer, PROGRESS_HIGHEST);
                }
                else // login case
                {
                    for (uint32 arena_slot = 0; arena_slot < MAX_ARENA_SLOT; ++arena_slot)
                    {
                        uint32 teamId = referencePlayer->GetArenaTeamId(arena_slot);
                        if (!teamId)
                            continue;

                        ArenaTeam* team = sArenaTeamMgr->GetArenaTeamById(teamId);
                        if (!team || team->GetType() != reqTeamType)
                            continue;

                        if (ArenaTeamMember const* member = team->GetMember(referencePlayer->GetGUID()))
                        {
                            SetCriteriaProgress(achievementCriteria, member->PersonalRating, referencePlayer, PROGRESS_HIGHEST);
                            break;
                        }
                    }
                }

                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_REACH_GUILD_LEVEL:
                SetCriteriaProgress(achievementCriteria, miscValue1, referencePlayer);
                break;
            // FIXME: not triggered in code as result, need to implement
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_RAID:
            case ACHIEVEMENT_CRITERIA_TYPE_PLAY_ARENA:
            case ACHIEVEMENT_CRITERIA_TYPE_OWN_RANK:
            case ACHIEVEMENT_CRITERIA_TYPE_EARNED_PVP_TITLE:
            case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE_TYPE:
            case ACHIEVEMENT_CRITERIA_TYPE_SPENT_GOLD_GUILD_REPAIRS:
            case ACHIEVEMENT_CRITERIA_TYPE_CRAFT_ITEMS_GUILD:
            case ACHIEVEMENT_CRITERIA_TYPE_CATCH_FROM_POOL:
            case ACHIEVEMENT_CRITERIA_TYPE_BUY_GUILD_BANK_SLOTS:
            case ACHIEVEMENT_CRITERIA_TYPE_EARN_GUILD_ACHIEVEMENT_POINTS:
            case ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_BATTLEGROUND:
            case ACHIEVEMENT_CRITERIA_TYPE_REACH_BG_RATING:
            case ACHIEVEMENT_CRITERIA_TYPE_BUY_GUILD_TABARD:
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUESTS_GUILD:
            case ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILLS_GUILD:
            case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE_TYPE_GUILD:
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_ARCHAEOLOGY_PROJECTS:
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_GUILD_CHALLENGE_TYPE:
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_GUILD_CHALLENGE:
                break;                                   // Not implemented yet :(
        }

        if (IsCompletedCriteria(achievementCriteria, achievement))
            CompletedCriteriaFor(achievement, referencePlayer);

        // check again the completeness for SUMM and REQ COUNT achievements,
        // as they don't depend on the completed criteria but on the sum of the progress of each individual criteria
        if (achievement->flags & ACHIEVEMENT_FLAG_SUMM)
            if (IsCompletedAchievement(achievement))
                CompletedAchievement(achievement, referencePlayer);

        if (AchievementEntryList const* achRefList = sAchievementMgr->GetAchievementByReferencedId(achievement->ID))
            for (AchievementEntryList::const_iterator itr = achRefList->begin(); itr != achRefList->end(); ++itr)
                if (IsCompletedAchievement(*itr))
                    CompletedAchievement(*itr, referencePlayer);
    }
}

template<class T>
bool AchievementMgr<T>::IsCompletedCriteria(AchievementCriteriaEntry const* achievementCriteria, AchievementEntry const* achievement)
{
    if (!achievement)
        return false;

    // counter can never complete
    if (achievement->flags & ACHIEVEMENT_FLAG_COUNTER)
        return false;

    if (achievement->flags & (ACHIEVEMENT_FLAG_REALM_FIRST_REACH | ACHIEVEMENT_FLAG_REALM_FIRST_KILL))
    {
        // someone on this realm has already completed that achievement
        if (sAchievementMgr->IsRealmCompleted(achievement))
            return false;
    }

    CriteriaProgress const* progress = GetCriteriaProgress(achievementCriteria);
    if (!progress)
        return false;

    switch (AchievementCriteriaTypes(achievementCriteria->type))
    {
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_BG:
            return progress->counter >= achievementCriteria->win_bg.winCount;
        case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE:
            return progress->counter >= achievementCriteria->kill_creature.creatureCount;
        case ACHIEVEMENT_CRITERIA_TYPE_REACH_LEVEL:
        case ACHIEVEMENT_CRITERIA_TYPE_REACH_GUILD_LEVEL:
            return progress->counter >= achievementCriteria->reach_level.level;
        case ACHIEVEMENT_CRITERIA_TYPE_REACH_SKILL_LEVEL:
            return progress->counter >= achievementCriteria->reach_skill_level.skillLevel;
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_ACHIEVEMENT:
            return progress->counter >= 1;
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST_COUNT:
            return progress->counter >= achievementCriteria->complete_quest_count.totalQuestCount;
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST_DAILY:
            return progress->counter >= achievementCriteria->complete_daily_quest_daily.numberOfDays;
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUESTS_IN_ZONE:
            return progress->counter >= achievementCriteria->complete_quests_in_zone.questCount;
        case ACHIEVEMENT_CRITERIA_TYPE_DAMAGE_DONE:
        case ACHIEVEMENT_CRITERIA_TYPE_HEALING_DONE:
            return progress->counter >= achievementCriteria->healing_done.count;
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST:
            return progress->counter >= achievementCriteria->complete_daily_quest.questCount;
        case ACHIEVEMENT_CRITERIA_TYPE_FALL_WITHOUT_DYING:
            return progress->counter >= achievementCriteria->fall_without_dying.fallHeight;
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST:
            return progress->counter >= 1;
        case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET:
        case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2:
            return progress->counter >= achievementCriteria->be_spell_target.spellCount;
        case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL:
        case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL2:
            return progress->counter >= achievementCriteria->cast_spell.castCount;
        case ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE:
            return progress->counter >= achievementCriteria->bg_objective.completeCount;
        case ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL_AT_AREA:
            return progress->counter >= achievementCriteria->honorable_kill_at_area.killCount;
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SPELL:
            return progress->counter >= 1;
        case ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL:
        case ACHIEVEMENT_CRITERIA_TYPE_EARN_HONORABLE_KILL:
            return progress->counter >= achievementCriteria->honorable_kill.killCount;
        case ACHIEVEMENT_CRITERIA_TYPE_OWN_ITEM:
            return progress->counter >= achievementCriteria->own_item.itemCount;
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_ARENA:
            return progress->counter >= achievementCriteria->win_rated_arena.count;
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_PERSONAL_RATING:
            return progress->counter >= achievementCriteria->highest_personal_rating.PersonalRating;
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LEVEL:
            return progress->counter >= (achievementCriteria->learn_skill_level.skillLevel * 75);
        case ACHIEVEMENT_CRITERIA_TYPE_USE_ITEM:
            return progress->counter >= achievementCriteria->use_item.itemCount;
        case ACHIEVEMENT_CRITERIA_TYPE_LOOT_ITEM:
            return progress->counter >= achievementCriteria->loot_item.itemCount;
        case ACHIEVEMENT_CRITERIA_TYPE_EXPLORE_AREA:
            return progress->counter >= 1;
        case ACHIEVEMENT_CRITERIA_TYPE_BUY_BANK_SLOT:
            return progress->counter >= achievementCriteria->buy_bank_slot.numberOfSlots;
        case ACHIEVEMENT_CRITERIA_TYPE_GAIN_REPUTATION:
            return progress->counter >= achievementCriteria->gain_reputation.reputationAmount;
        case ACHIEVEMENT_CRITERIA_TYPE_GAIN_EXALTED_REPUTATION:
            return progress->counter >= achievementCriteria->gain_exalted_reputation.numberOfExaltedFactions;
        case ACHIEVEMENT_CRITERIA_TYPE_VISIT_BARBER_SHOP:
            return progress->counter >= achievementCriteria->visit_barber.numberOfVisits;
        case ACHIEVEMENT_CRITERIA_TYPE_EQUIP_EPIC_ITEM:
            return progress->counter >= achievementCriteria->equip_epic_item.count;
        case ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED_ON_LOOT:
        case ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED_ON_LOOT:
            return progress->counter >= achievementCriteria->roll_greed_on_loot.count;
        case ACHIEVEMENT_CRITERIA_TYPE_HK_CLASS:
            return progress->counter >= achievementCriteria->hk_class.count;
        case ACHIEVEMENT_CRITERIA_TYPE_HK_RACE:
            return progress->counter >= achievementCriteria->hk_race.count;
        case ACHIEVEMENT_CRITERIA_TYPE_DO_EMOTE:
            return progress->counter >= achievementCriteria->do_emote.count;
        case ACHIEVEMENT_CRITERIA_TYPE_EQUIP_ITEM:
            return progress->counter >= achievementCriteria->equip_item.count;
        case ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_QUEST_REWARD:
            return progress->counter >= achievementCriteria->quest_reward_money.goldInCopper;
        case ACHIEVEMENT_CRITERIA_TYPE_LOOT_MONEY:
            return progress->counter >= achievementCriteria->loot_money.goldInCopper;
        case ACHIEVEMENT_CRITERIA_TYPE_USE_GAMEOBJECT:
            return progress->counter >= achievementCriteria->use_gameobject.useCount;
        case ACHIEVEMENT_CRITERIA_TYPE_SPECIAL_PVP_KILL:
            return progress->counter >= achievementCriteria->special_pvp_kill.killCount;
        case ACHIEVEMENT_CRITERIA_TYPE_FISH_IN_GAMEOBJECT:
            return progress->counter >= achievementCriteria->fish_in_gameobject.lootCount;
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILLLINE_SPELLS:
            return progress->counter >= achievementCriteria->learn_skillline_spell.spellCount;
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_DUEL:
            return progress->counter >= achievementCriteria->win_duel.duelCount;
        case ACHIEVEMENT_CRITERIA_TYPE_LOOT_TYPE:
            return progress->counter >= achievementCriteria->loot_type.lootTypeCount;
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LINE:
            return progress->counter >= achievementCriteria->learn_skill_line.spellCount;
        case ACHIEVEMENT_CRITERIA_TYPE_EARN_ACHIEVEMENT_POINTS:
            return progress->counter >= 9000;
        case ACHIEVEMENT_CRITERIA_TYPE_USE_LFD_TO_GROUP_WITH_PLAYERS:
            return progress->counter >= achievementCriteria->use_lfg.dungeonsComplete;
        case ACHIEVEMENT_CRITERIA_TYPE_GET_KILLING_BLOWS:
            return progress->counter >= achievementCriteria->get_killing_blow.killCount;
        case ACHIEVEMENT_CRITERIA_TYPE_CURRENCY:
            return progress->counter >= achievementCriteria->currencyGain.count;
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_ARENA:
            return achievementCriteria->win_arena.count && progress->counter >= achievementCriteria->win_arena.count;
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
        case ACHIEVEMENT_CRITERIA_TYPE_QUEST_ABANDONED:
        case ACHIEVEMENT_CRITERIA_TYPE_FLIGHT_PATHS_TAKEN:
        case ACHIEVEMENT_CRITERIA_TYPE_ACCEPTED_SUMMONINGS:
        default:
            break;
    }

    return false;
}

template<class T>
void AchievementMgr<T>::CompletedCriteriaFor(AchievementEntry const* achievement, Player* referencePlayer)
{
    // counter can never complete
    if (achievement->flags & ACHIEVEMENT_FLAG_COUNTER)
        return;

    // already completed and stored
    if (HasAchieved(achievement->ID))
        return;

    if (IsCompletedAchievement(achievement))
        CompletedAchievement(achievement, referencePlayer);
}

template<class T>
bool AchievementMgr<T>::IsCompletedAchievement(AchievementEntry const* entry)
{
    // counter can never complete
    if (entry->flags & ACHIEVEMENT_FLAG_COUNTER)
        return false;

    // for achievement with referenced achievement criterias get from referenced and counter from self
    uint32 achievementForTestId = entry->refAchievement ? entry->refAchievement : entry->ID;
    uint32 achievementForTestCount = entry->count;

    AchievementCriteriaEntryList const* cList = sAchievementMgr->GetAchievementCriteriaByAchievement(achievementForTestId);
    if (!cList)
        return false;
    uint64 count = 0;

    // For SUMM achievements, we have to count the progress of each criteria of the achievement.
    // Oddly, the target count is NOT contained in the achievement, but in each individual criteria
    if (entry->flags & ACHIEVEMENT_FLAG_SUMM)
    {
        for (AchievementCriteriaEntryList::const_iterator itr = cList->begin(); itr != cList->end(); ++itr)
        {
            AchievementCriteriaEntry const* criteria = *itr;

            CriteriaProgress const* progress = GetCriteriaProgress(criteria);
            if (!progress)
                continue;

            count += progress->counter;

            // for counters, field4 contains the main count requirement
            if (count >= criteria->raw.count)
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
        if (achievementForTestCount > 0 && achievementForTestCount <= count)
           return true;
    }

    // all criterias completed requirement
    if (completed_all && achievementForTestCount == 0)
        return true;

    return false;
}

template<class T>
CriteriaProgress* AchievementMgr<T>::GetCriteriaProgress(AchievementCriteriaEntry const* entry)
{
    CriteriaProgressMap::iterator iter = m_criteriaProgress.find(entry->ID);

    if (iter == m_criteriaProgress.end())
        return NULL;

    return &(iter->second);
}

template<class T>
void AchievementMgr<T>::SetCriteriaProgress(AchievementCriteriaEntry const* entry, uint64 changeValue, Player* referencePlayer, ProgressType ptype)
{
    // Don't allow to cheat - doing timed achievements without timer active
    TimedAchievementMap::iterator timedIter = m_timedAchievements.find(entry->ID);
    if (entry->timeLimit && timedIter == m_timedAchievements.end())
        return;

    TC_LOG_DEBUG(LOG_FILTER_ACHIEVEMENTSYS, "SetCriteriaProgress(%u, " UI64FMTD ") for (%s GUID: %u)",
                   entry->ID, changeValue, GetLogNameForGuid(GetOwner()->GetGUID()), GUID_LOPART(GetOwner()->GetGUID()));

    CriteriaProgress* progress = GetCriteriaProgress(entry);
    if (!progress)
    {
        // not create record for 0 counter but allow it for timed achievements
        // we will need to send 0 progress to client to start the timer
        if (changeValue == 0 && !entry->timeLimit)
            return;

        progress = &m_criteriaProgress[entry->ID];
        progress->counter = changeValue;
    }
    else
    {
        uint64 newValue = 0;
        switch (ptype)
        {
            case PROGRESS_SET:
                newValue = changeValue;
                break;
            case PROGRESS_ACCUMULATE:
            {
                // avoid overflow
                uint64 max_value = std::numeric_limits<uint64>::max();
                newValue = max_value - progress->counter > changeValue ? progress->counter + changeValue : max_value;
                break;
            }
            case PROGRESS_HIGHEST:
                newValue = progress->counter < changeValue ? changeValue : progress->counter;
                break;
        }

        // not update (not mark as changed) if counter will have same value
        if (progress->counter == newValue && !entry->timeLimit)
            return;

        progress->counter = newValue;
    }

    progress->changed = true;
    progress->date = time(NULL); // set the date to the latest update.

    AchievementEntry const* achievement = sAchievementMgr->GetAchievement(entry->achievement);
    uint32 timeElapsed = 0;
    bool criteriaComplete = IsCompletedCriteria(entry, achievement);

    if (entry->timeLimit)
    {
        // Client expects this in packet
        timeElapsed = entry->timeLimit - (timedIter->second/IN_MILLISECONDS);

        // Remove the timer, we wont need it anymore
        if (criteriaComplete)
            m_timedAchievements.erase(timedIter);
    }

    if (criteriaComplete && achievement->flags & ACHIEVEMENT_FLAG_SHOW_CRITERIA_MEMBERS && !progress->CompletedGUID)
        progress->CompletedGUID = referencePlayer->GetGUID();

    SendCriteriaUpdate(entry, progress, timeElapsed, criteriaComplete);
}

template<class T>
void AchievementMgr<T>::UpdateTimedAchievements(uint32 timeDiff)
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

template<class T>
void AchievementMgr<T>::StartTimedAchievement(AchievementCriteriaTimedTypes /*type*/, uint32 /*entry*/, uint32 /*timeLost = 0*/)
{
}

template<>
void AchievementMgr<Player>::StartTimedAchievement(AchievementCriteriaTimedTypes type, uint32 entry, uint32 timeLost /* = 0 */)
{
    AchievementCriteriaEntryList const& achievementCriteriaList = sAchievementMgr->GetTimedAchievementCriteriaByType(type);
    for (AchievementCriteriaEntryList::const_iterator i = achievementCriteriaList.begin(); i != achievementCriteriaList.end(); ++i)
    {
        if ((*i)->timedCriteriaMiscId != entry)
            continue;

        AchievementEntry const* achievement = sAchievementMgr->GetAchievement((*i)->achievement);
        if (m_timedAchievements.find((*i)->ID) == m_timedAchievements.end() && !IsCompletedCriteria(*i, achievement))
        {
            // Start the timer
            if ((*i)->timeLimit * IN_MILLISECONDS > timeLost)
            {
                m_timedAchievements[(*i)->ID] = (*i)->timeLimit * IN_MILLISECONDS - timeLost;

                // and at client too
                SetCriteriaProgress(*i, 0, GetOwner(), PROGRESS_SET);
            }
        }
    }
}

template<class T>
void AchievementMgr<T>::RemoveTimedAchievement(AchievementCriteriaTimedTypes type, uint32 entry)
{
    AchievementCriteriaEntryList const& achievementCriteriaList = sAchievementMgr->GetTimedAchievementCriteriaByType(type);
    for (AchievementCriteriaEntryList::const_iterator i = achievementCriteriaList.begin(); i != achievementCriteriaList.end(); ++i)
    {
        if ((*i)->timedCriteriaMiscId != entry)
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

template<>
void AchievementMgr<Player>::CompletedAchievement(AchievementEntry const* achievement, Player* referencePlayer)
{
    // disable for gamemasters with GM-mode enabled
    if (GetOwner()->IsGameMaster())
        return;

    if (achievement->flags & ACHIEVEMENT_FLAG_COUNTER || HasAchieved(achievement->ID))
        return;

    if (achievement->flags & ACHIEVEMENT_FLAG_SHOW_IN_GUILD_NEWS)
        if (Guild* guild = referencePlayer->GetGuild())
            guild->AddGuildNews(GUILD_NEWS_PLAYER_ACHIEVEMENT, referencePlayer->GetGUID(), achievement->flags & ACHIEVEMENT_FLAG_SHOW_IN_GUILD_HEADER, achievement->ID);

    if (!GetOwner()->GetSession()->PlayerLoading())
        SendAchievementEarned(achievement);

    TC_LOG_INFO(LOG_FILTER_ACHIEVEMENTSYS, "AchievementMgr::CompletedAchievement(%u). Player: %s (%u)",
        achievement->ID, GetOwner()->GetName().c_str(), GetOwner()->GetGUIDLow());

    CompletedAchievementData& ca = m_completedAchievements[achievement->ID];
    ca.date = time(NULL);
    ca.changed = true;

    // don't insert for ACHIEVEMENT_FLAG_REALM_FIRST_KILL since otherwise only the first group member would reach that achievement
    /// @todo where do set this instead?
    if (!(achievement->flags & ACHIEVEMENT_FLAG_REALM_FIRST_KILL))
        sAchievementMgr->SetRealmCompleted(achievement);

    _achievementPoints += achievement->points;

    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_ACHIEVEMENT, 0, 0, 0, NULL, referencePlayer);
    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_EARN_ACHIEVEMENT_POINTS, achievement->points, 0, 0, NULL, referencePlayer);

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
    if (uint32 titleId = reward->titleId[achievement->ID == 1793 ? GetOwner()->getGender() : (GetOwner()->GetTeam() == ALLIANCE ? 0 : 1)])
        if (CharTitlesEntry const* titleEntry = sCharTitlesStore.LookupEntry(titleId))
            GetOwner()->SetTitle(titleEntry);

    // mail
    if (reward->sender)
    {
        Item* item = reward->itemId ? Item::CreateItem(reward->itemId, 1, GetOwner()) : NULL;

        int loc_idx = GetOwner()->GetSession()->GetSessionDbLocaleIndex();

        // subject and text
        std::string subject = reward->subject;
        std::string text = reward->text;
        if (loc_idx >= 0)
        {
            if (AchievementRewardLocale const* loc = sAchievementMgr->GetAchievementRewardLocale(achievement))
            {
                ObjectMgr::GetLocaleString(loc->subject, loc_idx, subject);
                ObjectMgr::GetLocaleString(loc->text, loc_idx, text);
            }
        }

        MailDraft draft(subject, text);

        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        if (item)
        {
            // save new item before send
            item->SaveToDB(trans);                               // save for prevent lost at next mail load, if send fail then item will deleted

            // item
            draft.AddItem(item);
        }

        draft.SendMailTo(trans, GetOwner(), MailSender(MAIL_CREATURE, reward->sender));
        CharacterDatabase.CommitTransaction(trans);
    }
}

template<>
void AchievementMgr<Guild>::CompletedAchievement(AchievementEntry const* achievement, Player* referencePlayer)
{
    TC_LOG_DEBUG(LOG_FILTER_ACHIEVEMENTSYS, "AchievementMgr<Guild>::CompletedAchievement(%u)", achievement->ID);

    if (achievement->flags & ACHIEVEMENT_FLAG_COUNTER || HasAchieved(achievement->ID))
        return;

    if (achievement->flags & ACHIEVEMENT_FLAG_SHOW_IN_GUILD_NEWS)
        if (Guild* guild = referencePlayer->GetGuild())
            guild->AddGuildNews(GUILD_NEWS_GUILD_ACHIEVEMENT, 0, achievement->flags & ACHIEVEMENT_FLAG_SHOW_IN_GUILD_HEADER, achievement->ID);

    SendAchievementEarned(achievement);
    CompletedAchievementData& ca = m_completedAchievements[achievement->ID];
    ca.date = time(NULL);
    ca.changed = true;

    if (achievement->flags & ACHIEVEMENT_FLAG_SHOW_GUILD_MEMBERS)
    {
        if (referencePlayer->GetGuildId() == GetOwner()->GetId())
            ca.guids.insert(referencePlayer->GetGUID());

        if (Group const* group = referencePlayer->GetGroup())
            for (GroupReference const* ref = group->GetFirstMember(); ref != NULL; ref = ref->next())
                if (Player const* groupMember = ref->GetSource())
                    if (groupMember->GetGuildId() == GetOwner()->GetId())
                        ca.guids.insert(groupMember->GetGUID());
    }

    sAchievementMgr->SetRealmCompleted(achievement);

    _achievementPoints += achievement->points;

    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_ACHIEVEMENT, 0, 0, 0, NULL, referencePlayer);
    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_EARN_ACHIEVEMENT_POINTS, achievement->points, 0, 0, NULL, referencePlayer);
}

struct VisibleAchievementPred
{
    bool operator()(CompletedAchievementMap::value_type const& val)
    {
        AchievementEntry const* achievement = sAchievementMgr->GetAchievement(val.first);
        return achievement && !(achievement->flags & ACHIEVEMENT_FLAG_HIDDEN);
    }
};

template<class T>
void AchievementMgr<T>::SendAllAchievementData(Player* /*receiver*/) const
{
    VisibleAchievementPred isVisible;
    size_t numCriteria = m_criteriaProgress.size();
    size_t numAchievements = std::count_if(m_completedAchievements.begin(), m_completedAchievements.end(), isVisible);
    ByteBuffer criteriaData(numCriteria * (4 + 4 + 4 + 4 + 8 + 8));
    ObjectGuid guid = GetOwner()->GetGUID();
    ObjectGuid counter;

    WorldPacket data(SMSG_ALL_ACHIEVEMENT_DATA, 4 + numAchievements * (4 + 4) + 4 + numCriteria * (4 + 4 + 4 + 4 + 8 + 8));
    data.WriteBits(numCriteria, 21);
    for (CriteriaProgressMap::const_iterator itr = m_criteriaProgress.begin(); itr != m_criteriaProgress.end(); ++itr)
    {
        counter = itr->second.counter;

        data.WriteBit(guid[4]);
        data.WriteBit(counter[3]);
        data.WriteBit(guid[5]);
        data.WriteBit(counter[0]);
        data.WriteBit(counter[6]);
        data.WriteBit(guid[3]);
        data.WriteBit(guid[0]);
        data.WriteBit(counter[4]);
        data.WriteBit(guid[2]);
        data.WriteBit(counter[7]);
        data.WriteBit(guid[7]);
        data.WriteBits(0u, 2);
        data.WriteBit(guid[6]);
        data.WriteBit(counter[2]);
        data.WriteBit(counter[1]);
        data.WriteBit(counter[5]);
        data.WriteBit(guid[1]);

        criteriaData.WriteByteSeq(guid[3]);
        criteriaData.WriteByteSeq(counter[5]);
        criteriaData.WriteByteSeq(counter[6]);
        criteriaData.WriteByteSeq(guid[4]);
        criteriaData.WriteByteSeq(guid[6]);
        criteriaData.WriteByteSeq(counter[2]);
        criteriaData << uint32(0); // timer 2
        criteriaData.WriteByteSeq(guid[2]);
        criteriaData << uint32(itr->first); // criteria id
        criteriaData.WriteByteSeq(guid[5]);
        criteriaData.WriteByteSeq(counter[0]);
        criteriaData.WriteByteSeq(counter[3]);
        criteriaData.WriteByteSeq(counter[1]);
        criteriaData.WriteByteSeq(counter[4]);
        criteriaData.WriteByteSeq(guid[0]);
        criteriaData.WriteByteSeq(guid[7]);
        criteriaData.WriteByteSeq(counter[7]);
        criteriaData << uint32(0); // timer 1
        criteriaData.AppendPackedTime(itr->second.date);  // criteria date
        criteriaData.WriteByteSeq(guid[1]);
    }

    data.WriteBits(numAchievements, 23);
    data.FlushBits();
    data.append(criteriaData);

    for (CompletedAchievementMap::const_iterator itr = m_completedAchievements.begin(); itr != m_completedAchievements.end(); ++itr)
    {
        if (!isVisible(*itr))
            continue;

        data << uint32(itr->first);
        data.AppendPackedTime(itr->second.date);
    }

    SendPacket(&data);
}

template<>
void AchievementMgr<Guild>::SendAllAchievementData(Player* receiver) const
{
    VisibleAchievementPred isVisible;
    WorldPacket data(SMSG_GUILD_ACHIEVEMENT_DATA, m_completedAchievements.size() * (4 + 4) + 3);
    data.WriteBits(std::count_if(m_completedAchievements.begin(), m_completedAchievements.end(), isVisible), 23);
    for (CompletedAchievementMap::const_iterator itr = m_completedAchievements.begin(); itr != m_completedAchievements.end(); ++itr)
    {
        if (!isVisible(*itr))
            continue;

        data.AppendPackedTime(itr->second.date);
        data << uint32(itr->first);
    }

    receiver->GetSession()->SendPacket(&data);
}

template<>
void AchievementMgr<Player>::SendAchievementInfo(Player* receiver, uint32 /*achievementId = 0 */) const
{
    ObjectGuid guid = GetOwner()->GetGUID();
    ObjectGuid counter;

    VisibleAchievementPred isVisible;
    size_t numCriteria = m_criteriaProgress.size();
    size_t numAchievements = std::count_if(m_completedAchievements.begin(), m_completedAchievements.end(), isVisible);
    ByteBuffer criteriaData(numCriteria * 16);

    WorldPacket data(SMSG_RESPOND_INSPECT_ACHIEVEMENTS, 1 + 8 + 3 + 3 + numAchievements * (4 + 4) + numCriteria * (0));
    data.WriteBit(guid[7]);
    data.WriteBit(guid[4]);
    data.WriteBit(guid[1]);
    data.WriteBits(numAchievements, 23);
    data.WriteBit(guid[0]);
    data.WriteBit(guid[3]);
    data.WriteBits(numCriteria, 21);
    data.WriteBit(guid[2]);
    for (CriteriaProgressMap::const_iterator itr = m_criteriaProgress.begin(); itr != m_criteriaProgress.end(); ++itr)
    {
        counter = itr->second.counter;

        data.WriteBit(counter[5]);
        data.WriteBit(counter[3]);
        data.WriteBit(guid[1]);
        data.WriteBit(guid[4]);
        data.WriteBit(guid[2]);
        data.WriteBit(counter[6]);
        data.WriteBit(guid[0]);
        data.WriteBit(counter[4]);
        data.WriteBit(counter[1]);
        data.WriteBit(counter[2]);
        data.WriteBit(guid[3]);
        data.WriteBit(guid[7]);
        data.WriteBits(0, 2);           // criteria progress flags
        data.WriteBit(counter[0]);
        data.WriteBit(guid[5]);
        data.WriteBit(guid[6]);
        data.WriteBit(counter[7]);

        criteriaData.WriteByteSeq(guid[3]);
        criteriaData.WriteByteSeq(counter[4]);
        criteriaData << uint32(0);      // timer 1
        criteriaData.WriteByteSeq(guid[1]);
        criteriaData.AppendPackedTime(itr->second.date);
        criteriaData.WriteByteSeq(counter[3]);
        criteriaData.WriteByteSeq(counter[7]);
        criteriaData.WriteByteSeq(guid[5]);
        criteriaData.WriteByteSeq(counter[0]);
        criteriaData.WriteByteSeq(guid[4]);
        criteriaData.WriteByteSeq(guid[2]);
        criteriaData.WriteByteSeq(guid[6]);
        criteriaData.WriteByteSeq(guid[7]);
        criteriaData.WriteByteSeq(counter[6]);
        criteriaData << uint32(itr->first);
        criteriaData << uint32(0);      // timer 2
        criteriaData.WriteByteSeq(counter[1]);
        criteriaData.WriteByteSeq(counter[5]);
        criteriaData.WriteByteSeq(guid[0]);
        criteriaData.WriteByteSeq(counter[2]);
    }

    data.WriteBit(guid[6]);
    data.WriteBit(guid[5]);
    data.FlushBits();
    data.append(criteriaData);
    data.WriteByteSeq(guid[1]);
    data.WriteByteSeq(guid[6]);
    data.WriteByteSeq(guid[3]);
    data.WriteByteSeq(guid[0]);
    data.WriteByteSeq(guid[2]);

    for (CompletedAchievementMap::const_iterator itr = m_completedAchievements.begin(); itr != m_completedAchievements.end(); ++itr)
    {
        if (!isVisible(*itr))
            continue;

        data << uint32(itr->first);
        data.AppendPackedTime(itr->second.date);
    }

    data.WriteByteSeq(guid[7]);
    data.WriteByteSeq(guid[4]);
    data.WriteByteSeq(guid[5]);

    receiver->GetSession()->SendPacket(&data);
}

template<>
void AchievementMgr<Guild>::SendAchievementInfo(Player* receiver, uint32 achievementId /*= 0*/) const
{
    //will send response to criteria progress request
    AchievementCriteriaEntryList const* criteria = sAchievementMgr->GetAchievementCriteriaByAchievement(achievementId);
    if (!criteria)
    {
        // send empty packet
        WorldPacket data(SMSG_GUILD_CRITERIA_DATA, 3);
        data.WriteBits(0, 21);
        receiver->GetSession()->SendPacket(&data);
        return;
    }

    ObjectGuid counter;
    ObjectGuid guid;
    uint32 numCriteria = 0;
    ByteBuffer criteriaData(criteria->size() * (8 + 8 + 4 + 4 + 4));
    ByteBuffer criteriaBits(criteria->size() * (8 + 8) / 8);
    for (AchievementCriteriaEntryList::const_iterator itr = criteria->begin(); itr != criteria->end(); ++itr)
    {
        uint32 criteriaId = (*itr)->ID;
        CriteriaProgressMap::const_iterator progress = m_criteriaProgress.find(criteriaId);
        if (progress == m_criteriaProgress.end())
            continue;

        ++numCriteria;
    }

    criteriaBits.WriteBits(numCriteria, 21);

    for (AchievementCriteriaEntryList::const_iterator itr = criteria->begin(); itr != criteria->end(); ++itr)
    {
        uint32 criteriaId = (*itr)->ID;
        CriteriaProgressMap::const_iterator progress = m_criteriaProgress.find(criteriaId);
        if (progress == m_criteriaProgress.end())
            continue;

        counter = progress->second.counter;
        guid = progress->second.CompletedGUID;

        criteriaBits.WriteBit(counter[4]);
        criteriaBits.WriteBit(counter[1]);
        criteriaBits.WriteBit(guid[2]);
        criteriaBits.WriteBit(counter[3]);
        criteriaBits.WriteBit(guid[1]);
        criteriaBits.WriteBit(counter[5]);
        criteriaBits.WriteBit(counter[0]);
        criteriaBits.WriteBit(guid[3]);
        criteriaBits.WriteBit(counter[2]);
        criteriaBits.WriteBit(guid[7]);
        criteriaBits.WriteBit(guid[5]);
        criteriaBits.WriteBit(guid[0]);
        criteriaBits.WriteBit(counter[6]);
        criteriaBits.WriteBit(guid[6]);
        criteriaBits.WriteBit(counter[7]);
        criteriaBits.WriteBit(guid[4]);

        criteriaData.WriteByteSeq(guid[5]);
        criteriaData << uint32(progress->second.date);      // unknown date
        criteriaData.WriteByteSeq(counter[3]);
        criteriaData.WriteByteSeq(counter[7]);
        criteriaData << uint32(progress->second.date);      // unknown date
        criteriaData.WriteByteSeq(counter[6]);
        criteriaData.WriteByteSeq(guid[4]);
        criteriaData.WriteByteSeq(guid[1]);
        criteriaData.WriteByteSeq(counter[4]);
        criteriaData.WriteByteSeq(guid[3]);
        criteriaData.WriteByteSeq(counter[0]);
        criteriaData.WriteByteSeq(guid[2]);
        criteriaData.WriteByteSeq(counter[1]);
        criteriaData.WriteByteSeq(guid[6]);
        criteriaData << uint32(progress->second.date);      // last update time (not packed!)
        criteriaData << uint32(criteriaId);
        criteriaData.WriteByteSeq(counter[5]);
        criteriaData << uint32(0);
        criteriaData.WriteByteSeq(guid[7]);
        criteriaData.WriteByteSeq(counter[2]);
        criteriaData.WriteByteSeq(guid[0]);
    }

    WorldPacket data(SMSG_GUILD_CRITERIA_DATA, criteriaBits.size() + criteriaData.size());
    data.append(criteriaBits);
    if (numCriteria)
        data.append(criteriaData);

    receiver->GetSession()->SendPacket(&data);
}

template<class T>
bool AchievementMgr<T>::HasAchieved(uint32 achievementId) const
{
    return m_completedAchievements.find(achievementId) != m_completedAchievements.end();
}

template<class T>
bool AchievementMgr<T>::CanUpdateCriteria(AchievementCriteriaEntry const* criteria, AchievementEntry const* achievement, uint64 miscValue1, uint64 miscValue2, uint64 miscValue3, Unit const* unit, Player* referencePlayer)
{
    if (DisableMgr::IsDisabledFor(DISABLE_TYPE_ACHIEVEMENT_CRITERIA, criteria->ID, NULL))
    {
        TC_LOG_TRACE(LOG_FILTER_ACHIEVEMENTSYS, "CanUpdateCriteria: %s (Id: %u Type %s) Disabled",
            criteria->name, criteria->ID, AchievementGlobalMgr::GetCriteriaTypeString(criteria->type));
        return false;
    }

    if (achievement->mapID != -1 && referencePlayer->GetMapId() != uint32(achievement->mapID))
    {
        TC_LOG_TRACE(LOG_FILTER_ACHIEVEMENTSYS, "CanUpdateCriteria: %s (Id: %u Type %s) Wrong map",
            criteria->name, criteria->ID, AchievementGlobalMgr::GetCriteriaTypeString(criteria->type));
        return false;
    }

    if ((achievement->requiredFaction == ACHIEVEMENT_FACTION_HORDE    && referencePlayer->GetTeam() != HORDE) ||
        (achievement->requiredFaction == ACHIEVEMENT_FACTION_ALLIANCE && referencePlayer->GetTeam() != ALLIANCE))
    {
        TC_LOG_TRACE(LOG_FILTER_ACHIEVEMENTSYS, "CanUpdateCriteria: %s (Id: %u Type %s) Wrong faction",
            criteria->name, criteria->ID, AchievementGlobalMgr::GetCriteriaTypeString(criteria->type));
        return false;
    }

    if (IsCompletedCriteria(criteria, achievement))
    {
        TC_LOG_TRACE(LOG_FILTER_ACHIEVEMENTSYS, "CanUpdateCriteria: %s (Id: %u Type %s) Is Completed",
            criteria->name, criteria->ID, AchievementGlobalMgr::GetCriteriaTypeString(criteria->type));
        return false;
    }

    if (!RequirementsSatisfied(criteria, miscValue1, miscValue2, miscValue3, unit, referencePlayer))
    {
        TC_LOG_TRACE(LOG_FILTER_ACHIEVEMENTSYS, "CanUpdateCriteria: %s (Id: %u Type %s) Requirements not satisfied",
            criteria->name, criteria->ID, AchievementGlobalMgr::GetCriteriaTypeString(criteria->type));
        return false;
    }

    if (!AdditionalRequirementsSatisfied(criteria, miscValue1, miscValue2, unit, referencePlayer))
    {
        TC_LOG_TRACE(LOG_FILTER_ACHIEVEMENTSYS, "CanUpdateCriteria: %s (Id: %u Type %s) Additional requirements not satisfied",
            criteria->name, criteria->ID, AchievementGlobalMgr::GetCriteriaTypeString(criteria->type));
        return false;
    }

    if (!ConditionsSatisfied(criteria, referencePlayer))
    {
        TC_LOG_TRACE(LOG_FILTER_ACHIEVEMENTSYS, "CanUpdateCriteria: %s (Id: %u Type %s) Conditions not satisfied",
            criteria->name, criteria->ID, AchievementGlobalMgr::GetCriteriaTypeString(criteria->type));
        return false;
    }

    return true;
}

template<class T>
bool AchievementMgr<T>::ConditionsSatisfied(AchievementCriteriaEntry const* criteria, Player* referencePlayer) const
{
    for (uint32 i = 0; i < MAX_CRITERIA_REQUIREMENTS; ++i)
    {
        if (!criteria->additionalRequirements[i].additionalRequirement_type)
            continue;

        switch (criteria->additionalRequirements[i].additionalRequirement_type)
        {
            case ACHIEVEMENT_CRITERIA_CONDITION_BG_MAP:
                if (referencePlayer->GetMapId() != criteria->additionalRequirements[i].additionalRequirement_value)
                    return false;
                break;
            case ACHIEVEMENT_CRITERIA_CONDITION_NOT_IN_GROUP:
                if (referencePlayer->GetGroup())
                    return false;
                break;
            default:
                break;
        }
    }

    return true;
}

template<class T>
bool AchievementMgr<T>::RequirementsSatisfied(AchievementCriteriaEntry const* achievementCriteria, uint64 miscValue1, uint64 miscValue2, uint64 miscValue3, Unit const* unit, Player* referencePlayer) const
{
    switch (AchievementCriteriaTypes(achievementCriteria->type))
    {
        case ACHIEVEMENT_CRITERIA_TYPE_ACCEPTED_SUMMONINGS:
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST:
        case ACHIEVEMENT_CRITERIA_TYPE_CREATE_AUCTION:
        case ACHIEVEMENT_CRITERIA_TYPE_FALL_WITHOUT_DYING:
        case ACHIEVEMENT_CRITERIA_TYPE_FLIGHT_PATHS_TAKEN:
        case ACHIEVEMENT_CRITERIA_TYPE_GET_KILLING_BLOWS:
        case ACHIEVEMENT_CRITERIA_TYPE_GOLD_EARNED_BY_AUCTIONS:
        case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_AT_BARBER:
        case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_MAIL:
        case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_TALENTS:
        case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_TRAVELLING:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_AUCTION_BID:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_AUCTION_SOLD:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEALING_RECEIVED:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEAL_CASTED:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HIT_DEALT:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HIT_RECEIVED:
        case ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL:
        case ACHIEVEMENT_CRITERIA_TYPE_LOOT_MONEY:
        case ACHIEVEMENT_CRITERIA_TYPE_LOSE_DUEL:
        case ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_QUEST_REWARD:
        case ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_VENDORS:
        case ACHIEVEMENT_CRITERIA_TYPE_NUMBER_OF_TALENT_RESETS:
        case ACHIEVEMENT_CRITERIA_TYPE_QUEST_ABANDONED:
        case ACHIEVEMENT_CRITERIA_TYPE_REACH_GUILD_LEVEL:
        case ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED:
        case ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED:
        case ACHIEVEMENT_CRITERIA_TYPE_SPECIAL_PVP_KILL:
        case ACHIEVEMENT_CRITERIA_TYPE_TOTAL_DAMAGE_RECEIVED:
        case ACHIEVEMENT_CRITERIA_TYPE_TOTAL_HEALING_RECEIVED:
        case ACHIEVEMENT_CRITERIA_TYPE_USE_LFD_TO_GROUP_WITH_PLAYERS:
        case ACHIEVEMENT_CRITERIA_TYPE_VISIT_BARBER_SHOP:
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_DUEL:
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_ARENA:
        case ACHIEVEMENT_CRITERIA_TYPE_WON_AUCTIONS:
            if (!miscValue1)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_BUY_BANK_SLOT:
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST_DAILY:
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST_COUNT:
        case ACHIEVEMENT_CRITERIA_TYPE_EARNED_PVP_TITLE:
        case ACHIEVEMENT_CRITERIA_TYPE_EARN_ACHIEVEMENT_POINTS:
        case ACHIEVEMENT_CRITERIA_TYPE_GAIN_EXALTED_REPUTATION:
        case ACHIEVEMENT_CRITERIA_TYPE_GAIN_HONORED_REPUTATION:
        case ACHIEVEMENT_CRITERIA_TYPE_GAIN_REVERED_REPUTATION:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_GOLD_VALUE_OWNED:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_PERSONAL_RATING:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_TEAM_RATING:
        case ACHIEVEMENT_CRITERIA_TYPE_KNOWN_FACTIONS:
        case ACHIEVEMENT_CRITERIA_TYPE_REACH_LEVEL:
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_ACHIEVEMENT:
            if (m_completedAchievements.find(achievementCriteria->complete_achievement.linkedAchievement) == m_completedAchievements.end())
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_BG:
            if (!miscValue1 || achievementCriteria->win_bg.bgMapID != referencePlayer->GetMapId())
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE:
            if (!miscValue1 || achievementCriteria->kill_creature.creatureID != miscValue1)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_REACH_SKILL_LEVEL:
            // update at loading or specific skill update
            if (miscValue1 && miscValue1 != achievementCriteria->reach_skill_level.skillID)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LEVEL:
            // update at loading or specific skill update
            if (miscValue1 && miscValue1 != achievementCriteria->learn_skill_level.skillID)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUESTS_IN_ZONE:
            if (miscValue1 && miscValue1 != achievementCriteria->complete_quests_in_zone.zoneID)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_BATTLEGROUND:
            if (!miscValue1 || referencePlayer->GetMapId() != achievementCriteria->complete_battleground.mapID)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_DEATH_AT_MAP:
            if (!miscValue1 || referencePlayer->GetMapId() != achievementCriteria->death_at_map.mapID)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_DEATH:
        {
            if (!miscValue1)
                return false;
            // skip wrong arena achievements, if not achievIdByArenaSlot then normal total death counter
            bool notfit = false;
            for (int j = 0; j < MAX_ARENA_SLOT; ++j)
            {
                if (achievIdByArenaSlot[j] == achievementCriteria->achievement)
                {
                    Battleground* bg = referencePlayer->GetBattleground();
                    if (!bg || !bg->isArena() || ArenaTeam::GetSlotByType(bg->GetArenaType()) != j)
                        notfit = true;
                    break;
                }
            }
            if (notfit)
                return false;
            break;
        }
        case ACHIEVEMENT_CRITERIA_TYPE_DEATH_IN_DUNGEON:
        {
            if (!miscValue1)
                return false;

            Map const* map = referencePlayer->IsInWorld() ? referencePlayer->GetMap() : sMapMgr->FindMap(referencePlayer->GetMapId(), referencePlayer->GetInstanceId());
            if (!map || !map->IsDungeon())
                return false;

            // search case
            bool found = false;
            for (int j = 0; achievIdForDungeon[j][0]; ++j)
            {
                if (achievIdForDungeon[j][0] == achievementCriteria->achievement)
                {
                    if (map->IsRaid())
                    {
                        // if raid accepted (ignore difficulty)
                        if (!achievIdForDungeon[j][2])
                            break;                      // for
                    }
                    else if (referencePlayer->GetDungeonDifficulty() == DUNGEON_DIFFICULTY_NORMAL)
                    {
                        // dungeon in normal mode accepted
                        if (!achievIdForDungeon[j][1])
                            break;                      // for
                    }
                    else
                    {
                        // dungeon in heroic mode accepted
                        if (!achievIdForDungeon[j][3])
                            break;                      // for
                    }

                    found = true;
                    break;                              // for
                }
            }
            if (!found)
                return false;

            //FIXME: work only for instances where max == min for players
            if (((InstanceMap*)map)->GetMaxPlayers() != achievementCriteria->death_in_dungeon.manLimit)
                return false;
            break;
        }
        case ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_CREATURE:
            if (!miscValue1 || miscValue1 != achievementCriteria->killed_by_creature.creatureEntry)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_PLAYER:
            if (!miscValue1 || !unit || unit->GetTypeId() != TYPEID_PLAYER)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_DEATHS_FROM:
            if (!miscValue1 || miscValue2 != achievementCriteria->death_from.type)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST:
        {
            // if miscValues != 0, it contains the questID.
            if (miscValue1)
            {
                if (miscValue1 != achievementCriteria->complete_quest.questID)
                    return false;
            }
            else
            {
                // login case.
                if (!referencePlayer->GetQuestRewardStatus(achievementCriteria->complete_quest.questID))
                    return false;
            }

            if (AchievementCriteriaDataSet const* data = sAchievementMgr->GetCriteriaDataSet(achievementCriteria))
                if (!data->Meets(referencePlayer, unit))
                    return false;
            break;
        }
        case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET:
        case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2:
            if (!miscValue1 || miscValue1 != achievementCriteria->be_spell_target.spellID)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL:
        case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL2:
            if (!miscValue1 || miscValue1 != achievementCriteria->cast_spell.spellID)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SPELL:
            if (miscValue1 && miscValue1 != achievementCriteria->learn_spell.spellID)
                return false;

            if (!referencePlayer->HasSpell(achievementCriteria->learn_spell.spellID))
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_LOOT_TYPE:
            // miscValue1 = itemId - miscValue2 = count of item loot
            // miscValue3 = loot_type (note: 0 = LOOT_CORPSE and then it ignored)
            if (!miscValue1 || !miscValue2 || !miscValue3 || miscValue3 != achievementCriteria->loot_type.lootType)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_OWN_ITEM:
            if (miscValue1 && achievementCriteria->own_item.itemID != miscValue1)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_USE_ITEM:
            if (!miscValue1 || achievementCriteria->use_item.itemID != miscValue1)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_LOOT_ITEM:
            if (!miscValue1 || miscValue1 != achievementCriteria->own_item.itemID)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_EXPLORE_AREA:
        {
            WorldMapOverlayEntry const* worldOverlayEntry = sWorldMapOverlayStore.LookupEntry(achievementCriteria->explore_area.areaReference);
            if (!worldOverlayEntry)
                break;

            bool matchFound = false;
            for (int j = 0; j < MAX_WORLD_MAP_OVERLAY_AREA_IDX; ++j)
            {
                uint32 area_id = worldOverlayEntry->areatableID[j];
                if (!area_id)                            // array have 0 only in empty tail
                    break;

                int32 exploreFlag = GetAreaFlagByAreaID(area_id);
                if (exploreFlag < 0)
                    continue;

                uint32 playerIndexOffset = uint32(exploreFlag) / 32;
                uint32 mask = 1 << (uint32(exploreFlag) % 32);

                if (referencePlayer->GetUInt32Value(PLAYER_EXPLORED_ZONES_1 + playerIndexOffset) & mask)
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
            if (miscValue1 && miscValue1 != achievementCriteria->gain_reputation.factionID)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_EQUIP_EPIC_ITEM:
            // miscValue1 = itemid miscValue2 = itemSlot
            if (!miscValue1 || miscValue2 != achievementCriteria->equip_epic_item.itemSlot)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED_ON_LOOT:
        case ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED_ON_LOOT:
        {
            // miscValue1 = itemid miscValue2 = diced value
            if (!miscValue1 || miscValue2 != achievementCriteria->roll_greed_on_loot.rollValue)
                return false;

            ItemTemplate const* proto = sObjectMgr->GetItemTemplate(uint32(miscValue1));
            if (!proto)
                return false;
            break;
        }
        case ACHIEVEMENT_CRITERIA_TYPE_DO_EMOTE:
            if (!miscValue1 || miscValue1 != achievementCriteria->do_emote.emoteID)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_DAMAGE_DONE:
        case ACHIEVEMENT_CRITERIA_TYPE_HEALING_DONE:
            if (!miscValue1)
                return false;

            if (achievementCriteria->additionalRequirements[0].additionalRequirement_type == ACHIEVEMENT_CRITERIA_CONDITION_BG_MAP)
            {
                if (referencePlayer->GetMapId() != achievementCriteria->additionalRequirements[0].additionalRequirement_value)
                    return false;

                // map specific case (BG in fact) expected player targeted damage/heal
                if (!unit || unit->GetTypeId() != TYPEID_PLAYER)
                    return false;
            }
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_EQUIP_ITEM:
            // miscValue1 = item_id
            if (!miscValue1 || miscValue1 != achievementCriteria->equip_item.itemID)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_USE_GAMEOBJECT:
            if (!miscValue1 || miscValue1 != achievementCriteria->use_gameobject.goEntry)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_FISH_IN_GAMEOBJECT:
            if (!miscValue1 || miscValue1 != achievementCriteria->fish_in_gameobject.goEntry)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILLLINE_SPELLS:
            if (miscValue1 && miscValue1 != achievementCriteria->learn_skillline_spell.skillLine)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_LOOT_EPIC_ITEM:
        case ACHIEVEMENT_CRITERIA_TYPE_RECEIVE_EPIC_ITEM:
        {
            if (!miscValue1)
                return false;
            ItemTemplate const* proto = sObjectMgr->GetItemTemplate(uint32(miscValue1));
            if (!proto || proto->Quality < ITEM_QUALITY_EPIC)
                return false;
            break;
        }
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LINE:
            if (miscValue1 && miscValue1 != achievementCriteria->learn_skill_line.skillLine)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_HK_CLASS:
            if (!miscValue1 || miscValue1 != achievementCriteria->hk_class.classID)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_HK_RACE:
            if (!miscValue1 || miscValue1 != achievementCriteria->hk_race.raceID)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE:
            if (!miscValue1 || miscValue1 != achievementCriteria->bg_objective.objectiveId)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL_AT_AREA:
            if (!miscValue1 || miscValue1 != achievementCriteria->honorable_kill_at_area.areaID)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_CURRENCY:
            if (!miscValue1 || !miscValue2 || int64(miscValue2) < 0
                || miscValue1 != achievementCriteria->currencyGain.currency)
                return false;
            break;
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_ARENA:
            if (miscValue1 != achievementCriteria->win_arena.mapID)
                return false;
            break;
        default:
            break;
    }
    return true;
}

template<class T>
bool AchievementMgr<T>::AdditionalRequirementsSatisfied(AchievementCriteriaEntry const* criteria, uint64 miscValue1, uint64 /*miscValue2*/, Unit const* unit, Player* referencePlayer) const
{
    for (uint8 i = 0; i < MAX_ADDITIONAL_CRITERIA_CONDITIONS; ++i)
    {
        uint32 reqType = criteria->additionalConditionType[i];

        ///@TODO Extract additionalConditionValue[2] column from an older dbc and store it in database
        ///      This column is not present in 4.3.4 Achievement_Criteria.dbc
        ///      so for now, just return as failed condition to prevent invalid memory access
        if (i == 2 && reqType)
            return false;

        uint32 reqValue = criteria->additionalConditionValue[i];

        switch (AchievementCriteriaAdditionalCondition(reqType))
        {
            case ACHIEVEMENT_CRITERIA_ADDITIONAL_CONDITION_TARGET_CREATURE_ENTRY: // 4
                if (!unit || unit->GetEntry() != reqValue)
                    return false;
                break;
            case ACHIEVEMENT_CRITERIA_ADDITIONAL_CONDITION_TARGET_MUST_BE_PLAYER: // 5
                if (!unit || unit->GetTypeId() != TYPEID_PLAYER)
                    return false;
                break;
            case ACHIEVEMENT_CRITERIA_ADDITIONAL_CONDITION_TARGET_MUST_BE_DEAD: // 6
                if (!unit || unit->IsAlive())
                    return false;
                break;
            case ACHIEVEMENT_CRITERIA_ADDITIONAL_CONDITION_TARGET_MUST_BE_ENEMY: // 7
                if (!unit || !referencePlayer->IsHostileTo(unit))
                    return false;
                break;
            case ACHIEVEMENT_CRITERIA_ADDITIONAL_CONDITION_SOURCE_HAS_AURA: // 8
                if (!referencePlayer->HasAura(reqValue))
                    return false;
                break;
            case ACHIEVEMENT_CRITERIA_ADDITIONAL_CONDITION_TARGET_HAS_AURA: // 10
                if (!unit || !unit->HasAura(reqValue))
                    return false;
            case ACHIEVEMENT_CRITERIA_ADDITIONAL_CONDITION_TARGET_HAS_AURA_TYPE: // 11
                if (!unit || !unit->HasAuraType(AuraType(reqValue)))
                    return false;
                break;
            case ACHIEVEMENT_CRITERIA_ADDITIONAL_CONDITION_ITEM_QUALITY_MIN: // 14
            {
                // miscValue1 is itemid
                ItemTemplate const* const item = sObjectMgr->GetItemTemplate(uint32(miscValue1));
                if (!item || item->Quality < reqValue)
                    return false;
                break;
            }
            case ACHIEVEMENT_CRITERIA_ADDITIONAL_CONDITION_ITEM_QUALITY_EQUALS: // 15
            {
                // miscValue1 is itemid
                ItemTemplate const* const item = sObjectMgr->GetItemTemplate(uint32(miscValue1));
                if (!item || item->Quality != reqValue)
                    return false;
                break;
            }
            case ACHIEVEMENT_CRITERIA_ADDITIONAL_CONDITION_SOURCE_AREA_OR_ZONE: // 17
            {
                uint32 zoneId, areaId;
                referencePlayer->GetZoneAndAreaId(zoneId, areaId);
                if (zoneId != reqValue && areaId != reqValue)
                    return false;
                break;
            }
            case ACHIEVEMENT_CRITERIA_ADDITIONAL_CONDITION_TARGET_AREA_OR_ZONE: // 18
            {
                if (!unit)
                    return false;
                uint32 zoneId, areaId;
                unit->GetZoneAndAreaId(zoneId, areaId);
                if (zoneId != reqValue && areaId != reqValue)
                    return false;
                break;
            }
            case ACHIEVEMENT_CRITERIA_ADDITIONAL_CONDITION_MAP_DIFFICULTY: // 20
                if (uint32(referencePlayer->GetMap()->GetDifficulty()) != reqValue)
                    return false;
                break;
            case ACHIEVEMENT_CRITERIA_ADDITIONAL_CONDITION_SOURCE_RACE: // 25
                if (referencePlayer->getRace() != reqValue)
                    return false;
                break;
            case ACHIEVEMENT_CRITERIA_ADDITIONAL_CONDITION_SOURCE_CLASS: // 26
                if (referencePlayer->getClass() != reqValue)
                    return false;
                break;
            case ACHIEVEMENT_CRITERIA_ADDITIONAL_CONDITION_TARGET_RACE: // 27
                if (!unit || unit->GetTypeId() != TYPEID_PLAYER || unit->getRace() != reqValue)
                    return false;
                break;
            case ACHIEVEMENT_CRITERIA_ADDITIONAL_CONDITION_TARGET_CLASS: // 28
                if (!unit || unit->GetTypeId() != TYPEID_PLAYER || unit->getClass() != reqValue)
                    return false;
                break;
            case ACHIEVEMENT_CRITERIA_ADDITIONAL_CONDITION_MAX_GROUP_MEMBERS: // 29
                if (referencePlayer->GetGroup() && referencePlayer->GetGroup()->GetMembersCount() >= reqValue)
                    return false;
                break;
            case ACHIEVEMENT_CRITERIA_ADDITIONAL_CONDITION_TARGET_CREATURE_TYPE: // 30
            {
                if (!unit)
                    return false;
                Creature const* const creature = unit->ToCreature();
                if (!creature || creature->GetCreatureType() != reqValue)
                    return false;
                break;
            }
            case ACHIEVEMENT_CRITERIA_ADDITIONAL_CONDITION_SOURCE_MAP: // 32
                if (referencePlayer->GetMapId() != reqValue)
                    return false;
                break;
            case ACHIEVEMENT_CRITERIA_ADDITIONAL_CONDITION_TITLE_BIT_INDEX: // 38
                // miscValue1 is title's bit index
                if (miscValue1 != reqValue)
                    return false;
                break;
            case ACHIEVEMENT_CRITERIA_ADDITIONAL_CONDITION_SOURCE_LEVEL: // 39
                if (referencePlayer->getLevel() != reqValue)
                    return false;
                break;
            case ACHIEVEMENT_CRITERIA_ADDITIONAL_CONDITION_TARGET_LEVEL: // 40
                if (!unit || unit->getLevel() != reqValue)
                    return false;
                break;
            case ACHIEVEMENT_CRITERIA_ADDITIONAL_CONDITION_TARGET_ZONE: // 41
                if (!unit || unit->GetZoneId() != reqValue)
                    return false;
            case ACHIEVEMENT_CRITERIA_ADDITIONAL_CONDITION_TARGET_HEALTH_PERCENT_BELOW: // 46
                if (!unit || unit->GetHealthPct() >= reqValue)
                    return false;
                break;
            default:
                break;
        }
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
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_ARCHAEOLOGY_PROJECTS:
            return "COMPLETE_RESEARCH";
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
        case ACHIEVEMENT_CRITERIA_TYPE_CURRENCY:
            return "CURRENCY";
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
        case ACHIEVEMENT_CRITERIA_TYPE_EARNED_PVP_TITLE:
            return "EARNED_PVP_TITLE";
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
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HIT_DEALT:
            return "HIT_DEALT";
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HIT_RECEIVED:
            return "HIT_RECEIVED";
        case ACHIEVEMENT_CRITERIA_TYPE_TOTAL_DAMAGE_RECEIVED:
            return "TOTAL_DAMAGE_RECEIVED";
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEAL_CASTED:
            return "HIGHEST_HEAL_CASTED";
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
        case ACHIEVEMENT_CRITERIA_TYPE_SPENT_GOLD_GUILD_REPAIRS:
            return "SPENT_GOLD_GUILD_REPAIRS";
        case ACHIEVEMENT_CRITERIA_TYPE_REACH_GUILD_LEVEL:
            return "REACH_GUILD_LEVEL";
        case ACHIEVEMENT_CRITERIA_TYPE_CRAFT_ITEMS_GUILD:
            return "CRAFT_ITEMS_GUILD";
        case ACHIEVEMENT_CRITERIA_TYPE_CATCH_FROM_POOL:
            return "CATCH_FROM_POOL";
        case ACHIEVEMENT_CRITERIA_TYPE_BUY_GUILD_BANK_SLOTS:
            return "BUY_GUILD_BANK_SLOTS";
        case ACHIEVEMENT_CRITERIA_TYPE_EARN_GUILD_ACHIEVEMENT_POINTS:
            return "EARN_GUILD_ACHIEVEMENT_POINTS";
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_BATTLEGROUND:
            return "WIN_RATED_BATTLEGROUND";
        case ACHIEVEMENT_CRITERIA_TYPE_REACH_BG_RATING:
            return "REACH_BG_RATING";
        case ACHIEVEMENT_CRITERIA_TYPE_BUY_GUILD_TABARD:
            return "BUY_GUILD_TABARD";
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUESTS_GUILD:
            return "COMPLETE_QUESTS_GUILD";
        case ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILLS_GUILD:
            return "HONORABLE_KILLS_GUILD";
        case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE_TYPE_GUILD:
            return "KILL_CREATURE_TYPE_GUILD";
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_GUILD_CHALLENGE_TYPE:
            return "GUILD_CHALLENGE_TYPE";
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_GUILD_CHALLENGE:
            return "GUILD_CHALLENGE";
    }
    return "MISSING_TYPE";
}

template class AchievementMgr<Guild>;
template class AchievementMgr<Player>;

//==========================================================
void AchievementGlobalMgr::LoadAchievementCriteriaList()
{
    uint32 oldMSTime = getMSTime();

    if (sAchievementCriteriaStore.GetNumRows() == 0)
    {
        TC_LOG_ERROR(LOG_FILTER_SERVER_LOADING, ">> Loaded 0 achievement criteria.");
        return;
    }

    uint32 criterias = 0;
    uint32 guildCriterias = 0;
    for (uint32 entryId = 0; entryId < sAchievementCriteriaStore.GetNumRows(); ++entryId)
    {
        AchievementCriteriaEntry const* criteria = sAchievementMgr->GetAchievementCriteria(entryId);
        if (!criteria)
            continue;

        AchievementEntry const* achievement = sAchievementMgr->GetAchievement(criteria->achievement);

        m_AchievementCriteriaListByAchievement[criteria->achievement].push_back(criteria);

        if (achievement && achievement->flags & ACHIEVEMENT_FLAG_GUILD)
            ++guildCriterias, m_GuildAchievementCriteriasByType[criteria->type].push_back(criteria);
        else
            ++criterias, m_AchievementCriteriasByType[criteria->type].push_back(criteria);

        if (criteria->timeLimit)
            m_AchievementCriteriasByTimedType[criteria->timedCriteriaStartType].push_back(criteria);
    }

    TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> Loaded %u achievement criteria and %u guild achievement crieteria in %u ms", criterias, guildCriterias, GetMSTimeDiffToNow(oldMSTime));
}

void AchievementGlobalMgr::LoadAchievementReferenceList()
{
    uint32 oldMSTime = getMSTime();

    if (sAchievementStore.GetNumRows() == 0)
    {
        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> Loaded 0 achievement references.");
        return;
    }

    uint32 count = 0;

    for (uint32 entryId = 0; entryId < sAchievementStore.GetNumRows(); ++entryId)
    {
        AchievementEntry const* achievement = sAchievementMgr->GetAchievement(entryId);
        if (!achievement || !achievement->refAchievement)
            continue;

        m_AchievementListByReferencedId[achievement->refAchievement].push_back(achievement);
        ++count;
    }

    // Once Bitten, Twice Shy (10 player) - Icecrown Citadel
    if (AchievementEntry const* achievement = sAchievementMgr->GetAchievement(4539))
        const_cast<AchievementEntry*>(achievement)->mapID = 631;    // Correct map requirement (currently has Ulduar)

    TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> Loaded %u achievement references in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void AchievementGlobalMgr::LoadAchievementCriteriaData()
{
    uint32 oldMSTime = getMSTime();

    m_criteriaDataMap.clear();                              // need for reload case

    QueryResult result = WorldDatabase.Query("SELECT criteria_id, type, value1, value2, ScriptName FROM achievement_criteria_data");

    if (!result)
    {
        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> Loaded 0 additional achievement criteria data. DB table `achievement_criteria_data` is empty.");
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
            TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_criteria_data` has data for non-existing criteria (Entry: %u), ignore.", criteria_id);
            continue;
        }

        uint32 dataType = fields[1].GetUInt8();
        std::string scriptName = fields[4].GetString();
        uint32 scriptId = 0;
        if (scriptName.length()) // not empty
        {
            if (dataType != ACHIEVEMENT_CRITERIA_DATA_TYPE_SCRIPT)
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_criteria_data` has ScriptName set for non-scripted data type (Entry: %u, type %u), useless data.", criteria_id, dataType);
            else
                scriptId = sObjectMgr->GetScriptId(scriptName.c_str());
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

    TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> Loaded %u additional achievement criteria data in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void AchievementGlobalMgr::LoadCompletedAchievements()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = CharacterDatabase.Query("SELECT achievement FROM character_achievement GROUP BY achievement");

    if (!result)
    {
        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> Loaded 0 realm first completed achievements. DB table `character_achievement` is empty.");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        uint16 achievementId = fields[0].GetUInt16();
        const AchievementEntry* achievement = sAchievementMgr->GetAchievement(achievementId);
        if (!achievement)
        {
            // Remove non existent achievements from all characters
            TC_LOG_ERROR(LOG_FILTER_ACHIEVEMENTSYS, "Non-existing achievement %u data removed from table `character_achievement`.", achievementId);

            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_INVALID_ACHIEVMENT);
            stmt->setUInt16(0, uint16(achievementId));
            CharacterDatabase.Execute(stmt);

            continue;
        }
        else if (achievement->flags & (ACHIEVEMENT_FLAG_REALM_FIRST_REACH | ACHIEVEMENT_FLAG_REALM_FIRST_KILL))
            m_allCompletedAchievements.insert(achievementId);
    }
    while (result->NextRow());

    TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> Loaded %lu realm first completed achievements in %u ms", (unsigned long)m_allCompletedAchievements.size(), GetMSTimeDiffToNow(oldMSTime));
}

void AchievementGlobalMgr::LoadRewards()
{
    uint32 oldMSTime = getMSTime();

    m_achievementRewards.clear();                           // need for reload case

    //                                               0      1        2        3     4       5        6
    QueryResult result = WorldDatabase.Query("SELECT entry, title_A, title_H, item, sender, subject, text FROM achievement_reward");

    if (!result)
    {
        TC_LOG_ERROR(LOG_FILTER_SERVER_LOADING, ">> Loaded 0 achievement rewards. DB table `achievement_reward` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();
        uint32 entry = fields[0].GetUInt32();
        const AchievementEntry* pAchievement = GetAchievement(entry);
        if (!pAchievement)
        {
            TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_reward` has wrong achievement (Entry: %u), ignored.", entry);
            continue;
        }

        AchievementReward reward;
        reward.titleId[0] = fields[1].GetUInt32();
        reward.titleId[1] = fields[2].GetUInt32();
        reward.itemId     = fields[3].GetUInt32();
        reward.sender     = fields[4].GetUInt32();
        reward.subject    = fields[5].GetString();
        reward.text       = fields[6].GetString();

        // must be title or mail at least
        if (!reward.titleId[0] && !reward.titleId[1] && !reward.sender)
        {
            TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_reward` (Entry: %u) does not have title or item reward data, ignored.", entry);
            continue;
        }

        if (pAchievement->requiredFaction == ACHIEVEMENT_FACTION_ANY && ((reward.titleId[0] == 0) != (reward.titleId[1] == 0)))
            TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_reward` (Entry: %u) has title (A: %u H: %u) for only one team.", entry, reward.titleId[0], reward.titleId[1]);

        if (reward.titleId[0])
        {
            CharTitlesEntry const* titleEntry = sCharTitlesStore.LookupEntry(reward.titleId[0]);
            if (!titleEntry)
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_reward` (Entry: %u) has invalid title id (%u) in `title_A`, set to 0", entry, reward.titleId[0]);
                reward.titleId[0] = 0;
            }
        }

        if (reward.titleId[1])
        {
            CharTitlesEntry const* titleEntry = sCharTitlesStore.LookupEntry(reward.titleId[1]);
            if (!titleEntry)
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_reward` (Entry: %u) has invalid title id (%u) in `title_H`, set to 0", entry, reward.titleId[1]);
                reward.titleId[1] = 0;
            }
        }

        //check mail data before item for report including wrong item case
        if (reward.sender)
        {
            if (!sObjectMgr->GetCreatureTemplate(reward.sender))
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_reward` (Entry: %u) has invalid creature entry %u as sender, mail reward skipped.", entry, reward.sender);
                reward.sender = 0;
            }
        }
        else
        {
            if (reward.itemId)
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_reward` (Entry: %u) does not have sender data but has item reward, item will not be rewarded.", entry);

            if (!reward.subject.empty())
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_reward` (Entry: %u) does not have sender data but has mail subject.", entry);

            if (!reward.text.empty())
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_reward` (Entry: %u) does not have sender data but has mail text.", entry);
        }

        if (reward.itemId)
        {
            if (!sObjectMgr->GetItemTemplate(reward.itemId))
            {
                TC_LOG_ERROR(LOG_FILTER_SQL, "Table `achievement_reward` (Entry: %u) has invalid item id %u, reward mail will not contain item.", entry, reward.itemId);
                reward.itemId = 0;
            }
        }

        m_achievementRewards[entry] = reward;
        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> Loaded %u achievement rewards in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void AchievementGlobalMgr::LoadRewardLocales()
{
    uint32 oldMSTime = getMSTime();

    m_achievementRewardLocales.clear();                       // need for reload case

    QueryResult result = WorldDatabase.Query("SELECT entry, subject_loc1, text_loc1, subject_loc2, text_loc2, subject_loc3, text_loc3, subject_loc4, text_loc4, "
                                             "subject_loc5, text_loc5, subject_loc6, text_loc6, subject_loc7, text_loc7, subject_loc8, text_loc8"
                                             " FROM locales_achievement_reward");

    if (!result)
    {
        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> Loaded 0 achievement reward locale strings.  DB table `locales_achievement_reward` is empty");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        uint32 entry = fields[0].GetUInt32();

        if (m_achievementRewards.find(entry) == m_achievementRewards.end())
        {
            TC_LOG_ERROR(LOG_FILTER_SQL, "Table `locales_achievement_reward` (Entry: %u) has locale strings for non-existing achievement reward.", entry);
            continue;
        }

        AchievementRewardLocale& data = m_achievementRewardLocales[entry];

        for (int i = 1; i < TOTAL_LOCALES; ++i)
        {
            LocaleConstant locale = (LocaleConstant) i;
            ObjectMgr::AddLocaleString(fields[1 + 2 * (i - 1)].GetString(), locale, data.subject);
            ObjectMgr::AddLocaleString(fields[1 + 2 * (i - 1) + 1].GetString(), locale, data.text);
        }
    }
    while (result->NextRow());

    TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> Loaded %lu achievement reward locale strings in %u ms", (unsigned long)m_achievementRewardLocales.size(), GetMSTimeDiffToNow(oldMSTime));
}

AchievementEntry const* AchievementGlobalMgr::GetAchievement(uint32 achievementId) const
{
    return sAchievementStore.LookupEntry(achievementId);
}

AchievementCriteriaEntry const* AchievementGlobalMgr::GetAchievementCriteria(uint32 criteriaId) const
{
    return sAchievementCriteriaStore.LookupEntry(criteriaId);
}
