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

#ifndef AreaTriggerPackets_h__
#define AreaTriggerPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "Position.h"

namespace WorldPackets
{
    namespace AreaTrigger
    {
        struct AreaTriggerSplineInfo
        {
            uint32 TimeToTarget = 0;
            uint32 ElapsedTimeForMovement = 0;
            std::vector<TaggedPosition<Position::XYZ>> Points;
        };

        struct AreaTriggerUnkTypeInfo
        {
            Optional<ObjectGuid> AreaTriggerUnkGUID;
            Optional<TaggedPosition<Position::XYZ>> Center;
            bool UnkBit1 = false;
            bool UnkBit2 = false;
            uint32 UnkUInt1 = 0;
            int32 UnkInt1 = 0;
            uint32 UnkUInt2 = 0;
            float Radius = 0.0;
            float BlendFromRadius = 0.0f;
            float InitialAngel = 0.0f;
            float ZOffset = 0.0f;
        };

        class AreaTrigger final : public ClientPacket
        {
        public:
            AreaTrigger(WorldPacket&& packet) : ClientPacket(CMSG_AREA_TRIGGER, std::move(packet)) { }

            void Read() override;

            int32 AreaTriggerID = 0;
            bool Entered = false;
            bool FromClient = false;
        };

        class AreaTriggerDenied final : public ServerPacket
        {
        public:
            AreaTriggerDenied() : ServerPacket(SMSG_AREA_TRIGGER_DENIED, 5) { }

            int32 AreaTriggerID = 0;
            bool Entered = false;

            WorldPacket const* Write() override;
        };

        class AreaTriggerNoCorpse final : public ServerPacket
        {
        public:
            AreaTriggerNoCorpse() : ServerPacket(SMSG_AREA_TRIGGER_NO_CORPSE, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        class AreaTriggerRePath final : public ServerPacket
        {
        public:
            AreaTriggerRePath() : ServerPacket(SMSG_AREA_TRIGGER_RE_PATH, 50) { }

            WorldPacket const* Write() override;

            AreaTriggerSplineInfo AreaTriggerSpline;
            ObjectGuid TriggerGUID;
        };

        class AreaTriggerReShape final : public ServerPacket
        {
        public:
            AreaTriggerReShape() : ServerPacket(SMSG_AREA_TRIGGER_RE_SHAPE, 17) { }

            WorldPacket const* Write() override;

            Optional<AreaTriggerSplineInfo> AreaTriggerSpline;
            Optional<AreaTriggerUnkTypeInfo> AreaTriggerUnkType;
            ObjectGuid TriggerGUID;
        };
    }
}

#endif // AreaTriggerPackets_h__
