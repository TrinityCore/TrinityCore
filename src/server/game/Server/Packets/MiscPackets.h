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
#include "CUFProfile.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "SharedDefines.h"
#include "Position.h"
#include <array>

enum WeatherState : uint32;

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
            uint32 SoundKitID = 0;
        };

        class PlayObjectSound final : public ServerPacket
        {
        public:
            PlayObjectSound() : ServerPacket(SMSG_PLAY_OBJECT_SOUND, 8 + 8 + 4) { }
            PlayObjectSound(ObjectGuid sourceObjectGuid, ObjectGuid targetObjectGuid, uint32 soundKitID) : ServerPacket(SMSG_PLAY_OBJECT_SOUND, 8 + 8 + 4),
                SourceObjectGUID(sourceObjectGuid), TargetObjectGUID(targetObjectGuid), SoundKitID(soundKitID) { }

            WorldPacket const* Write() override;

            ObjectGuid SourceObjectGUID;
            ObjectGuid TargetObjectGUID;
            uint32 SoundKitID = 0;
        };

        class PlayMusic final : public ServerPacket
        {
        public:
            PlayMusic() : ServerPacket(SMSG_PLAY_MUSIC, 4 + 8) { }
            PlayMusic(uint32 soundKitID, ObjectGuid sourceObjectGuid) : ServerPacket(SMSG_PLAY_MUSIC, 4 + 8), SoundKitID(soundKitID), SourceObjectGUID(sourceObjectGuid) { }

            WorldPacket const* Write() override;

            uint32 SoundKitID = 0;
            ObjectGuid SourceObjectGUID;
        };

        class TC_GAME_API Weather final : public ServerPacket
        {
        public:
            Weather();
            Weather(WeatherState weatherID, float intensity = 0.0f, bool abrupt = false);

            WorldPacket const* Write() override;

            bool Abrupt = false;
            float Intensity = 0.0f;
            WeatherState WeatherID = WeatherState(0);
        };

        class OverrideLight final : public ServerPacket
        {
        public:
            OverrideLight() : ServerPacket(SMSG_OVERRIDE_LIGHT, 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            int32 AreaLightID = 0;
            int32 TransitionMilliseconds = 0;
            int32 OverrideLightID = 0;
        };

        class DurabilityDamageDeath final : public ServerPacket
        {
        public:
            DurabilityDamageDeath() : ServerPacket(SMSG_DURABILITY_DAMAGE_DEATH, 4) { }

            WorldPacket const* Write() override;

            int32 Percent = 0;
        };

        class PlayOneShotAnimKit final : public ServerPacket
        {
        public:
            PlayOneShotAnimKit() : ServerPacket(SMSG_PLAY_ONE_SHOT_ANIM_KIT, 8 + 2) { }

            WorldPacket const* Write() override;

            ObjectGuid Unit;
            uint16 AnimKitID = 0;
        };

        class SetAIAnimKit final : public ServerPacket
        {
        public:
            SetAIAnimKit() : ServerPacket(SMSG_SET_AI_ANIM_KIT, 8 + 2) { }

            WorldPacket const* Write() override;

            ObjectGuid Unit;
            uint16 AnimKitID = 0;
        };

        class SetMovementAnimKit final : public ServerPacket
        {
        public:
            SetMovementAnimKit() : ServerPacket(SMSG_SET_MOVEMENT_ANIM_KIT, 8 + 2) { }

            WorldPacket const* Write() override;

            ObjectGuid Unit;
            uint16 AnimKitID = 0;
        };

        class SetMeleeAnimKit final : public ServerPacket
        {
        public:
            SetMeleeAnimKit() : ServerPacket(SMSG_SET_MELEE_ANIM_KIT, 8 + 2) { }

            WorldPacket const* Write() override;

            ObjectGuid Unit;
            uint16 AnimKitID = 0;
        };

        class UnitHealthFrequent final : public ServerPacket
        {
        public:
            UnitHealthFrequent() : ServerPacket(SMSG_UNIT_HEALTH_FREQUENT, 12) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
            int32 Health = 0;
        };

        class StartTimer final : public ServerPacket
        {
        public:
            StartTimer() : ServerPacket(SMSG_START_TIMER, 12) { }

            WorldPacket const* Write() override;

            uint32 Type = 0;
            int32 TimeLeft = 0;
            int32 TotalTime = 0;
        };

        class DestroyObject final : public ServerPacket
        {
        public:
            DestroyObject() : ServerPacket(SMSG_DESTROY_OBJECT, 9) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
            bool IsDead = false;
        };

        class StandStateUpdate : public ServerPacket
        {
        public:
            StandStateUpdate() : ServerPacket(SMSG_STAND_STATE_UPDATE, 1) { }

            WorldPacket const* Write() override;

            uint8 State = 0;
        };

        class SetAnimTier final : public ServerPacket
        {
        public:
            SetAnimTier() : ServerPacket(SMSG_SET_ANIM_TIER, 8 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid Unit;
            int32 Tier = 0;
        };

        class SetPlayHoverAnim final : public ServerPacket
        {
        public:
            SetPlayHoverAnim() : ServerPacket(SMSG_SET_PLAY_HOVER_ANIM, 8 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
            bool PlayHoverAnim = false;
        };

        class StartMirrorTimer final : public ServerPacket
        {
        public:
            StartMirrorTimer() : ServerPacket(SMSG_START_MIRROR_TIMER, 4 + 4 + 4 + 4 + 4 + 1) { }
            StartMirrorTimer(int32 timer, int32 value, int32 maxValue, int32 scale, int32 spellID, bool paused) :
                ServerPacket(SMSG_START_MIRROR_TIMER, 21), Scale(scale), MaxValue(maxValue), Timer(timer), SpellID(spellID), Value(value), Paused(paused) { }

            WorldPacket const* Write() override;

            int32 Scale = 0;
            int32 MaxValue = 0;
            int32 Timer = 0;
            int32 SpellID = 0;
            int32 Value = 0;
            bool Paused = false;
        };

        class PauseMirrorTimer final : public ServerPacket
        {
        public:
            PauseMirrorTimer() : ServerPacket(SMSG_PAUSE_MIRROR_TIMER, 4 + 1) { }
            PauseMirrorTimer(int32 timer, bool paused) : ServerPacket(SMSG_PAUSE_MIRROR_TIMER, 5), Timer(timer), Paused(paused) { }

            WorldPacket const* Write() override;

            int32 Timer = 0;
            bool Paused = true;
        };

        class StopMirrorTimer final : public ServerPacket
        {
        public:
            StopMirrorTimer() : ServerPacket(SMSG_STOP_MIRROR_TIMER, 4) { }
            StopMirrorTimer(int32 timer) : ServerPacket(SMSG_STOP_MIRROR_TIMER, 4), Timer(timer) { }

            WorldPacket const* Write() override;

            int32 Timer = 0;
        };

        class CrossedInebriationThreshold final : public ServerPacket
        {
        public:
            CrossedInebriationThreshold() : ServerPacket(SMSG_CROSSED_INEBRIATION_THRESHOLD, 8 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
            int32 ItemID = 0;
            int32 Threshold = 0;
        };

        class LevelUpInfo final : public ServerPacket
        {
        public:
            LevelUpInfo() : ServerPacket(SMSG_LEVEL_UP_INFO, 48) { }

            WorldPacket const* Write() override;

            int32 Level = 0;
            int32 HealthDelta = 0;
            std::array<int32, 6> PowerDelta = { };
            std::array<int32, MAX_STATS> StatDelta = { };
        };

        class BindPointUpdate final : public ServerPacket
        {
        public:
            BindPointUpdate() : ServerPacket(SMSG_BIND_POINT_UPDATE, 20) { }

            WorldPacket const* Write() override;

            uint32 BindMapID = 0;
            TaggedPosition<Position::XYZ> BindPosition;
            uint32 BindAreaID = 0;
        };

        class WorldServerInfo final : public ServerPacket
        {
        public:
            WorldServerInfo() : ServerPacket(SMSG_WORLD_SERVER_INFO, 10) { }

            WorldPacket const* Write() override;

            uint32 DifficultyID = 0;
            uint32 WeeklyReset = 0;
            uint8 IsTournamentRealm = 0;
            Optional<uint32> IneligibleForLootMask;
            Optional<uint32> RestrictedAccountMaxLevel;
            Optional<uint32> RestrictedAccountMaxMoney;
        };

        class LoginSetTimeSpeed final : public ServerPacket
        {
        public:
            LoginSetTimeSpeed() : ServerPacket(SMSG_LOGIN_SET_TIME_SPEED, 12) { }

            WorldPacket const* Write() override;

            float NewSpeed = 0.0f;
            uint32 GameTime = 0;
            uint32 GameTimeHolidayOffset = 0;
        };

        class ZoneUnderAttack final : public ServerPacket
        {
        public:
            ZoneUnderAttack() : ServerPacket(SMSG_ZONE_UNDER_ATTACK, 4) { }

            WorldPacket const* Write() override;

            int32 AreaID = 0;
        };

        class Dismount final : public ServerPacket
        {
        public:
            Dismount() : ServerPacket(SMSG_DISMOUNT, 8) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
        };

        class LoadCUFProfiles final : public ServerPacket
        {
        public:
            LoadCUFProfiles() : ServerPacket(SMSG_LOAD_CUF_PROFILES, 20) { }

            WorldPacket const* Write() override;

            std::vector<CUFProfile const*> CUFProfiles;
        };

        class DeathReleaseLoc : public ServerPacket
        {
        public:
            DeathReleaseLoc() : ServerPacket(SMSG_DEATH_RELEASE_LOC, 4 + (3 * 4)) { }

            WorldPacket const* Write() override;

            int32 MapID = 0;
            TaggedPosition<Position::XYZ> Loc;
        };

        class BinderConfirm final : public ServerPacket
        {
        public:
            BinderConfirm() : ServerPacket(SMSG_BINDER_CONFIRM, 8) { }
            BinderConfirm(ObjectGuid unit) : ServerPacket(SMSG_BINDER_CONFIRM, 8), Unit(unit) { }

            WorldPacket const* Write() override;

            ObjectGuid Unit;
        };

        class RequestCemeteryListResponse final : public ServerPacket
        {
        public:
            RequestCemeteryListResponse() : ServerPacket(SMSG_REQUEST_CEMETERY_LIST_RESPONSE, 1) { }

            WorldPacket const* Write() override;

            bool IsGossipTriggered = false;
            std::vector<uint32> CemeteryID;
        };

        class CorpseReclaimDelay final : public ServerPacket
        {
        public:
            CorpseReclaimDelay() : ServerPacket(SMSG_CORPSE_RECLAIM_DELAY, 4) { }

            WorldPacket const* Write() override;

            uint32 Remaining = 0;
        };

        class SetCurrencyFlags final : public ClientPacket
        {
        public:
            SetCurrencyFlags(WorldPacket&& packet) : ClientPacket(CMSG_SET_CURRENCY_FLAGS, std::move(packet)) { }

            void Read() override;

            uint32 Flags = 0;
            uint32 CurrencyID = 0;
        };

        class MapObjEvents final : public ServerPacket
        {
        public:
            MapObjEvents() : ServerPacket(SMSG_MAP_OBJ_EVENTS, 8) { }

            WorldPacket const* Write() override;

            uint32 UniqueID = 0;
            std::vector<uint8> Events;
        };

        class SetCurrency final : public ServerPacket
        {
        public:
            SetCurrency() : ServerPacket(SMSG_SET_CURRENCY, 13) { }

            WorldPacket const* Write() override;

            bool SuppressChatLog = false;
            int32 Quantity = 0;
            int32 Type = 0;
            Optional<int32> TrackedQuantity;
            Optional<int32> WeeklyQuantity;
        };
    }
}

#endif // MiscPackets_h__
