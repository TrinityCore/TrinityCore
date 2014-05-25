/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "Player.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "DatabaseEnv.h"

#include "ArenaTeam.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "SocialMgr.h"
#include "ArenaTeamMgr.h"
#include "Opcodes.h"

void WorldSession::HandleInspectArenaTeamsOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "MSG_INSPECT_ARENA_TEAMS");

    uint64 guid;
    recvData >> guid;
    TC_LOG_DEBUG("network", "Inspect Arena stats (GUID: %u TypeId: %u)", GUID_LOPART(guid), GuidHigh2TypeId(GUID_HIPART(guid)));

    Player* player = ObjectAccessor::FindPlayer(guid);

    if (!player)
        return;

    if (!GetPlayer()->IsWithinDistInMap(player, INSPECT_DISTANCE, false))
        return;

    if (GetPlayer()->IsValidAttackTarget(player))
        return;

    for (uint8 i = 0; i < MAX_ARENA_SLOT; ++i)
    {
        if (uint32 a_id = player->GetArenaTeamId(i))
        {
            if (ArenaTeam* arenaTeam = sArenaTeamMgr->GetArenaTeamById(a_id))
                arenaTeam->Inspect(this, player->GetGUID());
        }
    }
}

void WorldSession::HandleArenaTeamQueryOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_ARENA_TEAM_QUERY");

    uint32 arenaTeamId;
    recvData >> arenaTeamId;

    if (ArenaTeam* arenaTeam = sArenaTeamMgr->GetArenaTeamById(arenaTeamId))
    {
        arenaTeam->Query(this);
        arenaTeam->SendStats(this);
    }
}

void WorldSession::HandleArenaTeamRosterOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_ARENA_TEAM_ROSTER");

    uint32 arenaTeamId;                                     // arena team id
    recvData >> arenaTeamId;

    if (ArenaTeam* arenaTeam = sArenaTeamMgr->GetArenaTeamById(arenaTeamId))
        arenaTeam->Roster(this);
}

void WorldSession::HandleArenaTeamInviteOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "CMSG_ARENA_TEAM_INVITE");

    uint32 arenaTeamId;                                     // arena team id
    std::string invitedName;

    Player* player = NULL;

    recvData >> arenaTeamId >> invitedName;

    if (!invitedName.empty())
    {
        if (!normalizePlayerName(invitedName))
            return;

        player = sObjectAccessor->FindPlayerByName(invitedName);
    }

    if (!player)
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", invitedName, ERR_ARENA_TEAM_PLAYER_NOT_FOUND_S);
        return;
    }

    if (player->getLevel() < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", player->GetName(), ERR_ARENA_TEAM_TARGET_TOO_LOW_S);
        return;
    }

    ArenaTeam* arenaTeam = sArenaTeamMgr->GetArenaTeamById(arenaTeamId);
    if (!arenaTeam)
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", "", ERR_ARENA_TEAM_PLAYER_NOT_IN_TEAM);
        return;
    }

    if (GetPlayer()->GetArenaTeamId(arenaTeam->GetSlot()) != arenaTeamId)
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", "", ERR_ARENA_TEAM_PERMISSIONS);
        return;
    }

    // OK result but don't send invite
    if (player->GetSocial()->HasIgnore(GetPlayer()->GetGUIDLow()))
        return;

    if (!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD) && player->GetTeam() != GetPlayer()->GetTeam())
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_INVITE_SS, "", "", ERR_ARENA_TEAM_NOT_ALLIED);
        return;
    }

    if (player->GetArenaTeamId(arenaTeam->GetSlot()))
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_INVITE_SS, "", player->GetName(), ERR_ALREADY_IN_ARENA_TEAM_S);
        return;
    }

    if (player->GetArenaTeamIdInvited())
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_INVITE_SS, "", player->GetName(), ERR_ALREADY_INVITED_TO_ARENA_TEAM_S);
        return;
    }

    if (arenaTeam->GetMembersSize() >= arenaTeam->GetType() * 2)
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, arenaTeam->GetName(), "", ERR_ARENA_TEAM_TOO_MANY_MEMBERS_S);
        return;
    }

    TC_LOG_DEBUG("bg.battleground", "Player %s Invited %s to Join his ArenaTeam", GetPlayer()->GetName().c_str(), invitedName.c_str());

    player->SetArenaTeamIdInvited(arenaTeam->GetId());

    WorldPacket data(SMSG_ARENA_TEAM_INVITE, (8+10));
    data << GetPlayer()->GetName();
    data << arenaTeam->GetName();
    player->GetSession()->SendPacket(&data);

    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_ARENA_TEAM_INVITE");
}

void WorldSession::HandleArenaTeamAcceptOpcode(WorldPacket & /*recvData*/)
{
    TC_LOG_DEBUG("network", "CMSG_ARENA_TEAM_ACCEPT");                // empty opcode

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
    if (!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD) && _player->GetTeam() != sObjectMgr->GetPlayerTeamByGUID(arenaTeam->GetCaptain()))
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
    arenaTeam->BroadcastEvent(ERR_ARENA_TEAM_JOIN_SS, _player->GetGUID(), 2, _player->GetName(), arenaTeam->GetName(), "");
}

void WorldSession::HandleArenaTeamDeclineOpcode(WorldPacket & /*recvData*/)
{
    TC_LOG_DEBUG("network", "CMSG_ARENA_TEAM_DECLINE");               // empty opcode

    // Remove invite from player
    _player->SetArenaTeamIdInvited(0);
}

void WorldSession::HandleArenaTeamLeaveOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "CMSG_ARENA_TEAM_LEAVE");

    uint32 arenaTeamId;
    recvData >> arenaTeamId;

    ArenaTeam* arenaTeam = sArenaTeamMgr->GetArenaTeamById(arenaTeamId);
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
    arenaTeam->BroadcastEvent(ERR_ARENA_TEAM_LEAVE_SS, _player->GetGUID(), 2, _player->GetName(), arenaTeam->GetName(), "");

    // Inform player who left
    SendArenaTeamCommandResult(ERR_ARENA_TEAM_QUIT_S, arenaTeam->GetName(), "", 0);
}

void WorldSession::HandleArenaTeamDisbandOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "CMSG_ARENA_TEAM_DISBAND");

    uint32 arenaTeamId;
    recvData >> arenaTeamId;

    if (ArenaTeam* arenaTeam = sArenaTeamMgr->GetArenaTeamById(arenaTeamId))
    {
        // Only captain can disband the team
        if (arenaTeam->GetCaptain() != _player->GetGUID())
            return;

        // Teams cannot be disbanded during fights
        if (arenaTeam->IsFighting())
            return;

        arenaTeam->Disband(this);
        delete arenaTeam;
    }
}

void WorldSession::HandleArenaTeamRemoveOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "CMSG_ARENA_TEAM_REMOVE");

    uint32 arenaTeamId;
    std::string name;

    recvData >> arenaTeamId;
    recvData >> name;

    // Check for valid arena team
    ArenaTeam* arenaTeam = sArenaTeamMgr->GetArenaTeamById(arenaTeamId);
    if (!arenaTeam)
        return;

    // Only captain can remove members
    if (arenaTeam->GetCaptain() != _player->GetGUID())
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", "", ERR_ARENA_TEAM_PERMISSIONS);
        return;
    }

    if (!normalizePlayerName(name))
        return;

    // Check if team member exists
    ArenaTeamMember* member = arenaTeam->GetMember(name);
    if (!member)
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", name, ERR_ARENA_TEAM_PLAYER_NOT_FOUND_S);
        return;
    }

    // Captain cannot be removed
    if (arenaTeam->GetCaptain() == member->Guid)
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_QUIT_S, "", "", ERR_ARENA_TEAM_LEADER_LEAVE_S);
        return;
    }

    arenaTeam->DelMember(member->Guid, true);

    // Broadcast event
    arenaTeam->BroadcastEvent(ERR_ARENA_TEAM_REMOVE_SSS, 0, 3, name, arenaTeam->GetName(), _player->GetName());
}

void WorldSession::HandleArenaTeamLeaderOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "CMSG_ARENA_TEAM_LEADER");

    uint32 arenaTeamId;
    std::string name;

    recvData >> arenaTeamId;
    recvData >> name;

    // Check for valid arena team
    ArenaTeam* arenaTeam = sArenaTeamMgr->GetArenaTeamById(arenaTeamId);
    if (!arenaTeam)
        return;

    // Only captain can pass leadership
    if (arenaTeam->GetCaptain() != _player->GetGUID())
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", "", ERR_ARENA_TEAM_PERMISSIONS);
        return;
    }

    if (!normalizePlayerName(name))
        return;

    // Check if team member exists
    ArenaTeamMember* member = arenaTeam->GetMember(name);
    if (!member)
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", name, ERR_ARENA_TEAM_PLAYER_NOT_FOUND_S);
        return;
    }

    // Check if the target is already team captain
    if (arenaTeam->GetCaptain() == member->Guid)
        return;

    arenaTeam->SetCaptain(member->Guid);

    // Broadcast event
    arenaTeam->BroadcastEvent(ERR_ARENA_TEAM_LEADER_CHANGED_SSS, 0, 3, _player->GetName(), name, arenaTeam->GetName());
}

void WorldSession::SendArenaTeamCommandResult(uint32 teamAction, const std::string& team, const std::string& player, uint32 errorId)
{
    WorldPacket data(SMSG_ARENA_TEAM_COMMAND_RESULT, 4+team.length()+1+player.length()+1+4);
    data << uint32(teamAction);
    data << team;
    data << player;
    data << uint32(errorId);
    SendPacket(&data);
}

void WorldSession::SendNotInArenaTeamPacket(uint8 type)
{
    WorldPacket data(SMSG_ARENA_ERROR, 4+1);                // 886 - You are not in a %uv%u arena team
    uint32 unk = 0;
    data << uint32(unk);                                    // unk(0)
    if (!unk)
        data << uint8(type);                                // team type (2=2v2, 3=3v3, 5=5v5), can be used for custom types...
    SendPacket(&data);
}

/*
+ERR_ARENA_NO_TEAM_II "You are not in a %dv%d arena team"

+ERR_ARENA_TEAM_CREATE_S "%s created.  To disband, use /teamdisband [2v2, 3v3, 5v5]."
+ERR_ARENA_TEAM_INVITE_SS "You have invited %s to join %s"
+ERR_ARENA_TEAM_QUIT_S "You are no longer a member of %s"
ERR_ARENA_TEAM_FOUNDER_S "Congratulations, you are a founding member of %s!  To leave, use /teamquit [2v2, 3v3, 5v5]."

+ERR_ARENA_TEAM_INTERNAL "Internal arena team error"
+ERR_ALREADY_IN_ARENA_TEAM "You are already in an arena team of that size"
+ERR_ALREADY_IN_ARENA_TEAM_S "%s is already in an arena team of that size"
+ERR_INVITED_TO_ARENA_TEAM "You have already been invited into an arena team"
+ERR_ALREADY_INVITED_TO_ARENA_TEAM_S "%s has already been invited to an arena team"
+ERR_ARENA_TEAM_NAME_INVALID "That name contains invalid characters, please enter a new name"
+ERR_ARENA_TEAM_NAME_EXISTS_S "There is already an arena team named \"%s\""
+ERR_ARENA_TEAM_LEADER_LEAVE_S "You must promote a new team captain using /teamcaptain before leaving the team"
+ERR_ARENA_TEAM_PERMISSIONS "You don't have permission to do that"
+ERR_ARENA_TEAM_PLAYER_NOT_IN_TEAM "You are not in an arena team of that size"
+ERR_ARENA_TEAM_PLAYER_NOT_IN_TEAM_SS "%s is not in %s"
+ERR_ARENA_TEAM_PLAYER_NOT_FOUND_S "\"%s\" not found"
+ERR_ARENA_TEAM_NOT_ALLIED "You cannot invite players from the opposing alliance"

+ERR_ARENA_TEAM_JOIN_SS "%s has joined %s"
+ERR_ARENA_TEAM_YOU_JOIN_S "You have joined %s.  To leave, use /teamquit [2v2, 3v3, 5v5]."

+ERR_ARENA_TEAM_LEAVE_SS "%s has left %s"

+ERR_ARENA_TEAM_LEADER_IS_SS "%s is the captain of %s"
+ERR_ARENA_TEAM_LEADER_CHANGED_SSS "%s has made %s the new captain of %s"

+ERR_ARENA_TEAM_REMOVE_SSS "%s has been kicked out of %s by %s"

+ERR_ARENA_TEAM_DISBANDED_S "%s has disbanded %s"

ERR_ARENA_TEAM_TARGET_TOO_LOW_S "%s is not high enough level to join your team"

ERR_ARENA_TEAM_TOO_MANY_MEMBERS_S "%s is full"

ERR_ARENA_TEAM_LEVEL_TOO_LOW_I "You must be level %d to form an arena team"
*/
