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

#include "Channel.h"
#include "Define.h"
#include "SmartEnum.h"
#include <stdexcept>

namespace Trinity::Impl::EnumUtilsImpl
{

/************************************************************\
|* data for enum 'ChatNotify' in 'Channel.h' auto-generated *|
\************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<ChatNotify>::ToString(ChatNotify value)
{
    switch (value)
    {
        case CHAT_JOINED_NOTICE: return { "CHAT_JOINED_NOTICE", "CHAT_JOINED_NOTICE", "+ \042%s joined channel.\042;" };
        case CHAT_LEFT_NOTICE: return { "CHAT_LEFT_NOTICE", "CHAT_LEFT_NOTICE", "+ \042%s left channel.\042;" };
        case CHAT_YOU_JOINED_NOTICE: return { "CHAT_YOU_JOINED_NOTICE", "CHAT_YOU_JOINED_NOTICE", "+ \042Joined Channel: [%s]\042; -- You joined" };
        case CHAT_YOU_LEFT_NOTICE: return { "CHAT_YOU_LEFT_NOTICE", "CHAT_YOU_LEFT_NOTICE", "+ \042Left Channel: [%s]\042; -- You left" };
        case CHAT_WRONG_PASSWORD_NOTICE: return { "CHAT_WRONG_PASSWORD_NOTICE", "CHAT_WRONG_PASSWORD_NOTICE", "+ \042Wrong password for %s.\042;" };
        case CHAT_NOT_MEMBER_NOTICE: return { "CHAT_NOT_MEMBER_NOTICE", "CHAT_NOT_MEMBER_NOTICE", "+ \042Not on channel %s.\042;" };
        case CHAT_NOT_MODERATOR_NOTICE: return { "CHAT_NOT_MODERATOR_NOTICE", "CHAT_NOT_MODERATOR_NOTICE", "+ \042Not a moderator of %s.\042;" };
        case CHAT_PASSWORD_CHANGED_NOTICE: return { "CHAT_PASSWORD_CHANGED_NOTICE", "CHAT_PASSWORD_CHANGED_NOTICE", "+ \042[%s] Password changed by %s.\042;" };
        case CHAT_OWNER_CHANGED_NOTICE: return { "CHAT_OWNER_CHANGED_NOTICE", "CHAT_OWNER_CHANGED_NOTICE", "+ \042[%s] Owner changed to %s.\042;" };
        case CHAT_PLAYER_NOT_FOUND_NOTICE: return { "CHAT_PLAYER_NOT_FOUND_NOTICE", "CHAT_PLAYER_NOT_FOUND_NOTICE", "+ \042[%s] Player %s was not found.\042;" };
        case CHAT_NOT_OWNER_NOTICE: return { "CHAT_NOT_OWNER_NOTICE", "CHAT_NOT_OWNER_NOTICE", "+ \042[%s] You are not the channel owner.\042;" };
        case CHAT_CHANNEL_OWNER_NOTICE: return { "CHAT_CHANNEL_OWNER_NOTICE", "CHAT_CHANNEL_OWNER_NOTICE", "+ \042[%s] Channel owner is %s.\042;" };
        case CHAT_MODE_CHANGE_NOTICE: return { "CHAT_MODE_CHANGE_NOTICE", "CHAT_MODE_CHANGE_NOTICE", "?" };
        case CHAT_ANNOUNCEMENTS_ON_NOTICE: return { "CHAT_ANNOUNCEMENTS_ON_NOTICE", "CHAT_ANNOUNCEMENTS_ON_NOTICE", "+ \042[%s] Channel announcements enabled by %s.\042;" };
        case CHAT_ANNOUNCEMENTS_OFF_NOTICE: return { "CHAT_ANNOUNCEMENTS_OFF_NOTICE", "CHAT_ANNOUNCEMENTS_OFF_NOTICE", "+ \042[%s] Channel announcements disabled by %s.\042;" };
        case CHAT_MODERATION_ON_NOTICE: return { "CHAT_MODERATION_ON_NOTICE", "CHAT_MODERATION_ON_NOTICE", "+ \042[%s] Channel moderation enabled by %s.\042;" };
        case CHAT_MODERATION_OFF_NOTICE: return { "CHAT_MODERATION_OFF_NOTICE", "CHAT_MODERATION_OFF_NOTICE", "+ \042[%s] Channel moderation disabled by %s.\042;" };
        case CHAT_MUTED_NOTICE: return { "CHAT_MUTED_NOTICE", "CHAT_MUTED_NOTICE", "+ \042[%s] You do not have permission to speak.\042;" };
        case CHAT_PLAYER_KICKED_NOTICE: return { "CHAT_PLAYER_KICKED_NOTICE", "CHAT_PLAYER_KICKED_NOTICE", "? \042[%s] Player %s kicked by %s.\042;" };
        case CHAT_BANNED_NOTICE: return { "CHAT_BANNED_NOTICE", "CHAT_BANNED_NOTICE", "+ \042[%s] You are banned from that channel.\042;" };
        case CHAT_PLAYER_BANNED_NOTICE: return { "CHAT_PLAYER_BANNED_NOTICE", "CHAT_PLAYER_BANNED_NOTICE", "? \042[%s] Player %s banned by %s.\042;" };
        case CHAT_PLAYER_UNBANNED_NOTICE: return { "CHAT_PLAYER_UNBANNED_NOTICE", "CHAT_PLAYER_UNBANNED_NOTICE", "? \042[%s] Player %s unbanned by %s.\042;" };
        case CHAT_PLAYER_NOT_BANNED_NOTICE: return { "CHAT_PLAYER_NOT_BANNED_NOTICE", "CHAT_PLAYER_NOT_BANNED_NOTICE", "+ \042[%s] Player %s is not banned.\042;" };
        case CHAT_PLAYER_ALREADY_MEMBER_NOTICE: return { "CHAT_PLAYER_ALREADY_MEMBER_NOTICE", "CHAT_PLAYER_ALREADY_MEMBER_NOTICE", "+ \042[%s] Player %s is already on the channel.\042;" };
        case CHAT_INVITE_NOTICE: return { "CHAT_INVITE_NOTICE", "CHAT_INVITE_NOTICE", "+ \042%2$s has invited you to join the channel '%1$s'.\042;" };
        case CHAT_INVITE_WRONG_FACTION_NOTICE: return { "CHAT_INVITE_WRONG_FACTION_NOTICE", "CHAT_INVITE_WRONG_FACTION_NOTICE", "+ \042Target is in the wrong alliance for %s.\042;" };
        case CHAT_WRONG_FACTION_NOTICE: return { "CHAT_WRONG_FACTION_NOTICE", "CHAT_WRONG_FACTION_NOTICE", "+ \042Wrong alliance for %s.\042;" };
        case CHAT_INVALID_NAME_NOTICE: return { "CHAT_INVALID_NAME_NOTICE", "CHAT_INVALID_NAME_NOTICE", "+ \042Invalid channel name\042;" };
        case CHAT_NOT_MODERATED_NOTICE: return { "CHAT_NOT_MODERATED_NOTICE", "CHAT_NOT_MODERATED_NOTICE", "+ \042%s is not moderated\042;" };
        case CHAT_PLAYER_INVITED_NOTICE: return { "CHAT_PLAYER_INVITED_NOTICE", "CHAT_PLAYER_INVITED_NOTICE", "+ \042[%s] You invited %s to join the channel\042;" };
        case CHAT_PLAYER_INVITE_BANNED_NOTICE: return { "CHAT_PLAYER_INVITE_BANNED_NOTICE", "CHAT_PLAYER_INVITE_BANNED_NOTICE", "+ \042[%s] %s has been banned.\042;" };
        case CHAT_THROTTLED_NOTICE: return { "CHAT_THROTTLED_NOTICE", "CHAT_THROTTLED_NOTICE", "+ \042[%s] The number of messages that can be sent to this channel is limited, please wait to send another message.\042;" };
        case CHAT_NOT_IN_AREA_NOTICE: return { "CHAT_NOT_IN_AREA_NOTICE", "CHAT_NOT_IN_AREA_NOTICE", "+ \042[%s] You are not in the correct area for this channel.\042; -- The user is trying to send a chat to a zone specific channel, and they're not physically in that zone." };
        case CHAT_NOT_IN_LFG_NOTICE: return { "CHAT_NOT_IN_LFG_NOTICE", "CHAT_NOT_IN_LFG_NOTICE", "+ \042[%s] You must be queued in looking for group before joining this channel.\042; -- The user must be in the looking for group system to join LFG chat channels." };
        case CHAT_VOICE_ON_NOTICE: return { "CHAT_VOICE_ON_NOTICE", "CHAT_VOICE_ON_NOTICE", "+ \042[%s] Channel voice enabled by %s.\042;" };
        case CHAT_VOICE_OFF_NOTICE: return { "CHAT_VOICE_OFF_NOTICE", "CHAT_VOICE_OFF_NOTICE", "+ \042[%s] Channel voice disabled by %s.\042;" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<ChatNotify>::Count() { return 36; }

template <>
TC_API_EXPORT ChatNotify EnumUtils<ChatNotify>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return CHAT_JOINED_NOTICE;
        case 1: return CHAT_LEFT_NOTICE;
        case 2: return CHAT_YOU_JOINED_NOTICE;
        case 3: return CHAT_YOU_LEFT_NOTICE;
        case 4: return CHAT_WRONG_PASSWORD_NOTICE;
        case 5: return CHAT_NOT_MEMBER_NOTICE;
        case 6: return CHAT_NOT_MODERATOR_NOTICE;
        case 7: return CHAT_PASSWORD_CHANGED_NOTICE;
        case 8: return CHAT_OWNER_CHANGED_NOTICE;
        case 9: return CHAT_PLAYER_NOT_FOUND_NOTICE;
        case 10: return CHAT_NOT_OWNER_NOTICE;
        case 11: return CHAT_CHANNEL_OWNER_NOTICE;
        case 12: return CHAT_MODE_CHANGE_NOTICE;
        case 13: return CHAT_ANNOUNCEMENTS_ON_NOTICE;
        case 14: return CHAT_ANNOUNCEMENTS_OFF_NOTICE;
        case 15: return CHAT_MODERATION_ON_NOTICE;
        case 16: return CHAT_MODERATION_OFF_NOTICE;
        case 17: return CHAT_MUTED_NOTICE;
        case 18: return CHAT_PLAYER_KICKED_NOTICE;
        case 19: return CHAT_BANNED_NOTICE;
        case 20: return CHAT_PLAYER_BANNED_NOTICE;
        case 21: return CHAT_PLAYER_UNBANNED_NOTICE;
        case 22: return CHAT_PLAYER_NOT_BANNED_NOTICE;
        case 23: return CHAT_PLAYER_ALREADY_MEMBER_NOTICE;
        case 24: return CHAT_INVITE_NOTICE;
        case 25: return CHAT_INVITE_WRONG_FACTION_NOTICE;
        case 26: return CHAT_WRONG_FACTION_NOTICE;
        case 27: return CHAT_INVALID_NAME_NOTICE;
        case 28: return CHAT_NOT_MODERATED_NOTICE;
        case 29: return CHAT_PLAYER_INVITED_NOTICE;
        case 30: return CHAT_PLAYER_INVITE_BANNED_NOTICE;
        case 31: return CHAT_THROTTLED_NOTICE;
        case 32: return CHAT_NOT_IN_AREA_NOTICE;
        case 33: return CHAT_NOT_IN_LFG_NOTICE;
        case 34: return CHAT_VOICE_ON_NOTICE;
        case 35: return CHAT_VOICE_OFF_NOTICE;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<ChatNotify>::ToIndex(ChatNotify value)
{
    switch (value)
    {
        case CHAT_JOINED_NOTICE: return 0;
        case CHAT_LEFT_NOTICE: return 1;
        case CHAT_YOU_JOINED_NOTICE: return 2;
        case CHAT_YOU_LEFT_NOTICE: return 3;
        case CHAT_WRONG_PASSWORD_NOTICE: return 4;
        case CHAT_NOT_MEMBER_NOTICE: return 5;
        case CHAT_NOT_MODERATOR_NOTICE: return 6;
        case CHAT_PASSWORD_CHANGED_NOTICE: return 7;
        case CHAT_OWNER_CHANGED_NOTICE: return 8;
        case CHAT_PLAYER_NOT_FOUND_NOTICE: return 9;
        case CHAT_NOT_OWNER_NOTICE: return 10;
        case CHAT_CHANNEL_OWNER_NOTICE: return 11;
        case CHAT_MODE_CHANGE_NOTICE: return 12;
        case CHAT_ANNOUNCEMENTS_ON_NOTICE: return 13;
        case CHAT_ANNOUNCEMENTS_OFF_NOTICE: return 14;
        case CHAT_MODERATION_ON_NOTICE: return 15;
        case CHAT_MODERATION_OFF_NOTICE: return 16;
        case CHAT_MUTED_NOTICE: return 17;
        case CHAT_PLAYER_KICKED_NOTICE: return 18;
        case CHAT_BANNED_NOTICE: return 19;
        case CHAT_PLAYER_BANNED_NOTICE: return 20;
        case CHAT_PLAYER_UNBANNED_NOTICE: return 21;
        case CHAT_PLAYER_NOT_BANNED_NOTICE: return 22;
        case CHAT_PLAYER_ALREADY_MEMBER_NOTICE: return 23;
        case CHAT_INVITE_NOTICE: return 24;
        case CHAT_INVITE_WRONG_FACTION_NOTICE: return 25;
        case CHAT_WRONG_FACTION_NOTICE: return 26;
        case CHAT_INVALID_NAME_NOTICE: return 27;
        case CHAT_NOT_MODERATED_NOTICE: return 28;
        case CHAT_PLAYER_INVITED_NOTICE: return 29;
        case CHAT_PLAYER_INVITE_BANNED_NOTICE: return 30;
        case CHAT_THROTTLED_NOTICE: return 31;
        case CHAT_NOT_IN_AREA_NOTICE: return 32;
        case CHAT_NOT_IN_LFG_NOTICE: return 33;
        case CHAT_VOICE_ON_NOTICE: return 34;
        case CHAT_VOICE_OFF_NOTICE: return 35;
        default: throw std::out_of_range("value");
    }
}
}
