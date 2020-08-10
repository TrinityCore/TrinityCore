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

#include "SocialMgr.h"
#include "DatabaseEnv.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "RBAC.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"

PlayerSocial::PlayerSocial(): _playerGUID()
{ }

uint32 PlayerSocial::GetNumberOfSocialsWithFlag(SocialFlag flag)
{
    uint32 counter = 0;
    for (PlayerSocialMap::const_iterator itr = _playerSocialMap.begin(); itr != _playerSocialMap.end(); ++itr)
        if ((itr->second.Flags & flag) != 0)
            ++counter;

    return counter;
}

bool PlayerSocial::AddToSocialList(ObjectGuid const& friendGuid, SocialFlag flag)
{
    // check client limits
    if (GetNumberOfSocialsWithFlag(flag) >= (((flag & SOCIAL_FLAG_FRIEND) != 0) ? SOCIALMGR_FRIEND_LIMIT : SOCIALMGR_IGNORE_LIMIT))
        return false;

    PlayerSocialMap::iterator itr = _playerSocialMap.find(friendGuid);
    if (itr != _playerSocialMap.end())
    {
        itr->second.Flags |= flag;

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHARACTER_SOCIAL_FLAGS);

        stmt->setUInt8(0, itr->second.Flags);
        stmt->setUInt32(1, GetPlayerGUID().GetCounter());
        stmt->setUInt32(2, friendGuid.GetCounter());

        CharacterDatabase.Execute(stmt);
    }
    else
    {
        _playerSocialMap[friendGuid].Flags |= flag;

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_SOCIAL);

        stmt->setUInt32(0, GetPlayerGUID().GetCounter());
        stmt->setUInt32(1, friendGuid.GetCounter());
        stmt->setUInt8(2, flag);

        CharacterDatabase.Execute(stmt);
    }

    return true;
}

void PlayerSocial::RemoveFromSocialList(ObjectGuid const& friendGuid, SocialFlag flag)
{
    PlayerSocialMap::iterator itr = _playerSocialMap.find(friendGuid);
    if (itr == _playerSocialMap.end())
        return;

    itr->second.Flags &= ~flag;

    if (!itr->second.Flags)
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_SOCIAL);

        stmt->setUInt32(0, GetPlayerGUID().GetCounter());
        stmt->setUInt32(1, friendGuid.GetCounter());

        CharacterDatabase.Execute(stmt);

        _playerSocialMap.erase(itr);
    }
    else
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHARACTER_SOCIAL_FLAGS);

        stmt->setUInt8(0, itr->second.Flags);
        stmt->setUInt32(1, GetPlayerGUID());
        stmt->setUInt32(2, friendGuid);

        CharacterDatabase.Execute(stmt);
    }
}

void PlayerSocial::SetFriendNote(ObjectGuid const& friendGuid, std::string const& note)
{
    PlayerSocialMap::iterator itr = _playerSocialMap.find(friendGuid);
    if (itr == _playerSocialMap.end())                  // not exist
        return;

    itr->second.Note = note;
    utf8truncate(itr->second.Note, 48);                 // DB and client size limitation

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHARACTER_SOCIAL_NOTE);

    stmt->setString(0, itr->second.Note);
    stmt->setUInt32(1, GetPlayerGUID().GetCounter());
    stmt->setUInt32(2, friendGuid.GetCounter());

    CharacterDatabase.Execute(stmt);
}

void PlayerSocial::SendSocialList(Player* player, uint32 flags)
{
    ASSERT(player);

    uint32 friendsCount = 0;
    uint32 ignoredCount = 0;
    uint32 totalCount = 0;

    WorldPacket data(SMSG_CONTACT_LIST, (4 + 4 + _playerSocialMap.size() * 25)); // just can guess size
    data << uint32(flags);                                  // 0x1 = Friendlist update. 0x2 = Ignorelist update. 0x4 = Mutelist update.
    size_t countPos = data.wpos();
    data << uint32(0);                                      // contacts count placeholder

    for (auto& v : _playerSocialMap)
    {
        uint8 contactFlags = v.second.Flags;
        if (!(contactFlags & flags))
            continue;

        // Check client limit for friends list
        if (contactFlags & SOCIAL_FLAG_FRIEND)
            if (++friendsCount > SOCIALMGR_FRIEND_LIMIT)
                continue;

        // Check client limit for ignore list
        if (contactFlags & SOCIAL_FLAG_IGNORED)
            if (++ignoredCount > SOCIALMGR_IGNORE_LIMIT)
                continue;

        ++totalCount;
        SocialMgr::GetFriendInfo(player, v.first, v.second);

        data << uint64(v.first);                            // player guid
        data << uint32(contactFlags);                       // player flag (0x1 = Friend, 0x2 = Ignored, 0x4 = Muted)
        data << v.second.Note;                              // string note
        if (contactFlags & SOCIAL_FLAG_FRIEND)              // if IsFriend()
        {
            data << uint8(v.second.Status);                 // online/offline/etc?
            if (v.second.Status)                            // if online
            {
                data << uint32(v.second.Area);              // player area
                data << uint32(v.second.Level);             // player level
                data << uint32(v.second.Class);             // player class
            }
        }
    }

    data.put<uint32>(countPos, totalCount);

    player->SendDirectMessage(&data);
}

bool PlayerSocial::_HasContact(ObjectGuid const& guid, SocialFlag flags)
{
    PlayerSocialMap::const_iterator itr = _playerSocialMap.find(guid);
    if (itr != _playerSocialMap.end())
        return (itr->second.Flags & flags) != 0;

    return false;
}

bool PlayerSocial::HasFriend(ObjectGuid const& friendGuid)
{
    return _HasContact(friendGuid, SOCIAL_FLAG_FRIEND);
}

bool PlayerSocial::HasIgnore(ObjectGuid const& ignoreGuid)
{
    return _HasContact(ignoreGuid, SOCIAL_FLAG_IGNORED);
}

SocialMgr* SocialMgr::instance()
{
    static SocialMgr instance;
    return &instance;
}

void SocialMgr::GetFriendInfo(Player* player, ObjectGuid const& friendGUID, FriendInfo& friendInfo)
{
    if (!player)
        return;

    friendInfo.Status = FRIEND_STATUS_OFFLINE;
    friendInfo.Area = 0;
    friendInfo.Level = 0;
    friendInfo.Class = 0;

    Player* target = ObjectAccessor::FindPlayer(friendGUID);
    if (!target)
        return;

    PlayerSocial::PlayerSocialMap::iterator itr = player->GetSocial()->_playerSocialMap.find(friendGUID);
    if (itr != player->GetSocial()->_playerSocialMap.end())
        friendInfo.Note = itr->second.Note;

    // PLAYER see his team only and PLAYER can't see MODERATOR, GAME MASTER, ADMINISTRATOR characters
    // MODERATOR, GAME MASTER, ADMINISTRATOR can see all

    if (!player->GetSession()->HasPermission(rbac::RBAC_PERM_WHO_SEE_ALL_SEC_LEVELS) &&
        target->GetSession()->GetSecurity() > AccountTypes(sWorld->getIntConfig(CONFIG_GM_LEVEL_IN_WHO_LIST)))
        return;

    // player can see member of other team only if CONFIG_ALLOW_TWO_SIDE_WHO_LIST
    if (target->GetTeam() != player->GetTeam() && !player->GetSession()->HasPermission(rbac::RBAC_PERM_TWO_SIDE_WHO_LIST))
        return;

    if (target->IsVisibleGloballyFor(player))
    {
        if (target->isDND())
            friendInfo.Status = FRIEND_STATUS_DND;
        else if (target->isAFK())
            friendInfo.Status = FRIEND_STATUS_AFK;
        else
        {
            friendInfo.Status = FRIEND_STATUS_ONLINE;

            if (target->GetSession()->GetRecruiterId() == player->GetSession()->GetAccountId() || target->GetSession()->GetAccountId() == player->GetSession()->GetRecruiterId())
                friendInfo.Status = FriendStatus(uint32(friendInfo.Status) | FRIEND_STATUS_RAF);
        }

        friendInfo.Area = target->GetZoneId();
        friendInfo.Level = target->GetLevel();
        friendInfo.Class = target->GetClass();
    }
}

void SocialMgr::SendFriendStatus(Player* player, FriendsResult result, ObjectGuid const& friendGuid, bool broadcast /*= false*/)
{
    FriendInfo fi;
    GetFriendInfo(player, friendGuid, fi);

    WorldPacket data(SMSG_FRIEND_STATUS, 9);
    data << uint8(result);
    data << friendGuid;
    switch (result)
    {
        case FRIEND_ADDED_OFFLINE:
        case FRIEND_ADDED_ONLINE:
            data << fi.Note;
            break;
        default:
            break;
    }

    switch (result)
    {
        case FRIEND_ADDED_ONLINE:
        case FRIEND_ONLINE:
            data << uint8(fi.Status);
            data << uint32(fi.Area);
            data << uint32(fi.Level);
            data << uint32(fi.Class);
            break;
        default:
            break;
    }

    if (broadcast)
        BroadcastToFriendListers(player, &data);
    else
        player->SendDirectMessage(&data);
}

void SocialMgr::BroadcastToFriendListers(Player* player, WorldPacket const* packet)
{
    ASSERT(player);

    AccountTypes gmSecLevel = AccountTypes(sWorld->getIntConfig(CONFIG_GM_LEVEL_IN_WHO_LIST));
    for (SocialMap::const_iterator itr = _socialMap.begin(); itr != _socialMap.end(); ++itr)
    {
        PlayerSocial::PlayerSocialMap::const_iterator itr2 = itr->second._playerSocialMap.find(player->GetGUID());
        if (itr2 != itr->second._playerSocialMap.end() && (itr2->second.Flags & SOCIAL_FLAG_FRIEND) != 0)
        {
            Player* target = ObjectAccessor::FindPlayer(itr->first);
            if (!target)
                continue;

            WorldSession* session = target->GetSession();
            if (!session->HasPermission(rbac::RBAC_PERM_WHO_SEE_ALL_SEC_LEVELS) && player->GetSession()->GetSecurity() > gmSecLevel)
                continue;

            if (target->GetTeam() != player->GetTeam() && !session->HasPermission(rbac::RBAC_PERM_TWO_SIDE_WHO_LIST))
                continue;

            if (player->IsVisibleGloballyFor(target))
                session->SendPacket(packet);
        }
    }
}

PlayerSocial* SocialMgr::LoadFromDB(PreparedQueryResult result, ObjectGuid const& guid)
{
    PlayerSocial* social = &_socialMap[guid];
    social->SetPlayerGUID(guid);

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();

            ObjectGuid friendGuid = ObjectGuid::Create<HighGuid::Player>(fields[0].GetUInt32());

            uint8 flag = fields[1].GetUInt8();
            social->_playerSocialMap[friendGuid] = FriendInfo(flag, fields[2].GetString());
        }
        while (result->NextRow());
    }

    return social;
}
