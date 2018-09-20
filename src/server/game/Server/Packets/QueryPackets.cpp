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

#include "QueryPackets.h"

void WorldPackets::Query::QueryCreature::Read()
{
    _worldPacket >> CreatureID;
    _worldPacket >> Guid;
}

WorldPacket const* WorldPackets::Query::QueryCreatureResponse::Write()
{
    _worldPacket << uint32(CreatureID | (Allow ? 0x00000000 : 0x80000000)); // creature entry

    if (Allow)
    {
        _worldPacket << Stats.Name;
        _worldPacket << uint8(0) << uint8(0) << uint8(0);                   // name2, name3, name4, always empty
        _worldPacket << Stats.NameAlt;
        _worldPacket << Stats.CursorName;                                   // "Directions" for guard, string for Icons 2.3.0
        _worldPacket << uint32(Stats.Flags);                                // flags
        _worldPacket << uint32(Stats.CreatureType);                         // CreatureType.dbc
        _worldPacket << uint32(Stats.CreatureFamily);                       // CreatureFamily.dbc
        _worldPacket << uint32(Stats.Classification);                       // Creature Rank (elite, boss, etc)
        _worldPacket.append(Stats.ProxyCreatureID, MAX_KILL_CREDIT);        // new in 3.1, kill credit
        _worldPacket.append(Stats.CreatureDisplayID, MAX_CREATURE_MODELS);  // Modelid
        _worldPacket << float(Stats.HpMulti);                               // dmg/hp modifier
        _worldPacket << float(Stats.EnergyMulti);                           // dmg/mana modifier
        _worldPacket << uint8(Stats.Leader);
        _worldPacket.append(Stats.QuestItems, MAX_CREATURE_QUEST_ITEMS);
        _worldPacket << uint32(Stats.CreatureMovementInfoID);               // CreatureMovementInfo.dbc
    }

    return &_worldPacket;
}

void WorldPackets::Query::QueryGameObject::Read()
{
    _worldPacket >> GameObjectID;
    _worldPacket >> Guid;
}

WorldPacket const* WorldPackets::Query::QueryGameObjectResponse::Write()
{
    _worldPacket << uint32(GameObjectID | (Allow ? 0x00000000 : 0x80000000));

    if (Allow)
    {
        _worldPacket << uint32(Stats.Type);
        _worldPacket << uint32(Stats.DisplayID);
        _worldPacket << Stats.Name;
        _worldPacket << uint8(0) << uint8(0) << uint8(0);           // name2, name3, name4
        _worldPacket << Stats.IconName;                             // 2.0.3, string. Icon name to use instead of default icon for go's (ex: "Attack" makes sword)
        _worldPacket << Stats.CastBarCaption;                       // 2.0.3, string. Text will appear in Cast Bar when using GO (ex: "Collecting")
        _worldPacket << Stats.UnkString;                            // 2.0.3, string
        _worldPacket.append(Stats.Data, MAX_GAMEOBJECT_DATA);
        _worldPacket << float(Stats.Size);                          // go size
        _worldPacket.append(Stats.QuestItems, MAX_GAMEOBJECT_QUEST_ITEMS);
    }

    return &_worldPacket;
}

void WorldPackets::Query::QueryItemSingle::Read()
{
    _worldPacket >> ItemID;
}

WorldPacket const* WorldPackets::Query::QueryItemSingleResponse::Write()
{
    _worldPacket << uint32(ItemID | (Allow ? 0x00000000 : 0x80000000));

    if (Allow)
    {
        _worldPacket << Stats.Class;
        _worldPacket << Stats.SubClass;
        _worldPacket << Stats.SoundOverrideSubclass;
        _worldPacket << Stats.Name;
        _worldPacket << uint8(0x00);                              //Name2; // blizz not send name there, just uint8(0x00); <-- \0 = empty string = empty name...
        _worldPacket << uint8(0x00);                              //Name3; // blizz not send name there, just uint8(0x00);
        _worldPacket << uint8(0x00);                              //Name4; // blizz not send name there, just uint8(0x00);
        _worldPacket << Stats.DisplayInfoID;
        _worldPacket << Stats.Quality;
        _worldPacket << Stats.Flags;
        _worldPacket << Stats.Flags2;
        _worldPacket << Stats.BuyPrice;
        _worldPacket << Stats.SellPrice;
        _worldPacket << Stats.InventoryType;
        _worldPacket << Stats.AllowableClass;
        _worldPacket << Stats.AllowableRace;
        _worldPacket << Stats.ItemLevel;
        _worldPacket << Stats.RequiredLevel;
        _worldPacket << Stats.RequiredSkill;
        _worldPacket << Stats.RequiredSkillRank;
        _worldPacket << Stats.RequiredSpell;
        _worldPacket << Stats.RequiredHonorRank;
        _worldPacket << Stats.RequiredCityRank;
        _worldPacket << Stats.RequiredReputationFaction;
        _worldPacket << Stats.RequiredReputationRank;
        _worldPacket << int32(Stats.MaxCount);
        _worldPacket << int32(Stats.Stackable);
        _worldPacket << Stats.ContainerSlots;
        _worldPacket << Stats.StatsCount;                         // item stats count
        for (uint32 i = 0; i < Stats.StatsCount; ++i)
        {
            _worldPacket << Stats.ItemStat[i].ItemStatType;
            _worldPacket << Stats.ItemStat[i].ItemStatValue;
        }
        _worldPacket << Stats.ScalingStatDistribution;            // scaling stats distribution
        _worldPacket << Stats.ScalingStatValue;                   // some kind of flags used to determine stat values column
        for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
        {
            _worldPacket << Stats.Damage[i].DamageMin;
            _worldPacket << Stats.Damage[i].DamageMax;
            _worldPacket << Stats.Damage[i].DamageType;
        }

        // resistances (7)
        for (uint8 i = SPELL_SCHOOL_NORMAL; i < MAX_SPELL_SCHOOL; ++i)
            _worldPacket << Stats.Resistance[i];

        _worldPacket << Stats.Delay;
        _worldPacket << Stats.AmmoType;
        _worldPacket << Stats.RangedModRange;

        for (uint8 s = 0; s < MAX_ITEM_PROTO_SPELLS; ++s)
        {
            // spells are validated on template loading
            if (Stats.Spells[s].SpellId > 0)
            {
                _worldPacket << Stats.Spells[s].SpellId;
                _worldPacket << Stats.Spells[s].SpellTrigger;
                _worldPacket << uint32(-abs(Stats.Spells[s].SpellCharges));
                _worldPacket << uint32(Stats.Spells[s].SpellCooldown);
                _worldPacket << uint32(Stats.Spells[s].SpellCategory);
                _worldPacket << uint32(Stats.Spells[s].SpellCategoryCooldown);
            }
            else
            {
                _worldPacket << uint32(0);
                _worldPacket << uint32(0);
                _worldPacket << uint32(0);
                _worldPacket << uint32(-1);
                _worldPacket << uint32(0);
                _worldPacket << uint32(-1);
            }
        }
        _worldPacket << Stats.Bonding;
        _worldPacket << Stats.Description;
        _worldPacket << Stats.PageText;
        _worldPacket << Stats.LanguageID;
        _worldPacket << Stats.PageMaterial;
        _worldPacket << Stats.StartQuest;
        _worldPacket << Stats.LockID;
        _worldPacket << int32(Stats.Material);
        _worldPacket << Stats.Sheath;
        _worldPacket << Stats.RandomProperty;
        _worldPacket << Stats.RandomSuffix;
        _worldPacket << Stats.Block;
        _worldPacket << Stats.ItemSet;
        _worldPacket << Stats.MaxDurability;
        _worldPacket << Stats.Area;
        _worldPacket << Stats.Map;                                // Added in 1.12.x & 2.0.1 client branch
        _worldPacket << Stats.BagFamily;
        _worldPacket << Stats.TotemCategory;
        for (uint8 s = 0; s < MAX_ITEM_PROTO_SOCKETS; ++s)
        {
            _worldPacket << Stats.Socket[s].Color;
            _worldPacket << Stats.Socket[s].Content;
        }
        _worldPacket << Stats.SocketBonus;
        _worldPacket << Stats.GemProperties;
        _worldPacket << Stats.RequiredDisenchantSkill;
        _worldPacket << Stats.ArmorDamageModifier;
        _worldPacket << Stats.Duration;                           // added in 2.4.2.8209, duration (seconds)
        _worldPacket << Stats.ItemLimitCategory;                  // WotLK, ItemLimitCategory
        _worldPacket << Stats.HolidayId;                          // Holiday.dbc?
    }

    return &_worldPacket;
}

void WorldPackets::Query::QuestPOIQuery::Read()
{
    _worldPacket >> MissingQuestCount; // quest count, max=25

    if (MissingQuestCount <= MAX_QUEST_LOG_SIZE)
    {
        for (uint8 i = 0; i < MissingQuestCount; ++i)
            _worldPacket >> MissingQuestPOIs[i];
    }

    _worldPacket.rfinish();
}
