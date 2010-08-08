/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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

#include "Player.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "DatabaseEnv.h"

#include "ArenaTeam.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "SocialMgr.h"

void WorldSession::HandleInspectArenaTeamsOpcode(WorldPacket & recv_data)
{
    sLog.outDebug("MSG_INSPECT_ARENA_TEAMS");

    uint64 guid;
    recv_data >> guid;
    sLog.outDebug("Inspect Arena stats (GUID: %u TypeId: %u)", GUID_LOPART(guid),GuidHigh2TypeId(GUID_HIPART(guid)));

    if (Player *plr = sObjectMgr.GetPlayer(guid))
    {
        for (uint8 i = 0; i < MAX_ARENA_SLOT; ++i)
        {
            if (uint32 a_id = plr->GetArenaTeamId(i))
            {
                if (ArenaTeam *at = sObjectMgr.GetArenaTeamById(a_id))
                    at->InspectStats(this, plr->GetGUID());
            }
        }
    }
}

void WorldSession::HandleArenaTeamQueryOpcode(WorldPacket & recv_data)
{
    sLog.outDebug("WORLD: Received CMSG_ARENA_TEAM_QUERY");

    uint32 ArenaTeamId;
    recv_data >> ArenaTeamId;

    if (ArenaTeam *arenateam = sObjectMgr.GetArenaTeamById(ArenaTeamId))
    {
        arenateam->Query(this);
        arenateam->Stats(this);
    }
}

void WorldSession::HandleArenaTeamRosterOpcode(WorldPacket & recv_data)
{
    sLog.outDebug("WORLD: Received CMSG_ARENA_TEAM_ROSTER");

    uint32 ArenaTeamId;                                     // arena team id
    recv_data >> ArenaTeamId;

    if (ArenaTeam *arenateam = sObjectMgr.GetArenaTeamById(ArenaTeamId))
        arenateam->Roster(this);
}

void WorldSession::HandleArenaTeamInviteOpcode(WorldPacket & recv_data)
{
    sLog.outDebug("CMSG_ARENA_TEAM_INVITE");

    uint32 ArenaTeamId;                                     // arena team id
    std::string Invitedname;

    Player * player = NULL;

    recv_data >> ArenaTeamId >> Invitedname;

    if (!Invitedname.empty())
    {
        if (!normalizePlayerName(Invitedname))
            return;

        player = sObjectAccessor.FindPlayerByName(Invitedname.c_str());
    }

    if (!player)
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", Invitedname, ERR_ARENA_TEAM_PLAYER_NOT_FOUND_S);
        return;
    }

    if (player->getLevel() < sWorld.getConfig(CONFIG_MAX_PLAYER_LEVEL))
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", player->GetName(), ERR_ARENA_TEAM_TARGET_TOO_LOW_S);
        return;
    }

    ArenaTeam *arenateam = sObjectMgr.GetArenaTeamById(ArenaTeamId);
    if (!arenateam)
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", "", ERR_ARENA_TEAM_PLAYER_NOT_IN_TEAM);
        return;
    }

    // OK result but not send invite
    if (player->GetSocial()->HasIgnore(GetPlayer()->GetGUIDLow()))
        return;

    if (!sWorld.getConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD) && player->GetTeam() != GetPlayer()->GetTeam())
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_INVITE_SS, "", "", ERR_ARENA_TEAM_NOT_ALLIED);
        return;
    }

    if (player->GetArenaTeamId(arenateam->GetSlot()))
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_INVITE_SS, "", player->GetName(), ERR_ALREADY_IN_ARENA_TEAM_S);
        return;
    }

    if (player->GetArenaTeamIdInvited())
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_INVITE_SS, "", player->GetName(), ERR_ALREADY_INVITED_TO_ARENA_TEAM_S);
        return;
    }

    if (arenateam->GetMembersSize() >= arenateam->GetType() * 2)
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, arenateam->GetName(), "", ERR_ARENA_TEAM_TOO_MANY_MEMBERS_S);
        return;
    }

    sLog.outDebug("Player %s Invited %s to Join his ArenaTeam", GetPlayer()->GetName(), Invitedname.c_str());

    player->SetArenaTeamIdInvited(arenateam->GetId());

    WorldPacket data(SMSG_ARENA_TEAM_INVITE, (8+10));
    data << GetPlayer()->GetName();
    data << arenateam->GetName();
    player->GetSession()->SendPacket(&data);

    sLog.outDebug("WORLD: Sent SMSG_ARENA_TEAM_INVITE");
}

void WorldSession::HandleArenaTeamAcceptOpcode(WorldPacket & /*recv_data*/)
{
    sLog.outDebug("CMSG_ARENA_TEAM_ACCEPT");                // empty opcode

    ArenaTeam *at = sObjectMgr.GetArenaTeamById(_player->GetArenaTeamIdInvited());
    if (!at)
        return;

    if (_player->GetArenaTeamId(at->GetSlot()))
    {
        // already in arena team that size
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", "", ERR_ALREADY_IN_ARENA_TEAM);
        return;
    }

    if (!sWorld.getConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GUILD) && _player->GetTeam() != sObjectMgr.GetPlayerTeamByGUID(at->GetCaptain()))
    {
        // not let enemies sign petition
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", "", ERR_ARENA_TEAM_NOT_ALLIED);
        return;
    }

    if (!at->AddMember(_player->GetGUID()))
    {
        // arena team not found
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S,"","",ERR_ARENA_TEAM_INTERNAL);
        return;
    }

    // event
    at->BroadcastEvent(ERR_ARENA_TEAM_JOIN_SS, _player->GetGUID(), 2, _player->GetName(), at->GetName(), "");
}

void WorldSession::HandleArenaTeamDeclineOpcode(WorldPacket & /*recv_data*/)
{
    sLog.outDebug("CMSG_ARENA_TEAM_DECLINE");               // empty opcode

    _player->SetArenaTeamIdInvited(0);                      // no more invited
}

void WorldSession::HandleArenaTeamLeaveOpcode(WorldPacket & recv_data)
{
    sLog.outDebug("CMSG_ARENA_TEAM_LEAVE");

    uint32 ArenaTeamId;                                     // arena team id
    recv_data >> ArenaTeamId;

    ArenaTeam *at = sObjectMgr.GetArenaTeamById(ArenaTeamId);
    if (!at)
        return;

    if (_player->GetGUID() == at->GetCaptain() && at->GetMembersSize() > 1)
    {
        // check for correctness
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_QUIT_S, "", "", ERR_ARENA_TEAM_LEADER_LEAVE_S);
        return;
    }

    // arena team has only one member (=captain)
    if (_player->GetGUID() == at->GetCaptain())
    {
        at->Disband(this);
        delete at;
        return;
    }

    at->DelMember(_player->GetGUID());

    // event
    at->BroadcastEvent(ERR_ARENA_TEAM_LEAVE_SS, _player->GetGUID(), 2, _player->GetName(), at->GetName(), "");

    // send you are no longer member of team
    SendArenaTeamCommandResult(ERR_ARENA_TEAM_QUIT_S, at->GetName(), "", 0);
}

void WorldSession::HandleArenaTeamDisbandOpcode(WorldPacket & recv_data)
{
    sLog.outDebug("CMSG_ARENA_TEAM_DISBAND");

    uint32 ArenaTeamId;                                     // arena team id
    recv_data >> ArenaTeamId;

    if (ArenaTeam *at = sObjectMgr.GetArenaTeamById(ArenaTeamId))
    {
        if (at->GetCaptain() != _player->GetGUID())
            return;

        if (at->IsFighting())
            return;

        at->Disband(this);
        delete at;
    }
}

void WorldSession::HandleArenaTeamRemoveOpcode(WorldPacket & recv_data)
{
    sLog.outDebug("CMSG_ARENA_TEAM_REMOVE");

    uint32 ArenaTeamId;
    std::string name;

    recv_data >> ArenaTeamId;
    recv_data >> name;

    ArenaTeam *at = sObjectMgr.GetArenaTeamById(ArenaTeamId);
    if (!at)                                                 // arena team not found
        return;

    if (at->GetCaptain() != _player->GetGUID())
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", "", ERR_ARENA_TEAM_PERMISSIONS);
        return;
    }

    if (!normalizePlayerName(name))
        return;

    ArenaTeamMember* member = at->GetMember(name);
    if (!member)                                             // member not found
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", name, ERR_ARENA_TEAM_PLAYER_NOT_FOUND_S);
        return;
    }

    if (at->GetCaptain() == member->guid)
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_QUIT_S, "", "", ERR_ARENA_TEAM_LEADER_LEAVE_S);
        return;
    }

    at->DelMember(member->guid);

    // event
    at->BroadcastEvent(ERR_ARENA_TEAM_REMOVE_SSS, 0, 3, name, at->GetName(), _player->GetName());
}

void WorldSession::HandleArenaTeamLeaderOpcode(WorldPacket & recv_data)
{
    sLog.outDebug("CMSG_ARENA_TEAM_LEADER");

    uint32 ArenaTeamId;
    std::string name;

    recv_data >> ArenaTeamId;
    recv_data >> name;

    ArenaTeam *at = sObjectMgr.GetArenaTeamById(ArenaTeamId);
    if (!at)                                                 // arena team not found
        return;

    if (at->GetCaptain() != _player->GetGUID())
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", "", ERR_ARENA_TEAM_PERMISSIONS);
        return;
    }

    if (!normalizePlayerName(name))
        return;

    ArenaTeamMember* member = at->GetMember(name);
    if (!member)                                             // member not found
    {
        SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, "", name, ERR_ARENA_TEAM_PLAYER_NOT_FOUND_S);
        return;
    }

    if (at->GetCaptain() == member->guid)                    // target player already captain
        return;

    at->SetCaptain(member->guid);

    // event
    at->BroadcastEvent(ERR_ARENA_TEAM_LEADER_CHANGED_SSS, 0, 3, _player->GetName(), name, at->GetName());
}

void WorldSession::SendArenaTeamCommandResult(uint32 team_action, const std::string& team, const std::string& player, uint32 error_id)
{
    WorldPacket data(SMSG_ARENA_TEAM_COMMAND_RESULT, 4+team.length()+1+player.length()+1+4);
    data << uint32(team_action);
    data << team;
    data << player;
    data << uint32(error_id);
    SendPacket(&data);
}

void WorldSession::SendNotInArenaTeamPacket(uint8 type)
{
    WorldPacket data(SMSG_ARENA_ERROR, 4+1);                // 886 - You are not in a %uv%u arena team
    uint32 unk = 0;
    data << uint32(unk);                                    // unk(0)
    if (!unk)
        data << uint8(type);                                // team type (2=2v2,3=3v3,5=5v5), can be used for custom types...
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
