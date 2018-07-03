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

#ifndef GameTables_h__
#define GameTables_h__

#include "SharedDefines.h"
#include "Common.h"
#include <vector>

struct GtArmorMitigationByLvlEntry
{
    float Mitigation = 0.0f;
};

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

struct GtCombatRatingsEntry
{
    float Amplify = 0.0f;
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
    float MultiStrike = 0.0f;
    float Readiness = 0.0f;
    float Speed = 0.0f;
    float ResilienceCritTaken = 0.0f;
    float ResiliencePlayerDamage = 0.0f;
    float Lifesteal = 0.0f;
    float HasteMelee = 0.0f;
    float HasteRanged = 0.0f;
    float HasteSpell = 0.0f;
    float Avoidance = 0.0f;
    float Sturdiness = 0.0f;
    float Unused7 = 0.0f;
    float Expertise = 0.0f;
    float ArmorPenetration = 0.0f;
    float Mastery = 0.0f;
    float PvPPower = 0.0f;
    float Cleave = 0.0f;
    float VersatilityDamageDone = 0.0f;
    float VersatilityHealingDone = 0.0f;
    float VersatilityDamageTaken = 0.0f;
    float Unused12 = 0.0f;
};

struct GtCombatRatingsMultByILvl
{
    float ArmorMultiplier = 0.0f;
    float WeaponMultiplier = 0.0f;
    float TrinketMultiplier = 0.0f;
    float JewelryMultiplier = 0.0f;
};

uint8 constexpr PRESTIGE_COLUMN_COUNT = 33;
struct GtHonorLevelEntry
{
    float Prestige[PRESTIGE_COLUMN_COUNT] = { };
};

struct GtHpPerStaEntry
{
    float Health = 0.0f;
};

struct GtItemSocketCostPerLevelEntry
{
    float SocketCost = 0.0f;
};

struct GtNpcDamageByClassEntry
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

struct GtNpcManaCostScalerEntry
{
    float Scaler = 0.0f;
};

struct GtNpcTotalHpEntry
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

struct GtXpEntry
{
    float Total = 0.0f;
    float PerKill = 0.0f;
    float Junk = 0.0f;
    float Stats = 0.0f;
    float Divisor = 0.0f;
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

TC_GAME_API extern GameTable<GtArmorMitigationByLvlEntry>           sArmorMitigationByLvlGameTable;
TC_GAME_API extern GameTable<GtArtifactKnowledgeMultiplierEntry>    sArtifactKnowledgeMultiplierGameTable;
TC_GAME_API extern GameTable<GtArtifactLevelXPEntry>                sArtifactLevelXPGameTable;
TC_GAME_API extern GameTable<GtBarberShopCostBaseEntry>             sBarberShopCostBaseGameTable;
TC_GAME_API extern GameTable<GtBaseMPEntry>                         sBaseMPGameTable;
TC_GAME_API extern GameTable<GtCombatRatingsEntry>                  sCombatRatingsGameTable;
TC_GAME_API extern GameTable<GtCombatRatingsMultByILvl>             sCombatRatingsMultByILvlGameTable;
TC_GAME_API extern GameTable<GtHonorLevelEntry>                     sHonorLevelGameTable;
TC_GAME_API extern GameTable<GtHpPerStaEntry>                       sHpPerStaGameTable;
TC_GAME_API extern GameTable<GtItemSocketCostPerLevelEntry>         sItemSocketCostPerLevelGameTable;
TC_GAME_API extern GameTable<GtNpcDamageByClassEntry>               sNpcDamageByClassGameTable[MAX_EXPANSIONS];
TC_GAME_API extern GameTable<GtNpcManaCostScalerEntry>              sNpcManaCostScalerGameTable;
TC_GAME_API extern GameTable<GtNpcTotalHpEntry>                     sNpcTotalHpGameTable[MAX_EXPANSIONS];
TC_GAME_API extern GameTable<GtSpellScalingEntry>                   sSpellScalingGameTable;
TC_GAME_API extern GameTable<GtXpEntry>                             sXpGameTable;

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

#endif // GameTables_h__
