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
#include "LFGPackets.h"
#include <G3D/Vector3.h>

namespace WorldPackets
{
    namespace Ticket
    {
        struct SupportTicketHeader
        {
            int32 MapID = 0;
            G3D::Vector3 Position;
            float Facing = 0.0f;
        };

        class GMTicketGetSystemStatus final : public ClientPacket
        {
        public:
            GMTicketGetSystemStatus(WorldPacket&& packet) : ClientPacket(CMSG_GM_TICKET_GET_SYSTEM_STATUS, std::move(packet)) { }

            void Read() override { }
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

            void Read() override { }
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
            };

            GMTicketCaseStatus() : ServerPacket(SMSG_GM_TICKET_CASE_STATUS, 12) { }

            WorldPacket const* Write() override;

            time_t OldestTicketTime = 0;
            time_t UpdateTime = 0;
            std::vector<GMTicketCase> Cases;
        };        

        class GMTicketAcknowledgeSurvey final : public ClientPacket
        {
        public:
            GMTicketAcknowledgeSurvey(WorldPacket&& packet) : ClientPacket(CMSG_GM_TICKET_ACKNOWLEDGE_SURVEY, std::move(packet)) { }

            void Read() override;

            int32 CaseID;
        };

        class SupportTicketSubmitBug final : public ClientPacket
        {
        public:
            SupportTicketSubmitBug(WorldPacket&& packet) : ClientPacket(CMSG_SUPPORT_TICKET_SUBMIT_BUG, std::move(packet)) { }

            void Read() override;

            SupportTicketHeader Header;
            std::string Note;
        };

        class SupportTicketSubmitSuggestion final : public ClientPacket
        {
        public:
            SupportTicketSubmitSuggestion(WorldPacket&& packet) : ClientPacket(CMSG_SUPPORT_TICKET_SUBMIT_SUGGESTION, std::move(packet)) { }

            void Read() override;

            SupportTicketHeader Header;
            std::string Note;
        };

        class SupportTicketSubmitComplaint final : public ClientPacket
        {
        public:
            struct SupportTicketChatLine
            {
                SupportTicketChatLine(ByteBuffer& data);
                SupportTicketChatLine(uint32 timestamp, std::string const& text);

                uint32 Timestamp = 0;
                std::string Text;
            };

            struct SupportTicketChatLog
            {
                std::vector<SupportTicketChatLine> Lines;
                Optional<uint32> ReportLineIndex;
            };

            struct SupportTicketMailInfo
            {
                int32 MailID = 0;
                std::string MailSubject;
                std::string MailBody;
            };

            struct SupportTicketCalendarEventInfo
            {
                ObjectGuid EventID;
                ObjectGuid InviteID;
                std::string EventTitle;
            };

            struct SupportTicketPetInfo
            {
                ObjectGuid PetID;
                std::string PetName;
            };

            struct SupportTicketGuildInfo
            {
                ObjectGuid GuildID;
                std::string GuildName;
            };

            struct Struct5E4383
            {
                WorldPackets::LFG::RideTicket RideTicket;
                ObjectGuid _40;
                ObjectGuid _56;
                ObjectGuid _72;
                std::string _88;
                std::string _217;
                std::string _1242;
            };

            struct Struct5E3DFB
            {
                WorldPackets::LFG::RideTicket RideTicket;
                std::string _32;
            };

            SupportTicketSubmitComplaint(WorldPacket&& packet) : ClientPacket(CMSG_SUPPORT_TICKET_SUBMIT_COMPLAINT, std::move(packet)) { }

            void Read() override;

            SupportTicketHeader Header;
            SupportTicketChatLog ChatLog;
            ObjectGuid TargetCharacterGUID;
            uint8 ComplaintType = 0;
            std::string Note;
            Optional<SupportTicketMailInfo> MailInfo;
            Optional<SupportTicketCalendarEventInfo> CalenderInfo;
            Optional<SupportTicketPetInfo> PetInfo;
            Optional<SupportTicketGuildInfo> GuildInfo;
            Optional<Struct5E4383> _5E4383;
            Optional<Struct5E3DFB> _5E3DFB;

        };

        class ComplaintResult final : public ServerPacket
        {
        public:
            ComplaintResult() : ServerPacket(SMSG_COMPLAINT_RESULT, 9) { }

            WorldPacket const* Write() override;

            uint32 ComplaintType = 0;
            uint8 Result = 0;
        };

        class BugReport final : public ClientPacket
        {
        public:
            BugReport(WorldPacket&& packet) : ClientPacket(CMSG_BUG_REPORT, std::move(packet)) { }

            void Read() override;

            uint32 Type = 0;
            std::string Text;
            std::string DiagInfo;
        };
    }
}

#endif // TicketPackets_h__
