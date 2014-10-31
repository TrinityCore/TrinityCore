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

#ifndef CharacterPackets_h__
#define CharacterPackets_h__

#include "Packet.h"
#include "Player.h"

namespace WorldPackets
{
    namespace Character
    {
        class CharEnumResult final : public ServerPacket
        {
        public:
            struct CharacterInfo
            {
                /**
                 * @fn  void WorldPackets::Character::CharEnumResult::CharacterInfo::CharacterInfo(Field* fields);
                 *
                 * @brief   Initialize the struct with values from QueryResult
                 *
                 * @param   fields         Field set of CharacterDatabaseStatements::CHAR_SEL_ENUM
                 */
                CharacterInfo(Field* fields);

                ObjectGuid Guid;
                std::string Name;
                uint8 ListPosition       = 0; ///< Order of the characters in list
                uint8 Race               = 0;
                uint8 Class              = 0;
                uint8 Sex                = 0;
                uint8 Skin               = 0;
                uint8 Face               = 0;
                uint8 HairStyle          = 0;
                uint8 HairColor          = 0;
                uint8 FacialHair         = 0;
                uint8 Level              = 0;
                uint32 ZoneId            = 0;
                uint32 MapId             = 0;
                G3D::Vector3 PreLoadPosition;
                ObjectGuid GuildGuid;
                uint32 Flags             = 0; ///< Character flag @see enum CharacterFlags
                uint32 CustomizationFlag = 0; ///< Character customization flags @see enum CharacterCustomizeFlags
                uint32 Flags3            = 0; ///< Character flags 3 @todo research
                bool FirstLogin      = false;

                struct PetInfo
                {
                    uint32 CreatureDisplayId = 0; ///< PetCreatureDisplayID
                    uint32 Level             = 0; ///< PetExperienceLevel
                    uint32 CreatureFamily    = 0; ///< PetCreatureFamilyID
                } Pet;

                bool BoostInProgress = false; ///< @todo
                uint32 ProfessionIds[2];      ///< @todo

                struct VisualItemInfo
                {
                    uint32 DisplayId        = 0;
                    uint32 DisplayEnchantId = 0;
                    uint8 InventoryType     = 0;
                };

                VisualItemInfo VisualItems[INVENTORY_SLOT_BAG_END];
            };

            struct RestrictedFactionChangeRuleInfo
            {
                RestrictedFactionChangeRuleInfo(uint32 mask, uint8 race)
                    : Mask(mask), Race(race) { }

                uint32 Mask = 0;
                uint8 Race  = 0;
            };

            CharEnumResult();

            void Write() override;

            bool Success                = false; ///<
            bool IsDeletedCharacters    = false; ///< used for character undelete list

            std::list<CharacterInfo> Characters; ///< all characters on the list
            std::list<RestrictedFactionChangeRuleInfo> FactionChangeRestrictions; ///< @todo: research
        };

        class PlayerLogin final : public ClientPacket
        {
        public:
            PlayerLogin(WorldPacket&& packet);

            void Read() override;

            ObjectGuid Guid;      ///< Guid of the player that is logging in
            float FarClip = 0.0f; ///< Visibility distance (for terrain)
        };
    }
}

#endif // CharacterPackets_h__
