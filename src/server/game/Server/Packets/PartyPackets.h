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

#ifndef PartyPackets_h__
#define PartyPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "Optional.h"

class Player;

namespace WorldPackets
{
    namespace Party
    {
        struct PartyMemberPhaseStates
        {
            uint32 PhaseShiftFlags = 0;
            std::vector<uint16> List;
        };

        struct PartyMemberAuraStates
        {
            int32 SpellID = 0;
            uint16 Flags = 0;
            std::vector<int32> Points;
        };

        struct PartyMemberPetStats
        {
            ObjectGuid GUID;
            std::string Name;
            int16 ModelId = 0;
            int32 CurrentHealth = 0;
            int32 MaxHealth = 0;
            uint8 PowerType = 0u;
            uint16 CurrentPower = 0;
            uint16 MaxPower = 0;
            uint64 AuraMask = 0;
            std::vector<PartyMemberAuraStates> Auras;
        };

        struct PartyMemberStats
        {
            uint16 Level = 0;
            uint16 Status = 0;
            int32 CurrentHealth = 0;
            int32 MaxHealth = 0;
            uint8 PowerType = 0u;
            uint16 CurrentPower = 0;
            uint16 MaxPower = 0;
            uint16 ZoneID = 0;
            uint16 WmoGroupID = 0;
            int16 PositionX = 0;
            int16 PositionY = 0;
            int16 PositionZ = 0;
            int32 VehicleSeat = 0;
            uint64 AuraMask = 0;
            uint32 AuraCount = 0;

            PartyMemberPhaseStates Phases;
            std::vector<PartyMemberAuraStates> Auras;
            Optional<PartyMemberPetStats> PetStats;
        };

        class PartyMemberState final : public ServerPacket
        {
        public:
            PartyMemberState(bool fullUpdate = false) : ServerPacket(fullUpdate ? SMSG_PARTY_MEMBER_FULL_STATE : SMSG_PARTY_MEMBER_STATE, 80) { }

            WorldPacket const* Write() override;
            void Initialize(Player const* player);

            bool ForEnemy = false;
            ObjectGuid MemberGuid;
            uint32 ChangeMask = 0;
            PartyMemberStats MemberStats;
        };
    }
}

#endif // PartyPackets_h__
