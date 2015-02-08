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

        class GMTicketCreate final : public ClientPacket
        {
        public:
            struct ChatHistoryData
            {
                uint8 TextCount = 0;
                std::vector<uint32> Sent;
                uint32 DecompressedSize = 0;
                ByteBuffer Data;
            };

            GMTicketCreate(WorldPacket&& packet) : ClientPacket(CMSG_GM_TICKET_CREATE, std::move(packet)) { }

            void Read() override;

            int32 Map = 0;
            G3D::Vector3 Pos;
            uint8 Flags = 0;
            std::string Description;
            bool NeedMoreHelp = false;
            bool NeedResponse = false;
            uint32 DataLength = 0;
            ChatHistoryData ChatHistoryData; ///< Compressed Data
        };

        class GMTicketUpdateText final : public ClientPacket
        {
        public:
            GMTicketUpdateText(WorldPacket&& packet) : ClientPacket(CMSG_GM_TICKET_UPDATE_TEXT, std::move(packet)) { }

            void Read() override;

            std::string Description;
        };

        class GMTicketUpdate final : public ServerPacket
        {
        public:
            GMTicketUpdate() : ServerPacket(SMSG_GM_TICKET_UPDATE, 1) { }

            WorldPacket const* Write() override;

            uint8 Result = 0;
        };

        class GMTicketStatusUpdate final : public ServerPacket
        {
        public:
            GMTicketStatusUpdate() : ServerPacket(SMSG_GM_TICKET_STATUS_UPDATE, 4) { }

            WorldPacket const* Write() override;

            int32 StatusInt = 0;
        };

        class GMTicketDelete final : public ClientPacket
        {
        public:
            GMTicketDelete(WorldPacket&& packet) : ClientPacket(CMSG_GM_TICKET_DELETE_TICKET, std::move(packet)) { }

            void Read() override { }
        };

        class GMTicketResponse final : public ServerPacket
        {
        public:
            GMTicketResponse() : ServerPacket(SMSG_GM_TICKET_RESPONSE, 12) { }

            WorldPacket const* Write() override;

            uint32 TicketID = 0;
            uint32 ResponseID = 0;
            std::string Description;
            std::string ResponseText;
        };

        class GMTicketResponseResolve final : public ClientPacket
        {
        public:
            GMTicketResponseResolve(WorldPacket&& packet) : ClientPacket(CMSG_GM_TICKET_RESPONSE_RESOLVE, std::move(packet)) { }

            void Read() override { }
        };

        class GMTicketResolveResponse final : public ServerPacket
        {
        public:
            GMTicketResolveResponse() : ServerPacket(SMSG_GM_TICKET_RESOLVE_RESPONSE, 1) { }

            WorldPacket const* Write() override;

            bool ShowSurvey = false;
        };

        class GMSurveySubmit final : public ClientPacket
        {
        public:
            struct GMSurveyQuestion
            {
                int32 QuestionID = 0;
                uint8 Answer = 0;
                std::string AnswerComment;
            };

            GMSurveySubmit(WorldPacket&& packet) : ClientPacket(CMSG_GM_SURVEY_SUBMIT, std::move(packet)) { }

            void Read() override;

            int32 SurveyID = 0;
            std::vector<GMSurveyQuestion> SurveyQuestion;
            std::string Comment;

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
    }
}

#endif // TicketPackets_h__
