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

#include "CharacterPackets.h"
#include "ObjectMgr.h"
#include "PacketUtilities.h"
#include "World.h"

WorldPackets::Character::EnumCharactersResult::CharacterInfo::CharacterInfo(Field* fields)
{
    //         0                1                2                3                 4                  5                       6                        7
    // "SELECT characters.guid, characters.name, characters.race, characters.class, characters.gender, characters.playerBytes, characters.playerBytes2, characters.level, "
    //  8                9               10                     11                     12                     13                    14
    // "characters.zone, characters.map, characters.position_x, characters.position_y, characters.position_z, guild_member.guildid, characters.playerFlags, "
    //  15                   16                   17                     18                   19               20                     21               22
    // "characters.at_login, character_pet.entry, character_pet.modelid, character_pet.level, characters.data, character_banned.guid, characters.slot, character_declinedname.genitive"

    Guid              = ObjectGuid::Create<HighGuid::Player>(fields[0].GetUInt64());
    Name              = fields[1].GetString();
    Race              = fields[2].GetUInt8();
    Class             = fields[3].GetUInt8();
    Sex               = fields[4].GetUInt8();
    Skin              = uint8(fields[5].GetUInt32() & 0xFF);
    Face              = uint8((fields[5].GetUInt32() >> 8) & 0xFF);
    HairStyle         = uint8((fields[5].GetUInt32() >> 16) & 0xFF);
    HairColor         = uint8((fields[5].GetUInt32() >> 24) & 0xFF);
    FacialHair        = uint8(fields[6].GetUInt32() & 0xFF);
    Level             = fields[7].GetUInt8();
    ZoneId            = int32(fields[8].GetUInt16());
    MapId             = int32(fields[9].GetUInt16());
    PreLoadPosition.x = fields[10].GetFloat();
    PreLoadPosition.y = fields[11].GetFloat();
    PreLoadPosition.z = fields[12].GetFloat();

    if (ObjectGuid::LowType guildId = fields[13].GetUInt64())
        GuildGuid = ObjectGuid::Create<HighGuid::Guild>(guildId);

    uint32 playerFlags  = fields[14].GetUInt32();
    uint32 atLoginFlags = fields[15].GetUInt16();

    if (playerFlags & PLAYER_FLAGS_HIDE_HELM)
        Flags |= CHARACTER_FLAG_HIDE_HELM;

    if (playerFlags & PLAYER_FLAGS_HIDE_CLOAK)
        Flags |= CHARACTER_FLAG_HIDE_CLOAK;

    if (playerFlags & PLAYER_FLAGS_GHOST)
        Flags |= CHARACTER_FLAG_GHOST;

    if (atLoginFlags & AT_LOGIN_RENAME)
        Flags |= CHARACTER_FLAG_RENAME;

    if (fields[20].GetUInt32())
        Flags |= CHARACTER_FLAG_LOCKED_BY_BILLING;

    if (sWorld->getBoolConfig(CONFIG_DECLINED_NAMES_USED) && !fields[22].GetString().empty())
        Flags |= CHARACTER_FLAG_DECLINED;

    if (atLoginFlags & AT_LOGIN_CUSTOMIZE)
        CustomizationFlag = CHAR_CUSTOMIZE_FLAG_CUSTOMIZE;
    else if (atLoginFlags & AT_LOGIN_CHANGE_FACTION)
        CustomizationFlag = CHAR_CUSTOMIZE_FLAG_FACTION;
    else if (atLoginFlags & AT_LOGIN_CHANGE_RACE)
        CustomizationFlag = CHAR_CUSTOMIZE_FLAG_RACE;

    Flags3 = 0;
    FirstLogin = (atLoginFlags & AT_LOGIN_FIRST) != 0;

    // show pet at selection character in character list only for non-ghost character
    if (!(playerFlags & PLAYER_FLAGS_GHOST) && (Class == CLASS_WARLOCK || Class == CLASS_HUNTER || Class == CLASS_DEATH_KNIGHT))
    {
        if (CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(fields[16].GetUInt32()))
        {
            Pet.CreatureDisplayId = fields[17].GetUInt32();
            Pet.Level = fields[18].GetUInt16();
            Pet.CreatureFamily = creatureInfo->family;
        }
    }

    BoostInProgress  = false;
    ProfessionIds[0] = 0;
    ProfessionIds[1] = 0;

    Tokenizer equipment(fields[19].GetString(), ' ');
    ListPosition = fields[21].GetUInt8();

    for (uint8 slot = 0; slot < INVENTORY_SLOT_BAG_END; ++slot)
    {
        uint32 visualBase = slot * 3;
        VisualItems[slot].InventoryType = Player::GetUInt32ValueFromArray(equipment, visualBase);
        VisualItems[slot].DisplayId = Player::GetUInt32ValueFromArray(equipment, visualBase + 1);
        VisualItems[slot].DisplayEnchantId = Player::GetUInt32ValueFromArray(equipment, visualBase + 2);
    }
}

WorldPacket const* WorldPackets::Character::EnumCharactersResult::Write()
{
    _worldPacket.reserve(9 + Characters.size() * sizeof(CharacterInfo) + FactionChangeRestrictions.size() * sizeof(RestrictedFactionChangeRuleInfo));

    _worldPacket.WriteBit(Success);
    _worldPacket.WriteBit(IsDeletedCharacters);
    _worldPacket << uint32(Characters.size());
    _worldPacket << uint32(FactionChangeRestrictions.size());

    for (CharacterInfo const& charInfo : Characters)
    {
        _worldPacket << charInfo.Guid;
        _worldPacket << uint8(charInfo.ListPosition);
        _worldPacket << uint8(charInfo.Race);
        _worldPacket << uint8(charInfo.Class);
        _worldPacket << uint8(charInfo.Sex);
        _worldPacket << uint8(charInfo.Skin);
        _worldPacket << uint8(charInfo.Face);
        _worldPacket << uint8(charInfo.HairStyle);
        _worldPacket << uint8(charInfo.HairColor);
        _worldPacket << uint8(charInfo.FacialHair);
        _worldPacket << uint8(charInfo.Level);
        _worldPacket << int32(charInfo.ZoneId);
        _worldPacket << int32(charInfo.MapId);
        _worldPacket << charInfo.PreLoadPosition;
        _worldPacket << charInfo.GuildGuid;
        _worldPacket << uint32(charInfo.Flags);
        _worldPacket << uint32(charInfo.CustomizationFlag);
        _worldPacket << uint32(charInfo.Flags3);
        _worldPacket << uint32(charInfo.Pet.CreatureDisplayId);
        _worldPacket << uint32(charInfo.Pet.Level);
        _worldPacket << uint32(charInfo.Pet.CreatureFamily);

        _worldPacket << uint32(charInfo.ProfessionIds[0]);
        _worldPacket << uint32(charInfo.ProfessionIds[1]);

        for (uint8 slot = 0; slot < INVENTORY_SLOT_BAG_END; ++slot)
        {
            _worldPacket << uint32(charInfo.VisualItems[slot].DisplayId);
            _worldPacket << uint32(charInfo.VisualItems[slot].DisplayEnchantId);
            _worldPacket << uint8(charInfo.VisualItems[slot].InventoryType);
        }

        _worldPacket.WriteBits(charInfo.Name.length(), 6);
        _worldPacket.WriteBit(charInfo.FirstLogin);
        _worldPacket.WriteBit(charInfo.BoostInProgress);
        _worldPacket.WriteBits(charInfo.unkWod61x, 5);
        _worldPacket.WriteString(charInfo.Name);
    }

    for (RestrictedFactionChangeRuleInfo const& rule : FactionChangeRestrictions)
    {
        _worldPacket << int32(rule.Mask);
        _worldPacket << uint8(rule.Race);
    }

    return &_worldPacket;
}

void WorldPackets::Character::CreateChar::Read()
{
    CreateInfo.reset(new CharacterCreateInfo());
    uint32 nameLength = _worldPacket.ReadBits(6);
    CreateInfo->TemplateSet.HasValue = _worldPacket.ReadBit();
    _worldPacket >> CreateInfo->Race;
    _worldPacket >> CreateInfo->Class;
    _worldPacket >> CreateInfo->Sex;
    _worldPacket >> CreateInfo->Skin;
    _worldPacket >> CreateInfo->Face;
    _worldPacket >> CreateInfo->HairStyle;
    _worldPacket >> CreateInfo->HairColor;
    _worldPacket >> CreateInfo->FacialHairStyle;
    _worldPacket >> CreateInfo->OutfitId;
    CreateInfo->Name = _worldPacket.ReadString(nameLength);
    if (CreateInfo->TemplateSet.HasValue)
        _worldPacket >> CreateInfo->TemplateSet.Value;
}

WorldPacket const* WorldPackets::Character::CharacterCreateResponse::Write()
{
    _worldPacket << uint8(Code);
    return &_worldPacket;
}

void WorldPackets::Character::DeleteChar::Read()
{
    _worldPacket >> Guid;
}

WorldPacket const* WorldPackets::Character::CharacterDeleteResponse::Write()
{
    _worldPacket << uint8(Code);
    return &_worldPacket;
}

void WorldPackets::Character::CharacterRenameRequest::Read()
{
    RenameInfo.reset(new CharacterRenameInfo());
    _worldPacket >> RenameInfo->Guid;
    RenameInfo->NewName = _worldPacket.ReadString(_worldPacket.ReadBits(6));
}

WorldPacket const* WorldPackets::Character::CharacterRenameResult::Write()
{
    _worldPacket << uint8(Result);
    _worldPacket.WriteBit(Guid.HasValue);
    _worldPacket.WriteBits(Name.length(), 6);

    if (Guid.HasValue)
        _worldPacket << Guid.Value;

    _worldPacket.WriteString(Name);
    return &_worldPacket;
}

void WorldPackets::Character::CharCustomize::Read()
{
    CustomizeInfo.reset(new CharCustomizeInfo());
    _worldPacket >> CustomizeInfo->CharGUID;
    _worldPacket >> CustomizeInfo->SexID;
    _worldPacket >> CustomizeInfo->SkinID;
    _worldPacket >> CustomizeInfo->HairColorID;
    _worldPacket >> CustomizeInfo->HairStyleID;
    _worldPacket >> CustomizeInfo->FacialHairStyleID;
    _worldPacket >> CustomizeInfo->FaceID;
    CustomizeInfo->CharName = _worldPacket.ReadString(_worldPacket.ReadBits(6));
}

void WorldPackets::Character::CharRaceOrFactionChange::Read()
{
    RaceOrFactionChangeInfo.reset(new CharRaceOrFactionChangeInfo());

    RaceOrFactionChangeInfo->FactionChange = _worldPacket.ReadBit();

    uint32 nameLength = _worldPacket.ReadBits(6);

    RaceOrFactionChangeInfo->SkinID.HasValue = _worldPacket.ReadBit();
    RaceOrFactionChangeInfo->HairColorID.HasValue = _worldPacket.ReadBit();
    RaceOrFactionChangeInfo->HairStyleID.HasValue = _worldPacket.ReadBit();
    RaceOrFactionChangeInfo->FacialHairStyleID.HasValue = _worldPacket.ReadBit();
    RaceOrFactionChangeInfo->FaceID.HasValue = _worldPacket.ReadBit();

    _worldPacket >> RaceOrFactionChangeInfo->Guid;
    _worldPacket >> RaceOrFactionChangeInfo->SexID;
    _worldPacket >> RaceOrFactionChangeInfo->RaceID;

    RaceOrFactionChangeInfo->Name = _worldPacket.ReadString(nameLength);

    if (RaceOrFactionChangeInfo->SkinID.HasValue)
        _worldPacket >> RaceOrFactionChangeInfo->SkinID.Value;

    if (RaceOrFactionChangeInfo->HairColorID.HasValue)
        _worldPacket >> RaceOrFactionChangeInfo->HairColorID.Value;

    if (RaceOrFactionChangeInfo->HairStyleID.HasValue)
        _worldPacket >> RaceOrFactionChangeInfo->HairStyleID.Value;

    if (RaceOrFactionChangeInfo->FacialHairStyleID.HasValue)
        _worldPacket >> RaceOrFactionChangeInfo->FacialHairStyleID.Value;

    if (RaceOrFactionChangeInfo->FaceID.HasValue)
        _worldPacket >> RaceOrFactionChangeInfo->FaceID.Value;
}

WorldPacket const* WorldPackets::Character::CharFactionChangeResult::Write()
{
    _worldPacket << uint8(Result);
    _worldPacket << Guid;
    _worldPacket.WriteBit(Display.HasValue);
    _worldPacket.FlushBits();

    if (Display.HasValue)
    {
        _worldPacket.WriteBits(Display.Value.Name.length(), 6);
        _worldPacket << uint8(Display.Value.SexID);
        _worldPacket << uint8(Display.Value.SkinID);
        _worldPacket << uint8(Display.Value.HairColorID);
        _worldPacket << uint8(Display.Value.HairStyleID);
        _worldPacket << uint8(Display.Value.FacialHairStyleID);
        _worldPacket << uint8(Display.Value.FaceID);
        _worldPacket << uint8(Display.Value.RaceID);
        _worldPacket.WriteString(Display.Value.Name);
    }

    return &_worldPacket;
}

void WorldPackets::Character::GenerateRandomCharacterName::Read()
{
    _worldPacket >> Race;
    _worldPacket >> Sex;
}

WorldPacket const* WorldPackets::Character::GenerateRandomCharacterNameResult::Write()
{
    _worldPacket.WriteBit(Success);
    _worldPacket.WriteBits(Name.length(), 6);
    _worldPacket.WriteString(Name);
    return &_worldPacket;
}

void WorldPackets::Character::ReorderCharacters::Read()
{
    uint32 count = std::min<uint32>(_worldPacket.ReadBits(9), sWorld->getIntConfig(CONFIG_CHARACTERS_PER_REALM));
    while (count--)
    {
        ReorderInfo reorderInfo;
        _worldPacket >> reorderInfo.PlayerGUID;
        _worldPacket >> reorderInfo.NewPosition;
        Entries.emplace_back(reorderInfo);
    }
}

void WorldPackets::Character::UndeleteCharacter::Read()
{
    UndeleteInfo.reset(new CharacterUndeleteInfo());
    _worldPacket >> UndeleteInfo->ClientToken;
    _worldPacket >> UndeleteInfo->CharacterGuid;
}

WorldPacket const* WorldPackets::Character::UndeleteCharacterResponse::Write()
{
    ASSERT(UndeleteInfo);
    _worldPacket << int32(UndeleteInfo->ClientToken);
    _worldPacket << uint32(Result);
    _worldPacket << UndeleteInfo->CharacterGuid;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Character::UndeleteCooldownStatusResponse::Write()
{
    _worldPacket.WriteBit(OnCooldown);
    _worldPacket << uint32(MaxCooldown);
    _worldPacket << uint32(CurrentCooldown);
    return &_worldPacket;
}

void WorldPackets::Character::PlayerLogin::Read()
{
    _worldPacket >> Guid;
    _worldPacket >> FarClip;
}

WorldPacket const* WorldPackets::Character::LoginVerifyWorld::Write()
{
    _worldPacket << int32(MapID);
    _worldPacket << Pos.PositionXYZOStream();
    _worldPacket << uint32(Reason);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Character::CharacterLoginFailed::Write()
{
    _worldPacket << uint8(Code);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Character::LogoutResponse::Write()
{
    _worldPacket << int32(LogoutResult);
    _worldPacket.WriteBit(Instant);
    _worldPacket.FlushBits();
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Character::LogoutComplete::Write()
{
    _worldPacket << SwitchToCharacter;
    return &_worldPacket;
}

void WorldPackets::Character::LoadingScreenNotify::Read()
{
    _worldPacket >> MapID;
    Showing = _worldPacket.ReadBit();
}

WorldPacket const* WorldPackets::Character::InitialSetup::Write()
{
    _worldPacket << uint32(QuestsCompleted.size());
    _worldPacket << uint8(ServerExpansionLevel);
    _worldPacket << uint8(ServerExpansionTier);
    _worldPacket << int32(ServerRegionID);
    _worldPacket << uint32(RaidOrigin);
    if (!QuestsCompleted.empty())
        _worldPacket.append(QuestsCompleted.data(), QuestsCompleted.size());

    return &_worldPacket;
}

void WorldPackets::Character::SetActionBarToggles::Read()
{
    _worldPacket >> Mask;
}

void WorldPackets::Character::PlayedTimeClient::Read()
{
    TriggerScriptEvent = _worldPacket.ReadBit();
}

WorldPacket const* WorldPackets::Character::PlayedTime::Write()
{
    _worldPacket << int32(TotalTime);
    _worldPacket << int32(LevelTime);
    _worldPacket.WriteBit(TriggerEvent);
    _worldPacket.FlushBits();

    return &_worldPacket;
}
