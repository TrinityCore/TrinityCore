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
#include "Optional.h"
#include "PacketUtilities.h"
#include "Position.h"
#include "RaceMask.h"
#include "SharedDefines.h"
#include "UnitDefines.h"
#include <array>
#include <memory>

class Field;

namespace WorldPackets
{
    namespace Character
    {
        class EnumCharacters final : public ClientPacket
        {
        public:
            EnumCharacters(WorldPacket&& packet);

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
            std::array<uint8, PLAYER_CUSTOM_DISPLAY_SIZE> CustomDisplay = { };
            uint8 OutfitId        = 0;
            Optional<int32> TemplateSet;
            bool IsTrialBoost     = false;
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
            std::array<uint8, PLAYER_CUSTOM_DISPLAY_SIZE> CustomDisplay = { };
        };

        struct CharRaceOrFactionChangeInfo
        {
            uint8 HairColorID       = 0;
            uint8 RaceID            = RACE_NONE;
            uint8 SexID             = GENDER_NONE;
            uint8 SkinID            = 0;
            uint8 FacialHairStyleID = 0;
            ObjectGuid Guid;
            bool FactionChange      = false;
            std::string Name;
            uint8 FaceID            = 0;
            uint8 HairStyleID       = 0;
            std::array<uint8, PLAYER_CUSTOM_DISPLAY_SIZE> CustomDisplay = { };
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
                uint64 GuildClubMemberID = 0; ///< same as bgs.protocol.club.v1.MemberId.unique_id, guessed basing on SMSG_QUERY_PLAYER_NAME_RESPONSE (that one is known)
                std::string Name;
                uint8 ListPosition       = 0; ///< Order of the characters in list
                uint8 RaceID             = 0;
                uint8 ClassID            = 0;
                uint8 SexID              = 0;
                uint8 SkinID             = 0;
                uint8 FaceID             = 0;
                uint8 HairStyle          = 0;
                uint8 HairColor          = 0;
                uint8 FacialHair         = 0;
                std::array<uint8, PLAYER_CUSTOM_DISPLAY_SIZE> CustomDisplay = { };
                uint8 ExperienceLevel    = 0;
                int32 ZoneID             = 0;
                int32 MapID              = 0;
                TaggedPosition<Position::XYZ> PreloadPos;
                ObjectGuid GuildGUID;
                uint32 Flags             = 0; ///< Character flag @see enum CharacterFlags
                uint32 Flags2            = 0; ///< Character customization flags @see enum CharacterCustomizeFlags
                uint32 Flags3            = 0; ///< Character flags 3 @todo research
                uint32 Flags4            = 0;
                bool FirstLogin      = false;
                uint8 unkWod61x          = 0;
                uint32 LastPlayedTime    = 0;
                uint16 SpecID            = 0;
                uint32 Unknown703        = 0;
                uint32 LastLoginVersion  = 0;

                uint32 PetCreatureDisplayID = 0;
                uint32 PetExperienceLevel   = 0;
                uint32 PetCreatureFamilyID  = 0;

                bool BoostInProgress = false; ///< @todo
                int32 ProfessionIds[2] = { }; ///< @todo

                struct VisualItemInfo
                {
                    uint32 DisplayID        = 0;
                    uint32 DisplayEnchantID = 0;
                    uint8 InvType           = 0;
                    uint8 Subclass          = 0;
                };

                std::array<VisualItemInfo, 23> VisualItems = { };
                std::vector<std::string> Unknown830; // Something with character names, same length limit as name,
                                                     // client accepts unlimited number of these in packet but only uses first 3
            };

            struct RaceUnlock
            {
                int32 RaceID          = 0;
                bool HasExpansion     = false;
                bool HasAchievement   = false;
                bool HasHeritageArmor = false;
            };

            struct UnlockedConditionalAppearance
            {
                int32 AchievementID = 0;
                int32 Unused = 0;
            };

            EnumCharactersResult() : ServerPacket(SMSG_ENUM_CHARACTERS_RESULT) { }

            WorldPacket const* Write() override;

            bool Success                          = false; ///<
            bool IsDeletedCharacters              = false; ///< used for character undelete list
            bool IsTestDemonHunterCreationAllowed = false; ///< allows client to skip 1 per realm and level 70 requirements
            bool HasDemonHunterOnRealm            = false;
            bool IsDemonHunterCreationAllowed     = false; ///< used for demon hunter early access
            bool IsAlliedRacesCreationAllowed     = false;

            int32 MaxCharacterLevel     = 1;
            Optional<uint32> DisabledClassesMask;

            std::vector<CharacterInfo> Characters; ///< all characters on the list
            std::vector<RaceUnlock> RaceUnlockData; ///<
            std::vector<UnlockedConditionalAppearance> UnlockedConditionalAppearances;
        };

        class CreateCharacter final : public ClientPacket
        {
        public:
            CreateCharacter(WorldPacket&& packet) : ClientPacket(CMSG_CREATE_CHARACTER, std::move(packet)) { }

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

        class CreateChar final : public ServerPacket
        {
        public:
            CreateChar() : ServerPacket(SMSG_CREATE_CHAR, 1) { }

            WorldPacket const* Write() override;

            uint8 Code = 0; ///< Result code @see enum ResponseCodes
            ObjectGuid Guid;
        };

        class CharDelete final : public ClientPacket
        {
        public:
            CharDelete(WorldPacket&& packet): ClientPacket(CMSG_CHAR_DELETE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid; ///< Guid of the character to delete
        };

        class DeleteChar final : public ServerPacket
        {
        public:
            DeleteChar(): ServerPacket(SMSG_DELETE_CHAR, 1) { }

            WorldPacket const* Write() override;

            uint8 Code = 0; ///< Result code @see enum ResponseCodes
        };

        class CharacterRenameRequest final : public ClientPacket
        {
        public:
            CharacterRenameRequest(WorldPacket&& packet) : ClientPacket(CMSG_CHARACTER_RENAME_REQUEST, std::move(packet)) { }

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
            CharacterRenameResult() : ServerPacket(SMSG_CHARACTER_RENAME_RESULT, 20) { }

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
                std::array<uint8, PLAYER_CUSTOM_DISPLAY_SIZE> CustomDisplay = { };
            };

            CharFactionChangeResult() : ServerPacket(SMSG_CHAR_FACTION_CHANGE_RESULT, 20 + sizeof(CharFactionChangeDisplayInfo)) { }

            WorldPacket const* Write() override;

            uint8 Result = 0; ///< @see enum ResponseCodes
            ObjectGuid Guid;
            Optional<CharFactionChangeDisplayInfo> Display;
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
            GenerateRandomCharacterNameResult() : ServerPacket(SMSG_GENERATE_RANDOM_CHARACTER_NAME_RESULT, 20) { }

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

            Array<ReorderInfo, MAX_CHARACTERS_PER_REALM> Entries;
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

        class GetUndeleteCharacterCooldownStatus final : public ClientPacket
        {
        public:
            GetUndeleteCharacterCooldownStatus(WorldPacket&& packet) : ClientPacket(CMSG_GET_UNDELETE_CHARACTER_COOLDOWN_STATUS, std::move(packet)) { }

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
            TaggedPosition<Position::XYZO> Pos;
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

            void Read() override;

            bool IdleLogout = false;
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
            LogoutComplete() : ServerPacket(SMSG_LOGOUT_COMPLETE, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
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
            LoadingScreenNotify(WorldPacket&& packet) : ClientPacket(CMSG_LOADING_SCREEN_NOTIFY, std::move(packet)) { }

            void Read() override;

            int32 MapID = -1;
            bool Showing = false;
        };

        class InitialSetup final : public ServerPacket
        {
        public:
            InitialSetup() : ServerPacket(SMSG_INITIAL_SETUP, 1 + 1) { }

            WorldPacket const* Write() override;

            uint8 ServerExpansionTier = 0;
            uint8 ServerExpansionLevel = 0;
        };

        class SetActionBarToggles final : public ClientPacket
        {
        public:
            SetActionBarToggles(WorldPacket&& packet) : ClientPacket(CMSG_SET_ACTION_BAR_TOGGLES, std::move(packet)) { }

            void Read() override;

            uint8 Mask = 0;
        };

        class RequestPlayedTime final : public ClientPacket
        {
        public:
            RequestPlayedTime(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_PLAYED_TIME, std::move(packet)) { }

            void Read() override;

            bool TriggerScriptEvent = false;
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

        class SetTitle final : public ClientPacket
        {
        public:
            SetTitle(WorldPacket&& packet) : ClientPacket(CMSG_SET_TITLE, std::move(packet)) { }

            void Read() override;

            int32 TitleID = 0;
        };

        class AlterApperance final : public ClientPacket
        {
        public:
            AlterApperance(WorldPacket&& packet) : ClientPacket(CMSG_ALTER_APPEARANCE, std::move(packet)) { }

            void Read() override;

            uint32 NewHairStyle = 0;
            uint32 NewHairColor = 0;
            uint32 NewFacialHair = 0;
            uint32 NewSkinColor = 0;
            uint32 NewFace = 0;
            std::array<uint32, PLAYER_CUSTOM_DISPLAY_SIZE> NewCustomDisplay = { };
        };

        class BarberShopResult final : public ServerPacket
        {
        public:
            enum class ResultEnum : uint8
            {
                Success = 0,
                NoMoney = 1,
                NotOnChair = 2,
                NoMoney2 = 3
            };

            BarberShopResult(ResultEnum result) : ServerPacket(SMSG_BARBER_SHOP_RESULT, 4), Result(result) { }

            WorldPacket const* Write() override;

            ResultEnum Result = ResultEnum::Success;
        };

        class LogXPGain final : public ServerPacket
        {
        public:
            LogXPGain() : ServerPacket(SMSG_LOG_XP_GAIN, 30) { }

            WorldPacket const* Write() override;

            ObjectGuid Victim;
            int32 Original = 0;
            uint8 Reason = 0;
            int32 Amount = 0;
            float GroupBonus = 0;
            uint8 ReferAFriendBonusType = 0;    // 1 - 300% of normal XP; 2 - 150% of normal XP
        };

        class TitleEarned final : public ServerPacket
        {
        public:
            TitleEarned(OpcodeServer opcode) : ServerPacket(opcode, 4) { }

            WorldPacket const* Write() override;

            uint32 Index = 0;
        };

        class SetFactionAtWar final : public ClientPacket
        {
        public:
            SetFactionAtWar(WorldPacket&& packet) : ClientPacket(CMSG_SET_FACTION_AT_WAR, std::move(packet)) { }

            void Read() override;

            uint8 FactionIndex = 0;
        };

        class SetFactionNotAtWar final : public ClientPacket
        {
        public:
            SetFactionNotAtWar(WorldPacket&& packet) : ClientPacket(CMSG_SET_FACTION_NOT_AT_WAR, std::move(packet)) { }

            void Read() override;

            uint8 FactionIndex = 0;
        };

        class SetFactionInactive final : public ClientPacket
        {
        public:
            SetFactionInactive(WorldPacket&& packet) : ClientPacket(CMSG_SET_FACTION_INACTIVE, std::move(packet)) { }

            void Read() override;

            uint32 Index = 0;
            bool State = false;
        };

        class SetWatchedFaction final : public ClientPacket
        {
        public:
            SetWatchedFaction(WorldPacket&& packet) : ClientPacket(CMSG_SET_WATCHED_FACTION, std::move(packet)) { }

            void Read() override;

            uint32 FactionIndex = 0;
        };

        class SetFactionVisible : public ServerPacket
        {
        public:
            SetFactionVisible(bool visible) : ServerPacket(visible ? SMSG_SET_FACTION_VISIBLE : SMSG_SET_FACTION_NOT_VISIBLE, 4) { }

            WorldPacket const* Write() override;

            uint32 FactionIndex = 0;
        };

        class CharCustomizeResponse final : public ServerPacket
        {
        public:
            CharCustomizeResponse() : ServerPacket(SMSG_CHAR_CUSTOMIZE, 16 + 1 + 1 + 1 + 1 + 1 + 1 + 1) { }
            CharCustomizeResponse(CharCustomizeInfo const* customizeInfo);

            WorldPacket const* Write() override;

            ObjectGuid CharGUID;
            std::string CharName;
            uint8 SexID = 0;
            uint8 SkinID = 0;
            uint8 HairColorID = 0;
            uint8 HairStyleID = 0;
            uint8 FacialHairStyleID = 0;
            uint8 FaceID = 0;
            std::array<uint8, PLAYER_CUSTOM_DISPLAY_SIZE> CustomDisplay = { };
        };

        class CharCustomizeFailed final : public ServerPacket
        {
        public:
            CharCustomizeFailed() : ServerPacket(SMSG_CHAR_CUSTOMIZE_FAILED, 1 + 16) { }

            WorldPacket const* Write() override;

            uint8 Result = 0;
            ObjectGuid CharGUID;
        };

        class SetPlayerDeclinedNames final : public ClientPacket
        {
        public:
            SetPlayerDeclinedNames(WorldPacket&& packet) : ClientPacket(CMSG_SET_PLAYER_DECLINED_NAMES, std::move(packet)) { }

            void Read() override;

            ObjectGuid Player;
            DeclinedName DeclinedNames;
        };

        class SetPlayerDeclinedNamesResult final : public ServerPacket
        {
        public:
            SetPlayerDeclinedNamesResult() : ServerPacket(SMSG_SET_PLAYER_DECLINED_NAMES_RESULT, 8 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid Player;
            int32 ResultCode = 0;
        };
    }
}

#endif // CharacterPackets_h__
