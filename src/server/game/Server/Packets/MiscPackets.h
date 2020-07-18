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
#include "Position.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "Weather.h"
#include <array>

enum WeatherState : uint32;

namespace WorldPackets
{
    namespace Misc
    {
        class BindPointUpdate final : public ServerPacket
        {
        public:
            BindPointUpdate() : ServerPacket(SMSG_BIND_POINT_UPDATE, 20) { }

            WorldPacket const* Write() override;

            uint32 BindMapID = 0;
            TaggedPosition<Position::XYZ> BindPosition;
            uint32 BindAreaID = 0;
        };

        class PlayerBound final : public ServerPacket
        {
        public:
            PlayerBound() : ServerPacket(SMSG_PLAYER_BOUND, 8 + 4) { }
            PlayerBound(ObjectGuid binderId, uint32 areaId) : ServerPacket(SMSG_PLAYER_BOUND, 8 + 4), BinderID(binderId), AreaID(areaId) { }

            WorldPacket const* Write() override;

            ObjectGuid BinderID;
            uint32 AreaID = 0;
        };

        class BinderConfirm final : public ServerPacket
        {
        public:
            BinderConfirm() : ServerPacket(SMSG_BINDER_CONFIRM, 8) { }
            BinderConfirm(ObjectGuid unit) : ServerPacket(SMSG_BINDER_CONFIRM, 8), Unit(unit) { }

            WorldPacket const* Write() override;

            ObjectGuid Unit;
        };

        class StartMirrorTimer final : public ServerPacket
        {
        public:
            StartMirrorTimer() : ServerPacket(SMSG_START_MIRROR_TIMER, 21) { }
            StartMirrorTimer(uint32 timer, uint32 value, uint32 maxValue, int32 scale, bool paused, uint32 spellID) :
                ServerPacket(SMSG_START_MIRROR_TIMER, 21), Timer(timer), Value(value), MaxValue(maxValue), Scale(scale), Paused(paused), SpellID(spellID) { }

            WorldPacket const* Write() override;

            uint32 Timer = 0;
            uint32 Value = 0;
            uint32 MaxValue = 0;
            int32 Scale = 0;
            bool Paused = false;
            uint32 SpellID = 0;
        };

        class PauseMirrorTimer final : public ServerPacket
        {
        public:
            PauseMirrorTimer() : ServerPacket(SMSG_PAUSE_MIRROR_TIMER, 5) { }
            PauseMirrorTimer(uint32 timer, bool paused) : ServerPacket(SMSG_PAUSE_MIRROR_TIMER, 5), Timer(timer), Paused(paused) { }

            WorldPacket const* Write() override;

            uint32 Timer = 0;
            bool Paused = true;
        };

        class StopMirrorTimer final : public ServerPacket
        {
        public:
            StopMirrorTimer() : ServerPacket(SMSG_STOP_MIRROR_TIMER, 4) { }
            StopMirrorTimer(uint32 timer) : ServerPacket(SMSG_STOP_MIRROR_TIMER, 4), Timer(timer) { }

            WorldPacket const* Write() override;

            uint32 Timer = 0;
        };

        class InvalidatePlayer final : public ServerPacket
        {
        public:
            InvalidatePlayer() : ServerPacket(SMSG_INVALIDATE_PLAYER, 8) { }
            InvalidatePlayer(ObjectGuid guid) : ServerPacket(SMSG_INVALIDATE_PLAYER, 8), Guid(guid) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
        };

        class LoginSetTimeSpeed final : public ServerPacket
        {
        public:
            LoginSetTimeSpeed() : ServerPacket(SMSG_LOGIN_SET_TIME_SPEED, 12) { }

            WorldPacket const* Write() override;

            float NewSpeed = 0.0f;
            uint32 GameTime = 0;
            int32 GameTimeHolidayOffset = 0;
        };

        class DurabilityDamageDeath final : public ServerPacket
        {
        public:
            DurabilityDamageDeath() : ServerPacket(SMSG_DURABILITY_DAMAGE_DEATH, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
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

        class LevelUpInfo final : public ServerPacket
        {
        public:
            LevelUpInfo() : ServerPacket(SMSG_LEVELUP_INFO, 56) { }

            WorldPacket const* Write() override;

            uint32 Level = 0;
            uint32 HealthDelta = 0;
            std::array<uint32, MAX_POWERS> PowerDelta = { };
            std::array<uint32, MAX_STATS> StatDelta = { };
        };

        class TC_GAME_API PlayMusic final : public ServerPacket
        {
        public:
            PlayMusic() : ServerPacket(SMSG_PLAY_MUSIC, 4) { }
            PlayMusic(uint32 soundKitID) : ServerPacket(SMSG_PLAY_MUSIC, 4), SoundKitID(soundKitID) { }

            WorldPacket const* Write() override;

            uint32 SoundKitID = 0;
        };

        class TC_GAME_API PlayObjectSound final : public ServerPacket
        {
        public:
            PlayObjectSound() : ServerPacket(SMSG_PLAY_OBJECT_SOUND, 4 + 8) { }
            PlayObjectSound(ObjectGuid const& sourceObjectGUID, uint32 soundKitID)
                : ServerPacket(SMSG_PLAY_OBJECT_SOUND, 4 + 8), SourceObjectGUID(sourceObjectGUID), SoundKitID(soundKitID) { }

            WorldPacket const* Write() override;

            ObjectGuid SourceObjectGUID;
            uint32 SoundKitID = 0;

        };

        class TC_GAME_API PlaySound final : public ServerPacket
        {
        public:
            PlaySound() : ServerPacket(SMSG_PLAY_SOUND, 4) { }
            PlaySound(uint32 soundKitID) : ServerPacket(SMSG_PLAY_SOUND, 4), SoundKitID(soundKitID) { }

            WorldPacket const* Write() override;

            uint32 SoundKitID = 0;
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

        class CrossedInebriationThreshold final : public ServerPacket
        {
        public:
            CrossedInebriationThreshold() : ServerPacket(SMSG_CROSSED_INEBRIATION_THRESHOLD, 8 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
            uint32 Threshold = 0;
            uint32 ItemID = 0;
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

        class RandomRollClient final : public ClientPacket
        {
        public:
            RandomRollClient(WorldPacket&& packet) : ClientPacket(MSG_RANDOM_ROLL, std::move(packet)) { }

            void Read() override;

            uint32 Min = 0;
            uint32 Max = 0;
        };

        class RandomRoll final : public ServerPacket
        {
        public:
            RandomRoll() : ServerPacket(MSG_RANDOM_ROLL, 4 + 4 + 4 + 8) { }

            WorldPacket const* Write() override;

            uint32 Min = 0;
            uint32 Max = 0;
            uint32 Result = 0;
            ObjectGuid Roller;
        };

        class TogglePvP final : public ClientPacket
        {
        public:
            TogglePvP(WorldPacket&& packet) : ClientPacket(CMSG_TOGGLE_PVP, std::move(packet)) { }

            void Read() override;

            bool HasPvPStatus() const { return GetSize() == 1; }

            Optional<bool> Enable;
        };

        class UITime final : public ServerPacket
        {
        public:
            UITime() : ServerPacket(SMSG_WORLD_STATE_UI_TIMER_UPDATE, 4) { }

            WorldPacket const* Write() override;

            uint32 Time = 0;
        };

        class WorldTeleport final : public ClientPacket
        {
        public:
            WorldTeleport(WorldPacket&& packet) : ClientPacket(CMSG_WORLD_TELEPORT, std::move(packet)) { }

            void Read() override;

            uint32 Time = 0;
            uint32 MapID = 0;
            TaggedPosition<Position::XYZ> Pos;
            float Facing = 0.0f;
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
            TaggedPosition<Position::XYZ> Loc;
        };

        class PreRessurect : public ServerPacket
        {
        public:
            PreRessurect() : ServerPacket(SMSG_PRE_RESURRECT, 8) { }

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

        class ResurrectResponse final : public ClientPacket
        {
        public:
            ResurrectResponse(WorldPacket&& packet) : ClientPacket(CMSG_RESURRECT_RESPONSE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Resurrecter;
            uint8 Response = 0;
        };
    }
}

#endif // MiscPackets_h__
