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
        struct CharacterCreateInfo
        {
            /// User specified variables
            uint8 Race            = 0;
            uint8 Class           = 0;
            uint8 Sex   = GENDER_NONE;
            uint8 Skin            = 0;
            uint8 Face            = 0;
            uint8 HairStyle       = 0;
            uint8 HairColor       = 0;
            uint8 FacialHairStyle = 0;
            uint8 OutfitId        = 0;
            Optional<int32> TemplateSet;
            std::string Name;

            /// Server side data
            uint8 CharCount  = 0;
        };

        struct CharacterRenameInfo
        {
            ObjectGuid Guid;
            std::string Name;
        };

        struct CharacterCustomizeInfo : public CharacterRenameInfo
        {
            uint8 Gender     = GENDER_NONE;
            uint8 Skin       = 0;
            uint8 Face       = 0;
            uint8 HairStyle  = 0;
            uint8 HairColor  = 0;
            uint8 FacialHair = 0;
        };

        struct CharacterFactionChangeInfo : public CharacterCustomizeInfo
        {
            uint8 Race = 0;
        };

        struct CharacterUndeleteInfo
        {
            /// User specified variables
            ObjectGuid CharacterGuid; ///< Guid of the character to restore
            int32 ClientToken    = 0; ///< @todo: research

            /// Server side data
            std::string Name;
        };

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
                int32 ZoneId             = 0;
                int32 MapId              = 0;
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
                int32 ProfessionIds[2];       ///< @todo

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
                RestrictedFactionChangeRuleInfo(int32 mask, uint8 race)
                    : Mask(mask), Race(race) { }

                int32 Mask = 0;
                uint8 Race = 0;
            };

            CharEnumResult();

            WorldPacket const* Write() override;

            bool Success                = false; ///<
            bool IsDeletedCharacters    = false; ///< used for character undelete list

            std::list<CharacterInfo> Characters; ///< all characters on the list
            std::list<RestrictedFactionChangeRuleInfo> FactionChangeRestrictions; ///< @todo: research
        };

        class CharacterCreate final : public ClientPacket
        {
        public:
            CharacterCreate(WorldPacket&& packet);

            void Read() override;

            /**
             * @var uint8 Race
             * @var uint8 Class
             * @var uint8 Sex
             * @var uint8 Skin
             * @var uint8 Face
             * @var uint8 HairStyle
             * @var uint8 HairColor
             * @var uint8 FacialHairStyle
             * @var uint8 OutfitId
             * @var Optional<int32> TemplateSet
             * @var std::string Name
             */
            std::shared_ptr<CharacterCreateInfo> CreateInfo;
        };

        class CharacterCreateResponse final : public ServerPacket
        {
        public:
            CharacterCreateResponse();

            WorldPacket const* Write() override;

            uint8 Code = 0; ///< Result code @see enum ResponseCodes
        };

        class CharacterDelete final : public ClientPacket
        {
        public:
            CharacterDelete(WorldPacket&& packet);

            void Read() override;

            ObjectGuid Guid; ///< Guid of the character to delete
        };

        class CharacterDeleteResponse final : public ServerPacket
        {
        public:
            CharacterDeleteResponse();

            WorldPacket const* Write() override;

            uint8 Code = 0; ///< Result code @see enum ResponseCodes
        };

        class GenerateRandomCharacterName final : public ClientPacket
        {
        public:
            GenerateRandomCharacterName(WorldPacket&& packet);
        
            void Read() override;
        
            uint8 Sex = 0;
            uint8 Race = 0;
        };

        class GenerateRandomCharacterNameResult final : public ServerPacket
        {
        public:
            GenerateRandomCharacterNameResult();

            WorldPacket const* Write() override;

            std::string Name;
            bool Success = false;
        };

        class ReorderCharacters final : public ClientPacket
        {
        public:
            struct ReorderInfo
            {
                ObjectGuid PlayerGUID;
                uint8 NewPosition = 0;
            };

            ReorderCharacters(WorldPacket&& packet);

            void Read() override;

            std::list<ReorderInfo> Entries;
        };

        class UndeleteCharacter final : public ClientPacket
        {
        public:
            UndeleteCharacter(WorldPacket&& packet);

            void Read() override;

            /**
             * @var ObjectGuid CharacterGuid
             * @var int32 ClientToken
             */
            std::shared_ptr<CharacterUndeleteInfo> UndeleteInfo;
        };

        class UndeleteCharacterResponse final : public ServerPacket
        {
        public:
            UndeleteCharacterResponse();

            WorldPacket const* Write() override;

            /**
             * @var ObjectGuid CharacterGuid
             * @var int32 ClientToken
             */
            CharacterUndeleteInfo const* UndeleteInfo = nullptr;
            uint32 Result = 0; ///< @see enum CharacterUndeleteResult
        };

        class UndeleteCooldownStatusResponse final : public ServerPacket
        {
        public:
            UndeleteCooldownStatusResponse();

            WorldPacket const* Write() override;

            bool OnCooldown    = false; ///<
            uint32 MaxCooldown     = 0; ///< Max. cooldown until next free character restoration. Displayed in undelete confirm message. (in sec)
            uint32 CurrentCooldown = 0; ///< Current cooldown until next free character restoration. (in sec)
        };

        class PlayerLogin final : public ClientPacket
        {
        public:
            PlayerLogin(WorldPacket&& packet);

            void Read() override;

            ObjectGuid Guid;      ///< Guid of the player that is logging in
            float FarClip = 0.0f; ///< Visibility distance (for terrain)
        };

        class LoginVerifyWorld final : public ServerPacket
        {
        public:
            LoginVerifyWorld() : ServerPacket(SMSG_LOGIN_VERIFY_WORLD, 4 + 4 * 4 + 4) { }

            WorldPacket const* Write() override;

            int32 MapID = -1;
            Position Pos;
            uint32 Reason = 0;
        };
    }
}

#endif // CharacterPackets_h__
