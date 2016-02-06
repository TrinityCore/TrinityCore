/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef TRINITY_DBCSTORES_H
#define TRINITY_DBCSTORES_H

#include "DBCStore.h"
#include "DBCStructure.h"
#include "DB2Structure.h"
#include "SharedDefines.h"

// CharSections
TC_GAME_API CharSectionsEntry const* GetCharSectionEntry(uint8 race, CharSectionType genType, uint8 gender, uint8 type, uint8 color);

// ChrClasses
TC_GAME_API char const* GetClassName(uint8 class_, uint8 locale);

// Faction
TC_GAME_API std::vector<uint32> const* GetFactionTeamList(uint32 faction);

// LfgDungeons
TC_GAME_API LFGDungeonEntry const* GetLFGDungeon(uint32 mapId, Difficulty difficulty);

// Light
TC_GAME_API uint32 GetDefaultMapLight(uint32 mapId);

// LiquidType
TC_GAME_API uint32 GetLiquidFlags(uint32 liquidType);

// MapDifficulty
typedef std::unordered_map<uint32, std::unordered_map<uint32, MapDifficultyEntry const*>> MapDifficultyMap;
TC_GAME_API MapDifficultyEntry const* GetDefaultMapDifficulty(uint32 mapId, Difficulty* difficulty = nullptr);
TC_GAME_API MapDifficultyEntry const* GetMapDifficultyData(uint32 mapId, Difficulty difficulty);
TC_GAME_API MapDifficultyEntry const* GetDownscaledMapDifficultyData(uint32 mapId, Difficulty &difficulty);

// Talent
typedef std::vector<TalentEntry const*> TalentsByPosition[MAX_CLASSES][MAX_TALENT_TIERS][MAX_TALENT_COLUMNS];

// WMOAreaTable
TC_GAME_API WMOAreaTableEntry const* GetWMOAreaTableEntryByTripple(int32 rootid, int32 adtid, int32 groupid);

// WorldMapArea
TC_GAME_API uint32 GetVirtualMapForMapAndZone(uint32 mapid, uint32 zoneId);
TC_GAME_API void Zone2MapCoordinates(float &x, float &y, uint32 worldMapAreaId);
TC_GAME_API void Map2ZoneCoordinates(float &x, float &y, uint32 worldMapAreaId);

TC_GAME_API uint32 GetMaxLevelForExpansion(uint32 expansion);
TC_GAME_API uint32 GetExpansionForLevel(uint32 level);

template<class T>
class GameTable
{
public:
    GameTable() : _storage("df"), _gtEntry(nullptr) { }

    void SetGameTableEntry(GameTablesEntry const* gtEntry) { _gtEntry = gtEntry; }

    T const* EvaluateTable(uint32 row, uint32 column) const
    {
        ASSERT(row < _gtEntry->NumRows, "Requested row %u from GameTable %s but there are only %u rows!", row, _gtEntry->Name->Str[0], _gtEntry->NumRows);
        ASSERT(column < _gtEntry->NumColumns, "Requested column %u from GameTable %s but there are only %u columns!", column, _gtEntry->Name->Str[0], _gtEntry->NumColumns);

        return _storage.LookupEntry(_gtEntry->NumRows * column + row);
    }

    char const* GetFormat() const { return _storage.GetFormat(); }
    uint32 GetFieldCount() const { return _storage.GetFieldCount(); }
    bool Load(char const* fileName) { return _storage.Load(fileName, nullptr); }

    uint32 GetTableRowCount() const { return _gtEntry->NumRows; }
    uint32 GetTableColumnCount() const { return _gtEntry->NumColumns; }

private:
    DBCStorage<T> _storage;
    GameTablesEntry const* _gtEntry;
};

TC_GAME_API extern DBCStorage<BannedAddOnsEntry>                sBannedAddOnsStore;
TC_GAME_API extern DBCStorage<BattlemasterListEntry>            sBattlemasterListStore;
TC_GAME_API extern DBCStorage<CharSectionsEntry>                sCharSectionsStore;
TC_GAME_API extern DBCStorage<ChrClassesEntry>                  sChrClassesStore;
TC_GAME_API extern DBCStorage<CreatureModelDataEntry>           sCreatureModelDataStore;
TC_GAME_API extern DBCStorage<FactionEntry>                     sFactionStore;
TC_GAME_API extern DBCStorage<FactionTemplateEntry>             sFactionTemplateStore;
TC_GAME_API extern DBCStorage<LFGDungeonEntry>                  sLFGDungeonStore;
TC_GAME_API extern DBCStorage<LiquidTypeEntry>                  sLiquidTypeStore;
TC_GAME_API extern MapDifficultyMap                             sMapDifficultyMap;
TC_GAME_API extern DBCStorage<SpellItemEnchantmentEntry>        sSpellItemEnchantmentStore;
TC_GAME_API extern DBCStorage<TalentEntry>                      sTalentStore;
TC_GAME_API extern TalentsByPosition                            sTalentByPos;
TC_GAME_API extern DBCStorage<VehicleEntry>                     sVehicleStore;
TC_GAME_API extern DBCStorage<WMOAreaTableEntry>                sWMOAreaTableStore;
TC_GAME_API extern DBCStorage<WorldSafeLocsEntry>               sWorldSafeLocsStore;

TC_GAME_API extern GameTable<GtArmorMitigationByLvlEntry>       sGtArmorMitigationByLvlStore;
TC_GAME_API extern GameTable<GtBarberShopCostBaseEntry>         sGtBarberShopCostBaseStore;
TC_GAME_API extern GameTable<GtChanceToMeleeCritBaseEntry>      sGtChanceToMeleeCritBaseStore;
TC_GAME_API extern GameTable<GtChanceToMeleeCritEntry>          sGtChanceToMeleeCritStore;
TC_GAME_API extern GameTable<GtChanceToSpellCritBaseEntry>      sGtChanceToSpellCritBaseStore;
TC_GAME_API extern GameTable<GtChanceToSpellCritEntry>          sGtChanceToSpellCritStore;
TC_GAME_API extern GameTable<GtCombatRatingsEntry>              sGtCombatRatingsStore;
TC_GAME_API extern GameTable<GtItemSocketCostPerLevelEntry>     sGtItemSocketCostPerLevelStore;
TC_GAME_API extern GameTable<GtNPCManaCostScalerEntry>          sGtNPCManaCostScalerStore;
TC_GAME_API extern GameTable<GtNpcTotalHpEntry>                 sGtNpcTotalHpStore[MAX_EXPANSIONS];
TC_GAME_API extern GameTable<GtNpcDamageByClassEntry>           sGtNpcDamageByClassStore[MAX_EXPANSIONS];
TC_GAME_API extern GameTable<GtOCTBaseHPByClassEntry>           sGtOCTBaseHPByClassStore;
TC_GAME_API extern GameTable<GtOCTBaseMPByClassEntry>           sGtOCTBaseMPByClassStore;
TC_GAME_API extern GameTable<GtOCTLevelExperienceEntry>         sGtOCTLevelExperienceStore;
TC_GAME_API extern GameTable<GtRegenMPPerSptEntry>              sGtRegenMPPerSptStore;
TC_GAME_API extern GameTable<GtSpellScalingEntry>               sGtSpellScalingStore;
TC_GAME_API extern GameTable<GtOCTHpPerStaminaEntry>            sGtOCTHpPerStaminaStore;

TC_GAME_API void LoadDBCStores(const std::string& dataPath, uint32 defaultLocale);
TC_GAME_API void LoadGameTables(const std::string& dataPath, uint32 defaultLocale);

#endif
