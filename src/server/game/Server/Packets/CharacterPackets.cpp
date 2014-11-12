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

#include "CharacterPackets.h"

void WorldPackets::Character::CreateCharacter::Read()
{
    CreateInfo = std::make_shared<CharacterCreateInfo>();

    _worldPacket >> CreateInfo->Name;
    _worldPacket >> CreateInfo->Race;
    _worldPacket >> CreateInfo->Class;
    _worldPacket >> CreateInfo->Sex;
    _worldPacket >> CreateInfo->Skin;
    _worldPacket >> CreateInfo->Face;
    _worldPacket >> CreateInfo->HairStyle;
    _worldPacket >> CreateInfo->HairColor;
    _worldPacket >> CreateInfo->FacialHairStyle;
    _worldPacket >> CreateInfo->OutfitId;
}

WorldPacket const* WorldPackets::Character::CreateChar::Write()
{
    _worldPacket << uint8(Code);

    return &_worldPacket;
}

void WorldPackets::Character::CharDelete::Read()
{
    _worldPacket >> Guid;
}

WorldPacket const* WorldPackets::Character::DeleteChar::Write()
{
    _worldPacket << uint8(Code);

    return &_worldPacket;
}

void WorldPackets::Character::CharacterRenameRequest::Read()
{
    RenameInfo = std::make_shared<CharacterRenameInfo>();

    _worldPacket >> RenameInfo->Guid;
    _worldPacket >> RenameInfo->NewName;
}

WorldPacket const* WorldPackets::Character::CharacterRenameResult::Write()
{
    _worldPacket << uint8(Result);
    if (Result == RESPONSE_SUCCESS)
    {
        _worldPacket << Guid;
        _worldPacket << Name;
    }

    return &_worldPacket;
}

void WorldPackets::Character::CharCustomize::Read()
{
    CustomizeInfo = std::make_shared<CharCustomizeInfo>();

    _worldPacket >> CustomizeInfo->CharGUID;
    _worldPacket >> CustomizeInfo->CharName;
    _worldPacket >> CustomizeInfo->SexID;
    _worldPacket >> CustomizeInfo->SkinID;
    _worldPacket >> CustomizeInfo->HairColorID;
    _worldPacket >> CustomizeInfo->HairStyleID;
    _worldPacket >> CustomizeInfo->FacialHairStyleID;
    _worldPacket >> CustomizeInfo->FaceID;
}

WorldPacket const* WorldPackets::Character::CharCustomizeResult::Write()
{
    _worldPacket << uint8(Code);
    if (Code == RESPONSE_SUCCESS)
    {
        _worldPacket << CustomizeInfo->CharGUID;
        _worldPacket << CustomizeInfo->CharName;
        _worldPacket << uint8(CustomizeInfo->SexID);
        _worldPacket << uint8(CustomizeInfo->SkinID);
        _worldPacket << uint8(CustomizeInfo->FaceID);
        _worldPacket << uint8(CustomizeInfo->HairStyleID);
        _worldPacket << uint8(CustomizeInfo->HairColorID);
        _worldPacket << uint8(CustomizeInfo->FacialHairStyleID);
    }

    return &_worldPacket;
}

void WorldPackets::Character::CharRaceOrFactionChange::Read()
{
    RaceOrFactionChangeInfo = std::make_shared<CharRaceOrFactionChangeInfo>();

    _worldPacket >> RaceOrFactionChangeInfo->Guid;
    _worldPacket >> RaceOrFactionChangeInfo->Name;
    _worldPacket >> RaceOrFactionChangeInfo->SexID;
    _worldPacket >> RaceOrFactionChangeInfo->SkinID;
    _worldPacket >> RaceOrFactionChangeInfo->HairColorID;
    _worldPacket >> RaceOrFactionChangeInfo->HairStyleID;
    _worldPacket >> RaceOrFactionChangeInfo->FacialHairStyleID;
    _worldPacket >> RaceOrFactionChangeInfo->FaceID;
    _worldPacket >> RaceOrFactionChangeInfo->RaceID;
    RaceOrFactionChangeInfo->FactionChange = GetOpcode() == CMSG_CHAR_FACTION_CHANGE;
}

WorldPacket const* WorldPackets::Character::CharFactionChangeResult::Write()
{
    _worldPacket << uint8(Result);
    if (Result == RESPONSE_SUCCESS)
    {
        _worldPacket << RaceOrFactionChangeInfo->Guid;
        _worldPacket << RaceOrFactionChangeInfo->Name;
        _worldPacket << uint8(RaceOrFactionChangeInfo->SexID);
        _worldPacket << uint8(RaceOrFactionChangeInfo->SkinID);
        _worldPacket << uint8(RaceOrFactionChangeInfo->FaceID);
        _worldPacket << uint8(RaceOrFactionChangeInfo->HairStyleID);
        _worldPacket << uint8(RaceOrFactionChangeInfo->HairColorID);
        _worldPacket << uint8(RaceOrFactionChangeInfo->FacialHairStyleID);
        _worldPacket << uint8(RaceOrFactionChangeInfo->RaceID);
    }

    return &_worldPacket;
}

void WorldPackets::Character::ShowingCloak::Read()
{
    _worldPacket >> ShowCloak;
}

void WorldPackets::Character::ShowingHelm::Read()
{
    _worldPacket >> ShowHelm;
}

WorldPacket const* WorldPackets::Character::LoginVerifyWorld::Write()
{
    _worldPacket << int32(MapID);
    _worldPacket << Pos;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Character::LogoutResponse::Write()
{
    _worldPacket << uint32(LogoutResult);
    _worldPacket << uint8(Instant);
    return &_worldPacket;
}

void WorldPackets::Character::PlayedTimeClient::Read()
{
    _worldPacket >> TriggerScriptEvent;
}

WorldPacket const* WorldPackets::Character::PlayedTime::Write()
{
    _worldPacket << uint32(TotalTime);
    _worldPacket << uint32(LevelTime);
    _worldPacket << uint8(TriggerScriptEvent);

    return &_worldPacket;
}
