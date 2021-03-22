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

    FriendsResult friendResult = FRIEND_NOT_FOUND;
    ObjectGuid friendGuid = sCharacterCache->GetCharacterGuidByName(packet.Name);
    if (!friendGuid.IsEmpty())
    {
        if (CharacterCacheEntry const* characterInfo = sCharacterCache->GetCharacterCacheByGuid(friendGuid))
        {
            uint32 team = Player::TeamForRace(characterInfo->Race);
            uint32 friendAccountId = characterInfo->AccountId;

            if (HasPermission(rbac::RBAC_PERM_ALLOW_GM_FRIEND) || AccountMgr::IsPlayerAccount(AccountMgr::GetSecurity(friendAccountId, realm.Id.Realm)))
            {
                if (friendGuid == GetPlayer()->GetGUID())
                    friendResult = FRIEND_SELF;
                else if (GetPlayer()->GetTeam() != team && !HasPermission(rbac::RBAC_PERM_TWO_SIDE_ADD_FRIEND))
                    friendResult = FRIEND_ENEMY;
                else if (GetPlayer()->GetSocial()->HasFriend(friendGuid))
                    friendResult = FRIEND_ALREADY;
                else
                {
                    Player* playerFriend = ObjectAccessor::FindPlayer(friendGuid);
                    if (playerFriend && playerFriend->IsVisibleGloballyFor(GetPlayer()))
                        friendResult = FRIEND_ADDED_ONLINE;
                    else
                        friendResult = FRIEND_ADDED_OFFLINE;

                    if (GetPlayer()->GetSocial()->AddToSocialList(friendGuid, SOCIAL_FLAG_FRIEND))
                        GetPlayer()->GetSocial()->SetFriendNote(friendGuid, packet.Notes);
                    else
                        friendResult = FRIEND_LIST_FULL;
                }
            }
        }
    }

    sSocialMgr->SendFriendStatus(GetPlayer(), friendResult, friendGuid);
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

    ObjectGuid ignoreGuid = sCharacterCache->GetCharacterGuidByName(packet.Name);
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
