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
#include "ArenaPackets.h"
#include "ArenaTeam.h"
#include "ArenaTeamMgr.h"
#include "BattlegroundMgr.h"
#include "CharacterCache.h"
#include "Player.h"
#include "World.h"

void WorldSession::HandleArenaTeamRosterOpcode(WorldPackets::Arena::CArenaTeamRoster& arenaTeamRoster)
{
    if (ArenaTeam* arenaTeam = sArenaTeamMgr->GetArenaTeamById(arenaTeamRoster.TeamID))
        arenaTeam->Roster(this);
}

void WorldSession::HandleArenaTeamAcceptOpcode(WorldPackets::Arena::ArenaTeamAccept& /*arenaTeamAccept*/)
{
    ArenaTeam* arenaTeam = sArenaTeamMgr->GetArenaTeamById(_player->GetArenaTeamIdInvited());
    if (!arenaTeam)
        return;

    // Check if player is already in another team of the same size
    if (_player->GetArenaTeamId(arenaTeam->GetSlot()))
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", "", ERR_ALREADY_IN_ARENA_TEAM);
        return;
    }

    // Only allow members of the other faction to join the team if cross faction interaction is enabled
    if (!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD) && _player->GetTeam() != sCharacterCache->GetCharacterTeamByGuid(arenaTeam->GetCaptain()))
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", "", ERR_ARENA_TEAM_NOT_ALLIED);
        return;
    }

    // Add player to team
    if (!arenaTeam->AddMember(_player->GetGUID()))
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", "", ERR_ARENA_TEAM_INTERNAL);
        return;
    }

    // Broadcast event
    arenaTeam->BroadcastEvent(ERR_ARENA_TEAM_JOIN_SS, _player->GetName(), arenaTeam->GetName(), "");
}

void WorldSession::HandleArenaTeamDeclineOpcode(WorldPackets::Arena::ArenaTeamDecline& /*arenaTeamAccept*/)
{
    // Remove invite from player
    _player->SetArenaTeamIdInvited(0);
}

void WorldSession::HandleArenaTeamDisbandOpcode(WorldPackets::Arena::ArenaTeamDisband& arenaTeamDisband)
{

    if (ArenaTeam* arenaTeam = sArenaTeamMgr->GetArenaTeamById(arenaTeamDisband.TeamID))
    {
        // Only captain can disband the team
        if (arenaTeam->GetCaptain() != _player->GetGUID())
            return;

        // Teams cannot be disbanded during queues
        BattlegroundQueueTypeId bgQueue = BattlegroundMgr::BGQueueTypeId(BATTLEGROUND_AA, BattlegroundQueueIdType::Arena, false, arenaTeam->GetType());

        GroupQueueInfo ginfo;
        BattlegroundQueue& queue = sBattlegroundMgr->GetBattlegroundQueue(bgQueue);
        if (queue.GetPlayerGroupInfoData(_player->GetGUID(), &ginfo))
            if (ginfo.IsInvitedToBGInstanceGUID)
                return;

        // Teams cannot be disbanded during fights
        if (arenaTeam->IsFighting())
            return;

        arenaTeam->Disband(this);
        delete arenaTeam;
    }
}

void WorldSession::HandleArenaTeamLeaveOpcode(WorldPackets::Arena::ArenaTeamLeave& arenaTeamLeave)
{
    ArenaTeam* arenaTeam = sArenaTeamMgr->GetArenaTeamById(arenaTeamLeave.TeamID);
    if (!arenaTeam)
        return;

    // Disallow leave team while in arena
    if (_player->InArena())
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_QUIT_S, "", "", ERR_ARENA_TEAM_INTERNAL);
        return;
    }

    // Team captain can't leave the team if other members are still present
    if (_player->GetGUID() == arenaTeam->GetCaptain() && arenaTeam->GetMembersSize() > 1)
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_QUIT_S, "", "", ERR_ARENA_TEAM_LEADER_LEAVE_S);
        return;
    }

    // Player cannot be removed during queues
    BattlegroundQueueTypeId bgQueue = BattlegroundMgr::BGQueueTypeId(BATTLEGROUND_AA, BattlegroundQueueIdType::Arena, false, arenaTeam->GetType());

    GroupQueueInfo ginfo;
    BattlegroundQueue& queue = sBattlegroundMgr->GetBattlegroundQueue(bgQueue);
    if (queue.GetPlayerGroupInfoData(_player->GetGUID(), &ginfo))
    {
        if (ginfo.IsInvitedToBGInstanceGUID)
        {
            SendArenaTeamCommandResult(ERR_ARENA_TEAM_QUIT_S, "", "", ERR_ARENA_TEAMS_LOCKED);
            return;
        }
    }

    // If team consists only of the captain, disband the team
    if (_player->GetGUID() == arenaTeam->GetCaptain())
    {
        arenaTeam->Disband(this);
        delete arenaTeam;
        return;
    }
    else
        arenaTeam->DelMember(_player->GetGUID(), true);

    // Broadcast event
    arenaTeam->BroadcastEvent(ERR_ARENA_TEAM_LEAVE_SS, _player->GetName(), arenaTeam->GetName(), "");

    // Inform player who left
    SendArenaTeamCommandResult(ERR_ARENA_TEAM_QUIT_S, arenaTeam->GetName(), "", 0);
}

void WorldSession::HandleQueryArenaTeamOpcode(WorldPackets::Arena::QueryArenaTeam& queryArenaTeam)
{
    if (ArenaTeam* arenaTeam = sArenaTeamMgr->GetArenaTeamById(queryArenaTeam.TeamID))
    {
        arenaTeam->Query(this);
        arenaTeam->SendStats(this);
    }
    else
    {
        WorldPackets::Arena::QueryArenaTeamResponse packet;
        packet.TeamID = queryArenaTeam.TeamID;
        packet.Allow = false;
    }
}

void WorldSession::SendArenaTeamCommandResult(uint32 teamAction, std::string const& team, std::string const& player,uint32 errorId)
{
    WorldPackets::Arena::ArenaTeamCommandResult packet;
    packet.Action = teamAction;
    packet.ErrorID = errorId;
    packet.TeamName = team;
    packet.PlayerName = player;

    SendPacket(packet.Write());
}
