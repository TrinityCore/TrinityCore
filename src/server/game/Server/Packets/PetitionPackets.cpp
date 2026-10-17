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

namespace WorldPackets::Petition
{
void QueryPetition::Read()
{
    _worldPacket >> PetitionID;
    _worldPacket >> ItemGUID;
}

ByteBuffer& operator>>(ByteBuffer& data, PetitionInfo& petitionInfo)
{
    data >> petitionInfo.PetitionID;
    data >> petitionInfo.Petitioner;
    data >> petitionInfo.Title;
    data >> petitionInfo.BodyText;
    data >> petitionInfo.MinSignatures;
    data >> petitionInfo.MaxSignatures;
    data >> petitionInfo.DeadLine;
    data >> petitionInfo.IssueDate;
    data >> petitionInfo.AllowedGuildID;
    data >> petitionInfo.AllowedClasses;
    data >> petitionInfo.AllowedRaces;
    data >> petitionInfo.AllowedGender;
    data >> petitionInfo.AllowedMinLevel;
    data >> petitionInfo.AllowedMaxLevel;
    data >> petitionInfo.NumChoices;

    for (std::string& choiceText : petitionInfo.Choicetext)
        data >> choiceText;

    data >> petitionInfo.Muid;
    data >> petitionInfo.StaticType;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, PetitionInfo const& petitionInfo)
{
    data << int32(petitionInfo.PetitionID);
    data << petitionInfo.Petitioner;
    data << petitionInfo.Title;
    data << petitionInfo.BodyText;
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

    for (std::string const& choiceText : petitionInfo.Choicetext)
        data << choiceText;

    data << uint32(petitionInfo.Muid);
    data << int32(petitionInfo.StaticType);

    return data;
}

WorldPacket const* QueryPetitionResponse::Write()
{
    _worldPacket << Info;

    return &_worldPacket;
}

void PetitionShowList::Read()
{
    _worldPacket >> PetitionUnit;
}

ByteBuffer& operator<<(ByteBuffer& data, PetitionList const& petitionInfo)
{
    data << uint32(petitionInfo.Muid);
    data << uint32(petitionInfo.ItemID);
    data << uint32(petitionInfo.ItemDisplayID);
    data << uint32(petitionInfo.Price);
    data << uint32(petitionInfo.PetitionTypeID);
    data << uint32(petitionInfo.SignaturesNeeded);

    return data;
}

WorldPacket const* ServerPetitionShowList::Write()
{
    _worldPacket << Unit;
    _worldPacket << uint8(PetitionInfo.size());

    for (PetitionList const& petitionInfo : PetitionInfo)
        _worldPacket << petitionInfo;

    return &_worldPacket;
}

void PetitionBuy::Read()
{
    _worldPacket >> Unit;
    _worldPacket >> Petition;
}

void PetitionShowSignatures::Read()
{
    _worldPacket >> Item;
}

WorldPacket const* ServerPetitionShowSignatures::Write()
{
    _worldPacket << Item;
    _worldPacket << Owner;
    _worldPacket << int32(PetitionID);
    _worldPacket << uint8(Signatures.size());

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
    _worldPacket << int32(Error);

    return &_worldPacket;
}

void DeclinePetition::Read()
{
    _worldPacket >> PetitionGUID;
}

WorldPacket const* PetitionDeclined::Write()
{
    _worldPacket << Decliner;

    return &_worldPacket;
}

void TurnInPetition::Read()
{
    _worldPacket >> Item;

    // if there is data left, we expect it to be exactly 5 ints for arena team emblem
    if (_worldPacket.rpos() >= _worldPacket.size())
        return;

    _worldPacket >> EmblemBackground;
    _worldPacket >> EmblemIconStyle;
    _worldPacket >> EmblemIconColor;
    _worldPacket >> EmblemBorderStyle;
    _worldPacket >> EmblemBorderColor;
}

WorldPacket const* TurnInPetitionResult::Write()
{
    _worldPacket << int32(Result);

    return &_worldPacket;
}

void OfferPetition::Read()
{
    _worldPacket >> ArenaTeamSize;
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
    _worldPacket >> NewGuildName;
}

WorldPacket const* PetitionRenameGuildResponse::Write()
{
    _worldPacket << PetitionGuid;
    _worldPacket << NewGuildName;

    return &_worldPacket;
}
}
