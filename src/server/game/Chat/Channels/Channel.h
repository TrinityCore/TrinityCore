/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#ifndef _CHANNEL_H
#define _CHANNEL_H

#include <list>
#include <map>
#include <string>

#include "Common.h"

#include "Opcodes.h"
#include "Player.h"
#include "WorldPacket.h"

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
    // CHAT_MODERATION_ON_NOTICE         = 0x0F,           //+ "[%s] Channel moderation enabled by %s.";
    // CHAT_MODERATION_OFF_NOTICE        = 0x10,           //+ "[%s] Channel moderation disabled by %s.";
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
    // LocalDefence             0x18 = 0x10 | 0x08
    // GuildRecruitment         0x38 = 0x20 | 0x10 | 0x08
    // LookingForGroup          0x50 = 0x40 | 0x10
};

enum ChannelDBCFlags
{
    CHANNEL_DBC_FLAG_NONE       = 0x00000,
    CHANNEL_DBC_FLAG_INITIAL    = 0x00001,              // General, Trade, LocalDefense, LFG
    CHANNEL_DBC_FLAG_ZONE_DEP   = 0x00002,              // General, Trade, LocalDefense, GuildRecruitment
    CHANNEL_DBC_FLAG_GLOBAL     = 0x00004,              // WorldDefense
    CHANNEL_DBC_FLAG_TRADE      = 0x00008,              // Trade
    CHANNEL_DBC_FLAG_CITY_ONLY  = 0x00010,              // Trade, GuildRecruitment
    CHANNEL_DBC_FLAG_CITY_ONLY2 = 0x00020,              // Trade, GuildRecruitment
    CHANNEL_DBC_FLAG_DEFENSE    = 0x10000,              // LocalDefense, WorldDefense
    CHANNEL_DBC_FLAG_GUILD_REQ  = 0x20000,              // GuildRecruitment
    CHANNEL_DBC_FLAG_LFG        = 0x40000               // LookingForGroup
};

enum ChannelMemberFlags
{
    MEMBER_FLAG_NONE        = 0x00,
    MEMBER_FLAG_OWNER       = 0x01,
    MEMBER_FLAG_MODERATOR   = 0x02,
    MEMBER_FLAG_VOICED      = 0x04,
    MEMBER_FLAG_MUTED       = 0x08,
    MEMBER_FLAG_CUSTOM      = 0x10,
    MEMBER_FLAG_MIC_MUTED   = 0x20,
    // 0x40
    // 0x80
};

class Channel
{
    struct PlayerInfo
    {
        uint64 player;
        uint8 flags;

        bool HasFlag(uint8 flag) const { return flags & flag; }
        void SetFlag(uint8 flag) { if (!HasFlag(flag)) flags |= flag; }
        bool IsOwner() const { return flags & MEMBER_FLAG_OWNER; }
        void SetOwner(bool state)
        {
            if (state) flags |= MEMBER_FLAG_OWNER;
            else flags &= ~MEMBER_FLAG_OWNER;
        }
        bool IsModerator() const { return flags & MEMBER_FLAG_MODERATOR; }
        void SetModerator(bool state)
        {
            if (state) flags |= MEMBER_FLAG_MODERATOR;
            else flags &= ~MEMBER_FLAG_MODERATOR;
        }
        bool IsMuted() const { return flags & MEMBER_FLAG_MUTED; }
        void SetMuted(bool state)
        {
            if (state) flags |= MEMBER_FLAG_MUTED;
            else flags &= ~MEMBER_FLAG_MUTED;
        }
    };

    typedef     std::map<uint64, PlayerInfo> PlayerList;
    PlayerList  players;
    typedef     std::set<uint64> BannedList;
    BannedList  banned;
    bool        m_announce;
    bool        m_ownership;
    std::string m_name;
    std::string m_password;
    uint8       m_flags;
    uint32      m_channelId;
    uint64      m_ownerGUID;
    bool        m_IsSaved;

    private:
        // initial packet data (notify type and channel name)
        void MakeNotifyPacket(WorldPacket *data, uint8 notify_type);
        // type specific packet data
        void MakeJoined(WorldPacket *data, uint64 guid);                        //+ 0x00
        void MakeLeft(WorldPacket *data, uint64 guid);                          //+ 0x01
        void MakeYouJoined(WorldPacket *data);                                  //+ 0x02
        void MakeYouLeft(WorldPacket *data);                                    //+ 0x03
        void MakeWrongPassword(WorldPacket *data);                              //? 0x04
        void MakeNotMember(WorldPacket *data);                                  //? 0x05
        void MakeNotModerator(WorldPacket *data);                               //? 0x06
        void MakePasswordChanged(WorldPacket *data, uint64 guid);               //+ 0x07
        void MakeOwnerChanged(WorldPacket *data, uint64 guid);                  //? 0x08
        void MakePlayerNotFound(WorldPacket *data, const std::string& name);    //+ 0x09
        void MakeNotOwner(WorldPacket *data);                                   //? 0x0A
        void MakeChannelOwner(WorldPacket *data);                               //? 0x0B
        void MakeModeChange(WorldPacket *data, uint64 guid, uint8 oldflags);    //+ 0x0C
        void MakeAnnouncementsOn(WorldPacket *data, uint64 guid);               //+ 0x0D
        void MakeAnnouncementsOff(WorldPacket *data, uint64 guid);              //+ 0x0E
        void MakeMuted(WorldPacket *data);                                      //? 0x11
        void MakePlayerKicked(WorldPacket *data, uint64 bad, uint64 good);      //? 0x12
        void MakeBanned(WorldPacket *data);                                     //? 0x13
        void MakePlayerBanned(WorldPacket *data, uint64 bad, uint64 good);      //? 0x14
        void MakePlayerUnbanned(WorldPacket *data, uint64 bad, uint64 good);    //? 0x15
        void MakePlayerNotBanned(WorldPacket *data, const std::string& name);   //? 0x16
        void MakePlayerAlreadyMember(WorldPacket *data, uint64 guid);           //+ 0x17
        void MakeInvite(WorldPacket *data, uint64 guid);                        //? 0x18
        void MakeInviteWrongFaction(WorldPacket *data);                         //? 0x19
        void MakeWrongFaction(WorldPacket *data);                               //? 0x1A
        void MakeInvalidName(WorldPacket *data);                                //? 0x1B
        void MakeNotModerated(WorldPacket *data);                               //? 0x1C
        void MakePlayerInvited(WorldPacket *data, const std::string& name);     //+ 0x1D
        void MakePlayerInviteBanned(WorldPacket *data, const std::string &name);//? 0x1E
        void MakeThrottled(WorldPacket *data);                                  //? 0x1F
        void MakeNotInArea(WorldPacket *data);                                  //? 0x20
        void MakeNotInLfg(WorldPacket *data);                                   //? 0x21
        void MakeVoiceOn(WorldPacket *data, uint64 guid);                       //+ 0x22
        void MakeVoiceOff(WorldPacket *data, uint64 guid);                      //+ 0x23

        void SendToAll(WorldPacket *data, uint64 p = 0);
        void SendToAllButOne(WorldPacket *data, uint64 who);
        void SendToOne(WorldPacket *data, uint64 who);

        bool IsOn(uint64 who) const { return players.find(who) != players.end(); }
        bool IsBanned(uint64 guid) const { return banned.find(guid) != banned.end(); }

        void UpdateChannelInDB() const;
        void UpdateChannelUseageInDB() const;

        uint8 GetPlayerFlags(uint64 p) const
        {
            PlayerList::const_iterator p_itr = players.find(p);
            if (p_itr == players.end())
                return 0;

            return p_itr->second.flags;
        }

        void SetModerator(uint64 p, bool set)
        {
            if (players[p].IsModerator() != set)
            {
                uint8 oldFlag = GetPlayerFlags(p);
                players[p].SetModerator(set);

                WorldPacket data;
                MakeModeChange(&data, p, oldFlag);
                SendToAll(&data);
            }
        }

        void SetMute(uint64 p, bool set)
        {
            if (players[p].IsMuted() != set)
            {
                uint8 oldFlag = GetPlayerFlags(p);
                players[p].SetMuted(set);

                WorldPacket data;
                MakeModeChange(&data, p, oldFlag);
                SendToAll(&data);
            }
        }

    public:
        uint32 m_Team;
        Channel(const std::string& name, uint32 channel_id, uint32 Team = 0);
        std::string GetName() const { return m_name; }
        uint32 GetChannelId() const { return m_channelId; }
        bool IsConstant() const { return m_channelId != 0; }
        bool IsAnnounce() const { return m_announce; }
        bool IsLFG() const { return GetFlags() & CHANNEL_FLAG_LFG; }
        std::string GetPassword() const { return m_password; }
        void SetPassword(const std::string& npassword) { m_password = npassword; }
        void SetAnnounce(bool nannounce) { m_announce = nannounce; }
        uint32 GetNumPlayers() const { return players.size(); }
        uint8 GetFlags() const { return m_flags; }
        bool HasFlag(uint8 flag) const { return m_flags & flag; }

        void Join(uint64 p, const char *pass);
        void Leave(uint64 p, bool send = true);
        void KickOrBan(uint64 good, const char *badname, bool ban);
        void Kick(uint64 good, const char *badname) { KickOrBan(good, badname, false); }
        void Ban(uint64 good, const char *badname) { KickOrBan(good, badname, true); }
        void UnBan(uint64 good, const char *badname);
        void Password(uint64 p, const char *pass);
        void SetMode(uint64 p, const char *p2n, bool mod, bool set);
        void SetOwner(uint64 p, bool exclaim = true);
        void SetOwner(uint64 p, const char *newname);
        void SendWhoOwner(uint64 p);
        void SetModerator(uint64 p, const char *newname) { SetMode(p, newname, true, true); }
        void UnsetModerator(uint64 p, const char *newname) { SetMode(p, newname, true, false); }
        void SetMute(uint64 p, const char *newname) { SetMode(p, newname, false, true); }
        void UnsetMute(uint64 p, const char *newname) { SetMode(p, newname, false, false); }
        void List(Player* p);
        void Announce(uint64 p);
        void Say(uint64 p, const char *what, uint32 lang);
        void Invite(uint64 p, const char *newp);
        void Voice(uint64 guid1, uint64 guid2);
        void DeVoice(uint64 guid1, uint64 guid2);
        void JoinNotify(uint64 guid);                                           // invisible notify
        void LeaveNotify(uint64 guid);                                          // invisible notify
        void SetOwnership(bool ownership) { m_ownership = ownership; };
        static void CleanOldChannelsInDB();
};
#endif

