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
#include "DatabaseEnv.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "QueryCallback.h"
#include "RBAC.h"
#include "Realm.h"
#include "SocialMgr.h"
#include "SocialPackets.h"
#include "World.h"

void WorldSession::HandleContactListOpcode(WorldPackets::Social::SendContactList& packet)
{
    TC_LOG_DEBUG("network", "WorldSession::HandleContactListOpcode: Flags: %u", packet.Flags);
    _player->GetSocial()->SendSocialList(_player, packet.Flags);
}

void WorldSession::HandleAddFriendOpcode(WorldPackets::Social::AddFriend& packet)
{
    if (!normalizePlayerName(packet.Name))
        return;

    TC_LOG_DEBUG("network", "WorldSession::HandleAddFriendOpcode: %s asked to add friend: %s",
        GetPlayerInfo().c_str(), packet.Name.c_str());

    CharacterCacheEntry const* friendCharacterInfo = sCharacterCache->GetCharacterCacheByName(packet.Name);
    if (!friendCharacterInfo)
    {
        sSocialMgr->SendFriendStatus(GetPlayer(), FRIEND_NOT_FOUND, ObjectGuid::Empty);
        return;
    }

    auto processFriendRequest = [this,
        playerGuid = _player->GetGUID(),
        friendGuid = friendCharacterInfo->Guid,
        friendAccountGuid = ObjectGuid::Create<HighGuid::WowAccount>(friendCharacterInfo->AccountId),
        team = Player::TeamForRace(friendCharacterInfo->Race),
        friendNote = std::move(packet.Notes)]()
    {
        if (playerGuid.GetCounter() != m_GUIDLow)
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
            if (GetPlayer()->GetSocial()->AddToSocialList(friendGuid, friendAccountGuid, SOCIAL_FLAG_FRIEND))
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

void WorldSession::HandleDelFriendOpcode(WorldPackets::Social::DelFriend& packet)
{
    /// @todo: handle VirtualRealmAddress
    TC_LOG_DEBUG("network", "WorldSession::HandleDelFriendOpcode: %s", packet.Player.Guid.ToString().c_str());

    GetPlayer()->GetSocial()->RemoveFromSocialList(packet.Player.Guid, SOCIAL_FLAG_FRIEND);

    sSocialMgr->SendFriendStatus(GetPlayer(), FRIEND_REMOVED, packet.Player.Guid);
}

void WorldSession::HandleAddIgnoreOpcode(WorldPackets::Social::AddIgnore& packet)
{
    if (!normalizePlayerName(packet.Name))
        return;

    TC_LOG_DEBUG("network", "WorldSession::HandleAddIgnoreOpcode: %s asked to Ignore: %s",
        GetPlayer()->GetName().c_str(), packet.Name.c_str());

    ObjectGuid ignoreGuid;
    FriendsResult ignoreResult = FRIEND_IGNORE_NOT_FOUND;

    if (CharacterCacheEntry const* characterInfo = sCharacterCache->GetCharacterCacheByName(packet.Name))
    {
        ignoreGuid = characterInfo->Guid;
        ObjectGuid ignoreAccountGuid = ObjectGuid::Create<HighGuid::WowAccount>(characterInfo->AccountId);
        if (ignoreGuid == GetPlayer()->GetGUID())              //not add yourself
            ignoreResult = FRIEND_IGNORE_SELF;
        else if (GetPlayer()->GetSocial()->HasIgnore(ignoreGuid, ignoreAccountGuid))
            ignoreResult = FRIEND_IGNORE_ALREADY;
        else
        {
            ignoreResult = FRIEND_IGNORE_ADDED;

            // ignore list full
            if (!GetPlayer()->GetSocial()->AddToSocialList(ignoreGuid, ignoreAccountGuid, SOCIAL_FLAG_IGNORED))
                ignoreResult = FRIEND_IGNORE_FULL;
        }
    }

    sSocialMgr->SendFriendStatus(GetPlayer(), ignoreResult, ObjectGuid::Empty);
}

void WorldSession::HandleDelIgnoreOpcode(WorldPackets::Social::DelIgnore& packet)
{
    /// @todo: handle VirtualRealmAddress
    TC_LOG_DEBUG("network", "WorldSession::HandleDelIgnoreOpcode: %s", packet.Player.Guid.ToString().c_str());

    GetPlayer()->GetSocial()->RemoveFromSocialList(packet.Player.Guid, SOCIAL_FLAG_IGNORED);

    sSocialMgr->SendFriendStatus(GetPlayer(), FRIEND_IGNORE_REMOVED, packet.Player.Guid);
}

void WorldSession::HandleSetContactNotesOpcode(WorldPackets::Social::SetContactNotes& packet)
{
    /// @todo: handle VirtualRealmAddress
    TC_LOG_DEBUG("network", "WorldSession::HandleSetContactNotesOpcode: Contact: %s, Notes: %s", packet.Player.Guid.ToString().c_str(), packet.Notes.c_str());
    _player->GetSocial()->SetFriendNote(packet.Player.Guid, packet.Notes);
}
