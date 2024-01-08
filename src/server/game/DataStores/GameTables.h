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

#ifndef GameTables_h__
#define GameTables_h__

#include "SharedDefines.h"
#include "Common.h"
#include <vector>

enum InventoryType : uint8;

struct GtArtifactKnowledgeMultiplierEntry
{
    float Multiplier = 0.0f;
};

struct GtArtifactLevelXPEntry
{
    float XP = 0.0f;
    float XP2 = 0.0f;
};

struct GtBarberShopCostBaseEntry
{
    float Cost = 0.0f;
};

struct GtBaseMPEntry
{
    float Rogue = 0.0f;
    float Druid = 0.0f;
    float Hunter = 0.0f;
    float Mage = 0.0f;
    float Paladin = 0.0f;
    float Priest = 0.0f;
    float Shaman = 0.0f;
    float Warlock = 0.0f;
    float Warrior = 0.0f;
    float DeathKnight = 0.0f;
    float Monk = 0.0f;
    float DemonHunter = 0.0f;
};

struct GtBattlePetXPEntry
{
    float Wins = 0.0f;
    float Xp = 0.0f;
};

struct GtCombatRatingsEntry
{
    float WeaponSkill = 0.0f;
    float DefenseSkill = 0.0f;
    float Dodge = 0.0f;
    float Parry = 0.0f;
    float Block = 0.0f;
    float HitMelee = 0.0f;
    float HitRanged = 0.0f;
    float HitSpell = 0.0f;
    float CritMelee = 0.0f;
    float CritRanged = 0.0f;
    float CritSpell = 0.0f;
    float HitTakenMelee = 0.0f;
    float HitTakenRanged = 0.0f;
    float HitTakenSpell = 0.0f;
    float CritTakenMelee = 0.0f;
    float CritTakenRanged = 0.0f;
    float CritTakenSpell = 0.0f;
    float HasteMelee = 0.0f;
    float HasteRanged = 0.0f;
    float HasteSpell = 0.0f;
    float Unknown0 = 0.0f;
    float Unknown1 = 0.0f;
    float Unknown2 = 0.0f;
    float Unknown3 = 0.0f;
    float Unknown4 = 0.0f;
    float Unknown5 = 0.0f;
    float Unknown6 = 0.0f;
    float Unknown7 = 0.0f;
    float Unknown8 = 0.0f;
    float Unknown9 = 0.0f;
    float Unknown10 = 0.0f;
    float Unknown11 = 0.0f;
};

struct GtCombatRatingsMultByILvl
{
    float ArmorMultiplier = 0.0f;
    float WeaponMultiplier = 0.0f;
    float TrinketMultiplier = 0.0f;
    float JewelryMultiplier = 0.0f;
};

struct GtHpPerStaEntry
{
    float Health = 0.0f;
};

struct GtItemSocketCostPerLevelEntry
{
    float SocketCost = 0.0f;
};

struct GtNpcManaCostScalerEntry
{
    float Scaler = 0.0f;
};

struct GtOCTRegenHPEntry
{
    float Warrior = 0.0f;
    float Paladin = 0.0f;
    float Hunter = 0.0f;
    float Rogue = 0.0f;
    float Priest = 0.0f;
    float DeathKnight = 0.0f;
    float Shaman = 0.0f;
    float Mage = 0.0f;
    float Warlock = 0.0f;
    float Monk = 0.0f;
    float Druid = 0.0f;
};

struct GtOCTRegenMPEntry
{
    float Warrior = 0.0f;
    float Paladin = 0.0f;
    float Hunter = 0.0f;
    float Rogue = 0.0f;
    float Priest = 0.0f;
    float DeathKnight = 0.0f;
    float Shaman = 0.0f;
    float Mage = 0.0f;
    float Warlock = 0.0f;
    float Monk = 0.0f;
    float Druid = 0.0f;
};

struct GtRegenHPPerSptEntry
{
    float Warrior = 0.0f;
    float Paladin = 0.0f;
    float Hunter = 0.0f;
    float Rogue = 0.0f;
    float Priest = 0.0f;
    float DeathKnight = 0.0f;
    float Shaman = 0.0f;
    float Mage = 0.0f;
    float Warlock = 0.0f;
    float Monk = 0.0f;
    float Druid = 0.0f;
};

struct GtRegenMPPerSptEntry
{
    float Warrior = 0.0f;
    float Paladin = 0.0f;
    float Hunter = 0.0f;
    float Rogue = 0.0f;
    float Priest = 0.0f;
    float DeathKnight = 0.0f;
    float Shaman = 0.0f;
    float Mage = 0.0f;
    float Warlock = 0.0f;
    float Monk = 0.0f;
    float Druid = 0.0f;
};

struct GtShieldBlockRegularEntry
{
    float Poor = 0.0f;
    float Standard = 0.0f;
    float Good = 0.0f;
    float Superior = 0.0f;
    float Epic = 0.0f;
    float Legendary = 0.0f;
    float Artifact = 0.0f;
    float ScalingStat = 0.0f;
};

struct GtSpellScalingEntry
{
    float Rogue = 0.0f;
    float Druid = 0.0f;
    float Hunter = 0.0f;
    float Mage = 0.0f;
    float Paladin = 0.0f;
    float Priest = 0.0f;
    float Shaman = 0.0f;
    float Warlock = 0.0f;
    float Warrior = 0.0f;
    float DeathKnight = 0.0f;
    float Monk = 0.0f;
    float DemonHunter = 0.0f;
    float Item = 0.0f;
    float Consumable = 0.0f;
    float Gem1 = 0.0f;
    float Gem2 = 0.0f;
    float Gem3 = 0.0f;
    float Health = 0.0f;
};

struct GtStaminaMultByILvl
{
    float ArmorMultiplier = 0.0f;
    float WeaponMultiplier = 0.0f;
    float TrinketMultiplier = 0.0f;
    float JewelryMultiplier = 0.0f;
};

template<class T>
class GameTable
{
public:
    T const* GetRow(uint32 row) const
    {
        if (row >= _data.size())
            return nullptr;

        return &_data[row];
    }

    std::size_t GetTableRowCount() const { return _data.size(); }

    void SetData(std::vector<T> data) { _data = std::move(data); }

private:
    std::vector<T> _data;
};

TC_GAME_API extern GameTable<GtArtifactKnowledgeMultiplierEntry>    sArtifactKnowledgeMultiplierGameTable;
TC_GAME_API extern GameTable<GtArtifactLevelXPEntry>                sArtifactLevelXPGameTable;
TC_GAME_API extern GameTable<GtBarberShopCostBaseEntry>             sBarberShopCostBaseGameTable;
TC_GAME_API extern GameTable<GtBaseMPEntry>                         sBaseMPGameTable;
TC_GAME_API extern GameTable<GtBattlePetXPEntry>                    sBattlePetXPGameTable;
TC_GAME_API extern GameTable<GtCombatRatingsEntry>                  sCombatRatingsGameTable;
TC_GAME_API extern GameTable<GtCombatRatingsMultByILvl>             sCombatRatingsMultByILvlGameTable;
TC_GAME_API extern GameTable<GtHpPerStaEntry>                       sHpPerStaGameTable;
TC_GAME_API extern GameTable<GtItemSocketCostPerLevelEntry>         sItemSocketCostPerLevelGameTable;
TC_GAME_API extern GameTable<GtNpcManaCostScalerEntry>              sNpcManaCostScalerGameTable;
TC_GAME_API extern GameTable<GtOCTRegenHPEntry>                     sOCTRegenHPGameTable;
TC_GAME_API extern GameTable<GtOCTRegenMPEntry>                     sOCTRegenMPGameTable;
TC_GAME_API extern GameTable<GtRegenHPPerSptEntry>                  sRegenHPPerSptGameTable;
TC_GAME_API extern GameTable<GtRegenMPPerSptEntry>                  sRegenMPPerSptGameTable;
TC_GAME_API extern GameTable<GtShieldBlockRegularEntry>             sShieldBlockRegularGameTable;
TC_GAME_API extern GameTable<GtSpellScalingEntry>                   sSpellScalingGameTable;

TC_GAME_API void LoadGameTables(std::string const& dataPath);

template<class T>
inline float GetGameTableColumnForClass(T const* row, int32 class_)
{
    switch (class_)
    {
        case CLASS_WARRIOR:
            return row->Warrior;
        case CLASS_PALADIN:
            return row->Paladin;
        case CLASS_HUNTER:
            return row->Hunter;
        case CLASS_ROGUE:
            return row->Rogue;
        case CLASS_PRIEST:
            return row->Priest;
        case CLASS_DEATH_KNIGHT:
            return row->DeathKnight;
        case CLASS_SHAMAN:
            return row->Shaman;
        case CLASS_MAGE:
            return row->Mage;
        case CLASS_WARLOCK:
            return row->Warlock;
        case CLASS_MONK:
            return row->Monk;
        case CLASS_DRUID:
            return row->Druid;
        case CLASS_DEMON_HUNTER:
            return row->DemonHunter;
        default:
            break;
    }

    return 0.0f;
}

template<class T>
inline float GetRegenGameTableColumnForClass(T const* row, int32 class_)
{
    switch (class_)
    {
    case CLASS_WARRIOR:
        return row->Warrior;
    case CLASS_PALADIN:
        return row->Paladin;
    case CLASS_HUNTER:
        return row->Hunter;
    case CLASS_ROGUE:
        return row->Rogue;
    case CLASS_PRIEST:
        return row->Priest;
    case CLASS_DEATH_KNIGHT:
        return row->DeathKnight;
    case CLASS_SHAMAN:
        return row->Shaman;
    case CLASS_MAGE:
        return row->Mage;
    case CLASS_WARLOCK:
        return row->Warlock;
    case CLASS_MONK:
        return row->Monk;
    case CLASS_DRUID:
        return row->Druid;
    default:
        break;
    }

    return 0.0f;
}

inline float GetSpellScalingColumnForClass(GtSpellScalingEntry const* row, int32 class_)
{
    switch (class_)
    {
        case CLASS_WARRIOR:
            return row->Warrior;
        case CLASS_PALADIN:
            return row->Paladin;
        case CLASS_HUNTER:
            return row->Hunter;
        case CLASS_ROGUE:
            return row->Rogue;
        case CLASS_PRIEST:
            return row->Priest;
        case CLASS_DEATH_KNIGHT:
            return row->DeathKnight;
        case CLASS_SHAMAN:
            return row->Shaman;
        case CLASS_MAGE:
            return row->Mage;
        case CLASS_WARLOCK:
            return row->Warlock;
        case CLASS_MONK:
            return row->Monk;
        case CLASS_DRUID:
            return row->Druid;
        case CLASS_DEMON_HUNTER:
            return row->DemonHunter;
        case -1:
        case -7:
            return row->Item;
        case -2:
            return row->Consumable;
        case -3:
            return row->Gem1;
        case -4:
            return row->Gem2;
        case -5:
            return row->Gem3;
        case -6:
            return row->Health;
        default:
            break;
    }

    return 0.0f;
}

inline float GetBattlePetXPPerLevel(GtBattlePetXPEntry const* row)
{
    return row->Wins * row->Xp;
}

inline float GetShieldBlockRegularColumnForQuality(GtShieldBlockRegularEntry const* row, ItemQualities quality)
{
    switch (quality)
    {
        case ITEM_QUALITY_POOR:
            return row->Poor;
        case ITEM_QUALITY_NORMAL:
            return row->Standard;
        case ITEM_QUALITY_UNCOMMON:
            return row->Good;
        case ITEM_QUALITY_RARE:
            return row->Superior;
        case ITEM_QUALITY_EPIC:
            return row->Epic;
        case ITEM_QUALITY_LEGENDARY:
            return row->Legendary;
        case ITEM_QUALITY_ARTIFACT:
            return row->Artifact;
        case ITEM_QUALITY_HEIRLOOM:
            return row->ScalingStat;
        default:
            break;
    }

    return 0.0f;
}

#endif // GameTables_h__
