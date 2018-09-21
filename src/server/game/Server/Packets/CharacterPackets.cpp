/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "DB2Stores.h"
#include "Field.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "World.h"

WorldPackets::Character::EnumCharacters::EnumCharacters(WorldPacket&& packet) : ClientPacket(std::move(packet))
{
    ASSERT(GetOpcode() == CMSG_ENUM_CHARACTERS || GetOpcode() == CMSG_ENUM_CHARACTERS_DELETED_BY_CLIENT);
}

WorldPackets::Character::EnumCharactersResult::CharacterInfo::CharacterInfo(Field* fields)
{
    //         0                1                2                3                 4                  5                6                7
    // "SELECT characters.guid, characters.name, characters.race, characters.class, characters.gender, characters.skin, characters.face, characters.hairStyle, "
    //  8                     9                       10                         11                         12                         13
    // "characters.hairColor, characters.facialStyle, characters.customDisplay1, characters.customDisplay2, characters.customDisplay3, characters.level, "
    //  14               15              16                     17                     18
    // "characters.zone, characters.map, characters.position_x, characters.position_y, characters.position_z, "
    //  19                    20                      21                   22                   23                     24                   25
    // "guild_member.guildid, characters.playerFlags, characters.at_login, character_pet.entry, character_pet.modelid, character_pet.level, characters.equipmentCache, "
    //  26                     27               28                      29                            30                         31
    // "character_banned.guid, characters.slot, characters.logout_time, characters.activeTalentGroup, characters.lastLoginBuild, character_declinedname.genitive"

    Guid              = ObjectGuid::Create<HighGuid::Player>(fields[0].GetUInt64());
    Name              = fields[1].GetString();
    Race              = fields[2].GetUInt8();
    Class             = fields[3].GetUInt8();
    Sex               = fields[4].GetUInt8();
    Skin              = fields[5].GetUInt8();
    Face              = fields[6].GetUInt8();
    HairStyle         = fields[7].GetUInt8();
    HairColor         = fields[8].GetUInt8();
    FacialHair        = fields[9].GetUInt8();
    CustomDisplay[0]  = fields[10].GetUInt8();
    CustomDisplay[1]  = fields[11].GetUInt8();
    CustomDisplay[2]  = fields[12].GetUInt8();
    Level             = fields[13].GetUInt8();
    ZoneId            = int32(fields[14].GetUInt16());
    MapId             = int32(fields[15].GetUInt16());
    PreLoadPosition   = Position(fields[16].GetFloat(), fields[17].GetFloat(), fields[18].GetFloat());

    if (ObjectGuid::LowType guildId = fields[19].GetUInt64())
        GuildGuid = ObjectGuid::Create<HighGuid::Guild>(guildId);

    uint32 playerFlags  = fields[20].GetUInt32();
    uint32 atLoginFlags = fields[21].GetUInt16();

    if (atLoginFlags & AT_LOGIN_RESURRECT)
        playerFlags &= ~PLAYER_FLAGS_GHOST;

    if (playerFlags & PLAYER_FLAGS_HIDE_HELM)
        Flags |= CHARACTER_FLAG_HIDE_HELM;

    if (playerFlags & PLAYER_FLAGS_HIDE_CLOAK)
        Flags |= CHARACTER_FLAG_HIDE_CLOAK;

    if (playerFlags & PLAYER_FLAGS_GHOST)
        Flags |= CHARACTER_FLAG_GHOST;

    if (atLoginFlags & AT_LOGIN_RENAME)
        Flags |= CHARACTER_FLAG_RENAME;

    if (fields[26].GetUInt64())
        Flags |= CHARACTER_FLAG_LOCKED_BY_BILLING;

    if (sWorld->getBoolConfig(CONFIG_DECLINED_NAMES_USED) && !fields[31].GetString().empty())
        Flags |= CHARACTER_FLAG_DECLINED;

    if (atLoginFlags & AT_LOGIN_CUSTOMIZE)
        CustomizationFlag = CHAR_CUSTOMIZE_FLAG_CUSTOMIZE;
    else if (atLoginFlags & AT_LOGIN_CHANGE_FACTION)
        CustomizationFlag = CHAR_CUSTOMIZE_FLAG_FACTION;
    else if (atLoginFlags & AT_LOGIN_CHANGE_RACE)
        CustomizationFlag = CHAR_CUSTOMIZE_FLAG_RACE;

    Flags3 = 0;
    Flags4 = 0;
    FirstLogin = (atLoginFlags & AT_LOGIN_FIRST) != 0;

    // show pet at selection character in character list only for non-ghost character
    if (!(playerFlags & PLAYER_FLAGS_GHOST) && (Class == CLASS_WARLOCK || Class == CLASS_HUNTER || Class == CLASS_DEATH_KNIGHT))
    {
        if (CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(fields[22].GetUInt32()))
        {
            Pet.CreatureDisplayId = fields[23].GetUInt32();
            Pet.Level = fields[24].GetUInt16();
            Pet.CreatureFamily = creatureInfo->family;
        }
    }

    BoostInProgress  = false;
    ProfessionIds[0] = 0;
    ProfessionIds[1] = 0;

    Tokenizer equipment(fields[25].GetString(), ' ');
    ListPosition = fields[27].GetUInt8();
    LastPlayedTime = fields[28].GetUInt32();
    if (ChrSpecializationEntry const* spec = sDB2Manager.GetChrSpecializationByIndex(Class, fields[29].GetUInt8()))
        SpecID = spec->ID;

    LastLoginBuild = fields[30].GetUInt32();

    for (uint8 slot = 0; slot < INVENTORY_SLOT_BAG_END; ++slot)
    {
        uint32 visualBase = slot * 3;
        VisualItems[slot].InventoryType = Player::GetUInt32ValueFromArray(equipment, visualBase);
        VisualItems[slot].DisplayId = Player::GetUInt32ValueFromArray(equipment, visualBase + 1);
        VisualItems[slot].DisplayEnchantId = Player::GetUInt32ValueFromArray(equipment, visualBase + 2);
    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Character::EnumCharactersResult::CharacterInfo::VisualItemInfo const& visualItem)
{
    data << uint32(visualItem.DisplayId);
    data << uint32(visualItem.DisplayEnchantId);
    data << uint8(visualItem.InventoryType);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Character::EnumCharactersResult::CharacterInfo const& charInfo)
{
    data << charInfo.Guid;
    data << uint8(charInfo.ListPosition);
    data << uint8(charInfo.Race);
    data << uint8(charInfo.Class);
    data << uint8(charInfo.Sex);
    data << uint8(charInfo.Skin);
    data << uint8(charInfo.Face);
    data << uint8(charInfo.HairStyle);
    data << uint8(charInfo.HairColor);
    data << uint8(charInfo.FacialHair);
    data.append(charInfo.CustomDisplay.data(), charInfo.CustomDisplay.size());
    data << uint8(charInfo.Level);
    data << int32(charInfo.ZoneId);
    data << int32(charInfo.MapId);
    data << charInfo.PreLoadPosition;
    data << charInfo.GuildGuid;
    data << uint32(charInfo.Flags);
    data << uint32(charInfo.CustomizationFlag);
    data << uint32(charInfo.Flags3);
    data << uint32(charInfo.Pet.CreatureDisplayId);
    data << uint32(charInfo.Pet.Level);
    data << uint32(charInfo.Pet.CreatureFamily);

    data << uint32(charInfo.ProfessionIds[0]);
    data << uint32(charInfo.ProfessionIds[1]);

    for (WorldPackets::Character::EnumCharactersResult::CharacterInfo::VisualItemInfo const& visualItem : charInfo.VisualItems)
        data << visualItem;

    data << uint32(charInfo.LastPlayedTime);
    data << uint16(charInfo.SpecID);
    data << uint32(charInfo.Unknown703);
    data << uint32(charInfo.LastLoginBuild);
    data << uint32(charInfo.Flags4);
    data.WriteBits(charInfo.Name.length(), 6);
    data.WriteBit(charInfo.FirstLogin);
    data.WriteBit(charInfo.BoostInProgress);
    data.WriteBits(charInfo.unkWod61x, 5);
    data.FlushBits();

    data.WriteString(charInfo.Name);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Character::EnumCharactersResult::RaceUnlock const& raceUnlock)
{
    data << int32(raceUnlock.RaceID);
    data.WriteBit(raceUnlock.HasExpansion);
    data.WriteBit(raceUnlock.HasAchievement);
    data.WriteBit(raceUnlock.HasHeritageArmor);
    data.FlushBits();

    return data;
}

WorldPacket const* WorldPackets::Character::EnumCharactersResult::Write()
{
    _worldPacket.reserve(9 + Characters.size() * sizeof(CharacterInfo) + RaceUnlockData.size() * sizeof(RaceUnlock));

    _worldPacket.WriteBit(Success);
    _worldPacket.WriteBit(IsDeletedCharacters);
    _worldPacket.WriteBit(IsDemonHunterCreationAllowed);
    _worldPacket.WriteBit(HasDemonHunterOnRealm);
    _worldPacket.WriteBit(Unknown7x);
    _worldPacket.WriteBit(DisabledClassesMask.is_initialized());
    _worldPacket.WriteBit(IsAlliedRacesCreationAllowed);
    _worldPacket << uint32(Characters.size());
    _worldPacket << int32(MaxCharacterLevel);
    _worldPacket << uint32(RaceUnlockData.size());

    if (DisabledClassesMask)
        _worldPacket << uint32(*DisabledClassesMask);

    for (CharacterInfo const& charInfo : Characters)
        _worldPacket << charInfo;

    for (RaceUnlock const& raceUnlock : RaceUnlockData)
        _worldPacket << raceUnlock;

    return &_worldPacket;
}

void WorldPackets::Character::CreateCharacter::Read()
{
    CreateInfo.reset(new CharacterCreateInfo());
    uint32 nameLength = _worldPacket.ReadBits(6);
    bool const hasTemplateSet = _worldPacket.ReadBit();

    _worldPacket >> CreateInfo->Race;
    _worldPacket >> CreateInfo->Class;
    _worldPacket >> CreateInfo->Sex;
    _worldPacket >> CreateInfo->Skin;
    _worldPacket >> CreateInfo->Face;
    _worldPacket >> CreateInfo->HairStyle;
    _worldPacket >> CreateInfo->HairColor;
    _worldPacket >> CreateInfo->FacialHairStyle;
    _worldPacket >> CreateInfo->OutfitId;
    _worldPacket.read(CreateInfo->CustomDisplay.data(), CreateInfo->CustomDisplay.size());
    CreateInfo->Name = _worldPacket.ReadString(nameLength);
    if (hasTemplateSet)
        CreateInfo->TemplateSet = _worldPacket.read<int32>();
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
    RenameInfo.reset(new CharacterRenameInfo());
    _worldPacket >> RenameInfo->Guid;
    RenameInfo->NewName = _worldPacket.ReadString(_worldPacket.ReadBits(6));
}

WorldPacket const* WorldPackets::Character::CharacterRenameResult::Write()
{
    _worldPacket << uint8(Result);
    _worldPacket.WriteBit(Guid.is_initialized());
    _worldPacket.WriteBits(Name.length(), 6);
    _worldPacket.FlushBits();

    if (Guid)
        _worldPacket << *Guid;

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
    _worldPacket.read(CustomizeInfo->CustomDisplay.data(), CustomizeInfo->CustomDisplay.size());
    CustomizeInfo->CharName = _worldPacket.ReadString(_worldPacket.ReadBits(6));
}

void WorldPackets::Character::CharRaceOrFactionChange::Read()
{
    RaceOrFactionChangeInfo.reset(new CharRaceOrFactionChangeInfo());

    RaceOrFactionChangeInfo->FactionChange = _worldPacket.ReadBit();

    uint32 nameLength = _worldPacket.ReadBits(6);

    _worldPacket >> RaceOrFactionChangeInfo->Guid;
    _worldPacket >> RaceOrFactionChangeInfo->SexID;
    _worldPacket >> RaceOrFactionChangeInfo->RaceID;
    _worldPacket >> RaceOrFactionChangeInfo->SkinID;
    _worldPacket >> RaceOrFactionChangeInfo->HairColorID;
    _worldPacket >> RaceOrFactionChangeInfo->HairStyleID;
    _worldPacket >> RaceOrFactionChangeInfo->FacialHairStyleID;
    _worldPacket >> RaceOrFactionChangeInfo->FaceID;
    _worldPacket.read(RaceOrFactionChangeInfo->CustomDisplay.data(), RaceOrFactionChangeInfo->CustomDisplay.size());
    RaceOrFactionChangeInfo->Name = _worldPacket.ReadString(nameLength);
}

WorldPacket const* WorldPackets::Character::CharFactionChangeResult::Write()
{
    _worldPacket << uint8(Result);
    _worldPacket << Guid;
    _worldPacket.WriteBit(Display.is_initialized());
    _worldPacket.FlushBits();

    if (Display)
    {
        _worldPacket.WriteBits(Display->Name.length(), 6);
        _worldPacket << uint8(Display->SexID);
        _worldPacket << uint8(Display->SkinID);
        _worldPacket << uint8(Display->HairColorID);
        _worldPacket << uint8(Display->HairStyleID);
        _worldPacket << uint8(Display->FacialHairStyleID);
        _worldPacket << uint8(Display->FaceID);
        _worldPacket << uint8(Display->RaceID);
        _worldPacket.append(Display->CustomDisplay.data(), Display->CustomDisplay.size());
        _worldPacket.WriteString(Display->Name);
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
    _worldPacket.FlushBits();

    _worldPacket.WriteString(Name);

    return &_worldPacket;
}

WorldPackets::Character::ReorderCharacters::ReorderCharacters(WorldPacket&& packet) : ClientPacket(CMSG_REORDER_CHARACTERS, std::move(packet))
{
}

void WorldPackets::Character::ReorderCharacters::Read()
{
    Entries.resize(_worldPacket.ReadBits(9));
    for (ReorderInfo& reorderInfo : Entries)
    {
        _worldPacket >> reorderInfo.PlayerGUID;
        _worldPacket >> reorderInfo.NewPosition;
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
    _worldPacket << Pos;
    _worldPacket << uint32(Reason);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Character::CharacterLoginFailed::Write()
{
    _worldPacket << uint8(Code);
    return &_worldPacket;
}

void WorldPackets::Character::LogoutRequest::Read()
{
    IdleLogout = _worldPacket.ReadBit();
}

WorldPacket const* WorldPackets::Character::LogoutResponse::Write()
{
    _worldPacket << int32(LogoutResult);
    _worldPacket.WriteBit(Instant);
    _worldPacket.FlushBits();
    return &_worldPacket;
}

void WorldPackets::Character::LoadingScreenNotify::Read()
{
    _worldPacket >> MapID;
    Showing = _worldPacket.ReadBit();
}

WorldPacket const* WorldPackets::Character::InitialSetup::Write()
{
    _worldPacket << uint8(ServerExpansionLevel);
    _worldPacket << uint8(ServerExpansionTier);

    return &_worldPacket;
}

void WorldPackets::Character::SetActionBarToggles::Read()
{
    _worldPacket >> Mask;
}

void WorldPackets::Character::RequestPlayedTime::Read()
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

void WorldPackets::Character::SetTitle::Read()
{
    _worldPacket >> TitleID;
}

void WorldPackets::Character::AlterApperance::Read()
{
    _worldPacket >> NewHairStyle;
    _worldPacket >> NewHairColor;
    _worldPacket >> NewFacialHair;
    _worldPacket >> NewSkinColor;
    _worldPacket >> NewFace;
    for (std::size_t i = 0; i < NewCustomDisplay.size(); ++i)
        _worldPacket >> NewCustomDisplay[i];
}

WorldPacket const* WorldPackets::Character::BarberShopResult::Write()
{
    _worldPacket << int32(Result);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Character::LogXPGain::Write()
{
    _worldPacket << Victim;
    _worldPacket << int32(Original);
    _worldPacket << uint8(Reason);
    _worldPacket << int32(Amount);
    _worldPacket << float(GroupBonus);
    _worldPacket << uint8(ReferAFriendBonusType);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Character::TitleEarned::Write()
{
    _worldPacket << uint32(Index);

    return &_worldPacket;
}

void WorldPackets::Character::SetFactionAtWar::Read()
{
    _worldPacket >> FactionIndex;
}

void WorldPackets::Character::SetFactionNotAtWar::Read()
{
    _worldPacket >> FactionIndex;
}

void WorldPackets::Character::SetFactionInactive::Read()
{
    _worldPacket >> Index;
    State = _worldPacket.ReadBit();
}

void WorldPackets::Character::SetWatchedFaction::Read()
{
    _worldPacket >> FactionIndex;
}

WorldPacket const* WorldPackets::Character::SetFactionVisible::Write()
{
    _worldPacket << FactionIndex;
    return &_worldPacket;
}

WorldPackets::Character::CharCustomizeResponse::CharCustomizeResponse(WorldPackets::Character::CharCustomizeInfo const* info)
    : ServerPacket(SMSG_CHAR_CUSTOMIZE, 16 + 1 + 1 + 1 + 1 + 1 + 1 + 1)
{
    CharGUID = info->CharGUID;
    SexID = info->SexID;
    SkinID = info->SkinID;
    HairColorID = info->HairColorID;
    HairStyleID = info->HairStyleID;
    FacialHairStyleID = info->FacialHairStyleID;
    FaceID = info->FaceID;
    CharName = info->CharName;
    CustomDisplay = info->CustomDisplay;
}

WorldPacket const* WorldPackets::Character::CharCustomizeResponse::Write()
{
    _worldPacket << CharGUID;
    _worldPacket << uint8(SexID);
    _worldPacket << uint8(SkinID);
    _worldPacket << uint8(HairColorID);
    _worldPacket << uint8(HairStyleID);
    _worldPacket << uint8(FacialHairStyleID);
    _worldPacket << uint8(FaceID);
    _worldPacket.append(CustomDisplay.data(), CustomDisplay.size());
    _worldPacket.WriteBits(CharName.length(), 6);
    _worldPacket.FlushBits();
    _worldPacket.WriteString(CharName);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Character::CharCustomizeFailed::Write()
{
    _worldPacket << uint8(Result);
    _worldPacket << CharGUID;

    return &_worldPacket;
}

void WorldPackets::Character::SetPlayerDeclinedNames::Read()
{
    _worldPacket >> Player;

    uint8 stringLengths[MAX_DECLINED_NAME_CASES];

    for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
        stringLengths[i] = _worldPacket.ReadBits(7);

    for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
        DeclinedNames.name[i] = _worldPacket.ReadString(stringLengths[i]);
}

WorldPacket const * WorldPackets::Character::SetPlayerDeclinedNamesResult::Write()
{
    _worldPacket << int32(ResultCode);
    _worldPacket << Player;

    return &_worldPacket;
}
