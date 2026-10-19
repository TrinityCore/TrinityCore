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

#ifndef TRINITYCORE_TICKET_PACKETS_H
#define TRINITYCORE_TICKET_PACKETS_H

#include "Packet.h"
#include "PacketUtilities.h"
#include "Position.h"
#include <span>

namespace WorldPackets
{
    namespace Ticket
    {
        struct SupportTicketHeader
        {
            int32 MapID = 0;
            TaggedPosition<::Position::XYZ> Position;
        };

        class GMTicketGetSystemStatus final : public ClientPacket
        {
        public:
            explicit GMTicketGetSystemStatus(WorldPacket&& packet) : ClientPacket(CMSG_GMTICKET_SYSTEMSTATUS, std::move(packet)) { }

            void Read() override { }
        };

        class GMTicketSystemStatus final : public ServerPacket
        {
        public:
            explicit GMTicketSystemStatus() : ServerPacket(SMSG_GMTICKET_SYSTEMSTATUS, 4) { }

            WorldPacket const* Write() override;

            int32 Status = 0;
        };

        class GMTicketGetTicket final : public ClientPacket
        {
        public:
            explicit GMTicketGetTicket(WorldPacket&& packet) : ClientPacket(CMSG_GMTICKET_GETTICKET, std::move(packet)) { }

            void Read() override { }
        };

        struct GMTicketInfo
        {
            int32 TicketID = 0;
            std::string_view TicketDescription;
            uint8 Category = 0;
            float TicketOpenTime = 0;
            float OldestTicketTime = 0;
            float UpdateTime = 0;
            uint8 AssignedToGM = 0;
            uint8 OpenedByGM = 0;
        };

        class GMTicketGetTicketResponse final : public ServerPacket
        {
        public:
            explicit GMTicketGetTicketResponse() : ServerPacket(SMSG_GMTICKET_GETTICKET) { }

            WorldPacket const* Write() override;

            int32 Result = 0;
            GMTicketInfo Info;
        };

        class GMTicketCreate final : public ClientPacket
        {
        public:
            explicit GMTicketCreate(WorldPacket&& packet) : ClientPacket(CMSG_GMTICKET_CREATE, std::move(packet)) { }

            void Read() override;

            SupportTicketHeader Header;
            std::string Description;
            uint32 NeedResponse = 0;
            bool NeedMoreHelp = false;
            Array<uint32, 60> ChatTimes;
            uint32 DecompressedSize = 0;
            std::span<uint8> ChatLines; ///< Compressed Data
        };

        class GMTicketCreateResponse final : public ServerPacket
        {
        public:
            explicit GMTicketCreateResponse() : ServerPacket(SMSG_GMTICKET_CREATE, 4) { }

            WorldPacket const* Write() override;

            uint32 Result = 0;
        };

        class GMTicketUpdateText final : public ClientPacket
        {
        public:
            explicit GMTicketUpdateText(WorldPacket&& packet) : ClientPacket(CMSG_GMTICKET_UPDATETEXT, std::move(packet)) { }

            void Read() override;

            std::string Description;
        };

        class GMTicketUpdate final : public ServerPacket
        {
        public:
            explicit GMTicketUpdate() : ServerPacket(SMSG_GMTICKET_UPDATETEXT, 4) { }

            WorldPacket const* Write() override;

            uint32 Result = 0;
        };

        class GMTicketDelete final : public ClientPacket
        {
        public:
            explicit GMTicketDelete(WorldPacket&& packet) : ClientPacket(CMSG_GMTICKET_DELETETICKET, std::move(packet)) { }

            void Read() override { }
        };

        class GMTicketDeleteResponse final : public ServerPacket
        {
        public:
            explicit GMTicketDeleteResponse() : ServerPacket(SMSG_GMTICKET_DELETETICKET, 4) { }

            WorldPacket const* Write() override;

            uint32 Result = 0;
        };

        class GMTicketResponse final : public ServerPacket
        {
        public:
            explicit GMTicketResponse() : ServerPacket(SMSG_GMRESPONSE_RECEIVED, 12) { }

            WorldPacket const* Write() override;

            uint32 ResponseID = 0;
            uint32 TicketID = 0;
            std::string_view Description;
            std::array<std::string_view, 4> ResponseText;
        };

        struct GMSurveyQuestion
        {
            int32 QuestionID = 0;
            uint8 Answer = 0;
            std::string AnswerComment;
        };

        class GMSurveySubmit final : public ClientPacket
        {
        public:
            explicit GMSurveySubmit(WorldPacket&& packet) : ClientPacket(CMSG_GMSURVEY_SUBMIT, std::move(packet)) { }

            void Read() override;

            int32 SurveyID = 0;
            std::vector<GMSurveyQuestion> SurveyQuestion;
            std::string Comment;
        };

        class GMLagReport final : public ClientPacket
        {
        public:
            explicit GMLagReport(WorldPacket&& packet) : ClientPacket(CMSG_GM_REPORT_LAG, std::move(packet)) { }

            void Read() override;

            int32 LagKind = 0;
            SupportTicketHeader Header;
        };

        class GMTicketResponseResolve final : public ClientPacket
        {
        public:
            explicit GMTicketResponseResolve(WorldPacket&& packet) : ClientPacket(CMSG_GMRESPONSE_RESOLVE, std::move(packet)) { }

            void Read() override { }
        };

        class GMTicketResolveResponse final : public ServerPacket
        {
        public:
            explicit GMTicketResolveResponse() : ServerPacket(SMSG_GMRESPONSE_STATUS_UPDATE, 1) { }

            WorldPacket const* Write() override;

            bool ShowSurvey = false;
        };
    }
}

#endif // TRINITYCORE_TICKET_PACKETS_H
