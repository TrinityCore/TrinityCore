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

#ifndef CharacterPackets_h__
#define CharacterPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "Position.h"
#include <array>

class Field;

namespace WorldPackets
{
    namespace Character
    {
        class EnumCharacters final : public ClientPacket
        {
        public:
            EnumCharacters(WorldPacket&& packet) : ClientPacket(CMSG_ENUM_CHARACTERS, std::move(packet)) { }

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

                struct VisualItemInfo
                {
                    uint32 DisplayID = 0;
                    uint32 DisplayEnchantID = 0;
                    uint8 InvType = 0;
                };

                Position PreloadPos;
                ObjectGuid Guid;
                ObjectGuid GuildGUID;
                uint32 Flags = 0;       ///< Character flag @see enum CharacterFlags
                uint32 Flags2 = 0;      ///< Character customization flags @see enum CharacterCustomizeFlags
                int32 MapID = 0;
                uint32 PetCreatureDisplayID = 0;
                uint32 PetCreatureFamilyID = 0;
                uint32 PetExperienceLevel = 0;
                int32 ZoneID = 0;
                uint8 ClassID = 0;
                uint8 ExperienceLevel = 0;
                uint8 FaceID = 0;
                uint8 FacialHair = 0;
                uint8 HairColor = 0;
                uint8 HairStyle = 0;
                uint8 ListPosition = 0; ///< Order of the characters in list
                uint8 RaceID = 0;
                uint8 SexID = 0;
                uint8 SkinID = 0;
                bool FirstLogin = false;
                std::string Name;
                std::array<VisualItemInfo, 23> VisualItems = { };
            };

            struct RestrictedFactionChangeRuleInfo
            {
                RestrictedFactionChangeRuleInfo(int32 mask, uint8 race)
                    : Mask(mask), Race(race) { }

                int32 Mask = 0;
                uint8 Race = 0;
            };

            EnumCharactersResult() : ServerPacket(SMSG_ENUM_CHARACTERS_RESULT) { }

            WorldPacket const* Write() override;

            bool Success = false; ///<

            std::vector<CharacterInfo> Characters; ///< all characters on the list
            std::vector<RestrictedFactionChangeRuleInfo> FactionChangeRestrictions; ///< @todo: research
        };

        enum class LoginFailureReason : uint8
        {
            Failed             = 0,
            NoWorld            = 1,
            DuplicateCharacter = 2,
            NoInstances        = 3,
            Disabled           = 4,
            NoCharacter        = 5,
            LockedForTransfer  = 6,
            LockedByBilling    = 7,
            LockedByMobileAH   = 8,
            TemporaryGMLock    = 9
        };

        class CharacterLoginFailed final : public ServerPacket
        {
        public:
            CharacterLoginFailed(LoginFailureReason code) : ServerPacket(SMSG_CHARACTER_LOGIN_FAILED, 1), Code(code) { }

            WorldPacket const* Write() override;

            LoginFailureReason Code = LoginFailureReason::Failed;
        };

        class ShowingCloak final : public ClientPacket
        {
        public:
            ShowingCloak(WorldPacket&& packet) : ClientPacket(CMSG_SHOWING_CLOAK, std::move(packet)) { }

            void Read() override;

            bool ShowCloak = false;
        };

        class ShowingHelm final : public ClientPacket
        {
        public:
            ShowingHelm(WorldPacket&& packet) : ClientPacket(CMSG_SHOWING_HELM, std::move(packet)) { }

            void Read() override;

            bool ShowHelm = false;
        };

        class LoginVerifyWorld final : public ServerPacket
        {
        public:
            LoginVerifyWorld() : ServerPacket(SMSG_LOGIN_VERIFY_WORLD, 4 + 4 * 4) { }

            WorldPacket const* Write() override;

            int32 MapID = -1;
            TaggedPosition<Position::XYZO> Pos;
        };

        class GenerateRandomCharacterName final : public ClientPacket
        {
        public:
            GenerateRandomCharacterName(WorldPacket&& packet) : ClientPacket(CMSG_GENERATE_RANDOM_CHARACTER_NAME, std::move(packet)) { }

            void Read() override;

            uint8 Sex = 0;
            uint8 Race = 0;
        };

        class GenerateRandomCharacterNameResult final : public ServerPacket
        {
        public:
            GenerateRandomCharacterNameResult() : ServerPacket(SMSG_GENERATE_RANDOM_CHARACTER_NAME_RESULT, 10) { }

            WorldPacket const* Write() override;

            std::string Name;
            bool Success = false;
        };

        class CreateChar final : public ServerPacket
        {
        public:
            CreateChar() : ServerPacket(SMSG_CREATE_CHAR, 1) { }

            WorldPacket const* Write() override;

            uint8 Code = 0; ///< Result code @see enum ResponseCodes
        };

        class CharDelete final : public ClientPacket
        {
        public:
            CharDelete(WorldPacket&& packet) : ClientPacket(CMSG_CHAR_DELETE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid; ///< Guid of the character to delete
        };

        class DeleteChar final : public ServerPacket
        {
        public:
            DeleteChar() : ServerPacket(SMSG_DELETE_CHAR, 1) { }

            WorldPacket const* Write() override;

            uint8 Code = 0; ///< Result code @see enum ResponseCodes
        };

        class PlayerLogin final : public ClientPacket
        {
        public:
            PlayerLogin(WorldPacket&& packet) : ClientPacket(CMSG_PLAYER_LOGIN, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid;      ///< Guid of the player that is logging in
        };

        class LogXPGain final : public ServerPacket
        {
        public:
            LogXPGain() : ServerPacket(SMSG_LOG_XP_GAIN, 30) { }

            WorldPacket const* Write() override;

            ObjectGuid Victim;
            int32 Original = 0;
            int32 Amount = 0;
            float GroupBonus = 0;
            uint8 Reason = 0;
            uint8 ReferAFriendBonusType = 0;    // 1 - 300% of normal XP; 2 - 150% of normal XP
        };

        class PlayedTime final : public ServerPacket
        {
        public:
            PlayedTime() : ServerPacket(SMSG_PLAYED_TIME, 9) { }

            WorldPacket const* Write() override;

            int32 TotalTime = 0;
            int32 LevelTime = 0;
            bool TriggerEvent = false;
        };

        class LoadingScreenNotify final : public ClientPacket
        {
        public:
            LoadingScreenNotify(WorldPacket&& packet) : ClientPacket(CMSG_LOADING_SCREEN_NOTIFY, std::move(packet)) { }

            void Read() override;

            int32 MapID = -1;
            bool Showing = false;
        };

        class FailedPlayerCondition final : public ServerPacket
        {
        public:
            FailedPlayerCondition() : ServerPacket(SMSG_FAILED_PLAYER_CONDITION, 4) { }

            WorldPacket const* Write() override;

            int32 ConditionID = 0;
        };
    }
}

#endif // CharacterPackets_h__
