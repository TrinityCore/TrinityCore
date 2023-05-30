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

#ifndef TicketPackets_h__
#define TicketPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "Position.h"

namespace WorldPackets
{
    namespace Ticket
    {
        struct ComplaintOffender
        {
            ObjectGuid PlayerGuid;
            uint32 TimeSinceOffence = 0;
        };

        struct ComplaintChat
        {
            uint32 Command = 0;
            uint32 ChannelID = 0;
            uint32 ChatFlags = 0;
            std::string MessageLog;
        };

        class Complaint final : public ClientPacket
        {
        public:
            Complaint(WorldPacket&& packet) : ClientPacket(CMSG_COMPLAINT, std::move(packet)) { }

            void Read() override;

            uint8 ComplaintType = 0;
            uint32 MailID = 0;
            ComplaintOffender Offender;
            ComplaintChat Chat;
        };

        class ComplaintResult final : public ServerPacket
        {
        public:
            ComplaintResult() : ServerPacket(SMSG_COMPLAINT_RESULT, 1 + 1) { }

            WorldPacket const* Write() override;

            uint8 ComplaintType = 0;
            uint8 Result = 0;
        };

        struct SupportTicketHeader
        {
            int32 MapID = 0;
            TaggedPosition<Position::XYZ> _Position;
            float Facing = 0.0f;
        };

        class SupportTicketSubmitSuggestion final : public ClientPacket
        {
        public:
            SupportTicketSubmitSuggestion(WorldPacket&& packet) : ClientPacket(CMSG_SUPPORT_TICKET_SUBMIT_SUGGESTION, std::move(packet)) { }

            void Read() override;

            SupportTicketHeader Header;
            std::string Note;
        };

        class SupportTicketSubmitBug final : public ClientPacket
        {
        public:
            SupportTicketSubmitBug(WorldPacket&& packet) : ClientPacket(CMSG_SUPPORT_TICKET_SUBMIT_BUG, std::move(packet)) { }

            void Read() override;

            SupportTicketHeader Header;
            std::string Note;
        };

        struct SupportTicketChatLine
        {
            int32 Timestamp = 0;
            std::string Text;
        };

        struct SupportTicketChatLog
        {
            std::vector<SupportTicketChatLine> Lines;
            Optional<uint32> ReportLineIndex;
        };

        class SupportTicketSubmitComplaint final : public ClientPacket
        {
        public:
            SupportTicketSubmitComplaint(WorldPacket&& packet) : ClientPacket(CMSG_SUPPORT_TICKET_SUBMIT_COMPLAINT, std::move(packet)) { }

            void Read() override;

            SupportTicketHeader Header;
            SupportTicketChatLog ChatLog;
            ObjectGuid TargetCharacterGUID;
            std::string Note;
            uint8 ComplaintType = 0;
        };
    }
}

#endif // TicketPackets_h__
