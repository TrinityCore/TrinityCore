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
        class EnumCharacters final : public ClientPacket
        {
        public:
            EnumCharacters(WorldPacket&& packet) : ClientPacket(std::move(packet))
            {
                ASSERT(GetOpcode() == CMSG_CHAR_ENUM || GetOpcode() == CMSG_CHAR_UNDELETE_ENUM);
            }

            void Read() override { }
        };

        struct CharacterCreateInfo
        {
            /// User specified variables
            uint8 Race            = RACE_NONE;
            uint8 Class           = CLASS_NONE;
            uint8 Sex             = GENDER_NONE;
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
            Optional<uint8> HairColorID;
            uint8 RaceID            = RACE_NONE;
            uint8 SexID             = GENDER_NONE;
            Optional<uint8> SkinID;
            Optional<uint8> FacialHairStyleID;
            ObjectGuid Guid;
            bool FactionChange      = false;
            std::string Name;
            Optional<uint8> FaceID;
            Optional<uint8> HairStyleID;
        };

        struct CharacterUndeleteInfo
        {
            /// User specified variables
            ObjectGuid CharacterGuid; ///< Guid of the character to restore
            int32 ClientToken    = 0; ///< @todo: research

            /// Server side data
            std::string Name;
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
                uint8 unkWod61x          = 0;

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

            EnumCharactersResult() : ServerPacket(SMSG_CHAR_ENUM) { }

            WorldPacket const* Write() override;

            bool Success                = false; ///<
            bool IsDeletedCharacters    = false; ///< used for character undelete list

            std::list<CharacterInfo> Characters; ///< all characters on the list
            std::list<RestrictedFactionChangeRuleInfo> FactionChangeRestrictions; ///< @todo: research
        };

        class CreateChar final : public ClientPacket
        {
        public:
            CreateChar(WorldPacket&& packet) : ClientPacket(CMSG_CHAR_CREATE, std::move(packet)) { }

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
            CharacterCreateResponse() : ServerPacket(SMSG_CHAR_CREATE, 1) { }

            WorldPacket const* Write() override;

            uint8 Code = 0; ///< Result code @see enum ResponseCodes
        };

        class DeleteChar final : public ClientPacket
        {
        public:
            DeleteChar(WorldPacket&& packet): ClientPacket(CMSG_CHAR_DELETE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid; ///< Guid of the character to delete
        };

        class CharacterDeleteResponse final : public ServerPacket
        {
        public:
            CharacterDeleteResponse(): ServerPacket(SMSG_CHAR_DELETE, 1) { }

            WorldPacket const* Write() override;

            uint8 Code = 0; ///< Result code @see enum ResponseCodes
        };

        class CharacterRenameRequest final : public ClientPacket
        {
        public:
            CharacterRenameRequest(WorldPacket&& packet) : ClientPacket(CMSG_CHAR_RENAME, std::move(packet)) { }

            void Read() override;

            /**
             * @var std::string NewName
             * @var ObjectGuid Guid
             */
            std::shared_ptr<CharacterRenameInfo> RenameInfo;
        };

        class CharacterRenameResult final : public ServerPacket
        {
        public:
            CharacterRenameResult() : ServerPacket(SMSG_CHAR_RENAME, 20) { }

            WorldPacket const* Write() override;

            std::string Name;
            uint8 Result = 0;
            Optional<ObjectGuid> Guid;
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

        /// @todo: CharCustomizeResult

        class CharRaceOrFactionChange final : public ClientPacket
        {
        public:
            CharRaceOrFactionChange(WorldPacket&& packet) : ClientPacket(CMSG_CHAR_RACE_OR_FACTION_CHANGE, std::move(packet)) { }

            void Read() override;

            /**
             * @var Optional<uint8> HairColorID
             * @var uint8 RaceID
             * @var uint8 SexID
             * @var Optional<uint8> SkinID
             * @var Optional<uint8> FacialHairStyleID
             * @var ObjectGuid Guid
             * @var bool FactionChange
             * @var std::string Name
             * @var Optional<uint8> FaceID
             * @var Optional<uint8> HairStyleID
             */
            std::shared_ptr<CharRaceOrFactionChangeInfo> RaceOrFactionChangeInfo;
        };

        class CharFactionChangeResult final : public ServerPacket
        {
        public:
            struct CharFactionChangeDisplayInfo
            {
                std::string Name;
                uint8 SexID             = 0;
                uint8 SkinID            = 0;
                uint8 HairColorID       = 0;
                uint8 HairStyleID       = 0;
                uint8 FacialHairStyleID = 0;
                uint8 FaceID            = 0;
                uint8 RaceID            = RACE_NONE;
            };

            CharFactionChangeResult() : ServerPacket(SMSG_CHAR_FACTION_CHANGE, 20 + sizeof(CharFactionChangeDisplayInfo)) { }

            WorldPacket const* Write() override;

            uint8 Result = 0; ///< @see enum ResponseCodes
            ObjectGuid Guid;
            Optional<CharFactionChangeDisplayInfo> Display;
        };

        class GenerateRandomCharacterName final : public ClientPacket
        {
        public:
            GenerateRandomCharacterName(WorldPacket&& packet) : ClientPacket(CMSG_RANDOMIZE_CHAR_NAME, std::move(packet)) { }

            void Read() override;

            uint8 Sex = 0;
            uint8 Race = 0;
        };

        class GenerateRandomCharacterNameResult final : public ServerPacket
        {
        public:
            GenerateRandomCharacterNameResult() : ServerPacket(SMSG_RANDOMIZE_CHAR_NAME, 20) { }

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

            ReorderCharacters(WorldPacket&& packet) : ClientPacket(CMSG_REORDER_CHARACTERS, std::move(packet)) { }

            void Read() override;

            std::list<ReorderInfo> Entries;
        };

        class UndeleteCharacter final : public ClientPacket
        {
        public:
            UndeleteCharacter(WorldPacket&& packet) : ClientPacket(CMSG_UNDELETE_CHARACTER, std::move(packet)) { }

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
            UndeleteCharacterResponse() : ServerPacket(SMSG_UNDELETE_CHARACTER_RESPONSE, 26) { }

            WorldPacket const* Write() override;

            /**
             * @var ObjectGuid CharacterGuid
             * @var int32 ClientToken
             */
            CharacterUndeleteInfo const* UndeleteInfo = nullptr;
            uint32 Result = 0; ///< @see enum CharacterUndeleteResult
        };

        class GetUndeleteCooldownStatus final : public ClientPacket
        {
        public:
            GetUndeleteCooldownStatus(WorldPacket&& packet) : ClientPacket(CMSG_GET_UNDELETE_COOLDOWN_STATUS, std::move(packet)) { }

            void Read() override { }
        };

        class UndeleteCooldownStatusResponse final : public ServerPacket
        {
        public:
            UndeleteCooldownStatusResponse() : ServerPacket(SMSG_UNDELETE_COOLDOWN_STATUS_RESPONSE, 9) { }

            WorldPacket const* Write() override;

            bool OnCooldown    = false; ///<
            uint32 MaxCooldown     = 0; ///< Max. cooldown until next free character restoration. Displayed in undelete confirm message. (in sec)
            uint32 CurrentCooldown = 0; ///< Current cooldown until next free character restoration. (in sec)
        };

        class PlayerLogin final : public ClientPacket
        {
        public:
            PlayerLogin(WorldPacket&& packet) : ClientPacket(CMSG_PLAYER_LOGIN, std::move(packet)) { }

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

        enum class LoginFailureReason : uint8
        {
            Failed                          = 0,
            NoWorld                         = 1,
            DuplicateCharacter              = 2,
            NoInstances                     = 3,
            Disabled                        = 4,
            NoCharacter                     = 5,
            LockedForTransfer               = 6,
            LockedByBilling                 = 7,
            LockedByMobileAH                = 8,
            TemporaryGMLock                 = 9,
            LockedByCharacterUpgrade        = 10,
            LockedByRevokedCharacterUpgrade = 11
        };

        class CharacterLoginFailed  final : public ServerPacket
        {
        public:
            CharacterLoginFailed(LoginFailureReason code) : ServerPacket(SMSG_CHARACTER_LOGIN_FAILED, 1), Code(code) { }

            WorldPacket const* Write() override;

            LoginFailureReason Code = LoginFailureReason::Failed;
        };

        class LogoutRequest final : public ClientPacket
        {
        public:
            LogoutRequest(WorldPacket&& packet) : ClientPacket(CMSG_LOGOUT_REQUEST, std::move(packet)) { }

            void Read() override { }
        };

        class LogoutResponse final : public ServerPacket
        {
        public:
            LogoutResponse() : ServerPacket(SMSG_LOGOUT_RESPONSE, 4 + 1) { }

            WorldPacket const* Write() override;

            int32 LogoutResult = 0;
            bool Instant = false;
        };

        class LogoutComplete final : public ServerPacket
        {
        public:
            LogoutComplete() : ServerPacket(SMSG_LOGOUT_COMPLETE, 2) { }

            WorldPacket const* Write() override;

            ObjectGuid SwitchToCharacter;
        };

        class LogoutCancel final : public ClientPacket
        {
        public:
            LogoutCancel(WorldPacket&& packet) : ClientPacket(CMSG_LOGOUT_CANCEL, std::move(packet)) { }

            void Read() override { }
        };

        class LogoutCancelAck final : public ServerPacket
        {
        public:
            LogoutCancelAck() : ServerPacket(SMSG_LOGOUT_CANCEL_ACK, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        class LoadingScreenNotify final : public ClientPacket
        {
        public:
            LoadingScreenNotify(WorldPacket&& packet) : ClientPacket(CMSG_LOAD_SCREEN, std::move(packet)) { }

            void Read() override;

            int32 MapID = -1;
            bool Showing = false;
        };

        class InitialSetup final : public ServerPacket
        {
        public:
            InitialSetup() : ServerPacket(SMSG_INITIAL_SETUP, 1 + 1 + 4 + QUESTS_COMPLETED_BITS_SIZE + 4)
            {
                QuestsCompleted.reserve(QUESTS_COMPLETED_BITS_SIZE);
            }

            WorldPacket const* Write() override;

            uint8 ServerExpansionTier = 0;
            uint8 ServerExpansionLevel = 0;
            time_t RaidOrigin = time_t(1135753200); // 28/12/2005 07:00:00
            std::vector<uint8> QuestsCompleted;
            int32 ServerRegionID = 3;   // Cfg_Regions.dbc, EU
        };

        class SetActionBarToggles final : public ClientPacket
        {
        public:
            SetActionBarToggles(WorldPacket&& packet) : ClientPacket(CMSG_SET_ACTIONBAR_TOGGLES, std::move(packet)) { }

            void Read() override;

            uint8 Mask = 0;
        };
    }
}

#endif // CharacterPackets_h__
