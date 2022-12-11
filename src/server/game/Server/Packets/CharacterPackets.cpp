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
#include "DBCStores.h"
#include "Field.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "World.h"

WorldPackets::Character::EnumCharactersResult::CharacterInfo::CharacterInfo(Field* fields)
{
    //           0                1                2                3                 4                  5                6                7
    //    SELECT characters.guid, characters.name, characters.race, characters.class, characters.gender, characters.skin, characters.face, characters.hairStyle,
    //    8                     9                       10                11               12              13                     14                     15
    //    characters.hairColor, characters.facialStyle, characters.level, characters.zone, characters.map, characters.position_x, characters.position_y, characters.position_z,
    //    16                    17                      18                   19                   20                     21                   22
    //    guild_member.guildid, characters.playerFlags, characters.at_login, character_pet.entry, character_pet.modelid, character_pet.level, characters.data,
    //    23                     24               25
    //    character_banned.guid, characters.slot, character_declinedname.genitive

    Guid              = ObjectGuid::Create<HighGuid::Player>(fields[0].GetUInt32());
    Name              = fields[1].GetString();
    RaceID            = fields[2].GetUInt8();
    ClassID           = fields[3].GetUInt8();
    SexID             = fields[4].GetUInt8();
    SkinID            = fields[5].GetUInt8();
    FaceID            = fields[6].GetUInt8();
    HairStyle         = fields[7].GetUInt8();
    HairColor         = fields[8].GetUInt8();
    FacialHair        = fields[9].GetUInt8();
    ExperienceLevel   = fields[10].GetUInt8();
    ZoneID            = int32(fields[11].GetUInt16());
    MapID             = int32(fields[12].GetUInt16());
    PreloadPos        = Position(fields[13].GetFloat(), fields[14].GetFloat(), fields[15].GetFloat());

    if (ObjectGuid::LowType guildId = fields[16].GetUInt32())
        GuildGUID = ObjectGuid::Create<HighGuid::Guild>(guildId);

    uint32 playerFlags  = fields[17].GetUInt32();
    uint32 atLoginFlags = fields[18].GetUInt16();

    if (atLoginFlags & AT_LOGIN_RESURRECT)
        playerFlags &= ~PLAYER_FLAGS_GHOST;

    if (playerFlags & PLAYER_FLAGS_GHOST)
        Flags |= CHARACTER_FLAG_GHOST;

    if (atLoginFlags & AT_LOGIN_RENAME)
        Flags |= CHARACTER_FLAG_RENAME;

    if (fields[23].GetUInt32())
        Flags |= CHARACTER_FLAG_LOCKED_BY_BILLING;

    if (sWorld->getBoolConfig(CONFIG_DECLINED_NAMES_USED) && !fields[22].GetString().empty())
        Flags |= CHARACTER_FLAG_DECLINED;

    if (atLoginFlags & AT_LOGIN_CUSTOMIZE)
        Flags2 = CHAR_CUSTOMIZE_FLAG_CUSTOMIZE;
    else if (atLoginFlags & AT_LOGIN_CHANGE_FACTION)
        Flags2 = CHAR_CUSTOMIZE_FLAG_FACTION;
    else if (atLoginFlags & AT_LOGIN_CHANGE_RACE)
        Flags2 = CHAR_CUSTOMIZE_FLAG_RACE;

    FirstLogin = (atLoginFlags & AT_LOGIN_FIRST) != 0;

    if (playerFlags & PLAYER_FLAGS_HIDE_HELM)
        Flags |= CHARACTER_FLAG_HIDE_HELM;

    if (playerFlags & PLAYER_FLAGS_HIDE_CLOAK)
        Flags |= CHARACTER_FLAG_HIDE_CLOAK;

    // show pet at selection character in character list only for non-ghost character
    if (!(playerFlags & PLAYER_FLAGS_GHOST) && (ClassID == CLASS_WARLOCK || ClassID == CLASS_HUNTER || ClassID == CLASS_DEATH_KNIGHT))
    {
        if (CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(fields[19].GetUInt32()))
        {
            PetCreatureDisplayID = fields[20].GetUInt32();
            PetExperienceLevel = fields[21].GetUInt16();
            PetCreatureFamilyID = creatureInfo->family;
        }
    }

    Tokenizer equipment(fields[22].GetString(), ' ');
    ListPosition = fields[24].GetUInt8();

    for (uint8 slot = 0; slot < INVENTORY_SLOT_BAG_END; ++slot)
    {
        uint32 visualBase = slot * 2;
        uint32 itemId = Player::GetUInt32ValueFromArray(equipment, visualBase);
        ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemId);
        if (!proto)
            continue;

        SpellItemEnchantmentEntry const* enchant = nullptr;
        uint32 enchants = Player::GetUInt32ValueFromArray(equipment, visualBase + 1);
        for (uint8 enchantSlot = PERM_ENCHANTMENT_SLOT; enchantSlot <= TEMP_ENCHANTMENT_SLOT; ++enchantSlot)
        {
            // values stored in 2 uint16
            uint32 enchantId = 0x0000FFFF & (enchants >> enchantSlot * 16);
            if (!enchantId)
                continue;

            enchant = sSpellItemEnchantmentStore.LookupEntry(enchantId);
            if (enchant)
                break;
        }

        VisualItems[slot].InvType = proto->GetInventoryType();
        VisualItems[slot].DisplayID = proto->GetDisplayID();
        VisualItems[slot].DisplayEnchantID = enchant ? enchant->ItemVisual : 0;
    }
}

WorldPacket const* WorldPackets::Character::EnumCharactersResult::Write()
{
    _worldPacket.reserve(6 + Characters.size() * sizeof(CharacterInfo) + FactionChangeRestrictions.size() * sizeof(RestrictedFactionChangeRuleInfo));

    _worldPacket.WriteBits(FactionChangeRestrictions.size(), 23);
    _worldPacket.WriteBit(Success);
    _worldPacket.WriteBits(Characters.size(), 17);

    for (CharacterInfo const& charInfo : Characters)
    {
        _worldPacket.WriteBit(charInfo.Guid[3]);
        _worldPacket.WriteBit(charInfo.GuildGUID[1]);
        _worldPacket.WriteBit(charInfo.GuildGUID[7]);
        _worldPacket.WriteBit(charInfo.GuildGUID[2]);
        _worldPacket.WriteBits(charInfo.Name.length(), 7);
        _worldPacket.WriteBit(charInfo.Guid[4]);
        _worldPacket.WriteBit(charInfo.Guid[7]);
        _worldPacket.WriteBit(charInfo.GuildGUID[3]);
        _worldPacket.WriteBit(charInfo.Guid[5]);
        _worldPacket.WriteBit(charInfo.GuildGUID[6]);
        _worldPacket.WriteBit(charInfo.Guid[1]);
        _worldPacket.WriteBit(charInfo.GuildGUID[5]);
        _worldPacket.WriteBit(charInfo.GuildGUID[4]);
        _worldPacket.WriteBit(charInfo.FirstLogin);
        _worldPacket.WriteBit(charInfo.Guid[0]);
        _worldPacket.WriteBit(charInfo.Guid[2]);
        _worldPacket.WriteBit(charInfo.Guid[6]);
        _worldPacket.WriteBit(charInfo.GuildGUID[0]);
    }

    _worldPacket.FlushBits();

    for (CharacterInfo const& charInfo : Characters)
    {
        _worldPacket << uint8(charInfo.ClassID);

        for (WorldPackets::Character::EnumCharactersResult::CharacterInfo::VisualItemInfo const& visualItem : charInfo.VisualItems)
        {
            _worldPacket << uint8(visualItem.InvType);
            _worldPacket << uint32(visualItem.DisplayID);
            _worldPacket << uint32(visualItem.DisplayEnchantID);
        }

        _worldPacket << uint32(charInfo.PetCreatureFamilyID);
        _worldPacket.WriteByteSeq(charInfo.GuildGUID[2]);
        _worldPacket << uint8(charInfo.ListPosition);
        _worldPacket << uint8(charInfo.HairStyle);
        _worldPacket.WriteByteSeq(charInfo.GuildGUID[3]);
        _worldPacket << uint32(charInfo.PetCreatureDisplayID);
        _worldPacket << uint32(charInfo.Flags);
        _worldPacket << uint8(charInfo.HairColor);
        _worldPacket.WriteByteSeq(charInfo.Guid[4]);
        _worldPacket << int32(charInfo.MapID);
        _worldPacket.WriteByteSeq(charInfo.GuildGUID[5]);
        _worldPacket << float(charInfo.PreloadPos.GetPositionZ());
        _worldPacket.WriteByteSeq(charInfo.GuildGUID[6]);
        _worldPacket << uint32(charInfo.PetExperienceLevel);
        _worldPacket.WriteByteSeq(charInfo.Guid[3]);
        _worldPacket << float(charInfo.PreloadPos.GetPositionY());
        _worldPacket << uint32(charInfo.Flags2);
        _worldPacket << uint8(charInfo.FacialHair);
        _worldPacket.WriteByteSeq(charInfo.Guid[7]);
        _worldPacket << uint8(charInfo.SexID);
        _worldPacket.WriteString(charInfo.Name);
        _worldPacket << uint8(charInfo.FaceID);
        _worldPacket.WriteByteSeq(charInfo.Guid[0]);
        _worldPacket.WriteByteSeq(charInfo.Guid[2]);
        _worldPacket.WriteByteSeq(charInfo.GuildGUID[1]);
        _worldPacket.WriteByteSeq(charInfo.GuildGUID[7]);
        _worldPacket << float(charInfo.PreloadPos.GetPositionX());
        _worldPacket << uint8(charInfo.SkinID);
        _worldPacket << uint8(charInfo.RaceID);
        _worldPacket << uint8(charInfo.ExperienceLevel);
        _worldPacket.WriteByteSeq(charInfo.Guid[6]);
        _worldPacket.WriteByteSeq(charInfo.GuildGUID[4]);
        _worldPacket.WriteByteSeq(charInfo.GuildGUID[0]);
        _worldPacket.WriteByteSeq(charInfo.Guid[5]);
        _worldPacket.WriteByteSeq(charInfo.Guid[1]);
        _worldPacket << int32(charInfo.ZoneID);
    }

    for (RestrictedFactionChangeRuleInfo const& rule : FactionChangeRestrictions)
    {
        _worldPacket << int32(rule.Mask);
        _worldPacket << uint8(rule.Race);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Character::CharacterLoginFailed::Write()
{
    _worldPacket << uint8(Code);
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

void WorldPackets::Character::GenerateRandomCharacterName::Read()
{
    _worldPacket >> Race;
    _worldPacket >> Sex;
}

WorldPacket const* WorldPackets::Character::GenerateRandomCharacterNameResult::Write()
{
    _worldPacket.WriteBit(Success);
    _worldPacket.WriteBits(Name.size(), 7);
    _worldPacket.WriteString(Name);

    return &_worldPacket;
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

void WorldPackets::Character::PlayerLogin::Read()
{
    Guid[2] = _worldPacket.ReadBit();
    Guid[3] = _worldPacket.ReadBit();
    Guid[0] = _worldPacket.ReadBit();
    Guid[6] = _worldPacket.ReadBit();
    Guid[4] = _worldPacket.ReadBit();
    Guid[5] = _worldPacket.ReadBit();
    Guid[1] = _worldPacket.ReadBit();
    Guid[7] = _worldPacket.ReadBit();

    _worldPacket.ReadByteSeq(Guid[2]);
    _worldPacket.ReadByteSeq(Guid[7]);
    _worldPacket.ReadByteSeq(Guid[0]);
    _worldPacket.ReadByteSeq(Guid[3]);
    _worldPacket.ReadByteSeq(Guid[5]);
    _worldPacket.ReadByteSeq(Guid[6]);
    _worldPacket.ReadByteSeq(Guid[1]);
    _worldPacket.ReadByteSeq(Guid[4]);
}

WorldPacket const* WorldPackets::Character::LogXPGain::Write()
{
    _worldPacket << Victim;
    _worldPacket << int32(Original);
    _worldPacket << uint8(Reason);
    if (!Reason)
    {
        _worldPacket << int32(Amount);
        _worldPacket << float(GroupBonus);
    }
    _worldPacket << uint8(ReferAFriendBonusType);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Character::PlayedTime::Write()
{
    _worldPacket << int32(TotalTime);
    _worldPacket << int32(LevelTime);
    _worldPacket << uint8(TriggerEvent);

    return &_worldPacket;
}

void WorldPackets::Character::LoadingScreenNotify::Read()
{
    _worldPacket >> MapID;
    Showing = _worldPacket.ReadBit();
}

WorldPacket const* WorldPackets::Character::FailedPlayerCondition::Write()
{
    _worldPacket << int32(ConditionID);

    return &_worldPacket;
}
