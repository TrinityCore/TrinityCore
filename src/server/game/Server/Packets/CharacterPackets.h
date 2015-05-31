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

#ifndef CharacterPackets_h__
#define CharacterPackets_h__

#include "Packet.h"
#include "Player.h"

namespace WorldPackets
{
    namespace Character
    {
        // Proxy structure to contain data passed to callback function,
        // only to prevent bloating the parameter list
        struct CharacterCreateInfo
        {
            /// User specified variables
            std::string Name;
            uint8 Race = RACE_NONE;
            uint8 Class = CLASS_NONE;
            uint8 Gender = GENDER_NONE;
            uint8 Skin = 0;
            uint8 Face = 0;
            uint8 HairStyle = 0;
            uint8 HairColor = 0;
            uint8 FacialHair = 0;
            uint8 OutfitId = 0;

            /// Server side data
            uint8 CharCount = 0;
        };

        struct CharacterRenameInfo
        {
            std::string NewName;
            ObjectGuid Guid;
        };

        struct CharCustomizeInfo
        {
            uint8 HairStyleID       = 0;
            uint8 FaceID            = 0;
            ObjectGuid CharGUID;
            uint8 SexID             = GENDER_NONE;
            std::string CharName;
            uint8 HairColorID       = 0;
            uint8 FacialHairStyleID = 0;
            uint8 SkinID            = 0;
        };

        struct CharRaceOrFactionChangeInfo
        {
            uint8 HairColorID       = 0;
            uint8 RaceID            = RACE_NONE;
            uint8 SexID             = GENDER_NONE;
            uint8 SkinID            = 0;
            uint8 FacialHairStyleID = 0;
            ObjectGuid Guid;
            bool FactionChange;
            std::string Name;
            uint8 FaceID            = 0;
            uint8 HairStyleID       = 0;
        };

        class EnumCharacters final : public ClientPacket
        {
            public:
                EnumCharacters(WorldPacket&& packet) : ClientPacket(CMSG_CHAR_ENUM, std::move(packet)) { }

                void Read() override { }
        };

        class EnumCharactersResult final : public ServerPacket
        {
            public:
                struct CharacterInfo
                {
                    /**
                    * @fn  void WorldPackets::Character::EnumCharactersResult::CharacterInfo::CharacterInfo(Field* fields);
                    *
                    * @brief   Initialize the struct with values from QueryResult
                    *
                    * @param   fields         Field set of CharacterDatabaseStatements::CHAR_SEL_ENUM
                    */
                    CharacterInfo(Field* fields);

                    ObjectGuid Guid;
                    std::string Name;
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
                    uint32 GuildID           = 0;
                    uint32 Flags             = 0; ///< Character flag @see enum CharacterFlags
                    uint32 CustomizationFlag = 0; ///< Character customization flags @see enum CharacterCustomizeFlags
                    bool FirstLogin      = false;

                    struct PetInfo
                    {
                        uint32 CreatureDisplayId = 0; ///< PetCreatureDisplayID
                        uint32 Level             = 0; ///< PetExperienceLevel
                        uint32 CreatureFamily    = 0; ///< PetCreatureFamilyID
                    } Pet;

                    struct VisualItemInfo
                    {
                        uint32 DisplayId        = 0;
                        uint32 DisplayEnchantId = 0;
                        uint8 InventoryType     = 0;
                    };

                    VisualItemInfo VisualItems[INVENTORY_SLOT_BAG_END];
                };

                EnumCharactersResult() : ServerPacket(SMSG_CHAR_ENUM) { }

                WorldPacket const* Write() override;

                std::list<CharacterInfo> Characters; ///< all characters on the list
        };

        class CreateCharacter final : public ClientPacket
        {
            public:
                CreateCharacter(WorldPacket&& packet) : ClientPacket(CMSG_CHAR_CREATE, std::move(packet)) { }

                void Read() override;

                std::shared_ptr<CharacterCreateInfo> CreateInfo;
        };

        class RenameCharacter final : public ClientPacket
        {
            public:
                RenameCharacter(WorldPacket&& packet) : ClientPacket(CMSG_CHAR_RENAME, std::move(packet)) { }

                void Read() override;

                /**
                * @var std::string NewName
                * @var ObjectGuid Guid
                */
                std::shared_ptr<CharacterRenameInfo> RenameInfo;
        };

        class CharCustomize final : public ClientPacket
        {
            public:
                CharCustomize(WorldPacket&& packet) : ClientPacket(CMSG_CHAR_CUSTOMIZE, std::move(packet)) { }

                void Read() override;

                /**
                 * @var uint8 HairStyleID
                 * @var uint8 FaceID
                 * @var ObjectGuid CharGUID
                 * @var uint8 SexID
                 * @var std::string CharName
                 * @var uint8 HairColorID
                 * @var uint8 FacialHairStyleID
                 * @var uint8 SkinID
                 */
                std::shared_ptr<CharCustomizeInfo> CustomizeInfo;
        };

        class CharRaceOrFactionChange final : public ClientPacket
        {
            public:
                CharRaceOrFactionChange(WorldPacket&& packet) : ClientPacket(std::move(packet))
                {
                    ASSERT(GetOpcode() == CMSG_CHAR_RACE_CHANGE || GetOpcode() == CMSG_CHAR_FACTION_CHANGE);
                }

                void Read() override;

                /**
                * @var uint8 HairColorID
                * @var uint8 RaceID
                * @var uint8 SexID
                * @var uint8 SkinID
                * @var uint8 FacialHairStyleID
                * @var ObjectGuid Guid
                * @var bool FactionChange
                * @var std::string Name
                * @var uint8 FaceID
                * @var uint8 HairStyleID
                */
                std::shared_ptr<CharRaceOrFactionChangeInfo> RaceOrFactionChangeInfo;
        };

        class PlayerLogin final : public ClientPacket
        {
            public:
                PlayerLogin(WorldPacket&& packet) : ClientPacket(CMSG_PLAYER_LOGIN, std::move(packet)) { }

                void Read() override;

                ObjectGuid Guid; ///< Guid of the player that is logging in
        };

        class PlayerLogout final : public ClientPacket
        {
            public:
                PlayerLogout(WorldPacket&& packet) : ClientPacket(CMSG_PLAYER_LOGOUT, std::move(packet)) { }

                void Read() override { }
        };

        class PlayerLogoutRequest final : public ClientPacket
        {
            public:
                PlayerLogoutRequest(WorldPacket&& packet) : ClientPacket(CMSG_LOGOUT_REQUEST, std::move(packet)) { }

                void Read() override { }
        };

        class PlayerLogoutCancel final : public ClientPacket
        {
            public:
                PlayerLogoutCancel(WorldPacket&& packet) : ClientPacket(CMSG_LOGOUT_CANCEL, std::move(packet)) { }

                void Read() override { }
        };

        class PlayerLogoutResponse final : public ServerPacket
        {
            public:
                PlayerLogoutResponse() : ServerPacket(SMSG_LOGOUT_CANCEL_ACK, 0) { }

                WorldPacket const* Write() override { return &_worldPacket; }
        };

        class CharDelete final : public ClientPacket
        {
            public:
                CharDelete(WorldPacket&& packet) : ClientPacket(CMSG_CHAR_DELETE, std::move(packet)) { }

                void Read() override;

                ObjectGuid Guid; ///< Guid of the character to delete
        };
    }
}

#endif // CharacterPackets_h__
