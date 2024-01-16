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

#ifndef TalentPackets_h__
#define TalentPackets_h__

#include "Packet.h"

namespace WorldPackets
{
    namespace Talents
    {
        class Wipe : public ServerPacket
        {
            public:
                Wipe() : ServerPacket(MSG_TALENT_WIPE_CONFIRM, 8 + 4) { }
                Wipe(ObjectGuid trainerGuid, uint32 cost) :
                    ServerPacket(MSG_TALENT_WIPE_CONFIRM, 8 + 4), TrainerGuid(trainerGuid), Cost(cost) { }

                WorldPacket const* Write() override;

                ObjectGuid TrainerGuid;
                uint32 Cost = 0;
        };

        class WipeConfirm : public ClientPacket
        {
            public:
                WipeConfirm(WorldPacket&& packet) : ClientPacket(MSG_TALENT_WIPE_CONFIRM, std::move(packet)) { }

                void Read() override;

                ObjectGuid TrainerGuid;
        };

        class InvoluntarilyReset : public ServerPacket
        {
            public:
                InvoluntarilyReset() : ServerPacket(SMSG_TALENTS_INVOLUNTARILY_RESET, 1) { }
                InvoluntarilyReset(uint8 isPetTalents) : ServerPacket(SMSG_TALENTS_INVOLUNTARILY_RESET, 1), IsPetTalents(isPetTalents) { }

                WorldPacket const* Write() override;

                uint8 IsPetTalents = 0;
        };
    }
}

#endif // TalentPackets_h__
