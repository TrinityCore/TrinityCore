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

#ifndef __TRINITY_SOCIALMGR_H
#define __TRINITY_SOCIALMGR_H

#include "DatabaseEnvFwd.h"
#include "Common.h"
#include "ObjectGuid.h"
#include <type_traits>
#include <unordered_map>

class Player;
class WorldSession;

enum FriendStatus : uint8
{
    FRIEND_STATUS_OFFLINE   = 0x00,
    FRIEND_STATUS_ONLINE    = 0x01,
    FRIEND_STATUS_AFK       = 0x02,
    FRIEND_STATUS_DND       = 0x04,
    FRIEND_STATUS_RAF       = 0x08
};

enum SocialFlag : uint32
{
    SOCIAL_FLAG_FRIEND      = 0x01,
    SOCIAL_FLAG_IGNORED     = 0x02,
    SOCIAL_FLAG_UNK1        = 0x04,                          // Unknown - muted?
    SOCIAL_FLAG_UNK2        = 0x08,                          // Unknown - does not appear to be RaF

    SOCIAL_FLAG_ALL         = SOCIAL_FLAG_FRIEND | SOCIAL_FLAG_IGNORED
};

/// Results of friend related commands
enum FriendsResult : uint8
{
    FRIEND_DB_ERROR         = 0x00,
    FRIEND_LIST_FULL        = 0x01,
    FRIEND_ONLINE           = 0x02,
    FRIEND_OFFLINE          = 0x03,
    FRIEND_NOT_FOUND        = 0x04,
    FRIEND_REMOVED          = 0x05,
    FRIEND_ADDED_ONLINE     = 0x06,
    FRIEND_ADDED_OFFLINE    = 0x07,
    FRIEND_ALREADY          = 0x08,
    FRIEND_SELF             = 0x09,
    FRIEND_ENEMY            = 0x0A,
    FRIEND_IGNORE_FULL      = 0x0B,
    FRIEND_IGNORE_SELF      = 0x0C,
    FRIEND_IGNORE_NOT_FOUND = 0x0D,
    FRIEND_IGNORE_ALREADY   = 0x0E,
    FRIEND_IGNORE_ADDED     = 0x0F,
    FRIEND_IGNORE_REMOVED   = 0x10,
    FRIEND_IGNORE_AMBIGUOUS = 0x11,                         // That name is ambiguous, type more of the player's server name
    FRIEND_MUTE_FULL        = 0x12,
    FRIEND_MUTE_SELF        = 0x13,
    FRIEND_MUTE_NOT_FOUND   = 0x14,
    FRIEND_MUTE_ALREADY     = 0x15,
    FRIEND_MUTE_ADDED       = 0x16,
    FRIEND_MUTE_REMOVED     = 0x17,
    FRIEND_MUTE_AMBIGUOUS   = 0x18,                         // That name is ambiguous, type more of the player's server name
    FRIEND_UNK1             = 0x19,                         // no message at client
    FRIEND_UNK2             = 0x1A,
    FRIEND_UNK3             = 0x1B,
    FRIEND_UNKNOWN          = 0x1C                          // Unknown friend response from server
};

#define SOCIALMGR_FRIEND_LIMIT  50u
#define SOCIALMGR_IGNORE_LIMIT  50u

struct SocialLink
{
    std::underlying_type_t<SocialFlag> Flags = 0x0;
    std::string Note;
    bool IsDirty = false;

    bool IsFriend() const { return (Flags & SOCIAL_FLAG_FRIEND); }
    bool IsIgnore() const { return (Flags & SOCIAL_FLAG_IGNORED); }
};

class SocialMgr
{
    private:
        SocialMgr() { }
        ~SocialMgr();

    public:
        static constexpr size_t MAX_SOCIALS_PER_FLAG = 50;

        static SocialMgr* instance();

        void LoadPlayerFromDB(Player const* player, PreparedQueryResult data);
        void SavePlayerToDB(Player const* player, SQLTransaction trans);
        void UnloadPlayer(ObjectGuid playerGuid);
        void EraseAllSocialLinks(ObjectGuid playerGuid, SQLTransaction trans);

        void AddSocialLink(Player const* player, std::string const& targetName, SocialFlag flag, std::string const& note = "");
        void SetSocialLinkNote(Player const* player, ObjectGuid targetGuid, std::string const& note);
        void RemoveSocialLink(Player const* player, ObjectGuid targetGuid, SocialFlag flag = SOCIAL_FLAG_ALL);

        void SendSocialLinks(Player const* player, SocialFlag filter = SOCIAL_FLAG_ALL) const;
        void BroadcastFriendStatusUpdate(Player const* player, FriendsResult result) const;

        auto const& GetSocialLinksFor(ObjectGuid target) { return _socialLinks[target]; }
        auto const& GetFollowersFor(ObjectGuid target) { return _followers[target]; }

    private:
        void _SendFriendStatusUpdate(Player const* target, ObjectGuid targetGuid, FriendsResult status, Player const* recipient) const;

        std::unordered_map<ObjectGuid, std::unordered_map<ObjectGuid, SocialLink>> _socialLinks;
        std::unordered_map<ObjectGuid, std::unordered_map<ObjectGuid, SocialLink const*>> _followers; // reverse lookup
};

#define sSocialMgr SocialMgr::instance()

#endif
