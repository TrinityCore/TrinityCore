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

void WorldPackets::Petition::QueryPetition::Read()
{
    _worldPacket >> PetitionID;
    _worldPacket >> ItemGUID;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Petition::PetitionInfo const& petitionInfo)
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
    data << int32(petitionInfo.StaticType);
    data << uint32(petitionInfo.Muid);

    data.WriteBits(petitionInfo.Title.length(), 7);
    data.WriteBits(petitionInfo.BodyText.length(), 12);

    for (std::size_t i = 0; i < petitionInfo.Choicetext.size(); ++i)
        data.WriteBits(petitionInfo.Choicetext[i].length(), 6);

    data.FlushBits();

    for (std::size_t i = 0; i < petitionInfo.Choicetext.size(); ++i)
        data.WriteString(petitionInfo.Choicetext[i]);

    data.WriteString(petitionInfo.Title);
    data.WriteString(petitionInfo.BodyText);

    return data;
}

WorldPacket const* WorldPackets::Petition::QueryPetitionResponse::Write()
{
    _worldPacket << uint32(PetitionID);
    _worldPacket.WriteBit(Allow);
    _worldPacket.FlushBits();

    if (Allow)
        _worldPacket << Info;

    return &_worldPacket;
}

void WorldPackets::Petition::PetitionShowList::Read()
{
    _worldPacket >> PetitionUnit;
}

WorldPacket const* WorldPackets::Petition::ServerPetitionShowList::Write()
{
    _worldPacket << Unit;
    _worldPacket << Price;

    return &_worldPacket;
}

void WorldPackets::Petition::PetitionBuy::Read()
{
    uint32 titleLen = _worldPacket.ReadBits(7);

    _worldPacket >> Unit;
    _worldPacket >> Unused910;
    Title = _worldPacket.ReadString(titleLen);
}

void WorldPackets::Petition::PetitionShowSignatures::Read()
{
    _worldPacket >> Item;
}

WorldPacket const* WorldPackets::Petition::ServerPetitionShowSignatures::Write()
{
    _worldPacket << Item;
    _worldPacket << Owner;
    _worldPacket << OwnerAccountID;
    _worldPacket << int32(PetitionID);

    _worldPacket << uint32(Signatures.size());
    for (PetitionSignature const& signature : Signatures)
    {
        _worldPacket << signature.Signer;
        _worldPacket << int32(signature.Choice);
    }

    return &_worldPacket;
}

void WorldPackets::Petition::SignPetition::Read()
{
    _worldPacket >> PetitionGUID;
    _worldPacket >> Choice;
}

WorldPacket const* WorldPackets::Petition::PetitionSignResults::Write()
{
    _worldPacket << Item;
    _worldPacket << Player;

    _worldPacket.WriteBits(Error, 4);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Petition::PetitionAlreadySigned::Write()
{
    _worldPacket << SignerGUID;

    return &_worldPacket;
}

void WorldPackets::Petition::DeclinePetition::Read()
{
    _worldPacket >> PetitionGUID;
}

void WorldPackets::Petition::TurnInPetition::Read()
{
    _worldPacket >> Item;
}

WorldPacket const* WorldPackets::Petition::TurnInPetitionResult::Write()
{
    _worldPacket.WriteBits(Result, 4);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Petition::OfferPetition::Read()
{
    _worldPacket >> ItemGUID;
    _worldPacket >> TargetPlayer;
}

WorldPacket const* WorldPackets::Petition::OfferPetitionError::Write()
{
    _worldPacket << PlayerGUID;

    return &_worldPacket;
}

void WorldPackets::Petition::PetitionRenameGuild::Read()
{
    _worldPacket >> PetitionGuid;

    _worldPacket.ResetBitPos();
    uint32 nameLen = _worldPacket.ReadBits(7);

    NewGuildName = _worldPacket.ReadString(nameLen);
}

WorldPacket const* WorldPackets::Petition::PetitionRenameGuildResponse::Write()
{
    _worldPacket << PetitionGuid;

    _worldPacket.WriteBits(NewGuildName.length(), 7);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(NewGuildName);

    return &_worldPacket;
}
