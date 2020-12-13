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
#include "DB2Stores.h"
#include "Field.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "World.h"

namespace UF
{
ByteBuffer& operator<<(ByteBuffer& data, ChrCustomizationChoice const& customizationChoice)
{
    data << uint32(customizationChoice.ChrCustomizationOptionID);
    data << uint32(customizationChoice.ChrCustomizationChoiceID);

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, ChrCustomizationChoice& customizationChoice)
{
    data >> customizationChoice.ChrCustomizationOptionID;
    data >> customizationChoice.ChrCustomizationChoiceID;

    return data;
}
}

namespace WorldPackets
{
namespace Character
{
void SortCustomizations(Array<ChrCustomizationChoice, 50>& customizations)
{
    auto first = customizations.begin();
    auto last = customizations.end();
    for (auto itr = first; itr != last; ++itr)
    {
        auto insertion = std::upper_bound(first, itr, *itr, [](ChrCustomizationChoice const& left, ChrCustomizationChoice const& right)
        {
            return left.ChrCustomizationOptionID < right.ChrCustomizationOptionID;
        });
        std::rotate(insertion, itr, std::next(itr));
    }
}

EnumCharacters::EnumCharacters(WorldPacket&& packet) : ClientPacket(std::move(packet))
{
    ASSERT(GetOpcode() == CMSG_ENUM_CHARACTERS || GetOpcode() == CMSG_ENUM_CHARACTERS_DELETED_BY_CLIENT);
}

EnumCharactersResult::CharacterInfo::CharacterInfo(Field* fields)
{
    //         0                1                2                3                 4                  5
    // "SELECT characters.guid, characters.name, characters.race, characters.class, characters.gender, characters.level, "
    //  6                7               8                      9                      10
    // "characters.zone, characters.map, characters.position_x, characters.position_y, characters.position_z, "
    //  11                    12                      13                   14                   15                     16                   17
    // "guild_member.guildid, characters.playerFlags, characters.at_login, character_pet.entry, character_pet.modelid, character_pet.level, characters.equipmentCache, "
    //  18                     19               20                      21                            22                         23
    // "character_banned.guid, characters.slot, characters.logout_time, characters.activeTalentGroup, characters.lastLoginBuild, character_declinedname.genitive"

    Guid              = ObjectGuid::Create<HighGuid::Player>(fields[0].GetUInt64());
    Name              = fields[1].GetString();
    RaceID            = fields[2].GetUInt8();
    ClassID           = fields[3].GetUInt8();
    SexID             = fields[4].GetUInt8();
    ExperienceLevel   = fields[5].GetUInt8();
    ZoneID            = int32(fields[6].GetUInt16());
    MapID             = int32(fields[7].GetUInt16());
    PreloadPos        = Position(fields[8].GetFloat(), fields[8].GetFloat(), fields[10].GetFloat());

    if (ObjectGuid::LowType guildId = fields[11].GetUInt64())
        GuildGUID = ObjectGuid::Create<HighGuid::Guild>(guildId);

    uint32 playerFlags  = fields[12].GetUInt32();
    uint32 atLoginFlags = fields[13].GetUInt16();

    if (atLoginFlags & AT_LOGIN_RESURRECT)
        playerFlags &= ~PLAYER_FLAGS_GHOST;

    if (playerFlags & PLAYER_FLAGS_GHOST)
        Flags |= CHARACTER_FLAG_GHOST;

    if (atLoginFlags & AT_LOGIN_RENAME)
        Flags |= CHARACTER_FLAG_RENAME;

    if (fields[18].GetUInt64())
        Flags |= CHARACTER_FLAG_LOCKED_BY_BILLING;

    if (sWorld->getBoolConfig(CONFIG_DECLINED_NAMES_USED) && !fields[23].GetString().empty())
        Flags |= CHARACTER_FLAG_DECLINED;

    if (atLoginFlags & AT_LOGIN_CUSTOMIZE)
        Flags2 = CHAR_CUSTOMIZE_FLAG_CUSTOMIZE;
    else if (atLoginFlags & AT_LOGIN_CHANGE_FACTION)
        Flags2 = CHAR_CUSTOMIZE_FLAG_FACTION;
    else if (atLoginFlags & AT_LOGIN_CHANGE_RACE)
        Flags2 = CHAR_CUSTOMIZE_FLAG_RACE;

    Flags3 = 0;
    Flags4 = 0;
    FirstLogin = (atLoginFlags & AT_LOGIN_FIRST) != 0;

    // show pet at selection character in character list only for non-ghost character
    if (!(playerFlags & PLAYER_FLAGS_GHOST) && (ClassID == CLASS_WARLOCK || ClassID == CLASS_HUNTER || ClassID == CLASS_DEATH_KNIGHT))
    {
        if (CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(fields[14].GetUInt32()))
        {
            PetCreatureDisplayID = fields[15].GetUInt32();
            PetExperienceLevel = fields[16].GetUInt16();
            PetCreatureFamilyID = creatureInfo->family;
        }
    }

    BoostInProgress  = false;
    ProfessionIds[0] = 0;
    ProfessionIds[1] = 0;

    Tokenizer equipment(fields[17].GetString(), ' ');
    ListPosition = fields[19].GetUInt8();
    LastPlayedTime = fields[20].GetUInt32();
    if (ChrSpecializationEntry const* spec = sDB2Manager.GetChrSpecializationByIndex(ClassID, fields[21].GetUInt8()))
        SpecID = spec->ID;

    LastLoginVersion = fields[22].GetUInt32();

    for (uint8 slot = 0; slot < INVENTORY_SLOT_BAG_END; ++slot)
    {
        uint32 visualBase = slot * 4;
        VisualItems[slot].InvType = Player::GetUInt32ValueFromArray(equipment, visualBase);
        VisualItems[slot].DisplayID = Player::GetUInt32ValueFromArray(equipment, visualBase + 1);
        VisualItems[slot].DisplayEnchantID = Player::GetUInt32ValueFromArray(equipment, visualBase + 2);
        VisualItems[slot].Subclass = Player::GetUInt32ValueFromArray(equipment, visualBase + 3);
    }
}

ByteBuffer& operator<<(ByteBuffer& data, EnumCharactersResult::CharacterInfo::VisualItemInfo const& visualItem)
{
    data << uint32(visualItem.DisplayID);
    data << uint32(visualItem.DisplayEnchantID);
    data << int32(visualItem.ItemModifiedAppearanceID);
    data << uint8(visualItem.InvType);
    data << uint8(visualItem.Subclass);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, EnumCharactersResult::CharacterInfo const& charInfo)
{
    ASSERT(charInfo.MailSenders.size() == charInfo.MailSenderTypes.size());

    data << charInfo.Guid;
    data << uint64(charInfo.GuildClubMemberID);
    data << uint8(charInfo.ListPosition);
    data << uint8(charInfo.RaceID);
    data << uint8(charInfo.ClassID);
    data << uint8(charInfo.SexID);
    data << uint32(charInfo.Customizations.size());
    data << uint8(charInfo.ExperienceLevel);
    data << int32(charInfo.ZoneID);
    data << int32(charInfo.MapID);
    data << charInfo.PreloadPos;
    data << charInfo.GuildGUID;
    data << uint32(charInfo.Flags);
    data << uint32(charInfo.Flags2);
    data << uint32(charInfo.Flags3);
    data << uint32(charInfo.PetCreatureDisplayID);
    data << uint32(charInfo.PetExperienceLevel);
    data << uint32(charInfo.PetCreatureFamilyID);

    data << uint32(charInfo.ProfessionIds[0]);
    data << uint32(charInfo.ProfessionIds[1]);

    for (EnumCharactersResult::CharacterInfo::VisualItemInfo const& visualItem : charInfo.VisualItems)
        data << visualItem;

    data << uint32(charInfo.LastPlayedTime);
    data << uint16(charInfo.SpecID);
    data << uint32(charInfo.Unknown703);
    data << uint32(charInfo.LastLoginVersion);
    data << uint32(charInfo.Flags4);
    data << uint32(charInfo.MailSenders.size());
    data << uint32(charInfo.MailSenderTypes.size());
    data << uint32(charInfo.OverrideSelectScreenFileDataID);

    for (ChrCustomizationChoice const& customization : charInfo.Customizations)
        data << customization;

    if (!charInfo.MailSenderTypes.empty())
        data.append(charInfo.MailSenderTypes.data(), charInfo.MailSenderTypes.size());

    data.WriteBits(charInfo.Name.length(), 6);
    data.WriteBit(charInfo.FirstLogin);
    data.WriteBit(charInfo.BoostInProgress);
    data.WriteBits(charInfo.unkWod61x, 5);

    for (std::string const& str : charInfo.MailSenders)
        data.WriteBits(str.length() + 1, 6);

    data.FlushBits();

    for (std::string const& str : charInfo.MailSenders)
        if (!str.empty())
            data << str;

    data.WriteString(charInfo.Name);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, EnumCharactersResult::RaceUnlock const& raceUnlock)
{
    data << int32(raceUnlock.RaceID);
    data.WriteBit(raceUnlock.HasExpansion);
    data.WriteBit(raceUnlock.HasAchievement);
    data.WriteBit(raceUnlock.HasHeritageArmor);
    data.FlushBits();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, EnumCharactersResult::UnlockedConditionalAppearance const& unlockedConditionalAppearance)
{
    data << int32(unlockedConditionalAppearance.AchievementID);
    data << int32(unlockedConditionalAppearance.Unused);

    return data;
}

WorldPacket const* EnumCharactersResult::Write()
{
    _worldPacket.reserve(9 + Characters.size() * sizeof(CharacterInfo) + RaceUnlockData.size() * sizeof(RaceUnlock));

    _worldPacket.WriteBit(Success);
    _worldPacket.WriteBit(IsDeletedCharacters);
    _worldPacket.WriteBit(IsNewPlayerRestrictionSkipped);
    _worldPacket.WriteBit(IsNewPlayerRestricted);
    _worldPacket.WriteBit(IsNewPlayer);
    _worldPacket.WriteBit(DisabledClassesMask.is_initialized());
    _worldPacket.WriteBit(IsAlliedRacesCreationAllowed);
    _worldPacket << uint32(Characters.size());
    _worldPacket << int32(MaxCharacterLevel);
    _worldPacket << uint32(RaceUnlockData.size());
    _worldPacket << uint32(UnlockedConditionalAppearances.size());

    if (DisabledClassesMask)
        _worldPacket << uint32(*DisabledClassesMask);

    for (UnlockedConditionalAppearance const& unlockedConditionalAppearance : UnlockedConditionalAppearances)
        _worldPacket << unlockedConditionalAppearance;

    for (CharacterInfo const& charInfo : Characters)
        _worldPacket << charInfo;

    for (RaceUnlock const& raceUnlock : RaceUnlockData)
        _worldPacket << raceUnlock;

    return &_worldPacket;
}

void CheckCharacterNameAvailability::Read()
{
    _worldPacket >> SequenceIndex;
    Name = _worldPacket.ReadString(_worldPacket.ReadBits(6));
}

WorldPacket const* CheckCharacterNameAvailabilityResult::Write()
{
    _worldPacket << uint32(SequenceIndex);
    _worldPacket << uint32(Result);

    return &_worldPacket;
}

void CreateCharacter::Read()
{
    CreateInfo = std::make_shared<CharacterCreateInfo>();
    uint32 nameLength = _worldPacket.ReadBits(6);
    bool const hasTemplateSet = _worldPacket.ReadBit();
    CreateInfo->IsTrialBoost = _worldPacket.ReadBit();
    CreateInfo->UseNPE = _worldPacket.ReadBit();

    _worldPacket >> CreateInfo->Race;
    _worldPacket >> CreateInfo->Class;
    _worldPacket >> CreateInfo->Sex;
    CreateInfo->Customizations.resize(_worldPacket.read<uint32>());
    CreateInfo->Name = _worldPacket.ReadString(nameLength);
    if (hasTemplateSet)
        CreateInfo->TemplateSet = _worldPacket.read<int32>();

    for (ChrCustomizationChoice& customization : CreateInfo->Customizations)
        _worldPacket >> customization;

    SortCustomizations(CreateInfo->Customizations);
}

WorldPacket const* CreateChar::Write()
{
    _worldPacket << uint8(Code);
    _worldPacket << Guid;
    return &_worldPacket;
}

void CharDelete::Read()
{
    _worldPacket >> Guid;
}

WorldPacket const* DeleteChar::Write()
{
    _worldPacket << uint8(Code);
    return &_worldPacket;
}

void CharacterRenameRequest::Read()
{
    RenameInfo = std::make_shared<CharacterRenameInfo>();
    _worldPacket >> RenameInfo->Guid;
    RenameInfo->NewName = _worldPacket.ReadString(_worldPacket.ReadBits(6));
}

WorldPacket const* CharacterRenameResult::Write()
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

void CharCustomize::Read()
{
    CustomizeInfo = std::make_shared<CharCustomizeInfo>();
    _worldPacket >> CustomizeInfo->CharGUID;
    _worldPacket >> CustomizeInfo->SexID;
    CustomizeInfo->Customizations.resize(_worldPacket.read<uint32>());
    for (ChrCustomizationChoice& customization : CustomizeInfo->Customizations)
        _worldPacket >> customization;

    SortCustomizations(CustomizeInfo->Customizations);

    CustomizeInfo->CharName = _worldPacket.ReadString(_worldPacket.ReadBits(6));
}

void CharRaceOrFactionChange::Read()
{
    RaceOrFactionChangeInfo = std::make_shared<CharRaceOrFactionChangeInfo>();

    RaceOrFactionChangeInfo->FactionChange = _worldPacket.ReadBit();

    uint32 nameLength = _worldPacket.ReadBits(6);

    _worldPacket >> RaceOrFactionChangeInfo->Guid;
    _worldPacket >> RaceOrFactionChangeInfo->SexID;
    _worldPacket >> RaceOrFactionChangeInfo->RaceID;
    RaceOrFactionChangeInfo->Customizations.resize(_worldPacket.read<uint32>());
    RaceOrFactionChangeInfo->Name = _worldPacket.ReadString(nameLength);
    for (ChrCustomizationChoice& customization : RaceOrFactionChangeInfo->Customizations)
        _worldPacket >> customization;

    SortCustomizations(RaceOrFactionChangeInfo->Customizations);
}

WorldPacket const* CharFactionChangeResult::Write()
{
    _worldPacket << uint8(Result);
    _worldPacket << Guid;
    _worldPacket.WriteBit(Display.is_initialized());
    _worldPacket.FlushBits();

    if (Display)
    {
        _worldPacket.WriteBits(Display->Name.length(), 6);
        _worldPacket << uint8(Display->SexID);
        _worldPacket << uint8(Display->RaceID);
        _worldPacket << uint32(Display->Customizations->size());
        _worldPacket.WriteString(Display->Name);
        for (ChrCustomizationChoice customization : *Display->Customizations)
            _worldPacket << customization;
    }

    return &_worldPacket;
}

void GenerateRandomCharacterName::Read()
{
    _worldPacket >> Race;
    _worldPacket >> Sex;
}

WorldPacket const* GenerateRandomCharacterNameResult::Write()
{
    _worldPacket.WriteBit(Success);
    _worldPacket.WriteBits(Name.length(), 6);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(Name);

    return &_worldPacket;
}

ReorderCharacters::ReorderCharacters(WorldPacket&& packet) : ClientPacket(CMSG_REORDER_CHARACTERS, std::move(packet))
{
}

void ReorderCharacters::Read()
{
    Entries.resize(_worldPacket.ReadBits(9));
    for (ReorderInfo& reorderInfo : Entries)
    {
        _worldPacket >> reorderInfo.PlayerGUID;
        _worldPacket >> reorderInfo.NewPosition;
    }
}

void UndeleteCharacter::Read()
{
    UndeleteInfo = std::make_shared<CharacterUndeleteInfo>();
    _worldPacket >> UndeleteInfo->ClientToken;
    _worldPacket >> UndeleteInfo->CharacterGuid;
}

WorldPacket const* UndeleteCharacterResponse::Write()
{
    ASSERT(UndeleteInfo);
    _worldPacket << int32(UndeleteInfo->ClientToken);
    _worldPacket << uint32(Result);
    _worldPacket << UndeleteInfo->CharacterGuid;
    return &_worldPacket;
}

WorldPacket const* UndeleteCooldownStatusResponse::Write()
{
    _worldPacket.WriteBit(OnCooldown);
    _worldPacket << uint32(MaxCooldown);
    _worldPacket << uint32(CurrentCooldown);
    return &_worldPacket;
}

void PlayerLogin::Read()
{
    _worldPacket >> Guid;
    _worldPacket >> FarClip;
}

WorldPacket const* LoginVerifyWorld::Write()
{
    _worldPacket << int32(MapID);
    _worldPacket << Pos;
    _worldPacket << uint32(Reason);
    return &_worldPacket;
}

WorldPacket const* CharacterLoginFailed::Write()
{
    _worldPacket << uint8(Code);
    return &_worldPacket;
}

void LogoutRequest::Read()
{
    IdleLogout = _worldPacket.ReadBit();
}

WorldPacket const* LogoutResponse::Write()
{
    _worldPacket << int32(LogoutResult);
    _worldPacket.WriteBit(Instant);
    _worldPacket.FlushBits();
    return &_worldPacket;
}

void LoadingScreenNotify::Read()
{
    _worldPacket >> MapID;
    Showing = _worldPacket.ReadBit();
}

WorldPacket const* InitialSetup::Write()
{
    _worldPacket << uint8(ServerExpansionLevel);
    _worldPacket << uint8(ServerExpansionTier);

    return &_worldPacket;
}

void SetActionBarToggles::Read()
{
    _worldPacket >> Mask;
}

void RequestPlayedTime::Read()
{
    TriggerScriptEvent = _worldPacket.ReadBit();
}

WorldPacket const* PlayedTime::Write()
{
    _worldPacket << int32(TotalTime);
    _worldPacket << int32(LevelTime);
    _worldPacket.WriteBit(TriggerEvent);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void SetTitle::Read()
{
    _worldPacket >> TitleID;
}

void AlterApperance::Read()
{
    Customizations.resize(_worldPacket.read<uint32>());
    _worldPacket >> NewSex;
    for (ChrCustomizationChoice& customization : Customizations)
        _worldPacket >> customization;

    SortCustomizations(Customizations);
}

WorldPacket const* BarberShopResult::Write()
{
    _worldPacket << int32(Result);
    return &_worldPacket;
}

WorldPacket const* LogXPGain::Write()
{
    _worldPacket << Victim;
    _worldPacket << int32(Original);
    _worldPacket << uint8(Reason);
    _worldPacket << int32(Amount);
    _worldPacket << float(GroupBonus);
    _worldPacket << uint8(ReferAFriendBonusType);

    return &_worldPacket;
}

WorldPacket const* TitleEarned::Write()
{
    _worldPacket << uint32(Index);

    return &_worldPacket;
}

void SetFactionAtWar::Read()
{
    _worldPacket >> FactionIndex;
}

void SetFactionNotAtWar::Read()
{
    _worldPacket >> FactionIndex;
}

void SetFactionInactive::Read()
{
    _worldPacket >> Index;
    State = _worldPacket.ReadBit();
}

void SetWatchedFaction::Read()
{
    _worldPacket >> FactionIndex;
}

WorldPacket const* SetFactionVisible::Write()
{
    _worldPacket << FactionIndex;
    return &_worldPacket;
}

CharCustomizeSuccess::CharCustomizeSuccess(CharCustomizeInfo const* info)
    : ServerPacket(SMSG_CHAR_CUSTOMIZE_SUCCESS, 16 + 1 + 1 + 1 + 1 + 1 + 1 + 1), Customizations(info->Customizations)
{
    CharGUID = info->CharGUID;
    SexID = info->SexID;
    CharName = info->CharName;
}

WorldPacket const* CharCustomizeSuccess::Write()
{
    _worldPacket << CharGUID;
    _worldPacket << uint8(SexID);
    _worldPacket << uint32(Customizations.size());
    for (ChrCustomizationChoice customization : Customizations)
        _worldPacket << customization;

    _worldPacket.WriteBits(CharName.length(), 6);
    _worldPacket.FlushBits();
    _worldPacket.WriteString(CharName);

    return &_worldPacket;
}

WorldPacket const* CharCustomizeFailure::Write()
{
    _worldPacket << uint8(Result);
    _worldPacket << CharGUID;

    return &_worldPacket;
}

void SetPlayerDeclinedNames::Read()
{
    _worldPacket >> Player;

    uint8 stringLengths[MAX_DECLINED_NAME_CASES];

    for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
        stringLengths[i] = _worldPacket.ReadBits(7);

    for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
        DeclinedNames.name[i] = _worldPacket.ReadString(stringLengths[i]);
}

WorldPacket const * SetPlayerDeclinedNamesResult::Write()
{
    _worldPacket << int32(ResultCode);
    _worldPacket << Player;

    return &_worldPacket;
}
}
}
