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
#include "AccountMgr.h"
#include "CharacterCache.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "QueryCallback.h"
#include "RBAC.h"
#include "Realm.h"
#include "SocialMgr.h"
#include "World.h"

void WorldSession::HandleContactListOpcode(WorldPacket& recvData)
{
    uint32 flags;
    recvData >> flags;
    _player->GetSocial()->SendSocialList(_player, flags);
}

void WorldSession::HandleAddFriendOpcode(WorldPacket& recvData)
{
    std::string friendName, friendNote;
    recvData >> friendName >> friendNote;

    if (!normalizePlayerName(friendName))
        return;

    TC_LOG_DEBUG("network", "WorldSession::HandleAddFriendOpcode: %s asked to add friend: %s",
        GetPlayer()->GetName().c_str(), friendName.c_str());

    CharacterCacheEntry const* friendCharacterInfo = sCharacterCache->GetCharacterCacheByName(friendName);
    if (!friendCharacterInfo)
    {
        sSocialMgr->SendFriendStatus(GetPlayer(), FRIEND_NOT_FOUND, ObjectGuid::Empty);
        return;
    }

    auto processFriendRequest = [this,
        playerGuid = _player->GetGUID(),
        friendGuid = friendCharacterInfo->Guid,
        team = Player::TeamForRace(friendCharacterInfo->Race),
        friendNote = std::move(friendNote)]()
    {
        if (playerGuid.GetCounter() != GetGUIDLow())
            return; // not the player initiating request, do nothing

        FriendsResult friendResult = FRIEND_NOT_FOUND;
        if (friendGuid == GetPlayer()->GetGUID())
            friendResult = FRIEND_SELF;
        else if (GetPlayer()->GetTeam() != team && !HasPermission(rbac::RBAC_PERM_TWO_SIDE_ADD_FRIEND))
            friendResult = FRIEND_ENEMY;
        else if (GetPlayer()->GetSocial()->HasFriend(friendGuid))
            friendResult = FRIEND_ALREADY;
        else
        {
            Player* pFriend = ObjectAccessor::FindPlayer(friendGuid);
            if (pFriend && pFriend->IsVisibleGloballyFor(GetPlayer()))
                friendResult = FRIEND_ADDED_ONLINE;
            else
                friendResult = FRIEND_ADDED_OFFLINE;
            if (GetPlayer()->GetSocial()->AddToSocialList(friendGuid, SOCIAL_FLAG_FRIEND))
                GetPlayer()->GetSocial()->SetFriendNote(friendGuid, friendNote);
            else
                friendResult = FRIEND_LIST_FULL;
        }

        sSocialMgr->SendFriendStatus(GetPlayer(), friendResult, friendGuid);
    };

    if (HasPermission(rbac::RBAC_PERM_ALLOW_GM_FRIEND))
    {
        processFriendRequest();
        return;
    }

    // First try looking up friend candidate security from online object
    if (Player* friendPlayer = ObjectAccessor::FindPlayer(friendCharacterInfo->Guid))
    {
        if (!AccountMgr::IsPlayerAccount(friendPlayer->GetSession()->GetSecurity()))
        {
            sSocialMgr->SendFriendStatus(GetPlayer(), FRIEND_NOT_FOUND, ObjectGuid::Empty);
            return;
        }

        processFriendRequest();
        return;
    }

    // When not found, consult database
    GetQueryProcessor().AddCallback(AccountMgr::GetSecurityAsync(friendCharacterInfo->AccountId, realm.Id.Realm,
        [this, continuation = std::move(processFriendRequest)](uint32 friendSecurity)
    {
        if (!AccountMgr::IsPlayerAccount(friendSecurity))
        {
            sSocialMgr->SendFriendStatus(GetPlayer(), FRIEND_NOT_FOUND, ObjectGuid::Empty);
            return;
        }

        continuation();
    }));
}

void WorldSession::HandleDelFriendOpcode(WorldPacket& recvData)
{
    ObjectGuid friendGuid;
    recvData >> friendGuid;
    TC_LOG_DEBUG("network", "WorldSession::HandleDelFriendOpcode: %s", friendGuid.ToString().c_str());

    _player->GetSocial()->RemoveFromSocialList(friendGuid, SOCIAL_FLAG_FRIEND);

    sSocialMgr->SendFriendStatus(GetPlayer(), FRIEND_REMOVED, friendGuid);
}

void WorldSession::HandleAddIgnoreOpcode(WorldPacket& recvData)
{
    std::string ignoreName;
    recvData >> ignoreName;

    if (!normalizePlayerName(ignoreName))
        return;

    TC_LOG_DEBUG("network", "WorldSession::HandleAddIgnoreOpcode: %s asked to Ignore: %s",
        GetPlayer()->GetName().c_str(), ignoreName.c_str());

    ObjectGuid ignoreGuid = sCharacterCache->GetCharacterGuidByName(ignoreName);
    FriendsResult ignoreResult = FRIEND_IGNORE_NOT_FOUND;
    if (!ignoreGuid.IsEmpty())
    {
        if (ignoreGuid == GetPlayer()->GetGUID())              //not add yourself
            ignoreResult = FRIEND_IGNORE_SELF;
        else if (GetPlayer()->GetSocial()->HasIgnore(ignoreGuid))
            ignoreResult = FRIEND_IGNORE_ALREADY;
        else
        {
            ignoreResult = FRIEND_IGNORE_ADDED;

            // ignore list full
            if (!GetPlayer()->GetSocial()->AddToSocialList(ignoreGuid, SOCIAL_FLAG_IGNORED))
                ignoreResult = FRIEND_IGNORE_FULL;
        }
    }

    sSocialMgr->SendFriendStatus(GetPlayer(), ignoreResult, ignoreGuid);
}

void WorldSession::HandleDelIgnoreOpcode(WorldPacket& recvData)
{
    ObjectGuid ignoreGuid;
    recvData >> ignoreGuid;

    TC_LOG_DEBUG("network", "WorldSession::HandleDelIgnoreOpcode: %s", ignoreGuid.ToString().c_str());

    _player->GetSocial()->RemoveFromSocialList(ignoreGuid, SOCIAL_FLAG_IGNORED);

    sSocialMgr->SendFriendStatus(GetPlayer(), FRIEND_IGNORE_REMOVED, ignoreGuid);
}

void WorldSession::HandleSetContactNotesOpcode(WorldPacket& recvData)
{
    ObjectGuid guid;
    std::string note;
    recvData >> guid >> note;

    TC_LOG_DEBUG("network", "WorldSession::HandleSetContactNotesOpcode: Contact: %s, Notes: %s", guid.ToString().c_str(), note.c_str());

    _player->GetSocial()->SetFriendNote(guid, note);
}
