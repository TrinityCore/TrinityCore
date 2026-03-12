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
#include "SharedDefines.h"
#include <memory>

namespace WorldPackets
{
    namespace Character
    {
        struct CharacterCreateInfo
        {
            /// User specified variables
            uint8 Race            = 0;
            uint8 Class           = 0;
            uint8 Sex             = GENDER_NONE;
            uint8 Skin            = 0;
            uint8 Face            = 0;
            uint8 HairStyle       = 0;
            uint8 HairColor       = 0;
            uint8 FacialHairStyle = 0;
            uint8 OutfitId        = 0;
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
        };

        class CreateCharacter final : public ClientPacket
        {
        public:
            explicit CreateCharacter(WorldPacket&& packet) : ClientPacket(CMSG_CHAR_CREATE, std::move(packet)) { }

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
            * @var std::string Name
            */
            std::shared_ptr<CharacterCreateInfo> CreateInfo;
        };

        class CreateChar final : public ServerPacket
        {
        public:
            explicit CreateChar() : ServerPacket(SMSG_CHAR_CREATE, 1) { }

            WorldPacket const* Write() override;

            uint8 Code = 0; ///< Result code @see enum ResponseCodes
        };

        class CharDelete final : public ClientPacket
        {
        public:
            explicit CharDelete(WorldPacket&& packet) : ClientPacket(CMSG_CHAR_DELETE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid; ///< Guid of the character to delete
        };

        class DeleteChar final : public ServerPacket
        {
        public:
            explicit DeleteChar() : ServerPacket(SMSG_CHAR_DELETE, 1) { }

            WorldPacket const* Write() override;

            uint8 Code = 0; ///< Result code @see enum ResponseCodes
        };

        class CharacterRenameRequest final : public ClientPacket
        {
        public:
            explicit CharacterRenameRequest(WorldPacket&& packet) : ClientPacket(CMSG_CHAR_RENAME, std::move(packet)) { }

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
            explicit CharacterRenameResult() : ServerPacket(SMSG_CHAR_RENAME, 20) { }

            WorldPacket const* Write() override;

            std::string_view Name;
            uint8 Result = 0;
            ObjectGuid Guid;
        };

        class CharCustomize final : public ClientPacket
        {
        public:
            explicit CharCustomize(WorldPacket&& packet) : ClientPacket(CMSG_CHAR_CUSTOMIZE, std::move(packet)) { }

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

        class CharCustomizeResult final : public ServerPacket
        {
        public:
            explicit CharCustomizeResult() : ServerPacket(SMSG_CHAR_CUSTOMIZE, 1 + 8 + 16 + 1 + 6) { }

            WorldPacket const* Write() override;

            uint8 Code = 0; ///< Result code @see enum ResponseCodes
            CharCustomizeInfo const* CustomizeInfo = nullptr;
        };

        class CharRaceOrFactionChange final : public ClientPacket
        {
        public:
            explicit CharRaceOrFactionChange(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

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

        class CharFactionChangeResult final : public ServerPacket
        {
        public:
            explicit CharFactionChangeResult() : ServerPacket(SMSG_CHAR_FACTION_CHANGE, 1 + sizeof(CharRaceOrFactionChangeInfo)) { }

            WorldPacket const* Write() override;

            uint8 Result = 0; ///< @see enum ResponseCodes
            CharRaceOrFactionChangeInfo const* RaceOrFactionChangeInfo = nullptr;
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

        class LogoutRequest final : public ClientPacket
        {
        public:
            LogoutRequest(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

            void Read() override { }
        };

        class LogoutResponse final : public ServerPacket
        {
        public:
            LogoutResponse() : ServerPacket(SMSG_LOGOUT_RESPONSE, 4 + 1) { }

            WorldPacket const* Write() override;

            uint32 LogoutResult = 0;
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
            LogoutCancel(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

            void Read() override { }
        };

        class LogoutCancelAck final : public ServerPacket
        {
        public:
            LogoutCancelAck() : ServerPacket(SMSG_LOGOUT_CANCEL_ACK, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        class PlayerLogout final : public ClientPacket
        {
        public:
            PlayerLogout(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

            void Read() override { }
        };

        class PlayedTimeClient final : public ClientPacket
        {
        public:
            PlayedTimeClient(WorldPacket&& packet) : ClientPacket(CMSG_PLAYED_TIME, std::move(packet)) { }

            void Read() override;

            bool TriggerScriptEvent = false;
        };

        class PlayedTime final : public ServerPacket
        {
        public:
            PlayedTime() : ServerPacket(SMSG_PLAYED_TIME, 9) { }

            WorldPacket const* Write() override;

            uint32 TotalTime = 0;
            uint32 LevelTime = 0;
            bool TriggerScriptEvent = false;
        };
    }
}

#endif // CharacterPackets_h__
