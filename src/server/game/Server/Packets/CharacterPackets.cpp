/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

WorldPackets::Character::CharEnumResult::CharacterInfo::CharacterInfo(Field* fields)
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

    if (uint32 guildId = fields[13].GetUInt32())
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
        uint32 visualBase = slot * 2;
        uint32 itemId = Player::GetUInt32ValueFromArray(equipment, visualBase);
        if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemId))
        {
            uint32 enchants = Player::GetUInt32ValueFromArray(equipment, visualBase + 1);
            for (uint8 enchantSlot = PERM_ENCHANTMENT_SLOT; enchantSlot <= TEMP_ENCHANTMENT_SLOT; ++enchantSlot)
            {
                // values stored in 2 uint16
                uint32 enchantId = 0x0000FFFF & (enchants >> enchantSlot * 16);
                if (!enchantId)
                    continue;

                if (SpellItemEnchantmentEntry const* enchant = sSpellItemEnchantmentStore.LookupEntry(enchantId))
                {
                    VisualItems[slot].DisplayEnchantId = enchant->aura_id;
                    break;
                }
            }

            VisualItems[slot].DisplayId = proto->DisplayInfoID;
            VisualItems[slot].InventoryType = uint8(proto->InventoryType);
        }
    }
}

WorldPackets::Character::CharEnumResult::CharEnumResult()
    : ServerPacket(SMSG_CHAR_ENUM) { }

void WorldPackets::Character::CharEnumResult::Write()
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
        _worldPacket << float(charInfo.PreLoadPosition.x);
        _worldPacket << float(charInfo.PreLoadPosition.y);
        _worldPacket << float(charInfo.PreLoadPosition.z);
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
        _worldPacket.WriteString(charInfo.Name);
    }

    for (RestrictedFactionChangeRuleInfo const& rule : FactionChangeRestrictions)
    {
        _worldPacket << int32(rule.Mask);
        _worldPacket << uint8(rule.Race);
    }
}

WorldPackets::Character::CharacterCreate::CharacterCreate(WorldPacket&& packet)
    : ClientPacket(std::move(packet))
{
    ASSERT(_worldPacket.GetOpcode() == CMSG_CHAR_CREATE);
}

void WorldPackets::Character::CharacterCreate::Read()
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
        _worldPacket >> CreateInfo->TemplateSet.value;
}

WorldPackets::Character::CharacterCreateResponse::CharacterCreateResponse()
    : ServerPacket(SMSG_CHAR_CREATE, 1) { }

void WorldPackets::Character::CharacterCreateResponse::Write()
{
    _worldPacket << uint8(Code);
}

WorldPackets::Character::CharacterDelete::CharacterDelete(WorldPacket&& packet)
    : ClientPacket(std::move(packet))
{
    ASSERT(_worldPacket.GetOpcode() == CMSG_CHAR_DELETE);
}

void WorldPackets::Character::CharacterDelete::Read()
{
    _worldPacket >> Guid;
}

WorldPackets::Character::CharacterDeleteResponse::CharacterDeleteResponse()
    : ServerPacket(SMSG_CHAR_DELETE, 1) { }

void WorldPackets::Character::CharacterDeleteResponse::Write()
{
    _worldPacket << uint8(Code);
}

WorldPackets::Character::UndeleteCharacter::UndeleteCharacter(WorldPacket&& packet)
    : ClientPacket(std::move(packet))
{
    ASSERT(_worldPacket.GetOpcode() == CMSG_UNDELETE_CHARACTER);
}

void WorldPackets::Character::UndeleteCharacter::Read()
{
    UndeleteInfo.reset(new CharacterUndeleteInfo());
    _worldPacket >> UndeleteInfo->ClientToken;
    _worldPacket >> UndeleteInfo->CharacterGuid;
}

WorldPackets::Character::UndeleteCharacterResponse::UndeleteCharacterResponse()
    : ServerPacket(SMSG_UNDELETE_CHARACTER_RESPONSE, 26) { }

void WorldPackets::Character::UndeleteCharacterResponse::Write()
{
    ASSERT(UndeleteInfo);
    _worldPacket << int32(UndeleteInfo->ClientToken);
    _worldPacket << uint32(Result);
    _worldPacket << UndeleteInfo->CharacterGuid;
}

WorldPackets::Character::UndeleteCooldownStatusResponse::UndeleteCooldownStatusResponse()
    : ServerPacket(SMSG_UNDELETE_COOLDOWN_STATUS_RESPONSE, 9) { }

void WorldPackets::Character::UndeleteCooldownStatusResponse::Write()
{
    _worldPacket.WriteBit(OnCooldown);
    _worldPacket << uint32(MaxCooldown);
    _worldPacket << uint32(CurrentCooldown);
}

WorldPackets::Character::PlayerLogin::PlayerLogin(WorldPacket&& packet)
    : ClientPacket(std::move(packet))
{
    ASSERT(_worldPacket.GetOpcode() == CMSG_PLAYER_LOGIN);
}

void WorldPackets::Character::PlayerLogin::Read()
{
    _worldPacket >> Guid;
    _worldPacket >> FarClip;
}
