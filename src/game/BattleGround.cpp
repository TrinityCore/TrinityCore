/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
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

    m_BgRaids[BG_TEAM_ALLIANCE]         = NULL;
    m_BgRaids[BG_TEAM_HORDE]            = NULL;

    m_PlayersCount[BG_TEAM_ALLIANCE]    = 0;
    m_PlayersCount[BG_TEAM_HORDE]       = 0;
}

BattleGround::~BattleGround()
{

}

void BattleGround::Update(time_t diff)
{

    if(!GetPlayersSize() && !GetRemovedPlayersSize() && !GetReviveQueueSize())
        //BG is empty
        return;

    WorldPacket data;

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

        if(plr->GetTeam() == TeamID)
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

        if(plr->GetTeam() == TeamID)
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

        if(plr->GetTeam() == TeamID)
            plr->CastSpell(plr, SpellID, true);
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

        if(plr->GetTeam() == TeamID)
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

        if(plr->GetTeam() == TeamID)
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
    WorldPacket data;
    Player *Source = NULL;
    const char *winmsg = "";

    if(winner == ALLIANCE)
    {
        winmsg = GetMangosString(LANG_BG_A_WINS);

        PlaySoundToAll(SOUND_ALLIANCE_WINS);                // alliance wins sound

        SetWinner(WINNER_ALLIANCE);
    }
    else
    {
        winmsg = GetMangosString(LANG_BG_H_WINS);

        PlaySoundToAll(SOUND_HORDE_WINS);                   // horde wins sound

        SetWinner(WINNER_HORDE);
    }

    SetStatus(STATUS_WAIT_LEAVE);
    m_EndTime = 0;

    for(std::map<uint64, BattleGroundPlayer>::iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
    {
        Player *plr = objmgr.GetPlayer(itr->first);
        if(!plr)
        {
            sLog.outError("BattleGround: Player " I64FMTD " not found!", itr->first);
            continue;
        }

        if(!plr->isAlive())
        {
            plr->ResurrectPlayer(1.0f);
            plr->SpawnCorpseBones();
        }

        if(plr->GetTeam() == winner)
        {
            if(!Source)
                Source = plr;
            RewardMark(plr,ITEM_WINNER_COUNT);
            UpdatePlayerScore(plr, SCORE_BONUS_HONOR, 20);
            RewardQuest(plr);
        }
        else
        {
            RewardMark(plr,ITEM_LOSER_COUNT);
        }

        plr->CombatStopWithPets(true);

        BlockMovement(plr);

        sBattleGroundMgr.BuildPvpLogDataPacket(&data, this);
        plr->GetSession()->SendPacket(&data);

        sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, this, plr->GetTeam(), plr->GetBattleGroundQueueIndex(m_TypeID), STATUS_IN_PROGRESS, TIME_TO_AUTOREMOVE, GetStartTime());
        plr->GetSession()->SendPacket(&data);
    }

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

    BattleGroundMarks mark;
    bool IsSpell;
    switch(GetTypeID())
    {
        case BATTLEGROUND_AV:
            IsSpell = true;
            if(count == ITEM_WINNER_COUNT)
                mark = SPELL_AV_MARK_WINNER;
            else
                mark = SPELL_AV_MARK_LOSER;
            break;
        case BATTLEGROUND_WS:
            IsSpell = true;
            if(count == ITEM_WINNER_COUNT)
                mark = SPELL_WS_MARK_WINNER;
            else
                mark = SPELL_WS_MARK_LOSER;
            break;
        case BATTLEGROUND_AB:
            IsSpell = true;
            if(count == ITEM_WINNER_COUNT)
                mark = SPELL_AB_MARK_WINNER;
            else
                mark = SPELL_AB_MARK_LOSER;
            break;
        case BATTLEGROUND_EY:
            IsSpell = false;
            mark = ITEM_EY_MARK_OF_HONOR;
            break;
        default:
            return;
    }

    if(IsSpell)
        plr->CastSpell(plr, mark, true);
    else if ( objmgr.GetItemPrototype( mark ) )
    {
        ItemPosCountVec dest;
        uint32 no_space_count = 0;
        uint8 msg = plr->CanStoreNewItem( NULL_BAG, NULL_SLOT, dest, mark, count, &no_space_count );
        if( msg != EQUIP_ERR_OK )                       // convert to possible store amount
            count -= no_space_count;

        if( count != 0 && !dest.empty())                // can add some
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
                if (il->Name.size() > loc_idx && !il->Name[loc_idx].empty())
                    subject = il->Name[loc_idx];

        // text
        std::string textFormat = plr->GetSession()->GetMangosString(LANG_BG_MARK_BY_MAIL);
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
    // Remove from lists/maps
    std::map<uint64, BattleGroundPlayer>::iterator itr = m_Players.find(guid);
    if(itr != m_Players.end())
    {
        UpdatePlayersCountByTeam(itr->second.Team, true);   // -1 player
        m_Players.erase(itr);
    }

    std::map<uint64, BattleGroundScore*>::iterator itr2 = m_PlayerScores.find(guid);
    if(itr2 != m_PlayerScores.end())
    {
        delete itr2->second;                                // delete player's score
        m_PlayerScores.erase(itr2);
    }

    RemovePlayerFromResurrectQueue(guid);

    Player *plr = objmgr.GetPlayer(guid);

    if(plr && !plr->isAlive())                              // resurrect on exit
    {
        plr->ResurrectPlayer(1.0f);
        plr->SpawnCorpseBones();
    }

    RemovePlayer(plr, guid);                                // BG subclass specific code

    if(plr)
    {
        plr->ClearAfkReports();

        if(isArena())
        {
            if(!sWorld.IsFFAPvPRealm())
                plr->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_FFA_PVP);
        }

        WorldPacket data;
        if(SendPacket)
        {
            sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, this, plr->GetTeam(), plr->GetBattleGroundQueueIndex(m_TypeID), STATUS_NONE, 0, 0);
            plr->GetSession()->SendPacket(&data);
        }

        // this call is important, because player, when joins to battleground, this method is not called, so it must be called when leaving bg
        plr->RemoveBattleGroundQueueId(m_TypeID);

        DecreaseInvitedCount(plr->GetTeam());
        //we should update battleground queue, but only if bg isn't ending
        if (GetQueueType() < MAX_BATTLEGROUND_QUEUES)
            sBattleGroundMgr.m_BattleGroundQueues[GetTypeID()].Update(GetTypeID(), GetQueueType());

        if(!plr->GetBattleGroundId())
            return;

        Group * group = plr->GetGroup();

        // remove from raid group if exist
        if(group && group == GetBgRaid(plr->GetTeam()))
        {
            if(!group->RemoveMember(guid, 0))               // group was disbanded
            {
                SetBgRaid(plr->GetTeam(), NULL);
                delete group;
            }
        }

        // Do next only if found in battleground
        plr->SetBattleGroundId(0);                          // We're not in BG.

        // Let others know
        sBattleGroundMgr.BuildPlayerLeftBattleGroundPacket(&data, plr);
        SendPacketToTeam(plr->GetTeam(), &data, plr, false);

        if(Transport)
        {
            plr->TeleportTo(plr->GetBattleGroundEntryPointMap(), plr->GetBattleGroundEntryPointX(), plr->GetBattleGroundEntryPointY(), plr->GetBattleGroundEntryPointZ(), plr->GetBattleGroundEntryPointO());
            //sLog.outDetail("BATTLEGROUND: Sending %s to %f,%f,%f,%f", pl->GetName(), x,y,z,O);
        }

        // Log
        sLog.outDetail("BATTLEGROUND: Removed player %s from BattleGround.", plr->GetName());
    }

    /// there will be code which will add battleground to BGFreeSlotQueue , when battleground instance will exist
    // we always should check if BG is in that queue before adding..

    if(!GetPlayersSize())
    {
        Reset();
    }
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

    m_Events = 0;

    if (m_InvitedAlliance > 0 || m_InvitedHorde > 0)
        sLog.outError("BattleGround system ERROR: bad counter, m_InvitedAlliance: %d, m_InvitedHorde: %d", m_InvitedAlliance, m_InvitedHorde);

    m_InvitedAlliance = 0;
    m_InvitedHorde = 0;

    m_Players.clear();
    m_PlayerScores.clear();

    // reset BGSubclass
    this->ResetBGSubclass();
}

void BattleGround::StartBattleGround()
{
    ///this method should spawn spirit guides and so on
    SetStartTime(0);

    SetLastResurrectTime(0);
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

    if(isArena())
    {
        plr->RemoveArenaSpellCooldowns();
        //plr->RemoveArenaAuras();
        plr->RemoveAllEnchantments(TEMP_ENCHANTMENT_SLOT);
        if(team == ALLIANCE && plr->GetTeam() == ALLIANCE)
            plr->CastSpell(plr,SPELL_ALLIANCE_GOLD_FLAG,true);
        else if(team == HORDE && plr->GetTeam() == ALLIANCE)
            plr->CastSpell(plr,SPELL_ALLIANCE_GREEN_FLAG,true);
        else if(team == ALLIANCE && plr->GetTeam() == HORDE)
            plr->CastSpell(plr,SPELL_HORDE_GOLD_FLAG,true);
        else
            plr->CastSpell(plr,SPELL_HORDE_GREEN_FLAG,true);
        plr->DestroyConjuredItems(true);

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

    if(isArena())
        plr->SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_FFA_PVP);

    // Log
    sLog.outDetail("BATTLEGROUND: Player %s joined the battle.", plr->GetName());
}

/* This method should be called only once ... it adds pointer to queue */
void BattleGround::AddToBGFreeSlotQueue()
{
    sBattleGroundMgr.BGFreeSlotQueue[m_TypeID].push_front(this);
}

/* This method removes this battleground from free queue - it must be called when deleting battleground - not used now*/
void BattleGround::RemoveFromBGFreeSlotQueue()
{
    /* uncomment this code when battlegrounds will work like instances
    for (std::deque<BattleGround*>::iterator itr = sBattleGroundMgr.BGFreeSlotQueue[m_TypeID].begin(); itr != sBattleGroundMgr.BGFreeSlotQueue[m_TypeID].end(); ++itr)
    {
        if ((*itr)->GetInstanceID() == m_InstanceID)
        {
            sBattleGroundMgr.BGFreeSlotQueue[m_TypeID].erase(itr);
            return;
        }
    }*/
}

/*
this method should decide, if we can invite new player of certain team to BG, it is based on BATTLEGROUND_STATUS
*/
bool BattleGround::HasFreeSlotsForTeam(uint32 Team) const
{
    //if BG is starting ... invite anyone:
    if (GetStatus() == STATUS_WAIT_JOIN)
        return GetInvitedCount(Team) < GetMaxPlayersPerTeam();
    //if BG is already started .. do not allow to join too much players of one faction
    uint32 otherTeam;
    if (Team == ALLIANCE)
        otherTeam = GetInvitedCount(HORDE);
    else
        otherTeam = GetInvitedCount(ALLIANCE);
    if (GetStatus() == STATUS_IN_PROGRESS)
        return (GetInvitedCount(Team) <= otherTeam && GetInvitedCount(Team) < GetMaxPlayersPerTeam());

    return false;
}

/* this method isn't called already, it will be useful when more battlegrounds of one type will be available */
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
            // reward honor instantly
            if(Source->RewardHonor(NULL, 1, value))
                itr->second->BonusHonor += value;
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
    GameObjectInfo const* goinfo = objmgr.GetGameObjectInfo(entry);
    if(!goinfo)
    {
        sLog.outErrorDb("Gameobject template %u not found in database! BattleGround not created!", entry);
        return false;
    }

    uint32 guid = objmgr.GenerateLowGuid(HIGHGUID_GAMEOBJECT);

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
    data.animprogress   = 100;
    data.go_state       = 1;
    data.spawnMask      = 1;
    objmgr.AddGameobjectToGrid(guid, &data);

    m_BgObjects[type] = MAKE_NEW_GUID(guid, entry, HIGHGUID_GAMEOBJECT);

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

void BattleGround::SpawnBGObject(uint32 type, uint32 respawntime)
{
    if( respawntime == 0 )
    {
        GameObject *obj = HashMapHolder<GameObject>::Find(m_BgObjects[type]);
        if(obj)
        {
            //we need to change state from GO_JUST_DEACTIVATED to GO_READY in case battleground is starting again
            if( obj->getLootState() == GO_JUST_DEACTIVATED )
                obj->SetLootState(GO_READY);
            obj->Respawn();
        }
        else
            objmgr.SaveGORespawnTime(GUID_LOPART(m_BgObjects[type]), 0, 0);
    }
    else
    {
        GameObject *obj = HashMapHolder<GameObject>::Find(m_BgObjects[type]);
        if(obj)
        {
            obj->SetRespawnTime(respawntime);
            obj->SetLootState(GO_JUST_DEACTIVATED);
        }
        else
            objmgr.SaveGORespawnTime(GUID_LOPART(m_BgObjects[type]), 0, time(NULL) + respawntime);
    }
}

Creature* BattleGround::AddCreature(uint32 entry, uint32 type, uint32 teamval, float x, float y, float z, float o)
{
    // note: this should normally be FindMap
    // but it's a hack to allow the battlegrounds to initialize at server startup
    Map * map = MapManager::Instance().GetMap(GetMapId(), 0);
    if(!map) return NULL;

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
        return NULL;
    }

    pCreature->AIM_Initialize();

    //pCreature->SetDungeonDifficulty(0);

    map->Add(pCreature);
    m_BgCreatures[type] = pCreature->GetGUID();
    return  pCreature;
}

bool BattleGround::DelCreature(uint32 type)
{
    Creature *cr = HashMapHolder<Creature>::Find(m_BgCreatures[type]);
    if(!cr)
    {
        sLog.outError("Can't find creature guid: %u",m_BgCreatures[type]);
        return false;
    }
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
        sLog.outError("Can't find gobject guid: %u",m_BgObjects[type]);
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
        this->EndNow();
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
    char const* text = GetMangosString(entry);
    WorldPacket data;
    ChatHandler::FillMessageData(&data, NULL, CHAT_MSG_BG_SYSTEM_NEUTRAL, LANG_UNIVERSAL, NULL, 0, text, NULL);
    SendPacketToAll(&data);
}

void BattleGround::EndNow()
{
    SetStatus(STATUS_WAIT_LEAVE);
    SetEndTime(TIME_TO_AUTOREMOVE);
}

// Battleground messages are localized using the dbc lang, they are not client language dependent
const char *BattleGround::GetMangosString(int32 entry)
{
    // FIXME: now we have different DBC locales and need localized message for each target client
    return objmgr.GetMangosStringForDBCLocale(entry);
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
