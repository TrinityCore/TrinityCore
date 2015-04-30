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

#ifndef PetPackets_h__
#define PetPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"

class WorldObject;

namespace WorldPackets
{
    namespace Pet
    {
        // SMSG_PET_GUIDS
        class PetGuids final : public ServerPacket
        {
        public:
            PetGuids() : ServerPacket(SMSG_PET_GUIDS, 16 + 4 ) { }

            WorldPacket const* Write() override;

            uint32 petCount = 0;
            //std::vector<ObjectGuid> petGuids;
            ObjectGuid petGuids;
           
        };

        //SMSG_PET_SPELLS_MESSAGE
        class PetSpellsMessage final : public ServerPacket
        {
        public:

            struct AuctionButton
            {
                int16 spell16 = 0;
                uint8 spell8 = 0;
                int32 spellid = spell16+(spell8 << 16);
                uint8 Slot = 0;
            };

            PetSpellsMessage() : ServerPacket(SMSG_PET_SPELLS_MESSAGE, 16 + 2 + 2 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid PetGUID;
            uint16 creatureFamily = CREATURE_FAMILY_WOLF;
            uint16 specialization = 0;
            uint32 timeLimit = 0;
            uint32 petModeAndOrders = 0;
            // ActionButtons

            int32 actionsCount = 0;
            uint32 cooldownsCount = 0;
            uint32 spellHistoryCount = 0;
            //Actions

            // PetSpellCooldown

            // PetSpellHistory

        };
    }
}
#endif // PetPackets_h__