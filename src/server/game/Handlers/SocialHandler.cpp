/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "RBAC.h"
#include "Realm.h"
#include "SocialMgr.h"
#include "World.h"

void WorldSession::HandleContactListOpcode(WorldPacket& recvData)
{
    uint32 flags;
    recvData >> flags;
    sSocialMgr->SendSocialLinks(GetPlayer(), SocialFlag(flags & SOCIAL_FLAG_ALL));
}

void WorldSession::HandleAddFriendOpcode(WorldPacket& recvData)
{
    std::string friendName, friendNote;
    recvData >> friendName >> friendNote;

    if (!normalizePlayerName(friendName))
        return;

    TC_LOG_DEBUG("network", "WorldSession::HandleAddFriendOpcode: %s asked to add friend: %s",
        GetPlayer()->GetName().c_str(), friendName.c_str());

    sSocialMgr->AddSocialLink(GetPlayer(), friendName, SOCIAL_FLAG_FRIEND, friendNote);
}

void WorldSession::HandleDelFriendOpcode(WorldPacket& recvData)
{
    ObjectGuid friendGuid;
    recvData >> friendGuid;
    TC_LOG_DEBUG("network", "WorldSession::HandleDelFriendOpcode: %s", friendGuid.ToString().c_str());

    sSocialMgr->RemoveSocialLink(GetPlayer(), friendGuid, SOCIAL_FLAG_FRIEND);
}

void WorldSession::HandleAddIgnoreOpcode(WorldPacket& recvData)
{
    std::string ignoreName;
    recvData >> ignoreName;

    if (!normalizePlayerName(ignoreName))
        return;

    TC_LOG_DEBUG("network", "WorldSession::HandleAddIgnoreOpcode: %s asked to Ignore: %s",
        GetPlayer()->GetName().c_str(), ignoreName.c_str());

    sSocialMgr->AddSocialLink(GetPlayer(), ignoreName, SOCIAL_FLAG_IGNORED);
}

void WorldSession::HandleDelIgnoreOpcode(WorldPacket& recvData)
{
    ObjectGuid ignoreGuid;
    recvData >> ignoreGuid;

    TC_LOG_DEBUG("network", "WorldSession::HandleDelIgnoreOpcode: %s", ignoreGuid.ToString().c_str());

    sSocialMgr->RemoveSocialLink(GetPlayer(), ignoreGuid, SOCIAL_FLAG_IGNORED);
}

void WorldSession::HandleSetContactNotesOpcode(WorldPacket& recvData)
{
    ObjectGuid guid;
    std::string note;
    recvData >> guid >> note;

    TC_LOG_DEBUG("network", "WorldSession::HandleSetContactNotesOpcode: Contact: %s, Notes: %s", guid.ToString().c_str(), note.c_str());

    sSocialMgr->SetSocialLinkNote(GetPlayer(), guid, note);
}
