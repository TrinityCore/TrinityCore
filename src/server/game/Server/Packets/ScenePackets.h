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

#ifndef TRINITYCORE_SCENE_PACKETS_H
#define TRINITYCORE_SCENE_PACKETS_H

#include "ObjectGuid.h"
#include "Packet.h"
#include "Position.h"

namespace WorldPackets
{
    namespace Scenes
    {
        class TC_GAME_API PlayScene final : public ServerPacket
        {
        public:
            explicit PlayScene() : ServerPacket(SMSG_PLAY_SCENE, 4 + 4 + 4 + 4 + 4 + 16 + 16 + 1) { }

            WorldPacket const* Write() override;

            int32 SceneID = 0;
            uint32 PlaybackFlags = 0;
            uint32 SceneInstanceID = 0;
            int32 SceneScriptPackageID = 0;
            int32 MovieID = 0;
            ObjectGuid TransportGUID;
            TaggedPosition<Position::XYZO> Location;
            bool Encrypted = false;
        };

        class TC_GAME_API CancelScene final : public ServerPacket
        {
        public:
            explicit CancelScene() : ServerPacket(SMSG_CANCEL_SCENE, 4) { }

            WorldPacket const* Write() override;

            int32 SceneInstanceID = 0;
        };

        class SceneTriggerEvent final : public ClientPacket
        {
        public:
            explicit SceneTriggerEvent(WorldPacket&& packet) : ClientPacket(CMSG_SCENE_TRIGGER_EVENT, std::move(packet)) { }

            void Read() override;

            uint32 SceneInstanceID = 0;
            std::string Event;
        };

        class ScenePlaybackComplete final : public ClientPacket
        {
        public:
            explicit ScenePlaybackComplete(WorldPacket&& packet) : ClientPacket(CMSG_SCENE_PLAYBACK_COMPLETE, std::move(packet)) { }

            void Read() override;

            uint32 SceneInstanceID = 0;
            int32 TimePassed = 0;
        };

        class ScenePlaybackCanceled final : public ClientPacket
        {
        public:
            explicit ScenePlaybackCanceled(WorldPacket&& packet) : ClientPacket(CMSG_SCENE_PLAYBACK_CANCELED, std::move(packet)) { }

            void Read() override;

            uint32 SceneInstanceID = 0;
            int32 TimePassed = 0;
        };
    }
}

#endif // TRINITYCORE_SCENE_PACKETS_H
