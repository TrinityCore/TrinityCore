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
                Timestamp<> CaseOpened;
                int32 CaseStatus = 0;
                uint16 CfgRealmID = 0;
                uint64 CharacterID = 0;
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

            int32 CaseID = 0;
        };

        class SubmitUserFeedback final : public ClientPacket
        {
        public:
            SubmitUserFeedback(WorldPacket&& packet) : ClientPacket(CMSG_SUBMIT_USER_FEEDBACK, std::move(packet)) { }

            void Read() override;

            SupportTicketHeader Header;
            std::string Note;
            bool IsSuggestion = false;
        };

        struct SupportTicketChatLine
        {
            SupportTicketChatLine(ByteBuffer& data);
            SupportTicketChatLine(time_t timestamp, std::string const& text);

            WorldPackets::Timestamp<> Timestamp;
            std::string Text;
        };

        struct SupportTicketChatLog
        {
            std::vector<SupportTicketChatLine> Lines;
            Optional<uint32> ReportLineIndex;
        };

        struct SupportTicketHorusChatLine
        {
            SupportTicketHorusChatLine(ByteBuffer& data);

            struct SenderRealm
            {
                uint32 VirtualRealmAddress;
                uint16 field_4;
                uint8 field_6;
            };

            WorldPackets::Timestamp<> Timestamp;
            ObjectGuid AuthorGUID;
            Optional<uint64> ClubID;
            Optional<ObjectGuid> ChannelGUID;
            Optional<SenderRealm> RealmAddress;
            Optional<int32> SlashCmd;
            std::string Text;
        };

        struct SupportTicketHorusChatLog
        {
            std::vector<SupportTicketHorusChatLine> Lines;
        };

        struct SupportTicketMailInfo
        {
            int32 MailID = 0;
            std::string MailSubject;
            std::string MailBody;
        };

        struct SupportTicketCalendarEventInfo
        {
            uint64 EventID = 0;
            uint64 InviteID = 0;
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

        struct SupportTicketCommunityMessage
        {
            bool IsPlayerUsingVoice = false;
        };

        struct SupportTicketClubFinderResult
        {
            uint64 ClubFinderPostingID = 0;
            uint64 ClubID = 0;
            ObjectGuid ClubFinderGUID;
            std::string ClubName;
        };

        struct SupportTicketUnused910
        {
            std::string field_0;
            ObjectGuid field_104;
        };

        class SupportTicketSubmitComplaint final : public ClientPacket
        {
        public:
            SupportTicketSubmitComplaint(WorldPacket&& packet) : ClientPacket(CMSG_SUPPORT_TICKET_SUBMIT_COMPLAINT, std::move(packet)) { }

            void Read() override;

            SupportTicketHeader Header;
            SupportTicketChatLog ChatLog;
            ObjectGuid TargetCharacterGUID;
            uint8 ComplaintType = 0;
            SupportTicketHorusChatLog HorusChatLog;
            std::string Note;
            Optional<SupportTicketMailInfo> MailInfo;
            Optional<SupportTicketCalendarEventInfo> CalenderInfo;
            Optional<SupportTicketPetInfo> PetInfo;
            Optional<SupportTicketGuildInfo> GuildInfo;
            Optional<SupportTicketLFGListSearchResult> LFGListSearchResult;
            Optional<SupportTicketLFGListApplicant> LFGListApplicant;
            Optional<SupportTicketCommunityMessage> CommunityMessage;
            Optional<SupportTicketClubFinderResult> ClubFinderResult;
            Optional<SupportTicketUnused910> Unused910;
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
