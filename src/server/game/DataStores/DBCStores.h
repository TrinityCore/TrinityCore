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

// ChrRaces
TC_GAME_API char const* GetRaceName(uint8 race, uint8 locale);

// ChrSpecialization
#define PET_SPEC_OVERRIDE_CLASS_INDEX MAX_CLASSES
typedef ChrSpecializationEntry const* ChrSpecializationByIndexArray[MAX_CLASSES + 1][MAX_SPECIALIZATIONS];

// CreatureFamilty
TC_GAME_API char const* GetCreatureFamilyPetName(uint32 petfamily, uint32 locale);

// EmotesText
TC_GAME_API EmotesTextSoundEntry const* FindTextSoundEmoteFor(uint32 emote, uint32 race, uint32 gender);

// Faction
TC_GAME_API std::vector<uint32> const* GetFactionTeamList(uint32 faction);

// ItemSetSpells
typedef std::vector<ItemSetSpellEntry const*> ItemSetSpells;
typedef std::unordered_map<uint32, ItemSetSpells> ItemSetSpellsStore;

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

// PvpDifficulty
TC_GAME_API PvPDifficultyEntry const* GetBattlegroundBracketByLevel(uint32 mapid, uint32 level);
TC_GAME_API PvPDifficultyEntry const* GetBattlegroundBracketById(uint32 mapid, BattlegroundBracketId id);

// SkillRaceClassInfo
typedef std::unordered_multimap<uint32, SkillRaceClassInfoEntry const*> SkillRaceClassInfoMap;
typedef std::pair<SkillRaceClassInfoMap::iterator, SkillRaceClassInfoMap::iterator> SkillRaceClassInfoBounds;
TC_GAME_API SkillRaceClassInfoEntry const* GetSkillRaceClassInfo(uint32 skill, uint8 race, uint8 class_);

// SpellEffectScaling
typedef std::unordered_map<uint32, uint32> SpellEffectScallingByEffectId;

// Talent
typedef std::vector<TalentEntry const*> TalentsByPosition[MAX_CLASSES][MAX_TALENT_TIERS][MAX_TALENT_COLUMNS];

// TotemCategory
TC_GAME_API bool IsTotemCategoryCompatibleWith(uint32 itemTotemCategoryId, uint32 requiredTotemCategoryId);

// WMOAreaTable
TC_GAME_API WMOAreaTableEntry const* GetWMOAreaTableEntryByTripple(int32 rootid, int32 adtid, int32 groupid);

// WorldMapArea
TC_GAME_API uint32 GetVirtualMapForMapAndZone(uint32 mapid, uint32 zoneId);
TC_GAME_API void Zone2MapCoordinates(float &x, float &y, uint32 worldMapAreaId);
TC_GAME_API void Map2ZoneCoordinates(float &x, float &y, uint32 worldMapAreaId);

// WorldMapTransforms
TC_GAME_API void DeterminaAlternateMapPosition(uint32 mapId, float x, float y, float z, uint32* newMapId = nullptr, DBCPosition2D* newPos = nullptr);

TC_GAME_API uint32 GetMaxLevelForExpansion(uint32 expansion);
TC_GAME_API uint32 GetExpansionForLevel(uint32 level);

template<class T>
class GameTable
{
public:
    GameTable(char const* format) : _storage(format), _gtEntry(nullptr) { }

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

TC_GAME_API extern DBCStorage<AnimKitEntry>                     sAnimKitStore;
TC_GAME_API extern DBCStorage<AreaTableEntry>                   sAreaTableStore;
TC_GAME_API extern DBCStorage<AreaTriggerEntry>                 sAreaTriggerStore;
TC_GAME_API extern DBCStorage<ArmorLocationEntry>               sArmorLocationStore;
TC_GAME_API extern DBCStorage<BankBagSlotPricesEntry>           sBankBagSlotPricesStore;
TC_GAME_API extern DBCStorage<BannedAddOnsEntry>                sBannedAddOnsStore;
TC_GAME_API extern DBCStorage<BattlemasterListEntry>            sBattlemasterListStore;
TC_GAME_API extern DBCStorage<CharSectionsEntry>                sCharSectionsStore;
TC_GAME_API extern DBCStorage<CharTitlesEntry>                  sCharTitlesStore;
TC_GAME_API extern DBCStorage<ChatChannelsEntry>                sChatChannelsStore;
TC_GAME_API extern DBCStorage<ChrClassesEntry>                  sChrClassesStore;
TC_GAME_API extern DBCStorage<ChrRacesEntry>                    sChrRacesStore;
TC_GAME_API extern DBCStorage<ChrSpecializationEntry>           sChrSpecializationStore;
TC_GAME_API extern ChrSpecializationByIndexArray                sChrSpecializationByIndexStore;
TC_GAME_API extern DBCStorage<CreatureDisplayInfoExtraEntry>    sCreatureDisplayInfoExtraStore;
TC_GAME_API extern DBCStorage<CreatureFamilyEntry>              sCreatureFamilyStore;
TC_GAME_API extern DBCStorage<CreatureModelDataEntry>           sCreatureModelDataStore;
TC_GAME_API extern DBCStorage<DifficultyEntry>                  sDifficultyStore;
TC_GAME_API extern DBCStorage<DungeonEncounterEntry>            sDungeonEncounterStore;
TC_GAME_API extern DBCStorage<DurabilityCostsEntry>             sDurabilityCostsStore;
TC_GAME_API extern DBCStorage<EmotesEntry>                      sEmotesStore;
TC_GAME_API extern DBCStorage<EmotesTextEntry>                  sEmotesTextStore;
TC_GAME_API extern DBCStorage<FactionEntry>                     sFactionStore;
TC_GAME_API extern DBCStorage<FactionTemplateEntry>             sFactionTemplateStore;
TC_GAME_API extern DBCStorage<GameObjectDisplayInfoEntry>       sGameObjectDisplayInfoStore;
TC_GAME_API extern DBCStorage<GemPropertiesEntry>               sGemPropertiesStore;
TC_GAME_API extern DBCStorage<GlyphPropertiesEntry>             sGlyphPropertiesStore;
TC_GAME_API extern DBCStorage<GuildColorBackgroundEntry>        sGuildColorBackgroundStore;
TC_GAME_API extern DBCStorage<GuildColorBorderEntry>            sGuildColorBorderStore;
TC_GAME_API extern DBCStorage<GuildColorEmblemEntry>            sGuildColorEmblemStore;
TC_GAME_API extern DBCStorage<ItemArmorQualityEntry>            sItemArmorQualityStore;
TC_GAME_API extern DBCStorage<ItemArmorShieldEntry>             sItemArmorShieldStore;
TC_GAME_API extern DBCStorage<ItemArmorTotalEntry>              sItemArmorTotalStore;
TC_GAME_API extern DBCStorage<ItemBagFamilyEntry>               sItemBagFamilyStore;
TC_GAME_API extern DBCStorage<ItemDamageEntry>                  sItemDamageAmmoStore;
TC_GAME_API extern DBCStorage<ItemDamageEntry>                  sItemDamageOneHandCasterStore;
TC_GAME_API extern DBCStorage<ItemDamageEntry>                  sItemDamageOneHandStore;
TC_GAME_API extern DBCStorage<ItemDamageEntry>                  sItemDamageRangedStore;
TC_GAME_API extern DBCStorage<ItemDamageEntry>                  sItemDamageThrownStore;
TC_GAME_API extern DBCStorage<ItemDamageEntry>                  sItemDamageTwoHandCasterStore;
TC_GAME_API extern DBCStorage<ItemDamageEntry>                  sItemDamageTwoHandStore;
TC_GAME_API extern DBCStorage<ItemDamageEntry>                  sItemDamageWandStore;
TC_GAME_API extern DBCStorage<ItemSetEntry>                     sItemSetStore;
TC_GAME_API extern DBCStorage<ItemSetSpellEntry>                sItemSetSpellStore;
TC_GAME_API extern ItemSetSpellsStore                           sItemSetSpellsStore;
TC_GAME_API extern DBCStorage<LFGDungeonEntry>                  sLFGDungeonStore;
TC_GAME_API extern DBCStorage<LiquidTypeEntry>                  sLiquidTypeStore;
TC_GAME_API extern DBCStorage<LockEntry>                        sLockStore;
TC_GAME_API extern DBCStorage<MapEntry>                         sMapStore;
TC_GAME_API extern MapDifficultyMap                             sMapDifficultyMap;
TC_GAME_API extern DBCStorage<MovieEntry>                       sMovieStore;
TC_GAME_API extern DBCStorage<PhaseEntry>                       sPhaseStore;
TC_GAME_API extern DBCStorage<PowerDisplayEntry>                sPowerDisplayStore;
TC_GAME_API extern DBCStorage<QuestFactionRewEntry>             sQuestFactionRewardStore;
TC_GAME_API extern DBCStorage<RandomPropertiesPointsEntry>      sRandomPropertiesPointsStore;
TC_GAME_API extern DBCStorage<SkillLineAbilityEntry>            sSkillLineAbilityStore;
TC_GAME_API extern DBCStorage<SkillLineEntry>                   sSkillLineStore;
TC_GAME_API extern DBCStorage<SkillRaceClassInfoEntry>          sSkillRaceClassInfoStore;
TC_GAME_API extern DBCStorage<SpellAuraOptionsEntry>            sSpellAuraOptionsStore;
TC_GAME_API extern DBCStorage<SpellCategoriesEntry>             sSpellCategoriesStore;
TC_GAME_API extern DBCStorage<SpellCategoryEntry>               sSpellCategoryStore;
TC_GAME_API extern DBCStorage<SpellCooldownsEntry>              sSpellCooldownsStore;
TC_GAME_API extern DBCStorage<SpellEffectEntry>                 sSpellEffectStore;
TC_GAME_API extern DBCStorage<SpellEffectScalingEntry>          sSpellEffectScalingStore;
TC_GAME_API extern SpellEffectScallingByEffectId                sSpellEffectScallingByEffectId;
TC_GAME_API extern DBCStorage<SpellEntry>                       sSpellStore;
TC_GAME_API extern DBCStorage<SpellEquippedItemsEntry>          sSpellEquippedItemsStore;
TC_GAME_API extern DBCStorage<SpellFocusObjectEntry>            sSpellFocusObjectStore;
TC_GAME_API extern DBCStorage<SpellInterruptsEntry>             sSpellInterruptsStore;
TC_GAME_API extern DBCStorage<SpellItemEnchantmentEntry>        sSpellItemEnchantmentStore;
TC_GAME_API extern DBCStorage<SpellLevelsEntry>                 sSpellLevelsStore;
TC_GAME_API extern DBCStorage<SpellScalingEntry>                sSpellScalingStore;
TC_GAME_API extern DBCStorage<SpellShapeshiftEntry>             sSpellShapeshiftStore;
TC_GAME_API extern DBCStorage<SpellShapeshiftFormEntry>         sSpellShapeshiftFormStore;
TC_GAME_API extern DBCStorage<SpellTargetRestrictionsEntry>     sSpellTargetRestrictionsStore;
TC_GAME_API extern DBCStorage<SummonPropertiesEntry>            sSummonPropertiesStore;
TC_GAME_API extern DBCStorage<TalentEntry>                      sTalentStore;
TC_GAME_API extern TalentsByPosition                            sTalentByPos;
TC_GAME_API extern DBCStorage<VehicleEntry>                     sVehicleStore;
TC_GAME_API extern DBCStorage<VehicleSeatEntry>                 sVehicleSeatStore;
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
TC_GAME_API extern GameTable<GtNpcTotalHpEntry>                 sGtNpcTotalHpStore;
TC_GAME_API extern GameTable<GtNpcTotalHpExp1Entry>             sGtNpcTotalHpExp1Store;
TC_GAME_API extern GameTable<GtNpcTotalHpExp2Entry>             sGtNpcTotalHpExp2Store;
TC_GAME_API extern GameTable<GtNpcTotalHpExp3Entry>             sGtNpcTotalHpExp3Store;
TC_GAME_API extern GameTable<GtNpcTotalHpExp4Entry>             sGtNpcTotalHpExp4Store;
TC_GAME_API extern GameTable<GtNpcTotalHpExp5Entry>             sGtNpcTotalHpExp5Store;
TC_GAME_API extern GameTable<GtOCTBaseHPByClassEntry>           sGtOCTBaseHPByClassStore;
TC_GAME_API extern GameTable<GtOCTBaseMPByClassEntry>           sGtOCTBaseMPByClassStore;
TC_GAME_API extern GameTable<GtOCTLevelExperienceEntry>         sGtOCTLevelExperienceStore;
TC_GAME_API extern GameTable<GtRegenMPPerSptEntry>              sGtRegenMPPerSptStore;
TC_GAME_API extern GameTable<GtSpellScalingEntry>               sGtSpellScalingStore;
TC_GAME_API extern GameTable<GtOCTHpPerStaminaEntry>            sGtOCTHpPerStaminaStore;

TC_GAME_API void LoadDBCStores(const std::string& dataPath, uint32 defaultLocale);
TC_GAME_API void LoadGameTables(const std::string& dataPath, uint32 defaultLocale);

#endif
