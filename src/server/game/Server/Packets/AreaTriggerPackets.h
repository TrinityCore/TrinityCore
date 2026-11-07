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

#ifndef TRINITYCORE_AREA_TRIGGER_PACKETS_H
#define TRINITYCORE_AREA_TRIGGER_PACKETS_H

#include "Packet.h"
#include "CombatLogPacketsCommon.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace AreaTrigger
    {
        class AreaTrigger final : public ClientPacket
        {
        public:
            explicit AreaTrigger(WorldPacket&& packet) : ClientPacket(CMSG_AREA_TRIGGER, std::move(packet)) { }

            void Read() override;

            int32 AreaTriggerID = 0;
            bool Entered = false;
            bool FromClient = false;
        };

        class AreaTriggerDenied final : public ServerPacket
        {
        public:
            explicit AreaTriggerDenied() : ServerPacket(SMSG_AREA_TRIGGER_DENIED, 5) { }

            int32 AreaTriggerID = 0;
            bool Entered = false;

            WorldPacket const* Write() override;
        };

        class AreaTriggerNoCorpse final : public ServerPacket
        {
        public:
            explicit AreaTriggerNoCorpse() : ServerPacket(SMSG_AREA_TRIGGER_NO_CORPSE, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        class AreaTriggerPlaySpellVisual final : public ServerPacket
        {
        public:
            explicit AreaTriggerPlaySpellVisual() : ServerPacket(SMSG_AREA_TRIGGER_PLAY_SPELL_VISUAL, 16 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid AreaTriggerGUID;
            uint32 SpellVisualID = 0;
        };

        class UpdateAreaTriggerVisual final : public ClientPacket
        {
        public:
            explicit UpdateAreaTriggerVisual(WorldPacket&& packet) : ClientPacket(CMSG_UPDATE_AREA_TRIGGER_VISUAL, std::move(packet)) { }

            void Read() override;

            int32 SpellID = 0;
            Spells::SpellCastVisual Visual;
            ObjectGuid TargetGUID;
        };
    }
}

#endif // TRINITYCORE_AREA_TRIGGER_PACKETS_H
