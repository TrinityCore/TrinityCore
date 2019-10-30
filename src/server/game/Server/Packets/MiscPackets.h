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
#include "Weather.h"

enum WeatherState : uint32;

namespace WorldPackets
{
    namespace Misc
    {
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

        class OverrideLight final : public ServerPacket
        {
        public:
            OverrideLight() : ServerPacket(SMSG_OVERRIDE_LIGHT, 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            int32 AreaLightID = 0;
            int32 TransitionMilliseconds = 0;
            int32 OverrideLightID = 0;
        };
    }
}

#endif // MiscPackets_h__
