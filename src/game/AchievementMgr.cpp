/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Common.h"
#include "DBCEnums.h"
#include "ObjectMgr.h"
#include "World.h"
#include "WorldPacket.h"
#include "Database/DatabaseEnv.h"
#include "Policies/SingletonImp.h"

#include "AchievementMgr.h"
#include "ArenaTeam.h"
#include "CellImpl.h"
#include "GameEventMgr.h"
#include "GridNotifiersImpl.h"
#include "Guild.h"
#include "Language.h"
#include "Player.h"
#include "ProgressBar.h"
#include "SpellMgr.h"

#include "MapManager.h"
#include "BattleGround.h"
#include "BattleGroundAB.h"
#include "Map.h"
#include "InstanceData.h"

INSTANTIATE_SINGLETON_1(AchievementGlobalMgr);

namespace Trinity
{
    class AchievementChatBuilder
    {
        public:
            AchievementChatBuilder(Player const& pl, ChatMsg msgtype, int32 textId, uint32 ach_id)
                : i_player(pl), i_msgtype(msgtype), i_textId(textId), i_achievementId(ach_id) {}
            void operator()(WorldPacket& data, int32 loc_idx)
            {
                char const* text = objmgr.GetTrinityString(i_textId,loc_idx);

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
    if(dataType >= MAX_ACHIEVEMENT_CRITERIA_DATA_TYPE)
    {
        sLog.outErrorDb( "Table `achievement_criteria_data` for criteria (Entry: %u) have wrong data type (%u), ignore.", criteria->ID,dataType);
        return false;
    }

    switch(criteria->requiredType)
    {
        case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE:
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_BG:
        case ACHIEVEMENT_CRITERIA_TYPE_FALL_WITHOUT_DYING:
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST:      // only hardcoded list
        case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL:
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_ARENA:
        case ACHIEVEMENT_CRITERIA_TYPE_DO_EMOTE:
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_DUEL:
        case ACHIEVEMENT_CRITERIA_TYPE_LOOT_TYPE:
        case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL2:
        case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET:
        case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2:
            break;
        default:
            sLog.outErrorDb( "Table `achievement_criteria_data` have data for not supported criteria type (Entry: %u Type: %u), ignore.", criteria->ID, criteria->requiredType);
            return false;
    }

    switch(dataType)
    {
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_NONE:
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_VALUE:
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_DISABLED:
        case ACHIEVEMENT_CRITERIA_DATA_INSTANCE_SCRIPT:
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_CREATURE:
            if (!creature.id || !objmgr.GetCreatureTemplate(creature.id))
            {
                sLog.outErrorDb( "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_CREATURE (%u) have not existed creature id in value1 (%u), ignore.",
                    criteria->ID, criteria->requiredType,dataType,creature.id);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_CLASS_RACE:
            if (!classRace.class_id && !classRace.race_id)
            {
                sLog.outErrorDb( "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_PLAYER_CLASS_RACE (%u) must have not 0 in one from value fields, ignore.",
                    criteria->ID, criteria->requiredType,dataType);
                return false;
            }
            if (classRace.class_id && ((1 << (classRace.class_id-1)) & CLASSMASK_ALL_PLAYABLE)==0)
            {
                sLog.outErrorDb( "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_CREATURE (%u) have not existed class in value1 (%u), ignore.",
                    criteria->ID, criteria->requiredType,dataType,classRace.class_id);
                return false;
            }
            if (classRace.race_id && ((1 << (classRace.race_id-1)) & RACEMASK_ALL_PLAYABLE)==0)
            {
                sLog.outErrorDb( "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_CREATURE (%u) have not existed race in value2 (%u), ignore.",
                    criteria->ID, criteria->requiredType,dataType,classRace.race_id);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_LESS_HEALTH:
            if (health.percent < 1 || health.percent > 100)
            {
                sLog.outErrorDb( "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_PLAYER_LESS_HEALTH (%u) have wrong percent value in value1 (%u), ignore.",
                    criteria->ID, criteria->requiredType,dataType,health.percent);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_DEAD:
            if (player_dead.own_team_flag > 1)
            {
                sLog.outErrorDb( "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_DEAD (%u) have wrong boolean value1 (%u).",
                    criteria->ID, criteria->requiredType,dataType,player_dead.own_team_flag);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA:
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_AURA:
        {
            SpellEntry const* spellEntry = sSpellStore.LookupEntry(aura.spell_id);
            if (!spellEntry)
            {
                sLog.outErrorDb( "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type %s (%u) have wrong spell id in value1 (%u), ignore.",
                    criteria->ID, criteria->requiredType,(dataType==ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA?"ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA":"ACHIEVEMENT_CRITERIA_DATA_TYPE_T_AURA"),dataType,aura.spell_id);
                return false;
            }
            if (aura.effect_idx >= 3)
            {
                sLog.outErrorDb( "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type %s (%u) have wrong spell effect index in value2 (%u), ignore.",
                    criteria->ID, criteria->requiredType,(dataType==ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA?"ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA":"ACHIEVEMENT_CRITERIA_DATA_TYPE_T_AURA"),dataType,aura.effect_idx);
                return false;
            }
            if (!spellEntry->EffectApplyAuraName[aura.effect_idx])
            {
                sLog.outErrorDb( "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type %s (%u) have non-aura spell effect (ID: %u Effect: %u), ignore.",
                    criteria->ID, criteria->requiredType,(dataType==ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA?"ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA":"ACHIEVEMENT_CRITERIA_DATA_TYPE_T_AURA"),dataType,aura.spell_id,aura.effect_idx);
                return false;
            }
            return true;
        }
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AREA:
            if (!GetAreaEntryByAreaID(area.id))
            {
                sLog.outErrorDb( "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AREA (%u) have wrong area id in value1 (%u), ignore.",
                    criteria->ID, criteria->requiredType,dataType,area.id);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_LEVEL:
            if (level.minlevel < 0 || level.minlevel > STRONG_MAX_LEVEL)
            {
                sLog.outErrorDb( "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_T_LEVEL (%u) have wrong minlevel in value1 (%u), ignore.",
                    criteria->ID, criteria->requiredType,dataType,level.minlevel);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_GENDER:
            if (gender.gender > GENDER_NONE)
            {
                sLog.outErrorDb( "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_T_GENDER (%u) have wrong gender in value1 (%u), ignore.",
                    criteria->ID, criteria->requiredType,dataType,gender.gender);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_MAP_DIFFICULTY:
            if (difficulty.difficulty >= MAX_DIFFICULTY)
            {
                sLog.outErrorDb( "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_MAP_DIFFICULTY (%u) have wrong difficulty in value1 (%u), ignore.",
                    criteria->ID, criteria->requiredType,dataType,difficulty.difficulty);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_MAP_PLAYER_COUNT:
            if (map_players.maxcount <= 0)
            {
                sLog.outErrorDb( "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_MAP_PLAYER_COUNT (%u) have wrong max players count in value1 (%u), ignore.",
                    criteria->ID, criteria->requiredType,dataType,map_players.maxcount);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_TEAM:
            if (team.team != ALLIANCE && team.team != HORDE)
            {
                sLog.outErrorDb( "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_T_TEAM (%u) have unknown team in value1 (%u), ignore.",
                    criteria->ID, criteria->requiredType,dataType,team.team);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_DRUNK:
            if(drunk.state >= MAX_DRUNKEN)
            {
                sLog.outErrorDb( "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_S_DRUNK (%u) have unknown drunken state in value1 (%u), ignore.",
                    criteria->ID, criteria->requiredType,dataType,drunk.state);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_HOLIDAY:
            if (!sHolidaysStore.LookupEntry(holiday.id))
            {
                sLog.outErrorDb( "Table `achievement_criteria_data` (Entry: %u Type: %u) for data type ACHIEVEMENT_CRITERIA_DATA_TYPE_HOLIDAY (%u) have unknown holiday in value1 (%u), ignore.",
                    criteria->ID, criteria->requiredType,dataType,holiday.id);
                return false;
            }
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_BG_LOSS_TEAM_SCORE:
            return true;                                    // not check correctness node indexes
        default:
            sLog.outErrorDb( "Table `achievement_criteria_data` (Entry: %u Type: %u) have data for not supported data type (%u), ignore.", criteria->ID, criteria->requiredType,dataType);
            return false;
    }
    return false;
}

bool AchievementCriteriaData::Meets(uint32 criteria_id, Player const* source, Unit const* target, uint32 miscvalue1 /*= 0*/) const
{
    switch(dataType)
    {
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_NONE:
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_CREATURE:
            if (!target || target->GetTypeId()!=TYPEID_UNIT)
                return false;
            return target->GetEntry() == creature.id;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_CLASS_RACE:
            if (!target || target->GetTypeId() != TYPEID_PLAYER)
                return false;
            if(classRace.class_id && classRace.class_id != ((Player*)target)->getClass())
                return false;
            if(classRace.race_id && classRace.race_id != ((Player*)target)->getRace())
                return false;
            return true;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_LESS_HEALTH:
            if (!target || target->GetTypeId() != TYPEID_PLAYER)
                return false;
            return target->GetHealth()*100 <= health.percent*target->GetMaxHealth();
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_DEAD:
            if (!target || target->GetTypeId() != TYPEID_PLAYER || target->isAlive() || ((Player*)target)->GetDeathTimer() == 0)
                return false;
            // flag set == must be same team, not set == different team
            return (((Player*)target)->GetTeam() == source->GetTeam()) == (player_dead.own_team_flag != 0);
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA:
            return source->HasAuraEffect(aura.spell_id,aura.effect_idx);
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AREA:
        {
            uint32 zone_id,area_id;
            source->GetZoneAndAreaId(zone_id,area_id);
            return area.id==zone_id || area.id==area_id;
        }
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_AURA:
            return target && target->HasAuraEffect(aura.spell_id,aura.effect_idx);
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_VALUE:
            return miscvalue1 >= value.minvalue;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_LEVEL:
            if (!target)
                return false;
            return target->getLevel() >= level.minlevel;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_GENDER:
            if (!target)
                return false;
            return target->getGender() == gender.gender;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_DISABLED:
            return false;                                   // always fail
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_MAP_DIFFICULTY:
            return source->GetMap()->GetSpawnMode()==difficulty.difficulty;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_MAP_PLAYER_COUNT:
            return source->GetMap()->GetPlayersCountExceptGMs() <= map_players.maxcount;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_T_TEAM:
            if (!target || target->GetTypeId() != TYPEID_PLAYER)
                return false;
            return ((Player*)target)->GetTeam() == team.team;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_S_DRUNK:
            return Player::GetDrunkenstateByValue(source->GetDrunkValue()) >= drunk.state;
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_HOLIDAY:
            return IsHolidayActive(HolidayIds(holiday.id));
        case ACHIEVEMENT_CRITERIA_DATA_TYPE_BG_LOSS_TEAM_SCORE:
        {
            BattleGround* bg = source->GetBattleGround();
            if(!bg)
                return false;
            return bg->IsTeamScoreInRange(source->GetTeam()==ALLIANCE ? HORDE : ALLIANCE,bg_loss_team_score.min_score,bg_loss_team_score.max_score);
        }
        case ACHIEVEMENT_CRITERIA_DATA_INSTANCE_SCRIPT:
            if (!source->IsInWorld())
                return false;
            Map* map = source->GetMap();
            if (!map->Instanceable())
            {
                sLog.outErrorDb("Achievement system call ACHIEVEMENT_CRITERIA_DATA_INSTANCE_SCRIPT (%u) for achievement criteria %u for non-instance map %u",
                    ACHIEVEMENT_CRITERIA_DATA_INSTANCE_SCRIPT, criteria_id, map->GetId());
                    return false;
            }
            InstanceData* data = ((InstanceMap*)map)->GetInstanceData();
            if (!data)
            {
                sLog.outErrorDb("Achievement system call ACHIEVEMENT_CRITERIA_DATA_INSTANCE_SCRIPT (%u) for achievement criteria %u for map %u but map not have instance script",
                    ACHIEVEMENT_CRITERIA_DATA_INSTANCE_SCRIPT, criteria_id, map->GetId());
                return false;
            }
            return data->CheckAchievementCriteriaMeet(criteria_id, source, target, miscvalue1);
    }
    return false;
}

bool AchievementCriteriaDataSet::Meets(Player const* source, Unit const* target, uint32 miscvalue /*= 0*/) const
{
    for (Storage::const_iterator itr = storage.begin(); itr != storage.end(); ++itr)
        if(!itr->Meets(criteria_id, source, target, miscvalue))
            return false;

    return true;
}

AchievementMgr::AchievementMgr(Player *player)
{
    m_player = player;
}

AchievementMgr::~AchievementMgr()
{
}

void AchievementMgr::Reset()
{
    for (CompletedAchievementMap::const_iterator iter = m_completedAchievements.begin(); iter!=m_completedAchievements.end(); ++iter)
    {
        WorldPacket data(SMSG_ACHIEVEMENT_DELETED,4);
        data << uint32(iter->first);
        m_player->SendDirectMessage(&data);
    }

    for (CriteriaProgressMap::const_iterator iter = m_criteriaProgress.begin(); iter!=m_criteriaProgress.end(); ++iter)
    {
        WorldPacket data(SMSG_CRITERIA_DELETED,4);
        data << uint32(iter->first);
        m_player->SendDirectMessage(&data);
    }

    m_completedAchievements.clear();
    m_criteriaProgress.clear();
    DeleteFromDB(m_player->GetGUIDLow());

    // re-fill data
    CheckAllAchievementCriteria();
}

void AchievementMgr::ResetAchievementCriteria(AchievementCriteriaTypes type, uint32 miscvalue1, uint32 miscvalue2)
{
    if((sLog.getLogFilter() & LOG_FILTER_ACHIEVEMENT_UPDATES)==0)
        sLog.outDetail("AchievementMgr::ResetAchievementCriteria(%u, %u, %u)", type, miscvalue1, miscvalue2);

    if (!sWorld.getConfig(CONFIG_GM_ALLOW_ACHIEVEMENT_GAINS) && m_player->GetSession()->GetSecurity() > SEC_PLAYER)
        return;

    AchievementCriteriaEntryList const& achievementCriteriaList = achievementmgr.GetAchievementCriteriaByType(type);
    for (AchievementCriteriaEntryList::const_iterator i = achievementCriteriaList.begin(); i!=achievementCriteriaList.end(); ++i)
    {
        AchievementCriteriaEntry const *achievementCriteria = (*i);

        AchievementEntry const *achievement = sAchievementStore.LookupEntry(achievementCriteria->referredAchievement);
        if (!achievement)
            continue;

        // don't update already completed criteria
        if (IsCompletedCriteria(achievementCriteria,achievement))
            continue;

        switch (type)
        {
            case ACHIEVEMENT_CRITERIA_TYPE_DAMAGE_DONE:     // have total statistic also not expected to be reset
            case ACHIEVEMENT_CRITERIA_TYPE_HEALING_DONE:    // have total statistic also not expected to be reset
                if (achievementCriteria->healing_done.flag == miscvalue1 &&
                    achievementCriteria->healing_done.mapid == miscvalue2)
                    SetCriteriaProgress(achievementCriteria, 0, PROGRESS_SET);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_ARENA: // have total statistic also not expected to be reset
                // reset only the criteria having the miscvalue1 condition
                if (achievementCriteria->win_rated_arena.flag == miscvalue1)
                    SetCriteriaProgress(achievementCriteria, 0, PROGRESS_SET);
                break;
            default:                                        // reset all cases
                break;
        }
    }
}

void AchievementMgr::DeleteFromDB(uint32 lowguid)
{
    CharacterDatabase.BeginTransaction ();
    CharacterDatabase.PExecute("DELETE FROM character_achievement WHERE guid = %u",lowguid);
    CharacterDatabase.PExecute("DELETE FROM character_achievement_progress WHERE guid = %u",lowguid);
    CharacterDatabase.CommitTransaction ();
}

void AchievementMgr::SaveToDB()
{
    if(!m_completedAchievements.empty())
    {
        bool need_execute = false;
        std::ostringstream ssdel;
        std::ostringstream ssins;
        for (CompletedAchievementMap::iterator iter = m_completedAchievements.begin(); iter!=m_completedAchievements.end(); ++iter)
        {
            if(!iter->second.changed)
                continue;

            /// first new/changed record prefix
            if(!need_execute)
            {
                ssdel << "DELETE FROM character_achievement WHERE guid = " << GetPlayer()->GetGUIDLow() << " AND achievement IN (";
                ssins << "INSERT INTO character_achievement (guid, achievement, date) VALUES ";
                need_execute = true;
            }
            /// next new/changed record prefix
            else
            {
                ssdel << ", ";
                ssins << ", ";
            }

            // new/changed record data
            ssdel << iter->first;
            ssins << "("<<GetPlayer()->GetGUIDLow() << ", " << iter->first << ", " << uint64(iter->second.date) << ")";

            /// mark as saved in db
            iter->second.changed = false;
        }

        if(need_execute)
            ssdel << ")";

        if(need_execute)
        {
            CharacterDatabase.Execute( ssdel.str().c_str() );
            CharacterDatabase.Execute( ssins.str().c_str() );
        }
    }

    if(!m_criteriaProgress.empty())
    {
        /// prepare deleting and insert
        bool need_execute_del = false;
        bool need_execute_ins = false;
        std::ostringstream ssdel;
        std::ostringstream ssins;
        for (CriteriaProgressMap::iterator iter = m_criteriaProgress.begin(); iter!=m_criteriaProgress.end(); ++iter)
        {
            if(!iter->second.changed)
                continue;

            // deleted data (including 0 progress state)
            {
                /// first new/changed record prefix (for any counter value)
                if(!need_execute_del)
                {
                    ssdel << "DELETE FROM character_achievement_progress WHERE guid = " << GetPlayer()->GetGUIDLow() << " AND criteria IN (";
                    need_execute_del = true;
                }
                /// next new/changed record prefix
                else
                    ssdel << ", ";

                // new/changed record data
                ssdel << iter->first;
            }

            // store data only for real progress
            if(iter->second.counter != 0)
            {
                /// first new/changed record prefix
                if(!need_execute_ins)
                {
                    ssins << "INSERT INTO character_achievement_progress (guid, criteria, counter, date) VALUES ";
                    need_execute_ins = true;
                }
                /// next new/changed record prefix
                else
                    ssins << ", ";

                // new/changed record data
                ssins << "(" << GetPlayer()->GetGUIDLow() << ", " << iter->first << ", " << iter->second.counter << ", " << iter->second.date << ")";
            }

            /// mark as updated in db
            iter->second.changed = false;
        }

        if(need_execute_del)                                // DELETE ... IN (.... _)_
            ssdel << ")";

        if(need_execute_del || need_execute_ins)
        {
            if(need_execute_del)
                CharacterDatabase.Execute( ssdel.str().c_str() );
            if(need_execute_ins)
                CharacterDatabase.Execute( ssins.str().c_str() );
        }
    }
}

void AchievementMgr::LoadFromDB(QueryResult_AutoPtr achievementResult, QueryResult_AutoPtr criteriaResult)
{
    if(achievementResult)
    {
        do
        {
            Field *fields = achievementResult->Fetch();

            uint32 achievement_id = fields[0].GetUInt32();

            // don't must happen: cleanup at server startup in achievementmgr.LoadCompletedAchievements()
            if(!sAchievementStore.LookupEntry(achievement_id))
                continue;

            CompletedAchievementData& ca = m_completedAchievements[achievement_id];
            ca.date = time_t(fields[1].GetUInt64());
            ca.changed = false;
        } while(achievementResult->NextRow());
    }

    if(criteriaResult)
    {
        do
        {
            Field *fields = criteriaResult->Fetch();

            uint32 id      = fields[0].GetUInt32();
            uint32 counter = fields[1].GetUInt32();
            time_t date    = time_t(fields[2].GetUInt64());

            AchievementCriteriaEntry const* criteria = sAchievementCriteriaStore.LookupEntry(id);
            if (!criteria)
            {
                // we will remove not existed criteria for all characters
                sLog.outError("Not existed achievement criteria %u data removed from table `character_achievement_progress`.",id);
                CharacterDatabase.PExecute("DELETE FROM character_achievement_progress WHERE criteria = %u",id);
                continue;
            }

            if (criteria->timeLimit && time_t(date + criteria->timeLimit) < time(NULL))
                continue;

            CriteriaProgress& progress = m_criteriaProgress[id];
            progress.counter = counter;
            progress.date    = date;
            progress.changed = false;
        } while(criteriaResult->NextRow());
    }

}

void AchievementMgr::SendAchievementEarned(AchievementEntry const* achievement)
{
    if(GetPlayer()->GetSession()->PlayerLoading())
        return;

    #ifdef TRINITY_DEBUG
    if((sLog.getLogFilter() & LOG_FILTER_ACHIEVEMENT_UPDATES)==0)
        sLog.outDebug("AchievementMgr::SendAchievementEarned(%u)", achievement->ID);
    #endif

    if(Guild* guild = objmgr.GetGuildById(GetPlayer()->GetGuildId()))
    {
        Trinity::AchievementChatBuilder say_builder(*GetPlayer(), CHAT_MSG_GUILD_ACHIEVEMENT, LANG_ACHIEVEMENT_EARNED,achievement->ID);
        Trinity::LocalizedPacketDo<Trinity::AchievementChatBuilder> say_do(say_builder);
        guild->BroadcastWorker(say_do,GetPlayer());
    }

    if(achievement->flags & (ACHIEVEMENT_FLAG_REALM_FIRST_KILL|ACHIEVEMENT_FLAG_REALM_FIRST_REACH))
    {
        // broadcast realm first reached
        WorldPacket data(SMSG_SERVER_FIRST_ACHIEVEMENT, strlen(GetPlayer()->GetName())+1+8+4+4);
        data << GetPlayer()->GetName();
        data << uint64(GetPlayer()->GetGUID());
        data << uint32(achievement->ID);
        data << uint32(0);                                  // 1=link supplied string as player name, 0=display plain string
        sWorld.SendGlobalMessage(&data);
    }
    // if player is in world he can tell his friends about new achievement
    else if (GetPlayer()->IsInWorld())
    {
        CellPair p = Trinity::ComputeCellPair(GetPlayer()->GetPositionX(), GetPlayer()->GetPositionY());

        Cell cell(p);
        cell.data.Part.reserved = ALL_DISTRICT;
        cell.SetNoCreate();

        Trinity::AchievementChatBuilder say_builder(*GetPlayer(), CHAT_MSG_ACHIEVEMENT, LANG_ACHIEVEMENT_EARNED,achievement->ID);
        Trinity::LocalizedPacketDo<Trinity::AchievementChatBuilder> say_do(say_builder);
        Trinity::PlayerDistWorker<Trinity::LocalizedPacketDo<Trinity::AchievementChatBuilder> > say_worker(GetPlayer(),sWorld.getConfig(CONFIG_LISTEN_RANGE_SAY),say_do);
        TypeContainerVisitor<Trinity::PlayerDistWorker<Trinity::LocalizedPacketDo<Trinity::AchievementChatBuilder> >, WorldTypeMapContainer > message(say_worker);
        cell.Visit(p, message, *GetPlayer()->GetMap(), *GetPlayer(), sWorld.getConfig(CONFIG_LISTEN_RANGE_SAY));
    }

    WorldPacket data(SMSG_ACHIEVEMENT_EARNED, 8+4+8);
    data.append(GetPlayer()->GetPackGUID());
    data << uint32(achievement->ID);
    data << uint32(secsToTimeBitFields(time(NULL)));
    data << uint32(0);
    GetPlayer()->SendMessageToSetInRange(&data, sWorld.getConfig(CONFIG_LISTEN_RANGE_SAY), true);
}

void AchievementMgr::SendCriteriaUpdate(uint32 id, CriteriaProgress const* progress)
{
    WorldPacket data(SMSG_CRITERIA_UPDATE, 8+4+8);
    data << uint32(id);

    // the counter is packed like a packed Guid
    data.appendPackGUID(progress->counter);

    data.append(GetPlayer()->GetPackGUID());
    data << uint32(0);
    data << uint32(secsToTimeBitFields(progress->date));
    data << uint32(0);  // timer 1
    data << uint32(0);  // timer 2
    GetPlayer()->SendDirectMessage(&data);
}

/**
 * called at player login. The player might have fulfilled some achievements when the achievement system wasn't working yet
 */
void AchievementMgr::CheckAllAchievementCriteria()
{
    // suppress sending packets
    for (uint32 i=0; i<ACHIEVEMENT_CRITERIA_TYPE_TOTAL; ++i)
        UpdateAchievementCriteria(AchievementCriteriaTypes(i));
}

static const uint32 achievIdByArenaSlot[MAX_ARENA_SLOT] = { 1057, 1107, 1108 };
static const uint32 achievIdForDangeon[][4] =
{
    // ach_cr_id,is_dungeon,is_raid,is_heroic_dungeon
    { 321,       true,      true,   true  },
    { 916,       false,     true,   false },
    { 917,       false,     true,   false },
    { 918,       true,      false,  false },
    { 2219,      false,     false,  true  },
    { 0,         false,     false,  false }
};

/**
 * this function will be called whenever the user might have done a criteria relevant action
 */
void AchievementMgr::UpdateAchievementCriteria(AchievementCriteriaTypes type, uint32 miscvalue1, uint32 miscvalue2, Unit *unit, uint32 time)
{
    if((sLog.getLogFilter() & LOG_FILTER_ACHIEVEMENT_UPDATES)==0)
        sLog.outDetail("AchievementMgr::UpdateAchievementCriteria(%u, %u, %u, %u)", type, miscvalue1, miscvalue2, time);

    if (!sWorld.getConfig(CONFIG_GM_ALLOW_ACHIEVEMENT_GAINS) && m_player->GetSession()->GetSecurity() > SEC_PLAYER)
        return;

    AchievementCriteriaEntryList const& achievementCriteriaList = achievementmgr.GetAchievementCriteriaByType(type);
    for (AchievementCriteriaEntryList::const_iterator i = achievementCriteriaList.begin(); i!=achievementCriteriaList.end(); ++i)
    {
        AchievementCriteriaEntry const *achievementCriteria = (*i);

        if (achievementCriteria->groupFlag & ACHIEVEMENT_CRITERIA_GROUP_NOT_IN_GROUP && GetPlayer()->GetGroup())
            continue;

        AchievementEntry const *achievement = sAchievementStore.LookupEntry(achievementCriteria->referredAchievement);
        if (!achievement)
            continue;

        if ((achievement->factionFlag == ACHIEVEMENT_FACTION_FLAG_HORDE    && GetPlayer()->GetTeam() != HORDE) ||
            (achievement->factionFlag == ACHIEVEMENT_FACTION_FLAG_ALLIANCE && GetPlayer()->GetTeam() != ALLIANCE))
            continue;

        // don't update already completed criteria
        if (IsCompletedCriteria(achievementCriteria,achievement))
            continue;

        switch (type)
        {
            // std. case: increment at 1
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST:
            case ACHIEVEMENT_CRITERIA_TYPE_NUMBER_OF_TALENT_RESETS:
            case ACHIEVEMENT_CRITERIA_TYPE_LOSE_DUEL:
            case ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED:
            case ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED:
            case ACHIEVEMENT_CRITERIA_TYPE_QUEST_ABANDONED:
            case ACHIEVEMENT_CRITERIA_TYPE_FLIGHT_PATHS_TAKEN:
            case ACHIEVEMENT_CRITERIA_TYPE_ACCEPTED_SUMMONINGS:
                // AchievementMgr::UpdateAchievementCriteria might also be called on login - skip in this case
                if(!miscvalue1)
                    continue;
                SetCriteriaProgress(achievementCriteria, 1, PROGRESS_ACCUMULATE);
                break;
            // std case: increment at miscvalue1
            case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_TALENTS:
            case ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_QUEST_REWARD:
            case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_TRAVELLING:
            case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_AT_BARBER:
            case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_MAIL:
            case ACHIEVEMENT_CRITERIA_TYPE_LOOT_MONEY:
            case ACHIEVEMENT_CRITERIA_TYPE_TOTAL_DAMAGE_RECEIVED:
            case ACHIEVEMENT_CRITERIA_TYPE_TOTAL_HEALING_RECEIVED:
                // AchievementMgr::UpdateAchievementCriteria might also be called on login - skip in this case
                if(!miscvalue1)
                    continue;
                SetCriteriaProgress(achievementCriteria, miscvalue1, PROGRESS_ACCUMULATE);
                break;
            // std case: high value at miscvalue1
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_AUCTION_BID:
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_AUCTION_SOLD: /* FIXME: for online player only currently */
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HIT_DEALT:
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HIT_RECEIVED:
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEAL_CASTED:
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEALING_RECEIVED:
                // AchievementMgr::UpdateAchievementCriteria might also be called on login - skip in this case
                if(!miscvalue1)
                    continue;
                SetCriteriaProgress(achievementCriteria, miscvalue1, PROGRESS_HIGHEST);
                break;

            // specialized cases

            case ACHIEVEMENT_CRITERIA_TYPE_WIN_BG:
            {
                // AchievementMgr::UpdateAchievementCriteria might also be called on login - skip in this case
                if (!miscvalue1)
                    continue;
                if (achievementCriteria->win_bg.bgMapID != GetPlayer()->GetMapId())
                    continue;

                if (achievementCriteria->win_bg.additionalRequirement1_type)
                {
                    // those requirements couldn't be found in the dbc
                    AchievementCriteriaDataSet const* data = achievementmgr.GetCriteriaDataSet(achievementCriteria);
                    if (!data || !data->Meets(GetPlayer(),unit))
                        continue;
                }
                // some hardcoded requirements
                else
                {
                    BattleGround* bg = GetPlayer()->GetBattleGround();
                    if (!bg)
                        continue;

                    switch(achievementCriteria->referredAchievement)
                    {
                        case 161:                           // AB, Overcome a 500 resource disadvantage
                        {
                            if (bg->GetTypeID() != BATTLEGROUND_AB)
                                continue;
                            if(!((BattleGroundAB*)bg)->IsTeamScores500Disadvantage(GetPlayer()->GetTeam()))
                                continue;
                            break;
                        }
                        case 156:                           // AB, win while controlling all 5 flags (all nodes)
                        case 784:                           // EY, win while holding 4 bases (all nodes)
                        {
                            if(!bg->IsAllNodesConrolledByTeam(GetPlayer()->GetTeam()))
                                continue;
                            break;
                        }
                        case 1762:                          // SA, win without losing any siege vehicles
                        case 2192:                          // SA, win without losing any siege vehicles
                            continue;                       // not implemented
                    }
                }

                SetCriteriaProgress(achievementCriteria, miscvalue1, PROGRESS_ACCUMULATE);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE:
            {
                // AchievementMgr::UpdateAchievementCriteria might also be called on login - skip in this case
                if(!miscvalue1)
                    continue;
                if(achievementCriteria->kill_creature.creatureID != miscvalue1)
                    continue;

                // those requirements couldn't be found in the dbc
                AchievementCriteriaDataSet const* data = achievementmgr.GetCriteriaDataSet(achievementCriteria);
                if(!data || !data->Meets(GetPlayer(),unit))
                    continue;

                SetCriteriaProgress(achievementCriteria, miscvalue2, PROGRESS_ACCUMULATE);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_REACH_LEVEL:
                SetCriteriaProgress(achievementCriteria, GetPlayer()->getLevel());
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_REACH_SKILL_LEVEL:
                // update at loading or specific skill update
                if(miscvalue1 && miscvalue1 != achievementCriteria->reach_skill_level.skillID)
                    continue;
                if(uint32 skillvalue = GetPlayer()->GetBaseSkillValue(achievementCriteria->reach_skill_level.skillID))
                    SetCriteriaProgress(achievementCriteria, skillvalue);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LEVEL:
                // update at loading or specific skill update
                if(miscvalue1 && miscvalue1 != achievementCriteria->learn_skill_level.skillID)
                    continue;
                if(uint32 maxSkillvalue = GetPlayer()->GetPureMaxSkillValue(achievementCriteria->learn_skill_level.skillID))
                    SetCriteriaProgress(achievementCriteria, maxSkillvalue);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_ACHIEVEMENT:
                if(m_completedAchievements.find(achievementCriteria->complete_achievement.linkedAchievement) != m_completedAchievements.end())
                    SetCriteriaProgress(achievementCriteria, 1);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST_COUNT:
            {
                uint32 counter =0;
                for (QuestStatusMap::const_iterator itr = GetPlayer()->getQuestStatusMap().begin(); itr!=GetPlayer()->getQuestStatusMap().end(); itr++)
                    if(itr->second.m_rewarded)
                        counter++;
                SetCriteriaProgress(achievementCriteria, counter);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUESTS_IN_ZONE:
            {
                // speedup for non-login case
                if(miscvalue1 && miscvalue1 != achievementCriteria->complete_quests_in_zone.zoneID)
                    continue;

                uint32 counter =0;
                for (QuestStatusMap::const_iterator itr = GetPlayer()->getQuestStatusMap().begin(); itr!=GetPlayer()->getQuestStatusMap().end(); itr++)
                {
                    Quest const* quest = objmgr.GetQuestTemplate(itr->first);
                    if(itr->second.m_rewarded && quest && quest->GetZoneOrSort() >= 0 && uint32(quest->GetZoneOrSort()) == achievementCriteria->complete_quests_in_zone.zoneID)
                        counter++;
                }
                SetCriteriaProgress(achievementCriteria, counter);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_BATTLEGROUND:
                // AchievementMgr::UpdateAchievementCriteria might also be called on login - skip in this case
                if(!miscvalue1)
                    continue;
                if(GetPlayer()->GetMapId() != achievementCriteria->complete_battleground.mapID)
                    continue;
                SetCriteriaProgress(achievementCriteria, miscvalue1, PROGRESS_ACCUMULATE);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_DEATH_AT_MAP:
                // AchievementMgr::UpdateAchievementCriteria might also be called on login - skip in this case
                if(!miscvalue1)
                    continue;
                if(GetPlayer()->GetMapId() != achievementCriteria->death_at_map.mapID)
                    continue;
                SetCriteriaProgress(achievementCriteria, 1, PROGRESS_ACCUMULATE);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_DEATH:
            {
                // AchievementMgr::UpdateAchievementCriteria might also be called on login - skip in this case
                if(!miscvalue1)
                    continue;
                // skip wrong arena achievements, if not achievIdByArenaSlot then normal total death counter
                bool notfit = false;
                for (int j = 0; j < MAX_ARENA_SLOT; ++j)
                {
                    if(achievIdByArenaSlot[j] == achievement->ID)
                    {
                        BattleGround* bg = GetPlayer()->GetBattleGround();
                        if(!bg || !bg->isArena() || ArenaTeam::GetSlotByType(bg->GetArenaType()) != j)
                            notfit = true;

                        break;
                    }
                }
                if(notfit)
                    continue;

                SetCriteriaProgress(achievementCriteria, 1, PROGRESS_ACCUMULATE);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_DEATH_IN_DUNGEON:
            {
                // AchievementMgr::UpdateAchievementCriteria might also be called on login - skip in this case
                if(!miscvalue1)
                    continue;

                Map const* map = GetPlayer()->IsInWorld() ? GetPlayer()->GetMap() : MapManager::Instance().FindMap(GetPlayer()->GetMapId(), GetPlayer()->GetInstanceId());
                if(!map || !map->IsDungeon())
                    continue;

                // search case
                bool found = false;
                for (int j = 0; achievIdForDangeon[j][0]; ++j)
                {
                    if(achievIdForDangeon[j][0] == achievement->ID)
                    {
                        if(map->IsRaid())
                        {
                            // if raid accepted (ignore difficulty)
                            if(!achievIdForDangeon[j][2])
                                break;                      // for
                        }
                        else if(GetPlayer()->GetDungeonDifficulty()==DUNGEON_DIFFICULTY_NORMAL)
                        {
                            // dungeon in normal mode accepted
                            if(!achievIdForDangeon[j][1])
                                break;                      // for
                        }
                        else
                        {
                            // dungeon in heroic mode accepted
                            if(!achievIdForDangeon[j][3])
                                break;                      // for
                        }

                        found = true;
                        break;                              // for
                    }
                }
                if(!found)
                    continue;

                //FIXME: work only for instances where max==min for players
                if(((InstanceMap*)map)->GetMaxPlayers() != achievementCriteria->death_in_dungeon.manLimit)
                    continue;
                SetCriteriaProgress(achievementCriteria, 1, PROGRESS_ACCUMULATE);
                break;

            }
            case ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_CREATURE:
                // AchievementMgr::UpdateAchievementCriteria might also be called on login - skip in this case
                if(!miscvalue1)
                    continue;
                if(miscvalue1 != achievementCriteria->killed_by_creature.creatureEntry)
                    continue;
                SetCriteriaProgress(achievementCriteria, 1, PROGRESS_ACCUMULATE);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_PLAYER:
                // AchievementMgr::UpdateAchievementCriteria might also be called on login - skip in this case
                if(!miscvalue1)
                    continue;

                // if team check required: must kill by opposition faction
                if(achievement->ID==318 && miscvalue2==GetPlayer()->GetTeam())
                    continue;

                SetCriteriaProgress(achievementCriteria, 1, PROGRESS_ACCUMULATE);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_FALL_WITHOUT_DYING:
            {
                // AchievementMgr::UpdateAchievementCriteria might also be called on login - skip in this case
                if(!miscvalue1)
                    continue;

                // those requirements couldn't be found in the dbc
                AchievementCriteriaDataSet const* data = achievementmgr.GetCriteriaDataSet(achievementCriteria);
                if(!data || !data->Meets(GetPlayer(),unit))
                    continue;

                // miscvalue1 is the ingame fallheight*100 as stored in dbc
                SetCriteriaProgress(achievementCriteria, miscvalue1);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_DEATHS_FROM:
                // AchievementMgr::UpdateAchievementCriteria might also be called on login - skip in this case
                if(!miscvalue1)
                    continue;
                if(miscvalue2 != achievementCriteria->death_from.type)
                    continue;
                SetCriteriaProgress(achievementCriteria, 1, PROGRESS_ACCUMULATE);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST:
            {
                // if miscvalues != 0, it contains the questID.
                if (miscvalue1)
                {
                    if (miscvalue1 != achievementCriteria->complete_quest.questID)
                        continue;
                }
                else
                {
                    // login case.
                    if(!GetPlayer()->GetQuestRewardStatus(achievementCriteria->complete_quest.questID))
                        continue;
                }

                // exist many achievements with this criteria, use at this moment hardcoded check to skil simple case
                switch(achievement->ID)
                {
                    case 31:
                    case 1275:
                    case 1276:
                    case 1277:
                    case 1282:
                    case 1789:
                    {
                        // those requirements couldn't be found in the dbc
                        AchievementCriteriaDataSet const* data = achievementmgr.GetCriteriaDataSet(achievementCriteria);
                        if(!data || !data->Meets(GetPlayer(),unit))
                            continue;
                        break;
                    }
                    default:
                        break;
                }

                SetCriteriaProgress(achievementCriteria, 1);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET:
            case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2:
            {
                if (!miscvalue1 || miscvalue1 != achievementCriteria->be_spell_target.spellID)
                    continue;

                // those requirements couldn't be found in the dbc
                AchievementCriteriaDataSet const* data = achievementmgr.GetCriteriaDataSet(achievementCriteria);
                if(!data)
                    continue;

                if(!data->Meets(GetPlayer(),unit))
                    continue;

                SetCriteriaProgress(achievementCriteria, 1, PROGRESS_ACCUMULATE);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL:
            case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL2:
            {
                if (!miscvalue1 || miscvalue1 != achievementCriteria->cast_spell.spellID)
                    continue;

                // those requirements couldn't be found in the dbc
                AchievementCriteriaDataSet const* data = achievementmgr.GetCriteriaDataSet(achievementCriteria);
                if(!data)
                    continue;

                if(!data->Meets(GetPlayer(),unit))
                    continue;

                SetCriteriaProgress(achievementCriteria, 1, PROGRESS_ACCUMULATE);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SPELL:
                if(miscvalue1 && miscvalue1!=achievementCriteria->learn_spell.spellID)
                    continue;

                if(GetPlayer()->HasSpell(achievementCriteria->learn_spell.spellID))
                    SetCriteriaProgress(achievementCriteria, 1);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_LOOT_TYPE:
            {
                // miscvalue1=loot_type (note: 0 = LOOT_CORSPE and then it ignored)
                // miscvalue2=count of item loot
                if (!miscvalue1 || !miscvalue2)
                    continue;
                if (miscvalue1 != achievementCriteria->loot_type.lootType)
                    continue;

                // zone specific
                if(achievementCriteria->loot_type.lootTypeCount==1)
                {
                    // those requirements couldn't be found in the dbc
                    AchievementCriteriaDataSet const* data = achievementmgr.GetCriteriaDataSet(achievementCriteria);
                    if(!data || !data->Meets(GetPlayer(),unit))
                        continue;
                }

                SetCriteriaProgress(achievementCriteria, miscvalue2, PROGRESS_ACCUMULATE);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_OWN_ITEM:
                // speedup for non-login case
                if(miscvalue1 && achievementCriteria->own_item.itemID != miscvalue1)
                    continue;
                SetCriteriaProgress(achievementCriteria, GetPlayer()->GetItemCount(achievementCriteria->own_item.itemID, true));
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_ARENA:
                // miscvalue1 contains the personal rating
                if (!miscvalue1)                            // no update at login
                    continue;

                // additional requirements
                if(achievementCriteria->win_rated_arena.flag==ACHIEVEMENT_CRITERIA_CONDITION_NO_LOOSE)
                {
                    // those requirements couldn't be found in the dbc
                    AchievementCriteriaDataSet const* data = achievementmgr.GetCriteriaDataSet(achievementCriteria);
                    if(!data || !data->Meets(GetPlayer(),unit,miscvalue1))
                    {
                        // reset the progress as we have a win without the requirement.
                        SetCriteriaProgress(achievementCriteria, 0);
                        continue;
                    }
                }

                SetCriteriaProgress(achievementCriteria, 1, PROGRESS_ACCUMULATE);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_USE_ITEM:
                // AchievementMgr::UpdateAchievementCriteria might also be called on login - skip in this case
                if(!miscvalue1)
                    continue;
                if(achievementCriteria->use_item.itemID != miscvalue1)
                    continue;
                SetCriteriaProgress(achievementCriteria, 1, PROGRESS_ACCUMULATE);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_LOOT_ITEM:
                // You _have_ to loot that item, just owning it when logging in does _not_ count!
                if(!miscvalue1)
                    continue;
                if(miscvalue1 != achievementCriteria->own_item.itemID)
                    continue;
                SetCriteriaProgress(achievementCriteria, miscvalue2, PROGRESS_ACCUMULATE);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_EXPLORE_AREA:
            {
                WorldMapOverlayEntry const* worldOverlayEntry = sWorldMapOverlayStore.LookupEntry(achievementCriteria->explore_area.areaReference);
                if(!worldOverlayEntry)
                    break;

                bool matchFound = false;
                for (int j = 0; j < MAX_WORLD_MAP_OVERLAY_AREA_IDX; ++j)
                {
                    uint32 area_id = worldOverlayEntry->areatableID[j];
                    if(!area_id)                            // array have 0 only in empty tail
                        break;

                    int32 exploreFlag = GetAreaFlagByAreaID(area_id);
                    if(exploreFlag < 0)
                        continue;

                    uint32 playerIndexOffset = uint32(exploreFlag) / 32;
                    uint32 mask = 1<< (uint32(exploreFlag) % 32);

                    if(GetPlayer()->GetUInt32Value(PLAYER_EXPLORED_ZONES_1 + playerIndexOffset) & mask)
                    {
                        matchFound = true;
                        break;
                    }
                }

                if(matchFound)
                    SetCriteriaProgress(achievementCriteria, 1);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_BUY_BANK_SLOT:
                SetCriteriaProgress(achievementCriteria, GetPlayer()->GetBankBagSlotCount());
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_GAIN_REPUTATION:
            {
                // skip faction check only at loading
                if (miscvalue1 && miscvalue1 != achievementCriteria->gain_reputation.factionID)
                    continue;

                int32 reputation = GetPlayer()->GetReputationMgr().GetReputation(achievementCriteria->gain_reputation.factionID);
                if (reputation > 0)
                    SetCriteriaProgress(achievementCriteria, reputation);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_GAIN_EXALTED_REPUTATION:
            {
                SetCriteriaProgress(achievementCriteria, GetPlayer()->GetReputationMgr().GetExaltedFactionCount());
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_VISIT_BARBER_SHOP:
            {
                // skip for login case
                if(!miscvalue1)
                    continue;
                SetCriteriaProgress(achievementCriteria, 1);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_EQUIP_EPIC_ITEM:
            {
                // miscvalue1 = itemid
                // miscvalue2 = itemSlot
                if (!miscvalue1)
                    continue;

                if (miscvalue2 != achievementCriteria->equip_epic_item.itemSlot)
                    continue;

                ItemPrototype const *pProto = objmgr.GetItemPrototype(miscvalue1);
                if (!pProto || pProto->Quality != ITEM_QUALITY_EPIC)
                    continue;

                // check item level via achievement_criteria_data
                AchievementCriteriaDataSet const* data = achievementmgr.GetCriteriaDataSet(achievementCriteria);
                if (!data || !data->Meets(GetPlayer(), 0, pProto->ItemLevel))
                    continue;

                SetCriteriaProgress(achievementCriteria, 1);
                break;
            }

            case ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED_ON_LOOT:
            case ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED_ON_LOOT:
            {
                // miscvalue1 = itemid
                // miscvalue2 = diced value
                if (!miscvalue1)
                    continue;
                if (miscvalue2 != achievementCriteria->roll_greed_on_loot.rollValue)
                    continue;

                ItemPrototype const *pProto = objmgr.GetItemPrototype(miscvalue1);
                if (!pProto)
                    continue;

                // check item level via achievement_criteria_data
                AchievementCriteriaDataSet const* data = achievementmgr.GetCriteriaDataSet(achievementCriteria);
                if (!data || !data->Meets(GetPlayer(), 0, pProto->ItemLevel))
                    continue;

                SetCriteriaProgress(achievementCriteria, 1, PROGRESS_ACCUMULATE);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_DO_EMOTE:
            {
                // miscvalue1 = emote
                if(!miscvalue1)
                    continue;
                if(miscvalue1 != achievementCriteria->do_emote.emoteID)
                    continue;
                if(achievementCriteria->do_emote.count)
                {
                    // those requirements couldn't be found in the dbc
                    AchievementCriteriaDataSet const* data = achievementmgr.GetCriteriaDataSet(achievementCriteria);
                    if(!data || !data->Meets(GetPlayer(),unit))
                        continue;
                }

                SetCriteriaProgress(achievementCriteria, 1, PROGRESS_ACCUMULATE);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_DAMAGE_DONE:
            case ACHIEVEMENT_CRITERIA_TYPE_HEALING_DONE:
            {
                if (!miscvalue1)
                    continue;

                if (achievementCriteria->healing_done.flag == ACHIEVEMENT_CRITERIA_CONDITION_MAP)
                {
                    if(GetPlayer()->GetMapId() != achievementCriteria->healing_done.mapid)
                        continue;

                    // map specific case (BG in fact) expected player targeted damage/heal
                    if(!unit || unit->GetTypeId() != TYPEID_PLAYER)
                        continue;
                }

                SetCriteriaProgress(achievementCriteria, miscvalue1, PROGRESS_ACCUMULATE);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_EQUIP_ITEM:
                // miscvalue1 = item_id
                if (!miscvalue1)
                    continue;
                if (miscvalue1 != achievementCriteria->equip_item.itemID)
                    continue;

                SetCriteriaProgress(achievementCriteria, 1);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_USE_GAMEOBJECT:
                // miscvalue1 = go entry
                if (!miscvalue1)
                    continue;
                if (miscvalue1 != achievementCriteria->use_gameobject.goEntry)
                    continue;

                SetCriteriaProgress(achievementCriteria, 1, PROGRESS_ACCUMULATE);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_FISH_IN_GAMEOBJECT:
                if (!miscvalue1)
                    continue;
                if (miscvalue1 != achievementCriteria->fish_in_gameobject.goEntry)
                    continue;

                SetCriteriaProgress(achievementCriteria, 1, PROGRESS_ACCUMULATE);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILLLINE_SPELLS:
            {
                if (miscvalue1 && miscvalue1 != achievementCriteria->learn_skillline_spell.skillLine)
                    continue;

                uint32 spellCount = 0;
                for (PlayerSpellMap::const_iterator spellIter = GetPlayer()->GetSpellMap().begin();
                    spellIter != GetPlayer()->GetSpellMap().end();
                    ++spellIter)
                {
                    SkillLineAbilityMapBounds bounds = spellmgr.GetSkillLineAbilityMapBounds(spellIter->first);
                    for (SkillLineAbilityMap::const_iterator skillIter = bounds.first; skillIter != bounds.second; ++skillIter)
                    {
                        if(skillIter->second->skillId == achievementCriteria->learn_skillline_spell.skillLine)
                            spellCount++;
                    }
                }
                SetCriteriaProgress(achievementCriteria, spellCount);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_WIN_DUEL:
                // AchievementMgr::UpdateAchievementCriteria might also be called on login - skip in this case
                if (!miscvalue1)
                    continue;

                if (achievementCriteria->win_duel.duelCount)
                {
                    // those requirements couldn't be found in the dbc
                    AchievementCriteriaDataSet const* data = achievementmgr.GetCriteriaDataSet(achievementCriteria);
                    if (!data)
                        continue;

                    if (!data->Meets(GetPlayer(),unit))
                        continue;
                }

                SetCriteriaProgress(achievementCriteria, 1, PROGRESS_ACCUMULATE);
                break;
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
                if (miscvalue1 && miscvalue1 != achievementCriteria->learn_skill_line.skillLine)
                    continue;

                uint32 spellCount = 0;
                for (PlayerSpellMap::const_iterator spellIter = GetPlayer()->GetSpellMap().begin();
                    spellIter != GetPlayer()->GetSpellMap().end();
                    ++spellIter)
                {
                    SkillLineAbilityMapBounds bounds = spellmgr.GetSkillLineAbilityMapBounds(spellIter->first);
                    for (SkillLineAbilityMap::const_iterator skillIter = bounds.first; skillIter != bounds.second; ++skillIter)
                        if (skillIter->second->skillId == achievementCriteria->learn_skill_line.skillLine)
                            spellCount++;
                }
                SetCriteriaProgress(achievementCriteria, spellCount);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_EARN_HONORABLE_KILL:
                SetCriteriaProgress(achievementCriteria, GetPlayer()->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS));
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_HK_CLASS:
                if (!miscvalue1 || miscvalue1 != achievementCriteria->hk_class.classID)
                    continue;

                SetCriteriaProgress(achievementCriteria, 1, PROGRESS_ACCUMULATE);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_HK_RACE:
                if (!miscvalue1 || miscvalue1 != achievementCriteria->hk_race.raceID)
                    continue;

                SetCriteriaProgress(achievementCriteria, 1, PROGRESS_ACCUMULATE);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_GOLD_VALUE_OWNED:
                SetCriteriaProgress(achievementCriteria, GetPlayer()->GetMoney(), PROGRESS_HIGHEST);
                break;
            // std case: not exist in DBC, not triggered in code as result
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEALTH:
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_SPELLPOWER:
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_ARMOR:
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_POWER:
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_STAT:
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_RATING:
                break;
            // FIXME: not triggered in code as result, need to implement
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST_DAILY:
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_RAID:
            case ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE:
            case ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL_AT_AREA:
            case ACHIEVEMENT_CRITERIA_TYPE_WIN_ARENA:
            case ACHIEVEMENT_CRITERIA_TYPE_PLAY_ARENA:
            case ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL:
            case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_TEAM_RATING:
            case ACHIEVEMENT_CRITERIA_TYPE_REACH_TEAM_RATING:
            case ACHIEVEMENT_CRITERIA_TYPE_OWN_RANK:
            case ACHIEVEMENT_CRITERIA_TYPE_GET_KILLING_BLOWS:
            case ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_VENDORS:
            case ACHIEVEMENT_CRITERIA_TYPE_SPECIAL_PVP_KILL:
            case ACHIEVEMENT_CRITERIA_TYPE_EARNED_PVP_TITLE:
            case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE_TYPE:
            case ACHIEVEMENT_CRITERIA_TYPE_GOLD_EARNED_BY_AUCTIONS:
            case ACHIEVEMENT_CRITERIA_TYPE_CREATE_AUCTION:
            case ACHIEVEMENT_CRITERIA_TYPE_WON_AUCTIONS:
            case ACHIEVEMENT_CRITERIA_TYPE_LOOT_EPIC_ITEM:
            case ACHIEVEMENT_CRITERIA_TYPE_RECEIVE_EPIC_ITEM:
            case ACHIEVEMENT_CRITERIA_TYPE_TOTAL:
                break;                                   // Not implemented yet :(
        }
        if(IsCompletedCriteria(achievementCriteria,achievement))
            CompletedCriteriaFor(achievement);

        // check again the completeness for SUMM and REQ COUNT achievements,
        // as they don't depend on the completed criteria but on the sum of the progress of each individual criteria
        if (achievement->flags & ACHIEVEMENT_FLAG_SUMM)
        {
            if (IsCompletedAchievement(achievement))
                CompletedAchievement(achievement);
        }

        if(AchievementEntryList const* achRefList = achievementmgr.GetAchievementByReferencedId(achievement->ID))
        {
            for (AchievementEntryList::const_iterator itr = achRefList->begin(); itr != achRefList->end(); ++itr)
                if(IsCompletedAchievement(*itr))
                    CompletedAchievement(*itr);
        }
    }
}

static const uint32 achievIdByClass[MAX_CLASSES] = { 0, 459, 465 , 462, 458, 464, 461, 467, 460, 463, 0, 466 };
static const uint32 achievIdByRace[MAX_RACES]    = { 0, 1408, 1410, 1407, 1409, 1413, 1411, 1404, 1412, 0, 1405, 1406 };

bool AchievementMgr::IsCompletedCriteria(AchievementCriteriaEntry const* achievementCriteria, AchievementEntry const* achievement)
{
    // counter can never complete
    if(achievement->flags & ACHIEVEMENT_FLAG_COUNTER)
        return false;

    if(achievement->flags & (ACHIEVEMENT_FLAG_REALM_FIRST_REACH | ACHIEVEMENT_FLAG_REALM_FIRST_KILL))
    {
        // someone on this realm has already completed that achievement
        if(achievementmgr.IsRealmCompleted(achievement))
            return false;
    }

    CriteriaProgressMap::const_iterator itr = m_criteriaProgress.find(achievementCriteria->ID);
    if(itr == m_criteriaProgress.end())
        return false;

    CriteriaProgress const* progress = &itr->second;

    switch(achievementCriteria->requiredType)
    {
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_BG:
            return progress->counter >= achievementCriteria->win_bg.winCount;
        case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE:
            return progress->counter >= achievementCriteria->kill_creature.creatureCount;
        case ACHIEVEMENT_CRITERIA_TYPE_REACH_LEVEL:
        {
            // skip wrong class achievements
            for (int i = 1; i < MAX_CLASSES; ++i)
                if(achievIdByClass[i] == achievement->ID && i != GetPlayer()->getClass())
                    return false;

            // skip wrong race achievements
            for (int i = 1; i < MAX_RACES; ++i)
                if(achievIdByRace[i] == achievement->ID && i != GetPlayer()->getRace())
                    return false;

            // appropriate class/race or not class/race specific
            return progress->counter >= achievementCriteria->reach_level.level;
        }
        case ACHIEVEMENT_CRITERIA_TYPE_REACH_SKILL_LEVEL:
            return progress->counter >= achievementCriteria->reach_skill_level.skillLevel;
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_ACHIEVEMENT:
            return progress->counter >= 1;
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST_COUNT:
            return progress->counter >= achievementCriteria->complete_quest_count.totalQuestCount;
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
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SPELL:
            return progress->counter >= 1;
        case ACHIEVEMENT_CRITERIA_TYPE_OWN_ITEM:
            return progress->counter >= achievementCriteria->own_item.itemCount;
        case ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_ARENA:
            return progress->counter >= achievementCriteria->win_rated_arena.count;
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
            return progress->counter >= 1;
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
        case ACHIEVEMENT_CRITERIA_TYPE_EARN_HONORABLE_KILL:
            return progress->counter >= achievementCriteria->honorable_kill.killCount;
        // handle all statistic-only criteria here
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_BATTLEGROUND:
        case ACHIEVEMENT_CRITERIA_TYPE_DEATH_AT_MAP:
        case ACHIEVEMENT_CRITERIA_TYPE_DEATH:
        case ACHIEVEMENT_CRITERIA_TYPE_DEATH_IN_DUNGEON:
        case ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_CREATURE:
        case ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_PLAYER:
        case ACHIEVEMENT_CRITERIA_TYPE_DEATHS_FROM:
        case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_TALENTS:
        case ACHIEVEMENT_CRITERIA_TYPE_NUMBER_OF_TALENT_RESETS:
        case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_AT_BARBER:
        case ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_MAIL:
        case ACHIEVEMENT_CRITERIA_TYPE_LOSE_DUEL:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_AUCTION_BID:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_AUCTION_SOLD:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_GOLD_VALUE_OWNED:
        case ACHIEVEMENT_CRITERIA_TYPE_GAIN_REVERED_REPUTATION:
        case ACHIEVEMENT_CRITERIA_TYPE_GAIN_HONORED_REPUTATION:
        case ACHIEVEMENT_CRITERIA_TYPE_KNOWN_FACTIONS:
        case ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED:
        case ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEALTH:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_SPELLPOWER:
        case ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_ARMOR:
        case ACHIEVEMENT_CRITERIA_TYPE_QUEST_ABANDONED:
        case ACHIEVEMENT_CRITERIA_TYPE_FLIGHT_PATHS_TAKEN:
        case ACHIEVEMENT_CRITERIA_TYPE_ACCEPTED_SUMMONINGS:
            return false;
    }
    return false;
}

void AchievementMgr::CompletedCriteriaFor(AchievementEntry const* achievement)
{
    // counter can never complete
    if(achievement->flags & ACHIEVEMENT_FLAG_COUNTER)
        return;

    // already completed and stored
    if (m_completedAchievements.find(achievement->ID)!=m_completedAchievements.end())
        return;

    if (IsCompletedAchievement(achievement))
        CompletedAchievement(achievement);
}

bool AchievementMgr::IsCompletedAchievement(AchievementEntry const* entry)
{
    // counter can never complete
    if(entry->flags & ACHIEVEMENT_FLAG_COUNTER)
        return false;

    // for achievement with referenced achievement criterias get from referenced and counter from self
    uint32 achievmentForTestId = entry->refAchievement ? entry->refAchievement : entry->ID;
    uint32 achievmentForTestCount = entry->count;

    AchievementCriteriaEntryList const* cList = achievementmgr.GetAchievementCriteriaByAchievement(achievmentForTestId);
    if(!cList)
        return false;
    uint32 count = 0;

    // For SUMM achievements, we have to count the progress of each criteria of the achievement.
    // Oddly, the target count is NOT countained in the achievement, but in each individual criteria
    if (entry->flags & ACHIEVEMENT_FLAG_SUMM)
    {
        for (AchievementCriteriaEntryList::const_iterator itr = cList->begin(); itr != cList->end(); ++itr)
        {
            AchievementCriteriaEntry const* criteria = *itr;

            CriteriaProgressMap::const_iterator itrProgress = m_criteriaProgress.find(criteria->ID);
            if(itrProgress == m_criteriaProgress.end())
                continue;

            CriteriaProgress const* progress = &itrProgress->second;
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

        bool completed = IsCompletedCriteria(criteria,entry);

        // found an uncompleted criteria, but DONT return false yet - there might be a completed criteria with ACHIEVEMENT_CRITERIA_COMPLETE_FLAG_ALL
        if(completed)
            ++count;
        else
            completed_all = false;

        // completed as have req. count of completed criterias
        if(achievmentForTestCount > 0 && achievmentForTestCount <= count)
           return true;
    }

    // all criterias completed requirement
    if(completed_all && achievmentForTestCount==0)
        return true;

    return false;
}

void AchievementMgr::SetCriteriaProgress(AchievementCriteriaEntry const* entry, uint32 changeValue, ProgressType ptype)
{
    if((sLog.getLogFilter() & LOG_FILTER_ACHIEVEMENT_UPDATES)==0)
        sLog.outDetail("AchievementMgr::SetCriteriaProgress(%u, %u) for (GUID:%u)", entry->ID, changeValue, m_player->GetGUIDLow());

    CriteriaProgress *progress = NULL;

    CriteriaProgressMap::iterator iter = m_criteriaProgress.find(entry->ID);

    if(iter == m_criteriaProgress.end())
    {
        // not create record for 0 counter
        if(changeValue == 0)
            return;

        progress = &m_criteriaProgress[entry->ID];
        progress->counter = changeValue;
        progress->date = time(NULL);
    }
    else
    {
        progress = &iter->second;

        uint32 newValue = 0;
        switch(ptype)
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
        if(progress->counter == newValue)
            return;

        progress->counter = newValue;
    }

    progress->changed = true;

    if(entry->timeLimit)
    {
        time_t now = time(NULL);
        if(time_t(progress->date + entry->timeLimit) < now)
            progress->counter = 1;

        // also it seems illogical, the timeframe will be extended at every criteria update
        progress->date = now;
    }
    SendCriteriaUpdate(entry->ID,progress);
}

void AchievementMgr::CompletedAchievement(AchievementEntry const* achievement)
{
    sLog.outDetail("AchievementMgr::CompletedAchievement(%u)", achievement->ID);

    if(!sWorld.getConfig(CONFIG_GM_ALLOW_ACHIEVEMENT_GAINS) && m_player->GetSession()->GetSecurity() > SEC_PLAYER)
        return;

    if(achievement->flags & ACHIEVEMENT_FLAG_COUNTER || m_completedAchievements.find(achievement->ID)!=m_completedAchievements.end())
        return;

    SendAchievementEarned(achievement);
    CompletedAchievementData& ca =  m_completedAchievements[achievement->ID];
    ca.date = time(NULL);
    ca.changed = true;

    // don't insert for ACHIEVEMENT_FLAG_REALM_FIRST_KILL since otherwise only the first group member would reach that achievement
    // TODO: where do set this instead?
    if(!(achievement->flags & ACHIEVEMENT_FLAG_REALM_FIRST_KILL))
        achievementmgr.SetRealmCompleted(achievement);

    UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_ACHIEVEMENT);

    // reward items and titles if any
    AchievementReward const* reward = achievementmgr.GetAchievementReward(achievement);

    // no rewards
    if(!reward)
        return;

    // titles
    if(uint32 titleId = reward->titleId[GetPlayer()->GetTeam() == HORDE ? 0 : 1])
    {
        if(CharTitlesEntry const* titleEntry = sCharTitlesStore.LookupEntry(titleId))
            GetPlayer()->SetTitle(titleEntry);
    }

    // mail
    if(reward->sender)
    {
        Item* item = reward->itemId ? Item::CreateItem(reward->itemId,1,GetPlayer ()) : NULL;

        int loc_idx = GetPlayer()->GetSession()->GetSessionDbLocaleIndex();

        // subject and text
        std::string subject = reward->subject;
        std::string text = reward->text;
        if ( loc_idx >= 0 )
        {
            if(AchievementRewardLocale const* loc = achievementmgr.GetAchievementRewardLocale(achievement))
            {
                if (loc->subject.size() > size_t(loc_idx) && !loc->subject[loc_idx].empty())
                    subject = loc->subject[loc_idx];
                if (loc->text.size() > size_t(loc_idx) && !loc->text[loc_idx].empty())
                    text = loc->text[loc_idx];
            }
        }

        uint32 itemTextId = objmgr.CreateItemText( text );

        MailDraft draft(subject, itemTextId);

        if(item)
        {
            // save new item before send
            item->SaveToDB();                               // save for prevent lost at next mail load, if send fail then item will deleted

            // item
            draft.AddItem(item);
        }

        draft.SendMailTo(GetPlayer(), MailSender(MAIL_CREATURE, reward->sender));
    }
}

void AchievementMgr::SendAllAchievementData()
{
    uint32 size = 18 + m_completedAchievements.size()*8 + m_criteriaProgress.size() * 36;

    bool send = false;

    WorldPacket data(SMSG_ALL_ACHIEVEMENT_DATA);
    if( size < 0x8000 )
        data.resize( size );
    else
        data.resize( 0x7fff );
        // More than this causes client trouble

    CompletedAchievementMap::const_iterator iter = m_completedAchievements.begin();
    CriteriaProgressMap::const_iterator iter2 = m_criteriaProgress.begin();

    bool cAchievements = false;
    bool cProgress = false;
    while( !cAchievements || !cProgress )
    {
        data.clear();
        send = false;

        if( !cAchievements )
        {
            for (; iter != m_completedAchievements.end() && !send; ++iter)
            {
                data << uint32(iter->first);
                data << uint32(secsToTimeBitFields(iter->second.date));
                send = data.size() > 0x7f00;
            }

            if( iter == m_completedAchievements.end() )
                cAchievements = true;
        }

        data << int32(-1);
        for (; iter2 != m_criteriaProgress.end() && !send; ++iter2)
        {
            data << uint32(iter2->first);
            data.appendPackGUID(iter2->second.counter);
            data.append(GetPlayer()->GetPackGUID());
            data << uint32(0);
            data << uint32(secsToTimeBitFields(iter2->second.date));
            data << uint32(0);
            data << uint32(0);
            send = data.size() > 0x7f00;
        }

        if( iter2 == m_criteriaProgress.end() )
            cProgress = true;

        data << int32(-1);
        GetPlayer()->GetSession()->SendPacket(&data);
    }
}

void AchievementMgr::SendRespondInspectAchievements(Player* player)
{
    // since we don't know the exact size of the packed GUIDs this is just an approximation
    WorldPacket data(SMSG_RESPOND_INSPECT_ACHIEVEMENTS, 4+4*2+m_completedAchievements.size()*4*2+m_completedAchievements.size()*7*4);
    data.append(GetPlayer()->GetPackGUID());
    BuildAllDataPacket(&data);
    player->GetSession()->SendPacket(&data);
}

/**
 * used by SMSG_RESPOND_INSPECT_ACHIEVEMENT
 */
void AchievementMgr::BuildAllDataPacket(WorldPacket *data)
{
    for (CompletedAchievementMap::const_iterator iter = m_completedAchievements.begin(); iter!=m_completedAchievements.end(); ++iter)
    {
        *data << uint32(iter->first);
        *data << uint32(secsToTimeBitFields(iter->second.date));
    }
    *data << int32(-1);

    for (CriteriaProgressMap::const_iterator iter = m_criteriaProgress.begin(); iter!=m_criteriaProgress.end(); ++iter)
    {
        *data << uint32(iter->first);
        data->appendPackGUID(iter->second.counter);
        data->append(GetPlayer()->GetPackGUID());
        *data << uint32(0);
        *data << uint32(secsToTimeBitFields(iter->second.date));
        *data << uint32(0);
        *data << uint32(0);
    }

    *data << int32(-1);
}

//==========================================================
AchievementCriteriaEntryList const& AchievementGlobalMgr::GetAchievementCriteriaByType(AchievementCriteriaTypes type)
{
    return m_AchievementCriteriasByType[type];
}

void AchievementGlobalMgr::LoadAchievementCriteriaList()
{
    if(sAchievementCriteriaStore.GetNumRows()==0)
    {
        barGoLink bar(1);
        bar.step();

        sLog.outString();
        sLog.outErrorDb(">> Loaded 0 achievement criteria.");
        return;
    }

    barGoLink bar( sAchievementCriteriaStore.GetNumRows() );
    for (uint32 entryId = 0; entryId < sAchievementCriteriaStore.GetNumRows(); ++entryId)
    {
        bar.step();

        AchievementCriteriaEntry const* criteria = sAchievementCriteriaStore.LookupEntry(entryId);
        if(!criteria)
            continue;

        m_AchievementCriteriasByType[criteria->requiredType].push_back(criteria);
        m_AchievementCriteriaListByAchievement[criteria->referredAchievement].push_back(criteria);
    }

    sLog.outString();
    sLog.outString(">> Loaded %lu achievement criteria.",(unsigned long)m_AchievementCriteriasByType->size());
}

void AchievementGlobalMgr::LoadAchievementReferenceList()
{
    if(sAchievementStore.GetNumRows()==0)
    {
        barGoLink bar(1);
        bar.step();

        sLog.outString();
        sLog.outErrorDb(">> Loaded 0 achievement references.");
        return;
    }

    uint32 count = 0;
    barGoLink bar( sAchievementStore.GetNumRows() );
    for (uint32 entryId = 0; entryId < sAchievementStore.GetNumRows(); ++entryId)
    {
        bar.step();

        AchievementEntry const* achievement = sAchievementStore.LookupEntry(entryId);
        if(!achievement || !achievement->refAchievement)
            continue;

        m_AchievementListByReferencedId[achievement->refAchievement].push_back(achievement);
        ++count;
    }

    sLog.outString();
    sLog.outString(">> Loaded %u achievement references.",count);
}

void AchievementGlobalMgr::LoadAchievementCriteriaData()
{
    m_criteriaDataMap.clear();                              // need for reload case

    QueryResult_AutoPtr result = WorldDatabase.Query("SELECT criteria_id, type, value1, value2 FROM achievement_criteria_data");

    if(!result)
    {
        barGoLink bar(1);
        bar.step();

        sLog.outString();
        sLog.outString(">> Loaded 0 additional achievement criteria data. DB table `achievement_criteria_data` is empty.");
        return;
    }

    uint32 count = 0;
    uint32 disabled_count = 0;
    barGoLink bar(result->GetRowCount());
    do
    {
        bar.step();
        Field *fields = result->Fetch();
        uint32 criteria_id = fields[0].GetUInt32();

        AchievementCriteriaEntry const* criteria = sAchievementCriteriaStore.LookupEntry(criteria_id);

        if (!criteria)
        {
            sLog.outErrorDb( "Table `achievement_criteria_data` have data for not existed criteria (Entry: %u), ignore.", criteria_id);
            continue;
        }

        AchievementCriteriaData data(fields[1].GetUInt32(),fields[2].GetUInt32(),fields[3].GetUInt32());

        if (!data.IsValid(criteria))
        {
            continue;
        }

        // this will allocate empty data set storage
        AchievementCriteriaDataSet& dataSet = m_criteriaDataMap[criteria_id];
        dataSet.SetCriteriaId(criteria_id);

        if (data.dataType == ACHIEVEMENT_CRITERIA_DATA_TYPE_DISABLED)
            ++disabled_count;

        // add real data only for not NONE data types
        if (data.dataType != ACHIEVEMENT_CRITERIA_DATA_TYPE_NONE)
            dataSet.Add(data);

        // counting data by and data types
        ++count;
    } while(result->NextRow());

    // post loading checks
    for (uint32 entryId = 0; entryId < sAchievementCriteriaStore.GetNumRows(); ++entryId)
    {
        AchievementCriteriaEntry const* criteria = sAchievementCriteriaStore.LookupEntry(entryId);
        if(!criteria)
            continue;

        switch(criteria->requiredType)
        {
            case ACHIEVEMENT_CRITERIA_TYPE_WIN_BG:
                if(!criteria->win_bg.additionalRequirement1_type)
                    continue;
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE:
                break;                                      // any cases
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST:
            {
                AchievementEntry const* achievement = sAchievementStore.LookupEntry(criteria->referredAchievement);
                if(!achievement)
                    continue;

                // exist many achievements with this criteria, use at this moment hardcoded check to skil simple case
                switch(achievement->ID)
                {
                    case 31:
                    case 1275:
                    case 1276:
                    case 1277:
                    case 1282:
                    case 1789:
                        break;
                    default:
                        continue;
                }
            }
            case ACHIEVEMENT_CRITERIA_TYPE_FALL_WITHOUT_DYING:
                break;                                      // any cases
            case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL:      // any cases
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_ARENA: // need skip generic cases
                if(criteria->win_rated_arena.flag!=ACHIEVEMENT_CRITERIA_CONDITION_NO_LOOSE)
                    continue;
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_DO_EMOTE:        // need skip generic cases
                if(criteria->do_emote.count==0)
                    continue;
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_WIN_DUEL:        // skip statistics
                if(criteria->win_duel.duelCount==0)
                    continue;
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL2:     // any cases
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_LOOT_TYPE:       // need skip generic cases
                if(criteria->loot_type.lootTypeCount!=1)
                    continue;
                break;
            default:                                        // type not use DB data, ignore
                continue;
        }

        if(!GetCriteriaDataSet(criteria))
            sLog.outErrorDb( "Table `achievement_criteria_data` not have expected data for criteria (Entry: %u Type: %u) for achievement %u.", criteria->ID, criteria->requiredType, criteria->referredAchievement);
    }

    sLog.outString();
    sLog.outString(">> Loaded %u additional achievement criteria data (%u disabled).",count,disabled_count);
}

void AchievementGlobalMgr::LoadCompletedAchievements()
{
    QueryResult_AutoPtr result = CharacterDatabase.Query("SELECT achievement FROM character_achievement GROUP BY achievement");

    if(!result)
    {
        barGoLink bar(1);
        bar.step();

        sLog.outString();
        sLog.outString(">> Loaded 0 realm completed achievements . DB table `character_achievement` is empty.");
        return;
    }

    barGoLink bar(result->GetRowCount());
    do
    {
        bar.step();
        Field *fields = result->Fetch();

        uint32 achievement_id = fields[0].GetUInt32();
        if(!sAchievementStore.LookupEntry(achievement_id))
        {
            // we will remove not existed achievement for all characters
            sLog.outError("Not existed achievement %u data removed from table `character_achievement`.",achievement_id);
            CharacterDatabase.PExecute("DELETE FROM character_achievement WHERE achievement = %u",achievement_id);
            continue;
        }

        m_allCompletedAchievements.insert(achievement_id);
    } while(result->NextRow());

    sLog.outString();
    sLog.outString(">> Loaded %lu realm completed achievements.",(unsigned long)m_allCompletedAchievements.size());
}

void AchievementGlobalMgr::LoadRewards()
{
    m_achievementRewards.clear();                           // need for reload case

    //                                                0      1        2        3     4       5        6
    QueryResult_AutoPtr result = WorldDatabase.Query("SELECT entry, title_A, title_H, item, sender, subject, text FROM achievement_reward");

    if(!result)
    {
        barGoLink bar(1);

        bar.step();

        sLog.outString();
        sLog.outErrorDb(">> Loaded 0 achievement rewards. DB table `achievement_reward` is empty.");
        return;
    }

    uint32 count = 0;
    barGoLink bar(result->GetRowCount());

    do
    {
        bar.step();

        Field *fields = result->Fetch();
        uint32 entry = fields[0].GetUInt32();
        if (!sAchievementStore.LookupEntry(entry))
        {
            sLog.outErrorDb( "Table `achievement_reward` has wrong achievement (Entry: %u), ignore", entry);
            continue;
        }

        AchievementReward reward;
        reward.titleId[0] = fields[1].GetUInt32();
        reward.titleId[1] = fields[2].GetUInt32();
        reward.itemId     = fields[3].GetUInt32();
        reward.sender     = fields[4].GetUInt32();
        reward.subject    = fields[5].GetCppString();
        reward.text       = fields[6].GetCppString();

        if ((reward.titleId[0]==0)!=(reward.titleId[1]==0))
            sLog.outErrorDb( "Table `achievement_reward` (Entry: %u) has title (A: %u H: %u) only for one from teams.", entry, reward.titleId[0], reward.titleId[1]);

        // must be title or mail at least
        if (!reward.titleId[0] && !reward.titleId[1] && !reward.sender)
        {
            sLog.outErrorDb( "Table `achievement_reward` (Entry: %u) not have title or item reward data, ignore.", entry);
            continue;
        }

        if (reward.titleId[0])
        {
            CharTitlesEntry const* titleEntry = sCharTitlesStore.LookupEntry(reward.titleId[0]);
            if (!titleEntry)
            {
                sLog.outErrorDb( "Table `achievement_reward` (Entry: %u) has invalid title id (%u) in `title_A`, set to 0", entry, reward.titleId[0]);
                reward.titleId[0] = 0;
            }
        }

        if (reward.titleId[1])
        {
            CharTitlesEntry const* titleEntry = sCharTitlesStore.LookupEntry(reward.titleId[1]);
            if (!titleEntry)
            {
                sLog.outErrorDb( "Table `achievement_reward` (Entry: %u) has invalid title id (%u) in `title_A`, set to 0", entry, reward.titleId[1]);
                reward.titleId[1] = 0;
            }
        }

        //check mail data before item for report including wrong item case
        if (reward.sender)
        {
            if (!objmgr.GetCreatureTemplate(reward.sender))
            {
                sLog.outErrorDb( "Table `achievement_reward` (Entry: %u) has invalid creature entry %u as sender, mail reward skipped.", entry, reward.sender);
                reward.sender = 0;
            }
        }
        else
        {
            if (reward.itemId)
                sLog.outErrorDb( "Table `achievement_reward` (Entry: %u) not have sender data but have item reward, item will not rewarded", entry);

            if (!reward.subject.empty())
                sLog.outErrorDb( "Table `achievement_reward` (Entry: %u) not have sender data but have mail subject.", entry);

            if (!reward.text.empty())
                sLog.outErrorDb( "Table `achievement_reward` (Entry: %u) not have sender data but have mail text.", entry);
        }

        if (reward.itemId)
        {
            if (!objmgr.GetItemPrototype(reward.itemId))
            {
                sLog.outErrorDb( "Table `achievement_reward` (Entry: %u) has invalid item id %u, reward mail will be without item.", entry, reward.itemId);
                reward.itemId = 0;
            }
        }

        m_achievementRewards[entry] = reward;
        ++count;

    } while (result->NextRow());

    sLog.outString();
    sLog.outString( ">> Loaded %u achievement rewards", count );
}

void AchievementGlobalMgr::LoadRewardLocales()
{
    m_achievementRewardLocales.clear();                       // need for reload case

    QueryResult_AutoPtr result = WorldDatabase.Query("SELECT entry,subject_loc1,text_loc1,subject_loc2,text_loc2,subject_loc3,text_loc3,subject_loc4,text_loc4,subject_loc5,text_loc5,subject_loc6,text_loc6,subject_loc7,text_loc7,subject_loc8,text_loc8 FROM locales_achievement_reward");

    if (!result)
    {
        barGoLink bar(1);

        bar.step();

        sLog.outString();
        sLog.outString(">> Loaded 0 achievement reward locale strings.");
        sLog.outString(">> DB table `locales_achievement_reward` is empty.");
        return;
    }

    barGoLink bar(result->GetRowCount());

    do
    {
        Field *fields = result->Fetch();
        bar.step();

        uint32 entry = fields[0].GetUInt32();

        if(m_achievementRewards.find(entry)==m_achievementRewards.end())
        {
            sLog.outErrorDb( "Table `locales_achievement_reward` (Entry: %u) has locale strings for not existed achievement reward .", entry);
            continue;
        }

        AchievementRewardLocale& data = m_achievementRewardLocales[entry];

        for (int i = 1; i < MAX_LOCALE; ++i)
        {
            std::string str = fields[1+2*(i-1)].GetCppString();
            if(!str.empty())
            {
                int idx = objmgr.GetOrNewIndexForLocale(LocaleConstant(i));
                if(idx >= 0)
                {
                    if(data.subject.size() <= size_t(idx))
                        data.subject.resize(idx+1);

                    data.subject[idx] = str;
                }
            }
            str = fields[1+2*(i-1)+1].GetCppString();
            if(!str.empty())
            {
                int idx = objmgr.GetOrNewIndexForLocale(LocaleConstant(i));
                if(idx >= 0)
                {
                    if(data.text.size() <= size_t(idx))
                        data.text.resize(idx+1);

                    data.text[idx] = str;
                }
            }
        }
    } while (result->NextRow());

    sLog.outString();
    sLog.outString( ">> Loaded %lu achievement reward locale strings", (unsigned long)m_achievementRewardLocales.size() );
}
