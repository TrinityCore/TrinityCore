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

#ifndef MiscPackets_h__
#define MiscPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "Optional.h"

namespace WorldPackets
{
    namespace Misc
    {
        class SetupCurrency final : public ServerPacket
        {
        public:
            struct Record
            {
                int32 Type = 0;                       // ID from CurrencyTypes.dbc
                int32 Quantity = 0;
                Optional<int32> WeeklyQuantity;       // Currency count obtained this Week.
                Optional<int32> MaxWeeklyQuantity;    // Weekly Currency cap.
                Optional<int32> TrackedQuantity;      // Currency count obtained this season.
                Optional<int32> MaxQuantity;
                uint8 Flags = 0;                      // 0 = none,
            };

            SetupCurrency() : ServerPacket(SMSG_SETUP_CURRENCY, 22) { }

            WorldPacket const* Write() override;

            std::vector<Record> Data;
        };

        class RequestPVPRewardsResponse final : public ServerPacket
        {
        public:
            RequestPVPRewardsResponse() : ServerPacket(SMSG_REQUEST_PVP_REWARDS_RESPONSE, 24) { }

            WorldPacket const* Write() override;

            int32 RatedRewardPointsThisWeek = 0;
            int32 ArenaRewardPointsThisWeek = 0;
            int32 RewardPointsThisWeek = 0;
            int32 RatedMaxRewardPointsThisWeek = 0;
            int32 ArenaMaxRewardPointsThisWeek = 0;
            int32 MaxRewardPointsThisWeek = 0;
        };

        class TriggerCinematic final : public ServerPacket
        {
        public:
            TriggerCinematic() : ServerPacket(SMSG_TRIGGER_CINEMATIC, 4) { }

            WorldPacket const* Write() override;

            uint32 CinematicID = 0;
        };

        class TriggerMovie final : public ServerPacket
        {
        public:
            TriggerMovie() : ServerPacket(SMSG_TRIGGER_MOVIE, 4) { }

            WorldPacket const* Write() override;

            uint32 MovieID = 0;
        };

        class CompleteCinematic final : public ClientPacket
        {
        public:
            CompleteCinematic(WorldPacket&& packet) : ClientPacket(CMSG_COMPLETE_CINEMATIC, std::move(packet)) { }

            void Read() override { }
        };

        class NextCinematicCamera final : public ClientPacket
        {
        public:
            NextCinematicCamera(WorldPacket&& packet) : ClientPacket(CMSG_NEXT_CINEMATIC_CAMERA, std::move(packet)) { }

            void Read() override { }
        };

        class CompleteMovie final : public ClientPacket
        {
        public:
            CompleteMovie(WorldPacket&& packet) : ClientPacket(CMSG_COMPLETE_MOVIE, std::move(packet)) { }

            void Read() override { }
        };

        class OpeningCinematic final : public ClientPacket
        {
        public:
            OpeningCinematic(WorldPacket&& packet) : ClientPacket(CMSG_OPENING_CINEMATIC, std::move(packet)) { }

            void Read() override { }
        };

        class StreamingMovies final : public ServerPacket
        {
        public:
            StreamingMovies() : ServerPacket(SMSG_STREAMING_MOVIES) { }

            WorldPacket const* Write() override;

            std::vector<uint16> MovieIDs;
        };

        struct PhaseShiftData
        {
            uint32 PhaseShiftFlags = 0;
            std::vector<uint16> Phases;
        };

        class PhaseShiftChange final : public ServerPacket
        {
        public:
            PhaseShiftChange() : ServerPacket(SMSG_PHASE_SHIFT_CHANGE, 8 + 4 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid Client;
            PhaseShiftData Phaseshift;
            std::vector<uint16> PreloadMapIDs;
            std::vector<uint16> UiMapPhaseIDs;
            std::vector<uint16> VisibleMapIDs;
        };

        class UITime final : public ServerPacket
        {
        public:
            UITime() : ServerPacket(SMSG_WORLD_STATE_UI_TIMER_UPDATE, 4) { }

            WorldPacket const* Write() override;

            uint32 Time = 0;
        };

        class TC_GAME_API PlaySound final : public ServerPacket
        {
        public:
            PlaySound() : ServerPacket(SMSG_PLAY_SOUND, 4 + 4) { }
            PlaySound(ObjectGuid sourceObjectGuid, uint32 soundKitID) : ServerPacket(SMSG_PLAY_SOUND, 4 + 4), SourceObjectGUID(sourceObjectGuid), SoundKitID(soundKitID) { }

            WorldPacket const* Write() override;

            ObjectGuid SourceObjectGUID;
            uint32 SoundKitID;
        };

        class PlayObjectSound final : public ServerPacket
        {
        public:
            PlayObjectSound() : ServerPacket(SMSG_PLAY_OBJECT_SOUND, 8 + 8 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid SourceObjectGUID;
            ObjectGuid TargetObjectGUID;
            uint32 SoundKitID = 0;
        };
    }
}

#endif // MiscPackets_h__
