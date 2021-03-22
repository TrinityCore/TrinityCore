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

#ifndef PetitionPackets_h__
#define PetitionPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "WorldSession.h"

namespace WorldPackets
{
    namespace Petition
    {
        class QueryPetition final : public ClientPacket
        {
        public:
            QueryPetition(WorldPacket&& packet) : ClientPacket(CMSG_QUERY_PETITION, std::move(packet)) { }

            void Read() override;

            ObjectGuid ItemGUID;
            uint32 PetitionID = 0;
        };

        struct PetitionInfo
        {
            int32 PetitionID = 0;
            ObjectGuid Petitioner;
            std::string Title;
            std::string BodyText;
            int32 MinSignatures = 0;
            int32 MaxSignatures = 0;
            int32 DeadLine = 0;
            int32 IssueDate = 0;
            int32 AllowedGuildID = 0;
            int32 AllowedClasses = 0;
            int32 AllowedRaces = 0;
            int16 AllowedGender = 0;
            int32 AllowedMinLevel = 0;
            int32 AllowedMaxLevel = 0;
            int32 NumChoices = 0;
            int32 StaticType = 0;
            uint32 Muid = 0;
            std::array<std::string, 10> Choicetext;
        };

        class QueryPetitionResponse final : public ServerPacket
        {
        public:
            QueryPetitionResponse() : ServerPacket(SMSG_QUERY_PETITION_RESPONSE, 75) { }

            WorldPacket const* Write() override;

            uint32 PetitionID = 0;
            bool Allow = false;
            PetitionInfo Info;
        };

        class PetitionShowList final : public ClientPacket
        {
        public:
            PetitionShowList(WorldPacket&& packet) : ClientPacket(CMSG_PETITION_SHOW_LIST, std::move(packet)) { }

            void Read() override;

            ObjectGuid PetitionUnit;
        };

        class ServerPetitionShowList final : public ServerPacket
        {
        public:
            ServerPetitionShowList() : ServerPacket(SMSG_PETITION_SHOW_LIST, 20) { }

            WorldPacket const* Write() override;

            ObjectGuid Unit;
            uint32 Price = 0;
        };

        class PetitionBuy final : public ClientPacket
        {
        public:
            PetitionBuy(WorldPacket&& packet) : ClientPacket(CMSG_PETITION_BUY, std::move(packet)) { }

            void Read() override;

            ObjectGuid Unit;
            std::string Title;
        };

        class PetitionShowSignatures final : public ClientPacket
        {
        public:
            PetitionShowSignatures(WorldPacket&& packet) : ClientPacket(CMSG_PETITION_SHOW_SIGNATURES, std::move(packet)) { }

            void Read() override;

            ObjectGuid Item;
        };

        class ServerPetitionShowSignatures final : public ServerPacket
        {
        public:
            struct PetitionSignature
            {
                ObjectGuid Signer;
                int32 Choice = 0;
            };

            ServerPetitionShowSignatures() : ServerPacket(SMSG_PETITION_SHOW_SIGNATURES, 40) { }

            WorldPacket const* Write() override;

            ObjectGuid Item;
            ObjectGuid Owner;
            ObjectGuid OwnerAccountID;
            int32 PetitionID = 0;
            std::vector<PetitionSignature> Signatures;
        };

        class SignPetition final : public ClientPacket
        {
        public:
            SignPetition(WorldPacket&& packet) : ClientPacket(CMSG_SIGN_PETITION, std::move(packet)) { }

            void Read() override;

            ObjectGuid PetitionGUID;
            uint8 Choice = 0;
        };

        class PetitionSignResults final : public ServerPacket
        {
        public:
            PetitionSignResults() : ServerPacket(SMSG_PETITION_SIGN_RESULTS, 33) { }

            WorldPacket const* Write() override;

            ObjectGuid Item;
            ObjectGuid Player;
            int32 Error = 0; // PetitionError
        };

        class PetitionAlreadySigned final : public ServerPacket
        {
        public:
            PetitionAlreadySigned() : ServerPacket(SMSG_PETITION_ALREADY_SIGNED, 16) { }

            WorldPacket const* Write() override;

            ObjectGuid SignerGUID;
        };

        class DeclinePetition final : public ClientPacket
        {
        public:
            DeclinePetition(WorldPacket&& packet) : ClientPacket(CMSG_DECLINE_PETITION, std::move(packet)) { }

            void Read() override;

            ObjectGuid PetitionGUID;
        };

        class TurnInPetition final : public ClientPacket
        {
        public:
            TurnInPetition(WorldPacket&& packet) : ClientPacket(CMSG_TURN_IN_PETITION, std::move(packet)) { }

            void Read() override;

            ObjectGuid Item;
        };

        class TurnInPetitionResult final : public ServerPacket
        {
        public:
            TurnInPetitionResult() : ServerPacket(SMSG_TURN_IN_PETITION_RESULT, 4) { }

            WorldPacket const* Write() override;

            int32 Result = 0; // PetitionError
        };

        class OfferPetition final : public ClientPacket
        {
        public:
            OfferPetition(WorldPacket&& packet) : ClientPacket(CMSG_OFFER_PETITION, std::move(packet)) { }

            void Read() override;

            ObjectGuid TargetPlayer;
            ObjectGuid ItemGUID;
        };

        class OfferPetitionError final : public ServerPacket
        {
        public:
            OfferPetitionError() : ServerPacket(SMSG_OFFER_PETITION_ERROR, 16) { }

            WorldPacket const* Write() override;

            ObjectGuid PlayerGUID;
        };

        class PetitionRenameGuild final : public ClientPacket
        {
        public:
            PetitionRenameGuild(WorldPacket&& packet) : ClientPacket(CMSG_PETITION_RENAME_GUILD, std::move(packet)) { }

            void Read() override;

            ObjectGuid PetitionGuid;
            std::string NewGuildName;
        };

        class PetitionRenameGuildResponse final : public ServerPacket
        {
        public:
            PetitionRenameGuildResponse() : ServerPacket(SMSG_PETITION_RENAME_GUILD_RESPONSE, 20) { }

            WorldPacket const* Write() override;

            ObjectGuid PetitionGuid;
            std::string NewGuildName;
        };
    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Petition::PetitionInfo const& petitionInfo);

#endif // PetitionPackets_h__
