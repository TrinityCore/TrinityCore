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

#include "PetitionPackets.h"
#include "PacketOperators.h"

namespace WorldPackets::Petition
{
void QueryPetition::Read()
{
    _worldPacket >> PetitionID;
    _worldPacket >> ItemGUID;
}

ByteBuffer& operator<<(ByteBuffer& data, PetitionInfo const& petitionInfo)
{
    data << int32(petitionInfo.PetitionID);
    data << petitionInfo.Petitioner;
    data << int32(petitionInfo.MinSignatures);
    data << int32(petitionInfo.MaxSignatures);
    data << int32(petitionInfo.DeadLine);
    data << int32(petitionInfo.IssueDate);
    data << int32(petitionInfo.AllowedGuildID);
    data << int32(petitionInfo.AllowedClasses);
    data << int32(petitionInfo.AllowedRaces);
    data << int16(petitionInfo.AllowedGender);
    data << int32(petitionInfo.AllowedMinLevel);
    data << int32(petitionInfo.AllowedMaxLevel);
    data << int32(petitionInfo.NumChoices);
    data << int8(petitionInfo.StaticType);
    data << uint32(petitionInfo.Muid);

    data << SizedString::BitsSize<8>(petitionInfo.Title);
    data << SizedString::BitsSize<12>(petitionInfo.BodyText);

    for (std::string const& choiceText : petitionInfo.Choicetext)
        data << SizedString::BitsSize<7>(choiceText);

    data.FlushBits();

    for (std::string const& choiceText : petitionInfo.Choicetext)
        data << SizedString::Data(choiceText);

    data << SizedString::Data(petitionInfo.Title);
    data << SizedString::Data(petitionInfo.BodyText);

    return data;
}

WorldPacket const* QueryPetitionResponse::Write()
{
    _worldPacket << uint32(PetitionID);
    _worldPacket << Bits<1>(Allow);
    _worldPacket.FlushBits();

    if (Allow)
        _worldPacket << Info;

    return &_worldPacket;
}

void PetitionShowList::Read()
{
    _worldPacket >> PetitionUnit;
}

WorldPacket const* ServerPetitionShowList::Write()
{
    _worldPacket << Unit;
    _worldPacket << Price;

    return &_worldPacket;
}

void PetitionBuy::Read()
{
    _worldPacket >> SizedString::BitsSize<7>(Title);

    _worldPacket >> Unit;
    _worldPacket >> Muid;
    _worldPacket >> SizedString::Data(Title);
}

void PetitionShowSignatures::Read()
{
    _worldPacket >> Item;
}

WorldPacket const* ServerPetitionShowSignatures::Write()
{
    _worldPacket << Item;
    _worldPacket << Owner;
    _worldPacket << OwnerAccountID;
    _worldPacket << int32(PetitionID);

    _worldPacket << Size<uint32>(Signatures);
    for (PetitionSignature const& signature : Signatures)
    {
        _worldPacket << signature.Signer;
        _worldPacket << int32(signature.Choice);
    }

    return &_worldPacket;
}

void SignPetition::Read()
{
    _worldPacket >> PetitionGUID;
    _worldPacket >> Choice;
}

WorldPacket const* PetitionSignResults::Write()
{
    _worldPacket << Item;
    _worldPacket << Player;

    _worldPacket << Bits<4>(Error);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* PetitionAlreadySigned::Write()
{
    _worldPacket << SignerGUID;

    return &_worldPacket;
}

void DeclinePetition::Read()
{
    _worldPacket >> PetitionGUID;
}

void TurnInPetition::Read()
{
    _worldPacket >> Item;
}

WorldPacket const* TurnInPetitionResult::Write()
{
    _worldPacket << Bits<4>(Result);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void OfferPetition::Read()
{
    _worldPacket >> ItemGUID;
    _worldPacket >> TargetPlayer;
}

WorldPacket const* OfferPetitionError::Write()
{
    _worldPacket << PlayerGUID;

    return &_worldPacket;
}

void PetitionRenameGuild::Read()
{
    _worldPacket >> PetitionGuid;
    _worldPacket >> SizedString::BitsSize<7>(NewGuildName);

    _worldPacket >> SizedString::Data(NewGuildName);
}

WorldPacket const* PetitionRenameGuildResponse::Write()
{
    _worldPacket << PetitionGuid;
    _worldPacket << SizedString::BitsSize<7>(NewGuildName);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(NewGuildName);

    return &_worldPacket;
}
}
