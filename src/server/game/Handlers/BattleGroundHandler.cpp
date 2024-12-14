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

#include "WorldSession.h"
#include "ArenaTeam.h"
#include "ArenaTeamMgr.h"
#include "Battlefield.h"
#include "BattlefieldMgr.h"
#include "Battleground.h"
#include "BattlegroundMgr.h"
#include "BattlegroundPackets.h"
#include "Chat.h"
#include "Common.h"
#include "Creature.h"
#include "DB2Stores.h"
#include "DisableMgr.h"
#include "Group.h"
#include "Language.h"
#include "Log.h"
#include "NPCPackets.h"
#include "Object.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "SpellInfo.h"
#include "World.h"

void WorldSession::HandleBattlemasterHelloOpcode(WorldPackets::NPC::Hello& hello)
{
    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(hello.Unit, UNIT_NPC_FLAG_BATTLEMASTER, UNIT_NPC_FLAG_2_NONE);
    if (!unit)
        return;

    // Stop the npc if moving
    if (uint32 pause = unit->GetMovementTemplate().GetInteractionPauseTimer())
        unit->PauseMovement(pause);
    unit->SetHomePosition(unit->GetPosition());

    BattlegroundTypeId bgTypeId = sBattlegroundMgr->GetBattleMasterBG(unit->GetEntry());

    if (!_player->GetBGAccessByLevel(bgTypeId))
    {
                                                            // temp, must be gossip message...
        SendNotification(LANG_YOUR_BG_LEVEL_REQ_ERROR);
        return;
    }

    sBattlegroundMgr->SendBattlegroundList(_player, hello.Unit, bgTypeId);
}

void WorldSession::HandleBattlemasterJoinOpcode(WorldPackets::Battleground::BattlemasterJoin& battlemasterJoin)
{
    bool isPremade = false;
    if (battlemasterJoin.QueueIDs.empty())
    {
        TC_LOG_ERROR("network", "Battleground: no bgtype received. possible cheater? {}", _player->GetGUID().ToString());
        return;
    }

    BattlegroundQueueTypeId bgQueueTypeId = BattlegroundQueueTypeId::FromPacked(battlemasterJoin.QueueIDs[0]);
    if (!BattlegroundMgr::IsValidQueueId(bgQueueTypeId))
    {
        TC_LOG_ERROR("network", "Battleground: invalid bg queue {{ BattlemasterListId: {}, Type: {}, Rated: {}, TeamSize: {} }} received. possible cheater? {}",
            bgQueueTypeId.BattlemasterListId, uint32(bgQueueTypeId.Type), bgQueueTypeId.Rated ? "true" : "false", uint32(bgQueueTypeId.TeamSize),
            _player->GetGUID().ToString());
        return;
    }

    BattlemasterListEntry const* battlemasterListEntry = sBattlemasterListStore.AssertEntry(bgQueueTypeId.BattlemasterListId);

    if (DisableMgr::IsDisabledFor(DISABLE_TYPE_BATTLEGROUND, bgQueueTypeId.BattlemasterListId, nullptr) || battlemasterListEntry->GetFlags().HasFlag(BattlemasterListFlags::InternalOnly))
    {
        ChatHandler(this).PSendSysMessage(LANG_BG_DISABLED);
        return;
    }

    BattlegroundTypeId bgTypeId = BattlegroundTypeId(bgQueueTypeId.BattlemasterListId);

    // ignore if player is already in BG
    if (_player->InBattleground())
        return;

    BattlegroundTemplate const* bgTemplate = sBattlegroundMgr->GetBattlegroundTemplateByTypeId(bgTypeId);
    if (!bgTemplate)
        return;

    // expected bracket entry
    PVPDifficultyEntry const* bracketEntry = DB2Manager::GetBattlegroundBracketByLevel(bgTemplate->MapIDs.front(), _player->GetLevel());
    if (!bracketEntry)
        return;

    GroupJoinBattlegroundResult err = ERR_BATTLEGROUND_NONE;

    Group const* grp = _player->GetGroup();

    auto getQueueTeam = [&]() -> Team
    {
        // mercenary applies only to unrated battlegrounds
        if (!bgQueueTypeId.Rated && !bgTemplate->IsArena())
        {
            if (_player->HasAura(SPELL_MERCENARY_CONTRACT_HORDE))
                return HORDE;

            if (_player->HasAura(SPELL_MERCENARY_CONTRACT_ALLIANCE))
                return ALLIANCE;
        }

        return Team(_player->GetTeam());
    };

    // check queue conditions
    if (!grp)
    {
        if (GetPlayer()->isUsingLfg())
        {
            WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
            sBattlegroundMgr->BuildBattlegroundStatusFailed(&battlefieldStatus, bgQueueTypeId, _player, 0, ERR_LFG_CANT_USE_BATTLEGROUND);
            SendPacket(battlefieldStatus.Write());
            return;
        }

        // check RBAC permissions
        if (!_player->CanJoinToBattleground(bgTemplate))
        {
            WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
            sBattlegroundMgr->BuildBattlegroundStatusFailed(&battlefieldStatus, bgQueueTypeId, _player, 0, ERR_BATTLEGROUND_JOIN_TIMED_OUT);
            SendPacket(battlefieldStatus.Write());
            return;
        }

        // check Deserter debuff
        if (_player->IsDeserter())
        {
            WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
            sBattlegroundMgr->BuildBattlegroundStatusFailed(&battlefieldStatus, bgQueueTypeId, _player, 0, ERR_GROUP_JOIN_BATTLEGROUND_DESERTERS);
            SendPacket(battlefieldStatus.Write());
            return;
        }

        bool isInRandomBgQueue = _player->InBattlegroundQueueForBattlegroundQueueType(BattlegroundMgr::BGQueueTypeId(BATTLEGROUND_RB, BattlegroundQueueIdType::Battleground, false, 0))
            || _player->InBattlegroundQueueForBattlegroundQueueType(BattlegroundMgr::BGQueueTypeId(BATTLEGROUND_RANDOM_EPIC, BattlegroundQueueIdType::Battleground, false, 0));
        if (!BattlegroundMgr::IsRandomBattleground(bgTypeId) && isInRandomBgQueue)
        {
            // player is already in random queue
            WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
            sBattlegroundMgr->BuildBattlegroundStatusFailed(&battlefieldStatus, bgQueueTypeId, _player, 0, ERR_IN_RANDOM_BG);
            SendPacket(battlefieldStatus.Write());
            return;
        }

        if (_player->InBattlegroundQueue(true) && !isInRandomBgQueue && BattlegroundMgr::IsRandomBattleground(bgTypeId))
        {
            // player is already in queue, can't start random queue
            WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
            sBattlegroundMgr->BuildBattlegroundStatusFailed(&battlefieldStatus, bgQueueTypeId, _player, 0, ERR_IN_NON_RANDOM_BG);
            SendPacket(battlefieldStatus.Write());
            return;
        }

        // check if already in queue
        if (_player->GetBattlegroundQueueIndex(bgQueueTypeId) < PLAYER_MAX_BATTLEGROUND_QUEUES)
            // player is already in this queue
            return;

        // check if has free queue slots
        if (!_player->HasFreeBattlegroundQueueId())
        {
            WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
            sBattlegroundMgr->BuildBattlegroundStatusFailed(&battlefieldStatus, bgQueueTypeId, _player, 0, ERR_BATTLEGROUND_TOO_MANY_QUEUES);
            SendPacket(battlefieldStatus.Write());
            return;
        }

        // check Freeze debuff
        if (_player->HasAura(9454))
            return;

        BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
        GroupQueueInfo* ginfo = bgQueue.AddGroup(_player, nullptr, getQueueTeam(), bracketEntry, false, isPremade, 0, 0);
        uint32 avgTime = bgQueue.GetAverageQueueWaitTime(ginfo, bracketEntry->GetBracketId());
        uint32 queueSlot = _player->AddBattlegroundQueueId(bgQueueTypeId);

        WorldPackets::Battleground::BattlefieldStatusQueued battlefieldStatus;
        sBattlegroundMgr->BuildBattlegroundStatusQueued(&battlefieldStatus, _player, queueSlot, ginfo->JoinTime, bgQueueTypeId, avgTime, false);
        SendPacket(battlefieldStatus.Write());

        TC_LOG_DEBUG("bg.battleground", "Battleground: player joined queue for bg queue {{ BattlemasterListId: {}, Type: {}, Rated: {}, TeamSize: {} }}, {}, NAME {}",
            bgQueueTypeId.BattlemasterListId, uint32(bgQueueTypeId.Type), bgQueueTypeId.Rated ? "true" : "false", uint32(bgQueueTypeId.TeamSize),
            _player->GetGUID().ToString(), _player->GetName());
    }
    else
    {
        if (grp->GetLeaderGUID() != _player->GetGUID())
            return;

        ObjectGuid errorGuid;
        err = grp->CanJoinBattlegroundQueue(bgTemplate, bgQueueTypeId, 0, bgTemplate->GetMaxPlayersPerTeam(), false, 0, errorGuid);
        isPremade = (grp->GetMembersCount() >= bgTemplate->GetMinPlayersPerTeam());

        BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
        GroupQueueInfo* ginfo = nullptr;
        uint32 avgTime = 0;

        if (!err)
        {
            TC_LOG_DEBUG("bg.battleground", "Battleground: the following players are joining as group:");
            ginfo = bgQueue.AddGroup(_player, grp, getQueueTeam(), bracketEntry, false, isPremade, 0, 0);
            avgTime = bgQueue.GetAverageQueueWaitTime(ginfo, bracketEntry->GetBracketId());
        }

        for (GroupReference const* itr = grp->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player* member = itr->GetSource();
            if (!member)
                continue;   // this should never happen

            if (err)
            {
                WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
                sBattlegroundMgr->BuildBattlegroundStatusFailed(&battlefieldStatus, bgQueueTypeId, _player, 0, err, &errorGuid);
                member->SendDirectMessage(battlefieldStatus.Write());
                continue;
            }

            // add to queue
            uint32 queueSlot = member->AddBattlegroundQueueId(bgQueueTypeId);

            WorldPackets::Battleground::BattlefieldStatusQueued battlefieldStatus;
            sBattlegroundMgr->BuildBattlegroundStatusQueued(&battlefieldStatus, member, queueSlot, ginfo->JoinTime, bgQueueTypeId, avgTime, true);
            member->SendDirectMessage(battlefieldStatus.Write());
            TC_LOG_DEBUG("bg.battleground", "Battleground: player joined queue for bg queue {{ BattlemasterListId: {}, Type: {}, Rated: {}, TeamSize: {} }}, {}, NAME {}",
                bgQueueTypeId.BattlemasterListId, uint32(bgQueueTypeId.Type), bgQueueTypeId.Rated ? "true" : "false", uint32(bgQueueTypeId.TeamSize),
                member->GetGUID().ToString(), member->GetName());
        }
        TC_LOG_DEBUG("bg.battleground", "Battleground: group end");
    }

    sBattlegroundMgr->ScheduleQueueUpdate(0, bgQueueTypeId, bracketEntry->GetBracketId());
}

void WorldSession::HandlePVPLogDataOpcode(WorldPackets::Battleground::PVPLogDataRequest& /*pvpLogDataRequest*/)
{
    Battleground* bg = _player->GetBattleground();
    if (!bg)
        return;

    // Prevent players from sending BuildPvpLogDataPacket in an arena except for when sent in BattleGround::EndBattleGround.
    if (bg->isArena())
        return;

    WorldPackets::Battleground::PVPMatchStatisticsMessage pvpMatchStatistics;
    bg->BuildPvPLogDataPacket(pvpMatchStatistics.Data);
    SendPacket(pvpMatchStatistics.Write());
}

void WorldSession::HandleBattlefieldListOpcode(WorldPackets::Battleground::BattlefieldListRequest& battlefieldList)
{
    BattlemasterListEntry const* battlemasterListEntry = sBattlemasterListStore.LookupEntry(battlefieldList.ListID);
    if (!battlemasterListEntry)
    {
        TC_LOG_DEBUG("bg.battleground", "BattlegroundHandler: invalid bgtype ({}) with player (Name: {}, {}) received.", battlefieldList.ListID, _player->GetName(), _player->GetGUID().ToString());
        return;
    }

    sBattlegroundMgr->SendBattlegroundList(_player, ObjectGuid::Empty, BattlegroundTypeId(battlefieldList.ListID));
}

void WorldSession::HandleBattleFieldPortOpcode(WorldPackets::Battleground::BattlefieldPort& battlefieldPort)
{
    if (!_player->InBattlegroundQueue())
    {
        TC_LOG_DEBUG("bg.battleground", "CMSG_BATTLEFIELD_PORT {} Slot: {}, Unk: {}, Time: {}, AcceptedInvite: {}. Player not in queue!",
            GetPlayerInfo(), battlefieldPort.Ticket.Id, uint32(battlefieldPort.Ticket.Type), battlefieldPort.Ticket.Time.AsUnderlyingType(), uint32(battlefieldPort.AcceptedInvite));
        return;
    }

    BattlegroundQueueTypeId bgQueueTypeId = _player->GetBattlegroundQueueTypeId(battlefieldPort.Ticket.Id);
    if (bgQueueTypeId == BATTLEGROUND_QUEUE_NONE)
    {
        TC_LOG_DEBUG("bg.battleground", "CMSG_BATTLEFIELD_PORT {} Slot: {}, Unk: {}, Time: {}, AcceptedInvite: {}. Invalid queueSlot!",
            GetPlayerInfo(), battlefieldPort.Ticket.Id, uint32(battlefieldPort.Ticket.Type), battlefieldPort.Ticket.Time.AsUnderlyingType(), uint32(battlefieldPort.AcceptedInvite));
        return;
    }

    BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);

    //we must use temporary variable, because GroupQueueInfo pointer can be deleted in BattlegroundQueue::RemovePlayer() function
    GroupQueueInfo ginfo;
    if (!bgQueue.GetPlayerGroupInfoData(_player->GetGUID(), &ginfo))
    {
        TC_LOG_DEBUG("bg.battleground", "CMSG_BATTLEFIELD_PORT {} Slot: {}, Unk: {}, Time: {}, AcceptedInvite: {}. Player not in queue (No player Group Info)!",
            GetPlayerInfo(), battlefieldPort.Ticket.Id, uint32(battlefieldPort.Ticket.Type), battlefieldPort.Ticket.Time.AsUnderlyingType(), uint32(battlefieldPort.AcceptedInvite));
        return;
    }
    // if action == 1, then player must have been invited to join
    if (!ginfo.IsInvitedToBGInstanceGUID && battlefieldPort.AcceptedInvite)
    {
        TC_LOG_DEBUG("bg.battleground", "CMSG_BATTLEFIELD_PORT {} Slot: {}, Unk: {}, Time: {}, AcceptedInvite: {}. Player is not invited to any bg!",
            GetPlayerInfo(), battlefieldPort.Ticket.Id, uint32(battlefieldPort.Ticket.Type), battlefieldPort.Ticket.Time.AsUnderlyingType(), uint32(battlefieldPort.AcceptedInvite));
        return;
    }

    BattlegroundTypeId bgTypeId = BattlegroundTypeId(bgQueueTypeId.BattlemasterListId);
    BattlegroundTemplate const* bgTemplate = sBattlegroundMgr->GetBattlegroundTemplateByTypeId(bgTypeId);
    if (!bgTemplate)
    {
        TC_LOG_ERROR("network", "BattlegroundHandle: BattlegroundTemplate not found for type id {}.", bgTypeId);
        return;
    }

    uint32 mapId = bgTemplate->MapIDs.front();

    // BGTemplateId returns BATTLEGROUND_AA when it is arena queue.
    // Do instance id search as there is no AA bg instances.
    Battleground* bg = sBattlegroundMgr->GetBattleground(ginfo.IsInvitedToBGInstanceGUID, bgTypeId == BATTLEGROUND_AA ? BATTLEGROUND_TYPE_NONE : bgTypeId);
    if (!bg && battlefieldPort.AcceptedInvite)
    {
        TC_LOG_DEBUG("bg.battleground", "CMSG_BATTLEFIELD_PORT {} Slot: {}, Unk: {}, Time: {}, AcceptedInvite: {}. Cant find BG with id {}!",
            GetPlayerInfo(), battlefieldPort.Ticket.Id, uint32(battlefieldPort.Ticket.Type), battlefieldPort.Ticket.Time.AsUnderlyingType(), uint32(battlefieldPort.AcceptedInvite), ginfo.IsInvitedToBGInstanceGUID);
        return;
    }
    else if (bg)
        mapId = bg->GetMapId();

    TC_LOG_DEBUG("bg.battleground", "CMSG_BATTLEFIELD_PORT {} Slot: {}, Unk: {}, Time: {}, AcceptedInvite: {}.",
        GetPlayerInfo(), battlefieldPort.Ticket.Id, uint32(battlefieldPort.Ticket.Type), battlefieldPort.Ticket.Time.AsUnderlyingType(), uint32(battlefieldPort.AcceptedInvite));

    // expected bracket entry
    PVPDifficultyEntry const* bracketEntry = DB2Manager::GetBattlegroundBracketByLevel(mapId, _player->GetLevel());
    if (!bracketEntry)
        return;

    //some checks if player isn't cheating - it is not exactly cheating, but we cannot allow it
    if (battlefieldPort.AcceptedInvite && bgQueue.GetQueueId().TeamSize == 0)
    {
        //if player is trying to enter battleground (not arena!) and he has deserter debuff, we must just remove him from queue
        if (_player->IsDeserter())
        {
            //send bg command result to show nice message
            WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
            sBattlegroundMgr->BuildBattlegroundStatusFailed(&battlefieldStatus, bgQueueTypeId, _player, battlefieldPort.Ticket.Id, ERR_GROUP_JOIN_BATTLEGROUND_DESERTERS);
            SendPacket(battlefieldStatus.Write());
            battlefieldPort.AcceptedInvite = false;
            TC_LOG_DEBUG("bg.battleground", "Player {} {} has a deserter debuff, do not port him to battleground!", _player->GetName(), _player->GetGUID().ToString());
        }
        //if player don't match battleground max level, then do not allow him to enter! (this might happen when player leveled up during his waiting in queue
        if (_player->GetLevel() > bg->GetMaxLevel())
        {
            TC_LOG_ERROR("network", "Player {} {} has level ({}) higher than maxlevel ({}) of battleground ({})! Do not port him to battleground!",
                _player->GetName(), _player->GetGUID().ToString(), _player->GetLevel(), bg->GetMaxLevel(), bg->GetTypeID());
            battlefieldPort.AcceptedInvite = false;
        }
    }

    if (battlefieldPort.AcceptedInvite)
    {
        // check Freeze debuff
        if (_player->HasAura(9454))
            return;

        if (!_player->IsInvitedForBattlegroundQueueType(bgQueueTypeId))
            return;                                 // cheating?

        if (!_player->InBattleground())
            _player->SetBattlegroundEntryPoint();

        // resurrect the player
        if (!_player->IsAlive())
        {
            _player->ResurrectPlayer(1.0f);
            _player->SpawnCorpseBones();
        }
        // stop taxi flight at port
        _player->FinishTaxiFlight();

        WorldPackets::Battleground::BattlefieldStatusActive battlefieldStatus;
        sBattlegroundMgr->BuildBattlegroundStatusActive(&battlefieldStatus, bg, _player, battlefieldPort.Ticket.Id, _player->GetBattlegroundQueueJoinTime(bgQueueTypeId), bgQueueTypeId);
        SendPacket(battlefieldStatus.Write());

        // remove battleground queue status from BGmgr
        bgQueue.RemovePlayer(_player->GetGUID(), false);
        // this is still needed here if battleground "jumping" shouldn't add deserter debuff
        // also this is required to prevent stuck at old battleground after SetBattlegroundId set to new
        if (Battleground* currentBg = _player->GetBattleground())
            currentBg->RemovePlayerAtLeave(_player->GetGUID(), false, true);

        // set the destination instance id
        _player->SetBattlegroundId(bg->GetInstanceID(), bg->GetTypeID(), bgQueueTypeId);
        // set the destination team
        _player->SetBGTeam(ginfo.Team);

        // bg->HandleBeforeTeleportToBattleground(_player);
        sBattlegroundMgr->SendToBattleground(_player, ginfo.IsInvitedToBGInstanceGUID, bgTypeId);
        // add only in HandleMoveWorldPortAck()
        // bg->AddPlayer(_player, team);
        TC_LOG_DEBUG("bg.battleground", "Battleground: player {} ({}) joined battle for bg {}, bgtype {}, queue {{ BattlemasterListId: {}, Type: {}, Rated: {}, TeamSize: {} }}.",
            _player->GetName(), _player->GetGUID().ToString(), bg->GetInstanceID(), bg->GetTypeID(),
            bgQueueTypeId.BattlemasterListId, uint32(bgQueueTypeId.Type), bgQueueTypeId.Rated ? "true" : "false", uint32(bgQueueTypeId.TeamSize));
    }
    else // leave queue
    {
        // if player leaves rated arena match before match start, it is counted as he played but he lost
        if (bgQueue.GetQueueId().Rated && ginfo.IsInvitedToBGInstanceGUID)
        {
            ArenaTeam* at = sArenaTeamMgr->GetArenaTeamById(ginfo.Team);
            if (at)
            {
                TC_LOG_DEBUG("bg.battleground", "UPDATING memberLost's personal arena rating for {} by opponents rating: {}, because he has left queue!", _player->GetGUID().ToString(), ginfo.OpponentsTeamRating);
                at->MemberLost(_player, ginfo.OpponentsMatchmakerRating);
                at->SaveToDB();
            }
        }

        WorldPackets::Battleground::BattlefieldStatusNone battlefieldStatus;
        battlefieldStatus.Ticket = battlefieldPort.Ticket;
        SendPacket(battlefieldStatus.Write());

        _player->RemoveBattlegroundQueueId(bgQueueTypeId);  // must be called this way, because if you move this call to queue->removeplayer, it causes bugs
        bgQueue.RemovePlayer(_player->GetGUID(), true);
        // player left queue, we should update it - do not update Arena Queue
        if (!bgQueue.GetQueueId().TeamSize)
            sBattlegroundMgr->ScheduleQueueUpdate(ginfo.ArenaMatchmakerRating, bgQueueTypeId, bracketEntry->GetBracketId());

        TC_LOG_DEBUG("bg.battleground", "Battleground: player {} ({}) left queue for bgtype {}, queue {{ BattlemasterListId: {}, Type: {}, Rated: {}, TeamSize: {} }}.",
            _player->GetName(), _player->GetGUID().ToString(), bg->GetTypeID(),
            bgQueueTypeId.BattlemasterListId, uint32(bgQueueTypeId.Type), bgQueueTypeId.Rated ? "true" : "false", uint32(bgQueueTypeId.TeamSize));
    }
}

void WorldSession::HandleBattlefieldLeaveOpcode(WorldPackets::Battleground::BattlefieldLeave& /*battlefieldLeave*/)
{
    // not allow leave battleground in combat
    if (_player->IsInCombat())
        if (Battleground* bg = _player->GetBattleground())
            if (bg->GetStatus() != STATUS_WAIT_LEAVE)
                return;

    _player->LeaveBattleground();
}

void WorldSession::HandleRequestBattlefieldStatusOpcode(WorldPackets::Battleground::RequestBattlefieldStatus& /*requestBattlefieldStatus*/)
{
    // we must update all queues here
    Battleground* bg = nullptr;
    for (uint8 i = 0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
    {
        BattlegroundQueueTypeId bgQueueTypeId = _player->GetBattlegroundQueueTypeId(i);
        if (bgQueueTypeId == BATTLEGROUND_QUEUE_NONE)
            continue;
        BattlegroundTypeId bgTypeId = BattlegroundTypeId(bgQueueTypeId.BattlemasterListId);
        bg = _player->GetBattleground();
        if (bg)
        {
            BattlegroundPlayer const* bgPlayer = bg->GetBattlegroundPlayerData(_player->GetGUID());
            if (bgPlayer && bgPlayer->queueTypeId == bgQueueTypeId)
            {
                //i cannot check any variable from player class because player class doesn't know if player is in 2v2 / 3v3 or 5v5 arena
                //so i must use bg pointer to get that information
                WorldPackets::Battleground::BattlefieldStatusActive battlefieldStatus;
                sBattlegroundMgr->BuildBattlegroundStatusActive(&battlefieldStatus, bg, _player, i, _player->GetBattlegroundQueueJoinTime(bgQueueTypeId), bgQueueTypeId);
                SendPacket(battlefieldStatus.Write());
                continue;
            }
        }

        //we are sending update to player about queue - he can be invited there!
        //get GroupQueueInfo for queue status
        BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
        GroupQueueInfo ginfo;
        if (!bgQueue.GetPlayerGroupInfoData(_player->GetGUID(), &ginfo))
            continue;
        if (ginfo.IsInvitedToBGInstanceGUID)
        {
            bg = sBattlegroundMgr->GetBattleground(ginfo.IsInvitedToBGInstanceGUID, bgTypeId);
            if (!bg)
                continue;

            WorldPackets::Battleground::BattlefieldStatusNeedConfirmation battlefieldStatus;
            sBattlegroundMgr->BuildBattlegroundStatusNeedConfirmation(&battlefieldStatus, bg, _player, i, _player->GetBattlegroundQueueJoinTime(bgQueueTypeId), getMSTimeDiff(getMSTime(), ginfo.RemoveInviteTime), bgQueueTypeId);
            SendPacket(battlefieldStatus.Write());
        }
        else
        {
            BattlegroundTemplate const* bgTemplate  = sBattlegroundMgr->GetBattlegroundTemplateByTypeId(bgTypeId);
            if (!bgTemplate)
                continue;

            // expected bracket entry
            PVPDifficultyEntry const* bracketEntry = DB2Manager::GetBattlegroundBracketByLevel(bgTemplate->MapIDs.front(), _player->GetLevel());
            if (!bracketEntry)
                continue;

            uint32 avgTime = bgQueue.GetAverageQueueWaitTime(&ginfo, bracketEntry->GetBracketId());
            WorldPackets::Battleground::BattlefieldStatusQueued battlefieldStatus;
            sBattlegroundMgr->BuildBattlegroundStatusQueued(&battlefieldStatus, _player, i, _player->GetBattlegroundQueueJoinTime(bgQueueTypeId), bgQueueTypeId, avgTime, ginfo.Players.size() > 1);
            SendPacket(battlefieldStatus.Write());
        }
    }
}

void WorldSession::HandleBattlemasterJoinArena(WorldPackets::Battleground::BattlemasterJoinArena& packet)
{
    // ignore if we already in BG or BG queue
    if (_player->InBattleground())
        return;

    uint8 arenatype = ArenaTeam::GetTypeBySlot(packet.TeamSizeIndex);

    //check existence
    BattlegroundTemplate const* bgTemplate = sBattlegroundMgr->GetBattlegroundTemplateByTypeId(BATTLEGROUND_AA);
    if (!bgTemplate)
    {
        TC_LOG_ERROR("network", "Battleground: template bg (all arenas) not found");
        return;
    }

    if (DisableMgr::IsDisabledFor(DISABLE_TYPE_BATTLEGROUND, BATTLEGROUND_AA, nullptr))
    {
        ChatHandler(this).PSendSysMessage(LANG_ARENA_DISABLED);
        return;
    }

    BattlegroundTypeId bgTypeId = bgTemplate->Id;
    BattlegroundQueueTypeId bgQueueTypeId = BattlegroundMgr::BGQueueTypeId(bgTypeId, BattlegroundQueueIdType::Arena, true, arenatype);
    PVPDifficultyEntry const* bracketEntry = DB2Manager::GetBattlegroundBracketByLevel(bgTemplate->MapIDs.front(), _player->GetLevel());
    if (!bracketEntry)
        return;

    Group* grp = _player->GetGroup();
    // no group found, error
    if (!grp)
        return;
    if (grp->GetLeaderGUID() != _player->GetGUID())
        return;

    uint32 ateamId = _player->GetArenaTeamId(packet.TeamSizeIndex);
    // check real arenateam existence only here (if it was moved to group->CanJoin .. () then we would ahve to get it twice)
    ArenaTeam* at = sArenaTeamMgr->GetArenaTeamById(ateamId);
    if (!at)
        return;

    // get the team rating for queuing
    uint32 arenaRating = at->GetRating();
    uint32 matchmakerRating = at->GetAverageMMR(grp);
    // the arenateam id must match for everyone in the group

    if (arenaRating <= 0)
        arenaRating = 1;

    BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);

    uint32 avgTime = 0;
    GroupQueueInfo* ginfo = nullptr;

    ObjectGuid errorGuid;
    GroupJoinBattlegroundResult err = grp->CanJoinBattlegroundQueue(bgTemplate, bgQueueTypeId, arenatype, arenatype, true, packet.TeamSizeIndex, errorGuid);
    if (!err)
    {
        TC_LOG_DEBUG("bg.battleground", "Battleground: arena team id {}, leader {} queued with matchmaker rating {} for type {}", _player->GetArenaTeamId(packet.TeamSizeIndex), _player->GetName(), matchmakerRating, arenatype);

        ginfo = bgQueue.AddGroup(_player, grp, Team(_player->GetTeam()), bracketEntry, false, arenaRating, matchmakerRating, ateamId);
        avgTime = bgQueue.GetAverageQueueWaitTime(ginfo, bracketEntry->GetBracketId());
    }

    for (GroupReference* itr = grp->GetFirstMember(); itr != nullptr; itr = itr->next())
    {
        Player* member = itr->GetSource();
        if (!member)
            continue;

        if (err)
        {
            WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
            sBattlegroundMgr->BuildBattlegroundStatusFailed(&battlefieldStatus, bgQueueTypeId, _player, 0, err, &errorGuid);
            member->SendDirectMessage(battlefieldStatus.Write());
            continue;
        }

        if (!_player->CanJoinToBattleground(bgTemplate))
        {
            WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
            sBattlegroundMgr->BuildBattlegroundStatusFailed(&battlefieldStatus, bgQueueTypeId, _player, 0, ERR_BATTLEGROUND_JOIN_FAILED, &errorGuid);
            member->SendDirectMessage(battlefieldStatus.Write());
            return;
        }

        // add to queue
        uint32 queueSlot = member->AddBattlegroundQueueId(bgQueueTypeId);

        WorldPackets::Battleground::BattlefieldStatusQueued battlefieldStatus;
        sBattlegroundMgr->BuildBattlegroundStatusQueued(&battlefieldStatus, member, queueSlot, ginfo->JoinTime, bgQueueTypeId, avgTime, true);
        member->SendDirectMessage(battlefieldStatus.Write());

        TC_LOG_DEBUG("bg.battleground", "Battleground: player joined queue for arena as group bg queue {{ BattlemasterListId: {}, Type: {}, Rated: {}, TeamSize: {} }}, {}, NAME {}",
            bgQueueTypeId.BattlemasterListId, uint32(bgQueueTypeId.Type), bgQueueTypeId.Rated ? "true" : "false", uint32(bgQueueTypeId.TeamSize),
            member->GetGUID().ToString(), member->GetName());
    }

    sBattlegroundMgr->ScheduleQueueUpdate(matchmakerRating, bgQueueTypeId, bracketEntry->GetBracketId());
}

void WorldSession::HandleReportPvPAFK(WorldPackets::Battleground::ReportPvPPlayerAFK& reportPvPPlayerAFK)
{
    Player* reportedPlayer = ObjectAccessor::FindPlayer(reportPvPPlayerAFK.Offender);
    if (!reportedPlayer)
    {
        TC_LOG_INFO("bg.reportpvpafk", "WorldSession::HandleReportPvPAFK: {} [IP: {}] reported {}", _player->GetName(), _player->GetSession()->GetRemoteAddress(), reportPvPPlayerAFK.Offender.ToString());
        return;
    }

    TC_LOG_DEBUG("bg.battleground", "WorldSession::HandleReportPvPAFK: {} reported {}", _player->GetName(), reportedPlayer->GetName());

    reportedPlayer->ReportedAfkBy(_player);
}

void WorldSession::HandleRequestRatedPvpInfo(WorldPackets::Battleground::RequestRatedPvpInfo& /*packet*/)
{
    WorldPackets::Battleground::RatedPvpInfo ratedPvpInfo;
    SendPacket(ratedPvpInfo.Write());
}

void WorldSession::HandleGetPVPOptionsEnabled(WorldPackets::Battleground::GetPVPOptionsEnabled& /*getPvPOptionsEnabled*/)
{
    WorldPackets::Battleground::PVPOptionsEnabled pvpOptionsEnabled;
    pvpOptionsEnabled.RatedBattlegrounds = false;
    pvpOptionsEnabled.PugBattlegrounds = true;
    pvpOptionsEnabled.WargameBattlegrounds = false;
    pvpOptionsEnabled.WargameArenas = false;
    pvpOptionsEnabled.RatedArenas = false;
    pvpOptionsEnabled.ArenaSkirmish = false;
    pvpOptionsEnabled.SoloShuffle = false;
    pvpOptionsEnabled.RatedSoloShuffle = false;
    pvpOptionsEnabled.BattlegroundBlitz = false;
    pvpOptionsEnabled.RatedBattlegroundBlitz = false;
    SendPacket(pvpOptionsEnabled.Write());
}

void WorldSession::HandleRequestPvpReward(WorldPackets::Battleground::RequestPVPRewards& /*packet*/)
{
    _player->SendPvpRewards();
}

void WorldSession::HandleAreaSpiritHealerQueryOpcode(WorldPackets::Battleground::AreaSpiritHealerQuery& areaSpiritHealerQuery)
{
    Player* player = GetPlayer();
    Creature* spiritHealer = ObjectAccessor::GetCreature(*player, areaSpiritHealerQuery.HealerGuid);
    if (!spiritHealer)
        return;

    if (!spiritHealer->IsAreaSpiritHealer())
        return;

    if (!_player->IsWithinDistInMap(spiritHealer, MAX_AREA_SPIRIT_HEALER_RANGE))
        return;

    if (spiritHealer->IsAreaSpiritHealerIndividual())
    {
        if (Aura* aura = player->GetAura(SPELL_SPIRIT_HEAL_PLAYER_AURA))
        {
            player->SendAreaSpiritHealerTime(spiritHealer->GetGUID(), aura->GetDuration());
        }
        else if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_SPIRIT_HEAL_PLAYER_AURA, DIFFICULTY_NONE))
        {
            spiritHealer->CastSpell(player, SPELL_SPIRIT_HEAL_PLAYER_AURA);
            player->SendAreaSpiritHealerTime(spiritHealer->GetGUID(), spellInfo->GetDuration());
            spiritHealer->CastSpell(nullptr, SPELL_SPIRIT_HEAL_CHANNEL_SELF);
        }
    }
    else
        _player->SendAreaSpiritHealerTime(spiritHealer);
}

void WorldSession::HandleAreaSpiritHealerQueueOpcode(WorldPackets::Battleground::AreaSpiritHealerQueue& areaSpiritHealerQueue)
{
    Creature* spiritHealer = ObjectAccessor::GetCreature(*GetPlayer(), areaSpiritHealerQueue.HealerGuid);
    if (!spiritHealer)
        return;

    if (!spiritHealer->IsAreaSpiritHealer())
        return;

    if (!_player->IsWithinDistInMap(spiritHealer, MAX_AREA_SPIRIT_HEALER_RANGE))
        return;

    _player->SetAreaSpiritHealer(spiritHealer);
}

void WorldSession::HandleHearthAndResurrect(WorldPackets::Battleground::HearthAndResurrect& /*hearthAndResurrect*/)
{
    if (_player->IsInFlight())
        return;

    if (Battlefield* bf = sBattlefieldMgr->GetBattlefieldToZoneId(_player->GetMap(), _player->GetZoneId()))
    {
        bf->PlayerAskToLeave(_player);
        return;
    }

    AreaTableEntry const* atEntry = sAreaTableStore.LookupEntry(_player->GetAreaId());
    if (!atEntry || !(atEntry->GetFlags().HasFlag(AreaFlags::AllowHearthAndRessurectFromArea)))
        return;

    _player->BuildPlayerRepop();
    _player->ResurrectPlayer(1.0f);
    _player->TeleportTo(_player->m_homebind);
}
