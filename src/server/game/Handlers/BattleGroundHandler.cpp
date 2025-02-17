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
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "DisableMgr.h"
#include "GameTime.h"
#include "Group.h"
#include "Language.h"
#include "Log.h"
#include "NPCPackets.h"
#include "Object.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "World.h"

void WorldSession::HandleBattlemasterHelloOpcode(WorldPackets::NPC::Hello& hello)
{
    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(hello.Unit, UNIT_NPC_FLAG_BATTLEMASTER);
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
    if (!sBattlemasterListStore.LookupEntry(battlemasterJoin.BattlemasterListID))
    {
        TC_LOG_ERROR("network", "Battleground: invalid bgtype ({}) received. possible cheater? player {}", battlemasterJoin.BattlemasterListID, _player->GetGUID().ToString());
        return;
    }

    if (DisableMgr::IsDisabledFor(DISABLE_TYPE_BATTLEGROUND, battlemasterJoin.BattlemasterListID, nullptr))
    {
        ChatHandler(this).PSendSysMessage(LANG_BG_DISABLED);
        return;
    }

    BattlegroundTypeId bgTypeId = BattlegroundTypeId(battlemasterJoin.BattlemasterListID);

    // ignore if player is already in BG
    if (_player->InBattleground())
        return;

    // get bg instance or bg template if instance not found
    Battleground* bg = nullptr;
    if (battlemasterJoin.InstanceID)
        bg = sBattlegroundMgr->GetBattlegroundThroughClientInstance(battlemasterJoin.InstanceID, bgTypeId);

    if (!bg)
        bg = sBattlegroundMgr->GetBattlegroundTemplate(bgTypeId);
    if (!bg)
        return;

    // expected bracket entry
    PvPDifficultyEntry const* bracketEntry = GetBattlegroundBracketByLevel(bg->GetMapId(), _player->GetLevel());
    if (!bracketEntry)
        return;

    // can do this, since it's battleground, not arena
    BattlegroundQueueTypeId bgQueueTypeId = BattlegroundMgr::BGQueueTypeId(bgTypeId, bracketEntry->GetBracketId(), 0);

    GroupJoinBattlegroundResult err = ERR_BATTLEGROUND_NONE;

    Group const* grp = _player->GetGroup();

    // check queue conditions
    if (!battlemasterJoin.JoinAsGroup)
    {
        if (GetPlayer()->isUsingLfg())
        {
            WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
            BattlegroundMgr::BuildBattlegroundStatusFailed(&battlefieldStatus, ERR_LFG_CANT_USE_BATTLEGROUND);
            SendPacket(battlefieldStatus.Write());
            return;
        }

        // check RBAC permissions
        if (!_player->CanJoinToBattleground(bg))
        {
            WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
            BattlegroundMgr::BuildBattlegroundStatusFailed(&battlefieldStatus, ERR_BATTLEGROUND_JOIN_TIMED_OUT);
            SendPacket(battlefieldStatus.Write());
            return;
        }

        // check Deserter debuff
        if (_player->IsDeserter())
        {
            WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
            BattlegroundMgr::BuildBattlegroundStatusFailed(&battlefieldStatus, ERR_GROUP_JOIN_BATTLEGROUND_DESERTERS);
            SendPacket(battlefieldStatus.Write());
            return;
        }

        bool isInRandomBgQueue = [&]
        {
            for (uint32 i = 0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
                if (_player->GetBattlegroundQueueTypeId(i).BattlemasterListId == BATTLEGROUND_RB)
                    return true;
            return false;
        }();
        if (!BattlegroundMgr::IsRandomBattleground(bgTypeId) && isInRandomBgQueue)
        {
            // player is already in random queue
            WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
            BattlegroundMgr::BuildBattlegroundStatusFailed(&battlefieldStatus, ERR_IN_RANDOM_BG);
            SendPacket(battlefieldStatus.Write());
            return;
        }

        if (_player->InBattlegroundQueue(true) && !isInRandomBgQueue && BattlegroundMgr::IsRandomBattleground(bgTypeId))
        {
            // player is already in queue, can't start random queue
            WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
            BattlegroundMgr::BuildBattlegroundStatusFailed(&battlefieldStatus, ERR_IN_NON_RANDOM_BG);
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
            BattlegroundMgr::BuildBattlegroundStatusFailed(&battlefieldStatus, ERR_BATTLEGROUND_TOO_MANY_QUEUES);
            SendPacket(battlefieldStatus.Write());
            return;
        }

        // check Freeze debuff
        if (_player->HasAura(9454))
            return;

        BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
        GroupQueueInfo* ginfo = bgQueue.AddGroup(_player, nullptr, bracketEntry, false, isPremade, 0, 0);
        uint32 avgTime = bgQueue.GetAverageQueueWaitTime(ginfo);
        uint32 queueSlot = _player->AddBattlegroundQueueId(bgQueueTypeId);

        WorldPackets::Battleground::BattlefieldStatusQueued battlefieldStatus;
        BattlegroundMgr::BuildBattlegroundStatusQueued(&battlefieldStatus, bg, queueSlot, ginfo->JoinTime, bgQueueTypeId, avgTime);
        SendPacket(battlefieldStatus.Write());

        TC_LOG_DEBUG("bg.battleground", "Battleground: player joined queue for bg queue {{ BattlemasterListId: {}, BracketId: {}, TeamSize: {} }}, {}, NAME {}",
            bgQueueTypeId.BattlemasterListId, uint32(bgQueueTypeId.BracketId), uint32(bgQueueTypeId.TeamSize),
            _player->GetGUID().ToString(), _player->GetName());
    }
    else
    {
        if (!grp)
            return;
        if (grp->GetLeaderGUID() != _player->GetGUID())
            return;

        ObjectGuid errorGuid;
        err = grp->CanJoinBattlegroundQueue(bg, bgQueueTypeId, 0, bg->GetMaxPlayersPerTeam(), false, 0, errorGuid);
        isPremade = (grp->GetMembersCount() >= bg->GetMinPlayersPerTeam());

        BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
        GroupQueueInfo* ginfo = nullptr;
        uint32 avgTime = 0;

        if (err > 0)
        {
            TC_LOG_DEBUG("bg.battleground", "Battleground: the following players are joining as group:");
            ginfo = bgQueue.AddGroup(_player, grp, bracketEntry, false, isPremade, 0, 0);
            avgTime = bgQueue.GetAverageQueueWaitTime(ginfo);
        }

        for (GroupReference const* itr = grp->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player* member = itr->GetSource();
            if (!member)
                continue;   // this should never happen

            if (err <= 0)
            {
                WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
                BattlegroundMgr::BuildBattlegroundStatusFailed(&battlefieldStatus, err, &errorGuid);
                member->SendDirectMessage(battlefieldStatus.Write());
                continue;
            }

            // add to queue
            uint32 queueSlot = member->AddBattlegroundQueueId(bgQueueTypeId);

            WorldPackets::Battleground::BattlefieldStatusQueued battlefieldStatus;
            BattlegroundMgr::BuildBattlegroundStatusQueued(&battlefieldStatus, bg, queueSlot, ginfo->JoinTime, bgQueueTypeId, avgTime);
            member->SendDirectMessage(battlefieldStatus.Write());

            WorldPackets::Battleground::GroupJoinedBattleground groupJoinedBattleground;
            BattlegroundMgr::BuildGroupJoinedBattlegroundPacket(&groupJoinedBattleground, BattlegroundTypeId(err));
            member->SendDirectMessage(battlefieldStatus.Write());
            TC_LOG_DEBUG("bg.battleground", "Battleground: player joined queue for bg queue {{ BattlemasterListId: {}, BracketId: {}, TeamSize: {} }}, {}, NAME {}",
                bgQueueTypeId.BattlemasterListId, uint32(bgQueueTypeId.BracketId), uint32(bgQueueTypeId.TeamSize),
                member->GetGUID().ToString(), member->GetName());
        }
        TC_LOG_DEBUG("bg.battleground", "Battleground: group end");
    }
    sBattlegroundMgr->ScheduleQueueUpdate(0, bgQueueTypeId);
}

void WorldSession::HandleBattlegroundPlayerPositionsOpcode(WorldPackets::Battleground::BattlegroundPlayerPositionsRequest& /*battlegroundPlayerPositionsRequest*/)
{
    Battleground* bg = _player->GetBattleground();
    if (!bg)                                                 // can't be received if player not in battleground
        return;

    WorldPackets::Battleground::BattlegroundPlayerPositions playerPositions;
    if (ObjectGuid guid = bg->GetFlagPickerGUID(TEAM_ALLIANCE))
        if (Player* allianceFlagCarrier = ObjectAccessor::GetPlayer(*_player, guid))
            playerPositions.FlagCarriers.emplace_back(guid, allianceFlagCarrier->GetPosition());

    if (ObjectGuid guid = bg->GetFlagPickerGUID(TEAM_HORDE))
        if (Player* hordeFlagCarrier = ObjectAccessor::GetPlayer(*_player, guid))
            playerPositions.FlagCarriers.emplace_back(guid, hordeFlagCarrier->GetPosition());

    SendPacket(playerPositions.Write());
}

void WorldSession::HandlePVPLogDataOpcode(WorldPackets::Battleground::PVPLogDataRequest& /*pvpLogDataRequest*/)
{
    Battleground* bg = _player->GetBattleground();
    if (!bg)
        return;

    // Prevent players from sending BuildPvpLogDataPacket in an arena except for when sent in BattleGround::EndBattleGround.
    if (bg->isArena())
        return;

    WorldPackets::Battleground::PVPMatchStatistics pvpMatchStatistics;
    bg->BuildPvPLogDataPacket(pvpMatchStatistics);
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
    BattlegroundQueueTypeId bgQueueTypeId = BattlegroundQueueTypeId::FromPacked(battlefieldPort.QueueID);
    uint32 queueSlot = _player->GetBattlegroundQueueIndex(bgQueueTypeId);
    if (queueSlot >= PLAYER_MAX_BATTLEGROUND_QUEUES)
    {
        TC_LOG_DEBUG("bg.battleground", "CMSG_BATTLEFIELD_PORT {} queue {{ BattlemasterListId: {}, BracketId: {}, TeamSize: {} }}, AcceptedInvite: {}. Invalid queueSlot.",
            GetPlayerInfo(), bgQueueTypeId.BattlemasterListId, uint32(bgQueueTypeId.BracketId), uint32(bgQueueTypeId.TeamSize), battlefieldPort.AcceptedInvite);
        return;
    }

    BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);

    //we must use temporary variable, because GroupQueueInfo pointer can be deleted in BattlegroundQueue::RemovePlayer() function
    GroupQueueInfo ginfo;
    if (!bgQueue.GetPlayerGroupInfoData(_player->GetGUID(), &ginfo))
    {
        TC_LOG_DEBUG("bg.battleground", "CMSG_BATTLEFIELD_PORT {} queue {{ BattlemasterListId: {}, BracketId: {}, TeamSize: {} }}, AcceptedInvite: {}. Player not in queue (No player Group Info)!",
            GetPlayerInfo(), bgQueueTypeId.BattlemasterListId, uint32(bgQueueTypeId.BracketId), uint32(bgQueueTypeId.TeamSize), battlefieldPort.AcceptedInvite);
        return;
    }
    // if action == 1, then player must have been invited to join
    if (!ginfo.IsInvitedToBGInstanceGUID && battlefieldPort.AcceptedInvite)
    {
        TC_LOG_DEBUG("bg.battleground", "CMSG_BATTLEFIELD_PORT {} queue {{ BattlemasterListId: {}, BracketId: {}, TeamSize: {} }}, AcceptedInvite: {}. Player is not invited to any bg!",
            GetPlayerInfo(), bgQueueTypeId.BattlemasterListId, uint32(bgQueueTypeId.BracketId), uint32(bgQueueTypeId.TeamSize), battlefieldPort.AcceptedInvite);
        return;
    }

    BattlegroundTypeId bgTypeId = BattlegroundTypeId(bgQueueTypeId.BattlemasterListId);
    Battleground* bg = sBattlegroundMgr->GetBattleground(ginfo.IsInvitedToBGInstanceGUID, bgTypeId);
    if (!bg)
    {
        if (battlefieldPort.AcceptedInvite)
        {
            TC_LOG_DEBUG("bg.battleground", "CMSG_BATTLEFIELD_PORT {} queue {{ BattlemasterListId: {}, BracketId: {}, TeamSize: {} }}, AcceptedInvite: {}. Cant find BG with id {}!",
                GetPlayerInfo(), bgQueueTypeId.BattlemasterListId, uint32(bgQueueTypeId.BracketId), uint32(bgQueueTypeId.TeamSize), battlefieldPort.AcceptedInvite, ginfo.IsInvitedToBGInstanceGUID);
            return;
        }

        bg = sBattlegroundMgr->GetBattlegroundTemplate(bgTypeId);
        if (!bg)
        {
            TC_LOG_ERROR("network", "BattlegroundHandler: BattlegroundTemplate not found for type id {}.", bgTypeId);
            return;
        }
    }

    TC_LOG_DEBUG("bg.battleground", "CMSG_BATTLEFIELD_PORT {} queue {{ BattlemasterListId: {}, BracketId: {}, TeamSize: {} }}, AcceptedInvite: {}.",
        GetPlayerInfo(), bgQueueTypeId.BattlemasterListId, uint32(bgQueueTypeId.BracketId), uint32(bgQueueTypeId.TeamSize), battlefieldPort.AcceptedInvite);

    // expected bracket entry
    PvPDifficultyEntry const* bracketEntry = GetBattlegroundBracketByLevel(bg->GetMapId(), _player->GetLevel());
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
            BattlegroundMgr::BuildBattlegroundStatusFailed(&battlefieldStatus, ERR_GROUP_JOIN_BATTLEGROUND_DESERTERS);
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
        BattlegroundMgr::BuildBattlegroundStatusActive(&battlefieldStatus, bg, _player, queueSlot, bgQueueTypeId);
        SendPacket(battlefieldStatus.Write());

        // remove battleground queue status from BGmgr
        bgQueue.RemovePlayer(_player->GetGUID(), false);
        // this is still needed here if battleground "jumping" shouldn't add deserter debuff
        // also this is required to prevent stuck at old battleground after SetBattlegroundId set to new
        if (Battleground* currentBg = _player->GetBattleground())
            currentBg->RemovePlayerAtLeave(_player->GetGUID(), false, true);

        // set the destination instance id
        _player->SetBattlegroundId(bg->GetInstanceID(), bgTypeId);
        // set the destination team
        _player->SetBGTeam(ginfo.Team);

        // bg->HandleBeforeTeleportToBattleground(_player);
        sBattlegroundMgr->SendToBattleground(_player, ginfo.IsInvitedToBGInstanceGUID, bgTypeId);
        // add only in HandleMoveWorldPortAck()
        // bg->AddPlayer(_player, team);
        TC_LOG_DEBUG("bg.battleground", "Battleground: player {} ({}) joined battle for bg {}, bgtype {}, queue {{ BattlemasterListId: {}, BracketId: {}, TeamSize: {} }}.",
            _player->GetName(), _player->GetGUID().ToString(), bg->GetInstanceID(), bg->GetTypeID(),
            bgQueueTypeId.BattlemasterListId, uint32(bgQueueTypeId.BracketId), uint32(bgQueueTypeId.TeamSize));
    }
    else // leave queue
    {
        if (bg->isArena() && bg->GetStatus() > STATUS_WAIT_QUEUE)
            return;

        // if player leaves rated arena match before match start, it is counted as he played but he lost
        if (ginfo.IsRated && ginfo.IsInvitedToBGInstanceGUID)
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
        BattlegroundMgr::BuildBattlegroundStatusNone(&battlefieldStatus, queueSlot);
        SendPacket(battlefieldStatus.Write());

        _player->RemoveBattlegroundQueueId(bgQueueTypeId);  // must be called this way, because if you move this call to queue->removeplayer, it causes bugs
        bgQueue.RemovePlayer(_player->GetGUID(), true);
        // player left queue, we should update it - do not update Arena Queue
        if (!bgQueue.GetQueueId().TeamSize)
            sBattlegroundMgr->ScheduleQueueUpdate(ginfo.ArenaMatchmakerRating, bgQueueTypeId);

        TC_LOG_DEBUG("bg.battleground", "Battleground: player {} ({}) left queue for bgtype {}, queue {{ BattlemasterListId: {}, BracketId: {}, TeamSize: {} }}.",
            _player->GetName(), _player->GetGUID().ToString(), bg->GetTypeID(),
            bgQueueTypeId.BattlemasterListId, uint32(bgQueueTypeId.BracketId), uint32(bgQueueTypeId.TeamSize));

        // track if player refuses to join the BG after being invited
        if (bg->isBattleground() && sWorld->getBoolConfig(CONFIG_BATTLEGROUND_TRACK_DESERTERS) &&
                (bg->GetStatus() == STATUS_IN_PROGRESS || bg->GetStatus() == STATUS_WAIT_JOIN))
        {
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_DESERTER_TRACK);
            stmt->setUInt32(0, _player->GetGUID().GetCounter());
            stmt->setUInt8(1, BG_DESERTION_TYPE_LEAVE_QUEUE);
            CharacterDatabase.Execute(stmt);
        }
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
            if (bgPlayer)
            {
                //i cannot check any variable from player class because player class doesn't know if player is in 2v2 / 3v3 or 5v5 arena
                //so i must use bg pointer to get that information
                WorldPackets::Battleground::BattlefieldStatusActive battlefieldStatus;
                BattlegroundMgr::BuildBattlegroundStatusActive(&battlefieldStatus, bg, _player, i, bgQueueTypeId);
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
            BattlegroundMgr::BuildBattlegroundStatusNeedConfirmation(&battlefieldStatus, bg, i, getMSTimeDiff(GameTime::GetGameTimeMS(), ginfo.RemoveInviteTime), bgQueueTypeId);
            SendPacket(battlefieldStatus.Write());
        }
        else
        {
            bg = sBattlegroundMgr->GetBattlegroundTemplate(bgTypeId);
            if (!bg)
                continue;

            // expected bracket entry
            PvPDifficultyEntry const* bracketEntry = GetBattlegroundBracketByLevel(bg->GetMapId(), _player->GetLevel());
            if (!bracketEntry)
                continue;

            uint32 avgTime = bgQueue.GetAverageQueueWaitTime(&ginfo);
            WorldPackets::Battleground::BattlefieldStatusQueued battlefieldStatus;
            BattlegroundMgr::BuildBattlegroundStatusQueued(&battlefieldStatus, bg, i, 0, bgQueueTypeId, avgTime);
            SendPacket(battlefieldStatus.Write());
        }
    }
}

void WorldSession::HandleBattlemasterJoinArena(WorldPackets::Battleground::BattlemasterJoinArena& packet)
{
    // ignore if rated but queued solo
    if (packet.IsRated && !packet.JoinAsGroup)
        return;

    // ignore if we already in BG or BG queue
    if (_player->InBattleground())
        return;

    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(packet.BattlemasterGuid, UNIT_NPC_FLAG_BATTLEMASTER);
    if (!unit)
        return;

    uint8 arenatype = ArenaTeam::GetTypeBySlot(packet.TeamSizeIndex);
    uint32 arenaRating = 0;
    uint32 matchmakerRating = 0;
    uint32 previousOpponents = 0;

    //check existence
    Battleground* bg = sBattlegroundMgr->GetBattlegroundTemplate(BATTLEGROUND_AA);
    if (!bg)
    {
        TC_LOG_ERROR("network", "Battleground: template bg (all arenas) not found");
        return;
    }

    if (DisableMgr::IsDisabledFor(DISABLE_TYPE_BATTLEGROUND, BATTLEGROUND_AA, nullptr))
    {
        ChatHandler(this).PSendSysMessage(LANG_ARENA_DISABLED);
        return;
    }

    BattlegroundTypeId bgTypeId = bg->GetTypeID();
    PvPDifficultyEntry const* bracketEntry = GetBattlegroundBracketByLevel(bg->GetMapId(), _player->GetLevel());
    if (!bracketEntry)
        return;

    BattlegroundQueueTypeId bgQueueTypeId = BattlegroundMgr::BGQueueTypeId(bgTypeId, bracketEntry->GetBracketId(), arenatype);
    Group* grp = _player->GetGroup();
    if (!packet.JoinAsGroup)
    {
        if (_player->isUsingLfg())
        {
            // player is using dungeon finder or raid finder
            WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
            BattlegroundMgr::BuildBattlegroundStatusFailed(&battlefieldStatus, ERR_LFG_CANT_USE_BATTLEGROUND);
            SendPacket(battlefieldStatus.Write());
            return;
        }

        if (!_player->CanJoinToBattleground(bg))
        {
            WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
            BattlegroundMgr::BuildBattlegroundStatusFailed(&battlefieldStatus, ERR_BATTLEGROUND_JOIN_FAILED);
            SendPacket(battlefieldStatus.Write());
            return;
        }

        // check if already in queue
        if (_player->GetBattlegroundQueueIndex(bgQueueTypeId) < PLAYER_MAX_BATTLEGROUND_QUEUES)
            //player is already in this queue
            return;
        // check if has free queue slots
        if (!_player->HasFreeBattlegroundQueueId())
            return;
    }
    else
    {
        // no group found, error
        if (!grp)
            return;
        if (grp->GetLeaderGUID() != _player->GetGUID())
            return;
    }

    uint32 ateamId = 0;

    if (packet.IsRated)
    {
        ateamId = _player->GetArenaTeamId(packet.TeamSizeIndex);
        // check real arenateam existence only here (if it was moved to group->CanJoin .. () then we would ahve to get it twice)
        ArenaTeam* at = sArenaTeamMgr->GetArenaTeamById(ateamId);
        if (!at)
        {
            SendNotInArenaTeamPacket(arenatype);
            return;
        }

        // get the team rating for queueing
        arenaRating = at->GetRating();
        matchmakerRating = at->GetAverageMMR(grp);
        // the arenateam id must match for everyone in the group

        if (arenaRating <= 0)
            arenaRating = 1;

        previousOpponents = at->GetPreviousOpponents();
    }

    BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
    if (packet.JoinAsGroup)
    {
        uint32 avgTime = 0;
        GroupQueueInfo* ginfo = nullptr;

        ObjectGuid errorGuid;
        GroupJoinBattlegroundResult err = grp->CanJoinBattlegroundQueue(bg, bgQueueTypeId, arenatype, arenatype, true, packet.TeamSizeIndex, errorGuid);
        if (err > 0)
        {
            if (packet.IsRated)
            {
                TC_LOG_DEBUG("bg.battleground", "Battleground: arena team id {}, leader {} queued with matchmaker rating {} for type {}", _player->GetArenaTeamId(packet.TeamSizeIndex), _player->GetName(), matchmakerRating, arenatype);
                bg->SetRated(true);
            }
            else
                bg->SetRated(false);

            ginfo = bgQueue.AddGroup(_player, grp, bracketEntry, packet.IsRated, false, arenaRating, matchmakerRating, ateamId, previousOpponents);
            avgTime = bgQueue.GetAverageQueueWaitTime(ginfo);
        }

        for (GroupReference* itr = grp->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player* member = itr->GetSource();
            if (!member)
                continue;

            if (err <= 0)
            {
                WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
                BattlegroundMgr::BuildBattlegroundStatusFailed(&battlefieldStatus, err, &errorGuid);
                member->SendDirectMessage(battlefieldStatus.Write());
                continue;
            }

            if (!_player->CanJoinToBattleground(bg))
            {
                WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
                BattlegroundMgr::BuildBattlegroundStatusFailed(&battlefieldStatus, ERR_BATTLEGROUND_JOIN_FAILED, &errorGuid);
                member->SendDirectMessage(battlefieldStatus.Write());
                return;
            }

            // add to queue
            uint32 queueSlot = member->AddBattlegroundQueueId(bgQueueTypeId);

            WorldPackets::Battleground::BattlefieldStatusQueued battlefieldStatus;
            BattlegroundMgr::BuildBattlegroundStatusQueued(&battlefieldStatus, bg, queueSlot, ginfo->JoinTime, bgQueueTypeId, avgTime);
            member->SendDirectMessage(battlefieldStatus.Write());

            WorldPackets::Battleground::GroupJoinedBattleground groupJoinedBattleground;
            BattlegroundMgr::BuildGroupJoinedBattlegroundPacket(&groupJoinedBattleground, BattlegroundTypeId(err));
            member->SendDirectMessage(groupJoinedBattleground.Write());
            TC_LOG_DEBUG("bg.battleground", "Battleground: player joined queue for arena as group bg queue {{ BattlemasterListId: {}, BracketId: {}, TeamSize: {} }}, {}, NAME {}",
                bgQueueTypeId.BattlemasterListId, uint32(bgQueueTypeId.BracketId), uint32(bgQueueTypeId.TeamSize),
                member->GetGUID().ToString(), member->GetName());
        }
    }
    else
    {
        GroupQueueInfo* ginfo = bgQueue.AddGroup(_player, nullptr, bracketEntry, packet.IsRated, false, arenaRating, matchmakerRating, ateamId, previousOpponents);
        uint32 avgTime = bgQueue.GetAverageQueueWaitTime(ginfo);
        uint32 queueSlot = _player->AddBattlegroundQueueId(bgQueueTypeId);

        WorldPackets::Battleground::BattlefieldStatusQueued battlefieldStatus;
        BattlegroundMgr::BuildBattlegroundStatusQueued(&battlefieldStatus, bg, queueSlot, ginfo->JoinTime, bgQueueTypeId, avgTime);
        SendPacket(battlefieldStatus.Write());

        TC_LOG_DEBUG("bg.battleground", "Battleground: player joined queue for arena, skirmish, bg queue type {{ BattlemasterListId: {}, BracketId: {}, TeamSize: {} }}: {}, NAME {}",
            bgQueueTypeId.BattlemasterListId, uint32(bgQueueTypeId.BracketId), uint32(bgQueueTypeId.TeamSize),
            _player->GetGUID().ToString(), _player->GetName());
    }

    sBattlegroundMgr->ScheduleQueueUpdate(matchmakerRating, bgQueueTypeId);
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

void WorldSession::HandleAreaSpiritHealerQueryOpcode(WorldPackets::Battleground::AreaSpiritHealerQuery& areaSpiritHealerQuery)
{
    Player* player = GetPlayer();
    Creature* spiritHealer = ObjectAccessor::GetCreature(*player, areaSpiritHealerQuery.HealerGuid);
    if (!spiritHealer)
        return;

    if (!spiritHealer->IsSpiritService())
        return;

    if (Battleground* bg = _player->GetBattleground())
        sBattlegroundMgr->SendAreaSpiritHealerQueryOpcode(_player, bg, areaSpiritHealerQuery.HealerGuid);

    if (Battlefield* bf = sBattlefieldMgr->GetBattlefieldToZoneId(_player->GetZoneId()))
        bf->SendAreaSpiritHealerQueryOpcode(_player, areaSpiritHealerQuery.HealerGuid);
}

void WorldSession::HandleAreaSpiritHealerQueueOpcode(WorldPackets::Battleground::AreaSpiritHealerQueue& areaSpiritHealerQueue)
{
    Creature* spiritHealer = ObjectAccessor::GetCreature(*GetPlayer(), areaSpiritHealerQueue.HealerGuid);
    if (!spiritHealer)
        return;

    if (!spiritHealer->IsSpiritService())
        return;

    if (Battleground* bg = _player->GetBattleground())
        bg->AddPlayerToResurrectQueue(areaSpiritHealerQueue.HealerGuid, _player->GetGUID());

    if (Battlefield* bf = sBattlefieldMgr->GetBattlefieldToZoneId(_player->GetZoneId()))
        bf->AddPlayerToResurrectQueue(areaSpiritHealerQueue.HealerGuid, _player->GetGUID());
}

void WorldSession::HandleHearthAndResurrect(WorldPackets::Battleground::HearthAndResurrect& /*hearthAndResurrect*/)
{
    if (_player->IsInFlight())
        return;

    if (Battlefield* bf = sBattlefieldMgr->GetBattlefieldToZoneId(_player->GetZoneId()))
    {
        bf->PlayerAskToLeave(_player);
        return;
    }

    AreaTableEntry const* atEntry = sAreaTableStore.LookupEntry(_player->GetAreaId());
    if (!atEntry || !(atEntry->Flags & AREA_FLAG_WINTERGRASP_2))
        return;

    _player->BuildPlayerRepop();
    _player->ResurrectPlayer(1.0f);
    _player->TeleportTo(_player->m_homebindMapId, _player->m_homebindX, _player->m_homebindY, _player->m_homebindZ, _player->GetOrientation());
}
