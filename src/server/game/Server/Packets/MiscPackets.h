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

#ifndef MiscPackets_h__
#define MiscPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "WorldSession.h"
#include "G3D/Vector3.h"
#include "Object.h"

namespace WorldPackets
{
    namespace Misc
    {
        class BindPointUpdate final : public ServerPacket
        {
        public:
            BindPointUpdate() : ServerPacket(SMSG_BINDPOINTUPDATE, 20) { }

            WorldPacket const* Write() override;

            uint32 BindMapID = MAPID_INVALID;
            G3D::Vector3 BindPosition;
            uint32 BindAreaID = 0;
        };

        class InvalidatePlayer final : public ServerPacket
        {
        public:
            InvalidatePlayer() : ServerPacket(SMSG_INVALIDATE_PLAYER, 18) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
        };

        class LoginSetTimeSpeed final : public ServerPacket
        {
        public:
            LoginSetTimeSpeed() : ServerPacket(SMSG_LOGIN_SETTIMESPEED, 20) { }

            WorldPacket const* Write() override;

            float NewSpeed = 0.0f;
            int32 ServerTimeHolidayOffset = 0;
            uint32 GameTime = 0;
            uint32 ServerTime = 0;
            int32 GameTimeHolidayOffset = 0;
        };

        class SetCurrency final : public ServerPacket
        {
        public:
            SetCurrency() : ServerPacket(SMSG_SET_CURRENCY, 12) { }

            WorldPacket const* Write() override;

            bool SuppressChatLog = false;
            Optional<int32> TrackedQuantity;
            int32 Quantity = 0;
            uint32 Flags = 0;
            int32 Type = 0;
            Optional<int32> WeeklyQuantity;
        };

        class SetSelection final : public ClientPacket
        {
        public:
            SetSelection(WorldPacket&& packet) : ClientPacket(CMSG_SET_SELECTION, std::move(packet)) { }

            void Read() override;

            ObjectGuid Selection; ///< Target
        };

        class SetupCurrency final : public ServerPacket
        {
        public:
            struct Record
            {
                int32 Type = 0;                       // ID from CurrencyTypes.dbc
                int32 Quantity = 0;
                Optional<int32> WeeklyQuantity;       // Currency count obtained this Week.  
                Optional<int32> MaxWeeklyQuantity;    // Weekly Currency cap.
                Optional<int32> TrackedQuantity;
                uint8 Flags = 0;                      // 0 = none, 
            };

            SetupCurrency() : ServerPacket(SMSG_SETUP_CURRENCY, 22) { }

            WorldPacket const* Write() override;

            std::vector<Record> Data;
        };

        class ViolenceLevel final : public ClientPacket
        {
        public:
            ViolenceLevel(WorldPacket&& packet) : ClientPacket(CMSG_VIOLENCE_LEVEL, std::move(packet)) { }

            void Read() override;

            int8 ViolenceLvl = -1; ///< 0 - no combat effects, 1 - display some combat effects, 2 - blood, 3 - bloody, 4 - bloodier, 5 - bloodiest
        };

        class TimeSyncRequest final : public ServerPacket
        {
        public:
            TimeSyncRequest() : ServerPacket(SMSG_TIME_SYNC_REQ, 4) { }

            WorldPacket const* Write() override;

            uint32 SequenceIndex = 0;
        };

        class TimeSyncResponse final : public ClientPacket
        {
        public:
            TimeSyncResponse(WorldPacket&& packet) : ClientPacket(CMSG_TIME_SYNC_RESP, std::move(packet)) { }

            void Read() override;

            uint32 ClientTime = 0; // Client ticks in ms
            uint32 SequenceIndex = 0; // Same index as in request
        };

        class UITime final : public ServerPacket
        {
        public:
            UITime() : ServerPacket(SMSG_WORLD_STATE_UI_TIMER_UPDATE, 4) { }

            WorldPacket const* Write() override;

            uint32 Time = 0;
        };

        class TutorialFlags : public ServerPacket
        {
        public:
            TutorialFlags() : ServerPacket(SMSG_TUTORIAL_FLAGS, 32)
            {
                std::memset(TutorialData, 0, sizeof(TutorialData));
            }

            WorldPacket const* Write() override;

            uint32 TutorialData[MAX_ACCOUNT_TUTORIAL_VALUES];
        };

        class TutorialSetFlag final : public ClientPacket
        {
        public:
            TutorialSetFlag(WorldPacket&& packet) : ClientPacket(CMSG_TUTORIAL_FLAG, std::move(packet)) { }

            void Read() override;

            uint8 Action = 0;
            uint32 TutorialBit = 0;
        };

        class WorldServerInfo final : public ServerPacket
        {
        public:
            WorldServerInfo() : ServerPacket(SMSG_WORLD_SERVER_INFO, 26) { }

            WorldPacket const* Write() override;

            Optional<uint32> IneligibleForLootMask; ///< Encountermask?
            uint32 WeeklyReset      = 0; ///< UnixTime of last Weekly Reset Time
            Optional<uint32> InstanceGroupSize;
            uint8 IsTournamentRealm = 0;
            Optional<uint32> RestrictedAccountMaxLevel;
            Optional<uint32> RestrictedAccountMaxMoney;
            uint32 DifficultyID     = 0;
        };
    }
}

#endif // MiscPackets_h__
