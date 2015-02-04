/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

namespace WorldPackets
{
    namespace Ticket
    {
        class GMTicketGetSystemStatus final : public ClientPacket
        {
        public:
            GMTicketGetSystemStatus(WorldPacket&& packet) : ClientPacket(CMSG_GM_TICKET_GET_SYSTEM_STATUS, std::move(packet)) { }

            void Read() override { };
        };

        class GMTicketSystemStatus final : public ServerPacket
        {
        public:
            GMTicketSystemStatus() : ServerPacket(SMSG_GM_TICKET_SYSTEM_STATUS, 4) { }

            WorldPacket const* Write() override;

            int32 Status = 0;
        };

        class GMTicketGetCaseStatus final : public ClientPacket
        {
        public:
            GMTicketGetCaseStatus(WorldPacket&& packet) : ClientPacket(CMSG_GM_TICKET_GET_CASE_STATUS, std::move(packet)) { }

            void Read() override { };
        };

        class GMTicketCaseStatus final : public ServerPacket
        {
        public:
            struct GMTicketCase
            {
                int32 CaseID = 0;
                int32 CaseOpened = 0;
                int32 CaseStatus = 0;
                int16 CfgRealmID = 0;
                int64 CharacterID = 0;
                int32 WaitTimeOverrideMinutes = 0;
                std::string Url;
                std::string WaitTimeOverrideMessage;

                bool operator<(GMTicketCase const& right) const
                {
                    return CaseID < right.CaseID;
                }
            };

            GMTicketCaseStatus() : ServerPacket(SMSG_GM_TICKET_CASE_STATUS, 12) { }

            WorldPacket const* Write() override;

            time_t OldestTicketTime = 0;
            time_t UpdateTime = 0;
            std::set<GMTicketCase> Cases;
        };

        class GMTicketGetTicket final : public ClientPacket
        {
        public:
            GMTicketGetTicket(WorldPacket&& packet) : ClientPacket(CMSG_GM_TICKET_GET_TICKET, std::move(packet)) { }

            void Read() override { }
        };

        class GMTicketGetTicketResponse final : public ServerPacket
        {
        public:
            struct GMTicketInfo
            {
                int32 TicketID = 0;
                std::string TicketDescription;
                uint8 Category = 0;
                time_t TicketOpenTime = 0;
                time_t OldestTicketTime = 0;
                time_t UpdateTime = 0;
                uint8 AssignedToGM = 0;
                uint8 OpenedByGM = 0;
                std::string WaitTimeOverrideMessage;
                int32 WaitTimeOverrideMinutes = 0;
            };

            GMTicketGetTicketResponse() : ServerPacket(SMSG_GM_TICKET_GET_TICKET_RESPONSE, 5) { }

            WorldPacket const* Write() override;

            int32 Result = 0;
            Optional<GMTicketInfo> Info;
        };

        class GMTicketAcknowledgeSurvey final : public ClientPacket
        {
        public:
            GMTicketAcknowledgeSurvey(WorldPacket&& packet) : ClientPacket(CMSG_GM_TICKET_ACKNOWLEDGE_SURVEY, std::move(packet)) { }

            void Read() override;

            int32 CaseID;
        };

        class GMTicketResponseError final : public ServerPacket
        {
        public:
            GMTicketResponseError() : ServerPacket(SMSG_GM_TICKET_RESPONSE_ERROR, 0) { }

            WorldPacket const* Write() { return &_worldPacket; }
        };
    }
}

#endif // TicketPackets_h__
