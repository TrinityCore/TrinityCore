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
#include "WorldSession.h"

namespace WorldPackets
{
    namespace Pet
    {        
        struct PetSpellCooldown
        {
            int32 SpellID = 0;
            int32 Duration = 0;
            int32 CategoryDuration = 0;
            int Category = 0;
        };

        struct PetSpellHistory
        {
            int32 CategoryID = 0;
            int32 RecoveryTime = 0;
            int8 ConsumedCharges = 0;
        };
        
        class PetSpells final : public ServerPacket
        {
        public:
            PetSpells() : ServerPacket(SMSG_PET_SPELLS_MESSAGE, 0) { }

            WorldPacket const* Write() override;

            ObjectGuid PetGUID;
            int CreatureFamily = 0;
            int Specialization = 0;
            int32 TimeLimit = 0;
            uint8 ReactState = 0;
            uint8 CommandState = 0;
            uint8 Flag = 0;

            uint32 ActionButtons[10];

            std::vector<uint32> Actions;
            std::vector<PetSpellCooldown> Cooldowns;
            std::vector<PetSpellHistory> SpellHistory;
        };
    }
}


#endif // PetPackets_h__
