/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "LFGPacketsCommon.h"
#include "Optional.h"
#include "Position.h"

namespace WorldPackets
{
    namespace Ticket
    {
        struct SupportTicketHeader
        {
            int32 MapID = 0;
            TaggedPosition<::Position::XYZ> Position;
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
                uint64 EventID;
                uint64 InviteID;
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

            struct SupportTicketLFGListSearchResult
            {
                WorldPackets::LFG::RideTicket RideTicket;
                uint32 GroupFinderActivityID = 0;
                ObjectGuid LastTitleAuthorGuid;
                ObjectGuid LastDescriptionAuthorGuid;
                ObjectGuid LastVoiceChatAuthorGuid;
                ObjectGuid ListingCreatorGuid;
                ObjectGuid Unknown735;
                std::string Title;
                std::string Description;
                std::string VoiceChat;
            };

            struct SupportTicketLFGListApplicant
            {
                WorldPackets::LFG::RideTicket RideTicket;
                std::string Comment;
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
            Optional<SupportTicketLFGListSearchResult> LFGListSearchResult;
            Optional<SupportTicketLFGListApplicant> LFGListApplicant;

        };

        class Complaint final : public ClientPacket
        {
        public:
            struct ComplaintOffender
            {
                ObjectGuid PlayerGuid;
                uint32 RealmAddress = 0;
                uint32 TimeSinceOffence = 0;
            };

            struct ComplaintChat
            {
                uint32 Command = 0;
                uint32 ChannelID = 0;
                std::string MessageLog;
            };

            Complaint(WorldPacket&& packet) : ClientPacket(CMSG_COMPLAINT, std::move(packet)) { }

            void Read() override;

            uint8 ComplaintType = 0;
            ComplaintOffender Offender;
            uint32 MailID = 0;
            ComplaintChat Chat;
            uint64 EventGuid = 0;
            uint64 InviteGuid = 0;
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
