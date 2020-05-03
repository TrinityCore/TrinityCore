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

#ifndef _CHANNEL_H
#define _CHANNEL_H

#include "Common.h"
#include "ObjectGuid.h"
#include <map>
#include <unordered_set>

class Player;

namespace WorldPackets
{
    namespace Channel
    {
        class ChannelNotify;
    }
}

struct AreaTableEntry;

enum ChatNotify
{
    CHAT_JOINED_NOTICE                = 0x00,           //+ "%s joined channel.";
    CHAT_LEFT_NOTICE                  = 0x01,           //+ "%s left channel.";
    //CHAT_SUSPENDED_NOTICE             = 0x01,           // "%s left channel.";
    CHAT_YOU_JOINED_NOTICE            = 0x02,           //+ "Joined Channel: [%s]"; -- You joined
    //CHAT_YOU_CHANGED_NOTICE           = 0x02,           // "Changed Channel: [%s]";
    CHAT_YOU_LEFT_NOTICE              = 0x03,           //+ "Left Channel: [%s]"; -- You left
    CHAT_WRONG_PASSWORD_NOTICE        = 0x04,           //+ "Wrong password for %s.";
    CHAT_NOT_MEMBER_NOTICE            = 0x05,           //+ "Not on channel %s.";
    CHAT_NOT_MODERATOR_NOTICE         = 0x06,           //+ "Not a moderator of %s.";
    CHAT_PASSWORD_CHANGED_NOTICE      = 0x07,           //+ "[%s] Password changed by %s.";
    CHAT_OWNER_CHANGED_NOTICE         = 0x08,           //+ "[%s] Owner changed to %s.";
    CHAT_PLAYER_NOT_FOUND_NOTICE      = 0x09,           //+ "[%s] Player %s was not found.";
    CHAT_NOT_OWNER_NOTICE             = 0x0A,           //+ "[%s] You are not the channel owner.";
    CHAT_CHANNEL_OWNER_NOTICE         = 0x0B,           //+ "[%s] Channel owner is %s.";
    CHAT_MODE_CHANGE_NOTICE           = 0x0C,           //?
    CHAT_ANNOUNCEMENTS_ON_NOTICE      = 0x0D,           //+ "[%s] Channel announcements enabled by %s.";
    CHAT_ANNOUNCEMENTS_OFF_NOTICE     = 0x0E,           //+ "[%s] Channel announcements disabled by %s.";
    CHAT_MODERATION_ON_NOTICE         = 0x0F,           //+ "[%s] Channel moderation enabled by %s.";
    CHAT_MODERATION_OFF_NOTICE        = 0x10,           //+ "[%s] Channel moderation disabled by %s.";
    CHAT_MUTED_NOTICE                 = 0x11,           //+ "[%s] You do not have permission to speak.";
    CHAT_PLAYER_KICKED_NOTICE         = 0x12,           //? "[%s] Player %s kicked by %s.";
    CHAT_BANNED_NOTICE                = 0x13,           //+ "[%s] You are banned from that channel.";
    CHAT_PLAYER_BANNED_NOTICE         = 0x14,           //? "[%s] Player %s banned by %s.";
    CHAT_PLAYER_UNBANNED_NOTICE       = 0x15,           //? "[%s] Player %s unbanned by %s.";
    CHAT_PLAYER_NOT_BANNED_NOTICE     = 0x16,           //+ "[%s] Player %s is not banned.";
    CHAT_PLAYER_ALREADY_MEMBER_NOTICE = 0x17,           //+ "[%s] Player %s is already on the channel.";
    CHAT_INVITE_NOTICE                = 0x18,           //+ "%2$s has invited you to join the channel '%1$s'.";
    CHAT_INVITE_WRONG_FACTION_NOTICE  = 0x19,           //+ "Target is in the wrong alliance for %s.";
    CHAT_WRONG_FACTION_NOTICE         = 0x1A,           //+ "Wrong alliance for %s.";
    CHAT_INVALID_NAME_NOTICE          = 0x1B,           //+ "Invalid channel name";
    CHAT_NOT_MODERATED_NOTICE         = 0x1C,           //+ "%s is not moderated";
    CHAT_PLAYER_INVITED_NOTICE        = 0x1D,           //+ "[%s] You invited %s to join the channel";
    CHAT_PLAYER_INVITE_BANNED_NOTICE  = 0x1E,           //+ "[%s] %s has been banned.";
    CHAT_THROTTLED_NOTICE             = 0x1F,           //+ "[%s] The number of messages that can be sent to this channel is limited, please wait to send another message.";
    CHAT_NOT_IN_AREA_NOTICE           = 0x20,           //+ "[%s] You are not in the correct area for this channel."; -- The user is trying to send a chat to a zone specific channel, and they're not physically in that zone.
    CHAT_NOT_IN_LFG_NOTICE            = 0x21,           //+ "[%s] You must be queued in looking for group before joining this channel."; -- The user must be in the looking for group system to join LFG chat channels.
    CHAT_VOICE_ON_NOTICE              = 0x22,           //+ "[%s] Channel voice enabled by %s.";
    CHAT_VOICE_OFF_NOTICE             = 0x23,           //+ "[%s] Channel voice disabled by %s.";
    CHAT_TRIAL_RESTRICTED             = 0x24,
    CHAT_NOT_ALLOWED_IN_CHANNEL       = 0x25
};

enum ChannelFlags
{
    CHANNEL_FLAG_NONE       = 0x00,
    CHANNEL_FLAG_CUSTOM     = 0x01,
    // 0x02
    CHANNEL_FLAG_TRADE      = 0x04,
    CHANNEL_FLAG_NOT_LFG    = 0x08,
    CHANNEL_FLAG_GENERAL    = 0x10,
    CHANNEL_FLAG_CITY       = 0x20,
    CHANNEL_FLAG_LFG        = 0x40,
    CHANNEL_FLAG_VOICE      = 0x80
    // General                  0x18 = 0x10 | 0x08
    // Trade                    0x3C = 0x20 | 0x10 | 0x08 | 0x04
    // LocalDefense             0x18 = 0x10 | 0x08
    // GuildRecruitment         0x38 = 0x20 | 0x10 | 0x08
    // LookingForGroup          0x50 = 0x40 | 0x10
};

enum ChannelDBCFlags
{
    CHANNEL_DBC_FLAG_NONE       = 0x00000,
    CHANNEL_DBC_FLAG_INITIAL    = 0x00001,              // General, Trade, LocalDefense, LFG
    CHANNEL_DBC_FLAG_ZONE_DEP   = 0x00002,              // General, Trade, LocalDefense, GuildRecruitment
    CHANNEL_DBC_FLAG_GLOBAL     = 0x00004,              // WorldDefense
    CHANNEL_DBC_FLAG_TRADE      = 0x00008,              // Trade, LFG
    CHANNEL_DBC_FLAG_CITY_ONLY  = 0x00010,              // Trade, GuildRecruitment, LFG
    CHANNEL_DBC_FLAG_CITY_ONLY2 = 0x00020,              // Trade, GuildRecruitment, LFG
    CHANNEL_DBC_FLAG_DEFENSE    = 0x10000,              // LocalDefense, WorldDefense
    CHANNEL_DBC_FLAG_GUILD_REQ  = 0x20000,              // GuildRecruitment
    CHANNEL_DBC_FLAG_LFG        = 0x40000,              // LFG
    CHANNEL_DBC_FLAG_UNK1       = 0x80000               // General
};

enum ChannelMemberFlags
{
    MEMBER_FLAG_NONE        = 0x00,
    MEMBER_FLAG_OWNER       = 0x01,
    MEMBER_FLAG_MODERATOR   = 0x02,
    MEMBER_FLAG_VOICED      = 0x04,
    MEMBER_FLAG_MUTED       = 0x08,
    MEMBER_FLAG_CUSTOM      = 0x10,
    MEMBER_FLAG_MIC_MUTED   = 0x20
    // 0x40
    // 0x80
};

class TC_GAME_API Channel
{
    struct PlayerInfo
    {
        uint8 GetFlags() const { return _flags; }

        bool IsInvisible() const { return _invisible; }
        void SetInvisible(bool on) { _invisible = on; }

        inline bool HasFlag(uint8 flag) const { return (_flags & flag) != 0; }
        inline void SetFlag(uint8 flag) { _flags |= flag; }
        inline void RemoveFlag(uint8 flag) { _flags &= ~flag; }

        bool IsOwner() const { return HasFlag(MEMBER_FLAG_OWNER); }
        void SetOwner(bool state)
        {
            if (state)
                SetFlag(MEMBER_FLAG_OWNER);
            else
                RemoveFlag(MEMBER_FLAG_OWNER);
        }

        bool IsModerator() const { return HasFlag(MEMBER_FLAG_MODERATOR); }
        void SetModerator(bool state)
        {
            if (state)
                SetFlag(MEMBER_FLAG_MODERATOR);
            else
                RemoveFlag(MEMBER_FLAG_MODERATOR);
        }

        bool IsMuted() const { return HasFlag(MEMBER_FLAG_MUTED); }
        void SetMuted(bool state)
        {
            if (state)
                SetFlag(MEMBER_FLAG_MUTED);
            else
                RemoveFlag(MEMBER_FLAG_MUTED);
        }

    private:
        uint8 _flags = MEMBER_FLAG_NONE;
        bool _invisible = false;
    };

    public:
        Channel(ObjectGuid const& guid, uint32 channelId, uint32 team = 0, AreaTableEntry const* zoneEntry = nullptr);  // built-in channel ctor
        Channel(ObjectGuid const& guid, std::string const& name, uint32 team = 0);                                      // custom player channel ctor

        static void GetChannelName(std::string& channelName, uint32 channelId, LocaleConstant locale, AreaTableEntry const* zoneEntry);
        std::string GetName(LocaleConstant locale = DEFAULT_LOCALE) const;

        uint32 GetChannelId() const { return _channelId; }
        bool IsConstant() const { return _channelId != 0; }

        bool IsLFG() const { return (GetFlags() & CHANNEL_FLAG_LFG) != 0; }

        bool IsAnnounce() const { return _announceEnabled; }
        void SetAnnounce(bool nannounce) { _announceEnabled = nannounce; }

        std::string const& GetPassword() const { return _channelPassword; }
        void SetPassword(std::string const& npassword) { _channelPassword = npassword; }

        uint32 GetNumPlayers() const { return uint32(_playersStore.size()); }

        uint8 GetFlags() const { return _channelFlags; }
        bool HasFlag(uint8 flag) const { return (_channelFlags & flag) != 0; }

        AreaTableEntry const* GetZoneEntry() const { return _zoneEntry; }

        void JoinChannel(Player* player, std::string const& pass);
        void LeaveChannel(Player* player, bool send = true, bool suspend = false);

        void KickOrBan(Player const* player, std::string const& badname, bool ban);
        void Kick(Player const* player, std::string const& badname) { KickOrBan(player, badname, false); }
        void Ban(Player const* player, std::string const& badname) { KickOrBan(player, badname, true); }

        void UnBan(Player const* player, std::string const& badname);
        void Password(Player const* player, std::string const& pass);
        void SetMode(Player const* player, std::string const& p2n, bool mod, bool set);

        void SetInvisible(Player const* player, bool on);

        void SetOwner(ObjectGuid const& guid, bool exclaim = true);
        void SetOwner(Player const* player, std::string const& name);
        void SendWhoOwner(Player const* player);

        void SetModerator(Player const* player, std::string const& newname) { SetMode(player, newname, true, true); }
        void UnsetModerator(Player const* player, std::string const& newname) { SetMode(player, newname, true, false); }
        void SetMute(Player const* player, std::string const& newname) { SetMode(player, newname, false, true); }
        void UnsetMute(Player const* player, std::string const& newname) { SetMode(player, newname, false, false); }
        void SilenceAll(Player const* player, std::string const& name);
        void UnsilenceAll(Player const* player, std::string const& name);
        void List(Player const* player);
        void Announce(Player const* player);
        void Say(ObjectGuid const& guid, std::string const& what, uint32 lang) const;
        void AddonSay(ObjectGuid const& guid, std::string const& prefix, std::string const& what, bool isLogged) const;
        void DeclineInvite(Player const* player);
        void Invite(Player const* player, std::string const& newp);
        void JoinNotify(Player const* player);
        void LeaveNotify(Player const* player);
        void SetOwnership(bool ownership) { _ownershipEnabled = ownership; }
        static void CleanOldChannelsInDB();

    private:
        template <class Builder>
        void SendToAll(Builder& builder, ObjectGuid const& guid = ObjectGuid::Empty) const;

        template <class Builder>
        void SendToAllButOne(Builder& builder, ObjectGuid const& who) const;

        template <class Builder>
        void SendToOne(Builder& builder, ObjectGuid const& who) const;

        template <class Builder>
        void SendToAllWithAddon(Builder& builder, std::string const& addonPrefix, ObjectGuid const& guid = ObjectGuid::Empty) const;

        bool IsOn(ObjectGuid const& who) const { return _playersStore.count(who) != 0; }
        bool IsBanned(ObjectGuid const& guid) const { return _bannedStore.count(guid) != 0; }

        void UpdateChannelInDB() const;
        void UpdateChannelUseageInDB() const;

        uint8 GetPlayerFlags(ObjectGuid const& guid) const
        {
            PlayerContainer::const_iterator itr = _playersStore.find(guid);
            return itr != _playersStore.end() ? itr->second.GetFlags() : 0;
        }

        void SetModerator(ObjectGuid const& guid, bool set);
        void SetMute(ObjectGuid const& guid, bool set);

        typedef std::map<ObjectGuid, PlayerInfo> PlayerContainer;
        typedef GuidUnorderedSet BannedContainer;

        bool _announceEnabled;          //< Whether we should broadcast a packet whenever a player joins/exits the channel
        bool _ownershipEnabled;         //< Whether the channel has to maintain an owner
        bool _persistentChannel;        //< Whether the channel is saved to DB
        bool _isOwnerInvisible;         //< Whether the channel is owned by invisible GM, ownership should change to first player that joins channel

        uint8 _channelFlags;
        uint32 _channelId;
        uint32 _channelTeam;
        ObjectGuid _channelGuid;
        ObjectGuid _ownerGuid;
        std::string _channelName;
        std::string _channelPassword;
        PlayerContainer _playersStore;
        BannedContainer _bannedStore;

        AreaTableEntry const* _zoneEntry;
};

#endif
