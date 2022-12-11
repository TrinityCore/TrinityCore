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

#ifndef PetPackets_h__
#define PetPackets_h__

#include "Packet.h"
#include "Position.h"

namespace WorldPackets
{
    namespace Pet
    {
        class PetDismissSound final : public ServerPacket
        {
        public:
            PetDismissSound() : ServerPacket(SMSG_PET_DISMISS_SOUND, 4 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            int32 ModelID = 0;
            TaggedPosition<Position::XYZ> ModelPosition;
        };
    }
}

#endif // PetPackets_h__
