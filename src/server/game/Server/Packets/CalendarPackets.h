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

#ifndef CalendarPackets_h__
#define CalendarPackets_h__

#include "Packet.h"
#include "CalendarMgr.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "PacketUtilities.h"
#include "WowTime.h"

namespace WorldPackets
{
    namespace Calendar
    {
        class CalendarGetCalendar final : public ClientPacket
        {
        public:
            CalendarGetCalendar(WorldPacket&& packet) : ClientPacket(CMSG_CALENDAR_GET, std::move(packet)) { }

            void Read() override { }
        };

        class CalendarGetEvent final : public ClientPacket
        {
        public:
            CalendarGetEvent(WorldPacket&& packet) : ClientPacket(CMSG_CALENDAR_GET_EVENT, std::move(packet)) { }

            void Read() override;

            uint64 EventID = 0;
        };

        class CalendarCommunityInviteRequest final : public ClientPacket
        {
        public:
            CalendarCommunityInviteRequest(WorldPacket&& packet) : ClientPacket(CMSG_CALENDAR_COMMUNITY_INVITE, std::move(packet)) { }

            void Read() override;

            uint64 ClubID = 0;
            uint8 MinLevel = 1;
            uint8 MaxLevel = 100;
            uint8 MaxRankOrder = 0;
        };

        struct CalendarAddEventInviteInfo
        {
            ObjectGuid Guid;
            uint8 Status = 0;
            uint8 Moderator = 0;
            Optional<ObjectGuid> Unused_801_1;
            Optional<uint64> Unused_801_2;
            Optional<uint64> Unused_801_3;
        };

        struct CalendarAddEventInfo
        {
            uint64 ClubID = 0;
            std::string Title;
            std::string Description;
            uint8 EventType = 0;
            int32 TextureID = 0;
            WowTime Time;
            uint32 Flags = 0;
            Array<CalendarAddEventInviteInfo, CALENDAR_MAX_INVITES> Invites;
        };

        class CalendarAddEvent final : public ClientPacket
        {
        public:
            CalendarAddEvent(WorldPacket&& packet) : ClientPacket(CMSG_CALENDAR_ADD_EVENT, std::move(packet)) { }

            void Read() override;

            uint32 MaxSize = 100;
            CalendarAddEventInfo EventInfo;
        };

        struct CalendarUpdateEventInfo
        {
            uint64 ClubID = 0;
            uint64 EventID = 0;
            uint64 ModeratorID = 0;
            std::string Title;
            std::string Description;
            uint8 EventType = 0;
            uint32 TextureID = 0;
            WowTime Time;
            uint32 Flags = 0;
        };

        class CalendarUpdateEvent final : public ClientPacket
        {
        public:
            CalendarUpdateEvent(WorldPacket&& packet) : ClientPacket(CMSG_CALENDAR_UPDATE_EVENT, std::move(packet)) { }

            void Read() override;

            uint32 MaxSize = 0;
            CalendarUpdateEventInfo EventInfo;
        };

        class CalendarRemoveEvent final : public ClientPacket
        {
        public:
            CalendarRemoveEvent(WorldPacket&& packet) : ClientPacket(CMSG_CALENDAR_REMOVE_EVENT, std::move(packet)) { }

            void Read() override;

            uint64 ModeratorID = 0;
            uint64 EventID = 0;
            uint64 ClubID = 0;
            uint32 Flags = 0;
        };

        class CalendarCopyEvent final : public ClientPacket
        {
        public:
            CalendarCopyEvent(WorldPacket&& packet) : ClientPacket(CMSG_CALENDAR_COPY_EVENT, std::move(packet)) { }

            void Read() override;

            uint64 ModeratorID = 0;
            uint64 EventID = 0;
            uint64 EventClubID = 0;
            WowTime Date;
        };

        class CalendarInviteAdded final : public ServerPacket
        {
        public:
            CalendarInviteAdded() : ServerPacket(SMSG_CALENDAR_INVITE_ADDED, 43) { }

            WorldPacket const* Write() override;

            uint64 InviteID = 0;
            WowTime ResponseTime;
            uint8 Level = 100;
            ObjectGuid InviteGuid;
            uint64 EventID = 0;
            uint8 Type = 0;
            bool ClearPending = false;
            uint8 Status = 0;
        };

        struct CalendarSendCalendarInviteInfo
        {
            uint64 EventID = 0;
            uint64 InviteID = 0;
            ObjectGuid InviterGuid;
            uint8 Status = 0;
            uint8 Moderator = 0;
            uint8 InviteType = 0;
            bool IgnoreFriendAndGuildRestriction = false;
        };

        struct CalendarSendCalendarRaidLockoutInfo
        {
            uint64 InstanceID = 0;
            int32 MapID = 0;
            uint32 DifficultyID = 0;
            int32 ExpireTime = 0;
        };

        struct CalendarSendCalendarEventInfo
        {
            uint64 EventID = 0;
            std::string EventName;
            uint8 EventType = 0;
            WowTime Date;
            uint32 Flags = 0;
            int32 TextureID = 0;
            uint64 EventClubID = 0;
            ObjectGuid OwnerGuid;
        };

        class CalendarSendCalendar final : public ServerPacket
        {
        public:
            CalendarSendCalendar() : ServerPacket(SMSG_CALENDAR_SEND_CALENDAR, 338) { }

            WorldPacket const* Write() override;

            WowTime ServerTime;
            std::vector<CalendarSendCalendarInviteInfo> Invites;
            std::vector<CalendarSendCalendarRaidLockoutInfo> RaidLockouts;
            std::vector<CalendarSendCalendarEventInfo> Events;
        };

        struct CalendarEventInviteInfo
        {
            ObjectGuid Guid;
            uint64 InviteID = 0;
            WowTime ResponseTime;
            uint8 Level = 1;
            uint8 Status = 0;
            uint8 Moderator = 0;
            uint8 InviteType = 0;
            std::string Notes;
        };

        class CalendarSendEvent final : public ServerPacket
        {
        public:
            CalendarSendEvent() : ServerPacket(SMSG_CALENDAR_SEND_EVENT, 93) { }

            WorldPacket const* Write() override;

            ObjectGuid OwnerGuid;
            uint64 EventClubID = 0;
            uint64 EventID = 0;
            WowTime Date;
            WowTime LockDate;
            uint32 Flags = 0;
            int32 TextureID = 0;
            uint8 GetEventType = 0;
            uint8 EventType = 0;
            std::string Description;
            std::string EventName;
            std::vector<CalendarEventInviteInfo> Invites;
        };

        class CalendarInviteAlert final : public ServerPacket
        {
        public:
            CalendarInviteAlert() : ServerPacket(SMSG_CALENDAR_INVITE_ALERT, 80) { }

            WorldPacket const* Write() override;

            ObjectGuid OwnerGuid;
            uint64 EventClubID = 0;
            ObjectGuid InvitedByGuid;
            uint64 InviteID = 0;
            uint64 EventID = 0;
            uint32 Flags = 0;
            WowTime Date;
            int32 TextureID = 0;
            uint8 Status = 0;
            uint8 EventType = 0;
            uint8 ModeratorStatus = 0;
            std::string EventName;
        };

        class CalendarInvite final : public ClientPacket
        {
        public:
            CalendarInvite(WorldPacket&& packet) : ClientPacket(CMSG_CALENDAR_INVITE, std::move(packet)) { }

            void Read() override;

            uint64 ModeratorID = 0;
            bool IsSignUp = false;
            bool Creating = true;
            uint64 EventID = 0;
            uint64 ClubID = 0;
            std::string Name;
        };

        class CalendarRSVP final : public ClientPacket
        {
        public:
            CalendarRSVP(WorldPacket&& packet) : ClientPacket(CMSG_CALENDAR_RSVP, std::move(packet)) { }

            void Read() override;

            uint64 InviteID = 0;
            uint64 EventID = 0;
            uint8 Status = 0;
        };

        class CalendarInviteStatus final : public ServerPacket
        {
        public:
            CalendarInviteStatus() : ServerPacket(SMSG_CALENDAR_INVITE_STATUS, 41) { }

            WorldPacket const* Write() override;

            uint32 Flags = 0;
            uint64 EventID = 0;
            uint8 Status = 0;
            bool ClearPending = false;
            WowTime ResponseTime;
            WowTime Date;
            ObjectGuid InviteGuid;
        };

        class CalendarInviteRemoved final : public ServerPacket
        {
        public:
            CalendarInviteRemoved() : ServerPacket(SMSG_CALENDAR_INVITE_REMOVED, 29) { }

            WorldPacket const* Write() override;

            ObjectGuid InviteGuid;
            uint64 EventID = 0;
            uint32 Flags = 0;
            bool ClearPending = false;
        };

        class CalendarModeratorStatus final : public ServerPacket
        {
        public:
            CalendarModeratorStatus() : ServerPacket(SMSG_CALENDAR_MODERATOR_STATUS, 26) { }

            WorldPacket const* Write() override;

            ObjectGuid InviteGuid;
            uint64 EventID = 0;
            uint8 Status = 0;
            bool ClearPending = false;
        };

        class CalendarInviteRemovedAlert final : public ServerPacket
        {
        public:
            CalendarInviteRemovedAlert() : ServerPacket(SMSG_CALENDAR_INVITE_REMOVED_ALERT, 17) { }

            WorldPacket const* Write() override;

            uint64 EventID = 0;
            WowTime Date;
            uint32 Flags = 0;
            uint8 Status = 0;
        };

        class CalendarClearPendingAction final : public ServerPacket
        {
        public:
            CalendarClearPendingAction() : ServerPacket(SMSG_CALENDAR_CLEAR_PENDING_ACTION, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        class CalendarEventUpdatedAlert final : public ServerPacket
        {
        public:
            CalendarEventUpdatedAlert() : ServerPacket(SMSG_CALENDAR_EVENT_UPDATED_ALERT, 32) { }

            WorldPacket const* Write() override;

            uint64 EventClubID = 0;
            uint64 EventID = 0;
            WowTime Date;
            uint32 Flags = 0;
            WowTime LockDate;
            WowTime OriginalDate;
            int32 TextureID = 0;
            uint8 EventType = 0;
            bool ClearPending = false;
            std::string Description;
            std::string EventName;
        };

        class CalendarEventRemovedAlert final : public ServerPacket
        {
        public:
            CalendarEventRemovedAlert() : ServerPacket(SMSG_CALENDAR_EVENT_REMOVED_ALERT, 13) { }

            WorldPacket const* Write() override;

            uint64 EventID = 0;
            WowTime Date;
            bool ClearPending = false;
        };

        class CalendarSendNumPending final : public ServerPacket
        {
        public:
            CalendarSendNumPending() : ServerPacket(SMSG_CALENDAR_SEND_NUM_PENDING, 4) { }
            CalendarSendNumPending(uint32 numPending) : ServerPacket(SMSG_CALENDAR_SEND_NUM_PENDING, 4), NumPending(numPending) { }

            WorldPacket const* Write() override;

            uint32 NumPending = 0;
        };

        class CalendarGetNumPending final : public ClientPacket
        {
        public:
            CalendarGetNumPending(WorldPacket&& packet) : ClientPacket(CMSG_CALENDAR_GET_NUM_PENDING, std::move(packet)) { }

            void Read() override { }
        };

        class CalendarEventSignUp final : public ClientPacket
        {
        public:
            CalendarEventSignUp(WorldPacket&& packet) : ClientPacket(CMSG_CALENDAR_EVENT_SIGN_UP, std::move(packet)) { }

            void Read() override;

            bool Tentative = false;
            uint64 EventID = 0;
            uint64 ClubID = 0;
        };

        class CalendarRemoveInvite final : public ClientPacket
        {
        public:
            CalendarRemoveInvite(WorldPacket&& packet) : ClientPacket(CMSG_CALENDAR_REMOVE_INVITE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid;
            uint64 EventID = 0;
            uint64 ModeratorID = 0;
            uint64 InviteID = 0;
        };

        class CalendarStatus final : public ClientPacket
        {
        public:
            CalendarStatus(WorldPacket&& packet) : ClientPacket(CMSG_CALENDAR_STATUS, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid;
            uint64 EventID = 0;
            uint64 ModeratorID = 0;
            uint64 InviteID = 0;
            uint8 Status = 0;
        };

        class SetSavedInstanceExtend final : public ClientPacket
        {
        public:
            SetSavedInstanceExtend(WorldPacket&& packet) : ClientPacket(CMSG_SET_SAVED_INSTANCE_EXTEND, std::move(packet)) { }

            void Read() override;

            int32 MapID = 0;
            bool Extend = false;
            uint32 DifficultyID = 0;
        };

        class CalendarModeratorStatusQuery final : public ClientPacket
        {
        public:
            CalendarModeratorStatusQuery(WorldPacket&& packet) : ClientPacket(CMSG_CALENDAR_MODERATOR_STATUS, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid;
            uint64 EventID = 0;
            uint64 InviteID = 0;
            uint64 ModeratorID = 0;
            uint8 Status = 0;
        };

        class CalendarCommandResult final : public ServerPacket
        {
        public:
            CalendarCommandResult() : ServerPacket(SMSG_CALENDAR_COMMAND_RESULT, 3) { }
            CalendarCommandResult(uint8 command, uint8 result, std::string const& name) : ServerPacket(SMSG_CALENDAR_COMMAND_RESULT, 3), Command(command), Result(result), Name(name) { }

            WorldPacket const* Write() override;

            uint8 Command = 0;
            uint8 Result = 0;
            std::string Name;
        };

        class CalendarRaidLockoutAdded final : public ServerPacket
        {
        public:
            CalendarRaidLockoutAdded() : ServerPacket(SMSG_CALENDAR_RAID_LOCKOUT_ADDED, 8 + 4 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            uint64 InstanceID = 0;
            uint32 DifficultyID = 0;
            int32 TimeRemaining = 0;
            WowTime ServerTime;
            int32 MapID = 0;
        };

        class CalendarRaidLockoutRemoved final : public ServerPacket
        {
        public:
            CalendarRaidLockoutRemoved() : ServerPacket(SMSG_CALENDAR_RAID_LOCKOUT_REMOVED, 8 + 4 + 4) { }

            WorldPacket const* Write() override;

            uint64 InstanceID = 0;
            int32 MapID = 0;
            uint32 DifficultyID = 0;
        };

        class CalendarRaidLockoutUpdated final : public ServerPacket
        {
        public:
            CalendarRaidLockoutUpdated() : ServerPacket(SMSG_CALENDAR_RAID_LOCKOUT_UPDATED, 20) { }

            WorldPacket const* Write() override;

            WowTime ServerTime;
            int32 MapID = 0;
            uint32 DifficultyID = 0;
            int32 NewTimeRemaining = 0;
            int32 OldTimeRemaining = 0;
        };

        struct CalendarEventInitialInviteInfo
        {
            CalendarEventInitialInviteInfo(ObjectGuid inviteGuid, uint8 level) : InviteGuid(inviteGuid), Level(level) { }

            ObjectGuid InviteGuid;
            uint8 Level = 100;
        };

        class CalendarCommunityInvite final : public ServerPacket
        {
        public:
            CalendarCommunityInvite() : ServerPacket(SMSG_CALENDAR_COMMUNITY_INVITE, 17) { }

            WorldPacket const* Write() override;

            std::vector<CalendarEventInitialInviteInfo> Invites;
        };

        class CalendarInviteStatusAlert final : public ServerPacket
        {
        public:
            CalendarInviteStatusAlert() : ServerPacket(SMSG_CALENDAR_INVITE_STATUS_ALERT, 5) { }

            WorldPacket const* Write() override;

            uint64 EventID = 0;
            uint32 Flags = 0;
            WowTime Date;
            uint8 Status = 0;
        };

        class CalendarInviteNotesAlert final : public ServerPacket
        {
        public:
            CalendarInviteNotesAlert() : ServerPacket(SMSG_CALENDAR_INVITE_NOTES_ALERT, 9) { }
            CalendarInviteNotesAlert(uint64 eventID, std::string const& notes) : ServerPacket(SMSG_CALENDAR_INVITE_NOTES_ALERT, 8 + notes.size()), EventID(eventID), Notes(notes) { }

            WorldPacket const* Write() override;

            uint64 EventID = 0;
            std::string Notes;
        };

        class CalendarInviteNotes final : public ServerPacket
        {
        public:
            CalendarInviteNotes() : ServerPacket(SMSG_CALENDAR_INVITE_NOTES, 26) { }

            WorldPacket const* Write() override;

            ObjectGuid InviteGuid;
            uint64 EventID = 0;
            std::string Notes;
            bool ClearPending = false;
        };

        class CalendarComplain final : public ClientPacket
        {
        public:
            CalendarComplain(WorldPacket&& packet) : ClientPacket(CMSG_CALENDAR_COMPLAIN, std::move(packet)) { }

            void Read() override;

            ObjectGuid InvitedByGUID;
            uint64 InviteID = 0;
            uint64 EventID = 0;
        };
    }
}

#endif // CalendarPackets_h__
