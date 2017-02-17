/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#ifndef _CHANNELAPPENDERS_H
#define _CHANNELAPPENDERS_H

#include "Channel.h"
#include "CharacterCache.h"

// initial packet data (notify type and channel name)
template<class PacketModifier>
class ChannelNameBuilder
{
    public:
        ChannelNameBuilder(Channel const* source, PacketModifier const& modifier)
            : _source(source), _modifier(modifier){ }

        void operator()(WorldPacket& data, LocaleConstant locale) const
        {
            // LocalizedPacketDo sends client DBC locale, we need to get available to server locale
            LocaleConstant localeIdx = sWorld->GetAvailableDbcLocale(locale);

            data.Initialize(SMSG_CHANNEL_NOTIFY, 60); // guess size
            data << uint8(_modifier.NotificationType);
            data << _source->GetName(localeIdx);
            _modifier.Append(data);
        }

        private:
            Channel const* _source;
            PacketModifier _modifier;
};

struct JoinedAppend
{
    explicit JoinedAppend(ObjectGuid const& guid) : _guid(guid) { }

    static uint8 const NotificationType = CHAT_JOINED_NOTICE;

    void Append(WorldPacket& data) const
    {
        data << uint64(_guid);
    }

private:
    ObjectGuid _guid;
};

struct LeftAppend
{
    explicit LeftAppend(ObjectGuid const& guid) : _guid(guid) { }

    static uint8 const NotificationType = CHAT_LEFT_NOTICE;

    void Append(WorldPacket& data) const
    {
        data << uint64(_guid);
    }

private:
    ObjectGuid _guid;
};

struct YouJoinedAppend
{
    explicit YouJoinedAppend(Channel const* channel) : _channel(channel) { }

    static uint8 const NotificationType = CHAT_YOU_JOINED_NOTICE;

    void Append(WorldPacket& data) const
    {
        data << uint8(_channel->GetFlags());
        data << uint32(_channel->GetChannelId());
        data << uint32(0);
    }

private:
    Channel const* _channel;
};

struct YouLeftAppend
{
    explicit YouLeftAppend(Channel const* channel) : _channel(channel) { }

    static uint8 const NotificationType = CHAT_YOU_LEFT_NOTICE;

    void Append(WorldPacket& data) const
    {
        data << uint32(_channel->GetChannelId());
        data << uint8(_channel->IsConstant());
    }

private:
    Channel const* _channel;
};

struct WrongPasswordAppend
{
    static uint8 const NotificationType = CHAT_WRONG_PASSWORD_NOTICE;

    void Append(WorldPacket& /*data*/) const { }
};

struct NotMemberAppend
{
    static uint8 const NotificationType = CHAT_NOT_MEMBER_NOTICE;

    void Append(WorldPacket& /*data*/) const { }
};

struct NotModeratorAppend
{
    static uint8 const NotificationType = CHAT_NOT_MODERATOR_NOTICE;

    void Append(WorldPacket& /*data*/) const { }
};

struct PasswordChangedAppend
{
    explicit PasswordChangedAppend(ObjectGuid const& guid) : _guid(guid) { }

    static uint8 const NotificationType = CHAT_PASSWORD_CHANGED_NOTICE;

    void Append(WorldPacket& data) const
    {
        data << uint64(_guid);
    }

private:
    ObjectGuid _guid;
};

struct OwnerChangedAppend
{
    explicit OwnerChangedAppend(ObjectGuid const& guid) : _guid(guid) { }

    static uint8 const NotificationType = CHAT_OWNER_CHANGED_NOTICE;

    void Append(WorldPacket& data) const
    {
        data << uint64(_guid);
    }

private:
    ObjectGuid _guid;
};

struct PlayerNotFoundAppend
{
    explicit PlayerNotFoundAppend(std::string const& playerName) : _playerName(playerName) { }

    static uint8 const NotificationType = CHAT_PLAYER_NOT_FOUND_NOTICE;

    void Append(WorldPacket& data) const
    {
        data << _playerName;
    }

private:
    std::string _playerName;
};

struct NotOwnerAppend
{
    static uint8 const NotificationType = CHAT_NOT_OWNER_NOTICE;

    void Append(WorldPacket& /*data*/) const { }
};

struct ChannelOwnerAppend
{
    explicit ChannelOwnerAppend(Channel const* channel, ObjectGuid const& ownerGuid) : _channel(channel), _ownerGuid(ownerGuid)
    {
        CharacterCacheEntry const* cInfo = sCharacterCache->GetCharacterCacheByGuid(_ownerGuid);
        if (!cInfo || cInfo->Name.empty())
            _ownerName = "PLAYER_NOT_FOUND";
        else
            _ownerName = cInfo->Name;
    }

    static uint8 const NotificationType = CHAT_CHANNEL_OWNER_NOTICE;

    void Append(WorldPacket& data) const
    {
        data << ((_channel->IsConstant() || !_ownerGuid) ? "Nobody" : _ownerName);
    }

private:
    Channel const* _channel;
    ObjectGuid _ownerGuid;

    std::string _ownerName;
};

struct ModeChangeAppend
{
    explicit ModeChangeAppend(ObjectGuid const& guid, uint8 oldFlags, uint8 newFlags) : _guid(guid), _oldFlags(oldFlags), _newFlags(newFlags) { }

    static uint8 const NotificationType = CHAT_MODE_CHANGE_NOTICE;

    void Append(WorldPacket& data) const
    {
        data << uint64(_guid);
        data << uint8(_oldFlags);
        data << uint8(_newFlags);
    }

private:
    ObjectGuid _guid;
    uint8 _oldFlags;
    uint8 _newFlags;
};

struct AnnouncementsOnAppend
{
    explicit AnnouncementsOnAppend(ObjectGuid const& guid) : _guid(guid) { }

    static uint8 const NotificationType = CHAT_ANNOUNCEMENTS_ON_NOTICE;

    void Append(WorldPacket& data) const
    {
        data << uint64(_guid);
    }

private:
    ObjectGuid _guid;
};

struct AnnouncementsOffAppend
{
    explicit AnnouncementsOffAppend(ObjectGuid const& guid) : _guid(guid) { }

    static uint8 const NotificationType = CHAT_ANNOUNCEMENTS_OFF_NOTICE;

    void Append(WorldPacket& data) const
    {
        data << uint64(_guid);
    }

private:
    ObjectGuid _guid;
};

struct MutedAppend
{
    static uint8 const NotificationType = CHAT_MUTED_NOTICE;

    void Append(WorldPacket& /*data*/) const { }
};

struct PlayerKickedAppend
{
    explicit PlayerKickedAppend(ObjectGuid const& kicker, ObjectGuid const& kickee) : _kicker(kicker), _kickee(kickee) { }

    static uint8 const NotificationType = CHAT_PLAYER_KICKED_NOTICE;

    void Append(WorldPacket& data) const
    {
        data << uint64(_kickee);
        data << uint64(_kicker);
    }

private:
    ObjectGuid _kicker;
    ObjectGuid _kickee;
};

struct BannedAppend
{
    static uint8 const NotificationType = CHAT_BANNED_NOTICE;

    void Append(WorldPacket& /*data*/) const { }
};

struct PlayerBannedAppend
{
    explicit PlayerBannedAppend(ObjectGuid const& moderator, ObjectGuid const& banned) : _moderator(moderator), _banned(banned) { }

    static uint8 const NotificationType = CHAT_PLAYER_BANNED_NOTICE;

    void Append(WorldPacket& data) const
    {
        data << uint64(_banned);
        data << uint64(_moderator);
    }

private:
    ObjectGuid _moderator;
    ObjectGuid _banned;
};

struct PlayerUnbannedAppend
{
    explicit PlayerUnbannedAppend(ObjectGuid const& moderator, ObjectGuid const& unbanned) : _moderator(moderator), _unbanned(unbanned) { }

    static uint8 const NotificationType = CHAT_PLAYER_UNBANNED_NOTICE;

    void Append(WorldPacket& data) const
    {
        data << uint64(_unbanned);
        data << uint64(_moderator);
    }

private:
    ObjectGuid _moderator;
    ObjectGuid _unbanned;
};

struct PlayerNotBannedAppend
{
    explicit PlayerNotBannedAppend(std::string const& playerName) : _playerName(playerName) { }

    static uint8 const NotificationType = CHAT_PLAYER_NOT_BANNED_NOTICE;

    void Append(WorldPacket& data) const
    {
        data << _playerName;
    }

private:
    std::string _playerName;
};

struct PlayerAlreadyMemberAppend
{
    explicit PlayerAlreadyMemberAppend(ObjectGuid const& guid) : _guid(guid) { }

    static uint8 const NotificationType = CHAT_PLAYER_ALREADY_MEMBER_NOTICE;

    void Append(WorldPacket& data) const
    {
        data << uint64(_guid);
    }

private:
    ObjectGuid _guid;
};

struct InviteAppend
{
    explicit InviteAppend(ObjectGuid const& guid) : _guid(guid) { }

    static uint8 const NotificationType = CHAT_INVITE_NOTICE;

    void Append(WorldPacket& data) const
    {
        data << uint64(_guid);
    }

private:
    ObjectGuid _guid;
};

struct InviteWrongFactionAppend
{
    static uint8 const NotificationType = CHAT_INVITE_WRONG_FACTION_NOTICE;

    void Append(WorldPacket& /*data*/) const { }
};

struct WrongFactionAppend
{
    static uint8 const NotificationType = CHAT_WRONG_FACTION_NOTICE;

    void Append(WorldPacket& /*data*/) const { }
};

struct InvalidNameAppend
{
    static uint8 const NotificationType = CHAT_INVALID_NAME_NOTICE;

    void Append(WorldPacket& /*data*/) const { }
};

struct NotModeratedAppend
{
    static uint8 const NotificationType = CHAT_NOT_MODERATED_NOTICE;

    void Append(WorldPacket& /*data*/) const { }
};

struct PlayerInvitedAppend
{
    explicit PlayerInvitedAppend(std::string const& playerName) : _playerName(playerName) { }

    static uint8 const NotificationType = CHAT_PLAYER_INVITED_NOTICE;

    void Append(WorldPacket& data) const
    {
        data << _playerName;
    }

private:
    std::string _playerName;
};

struct PlayerInviteBannedAppend
{
    explicit PlayerInviteBannedAppend(std::string const& playerName) : _playerName(playerName) { }

    static uint8 const NotificationType = CHAT_PLAYER_INVITE_BANNED_NOTICE;

    void Append(WorldPacket& data) const
    {
        data << _playerName;
    }

private:
    std::string _playerName;
};

struct ThrottledAppend
{
    static uint8 const NotificationType = CHAT_THROTTLED_NOTICE;

    void Append(WorldPacket& /*data*/) const { }
};

struct NotInAreaAppend
{
    static uint8 const NotificationType = CHAT_NOT_IN_AREA_NOTICE;

    void Append(WorldPacket& /*data*/) const { }
};

struct NotInLFGAppend
{
    static uint8 const NotificationType = CHAT_NOT_IN_LFG_NOTICE;

    void Append(WorldPacket& /*data*/) const { }
};

struct VoiceOnAppend
{
    explicit VoiceOnAppend(ObjectGuid const& guid) : _guid(guid) { }

    static uint8 const NotificationType = CHAT_VOICE_ON_NOTICE;

    void Append(WorldPacket& data) const
    {
        data << uint64(_guid);
    }

private:
    ObjectGuid _guid;
};

struct VoiceOffAppend
{
    explicit VoiceOffAppend(ObjectGuid const& guid) : _guid(guid) { }

    static uint8 const NotificationType = CHAT_VOICE_OFF_NOTICE;

    void Append(WorldPacket& data) const
    {
        data << uint64(_guid);
    }

private:
    ObjectGuid _guid;
};

#endif // _CHANNELAPPENDERS_H
