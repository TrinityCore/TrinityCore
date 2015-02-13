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

#ifndef MiscPackets_h__
#define MiscPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "WorldSession.h"
#include "G3D/Vector3.h"
#include "Object.h"
#include "Unit.h"
#include "Weather.h"

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

        class PlayerBound final : public ServerPacket
        {
        public:
            PlayerBound() : ServerPacket(SMSG_PLAYER_BOUND, 16 + 4) { }
            PlayerBound(ObjectGuid binderId, uint32 areaId) : ServerPacket(SMSG_PLAYER_BOUND, 16 + 4), BinderID(binderId), AreaID(areaId) { }

            WorldPacket const* Write() override;

            ObjectGuid BinderID;
            uint32 AreaID = 0;
        };

        class BinderConfirm final : public ServerPacket
        {
        public:
            BinderConfirm() : ServerPacket(SMSG_BINDER_CONFIRM, 16) { }
            BinderConfirm(ObjectGuid unit) : ServerPacket(SMSG_BINDER_CONFIRM, 16), Unit(unit) { }

            WorldPacket const* Write() override;

            ObjectGuid Unit;
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
            TimeSyncResponse(WorldPacket&& packet) : ClientPacket(CMSG_TIME_SYNC_RESPONSE, std::move(packet)) { }

            void Read() override;

            uint32 ClientTime = 0; // Client ticks in ms
            uint32 SequenceIndex = 0; // Same index as in request
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

        class UITimeRequest final : public ClientPacket
        {
        public:
            UITimeRequest(WorldPacket&& packet) : ClientPacket(CMSG_UI_TIME_REQUEST, std::move(packet)) { }

            void Read() override { }
        };

        class UITime final : public ServerPacket
        {
        public:
            UITime() : ServerPacket(SMSG_UI_TIME, 4) { }

            WorldPacket const* Write() override;

            uint32 Time = 0; ///< UnixTime
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

        class AreaTrigger final : public ClientPacket
        {
        public:
            AreaTrigger(WorldPacket&& packet) : ClientPacket(CMSG_AREATRIGGER, std::move(packet)) { }

            void Read() override;

            int32 AreaTriggerID = 0;
            bool Entered = false;
            bool FromClient = false;
        };

        class SetDungeonDifficulty final : public ClientPacket
        {
        public:
            SetDungeonDifficulty(WorldPacket&& packet) : ClientPacket(CMSG_SET_DUNGEON_DIFFICULTY, std::move(packet)) { }

            void Read() override;

            int32 DifficultyID = 0;
        };

        class SetRaidDifficulty final : public ClientPacket
        {
        public:
            SetRaidDifficulty(WorldPacket&& packet) : ClientPacket(CMSG_SET_RAID_DIFFICULTY, std::move(packet)) { }

            void Read() override;

            int32 DifficultyID = 0;
            uint8 Legacy = 0;
        };

        class DungeonDifficultySet final : public ServerPacket
        {
        public:
            DungeonDifficultySet() : ServerPacket(SMSG_SET_DUNGEON_DIFFICULTY, 4) { }

            WorldPacket const* Write() override;

            int32 DifficultyID = 0;
        };

        class RaidDifficultySet final : public ServerPacket
        {
        public:
            RaidDifficultySet() : ServerPacket(SMSG_SET_RAID_DIFFICULTY, 4 + 1) { }

            WorldPacket const* Write() override;

            int32 DifficultyID = 0;
            uint8 Legacy = 0;
        };

        class CorpseReclaimDelay : public ServerPacket
        {
        public:
            CorpseReclaimDelay() : ServerPacket(SMSG_CORPSE_RECLAIM_DELAY, 4) { }

            WorldPacket const* Write() override;

            uint32 Remaining = 0;
        };

        class DeathReleaseLoc : public ServerPacket
        {
        public:
            DeathReleaseLoc() : ServerPacket(SMSG_DEATH_RELEASE_LOC, 4 + (3 * 4)) { }

            WorldPacket const* Write() override;

            int32 MapID = 0;
            G3D::Vector3 Loc;
        };

        class PortGraveyard final : public ClientPacket
        {
        public:
            PortGraveyard(WorldPacket&& packet) : ClientPacket(CMSG_PORT_GRAVEYARD, std::move(packet)) { }

            void Read() override { }
        };

        class PreRessurect : public ServerPacket
        {
        public:
            PreRessurect() : ServerPacket(SMSG_PRE_RESSURECT, 18) { }

            WorldPacket const* Write() override;

            ObjectGuid PlayerGUID;
        };

        class ReclaimCorpse final : public ClientPacket
        {
        public:
            ReclaimCorpse(WorldPacket&& packet) : ClientPacket(CMSG_RECLAIM_CORPSE, std::move(packet)) { }

            void Read() override;

            ObjectGuid CorpseGUID;
        };

        class RepopRequest final : public ClientPacket
        {
        public:
            RepopRequest(WorldPacket&& packet) : ClientPacket(CMSG_REPOP_REQUEST, std::move(packet)) { }

            void Read() override;

            bool CheckInstance = false;
        };

        class RequestCemeteryList final : public ClientPacket
        {
        public:
            RequestCemeteryList(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_CEMETERY_LIST, std::move(packet)) { }

            void Read() override { }
        };

        class RequestCemeteryListResponse final : public ServerPacket
        {
        public:
            RequestCemeteryListResponse() : ServerPacket(SMSG_REQUEST_CEMETERY_LIST_RESPONSE, 1) { }

            WorldPacket const* Write() override;

            bool IsGossipTriggered = false;
            std::vector<uint32> CemeteryID;
        };

        class ResurrectResponse final : public ClientPacket
        {
        public:
            ResurrectResponse(WorldPacket&& packet) : ClientPacket(CMSG_RESURRECT_RESPONSE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Resurrecter;
            uint32 Response = 0;
        };

        class AreaTriggerNoCorpse final : public ServerPacket
        {
        public:
            AreaTriggerNoCorpse() : ServerPacket(SMSG_AREA_TRIGGER_NO_CORPSE, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        class Weather final : public ServerPacket
        {
        public:
            Weather();
            Weather(WeatherState weatherID, float intensity = 0.0f, bool abrupt = false);

            WorldPacket const* Write() override;

            bool Abrupt = false;
            float Intensity = 0.0f;
            WeatherState WeatherID = WEATHER_STATE_FINE;
        };

        class StandStateChange final : public ClientPacket
        {
        public:
            StandStateChange(WorldPacket&& packet) : ClientPacket(CMSG_STAND_STATE_CHANGE, std::move(packet)) { }

            void Read() override;

            UnitStandStateType StandState = UNIT_STAND_STATE_STAND;
        };

        class StandStateUpdate final : public ServerPacket
        {
        public:
            StandStateUpdate() : ServerPacket(SMSG_STAND_STATE_UPDATE, 1) { }
            StandStateUpdate(UnitStandStateType state) : ServerPacket(SMSG_STAND_STATE_UPDATE, 1), State(state) { }

            WorldPacket const* Write() override;

            UnitStandStateType State = UNIT_STAND_STATE_STAND;
        };
    }
}

#endif // MiscPackets_h__
