/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include "WorldPacket.h"
#include "Object.h"
#include "SharedDefines.h"
#include "GuildFinderMgr.h"
#include "GuildMgr.h"

void WorldSession::HandleGuildFinderAddRecruit(WorldPacket& recvPacket)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_LF_GUILD_ADD_RECRUIT");

    if (sGuildFinderMgr->GetAllMembershipRequestsForPlayer(GetPlayer()->GetGUID().GetCounter()).size() == 10)
        return;

    uint32 classRoles = 0;
    uint32 availability = 0;
    uint32 guildInterests = 0;

    recvPacket >> classRoles >> guildInterests >> availability;

    ObjectGuid guid;
    guid[3] = recvPacket.ReadBit();
    guid[0] = recvPacket.ReadBit();
    guid[6] = recvPacket.ReadBit();
    guid[1] = recvPacket.ReadBit();
    uint16 commentLength = recvPacket.ReadBits(11);
    guid[5] = recvPacket.ReadBit();
    guid[4] = recvPacket.ReadBit();
    guid[7] = recvPacket.ReadBit();
    uint8 nameLength = recvPacket.ReadBits(7);
    guid[2] = recvPacket.ReadBit();

    recvPacket.ReadByteSeq(guid[4]);
    recvPacket.ReadByteSeq(guid[5]);
    std::string comment = recvPacket.ReadString(commentLength);
    std::string playerName = recvPacket.ReadString(nameLength);
    recvPacket.ReadByteSeq(guid[7]);
    recvPacket.ReadByteSeq(guid[2]);
    recvPacket.ReadByteSeq(guid[0]);
    recvPacket.ReadByteSeq(guid[6]);
    recvPacket.ReadByteSeq(guid[1]);
    recvPacket.ReadByteSeq(guid[3]);

    uint32 guildLowGuid = guid.GetCounter();

    if (!guid.IsGuild())
        return;
    if (!(classRoles & GUILDFINDER_ALL_ROLES) || classRoles > GUILDFINDER_ALL_ROLES)
        return;
    if (!(availability & AVAILABILITY_ALWAYS) || availability > AVAILABILITY_ALWAYS)
        return;
    if (!(guildInterests & ALL_INTERESTS) || guildInterests > ALL_INTERESTS)
        return;

    MembershipRequest request = MembershipRequest(GetPlayer()->GetGUID(), guildLowGuid, availability, classRoles, guildInterests, comment, time(NULL));
    sGuildFinderMgr->AddMembershipRequest(guildLowGuid, request);
}

void WorldSession::HandleGuildFinderBrowse(WorldPacket& recvPacket)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_LF_GUILD_BROWSE");
    uint32 classRoles = 0;
    uint32 availability = 0;
    uint32 guildInterests = 0;
    uint32 playerLevel = 0; // Raw player level (1-85), do they use MAX_FINDER_LEVEL when on level 85 ?

    recvPacket >> classRoles >> availability >> guildInterests >> playerLevel;

    if (!(classRoles & GUILDFINDER_ALL_ROLES) || classRoles > GUILDFINDER_ALL_ROLES)
        return;
    if (!(availability & AVAILABILITY_ALWAYS) || availability > AVAILABILITY_ALWAYS)
        return;
    if (!(guildInterests & ALL_INTERESTS) || guildInterests > ALL_INTERESTS)
        return;
    if (playerLevel > sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL) || playerLevel < 1)
        return;

    Player* player = GetPlayer();

    LFGuildPlayer settings(player->GetGUID().GetCounter(), classRoles, availability, guildInterests, ANY_FINDER_LEVEL);
    LFGuildStore guildList = sGuildFinderMgr->GetGuildsMatchingSetting(settings, player->GetTeamId());
    uint32 guildCount = guildList.size();

    if (guildCount == 0)
    {
        WorldPacket packet(SMSG_LF_GUILD_BROWSE_UPDATED, 0);
        player->SendDirectMessage(&packet);
        return;
    }

    ByteBuffer bufferData(65 * guildCount);
    WorldPacket data(SMSG_LF_GUILD_BROWSE_UPDATED, 3 + guildCount * 65); // Estimated size
    data.WriteBits(guildCount, 19);

    for (LFGuildStore::const_iterator itr = guildList.begin(); itr != guildList.end(); ++itr)
    {
        LFGuildSettings guildSettings = itr->second;
        Guild* guild = sGuildMgr->GetGuildById(itr->first);

        ObjectGuid guildGUID = ObjectGuid(guild->GetGUID());

        data.WriteBit(guildGUID[7]);
        data.WriteBit(guildGUID[5]);
        data.WriteBits(guild->GetName().size(), 8);
        data.WriteBit(guildGUID[0]);
        data.WriteBits(guildSettings.GetComment().size(), 11);
        data.WriteBit(guildGUID[4]);
        data.WriteBit(guildGUID[1]);
        data.WriteBit(guildGUID[2]);
        data.WriteBit(guildGUID[6]);
        data.WriteBit(guildGUID[3]);

        bufferData << uint32(guild->GetEmblemInfo().GetColor());
        bufferData << uint32(guild->GetEmblemInfo().GetBorderStyle()); // Guessed
        bufferData << uint32(guild->GetEmblemInfo().GetStyle());

        bufferData.WriteString(guildSettings.GetComment());

        bufferData << uint8(0); // Unk

        bufferData.WriteByteSeq(guildGUID[5]);

        bufferData << uint32(guildSettings.GetInterests());

        bufferData.WriteByteSeq(guildGUID[6]);
        bufferData.WriteByteSeq(guildGUID[4]);

        bufferData << uint32(guild->GetLevel());

        bufferData.WriteString(guild->GetName());

        bufferData << uint32(guild->GetAchievementMgr().GetAchievementPoints());

        bufferData.WriteByteSeq(guildGUID[7]);

        bufferData << uint8(sGuildFinderMgr->HasRequest(player->GetGUID().GetCounter(), guild->GetGUID())); // Request pending

        bufferData.WriteByteSeq(guildGUID[2]);
        bufferData.WriteByteSeq(guildGUID[0]);

        bufferData << uint32(guildSettings.GetAvailability());

        bufferData.WriteByteSeq(guildGUID[1]);

        bufferData << uint32(guild->GetEmblemInfo().GetBackgroundColor());
        bufferData << uint32(0); // Unk Int 2 (+ 128) // Always 0 or 1
        bufferData << uint32(guild->GetEmblemInfo().GetBorderColor());
        bufferData << uint32(guildSettings.GetClassRoles());

        bufferData.WriteByteSeq(guildGUID[3]);
        bufferData << uint32(guild->GetMembersCount());
    }

    data.FlushBits();
    data.append(bufferData);

    player->SendDirectMessage(&data);
}

void WorldSession::HandleGuildFinderDeclineRecruit(WorldPacket& recvPacket)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_LF_GUILD_DECLINE_RECRUIT");

    ObjectGuid playerGuid;

    playerGuid[1] = recvPacket.ReadBit();
    playerGuid[4] = recvPacket.ReadBit();
    playerGuid[5] = recvPacket.ReadBit();
    playerGuid[2] = recvPacket.ReadBit();
    playerGuid[6] = recvPacket.ReadBit();
    playerGuid[7] = recvPacket.ReadBit();
    playerGuid[0] = recvPacket.ReadBit();
    playerGuid[3] = recvPacket.ReadBit();

    recvPacket.ReadByteSeq(playerGuid[5]);
    recvPacket.ReadByteSeq(playerGuid[7]);
    recvPacket.ReadByteSeq(playerGuid[2]);
    recvPacket.ReadByteSeq(playerGuid[3]);
    recvPacket.ReadByteSeq(playerGuid[4]);
    recvPacket.ReadByteSeq(playerGuid[1]);
    recvPacket.ReadByteSeq(playerGuid[0]);
    recvPacket.ReadByteSeq(playerGuid[6]);

    if (!playerGuid.IsPlayer())
        return;

    sGuildFinderMgr->RemoveMembershipRequest(playerGuid.GetCounter(), GetPlayer()->GetGuildId());
}

void WorldSession::HandleGuildFinderGetApplications(WorldPacket& /*recvPacket*/)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_LF_GUILD_GET_APPLICATIONS"); // Empty opcode

    std::list<MembershipRequest> applicatedGuilds = sGuildFinderMgr->GetAllMembershipRequestsForPlayer(GetPlayer()->GetGUID().GetCounter());
    uint32 applicationsCount = applicatedGuilds.size();
    WorldPacket data(SMSG_LF_GUILD_MEMBERSHIP_LIST_UPDATED, 7 + 54 * applicationsCount);
    data.WriteBits(applicationsCount, 20);

    if (applicationsCount > 0)
    {
        ByteBuffer bufferData(54 * applicationsCount);
        for (std::list<MembershipRequest>::const_iterator itr = applicatedGuilds.begin(); itr != applicatedGuilds.end(); ++itr)
        {
            Guild* guild = sGuildMgr->GetGuildById(itr->GetGuildId());
            LFGuildSettings guildSettings = sGuildFinderMgr->GetGuildSettings(itr->GetGuildId());
            MembershipRequest request = *itr;

            ObjectGuid guildGuid = ObjectGuid(guild->GetGUID());

            data.WriteBit(guildGuid[1]);
            data.WriteBit(guildGuid[0]);
            data.WriteBit(guildGuid[5]);
            data.WriteBits(request.GetComment().size(), 11);
            data.WriteBit(guildGuid[3]);
            data.WriteBit(guildGuid[7]);
            data.WriteBit(guildGuid[4]);
            data.WriteBit(guildGuid[6]);
            data.WriteBit(guildGuid[2]);
            data.WriteBits(guild->GetName().size(), 8);

            bufferData.WriteByteSeq(guildGuid[2]);
            bufferData.WriteString(request.GetComment());
            bufferData.WriteByteSeq(guildGuid[5]);
            bufferData.WriteString(guild->GetName());

            bufferData << uint32(guildSettings.GetAvailability());
            bufferData << uint32(request.GetExpiryTime() - time(NULL)); // Time left to application expiry (seconds)

            bufferData.WriteByteSeq(guildGuid[0]);
            bufferData.WriteByteSeq(guildGuid[6]);
            bufferData.WriteByteSeq(guildGuid[3]);
            bufferData.WriteByteSeq(guildGuid[7]);

            bufferData << uint32(guildSettings.GetClassRoles());

            bufferData.WriteByteSeq(guildGuid[4]);
            bufferData.WriteByteSeq(guildGuid[1]);

            bufferData << uint32(time(NULL) - request.GetSubmitTime()); // Time since application (seconds)
            bufferData << uint32(guildSettings.GetInterests());
        }

        data.FlushBits();
        data.append(bufferData);
    }
    data << uint32(10 - sGuildFinderMgr->CountRequestsFromPlayer(GetPlayer()->GetGUID().GetCounter())); // Applications count left

    GetPlayer()->SendDirectMessage(&data);
}

// Lists all recruits for a guild - Misses times
void WorldSession::HandleGuildFinderGetRecruits(WorldPacket& recvPacket)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_LF_GUILD_GET_RECRUITS");

    uint32 unkTime = 0;
    recvPacket >> unkTime;

    Player* player = GetPlayer();
    if (!player->GetGuildId())
        return;

    std::vector<MembershipRequest> recruitsList = sGuildFinderMgr->GetAllMembershipRequestsForGuild(player->GetGuildId());
    uint32 recruitCount = recruitsList.size();

    ByteBuffer dataBuffer(53 * recruitCount);
    WorldPacket data(SMSG_LF_GUILD_RECRUIT_LIST_UPDATED, 7 + 26 * recruitCount + 53 * recruitCount);
    data.WriteBits(recruitCount, 20);

    for (std::vector<MembershipRequest>::const_iterator itr = recruitsList.begin(); itr != recruitsList.end(); ++itr)
    {
        MembershipRequest request = *itr;
        ObjectGuid playerGuid = request.GetPlayerGUID();

        data.WriteBits(request.GetComment().size(), 11);
        data.WriteBit(playerGuid[2]);
        data.WriteBit(playerGuid[4]);
        data.WriteBit(playerGuid[3]);
        data.WriteBit(playerGuid[7]);
        data.WriteBit(playerGuid[0]);
        data.WriteBits(request.GetName().size(), 7);
        data.WriteBit(playerGuid[5]);
        data.WriteBit(playerGuid[1]);
        data.WriteBit(playerGuid[6]);

        dataBuffer.WriteByteSeq(playerGuid[4]);

        dataBuffer << int32(time(NULL) <= request.GetExpiryTime());

        dataBuffer.WriteByteSeq(playerGuid[3]);
        dataBuffer.WriteByteSeq(playerGuid[0]);
        dataBuffer.WriteByteSeq(playerGuid[1]);

        dataBuffer << int32(request.GetLevel());

        dataBuffer.WriteByteSeq(playerGuid[6]);
        dataBuffer.WriteByteSeq(playerGuid[7]);
        dataBuffer.WriteByteSeq(playerGuid[2]);

        dataBuffer << int32(time(NULL) - request.GetSubmitTime()); // Time in seconds since application submitted.
        dataBuffer << int32(request.GetAvailability());
        dataBuffer << int32(request.GetClassRoles());
        dataBuffer << int32(request.GetInterests());
        dataBuffer << int32(request.GetExpiryTime() - time(NULL)); // TIme in seconds until application expires.

        dataBuffer.WriteString(request.GetName());
        dataBuffer.WriteString(request.GetComment());

        dataBuffer << int32(request.GetClass());

        dataBuffer.WriteByteSeq(playerGuid[5]);
    }

    data.FlushBits();
    data.append(dataBuffer);
    data << uint32(time(NULL)); // Unk time

    player->SendDirectMessage(&data);
}

void WorldSession::HandleGuildFinderPostRequest(WorldPacket& /*recvPacket*/)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_LF_GUILD_POST_REQUEST"); // Empty opcode

    Player* player = GetPlayer();

    if (!player->GetGuildId()) // Player must be in guild
        return;

    bool isGuildMaster = true;
    if (Guild* guild = sGuildMgr->GetGuildById(player->GetGuildId()))
        if (guild->GetLeaderGUID() != player->GetGUID())
            isGuildMaster = false;

    LFGuildSettings settings = sGuildFinderMgr->GetGuildSettings(player->GetGuildId());

    WorldPacket data(SMSG_LF_GUILD_POST_UPDATED, 35);
    data.WriteBit(isGuildMaster); // Guessed

    if (isGuildMaster)
    {
        data.WriteBits(settings.GetComment().size(), 11);
        data.WriteBit(settings.IsListed());
        data << uint32(settings.GetLevel());
        data.WriteString(settings.GetComment());
        data << uint32(0); // Unk Int32
        data << uint32(settings.GetAvailability());
        data << uint32(settings.GetClassRoles());
        data << uint32(settings.GetInterests());
    }
    else
        data.FlushBits();
    player->SendDirectMessage(&data);
}

void WorldSession::HandleGuildFinderRemoveRecruit(WorldPacket& recvPacket)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_LF_GUILD_REMOVE_RECRUIT");

    ObjectGuid guildGuid;

    guildGuid[0] = recvPacket.ReadBit();
    guildGuid[4] = recvPacket.ReadBit();
    guildGuid[3] = recvPacket.ReadBit();
    guildGuid[5] = recvPacket.ReadBit();
    guildGuid[7] = recvPacket.ReadBit();
    guildGuid[6] = recvPacket.ReadBit();
    guildGuid[2] = recvPacket.ReadBit();
    guildGuid[1] = recvPacket.ReadBit();

    recvPacket.ReadByteSeq(guildGuid[4]);
    recvPacket.ReadByteSeq(guildGuid[0]);
    recvPacket.ReadByteSeq(guildGuid[3]);
    recvPacket.ReadByteSeq(guildGuid[6]);
    recvPacket.ReadByteSeq(guildGuid[5]);
    recvPacket.ReadByteSeq(guildGuid[1]);
    recvPacket.ReadByteSeq(guildGuid[2]);
    recvPacket.ReadByteSeq(guildGuid[7]);

    if (!guildGuid.IsGuild())
        return;

    sGuildFinderMgr->RemoveMembershipRequest(GetPlayer()->GetGUID().GetCounter(), guildGuid.GetCounter());
}

// Sent any time a guild master sets an option in the interface and when listing / unlisting his guild
void WorldSession::HandleGuildFinderSetGuildPost(WorldPacket& recvPacket)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_LF_GUILD_SET_GUILD_POST");

    uint32 classRoles = 0;
    uint32 availability = 0;
    uint32 guildInterests =  0;
    uint32 level = 0;

    recvPacket >> level >> availability >> guildInterests >> classRoles;
    // Level sent is zero if untouched, force to any (from interface). Idk why
    if (!level)
        level = ANY_FINDER_LEVEL;

    uint16 length = recvPacket.ReadBits(11);
    bool listed = recvPacket.ReadBit();
    std::string comment = recvPacket.ReadString(length);

    if (!(classRoles & GUILDFINDER_ALL_ROLES) || classRoles > GUILDFINDER_ALL_ROLES)
        return;
    if (!(availability & AVAILABILITY_ALWAYS) || availability > AVAILABILITY_ALWAYS)
        return;
    if (!(guildInterests & ALL_INTERESTS) || guildInterests > ALL_INTERESTS)
        return;
    if (!(level & ALL_GUILDFINDER_LEVELS) || level > ALL_GUILDFINDER_LEVELS)
        return;

    Player* player = GetPlayer();

    if (!player->GetGuildId()) // Player must be in guild
        return;

    if (Guild* guild = sGuildMgr->GetGuildById(player->GetGuildId())) // Player must be guild master
        if (guild->GetLeaderGUID() != player->GetGUID())
            return;

    LFGuildSettings settings(listed, player->GetTeamId(), player->GetGuildId(), classRoles, availability, guildInterests, level, comment);
    sGuildFinderMgr->SetGuildSettings(player->GetGuildId(), settings);
}
