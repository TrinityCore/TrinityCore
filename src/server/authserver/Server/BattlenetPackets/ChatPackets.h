/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef ChatPackets_h__
#define ChatPackets_h__

#include "BattlenetPacketsBase.h"

namespace Battlenet
{
    namespace Chat
    {
        enum Opcode
        {
            CMSG_JOIN_REQUEST_2                 = 0x00, // Not implemented
            CMSG_LEAVE_REQUEST                  = 0x02, // Not implemented
            CMSG_INVITE_REQUEST                 = 0x03, // Not implemented
            CMSG_CREATE_AND_INVITE_REQUEST      = 0x0A, // Not implemented
            CMSG_MESSAGE_SEND                   = 0x0B, // Not implemented
            CMSG_DATAGRAM_CONNECTION_UPDATE     = 0x0D, // Not implemented
            CMSG_REPORT_SPAM_REQUEST            = 0x0E, // Not implemented
            CMSG_WHISPER_SEND                   = 0x13, // Not implemented
            CMSG_ENUM_CATEGORY_DESCRIPTIONS     = 0x15, // Not implemented
            CMSG_ENUM_CONFERENCE_DESCRIPTIONS   = 0x17, // Not implemented
            CMSG_ENUM_CONFERENCE_MEMBER_COUNTS  = 0x19, // Not implemented
            CMSG_MODIFY_CHANNEL_LIST_REQUEST    = 0x1B, // Not implemented

            SMSG_MEMBERSHIP_CHANGE_NOTIFY       = 0x01, // Not implemented
            SMSG_INVITE_NOTIFY                  = 0x04, // Not implemented
            SMSG_INVITE_CANCELED                = 0x07, // Not implemented
            SMSG_MESSAGE_RECV                   = 0x0B, // Not implemented
            SMSG_MESSAGE_UNDELIVERABLE          = 0x0C, // Not implemented
            SMSG_DATAGRAM_CONNECTION_UPDATE     = 0x0D, // Not implemented
            SMSG_INVITE_FAILURE                 = 0x0F, // Not implemented
            SMSG_SYSTEM_MESSAGE                 = 0x10, // Not implemented
            SMSG_MESSAGE_BLOCKED                = 0x12, // Not implemented
            SMSG_WHISPER_RECV                   = 0x13, // Not implemented
            SMSG_WHISPER_UNDELIVERABLE          = 0x14, // Not implemented
            SMSG_CATEGORY_DESCRIPTIONS          = 0x16, // Not implemented
            SMSG_CONFERENCE_DESCRIPTIONS        = 0x18, // Not implemented
            SMSG_CONFERENCE_MEMBER_COUNTS       = 0x1A, // Not implemented
            SMSG_JOIN_NOTIFY_2                  = 0x1B, // Not implemented
            SMSG_MODIFY_CHANNEL_LIST_RESPONSE   = 0x1C, // Not implemented
            SMSG_CONFIG_CHANGED                 = 0x1D  // Not implemented
        };
    }
}

#endif // ChatPackets_h__
