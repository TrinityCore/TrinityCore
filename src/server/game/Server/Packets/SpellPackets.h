/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef SpellPackets_h__
#define SpellPackets_h__

#include "Packet.h"
#include "Player.h"

namespace WorldPackets
{
    namespace Spell
    {
        class CategoryCooldown final : public ServerPacket
        {
        public:
            struct CategoryCooldownInfo
            {
                CategoryCooldownInfo(uint32 category, int32 cooldown)
                    : Category(category), ModCooldown(cooldown) { }

                uint32 Category   = 0; ///< SpellCategory Id
                int32 ModCooldown = 0; ///< Reduced Cooldown in ms
            };

            CategoryCooldown() : ServerPacket(SMSG_SPELL_CATEGORY_COOLDOWN, 4) { }

            WorldPacket const* Write() override;

            std::vector<CategoryCooldownInfo> CategoryCooldowns;
        };

        class SendKnownSpells final : public ServerPacket
        {
        public:
            SendKnownSpells() : ServerPacket(SMSG_INITIAL_SPELLS, 5) { }

            WorldPacket const* Write() override;

            bool InitialLogin = false;
            std::vector<uint32> KnownSpells;
        };

        class UpdateActionButtons final : public ServerPacket
        {
        public:
            UpdateActionButtons() : ServerPacket(SMSG_ACTION_BUTTONS, MAX_ACTION_BUTTONS * 8 + 1)
            {
                std::memset(ActionButtons, 0, sizeof(ActionButtons));
            }

            WorldPacket const* Write() override;

            uint64 ActionButtons[MAX_ACTION_BUTTONS];
            uint8 Reason = 0;
            /*
                Reason can be 0, 1, 2
                0 - Sends initial action buttons, client does not validate if we have the spell or not
                1 - Used used after spec swaps, client validates if a spell is known.
                2 - Clears the action bars client sided. This is sent during spec swap before unlearning and before sending the new buttons
            */
        };

        class SendUnlearnSpells final : public ServerPacket
        {
        public:
            SendUnlearnSpells() : ServerPacket(SMSG_SEND_UNLEARN_SPELLS, 4) { }

            WorldPacket const* Write() override;

            std::vector<uint32> Spells;
        };

        struct SpellLogPowerData
        {
            int32 PowerType = 0;
            int32 Amount    = 0;
        };

        struct SpellCastLogData
        {
            int32 Health        = 0;
            int32 AttackPower   = 0;
            int32 SpellPower    = 0;
            std::vector<SpellLogPowerData> PowerData;
        };
    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spell::SpellCastLogData& spellCastLogData);

#endif // SpellPackets_h__
