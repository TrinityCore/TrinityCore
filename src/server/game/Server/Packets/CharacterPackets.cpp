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
#include "PacketOperators.h"
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

namespace WorldPackets::Character
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
    //  18                     19               20                     21                      22                            23
    // "character_banned.guid, characters.slot, characters.createTime, characters.logout_time, characters.activeTalentGroup, characters.lastLoginBuild, "
    //  24                                    25                                    26                                    27                                    28
    // "characters.personalTabardEmblemStyle, characters.personalTabardEmblemColor, characters.personalTabardBorderStyle, characters.personalTabardBorderColor, characters.personalTabardBackgroundColor "
    //  29
    // "character_declinedname.genitive"

    Guid              = ObjectGuid::Create<HighGuid::Player>(fields[0].GetUInt64());
    VirtualRealmAddress = GetVirtualRealmAddress();
    GuildClubMemberID = ::Battlenet::Services::Clubs::CreateClubMemberId(Guid);
    Name              = fields[1].GetStringView();
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

    if (atLoginFlags & AT_LOGIN_RESET_TALENTS)
        Flags |= CHARACTER_FLAG_RESET_TALENTS_ON_LOGIN;

    if (atLoginFlags & AT_LOGIN_RESURRECT)
        playerFlags &= ~PLAYER_FLAGS_GHOST;

    if (playerFlags & PLAYER_FLAGS_GHOST)
        Flags |= CHARACTER_FLAG_GHOST;

    if (atLoginFlags & AT_LOGIN_RENAME)
        Flags |= CHARACTER_FLAG_RENAME;

    if (fields[18].GetUInt64())
        Flags |= CHARACTER_FLAG_LOCKED_BY_BILLING;

    if (sWorld->getBoolConfig(CONFIG_DECLINED_NAMES_USED) && !fields[29].GetStringView().empty())
        Flags |= CHARACTER_FLAG_DECLINED;

    if (atLoginFlags & AT_LOGIN_CUSTOMIZE)
        Flags2 = CHARACTER_FLAG_2_CUSTOMIZE;
    else if (atLoginFlags & AT_LOGIN_CHANGE_FACTION)
        Flags2 = CHARACTER_FLAG_2_FACTION_CHANGE;
    else if (atLoginFlags & AT_LOGIN_CHANGE_RACE)
        Flags2 = CHARACTER_FLAG_2_RACE_CHANGE;

    if (playerFlags & PLAYER_FLAGS_NO_XP_GAIN)
        Flags2 |= CHARACTER_FLAG_2_NO_XP_GAIN;

    if (playerFlags & PLAYER_FLAGS_LOW_LEVEL_RAID_ENABLED)
        Flags2 |= CHARACTER_FLAG_2_LOW_LEVEL_RAID_ENABLED;

    if (playerFlags & PLAYER_FLAGS_AUTO_DECLINE_GUILD)
        Flags2 |= CHARACTER_FLAG_2_AUTO_DECLINE_GUILD;

    if (playerFlags & PLAYER_FLAGS_HIDE_ACCOUNT_ACHIEVEMENTS)
        Flags3 |= CHARACTER_FLAG_3_HIDE_ACCOUNT_ACHIEVEMENTS;

    if (playerFlags & PLAYER_FLAGS_WAR_MODE_DESIRED)
        Flags3 |= CHARACTER_FLAG_3_WAR_MODE_DESIRED;

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
    CreateTime = fields[20].GetInt64();
    LastActiveTime = fields[21].GetInt64();
    if (ChrSpecializationEntry const* spec = sDB2Manager.GetChrSpecializationByIndex(ClassID, fields[22].GetUInt8()))
        SpecID = spec->ID;

    LastLoginVersion = fields[23].GetUInt32();

    PersonalTabard.EmblemStyle = fields[24].GetInt32();
    PersonalTabard.EmblemColor = fields[25].GetInt32();
    PersonalTabard.BorderStyle = fields[26].GetInt32();
    PersonalTabard.BorderColor = fields[27].GetInt32();
    PersonalTabard.BackgroundColor = fields[28].GetInt32();

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
    data << uint32(visualItem.ItemID);
    data << uint32(visualItem.TransmogrifiedItemID);
    data << uint8(visualItem.Subclass);
    data << uint8(visualItem.InvType);
    data << uint32(visualItem.DisplayID);
    data << uint32(visualItem.DisplayEnchantID);
    data << int32(visualItem.SecondaryItemModifiedAppearanceID);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, EnumCharactersResult::CharacterInfoBasic const& charInfo)
{
    data << charInfo.Guid;
    data << uint32(charInfo.VirtualRealmAddress);
    data << uint16(charInfo.ListPosition);
    data << uint8(charInfo.RaceID);
    data << uint8(charInfo.SexID);
    data << uint8(charInfo.ClassID);
    data << int16(charInfo.SpecID);
    data << Size<uint32>(charInfo.Customizations);
    data << uint8(charInfo.ExperienceLevel);
    data << int32(charInfo.MapID);
    data << int32(charInfo.ZoneID);
    data << charInfo.PreloadPos;
    data << uint64(charInfo.GuildClubMemberID);
    data << charInfo.GuildGUID;
    data << uint32(charInfo.Flags);
    data << uint32(charInfo.Flags2);
    data << uint32(charInfo.Flags3);
    data << uint32(charInfo.Flags4);
    data << uint8(charInfo.CantLoginReason);

    data << uint32(charInfo.PetCreatureDisplayID);
    data << uint32(charInfo.PetExperienceLevel);
    data << uint32(charInfo.PetCreatureFamilyID);

    for (EnumCharactersResult::CharacterInfoBasic::VisualItemInfo const& visualItem : charInfo.VisualItems)
        data << visualItem;

    data << int32(charInfo.SaveVersion);
    data << charInfo.CreateTime;
    data << charInfo.LastActiveTime;
    data << int32(charInfo.LastLoginVersion);
    data << charInfo.PersonalTabard;

    data << uint32(charInfo.ProfessionIds[0]);
    data << uint32(charInfo.ProfessionIds[1]);

    data << int32(charInfo.TimerunningSeasonID);
    data << uint32(charInfo.OverrideSelectScreenFileDataID);
    data << uint32(charInfo.RealmQueue);

    for (ChrCustomizationChoice const& customization : charInfo.Customizations)
        data << customization;

    data << SizedString::BitsSize<6>(charInfo.Name);
    data << Bits<1>(charInfo.FirstLogin);
    data << Bits<1>(charInfo.RealmInfoFound);
    data << Bits<1>(charInfo.IsRealmOffline);

    data.FlushBits();

    data << SizedString::Data(charInfo.Name);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, EnumCharactersResult::CharacterRestrictionAndMailData const& restrictionsAndMails)
{
    ASSERT(restrictionsAndMails.MailSenders.size() == restrictionsAndMails.MailSenderTypes.size());

    data << Bits<1>(restrictionsAndMails.BoostInProgress);
    data << Bits<1>(restrictionsAndMails.RpeAvailable);
    data.FlushBits();

    data << uint32(restrictionsAndMails.RestrictionFlags);
    data << Size<uint32>(restrictionsAndMails.MailSenders);
    data << Size<uint32>(restrictionsAndMails.MailSenderTypes);

    if (!restrictionsAndMails.MailSenderTypes.empty())
        data.append(restrictionsAndMails.MailSenderTypes.data(), restrictionsAndMails.MailSenderTypes.size());

    for (std::string const& str : restrictionsAndMails.MailSenders)
        data << SizedCString::BitsSize<6>(str);

    data.FlushBits();

    for (std::string const& str : restrictionsAndMails.MailSenders)
        data << SizedCString::Data(str);

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
    data << float(charInfo.AvgEquippedItemLevel);
    data << float(charInfo.CurrentSeasonMythicPlusOverallScore);
    data << int32(charInfo.CurrentSeasonBestPvpRating);
    data << int8(charInfo.PvpRatingBracket);
    data << int16(charInfo.PvpRatingAssociatedSpecID);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, EnumCharactersResult::ClassUnlock const& classUnlock)
{
    data << int8(classUnlock.ClassID);
    data << uint32(classUnlock.AchievementID);
    data << Bits<1>(classUnlock.HasUnlockedAchievement);
    data.FlushBits();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, EnumCharactersResult::RaceUnlock const& raceUnlock)
{
    data << int8(raceUnlock.RaceID);
    data << Size<uint32>(raceUnlock.ClassUnlocks);
    data << Bits<1>(raceUnlock.HasUnlockedLicense);
    data << Bits<1>(raceUnlock.HasUnlockedAchievement);
    data << Bits<1>(raceUnlock.HasHeritageArmorUnlockAchievement);
    data << Bits<1>(raceUnlock.HideRaceOnClient);
    data << Bits<1>(raceUnlock.FactionBalanceDisabled);
    data.FlushBits();

    for (EnumCharactersResult::ClassUnlock const& classUnlock : raceUnlock.ClassUnlocks)
        data << classUnlock;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, EnumCharactersResult::UnlockedConditionalAppearance const& unlockedConditionalAppearance)
{
    data << int32(unlockedConditionalAppearance.AchievementID);
    data << int32(unlockedConditionalAppearance.ConditionalType);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, EnumCharactersResult::RaceLimitDisableInfo const& raceLimitDisableInfo)
{
    data << int8(raceLimitDisableInfo.RaceID);
    data << int8(raceLimitDisableInfo.Reason);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WarbandGroupMember const& warbandGroupMember)
{
    data << uint32(warbandGroupMember.WarbandScenePlacementID);
    data << int32(warbandGroupMember.Type);
    data << int32(warbandGroupMember.ContentSetID);
    if (warbandGroupMember.Type == 0)
        data << warbandGroupMember.Guid;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WarbandGroup const& warbandGroup)
{
    data << uint64(warbandGroup.GroupID);
    data << uint8(warbandGroup.OrderIndex);
    data << uint32(warbandGroup.WarbandSceneID);
    data << uint32(warbandGroup.Flags);
    data << int32(warbandGroup.ContentSetID);
    data << Size<uint32>(warbandGroup.Members);

    for (WarbandGroupMember const& member : warbandGroup.Members)
        data << member;

    data << SizedString::BitsSize<9>(warbandGroup.Name);
    data.FlushBits();

    data << SizedString::Data(warbandGroup.Name);

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
    _worldPacket << Bits<1>(IgnoreNewPlayerRestrictions);
    _worldPacket << Bits<1>(IsRestrictedNewPlayer);
    _worldPacket << Bits<1>(IsNewcomerChatCompleted);
    _worldPacket << Bits<1>(IsRestrictedTrial);
    _worldPacket << Bits<1>(IsAccountLapsedPlayer);
    _worldPacket << OptionalInit(ClassDisableMask);
    _worldPacket << Bits<1>(ForceCharacterListSort);
    _worldPacket << Size<uint32>(Characters);
    _worldPacket << Size<uint32>(RegionwideCharacters);
    _worldPacket << int32(MaxCharacterLevel);
    _worldPacket << Size<uint32>(RaceUnlockData);
    _worldPacket << Size<uint32>(UnlockedConditionalAppearances);
    _worldPacket << Size<uint32>(RaceLimitDisables);
    _worldPacket << Size<uint32>(WarbandGroups);

    if (ClassDisableMask)
        _worldPacket << uint32(*ClassDisableMask);

    for (UnlockedConditionalAppearance const& unlockedConditionalAppearance : UnlockedConditionalAppearances)
        _worldPacket << unlockedConditionalAppearance;

    for (RaceLimitDisableInfo const& raceLimitDisableInfo : RaceLimitDisables)
        _worldPacket << raceLimitDisableInfo;

    for (CharacterInfo const& charInfo : Characters)
        _worldPacket << charInfo;

    for (RegionwideCharacterListEntry const& charInfo : RegionwideCharacters)
        _worldPacket << charInfo;

    for (RaceUnlock const& raceUnlock : RaceUnlockData)
        _worldPacket << raceUnlock;

    for (WarbandGroup const& warbandGroup : WarbandGroups)
        _worldPacket << warbandGroup;

    return &_worldPacket;
}

void CheckCharacterNameAvailability::Read()
{
    _worldPacket >> SequenceIndex;
    _worldPacket >> SizedString::BitsSize<6>(Name);

    _worldPacket >> SizedString::Data(Name);
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

    _worldPacket >> SizedString::BitsSize<6>(CreateInfo->Name);
    _worldPacket >> OptionalInit(CreateInfo->TemplateSet);
    _worldPacket >> Bits<1>(CreateInfo->IsTrialBoost);
    _worldPacket >> Bits<1>(CreateInfo->UseNPE);
    _worldPacket >> Bits<1>(CreateInfo->HardcoreSelfFound);
    _worldPacket >> CreateInfo->Race;
    _worldPacket >> CreateInfo->Class;
    _worldPacket >> CreateInfo->Sex;
    _worldPacket >> Size<uint32>(CreateInfo->Customizations);
    _worldPacket >> CreateInfo->TimerunningSeasonID;
    _worldPacket >> SizedString::Data(CreateInfo->Name);
    if (CreateInfo->TemplateSet)
        _worldPacket >> *CreateInfo->TemplateSet;

    for (ChrCustomizationChoice& customization : CreateInfo->Customizations)
        _worldPacket >> customization;

    SortCustomizations(CreateInfo->Customizations);
}

WorldPacket const* CreateChar::Write()
{
    _worldPacket << uint32(Code);
    _worldPacket << Guid;

    return &_worldPacket;
}

void CharDelete::Read()
{
    _worldPacket >> Guid;
}

WorldPacket const* DeleteChar::Write()
{
    _worldPacket << uint32(Code);

    return &_worldPacket;
}

void CharacterRenameRequest::Read()
{
    RenameInfo = std::make_shared<CharacterRenameInfo>();

    _worldPacket >> RenameInfo->Guid;
    _worldPacket >> SizedString::BitsSize<6>(RenameInfo->NewName);

    _worldPacket >> SizedString::Data(RenameInfo->NewName);
}

WorldPacket const* CharacterRenameResult::Write()
{
    _worldPacket << uint32(Result);
    _worldPacket << OptionalInit(Guid);
    _worldPacket << SizedString::BitsSize<6>(Name);
    _worldPacket.FlushBits();

    if (Guid)
        _worldPacket << *Guid;

    _worldPacket << SizedString::Data(Name);

    return &_worldPacket;
}

void CharCustomize::Read()
{
    CustomizeInfo = std::make_shared<CharCustomizeInfo>();

    _worldPacket >> CustomizeInfo->CharGUID;
    _worldPacket >> CustomizeInfo->SexID;
    _worldPacket >> Size<uint32>(CustomizeInfo->Customizations);
    for (ChrCustomizationChoice& customization : CustomizeInfo->Customizations)
        _worldPacket >> customization;

    _worldPacket >> SizedString::BitsSize<6>(CustomizeInfo->CharName);
    _worldPacket >> SizedString::Data(CustomizeInfo->CharName);

    SortCustomizations(CustomizeInfo->Customizations);
}

void CharRaceOrFactionChange::Read()
{
    RaceOrFactionChangeInfo = std::make_shared<CharRaceOrFactionChangeInfo>();

    _worldPacket >> Bits<1>(RaceOrFactionChangeInfo->FactionChange);
    _worldPacket >> SizedString::BitsSize<6>(RaceOrFactionChangeInfo->Name);
    _worldPacket >> RaceOrFactionChangeInfo->Guid;
    _worldPacket >> RaceOrFactionChangeInfo->SexID;
    _worldPacket >> RaceOrFactionChangeInfo->RaceID;
    _worldPacket >> RaceOrFactionChangeInfo->InitialRaceID;
    _worldPacket >> Size<uint32>(RaceOrFactionChangeInfo->Customizations);
    _worldPacket >> SizedString::Data(RaceOrFactionChangeInfo->Name);
    for (ChrCustomizationChoice& customization : RaceOrFactionChangeInfo->Customizations)
        _worldPacket >> customization;

    SortCustomizations(RaceOrFactionChangeInfo->Customizations);
}

WorldPacket const* CharFactionChangeResult::Write()
{
    _worldPacket << uint32(Result);
    _worldPacket << Guid;
    _worldPacket << OptionalInit(Display);
    _worldPacket.FlushBits();

    if (Display)
    {
        _worldPacket << SizedString::BitsSize<6>(Display->Name);
        _worldPacket << uint8(Display->SexID);
        _worldPacket << uint8(Display->RaceID);
        _worldPacket << Size<uint32>(*Display->Customizations);
        _worldPacket << SizedString::Data(Display->Name);
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
    _worldPacket << Bits<1>(Success);
    _worldPacket << SizedString::BitsSize<6>(Name);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(Name);

    return &_worldPacket;
}

ReorderCharacters::ReorderCharacters(WorldPacket&& packet) : ClientPacket(CMSG_REORDER_CHARACTERS, std::move(packet))
{
}

void ReorderCharacters::Read()
{
    _worldPacket >> BitsSize<9>(Entries);
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
    _worldPacket << uint32(MaxCooldown);
    _worldPacket << uint32(CurrentCooldown);
    _worldPacket << Bits<1>(OnCooldown);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void PlayerLogin::Read()
{
    _worldPacket >> Guid;
    _worldPacket >> FarClip;
    _worldPacket >> Bits<1>(RPE);
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
    _worldPacket >> Bits<1>(IdleLogout);
}

WorldPacket const* LogoutResponse::Write()
{
    _worldPacket << int32(LogoutResult);
    _worldPacket << Bits<1>(Instant);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, GameModeData const& gameModeData)
{
    data << int32(gameModeData.Unknown_1107_0);
    data << gameModeData.Guid;
    data << uint8(gameModeData.GameMode);
    data << int32(gameModeData.MapID);
    data << uint8(gameModeData.Unknown_1107_1);
    data << uint8(gameModeData.Unknown_1107_2);
    data << uint8(gameModeData.Unknown_1107_3);
    data << Size<uint32>(gameModeData.Customizations);
    data << Size<uint32>(gameModeData.Unknown_1107_4);

    for (ChrCustomizationChoice const& customization : gameModeData.Customizations)
        data << customization;

    for (ChrCustomizationChoice const& customization : gameModeData.Unknown_1107_4)
        data << customization;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, SwitchGameModeData const& switchGameModeData)
{
    data << Bits<1>(switchGameModeData.IsFastLogin);
    data << switchGameModeData.Current;
    data << switchGameModeData.New;

    return data;
}

WorldPacket const* LogoutComplete::Write()
{
    _worldPacket << OptionalInit(SwitchGameMode);
    _worldPacket.FlushBits();

    if (SwitchGameMode)
        _worldPacket << *SwitchGameMode;

    return &_worldPacket;
}

void LoadingScreenNotify::Read()
{
    _worldPacket >> MapID;
    _worldPacket >> Bits<1>(Showing);
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
    _worldPacket >> Bits<1>(TriggerScriptEvent);
}

WorldPacket const* PlayedTime::Write()
{
    _worldPacket << int32(TotalTime);
    _worldPacket << int32(LevelTime);
    _worldPacket << Bits<1>(TriggerEvent);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void SetTitle::Read()
{
    _worldPacket >> TitleID;
}

void AlterApperance::Read()
{
    _worldPacket >> Size<uint32>(Customizations);
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
    _worldPacket >> Bits<1>(State);
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
    _worldPacket << Size<uint32>(Customizations);
    for (ChrCustomizationChoice customization : Customizations)
        _worldPacket << customization;

    _worldPacket << SizedString::BitsSize<6>(CharName);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(CharName);

    return &_worldPacket;
}

WorldPacket const* CharCustomizeFailure::Write()
{
    _worldPacket << uint32(Result);
    _worldPacket << CharGUID;

    return &_worldPacket;
}

void SetPlayerDeclinedNames::Read()
{
    _worldPacket >> Player;

    for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
        _worldPacket >> SizedString::BitsSize<7>(DeclinedNames.name[i]);

    for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
        _worldPacket >> SizedString::Data(DeclinedNames.name[i]);
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
