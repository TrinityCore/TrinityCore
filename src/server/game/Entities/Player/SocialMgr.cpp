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
#include "SocialPackets.h"
#include "World.h"
#include "WorldSession.h"

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
        stmt->setUInt64(1, GetPlayerGUID().GetCounter());
        stmt->setUInt64(2, friendGuid.GetCounter());

        CharacterDatabase.Execute(stmt);
    }
    else
    {
        _playerSocialMap[friendGuid].Flags |= flag;

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_SOCIAL);

        stmt->setUInt64(0, GetPlayerGUID().GetCounter());
        stmt->setUInt64(1, friendGuid.GetCounter());
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

        stmt->setUInt64(0, GetPlayerGUID().GetCounter());
        stmt->setUInt64(1, friendGuid.GetCounter());

        CharacterDatabase.Execute(stmt);

        _playerSocialMap.erase(itr);
    }
    else
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHARACTER_SOCIAL_FLAGS);

        stmt->setUInt8(0, itr->second.Flags);
        stmt->setUInt64(1, GetPlayerGUID().GetCounter());
        stmt->setUInt64(2, friendGuid.GetCounter());

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
    stmt->setUInt64(1, GetPlayerGUID().GetCounter());
    stmt->setUInt64(2, friendGuid.GetCounter());

    CharacterDatabase.Execute(stmt);
}

void PlayerSocial::SendSocialList(Player* player, uint32 flags)
{
    ASSERT(player);

    WorldPackets::Social::ContactList contactList;
    contactList.Flags = flags;

    for (PlayerSocialMap::value_type& v : _playerSocialMap)
    {
        if (!(v.second.Flags & flags))
            continue;

        sSocialMgr->GetFriendInfo(player, v.first, v.second);

        contactList.Contacts.emplace_back(v.first, v.second);

        // client's friends list and ignore list limit
        if (contactList.Contacts.size() >= (((flags & SOCIAL_FLAG_FRIEND) != 0) ? SOCIALMGR_FRIEND_LIMIT : SOCIALMGR_IGNORE_LIMIT))
            break;
    }

    player->SendDirectMessage(contactList.Write());
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
            friendInfo.Status = FRIEND_STATUS_ONLINE;

        friendInfo.Area = target->GetZoneId();
        friendInfo.Level = target->getLevel();
        friendInfo.Class = target->getClass();
    }
}

void SocialMgr::SendFriendStatus(Player* player, FriendsResult result, ObjectGuid const& friendGuid, bool broadcast /*= false*/)
{
    FriendInfo fi;
    GetFriendInfo(player, friendGuid, fi);

    WorldPackets::Social::FriendStatus friendStatus;
    friendStatus.Initialize(friendGuid, result, fi);

    if (broadcast)
        BroadcastToFriendListers(player, friendStatus.Write());
    else
        player->SendDirectMessage(friendStatus.Write());
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

            ObjectGuid friendGuid = ObjectGuid::Create<HighGuid::Player>(fields[0].GetUInt64());
            ObjectGuid friendAccountGuid = ObjectGuid::Create<HighGuid::WowAccount>(uint64(fields[1].GetUInt32()));

            uint8 flag = fields[2].GetUInt8();
            social->_playerSocialMap[friendGuid] = FriendInfo(friendAccountGuid, flag, fields[3].GetString());
        }
        while (result->NextRow());
    }

    return social;
}
