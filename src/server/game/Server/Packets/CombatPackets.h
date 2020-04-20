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

#ifndef CombatPackets_h__
#define CombatPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace Combat
    {
        struct ThreatInfo
        {
            ObjectGuid UnitGUID;
            int32 Threat = 0;
        };

        class ThreatUpdate final : public ServerPacket
        {
        public:
            ThreatUpdate() : ServerPacket(SMSG_THREAT_UPDATE, 20) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
            std::vector<ThreatInfo> ThreatList;
        };

        class HighestThreatUpdate final : public ServerPacket
        {
        public:
            HighestThreatUpdate() : ServerPacket(SMSG_HIGHEST_THREAT_UPDATE, 28) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
            std::vector<ThreatInfo> ThreatList;
            ObjectGuid HighestThreatGUID;
        };

        class ThreatRemove final : public ServerPacket
        {
        public:
            ThreatRemove() : ServerPacket(SMSG_THREAT_REMOVE, 16) { }

            WorldPacket const* Write() override;

            ObjectGuid AboutGUID; // Unit to remove threat from (e.g. player, pet, guardian)
            ObjectGuid UnitGUID; // Unit being attacked (e.g. creature, boss)
        };

        class ThreatClear final : public ServerPacket
        {
        public:
            ThreatClear() : ServerPacket(SMSG_THREAT_CLEAR, 8) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
        };
    }
}

#endif // CombatPackets_h__
