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
#include "ClubUtils.h"
#include "DB2Stores.h"
#include "Field.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "StringConvert.h"
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
void SortCustomizations(Array<ChrCustomizationChoice, 250>& customizations)
{
    std::ranges::sort(customizations, std::ranges::less(), &ChrCustomizationChoice::ChrCustomizationOptionID);
}

ByteBuffer& operator<<(ByteBuffer& data, CustomTabardInfo const& customTabardInfo)
{
    data << int32(customTabardInfo.EmblemStyle);
    data << int32(customTabardInfo.EmblemColor);
    data << int32(customTabardInfo.BorderStyle);
    data << int32(customTabardInfo.BorderColor);
    data << int32(customTabardInfo.BackgroundColor);

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, CustomTabardInfo& customTabardInfo)
{
    data >> customTabardInfo.EmblemStyle;
    data >> customTabardInfo.EmblemColor;
    data >> customTabardInfo.BorderStyle;
    data >> customTabardInfo.BorderColor;
    data >> customTabardInfo.BackgroundColor;

    return data;
}

EnumCharacters::EnumCharacters(WorldPacket&& packet) : ClientPacket(std::move(packet))
{
    ASSERT(GetOpcode() == CMSG_ENUM_CHARACTERS || GetOpcode() == CMSG_ENUM_CHARACTERS_DELETED_BY_CLIENT);
}

EnumCharactersResult::CharacterInfoBasic::CharacterInfoBasic(Field const* fields)
{
    //         0                1                2                3                 4                  5
    // "SELECT characters.guid, characters.name, characters.race, characters.class, characters.gender, characters.level, "
    //  6                7               8                      9                      10
    // "characters.zone, characters.map, characters.position_x, characters.position_y, characters.position_z, "
    //  11                    12                      13                   14                   15                     16                   17
    // "guild_member.guildid, characters.playerFlags, characters.at_login, character_pet.entry, character_pet.modelid, character_pet.level, characters.equipmentCache, "
    //  18                     19               20                      21                            22
    // "character_banned.guid, characters.slot, characters.logout_time, characters.activeTalentGroup, characters.lastLoginBuild, "
    //  23                                    24                                    25                                    26                                    27
    // "characters.personalTabardEmblemStyle, characters.personalTabardEmblemColor, characters.personalTabardBorderStyle, characters.personalTabardBorderColor, characters.personalTabardBackgroundColor "
    //  28
    // "character_declinedname.genitive"

    Guid              = ObjectGuid::Create<HighGuid::Player>(fields[0].GetUInt64());
    VirtualRealmAddress = GetVirtualRealmAddress();
    GuildClubMemberID = ::Battlenet::Services::Clubs::CreateClubMemberId(Guid);
    Name              = fields[1].GetString();
    RaceID            = fields[2].GetUInt8();
    ClassID           = fields[3].GetUInt8();
    SexID             = fields[4].GetUInt8();
    ExperienceLevel   = fields[5].GetUInt8();
    ZoneID            = int32(fields[6].GetUInt16());
    MapID             = int32(fields[7].GetUInt16());
    PreloadPos        = Position(fields[8].GetFloat(), fields[9].GetFloat(), fields[10].GetFloat());

    if (ObjectGuid::LowType guildId = fields[11].GetUInt64())
        GuildGUID = ObjectGuid::Create<HighGuid::Guild>(guildId);

    uint32 playerFlags  = fields[12].GetUInt32();
    uint32 atLoginFlags = fields[13].GetUInt16();

    if (playerFlags & PLAYER_FLAGS_RESTING)
        Flags |= CHARACTER_FLAG_RESTING;

    if (atLoginFlags & AT_LOGIN_RESURRECT)
        playerFlags &= ~PLAYER_FLAGS_GHOST;

    if (playerFlags & PLAYER_FLAGS_GHOST)
        Flags |= CHARACTER_FLAG_GHOST;

    if (atLoginFlags & AT_LOGIN_RENAME)
        Flags |= CHARACTER_FLAG_RENAME;

    if (fields[18].GetUInt64())
        Flags |= CHARACTER_FLAG_LOCKED_BY_BILLING;

    if (sWorld->getBoolConfig(CONFIG_DECLINED_NAMES_USED) && !fields[28].GetString().empty())
        Flags |= CHARACTER_FLAG_DECLINED;

    if (atLoginFlags & AT_LOGIN_CUSTOMIZE)
        Flags2 = CHAR_CUSTOMIZE_FLAG_CUSTOMIZE;
    else if (atLoginFlags & AT_LOGIN_CHANGE_FACTION)
        Flags2 = CHAR_CUSTOMIZE_FLAG_FACTION;
    else if (atLoginFlags & AT_LOGIN_CHANGE_RACE)
        Flags2 = CHAR_CUSTOMIZE_FLAG_RACE;

    Flags3 = 0;
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

    ProfessionIds[0] = 0;
    ProfessionIds[1] = 0;

    std::vector<std::string_view> equipment = Trinity::Tokenize(fields[17].GetStringView(), ' ', false);
    ListPosition = fields[19].GetUInt8();
    LastPlayedTime = fields[20].GetInt64();
    if (ChrSpecializationEntry const* spec = sDB2Manager.GetChrSpecializationByIndex(ClassID, fields[21].GetUInt8()))
        SpecID = spec->ID;

    LastLoginVersion = fields[22].GetUInt32();

    PersonalTabard.EmblemStyle = fields[23].GetInt32();
    PersonalTabard.EmblemColor = fields[24].GetInt32();
    PersonalTabard.BorderStyle = fields[25].GetInt32();
    PersonalTabard.BorderColor = fields[26].GetInt32();
    PersonalTabard.BackgroundColor = fields[27].GetInt32();

    constexpr std::size_t equipmentFieldsPerSlot = 5;

    for (std::size_t slot = 0; slot < VisualItems.size() && (slot + 1) * equipmentFieldsPerSlot <= equipment.size(); ++slot)
    {
        std::size_t visualBase = slot * equipmentFieldsPerSlot;
        VisualItems[slot].InvType = Trinity::StringTo<uint8>(equipment[visualBase + 0]).value_or(0);
        VisualItems[slot].DisplayID = Trinity::StringTo<uint32>(equipment[visualBase + 1]).value_or(0);
        VisualItems[slot].DisplayEnchantID = Trinity::StringTo<uint32>(equipment[visualBase + 2]).value_or(0);
        VisualItems[slot].Subclass = Trinity::StringTo<uint8>(equipment[visualBase + 3]).value_or(0);
        VisualItems[slot].SecondaryItemModifiedAppearanceID = Trinity::StringTo<int32>(equipment[visualBase + 4]).value_or(0);
    }
}

ByteBuffer& operator<<(ByteBuffer& data, EnumCharactersResult::CharacterInfoBasic::VisualItemInfo const& visualItem)
{
    data << uint32(visualItem.DisplayID);
    data << uint8(visualItem.InvType);
    data << uint32(visualItem.DisplayEnchantID);
    data << uint8(visualItem.Subclass);
    data << int32(visualItem.SecondaryItemModifiedAppearanceID);
    data << uint32(visualItem.ItemID);
    data << uint32(visualItem.TransmogrifiedItemID);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, EnumCharactersResult::CharacterInfoBasic const& charInfo)
{
    data << charInfo.Guid;
    data << uint32(charInfo.VirtualRealmAddress);
    data << uint8(charInfo.ListPosition);
    data << uint8(charInfo.RaceID);
    data << uint8(charInfo.SexID);
    data << uint8(charInfo.ClassID);
    data << int16(charInfo.SpecID);
    data << uint32(charInfo.Customizations.size());
    data << uint8(charInfo.ExperienceLevel);
    data << int32(charInfo.MapID);
    data << int32(charInfo.ZoneID);
    data << charInfo.PreloadPos;
    data << uint64(charInfo.GuildClubMemberID);
    data << charInfo.GuildGUID;
    data << uint32(charInfo.Flags);
    data << uint32(charInfo.Flags2);
    data << uint32(charInfo.Flags3);
    data << uint8(charInfo.unkWod61x);

    data << uint32(charInfo.PetCreatureDisplayID);
    data << uint32(charInfo.PetExperienceLevel);
    data << uint32(charInfo.PetCreatureFamilyID);

    for (EnumCharactersResult::CharacterInfoBasic::VisualItemInfo const& visualItem : charInfo.VisualItems)
        data << visualItem;

    data << int32(charInfo.Unknown703);
    data << charInfo.LastPlayedTime;
    data << int32(charInfo.LastLoginVersion);
    data << charInfo.PersonalTabard;

    data << uint32(charInfo.ProfessionIds[0]);
    data << uint32(charInfo.ProfessionIds[1]);

    data << int32(charInfo.TimerunningSeasonID);
    data << uint32(charInfo.OverrideSelectScreenFileDataID);

    for (ChrCustomizationChoice const& customization : charInfo.Customizations)
        data << customization;

    data << BitsSize<6>(charInfo.Name);
    data << Bits<1>(charInfo.FirstLogin);

    data.FlushBits();

    data.WriteString(charInfo.Name);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, EnumCharactersResult::CharacterRestrictionAndMailData const& restrictionsAndMails)
{
    ASSERT(restrictionsAndMails.MailSenders.size() == restrictionsAndMails.MailSenderTypes.size());

    data << Bits<1>(restrictionsAndMails.BoostInProgress);
    data << Bits<1>(restrictionsAndMails.RpeResetAvailable);
    data << Bits<1>(restrictionsAndMails.RpeResetQuestClearAvailable);
    data.FlushBits();

    data << uint32(restrictionsAndMails.Flags4);
    data << uint32(restrictionsAndMails.MailSenders.size());
    data << uint32(restrictionsAndMails.MailSenderTypes.size());

    if (!restrictionsAndMails.MailSenderTypes.empty())
        data.append(restrictionsAndMails.MailSenderTypes.data(), restrictionsAndMails.MailSenderTypes.size());

    for (std::string const& str : restrictionsAndMails.MailSenders)
        data << Bits<6>(str.length() + 1);

    data.FlushBits();

    for (std::string const& str : restrictionsAndMails.MailSenders)
        if (!str.empty())
            data << str;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, EnumCharactersResult::CharacterInfo const& charInfo)
{
    data << charInfo.Basic;
    data << charInfo.RestrictionsAndMails;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, EnumCharactersResult::RegionwideCharacterListEntry const& charInfo)
{
    data << charInfo.Basic;
    data << uint64(charInfo.Money);
    data << float(charInfo.CurrentSeasonMythicPlusOverallScore);
    data << int32(charInfo.CurrentSeasonBestPvpRating);
    data << int8(charInfo.PvpRatingBracket);
    data << int16(charInfo.PvpRatingAssociatedSpecID);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, EnumCharactersResult::RaceUnlock const& raceUnlock)
{
    data << int32(raceUnlock.RaceID);
    data << Bits<1>(raceUnlock.HasExpansion);
    data << Bits<1>(raceUnlock.HasAchievement);
    data << Bits<1>(raceUnlock.HasHeritageArmor);
    data << Bits<1>(raceUnlock.IsLocked);
    data << Bits<1>(raceUnlock.Unused1027);
    data.FlushBits();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, EnumCharactersResult::UnlockedConditionalAppearance const& unlockedConditionalAppearance)
{
    data << int32(unlockedConditionalAppearance.AchievementID);
    data << int32(unlockedConditionalAppearance.Unused);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, EnumCharactersResult::RaceLimitDisableInfo const& raceLimitDisableInfo)
{
    data << int32(raceLimitDisableInfo.RaceID);
    data << int32(raceLimitDisableInfo.BlockReason);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WarbandGroupMember const& warbandGroupMember)
{
    data << int32(warbandGroupMember.WarbandScenePlacementID);
    data << int32(warbandGroupMember.Type);
    if (warbandGroupMember.Type == 0)
        data << warbandGroupMember.Guid;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WarbandGroup const& warbandGroup)
{
    data << uint64(warbandGroup.GroupID);
    data << uint8(warbandGroup.Unknown_1100);
    data << int32(warbandGroup.Flags);
    data << uint32(warbandGroup.Members.size());

    for (WarbandGroupMember const& member : warbandGroup.Members)
        data << member;

    return data;
}

EnumCharactersResult::CharacterInfo::CharacterInfo(Field const* fields) : Basic(fields)
{
}

EnumCharactersResult::RegionwideCharacterListEntry::RegionwideCharacterListEntry(Field const* fields) : Basic(fields)
{
}

WorldPacket const* EnumCharactersResult::Write()
{
    _worldPacket.reserve(9 + Characters.size() * sizeof(CharacterInfo) + RaceUnlockData.size() * sizeof(RaceUnlock));

    _worldPacket << Bits<1>(Success);
    _worldPacket << Bits<1>(Realmless);
    _worldPacket << Bits<1>(IsDeletedCharacters);
    _worldPacket << Bits<1>(IsNewPlayerRestrictionSkipped);
    _worldPacket << Bits<1>(IsNewPlayerRestricted);
    _worldPacket << Bits<1>(IsNewPlayer);
    _worldPacket << Bits<1>(IsTrialAccountRestricted);
    _worldPacket << OptionalInit(DisabledClassesMask);
    _worldPacket << Bits<1>(DontCreateCharacterDisplays);
    _worldPacket << uint32(Characters.size());
    _worldPacket << uint32(RegionwideCharacters.size());
    _worldPacket << int32(MaxCharacterLevel);
    _worldPacket << uint32(RaceUnlockData.size());
    _worldPacket << uint32(UnlockedConditionalAppearances.size());
    _worldPacket << uint32(RaceLimitDisables.size());
    _worldPacket << uint32(WarbandGroups.size());

    if (DisabledClassesMask)
        _worldPacket << uint32(*DisabledClassesMask);

    for (UnlockedConditionalAppearance const& unlockedConditionalAppearance : UnlockedConditionalAppearances)
        _worldPacket << unlockedConditionalAppearance;

    for (RaceLimitDisableInfo const& raceLimitDisableInfo : RaceLimitDisables)
        _worldPacket << raceLimitDisableInfo;

    for (WarbandGroup const& warbandGroup : WarbandGroups)
        _worldPacket << warbandGroup;

    for (CharacterInfo const& charInfo : Characters)
        _worldPacket << charInfo;

    for (RegionwideCharacterListEntry const& charInfo : RegionwideCharacters)
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
    CreateInfo->HardcoreSelfFound = _worldPacket.ReadBit();

    _worldPacket >> CreateInfo->Race;
    _worldPacket >> CreateInfo->Class;
    _worldPacket >> CreateInfo->Sex;
    CreateInfo->Customizations.resize(_worldPacket.read<uint32>());
    _worldPacket >> CreateInfo->TimerunningSeasonID;
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
    _worldPacket.WriteBit(Guid.has_value());
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
    _worldPacket >> RaceOrFactionChangeInfo->InitialRaceID;
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
    _worldPacket.WriteBit(Display.has_value());
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
    _worldPacket >> CustomizedRace;
    _worldPacket >> CustomizedChrModelID;
    _worldPacket >> UnalteredVisualRaceID;
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

void SavePersonalEmblem::Read()
{
    _worldPacket >> Vendor;
    _worldPacket >> PersonalTabard;
}

WorldPacket const* PlayerSavePersonalEmblem::Write()
{
    _worldPacket << int32(Error);

    return &_worldPacket;
}
}
}
