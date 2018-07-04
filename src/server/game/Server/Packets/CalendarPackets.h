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

#ifndef CalendarPackets_h__
#define CalendarPackets_h__

#include "Packet.h"
#include "CalendarMgr.h"
#include "ObjectGuid.h"
#include "PacketUtilities.h"

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

        class CalendarGuildFilter final : public ClientPacket
        {
        public:
            CalendarGuildFilter(WorldPacket&& packet) : ClientPacket(CMSG_CALENDAR_GUILD_FILTER, std::move(packet)) { }

            void Read() override;

            uint8 MinLevel = 1;
            uint8 MaxLevel = 100;
            uint8 MaxRankOrder = 0;
        };

        struct CalendarAddEventInviteInfo
        {
            ObjectGuid Guid;
            uint8 Status = 0;
            uint8 Moderator = 0;
        };

        struct CalendarAddEventInfo
        {
            std::string Title;
            std::string Description;
            uint8 EventType = 0;
            int32 TextureID = 0;
            time_t Time = time_t(0);
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
            uint64 EventID = 0;
            uint64 ModeratorID = 0;
            std::string Title;
            std::string Description;
            uint8 EventType = 0;
            uint32 TextureID = 0;
            time_t Time = time_t(0);
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
            uint32 Flags = 0;
        };

        class CalendarCopyEvent final : public ClientPacket
        {
        public:
            CalendarCopyEvent(WorldPacket&& packet) : ClientPacket(CMSG_CALENDAR_COPY_EVENT, std::move(packet)) { }

            void Read() override;

            uint64 ModeratorID = 0;
            uint64 EventID = 0;
            time_t Date = time_t(0);
        };

        class SCalendarEventInvite final : public ServerPacket
        {
        public:
            SCalendarEventInvite() : ServerPacket(SMSG_CALENDAR_EVENT_INVITE, 43) { }

            WorldPacket const* Write() override;

            uint64 InviteID = 0;
            time_t ResponseTime = time_t(0);
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
        };

        struct CalendarSendCalendarRaidLockoutInfo
        {
            uint64 InstanceID = 0;
            int32 MapID = 0;
            uint32 DifficultyID = 0;
            time_t ExpireTime = time_t(0);
        };

        struct CalendarSendCalendarEventInfo
        {
            uint64 EventID = 0;
            std::string EventName;
            uint8 EventType = 0;
            time_t Date = time_t(0);
            uint32 Flags = 0;
            int32 TextureID = 0;
            ObjectGuid EventGuildID;
            ObjectGuid OwnerGuid;
        };

        class CalendarSendCalendar final : public ServerPacket
        {
        public:
            CalendarSendCalendar() : ServerPacket(SMSG_CALENDAR_SEND_CALENDAR, 338) { }

            WorldPacket const* Write() override;

            time_t ServerTime = time_t(0);
            std::vector<CalendarSendCalendarInviteInfo> Invites;
            std::vector<CalendarSendCalendarRaidLockoutInfo> RaidLockouts;
            std::vector<CalendarSendCalendarEventInfo> Events;
        };

        struct CalendarEventInviteInfo
        {
            ObjectGuid Guid;
            uint64 InviteID = 0;
            time_t ResponseTime = time_t(0);
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
            ObjectGuid EventGuildID;
            uint64 EventID = 0;
            time_t Date = time_t(0);
            time_t LockDate = time_t(0);
            uint32 Flags = 0;
            int32 TextureID = 0;
            uint8 GetEventType = 0;
            uint8 EventType = 0;
            std::string Description;
            std::string EventName;
            std::vector<CalendarEventInviteInfo> Invites;
        };

        class CalendarEventInviteAlert final : public ServerPacket
        {
        public:
            CalendarEventInviteAlert() : ServerPacket(SMSG_CALENDAR_EVENT_INVITE_ALERT, 80) { }

            WorldPacket const* Write() override;

            ObjectGuid OwnerGuid;
            ObjectGuid EventGuildID;
            ObjectGuid InvitedByGuid;
            uint64 InviteID = 0;
            uint64 EventID = 0;
            uint32 Flags = 0;
            time_t Date = time_t(0);
            int32 TextureID = 0;
            uint8 Status = 0;
            uint8 EventType = 0;
            uint8 ModeratorStatus = 0;
            std::string EventName;
        };

        class CalendarEventInvite final : public ClientPacket
        {
        public:
            CalendarEventInvite(WorldPacket&& packet) : ClientPacket(CMSG_CALENDAR_EVENT_INVITE, std::move(packet)) { }

            void Read() override;

            uint64 ModeratorID = 0;
            bool IsSignUp = false;
            bool Creating = true;
            uint64 EventID = 0;
            std::string Name;
        };

        class CalendarEventRSVP final : public ClientPacket
        {
        public:
            CalendarEventRSVP(WorldPacket&& packet) : ClientPacket(CMSG_CALENDAR_EVENT_RSVP, std::move(packet)) { }

            void Read() override;

            uint64 InviteID = 0;
            uint64 EventID = 0;
            uint8 Status = 0;
        };

        class CalendarEventInviteStatus final : public ServerPacket
        {
        public:
            CalendarEventInviteStatus() : ServerPacket(SMSG_CALENDAR_EVENT_INVITE_STATUS, 41) { }

            WorldPacket const* Write() override;

            uint32 Flags = 0;
            uint64 EventID = 0;
            uint8 Status = 0;
            bool ClearPending = false;
            time_t ResponseTime = time_t(0);
            time_t Date = time_t(0);
            ObjectGuid InviteGuid;
        };

        class CalendarEventInviteRemoved final : public ServerPacket
        {
        public:
            CalendarEventInviteRemoved() : ServerPacket(SMSG_CALENDAR_EVENT_INVITE_REMOVED, 29) { }

            WorldPacket const* Write() override;

            ObjectGuid InviteGuid;
            uint64 EventID = 0;
            uint32 Flags = 0;
            bool ClearPending = false;
        };

        class CalendarEventInviteModeratorStatus final : public ServerPacket
        {
        public:
            CalendarEventInviteModeratorStatus() : ServerPacket(SMSG_CALENDAR_EVENT_INVITE_MODERATOR_STATUS, 26) { }

            WorldPacket const* Write() override;

            ObjectGuid InviteGuid;
            uint64 EventID = 0;
            uint8 Status = 0;
            bool ClearPending = false;
        };

        class CalendarEventInviteRemovedAlert final : public ServerPacket
        {
        public:
            CalendarEventInviteRemovedAlert() : ServerPacket(SMSG_CALENDAR_EVENT_INVITE_REMOVED_ALERT, 17) { }

            WorldPacket const* Write() override;

            uint64 EventID = 0;
            time_t Date = time_t(0);
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

            uint64 EventID = 0;
            time_t Date = time_t(0);
            uint32 Flags = 0;
            time_t LockDate = time_t(0);
            time_t OriginalDate = time_t(0);
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
            time_t Date = time_t(0);
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

        class CalendarEventStatus final : public ClientPacket
        {
        public:
            CalendarEventStatus(WorldPacket&& packet) : ClientPacket(CMSG_CALENDAR_EVENT_STATUS, std::move(packet)) { }

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

        class CalendarEventModeratorStatus final : public ClientPacket
        {
        public:
            CalendarEventModeratorStatus(WorldPacket&& packet) : ClientPacket(CMSG_CALENDAR_EVENT_MODERATOR_STATUS, std::move(packet)) { }

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
            uint32 ServerTime = 0;
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

            int32 MapID = 0;
            int32 OldTimeRemaining = 0;
            time_t ServerTime = 0;
            uint32 DifficultyID = 0;
            int32 NewTimeRemaining = 0;
        };

        struct CalendarEventInitialInviteInfo
        {
            CalendarEventInitialInviteInfo(ObjectGuid inviteGuid, uint8 level) : InviteGuid(inviteGuid), Level(level) { }

            ObjectGuid InviteGuid;
            uint8 Level = 100;
        };

        class CalendarEventInitialInvites final : public ServerPacket
        {
        public:
            CalendarEventInitialInvites() : ServerPacket(SMSG_CALENDAR_EVENT_INITIAL_INVITES, 17) { }

            WorldPacket const* Write() override;

            std::vector<CalendarEventInitialInviteInfo> Invites;
        };

        class CalendarEventInviteStatusAlert final : public ServerPacket
        {
        public:
            CalendarEventInviteStatusAlert() : ServerPacket(SMSG_CALENDAR_EVENT_INVITE_STATUS_ALERT, 5) { }

            WorldPacket const* Write() override;

            uint64 EventID = 0;
            uint32 Flags = 0;
            time_t Date = time_t(0);
            uint8 Status = 0;
        };

        class CalendarEventInviteNotesAlert final : public ServerPacket
        {
        public:
            CalendarEventInviteNotesAlert() : ServerPacket(SMSG_CALENDAR_EVENT_INVITE_NOTES_ALERT, 9) { }
            CalendarEventInviteNotesAlert(uint64 eventID, std::string const& notes) : ServerPacket(SMSG_CALENDAR_EVENT_INVITE_NOTES_ALERT, 8 + notes.size()), EventID(eventID), Notes(notes) { }

            WorldPacket const* Write() override;

            uint64 EventID = 0;
            std::string Notes;
        };

        class CalendarEventInviteNotes final : public ServerPacket
        {
        public:
            CalendarEventInviteNotes() : ServerPacket(SMSG_CALENDAR_EVENT_INVITE_NOTES, 26) { }

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
