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
#include "PacketUtilities.h"

WorldPackets::Character::EnumCharactersResult::CharacterInfo::CharacterInfo(Field* fields)
{
    //             0               1                2                3                 4                  5                       6                        7
    //    "SELECT characters.guid, characters.name, characters.race, characters.class, characters.gender, characters.playerBytes, characters.playerBytes2, characters.level, "
    //     8                9               10                     11                     12                     13                    14
    //    "characters.zone, characters.map, characters.position_x, characters.position_y, characters.position_z, guild_member.guildid, characters.playerFlags, "
    //    15                    16                   17                     18                   19               20                     21
    //    "characters.at_login, character_pet.entry, character_pet.modelid, character_pet.level, characters.data, character_banned.guid, character_declinedname.genitive "

    Guid = ObjectGuid(HIGHGUID_PLAYER, fields[0].GetUInt32());
    Name = fields[1].GetString();
    Race = fields[2].GetUInt8();
    Class = fields[3].GetUInt8();
    Sex = fields[4].GetUInt8();
    Skin = uint8(fields[5].GetUInt32() & 0xFF);
    Face = uint8((fields[5].GetUInt32() >> 8) & 0xFF);
    HairStyle = uint8((fields[5].GetUInt32() >> 16) & 0xFF);
    HairColor = uint8((fields[5].GetUInt32() >> 24) & 0xFF);
    FacialHair = uint8(fields[6].GetUInt32() & 0xFF);
    Level = fields[7].GetUInt8();
    ZoneId = uint32(fields[8].GetUInt16());
    MapId = uint32(fields[9].GetUInt16());
    PreLoadPosition.x = fields[10].GetFloat();
    PreLoadPosition.y = fields[11].GetFloat();
    PreLoadPosition.z = fields[12].GetFloat();
    GuildID = fields[13].GetUInt32();

    uint32 playerFlags = fields[14].GetUInt32();
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

    if (sWorld->getBoolConfig(CONFIG_DECLINED_NAMES_USED))
    {
        if (!fields[21].GetString().empty())
            Flags |= CHARACTER_FLAG_DECLINED;
    }
    else
        Flags |= CHARACTER_FLAG_DECLINED;

    if (atLoginFlags & AT_LOGIN_CUSTOMIZE)
        CustomizationFlag = CHAR_CUSTOMIZE_FLAG_CUSTOMIZE;
    else if (atLoginFlags & AT_LOGIN_CHANGE_FACTION)
        CustomizationFlag = CHAR_CUSTOMIZE_FLAG_FACTION;
    else if (atLoginFlags & AT_LOGIN_CHANGE_RACE)
        CustomizationFlag = CHAR_CUSTOMIZE_FLAG_RACE;
    else
        CustomizationFlag = CHAR_CUSTOMIZE_FLAG_NONE;

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

    Tokenizer equipment(fields[19].GetString(), ' ');

    for (uint8 slot = 0; slot < INVENTORY_SLOT_BAG_END; ++slot)
    {
        uint32 visualBase = slot << 1;
        if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(Player::GetUInt32ValueFromArray(equipment, visualBase)))
        {
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
                {
                    VisualItems[slot].DisplayEnchantId = enchant->aura_id;
                    break;
                }
            }

            VisualItems[slot].DisplayId = proto->DisplayInfoID;
            VisualItems[slot].InventoryType = proto->InventoryType;
        }
    }
}

WorldPacket const* WorldPackets::Character::EnumCharactersResult::Write()
{
    _worldPacket.reserve(1 + Characters.size() * sizeof(CharacterInfo));
    _worldPacket << uint8(Characters.size());

    for (CharacterInfo const& charInfo : Characters)
    {
        _worldPacket << charInfo.Guid;
        _worldPacket << charInfo.Name;
        _worldPacket << uint8(charInfo.Race);
        _worldPacket << uint8(charInfo.Class);
        _worldPacket << uint8(charInfo.Sex);
        _worldPacket << uint8(charInfo.Skin);
        _worldPacket << uint8(charInfo.Face);
        _worldPacket << uint8(charInfo.HairStyle);
        _worldPacket << uint8(charInfo.HairColor);
        _worldPacket << uint8(charInfo.FacialHair);
        _worldPacket << uint8(charInfo.Level);
        _worldPacket << uint32(charInfo.ZoneId);
        _worldPacket << uint32(charInfo.MapId);
        _worldPacket << charInfo.PreLoadPosition;
        _worldPacket << uint32(charInfo.GuildID);
        _worldPacket << uint32(charInfo.Flags);
        _worldPacket << uint32(charInfo.CustomizationFlag);
        _worldPacket << uint8(charInfo.FirstLogin ? 1 : 0);
        _worldPacket << uint32(charInfo.Pet.CreatureDisplayId);
        _worldPacket << uint32(charInfo.Pet.Level);
        _worldPacket << uint32(charInfo.Pet.CreatureFamily);

        for (uint8 slot = 0; slot < INVENTORY_SLOT_BAG_END; ++slot)
        {
            _worldPacket << uint32(charInfo.VisualItems[slot].DisplayId);
            _worldPacket << uint8(charInfo.VisualItems[slot].InventoryType);
            _worldPacket << uint32(charInfo.VisualItems[slot].DisplayEnchantId);
        }
    }

    return &_worldPacket;
}

void WorldPackets::Character::PlayerLogin::Read()
{
    _worldPacket >> Guid;
}

void WorldPackets::Character::CharDelete::Read()
{
    _worldPacket >> Guid;
}

void WorldPackets::Character::CreateCharacter::Read()
{
    CreateInfo.reset(new CharacterCreateInfo());

    _worldPacket >> CreateInfo->Name
                 >> CreateInfo->Race
                 >> CreateInfo->Class
                 >> CreateInfo->Gender
                 >> CreateInfo->Skin
                 >> CreateInfo->Face
                 >> CreateInfo->HairStyle
                 >> CreateInfo->HairColor
                 >> CreateInfo->FacialHair
                 >> CreateInfo->OutfitId;
}

void WorldPackets::Character::RenameCharacter::Read()
{
    RenameInfo.reset(new CharacterRenameInfo());

    _worldPacket >> RenameInfo->Guid
                 >> RenameInfo->NewName;
}

void WorldPackets::Character::CharCustomize::Read()
{
    CustomizeInfo.reset(new CharCustomizeInfo());

    _worldPacket >> CustomizeInfo->CharGUID
                 >> CustomizeInfo->CharName
                 >> CustomizeInfo->SexID
                 >> CustomizeInfo->SkinID
                 >> CustomizeInfo->HairColorID
                 >> CustomizeInfo->HairStyleID
                 >> CustomizeInfo->FacialHairStyleID
                 >> CustomizeInfo->FaceID;
}

void WorldPackets::Character::CharRaceOrFactionChange::Read()
{
    RaceOrFactionChangeInfo.reset(new CharRaceOrFactionChangeInfo());

    _worldPacket >> RaceOrFactionChangeInfo->Guid
                 >> RaceOrFactionChangeInfo->Name
                 >> RaceOrFactionChangeInfo->SexID
                 >> RaceOrFactionChangeInfo->SkinID
                 >> RaceOrFactionChangeInfo->HairColorID
                 >> RaceOrFactionChangeInfo->HairStyleID
                 >> RaceOrFactionChangeInfo->FacialHairStyleID
                 >> RaceOrFactionChangeInfo->FaceID
                 >> RaceOrFactionChangeInfo->RaceID;

    RaceOrFactionChangeInfo->FactionChange = (_worldPacket.GetOpcode() == CMSG_CHAR_FACTION_CHANGE);
}
