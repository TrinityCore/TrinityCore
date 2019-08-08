/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "SocialMgr.h"
#include "AccountMgr.h"
#include "CharacterCache.h"
#include "DatabaseEnv.h"
#include "Errors.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "RBAC.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"

/*static*/ SocialMgr* SocialMgr::instance()
{
    static SocialMgr instance;
    return &instance;
}

SocialMgr::~SocialMgr()
{
    // sanity check
    ASSERT(_socialLinks.empty());
}

void SocialMgr::LoadPlayerFromDB(Player const* player, PreparedQueryResult data)
{
    auto& socialLinks = const_cast<std::unordered_map<ObjectGuid, SocialLink>&>(player->GetSocialLinks());
    ASSERT(socialLinks.empty(), "Double load of player %s", player->GetGUID().ToString().c_str());
    if (data) do
    {
        Field* fields = data->Fetch();
        ObjectGuid targetGuid = ObjectGuid::Create<HighGuid::Player>(fields[0].GetUInt32());
        SocialLink& link = socialLinks[targetGuid];
        link.Flags = (fields[1].GetUInt8() & SOCIAL_FLAG_ALL);
        link.Note = fields[2].GetString();

        _followers[targetGuid].emplace(player->GetGUID(), &link);
    } while (data->NextRow());
}

void SocialMgr::SavePlayerToDB(Player const* player, SQLTransaction trans)
{
    uint32 const playerGuidLow = player->GetGUID().GetCounter();
    auto& socialLinks = const_cast<std::unordered_map<ObjectGuid, SocialLink>&>(player->GetSocialLinks());
    for (auto it = socialLinks.begin(), end = socialLinks.end(); it != end;) // incremented inside loop
    {
        uint32 const targetGuidLow = it->first.GetCounter();
        SocialLink& link = it->second;
        if (!link.IsDirty)
        {
            ++it;
            continue;
        }

        if (link.Flags)
        {
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHARACTER_SOCIAL_LINK);
            stmt->setUInt32(0, playerGuidLow);
            stmt->setUInt32(1, targetGuidLow);
            stmt->setUInt8(2, link.Flags);
            stmt->setString(3, link.Note);
            trans->Append(stmt);
            link.IsDirty = false;
            ++it;
        }
        else
        {
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_SOCIAL_LINK);
            stmt->setUInt32(0, playerGuidLow);
            stmt->setUInt32(1, targetGuidLow);
            trans->Append(stmt);
            it = socialLinks.erase(it);
        }
    }
}

void SocialMgr::UnloadPlayer(ObjectGuid playerGuid)
{
    auto it = _socialLinks.find(playerGuid);
    for (auto const& pair : it->second)
    {
        ASSERT(!pair.second.IsDirty, "Player %s being unloaded, but still has unsaved social link with %s?", playerGuid.ToString().c_str(), pair.first.ToString().c_str());
        _followers[pair.first].erase(playerGuid);
    }
    _socialLinks.erase(it);
}

void SocialMgr::AddSocialLink(Player const* player, std::string const& targetName, SocialFlag flag, std::string const& note)
{
    bool const isFriend = (flag == SOCIAL_FLAG_FRIEND);
    ASSERT(isFriend || (flag == SOCIAL_FLAG_IGNORED), "Invalid social flag %u to AddSocialLink", uint32(flag));

    WorldSession* playerSession = player->GetSession();
    FriendsResult result;
    Player const* targetPlayer = nullptr;
    CharacterCacheEntry const* target = sCharacterCache->GetCharacterCacheByName(targetName);
    {
#define SEND_RESULT(v1,v2) do { result = (isFriend ? v1 : v2); goto send; } while(0);
        if (!target)
            SEND_RESULT(FRIEND_NOT_FOUND, FRIEND_IGNORE_NOT_FOUND);

        if (isFriend && !(playerSession->HasPermission(rbac::RBAC_PERM_ALLOW_GM_FRIEND) || AccountMgr::IsPlayerAccount(AccountMgr::GetSecurity(target->AccountId))))
            SEND_RESULT(FRIEND_NOT_FOUND, FRIEND_DB_ERROR);

        if (player->GetGUID() == target->Guid)
            SEND_RESULT(FRIEND_SELF, FRIEND_IGNORE_SELF);

        if (isFriend && (player->GetTeam() != Player::TeamForRace(target->Race)) && !playerSession->HasPermission(rbac::RBAC_PERM_TWO_SIDE_ADD_FRIEND))
            SEND_RESULT(FRIEND_ENEMY, FRIEND_DB_ERROR);

        auto& links = const_cast<std::unordered_map<ObjectGuid, SocialLink>&>(player->GetSocialLinks());
        SocialLink& link = links[target->Guid];
        if (link.Flags & flag)
            SEND_RESULT(FRIEND_ALREADY, FRIEND_IGNORE_ALREADY);

        if (std::count_if(links.begin(), links.end(), [flag](std::pair<ObjectGuid, SocialLink> const& pair) { return (pair.second.Flags & flag); }) >= MAX_SOCIALS_PER_FLAG)
            SEND_RESULT(FRIEND_LIST_FULL, FRIEND_IGNORE_FULL);

        link.Flags |= flag;
        link.IsDirty = true;

        if (isFriend)
        {
            link.Note = note;

            targetPlayer = ObjectAccessor::FindConnectedPlayer(target->Guid);
            result = targetPlayer ? FRIEND_ADDED_ONLINE : FRIEND_ADDED_OFFLINE;
        }
        else
            result = FRIEND_IGNORE_ADDED;

        auto& followers = (targetPlayer ? const_cast<std::unordered_map<ObjectGuid, SocialLink const*>&>(targetPlayer->GetFollowers()) : _followers[target->Guid]);
        followers[player->GetGUID()] = &link;

#undef SEND_RESULT
    }
send:
    if (player)
        _SendFriendStatusUpdate(targetPlayer, (target ? target->Guid : ObjectGuid::Empty), result, player);
}

void SocialMgr::RemoveSocialLink(Player const* player, ObjectGuid targetGuid, SocialFlag flag)
{
    auto& links = const_cast<std::unordered_map<ObjectGuid, SocialLink>&>(player->GetSocialLinks());
    auto it = links.find(targetGuid);
    SocialLink* link = (it != links.end()) ? &it->second : nullptr;

    if (flag & SOCIAL_FLAG_FRIEND)
    {
        if (link && (link->Flags & SOCIAL_FLAG_FRIEND))
        {
            link->Flags ^= SOCIAL_FLAG_FRIEND;
            link->IsDirty = true;

            _SendFriendStatusUpdate(nullptr, targetGuid, FRIEND_REMOVED, player);
        }
        else
            _SendFriendStatusUpdate(nullptr, targetGuid, FRIEND_NOT_FOUND, player);
    }

    if (flag & SOCIAL_FLAG_IGNORED)
    {
        if (link && (link->Flags & SOCIAL_FLAG_IGNORED))
        {
            link->Flags ^= SOCIAL_FLAG_IGNORED;
            link->IsDirty = true;

            _SendFriendStatusUpdate(nullptr, targetGuid, FRIEND_IGNORE_REMOVED, player);
        }
        else
            _SendFriendStatusUpdate(nullptr, targetGuid, FRIEND_IGNORE_NOT_FOUND, player);
    }

    if (link && !link->Flags)
        _followers[targetGuid].erase(player->GetGUID());
}

void SocialMgr::SetSocialLinkNote(Player const* player, ObjectGuid targetGuid, std::string const& note)
{
    auto& socialLinks = const_cast<std::unordered_map<ObjectGuid, SocialLink>&>(player->GetSocialLinks());
    auto it = socialLinks.find(targetGuid);
    if (it != socialLinks.end())
    {
        it->second.Note = note;
        it->second.IsDirty = true;
    }
}

void SocialMgr::EraseAllSocialLinks(ObjectGuid playerGuid, SQLTransaction trans)
{
    do
    { // remove all of our social links and any resulting follower references
        auto it = _socialLinks.find(playerGuid);
        if (it == _socialLinks.end())
            break;

        for (auto const& pair : it->second)
            _followers[pair.first].erase(playerGuid);
        _socialLinks.erase(it);
    } while (0);

    do
    { // remove us from our followers' social lists
        auto it = _followers.find(playerGuid);
        if (it == _followers.end())
            break;

        for (auto const& pair : it->second)
        {
            ObjectGuid const followerGuid = pair.first;
            auto& links = _socialLinks[followerGuid];
            auto it2 = links.find(playerGuid);
            ASSERT(it2 != links.end(), "SocialMgr internal inconsistency - %s follows %s, but this is not reciprocal?", followerGuid.ToString().c_str(), playerGuid.ToString().c_str());

            // notify the follower if they're online
            if (Player* follower = ObjectAccessor::FindConnectedPlayer(followerGuid))
            {
                if (it2->second.Flags & SOCIAL_FLAG_FRIEND)
                    _SendFriendStatusUpdate(nullptr, playerGuid, FRIEND_REMOVED, follower);
                if (it2->second.Flags & SOCIAL_FLAG_IGNORED)
                    _SendFriendStatusUpdate(nullptr, playerGuid, FRIEND_IGNORE_REMOVED, follower);
            }
            links.erase(it2);
        }
        _followers.erase(it);
    } while (0);

    do
    { // immediately remove from database
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_SOCIAL_ALL);
        stmt->setUInt32(0, playerGuid.GetCounter());
        stmt->setUInt32(0, playerGuid.GetCounter());
        trans->Append(stmt);
    } while (0);
}

static uint8 getFriendStatus(Player const* player, Player const* target)
{
    uint8 status = ASSERT_NOTNULL(target)->isDND() ? FRIEND_STATUS_DND : target->isAFK() ? FRIEND_STATUS_AFK : FRIEND_STATUS_ONLINE;
    if (player)
    {
        WorldSession* playerSession = player->GetSession();
        WorldSession* targetSession = target->GetSession();
        if ((playerSession->GetRecruiterId() == targetSession->GetAccountId()) || (playerSession->GetAccountId() == targetSession->GetRecruiterId()))
            status |= FRIEND_STATUS_RAF;
    }
    return status;
}

void SocialMgr::BroadcastFriendStatusUpdate(Player const* target, FriendsResult result) const
{
    _SendFriendStatusUpdate(target, target->GetGUID(), result, nullptr);
}

void SocialMgr::_SendFriendStatusUpdate(Player const* target, ObjectGuid targetGuid, FriendsResult status, Player const* recipient) const
{
    WorldPacket data(SMSG_FRIEND_STATUS, 9);
    data << uint8(status);
    data << targetGuid;
    if ((status == FRIEND_ADDED_ONLINE) || (status == FRIEND_ADDED_OFFLINE))
        data << ASSERT_NOTNULL(recipient)->GetSocialLinks().at(targetGuid).Note;
    if ((status == FRIEND_ADDED_ONLINE) || (status == FRIEND_ONLINE))
    {
        data << getFriendStatus(recipient, target);
        data << uint32(target->GetZoneId());
        data << uint32(target->GetLevel());
        data << uint32(target->GetClass());
    }

    if (recipient)
        recipient->SendDirectMessage(&data);
    else for (auto const& pair : ASSERT_NOTNULL(target)->GetFollowers())
    {
        if (pair.second->Flags & SOCIAL_FLAG_FRIEND)
            if (Player* follower = ObjectAccessor::FindConnectedPlayer(pair.first))
                follower->SendDirectMessage(&data);
    }
}

void SocialMgr::SendSocialLinks(Player const* player, SocialFlag filter) const
{
    auto const& socialLinks = ASSERT_NOTNULL(player)->GetSocialLinks();
    WorldPacket data(SMSG_CONTACT_LIST, (4 + 4 + socialLinks.size()));
    data << uint32(filter);
    size_t countPos = data.wpos();
    data << uint32(0); // placeholder

    uint32 friendsLeft = MAX_SOCIALS_PER_FLAG;
    uint32 ignoredLeft = MAX_SOCIALS_PER_FLAG;
    uint32 count = 0;
    for (auto const& pair : socialLinks)
    {
        ObjectGuid const targetGuid = pair.first;
        SocialLink const& link = pair.second;
        if (!(link.Flags & filter))
            continue;

        bool const isFriend = (link.Flags & SOCIAL_FLAG_FRIEND);
        bool const isIgnored = (link.Flags & SOCIAL_FLAG_IGNORED);

        if ((isFriend && !friendsLeft) || (isIgnored && !ignoredLeft))
            continue;

        if (isFriend)
            --friendsLeft;
        if (isIgnored)
            --ignoredLeft;

        data << targetGuid;
        data << uint32(link.Flags);
        data << link.Note;
        if (isFriend)
        {
            Player const* target = ObjectAccessor::FindConnectedPlayer(targetGuid);
            if (target)
            {
                data << getFriendStatus(player, target);
                data << uint32(target->GetZoneId());
                data << uint32(target->GetLevel());
                data << uint32(target->GetClass());
            }
            else
                data << uint8(FRIEND_STATUS_OFFLINE);
        }
        ++count;
    }

    data.put<uint32>(countPos, count);
    player->SendDirectMessage(&data);
}
