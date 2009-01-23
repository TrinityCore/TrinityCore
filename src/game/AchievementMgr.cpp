/*
 * Copyright (C) 2005-2008 MaNGOS <http://getmangos.com/>
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

#include "AchievementMgr.h"
#include "Common.h"
#include "Player.h"
#include "WorldPacket.h"
#include "Database/DBCEnums.h"
#include "ObjectMgr.h"
#include "Guild.h"
#include "Database/DatabaseEnv.h"
#include "GameEvent.h"
#include "World.h"
#include "SpellMgr.h"
#include "ProgressBar.h"

#include "Policies/SingletonImp.h"

INSTANTIATE_SINGLETON_1(AchievementGlobalMgr);

const CriteriaCastSpellRequirement AchievementGlobalMgr::m_criteriaCastSpellRequirements[CRITERIA_CAST_SPELL_REQ_COUNT] =
    {
        {5272, 3057, 0, 0},
        {5273, 2784, 0, 0},
        {5752, 9099, 0, 0},
        {5753, 8403, 0, 0},
        {5772, 0, 0, RACE_GNOME},
        {5774, 0, 0, RACE_BLOODELF},
        {5775, 0, 0, RACE_DRAENEI},
        {5776, 0, 0, RACE_DWARF},
        {5777, 0, 0, RACE_HUMAN},
        {5778, 0, 0, RACE_NIGHTELF},
        {5779, 0, 0, RACE_ORC},
        {5780, 0, 0, RACE_TAUREN},
        {5781, 0, 0, RACE_TROLL},
        {5782, 0, 0, RACE_UNDEAD_PLAYER},
        {6225, 5661, 0, 0},
        {6226, 26044, 0, 0},
        {6228, 739, 0, 0},
        {6229, 927, 0, 0},
        {6230, 1444, 0, 0},
        {6231, 8140, 0, 0},
        {6232, 5489, 0, 0},
        {6233,12336, 0, 0},
        {6234, 1351, 0, 0},
        {6235, 5484, 0, 0},
        {6236, 1182, 0, 0},
        {6237, 0, CLASS_DEATH_KNIGHT, RACE_ORC},
        {6238, 0, CLASS_WARRIOR, RACE_HUMAN},
        {6239, 0, CLASS_SHAMAN, RACE_TAUREN},
        {6240, 0, CLASS_DRUID, RACE_NIGHTELF},
        {6241, 0, CLASS_ROGUE, RACE_UNDEAD_PLAYER},
        {6242, 0, CLASS_HUNTER, RACE_TROLL},
        {6243, 0, CLASS_MAGE, RACE_GNOME},
        {6244, 0, CLASS_PALADIN, RACE_DWARF},
        {6245, 0, CLASS_WARLOCK, RACE_BLOODELF},
        {6246, 0, CLASS_PRIEST, RACE_DRAENEI},
        {6312, 0, CLASS_WARLOCK, RACE_GNOME},
        {6313, 0, CLASS_DEATH_KNIGHT, RACE_HUMAN},
        {6314, 0, CLASS_PRIEST, RACE_NIGHTELF},
        {6315, 0, CLASS_SHAMAN, RACE_ORC},
        {6316, 0, CLASS_DRUID, RACE_TAUREN},
        {6317, 0, CLASS_ROGUE, RACE_TROLL},
        {6318, 0, CLASS_WARRIOR, RACE_UNDEAD_PLAYER},
        {6319, 0, CLASS_MAGE, RACE_BLOODELF},
        {6320, 0, CLASS_PALADIN, RACE_DRAENEI},
        {6321, 0, CLASS_HUNTER, RACE_DWARF},
        {6662, 31261, 0, 0}
    };

AchievementMgr::AchievementMgr(Player *player)
{
    m_player = player;
}

AchievementMgr::~AchievementMgr()
{
}

void AchievementMgr::SaveToDB()
{
    if(!m_completedAchievements.empty())
    {
        bool need_execute = false;
        std::ostringstream ssdel;
        std::ostringstream ssins;
        for(CompletedAchievementMap::iterator iter = m_completedAchievements.begin(); iter!=m_completedAchievements.end(); iter++)
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
            CharacterDatabase.BeginTransaction ();
            CharacterDatabase.Execute( ssdel.str().c_str() );
            CharacterDatabase.Execute( ssins.str().c_str() );
            CharacterDatabase.CommitTransaction ();
        }
    }

    if(!m_criteriaProgress.empty())
    {
        /// prepare deleting and insert
        bool need_execute_del = false;
        bool need_execute_ins = false;
        std::ostringstream ssdel;
        std::ostringstream ssins;
        for(CriteriaProgressMap::iterator iter = m_criteriaProgress.begin(); iter!=m_criteriaProgress.end(); ++iter)
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
            CharacterDatabase.BeginTransaction ();
            if(need_execute_del)
                CharacterDatabase.Execute( ssdel.str().c_str() );
            if(need_execute_ins)
                CharacterDatabase.Execute( ssins.str().c_str() );
            CharacterDatabase.CommitTransaction ();
        }
    }
}

void AchievementMgr::LoadFromDB(QueryResult *achievementResult, QueryResult *criteriaResult)
{
    if(achievementResult)
    {
        do
        {
            Field *fields = achievementResult->Fetch();
            CompletedAchievementData& ca = m_completedAchievements[fields[0].GetUInt32()];
            ca.date = time_t(fields[1].GetUInt64());
            ca.changed = false;
        } while(achievementResult->NextRow());
        delete achievementResult;
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
            if(!criteria || criteria->timeLimit && date + criteria->timeLimit < time(NULL))
                continue;

            CriteriaProgress& progress = m_criteriaProgress[id];
            progress.counter = counter;
            progress.date    = date;
            progress.changed = false;
        } while(criteriaResult->NextRow());
        delete criteriaResult;
    }

}

void AchievementMgr::SendAchievementEarned(AchievementEntry const* achievement)
{
    sLog.outString("AchievementMgr::SendAchievementEarned(%u)", achievement->ID);

    const char *msg = "|Hplayer:$N|h[$N]|h has earned the achievement $a!";
    if(Guild* guild = objmgr.GetGuildById(GetPlayer()->GetGuildId()))
    {
        WorldPacket data(SMSG_MESSAGECHAT, 200);
        data << uint8(CHAT_MSG_ACHIEVEMENT);
        data << uint8(CHAT_MSG_GUILD_ACHIEVEMENT);
        data << uint32(LANG_UNIVERSAL);
        data << uint64(GetPlayer()->GetGUID());
        data << uint32(5);
        data << uint64(GetPlayer()->GetGUID());
        data << uint32(strlen(msg)+1);
        data << msg;
        data << uint8(0);
        data << uint32(achievement->ID);
        guild->BroadcastPacket(&data);
    }
    if(achievement->flags & (ACHIEVEMENT_FLAG_REALM_FIRST_KILL|ACHIEVEMENT_FLAG_REALM_FIRST_REACH))
    {
        // broadcast realm first reached
        WorldPacket data(SMSG_SERVER_FIRST_ACHIEVEMENT, strlen(GetPlayer()->GetName())+1+8+4+4);
        data << GetPlayer()->GetName();
        data << uint64(GetPlayer()->GetGUID());
        data << uint32(achievement->ID);
        data << uint32(0);  // 1=link supplied string as player name, 0=display plain string
        sWorld.SendGlobalMessage(&data);
    }
    else
    {
        WorldPacket data(SMSG_MESSAGECHAT, 200);
        data << uint8(CHAT_MSG_ACHIEVEMENT);
        data << uint32(LANG_UNIVERSAL);
        data << uint64(GetPlayer()->GetGUID());
        data << uint32(5);
        data << uint64(GetPlayer()->GetGUID());
        data << uint32(strlen(msg)+1);
        data << msg;
        data << uint8(0);
        data << uint32(achievement->ID);
        GetPlayer()->SendMessageToSet(&data, true);

    }
    WorldPacket data(SMSG_ACHIEVEMENT_EARNED, 8+4+8);
    data.append(GetPlayer()->GetPackGUID());
    data << uint32(achievement->ID);
    data << uint32(secsToTimeBitFields(time(NULL)));
    data << uint32(0);
    GetPlayer()->SendMessageToSet(&data, true);
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
    GetPlayer()->SendMessageToSet(&data, true);
}

/**
 * called at player login. The player might have fulfilled some achievements when the achievement system wasn't working yet
 */
void AchievementMgr::CheckAllAchievementCriteria()
{
    // suppress sending packets
    for(uint32 i=0; i<ACHIEVEMENT_CRITERIA_TYPE_TOTAL; i++)
        UpdateAchievementCriteria(AchievementCriteriaTypes(i));
}

/**
 * this function will be called whenever the user might have done a criteria relevant action
 */
void AchievementMgr::UpdateAchievementCriteria(AchievementCriteriaTypes type, uint32 miscvalue1, uint32 miscvalue2, Unit *unit, uint32 time)
{
    sLog.outDetail("AchievementMgr::UpdateAchievementCriteria(%u, %u, %u, %u)", type, miscvalue1, miscvalue2, time);
    AchievementCriteriaEntryList const& achievementCriteriaList = achievementmgr.GetAchievementCriteriaByType(type);
    for(AchievementCriteriaEntryList::const_iterator i = achievementCriteriaList.begin(); i!=achievementCriteriaList.end(); ++i)
    {
        AchievementCriteriaEntry const *achievementCriteria = (*i);

        // don't update already completed criteria
        if(IsCompletedCriteria(achievementCriteria))
            continue;

        if(achievementCriteria->groupFlag & ACHIEVEMENT_CRITERIA_GROUP_NOT_IN_GROUP && GetPlayer()->GetGroup())
            continue;

        AchievementEntry const *achievement = sAchievementStore.LookupEntry(achievementCriteria->referredAchievement);
        if(!achievement)
            continue;

        if(achievement->factionFlag == ACHIEVEMENT_FACTION_FLAG_HORDE && GetPlayer()->GetTeam() != HORDE ||
            achievement->factionFlag == ACHIEVEMENT_FACTION_FLAG_ALLIANCE && GetPlayer()->GetTeam() != ALLIANCE)
            continue;

        switch (type)
        {
            case ACHIEVEMENT_CRITERIA_TYPE_REACH_LEVEL:
                SetCriteriaProgress(achievementCriteria, GetPlayer()->getLevel());
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_BUY_BANK_SLOT:
                SetCriteriaProgress(achievementCriteria, GetPlayer()->GetByteValue(PLAYER_BYTES_2, 2)+1);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE:
                // AchievementMgr::UpdateAchievementCriteria might also be called on login - skip in this case
                if(!miscvalue1)
                    continue;
                if(achievementCriteria->kill_creature.creatureID != miscvalue1)
                    continue;
                SetCriteriaProgress(achievementCriteria, miscvalue2, true);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_REACH_SKILL_LEVEL:
                if(uint32 skillvalue = GetPlayer()->GetBaseSkillValue(achievementCriteria->reach_skill_level.skillID))
                    SetCriteriaProgress(achievementCriteria, skillvalue);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST_COUNT:
            {
                uint32 counter =0;
                for(QuestStatusMap::iterator itr = GetPlayer()->getQuestStatusMap().begin(); itr!=GetPlayer()->getQuestStatusMap().end(); itr++)
                    if(itr->second.m_rewarded)
                        counter++;
                SetCriteriaProgress(achievementCriteria, counter);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUESTS_IN_ZONE:
            {
                uint32 counter =0;
                for(QuestStatusMap::iterator itr = GetPlayer()->getQuestStatusMap().begin(); itr!=GetPlayer()->getQuestStatusMap().end(); itr++)
                {
                    Quest const* quest = objmgr.GetQuestTemplate(itr->first);
                    if(itr->second.m_rewarded && quest->GetZoneOrSort() == achievementCriteria->complete_quests_in_zone.zoneID)
                        counter++;
                }
                SetCriteriaProgress(achievementCriteria, counter);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST:
                // AchievementMgr::UpdateAchievementCriteria might also be called on login - skip in this case
                if(!miscvalue1)
                    continue;
                SetCriteriaProgress(achievementCriteria, miscvalue1, true);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_BATTLEGROUND:
                // AchievementMgr::UpdateAchievementCriteria might also be called on login - skip in this case
                if(!miscvalue1)
                    continue;
                if(GetPlayer()->GetMapId() != achievementCriteria->complete_battleground.mapID)
                    continue;
                SetCriteriaProgress(achievementCriteria, miscvalue1, true);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SPELL:
                if(GetPlayer()->HasSpell(achievementCriteria->learn_spell.spellID))
                    SetCriteriaProgress(achievementCriteria, 1);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_ACHIEVEMENT:
                if(m_completedAchievements.find(achievementCriteria->complete_achievement.linkedAchievement) != m_completedAchievements.end())
                    SetCriteriaProgress(achievementCriteria, 1);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_DEATH_AT_MAP:
                // AchievementMgr::UpdateAchievementCriteria might also be called on login - skip in this case
                if(!miscvalue1)
                    continue;
                if(GetPlayer()->GetMapId() != achievementCriteria->death_at_map.mapID)
                    continue;
                SetCriteriaProgress(achievementCriteria, 1, true);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_CREATURE:
                // AchievementMgr::UpdateAchievementCriteria might also be called on login - skip in this case
                if(!miscvalue1)
                    continue;
                if(miscvalue1 != achievementCriteria->killed_by_creature.creatureEntry)
                    continue;
                SetCriteriaProgress(achievementCriteria, 1, true);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_PLAYER:
                // AchievementMgr::UpdateAchievementCriteria might also be called on login - skip in this case
                if(!miscvalue1)
                    continue;
                SetCriteriaProgress(achievementCriteria, 1, true);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_FALL_WITHOUT_DYING:
            {
                // AchievementMgr::UpdateAchievementCriteria might also be called on login - skip in this case
                if(!miscvalue1)
                    continue;
                if(achievement->ID == 1260)
                {
                    if(Player::GetDrunkenstateByValue(GetPlayer()->GetDrunkValue()) != DRUNKEN_SMASHED)
                        continue;
                    // TODO: hardcoding eventid is bad, it can differ from DB to DB - maye implement something using HolidayNames.dbc?
                    if(!gameeventmgr.IsActiveEvent(26))
                        continue;
                }
                // miscvalue1 is the ingame fallheight*100 as stored in dbc
                SetCriteriaProgress(achievementCriteria, miscvalue1);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST:
                if(GetPlayer()->GetQuestRewardStatus(achievementCriteria->complete_quest.questID))
                    SetCriteriaProgress(achievementCriteria, 1);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_USE_ITEM:
                // AchievementMgr::UpdateAchievementCriteria might also be called on login - skip in this case
                if(!miscvalue1)
                    continue;
                if(achievementCriteria->use_item.itemID != miscvalue1)
                    continue;
                SetCriteriaProgress(achievementCriteria, 1, true);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_OWN_ITEM:
                // speedup for non-login case
                if(miscvalue1 && achievementCriteria->own_item.itemID!=miscvalue1)
                    continue;
                SetCriteriaProgress(achievementCriteria, GetPlayer()->GetItemCount(achievementCriteria->own_item.itemID, true));
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_LOOT_ITEM:
                // You _have_ to loot that item, just owning it when logging in does _not_ count!
                if(!miscvalue1)
                    continue;
                if(miscvalue1 != achievementCriteria->own_item.itemID)
                    continue;
                SetCriteriaProgress(achievementCriteria, miscvalue2, true);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET:
            case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2:
                if (!miscvalue1 || miscvalue1 != achievementCriteria->be_spell_target.spellID)
                    continue;
                SetCriteriaProgress(achievementCriteria, 1, true);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL:
                if (!miscvalue1 || miscvalue1 != achievementCriteria->cast_spell.spellID)
                    continue;
                SetCriteriaProgress(achievementCriteria, 1, true);
                break;
            case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL2:
            {
                if (!miscvalue1 || miscvalue1 != achievementCriteria->cast_spell.spellID)
                    continue;

                // those requirements couldn't be found in the dbc
                if (CriteriaCastSpellRequirement const* requirement = AchievementGlobalMgr::GetCriteriaCastSpellRequirement(achievementCriteria))
                {
                    if (!unit)
                        continue;

                    if (requirement->creatureEntry && unit->GetEntry() != requirement->creatureEntry)
                        continue;

                    if (requirement->playerRace && (unit->GetTypeId() != TYPEID_PLAYER || unit->getRace()!=requirement->playerRace))
                        continue;

                    if (requirement->playerClass && (unit->GetTypeId() != TYPEID_PLAYER || unit->getClass()!=requirement->playerClass))
                        continue;
                }

                SetCriteriaProgress(achievementCriteria, 1, true);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILLLINE_SPELLS:
            {
                uint32 spellCount = 0;
                for (PlayerSpellMap::const_iterator spellIter = GetPlayer()->GetSpellMap().begin();
                        spellIter != GetPlayer()->GetSpellMap().end();
                        spellIter++)
                {
                    for(SkillLineAbilityMap::const_iterator skillIter = spellmgr.GetBeginSkillLineAbilityMap(spellIter->first);
                            skillIter != spellmgr.GetEndSkillLineAbilityMap(spellIter->first);
                            skillIter++)
                    {
                        if(skillIter->second->skillId == achievementCriteria->learn_skilline_spell.skillLine)
                            spellCount++;
                    }
                }
                SetCriteriaProgress(achievementCriteria, spellCount);
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
            case ACHIEVEMENT_CRITERIA_TYPE_GAIN_REPUTATION:
            {
                int32 reputation = GetPlayer()->GetReputation(achievementCriteria->gain_reputation.factionID);
                if (reputation > 0)
                    SetCriteriaProgress(achievementCriteria, reputation);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_GAIN_EXALTED_REPUTATION:
            {
                uint32 counter = 0;
                const FactionStateList factionStateList = GetPlayer()->GetFactionStateList();
                for (FactionStateList::const_iterator iter = factionStateList.begin(); iter!= factionStateList.end(); iter++)
                {
                    if(GetPlayer()->ReputationToRank(iter->second.Standing) >= REP_EXALTED)
                        ++counter;
                }
                SetCriteriaProgress(achievementCriteria, counter);
                break;
            }
            case ACHIEVEMENT_CRITERIA_TYPE_EXPLORE_AREA:
            {
                WorldMapOverlayEntry const* worldOverlayEntry = sWorldMapOverlayStore.LookupEntry(achievementCriteria->explore_area.areaReference);
                if(!worldOverlayEntry)
                    break;

                int32 exploreFlag = GetAreaFlagByAreaID(worldOverlayEntry->areatableID);
                if(exploreFlag < 0)
                    break;

                uint32 playerIndexOffset = uint32(exploreFlag) / 32;
                uint32 mask = 1<< (uint32(exploreFlag) % 32);

                if(GetPlayer()->GetUInt32Value(PLAYER_EXPLORED_ZONES_1 + playerIndexOffset) & mask)
                    SetCriteriaProgress(achievementCriteria, 1);
                break;
            }
           case ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED_ON_LOOT:
           case ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED_ON_LOOT:
           {
               // miscvalue1 = itemid
               // miscvalue2 = diced value
               if(!miscvalue1)
                   continue;
               if(miscvalue2 != achievementCriteria->roll_greed_on_loot.rollValue)
                   continue;
               ItemPrototype const *pProto = objmgr.GetItemPrototype( miscvalue1 );

               uint32 requiredItemLevel = 0;
               if (achievementCriteria->ID == 2412 || achievementCriteria->ID == 2358)
                   requiredItemLevel = 185;

               if(!pProto || pProto->ItemLevel <requiredItemLevel)
                   continue;
               SetCriteriaProgress(achievementCriteria, 1, true);
               break;
           }
        }
        if(IsCompletedCriteria(achievementCriteria))
            CompletedCriteria(achievementCriteria);
    }
}

bool AchievementMgr::IsCompletedCriteria(AchievementCriteriaEntry const* achievementCriteria)
{
    AchievementEntry const* achievement = sAchievementStore.LookupEntry(achievementCriteria->referredAchievement);
    if(!achievement)
        return false;

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
        case ACHIEVEMENT_CRITERIA_TYPE_REACH_LEVEL:
            if(achievement->ID == 467 && GetPlayer()->getClass() != CLASS_SHAMAN ||
                    achievement->ID == 466 && GetPlayer()->getClass() != CLASS_DRUID ||
                    achievement->ID == 465 && GetPlayer()->getClass() != CLASS_PALADIN ||
                    achievement->ID == 464 && GetPlayer()->getClass() != CLASS_PRIEST ||
                    achievement->ID == 463 && GetPlayer()->getClass() != CLASS_WARLOCK ||
                    achievement->ID == 462 && GetPlayer()->getClass() != CLASS_HUNTER ||
                    achievement->ID == 461 && GetPlayer()->getClass() != CLASS_DEATH_KNIGHT ||
                    achievement->ID == 460 && GetPlayer()->getClass() != CLASS_MAGE ||
                    achievement->ID == 459 && GetPlayer()->getClass() != CLASS_WARRIOR ||
                    achievement->ID == 458 && GetPlayer()->getClass() != CLASS_ROGUE ||

                    achievement->ID == 1404 && GetPlayer()->getRace() != RACE_GNOME ||
                    achievement->ID == 1405 && GetPlayer()->getRace() != RACE_BLOODELF ||
                    achievement->ID == 1406 && GetPlayer()->getRace() != RACE_DRAENEI ||
                    achievement->ID == 1407 && GetPlayer()->getRace() != RACE_DWARF ||
                    achievement->ID == 1408 && GetPlayer()->getRace() != RACE_HUMAN ||
                    achievement->ID == 1409 && GetPlayer()->getRace() != RACE_NIGHTELF ||
                    achievement->ID == 1410 && GetPlayer()->getRace() != RACE_ORC ||
                    achievement->ID == 1411 && GetPlayer()->getRace() != RACE_TAUREN ||
                    achievement->ID == 1412 && GetPlayer()->getRace() != RACE_TROLL ||
                    achievement->ID == 1413 && GetPlayer()->getRace() != RACE_UNDEAD_PLAYER )
                return false;
            return progress->counter >= achievementCriteria->reach_level.level;
        case ACHIEVEMENT_CRITERIA_TYPE_BUY_BANK_SLOT:
            return progress->counter >= achievementCriteria->buy_bank_slot.numberOfSlots;
        case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE:
            return progress->counter >= achievementCriteria->kill_creature.creatureCount;
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_ACHIEVEMENT:
            return progress->counter >= 1;
        case ACHIEVEMENT_CRITERIA_TYPE_REACH_SKILL_LEVEL:
            return progress->counter >= achievementCriteria->reach_skill_level.skillLevel;
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST_COUNT:
            return progress->counter >= achievementCriteria->complete_quest_count.totalQuestCount;
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUESTS_IN_ZONE:
            return progress->counter >= achievementCriteria->complete_quests_in_zone.questCount;
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST:
            return progress->counter >= achievementCriteria->complete_daily_quest.questCount;
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SPELL:
            return progress->counter >= 1;
        case ACHIEVEMENT_CRITERIA_TYPE_FALL_WITHOUT_DYING:
            return progress->counter >= achievementCriteria->fall_without_dying.fallHeight;
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST:
            return progress->counter >= 1;
        case ACHIEVEMENT_CRITERIA_TYPE_USE_ITEM:
            return progress->counter >= achievementCriteria->use_item.itemCount;
        case ACHIEVEMENT_CRITERIA_TYPE_OWN_ITEM:
            return progress->counter >= achievementCriteria->own_item.itemCount;
        case ACHIEVEMENT_CRITERIA_TYPE_LOOT_ITEM:
            return progress->counter >= achievementCriteria->loot_item.itemCount;
        case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET:
        case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2:
            return progress->counter >= achievementCriteria->be_spell_target.spellCount;
        case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL:
        case ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL2:
            return progress->counter >= achievementCriteria->cast_spell.castCount;
        case ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILLLINE_SPELLS:
            return progress->counter >= achievementCriteria->learn_skilline_spell.spellCount;
        case ACHIEVEMENT_CRITERIA_TYPE_VISIT_BARBER_SHOP:
            return progress->counter >= achievementCriteria->visit_barber.numberOfVisits;
        case ACHIEVEMENT_CRITERIA_TYPE_GAIN_REPUTATION:
            return progress->counter >= achievementCriteria->gain_reputation.reputationAmount;
        case ACHIEVEMENT_CRITERIA_TYPE_GAIN_EXALTED_REPUTATION:
            return progress->counter >= achievementCriteria->gain_exalted_reputation.numberOfExaltedFactions;
        case ACHIEVEMENT_CRITERIA_TYPE_EXPLORE_AREA:
            return progress->counter >= 1;
       case ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED_ON_LOOT:
       case ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED_ON_LOOT:
           return progress->counter >= achievementCriteria->roll_greed_on_loot.count;

        // handle all statistic-only criteria here
        case ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_BATTLEGROUND:
        case ACHIEVEMENT_CRITERIA_TYPE_DEATH_AT_MAP:
        case ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_CREATURE:
        case ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_PLAYER:
            return false;
    }
    return false;
}

void AchievementMgr::CompletedCriteria(AchievementCriteriaEntry const* criteria)
{
    AchievementEntry const* achievement = sAchievementStore.LookupEntry(criteria->referredAchievement);
    if(!achievement)
        return;
    // counter can never complete
    if(achievement->flags & ACHIEVEMENT_FLAG_COUNTER)
        return;

    if(criteria->completionFlag & ACHIEVEMENT_CRITERIA_COMPLETE_FLAG_ALL || GetAchievementCompletionState(achievement)==ACHIEVEMENT_COMPLETED_COMPLETED_NOT_STORED)
    {
        CompletedAchievement(achievement);
    }
}

// TODO: achievement 705 requires 4 criteria to be fulfilled
AchievementCompletionState AchievementMgr::GetAchievementCompletionState(AchievementEntry const* entry)
{
    if(m_completedAchievements.find(entry->ID)!=m_completedAchievements.end())
        return ACHIEVEMENT_COMPLETED_COMPLETED_STORED;

    bool foundOutstanding = false;
    for (uint32 entryId = 0; entryId<sAchievementCriteriaStore.GetNumRows(); entryId++)
    {
         AchievementCriteriaEntry const* criteria = sAchievementCriteriaStore.LookupEntry(entryId);
         if(!criteria || criteria->referredAchievement!= entry->ID)
             continue;

         if(IsCompletedCriteria(criteria) && criteria->completionFlag & ACHIEVEMENT_CRITERIA_COMPLETE_FLAG_ALL)
             return ACHIEVEMENT_COMPLETED_COMPLETED_NOT_STORED;

         // found an umcompleted criteria, but DONT return false yet - there might be a completed criteria with ACHIEVEMENT_CRITERIA_COMPLETE_FLAG_ALL
         if(!IsCompletedCriteria(criteria))
             foundOutstanding = true;
    }
    if(foundOutstanding)
        return ACHIEVEMENT_COMPLETED_NONE;
    else
        return ACHIEVEMENT_COMPLETED_COMPLETED_NOT_STORED;
}

void AchievementMgr::SetCriteriaProgress(AchievementCriteriaEntry const* entry, uint32 newValue, bool relative)
{
    sLog.outDetail("AchievementMgr::SetCriteriaProgress(%u, %u)", entry->ID, newValue);
    CriteriaProgress *progress = NULL;

    CriteriaProgressMap::iterator iter = m_criteriaProgress.find(entry->ID);

    if(iter == m_criteriaProgress.end())
    {
        // not create record for 0 counter
        if(newValue == 0)
            return;

        progress = &m_criteriaProgress[entry->ID];
        progress->counter = newValue;
        progress->date = time(NULL);
    }
    else
    {
        progress = &iter->second;
        if(relative)
            newValue += progress->counter;

        // not update (not mark as changed) if counter will have same value
        if(progress->counter == newValue)
            return;

        progress->counter = newValue;
    }

    progress->changed = true;

    if(entry->timeLimit)
    {
        time_t now = time(NULL);
        if(progress->date + entry->timeLimit < now)
        {
            progress->counter = 1;
        }
        // also it seems illogical, the timeframe will be extended at every criteria update
        progress->date = now;
    }
    SendCriteriaUpdate(entry->ID,progress);
}

void AchievementMgr::CompletedAchievement(AchievementEntry const* achievement)
{
    sLog.outDetail("AchievementMgr::CompletedAchievement(%u)", achievement->ID);
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
    if(uint32 titleId = reward->titleId[GetPlayer()->GetTeam() == HORDE?0:1])
    {
        if(CharTitlesEntry const* titleEntry = sCharTitlesStore.LookupEntry(titleId))
            GetPlayer()->SetTitle(titleEntry);
    }

    // mail
    if(reward->sender)
    {
        Item* item = reward->itemId ? Item::CreateItem(reward->itemId,1,GetPlayer ()) : NULL;

        MailItemsInfo mi;
        if(item)
        {
            // save new item before send
            item->SaveToDB();                               // save for prevent lost at next mail load, if send fail then item will deleted

            // item
            mi.AddItem(item->GetGUIDLow(), item->GetEntry(), item);
        }

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

        WorldSession::SendMailTo(GetPlayer(), MAIL_CREATURE, MAIL_STATIONERY_NORMAL, reward->sender, GetPlayer()->GetGUIDLow(), subject, itemTextId , &mi, 0, 0, MAIL_CHECK_MASK_NONE);
    }
}

void AchievementMgr::SendAllAchievementData()
{
    // since we don't know the exact size of the packed GUIDs this is just an approximation
    WorldPacket data(SMSG_ALL_ACHIEVEMENT_DATA, 4*2+m_completedAchievements.size()*4*2+m_completedAchievements.size()*7*4);
    BuildAllDataPacket(&data);
    GetPlayer()->GetSession()->SendPacket(&data);
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
 * used by both SMSG_ALL_ACHIEVEMENT_DATA  and SMSG_RESPOND_INSPECT_ACHIEVEMENT
 */
void AchievementMgr::BuildAllDataPacket(WorldPacket *data)
{
    for(CompletedAchievementMap::const_iterator iter = m_completedAchievements.begin(); iter!=m_completedAchievements.end(); ++iter)
    {
        *data << uint32(iter->first);
        *data << uint32(secsToTimeBitFields(iter->second.date));
    }
    *data << int32(-1);

    for(CriteriaProgressMap::const_iterator iter = m_criteriaProgress.begin(); iter!=m_criteriaProgress.end(); ++iter)
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

        sLog.outString("");
        sLog.outErrorDb(">> Loaded 0 achievement criteria.");
        return;
    }

    barGoLink bar( sAchievementCriteriaStore.GetNumRows() );
    for (uint32 entryId = 0; entryId<sAchievementCriteriaStore.GetNumRows(); entryId++)
    {
        bar.step();

        AchievementCriteriaEntry const* criteria = sAchievementCriteriaStore.LookupEntry(entryId);
        if(!criteria)
            continue;

        m_AchievementCriteriasByType[criteria->requiredType].push_back(criteria);
    }

    sLog.outString();
    sLog.outErrorDb(">> Loaded 0 achievement criteria.",m_AchievementCriteriasByType->size());
}


void AchievementGlobalMgr::LoadCompletedAchievements()
{
    QueryResult *result = CharacterDatabase.Query("SELECT achievement FROM character_achievement GROUP BY achievement");

    if(!result)
    {
        barGoLink bar(1);
        bar.step();

        sLog.outString("");
        sLog.outString(">> Loaded 0 realm completed achievements . DB table `character_achievement` is empty.");
        return;
    }

    barGoLink bar(result->GetRowCount());
    do
    {
        bar.step();
        Field *fields = result->Fetch();
        m_allCompletedAchievements.insert(fields[0].GetUInt32());
    } while(result->NextRow());

    delete result;

    sLog.outString("");
    sLog.outString(">> Loaded %u realm completed achievements.",m_allCompletedAchievements.size());
}

void AchievementGlobalMgr::LoadRewards()
{
    m_achievementRewards.clear();                             // need for reload case

    //                                                0      1        2        3     4       5        6
    QueryResult *result = WorldDatabase.Query("SELECT entry, title_A, title_H, item, sender, subject, text FROM achievement_reward");

    if(!result)
    {
        barGoLink bar(1);

        bar.step();

        sLog.outString("");
        sLog.outErrorDb(">> Loaded 0 achievement rewards. DB table `achievement_reward` is empty.");
        return;
    }

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

    } while (result->NextRow());

    delete result;

    sLog.outString();
    sLog.outString( ">> Loaded %u achievement reward locale strings", m_achievementRewardLocales.size() );
}

void AchievementGlobalMgr::LoadRewardLocales()
{
    m_achievementRewardLocales.clear();                       // need for reload case

    QueryResult *result = WorldDatabase.Query("SELECT entry,subject_loc1,text_loc1,subject_loc2,text_loc2,subject_loc3,text_loc3,subject_loc4,text_loc4,subject_loc5,text_loc5,subject_loc6,text_loc6,subject_loc7,text_loc7,subject_loc8,text_loc8 FROM locales_achievement_reward");

    if(!result)
    {
        barGoLink bar(1);

        bar.step();

        sLog.outString("");
        sLog.outString(">> Loaded 0 achievement reward locale strings. DB table `locales_achievement_reward` is empty.");
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

        for(int i = 1; i < MAX_LOCALE; ++i)
        {
            std::string str = fields[1+2*(i-1)].GetCppString();
            if(!str.empty())
            {
                int idx = objmgr.GetOrNewIndexForLocale(LocaleConstant(i));
                if(idx >= 0)
                {
                    if(data.subject.size() <= idx)
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
                    if(data.text.size() <= idx)
                        data.text.resize(idx+1);

                    data.text[idx] = str;
                }
            }
        }
    } while (result->NextRow());

    delete result;

    sLog.outString();
    sLog.outString( ">> Loaded %u achievement reward locale strings", m_achievementRewardLocales.size() );
}
