/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
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

#include "Object.h"
#include "Player.h"
#include "BattleGround.h"
#include "Creature.h"
#include "MapManager.h"
#include "Language.h"
#include "Chat.h"
#include "SpellAuras.h"
#include "ArenaTeam.h"
#include "World.h"
#include "Util.h"

BattleGround::BattleGround()
{
    m_TypeID            = 0;
    m_InstanceID        = 0;
    m_Status            = 0;
    m_EndTime           = 0;
    m_LastResurrectTime = 0;
    m_Queue_type        = MAX_BATTLEGROUND_QUEUES;
    m_InvitedAlliance   = 0;
    m_InvitedHorde      = 0;
    m_ArenaType         = 0;
    m_IsArena           = false;
    m_Winner            = 2;
    m_StartTime         = 0;
    m_Events            = 0;
    m_IsRated           = false;
    m_BuffChange        = false;
    m_Name              = "";
    m_LevelMin          = 0;
    m_LevelMax          = 0;
    m_InBGFreeSlotQueue = false;
    m_SetDeleteThis     = false;

    m_MaxPlayersPerTeam = 0;
    m_MaxPlayers        = 0;
    m_MinPlayersPerTeam = 0;
    m_MinPlayers        = 0;

    m_MapId             = 0;

    m_TeamStartLocX[BG_TEAM_ALLIANCE]   = 0;
    m_TeamStartLocX[BG_TEAM_HORDE]      = 0;

    m_TeamStartLocY[BG_TEAM_ALLIANCE]   = 0;
    m_TeamStartLocY[BG_TEAM_HORDE]      = 0;

    m_TeamStartLocZ[BG_TEAM_ALLIANCE]   = 0;
    m_TeamStartLocZ[BG_TEAM_HORDE]      = 0;

    m_TeamStartLocO[BG_TEAM_ALLIANCE]   = 0;
    m_TeamStartLocO[BG_TEAM_HORDE]      = 0;

    m_ArenaTeamIds[BG_TEAM_ALLIANCE]   = 0;
    m_ArenaTeamIds[BG_TEAM_HORDE]      = 0;

    m_ArenaTeamRatingChanges[BG_TEAM_ALLIANCE]   = 0;
    m_ArenaTeamRatingChanges[BG_TEAM_HORDE]      = 0;

    m_BgRaids[BG_TEAM_ALLIANCE]         = NULL;
    m_BgRaids[BG_TEAM_HORDE]            = NULL;

    m_PlayersCount[BG_TEAM_ALLIANCE]    = 0;
    m_PlayersCount[BG_TEAM_HORDE]       = 0;

    m_PrematureCountDown = false;
    m_PrematureCountDown = 0;

    m_HonorMode = BG_NORMAL;
}

BattleGround::~BattleGround()
{
    // remove objects and creatures
    // (this is done automatically in mapmanager update, when the instance is reset after the reset time)
    int size = m_BgCreatures.size();
    for(int i = 0; i < size; ++i)
    {
        DelCreature(i);
    }
    size = m_BgObjects.size();
    for(int i = 0; i < size; ++i)
    {
        DelObject(i);
    }

    // delete creature and go respawn times
    WorldDatabase.PExecute("DELETE FROM creature_respawn WHERE instance = '%u'",GetInstanceID());
    WorldDatabase.PExecute("DELETE FROM gameobject_respawn WHERE instance = '%u'",GetInstanceID());
    // delete instance from db
    CharacterDatabase.PExecute("DELETE FROM instance WHERE id = '%u'",GetInstanceID());
    // remove from battlegrounds
    sBattleGroundMgr.RemoveBattleGround(GetInstanceID());
    // unload map
    if(Map * map = MapManager::Instance().FindMap(GetMapId(), GetInstanceID()))
        if(map->IsBattleGroundOrArena())
            ((BattleGroundMap*)map)->SetUnload();
    // remove from bg free slot queue
    this->RemoveFromBGFreeSlotQueue();
}

void BattleGround::Update(time_t diff)
{
    if(!GetPlayersSize() && !GetRemovedPlayersSize() && !GetReviveQueueSize())
        //BG is empty
        return;

    m_StartTime += diff;

    // WorldPacket data;

    if(GetRemovedPlayersSize())
    {
        for(std::map<uint64, uint8>::iterator itr = m_RemovedPlayers.begin(); itr != m_RemovedPlayers.end(); ++itr)
        {
            Player *plr = objmgr.GetPlayer(itr->first);
            switch(itr->second)
            {
                //following code is handled by event:
                /*case 0:
                    sBattleGroundMgr.m_BattleGroundQueues[GetTypeID()].RemovePlayer(itr->first);
                    //RemovePlayerFromQueue(itr->first);
                    if(plr)
                    {
                        sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, this, plr->GetTeam(), plr->GetBattleGroundQueueIndex(m_TypeID), STATUS_NONE, 0, 0);
                        plr->GetSession()->SendPacket(&data);
                    }
                    break;*/
                case 1:                                     // currently in bg and was removed from bg
                    if(plr)
                        RemovePlayerAtLeave(itr->first, true, true);
                    else
                        RemovePlayerAtLeave(itr->first, false, false);
                    break;
                case 2:                                     // revive queue
                    RemovePlayerFromResurrectQueue(itr->first);
                    break;
                default:
                    sLog.outError("BattleGround: Unknown remove player case!");
            }
        }
        m_RemovedPlayers.clear();
    }

    // this code isn't efficient and its idea isn't implemented yet
    /* offline players are removed from battleground in worldsession::LogoutPlayer()
    // remove offline players from bg after ~5 minutes
    if(GetPlayersSize())
    {
        for(std::map<uint64, BattleGroundPlayer>::iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
        {
            Player *plr = objmgr.GetPlayer(itr->first);
            itr->second.LastOnlineTime += diff;

            if(plr)
                itr->second.LastOnlineTime = 0;   // update last online time
            else
                if(itr->second.LastOnlineTime >= MAX_OFFLINE_TIME)                   // 5 minutes
                    m_RemovedPlayers[itr->first] = 1;       // add to remove list (BG)
        }
    }*/

    m_LastResurrectTime += diff;
    if (m_LastResurrectTime >= RESURRECTION_INTERVAL)
    {
        if(GetReviveQueueSize())
        {
            for(std::map<uint64, std::vector<uint64> >::iterator itr = m_ReviveQueue.begin(); itr != m_ReviveQueue.end(); ++itr)
            {
                Creature *sh = NULL;
                for(std::vector<uint64>::iterator itr2 = (itr->second).begin(); itr2 != (itr->second).end(); ++itr2)
                {
                    Player *plr = objmgr.GetPlayer(*itr2);
                    if(!plr)
                        continue;

                    if (!sh)
                    {
                        sh = ObjectAccessor::GetCreature(*plr, itr->first);
                        // only for visual effect
                        if (sh)
                            sh->CastSpell(sh, SPELL_SPIRIT_HEAL, true);   // Spirit Heal, effect 117
                    }

                    plr->CastSpell(plr, SPELL_RESURRECTION_VISUAL, true);   // Resurrection visual
                    m_ResurrectQueue.push_back(*itr2);
                }
                (itr->second).clear();
            }

            m_ReviveQueue.clear();
            m_LastResurrectTime = 0;
        }
        else
            // queue is clear and time passed, just update last resurrection time
            m_LastResurrectTime = 0;
    }
    else if (m_LastResurrectTime > 500)    // Resurrect players only half a second later, to see spirit heal effect on NPC
    {
        for(std::vector<uint64>::iterator itr = m_ResurrectQueue.begin(); itr != m_ResurrectQueue.end(); ++itr)
        {
            Player *plr = objmgr.GetPlayer(*itr);
            if(!plr)
                continue;
            plr->ResurrectPlayer(1.0f);
            plr->CastSpell(plr, SPELL_SPIRIT_HEAL_MANA, true);
            ObjectAccessor::Instance().ConvertCorpseForPlayer(*itr);
        }
        m_ResurrectQueue.clear();
    }

    // if less then minimum players are in on one side, then start premature finish timer
    if(GetStatus() == STATUS_IN_PROGRESS && !isArena() && sBattleGroundMgr.GetPrematureFinishTime() && (GetPlayersCountByTeam(ALLIANCE) < GetMinPlayersPerTeam() || GetPlayersCountByTeam(HORDE) < GetMinPlayersPerTeam()))
    {
        if(!m_PrematureCountDown)
        {
            m_PrematureCountDown = true;
            m_PrematureCountDownTimer = sBattleGroundMgr.GetPrematureFinishTime();
            SendMessageToAll(LANG_BATTLEGROUND_PREMATURE_FINISH_WARNING);
        }
        else if(m_PrematureCountDownTimer < diff)
        {
            // time's up!
            EndBattleGround(0); // noone wins
            m_PrematureCountDown = false;
        }
        else
        {
            uint32 newtime = m_PrematureCountDownTimer - diff;
            // announce every minute
            if(m_PrematureCountDownTimer != sBattleGroundMgr.GetPrematureFinishTime() && newtime / 60000 != m_PrematureCountDownTimer / 60000)
                SendMessageToAll(LANG_BATTLEGROUND_PREMATURE_FINISH_WARNING);
            m_PrematureCountDownTimer = newtime;
        }
    }
    else if (m_PrematureCountDown)
        m_PrematureCountDown = false;

    if(GetStatus() == STATUS_WAIT_LEAVE)
    {
        // remove all players from battleground after 2 minutes
        m_EndTime += diff;
        if(m_EndTime >= TIME_TO_AUTOREMOVE)                 // 2 minutes
        {
            for(std::map<uint64, BattleGroundPlayer>::iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
            {
                m_RemovedPlayers[itr->first] = 1;           // add to remove list (BG)
            }
            // do not change any battleground's private variables
        }
    }
}

void BattleGround::SetTeamStartLoc(uint32 TeamID, float X, float Y, float Z, float O)
{
    uint8 idx = GetTeamIndexByTeamId(TeamID);
    m_TeamStartLocX[idx] = X;
    m_TeamStartLocY[idx] = Y;
    m_TeamStartLocZ[idx] = Z;
    m_TeamStartLocO[idx] = O;
}

void BattleGround::SendPacketToAll(WorldPacket *packet)
{
    for(std::map<uint64, BattleGroundPlayer>::iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        Player *plr = objmgr.GetPlayer(itr->first);
        if(plr)
            plr->GetSession()->SendPacket(packet);
        else
            sLog.outError("BattleGround: Player " I64FMTD " not found!", itr->first);
    }
}

void BattleGround::SendPacketToTeam(uint32 TeamID, WorldPacket *packet, Player *sender, bool self)
{
    for(std::map<uint64, BattleGroundPlayer>::iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        Player *plr = objmgr.GetPlayer(itr->first);

        if(!plr)
        {
            sLog.outError("BattleGround: Player " I64FMTD " not found!", itr->first);
            continue;
        }

        if(!self && sender == plr)
            continue;

        uint32 team = itr->second.Team;//GetPlayerTeam(plr->GetGUID());
        if(!team) team = plr->GetTeam();

        if(team == TeamID)
            plr->GetSession()->SendPacket(packet);
    }
}

void BattleGround::PlaySoundToAll(uint32 SoundID)
{
    WorldPacket data;
    sBattleGroundMgr.BuildPlaySoundPacket(&data, SoundID);
    SendPacketToAll(&data);
}

void BattleGround::PlaySoundToTeam(uint32 SoundID, uint32 TeamID)
{
    WorldPacket data;

    for(std::map<uint64, BattleGroundPlayer>::iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        Player *plr = objmgr.GetPlayer(itr->first);

        if(!plr)
        {
            sLog.outError("BattleGround: Player " I64FMTD " not found!", itr->first);
            continue;
        }

        uint32 team = itr->second.Team;//GetPlayerTeam(plr->GetGUID());
        if(!team) team = plr->GetTeam();

        if(team == TeamID)
        {
            sBattleGroundMgr.BuildPlaySoundPacket(&data, SoundID);
            plr->GetSession()->SendPacket(&data);
        }
    }
}

void BattleGround::CastSpellOnTeam(uint32 SpellID, uint32 TeamID)
{
    for(std::map<uint64, BattleGroundPlayer>::iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        Player *plr = objmgr.GetPlayer(itr->first);

        if(!plr)
        {
            sLog.outError("BattleGround: Player " I64FMTD " not found!", itr->first);
            continue;
        }

        uint32 team = itr->second.Team;//GetPlayerTeam(plr->GetGUID());
        if(!team) team = plr->GetTeam();

        if(team == TeamID)
            plr->CastSpell(plr, SpellID, true);
    }
}

void BattleGround::YellToAll(Creature* creature, const char* text, uint32 language)
{
    for(std::map<uint64, BattleGroundPlayer>::iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        WorldPacket data(SMSG_MESSAGECHAT, 200);
        Player *plr = objmgr.GetPlayer(itr->first);
        if(!plr)
        {
            sLog.outError("BattleGround: Player " I64FMTD " not found!", itr->first);
            continue;
        }
        creature->BuildMonsterChat(&data,CHAT_MSG_MONSTER_YELL,text,language,creature->GetName(),itr->first);
        plr->GetSession()->SendPacket(&data);
    }
}


void BattleGround::RewardHonorToTeam(uint32 Honor, uint32 TeamID)
{
    for(std::map<uint64, BattleGroundPlayer>::iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        Player *plr = objmgr.GetPlayer(itr->first);

        if(!plr)
        {
            sLog.outError("BattleGround: Player " I64FMTD " not found!", itr->first);
            continue;
        }

        uint32 team = itr->second.Team;//GetPlayerTeam(plr->GetGUID());
        if(!team) team = plr->GetTeam();

        if(team == TeamID)
            UpdatePlayerScore(plr, SCORE_BONUS_HONOR, Honor);
    }
}

void BattleGround::RewardReputationToTeam(uint32 faction_id, uint32 Reputation, uint32 TeamID)
{
    FactionEntry const* factionEntry = sFactionStore.LookupEntry(faction_id);

    if(!factionEntry)
        return;

    for(std::map<uint64, BattleGroundPlayer>::iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        Player *plr = objmgr.GetPlayer(itr->first);

        if(!plr)
        {
            sLog.outError("BattleGround: Player " I64FMTD " not found!", itr->first);
            continue;
        }

        uint32 team = itr->second.Team;//GetPlayerTeam(plr->GetGUID());
        if(!team) team = plr->GetTeam();

        if(team == TeamID)
            plr->ModifyFactionReputation(factionEntry, Reputation);
    }
}

void BattleGround::UpdateWorldState(uint32 Field, uint32 Value)
{
    WorldPacket data;
    sBattleGroundMgr.BuildUpdateWorldStatePacket(&data, Field, Value);
    SendPacketToAll(&data);
}

void BattleGround::UpdateWorldStateForPlayer(uint32 Field, uint32 Value, Player *Source)
{
    WorldPacket data;
    sBattleGroundMgr.BuildUpdateWorldStatePacket(&data, Field, Value);
    Source->GetSession()->SendPacket(&data);
}

void BattleGround::EndBattleGround(uint32 winner)
{
    this->RemoveFromBGFreeSlotQueue();
    uint32 almost_winning_team = HORDE;
    ArenaTeam * winner_arena_team = NULL;
    ArenaTeam * loser_arena_team = NULL;
    uint32 loser_rating = 0;
    uint32 winner_rating = 0;
    WorldPacket data;
    Player *Source = NULL;
    const char *winmsg = "";

    if(winner == ALLIANCE)
    {
        if(isBattleGround())
            winmsg = GetTrinityString(LANG_BG_A_WINS);
        else
            winmsg = GetTrinityString(LANG_ARENA_GOLD_WINS);

        PlaySoundToAll(SOUND_ALLIANCE_WINS);                // alliance wins sound

        SetWinner(WINNER_ALLIANCE);
    }
    else if(winner == HORDE)
    {
        if(isBattleGround())
            winmsg = GetTrinityString(LANG_BG_H_WINS);
        else
            winmsg = GetTrinityString(LANG_ARENA_GREEN_WINS);

        PlaySoundToAll(SOUND_HORDE_WINS);                   // horde wins sound

        SetWinner(WINNER_HORDE);
    }
    else
    {
        SetWinner(3);
    }

    SetStatus(STATUS_WAIT_LEAVE);
    m_EndTime = 0;

    // arena rating calculation
    if(isArena() && isRated())
    {
        if(winner == ALLIANCE)
        {
            winner_arena_team = objmgr.GetArenaTeamById(GetArenaTeamIdForTeam(ALLIANCE));
            loser_arena_team = objmgr.GetArenaTeamById(GetArenaTeamIdForTeam(HORDE));
        }
        else if(winner == HORDE)
        {
            winner_arena_team = objmgr.GetArenaTeamById(GetArenaTeamIdForTeam(HORDE));
            loser_arena_team = objmgr.GetArenaTeamById(GetArenaTeamIdForTeam(ALLIANCE));
        }
        if(winner_arena_team && loser_arena_team)
        {
            loser_rating = loser_arena_team->GetStats().rating;
            winner_rating = winner_arena_team->GetStats().rating;
            int32 winner_change = winner_arena_team->WonAgainst(loser_rating);
            int32 loser_change = loser_arena_team->LostAgainst(winner_rating);
            sLog.outDebug("--- Winner rating: %u, Loser rating: %u, Winner change: %u, Losser change: %u ---", winner_rating, loser_rating, winner_change, loser_change);
            if(winner == ALLIANCE)
            {
                SetArenaTeamRatingChangeForTeam(ALLIANCE, winner_change);
                SetArenaTeamRatingChangeForTeam(HORDE, loser_change);
            }
            else
            {
                SetArenaTeamRatingChangeForTeam(HORDE, winner_change);
                SetArenaTeamRatingChangeForTeam(ALLIANCE, loser_change);
            }
            sLog.outArena("Arena match Type: %u for Team1Id: %u - Team2Id: %u ended. WinnerTeamId: %u. RatingChange: %i.", m_ArenaType, m_ArenaTeamIds[BG_TEAM_ALLIANCE], m_ArenaTeamIds[BG_TEAM_HORDE], winner_arena_team->GetId(), winner_change);
        }
        else
        {
            SetArenaTeamRatingChangeForTeam(ALLIANCE, 0);
            SetArenaTeamRatingChangeForTeam(HORDE, 0);
        }
    }

    if(!isArena()){

    if(m_score[GetTeamIndexByTeamId(ALLIANCE)] == m_score[GetTeamIndexByTeamId(HORDE)])
        almost_winning_team = 0;         //no real winner
    if(m_score[GetTeamIndexByTeamId(ALLIANCE)] > m_score[GetTeamIndexByTeamId(HORDE)])
        almost_winning_team = ALLIANCE;

    }

    for(std::map<uint64, BattleGroundPlayer>::iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        Player *plr = objmgr.GetPlayer(itr->first);
        if(!plr)
        {
            sLog.outError("BattleGround: Player " I64FMTD " not found!", itr->first);
            continue;
        }

        // should remove spirit of redemption
        if(plr->HasAuraType(SPELL_AURA_SPIRIT_OF_REDEMPTION))
            plr->RemoveSpellsCausingAura(SPELL_AURA_MOD_SHAPESHIFT);

        if(!plr->isAlive())
        {
            plr->ResurrectPlayer(1.0f);
            plr->SpawnCorpseBones();
        }

        uint32 team = itr->second.Team;
        if(!team) team = plr->GetTeam();

        // per player calculation
        if(isArena() && isRated() && winner_arena_team && loser_arena_team)
        {
            if(team == winner)
                winner_arena_team->MemberWon(plr,loser_rating);
            else
                loser_arena_team->MemberLost(plr,winner_rating);
        }

        if(team == winner)
        {
            if(!Source)
                Source = plr;
            RewardMark(plr,ITEM_WINNER_COUNT);
            UpdatePlayerScore(plr, SCORE_BONUS_HONOR, 20);
            RewardQuest(plr);
        }
        else if(winner !=0)
        {
        RewardMark(plr,ITEM_LOSER_COUNT);
        }
    else if(winner == 0)
    {
        if(sWorld.getConfig(CONFIG_PREMATURE_BG_REWARD))    // We're feeling generous, giving rewards to people who not earned them ;)
        {    //nested ifs for the win! its boring writing that, forgive me my unfunniness
            
            if(almost_winning_team == team)                    //player's team had more points
                RewardMark(plr,ITEM_WINNER_COUNT);
            else
                RewardMark(plr,ITEM_LOSER_COUNT);            // if scores were the same, each team gets 1 mark.
        }
    }

        plr->CombatStopWithPets(true);

        BlockMovement(plr);

        sBattleGroundMgr.BuildPvpLogDataPacket(&data, this);
        plr->GetSession()->SendPacket(&data);

        uint32 bgQueueTypeId = sBattleGroundMgr.BGQueueTypeId(GetTypeID(), GetArenaType());
        sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, this, plr->GetTeam(), plr->GetBattleGroundQueueIndex(bgQueueTypeId), STATUS_IN_PROGRESS, TIME_TO_AUTOREMOVE, GetStartTime());
        plr->GetSession()->SendPacket(&data);
    }

    if(isArena() && isRated() && winner_arena_team && loser_arena_team)
    {
        // update arena points only after increasing the player's match count!
        //obsolete: winner_arena_team->UpdateArenaPointsHelper();
        //obsolete: loser_arena_team->UpdateArenaPointsHelper();
        // save the stat changes
        winner_arena_team->SaveToDB();
        loser_arena_team->SaveToDB();
        // send updated arena team stats to players
        // this way all arena team members will get notified, not only the ones who participated in this match
        winner_arena_team->NotifyStatsChanged();
        loser_arena_team->NotifyStatsChanged();
    sLog.outDebug("Rated arena match between %s and %s finished, winner: %s", loser_arena_team->GetName().c_str(),winner_arena_team->GetName().c_str(),winner_arena_team->GetName().c_str());
    }

    // inform invited players about the removal
    sBattleGroundMgr.m_BattleGroundQueues[sBattleGroundMgr.BGQueueTypeId(GetTypeID(), GetArenaType())].BGEndedRemoveInvites(this);

    if(Source)
    {
        ChatHandler(Source).FillMessageData(&data, CHAT_MSG_BG_SYSTEM_NEUTRAL, LANG_UNIVERSAL, Source->GetGUID(), winmsg);
        SendPacketToAll(&data);
    }
}

uint32 BattleGround::GetBattlemasterEntry() const
{
    switch(GetTypeID())
    {
        case BATTLEGROUND_AV: return 15972;
        case BATTLEGROUND_WS: return 14623;
        case BATTLEGROUND_AB: return 14879;
        case BATTLEGROUND_EY: return 22516;
        case BATTLEGROUND_NA: return 20200;
        default:              return 0;
    }
}

void BattleGround::RewardMark(Player *plr,uint32 count)
{
    // 'Inactive' this aura prevents the player from gaining honor points and battleground tokens
    if(plr->GetDummyAura(SPELL_AURA_PLAYER_INACTIVE))
        return;

    if(!plr || !count)
        return;

    BattleGroundMarks mark;    
    switch(GetTypeID())
    {
        case BATTLEGROUND_AV:
            mark = ITEM_AV_MARK_OF_HONOR;
            break;
        case BATTLEGROUND_WS:
            mark = ITEM_WS_MARK_OF_HONOR;
            break;
        case BATTLEGROUND_AB:
            mark = ITEM_AB_MARK_OF_HONOR;
            break;
        case BATTLEGROUND_EY:            
            mark = ITEM_EY_MARK_OF_HONOR;
            break;
        default:
            return;
    }

    if ( objmgr.GetItemPrototype( mark ) )
    {
        ItemPosCountVec dest;
        uint32 no_space_count = 0;
        uint8 msg = plr->CanStoreNewItem( NULL_BAG, NULL_SLOT, dest, mark, count, &no_space_count );
        if( msg != EQUIP_ERR_OK )                       // convert to possible store amount
            count -= no_space_count;

        if(!dest.empty())                // can add some
            if(Item* item = plr->StoreNewItem( dest, mark, true, 0))
                plr->SendNewItem(item,count,false,true);

        if(no_space_count > 0)
            SendRewardMarkByMail(plr,mark,no_space_count);
    }
}

void BattleGround::SendRewardMarkByMail(Player *plr,uint32 mark, uint32 count)
{
    uint32 bmEntry = GetBattlemasterEntry();
    if(!bmEntry)
        return;

    ItemPrototype const* markProto = objmgr.GetItemPrototype(mark);
    if(!markProto)
        return;

    if(Item* markItem = Item::CreateItem(mark,count,plr))
    {
        // save new item before send
        markItem->SaveToDB();                               // save for prevent lost at next mail load, if send fail then item will deleted

        // item
        MailItemsInfo mi;
        mi.AddItem(markItem->GetGUIDLow(), markItem->GetEntry(), markItem);

        // subject: item name
        std::string subject = markProto->Name1;
        int loc_idx = plr->GetSession()->GetSessionDbLocaleIndex();
        if ( loc_idx >= 0 )
            if(ItemLocale const *il = objmgr.GetItemLocale(markProto->ItemId))
                if (il->Name.size() > size_t(loc_idx) && !il->Name[loc_idx].empty())
                    subject = il->Name[loc_idx];

        // text
        std::string textFormat = plr->GetSession()->GetTrinityString(LANG_BG_MARK_BY_MAIL);
        char textBuf[300];
        snprintf(textBuf,300,textFormat.c_str(),GetName(),GetName());
        uint32 itemTextId = objmgr.CreateItemText( textBuf );

        WorldSession::SendMailTo(plr, MAIL_CREATURE, MAIL_STATIONERY_NORMAL, bmEntry, plr->GetGUIDLow(), subject, itemTextId , &mi, 0, 0, MAIL_CHECK_MASK_NONE);
    }
}

void BattleGround::RewardQuest(Player *plr)
{
    // 'Inactive' this aura prevents the player from gaining honor points and battleground tokens
    if(plr->GetDummyAura(SPELL_AURA_PLAYER_INACTIVE))
        return;

    uint32 quest;
    switch(GetTypeID())
    {
        case BATTLEGROUND_AV:
            quest = SPELL_AV_QUEST_REWARD;
            break;
        case BATTLEGROUND_WS:
            quest = SPELL_WS_QUEST_REWARD;
            break;
        case BATTLEGROUND_AB:
            quest = SPELL_AB_QUEST_REWARD;
            break;
        case BATTLEGROUND_EY:
            quest = SPELL_EY_QUEST_REWARD;
            break;
        default:
            return;
    }

    plr->CastSpell(plr, quest, true);
}

void BattleGround::BlockMovement(Player *plr)
{
    plr->SetClientControl(plr, 0);                          // movement disabled NOTE: the effect will be automatically removed by client when the player is teleported from the battleground, so no need to send with uint8(1) in RemovePlayerAtLeave()
}

void BattleGround::RemovePlayerAtLeave(uint64 guid, bool Transport, bool SendPacket)
{
    uint32 team = GetPlayerTeam(guid);
    bool participant = false;
    // Remove from lists/maps
    std::map<uint64, BattleGroundPlayer>::iterator itr = m_Players.find(guid);
    if(itr != m_Players.end())
    {
        UpdatePlayersCountByTeam(team, true);   // -1 player
        m_Players.erase(itr);
        // check if the player was a participant of the match, or only entered through gm command (goname)
        participant = true;
    }

    std::map<uint64, BattleGroundScore*>::iterator itr2 = m_PlayerScores.find(guid);
    if(itr2 != m_PlayerScores.end())
    {
        delete itr2->second;                                // delete player's score
        m_PlayerScores.erase(itr2);
    }

    RemovePlayerFromResurrectQueue(guid);

    Player *plr = objmgr.GetPlayer(guid);

    // should remove spirit of redemption
    if(plr && plr->HasAuraType(SPELL_AURA_SPIRIT_OF_REDEMPTION))
        plr->RemoveSpellsCausingAura(SPELL_AURA_MOD_SHAPESHIFT);

    if(plr && !plr->isAlive())                              // resurrect on exit
    {
        plr->ResurrectPlayer(1.0f);
        plr->SpawnCorpseBones();
    }

    RemovePlayer(plr, guid);                                // BG subclass specific code

    if(plr)
    {
        plr->ClearAfkReports();

        if(participant) // if the player was a match participant, remove auras, calc rating, update queue
        {
            if(!team) team = plr->GetTeam();

            uint32 bgTypeId = GetTypeID();
            uint32 bgQueueTypeId = sBattleGroundMgr.BGQueueTypeId(GetTypeID(), GetArenaType());
            // if arena, remove the specific arena auras
            if(isArena())
            {
                plr->RemoveArenaAuras(true);    // removes debuffs / dots etc., we don't want the player to die after porting out
                bgTypeId=BATTLEGROUND_AA;       // set the bg type to all arenas (it will be used for queue refreshing)

                // summon old pet if there was one and there isn't a current pet
                if(!plr->GetPet() && plr->GetTemporaryUnsummonedPetNumber())
                {
                    Pet* NewPet = new Pet;
                    if(!NewPet->LoadPetFromDB(plr, 0, (plr)->GetTemporaryUnsummonedPetNumber(), true))
                        delete NewPet;

                    (plr)->SetTemporaryUnsummonedPetNumber(0);
                }

                if(isRated() && GetStatus() == STATUS_IN_PROGRESS)
                {
                    //left a rated match while the encounter was in progress, consider as loser
                    ArenaTeam * winner_arena_team = 0;
                    ArenaTeam * loser_arena_team = 0;
                    if(team == HORDE)
                    {
                        winner_arena_team = objmgr.GetArenaTeamById(GetArenaTeamIdForTeam(ALLIANCE));
                        loser_arena_team = objmgr.GetArenaTeamById(GetArenaTeamIdForTeam(HORDE));
                    }
                    else
                    {
                        winner_arena_team = objmgr.GetArenaTeamById(GetArenaTeamIdForTeam(HORDE));
                        loser_arena_team = objmgr.GetArenaTeamById(GetArenaTeamIdForTeam(ALLIANCE));
                    }
                    if(winner_arena_team && loser_arena_team)
                    {
                        loser_arena_team->MemberLost(plr,winner_arena_team->GetRating());
                    }
                }
            }

            WorldPacket data;
            if(SendPacket)
            {
                sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, this, team, plr->GetBattleGroundQueueIndex(bgQueueTypeId), STATUS_NONE, 0, 0);
                plr->GetSession()->SendPacket(&data);
            }

            // this call is important, because player, when joins to battleground, this method is not called, so it must be called when leaving bg
            plr->RemoveBattleGroundQueueId(bgQueueTypeId);

            DecreaseInvitedCount(team);
            //we should update battleground queue, but only if bg isn't ending
            if (GetQueueType() < MAX_BATTLEGROUND_QUEUES)
                sBattleGroundMgr.m_BattleGroundQueues[bgQueueTypeId].Update(bgTypeId, GetQueueType());

            Group * group = plr->GetGroup();
            // remove from raid group if exist
            if(group && group == GetBgRaid(team))
            {
                if(!group->RemoveMember(guid, 0))               // group was disbanded
                {
                    SetBgRaid(team, NULL);
                    delete group;
                }
            }

            // Let others know
            sBattleGroundMgr.BuildPlayerLeftBattleGroundPacket(&data, plr);
            SendPacketToTeam(team, &data, plr, false);
        }

        // Do next only if found in battleground
        plr->SetBattleGroundId(0);                          // We're not in BG.
        // reset destination bg team
        plr->SetBGTeam(0);

        if(Transport)
        {
            plr->TeleportTo(plr->GetBattleGroundEntryPointMap(), plr->GetBattleGroundEntryPointX(), plr->GetBattleGroundEntryPointY(), plr->GetBattleGroundEntryPointZ(), plr->GetBattleGroundEntryPointO());
        }

        // Log
        sLog.outDetail("BATTLEGROUND: Removed player %s from BattleGround.", plr->GetName());
    }

    if(!GetPlayersSize() && !GetInvitedCount(HORDE) && !GetInvitedCount(ALLIANCE))
    {
        // if no players left AND no invitees left, set this bg to delete in next update
        // direct deletion could cause crashes
        m_SetDeleteThis = true;
        // return to prevent addition to freeslotqueue
        return;
    }

    // a player exited the battleground, so there are free slots. add to queue
    this->AddToBGFreeSlotQueue();
}

// this method is called when no players remains in battleground
void BattleGround::Reset()
{
    SetQueueType(MAX_BATTLEGROUND_QUEUES);
    SetWinner(WINNER_NONE);
    SetStatus(STATUS_WAIT_QUEUE);
    SetStartTime(0);
    SetEndTime(0);
    SetLastResurrectTime(0);
    SetArenaType(0);
    SetRated(false);

    m_Events = 0;

    if (m_InvitedAlliance > 0 || m_InvitedHorde > 0)
        sLog.outError("BattleGround system ERROR: bad counter, m_InvitedAlliance: %d, m_InvitedHorde: %d", m_InvitedAlliance, m_InvitedHorde);

    m_InvitedAlliance = 0;
    m_InvitedHorde = 0;
    m_InBGFreeSlotQueue = false;

    m_Players.clear();
    m_PlayerScores.clear();

    // reset BGSubclass
    ResetBGSubclass();
}

void BattleGround::StartBattleGround()
{
    ///this method should spawn spirit guides and so on
    SetStartTime(0);
    SetLastResurrectTime(0);
    if(m_IsRated)
        sLog.outArena("Arena match type: %u for Team1Id: %u - Team2Id: %u started.", m_ArenaType, m_ArenaTeamIds[BG_TEAM_ALLIANCE], m_ArenaTeamIds[BG_TEAM_HORDE]);
}

void BattleGround::AddPlayer(Player *plr)
{
    // score struct must be created in inherited class

    uint64 guid = plr->GetGUID();
    uint32 team = plr->GetBGTeam();

    BattleGroundPlayer bp;
    bp.LastOnlineTime = 0;
    bp.Team = team;

    // Add to list/maps
    m_Players[guid] = bp;

    UpdatePlayersCountByTeam(team, false);                  // +1 player

    WorldPacket data;
    sBattleGroundMgr.BuildPlayerJoinedBattleGroundPacket(&data, plr);
    SendPacketToTeam(team, &data, plr, false);

    // add arena specific auras
    if(isArena())
    {
        plr->RemoveArenaSpellCooldowns();
        plr->RemoveArenaAuras();
        plr->RemoveAllEnchantments(TEMP_ENCHANTMENT_SLOT, true);
        if(team == ALLIANCE)                                // gold
        {
            if(plr->GetTeam() == HORDE)
                plr->CastSpell(plr, SPELL_HORDE_GOLD_FLAG,true);
            else
                plr->CastSpell(plr, SPELL_ALLIANCE_GOLD_FLAG,true);
        }
        else                                                // green
        {
            if(plr->GetTeam() == HORDE)
                plr->CastSpell(plr, SPELL_HORDE_GREEN_FLAG,true);
            else
                plr->CastSpell(plr, SPELL_ALLIANCE_GREEN_FLAG,true);
        }

        plr->DestroyConjuredItems(true);

        Pet* pet = plr->GetPet();
        if(pet)
        {
            if(pet->getPetType() == SUMMON_PET || pet->getPetType() == HUNTER_PET)
            {
                (plr)->SetTemporaryUnsummonedPetNumber(pet->GetCharmInfo()->GetPetNumber());
                (plr)->SetOldPetSpell(pet->GetUInt32Value(UNIT_CREATED_BY_SPELL));
            }
            (plr)->RemovePet(NULL,PET_SAVE_NOT_IN_SLOT);
        }
    else
            (plr)->SetTemporaryUnsummonedPetNumber(0);

        if(GetStatus() == STATUS_WAIT_JOIN)                 // not started yet
        {
            plr->CastSpell(plr, SPELL_ARENA_PREPARATION, true);

            plr->SetHealth(plr->GetMaxHealth());
            plr->SetPower(POWER_MANA, plr->GetMaxPower(POWER_MANA));
        }
    }
    else
    {
        if(GetStatus() == STATUS_WAIT_JOIN)                 // not started yet
            plr->CastSpell(plr, SPELL_PREPARATION, true);   // reduces all mana cost of spells.
    }

    // Log
    sLog.outDetail("BATTLEGROUND: Player %s joined the battle.", plr->GetName());
}

/* This method should be called only once ... it adds pointer to queue */
void BattleGround::AddToBGFreeSlotQueue()
{
    // make sure to add only once
    if(!m_InBGFreeSlotQueue)
    {
        sBattleGroundMgr.BGFreeSlotQueue[m_TypeID].push_front(this);
        m_InBGFreeSlotQueue = true;
    }
}

/* This method removes this battleground from free queue - it must be called when deleting battleground - not used now*/
void BattleGround::RemoveFromBGFreeSlotQueue()
{
    // set to be able to re-add if needed
    m_InBGFreeSlotQueue = false;
    // uncomment this code when battlegrounds will work like instances
    for (std::deque<BattleGround*>::iterator itr = sBattleGroundMgr.BGFreeSlotQueue[m_TypeID].begin(); itr != sBattleGroundMgr.BGFreeSlotQueue[m_TypeID].end(); ++itr)
    {
        if ((*itr)->GetInstanceID() == m_InstanceID)
        {
            sBattleGroundMgr.BGFreeSlotQueue[m_TypeID].erase(itr);
            return;
        }
    }
}

// get the number of free slots for team
// works in similar way that HasFreeSlotsForTeam did, but this is needed for join as group
uint32 BattleGround::GetFreeSlotsForTeam(uint32 Team) const
{
    //if BG is starting ... invite anyone
    if (GetStatus() == STATUS_WAIT_JOIN)
        return (GetInvitedCount(Team) < GetMaxPlayersPerTeam()) ? GetMaxPlayersPerTeam() - GetInvitedCount(Team) : 0;
    //if BG is already started .. do not allow to join too much players of one faction
    uint32 otherTeam;
    uint32 otherIn;
    if (Team == ALLIANCE)
    {
        otherTeam = GetInvitedCount(HORDE);
        otherIn = GetPlayersCountByTeam(HORDE);
    }
    else
    {
        otherTeam = GetInvitedCount(ALLIANCE);
        otherIn = GetPlayersCountByTeam(ALLIANCE);
    }
    if (GetStatus() == STATUS_IN_PROGRESS)
    {
        // difference based on ppl invited (not necessarily entered battle)
        // default: allow 0
        uint32 diff = 0;
        // allow join one person if the sides are equal (to fill up bg to minplayersperteam)
        if (otherTeam == GetInvitedCount(Team))
            diff = 1;
        // allow join more ppl if the other side has more players
        else if(otherTeam > GetInvitedCount(Team))
            diff = otherTeam - GetInvitedCount(Team);

        // difference based on max players per team (don't allow inviting more)
        uint32 diff2 = (GetInvitedCount(Team) < GetMaxPlayersPerTeam()) ? GetMaxPlayersPerTeam() - GetInvitedCount(Team) : 0;

        // difference based on players who already entered
        // default: allow 0
        uint32 diff3 = 0;
        // allow join one person if the sides are equal (to fill up bg minplayersperteam)
        if (otherIn == GetPlayersCountByTeam(Team))
            diff3 = 1;
        // allow join more ppl if the other side has more players
        else if (otherIn > GetPlayersCountByTeam(Team))
            diff3 = otherIn - GetPlayersCountByTeam(Team);
        // or other side has less than minPlayersPerTeam
        else if (GetInvitedCount(Team) <= GetMinPlayersPerTeam())
            diff3 = GetMinPlayersPerTeam() - GetInvitedCount(Team) + 1;

        // return the minimum of the 3 differences

        // min of diff and diff 2
        diff = diff < diff2 ? diff : diff2;

        // min of diff, diff2 and diff3
        return diff < diff3 ? diff : diff3 ;
    }

    return 0;
}

bool BattleGround::HasFreeSlots() const
{
    return GetPlayersSize() < GetMaxPlayers();
}

void BattleGround::UpdatePlayerScore(Player *Source, uint32 type, uint32 value)
{
    //this procedure is called from virtual function implemented in bg subclass
    std::map<uint64, BattleGroundScore*>::iterator itr = m_PlayerScores.find(Source->GetGUID());

    if(itr == m_PlayerScores.end())                         // player not found...
        return;

    switch(type)
    {
        case SCORE_KILLING_BLOWS:                           // Killing blows
            itr->second->KillingBlows += value;
            break;
        case SCORE_DEATHS:                                  // Deaths
            itr->second->Deaths += value;
            break;
        case SCORE_HONORABLE_KILLS:                         // Honorable kills
            itr->second->HonorableKills += value;
            break;
        case SCORE_BONUS_HONOR:                             // Honor bonus
            // do not add honor in arenas
            if(isBattleGround())
            {
                // reward honor instantly
                if(Source->RewardHonor(NULL, 1, value))
                    itr->second->BonusHonor += value;
            }
            break;
            //used only in EY, but in MSG_PVP_LOG_DATA opcode
        case SCORE_DAMAGE_DONE:                             // Damage Done
            itr->second->DamageDone += value;
            break;
        case SCORE_HEALING_DONE:                            // Healing Done
            itr->second->HealingDone += value;
            break;
        default:
            sLog.outError("BattleGround: Unknown player score type %u", type);
            break;
    }
}

void BattleGround::AddPlayerToResurrectQueue(uint64 npc_guid, uint64 player_guid)
{
    m_ReviveQueue[npc_guid].push_back(player_guid);

    Player *plr = objmgr.GetPlayer(player_guid);
    if(!plr)
        return;

    plr->CastSpell(plr, SPELL_WAITING_FOR_RESURRECT, true);
    SpellEntry const *spellInfo = sSpellStore.LookupEntry( SPELL_WAITING_FOR_RESURRECT );
    if(spellInfo)
    {
        Aura *Aur = CreateAura(spellInfo, 0, NULL, plr);
        plr->AddAura(Aur);
    }
}

void BattleGround::RemovePlayerFromResurrectQueue(uint64 player_guid)
{
    for(std::map<uint64, std::vector<uint64> >::iterator itr = m_ReviveQueue.begin(); itr != m_ReviveQueue.end(); ++itr)
    {
        for(std::vector<uint64>::iterator itr2 =(itr->second).begin(); itr2 != (itr->second).end(); ++itr2)
        {
            if(*itr2 == player_guid)
            {
                (itr->second).erase(itr2);

                Player *plr = objmgr.GetPlayer(player_guid);
                if(!plr)
                    return;

                plr->RemoveAurasDueToSpell(SPELL_WAITING_FOR_RESURRECT);

                return;
            }
        }
    }
}

bool BattleGround::AddObject(uint32 type, uint32 entry, float x, float y, float z, float o, float rotation0, float rotation1, float rotation2, float rotation3, uint32 respawnTime)
{
    Map * map = MapManager::Instance().FindMap(GetMapId(),GetInstanceID());
    if(!map)
        return false;

    // must be created this way, adding to godatamap would add it to the base map of the instance
    // and when loading it (in go::LoadFromDB()), a new guid would be assigned to the object, and a new object would be created
    // so we must create it specific for this instance
    GameObject * go = new GameObject;
    if(!go->Create(objmgr.GenerateLowGuid(HIGHGUID_GAMEOBJECT),entry, map,x,y,z,o,rotation0,rotation1,rotation2,rotation3,100,1))
    {
        sLog.outErrorDb("Gameobject template %u not found in database! BattleGround not created!", entry);
        sLog.outError("Cannot create gameobject template %u! BattleGround not created!", entry);
        delete go;
        return false;
    }
/*
    uint32 guid = go->GetGUIDLow();

    // without this, UseButtonOrDoor caused the crash, since it tried to get go info from godata
    // iirc that was changed, so adding to go data map is no longer required if that was the only function using godata from GameObject without checking if it existed
    GameObjectData& data = objmgr.NewGOData(guid);

    data.id             = entry;
    data.mapid          = GetMapId();
    data.posX           = x;
    data.posY           = y;
    data.posZ           = z;
    data.orientation    = o;
    data.rotation0      = rotation0;
    data.rotation1      = rotation1;
    data.rotation2      = rotation2;
    data.rotation3      = rotation3;
    data.spawntimesecs  = respawnTime;
    data.spawnMask      = 1;
    data.animprogress   = 100;
    data.go_state       = 1;
*/
    // add to world, so it can be later looked up from HashMapHolder
    map->Add(go);
    m_BgObjects[type] = go->GetGUID();
    return true;
}

//some doors aren't despawned so we cannot handle their closing in gameobject::update()
//it would be nice to correctly implement GO_ACTIVATED state and open/close doors in gameobject code
void BattleGround::DoorClose(uint32 type)
{
    GameObject *obj = HashMapHolder<GameObject>::Find(m_BgObjects[type]);
    if(obj)
    {
        //if doors are open, close it
        if( obj->getLootState() == GO_ACTIVATED && !obj->GetGoState() )
        {
            //change state to allow door to be closed
            obj->SetLootState(GO_READY);
            obj->UseDoorOrButton(RESPAWN_ONE_DAY);
        }
    }
    else
    {
        sLog.outError("BattleGround: Door object not found (cannot close doors)");
    }
}

void BattleGround::DoorOpen(uint32 type)
{
    GameObject *obj = HashMapHolder<GameObject>::Find(m_BgObjects[type]);
    if(obj)
    {
        //change state to be sure they will be opened
        obj->SetLootState(GO_READY);
        obj->UseDoorOrButton(RESPAWN_ONE_DAY);
    }
    else
    {
        sLog.outError("BattleGround: Door object not found! - doors will be closed.");
    }
}

GameObject* BattleGround::GetBGObject(uint32 type)
{
    GameObject *obj = HashMapHolder<GameObject>::Find(m_BgObjects[type]);
    if(!obj)
        sLog.outError("couldn't get gameobject %i",type);
    return obj;
}

Creature* BattleGround::GetBGCreature(uint32 type)
{
    Creature *creature = HashMapHolder<Creature>::Find(m_BgCreatures[type]);
    if(!creature)
        sLog.outError("couldn't get creature %i",type);
    return creature;
}

void BattleGround::SpawnBGObject(uint32 type, uint32 respawntime)
{
    Map * map = MapManager::Instance().FindMap(GetMapId(),GetInstanceID());
    if(!map)
        return;
    if( respawntime == 0 )
    {
        GameObject *obj = HashMapHolder<GameObject>::Find(m_BgObjects[type]);
        if(obj)
        {
            //we need to change state from GO_JUST_DEACTIVATED to GO_READY in case battleground is starting again
            if( obj->getLootState() == GO_JUST_DEACTIVATED )
                obj->SetLootState(GO_READY);
            obj->SetRespawnTime(0);
            map->Add(obj);
        }
    }
    else
    {
        GameObject *obj = HashMapHolder<GameObject>::Find(m_BgObjects[type]);
        if(obj)
        {
            map->Add(obj);
            obj->SetRespawnTime(respawntime);
            obj->SetLootState(GO_JUST_DEACTIVATED);
        }
    }
}

Creature* BattleGround::AddCreature(uint32 entry, uint32 type, uint32 teamval, float x, float y, float z, float o, uint32 respawntime)
{
    Map * map = MapManager::Instance().FindMap(GetMapId(),GetInstanceID());
    if(!map)
        return NULL;

    Creature* pCreature = new Creature;
    if (!pCreature->Create(objmgr.GenerateLowGuid(HIGHGUID_UNIT), map, entry, teamval))
    {
        sLog.outError("Can't create creature entry: %u",entry);
        delete pCreature;
        return NULL;
    }

    pCreature->Relocate(x, y, z, o);

    if(!pCreature->IsPositionValid())
    {
        sLog.outError("ERROR: Creature (guidlow %d, entry %d) not added to battleground. Suggested coordinates isn't valid (X: %f Y: %f)",pCreature->GetGUIDLow(),pCreature->GetEntry(),pCreature->GetPositionX(),pCreature->GetPositionY());
        delete pCreature;
        return NULL;
    }

    pCreature->SetHomePosition(x, y, z, o);
    pCreature->AIM_Initialize();

    //pCreature->SetDungeonDifficulty(0);

    map->Add(pCreature);
    m_BgCreatures[type] = pCreature->GetGUID();

    return  pCreature;
}
/*
void BattleGround::SpawnBGCreature(uint32 type, uint32 respawntime)
{
    Map * map = MapManager::Instance().FindMap(GetMapId(),GetInstanceId());
    if(!map)
        return false;

    if(respawntime == 0)
    {
        Creature *obj = HashMapHolder<Creature>::Find(m_BgCreatures[type]);
        if(obj)
        {
            //obj->Respawn();                               // bugged
            obj->SetRespawnTime(0);
            objmgr.SaveCreatureRespawnTime(obj->GetGUIDLow(), GetInstanceID(), 0);
            map->Add(obj);
        }
    }
    else
    {
        Creature *obj = HashMapHolder<Creature>::Find(m_BgCreatures[type]);
        if(obj)
        {
            obj->setDeathState(DEAD);
            obj->SetRespawnTime(respawntime);
            map->Add(obj);
        }
    }
}
*/
bool BattleGround::DelCreature(uint32 type)
{
    Creature *cr = HashMapHolder<Creature>::Find(m_BgCreatures[type]);
    if(!cr)
    {
        sLog.outError("Can't find creature guid: %u",GUID_LOPART(m_BgCreatures[type]));
        return false;
    }
    //TODO: only delete creature after not in combat
    cr->CleanupsBeforeDelete();
    cr->AddObjectToRemoveList();
    m_BgCreatures[type] = 0;
    return true;
}

bool BattleGround::DelObject(uint32 type)
{
    GameObject *obj = HashMapHolder<GameObject>::Find(m_BgObjects[type]);
    if(!obj)
    {
        sLog.outError("Can't find gobject guid: %u",GUID_LOPART(m_BgObjects[type]));
        return false;
    }
    obj->SetRespawnTime(0);                                 // not save respawn time
    obj->Delete();
    m_BgObjects[type] = 0;
    return true;
}

bool BattleGround::AddSpiritGuide(uint32 type, float x, float y, float z, float o, uint32 team)
{
    uint32 entry = 0;

    if(team == ALLIANCE)
        entry = 13116;
    else
        entry = 13117;

    Creature* pCreature = AddCreature(entry,type,team,x,y,z,o);
    if(!pCreature)
    {
        sLog.outError("Can't create Spirit guide. BattleGround not created!");
        EndNow();
        return false;
    }

    pCreature->setDeathState(DEAD);

    pCreature->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, pCreature->GetGUID());
    // aura
    pCreature->SetUInt32Value(UNIT_FIELD_AURA, SPELL_SPIRIT_HEAL_CHANNEL);
    pCreature->SetUInt32Value(UNIT_FIELD_AURAFLAGS, 0x00000009);
    pCreature->SetUInt32Value(UNIT_FIELD_AURALEVELS, 0x0000003C);
    pCreature->SetUInt32Value(UNIT_FIELD_AURAAPPLICATIONS, 0x000000FF);
    // casting visual effect
    pCreature->SetUInt32Value(UNIT_CHANNEL_SPELL, SPELL_SPIRIT_HEAL_CHANNEL);
    // correct cast speed
    pCreature->SetFloatValue(UNIT_MOD_CAST_SPEED, 1.0f);

    //pCreature->CastSpell(pCreature, SPELL_SPIRIT_HEAL_CHANNEL, true);

    return true;
}

void BattleGround::SendMessageToAll(char const* text)
{
    WorldPacket data;
    ChatHandler::FillMessageData(&data, NULL, CHAT_MSG_BG_SYSTEM_NEUTRAL, LANG_UNIVERSAL, NULL, 0, text, NULL);
    SendPacketToAll(&data);
}

void BattleGround::SendMessageToAll(int32 entry)
{
    char const* text = GetTrinityString(entry);
    WorldPacket data;
    ChatHandler::FillMessageData(&data, NULL, CHAT_MSG_BG_SYSTEM_NEUTRAL, LANG_UNIVERSAL, NULL, 0, text, NULL);
    SendPacketToAll(&data);
}

void BattleGround::EndNow()
{
    RemoveFromBGFreeSlotQueue();
    SetStatus(STATUS_WAIT_LEAVE);
    SetEndTime(TIME_TO_AUTOREMOVE);
    // inform invited players about the removal
    sBattleGroundMgr.m_BattleGroundQueues[sBattleGroundMgr.BGQueueTypeId(GetTypeID(), GetArenaType())].BGEndedRemoveInvites(this);
}

// Battleground messages are localized using the dbc lang, they are not client language dependent
const char *BattleGround::GetTrinityString(int32 entry)
{
    // FIXME: now we have different DBC locales and need localized message for each target client
    return objmgr.GetTrinityStringForDBCLocale(entry);
}

/*
important notice:
buffs aren't spawned/despawned when players captures anything
buffs are in their positions when battleground starts
*/
void BattleGround::HandleTriggerBuff(uint64 const& go_guid)
{
    GameObject *obj = HashMapHolder<GameObject>::Find(go_guid);
    if(!obj || obj->GetGoType() != GAMEOBJECT_TYPE_TRAP || !obj->isSpawned())
        return;

    //change buff type, when buff is used:
    int32 index = m_BgObjects.size() - 1;
    while (index >= 0 && m_BgObjects[index] != go_guid)
        index--;
    if (index < 0)
    {
        sLog.outError("BattleGround (Type: %u) has buff gameobject (Guid: %u Entry: %u Type:%u) but it hasn't that object in its internal data",GetTypeID(),GUID_LOPART(go_guid),obj->GetEntry(),obj->GetGoType());
        return;
    }

    //randomly select new buff
    uint8 buff = urand(0, 2);
    uint32 entry = obj->GetEntry();
    if( m_BuffChange && entry != Buff_Entries[buff] )
    {
        //despawn current buff
        SpawnBGObject(index, RESPAWN_ONE_DAY);
        //set index for new one
        for (uint8 currBuffTypeIndex = 0; currBuffTypeIndex < 3; ++currBuffTypeIndex)
            if( entry == Buff_Entries[currBuffTypeIndex] )
            {
                index -= currBuffTypeIndex;
                index += buff;
            }
    }

    SpawnBGObject(index, BUFF_RESPAWN_TIME);
}

void BattleGround::HandleKillPlayer( Player *player, Player *killer )
{
    //keep in mind that for arena this will have to be changed a bit

    // add +1 deaths
    UpdatePlayerScore(player, SCORE_DEATHS, 1);

    // add +1 kills to group and +1 killing_blows to killer
    if( killer )
    {
        UpdatePlayerScore(killer, SCORE_HONORABLE_KILLS, 1);
        UpdatePlayerScore(killer, SCORE_KILLING_BLOWS, 1);

        for(std::map<uint64, BattleGroundPlayer>::iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
        {
            Player *plr = objmgr.GetPlayer(itr->first);

            if(!plr || plr == killer)
                continue;

            if( plr->GetTeam() == killer->GetTeam() && plr->IsAtGroupRewardDistance(player) )
                UpdatePlayerScore(plr, SCORE_HONORABLE_KILLS, 1);
        }
    }

    // to be able to remove insignia
    player->SetFlag( UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE );
}

// return the player's team based on battlegroundplayer info
// used in same faction arena matches mainly
uint32 BattleGround::GetPlayerTeam(uint64 guid)
{
    std::map<uint64, BattleGroundPlayer>::const_iterator itr = m_Players.find(guid);
    if(itr!=m_Players.end())
        return itr->second.Team;
    return 0;
}

uint32 BattleGround::GetAlivePlayersCountByTeam(uint32 Team) const
{
    int count = 0;
    for(std::map<uint64, BattleGroundPlayer>::const_iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        if(itr->second.Team == Team)
        {
            Player * pl = objmgr.GetPlayer(itr->first);
            if(pl && pl->isAlive())
                ++count;
        }
    }
    return count;
}

void BattleGround::SetHoliday(bool is_holiday)
{
    if(is_holiday)
        m_HonorMode = BG_HOLIDAY;
    else
        m_HonorMode = BG_NORMAL;
}

int32 BattleGround::GetObjectType(uint64 guid)
{
    for(uint32 i = 0;i <= m_BgObjects.size(); i++)
        if(m_BgObjects[i] == guid)
            return i;
    sLog.outError("BattleGround: cheating? a player used a gameobject which isnt supposed to be a usable object!");
    return -1;
}

void BattleGround::HandleKillUnit(Creature *creature, Player *killer)
{
}

